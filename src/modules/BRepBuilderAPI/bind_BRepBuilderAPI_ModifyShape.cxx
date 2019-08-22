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
#include <BRepBuilderAPI_MakeShape.hxx>
#include <Standard.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <BRepTools_Modification.hxx>
#include <BRepTools_Modifier.hxx>
#include <BRepBuilderAPI_ModifyShape.hxx>

void bind_BRepBuilderAPI_ModifyShape(py::module &mod){

py::class_<BRepBuilderAPI_ModifyShape, BRepBuilderAPI_MakeShape> cls_BRepBuilderAPI_ModifyShape(mod, "BRepBuilderAPI_ModifyShape", "Implements the methods of MakeShape for the constant topology modifications. The methods are implemented when the modification uses a Modifier from BRepTools. Some of them have to be redefined if the modification is implemented with another tool (see Transform from BRepBuilderAPI for example). The BRepBuilderAPI package provides the following frameworks to perform modifications of this sort: - BRepBuilderAPI_Copy to produce the copy of a shape, - BRepBuilderAPI_Transform and BRepBuilderAPI_GTransform to apply a geometric transformation to a shape, - BRepBuilderAPI_NurbsConvert to convert the whole geometry of a shape into NURBS geometry, - BRepOffsetAPI_DraftAngle to build a tapered shape.");

// Constructors

// Fields

// Methods
// cls_BRepBuilderAPI_ModifyShape.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_ModifyShape::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_ModifyShape.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_ModifyShape::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_ModifyShape.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_ModifyShape::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_ModifyShape.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_ModifyShape::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_ModifyShape.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_ModifyShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_ModifyShape.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_ModifyShape::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_ModifyShape.def("Modified", (const TopTools_ListOfShape & (BRepBuilderAPI_ModifyShape::*)(const TopoDS_Shape &)) &BRepBuilderAPI_ModifyShape::Modified, "Returns the list of shapes modified from the shape <S>.", py::arg("S"));
cls_BRepBuilderAPI_ModifyShape.def("ModifiedShape", (TopoDS_Shape (BRepBuilderAPI_ModifyShape::*)(const TopoDS_Shape &) const) &BRepBuilderAPI_ModifyShape::ModifiedShape, "Returns the modified shape corresponding to <S>. S can correspond to the entire initial shape or to its subshape. Exceptions Standard_NoSuchObject if S is not the initial shape or a subshape of the initial shape to which the transformation has been applied. Raises NoSuchObject from Standard if S is not the initial shape or a sub-shape of the initial shape.", py::arg("S"));

// Enums

}