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
#include <ChFiDS_SurfData.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_Orientation.hxx>
#include <ChFiDS_FaceInterference.hxx>
#include <ChFiDS_CommonPoint.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_Type.hxx>

void bind_ChFiDS_SurfData(py::module &mod){

py::class_<ChFiDS_SurfData, opencascade::handle<ChFiDS_SurfData>, Standard_Transient> cls_ChFiDS_SurfData(mod, "ChFiDS_SurfData", "data structure for all information related to the fillet and to 2 faces vis a vis");

// Constructors
cls_ChFiDS_SurfData.def(py::init<>());

// Fields

// Methods
cls_ChFiDS_SurfData.def("Copy", (void (ChFiDS_SurfData::*)(const opencascade::handle<ChFiDS_SurfData> &)) &ChFiDS_SurfData::Copy, "None", py::arg("Other"));
cls_ChFiDS_SurfData.def("IndexOfS1", (Standard_Integer (ChFiDS_SurfData::*)() const) &ChFiDS_SurfData::IndexOfS1, "None");
cls_ChFiDS_SurfData.def("IndexOfS2", (Standard_Integer (ChFiDS_SurfData::*)() const) &ChFiDS_SurfData::IndexOfS2, "None");
cls_ChFiDS_SurfData.def("IsOnCurve1", (Standard_Boolean (ChFiDS_SurfData::*)() const) &ChFiDS_SurfData::IsOnCurve1, "None");
cls_ChFiDS_SurfData.def("IsOnCurve2", (Standard_Boolean (ChFiDS_SurfData::*)() const) &ChFiDS_SurfData::IsOnCurve2, "None");
cls_ChFiDS_SurfData.def("IndexOfC1", (Standard_Integer (ChFiDS_SurfData::*)() const) &ChFiDS_SurfData::IndexOfC1, "None");
cls_ChFiDS_SurfData.def("IndexOfC2", (Standard_Integer (ChFiDS_SurfData::*)() const) &ChFiDS_SurfData::IndexOfC2, "None");
cls_ChFiDS_SurfData.def("Surf", (Standard_Integer (ChFiDS_SurfData::*)() const) &ChFiDS_SurfData::Surf, "None");
cls_ChFiDS_SurfData.def("Orientation", (TopAbs_Orientation (ChFiDS_SurfData::*)() const) &ChFiDS_SurfData::Orientation, "None");
cls_ChFiDS_SurfData.def("InterferenceOnS1", (const ChFiDS_FaceInterference & (ChFiDS_SurfData::*)() const) &ChFiDS_SurfData::InterferenceOnS1, "None");
cls_ChFiDS_SurfData.def("InterferenceOnS2", (const ChFiDS_FaceInterference & (ChFiDS_SurfData::*)() const) &ChFiDS_SurfData::InterferenceOnS2, "None");
cls_ChFiDS_SurfData.def("VertexFirstOnS1", (const ChFiDS_CommonPoint & (ChFiDS_SurfData::*)() const) &ChFiDS_SurfData::VertexFirstOnS1, "None");
cls_ChFiDS_SurfData.def("VertexFirstOnS2", (const ChFiDS_CommonPoint & (ChFiDS_SurfData::*)() const) &ChFiDS_SurfData::VertexFirstOnS2, "None");
cls_ChFiDS_SurfData.def("VertexLastOnS1", (const ChFiDS_CommonPoint & (ChFiDS_SurfData::*)() const) &ChFiDS_SurfData::VertexLastOnS1, "None");
cls_ChFiDS_SurfData.def("VertexLastOnS2", (const ChFiDS_CommonPoint & (ChFiDS_SurfData::*)() const) &ChFiDS_SurfData::VertexLastOnS2, "None");
cls_ChFiDS_SurfData.def("ChangeIndexOfS1", (void (ChFiDS_SurfData::*)(const Standard_Integer)) &ChFiDS_SurfData::ChangeIndexOfS1, "None", py::arg("Index"));
cls_ChFiDS_SurfData.def("ChangeIndexOfS2", (void (ChFiDS_SurfData::*)(const Standard_Integer)) &ChFiDS_SurfData::ChangeIndexOfS2, "None", py::arg("Index"));
cls_ChFiDS_SurfData.def("ChangeSurf", (void (ChFiDS_SurfData::*)(const Standard_Integer)) &ChFiDS_SurfData::ChangeSurf, "None", py::arg("Index"));
cls_ChFiDS_SurfData.def("SetIndexOfC1", (void (ChFiDS_SurfData::*)(const Standard_Integer)) &ChFiDS_SurfData::SetIndexOfC1, "None", py::arg("Index"));
cls_ChFiDS_SurfData.def("SetIndexOfC2", (void (ChFiDS_SurfData::*)(const Standard_Integer)) &ChFiDS_SurfData::SetIndexOfC2, "None", py::arg("Index"));
cls_ChFiDS_SurfData.def("ChangeOrientation", (TopAbs_Orientation & (ChFiDS_SurfData::*)()) &ChFiDS_SurfData::ChangeOrientation, "None");
cls_ChFiDS_SurfData.def("ChangeInterferenceOnS1", (ChFiDS_FaceInterference & (ChFiDS_SurfData::*)()) &ChFiDS_SurfData::ChangeInterferenceOnS1, "None");
cls_ChFiDS_SurfData.def("ChangeInterferenceOnS2", (ChFiDS_FaceInterference & (ChFiDS_SurfData::*)()) &ChFiDS_SurfData::ChangeInterferenceOnS2, "None");
cls_ChFiDS_SurfData.def("ChangeVertexFirstOnS1", (ChFiDS_CommonPoint & (ChFiDS_SurfData::*)()) &ChFiDS_SurfData::ChangeVertexFirstOnS1, "None");
cls_ChFiDS_SurfData.def("ChangeVertexFirstOnS2", (ChFiDS_CommonPoint & (ChFiDS_SurfData::*)()) &ChFiDS_SurfData::ChangeVertexFirstOnS2, "None");
cls_ChFiDS_SurfData.def("ChangeVertexLastOnS1", (ChFiDS_CommonPoint & (ChFiDS_SurfData::*)()) &ChFiDS_SurfData::ChangeVertexLastOnS1, "None");
cls_ChFiDS_SurfData.def("ChangeVertexLastOnS2", (ChFiDS_CommonPoint & (ChFiDS_SurfData::*)()) &ChFiDS_SurfData::ChangeVertexLastOnS2, "None");
cls_ChFiDS_SurfData.def("Interference", (const ChFiDS_FaceInterference & (ChFiDS_SurfData::*)(const Standard_Integer) const) &ChFiDS_SurfData::Interference, "None", py::arg("OnS"));
cls_ChFiDS_SurfData.def("ChangeInterference", (ChFiDS_FaceInterference & (ChFiDS_SurfData::*)(const Standard_Integer)) &ChFiDS_SurfData::ChangeInterference, "None", py::arg("OnS"));
cls_ChFiDS_SurfData.def("Index", (Standard_Integer (ChFiDS_SurfData::*)(const Standard_Integer) const) &ChFiDS_SurfData::Index, "None", py::arg("OfS"));
cls_ChFiDS_SurfData.def("Vertex", (const ChFiDS_CommonPoint & (ChFiDS_SurfData::*)(const Standard_Boolean, const Standard_Integer) const) &ChFiDS_SurfData::Vertex, "returns one of the four vertices wether First is true or wrong and OnS equals 1 or 2.", py::arg("First"), py::arg("OnS"));
cls_ChFiDS_SurfData.def("ChangeVertex", (ChFiDS_CommonPoint & (ChFiDS_SurfData::*)(const Standard_Boolean, const Standard_Integer)) &ChFiDS_SurfData::ChangeVertex, "returns one of the four vertices wether First is true or wrong and OnS equals 1 or 2.", py::arg("First"), py::arg("OnS"));
cls_ChFiDS_SurfData.def("IsOnCurve", (Standard_Boolean (ChFiDS_SurfData::*)(const Standard_Integer) const) &ChFiDS_SurfData::IsOnCurve, "None", py::arg("OnS"));
cls_ChFiDS_SurfData.def("IndexOfC", (Standard_Integer (ChFiDS_SurfData::*)(const Standard_Integer) const) &ChFiDS_SurfData::IndexOfC, "None", py::arg("OnS"));
cls_ChFiDS_SurfData.def("FirstSpineParam", (Standard_Real (ChFiDS_SurfData::*)() const) &ChFiDS_SurfData::FirstSpineParam, "None");
cls_ChFiDS_SurfData.def("LastSpineParam", (Standard_Real (ChFiDS_SurfData::*)() const) &ChFiDS_SurfData::LastSpineParam, "None");
cls_ChFiDS_SurfData.def("FirstSpineParam", (void (ChFiDS_SurfData::*)(const Standard_Real)) &ChFiDS_SurfData::FirstSpineParam, "None", py::arg("Par"));
cls_ChFiDS_SurfData.def("LastSpineParam", (void (ChFiDS_SurfData::*)(const Standard_Real)) &ChFiDS_SurfData::LastSpineParam, "None", py::arg("Par"));
cls_ChFiDS_SurfData.def("FirstExtensionValue", (Standard_Real (ChFiDS_SurfData::*)() const) &ChFiDS_SurfData::FirstExtensionValue, "None");
cls_ChFiDS_SurfData.def("LastExtensionValue", (Standard_Real (ChFiDS_SurfData::*)() const) &ChFiDS_SurfData::LastExtensionValue, "None");
cls_ChFiDS_SurfData.def("FirstExtensionValue", (void (ChFiDS_SurfData::*)(const Standard_Real)) &ChFiDS_SurfData::FirstExtensionValue, "None", py::arg("Extend"));
cls_ChFiDS_SurfData.def("LastExtensionValue", (void (ChFiDS_SurfData::*)(const Standard_Real)) &ChFiDS_SurfData::LastExtensionValue, "None", py::arg("Extend"));
cls_ChFiDS_SurfData.def("Simul", (opencascade::handle<Standard_Transient> (ChFiDS_SurfData::*)() const) &ChFiDS_SurfData::Simul, "None");
cls_ChFiDS_SurfData.def("SetSimul", (void (ChFiDS_SurfData::*)(const opencascade::handle<Standard_Transient> &)) &ChFiDS_SurfData::SetSimul, "None", py::arg("S"));
cls_ChFiDS_SurfData.def("ResetSimul", (void (ChFiDS_SurfData::*)()) &ChFiDS_SurfData::ResetSimul, "None");
cls_ChFiDS_SurfData.def("Get2dPoints", (gp_Pnt2d (ChFiDS_SurfData::*)(const Standard_Boolean, const Standard_Integer) const) &ChFiDS_SurfData::Get2dPoints, "None", py::arg("First"), py::arg("OnS"));
cls_ChFiDS_SurfData.def("Get2dPoints", (void (ChFiDS_SurfData::*)(gp_Pnt2d &, gp_Pnt2d &, gp_Pnt2d &, gp_Pnt2d &) const) &ChFiDS_SurfData::Get2dPoints, "None", py::arg("P2df1"), py::arg("P2dl1"), py::arg("P2df2"), py::arg("P2dl2"));
cls_ChFiDS_SurfData.def("Set2dPoints", (void (ChFiDS_SurfData::*)(const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &)) &ChFiDS_SurfData::Set2dPoints, "None", py::arg("P2df1"), py::arg("P2dl1"), py::arg("P2df2"), py::arg("P2dl2"));
cls_ChFiDS_SurfData.def("TwistOnS1", (Standard_Boolean (ChFiDS_SurfData::*)() const) &ChFiDS_SurfData::TwistOnS1, "None");
cls_ChFiDS_SurfData.def("TwistOnS2", (Standard_Boolean (ChFiDS_SurfData::*)() const) &ChFiDS_SurfData::TwistOnS2, "None");
cls_ChFiDS_SurfData.def("TwistOnS1", (void (ChFiDS_SurfData::*)(const Standard_Boolean)) &ChFiDS_SurfData::TwistOnS1, "None", py::arg("T"));
cls_ChFiDS_SurfData.def("TwistOnS2", (void (ChFiDS_SurfData::*)(const Standard_Boolean)) &ChFiDS_SurfData::TwistOnS2, "None", py::arg("T"));
cls_ChFiDS_SurfData.def_static("get_type_name_", (const char * (*)()) &ChFiDS_SurfData::get_type_name, "None");
cls_ChFiDS_SurfData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ChFiDS_SurfData::get_type_descriptor, "None");
cls_ChFiDS_SurfData.def("DynamicType", (const opencascade::handle<Standard_Type> & (ChFiDS_SurfData::*)() const) &ChFiDS_SurfData::DynamicType, "None");

// Enums

}