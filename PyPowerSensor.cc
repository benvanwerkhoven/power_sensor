#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "PowerSensor.cc"

namespace py = pybind11;

PYBIND11_MODULE(power_sensor, m) {
    py::class_<PowerSensor::PowerSensor>(m, "PowerSensor")
        .def(py::init<const char *>())
        .def("dump", &PowerSensor::PowerSensor::dump)
        .def("read", &PowerSensor::PowerSensor::read);

    m.def("Joules", &PowerSensor::Joules);

    py::class_<PowerSensor::State>(m, "State")
        .def_readonly("consumed_energy", &PowerSensor::State::consumedEnergy)
        .def_readonly("time_at_read", &PowerSensor::State::timeAtRead);

}
