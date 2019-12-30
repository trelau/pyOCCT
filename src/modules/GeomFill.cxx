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
#include <GeomFill_PipeError.hxx>
#include <GeomFill_Trihedron.hxx>
#include <GeomFill_ApproxStyle.hxx>
#include <GeomFill_FillingStyle.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <gp_Mat.hxx>
#include <GeomFill_LocationLaw.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Vec.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <NCollection_Array1.hxx>
#include <GeomFill_Array1OfLocationLaw.hxx>
#include <Standard.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <GeomFill_HArray1OfLocationLaw.hxx>
#include <NCollection_Sequence.hxx>
#include <gp_Trsf.hxx>
#include <GeomFill_SequenceOfTrsf.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <Geom_BSplineSurface.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <Geom_Curve.hxx>
#include <GeomFill_SectionLaw.hxx>
#include <GeomFill_Array1OfSectionLaw.hxx>
#include <GeomFill_HArray1OfSectionLaw.hxx>
#include <GeomFill_Boundary.hxx>
#include <Adaptor3d_CurveOnSurface.hxx>
#include <GeomFill_BoundWithSurf.hxx>
#include <Law_Function.hxx>
#include <GeomFill_SimpleBound.hxx>
#include <GeomFill_CornerState.hxx>
#include <GeomFill_CoonsAlgPatch.hxx>
#include <GeomFill_TgtField.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColgp_HArray2OfPnt.hxx>
#include <GeomFill_ConstrainedFilling.hxx>
#include <Geom_Surface.hxx>
#include <Convert_ParameterisationType.hxx>
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
#include <GeomFill_DegeneratedBound.hxx>
#include <GeomFill_TgtOnCoons.hxx>
#include <GeomFill_CircularBlendFunc.hxx>
#include <GeomFill_SweepFunction.hxx>
#include <GeomFill_LocFunction.hxx>
#include <GeomFill_PolynomialConvertor.hxx>
#include <GeomFill_QuasiAngularConvertor.hxx>
#include <GeomFill_SnglrFunc.hxx>
#include <GeomFill_FunctionDraft.hxx>
#include <GeomFill_PlanFunc.hxx>
#include <GeomFill_FunctionGuide.hxx>
#include <GeomFill_UniformSection.hxx>
#include <GeomFill_EvolvedSection.hxx>
#include <GeomFill_NSections.hxx>
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
#include <AppBlend_Approx.hxx>
#include <Approx_ParametrizationType.hxx>
#include <TColgp_Array2OfPnt.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <TColgp_SequenceOfArray1OfPnt2d.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_BezierSurface.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Approx_SweepFunction.hxx>
#include <gp_Dir.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <TColgp_SequenceOfVec.hxx>
#include <TColgp_HArray1OfVec.hxx>
#include <gp_Ax2.hxx>
#include <GeomFill_SequenceOfAx2.hxx>
#include <GeomFill_HSequenceOfAx2.hxx>
#include <TColStd_HSequenceOfReal.hxx>
#include <math_FunctionSetWithDerivatives.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <gp_XYZ.hxx>
#include <TColGeom_SequenceOfCurve.hxx>
#include <Approx_CurvlinFunc.hxx>
#include <TColgp_HArray2OfPnt2d.hxx>
#include <TColgp_HArray1OfPnt2d.hxx>
#include <Geom2d_Curve.hxx>
#include <math_FunctionWithDerivative.hxx>
#include <Geom_Geometry.hxx>
#include <gp_Ax1.hxx>
#include <GeomAdaptor_Curve.hxx>
#include <Extrema_ExtPC.hxx>
#include <Adaptor3d_Curve.hxx>
#include <GeomAbs_CurveType.hxx>
#include <TColGeom2d_HArray1OfCurve.hxx>
#include <Law_BSpline.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_Define_HArray1.hxx>
#include <bind_NCollection_Sequence.hxx>
#include <bind_Define_HSequence.hxx>

PYBIND11_MODULE(GeomFill, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.gp");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Law");
py::module::import("OCCT.Convert");
py::module::import("OCCT.AppBlend");
py::module::import("OCCT.Approx");
py::module::import("OCCT.math");
py::module::import("OCCT.TColGeom");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.GeomAdaptor");
py::module::import("OCCT.Extrema");
py::module::import("OCCT.TColGeom2d");

// ENUM: GEOMFILL_PIPEERROR
py::enum_<GeomFill_PipeError>(mod, "GeomFill_PipeError", "None")
	.value("GeomFill_PipeOk", GeomFill_PipeError::GeomFill_PipeOk)
	.value("GeomFill_PipeNotOk", GeomFill_PipeError::GeomFill_PipeNotOk)
	.value("GeomFill_PlaneNotIntersectGuide", GeomFill_PipeError::GeomFill_PlaneNotIntersectGuide)
	.value("GeomFill_ImpossibleContact", GeomFill_PipeError::GeomFill_ImpossibleContact)
	.export_values();


// ENUM: GEOMFILL_TRIHEDRON
py::enum_<GeomFill_Trihedron>(mod, "GeomFill_Trihedron", "None")
	.value("GeomFill_IsCorrectedFrenet", GeomFill_Trihedron::GeomFill_IsCorrectedFrenet)
	.value("GeomFill_IsFixed", GeomFill_Trihedron::GeomFill_IsFixed)
	.value("GeomFill_IsFrenet", GeomFill_Trihedron::GeomFill_IsFrenet)
	.value("GeomFill_IsConstantNormal", GeomFill_Trihedron::GeomFill_IsConstantNormal)
	.value("GeomFill_IsDarboux", GeomFill_Trihedron::GeomFill_IsDarboux)
	.value("GeomFill_IsGuideAC", GeomFill_Trihedron::GeomFill_IsGuideAC)
	.value("GeomFill_IsGuidePlan", GeomFill_Trihedron::GeomFill_IsGuidePlan)
	.value("GeomFill_IsGuideACWithContact", GeomFill_Trihedron::GeomFill_IsGuideACWithContact)
	.value("GeomFill_IsGuidePlanWithContact", GeomFill_Trihedron::GeomFill_IsGuidePlanWithContact)
	.value("GeomFill_IsDiscreteTrihedron", GeomFill_Trihedron::GeomFill_IsDiscreteTrihedron)
	.export_values();


// ENUM: GEOMFILL_APPROXSTYLE
py::enum_<GeomFill_ApproxStyle>(mod, "GeomFill_ApproxStyle", "None")
	.value("GeomFill_Section", GeomFill_ApproxStyle::GeomFill_Section)
	.value("GeomFill_Location", GeomFill_ApproxStyle::GeomFill_Location)
	.export_values();


// ENUM: GEOMFILL_FILLINGSTYLE
py::enum_<GeomFill_FillingStyle>(mod, "GeomFill_FillingStyle", "Defines the three filling styles used in this package - GeomFill_Stretch - the style with the flattest patches - GeomFill_Coons - a rounded style of patch with less depth than those of Curved - GeomFill_Curved - the style with the most rounded patches.")
	.value("GeomFill_StretchStyle", GeomFill_FillingStyle::GeomFill_StretchStyle)
	.value("GeomFill_CoonsStyle", GeomFill_FillingStyle::GeomFill_CoonsStyle)
	.value("GeomFill_CurvedStyle", GeomFill_FillingStyle::GeomFill_CurvedStyle)
	.export_values();


// CLASS: GEOMFILL_LOCATIONLAW
py::class_<GeomFill_LocationLaw, opencascade::handle<GeomFill_LocationLaw>, Standard_Transient> cls_GeomFill_LocationLaw(mod, "GeomFill_LocationLaw", "To define location law in Sweeping location is -- defined by an Matrix M and an Vector V, and transform an point P in MP+V.");

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

// TYPEDEF: GEOMFILL_ARRAY1OFLOCATIONLAW
bind_NCollection_Array1<opencascade::handle<GeomFill_LocationLaw> >(mod, "GeomFill_Array1OfLocationLaw", py::module_local(false));

// CLASS: GEOMFILL_HARRAY1OFLOCATIONLAW
bind_Define_HArray1<GeomFill_HArray1OfLocationLaw, GeomFill_Array1OfLocationLaw>(mod, "GeomFill_HArray1OfLocationLaw");

// TYPEDEF: GEOMFILL_SEQUENCEOFTRSF
bind_NCollection_Sequence<gp_Trsf>(mod, "GeomFill_SequenceOfTrsf", py::module_local(false));

// CLASS: GEOMFILL_SECTIONLAW
py::class_<GeomFill_SectionLaw, opencascade::handle<GeomFill_SectionLaw>, Standard_Transient> cls_GeomFill_SectionLaw(mod, "GeomFill_SectionLaw", "To define section law in sweeping");

// Methods
cls_GeomFill_SectionLaw.def("D0", (Standard_Boolean (GeomFill_SectionLaw::*)(const Standard_Real, TColgp_Array1OfPnt &, TColStd_Array1OfReal &)) &GeomFill_SectionLaw::D0, "compute the section for v = param", py::arg("Param"), py::arg("Poles"), py::arg("Weigths"));
cls_GeomFill_SectionLaw.def("D1", (Standard_Boolean (GeomFill_SectionLaw::*)(const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &GeomFill_SectionLaw::D1, "compute the first derivative in v direction of the section for v = param Warning : It used only for C1 or C2 aproximation", py::arg("Param"), py::arg("Poles"), py::arg("DPoles"), py::arg("Weigths"), py::arg("DWeigths"));
cls_GeomFill_SectionLaw.def("D2", (Standard_Boolean (GeomFill_SectionLaw::*)(const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &GeomFill_SectionLaw::D2, "compute the second derivative in v direction of the section for v = param Warning : It used only for C2 aproximation", py::arg("Param"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_GeomFill_SectionLaw.def("BSplineSurface", (opencascade::handle<Geom_BSplineSurface> (GeomFill_SectionLaw::*)() const) &GeomFill_SectionLaw::BSplineSurface, "give if possible an bspline Surface, like iso-v are the section. If it is not possible this methode have to get an Null Surface. It is the default implementation.");
cls_GeomFill_SectionLaw.def("SectionShape", [](GeomFill_SectionLaw &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree){ self.SectionShape(NbPoles, NbKnots, Degree); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree); }, "get the format of an section", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"));
cls_GeomFill_SectionLaw.def("Knots", (void (GeomFill_SectionLaw::*)(TColStd_Array1OfReal &) const) &GeomFill_SectionLaw::Knots, "get the Knots of the section", py::arg("TKnots"));
cls_GeomFill_SectionLaw.def("Mults", (void (GeomFill_SectionLaw::*)(TColStd_Array1OfInteger &) const) &GeomFill_SectionLaw::Mults, "get the Multplicities of the section", py::arg("TMults"));
cls_GeomFill_SectionLaw.def("IsRational", (Standard_Boolean (GeomFill_SectionLaw::*)() const) &GeomFill_SectionLaw::IsRational, "Returns if the sections are rationnal or not");
cls_GeomFill_SectionLaw.def("IsUPeriodic", (Standard_Boolean (GeomFill_SectionLaw::*)() const) &GeomFill_SectionLaw::IsUPeriodic, "Returns if the sections are periodic or not");
cls_GeomFill_SectionLaw.def("IsVPeriodic", (Standard_Boolean (GeomFill_SectionLaw::*)() const) &GeomFill_SectionLaw::IsVPeriodic, "Returns if law is periodic or not");
cls_GeomFill_SectionLaw.def("NbIntervals", (Standard_Integer (GeomFill_SectionLaw::*)(const GeomAbs_Shape) const) &GeomFill_SectionLaw::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_SectionLaw.def("Intervals", (void (GeomFill_SectionLaw::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_SectionLaw::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_SectionLaw.def("SetInterval", (void (GeomFill_SectionLaw::*)(const Standard_Real, const Standard_Real)) &GeomFill_SectionLaw::SetInterval, "Sets the bounds of the parametric interval on the function This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_GeomFill_SectionLaw.def("GetInterval", [](GeomFill_SectionLaw &self, Standard_Real & First, Standard_Real & Last){ self.GetInterval(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "Gets the bounds of the parametric interval on the function", py::arg("First"), py::arg("Last"));
cls_GeomFill_SectionLaw.def("GetDomain", [](GeomFill_SectionLaw &self, Standard_Real & First, Standard_Real & Last){ self.GetDomain(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "Gets the bounds of the function parametric domain. Warning: This domain it is not modified by the SetValue method", py::arg("First"), py::arg("Last"));
cls_GeomFill_SectionLaw.def("GetTolerance", (void (GeomFill_SectionLaw::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColStd_Array1OfReal &) const) &GeomFill_SectionLaw::GetTolerance, "Returns the tolerances associated at each poles to reach in approximation, to satisfy: BoundTol error at the Boundary AngleTol tangent error at the Boundary (in radian) SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"));
cls_GeomFill_SectionLaw.def("SetTolerance", (void (GeomFill_SectionLaw::*)(const Standard_Real, const Standard_Real)) &GeomFill_SectionLaw::SetTolerance, "Is usefull, if (me) have to run numerical algorithm to perform D0, D1 or D2 The default implementation make nothing.", py::arg("Tol3d"), py::arg("Tol2d"));
cls_GeomFill_SectionLaw.def("BarycentreOfSurf", (gp_Pnt (GeomFill_SectionLaw::*)() const) &GeomFill_SectionLaw::BarycentreOfSurf, "Get the barycentre of Surface. An very poor estimation is sufficent. This information is usefull to perform well conditioned rational approximation. Warning: Used only if <me> IsRational");
cls_GeomFill_SectionLaw.def("MaximalSection", (Standard_Real (GeomFill_SectionLaw::*)() const) &GeomFill_SectionLaw::MaximalSection, "Returns the length of the greater section. This information is usefull to G1's control. Warning: With an little value, approximation can be slower.");
cls_GeomFill_SectionLaw.def("GetMinimalWeight", (void (GeomFill_SectionLaw::*)(TColStd_Array1OfReal &) const) &GeomFill_SectionLaw::GetMinimalWeight, "Compute the minimal value of weight for each poles in all sections. This information is usefull to control error in rational approximation. Warning: Used only if <me> IsRational", py::arg("Weigths"));
cls_GeomFill_SectionLaw.def("IsConstant", [](GeomFill_SectionLaw &self, Standard_Real & Error){ Standard_Boolean rv = self.IsConstant(Error); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Error); }, "Say if all sections are equals", py::arg("Error"));
cls_GeomFill_SectionLaw.def("ConstantSection", (opencascade::handle<Geom_Curve> (GeomFill_SectionLaw::*)() const) &GeomFill_SectionLaw::ConstantSection, "Return a copy of the constant Section, if me IsConstant");
cls_GeomFill_SectionLaw.def("IsConicalLaw", [](GeomFill_SectionLaw &self, Standard_Real & Error){ Standard_Boolean rv = self.IsConicalLaw(Error); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Error); }, "Returns True if all section are circle, with same plane,same center and linear radius evolution Return False by Default.", py::arg("Error"));
cls_GeomFill_SectionLaw.def("CirclSection", (opencascade::handle<Geom_Curve> (GeomFill_SectionLaw::*)(const Standard_Real) const) &GeomFill_SectionLaw::CirclSection, "Return the circle section at parameter <Param>, if <me> a IsConicalLaw", py::arg("Param"));
cls_GeomFill_SectionLaw.def_static("get_type_name_", (const char * (*)()) &GeomFill_SectionLaw::get_type_name, "None");
cls_GeomFill_SectionLaw.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_SectionLaw::get_type_descriptor, "None");
cls_GeomFill_SectionLaw.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_SectionLaw::*)() const) &GeomFill_SectionLaw::DynamicType, "None");

// TYPEDEF: GEOMFILL_ARRAY1OFSECTIONLAW
bind_NCollection_Array1<opencascade::handle<GeomFill_SectionLaw> >(mod, "GeomFill_Array1OfSectionLaw", py::module_local(false));

// CLASS: GEOMFILL_HARRAY1OFSECTIONLAW
bind_Define_HArray1<GeomFill_HArray1OfSectionLaw, GeomFill_Array1OfSectionLaw>(mod, "GeomFill_HArray1OfSectionLaw");

// CLASS: GEOMFILL_BOUNDARY
py::class_<GeomFill_Boundary, opencascade::handle<GeomFill_Boundary>, Standard_Transient> cls_GeomFill_Boundary(mod, "GeomFill_Boundary", "Root class to define a boundary which will form part of a contour around a gap requiring filling. Any new type of constrained boundary must inherit this class. The GeomFill package provides two classes to define constrained boundaries: - GeomFill_SimpleBound to define an unattached boundary - GeomFill_BoundWithSurf to define a boundary attached to a surface. These objects are used to define the boundaries for a GeomFill_ConstrainedFilling framework.");

// Methods
cls_GeomFill_Boundary.def("Value", (gp_Pnt (GeomFill_Boundary::*)(const Standard_Real) const) &GeomFill_Boundary::Value, "None", py::arg("U"));
cls_GeomFill_Boundary.def("D1", (void (GeomFill_Boundary::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &GeomFill_Boundary::D1, "None", py::arg("U"), py::arg("P"), py::arg("V"));
cls_GeomFill_Boundary.def("HasNormals", (Standard_Boolean (GeomFill_Boundary::*)() const) &GeomFill_Boundary::HasNormals, "None");
cls_GeomFill_Boundary.def("Norm", (gp_Vec (GeomFill_Boundary::*)(const Standard_Real) const) &GeomFill_Boundary::Norm, "None", py::arg("U"));
cls_GeomFill_Boundary.def("D1Norm", (void (GeomFill_Boundary::*)(const Standard_Real, gp_Vec &, gp_Vec &) const) &GeomFill_Boundary::D1Norm, "None", py::arg("U"), py::arg("N"), py::arg("DN"));
cls_GeomFill_Boundary.def("Reparametrize", (void (GeomFill_Boundary::*)(const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Boolean)) &GeomFill_Boundary::Reparametrize, "None", py::arg("First"), py::arg("Last"), py::arg("HasDF"), py::arg("HasDL"), py::arg("DF"), py::arg("DL"), py::arg("Rev"));
cls_GeomFill_Boundary.def("Points", (void (GeomFill_Boundary::*)(gp_Pnt &, gp_Pnt &) const) &GeomFill_Boundary::Points, "None", py::arg("PFirst"), py::arg("PLast"));
cls_GeomFill_Boundary.def("Bounds", [](GeomFill_Boundary &self, Standard_Real & First, Standard_Real & Last){ self.Bounds(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "None", py::arg("First"), py::arg("Last"));
cls_GeomFill_Boundary.def("IsDegenerated", (Standard_Boolean (GeomFill_Boundary::*)() const) &GeomFill_Boundary::IsDegenerated, "None");
cls_GeomFill_Boundary.def("Tol3d", (Standard_Real (GeomFill_Boundary::*)() const) &GeomFill_Boundary::Tol3d, "None");
cls_GeomFill_Boundary.def("Tol3d", (void (GeomFill_Boundary::*)(const Standard_Real)) &GeomFill_Boundary::Tol3d, "None", py::arg("Tol"));
cls_GeomFill_Boundary.def("Tolang", (Standard_Real (GeomFill_Boundary::*)() const) &GeomFill_Boundary::Tolang, "None");
cls_GeomFill_Boundary.def("Tolang", (void (GeomFill_Boundary::*)(const Standard_Real)) &GeomFill_Boundary::Tolang, "None", py::arg("Tol"));
cls_GeomFill_Boundary.def_static("get_type_name_", (const char * (*)()) &GeomFill_Boundary::get_type_name, "None");
cls_GeomFill_Boundary.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_Boundary::get_type_descriptor, "None");
cls_GeomFill_Boundary.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_Boundary::*)() const) &GeomFill_Boundary::DynamicType, "None");

// CLASS: GEOMFILL_BOUNDWITHSURF
py::class_<GeomFill_BoundWithSurf, opencascade::handle<GeomFill_BoundWithSurf>, GeomFill_Boundary> cls_GeomFill_BoundWithSurf(mod, "GeomFill_BoundWithSurf", "Defines a 3d curve as a boundary for a GeomFill_ConstrainedFilling algorithm. This curve is attached to an existing surface. Defines a constrained boundary for filling the computations are done with a CurveOnSurf and a normals field defined by the normalized normal to the surface along the PCurve. Contains fields to allow a reparametrization of curve and normals field.");

// Constructors
cls_GeomFill_BoundWithSurf.def(py::init<const Adaptor3d_CurveOnSurface &, const Standard_Real, const Standard_Real>(), py::arg("CurveOnSurf"), py::arg("Tol3d"), py::arg("Tolang"));

// Methods
cls_GeomFill_BoundWithSurf.def("Value", (gp_Pnt (GeomFill_BoundWithSurf::*)(const Standard_Real) const) &GeomFill_BoundWithSurf::Value, "None", py::arg("U"));
cls_GeomFill_BoundWithSurf.def("D1", (void (GeomFill_BoundWithSurf::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &GeomFill_BoundWithSurf::D1, "None", py::arg("U"), py::arg("P"), py::arg("V"));
cls_GeomFill_BoundWithSurf.def("HasNormals", (Standard_Boolean (GeomFill_BoundWithSurf::*)() const) &GeomFill_BoundWithSurf::HasNormals, "None");
cls_GeomFill_BoundWithSurf.def("Norm", (gp_Vec (GeomFill_BoundWithSurf::*)(const Standard_Real) const) &GeomFill_BoundWithSurf::Norm, "None", py::arg("U"));
cls_GeomFill_BoundWithSurf.def("D1Norm", (void (GeomFill_BoundWithSurf::*)(const Standard_Real, gp_Vec &, gp_Vec &) const) &GeomFill_BoundWithSurf::D1Norm, "None", py::arg("U"), py::arg("N"), py::arg("DN"));
cls_GeomFill_BoundWithSurf.def("Reparametrize", (void (GeomFill_BoundWithSurf::*)(const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Boolean)) &GeomFill_BoundWithSurf::Reparametrize, "None", py::arg("First"), py::arg("Last"), py::arg("HasDF"), py::arg("HasDL"), py::arg("DF"), py::arg("DL"), py::arg("Rev"));
cls_GeomFill_BoundWithSurf.def("Bounds", [](GeomFill_BoundWithSurf &self, Standard_Real & First, Standard_Real & Last){ self.Bounds(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "None", py::arg("First"), py::arg("Last"));
cls_GeomFill_BoundWithSurf.def("IsDegenerated", (Standard_Boolean (GeomFill_BoundWithSurf::*)() const) &GeomFill_BoundWithSurf::IsDegenerated, "None");
cls_GeomFill_BoundWithSurf.def_static("get_type_name_", (const char * (*)()) &GeomFill_BoundWithSurf::get_type_name, "None");
cls_GeomFill_BoundWithSurf.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_BoundWithSurf::get_type_descriptor, "None");
cls_GeomFill_BoundWithSurf.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_BoundWithSurf::*)() const) &GeomFill_BoundWithSurf::DynamicType, "None");

// CLASS: GEOMFILL_SIMPLEBOUND
py::class_<GeomFill_SimpleBound, opencascade::handle<GeomFill_SimpleBound>, GeomFill_Boundary> cls_GeomFill_SimpleBound(mod, "GeomFill_SimpleBound", "Defines a 3d curve as a boundary for a GeomFill_ConstrainedFilling algorithm. This curve is unattached to an existing surface.D Contains fields to allow a reparametrization of curve.");

// Constructors
cls_GeomFill_SimpleBound.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Real>(), py::arg("Curve"), py::arg("Tol3d"), py::arg("Tolang"));

// Methods
cls_GeomFill_SimpleBound.def("Value", (gp_Pnt (GeomFill_SimpleBound::*)(const Standard_Real) const) &GeomFill_SimpleBound::Value, "None", py::arg("U"));
cls_GeomFill_SimpleBound.def("D1", (void (GeomFill_SimpleBound::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &GeomFill_SimpleBound::D1, "None", py::arg("U"), py::arg("P"), py::arg("V"));
cls_GeomFill_SimpleBound.def("Reparametrize", (void (GeomFill_SimpleBound::*)(const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Boolean)) &GeomFill_SimpleBound::Reparametrize, "None", py::arg("First"), py::arg("Last"), py::arg("HasDF"), py::arg("HasDL"), py::arg("DF"), py::arg("DL"), py::arg("Rev"));
cls_GeomFill_SimpleBound.def("Bounds", [](GeomFill_SimpleBound &self, Standard_Real & First, Standard_Real & Last){ self.Bounds(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "None", py::arg("First"), py::arg("Last"));
cls_GeomFill_SimpleBound.def("IsDegenerated", (Standard_Boolean (GeomFill_SimpleBound::*)() const) &GeomFill_SimpleBound::IsDegenerated, "None");
cls_GeomFill_SimpleBound.def_static("get_type_name_", (const char * (*)()) &GeomFill_SimpleBound::get_type_name, "None");
cls_GeomFill_SimpleBound.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_SimpleBound::get_type_descriptor, "None");
cls_GeomFill_SimpleBound.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_SimpleBound::*)() const) &GeomFill_SimpleBound::DynamicType, "None");

// CLASS: GEOMFILL_CORNERSTATE
py::class_<GeomFill_CornerState> cls_GeomFill_CornerState(mod, "GeomFill_CornerState", "Class (should be a structure) storing the informations about continuity, normals parallelism, coons conditions and bounds tangents angle on the corner of contour to be filled.");

// Constructors
cls_GeomFill_CornerState.def(py::init<>());

// Methods
// cls_GeomFill_CornerState.def_static("operator new_", (void * (*)(size_t)) &GeomFill_CornerState::operator new, "None", py::arg("theSize"));
// cls_GeomFill_CornerState.def_static("operator delete_", (void (*)(void *)) &GeomFill_CornerState::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_CornerState.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_CornerState::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_CornerState.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_CornerState::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_CornerState.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_CornerState::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_CornerState.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_CornerState::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_CornerState.def("Gap", (Standard_Real (GeomFill_CornerState::*)() const) &GeomFill_CornerState::Gap, "None");
cls_GeomFill_CornerState.def("Gap", (void (GeomFill_CornerState::*)(const Standard_Real)) &GeomFill_CornerState::Gap, "None", py::arg("G"));
cls_GeomFill_CornerState.def("TgtAng", (Standard_Real (GeomFill_CornerState::*)() const) &GeomFill_CornerState::TgtAng, "None");
cls_GeomFill_CornerState.def("TgtAng", (void (GeomFill_CornerState::*)(const Standard_Real)) &GeomFill_CornerState::TgtAng, "None", py::arg("Ang"));
cls_GeomFill_CornerState.def("HasConstraint", (Standard_Boolean (GeomFill_CornerState::*)() const) &GeomFill_CornerState::HasConstraint, "None");
cls_GeomFill_CornerState.def("Constraint", (void (GeomFill_CornerState::*)()) &GeomFill_CornerState::Constraint, "None");
cls_GeomFill_CornerState.def("NorAng", (Standard_Real (GeomFill_CornerState::*)() const) &GeomFill_CornerState::NorAng, "None");
cls_GeomFill_CornerState.def("NorAng", (void (GeomFill_CornerState::*)(const Standard_Real)) &GeomFill_CornerState::NorAng, "None", py::arg("Ang"));
cls_GeomFill_CornerState.def("IsToKill", [](GeomFill_CornerState &self, Standard_Real & Scal){ Standard_Boolean rv = self.IsToKill(Scal); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Scal); }, "None", py::arg("Scal"));
cls_GeomFill_CornerState.def("DoKill", (void (GeomFill_CornerState::*)(const Standard_Real)) &GeomFill_CornerState::DoKill, "None", py::arg("Scal"));

// CLASS: GEOMFILL_CONSTRAINEDFILLING
py::class_<GeomFill_ConstrainedFilling> cls_GeomFill_ConstrainedFilling(mod, "GeomFill_ConstrainedFilling", "An algorithm for constructing a BSpline surface filled from a series of boundaries which serve as path constraints and optionally, as tangency constraints. The algorithm accepts three or four curves as the boundaries of the target surface. The only FillingStyle used is Coons. A ConstrainedFilling object provides a framework for: - defining the boundaries of the surface - implementing the construction algorithm - consulting the result. Warning This surface filling algorithm is specifically designed to be used in connection with fillets. Satisfactory results cannot be guaranteed for other uses.");

// Constructors
cls_GeomFill_ConstrainedFilling.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("MaxDeg"), py::arg("MaxSeg"));

// Methods
// cls_GeomFill_ConstrainedFilling.def_static("operator new_", (void * (*)(size_t)) &GeomFill_ConstrainedFilling::operator new, "None", py::arg("theSize"));
// cls_GeomFill_ConstrainedFilling.def_static("operator delete_", (void (*)(void *)) &GeomFill_ConstrainedFilling::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_ConstrainedFilling.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_ConstrainedFilling::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_ConstrainedFilling.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_ConstrainedFilling::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_ConstrainedFilling.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_ConstrainedFilling::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_ConstrainedFilling.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_ConstrainedFilling::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_ConstrainedFilling.def("Init", [](GeomFill_ConstrainedFilling &self, const opencascade::handle<GeomFill_Boundary> & a0, const opencascade::handle<GeomFill_Boundary> & a1, const opencascade::handle<GeomFill_Boundary> & a2) -> void { return self.Init(a0, a1, a2); });
cls_GeomFill_ConstrainedFilling.def("Init", (void (GeomFill_ConstrainedFilling::*)(const opencascade::handle<GeomFill_Boundary> &, const opencascade::handle<GeomFill_Boundary> &, const opencascade::handle<GeomFill_Boundary> &, const Standard_Boolean)) &GeomFill_ConstrainedFilling::Init, "None", py::arg("B1"), py::arg("B2"), py::arg("B3"), py::arg("NoCheck"));
cls_GeomFill_ConstrainedFilling.def("Init", [](GeomFill_ConstrainedFilling &self, const opencascade::handle<GeomFill_Boundary> & a0, const opencascade::handle<GeomFill_Boundary> & a1, const opencascade::handle<GeomFill_Boundary> & a2, const opencascade::handle<GeomFill_Boundary> & a3) -> void { return self.Init(a0, a1, a2, a3); });
cls_GeomFill_ConstrainedFilling.def("Init", (void (GeomFill_ConstrainedFilling::*)(const opencascade::handle<GeomFill_Boundary> &, const opencascade::handle<GeomFill_Boundary> &, const opencascade::handle<GeomFill_Boundary> &, const opencascade::handle<GeomFill_Boundary> &, const Standard_Boolean)) &GeomFill_ConstrainedFilling::Init, "Constructs a BSpline surface filled from the series of boundaries B1, B2, B3 and, if need be, B4, which serve: - as path constraints - and optionally, as tangency constraints if they are GeomFill_BoundWithSurf curves. The boundaries may be given in any order: they are classified and if necessary, reversed and reparameterized. The surface will also respect the following constraints: - its degree will not be greater than the maximum degree defined at the time of construction of this framework, and - the maximum number of segments MaxSeg which BSpline surfaces can have", py::arg("B1"), py::arg("B2"), py::arg("B3"), py::arg("B4"), py::arg("NoCheck"));
cls_GeomFill_ConstrainedFilling.def("SetDomain", (void (GeomFill_ConstrainedFilling::*)(const Standard_Real, const opencascade::handle<GeomFill_BoundWithSurf> &)) &GeomFill_ConstrainedFilling::SetDomain, "Allows to modify domain on witch the blending function associated to the constrained boundary B will propag the influence of the field of tangency. Can be usefull to reduce influence of boundaries on whitch the Coons compatibility conditions are not respected. l is a relative value of the parametric range of B. Default value for l is 1 (used in Init). Warning: Must be called after Init with a constrained boundary used in the call to Init.", py::arg("l"), py::arg("B"));
cls_GeomFill_ConstrainedFilling.def("ReBuild", (void (GeomFill_ConstrainedFilling::*)()) &GeomFill_ConstrainedFilling::ReBuild, "Computes the new poles of the surface using the new blending functions set by several calls to SetDomain.");
cls_GeomFill_ConstrainedFilling.def("Boundary", (opencascade::handle<GeomFill_Boundary> (GeomFill_ConstrainedFilling::*)(const Standard_Integer) const) &GeomFill_ConstrainedFilling::Boundary, "Returns the bound of index i after sort.", py::arg("I"));
cls_GeomFill_ConstrainedFilling.def("Surface", (opencascade::handle<Geom_BSplineSurface> (GeomFill_ConstrainedFilling::*)() const) &GeomFill_ConstrainedFilling::Surface, "Returns the BSpline surface after computation of the fill by this framework.");
cls_GeomFill_ConstrainedFilling.def("Eval", [](GeomFill_ConstrainedFilling &self, const Standard_Real W, const Standard_Integer Ord, Standard_Real & Result){ Standard_Integer rv = self.Eval(W, Ord, Result); return std::tuple<Standard_Integer, Standard_Real &>(rv, Result); }, "Internal use for Advmath approximation call.", py::arg("W"), py::arg("Ord"), py::arg("Result"));
cls_GeomFill_ConstrainedFilling.def("CheckCoonsAlgPatch", (void (GeomFill_ConstrainedFilling::*)(const Standard_Integer)) &GeomFill_ConstrainedFilling::CheckCoonsAlgPatch, "Computes the fields of tangents on 30 points along the bound I, these are not the constraint tangents but gives an idea of the coonsAlgPatch regularity.", py::arg("I"));
cls_GeomFill_ConstrainedFilling.def("CheckTgteField", (void (GeomFill_ConstrainedFilling::*)(const Standard_Integer)) &GeomFill_ConstrainedFilling::CheckTgteField, "Computes the fields of tangents and normals on 30 points along the bound I, draw them, and computes the max dot product that must be near than 0.", py::arg("I"));
cls_GeomFill_ConstrainedFilling.def("CheckApprox", (void (GeomFill_ConstrainedFilling::*)(const Standard_Integer)) &GeomFill_ConstrainedFilling::CheckApprox, "Computes values and normals along the bound I and compare them to the approx result curves (bound and tgte field) , draw the normals and tangents.", py::arg("I"));
cls_GeomFill_ConstrainedFilling.def("CheckResult", (void (GeomFill_ConstrainedFilling::*)(const Standard_Integer)) &GeomFill_ConstrainedFilling::CheckResult, "Computes values and normals along the bound I on both constraint surface and result surface, draw the normals, and computes the max distance between values and the max angle between normals.", py::arg("I"));

// CLASS: GEOMFILL
py::class_<GeomFill> cls_GeomFill(mod, "GeomFill", "Tools and Data to filling Surface and Sweep Surfaces");

// Constructors
cls_GeomFill.def(py::init<>());

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

// CLASS: GEOMFILL_APPSURF
py::class_<GeomFill_AppSurf, AppBlend_Approx> cls_GeomFill_AppSurf(mod, "GeomFill_AppSurf", "Approximate a BSplineSurface passing by all the curves described in the SectionGenerator");

// Constructors
cls_GeomFill_AppSurf.def(py::init<>());
cls_GeomFill_AppSurf.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Degmin"), py::arg("Degmax"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("NbIt"));
cls_GeomFill_AppSurf.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Degmin"), py::arg("Degmax"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("NbIt"), py::arg("KnownParameters"));

// Methods
// cls_GeomFill_AppSurf.def_static("operator new_", (void * (*)(size_t)) &GeomFill_AppSurf::operator new, "None", py::arg("theSize"));
// cls_GeomFill_AppSurf.def_static("operator delete_", (void (*)(void *)) &GeomFill_AppSurf::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_AppSurf.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_AppSurf::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_AppSurf.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_AppSurf::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_AppSurf.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_AppSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_AppSurf.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_AppSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_AppSurf.def("Init", [](GeomFill_AppSurf &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_GeomFill_AppSurf.def("Init", (void (GeomFill_AppSurf::*)(const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean)) &GeomFill_AppSurf::Init, "None", py::arg("Degmin"), py::arg("Degmax"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("NbIt"), py::arg("KnownParameters"));
cls_GeomFill_AppSurf.def("SetParType", (void (GeomFill_AppSurf::*)(const Approx_ParametrizationType)) &GeomFill_AppSurf::SetParType, "Define the type of parametrization used in the approximation", py::arg("ParType"));
cls_GeomFill_AppSurf.def("SetContinuity", (void (GeomFill_AppSurf::*)(const GeomAbs_Shape)) &GeomFill_AppSurf::SetContinuity, "Define the Continuity used in the approximation", py::arg("C"));
cls_GeomFill_AppSurf.def("SetCriteriumWeight", (void (GeomFill_AppSurf::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &GeomFill_AppSurf::SetCriteriumWeight, "define the Weights associed to the criterium used in the optimization.", py::arg("W1"), py::arg("W2"), py::arg("W3"));
cls_GeomFill_AppSurf.def("ParType", (Approx_ParametrizationType (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::ParType, "returns the type of parametrization used in the approximation");
cls_GeomFill_AppSurf.def("Continuity", (GeomAbs_Shape (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::Continuity, "returns the Continuity used in the approximation");
cls_GeomFill_AppSurf.def("CriteriumWeight", [](GeomFill_AppSurf &self, Standard_Real & W1, Standard_Real & W2, Standard_Real & W3){ self.CriteriumWeight(W1, W2, W3); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(W1, W2, W3); }, "returns the Weights (as percent) associed to the criterium used in the optimization.", py::arg("W1"), py::arg("W2"), py::arg("W3"));
cls_GeomFill_AppSurf.def("Perform", [](GeomFill_AppSurf &self, const opencascade::handle<GeomFill_Line> & a0, GeomFill_SectionGenerator & a1) -> void { return self.Perform(a0, a1); });
cls_GeomFill_AppSurf.def("Perform", (void (GeomFill_AppSurf::*)(const opencascade::handle<GeomFill_Line> &, GeomFill_SectionGenerator &, const Standard_Boolean)) &GeomFill_AppSurf::Perform, "None", py::arg("Lin"), py::arg("SecGen"), py::arg("SpApprox"));
cls_GeomFill_AppSurf.def("PerformSmoothing", (void (GeomFill_AppSurf::*)(const opencascade::handle<GeomFill_Line> &, GeomFill_SectionGenerator &)) &GeomFill_AppSurf::PerformSmoothing, "None", py::arg("Lin"), py::arg("SecGen"));
cls_GeomFill_AppSurf.def("Perform", (void (GeomFill_AppSurf::*)(const opencascade::handle<GeomFill_Line> &, GeomFill_SectionGenerator &, const Standard_Integer)) &GeomFill_AppSurf::Perform, "None", py::arg("Lin"), py::arg("SecGen"), py::arg("NbMaxP"));
cls_GeomFill_AppSurf.def("IsDone", (Standard_Boolean (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::IsDone, "None");
cls_GeomFill_AppSurf.def("SurfShape", [](GeomFill_AppSurf &self, Standard_Integer & UDegree, Standard_Integer & VDegree, Standard_Integer & NbUPoles, Standard_Integer & NbVPoles, Standard_Integer & NbUKnots, Standard_Integer & NbVKnots){ self.SurfShape(UDegree, VDegree, NbUPoles, NbVPoles, NbUKnots, NbVKnots); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(UDegree, VDegree, NbUPoles, NbVPoles, NbUKnots, NbVKnots); }, "None", py::arg("UDegree"), py::arg("VDegree"), py::arg("NbUPoles"), py::arg("NbVPoles"), py::arg("NbUKnots"), py::arg("NbVKnots"));
cls_GeomFill_AppSurf.def("Surface", (void (GeomFill_AppSurf::*)(TColgp_Array2OfPnt &, TColStd_Array2OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfInteger &, TColStd_Array1OfInteger &) const) &GeomFill_AppSurf::Surface, "None", py::arg("TPoles"), py::arg("TWeights"), py::arg("TUKnots"), py::arg("TVKnots"), py::arg("TUMults"), py::arg("TVMults"));
cls_GeomFill_AppSurf.def("UDegree", (Standard_Integer (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::UDegree, "None");
cls_GeomFill_AppSurf.def("VDegree", (Standard_Integer (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::VDegree, "None");
cls_GeomFill_AppSurf.def("SurfPoles", (const TColgp_Array2OfPnt & (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::SurfPoles, "None");
cls_GeomFill_AppSurf.def("SurfWeights", (const TColStd_Array2OfReal & (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::SurfWeights, "None");
cls_GeomFill_AppSurf.def("SurfUKnots", (const TColStd_Array1OfReal & (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::SurfUKnots, "None");
cls_GeomFill_AppSurf.def("SurfVKnots", (const TColStd_Array1OfReal & (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::SurfVKnots, "None");
cls_GeomFill_AppSurf.def("SurfUMults", (const TColStd_Array1OfInteger & (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::SurfUMults, "None");
cls_GeomFill_AppSurf.def("SurfVMults", (const TColStd_Array1OfInteger & (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::SurfVMults, "None");
cls_GeomFill_AppSurf.def("NbCurves2d", (Standard_Integer (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::NbCurves2d, "None");
cls_GeomFill_AppSurf.def("Curves2dShape", [](GeomFill_AppSurf &self, Standard_Integer & Degree, Standard_Integer & NbPoles, Standard_Integer & NbKnots){ self.Curves2dShape(Degree, NbPoles, NbKnots); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(Degree, NbPoles, NbKnots); }, "None", py::arg("Degree"), py::arg("NbPoles"), py::arg("NbKnots"));
cls_GeomFill_AppSurf.def("Curve2d", (void (GeomFill_AppSurf::*)(const Standard_Integer, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &, TColStd_Array1OfInteger &) const) &GeomFill_AppSurf::Curve2d, "None", py::arg("Index"), py::arg("TPoles"), py::arg("TKnots"), py::arg("TMults"));
cls_GeomFill_AppSurf.def("Curves2dDegree", (Standard_Integer (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::Curves2dDegree, "None");
cls_GeomFill_AppSurf.def("Curve2dPoles", (const TColgp_Array1OfPnt2d & (GeomFill_AppSurf::*)(const Standard_Integer) const) &GeomFill_AppSurf::Curve2dPoles, "None", py::arg("Index"));
cls_GeomFill_AppSurf.def("Curves2dKnots", (const TColStd_Array1OfReal & (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::Curves2dKnots, "None");
cls_GeomFill_AppSurf.def("Curves2dMults", (const TColStd_Array1OfInteger & (GeomFill_AppSurf::*)() const) &GeomFill_AppSurf::Curves2dMults, "None");
cls_GeomFill_AppSurf.def("TolReached", [](GeomFill_AppSurf &self, Standard_Real & Tol3d, Standard_Real & Tol2d){ self.TolReached(Tol3d, Tol2d); return std::tuple<Standard_Real &, Standard_Real &>(Tol3d, Tol2d); }, "None", py::arg("Tol3d"), py::arg("Tol2d"));
cls_GeomFill_AppSurf.def("TolCurveOnSurf", (Standard_Real (GeomFill_AppSurf::*)(const Standard_Integer) const) &GeomFill_AppSurf::TolCurveOnSurf, "None", py::arg("Index"));

// CLASS: GEOMFILL_APPSWEEP
py::class_<GeomFill_AppSweep, AppBlend_Approx> cls_GeomFill_AppSweep(mod, "GeomFill_AppSweep", "Approximate a sweep surface passing by all the curves described in the SweepSectionGenerator.");

// Constructors
cls_GeomFill_AppSweep.def(py::init<>());
cls_GeomFill_AppSweep.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("Degmin"), py::arg("Degmax"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("NbIt"));
cls_GeomFill_AppSweep.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean>(), py::arg("Degmin"), py::arg("Degmax"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("NbIt"), py::arg("KnownParameters"));

// Methods
// cls_GeomFill_AppSweep.def_static("operator new_", (void * (*)(size_t)) &GeomFill_AppSweep::operator new, "None", py::arg("theSize"));
// cls_GeomFill_AppSweep.def_static("operator delete_", (void (*)(void *)) &GeomFill_AppSweep::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_AppSweep.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_AppSweep::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_AppSweep.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_AppSweep::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_AppSweep.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_AppSweep::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_AppSweep.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_AppSweep::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_AppSweep.def("Init", [](GeomFill_AppSweep &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2, const Standard_Real a3, const Standard_Integer a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_GeomFill_AppSweep.def("Init", (void (GeomFill_AppSweep::*)(const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean)) &GeomFill_AppSweep::Init, "None", py::arg("Degmin"), py::arg("Degmax"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("NbIt"), py::arg("KnownParameters"));
cls_GeomFill_AppSweep.def("SetParType", (void (GeomFill_AppSweep::*)(const Approx_ParametrizationType)) &GeomFill_AppSweep::SetParType, "Define the type of parametrization used in the approximation", py::arg("ParType"));
cls_GeomFill_AppSweep.def("SetContinuity", (void (GeomFill_AppSweep::*)(const GeomAbs_Shape)) &GeomFill_AppSweep::SetContinuity, "Define the Continuity used in the approximation", py::arg("C"));
cls_GeomFill_AppSweep.def("SetCriteriumWeight", (void (GeomFill_AppSweep::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &GeomFill_AppSweep::SetCriteriumWeight, "define the Weights associed to the criterium used in the optimization.", py::arg("W1"), py::arg("W2"), py::arg("W3"));
cls_GeomFill_AppSweep.def("ParType", (Approx_ParametrizationType (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::ParType, "returns the type of parametrization used in the approximation");
cls_GeomFill_AppSweep.def("Continuity", (GeomAbs_Shape (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::Continuity, "returns the Continuity used in the approximation");
cls_GeomFill_AppSweep.def("CriteriumWeight", [](GeomFill_AppSweep &self, Standard_Real & W1, Standard_Real & W2, Standard_Real & W3){ self.CriteriumWeight(W1, W2, W3); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(W1, W2, W3); }, "returns the Weights (as percent) associed to the criterium used in the optimization.", py::arg("W1"), py::arg("W2"), py::arg("W3"));
cls_GeomFill_AppSweep.def("Perform", [](GeomFill_AppSweep &self, const opencascade::handle<GeomFill_Line> & a0, GeomFill_SweepSectionGenerator & a1) -> void { return self.Perform(a0, a1); });
cls_GeomFill_AppSweep.def("Perform", (void (GeomFill_AppSweep::*)(const opencascade::handle<GeomFill_Line> &, GeomFill_SweepSectionGenerator &, const Standard_Boolean)) &GeomFill_AppSweep::Perform, "None", py::arg("Lin"), py::arg("SecGen"), py::arg("SpApprox"));
cls_GeomFill_AppSweep.def("PerformSmoothing", (void (GeomFill_AppSweep::*)(const opencascade::handle<GeomFill_Line> &, GeomFill_SweepSectionGenerator &)) &GeomFill_AppSweep::PerformSmoothing, "None", py::arg("Lin"), py::arg("SecGen"));
cls_GeomFill_AppSweep.def("Perform", (void (GeomFill_AppSweep::*)(const opencascade::handle<GeomFill_Line> &, GeomFill_SweepSectionGenerator &, const Standard_Integer)) &GeomFill_AppSweep::Perform, "None", py::arg("Lin"), py::arg("SecGen"), py::arg("NbMaxP"));
cls_GeomFill_AppSweep.def("IsDone", (Standard_Boolean (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::IsDone, "None");
cls_GeomFill_AppSweep.def("SurfShape", [](GeomFill_AppSweep &self, Standard_Integer & UDegree, Standard_Integer & VDegree, Standard_Integer & NbUPoles, Standard_Integer & NbVPoles, Standard_Integer & NbUKnots, Standard_Integer & NbVKnots){ self.SurfShape(UDegree, VDegree, NbUPoles, NbVPoles, NbUKnots, NbVKnots); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(UDegree, VDegree, NbUPoles, NbVPoles, NbUKnots, NbVKnots); }, "None", py::arg("UDegree"), py::arg("VDegree"), py::arg("NbUPoles"), py::arg("NbVPoles"), py::arg("NbUKnots"), py::arg("NbVKnots"));
cls_GeomFill_AppSweep.def("Surface", (void (GeomFill_AppSweep::*)(TColgp_Array2OfPnt &, TColStd_Array2OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfInteger &, TColStd_Array1OfInteger &) const) &GeomFill_AppSweep::Surface, "None", py::arg("TPoles"), py::arg("TWeights"), py::arg("TUKnots"), py::arg("TVKnots"), py::arg("TUMults"), py::arg("TVMults"));
cls_GeomFill_AppSweep.def("UDegree", (Standard_Integer (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::UDegree, "None");
cls_GeomFill_AppSweep.def("VDegree", (Standard_Integer (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::VDegree, "None");
cls_GeomFill_AppSweep.def("SurfPoles", (const TColgp_Array2OfPnt & (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::SurfPoles, "None");
cls_GeomFill_AppSweep.def("SurfWeights", (const TColStd_Array2OfReal & (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::SurfWeights, "None");
cls_GeomFill_AppSweep.def("SurfUKnots", (const TColStd_Array1OfReal & (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::SurfUKnots, "None");
cls_GeomFill_AppSweep.def("SurfVKnots", (const TColStd_Array1OfReal & (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::SurfVKnots, "None");
cls_GeomFill_AppSweep.def("SurfUMults", (const TColStd_Array1OfInteger & (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::SurfUMults, "None");
cls_GeomFill_AppSweep.def("SurfVMults", (const TColStd_Array1OfInteger & (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::SurfVMults, "None");
cls_GeomFill_AppSweep.def("NbCurves2d", (Standard_Integer (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::NbCurves2d, "None");
cls_GeomFill_AppSweep.def("Curves2dShape", [](GeomFill_AppSweep &self, Standard_Integer & Degree, Standard_Integer & NbPoles, Standard_Integer & NbKnots){ self.Curves2dShape(Degree, NbPoles, NbKnots); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(Degree, NbPoles, NbKnots); }, "None", py::arg("Degree"), py::arg("NbPoles"), py::arg("NbKnots"));
cls_GeomFill_AppSweep.def("Curve2d", (void (GeomFill_AppSweep::*)(const Standard_Integer, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &, TColStd_Array1OfInteger &) const) &GeomFill_AppSweep::Curve2d, "None", py::arg("Index"), py::arg("TPoles"), py::arg("TKnots"), py::arg("TMults"));
cls_GeomFill_AppSweep.def("Curves2dDegree", (Standard_Integer (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::Curves2dDegree, "None");
cls_GeomFill_AppSweep.def("Curve2dPoles", (const TColgp_Array1OfPnt2d & (GeomFill_AppSweep::*)(const Standard_Integer) const) &GeomFill_AppSweep::Curve2dPoles, "None", py::arg("Index"));
cls_GeomFill_AppSweep.def("Curves2dKnots", (const TColStd_Array1OfReal & (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::Curves2dKnots, "None");
cls_GeomFill_AppSweep.def("Curves2dMults", (const TColStd_Array1OfInteger & (GeomFill_AppSweep::*)() const) &GeomFill_AppSweep::Curves2dMults, "None");
cls_GeomFill_AppSweep.def("TolReached", [](GeomFill_AppSweep &self, Standard_Real & Tol3d, Standard_Real & Tol2d){ self.TolReached(Tol3d, Tol2d); return std::tuple<Standard_Real &, Standard_Real &>(Tol3d, Tol2d); }, "None", py::arg("Tol3d"), py::arg("Tol2d"));
cls_GeomFill_AppSweep.def("TolCurveOnSurf", (Standard_Real (GeomFill_AppSweep::*)(const Standard_Integer) const) &GeomFill_AppSweep::TolCurveOnSurf, "None", py::arg("Index"));

// CLASS: GEOMFILL_BEZIERCURVES
py::class_<GeomFill_BezierCurves> cls_GeomFill_BezierCurves(mod, "GeomFill_BezierCurves", "This class provides an algorithm for constructing a Bezier surface filled from contiguous Bezier curves which form its boundaries. The algorithm accepts two, three or four Bezier curves as the boundaries of the target surface. A range of filling styles - more or less rounded, more or less flat - is available. A BezierCurves object provides a framework for: - defining the boundaries, and the filling style of the surface - implementing the construction algorithm - consulting the result. Warning Some problems may show up with rational curves.");

// Constructors
cls_GeomFill_BezierCurves.def(py::init<>());
cls_GeomFill_BezierCurves.def(py::init<const opencascade::handle<Geom_BezierCurve> &, const opencascade::handle<Geom_BezierCurve> &, const opencascade::handle<Geom_BezierCurve> &, const opencascade::handle<Geom_BezierCurve> &, const GeomFill_FillingStyle>(), py::arg("C1"), py::arg("C2"), py::arg("C3"), py::arg("C4"), py::arg("Type"));
cls_GeomFill_BezierCurves.def(py::init<const opencascade::handle<Geom_BezierCurve> &, const opencascade::handle<Geom_BezierCurve> &, const opencascade::handle<Geom_BezierCurve> &, const GeomFill_FillingStyle>(), py::arg("C1"), py::arg("C2"), py::arg("C3"), py::arg("Type"));
cls_GeomFill_BezierCurves.def(py::init<const opencascade::handle<Geom_BezierCurve> &, const opencascade::handle<Geom_BezierCurve> &, const GeomFill_FillingStyle>(), py::arg("C1"), py::arg("C2"), py::arg("Type"));

// Methods
// cls_GeomFill_BezierCurves.def_static("operator new_", (void * (*)(size_t)) &GeomFill_BezierCurves::operator new, "None", py::arg("theSize"));
// cls_GeomFill_BezierCurves.def_static("operator delete_", (void (*)(void *)) &GeomFill_BezierCurves::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_BezierCurves.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_BezierCurves::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_BezierCurves.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_BezierCurves::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_BezierCurves.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_BezierCurves::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_BezierCurves.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_BezierCurves::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_BezierCurves.def("Init", (void (GeomFill_BezierCurves::*)(const opencascade::handle<Geom_BezierCurve> &, const opencascade::handle<Geom_BezierCurve> &, const opencascade::handle<Geom_BezierCurve> &, const opencascade::handle<Geom_BezierCurve> &, const GeomFill_FillingStyle)) &GeomFill_BezierCurves::Init, "if the curves cannot be joined", py::arg("C1"), py::arg("C2"), py::arg("C3"), py::arg("C4"), py::arg("Type"));
cls_GeomFill_BezierCurves.def("Init", (void (GeomFill_BezierCurves::*)(const opencascade::handle<Geom_BezierCurve> &, const opencascade::handle<Geom_BezierCurve> &, const opencascade::handle<Geom_BezierCurve> &, const GeomFill_FillingStyle)) &GeomFill_BezierCurves::Init, "if the curves cannot be joined", py::arg("C1"), py::arg("C2"), py::arg("C3"), py::arg("Type"));
cls_GeomFill_BezierCurves.def("Init", (void (GeomFill_BezierCurves::*)(const opencascade::handle<Geom_BezierCurve> &, const opencascade::handle<Geom_BezierCurve> &, const GeomFill_FillingStyle)) &GeomFill_BezierCurves::Init, "Initializes or reinitializes this algorithm with two, three, or four curves - C1, C2, C3, and C4 - and Type, one of the following filling styles: - GeomFill_Stretch - the style with the flattest patch - GeomFill_Coons - a rounded style of patch with less depth than that of Curved - GeomFill_Curved - the style with the most rounded patch. Exceptions Standard_ConstructionError if the curves are not contiguous.", py::arg("C1"), py::arg("C2"), py::arg("Type"));
cls_GeomFill_BezierCurves.def("Surface", (const opencascade::handle<Geom_BezierSurface> & (GeomFill_BezierCurves::*)() const) &GeomFill_BezierCurves::Surface, "Returns the Bezier surface resulting from the computation performed by this algorithm.");

// CLASS: GEOMFILL_BSPLINECURVES
py::class_<GeomFill_BSplineCurves> cls_GeomFill_BSplineCurves(mod, "GeomFill_BSplineCurves", "An algorithm for constructing a BSpline surface filled from contiguous BSpline curves which form its boundaries. The algorithm accepts two, three or four BSpline curves as the boundaries of the target surface. A range of filling styles - more or less rounded, more or less flat - is available. A BSplineCurves object provides a framework for: - defining the boundaries, and the filling style of the surface - implementing the construction algorithm - consulting the result. Warning Some problems may show up with rational curves.");

// Constructors
cls_GeomFill_BSplineCurves.def(py::init<>());
cls_GeomFill_BSplineCurves.def(py::init<const opencascade::handle<Geom_BSplineCurve> &, const opencascade::handle<Geom_BSplineCurve> &, const opencascade::handle<Geom_BSplineCurve> &, const opencascade::handle<Geom_BSplineCurve> &, const GeomFill_FillingStyle>(), py::arg("C1"), py::arg("C2"), py::arg("C3"), py::arg("C4"), py::arg("Type"));
cls_GeomFill_BSplineCurves.def(py::init<const opencascade::handle<Geom_BSplineCurve> &, const opencascade::handle<Geom_BSplineCurve> &, const opencascade::handle<Geom_BSplineCurve> &, const GeomFill_FillingStyle>(), py::arg("C1"), py::arg("C2"), py::arg("C3"), py::arg("Type"));
cls_GeomFill_BSplineCurves.def(py::init<const opencascade::handle<Geom_BSplineCurve> &, const opencascade::handle<Geom_BSplineCurve> &, const GeomFill_FillingStyle>(), py::arg("C1"), py::arg("C2"), py::arg("Type"));

// Methods
// cls_GeomFill_BSplineCurves.def_static("operator new_", (void * (*)(size_t)) &GeomFill_BSplineCurves::operator new, "None", py::arg("theSize"));
// cls_GeomFill_BSplineCurves.def_static("operator delete_", (void (*)(void *)) &GeomFill_BSplineCurves::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_BSplineCurves.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_BSplineCurves::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_BSplineCurves.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_BSplineCurves::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_BSplineCurves.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_BSplineCurves::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_BSplineCurves.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_BSplineCurves::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_BSplineCurves.def("Init", (void (GeomFill_BSplineCurves::*)(const opencascade::handle<Geom_BSplineCurve> &, const opencascade::handle<Geom_BSplineCurve> &, const opencascade::handle<Geom_BSplineCurve> &, const opencascade::handle<Geom_BSplineCurve> &, const GeomFill_FillingStyle)) &GeomFill_BSplineCurves::Init, "if the curves cannot be joined", py::arg("C1"), py::arg("C2"), py::arg("C3"), py::arg("C4"), py::arg("Type"));
cls_GeomFill_BSplineCurves.def("Init", (void (GeomFill_BSplineCurves::*)(const opencascade::handle<Geom_BSplineCurve> &, const opencascade::handle<Geom_BSplineCurve> &, const opencascade::handle<Geom_BSplineCurve> &, const GeomFill_FillingStyle)) &GeomFill_BSplineCurves::Init, "if the curves cannot be joined", py::arg("C1"), py::arg("C2"), py::arg("C3"), py::arg("Type"));
cls_GeomFill_BSplineCurves.def("Init", (void (GeomFill_BSplineCurves::*)(const opencascade::handle<Geom_BSplineCurve> &, const opencascade::handle<Geom_BSplineCurve> &, const GeomFill_FillingStyle)) &GeomFill_BSplineCurves::Init, "Initializes or reinitializes this algorithm with two, three, or four curves - C1, C2, C3, and C4 - and Type, one of the following filling styles: - GeomFill_Stretch - the style with the flattest patch - GeomFill_Coons - a rounded style of patch with less depth than that of Curved - GeomFill_Curved - the style with the most rounded patch. Exceptions Standard_ConstructionError if the curves are not contiguous.", py::arg("C1"), py::arg("C2"), py::arg("Type"));
cls_GeomFill_BSplineCurves.def("Surface", (const opencascade::handle<Geom_BSplineSurface> & (GeomFill_BSplineCurves::*)() const) &GeomFill_BSplineCurves::Surface, "Returns the BSpline surface Surface resulting from the computation performed by this algorithm.");

// CLASS: GEOMFILL_CIRCULARBLENDFUNC
py::class_<GeomFill_CircularBlendFunc, opencascade::handle<GeomFill_CircularBlendFunc>, Approx_SweepFunction> cls_GeomFill_CircularBlendFunc(mod, "GeomFill_CircularBlendFunc", "Circular Blend Function to approximate by SweepApproximation from Approx");

// Constructors
cls_GeomFill_CircularBlendFunc.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real>(), py::arg("Path"), py::arg("Curve1"), py::arg("Curve2"), py::arg("Radius"));
cls_GeomFill_CircularBlendFunc.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Boolean>(), py::arg("Path"), py::arg("Curve1"), py::arg("Curve2"), py::arg("Radius"), py::arg("Polynomial"));

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

// CLASS: GEOMFILL_TRIHEDRONLAW
py::class_<GeomFill_TrihedronLaw, opencascade::handle<GeomFill_TrihedronLaw>, Standard_Transient> cls_GeomFill_TrihedronLaw(mod, "GeomFill_TrihedronLaw", "To define Trihedron along one Curve");

// Methods
cls_GeomFill_TrihedronLaw.def("SetCurve", (void (GeomFill_TrihedronLaw::*)(const opencascade::handle<Adaptor3d_HCurve> &)) &GeomFill_TrihedronLaw::SetCurve, "None", py::arg("C"));
cls_GeomFill_TrihedronLaw.def("Copy", (opencascade::handle<GeomFill_TrihedronLaw> (GeomFill_TrihedronLaw::*)() const) &GeomFill_TrihedronLaw::Copy, "None");
cls_GeomFill_TrihedronLaw.def("ErrorStatus", (GeomFill_PipeError (GeomFill_TrihedronLaw::*)() const) &GeomFill_TrihedronLaw::ErrorStatus, "Give a status to the Law Returns PipeOk (default implementation)");
cls_GeomFill_TrihedronLaw.def("D0", (Standard_Boolean (GeomFill_TrihedronLaw::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_TrihedronLaw::D0, "compute Triedrhon on curve at parameter <Param>", py::arg("Param"), py::arg("Tangent"), py::arg("Normal"), py::arg("BiNormal"));
cls_GeomFill_TrihedronLaw.def("D1", (Standard_Boolean (GeomFill_TrihedronLaw::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_TrihedronLaw::D1, "compute Triedrhon and derivative Trihedron on curve at parameter <Param> Warning : It used only for C1 or C2 aproximation", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("BiNormal"), py::arg("DBiNormal"));
cls_GeomFill_TrihedronLaw.def("D2", (Standard_Boolean (GeomFill_TrihedronLaw::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_TrihedronLaw::D2, "compute Trihedron on curve first and seconde derivatives. Warning : It used only for C2 aproximation", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("D2Tangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("D2Normal"), py::arg("BiNormal"), py::arg("DBiNormal"), py::arg("D2BiNormal"));
cls_GeomFill_TrihedronLaw.def("NbIntervals", (Standard_Integer (GeomFill_TrihedronLaw::*)(const GeomAbs_Shape) const) &GeomFill_TrihedronLaw::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_TrihedronLaw.def("Intervals", (void (GeomFill_TrihedronLaw::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_TrihedronLaw::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_TrihedronLaw.def("SetInterval", (void (GeomFill_TrihedronLaw::*)(const Standard_Real, const Standard_Real)) &GeomFill_TrihedronLaw::SetInterval, "Sets the bounds of the parametric interval on the function This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_GeomFill_TrihedronLaw.def("GetInterval", [](GeomFill_TrihedronLaw &self, Standard_Real & First, Standard_Real & Last){ self.GetInterval(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "Gets the bounds of the parametric interval on the function", py::arg("First"), py::arg("Last"));
cls_GeomFill_TrihedronLaw.def("GetAverageLaw", (void (GeomFill_TrihedronLaw::*)(gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_TrihedronLaw::GetAverageLaw, "Get average value of M(t) and V(t) it is usfull to make fast approximation of rational surfaces.", py::arg("ATangent"), py::arg("ANormal"), py::arg("ABiNormal"));
cls_GeomFill_TrihedronLaw.def("IsConstant", (Standard_Boolean (GeomFill_TrihedronLaw::*)() const) &GeomFill_TrihedronLaw::IsConstant, "Say if the law is Constant");
cls_GeomFill_TrihedronLaw.def("IsOnlyBy3dCurve", (Standard_Boolean (GeomFill_TrihedronLaw::*)() const) &GeomFill_TrihedronLaw::IsOnlyBy3dCurve, "Say if the law is defined, only by the 3d Geometry of the setted Curve Return False by Default.");
cls_GeomFill_TrihedronLaw.def_static("get_type_name_", (const char * (*)()) &GeomFill_TrihedronLaw::get_type_name, "None");
cls_GeomFill_TrihedronLaw.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_TrihedronLaw::get_type_descriptor, "None");
cls_GeomFill_TrihedronLaw.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_TrihedronLaw::*)() const) &GeomFill_TrihedronLaw::DynamicType, "None");

// CLASS: GEOMFILL_CONSTANTBINORMAL
py::class_<GeomFill_ConstantBiNormal, opencascade::handle<GeomFill_ConstantBiNormal>, GeomFill_TrihedronLaw> cls_GeomFill_ConstantBiNormal(mod, "GeomFill_ConstantBiNormal", "Defined an Trihedron Law where the BiNormal, is fixed");

// Constructors
cls_GeomFill_ConstantBiNormal.def(py::init<const gp_Dir &>(), py::arg("BiNormal"));

// Methods
cls_GeomFill_ConstantBiNormal.def("Copy", (opencascade::handle<GeomFill_TrihedronLaw> (GeomFill_ConstantBiNormal::*)() const) &GeomFill_ConstantBiNormal::Copy, "None");
cls_GeomFill_ConstantBiNormal.def("SetCurve", (void (GeomFill_ConstantBiNormal::*)(const opencascade::handle<Adaptor3d_HCurve> &)) &GeomFill_ConstantBiNormal::SetCurve, "None", py::arg("C"));
cls_GeomFill_ConstantBiNormal.def("D0", (Standard_Boolean (GeomFill_ConstantBiNormal::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_ConstantBiNormal::D0, "Computes Triedrhon on curve at parameter <Param>", py::arg("Param"), py::arg("Tangent"), py::arg("Normal"), py::arg("BiNormal"));
cls_GeomFill_ConstantBiNormal.def("D1", (Standard_Boolean (GeomFill_ConstantBiNormal::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_ConstantBiNormal::D1, "Computes Triedrhon and derivative Trihedron on curve at parameter <Param> Warning : It used only for C1 or C2 aproximation", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("BiNormal"), py::arg("DBiNormal"));
cls_GeomFill_ConstantBiNormal.def("D2", (Standard_Boolean (GeomFill_ConstantBiNormal::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_ConstantBiNormal::D2, "compute Trihedron on curve first and seconde derivatives. Warning : It used only for C2 aproximation", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("D2Tangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("D2Normal"), py::arg("BiNormal"), py::arg("DBiNormal"), py::arg("D2BiNormal"));
cls_GeomFill_ConstantBiNormal.def("NbIntervals", (Standard_Integer (GeomFill_ConstantBiNormal::*)(const GeomAbs_Shape) const) &GeomFill_ConstantBiNormal::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_ConstantBiNormal.def("Intervals", (void (GeomFill_ConstantBiNormal::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_ConstantBiNormal::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_ConstantBiNormal.def("GetAverageLaw", (void (GeomFill_ConstantBiNormal::*)(gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_ConstantBiNormal::GetAverageLaw, "Gets average value of Tangent(t) and Normal(t) it is usfull to make fast approximation of rational surfaces.", py::arg("ATangent"), py::arg("ANormal"), py::arg("ABiNormal"));
cls_GeomFill_ConstantBiNormal.def("IsConstant", (Standard_Boolean (GeomFill_ConstantBiNormal::*)() const) &GeomFill_ConstantBiNormal::IsConstant, "Says if the law is Constant.");
cls_GeomFill_ConstantBiNormal.def("IsOnlyBy3dCurve", (Standard_Boolean (GeomFill_ConstantBiNormal::*)() const) &GeomFill_ConstantBiNormal::IsOnlyBy3dCurve, "Return True.");
cls_GeomFill_ConstantBiNormal.def_static("get_type_name_", (const char * (*)()) &GeomFill_ConstantBiNormal::get_type_name, "None");
cls_GeomFill_ConstantBiNormal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_ConstantBiNormal::get_type_descriptor, "None");
cls_GeomFill_ConstantBiNormal.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_ConstantBiNormal::*)() const) &GeomFill_ConstantBiNormal::DynamicType, "None");

// CLASS: GEOMFILL_FILLING
py::class_<GeomFill_Filling> cls_GeomFill_Filling(mod, "GeomFill_Filling", "Root class for Filling;");

// Constructors
cls_GeomFill_Filling.def(py::init<>());

// Methods
// cls_GeomFill_Filling.def_static("operator new_", (void * (*)(size_t)) &GeomFill_Filling::operator new, "None", py::arg("theSize"));
// cls_GeomFill_Filling.def_static("operator delete_", (void (*)(void *)) &GeomFill_Filling::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_Filling.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_Filling::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_Filling.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_Filling::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_Filling.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_Filling::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_Filling.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_Filling::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_Filling.def("NbUPoles", (Standard_Integer (GeomFill_Filling::*)() const) &GeomFill_Filling::NbUPoles, "None");
cls_GeomFill_Filling.def("NbVPoles", (Standard_Integer (GeomFill_Filling::*)() const) &GeomFill_Filling::NbVPoles, "None");
cls_GeomFill_Filling.def("Poles", (void (GeomFill_Filling::*)(TColgp_Array2OfPnt &) const) &GeomFill_Filling::Poles, "None", py::arg("Poles"));
cls_GeomFill_Filling.def("isRational", (Standard_Boolean (GeomFill_Filling::*)() const) &GeomFill_Filling::isRational, "None");
cls_GeomFill_Filling.def("Weights", (void (GeomFill_Filling::*)(TColStd_Array2OfReal &) const) &GeomFill_Filling::Weights, "None", py::arg("Weights"));

// CLASS: GEOMFILL_COONS
py::class_<GeomFill_Coons, GeomFill_Filling> cls_GeomFill_Coons(mod, "GeomFill_Coons", "None");

// Constructors
cls_GeomFill_Coons.def(py::init<>());
cls_GeomFill_Coons.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"));
cls_GeomFill_Coons.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"), py::arg("W1"), py::arg("W2"), py::arg("W3"), py::arg("W4"));

// Methods
// cls_GeomFill_Coons.def_static("operator new_", (void * (*)(size_t)) &GeomFill_Coons::operator new, "None", py::arg("theSize"));
// cls_GeomFill_Coons.def_static("operator delete_", (void (*)(void *)) &GeomFill_Coons::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_Coons.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_Coons::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_Coons.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_Coons::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_Coons.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_Coons::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_Coons.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_Coons::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_Coons.def("Init", (void (GeomFill_Coons::*)(const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &)) &GeomFill_Coons::Init, "None", py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"));
cls_GeomFill_Coons.def("Init", (void (GeomFill_Coons::*)(const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &)) &GeomFill_Coons::Init, "None", py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"), py::arg("W1"), py::arg("W2"), py::arg("W3"), py::arg("W4"));

// CLASS: GEOMFILL_COONSALGPATCH
py::class_<GeomFill_CoonsAlgPatch, opencascade::handle<GeomFill_CoonsAlgPatch>, Standard_Transient> cls_GeomFill_CoonsAlgPatch(mod, "GeomFill_CoonsAlgPatch", "Provides evaluation methods on an algorithmic patch (based on 4 Curves) defined by its boundaries and blending functions.");

// Constructors
cls_GeomFill_CoonsAlgPatch.def(py::init<const opencascade::handle<GeomFill_Boundary> &, const opencascade::handle<GeomFill_Boundary> &, const opencascade::handle<GeomFill_Boundary> &, const opencascade::handle<GeomFill_Boundary> &>(), py::arg("B1"), py::arg("B2"), py::arg("B3"), py::arg("B4"));

// Methods
cls_GeomFill_CoonsAlgPatch.def("Func", (void (GeomFill_CoonsAlgPatch::*)(opencascade::handle<Law_Function> &, opencascade::handle<Law_Function> &) const) &GeomFill_CoonsAlgPatch::Func, "Give the blending functions.", py::arg("f1"), py::arg("f2"));
cls_GeomFill_CoonsAlgPatch.def("SetFunc", (void (GeomFill_CoonsAlgPatch::*)(const opencascade::handle<Law_Function> &, const opencascade::handle<Law_Function> &)) &GeomFill_CoonsAlgPatch::SetFunc, "Set the blending functions.", py::arg("f1"), py::arg("f2"));
cls_GeomFill_CoonsAlgPatch.def("Value", (gp_Pnt (GeomFill_CoonsAlgPatch::*)(const Standard_Real, const Standard_Real) const) &GeomFill_CoonsAlgPatch::Value, "Computes the value on the algorithmic patch at parameters U and V.", py::arg("U"), py::arg("V"));
cls_GeomFill_CoonsAlgPatch.def("D1U", (gp_Vec (GeomFill_CoonsAlgPatch::*)(const Standard_Real, const Standard_Real) const) &GeomFill_CoonsAlgPatch::D1U, "Computes the d/dU partial derivative on the algorithmic patch at parameters U and V.", py::arg("U"), py::arg("V"));
cls_GeomFill_CoonsAlgPatch.def("D1V", (gp_Vec (GeomFill_CoonsAlgPatch::*)(const Standard_Real, const Standard_Real) const) &GeomFill_CoonsAlgPatch::D1V, "Computes the d/dV partial derivative on the algorithmic patch at parameters U and V.", py::arg("U"), py::arg("V"));
cls_GeomFill_CoonsAlgPatch.def("DUV", (gp_Vec (GeomFill_CoonsAlgPatch::*)(const Standard_Real, const Standard_Real) const) &GeomFill_CoonsAlgPatch::DUV, "Computes the d2/dUdV partial derivative on the algorithmic patch made with linear blending functions at parameter U and V.", py::arg("U"), py::arg("V"));
cls_GeomFill_CoonsAlgPatch.def("Corner", (const gp_Pnt & (GeomFill_CoonsAlgPatch::*)(const Standard_Integer) const) &GeomFill_CoonsAlgPatch::Corner, "None", py::arg("I"));
cls_GeomFill_CoonsAlgPatch.def("Bound", (const opencascade::handle<GeomFill_Boundary> & (GeomFill_CoonsAlgPatch::*)(const Standard_Integer) const) &GeomFill_CoonsAlgPatch::Bound, "None", py::arg("I"));
cls_GeomFill_CoonsAlgPatch.def("Func", (const opencascade::handle<Law_Function> & (GeomFill_CoonsAlgPatch::*)(const Standard_Integer) const) &GeomFill_CoonsAlgPatch::Func, "None", py::arg("I"));
cls_GeomFill_CoonsAlgPatch.def_static("get_type_name_", (const char * (*)()) &GeomFill_CoonsAlgPatch::get_type_name, "None");
cls_GeomFill_CoonsAlgPatch.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_CoonsAlgPatch::get_type_descriptor, "None");
cls_GeomFill_CoonsAlgPatch.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_CoonsAlgPatch::*)() const) &GeomFill_CoonsAlgPatch::DynamicType, "None");

// CLASS: GEOMFILL_CORRECTEDFRENET
py::class_<GeomFill_CorrectedFrenet, opencascade::handle<GeomFill_CorrectedFrenet>, GeomFill_TrihedronLaw> cls_GeomFill_CorrectedFrenet(mod, "GeomFill_CorrectedFrenet", "Defined an Corrected Frenet Trihedron Law It is like Frenet with an Torsion's minimization");

// Constructors
cls_GeomFill_CorrectedFrenet.def(py::init<>());
cls_GeomFill_CorrectedFrenet.def(py::init<const Standard_Boolean>(), py::arg("ForEvaluation"));

// Methods
cls_GeomFill_CorrectedFrenet.def("Copy", (opencascade::handle<GeomFill_TrihedronLaw> (GeomFill_CorrectedFrenet::*)() const) &GeomFill_CorrectedFrenet::Copy, "None");
cls_GeomFill_CorrectedFrenet.def("SetCurve", (void (GeomFill_CorrectedFrenet::*)(const opencascade::handle<Adaptor3d_HCurve> &)) &GeomFill_CorrectedFrenet::SetCurve, "None", py::arg("C"));
cls_GeomFill_CorrectedFrenet.def("SetInterval", (void (GeomFill_CorrectedFrenet::*)(const Standard_Real, const Standard_Real)) &GeomFill_CorrectedFrenet::SetInterval, "None", py::arg("First"), py::arg("Last"));
cls_GeomFill_CorrectedFrenet.def("D0", (Standard_Boolean (GeomFill_CorrectedFrenet::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_CorrectedFrenet::D0, "compute Triedrhon on curve at parameter <Param>", py::arg("Param"), py::arg("Tangent"), py::arg("Normal"), py::arg("BiNormal"));
cls_GeomFill_CorrectedFrenet.def("D1", (Standard_Boolean (GeomFill_CorrectedFrenet::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_CorrectedFrenet::D1, "compute Triedrhon and derivative Trihedron on curve at parameter <Param> Warning : It used only for C1 or C2 aproximation", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("BiNormal"), py::arg("DBiNormal"));
cls_GeomFill_CorrectedFrenet.def("D2", (Standard_Boolean (GeomFill_CorrectedFrenet::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_CorrectedFrenet::D2, "compute Trihedron on curve first and seconde derivatives. Warning : It used only for C2 aproximation", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("D2Tangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("D2Normal"), py::arg("BiNormal"), py::arg("DBiNormal"), py::arg("D2BiNormal"));
cls_GeomFill_CorrectedFrenet.def("NbIntervals", (Standard_Integer (GeomFill_CorrectedFrenet::*)(const GeomAbs_Shape) const) &GeomFill_CorrectedFrenet::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_CorrectedFrenet.def("Intervals", (void (GeomFill_CorrectedFrenet::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_CorrectedFrenet::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_CorrectedFrenet.def("EvaluateBestMode", (GeomFill_Trihedron (GeomFill_CorrectedFrenet::*)()) &GeomFill_CorrectedFrenet::EvaluateBestMode, "Tries to define the best trihedron mode for the curve. It can be: - Frenet - CorrectedFrenet - DiscreteTrihedron Warning: the CorrectedFrenet must be constructed with option ForEvaluation = True, the curve must be set by method SetCurve.");
cls_GeomFill_CorrectedFrenet.def("GetAverageLaw", (void (GeomFill_CorrectedFrenet::*)(gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_CorrectedFrenet::GetAverageLaw, "Get average value of Tangent(t) and Normal(t) it is usfull to make fast approximation of rational surfaces.", py::arg("ATangent"), py::arg("ANormal"), py::arg("ABiNormal"));
cls_GeomFill_CorrectedFrenet.def("IsConstant", (Standard_Boolean (GeomFill_CorrectedFrenet::*)() const) &GeomFill_CorrectedFrenet::IsConstant, "Say if the law is Constant.");
cls_GeomFill_CorrectedFrenet.def("IsOnlyBy3dCurve", (Standard_Boolean (GeomFill_CorrectedFrenet::*)() const) &GeomFill_CorrectedFrenet::IsOnlyBy3dCurve, "Return True.");
cls_GeomFill_CorrectedFrenet.def_static("get_type_name_", (const char * (*)()) &GeomFill_CorrectedFrenet::get_type_name, "None");
cls_GeomFill_CorrectedFrenet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_CorrectedFrenet::get_type_descriptor, "None");
cls_GeomFill_CorrectedFrenet.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_CorrectedFrenet::*)() const) &GeomFill_CorrectedFrenet::DynamicType, "None");

// CLASS: GEOMFILL_CURVEANDTRIHEDRON
py::class_<GeomFill_CurveAndTrihedron, opencascade::handle<GeomFill_CurveAndTrihedron>, GeomFill_LocationLaw> cls_GeomFill_CurveAndTrihedron(mod, "GeomFill_CurveAndTrihedron", "Define location law with an TrihedronLaw and an curve Definition Location is : transformed section coordinates in (Curve(v)), (Normal(v), BiNormal(v), Tangente(v))) systeme are the same like section shape coordinates in (O,(OX, OY, OZ)) systeme.");

// Constructors
cls_GeomFill_CurveAndTrihedron.def(py::init<const opencascade::handle<GeomFill_TrihedronLaw> &>(), py::arg("Trihedron"));

// Methods
cls_GeomFill_CurveAndTrihedron.def("SetCurve", (void (GeomFill_CurveAndTrihedron::*)(const opencascade::handle<Adaptor3d_HCurve> &)) &GeomFill_CurveAndTrihedron::SetCurve, "None", py::arg("C"));
cls_GeomFill_CurveAndTrihedron.def("GetCurve", (const opencascade::handle<Adaptor3d_HCurve> & (GeomFill_CurveAndTrihedron::*)() const) &GeomFill_CurveAndTrihedron::GetCurve, "None");
cls_GeomFill_CurveAndTrihedron.def("SetTrsf", (void (GeomFill_CurveAndTrihedron::*)(const gp_Mat &)) &GeomFill_CurveAndTrihedron::SetTrsf, "Set a transformation Matrix like the law M(t) become Mat * M(t)", py::arg("Transfo"));
cls_GeomFill_CurveAndTrihedron.def("Copy", (opencascade::handle<GeomFill_LocationLaw> (GeomFill_CurveAndTrihedron::*)() const) &GeomFill_CurveAndTrihedron::Copy, "None");
cls_GeomFill_CurveAndTrihedron.def("D0", (Standard_Boolean (GeomFill_CurveAndTrihedron::*)(const Standard_Real, gp_Mat &, gp_Vec &)) &GeomFill_CurveAndTrihedron::D0, "compute Location and 2d points", py::arg("Param"), py::arg("M"), py::arg("V"));
cls_GeomFill_CurveAndTrihedron.def("D0", (Standard_Boolean (GeomFill_CurveAndTrihedron::*)(const Standard_Real, gp_Mat &, gp_Vec &, TColgp_Array1OfPnt2d &)) &GeomFill_CurveAndTrihedron::D0, "compute Location and 2d points", py::arg("Param"), py::arg("M"), py::arg("V"), py::arg("Poles2d"));
cls_GeomFill_CurveAndTrihedron.def("D1", (Standard_Boolean (GeomFill_CurveAndTrihedron::*)(const Standard_Real, gp_Mat &, gp_Vec &, gp_Mat &, gp_Vec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &)) &GeomFill_CurveAndTrihedron::D1, "compute location 2d points and associated first derivatives. Warning : It used only for C1 or C2 aproximation", py::arg("Param"), py::arg("M"), py::arg("V"), py::arg("DM"), py::arg("DV"), py::arg("Poles2d"), py::arg("DPoles2d"));
cls_GeomFill_CurveAndTrihedron.def("D2", (Standard_Boolean (GeomFill_CurveAndTrihedron::*)(const Standard_Real, gp_Mat &, gp_Vec &, gp_Mat &, gp_Vec &, gp_Mat &, gp_Vec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &)) &GeomFill_CurveAndTrihedron::D2, "compute location 2d points and associated first and seconde derivatives. Warning : It used only for C2 aproximation", py::arg("Param"), py::arg("M"), py::arg("V"), py::arg("DM"), py::arg("DV"), py::arg("D2M"), py::arg("D2V"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"));
cls_GeomFill_CurveAndTrihedron.def("NbIntervals", (Standard_Integer (GeomFill_CurveAndTrihedron::*)(const GeomAbs_Shape) const) &GeomFill_CurveAndTrihedron::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_CurveAndTrihedron.def("Intervals", (void (GeomFill_CurveAndTrihedron::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_CurveAndTrihedron::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_CurveAndTrihedron.def("SetInterval", (void (GeomFill_CurveAndTrihedron::*)(const Standard_Real, const Standard_Real)) &GeomFill_CurveAndTrihedron::SetInterval, "Sets the bounds of the parametric interval on the function This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_GeomFill_CurveAndTrihedron.def("GetInterval", [](GeomFill_CurveAndTrihedron &self, Standard_Real & First, Standard_Real & Last){ self.GetInterval(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "Gets the bounds of the parametric interval on the function", py::arg("First"), py::arg("Last"));
cls_GeomFill_CurveAndTrihedron.def("GetDomain", [](GeomFill_CurveAndTrihedron &self, Standard_Real & First, Standard_Real & Last){ self.GetDomain(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "Gets the bounds of the function parametric domain. Warning: This domain it is not modified by the SetValue method", py::arg("First"), py::arg("Last"));
cls_GeomFill_CurveAndTrihedron.def("GetMaximalNorm", (Standard_Real (GeomFill_CurveAndTrihedron::*)()) &GeomFill_CurveAndTrihedron::GetMaximalNorm, "Get the maximum Norm of the matrix-location part. It is usful to find an good Tolerance to approx M(t).");
cls_GeomFill_CurveAndTrihedron.def("GetAverageLaw", (void (GeomFill_CurveAndTrihedron::*)(gp_Mat &, gp_Vec &)) &GeomFill_CurveAndTrihedron::GetAverageLaw, "Get average value of M(t) and V(t) it is usfull to make fast approximation of rational surfaces.", py::arg("AM"), py::arg("AV"));
cls_GeomFill_CurveAndTrihedron.def("IsTranslation", [](GeomFill_CurveAndTrihedron &self, Standard_Real & Error){ Standard_Boolean rv = self.IsTranslation(Error); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Error); }, "Say if the Location Law, is an translation of Location The default implementation is ' returns False '.", py::arg("Error"));
cls_GeomFill_CurveAndTrihedron.def("IsRotation", [](GeomFill_CurveAndTrihedron &self, Standard_Real & Error){ Standard_Boolean rv = self.IsRotation(Error); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Error); }, "Say if the Location Law, is a rotation of Location The default implementation is ' returns False '.", py::arg("Error"));
cls_GeomFill_CurveAndTrihedron.def("Rotation", (void (GeomFill_CurveAndTrihedron::*)(gp_Pnt &) const) &GeomFill_CurveAndTrihedron::Rotation, "None", py::arg("Center"));
cls_GeomFill_CurveAndTrihedron.def_static("get_type_name_", (const char * (*)()) &GeomFill_CurveAndTrihedron::get_type_name, "None");
cls_GeomFill_CurveAndTrihedron.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_CurveAndTrihedron::get_type_descriptor, "None");
cls_GeomFill_CurveAndTrihedron.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_CurveAndTrihedron::*)() const) &GeomFill_CurveAndTrihedron::DynamicType, "None");

// CLASS: GEOMFILL_CURVED
py::class_<GeomFill_Curved, GeomFill_Filling> cls_GeomFill_Curved(mod, "GeomFill_Curved", "None");

// Constructors
cls_GeomFill_Curved.def(py::init<>());
cls_GeomFill_Curved.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"));
cls_GeomFill_Curved.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"), py::arg("W1"), py::arg("W2"), py::arg("W3"), py::arg("W4"));
cls_GeomFill_Curved.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &>(), py::arg("P1"), py::arg("P2"));
cls_GeomFill_Curved.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &>(), py::arg("P1"), py::arg("P2"), py::arg("W1"), py::arg("W2"));

// Methods
// cls_GeomFill_Curved.def_static("operator new_", (void * (*)(size_t)) &GeomFill_Curved::operator new, "None", py::arg("theSize"));
// cls_GeomFill_Curved.def_static("operator delete_", (void (*)(void *)) &GeomFill_Curved::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_Curved.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_Curved::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_Curved.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_Curved::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_Curved.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_Curved::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_Curved.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_Curved::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_Curved.def("Init", (void (GeomFill_Curved::*)(const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &)) &GeomFill_Curved::Init, "None", py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"));
cls_GeomFill_Curved.def("Init", (void (GeomFill_Curved::*)(const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &)) &GeomFill_Curved::Init, "None", py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"), py::arg("W1"), py::arg("W2"), py::arg("W3"), py::arg("W4"));
cls_GeomFill_Curved.def("Init", (void (GeomFill_Curved::*)(const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &)) &GeomFill_Curved::Init, "None", py::arg("P1"), py::arg("P2"));
cls_GeomFill_Curved.def("Init", (void (GeomFill_Curved::*)(const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &)) &GeomFill_Curved::Init, "None", py::arg("P1"), py::arg("P2"), py::arg("W1"), py::arg("W2"));

// CLASS: GEOMFILL_DARBOUX
py::class_<GeomFill_Darboux, opencascade::handle<GeomFill_Darboux>, GeomFill_TrihedronLaw> cls_GeomFill_Darboux(mod, "GeomFill_Darboux", "Defines Darboux case of Frenet Trihedron Law");

// Constructors
cls_GeomFill_Darboux.def(py::init<>());

// Methods
cls_GeomFill_Darboux.def("Copy", (opencascade::handle<GeomFill_TrihedronLaw> (GeomFill_Darboux::*)() const) &GeomFill_Darboux::Copy, "None");
cls_GeomFill_Darboux.def("D0", (Standard_Boolean (GeomFill_Darboux::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_Darboux::D0, "compute Triedrhon on curve at parameter <Param>", py::arg("Param"), py::arg("Tangent"), py::arg("Normal"), py::arg("BiNormal"));
cls_GeomFill_Darboux.def("D1", (Standard_Boolean (GeomFill_Darboux::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_Darboux::D1, "compute Triedrhon and derivative Trihedron on curve at parameter <Param> Warning : It used only for C1 or C2 aproximation", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("BiNormal"), py::arg("DBiNormal"));
cls_GeomFill_Darboux.def("D2", (Standard_Boolean (GeomFill_Darboux::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_Darboux::D2, "compute Trihedron on curve first and seconde derivatives. Warning : It used only for C2 aproximation", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("D2Tangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("D2Normal"), py::arg("BiNormal"), py::arg("DBiNormal"), py::arg("D2BiNormal"));
cls_GeomFill_Darboux.def("NbIntervals", (Standard_Integer (GeomFill_Darboux::*)(const GeomAbs_Shape) const) &GeomFill_Darboux::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_Darboux.def("Intervals", (void (GeomFill_Darboux::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_Darboux::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_Darboux.def("GetAverageLaw", (void (GeomFill_Darboux::*)(gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_Darboux::GetAverageLaw, "Get average value of Tangent(t) and Normal(t) it is usfull to make fast approximation of rational surfaces.", py::arg("ATangent"), py::arg("ANormal"), py::arg("ABiNormal"));
cls_GeomFill_Darboux.def("IsConstant", (Standard_Boolean (GeomFill_Darboux::*)() const) &GeomFill_Darboux::IsConstant, "Say if the law is Constant.");
cls_GeomFill_Darboux.def("IsOnlyBy3dCurve", (Standard_Boolean (GeomFill_Darboux::*)() const) &GeomFill_Darboux::IsOnlyBy3dCurve, "Return False.");
cls_GeomFill_Darboux.def_static("get_type_name_", (const char * (*)()) &GeomFill_Darboux::get_type_name, "None");
cls_GeomFill_Darboux.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_Darboux::get_type_descriptor, "None");
cls_GeomFill_Darboux.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_Darboux::*)() const) &GeomFill_Darboux::DynamicType, "None");

// CLASS: GEOMFILL_DEGENERATEDBOUND
py::class_<GeomFill_DegeneratedBound, opencascade::handle<GeomFill_DegeneratedBound>, GeomFill_Boundary> cls_GeomFill_DegeneratedBound(mod, "GeomFill_DegeneratedBound", "Description of a degenerated boundary (a point). Class defining a degenerated boundary for a constrained filling with a point and no other constraint. Only used to simulate an ordinary bound, may not be usefull and desapear soon.");

// Constructors
cls_GeomFill_DegeneratedBound.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Point"), py::arg("First"), py::arg("Last"), py::arg("Tol3d"), py::arg("Tolang"));

// Methods
cls_GeomFill_DegeneratedBound.def("Value", (gp_Pnt (GeomFill_DegeneratedBound::*)(const Standard_Real) const) &GeomFill_DegeneratedBound::Value, "None", py::arg("U"));
cls_GeomFill_DegeneratedBound.def("D1", (void (GeomFill_DegeneratedBound::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &GeomFill_DegeneratedBound::D1, "None", py::arg("U"), py::arg("P"), py::arg("V"));
cls_GeomFill_DegeneratedBound.def("Reparametrize", (void (GeomFill_DegeneratedBound::*)(const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_Boolean)) &GeomFill_DegeneratedBound::Reparametrize, "None", py::arg("First"), py::arg("Last"), py::arg("HasDF"), py::arg("HasDL"), py::arg("DF"), py::arg("DL"), py::arg("Rev"));
cls_GeomFill_DegeneratedBound.def("Bounds", [](GeomFill_DegeneratedBound &self, Standard_Real & First, Standard_Real & Last){ self.Bounds(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "None", py::arg("First"), py::arg("Last"));
cls_GeomFill_DegeneratedBound.def("IsDegenerated", (Standard_Boolean (GeomFill_DegeneratedBound::*)() const) &GeomFill_DegeneratedBound::IsDegenerated, "None");
cls_GeomFill_DegeneratedBound.def_static("get_type_name_", (const char * (*)()) &GeomFill_DegeneratedBound::get_type_name, "None");
cls_GeomFill_DegeneratedBound.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_DegeneratedBound::get_type_descriptor, "None");
cls_GeomFill_DegeneratedBound.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_DegeneratedBound::*)() const) &GeomFill_DegeneratedBound::DynamicType, "None");

// TYPEDEF: GEOMFILL_SEQUENCEOFAX2
bind_NCollection_Sequence<gp_Ax2>(mod, "GeomFill_SequenceOfAx2", py::module_local(false));

// CLASS: GEOMFILL_HSEQUENCEOFAX2
bind_Define_HSequence<GeomFill_HSequenceOfAx2, GeomFill_SequenceOfAx2>(mod, "GeomFill_HSequenceOfAx2");

// CLASS: GEOMFILL_DISCRETETRIHEDRON
py::class_<GeomFill_DiscreteTrihedron, opencascade::handle<GeomFill_DiscreteTrihedron>, GeomFill_TrihedronLaw> cls_GeomFill_DiscreteTrihedron(mod, "GeomFill_DiscreteTrihedron", "Defined Discrete Trihedron Law. The requirement for path curve is only G1. The result is C0-continuous surface that can be later approximated to C1.");

// Constructors
cls_GeomFill_DiscreteTrihedron.def(py::init<>());

// Methods
cls_GeomFill_DiscreteTrihedron.def("Copy", (opencascade::handle<GeomFill_TrihedronLaw> (GeomFill_DiscreteTrihedron::*)() const) &GeomFill_DiscreteTrihedron::Copy, "None");
cls_GeomFill_DiscreteTrihedron.def("Init", (void (GeomFill_DiscreteTrihedron::*)()) &GeomFill_DiscreteTrihedron::Init, "None");
cls_GeomFill_DiscreteTrihedron.def("SetCurve", (void (GeomFill_DiscreteTrihedron::*)(const opencascade::handle<Adaptor3d_HCurve> &)) &GeomFill_DiscreteTrihedron::SetCurve, "None", py::arg("C"));
cls_GeomFill_DiscreteTrihedron.def("D0", (Standard_Boolean (GeomFill_DiscreteTrihedron::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_DiscreteTrihedron::D0, "compute Trihedron on curve at parameter <Param>", py::arg("Param"), py::arg("Tangent"), py::arg("Normal"), py::arg("BiNormal"));
cls_GeomFill_DiscreteTrihedron.def("D1", (Standard_Boolean (GeomFill_DiscreteTrihedron::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_DiscreteTrihedron::D1, "compute Trihedron and derivative Trihedron on curve at parameter <Param> Warning : It used only for C1 or C2 aproximation For the moment it returns null values for DTangent, DNormal and DBiNormal.", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("BiNormal"), py::arg("DBiNormal"));
cls_GeomFill_DiscreteTrihedron.def("D2", (Standard_Boolean (GeomFill_DiscreteTrihedron::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_DiscreteTrihedron::D2, "compute Trihedron on curve first and seconde derivatives. Warning : It used only for C2 aproximation For the moment it returns null values for DTangent, DNormal DBiNormal, D2Tangent, D2Normal, D2BiNormal.", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("D2Tangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("D2Normal"), py::arg("BiNormal"), py::arg("DBiNormal"), py::arg("D2BiNormal"));
cls_GeomFill_DiscreteTrihedron.def("NbIntervals", (Standard_Integer (GeomFill_DiscreteTrihedron::*)(const GeomAbs_Shape) const) &GeomFill_DiscreteTrihedron::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_DiscreteTrihedron.def("Intervals", (void (GeomFill_DiscreteTrihedron::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_DiscreteTrihedron::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_DiscreteTrihedron.def("GetAverageLaw", (void (GeomFill_DiscreteTrihedron::*)(gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_DiscreteTrihedron::GetAverageLaw, "Get average value of Tangent(t) and Normal(t) it is usful to make fast approximation of rational surfaces.", py::arg("ATangent"), py::arg("ANormal"), py::arg("ABiNormal"));
cls_GeomFill_DiscreteTrihedron.def("IsConstant", (Standard_Boolean (GeomFill_DiscreteTrihedron::*)() const) &GeomFill_DiscreteTrihedron::IsConstant, "Say if the law is Constant.");
cls_GeomFill_DiscreteTrihedron.def("IsOnlyBy3dCurve", (Standard_Boolean (GeomFill_DiscreteTrihedron::*)() const) &GeomFill_DiscreteTrihedron::IsOnlyBy3dCurve, "Return True.");
cls_GeomFill_DiscreteTrihedron.def_static("get_type_name_", (const char * (*)()) &GeomFill_DiscreteTrihedron::get_type_name, "None");
cls_GeomFill_DiscreteTrihedron.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_DiscreteTrihedron::get_type_descriptor, "None");
cls_GeomFill_DiscreteTrihedron.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_DiscreteTrihedron::*)() const) &GeomFill_DiscreteTrihedron::DynamicType, "None");

// CLASS: GEOMFILL_DRAFTTRIHEDRON
py::class_<GeomFill_DraftTrihedron, opencascade::handle<GeomFill_DraftTrihedron>, GeomFill_TrihedronLaw> cls_GeomFill_DraftTrihedron(mod, "GeomFill_DraftTrihedron", "None");

// Constructors
cls_GeomFill_DraftTrihedron.def(py::init<const gp_Vec &, const Standard_Real>(), py::arg("BiNormal"), py::arg("Angle"));

// Methods
cls_GeomFill_DraftTrihedron.def("SetAngle", (void (GeomFill_DraftTrihedron::*)(const Standard_Real)) &GeomFill_DraftTrihedron::SetAngle, "None", py::arg("Angle"));
cls_GeomFill_DraftTrihedron.def("Copy", (opencascade::handle<GeomFill_TrihedronLaw> (GeomFill_DraftTrihedron::*)() const) &GeomFill_DraftTrihedron::Copy, "None");
cls_GeomFill_DraftTrihedron.def("D0", (Standard_Boolean (GeomFill_DraftTrihedron::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_DraftTrihedron::D0, "compute Triedrhon and derivative Trihedron on curve at parameter <Param> Warning : It used only for C1 or C2 aproximation", py::arg("Param"), py::arg("Tangent"), py::arg("Normal"), py::arg("BiNormal"));
cls_GeomFill_DraftTrihedron.def("D1", (Standard_Boolean (GeomFill_DraftTrihedron::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_DraftTrihedron::D1, "compute Trihedron on curve first and seconde derivatives. Warning : It used only for C2 aproximation", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("BiNormal"), py::arg("DBiNormal"));
cls_GeomFill_DraftTrihedron.def("D2", (Standard_Boolean (GeomFill_DraftTrihedron::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_DraftTrihedron::D2, "None", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("D2Tangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("D2Normal"), py::arg("BiNormal"), py::arg("DBiNormal"), py::arg("D2BiNormal"));
cls_GeomFill_DraftTrihedron.def("NbIntervals", (Standard_Integer (GeomFill_DraftTrihedron::*)(const GeomAbs_Shape) const) &GeomFill_DraftTrihedron::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_DraftTrihedron.def("Intervals", (void (GeomFill_DraftTrihedron::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_DraftTrihedron::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_DraftTrihedron.def("GetAverageLaw", (void (GeomFill_DraftTrihedron::*)(gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_DraftTrihedron::GetAverageLaw, "Get average value of Tangent(t) and Normal(t) it is usefull to make fast approximation of rational surfaces.", py::arg("ATangent"), py::arg("ANormal"), py::arg("ABiNormal"));
cls_GeomFill_DraftTrihedron.def("IsConstant", (Standard_Boolean (GeomFill_DraftTrihedron::*)() const) &GeomFill_DraftTrihedron::IsConstant, "Say if the law is Constant.");
cls_GeomFill_DraftTrihedron.def("IsOnlyBy3dCurve", (Standard_Boolean (GeomFill_DraftTrihedron::*)() const) &GeomFill_DraftTrihedron::IsOnlyBy3dCurve, "Return True.");
cls_GeomFill_DraftTrihedron.def_static("get_type_name_", (const char * (*)()) &GeomFill_DraftTrihedron::get_type_name, "None");
cls_GeomFill_DraftTrihedron.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_DraftTrihedron::get_type_descriptor, "None");
cls_GeomFill_DraftTrihedron.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_DraftTrihedron::*)() const) &GeomFill_DraftTrihedron::DynamicType, "None");

// CLASS: GEOMFILL_EVOLVEDSECTION
py::class_<GeomFill_EvolvedSection, opencascade::handle<GeomFill_EvolvedSection>, GeomFill_SectionLaw> cls_GeomFill_EvolvedSection(mod, "GeomFill_EvolvedSection", "Define an Constant Section Law");

// Constructors
cls_GeomFill_EvolvedSection.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Law_Function> &>(), py::arg("C"), py::arg("L"));

// Methods
cls_GeomFill_EvolvedSection.def("D0", (Standard_Boolean (GeomFill_EvolvedSection::*)(const Standard_Real, TColgp_Array1OfPnt &, TColStd_Array1OfReal &)) &GeomFill_EvolvedSection::D0, "compute the section for v = param", py::arg("Param"), py::arg("Poles"), py::arg("Weigths"));
cls_GeomFill_EvolvedSection.def("D1", (Standard_Boolean (GeomFill_EvolvedSection::*)(const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &GeomFill_EvolvedSection::D1, "compute the first derivative in v direction of the section for v = param Warning : It used only for C1 or C2 aproximation", py::arg("Param"), py::arg("Poles"), py::arg("DPoles"), py::arg("Weigths"), py::arg("DWeigths"));
cls_GeomFill_EvolvedSection.def("D2", (Standard_Boolean (GeomFill_EvolvedSection::*)(const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &GeomFill_EvolvedSection::D2, "compute the second derivative in v direction of the section for v = param Warning : It used only for C2 aproximation", py::arg("Param"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
cls_GeomFill_EvolvedSection.def("BSplineSurface", (opencascade::handle<Geom_BSplineSurface> (GeomFill_EvolvedSection::*)() const) &GeomFill_EvolvedSection::BSplineSurface, "give if possible an bspline Surface, like iso-v are the section. If it is not possible this methode have to get an Null Surface. Is it the default implementation.");
cls_GeomFill_EvolvedSection.def("SectionShape", [](GeomFill_EvolvedSection &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree){ self.SectionShape(NbPoles, NbKnots, Degree); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree); }, "get the format of an section", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"));
cls_GeomFill_EvolvedSection.def("Knots", (void (GeomFill_EvolvedSection::*)(TColStd_Array1OfReal &) const) &GeomFill_EvolvedSection::Knots, "get the Knots of the section", py::arg("TKnots"));
cls_GeomFill_EvolvedSection.def("Mults", (void (GeomFill_EvolvedSection::*)(TColStd_Array1OfInteger &) const) &GeomFill_EvolvedSection::Mults, "get the Multplicities of the section", py::arg("TMults"));
cls_GeomFill_EvolvedSection.def("IsRational", (Standard_Boolean (GeomFill_EvolvedSection::*)() const) &GeomFill_EvolvedSection::IsRational, "Returns if the sections are rationnal or not");
cls_GeomFill_EvolvedSection.def("IsUPeriodic", (Standard_Boolean (GeomFill_EvolvedSection::*)() const) &GeomFill_EvolvedSection::IsUPeriodic, "Returns if the sections are periodic or not");
cls_GeomFill_EvolvedSection.def("IsVPeriodic", (Standard_Boolean (GeomFill_EvolvedSection::*)() const) &GeomFill_EvolvedSection::IsVPeriodic, "Returns if the law isperiodic or not");
cls_GeomFill_EvolvedSection.def("NbIntervals", (Standard_Integer (GeomFill_EvolvedSection::*)(const GeomAbs_Shape) const) &GeomFill_EvolvedSection::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_EvolvedSection.def("Intervals", (void (GeomFill_EvolvedSection::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_EvolvedSection::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_EvolvedSection.def("SetInterval", (void (GeomFill_EvolvedSection::*)(const Standard_Real, const Standard_Real)) &GeomFill_EvolvedSection::SetInterval, "Sets the bounds of the parametric interval on the function This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_GeomFill_EvolvedSection.def("GetInterval", [](GeomFill_EvolvedSection &self, Standard_Real & First, Standard_Real & Last){ self.GetInterval(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "Gets the bounds of the parametric interval on the function", py::arg("First"), py::arg("Last"));
cls_GeomFill_EvolvedSection.def("GetDomain", [](GeomFill_EvolvedSection &self, Standard_Real & First, Standard_Real & Last){ self.GetDomain(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "Gets the bounds of the function parametric domain. Warning: This domain it is not modified by the SetValue method", py::arg("First"), py::arg("Last"));
cls_GeomFill_EvolvedSection.def("GetTolerance", (void (GeomFill_EvolvedSection::*)(const Standard_Real, const Standard_Real, const Standard_Real, TColStd_Array1OfReal &) const) &GeomFill_EvolvedSection::GetTolerance, "Returns the tolerances associated at each poles to reach in approximation, to satisfy: BoundTol error at the Boundary AngleTol tangent error at the Boundary (in radian) SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"));
cls_GeomFill_EvolvedSection.def("BarycentreOfSurf", (gp_Pnt (GeomFill_EvolvedSection::*)() const) &GeomFill_EvolvedSection::BarycentreOfSurf, "Get the barycentre of Surface. An very poor estimation is sufficent. This information is usefull to perform well conditioned rational approximation. Warning: Used only if <me> IsRational");
cls_GeomFill_EvolvedSection.def("MaximalSection", (Standard_Real (GeomFill_EvolvedSection::*)() const) &GeomFill_EvolvedSection::MaximalSection, "Returns the length of the greater section. This information is usefull to G1's control. Warning: With an little value, approximation can be slower.");
cls_GeomFill_EvolvedSection.def("GetMinimalWeight", (void (GeomFill_EvolvedSection::*)(TColStd_Array1OfReal &) const) &GeomFill_EvolvedSection::GetMinimalWeight, "Compute the minimal value of weight for each poles in all sections. This information is usefull to control error in rational approximation. Warning: Used only if <me> IsRational", py::arg("Weigths"));
cls_GeomFill_EvolvedSection.def("IsConstant", [](GeomFill_EvolvedSection &self, Standard_Real & Error){ Standard_Boolean rv = self.IsConstant(Error); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Error); }, "return True If the Law isConstant", py::arg("Error"));
cls_GeomFill_EvolvedSection.def("ConstantSection", (opencascade::handle<Geom_Curve> (GeomFill_EvolvedSection::*)() const) &GeomFill_EvolvedSection::ConstantSection, "Return the constant Section if <me> IsConstant.");
cls_GeomFill_EvolvedSection.def_static("get_type_name_", (const char * (*)()) &GeomFill_EvolvedSection::get_type_name, "None");
cls_GeomFill_EvolvedSection.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_EvolvedSection::get_type_descriptor, "None");
cls_GeomFill_EvolvedSection.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_EvolvedSection::*)() const) &GeomFill_EvolvedSection::DynamicType, "None");

// CLASS: GEOMFILL_FIXED
py::class_<GeomFill_Fixed, opencascade::handle<GeomFill_Fixed>, GeomFill_TrihedronLaw> cls_GeomFill_Fixed(mod, "GeomFill_Fixed", "Defined an constant TrihedronLaw");

// Constructors
cls_GeomFill_Fixed.def(py::init<const gp_Vec &, const gp_Vec &>(), py::arg("Tangent"), py::arg("Normal"));

// Methods
cls_GeomFill_Fixed.def("Copy", (opencascade::handle<GeomFill_TrihedronLaw> (GeomFill_Fixed::*)() const) &GeomFill_Fixed::Copy, "None");
cls_GeomFill_Fixed.def("D0", (Standard_Boolean (GeomFill_Fixed::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_Fixed::D0, "compute Triedrhon on curve at parameter <Param>", py::arg("Param"), py::arg("Tangent"), py::arg("Normal"), py::arg("BiNormal"));
cls_GeomFill_Fixed.def("D1", (Standard_Boolean (GeomFill_Fixed::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_Fixed::D1, "compute Triedrhon and derivative Trihedron on curve at parameter <Param> Warning : It used only for C1 or C2 aproximation", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("BiNormal"), py::arg("DBiNormal"));
cls_GeomFill_Fixed.def("D2", (Standard_Boolean (GeomFill_Fixed::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_Fixed::D2, "compute Trihedron on curve first and seconde derivatives. Warning : It used only for C2 aproximation", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("D2Tangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("D2Normal"), py::arg("BiNormal"), py::arg("DBiNormal"), py::arg("D2BiNormal"));
cls_GeomFill_Fixed.def("NbIntervals", (Standard_Integer (GeomFill_Fixed::*)(const GeomAbs_Shape) const) &GeomFill_Fixed::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_Fixed.def("Intervals", (void (GeomFill_Fixed::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_Fixed::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_Fixed.def("GetAverageLaw", (void (GeomFill_Fixed::*)(gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_Fixed::GetAverageLaw, "Get average value of Tangent(t) and Normal(t) it is usfull to make fast approximation of rational surfaces.", py::arg("ATangent"), py::arg("ANormal"), py::arg("ABiNormal"));
cls_GeomFill_Fixed.def("IsConstant", (Standard_Boolean (GeomFill_Fixed::*)() const) &GeomFill_Fixed::IsConstant, "Return True.");
cls_GeomFill_Fixed.def_static("get_type_name_", (const char * (*)()) &GeomFill_Fixed::get_type_name, "None");
cls_GeomFill_Fixed.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_Fixed::get_type_descriptor, "None");
cls_GeomFill_Fixed.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_Fixed::*)() const) &GeomFill_Fixed::DynamicType, "None");

// CLASS: GEOMFILL_FRENET
py::class_<GeomFill_Frenet, opencascade::handle<GeomFill_Frenet>, GeomFill_TrihedronLaw> cls_GeomFill_Frenet(mod, "GeomFill_Frenet", "Defined Frenet Trihedron Law");

// Constructors
cls_GeomFill_Frenet.def(py::init<>());

// Methods
cls_GeomFill_Frenet.def("Copy", (opencascade::handle<GeomFill_TrihedronLaw> (GeomFill_Frenet::*)() const) &GeomFill_Frenet::Copy, "None");
cls_GeomFill_Frenet.def("Init", (void (GeomFill_Frenet::*)()) &GeomFill_Frenet::Init, "None");
cls_GeomFill_Frenet.def("SetCurve", (void (GeomFill_Frenet::*)(const opencascade::handle<Adaptor3d_HCurve> &)) &GeomFill_Frenet::SetCurve, "None", py::arg("C"));
cls_GeomFill_Frenet.def("D0", (Standard_Boolean (GeomFill_Frenet::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_Frenet::D0, "compute Triedrhon on curve at parameter <Param>", py::arg("Param"), py::arg("Tangent"), py::arg("Normal"), py::arg("BiNormal"));
cls_GeomFill_Frenet.def("D1", (Standard_Boolean (GeomFill_Frenet::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_Frenet::D1, "compute Triedrhon and derivative Trihedron on curve at parameter <Param> Warning : It used only for C1 or C2 aproximation", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("BiNormal"), py::arg("DBiNormal"));
cls_GeomFill_Frenet.def("D2", (Standard_Boolean (GeomFill_Frenet::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_Frenet::D2, "compute Trihedron on curve first and seconde derivatives. Warning : It used only for C2 aproximation", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("D2Tangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("D2Normal"), py::arg("BiNormal"), py::arg("DBiNormal"), py::arg("D2BiNormal"));
cls_GeomFill_Frenet.def("NbIntervals", (Standard_Integer (GeomFill_Frenet::*)(const GeomAbs_Shape) const) &GeomFill_Frenet::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_Frenet.def("Intervals", (void (GeomFill_Frenet::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_Frenet::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_Frenet.def("GetAverageLaw", (void (GeomFill_Frenet::*)(gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_Frenet::GetAverageLaw, "Get average value of Tangent(t) and Normal(t) it is usfull to make fast approximation of rational surfaces.", py::arg("ATangent"), py::arg("ANormal"), py::arg("ABiNormal"));
cls_GeomFill_Frenet.def("IsConstant", (Standard_Boolean (GeomFill_Frenet::*)() const) &GeomFill_Frenet::IsConstant, "Say if the law is Constant.");
cls_GeomFill_Frenet.def("IsOnlyBy3dCurve", (Standard_Boolean (GeomFill_Frenet::*)() const) &GeomFill_Frenet::IsOnlyBy3dCurve, "Return True.");
cls_GeomFill_Frenet.def_static("get_type_name_", (const char * (*)()) &GeomFill_Frenet::get_type_name, "None");
cls_GeomFill_Frenet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_Frenet::get_type_descriptor, "None");
cls_GeomFill_Frenet.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_Frenet::*)() const) &GeomFill_Frenet::DynamicType, "None");

// CLASS: GEOMFILL_FUNCTIONDRAFT
py::class_<GeomFill_FunctionDraft, math_FunctionSetWithDerivatives> cls_GeomFill_FunctionDraft(mod, "GeomFill_FunctionDraft", "None");

// Constructors
cls_GeomFill_FunctionDraft.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S"), py::arg("C"));

// Methods
// cls_GeomFill_FunctionDraft.def_static("operator new_", (void * (*)(size_t)) &GeomFill_FunctionDraft::operator new, "None", py::arg("theSize"));
// cls_GeomFill_FunctionDraft.def_static("operator delete_", (void (*)(void *)) &GeomFill_FunctionDraft::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_FunctionDraft.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_FunctionDraft::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_FunctionDraft.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_FunctionDraft::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_FunctionDraft.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_FunctionDraft::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_FunctionDraft.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_FunctionDraft::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_FunctionDraft.def("NbVariables", (Standard_Integer (GeomFill_FunctionDraft::*)() const) &GeomFill_FunctionDraft::NbVariables, "returns the number of variables of the function.");
cls_GeomFill_FunctionDraft.def("NbEquations", (Standard_Integer (GeomFill_FunctionDraft::*)() const) &GeomFill_FunctionDraft::NbEquations, "returns the number of equations of the function.");
cls_GeomFill_FunctionDraft.def("Value", (Standard_Boolean (GeomFill_FunctionDraft::*)(const math_Vector &, math_Vector &)) &GeomFill_FunctionDraft::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_GeomFill_FunctionDraft.def("Derivatives", (Standard_Boolean (GeomFill_FunctionDraft::*)(const math_Vector &, math_Matrix &)) &GeomFill_FunctionDraft::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_GeomFill_FunctionDraft.def("Values", (Standard_Boolean (GeomFill_FunctionDraft::*)(const math_Vector &, math_Vector &, math_Matrix &)) &GeomFill_FunctionDraft::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_GeomFill_FunctionDraft.def("DerivT", (Standard_Boolean (GeomFill_FunctionDraft::*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Real, const gp_Vec &, const Standard_Real, math_Vector &)) &GeomFill_FunctionDraft::DerivT, "returns the values <F> of the T derivatives for the parameter Param .", py::arg("C"), py::arg("Param"), py::arg("W"), py::arg("dN"), py::arg("teta"), py::arg("F"));
cls_GeomFill_FunctionDraft.def("Deriv2T", (Standard_Boolean (GeomFill_FunctionDraft::*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real, const Standard_Real, const gp_Vec &, const Standard_Real, math_Vector &)) &GeomFill_FunctionDraft::Deriv2T, "returns the values <F> of the T2 derivatives for the parameter Param .", py::arg("C"), py::arg("Param"), py::arg("W"), py::arg("d2N"), py::arg("teta"), py::arg("F"));
cls_GeomFill_FunctionDraft.def("DerivTX", (Standard_Boolean (GeomFill_FunctionDraft::*)(const gp_Vec &, const Standard_Real, math_Matrix &)) &GeomFill_FunctionDraft::DerivTX, "returns the values <D> of the TX derivatives for the parameter Param .", py::arg("dN"), py::arg("teta"), py::arg("D"));
cls_GeomFill_FunctionDraft.def("Deriv2X", (Standard_Boolean (GeomFill_FunctionDraft::*)(const math_Vector &, GeomFill_Tensor &)) &GeomFill_FunctionDraft::Deriv2X, "returns the values <T> of the X2 derivatives for the parameter Param .", py::arg("X"), py::arg("T"));

// CLASS: GEOMFILL_FUNCTIONGUIDE
py::class_<GeomFill_FunctionGuide, math_FunctionSetWithDerivatives> cls_GeomFill_FunctionGuide(mod, "GeomFill_FunctionGuide", "None");

// Constructors
cls_GeomFill_FunctionGuide.def(py::init<const opencascade::handle<GeomFill_SectionLaw> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S"), py::arg("Guide"));
cls_GeomFill_FunctionGuide.def(py::init<const opencascade::handle<GeomFill_SectionLaw> &, const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real>(), py::arg("S"), py::arg("Guide"), py::arg("ParamOnLaw"));

// Methods
// cls_GeomFill_FunctionGuide.def_static("operator new_", (void * (*)(size_t)) &GeomFill_FunctionGuide::operator new, "None", py::arg("theSize"));
// cls_GeomFill_FunctionGuide.def_static("operator delete_", (void (*)(void *)) &GeomFill_FunctionGuide::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_FunctionGuide.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_FunctionGuide::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_FunctionGuide.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_FunctionGuide::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_FunctionGuide.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_FunctionGuide::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_FunctionGuide.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_FunctionGuide::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_FunctionGuide.def("SetParam", (void (GeomFill_FunctionGuide::*)(const Standard_Real, const gp_Pnt &, const gp_XYZ &, const gp_XYZ &)) &GeomFill_FunctionGuide::SetParam, "None", py::arg("Param"), py::arg("Centre"), py::arg("Dir"), py::arg("XDir"));
cls_GeomFill_FunctionGuide.def("NbVariables", (Standard_Integer (GeomFill_FunctionGuide::*)() const) &GeomFill_FunctionGuide::NbVariables, "returns the number of variables of the function.");
cls_GeomFill_FunctionGuide.def("NbEquations", (Standard_Integer (GeomFill_FunctionGuide::*)() const) &GeomFill_FunctionGuide::NbEquations, "returns the number of equations of the function.");
cls_GeomFill_FunctionGuide.def("Value", (Standard_Boolean (GeomFill_FunctionGuide::*)(const math_Vector &, math_Vector &)) &GeomFill_FunctionGuide::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
cls_GeomFill_FunctionGuide.def("Derivatives", (Standard_Boolean (GeomFill_FunctionGuide::*)(const math_Vector &, math_Matrix &)) &GeomFill_FunctionGuide::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
cls_GeomFill_FunctionGuide.def("Values", (Standard_Boolean (GeomFill_FunctionGuide::*)(const math_Vector &, math_Vector &, math_Matrix &)) &GeomFill_FunctionGuide::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_GeomFill_FunctionGuide.def("DerivT", (Standard_Boolean (GeomFill_FunctionGuide::*)(const math_Vector &, const gp_XYZ &, const gp_XYZ &, math_Vector &)) &GeomFill_FunctionGuide::DerivT, "returns the values <F> of the T derivatives for the parameter Param .", py::arg("X"), py::arg("DCentre"), py::arg("DDir"), py::arg("DFDT"));
// cls_GeomFill_FunctionGuide.def("Deriv2T", (Standard_Boolean (GeomFill_FunctionGuide::*)(const gp_XYZ &, const gp_XYZ &, math_Vector &, math_Vector &)) &GeomFill_FunctionGuide::Deriv2T, "returns the values <F> of the T2 derivatives for the parameter Param . returns the values <D> of the TX derivatives for the parameter Param . returns Boolean is static; returns the values <T> of the X2 derivatives for the parameter Param . returns Boolean is static;", py::arg("DCentre"), py::arg("DDir"), py::arg("DFDT"), py::arg("D2FT"));

// CLASS: GEOMFILL_PROFILER
py::class_<GeomFill_Profiler> cls_GeomFill_Profiler(mod, "GeomFill_Profiler", "Evaluation of the common BSplineProfile of a group of curves from Geom. All the curves will have the same degree, the same knot-vector, so the same number of poles.");

// Constructors
cls_GeomFill_Profiler.def(py::init<>());

// Methods
// cls_GeomFill_Profiler.def_static("operator new_", (void * (*)(size_t)) &GeomFill_Profiler::operator new, "None", py::arg("theSize"));
// cls_GeomFill_Profiler.def_static("operator delete_", (void (*)(void *)) &GeomFill_Profiler::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_Profiler.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_Profiler::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_Profiler.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_Profiler::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_Profiler.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_Profiler::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_Profiler.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_Profiler::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_Profiler.def("AddCurve", (void (GeomFill_Profiler::*)(const opencascade::handle<Geom_Curve> &)) &GeomFill_Profiler::AddCurve, "None", py::arg("Curve"));
cls_GeomFill_Profiler.def("Perform", (void (GeomFill_Profiler::*)(const Standard_Real)) &GeomFill_Profiler::Perform, "Converts all curves to BSplineCurves. Set them to the common profile. <PTol> is used to compare 2 knots.", py::arg("PTol"));
cls_GeomFill_Profiler.def("Degree", (Standard_Integer (GeomFill_Profiler::*)() const) &GeomFill_Profiler::Degree, "Raises if not yet perform");
cls_GeomFill_Profiler.def("IsPeriodic", (Standard_Boolean (GeomFill_Profiler::*)() const) &GeomFill_Profiler::IsPeriodic, "None");
cls_GeomFill_Profiler.def("NbPoles", (Standard_Integer (GeomFill_Profiler::*)() const) &GeomFill_Profiler::NbPoles, "Raises if not yet perform");
cls_GeomFill_Profiler.def("Poles", (void (GeomFill_Profiler::*)(const Standard_Integer, TColgp_Array1OfPnt &) const) &GeomFill_Profiler::Poles, "returns in <Poles> the poles of the BSplineCurve from index <Index> adjusting to the current profile. Raises if not yet perform Raises if <Index> not in the range [1,NbCurves] if the length of <Poles> is not equal to NbPoles().", py::arg("Index"), py::arg("Poles"));
cls_GeomFill_Profiler.def("Weights", (void (GeomFill_Profiler::*)(const Standard_Integer, TColStd_Array1OfReal &) const) &GeomFill_Profiler::Weights, "returns in <Weights> the weights of the BSplineCurve from index <Index> adjusting to the current profile. Raises if not yet perform Raises if <Index> not in the range [1,NbCurves] or if the length of <Weights> is not equal to NbPoles().", py::arg("Index"), py::arg("Weights"));
cls_GeomFill_Profiler.def("NbKnots", (Standard_Integer (GeomFill_Profiler::*)() const) &GeomFill_Profiler::NbKnots, "Raises if not yet perform");
cls_GeomFill_Profiler.def("KnotsAndMults", (void (GeomFill_Profiler::*)(TColStd_Array1OfReal &, TColStd_Array1OfInteger &) const) &GeomFill_Profiler::KnotsAndMults, "Raises if not yet perform Raises if the lengthes of <Knots> and <Mults> are not equal to NbKnots().", py::arg("Knots"), py::arg("Mults"));
cls_GeomFill_Profiler.def("Curve", (const opencascade::handle<Geom_Curve> & (GeomFill_Profiler::*)(const Standard_Integer) const) &GeomFill_Profiler::Curve, "None", py::arg("Index"));

// CLASS: GEOMFILL_GENERATOR
py::class_<GeomFill_Generator, GeomFill_Profiler> cls_GeomFill_Generator(mod, "GeomFill_Generator", "Create a surface using generating lines. Inherits profiler. The surface will be a BSplineSurface passing by all the curves described in the generator. The VDegree of the resulting surface is 1.");

// Constructors
cls_GeomFill_Generator.def(py::init<>());

// Methods
// cls_GeomFill_Generator.def_static("operator new_", (void * (*)(size_t)) &GeomFill_Generator::operator new, "None", py::arg("theSize"));
// cls_GeomFill_Generator.def_static("operator delete_", (void (*)(void *)) &GeomFill_Generator::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_Generator.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_Generator::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_Generator.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_Generator::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_Generator.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_Generator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_Generator.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_Generator::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_Generator.def("Perform", (void (GeomFill_Generator::*)(const Standard_Real)) &GeomFill_Generator::Perform, "Converts all curves to BSplineCurves. Set them to the common profile. Compute the surface (degv = 1). <PTol> is used to compare 2 knots.", py::arg("PTol"));
cls_GeomFill_Generator.def("Surface", (const opencascade::handle<Geom_Surface> & (GeomFill_Generator::*)() const) &GeomFill_Generator::Surface, "None");

// CLASS: GEOMFILL_TRIHEDRONWITHGUIDE
py::class_<GeomFill_TrihedronWithGuide, opencascade::handle<GeomFill_TrihedronWithGuide>, GeomFill_TrihedronLaw> cls_GeomFill_TrihedronWithGuide(mod, "GeomFill_TrihedronWithGuide", "To define Trihedron along one Curve with a guide");

// Methods
cls_GeomFill_TrihedronWithGuide.def("Guide", (opencascade::handle<Adaptor3d_HCurve> (GeomFill_TrihedronWithGuide::*)() const) &GeomFill_TrihedronWithGuide::Guide, "None");
cls_GeomFill_TrihedronWithGuide.def("Origine", (void (GeomFill_TrihedronWithGuide::*)(const Standard_Real, const Standard_Real)) &GeomFill_TrihedronWithGuide::Origine, "None", py::arg("Param1"), py::arg("Param2"));
cls_GeomFill_TrihedronWithGuide.def("CurrentPointOnGuide", (gp_Pnt (GeomFill_TrihedronWithGuide::*)() const) &GeomFill_TrihedronWithGuide::CurrentPointOnGuide, "Returns the current point on guide found by D0, D1 or D2.");
cls_GeomFill_TrihedronWithGuide.def_static("get_type_name_", (const char * (*)()) &GeomFill_TrihedronWithGuide::get_type_name, "None");
cls_GeomFill_TrihedronWithGuide.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_TrihedronWithGuide::get_type_descriptor, "None");
cls_GeomFill_TrihedronWithGuide.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_TrihedronWithGuide::*)() const) &GeomFill_TrihedronWithGuide::DynamicType, "None");

// CLASS: GEOMFILL_GUIDETRIHEDRONAC
py::class_<GeomFill_GuideTrihedronAC, opencascade::handle<GeomFill_GuideTrihedronAC>, GeomFill_TrihedronWithGuide> cls_GeomFill_GuideTrihedronAC(mod, "GeomFill_GuideTrihedronAC", "Trihedron in the case of a sweeping along a guide curve. defined by curviline absciss");

// Constructors
cls_GeomFill_GuideTrihedronAC.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("guide"));

// Methods
cls_GeomFill_GuideTrihedronAC.def("SetCurve", (void (GeomFill_GuideTrihedronAC::*)(const opencascade::handle<Adaptor3d_HCurve> &)) &GeomFill_GuideTrihedronAC::SetCurve, "None", py::arg("C"));
cls_GeomFill_GuideTrihedronAC.def("Copy", (opencascade::handle<GeomFill_TrihedronLaw> (GeomFill_GuideTrihedronAC::*)() const) &GeomFill_GuideTrihedronAC::Copy, "None");
cls_GeomFill_GuideTrihedronAC.def("Guide", (opencascade::handle<Adaptor3d_HCurve> (GeomFill_GuideTrihedronAC::*)() const) &GeomFill_GuideTrihedronAC::Guide, "None");
cls_GeomFill_GuideTrihedronAC.def("D0", (Standard_Boolean (GeomFill_GuideTrihedronAC::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_GuideTrihedronAC::D0, "None", py::arg("Param"), py::arg("Tangent"), py::arg("Normal"), py::arg("BiNormal"));
cls_GeomFill_GuideTrihedronAC.def("D1", (Standard_Boolean (GeomFill_GuideTrihedronAC::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_GuideTrihedronAC::D1, "None", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("BiNormal"), py::arg("DBiNormal"));
cls_GeomFill_GuideTrihedronAC.def("D2", (Standard_Boolean (GeomFill_GuideTrihedronAC::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_GuideTrihedronAC::D2, "None", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("D2Tangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("D2Normal"), py::arg("BiNormal"), py::arg("DBiNormal"), py::arg("D2BiNormal"));
cls_GeomFill_GuideTrihedronAC.def("NbIntervals", (Standard_Integer (GeomFill_GuideTrihedronAC::*)(const GeomAbs_Shape) const) &GeomFill_GuideTrihedronAC::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_GuideTrihedronAC.def("Intervals", (void (GeomFill_GuideTrihedronAC::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_GuideTrihedronAC::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_GuideTrihedronAC.def("SetInterval", (void (GeomFill_GuideTrihedronAC::*)(const Standard_Real, const Standard_Real)) &GeomFill_GuideTrihedronAC::SetInterval, "Sets the bounds of the parametric interval on the function This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_GeomFill_GuideTrihedronAC.def("GetAverageLaw", (void (GeomFill_GuideTrihedronAC::*)(gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_GuideTrihedronAC::GetAverageLaw, "Get average value of M(t) and V(t) it is usfull to make fast approximation of rational surfaces.", py::arg("ATangent"), py::arg("ANormal"), py::arg("ABiNormal"));
cls_GeomFill_GuideTrihedronAC.def("IsConstant", (Standard_Boolean (GeomFill_GuideTrihedronAC::*)() const) &GeomFill_GuideTrihedronAC::IsConstant, "Say if the law is Constant");
cls_GeomFill_GuideTrihedronAC.def("IsOnlyBy3dCurve", (Standard_Boolean (GeomFill_GuideTrihedronAC::*)() const) &GeomFill_GuideTrihedronAC::IsOnlyBy3dCurve, "Say if the law is defined, only by the 3d Geometry of the setted Curve Return False by Default.");
cls_GeomFill_GuideTrihedronAC.def("Origine", (void (GeomFill_GuideTrihedronAC::*)(const Standard_Real, const Standard_Real)) &GeomFill_GuideTrihedronAC::Origine, "None", py::arg("OrACR1"), py::arg("OrACR2"));
cls_GeomFill_GuideTrihedronAC.def_static("get_type_name_", (const char * (*)()) &GeomFill_GuideTrihedronAC::get_type_name, "None");
cls_GeomFill_GuideTrihedronAC.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_GuideTrihedronAC::get_type_descriptor, "None");
cls_GeomFill_GuideTrihedronAC.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_GuideTrihedronAC::*)() const) &GeomFill_GuideTrihedronAC::DynamicType, "None");

// CLASS: GEOMFILL_GUIDETRIHEDRONPLAN
py::class_<GeomFill_GuideTrihedronPlan, opencascade::handle<GeomFill_GuideTrihedronPlan>, GeomFill_TrihedronWithGuide> cls_GeomFill_GuideTrihedronPlan(mod, "GeomFill_GuideTrihedronPlan", "Trihedron in the case of sweeping along a guide curve defined by the orthogonal plan on the trajectory");

// Constructors
cls_GeomFill_GuideTrihedronPlan.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("theGuide"));

// Methods
cls_GeomFill_GuideTrihedronPlan.def("SetCurve", (void (GeomFill_GuideTrihedronPlan::*)(const opencascade::handle<Adaptor3d_HCurve> &)) &GeomFill_GuideTrihedronPlan::SetCurve, "None", py::arg("thePath"));
cls_GeomFill_GuideTrihedronPlan.def("Copy", (opencascade::handle<GeomFill_TrihedronLaw> (GeomFill_GuideTrihedronPlan::*)() const) &GeomFill_GuideTrihedronPlan::Copy, "None");
cls_GeomFill_GuideTrihedronPlan.def("ErrorStatus", (GeomFill_PipeError (GeomFill_GuideTrihedronPlan::*)() const) &GeomFill_GuideTrihedronPlan::ErrorStatus, "Give a status to the Law Returns PipeOk (default implementation)");
cls_GeomFill_GuideTrihedronPlan.def("Guide", (opencascade::handle<Adaptor3d_HCurve> (GeomFill_GuideTrihedronPlan::*)() const) &GeomFill_GuideTrihedronPlan::Guide, "None");
cls_GeomFill_GuideTrihedronPlan.def("D0", (Standard_Boolean (GeomFill_GuideTrihedronPlan::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_GuideTrihedronPlan::D0, "None", py::arg("Param"), py::arg("Tangent"), py::arg("Normal"), py::arg("BiNormal"));
cls_GeomFill_GuideTrihedronPlan.def("D1", (Standard_Boolean (GeomFill_GuideTrihedronPlan::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_GuideTrihedronPlan::D1, "None", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("BiNormal"), py::arg("DBiNormal"));
cls_GeomFill_GuideTrihedronPlan.def("D2", (Standard_Boolean (GeomFill_GuideTrihedronPlan::*)(const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_GuideTrihedronPlan::D2, "None", py::arg("Param"), py::arg("Tangent"), py::arg("DTangent"), py::arg("D2Tangent"), py::arg("Normal"), py::arg("DNormal"), py::arg("D2Normal"), py::arg("BiNormal"), py::arg("DBiNormal"), py::arg("D2BiNormal"));
cls_GeomFill_GuideTrihedronPlan.def("SetInterval", (void (GeomFill_GuideTrihedronPlan::*)(const Standard_Real, const Standard_Real)) &GeomFill_GuideTrihedronPlan::SetInterval, "Sets the bounds of the parametric interval on the function This determines the derivatives in these values if the function is not Cn.", py::arg("First"), py::arg("Last"));
cls_GeomFill_GuideTrihedronPlan.def("NbIntervals", (Standard_Integer (GeomFill_GuideTrihedronPlan::*)(const GeomAbs_Shape) const) &GeomFill_GuideTrihedronPlan::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_GuideTrihedronPlan.def("Intervals", (void (GeomFill_GuideTrihedronPlan::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_GuideTrihedronPlan::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_GuideTrihedronPlan.def("GetAverageLaw", (void (GeomFill_GuideTrihedronPlan::*)(gp_Vec &, gp_Vec &, gp_Vec &)) &GeomFill_GuideTrihedronPlan::GetAverageLaw, "Get average value of M(t) and V(t) it is usfull to make fast approximation of rational surfaces.", py::arg("ATangent"), py::arg("ANormal"), py::arg("ABiNormal"));
cls_GeomFill_GuideTrihedronPlan.def("IsConstant", (Standard_Boolean (GeomFill_GuideTrihedronPlan::*)() const) &GeomFill_GuideTrihedronPlan::IsConstant, "Say if the law is Constant");
cls_GeomFill_GuideTrihedronPlan.def("IsOnlyBy3dCurve", (Standard_Boolean (GeomFill_GuideTrihedronPlan::*)() const) &GeomFill_GuideTrihedronPlan::IsOnlyBy3dCurve, "Say if the law is defined, only by the 3d Geometry of the setted Curve Return False by Default.");
cls_GeomFill_GuideTrihedronPlan.def("Origine", (void (GeomFill_GuideTrihedronPlan::*)(const Standard_Real, const Standard_Real)) &GeomFill_GuideTrihedronPlan::Origine, "None", py::arg("OrACR1"), py::arg("OrACR2"));
cls_GeomFill_GuideTrihedronPlan.def_static("get_type_name_", (const char * (*)()) &GeomFill_GuideTrihedronPlan::get_type_name, "None");
cls_GeomFill_GuideTrihedronPlan.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_GuideTrihedronPlan::get_type_descriptor, "None");
cls_GeomFill_GuideTrihedronPlan.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_GuideTrihedronPlan::*)() const) &GeomFill_GuideTrihedronPlan::DynamicType, "None");

// CLASS: GEOMFILL_LINE
py::class_<GeomFill_Line, opencascade::handle<GeomFill_Line>, Standard_Transient> cls_GeomFill_Line(mod, "GeomFill_Line", "class for instantiation of AppBlend");

// Constructors
cls_GeomFill_Line.def(py::init<>());
cls_GeomFill_Line.def(py::init<const Standard_Integer>(), py::arg("NbPoints"));

// Methods
cls_GeomFill_Line.def("NbPoints", (Standard_Integer (GeomFill_Line::*)() const) &GeomFill_Line::NbPoints, "None");
cls_GeomFill_Line.def("Point", (Standard_Integer (GeomFill_Line::*)(const Standard_Integer) const) &GeomFill_Line::Point, "None", py::arg("Index"));
cls_GeomFill_Line.def_static("get_type_name_", (const char * (*)()) &GeomFill_Line::get_type_name, "None");
cls_GeomFill_Line.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_Line::get_type_descriptor, "None");
cls_GeomFill_Line.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_Line::*)() const) &GeomFill_Line::DynamicType, "None");

// CLASS: GEOMFILL_LOCATIONDRAFT
py::class_<GeomFill_LocationDraft, opencascade::handle<GeomFill_LocationDraft>, GeomFill_LocationLaw> cls_GeomFill_LocationDraft(mod, "GeomFill_LocationDraft", "None");

// Constructors
cls_GeomFill_LocationDraft.def(py::init<const gp_Dir &, const Standard_Real>(), py::arg("Direction"), py::arg("Angle"));

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

// CLASS: GEOMFILL_LOCATIONGUIDE
py::class_<GeomFill_LocationGuide, opencascade::handle<GeomFill_LocationGuide>, GeomFill_LocationLaw> cls_GeomFill_LocationGuide(mod, "GeomFill_LocationGuide", "None");

// Constructors
cls_GeomFill_LocationGuide.def(py::init<const opencascade::handle<GeomFill_TrihedronWithGuide> &>(), py::arg("Triedre"));

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

// CLASS: GEOMFILL_LOCFUNCTION
py::class_<GeomFill_LocFunction> cls_GeomFill_LocFunction(mod, "GeomFill_LocFunction", "None");

// Constructors
cls_GeomFill_LocFunction.def(py::init<const opencascade::handle<GeomFill_LocationLaw> &>(), py::arg("Law"));

// Methods
// cls_GeomFill_LocFunction.def_static("operator new_", (void * (*)(size_t)) &GeomFill_LocFunction::operator new, "None", py::arg("theSize"));
// cls_GeomFill_LocFunction.def_static("operator delete_", (void (*)(void *)) &GeomFill_LocFunction::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_LocFunction.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_LocFunction::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_LocFunction.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_LocFunction::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_LocFunction.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_LocFunction::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_LocFunction.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_LocFunction::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_LocFunction.def("D0", (Standard_Boolean (GeomFill_LocFunction::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &GeomFill_LocFunction::D0, "compute the section for v = param", py::arg("Param"), py::arg("First"), py::arg("Last"));
cls_GeomFill_LocFunction.def("D1", (Standard_Boolean (GeomFill_LocFunction::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &GeomFill_LocFunction::D1, "compute the first derivative in v direction of the section for v = param", py::arg("Param"), py::arg("First"), py::arg("Last"));
cls_GeomFill_LocFunction.def("D2", (Standard_Boolean (GeomFill_LocFunction::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &GeomFill_LocFunction::D2, "compute the second derivative in v direction of the section for v = param", py::arg("Param"), py::arg("First"), py::arg("Last"));
cls_GeomFill_LocFunction.def("DN", [](GeomFill_LocFunction &self, const Standard_Real Param, const Standard_Real First, const Standard_Real Last, const Standard_Integer Order, Standard_Real & Result, Standard_Integer & Ier){ self.DN(Param, First, Last, Order, Result, Ier); return std::tuple<Standard_Real &, Standard_Integer &>(Result, Ier); }, "None", py::arg("Param"), py::arg("First"), py::arg("Last"), py::arg("Order"), py::arg("Result"), py::arg("Ier"));

// CLASS: GEOMFILL_NSECTIONS
py::class_<GeomFill_NSections, opencascade::handle<GeomFill_NSections>, GeomFill_SectionLaw> cls_GeomFill_NSections(mod, "GeomFill_NSections", "Define a Section Law by N Sections");

// Constructors
cls_GeomFill_NSections.def(py::init<const TColGeom_SequenceOfCurve &>(), py::arg("NC"));
cls_GeomFill_NSections.def(py::init<const TColGeom_SequenceOfCurve &, const TColStd_SequenceOfReal &>(), py::arg("NC"), py::arg("NP"));
// cls_GeomFill_NSections.def(py::init<const TColGeom_SequenceOfCurve &, const TColStd_SequenceOfReal &, const Standard_Real, const Standard_Real>(), py::arg("NC"), py::arg("NP"), py::arg("UF"), py::arg("UL"));
cls_GeomFill_NSections.def(py::init<const TColGeom_SequenceOfCurve &, const TColStd_SequenceOfReal &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("NC"), py::arg("NP"), py::arg("UF"), py::arg("UL"), py::arg("VF"), py::arg("VL"));
cls_GeomFill_NSections.def(py::init<const TColGeom_SequenceOfCurve &, const GeomFill_SequenceOfTrsf &, const TColStd_SequenceOfReal &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_BSplineSurface> &>(), py::arg("NC"), py::arg("Trsfs"), py::arg("NP"), py::arg("UF"), py::arg("UL"), py::arg("VF"), py::arg("VL"), py::arg("Surf"));

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

// CLASS: GEOMFILL_PIPE
py::class_<GeomFill_Pipe> cls_GeomFill_Pipe(mod, "GeomFill_Pipe", "Describes functions to construct pipes. A pipe is built by sweeping a curve (the section) along another curve (the path). The Pipe class provides the following types of construction: - pipes with a circular section of constant radius, - pipes with a constant section, - pipes with a section evolving between two given curves. All standard specific cases are detected in order to build, where required, a plane, cylinder, cone, sphere, torus, surface of linear extrusion or surface of revolution. Generally speaking, the result is a BSpline surface (NURBS). A Pipe object provides a framework for: - defining the pipe to be built, - implementing the construction algorithm, and - consulting the resulting surface. There are several methods to instantiate a Pipe: 1) give a path and a radius : the section is a circle. This location is the first point of the path, and this direction is the first derivate (calculate at the first point ) of the path.");

// Constructors
cls_GeomFill_Pipe.def(py::init<>());
cls_GeomFill_Pipe.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real>(), py::arg("Path"), py::arg("Radius"));
cls_GeomFill_Pipe.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &>(), py::arg("Path"), py::arg("FirstSect"));
cls_GeomFill_Pipe.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const GeomFill_Trihedron>(), py::arg("Path"), py::arg("FirstSect"), py::arg("Option"));
cls_GeomFill_Pipe.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Curve> &>(), py::arg("Path"), py::arg("Support"), py::arg("FirstSect"));
cls_GeomFill_Pipe.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const gp_Dir &>(), py::arg("Path"), py::arg("FirstSect"), py::arg("Dir"));
cls_GeomFill_Pipe.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &>(), py::arg("Path"), py::arg("FirstSect"), py::arg("LastSect"));
cls_GeomFill_Pipe.def(py::init<const opencascade::handle<Geom_Curve> &, const TColGeom_SequenceOfCurve &>(), py::arg("Path"), py::arg("NSections"));
cls_GeomFill_Pipe.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const Standard_Real>(), py::arg("Path"), py::arg("Curve1"), py::arg("Curve2"), py::arg("Radius"));
cls_GeomFill_Pipe.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real>(), py::arg("Path"), py::arg("Curve1"), py::arg("Curve2"), py::arg("Radius"));
cls_GeomFill_Pipe.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Geom_Curve> &, const Standard_Boolean, const Standard_Boolean>(), py::arg("Path"), py::arg("Guide"), py::arg("FirstSect"), py::arg("ByACR"), py::arg("rotat"));

// Methods
// cls_GeomFill_Pipe.def_static("operator new_", (void * (*)(size_t)) &GeomFill_Pipe::operator new, "None", py::arg("theSize"));
// cls_GeomFill_Pipe.def_static("operator delete_", (void (*)(void *)) &GeomFill_Pipe::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_Pipe.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_Pipe::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_Pipe.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_Pipe::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_Pipe.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_Pipe::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_Pipe.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_Pipe::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_Pipe.def("Init", (void (GeomFill_Pipe::*)(const opencascade::handle<Geom_Curve> &, const Standard_Real)) &GeomFill_Pipe::Init, "None", py::arg("Path"), py::arg("Radius"));
cls_GeomFill_Pipe.def("Init", [](GeomFill_Pipe &self, const opencascade::handle<Geom_Curve> & a0, const opencascade::handle<Geom_Curve> & a1) -> void { return self.Init(a0, a1); });
cls_GeomFill_Pipe.def("Init", (void (GeomFill_Pipe::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const GeomFill_Trihedron)) &GeomFill_Pipe::Init, "None", py::arg("Path"), py::arg("FirstSect"), py::arg("Option"));
cls_GeomFill_Pipe.def("Init", (void (GeomFill_Pipe::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Curve> &)) &GeomFill_Pipe::Init, "None", py::arg("Path"), py::arg("Support"), py::arg("FirstSect"));
cls_GeomFill_Pipe.def("Init", (void (GeomFill_Pipe::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const gp_Dir &)) &GeomFill_Pipe::Init, "None", py::arg("Path"), py::arg("FirstSect"), py::arg("Dir"));
cls_GeomFill_Pipe.def("Init", (void (GeomFill_Pipe::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &)) &GeomFill_Pipe::Init, "None", py::arg("Path"), py::arg("FirstSect"), py::arg("LastSect"));
cls_GeomFill_Pipe.def("Init", (void (GeomFill_Pipe::*)(const opencascade::handle<Geom_Curve> &, const TColGeom_SequenceOfCurve &)) &GeomFill_Pipe::Init, "None", py::arg("Path"), py::arg("NSections"));
cls_GeomFill_Pipe.def("Init", (void (GeomFill_Pipe::*)(const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real)) &GeomFill_Pipe::Init, "Create a pipe with a constant radius with 2 guide-line.", py::arg("Path"), py::arg("Curve1"), py::arg("Curve2"), py::arg("Radius"));
cls_GeomFill_Pipe.def("Init", (void (GeomFill_Pipe::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Geom_Curve> &, const Standard_Boolean, const Standard_Boolean)) &GeomFill_Pipe::Init, "Initializes this pipe algorithm to build the following surface: - a pipe with a constant circular section of radius Radius along the path Path, or - a pipe with constant section FirstSect along the path Path, or - a pipe where the section evolves from FirstSect to LastSect along the path Path. Use the function Perform to build the surface. Note: a description of the resulting surface is given under Constructors.", py::arg("Path"), py::arg("Guide"), py::arg("FirstSect"), py::arg("ByACR"), py::arg("rotat"));
cls_GeomFill_Pipe.def("Perform", [](GeomFill_Pipe &self) -> void { return self.Perform(); });
cls_GeomFill_Pipe.def("Perform", [](GeomFill_Pipe &self, const Standard_Boolean a0) -> void { return self.Perform(a0); });
cls_GeomFill_Pipe.def("Perform", (void (GeomFill_Pipe::*)(const Standard_Boolean, const Standard_Boolean)) &GeomFill_Pipe::Perform, "Builds the pipe defined at the time of initialization of this algorithm. A description of the resulting surface is given under Constructors. If WithParameters (defaulted to false) is set to true, the approximation algorithm (used only in the general case of construction of a BSpline surface) builds the surface with a u parameter corresponding to the one of the path. Exceptions Standard_ConstructionError if a surface cannot be constructed from the data. Warning: It is the old Perform method, the next methode is recommended.", py::arg("WithParameters"), py::arg("myPolynomial"));
cls_GeomFill_Pipe.def("Perform", [](GeomFill_Pipe &self, const Standard_Real a0, const Standard_Boolean a1) -> void { return self.Perform(a0, a1); });
cls_GeomFill_Pipe.def("Perform", [](GeomFill_Pipe &self, const Standard_Real a0, const Standard_Boolean a1, const GeomAbs_Shape a2) -> void { return self.Perform(a0, a1, a2); });
cls_GeomFill_Pipe.def("Perform", [](GeomFill_Pipe &self, const Standard_Real a0, const Standard_Boolean a1, const GeomAbs_Shape a2, const Standard_Integer a3) -> void { return self.Perform(a0, a1, a2, a3); });
cls_GeomFill_Pipe.def("Perform", (void (GeomFill_Pipe::*)(const Standard_Real, const Standard_Boolean, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer)) &GeomFill_Pipe::Perform, "detects the particular cases. And compute the surface. if none particular case is detected we make an approximation with respect of the Tolerance <Tol>, the continuty <Conti>, the maximum degree <MaxDegree>, the maximum number of span <NbMaxSegment> and the spine parametrization. If we can't create a surface with the data", py::arg("Tol"), py::arg("Polynomial"), py::arg("Conti"), py::arg("MaxDegree"), py::arg("NbMaxSegment"));
cls_GeomFill_Pipe.def("Surface", (const opencascade::handle<Geom_Surface> & (GeomFill_Pipe::*)() const) &GeomFill_Pipe::Surface, "Returns the surface built by this algorithm. Warning Do not use this function before the surface is built (in this case the function will return a null handle).");
cls_GeomFill_Pipe.def("ExchangeUV", (Standard_Boolean (GeomFill_Pipe::*)() const) &GeomFill_Pipe::ExchangeUV, "The u parametric direction of the surface constructed by this algorithm usually corresponds to the evolution along the path and the v parametric direction corresponds to the evolution along the section(s). However, this rule is not respected when constructing certain specific Geom surfaces (typically cylindrical surfaces, surfaces of revolution, etc.) for which the parameterization is inversed. The ExchangeUV function checks for this, and returns true in all these specific cases. Warning Do not use this function before the surface is built.");
cls_GeomFill_Pipe.def("GenerateParticularCase", (void (GeomFill_Pipe::*)(const Standard_Boolean)) &GeomFill_Pipe::GenerateParticularCase, "Sets a flag to try to create as many planes, cylinder,... as possible. Default value is <Standard_False>.", py::arg("B"));
cls_GeomFill_Pipe.def("GenerateParticularCase", (Standard_Boolean (GeomFill_Pipe::*)() const) &GeomFill_Pipe::GenerateParticularCase, "Returns the flag.");
cls_GeomFill_Pipe.def("ErrorOnSurf", (Standard_Real (GeomFill_Pipe::*)() const) &GeomFill_Pipe::ErrorOnSurf, "Returns the approximation's error. if the Surface is plane, cylinder ... this error can be 0.");
cls_GeomFill_Pipe.def("IsDone", (Standard_Boolean (GeomFill_Pipe::*)() const) &GeomFill_Pipe::IsDone, "Returns whether approximation was done.");

// CLASS: GEOMFILL_PLANFUNC
py::class_<GeomFill_PlanFunc, math_FunctionWithDerivative> cls_GeomFill_PlanFunc(mod, "GeomFill_PlanFunc", "None");

// Constructors
cls_GeomFill_PlanFunc.def(py::init<const gp_Pnt &, const gp_Vec &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("P"), py::arg("V"), py::arg("C"));

// Methods
// cls_GeomFill_PlanFunc.def_static("operator new_", (void * (*)(size_t)) &GeomFill_PlanFunc::operator new, "None", py::arg("theSize"));
// cls_GeomFill_PlanFunc.def_static("operator delete_", (void (*)(void *)) &GeomFill_PlanFunc::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_PlanFunc.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_PlanFunc::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_PlanFunc.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_PlanFunc::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_PlanFunc.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_PlanFunc::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_PlanFunc.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_PlanFunc::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_PlanFunc.def("Value", [](GeomFill_PlanFunc &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "computes the value <F>of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("F"));
cls_GeomFill_PlanFunc.def("Derivative", [](GeomFill_PlanFunc &self, const Standard_Real X, Standard_Real & D){ Standard_Boolean rv = self.Derivative(X, D); return std::tuple<Standard_Boolean, Standard_Real &>(rv, D); }, "computes the derivative <D> of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("D"));
cls_GeomFill_PlanFunc.def("Values", [](GeomFill_PlanFunc &self, const Standard_Real X, Standard_Real & F, Standard_Real & D){ Standard_Boolean rv = self.Values(X, F, D); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, D); }, "computes the value <F> and the derivative <D> of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
cls_GeomFill_PlanFunc.def("D2", [](GeomFill_PlanFunc &self, const Standard_Real X, Standard_Real & F, Standard_Real & D1, Standard_Real & D2){ self.D2(X, F, D1, D2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(F, D1, D2); }, "None", py::arg("X"), py::arg("F"), py::arg("D1"), py::arg("D2"));
cls_GeomFill_PlanFunc.def("DEDT", [](GeomFill_PlanFunc &self, const Standard_Real X, const gp_Vec & DP, const gp_Vec & DV, Standard_Real & DF){ self.DEDT(X, DP, DV, DF); return DF; }, "None", py::arg("X"), py::arg("DP"), py::arg("DV"), py::arg("DF"));
cls_GeomFill_PlanFunc.def("D2E", [](GeomFill_PlanFunc &self, const Standard_Real X, const gp_Vec & DP, const gp_Vec & D2P, const gp_Vec & DV, const gp_Vec & D2V, Standard_Real & DFDT, Standard_Real & D2FDT2, Standard_Real & D2FDTDX){ self.D2E(X, DP, D2P, DV, D2V, DFDT, D2FDT2, D2FDTDX); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(DFDT, D2FDT2, D2FDTDX); }, "None", py::arg("X"), py::arg("DP"), py::arg("D2P"), py::arg("DV"), py::arg("D2V"), py::arg("DFDT"), py::arg("D2FDT2"), py::arg("D2FDTDX"));

// CLASS: GEOMFILL_POLYNOMIALCONVERTOR
py::class_<GeomFill_PolynomialConvertor> cls_GeomFill_PolynomialConvertor(mod, "GeomFill_PolynomialConvertor", "To convert circular section in polynome");

// Constructors
cls_GeomFill_PolynomialConvertor.def(py::init<>());

// Methods
// cls_GeomFill_PolynomialConvertor.def_static("operator new_", (void * (*)(size_t)) &GeomFill_PolynomialConvertor::operator new, "None", py::arg("theSize"));
// cls_GeomFill_PolynomialConvertor.def_static("operator delete_", (void (*)(void *)) &GeomFill_PolynomialConvertor::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_PolynomialConvertor.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_PolynomialConvertor::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_PolynomialConvertor.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_PolynomialConvertor::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_PolynomialConvertor.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_PolynomialConvertor::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_PolynomialConvertor.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_PolynomialConvertor::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_PolynomialConvertor.def("Initialized", (Standard_Boolean (GeomFill_PolynomialConvertor::*)() const) &GeomFill_PolynomialConvertor::Initialized, "say if <me> is Initialized");
cls_GeomFill_PolynomialConvertor.def("Init", (void (GeomFill_PolynomialConvertor::*)()) &GeomFill_PolynomialConvertor::Init, "None");
cls_GeomFill_PolynomialConvertor.def("Section", (void (GeomFill_PolynomialConvertor::*)(const gp_Pnt &, const gp_Pnt &, const gp_Vec &, const Standard_Real, TColgp_Array1OfPnt &) const) &GeomFill_PolynomialConvertor::Section, "None", py::arg("FirstPnt"), py::arg("Center"), py::arg("Dir"), py::arg("Angle"), py::arg("Poles"));
cls_GeomFill_PolynomialConvertor.def("Section", (void (GeomFill_PolynomialConvertor::*)(const gp_Pnt &, const gp_Vec &, const gp_Pnt &, const gp_Vec &, const gp_Vec &, const gp_Vec &, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &) const) &GeomFill_PolynomialConvertor::Section, "None", py::arg("FirstPnt"), py::arg("DFirstPnt"), py::arg("Center"), py::arg("DCenter"), py::arg("Dir"), py::arg("DDir"), py::arg("Angle"), py::arg("DAngle"), py::arg("Poles"), py::arg("DPoles"));
cls_GeomFill_PolynomialConvertor.def("Section", (void (GeomFill_PolynomialConvertor::*)(const gp_Pnt &, const gp_Vec &, const gp_Vec &, const gp_Pnt &, const gp_Vec &, const gp_Vec &, const gp_Vec &, const gp_Vec &, const gp_Vec &, const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &) const) &GeomFill_PolynomialConvertor::Section, "None", py::arg("FirstPnt"), py::arg("DFirstPnt"), py::arg("D2FirstPnt"), py::arg("Center"), py::arg("DCenter"), py::arg("D2Center"), py::arg("Dir"), py::arg("DDir"), py::arg("D2Dir"), py::arg("Angle"), py::arg("DAngle"), py::arg("D2Angle"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"));

// CLASS: GEOMFILL_QUASIANGULARCONVERTOR
py::class_<GeomFill_QuasiAngularConvertor> cls_GeomFill_QuasiAngularConvertor(mod, "GeomFill_QuasiAngularConvertor", "To convert circular section in QuasiAngular Bezier form");

// Constructors
cls_GeomFill_QuasiAngularConvertor.def(py::init<>());

// Methods
// cls_GeomFill_QuasiAngularConvertor.def_static("operator new_", (void * (*)(size_t)) &GeomFill_QuasiAngularConvertor::operator new, "None", py::arg("theSize"));
// cls_GeomFill_QuasiAngularConvertor.def_static("operator delete_", (void (*)(void *)) &GeomFill_QuasiAngularConvertor::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_QuasiAngularConvertor.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_QuasiAngularConvertor::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_QuasiAngularConvertor.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_QuasiAngularConvertor::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_QuasiAngularConvertor.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_QuasiAngularConvertor::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_QuasiAngularConvertor.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_QuasiAngularConvertor::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_QuasiAngularConvertor.def("Initialized", (Standard_Boolean (GeomFill_QuasiAngularConvertor::*)() const) &GeomFill_QuasiAngularConvertor::Initialized, "say if <me> is Initialized");
cls_GeomFill_QuasiAngularConvertor.def("Init", (void (GeomFill_QuasiAngularConvertor::*)()) &GeomFill_QuasiAngularConvertor::Init, "None");
cls_GeomFill_QuasiAngularConvertor.def("Section", (void (GeomFill_QuasiAngularConvertor::*)(const gp_Pnt &, const gp_Pnt &, const gp_Vec &, const Standard_Real, TColgp_Array1OfPnt &, TColStd_Array1OfReal &)) &GeomFill_QuasiAngularConvertor::Section, "None", py::arg("FirstPnt"), py::arg("Center"), py::arg("Dir"), py::arg("Angle"), py::arg("Poles"), py::arg("Weights"));
cls_GeomFill_QuasiAngularConvertor.def("Section", (void (GeomFill_QuasiAngularConvertor::*)(const gp_Pnt &, const gp_Vec &, const gp_Pnt &, const gp_Vec &, const gp_Vec &, const gp_Vec &, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &GeomFill_QuasiAngularConvertor::Section, "None", py::arg("FirstPnt"), py::arg("DFirstPnt"), py::arg("Center"), py::arg("DCenter"), py::arg("Dir"), py::arg("DDir"), py::arg("Angle"), py::arg("DAngle"), py::arg("Poles"), py::arg("DPoles"), py::arg("Weights"), py::arg("DWeights"));
cls_GeomFill_QuasiAngularConvertor.def("Section", (void (GeomFill_QuasiAngularConvertor::*)(const gp_Pnt &, const gp_Vec &, const gp_Vec &, const gp_Pnt &, const gp_Vec &, const gp_Vec &, const gp_Vec &, const gp_Vec &, const gp_Vec &, const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &GeomFill_QuasiAngularConvertor::Section, "None", py::arg("FirstPnt"), py::arg("DFirstPnt"), py::arg("D2FirstPnt"), py::arg("Center"), py::arg("DCenter"), py::arg("D2Center"), py::arg("Dir"), py::arg("DDir"), py::arg("D2Dir"), py::arg("Angle"), py::arg("DAngle"), py::arg("D2Angle"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Weights"), py::arg("DWeights"), py::arg("D2Weights"));

// CLASS: GEOMFILL_SECTIONGENERATOR
py::class_<GeomFill_SectionGenerator, GeomFill_Profiler> cls_GeomFill_SectionGenerator(mod, "GeomFill_SectionGenerator", "gives the functions needed for instantiation from AppSurf in AppBlend. Allow to evaluate a surface passing by all the curves if the Profiler.");

// Constructors
cls_GeomFill_SectionGenerator.def(py::init<>());

// Methods
// cls_GeomFill_SectionGenerator.def_static("operator new_", (void * (*)(size_t)) &GeomFill_SectionGenerator::operator new, "None", py::arg("theSize"));
// cls_GeomFill_SectionGenerator.def_static("operator delete_", (void (*)(void *)) &GeomFill_SectionGenerator::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_SectionGenerator.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_SectionGenerator::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_SectionGenerator.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_SectionGenerator::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_SectionGenerator.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_SectionGenerator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_SectionGenerator.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_SectionGenerator::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_SectionGenerator.def("SetParam", (void (GeomFill_SectionGenerator::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &GeomFill_SectionGenerator::SetParam, "None", py::arg("Params"));
cls_GeomFill_SectionGenerator.def("GetShape", [](GeomFill_SectionGenerator &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
cls_GeomFill_SectionGenerator.def("Knots", (void (GeomFill_SectionGenerator::*)(TColStd_Array1OfReal &) const) &GeomFill_SectionGenerator::Knots, "None", py::arg("TKnots"));
cls_GeomFill_SectionGenerator.def("Mults", (void (GeomFill_SectionGenerator::*)(TColStd_Array1OfInteger &) const) &GeomFill_SectionGenerator::Mults, "None", py::arg("TMults"));
cls_GeomFill_SectionGenerator.def("Section", (Standard_Boolean (GeomFill_SectionGenerator::*)(const Standard_Integer, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &) const) &GeomFill_SectionGenerator::Section, "Used for the first and last section The method returns Standard_True if the derivatives are computed, otherwise it returns Standard_False.", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_GeomFill_SectionGenerator.def("Section", (void (GeomFill_SectionGenerator::*)(const Standard_Integer, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &) const) &GeomFill_SectionGenerator::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_GeomFill_SectionGenerator.def("Parameter", (Standard_Real (GeomFill_SectionGenerator::*)(const Standard_Integer) const) &GeomFill_SectionGenerator::Parameter, "Returns the parameter of Section<P>, to impose it for the approximation.", py::arg("P"));

// CLASS: GEOMFILL_SECTIONPLACEMENT
py::class_<GeomFill_SectionPlacement> cls_GeomFill_SectionPlacement(mod, "GeomFill_SectionPlacement", "To place section in sweep Function");

// Constructors
cls_GeomFill_SectionPlacement.def(py::init<const opencascade::handle<GeomFill_LocationLaw> &, const opencascade::handle<Geom_Geometry> &>(), py::arg("L"), py::arg("Section"));

// Methods
// cls_GeomFill_SectionPlacement.def_static("operator new_", (void * (*)(size_t)) &GeomFill_SectionPlacement::operator new, "None", py::arg("theSize"));
// cls_GeomFill_SectionPlacement.def_static("operator delete_", (void (*)(void *)) &GeomFill_SectionPlacement::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_SectionPlacement.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_SectionPlacement::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_SectionPlacement.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_SectionPlacement::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_SectionPlacement.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_SectionPlacement::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_SectionPlacement.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_SectionPlacement::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_SectionPlacement.def("SetLocation", (void (GeomFill_SectionPlacement::*)(const opencascade::handle<GeomFill_LocationLaw> &)) &GeomFill_SectionPlacement::SetLocation, "To change the section Law", py::arg("L"));
cls_GeomFill_SectionPlacement.def("Perform", (void (GeomFill_SectionPlacement::*)(const Standard_Real)) &GeomFill_SectionPlacement::Perform, "None", py::arg("Tol"));
cls_GeomFill_SectionPlacement.def("Perform", (void (GeomFill_SectionPlacement::*)(const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real)) &GeomFill_SectionPlacement::Perform, "None", py::arg("Path"), py::arg("Tol"));
cls_GeomFill_SectionPlacement.def("Perform", (void (GeomFill_SectionPlacement::*)(const Standard_Real, const Standard_Real)) &GeomFill_SectionPlacement::Perform, "None", py::arg("ParamOnPath"), py::arg("Tol"));
cls_GeomFill_SectionPlacement.def("IsDone", (Standard_Boolean (GeomFill_SectionPlacement::*)() const) &GeomFill_SectionPlacement::IsDone, "None");
cls_GeomFill_SectionPlacement.def("ParameterOnPath", (Standard_Real (GeomFill_SectionPlacement::*)() const) &GeomFill_SectionPlacement::ParameterOnPath, "None");
cls_GeomFill_SectionPlacement.def("ParameterOnSection", (Standard_Real (GeomFill_SectionPlacement::*)() const) &GeomFill_SectionPlacement::ParameterOnSection, "None");
cls_GeomFill_SectionPlacement.def("Distance", (Standard_Real (GeomFill_SectionPlacement::*)() const) &GeomFill_SectionPlacement::Distance, "None");
cls_GeomFill_SectionPlacement.def("Angle", (Standard_Real (GeomFill_SectionPlacement::*)() const) &GeomFill_SectionPlacement::Angle, "None");
cls_GeomFill_SectionPlacement.def("Transformation", [](GeomFill_SectionPlacement &self, const Standard_Boolean a0) -> gp_Trsf { return self.Transformation(a0); });
cls_GeomFill_SectionPlacement.def("Transformation", (gp_Trsf (GeomFill_SectionPlacement::*)(const Standard_Boolean, const Standard_Boolean) const) &GeomFill_SectionPlacement::Transformation, "None", py::arg("WithTranslation"), py::arg("WithCorrection"));
cls_GeomFill_SectionPlacement.def("Section", (opencascade::handle<Geom_Curve> (GeomFill_SectionPlacement::*)(const Standard_Boolean) const) &GeomFill_SectionPlacement::Section, "Compute the Section, in the coordinate syteme given by the Location Law. If <WithTranslation> contact beetween <Section> and <Path> is forced.", py::arg("WithTranslation"));
cls_GeomFill_SectionPlacement.def("ModifiedSection", (opencascade::handle<Geom_Curve> (GeomFill_SectionPlacement::*)(const Standard_Boolean) const) &GeomFill_SectionPlacement::ModifiedSection, "Compute the Section, in the coordinate syteme given by the Location Law. To have the Normal to section equal to the Location Law Normal. If <WithTranslation> contact beetween <Section> and <Path> is forced.", py::arg("WithTranslation"));

// CLASS: GEOMFILL_SNGLRFUNC
py::class_<GeomFill_SnglrFunc, Adaptor3d_Curve> cls_GeomFill_SnglrFunc(mod, "GeomFill_SnglrFunc", "to represent function C'(t)^C''(t)");

// Constructors
cls_GeomFill_SnglrFunc.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("HC"));

// Methods
// cls_GeomFill_SnglrFunc.def_static("operator new_", (void * (*)(size_t)) &GeomFill_SnglrFunc::operator new, "None", py::arg("theSize"));
// cls_GeomFill_SnglrFunc.def_static("operator delete_", (void (*)(void *)) &GeomFill_SnglrFunc::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_SnglrFunc.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_SnglrFunc::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_SnglrFunc.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_SnglrFunc::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_SnglrFunc.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_SnglrFunc::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_SnglrFunc.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_SnglrFunc::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_SnglrFunc.def("SetRatio", (void (GeomFill_SnglrFunc::*)(const Standard_Real)) &GeomFill_SnglrFunc::SetRatio, "None", py::arg("Ratio"));
cls_GeomFill_SnglrFunc.def("FirstParameter", (Standard_Real (GeomFill_SnglrFunc::*)() const) &GeomFill_SnglrFunc::FirstParameter, "None");
cls_GeomFill_SnglrFunc.def("LastParameter", (Standard_Real (GeomFill_SnglrFunc::*)() const) &GeomFill_SnglrFunc::LastParameter, "None");
cls_GeomFill_SnglrFunc.def("NbIntervals", (Standard_Integer (GeomFill_SnglrFunc::*)(const GeomAbs_Shape) const) &GeomFill_SnglrFunc::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
cls_GeomFill_SnglrFunc.def("Intervals", (void (GeomFill_SnglrFunc::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const) &GeomFill_SnglrFunc::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
cls_GeomFill_SnglrFunc.def("Value", (gp_Pnt (GeomFill_SnglrFunc::*)(const Standard_Real) const) &GeomFill_SnglrFunc::Value, "Computes the point of parameter U on the curve.", py::arg("U"));
cls_GeomFill_SnglrFunc.def("IsPeriodic", (Standard_Boolean (GeomFill_SnglrFunc::*)() const) &GeomFill_SnglrFunc::IsPeriodic, "None");
cls_GeomFill_SnglrFunc.def("Period", (Standard_Real (GeomFill_SnglrFunc::*)() const) &GeomFill_SnglrFunc::Period, "None");
cls_GeomFill_SnglrFunc.def("D0", (void (GeomFill_SnglrFunc::*)(const Standard_Real, gp_Pnt &) const) &GeomFill_SnglrFunc::D0, "Computes the point of parameter U on the curve.", py::arg("U"), py::arg("P"));
cls_GeomFill_SnglrFunc.def("D1", (void (GeomFill_SnglrFunc::*)(const Standard_Real, gp_Pnt &, gp_Vec &) const) &GeomFill_SnglrFunc::D1, "Computes the point of parameter U on the curve with its first derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V"));
cls_GeomFill_SnglrFunc.def("D2", (void (GeomFill_SnglrFunc::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &) const) &GeomFill_SnglrFunc::D2, "Returns the point P of parameter U, the first and second derivatives V1 and V2. Raised if the continuity of the current interval is not C2.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"));
cls_GeomFill_SnglrFunc.def("D3", (void (GeomFill_SnglrFunc::*)(const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &) const) &GeomFill_SnglrFunc::D3, "Returns the point P of parameter U, the first, the second and the third derivative. Raised if the continuity of the current interval is not C1.", py::arg("U"), py::arg("P"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_GeomFill_SnglrFunc.def("DN", (gp_Vec (GeomFill_SnglrFunc::*)(const Standard_Real, const Standard_Integer) const) &GeomFill_SnglrFunc::DN, "The returned vector gives the value of the derivative for the order of derivation N. Raised if N < 1.", py::arg("U"), py::arg("N"));
cls_GeomFill_SnglrFunc.def("Resolution", (Standard_Real (GeomFill_SnglrFunc::*)(const Standard_Real) const) &GeomFill_SnglrFunc::Resolution, "Returns the parametric resolution corresponding to the real space resolution <R3d>.", py::arg("R3d"));
cls_GeomFill_SnglrFunc.def("GetType", (GeomAbs_CurveType (GeomFill_SnglrFunc::*)() const) &GeomFill_SnglrFunc::GetType, "Returns the type of the curve in the current interval : Line, Circle, Ellipse, Hyperbola, Parabola, BezierCurve, BSplineCurve, OtherCurve.");

// CLASS: GEOMFILL_STRETCH
py::class_<GeomFill_Stretch, GeomFill_Filling> cls_GeomFill_Stretch(mod, "GeomFill_Stretch", "None");

// Constructors
cls_GeomFill_Stretch.def(py::init<>());
cls_GeomFill_Stretch.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"));
cls_GeomFill_Stretch.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"), py::arg("W1"), py::arg("W2"), py::arg("W3"), py::arg("W4"));

// Methods
// cls_GeomFill_Stretch.def_static("operator new_", (void * (*)(size_t)) &GeomFill_Stretch::operator new, "None", py::arg("theSize"));
// cls_GeomFill_Stretch.def_static("operator delete_", (void (*)(void *)) &GeomFill_Stretch::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_Stretch.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_Stretch::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_Stretch.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_Stretch::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_Stretch.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_Stretch::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_Stretch.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_Stretch::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_Stretch.def("Init", (void (GeomFill_Stretch::*)(const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &)) &GeomFill_Stretch::Init, "None", py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"));
cls_GeomFill_Stretch.def("Init", (void (GeomFill_Stretch::*)(const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &)) &GeomFill_Stretch::Init, "None", py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"), py::arg("W1"), py::arg("W2"), py::arg("W3"), py::arg("W4"));

// CLASS: GEOMFILL_SWEEP
py::class_<GeomFill_Sweep> cls_GeomFill_Sweep(mod, "GeomFill_Sweep", "Geometrical Sweep Algorithm");

// Constructors
cls_GeomFill_Sweep.def(py::init<const opencascade::handle<GeomFill_LocationLaw> &>(), py::arg("Location"));
cls_GeomFill_Sweep.def(py::init<const opencascade::handle<GeomFill_LocationLaw> &, const Standard_Boolean>(), py::arg("Location"), py::arg("WithKpart"));

// Methods
// cls_GeomFill_Sweep.def_static("operator new_", (void * (*)(size_t)) &GeomFill_Sweep::operator new, "None", py::arg("theSize"));
// cls_GeomFill_Sweep.def_static("operator delete_", (void (*)(void *)) &GeomFill_Sweep::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_Sweep.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_Sweep::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_Sweep.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_Sweep::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_Sweep.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_Sweep::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_Sweep.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_Sweep::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_Sweep.def("SetDomain", (void (GeomFill_Sweep::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomFill_Sweep::SetDomain, "Set parametric information [<First>, <Last>] Sets the parametric bound of the sweeping surface to build. <SectionFirst>, <SectionLast> gives coresponding bounds parameter on the section law of <First> and <Last>", py::arg("First"), py::arg("Last"), py::arg("SectionFirst"), py::arg("SectionLast"));
cls_GeomFill_Sweep.def("SetTolerance", [](GeomFill_Sweep &self, const Standard_Real a0) -> void { return self.SetTolerance(a0); });
cls_GeomFill_Sweep.def("SetTolerance", [](GeomFill_Sweep &self, const Standard_Real a0, const Standard_Real a1) -> void { return self.SetTolerance(a0, a1); });
cls_GeomFill_Sweep.def("SetTolerance", [](GeomFill_Sweep &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.SetTolerance(a0, a1, a2); });
cls_GeomFill_Sweep.def("SetTolerance", (void (GeomFill_Sweep::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomFill_Sweep::SetTolerance, "Set Approximation Tolerance Tol3d : Tolerance to surface approximation Tol2d : Tolerance used to perform curve approximation Normaly the 2d curve are approximated with a tolerance given by the resolution method define in <LocationLaw> but if this tolerance is too large Tol2d is used. TolAngular : Tolerance (in radian) to control the angle beetween tangents on the section law and tangent of iso-v on approximed surface", py::arg("Tol3d"), py::arg("BoundTol"), py::arg("Tol2d"), py::arg("TolAngular"));
cls_GeomFill_Sweep.def("SetForceApproxC1", (void (GeomFill_Sweep::*)(const Standard_Boolean)) &GeomFill_Sweep::SetForceApproxC1, "Set the flag that indicates attempt to approximate a C1-continuous surface if a swept surface proved to be C0.", py::arg("ForceApproxC1"));
cls_GeomFill_Sweep.def("ExchangeUV", (Standard_Boolean (GeomFill_Sweep::*)() const) &GeomFill_Sweep::ExchangeUV, "returns true if sections are U-Iso This can be produce in some cases when <WithKpart> is True.");
cls_GeomFill_Sweep.def("UReversed", (Standard_Boolean (GeomFill_Sweep::*)() const) &GeomFill_Sweep::UReversed, "returns true if Parametrisation sens in U is inverse of parametrisation sens of section (or of path if ExchangeUV)");
cls_GeomFill_Sweep.def("VReversed", (Standard_Boolean (GeomFill_Sweep::*)() const) &GeomFill_Sweep::VReversed, "returns true if Parametrisation sens in V is inverse of parametrisation sens of path (or of section if ExchangeUV)");
cls_GeomFill_Sweep.def("Build", [](GeomFill_Sweep &self, const opencascade::handle<GeomFill_SectionLaw> & a0) -> void { return self.Build(a0); });
cls_GeomFill_Sweep.def("Build", [](GeomFill_Sweep &self, const opencascade::handle<GeomFill_SectionLaw> & a0, const GeomFill_ApproxStyle a1) -> void { return self.Build(a0, a1); });
cls_GeomFill_Sweep.def("Build", [](GeomFill_Sweep &self, const opencascade::handle<GeomFill_SectionLaw> & a0, const GeomFill_ApproxStyle a1, const GeomAbs_Shape a2) -> void { return self.Build(a0, a1, a2); });
cls_GeomFill_Sweep.def("Build", [](GeomFill_Sweep &self, const opencascade::handle<GeomFill_SectionLaw> & a0, const GeomFill_ApproxStyle a1, const GeomAbs_Shape a2, const Standard_Integer a3) -> void { return self.Build(a0, a1, a2, a3); });
cls_GeomFill_Sweep.def("Build", (void (GeomFill_Sweep::*)(const opencascade::handle<GeomFill_SectionLaw> &, const GeomFill_ApproxStyle, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer)) &GeomFill_Sweep::Build, "Build the Sweeep Surface ApproxStyle defines Approximation Strategy - GeomFill_Section : The composed Function : Location X Section is directly approximed. - GeomFill_Location : The location law is approximed, and the SweepSurface is build algebric composition of approximed location law and section law This option is Ok, if Section.Surface() methode is effective. Continuity : The continuity in v waiting on the surface Degmax : The maximum degree in v requiered on the surface Segmax : The maximum number of span in v requiered on the surface", py::arg("Section"), py::arg("Methode"), py::arg("Continuity"), py::arg("Degmax"), py::arg("Segmax"));
cls_GeomFill_Sweep.def("IsDone", (Standard_Boolean (GeomFill_Sweep::*)() const) &GeomFill_Sweep::IsDone, "Tells if the Surface is Buildt.");
cls_GeomFill_Sweep.def("ErrorOnSurface", (Standard_Real (GeomFill_Sweep::*)() const) &GeomFill_Sweep::ErrorOnSurface, "Gets the Approximation error.");
cls_GeomFill_Sweep.def("ErrorOnRestriction", [](GeomFill_Sweep &self, const Standard_Boolean IsFirst, Standard_Real & UError, Standard_Real & VError){ self.ErrorOnRestriction(IsFirst, UError, VError); return std::tuple<Standard_Real &, Standard_Real &>(UError, VError); }, "Gets the Approximation error.", py::arg("IsFirst"), py::arg("UError"), py::arg("VError"));
cls_GeomFill_Sweep.def("ErrorOnTrace", [](GeomFill_Sweep &self, const Standard_Integer IndexOfTrace, Standard_Real & UError, Standard_Real & VError){ self.ErrorOnTrace(IndexOfTrace, UError, VError); return std::tuple<Standard_Real &, Standard_Real &>(UError, VError); }, "Gets the Approximation error.", py::arg("IndexOfTrace"), py::arg("UError"), py::arg("VError"));
cls_GeomFill_Sweep.def("Surface", (opencascade::handle<Geom_Surface> (GeomFill_Sweep::*)() const) &GeomFill_Sweep::Surface, "None");
cls_GeomFill_Sweep.def("Restriction", (opencascade::handle<Geom2d_Curve> (GeomFill_Sweep::*)(const Standard_Boolean) const) &GeomFill_Sweep::Restriction, "None", py::arg("IsFirst"));
cls_GeomFill_Sweep.def("NumberOfTrace", (Standard_Integer (GeomFill_Sweep::*)() const) &GeomFill_Sweep::NumberOfTrace, "None");
cls_GeomFill_Sweep.def("Trace", (opencascade::handle<Geom2d_Curve> (GeomFill_Sweep::*)(const Standard_Integer) const) &GeomFill_Sweep::Trace, "None", py::arg("IndexOfTrace"));

// CLASS: GEOMFILL_SWEEPFUNCTION
py::class_<GeomFill_SweepFunction, opencascade::handle<GeomFill_SweepFunction>, Approx_SweepFunction> cls_GeomFill_SweepFunction(mod, "GeomFill_SweepFunction", "Function to approximate by SweepApproximation from Approx. To bulid general sweep Surface.");

// Constructors
cls_GeomFill_SweepFunction.def(py::init<const opencascade::handle<GeomFill_SectionLaw> &, const opencascade::handle<GeomFill_LocationLaw> &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Section"), py::arg("Location"), py::arg("FirstParameter"), py::arg("FirstParameterOnS"), py::arg("RatioParameterOnS"));

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

// CLASS: GEOMFILL_SWEEPSECTIONGENERATOR
py::class_<GeomFill_SweepSectionGenerator> cls_GeomFill_SweepSectionGenerator(mod, "GeomFill_SweepSectionGenerator", "class for instantiation of AppBlend. evaluate the sections of a sweep surface.");

// Constructors
cls_GeomFill_SweepSectionGenerator.def(py::init<>());
cls_GeomFill_SweepSectionGenerator.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real>(), py::arg("Path"), py::arg("Radius"));
cls_GeomFill_SweepSectionGenerator.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &>(), py::arg("Path"), py::arg("FirstSect"));
cls_GeomFill_SweepSectionGenerator.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &>(), py::arg("Path"), py::arg("FirstSect"), py::arg("LastSect"));
// cls_GeomFill_SweepSectionGenerator.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const Standard_Real>(), py::arg("Path"), py::arg("Curve1"), py::arg("Curve2"), py::arg("Radius"));
cls_GeomFill_SweepSectionGenerator.def(py::init<const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real>(), py::arg("Path"), py::arg("Curve1"), py::arg("Curve2"), py::arg("Radius"));

// Methods
// cls_GeomFill_SweepSectionGenerator.def_static("operator new_", (void * (*)(size_t)) &GeomFill_SweepSectionGenerator::operator new, "None", py::arg("theSize"));
// cls_GeomFill_SweepSectionGenerator.def_static("operator delete_", (void (*)(void *)) &GeomFill_SweepSectionGenerator::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_SweepSectionGenerator.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_SweepSectionGenerator::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_SweepSectionGenerator.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_SweepSectionGenerator::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_SweepSectionGenerator.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_SweepSectionGenerator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_SweepSectionGenerator.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_SweepSectionGenerator::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_SweepSectionGenerator.def("Init", (void (GeomFill_SweepSectionGenerator::*)(const opencascade::handle<Geom_Curve> &, const Standard_Real)) &GeomFill_SweepSectionGenerator::Init, "None", py::arg("Path"), py::arg("Radius"));
cls_GeomFill_SweepSectionGenerator.def("Init", (void (GeomFill_SweepSectionGenerator::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &)) &GeomFill_SweepSectionGenerator::Init, "None", py::arg("Path"), py::arg("FirstSect"));
cls_GeomFill_SweepSectionGenerator.def("Init", (void (GeomFill_SweepSectionGenerator::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &)) &GeomFill_SweepSectionGenerator::Init, "None", py::arg("Path"), py::arg("FirstSect"), py::arg("LastSect"));
// cls_GeomFill_SweepSectionGenerator.def("Init", (void (GeomFill_SweepSectionGenerator::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Curve> &, const Standard_Real)) &GeomFill_SweepSectionGenerator::Init, "None", py::arg("Path"), py::arg("Curve1"), py::arg("Curve2"), py::arg("Radius"));
cls_GeomFill_SweepSectionGenerator.def("Init", (void (GeomFill_SweepSectionGenerator::*)(const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const Standard_Real)) &GeomFill_SweepSectionGenerator::Init, "None", py::arg("Path"), py::arg("Curve1"), py::arg("Curve2"), py::arg("Radius"));
cls_GeomFill_SweepSectionGenerator.def("Perform", [](GeomFill_SweepSectionGenerator &self) -> void { return self.Perform(); });
cls_GeomFill_SweepSectionGenerator.def("Perform", (void (GeomFill_SweepSectionGenerator::*)(const Standard_Boolean)) &GeomFill_SweepSectionGenerator::Perform, "None", py::arg("Polynomial"));
cls_GeomFill_SweepSectionGenerator.def("GetShape", [](GeomFill_SweepSectionGenerator &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
cls_GeomFill_SweepSectionGenerator.def("Knots", (void (GeomFill_SweepSectionGenerator::*)(TColStd_Array1OfReal &) const) &GeomFill_SweepSectionGenerator::Knots, "None", py::arg("TKnots"));
cls_GeomFill_SweepSectionGenerator.def("Mults", (void (GeomFill_SweepSectionGenerator::*)(TColStd_Array1OfInteger &) const) &GeomFill_SweepSectionGenerator::Mults, "None", py::arg("TMults"));
cls_GeomFill_SweepSectionGenerator.def("NbSections", (Standard_Integer (GeomFill_SweepSectionGenerator::*)() const) &GeomFill_SweepSectionGenerator::NbSections, "None");
cls_GeomFill_SweepSectionGenerator.def("Section", (Standard_Boolean (GeomFill_SweepSectionGenerator::*)(const Standard_Integer, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &) const) &GeomFill_SweepSectionGenerator::Section, "Used for the first and last section The method returns Standard_True if the derivatives are computed, otherwise it returns Standard_False.", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
cls_GeomFill_SweepSectionGenerator.def("Section", (void (GeomFill_SweepSectionGenerator::*)(const Standard_Integer, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &) const) &GeomFill_SweepSectionGenerator::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
cls_GeomFill_SweepSectionGenerator.def("Transformation", (const gp_Trsf & (GeomFill_SweepSectionGenerator::*)(const Standard_Integer) const) &GeomFill_SweepSectionGenerator::Transformation, "raised if <Index> not in the range [1,NbSections()]", py::arg("Index"));
cls_GeomFill_SweepSectionGenerator.def("Parameter", (Standard_Real (GeomFill_SweepSectionGenerator::*)(const Standard_Integer) const) &GeomFill_SweepSectionGenerator::Parameter, "Returns the parameter of <P>, to impose it for the approximation.", py::arg("P"));

// CLASS: GEOMFILL_TENSOR
py::class_<GeomFill_Tensor> cls_GeomFill_Tensor(mod, "GeomFill_Tensor", "used to store the 'gradient of gradient'");

// Constructors
cls_GeomFill_Tensor.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("NbRow"), py::arg("NbCol"), py::arg("NbMat"));

// Methods
// cls_GeomFill_Tensor.def_static("operator new_", (void * (*)(size_t)) &GeomFill_Tensor::operator new, "None", py::arg("theSize"));
// cls_GeomFill_Tensor.def_static("operator delete_", (void (*)(void *)) &GeomFill_Tensor::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_Tensor.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_Tensor::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_Tensor.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_Tensor::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_Tensor.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_Tensor::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_Tensor.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_Tensor::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_Tensor.def("Init", (void (GeomFill_Tensor::*)(const Standard_Real)) &GeomFill_Tensor::Init, "Initialize all the elements of a Tensor to InitialValue.", py::arg("InitialValue"));
cls_GeomFill_Tensor.def("Value", (const Standard_Real & (GeomFill_Tensor::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer) const) &GeomFill_Tensor::Value, "accesses (in read or write mode) the value of index <Row>, <Col> and <Mat> of a Tensor. An exception is raised if <Row>, <Col> or <Mat> are not in the correct range.", py::arg("Row"), py::arg("Col"), py::arg("Mat"));
cls_GeomFill_Tensor.def("__call__", (const Standard_Real & (GeomFill_Tensor::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer) const) &GeomFill_Tensor::operator(), py::is_operator(), "None", py::arg("Row"), py::arg("Col"), py::arg("Mat"));
cls_GeomFill_Tensor.def("ChangeValue", (Standard_Real & (GeomFill_Tensor::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &GeomFill_Tensor::ChangeValue, "accesses (in read or write mode) the value of index <Row>, <Col> and <Mat> of a Tensor. An exception is raised if <Row>, <Col> or <Mat> are not in the correct range.", py::arg("Row"), py::arg("Col"), py::arg("Mat"));
cls_GeomFill_Tensor.def("__call__", (Standard_Real & (GeomFill_Tensor::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &GeomFill_Tensor::operator(), py::is_operator(), "None", py::arg("Row"), py::arg("Col"), py::arg("Mat"));
cls_GeomFill_Tensor.def("Multiply", (void (GeomFill_Tensor::*)(const math_Vector &, math_Matrix &) const) &GeomFill_Tensor::Multiply, "None", py::arg("Right"), py::arg("Product"));

// CLASS: GEOMFILL_TGTFIELD
py::class_<GeomFill_TgtField, opencascade::handle<GeomFill_TgtField>, Standard_Transient> cls_GeomFill_TgtField(mod, "GeomFill_TgtField", "Root class defining the methods we need to make an algorithmic tangents field.");

// Methods
cls_GeomFill_TgtField.def("IsScalable", (Standard_Boolean (GeomFill_TgtField::*)() const) &GeomFill_TgtField::IsScalable, "None");
cls_GeomFill_TgtField.def("Scale", (void (GeomFill_TgtField::*)(const opencascade::handle<Law_BSpline> &)) &GeomFill_TgtField::Scale, "None", py::arg("Func"));
cls_GeomFill_TgtField.def("Value", (gp_Vec (GeomFill_TgtField::*)(const Standard_Real) const) &GeomFill_TgtField::Value, "Computes the value of the field of tangency at parameter W.", py::arg("W"));
cls_GeomFill_TgtField.def("D1", (gp_Vec (GeomFill_TgtField::*)(const Standard_Real) const) &GeomFill_TgtField::D1, "Computes the derivative of the field of tangency at parameter W.", py::arg("W"));
cls_GeomFill_TgtField.def("D1", (void (GeomFill_TgtField::*)(const Standard_Real, gp_Vec &, gp_Vec &) const) &GeomFill_TgtField::D1, "Computes the value and the derivative of the field of tangency at parameter W.", py::arg("W"), py::arg("V"), py::arg("DV"));
cls_GeomFill_TgtField.def_static("get_type_name_", (const char * (*)()) &GeomFill_TgtField::get_type_name, "None");
cls_GeomFill_TgtField.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_TgtField::get_type_descriptor, "None");
cls_GeomFill_TgtField.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_TgtField::*)() const) &GeomFill_TgtField::DynamicType, "None");

// CLASS: GEOMFILL_TGTONCOONS
py::class_<GeomFill_TgtOnCoons, opencascade::handle<GeomFill_TgtOnCoons>, GeomFill_TgtField> cls_GeomFill_TgtOnCoons(mod, "GeomFill_TgtOnCoons", "Defines an algorithmic tangents field on a boundary of a CoonsAlgPatch.");

// Constructors
cls_GeomFill_TgtOnCoons.def(py::init<const opencascade::handle<GeomFill_CoonsAlgPatch> &, const Standard_Integer>(), py::arg("K"), py::arg("I"));

// Methods
cls_GeomFill_TgtOnCoons.def("Value", (gp_Vec (GeomFill_TgtOnCoons::*)(const Standard_Real) const) &GeomFill_TgtOnCoons::Value, "Computes the value of the field of tangency at parameter W.", py::arg("W"));
cls_GeomFill_TgtOnCoons.def("D1", (gp_Vec (GeomFill_TgtOnCoons::*)(const Standard_Real) const) &GeomFill_TgtOnCoons::D1, "Computes the derivative of the field of tangency at parameter W.", py::arg("W"));
cls_GeomFill_TgtOnCoons.def("D1", (void (GeomFill_TgtOnCoons::*)(const Standard_Real, gp_Vec &, gp_Vec &) const) &GeomFill_TgtOnCoons::D1, "Computes the value and the derivative of the field of tangency at parameter W.", py::arg("W"), py::arg("T"), py::arg("DT"));
cls_GeomFill_TgtOnCoons.def_static("get_type_name_", (const char * (*)()) &GeomFill_TgtOnCoons::get_type_name, "None");
cls_GeomFill_TgtOnCoons.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_TgtOnCoons::get_type_descriptor, "None");
cls_GeomFill_TgtOnCoons.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_TgtOnCoons::*)() const) &GeomFill_TgtOnCoons::DynamicType, "None");

// CLASS: GEOMFILL_UNIFORMSECTION
py::class_<GeomFill_UniformSection, opencascade::handle<GeomFill_UniformSection>, GeomFill_SectionLaw> cls_GeomFill_UniformSection(mod, "GeomFill_UniformSection", "Define an Constant Section Law");

// Constructors
cls_GeomFill_UniformSection.def(py::init<const opencascade::handle<Geom_Curve> &>(), py::arg("C"));
cls_GeomFill_UniformSection.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real>(), py::arg("C"), py::arg("FirstParameter"));
cls_GeomFill_UniformSection.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("FirstParameter"), py::arg("LastParameter"));

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


}
