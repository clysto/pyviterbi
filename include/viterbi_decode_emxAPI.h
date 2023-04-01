/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * viterbi_decode_emxAPI.h
 *
 * Code generation for function 'viterbi_decode_emxAPI'
 *
 */

#ifndef VITERBI_DECODE_EMXAPI_H
#define VITERBI_DECODE_EMXAPI_H

/* Include files */
#include "rtwtypes.h"
#include "viterbi_decode_types.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern emxArray_uint8_T *emxCreateND_uint8_T(int numDimensions,
                                             const int *size);

extern emxArray_uint8_T *emxCreateWrapperND_uint8_T(unsigned char *data,
                                                    int numDimensions,
                                                    const int *size);

extern emxArray_uint8_T *emxCreateWrapper_uint8_T(unsigned char *data, int rows,
                                                  int cols);

extern emxArray_uint8_T *emxCreate_uint8_T(int rows, int cols);

extern void emxDestroyArray_uint8_T(emxArray_uint8_T *emxArray);

extern void emxInitArray_uint8_T(emxArray_uint8_T **pEmxArray,
                                 int numDimensions);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (viterbi_decode_emxAPI.h) */
