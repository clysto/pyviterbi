/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * viterbi_decode.c
 *
 * Code generation for function 'viterbi_decode'
 *
 */

/* Include files */
#include "viterbi_decode.h"
#include "viterbi_decode_emxutil.h"
#include "viterbi_decode_types.h"
#include <math.h>
#include <string.h>

/* Function Declarations */
static int div_s32_floor(int numerator, int denominator);

static double rt_roundd_snf(double u);

/* Function Definitions */
static int div_s32_floor(int numerator, int denominator)
{
  int quotient;
  if (denominator == 0) {
    if (numerator >= 0) {
      quotient = MAX_int32_T;
    } else {
      quotient = MIN_int32_T;
    }
  } else {
    unsigned int absDenominator;
    unsigned int absNumerator;
    unsigned int tempAbsQuotient;
    bool quotientNeedsNegation;
    if (numerator < 0) {
      absNumerator = ~(unsigned int)numerator + 1U;
    } else {
      absNumerator = (unsigned int)numerator;
    }
    if (denominator < 0) {
      absDenominator = ~(unsigned int)denominator + 1U;
    } else {
      absDenominator = (unsigned int)denominator;
    }
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
      quotient = -(int)tempAbsQuotient;
    } else {
      quotient = (int)tempAbsQuotient;
    }
  }
  return quotient;
}

static double rt_roundd_snf(double u)
{
  double y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }
  return y;
}

void viterbi_decode(const emxArray_uint8_T *codein, emxArray_uint8_T *decodeout)
{
  static const unsigned short uv[64] = {
      0U,     32767U, 32767U, 32767U, 32767U, 32767U, 32767U, 32767U,
      32767U, 32767U, 32767U, 32767U, 32767U, 32767U, 32767U, 32767U,
      32767U, 32767U, 32767U, 32767U, 32767U, 32767U, 32767U, 32767U,
      32767U, 32767U, 32767U, 32767U, 32767U, 32767U, 32767U, 32767U,
      32767U, 32767U, 32767U, 32767U, 32767U, 32767U, 32767U, 32767U,
      32767U, 32767U, 32767U, 32767U, 32767U, 32767U, 32767U, 32767U,
      32767U, 32767U, 32767U, 32767U, 32767U, 32767U, 32767U, 32767U,
      32767U, 32767U, 32767U, 32767U, 32767U, 32767U, 32767U, 32767U};
  static const signed char nextState[128] = {
      0,  0,  1,  1,  2,  2,  3,  3,  4,  4,  5,  5,  6,  6,  7,  7,
      8,  8,  9,  9,  10, 10, 11, 11, 12, 12, 13, 13, 14, 14, 15, 15,
      16, 16, 17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 23,
      24, 24, 25, 25, 26, 26, 27, 27, 28, 28, 29, 29, 30, 30, 31, 31,
      32, 32, 33, 33, 34, 34, 35, 35, 36, 36, 37, 37, 38, 38, 39, 39,
      40, 40, 41, 41, 42, 42, 43, 43, 44, 44, 45, 45, 46, 46, 47, 47,
      48, 48, 49, 49, 50, 50, 51, 51, 52, 52, 53, 53, 54, 54, 55, 55,
      56, 56, 57, 57, 58, 58, 59, 59, 60, 60, 61, 61, 62, 62, 63, 63};
  static const signed char output[128] = {
      0, 3, 2, 1, 0, 3, 2, 1, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 1, 2, 3, 0,
      1, 2, 0, 3, 2, 1, 0, 3, 2, 1, 1, 2, 3, 0, 1, 2, 3, 0, 2, 1, 0, 3,
      2, 1, 0, 3, 2, 1, 0, 3, 2, 1, 0, 3, 1, 2, 3, 0, 1, 2, 3, 0, 3, 0,
      1, 2, 3, 0, 1, 2, 0, 3, 2, 1, 0, 3, 2, 1, 0, 3, 2, 1, 0, 3, 2, 1,
      3, 0, 1, 2, 3, 0, 1, 2, 2, 1, 0, 3, 2, 1, 0, 3, 1, 2, 3, 0, 1, 2,
      3, 0, 1, 2, 3, 0, 1, 2, 3, 0, 2, 1, 0, 3, 2, 1, 0, 3};
  emxArray_uint8_T *preDecodVec;
  int i;
  int ib;
  int inputIdxOffset;
  int nextStateIdx;
  int p;
  int qY;
  int stateIdx;
  signed char tbInput[2304];
  signed char tbState[2304];
  const unsigned char *codein_data;
  unsigned char *decodeout_data;
  unsigned char *preDecodVec_data;
  codein_data = codein->data;
  i = decodeout->size[0] * decodeout->size[1];
  decodeout->size[0] = 1;
  decodeout->size[1] = codein->size[1];
  emxEnsureCapacity_uint8_T(decodeout, i);
  decodeout_data = decodeout->data;
  nextStateIdx = codein->size[1];
  for (i = 0; i < nextStateIdx; i++) {
    decodeout_data[i] = codein_data[i];
  }
  if (codein->size[1] != 0) {
    int stateMetric[64];
    int blockSize;
    int input;
    int minStateLastTB;
    int tbIdx;
    unsigned int tbWorkLastTB;
    for (i = 0; i < 64; i++) {
      stateMetric[i] = uv[i];
    }
    memset(&tbInput[0], 0, 2304U * sizeof(signed char));
    memset(&tbState[0], 0, 2304U * sizeof(signed char));
    tbIdx = 0;
    emxInit_uint8_T(&preDecodVec, 1);
    i = preDecodVec->size[0];
    preDecodVec->size[0] = codein->size[1];
    emxEnsureCapacity_uint8_T(preDecodVec, i);
    preDecodVec_data = preDecodVec->data;
    nextStateIdx = codein->size[1];
    for (i = 0; i < nextStateIdx; i++) {
      preDecodVec_data[i] = codein_data[i];
    }
    blockSize = (int)rt_roundd_snf((double)codein->size[1] / 2.0);
    i = decodeout->size[0] * decodeout->size[1];
    decodeout->size[0] = 1;
    decodeout->size[1] = blockSize;
    emxEnsureCapacity_uint8_T(decodeout, i);
    decodeout_data = decodeout->data;
    for (i = 0; i < blockSize; i++) {
      decodeout_data[i] = 0U;
    }
    tbWorkLastTB = 1U;
    minStateLastTB = 0;
    i = blockSize - 1;
    input = 0;
    for (ib = 0; ib <= i; ib++) {
      int tempMetric[64];
      int branchMetric[4];
      int outputIdxOffset;
      int renorm;
      unsigned int tbWork;
      outputIdxOffset =
          (ib - div_s32_floor(ib - 35, blockSize) * blockSize) - 35;
      inputIdxOffset = ib << 1;
      for (p = 0; p < 4; p++) {
        branchMetric[p] = 0;
        if ((p & 1) != 0) {
          if (inputIdxOffset > 2147483645) {
            qY = MAX_int32_T;
          } else {
            qY = inputIdxOffset + 2;
          }
          qY = 1 - preDecodVec_data[qY - 1];
          branchMetric[p] = qY;
        } else {
          if (inputIdxOffset > 2147483645) {
            qY = MAX_int32_T;
          } else {
            qY = inputIdxOffset + 2;
          }
          qY = preDecodVec_data[qY - 1];
          branchMetric[p] = qY;
        }
        if (p >> 1 != 0) {
          nextStateIdx = 1 - preDecodVec_data[inputIdxOffset];
          if ((qY < 0) && (nextStateIdx < MIN_int32_T - qY)) {
            qY = MIN_int32_T;
          } else if ((qY > 0) && (nextStateIdx > MAX_int32_T - qY)) {
            qY = MAX_int32_T;
          } else {
            qY += nextStateIdx;
          }
          branchMetric[p] = qY;
        } else {
          nextStateIdx = preDecodVec_data[inputIdxOffset];
          branchMetric[p] = qY + nextStateIdx;
        }
      }
      renorm = 32767;
      for (inputIdxOffset = 0; inputIdxOffset < 64; inputIdxOffset++) {
        tempMetric[inputIdxOffset] = 32767;
      }
      for (stateIdx = 0; stateIdx < 64; stateIdx++) {
        nextStateIdx = nextState[stateIdx];
        p = stateMetric[stateIdx];
        qY = branchMetric[output[stateIdx]];
        if ((p < 0) && (qY < MIN_int32_T - p)) {
          qY = MIN_int32_T;
        } else if ((p > 0) && (qY > MAX_int32_T - p)) {
          qY = MAX_int32_T;
        } else {
          qY += p;
        }
        if (qY < tempMetric[nextStateIdx]) {
          tempMetric[nextStateIdx] = qY;
          if (qY < renorm) {
            renorm = qY;
          }
          nextStateIdx += tbIdx << 6;
          tbState[nextStateIdx] = (signed char)stateIdx;
          tbInput[nextStateIdx] = 0;
        }
        nextStateIdx = nextState[stateIdx + 64];
        qY = branchMetric[output[stateIdx + 64]];
        if ((p < 0) && (qY < MIN_int32_T - p)) {
          qY = MIN_int32_T;
        } else if ((p > 0) && (qY > MAX_int32_T - p)) {
          qY = MAX_int32_T;
        } else {
          qY += p;
        }
        if (qY < tempMetric[nextStateIdx]) {
          tempMetric[nextStateIdx] = qY;
          if (qY < renorm) {
            renorm = qY;
          }
          nextStateIdx += tbIdx << 6;
          tbState[nextStateIdx] = (signed char)stateIdx;
          tbInput[nextStateIdx] = 1;
        }
      }
      inputIdxOffset = 0;
      for (stateIdx = 0; stateIdx < 64; stateIdx++) {
        p = tempMetric[stateIdx];
        if ((p >= 0) && (renorm < p - MAX_int32_T)) {
          qY = MAX_int32_T;
        } else if ((p < 0) && (renorm > p - MIN_int32_T)) {
          qY = MIN_int32_T;
        } else {
          qY = p - renorm;
        }
        stateMetric[stateIdx] = qY;
        if (qY == 0) {
          inputIdxOffset = stateIdx;
        }
      }
      tbWork = (unsigned int)tbIdx + 1U;
      if (ib == blockSize - 1) {
        minStateLastTB = inputIdxOffset;
        tbWorkLastTB = (unsigned int)tbIdx + 1U;
      }
      if (ib >= 35) {
        for (qY = 0; qY < 36; qY++) {
          nextStateIdx = inputIdxOffset + (((int)tbWork - 1) << 6);
          input = tbInput[nextStateIdx];
          inputIdxOffset = tbState[nextStateIdx];
          if (tbWork - 1U > 0U) {
            tbWork--;
          } else {
            tbWork = 36U;
          }
        }
        if (outputIdxOffset > 2147483646) {
          qY = MAX_int32_T;
        } else {
          qY = outputIdxOffset + 1;
        }
        decodeout_data[qY - 1] = (unsigned char)input;
      }
      if (tbIdx < 35) {
        tbIdx = (int)((unsigned int)tbIdx + 1U);
      } else {
        tbIdx = 0;
      }
    }
    emxFree_uint8_T(&preDecodVec);
    for (qY = 0; qY < 35; qY++) {
      nextStateIdx = minStateLastTB + (((int)tbWorkLastTB - 1) << 6);
      decodeout_data[(blockSize - qY) - 1] =
          (unsigned char)tbInput[nextStateIdx];
      minStateLastTB = tbState[nextStateIdx];
      if (tbWorkLastTB - 1U > 0U) {
        tbWorkLastTB--;
      } else {
        tbWorkLastTB = 36U;
      }
    }
  }
}

/* End of code generation (viterbi_decode.c) */
