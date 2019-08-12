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
#include <Standard_TypeDef.hxx>
#include <gp_XY.hxx>
#include <gp_XYZ.hxx>
#include <Plate_D1.hxx>
#include <Plate_D2.hxx>
#include <Plate_D3.hxx>
#include <Standard_Handle.hxx>
#include <NLPlate_HGPPConstraint.hxx>
#include <Standard_Type.hxx>

void bind_NLPlate_HGPPConstraint(py::module &mod){

py::class_<NLPlate_HGPPConstraint, opencascade::handle<NLPlate_HGPPConstraint>, Standard_Transient> cls_NLPlate_HGPPConstraint(mod, "NLPlate_HGPPConstraint", "define a PinPoint geometric Constraint used to load a Non Linear Plate");

// Fields

// Methods
cls_NLPlate_HGPPConstraint.def("SetUVFreeSliding", (void (NLPlate_HGPPConstraint::*)(const Standard_Boolean)) &NLPlate_HGPPConstraint::SetUVFreeSliding, "None", py::arg("UVFree"));
cls_NLPlate_HGPPConstraint.def("SetIncrementalLoadAllowed", (void (NLPlate_HGPPConstraint::*)(const Standard_Boolean)) &NLPlate_HGPPConstraint::SetIncrementalLoadAllowed, "None", py::arg("ILA"));
cls_NLPlate_HGPPConstraint.def("SetActiveOrder", (void (NLPlate_HGPPConstraint::*)(const Standard_Integer)) &NLPlate_HGPPConstraint::SetActiveOrder, "None", py::arg("ActiveOrder"));
cls_NLPlate_HGPPConstraint.def("SetUV", (void (NLPlate_HGPPConstraint::*)(const gp_XY &)) &NLPlate_HGPPConstraint::SetUV, "None", py::arg("UV"));
cls_NLPlate_HGPPConstraint.def("SetOrientation", [](NLPlate_HGPPConstraint &self) -> void { return self.SetOrientation(); });
cls_NLPlate_HGPPConstraint.def("SetOrientation", (void (NLPlate_HGPPConstraint::*)(const Standard_Integer)) &NLPlate_HGPPConstraint::SetOrientation, "None", py::arg("Orient"));
cls_NLPlate_HGPPConstraint.def("SetG0Criterion", (void (NLPlate_HGPPConstraint::*)(const Standard_Real)) &NLPlate_HGPPConstraint::SetG0Criterion, "None", py::arg("TolDist"));
cls_NLPlate_HGPPConstraint.def("SetG1Criterion", (void (NLPlate_HGPPConstraint::*)(const Standard_Real)) &NLPlate_HGPPConstraint::SetG1Criterion, "None", py::arg("TolAng"));
cls_NLPlate_HGPPConstraint.def("SetG2Criterion", (void (NLPlate_HGPPConstraint::*)(const Standard_Real)) &NLPlate_HGPPConstraint::SetG2Criterion, "None", py::arg("TolCurv"));
cls_NLPlate_HGPPConstraint.def("SetG3Criterion", (void (NLPlate_HGPPConstraint::*)(const Standard_Real)) &NLPlate_HGPPConstraint::SetG3Criterion, "None", py::arg("TolG3"));
cls_NLPlate_HGPPConstraint.def("UVFreeSliding", (Standard_Boolean (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::UVFreeSliding, "None");
cls_NLPlate_HGPPConstraint.def("IncrementalLoadAllowed", (Standard_Boolean (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::IncrementalLoadAllowed, "None");
cls_NLPlate_HGPPConstraint.def("ActiveOrder", (Standard_Integer (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::ActiveOrder, "None");
cls_NLPlate_HGPPConstraint.def("UV", (const gp_XY & (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::UV, "None");
cls_NLPlate_HGPPConstraint.def("Orientation", (Standard_Integer (NLPlate_HGPPConstraint::*)()) &NLPlate_HGPPConstraint::Orientation, "None");
cls_NLPlate_HGPPConstraint.def("IsG0", (Standard_Boolean (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::IsG0, "None");
cls_NLPlate_HGPPConstraint.def("G0Target", (const gp_XYZ & (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::G0Target, "None");
cls_NLPlate_HGPPConstraint.def("G1Target", (const Plate_D1 & (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::G1Target, "None");
cls_NLPlate_HGPPConstraint.def("G2Target", (const Plate_D2 & (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::G2Target, "None");
cls_NLPlate_HGPPConstraint.def("G3Target", (const Plate_D3 & (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::G3Target, "None");
cls_NLPlate_HGPPConstraint.def("G0Criterion", (Standard_Real (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::G0Criterion, "None");
cls_NLPlate_HGPPConstraint.def("G1Criterion", (Standard_Real (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::G1Criterion, "None");
cls_NLPlate_HGPPConstraint.def("G2Criterion", (Standard_Real (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::G2Criterion, "None");
cls_NLPlate_HGPPConstraint.def("G3Criterion", (Standard_Real (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::G3Criterion, "None");
cls_NLPlate_HGPPConstraint.def_static("get_type_name_", (const char * (*)()) &NLPlate_HGPPConstraint::get_type_name, "None");
cls_NLPlate_HGPPConstraint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &NLPlate_HGPPConstraint::get_type_descriptor, "None");
cls_NLPlate_HGPPConstraint.def("DynamicType", (const opencascade::handle<Standard_Type> & (NLPlate_HGPPConstraint::*)() const) &NLPlate_HGPPConstraint::DynamicType, "None");

// Enums

}