#ifndef _JACK_LIN_TYPES_H_
#define _JACK_LIN_TYPES_H_

//data types start
typedef unsigned char UInt8;
typedef char SInt8;
typedef signed char Int8;
typedef unsigned short UInt16;
typedef signed short SInt16;
typedef unsigned int UInt32;
typedef signed int SInt32;
typedef unsigned long ULong32;
typedef signed long SLong32;
typedef unsigned long long UInt64;
typedef signed long long SInt64;
typedef float Double32;
typedef double Double64;
//data types end

typedef UInt32 return_t;
typedef UInt8 BOOL;

#define JACK_TRUE ((UInt8)1)
#define JACK_FALSE ((UInt8)0)

#define JACK_FAILURE ((UInt32)0)
#define JACK_SUCCESS ((UInt32)1)

#ifndef PNULL
#define PNULL ((void*)0)
#endif

#define BOOL_COMPARE_AND_SWAP(a,b,c) __sync_bool_compare_and_swap((SInt32*)(a),(SInt32)(b),(SInt32)(c))
#define FETCH_AND_ADD_EV32(a,b) __sync_fetch_and_add((SInt32*)(a),(b))
#define FETCH_AND_ADD_EV64(a,b) __sync_fetch_and_add((SInt64*)(a),(b))
#define FETCH_AND_SUB_EV32(a,b) __sync_fetch_and_sub((SInt32*)(a),(b))



#endif
