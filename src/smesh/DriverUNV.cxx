/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>

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

	// CLASSES
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\DriverUNV_R_SMDS_Mesh.h
	py::class_<DriverUNV_R_SMDS_Mesh, Driver_SMDS_Mesh> cls_DriverUNV_R_SMDS_Mesh(mod, "DriverUNV_R_SMDS_Mesh", "None");
	cls_DriverUNV_R_SMDS_Mesh.def(py::init<>());
	cls_DriverUNV_R_SMDS_Mesh.def("Perform", (Driver_Mesh::Status (DriverUNV_R_SMDS_Mesh::*)()) &DriverUNV_R_SMDS_Mesh::Perform, "None");
	cls_DriverUNV_R_SMDS_Mesh.def("GetGroup", (const SMDS_MeshGroup * (DriverUNV_R_SMDS_Mesh::*)() const ) &DriverUNV_R_SMDS_Mesh::GetGroup, "None");
	cls_DriverUNV_R_SMDS_Mesh.def("GetGroupNamesMap", (const TGroupNamesMap & (DriverUNV_R_SMDS_Mesh::*)() const ) &DriverUNV_R_SMDS_Mesh::GetGroupNamesMap, "None");
	cls_DriverUNV_R_SMDS_Mesh.def("GetGroupIdMap", (const TGroupIdMap & (DriverUNV_R_SMDS_Mesh::*)() const ) &DriverUNV_R_SMDS_Mesh::GetGroupIdMap, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\DriverUNV_W_SMDS_Mesh.h
	py::class_<DriverUNV_W_SMDS_Mesh, Driver_SMDS_Mesh> cls_DriverUNV_W_SMDS_Mesh(mod, "DriverUNV_W_SMDS_Mesh", "None");
	cls_DriverUNV_W_SMDS_Mesh.def("Perform", (Driver_Mesh::Status (DriverUNV_W_SMDS_Mesh::*)()) &DriverUNV_W_SMDS_Mesh::Perform, "None");
	cls_DriverUNV_W_SMDS_Mesh.def("AddGroup", (void (DriverUNV_W_SMDS_Mesh::*)(SMESHDS_GroupBase *)) &DriverUNV_W_SMDS_Mesh::AddGroup, "None", py::arg("theGroup"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\DriverUNV_R_SMDS_Mesh.h
	// FIXME bind_std::map<SMDS_MeshGroup *, std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::less<SMDS_MeshGroup *>, std::allocator<std::pair<SMDS_MeshGroup *const, std::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >(mod, "TGroupNamesMap");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\DriverUNV_R_SMDS_Mesh.h
	// FIXME bind_std::map<SMDS_MeshGroup *, int, std::less<SMDS_MeshGroup *>, std::allocator<std::pair<SMDS_MeshGroup *const, int> > >(mod, "TGroupIdMap");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\DriverUNV_W_SMDS_Mesh.h
	// FIXME bind_std::list<SMESHDS_GroupBase *, std::allocator<SMESHDS_GroupBase *> >(mod, "TGroupList");


}
