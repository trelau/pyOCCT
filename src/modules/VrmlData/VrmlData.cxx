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

void bind_VrmlData_ErrorStatus(py::module &);
void bind_VrmlData_Node(py::module &);
void bind_VrmlData_Material(py::module &);
void bind_VrmlData_Texture(py::module &);
void bind_VrmlData_TextureTransform(py::module &);
void bind_VrmlData_Appearance(py::module &);
void bind_VrmlData_ArrayVec3d(py::module &);
void bind_VrmlData_Geometry(py::module &);
void bind_VrmlData_Box(py::module &);
void bind_VrmlData_Color(py::module &);
void bind_VrmlData_Cone(py::module &);
void bind_VrmlData_Coordinate(py::module &);
void bind_VrmlData_Cylinder(py::module &);
void bind_VrmlData_DataMapOfShapeAppearance(py::module &);
void bind_VrmlData_Faceted(py::module &);
void bind_VrmlData_ListOfNode(py::module &);
void bind_VrmlData_Group(py::module &);
void bind_VrmlData_ImageTexture(py::module &);
void bind_VrmlData_InBuffer(py::module &);
void bind_VrmlData_Normal(py::module &);
void bind_VrmlData_TextureCoordinate(py::module &);
void bind_VrmlData_IndexedFaceSet(py::module &);
void bind_VrmlData_IndexedLineSet(py::module &);
void bind_VrmlData_MapOfNode(py::module &);
void bind_VrmlData_WorldInfo(py::module &);
void bind_VrmlData_Scene(py::module &);
void bind_VrmlData_ShapeConvert(py::module &);
void bind_VrmlData_ShapeNode(py::module &);
void bind_VrmlData_Sphere(py::module &);
void bind_VrmlData_UnknownNode(py::module &);

PYBIND11_MODULE(VrmlData, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.gp");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.Poly");

bind_VrmlData_ErrorStatus(mod);
bind_VrmlData_Node(mod);
bind_VrmlData_Material(mod);
bind_VrmlData_Texture(mod);
bind_VrmlData_TextureTransform(mod);
bind_VrmlData_Appearance(mod);
bind_VrmlData_ArrayVec3d(mod);
bind_VrmlData_Geometry(mod);
bind_VrmlData_Box(mod);
bind_VrmlData_Color(mod);
bind_VrmlData_Cone(mod);
bind_VrmlData_Coordinate(mod);
bind_VrmlData_Cylinder(mod);
bind_VrmlData_DataMapOfShapeAppearance(mod);
bind_VrmlData_Faceted(mod);
bind_VrmlData_ListOfNode(mod);
bind_VrmlData_Group(mod);
bind_VrmlData_ImageTexture(mod);
bind_VrmlData_InBuffer(mod);
bind_VrmlData_Normal(mod);
bind_VrmlData_TextureCoordinate(mod);
bind_VrmlData_IndexedFaceSet(mod);
bind_VrmlData_IndexedLineSet(mod);
bind_VrmlData_MapOfNode(mod);
bind_VrmlData_WorldInfo(mod);
bind_VrmlData_Scene(mod);
bind_VrmlData_ShapeConvert(mod);
bind_VrmlData_ShapeNode(mod);
bind_VrmlData_Sphere(mod);
bind_VrmlData_UnknownNode(mod);

}
