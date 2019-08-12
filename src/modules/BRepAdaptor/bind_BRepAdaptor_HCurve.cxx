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
#include <BRepAdaptor_Curve.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Standard_Handle.hxx>
#include <BRepAdaptor_HCurve.hxx>
#include <Standard_Type.hxx>

void bind_BRepAdaptor_HCurve(py::module &mod){

py::class_<BRepAdaptor_HCurve, opencascade::handle<BRepAdaptor_HCurve>, Adaptor3d_HCurve> cls_BRepAdaptor_HCurve(mod, "BRepAdaptor_HCurve", "None");

// Constructors
cls_BRepAdaptor_HCurve.def(py::init<>());
cls_BRepAdaptor_HCurve.def(py::init<const BRepAdaptor_Curve &>(), py::arg("C"));

// Fields

// Methods
cls_BRepAdaptor_HCurve.def("Set", (void (BRepAdaptor_HCurve::*)(const BRepAdaptor_Curve &)) &BRepAdaptor_HCurve::Set, "Sets the field of the GenHCurve.", py::arg("C"));
cls_BRepAdaptor_HCurve.def("Curve", (const Adaptor3d_Curve & (BRepAdaptor_HCurve::*)() const) &BRepAdaptor_HCurve::Curve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
cls_BRepAdaptor_HCurve.def("GetCurve", (Adaptor3d_Curve & (BRepAdaptor_HCurve::*)()) &BRepAdaptor_HCurve::GetCurve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
cls_BRepAdaptor_HCurve.def("ChangeCurve", (BRepAdaptor_Curve & (BRepAdaptor_HCurve::*)()) &BRepAdaptor_HCurve::ChangeCurve, "Returns the curve used to create the GenHCurve.");
cls_BRepAdaptor_HCurve.def_static("get_type_name_", (const char * (*)()) &BRepAdaptor_HCurve::get_type_name, "None");
cls_BRepAdaptor_HCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepAdaptor_HCurve::get_type_descriptor, "None");
cls_BRepAdaptor_HCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepAdaptor_HCurve::*)() const) &BRepAdaptor_HCurve::DynamicType, "None");

// Enums

}