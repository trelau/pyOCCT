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
#include <Prs3d_VertexDrawMode.hxx>

void bind_Prs3d_VertexDrawMode(py::module &mod){

py::enum_<Prs3d_VertexDrawMode>(mod, "Prs3d_VertexDrawMode", "Describes supported modes of visualization of the shape's vertices: VDM_Isolated - only isolated vertices (not belonging to a face) are displayed. VDM_All - all vertices of the shape are displayed. VDM_Inherited - the global settings are inherited and applied to the shape's presentation.")
	.value("Prs3d_VDM_Isolated", Prs3d_VertexDrawMode::Prs3d_VDM_Isolated)
	.value("Prs3d_VDM_All", Prs3d_VertexDrawMode::Prs3d_VDM_All)
	.value("Prs3d_VDM_Inherited", Prs3d_VertexDrawMode::Prs3d_VDM_Inherited)
	.export_values();


}