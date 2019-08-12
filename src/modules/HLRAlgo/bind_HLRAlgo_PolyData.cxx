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
#include <Standard_Handle.hxx>
#include <TColgp_HArray1OfXYZ.hxx>
#include <HLRAlgo_HArray1OfTData.hxx>
#include <HLRAlgo_HArray1OfPHDat.hxx>
#include <TColgp_Array1OfXYZ.hxx>
#include <HLRAlgo_Array1OfTData.hxx>
#include <HLRAlgo_Array1OfPHDat.hxx>
#include <HLRAlgo_PolyData.hxx>
#include <HLRAlgo_BiPoint.hxx>
#include <HLRAlgo_EdgeStatus.hxx>
#include <Standard_Type.hxx>

void bind_HLRAlgo_PolyData(py::module &mod){

py::class_<HLRAlgo_PolyData, opencascade::handle<HLRAlgo_PolyData>, Standard_Transient> cls_HLRAlgo_PolyData(mod, "HLRAlgo_PolyData", "Data structure of a set of Triangles.");

// Constructors
cls_HLRAlgo_PolyData.def(py::init<>());

// Fields

// Methods
cls_HLRAlgo_PolyData.def("HNodes", (void (HLRAlgo_PolyData::*)(const opencascade::handle<TColgp_HArray1OfXYZ> &)) &HLRAlgo_PolyData::HNodes, "None", py::arg("HNodes"));
cls_HLRAlgo_PolyData.def("HTData", (void (HLRAlgo_PolyData::*)(const opencascade::handle<HLRAlgo_HArray1OfTData> &)) &HLRAlgo_PolyData::HTData, "None", py::arg("HTData"));
cls_HLRAlgo_PolyData.def("HPHDat", (void (HLRAlgo_PolyData::*)(const opencascade::handle<HLRAlgo_HArray1OfPHDat> &)) &HLRAlgo_PolyData::HPHDat, "None", py::arg("HPHDat"));
cls_HLRAlgo_PolyData.def("FaceIndex", (void (HLRAlgo_PolyData::*)(const Standard_Integer)) &HLRAlgo_PolyData::FaceIndex, "None", py::arg("I"));
cls_HLRAlgo_PolyData.def("FaceIndex", (Standard_Integer (HLRAlgo_PolyData::*)() const) &HLRAlgo_PolyData::FaceIndex, "None");
cls_HLRAlgo_PolyData.def("Nodes", (TColgp_Array1OfXYZ & (HLRAlgo_PolyData::*)() const) &HLRAlgo_PolyData::Nodes, "None");
cls_HLRAlgo_PolyData.def("TData", (HLRAlgo_Array1OfTData & (HLRAlgo_PolyData::*)() const) &HLRAlgo_PolyData::TData, "None");
cls_HLRAlgo_PolyData.def("PHDat", (HLRAlgo_Array1OfPHDat & (HLRAlgo_PolyData::*)() const) &HLRAlgo_PolyData::PHDat, "None");
cls_HLRAlgo_PolyData.def("UpdateGlobalMinMax", (void (HLRAlgo_PolyData::*)(HLRAlgo_PolyData::Box &)) &HLRAlgo_PolyData::UpdateGlobalMinMax, "None", py::arg("theBox"));
cls_HLRAlgo_PolyData.def("Hiding", (Standard_Boolean (HLRAlgo_PolyData::*)() const) &HLRAlgo_PolyData::Hiding, "None");
cls_HLRAlgo_PolyData.def("HideByPolyData", (void (HLRAlgo_PolyData::*)(const HLRAlgo_BiPoint::PointsT &, HLRAlgo_PolyData::Triangle &, HLRAlgo_BiPoint::IndicesT &, const Standard_Boolean, HLRAlgo_EdgeStatus &)) &HLRAlgo_PolyData::HideByPolyData, "process hiding between <Pt1> and <Pt2>.", py::arg("thePoints"), py::arg("theTriangle"), py::arg("theIndices"), py::arg("HidingShell"), py::arg("status"));
cls_HLRAlgo_PolyData.def("Indices", (HLRAlgo_PolyData::FaceIndices & (HLRAlgo_PolyData::*)()) &HLRAlgo_PolyData::Indices, "None");
cls_HLRAlgo_PolyData.def_static("get_type_name_", (const char * (*)()) &HLRAlgo_PolyData::get_type_name, "None");
cls_HLRAlgo_PolyData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRAlgo_PolyData::get_type_descriptor, "None");
cls_HLRAlgo_PolyData.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRAlgo_PolyData::*)() const) &HLRAlgo_PolyData::DynamicType, "None");

// Enums

}