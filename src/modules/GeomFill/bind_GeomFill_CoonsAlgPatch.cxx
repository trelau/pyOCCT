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
#include <Standard_Handle.hxx>
#include <GeomFill_Boundary.hxx>
#include <Law_Function.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Vec.hxx>
#include <GeomFill_CoonsAlgPatch.hxx>
#include <Standard_Type.hxx>

void bind_GeomFill_CoonsAlgPatch(py::module &mod){

py::class_<GeomFill_CoonsAlgPatch, opencascade::handle<GeomFill_CoonsAlgPatch>, Standard_Transient> cls_GeomFill_CoonsAlgPatch(mod, "GeomFill_CoonsAlgPatch", "Provides evaluation methods on an algorithmic patch (based on 4 Curves) defined by its boundaries and blending functions.");

// Constructors
cls_GeomFill_CoonsAlgPatch.def(py::init<const opencascade::handle<GeomFill_Boundary> &, const opencascade::handle<GeomFill_Boundary> &, const opencascade::handle<GeomFill_Boundary> &, const opencascade::handle<GeomFill_Boundary> &>(), py::arg("B1"), py::arg("B2"), py::arg("B3"), py::arg("B4"));

// Fields

// Methods
cls_GeomFill_CoonsAlgPatch.def("Func", (void (GeomFill_CoonsAlgPatch::*)(opencascade::handle<Law_Function> &, opencascade::handle<Law_Function> &) const) &GeomFill_CoonsAlgPatch::Func, "Give the blending functions.", py::arg("f1"), py::arg("f2"));
cls_GeomFill_CoonsAlgPatch.def("SetFunc", (void (GeomFill_CoonsAlgPatch::*)(const opencascade::handle<Law_Function> &, const opencascade::handle<Law_Function> &)) &GeomFill_CoonsAlgPatch::SetFunc, "Set the blending functions.", py::arg("f1"), py::arg("f2"));
cls_GeomFill_CoonsAlgPatch.def("Value", (gp_Pnt (GeomFill_CoonsAlgPatch::*)(const Standard_Real, const Standard_Real) const) &GeomFill_CoonsAlgPatch::Value, "Computes the value on the algorithmic patch at parameters U and V.", py::arg("U"), py::arg("V"));
cls_GeomFill_CoonsAlgPatch.def("D1U", (gp_Vec (GeomFill_CoonsAlgPatch::*)(const Standard_Real, const Standard_Real) const) &GeomFill_CoonsAlgPatch::D1U, "Computes the d/dU partial derivative on the algorithmic patch at parameters U and V.", py::arg("U"), py::arg("V"));
cls_GeomFill_CoonsAlgPatch.def("D1V", (gp_Vec (GeomFill_CoonsAlgPatch::*)(const Standard_Real, const Standard_Real) const) &GeomFill_CoonsAlgPatch::D1V, "Computes the d/dV partial derivative on the algorithmic patch at parameters U and V.", py::arg("U"), py::arg("V"));
cls_GeomFill_CoonsAlgPatch.def("DUV", (gp_Vec (GeomFill_CoonsAlgPatch::*)(const Standard_Real, const Standard_Real) const) &GeomFill_CoonsAlgPatch::DUV, "Computes the d2/dUdV partial derivative on the algorithmic patch made with linear blending functions at parameter U and V.", py::arg("U"), py::arg("V"));
cls_GeomFill_CoonsAlgPatch.def("Corner", (const gp_Pnt & (GeomFill_CoonsAlgPatch::*)(const Standard_Integer) const) &GeomFill_CoonsAlgPatch::Corner, "None", py::arg("I"));
cls_GeomFill_CoonsAlgPatch.def("Bound", (const opencascade::handle<GeomFill_Boundary> & (GeomFill_CoonsAlgPatch::*)(const Standard_Integer) const) &GeomFill_CoonsAlgPatch::Bound, "None", py::arg("I"));
cls_GeomFill_CoonsAlgPatch.def("Func", (const opencascade::handle<Law_Function> & (GeomFill_CoonsAlgPatch::*)(const Standard_Integer) const) &GeomFill_CoonsAlgPatch::Func, "None", py::arg("I"));
cls_GeomFill_CoonsAlgPatch.def_static("get_type_name_", (const char * (*)()) &GeomFill_CoonsAlgPatch::get_type_name, "None");
cls_GeomFill_CoonsAlgPatch.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_CoonsAlgPatch::get_type_descriptor, "None");
cls_GeomFill_CoonsAlgPatch.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_CoonsAlgPatch::*)() const) &GeomFill_CoonsAlgPatch::DynamicType, "None");

// Enums

}