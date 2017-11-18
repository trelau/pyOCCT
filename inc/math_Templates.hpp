#ifndef __math_Templates_Header__
#define __math_Templates_Header__

#include <pyOCCT_Common.hpp>

#include <Standard_TypeDef.hxx>
#include <math_SingleTab.hxx>

// C:\Miniconda\envs\occt\Library\include\opencascade\math_SingleTab.hxx
template <typename T>
void bind_math_SingleTab(py::object &mod, std::string const &name) {

	// C:\Miniconda\envs\occt\Library\include\opencascade\math_SingleTab.hxx
	py::class_<math_SingleTab<T>, std::unique_ptr<math_SingleTab<T>, Deleter<math_SingleTab<T>>>> cls(mod, name.c_str(), "None");
	cls.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("LowerIndex"), py::arg("UpperIndex"));
	cls.def(py::init<const Standard_Address, const Standard_Integer, const Standard_Integer>(), py::arg("Tab"), py::arg("LowerIndex"), py::arg("UpperIndex"));
	cls.def(py::init([] (const math_SingleTab<T> &other) {return new math_SingleTab<T>(other);}), "Copy constructor", py::arg("other"));
	cls.def("Init", (void (math_SingleTab<T>::*)(const T)) &math_SingleTab<T>::Init, "None", py::arg("InitValue"));
	cls.def("Copy", (void (math_SingleTab<T>::*)(math_SingleTab<T> &) const ) &math_SingleTab<T>::Copy, "None", py::arg("Other"));
	cls.def("SetLower", (void (math_SingleTab<T>::*)(const Standard_Integer)) &math_SingleTab<T>::SetLower, "None", py::arg("LowerIndex"));
	cls.def("Value", (T & (math_SingleTab<T>::*)(const Standard_Integer) const ) &math_SingleTab<T>::Value, "None", py::arg("Index"));
	cls.def("__call__", (T & (math_SingleTab<T>::*)(const Standard_Integer) const ) &math_SingleTab<T>::operator(), py::is_operator(), "None", py::arg("Index"));
	cls.def("Free", (void (math_SingleTab<T>::*)()) &math_SingleTab<T>::Free, "None");

};

#endif