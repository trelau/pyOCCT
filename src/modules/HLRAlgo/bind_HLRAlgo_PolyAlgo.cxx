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
#include <TColStd_HArray1OfTransient.hxx>
#include <TColStd_Array1OfTransient.hxx>
#include <Standard_TypeDef.hxx>
#include <HLRAlgo_BiPoint.hxx>
#include <HLRAlgo_EdgeStatus.hxx>
#include <HLRAlgo_PolyAlgo.hxx>
#include <Standard_Type.hxx>
#include <HLRAlgo_PolyData.hxx>
#include <HLRAlgo_ListOfBPoint.hxx>

void bind_HLRAlgo_PolyAlgo(py::module &mod){

py::class_<HLRAlgo_PolyAlgo, opencascade::handle<HLRAlgo_PolyAlgo>, Standard_Transient> cls_HLRAlgo_PolyAlgo(mod, "HLRAlgo_PolyAlgo", "to remove Hidden lines on Triangulations.");

// Constructors
cls_HLRAlgo_PolyAlgo.def(py::init<>());

// Fields

// Methods
cls_HLRAlgo_PolyAlgo.def("Init", (void (HLRAlgo_PolyAlgo::*)(const opencascade::handle<TColStd_HArray1OfTransient> &)) &HLRAlgo_PolyAlgo::Init, "None", py::arg("HShell"));
cls_HLRAlgo_PolyAlgo.def("PolyShell", (TColStd_Array1OfTransient & (HLRAlgo_PolyAlgo::*)() const) &HLRAlgo_PolyAlgo::PolyShell, "None");
cls_HLRAlgo_PolyAlgo.def("Clear", (void (HLRAlgo_PolyAlgo::*)()) &HLRAlgo_PolyAlgo::Clear, "None");
cls_HLRAlgo_PolyAlgo.def("Update", (void (HLRAlgo_PolyAlgo::*)()) &HLRAlgo_PolyAlgo::Update, "Prepare all the data to process the algo.");
cls_HLRAlgo_PolyAlgo.def("InitHide", (void (HLRAlgo_PolyAlgo::*)()) &HLRAlgo_PolyAlgo::InitHide, "None");
cls_HLRAlgo_PolyAlgo.def("MoreHide", (Standard_Boolean (HLRAlgo_PolyAlgo::*)() const) &HLRAlgo_PolyAlgo::MoreHide, "None");
cls_HLRAlgo_PolyAlgo.def("NextHide", (void (HLRAlgo_PolyAlgo::*)()) &HLRAlgo_PolyAlgo::NextHide, "None");
cls_HLRAlgo_PolyAlgo.def("Hide", [](HLRAlgo_PolyAlgo &self, HLRAlgo_EdgeStatus & status, Standard_Integer & Index, Standard_Boolean & reg1, Standard_Boolean & regn, Standard_Boolean & outl, Standard_Boolean & intl){ HLRAlgo_BiPoint::PointsT & rv = self.Hide(status, Index, reg1, regn, outl, intl); return std::tuple<HLRAlgo_BiPoint::PointsT &, Standard_Integer &, Standard_Boolean &, Standard_Boolean &, Standard_Boolean &, Standard_Boolean &>(rv, Index, reg1, regn, outl, intl); }, "process hiding between <Pt1> and <Pt2>.", py::arg("status"), py::arg("Index"), py::arg("reg1"), py::arg("regn"), py::arg("outl"), py::arg("intl"));
cls_HLRAlgo_PolyAlgo.def("InitShow", (void (HLRAlgo_PolyAlgo::*)()) &HLRAlgo_PolyAlgo::InitShow, "None");
cls_HLRAlgo_PolyAlgo.def("MoreShow", (Standard_Boolean (HLRAlgo_PolyAlgo::*)() const) &HLRAlgo_PolyAlgo::MoreShow, "None");
cls_HLRAlgo_PolyAlgo.def("NextShow", (void (HLRAlgo_PolyAlgo::*)()) &HLRAlgo_PolyAlgo::NextShow, "None");
cls_HLRAlgo_PolyAlgo.def("Show", [](HLRAlgo_PolyAlgo &self, Standard_Integer & Index, Standard_Boolean & reg1, Standard_Boolean & regn, Standard_Boolean & outl, Standard_Boolean & intl){ HLRAlgo_BiPoint::PointsT & rv = self.Show(Index, reg1, regn, outl, intl); return std::tuple<HLRAlgo_BiPoint::PointsT &, Standard_Integer &, Standard_Boolean &, Standard_Boolean &, Standard_Boolean &, Standard_Boolean &>(rv, Index, reg1, regn, outl, intl); }, "process hiding between <Pt1> and <Pt2>.", py::arg("Index"), py::arg("reg1"), py::arg("regn"), py::arg("outl"), py::arg("intl"));
cls_HLRAlgo_PolyAlgo.def_static("get_type_name_", (const char * (*)()) &HLRAlgo_PolyAlgo::get_type_name, "None");
cls_HLRAlgo_PolyAlgo.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRAlgo_PolyAlgo::get_type_descriptor, "None");
cls_HLRAlgo_PolyAlgo.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRAlgo_PolyAlgo::*)() const) &HLRAlgo_PolyAlgo::DynamicType, "None");

// Enums

}