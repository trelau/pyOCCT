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
#include <Standard_TypeDef.hxx>
#include <gp_Vec.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <GeomFill_GuideTrihedronAC.hxx>
#include <Standard_Type.hxx>
#include <Approx_CurvlinFunc.hxx>

void bind_GeomFill_GuideTrihedronAC(py::module &mod){

py::class_<GeomFill_GuideTrihedronAC, opencascade::handle<GeomFill_GuideTrihedronAC>, GeomFill_TrihedronWithGuide> cls_GeomFill_GuideTrihedronAC(mod, "GeomFill_GuideTrihedronAC", "Trihedron in the case of a sweeping along a guide curve. defined by curviline absciss");

// Constructors
cls_GeomFill_GuideTrihedronAC.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("guide"));

// Fields

// Methods
cls_GeomFill_GuideTrihedronAC.def("SetCurve", (void (GeomFill_GuideTrihedronAC::*)(const opencascade::handle<Adaptor3d_HCurve> &)) &GeomFill_GuideTrihedronAC::SetCurve, "None", py::arg("C"));
cls_GeomFill_GuideTrihedronAC.def("Copy", (opencascade::handle<GeomFill_TrihedronLaw> (GeomFill_GuideTrihedronAC::*)() const) &GeomFill_GuideTrihedronAC::Copy, "None");
cls_GeomFill_GuideTrihedronAC.def("Guide", (opencascade::handle<Adaptor3d_HCurve> (GeomFill_GuideTrihedronAC::*)() const) &GeomFill_GuideTrihedronAC::Guide, "None");
cls_GeomFill_GuideTrihedronAC.def("D0", (Standard_Boolean (GeomFill_GuideTrihedronAC::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_GuideTrihedronAC::D0, "None", py::arg("Param"), py::arg("Tangent"), py::arg("Normal"), py::arg("BiNormal"));
cls_GeomFill_GuideTrihedronAC.def("D1", (Standard_Boolean (GeomFill_GuideTrihedronAC::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_GuideTrihedronAC::D1, "None", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("BiNormal"), py::arg("DBiNormal"));
cls_GeomFill_GuideTrihedronAC.def("D2", (Standard_Boolean (GeomFill_GuideTrihedronAC::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_GuideTrihedronAC::D2, "None", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("D2Tangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("D2Normal"), py::arg("BiNormal"), py::arg("DBiNormal"), py::arg("D2BiNormal"));
cls_GeomFill_GuideTrihedronAC.def("NbIntervals", (Standard_Integer (GeomFill_GuideTrihedronAC::*)(const GeomAbs_Shape) const) &GeomFill_GuideTrihedronAC::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_GuideTrihedronAC.def("Intervals", (void (GeomFill_GuideTrihedronAC::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_GuideTrihedronAC::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_GuideTrihedronAC.def("SetInterval", (void (GeomFill_GuideTrihedronAC::*)(const Standard_Real, const Standard_Real)) &GeomFill_GuideTrihedronAC::SetInterval, "Sets the bounds of the parametric interval on the function This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_GeomFill_GuideTrihedronAC.def("GetAverageLaw", (void (GeomFill_GuideTrihedronAC::*)(gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_GuideTrihedronAC::GetAverageLaw, "Get average value of M(t) and V(t) it is usfull to make fast approximation of rational surfaces.", py::arg("ATangent"), py::arg("ANormal"), py::arg("ABiNormal"));
cls_GeomFill_GuideTrihedronAC.def("IsConstant", (Standard_Boolean (GeomFill_GuideTrihedronAC::*)() const) &GeomFill_GuideTrihedronAC::IsConstant, "Say if the law is Constant");
cls_GeomFill_GuideTrihedronAC.def("IsOnlyBy3dCurve", (Standard_Boolean (GeomFill_GuideTrihedronAC::*)() const) &GeomFill_GuideTrihedronAC::IsOnlyBy3dCurve, "Say if the law is defined, only by the 3d Geometry of the setted Curve Return False by Default.");
cls_GeomFill_GuideTrihedronAC.def("Origine", (void (GeomFill_GuideTrihedronAC::*)(const Standard_Real, const Standard_Real)) &GeomFill_GuideTrihedronAC::Origine, "None", py::arg("OrACR1"), py::arg("OrACR2"));
cls_GeomFill_GuideTrihedronAC.def_static("get_type_name_", (const char * (*)()) &GeomFill_GuideTrihedronAC::get_type_name, "None");
cls_GeomFill_GuideTrihedronAC.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_GuideTrihedronAC::get_type_descriptor, "None");
cls_GeomFill_GuideTrihedronAC.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_GuideTrihedronAC::*)() const) &GeomFill_GuideTrihedronAC::DynamicType, "None");

// Enums

}