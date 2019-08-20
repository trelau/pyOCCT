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
#include <TopAbs_State.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepBuild_HBuilder.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_MapOfShape.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <BRepAlgo_BooleanOperation.hxx>

void bind_BRepAlgo_BooleanOperation(py::module &mod){

py::class_<BRepAlgo_BooleanOperation, std::unique_ptr<BRepAlgo_BooleanOperation>, BRepBuilderAPI_MakeShape> cls_BRepAlgo_BooleanOperation(mod, "BRepAlgo_BooleanOperation", "The abstract class BooleanOperation is the root class of Boolean operations. A BooleanOperation object stores the two shapes in preparation for the Boolean operation specified in one of the classes inheriting from this one. These include: - Common - Cut - Fuse - Section.");

// Constructors

// Fields

// Methods
// cls_BRepAlgo_BooleanOperation.def_static("operator new_", (void * (*)(size_t)) &BRepAlgo_BooleanOperation::operator new, "None", py::arg("theSize"));
// cls_BRepAlgo_BooleanOperation.def_static("operator delete_", (void (*)(void *)) &BRepAlgo_BooleanOperation::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgo_BooleanOperation.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgo_BooleanOperation::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgo_BooleanOperation.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgo_BooleanOperation::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgo_BooleanOperation.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgo_BooleanOperation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgo_BooleanOperation.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgo_BooleanOperation::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepAlgo_BooleanOperation.def("PerformDS", (void (BRepAlgo_BooleanOperation::*)()) &BRepAlgo_BooleanOperation::PerformDS, "None");
cls_BRepAlgo_BooleanOperation.def("Perform", (void (BRepAlgo_BooleanOperation::*)(const TopAbs_State, const TopAbs_State)) &BRepAlgo_BooleanOperation::Perform, "None", py::arg("St1"), py::arg("St2"));
cls_BRepAlgo_BooleanOperation.def("Builder", (opencascade::handle<TopOpeBRepBuild_HBuilder> (BRepAlgo_BooleanOperation::*)() const) &BRepAlgo_BooleanOperation::Builder, "None");
cls_BRepAlgo_BooleanOperation.def("Shape1", (const TopoDS_Shape & (BRepAlgo_BooleanOperation::*)() const) &BRepAlgo_BooleanOperation::Shape1, "Returns the first shape involved in this Boolean operation.");
cls_BRepAlgo_BooleanOperation.def("Shape2", (const TopoDS_Shape & (BRepAlgo_BooleanOperation::*)() const) &BRepAlgo_BooleanOperation::Shape2, "Returns the second shape involved in this Boolean operation.");
cls_BRepAlgo_BooleanOperation.def("Modified", (const TopTools_ListOfShape & (BRepAlgo_BooleanOperation::*)(const TopoDS_Shape &)) &BRepAlgo_BooleanOperation::Modified, "Returns the list of shapes modified from the shape <S>.", py::arg("S"));
cls_BRepAlgo_BooleanOperation.def("IsDeleted", (Standard_Boolean (BRepAlgo_BooleanOperation::*)(const TopoDS_Shape &)) &BRepAlgo_BooleanOperation::IsDeleted, "None", py::arg("S"));

// Enums

}