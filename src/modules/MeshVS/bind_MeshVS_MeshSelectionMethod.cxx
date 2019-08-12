/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

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
#include <MeshVS_MeshSelectionMethod.hxx>

void bind_MeshVS_MeshSelectionMethod(py::module &mod){

py::enum_<MeshVS_MeshSelectionMethod>(mod, "MeshVS_MeshSelectionMethod", "this enumeration describe what type of sensitive entity will be built in 0-th selection mode (it means that whole mesh is selected )")
	.value("MeshVS_MSM_PRECISE", MeshVS_MeshSelectionMethod::MeshVS_MSM_PRECISE)
	.value("MeshVS_MSM_NODES", MeshVS_MeshSelectionMethod::MeshVS_MSM_NODES)
	.value("MeshVS_MSM_BOX", MeshVS_MeshSelectionMethod::MeshVS_MSM_BOX)
	.export_values();


}