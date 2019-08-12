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
#include <Adaptor2d_Line2d.hxx>
#include <Adaptor2d_Curve2d.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor2d_HLine2d.hxx>
#include <Standard_Type.hxx>

void bind_Adaptor2d_HLine2d(py::module &mod){

py::class_<Adaptor2d_HLine2d, opencascade::handle<Adaptor2d_HLine2d>, Adaptor2d_HCurve2d> cls_Adaptor2d_HLine2d(mod, "Adaptor2d_HLine2d", "None");

// Constructors
cls_Adaptor2d_HLine2d.def(py::init<>());
cls_Adaptor2d_HLine2d.def(py::init<const Adaptor2d_Line2d &>(), py::arg("C"));

// Fields

// Methods
cls_Adaptor2d_HLine2d.def("Set", (void (Adaptor2d_HLine2d::*)(const Adaptor2d_Line2d &)) &Adaptor2d_HLine2d::Set, "Sets the field of the GenHCurve2d.", py::arg("C"));
cls_Adaptor2d_HLine2d.def("Curve2d", (const Adaptor2d_Curve2d & (Adaptor2d_HLine2d::*)() const) &Adaptor2d_HLine2d::Curve2d, "Returns the curve used to create the GenHCurve2d. This is redefined from HCurve2d, cannot be inline.");
cls_Adaptor2d_HLine2d.def("ChangeCurve2d", (Adaptor2d_Line2d & (Adaptor2d_HLine2d::*)()) &Adaptor2d_HLine2d::ChangeCurve2d, "Returns the curve used to create the GenHCurve.");
cls_Adaptor2d_HLine2d.def_static("get_type_name_", (const char * (*)()) &Adaptor2d_HLine2d::get_type_name, "None");
cls_Adaptor2d_HLine2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Adaptor2d_HLine2d::get_type_descriptor, "None");
cls_Adaptor2d_HLine2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (Adaptor2d_HLine2d::*)() const) &Adaptor2d_HLine2d::DynamicType, "None");

// Enums

}