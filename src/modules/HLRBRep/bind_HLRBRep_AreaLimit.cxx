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
#include <Standard_Transient.hxx>
#include <HLRAlgo_Intersection.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_State.hxx>
#include <Standard_Handle.hxx>
#include <HLRBRep_AreaLimit.hxx>
#include <Standard_Type.hxx>

void bind_HLRBRep_AreaLimit(py::module &mod){

py::class_<HLRBRep_AreaLimit, opencascade::handle<HLRBRep_AreaLimit>, Standard_Transient> cls_HLRBRep_AreaLimit(mod, "HLRBRep_AreaLimit", "The private nested class AreaLimit represents a -- vertex on the Edge with the state on the left and -- the right.");

// Constructors
cls_HLRBRep_AreaLimit.def(py::init<const HLRAlgo_Intersection &, const Standard_Boolean, const Standard_Boolean, const TopAbs_State, const TopAbs_State, const TopAbs_State, const TopAbs_State>(), py::arg("V"), py::arg("Boundary"), py::arg("Interference"), py::arg("StateBefore"), py::arg("StateAfter"), py::arg("EdgeBefore"), py::arg("EdgeAfter"));

// Fields

// Methods
cls_HLRBRep_AreaLimit.def("StateBefore", (void (HLRBRep_AreaLimit::*)(const TopAbs_State)) &HLRBRep_AreaLimit::StateBefore, "None", py::arg("St"));
cls_HLRBRep_AreaLimit.def("StateAfter", (void (HLRBRep_AreaLimit::*)(const TopAbs_State)) &HLRBRep_AreaLimit::StateAfter, "None", py::arg("St"));
cls_HLRBRep_AreaLimit.def("EdgeBefore", (void (HLRBRep_AreaLimit::*)(const TopAbs_State)) &HLRBRep_AreaLimit::EdgeBefore, "None", py::arg("St"));
cls_HLRBRep_AreaLimit.def("EdgeAfter", (void (HLRBRep_AreaLimit::*)(const TopAbs_State)) &HLRBRep_AreaLimit::EdgeAfter, "None", py::arg("St"));
cls_HLRBRep_AreaLimit.def("Previous", (void (HLRBRep_AreaLimit::*)(const opencascade::handle<HLRBRep_AreaLimit> &)) &HLRBRep_AreaLimit::Previous, "None", py::arg("P"));
cls_HLRBRep_AreaLimit.def("Next", (void (HLRBRep_AreaLimit::*)(const opencascade::handle<HLRBRep_AreaLimit> &)) &HLRBRep_AreaLimit::Next, "None", py::arg("N"));
cls_HLRBRep_AreaLimit.def("Vertex", (const HLRAlgo_Intersection & (HLRBRep_AreaLimit::*)() const) &HLRBRep_AreaLimit::Vertex, "None");
cls_HLRBRep_AreaLimit.def("IsBoundary", (Standard_Boolean (HLRBRep_AreaLimit::*)() const) &HLRBRep_AreaLimit::IsBoundary, "None");
cls_HLRBRep_AreaLimit.def("IsInterference", (Standard_Boolean (HLRBRep_AreaLimit::*)() const) &HLRBRep_AreaLimit::IsInterference, "None");
cls_HLRBRep_AreaLimit.def("StateBefore", (TopAbs_State (HLRBRep_AreaLimit::*)() const) &HLRBRep_AreaLimit::StateBefore, "None");
cls_HLRBRep_AreaLimit.def("StateAfter", (TopAbs_State (HLRBRep_AreaLimit::*)() const) &HLRBRep_AreaLimit::StateAfter, "None");
cls_HLRBRep_AreaLimit.def("EdgeBefore", (TopAbs_State (HLRBRep_AreaLimit::*)() const) &HLRBRep_AreaLimit::EdgeBefore, "None");
cls_HLRBRep_AreaLimit.def("EdgeAfter", (TopAbs_State (HLRBRep_AreaLimit::*)() const) &HLRBRep_AreaLimit::EdgeAfter, "None");
cls_HLRBRep_AreaLimit.def("Previous", (opencascade::handle<HLRBRep_AreaLimit> (HLRBRep_AreaLimit::*)() const) &HLRBRep_AreaLimit::Previous, "None");
cls_HLRBRep_AreaLimit.def("Next", (opencascade::handle<HLRBRep_AreaLimit> (HLRBRep_AreaLimit::*)() const) &HLRBRep_AreaLimit::Next, "None");
cls_HLRBRep_AreaLimit.def("Clear", (void (HLRBRep_AreaLimit::*)()) &HLRBRep_AreaLimit::Clear, "None");
cls_HLRBRep_AreaLimit.def_static("get_type_name_", (const char * (*)()) &HLRBRep_AreaLimit::get_type_name, "None");
cls_HLRBRep_AreaLimit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRBRep_AreaLimit::get_type_descriptor, "None");
cls_HLRBRep_AreaLimit.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRBRep_AreaLimit::*)() const) &HLRBRep_AreaLimit::DynamicType, "None");

// Enums

}