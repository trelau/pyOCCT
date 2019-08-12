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
#include <BiTgte_CurveOnVertex.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Standard_Handle.hxx>
#include <BiTgte_HCurveOnVertex.hxx>
#include <Standard_Type.hxx>

void bind_BiTgte_HCurveOnVertex(py::module &mod){

py::class_<BiTgte_HCurveOnVertex, opencascade::handle<BiTgte_HCurveOnVertex>, Adaptor3d_HCurve> cls_BiTgte_HCurveOnVertex(mod, "BiTgte_HCurveOnVertex", "None");

// Constructors
cls_BiTgte_HCurveOnVertex.def(py::init<>());
cls_BiTgte_HCurveOnVertex.def(py::init<const BiTgte_CurveOnVertex &>(), py::arg("C"));

// Fields

// Methods
cls_BiTgte_HCurveOnVertex.def("Set", (void (BiTgte_HCurveOnVertex::*)(const BiTgte_CurveOnVertex &)) &BiTgte_HCurveOnVertex::Set, "Sets the field of the GenHCurve.", py::arg("C"));
cls_BiTgte_HCurveOnVertex.def("Curve", (const Adaptor3d_Curve & (BiTgte_HCurveOnVertex::*)() const) &BiTgte_HCurveOnVertex::Curve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
cls_BiTgte_HCurveOnVertex.def("GetCurve", (Adaptor3d_Curve & (BiTgte_HCurveOnVertex::*)()) &BiTgte_HCurveOnVertex::GetCurve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
cls_BiTgte_HCurveOnVertex.def("ChangeCurve", (BiTgte_CurveOnVertex & (BiTgte_HCurveOnVertex::*)()) &BiTgte_HCurveOnVertex::ChangeCurve, "Returns the curve used to create the GenHCurve.");
cls_BiTgte_HCurveOnVertex.def_static("get_type_name_", (const char * (*)()) &BiTgte_HCurveOnVertex::get_type_name, "None");
cls_BiTgte_HCurveOnVertex.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BiTgte_HCurveOnVertex::get_type_descriptor, "None");
cls_BiTgte_HCurveOnVertex.def("DynamicType", (const opencascade::handle<Standard_Type> & (BiTgte_HCurveOnVertex::*)() const) &BiTgte_HCurveOnVertex::DynamicType, "None");

// Enums

}