/*
 * episodicREINFORCE_terminate.c
 *
 * Code generation for function 'episodicREINFORCE_terminate'
 *
 * C source code generated on: Mon Jul 28 22:57:44 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "episodicREINFORCE.h"
#include "episodicREINFORCE_terminate.h"

/* Function Definitions */
void episodicREINFORCE_atexit(emlrtStack *sp)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  sp->tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(sp);
  emlrtLeaveRtStackR2012b(sp);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void episodicREINFORCE_terminate(emlrtStack *sp)
{
  emlrtLeaveRtStackR2012b(sp);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (episodicREINFORCE_terminate.c) */
