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
#include <HLRBRep_EdgeInterferenceTool.hxx>
#include <HLRAlgo_InterferenceList.hxx>
#include <Standard_TypeDef.hxx>
#include <HLRAlgo_Intersection.hxx>
#include <TopAbs_Orientation.hxx>
#include <HLRBRep_VertexList.hxx>

void bind_HLRBRep_VertexList(py::module &mod){

py::class_<HLRBRep_VertexList, std::unique_ptr<HLRBRep_VertexList>> cls_HLRBRep_VertexList(mod, "HLRBRep_VertexList", "None");

// Constructors
cls_HLRBRep_VertexList.def(py::init<const HLRBRep_EdgeInterferenceTool &, const HLRAlgo_ListIteratorOfInterferenceList &>(), py::arg("T"), py::arg("I"));

// Fields

// Methods
// cls_HLRBRep_VertexList.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_VertexList::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_VertexList.def_static("operator delete_", (void (*)(void *)) &HLRBRep_VertexList::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_VertexList.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_VertexList::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_VertexList.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_VertexList::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_VertexList.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_VertexList::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_VertexList.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_VertexList::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_VertexList.def("IsPeriodic", (Standard_Boolean (HLRBRep_VertexList::*)() const) &HLRBRep_VertexList::IsPeriodic, "Returns True when the curve is periodic.");
cls_HLRBRep_VertexList.def("More", (Standard_Boolean (HLRBRep_VertexList::*)() const) &HLRBRep_VertexList::More, "Returns True when there are more vertices.");
cls_HLRBRep_VertexList.def("Next", (void (HLRBRep_VertexList::*)()) &HLRBRep_VertexList::Next, "Proceeds to the next vertex.");
cls_HLRBRep_VertexList.def("Current", (const HLRAlgo_Intersection & (HLRBRep_VertexList::*)() const) &HLRBRep_VertexList::Current, "Returns the current vertex");
cls_HLRBRep_VertexList.def("IsBoundary", (Standard_Boolean (HLRBRep_VertexList::*)() const) &HLRBRep_VertexList::IsBoundary, "Returns True if the current vertex is is on the boundary of the edge.");
cls_HLRBRep_VertexList.def("IsInterference", (Standard_Boolean (HLRBRep_VertexList::*)() const) &HLRBRep_VertexList::IsInterference, "Returns True if the current vertex is an interference.");
cls_HLRBRep_VertexList.def("Orientation", (TopAbs_Orientation (HLRBRep_VertexList::*)() const) &HLRBRep_VertexList::Orientation, "Returns the orientation of the current vertex if it is on the boundary of the edge.");
cls_HLRBRep_VertexList.def("Transition", (TopAbs_Orientation (HLRBRep_VertexList::*)() const) &HLRBRep_VertexList::Transition, "Returns the transition of the current vertex if it is an interference.");
cls_HLRBRep_VertexList.def("BoundaryTransition", (TopAbs_Orientation (HLRBRep_VertexList::*)() const) &HLRBRep_VertexList::BoundaryTransition, "Returns the transition of the current vertex relative to the boundary if it is an interference.");

// Enums

}