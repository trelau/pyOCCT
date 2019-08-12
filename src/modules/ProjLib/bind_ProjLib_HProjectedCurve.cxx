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
#include <ProjLib_ProjectedCurve.hxx>
#include <Adaptor2d_Curve2d.hxx>
#include <Standard_Handle.hxx>
#include <ProjLib_HProjectedCurve.hxx>
#include <Standard_Type.hxx>

void bind_ProjLib_HProjectedCurve(py::module &mod){

py::class_<ProjLib_HProjectedCurve, opencascade::handle<ProjLib_HProjectedCurve>, Adaptor2d_HCurve2d> cls_ProjLib_HProjectedCurve(mod, "ProjLib_HProjectedCurve", "None");

// Constructors
cls_ProjLib_HProjectedCurve.def(py::init<>());
cls_ProjLib_HProjectedCurve.def(py::init<const ProjLib_ProjectedCurve &>(), py::arg("C"));

// Fields

// Methods
cls_ProjLib_HProjectedCurve.def("Set", (void (ProjLib_HProjectedCurve::*)(const ProjLib_ProjectedCurve &)) &ProjLib_HProjectedCurve::Set, "Sets the field of the GenHCurve2d.", py::arg("C"));
cls_ProjLib_HProjectedCurve.def("Curve2d", (const Adaptor2d_Curve2d & (ProjLib_HProjectedCurve::*)() const) &ProjLib_HProjectedCurve::Curve2d, "Returns the curve used to create the GenHCurve2d. This is redefined from HCurve2d, cannot be inline.");
cls_ProjLib_HProjectedCurve.def("ChangeCurve2d", (ProjLib_ProjectedCurve & (ProjLib_HProjectedCurve::*)()) &ProjLib_HProjectedCurve::ChangeCurve2d, "Returns the curve used to create the GenHCurve.");
cls_ProjLib_HProjectedCurve.def_static("get_type_name_", (const char * (*)()) &ProjLib_HProjectedCurve::get_type_name, "None");
cls_ProjLib_HProjectedCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ProjLib_HProjectedCurve::get_type_descriptor, "None");
cls_ProjLib_HProjectedCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (ProjLib_HProjectedCurve::*)() const) &ProjLib_HProjectedCurve::DynamicType, "None");

// Enums

}