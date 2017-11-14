#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <TDocStd_Application.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <AppStd_Application.hxx>

PYBIND11_MODULE(AppStd, mod) {

	// IMPORT
	py::module::import("OCCT.TDocStd");
	py::module::import("OCCT.Standard");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\AppStd_Application.hxx
	py::class_<AppStd_Application, opencascade::handle<AppStd_Application>, TDocStd_Application> cls_AppStd_Application(mod, "AppStd_Application", "Legacy class defining resources name for standard OCAF documents");
	cls_AppStd_Application.def("ResourcesName", (Standard_CString (AppStd_Application::*)()) &AppStd_Application::ResourcesName, "returns the file name which contains application resources");
	cls_AppStd_Application.def_static("get_type_name_", (const char * (*)()) &AppStd_Application::get_type_name, "None");
	cls_AppStd_Application.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AppStd_Application::get_type_descriptor, "None");
	cls_AppStd_Application.def("DynamicType", (const opencascade::handle<Standard_Type> & (AppStd_Application::*)() const ) &AppStd_Application::DynamicType, "None");


}
