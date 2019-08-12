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
#include <ProjLib_CompProjectedCurve.hxx>
#include <Adaptor2d_Curve2d.hxx>
#include <Standard_Handle.hxx>
#include <ProjLib_HCompProjectedCurve.hxx>
#include <Standard_Type.hxx>

void bind_ProjLib_HCompProjectedCurve(py::module &mod){

py::class_<ProjLib_HCompProjectedCurve, opencascade::handle<ProjLib_HCompProjectedCurve>, Adaptor2d_HCurve2d> cls_ProjLib_HCompProjectedCurve(mod, "ProjLib_HCompProjectedCurve", "None");

// Constructors
cls_ProjLib_HCompProjectedCurve.def(py::init<>());
cls_ProjLib_HCompProjectedCurve.def(py::init<const ProjLib_CompProjectedCurve &>(), py::arg("C"));

// Fields

// Methods
cls_ProjLib_HCompProjectedCurve.def("Set", (void (ProjLib_HCompProjectedCurve::*)(const ProjLib_CompProjectedCurve &)) &ProjLib_HCompProjectedCurve::Set, "Sets the field of the GenHCurve2d.", py::arg("C"));
cls_ProjLib_HCompProjectedCurve.def("Curve2d", (const Adaptor2d_Curve2d & (ProjLib_HCompProjectedCurve::*)() const) &ProjLib_HCompProjectedCurve::Curve2d, "Returns the curve used to create the GenHCurve2d. This is redefined from HCurve2d, cannot be inline.");
cls_ProjLib_HCompProjectedCurve.def("ChangeCurve2d", (ProjLib_CompProjectedCurve & (ProjLib_HCompProjectedCurve::*)()) &ProjLib_HCompProjectedCurve::ChangeCurve2d, "Returns the curve used to create the GenHCurve.");
cls_ProjLib_HCompProjectedCurve.def_static("get_type_name_", (const char * (*)()) &ProjLib_HCompProjectedCurve::get_type_name, "None");
cls_ProjLib_HCompProjectedCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ProjLib_HCompProjectedCurve::get_type_descriptor, "None");
cls_ProjLib_HCompProjectedCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (ProjLib_HCompProjectedCurve::*)() const) &ProjLib_HCompProjectedCurve::DynamicType, "None");

// Enums

}