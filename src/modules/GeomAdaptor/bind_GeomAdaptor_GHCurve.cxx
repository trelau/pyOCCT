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
#include <GeomAdaptor_Curve.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Standard_Handle.hxx>
#include <GeomAdaptor_GHCurve.hxx>
#include <Standard_Type.hxx>

void bind_GeomAdaptor_GHCurve(py::module &mod){

py::class_<GeomAdaptor_GHCurve, opencascade::handle<GeomAdaptor_GHCurve>, Adaptor3d_HCurve> cls_GeomAdaptor_GHCurve(mod, "GeomAdaptor_GHCurve", "None");

// Constructors
cls_GeomAdaptor_GHCurve.def(py::init<>());
cls_GeomAdaptor_GHCurve.def(py::init<const GeomAdaptor_Curve &>(), py::arg("C"));

// Fields

// Methods
cls_GeomAdaptor_GHCurve.def("Set", (void (GeomAdaptor_GHCurve::*)(const GeomAdaptor_Curve &)) &GeomAdaptor_GHCurve::Set, "Sets the field of the GenHCurve.", py::arg("C"));
cls_GeomAdaptor_GHCurve.def("Curve", (const Adaptor3d_Curve & (GeomAdaptor_GHCurve::*)() const) &GeomAdaptor_GHCurve::Curve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
cls_GeomAdaptor_GHCurve.def("GetCurve", (Adaptor3d_Curve & (GeomAdaptor_GHCurve::*)()) &GeomAdaptor_GHCurve::GetCurve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
cls_GeomAdaptor_GHCurve.def("ChangeCurve", (GeomAdaptor_Curve & (GeomAdaptor_GHCurve::*)()) &GeomAdaptor_GHCurve::ChangeCurve, "Returns the curve used to create the GenHCurve.");
cls_GeomAdaptor_GHCurve.def_static("get_type_name_", (const char * (*)()) &GeomAdaptor_GHCurve::get_type_name, "None");
cls_GeomAdaptor_GHCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomAdaptor_GHCurve::get_type_descriptor, "None");
cls_GeomAdaptor_GHCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomAdaptor_GHCurve::*)() const) &GeomAdaptor_GHCurve::DynamicType, "None");

// Enums

}