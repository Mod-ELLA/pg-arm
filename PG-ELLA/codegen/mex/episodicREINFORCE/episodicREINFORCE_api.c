/*
 * episodicREINFORCE_api.c
 *
 * Code generation for function 'episodicREINFORCE_api'
 *
 * C source code generated on: Mon Jul 28 22:57:44 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "episodicREINFORCE.h"
#include "episodicREINFORCE_api.h"
#include "episodicREINFORCE_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo f_emlrtRTEI = { 1, 1, "episodicREINFORCE_api", "" };

/* Function Declarations */
static b_struct_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static struct_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4]);
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static b_struct_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *policy,
  const char_T *identifier);
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, emxArray_creal_T
  *u);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *data, const
  char_T *identifier, d_struct_T *y);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, d_struct_T *y);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[20]);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[10]);
static c_struct_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *param,
  const char_T *identifier);
static c_struct_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4]);
static real_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[20]);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[10]);

/* Function Definitions */
static b_struct_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  b_struct_T y;
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[2] = { "theta", "type" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(sp, parentId, u, 2, fieldNames, 0U, 0);
  thisId.fIdentifier = "theta";
  y.theta = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "theta")), &thisId);
  thisId.fIdentifier = "type";
  y.type = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "type")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static struct_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  struct_T y;
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[2] = { "k", "sigma" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(sp, parentId, u, 2, fieldNames, 0U, 0);
  thisId.fIdentifier = "k";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "k")), &thisId,
                     y.k);
  thisId.fIdentifier = "sigma";
  y.sigma = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "sigma")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4])
{
  l_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = m_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static b_struct_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *policy,
  const char_T *identifier)
{
  b_struct_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = b_emlrt_marshallIn(sp, emlrtAlias(policy), &thisId);
  emlrtDestroyArray(&policy);
  return y;
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp, emxArray_creal_T
  *u)
{
  const mxArray *y;
  const mxArray *m2;
  y = NULL;
  m2 = mxCreateNumericArray(1, u->size, mxDOUBLE_CLASS, mxCOMPLEX);
  emlrtExportNumericArrayR2013b(sp, m2, (void *)u->data, 8);
  emlrtAssign(&y, m2);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *data, const
  char_T *identifier, d_struct_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  g_emlrt_marshallIn(sp, emlrtAlias(data), &thisId, y);
  emlrtDestroyArray(&data);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, d_struct_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[3] = { "x", "u", "r" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(sp, parentId, u, 3, fieldNames, 0U, 0);
  thisId.fIdentifier = "x";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "x")), &thisId,
                     y->x);
  thisId.fIdentifier = "u";
  i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "u")), &thisId,
                     y->u);
  thisId.fIdentifier = "r";
  i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "r")), &thisId,
                     y->r);
  emlrtDestroyArray(&u);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[20])
{
  n_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[10])
{
  o_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static c_struct_T j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *param,
  const char_T *identifier)
{
  c_struct_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = k_emlrt_marshallIn(sp, emlrtAlias(param), &thisId);
  emlrtDestroyArray(&param);
  return y;
}

static c_struct_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  c_struct_T y;
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[3] = { "N", "M", "gamma" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(sp, parentId, u, 3, fieldNames, 0U, 0);
  thisId.fIdentifier = "N";
  y.N = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "N")),
    &thisId);
  thisId.fIdentifier = "M";
  y.M = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0, "M")),
    &thisId);
  thisId.fIdentifier = "gamma";
  y.gamma = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2013a(sp, u, 0,
    "gamma")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4])
{
  int32_T iv16[1];
  int32_T i3;
  iv16[0] = 4;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", FALSE, 1U, iv16);
  for (i3 = 0; i3 < 4; i3++) {
    ret[i3] = (*(real_T (*)[4])mxGetData(src))[i3];
  }

  emlrtDestroyArray(&src);
}

static real_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", FALSE, 0U, 0);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[20])
{
  int32_T iv17[2];
  int32_T i4;
  int32_T i5;
  for (i4 = 0; i4 < 2; i4++) {
    iv17[i4] = 2 + (i4 << 3);
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", FALSE, 2U, iv17);
  for (i4 = 0; i4 < 10; i4++) {
    for (i5 = 0; i5 < 2; i5++) {
      ret[i5 + (i4 << 1)] = (*(real_T (*)[20])mxGetData(src))[i5 + (i4 << 1)];
    }
  }

  emlrtDestroyArray(&src);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[10])
{
  int32_T iv18[2];
  int32_T i6;
  for (i6 = 0; i6 < 2; i6++) {
    iv18[i6] = 1 + 9 * i6;
  }

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", FALSE, 2U, iv18);
  for (i6 = 0; i6 < 10; i6++) {
    ret[i6] = (*(real_T (*)[10])mxGetData(src))[i6];
  }

  emlrtDestroyArray(&src);
}

void episodicREINFORCE_api(emlrtStack *sp, const mxArray * const prhs[3], const
  mxArray *plhs[1])
{
  emxArray_creal_T *dJdtheta;
  b_struct_T policy;
  d_struct_T data;
  c_struct_T param;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_creal_T(sp, &dJdtheta, 1, &f_emlrtRTEI, TRUE);

  /* Marshall function inputs */
  policy = emlrt_marshallIn(sp, emlrtAliasP(prhs[0]), "policy");
  f_emlrt_marshallIn(sp, emlrtAliasP(prhs[1]), "data", &data);
  param = j_emlrt_marshallIn(sp, emlrtAliasP(prhs[2]), "param");

  /* Invoke the target function */
  episodicREINFORCE(sp, &policy, &data, &param, dJdtheta);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(sp, dJdtheta);
  emxFree_creal_T(&dJdtheta);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (episodicREINFORCE_api.c) */
