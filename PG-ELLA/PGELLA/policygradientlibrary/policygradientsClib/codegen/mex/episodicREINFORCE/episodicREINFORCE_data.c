/*
 * episodicREINFORCE_data.c
 *
 * Code generation for function 'episodicREINFORCE_data'
 *
 * C source code generated on: Tue Jul 29 16:12:56 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "episodicREINFORCE.h"
#include "episodicREINFORCE_data.h"

/* Variable Definitions */
const volatile char_T *emlrtBreakCheckR2012bFlagVar;
emlrtRSInfo m_emlrtRSI = { 59, "eml_min_or_max",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

emlrtRSInfo n_emlrtRSI = { 124, "eml_min_or_max",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

emlrtRSInfo r_emlrtRSI = { 28, "eml_xdot",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/blas/eml_xdot.m" };

emlrtRSInfo s_emlrtRSI = { 18, "eml_blas_xdot",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"
};

emlrtRSInfo t_emlrtRSI = { 21, "eml_blas_xdot",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"
};

emlrtRSInfo u_emlrtRSI = { 28, "eml_blas_xdot",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"
};

emlrtRSInfo v_emlrtRSI = { 14, "eml_refblas_xdot",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdot.m"
};

emlrtRSInfo w_emlrtRSI = { 30, "eml_refblas_xdotx",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"
};

emlrtRSInfo x_emlrtRSI = { 31, "eml_refblas_xdotx",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/blas/refblas/eml_refblas_xdotx.m"
};

emlrtRSInfo y_emlrtRSI = { 9, "eml_int_forloop_overflow_check",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

emlrtRSInfo ab_emlrtRSI = { 12, "eml_int_forloop_overflow_check",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

emlrtRSInfo bb_emlrtRSI = { 64, "eml_blas_xdot",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"
};

emlrtRSInfo cb_emlrtRSI = { 65, "eml_blas_xdot",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"
};

emlrtRSInfo db_emlrtRSI = { 66, "eml_blas_xdot",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xdot.m"
};

emlrtRSInfo eb_emlrtRSI = { 37, "mpower",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/ops/mpower.m" };

emlrtRSInfo fb_emlrtRSI = { 42, "power",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/ops/power.m" };

emlrtRSInfo gb_emlrtRSI = { 58, "power",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/ops/power.m" };

emlrtRSInfo hb_emlrtRSI = { 12, "floor",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/elfun/floor.m" };

emlrtRSInfo ib_emlrtRSI = { 74, "power",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/ops/power.m" };

emlrtRSInfo jb_emlrtRSI = { 1, "mrdivide",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/ops/mrdivide.p" };

emlrtRSInfo kb_emlrtRSI = { 15, "rdivide",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/ops/rdivide.m" };

emlrtRSInfo lb_emlrtRSI = { 12, "eml_div",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/eml_div.m" };

emlrtRSInfo mb_emlrtRSI = { 88, "eml_min_or_max",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

emlrtRSInfo nb_emlrtRSI = { 38, "eml_int_forloop_overflow_check",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

emlrtRSInfo ob_emlrtRSI = { 190, "eml_min_or_max",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

emlrtRSInfo pb_emlrtRSI = { 194, "eml_min_or_max",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

emlrtRSInfo qb_emlrtRSI = { 200, "eml_min_or_max",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

emlrtRSInfo rb_emlrtRSI = { 221, "eml_min_or_max",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

emlrtRSInfo sb_emlrtRSI = { 225, "eml_min_or_max",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"
};

emlrtRSInfo tb_emlrtRSI = { 55, "power",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/ops/power.m" };

emlrtRSInfo ub_emlrtRSI = { 56, "power",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/ops/power.m" };

emlrtRSInfo vb_emlrtRSI = { 30, "eml_div",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/eml_div.m" };

emlrtRSInfo wb_emlrtRSI = { 19, "abs",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/elfun/abs.m" };

emlrtMCInfo e_emlrtMCI = { 52, 9, "eml_int_forloop_overflow_check",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

emlrtMCInfo f_emlrtMCI = { 51, 15, "eml_int_forloop_overflow_check",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

emlrtRTEInfo g_emlrtRTEI = { 20, 5, "eml_error",
  "/Applications/MATLAB_R2013b.app/toolbox/eml/lib/matlab/eml/eml_error.m" };

/* End of code generation (episodicREINFORCE_data.c) */
