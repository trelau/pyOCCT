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
#include <BiTgte_CurveOnEdge.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Standard_Handle.hxx>
#include <BiTgte_HCurveOnEdge.hxx>
#include <Standard_Type.hxx>

void bind_BiTgte_HCurveOnEdge(py::module &mod){

py::class_<BiTgte_HCurveOnEdge, opencascade::handle<BiTgte_HCurveOnEdge>, Adaptor3d_HCurve> cls_BiTgte_HCurveOnEdge(mod, "BiTgte_HCurveOnEdge", "None");

// Constructors
cls_BiTgte_HCurveOnEdge.def(py::init<>());
cls_BiTgte_HCurveOnEdge.def(py::init<const BiTgte_CurveOnEdge &>(), py::arg("C"));

// Fields

// Methods
cls_BiTgte_HCurveOnEdge.def("Set", (void (BiTgte_HCurveOnEdge::*)(const BiTgte_CurveOnEdge &)) &BiTgte_HCurveOnEdge::Set, "Sets the field of the GenHCurve.", py::arg("C"));
cls_BiTgte_HCurveOnEdge.def("Curve", (const Adaptor3d_Curve & (BiTgte_HCurveOnEdge::*)() const) &BiTgte_HCurveOnEdge::Curve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
cls_BiTgte_HCurveOnEdge.def("GetCurve", (Adaptor3d_Curve & (BiTgte_HCurveOnEdge::*)()) &BiTgte_HCurveOnEdge::GetCurve, "Returns the curve used to create the GenHCurve. This is redefined from HCurve, cannot be inline.");
cls_BiTgte_HCurveOnEdge.def("ChangeCurve", (BiTgte_CurveOnEdge & (BiTgte_HCurveOnEdge::*)()) &BiTgte_HCurveOnEdge::ChangeCurve, "Returns the curve used to create the GenHCurve.");
cls_BiTgte_HCurveOnEdge.def_static("get_type_name_", (const char * (*)()) &BiTgte_HCurveOnEdge::get_type_name, "None");
cls_BiTgte_HCurveOnEdge.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BiTgte_HCurveOnEdge::get_type_descriptor, "None");
cls_BiTgte_HCurveOnEdge.def("DynamicType", (const opencascade::handle<Standard_Type> & (BiTgte_HCurveOnEdge::*)() const) &BiTgte_HCurveOnEdge::DynamicType, "None");

// Enums

}