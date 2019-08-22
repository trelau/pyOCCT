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
#include <Standard_Handle.hxx>
#include <Geom_Axis1Placement.hxx>
#include <StepGeom_Axis1Placement.hxx>
#include <Geom_Axis2Placement.hxx>
#include <StepGeom_Axis2Placement3d.hxx>
#include <Geom2d_AxisPlacement.hxx>
#include <StepGeom_Axis2Placement2d.hxx>
#include <Geom_BoundedCurve.hxx>
#include <StepGeom_BoundedCurve.hxx>
#include <Geom2d_BoundedCurve.hxx>
#include <Geom_BoundedSurface.hxx>
#include <StepGeom_BoundedSurface.hxx>
#include <Geom_BSplineCurve.hxx>
#include <StepGeom_BSplineCurve.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Geom_BSplineSurface.hxx>
#include <StepGeom_BSplineSurface.hxx>
#include <Geom_CartesianPoint.hxx>
#include <StepGeom_CartesianPoint.hxx>
#include <Geom2d_CartesianPoint.hxx>
#include <Geom_Circle.hxx>
#include <StepGeom_Circle.hxx>
#include <Geom2d_Circle.hxx>
#include <Geom_Conic.hxx>
#include <StepGeom_Conic.hxx>
#include <Geom2d_Conic.hxx>
#include <Geom_ConicalSurface.hxx>
#include <StepGeom_ConicalSurface.hxx>
#include <Geom_Curve.hxx>
#include <StepGeom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_CylindricalSurface.hxx>
#include <StepGeom_CylindricalSurface.hxx>
#include <Geom_Direction.hxx>
#include <StepGeom_Direction.hxx>
#include <Geom2d_Direction.hxx>
#include <Geom_ElementarySurface.hxx>
#include <StepGeom_ElementarySurface.hxx>
#include <Geom_Ellipse.hxx>
#include <StepGeom_Ellipse.hxx>
#include <Geom2d_Ellipse.hxx>
#include <Geom_Hyperbola.hxx>
#include <StepGeom_Hyperbola.hxx>
#include <Geom2d_Hyperbola.hxx>
#include <Geom_Line.hxx>
#include <StepGeom_Line.hxx>
#include <Geom2d_Line.hxx>
#include <Geom_Parabola.hxx>
#include <StepGeom_Parabola.hxx>
#include <Geom2d_Parabola.hxx>
#include <Geom_Plane.hxx>
#include <StepGeom_Plane.hxx>
#include <StepGeom_Polyline.hxx>
#include <Geom_RectangularTrimmedSurface.hxx>
#include <StepGeom_RectangularTrimmedSurface.hxx>
#include <Geom_SphericalSurface.hxx>
#include <StepGeom_SphericalSurface.hxx>
#include <Geom_Surface.hxx>
#include <StepGeom_Surface.hxx>
#include <Geom_SurfaceOfLinearExtrusion.hxx>
#include <StepGeom_SurfaceOfLinearExtrusion.hxx>
#include <Geom_SurfaceOfRevolution.hxx>
#include <StepGeom_SurfaceOfRevolution.hxx>
#include <Geom_SweptSurface.hxx>
#include <StepGeom_SweptSurface.hxx>
#include <Geom_ToroidalSurface.hxx>
#include <StepGeom_ToroidalSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_CartesianTransformationOperator2d.hxx>
#include <gp_Trsf2d.hxx>
#include <StepGeom_CartesianTransformationOperator3d.hxx>
#include <gp_Trsf.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <StepGeom_TrimmedCurve.hxx>
#include <Geom_VectorWithMagnitude.hxx>
#include <StepGeom_Vector.hxx>
#include <Geom2d_VectorWithMagnitude.hxx>
#include <StepToGeom.hxx>

void bind_StepToGeom(py::module &mod){

py::class_<StepToGeom> cls_StepToGeom(mod, "StepToGeom", "This class provides static methods to convert STEP geometric entities to OCCT. The methods returning handles will return null handle in case of error. The methods returning boolean will return True if succeeded and False if error.");

// Constructors

// Fields

// Methods
cls_StepToGeom.def_static("MakeAxis1Placement_", (opencascade::handle<Geom_Axis1Placement> (*)(const opencascade::handle<StepGeom_Axis1Placement> &)) &StepToGeom::MakeAxis1Placement, "None", py::arg("SA"));
cls_StepToGeom.def_static("MakeAxis2Placement_", (opencascade::handle<Geom_Axis2Placement> (*)(const opencascade::handle<StepGeom_Axis2Placement3d> &)) &StepToGeom::MakeAxis2Placement, "None", py::arg("SA"));
cls_StepToGeom.def_static("MakeAxisPlacement_", (opencascade::handle<Geom2d_AxisPlacement> (*)(const opencascade::handle<StepGeom_Axis2Placement2d> &)) &StepToGeom::MakeAxisPlacement, "None", py::arg("SA"));
cls_StepToGeom.def_static("MakeBoundedCurve_", (opencascade::handle<Geom_BoundedCurve> (*)(const opencascade::handle<StepGeom_BoundedCurve> &)) &StepToGeom::MakeBoundedCurve, "None", py::arg("SC"));
cls_StepToGeom.def_static("MakeBoundedCurve2d_", (opencascade::handle<Geom2d_BoundedCurve> (*)(const opencascade::handle<StepGeom_BoundedCurve> &)) &StepToGeom::MakeBoundedCurve2d, "None", py::arg("SC"));
cls_StepToGeom.def_static("MakeBoundedSurface_", (opencascade::handle<Geom_BoundedSurface> (*)(const opencascade::handle<StepGeom_BoundedSurface> &)) &StepToGeom::MakeBoundedSurface, "None", py::arg("SS"));
cls_StepToGeom.def_static("MakeBSplineCurve_", (opencascade::handle<Geom_BSplineCurve> (*)(const opencascade::handle<StepGeom_BSplineCurve> &)) &StepToGeom::MakeBSplineCurve, "None", py::arg("SC"));
cls_StepToGeom.def_static("MakeBSplineCurve2d_", (opencascade::handle<Geom2d_BSplineCurve> (*)(const opencascade::handle<StepGeom_BSplineCurve> &)) &StepToGeom::MakeBSplineCurve2d, "None", py::arg("SC"));
cls_StepToGeom.def_static("MakeBSplineSurface_", (opencascade::handle<Geom_BSplineSurface> (*)(const opencascade::handle<StepGeom_BSplineSurface> &)) &StepToGeom::MakeBSplineSurface, "None", py::arg("SS"));
cls_StepToGeom.def_static("MakeCartesianPoint_", (opencascade::handle<Geom_CartesianPoint> (*)(const opencascade::handle<StepGeom_CartesianPoint> &)) &StepToGeom::MakeCartesianPoint, "None", py::arg("SP"));
cls_StepToGeom.def_static("MakeCartesianPoint2d_", (opencascade::handle<Geom2d_CartesianPoint> (*)(const opencascade::handle<StepGeom_CartesianPoint> &)) &StepToGeom::MakeCartesianPoint2d, "None", py::arg("SP"));
cls_StepToGeom.def_static("MakeCircle_", (opencascade::handle<Geom_Circle> (*)(const opencascade::handle<StepGeom_Circle> &)) &StepToGeom::MakeCircle, "None", py::arg("SC"));
cls_StepToGeom.def_static("MakeCircle2d_", (opencascade::handle<Geom2d_Circle> (*)(const opencascade::handle<StepGeom_Circle> &)) &StepToGeom::MakeCircle2d, "None", py::arg("SC"));
cls_StepToGeom.def_static("MakeConic_", (opencascade::handle<Geom_Conic> (*)(const opencascade::handle<StepGeom_Conic> &)) &StepToGeom::MakeConic, "None", py::arg("SC"));
cls_StepToGeom.def_static("MakeConic2d_", (opencascade::handle<Geom2d_Conic> (*)(const opencascade::handle<StepGeom_Conic> &)) &StepToGeom::MakeConic2d, "None", py::arg("SC"));
cls_StepToGeom.def_static("MakeConicalSurface_", (opencascade::handle<Geom_ConicalSurface> (*)(const opencascade::handle<StepGeom_ConicalSurface> &)) &StepToGeom::MakeConicalSurface, "None", py::arg("SS"));
cls_StepToGeom.def_static("MakeCurve_", (opencascade::handle<Geom_Curve> (*)(const opencascade::handle<StepGeom_Curve> &)) &StepToGeom::MakeCurve, "None", py::arg("SC"));
cls_StepToGeom.def_static("MakeCurve2d_", (opencascade::handle<Geom2d_Curve> (*)(const opencascade::handle<StepGeom_Curve> &)) &StepToGeom::MakeCurve2d, "None", py::arg("SC"));
cls_StepToGeom.def_static("MakeCylindricalSurface_", (opencascade::handle<Geom_CylindricalSurface> (*)(const opencascade::handle<StepGeom_CylindricalSurface> &)) &StepToGeom::MakeCylindricalSurface, "None", py::arg("SS"));
cls_StepToGeom.def_static("MakeDirection_", (opencascade::handle<Geom_Direction> (*)(const opencascade::handle<StepGeom_Direction> &)) &StepToGeom::MakeDirection, "None", py::arg("SD"));
cls_StepToGeom.def_static("MakeDirection2d_", (opencascade::handle<Geom2d_Direction> (*)(const opencascade::handle<StepGeom_Direction> &)) &StepToGeom::MakeDirection2d, "None", py::arg("SD"));
cls_StepToGeom.def_static("MakeElementarySurface_", (opencascade::handle<Geom_ElementarySurface> (*)(const opencascade::handle<StepGeom_ElementarySurface> &)) &StepToGeom::MakeElementarySurface, "None", py::arg("SS"));
cls_StepToGeom.def_static("MakeEllipse_", (opencascade::handle<Geom_Ellipse> (*)(const opencascade::handle<StepGeom_Ellipse> &)) &StepToGeom::MakeEllipse, "None", py::arg("SC"));
cls_StepToGeom.def_static("MakeEllipse2d_", (opencascade::handle<Geom2d_Ellipse> (*)(const opencascade::handle<StepGeom_Ellipse> &)) &StepToGeom::MakeEllipse2d, "None", py::arg("SC"));
cls_StepToGeom.def_static("MakeHyperbola_", (opencascade::handle<Geom_Hyperbola> (*)(const opencascade::handle<StepGeom_Hyperbola> &)) &StepToGeom::MakeHyperbola, "None", py::arg("SC"));
cls_StepToGeom.def_static("MakeHyperbola2d_", (opencascade::handle<Geom2d_Hyperbola> (*)(const opencascade::handle<StepGeom_Hyperbola> &)) &StepToGeom::MakeHyperbola2d, "None", py::arg("SC"));
cls_StepToGeom.def_static("MakeLine_", (opencascade::handle<Geom_Line> (*)(const opencascade::handle<StepGeom_Line> &)) &StepToGeom::MakeLine, "None", py::arg("SC"));
cls_StepToGeom.def_static("MakeLine2d_", (opencascade::handle<Geom2d_Line> (*)(const opencascade::handle<StepGeom_Line> &)) &StepToGeom::MakeLine2d, "None", py::arg("SC"));
cls_StepToGeom.def_static("MakeParabola_", (opencascade::handle<Geom_Parabola> (*)(const opencascade::handle<StepGeom_Parabola> &)) &StepToGeom::MakeParabola, "None", py::arg("SC"));
cls_StepToGeom.def_static("MakeParabola2d_", (opencascade::handle<Geom2d_Parabola> (*)(const opencascade::handle<StepGeom_Parabola> &)) &StepToGeom::MakeParabola2d, "None", py::arg("SC"));
cls_StepToGeom.def_static("MakePlane_", (opencascade::handle<Geom_Plane> (*)(const opencascade::handle<StepGeom_Plane> &)) &StepToGeom::MakePlane, "None", py::arg("SP"));
cls_StepToGeom.def_static("MakePolyline_", (opencascade::handle<Geom_BSplineCurve> (*)(const opencascade::handle<StepGeom_Polyline> &)) &StepToGeom::MakePolyline, "None", py::arg("SPL"));
cls_StepToGeom.def_static("MakePolyline2d_", (opencascade::handle<Geom2d_BSplineCurve> (*)(const opencascade::handle<StepGeom_Polyline> &)) &StepToGeom::MakePolyline2d, "None", py::arg("SPL"));
cls_StepToGeom.def_static("MakeRectangularTrimmedSurface_", (opencascade::handle<Geom_RectangularTrimmedSurface> (*)(const opencascade::handle<StepGeom_RectangularTrimmedSurface> &)) &StepToGeom::MakeRectangularTrimmedSurface, "None", py::arg("SS"));
cls_StepToGeom.def_static("MakeSphericalSurface_", (opencascade::handle<Geom_SphericalSurface> (*)(const opencascade::handle<StepGeom_SphericalSurface> &)) &StepToGeom::MakeSphericalSurface, "None", py::arg("SS"));
cls_StepToGeom.def_static("MakeSurface_", (opencascade::handle<Geom_Surface> (*)(const opencascade::handle<StepGeom_Surface> &)) &StepToGeom::MakeSurface, "None", py::arg("SS"));
cls_StepToGeom.def_static("MakeSurfaceOfLinearExtrusion_", (opencascade::handle<Geom_SurfaceOfLinearExtrusion> (*)(const opencascade::handle<StepGeom_SurfaceOfLinearExtrusion> &)) &StepToGeom::MakeSurfaceOfLinearExtrusion, "None", py::arg("SS"));
cls_StepToGeom.def_static("MakeSurfaceOfRevolution_", (opencascade::handle<Geom_SurfaceOfRevolution> (*)(const opencascade::handle<StepGeom_SurfaceOfRevolution> &)) &StepToGeom::MakeSurfaceOfRevolution, "None", py::arg("SS"));
cls_StepToGeom.def_static("MakeSweptSurface_", (opencascade::handle<Geom_SweptSurface> (*)(const opencascade::handle<StepGeom_SweptSurface> &)) &StepToGeom::MakeSweptSurface, "None", py::arg("SS"));
cls_StepToGeom.def_static("MakeToroidalSurface_", (opencascade::handle<Geom_ToroidalSurface> (*)(const opencascade::handle<StepGeom_ToroidalSurface> &)) &StepToGeom::MakeToroidalSurface, "None", py::arg("SS"));
cls_StepToGeom.def_static("MakeTransformation2d_", (Standard_Boolean (*)(const opencascade::handle<StepGeom_CartesianTransformationOperator2d> &, gp_Trsf2d &)) &StepToGeom::MakeTransformation2d, "None", py::arg("SCTO"), py::arg("CT"));
cls_StepToGeom.def_static("MakeTransformation3d_", (Standard_Boolean (*)(const opencascade::handle<StepGeom_CartesianTransformationOperator3d> &, gp_Trsf &)) &StepToGeom::MakeTransformation3d, "None", py::arg("SCTO"), py::arg("CT"));
cls_StepToGeom.def_static("MakeTrimmedCurve_", (opencascade::handle<Geom_TrimmedCurve> (*)(const opencascade::handle<StepGeom_TrimmedCurve> &)) &StepToGeom::MakeTrimmedCurve, "None", py::arg("SC"));
cls_StepToGeom.def_static("MakeTrimmedCurve2d_", (opencascade::handle<Geom2d_BSplineCurve> (*)(const opencascade::handle<StepGeom_TrimmedCurve> &)) &StepToGeom::MakeTrimmedCurve2d, "None", py::arg("SC"));
cls_StepToGeom.def_static("MakeVectorWithMagnitude_", (opencascade::handle<Geom_VectorWithMagnitude> (*)(const opencascade::handle<StepGeom_Vector> &)) &StepToGeom::MakeVectorWithMagnitude, "None", py::arg("SV"));
cls_StepToGeom.def_static("MakeVectorWithMagnitude2d_", (opencascade::handle<Geom2d_VectorWithMagnitude> (*)(const opencascade::handle<StepGeom_Vector> &)) &StepToGeom::MakeVectorWithMagnitude2d, "None", py::arg("SV"));

// Enums

}