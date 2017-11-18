#include <pyOCCT_Common.hpp>

#include <LDOMBasicString.hxx>
#include <LDOMString.hxx>
#include <Standard_TypeDef.hxx>
#include <LDOM_MemManager.hxx>

PYBIND11_MODULE(LDOMString, mod) {

	// IMPORT
	py::module::import("OCCT.LDOMBasicString");
	py::module::import("OCCT.Standard");

	py::module other_mod;

	// IMPORT GUARDS
	struct ImportLDOM{
		ImportLDOM() { py::module::import("OCCT.LDOM"); }
	};


	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOMString.hxx
	py::class_<LDOMString, std::unique_ptr<LDOMString, Deleter<LDOMString>>, LDOMBasicString> cls_LDOMString(mod, "LDOMString", "None");
	cls_LDOMString.def(py::init<>());
	cls_LDOMString.def(py::init([] (const LDOMString &other) {return new LDOMString(other);}), "Copy constructor", py::arg("other"));
	cls_LDOMString.def(py::init<const Standard_Integer>(), py::arg("aValue"));
	cls_LDOMString.def(py::init<const char *>(), py::arg("aValue"));
	cls_LDOMString.def("getOwnerDocument", (const LDOM_MemManager & (LDOMString::*)() const ) &LDOMString::getOwnerDocument, "None", py::call_guard<ImportLDOM>());
	// FIXME cls_LDOMString.def("assign", (LDOMString & (LDOMString::*)(const LDOM_NullPtr *)) &LDOMString::operator=, py::is_operator(), "None", py::arg("aNull"));
	cls_LDOMString.def("assign", (LDOMString & (LDOMString::*)(const LDOMString &)) &LDOMString::operator=, py::is_operator(), "None", py::arg("anOther"));


}
