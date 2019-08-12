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
#include <GeomAdaptor_GHCurve.hxx>
#include <GeomAdaptor_Curve.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAdaptor_HCurve.hxx>
#include <Standard_Type.hxx>

void bind_GeomAdaptor_HCurve(py::module &mod){

py::class_<GeomAdaptor_HCurve, opencascade::handle<GeomAdaptor_HCurve>, GeomAdaptor_GHCurve> cls_GeomAdaptor_HCurve(mod, "GeomAdaptor_HCurve", "An interface between the services provided by any curve from the package Geom and those required of the curve by algorithms which use it.");

// Constructors
cls_GeomAdaptor_HCurve.def(py::init<>());
cls_GeomAdaptor_HCurve.def(py::init<const GeomAdaptor_Curve &>(), py::arg("AS"));
cls_GeomAdaptor_HCurve.def(py::init<const opencascade::handle<Geom_Curve> &>(), py::arg("S"));
cls_GeomAdaptor_HCurve.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("S"), py::arg("UFirst"), py::arg("ULast"));

// Fields

// Methods
cls_GeomAdaptor_HCurve.def_static("get_type_name_", (const char * (*)()) &GeomAdaptor_HCurve::get_type_name, "None");
cls_GeomAdaptor_HCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomAdaptor_HCurve::get_type_descriptor, "None");
cls_GeomAdaptor_HCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomAdaptor_HCurve::*)() const) &GeomAdaptor_HCurve::DynamicType, "None");

// Enums

}