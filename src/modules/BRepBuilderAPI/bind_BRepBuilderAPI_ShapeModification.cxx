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
#include <BRepBuilderAPI_ShapeModification.hxx>

void bind_BRepBuilderAPI_ShapeModification(py::module &mod){

py::enum_<BRepBuilderAPI_ShapeModification>(mod, "BRepBuilderAPI_ShapeModification", "Lists the possible types of modification to a shape following a topological operation: Preserved, Deleted, Trimmed, Merged or BoundaryModified. This enumeration enables you to assign a 'state' to the different shapes that are on the list of operands for each API function. The MakeShape class then uses this to determine what has happened to the shapes which constitute the list of operands.")
	.value("BRepBuilderAPI_Preserved", BRepBuilderAPI_ShapeModification::BRepBuilderAPI_Preserved)
	.value("BRepBuilderAPI_Deleted", BRepBuilderAPI_ShapeModification::BRepBuilderAPI_Deleted)
	.value("BRepBuilderAPI_Trimmed", BRepBuilderAPI_ShapeModification::BRepBuilderAPI_Trimmed)
	.value("BRepBuilderAPI_Merged", BRepBuilderAPI_ShapeModification::BRepBuilderAPI_Merged)
	.value("BRepBuilderAPI_BoundaryModified", BRepBuilderAPI_ShapeModification::BRepBuilderAPI_BoundaryModified)
	.export_values();


}