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
#include <TopAbs_Orientation.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_State.hxx>
#include <HLRAlgo_Intersection.hxx>

void bind_HLRAlgo_Intersection(py::module &mod){

py::class_<HLRAlgo_Intersection> cls_HLRAlgo_Intersection(mod, "HLRAlgo_Intersection", "Describes an intersection on an edge to hide. Contains a parameter and a state (ON = on the face, OUT = above the face, IN = under the Face)");

// Constructors
cls_HLRAlgo_Intersection.def(py::init<>());
cls_HLRAlgo_Intersection.def(py::init<const TopAbs_Orientation, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_ShortReal, const TopAbs_State>(), py::arg("Ori"), py::arg("Lev"), py::arg("SegInd"), py::arg("Ind"), py::arg("P"), py::arg("Tol"), py::arg("S"));

// Fields

// Methods
// cls_HLRAlgo_Intersection.def_static("operator new_", (void * (*)(size_t)) &HLRAlgo_Intersection::operator new, "None", py::arg("theSize"));
// cls_HLRAlgo_Intersection.def_static("operator delete_", (void (*)(void *)) &HLRAlgo_Intersection::operator delete, "None", py::arg("theAddress"));
// cls_HLRAlgo_Intersection.def_static("operator new[]_", (void * (*)(size_t)) &HLRAlgo_Intersection::operator new[], "None", py::arg("theSize"));
// cls_HLRAlgo_Intersection.def_static("operator delete[]_", (void (*)(void *)) &HLRAlgo_Intersection::operator delete[], "None", py::arg("theAddress"));
// cls_HLRAlgo_Intersection.def_static("operator new_", (void * (*)(size_t, void *)) &HLRAlgo_Intersection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRAlgo_Intersection.def_static("operator delete_", (void (*)(void *, void *)) &HLRAlgo_Intersection::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRAlgo_Intersection.def("Orientation", (void (HLRAlgo_Intersection::*)(const TopAbs_Orientation)) &HLRAlgo_Intersection::Orientation, "None", py::arg("Ori"));
cls_HLRAlgo_Intersection.def("Orientation", (TopAbs_Orientation (HLRAlgo_Intersection::*)() const) &HLRAlgo_Intersection::Orientation, "None");
cls_HLRAlgo_Intersection.def("Level", (void (HLRAlgo_Intersection::*)(const Standard_Integer)) &HLRAlgo_Intersection::Level, "None", py::arg("Lev"));
cls_HLRAlgo_Intersection.def("Level", (Standard_Integer (HLRAlgo_Intersection::*)() const) &HLRAlgo_Intersection::Level, "None");
cls_HLRAlgo_Intersection.def("SegIndex", (void (HLRAlgo_Intersection::*)(const Standard_Integer)) &HLRAlgo_Intersection::SegIndex, "None", py::arg("SegInd"));
cls_HLRAlgo_Intersection.def("SegIndex", (Standard_Integer (HLRAlgo_Intersection::*)() const) &HLRAlgo_Intersection::SegIndex, "None");
cls_HLRAlgo_Intersection.def("Index", (void (HLRAlgo_Intersection::*)(const Standard_Integer)) &HLRAlgo_Intersection::Index, "None", py::arg("Ind"));
cls_HLRAlgo_Intersection.def("Index", (Standard_Integer (HLRAlgo_Intersection::*)() const) &HLRAlgo_Intersection::Index, "None");
cls_HLRAlgo_Intersection.def("Parameter", (void (HLRAlgo_Intersection::*)(const Standard_Real)) &HLRAlgo_Intersection::Parameter, "None", py::arg("P"));
cls_HLRAlgo_Intersection.def("Parameter", (Standard_Real (HLRAlgo_Intersection::*)() const) &HLRAlgo_Intersection::Parameter, "None");
cls_HLRAlgo_Intersection.def("Tolerance", (void (HLRAlgo_Intersection::*)(const Standard_ShortReal)) &HLRAlgo_Intersection::Tolerance, "None", py::arg("T"));
cls_HLRAlgo_Intersection.def("Tolerance", (Standard_ShortReal (HLRAlgo_Intersection::*)() const) &HLRAlgo_Intersection::Tolerance, "None");
cls_HLRAlgo_Intersection.def("State", (void (HLRAlgo_Intersection::*)(const TopAbs_State)) &HLRAlgo_Intersection::State, "None", py::arg("S"));
cls_HLRAlgo_Intersection.def("State", (TopAbs_State (HLRAlgo_Intersection::*)() const) &HLRAlgo_Intersection::State, "None");

// Enums

}