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
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <Standard_Handle.hxx>
#include <GeomEvaluator_Curve.hxx>
#include <Standard_Type.hxx>

void bind_GeomEvaluator_Curve(py::module &mod){

py::class_<GeomEvaluator_Curve, opencascade::handle<GeomEvaluator_Curve>, Standard_Transient> cls_GeomEvaluator_Curve(mod, "GeomEvaluator_Curve", "Interface for calculation of values and derivatives for different kinds of curves in 3D. Works both with adaptors and curves.");

// Fields

// Methods
cls_GeomEvaluator_Curve.def("D0", (void (GeomEvaluator_Curve::*)(const Standard_Real, gp_Pnt &) const) &GeomEvaluator_Curve::D0, "Value of 3D curve", py::arg("theU"), py::arg("theValue"));
cls_GeomEvaluator_Curve.def("D1", (void (GeomEvaluator_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &GeomEvaluator_Curve::D1, "Value and first derivatives of curve", py::arg("theU"), py::arg("theValue"), py::arg("theD1"));
cls_GeomEvaluator_Curve.def("D2", (void (GeomEvaluator_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &GeomEvaluator_Curve::D2, "Value, first and second derivatives of curve", py::arg("theU"), py::arg("theValue"), py::arg("theD1"), py::arg("theD2"));
cls_GeomEvaluator_Curve.def("D3", (void (GeomEvaluator_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &GeomEvaluator_Curve::D3, "Value, first, second and third derivatives of curve", py::arg("theU"), py::arg("theValue"), py::arg("theD1"), py::arg("theD2"), py::arg("theD3"));
cls_GeomEvaluator_Curve.def("DN", (gp_Vec (GeomEvaluator_Curve::*)(const Standard_Real, const Standard_Integer) const) &GeomEvaluator_Curve::DN, "Calculates N-th derivatives of curve, where N = theDerU. Raises if N < 1", py::arg("theU"), py::arg("theDerU"));
cls_GeomEvaluator_Curve.def_static("get_type_name_", (const char * (*)()) &GeomEvaluator_Curve::get_type_name, "None");
cls_GeomEvaluator_Curve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomEvaluator_Curve::get_type_descriptor, "None");
cls_GeomEvaluator_Curve.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomEvaluator_Curve::*)() const) &GeomEvaluator_Curve::DynamicType, "None");

// Enums

}