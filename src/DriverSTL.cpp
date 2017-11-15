#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Driver_SMDS_Mesh.h>
#include <Driver_Mesh.h>
#include <DriverSTL_R_SMDS_Mesh.h>
#include <DriverSTL_W_SMDS_Mesh.h>

PYBIND11_MODULE(DriverSTL, mod) {

	// IMPORT
	py::module::import("OCCT.Driver");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\DriverSTL_R_SMDS_Mesh.h
	py::class_<DriverSTL_R_SMDS_Mesh, std::unique_ptr<DriverSTL_R_SMDS_Mesh, Deleter<DriverSTL_R_SMDS_Mesh>>, Driver_SMDS_Mesh> cls_DriverSTL_R_SMDS_Mesh(mod, "DriverSTL_R_SMDS_Mesh", "None");
	cls_DriverSTL_R_SMDS_Mesh.def(py::init<>());
	cls_DriverSTL_R_SMDS_Mesh.def("Perform", (Driver_Mesh::Status (DriverSTL_R_SMDS_Mesh::*)()) &DriverSTL_R_SMDS_Mesh::Perform, "None");
	cls_DriverSTL_R_SMDS_Mesh.def("SetIsCreateFaces", [](DriverSTL_R_SMDS_Mesh &self) -> void { return self.SetIsCreateFaces(); });
	cls_DriverSTL_R_SMDS_Mesh.def("SetIsCreateFaces", (void (DriverSTL_R_SMDS_Mesh::*)(const bool)) &DriverSTL_R_SMDS_Mesh::SetIsCreateFaces, "None", py::arg("theIsCreate"));
	cls_DriverSTL_R_SMDS_Mesh.def("GetName", (std::string (DriverSTL_R_SMDS_Mesh::*)() const ) &DriverSTL_R_SMDS_Mesh::GetName, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\DriverSTL_W_SMDS_Mesh.h
	py::class_<DriverSTL_W_SMDS_Mesh, std::unique_ptr<DriverSTL_W_SMDS_Mesh, Deleter<DriverSTL_W_SMDS_Mesh>>, Driver_SMDS_Mesh> cls_DriverSTL_W_SMDS_Mesh(mod, "DriverSTL_W_SMDS_Mesh", "Writer of a mesh in STL (STereoLithography) file format.");
	cls_DriverSTL_W_SMDS_Mesh.def(py::init<>());
	cls_DriverSTL_W_SMDS_Mesh.def("Perform", (Driver_Mesh::Status (DriverSTL_W_SMDS_Mesh::*)()) &DriverSTL_W_SMDS_Mesh::Perform, "None");
	cls_DriverSTL_W_SMDS_Mesh.def("SetIsAscii", [](DriverSTL_W_SMDS_Mesh &self) -> void { return self.SetIsAscii(); });
	cls_DriverSTL_W_SMDS_Mesh.def("SetIsAscii", (void (DriverSTL_W_SMDS_Mesh::*)(const bool)) &DriverSTL_W_SMDS_Mesh::SetIsAscii, "None", py::arg("theIsAscii"));
	cls_DriverSTL_W_SMDS_Mesh.def("SetName", (void (DriverSTL_W_SMDS_Mesh::*)(const std::string)) &DriverSTL_W_SMDS_Mesh::SetName, "None", py::arg("name"));


}
