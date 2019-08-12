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
#include <Graphic3d_TypeOfPrimitiveArray.hxx>

void bind_Graphic3d_TypeOfPrimitiveArray(py::module &mod){

py::enum_<Graphic3d_TypeOfPrimitiveArray>(mod, "Graphic3d_TypeOfPrimitiveArray", "The type of primitive array in a group in a structure.")
	.value("Graphic3d_TOPA_UNDEFINED", Graphic3d_TypeOfPrimitiveArray::Graphic3d_TOPA_UNDEFINED)
	.value("Graphic3d_TOPA_POINTS", Graphic3d_TypeOfPrimitiveArray::Graphic3d_TOPA_POINTS)
	.value("Graphic3d_TOPA_SEGMENTS", Graphic3d_TypeOfPrimitiveArray::Graphic3d_TOPA_SEGMENTS)
	.value("Graphic3d_TOPA_POLYLINES", Graphic3d_TypeOfPrimitiveArray::Graphic3d_TOPA_POLYLINES)
	.value("Graphic3d_TOPA_TRIANGLES", Graphic3d_TypeOfPrimitiveArray::Graphic3d_TOPA_TRIANGLES)
	.value("Graphic3d_TOPA_TRIANGLESTRIPS", Graphic3d_TypeOfPrimitiveArray::Graphic3d_TOPA_TRIANGLESTRIPS)
	.value("Graphic3d_TOPA_TRIANGLEFANS", Graphic3d_TypeOfPrimitiveArray::Graphic3d_TOPA_TRIANGLEFANS)
	.value("Graphic3d_TOPA_LINES_ADJACENCY", Graphic3d_TypeOfPrimitiveArray::Graphic3d_TOPA_LINES_ADJACENCY)
	.value("Graphic3d_TOPA_LINE_STRIP_ADJACENCY", Graphic3d_TypeOfPrimitiveArray::Graphic3d_TOPA_LINE_STRIP_ADJACENCY)
	.value("Graphic3d_TOPA_TRIANGLES_ADJACENCY", Graphic3d_TypeOfPrimitiveArray::Graphic3d_TOPA_TRIANGLES_ADJACENCY)
	.value("Graphic3d_TOPA_TRIANGLE_STRIP_ADJACENCY", Graphic3d_TypeOfPrimitiveArray::Graphic3d_TOPA_TRIANGLE_STRIP_ADJACENCY)
	.value("Graphic3d_TOPA_QUADRANGLES", Graphic3d_TypeOfPrimitiveArray::Graphic3d_TOPA_QUADRANGLES)
	.value("Graphic3d_TOPA_QUADRANGLESTRIPS", Graphic3d_TypeOfPrimitiveArray::Graphic3d_TOPA_QUADRANGLESTRIPS)
	.value("Graphic3d_TOPA_POLYGONS", Graphic3d_TypeOfPrimitiveArray::Graphic3d_TOPA_POLYGONS)
	.export_values();


}