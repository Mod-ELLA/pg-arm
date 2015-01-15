/*
 * episodicREINFORCE.c
 *
 * Code generation for function 'episodicREINFORCE'
 *
 * C source code generated on: Tue Jul 29 16:12:56 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "episodicREINFORCE.h"
#include "episodicREINFORCE_emxutil.h"
#include "DlogPiDTheta.h"
#include "episodicREINFORCE_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 6, "episodicREINFORCE",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/episodicREINFORCE.m"
};

static emlrtRSInfo b_emlrtRSI = { 9, "episodicREINFORCE",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/episodicREINFORCE.m"
};

static emlrtRSInfo c_emlrtRSI = { 13, "episodicREINFORCE",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/episodicREINFORCE.m"
};

static emlrtRSInfo d_emlrtRSI = { 14, "episodicREINFORCE",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/episodicREINFORCE.m"
};

static emlrtRSInfo e_emlrtRSI = { 17, "episodicREINFORCE",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/episodicREINFORCE.m"
};

static emlrtRSInfo f_emlrtRSI = { 22, "episodicREINFORCE",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/episodicREINFORCE.m"
};

static emlrtRSInfo g_emlrtRSI = { 24, "episodicREINFORCE",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/episodicREINFORCE.m"
};

static emlrtRTEInfo emlrtRTEI = { 1, 22, "episodicREINFORCE",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/episodicREINFORCE.m"
};

static emlrtRTEInfo b_emlrtRTEI = { 9, 3, "episodicREINFORCE",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/episodicREINFORCE.m"
};

static emlrtECInfo emlrtECI = { -1, 13, 19, "episodicREINFORCE",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/episodicREINFORCE.m"
};

static emlrtECInfo b_emlrtECI = { -1, 17, 18, "episodicREINFORCE",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/episodicREINFORCE.m"
};

/* Function Definitions */
void episodicREINFORCE(const emlrtStack *sp, const b_struct_T *policy, const
  d_struct_T *data, const c_struct_T *param, emxArray_creal_T *dJdtheta)
{
  emxArray_real_T *dSumPi;
  emxArray_real_T *r0;
  uint32_T unnamed_idx_0;
  uint32_T b_unnamed_idx_0;
  int32_T i0;
  int32_T loop_ub;
  real_T sumR;
  int32_T Steps;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &dSumPi, 1, &b_emlrtRTEI, TRUE);
  emxInit_real_T(sp, &r0, 1, &emlrtRTEI, TRUE);
  st.site = &emlrtRSI;
  DlogPiDTheta(&st, policy->theta.k, policy->theta.sigma, param->N, r0);
  unnamed_idx_0 = (uint32_T)r0->size[0];
  st.site = &b_emlrtRSI;
  DlogPiDTheta(&st, policy->theta.k, policy->theta.sigma, param->N, r0);
  b_unnamed_idx_0 = (uint32_T)r0->size[0];
  i0 = dSumPi->size[0];
  dSumPi->size[0] = (int32_T)b_unnamed_idx_0;
  emxEnsureCapacity(sp, (emxArray__common *)dSumPi, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = (int32_T)b_unnamed_idx_0;
  for (i0 = 0; i0 < loop_ub; i0++) {
    dSumPi->data[i0] = 0.0;
  }

  sumR = 0.0;
  for (Steps = 0; Steps < 10; Steps++) {
    st.site = &c_emlrtRSI;
    b_DlogPiDTheta(&st, policy->theta.k, policy->theta.sigma, data->x[Steps],
                   data->u[Steps], param->N, r0);
    i0 = dSumPi->size[0];
    loop_ub = r0->size[0];
    emlrtSizeEqCheck1DFastR2012b(i0, loop_ub, &emlrtECI, sp);
    i0 = dSumPi->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)dSumPi, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    loop_ub = dSumPi->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      dSumPi->data[i0] += r0->data[i0];
    }

    st.site = &d_emlrtRSI;
    b_st.site = &eb_emlrtRSI;
    c_st.site = &fb_emlrtRSI;
    st.site = &d_emlrtRSI;
    sumR += muDoubleScalarPower(param->gamma, (1.0 + (real_T)Steps) - 1.0) *
      data->r[Steps];
    emlrtBreakCheckFastR2012b(emlrtBreakCheckR2012bFlagVar, sp);
  }

  emxFree_real_T(&r0);
  st.site = &e_emlrtRSI;
  i0 = dSumPi->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)dSumPi, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  loop_ub = dSumPi->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    dSumPi->data[i0] *= sumR;
  }

  i0 = (int32_T)unnamed_idx_0;
  loop_ub = dSumPi->size[0];
  emlrtSizeEqCheck1DFastR2012b(i0, loop_ub, &b_emlrtECI, sp);
  i0 = dSumPi->size[0];
  dSumPi->size[0] = (int32_T)unnamed_idx_0;
  emxEnsureCapacity(sp, (emxArray__common *)dSumPi, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  if (param->gamma == 1.0) {
    st.site = &f_emlrtRSI;
    b_st.site = &jb_emlrtRSI;
    c_st.site = &kb_emlrtRSI;
    i0 = dJdtheta->size[0];
    dJdtheta->size[0] = dSumPi->size[0];
    emxEnsureCapacity(&c_st, (emxArray__common *)dJdtheta, i0, (int32_T)sizeof
                      (creal_T), &emlrtRTEI);
    loop_ub = dSumPi->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      sumR = dSumPi->data[i0];
      if (sumR == 0.0) {
        dJdtheta->data[i0].re = 0.0;
        dJdtheta->data[i0].im = 0.0;
      } else {
        dJdtheta->data[i0].re = 0.0;
        dJdtheta->data[i0].im = -sumR;
      }
    }
  } else {
    st.site = &g_emlrtRSI;
    st.site = &g_emlrtRSI;
    b_st.site = &jb_emlrtRSI;
    c_st.site = &kb_emlrtRSI;
    i0 = dJdtheta->size[0];
    dJdtheta->size[0] = dSumPi->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)dJdtheta, i0, (int32_T)sizeof
                      (creal_T), &emlrtRTEI);
    loop_ub = dSumPi->size[0];
    for (i0 = 0; i0 < loop_ub; i0++) {
      dJdtheta->data[i0].re = (1.0 - param->gamma) * dSumPi->data[i0];
      dJdtheta->data[i0].im = 0.0;
    }
  }

  emxFree_real_T(&dSumPi);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (episodicREINFORCE.c) */
