import ctypes

lib = ctypes.CDLL("./libviterbi.so")


def decode(codein):
    codein = (ctypes.c_ubyte * len(codein))(*codein)
    codeout = (ctypes.c_ubyte * len(codein))()
    lib.decode(codein, len(codein), codeout, len(codeout))
    return list(codeout[: len(codein) // 2])
