#include <pybind11/pybind11.h>
#include "all.h"

namespace py = pybind11;

PYBIND11_MODULE(libtest, m) {
    m.doc() = "test"; // optional module docstring
    m.def("uncompress",&uncompress,"test");
}
