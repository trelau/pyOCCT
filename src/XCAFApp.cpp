#include <pyOCCT_Common.hpp>

#include <TDocStd_Application.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TDocStd_Document.hxx>
#include <XCAFApp_Application.hxx>
#include <Standard_Type.hxx>

PYBIND11_MODULE(XCAFApp, mod) {

	// IMPORT
	py::module::import("OCCT.TDocStd");
	py::module::import("OCCT.Standard");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\XCAFApp_Application.hxx
	py::class_<XCAFApp_Application, opencascade::handle<XCAFApp_Application>, TDocStd_Application> cls_XCAFApp_Application(mod, "XCAFApp_Application", "Implements an Application for the DECAF documents");
	cls_XCAFApp_Application.def("ResourcesName", (Standard_CString (XCAFApp_Application::*)()) &XCAFApp_Application::ResourcesName, "methods from TDocStd_Application ================================");
	cls_XCAFApp_Application.def("InitDocument", (void (XCAFApp_Application::*)(const opencascade::handle<TDocStd_Document> &) const ) &XCAFApp_Application::InitDocument, "Set XCAFDoc_DocumentTool attribute", py::arg("aDoc"));
	cls_XCAFApp_Application.def_static("GetApplication_", (opencascade::handle<XCAFApp_Application> (*)()) &XCAFApp_Application::GetApplication, "Initializes (for the first time) and returns the static object (XCAFApp_Application) This is the only valid method to get XCAFApp_Application object, and it should be called at least once before any actions with documents in order to init application");
	cls_XCAFApp_Application.def_static("get_type_name_", (const char * (*)()) &XCAFApp_Application::get_type_name, "None");
	cls_XCAFApp_Application.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFApp_Application::get_type_descriptor, "None");
	cls_XCAFApp_Application.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFApp_Application::*)() const ) &XCAFApp_Application::DynamicType, "None");


}
