/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * viterbi_decode_emxutil.h
 *
 * Code generation for function 'viterbi_decode_emxutil'
 *
 */

#ifndef VITERBI_DECODE_EMXUTIL_H
#define VITERBI_DECODE_EMXUTIL_H

/* Include files */
#include "rtwtypes.h"
#include "viterbi_decode_types.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void emxEnsureCapacity_uint8_T(emxArray_uint8_T *emxArray, int oldNumel);

extern void emxFree_uint8_T(emxArray_uint8_T **pEmxArray);

extern void emxInit_uint8_T(emxArray_uint8_T **pEmxArray, int numDimensions);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (viterbi_decode_emxutil.h) */
