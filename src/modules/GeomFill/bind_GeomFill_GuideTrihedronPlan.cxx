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
#include <GeomFill_TrihedronWithGuide.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <GeomFill_TrihedronLaw.hxx>
#include <GeomFill_PipeError.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Vec.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <GeomFill_GuideTrihedronPlan.hxx>
#include <Standard_Type.hxx>
#include <TColgp_HArray2OfPnt2d.hxx>
#include <math_Vector.hxx>
#include <GeomFill_Frenet.hxx>

void bind_GeomFill_GuideTrihedronPlan(py::module &mod){

py::class_<GeomFill_GuideTrihedronPlan, opencascade::handle<GeomFill_GuideTrihedronPlan>, GeomFill_TrihedronWithGuide> cls_GeomFill_GuideTrihedronPlan(mod, "GeomFill_GuideTrihedronPlan", "Trihedron in the case of sweeping along a guide curve defined by the orthogonal plan on the trajectory");

// Constructors
cls_GeomFill_GuideTrihedronPlan.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("theGuide"));

// Fields

// Methods
cls_GeomFill_GuideTrihedronPlan.def("SetCurve", (void (GeomFill_GuideTrihedronPlan::*)(const opencascade::handle<Adaptor3d_HCurve> &)) &GeomFill_GuideTrihedronPlan::SetCurve, "None", py::arg("thePath"));
cls_GeomFill_GuideTrihedronPlan.def("Copy", (opencascade::handle<GeomFill_TrihedronLaw> (GeomFill_GuideTrihedronPlan::*)() const) &GeomFill_GuideTrihedronPlan::Copy, "None");
cls_GeomFill_GuideTrihedronPlan.def("ErrorStatus", (GeomFill_PipeError (GeomFill_GuideTrihedronPlan::*)() const) &GeomFill_GuideTrihedronPlan::ErrorStatus, "Give a status to the Law Returns PipeOk (default implementation)");
cls_GeomFill_GuideTrihedronPlan.def("Guide", (opencascade::handle<Adaptor3d_HCurve> (GeomFill_GuideTrihedronPlan::*)() const) &GeomFill_GuideTrihedronPlan::Guide, "None");
cls_GeomFill_GuideTrihedronPlan.def("D0", (Standard_Boolean (GeomFill_GuideTrihedronPlan::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_GuideTrihedronPlan::D0, "None", py::arg("Param"), py::arg("Tangent"), py::arg("Normal"), py::arg("BiNormal"));
cls_GeomFill_GuideTrihedronPlan.def("D1", (Standard_Boolean (GeomFill_GuideTrihedronPlan::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_GuideTrihedronPlan::D1, "None", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("BiNormal"), py::arg("DBiNormal"));
cls_GeomFill_GuideTrihedronPlan.def("D2", (Standard_Boolean (GeomFill_GuideTrihedronPlan::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_GuideTrihedronPlan::D2, "None", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("D2Tangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("D2Normal"), py::arg("BiNormal"), py::arg("DBiNormal"), py::arg("D2BiNormal"));
cls_GeomFill_GuideTrihedronPlan.def("SetInterval", (void (GeomFill_GuideTrihedronPlan::*)(const Standard_Real, const Standard_Real)) &GeomFill_GuideTrihedronPlan::SetInterval, "Sets the bounds of the parametric interval on the function This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_GeomFill_GuideTrihedronPlan.def("NbIntervals", (Standard_Integer (GeomFill_GuideTrihedronPlan::*)(const GeomAbs_Shape) const) &GeomFill_GuideTrihedronPlan::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_GuideTrihedronPlan.def("Intervals", (void (GeomFill_GuideTrihedronPlan::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_GuideTrihedronPlan::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_GuideTrihedronPlan.def("GetAverageLaw", (void (GeomFill_GuideTrihedronPlan::*)(gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_GuideTrihedronPlan::GetAverageLaw, "Get average value of M(t) and V(t) it is usfull to make fast approximation of rational surfaces.", py::arg("ATangent"), py::arg("ANormal"), py::arg("ABiNormal"));
cls_GeomFill_GuideTrihedronPlan.def("IsConstant", (Standard_Boolean (GeomFill_GuideTrihedronPlan::*)() const) &GeomFill_GuideTrihedronPlan::IsConstant, "Say if the law is Constant");
cls_GeomFill_GuideTrihedronPlan.def("IsOnlyBy3dCurve", (Standard_Boolean (GeomFill_GuideTrihedronPlan::*)() const) &GeomFill_GuideTrihedronPlan::IsOnlyBy3dCurve, "Say if the law is defined, only by the 3d Geometry of the setted Curve Return False by Default.");
cls_GeomFill_GuideTrihedronPlan.def("Origine", (void (GeomFill_GuideTrihedronPlan::*)(const Standard_Real, const Standard_Real)) &GeomFill_GuideTrihedronPlan::Origine, "None", py::arg("OrACR1"), py::arg("OrACR2"));
cls_GeomFill_GuideTrihedronPlan.def_static("get_type_name_", (const char * (*)()) &GeomFill_GuideTrihedronPlan::get_type_name, "None");
cls_GeomFill_GuideTrihedronPlan.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_GuideTrihedronPlan::get_type_descriptor, "None");
cls_GeomFill_GuideTrihedronPlan.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_GuideTrihedronPlan::*)() const) &GeomFill_GuideTrihedronPlan::DynamicType, "None");

// Enums

}