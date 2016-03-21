

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Mon Mar 21 23:58:52 2016
 */
/* Compiler settings for SafeTextBoxControl.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
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


#ifndef __SafeTextBoxControlidl_h__
#define __SafeTextBoxControlidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DSafeTextBoxControl_FWD_DEFINED__
#define ___DSafeTextBoxControl_FWD_DEFINED__
typedef interface _DSafeTextBoxControl _DSafeTextBoxControl;
#endif 	/* ___DSafeTextBoxControl_FWD_DEFINED__ */


#ifndef ___DSafeTextBoxControlEvents_FWD_DEFINED__
#define ___DSafeTextBoxControlEvents_FWD_DEFINED__
typedef interface _DSafeTextBoxControlEvents _DSafeTextBoxControlEvents;
#endif 	/* ___DSafeTextBoxControlEvents_FWD_DEFINED__ */


#ifndef __SafeTextBoxControl_FWD_DEFINED__
#define __SafeTextBoxControl_FWD_DEFINED__

#ifdef __cplusplus
typedef class SafeTextBoxControl SafeTextBoxControl;
#else
typedef struct SafeTextBoxControl SafeTextBoxControl;
#endif /* __cplusplus */

#endif 	/* __SafeTextBoxControl_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __SafeTextBoxControlLib_LIBRARY_DEFINED__
#define __SafeTextBoxControlLib_LIBRARY_DEFINED__

/* library SafeTextBoxControlLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_SafeTextBoxControlLib;

#ifndef ___DSafeTextBoxControl_DISPINTERFACE_DEFINED__
#define ___DSafeTextBoxControl_DISPINTERFACE_DEFINED__

/* dispinterface _DSafeTextBoxControl */
/* [uuid] */ 


EXTERN_C const IID DIID__DSafeTextBoxControl;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("DE709E5D-8662-4A83-9273-0AF359B91AB1")
    _DSafeTextBoxControl : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DSafeTextBoxControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DSafeTextBoxControl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DSafeTextBoxControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DSafeTextBoxControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DSafeTextBoxControl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DSafeTextBoxControl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DSafeTextBoxControl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DSafeTextBoxControl * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DSafeTextBoxControlVtbl;

    interface _DSafeTextBoxControl
    {
        CONST_VTBL struct _DSafeTextBoxControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DSafeTextBoxControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DSafeTextBoxControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DSafeTextBoxControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DSafeTextBoxControl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DSafeTextBoxControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DSafeTextBoxControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DSafeTextBoxControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DSafeTextBoxControl_DISPINTERFACE_DEFINED__ */


#ifndef ___DSafeTextBoxControlEvents_DISPINTERFACE_DEFINED__
#define ___DSafeTextBoxControlEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DSafeTextBoxControlEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DSafeTextBoxControlEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("AD32A0DC-6667-45F0-9C64-F08C262C9372")
    _DSafeTextBoxControlEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DSafeTextBoxControlEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DSafeTextBoxControlEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DSafeTextBoxControlEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DSafeTextBoxControlEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DSafeTextBoxControlEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DSafeTextBoxControlEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DSafeTextBoxControlEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DSafeTextBoxControlEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DSafeTextBoxControlEventsVtbl;

    interface _DSafeTextBoxControlEvents
    {
        CONST_VTBL struct _DSafeTextBoxControlEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DSafeTextBoxControlEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DSafeTextBoxControlEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DSafeTextBoxControlEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DSafeTextBoxControlEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DSafeTextBoxControlEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DSafeTextBoxControlEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DSafeTextBoxControlEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DSafeTextBoxControlEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SafeTextBoxControl;

#ifdef __cplusplus

class DECLSPEC_UUID("0D40C51E-2774-4FF7-9462-57091653AA87")
SafeTextBoxControl;
#endif
#endif /* __SafeTextBoxControlLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


