

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Fri Jul 11 15:41:54 2014
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


#ifndef __ISubSearch_FWD_DEFINED__
#define __ISubSearch_FWD_DEFINED__
typedef interface ISubSearch ISubSearch;

#endif 	/* __ISubSearch_FWD_DEFINED__ */


#ifndef __SubSearch_FWD_DEFINED__
#define __SubSearch_FWD_DEFINED__

#ifdef __cplusplus
typedef class SubSearch SubSearch;
#else
typedef struct SubSearch SubSearch;
#endif /* __cplusplus */

#endif 	/* __SubSearch_FWD_DEFINED__ */


#ifndef __ISubInsert_FWD_DEFINED__
#define __ISubInsert_FWD_DEFINED__
typedef interface ISubInsert ISubInsert;

#endif 	/* __ISubInsert_FWD_DEFINED__ */


#ifndef __SubInsert_FWD_DEFINED__
#define __SubInsert_FWD_DEFINED__

#ifdef __cplusplus
typedef class SubInsert SubInsert;
#else
typedef struct SubInsert SubInsert;
#endif /* __cplusplus */

#endif 	/* __SubInsert_FWD_DEFINED__ */


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


#ifndef __ISubMapECNU_FWD_DEFINED__
#define __ISubMapECNU_FWD_DEFINED__
typedef interface ISubMapECNU ISubMapECNU;

#endif 	/* __ISubMapECNU_FWD_DEFINED__ */


#ifndef __SubMapECNU_FWD_DEFINED__
#define __SubMapECNU_FWD_DEFINED__

#ifdef __cplusplus
typedef class SubMapECNU SubMapECNU;
#else
typedef struct SubMapECNU SubMapECNU;
#endif /* __cplusplus */

#endif 	/* __SubMapECNU_FWD_DEFINED__ */


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

#ifndef __ISubSearch_DISPINTERFACE_DEFINED__
#define __ISubSearch_DISPINTERFACE_DEFINED__

/* dispinterface ISubSearch */
/* [uuid] */ 


EXTERN_C const IID DIID_ISubSearch;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("06999DF4-A175-421B-BD02-B11743FDD4E4")
    ISubSearch : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ISubSearchVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISubSearch * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISubSearch * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISubSearch * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISubSearch * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISubSearch * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISubSearch * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISubSearch * This,
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
    } ISubSearchVtbl;

    interface ISubSearch
    {
        CONST_VTBL struct ISubSearchVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISubSearch_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISubSearch_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISubSearch_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISubSearch_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISubSearch_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISubSearch_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISubSearch_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ISubSearch_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SubSearch;

#ifdef __cplusplus

class DECLSPEC_UUID("13D80995-5805-44E9-8549-5AA1E647AA48")
SubSearch;
#endif

#ifndef __ISubInsert_DISPINTERFACE_DEFINED__
#define __ISubInsert_DISPINTERFACE_DEFINED__

/* dispinterface ISubInsert */
/* [uuid] */ 


EXTERN_C const IID DIID_ISubInsert;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("2D222094-DF36-4F51-AE8C-50B3B78A0615")
    ISubInsert : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ISubInsertVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISubInsert * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISubInsert * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISubInsert * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISubInsert * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISubInsert * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISubInsert * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISubInsert * This,
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
    } ISubInsertVtbl;

    interface ISubInsert
    {
        CONST_VTBL struct ISubInsertVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISubInsert_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISubInsert_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISubInsert_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISubInsert_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISubInsert_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISubInsert_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISubInsert_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ISubInsert_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SubInsert;

#ifdef __cplusplus

class DECLSPEC_UUID("8E8006F3-B4B0-481E-8130-86096B9A98F7")
SubInsert;
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

#ifndef __ISubMapECNU_DISPINTERFACE_DEFINED__
#define __ISubMapECNU_DISPINTERFACE_DEFINED__

/* dispinterface ISubMapECNU */
/* [uuid] */ 


EXTERN_C const IID DIID_ISubMapECNU;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("AD9EC178-95AC-4A49-B1F2-15DD03905F22")
    ISubMapECNU : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct ISubMapECNUVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISubMapECNU * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISubMapECNU * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISubMapECNU * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISubMapECNU * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISubMapECNU * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISubMapECNU * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISubMapECNU * This,
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
    } ISubMapECNUVtbl;

    interface ISubMapECNU
    {
        CONST_VTBL struct ISubMapECNUVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISubMapECNU_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISubMapECNU_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISubMapECNU_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISubMapECNU_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISubMapECNU_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISubMapECNU_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISubMapECNU_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __ISubMapECNU_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SubMapECNU;

#ifdef __cplusplus

class DECLSPEC_UUID("13F71C93-A6CD-48C1-91F3-175DD92A82B7")
SubMapECNU;
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


