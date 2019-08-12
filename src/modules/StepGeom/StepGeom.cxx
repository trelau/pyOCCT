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

void bind_StepGeom_TransitionCode(py::module &);
void bind_StepGeom_BSplineCurveForm(py::module &);
void bind_StepGeom_BSplineSurfaceForm(py::module &);
void bind_StepGeom_KnotType(py::module &);
void bind_StepGeom_PreferredSurfaceCurveRepresentation(py::module &);
void bind_StepGeom_TrimmingPreference(py::module &);
void bind_StepGeom_GeometricRepresentationItem(py::module &);
void bind_StepGeom_Placement(py::module &);
void bind_StepGeom_Axis2Placement3d(py::module &);
void bind_StepGeom_Point(py::module &);
void bind_StepGeom_CompositeCurveSegment(py::module &);
void bind_StepGeom_Array1OfCompositeCurveSegment(py::module &);
void bind_StepGeom_HArray1OfCompositeCurveSegment(py::module &);
void bind_StepGeom_Curve(py::module &);
void bind_StepGeom_BoundedCurve(py::module &);
void bind_StepGeom_CompositeCurve(py::module &);
void bind_StepGeom_CompositeCurveOnSurface(py::module &);
void bind_StepGeom_BoundaryCurve(py::module &);
void bind_StepGeom_Array1OfBoundaryCurve(py::module &);
void bind_StepGeom_CartesianPoint(py::module &);
void bind_StepGeom_Array1OfCartesianPoint(py::module &);
void bind_StepGeom_Array1OfCurve(py::module &);
void bind_StepGeom_PcurveOrSurface(py::module &);
void bind_StepGeom_Array1OfPcurveOrSurface(py::module &);
void bind_StepGeom_SurfaceBoundary(py::module &);
void bind_StepGeom_Array1OfSurfaceBoundary(py::module &);
void bind_StepGeom_TrimmingSelect(py::module &);
void bind_StepGeom_Array1OfTrimmingSelect(py::module &);
void bind_StepGeom_Array2OfCartesianPoint(py::module &);
void bind_StepGeom_SurfacePatch(py::module &);
void bind_StepGeom_Array2OfSurfacePatch(py::module &);
void bind_StepGeom_Axis1Placement(py::module &);
void bind_StepGeom_Axis2Placement(py::module &);
void bind_StepGeom_Axis2Placement2d(py::module &);
void bind_StepGeom_HArray1OfCartesianPoint(py::module &);
void bind_StepGeom_BSplineCurve(py::module &);
void bind_StepGeom_BezierCurve(py::module &);
void bind_StepGeom_BezierCurveAndRationalBSplineCurve(py::module &);
void bind_StepGeom_HArray2OfCartesianPoint(py::module &);
void bind_StepGeom_Surface(py::module &);
void bind_StepGeom_BoundedSurface(py::module &);
void bind_StepGeom_BSplineSurface(py::module &);
void bind_StepGeom_BezierSurface(py::module &);
void bind_StepGeom_BezierSurfaceAndRationalBSplineSurface(py::module &);
void bind_StepGeom_BSplineCurveWithKnots(py::module &);
void bind_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve(py::module &);
void bind_StepGeom_BSplineSurfaceWithKnots(py::module &);
void bind_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface(py::module &);
void bind_StepGeom_CartesianTransformationOperator(py::module &);
void bind_StepGeom_CartesianTransformationOperator2d(py::module &);
void bind_StepGeom_CartesianTransformationOperator3d(py::module &);
void bind_StepGeom_Conic(py::module &);
void bind_StepGeom_Circle(py::module &);
void bind_StepGeom_ElementarySurface(py::module &);
void bind_StepGeom_ConicalSurface(py::module &);
void bind_StepGeom_HArray1OfSurfaceBoundary(py::module &);
void bind_StepGeom_CurveBoundedSurface(py::module &);
void bind_StepGeom_CurveOnSurface(py::module &);
void bind_StepGeom_CurveReplica(py::module &);
void bind_StepGeom_CylindricalSurface(py::module &);
void bind_StepGeom_DegeneratePcurve(py::module &);
void bind_StepGeom_ToroidalSurface(py::module &);
void bind_StepGeom_DegenerateToroidalSurface(py::module &);
void bind_StepGeom_Direction(py::module &);
void bind_StepGeom_Ellipse(py::module &);
void bind_StepGeom_EvaluatedDegeneratePcurve(py::module &);
void bind_StepGeom_GeometricRepresentationContext(py::module &);
void bind_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext(py::module &);
void bind_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext(py::module &);
void bind_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx(py::module &);
void bind_StepGeom_HArray1OfBoundaryCurve(py::module &);
void bind_StepGeom_HArray1OfCurve(py::module &);
void bind_StepGeom_HArray1OfPcurveOrSurface(py::module &);
void bind_StepGeom_HArray1OfTrimmingSelect(py::module &);
void bind_StepGeom_HArray2OfSurfacePatch(py::module &);
void bind_StepGeom_Hyperbola(py::module &);
void bind_StepGeom_SurfaceCurve(py::module &);
void bind_StepGeom_IntersectionCurve(py::module &);
void bind_StepGeom_Line(py::module &);
void bind_StepGeom_OffsetCurve3d(py::module &);
void bind_StepGeom_OffsetSurface(py::module &);
void bind_StepGeom_OrientedSurface(py::module &);
void bind_StepGeom_OuterBoundaryCurve(py::module &);
void bind_StepGeom_Parabola(py::module &);
void bind_StepGeom_Pcurve(py::module &);
void bind_StepGeom_Plane(py::module &);
void bind_StepGeom_PointOnCurve(py::module &);
void bind_StepGeom_PointOnSurface(py::module &);
void bind_StepGeom_PointReplica(py::module &);
void bind_StepGeom_Polyline(py::module &);
void bind_StepGeom_QuasiUniformCurve(py::module &);
void bind_StepGeom_QuasiUniformCurveAndRationalBSplineCurve(py::module &);
void bind_StepGeom_QuasiUniformSurface(py::module &);
void bind_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface(py::module &);
void bind_StepGeom_RationalBSplineCurve(py::module &);
void bind_StepGeom_RationalBSplineSurface(py::module &);
void bind_StepGeom_RectangularCompositeSurface(py::module &);
void bind_StepGeom_RectangularTrimmedSurface(py::module &);
void bind_StepGeom_ReparametrisedCompositeCurveSegment(py::module &);
void bind_StepGeom_SeamCurve(py::module &);
void bind_StepGeom_SphericalSurface(py::module &);
void bind_StepGeom_SurfaceCurveAndBoundedCurve(py::module &);
void bind_StepGeom_SweptSurface(py::module &);
void bind_StepGeom_SurfaceOfLinearExtrusion(py::module &);
void bind_StepGeom_SurfaceOfRevolution(py::module &);
void bind_StepGeom_SurfaceReplica(py::module &);
void bind_StepGeom_TrimmedCurve(py::module &);
void bind_StepGeom_TrimmingMember(py::module &);
void bind_StepGeom_UniformCurve(py::module &);
void bind_StepGeom_UniformCurveAndRationalBSplineCurve(py::module &);
void bind_StepGeom_UniformSurface(py::module &);
void bind_StepGeom_UniformSurfaceAndRationalBSplineSurface(py::module &);
void bind_StepGeom_Vector(py::module &);
void bind_StepGeom_VectorOrDirection(py::module &);

PYBIND11_MODULE(StepGeom, mod) {

py::module::import("OCCT.StepRepr");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.StepData");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.StepBasic");

bind_StepGeom_TransitionCode(mod);
bind_StepGeom_BSplineCurveForm(mod);
bind_StepGeom_BSplineSurfaceForm(mod);
bind_StepGeom_KnotType(mod);
bind_StepGeom_PreferredSurfaceCurveRepresentation(mod);
bind_StepGeom_TrimmingPreference(mod);
bind_StepGeom_GeometricRepresentationItem(mod);
bind_StepGeom_Placement(mod);
bind_StepGeom_Axis2Placement3d(mod);
bind_StepGeom_Point(mod);
bind_StepGeom_CompositeCurveSegment(mod);
bind_StepGeom_Array1OfCompositeCurveSegment(mod);
bind_StepGeom_HArray1OfCompositeCurveSegment(mod);
bind_StepGeom_Curve(mod);
bind_StepGeom_BoundedCurve(mod);
bind_StepGeom_CompositeCurve(mod);
bind_StepGeom_CompositeCurveOnSurface(mod);
bind_StepGeom_BoundaryCurve(mod);
bind_StepGeom_Array1OfBoundaryCurve(mod);
bind_StepGeom_CartesianPoint(mod);
bind_StepGeom_Array1OfCartesianPoint(mod);
bind_StepGeom_Array1OfCurve(mod);
bind_StepGeom_PcurveOrSurface(mod);
bind_StepGeom_Array1OfPcurveOrSurface(mod);
bind_StepGeom_SurfaceBoundary(mod);
bind_StepGeom_Array1OfSurfaceBoundary(mod);
bind_StepGeom_TrimmingSelect(mod);
bind_StepGeom_Array1OfTrimmingSelect(mod);
bind_StepGeom_Array2OfCartesianPoint(mod);
bind_StepGeom_SurfacePatch(mod);
bind_StepGeom_Array2OfSurfacePatch(mod);
bind_StepGeom_Axis1Placement(mod);
bind_StepGeom_Axis2Placement(mod);
bind_StepGeom_Axis2Placement2d(mod);
bind_StepGeom_HArray1OfCartesianPoint(mod);
bind_StepGeom_BSplineCurve(mod);
bind_StepGeom_BezierCurve(mod);
bind_StepGeom_BezierCurveAndRationalBSplineCurve(mod);
bind_StepGeom_HArray2OfCartesianPoint(mod);
bind_StepGeom_Surface(mod);
bind_StepGeom_BoundedSurface(mod);
bind_StepGeom_BSplineSurface(mod);
bind_StepGeom_BezierSurface(mod);
bind_StepGeom_BezierSurfaceAndRationalBSplineSurface(mod);
bind_StepGeom_BSplineCurveWithKnots(mod);
bind_StepGeom_BSplineCurveWithKnotsAndRationalBSplineCurve(mod);
bind_StepGeom_BSplineSurfaceWithKnots(mod);
bind_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface(mod);
bind_StepGeom_CartesianTransformationOperator(mod);
bind_StepGeom_CartesianTransformationOperator2d(mod);
bind_StepGeom_CartesianTransformationOperator3d(mod);
bind_StepGeom_Conic(mod);
bind_StepGeom_Circle(mod);
bind_StepGeom_ElementarySurface(mod);
bind_StepGeom_ConicalSurface(mod);
bind_StepGeom_HArray1OfSurfaceBoundary(mod);
bind_StepGeom_CurveBoundedSurface(mod);
bind_StepGeom_CurveOnSurface(mod);
bind_StepGeom_CurveReplica(mod);
bind_StepGeom_CylindricalSurface(mod);
bind_StepGeom_DegeneratePcurve(mod);
bind_StepGeom_ToroidalSurface(mod);
bind_StepGeom_DegenerateToroidalSurface(mod);
bind_StepGeom_Direction(mod);
bind_StepGeom_Ellipse(mod);
bind_StepGeom_EvaluatedDegeneratePcurve(mod);
bind_StepGeom_GeometricRepresentationContext(mod);
bind_StepGeom_GeometricRepresentationContextAndGlobalUnitAssignedContext(mod);
bind_StepGeom_GeometricRepresentationContextAndParametricRepresentationContext(mod);
bind_StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx(mod);
bind_StepGeom_HArray1OfBoundaryCurve(mod);
bind_StepGeom_HArray1OfCurve(mod);
bind_StepGeom_HArray1OfPcurveOrSurface(mod);
bind_StepGeom_HArray1OfTrimmingSelect(mod);
bind_StepGeom_HArray2OfSurfacePatch(mod);
bind_StepGeom_Hyperbola(mod);
bind_StepGeom_SurfaceCurve(mod);
bind_StepGeom_IntersectionCurve(mod);
bind_StepGeom_Line(mod);
bind_StepGeom_OffsetCurve3d(mod);
bind_StepGeom_OffsetSurface(mod);
bind_StepGeom_OrientedSurface(mod);
bind_StepGeom_OuterBoundaryCurve(mod);
bind_StepGeom_Parabola(mod);
bind_StepGeom_Pcurve(mod);
bind_StepGeom_Plane(mod);
bind_StepGeom_PointOnCurve(mod);
bind_StepGeom_PointOnSurface(mod);
bind_StepGeom_PointReplica(mod);
bind_StepGeom_Polyline(mod);
bind_StepGeom_QuasiUniformCurve(mod);
bind_StepGeom_QuasiUniformCurveAndRationalBSplineCurve(mod);
bind_StepGeom_QuasiUniformSurface(mod);
bind_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface(mod);
bind_StepGeom_RationalBSplineCurve(mod);
bind_StepGeom_RationalBSplineSurface(mod);
bind_StepGeom_RectangularCompositeSurface(mod);
bind_StepGeom_RectangularTrimmedSurface(mod);
bind_StepGeom_ReparametrisedCompositeCurveSegment(mod);
bind_StepGeom_SeamCurve(mod);
bind_StepGeom_SphericalSurface(mod);
bind_StepGeom_SurfaceCurveAndBoundedCurve(mod);
bind_StepGeom_SweptSurface(mod);
bind_StepGeom_SurfaceOfLinearExtrusion(mod);
bind_StepGeom_SurfaceOfRevolution(mod);
bind_StepGeom_SurfaceReplica(mod);
bind_StepGeom_TrimmedCurve(mod);
bind_StepGeom_TrimmingMember(mod);
bind_StepGeom_UniformCurve(mod);
bind_StepGeom_UniformCurveAndRationalBSplineCurve(mod);
bind_StepGeom_UniformSurface(mod);
bind_StepGeom_UniformSurfaceAndRationalBSplineSurface(mod);
bind_StepGeom_Vector(mod);
bind_StepGeom_VectorOrDirection(mod);

}
