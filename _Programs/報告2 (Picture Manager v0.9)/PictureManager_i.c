

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Thu Jul 10 17:05:52 2014
 */
/* Compiler settings for PictureManager.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_PictureManager,0x6B2098AE,0xFEFD,0x4D72,0xBC,0x8F,0xA9,0x0C,0x4D,0x2E,0xC9,0x46);


MIDL_DEFINE_GUID(IID, DIID_IPictureManager,0x1DBA136B,0x0F19,0x4980,0xB8,0x6E,0xC0,0x8C,0xF6,0x88,0x04,0x07);


MIDL_DEFINE_GUID(CLSID, CLSID_PictureManager,0x9E4494A9,0xA9A1,0x461D,0x8B,0x81,0xE1,0xEB,0x47,0x39,0xE6,0x18);


MIDL_DEFINE_GUID(IID, DIID_ISubSearchByName,0x06999DF4,0xA175,0x421B,0xBD,0x02,0xB1,0x17,0x43,0xFD,0xD4,0xE4);


MIDL_DEFINE_GUID(CLSID, CLSID_SubSearchByName,0x13D80995,0x5805,0x44E9,0x85,0x49,0x5A,0xA1,0xE6,0x47,0xAA,0x48);


MIDL_DEFINE_GUID(IID, DIID_ISubAddNewPic,0x2D222094,0xDF36,0x4F51,0xAE,0x8C,0x50,0xB3,0xB7,0x8A,0x06,0x15);


MIDL_DEFINE_GUID(CLSID, CLSID_SubAddNewPic,0x8E8006F3,0xB4B0,0x481E,0x81,0x30,0x86,0x09,0x6B,0x9A,0x98,0xF7);


MIDL_DEFINE_GUID(IID, DIID_ISubGetOnePic,0xC6A05288,0x1BE8,0x4C9A,0x82,0x8E,0x54,0xDB,0x7B,0x87,0x9E,0x45);


MIDL_DEFINE_GUID(CLSID, CLSID_SubGetOnePic,0xAA0DDC2C,0xCB69,0x4229,0x9A,0xB7,0x22,0x7C,0xE4,0x9F,0x6F,0xCC);


MIDL_DEFINE_GUID(IID, DIID_ISubFootprint,0xAD9EC178,0x95AC,0x4A49,0xB1,0xF2,0x15,0xDD,0x03,0x90,0x5F,0x22);


MIDL_DEFINE_GUID(CLSID, CLSID_SubFootprint,0x13F71C93,0xA6CD,0x48C1,0x91,0xF3,0x17,0x5D,0xD9,0x2A,0x82,0xB7);


MIDL_DEFINE_GUID(IID, DIID_ISubTestTime,0x7E9A95C9,0xDE8A,0x4B37,0x95,0xD4,0xB2,0x17,0x67,0x2A,0x13,0x65);


MIDL_DEFINE_GUID(CLSID, CLSID_SubTestTime,0xD3A49992,0xF049,0x48A2,0x87,0x3C,0x1F,0xCF,0x98,0x23,0x60,0x84);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



