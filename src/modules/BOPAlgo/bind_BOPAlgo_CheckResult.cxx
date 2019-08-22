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
#include <TopTools_ListOfShape.hxx>
#include <BOPAlgo_CheckStatus.hxx>
#include <Standard_TypeDef.hxx>
#include <BOPAlgo_CheckResult.hxx>

void bind_BOPAlgo_CheckResult(py::module &mod){

py::class_<BOPAlgo_CheckResult> cls_BOPAlgo_CheckResult(mod, "BOPAlgo_CheckResult", "contains information about faulty shapes and faulty types can't be processed by Boolean Operations");

// Constructors
cls_BOPAlgo_CheckResult.def(py::init<>());

// Fields

// Methods
// cls_BOPAlgo_CheckResult.def_static("operator new_", (void * (*)(size_t)) &BOPAlgo_CheckResult::operator new, "None", py::arg("theSize"));
// cls_BOPAlgo_CheckResult.def_static("operator delete_", (void (*)(void *)) &BOPAlgo_CheckResult::operator delete, "None", py::arg("theAddress"));
// cls_BOPAlgo_CheckResult.def_static("operator new[]_", (void * (*)(size_t)) &BOPAlgo_CheckResult::operator new[], "None", py::arg("theSize"));
// cls_BOPAlgo_CheckResult.def_static("operator delete[]_", (void (*)(void *)) &BOPAlgo_CheckResult::operator delete[], "None", py::arg("theAddress"));
// cls_BOPAlgo_CheckResult.def_static("operator new_", (void * (*)(size_t, void *)) &BOPAlgo_CheckResult::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BOPAlgo_CheckResult.def_static("operator delete_", (void (*)(void *, void *)) &BOPAlgo_CheckResult::operator delete, "None", py::arg(""), py::arg(""));
cls_BOPAlgo_CheckResult.def("SetShape1", (void (BOPAlgo_CheckResult::*)(const TopoDS_Shape &)) &BOPAlgo_CheckResult::SetShape1, "sets ancestor shape (object) for faulty sub-shapes", py::arg("TheShape"));
cls_BOPAlgo_CheckResult.def("AddFaultyShape1", (void (BOPAlgo_CheckResult::*)(const TopoDS_Shape &)) &BOPAlgo_CheckResult::AddFaultyShape1, "adds faulty sub-shapes from object to a list", py::arg("TheShape"));
cls_BOPAlgo_CheckResult.def("SetShape2", (void (BOPAlgo_CheckResult::*)(const TopoDS_Shape &)) &BOPAlgo_CheckResult::SetShape2, "sets ancestor shape (tool) for faulty sub-shapes", py::arg("TheShape"));
cls_BOPAlgo_CheckResult.def("AddFaultyShape2", (void (BOPAlgo_CheckResult::*)(const TopoDS_Shape &)) &BOPAlgo_CheckResult::AddFaultyShape2, "adds faulty sub-shapes from tool to a list", py::arg("TheShape"));
cls_BOPAlgo_CheckResult.def("GetShape1", (const TopoDS_Shape & (BOPAlgo_CheckResult::*)() const) &BOPAlgo_CheckResult::GetShape1, "returns ancestor shape (object) for faulties");
cls_BOPAlgo_CheckResult.def("GetShape2", (const TopoDS_Shape & (BOPAlgo_CheckResult::*)() const) &BOPAlgo_CheckResult::GetShape2, "returns ancestor shape (tool) for faulties");
cls_BOPAlgo_CheckResult.def("GetFaultyShapes1", (const TopTools_ListOfShape & (BOPAlgo_CheckResult::*)() const) &BOPAlgo_CheckResult::GetFaultyShapes1, "returns list of faulty shapes for object");
cls_BOPAlgo_CheckResult.def("GetFaultyShapes2", (const TopTools_ListOfShape & (BOPAlgo_CheckResult::*)() const) &BOPAlgo_CheckResult::GetFaultyShapes2, "returns list of faulty shapes for tool");
cls_BOPAlgo_CheckResult.def("SetCheckStatus", (void (BOPAlgo_CheckResult::*)(const BOPAlgo_CheckStatus)) &BOPAlgo_CheckResult::SetCheckStatus, "set status of faulty", py::arg("TheStatus"));
cls_BOPAlgo_CheckResult.def("GetCheckStatus", (BOPAlgo_CheckStatus (BOPAlgo_CheckResult::*)() const) &BOPAlgo_CheckResult::GetCheckStatus, "gets status of faulty");
cls_BOPAlgo_CheckResult.def("SetMaxDistance1", (void (BOPAlgo_CheckResult::*)(const Standard_Real)) &BOPAlgo_CheckResult::SetMaxDistance1, "Sets max distance for the first shape", py::arg("theDist"));
cls_BOPAlgo_CheckResult.def("SetMaxDistance2", (void (BOPAlgo_CheckResult::*)(const Standard_Real)) &BOPAlgo_CheckResult::SetMaxDistance2, "Sets max distance for the second shape", py::arg("theDist"));
cls_BOPAlgo_CheckResult.def("SetMaxParameter1", (void (BOPAlgo_CheckResult::*)(const Standard_Real)) &BOPAlgo_CheckResult::SetMaxParameter1, "Sets the parameter for the first shape", py::arg("thePar"));
cls_BOPAlgo_CheckResult.def("SetMaxParameter2", (void (BOPAlgo_CheckResult::*)(const Standard_Real)) &BOPAlgo_CheckResult::SetMaxParameter2, "Sets the parameter for the second shape", py::arg("thePar"));
cls_BOPAlgo_CheckResult.def("GetMaxDistance1", (Standard_Real (BOPAlgo_CheckResult::*)() const) &BOPAlgo_CheckResult::GetMaxDistance1, "Returns the distance for the first shape");
cls_BOPAlgo_CheckResult.def("GetMaxDistance2", (Standard_Real (BOPAlgo_CheckResult::*)() const) &BOPAlgo_CheckResult::GetMaxDistance2, "Returns the distance for the second shape");
cls_BOPAlgo_CheckResult.def("GetMaxParameter1", (Standard_Real (BOPAlgo_CheckResult::*)() const) &BOPAlgo_CheckResult::GetMaxParameter1, "Returns the parameter for the fircst shape");
cls_BOPAlgo_CheckResult.def("GetMaxParameter2", (Standard_Real (BOPAlgo_CheckResult::*)() const) &BOPAlgo_CheckResult::GetMaxParameter2, "Returns the parameter for the second shape");

// Enums

}