# Deployment filter (compatible with Travis and AppVeyor)
#
# execute script if: 
#   - REPOSITORY=OpenSmalltalk/opensmalltalk-vm
#   - BRANCH=Cog or TAG_NAME is not empty

readonly REPO_NAME="${TRAVIS_REPO_SLUG:-${APPVEYOR_REPO_NAME}}"
readonly BRANCH_NAME="${TRAVIS_BRANCH:-${APPVEYOR_REPO_BRANCH}}"
readonly TAG_NAME="${TRAVIS_TAG:-${APPVEYOR_REPO_TAG_NAME}}"

if [[ "${REPO_NAME}" != "OpenSmalltalk/opensmalltalk-vm" ]]; then
	echo "Trying to deploy in repository: ${APPVEYOR_REPO_NAME}. Skipping."
	exit
fi

if [[ "${BRANCH_NAME}" != "Cog" ]] && [[ -z "${TAG_NAME}" ]]; then
  echo "Skipping a deployment with the script provider because this branch is not permitted"
	exit
fi

`dirname $0`/$1