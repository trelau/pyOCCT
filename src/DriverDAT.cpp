#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };


PYBIND11_MODULE(DriverDAT, mod) {

	// IMPORT

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\DriverDAT_R_SMDS_Mesh.h
	py::class_<DriverDAT_R_SMDS_Mesh, std::unique_ptr<DriverDAT_R_SMDS_Mesh, Deleter<DriverDAT_R_SMDS_Mesh>>, Driver_SMDS_Mesh> cls_DriverDAT_R_SMDS_Mesh(mod, "DriverDAT_R_SMDS_Mesh", "None");
	cls_DriverDAT_R_SMDS_Mesh.def("Perform", (Driver_Mesh::Status (DriverDAT_R_SMDS_Mesh::*)()) &DriverDAT_R_SMDS_Mesh::Perform, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\DriverDAT_W_SMDS_Mesh.h
	py::class_<DriverDAT_W_SMDS_Mesh, std::unique_ptr<DriverDAT_W_SMDS_Mesh, Deleter<DriverDAT_W_SMDS_Mesh>>, Driver_SMDS_Mesh> cls_DriverDAT_W_SMDS_Mesh(mod, "DriverDAT_W_SMDS_Mesh", "None");
	cls_DriverDAT_W_SMDS_Mesh.def("Perform", (Driver_Mesh::Status (DriverDAT_W_SMDS_Mesh::*)()) &DriverDAT_W_SMDS_Mesh::Perform, "None");


}
