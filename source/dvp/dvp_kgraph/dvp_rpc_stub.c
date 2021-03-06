/**
 *  Copyright (C) 2009-2011 Texas Instruments, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#if !defined(DVP_USE_IPC)

//******************************************************************************
// INCLUDES
//******************************************************************************

#include <sosal/sosal.h>

#include <dvp/dvp.h>
#include <dvp/dvp_debug.h>
// @NOTE we include dvp_rpc.h further down in the file...

//******************************************************************************
// #DEFINES
//******************************************************************************

//******************************************************************************
// TYPEDEFS
//******************************************************************************

typedef struct _dvp_rpc_core_t DVP_RPC_Core_t;

typedef struct _dvp_rpc_t {
    DVP_Handle handle;         /** This contains the pointer back the DVP_t. It MUST be the FIRST entry in the structure! */
    mutex_t    lock;
    DVP_RPC_Core_t *cores[DVP_CORE_MAX];
} DVP_RPC_t;

struct _dvp_rpc_core_t {
    DVP_S32 coreEnum;
    void *callback; // will be later cast the proper type
    void *cookie;
};

#define DVP_RPC_T   // we're defining the RPC structure locally!
#include <dvp_rpc.h>

//******************************************************************************
// LOCAL VARIABLES
//******************************************************************************


//******************************************************************************
// LOCAL FUNCTIONS
//******************************************************************************

DVP_RPC_t *dvp_rpc_init()
{
    return (DVP_RPC_t *)calloc(1, sizeof(DVP_RPC_t));
}

void dvp_rpc_deinit(DVP_RPC_t **rpc)
{
    free(*rpc);
    *rpc = NULL;
}

void dvp_rpc_restart_callback_register(DVP_RPC_t *rpc,
                                       DVP_RPC_Core_t *rpcc,
                                       dvp_rpc_restart_f func,
                                       void *cookie)
{
    ; // do nothing
}

DVP_PTR dvp_rpc_mem_xlate_fwrd(DVP_RPC_t *rpc,
                               DVP_Core_e core,
                               DVP_PTR localAddr,
                               DVP_U32 localSize,
                               DVP_MemType_e memType)
{
    return NULL;
}

DVP_PTR dvp_rpc_mem_xlate_back(DVP_RPC_t *rpc,
                               DVP_Core_e core,
                               DVP_PTR remoteAddr,
                               DVP_MemType_e memType)
{
    return NULL;
}

void dvp_rpc_mem_remove(DVP_RPC_t *rpc,
                        DVP_PTR localAddr,
                        DVP_U32 localSize,
                        DVP_MemType_e memType)
{
    ; // do nothing
}

DVP_RPC_Core_t *dvp_rpc_core_init(DVP_RPC_t *rpc, DVP_RPC_Interface_t *rpci)
{
    return (DVP_RPC_Core_t *)calloc(1, sizeof(DVP_RPC_Core_t));
}

void dvp_rpc_core_deinit(DVP_RPC_t *rpc, DVP_RPC_Core_t **rpcc)
{
    free(*rpcc);
    *rpcc = NULL;
}

DVP_BOOL dvp_rpc_dissociate(DVP_RPC_t *rpc,
                            DVP_Mem_t *mem,
                            DVP_PTR ptr,
                            DVP_VALUE *pHandle,
                            size_t size,
                            DVP_MemType_e mtype)
{
    return DVP_FALSE;
}

DVP_BOOL dvp_rpc_associate(DVP_RPC_t *rpc,
                           DVP_Mem_t *mem,
                           DVP_PTR ptr,
                           DVP_VALUE handle,
                           size_t size,
                           DVP_MemType_e mtype)
{
    return DVP_FALSE;
}

DVP_VALUE dvp_rpc_get_handle(DVP_RPC_t *rpc, DVP_PTR ptr)
{
    return 0;
}

int dvp_rpc_remote_execute(DVP_RPC_t *rpc,
                           DVP_RPC_Core_t *rpcc,
                           int cliIndex,
                           DVP_RPC_Parameter_t *params,
                           DVP_U32 numParams,
                           DVP_RPC_Translation_t *trans)
{
    return 0;
}

DVP_BOOL dvp_rpc_invalidate(DVP_RPC_t *rpc,
                            DVP_Core_e core,
                            DVP_PTR address,
                            DVP_U32 size,
                            DVP_MemType_e mtype)
{
    return DVP_FALSE;
}

DVP_BOOL dvp_rpc_flush(DVP_RPC_t *rpc,
                       DVP_Core_e core,
                       DVP_PTR address,
                       DVP_U32 size,
                       DVP_MemType_e mtype)
{
    return DVP_FALSE;
}

void dvp_rpc_prepare_image(DVP_RPC_t *rpc,
                           DVP_Core_e core,
                           DVP_Image_t *pImage,
                           DVP_BOOL cacheOp,
                           DVP_PTR base,
                           DVP_RPC_Translation_t *trans)
{
    ; // do nothing
}

void dvp_rpc_return_image(DVP_RPC_t *rpc,
                          DVP_Core_e core,
                          DVP_Image_t *pImage,
                          DVP_BOOL cacheOp)
{
    ; // do nothing
}

void dvp_rpc_prepare_buffer(DVP_RPC_t *rpc,
                            DVP_Core_e core,
                            DVP_Buffer_t *pBuffer,
                            DVP_BOOL cacheOp,
                            DVP_PTR base,
                            DVP_RPC_Translation_t *trans)
{
    ; // do nothing
}

void dvp_rpc_return_buffer(DVP_RPC_t *rpc,
                           DVP_Core_e core,
                           DVP_Buffer_t *pBuffer,
                           DVP_BOOL cacheOp)
{
    ; // do nothing
}

#endif

//******************************************************************************
// END
//******************************************************************************

