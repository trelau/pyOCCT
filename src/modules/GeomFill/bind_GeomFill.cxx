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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <Geom_Curve.hxx>
#include <Convert_ParameterisationType.hxx>
#include <gp_Vec.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <GeomFill_Filling.hxx>
#include <GeomFill_Stretch.hxx>
#include <GeomFill_Coons.hxx>
#include <GeomFill_Curved.hxx>
#include <GeomFill_BezierCurves.hxx>
#include <GeomFill_BSplineCurves.hxx>
#include <GeomFill_Profiler.hxx>
#include <GeomFill_SectionGenerator.hxx>
#include <GeomFill_Line.hxx>
#include <GeomFill_AppSurf.hxx>
#include <GeomFill_SweepSectionGenerator.hxx>
#include <GeomFill_AppSweep.hxx>
#include <GeomFill_Generator.hxx>
#include <GeomFill_Pipe.hxx>
#include <GeomFill_Tensor.hxx>
#include <GeomFill_ConstrainedFilling.hxx>
#include <GeomFill_Boundary.hxx>
#include <GeomFill_DegeneratedBound.hxx>
#include <GeomFill_SimpleBound.hxx>
#include <GeomFill_BoundWithSurf.hxx>
#include <GeomFill_CoonsAlgPatch.hxx>
#include <GeomFill_TgtField.hxx>
#include <GeomFill_TgtOnCoons.hxx>
#include <GeomFill_CornerState.hxx>
#include <GeomFill_CircularBlendFunc.hxx>
#include <GeomFill_SweepFunction.hxx>
#include <GeomFill_LocFunction.hxx>
#include <GeomFill_PolynomialConvertor.hxx>
#include <GeomFill_QuasiAngularConvertor.hxx>
#include <GeomFill_SnglrFunc.hxx>
#include <GeomFill_FunctionDraft.hxx>
#include <GeomFill_PlanFunc.hxx>
#include <GeomFill_FunctionGuide.hxx>
#include <GeomFill_SectionLaw.hxx>
#include <GeomFill_UniformSection.hxx>
#include <GeomFill_EvolvedSection.hxx>
#include <GeomFill_NSections.hxx>
#include <GeomFill_LocationLaw.hxx>
#include <GeomFill_CurveAndTrihedron.hxx>
#include <GeomFill_LocationDraft.hxx>
#include <GeomFill_LocationGuide.hxx>
#include <GeomFill_TrihedronLaw.hxx>
#include <GeomFill_Fixed.hxx>
#include <GeomFill_Frenet.hxx>
#include <GeomFill_CorrectedFrenet.hxx>
#include <GeomFill_DiscreteTrihedron.hxx>
#include <GeomFill_ConstantBiNormal.hxx>
#include <GeomFill_Darboux.hxx>
#include <GeomFill_DraftTrihedron.hxx>
#include <GeomFill_TrihedronWithGuide.hxx>
#include <GeomFill_GuideTrihedronAC.hxx>
#include <GeomFill_GuideTrihedronPlan.hxx>
#include <GeomFill_Sweep.hxx>
#include <GeomFill_SectionPlacement.hxx>
#include <GeomFill.hxx>

void bind_GeomFill(py::module &mod){

py::class_<GeomFill> cls_GeomFill(mod, "GeomFill", "Tools and Data to filling Surface and Sweep Surfaces");

// Constructors

// Fields

// Methods
// cls_GeomFill.def_static("operator new_", (void * (*)(size_t)) &GeomFill::operator new, "None", py::arg("theSize"));
// cls_GeomFill.def_static("operator delete_", (void (*)(void *)) &GeomFill::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill::operator new[], "None", py::arg("theSize"));
// cls_GeomFill.def_static("operator delete[]_", (void (*)(void *)) &GeomFill::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill.def_static("Surface_", (opencascade::handle<Geom_Surface> (*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &)) &GeomFill::Surface, "Builds a ruled surface between the two curves, Curve1 and Curve2.", py::arg("Curve1"), py::arg("Curve2"));
cls_GeomFill.def_static("GetCircle_", (void (*)(const Convert_ParameterisationType, const gp_Vec &, const gp_Vec &, const gp_Vec &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const gp_Pnt &, TColgp_Array1OfPnt &, TColStd_Array1OfReal &)) &GeomFill::GetCircle, "None", py::arg("TConv"), py::arg("ns1"), py::arg("ns2"), py::arg("nplan"), py::arg("pt1"), py::arg("pt2"), py::arg("Rayon"), py::arg("Center"), py::arg("Poles"), py::arg("Weigths"));
cls_GeomFill.def_static("GetCircle_", (Standard_Boolean (*)(const Convert_ParameterisationType, const gp_Vec &, const gp_Vec &, const gp_Vec &, const gp_Vec &, const gp_Vec &, const gp_Vec &, const gp_Pnt &, const gp_Pnt &, const gp_Vec &, const gp_Vec &, const Standard_Real, const Standard_Real, const gp_Pnt &, const gp_Vec &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &GeomFill::GetCircle, "None", py::arg("TConv"), py::arg("ns1"), py::arg("ns2"), py::arg("dn1w"), py::arg("dn2w"), py::arg("nplan"), py::arg("dnplan"), py::arg("pts1"), py::arg("pts2"), py::arg("tang1"), py::arg("tang2"), py::arg("Rayon"), py::arg("DRayon"), py::arg("Center"), py::arg("DCenter"), py::arg("Poles"), py::arg("DPoles"), py::arg("Weigths"), py::arg("DWeigths"));
cls_GeomFill.def_static("GetCircle_", (Standard_Boolean (*)(const Convert_ParameterisationType, const gp_Vec &, const gp_Vec &, const gp_Vec &, const gp_Vec &, const gp_Vec &, const gp_Vec &, const gp_Vec &, const gp_Vec &, const gp_Vec &, const gp_Pnt &, const gp_Pnt &, const gp_Vec &, const gp_Vec &, const gp_Vec &, const gp_Vec &, const Standard_Real, const Standard_Real, const Standard_Real, const gp_Pnt &, const gp_Vec &, const gp_Vec &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &GeomFill::GetCircle, "None", py::arg("TConv"), py::arg("ns1"), py::arg("ns2"), py::arg("dn1w"), py::arg("dn2w"), py::arg("d2n1w"), py::arg("d2n2w"), py::arg("nplan"), py::arg("dnplan"), py::arg("d2nplan"), py::arg("pts1"), py::arg("pts2"), py::arg("tang1"), py::arg("tang2"), py::arg("Dtang1"), py::arg("Dtang2"), py::arg("Rayon"), py::arg("DRayon"), py::arg("D2Rayon"), py::arg("Center"), py::arg("DCenter"), py::arg("D2Center"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_GeomFill.def_static("GetShape_", [](const Standard_Real MaxAng, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Convert_ParameterisationType & TypeConv){ GeomFill::GetShape(MaxAng, NbPoles, NbKnots, Degree, TypeConv); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree); }, "None", py::arg("MaxAng"), py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("TypeConv"));
cls_GeomFill.def_static("Knots_", (void (*)(const Convert_ParameterisationType, TColStd_Array1OfReal &)) &GeomFill::Knots, "None", py::arg("TypeConv"), py::arg("TKnots"));
cls_GeomFill.def_static("Mults_", (void (*)(const Convert_ParameterisationType, TColStd_Array1OfInteger &)) &GeomFill::Mults, "None", py::arg("TypeConv"), py::arg("TMults"));
cls_GeomFill.def_static("GetMinimalWeights_", (void (*)(const Convert_ParameterisationType, const Standard_Real, const Standard_Real, TColStd_Array1OfReal &)) &GeomFill::GetMinimalWeights, "None", py::arg("TConv"), py::arg("AngleMin"), py::arg("AngleMax"), py::arg("Weigths"));
cls_GeomFill.def_static("GetTolerance_", (Standard_Real (*)(const Convert_ParameterisationType, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomFill::GetTolerance, "Used by the generical classes to determine Tolerance for approximation", py::arg("TConv"), py::arg("AngleMin"), py::arg("Radius"), py::arg("AngularTol"), py::arg("SpatialTol"));

// Enums

}