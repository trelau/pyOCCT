#include <pyOCCT_Common.hpp>

#include <LDOM_Document.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <LDOMParser.hxx>

PYBIND11_MODULE(LDOMParser, mod) {

	// IMPORT
	py::module::import("OCCT.LDOM");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\LDOMParser.hxx
	py::class_<LDOMParser, std::unique_ptr<LDOMParser, Deleter<LDOMParser>>> cls_LDOMParser(mod, "LDOMParser", "None");
	cls_LDOMParser.def(py::init<>());
	cls_LDOMParser.def("getDocument", (LDOM_Document (LDOMParser::*)()) &LDOMParser::getDocument, "None");
	cls_LDOMParser.def("parse", (Standard_Boolean (LDOMParser::*)(const char *const)) &LDOMParser::parse, "None", py::arg("aFileName"));
	cls_LDOMParser.def("parse", [](LDOMParser &self, std::istream & a0) -> Standard_Boolean { return self.parse(a0); }, py::arg("anInput"));
	cls_LDOMParser.def("parse", [](LDOMParser &self, std::istream & a0, const Standard_Boolean a1) -> Standard_Boolean { return self.parse(a0, a1); }, py::arg("anInput"), py::arg("theTagPerStep"));
	cls_LDOMParser.def("parse", (Standard_Boolean (LDOMParser::*)(std::istream &, const Standard_Boolean, const Standard_Boolean)) &LDOMParser::parse, "None", py::arg("anInput"), py::arg("theTagPerStep"), py::arg("theWithoutRoot"));
	cls_LDOMParser.def("GetError", (const TCollection_AsciiString & (LDOMParser::*)(TCollection_AsciiString &) const ) &LDOMParser::GetError, "None", py::arg("aData"));


}
