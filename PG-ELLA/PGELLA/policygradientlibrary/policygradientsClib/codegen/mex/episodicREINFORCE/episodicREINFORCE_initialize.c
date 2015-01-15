/*
 * episodicREINFORCE_initialize.c
 *
 * Code generation for function 'episodicREINFORCE_initialize'
 *
 * C source code generated on: Tue Jul 29 16:12:56 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "episodicREINFORCE.h"
#include "episodicREINFORCE_initialize.h"
#include "episodicREINFORCE_data.h"

/* Function Definitions */
void episodicREINFORCE_initialize(emlrtStack *sp, emlrtContext *aContext)
{
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, aContext, NULL, 1);
  sp->tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(sp, FALSE, 0U, 0);
  emlrtEnterRtStackR2012b(sp);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (episodicREINFORCE_initialize.c) */
