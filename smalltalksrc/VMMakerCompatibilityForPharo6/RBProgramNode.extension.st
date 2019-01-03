Extension { #name : #RBProgramNode }

{ #category : #'*VMMakerCompatibilityForPharo6-C translation' }
RBProgramNode >> asTranslatorNodeIn: aTMethod [
	"Answer a TParseNode subclass equivalent of me"
	self subclassResponsibility
]

{ #category : #'*VMMakerCompatibilityForPharo6-C translation' }
RBProgramNode >> commentOrNil [
	^self propertyAt: #comments ifAbsent: []
]

{ #category : #'*VMMakerCompatibilityForPharo6-testing' }
RBProgramNode >> isBlockNode [
	^false
]

{ #category : #'*VMMakerCompatibilityForPharo6-testing' }
RBProgramNode >> isConstantNumber [  "Overridden in RBLiteralValueNode"
	^false
]

{ #category : #'*VMMakerCompatibilityForPharo6-testing' }
RBProgramNode >> isNodeNil [
	^false
]

{ #category : #'*VMMakerCompatibilityForPharo6-testing' }
RBProgramNode >> isVariableNode [
	^false
]

{ #category : #'*VMMakerCompatibilityForPharo6-C translation' }
RBProgramNode >> missingCommentNeededForCTranslation [
	"So far the RBProgramNode hierarchy omits/elides comments :-("
	^nil
]