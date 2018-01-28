/* Automatically generated by
	SmartSyntaxPluginCodeGenerator VMMaker.oscog-eem.2309 uuid: 122d5ac0-b546-4f56-a020-8e8988fc5c10
   from
	SHA256Plugin CryptographyPlugins-eem.12 uuid: 2945c878-6a44-4c6a-8374-b56aa6175d0f
 */
static char __buildInfo[] = "SHA256Plugin CryptographyPlugins-eem.12 uuid: 2945c878-6a44-4c6a-8374-b56aa6175d0f " __DATE__ ;



#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
#include "sqConfig.h"			/* Configuration options */
#include "sqVirtualMachine.h"	/*  The virtual machine proxy definition */
#include "sqPlatformSpecific.h"	/* Platform specific definitions */

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
# undef EXPORT
# define EXPORT(returnType) static returnType
#endif

#include "sqMemoryAccess.h"


/*** Function Prototypes ***/
extern sqInt copyintocount(char*x, char*w, unsigned int n);
extern sqInt expand(unsigned int*w);
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) primitiveFinalHashFromState(void);
EXPORT(sqInt) primitiveInitializeState(void);
EXPORT(sqInt) primitivePluginAvailable(void);
EXPORT(sqInt) primitiveProcessBufferWithState(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
extern sqInt sha256InitializeState(unsigned int*state);
extern sqInt sha256ProcessBufferwithState(unsigned int*buffer, unsigned int*state);
static sqInt sqAssert(sqInt aBool);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*failed)(void);
static sqInt (*falseObject)(void);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*isBytes)(sqInt oop);
static sqInt (*pop)(sqInt nItems);
static sqInt (*popthenPush)(sqInt nItems, sqInt oop);
static sqInt (*stackValue)(sqInt offset);
static sqInt (*success)(sqInt aBoolean);
static sqInt (*trueObject)(void);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt failed(void);
extern sqInt falseObject(void);
extern void * firstIndexableField(sqInt oop);
extern sqInt isBytes(sqInt oop);
extern sqInt pop(sqInt nItems);
extern sqInt popthenPush(sqInt nItems, sqInt oop);
extern sqInt stackValue(sqInt offset);
extern sqInt success(sqInt aBoolean);
extern sqInt trueObject(void);
extern
#endif
struct VirtualMachine* interpreterProxy;
static unsigned int k[] = {
/*0*/	1116352408, 1899447441, 3049323471U, 3921009573U, 961987163, 1508970993, 2453635748U,
/*7*/	2870763221U, 3624381080U, 310598401, 607225278, 1426881987, 1925078388, 2162078206U,
/*14*/	2614888103U, 3248222580U, 3835390401U, 4022224774U, 264347078, 604807628,
/*20*/	770255983, 1249150122, 1555081692, 1996064986, 2554220882U, 2821834349U, 2952996808U,
/*27*/	3210313671U, 3336571891U, 3584528711U, 113926993, 338241895, 666307205, 773529912,
/*34*/	1294757372, 1396182291, 1695183700, 1986661051, 2177026350U, 2456956037U,
/*40*/	2730485921U, 2820302411U, 3259730800U, 3345764771U, 3516065817U, 3600352804U,
/*46*/	4094571909U, 275423344, 430227734, 506948616, 659060556, 883997877, 958139571,
/*53*/	1322822218, 1537002063, 1747873779, 1955562222, 2024104815, 2227730452U, 2361852424U,
/*60*/	2428436474U, 2756734187U, 3204031479U, 3329325298U
	};
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"SHA256Plugin CryptographyPlugins-eem.12 (i)"
#else
	"SHA256Plugin CryptographyPlugins-eem.12 (e)"
#endif
;
static unsigned int swap[] = {
		3, 2, 1, 0
	};



/*	copy n unsigned integers from x to w and change their endianness if the
	platform is little endian
 */

	/* SHA256Plugin>>#copy:into:count: */
sqInt
copyintocount(char*x, char*w, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < (4 * n); i += 4) {
		w[i] = (x[i + (swap[0])]);
		w[i + 1] = (x[i + (swap[1])]);
		w[i + 2] = (x[i + (swap[2])]);
		w[i + 3] = (x[i + (swap[3])]);
	}
	return 0;
}

	/* SHA256Plugin>>#expand: */
sqInt
expand(unsigned int*w)
{
	unsigned int i;
	unsigned int s0;
	unsigned int s1;

	for (i = 16; i <= 0x3F; i += 1) {
		s0 = ((((usqInt) (w[i - 15])) >> 7) | (((usqInt)((w[i - 15])) << (32 - 7)))) ^ (((((usqInt) (w[i - 15])) >> 18) | (((usqInt)((w[i - 15])) << (32 - 18)))) ^ (((usqInt) (w[i - 15])) >> 3));
		s1 = ((((usqInt) (w[i - 2])) >> 17) | (((usqInt)((w[i - 2])) << (32 - 17)))) ^ (((((usqInt) (w[i - 2])) >> 19) | (((usqInt)((w[i - 2])) << (32 - 19)))) ^ (((usqInt) (w[i - 2])) >> 10));
		w[i] = (((s0 + s1) + (w[i - 16])) + (w[i - 7]));
	}
	return 0;
}


/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

	/* InterpreterPlugin>>#getModuleName */
EXPORT(const char*)
getModuleName(void)
{
	return moduleName;
}

	/* SHA256Plugin>>#primitiveFinalHash:fromState: */
EXPORT(sqInt)
primitiveFinalHashFromState(void)
{
	unsigned int i;
	char *s;
	char *x;

	success(isBytes(stackValue(1)));
	x = ((char *) (firstIndexableField(stackValue(1))));
	success(isBytes(stackValue(0)));
	s = ((char *) (firstIndexableField(stackValue(0))));
	if (failed()) {
		return null;
	}
	/* begin copy:into:count: */
	for (i = 0; i < (4 * 8); i += 4) {
		(((char*) x))[i] = ((((char*) s))[i + (swap[0])]);
		(((char*) x))[i + 1] = ((((char*) s))[i + (swap[1])]);
		(((char*) x))[i + 2] = ((((char*) s))[i + (swap[2])]);
		(((char*) x))[i + 3] = ((((char*) s))[i + (swap[3])]);
	}
	if (failed()) {
		return null;
	}
	pop(2);
	return null;
}

	/* SHA256Plugin>>#primitiveInitializeState: */
EXPORT(sqInt)
primitiveInitializeState(void)
{
	char *state;
	unsigned int*state1;

	success(isBytes(stackValue(0)));
	state = ((char *) (firstIndexableField(stackValue(0))));
	if (failed()) {
		return null;
	}
	/* begin sha256InitializeState: */
	state1 = ((unsigned int*) state);
	state1[0] = 1779033703;
	state1[1] = 3144134277U;
	state1[2] = 1013904242;
	state1[3] = 2773480762U;
	state1[4] = 1359893119;
	state1[5] = 2600822924U;
	state1[6] = 528734635;
	state1[7] = 1541459225;
	if (failed()) {
		return null;
	}
	pop(1);
	return null;
}

	/* SHA256Plugin>>#primitivePluginAvailable */
EXPORT(sqInt)
primitivePluginAvailable(void)
{
	sqInt _return_value;

	_return_value = ((1) ? trueObject() : falseObject());
	if (failed()) {
		return null;
	}
	popthenPush(1, _return_value);
	return null;
}

	/* SHA256Plugin>>#primitiveProcessBuffer:withState: */
EXPORT(sqInt)
primitiveProcessBufferWithState(void)
{
	unsigned int a;
	unsigned int b;
	char *buffer;
	unsigned int c;
	unsigned int ch;
	unsigned int d;
	unsigned int e;
	unsigned int f;
	unsigned int g;
	unsigned int h;
	unsigned int i;
	unsigned int i1;
	unsigned int i2;
	unsigned int maj;
	unsigned int s0;
	unsigned int s01;
	unsigned int s1;
	unsigned int s11;
	char *state;
	unsigned int*state1;
	unsigned int t1;
	unsigned int t2;
	unsigned int w[64];

	success(isBytes(stackValue(1)));
	buffer = ((char *) (firstIndexableField(stackValue(1))));
	success(isBytes(stackValue(0)));
	state = ((char *) (firstIndexableField(stackValue(0))));
	if (failed()) {
		return null;
	}
	/* begin sha256ProcessBuffer:withState: */
	state1 = ((unsigned int*) state);
	/* begin copy:into:count: */
	for (i1 = 0; i1 < (4 * 16); i1 += 4) {
		(((char*) w))[i1] = ((((char*) (((unsigned int*) buffer))))[i1 + (swap[0])]);
		(((char*) w))[i1 + 1] = ((((char*) (((unsigned int*) buffer))))[i1 + (swap[1])]);
		(((char*) w))[i1 + 2] = ((((char*) (((unsigned int*) buffer))))[i1 + (swap[2])]);
		(((char*) w))[i1 + 3] = ((((char*) (((unsigned int*) buffer))))[i1 + (swap[3])]);
	}
	/* begin expand: */
	for (i2 = 16; i2 <= 0x3F; i2 += 1) {
		s01 = ((((usqInt) ((((unsigned int*) w))[i2 - 15])) >> 7) | (((usqInt)(((((unsigned int*) w))[i2 - 15])) << (32 - 7)))) ^ (((((usqInt) ((((unsigned int*) w))[i2 - 15])) >> 18) | (((usqInt)(((((unsigned int*) w))[i2 - 15])) << (32 - 18)))) ^ (((usqInt) ((((unsigned int*) w))[i2 - 15])) >> 3));
		s11 = ((((usqInt) ((((unsigned int*) w))[i2 - 2])) >> 17) | (((usqInt)(((((unsigned int*) w))[i2 - 2])) << (32 - 17)))) ^ (((((usqInt) ((((unsigned int*) w))[i2 - 2])) >> 19) | (((usqInt)(((((unsigned int*) w))[i2 - 2])) << (32 - 19)))) ^ (((usqInt) ((((unsigned int*) w))[i2 - 2])) >> 10));
		(((unsigned int*) w))[i2] = (((s01 + s11) + ((((unsigned int*) w))[i2 - 16])) + ((((unsigned int*) w))[i2 - 7]));
	}
	a = state1[0];
	b = state1[1];
	c = state1[2];
	d = state1[3];
	e = state1[4];
	f = state1[5];
	g = state1[6];
	h = state1[7];
	for (i = 0; i <= 0x3F; i += 1) {
		s0 = ((((usqInt) a) >> 2) | (((usqInt)(a) << (32 - 2)))) ^ (((((usqInt) a) >> 13) | (((usqInt)(a) << (32 - 13)))) ^ ((((usqInt) a) >> 22) | (((usqInt)(a) << (32 - 22)))));
		maj = (a & b) ^ ((a & c) ^ (b & c));
		t2 = s0 + maj;
		s1 = ((((usqInt) e) >> 6) | (((usqInt)(e) << (32 - 6)))) ^ (((((usqInt) e) >> 11) | (((usqInt)(e) << (32 - 11)))) ^ ((((usqInt) e) >> 25) | (((usqInt)(e) << (32 - 25)))));
		ch = (e & f) ^ (((unsigned int)~e) & g);
		t1 = (((h + s1) + ch) + (k[i])) + (w[i]);
		h = g;
		g = f;
		f = e;
		e = d + t1;
		d = c;
		c = b;
		b = a;
		a = t1 + t2;
	}
	state1[0] = ((state1[0]) + a);
	state1[1] = ((state1[1]) + b);
	state1[2] = ((state1[2]) + c);
	state1[3] = ((state1[3]) + d);
	state1[4] = ((state1[4]) + e);
	state1[5] = ((state1[5]) + f);
	state1[6] = ((state1[6]) + g);
	state1[7] = ((state1[7]) + h);
	if (failed()) {
		return null;
	}
	pop(2);
	return null;
}


/*	Note: This is coded so that it can be run in Squeak. */

	/* InterpreterPlugin>>#setInterpreter: */
EXPORT(sqInt)
setInterpreter(struct VirtualMachine*anInterpreter)
{
	sqInt ok;

	interpreterProxy = anInterpreter;
	ok = ((interpreterProxy->majorVersion()) == (VM_PROXY_MAJOR))
	 && ((interpreterProxy->minorVersion()) >= (VM_PROXY_MINOR));
	if (ok) {
		
#if !defined(SQUEAK_BUILTIN_PLUGIN)
		failed = interpreterProxy->failed;
		falseObject = interpreterProxy->falseObject;
		firstIndexableField = interpreterProxy->firstIndexableField;
		isBytes = interpreterProxy->isBytes;
		pop = interpreterProxy->pop;
		popthenPush = interpreterProxy->popthenPush;
		stackValue = interpreterProxy->stackValue;
		success = interpreterProxy->success;
		trueObject = interpreterProxy->trueObject;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}


/*	#(2 3 5 7 11 13 17 19) collect: [:x | (x asFloat sqrt fractionPart * (2
	raisedTo: 32)) truncated storeStringHex ]
 */

	/* SHA256Plugin>>#sha256InitializeState: */
sqInt
sha256InitializeState(unsigned int*state)
{
	state[0] = 1779033703;
	state[1] = 3144134277U;
	state[2] = 1013904242;
	state[3] = 2773480762U;
	state[4] = 1359893119;
	state[5] = 2600822924U;
	state[6] = 528734635;
	state[7] = 1541459225;
	return 0;
}

	/* SHA256Plugin>>#sha256ProcessBuffer:withState: */
sqInt
sha256ProcessBufferwithState(unsigned int*buffer, unsigned int*state)
{
	unsigned int a;
	unsigned int b;
	unsigned int c;
	unsigned int ch;
	unsigned int d;
	unsigned int e;
	unsigned int f;
	unsigned int g;
	unsigned int h;
	unsigned int i;
	unsigned int i1;
	unsigned int i2;
	unsigned int maj;
	unsigned int s0;
	unsigned int s01;
	unsigned int s1;
	unsigned int s11;
	unsigned int t1;
	unsigned int t2;
	unsigned int w[64];

	/* begin copy:into:count: */
	for (i1 = 0; i1 < (4 * 16); i1 += 4) {
		(((char*) w))[i1] = ((((char*) buffer))[i1 + (swap[0])]);
		(((char*) w))[i1 + 1] = ((((char*) buffer))[i1 + (swap[1])]);
		(((char*) w))[i1 + 2] = ((((char*) buffer))[i1 + (swap[2])]);
		(((char*) w))[i1 + 3] = ((((char*) buffer))[i1 + (swap[3])]);
	}
	/* begin expand: */
	for (i2 = 16; i2 <= 0x3F; i2 += 1) {
		s01 = ((((usqInt) ((((unsigned int*) w))[i2 - 15])) >> 7) | (((usqInt)(((((unsigned int*) w))[i2 - 15])) << (32 - 7)))) ^ (((((usqInt) ((((unsigned int*) w))[i2 - 15])) >> 18) | (((usqInt)(((((unsigned int*) w))[i2 - 15])) << (32 - 18)))) ^ (((usqInt) ((((unsigned int*) w))[i2 - 15])) >> 3));
		s11 = ((((usqInt) ((((unsigned int*) w))[i2 - 2])) >> 17) | (((usqInt)(((((unsigned int*) w))[i2 - 2])) << (32 - 17)))) ^ (((((usqInt) ((((unsigned int*) w))[i2 - 2])) >> 19) | (((usqInt)(((((unsigned int*) w))[i2 - 2])) << (32 - 19)))) ^ (((usqInt) ((((unsigned int*) w))[i2 - 2])) >> 10));
		(((unsigned int*) w))[i2] = (((s01 + s11) + ((((unsigned int*) w))[i2 - 16])) + ((((unsigned int*) w))[i2 - 7]));
	}
	a = state[0];
	b = state[1];
	c = state[2];
	d = state[3];
	e = state[4];
	f = state[5];
	g = state[6];
	h = state[7];
	for (i = 0; i <= 0x3F; i += 1) {
		s0 = ((((usqInt) a) >> 2) | (((usqInt)(a) << (32 - 2)))) ^ (((((usqInt) a) >> 13) | (((usqInt)(a) << (32 - 13)))) ^ ((((usqInt) a) >> 22) | (((usqInt)(a) << (32 - 22)))));
		maj = (a & b) ^ ((a & c) ^ (b & c));
		t2 = s0 + maj;
		s1 = ((((usqInt) e) >> 6) | (((usqInt)(e) << (32 - 6)))) ^ (((((usqInt) e) >> 11) | (((usqInt)(e) << (32 - 11)))) ^ ((((usqInt) e) >> 25) | (((usqInt)(e) << (32 - 25)))));
		ch = (e & f) ^ (((unsigned int)~e) & g);
		t1 = (((h + s1) + ch) + (k[i])) + (w[i]);
		h = g;
		g = f;
		f = e;
		e = d + t1;
		d = c;
		c = b;
		b = a;
		a = t1 + t2;
	}
	state[0] = ((state[0]) + a);
	state[1] = ((state[1]) + b);
	state[2] = ((state[2]) + c);
	state[3] = ((state[3]) + d);
	state[4] = ((state[4]) + e);
	state[5] = ((state[5]) + f);
	state[6] = ((state[6]) + g);
	state[7] = ((state[7]) + h);
	return 0;
}

	/* SmartSyntaxInterpreterPlugin>>#sqAssert: */
static sqInt
sqAssert(sqInt aBool)
{
	/* missing DebugCode */;
	return aBool;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "SHA256Plugin";
void* SHA256Plugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "primitiveFinalHashFromState\000\377", (void*)primitiveFinalHashFromState},
	{(void*)_m, "primitiveInitializeState\000\377", (void*)primitiveInitializeState},
	{(void*)_m, "primitivePluginAvailable\000\377", (void*)primitivePluginAvailable},
	{(void*)_m, "primitiveProcessBufferWithState\000\377", (void*)primitiveProcessBufferWithState},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */


#endif /* ifdef SQ_BUILTIN_PLUGIN */
