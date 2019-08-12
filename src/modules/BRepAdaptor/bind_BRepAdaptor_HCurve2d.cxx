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
#include <BRepAdaptor_Curve2d.hxx>
#include <Adaptor2d_Curve2d.hxx>
#include <Standard_Handle.hxx>
#include <BRepAdaptor_HCurve2d.hxx>
#include <Standard_Type.hxx>

void bind_BRepAdaptor_HCurve2d(py::module &mod){

py::class_<BRepAdaptor_HCurve2d, opencascade::handle<BRepAdaptor_HCurve2d>, Adaptor2d_HCurve2d> cls_BRepAdaptor_HCurve2d(mod, "BRepAdaptor_HCurve2d", "None");

// Constructors
cls_BRepAdaptor_HCurve2d.def(py::init<>());
cls_BRepAdaptor_HCurve2d.def(py::init<const BRepAdaptor_Curve2d &>(), py::arg("C"));

// Fields

// Methods
cls_BRepAdaptor_HCurve2d.def("Set", (void (BRepAdaptor_HCurve2d::*)(const BRepAdaptor_Curve2d &)) &BRepAdaptor_HCurve2d::Set, "Sets the field of the GenHCurve2d.", py::arg("C"));
cls_BRepAdaptor_HCurve2d.def("Curve2d", (const Adaptor2d_Curve2d & (BRepAdaptor_HCurve2d::*)() const) &BRepAdaptor_HCurve2d::Curve2d, "Returns the curve used to create the GenHCurve2d. This is redefined from HCurve2d, cannot be inline.");
cls_BRepAdaptor_HCurve2d.def("ChangeCurve2d", (BRepAdaptor_Curve2d & (BRepAdaptor_HCurve2d::*)()) &BRepAdaptor_HCurve2d::ChangeCurve2d, "Returns the curve used to create the GenHCurve.");
cls_BRepAdaptor_HCurve2d.def_static("get_type_name_", (const char * (*)()) &BRepAdaptor_HCurve2d::get_type_name, "None");
cls_BRepAdaptor_HCurve2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepAdaptor_HCurve2d::get_type_descriptor, "None");
cls_BRepAdaptor_HCurve2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepAdaptor_HCurve2d::*)() const) &BRepAdaptor_HCurve2d::DynamicType, "None");

// Enums

}