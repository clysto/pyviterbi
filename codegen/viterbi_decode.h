/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * viterbi_decode.h
 *
 * Code generation for function 'viterbi_decode'
 *
 */

#ifndef VITERBI_DECODE_H
#define VITERBI_DECODE_H

/* Include files */
#include "rtwtypes.h"
#include "viterbi_decode_types.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void viterbi_decode(const emxArray_uint8_T *codein,
                           emxArray_uint8_T *decodeout);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (viterbi_decode.h) */
