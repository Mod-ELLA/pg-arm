/*
 * DlogPiDTheta.h
 *
 * Code generation for function 'DlogPiDTheta'
 *
 * C source code generated on: Mon Jul 28 22:57:44 2014
 *
 */

#ifndef __DLOGPIDTHETA_H__
#define __DLOGPIDTHETA_H__
/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"

#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "episodicREINFORCE_types.h"

/* Function Declarations */
extern void DlogPiDTheta(const emlrtStack *sp, const real_T policy_theta_k[4], real_T policy_theta_sigma, real_T param_N, emxArray_real_T *der);
extern void b_DlogPiDTheta(const emlrtStack *sp, const real_T policy_theta_k[4], real_T policy_theta_sigma, real_T x, real_T u, real_T param_N, emxArray_real_T *der);
#endif
/* End of code generation (DlogPiDTheta.h) */
