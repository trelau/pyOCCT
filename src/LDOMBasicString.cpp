#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <LDOMBasicString.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <LDOM_MemManager.hxx>

PYBIND11_MODULE(LDOMBasicString, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");

	py::module other_mod;

	// IMPORT GUARDS
	struct ImportLDOM{
		ImportLDOM() { py::module::import("OCCT.LDOM"); }
	};


	// ENUMS

	// FUNCTIONS

	// CLASSES
	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOMBasicString.hxx
	py::class_<LDOM_NullPtr, std::unique_ptr<LDOM_NullPtr, Deleter<LDOM_NullPtr>>> cls_LDOM_NullPtr(mod, "LDOM_NullPtr", "None");
	cls_LDOM_NullPtr.def(py::init<>());
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOMBasicString.hxx
	py::class_<LDOMBasicString, std::unique_ptr<LDOMBasicString, Deleter<LDOMBasicString>>> cls_LDOMBasicString(mod, "LDOMBasicString", "None");
	cls_LDOMBasicString.def(py::init<>());
	cls_LDOMBasicString.def(py::init([] (const LDOMBasicString &other) {return new LDOMBasicString(other);}), "Copy constructor", py::arg("other"));
	cls_LDOMBasicString.def(py::init<const Standard_Integer>(), py::arg("aValue"));
	cls_LDOMBasicString.def(py::init<const char *>(), py::arg("aValue"));
	cls_LDOMBasicString.def(py::init<const char *, const opencascade::handle<LDOM_MemManager> &>(), py::arg("aValue"), py::arg("aDoc"));
	cls_LDOMBasicString.def(py::init<const char *, const Standard_Integer, const opencascade::handle<LDOM_MemManager> &>(), py::arg("aValue"), py::arg("aLen"), py::arg("aDoc"));
	cls_LDOMBasicString.def("Type", (LDOMBasicString::StringType (LDOMBasicString::*)() const ) &LDOMBasicString::Type, "None");
	cls_LDOMBasicString.def("GetInteger", (Standard_Boolean (LDOMBasicString::*)(Standard_Integer &) const ) &LDOMBasicString::GetInteger, "None", py::arg("aResult"));
	cls_LDOMBasicString.def("GetString", (const char * (LDOMBasicString::*)() const ) &LDOMBasicString::GetString, "None");
	cls_LDOMBasicString.def("equals", (Standard_Boolean (LDOMBasicString::*)(const LDOMBasicString &) const ) &LDOMBasicString::equals, "None", py::arg("anOther"));
	// FIXME cls_LDOMBasicString.def("assign", (LDOMBasicString & (LDOMBasicString::*)(const LDOM_NullPtr *)) &LDOMBasicString::operator=, py::is_operator(), "None", py::arg(""));
	// FIXME cls_LDOMBasicString.def("assign", (LDOMBasicString & (LDOMBasicString::*)(const LDOMBasicString &)) &LDOMBasicString::operator=, py::is_operator(), "None", py::arg("anOther"));
	// FIXME cls_LDOMBasicString.def("__eq__", (Standard_Boolean (LDOMBasicString::*)(const LDOM_NullPtr *) const ) &LDOMBasicString::operator==, py::is_operator(), "None", py::arg(""));
	// FIXME cls_LDOMBasicString.def("__ne__", (Standard_Boolean (LDOMBasicString::*)(const LDOM_NullPtr *) const ) &LDOMBasicString::operator!=, py::is_operator(), "None", py::arg(""));
	// FIXME cls_LDOMBasicString.def("__eq__", (Standard_Boolean (LDOMBasicString::*)(const LDOMBasicString &) const ) &LDOMBasicString::operator==, py::is_operator(), "None", py::arg("anOther"));
	// FIXME cls_LDOMBasicString.def("__ne__", (Standard_Boolean (LDOMBasicString::*)(const LDOMBasicString &) const ) &LDOMBasicString::operator!=, py::is_operator(), "None", py::arg("anOther"));


}
