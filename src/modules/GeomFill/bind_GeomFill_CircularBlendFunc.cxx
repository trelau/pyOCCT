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
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Pnt.hxx>
#include <GeomFill_CircularBlendFunc.hxx>
#include <Standard_Type.hxx>
#include <Convert_ParameterisationType.hxx>

void bind_GeomFill_CircularBlendFunc(py::module &mod){

py::class_<GeomFill_CircularBlendFunc, opencascade::handle<GeomFill_CircularBlendFunc>, Approx_SweepFunction> cls_GeomFill_CircularBlendFunc(mod, "GeomFill_CircularBlendFunc", "Circular Blend Function to approximate by SweepApproximation from Approx");

// Constructors
cls_GeomFill_CircularBlendFunc.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real>(), py::arg("Path"), py::arg("Curve1"), py::arg("Curve2"), py::arg("Radius"));
cls_GeomFill_CircularBlendFunc.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Boolean>(), py::arg("Path"), py::arg("Curve1"), py::arg("Curve2"), py::arg("Radius"), py::arg("Polynomial"));

// Fields

// Methods
cls_GeomFill_CircularBlendFunc.def("D0", (Standard_Boolean (GeomFill_CircularBlendFunc::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &GeomFill_CircularBlendFunc::D0, "compute the section for v = param", py::arg("Param"), py::arg("First"), py::arg("Last"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_GeomFill_CircularBlendFunc.def("D1", (Standard_Boolean (GeomFill_CircularBlendFunc::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &GeomFill_CircularBlendFunc::D1, "compute the first derivative in v direction of the section for v = param", py::arg("Param"), py::arg("First"), py::arg("Last"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_GeomFill_CircularBlendFunc.def("D2", (Standard_Boolean (GeomFill_CircularBlendFunc::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &GeomFill_CircularBlendFunc::D2, "compute the second derivative in v direction of the section for v = param", py::arg("Param"), py::arg("First"), py::arg("Last"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_GeomFill_CircularBlendFunc.def("Nb2dCurves", (Standard_Integer (GeomFill_CircularBlendFunc::*)() const) &GeomFill_CircularBlendFunc::Nb2dCurves, "get the number of 2d curves to approximate.");
cls_GeomFill_CircularBlendFunc.def("SectionShape", [](GeomFill_CircularBlendFunc &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree){ self.SectionShape(NbPoles, NbKnots, Degree); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree); }, "get the format of an section", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"));
cls_GeomFill_CircularBlendFunc.def("Knots", (void (GeomFill_CircularBlendFunc::*)(TColStd_Array1OfReal &) const) &GeomFill_CircularBlendFunc::Knots, "get the Knots of the section", py::arg("TKnots"));
cls_GeomFill_CircularBlendFunc.def("Mults", (void (GeomFill_CircularBlendFunc::*)(TColStd_Array1OfInteger &) const) &GeomFill_CircularBlendFunc::Mults, "get the Multplicities of the section", py::arg("TMults"));
cls_GeomFill_CircularBlendFunc.def("IsRational", (Standard_Boolean (GeomFill_CircularBlendFunc::*)() const) &GeomFill_CircularBlendFunc::IsRational, "Returns if the section is rationnal or not");
cls_GeomFill_CircularBlendFunc.def("NbIntervals", (Standard_Integer (GeomFill_CircularBlendFunc::*)(const GeomAbs_Shape) const) &GeomFill_CircularBlendFunc::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_CircularBlendFunc.def("Intervals", (void (GeomFill_CircularBlendFunc::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_CircularBlendFunc::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_CircularBlendFunc.def("SetInterval", (void (GeomFill_CircularBlendFunc::*)(const Standard_Real, const Standard_Real)) &GeomFill_CircularBlendFunc::SetInterval, "Sets the bounds of the parametric interval on the fonction This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_GeomFill_CircularBlendFunc.def("GetTolerance", (void (GeomFill_CircularBlendFunc::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColStd_Array1OfReal &) const) &GeomFill_CircularBlendFunc::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary (in radian) SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"));
cls_GeomFill_CircularBlendFunc.def("SetTolerance", (void (GeomFill_CircularBlendFunc::*)(const Standard_Real, const Standard_Real)) &GeomFill_CircularBlendFunc::SetTolerance, "Is usfull, if (me) have to be run numerical algorithme to perform D0, D1 or D2", py::arg("Tol3d"), py::arg("Tol2d"));
cls_GeomFill_CircularBlendFunc.def("BarycentreOfSurf", (gp_Pnt (GeomFill_CircularBlendFunc::*)() const) &GeomFill_CircularBlendFunc::BarycentreOfSurf, "Get the barycentre of Surface. An very poor estimation is sufficent. This information is usefull to perform well conditionned rational approximation.");
cls_GeomFill_CircularBlendFunc.def("MaximalSection", (Standard_Real (GeomFill_CircularBlendFunc::*)() const) &GeomFill_CircularBlendFunc::MaximalSection, "Returns the length of the maximum section. This information is usefull to perform well conditionned rational approximation.");
cls_GeomFill_CircularBlendFunc.def("GetMinimalWeight", (void (GeomFill_CircularBlendFunc::*)(TColStd_Array1OfReal &) const) &GeomFill_CircularBlendFunc::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections. This information is usefull to perform well conditionned rational approximation.", py::arg("Weigths"));
cls_GeomFill_CircularBlendFunc.def_static("get_type_name_", (const char * (*)()) &GeomFill_CircularBlendFunc::get_type_name, "None");
cls_GeomFill_CircularBlendFunc.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_CircularBlendFunc::get_type_descriptor, "None");
cls_GeomFill_CircularBlendFunc.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_CircularBlendFunc::*)() const) &GeomFill_CircularBlendFunc::DynamicType, "None");

// Enums

}