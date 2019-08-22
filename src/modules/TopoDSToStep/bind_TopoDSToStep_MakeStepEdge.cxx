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
#include <TopoDSToStep_Root.hxx>
#include <Standard.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDSToStep_Tool.hxx>
#include <Standard_Handle.hxx>
#include <Transfer_FinderProcess.hxx>
#include <StepShape_TopologicalRepresentationItem.hxx>
#include <TopoDSToStep_MakeEdgeError.hxx>
#include <TopoDSToStep_MakeStepEdge.hxx>

void bind_TopoDSToStep_MakeStepEdge(py::module &mod){

py::class_<TopoDSToStep_MakeStepEdge, TopoDSToStep_Root> cls_TopoDSToStep_MakeStepEdge(mod, "TopoDSToStep_MakeStepEdge", "This class implements the mapping between classes Edge from TopoDS and TopologicalRepresentationItem from StepShape.");

// Constructors
cls_TopoDSToStep_MakeStepEdge.def(py::init<>());
cls_TopoDSToStep_MakeStepEdge.def(py::init<const TopoDS_Edge &, TopoDSToStep_Tool &, const opencascade::handle<Transfer_FinderProcess> &>(), py::arg("E"), py::arg("T"), py::arg("FP"));

// Fields

// Methods
// cls_TopoDSToStep_MakeStepEdge.def_static("operator new_", (void * (*)(size_t)) &TopoDSToStep_MakeStepEdge::operator new, "None", py::arg("theSize"));
// cls_TopoDSToStep_MakeStepEdge.def_static("operator delete_", (void (*)(void *)) &TopoDSToStep_MakeStepEdge::operator delete, "None", py::arg("theAddress"));
// cls_TopoDSToStep_MakeStepEdge.def_static("operator new[]_", (void * (*)(size_t)) &TopoDSToStep_MakeStepEdge::operator new[], "None", py::arg("theSize"));
// cls_TopoDSToStep_MakeStepEdge.def_static("operator delete[]_", (void (*)(void *)) &TopoDSToStep_MakeStepEdge::operator delete[], "None", py::arg("theAddress"));
// cls_TopoDSToStep_MakeStepEdge.def_static("operator new_", (void * (*)(size_t, void *)) &TopoDSToStep_MakeStepEdge::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopoDSToStep_MakeStepEdge.def_static("operator delete_", (void (*)(void *, void *)) &TopoDSToStep_MakeStepEdge::operator delete, "None", py::arg(""), py::arg(""));
cls_TopoDSToStep_MakeStepEdge.def("Init", (void (TopoDSToStep_MakeStepEdge::*)(const TopoDS_Edge &, TopoDSToStep_Tool &, const opencascade::handle<Transfer_FinderProcess> &)) &TopoDSToStep_MakeStepEdge::Init, "None", py::arg("E"), py::arg("T"), py::arg("FP"));
cls_TopoDSToStep_MakeStepEdge.def("Value", (const opencascade::handle<StepShape_TopologicalRepresentationItem> & (TopoDSToStep_MakeStepEdge::*)() const) &TopoDSToStep_MakeStepEdge::Value, "None");
cls_TopoDSToStep_MakeStepEdge.def("Error", (TopoDSToStep_MakeEdgeError (TopoDSToStep_MakeStepEdge::*)() const) &TopoDSToStep_MakeStepEdge::Error, "None");

// Enums

}