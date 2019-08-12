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
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <gp_Mat.hxx>
#include <gp_Vec.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <gp_Pnt.hxx>
#include <GeomFill_LocationDraft.hxx>
#include <Standard_Type.hxx>
#include <TColgp_HArray1OfPnt2d.hxx>
#include <GeomFill_DraftTrihedron.hxx>

void bind_GeomFill_LocationDraft(py::module &mod){

py::class_<GeomFill_LocationDraft, opencascade::handle<GeomFill_LocationDraft>, GeomFill_LocationLaw> cls_GeomFill_LocationDraft(mod, "GeomFill_LocationDraft", "None");

// Constructors
cls_GeomFill_LocationDraft.def(py::init<const gp_Dir &, const Standard_Real>(), py::arg("Direction"), py::arg("Angle"));

// Fields

// Methods
cls_GeomFill_LocationDraft.def("SetStopSurf", (void (GeomFill_LocationDraft::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &GeomFill_LocationDraft::SetStopSurf, "None", py::arg("Surf"));
cls_GeomFill_LocationDraft.def("SetAngle", (void (GeomFill_LocationDraft::*)(const Standard_Real)) &GeomFill_LocationDraft::SetAngle, "None", py::arg("Angle"));
cls_GeomFill_LocationDraft.def("SetCurve", (void (GeomFill_LocationDraft::*)(const opencascade::handle<Adaptor3d_HCurve> &)) &GeomFill_LocationDraft::SetCurve, "None", py::arg("C"));
cls_GeomFill_LocationDraft.def("GetCurve", (const opencascade::handle<Adaptor3d_HCurve> & (GeomFill_LocationDraft::*)() const) &GeomFill_LocationDraft::GetCurve, "None");
cls_GeomFill_LocationDraft.def("SetTrsf", (void (GeomFill_LocationDraft::*)(const gp_Mat &)) &GeomFill_LocationDraft::SetTrsf, "None", py::arg("Transfo"));
cls_GeomFill_LocationDraft.def("Copy", (opencascade::handle<GeomFill_LocationLaw> (GeomFill_LocationDraft::*)() const) &GeomFill_LocationDraft::Copy, "None");
cls_GeomFill_LocationDraft.def("D0", (Standard_Boolean (GeomFill_LocationDraft::*)(const Standard_Real, gp_Mat &, gp_Vec &)) &GeomFill_LocationDraft::D0, "compute Location", py::arg("Param"), py::arg("M"), py::arg("V"));
cls_GeomFill_LocationDraft.def("D0", (Standard_Boolean (GeomFill_LocationDraft::*)(const Standard_Real, gp_Mat &, gp_Vec &, TColgp_Array1OfPnt2d &)) &GeomFill_LocationDraft::D0, "compute Location and 2d points", py::arg("Param"), py::arg("M"), py::arg("V"), py::arg("Poles2d"));
cls_GeomFill_LocationDraft.def("D1", (Standard_Boolean (GeomFill_LocationDraft::*)(const Standard_Real, gp_Mat &, gp_Vec &, gp_Mat &, gp_Vec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &)) &GeomFill_LocationDraft::D1, "compute location 2d points and associated first derivatives. Warning : It used only for C1 or C2 aproximation", py::arg("Param"), py::arg("M"), py::arg("V"), py::arg("DM"), py::arg("DV"), py::arg("Poles2d"), py::arg("DPoles2d"));
cls_GeomFill_LocationDraft.def("D2", (Standard_Boolean (GeomFill_LocationDraft::*)(const Standard_Real, gp_Mat &, gp_Vec &, gp_Mat &, gp_Vec &, gp_Mat &, gp_Vec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &)) &GeomFill_LocationDraft::D2, "compute location 2d points and associated first and seconde derivatives. Warning : It used only for C2 aproximation", py::arg("Param"), py::arg("M"), py::arg("V"), py::arg("DM"), py::arg("DV"), py::arg("D2M"), py::arg("D2V"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"));
cls_GeomFill_LocationDraft.def("HasFirstRestriction", (Standard_Boolean (GeomFill_LocationDraft::*)() const) &GeomFill_LocationDraft::HasFirstRestriction, "Say if the first restriction is defined in this class. If it is true the first element of poles array in D0,D1,D2... Correspond to this restriction. Returns Standard_False (default implementation)");
cls_GeomFill_LocationDraft.def("HasLastRestriction", (Standard_Boolean (GeomFill_LocationDraft::*)() const) &GeomFill_LocationDraft::HasLastRestriction, "Say if the last restriction is defined in this class. If it is true the last element of poles array in D0,D1,D2... Correspond to this restriction. Returns Standard_False (default implementation)");
cls_GeomFill_LocationDraft.def("TraceNumber", (Standard_Integer (GeomFill_LocationDraft::*)() const) &GeomFill_LocationDraft::TraceNumber, "Give the number of trace (Curves 2d wich are not restriction) Returns 1 (default implementation)");
cls_GeomFill_LocationDraft.def("NbIntervals", (Standard_Integer (GeomFill_LocationDraft::*)(const GeomAbs_Shape) const) &GeomFill_LocationDraft::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_LocationDraft.def("Intervals", (void (GeomFill_LocationDraft::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_LocationDraft::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_LocationDraft.def("SetInterval", (void (GeomFill_LocationDraft::*)(const Standard_Real, const Standard_Real)) &GeomFill_LocationDraft::SetInterval, "Sets the bounds of the parametric interval on the function This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_GeomFill_LocationDraft.def("GetInterval", [](GeomFill_LocationDraft &self, Standard_Real & First, Standard_Real & Last){ self.GetInterval(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "Gets the bounds of the parametric interval on the function", py::arg("First"), py::arg("Last"));
cls_GeomFill_LocationDraft.def("GetDomain", [](GeomFill_LocationDraft &self, Standard_Real & First, Standard_Real & Last){ self.GetDomain(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "Gets the bounds of the function parametric domain. Warning: This domain it is not modified by the SetValue method", py::arg("First"), py::arg("Last"));
cls_GeomFill_LocationDraft.def("Resolution", [](GeomFill_LocationDraft &self, const Standard_Integer Index, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(Index, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "Returns the resolutions in the sub-space 2d <Index> This information is usfull to find an good tolerance in 2d approximation. Warning: Used only if Nb2dCurve > 0", py::arg("Index"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));
cls_GeomFill_LocationDraft.def("GetMaximalNorm", (Standard_Real (GeomFill_LocationDraft::*)()) &GeomFill_LocationDraft::GetMaximalNorm, "Get the maximum Norm of the matrix-location part. It is usful to find an good Tolerance to approx M(t).");
cls_GeomFill_LocationDraft.def("GetAverageLaw", (void (GeomFill_LocationDraft::*)(gp_Mat &, gp_Vec &)) &GeomFill_LocationDraft::GetAverageLaw, "Get average value of M(t) and V(t) it is usfull to make fast approximation of rational surfaces.", py::arg("AM"), py::arg("AV"));
cls_GeomFill_LocationDraft.def("IsTranslation", [](GeomFill_LocationDraft &self, Standard_Real & Error){ Standard_Boolean rv = self.IsTranslation(Error); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Error); }, "Say if the Location Law, is an translation of Location The default implementation is ' returns False '.", py::arg("Error"));
cls_GeomFill_LocationDraft.def("IsRotation", [](GeomFill_LocationDraft &self, Standard_Real & Error){ Standard_Boolean rv = self.IsRotation(Error); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Error); }, "Say if the Location Law, is a rotation of Location The default implementation is ' returns False '.", py::arg("Error"));
cls_GeomFill_LocationDraft.def("Rotation", (void (GeomFill_LocationDraft::*)(gp_Pnt &) const) &GeomFill_LocationDraft::Rotation, "None", py::arg("Center"));
cls_GeomFill_LocationDraft.def("IsIntersec", (Standard_Boolean (GeomFill_LocationDraft::*)() const) &GeomFill_LocationDraft::IsIntersec, "Say if the generatrice interset the surface");
cls_GeomFill_LocationDraft.def("Direction", (gp_Dir (GeomFill_LocationDraft::*)() const) &GeomFill_LocationDraft::Direction, "None");
cls_GeomFill_LocationDraft.def_static("get_type_name_", (const char * (*)()) &GeomFill_LocationDraft::get_type_name, "None");
cls_GeomFill_LocationDraft.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_LocationDraft::get_type_descriptor, "None");
cls_GeomFill_LocationDraft.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_LocationDraft::*)() const) &GeomFill_LocationDraft::DynamicType, "None");

// Enums

}