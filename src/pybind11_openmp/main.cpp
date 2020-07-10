#include <pybind11/pybind11.h>
#include <Matrix.hpp>

namespace py = pybind11;

class PyIGenerator : public IGenerator {
public:

    using IGenerator::IGenerator;


    /* Trampoline (need one for each virtual function) */
    int compute(int i) override {
        PYBIND11_OVERLOAD_PURE(
            int, /* Return type */
            IGenerator,      /* Parent class */
            compute,          /* Name of function in C++ (must match Python name) */
            i      /* Argument(s) */
        );
    }
};




PYBIND11_MODULE(pybind11_openmp, m) {
    py::class_<IGenerator, PyIGenerator>(m, "IGenerator")
        .def(py::init<>())
        .def("compute",&IGenerator::compute);

    py::class_<Matrix>(m, "Matrix")
        .def(py::init<int,IGenerator&>(),py::call_guard<py::gil_scoped_release>());


}