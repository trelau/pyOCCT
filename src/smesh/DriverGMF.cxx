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

#include <pybind11/stl.h>

#include <Driver_SMESHDS_Mesh.h>
#include <Driver_Mesh.h>
#include <DriverGMF_Read.hxx>
#include <SMESH_ControlPnt.hxx>
#include <DriverGMF_Write.hxx>

PYBIND11_MODULE(DriverGMF, mod) {

	// IMPORT
	py::module::import("OCCT.Driver");
	py::module::import("OCCT.SMESH");

	// CLASSES
	py::class_<DriverGMF_Read, Driver_SMESHDS_Mesh> cls_DriverGMF_Read(mod, "DriverGMF_Read", "Driver reading a mesh from the GMF file. The mesh to read is selected by an index (counted form 0) set via SetMeshId()");
	cls_DriverGMF_Read.def(py::init<>());
	cls_DriverGMF_Read.def("SetMakeRequiredGroups", (void (DriverGMF_Read::*)(bool)) &DriverGMF_Read::SetMakeRequiredGroups, "None", py::arg("theMakeRequiredGroups"));
	cls_DriverGMF_Read.def("Perform", (Driver_Mesh::Status (DriverGMF_Read::*)()) &DriverGMF_Read::Perform, "None");

	py::class_<DriverGMF_Write, Driver_SMESHDS_Mesh> cls_DriverGMF_Write(mod, "DriverGMF_Write", "Driver Writing a mesh into a GMF file.");
	cls_DriverGMF_Write.def(py::init<>());
	cls_DriverGMF_Write.def("SetExportRequiredGroups", (void (DriverGMF_Write::*)(bool)) &DriverGMF_Write::SetExportRequiredGroups, "None", py::arg("toExport"));
	cls_DriverGMF_Write.def("Perform", (Driver_Mesh::Status (DriverGMF_Write::*)()) &DriverGMF_Write::Perform, "None");
	cls_DriverGMF_Write.def("PerformSizeMap", (Driver_Mesh::Status (DriverGMF_Write::*)(const std::vector<SMESHUtils::ControlPnt> &)) &DriverGMF_Write::PerformSizeMap, "None", py::arg("points"));
	cls_DriverGMF_Write.def("SetSizeMapPrefix", (void (DriverGMF_Write::*)(std::string)) &DriverGMF_Write::SetSizeMapPrefix, "None", py::arg("prefix"));
	cls_DriverGMF_Write.def("GetSizeMapFiles", (std::vector<std::string> (DriverGMF_Write::*)()) &DriverGMF_Write::GetSizeMapFiles, "None");

}
