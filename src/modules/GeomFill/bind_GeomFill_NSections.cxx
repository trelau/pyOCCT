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
#include <GeomFill_SectionLaw.hxx>
#include <TColGeom_SequenceOfCurve.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomFill_SequenceOfTrsf.hxx>
#include <Standard_Handle.hxx>
#include <Geom_BSplineSurface.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Pnt.hxx>
#include <Geom_Curve.hxx>
#include <GeomFill_NSections.hxx>
#include <Standard_Type.hxx>

void bind_GeomFill_NSections(py::module &mod){

py::class_<GeomFill_NSections, opencascade::handle<GeomFill_NSections>, GeomFill_SectionLaw> cls_GeomFill_NSections(mod, "GeomFill_NSections", "Define a Section Law by N Sections");

// Constructors
cls_GeomFill_NSections.def(py::init<const TColGeom_SequenceOfCurve &>(), py::arg("NC"));
cls_GeomFill_NSections.def(py::init<const TColGeom_SequenceOfCurve &, const TColStd_SequenceOfReal &>(), py::arg("NC"), py::arg("NP"));
// cls_GeomFill_NSections.def(py::init<const TColGeom_SequenceOfCurve &, const TColStd_SequenceOfReal &, const Standard_Real, const Standard_Real>(), py::arg("NC"), py::arg("NP"), py::arg("UF"), py::arg("UL"));
cls_GeomFill_NSections.def(py::init<const TColGeom_SequenceOfCurve &, const TColStd_SequenceOfReal &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("NC"), py::arg("NP"), py::arg("UF"), py::arg("UL"), py::arg("VF"), py::arg("VL"));
cls_GeomFill_NSections.def(py::init<const TColGeom_SequenceOfCurve &, const GeomFill_SequenceOfTrsf &, const TColStd_SequenceOfReal &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_BSplineSurface> &>(), py::arg("NC"), py::arg("Trsfs"), py::arg("NP"), py::arg("UF"), py::arg("UL"), py::arg("VF"), py::arg("VL"), py::arg("Surf"));

// Fields

// Methods
cls_GeomFill_NSections.def("D0", (Standard_Boolean (GeomFill_NSections::*)(const Standard_Real, TColgp_Array1OfPnt &, TColStd_Array1OfReal &)) &GeomFill_NSections::D0, "compute the section for v = param", py::arg("Param"), py::arg("Poles"), py::arg("Weigths"));
cls_GeomFill_NSections.def("D1", (Standard_Boolean (GeomFill_NSections::*)(const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &GeomFill_NSections::D1, "compute the first derivative in v direction of the section for v = param Warning : It used only for C1 or C2 aproximation", py::arg("Param"), py::arg("Poles"), py::arg("DPoles"), py::arg("Weigths"), py::arg("DWeigths"));
cls_GeomFill_NSections.def("D2", (Standard_Boolean (GeomFill_NSections::*)(const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &GeomFill_NSections::D2, "compute the second derivative in v direction of the section for v = param Warning : It used only for C2 aproximation", py::arg("Param"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_GeomFill_NSections.def("SetSurface", (void (GeomFill_NSections::*)(const opencascade::handle<Geom_BSplineSurface> &)) &GeomFill_NSections::SetSurface, "Sets the reference surface", py::arg("RefSurf"));
cls_GeomFill_NSections.def("ComputeSurface", (void (GeomFill_NSections::*)()) &GeomFill_NSections::ComputeSurface, "Computes the surface");
cls_GeomFill_NSections.def("BSplineSurface", (opencascade::handle<Geom_BSplineSurface> (GeomFill_NSections::*)() const) &GeomFill_NSections::BSplineSurface, "give if possible an bspline Surface, like iso-v are the section. If it is not possible this methode have to get an Null Surface. Is it the default implementation.");
cls_GeomFill_NSections.def("SectionShape", [](GeomFill_NSections &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree){ self.SectionShape(NbPoles, NbKnots, Degree); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree); }, "get the format of an section", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"));
cls_GeomFill_NSections.def("Knots", (void (GeomFill_NSections::*)(TColStd_Array1OfReal &) const) &GeomFill_NSections::Knots, "get the Knots of the section", py::arg("TKnots"));
cls_GeomFill_NSections.def("Mults", (void (GeomFill_NSections::*)(TColStd_Array1OfInteger &) const) &GeomFill_NSections::Mults, "get the Multplicities of the section", py::arg("TMults"));
cls_GeomFill_NSections.def("IsRational", (Standard_Boolean (GeomFill_NSections::*)() const) &GeomFill_NSections::IsRational, "Returns if the sections are rationnal or not");
cls_GeomFill_NSections.def("IsUPeriodic", (Standard_Boolean (GeomFill_NSections::*)() const) &GeomFill_NSections::IsUPeriodic, "Returns if the sections are periodic or not");
cls_GeomFill_NSections.def("IsVPeriodic", (Standard_Boolean (GeomFill_NSections::*)() const) &GeomFill_NSections::IsVPeriodic, "Returns if the law isperiodic or not");
cls_GeomFill_NSections.def("NbIntervals", (Standard_Integer (GeomFill_NSections::*)(const GeomAbs_Shape) const) &GeomFill_NSections::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_NSections.def("Intervals", (void (GeomFill_NSections::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_NSections::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_NSections.def("SetInterval", (void (GeomFill_NSections::*)(const Standard_Real, const Standard_Real)) &GeomFill_NSections::SetInterval, "Sets the bounds of the parametric interval on the function This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_GeomFill_NSections.def("GetInterval", [](GeomFill_NSections &self, Standard_Real & First, Standard_Real & Last){ self.GetInterval(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "Gets the bounds of the parametric interval on the function", py::arg("First"), py::arg("Last"));
cls_GeomFill_NSections.def("GetDomain", [](GeomFill_NSections &self, Standard_Real & First, Standard_Real & Last){ self.GetDomain(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "Gets the bounds of the function parametric domain. Warning: This domain it is not modified by the SetValue method", py::arg("First"), py::arg("Last"));
cls_GeomFill_NSections.def("GetTolerance", (void (GeomFill_NSections::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColStd_Array1OfReal &) const) &GeomFill_NSections::GetTolerance, "Returns the tolerances associated at each poles to reach in approximation, to satisfy: BoundTol error at the Boundary AngleTol tangent error at the Boundary (in radian) SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"));
cls_GeomFill_NSections.def("BarycentreOfSurf", (gp_Pnt (GeomFill_NSections::*)() const) &GeomFill_NSections::BarycentreOfSurf, "Get the barycentre of Surface. An very poor estimation is sufficent. This information is usefull to perform well conditioned rational approximation. Warning: Used only if <me> IsRational");
cls_GeomFill_NSections.def("MaximalSection", (Standard_Real (GeomFill_NSections::*)() const) &GeomFill_NSections::MaximalSection, "Returns the length of the greater section. This information is usefull to G1's control. Warning: With an little value, approximation can be slower.");
cls_GeomFill_NSections.def("GetMinimalWeight", (void (GeomFill_NSections::*)(TColStd_Array1OfReal &) const) &GeomFill_NSections::GetMinimalWeight, "Compute the minimal value of weight for each poles in all sections. This information is usefull to control error in rational approximation. Warning: Used only if <me> IsRational", py::arg("Weigths"));
cls_GeomFill_NSections.def("IsConstant", [](GeomFill_NSections &self, Standard_Real & Error){ Standard_Boolean rv = self.IsConstant(Error); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Error); }, "return True If the Law isConstant", py::arg("Error"));
cls_GeomFill_NSections.def("ConstantSection", (opencascade::handle<Geom_Curve> (GeomFill_NSections::*)() const) &GeomFill_NSections::ConstantSection, "Return the constant Section if <me> IsConstant.");
cls_GeomFill_NSections.def("IsConicalLaw", [](GeomFill_NSections &self, Standard_Real & Error){ Standard_Boolean rv = self.IsConicalLaw(Error); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Error); }, "Returns True if all section are circle, with same plane,same center and linear radius evolution Return False by Default.", py::arg("Error"));
cls_GeomFill_NSections.def("CirclSection", (opencascade::handle<Geom_Curve> (GeomFill_NSections::*)(const Standard_Real) const) &GeomFill_NSections::CirclSection, "Return the circle section at parameter <Param>, if <me> a IsConicalLaw", py::arg("Param"));
cls_GeomFill_NSections.def_static("get_type_name_", (const char * (*)()) &GeomFill_NSections::get_type_name, "None");
cls_GeomFill_NSections.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_NSections::get_type_descriptor, "None");
cls_GeomFill_NSections.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_NSections::*)() const) &GeomFill_NSections::DynamicType, "None");

// Enums

}