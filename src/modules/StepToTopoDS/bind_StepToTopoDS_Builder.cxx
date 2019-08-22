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
#include <StepToTopoDS_Root.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <StepShape_ManifoldSolidBrep.hxx>
#include <Transfer_TransientProcess.hxx>
#include <StepShape_BrepWithVoids.hxx>
#include <StepShape_FacetedBrep.hxx>
#include <StepShape_FacetedBrepAndBrepWithVoids.hxx>
#include <StepShape_ShellBasedSurfaceModel.hxx>
#include <StepToTopoDS_NMTool.hxx>
#include <StepShape_GeometricSet.hxx>
#include <StepShape_EdgeBasedWireframeModel.hxx>
#include <StepShape_FaceBasedSurfaceModel.hxx>
#include <Transfer_ActorOfTransientProcess.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <StepToTopoDS_BuilderError.hxx>
#include <StepToTopoDS_Builder.hxx>

void bind_StepToTopoDS_Builder(py::module &mod){

py::class_<StepToTopoDS_Builder, StepToTopoDS_Root> cls_StepToTopoDS_Builder(mod, "StepToTopoDS_Builder", "None");

// Constructors
cls_StepToTopoDS_Builder.def(py::init<>());
cls_StepToTopoDS_Builder.def(py::init<const opencascade::handle<StepShape_ManifoldSolidBrep> &, const opencascade::handle<Transfer_TransientProcess> &>(), py::arg("S"), py::arg("TP"));
cls_StepToTopoDS_Builder.def(py::init<const opencascade::handle<StepShape_BrepWithVoids> &, const opencascade::handle<Transfer_TransientProcess> &>(), py::arg("S"), py::arg("TP"));
cls_StepToTopoDS_Builder.def(py::init<const opencascade::handle<StepShape_FacetedBrep> &, const opencascade::handle<Transfer_TransientProcess> &>(), py::arg("S"), py::arg("TP"));
cls_StepToTopoDS_Builder.def(py::init<const opencascade::handle<StepShape_FacetedBrepAndBrepWithVoids> &, const opencascade::handle<Transfer_TransientProcess> &>(), py::arg("S"), py::arg("TP"));
cls_StepToTopoDS_Builder.def(py::init<const opencascade::handle<StepShape_ShellBasedSurfaceModel> &, const opencascade::handle<Transfer_TransientProcess> &, StepToTopoDS_NMTool &>(), py::arg("S"), py::arg("TP"), py::arg("NMTool"));
// cls_StepToTopoDS_Builder.def(py::init<const opencascade::handle<StepShape_GeometricSet> &, const opencascade::handle<Transfer_TransientProcess> &>(), py::arg("S"), py::arg("TP"));

// Fields

// Methods
// cls_StepToTopoDS_Builder.def_static("operator new_", (void * (*)(size_t)) &StepToTopoDS_Builder::operator new, "None", py::arg("theSize"));
// cls_StepToTopoDS_Builder.def_static("operator delete_", (void (*)(void *)) &StepToTopoDS_Builder::operator delete, "None", py::arg("theAddress"));
// cls_StepToTopoDS_Builder.def_static("operator new[]_", (void * (*)(size_t)) &StepToTopoDS_Builder::operator new[], "None", py::arg("theSize"));
// cls_StepToTopoDS_Builder.def_static("operator delete[]_", (void (*)(void *)) &StepToTopoDS_Builder::operator delete[], "None", py::arg("theAddress"));
// cls_StepToTopoDS_Builder.def_static("operator new_", (void * (*)(size_t, void *)) &StepToTopoDS_Builder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepToTopoDS_Builder.def_static("operator delete_", (void (*)(void *, void *)) &StepToTopoDS_Builder::operator delete, "None", py::arg(""), py::arg(""));
cls_StepToTopoDS_Builder.def("Init", (void (StepToTopoDS_Builder::*)(const opencascade::handle<StepShape_ManifoldSolidBrep> &, const opencascade::handle<Transfer_TransientProcess> &)) &StepToTopoDS_Builder::Init, "None", py::arg("S"), py::arg("TP"));
cls_StepToTopoDS_Builder.def("Init", (void (StepToTopoDS_Builder::*)(const opencascade::handle<StepShape_BrepWithVoids> &, const opencascade::handle<Transfer_TransientProcess> &)) &StepToTopoDS_Builder::Init, "None", py::arg("S"), py::arg("TP"));
cls_StepToTopoDS_Builder.def("Init", (void (StepToTopoDS_Builder::*)(const opencascade::handle<StepShape_FacetedBrep> &, const opencascade::handle<Transfer_TransientProcess> &)) &StepToTopoDS_Builder::Init, "None", py::arg("S"), py::arg("TP"));
cls_StepToTopoDS_Builder.def("Init", (void (StepToTopoDS_Builder::*)(const opencascade::handle<StepShape_FacetedBrepAndBrepWithVoids> &, const opencascade::handle<Transfer_TransientProcess> &)) &StepToTopoDS_Builder::Init, "None", py::arg("S"), py::arg("TP"));
cls_StepToTopoDS_Builder.def("Init", (void (StepToTopoDS_Builder::*)(const opencascade::handle<StepShape_ShellBasedSurfaceModel> &, const opencascade::handle<Transfer_TransientProcess> &, StepToTopoDS_NMTool &)) &StepToTopoDS_Builder::Init, "None", py::arg("S"), py::arg("TP"), py::arg("NMTool"));
cls_StepToTopoDS_Builder.def("Init", (void (StepToTopoDS_Builder::*)(const opencascade::handle<StepShape_EdgeBasedWireframeModel> &, const opencascade::handle<Transfer_TransientProcess> &)) &StepToTopoDS_Builder::Init, "None", py::arg("S"), py::arg("TP"));
cls_StepToTopoDS_Builder.def("Init", (void (StepToTopoDS_Builder::*)(const opencascade::handle<StepShape_FaceBasedSurfaceModel> &, const opencascade::handle<Transfer_TransientProcess> &)) &StepToTopoDS_Builder::Init, "None", py::arg("S"), py::arg("TP"));
cls_StepToTopoDS_Builder.def("Init", [](StepToTopoDS_Builder &self, const opencascade::handle<StepShape_GeometricSet> & a0, const opencascade::handle<Transfer_TransientProcess> & a1) -> void { return self.Init(a0, a1); });
cls_StepToTopoDS_Builder.def("Init", [](StepToTopoDS_Builder &self, const opencascade::handle<StepShape_GeometricSet> & a0, const opencascade::handle<Transfer_TransientProcess> & a1, const opencascade::handle<Transfer_ActorOfTransientProcess> & a2) -> void { return self.Init(a0, a1, a2); });
cls_StepToTopoDS_Builder.def("Init", (void (StepToTopoDS_Builder::*)(const opencascade::handle<StepShape_GeometricSet> &, const opencascade::handle<Transfer_TransientProcess> &, const opencascade::handle<Transfer_ActorOfTransientProcess> &, const Standard_Boolean)) &StepToTopoDS_Builder::Init, "None", py::arg("S"), py::arg("TP"), py::arg("RA"), py::arg("isManifold"));
cls_StepToTopoDS_Builder.def("Value", (const TopoDS_Shape & (StepToTopoDS_Builder::*)() const) &StepToTopoDS_Builder::Value, "None");
cls_StepToTopoDS_Builder.def("Error", (StepToTopoDS_BuilderError (StepToTopoDS_Builder::*)() const) &StepToTopoDS_Builder::Error, "None");

// Enums

}