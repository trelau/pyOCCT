#include <pyOCCT_Common.hpp>

#include <DriverUNV_R_SMDS_Mesh.h>
#include <Driver_SMDS_Mesh.h>
#include <Driver_Mesh.h>
#include <SMDS_MeshGroup.hxx>
#include <DriverUNV_W_SMDS_Mesh.h>
#include <SMESHDS_GroupBase.hxx>

PYBIND11_MODULE(DriverUNV, mod) {

	// IMPORT
	py::module::import("OCCT.Driver");
	py::module::import("OCCT.SMDS");
	py::module::import("OCCT.SMESHDS");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\DriverUNV_R_SMDS_Mesh.h
	py::class_<DriverUNV_R_SMDS_Mesh, std::unique_ptr<DriverUNV_R_SMDS_Mesh, Deleter<DriverUNV_R_SMDS_Mesh>>, Driver_SMDS_Mesh> cls_DriverUNV_R_SMDS_Mesh(mod, "DriverUNV_R_SMDS_Mesh", "None");
	cls_DriverUNV_R_SMDS_Mesh.def(py::init<>());
	cls_DriverUNV_R_SMDS_Mesh.def("Perform", (Driver_Mesh::Status (DriverUNV_R_SMDS_Mesh::*)()) &DriverUNV_R_SMDS_Mesh::Perform, "None");
	cls_DriverUNV_R_SMDS_Mesh.def("GetGroup", (const SMDS_MeshGroup * (DriverUNV_R_SMDS_Mesh::*)() const ) &DriverUNV_R_SMDS_Mesh::GetGroup, "None");
	cls_DriverUNV_R_SMDS_Mesh.def("GetGroupNamesMap", (const TGroupNamesMap & (DriverUNV_R_SMDS_Mesh::*)() const ) &DriverUNV_R_SMDS_Mesh::GetGroupNamesMap, "None");
	cls_DriverUNV_R_SMDS_Mesh.def("GetGroupIdMap", (const TGroupIdMap & (DriverUNV_R_SMDS_Mesh::*)() const ) &DriverUNV_R_SMDS_Mesh::GetGroupIdMap, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\DriverUNV_W_SMDS_Mesh.h
	py::class_<DriverUNV_W_SMDS_Mesh, std::unique_ptr<DriverUNV_W_SMDS_Mesh, Deleter<DriverUNV_W_SMDS_Mesh>>, Driver_SMDS_Mesh> cls_DriverUNV_W_SMDS_Mesh(mod, "DriverUNV_W_SMDS_Mesh", "None");
	cls_DriverUNV_W_SMDS_Mesh.def("Perform", (Driver_Mesh::Status (DriverUNV_W_SMDS_Mesh::*)()) &DriverUNV_W_SMDS_Mesh::Perform, "None");
	cls_DriverUNV_W_SMDS_Mesh.def("AddGroup", (void (DriverUNV_W_SMDS_Mesh::*)(SMESHDS_GroupBase *)) &DriverUNV_W_SMDS_Mesh::AddGroup, "None", py::arg("theGroup"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\DriverUNV_R_SMDS_Mesh.h
	// FIXME bind_std::map<SMDS_MeshGroup *, std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::less<SMDS_MeshGroup *>, std::allocator<std::pair<SMDS_MeshGroup *const, std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >(mod, "TGroupNamesMap");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\DriverUNV_R_SMDS_Mesh.h
	// FIXME bind_std::map<SMDS_MeshGroup *, int, std::less<SMDS_MeshGroup *>, std::allocator<std::pair<SMDS_MeshGroup *const, int> > >(mod, "TGroupIdMap");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\DriverUNV_W_SMDS_Mesh.h
	// FIXME bind_std::list<SMESHDS_GroupBase *, std::allocator<SMESHDS_GroupBase *> >(mod, "TGroupList");


}
