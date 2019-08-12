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
#include <Standard_TypeDef.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Pnt.hxx>
#include <Blend_AppFunction.hxx>
#include <math_Vector.hxx>
#include <Blend_Point.hxx>
#include <Standard_Handle.hxx>
#include <BRepBlend_AppFuncRoot.hxx>
#include <Standard_Type.hxx>
#include <BRepBlend_Line.hxx>

void bind_BRepBlend_AppFuncRoot(py::module &mod){

py::class_<BRepBlend_AppFuncRoot, opencascade::handle<BRepBlend_AppFuncRoot>, Approx_SweepFunction> cls_BRepBlend_AppFuncRoot(mod, "BRepBlend_AppFuncRoot", "Function to approximate by AppSurface");

// Fields

// Methods
cls_BRepBlend_AppFuncRoot.def("D0", (Standard_Boolean (BRepBlend_AppFuncRoot::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BRepBlend_AppFuncRoot::D0, "compute the section for v = param", py::arg("Param"), py::arg("First"), py::arg("Last"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_BRepBlend_AppFuncRoot.def("D1", (Standard_Boolean (BRepBlend_AppFuncRoot::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BRepBlend_AppFuncRoot::D1, "compute the first derivative in v direction of the section for v = param", py::arg("Param"), py::arg("First"), py::arg("Last"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_BRepBlend_AppFuncRoot.def("D2", (Standard_Boolean (BRepBlend_AppFuncRoot::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BRepBlend_AppFuncRoot::D2, "compute the second derivative in v direction of the section for v = param", py::arg("Param"), py::arg("First"), py::arg("Last"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_BRepBlend_AppFuncRoot.def("Nb2dCurves", (Standard_Integer (BRepBlend_AppFuncRoot::*)() const) &BRepBlend_AppFuncRoot::Nb2dCurves, "get the number of 2d curves to approximate.");
cls_BRepBlend_AppFuncRoot.def("SectionShape", [](BRepBlend_AppFuncRoot &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree){ self.SectionShape(NbPoles, NbKnots, Degree); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree); }, "get the format of an section", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"));
cls_BRepBlend_AppFuncRoot.def("Knots", (void (BRepBlend_AppFuncRoot::*)(TColStd_Array1OfReal &) const) &BRepBlend_AppFuncRoot::Knots, "get the Knots of the section", py::arg("TKnots"));
cls_BRepBlend_AppFuncRoot.def("Mults", (void (BRepBlend_AppFuncRoot::*)(TColStd_Array1OfInteger &) const) &BRepBlend_AppFuncRoot::Mults, "get the Multplicities of the section", py::arg("TMults"));
cls_BRepBlend_AppFuncRoot.def("IsRational", (Standard_Boolean (BRepBlend_AppFuncRoot::*)() const) &BRepBlend_AppFuncRoot::IsRational, "Returns if the section is rationnal or not");
cls_BRepBlend_AppFuncRoot.def("NbIntervals", (Standard_Integer (BRepBlend_AppFuncRoot::*)(const GeomAbs_Shape) const) &BRepBlend_AppFuncRoot::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_BRepBlend_AppFuncRoot.def("Intervals", (void (BRepBlend_AppFuncRoot::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &BRepBlend_AppFuncRoot::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_BRepBlend_AppFuncRoot.def("SetInterval", (void (BRepBlend_AppFuncRoot::*)(const Standard_Real, const Standard_Real)) &BRepBlend_AppFuncRoot::SetInterval, "Sets the bounds of the parametric interval on the fonction This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_BRepBlend_AppFuncRoot.def("Resolution", [](BRepBlend_AppFuncRoot &self, const Standard_Integer Index, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(Index, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "Returns the resolutions in the sub-space 2d <Index> -- This information is usfull to find an good tolerance in 2d approximation", py::arg("Index"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));
cls_BRepBlend_AppFuncRoot.def("GetTolerance", (void (BRepBlend_AppFuncRoot::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColStd_Array1OfReal &) const) &BRepBlend_AppFuncRoot::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary (in radian) SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"));
cls_BRepBlend_AppFuncRoot.def("SetTolerance", (void (BRepBlend_AppFuncRoot::*)(const Standard_Real, const Standard_Real)) &BRepBlend_AppFuncRoot::SetTolerance, "Is usfull, if (me) have to be run numerical algorithme to perform D0, D1 or D2", py::arg("Tol3d"), py::arg("Tol2d"));
cls_BRepBlend_AppFuncRoot.def("BarycentreOfSurf", (gp_Pnt (BRepBlend_AppFuncRoot::*)() const) &BRepBlend_AppFuncRoot::BarycentreOfSurf, "Get the barycentre of Surface. An very poor estimation is sufficent. This information is usefull to perform well conditionned rational approximation.");
cls_BRepBlend_AppFuncRoot.def("MaximalSection", (Standard_Real (BRepBlend_AppFuncRoot::*)() const) &BRepBlend_AppFuncRoot::MaximalSection, "Returns the length of the maximum section. This information is usefull to perform well conditionned rational approximation.");
cls_BRepBlend_AppFuncRoot.def("GetMinimalWeight", (void (BRepBlend_AppFuncRoot::*)(TColStd_Array1OfReal &) const) &BRepBlend_AppFuncRoot::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections. This information is usefull to perform well conditionned rational approximation.", py::arg("Weigths"));
cls_BRepBlend_AppFuncRoot.def("Point", (void (BRepBlend_AppFuncRoot::*)(const Blend_AppFunction &, const Standard_Real, const math_Vector &, Blend_Point &) const) &BRepBlend_AppFuncRoot::Point, "None", py::arg("Func"), py::arg("Param"), py::arg("Sol"), py::arg("Pnt"));
cls_BRepBlend_AppFuncRoot.def("Vec", (void (BRepBlend_AppFuncRoot::*)(math_Vector &, const Blend_Point &) const) &BRepBlend_AppFuncRoot::Vec, "None", py::arg("Sol"), py::arg("Pnt"));
cls_BRepBlend_AppFuncRoot.def_static("get_type_name_", (const char * (*)()) &BRepBlend_AppFuncRoot::get_type_name, "None");
cls_BRepBlend_AppFuncRoot.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepBlend_AppFuncRoot::get_type_descriptor, "None");
cls_BRepBlend_AppFuncRoot.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepBlend_AppFuncRoot::*)() const) &BRepBlend_AppFuncRoot::DynamicType, "None");

// Enums

}