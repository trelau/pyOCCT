#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Utils_SALOME_Exception.hxx>

PYBIND11_MODULE(Utils, mod) {

	// IMPORT

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS
	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\Utils_SALOME_Exception.hxx
	mod.def("operator<<", (std::ostream & (*)(std::ostream &, const SALOME_Exception &)) &operator<<, "None", py::arg(""), py::arg(""));
	*/
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\Utils_SALOME_Exception.hxx
	mod.def("makeText", (const char * (*)(const char *, const char *, const unsigned int)) &makeText, "None", py::arg("text"), py::arg("fileName"), py::arg("lineNumber"));


	// CLASSES
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\Utils_SALOME_Exception.hxx
	py::class_<SALOME_Exception, std::unique_ptr<SALOME_Exception, Deleter<SALOME_Exception>>, std::exception> cls_SALOME_Exception(mod, "SALOME_Exception", "None");
	cls_SALOME_Exception.def(py::init<const char *>(), py::arg("text"));
	cls_SALOME_Exception.def(py::init<const char *, const char *>(), py::arg("text"), py::arg("fileName"));
	cls_SALOME_Exception.def(py::init<const char *, const char *, const unsigned int>(), py::arg("text"), py::arg("fileName"), py::arg("lineNumber"));
	cls_SALOME_Exception.def(py::init([] (const SALOME_Exception &other) {return new SALOME_Exception(other);}), "Copy constructor", py::arg("other"));
	cls_SALOME_Exception.def("what", (const char * (SALOME_Exception::*)() const ) &SALOME_Exception::what, "None");


}
