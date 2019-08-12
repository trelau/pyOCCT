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
#include <HLRAlgo_Array1OfTData.hxx>
#include <HLRAlgo_Array1OfPISeg.hxx>
#include <HLRAlgo_Array1OfPINod.hxx>
#include <HLRAlgo_PolyInternalNode.hxx>
#include <Standard_Handle.hxx>
#include <HLRAlgo_PolyInternalData.hxx>
#include <Standard_Type.hxx>
#include <HLRAlgo_HArray1OfTData.hxx>
#include <HLRAlgo_HArray1OfPISeg.hxx>
#include <HLRAlgo_HArray1OfPINod.hxx>

void bind_HLRAlgo_PolyInternalData(py::module &mod){

py::class_<HLRAlgo_PolyInternalData, opencascade::handle<HLRAlgo_PolyInternalData>, Standard_Transient> cls_HLRAlgo_PolyInternalData(mod, "HLRAlgo_PolyInternalData", "to Update OutLines.");

// Constructors
cls_HLRAlgo_PolyInternalData.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("nbNod"), py::arg("nbTri"));

// Fields

// Methods
// cls_HLRAlgo_PolyInternalData.def("UpdateLinks", (void (HLRAlgo_PolyInternalData::*)(HLRAlgo_Array1OfTData *&, HLRAlgo_Array1OfPISeg *&, HLRAlgo_Array1OfPINod *&)) &HLRAlgo_PolyInternalData::UpdateLinks, "None", py::arg("TData"), py::arg("PISeg"), py::arg("PINod"));
// cls_HLRAlgo_PolyInternalData.def("AddNode", (Standard_Integer (HLRAlgo_PolyInternalData::*)(HLRAlgo_PolyInternalNode::NodeData &, HLRAlgo_PolyInternalNode::NodeData &, HLRAlgo_Array1OfPINod *&, HLRAlgo_Array1OfPINod *&, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &HLRAlgo_PolyInternalData::AddNode, "None", py::arg("Nod1RValues"), py::arg("Nod2RValues"), py::arg("PINod1"), py::arg("PINod2"), py::arg("coef1"), py::arg("X3"), py::arg("Y3"), py::arg("Z3"));
// cls_HLRAlgo_PolyInternalData.def("UpdateLinks", (void (HLRAlgo_PolyInternalData::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, HLRAlgo_Array1OfTData *&, HLRAlgo_Array1OfTData *&, HLRAlgo_Array1OfPISeg *&, HLRAlgo_Array1OfPISeg *&, HLRAlgo_Array1OfPINod *&, HLRAlgo_Array1OfPINod *&)) &HLRAlgo_PolyInternalData::UpdateLinks, "None", py::arg("ip1"), py::arg("ip2"), py::arg("ip3"), py::arg("TData1"), py::arg("TData2"), py::arg("PISeg1"), py::arg("PISeg2"), py::arg("PINod1"), py::arg("PINod2"));
cls_HLRAlgo_PolyInternalData.def("Dump", (void (HLRAlgo_PolyInternalData::*)() const) &HLRAlgo_PolyInternalData::Dump, "None");
// cls_HLRAlgo_PolyInternalData.def("IncTData", (void (HLRAlgo_PolyInternalData::*)(HLRAlgo_Array1OfTData *&, HLRAlgo_Array1OfTData *&)) &HLRAlgo_PolyInternalData::IncTData, "None", py::arg("TData1"), py::arg("TData2"));
// cls_HLRAlgo_PolyInternalData.def("IncPISeg", (void (HLRAlgo_PolyInternalData::*)(HLRAlgo_Array1OfPISeg *&, HLRAlgo_Array1OfPISeg *&)) &HLRAlgo_PolyInternalData::IncPISeg, "None", py::arg("PISeg1"), py::arg("PISeg2"));
// cls_HLRAlgo_PolyInternalData.def("IncPINod", (void (HLRAlgo_PolyInternalData::*)(HLRAlgo_Array1OfPINod *&, HLRAlgo_Array1OfPINod *&)) &HLRAlgo_PolyInternalData::IncPINod, "None", py::arg("PINod1"), py::arg("PINod2"));
cls_HLRAlgo_PolyInternalData.def("DecTData", (void (HLRAlgo_PolyInternalData::*)()) &HLRAlgo_PolyInternalData::DecTData, "None");
cls_HLRAlgo_PolyInternalData.def("DecPISeg", (void (HLRAlgo_PolyInternalData::*)()) &HLRAlgo_PolyInternalData::DecPISeg, "None");
cls_HLRAlgo_PolyInternalData.def("DecPINod", (void (HLRAlgo_PolyInternalData::*)()) &HLRAlgo_PolyInternalData::DecPINod, "None");
cls_HLRAlgo_PolyInternalData.def("NbTData", (Standard_Integer (HLRAlgo_PolyInternalData::*)() const) &HLRAlgo_PolyInternalData::NbTData, "None");
cls_HLRAlgo_PolyInternalData.def("NbPISeg", (Standard_Integer (HLRAlgo_PolyInternalData::*)() const) &HLRAlgo_PolyInternalData::NbPISeg, "None");
cls_HLRAlgo_PolyInternalData.def("NbPINod", (Standard_Integer (HLRAlgo_PolyInternalData::*)() const) &HLRAlgo_PolyInternalData::NbPINod, "None");
cls_HLRAlgo_PolyInternalData.def("Planar", (Standard_Boolean (HLRAlgo_PolyInternalData::*)() const) &HLRAlgo_PolyInternalData::Planar, "None");
cls_HLRAlgo_PolyInternalData.def("Planar", (void (HLRAlgo_PolyInternalData::*)(const Standard_Boolean)) &HLRAlgo_PolyInternalData::Planar, "None", py::arg("B"));
cls_HLRAlgo_PolyInternalData.def("IntOutL", (Standard_Boolean (HLRAlgo_PolyInternalData::*)() const) &HLRAlgo_PolyInternalData::IntOutL, "None");
cls_HLRAlgo_PolyInternalData.def("IntOutL", (void (HLRAlgo_PolyInternalData::*)(const Standard_Boolean)) &HLRAlgo_PolyInternalData::IntOutL, "None", py::arg("B"));
cls_HLRAlgo_PolyInternalData.def("TData", (HLRAlgo_Array1OfTData & (HLRAlgo_PolyInternalData::*)() const) &HLRAlgo_PolyInternalData::TData, "None");
cls_HLRAlgo_PolyInternalData.def("PISeg", (HLRAlgo_Array1OfPISeg & (HLRAlgo_PolyInternalData::*)() const) &HLRAlgo_PolyInternalData::PISeg, "None");
cls_HLRAlgo_PolyInternalData.def("PINod", (HLRAlgo_Array1OfPINod & (HLRAlgo_PolyInternalData::*)() const) &HLRAlgo_PolyInternalData::PINod, "None");
cls_HLRAlgo_PolyInternalData.def_static("get_type_name_", (const char * (*)()) &HLRAlgo_PolyInternalData::get_type_name, "None");
cls_HLRAlgo_PolyInternalData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRAlgo_PolyInternalData::get_type_descriptor, "None");
cls_HLRAlgo_PolyInternalData.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRAlgo_PolyInternalData::*)() const) &HLRAlgo_PolyInternalData::DynamicType, "None");

// Enums

}