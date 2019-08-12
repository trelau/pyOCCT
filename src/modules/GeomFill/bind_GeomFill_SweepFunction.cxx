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
#include <Approx_SweepFunction.hxx>
#include <Standard_Handle.hxx>
#include <GeomFill_SectionLaw.hxx>
#include <GeomFill_LocationLaw.hxx>
#include <Standard_TypeDef.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Pnt.hxx>
#include <GeomFill_SweepFunction.hxx>
#include <Standard_Type.hxx>
#include <gp_Mat.hxx>
#include <gp_Vec.hxx>

void bind_GeomFill_SweepFunction(py::module &mod){

py::class_<GeomFill_SweepFunction, opencascade::handle<GeomFill_SweepFunction>, Approx_SweepFunction> cls_GeomFill_SweepFunction(mod, "GeomFill_SweepFunction", "Function to approximate by SweepApproximation from Approx. To bulid general sweep Surface.");

// Constructors
cls_GeomFill_SweepFunction.def(py::init<const opencascade::handle<GeomFill_SectionLaw> &, const opencascade::handle<GeomFill_LocationLaw> &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Section"), py::arg("Location"), py::arg("FirstParameter"), py::arg("FirstParameterOnS"), py::arg("RatioParameterOnS"));

// Fields

// Methods
cls_GeomFill_SweepFunction.def("D0", (Standard_Boolean (GeomFill_SweepFunction::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &GeomFill_SweepFunction::D0, "compute the section for v = param", py::arg("Param"), py::arg("First"), py::arg("Last"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_GeomFill_SweepFunction.def("D1", (Standard_Boolean (GeomFill_SweepFunction::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &GeomFill_SweepFunction::D1, "compute the first derivative in v direction of the section for v = param", py::arg("Param"), py::arg("First"), py::arg("Last"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_GeomFill_SweepFunction.def("D2", (Standard_Boolean (GeomFill_SweepFunction::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &GeomFill_SweepFunction::D2, "compute the second derivative in v direction of the section for v = param", py::arg("Param"), py::arg("First"), py::arg("Last"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_GeomFill_SweepFunction.def("Nb2dCurves", (Standard_Integer (GeomFill_SweepFunction::*)() const) &GeomFill_SweepFunction::Nb2dCurves, "get the number of 2d curves to approximate.");
cls_GeomFill_SweepFunction.def("SectionShape", [](GeomFill_SweepFunction &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree){ self.SectionShape(NbPoles, NbKnots, Degree); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree); }, "get the format of an section", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"));
cls_GeomFill_SweepFunction.def("Knots", (void (GeomFill_SweepFunction::*)(TColStd_Array1OfReal &) const) &GeomFill_SweepFunction::Knots, "get the Knots of the section", py::arg("TKnots"));
cls_GeomFill_SweepFunction.def("Mults", (void (GeomFill_SweepFunction::*)(TColStd_Array1OfInteger &) const) &GeomFill_SweepFunction::Mults, "get the Multplicities of the section", py::arg("TMults"));
cls_GeomFill_SweepFunction.def("IsRational", (Standard_Boolean (GeomFill_SweepFunction::*)() const) &GeomFill_SweepFunction::IsRational, "Returns if the section is rationnal or not");
cls_GeomFill_SweepFunction.def("NbIntervals", (Standard_Integer (GeomFill_SweepFunction::*)(const GeomAbs_Shape) const) &GeomFill_SweepFunction::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_SweepFunction.def("Intervals", (void (GeomFill_SweepFunction::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_SweepFunction::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_SweepFunction.def("SetInterval", (void (GeomFill_SweepFunction::*)(const Standard_Real, const Standard_Real)) &GeomFill_SweepFunction::SetInterval, "Sets the bounds of the parametric interval on the function This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_GeomFill_SweepFunction.def("Resolution", [](GeomFill_SweepFunction &self, const Standard_Integer Index, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(Index, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "Returns the resolutions in the sub-space 2d <Index> This information is usfull to find an good tolerance in 2d approximation. Warning: Used only if Nb2dCurve > 0", py::arg("Index"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));
cls_GeomFill_SweepFunction.def("GetTolerance", (void (GeomFill_SweepFunction::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColStd_Array1OfReal &) const) &GeomFill_SweepFunction::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary (in radian) SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"));
cls_GeomFill_SweepFunction.def("SetTolerance", (void (GeomFill_SweepFunction::*)(const Standard_Real, const Standard_Real)) &GeomFill_SweepFunction::SetTolerance, "Is usfull, if (me) have to be run numerical algorithme to perform D0, D1 or D2", py::arg("Tol3d"), py::arg("Tol2d"));
cls_GeomFill_SweepFunction.def("BarycentreOfSurf", (gp_Pnt (GeomFill_SweepFunction::*)() const) &GeomFill_SweepFunction::BarycentreOfSurf, "Get the barycentre of Surface. An very poor estimation is sufficent. This information is usefull to perform well conditionned rational approximation. Warning: Used only if <me> IsRational");
cls_GeomFill_SweepFunction.def("MaximalSection", (Standard_Real (GeomFill_SweepFunction::*)() const) &GeomFill_SweepFunction::MaximalSection, "Returns the length of the maximum section. This information is usefull to perform well conditionned rational approximation.");
cls_GeomFill_SweepFunction.def("GetMinimalWeight", (void (GeomFill_SweepFunction::*)(TColStd_Array1OfReal &) const) &GeomFill_SweepFunction::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections. This information is usefull to perform well conditionned rational approximation. Warning: Used only if <me> IsRational", py::arg("Weigths"));
cls_GeomFill_SweepFunction.def_static("get_type_name_", (const char * (*)()) &GeomFill_SweepFunction::get_type_name, "None");
cls_GeomFill_SweepFunction.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_SweepFunction::get_type_descriptor, "None");
cls_GeomFill_SweepFunction.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_SweepFunction::*)() const) &GeomFill_SweepFunction::DynamicType, "None");

// Enums

}