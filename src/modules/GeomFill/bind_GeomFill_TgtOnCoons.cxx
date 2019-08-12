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
#include <GeomFill_TgtField.hxx>
#include <Standard_Handle.hxx>
#include <GeomFill_CoonsAlgPatch.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Vec.hxx>
#include <GeomFill_TgtOnCoons.hxx>
#include <Standard_Type.hxx>

void bind_GeomFill_TgtOnCoons(py::module &mod){

py::class_<GeomFill_TgtOnCoons, opencascade::handle<GeomFill_TgtOnCoons>, GeomFill_TgtField> cls_GeomFill_TgtOnCoons(mod, "GeomFill_TgtOnCoons", "Defines an algorithmic tangents field on a boundary of a CoonsAlgPatch.");

// Constructors
cls_GeomFill_TgtOnCoons.def(py::init<const opencascade::handle<GeomFill_CoonsAlgPatch> &, const Standard_Integer>(), py::arg("K"), py::arg("I"));

// Fields

// Methods
cls_GeomFill_TgtOnCoons.def("Value", (gp_Vec (GeomFill_TgtOnCoons::*)(const Standard_Real) const) &GeomFill_TgtOnCoons::Value, "Computes the value of the field of tangency at parameter W.", py::arg("W"));
cls_GeomFill_TgtOnCoons.def("D1", (gp_Vec (GeomFill_TgtOnCoons::*)(const Standard_Real) const) &GeomFill_TgtOnCoons::D1, "Computes the derivative of the field of tangency at parameter W.", py::arg("W"));
cls_GeomFill_TgtOnCoons.def("D1", (void (GeomFill_TgtOnCoons::*)(const Standard_Real, gp_Vec &, gp_Vec &) const) &GeomFill_TgtOnCoons::D1, "Computes the value and the derivative of the field of tangency at parameter W.", py::arg("W"), py::arg("T"), py::arg("DT"));
cls_GeomFill_TgtOnCoons.def_static("get_type_name_", (const char * (*)()) &GeomFill_TgtOnCoons::get_type_name, "None");
cls_GeomFill_TgtOnCoons.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_TgtOnCoons::get_type_descriptor, "None");
cls_GeomFill_TgtOnCoons.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_TgtOnCoons::*)() const) &GeomFill_TgtOnCoons::DynamicType, "None");

// Enums

}