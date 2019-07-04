def isWindows(){
  //If NODE_LABELS environment variable is null, we assume we are on master unix machine
  if (env.NODE_LABELS == null) {
    return false
  }
    return env.NODE_LABELS.toLowerCase().contains('windows')
}

def shell(params){
    if(isWindows()) bat(params) 
    else sh(params)
}

def runInCygwin(command){
    def c = """#!c:\\cygwin64\\bin\\bash --login
    cd `cygpath \"$WORKSPACE\"`
    set -ex
    ${command}
    """
    
    echo("Executing: ${c}")
    return sh(c)
}


def runBuild(platform){
	cleanWs()
	

    stage("Checkout-${platform}"){
        checkout scm
    }


	stage("Build-${platform}"){
    	if(isWindows()){
    	    runInCygwin "cmake . -DWIN=1"
    	    runInCygwin "make install"
    	    runInCygwin "make package"
    	}else{
    		cmakeBuild generator: 'Unix Makefiles', installation: 'InSearchPath'
    		shell "make install"
			shell "make package"			
    	}
		
		stash excludes: '_CPack_Packages', includes: 'build/packages/*', name: "packages-${platform}"
		archiveArtifacts artifacts: 'build/packages/*', excludes: '_CPack_Packages'
	}
}


def upload(platform, vmDir) {

	unstash name: "packages-${platform}"

	def expandedFileName = sh(returnStdout: true, script: "ls build/packages/PharoVM-*-${vmDir}64.zip").trim()

	sshagent (credentials: ['b5248b59-a193-4457-8459-e28e9eb29ed7']) {
		sh "scp -o StrictHostKeyChecking=no \
		${expandedFileName} \
		pharoorgde@ssh.cluster023.hosting.ovh.net:/home/pharoorgde/files/vm/pharo-spur64-headless/${vmDir}"

		sh "scp -o StrictHostKeyChecking=no \
		${expandedFileName} \
		pharoorgde@ssh.cluster023.hosting.ovh.net:/home/pharoorgde/files/vm/pharo-spur64-headless/${vmDir}/latest.zip"
	}
}

def isPullRequest() {
  return env.CHANGE_ID != null
}

def uploadPackages(){
	node('unix'){
		stage('Upload'){
			if (isPullRequest()) {
				//Only upload files if not in a PR (i.e., CHANGE_ID not empty)
				echo "[DO NO UPLOAD] In PR " + (env.CHANGE_ID?.trim())
				return;
			}
			
			upload('osx', 'mac')
			upload('unix', 'linux')
			upload('windows', 'win')
		}
	}
}

try{
    properties([disableConcurrentBuilds()])

    def platforms = ['unix', 'osx', 'windows']
	def builders = [:]

	for (platf in platforms) {
        // Need to bind the label variable before the closure - can't do 'for (label in labels)'
        def platform = platf
		
		builders[platform] = {
			node(platform){
				timeout(30){
					runBuild(platform)
				}
			}
		}
	}
	
	parallel builders
	
	uploadPackages()

} catch (e) {
  throw e
}