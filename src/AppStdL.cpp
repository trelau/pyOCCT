#include <pyOCCT_Common.hpp>

#include <TDocStd_Application.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <AppStdL_Application.hxx>

PYBIND11_MODULE(AppStdL, mod) {

	// IMPORT
	py::module::import("OCCT.TDocStd");
	py::module::import("OCCT.Standard");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\AppStdL_Application.hxx
	py::class_<AppStdL_Application, opencascade::handle<AppStdL_Application>, TDocStd_Application> cls_AppStdL_Application(mod, "AppStdL_Application", "Legacy class defining resources name for lite OCAF documents");
	cls_AppStdL_Application.def("ResourcesName", (Standard_CString (AppStdL_Application::*)()) &AppStdL_Application::ResourcesName, "returns the file name which contains application resources");
	cls_AppStdL_Application.def_static("get_type_name_", (const char * (*)()) &AppStdL_Application::get_type_name, "None");
	cls_AppStdL_Application.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AppStdL_Application::get_type_descriptor, "None");
	cls_AppStdL_Application.def("DynamicType", (const opencascade::handle<Standard_Type> & (AppStdL_Application::*)() const ) &AppStdL_Application::DynamicType, "None");


}
