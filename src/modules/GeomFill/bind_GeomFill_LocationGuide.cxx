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
#include <GeomFill_LocationLaw.hxx>
#include <Standard_Handle.hxx>
#include <GeomFill_TrihedronWithGuide.hxx>
#include <GeomFill_SectionLaw.hxx>
#include <Standard_TypeDef.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <gp_Mat.hxx>
#include <gp_Vec.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <GeomFill_PipeError.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <gp_Pnt.hxx>
#include <Geom_Curve.hxx>
#include <TColgp_HArray1OfPnt2d.hxx>
#include <GeomFill_LocationGuide.hxx>
#include <Standard_Type.hxx>
#include <TColgp_HArray2OfPnt2d.hxx>
#include <math_Vector.hxx>

void bind_GeomFill_LocationGuide(py::module &mod){

py::class_<GeomFill_LocationGuide, opencascade::handle<GeomFill_LocationGuide>, GeomFill_LocationLaw> cls_GeomFill_LocationGuide(mod, "GeomFill_LocationGuide", "None");

// Constructors
cls_GeomFill_LocationGuide.def(py::init<const opencascade::handle<GeomFill_TrihedronWithGuide> &>(), py::arg("Triedre"));

// Fields

// Methods
cls_GeomFill_LocationGuide.def("Set", [](GeomFill_LocationGuide &self, const opencascade::handle<GeomFill_SectionLaw> & Section, const Standard_Boolean rotat, const Standard_Real SFirst, const Standard_Real SLast, const Standard_Real PrecAngle, Standard_Real & LastAngle){ self.Set(Section, rotat, SFirst, SLast, PrecAngle, LastAngle); return LastAngle; }, "None", py::arg("Section"), py::arg("rotat"), py::arg("SFirst"), py::arg("SLast"), py::arg("PrecAngle"), py::arg("LastAngle"));
cls_GeomFill_LocationGuide.def("EraseRotation", (void (GeomFill_LocationGuide::*)()) &GeomFill_LocationGuide::EraseRotation, "None");
cls_GeomFill_LocationGuide.def("SetCurve", (void (GeomFill_LocationGuide::*)(const opencascade::handle<Adaptor3d_HCurve> &)) &GeomFill_LocationGuide::SetCurve, "None", py::arg("C"));
cls_GeomFill_LocationGuide.def("GetCurve", (const opencascade::handle<Adaptor3d_HCurve> & (GeomFill_LocationGuide::*)() const) &GeomFill_LocationGuide::GetCurve, "None");
cls_GeomFill_LocationGuide.def("SetTrsf", (void (GeomFill_LocationGuide::*)(const gp_Mat &)) &GeomFill_LocationGuide::SetTrsf, "None", py::arg("Transfo"));
cls_GeomFill_LocationGuide.def("Copy", (opencascade::handle<GeomFill_LocationLaw> (GeomFill_LocationGuide::*)() const) &GeomFill_LocationGuide::Copy, "None");
cls_GeomFill_LocationGuide.def("D0", (Standard_Boolean (GeomFill_LocationGuide::*)(const Standard_Real, gp_Mat &, gp_Vec &)) &GeomFill_LocationGuide::D0, "compute Location", py::arg("Param"), py::arg("M"), py::arg("V"));
cls_GeomFill_LocationGuide.def("D0", (Standard_Boolean (GeomFill_LocationGuide::*)(const Standard_Real, gp_Mat &, gp_Vec &, TColgp_Array1OfPnt2d &)) &GeomFill_LocationGuide::D0, "compute Location and 2d points", py::arg("Param"), py::arg("M"), py::arg("V"), py::arg("Poles2d"));
cls_GeomFill_LocationGuide.def("D1", (Standard_Boolean (GeomFill_LocationGuide::*)(const Standard_Real, gp_Mat &, gp_Vec &, gp_Mat &, gp_Vec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &)) &GeomFill_LocationGuide::D1, "compute location 2d points and associated first derivatives. Warning : It used only for C1 or C2 aproximation", py::arg("Param"), py::arg("M"), py::arg("V"), py::arg("DM"), py::arg("DV"), py::arg("Poles2d"), py::arg("DPoles2d"));
cls_GeomFill_LocationGuide.def("D2", (Standard_Boolean (GeomFill_LocationGuide::*)(const Standard_Real, gp_Mat &, gp_Vec &, gp_Mat &, gp_Vec &, gp_Mat &, gp_Vec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &)) &GeomFill_LocationGuide::D2, "compute location 2d points and associated first and seconde derivatives. Warning : It used only for C2 aproximation", py::arg("Param"), py::arg("M"), py::arg("V"), py::arg("DM"), py::arg("DV"), py::arg("D2M"), py::arg("D2V"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"));
cls_GeomFill_LocationGuide.def("HasFirstRestriction", (Standard_Boolean (GeomFill_LocationGuide::*)() const) &GeomFill_LocationGuide::HasFirstRestriction, "Say if the first restriction is defined in this class. If it is true the first element of poles array in D0,D1,D2... Correspond to this restriction. Returns Standard_False (default implementation)");
cls_GeomFill_LocationGuide.def("HasLastRestriction", (Standard_Boolean (GeomFill_LocationGuide::*)() const) &GeomFill_LocationGuide::HasLastRestriction, "Say if the last restriction is defined in this class. If it is true the last element of poles array in D0,D1,D2... Correspond to this restriction. Returns Standard_False (default implementation)");
cls_GeomFill_LocationGuide.def("TraceNumber", (Standard_Integer (GeomFill_LocationGuide::*)() const) &GeomFill_LocationGuide::TraceNumber, "Give the number of trace (Curves 2d wich are not restriction) Returns 1 (default implementation)");
cls_GeomFill_LocationGuide.def("ErrorStatus", (GeomFill_PipeError (GeomFill_LocationGuide::*)() const) &GeomFill_LocationGuide::ErrorStatus, "Give a status to the Law Returns PipeOk (default implementation)");
cls_GeomFill_LocationGuide.def("NbIntervals", (Standard_Integer (GeomFill_LocationGuide::*)(const GeomAbs_Shape) const) &GeomFill_LocationGuide::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_LocationGuide.def("Intervals", (void (GeomFill_LocationGuide::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_LocationGuide::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_LocationGuide.def("SetInterval", (void (GeomFill_LocationGuide::*)(const Standard_Real, const Standard_Real)) &GeomFill_LocationGuide::SetInterval, "Sets the bounds of the parametric interval on the function This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_GeomFill_LocationGuide.def("GetInterval", [](GeomFill_LocationGuide &self, Standard_Real & First, Standard_Real & Last){ self.GetInterval(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "Gets the bounds of the parametric interval on the function", py::arg("First"), py::arg("Last"));
cls_GeomFill_LocationGuide.def("GetDomain", [](GeomFill_LocationGuide &self, Standard_Real & First, Standard_Real & Last){ self.GetDomain(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "Gets the bounds of the function parametric domain. Warning: This domain it is not modified by the SetValue method", py::arg("First"), py::arg("Last"));
cls_GeomFill_LocationGuide.def("SetTolerance", (void (GeomFill_LocationGuide::*)(const Standard_Real, const Standard_Real)) &GeomFill_LocationGuide::SetTolerance, "Is usefull, if (me) have to run numerical algorithm to perform D0, D1 or D2 The default implementation make nothing.", py::arg("Tol3d"), py::arg("Tol2d"));
cls_GeomFill_LocationGuide.def("Resolution", [](GeomFill_LocationGuide &self, const Standard_Integer Index, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(Index, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "Returns the resolutions in the sub-space 2d <Index> This information is usfull to find an good tolerance in 2d approximation. Warning: Used only if Nb2dCurve > 0", py::arg("Index"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));
cls_GeomFill_LocationGuide.def("GetMaximalNorm", (Standard_Real (GeomFill_LocationGuide::*)()) &GeomFill_LocationGuide::GetMaximalNorm, "Get the maximum Norm of the matrix-location part. It is usful to find an good Tolerance to approx M(t).");
cls_GeomFill_LocationGuide.def("GetAverageLaw", (void (GeomFill_LocationGuide::*)(gp_Mat &, gp_Vec &)) &GeomFill_LocationGuide::GetAverageLaw, "Get average value of M(t) and V(t) it is usfull to make fast approximation of rational surfaces.", py::arg("AM"), py::arg("AV"));
cls_GeomFill_LocationGuide.def("IsTranslation", [](GeomFill_LocationGuide &self, Standard_Real & Error){ Standard_Boolean rv = self.IsTranslation(Error); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Error); }, "Say if the Location Law, is an translation of Location The default implementation is ' returns False '.", py::arg("Error"));
cls_GeomFill_LocationGuide.def("IsRotation", [](GeomFill_LocationGuide &self, Standard_Real & Error){ Standard_Boolean rv = self.IsRotation(Error); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Error); }, "Say if the Location Law, is a rotation of Location The default implementation is ' returns False '.", py::arg("Error"));
cls_GeomFill_LocationGuide.def("Rotation", (void (GeomFill_LocationGuide::*)(gp_Pnt &) const) &GeomFill_LocationGuide::Rotation, "None", py::arg("Center"));
cls_GeomFill_LocationGuide.def("Section", (opencascade::handle<Geom_Curve> (GeomFill_LocationGuide::*)() const) &GeomFill_LocationGuide::Section, "None");
cls_GeomFill_LocationGuide.def("Guide", (opencascade::handle<Adaptor3d_HCurve> (GeomFill_LocationGuide::*)() const) &GeomFill_LocationGuide::Guide, "None");
cls_GeomFill_LocationGuide.def("SetOrigine", (void (GeomFill_LocationGuide::*)(const Standard_Real, const Standard_Real)) &GeomFill_LocationGuide::SetOrigine, "None", py::arg("Param1"), py::arg("Param2"));
cls_GeomFill_LocationGuide.def("ComputeAutomaticLaw", (GeomFill_PipeError (GeomFill_LocationGuide::*)(opencascade::handle<TColgp_HArray1OfPnt2d> &) const) &GeomFill_LocationGuide::ComputeAutomaticLaw, "None", py::arg("ParAndRad"));
cls_GeomFill_LocationGuide.def_static("get_type_name_", (const char * (*)()) &GeomFill_LocationGuide::get_type_name, "None");
cls_GeomFill_LocationGuide.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_LocationGuide::get_type_descriptor, "None");
cls_GeomFill_LocationGuide.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_LocationGuide::*)() const) &GeomFill_LocationGuide::DynamicType, "None");

// Enums

}