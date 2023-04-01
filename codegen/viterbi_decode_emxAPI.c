/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * viterbi_decode_emxAPI.c
 *
 * Code generation for function 'viterbi_decode_emxAPI'
 *
 */

/* Include files */
#include "viterbi_decode_emxAPI.h"
#include "viterbi_decode_emxutil.h"
#include "viterbi_decode_types.h"
#include <stdlib.h>

/* Function Definitions */
emxArray_uint8_T *emxCreateND_uint8_T(int numDimensions, const int *size)
{
  emxArray_uint8_T *emx;
  int i;
  int numEl;
  emxInit_uint8_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }
  emx->data =
      (unsigned char *)calloc((unsigned int)numEl, sizeof(unsigned char));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

emxArray_uint8_T *emxCreateWrapperND_uint8_T(unsigned char *data,
                                             int numDimensions, const int *size)
{
  emxArray_uint8_T *emx;
  int i;
  int numEl;
  emxInit_uint8_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }
  emx->data = data;
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

emxArray_uint8_T *emxCreateWrapper_uint8_T(unsigned char *data, int rows,
                                           int cols)
{
  emxArray_uint8_T *emx;
  emxInit_uint8_T(&emx, 2);
  emx->size[0] = rows;
  emx->size[1] = cols;
  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = rows * cols;
  emx->canFreeData = false;
  return emx;
}

emxArray_uint8_T *emxCreate_uint8_T(int rows, int cols)
{
  emxArray_uint8_T *emx;
  int numEl;
  emxInit_uint8_T(&emx, 2);
  emx->size[0] = rows;
  numEl = rows * cols;
  emx->size[1] = cols;
  emx->data =
      (unsigned char *)calloc((unsigned int)numEl, sizeof(unsigned char));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

void emxDestroyArray_uint8_T(emxArray_uint8_T *emxArray)
{
  emxFree_uint8_T(&emxArray);
}

void emxInitArray_uint8_T(emxArray_uint8_T **pEmxArray, int numDimensions)
{
  emxInit_uint8_T(pEmxArray, numDimensions);
}

/* End of code generation (viterbi_decode_emxAPI.c) */
