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
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom2dEvaluator_Curve.hxx>
#include <Standard_Type.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom2dAdaptor_HCurve.hxx>
#include <Geom2dEvaluator_OffsetCurve.hxx>

PYBIND11_MODULE(Geom2dEvaluator, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.Geom2dAdaptor");

// CLASS: GEOM2DEVALUATOR_CURVE
py::class_<Geom2dEvaluator_Curve, opencascade::handle<Geom2dEvaluator_Curve>, Standard_Transient> cls_Geom2dEvaluator_Curve(mod, "Geom2dEvaluator_Curve", "Interface for calculation of values and derivatives for different kinds of curves in 2D. Works both with adaptors and curves.");

// Methods
cls_Geom2dEvaluator_Curve.def("D0", (void (Geom2dEvaluator_Curve::*)(const Standard_Real, gp_Pnt2d &) const) &Geom2dEvaluator_Curve::D0, "Value of 2D curve", py::arg("theU"), py::arg("theValue"));
cls_Geom2dEvaluator_Curve.def("D1", (void (Geom2dEvaluator_Curve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const) &Geom2dEvaluator_Curve::D1, "Value and first derivatives of curve", py::arg("theU"), py::arg("theValue"), py::arg("theD1"));
cls_Geom2dEvaluator_Curve.def("D2", (void (Geom2dEvaluator_Curve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const) &Geom2dEvaluator_Curve::D2, "Value, first and second derivatives of curve", py::arg("theU"), py::arg("theValue"), py::arg("theD1"), py::arg("theD2"));
cls_Geom2dEvaluator_Curve.def("D3", (void (Geom2dEvaluator_Curve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const) &Geom2dEvaluator_Curve::D3, "Value, first, second and third derivatives of curve", py::arg("theU"), py::arg("theValue"), py::arg("theD1"), py::arg("theD2"), py::arg("theD3"));
cls_Geom2dEvaluator_Curve.def("DN", (gp_Vec2d (Geom2dEvaluator_Curve::*)(const Standard_Real, const Standard_Integer) const) &Geom2dEvaluator_Curve::DN, "Calculates N-th derivatives of curve, where N = theDerU. Raises if N < 1", py::arg("theU"), py::arg("theDerU"));
cls_Geom2dEvaluator_Curve.def_static("get_type_name_", (const char * (*)()) &Geom2dEvaluator_Curve::get_type_name, "None");
cls_Geom2dEvaluator_Curve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom2dEvaluator_Curve::get_type_descriptor, "None");
cls_Geom2dEvaluator_Curve.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom2dEvaluator_Curve::*)() const) &Geom2dEvaluator_Curve::DynamicType, "None");

// CLASS: GEOM2DEVALUATOR_OFFSETCURVE
py::class_<Geom2dEvaluator_OffsetCurve, opencascade::handle<Geom2dEvaluator_OffsetCurve>, Geom2dEvaluator_Curve> cls_Geom2dEvaluator_OffsetCurve(mod, "Geom2dEvaluator_OffsetCurve", "Allows to calculate values and derivatives for offset curves in 2D");

// Constructors
cls_Geom2dEvaluator_OffsetCurve.def(py::init<const opencascade::handle<Geom2d_Curve> &, const Standard_Real>(), py::arg("theBase"), py::arg("theOffset"));
cls_Geom2dEvaluator_OffsetCurve.def(py::init<const opencascade::handle<Geom2dAdaptor_HCurve> &, const Standard_Real>(), py::arg("theBase"), py::arg("theOffset"));

// Methods
cls_Geom2dEvaluator_OffsetCurve.def("SetOffsetValue", (void (Geom2dEvaluator_OffsetCurve::*)(Standard_Real)) &Geom2dEvaluator_OffsetCurve::SetOffsetValue, "Change the offset value", py::arg("theOffset"));
cls_Geom2dEvaluator_OffsetCurve.def("D0", (void (Geom2dEvaluator_OffsetCurve::*)(const Standard_Real, gp_Pnt2d &) const) &Geom2dEvaluator_OffsetCurve::D0, "Value of curve", py::arg("theU"), py::arg("theValue"));
cls_Geom2dEvaluator_OffsetCurve.def("D1", (void (Geom2dEvaluator_OffsetCurve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &) const) &Geom2dEvaluator_OffsetCurve::D1, "Value and first derivatives of curve", py::arg("theU"), py::arg("theValue"), py::arg("theD1"));
cls_Geom2dEvaluator_OffsetCurve.def("D2", (void (Geom2dEvaluator_OffsetCurve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &) const) &Geom2dEvaluator_OffsetCurve::D2, "Value, first and second derivatives of curve", py::arg("theU"), py::arg("theValue"), py::arg("theD1"), py::arg("theD2"));
cls_Geom2dEvaluator_OffsetCurve.def("D3", (void (Geom2dEvaluator_OffsetCurve::*)(const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &) const) &Geom2dEvaluator_OffsetCurve::D3, "Value, first, second and third derivatives of curve", py::arg("theU"), py::arg("theValue"), py::arg("theD1"), py::arg("theD2"), py::arg("theD3"));
cls_Geom2dEvaluator_OffsetCurve.def("DN", (gp_Vec2d (Geom2dEvaluator_OffsetCurve::*)(const Standard_Real, const Standard_Integer) const) &Geom2dEvaluator_OffsetCurve::DN, "Calculates N-th derivatives of curve, where N = theDeriv. Raises if N < 1", py::arg("theU"), py::arg("theDeriv"));
cls_Geom2dEvaluator_OffsetCurve.def_static("get_type_name_", (const char * (*)()) &Geom2dEvaluator_OffsetCurve::get_type_name, "None");
cls_Geom2dEvaluator_OffsetCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom2dEvaluator_OffsetCurve::get_type_descriptor, "None");
cls_Geom2dEvaluator_OffsetCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom2dEvaluator_OffsetCurve::*)() const) &Geom2dEvaluator_OffsetCurve::DynamicType, "None");


}
