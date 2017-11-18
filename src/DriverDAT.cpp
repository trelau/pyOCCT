#include <pyOCCT_Common.hpp>

#include <Driver_SMDS_Mesh.h>
#include <Driver_Mesh.h>
#include <DriverDAT_R_SMDS_Mesh.h>
#include <DriverDAT_W_SMDS_Mesh.h>

PYBIND11_MODULE(DriverDAT, mod) {

	// IMPORT
	py::module::import("OCCT.Driver");

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
