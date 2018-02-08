/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <GeomAbs_Shape.hxx>
#include <GeomAbs_CurveType.hxx>
#include <GeomAbs_BSplKnotDistribution.hxx>
#include <GeomAbs_IsoType.hxx>
#include <GeomAbs_SurfaceType.hxx>
#include <GeomAbs_JoinType.hxx>
#include <GeomAbs_CurveForm.hxx>
#include <GeomAbs_SurfaceForm.hxx>
#include <GeomAbs_UVSense.hxx>

PYBIND11_MODULE(GeomAbs, mod) {

	// IMPORT

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomAbs_Shape.hxx
	py::enum_<GeomAbs_Shape>(mod, "GeomAbs_Shape", "Provides information about the continuity of a curve: - C0: only geometric continuity. - G1: for each point on the curve, the tangent vectors 'on the right' and 'on the left' are collinear with the same orientation. - C1: continuity of the first derivative. The 'C1' curve is also 'G1' but, in addition, the tangent vectors ' on the right' and 'on the left' are equal. - G2: for each point on the curve, the normalized normal vectors 'on the right' and 'on the left' are equal. - C2: continuity of the second derivative. - C3: continuity of the third derivative. - CN: continuity of the N-th derivative, whatever is the value given for N (infinite order of continuity). Also provides information about the continuity of a surface: - C0: only geometric continuity. - C1: continuity of the first derivatives; any isoparametric (in U or V) of a surface 'C1' is also 'C1'. - G2: for BSpline curves only; 'on the right' and 'on the left' of a knot the computation of the 'main curvature radii' and the 'main directions' (when they exist) gives the same result. - C2: continuity of the second derivative. - C3: continuity of the third derivative. - CN: continuity of any N-th derivative, whatever is the value given for N (infinite order of continuity). We may also say that a surface is 'Ci' in u, and 'Cj' in v to indicate the continuity of its derivatives up to the order i in the u parametric direction, and j in the v parametric direction.")
		.value("GeomAbs_C0", GeomAbs_Shape::GeomAbs_C0)
		.value("GeomAbs_G1", GeomAbs_Shape::GeomAbs_G1)
		.value("GeomAbs_C1", GeomAbs_Shape::GeomAbs_C1)
		.value("GeomAbs_G2", GeomAbs_Shape::GeomAbs_G2)
		.value("GeomAbs_C2", GeomAbs_Shape::GeomAbs_C2)
		.value("GeomAbs_C3", GeomAbs_Shape::GeomAbs_C3)
		.value("GeomAbs_CN", GeomAbs_Shape::GeomAbs_CN)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomAbs_CurveType.hxx
	py::enum_<GeomAbs_CurveType>(mod, "GeomAbs_CurveType", "Identifies the type of a curve.")
		.value("GeomAbs_Line", GeomAbs_CurveType::GeomAbs_Line)
		.value("GeomAbs_Circle", GeomAbs_CurveType::GeomAbs_Circle)
		.value("GeomAbs_Ellipse", GeomAbs_CurveType::GeomAbs_Ellipse)
		.value("GeomAbs_Hyperbola", GeomAbs_CurveType::GeomAbs_Hyperbola)
		.value("GeomAbs_Parabola", GeomAbs_CurveType::GeomAbs_Parabola)
		.value("GeomAbs_BezierCurve", GeomAbs_CurveType::GeomAbs_BezierCurve)
		.value("GeomAbs_BSplineCurve", GeomAbs_CurveType::GeomAbs_BSplineCurve)
		.value("GeomAbs_OffsetCurve", GeomAbs_CurveType::GeomAbs_OffsetCurve)
		.value("GeomAbs_OtherCurve", GeomAbs_CurveType::GeomAbs_OtherCurve)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomAbs_BSplKnotDistribution.hxx
	py::enum_<GeomAbs_BSplKnotDistribution>(mod, "GeomAbs_BSplKnotDistribution", "This enumeration is used in the classes BSplineCurve and BSplineSurface to describe the repartition of set of knots. (comments in classes BSplineCurve and BSplineSurface)")
		.value("GeomAbs_NonUniform", GeomAbs_BSplKnotDistribution::GeomAbs_NonUniform)
		.value("GeomAbs_Uniform", GeomAbs_BSplKnotDistribution::GeomAbs_Uniform)
		.value("GeomAbs_QuasiUniform", GeomAbs_BSplKnotDistribution::GeomAbs_QuasiUniform)
		.value("GeomAbs_PiecewiseBezier", GeomAbs_BSplKnotDistribution::GeomAbs_PiecewiseBezier)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomAbs_IsoType.hxx
	py::enum_<GeomAbs_IsoType>(mod, "GeomAbs_IsoType", "this enumeration describes if a curve is an U isoparaetric or V isoparametric")
		.value("GeomAbs_IsoU", GeomAbs_IsoType::GeomAbs_IsoU)
		.value("GeomAbs_IsoV", GeomAbs_IsoType::GeomAbs_IsoV)
		.value("GeomAbs_NoneIso", GeomAbs_IsoType::GeomAbs_NoneIso)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomAbs_SurfaceType.hxx
	py::enum_<GeomAbs_SurfaceType>(mod, "GeomAbs_SurfaceType", "None")
		.value("GeomAbs_Plane", GeomAbs_SurfaceType::GeomAbs_Plane)
		.value("GeomAbs_Cylinder", GeomAbs_SurfaceType::GeomAbs_Cylinder)
		.value("GeomAbs_Cone", GeomAbs_SurfaceType::GeomAbs_Cone)
		.value("GeomAbs_Sphere", GeomAbs_SurfaceType::GeomAbs_Sphere)
		.value("GeomAbs_Torus", GeomAbs_SurfaceType::GeomAbs_Torus)
		.value("GeomAbs_BezierSurface", GeomAbs_SurfaceType::GeomAbs_BezierSurface)
		.value("GeomAbs_BSplineSurface", GeomAbs_SurfaceType::GeomAbs_BSplineSurface)
		.value("GeomAbs_SurfaceOfRevolution", GeomAbs_SurfaceType::GeomAbs_SurfaceOfRevolution)
		.value("GeomAbs_SurfaceOfExtrusion", GeomAbs_SurfaceType::GeomAbs_SurfaceOfExtrusion)
		.value("GeomAbs_OffsetSurface", GeomAbs_SurfaceType::GeomAbs_OffsetSurface)
		.value("GeomAbs_OtherSurface", GeomAbs_SurfaceType::GeomAbs_OtherSurface)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomAbs_JoinType.hxx
	py::enum_<GeomAbs_JoinType>(mod, "GeomAbs_JoinType", "Characterizes the type of a join, built by an algorithm for constructing parallel curves, between two consecutive arcs of a contour parallel to a given contour.")
		.value("GeomAbs_Arc", GeomAbs_JoinType::GeomAbs_Arc)
		.value("GeomAbs_Tangent", GeomAbs_JoinType::GeomAbs_Tangent)
		.value("GeomAbs_Intersection", GeomAbs_JoinType::GeomAbs_Intersection)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomAbs_CurveForm.hxx
	py::enum_<GeomAbs_CurveForm>(mod, "GeomAbs_CurveForm", "This enumeration is used to note specific curve form.")
		.value("GeomAbs_PolylineForm", GeomAbs_CurveForm::GeomAbs_PolylineForm)
		.value("GeomAbs_CircularForm", GeomAbs_CurveForm::GeomAbs_CircularForm)
		.value("GeomAbs_EllipticForm", GeomAbs_CurveForm::GeomAbs_EllipticForm)
		.value("GeomAbs_HyperbolicForm", GeomAbs_CurveForm::GeomAbs_HyperbolicForm)
		.value("GeomAbs_ParabolicForm", GeomAbs_CurveForm::GeomAbs_ParabolicForm)
		.value("GeomAbs_OtherCurveForm", GeomAbs_CurveForm::GeomAbs_OtherCurveForm)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomAbs_SurfaceForm.hxx
	py::enum_<GeomAbs_SurfaceForm>(mod, "GeomAbs_SurfaceForm", "This enumeration is used to note specific surface form.")
		.value("GeomAbs_PlanarForm", GeomAbs_SurfaceForm::GeomAbs_PlanarForm)
		.value("GeomAbs_ConicalForm", GeomAbs_SurfaceForm::GeomAbs_ConicalForm)
		.value("GeomAbs_CylindricalForm", GeomAbs_SurfaceForm::GeomAbs_CylindricalForm)
		.value("GeomAbs_ToroidalForm", GeomAbs_SurfaceForm::GeomAbs_ToroidalForm)
		.value("GeomAbs_SphericalForm", GeomAbs_SurfaceForm::GeomAbs_SphericalForm)
		.value("GeomAbs_RevolutionForm", GeomAbs_SurfaceForm::GeomAbs_RevolutionForm)
		.value("GeomAbs_RuledForm", GeomAbs_SurfaceForm::GeomAbs_RuledForm)
		.value("GeomAbs_QuadricForm", GeomAbs_SurfaceForm::GeomAbs_QuadricForm)
		.value("GeomAbs_OtherSurfaceForm", GeomAbs_SurfaceForm::GeomAbs_OtherSurfaceForm)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomAbs_UVSense.hxx
	py::enum_<GeomAbs_UVSense>(mod, "GeomAbs_UVSense", "This enumeration is used in the class RectangularTrimmedSurface to compare the orientation of the basic surface and the orientation of the trimmed surface and in the class ElementarySurface to know the direction of parametrization by comparison with the default construction mode.")
		.value("GeomAbs_SameUV", GeomAbs_UVSense::GeomAbs_SameUV)
		.value("GeomAbs_SameU", GeomAbs_UVSense::GeomAbs_SameU)
		.value("GeomAbs_SameV", GeomAbs_UVSense::GeomAbs_SameV)
		.value("GeomAbs_OppositeUV", GeomAbs_UVSense::GeomAbs_OppositeUV)
		.export_values();

	// FUNCTIONS

	// CLASSES

}
