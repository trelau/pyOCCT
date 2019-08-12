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
#include <Geom2dAdaptor_GHCurve.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom2dAdaptor_HCurve.hxx>
#include <Standard_Type.hxx>

void bind_Geom2dAdaptor_HCurve(py::module &mod){

py::class_<Geom2dAdaptor_HCurve, opencascade::handle<Geom2dAdaptor_HCurve>, Geom2dAdaptor_GHCurve> cls_Geom2dAdaptor_HCurve(mod, "Geom2dAdaptor_HCurve", "Provides an interface between the services provided by any curve from the package Geom2d and those required of the curve by algorithms, which use it.");

// Constructors
cls_Geom2dAdaptor_HCurve.def(py::init<>());
cls_Geom2dAdaptor_HCurve.def(py::init<const Geom2dAdaptor_Curve &>(), py::arg("AS"));
cls_Geom2dAdaptor_HCurve.def(py::init<const opencascade::handle<Geom2d_Curve> &>(), py::arg("S"));
cls_Geom2dAdaptor_HCurve.def(py::init<const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UFirst"), py::arg("ULast"));

// Fields

// Methods
cls_Geom2dAdaptor_HCurve.def_static("get_type_name_", (const char * (*)()) &Geom2dAdaptor_HCurve::get_type_name, "None");
cls_Geom2dAdaptor_HCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom2dAdaptor_HCurve::get_type_descriptor, "None");
cls_Geom2dAdaptor_HCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom2dAdaptor_HCurve::*)() const) &Geom2dAdaptor_HCurve::DynamicType, "None");

// Enums

}