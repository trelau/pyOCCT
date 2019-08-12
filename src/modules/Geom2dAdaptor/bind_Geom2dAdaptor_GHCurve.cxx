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
#include <Adaptor2d_HCurve2d.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <Adaptor2d_Curve2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom2dAdaptor_GHCurve.hxx>
#include <Standard_Type.hxx>

void bind_Geom2dAdaptor_GHCurve(py::module &mod){

py::class_<Geom2dAdaptor_GHCurve, opencascade::handle<Geom2dAdaptor_GHCurve>, Adaptor2d_HCurve2d> cls_Geom2dAdaptor_GHCurve(mod, "Geom2dAdaptor_GHCurve", "None");

// Constructors
cls_Geom2dAdaptor_GHCurve.def(py::init<>());
cls_Geom2dAdaptor_GHCurve.def(py::init<const Geom2dAdaptor_Curve &>(), py::arg("C"));

// Fields

// Methods
cls_Geom2dAdaptor_GHCurve.def("Set", (void (Geom2dAdaptor_GHCurve::*)(const Geom2dAdaptor_Curve &)) &Geom2dAdaptor_GHCurve::Set, "Sets the field of the GenHCurve2d.", py::arg("C"));
cls_Geom2dAdaptor_GHCurve.def("Curve2d", (const Adaptor2d_Curve2d & (Geom2dAdaptor_GHCurve::*)() const) &Geom2dAdaptor_GHCurve::Curve2d, "Returns the curve used to create the GenHCurve2d. This is redefined from HCurve2d, cannot be inline.");
cls_Geom2dAdaptor_GHCurve.def("ChangeCurve2d", (Geom2dAdaptor_Curve & (Geom2dAdaptor_GHCurve::*)()) &Geom2dAdaptor_GHCurve::ChangeCurve2d, "Returns the curve used to create the GenHCurve.");
cls_Geom2dAdaptor_GHCurve.def_static("get_type_name_", (const char * (*)()) &Geom2dAdaptor_GHCurve::get_type_name, "None");
cls_Geom2dAdaptor_GHCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom2dAdaptor_GHCurve::get_type_descriptor, "None");
cls_Geom2dAdaptor_GHCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom2dAdaptor_GHCurve::*)() const) &Geom2dAdaptor_GHCurve::DynamicType, "None");

// Enums

}