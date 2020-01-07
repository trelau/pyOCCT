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
#include <StepGeom_TransitionCode.hxx>
#include <StepGeom_BSplineCurveForm.hxx>
#include <StepGeom_BSplineSurfaceForm.hxx>
#include <StepGeom_KnotType.hxx>
#include <StepGeom_PreferredSurfaceCurveRepresentation.hxx>
#include <StepGeom_TrimmingPreference.hxx>
#include <StepRepr_RepresentationItem.hxx>
#include <Standard_Std.hxx>
#include <StepGeom_GeometricRepresentationItem.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepGeom_CartesianPoint.hxx>
#include <StepGeom_Placement.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_Direction.hxx>
#include <StepGeom_Axis2Placement3d.hxx>
#include <StepGeom_Point.hxx>
#include <Standard_Transient.hxx>
#include <StepGeom_Curve.hxx>
#include <StepGeom_CompositeCurveSegment.hxx>
#include <NCollection_Array1.hxx>
#include <StepGeom_Array1OfCompositeCurveSegment.hxx>
#include <Standard.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <StepGeom_HArray1OfCompositeCurveSegment.hxx>
#include <StepGeom_BoundedCurve.hxx>
#include <StepData_Logical.hxx>
#include <StepGeom_CompositeCurve.hxx>
#include <StepGeom_CompositeCurveOnSurface.hxx>
#include <StepGeom_BoundaryCurve.hxx>
#include <StepGeom_Array1OfBoundaryCurve.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <StepGeom_Array1OfCartesianPoint.hxx>
#include <StepGeom_Array1OfCurve.hxx>
#include <StepData_SelectType.hxx>
#include <StepGeom_Pcurve.hxx>
#include <StepGeom_Surface.hxx>
#include <StepGeom_PcurveOrSurface.hxx>
#include <StepGeom_Array1OfPcurveOrSurface.hxx>
#include <StepGeom_DegeneratePcurve.hxx>
#include <StepGeom_SurfaceBoundary.hxx>
#include <StepGeom_Array1OfSurfaceBoundary.hxx>
#include <StepData_SelectMember.hxx>
#include <StepGeom_TrimmingSelect.hxx>
#include <StepGeom_Array1OfTrimmingSelect.hxx>
#include <NCollection_Array2.hxx>
#include <StepGeom_Array2OfCartesianPoint.hxx>
#include <StepGeom_BoundedSurface.hxx>
#include <StepGeom_SurfacePatch.hxx>
#include <StepGeom_Array2OfSurfacePatch.hxx>
#include <StepGeom_Axis1Placement.hxx>
#include <StepGeom_Axis2Placement2d.hxx>
#include <StepGeom_Axis2Placement.hxx>
#include <StepGeom_HArray1OfCartesianPoint.hxx>
#include <StepGeom_BSplineCurve.hxx>
#include <StepGeom_BezierCurve.hxx>
#include <StepGeom_RationalBSplineCurve.hxx>
#include <StepGeom_BezierCurveAndRationalBSplineCurve.hxx>
#include <StepGeom_HArray2OfCartesianPoint.hxx>
#include <StepGeom_BSplineSurface.hxx>
#include <StepGeom_BezierSurface.hxx>
#include <StepGeom_RationalBSplineSurface.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <StepGeom_BezierSurfaceAndRationalBSplineSurface.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <StepGeom_BSplineCurveWithKnots.hxx>
#include <StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.hxx>
#include <StepGeom_BSplineSurfaceWithKnots.hxx>
#include <StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.hxx>
#include <StepGeom_CartesianTransformationOperator.hxx>
#include <StepGeom_CartesianTransformationOperator2d.hxx>
#include <StepGeom_CartesianTransformationOperator3d.hxx>
#include <StepGeom_Conic.hxx>
#include <StepGeom_Circle.hxx>
#include <StepGeom_ElementarySurface.hxx>
#include <StepGeom_ConicalSurface.hxx>
#include <StepGeom_HArray1OfSurfaceBoundary.hxx>
#include <StepGeom_CurveBoundedSurface.hxx>
#include <StepGeom_SurfaceCurve.hxx>
#include <StepGeom_CurveOnSurface.hxx>
#include <StepGeom_CurveReplica.hxx>
#include <StepGeom_CylindricalSurface.hxx>
#include <StepRepr_DefinitionalRepresentation.hxx>
#include <StepGeom_ToroidalSurface.hxx>
#include <StepGeom_DegenerateToroidalSurface.hxx>
#include <StepGeom_Ellipse.hxx>
#include <StepGeom_EvaluatedDegeneratePcurve.hxx>
#include <StepRepr_RepresentationContext.hxx>
#include <StepGeom_GeometricRepresentationContext.hxx>
#include <StepRepr_GlobalUnitAssignedContext.hxx>
#include <StepBasic_HArray1OfNamedUnit.hxx>
#include <StepBasic_NamedUnit.hxx>
#include <StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.hxx>
#include <StepRepr_ParametricRepresentationContext.hxx>
#include <StepGeom_GeometricRepresentationContextAndParametricRepresentationContext.hxx>
#include <StepRepr_GlobalUncertaintyAssignedContext.hxx>
#include <StepBasic_HArray1OfUncertaintyMeasureWithUnit.hxx>
#include <StepBasic_UncertaintyMeasureWithUnit.hxx>
#include <StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.hxx>
#include <StepGeom_HArray1OfBoundaryCurve.hxx>
#include <StepGeom_HArray1OfCurve.hxx>
#include <StepGeom_HArray1OfPcurveOrSurface.hxx>
#include <StepGeom_HArray1OfTrimmingSelect.hxx>
#include <StepGeom_HArray2OfSurfacePatch.hxx>
#include <StepGeom_Hyperbola.hxx>
#include <StepGeom_IntersectionCurve.hxx>
#include <StepGeom_Vector.hxx>
#include <StepGeom_Line.hxx>
#include <StepGeom_OffsetCurve3d.hxx>
#include <StepGeom_OffsetSurface.hxx>
#include <StepGeom_OrientedSurface.hxx>
#include <StepGeom_OuterBoundaryCurve.hxx>
#include <StepGeom_Parabola.hxx>
#include <StepGeom_Plane.hxx>
#include <StepGeom_PointOnCurve.hxx>
#include <StepGeom_PointOnSurface.hxx>
#include <StepGeom_PointReplica.hxx>
#include <StepGeom_Polyline.hxx>
#include <StepGeom_QuasiUniformCurve.hxx>
#include <StepGeom_QuasiUniformCurveAndRationalBSplineCurve.hxx>
#include <StepGeom_QuasiUniformSurface.hxx>
#include <StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.hxx>
#include <StepGeom_RectangularCompositeSurface.hxx>
#include <StepGeom_RectangularTrimmedSurface.hxx>
#include <StepGeom_ReparametrisedCompositeCurveSegment.hxx>
#include <StepGeom_SeamCurve.hxx>
#include <StepGeom_SphericalSurface.hxx>
#include <StepGeom_SurfaceCurveAndBoundedCurve.hxx>
#include <StepGeom_SweptSurface.hxx>
#include <StepGeom_SurfaceOfLinearExtrusion.hxx>
#include <StepGeom_SurfaceOfRevolution.hxx>
#include <StepGeom_SurfaceReplica.hxx>
#include <StepGeom_TrimmedCurve.hxx>
#include <StepData_SelectReal.hxx>
#include <StepGeom_TrimmingMember.hxx>
#include <StepGeom_UniformCurve.hxx>
#include <StepGeom_UniformCurveAndRationalBSplineCurve.hxx>
#include <StepGeom_UniformSurface.hxx>
#include <StepGeom_UniformSurfaceAndRationalBSplineSurface.hxx>
#include <StepGeom_VectorOrDirection.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_Define_HArray1.hxx>
#include <bind_NCollection_Array2.hxx>
#include <bind_Define_HArray2.hxx>

PYBIND11_MODULE(StepGeom, mod) {

py::module::import("OCCT.StepRepr");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.StepData");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.StepBasic");

// ENUM: STEPGEOM_TRANSITIONCODE
py::enum_<StepGeom_TransitionCode>(mod, "StepGeom_TransitionCode", "None")
	.value("StepGeom_tcDiscontinuous", StepGeom_TransitionCode::StepGeom_tcDiscontinuous)
	.value("StepGeom_tcContinuous", StepGeom_TransitionCode::StepGeom_tcContinuous)
	.value("StepGeom_tcContSameGradient", StepGeom_TransitionCode::StepGeom_tcContSameGradient)
	.value("StepGeom_tcContSameGradientSameCurvature", StepGeom_TransitionCode::StepGeom_tcContSameGradientSameCurvature)
	.export_values();


// ENUM: STEPGEOM_BSPLINECURVEFORM
py::enum_<StepGeom_BSplineCurveForm>(mod, "StepGeom_BSplineCurveForm", "None")
	.value("StepGeom_bscfPolylineForm", StepGeom_BSplineCurveForm::StepGeom_bscfPolylineForm)
	.value("StepGeom_bscfCircularArc", StepGeom_BSplineCurveForm::StepGeom_bscfCircularArc)
	.value("StepGeom_bscfEllipticArc", StepGeom_BSplineCurveForm::StepGeom_bscfEllipticArc)
	.value("StepGeom_bscfParabolicArc", StepGeom_BSplineCurveForm::StepGeom_bscfParabolicArc)
	.value("StepGeom_bscfHyperbolicArc", StepGeom_BSplineCurveForm::StepGeom_bscfHyperbolicArc)
	.value("StepGeom_bscfUnspecified", StepGeom_BSplineCurveForm::StepGeom_bscfUnspecified)
	.export_values();


// ENUM: STEPGEOM_BSPLINESURFACEFORM
py::enum_<StepGeom_BSplineSurfaceForm>(mod, "StepGeom_BSplineSurfaceForm", "None")
	.value("StepGeom_bssfPlaneSurf", StepGeom_BSplineSurfaceForm::StepGeom_bssfPlaneSurf)
	.value("StepGeom_bssfCylindricalSurf", StepGeom_BSplineSurfaceForm::StepGeom_bssfCylindricalSurf)
	.value("StepGeom_bssfConicalSurf", StepGeom_BSplineSurfaceForm::StepGeom_bssfConicalSurf)
	.value("StepGeom_bssfSphericalSurf", StepGeom_BSplineSurfaceForm::StepGeom_bssfSphericalSurf)
	.value("StepGeom_bssfToroidalSurf", StepGeom_BSplineSurfaceForm::StepGeom_bssfToroidalSurf)
	.value("StepGeom_bssfSurfOfRevolution", StepGeom_BSplineSurfaceForm::StepGeom_bssfSurfOfRevolution)
	.value("StepGeom_bssfRuledSurf", StepGeom_BSplineSurfaceForm::StepGeom_bssfRuledSurf)
	.value("StepGeom_bssfGeneralisedCone", StepGeom_BSplineSurfaceForm::StepGeom_bssfGeneralisedCone)
	.value("StepGeom_bssfQuadricSurf", StepGeom_BSplineSurfaceForm::StepGeom_bssfQuadricSurf)
	.value("StepGeom_bssfSurfOfLinearExtrusion", StepGeom_BSplineSurfaceForm::StepGeom_bssfSurfOfLinearExtrusion)
	.value("StepGeom_bssfUnspecified", StepGeom_BSplineSurfaceForm::StepGeom_bssfUnspecified)
	.export_values();


// ENUM: STEPGEOM_KNOTTYPE
py::enum_<StepGeom_KnotType>(mod, "StepGeom_KnotType", "None")
	.value("StepGeom_ktUniformKnots", StepGeom_KnotType::StepGeom_ktUniformKnots)
	.value("StepGeom_ktUnspecified", StepGeom_KnotType::StepGeom_ktUnspecified)
	.value("StepGeom_ktQuasiUniformKnots", StepGeom_KnotType::StepGeom_ktQuasiUniformKnots)
	.value("StepGeom_ktPiecewiseBezierKnots", StepGeom_KnotType::StepGeom_ktPiecewiseBezierKnots)
	.export_values();


// ENUM: STEPGEOM_PREFERREDSURFACECURVEREPRESENTATION
py::enum_<StepGeom_PreferredSurfaceCurveRepresentation>(mod, "StepGeom_PreferredSurfaceCurveRepresentation", "None")
	.value("StepGeom_pscrCurve3d", StepGeom_PreferredSurfaceCurveRepresentation::StepGeom_pscrCurve3d)
	.value("StepGeom_pscrPcurveS1", StepGeom_PreferredSurfaceCurveRepresentation::StepGeom_pscrPcurveS1)
	.value("StepGeom_pscrPcurveS2", StepGeom_PreferredSurfaceCurveRepresentation::StepGeom_pscrPcurveS2)
	.export_values();


// ENUM: STEPGEOM_TRIMMINGPREFERENCE
py::enum_<StepGeom_TrimmingPreference>(mod, "StepGeom_TrimmingPreference", "None")
	.value("StepGeom_tpCartesian", StepGeom_TrimmingPreference::StepGeom_tpCartesian)
	.value("StepGeom_tpParameter", StepGeom_TrimmingPreference::StepGeom_tpParameter)
	.value("StepGeom_tpUnspecified", StepGeom_TrimmingPreference::StepGeom_tpUnspecified)
	.export_values();


// CLASS: STEPGEOM_GEOMETRICREPRESENTATIONITEM
py::class_<StepGeom_GeometricRepresentationItem, opencascade::handle<StepGeom_GeometricRepresentationItem>, StepRepr_RepresentationItem> cls_StepGeom_GeometricRepresentationItem(mod, "StepGeom_GeometricRepresentationItem", "None");

// Constructors
cls_StepGeom_GeometricRepresentationItem.def(py::init<>());

// Methods
cls_StepGeom_GeometricRepresentationItem.def_static("get_type_name_", (const char * (*)()) &StepGeom_GeometricRepresentationItem::get_type_name, "None");
cls_StepGeom_GeometricRepresentationItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_GeometricRepresentationItem::get_type_descriptor, "None");
cls_StepGeom_GeometricRepresentationItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_GeometricRepresentationItem::*)() const) &StepGeom_GeometricRepresentationItem::DynamicType, "None");

// CLASS: STEPGEOM_PLACEMENT
py::class_<StepGeom_Placement, opencascade::handle<StepGeom_Placement>, StepGeom_GeometricRepresentationItem> cls_StepGeom_Placement(mod, "StepGeom_Placement", "None");

// Constructors
cls_StepGeom_Placement.def(py::init<>());

// Methods
cls_StepGeom_Placement.def("Init", (void (StepGeom_Placement::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_CartesianPoint> &)) &StepGeom_Placement::Init, "None", py::arg("aName"), py::arg("aLocation"));
cls_StepGeom_Placement.def("SetLocation", (void (StepGeom_Placement::*)(const opencascade::handle<StepGeom_CartesianPoint> &)) &StepGeom_Placement::SetLocation, "None", py::arg("aLocation"));
cls_StepGeom_Placement.def("Location", (opencascade::handle<StepGeom_CartesianPoint> (StepGeom_Placement::*)() const) &StepGeom_Placement::Location, "None");
cls_StepGeom_Placement.def_static("get_type_name_", (const char * (*)()) &StepGeom_Placement::get_type_name, "None");
cls_StepGeom_Placement.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Placement::get_type_descriptor, "None");
cls_StepGeom_Placement.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Placement::*)() const) &StepGeom_Placement::DynamicType, "None");

// CLASS: STEPGEOM_AXIS2PLACEMENT3D
py::class_<StepGeom_Axis2Placement3d, opencascade::handle<StepGeom_Axis2Placement3d>, StepGeom_Placement> cls_StepGeom_Axis2Placement3d(mod, "StepGeom_Axis2Placement3d", "None");

// Constructors
cls_StepGeom_Axis2Placement3d.def(py::init<>());

// Methods
cls_StepGeom_Axis2Placement3d.def("Init", (void (StepGeom_Axis2Placement3d::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_CartesianPoint> &, const Standard_Boolean, const opencascade::handle<StepGeom_Direction> &, const Standard_Boolean, const opencascade::handle<StepGeom_Direction> &)) &StepGeom_Axis2Placement3d::Init, "None", py::arg("aName"), py::arg("aLocation"), py::arg("hasAaxis"), py::arg("aAxis"), py::arg("hasArefDirection"), py::arg("aRefDirection"));
cls_StepGeom_Axis2Placement3d.def("SetAxis", (void (StepGeom_Axis2Placement3d::*)(const opencascade::handle<StepGeom_Direction> &)) &StepGeom_Axis2Placement3d::SetAxis, "None", py::arg("aAxis"));
cls_StepGeom_Axis2Placement3d.def("UnSetAxis", (void (StepGeom_Axis2Placement3d::*)()) &StepGeom_Axis2Placement3d::UnSetAxis, "None");
cls_StepGeom_Axis2Placement3d.def("Axis", (opencascade::handle<StepGeom_Direction> (StepGeom_Axis2Placement3d::*)() const) &StepGeom_Axis2Placement3d::Axis, "None");
cls_StepGeom_Axis2Placement3d.def("HasAxis", (Standard_Boolean (StepGeom_Axis2Placement3d::*)() const) &StepGeom_Axis2Placement3d::HasAxis, "None");
cls_StepGeom_Axis2Placement3d.def("SetRefDirection", (void (StepGeom_Axis2Placement3d::*)(const opencascade::handle<StepGeom_Direction> &)) &StepGeom_Axis2Placement3d::SetRefDirection, "None", py::arg("aRefDirection"));
cls_StepGeom_Axis2Placement3d.def("UnSetRefDirection", (void (StepGeom_Axis2Placement3d::*)()) &StepGeom_Axis2Placement3d::UnSetRefDirection, "None");
cls_StepGeom_Axis2Placement3d.def("RefDirection", (opencascade::handle<StepGeom_Direction> (StepGeom_Axis2Placement3d::*)() const) &StepGeom_Axis2Placement3d::RefDirection, "None");
cls_StepGeom_Axis2Placement3d.def("HasRefDirection", (Standard_Boolean (StepGeom_Axis2Placement3d::*)() const) &StepGeom_Axis2Placement3d::HasRefDirection, "None");
cls_StepGeom_Axis2Placement3d.def_static("get_type_name_", (const char * (*)()) &StepGeom_Axis2Placement3d::get_type_name, "None");
cls_StepGeom_Axis2Placement3d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Axis2Placement3d::get_type_descriptor, "None");
cls_StepGeom_Axis2Placement3d.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Axis2Placement3d::*)() const) &StepGeom_Axis2Placement3d::DynamicType, "None");

// CLASS: STEPGEOM_POINT
py::class_<StepGeom_Point, opencascade::handle<StepGeom_Point>, StepGeom_GeometricRepresentationItem> cls_StepGeom_Point(mod, "StepGeom_Point", "None");

// Constructors
cls_StepGeom_Point.def(py::init<>());

// Methods
cls_StepGeom_Point.def_static("get_type_name_", (const char * (*)()) &StepGeom_Point::get_type_name, "None");
cls_StepGeom_Point.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Point::get_type_descriptor, "None");
cls_StepGeom_Point.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Point::*)() const) &StepGeom_Point::DynamicType, "None");

// CLASS: STEPGEOM_COMPOSITECURVESEGMENT
py::class_<StepGeom_CompositeCurveSegment, opencascade::handle<StepGeom_CompositeCurveSegment>, Standard_Transient> cls_StepGeom_CompositeCurveSegment(mod, "StepGeom_CompositeCurveSegment", "None");

// Constructors
cls_StepGeom_CompositeCurveSegment.def(py::init<>());

// Methods
cls_StepGeom_CompositeCurveSegment.def("Init", (void (StepGeom_CompositeCurveSegment::*)(const StepGeom_TransitionCode, const Standard_Boolean, const opencascade::handle<StepGeom_Curve> &)) &StepGeom_CompositeCurveSegment::Init, "None", py::arg("aTransition"), py::arg("aSameSense"), py::arg("aParentCurve"));
cls_StepGeom_CompositeCurveSegment.def("SetTransition", (void (StepGeom_CompositeCurveSegment::*)(const StepGeom_TransitionCode)) &StepGeom_CompositeCurveSegment::SetTransition, "None", py::arg("aTransition"));
cls_StepGeom_CompositeCurveSegment.def("Transition", (StepGeom_TransitionCode (StepGeom_CompositeCurveSegment::*)() const) &StepGeom_CompositeCurveSegment::Transition, "None");
cls_StepGeom_CompositeCurveSegment.def("SetSameSense", (void (StepGeom_CompositeCurveSegment::*)(const Standard_Boolean)) &StepGeom_CompositeCurveSegment::SetSameSense, "None", py::arg("aSameSense"));
cls_StepGeom_CompositeCurveSegment.def("SameSense", (Standard_Boolean (StepGeom_CompositeCurveSegment::*)() const) &StepGeom_CompositeCurveSegment::SameSense, "None");
cls_StepGeom_CompositeCurveSegment.def("SetParentCurve", (void (StepGeom_CompositeCurveSegment::*)(const opencascade::handle<StepGeom_Curve> &)) &StepGeom_CompositeCurveSegment::SetParentCurve, "None", py::arg("aParentCurve"));
cls_StepGeom_CompositeCurveSegment.def("ParentCurve", (opencascade::handle<StepGeom_Curve> (StepGeom_CompositeCurveSegment::*)() const) &StepGeom_CompositeCurveSegment::ParentCurve, "None");
cls_StepGeom_CompositeCurveSegment.def_static("get_type_name_", (const char * (*)()) &StepGeom_CompositeCurveSegment::get_type_name, "None");
cls_StepGeom_CompositeCurveSegment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_CompositeCurveSegment::get_type_descriptor, "None");
cls_StepGeom_CompositeCurveSegment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_CompositeCurveSegment::*)() const) &StepGeom_CompositeCurveSegment::DynamicType, "None");

// TYPEDEF: STEPGEOM_ARRAY1OFCOMPOSITECURVESEGMENT
bind_NCollection_Array1<opencascade::handle<StepGeom_CompositeCurveSegment> >(mod, "StepGeom_Array1OfCompositeCurveSegment", py::module_local(false));

// CLASS: STEPGEOM_HARRAY1OFCOMPOSITECURVESEGMENT
bind_Define_HArray1<StepGeom_HArray1OfCompositeCurveSegment, StepGeom_Array1OfCompositeCurveSegment>(mod, "StepGeom_HArray1OfCompositeCurveSegment");

// CLASS: STEPGEOM_CURVE
py::class_<StepGeom_Curve, opencascade::handle<StepGeom_Curve>, StepGeom_GeometricRepresentationItem> cls_StepGeom_Curve(mod, "StepGeom_Curve", "None");

// Constructors
cls_StepGeom_Curve.def(py::init<>());

// Methods
cls_StepGeom_Curve.def_static("get_type_name_", (const char * (*)()) &StepGeom_Curve::get_type_name, "None");
cls_StepGeom_Curve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Curve::get_type_descriptor, "None");
cls_StepGeom_Curve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Curve::*)() const) &StepGeom_Curve::DynamicType, "None");

// CLASS: STEPGEOM_BOUNDEDCURVE
py::class_<StepGeom_BoundedCurve, opencascade::handle<StepGeom_BoundedCurve>, StepGeom_Curve> cls_StepGeom_BoundedCurve(mod, "StepGeom_BoundedCurve", "None");

// Constructors
cls_StepGeom_BoundedCurve.def(py::init<>());

// Methods
cls_StepGeom_BoundedCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_BoundedCurve::get_type_name, "None");
cls_StepGeom_BoundedCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_BoundedCurve::get_type_descriptor, "None");
cls_StepGeom_BoundedCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_BoundedCurve::*)() const) &StepGeom_BoundedCurve::DynamicType, "None");

// CLASS: STEPGEOM_COMPOSITECURVE
py::class_<StepGeom_CompositeCurve, opencascade::handle<StepGeom_CompositeCurve>, StepGeom_BoundedCurve> cls_StepGeom_CompositeCurve(mod, "StepGeom_CompositeCurve", "None");

// Constructors
cls_StepGeom_CompositeCurve.def(py::init<>());

// Methods
cls_StepGeom_CompositeCurve.def("Init", (void (StepGeom_CompositeCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_HArray1OfCompositeCurveSegment> &, const StepData_Logical)) &StepGeom_CompositeCurve::Init, "None", py::arg("aName"), py::arg("aSegments"), py::arg("aSelfIntersect"));
cls_StepGeom_CompositeCurve.def("SetSegments", (void (StepGeom_CompositeCurve::*)(const opencascade::handle<StepGeom_HArray1OfCompositeCurveSegment> &)) &StepGeom_CompositeCurve::SetSegments, "None", py::arg("aSegments"));
cls_StepGeom_CompositeCurve.def("Segments", (opencascade::handle<StepGeom_HArray1OfCompositeCurveSegment> (StepGeom_CompositeCurve::*)() const) &StepGeom_CompositeCurve::Segments, "None");
cls_StepGeom_CompositeCurve.def("SegmentsValue", (opencascade::handle<StepGeom_CompositeCurveSegment> (StepGeom_CompositeCurve::*)(const Standard_Integer) const) &StepGeom_CompositeCurve::SegmentsValue, "None", py::arg("num"));
cls_StepGeom_CompositeCurve.def("NbSegments", (Standard_Integer (StepGeom_CompositeCurve::*)() const) &StepGeom_CompositeCurve::NbSegments, "None");
cls_StepGeom_CompositeCurve.def("SetSelfIntersect", (void (StepGeom_CompositeCurve::*)(const StepData_Logical)) &StepGeom_CompositeCurve::SetSelfIntersect, "None", py::arg("aSelfIntersect"));
cls_StepGeom_CompositeCurve.def("SelfIntersect", (StepData_Logical (StepGeom_CompositeCurve::*)() const) &StepGeom_CompositeCurve::SelfIntersect, "None");
cls_StepGeom_CompositeCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_CompositeCurve::get_type_name, "None");
cls_StepGeom_CompositeCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_CompositeCurve::get_type_descriptor, "None");
cls_StepGeom_CompositeCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_CompositeCurve::*)() const) &StepGeom_CompositeCurve::DynamicType, "None");

// CLASS: STEPGEOM_COMPOSITECURVEONSURFACE
py::class_<StepGeom_CompositeCurveOnSurface, opencascade::handle<StepGeom_CompositeCurveOnSurface>, StepGeom_CompositeCurve> cls_StepGeom_CompositeCurveOnSurface(mod, "StepGeom_CompositeCurveOnSurface", "None");

// Constructors
cls_StepGeom_CompositeCurveOnSurface.def(py::init<>());

// Methods
cls_StepGeom_CompositeCurveOnSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_CompositeCurveOnSurface::get_type_name, "None");
cls_StepGeom_CompositeCurveOnSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_CompositeCurveOnSurface::get_type_descriptor, "None");
cls_StepGeom_CompositeCurveOnSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_CompositeCurveOnSurface::*)() const) &StepGeom_CompositeCurveOnSurface::DynamicType, "None");

// CLASS: STEPGEOM_BOUNDARYCURVE
py::class_<StepGeom_BoundaryCurve, opencascade::handle<StepGeom_BoundaryCurve>, StepGeom_CompositeCurveOnSurface> cls_StepGeom_BoundaryCurve(mod, "StepGeom_BoundaryCurve", "None");

// Constructors
cls_StepGeom_BoundaryCurve.def(py::init<>());

// Methods
cls_StepGeom_BoundaryCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_BoundaryCurve::get_type_name, "None");
cls_StepGeom_BoundaryCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_BoundaryCurve::get_type_descriptor, "None");
cls_StepGeom_BoundaryCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_BoundaryCurve::*)() const) &StepGeom_BoundaryCurve::DynamicType, "None");

// TYPEDEF: STEPGEOM_ARRAY1OFBOUNDARYCURVE
bind_NCollection_Array1<opencascade::handle<StepGeom_BoundaryCurve> >(mod, "StepGeom_Array1OfBoundaryCurve", py::module_local(false));

// CLASS: STEPGEOM_CARTESIANPOINT
py::class_<StepGeom_CartesianPoint, opencascade::handle<StepGeom_CartesianPoint>, StepGeom_Point> cls_StepGeom_CartesianPoint(mod, "StepGeom_CartesianPoint", "None");

// Constructors
cls_StepGeom_CartesianPoint.def(py::init<>());

// Methods
cls_StepGeom_CartesianPoint.def("Init", (void (StepGeom_CartesianPoint::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_CartesianPoint::Init, "None", py::arg("aName"), py::arg("aCoordinates"));
cls_StepGeom_CartesianPoint.def("Init2D", (void (StepGeom_CartesianPoint::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const Standard_Real)) &StepGeom_CartesianPoint::Init2D, "None", py::arg("aName"), py::arg("X"), py::arg("Y"));
cls_StepGeom_CartesianPoint.def("Init3D", (void (StepGeom_CartesianPoint::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const Standard_Real, const Standard_Real)) &StepGeom_CartesianPoint::Init3D, "None", py::arg("aName"), py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_StepGeom_CartesianPoint.def("SetCoordinates", (void (StepGeom_CartesianPoint::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_CartesianPoint::SetCoordinates, "None", py::arg("aCoordinates"));
cls_StepGeom_CartesianPoint.def("Coordinates", (opencascade::handle<TColStd_HArray1OfReal> (StepGeom_CartesianPoint::*)() const) &StepGeom_CartesianPoint::Coordinates, "None");
cls_StepGeom_CartesianPoint.def("CoordinatesValue", (Standard_Real (StepGeom_CartesianPoint::*)(const Standard_Integer) const) &StepGeom_CartesianPoint::CoordinatesValue, "None", py::arg("num"));
cls_StepGeom_CartesianPoint.def("NbCoordinates", (Standard_Integer (StepGeom_CartesianPoint::*)() const) &StepGeom_CartesianPoint::NbCoordinates, "None");
cls_StepGeom_CartesianPoint.def_static("get_type_name_", (const char * (*)()) &StepGeom_CartesianPoint::get_type_name, "None");
cls_StepGeom_CartesianPoint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_CartesianPoint::get_type_descriptor, "None");
cls_StepGeom_CartesianPoint.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_CartesianPoint::*)() const) &StepGeom_CartesianPoint::DynamicType, "None");

// TYPEDEF: STEPGEOM_ARRAY1OFCARTESIANPOINT
bind_NCollection_Array1<opencascade::handle<StepGeom_CartesianPoint> >(mod, "StepGeom_Array1OfCartesianPoint", py::module_local(false));

// TYPEDEF: STEPGEOM_ARRAY1OFCURVE
bind_NCollection_Array1<opencascade::handle<StepGeom_Curve> >(mod, "StepGeom_Array1OfCurve", py::module_local(false));

// CLASS: STEPGEOM_PCURVEORSURFACE
py::class_<StepGeom_PcurveOrSurface, StepData_SelectType> cls_StepGeom_PcurveOrSurface(mod, "StepGeom_PcurveOrSurface", "None");

// Constructors
cls_StepGeom_PcurveOrSurface.def(py::init<>());

// Methods
// cls_StepGeom_PcurveOrSurface.def_static("operator new_", (void * (*)(size_t)) &StepGeom_PcurveOrSurface::operator new, "None", py::arg("theSize"));
// cls_StepGeom_PcurveOrSurface.def_static("operator delete_", (void (*)(void *)) &StepGeom_PcurveOrSurface::operator delete, "None", py::arg("theAddress"));
// cls_StepGeom_PcurveOrSurface.def_static("operator new[]_", (void * (*)(size_t)) &StepGeom_PcurveOrSurface::operator new[], "None", py::arg("theSize"));
// cls_StepGeom_PcurveOrSurface.def_static("operator delete[]_", (void (*)(void *)) &StepGeom_PcurveOrSurface::operator delete[], "None", py::arg("theAddress"));
// cls_StepGeom_PcurveOrSurface.def_static("operator new_", (void * (*)(size_t, void *)) &StepGeom_PcurveOrSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepGeom_PcurveOrSurface.def_static("operator delete_", (void (*)(void *, void *)) &StepGeom_PcurveOrSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_StepGeom_PcurveOrSurface.def("CaseNum", (Standard_Integer (StepGeom_PcurveOrSurface::*)(const opencascade::handle<Standard_Transient> &) const) &StepGeom_PcurveOrSurface::CaseNum, "Recognizes a PcurveOrSurface Kind Entity that is : 1 -> Pcurve 2 -> Surface 0 else", py::arg("ent"));
cls_StepGeom_PcurveOrSurface.def("Pcurve", (opencascade::handle<StepGeom_Pcurve> (StepGeom_PcurveOrSurface::*)() const) &StepGeom_PcurveOrSurface::Pcurve, "returns Value as a Pcurve (Null if another type)");
cls_StepGeom_PcurveOrSurface.def("Surface", (opencascade::handle<StepGeom_Surface> (StepGeom_PcurveOrSurface::*)() const) &StepGeom_PcurveOrSurface::Surface, "returns Value as a Surface (Null if another type)");

// TYPEDEF: STEPGEOM_ARRAY1OFPCURVEORSURFACE
bind_NCollection_Array1<StepGeom_PcurveOrSurface>(mod, "StepGeom_Array1OfPcurveOrSurface", py::module_local(false));

// CLASS: STEPGEOM_SURFACEBOUNDARY
py::class_<StepGeom_SurfaceBoundary, StepData_SelectType> cls_StepGeom_SurfaceBoundary(mod, "StepGeom_SurfaceBoundary", "Representation of STEP SELECT type SurfaceBoundary");

// Constructors
cls_StepGeom_SurfaceBoundary.def(py::init<>());

// Methods
// cls_StepGeom_SurfaceBoundary.def_static("operator new_", (void * (*)(size_t)) &StepGeom_SurfaceBoundary::operator new, "None", py::arg("theSize"));
// cls_StepGeom_SurfaceBoundary.def_static("operator delete_", (void (*)(void *)) &StepGeom_SurfaceBoundary::operator delete, "None", py::arg("theAddress"));
// cls_StepGeom_SurfaceBoundary.def_static("operator new[]_", (void * (*)(size_t)) &StepGeom_SurfaceBoundary::operator new[], "None", py::arg("theSize"));
// cls_StepGeom_SurfaceBoundary.def_static("operator delete[]_", (void (*)(void *)) &StepGeom_SurfaceBoundary::operator delete[], "None", py::arg("theAddress"));
// cls_StepGeom_SurfaceBoundary.def_static("operator new_", (void * (*)(size_t, void *)) &StepGeom_SurfaceBoundary::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepGeom_SurfaceBoundary.def_static("operator delete_", (void (*)(void *, void *)) &StepGeom_SurfaceBoundary::operator delete, "None", py::arg(""), py::arg(""));
cls_StepGeom_SurfaceBoundary.def("CaseNum", (Standard_Integer (StepGeom_SurfaceBoundary::*)(const opencascade::handle<Standard_Transient> &) const) &StepGeom_SurfaceBoundary::CaseNum, "Recognizes a kind of SurfaceBoundary select type 1 -> BoundaryCurve from StepGeom 2 -> DegeneratePcurve from StepGeom 0 else", py::arg("ent"));
cls_StepGeom_SurfaceBoundary.def("BoundaryCurve", (opencascade::handle<StepGeom_BoundaryCurve> (StepGeom_SurfaceBoundary::*)() const) &StepGeom_SurfaceBoundary::BoundaryCurve, "Returns Value as BoundaryCurve (or Null if another type)");
cls_StepGeom_SurfaceBoundary.def("DegeneratePcurve", (opencascade::handle<StepGeom_DegeneratePcurve> (StepGeom_SurfaceBoundary::*)() const) &StepGeom_SurfaceBoundary::DegeneratePcurve, "Returns Value as DegeneratePcurve (or Null if another type)");

// TYPEDEF: STEPGEOM_ARRAY1OFSURFACEBOUNDARY
bind_NCollection_Array1<StepGeom_SurfaceBoundary>(mod, "StepGeom_Array1OfSurfaceBoundary", py::module_local(false));

// CLASS: STEPGEOM_TRIMMINGSELECT
py::class_<StepGeom_TrimmingSelect, StepData_SelectType> cls_StepGeom_TrimmingSelect(mod, "StepGeom_TrimmingSelect", "None");

// Constructors
cls_StepGeom_TrimmingSelect.def(py::init<>());

// Methods
// cls_StepGeom_TrimmingSelect.def_static("operator new_", (void * (*)(size_t)) &StepGeom_TrimmingSelect::operator new, "None", py::arg("theSize"));
// cls_StepGeom_TrimmingSelect.def_static("operator delete_", (void (*)(void *)) &StepGeom_TrimmingSelect::operator delete, "None", py::arg("theAddress"));
// cls_StepGeom_TrimmingSelect.def_static("operator new[]_", (void * (*)(size_t)) &StepGeom_TrimmingSelect::operator new[], "None", py::arg("theSize"));
// cls_StepGeom_TrimmingSelect.def_static("operator delete[]_", (void (*)(void *)) &StepGeom_TrimmingSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StepGeom_TrimmingSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StepGeom_TrimmingSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepGeom_TrimmingSelect.def_static("operator delete_", (void (*)(void *, void *)) &StepGeom_TrimmingSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_StepGeom_TrimmingSelect.def("CaseNum", (Standard_Integer (StepGeom_TrimmingSelect::*)(const opencascade::handle<Standard_Transient> &) const) &StepGeom_TrimmingSelect::CaseNum, "Recognizes a TrimmingSelect Kind Entity that is : 1 -> CartesianPoint 0 else (i.e. Real)", py::arg("ent"));
cls_StepGeom_TrimmingSelect.def("NewMember", (opencascade::handle<StepData_SelectMember> (StepGeom_TrimmingSelect::*)() const) &StepGeom_TrimmingSelect::NewMember, "Returns a TrimmingMember (for PARAMETER_VALUE) as preferred");
cls_StepGeom_TrimmingSelect.def("CaseMem", (Standard_Integer (StepGeom_TrimmingSelect::*)(const opencascade::handle<StepData_SelectMember> &) const) &StepGeom_TrimmingSelect::CaseMem, "Recognizes a SelectMember as Real, named as PARAMETER_VALUE 1 -> ParameterValue i.e. Real 0 else (i.e. Entity)", py::arg("ent"));
cls_StepGeom_TrimmingSelect.def("CartesianPoint", (opencascade::handle<StepGeom_CartesianPoint> (StepGeom_TrimmingSelect::*)() const) &StepGeom_TrimmingSelect::CartesianPoint, "returns Value as a CartesianPoint (Null if another type)");
cls_StepGeom_TrimmingSelect.def("SetParameterValue", (void (StepGeom_TrimmingSelect::*)(const Standard_Real)) &StepGeom_TrimmingSelect::SetParameterValue, "sets the ParameterValue as Real", py::arg("aParameterValue"));
cls_StepGeom_TrimmingSelect.def("ParameterValue", (Standard_Real (StepGeom_TrimmingSelect::*)() const) &StepGeom_TrimmingSelect::ParameterValue, "returns Value as a Real (0.0 if not a Real)");

// TYPEDEF: STEPGEOM_ARRAY1OFTRIMMINGSELECT
bind_NCollection_Array1<StepGeom_TrimmingSelect>(mod, "StepGeom_Array1OfTrimmingSelect", py::module_local(false));

// TYPEDEF: STEPGEOM_ARRAY2OFCARTESIANPOINT
bind_NCollection_Array2<opencascade::handle<StepGeom_CartesianPoint> >(mod, "StepGeom_Array2OfCartesianPoint", py::module_local(false));

// CLASS: STEPGEOM_SURFACEPATCH
py::class_<StepGeom_SurfacePatch, opencascade::handle<StepGeom_SurfacePatch>, Standard_Transient> cls_StepGeom_SurfacePatch(mod, "StepGeom_SurfacePatch", "None");

// Constructors
cls_StepGeom_SurfacePatch.def(py::init<>());

// Methods
cls_StepGeom_SurfacePatch.def("Init", (void (StepGeom_SurfacePatch::*)(const opencascade::handle<StepGeom_BoundedSurface> &, const StepGeom_TransitionCode, const StepGeom_TransitionCode, const Standard_Boolean, const Standard_Boolean)) &StepGeom_SurfacePatch::Init, "None", py::arg("aParentSurface"), py::arg("aUTransition"), py::arg("aVTransition"), py::arg("aUSense"), py::arg("aVSense"));
cls_StepGeom_SurfacePatch.def("SetParentSurface", (void (StepGeom_SurfacePatch::*)(const opencascade::handle<StepGeom_BoundedSurface> &)) &StepGeom_SurfacePatch::SetParentSurface, "None", py::arg("aParentSurface"));
cls_StepGeom_SurfacePatch.def("ParentSurface", (opencascade::handle<StepGeom_BoundedSurface> (StepGeom_SurfacePatch::*)() const) &StepGeom_SurfacePatch::ParentSurface, "None");
cls_StepGeom_SurfacePatch.def("SetUTransition", (void (StepGeom_SurfacePatch::*)(const StepGeom_TransitionCode)) &StepGeom_SurfacePatch::SetUTransition, "None", py::arg("aUTransition"));
cls_StepGeom_SurfacePatch.def("UTransition", (StepGeom_TransitionCode (StepGeom_SurfacePatch::*)() const) &StepGeom_SurfacePatch::UTransition, "None");
cls_StepGeom_SurfacePatch.def("SetVTransition", (void (StepGeom_SurfacePatch::*)(const StepGeom_TransitionCode)) &StepGeom_SurfacePatch::SetVTransition, "None", py::arg("aVTransition"));
cls_StepGeom_SurfacePatch.def("VTransition", (StepGeom_TransitionCode (StepGeom_SurfacePatch::*)() const) &StepGeom_SurfacePatch::VTransition, "None");
cls_StepGeom_SurfacePatch.def("SetUSense", (void (StepGeom_SurfacePatch::*)(const Standard_Boolean)) &StepGeom_SurfacePatch::SetUSense, "None", py::arg("aUSense"));
cls_StepGeom_SurfacePatch.def("USense", (Standard_Boolean (StepGeom_SurfacePatch::*)() const) &StepGeom_SurfacePatch::USense, "None");
cls_StepGeom_SurfacePatch.def("SetVSense", (void (StepGeom_SurfacePatch::*)(const Standard_Boolean)) &StepGeom_SurfacePatch::SetVSense, "None", py::arg("aVSense"));
cls_StepGeom_SurfacePatch.def("VSense", (Standard_Boolean (StepGeom_SurfacePatch::*)() const) &StepGeom_SurfacePatch::VSense, "None");
cls_StepGeom_SurfacePatch.def_static("get_type_name_", (const char * (*)()) &StepGeom_SurfacePatch::get_type_name, "None");
cls_StepGeom_SurfacePatch.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_SurfacePatch::get_type_descriptor, "None");
cls_StepGeom_SurfacePatch.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_SurfacePatch::*)() const) &StepGeom_SurfacePatch::DynamicType, "None");

// TYPEDEF: STEPGEOM_ARRAY2OFSURFACEPATCH
bind_NCollection_Array2<opencascade::handle<StepGeom_SurfacePatch> >(mod, "StepGeom_Array2OfSurfacePatch", py::module_local(false));

// CLASS: STEPGEOM_AXIS1PLACEMENT
py::class_<StepGeom_Axis1Placement, opencascade::handle<StepGeom_Axis1Placement>, StepGeom_Placement> cls_StepGeom_Axis1Placement(mod, "StepGeom_Axis1Placement", "None");

// Constructors
cls_StepGeom_Axis1Placement.def(py::init<>());

// Methods
cls_StepGeom_Axis1Placement.def("Init", (void (StepGeom_Axis1Placement::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_CartesianPoint> &, const Standard_Boolean, const opencascade::handle<StepGeom_Direction> &)) &StepGeom_Axis1Placement::Init, "None", py::arg("aName"), py::arg("aLocation"), py::arg("hasAaxis"), py::arg("aAxis"));
cls_StepGeom_Axis1Placement.def("SetAxis", (void (StepGeom_Axis1Placement::*)(const opencascade::handle<StepGeom_Direction> &)) &StepGeom_Axis1Placement::SetAxis, "None", py::arg("aAxis"));
cls_StepGeom_Axis1Placement.def("UnSetAxis", (void (StepGeom_Axis1Placement::*)()) &StepGeom_Axis1Placement::UnSetAxis, "None");
cls_StepGeom_Axis1Placement.def("Axis", (opencascade::handle<StepGeom_Direction> (StepGeom_Axis1Placement::*)() const) &StepGeom_Axis1Placement::Axis, "None");
cls_StepGeom_Axis1Placement.def("HasAxis", (Standard_Boolean (StepGeom_Axis1Placement::*)() const) &StepGeom_Axis1Placement::HasAxis, "None");
cls_StepGeom_Axis1Placement.def_static("get_type_name_", (const char * (*)()) &StepGeom_Axis1Placement::get_type_name, "None");
cls_StepGeom_Axis1Placement.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Axis1Placement::get_type_descriptor, "None");
cls_StepGeom_Axis1Placement.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Axis1Placement::*)() const) &StepGeom_Axis1Placement::DynamicType, "None");

// CLASS: STEPGEOM_AXIS2PLACEMENT
py::class_<StepGeom_Axis2Placement, StepData_SelectType> cls_StepGeom_Axis2Placement(mod, "StepGeom_Axis2Placement", "None");

// Constructors
cls_StepGeom_Axis2Placement.def(py::init<>());

// Methods
// cls_StepGeom_Axis2Placement.def_static("operator new_", (void * (*)(size_t)) &StepGeom_Axis2Placement::operator new, "None", py::arg("theSize"));
// cls_StepGeom_Axis2Placement.def_static("operator delete_", (void (*)(void *)) &StepGeom_Axis2Placement::operator delete, "None", py::arg("theAddress"));
// cls_StepGeom_Axis2Placement.def_static("operator new[]_", (void * (*)(size_t)) &StepGeom_Axis2Placement::operator new[], "None", py::arg("theSize"));
// cls_StepGeom_Axis2Placement.def_static("operator delete[]_", (void (*)(void *)) &StepGeom_Axis2Placement::operator delete[], "None", py::arg("theAddress"));
// cls_StepGeom_Axis2Placement.def_static("operator new_", (void * (*)(size_t, void *)) &StepGeom_Axis2Placement::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepGeom_Axis2Placement.def_static("operator delete_", (void (*)(void *, void *)) &StepGeom_Axis2Placement::operator delete, "None", py::arg(""), py::arg(""));
cls_StepGeom_Axis2Placement.def("CaseNum", (Standard_Integer (StepGeom_Axis2Placement::*)(const opencascade::handle<Standard_Transient> &) const) &StepGeom_Axis2Placement::CaseNum, "Recognizes a Axis2Placement Kind Entity that is : 1 -> Axis2Placement2d 2 -> Axis2Placement3d 0 else", py::arg("ent"));
cls_StepGeom_Axis2Placement.def("Axis2Placement2d", (opencascade::handle<StepGeom_Axis2Placement2d> (StepGeom_Axis2Placement::*)() const) &StepGeom_Axis2Placement::Axis2Placement2d, "returns Value as a Axis2Placement2d (Null if another type)");
cls_StepGeom_Axis2Placement.def("Axis2Placement3d", (opencascade::handle<StepGeom_Axis2Placement3d> (StepGeom_Axis2Placement::*)() const) &StepGeom_Axis2Placement::Axis2Placement3d, "returns Value as a Axis2Placement3d (Null if another type)");

// CLASS: STEPGEOM_AXIS2PLACEMENT2D
py::class_<StepGeom_Axis2Placement2d, opencascade::handle<StepGeom_Axis2Placement2d>, StepGeom_Placement> cls_StepGeom_Axis2Placement2d(mod, "StepGeom_Axis2Placement2d", "None");

// Constructors
cls_StepGeom_Axis2Placement2d.def(py::init<>());

// Methods
cls_StepGeom_Axis2Placement2d.def("Init", (void (StepGeom_Axis2Placement2d::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_CartesianPoint> &, const Standard_Boolean, const opencascade::handle<StepGeom_Direction> &)) &StepGeom_Axis2Placement2d::Init, "None", py::arg("aName"), py::arg("aLocation"), py::arg("hasArefDirection"), py::arg("aRefDirection"));
cls_StepGeom_Axis2Placement2d.def("SetRefDirection", (void (StepGeom_Axis2Placement2d::*)(const opencascade::handle<StepGeom_Direction> &)) &StepGeom_Axis2Placement2d::SetRefDirection, "None", py::arg("aRefDirection"));
cls_StepGeom_Axis2Placement2d.def("UnSetRefDirection", (void (StepGeom_Axis2Placement2d::*)()) &StepGeom_Axis2Placement2d::UnSetRefDirection, "None");
cls_StepGeom_Axis2Placement2d.def("RefDirection", (opencascade::handle<StepGeom_Direction> (StepGeom_Axis2Placement2d::*)() const) &StepGeom_Axis2Placement2d::RefDirection, "None");
cls_StepGeom_Axis2Placement2d.def("HasRefDirection", (Standard_Boolean (StepGeom_Axis2Placement2d::*)() const) &StepGeom_Axis2Placement2d::HasRefDirection, "None");
cls_StepGeom_Axis2Placement2d.def_static("get_type_name_", (const char * (*)()) &StepGeom_Axis2Placement2d::get_type_name, "None");
cls_StepGeom_Axis2Placement2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Axis2Placement2d::get_type_descriptor, "None");
cls_StepGeom_Axis2Placement2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Axis2Placement2d::*)() const) &StepGeom_Axis2Placement2d::DynamicType, "None");

// CLASS: STEPGEOM_HARRAY1OFCARTESIANPOINT
bind_Define_HArray1<StepGeom_HArray1OfCartesianPoint, StepGeom_Array1OfCartesianPoint>(mod, "StepGeom_HArray1OfCartesianPoint");

// CLASS: STEPGEOM_BSPLINECURVE
py::class_<StepGeom_BSplineCurve, opencascade::handle<StepGeom_BSplineCurve>, StepGeom_BoundedCurve> cls_StepGeom_BSplineCurve(mod, "StepGeom_BSplineCurve", "None");

// Constructors
cls_StepGeom_BSplineCurve.def(py::init<>());

// Methods
cls_StepGeom_BSplineCurve.def("Init", (void (StepGeom_BSplineCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &, const StepGeom_BSplineCurveForm, const StepData_Logical, const StepData_Logical)) &StepGeom_BSplineCurve::Init, "None", py::arg("aName"), py::arg("aDegree"), py::arg("aControlPointsList"), py::arg("aCurveForm"), py::arg("aClosedCurve"), py::arg("aSelfIntersect"));
cls_StepGeom_BSplineCurve.def("SetDegree", (void (StepGeom_BSplineCurve::*)(const Standard_Integer)) &StepGeom_BSplineCurve::SetDegree, "None", py::arg("aDegree"));
cls_StepGeom_BSplineCurve.def("Degree", (Standard_Integer (StepGeom_BSplineCurve::*)() const) &StepGeom_BSplineCurve::Degree, "None");
cls_StepGeom_BSplineCurve.def("SetControlPointsList", (void (StepGeom_BSplineCurve::*)(const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &)) &StepGeom_BSplineCurve::SetControlPointsList, "None", py::arg("aControlPointsList"));
cls_StepGeom_BSplineCurve.def("ControlPointsList", (opencascade::handle<StepGeom_HArray1OfCartesianPoint> (StepGeom_BSplineCurve::*)() const) &StepGeom_BSplineCurve::ControlPointsList, "None");
cls_StepGeom_BSplineCurve.def("ControlPointsListValue", (opencascade::handle<StepGeom_CartesianPoint> (StepGeom_BSplineCurve::*)(const Standard_Integer) const) &StepGeom_BSplineCurve::ControlPointsListValue, "None", py::arg("num"));
cls_StepGeom_BSplineCurve.def("NbControlPointsList", (Standard_Integer (StepGeom_BSplineCurve::*)() const) &StepGeom_BSplineCurve::NbControlPointsList, "None");
cls_StepGeom_BSplineCurve.def("SetCurveForm", (void (StepGeom_BSplineCurve::*)(const StepGeom_BSplineCurveForm)) &StepGeom_BSplineCurve::SetCurveForm, "None", py::arg("aCurveForm"));
cls_StepGeom_BSplineCurve.def("CurveForm", (StepGeom_BSplineCurveForm (StepGeom_BSplineCurve::*)() const) &StepGeom_BSplineCurve::CurveForm, "None");
cls_StepGeom_BSplineCurve.def("SetClosedCurve", (void (StepGeom_BSplineCurve::*)(const StepData_Logical)) &StepGeom_BSplineCurve::SetClosedCurve, "None", py::arg("aClosedCurve"));
cls_StepGeom_BSplineCurve.def("ClosedCurve", (StepData_Logical (StepGeom_BSplineCurve::*)() const) &StepGeom_BSplineCurve::ClosedCurve, "None");
cls_StepGeom_BSplineCurve.def("SetSelfIntersect", (void (StepGeom_BSplineCurve::*)(const StepData_Logical)) &StepGeom_BSplineCurve::SetSelfIntersect, "None", py::arg("aSelfIntersect"));
cls_StepGeom_BSplineCurve.def("SelfIntersect", (StepData_Logical (StepGeom_BSplineCurve::*)() const) &StepGeom_BSplineCurve::SelfIntersect, "None");
cls_StepGeom_BSplineCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_BSplineCurve::get_type_name, "None");
cls_StepGeom_BSplineCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_BSplineCurve::get_type_descriptor, "None");
cls_StepGeom_BSplineCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_BSplineCurve::*)() const) &StepGeom_BSplineCurve::DynamicType, "None");

// CLASS: STEPGEOM_BEZIERCURVE
py::class_<StepGeom_BezierCurve, opencascade::handle<StepGeom_BezierCurve>, StepGeom_BSplineCurve> cls_StepGeom_BezierCurve(mod, "StepGeom_BezierCurve", "None");

// Constructors
cls_StepGeom_BezierCurve.def(py::init<>());

// Methods
cls_StepGeom_BezierCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_BezierCurve::get_type_name, "None");
cls_StepGeom_BezierCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_BezierCurve::get_type_descriptor, "None");
cls_StepGeom_BezierCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_BezierCurve::*)() const) &StepGeom_BezierCurve::DynamicType, "None");

// CLASS: STEPGEOM_BEZIERCURVEANDRATIONALBSPLINECURVE
py::class_<StepGeom_BezierCurveAndRationalBSplineCurve, opencascade::handle<StepGeom_BezierCurveAndRationalBSplineCurve>, StepGeom_BSplineCurve> cls_StepGeom_BezierCurveAndRationalBSplineCurve(mod, "StepGeom_BezierCurveAndRationalBSplineCurve", "None");

// Constructors
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def(py::init<>());

// Methods
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def("Init", (void (StepGeom_BezierCurveAndRationalBSplineCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &, const StepGeom_BSplineCurveForm, const StepData_Logical, const StepData_Logical, const opencascade::handle<StepGeom_BezierCurve> &, const opencascade::handle<StepGeom_RationalBSplineCurve> &)) &StepGeom_BezierCurveAndRationalBSplineCurve::Init, "None", py::arg("aName"), py::arg("aDegree"), py::arg("aControlPointsList"), py::arg("aCurveForm"), py::arg("aClosedCurve"), py::arg("aSelfIntersect"), py::arg("aBezierCurve"), py::arg("aRationalBSplineCurve"));
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def("Init", (void (StepGeom_BezierCurveAndRationalBSplineCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &, const StepGeom_BSplineCurveForm, const StepData_Logical, const StepData_Logical, const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_BezierCurveAndRationalBSplineCurve::Init, "None", py::arg("aName"), py::arg("aDegree"), py::arg("aControlPointsList"), py::arg("aCurveForm"), py::arg("aClosedCurve"), py::arg("aSelfIntersect"), py::arg("aWeightsData"));
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def("SetBezierCurve", (void (StepGeom_BezierCurveAndRationalBSplineCurve::*)(const opencascade::handle<StepGeom_BezierCurve> &)) &StepGeom_BezierCurveAndRationalBSplineCurve::SetBezierCurve, "None", py::arg("aBezierCurve"));
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def("BezierCurve", (opencascade::handle<StepGeom_BezierCurve> (StepGeom_BezierCurveAndRationalBSplineCurve::*)() const) &StepGeom_BezierCurveAndRationalBSplineCurve::BezierCurve, "None");
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def("SetRationalBSplineCurve", (void (StepGeom_BezierCurveAndRationalBSplineCurve::*)(const opencascade::handle<StepGeom_RationalBSplineCurve> &)) &StepGeom_BezierCurveAndRationalBSplineCurve::SetRationalBSplineCurve, "None", py::arg("aRationalBSplineCurve"));
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def("RationalBSplineCurve", (opencascade::handle<StepGeom_RationalBSplineCurve> (StepGeom_BezierCurveAndRationalBSplineCurve::*)() const) &StepGeom_BezierCurveAndRationalBSplineCurve::RationalBSplineCurve, "None");
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def("SetWeightsData", (void (StepGeom_BezierCurveAndRationalBSplineCurve::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_BezierCurveAndRationalBSplineCurve::SetWeightsData, "None", py::arg("aWeightsData"));
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def("WeightsData", (opencascade::handle<TColStd_HArray1OfReal> (StepGeom_BezierCurveAndRationalBSplineCurve::*)() const) &StepGeom_BezierCurveAndRationalBSplineCurve::WeightsData, "None");
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def("WeightsDataValue", (Standard_Real (StepGeom_BezierCurveAndRationalBSplineCurve::*)(const Standard_Integer) const) &StepGeom_BezierCurveAndRationalBSplineCurve::WeightsDataValue, "None", py::arg("num"));
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def("NbWeightsData", (Standard_Integer (StepGeom_BezierCurveAndRationalBSplineCurve::*)() const) &StepGeom_BezierCurveAndRationalBSplineCurve::NbWeightsData, "None");
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_BezierCurveAndRationalBSplineCurve::get_type_name, "None");
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_BezierCurveAndRationalBSplineCurve::get_type_descriptor, "None");
cls_StepGeom_BezierCurveAndRationalBSplineCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_BezierCurveAndRationalBSplineCurve::*)() const) &StepGeom_BezierCurveAndRationalBSplineCurve::DynamicType, "None");

// CLASS: STEPGEOM_HARRAY2OFCARTESIANPOINT
bind_Define_HArray2<StepGeom_HArray2OfCartesianPoint, StepGeom_Array2OfCartesianPoint>(mod, "StepGeom_HArray2OfCartesianPoint");

// CLASS: STEPGEOM_SURFACE
py::class_<StepGeom_Surface, opencascade::handle<StepGeom_Surface>, StepGeom_GeometricRepresentationItem> cls_StepGeom_Surface(mod, "StepGeom_Surface", "None");

// Constructors
cls_StepGeom_Surface.def(py::init<>());

// Methods
cls_StepGeom_Surface.def_static("get_type_name_", (const char * (*)()) &StepGeom_Surface::get_type_name, "None");
cls_StepGeom_Surface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Surface::get_type_descriptor, "None");
cls_StepGeom_Surface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Surface::*)() const) &StepGeom_Surface::DynamicType, "None");

// CLASS: STEPGEOM_BOUNDEDSURFACE
py::class_<StepGeom_BoundedSurface, opencascade::handle<StepGeom_BoundedSurface>, StepGeom_Surface> cls_StepGeom_BoundedSurface(mod, "StepGeom_BoundedSurface", "None");

// Constructors
cls_StepGeom_BoundedSurface.def(py::init<>());

// Methods
cls_StepGeom_BoundedSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_BoundedSurface::get_type_name, "None");
cls_StepGeom_BoundedSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_BoundedSurface::get_type_descriptor, "None");
cls_StepGeom_BoundedSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_BoundedSurface::*)() const) &StepGeom_BoundedSurface::DynamicType, "None");

// CLASS: STEPGEOM_BSPLINESURFACE
py::class_<StepGeom_BSplineSurface, opencascade::handle<StepGeom_BSplineSurface>, StepGeom_BoundedSurface> cls_StepGeom_BSplineSurface(mod, "StepGeom_BSplineSurface", "None");

// Constructors
cls_StepGeom_BSplineSurface.def(py::init<>());

// Methods
cls_StepGeom_BSplineSurface.def("Init", (void (StepGeom_BSplineSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Integer, const opencascade::handle<StepGeom_HArray2OfCartesianPoint> &, const StepGeom_BSplineSurfaceForm, const StepData_Logical, const StepData_Logical, const StepData_Logical)) &StepGeom_BSplineSurface::Init, "None", py::arg("aName"), py::arg("aUDegree"), py::arg("aVDegree"), py::arg("aControlPointsList"), py::arg("aSurfaceForm"), py::arg("aUClosed"), py::arg("aVClosed"), py::arg("aSelfIntersect"));
cls_StepGeom_BSplineSurface.def("SetUDegree", (void (StepGeom_BSplineSurface::*)(const Standard_Integer)) &StepGeom_BSplineSurface::SetUDegree, "None", py::arg("aUDegree"));
cls_StepGeom_BSplineSurface.def("UDegree", (Standard_Integer (StepGeom_BSplineSurface::*)() const) &StepGeom_BSplineSurface::UDegree, "None");
cls_StepGeom_BSplineSurface.def("SetVDegree", (void (StepGeom_BSplineSurface::*)(const Standard_Integer)) &StepGeom_BSplineSurface::SetVDegree, "None", py::arg("aVDegree"));
cls_StepGeom_BSplineSurface.def("VDegree", (Standard_Integer (StepGeom_BSplineSurface::*)() const) &StepGeom_BSplineSurface::VDegree, "None");
cls_StepGeom_BSplineSurface.def("SetControlPointsList", (void (StepGeom_BSplineSurface::*)(const opencascade::handle<StepGeom_HArray2OfCartesianPoint> &)) &StepGeom_BSplineSurface::SetControlPointsList, "None", py::arg("aControlPointsList"));
cls_StepGeom_BSplineSurface.def("ControlPointsList", (opencascade::handle<StepGeom_HArray2OfCartesianPoint> (StepGeom_BSplineSurface::*)() const) &StepGeom_BSplineSurface::ControlPointsList, "None");
cls_StepGeom_BSplineSurface.def("ControlPointsListValue", (opencascade::handle<StepGeom_CartesianPoint> (StepGeom_BSplineSurface::*)(const Standard_Integer, const Standard_Integer) const) &StepGeom_BSplineSurface::ControlPointsListValue, "None", py::arg("num1"), py::arg("num2"));
cls_StepGeom_BSplineSurface.def("NbControlPointsListI", (Standard_Integer (StepGeom_BSplineSurface::*)() const) &StepGeom_BSplineSurface::NbControlPointsListI, "None");
cls_StepGeom_BSplineSurface.def("NbControlPointsListJ", (Standard_Integer (StepGeom_BSplineSurface::*)() const) &StepGeom_BSplineSurface::NbControlPointsListJ, "None");
cls_StepGeom_BSplineSurface.def("SetSurfaceForm", (void (StepGeom_BSplineSurface::*)(const StepGeom_BSplineSurfaceForm)) &StepGeom_BSplineSurface::SetSurfaceForm, "None", py::arg("aSurfaceForm"));
cls_StepGeom_BSplineSurface.def("SurfaceForm", (StepGeom_BSplineSurfaceForm (StepGeom_BSplineSurface::*)() const) &StepGeom_BSplineSurface::SurfaceForm, "None");
cls_StepGeom_BSplineSurface.def("SetUClosed", (void (StepGeom_BSplineSurface::*)(const StepData_Logical)) &StepGeom_BSplineSurface::SetUClosed, "None", py::arg("aUClosed"));
cls_StepGeom_BSplineSurface.def("UClosed", (StepData_Logical (StepGeom_BSplineSurface::*)() const) &StepGeom_BSplineSurface::UClosed, "None");
cls_StepGeom_BSplineSurface.def("SetVClosed", (void (StepGeom_BSplineSurface::*)(const StepData_Logical)) &StepGeom_BSplineSurface::SetVClosed, "None", py::arg("aVClosed"));
cls_StepGeom_BSplineSurface.def("VClosed", (StepData_Logical (StepGeom_BSplineSurface::*)() const) &StepGeom_BSplineSurface::VClosed, "None");
cls_StepGeom_BSplineSurface.def("SetSelfIntersect", (void (StepGeom_BSplineSurface::*)(const StepData_Logical)) &StepGeom_BSplineSurface::SetSelfIntersect, "None", py::arg("aSelfIntersect"));
cls_StepGeom_BSplineSurface.def("SelfIntersect", (StepData_Logical (StepGeom_BSplineSurface::*)() const) &StepGeom_BSplineSurface::SelfIntersect, "None");
cls_StepGeom_BSplineSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_BSplineSurface::get_type_name, "None");
cls_StepGeom_BSplineSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_BSplineSurface::get_type_descriptor, "None");
cls_StepGeom_BSplineSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_BSplineSurface::*)() const) &StepGeom_BSplineSurface::DynamicType, "None");

// CLASS: STEPGEOM_BEZIERSURFACE
py::class_<StepGeom_BezierSurface, opencascade::handle<StepGeom_BezierSurface>, StepGeom_BSplineSurface> cls_StepGeom_BezierSurface(mod, "StepGeom_BezierSurface", "None");

// Constructors
cls_StepGeom_BezierSurface.def(py::init<>());

// Methods
cls_StepGeom_BezierSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_BezierSurface::get_type_name, "None");
cls_StepGeom_BezierSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_BezierSurface::get_type_descriptor, "None");
cls_StepGeom_BezierSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_BezierSurface::*)() const) &StepGeom_BezierSurface::DynamicType, "None");

// CLASS: STEPGEOM_BEZIERSURFACEANDRATIONALBSPLINESURFACE
py::class_<StepGeom_BezierSurfaceAndRationalBSplineSurface, opencascade::handle<StepGeom_BezierSurfaceAndRationalBSplineSurface>, StepGeom_BSplineSurface> cls_StepGeom_BezierSurfaceAndRationalBSplineSurface(mod, "StepGeom_BezierSurfaceAndRationalBSplineSurface", "None");

// Constructors
cls_StepGeom_BezierSurfaceAndRationalBSplineSurface.def(py::init<>());

// Methods
cls_StepGeom_BezierSurfaceAndRationalBSplineSurface.def("Init", (void (StepGeom_BezierSurfaceAndRationalBSplineSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Integer, const opencascade::handle<StepGeom_HArray2OfCartesianPoint> &, const StepGeom_BSplineSurfaceForm, const StepData_Logical, const StepData_Logical, const StepData_Logical, const opencascade::handle<StepGeom_BezierSurface> &, const opencascade::handle<StepGeom_RationalBSplineSurface> &)) &StepGeom_BezierSurfaceAndRationalBSplineSurface::Init, "None", py::arg("aName"), py::arg("aUDegree"), py::arg("aVDegree"), py::arg("aControlPointsList"), py::arg("aSurfaceForm"), py::arg("aUClosed"), py::arg("aVClosed"), py::arg("aSelfIntersect"), py::arg("aBezierSurface"), py::arg("aRationalBSplineSurface"));
cls_StepGeom_BezierSurfaceAndRationalBSplineSurface.def("Init", (void (StepGeom_BezierSurfaceAndRationalBSplineSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Integer, const opencascade::handle<StepGeom_HArray2OfCartesianPoint> &, const StepGeom_BSplineSurfaceForm, const StepData_Logical, const StepData_Logical, const StepData_Logical, const opencascade::handle<TColStd_HArray2OfReal> &)) &StepGeom_BezierSurfaceAndRationalBSplineSurface::Init, "None", py::arg("aName"), py::arg("aUDegree"), py::arg("aVDegree"), py::arg("aControlPointsList"), py::arg("aSurfaceForm"), py::arg("aUClosed"), py::arg("aVClosed"), py::arg("aSelfIntersect"), py::arg("aWeightsData"));
cls_StepGeom_BezierSurfaceAndRationalBSplineSurface.def("SetBezierSurface", (void (StepGeom_BezierSurfaceAndRationalBSplineSurface::*)(const opencascade::handle<StepGeom_BezierSurface> &)) &StepGeom_BezierSurfaceAndRationalBSplineSurface::SetBezierSurface, "None", py::arg("aBezierSurface"));
cls_StepGeom_BezierSurfaceAndRationalBSplineSurface.def("BezierSurface", (opencascade::handle<StepGeom_BezierSurface> (StepGeom_BezierSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_BezierSurfaceAndRationalBSplineSurface::BezierSurface, "None");
cls_StepGeom_BezierSurfaceAndRationalBSplineSurface.def("SetRationalBSplineSurface", (void (StepGeom_BezierSurfaceAndRationalBSplineSurface::*)(const opencascade::handle<StepGeom_RationalBSplineSurface> &)) &StepGeom_BezierSurfaceAndRationalBSplineSurface::SetRationalBSplineSurface, "None", py::arg("aRationalBSplineSurface"));
cls_StepGeom_BezierSurfaceAndRationalBSplineSurface.def("RationalBSplineSurface", (opencascade::handle<StepGeom_RationalBSplineSurface> (StepGeom_BezierSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_BezierSurfaceAndRationalBSplineSurface::RationalBSplineSurface, "None");
cls_StepGeom_BezierSurfaceAndRationalBSplineSurface.def("SetWeightsData", (void (StepGeom_BezierSurfaceAndRationalBSplineSurface::*)(const opencascade::handle<TColStd_HArray2OfReal> &)) &StepGeom_BezierSurfaceAndRationalBSplineSurface::SetWeightsData, "None", py::arg("aWeightsData"));
cls_StepGeom_BezierSurfaceAndRationalBSplineSurface.def("WeightsData", (opencascade::handle<TColStd_HArray2OfReal> (StepGeom_BezierSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_BezierSurfaceAndRationalBSplineSurface::WeightsData, "None");
cls_StepGeom_BezierSurfaceAndRationalBSplineSurface.def("WeightsDataValue", (Standard_Real (StepGeom_BezierSurfaceAndRationalBSplineSurface::*)(const Standard_Integer, const Standard_Integer) const) &StepGeom_BezierSurfaceAndRationalBSplineSurface::WeightsDataValue, "None", py::arg("num1"), py::arg("num2"));
cls_StepGeom_BezierSurfaceAndRationalBSplineSurface.def("NbWeightsDataI", (Standard_Integer (StepGeom_BezierSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_BezierSurfaceAndRationalBSplineSurface::NbWeightsDataI, "None");
cls_StepGeom_BezierSurfaceAndRationalBSplineSurface.def("NbWeightsDataJ", (Standard_Integer (StepGeom_BezierSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_BezierSurfaceAndRationalBSplineSurface::NbWeightsDataJ, "None");
cls_StepGeom_BezierSurfaceAndRationalBSplineSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_BezierSurfaceAndRationalBSplineSurface::get_type_name, "None");
cls_StepGeom_BezierSurfaceAndRationalBSplineSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_BezierSurfaceAndRationalBSplineSurface::get_type_descriptor, "None");
cls_StepGeom_BezierSurfaceAndRationalBSplineSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_BezierSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_BezierSurfaceAndRationalBSplineSurface::DynamicType, "None");

// CLASS: STEPGEOM_BSPLINECURVEWITHKNOTS
py::class_<StepGeom_BSplineCurveWithKnots, opencascade::handle<StepGeom_BSplineCurveWithKnots>, StepGeom_BSplineCurve> cls_StepGeom_BSplineCurveWithKnots(mod, "StepGeom_BSplineCurveWithKnots", "None");

// Constructors
cls_StepGeom_BSplineCurveWithKnots.def(py::init<>());

// Methods
cls_StepGeom_BSplineCurveWithKnots.def("Init", (void (StepGeom_BSplineCurveWithKnots::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &, const StepGeom_BSplineCurveForm, const StepData_Logical, const StepData_Logical, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfReal> &, const StepGeom_KnotType)) &StepGeom_BSplineCurveWithKnots::Init, "None", py::arg("aName"), py::arg("aDegree"), py::arg("aControlPointsList"), py::arg("aCurveForm"), py::arg("aClosedCurve"), py::arg("aSelfIntersect"), py::arg("aKnotMultiplicities"), py::arg("aKnots"), py::arg("aKnotSpec"));
cls_StepGeom_BSplineCurveWithKnots.def("SetKnotMultiplicities", (void (StepGeom_BSplineCurveWithKnots::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &StepGeom_BSplineCurveWithKnots::SetKnotMultiplicities, "None", py::arg("aKnotMultiplicities"));
cls_StepGeom_BSplineCurveWithKnots.def("KnotMultiplicities", (opencascade::handle<TColStd_HArray1OfInteger> (StepGeom_BSplineCurveWithKnots::*)() const) &StepGeom_BSplineCurveWithKnots::KnotMultiplicities, "None");
cls_StepGeom_BSplineCurveWithKnots.def("KnotMultiplicitiesValue", (Standard_Integer (StepGeom_BSplineCurveWithKnots::*)(const Standard_Integer) const) &StepGeom_BSplineCurveWithKnots::KnotMultiplicitiesValue, "None", py::arg("num"));
cls_StepGeom_BSplineCurveWithKnots.def("NbKnotMultiplicities", (Standard_Integer (StepGeom_BSplineCurveWithKnots::*)() const) &StepGeom_BSplineCurveWithKnots::NbKnotMultiplicities, "None");
cls_StepGeom_BSplineCurveWithKnots.def("SetKnots", (void (StepGeom_BSplineCurveWithKnots::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_BSplineCurveWithKnots::SetKnots, "None", py::arg("aKnots"));
cls_StepGeom_BSplineCurveWithKnots.def("Knots", (opencascade::handle<TColStd_HArray1OfReal> (StepGeom_BSplineCurveWithKnots::*)() const) &StepGeom_BSplineCurveWithKnots::Knots, "None");
cls_StepGeom_BSplineCurveWithKnots.def("KnotsValue", (Standard_Real (StepGeom_BSplineCurveWithKnots::*)(const Standard_Integer) const) &StepGeom_BSplineCurveWithKnots::KnotsValue, "None", py::arg("num"));
cls_StepGeom_BSplineCurveWithKnots.def("NbKnots", (Standard_Integer (StepGeom_BSplineCurveWithKnots::*)() const) &StepGeom_BSplineCurveWithKnots::NbKnots, "None");
cls_StepGeom_BSplineCurveWithKnots.def("SetKnotSpec", (void (StepGeom_BSplineCurveWithKnots::*)(const StepGeom_KnotType)) &StepGeom_BSplineCurveWithKnots::SetKnotSpec, "None", py::arg("aKnotSpec"));
cls_StepGeom_BSplineCurveWithKnots.def("KnotSpec", (StepGeom_KnotType (StepGeom_BSplineCurveWithKnots::*)() const) &StepGeom_BSplineCurveWithKnots::KnotSpec, "None");
cls_StepGeom_BSplineCurveWithKnots.def_static("get_type_name_", (const char * (*)()) &StepGeom_BSplineCurveWithKnots::get_type_name, "None");
cls_StepGeom_BSplineCurveWithKnots.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_BSplineCurveWithKnots::get_type_descriptor, "None");
cls_StepGeom_BSplineCurveWithKnots.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_BSplineCurveWithKnots::*)() const) &StepGeom_BSplineCurveWithKnots::DynamicType, "None");

// CLASS: STEPGEOM_BSPLINECURVEWITHKNOTSANDRATIONALBSPLINECURVE
py::class_<StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve, opencascade::handle<StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve>, StepGeom_BSplineCurve> cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve(mod, "StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve", "None");

// Constructors
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def(py::init<>());

// Methods
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("Init", (void (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &, const StepGeom_BSplineCurveForm, const StepData_Logical, const StepData_Logical, const opencascade::handle<StepGeom_BSplineCurveWithKnots> &, const opencascade::handle<StepGeom_RationalBSplineCurve> &)) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::Init, "None", py::arg("aName"), py::arg("aDegree"), py::arg("aControlPointsList"), py::arg("aCurveForm"), py::arg("aClosedCurve"), py::arg("aSelfIntersect"), py::arg("aBSplineCurveWithKnots"), py::arg("aRationalBSplineCurve"));
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("Init", (void (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &, const StepGeom_BSplineCurveForm, const StepData_Logical, const StepData_Logical, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfReal> &, const StepGeom_KnotType, const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::Init, "None", py::arg("aName"), py::arg("aDegree"), py::arg("aControlPointsList"), py::arg("aCurveForm"), py::arg("aClosedCurve"), py::arg("aSelfIntersect"), py::arg("aKnotMultiplicities"), py::arg("aKnots"), py::arg("aKnotSpec"), py::arg("aWeightsData"));
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("SetBSplineCurveWithKnots", (void (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)(const opencascade::handle<StepGeom_BSplineCurveWithKnots> &)) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::SetBSplineCurveWithKnots, "None", py::arg("aBSplineCurveWithKnots"));
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("BSplineCurveWithKnots", (opencascade::handle<StepGeom_BSplineCurveWithKnots> (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)() const) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::BSplineCurveWithKnots, "None");
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("SetRationalBSplineCurve", (void (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)(const opencascade::handle<StepGeom_RationalBSplineCurve> &)) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::SetRationalBSplineCurve, "None", py::arg("aRationalBSplineCurve"));
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("RationalBSplineCurve", (opencascade::handle<StepGeom_RationalBSplineCurve> (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)() const) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::RationalBSplineCurve, "None");
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("SetKnotMultiplicities", (void (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::SetKnotMultiplicities, "None", py::arg("aKnotMultiplicities"));
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("KnotMultiplicities", (opencascade::handle<TColStd_HArray1OfInteger> (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)() const) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::KnotMultiplicities, "None");
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("KnotMultiplicitiesValue", (Standard_Integer (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)(const Standard_Integer) const) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::KnotMultiplicitiesValue, "None", py::arg("num"));
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("NbKnotMultiplicities", (Standard_Integer (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)() const) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::NbKnotMultiplicities, "None");
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("SetKnots", (void (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::SetKnots, "None", py::arg("aKnots"));
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("Knots", (opencascade::handle<TColStd_HArray1OfReal> (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)() const) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::Knots, "None");
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("KnotsValue", (Standard_Real (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)(const Standard_Integer) const) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::KnotsValue, "None", py::arg("num"));
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("NbKnots", (Standard_Integer (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)() const) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::NbKnots, "None");
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("SetKnotSpec", (void (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)(const StepGeom_KnotType)) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::SetKnotSpec, "None", py::arg("aKnotSpec"));
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("KnotSpec", (StepGeom_KnotType (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)() const) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::KnotSpec, "None");
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("SetWeightsData", (void (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::SetWeightsData, "None", py::arg("aWeightsData"));
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("WeightsData", (opencascade::handle<TColStd_HArray1OfReal> (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)() const) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::WeightsData, "None");
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("WeightsDataValue", (Standard_Real (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)(const Standard_Integer) const) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::WeightsDataValue, "None", py::arg("num"));
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("NbWeightsData", (Standard_Integer (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)() const) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::NbWeightsData, "None");
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::get_type_name, "None");
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::get_type_descriptor, "None");
cls_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::*)() const) &StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve::DynamicType, "None");

// CLASS: STEPGEOM_BSPLINESURFACEWITHKNOTS
py::class_<StepGeom_BSplineSurfaceWithKnots, opencascade::handle<StepGeom_BSplineSurfaceWithKnots>, StepGeom_BSplineSurface> cls_StepGeom_BSplineSurfaceWithKnots(mod, "StepGeom_BSplineSurfaceWithKnots", "None");

// Constructors
cls_StepGeom_BSplineSurfaceWithKnots.def(py::init<>());

// Methods
cls_StepGeom_BSplineSurfaceWithKnots.def("Init", (void (StepGeom_BSplineSurfaceWithKnots::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Integer, const opencascade::handle<StepGeom_HArray2OfCartesianPoint> &, const StepGeom_BSplineSurfaceForm, const StepData_Logical, const StepData_Logical, const StepData_Logical, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const StepGeom_KnotType)) &StepGeom_BSplineSurfaceWithKnots::Init, "None", py::arg("aName"), py::arg("aUDegree"), py::arg("aVDegree"), py::arg("aControlPointsList"), py::arg("aSurfaceForm"), py::arg("aUClosed"), py::arg("aVClosed"), py::arg("aSelfIntersect"), py::arg("aUMultiplicities"), py::arg("aVMultiplicities"), py::arg("aUKnots"), py::arg("aVKnots"), py::arg("aKnotSpec"));
cls_StepGeom_BSplineSurfaceWithKnots.def("SetUMultiplicities", (void (StepGeom_BSplineSurfaceWithKnots::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &StepGeom_BSplineSurfaceWithKnots::SetUMultiplicities, "None", py::arg("aUMultiplicities"));
cls_StepGeom_BSplineSurfaceWithKnots.def("UMultiplicities", (opencascade::handle<TColStd_HArray1OfInteger> (StepGeom_BSplineSurfaceWithKnots::*)() const) &StepGeom_BSplineSurfaceWithKnots::UMultiplicities, "None");
cls_StepGeom_BSplineSurfaceWithKnots.def("UMultiplicitiesValue", (Standard_Integer (StepGeom_BSplineSurfaceWithKnots::*)(const Standard_Integer) const) &StepGeom_BSplineSurfaceWithKnots::UMultiplicitiesValue, "None", py::arg("num"));
cls_StepGeom_BSplineSurfaceWithKnots.def("NbUMultiplicities", (Standard_Integer (StepGeom_BSplineSurfaceWithKnots::*)() const) &StepGeom_BSplineSurfaceWithKnots::NbUMultiplicities, "None");
cls_StepGeom_BSplineSurfaceWithKnots.def("SetVMultiplicities", (void (StepGeom_BSplineSurfaceWithKnots::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &StepGeom_BSplineSurfaceWithKnots::SetVMultiplicities, "None", py::arg("aVMultiplicities"));
cls_StepGeom_BSplineSurfaceWithKnots.def("VMultiplicities", (opencascade::handle<TColStd_HArray1OfInteger> (StepGeom_BSplineSurfaceWithKnots::*)() const) &StepGeom_BSplineSurfaceWithKnots::VMultiplicities, "None");
cls_StepGeom_BSplineSurfaceWithKnots.def("VMultiplicitiesValue", (Standard_Integer (StepGeom_BSplineSurfaceWithKnots::*)(const Standard_Integer) const) &StepGeom_BSplineSurfaceWithKnots::VMultiplicitiesValue, "None", py::arg("num"));
cls_StepGeom_BSplineSurfaceWithKnots.def("NbVMultiplicities", (Standard_Integer (StepGeom_BSplineSurfaceWithKnots::*)() const) &StepGeom_BSplineSurfaceWithKnots::NbVMultiplicities, "None");
cls_StepGeom_BSplineSurfaceWithKnots.def("SetUKnots", (void (StepGeom_BSplineSurfaceWithKnots::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_BSplineSurfaceWithKnots::SetUKnots, "None", py::arg("aUKnots"));
cls_StepGeom_BSplineSurfaceWithKnots.def("UKnots", (opencascade::handle<TColStd_HArray1OfReal> (StepGeom_BSplineSurfaceWithKnots::*)() const) &StepGeom_BSplineSurfaceWithKnots::UKnots, "None");
cls_StepGeom_BSplineSurfaceWithKnots.def("UKnotsValue", (Standard_Real (StepGeom_BSplineSurfaceWithKnots::*)(const Standard_Integer) const) &StepGeom_BSplineSurfaceWithKnots::UKnotsValue, "None", py::arg("num"));
cls_StepGeom_BSplineSurfaceWithKnots.def("NbUKnots", (Standard_Integer (StepGeom_BSplineSurfaceWithKnots::*)() const) &StepGeom_BSplineSurfaceWithKnots::NbUKnots, "None");
cls_StepGeom_BSplineSurfaceWithKnots.def("SetVKnots", (void (StepGeom_BSplineSurfaceWithKnots::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_BSplineSurfaceWithKnots::SetVKnots, "None", py::arg("aVKnots"));
cls_StepGeom_BSplineSurfaceWithKnots.def("VKnots", (opencascade::handle<TColStd_HArray1OfReal> (StepGeom_BSplineSurfaceWithKnots::*)() const) &StepGeom_BSplineSurfaceWithKnots::VKnots, "None");
cls_StepGeom_BSplineSurfaceWithKnots.def("VKnotsValue", (Standard_Real (StepGeom_BSplineSurfaceWithKnots::*)(const Standard_Integer) const) &StepGeom_BSplineSurfaceWithKnots::VKnotsValue, "None", py::arg("num"));
cls_StepGeom_BSplineSurfaceWithKnots.def("NbVKnots", (Standard_Integer (StepGeom_BSplineSurfaceWithKnots::*)() const) &StepGeom_BSplineSurfaceWithKnots::NbVKnots, "None");
cls_StepGeom_BSplineSurfaceWithKnots.def("SetKnotSpec", (void (StepGeom_BSplineSurfaceWithKnots::*)(const StepGeom_KnotType)) &StepGeom_BSplineSurfaceWithKnots::SetKnotSpec, "None", py::arg("aKnotSpec"));
cls_StepGeom_BSplineSurfaceWithKnots.def("KnotSpec", (StepGeom_KnotType (StepGeom_BSplineSurfaceWithKnots::*)() const) &StepGeom_BSplineSurfaceWithKnots::KnotSpec, "None");
cls_StepGeom_BSplineSurfaceWithKnots.def_static("get_type_name_", (const char * (*)()) &StepGeom_BSplineSurfaceWithKnots::get_type_name, "None");
cls_StepGeom_BSplineSurfaceWithKnots.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_BSplineSurfaceWithKnots::get_type_descriptor, "None");
cls_StepGeom_BSplineSurfaceWithKnots.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_BSplineSurfaceWithKnots::*)() const) &StepGeom_BSplineSurfaceWithKnots::DynamicType, "None");

// CLASS: STEPGEOM_BSPLINESURFACEWITHKNOTSANDRATIONALBSPLINESURFACE
py::class_<StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface, opencascade::handle<StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface>, StepGeom_BSplineSurface> cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface(mod, "StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface", "None");

// Constructors
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def(py::init<>());

// Methods
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("Init", (void (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Integer, const opencascade::handle<StepGeom_HArray2OfCartesianPoint> &, const StepGeom_BSplineSurfaceForm, const StepData_Logical, const StepData_Logical, const StepData_Logical, const opencascade::handle<StepGeom_BSplineSurfaceWithKnots> &, const opencascade::handle<StepGeom_RationalBSplineSurface> &)) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::Init, "None", py::arg("aName"), py::arg("aUDegree"), py::arg("aVDegree"), py::arg("aControlPointsList"), py::arg("aSurfaceForm"), py::arg("aUClosed"), py::arg("aVClosed"), py::arg("aSelfIntersect"), py::arg("aBSplineSurfaceWithKnots"), py::arg("aRationalBSplineSurface"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("Init", (void (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Integer, const opencascade::handle<StepGeom_HArray2OfCartesianPoint> &, const StepGeom_BSplineSurfaceForm, const StepData_Logical, const StepData_Logical, const StepData_Logical, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const StepGeom_KnotType, const opencascade::handle<TColStd_HArray2OfReal> &)) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::Init, "None", py::arg("aName"), py::arg("aUDegree"), py::arg("aVDegree"), py::arg("aControlPointsList"), py::arg("aSurfaceForm"), py::arg("aUClosed"), py::arg("aVClosed"), py::arg("aSelfIntersect"), py::arg("aUMultiplicities"), py::arg("aVMultiplicities"), py::arg("aUKnots"), py::arg("aVKnots"), py::arg("aKnotSpec"), py::arg("aWeightsData"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("SetBSplineSurfaceWithKnots", (void (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const opencascade::handle<StepGeom_BSplineSurfaceWithKnots> &)) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::SetBSplineSurfaceWithKnots, "None", py::arg("aBSplineSurfaceWithKnots"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("BSplineSurfaceWithKnots", (opencascade::handle<StepGeom_BSplineSurfaceWithKnots> (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::BSplineSurfaceWithKnots, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("SetRationalBSplineSurface", (void (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const opencascade::handle<StepGeom_RationalBSplineSurface> &)) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::SetRationalBSplineSurface, "None", py::arg("aRationalBSplineSurface"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("RationalBSplineSurface", (opencascade::handle<StepGeom_RationalBSplineSurface> (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::RationalBSplineSurface, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("SetUMultiplicities", (void (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::SetUMultiplicities, "None", py::arg("aUMultiplicities"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("UMultiplicities", (opencascade::handle<TColStd_HArray1OfInteger> (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::UMultiplicities, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("UMultiplicitiesValue", (Standard_Integer (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const Standard_Integer) const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::UMultiplicitiesValue, "None", py::arg("num"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("NbUMultiplicities", (Standard_Integer (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::NbUMultiplicities, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("SetVMultiplicities", (void (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::SetVMultiplicities, "None", py::arg("aVMultiplicities"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("VMultiplicities", (opencascade::handle<TColStd_HArray1OfInteger> (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::VMultiplicities, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("VMultiplicitiesValue", (Standard_Integer (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const Standard_Integer) const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::VMultiplicitiesValue, "None", py::arg("num"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("NbVMultiplicities", (Standard_Integer (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::NbVMultiplicities, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("SetUKnots", (void (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::SetUKnots, "None", py::arg("aUKnots"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("UKnots", (opencascade::handle<TColStd_HArray1OfReal> (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::UKnots, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("UKnotsValue", (Standard_Real (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const Standard_Integer) const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::UKnotsValue, "None", py::arg("num"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("NbUKnots", (Standard_Integer (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::NbUKnots, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("SetVKnots", (void (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::SetVKnots, "None", py::arg("aVKnots"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("VKnots", (opencascade::handle<TColStd_HArray1OfReal> (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::VKnots, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("VKnotsValue", (Standard_Real (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const Standard_Integer) const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::VKnotsValue, "None", py::arg("num"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("NbVKnots", (Standard_Integer (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::NbVKnots, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("SetKnotSpec", (void (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const StepGeom_KnotType)) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::SetKnotSpec, "None", py::arg("aKnotSpec"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("KnotSpec", (StepGeom_KnotType (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::KnotSpec, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("SetWeightsData", (void (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const opencascade::handle<TColStd_HArray2OfReal> &)) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::SetWeightsData, "None", py::arg("aWeightsData"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("WeightsData", (opencascade::handle<TColStd_HArray2OfReal> (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::WeightsData, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("WeightsDataValue", (Standard_Real (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const Standard_Integer, const Standard_Integer) const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::WeightsDataValue, "None", py::arg("num1"), py::arg("num2"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("NbWeightsDataI", (Standard_Integer (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::NbWeightsDataI, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("NbWeightsDataJ", (Standard_Integer (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::NbWeightsDataJ, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::get_type_name, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::get_type_descriptor, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::DynamicType, "None");

// CLASS: STEPGEOM_CARTESIANTRANSFORMATIONOPERATOR
py::class_<StepGeom_CartesianTransformationOperator, opencascade::handle<StepGeom_CartesianTransformationOperator>, StepGeom_GeometricRepresentationItem> cls_StepGeom_CartesianTransformationOperator(mod, "StepGeom_CartesianTransformationOperator", "None");

// Constructors
cls_StepGeom_CartesianTransformationOperator.def(py::init<>());

// Methods
cls_StepGeom_CartesianTransformationOperator.def("Init", (void (StepGeom_CartesianTransformationOperator::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<StepGeom_Direction> &, const Standard_Boolean, const opencascade::handle<StepGeom_Direction> &, const opencascade::handle<StepGeom_CartesianPoint> &, const Standard_Boolean, const Standard_Real)) &StepGeom_CartesianTransformationOperator::Init, "None", py::arg("aName"), py::arg("hasAaxis1"), py::arg("aAxis1"), py::arg("hasAaxis2"), py::arg("aAxis2"), py::arg("aLocalOrigin"), py::arg("hasAscale"), py::arg("aScale"));
cls_StepGeom_CartesianTransformationOperator.def("SetAxis1", (void (StepGeom_CartesianTransformationOperator::*)(const opencascade::handle<StepGeom_Direction> &)) &StepGeom_CartesianTransformationOperator::SetAxis1, "None", py::arg("aAxis1"));
cls_StepGeom_CartesianTransformationOperator.def("UnSetAxis1", (void (StepGeom_CartesianTransformationOperator::*)()) &StepGeom_CartesianTransformationOperator::UnSetAxis1, "None");
cls_StepGeom_CartesianTransformationOperator.def("Axis1", (opencascade::handle<StepGeom_Direction> (StepGeom_CartesianTransformationOperator::*)() const) &StepGeom_CartesianTransformationOperator::Axis1, "None");
cls_StepGeom_CartesianTransformationOperator.def("HasAxis1", (Standard_Boolean (StepGeom_CartesianTransformationOperator::*)() const) &StepGeom_CartesianTransformationOperator::HasAxis1, "None");
cls_StepGeom_CartesianTransformationOperator.def("SetAxis2", (void (StepGeom_CartesianTransformationOperator::*)(const opencascade::handle<StepGeom_Direction> &)) &StepGeom_CartesianTransformationOperator::SetAxis2, "None", py::arg("aAxis2"));
cls_StepGeom_CartesianTransformationOperator.def("UnSetAxis2", (void (StepGeom_CartesianTransformationOperator::*)()) &StepGeom_CartesianTransformationOperator::UnSetAxis2, "None");
cls_StepGeom_CartesianTransformationOperator.def("Axis2", (opencascade::handle<StepGeom_Direction> (StepGeom_CartesianTransformationOperator::*)() const) &StepGeom_CartesianTransformationOperator::Axis2, "None");
cls_StepGeom_CartesianTransformationOperator.def("HasAxis2", (Standard_Boolean (StepGeom_CartesianTransformationOperator::*)() const) &StepGeom_CartesianTransformationOperator::HasAxis2, "None");
cls_StepGeom_CartesianTransformationOperator.def("SetLocalOrigin", (void (StepGeom_CartesianTransformationOperator::*)(const opencascade::handle<StepGeom_CartesianPoint> &)) &StepGeom_CartesianTransformationOperator::SetLocalOrigin, "None", py::arg("aLocalOrigin"));
cls_StepGeom_CartesianTransformationOperator.def("LocalOrigin", (opencascade::handle<StepGeom_CartesianPoint> (StepGeom_CartesianTransformationOperator::*)() const) &StepGeom_CartesianTransformationOperator::LocalOrigin, "None");
cls_StepGeom_CartesianTransformationOperator.def("SetScale", (void (StepGeom_CartesianTransformationOperator::*)(const Standard_Real)) &StepGeom_CartesianTransformationOperator::SetScale, "None", py::arg("aScale"));
cls_StepGeom_CartesianTransformationOperator.def("UnSetScale", (void (StepGeom_CartesianTransformationOperator::*)()) &StepGeom_CartesianTransformationOperator::UnSetScale, "None");
cls_StepGeom_CartesianTransformationOperator.def("Scale", (Standard_Real (StepGeom_CartesianTransformationOperator::*)() const) &StepGeom_CartesianTransformationOperator::Scale, "None");
cls_StepGeom_CartesianTransformationOperator.def("HasScale", (Standard_Boolean (StepGeom_CartesianTransformationOperator::*)() const) &StepGeom_CartesianTransformationOperator::HasScale, "None");
cls_StepGeom_CartesianTransformationOperator.def_static("get_type_name_", (const char * (*)()) &StepGeom_CartesianTransformationOperator::get_type_name, "None");
cls_StepGeom_CartesianTransformationOperator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_CartesianTransformationOperator::get_type_descriptor, "None");
cls_StepGeom_CartesianTransformationOperator.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_CartesianTransformationOperator::*)() const) &StepGeom_CartesianTransformationOperator::DynamicType, "None");

// CLASS: STEPGEOM_CARTESIANTRANSFORMATIONOPERATOR2D
py::class_<StepGeom_CartesianTransformationOperator2d, opencascade::handle<StepGeom_CartesianTransformationOperator2d>, StepGeom_CartesianTransformationOperator> cls_StepGeom_CartesianTransformationOperator2d(mod, "StepGeom_CartesianTransformationOperator2d", "Added from StepGeom Rev2 to Rev4");

// Constructors
cls_StepGeom_CartesianTransformationOperator2d.def(py::init<>());

// Methods
cls_StepGeom_CartesianTransformationOperator2d.def_static("get_type_name_", (const char * (*)()) &StepGeom_CartesianTransformationOperator2d::get_type_name, "None");
cls_StepGeom_CartesianTransformationOperator2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_CartesianTransformationOperator2d::get_type_descriptor, "None");
cls_StepGeom_CartesianTransformationOperator2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_CartesianTransformationOperator2d::*)() const) &StepGeom_CartesianTransformationOperator2d::DynamicType, "None");

// CLASS: STEPGEOM_CARTESIANTRANSFORMATIONOPERATOR3D
py::class_<StepGeom_CartesianTransformationOperator3d, opencascade::handle<StepGeom_CartesianTransformationOperator3d>, StepGeom_CartesianTransformationOperator> cls_StepGeom_CartesianTransformationOperator3d(mod, "StepGeom_CartesianTransformationOperator3d", "None");

// Constructors
cls_StepGeom_CartesianTransformationOperator3d.def(py::init<>());

// Methods
cls_StepGeom_CartesianTransformationOperator3d.def("Init", (void (StepGeom_CartesianTransformationOperator3d::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<StepGeom_Direction> &, const Standard_Boolean, const opencascade::handle<StepGeom_Direction> &, const opencascade::handle<StepGeom_CartesianPoint> &, const Standard_Boolean, const Standard_Real, const Standard_Boolean, const opencascade::handle<StepGeom_Direction> &)) &StepGeom_CartesianTransformationOperator3d::Init, "None", py::arg("aName"), py::arg("hasAaxis1"), py::arg("aAxis1"), py::arg("hasAaxis2"), py::arg("aAxis2"), py::arg("aLocalOrigin"), py::arg("hasAscale"), py::arg("aScale"), py::arg("hasAaxis3"), py::arg("aAxis3"));
cls_StepGeom_CartesianTransformationOperator3d.def("SetAxis3", (void (StepGeom_CartesianTransformationOperator3d::*)(const opencascade::handle<StepGeom_Direction> &)) &StepGeom_CartesianTransformationOperator3d::SetAxis3, "None", py::arg("aAxis3"));
cls_StepGeom_CartesianTransformationOperator3d.def("UnSetAxis3", (void (StepGeom_CartesianTransformationOperator3d::*)()) &StepGeom_CartesianTransformationOperator3d::UnSetAxis3, "None");
cls_StepGeom_CartesianTransformationOperator3d.def("Axis3", (opencascade::handle<StepGeom_Direction> (StepGeom_CartesianTransformationOperator3d::*)() const) &StepGeom_CartesianTransformationOperator3d::Axis3, "None");
cls_StepGeom_CartesianTransformationOperator3d.def("HasAxis3", (Standard_Boolean (StepGeom_CartesianTransformationOperator3d::*)() const) &StepGeom_CartesianTransformationOperator3d::HasAxis3, "None");
cls_StepGeom_CartesianTransformationOperator3d.def_static("get_type_name_", (const char * (*)()) &StepGeom_CartesianTransformationOperator3d::get_type_name, "None");
cls_StepGeom_CartesianTransformationOperator3d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_CartesianTransformationOperator3d::get_type_descriptor, "None");
cls_StepGeom_CartesianTransformationOperator3d.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_CartesianTransformationOperator3d::*)() const) &StepGeom_CartesianTransformationOperator3d::DynamicType, "None");

// CLASS: STEPGEOM_CONIC
py::class_<StepGeom_Conic, opencascade::handle<StepGeom_Conic>, StepGeom_Curve> cls_StepGeom_Conic(mod, "StepGeom_Conic", "None");

// Constructors
cls_StepGeom_Conic.def(py::init<>());

// Methods
cls_StepGeom_Conic.def("Init", (void (StepGeom_Conic::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepGeom_Axis2Placement &)) &StepGeom_Conic::Init, "None", py::arg("aName"), py::arg("aPosition"));
cls_StepGeom_Conic.def("SetPosition", (void (StepGeom_Conic::*)(const StepGeom_Axis2Placement &)) &StepGeom_Conic::SetPosition, "None", py::arg("aPosition"));
cls_StepGeom_Conic.def("Position", (StepGeom_Axis2Placement (StepGeom_Conic::*)() const) &StepGeom_Conic::Position, "None");
cls_StepGeom_Conic.def_static("get_type_name_", (const char * (*)()) &StepGeom_Conic::get_type_name, "None");
cls_StepGeom_Conic.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Conic::get_type_descriptor, "None");
cls_StepGeom_Conic.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Conic::*)() const) &StepGeom_Conic::DynamicType, "None");

// CLASS: STEPGEOM_CIRCLE
py::class_<StepGeom_Circle, opencascade::handle<StepGeom_Circle>, StepGeom_Conic> cls_StepGeom_Circle(mod, "StepGeom_Circle", "None");

// Constructors
cls_StepGeom_Circle.def(py::init<>());

// Methods
cls_StepGeom_Circle.def("Init", (void (StepGeom_Circle::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepGeom_Axis2Placement &, const Standard_Real)) &StepGeom_Circle::Init, "None", py::arg("aName"), py::arg("aPosition"), py::arg("aRadius"));
cls_StepGeom_Circle.def("SetRadius", (void (StepGeom_Circle::*)(const Standard_Real)) &StepGeom_Circle::SetRadius, "None", py::arg("aRadius"));
cls_StepGeom_Circle.def("Radius", (Standard_Real (StepGeom_Circle::*)() const) &StepGeom_Circle::Radius, "None");
cls_StepGeom_Circle.def_static("get_type_name_", (const char * (*)()) &StepGeom_Circle::get_type_name, "None");
cls_StepGeom_Circle.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Circle::get_type_descriptor, "None");
cls_StepGeom_Circle.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Circle::*)() const) &StepGeom_Circle::DynamicType, "None");

// CLASS: STEPGEOM_ELEMENTARYSURFACE
py::class_<StepGeom_ElementarySurface, opencascade::handle<StepGeom_ElementarySurface>, StepGeom_Surface> cls_StepGeom_ElementarySurface(mod, "StepGeom_ElementarySurface", "None");

// Constructors
cls_StepGeom_ElementarySurface.def(py::init<>());

// Methods
cls_StepGeom_ElementarySurface.def("Init", (void (StepGeom_ElementarySurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Axis2Placement3d> &)) &StepGeom_ElementarySurface::Init, "None", py::arg("aName"), py::arg("aPosition"));
cls_StepGeom_ElementarySurface.def("SetPosition", (void (StepGeom_ElementarySurface::*)(const opencascade::handle<StepGeom_Axis2Placement3d> &)) &StepGeom_ElementarySurface::SetPosition, "None", py::arg("aPosition"));
cls_StepGeom_ElementarySurface.def("Position", (opencascade::handle<StepGeom_Axis2Placement3d> (StepGeom_ElementarySurface::*)() const) &StepGeom_ElementarySurface::Position, "None");
cls_StepGeom_ElementarySurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_ElementarySurface::get_type_name, "None");
cls_StepGeom_ElementarySurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_ElementarySurface::get_type_descriptor, "None");
cls_StepGeom_ElementarySurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_ElementarySurface::*)() const) &StepGeom_ElementarySurface::DynamicType, "None");

// CLASS: STEPGEOM_CONICALSURFACE
py::class_<StepGeom_ConicalSurface, opencascade::handle<StepGeom_ConicalSurface>, StepGeom_ElementarySurface> cls_StepGeom_ConicalSurface(mod, "StepGeom_ConicalSurface", "None");

// Constructors
cls_StepGeom_ConicalSurface.def(py::init<>());

// Methods
cls_StepGeom_ConicalSurface.def("Init", (void (StepGeom_ConicalSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Axis2Placement3d> &, const Standard_Real, const Standard_Real)) &StepGeom_ConicalSurface::Init, "None", py::arg("aName"), py::arg("aPosition"), py::arg("aRadius"), py::arg("aSemiAngle"));
cls_StepGeom_ConicalSurface.def("SetRadius", (void (StepGeom_ConicalSurface::*)(const Standard_Real)) &StepGeom_ConicalSurface::SetRadius, "None", py::arg("aRadius"));
cls_StepGeom_ConicalSurface.def("Radius", (Standard_Real (StepGeom_ConicalSurface::*)() const) &StepGeom_ConicalSurface::Radius, "None");
cls_StepGeom_ConicalSurface.def("SetSemiAngle", (void (StepGeom_ConicalSurface::*)(const Standard_Real)) &StepGeom_ConicalSurface::SetSemiAngle, "None", py::arg("aSemiAngle"));
cls_StepGeom_ConicalSurface.def("SemiAngle", (Standard_Real (StepGeom_ConicalSurface::*)() const) &StepGeom_ConicalSurface::SemiAngle, "None");
cls_StepGeom_ConicalSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_ConicalSurface::get_type_name, "None");
cls_StepGeom_ConicalSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_ConicalSurface::get_type_descriptor, "None");
cls_StepGeom_ConicalSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_ConicalSurface::*)() const) &StepGeom_ConicalSurface::DynamicType, "None");

// CLASS: STEPGEOM_HARRAY1OFSURFACEBOUNDARY
bind_Define_HArray1<StepGeom_HArray1OfSurfaceBoundary, StepGeom_Array1OfSurfaceBoundary>(mod, "StepGeom_HArray1OfSurfaceBoundary");

// CLASS: STEPGEOM_CURVEBOUNDEDSURFACE
py::class_<StepGeom_CurveBoundedSurface, opencascade::handle<StepGeom_CurveBoundedSurface>, StepGeom_BoundedSurface> cls_StepGeom_CurveBoundedSurface(mod, "StepGeom_CurveBoundedSurface", "Representation of STEP entity CurveBoundedSurface");

// Constructors
cls_StepGeom_CurveBoundedSurface.def(py::init<>());

// Methods
cls_StepGeom_CurveBoundedSurface.def("Init", (void (StepGeom_CurveBoundedSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Surface> &, const opencascade::handle<StepGeom_HArray1OfSurfaceBoundary> &, const Standard_Boolean)) &StepGeom_CurveBoundedSurface::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aBasisSurface"), py::arg("aBoundaries"), py::arg("aImplicitOuter"));
cls_StepGeom_CurveBoundedSurface.def("BasisSurface", (opencascade::handle<StepGeom_Surface> (StepGeom_CurveBoundedSurface::*)() const) &StepGeom_CurveBoundedSurface::BasisSurface, "Returns field BasisSurface");
cls_StepGeom_CurveBoundedSurface.def("SetBasisSurface", (void (StepGeom_CurveBoundedSurface::*)(const opencascade::handle<StepGeom_Surface> &)) &StepGeom_CurveBoundedSurface::SetBasisSurface, "Set field BasisSurface", py::arg("BasisSurface"));
cls_StepGeom_CurveBoundedSurface.def("Boundaries", (opencascade::handle<StepGeom_HArray1OfSurfaceBoundary> (StepGeom_CurveBoundedSurface::*)() const) &StepGeom_CurveBoundedSurface::Boundaries, "Returns field Boundaries");
cls_StepGeom_CurveBoundedSurface.def("SetBoundaries", (void (StepGeom_CurveBoundedSurface::*)(const opencascade::handle<StepGeom_HArray1OfSurfaceBoundary> &)) &StepGeom_CurveBoundedSurface::SetBoundaries, "Set field Boundaries", py::arg("Boundaries"));
cls_StepGeom_CurveBoundedSurface.def("ImplicitOuter", (Standard_Boolean (StepGeom_CurveBoundedSurface::*)() const) &StepGeom_CurveBoundedSurface::ImplicitOuter, "Returns field ImplicitOuter");
cls_StepGeom_CurveBoundedSurface.def("SetImplicitOuter", (void (StepGeom_CurveBoundedSurface::*)(const Standard_Boolean)) &StepGeom_CurveBoundedSurface::SetImplicitOuter, "Set field ImplicitOuter", py::arg("ImplicitOuter"));
cls_StepGeom_CurveBoundedSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_CurveBoundedSurface::get_type_name, "None");
cls_StepGeom_CurveBoundedSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_CurveBoundedSurface::get_type_descriptor, "None");
cls_StepGeom_CurveBoundedSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_CurveBoundedSurface::*)() const) &StepGeom_CurveBoundedSurface::DynamicType, "None");

// CLASS: STEPGEOM_CURVEONSURFACE
py::class_<StepGeom_CurveOnSurface, StepData_SelectType> cls_StepGeom_CurveOnSurface(mod, "StepGeom_CurveOnSurface", "None");

// Constructors
cls_StepGeom_CurveOnSurface.def(py::init<>());

// Methods
// cls_StepGeom_CurveOnSurface.def_static("operator new_", (void * (*)(size_t)) &StepGeom_CurveOnSurface::operator new, "None", py::arg("theSize"));
// cls_StepGeom_CurveOnSurface.def_static("operator delete_", (void (*)(void *)) &StepGeom_CurveOnSurface::operator delete, "None", py::arg("theAddress"));
// cls_StepGeom_CurveOnSurface.def_static("operator new[]_", (void * (*)(size_t)) &StepGeom_CurveOnSurface::operator new[], "None", py::arg("theSize"));
// cls_StepGeom_CurveOnSurface.def_static("operator delete[]_", (void (*)(void *)) &StepGeom_CurveOnSurface::operator delete[], "None", py::arg("theAddress"));
// cls_StepGeom_CurveOnSurface.def_static("operator new_", (void * (*)(size_t, void *)) &StepGeom_CurveOnSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepGeom_CurveOnSurface.def_static("operator delete_", (void (*)(void *, void *)) &StepGeom_CurveOnSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_StepGeom_CurveOnSurface.def("CaseNum", (Standard_Integer (StepGeom_CurveOnSurface::*)(const opencascade::handle<Standard_Transient> &) const) &StepGeom_CurveOnSurface::CaseNum, "Recognizes a CurveOnSurface Kind Entity that is : 1 -> Pcurve 2 -> SurfaceCurve 3 -> CompositeCurveOnSurface 0 else", py::arg("ent"));
cls_StepGeom_CurveOnSurface.def("Pcurve", (opencascade::handle<StepGeom_Pcurve> (StepGeom_CurveOnSurface::*)() const) &StepGeom_CurveOnSurface::Pcurve, "returns Value as a Pcurve (Null if another type)");
cls_StepGeom_CurveOnSurface.def("SurfaceCurve", (opencascade::handle<StepGeom_SurfaceCurve> (StepGeom_CurveOnSurface::*)() const) &StepGeom_CurveOnSurface::SurfaceCurve, "returns Value as a SurfaceCurve (Null if another type)");
cls_StepGeom_CurveOnSurface.def("CompositeCurveOnSurface", (opencascade::handle<StepGeom_CompositeCurveOnSurface> (StepGeom_CurveOnSurface::*)() const) &StepGeom_CurveOnSurface::CompositeCurveOnSurface, "returns Value as a CompositeCurveOnSurface (Null if another type)");

// CLASS: STEPGEOM_CURVEREPLICA
py::class_<StepGeom_CurveReplica, opencascade::handle<StepGeom_CurveReplica>, StepGeom_Curve> cls_StepGeom_CurveReplica(mod, "StepGeom_CurveReplica", "None");

// Constructors
cls_StepGeom_CurveReplica.def(py::init<>());

// Methods
cls_StepGeom_CurveReplica.def("Init", (void (StepGeom_CurveReplica::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Curve> &, const opencascade::handle<StepGeom_CartesianTransformationOperator> &)) &StepGeom_CurveReplica::Init, "None", py::arg("aName"), py::arg("aParentCurve"), py::arg("aTransformation"));
cls_StepGeom_CurveReplica.def("SetParentCurve", (void (StepGeom_CurveReplica::*)(const opencascade::handle<StepGeom_Curve> &)) &StepGeom_CurveReplica::SetParentCurve, "None", py::arg("aParentCurve"));
cls_StepGeom_CurveReplica.def("ParentCurve", (opencascade::handle<StepGeom_Curve> (StepGeom_CurveReplica::*)() const) &StepGeom_CurveReplica::ParentCurve, "None");
cls_StepGeom_CurveReplica.def("SetTransformation", (void (StepGeom_CurveReplica::*)(const opencascade::handle<StepGeom_CartesianTransformationOperator> &)) &StepGeom_CurveReplica::SetTransformation, "None", py::arg("aTransformation"));
cls_StepGeom_CurveReplica.def("Transformation", (opencascade::handle<StepGeom_CartesianTransformationOperator> (StepGeom_CurveReplica::*)() const) &StepGeom_CurveReplica::Transformation, "None");
cls_StepGeom_CurveReplica.def_static("get_type_name_", (const char * (*)()) &StepGeom_CurveReplica::get_type_name, "None");
cls_StepGeom_CurveReplica.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_CurveReplica::get_type_descriptor, "None");
cls_StepGeom_CurveReplica.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_CurveReplica::*)() const) &StepGeom_CurveReplica::DynamicType, "None");

// CLASS: STEPGEOM_CYLINDRICALSURFACE
py::class_<StepGeom_CylindricalSurface, opencascade::handle<StepGeom_CylindricalSurface>, StepGeom_ElementarySurface> cls_StepGeom_CylindricalSurface(mod, "StepGeom_CylindricalSurface", "None");

// Constructors
cls_StepGeom_CylindricalSurface.def(py::init<>());

// Methods
cls_StepGeom_CylindricalSurface.def("Init", (void (StepGeom_CylindricalSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Axis2Placement3d> &, const Standard_Real)) &StepGeom_CylindricalSurface::Init, "None", py::arg("aName"), py::arg("aPosition"), py::arg("aRadius"));
cls_StepGeom_CylindricalSurface.def("SetRadius", (void (StepGeom_CylindricalSurface::*)(const Standard_Real)) &StepGeom_CylindricalSurface::SetRadius, "None", py::arg("aRadius"));
cls_StepGeom_CylindricalSurface.def("Radius", (Standard_Real (StepGeom_CylindricalSurface::*)() const) &StepGeom_CylindricalSurface::Radius, "None");
cls_StepGeom_CylindricalSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_CylindricalSurface::get_type_name, "None");
cls_StepGeom_CylindricalSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_CylindricalSurface::get_type_descriptor, "None");
cls_StepGeom_CylindricalSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_CylindricalSurface::*)() const) &StepGeom_CylindricalSurface::DynamicType, "None");

// CLASS: STEPGEOM_DEGENERATEPCURVE
py::class_<StepGeom_DegeneratePcurve, opencascade::handle<StepGeom_DegeneratePcurve>, StepGeom_Point> cls_StepGeom_DegeneratePcurve(mod, "StepGeom_DegeneratePcurve", "None");

// Constructors
cls_StepGeom_DegeneratePcurve.def(py::init<>());

// Methods
cls_StepGeom_DegeneratePcurve.def("Init", (void (StepGeom_DegeneratePcurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Surface> &, const opencascade::handle<StepRepr_DefinitionalRepresentation> &)) &StepGeom_DegeneratePcurve::Init, "None", py::arg("aName"), py::arg("aBasisSurface"), py::arg("aReferenceToCurve"));
cls_StepGeom_DegeneratePcurve.def("SetBasisSurface", (void (StepGeom_DegeneratePcurve::*)(const opencascade::handle<StepGeom_Surface> &)) &StepGeom_DegeneratePcurve::SetBasisSurface, "None", py::arg("aBasisSurface"));
cls_StepGeom_DegeneratePcurve.def("BasisSurface", (opencascade::handle<StepGeom_Surface> (StepGeom_DegeneratePcurve::*)() const) &StepGeom_DegeneratePcurve::BasisSurface, "None");
cls_StepGeom_DegeneratePcurve.def("SetReferenceToCurve", (void (StepGeom_DegeneratePcurve::*)(const opencascade::handle<StepRepr_DefinitionalRepresentation> &)) &StepGeom_DegeneratePcurve::SetReferenceToCurve, "None", py::arg("aReferenceToCurve"));
cls_StepGeom_DegeneratePcurve.def("ReferenceToCurve", (opencascade::handle<StepRepr_DefinitionalRepresentation> (StepGeom_DegeneratePcurve::*)() const) &StepGeom_DegeneratePcurve::ReferenceToCurve, "None");
cls_StepGeom_DegeneratePcurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_DegeneratePcurve::get_type_name, "None");
cls_StepGeom_DegeneratePcurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_DegeneratePcurve::get_type_descriptor, "None");
cls_StepGeom_DegeneratePcurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_DegeneratePcurve::*)() const) &StepGeom_DegeneratePcurve::DynamicType, "None");

// CLASS: STEPGEOM_TOROIDALSURFACE
py::class_<StepGeom_ToroidalSurface, opencascade::handle<StepGeom_ToroidalSurface>, StepGeom_ElementarySurface> cls_StepGeom_ToroidalSurface(mod, "StepGeom_ToroidalSurface", "None");

// Constructors
cls_StepGeom_ToroidalSurface.def(py::init<>());

// Methods
cls_StepGeom_ToroidalSurface.def("Init", (void (StepGeom_ToroidalSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Axis2Placement3d> &, const Standard_Real, const Standard_Real)) &StepGeom_ToroidalSurface::Init, "None", py::arg("aName"), py::arg("aPosition"), py::arg("aMajorRadius"), py::arg("aMinorRadius"));
cls_StepGeom_ToroidalSurface.def("SetMajorRadius", (void (StepGeom_ToroidalSurface::*)(const Standard_Real)) &StepGeom_ToroidalSurface::SetMajorRadius, "None", py::arg("aMajorRadius"));
cls_StepGeom_ToroidalSurface.def("MajorRadius", (Standard_Real (StepGeom_ToroidalSurface::*)() const) &StepGeom_ToroidalSurface::MajorRadius, "None");
cls_StepGeom_ToroidalSurface.def("SetMinorRadius", (void (StepGeom_ToroidalSurface::*)(const Standard_Real)) &StepGeom_ToroidalSurface::SetMinorRadius, "None", py::arg("aMinorRadius"));
cls_StepGeom_ToroidalSurface.def("MinorRadius", (Standard_Real (StepGeom_ToroidalSurface::*)() const) &StepGeom_ToroidalSurface::MinorRadius, "None");
cls_StepGeom_ToroidalSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_ToroidalSurface::get_type_name, "None");
cls_StepGeom_ToroidalSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_ToroidalSurface::get_type_descriptor, "None");
cls_StepGeom_ToroidalSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_ToroidalSurface::*)() const) &StepGeom_ToroidalSurface::DynamicType, "None");

// CLASS: STEPGEOM_DEGENERATETOROIDALSURFACE
py::class_<StepGeom_DegenerateToroidalSurface, opencascade::handle<StepGeom_DegenerateToroidalSurface>, StepGeom_ToroidalSurface> cls_StepGeom_DegenerateToroidalSurface(mod, "StepGeom_DegenerateToroidalSurface", "None");

// Constructors
cls_StepGeom_DegenerateToroidalSurface.def(py::init<>());

// Methods
cls_StepGeom_DegenerateToroidalSurface.def("Init", (void (StepGeom_DegenerateToroidalSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Axis2Placement3d> &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &StepGeom_DegenerateToroidalSurface::Init, "None", py::arg("aName"), py::arg("aPosition"), py::arg("aMajorRadius"), py::arg("aMinorRadius"), py::arg("aSelectOuter"));
cls_StepGeom_DegenerateToroidalSurface.def("SetSelectOuter", (void (StepGeom_DegenerateToroidalSurface::*)(const Standard_Boolean)) &StepGeom_DegenerateToroidalSurface::SetSelectOuter, "None", py::arg("aSelectOuter"));
cls_StepGeom_DegenerateToroidalSurface.def("SelectOuter", (Standard_Boolean (StepGeom_DegenerateToroidalSurface::*)() const) &StepGeom_DegenerateToroidalSurface::SelectOuter, "None");
cls_StepGeom_DegenerateToroidalSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_DegenerateToroidalSurface::get_type_name, "None");
cls_StepGeom_DegenerateToroidalSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_DegenerateToroidalSurface::get_type_descriptor, "None");
cls_StepGeom_DegenerateToroidalSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_DegenerateToroidalSurface::*)() const) &StepGeom_DegenerateToroidalSurface::DynamicType, "None");

// CLASS: STEPGEOM_DIRECTION
py::class_<StepGeom_Direction, opencascade::handle<StepGeom_Direction>, StepGeom_GeometricRepresentationItem> cls_StepGeom_Direction(mod, "StepGeom_Direction", "None");

// Constructors
cls_StepGeom_Direction.def(py::init<>());

// Methods
cls_StepGeom_Direction.def("Init", (void (StepGeom_Direction::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_Direction::Init, "None", py::arg("aName"), py::arg("aDirectionRatios"));
cls_StepGeom_Direction.def("SetDirectionRatios", (void (StepGeom_Direction::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_Direction::SetDirectionRatios, "None", py::arg("aDirectionRatios"));
cls_StepGeom_Direction.def("DirectionRatios", (opencascade::handle<TColStd_HArray1OfReal> (StepGeom_Direction::*)() const) &StepGeom_Direction::DirectionRatios, "None");
cls_StepGeom_Direction.def("DirectionRatiosValue", (Standard_Real (StepGeom_Direction::*)(const Standard_Integer) const) &StepGeom_Direction::DirectionRatiosValue, "None", py::arg("num"));
cls_StepGeom_Direction.def("NbDirectionRatios", (Standard_Integer (StepGeom_Direction::*)() const) &StepGeom_Direction::NbDirectionRatios, "None");
cls_StepGeom_Direction.def_static("get_type_name_", (const char * (*)()) &StepGeom_Direction::get_type_name, "None");
cls_StepGeom_Direction.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Direction::get_type_descriptor, "None");
cls_StepGeom_Direction.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Direction::*)() const) &StepGeom_Direction::DynamicType, "None");

// CLASS: STEPGEOM_ELLIPSE
py::class_<StepGeom_Ellipse, opencascade::handle<StepGeom_Ellipse>, StepGeom_Conic> cls_StepGeom_Ellipse(mod, "StepGeom_Ellipse", "None");

// Constructors
cls_StepGeom_Ellipse.def(py::init<>());

// Methods
cls_StepGeom_Ellipse.def("Init", (void (StepGeom_Ellipse::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepGeom_Axis2Placement &, const Standard_Real, const Standard_Real)) &StepGeom_Ellipse::Init, "None", py::arg("aName"), py::arg("aPosition"), py::arg("aSemiAxis1"), py::arg("aSemiAxis2"));
cls_StepGeom_Ellipse.def("SetSemiAxis1", (void (StepGeom_Ellipse::*)(const Standard_Real)) &StepGeom_Ellipse::SetSemiAxis1, "None", py::arg("aSemiAxis1"));
cls_StepGeom_Ellipse.def("SemiAxis1", (Standard_Real (StepGeom_Ellipse::*)() const) &StepGeom_Ellipse::SemiAxis1, "None");
cls_StepGeom_Ellipse.def("SetSemiAxis2", (void (StepGeom_Ellipse::*)(const Standard_Real)) &StepGeom_Ellipse::SetSemiAxis2, "None", py::arg("aSemiAxis2"));
cls_StepGeom_Ellipse.def("SemiAxis2", (Standard_Real (StepGeom_Ellipse::*)() const) &StepGeom_Ellipse::SemiAxis2, "None");
cls_StepGeom_Ellipse.def_static("get_type_name_", (const char * (*)()) &StepGeom_Ellipse::get_type_name, "None");
cls_StepGeom_Ellipse.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Ellipse::get_type_descriptor, "None");
cls_StepGeom_Ellipse.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Ellipse::*)() const) &StepGeom_Ellipse::DynamicType, "None");

// CLASS: STEPGEOM_EVALUATEDDEGENERATEPCURVE
py::class_<StepGeom_EvaluatedDegeneratePcurve, opencascade::handle<StepGeom_EvaluatedDegeneratePcurve>, StepGeom_DegeneratePcurve> cls_StepGeom_EvaluatedDegeneratePcurve(mod, "StepGeom_EvaluatedDegeneratePcurve", "None");

// Constructors
cls_StepGeom_EvaluatedDegeneratePcurve.def(py::init<>());

// Methods
cls_StepGeom_EvaluatedDegeneratePcurve.def("Init", (void (StepGeom_EvaluatedDegeneratePcurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Surface> &, const opencascade::handle<StepRepr_DefinitionalRepresentation> &, const opencascade::handle<StepGeom_CartesianPoint> &)) &StepGeom_EvaluatedDegeneratePcurve::Init, "None", py::arg("aName"), py::arg("aBasisSurface"), py::arg("aReferenceToCurve"), py::arg("aEquivalentPoint"));
cls_StepGeom_EvaluatedDegeneratePcurve.def("SetEquivalentPoint", (void (StepGeom_EvaluatedDegeneratePcurve::*)(const opencascade::handle<StepGeom_CartesianPoint> &)) &StepGeom_EvaluatedDegeneratePcurve::SetEquivalentPoint, "None", py::arg("aEquivalentPoint"));
cls_StepGeom_EvaluatedDegeneratePcurve.def("EquivalentPoint", (opencascade::handle<StepGeom_CartesianPoint> (StepGeom_EvaluatedDegeneratePcurve::*)() const) &StepGeom_EvaluatedDegeneratePcurve::EquivalentPoint, "None");
cls_StepGeom_EvaluatedDegeneratePcurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_EvaluatedDegeneratePcurve::get_type_name, "None");
cls_StepGeom_EvaluatedDegeneratePcurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_EvaluatedDegeneratePcurve::get_type_descriptor, "None");
cls_StepGeom_EvaluatedDegeneratePcurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_EvaluatedDegeneratePcurve::*)() const) &StepGeom_EvaluatedDegeneratePcurve::DynamicType, "None");

// CLASS: STEPGEOM_GEOMETRICREPRESENTATIONCONTEXT
py::class_<StepGeom_GeometricRepresentationContext, opencascade::handle<StepGeom_GeometricRepresentationContext>, StepRepr_RepresentationContext> cls_StepGeom_GeometricRepresentationContext(mod, "StepGeom_GeometricRepresentationContext", "None");

// Constructors
cls_StepGeom_GeometricRepresentationContext.def(py::init<>());

// Methods
cls_StepGeom_GeometricRepresentationContext.def("Init", (void (StepGeom_GeometricRepresentationContext::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer)) &StepGeom_GeometricRepresentationContext::Init, "None", py::arg("aContextIdentifier"), py::arg("aContextType"), py::arg("aCoordinateSpaceDimension"));
cls_StepGeom_GeometricRepresentationContext.def("SetCoordinateSpaceDimension", (void (StepGeom_GeometricRepresentationContext::*)(const Standard_Integer)) &StepGeom_GeometricRepresentationContext::SetCoordinateSpaceDimension, "None", py::arg("aCoordinateSpaceDimension"));
cls_StepGeom_GeometricRepresentationContext.def("CoordinateSpaceDimension", (Standard_Integer (StepGeom_GeometricRepresentationContext::*)() const) &StepGeom_GeometricRepresentationContext::CoordinateSpaceDimension, "None");
cls_StepGeom_GeometricRepresentationContext.def_static("get_type_name_", (const char * (*)()) &StepGeom_GeometricRepresentationContext::get_type_name, "None");
cls_StepGeom_GeometricRepresentationContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_GeometricRepresentationContext::get_type_descriptor, "None");
cls_StepGeom_GeometricRepresentationContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_GeometricRepresentationContext::*)() const) &StepGeom_GeometricRepresentationContext::DynamicType, "None");

// CLASS: STEPGEOM_GEOMETRICREPRESENTATIONCONTEXTANDGLOBALUNITASSIGNEDCONTEXT
py::class_<StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext, opencascade::handle<StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext>, StepRepr_RepresentationContext> cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext(mod, "StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext", "None");

// Constructors
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def(py::init<>());

// Methods
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def("Init", (void (StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_GeometricRepresentationContext> &, const opencascade::handle<StepRepr_GlobalUnitAssignedContext> &)) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::Init, "None", py::arg("aContextIdentifier"), py::arg("aContextType"), py::arg("aGeometricRepresentationContext"), py::arg("aGlobalUnitAssignedContext"));
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def("Init", (void (StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepBasic_HArray1OfNamedUnit> &)) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::Init, "None", py::arg("aContextIdentifier"), py::arg("aContextType"), py::arg("aCoordinateSpaceDimension"), py::arg("aUnits"));
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def("SetGeometricRepresentationContext", (void (StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::*)(const opencascade::handle<StepGeom_GeometricRepresentationContext> &)) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::SetGeometricRepresentationContext, "None", py::arg("aGeometricRepresentationContext"));
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def("GeometricRepresentationContext", (opencascade::handle<StepGeom_GeometricRepresentationContext> (StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::*)() const) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::GeometricRepresentationContext, "None");
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def("SetGlobalUnitAssignedContext", (void (StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::*)(const opencascade::handle<StepRepr_GlobalUnitAssignedContext> &)) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::SetGlobalUnitAssignedContext, "None", py::arg("aGlobalUnitAssignedContext"));
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def("GlobalUnitAssignedContext", (opencascade::handle<StepRepr_GlobalUnitAssignedContext> (StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::*)() const) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::GlobalUnitAssignedContext, "None");
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def("SetCoordinateSpaceDimension", (void (StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::*)(const Standard_Integer)) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::SetCoordinateSpaceDimension, "None", py::arg("aCoordinateSpaceDimension"));
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def("CoordinateSpaceDimension", (Standard_Integer (StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::*)() const) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::CoordinateSpaceDimension, "None");
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def("SetUnits", (void (StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::*)(const opencascade::handle<StepBasic_HArray1OfNamedUnit> &)) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::SetUnits, "None", py::arg("aUnits"));
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def("Units", (opencascade::handle<StepBasic_HArray1OfNamedUnit> (StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::*)() const) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::Units, "None");
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def("UnitsValue", (opencascade::handle<StepBasic_NamedUnit> (StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::*)(const Standard_Integer) const) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::UnitsValue, "None", py::arg("num"));
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def("NbUnits", (Standard_Integer (StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::*)() const) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::NbUnits, "None");
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def_static("get_type_name_", (const char * (*)()) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::get_type_name, "None");
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::get_type_descriptor, "None");
cls_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::*)() const) &StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext::DynamicType, "None");

// CLASS: STEPGEOM_GEOMETRICREPRESENTATIONCONTEXTANDPARAMETRICREPRESENTATIONCONTEXT
py::class_<StepGeom_GeometricRepresentationContextAndParametricRepresentationContext, opencascade::handle<StepGeom_GeometricRepresentationContextAndParametricRepresentationContext>, StepRepr_RepresentationContext> cls_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext(mod, "StepGeom_GeometricRepresentationContextAndParametricRepresentationContext", "None");

// Constructors
cls_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext.def(py::init<>());

// Methods
cls_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext.def("Init", (void (StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_GeometricRepresentationContext> &, const opencascade::handle<StepRepr_ParametricRepresentationContext> &)) &StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::Init, "None", py::arg("aContextIdentifier"), py::arg("aContextType"), py::arg("aGeometricRepresentationContext"), py::arg("aParametricRepresentationContext"));
cls_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext.def("Init", (void (StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer)) &StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::Init, "None", py::arg("aContextIdentifier"), py::arg("aContextType"), py::arg("aCoordinateSpaceDimension"));
cls_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext.def("SetGeometricRepresentationContext", (void (StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::*)(const opencascade::handle<StepGeom_GeometricRepresentationContext> &)) &StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::SetGeometricRepresentationContext, "None", py::arg("aGeometricRepresentationContext"));
cls_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext.def("GeometricRepresentationContext", (opencascade::handle<StepGeom_GeometricRepresentationContext> (StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::*)() const) &StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::GeometricRepresentationContext, "None");
cls_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext.def("SetParametricRepresentationContext", (void (StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::*)(const opencascade::handle<StepRepr_ParametricRepresentationContext> &)) &StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::SetParametricRepresentationContext, "None", py::arg("aParametricRepresentationContext"));
cls_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext.def("ParametricRepresentationContext", (opencascade::handle<StepRepr_ParametricRepresentationContext> (StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::*)() const) &StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::ParametricRepresentationContext, "None");
cls_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext.def("SetCoordinateSpaceDimension", (void (StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::*)(const Standard_Integer)) &StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::SetCoordinateSpaceDimension, "None", py::arg("aCoordinateSpaceDimension"));
cls_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext.def("CoordinateSpaceDimension", (Standard_Integer (StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::*)() const) &StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::CoordinateSpaceDimension, "None");
cls_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext.def_static("get_type_name_", (const char * (*)()) &StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::get_type_name, "None");
cls_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::get_type_descriptor, "None");
cls_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::*)() const) &StepGeom_GeometricRepresentationContextAndParametricRepresentationContext::DynamicType, "None");

// CLASS: STEPGEOM_GEOMREPCONTEXTANDGLOBUNITASSCTXANDGLOBUNCERTAINTYASSCTX
py::class_<StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx, opencascade::handle<StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx>, StepRepr_RepresentationContext> cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx(mod, "StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx", "None");

// Constructors
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def(py::init<>());

// Methods
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("Init", (void (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_GeometricRepresentationContext> &, const opencascade::handle<StepRepr_GlobalUnitAssignedContext> &, const opencascade::handle<StepRepr_GlobalUncertaintyAssignedContext> &)) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::Init, "None", py::arg("aContextIdentifier"), py::arg("aContextType"), py::arg("aGeometricRepresentationCtx"), py::arg("aGlobalUnitAssignedCtx"), py::arg("aGlobalUncertaintyAssignedCtx"));
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("Init", (void (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepBasic_HArray1OfNamedUnit> &, const opencascade::handle<StepBasic_HArray1OfUncertaintyMeasureWithUnit> &)) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::Init, "None", py::arg("aContextIdentifier"), py::arg("aContextType"), py::arg("aCoordinateSpaceDimension"), py::arg("aUnits"), py::arg("anUncertainty"));
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("SetGeometricRepresentationContext", (void (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)(const opencascade::handle<StepGeom_GeometricRepresentationContext> &)) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::SetGeometricRepresentationContext, "None", py::arg("aGeometricRepresentationContext"));
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("GeometricRepresentationContext", (opencascade::handle<StepGeom_GeometricRepresentationContext> (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)() const) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::GeometricRepresentationContext, "None");
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("SetGlobalUnitAssignedContext", (void (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)(const opencascade::handle<StepRepr_GlobalUnitAssignedContext> &)) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::SetGlobalUnitAssignedContext, "None", py::arg("aGlobalUnitAssignedContext"));
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("GlobalUnitAssignedContext", (opencascade::handle<StepRepr_GlobalUnitAssignedContext> (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)() const) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::GlobalUnitAssignedContext, "None");
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("SetGlobalUncertaintyAssignedContext", (void (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)(const opencascade::handle<StepRepr_GlobalUncertaintyAssignedContext> &)) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::SetGlobalUncertaintyAssignedContext, "None", py::arg("aGlobalUncertaintyAssignedCtx"));
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("GlobalUncertaintyAssignedContext", (opencascade::handle<StepRepr_GlobalUncertaintyAssignedContext> (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)() const) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::GlobalUncertaintyAssignedContext, "None");
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("SetCoordinateSpaceDimension", (void (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)(const Standard_Integer)) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::SetCoordinateSpaceDimension, "None", py::arg("aCoordinateSpaceDimension"));
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("CoordinateSpaceDimension", (Standard_Integer (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)() const) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::CoordinateSpaceDimension, "None");
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("SetUnits", (void (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)(const opencascade::handle<StepBasic_HArray1OfNamedUnit> &)) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::SetUnits, "None", py::arg("aUnits"));
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("Units", (opencascade::handle<StepBasic_HArray1OfNamedUnit> (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)() const) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::Units, "None");
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("UnitsValue", (opencascade::handle<StepBasic_NamedUnit> (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)(const Standard_Integer) const) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::UnitsValue, "None", py::arg("num"));
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("NbUnits", (Standard_Integer (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)() const) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::NbUnits, "None");
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("SetUncertainty", (void (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)(const opencascade::handle<StepBasic_HArray1OfUncertaintyMeasureWithUnit> &)) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::SetUncertainty, "None", py::arg("aUncertainty"));
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("Uncertainty", (opencascade::handle<StepBasic_HArray1OfUncertaintyMeasureWithUnit> (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)() const) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::Uncertainty, "None");
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("UncertaintyValue", (opencascade::handle<StepBasic_UncertaintyMeasureWithUnit> (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)(const Standard_Integer) const) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::UncertaintyValue, "None", py::arg("num"));
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("NbUncertainty", (Standard_Integer (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)() const) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::NbUncertainty, "None");
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def_static("get_type_name_", (const char * (*)()) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::get_type_name, "None");
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::get_type_descriptor, "None");
cls_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::*)() const) &StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx::DynamicType, "None");

// CLASS: STEPGEOM_HARRAY1OFBOUNDARYCURVE
bind_Define_HArray1<StepGeom_HArray1OfBoundaryCurve, StepGeom_Array1OfBoundaryCurve>(mod, "StepGeom_HArray1OfBoundaryCurve");

// CLASS: STEPGEOM_HARRAY1OFCURVE
bind_Define_HArray1<StepGeom_HArray1OfCurve, StepGeom_Array1OfCurve>(mod, "StepGeom_HArray1OfCurve");

// CLASS: STEPGEOM_HARRAY1OFPCURVEORSURFACE
bind_Define_HArray1<StepGeom_HArray1OfPcurveOrSurface, StepGeom_Array1OfPcurveOrSurface>(mod, "StepGeom_HArray1OfPcurveOrSurface");

// CLASS: STEPGEOM_HARRAY1OFTRIMMINGSELECT
bind_Define_HArray1<StepGeom_HArray1OfTrimmingSelect, StepGeom_Array1OfTrimmingSelect>(mod, "StepGeom_HArray1OfTrimmingSelect");

// CLASS: STEPGEOM_HARRAY2OFSURFACEPATCH
bind_Define_HArray2<StepGeom_HArray2OfSurfacePatch, StepGeom_Array2OfSurfacePatch>(mod, "StepGeom_HArray2OfSurfacePatch");

// CLASS: STEPGEOM_HYPERBOLA
py::class_<StepGeom_Hyperbola, opencascade::handle<StepGeom_Hyperbola>, StepGeom_Conic> cls_StepGeom_Hyperbola(mod, "StepGeom_Hyperbola", "None");

// Constructors
cls_StepGeom_Hyperbola.def(py::init<>());

// Methods
cls_StepGeom_Hyperbola.def("Init", (void (StepGeom_Hyperbola::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepGeom_Axis2Placement &, const Standard_Real, const Standard_Real)) &StepGeom_Hyperbola::Init, "None", py::arg("aName"), py::arg("aPosition"), py::arg("aSemiAxis"), py::arg("aSemiImagAxis"));
cls_StepGeom_Hyperbola.def("SetSemiAxis", (void (StepGeom_Hyperbola::*)(const Standard_Real)) &StepGeom_Hyperbola::SetSemiAxis, "None", py::arg("aSemiAxis"));
cls_StepGeom_Hyperbola.def("SemiAxis", (Standard_Real (StepGeom_Hyperbola::*)() const) &StepGeom_Hyperbola::SemiAxis, "None");
cls_StepGeom_Hyperbola.def("SetSemiImagAxis", (void (StepGeom_Hyperbola::*)(const Standard_Real)) &StepGeom_Hyperbola::SetSemiImagAxis, "None", py::arg("aSemiImagAxis"));
cls_StepGeom_Hyperbola.def("SemiImagAxis", (Standard_Real (StepGeom_Hyperbola::*)() const) &StepGeom_Hyperbola::SemiImagAxis, "None");
cls_StepGeom_Hyperbola.def_static("get_type_name_", (const char * (*)()) &StepGeom_Hyperbola::get_type_name, "None");
cls_StepGeom_Hyperbola.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Hyperbola::get_type_descriptor, "None");
cls_StepGeom_Hyperbola.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Hyperbola::*)() const) &StepGeom_Hyperbola::DynamicType, "None");

// CLASS: STEPGEOM_SURFACECURVE
py::class_<StepGeom_SurfaceCurve, opencascade::handle<StepGeom_SurfaceCurve>, StepGeom_Curve> cls_StepGeom_SurfaceCurve(mod, "StepGeom_SurfaceCurve", "None");

// Constructors
cls_StepGeom_SurfaceCurve.def(py::init<>());

// Methods
cls_StepGeom_SurfaceCurve.def("Init", (void (StepGeom_SurfaceCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Curve> &, const opencascade::handle<StepGeom_HArray1OfPcurveOrSurface> &, const StepGeom_PreferredSurfaceCurveRepresentation)) &StepGeom_SurfaceCurve::Init, "None", py::arg("aName"), py::arg("aCurve3d"), py::arg("aAssociatedGeometry"), py::arg("aMasterRepresentation"));
cls_StepGeom_SurfaceCurve.def("SetCurve3d", (void (StepGeom_SurfaceCurve::*)(const opencascade::handle<StepGeom_Curve> &)) &StepGeom_SurfaceCurve::SetCurve3d, "None", py::arg("aCurve3d"));
cls_StepGeom_SurfaceCurve.def("Curve3d", (opencascade::handle<StepGeom_Curve> (StepGeom_SurfaceCurve::*)() const) &StepGeom_SurfaceCurve::Curve3d, "None");
cls_StepGeom_SurfaceCurve.def("SetAssociatedGeometry", (void (StepGeom_SurfaceCurve::*)(const opencascade::handle<StepGeom_HArray1OfPcurveOrSurface> &)) &StepGeom_SurfaceCurve::SetAssociatedGeometry, "None", py::arg("aAssociatedGeometry"));
cls_StepGeom_SurfaceCurve.def("AssociatedGeometry", (opencascade::handle<StepGeom_HArray1OfPcurveOrSurface> (StepGeom_SurfaceCurve::*)() const) &StepGeom_SurfaceCurve::AssociatedGeometry, "None");
cls_StepGeom_SurfaceCurve.def("AssociatedGeometryValue", (StepGeom_PcurveOrSurface (StepGeom_SurfaceCurve::*)(const Standard_Integer) const) &StepGeom_SurfaceCurve::AssociatedGeometryValue, "None", py::arg("num"));
cls_StepGeom_SurfaceCurve.def("NbAssociatedGeometry", (Standard_Integer (StepGeom_SurfaceCurve::*)() const) &StepGeom_SurfaceCurve::NbAssociatedGeometry, "None");
cls_StepGeom_SurfaceCurve.def("SetMasterRepresentation", (void (StepGeom_SurfaceCurve::*)(const StepGeom_PreferredSurfaceCurveRepresentation)) &StepGeom_SurfaceCurve::SetMasterRepresentation, "None", py::arg("aMasterRepresentation"));
cls_StepGeom_SurfaceCurve.def("MasterRepresentation", (StepGeom_PreferredSurfaceCurveRepresentation (StepGeom_SurfaceCurve::*)() const) &StepGeom_SurfaceCurve::MasterRepresentation, "None");
cls_StepGeom_SurfaceCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_SurfaceCurve::get_type_name, "None");
cls_StepGeom_SurfaceCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_SurfaceCurve::get_type_descriptor, "None");
cls_StepGeom_SurfaceCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_SurfaceCurve::*)() const) &StepGeom_SurfaceCurve::DynamicType, "None");

// CLASS: STEPGEOM_INTERSECTIONCURVE
py::class_<StepGeom_IntersectionCurve, opencascade::handle<StepGeom_IntersectionCurve>, StepGeom_SurfaceCurve> cls_StepGeom_IntersectionCurve(mod, "StepGeom_IntersectionCurve", "None");

// Constructors
cls_StepGeom_IntersectionCurve.def(py::init<>());

// Methods
cls_StepGeom_IntersectionCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_IntersectionCurve::get_type_name, "None");
cls_StepGeom_IntersectionCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_IntersectionCurve::get_type_descriptor, "None");
cls_StepGeom_IntersectionCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_IntersectionCurve::*)() const) &StepGeom_IntersectionCurve::DynamicType, "None");

// CLASS: STEPGEOM_LINE
py::class_<StepGeom_Line, opencascade::handle<StepGeom_Line>, StepGeom_Curve> cls_StepGeom_Line(mod, "StepGeom_Line", "None");

// Constructors
cls_StepGeom_Line.def(py::init<>());

// Methods
cls_StepGeom_Line.def("Init", (void (StepGeom_Line::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_CartesianPoint> &, const opencascade::handle<StepGeom_Vector> &)) &StepGeom_Line::Init, "None", py::arg("aName"), py::arg("aPnt"), py::arg("aDir"));
cls_StepGeom_Line.def("SetPnt", (void (StepGeom_Line::*)(const opencascade::handle<StepGeom_CartesianPoint> &)) &StepGeom_Line::SetPnt, "None", py::arg("aPnt"));
cls_StepGeom_Line.def("Pnt", (opencascade::handle<StepGeom_CartesianPoint> (StepGeom_Line::*)() const) &StepGeom_Line::Pnt, "None");
cls_StepGeom_Line.def("SetDir", (void (StepGeom_Line::*)(const opencascade::handle<StepGeom_Vector> &)) &StepGeom_Line::SetDir, "None", py::arg("aDir"));
cls_StepGeom_Line.def("Dir", (opencascade::handle<StepGeom_Vector> (StepGeom_Line::*)() const) &StepGeom_Line::Dir, "None");
cls_StepGeom_Line.def_static("get_type_name_", (const char * (*)()) &StepGeom_Line::get_type_name, "None");
cls_StepGeom_Line.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Line::get_type_descriptor, "None");
cls_StepGeom_Line.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Line::*)() const) &StepGeom_Line::DynamicType, "None");

// CLASS: STEPGEOM_OFFSETCURVE3D
py::class_<StepGeom_OffsetCurve3d, opencascade::handle<StepGeom_OffsetCurve3d>, StepGeom_Curve> cls_StepGeom_OffsetCurve3d(mod, "StepGeom_OffsetCurve3d", "None");

// Constructors
cls_StepGeom_OffsetCurve3d.def(py::init<>());

// Methods
cls_StepGeom_OffsetCurve3d.def("Init", (void (StepGeom_OffsetCurve3d::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Curve> &, const Standard_Real, const StepData_Logical, const opencascade::handle<StepGeom_Direction> &)) &StepGeom_OffsetCurve3d::Init, "None", py::arg("aName"), py::arg("aBasisCurve"), py::arg("aDistance"), py::arg("aSelfIntersect"), py::arg("aRefDirection"));
cls_StepGeom_OffsetCurve3d.def("SetBasisCurve", (void (StepGeom_OffsetCurve3d::*)(const opencascade::handle<StepGeom_Curve> &)) &StepGeom_OffsetCurve3d::SetBasisCurve, "None", py::arg("aBasisCurve"));
cls_StepGeom_OffsetCurve3d.def("BasisCurve", (opencascade::handle<StepGeom_Curve> (StepGeom_OffsetCurve3d::*)() const) &StepGeom_OffsetCurve3d::BasisCurve, "None");
cls_StepGeom_OffsetCurve3d.def("SetDistance", (void (StepGeom_OffsetCurve3d::*)(const Standard_Real)) &StepGeom_OffsetCurve3d::SetDistance, "None", py::arg("aDistance"));
cls_StepGeom_OffsetCurve3d.def("Distance", (Standard_Real (StepGeom_OffsetCurve3d::*)() const) &StepGeom_OffsetCurve3d::Distance, "None");
cls_StepGeom_OffsetCurve3d.def("SetSelfIntersect", (void (StepGeom_OffsetCurve3d::*)(const StepData_Logical)) &StepGeom_OffsetCurve3d::SetSelfIntersect, "None", py::arg("aSelfIntersect"));
cls_StepGeom_OffsetCurve3d.def("SelfIntersect", (StepData_Logical (StepGeom_OffsetCurve3d::*)() const) &StepGeom_OffsetCurve3d::SelfIntersect, "None");
cls_StepGeom_OffsetCurve3d.def("SetRefDirection", (void (StepGeom_OffsetCurve3d::*)(const opencascade::handle<StepGeom_Direction> &)) &StepGeom_OffsetCurve3d::SetRefDirection, "None", py::arg("aRefDirection"));
cls_StepGeom_OffsetCurve3d.def("RefDirection", (opencascade::handle<StepGeom_Direction> (StepGeom_OffsetCurve3d::*)() const) &StepGeom_OffsetCurve3d::RefDirection, "None");
cls_StepGeom_OffsetCurve3d.def_static("get_type_name_", (const char * (*)()) &StepGeom_OffsetCurve3d::get_type_name, "None");
cls_StepGeom_OffsetCurve3d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_OffsetCurve3d::get_type_descriptor, "None");
cls_StepGeom_OffsetCurve3d.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_OffsetCurve3d::*)() const) &StepGeom_OffsetCurve3d::DynamicType, "None");

// CLASS: STEPGEOM_OFFSETSURFACE
py::class_<StepGeom_OffsetSurface, opencascade::handle<StepGeom_OffsetSurface>, StepGeom_Surface> cls_StepGeom_OffsetSurface(mod, "StepGeom_OffsetSurface", "None");

// Constructors
cls_StepGeom_OffsetSurface.def(py::init<>());

// Methods
cls_StepGeom_OffsetSurface.def("Init", (void (StepGeom_OffsetSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Surface> &, const Standard_Real, const StepData_Logical)) &StepGeom_OffsetSurface::Init, "None", py::arg("aName"), py::arg("aBasisSurface"), py::arg("aDistance"), py::arg("aSelfIntersect"));
cls_StepGeom_OffsetSurface.def("SetBasisSurface", (void (StepGeom_OffsetSurface::*)(const opencascade::handle<StepGeom_Surface> &)) &StepGeom_OffsetSurface::SetBasisSurface, "None", py::arg("aBasisSurface"));
cls_StepGeom_OffsetSurface.def("BasisSurface", (opencascade::handle<StepGeom_Surface> (StepGeom_OffsetSurface::*)() const) &StepGeom_OffsetSurface::BasisSurface, "None");
cls_StepGeom_OffsetSurface.def("SetDistance", (void (StepGeom_OffsetSurface::*)(const Standard_Real)) &StepGeom_OffsetSurface::SetDistance, "None", py::arg("aDistance"));
cls_StepGeom_OffsetSurface.def("Distance", (Standard_Real (StepGeom_OffsetSurface::*)() const) &StepGeom_OffsetSurface::Distance, "None");
cls_StepGeom_OffsetSurface.def("SetSelfIntersect", (void (StepGeom_OffsetSurface::*)(const StepData_Logical)) &StepGeom_OffsetSurface::SetSelfIntersect, "None", py::arg("aSelfIntersect"));
cls_StepGeom_OffsetSurface.def("SelfIntersect", (StepData_Logical (StepGeom_OffsetSurface::*)() const) &StepGeom_OffsetSurface::SelfIntersect, "None");
cls_StepGeom_OffsetSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_OffsetSurface::get_type_name, "None");
cls_StepGeom_OffsetSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_OffsetSurface::get_type_descriptor, "None");
cls_StepGeom_OffsetSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_OffsetSurface::*)() const) &StepGeom_OffsetSurface::DynamicType, "None");

// CLASS: STEPGEOM_ORIENTEDSURFACE
py::class_<StepGeom_OrientedSurface, opencascade::handle<StepGeom_OrientedSurface>, StepGeom_Surface> cls_StepGeom_OrientedSurface(mod, "StepGeom_OrientedSurface", "Representation of STEP entity OrientedSurface");

// Constructors
cls_StepGeom_OrientedSurface.def(py::init<>());

// Methods
cls_StepGeom_OrientedSurface.def("Init", (void (StepGeom_OrientedSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean)) &StepGeom_OrientedSurface::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aOrientation"));
cls_StepGeom_OrientedSurface.def("Orientation", (Standard_Boolean (StepGeom_OrientedSurface::*)() const) &StepGeom_OrientedSurface::Orientation, "Returns field Orientation");
cls_StepGeom_OrientedSurface.def("SetOrientation", (void (StepGeom_OrientedSurface::*)(const Standard_Boolean)) &StepGeom_OrientedSurface::SetOrientation, "Set field Orientation", py::arg("Orientation"));
cls_StepGeom_OrientedSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_OrientedSurface::get_type_name, "None");
cls_StepGeom_OrientedSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_OrientedSurface::get_type_descriptor, "None");
cls_StepGeom_OrientedSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_OrientedSurface::*)() const) &StepGeom_OrientedSurface::DynamicType, "None");

// CLASS: STEPGEOM_OUTERBOUNDARYCURVE
py::class_<StepGeom_OuterBoundaryCurve, opencascade::handle<StepGeom_OuterBoundaryCurve>, StepGeom_BoundaryCurve> cls_StepGeom_OuterBoundaryCurve(mod, "StepGeom_OuterBoundaryCurve", "None");

// Constructors
cls_StepGeom_OuterBoundaryCurve.def(py::init<>());

// Methods
cls_StepGeom_OuterBoundaryCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_OuterBoundaryCurve::get_type_name, "None");
cls_StepGeom_OuterBoundaryCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_OuterBoundaryCurve::get_type_descriptor, "None");
cls_StepGeom_OuterBoundaryCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_OuterBoundaryCurve::*)() const) &StepGeom_OuterBoundaryCurve::DynamicType, "None");

// CLASS: STEPGEOM_PARABOLA
py::class_<StepGeom_Parabola, opencascade::handle<StepGeom_Parabola>, StepGeom_Conic> cls_StepGeom_Parabola(mod, "StepGeom_Parabola", "None");

// Constructors
cls_StepGeom_Parabola.def(py::init<>());

// Methods
cls_StepGeom_Parabola.def("Init", (void (StepGeom_Parabola::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepGeom_Axis2Placement &, const Standard_Real)) &StepGeom_Parabola::Init, "None", py::arg("aName"), py::arg("aPosition"), py::arg("aFocalDist"));
cls_StepGeom_Parabola.def("SetFocalDist", (void (StepGeom_Parabola::*)(const Standard_Real)) &StepGeom_Parabola::SetFocalDist, "None", py::arg("aFocalDist"));
cls_StepGeom_Parabola.def("FocalDist", (Standard_Real (StepGeom_Parabola::*)() const) &StepGeom_Parabola::FocalDist, "None");
cls_StepGeom_Parabola.def_static("get_type_name_", (const char * (*)()) &StepGeom_Parabola::get_type_name, "None");
cls_StepGeom_Parabola.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Parabola::get_type_descriptor, "None");
cls_StepGeom_Parabola.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Parabola::*)() const) &StepGeom_Parabola::DynamicType, "None");

// CLASS: STEPGEOM_PCURVE
py::class_<StepGeom_Pcurve, opencascade::handle<StepGeom_Pcurve>, StepGeom_Curve> cls_StepGeom_Pcurve(mod, "StepGeom_Pcurve", "None");

// Constructors
cls_StepGeom_Pcurve.def(py::init<>());

// Methods
cls_StepGeom_Pcurve.def("Init", (void (StepGeom_Pcurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Surface> &, const opencascade::handle<StepRepr_DefinitionalRepresentation> &)) &StepGeom_Pcurve::Init, "None", py::arg("aName"), py::arg("aBasisSurface"), py::arg("aReferenceToCurve"));
cls_StepGeom_Pcurve.def("SetBasisSurface", (void (StepGeom_Pcurve::*)(const opencascade::handle<StepGeom_Surface> &)) &StepGeom_Pcurve::SetBasisSurface, "None", py::arg("aBasisSurface"));
cls_StepGeom_Pcurve.def("BasisSurface", (opencascade::handle<StepGeom_Surface> (StepGeom_Pcurve::*)() const) &StepGeom_Pcurve::BasisSurface, "None");
cls_StepGeom_Pcurve.def("SetReferenceToCurve", (void (StepGeom_Pcurve::*)(const opencascade::handle<StepRepr_DefinitionalRepresentation> &)) &StepGeom_Pcurve::SetReferenceToCurve, "None", py::arg("aReferenceToCurve"));
cls_StepGeom_Pcurve.def("ReferenceToCurve", (opencascade::handle<StepRepr_DefinitionalRepresentation> (StepGeom_Pcurve::*)() const) &StepGeom_Pcurve::ReferenceToCurve, "None");
cls_StepGeom_Pcurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_Pcurve::get_type_name, "None");
cls_StepGeom_Pcurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Pcurve::get_type_descriptor, "None");
cls_StepGeom_Pcurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Pcurve::*)() const) &StepGeom_Pcurve::DynamicType, "None");

// CLASS: STEPGEOM_PLANE
py::class_<StepGeom_Plane, opencascade::handle<StepGeom_Plane>, StepGeom_ElementarySurface> cls_StepGeom_Plane(mod, "StepGeom_Plane", "None");

// Constructors
cls_StepGeom_Plane.def(py::init<>());

// Methods
cls_StepGeom_Plane.def_static("get_type_name_", (const char * (*)()) &StepGeom_Plane::get_type_name, "None");
cls_StepGeom_Plane.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Plane::get_type_descriptor, "None");
cls_StepGeom_Plane.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Plane::*)() const) &StepGeom_Plane::DynamicType, "None");

// CLASS: STEPGEOM_POINTONCURVE
py::class_<StepGeom_PointOnCurve, opencascade::handle<StepGeom_PointOnCurve>, StepGeom_Point> cls_StepGeom_PointOnCurve(mod, "StepGeom_PointOnCurve", "None");

// Constructors
cls_StepGeom_PointOnCurve.def(py::init<>());

// Methods
cls_StepGeom_PointOnCurve.def("Init", (void (StepGeom_PointOnCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Curve> &, const Standard_Real)) &StepGeom_PointOnCurve::Init, "None", py::arg("aName"), py::arg("aBasisCurve"), py::arg("aPointParameter"));
cls_StepGeom_PointOnCurve.def("SetBasisCurve", (void (StepGeom_PointOnCurve::*)(const opencascade::handle<StepGeom_Curve> &)) &StepGeom_PointOnCurve::SetBasisCurve, "None", py::arg("aBasisCurve"));
cls_StepGeom_PointOnCurve.def("BasisCurve", (opencascade::handle<StepGeom_Curve> (StepGeom_PointOnCurve::*)() const) &StepGeom_PointOnCurve::BasisCurve, "None");
cls_StepGeom_PointOnCurve.def("SetPointParameter", (void (StepGeom_PointOnCurve::*)(const Standard_Real)) &StepGeom_PointOnCurve::SetPointParameter, "None", py::arg("aPointParameter"));
cls_StepGeom_PointOnCurve.def("PointParameter", (Standard_Real (StepGeom_PointOnCurve::*)() const) &StepGeom_PointOnCurve::PointParameter, "None");
cls_StepGeom_PointOnCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_PointOnCurve::get_type_name, "None");
cls_StepGeom_PointOnCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_PointOnCurve::get_type_descriptor, "None");
cls_StepGeom_PointOnCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_PointOnCurve::*)() const) &StepGeom_PointOnCurve::DynamicType, "None");

// CLASS: STEPGEOM_POINTONSURFACE
py::class_<StepGeom_PointOnSurface, opencascade::handle<StepGeom_PointOnSurface>, StepGeom_Point> cls_StepGeom_PointOnSurface(mod, "StepGeom_PointOnSurface", "None");

// Constructors
cls_StepGeom_PointOnSurface.def(py::init<>());

// Methods
cls_StepGeom_PointOnSurface.def("Init", (void (StepGeom_PointOnSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Surface> &, const Standard_Real, const Standard_Real)) &StepGeom_PointOnSurface::Init, "None", py::arg("aName"), py::arg("aBasisSurface"), py::arg("aPointParameterU"), py::arg("aPointParameterV"));
cls_StepGeom_PointOnSurface.def("SetBasisSurface", (void (StepGeom_PointOnSurface::*)(const opencascade::handle<StepGeom_Surface> &)) &StepGeom_PointOnSurface::SetBasisSurface, "None", py::arg("aBasisSurface"));
cls_StepGeom_PointOnSurface.def("BasisSurface", (opencascade::handle<StepGeom_Surface> (StepGeom_PointOnSurface::*)() const) &StepGeom_PointOnSurface::BasisSurface, "None");
cls_StepGeom_PointOnSurface.def("SetPointParameterU", (void (StepGeom_PointOnSurface::*)(const Standard_Real)) &StepGeom_PointOnSurface::SetPointParameterU, "None", py::arg("aPointParameterU"));
cls_StepGeom_PointOnSurface.def("PointParameterU", (Standard_Real (StepGeom_PointOnSurface::*)() const) &StepGeom_PointOnSurface::PointParameterU, "None");
cls_StepGeom_PointOnSurface.def("SetPointParameterV", (void (StepGeom_PointOnSurface::*)(const Standard_Real)) &StepGeom_PointOnSurface::SetPointParameterV, "None", py::arg("aPointParameterV"));
cls_StepGeom_PointOnSurface.def("PointParameterV", (Standard_Real (StepGeom_PointOnSurface::*)() const) &StepGeom_PointOnSurface::PointParameterV, "None");
cls_StepGeom_PointOnSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_PointOnSurface::get_type_name, "None");
cls_StepGeom_PointOnSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_PointOnSurface::get_type_descriptor, "None");
cls_StepGeom_PointOnSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_PointOnSurface::*)() const) &StepGeom_PointOnSurface::DynamicType, "None");

// CLASS: STEPGEOM_POINTREPLICA
py::class_<StepGeom_PointReplica, opencascade::handle<StepGeom_PointReplica>, StepGeom_Point> cls_StepGeom_PointReplica(mod, "StepGeom_PointReplica", "None");

// Constructors
cls_StepGeom_PointReplica.def(py::init<>());

// Methods
cls_StepGeom_PointReplica.def("Init", (void (StepGeom_PointReplica::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Point> &, const opencascade::handle<StepGeom_CartesianTransformationOperator> &)) &StepGeom_PointReplica::Init, "None", py::arg("aName"), py::arg("aParentPt"), py::arg("aTransformation"));
cls_StepGeom_PointReplica.def("SetParentPt", (void (StepGeom_PointReplica::*)(const opencascade::handle<StepGeom_Point> &)) &StepGeom_PointReplica::SetParentPt, "None", py::arg("aParentPt"));
cls_StepGeom_PointReplica.def("ParentPt", (opencascade::handle<StepGeom_Point> (StepGeom_PointReplica::*)() const) &StepGeom_PointReplica::ParentPt, "None");
cls_StepGeom_PointReplica.def("SetTransformation", (void (StepGeom_PointReplica::*)(const opencascade::handle<StepGeom_CartesianTransformationOperator> &)) &StepGeom_PointReplica::SetTransformation, "None", py::arg("aTransformation"));
cls_StepGeom_PointReplica.def("Transformation", (opencascade::handle<StepGeom_CartesianTransformationOperator> (StepGeom_PointReplica::*)() const) &StepGeom_PointReplica::Transformation, "None");
cls_StepGeom_PointReplica.def_static("get_type_name_", (const char * (*)()) &StepGeom_PointReplica::get_type_name, "None");
cls_StepGeom_PointReplica.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_PointReplica::get_type_descriptor, "None");
cls_StepGeom_PointReplica.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_PointReplica::*)() const) &StepGeom_PointReplica::DynamicType, "None");

// CLASS: STEPGEOM_POLYLINE
py::class_<StepGeom_Polyline, opencascade::handle<StepGeom_Polyline>, StepGeom_BoundedCurve> cls_StepGeom_Polyline(mod, "StepGeom_Polyline", "None");

// Constructors
cls_StepGeom_Polyline.def(py::init<>());

// Methods
cls_StepGeom_Polyline.def("Init", (void (StepGeom_Polyline::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &)) &StepGeom_Polyline::Init, "None", py::arg("aName"), py::arg("aPoints"));
cls_StepGeom_Polyline.def("SetPoints", (void (StepGeom_Polyline::*)(const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &)) &StepGeom_Polyline::SetPoints, "None", py::arg("aPoints"));
cls_StepGeom_Polyline.def("Points", (opencascade::handle<StepGeom_HArray1OfCartesianPoint> (StepGeom_Polyline::*)() const) &StepGeom_Polyline::Points, "None");
cls_StepGeom_Polyline.def("PointsValue", (opencascade::handle<StepGeom_CartesianPoint> (StepGeom_Polyline::*)(const Standard_Integer) const) &StepGeom_Polyline::PointsValue, "None", py::arg("num"));
cls_StepGeom_Polyline.def("NbPoints", (Standard_Integer (StepGeom_Polyline::*)() const) &StepGeom_Polyline::NbPoints, "None");
cls_StepGeom_Polyline.def_static("get_type_name_", (const char * (*)()) &StepGeom_Polyline::get_type_name, "None");
cls_StepGeom_Polyline.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Polyline::get_type_descriptor, "None");
cls_StepGeom_Polyline.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Polyline::*)() const) &StepGeom_Polyline::DynamicType, "None");

// CLASS: STEPGEOM_QUASIUNIFORMCURVE
py::class_<StepGeom_QuasiUniformCurve, opencascade::handle<StepGeom_QuasiUniformCurve>, StepGeom_BSplineCurve> cls_StepGeom_QuasiUniformCurve(mod, "StepGeom_QuasiUniformCurve", "None");

// Constructors
cls_StepGeom_QuasiUniformCurve.def(py::init<>());

// Methods
cls_StepGeom_QuasiUniformCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_QuasiUniformCurve::get_type_name, "None");
cls_StepGeom_QuasiUniformCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_QuasiUniformCurve::get_type_descriptor, "None");
cls_StepGeom_QuasiUniformCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_QuasiUniformCurve::*)() const) &StepGeom_QuasiUniformCurve::DynamicType, "None");

// CLASS: STEPGEOM_QUASIUNIFORMCURVEANDRATIONALBSPLINECURVE
py::class_<StepGeom_QuasiUniformCurveAndRationalBSplineCurve, opencascade::handle<StepGeom_QuasiUniformCurveAndRationalBSplineCurve>, StepGeom_BSplineCurve> cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve(mod, "StepGeom_QuasiUniformCurveAndRationalBSplineCurve", "None");

// Constructors
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def(py::init<>());

// Methods
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def("Init", (void (StepGeom_QuasiUniformCurveAndRationalBSplineCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &, const StepGeom_BSplineCurveForm, const StepData_Logical, const StepData_Logical, const opencascade::handle<StepGeom_QuasiUniformCurve> &, const opencascade::handle<StepGeom_RationalBSplineCurve> &)) &StepGeom_QuasiUniformCurveAndRationalBSplineCurve::Init, "None", py::arg("aName"), py::arg("aDegree"), py::arg("aControlPointsList"), py::arg("aCurveForm"), py::arg("aClosedCurve"), py::arg("aSelfIntersect"), py::arg("aQuasiUniformCurve"), py::arg("aRationalBSplineCurve"));
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def("Init", (void (StepGeom_QuasiUniformCurveAndRationalBSplineCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &, const StepGeom_BSplineCurveForm, const StepData_Logical, const StepData_Logical, const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_QuasiUniformCurveAndRationalBSplineCurve::Init, "None", py::arg("aName"), py::arg("aDegree"), py::arg("aControlPointsList"), py::arg("aCurveForm"), py::arg("aClosedCurve"), py::arg("aSelfIntersect"), py::arg("aWeightsData"));
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def("SetQuasiUniformCurve", (void (StepGeom_QuasiUniformCurveAndRationalBSplineCurve::*)(const opencascade::handle<StepGeom_QuasiUniformCurve> &)) &StepGeom_QuasiUniformCurveAndRationalBSplineCurve::SetQuasiUniformCurve, "None", py::arg("aQuasiUniformCurve"));
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def("QuasiUniformCurve", (opencascade::handle<StepGeom_QuasiUniformCurve> (StepGeom_QuasiUniformCurveAndRationalBSplineCurve::*)() const) &StepGeom_QuasiUniformCurveAndRationalBSplineCurve::QuasiUniformCurve, "None");
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def("SetRationalBSplineCurve", (void (StepGeom_QuasiUniformCurveAndRationalBSplineCurve::*)(const opencascade::handle<StepGeom_RationalBSplineCurve> &)) &StepGeom_QuasiUniformCurveAndRationalBSplineCurve::SetRationalBSplineCurve, "None", py::arg("aRationalBSplineCurve"));
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def("RationalBSplineCurve", (opencascade::handle<StepGeom_RationalBSplineCurve> (StepGeom_QuasiUniformCurveAndRationalBSplineCurve::*)() const) &StepGeom_QuasiUniformCurveAndRationalBSplineCurve::RationalBSplineCurve, "None");
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def("SetWeightsData", (void (StepGeom_QuasiUniformCurveAndRationalBSplineCurve::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_QuasiUniformCurveAndRationalBSplineCurve::SetWeightsData, "None", py::arg("aWeightsData"));
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def("WeightsData", (opencascade::handle<TColStd_HArray1OfReal> (StepGeom_QuasiUniformCurveAndRationalBSplineCurve::*)() const) &StepGeom_QuasiUniformCurveAndRationalBSplineCurve::WeightsData, "None");
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def("WeightsDataValue", (Standard_Real (StepGeom_QuasiUniformCurveAndRationalBSplineCurve::*)(const Standard_Integer) const) &StepGeom_QuasiUniformCurveAndRationalBSplineCurve::WeightsDataValue, "None", py::arg("num"));
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def("NbWeightsData", (Standard_Integer (StepGeom_QuasiUniformCurveAndRationalBSplineCurve::*)() const) &StepGeom_QuasiUniformCurveAndRationalBSplineCurve::NbWeightsData, "None");
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_QuasiUniformCurveAndRationalBSplineCurve::get_type_name, "None");
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_QuasiUniformCurveAndRationalBSplineCurve::get_type_descriptor, "None");
cls_StepGeom_QuasiUniformCurveAndRationalBSplineCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_QuasiUniformCurveAndRationalBSplineCurve::*)() const) &StepGeom_QuasiUniformCurveAndRationalBSplineCurve::DynamicType, "None");

// CLASS: STEPGEOM_QUASIUNIFORMSURFACE
py::class_<StepGeom_QuasiUniformSurface, opencascade::handle<StepGeom_QuasiUniformSurface>, StepGeom_BSplineSurface> cls_StepGeom_QuasiUniformSurface(mod, "StepGeom_QuasiUniformSurface", "None");

// Constructors
cls_StepGeom_QuasiUniformSurface.def(py::init<>());

// Methods
cls_StepGeom_QuasiUniformSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_QuasiUniformSurface::get_type_name, "None");
cls_StepGeom_QuasiUniformSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_QuasiUniformSurface::get_type_descriptor, "None");
cls_StepGeom_QuasiUniformSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_QuasiUniformSurface::*)() const) &StepGeom_QuasiUniformSurface::DynamicType, "None");

// CLASS: STEPGEOM_QUASIUNIFORMSURFACEANDRATIONALBSPLINESURFACE
py::class_<StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface, opencascade::handle<StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface>, StepGeom_BSplineSurface> cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface(mod, "StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface", "None");

// Constructors
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def(py::init<>());

// Methods
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def("Init", (void (StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Integer, const opencascade::handle<StepGeom_HArray2OfCartesianPoint> &, const StepGeom_BSplineSurfaceForm, const StepData_Logical, const StepData_Logical, const StepData_Logical, const opencascade::handle<StepGeom_QuasiUniformSurface> &, const opencascade::handle<StepGeom_RationalBSplineSurface> &)) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::Init, "None", py::arg("aName"), py::arg("aUDegree"), py::arg("aVDegree"), py::arg("aControlPointsList"), py::arg("aSurfaceForm"), py::arg("aUClosed"), py::arg("aVClosed"), py::arg("aSelfIntersect"), py::arg("aQuasiUniformSurface"), py::arg("aRationalBSplineSurface"));
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def("Init", (void (StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Integer, const opencascade::handle<StepGeom_HArray2OfCartesianPoint> &, const StepGeom_BSplineSurfaceForm, const StepData_Logical, const StepData_Logical, const StepData_Logical, const opencascade::handle<TColStd_HArray2OfReal> &)) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::Init, "None", py::arg("aName"), py::arg("aUDegree"), py::arg("aVDegree"), py::arg("aControlPointsList"), py::arg("aSurfaceForm"), py::arg("aUClosed"), py::arg("aVClosed"), py::arg("aSelfIntersect"), py::arg("aWeightsData"));
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def("SetQuasiUniformSurface", (void (StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::*)(const opencascade::handle<StepGeom_QuasiUniformSurface> &)) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::SetQuasiUniformSurface, "None", py::arg("aQuasiUniformSurface"));
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def("QuasiUniformSurface", (opencascade::handle<StepGeom_QuasiUniformSurface> (StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::QuasiUniformSurface, "None");
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def("SetRationalBSplineSurface", (void (StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::*)(const opencascade::handle<StepGeom_RationalBSplineSurface> &)) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::SetRationalBSplineSurface, "None", py::arg("aRationalBSplineSurface"));
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def("RationalBSplineSurface", (opencascade::handle<StepGeom_RationalBSplineSurface> (StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::RationalBSplineSurface, "None");
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def("SetWeightsData", (void (StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::*)(const opencascade::handle<TColStd_HArray2OfReal> &)) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::SetWeightsData, "None", py::arg("aWeightsData"));
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def("WeightsData", (opencascade::handle<TColStd_HArray2OfReal> (StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::WeightsData, "None");
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def("WeightsDataValue", (Standard_Real (StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::*)(const Standard_Integer, const Standard_Integer) const) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::WeightsDataValue, "None", py::arg("num1"), py::arg("num2"));
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def("NbWeightsDataI", (Standard_Integer (StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::NbWeightsDataI, "None");
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def("NbWeightsDataJ", (Standard_Integer (StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::NbWeightsDataJ, "None");
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::get_type_name, "None");
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::get_type_descriptor, "None");
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::DynamicType, "None");

// CLASS: STEPGEOM_RATIONALBSPLINECURVE
py::class_<StepGeom_RationalBSplineCurve, opencascade::handle<StepGeom_RationalBSplineCurve>, StepGeom_BSplineCurve> cls_StepGeom_RationalBSplineCurve(mod, "StepGeom_RationalBSplineCurve", "None");

// Constructors
cls_StepGeom_RationalBSplineCurve.def(py::init<>());

// Methods
cls_StepGeom_RationalBSplineCurve.def("Init", (void (StepGeom_RationalBSplineCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &, const StepGeom_BSplineCurveForm, const StepData_Logical, const StepData_Logical, const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_RationalBSplineCurve::Init, "None", py::arg("aName"), py::arg("aDegree"), py::arg("aControlPointsList"), py::arg("aCurveForm"), py::arg("aClosedCurve"), py::arg("aSelfIntersect"), py::arg("aWeightsData"));
cls_StepGeom_RationalBSplineCurve.def("SetWeightsData", (void (StepGeom_RationalBSplineCurve::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_RationalBSplineCurve::SetWeightsData, "None", py::arg("aWeightsData"));
cls_StepGeom_RationalBSplineCurve.def("WeightsData", (opencascade::handle<TColStd_HArray1OfReal> (StepGeom_RationalBSplineCurve::*)() const) &StepGeom_RationalBSplineCurve::WeightsData, "None");
cls_StepGeom_RationalBSplineCurve.def("WeightsDataValue", (Standard_Real (StepGeom_RationalBSplineCurve::*)(const Standard_Integer) const) &StepGeom_RationalBSplineCurve::WeightsDataValue, "None", py::arg("num"));
cls_StepGeom_RationalBSplineCurve.def("NbWeightsData", (Standard_Integer (StepGeom_RationalBSplineCurve::*)() const) &StepGeom_RationalBSplineCurve::NbWeightsData, "None");
cls_StepGeom_RationalBSplineCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_RationalBSplineCurve::get_type_name, "None");
cls_StepGeom_RationalBSplineCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_RationalBSplineCurve::get_type_descriptor, "None");
cls_StepGeom_RationalBSplineCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_RationalBSplineCurve::*)() const) &StepGeom_RationalBSplineCurve::DynamicType, "None");

// CLASS: STEPGEOM_RATIONALBSPLINESURFACE
py::class_<StepGeom_RationalBSplineSurface, opencascade::handle<StepGeom_RationalBSplineSurface>, StepGeom_BSplineSurface> cls_StepGeom_RationalBSplineSurface(mod, "StepGeom_RationalBSplineSurface", "None");

// Constructors
cls_StepGeom_RationalBSplineSurface.def(py::init<>());

// Methods
cls_StepGeom_RationalBSplineSurface.def("Init", (void (StepGeom_RationalBSplineSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Integer, const opencascade::handle<StepGeom_HArray2OfCartesianPoint> &, const StepGeom_BSplineSurfaceForm, const StepData_Logical, const StepData_Logical, const StepData_Logical, const opencascade::handle<TColStd_HArray2OfReal> &)) &StepGeom_RationalBSplineSurface::Init, "None", py::arg("aName"), py::arg("aUDegree"), py::arg("aVDegree"), py::arg("aControlPointsList"), py::arg("aSurfaceForm"), py::arg("aUClosed"), py::arg("aVClosed"), py::arg("aSelfIntersect"), py::arg("aWeightsData"));
cls_StepGeom_RationalBSplineSurface.def("SetWeightsData", (void (StepGeom_RationalBSplineSurface::*)(const opencascade::handle<TColStd_HArray2OfReal> &)) &StepGeom_RationalBSplineSurface::SetWeightsData, "None", py::arg("aWeightsData"));
cls_StepGeom_RationalBSplineSurface.def("WeightsData", (opencascade::handle<TColStd_HArray2OfReal> (StepGeom_RationalBSplineSurface::*)() const) &StepGeom_RationalBSplineSurface::WeightsData, "None");
cls_StepGeom_RationalBSplineSurface.def("WeightsDataValue", (Standard_Real (StepGeom_RationalBSplineSurface::*)(const Standard_Integer, const Standard_Integer) const) &StepGeom_RationalBSplineSurface::WeightsDataValue, "None", py::arg("num1"), py::arg("num2"));
cls_StepGeom_RationalBSplineSurface.def("NbWeightsDataI", (Standard_Integer (StepGeom_RationalBSplineSurface::*)() const) &StepGeom_RationalBSplineSurface::NbWeightsDataI, "None");
cls_StepGeom_RationalBSplineSurface.def("NbWeightsDataJ", (Standard_Integer (StepGeom_RationalBSplineSurface::*)() const) &StepGeom_RationalBSplineSurface::NbWeightsDataJ, "None");
cls_StepGeom_RationalBSplineSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_RationalBSplineSurface::get_type_name, "None");
cls_StepGeom_RationalBSplineSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_RationalBSplineSurface::get_type_descriptor, "None");
cls_StepGeom_RationalBSplineSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_RationalBSplineSurface::*)() const) &StepGeom_RationalBSplineSurface::DynamicType, "None");

// CLASS: STEPGEOM_RECTANGULARCOMPOSITESURFACE
py::class_<StepGeom_RectangularCompositeSurface, opencascade::handle<StepGeom_RectangularCompositeSurface>, StepGeom_BoundedSurface> cls_StepGeom_RectangularCompositeSurface(mod, "StepGeom_RectangularCompositeSurface", "None");

// Constructors
cls_StepGeom_RectangularCompositeSurface.def(py::init<>());

// Methods
cls_StepGeom_RectangularCompositeSurface.def("Init", (void (StepGeom_RectangularCompositeSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_HArray2OfSurfacePatch> &)) &StepGeom_RectangularCompositeSurface::Init, "None", py::arg("aName"), py::arg("aSegments"));
cls_StepGeom_RectangularCompositeSurface.def("SetSegments", (void (StepGeom_RectangularCompositeSurface::*)(const opencascade::handle<StepGeom_HArray2OfSurfacePatch> &)) &StepGeom_RectangularCompositeSurface::SetSegments, "None", py::arg("aSegments"));
cls_StepGeom_RectangularCompositeSurface.def("Segments", (opencascade::handle<StepGeom_HArray2OfSurfacePatch> (StepGeom_RectangularCompositeSurface::*)() const) &StepGeom_RectangularCompositeSurface::Segments, "None");
cls_StepGeom_RectangularCompositeSurface.def("SegmentsValue", (opencascade::handle<StepGeom_SurfacePatch> (StepGeom_RectangularCompositeSurface::*)(const Standard_Integer, const Standard_Integer) const) &StepGeom_RectangularCompositeSurface::SegmentsValue, "None", py::arg("num1"), py::arg("num2"));
cls_StepGeom_RectangularCompositeSurface.def("NbSegmentsI", (Standard_Integer (StepGeom_RectangularCompositeSurface::*)() const) &StepGeom_RectangularCompositeSurface::NbSegmentsI, "None");
cls_StepGeom_RectangularCompositeSurface.def("NbSegmentsJ", (Standard_Integer (StepGeom_RectangularCompositeSurface::*)() const) &StepGeom_RectangularCompositeSurface::NbSegmentsJ, "None");
cls_StepGeom_RectangularCompositeSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_RectangularCompositeSurface::get_type_name, "None");
cls_StepGeom_RectangularCompositeSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_RectangularCompositeSurface::get_type_descriptor, "None");
cls_StepGeom_RectangularCompositeSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_RectangularCompositeSurface::*)() const) &StepGeom_RectangularCompositeSurface::DynamicType, "None");

// CLASS: STEPGEOM_RECTANGULARTRIMMEDSURFACE
py::class_<StepGeom_RectangularTrimmedSurface, opencascade::handle<StepGeom_RectangularTrimmedSurface>, StepGeom_BoundedSurface> cls_StepGeom_RectangularTrimmedSurface(mod, "StepGeom_RectangularTrimmedSurface", "None");

// Constructors
cls_StepGeom_RectangularTrimmedSurface.def(py::init<>());

// Methods
cls_StepGeom_RectangularTrimmedSurface.def("Init", (void (StepGeom_RectangularTrimmedSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &StepGeom_RectangularTrimmedSurface::Init, "None", py::arg("aName"), py::arg("aBasisSurface"), py::arg("aU1"), py::arg("aU2"), py::arg("aV1"), py::arg("aV2"), py::arg("aUsense"), py::arg("aVsense"));
cls_StepGeom_RectangularTrimmedSurface.def("SetBasisSurface", (void (StepGeom_RectangularTrimmedSurface::*)(const opencascade::handle<StepGeom_Surface> &)) &StepGeom_RectangularTrimmedSurface::SetBasisSurface, "None", py::arg("aBasisSurface"));
cls_StepGeom_RectangularTrimmedSurface.def("BasisSurface", (opencascade::handle<StepGeom_Surface> (StepGeom_RectangularTrimmedSurface::*)() const) &StepGeom_RectangularTrimmedSurface::BasisSurface, "None");
cls_StepGeom_RectangularTrimmedSurface.def("SetU1", (void (StepGeom_RectangularTrimmedSurface::*)(const Standard_Real)) &StepGeom_RectangularTrimmedSurface::SetU1, "None", py::arg("aU1"));
cls_StepGeom_RectangularTrimmedSurface.def("U1", (Standard_Real (StepGeom_RectangularTrimmedSurface::*)() const) &StepGeom_RectangularTrimmedSurface::U1, "None");
cls_StepGeom_RectangularTrimmedSurface.def("SetU2", (void (StepGeom_RectangularTrimmedSurface::*)(const Standard_Real)) &StepGeom_RectangularTrimmedSurface::SetU2, "None", py::arg("aU2"));
cls_StepGeom_RectangularTrimmedSurface.def("U2", (Standard_Real (StepGeom_RectangularTrimmedSurface::*)() const) &StepGeom_RectangularTrimmedSurface::U2, "None");
cls_StepGeom_RectangularTrimmedSurface.def("SetV1", (void (StepGeom_RectangularTrimmedSurface::*)(const Standard_Real)) &StepGeom_RectangularTrimmedSurface::SetV1, "None", py::arg("aV1"));
cls_StepGeom_RectangularTrimmedSurface.def("V1", (Standard_Real (StepGeom_RectangularTrimmedSurface::*)() const) &StepGeom_RectangularTrimmedSurface::V1, "None");
cls_StepGeom_RectangularTrimmedSurface.def("SetV2", (void (StepGeom_RectangularTrimmedSurface::*)(const Standard_Real)) &StepGeom_RectangularTrimmedSurface::SetV2, "None", py::arg("aV2"));
cls_StepGeom_RectangularTrimmedSurface.def("V2", (Standard_Real (StepGeom_RectangularTrimmedSurface::*)() const) &StepGeom_RectangularTrimmedSurface::V2, "None");
cls_StepGeom_RectangularTrimmedSurface.def("SetUsense", (void (StepGeom_RectangularTrimmedSurface::*)(const Standard_Boolean)) &StepGeom_RectangularTrimmedSurface::SetUsense, "None", py::arg("aUsense"));
cls_StepGeom_RectangularTrimmedSurface.def("Usense", (Standard_Boolean (StepGeom_RectangularTrimmedSurface::*)() const) &StepGeom_RectangularTrimmedSurface::Usense, "None");
cls_StepGeom_RectangularTrimmedSurface.def("SetVsense", (void (StepGeom_RectangularTrimmedSurface::*)(const Standard_Boolean)) &StepGeom_RectangularTrimmedSurface::SetVsense, "None", py::arg("aVsense"));
cls_StepGeom_RectangularTrimmedSurface.def("Vsense", (Standard_Boolean (StepGeom_RectangularTrimmedSurface::*)() const) &StepGeom_RectangularTrimmedSurface::Vsense, "None");
cls_StepGeom_RectangularTrimmedSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_RectangularTrimmedSurface::get_type_name, "None");
cls_StepGeom_RectangularTrimmedSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_RectangularTrimmedSurface::get_type_descriptor, "None");
cls_StepGeom_RectangularTrimmedSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_RectangularTrimmedSurface::*)() const) &StepGeom_RectangularTrimmedSurface::DynamicType, "None");

// CLASS: STEPGEOM_REPARAMETRISEDCOMPOSITECURVESEGMENT
py::class_<StepGeom_ReparametrisedCompositeCurveSegment, opencascade::handle<StepGeom_ReparametrisedCompositeCurveSegment>, StepGeom_CompositeCurveSegment> cls_StepGeom_ReparametrisedCompositeCurveSegment(mod, "StepGeom_ReparametrisedCompositeCurveSegment", "None");

// Constructors
cls_StepGeom_ReparametrisedCompositeCurveSegment.def(py::init<>());

// Methods
cls_StepGeom_ReparametrisedCompositeCurveSegment.def("Init", (void (StepGeom_ReparametrisedCompositeCurveSegment::*)(const StepGeom_TransitionCode, const Standard_Boolean, const opencascade::handle<StepGeom_Curve> &, const Standard_Real)) &StepGeom_ReparametrisedCompositeCurveSegment::Init, "None", py::arg("aTransition"), py::arg("aSameSense"), py::arg("aParentCurve"), py::arg("aParamLength"));
cls_StepGeom_ReparametrisedCompositeCurveSegment.def("SetParamLength", (void (StepGeom_ReparametrisedCompositeCurveSegment::*)(const Standard_Real)) &StepGeom_ReparametrisedCompositeCurveSegment::SetParamLength, "None", py::arg("aParamLength"));
cls_StepGeom_ReparametrisedCompositeCurveSegment.def("ParamLength", (Standard_Real (StepGeom_ReparametrisedCompositeCurveSegment::*)() const) &StepGeom_ReparametrisedCompositeCurveSegment::ParamLength, "None");
cls_StepGeom_ReparametrisedCompositeCurveSegment.def_static("get_type_name_", (const char * (*)()) &StepGeom_ReparametrisedCompositeCurveSegment::get_type_name, "None");
cls_StepGeom_ReparametrisedCompositeCurveSegment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_ReparametrisedCompositeCurveSegment::get_type_descriptor, "None");
cls_StepGeom_ReparametrisedCompositeCurveSegment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_ReparametrisedCompositeCurveSegment::*)() const) &StepGeom_ReparametrisedCompositeCurveSegment::DynamicType, "None");

// CLASS: STEPGEOM_SEAMCURVE
py::class_<StepGeom_SeamCurve, opencascade::handle<StepGeom_SeamCurve>, StepGeom_SurfaceCurve> cls_StepGeom_SeamCurve(mod, "StepGeom_SeamCurve", "None");

// Constructors
cls_StepGeom_SeamCurve.def(py::init<>());

// Methods
cls_StepGeom_SeamCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_SeamCurve::get_type_name, "None");
cls_StepGeom_SeamCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_SeamCurve::get_type_descriptor, "None");
cls_StepGeom_SeamCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_SeamCurve::*)() const) &StepGeom_SeamCurve::DynamicType, "None");

// CLASS: STEPGEOM_SPHERICALSURFACE
py::class_<StepGeom_SphericalSurface, opencascade::handle<StepGeom_SphericalSurface>, StepGeom_ElementarySurface> cls_StepGeom_SphericalSurface(mod, "StepGeom_SphericalSurface", "None");

// Constructors
cls_StepGeom_SphericalSurface.def(py::init<>());

// Methods
cls_StepGeom_SphericalSurface.def("Init", (void (StepGeom_SphericalSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Axis2Placement3d> &, const Standard_Real)) &StepGeom_SphericalSurface::Init, "None", py::arg("aName"), py::arg("aPosition"), py::arg("aRadius"));
cls_StepGeom_SphericalSurface.def("SetRadius", (void (StepGeom_SphericalSurface::*)(const Standard_Real)) &StepGeom_SphericalSurface::SetRadius, "None", py::arg("aRadius"));
cls_StepGeom_SphericalSurface.def("Radius", (Standard_Real (StepGeom_SphericalSurface::*)() const) &StepGeom_SphericalSurface::Radius, "None");
cls_StepGeom_SphericalSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_SphericalSurface::get_type_name, "None");
cls_StepGeom_SphericalSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_SphericalSurface::get_type_descriptor, "None");
cls_StepGeom_SphericalSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_SphericalSurface::*)() const) &StepGeom_SphericalSurface::DynamicType, "None");

// CLASS: STEPGEOM_SURFACECURVEANDBOUNDEDCURVE
py::class_<StepGeom_SurfaceCurveAndBoundedCurve, opencascade::handle<StepGeom_SurfaceCurveAndBoundedCurve>, StepGeom_SurfaceCurve> cls_StepGeom_SurfaceCurveAndBoundedCurve(mod, "StepGeom_SurfaceCurveAndBoundedCurve", "complex type: bounded_curve + surface_curve needed for curve_bounded_surfaces (S4132)");

// Constructors
cls_StepGeom_SurfaceCurveAndBoundedCurve.def(py::init<>());

// Methods
cls_StepGeom_SurfaceCurveAndBoundedCurve.def("BoundedCurve", (opencascade::handle<StepGeom_BoundedCurve> & (StepGeom_SurfaceCurveAndBoundedCurve::*)()) &StepGeom_SurfaceCurveAndBoundedCurve::BoundedCurve, "returns field BoundedCurve");
cls_StepGeom_SurfaceCurveAndBoundedCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_SurfaceCurveAndBoundedCurve::get_type_name, "None");
cls_StepGeom_SurfaceCurveAndBoundedCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_SurfaceCurveAndBoundedCurve::get_type_descriptor, "None");
cls_StepGeom_SurfaceCurveAndBoundedCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_SurfaceCurveAndBoundedCurve::*)() const) &StepGeom_SurfaceCurveAndBoundedCurve::DynamicType, "None");

// CLASS: STEPGEOM_SWEPTSURFACE
py::class_<StepGeom_SweptSurface, opencascade::handle<StepGeom_SweptSurface>, StepGeom_Surface> cls_StepGeom_SweptSurface(mod, "StepGeom_SweptSurface", "None");

// Constructors
cls_StepGeom_SweptSurface.def(py::init<>());

// Methods
cls_StepGeom_SweptSurface.def("Init", (void (StepGeom_SweptSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Curve> &)) &StepGeom_SweptSurface::Init, "None", py::arg("aName"), py::arg("aSweptCurve"));
cls_StepGeom_SweptSurface.def("SetSweptCurve", (void (StepGeom_SweptSurface::*)(const opencascade::handle<StepGeom_Curve> &)) &StepGeom_SweptSurface::SetSweptCurve, "None", py::arg("aSweptCurve"));
cls_StepGeom_SweptSurface.def("SweptCurve", (opencascade::handle<StepGeom_Curve> (StepGeom_SweptSurface::*)() const) &StepGeom_SweptSurface::SweptCurve, "None");
cls_StepGeom_SweptSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_SweptSurface::get_type_name, "None");
cls_StepGeom_SweptSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_SweptSurface::get_type_descriptor, "None");
cls_StepGeom_SweptSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_SweptSurface::*)() const) &StepGeom_SweptSurface::DynamicType, "None");

// CLASS: STEPGEOM_SURFACEOFLINEAREXTRUSION
py::class_<StepGeom_SurfaceOfLinearExtrusion, opencascade::handle<StepGeom_SurfaceOfLinearExtrusion>, StepGeom_SweptSurface> cls_StepGeom_SurfaceOfLinearExtrusion(mod, "StepGeom_SurfaceOfLinearExtrusion", "None");

// Constructors
cls_StepGeom_SurfaceOfLinearExtrusion.def(py::init<>());

// Methods
cls_StepGeom_SurfaceOfLinearExtrusion.def("Init", (void (StepGeom_SurfaceOfLinearExtrusion::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Curve> &, const opencascade::handle<StepGeom_Vector> &)) &StepGeom_SurfaceOfLinearExtrusion::Init, "None", py::arg("aName"), py::arg("aSweptCurve"), py::arg("aExtrusionAxis"));
cls_StepGeom_SurfaceOfLinearExtrusion.def("SetExtrusionAxis", (void (StepGeom_SurfaceOfLinearExtrusion::*)(const opencascade::handle<StepGeom_Vector> &)) &StepGeom_SurfaceOfLinearExtrusion::SetExtrusionAxis, "None", py::arg("aExtrusionAxis"));
cls_StepGeom_SurfaceOfLinearExtrusion.def("ExtrusionAxis", (opencascade::handle<StepGeom_Vector> (StepGeom_SurfaceOfLinearExtrusion::*)() const) &StepGeom_SurfaceOfLinearExtrusion::ExtrusionAxis, "None");
cls_StepGeom_SurfaceOfLinearExtrusion.def_static("get_type_name_", (const char * (*)()) &StepGeom_SurfaceOfLinearExtrusion::get_type_name, "None");
cls_StepGeom_SurfaceOfLinearExtrusion.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_SurfaceOfLinearExtrusion::get_type_descriptor, "None");
cls_StepGeom_SurfaceOfLinearExtrusion.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_SurfaceOfLinearExtrusion::*)() const) &StepGeom_SurfaceOfLinearExtrusion::DynamicType, "None");

// CLASS: STEPGEOM_SURFACEOFREVOLUTION
py::class_<StepGeom_SurfaceOfRevolution, opencascade::handle<StepGeom_SurfaceOfRevolution>, StepGeom_SweptSurface> cls_StepGeom_SurfaceOfRevolution(mod, "StepGeom_SurfaceOfRevolution", "None");

// Constructors
cls_StepGeom_SurfaceOfRevolution.def(py::init<>());

// Methods
cls_StepGeom_SurfaceOfRevolution.def("Init", (void (StepGeom_SurfaceOfRevolution::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Curve> &, const opencascade::handle<StepGeom_Axis1Placement> &)) &StepGeom_SurfaceOfRevolution::Init, "None", py::arg("aName"), py::arg("aSweptCurve"), py::arg("aAxisPosition"));
cls_StepGeom_SurfaceOfRevolution.def("SetAxisPosition", (void (StepGeom_SurfaceOfRevolution::*)(const opencascade::handle<StepGeom_Axis1Placement> &)) &StepGeom_SurfaceOfRevolution::SetAxisPosition, "None", py::arg("aAxisPosition"));
cls_StepGeom_SurfaceOfRevolution.def("AxisPosition", (opencascade::handle<StepGeom_Axis1Placement> (StepGeom_SurfaceOfRevolution::*)() const) &StepGeom_SurfaceOfRevolution::AxisPosition, "None");
cls_StepGeom_SurfaceOfRevolution.def_static("get_type_name_", (const char * (*)()) &StepGeom_SurfaceOfRevolution::get_type_name, "None");
cls_StepGeom_SurfaceOfRevolution.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_SurfaceOfRevolution::get_type_descriptor, "None");
cls_StepGeom_SurfaceOfRevolution.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_SurfaceOfRevolution::*)() const) &StepGeom_SurfaceOfRevolution::DynamicType, "None");

// CLASS: STEPGEOM_SURFACEREPLICA
py::class_<StepGeom_SurfaceReplica, opencascade::handle<StepGeom_SurfaceReplica>, StepGeom_Surface> cls_StepGeom_SurfaceReplica(mod, "StepGeom_SurfaceReplica", "None");

// Constructors
cls_StepGeom_SurfaceReplica.def(py::init<>());

// Methods
cls_StepGeom_SurfaceReplica.def("Init", (void (StepGeom_SurfaceReplica::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Surface> &, const opencascade::handle<StepGeom_CartesianTransformationOperator3d> &)) &StepGeom_SurfaceReplica::Init, "None", py::arg("aName"), py::arg("aParentSurface"), py::arg("aTransformation"));
cls_StepGeom_SurfaceReplica.def("SetParentSurface", (void (StepGeom_SurfaceReplica::*)(const opencascade::handle<StepGeom_Surface> &)) &StepGeom_SurfaceReplica::SetParentSurface, "None", py::arg("aParentSurface"));
cls_StepGeom_SurfaceReplica.def("ParentSurface", (opencascade::handle<StepGeom_Surface> (StepGeom_SurfaceReplica::*)() const) &StepGeom_SurfaceReplica::ParentSurface, "None");
cls_StepGeom_SurfaceReplica.def("SetTransformation", (void (StepGeom_SurfaceReplica::*)(const opencascade::handle<StepGeom_CartesianTransformationOperator3d> &)) &StepGeom_SurfaceReplica::SetTransformation, "None", py::arg("aTransformation"));
cls_StepGeom_SurfaceReplica.def("Transformation", (opencascade::handle<StepGeom_CartesianTransformationOperator3d> (StepGeom_SurfaceReplica::*)() const) &StepGeom_SurfaceReplica::Transformation, "None");
cls_StepGeom_SurfaceReplica.def_static("get_type_name_", (const char * (*)()) &StepGeom_SurfaceReplica::get_type_name, "None");
cls_StepGeom_SurfaceReplica.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_SurfaceReplica::get_type_descriptor, "None");
cls_StepGeom_SurfaceReplica.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_SurfaceReplica::*)() const) &StepGeom_SurfaceReplica::DynamicType, "None");

// CLASS: STEPGEOM_TRIMMEDCURVE
py::class_<StepGeom_TrimmedCurve, opencascade::handle<StepGeom_TrimmedCurve>, StepGeom_BoundedCurve> cls_StepGeom_TrimmedCurve(mod, "StepGeom_TrimmedCurve", "None");

// Constructors
cls_StepGeom_TrimmedCurve.def(py::init<>());

// Methods
cls_StepGeom_TrimmedCurve.def("Init", (void (StepGeom_TrimmedCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Curve> &, const opencascade::handle<StepGeom_HArray1OfTrimmingSelect> &, const opencascade::handle<StepGeom_HArray1OfTrimmingSelect> &, const Standard_Boolean, const StepGeom_TrimmingPreference)) &StepGeom_TrimmedCurve::Init, "None", py::arg("aName"), py::arg("aBasisCurve"), py::arg("aTrim1"), py::arg("aTrim2"), py::arg("aSenseAgreement"), py::arg("aMasterRepresentation"));
cls_StepGeom_TrimmedCurve.def("SetBasisCurve", (void (StepGeom_TrimmedCurve::*)(const opencascade::handle<StepGeom_Curve> &)) &StepGeom_TrimmedCurve::SetBasisCurve, "None", py::arg("aBasisCurve"));
cls_StepGeom_TrimmedCurve.def("BasisCurve", (opencascade::handle<StepGeom_Curve> (StepGeom_TrimmedCurve::*)() const) &StepGeom_TrimmedCurve::BasisCurve, "None");
cls_StepGeom_TrimmedCurve.def("SetTrim1", (void (StepGeom_TrimmedCurve::*)(const opencascade::handle<StepGeom_HArray1OfTrimmingSelect> &)) &StepGeom_TrimmedCurve::SetTrim1, "None", py::arg("aTrim1"));
cls_StepGeom_TrimmedCurve.def("Trim1", (opencascade::handle<StepGeom_HArray1OfTrimmingSelect> (StepGeom_TrimmedCurve::*)() const) &StepGeom_TrimmedCurve::Trim1, "None");
cls_StepGeom_TrimmedCurve.def("Trim1Value", (StepGeom_TrimmingSelect (StepGeom_TrimmedCurve::*)(const Standard_Integer) const) &StepGeom_TrimmedCurve::Trim1Value, "None", py::arg("num"));
cls_StepGeom_TrimmedCurve.def("NbTrim1", (Standard_Integer (StepGeom_TrimmedCurve::*)() const) &StepGeom_TrimmedCurve::NbTrim1, "None");
cls_StepGeom_TrimmedCurve.def("SetTrim2", (void (StepGeom_TrimmedCurve::*)(const opencascade::handle<StepGeom_HArray1OfTrimmingSelect> &)) &StepGeom_TrimmedCurve::SetTrim2, "None", py::arg("aTrim2"));
cls_StepGeom_TrimmedCurve.def("Trim2", (opencascade::handle<StepGeom_HArray1OfTrimmingSelect> (StepGeom_TrimmedCurve::*)() const) &StepGeom_TrimmedCurve::Trim2, "None");
cls_StepGeom_TrimmedCurve.def("Trim2Value", (StepGeom_TrimmingSelect (StepGeom_TrimmedCurve::*)(const Standard_Integer) const) &StepGeom_TrimmedCurve::Trim2Value, "None", py::arg("num"));
cls_StepGeom_TrimmedCurve.def("NbTrim2", (Standard_Integer (StepGeom_TrimmedCurve::*)() const) &StepGeom_TrimmedCurve::NbTrim2, "None");
cls_StepGeom_TrimmedCurve.def("SetSenseAgreement", (void (StepGeom_TrimmedCurve::*)(const Standard_Boolean)) &StepGeom_TrimmedCurve::SetSenseAgreement, "None", py::arg("aSenseAgreement"));
cls_StepGeom_TrimmedCurve.def("SenseAgreement", (Standard_Boolean (StepGeom_TrimmedCurve::*)() const) &StepGeom_TrimmedCurve::SenseAgreement, "None");
cls_StepGeom_TrimmedCurve.def("SetMasterRepresentation", (void (StepGeom_TrimmedCurve::*)(const StepGeom_TrimmingPreference)) &StepGeom_TrimmedCurve::SetMasterRepresentation, "None", py::arg("aMasterRepresentation"));
cls_StepGeom_TrimmedCurve.def("MasterRepresentation", (StepGeom_TrimmingPreference (StepGeom_TrimmedCurve::*)() const) &StepGeom_TrimmedCurve::MasterRepresentation, "None");
cls_StepGeom_TrimmedCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_TrimmedCurve::get_type_name, "None");
cls_StepGeom_TrimmedCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_TrimmedCurve::get_type_descriptor, "None");
cls_StepGeom_TrimmedCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_TrimmedCurve::*)() const) &StepGeom_TrimmedCurve::DynamicType, "None");

// CLASS: STEPGEOM_TRIMMINGMEMBER
py::class_<StepGeom_TrimmingMember, opencascade::handle<StepGeom_TrimmingMember>, StepData_SelectReal> cls_StepGeom_TrimmingMember(mod, "StepGeom_TrimmingMember", "For immediate members of TrimmingSelect, i.e. : ParameterValue (a Real)");

// Constructors
cls_StepGeom_TrimmingMember.def(py::init<>());

// Methods
cls_StepGeom_TrimmingMember.def("HasName", (Standard_Boolean (StepGeom_TrimmingMember::*)() const) &StepGeom_TrimmingMember::HasName, "None");
cls_StepGeom_TrimmingMember.def("Name", (Standard_CString (StepGeom_TrimmingMember::*)() const) &StepGeom_TrimmingMember::Name, "None");
cls_StepGeom_TrimmingMember.def("SetName", (Standard_Boolean (StepGeom_TrimmingMember::*)(const Standard_CString)) &StepGeom_TrimmingMember::SetName, "None", py::arg("name"));
cls_StepGeom_TrimmingMember.def_static("get_type_name_", (const char * (*)()) &StepGeom_TrimmingMember::get_type_name, "None");
cls_StepGeom_TrimmingMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_TrimmingMember::get_type_descriptor, "None");
cls_StepGeom_TrimmingMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_TrimmingMember::*)() const) &StepGeom_TrimmingMember::DynamicType, "None");

// CLASS: STEPGEOM_UNIFORMCURVE
py::class_<StepGeom_UniformCurve, opencascade::handle<StepGeom_UniformCurve>, StepGeom_BSplineCurve> cls_StepGeom_UniformCurve(mod, "StepGeom_UniformCurve", "None");

// Constructors
cls_StepGeom_UniformCurve.def(py::init<>());

// Methods
cls_StepGeom_UniformCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_UniformCurve::get_type_name, "None");
cls_StepGeom_UniformCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_UniformCurve::get_type_descriptor, "None");
cls_StepGeom_UniformCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_UniformCurve::*)() const) &StepGeom_UniformCurve::DynamicType, "None");

// CLASS: STEPGEOM_UNIFORMCURVEANDRATIONALBSPLINECURVE
py::class_<StepGeom_UniformCurveAndRationalBSplineCurve, opencascade::handle<StepGeom_UniformCurveAndRationalBSplineCurve>, StepGeom_BSplineCurve> cls_StepGeom_UniformCurveAndRationalBSplineCurve(mod, "StepGeom_UniformCurveAndRationalBSplineCurve", "None");

// Constructors
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def(py::init<>());

// Methods
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def("Init", (void (StepGeom_UniformCurveAndRationalBSplineCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &, const StepGeom_BSplineCurveForm, const StepData_Logical, const StepData_Logical, const opencascade::handle<StepGeom_UniformCurve> &, const opencascade::handle<StepGeom_RationalBSplineCurve> &)) &StepGeom_UniformCurveAndRationalBSplineCurve::Init, "None", py::arg("aName"), py::arg("aDegree"), py::arg("aControlPointsList"), py::arg("aCurveForm"), py::arg("aClosedCurve"), py::arg("aSelfIntersect"), py::arg("aUniformCurve"), py::arg("aRationalBSplineCurve"));
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def("Init", (void (StepGeom_UniformCurveAndRationalBSplineCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &, const StepGeom_BSplineCurveForm, const StepData_Logical, const StepData_Logical, const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_UniformCurveAndRationalBSplineCurve::Init, "None", py::arg("aName"), py::arg("aDegree"), py::arg("aControlPointsList"), py::arg("aCurveForm"), py::arg("aClosedCurve"), py::arg("aSelfIntersect"), py::arg("aWeightsData"));
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def("SetUniformCurve", (void (StepGeom_UniformCurveAndRationalBSplineCurve::*)(const opencascade::handle<StepGeom_UniformCurve> &)) &StepGeom_UniformCurveAndRationalBSplineCurve::SetUniformCurve, "None", py::arg("aUniformCurve"));
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def("UniformCurve", (opencascade::handle<StepGeom_UniformCurve> (StepGeom_UniformCurveAndRationalBSplineCurve::*)() const) &StepGeom_UniformCurveAndRationalBSplineCurve::UniformCurve, "None");
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def("SetRationalBSplineCurve", (void (StepGeom_UniformCurveAndRationalBSplineCurve::*)(const opencascade::handle<StepGeom_RationalBSplineCurve> &)) &StepGeom_UniformCurveAndRationalBSplineCurve::SetRationalBSplineCurve, "None", py::arg("aRationalBSplineCurve"));
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def("RationalBSplineCurve", (opencascade::handle<StepGeom_RationalBSplineCurve> (StepGeom_UniformCurveAndRationalBSplineCurve::*)() const) &StepGeom_UniformCurveAndRationalBSplineCurve::RationalBSplineCurve, "None");
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def("SetWeightsData", (void (StepGeom_UniformCurveAndRationalBSplineCurve::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_UniformCurveAndRationalBSplineCurve::SetWeightsData, "None", py::arg("aWeightsData"));
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def("WeightsData", (opencascade::handle<TColStd_HArray1OfReal> (StepGeom_UniformCurveAndRationalBSplineCurve::*)() const) &StepGeom_UniformCurveAndRationalBSplineCurve::WeightsData, "None");
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def("WeightsDataValue", (Standard_Real (StepGeom_UniformCurveAndRationalBSplineCurve::*)(const Standard_Integer) const) &StepGeom_UniformCurveAndRationalBSplineCurve::WeightsDataValue, "None", py::arg("num"));
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def("NbWeightsData", (Standard_Integer (StepGeom_UniformCurveAndRationalBSplineCurve::*)() const) &StepGeom_UniformCurveAndRationalBSplineCurve::NbWeightsData, "None");
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_UniformCurveAndRationalBSplineCurve::get_type_name, "None");
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_UniformCurveAndRationalBSplineCurve::get_type_descriptor, "None");
cls_StepGeom_UniformCurveAndRationalBSplineCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_UniformCurveAndRationalBSplineCurve::*)() const) &StepGeom_UniformCurveAndRationalBSplineCurve::DynamicType, "None");

// CLASS: STEPGEOM_UNIFORMSURFACE
py::class_<StepGeom_UniformSurface, opencascade::handle<StepGeom_UniformSurface>, StepGeom_BSplineSurface> cls_StepGeom_UniformSurface(mod, "StepGeom_UniformSurface", "None");

// Constructors
cls_StepGeom_UniformSurface.def(py::init<>());

// Methods
cls_StepGeom_UniformSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_UniformSurface::get_type_name, "None");
cls_StepGeom_UniformSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_UniformSurface::get_type_descriptor, "None");
cls_StepGeom_UniformSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_UniformSurface::*)() const) &StepGeom_UniformSurface::DynamicType, "None");

// CLASS: STEPGEOM_UNIFORMSURFACEANDRATIONALBSPLINESURFACE
py::class_<StepGeom_UniformSurfaceAndRationalBSplineSurface, opencascade::handle<StepGeom_UniformSurfaceAndRationalBSplineSurface>, StepGeom_BSplineSurface> cls_StepGeom_UniformSurfaceAndRationalBSplineSurface(mod, "StepGeom_UniformSurfaceAndRationalBSplineSurface", "None");

// Constructors
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def(py::init<>());

// Methods
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def("Init", (void (StepGeom_UniformSurfaceAndRationalBSplineSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Integer, const opencascade::handle<StepGeom_HArray2OfCartesianPoint> &, const StepGeom_BSplineSurfaceForm, const StepData_Logical, const StepData_Logical, const StepData_Logical, const opencascade::handle<StepGeom_UniformSurface> &, const opencascade::handle<StepGeom_RationalBSplineSurface> &)) &StepGeom_UniformSurfaceAndRationalBSplineSurface::Init, "None", py::arg("aName"), py::arg("aUDegree"), py::arg("aVDegree"), py::arg("aControlPointsList"), py::arg("aSurfaceForm"), py::arg("aUClosed"), py::arg("aVClosed"), py::arg("aSelfIntersect"), py::arg("aUniformSurface"), py::arg("aRationalBSplineSurface"));
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def("Init", (void (StepGeom_UniformSurfaceAndRationalBSplineSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Integer, const opencascade::handle<StepGeom_HArray2OfCartesianPoint> &, const StepGeom_BSplineSurfaceForm, const StepData_Logical, const StepData_Logical, const StepData_Logical, const opencascade::handle<TColStd_HArray2OfReal> &)) &StepGeom_UniformSurfaceAndRationalBSplineSurface::Init, "None", py::arg("aName"), py::arg("aUDegree"), py::arg("aVDegree"), py::arg("aControlPointsList"), py::arg("aSurfaceForm"), py::arg("aUClosed"), py::arg("aVClosed"), py::arg("aSelfIntersect"), py::arg("aWeightsData"));
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def("SetUniformSurface", (void (StepGeom_UniformSurfaceAndRationalBSplineSurface::*)(const opencascade::handle<StepGeom_UniformSurface> &)) &StepGeom_UniformSurfaceAndRationalBSplineSurface::SetUniformSurface, "None", py::arg("aUniformSurface"));
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def("UniformSurface", (opencascade::handle<StepGeom_UniformSurface> (StepGeom_UniformSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_UniformSurfaceAndRationalBSplineSurface::UniformSurface, "None");
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def("SetRationalBSplineSurface", (void (StepGeom_UniformSurfaceAndRationalBSplineSurface::*)(const opencascade::handle<StepGeom_RationalBSplineSurface> &)) &StepGeom_UniformSurfaceAndRationalBSplineSurface::SetRationalBSplineSurface, "None", py::arg("aRationalBSplineSurface"));
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def("RationalBSplineSurface", (opencascade::handle<StepGeom_RationalBSplineSurface> (StepGeom_UniformSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_UniformSurfaceAndRationalBSplineSurface::RationalBSplineSurface, "None");
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def("SetWeightsData", (void (StepGeom_UniformSurfaceAndRationalBSplineSurface::*)(const opencascade::handle<TColStd_HArray2OfReal> &)) &StepGeom_UniformSurfaceAndRationalBSplineSurface::SetWeightsData, "None", py::arg("aWeightsData"));
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def("WeightsData", (opencascade::handle<TColStd_HArray2OfReal> (StepGeom_UniformSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_UniformSurfaceAndRationalBSplineSurface::WeightsData, "None");
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def("WeightsDataValue", (Standard_Real (StepGeom_UniformSurfaceAndRationalBSplineSurface::*)(const Standard_Integer, const Standard_Integer) const) &StepGeom_UniformSurfaceAndRationalBSplineSurface::WeightsDataValue, "None", py::arg("num1"), py::arg("num2"));
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def("NbWeightsDataI", (Standard_Integer (StepGeom_UniformSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_UniformSurfaceAndRationalBSplineSurface::NbWeightsDataI, "None");
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def("NbWeightsDataJ", (Standard_Integer (StepGeom_UniformSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_UniformSurfaceAndRationalBSplineSurface::NbWeightsDataJ, "None");
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_UniformSurfaceAndRationalBSplineSurface::get_type_name, "None");
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_UniformSurfaceAndRationalBSplineSurface::get_type_descriptor, "None");
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_UniformSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_UniformSurfaceAndRationalBSplineSurface::DynamicType, "None");

// CLASS: STEPGEOM_VECTOR
py::class_<StepGeom_Vector, opencascade::handle<StepGeom_Vector>, StepGeom_GeometricRepresentationItem> cls_StepGeom_Vector(mod, "StepGeom_Vector", "None");

// Constructors
cls_StepGeom_Vector.def(py::init<>());

// Methods
cls_StepGeom_Vector.def("Init", (void (StepGeom_Vector::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Direction> &, const Standard_Real)) &StepGeom_Vector::Init, "None", py::arg("aName"), py::arg("aOrientation"), py::arg("aMagnitude"));
cls_StepGeom_Vector.def("SetOrientation", (void (StepGeom_Vector::*)(const opencascade::handle<StepGeom_Direction> &)) &StepGeom_Vector::SetOrientation, "None", py::arg("aOrientation"));
cls_StepGeom_Vector.def("Orientation", (opencascade::handle<StepGeom_Direction> (StepGeom_Vector::*)() const) &StepGeom_Vector::Orientation, "None");
cls_StepGeom_Vector.def("SetMagnitude", (void (StepGeom_Vector::*)(const Standard_Real)) &StepGeom_Vector::SetMagnitude, "None", py::arg("aMagnitude"));
cls_StepGeom_Vector.def("Magnitude", (Standard_Real (StepGeom_Vector::*)() const) &StepGeom_Vector::Magnitude, "None");
cls_StepGeom_Vector.def_static("get_type_name_", (const char * (*)()) &StepGeom_Vector::get_type_name, "None");
cls_StepGeom_Vector.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Vector::get_type_descriptor, "None");
cls_StepGeom_Vector.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Vector::*)() const) &StepGeom_Vector::DynamicType, "None");

// CLASS: STEPGEOM_VECTORORDIRECTION
py::class_<StepGeom_VectorOrDirection, StepData_SelectType> cls_StepGeom_VectorOrDirection(mod, "StepGeom_VectorOrDirection", "None");

// Constructors
cls_StepGeom_VectorOrDirection.def(py::init<>());

// Methods
// cls_StepGeom_VectorOrDirection.def_static("operator new_", (void * (*)(size_t)) &StepGeom_VectorOrDirection::operator new, "None", py::arg("theSize"));
// cls_StepGeom_VectorOrDirection.def_static("operator delete_", (void (*)(void *)) &StepGeom_VectorOrDirection::operator delete, "None", py::arg("theAddress"));
// cls_StepGeom_VectorOrDirection.def_static("operator new[]_", (void * (*)(size_t)) &StepGeom_VectorOrDirection::operator new[], "None", py::arg("theSize"));
// cls_StepGeom_VectorOrDirection.def_static("operator delete[]_", (void (*)(void *)) &StepGeom_VectorOrDirection::operator delete[], "None", py::arg("theAddress"));
// cls_StepGeom_VectorOrDirection.def_static("operator new_", (void * (*)(size_t, void *)) &StepGeom_VectorOrDirection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepGeom_VectorOrDirection.def_static("operator delete_", (void (*)(void *, void *)) &StepGeom_VectorOrDirection::operator delete, "None", py::arg(""), py::arg(""));
cls_StepGeom_VectorOrDirection.def("CaseNum", (Standard_Integer (StepGeom_VectorOrDirection::*)(const opencascade::handle<Standard_Transient> &) const) &StepGeom_VectorOrDirection::CaseNum, "Recognizes a VectorOrDirection Kind Entity that is : 1 -> Vector 2 -> Direction 0 else", py::arg("ent"));
cls_StepGeom_VectorOrDirection.def("Vector", (opencascade::handle<StepGeom_Vector> (StepGeom_VectorOrDirection::*)() const) &StepGeom_VectorOrDirection::Vector, "returns Value as a Vector (Null if another type)");
cls_StepGeom_VectorOrDirection.def("Direction", (opencascade::handle<StepGeom_Direction> (StepGeom_VectorOrDirection::*)() const) &StepGeom_VectorOrDirection::Direction, "returns Value as a Direction (Null if another type)");


}
