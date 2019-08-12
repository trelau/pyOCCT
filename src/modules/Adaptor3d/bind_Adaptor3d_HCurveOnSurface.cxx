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
#include <Adaptor3d_CurveOnSurface.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HCurveOnSurface.hxx>
#include <Standard_Type.hxx>

void bind_Adaptor3d_HCurveOnSurface(py::module &mod){

py::class_<Adaptor3d_HCurveOnSurface, opencascade::handle<Adaptor3d_HCurveOnSurface>, Adaptor3d_HCurve> cls_Adaptor3d_HCurveOnSurface(mod, "Adaptor3d_HCurveOnSurface", "None");

// Constructors
cls_Adaptor3d_HCurveOnSurface.def(py::init<>());
cls_Adaptor3d_HCurveOnSurface.def(py::init<const Adaptor3d_CurveOnSurface &>(), py::arg("C"));

// Fields

// Methods
cls_Adaptor3d_HCurveOnSurface.def("Set", (void (Adaptor3d_HCurveOnSurface::*)(const Adaptor3d_CurveOnSurface &)) &Adaptor3d_HCurveOnSurface::Set, "Sets the field of the GenHCurve.", py::arg("C"));
cls_Adaptor3d_HCurveOnSurface.def("Curve", (const Adaptor3d_Curve & (Adaptor3d_HCurveOnSurface::*)() const) &Adaptor3d_HCurveOnSurface::Curve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
cls_Adaptor3d_HCurveOnSurface.def("GetCurve", (Adaptor3d_Curve & (Adaptor3d_HCurveOnSurface::*)()) &Adaptor3d_HCurveOnSurface::GetCurve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
cls_Adaptor3d_HCurveOnSurface.def("ChangeCurve", (Adaptor3d_CurveOnSurface & (Adaptor3d_HCurveOnSurface::*)()) &Adaptor3d_HCurveOnSurface::ChangeCurve, "Returns the curve used to create the GenHCurve.");
cls_Adaptor3d_HCurveOnSurface.def_static("get_type_name_", (const char * (*)()) &Adaptor3d_HCurveOnSurface::get_type_name, "None");
cls_Adaptor3d_HCurveOnSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Adaptor3d_HCurveOnSurface::get_type_descriptor, "None");
cls_Adaptor3d_HCurveOnSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (Adaptor3d_HCurveOnSurface::*)() const) &Adaptor3d_HCurveOnSurface::DynamicType, "None");

// Enums

}