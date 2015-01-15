/*
 * episodicREINFORCE_types.h
 *
 * Code generation for function 'episodicREINFORCE'
 *
 * C source code generated on: Tue Jul 29 16:12:56 2014
 *
 */

#ifndef __EPISODICREINFORCE_TYPES_H__
#define __EPISODICREINFORCE_TYPES_H__

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_struct_T
#define typedef_struct_T
typedef struct
{
    real_T k[2];
    real_T sigma;
} struct_T;
#endif /*typedef_struct_T*/
#ifndef typedef_b_struct_T
#define typedef_b_struct_T
typedef struct
{
    struct_T theta;
    real_T type;
} b_struct_T;
#endif /*typedef_b_struct_T*/
#ifndef typedef_c_struct_T
#define typedef_c_struct_T
typedef struct
{
    real_T N;
    real_T M;
    real_T gamma;
} c_struct_T;
#endif /*typedef_c_struct_T*/
#ifndef typedef_d_struct_T
#define typedef_d_struct_T
typedef struct
{
    real_T u[10];
    real_T r[10];
    real_T x[20];
} d_struct_T;
#endif /*typedef_d_struct_T*/
#ifndef struct_emxArray__common
#define struct_emxArray__common
struct emxArray__common
{
    void *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};
#endif /*struct_emxArray__common*/
#ifndef typedef_emxArray__common
#define typedef_emxArray__common
typedef struct emxArray__common emxArray__common;
#endif /*typedef_emxArray__common*/
#ifndef struct_emxArray_creal_T
#define struct_emxArray_creal_T
struct emxArray_creal_T
{
    creal_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};
#endif /*struct_emxArray_creal_T*/
#ifndef typedef_emxArray_creal_T
#define typedef_emxArray_creal_T
typedef struct emxArray_creal_T emxArray_creal_T;
#endif /*typedef_emxArray_creal_T*/
#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T
struct emxArray_int32_T
{
    int32_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};
#endif /*struct_emxArray_int32_T*/
#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T
typedef struct emxArray_int32_T emxArray_int32_T;
#endif /*typedef_emxArray_int32_T*/
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T
{
    real_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};
#endif /*struct_emxArray_real_T*/
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /*typedef_emxArray_real_T*/
#ifndef struct_emxArray_real_T_1x1
#define struct_emxArray_real_T_1x1
struct emxArray_real_T_1x1
{
    real_T data[1];
    int32_T size[2];
};
#endif /*struct_emxArray_real_T_1x1*/
#ifndef typedef_emxArray_real_T_1x1
#define typedef_emxArray_real_T_1x1
typedef struct emxArray_real_T_1x1 emxArray_real_T_1x1;
#endif /*typedef_emxArray_real_T_1x1*/

#endif
/* End of code generation (episodicREINFORCE_types.h) */
