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
#include <TopoDS_Vertex.hxx>
#include <TopoDSToStep_Tool.hxx>
#include <Standard_Handle.hxx>
#include <Transfer_FinderProcess.hxx>
#include <StepShape_TopologicalRepresentationItem.hxx>
#include <TopoDSToStep_MakeVertexError.hxx>
#include <TopoDSToStep_MakeStepVertex.hxx>

void bind_TopoDSToStep_MakeStepVertex(py::module &mod){

py::class_<TopoDSToStep_MakeStepVertex, TopoDSToStep_Root> cls_TopoDSToStep_MakeStepVertex(mod, "TopoDSToStep_MakeStepVertex", "This class implements the mapping between classes Vertex from TopoDS and TopologicalRepresentationItem from StepShape.");

// Constructors
cls_TopoDSToStep_MakeStepVertex.def(py::init<>());
cls_TopoDSToStep_MakeStepVertex.def(py::init<const TopoDS_Vertex &, TopoDSToStep_Tool &, const opencascade::handle<Transfer_FinderProcess> &>(), py::arg("V"), py::arg("T"), py::arg("FP"));

// Fields

// Methods
// cls_TopoDSToStep_MakeStepVertex.def_static("operator new_", (void * (*)(size_t)) &TopoDSToStep_MakeStepVertex::operator new, "None", py::arg("theSize"));
// cls_TopoDSToStep_MakeStepVertex.def_static("operator delete_", (void (*)(void *)) &TopoDSToStep_MakeStepVertex::operator delete, "None", py::arg("theAddress"));
// cls_TopoDSToStep_MakeStepVertex.def_static("operator new[]_", (void * (*)(size_t)) &TopoDSToStep_MakeStepVertex::operator new[], "None", py::arg("theSize"));
// cls_TopoDSToStep_MakeStepVertex.def_static("operator delete[]_", (void (*)(void *)) &TopoDSToStep_MakeStepVertex::operator delete[], "None", py::arg("theAddress"));
// cls_TopoDSToStep_MakeStepVertex.def_static("operator new_", (void * (*)(size_t, void *)) &TopoDSToStep_MakeStepVertex::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopoDSToStep_MakeStepVertex.def_static("operator delete_", (void (*)(void *, void *)) &TopoDSToStep_MakeStepVertex::operator delete, "None", py::arg(""), py::arg(""));
cls_TopoDSToStep_MakeStepVertex.def("Init", (void (TopoDSToStep_MakeStepVertex::*)(const TopoDS_Vertex &, TopoDSToStep_Tool &, const opencascade::handle<Transfer_FinderProcess> &)) &TopoDSToStep_MakeStepVertex::Init, "None", py::arg("V"), py::arg("T"), py::arg("FP"));
cls_TopoDSToStep_MakeStepVertex.def("Value", (const opencascade::handle<StepShape_TopologicalRepresentationItem> & (TopoDSToStep_MakeStepVertex::*)() const) &TopoDSToStep_MakeStepVertex::Value, "None");
cls_TopoDSToStep_MakeStepVertex.def("Error", (TopoDSToStep_MakeVertexError (TopoDSToStep_MakeStepVertex::*)() const) &TopoDSToStep_MakeStepVertex::Error, "None");

// Enums

}