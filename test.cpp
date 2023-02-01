#include <pybind11/pybind11.h>
#include "all.h"

namespace py = pybind11;

PYBIND11_MODULE(libtest, m) {
    m.doc() = "rtklib python interface by pybind11"; // optional module docstring
    m.def("uncompress",&uncompress,"test");
}
