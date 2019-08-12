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
#include <TopAbs_ShapeEnum.hxx>

void bind_TopAbs_ShapeEnum(py::module &mod){

py::enum_<TopAbs_ShapeEnum>(mod, "TopAbs_ShapeEnum", "Identifies various topological shapes. This enumeration allows you to use dynamic typing of shapes. The values are listed in order of complexity, from the most complex to the most simple i.e. COMPOUND > COMPSOLID > SOLID > .... > VERTEX > SHAPE. Any shape can contain simpler shapes in its definition. Abstract topological data structure describes a basic entity, the shape (present in this enumeration as the SHAPE value), which can be divided into the following component topologies: - COMPOUND: A group of any of the shapes below. - COMPSOLID: A set of solids connected by their faces. This expands the notions of WIRE and SHELL to solids. - SOLID: A part of 3D space bounded by shells. - SHELL: A set of faces connected by some of the edges of their wire boundaries. A shell can be open or closed. - FACE: Part of a plane (in 2D geometry) or a surface (in 3D geometry) bounded by a closed wire. Its geometry is constrained (trimmed) by contours. - WIRE: A sequence of edges connected by their vertices. It can be open or closed depending on whether the edges are linked or not. - EDGE: A single dimensional shape corresponding to a curve, and bound by a vertex at each extremity. - VERTEX: A zero-dimensional shape corresponding to a point in geometry.")
	.value("TopAbs_COMPOUND", TopAbs_ShapeEnum::TopAbs_COMPOUND)
	.value("TopAbs_COMPSOLID", TopAbs_ShapeEnum::TopAbs_COMPSOLID)
	.value("TopAbs_SOLID", TopAbs_ShapeEnum::TopAbs_SOLID)
	.value("TopAbs_SHELL", TopAbs_ShapeEnum::TopAbs_SHELL)
	.value("TopAbs_FACE", TopAbs_ShapeEnum::TopAbs_FACE)
	.value("TopAbs_WIRE", TopAbs_ShapeEnum::TopAbs_WIRE)
	.value("TopAbs_EDGE", TopAbs_ShapeEnum::TopAbs_EDGE)
	.value("TopAbs_VERTEX", TopAbs_ShapeEnum::TopAbs_VERTEX)
	.value("TopAbs_SHAPE", TopAbs_ShapeEnum::TopAbs_SHAPE)
	.export_values();


}