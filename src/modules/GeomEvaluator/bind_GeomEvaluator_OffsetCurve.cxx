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
#include <GeomEvaluator_Curve.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Dir.hxx>
#include <GeomAdaptor_HCurve.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <GeomEvaluator_OffsetCurve.hxx>
#include <Standard_Type.hxx>

void bind_GeomEvaluator_OffsetCurve(py::module &mod){

py::class_<GeomEvaluator_OffsetCurve, opencascade::handle<GeomEvaluator_OffsetCurve>, GeomEvaluator_Curve> cls_GeomEvaluator_OffsetCurve(mod, "GeomEvaluator_OffsetCurve", "Allows to calculate values and derivatives for offset curves in 3D");

// Constructors
cls_GeomEvaluator_OffsetCurve.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const gp_Dir &>(), py::arg("theBase"), py::arg("theOffset"), py::arg("theDirection"));
cls_GeomEvaluator_OffsetCurve.def(py::init<const opencascade::handle<GeomAdaptor_HCurve> &, const Standard_Real, const gp_Dir &>(), py::arg("theBase"), py::arg("theOffset"), py::arg("theDirection"));

// Fields

// Methods
cls_GeomEvaluator_OffsetCurve.def("SetOffsetValue", (void (GeomEvaluator_OffsetCurve::*)(Standard_Real)) &GeomEvaluator_OffsetCurve::SetOffsetValue, "Change the offset value", py::arg("theOffset"));
cls_GeomEvaluator_OffsetCurve.def("SetOffsetDirection", (void (GeomEvaluator_OffsetCurve::*)(const gp_Dir &)) &GeomEvaluator_OffsetCurve::SetOffsetDirection, "None", py::arg("theDirection"));
cls_GeomEvaluator_OffsetCurve.def("D0", (void (GeomEvaluator_OffsetCurve::*)(const Standard_Real, gp_Pnt &) const) &GeomEvaluator_OffsetCurve::D0, "Value of curve", py::arg("theU"), py::arg("theValue"));
cls_GeomEvaluator_OffsetCurve.def("D1", (void (GeomEvaluator_OffsetCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &GeomEvaluator_OffsetCurve::D1, "Value and first derivatives of curve", py::arg("theU"), py::arg("theValue"), py::arg("theD1"));
cls_GeomEvaluator_OffsetCurve.def("D2", (void (GeomEvaluator_OffsetCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &GeomEvaluator_OffsetCurve::D2, "Value, first and second derivatives of curve", py::arg("theU"), py::arg("theValue"), py::arg("theD1"), py::arg("theD2"));
cls_GeomEvaluator_OffsetCurve.def("D3", (void (GeomEvaluator_OffsetCurve::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &GeomEvaluator_OffsetCurve::D3, "Value, first, second and third derivatives of curve", py::arg("theU"), py::arg("theValue"), py::arg("theD1"), py::arg("theD2"), py::arg("theD3"));
cls_GeomEvaluator_OffsetCurve.def("DN", (gp_Vec (GeomEvaluator_OffsetCurve::*)(const Standard_Real, const Standard_Integer) const) &GeomEvaluator_OffsetCurve::DN, "Calculates N-th derivatives of curve, where N = theDeriv. Raises if N < 1", py::arg("theU"), py::arg("theDeriv"));
cls_GeomEvaluator_OffsetCurve.def_static("get_type_name_", (const char * (*)()) &GeomEvaluator_OffsetCurve::get_type_name, "None");
cls_GeomEvaluator_OffsetCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomEvaluator_OffsetCurve::get_type_descriptor, "None");
cls_GeomEvaluator_OffsetCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomEvaluator_OffsetCurve::*)() const) &GeomEvaluator_OffsetCurve::DynamicType, "None");

// Enums

}