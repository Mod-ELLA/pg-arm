/*
 * DlogPiDTheta.c
 *
 * Code generation for function 'DlogPiDTheta'
 *
 * C source code generated on: Mon Jul 28 22:57:44 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "episodicREINFORCE.h"
#include "DlogPiDTheta.h"
#include "episodicREINFORCE_emxutil.h"
#include "episodicREINFORCE_data.h"

/* Variable Definitions */
static emlrtRSInfo h_emlrtRSI = { 26, "DlogPiDTheta",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/DlogPiDTheta.m"
};

static emlrtRSInfo i_emlrtRSI = { 34, "DlogPiDTheta",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/DlogPiDTheta.m"
};

static emlrtRSInfo j_emlrtRSI = { 35, "DlogPiDTheta",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/DlogPiDTheta.m"
};

static emlrtRSInfo k_emlrtRSI = { 16, "max",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/datafun/max.m" };

static emlrtRSInfo l_emlrtRSI = { 18, "eml_min_or_max",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

static emlrtRSInfo o_emlrtRSI = { 58, "mtimes",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/ops/mtimes.m" };

static emlrtRSInfo p_emlrtRSI = { 21, "mtimes",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/ops/mtimes.m" };

static emlrtRSInfo q_emlrtRSI = { 31, "eml_xdotu",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"
};

static emlrtMCInfo emlrtMCI = { 94, 13, "mtimes",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/ops/mtimes.m" };

static emlrtMCInfo b_emlrtMCI = { 93, 23, "mtimes",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/ops/mtimes.m" };

static emlrtMCInfo c_emlrtMCI = { 99, 13, "mtimes",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/ops/mtimes.m" };

static emlrtMCInfo d_emlrtMCI = { 98, 23, "mtimes",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/ops/mtimes.m" };

static emlrtRTEInfo c_emlrtRTEI = { 1, 16, "DlogPiDTheta",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/DlogPiDTheta.m"
};

static emlrtRTEInfo d_emlrtRTEI = { 6, 5, "DlogPiDTheta",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/DlogPiDTheta.m"
};

static emlrtRTEInfo e_emlrtRTEI = { 7, 5, "DlogPiDTheta",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/DlogPiDTheta.m"
};

static emlrtBCInfo emlrtBCI = { 1, 4, 32, 20, "policy.theta.k", "DlogPiDTheta",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/DlogPiDTheta.m",
  0 };

static emlrtBCInfo b_emlrtBCI = { 1, 1, 33, 20, "x", "DlogPiDTheta",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/DlogPiDTheta.m",
  0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 32, 9, "k", "DlogPiDTheta",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/DlogPiDTheta.m",
  0 };

static emlrtECInfo c_emlrtECI = { -1, 32, 7, "DlogPiDTheta",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/DlogPiDTheta.m"
};

static emlrtECInfo d_emlrtECI = { -1, 33, 7, "DlogPiDTheta",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/DlogPiDTheta.m"
};

static emlrtBCInfo d_emlrtBCI = { -1, -1, 34, 11, "der", "DlogPiDTheta",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/DlogPiDTheta.m",
  0 };

static emlrtECInfo e_emlrtECI = { -1, 34, 7, "DlogPiDTheta",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/DlogPiDTheta.m"
};

static emlrtDCInfo emlrtDCI = { 6, 13, "DlogPiDTheta",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/DlogPiDTheta.m",
  1 };

static emlrtDCInfo b_emlrtDCI = { 6, 13, "DlogPiDTheta",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/DlogPiDTheta.m",
  4 };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 9, 9, "der", "DlogPiDTheta",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/DlogPiDTheta.m",
  0 };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 35, 11, "der", "DlogPiDTheta",
  "/Users/haithambouammar/Documents/Code/LisaEric/PGELLA/policygradientlibrary/Library/DlogPiDTheta.m",
  0 };

static emlrtRSInfo xb_emlrtRSI = { 93, "mtimes",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/ops/mtimes.m" };

static emlrtRSInfo yb_emlrtRSI = { 98, "mtimes",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/ops/mtimes.m" };

static emlrtRSInfo ac_emlrtRSI = { 94, "mtimes",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/ops/mtimes.m" };

static emlrtRSInfo bc_emlrtRSI = { 99, "mtimes",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/ops/mtimes.m" };

/* Function Declarations */
static void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location);
static const mxArray *message(const emlrtStack *sp, const mxArray *b,
  emlrtMCInfo *location);

/* Function Definitions */
static void error(const emlrtStack *sp, const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(sp, 0, NULL, 1, &pArray, "error", TRUE, location);
}

static const mxArray *message(const emlrtStack *sp, const mxArray *b,
  emlrtMCInfo *location)
{
  const mxArray *pArray;
  const mxArray *m3;
  pArray = b;
  return emlrtCallMATLABR2012b(sp, 1, &m3, 1, &pArray, "message", TRUE, location);
}

void DlogPiDTheta(const emlrtStack *sp, const real_T policy_theta_k[4], real_T
                  policy_theta_sigma, real_T param_N, emxArray_real_T *der)
{
  emxArray_real_T *k;
  int32_T i1;
  real_T sigma;
  int32_T loop_ub;
  emxArray_real_T *xx;
  int32_T i;
  emxArray_int32_T *r1;
  int32_T iv0[1];
  int32_T iv1[1];
  int32_T tmp_size[2];
  int32_T iv2[1];
  emxArray_real_T *a;
  const mxArray *y;
  static const int32_T iv3[2] = { 1, 45 };

  const mxArray *m0;
  char_T cv0[45];
  static const char_T cv1[45] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'm', 't', 'i', 'm', 'e', 's', '_', 'n', 'o', 'D',
    'y', 'n', 'a', 'm', 'i', 'c', 'S', 'c', 'a', 'l', 'a', 'r', 'E', 'x', 'p',
    'a', 'n', 's', 'i', 'o', 'n' };

  const mxArray *b_y;
  static const int32_T iv4[2] = { 1, 21 };

  char_T cv2[21];
  static const char_T cv3[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'i', 'n', 'n', 'e', 'r', 'd', 'i', 'm' };

  real_T c_y;
  ptrdiff_t n_t;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  double * xix0_t;
  double * yiy0_t;
  emxArray_real_T *r2;
  real_T B;
  int32_T iv5[1];
  const mxArray *d_y;
  static const int32_T iv6[2] = { 1, 45 };

  const mxArray *e_y;
  static const int32_T iv7[2] = { 1, 21 };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &b_st;
  d_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &k, 1, &d_emlrtRTEI, TRUE);

  /* global N M */
  i1 = k->size[0];
  sigma = emlrtNonNegativeCheckFastR2012b(param_N, &b_emlrtDCI, sp);
  k->size[0] = (int32_T)emlrtIntegerCheckFastR2012b(sigma, &emlrtDCI, sp);
  emxEnsureCapacity(sp, (emxArray__common *)k, i1, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);
  sigma = emlrtNonNegativeCheckFastR2012b(param_N, &b_emlrtDCI, sp);
  loop_ub = (int32_T)emlrtIntegerCheckFastR2012b(sigma, &emlrtDCI, sp);
  for (i1 = 0; i1 < loop_ub; i1++) {
    k->data[i1] = 0.0;
  }

  emxInit_real_T(sp, &xx, 1, &e_emlrtRTEI, TRUE);
  i1 = xx->size[0];
  xx->size[0] = (int32_T)param_N;
  emxEnsureCapacity(sp, (emxArray__common *)xx, i1, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);
  loop_ub = (int32_T)param_N;
  for (i1 = 0; i1 < loop_ub; i1++) {
    xx->data[i1] = 0.0;
  }

  i1 = der->size[0];
  der->size[0] = (int32_T)param_N;
  emxEnsureCapacity(sp, (emxArray__common *)der, i1, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);
  loop_ub = (int32_T)param_N;
  for (i1 = 0; i1 < loop_ub; i1++) {
    der->data[i1] = 0.0;
  }

  i1 = (int32_T)param_N;
  i = (int32_T)(param_N + 1.0);
  der->data[emlrtDynamicBoundsCheckFastR2012b(i, 1, i1, &e_emlrtBCI, sp) - 1] =
    0.0;

  /* if(policy.type == 1) */
  /*  der = zeros(N*(M-1),1);     */
  /* if(u==M) */
  /*     actions = selDecBor(x,1):selDecBor(x,M-1); */
  /*     der(actions,1) = - 1 / (1 - sum(policy.theta(actions))); */
  /*  else */
  /*     der(selDecBor(x,u),1) = 1 / policy.theta(selDecBor(x,u)); */
  /*  end;    */
  /* elseif(policy.type == 2)  */
  /*    der = zeros(N*M,1); */
  /*    for i=1:M */
  /*       der(selGibbs(x,i),1) = -pi_theta(policy, x, i)/policy.eps; */
  /*    end;    */
  /*   der(selGibbs(x,u)) = (1 - pi_theta(policy, x, u))/policy.eps; */
  /* if(policy.type == 3)  */
  st.site = &h_emlrtRSI;
  b_st.site = &k_emlrtRSI;
  c_st.site = &l_emlrtRSI;
  sigma = muDoubleScalarMax(policy_theta_sigma, 1.0E-5);

  /* tempTheta=policy.theta.k;  */
  /* for l=1:length(tempTheta) */
  /*     k(l,:)=tempTheta(l,:); */
  /*    xx(l,:)=x(l,:); */
  /* end */
  if (1.0 > param_N) {
    loop_ub = 0;
  } else {
    i1 = (int32_T)param_N;
    loop_ub = emlrtDynamicBoundsCheckFastR2012b(i1, 1, 4, &emlrtBCI, sp);
  }

  if (1.0 > param_N) {
    i = 0;
  } else {
    i1 = (int32_T)param_N;
    i = (int32_T)param_N;
    i = emlrtDynamicBoundsCheckFastR2012b(i, 1, i1, &c_emlrtBCI, sp);
  }

  emxInit_int32_T(sp, &r1, 1, &c_emlrtRTEI, TRUE);
  i1 = r1->size[0];
  r1->size[0] = i;
  emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(int32_T),
                    &c_emlrtRTEI);
  for (i1 = 0; i1 < i; i1++) {
    r1->data[i1] = i1;
  }

  iv0[0] = r1->size[0];
  iv1[0] = loop_ub;
  emlrtSubAssignSizeCheckR2012b(iv0, 1, iv1, 1, &c_emlrtECI, sp);
  for (i1 = 0; i1 < loop_ub; i1++) {
    k->data[r1->data[i1]] = policy_theta_k[i1];
  }

  if (1.0 > param_N) {
    i1 = -1;
  } else {
    i1 = (int32_T)param_N;
    emlrtDynamicBoundsCheckFastR2012b(i1, 1, 1, &b_emlrtBCI, sp);
    i1 = 0;
  }

  tmp_size[0] = 1;
  tmp_size[1] = i1 + 1;
  if (1.0 > param_N) {
    loop_ub = -1;
  } else {
    loop_ub = 0;
  }

  i1 = r1->size[0];
  r1->size[0] = loop_ub + 1;
  emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(int32_T),
                    &c_emlrtRTEI);
  i1 = 0;
  while (i1 <= loop_ub) {
    r1->data[0] = 0;
    i1 = 1;
  }

  iv2[0] = r1->size[0];
  emlrtSubAssignSizeCheckR2012b(iv2, 1, tmp_size, 2, &d_emlrtECI, sp);
  i = r1->size[0];
  for (i1 = 0; i1 < i; i1++) {
    xx->data[r1->data[i1]] = 1.0;
  }

  if (1.0 > param_N) {
    loop_ub = -1;
  } else {
    i1 = der->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i1, &d_emlrtBCI, sp);
    i1 = der->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i1, &d_emlrtBCI, sp);
    loop_ub = 0;
  }

  i1 = r1->size[0];
  r1->size[0] = loop_ub + 1;
  emxEnsureCapacity(sp, (emxArray__common *)r1, i1, (int32_T)sizeof(int32_T),
                    &c_emlrtRTEI);
  i1 = 0;
  while (i1 <= loop_ub) {
    r1->data[0] = 0;
    i1 = 1;
  }

  b_emxInit_real_T(sp, &a, 2, &c_emlrtRTEI, TRUE);
  st.site = &i_emlrtRSI;
  i1 = a->size[0] * a->size[1];
  a->size[0] = 1;
  a->size[1] = k->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)a, i1, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);
  loop_ub = k->size[0];
  for (i1 = 0; i1 < loop_ub; i1++) {
    a->data[a->size[0] * i1] = k->data[i1];
  }

  b_st.site = &p_emlrtRSI;
  if (!(a->size[1] == xx->size[0])) {
    if ((a->size[1] == 1) || (xx->size[0] == 1)) {
      y = NULL;
      m0 = mxCreateCharArray(2, iv3);
      for (i = 0; i < 45; i++) {
        cv0[i] = cv1[i];
      }

      emlrtInitCharArrayR2013a(&b_st, 45, m0, cv0);
      emlrtAssign(&y, m0);
      c_st.site = &xb_emlrtRSI;
      d_st.site = &ac_emlrtRSI;
      error(&c_st, message(&d_st, y, &emlrtMCI), &b_emlrtMCI);
    } else {
      b_y = NULL;
      m0 = mxCreateCharArray(2, iv4);
      for (i = 0; i < 21; i++) {
        cv2[i] = cv3[i];
      }

      emlrtInitCharArrayR2013a(&b_st, 21, m0, cv2);
      emlrtAssign(&b_y, m0);
      c_st.site = &yb_emlrtRSI;
      d_st.site = &bc_emlrtRSI;
      error(&c_st, message(&d_st, b_y, &c_emlrtMCI), &d_emlrtMCI);
    }
  }

  if ((a->size[1] == 1) || (xx->size[0] == 1)) {
    c_y = 0.0;
    for (i1 = 0; i1 < a->size[1]; i1++) {
      c_y += a->data[a->size[0] * i1] * xx->data[i1];
    }
  } else {
    b_st.site = &o_emlrtRSI;
    c_st.site = &q_emlrtRSI;
    if (a->size[1] < 1) {
      c_y = 0.0;
    } else {
      n_t = (ptrdiff_t)(a->size[1]);
      incx_t = (ptrdiff_t)(1);
      incy_t = (ptrdiff_t)(1);
      xix0_t = (double *)(&a->data[0]);
      yiy0_t = (double *)(&xx->data[0]);
      c_y = ddot(&n_t, xix0_t, &incx_t, yiy0_t, &incy_t);
    }
  }

  emxInit_real_T(&st, &r2, 1, &c_emlrtRTEI, TRUE);
  st.site = &i_emlrtRSI;
  st.site = &i_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  c_st.site = &fb_emlrtRSI;
  B = sigma * sigma;
  st.site = &i_emlrtRSI;
  b_st.site = &jb_emlrtRSI;
  c_st.site = &kb_emlrtRSI;
  i1 = r2->size[0];
  r2->size[0] = xx->size[0];
  emxEnsureCapacity(&c_st, (emxArray__common *)r2, i1, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);
  loop_ub = xx->size[0];
  for (i1 = 0; i1 < loop_ub; i1++) {
    r2->data[i1] = (1.0 - c_y) * xx->data[i1] / B;
  }

  iv5[0] = r1->size[0];
  emlrtSubAssignSizeCheckR2012b(iv5, 1, *(int32_T (*)[1])r2->size, 1,
    &e_emlrtECI, sp);
  loop_ub = r2->size[0];
  for (i1 = 0; i1 < loop_ub; i1++) {
    der->data[r1->data[i1]] = r2->data[i1];
  }

  emxFree_real_T(&r2);
  emxFree_int32_T(&r1);
  st.site = &j_emlrtRSI;
  i1 = a->size[0] * a->size[1];
  a->size[0] = 1;
  a->size[1] = k->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)a, i1, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);
  loop_ub = k->size[0];
  for (i1 = 0; i1 < loop_ub; i1++) {
    a->data[a->size[0] * i1] = k->data[i1];
  }

  emxFree_real_T(&k);
  b_st.site = &p_emlrtRSI;
  if (!(a->size[1] == xx->size[0])) {
    if ((a->size[1] == 1) || (xx->size[0] == 1)) {
      d_y = NULL;
      m0 = mxCreateCharArray(2, iv6);
      for (i = 0; i < 45; i++) {
        cv0[i] = cv1[i];
      }

      emlrtInitCharArrayR2013a(&b_st, 45, m0, cv0);
      emlrtAssign(&d_y, m0);
      c_st.site = &xb_emlrtRSI;
      d_st.site = &ac_emlrtRSI;
      error(&c_st, message(&d_st, d_y, &emlrtMCI), &b_emlrtMCI);
    } else {
      e_y = NULL;
      m0 = mxCreateCharArray(2, iv7);
      for (i = 0; i < 21; i++) {
        cv2[i] = cv3[i];
      }

      emlrtInitCharArrayR2013a(&b_st, 21, m0, cv2);
      emlrtAssign(&e_y, m0);
      c_st.site = &yb_emlrtRSI;
      d_st.site = &bc_emlrtRSI;
      error(&c_st, message(&d_st, e_y, &c_emlrtMCI), &d_emlrtMCI);
    }
  }

  if ((a->size[1] == 1) || (xx->size[0] == 1)) {
    c_y = 0.0;
    for (i1 = 0; i1 < a->size[1]; i1++) {
      c_y += a->data[a->size[0] * i1] * xx->data[i1];
    }
  } else {
    b_st.site = &o_emlrtRSI;
    c_st.site = &q_emlrtRSI;
    if (a->size[1] < 1) {
      c_y = 0.0;
    } else {
      n_t = (ptrdiff_t)(a->size[1]);
      incx_t = (ptrdiff_t)(1);
      incy_t = (ptrdiff_t)(1);
      xix0_t = (double *)(&a->data[0]);
      yiy0_t = (double *)(&xx->data[0]);
      c_y = ddot(&n_t, xix0_t, &incx_t, yiy0_t, &incy_t);
    }
  }

  emxFree_real_T(&a);
  emxFree_real_T(&xx);
  st.site = &j_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  c_st.site = &fb_emlrtRSI;
  st.site = &j_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  c_st.site = &fb_emlrtRSI;
  st.site = &j_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  c_st.site = &fb_emlrtRSI;
  st.site = &j_emlrtRSI;
  b_st.site = &jb_emlrtRSI;
  c_st.site = &kb_emlrtRSI;
  i1 = der->size[0];
  i = (int32_T)param_N + 1;
  der->data[emlrtDynamicBoundsCheckFastR2012b(i, 1, i1, &f_emlrtBCI, sp) - 1] =
    ((1.0 - c_y) * (1.0 - c_y) - sigma * sigma) / muDoubleScalarPower(sigma, 3.0);

  /* end;    */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void b_DlogPiDTheta(const emlrtStack *sp, const real_T policy_theta_k[4], real_T
                    policy_theta_sigma, real_T x, real_T u, real_T param_N,
                    emxArray_real_T *der)
{
  emxArray_real_T *k;
  int32_T i2;
  real_T y;
  int32_T loop_ub;
  emxArray_real_T *xx;
  int32_T i;
  real_T sigma;
  emxArray_int32_T *r3;
  int32_T iv8[1];
  int32_T iv9[1];
  int32_T tmp_size[2];
  int32_T iv10[1];
  real_T x_data[1];
  emxArray_real_T *a;
  const mxArray *b_y;
  static const int32_T iv11[2] = { 1, 45 };

  const mxArray *m1;
  char_T cv4[45];
  static const char_T cv5[45] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'm', 't', 'i', 'm', 'e', 's', '_', 'n', 'o', 'D',
    'y', 'n', 'a', 'm', 'i', 'c', 'S', 'c', 'a', 'l', 'a', 'r', 'E', 'x', 'p',
    'a', 'n', 's', 'i', 'o', 'n' };

  const mxArray *c_y;
  static const int32_T iv12[2] = { 1, 21 };

  char_T cv6[21];
  static const char_T cv7[21] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 'i', 'n', 'n', 'e', 'r', 'd', 'i', 'm' };

  ptrdiff_t n_t;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  double * xix0_t;
  double * yiy0_t;
  emxArray_real_T *r4;
  real_T B;
  int32_T iv13[1];
  const mxArray *d_y;
  static const int32_T iv14[2] = { 1, 45 };

  const mxArray *e_y;
  static const int32_T iv15[2] = { 1, 21 };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &b_st;
  d_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &k, 1, &d_emlrtRTEI, TRUE);

  /* global N M */
  i2 = k->size[0];
  y = emlrtNonNegativeCheckFastR2012b(param_N, &b_emlrtDCI, sp);
  k->size[0] = (int32_T)emlrtIntegerCheckFastR2012b(y, &emlrtDCI, sp);
  emxEnsureCapacity(sp, (emxArray__common *)k, i2, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);
  y = emlrtNonNegativeCheckFastR2012b(param_N, &b_emlrtDCI, sp);
  loop_ub = (int32_T)emlrtIntegerCheckFastR2012b(y, &emlrtDCI, sp);
  for (i2 = 0; i2 < loop_ub; i2++) {
    k->data[i2] = 0.0;
  }

  emxInit_real_T(sp, &xx, 1, &e_emlrtRTEI, TRUE);
  i2 = xx->size[0];
  xx->size[0] = (int32_T)param_N;
  emxEnsureCapacity(sp, (emxArray__common *)xx, i2, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);
  loop_ub = (int32_T)param_N;
  for (i2 = 0; i2 < loop_ub; i2++) {
    xx->data[i2] = 0.0;
  }

  i2 = der->size[0];
  der->size[0] = (int32_T)param_N;
  emxEnsureCapacity(sp, (emxArray__common *)der, i2, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);
  loop_ub = (int32_T)param_N;
  for (i2 = 0; i2 < loop_ub; i2++) {
    der->data[i2] = 0.0;
  }

  i2 = (int32_T)param_N;
  i = (int32_T)(param_N + 1.0);
  der->data[emlrtDynamicBoundsCheckFastR2012b(i, 1, i2, &e_emlrtBCI, sp) - 1] =
    0.0;

  /* if(policy.type == 1) */
  /*  der = zeros(N*(M-1),1);     */
  /* if(u==M) */
  /*     actions = selDecBor(x,1):selDecBor(x,M-1); */
  /*     der(actions,1) = - 1 / (1 - sum(policy.theta(actions))); */
  /*  else */
  /*     der(selDecBor(x,u),1) = 1 / policy.theta(selDecBor(x,u)); */
  /*  end;    */
  /* elseif(policy.type == 2)  */
  /*    der = zeros(N*M,1); */
  /*    for i=1:M */
  /*       der(selGibbs(x,i),1) = -pi_theta(policy, x, i)/policy.eps; */
  /*    end;    */
  /*   der(selGibbs(x,u)) = (1 - pi_theta(policy, x, u))/policy.eps; */
  /* if(policy.type == 3)  */
  st.site = &h_emlrtRSI;
  b_st.site = &k_emlrtRSI;
  c_st.site = &l_emlrtRSI;
  sigma = muDoubleScalarMax(policy_theta_sigma, 1.0E-5);

  /* tempTheta=policy.theta.k;  */
  /* for l=1:length(tempTheta) */
  /*     k(l,:)=tempTheta(l,:); */
  /*    xx(l,:)=x(l,:); */
  /* end */
  if (1.0 > param_N) {
    loop_ub = 0;
  } else {
    i2 = (int32_T)param_N;
    loop_ub = emlrtDynamicBoundsCheckFastR2012b(i2, 1, 4, &emlrtBCI, sp);
  }

  if (1.0 > param_N) {
    i = 0;
  } else {
    i2 = (int32_T)param_N;
    i = (int32_T)param_N;
    i = emlrtDynamicBoundsCheckFastR2012b(i, 1, i2, &c_emlrtBCI, sp);
  }

  emxInit_int32_T(sp, &r3, 1, &c_emlrtRTEI, TRUE);
  i2 = r3->size[0];
  r3->size[0] = i;
  emxEnsureCapacity(sp, (emxArray__common *)r3, i2, (int32_T)sizeof(int32_T),
                    &c_emlrtRTEI);
  for (i2 = 0; i2 < i; i2++) {
    r3->data[i2] = i2;
  }

  iv8[0] = r3->size[0];
  iv9[0] = loop_ub;
  emlrtSubAssignSizeCheckR2012b(iv8, 1, iv9, 1, &c_emlrtECI, sp);
  for (i2 = 0; i2 < loop_ub; i2++) {
    k->data[r3->data[i2]] = policy_theta_k[i2];
  }

  if (1.0 > param_N) {
    i2 = -1;
  } else {
    i2 = (int32_T)param_N;
    emlrtDynamicBoundsCheckFastR2012b(i2, 1, 1, &b_emlrtBCI, sp);
    i2 = 0;
  }

  tmp_size[0] = 1;
  tmp_size[1] = i2 + 1;
  if (1.0 > param_N) {
    loop_ub = -1;
  } else {
    loop_ub = 0;
  }

  i = r3->size[0];
  r3->size[0] = loop_ub + 1;
  emxEnsureCapacity(sp, (emxArray__common *)r3, i, (int32_T)sizeof(int32_T),
                    &c_emlrtRTEI);
  i = 0;
  while (i <= loop_ub) {
    r3->data[0] = 0;
    i = 1;
  }

  iv10[0] = r3->size[0];
  emlrtSubAssignSizeCheckR2012b(iv10, 1, tmp_size, 2, &d_emlrtECI, sp);
  loop_ub = i2 + 1;
  i2 = 0;
  while (i2 <= loop_ub - 1) {
    x_data[0] = x;
    i2 = 1;
  }

  i = r3->size[0];
  for (i2 = 0; i2 < i; i2++) {
    xx->data[r3->data[i2]] = x_data[i2];
  }

  if (1.0 > param_N) {
    loop_ub = -1;
  } else {
    i2 = der->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i2, &d_emlrtBCI, sp);
    i2 = der->size[0];
    emlrtDynamicBoundsCheckFastR2012b(1, 1, i2, &d_emlrtBCI, sp);
    loop_ub = 0;
  }

  i2 = r3->size[0];
  r3->size[0] = loop_ub + 1;
  emxEnsureCapacity(sp, (emxArray__common *)r3, i2, (int32_T)sizeof(int32_T),
                    &c_emlrtRTEI);
  i2 = 0;
  while (i2 <= loop_ub) {
    r3->data[0] = 0;
    i2 = 1;
  }

  b_emxInit_real_T(sp, &a, 2, &c_emlrtRTEI, TRUE);
  st.site = &i_emlrtRSI;
  i2 = a->size[0] * a->size[1];
  a->size[0] = 1;
  a->size[1] = k->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)a, i2, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);
  loop_ub = k->size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    a->data[a->size[0] * i2] = k->data[i2];
  }

  b_st.site = &p_emlrtRSI;
  if (!(a->size[1] == xx->size[0])) {
    if ((a->size[1] == 1) || (xx->size[0] == 1)) {
      b_y = NULL;
      m1 = mxCreateCharArray(2, iv11);
      for (i = 0; i < 45; i++) {
        cv4[i] = cv5[i];
      }

      emlrtInitCharArrayR2013a(&b_st, 45, m1, cv4);
      emlrtAssign(&b_y, m1);
      c_st.site = &xb_emlrtRSI;
      d_st.site = &ac_emlrtRSI;
      error(&c_st, message(&d_st, b_y, &emlrtMCI), &b_emlrtMCI);
    } else {
      c_y = NULL;
      m1 = mxCreateCharArray(2, iv12);
      for (i = 0; i < 21; i++) {
        cv6[i] = cv7[i];
      }

      emlrtInitCharArrayR2013a(&b_st, 21, m1, cv6);
      emlrtAssign(&c_y, m1);
      c_st.site = &yb_emlrtRSI;
      d_st.site = &bc_emlrtRSI;
      error(&c_st, message(&d_st, c_y, &c_emlrtMCI), &d_emlrtMCI);
    }
  }

  if ((a->size[1] == 1) || (xx->size[0] == 1)) {
    y = 0.0;
    for (i2 = 0; i2 < a->size[1]; i2++) {
      y += a->data[a->size[0] * i2] * xx->data[i2];
    }
  } else {
    b_st.site = &o_emlrtRSI;
    c_st.site = &q_emlrtRSI;
    if (a->size[1] < 1) {
      y = 0.0;
    } else {
      n_t = (ptrdiff_t)(a->size[1]);
      incx_t = (ptrdiff_t)(1);
      incy_t = (ptrdiff_t)(1);
      xix0_t = (double *)(&a->data[0]);
      yiy0_t = (double *)(&xx->data[0]);
      y = ddot(&n_t, xix0_t, &incx_t, yiy0_t, &incy_t);
    }
  }

  emxInit_real_T(&st, &r4, 1, &c_emlrtRTEI, TRUE);
  st.site = &i_emlrtRSI;
  y = u - y;
  st.site = &i_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  c_st.site = &fb_emlrtRSI;
  B = sigma * sigma;
  st.site = &i_emlrtRSI;
  b_st.site = &jb_emlrtRSI;
  c_st.site = &kb_emlrtRSI;
  i2 = r4->size[0];
  r4->size[0] = xx->size[0];
  emxEnsureCapacity(&c_st, (emxArray__common *)r4, i2, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);
  loop_ub = xx->size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    r4->data[i2] = y * xx->data[i2] / B;
  }

  iv13[0] = r3->size[0];
  emlrtSubAssignSizeCheckR2012b(iv13, 1, *(int32_T (*)[1])r4->size, 1,
    &e_emlrtECI, sp);
  loop_ub = r4->size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    der->data[r3->data[i2]] = r4->data[i2];
  }

  emxFree_real_T(&r4);
  emxFree_int32_T(&r3);
  st.site = &j_emlrtRSI;
  i2 = a->size[0] * a->size[1];
  a->size[0] = 1;
  a->size[1] = k->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)a, i2, (int32_T)sizeof(real_T),
                    &c_emlrtRTEI);
  loop_ub = k->size[0];
  for (i2 = 0; i2 < loop_ub; i2++) {
    a->data[a->size[0] * i2] = k->data[i2];
  }

  emxFree_real_T(&k);
  b_st.site = &p_emlrtRSI;
  if (!(a->size[1] == xx->size[0])) {
    if ((a->size[1] == 1) || (xx->size[0] == 1)) {
      d_y = NULL;
      m1 = mxCreateCharArray(2, iv14);
      for (i = 0; i < 45; i++) {
        cv4[i] = cv5[i];
      }

      emlrtInitCharArrayR2013a(&b_st, 45, m1, cv4);
      emlrtAssign(&d_y, m1);
      c_st.site = &xb_emlrtRSI;
      d_st.site = &ac_emlrtRSI;
      error(&c_st, message(&d_st, d_y, &emlrtMCI), &b_emlrtMCI);
    } else {
      e_y = NULL;
      m1 = mxCreateCharArray(2, iv15);
      for (i = 0; i < 21; i++) {
        cv6[i] = cv7[i];
      }

      emlrtInitCharArrayR2013a(&b_st, 21, m1, cv6);
      emlrtAssign(&e_y, m1);
      c_st.site = &yb_emlrtRSI;
      d_st.site = &bc_emlrtRSI;
      error(&c_st, message(&d_st, e_y, &c_emlrtMCI), &d_emlrtMCI);
    }
  }

  if ((a->size[1] == 1) || (xx->size[0] == 1)) {
    y = 0.0;
    for (i2 = 0; i2 < a->size[1]; i2++) {
      y += a->data[a->size[0] * i2] * xx->data[i2];
    }
  } else {
    b_st.site = &o_emlrtRSI;
    c_st.site = &q_emlrtRSI;
    if (a->size[1] < 1) {
      y = 0.0;
    } else {
      n_t = (ptrdiff_t)(a->size[1]);
      incx_t = (ptrdiff_t)(1);
      incy_t = (ptrdiff_t)(1);
      xix0_t = (double *)(&a->data[0]);
      yiy0_t = (double *)(&xx->data[0]);
      y = ddot(&n_t, xix0_t, &incx_t, yiy0_t, &incy_t);
    }
  }

  emxFree_real_T(&a);
  emxFree_real_T(&xx);
  st.site = &j_emlrtRSI;
  y = u - y;
  b_st.site = &eb_emlrtRSI;
  c_st.site = &fb_emlrtRSI;
  st.site = &j_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  c_st.site = &fb_emlrtRSI;
  st.site = &j_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  c_st.site = &fb_emlrtRSI;
  st.site = &j_emlrtRSI;
  b_st.site = &jb_emlrtRSI;
  c_st.site = &kb_emlrtRSI;
  i2 = der->size[0];
  i = (int32_T)param_N + 1;
  der->data[emlrtDynamicBoundsCheckFastR2012b(i, 1, i2, &f_emlrtBCI, sp) - 1] =
    (y * y - sigma * sigma) / muDoubleScalarPower(sigma, 3.0);

  /* end;    */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (DlogPiDTheta.c) */
