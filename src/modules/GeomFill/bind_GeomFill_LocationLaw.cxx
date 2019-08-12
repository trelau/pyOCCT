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
#include <Adaptor3d_HCurve.hxx>
#include <gp_Mat.hxx>
#include <GeomFill_LocationLaw.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Vec.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <GeomFill_PipeError.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Type.hxx>

void bind_GeomFill_LocationLaw(py::module &mod){

py::class_<GeomFill_LocationLaw, opencascade::handle<GeomFill_LocationLaw>, Standard_Transient> cls_GeomFill_LocationLaw(mod, "GeomFill_LocationLaw", "To define location law in Sweeping location is -- defined by an Matrix M and an Vector V, and transform an point P in MP+V.");

// Fields

// Methods
cls_GeomFill_LocationLaw.def("SetCurve", (void (GeomFill_LocationLaw::*)(const opencascade::handle<Adaptor3d_HCurve> &)) &GeomFill_LocationLaw::SetCurve, "None", py::arg("C"));
cls_GeomFill_LocationLaw.def("GetCurve", (const opencascade::handle<Adaptor3d_HCurve> & (GeomFill_LocationLaw::*)() const) &GeomFill_LocationLaw::GetCurve, "None");
cls_GeomFill_LocationLaw.def("SetTrsf", (void (GeomFill_LocationLaw::*)(const gp_Mat &)) &GeomFill_LocationLaw::SetTrsf, "Set a transformation Matrix like the law M(t) become Mat * M(t)", py::arg("Transfo"));
cls_GeomFill_LocationLaw.def("Copy", (opencascade::handle<GeomFill_LocationLaw> (GeomFill_LocationLaw::*)() const) &GeomFill_LocationLaw::Copy, "None");
cls_GeomFill_LocationLaw.def("D0", (Standard_Boolean (GeomFill_LocationLaw::*)(const Standard_Real, gp_Mat &, gp_Vec &)) &GeomFill_LocationLaw::D0, "compute Location", py::arg("Param"), py::arg("M"), py::arg("V"));
cls_GeomFill_LocationLaw.def("D0", (Standard_Boolean (GeomFill_LocationLaw::*)(const Standard_Real, gp_Mat &, gp_Vec &, TColgp_Array1OfPnt2d &)) &GeomFill_LocationLaw::D0, "compute Location and 2d points", py::arg("Param"), py::arg("M"), py::arg("V"), py::arg("Poles2d"));
cls_GeomFill_LocationLaw.def("D1", (Standard_Boolean (GeomFill_LocationLaw::*)(const Standard_Real, gp_Mat &, gp_Vec &, gp_Mat &, gp_Vec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &)) &GeomFill_LocationLaw::D1, "compute location 2d points and associated first derivatives. Warning : It used only for C1 or C2 aproximation", py::arg("Param"), py::arg("M"), py::arg("V"), py::arg("DM"), py::arg("DV"), py::arg("Poles2d"), py::arg("DPoles2d"));
cls_GeomFill_LocationLaw.def("D2", (Standard_Boolean (GeomFill_LocationLaw::*)(const Standard_Real, gp_Mat &, gp_Vec &, gp_Mat &, gp_Vec &, gp_Mat &, gp_Vec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &)) &GeomFill_LocationLaw::D2, "compute location 2d points and associated first and seconde derivatives. Warning : It used only for C2 aproximation", py::arg("Param"), py::arg("M"), py::arg("V"), py::arg("DM"), py::arg("DV"), py::arg("D2M"), py::arg("D2V"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"));
cls_GeomFill_LocationLaw.def("Nb2dCurves", (Standard_Integer (GeomFill_LocationLaw::*)() const) &GeomFill_LocationLaw::Nb2dCurves, "get the number of 2d curves (Restrictions + Traces) to approximate.");
cls_GeomFill_LocationLaw.def("HasFirstRestriction", (Standard_Boolean (GeomFill_LocationLaw::*)() const) &GeomFill_LocationLaw::HasFirstRestriction, "Say if the first restriction is defined in this class. If it is true the first element of poles array in D0,D1,D2... Correspond to this restriction. Returns Standard_False (default implementation)");
cls_GeomFill_LocationLaw.def("HasLastRestriction", (Standard_Boolean (GeomFill_LocationLaw::*)() const) &GeomFill_LocationLaw::HasLastRestriction, "Say if the last restriction is defined in this class. If it is true the last element of poles array in D0,D1,D2... Correspond to this restriction. Returns Standard_False (default implementation)");
cls_GeomFill_LocationLaw.def("TraceNumber", (Standard_Integer (GeomFill_LocationLaw::*)() const) &GeomFill_LocationLaw::TraceNumber, "Give the number of trace (Curves 2d wich are not restriction) Returns 0 (default implementation)");
cls_GeomFill_LocationLaw.def("ErrorStatus", (GeomFill_PipeError (GeomFill_LocationLaw::*)() const) &GeomFill_LocationLaw::ErrorStatus, "Give a status to the Law Returns PipeOk (default implementation)");
cls_GeomFill_LocationLaw.def("NbIntervals", (Standard_Integer (GeomFill_LocationLaw::*)(const GeomAbs_Shape) const) &GeomFill_LocationLaw::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_LocationLaw.def("Intervals", (void (GeomFill_LocationLaw::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_LocationLaw::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_LocationLaw.def("SetInterval", (void (GeomFill_LocationLaw::*)(const Standard_Real, const Standard_Real)) &GeomFill_LocationLaw::SetInterval, "Sets the bounds of the parametric interval on the function This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_GeomFill_LocationLaw.def("GetInterval", [](GeomFill_LocationLaw &self, Standard_Real & First, Standard_Real & Last){ self.GetInterval(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "Gets the bounds of the parametric interval on the function", py::arg("First"), py::arg("Last"));
cls_GeomFill_LocationLaw.def("GetDomain", [](GeomFill_LocationLaw &self, Standard_Real & First, Standard_Real & Last){ self.GetDomain(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "Gets the bounds of the function parametric domain. Warning: This domain it is not modified by the SetValue method", py::arg("First"), py::arg("Last"));
cls_GeomFill_LocationLaw.def("Resolution", [](GeomFill_LocationLaw &self, const Standard_Integer Index, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(Index, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "Returns the resolutions in the sub-space 2d <Index> This information is usfull to find an good tolerance in 2d approximation.", py::arg("Index"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));
cls_GeomFill_LocationLaw.def("SetTolerance", (void (GeomFill_LocationLaw::*)(const Standard_Real, const Standard_Real)) &GeomFill_LocationLaw::SetTolerance, "Is usefull, if (me) have to run numerical algorithm to perform D0, D1 or D2 The default implementation make nothing.", py::arg("Tol3d"), py::arg("Tol2d"));
cls_GeomFill_LocationLaw.def("GetMaximalNorm", (Standard_Real (GeomFill_LocationLaw::*)()) &GeomFill_LocationLaw::GetMaximalNorm, "Get the maximum Norm of the matrix-location part. It is usful to find an good Tolerance to approx M(t).");
cls_GeomFill_LocationLaw.def("GetAverageLaw", (void (GeomFill_LocationLaw::*)(gp_Mat &, gp_Vec &)) &GeomFill_LocationLaw::GetAverageLaw, "Get average value of M(t) and V(t) it is usfull to make fast approximation of rational surfaces.", py::arg("AM"), py::arg("AV"));
cls_GeomFill_LocationLaw.def("IsTranslation", [](GeomFill_LocationLaw &self, Standard_Real & Error){ Standard_Boolean rv = self.IsTranslation(Error); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Error); }, "Say if the Location Law, is an translation of Location The default implementation is ' returns False '.", py::arg("Error"));
cls_GeomFill_LocationLaw.def("IsRotation", [](GeomFill_LocationLaw &self, Standard_Real & Error){ Standard_Boolean rv = self.IsRotation(Error); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Error); }, "Say if the Location Law, is a rotation of Location The default implementation is ' returns False '.", py::arg("Error"));
cls_GeomFill_LocationLaw.def("Rotation", (void (GeomFill_LocationLaw::*)(gp_Pnt &) const) &GeomFill_LocationLaw::Rotation, "None", py::arg("Center"));
cls_GeomFill_LocationLaw.def_static("get_type_name_", (const char * (*)()) &GeomFill_LocationLaw::get_type_name, "None");
cls_GeomFill_LocationLaw.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_LocationLaw::get_type_descriptor, "None");
cls_GeomFill_LocationLaw.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_LocationLaw::*)() const) &GeomFill_LocationLaw::DynamicType, "None");

// Enums

}