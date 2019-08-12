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
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Handle.hxx>
#include <Approx_SweepFunction.hxx>
#include <Standard_Type.hxx>

void bind_Approx_SweepFunction(py::module &mod){

py::class_<Approx_SweepFunction, opencascade::handle<Approx_SweepFunction>, Standard_Transient> cls_Approx_SweepFunction(mod, "Approx_SweepFunction", "defined the function used by SweepApproximation to perform sweeping application.");

// Fields

// Methods
cls_Approx_SweepFunction.def("D0", (Standard_Boolean (Approx_SweepFunction::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &Approx_SweepFunction::D0, "compute the section for v = param", py::arg("Param"), py::arg("First"), py::arg("Last"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_Approx_SweepFunction.def("D1", (Standard_Boolean (Approx_SweepFunction::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &Approx_SweepFunction::D1, "compute the first derivative in v direction of the section for v = param Warning : It used only for C1 or C2 aproximation", py::arg("Param"), py::arg("First"), py::arg("Last"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_Approx_SweepFunction.def("D2", (Standard_Boolean (Approx_SweepFunction::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &Approx_SweepFunction::D2, "compute the second derivative in v direction of the section for v = param Warning : It used only for C2 aproximation", py::arg("Param"), py::arg("First"), py::arg("Last"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_Approx_SweepFunction.def("Nb2dCurves", (Standard_Integer (Approx_SweepFunction::*)() const) &Approx_SweepFunction::Nb2dCurves, "get the number of 2d curves to approximate.");
cls_Approx_SweepFunction.def("SectionShape", [](Approx_SweepFunction &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree){ self.SectionShape(NbPoles, NbKnots, Degree); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree); }, "get the format of an section", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"));
cls_Approx_SweepFunction.def("Knots", (void (Approx_SweepFunction::*)(TColStd_Array1OfReal &) const) &Approx_SweepFunction::Knots, "get the Knots of the section", py::arg("TKnots"));
cls_Approx_SweepFunction.def("Mults", (void (Approx_SweepFunction::*)(TColStd_Array1OfInteger &) const) &Approx_SweepFunction::Mults, "get the Multplicities of the section", py::arg("TMults"));
cls_Approx_SweepFunction.def("IsRational", (Standard_Boolean (Approx_SweepFunction::*)() const) &Approx_SweepFunction::IsRational, "Returns if the sections are rationnal or not");
cls_Approx_SweepFunction.def("NbIntervals", (Standard_Integer (Approx_SweepFunction::*)(const GeomAbs_Shape) const) &Approx_SweepFunction::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_Approx_SweepFunction.def("Intervals", (void (Approx_SweepFunction::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &Approx_SweepFunction::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_Approx_SweepFunction.def("SetInterval", (void (Approx_SweepFunction::*)(const Standard_Real, const Standard_Real)) &Approx_SweepFunction::SetInterval, "Sets the bounds of the parametric interval on the fonction This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_Approx_SweepFunction.def("Resolution", [](Approx_SweepFunction &self, const Standard_Integer Index, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(Index, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "Returns the resolutions in the sub-space 2d <Index> This information is usfull to find an good tolerance in 2d approximation.", py::arg("Index"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));
cls_Approx_SweepFunction.def("GetTolerance", (void (Approx_SweepFunction::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColStd_Array1OfReal &) const) &Approx_SweepFunction::GetTolerance, "Returns the tolerance to reach in approximation to satisfy. BoundTol error at the Boundary AngleTol tangent error at the Boundary (in radian) SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"));
cls_Approx_SweepFunction.def("SetTolerance", (void (Approx_SweepFunction::*)(const Standard_Real, const Standard_Real)) &Approx_SweepFunction::SetTolerance, "Is usefull, if (me) have to run numerical algorithm to perform D0, D1 or D2", py::arg("Tol3d"), py::arg("Tol2d"));
cls_Approx_SweepFunction.def("BarycentreOfSurf", (gp_Pnt (Approx_SweepFunction::*)() const) &Approx_SweepFunction::BarycentreOfSurf, "Get the barycentre of Surface. An very poor estimation is sufficent. This information is usefull to perform well conditioned rational approximation. Warning: Used only if <me> IsRational");
cls_Approx_SweepFunction.def("MaximalSection", (Standard_Real (Approx_SweepFunction::*)() const) &Approx_SweepFunction::MaximalSection, "Returns the length of the greater section. This information is usefull to G1's control. Warning: With an little value, approximation can be slower.");
cls_Approx_SweepFunction.def("GetMinimalWeight", (void (Approx_SweepFunction::*)(TColStd_Array1OfReal &) const) &Approx_SweepFunction::GetMinimalWeight, "Compute the minimal value of weight for each poles in all sections. This information is usefull to control error in rational approximation. Warning: Used only if <me> IsRational", py::arg("Weigths"));
cls_Approx_SweepFunction.def_static("get_type_name_", (const char * (*)()) &Approx_SweepFunction::get_type_name, "None");
cls_Approx_SweepFunction.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Approx_SweepFunction::get_type_descriptor, "None");
cls_Approx_SweepFunction.def("DynamicType", (const opencascade::handle<Standard_Type> & (Approx_SweepFunction::*)() const) &Approx_SweepFunction::DynamicType, "None");

// Enums

}