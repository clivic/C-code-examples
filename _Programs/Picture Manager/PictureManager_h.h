

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Sun Jul 13 02:55:25 2014
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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __PictureManager_h_h__
#define __PictureManager_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IPictureManager_FWD_DEFINED__
#define __IPictureManager_FWD_DEFINED__
typedef interface IPictureManager IPictureManager;

#endif 	/* __IPictureManager_FWD_DEFINED__ */


#ifndef __PictureManager_FWD_DEFINED__
#define __PictureManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class PictureManager PictureManager;
#else
typedef struct PictureManager PictureManager;
#endif /* __cplusplus */

#endif 	/* __PictureManager_FWD_DEFINED__ */


#ifndef __ISubSearchByName_FWD_DEFINED__
#define __ISubSearchByName_FWD_DEFINED__
typedef interface ISubSearchByName ISubSearchByName;

#endif 	/* __ISubSearchByName_FWD_DEFINED__ */


#ifndef __SubSearchByName_FWD_DEFINED__
#define __SubSearchByName_FWD_DEFINED__

#ifdef __cplusplus
typedef class SubSearchByName SubSearchByName;
#else
typedef struct SubSearchByName SubSearchByName;
#endif /* __cplusplus */

#endif 	/* __SubSearchByName_FWD_DEFINED__ */


#ifndef __ISubAddNewPic_FWD_DEFINED__
#define __ISubAddNewPic_FWD_DEFINED__
typedef interface ISubAddNewPic ISubAddNewPic;

#endif 	/* __ISubAddNewPic_FWD_DEFINED__ */


#ifndef __SubAddNewPic_FWD_DEFINED__
#define __SubAddNewPic_FWD_DEFINED__

#ifdef __cplusplus
typedef class SubAddNewPic SubAddNewPic;
#else
typedef struct SubAddNewPic SubAddNewPic;
#endif /* __cplusplus */

#endif 	/* __SubAddNewPic_FWD_DEFINED__ */


#ifndef __ISubGetOnePic_FWD_DEFINED__
#define __ISubGetOnePic_FWD_DEFINED__
typedef interface ISubGetOnePic ISubGetOnePic;

#endif 	/* __ISubGetOnePic_FWD_DEFINED__ */


#ifndef __SubGetOnePic_FWD_DEFINED__
#define __SubGetOnePic_FWD_DEFINED__

#ifdef __cplusplus
typedef class SubGetOnePic SubGetOnePic;
#else
typedef struct SubGetOnePic SubGetOnePic;
#endif /* __cplusplus */

#endif 	/* __SubGetOnePic_FWD_DEFINED__ */


#ifndef __ISubFootPrintECNU_FWD_DEFINED__
#define __ISubFootPrintECNU_FWD_DEFINED__
typedef interface ISubFootPrintECNU ISubFootPrintECNU;

#endif 	/* __ISubFootPrintECNU_FWD_DEFINED__ */


#ifndef __SubFootPrintECNU_FWD_DEFINED__
#define __SubFootPrintECNU_FWD_DEFINED__

#ifdef __cplusplus
typedef class SubFootPrintECNU SubFootPrintECNU;
#else
typedef struct SubFootPrintECNU SubFootPrintECNU;
#endif /* __cplusplus */

#endif 	/* __SubFootPrintECNU_FWD_DEFINED__ */


#ifndef __ISubTestTime_FWD_DEFINED__
#define __ISubTestTime_FWD_DEFINED__
typedef interface ISubTestTime ISubTestTime;

#endif 	/* __ISubTestTime_FWD_DEFINED__ */


#ifndef __SubTestTime_FWD_DEFINED__
#define __SubTestTime_FWD_DEFINED__

#ifdef __cplusplus
typedef class SubTestTime SubTestTime;
#else
typedef struct SubTestTime SubTestTime;
#endif /* __cplusplus */

#endif 	/* __SubTestTime_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __PictureManager_LIBRARY_DEFINED__
#define __PictureManager_LIBRARY_DEFINED__

/* library PictureManager */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_PictureManager;

#ifndef __IPictureManager_DISPINTERFACE_DEFINED__
#define __IPictureManager_DISPINTERFACE_DEFINED__

/* dispinterface IPictureManager */
/* [uuid] */ 


EXTERN_C const IID DIID_IPictureManager;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("1DBA136B-0F19-4980-B86E-C08CF6880407")
    IPictureManager : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IPictureManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPictureManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPictureManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPictureManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPictureManager * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPictureManager * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPictureManager * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPictureManager * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IPictureManagerVtbl;

    interface IPictureManager
    {
        CONST_VTBL struct IPictureManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPictureManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPictureManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPictureManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPictureManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPictureManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPictureManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPictureManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IPictureManager_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_PictureManager;

#ifdef __cplusplus

class DECLSPEC_UUID("9E4494A9-A9A1-461D-8B81-E1EB4739E618")
PictureManager;
#endif

#ifndef __ISubSearchByName_DISPINTERFACE_DEFINED__
#define __ISubSearchByName_DISPINTERFACE_DEFINED__

/* dispinterface ISubSearchByName */
/* [uuid] */ 


EXTERN_C const IID DIID_ISubSearchByName;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("06999DF4-A175-421B-BD02-B11743FDD4E4")
    ISubSearchByName : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ISubSearchByNameVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISubSearchByName * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISubSearchByName * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISubSearchByName * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISubSearchByName * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISubSearchByName * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISubSearchByName * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISubSearchByName * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ISubSearchByNameVtbl;

    interface ISubSearchByName
    {
        CONST_VTBL struct ISubSearchByNameVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISubSearchByName_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISubSearchByName_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISubSearchByName_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISubSearchByName_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISubSearchByName_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISubSearchByName_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISubSearchByName_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ISubSearchByName_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SubSearchByName;

#ifdef __cplusplus

class DECLSPEC_UUID("13D80995-5805-44E9-8549-5AA1E647AA48")
SubSearchByName;
#endif

#ifndef __ISubAddNewPic_DISPINTERFACE_DEFINED__
#define __ISubAddNewPic_DISPINTERFACE_DEFINED__

/* dispinterface ISubAddNewPic */
/* [uuid] */ 


EXTERN_C const IID DIID_ISubAddNewPic;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("2D222094-DF36-4F51-AE8C-50B3B78A0615")
    ISubAddNewPic : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ISubAddNewPicVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISubAddNewPic * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISubAddNewPic * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISubAddNewPic * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISubAddNewPic * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISubAddNewPic * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISubAddNewPic * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISubAddNewPic * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ISubAddNewPicVtbl;

    interface ISubAddNewPic
    {
        CONST_VTBL struct ISubAddNewPicVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISubAddNewPic_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISubAddNewPic_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISubAddNewPic_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISubAddNewPic_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISubAddNewPic_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISubAddNewPic_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISubAddNewPic_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ISubAddNewPic_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SubAddNewPic;

#ifdef __cplusplus

class DECLSPEC_UUID("8E8006F3-B4B0-481E-8130-86096B9A98F7")
SubAddNewPic;
#endif

#ifndef __ISubGetOnePic_DISPINTERFACE_DEFINED__
#define __ISubGetOnePic_DISPINTERFACE_DEFINED__

/* dispinterface ISubGetOnePic */
/* [uuid] */ 


EXTERN_C const IID DIID_ISubGetOnePic;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("C6A05288-1BE8-4C9A-828E-54DB7B879E45")
    ISubGetOnePic : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ISubGetOnePicVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISubGetOnePic * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISubGetOnePic * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISubGetOnePic * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISubGetOnePic * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISubGetOnePic * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISubGetOnePic * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISubGetOnePic * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ISubGetOnePicVtbl;

    interface ISubGetOnePic
    {
        CONST_VTBL struct ISubGetOnePicVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISubGetOnePic_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISubGetOnePic_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISubGetOnePic_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISubGetOnePic_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISubGetOnePic_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISubGetOnePic_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISubGetOnePic_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ISubGetOnePic_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SubGetOnePic;

#ifdef __cplusplus

class DECLSPEC_UUID("AA0DDC2C-CB69-4229-9AB7-227CE49F6FCC")
SubGetOnePic;
#endif

#ifndef __ISubFootPrintECNU_DISPINTERFACE_DEFINED__
#define __ISubFootPrintECNU_DISPINTERFACE_DEFINED__

/* dispinterface ISubFootPrintECNU */
/* [uuid] */ 


EXTERN_C const IID DIID_ISubFootPrintECNU;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("AD9EC178-95AC-4A49-B1F2-15DD03905F22")
    ISubFootPrintECNU : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ISubFootPrintECNUVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISubFootPrintECNU * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISubFootPrintECNU * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISubFootPrintECNU * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISubFootPrintECNU * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISubFootPrintECNU * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISubFootPrintECNU * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISubFootPrintECNU * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ISubFootPrintECNUVtbl;

    interface ISubFootPrintECNU
    {
        CONST_VTBL struct ISubFootPrintECNUVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISubFootPrintECNU_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISubFootPrintECNU_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISubFootPrintECNU_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISubFootPrintECNU_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISubFootPrintECNU_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISubFootPrintECNU_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISubFootPrintECNU_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ISubFootPrintECNU_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SubFootPrintECNU;

#ifdef __cplusplus

class DECLSPEC_UUID("13F71C93-A6CD-48C1-91F3-175DD92A82B7")
SubFootPrintECNU;
#endif

#ifndef __ISubTestTime_DISPINTERFACE_DEFINED__
#define __ISubTestTime_DISPINTERFACE_DEFINED__

/* dispinterface ISubTestTime */
/* [uuid] */ 


EXTERN_C const IID DIID_ISubTestTime;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("7E9A95C9-DE8A-4B37-95D4-B217672A1365")
    ISubTestTime : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ISubTestTimeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISubTestTime * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISubTestTime * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISubTestTime * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISubTestTime * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISubTestTime * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISubTestTime * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISubTestTime * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } ISubTestTimeVtbl;

    interface ISubTestTime
    {
        CONST_VTBL struct ISubTestTimeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISubTestTime_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISubTestTime_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISubTestTime_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISubTestTime_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISubTestTime_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISubTestTime_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISubTestTime_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ISubTestTime_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SubTestTime;

#ifdef __cplusplus

class DECLSPEC_UUID("D3A49992-F049-48A2-873C-1FCF98236084")
SubTestTime;
#endif
#endif /* __PictureManager_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


