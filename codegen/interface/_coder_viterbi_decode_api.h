/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_viterbi_decode_api.h
 *
 * Code generation for function 'viterbi_decode'
 *
 */

#ifndef _CODER_VITERBI_DECODE_API_H
#define _CODER_VITERBI_DECODE_API_H

/* Include files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_uint8_T
#define struct_emxArray_uint8_T
struct emxArray_uint8_T {
  uint8_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_uint8_T */
#ifndef typedef_emxArray_uint8_T
#define typedef_emxArray_uint8_T
typedef struct emxArray_uint8_T emxArray_uint8_T;
#endif /* typedef_emxArray_uint8_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void viterbi_decode(emxArray_uint8_T *codein, emxArray_uint8_T *decodeout);

void viterbi_decode_api(const mxArray *prhs, const mxArray **plhs);

void viterbi_decode_atexit(void);

void viterbi_decode_initialize(void);

void viterbi_decode_terminate(void);

void viterbi_decode_xil_shutdown(void);

void viterbi_decode_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_viterbi_decode_api.h) */
