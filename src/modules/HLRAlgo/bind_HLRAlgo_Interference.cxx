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
#include <HLRAlgo_Intersection.hxx>
#include <HLRAlgo_Coincidence.hxx>
#include <TopAbs_Orientation.hxx>
#include <HLRAlgo_Interference.hxx>

void bind_HLRAlgo_Interference(py::module &mod){

py::class_<HLRAlgo_Interference> cls_HLRAlgo_Interference(mod, "HLRAlgo_Interference", "None");

// Constructors
cls_HLRAlgo_Interference.def(py::init<>());
cls_HLRAlgo_Interference.def(py::init<const HLRAlgo_Intersection &, const HLRAlgo_Coincidence &, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation>(), py::arg("Inters"), py::arg("Bound"), py::arg("Orient"), py::arg("Trans"), py::arg("BTrans"));

// Fields

// Methods
// cls_HLRAlgo_Interference.def_static("operator new_", (void * (*)(size_t)) &HLRAlgo_Interference::operator new, "None", py::arg("theSize"));
// cls_HLRAlgo_Interference.def_static("operator delete_", (void (*)(void *)) &HLRAlgo_Interference::operator delete, "None", py::arg("theAddress"));
// cls_HLRAlgo_Interference.def_static("operator new[]_", (void * (*)(size_t)) &HLRAlgo_Interference::operator new[], "None", py::arg("theSize"));
// cls_HLRAlgo_Interference.def_static("operator delete[]_", (void (*)(void *)) &HLRAlgo_Interference::operator delete[], "None", py::arg("theAddress"));
// cls_HLRAlgo_Interference.def_static("operator new_", (void * (*)(size_t, void *)) &HLRAlgo_Interference::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRAlgo_Interference.def_static("operator delete_", (void (*)(void *, void *)) &HLRAlgo_Interference::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRAlgo_Interference.def("Intersection", (void (HLRAlgo_Interference::*)(const HLRAlgo_Intersection &)) &HLRAlgo_Interference::Intersection, "None", py::arg("I"));
cls_HLRAlgo_Interference.def("Boundary", (void (HLRAlgo_Interference::*)(const HLRAlgo_Coincidence &)) &HLRAlgo_Interference::Boundary, "None", py::arg("B"));
cls_HLRAlgo_Interference.def("Orientation", (void (HLRAlgo_Interference::*)(const TopAbs_Orientation)) &HLRAlgo_Interference::Orientation, "None", py::arg("O"));
cls_HLRAlgo_Interference.def("Transition", (void (HLRAlgo_Interference::*)(const TopAbs_Orientation)) &HLRAlgo_Interference::Transition, "None", py::arg("Tr"));
cls_HLRAlgo_Interference.def("BoundaryTransition", (void (HLRAlgo_Interference::*)(const TopAbs_Orientation)) &HLRAlgo_Interference::BoundaryTransition, "None", py::arg("BTr"));
cls_HLRAlgo_Interference.def("Intersection", (const HLRAlgo_Intersection & (HLRAlgo_Interference::*)() const) &HLRAlgo_Interference::Intersection, "None");
cls_HLRAlgo_Interference.def("ChangeIntersection", (HLRAlgo_Intersection & (HLRAlgo_Interference::*)()) &HLRAlgo_Interference::ChangeIntersection, "None");
cls_HLRAlgo_Interference.def("Boundary", (const HLRAlgo_Coincidence & (HLRAlgo_Interference::*)() const) &HLRAlgo_Interference::Boundary, "None");
cls_HLRAlgo_Interference.def("ChangeBoundary", (HLRAlgo_Coincidence & (HLRAlgo_Interference::*)()) &HLRAlgo_Interference::ChangeBoundary, "None");
cls_HLRAlgo_Interference.def("Orientation", (TopAbs_Orientation (HLRAlgo_Interference::*)() const) &HLRAlgo_Interference::Orientation, "None");
cls_HLRAlgo_Interference.def("Transition", (TopAbs_Orientation (HLRAlgo_Interference::*)() const) &HLRAlgo_Interference::Transition, "None");
cls_HLRAlgo_Interference.def("BoundaryTransition", (TopAbs_Orientation (HLRAlgo_Interference::*)() const) &HLRAlgo_Interference::BoundaryTransition, "None");

// Enums

}