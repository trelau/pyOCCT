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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Law_BSpline.hxx>
#include <gp_Vec.hxx>
#include <GeomFill_TgtField.hxx>
#include <Standard_Type.hxx>

void bind_GeomFill_TgtField(py::module &mod){

py::class_<GeomFill_TgtField, opencascade::handle<GeomFill_TgtField>, Standard_Transient> cls_GeomFill_TgtField(mod, "GeomFill_TgtField", "Root class defining the methods we need to make an algorithmic tangents field.");

// Fields

// Methods
cls_GeomFill_TgtField.def("IsScalable", (Standard_Boolean (GeomFill_TgtField::*)() const) &GeomFill_TgtField::IsScalable, "None");
cls_GeomFill_TgtField.def("Scale", (void (GeomFill_TgtField::*)(const opencascade::handle<Law_BSpline> &)) &GeomFill_TgtField::Scale, "None", py::arg("Func"));
cls_GeomFill_TgtField.def("Value", (gp_Vec (GeomFill_TgtField::*)(const Standard_Real) const) &GeomFill_TgtField::Value, "Computes the value of the field of tangency at parameter W.", py::arg("W"));
cls_GeomFill_TgtField.def("D1", (gp_Vec (GeomFill_TgtField::*)(const Standard_Real) const) &GeomFill_TgtField::D1, "Computes the derivative of the field of tangency at parameter W.", py::arg("W"));
cls_GeomFill_TgtField.def("D1", (void (GeomFill_TgtField::*)(const Standard_Real, gp_Vec &, gp_Vec &) const) &GeomFill_TgtField::D1, "Computes the value and the derivative of the field of tangency at parameter W.", py::arg("W"), py::arg("V"), py::arg("DV"));
cls_GeomFill_TgtField.def_static("get_type_name_", (const char * (*)()) &GeomFill_TgtField::get_type_name, "None");
cls_GeomFill_TgtField.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_TgtField::get_type_descriptor, "None");
cls_GeomFill_TgtField.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_TgtField::*)() const) &GeomFill_TgtField::DynamicType, "None");

// Enums

}