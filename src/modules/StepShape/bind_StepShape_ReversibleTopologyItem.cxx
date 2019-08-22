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
#include <StepData_SelectType.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <StepShape_Edge.hxx>
#include <StepShape_Path.hxx>
#include <StepShape_Face.hxx>
#include <StepShape_FaceBound.hxx>
#include <StepShape_ClosedShell.hxx>
#include <StepShape_OpenShell.hxx>
#include <StepShape_ReversibleTopologyItem.hxx>

void bind_StepShape_ReversibleTopologyItem(py::module &mod){

py::class_<StepShape_ReversibleTopologyItem, StepData_SelectType> cls_StepShape_ReversibleTopologyItem(mod, "StepShape_ReversibleTopologyItem", "None");

// Constructors
cls_StepShape_ReversibleTopologyItem.def(py::init<>());

// Fields

// Methods
// cls_StepShape_ReversibleTopologyItem.def_static("operator new_", (void * (*)(size_t)) &StepShape_ReversibleTopologyItem::operator new, "None", py::arg("theSize"));
// cls_StepShape_ReversibleTopologyItem.def_static("operator delete_", (void (*)(void *)) &StepShape_ReversibleTopologyItem::operator delete, "None", py::arg("theAddress"));
// cls_StepShape_ReversibleTopologyItem.def_static("operator new[]_", (void * (*)(size_t)) &StepShape_ReversibleTopologyItem::operator new[], "None", py::arg("theSize"));
// cls_StepShape_ReversibleTopologyItem.def_static("operator delete[]_", (void (*)(void *)) &StepShape_ReversibleTopologyItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepShape_ReversibleTopologyItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepShape_ReversibleTopologyItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepShape_ReversibleTopologyItem.def_static("operator delete_", (void (*)(void *, void *)) &StepShape_ReversibleTopologyItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepShape_ReversibleTopologyItem.def("CaseNum", (Standard_Integer (StepShape_ReversibleTopologyItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepShape_ReversibleTopologyItem::CaseNum, "Recognizes a ReversibleTopologyItem Kind Entity that is : 1 -> Edge 2 -> Path 3 -> Face 4 -> FaceBound 5 -> ClosedShell 6 -> OpenShell 0 else", py::arg("ent"));
cls_StepShape_ReversibleTopologyItem.def("Edge", (opencascade::handle<StepShape_Edge> (StepShape_ReversibleTopologyItem::*)() const) &StepShape_ReversibleTopologyItem::Edge, "returns Value as a Edge (Null if another type)");
cls_StepShape_ReversibleTopologyItem.def("Path", (opencascade::handle<StepShape_Path> (StepShape_ReversibleTopologyItem::*)() const) &StepShape_ReversibleTopologyItem::Path, "returns Value as a Path (Null if another type)");
cls_StepShape_ReversibleTopologyItem.def("Face", (opencascade::handle<StepShape_Face> (StepShape_ReversibleTopologyItem::*)() const) &StepShape_ReversibleTopologyItem::Face, "returns Value as a Face (Null if another type)");
cls_StepShape_ReversibleTopologyItem.def("FaceBound", (opencascade::handle<StepShape_FaceBound> (StepShape_ReversibleTopologyItem::*)() const) &StepShape_ReversibleTopologyItem::FaceBound, "returns Value as a FaceBound (Null if another type)");
cls_StepShape_ReversibleTopologyItem.def("ClosedShell", (opencascade::handle<StepShape_ClosedShell> (StepShape_ReversibleTopologyItem::*)() const) &StepShape_ReversibleTopologyItem::ClosedShell, "returns Value as a ClosedShell (Null if another type)");
cls_StepShape_ReversibleTopologyItem.def("OpenShell", (opencascade::handle<StepShape_OpenShell> (StepShape_ReversibleTopologyItem::*)() const) &StepShape_ReversibleTopologyItem::OpenShell, "returns Value as a OpenShell (Null if another type)");

// Enums

}