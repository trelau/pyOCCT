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
#include <Interface_Graph.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <StepShape_ConnectedFaceSet.hxx>
#include <StepGeom_CompositeCurve.hxx>
#include <TColStd_MapOfTransient.hxx>
#include <STEPSelections_Counter.hxx>

void bind_STEPSelections_Counter(py::module &mod){

py::class_<STEPSelections_Counter, std::unique_ptr<STEPSelections_Counter>> cls_STEPSelections_Counter(mod, "STEPSelections_Counter", "None");

// Constructors
cls_STEPSelections_Counter.def(py::init<>());

// Fields

// Methods
// cls_STEPSelections_Counter.def_static("operator new_", (void * (*)(size_t)) &STEPSelections_Counter::operator new, "None", py::arg("theSize"));
// cls_STEPSelections_Counter.def_static("operator delete_", (void (*)(void *)) &STEPSelections_Counter::operator delete, "None", py::arg("theAddress"));
// cls_STEPSelections_Counter.def_static("operator new[]_", (void * (*)(size_t)) &STEPSelections_Counter::operator new[], "None", py::arg("theSize"));
// cls_STEPSelections_Counter.def_static("operator delete[]_", (void (*)(void *)) &STEPSelections_Counter::operator delete[], "None", py::arg("theAddress"));
// cls_STEPSelections_Counter.def_static("operator new_", (void * (*)(size_t, void *)) &STEPSelections_Counter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPSelections_Counter.def_static("operator delete_", (void (*)(void *, void *)) &STEPSelections_Counter::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPSelections_Counter.def("Count", (void (STEPSelections_Counter::*)(const Interface_Graph &, const opencascade::handle<Standard_Transient> &)) &STEPSelections_Counter::Count, "None", py::arg("graph"), py::arg("start"));
cls_STEPSelections_Counter.def("Clear", (void (STEPSelections_Counter::*)()) &STEPSelections_Counter::Clear, "None");
cls_STEPSelections_Counter.def("NbInstancesOfFaces", (Standard_Integer (STEPSelections_Counter::*)() const) &STEPSelections_Counter::NbInstancesOfFaces, "None");
// cls_STEPSelections_Counter.def("POP", (Standard_Integer (STEPSelections_Counter::*)() const) &STEPSelections_Counter::POP, "None");
// cls_STEPSelections_Counter.def("POP2", (Standard_Integer (STEPSelections_Counter::*)() const) &STEPSelections_Counter::POP2, "None");
cls_STEPSelections_Counter.def("NbInstancesOfShells", (Standard_Integer (STEPSelections_Counter::*)() const) &STEPSelections_Counter::NbInstancesOfShells, "None");
cls_STEPSelections_Counter.def("NbInstancesOfSolids", (Standard_Integer (STEPSelections_Counter::*)() const) &STEPSelections_Counter::NbInstancesOfSolids, "None");
cls_STEPSelections_Counter.def("NbInstancesOfEdges", (Standard_Integer (STEPSelections_Counter::*)() const) &STEPSelections_Counter::NbInstancesOfEdges, "None");
cls_STEPSelections_Counter.def("NbInstancesOfWires", (Standard_Integer (STEPSelections_Counter::*)() const) &STEPSelections_Counter::NbInstancesOfWires, "None");
cls_STEPSelections_Counter.def("NbSourceFaces", (Standard_Integer (STEPSelections_Counter::*)() const) &STEPSelections_Counter::NbSourceFaces, "None");
cls_STEPSelections_Counter.def("NbSourceShells", (Standard_Integer (STEPSelections_Counter::*)() const) &STEPSelections_Counter::NbSourceShells, "None");
cls_STEPSelections_Counter.def("NbSourceSolids", (Standard_Integer (STEPSelections_Counter::*)() const) &STEPSelections_Counter::NbSourceSolids, "None");
cls_STEPSelections_Counter.def("NbSourceEdges", (Standard_Integer (STEPSelections_Counter::*)() const) &STEPSelections_Counter::NbSourceEdges, "None");
cls_STEPSelections_Counter.def("NbSourceWires", (Standard_Integer (STEPSelections_Counter::*)() const) &STEPSelections_Counter::NbSourceWires, "None");

// Enums

}