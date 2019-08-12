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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <gp_Vec.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <GeomFill_Trihedron.hxx>
#include <GeomFill_CorrectedFrenet.hxx>
#include <Standard_Type.hxx>
#include <Law_Function.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <TColgp_SequenceOfVec.hxx>
#include <GeomFill_Frenet.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColgp_HArray1OfVec.hxx>

void bind_GeomFill_CorrectedFrenet(py::module &mod){

py::class_<GeomFill_CorrectedFrenet, opencascade::handle<GeomFill_CorrectedFrenet>, GeomFill_TrihedronLaw> cls_GeomFill_CorrectedFrenet(mod, "GeomFill_CorrectedFrenet", "Defined an Corrected Frenet Trihedron Law It is like Frenet with an Torsion's minimization");

// Constructors
cls_GeomFill_CorrectedFrenet.def(py::init<>());
cls_GeomFill_CorrectedFrenet.def(py::init<const Standard_Boolean>(), py::arg("ForEvaluation"));

// Fields

// Methods
cls_GeomFill_CorrectedFrenet.def("Copy", (opencascade::handle<GeomFill_TrihedronLaw> (GeomFill_CorrectedFrenet::*)() const) &GeomFill_CorrectedFrenet::Copy, "None");
cls_GeomFill_CorrectedFrenet.def("SetCurve", (void (GeomFill_CorrectedFrenet::*)(const opencascade::handle<Adaptor3d_HCurve> &)) &GeomFill_CorrectedFrenet::SetCurve, "None", py::arg("C"));
cls_GeomFill_CorrectedFrenet.def("SetInterval", (void (GeomFill_CorrectedFrenet::*)(const Standard_Real, const Standard_Real)) &GeomFill_CorrectedFrenet::SetInterval, "None", py::arg("First"), py::arg("Last"));
cls_GeomFill_CorrectedFrenet.def("D0", (Standard_Boolean (GeomFill_CorrectedFrenet::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_CorrectedFrenet::D0, "compute Triedrhon on curve at parameter <Param>", py::arg("Param"), py::arg("Tangent"), py::arg("Normal"), py::arg("BiNormal"));
cls_GeomFill_CorrectedFrenet.def("D1", (Standard_Boolean (GeomFill_CorrectedFrenet::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_CorrectedFrenet::D1, "compute Triedrhon and derivative Trihedron on curve at parameter <Param> Warning : It used only for C1 or C2 aproximation", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("BiNormal"), py::arg("DBiNormal"));
cls_GeomFill_CorrectedFrenet.def("D2", (Standard_Boolean (GeomFill_CorrectedFrenet::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_CorrectedFrenet::D2, "compute Trihedron on curve first and seconde derivatives. Warning : It used only for C2 aproximation", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("D2Tangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("D2Normal"), py::arg("BiNormal"), py::arg("DBiNormal"), py::arg("D2BiNormal"));
cls_GeomFill_CorrectedFrenet.def("NbIntervals", (Standard_Integer (GeomFill_CorrectedFrenet::*)(const GeomAbs_Shape) const) &GeomFill_CorrectedFrenet::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_CorrectedFrenet.def("Intervals", (void (GeomFill_CorrectedFrenet::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_CorrectedFrenet::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_CorrectedFrenet.def("EvaluateBestMode", (GeomFill_Trihedron (GeomFill_CorrectedFrenet::*)()) &GeomFill_CorrectedFrenet::EvaluateBestMode, "Tries to define the best trihedron mode for the curve. It can be: - Frenet - CorrectedFrenet - DiscreteTrihedron Warning: the CorrectedFrenet must be constructed with option ForEvaluation = True, the curve must be set by method SetCurve.");
cls_GeomFill_CorrectedFrenet.def("GetAverageLaw", (void (GeomFill_CorrectedFrenet::*)(gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_CorrectedFrenet::GetAverageLaw, "Get average value of Tangent(t) and Normal(t) it is usfull to make fast approximation of rational surfaces.", py::arg("ATangent"), py::arg("ANormal"), py::arg("ABiNormal"));
cls_GeomFill_CorrectedFrenet.def("IsConstant", (Standard_Boolean (GeomFill_CorrectedFrenet::*)() const) &GeomFill_CorrectedFrenet::IsConstant, "Say if the law is Constant.");
cls_GeomFill_CorrectedFrenet.def("IsOnlyBy3dCurve", (Standard_Boolean (GeomFill_CorrectedFrenet::*)() const) &GeomFill_CorrectedFrenet::IsOnlyBy3dCurve, "Return True.");
cls_GeomFill_CorrectedFrenet.def_static("get_type_name_", (const char * (*)()) &GeomFill_CorrectedFrenet::get_type_name, "None");
cls_GeomFill_CorrectedFrenet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_CorrectedFrenet::get_type_descriptor, "None");
cls_GeomFill_CorrectedFrenet.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_CorrectedFrenet::*)() const) &GeomFill_CorrectedFrenet::DynamicType, "None");

// Enums

}