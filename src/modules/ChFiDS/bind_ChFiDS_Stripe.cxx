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
#include <Standard_Handle.hxx>
#include <ChFiDS_HData.hxx>
#include <ChFiDS_Spine.hxx>
#include <TopAbs_Orientation.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom2d_Curve.hxx>
#include <ChFiDS_Stripe.hxx>
#include <Standard_Type.hxx>

void bind_ChFiDS_Stripe(py::module &mod){

py::class_<ChFiDS_Stripe, opencascade::handle<ChFiDS_Stripe>, Standard_Transient> cls_ChFiDS_Stripe(mod, "ChFiDS_Stripe", "Data characterising a band of fillet.");

// Constructors
cls_ChFiDS_Stripe.def(py::init<>());

// Fields

// Methods
cls_ChFiDS_Stripe.def("Reset", (void (ChFiDS_Stripe::*)()) &ChFiDS_Stripe::Reset, "Reset everything except Spine.");
cls_ChFiDS_Stripe.def("SetOfSurfData", (const opencascade::handle<ChFiDS_HData> & (ChFiDS_Stripe::*)() const) &ChFiDS_Stripe::SetOfSurfData, "None");
cls_ChFiDS_Stripe.def("Spine", (const opencascade::handle<ChFiDS_Spine> & (ChFiDS_Stripe::*)() const) &ChFiDS_Stripe::Spine, "None");
cls_ChFiDS_Stripe.def("OrientationOnFace1", (TopAbs_Orientation (ChFiDS_Stripe::*)() const) &ChFiDS_Stripe::OrientationOnFace1, "None");
cls_ChFiDS_Stripe.def("OrientationOnFace2", (TopAbs_Orientation (ChFiDS_Stripe::*)() const) &ChFiDS_Stripe::OrientationOnFace2, "None");
cls_ChFiDS_Stripe.def("Choix", (Standard_Integer (ChFiDS_Stripe::*)() const) &ChFiDS_Stripe::Choix, "None");
cls_ChFiDS_Stripe.def("ChangeSetOfSurfData", (opencascade::handle<ChFiDS_HData> & (ChFiDS_Stripe::*)()) &ChFiDS_Stripe::ChangeSetOfSurfData, "None");
cls_ChFiDS_Stripe.def("ChangeSpine", (opencascade::handle<ChFiDS_Spine> & (ChFiDS_Stripe::*)()) &ChFiDS_Stripe::ChangeSpine, "None");
cls_ChFiDS_Stripe.def("OrientationOnFace1", (void (ChFiDS_Stripe::*)(const TopAbs_Orientation)) &ChFiDS_Stripe::OrientationOnFace1, "None", py::arg("Or1"));
cls_ChFiDS_Stripe.def("OrientationOnFace2", (void (ChFiDS_Stripe::*)(const TopAbs_Orientation)) &ChFiDS_Stripe::OrientationOnFace2, "None", py::arg("Or2"));
cls_ChFiDS_Stripe.def("Choix", (void (ChFiDS_Stripe::*)(const Standard_Integer)) &ChFiDS_Stripe::Choix, "None", py::arg("C"));
cls_ChFiDS_Stripe.def("FirstParameters", [](ChFiDS_Stripe &self, Standard_Real & Pdeb, Standard_Real & Pfin){ self.FirstParameters(Pdeb, Pfin); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "None", py::arg("Pdeb"), py::arg("Pfin"));
cls_ChFiDS_Stripe.def("LastParameters", [](ChFiDS_Stripe &self, Standard_Real & Pdeb, Standard_Real & Pfin){ self.LastParameters(Pdeb, Pfin); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "None", py::arg("Pdeb"), py::arg("Pfin"));
cls_ChFiDS_Stripe.def("ChangeFirstParameters", (void (ChFiDS_Stripe::*)(const Standard_Real, const Standard_Real)) &ChFiDS_Stripe::ChangeFirstParameters, "None", py::arg("Pdeb"), py::arg("Pfin"));
cls_ChFiDS_Stripe.def("ChangeLastParameters", (void (ChFiDS_Stripe::*)(const Standard_Real, const Standard_Real)) &ChFiDS_Stripe::ChangeLastParameters, "None", py::arg("Pdeb"), py::arg("Pfin"));
cls_ChFiDS_Stripe.def("FirstCurve", (Standard_Integer (ChFiDS_Stripe::*)() const) &ChFiDS_Stripe::FirstCurve, "None");
cls_ChFiDS_Stripe.def("LastCurve", (Standard_Integer (ChFiDS_Stripe::*)() const) &ChFiDS_Stripe::LastCurve, "None");
cls_ChFiDS_Stripe.def("ChangeFirstCurve", (void (ChFiDS_Stripe::*)(const Standard_Integer)) &ChFiDS_Stripe::ChangeFirstCurve, "None", py::arg("Index"));
cls_ChFiDS_Stripe.def("ChangeLastCurve", (void (ChFiDS_Stripe::*)(const Standard_Integer)) &ChFiDS_Stripe::ChangeLastCurve, "None", py::arg("Index"));
cls_ChFiDS_Stripe.def("FirstPCurve", (const opencascade::handle<Geom2d_Curve> & (ChFiDS_Stripe::*)() const) &ChFiDS_Stripe::FirstPCurve, "None");
cls_ChFiDS_Stripe.def("LastPCurve", (const opencascade::handle<Geom2d_Curve> & (ChFiDS_Stripe::*)() const) &ChFiDS_Stripe::LastPCurve, "None");
cls_ChFiDS_Stripe.def("ChangeFirstPCurve", (opencascade::handle<Geom2d_Curve> & (ChFiDS_Stripe::*)()) &ChFiDS_Stripe::ChangeFirstPCurve, "None");
cls_ChFiDS_Stripe.def("ChangeLastPCurve", (opencascade::handle<Geom2d_Curve> & (ChFiDS_Stripe::*)()) &ChFiDS_Stripe::ChangeLastPCurve, "None");
cls_ChFiDS_Stripe.def("FirstPCurveOrientation", (TopAbs_Orientation (ChFiDS_Stripe::*)() const) &ChFiDS_Stripe::FirstPCurveOrientation, "None");
cls_ChFiDS_Stripe.def("LastPCurveOrientation", (TopAbs_Orientation (ChFiDS_Stripe::*)() const) &ChFiDS_Stripe::LastPCurveOrientation, "None");
cls_ChFiDS_Stripe.def("FirstPCurveOrientation", (void (ChFiDS_Stripe::*)(const TopAbs_Orientation)) &ChFiDS_Stripe::FirstPCurveOrientation, "None", py::arg("O"));
cls_ChFiDS_Stripe.def("LastPCurveOrientation", (void (ChFiDS_Stripe::*)(const TopAbs_Orientation)) &ChFiDS_Stripe::LastPCurveOrientation, "None", py::arg("O"));
cls_ChFiDS_Stripe.def("IndexFirstPointOnS1", (Standard_Integer (ChFiDS_Stripe::*)() const) &ChFiDS_Stripe::IndexFirstPointOnS1, "None");
cls_ChFiDS_Stripe.def("IndexFirstPointOnS2", (Standard_Integer (ChFiDS_Stripe::*)() const) &ChFiDS_Stripe::IndexFirstPointOnS2, "None");
cls_ChFiDS_Stripe.def("IndexLastPointOnS1", (Standard_Integer (ChFiDS_Stripe::*)() const) &ChFiDS_Stripe::IndexLastPointOnS1, "None");
cls_ChFiDS_Stripe.def("IndexLastPointOnS2", (Standard_Integer (ChFiDS_Stripe::*)() const) &ChFiDS_Stripe::IndexLastPointOnS2, "None");
cls_ChFiDS_Stripe.def("ChangeIndexFirstPointOnS1", (void (ChFiDS_Stripe::*)(const Standard_Integer)) &ChFiDS_Stripe::ChangeIndexFirstPointOnS1, "None", py::arg("Index"));
cls_ChFiDS_Stripe.def("ChangeIndexFirstPointOnS2", (void (ChFiDS_Stripe::*)(const Standard_Integer)) &ChFiDS_Stripe::ChangeIndexFirstPointOnS2, "None", py::arg("Index"));
cls_ChFiDS_Stripe.def("ChangeIndexLastPointOnS1", (void (ChFiDS_Stripe::*)(const Standard_Integer)) &ChFiDS_Stripe::ChangeIndexLastPointOnS1, "None", py::arg("Index"));
cls_ChFiDS_Stripe.def("ChangeIndexLastPointOnS2", (void (ChFiDS_Stripe::*)(const Standard_Integer)) &ChFiDS_Stripe::ChangeIndexLastPointOnS2, "None", py::arg("Index"));
cls_ChFiDS_Stripe.def("Parameters", [](ChFiDS_Stripe &self, const Standard_Boolean First, Standard_Real & Pdeb, Standard_Real & Pfin){ self.Parameters(First, Pdeb, Pfin); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "None", py::arg("First"), py::arg("Pdeb"), py::arg("Pfin"));
cls_ChFiDS_Stripe.def("SetParameters", (void (ChFiDS_Stripe::*)(const Standard_Boolean, const Standard_Real, const Standard_Real)) &ChFiDS_Stripe::SetParameters, "None", py::arg("First"), py::arg("Pdeb"), py::arg("Pfin"));
cls_ChFiDS_Stripe.def("Curve", (Standard_Integer (ChFiDS_Stripe::*)(const Standard_Boolean) const) &ChFiDS_Stripe::Curve, "None", py::arg("First"));
cls_ChFiDS_Stripe.def("SetCurve", (void (ChFiDS_Stripe::*)(const Standard_Integer, const Standard_Boolean)) &ChFiDS_Stripe::SetCurve, "None", py::arg("Index"), py::arg("First"));
cls_ChFiDS_Stripe.def("PCurve", (const opencascade::handle<Geom2d_Curve> & (ChFiDS_Stripe::*)(const Standard_Boolean) const) &ChFiDS_Stripe::PCurve, "None", py::arg("First"));
cls_ChFiDS_Stripe.def("ChangePCurve", (opencascade::handle<Geom2d_Curve> & (ChFiDS_Stripe::*)(const Standard_Boolean)) &ChFiDS_Stripe::ChangePCurve, "None", py::arg("First"));
cls_ChFiDS_Stripe.def("Orientation", (TopAbs_Orientation (ChFiDS_Stripe::*)(const Standard_Integer) const) &ChFiDS_Stripe::Orientation, "None", py::arg("OnS"));
cls_ChFiDS_Stripe.def("SetOrientation", (void (ChFiDS_Stripe::*)(const TopAbs_Orientation, const Standard_Integer)) &ChFiDS_Stripe::SetOrientation, "None", py::arg("Or"), py::arg("OnS"));
cls_ChFiDS_Stripe.def("Orientation", (TopAbs_Orientation (ChFiDS_Stripe::*)(const Standard_Boolean) const) &ChFiDS_Stripe::Orientation, "None", py::arg("First"));
cls_ChFiDS_Stripe.def("SetOrientation", (void (ChFiDS_Stripe::*)(const TopAbs_Orientation, const Standard_Boolean)) &ChFiDS_Stripe::SetOrientation, "None", py::arg("Or"), py::arg("First"));
cls_ChFiDS_Stripe.def("IndexPoint", (Standard_Integer (ChFiDS_Stripe::*)(const Standard_Boolean, const Standard_Integer) const) &ChFiDS_Stripe::IndexPoint, "None", py::arg("First"), py::arg("OnS"));
cls_ChFiDS_Stripe.def("SetIndexPoint", (void (ChFiDS_Stripe::*)(const Standard_Integer, const Standard_Boolean, const Standard_Integer)) &ChFiDS_Stripe::SetIndexPoint, "None", py::arg("Index"), py::arg("First"), py::arg("OnS"));
cls_ChFiDS_Stripe.def("SolidIndex", (Standard_Integer (ChFiDS_Stripe::*)() const) &ChFiDS_Stripe::SolidIndex, "None");
cls_ChFiDS_Stripe.def("SetSolidIndex", (void (ChFiDS_Stripe::*)(const Standard_Integer)) &ChFiDS_Stripe::SetSolidIndex, "None", py::arg("Index"));
cls_ChFiDS_Stripe.def("InDS", [](ChFiDS_Stripe &self, const Standard_Boolean a0) -> void { return self.InDS(a0); });
cls_ChFiDS_Stripe.def("InDS", (void (ChFiDS_Stripe::*)(const Standard_Boolean, const Standard_Integer)) &ChFiDS_Stripe::InDS, "Set nb of SurfData's at end put in DS", py::arg("First"), py::arg("Nb"));
cls_ChFiDS_Stripe.def("IsInDS", (Standard_Integer (ChFiDS_Stripe::*)(const Standard_Boolean) const) &ChFiDS_Stripe::IsInDS, "Returns nb of SurfData's at end being in DS", py::arg("First"));
cls_ChFiDS_Stripe.def_static("get_type_name_", (const char * (*)()) &ChFiDS_Stripe::get_type_name, "None");
cls_ChFiDS_Stripe.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ChFiDS_Stripe::get_type_descriptor, "None");
cls_ChFiDS_Stripe.def("DynamicType", (const opencascade::handle<Standard_Type> & (ChFiDS_Stripe::*)() const) &ChFiDS_Stripe::DynamicType, "None");

// Enums

}