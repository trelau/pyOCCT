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

#include <Driver_SMDS_Mesh.h>
#include <Driver_Mesh.h>
#include <DriverDAT_R_SMDS_Mesh.h>
#include <DriverDAT_W_SMDS_Mesh.h>

PYBIND11_MODULE(DriverDAT, mod) {

	// IMPORT
	py::module::import("OCCT.Driver");

	// CLASSES
	py::class_<DriverDAT_R_SMDS_Mesh, Driver_SMDS_Mesh> cls_DriverDAT_R_SMDS_Mesh(mod, "DriverDAT_R_SMDS_Mesh", "None");
	cls_DriverDAT_R_SMDS_Mesh.def("Perform", (Driver_Mesh::Status (DriverDAT_R_SMDS_Mesh::*)()) &DriverDAT_R_SMDS_Mesh::Perform, "None");

	py::class_<DriverDAT_W_SMDS_Mesh, Driver_SMDS_Mesh> cls_DriverDAT_W_SMDS_Mesh(mod, "DriverDAT_W_SMDS_Mesh", "None");
	cls_DriverDAT_W_SMDS_Mesh.def("Perform", (Driver_Mesh::Status (DriverDAT_W_SMDS_Mesh::*)()) &DriverDAT_W_SMDS_Mesh::Perform, "None");

}
