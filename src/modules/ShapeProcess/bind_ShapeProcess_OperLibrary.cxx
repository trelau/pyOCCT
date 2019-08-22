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
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <ShapeProcess_ShapeContext.hxx>
#include <BRepTools_Modification.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <ShapeExtend_MsgRegistrator.hxx>
#include <Standard_TypeDef.hxx>
#include <ShapeProcess_OperLibrary.hxx>

void bind_ShapeProcess_OperLibrary(py::module &mod){

py::class_<ShapeProcess_OperLibrary> cls_ShapeProcess_OperLibrary(mod, "ShapeProcess_OperLibrary", "Provides a set of following operators");

// Constructors

// Fields

// Methods
// cls_ShapeProcess_OperLibrary.def_static("operator new_", (void * (*)(size_t)) &ShapeProcess_OperLibrary::operator new, "None", py::arg("theSize"));
// cls_ShapeProcess_OperLibrary.def_static("operator delete_", (void (*)(void *)) &ShapeProcess_OperLibrary::operator delete, "None", py::arg("theAddress"));
// cls_ShapeProcess_OperLibrary.def_static("operator new[]_", (void * (*)(size_t)) &ShapeProcess_OperLibrary::operator new[], "None", py::arg("theSize"));
// cls_ShapeProcess_OperLibrary.def_static("operator delete[]_", (void (*)(void *)) &ShapeProcess_OperLibrary::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeProcess_OperLibrary.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeProcess_OperLibrary::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeProcess_OperLibrary.def_static("operator delete_", (void (*)(void *, void *)) &ShapeProcess_OperLibrary::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeProcess_OperLibrary.def_static("Init_", (void (*)()) &ShapeProcess_OperLibrary::Init, "Registers all the operators");
cls_ShapeProcess_OperLibrary.def_static("ApplyModifier_", [](const TopoDS_Shape & a0, const opencascade::handle<ShapeProcess_ShapeContext> & a1, const opencascade::handle<BRepTools_Modification> & a2, TopTools_DataMapOfShapeShape & a3) -> TopoDS_Shape { return ShapeProcess_OperLibrary::ApplyModifier(a0, a1, a2, a3); });
cls_ShapeProcess_OperLibrary.def_static("ApplyModifier_", [](const TopoDS_Shape & a0, const opencascade::handle<ShapeProcess_ShapeContext> & a1, const opencascade::handle<BRepTools_Modification> & a2, TopTools_DataMapOfShapeShape & a3, const opencascade::handle<ShapeExtend_MsgRegistrator> & a4) -> TopoDS_Shape { return ShapeProcess_OperLibrary::ApplyModifier(a0, a1, a2, a3, a4); });
cls_ShapeProcess_OperLibrary.def_static("ApplyModifier_", (TopoDS_Shape (*)(const TopoDS_Shape &, const opencascade::handle<ShapeProcess_ShapeContext> &, const opencascade::handle<BRepTools_Modification> &, TopTools_DataMapOfShapeShape &, const opencascade::handle<ShapeExtend_MsgRegistrator> &, Standard_Boolean)) &ShapeProcess_OperLibrary::ApplyModifier, "Applies BRepTools_Modification to a shape, taking into account sharing of components of compounds. if theMutableInput vat is set to true then imput shape S can be modified during the modification process.", py::arg("S"), py::arg("context"), py::arg("M"), py::arg("map"), py::arg("msg"), py::arg("theMutableInput"));

// Enums

}