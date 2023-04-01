import ctypes
import os


dll_name = "libviterbi.so"
dllabspath = os.path.dirname(os.path.abspath(__file__)) + os.path.sep + dll_name

lib = ctypes.CDLL(dllabspath)


def decode(codein):
    codein = (ctypes.c_ubyte * len(codein))(*codein)
    codeout = (ctypes.c_ubyte * len(codein))()
    lib.decode(codein, len(codein), codeout, len(codeout))
    return list(codeout[: len(codein) // 2])
