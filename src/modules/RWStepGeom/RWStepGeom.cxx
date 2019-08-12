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

void bind_RWStepGeom_RWAxis1Placement(py::module &);
void bind_RWStepGeom_RWAxis2Placement2d(py::module &);
void bind_RWStepGeom_RWAxis2Placement3d(py::module &);
void bind_RWStepGeom_RWBezierCurve(py::module &);
void bind_RWStepGeom_RWBezierCurveAndRationalBSplineCurve(py::module &);
void bind_RWStepGeom_RWBezierSurface(py::module &);
void bind_RWStepGeom_RWBezierSurfaceAndRationalBSplineSurface(py::module &);
void bind_RWStepGeom_RWBoundaryCurve(py::module &);
void bind_RWStepGeom_RWBoundedCurve(py::module &);
void bind_RWStepGeom_RWBoundedSurface(py::module &);
void bind_RWStepGeom_RWBSplineCurve(py::module &);
void bind_RWStepGeom_RWBSplineCurveWithKnots(py::module &);
void bind_RWStepGeom_RWBSplineCurveWithKnotsAndRationalBSplineCurve(py::module &);
void bind_RWStepGeom_RWBSplineSurface(py::module &);
void bind_RWStepGeom_RWBSplineSurfaceWithKnots(py::module &);
void bind_RWStepGeom_RWBSplineSurfaceWithKnotsAndRationalBSplineSurface(py::module &);
void bind_RWStepGeom_RWCartesianPoint(py::module &);
void bind_RWStepGeom_RWCartesianTransformationOperator(py::module &);
void bind_RWStepGeom_RWCartesianTransformationOperator3d(py::module &);
void bind_RWStepGeom_RWCircle(py::module &);
void bind_RWStepGeom_RWCompositeCurve(py::module &);
void bind_RWStepGeom_RWCompositeCurveOnSurface(py::module &);
void bind_RWStepGeom_RWCompositeCurveSegment(py::module &);
void bind_RWStepGeom_RWConic(py::module &);
void bind_RWStepGeom_RWConicalSurface(py::module &);
void bind_RWStepGeom_RWCurve(py::module &);
void bind_RWStepGeom_RWCurveBoundedSurface(py::module &);
void bind_RWStepGeom_RWCurveReplica(py::module &);
void bind_RWStepGeom_RWCylindricalSurface(py::module &);
void bind_RWStepGeom_RWDegeneratePcurve(py::module &);
void bind_RWStepGeom_RWDegenerateToroidalSurface(py::module &);
void bind_RWStepGeom_RWDirection(py::module &);
void bind_RWStepGeom_RWElementarySurface(py::module &);
void bind_RWStepGeom_RWEllipse(py::module &);
void bind_RWStepGeom_RWEvaluatedDegeneratePcurve(py::module &);
void bind_RWStepGeom_RWGeometricRepresentationContext(py::module &);
void bind_RWStepGeom_RWGeometricRepresentationContextAndGlobalUnitAssignedContext(py::module &);
void bind_RWStepGeom_RWGeometricRepresentationContextAndParametricRepresentationContext(py::module &);
void bind_RWStepGeom_RWGeometricRepresentationItem(py::module &);
void bind_RWStepGeom_RWGeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx(py::module &);
void bind_RWStepGeom_RWHyperbola(py::module &);
void bind_RWStepGeom_RWIntersectionCurve(py::module &);
void bind_RWStepGeom_RWLine(py::module &);
void bind_RWStepGeom_RWOffsetCurve3d(py::module &);
void bind_RWStepGeom_RWOffsetSurface(py::module &);
void bind_RWStepGeom_RWOrientedSurface(py::module &);
void bind_RWStepGeom_RWOuterBoundaryCurve(py::module &);
void bind_RWStepGeom_RWParabola(py::module &);
void bind_RWStepGeom_RWPcurve(py::module &);
void bind_RWStepGeom_RWPlacement(py::module &);
void bind_RWStepGeom_RWPlane(py::module &);
void bind_RWStepGeom_RWPoint(py::module &);
void bind_RWStepGeom_RWPointOnCurve(py::module &);
void bind_RWStepGeom_RWPointOnSurface(py::module &);
void bind_RWStepGeom_RWPointReplica(py::module &);
void bind_RWStepGeom_RWPolyline(py::module &);
void bind_RWStepGeom_RWQuasiUniformCurve(py::module &);
void bind_RWStepGeom_RWQuasiUniformCurveAndRationalBSplineCurve(py::module &);
void bind_RWStepGeom_RWQuasiUniformSurface(py::module &);
void bind_RWStepGeom_RWQuasiUniformSurfaceAndRationalBSplineSurface(py::module &);
void bind_RWStepGeom_RWRationalBSplineCurve(py::module &);
void bind_RWStepGeom_RWRationalBSplineSurface(py::module &);
void bind_RWStepGeom_RWRectangularCompositeSurface(py::module &);
void bind_RWStepGeom_RWRectangularTrimmedSurface(py::module &);
void bind_RWStepGeom_RWReparametrisedCompositeCurveSegment(py::module &);
void bind_RWStepGeom_RWSeamCurve(py::module &);
void bind_RWStepGeom_RWSphericalSurface(py::module &);
void bind_RWStepGeom_RWSurface(py::module &);
void bind_RWStepGeom_RWSurfaceCurve(py::module &);
void bind_RWStepGeom_RWSurfaceCurveAndBoundedCurve(py::module &);
void bind_RWStepGeom_RWSurfaceOfLinearExtrusion(py::module &);
void bind_RWStepGeom_RWSurfaceOfRevolution(py::module &);
void bind_RWStepGeom_RWSurfacePatch(py::module &);
void bind_RWStepGeom_RWSurfaceReplica(py::module &);
void bind_RWStepGeom_RWSweptSurface(py::module &);
void bind_RWStepGeom_RWToroidalSurface(py::module &);
void bind_RWStepGeom_RWTrimmedCurve(py::module &);
void bind_RWStepGeom_RWUniformCurve(py::module &);
void bind_RWStepGeom_RWUniformCurveAndRationalBSplineCurve(py::module &);
void bind_RWStepGeom_RWUniformSurface(py::module &);
void bind_RWStepGeom_RWUniformSurfaceAndRationalBSplineSurface(py::module &);
void bind_RWStepGeom_RWVector(py::module &);

PYBIND11_MODULE(RWStepGeom, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.StepData");
py::module::import("OCCT.Interface");
py::module::import("OCCT.StepGeom");

bind_RWStepGeom_RWAxis1Placement(mod);
bind_RWStepGeom_RWAxis2Placement2d(mod);
bind_RWStepGeom_RWAxis2Placement3d(mod);
bind_RWStepGeom_RWBezierCurve(mod);
bind_RWStepGeom_RWBezierCurveAndRationalBSplineCurve(mod);
bind_RWStepGeom_RWBezierSurface(mod);
bind_RWStepGeom_RWBezierSurfaceAndRationalBSplineSurface(mod);
bind_RWStepGeom_RWBoundaryCurve(mod);
bind_RWStepGeom_RWBoundedCurve(mod);
bind_RWStepGeom_RWBoundedSurface(mod);
bind_RWStepGeom_RWBSplineCurve(mod);
bind_RWStepGeom_RWBSplineCurveWithKnots(mod);
bind_RWStepGeom_RWBSplineCurveWithKnotsAndRationalBSplineCurve(mod);
bind_RWStepGeom_RWBSplineSurface(mod);
bind_RWStepGeom_RWBSplineSurfaceWithKnots(mod);
bind_RWStepGeom_RWBSplineSurfaceWithKnotsAndRationalBSplineSurface(mod);
bind_RWStepGeom_RWCartesianPoint(mod);
bind_RWStepGeom_RWCartesianTransformationOperator(mod);
bind_RWStepGeom_RWCartesianTransformationOperator3d(mod);
bind_RWStepGeom_RWCircle(mod);
bind_RWStepGeom_RWCompositeCurve(mod);
bind_RWStepGeom_RWCompositeCurveOnSurface(mod);
bind_RWStepGeom_RWCompositeCurveSegment(mod);
bind_RWStepGeom_RWConic(mod);
bind_RWStepGeom_RWConicalSurface(mod);
bind_RWStepGeom_RWCurve(mod);
bind_RWStepGeom_RWCurveBoundedSurface(mod);
bind_RWStepGeom_RWCurveReplica(mod);
bind_RWStepGeom_RWCylindricalSurface(mod);
bind_RWStepGeom_RWDegeneratePcurve(mod);
bind_RWStepGeom_RWDegenerateToroidalSurface(mod);
bind_RWStepGeom_RWDirection(mod);
bind_RWStepGeom_RWElementarySurface(mod);
bind_RWStepGeom_RWEllipse(mod);
bind_RWStepGeom_RWEvaluatedDegeneratePcurve(mod);
bind_RWStepGeom_RWGeometricRepresentationContext(mod);
bind_RWStepGeom_RWGeometricRepresentationContextAndGlobalUnitAssignedContext(mod);
bind_RWStepGeom_RWGeometricRepresentationContextAndParametricRepresentationContext(mod);
bind_RWStepGeom_RWGeometricRepresentationItem(mod);
bind_RWStepGeom_RWGeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx(mod);
bind_RWStepGeom_RWHyperbola(mod);
bind_RWStepGeom_RWIntersectionCurve(mod);
bind_RWStepGeom_RWLine(mod);
bind_RWStepGeom_RWOffsetCurve3d(mod);
bind_RWStepGeom_RWOffsetSurface(mod);
bind_RWStepGeom_RWOrientedSurface(mod);
bind_RWStepGeom_RWOuterBoundaryCurve(mod);
bind_RWStepGeom_RWParabola(mod);
bind_RWStepGeom_RWPcurve(mod);
bind_RWStepGeom_RWPlacement(mod);
bind_RWStepGeom_RWPlane(mod);
bind_RWStepGeom_RWPoint(mod);
bind_RWStepGeom_RWPointOnCurve(mod);
bind_RWStepGeom_RWPointOnSurface(mod);
bind_RWStepGeom_RWPointReplica(mod);
bind_RWStepGeom_RWPolyline(mod);
bind_RWStepGeom_RWQuasiUniformCurve(mod);
bind_RWStepGeom_RWQuasiUniformCurveAndRationalBSplineCurve(mod);
bind_RWStepGeom_RWQuasiUniformSurface(mod);
bind_RWStepGeom_RWQuasiUniformSurfaceAndRationalBSplineSurface(mod);
bind_RWStepGeom_RWRationalBSplineCurve(mod);
bind_RWStepGeom_RWRationalBSplineSurface(mod);
bind_RWStepGeom_RWRectangularCompositeSurface(mod);
bind_RWStepGeom_RWRectangularTrimmedSurface(mod);
bind_RWStepGeom_RWReparametrisedCompositeCurveSegment(mod);
bind_RWStepGeom_RWSeamCurve(mod);
bind_RWStepGeom_RWSphericalSurface(mod);
bind_RWStepGeom_RWSurface(mod);
bind_RWStepGeom_RWSurfaceCurve(mod);
bind_RWStepGeom_RWSurfaceCurveAndBoundedCurve(mod);
bind_RWStepGeom_RWSurfaceOfLinearExtrusion(mod);
bind_RWStepGeom_RWSurfaceOfRevolution(mod);
bind_RWStepGeom_RWSurfacePatch(mod);
bind_RWStepGeom_RWSurfaceReplica(mod);
bind_RWStepGeom_RWSweptSurface(mod);
bind_RWStepGeom_RWToroidalSurface(mod);
bind_RWStepGeom_RWTrimmedCurve(mod);
bind_RWStepGeom_RWUniformCurve(mod);
bind_RWStepGeom_RWUniformCurveAndRationalBSplineCurve(mod);
bind_RWStepGeom_RWUniformSurface(mod);
bind_RWStepGeom_RWUniformSurfaceAndRationalBSplineSurface(mod);
bind_RWStepGeom_RWVector(mod);

}
