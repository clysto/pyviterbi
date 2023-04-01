#include <viterbi_decode.h>
#include <viterbi_decode_emxAPI.h>
#include <viterbi_decode_terminate.h>
#include <viterbi_decode_types.h>

void decode(unsigned char *codein, size_t codein_size, unsigned char *decodeout,
            size_t decodeout_size) {
  emxArray_uint8_T *codein_emx;
  emxArray_uint8_T *decodeout_emx;
  codein_emx = emxCreateWrapper_uint8_T(codein, 1, codein_size);
  decodeout_emx = emxCreateWrapper_uint8_T(decodeout, 1, decodeout_size);
  viterbi_decode(codein_emx, decodeout_emx);
  emxDestroyArray_uint8_T(codein_emx);
  emxDestroyArray_uint8_T(decodeout_emx);
}
