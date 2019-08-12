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
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <Geom_BSplineSurface.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <GeomAbs_Shape.hxx>
#include <gp_Pnt.hxx>
#include <GeomFill_UniformSection.hxx>
#include <Standard_Type.hxx>
#include <Geom_BSplineCurve.hxx>

void bind_GeomFill_UniformSection(py::module &mod){

py::class_<GeomFill_UniformSection, opencascade::handle<GeomFill_UniformSection>, GeomFill_SectionLaw> cls_GeomFill_UniformSection(mod, "GeomFill_UniformSection", "Define an Constant Section Law");

// Constructors
cls_GeomFill_UniformSection.def(py::init<const opencascade::handle<Geom_Curve> &>(), py::arg("C"));
cls_GeomFill_UniformSection.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real>(), py::arg("C"), py::arg("FirstParameter"));
cls_GeomFill_UniformSection.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("FirstParameter"), py::arg("LastParameter"));

// Fields

// Methods
cls_GeomFill_UniformSection.def("D0", (Standard_Boolean (GeomFill_UniformSection::*)(const Standard_Real, TColgp_Array1OfPnt &, TColStd_Array1OfReal &)) &GeomFill_UniformSection::D0, "compute the section for v = param", py::arg("Param"), py::arg("Poles"), py::arg("Weigths"));
cls_GeomFill_UniformSection.def("D1", (Standard_Boolean (GeomFill_UniformSection::*)(const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &GeomFill_UniformSection::D1, "compute the first derivative in v direction of the section for v = param Warning : It used only for C1 or C2 aproximation", py::arg("Param"), py::arg("Poles"), py::arg("DPoles"), py::arg("Weigths"), py::arg("DWeigths"));
cls_GeomFill_UniformSection.def("D2", (Standard_Boolean (GeomFill_UniformSection::*)(const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &GeomFill_UniformSection::D2, "compute the second derivative in v direction of the section for v = param Warning : It used only for C2 aproximation", py::arg("Param"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_GeomFill_UniformSection.def("BSplineSurface", (opencascade::handle<Geom_BSplineSurface> (GeomFill_UniformSection::*)() const) &GeomFill_UniformSection::BSplineSurface, "give if possible an bspline Surface, like iso-v are the section. If it is not possible this methode have to get an Null Surface. Is it the default implementation.");
cls_GeomFill_UniformSection.def("SectionShape", [](GeomFill_UniformSection &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree){ self.SectionShape(NbPoles, NbKnots, Degree); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree); }, "get the format of an section", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"));
cls_GeomFill_UniformSection.def("Knots", (void (GeomFill_UniformSection::*)(TColStd_Array1OfReal &) const) &GeomFill_UniformSection::Knots, "get the Knots of the section", py::arg("TKnots"));
cls_GeomFill_UniformSection.def("Mults", (void (GeomFill_UniformSection::*)(TColStd_Array1OfInteger &) const) &GeomFill_UniformSection::Mults, "get the Multplicities of the section", py::arg("TMults"));
cls_GeomFill_UniformSection.def("IsRational", (Standard_Boolean (GeomFill_UniformSection::*)() const) &GeomFill_UniformSection::IsRational, "Returns if the sections are rationnal or not");
cls_GeomFill_UniformSection.def("IsUPeriodic", (Standard_Boolean (GeomFill_UniformSection::*)() const) &GeomFill_UniformSection::IsUPeriodic, "Returns if the sections are periodic or not");
cls_GeomFill_UniformSection.def("IsVPeriodic", (Standard_Boolean (GeomFill_UniformSection::*)() const) &GeomFill_UniformSection::IsVPeriodic, "Returns if the law isperiodic or not");
cls_GeomFill_UniformSection.def("NbIntervals", (Standard_Integer (GeomFill_UniformSection::*)(const GeomAbs_Shape) const) &GeomFill_UniformSection::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_UniformSection.def("Intervals", (void (GeomFill_UniformSection::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_UniformSection::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_UniformSection.def("SetInterval", (void (GeomFill_UniformSection::*)(const Standard_Real, const Standard_Real)) &GeomFill_UniformSection::SetInterval, "Sets the bounds of the parametric interval on the function This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_GeomFill_UniformSection.def("GetInterval", [](GeomFill_UniformSection &self, Standard_Real & First, Standard_Real & Last){ self.GetInterval(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "Gets the bounds of the parametric interval on the function", py::arg("First"), py::arg("Last"));
cls_GeomFill_UniformSection.def("GetDomain", [](GeomFill_UniformSection &self, Standard_Real & First, Standard_Real & Last){ self.GetDomain(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "Gets the bounds of the function parametric domain. Warning: This domain it is not modified by the SetValue method", py::arg("First"), py::arg("Last"));
cls_GeomFill_UniformSection.def("GetTolerance", (void (GeomFill_UniformSection::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColStd_Array1OfReal &) const) &GeomFill_UniformSection::GetTolerance, "Returns the tolerances associated at each poles to reach in approximation, to satisfy: BoundTol error at the Boundary AngleTol tangent error at the Boundary (in radian) SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"));
cls_GeomFill_UniformSection.def("BarycentreOfSurf", (gp_Pnt (GeomFill_UniformSection::*)() const) &GeomFill_UniformSection::BarycentreOfSurf, "Get the barycentre of Surface. An very poor estimation is sufficent. This information is usefull to perform well conditioned rational approximation. Warning: Used only if <me> IsRational");
cls_GeomFill_UniformSection.def("MaximalSection", (Standard_Real (GeomFill_UniformSection::*)() const) &GeomFill_UniformSection::MaximalSection, "Returns the length of the greater section. This information is usefull to G1's control. Warning: With an little value, approximation can be slower.");
cls_GeomFill_UniformSection.def("GetMinimalWeight", (void (GeomFill_UniformSection::*)(TColStd_Array1OfReal &) const) &GeomFill_UniformSection::GetMinimalWeight, "Compute the minimal value of weight for each poles in all sections. This information is usefull to control error in rational approximation. Warning: Used only if <me> IsRational", py::arg("Weigths"));
cls_GeomFill_UniformSection.def("IsConstant", [](GeomFill_UniformSection &self, Standard_Real & Error){ Standard_Boolean rv = self.IsConstant(Error); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Error); }, "return True", py::arg("Error"));
cls_GeomFill_UniformSection.def("ConstantSection", (opencascade::handle<Geom_Curve> (GeomFill_UniformSection::*)() const) &GeomFill_UniformSection::ConstantSection, "Return the constant Section if <me> IsConstant.");
cls_GeomFill_UniformSection.def_static("get_type_name_", (const char * (*)()) &GeomFill_UniformSection::get_type_name, "None");
cls_GeomFill_UniformSection.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_UniformSection::get_type_descriptor, "None");
cls_GeomFill_UniformSection.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_UniformSection::*)() const) &GeomFill_UniformSection::DynamicType, "None");

// Enums

}