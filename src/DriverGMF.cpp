#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <DriverGMF_Read.hxx>
#include <SMESH_ControlPnt.hxx>
#include <DriverGMF_Write.hxx>

PYBIND11_MODULE(DriverGMF, mod) {

	// IMPORT
	py::module::import("OCCT.SMESH");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\DriverGMF_Read.hxx
	py::class_<DriverGMF_Read, std::unique_ptr<DriverGMF_Read, Deleter<DriverGMF_Read>>, Driver_SMESHDS_Mesh> cls_DriverGMF_Read(mod, "DriverGMF_Read", "Driver reading a mesh from the GMF file. The mesh to read is selected by an index (counted form 0) set via SetMeshId()");
	cls_DriverGMF_Read.def(py::init<>());
	cls_DriverGMF_Read.def("SetMakeRequiredGroups", (void (DriverGMF_Read::*)(bool)) &DriverGMF_Read::SetMakeRequiredGroups, "None", py::arg("theMakeRequiredGroups"));
	cls_DriverGMF_Read.def("Perform", (Driver_Mesh::Status (DriverGMF_Read::*)()) &DriverGMF_Read::Perform, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\DriverGMF_Write.hxx
	py::class_<DriverGMF_Write, std::unique_ptr<DriverGMF_Write, Deleter<DriverGMF_Write>>, Driver_SMESHDS_Mesh> cls_DriverGMF_Write(mod, "DriverGMF_Write", "Driver Writing a mesh into a GMF file.");
	cls_DriverGMF_Write.def(py::init<>());
	cls_DriverGMF_Write.def("SetExportRequiredGroups", (void (DriverGMF_Write::*)(bool)) &DriverGMF_Write::SetExportRequiredGroups, "None", py::arg("toExport"));
	cls_DriverGMF_Write.def("Perform", (Driver_Mesh::Status (DriverGMF_Write::*)()) &DriverGMF_Write::Perform, "None");
	cls_DriverGMF_Write.def("PerformSizeMap", (Driver_Mesh::Status (DriverGMF_Write::*)(const std::vector<SMESHUtils::ControlPnt> &)) &DriverGMF_Write::PerformSizeMap, "None", py::arg("points"));
	cls_DriverGMF_Write.def("SetSizeMapPrefix", (void (DriverGMF_Write::*)(std::string)) &DriverGMF_Write::SetSizeMapPrefix, "None", py::arg("prefix"));
	cls_DriverGMF_Write.def("GetSizeMapFiles", (std::vector<std::string> (DriverGMF_Write::*)()) &DriverGMF_Write::GetSizeMapFiles, "None");


}
