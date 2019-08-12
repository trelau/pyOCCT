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
#include <Adaptor3d_HCurve.hxx>
#include <ChFiDS_ElSpine.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Standard_Handle.hxx>
#include <ChFiDS_HElSpine.hxx>
#include <Standard_Type.hxx>

void bind_ChFiDS_HElSpine(py::module &mod){

py::class_<ChFiDS_HElSpine, opencascade::handle<ChFiDS_HElSpine>, Adaptor3d_HCurve> cls_ChFiDS_HElSpine(mod, "ChFiDS_HElSpine", "None");

// Constructors
cls_ChFiDS_HElSpine.def(py::init<>());
cls_ChFiDS_HElSpine.def(py::init<const ChFiDS_ElSpine &>(), py::arg("C"));

// Fields

// Methods
cls_ChFiDS_HElSpine.def("Set", (void (ChFiDS_HElSpine::*)(const ChFiDS_ElSpine &)) &ChFiDS_HElSpine::Set, "Sets the field of the GenHCurve.", py::arg("C"));
cls_ChFiDS_HElSpine.def("Curve", (const Adaptor3d_Curve & (ChFiDS_HElSpine::*)() const) &ChFiDS_HElSpine::Curve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
cls_ChFiDS_HElSpine.def("GetCurve", (Adaptor3d_Curve & (ChFiDS_HElSpine::*)()) &ChFiDS_HElSpine::GetCurve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
cls_ChFiDS_HElSpine.def("ChangeCurve", (ChFiDS_ElSpine & (ChFiDS_HElSpine::*)()) &ChFiDS_HElSpine::ChangeCurve, "Returns the curve used to create the GenHCurve.");
cls_ChFiDS_HElSpine.def_static("get_type_name_", (const char * (*)()) &ChFiDS_HElSpine::get_type_name, "None");
cls_ChFiDS_HElSpine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ChFiDS_HElSpine::get_type_descriptor, "None");
cls_ChFiDS_HElSpine.def("DynamicType", (const opencascade::handle<Standard_Type> & (ChFiDS_HElSpine::*)() const) &ChFiDS_HElSpine::DynamicType, "None");

// Enums

}