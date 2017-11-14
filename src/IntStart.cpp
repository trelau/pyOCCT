#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Standard_Transient.hxx>
#include <TopAbs_State.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <IntStart_SITopolTool.hxx>

PYBIND11_MODULE(IntStart, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.gp");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntStart_SITopolTool.hxx
	py::class_<IntStart_SITopolTool, opencascade::handle<IntStart_SITopolTool>, Standard_Transient> cls_IntStart_SITopolTool(mod, "IntStart_SITopolTool", "template class for a topological tool. This tool is linked with the surface on which the classification has to be made.");
	cls_IntStart_SITopolTool.def("Classify", (TopAbs_State (IntStart_SITopolTool::*)(const gp_Pnt2d &, const Standard_Real)) &IntStart_SITopolTool::Classify, "None", py::arg("P"), py::arg("Tol"));
	cls_IntStart_SITopolTool.def_static("get_type_name_", (const char * (*)()) &IntStart_SITopolTool::get_type_name, "None");
	cls_IntStart_SITopolTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IntStart_SITopolTool::get_type_descriptor, "None");
	cls_IntStart_SITopolTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (IntStart_SITopolTool::*)() const ) &IntStart_SITopolTool::DynamicType, "None");


}
