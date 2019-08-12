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
#include <GeomFill_TrihedronLaw.hxx>
#include <Standard_Handle.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Vec.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <GeomFill_Darboux.hxx>
#include <Standard_Type.hxx>

void bind_GeomFill_Darboux(py::module &mod){

py::class_<GeomFill_Darboux, opencascade::handle<GeomFill_Darboux>, GeomFill_TrihedronLaw> cls_GeomFill_Darboux(mod, "GeomFill_Darboux", "Defines Darboux case of Frenet Trihedron Law");

// Constructors
cls_GeomFill_Darboux.def(py::init<>());

// Fields

// Methods
cls_GeomFill_Darboux.def("Copy", (opencascade::handle<GeomFill_TrihedronLaw> (GeomFill_Darboux::*)() const) &GeomFill_Darboux::Copy, "None");
cls_GeomFill_Darboux.def("D0", (Standard_Boolean (GeomFill_Darboux::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_Darboux::D0, "compute Triedrhon on curve at parameter <Param>", py::arg("Param"), py::arg("Tangent"), py::arg("Normal"), py::arg("BiNormal"));
cls_GeomFill_Darboux.def("D1", (Standard_Boolean (GeomFill_Darboux::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_Darboux::D1, "compute Triedrhon and derivative Trihedron on curve at parameter <Param> Warning : It used only for C1 or C2 aproximation", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("BiNormal"), py::arg("DBiNormal"));
cls_GeomFill_Darboux.def("D2", (Standard_Boolean (GeomFill_Darboux::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_Darboux::D2, "compute Trihedron on curve first and seconde derivatives. Warning : It used only for C2 aproximation", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("D2Tangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("D2Normal"), py::arg("BiNormal"), py::arg("DBiNormal"), py::arg("D2BiNormal"));
cls_GeomFill_Darboux.def("NbIntervals", (Standard_Integer (GeomFill_Darboux::*)(const GeomAbs_Shape) const) &GeomFill_Darboux::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_Darboux.def("Intervals", (void (GeomFill_Darboux::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_Darboux::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_Darboux.def("GetAverageLaw", (void (GeomFill_Darboux::*)(gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_Darboux::GetAverageLaw, "Get average value of Tangent(t) and Normal(t) it is usfull to make fast approximation of rational surfaces.", py::arg("ATangent"), py::arg("ANormal"), py::arg("ABiNormal"));
cls_GeomFill_Darboux.def("IsConstant", (Standard_Boolean (GeomFill_Darboux::*)() const) &GeomFill_Darboux::IsConstant, "Say if the law is Constant.");
cls_GeomFill_Darboux.def("IsOnlyBy3dCurve", (Standard_Boolean (GeomFill_Darboux::*)() const) &GeomFill_Darboux::IsOnlyBy3dCurve, "Return False.");
cls_GeomFill_Darboux.def_static("get_type_name_", (const char * (*)()) &GeomFill_Darboux::get_type_name, "None");
cls_GeomFill_Darboux.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_Darboux::get_type_descriptor, "None");
cls_GeomFill_Darboux.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_Darboux::*)() const) &GeomFill_Darboux::DynamicType, "None");

// Enums

}