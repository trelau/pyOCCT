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

#include <gp_Lin.hxx>
#include <IntAna_Quadric.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Parab.hxx>
#include <gp_Hypr.hxx>
#include <gp_Pln.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <IntAna_IntConicQuad.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Cone.hxx>
#include <gp_Vec.hxx>
#include <IntAna_Curve.hxx>
#include <IntAna_Int3Pln.hxx>
#include <gp_Sphere.hxx>
#include <gp_Ax3.hxx>
#include <gp_Torus.hxx>
#include <IntAna_IntLinTorus.hxx>
#include <IntAna_IntQuadQuad.hxx>
#include <NCollection_BaseList.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_List.hxx>
#include <IntAna_ListOfCurve.hxx>
#include <IntAna_ResultType.hxx>
#include <IntAna_QuadQuadGeo.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(IntAna, mod) {

	// IMPORT
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntAna_ResultType.hxx
	py::enum_<IntAna_ResultType>(mod, "IntAna_ResultType", "None")
		.value("IntAna_Point", IntAna_ResultType::IntAna_Point)
		.value("IntAna_Line", IntAna_ResultType::IntAna_Line)
		.value("IntAna_Circle", IntAna_ResultType::IntAna_Circle)
		.value("IntAna_PointAndCircle", IntAna_ResultType::IntAna_PointAndCircle)
		.value("IntAna_Ellipse", IntAna_ResultType::IntAna_Ellipse)
		.value("IntAna_Parabola", IntAna_ResultType::IntAna_Parabola)
		.value("IntAna_Hyperbola", IntAna_ResultType::IntAna_Hyperbola)
		.value("IntAna_Empty", IntAna_ResultType::IntAna_Empty)
		.value("IntAna_Same", IntAna_ResultType::IntAna_Same)
		.value("IntAna_NoGeometricSolution", IntAna_ResultType::IntAna_NoGeometricSolution)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\IntAna_IntConicQuad.hxx
	py::class_<IntAna_IntConicQuad, std::unique_ptr<IntAna_IntConicQuad, Deleter<IntAna_IntConicQuad>>> cls_IntAna_IntConicQuad(mod, "IntAna_IntConicQuad", "This class provides the analytic intersection between a conic defined as an element of gp (Lin,Circ,Elips, Parab,Hypr) and a quadric as defined in the class Quadric from IntAna. The intersection between a conic and a plane is treated as a special case.");
	cls_IntAna_IntConicQuad.def(py::init<>());
	cls_IntAna_IntConicQuad.def(py::init<const gp_Lin &, const IntAna_Quadric &>(), py::arg("L"), py::arg("Q"));
	cls_IntAna_IntConicQuad.def(py::init<const gp_Circ &, const IntAna_Quadric &>(), py::arg("C"), py::arg("Q"));
	cls_IntAna_IntConicQuad.def(py::init<const gp_Elips &, const IntAna_Quadric &>(), py::arg("E"), py::arg("Q"));
	cls_IntAna_IntConicQuad.def(py::init<const gp_Parab &, const IntAna_Quadric &>(), py::arg("P"), py::arg("Q"));
	cls_IntAna_IntConicQuad.def(py::init<const gp_Hypr &, const IntAna_Quadric &>(), py::arg("H"), py::arg("Q"));
	cls_IntAna_IntConicQuad.def(py::init<const gp_Lin &, const gp_Pln &, const Standard_Real>(), py::arg("L"), py::arg("P"), py::arg("Tolang"));
	cls_IntAna_IntConicQuad.def(py::init<const gp_Lin &, const gp_Pln &, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("P"), py::arg("Tolang"), py::arg("Tol"));
	cls_IntAna_IntConicQuad.def(py::init<const gp_Lin &, const gp_Pln &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("L"), py::arg("P"), py::arg("Tolang"), py::arg("Tol"), py::arg("Len"));
	cls_IntAna_IntConicQuad.def(py::init<const gp_Circ &, const gp_Pln &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("P"), py::arg("Tolang"), py::arg("Tol"));
	cls_IntAna_IntConicQuad.def(py::init<const gp_Elips &, const gp_Pln &, const Standard_Real, const Standard_Real>(), py::arg("E"), py::arg("P"), py::arg("Tolang"), py::arg("Tol"));
	cls_IntAna_IntConicQuad.def(py::init<const gp_Parab &, const gp_Pln &, const Standard_Real>(), py::arg("Pb"), py::arg("P"), py::arg("Tolang"));
	cls_IntAna_IntConicQuad.def(py::init<const gp_Hypr &, const gp_Pln &, const Standard_Real>(), py::arg("H"), py::arg("P"), py::arg("Tolang"));
	cls_IntAna_IntConicQuad.def("Perform", (void (IntAna_IntConicQuad::*)(const gp_Lin &, const IntAna_Quadric &)) &IntAna_IntConicQuad::Perform, "Intersects a line and a quadric.", py::arg("L"), py::arg("Q"));
	cls_IntAna_IntConicQuad.def("Perform", (void (IntAna_IntConicQuad::*)(const gp_Circ &, const IntAna_Quadric &)) &IntAna_IntConicQuad::Perform, "Intersects a circle and a quadric.", py::arg("C"), py::arg("Q"));
	cls_IntAna_IntConicQuad.def("Perform", (void (IntAna_IntConicQuad::*)(const gp_Elips &, const IntAna_Quadric &)) &IntAna_IntConicQuad::Perform, "Intersects an ellipse and a quadric.", py::arg("E"), py::arg("Q"));
	cls_IntAna_IntConicQuad.def("Perform", (void (IntAna_IntConicQuad::*)(const gp_Parab &, const IntAna_Quadric &)) &IntAna_IntConicQuad::Perform, "Intersects a parabola and a quadric.", py::arg("P"), py::arg("Q"));
	cls_IntAna_IntConicQuad.def("Perform", (void (IntAna_IntConicQuad::*)(const gp_Hypr &, const IntAna_Quadric &)) &IntAna_IntConicQuad::Perform, "Intersects an hyperbola and a quadric.", py::arg("H"), py::arg("Q"));
	cls_IntAna_IntConicQuad.def("Perform", [](IntAna_IntConicQuad &self, const gp_Lin & a0, const gp_Pln & a1, const Standard_Real a2) -> void { return self.Perform(a0, a1, a2); }, py::arg("L"), py::arg("P"), py::arg("Tolang"));
	cls_IntAna_IntConicQuad.def("Perform", [](IntAna_IntConicQuad &self, const gp_Lin & a0, const gp_Pln & a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Perform(a0, a1, a2, a3); }, py::arg("L"), py::arg("P"), py::arg("Tolang"), py::arg("Tol"));
	cls_IntAna_IntConicQuad.def("Perform", (void (IntAna_IntConicQuad::*)(const gp_Lin &, const gp_Pln &, const Standard_Real, const Standard_Real, const Standard_Real)) &IntAna_IntConicQuad::Perform, "Intersects a line and a plane. Tolang is used to determine if the angle between two vectors is null. Tol is used to check the distance between line and plane on the distance <Len> from the origin of the line.", py::arg("L"), py::arg("P"), py::arg("Tolang"), py::arg("Tol"), py::arg("Len"));
	cls_IntAna_IntConicQuad.def("Perform", (void (IntAna_IntConicQuad::*)(const gp_Circ &, const gp_Pln &, const Standard_Real, const Standard_Real)) &IntAna_IntConicQuad::Perform, "Intersects a circle and a plane. Tolang is used to determine if the angle between two vectors is null. Tol is used to determine if a distance is null.", py::arg("C"), py::arg("P"), py::arg("Tolang"), py::arg("Tol"));
	cls_IntAna_IntConicQuad.def("Perform", (void (IntAna_IntConicQuad::*)(const gp_Elips &, const gp_Pln &, const Standard_Real, const Standard_Real)) &IntAna_IntConicQuad::Perform, "Intersects an ellipse and a plane. Tolang is used to determine if the angle between two vectors is null. Tol is used to determine if a distance is null.", py::arg("E"), py::arg("P"), py::arg("Tolang"), py::arg("Tol"));
	cls_IntAna_IntConicQuad.def("Perform", (void (IntAna_IntConicQuad::*)(const gp_Parab &, const gp_Pln &, const Standard_Real)) &IntAna_IntConicQuad::Perform, "Intersects a parabola and a plane. Tolang is used to determine if the angle between two vectors is null.", py::arg("Pb"), py::arg("P"), py::arg("Tolang"));
	cls_IntAna_IntConicQuad.def("Perform", (void (IntAna_IntConicQuad::*)(const gp_Hypr &, const gp_Pln &, const Standard_Real)) &IntAna_IntConicQuad::Perform, "Intersects an hyperbola and a plane. Tolang is used to determine if the angle between two vectors is null.", py::arg("H"), py::arg("P"), py::arg("Tolang"));
	cls_IntAna_IntConicQuad.def("IsDone", (Standard_Boolean (IntAna_IntConicQuad::*)() const ) &IntAna_IntConicQuad::IsDone, "Returns TRUE if the creation completed.");
	cls_IntAna_IntConicQuad.def("IsInQuadric", (Standard_Boolean (IntAna_IntConicQuad::*)() const ) &IntAna_IntConicQuad::IsInQuadric, "Returns TRUE if the conic is in the quadric.");
	cls_IntAna_IntConicQuad.def("IsParallel", (Standard_Boolean (IntAna_IntConicQuad::*)() const ) &IntAna_IntConicQuad::IsParallel, "Returns TRUE if the line is in a quadric which is parallel to the quadric.");
	cls_IntAna_IntConicQuad.def("NbPoints", (Standard_Integer (IntAna_IntConicQuad::*)() const ) &IntAna_IntConicQuad::NbPoints, "Returns the number of intersection point.");
	cls_IntAna_IntConicQuad.def("Point", (const gp_Pnt & (IntAna_IntConicQuad::*)(const Standard_Integer) const ) &IntAna_IntConicQuad::Point, "Returns the point of range N.", py::arg("N"));
	cls_IntAna_IntConicQuad.def("ParamOnConic", (Standard_Real (IntAna_IntConicQuad::*)(const Standard_Integer) const ) &IntAna_IntConicQuad::ParamOnConic, "Returns the parameter on the line of the intersection point of range N.", py::arg("N"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntAna_Curve.hxx
	py::class_<IntAna_Curve, std::unique_ptr<IntAna_Curve, Deleter<IntAna_Curve>>> cls_IntAna_Curve(mod, "IntAna_Curve", "Definition of a parametric Curve which is the result of the intersection between two quadrics.");
	cls_IntAna_Curve.def(py::init<>());
	cls_IntAna_Curve.def("SetCylinderQuadValues", (void (IntAna_Curve::*)(const gp_Cylinder &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &IntAna_Curve::SetCylinderQuadValues, "Sets the parameters used to compute Points and Derivative on the curve.", py::arg("Cylinder"), py::arg("Qxx"), py::arg("Qyy"), py::arg("Qzz"), py::arg("Qxy"), py::arg("Qxz"), py::arg("Qyz"), py::arg("Qx"), py::arg("Qy"), py::arg("Qz"), py::arg("Q1"), py::arg("Tol"), py::arg("DomInf"), py::arg("DomSup"), py::arg("TwoZForATheta"), py::arg("ZIsPositive"));
	cls_IntAna_Curve.def("SetConeQuadValues", (void (IntAna_Curve::*)(const gp_Cone &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &IntAna_Curve::SetConeQuadValues, "Sets the parameters used to compute Points and Derivative on the curve.", py::arg("Cone"), py::arg("Qxx"), py::arg("Qyy"), py::arg("Qzz"), py::arg("Qxy"), py::arg("Qxz"), py::arg("Qyz"), py::arg("Qx"), py::arg("Qy"), py::arg("Qz"), py::arg("Q1"), py::arg("Tol"), py::arg("DomInf"), py::arg("DomSup"), py::arg("TwoZForATheta"), py::arg("ZIsPositive"));
	cls_IntAna_Curve.def("IsOpen", (Standard_Boolean (IntAna_Curve::*)() const ) &IntAna_Curve::IsOpen, "Returns TRUE if the curve is not infinite at the last parameter or at the first parameter of the domain.");
	cls_IntAna_Curve.def("Domain", [](IntAna_Curve &self, Standard_Real & Theta1, Standard_Real & Theta2){ self.Domain(Theta1, Theta2); return std::tuple<Standard_Real &, Standard_Real &>(Theta1, Theta2); }, "Returns the paramatric domain of the curve.", py::arg("Theta1"), py::arg("Theta2"));
	cls_IntAna_Curve.def("IsConstant", (Standard_Boolean (IntAna_Curve::*)() const ) &IntAna_Curve::IsConstant, "Returns TRUE if the function is constant.");
	cls_IntAna_Curve.def("IsFirstOpen", (Standard_Boolean (IntAna_Curve::*)() const ) &IntAna_Curve::IsFirstOpen, "Returns TRUE if the domain is open at the beginning.");
	cls_IntAna_Curve.def("IsLastOpen", (Standard_Boolean (IntAna_Curve::*)() const ) &IntAna_Curve::IsLastOpen, "Returns TRUE if the domain is open at the end.");
	cls_IntAna_Curve.def("Value", (gp_Pnt (IntAna_Curve::*)(const Standard_Real)) &IntAna_Curve::Value, "Returns the point at parameter Theta on the curve.", py::arg("Theta"));
	cls_IntAna_Curve.def("D1u", (Standard_Boolean (IntAna_Curve::*)(const Standard_Real, gp_Pnt &, gp_Vec &)) &IntAna_Curve::D1u, "Returns the point and the first derivative at parameter Theta on the curve.", py::arg("Theta"), py::arg("P"), py::arg("V"));
	cls_IntAna_Curve.def("FindParameter", [](IntAna_Curve &self, const gp_Pnt & P, Standard_Real & Para){ Standard_Boolean rv = self.FindParameter(P, Para); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Para); }, "Tries to find the parameter of the point P on the curve. If the method returns False, the 'projection' is impossible, and the value of Para is not significant. If the method returns True, Para is the parameter of the nearest intersection between the curve and the iso-theta containing P.", py::arg("P"), py::arg("Para"));
	cls_IntAna_Curve.def("SetIsFirstOpen", (void (IntAna_Curve::*)(const Standard_Boolean)) &IntAna_Curve::SetIsFirstOpen, "If flag is True, the Curve is not defined at the first parameter of its domain.", py::arg("Flag"));
	cls_IntAna_Curve.def("SetIsLastOpen", (void (IntAna_Curve::*)(const Standard_Boolean)) &IntAna_Curve::SetIsLastOpen, "If flag is True, the Curve is not defined at the first parameter of its domain.", py::arg("Flag"));
	cls_IntAna_Curve.def("InternalUVValue", [](IntAna_Curve &self, const Standard_Real Param, Standard_Real & U, Standard_Real & V, Standard_Real & A, Standard_Real & B, Standard_Real & C, Standard_Real & Co, Standard_Real & Si, Standard_Real & Di){ self.InternalUVValue(Param, U, V, A, B, C, Co, Si, Di); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U, V, A, B, C, Co, Si, Di); }, "Protected function.", py::arg("Param"), py::arg("U"), py::arg("V"), py::arg("A"), py::arg("B"), py::arg("C"), py::arg("Co"), py::arg("Si"), py::arg("Di"));
	cls_IntAna_Curve.def("SetDomain", (void (IntAna_Curve::*)(const Standard_Real, const Standard_Real)) &IntAna_Curve::SetDomain, "None", py::arg("Theta1"), py::arg("Theta2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntAna_Int3Pln.hxx
	py::class_<IntAna_Int3Pln, std::unique_ptr<IntAna_Int3Pln, Deleter<IntAna_Int3Pln>>> cls_IntAna_Int3Pln(mod, "IntAna_Int3Pln", "Intersection between 3 planes. The algorithm searches for an intersection point. If two of the planes are parallel or identical, IsEmpty returns TRUE.");
	cls_IntAna_Int3Pln.def(py::init<>());
	cls_IntAna_Int3Pln.def(py::init<const gp_Pln &, const gp_Pln &, const gp_Pln &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"));
	cls_IntAna_Int3Pln.def("Perform", (void (IntAna_Int3Pln::*)(const gp_Pln &, const gp_Pln &, const gp_Pln &)) &IntAna_Int3Pln::Perform, "Determination of the intersection point between 3 planes.", py::arg("P1"), py::arg("P2"), py::arg("P3"));
	cls_IntAna_Int3Pln.def("IsDone", (Standard_Boolean (IntAna_Int3Pln::*)() const ) &IntAna_Int3Pln::IsDone, "Returns True if the computation was successful.");
	cls_IntAna_Int3Pln.def("IsEmpty", (Standard_Boolean (IntAna_Int3Pln::*)() const ) &IntAna_Int3Pln::IsEmpty, "Returns TRUE if there is no intersection POINT. If 2 planes are identical or parallel, IsEmpty will return TRUE.");
	cls_IntAna_Int3Pln.def("Value", (const gp_Pnt & (IntAna_Int3Pln::*)() const ) &IntAna_Int3Pln::Value, "Returns the intersection point.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntAna_Quadric.hxx
	py::class_<IntAna_Quadric, std::unique_ptr<IntAna_Quadric, Deleter<IntAna_Quadric>>> cls_IntAna_Quadric(mod, "IntAna_Quadric", "This class provides a description of Quadrics by their Coefficients in natural coordinate system.");
	cls_IntAna_Quadric.def(py::init<>());
	cls_IntAna_Quadric.def(py::init<const gp_Pln &>(), py::arg("P"));
	cls_IntAna_Quadric.def(py::init<const gp_Sphere &>(), py::arg("Sph"));
	cls_IntAna_Quadric.def(py::init<const gp_Cylinder &>(), py::arg("Cyl"));
	cls_IntAna_Quadric.def(py::init<const gp_Cone &>(), py::arg("Cone"));
	cls_IntAna_Quadric.def("SetQuadric", (void (IntAna_Quadric::*)(const gp_Pln &)) &IntAna_Quadric::SetQuadric, "Initializes the quadric with a Pln", py::arg("P"));
	cls_IntAna_Quadric.def("SetQuadric", (void (IntAna_Quadric::*)(const gp_Sphere &)) &IntAna_Quadric::SetQuadric, "Initialize the quadric with a Sphere", py::arg("Sph"));
	cls_IntAna_Quadric.def("SetQuadric", (void (IntAna_Quadric::*)(const gp_Cone &)) &IntAna_Quadric::SetQuadric, "Initializes the quadric with a Cone", py::arg("Con"));
	cls_IntAna_Quadric.def("SetQuadric", (void (IntAna_Quadric::*)(const gp_Cylinder &)) &IntAna_Quadric::SetQuadric, "Initializes the quadric with a Cylinder", py::arg("Cyl"));
	cls_IntAna_Quadric.def("Coefficients", [](IntAna_Quadric &self, Standard_Real & xCXX, Standard_Real & xCYY, Standard_Real & xCZZ, Standard_Real & xCXY, Standard_Real & xCXZ, Standard_Real & xCYZ, Standard_Real & xCX, Standard_Real & xCY, Standard_Real & xCZ, Standard_Real & xCCte){ self.Coefficients(xCXX, xCYY, xCZZ, xCXY, xCXZ, xCYZ, xCX, xCY, xCZ, xCCte); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(xCXX, xCYY, xCZZ, xCXY, xCXZ, xCYZ, xCX, xCY, xCZ, xCCte); }, "Returns the coefficients of the polynomial equation which define the quadric: xCXX x**2 + xCYY y**2 + xCZZ z**2 + 2 ( xCXY x y + xCXZ x z + xCYZ y z ) + 2 ( xCX x + xCY y + xCZ z ) + xCCte", py::arg("xCXX"), py::arg("xCYY"), py::arg("xCZZ"), py::arg("xCXY"), py::arg("xCXZ"), py::arg("xCYZ"), py::arg("xCX"), py::arg("xCY"), py::arg("xCZ"), py::arg("xCCte"));
	cls_IntAna_Quadric.def("NewCoefficients", [](IntAna_Quadric &self, Standard_Real & xCXX, Standard_Real & xCYY, Standard_Real & xCZZ, Standard_Real & xCXY, Standard_Real & xCXZ, Standard_Real & xCYZ, Standard_Real & xCX, Standard_Real & xCY, Standard_Real & xCZ, Standard_Real & xCCte, const gp_Ax3 & Axis){ self.NewCoefficients(xCXX, xCYY, xCZZ, xCXY, xCXZ, xCYZ, xCX, xCY, xCZ, xCCte, Axis); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(xCXX, xCYY, xCZZ, xCXY, xCXZ, xCYZ, xCX, xCY, xCZ, xCCte); }, "Returns the coefficients of the polynomial equation ( written in the natural coordinates system ) in the local coordinates system defined by Axis", py::arg("xCXX"), py::arg("xCYY"), py::arg("xCZZ"), py::arg("xCXY"), py::arg("xCXZ"), py::arg("xCYZ"), py::arg("xCX"), py::arg("xCY"), py::arg("xCZ"), py::arg("xCCte"), py::arg("Axis"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntAna_IntLinTorus.hxx
	py::class_<IntAna_IntLinTorus, std::unique_ptr<IntAna_IntLinTorus, Deleter<IntAna_IntLinTorus>>> cls_IntAna_IntLinTorus(mod, "IntAna_IntLinTorus", "Intersection between a line and a torus.");
	cls_IntAna_IntLinTorus.def(py::init<>());
	cls_IntAna_IntLinTorus.def(py::init<const gp_Lin &, const gp_Torus &>(), py::arg("L"), py::arg("T"));
	cls_IntAna_IntLinTorus.def("Perform", (void (IntAna_IntLinTorus::*)(const gp_Lin &, const gp_Torus &)) &IntAna_IntLinTorus::Perform, "Intersects a line and a torus.", py::arg("L"), py::arg("T"));
	cls_IntAna_IntLinTorus.def("IsDone", (Standard_Boolean (IntAna_IntLinTorus::*)() const ) &IntAna_IntLinTorus::IsDone, "Returns True if the computation was successful.");
	cls_IntAna_IntLinTorus.def("NbPoints", (Standard_Integer (IntAna_IntLinTorus::*)() const ) &IntAna_IntLinTorus::NbPoints, "Returns the number of intersection points.");
	cls_IntAna_IntLinTorus.def("Value", (const gp_Pnt & (IntAna_IntLinTorus::*)(const Standard_Integer) const ) &IntAna_IntLinTorus::Value, "Returns the intersection point of range Index.", py::arg("Index"));
	cls_IntAna_IntLinTorus.def("ParamOnLine", (Standard_Real (IntAna_IntLinTorus::*)(const Standard_Integer) const ) &IntAna_IntLinTorus::ParamOnLine, "Returns the parameter on the line of the intersection point of range Index.", py::arg("Index"));
	cls_IntAna_IntLinTorus.def("ParamOnTorus", [](IntAna_IntLinTorus &self, const Standard_Integer Index, Standard_Real & FI, Standard_Real & THETA){ self.ParamOnTorus(Index, FI, THETA); return std::tuple<Standard_Real &, Standard_Real &>(FI, THETA); }, "Returns the parameters on the torus of the intersection point of range Index.", py::arg("Index"), py::arg("FI"), py::arg("THETA"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntAna_IntQuadQuad.hxx
	py::class_<IntAna_IntQuadQuad, std::unique_ptr<IntAna_IntQuadQuad, Deleter<IntAna_IntQuadQuad>>> cls_IntAna_IntQuadQuad(mod, "IntAna_IntQuadQuad", "This class provides the analytic intersection between a cylinder or a cone from gp and another quadric, as defined in the class Quadric from IntAna. This algorithm is used when the geometric intersection (class QuadQuadGeo from IntAna) returns no geometric solution. The result of the intersection may be - Curves as defined in the class Curve from IntAna - Points (Pnt from gp)");
	cls_IntAna_IntQuadQuad.def(py::init<>());
	cls_IntAna_IntQuadQuad.def(py::init<const gp_Cylinder &, const IntAna_Quadric &, const Standard_Real>(), py::arg("C"), py::arg("Q"), py::arg("Tol"));
	cls_IntAna_IntQuadQuad.def(py::init<const gp_Cone &, const IntAna_Quadric &, const Standard_Real>(), py::arg("C"), py::arg("Q"), py::arg("Tol"));
	cls_IntAna_IntQuadQuad.def("Perform", (void (IntAna_IntQuadQuad::*)(const gp_Cylinder &, const IntAna_Quadric &, const Standard_Real)) &IntAna_IntQuadQuad::Perform, "Intersects a cylinder and a quadric . Tol est a definir plus precisemment.", py::arg("C"), py::arg("Q"), py::arg("Tol"));
	cls_IntAna_IntQuadQuad.def("Perform", (void (IntAna_IntQuadQuad::*)(const gp_Cone &, const IntAna_Quadric &, const Standard_Real)) &IntAna_IntQuadQuad::Perform, "Intersects a cone and a quadric. Tol est a definir plus precisemment.", py::arg("C"), py::arg("Q"), py::arg("Tol"));
	cls_IntAna_IntQuadQuad.def("IsDone", (Standard_Boolean (IntAna_IntQuadQuad::*)() const ) &IntAna_IntQuadQuad::IsDone, "Returns True if the computation was successful.");
	cls_IntAna_IntQuadQuad.def("IdenticalElements", (Standard_Boolean (IntAna_IntQuadQuad::*)() const ) &IntAna_IntQuadQuad::IdenticalElements, "Returns TRUE if the cylinder, the cone or the sphere is identical to the quadric.");
	cls_IntAna_IntQuadQuad.def("NbCurve", (Standard_Integer (IntAna_IntQuadQuad::*)() const ) &IntAna_IntQuadQuad::NbCurve, "Returns the number of curves solution.");
	cls_IntAna_IntQuadQuad.def("Curve", (const IntAna_Curve & (IntAna_IntQuadQuad::*)(const Standard_Integer) const ) &IntAna_IntQuadQuad::Curve, "Returns the curve of range N.", py::arg("N"));
	cls_IntAna_IntQuadQuad.def("NbPnt", (Standard_Integer (IntAna_IntQuadQuad::*)() const ) &IntAna_IntQuadQuad::NbPnt, "Returns the number of contact point.");
	cls_IntAna_IntQuadQuad.def("Point", (const gp_Pnt & (IntAna_IntQuadQuad::*)(const Standard_Integer) const ) &IntAna_IntQuadQuad::Point, "Returns the point of range N.", py::arg("N"));
	cls_IntAna_IntQuadQuad.def("Parameters", [](IntAna_IntQuadQuad &self, const Standard_Integer N, Standard_Real & U1, Standard_Real & U2){ self.Parameters(N, U1, U2); return std::tuple<Standard_Real &, Standard_Real &>(U1, U2); }, "Returns the parameters on the 'explicit quadric' (i.e the cylinder or the cone, the first argument given to the constructor) of the point of range N.", py::arg("N"), py::arg("U1"), py::arg("U2"));
	cls_IntAna_IntQuadQuad.def("HasNextCurve", (Standard_Boolean (IntAna_IntQuadQuad::*)(const Standard_Integer) const ) &IntAna_IntQuadQuad::HasNextCurve, "Returns True if the Curve I shares its last bound with another curve.", py::arg("I"));
	cls_IntAna_IntQuadQuad.def("NextCurve", [](IntAna_IntQuadQuad &self, const Standard_Integer I, Standard_Boolean & theOpposite){ Standard_Integer rv = self.NextCurve(I, theOpposite); return std::tuple<Standard_Integer, Standard_Boolean &>(rv, theOpposite); }, "If HasNextCurve(I) returns True, this function returns the Index J of the curve which has a common bound with the curve I. If theOpposite == True , then the last parameter of the curve I, and the last parameter of the curve J give the same point. Else the last parameter of the curve I and the first parameter of the curve J are the same point.", py::arg("I"), py::arg("theOpposite"));
	cls_IntAna_IntQuadQuad.def("HasPreviousCurve", (Standard_Boolean (IntAna_IntQuadQuad::*)(const Standard_Integer) const ) &IntAna_IntQuadQuad::HasPreviousCurve, "Returns True if the Curve I shares its first bound with another curve.", py::arg("I"));
	cls_IntAna_IntQuadQuad.def("PreviousCurve", [](IntAna_IntQuadQuad &self, const Standard_Integer I, Standard_Boolean & theOpposite){ Standard_Integer rv = self.PreviousCurve(I, theOpposite); return std::tuple<Standard_Integer, Standard_Boolean &>(rv, theOpposite); }, "if HasPreviousCurve(I) returns True, this function returns the Index J of the curve which has a common bound with the curve I. If theOpposite == True , then the first parameter of the curve I, and the first parameter of the curve J give the same point. Else the first parameter of the curve I and the last parameter of the curve J are the same point.", py::arg("I"), py::arg("theOpposite"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntAna_QuadQuadGeo.hxx
	py::class_<IntAna_QuadQuadGeo, std::unique_ptr<IntAna_QuadQuadGeo, Deleter<IntAna_QuadQuadGeo>>> cls_IntAna_QuadQuadGeo(mod, "IntAna_QuadQuadGeo", "Geometric intersections between two natural quadrics (Sphere , Cylinder , Cone , Pln from gp). The possible intersections are : - 1 point - 1 or 2 line(s) - 1 Point and 1 Line - 1 circle - 1 ellipse - 1 parabola - 1 or 2 hyperbola(s). - Empty : there is no intersection between the two quadrics. - Same : the quadrics are identical - NoGeometricSolution : there may be an intersection, but it is necessary to use an analytic algorithm to determine it. See class IntQuadQuad from IntAna.");
	cls_IntAna_QuadQuadGeo.def(py::init<>());
	cls_IntAna_QuadQuadGeo.def(py::init<const gp_Pln &, const gp_Pln &, const Standard_Real, const Standard_Real>(), py::arg("P1"), py::arg("P2"), py::arg("TolAng"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def(py::init<const gp_Pln &, const gp_Cylinder &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Tolang"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def(py::init<const gp_Pln &, const gp_Cylinder &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Tolang"), py::arg("Tol"), py::arg("H"));
	cls_IntAna_QuadQuadGeo.def(py::init<const gp_Pln &, const gp_Sphere &>(), py::arg("P"), py::arg("S"));
	cls_IntAna_QuadQuadGeo.def(py::init<const gp_Pln &, const gp_Cone &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("C"), py::arg("Tolang"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def(py::init<const gp_Cylinder &, const gp_Cylinder &, const Standard_Real>(), py::arg("Cyl1"), py::arg("Cyl2"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def(py::init<const gp_Cylinder &, const gp_Sphere &, const Standard_Real>(), py::arg("Cyl"), py::arg("Sph"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def(py::init<const gp_Cylinder &, const gp_Cone &, const Standard_Real>(), py::arg("Cyl"), py::arg("Con"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def(py::init<const gp_Sphere &, const gp_Sphere &, const Standard_Real>(), py::arg("Sph1"), py::arg("Sph2"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def(py::init<const gp_Sphere &, const gp_Cone &, const Standard_Real>(), py::arg("Sph"), py::arg("Con"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def(py::init<const gp_Cone &, const gp_Cone &, const Standard_Real>(), py::arg("Con1"), py::arg("Con2"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def(py::init<const gp_Pln &, const gp_Torus &, const Standard_Real>(), py::arg("Pln"), py::arg("Tor"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def(py::init<const gp_Cylinder &, const gp_Torus &, const Standard_Real>(), py::arg("Cyl"), py::arg("Tor"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def(py::init<const gp_Cone &, const gp_Torus &, const Standard_Real>(), py::arg("Con"), py::arg("Tor"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def(py::init<const gp_Sphere &, const gp_Torus &, const Standard_Real>(), py::arg("Sph"), py::arg("Tor"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def(py::init<const gp_Torus &, const gp_Torus &, const Standard_Real>(), py::arg("Tor1"), py::arg("Tor2"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def("Perform", (void (IntAna_QuadQuadGeo::*)(const gp_Pln &, const gp_Pln &, const Standard_Real, const Standard_Real)) &IntAna_QuadQuadGeo::Perform, "Intersects two planes. TolAng is the angular tolerance used to determine if the planes are parallel. Tol is the tolerance used to determine if the planes are identical (only when they are parallel).", py::arg("P1"), py::arg("P2"), py::arg("TolAng"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def("Perform", [](IntAna_QuadQuadGeo &self, const gp_Pln & a0, const gp_Cylinder & a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Perform(a0, a1, a2, a3); }, py::arg("P"), py::arg("C"), py::arg("Tolang"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def("Perform", (void (IntAna_QuadQuadGeo::*)(const gp_Pln &, const gp_Cylinder &, const Standard_Real, const Standard_Real, const Standard_Real)) &IntAna_QuadQuadGeo::Perform, "Intersects a plane and a cylinder. TolAng is the angular tolerance used to determine if the axis of the cylinder is parallel to the plane. Tol is the tolerance used to determine if the result is a circle or an ellipse. If the maximum distance between the ellipse solution and the circle centered at the ellipse center is less than Tol, the result will be the circle. H is the height of the cylinder <Cyl>. It is used to check whether the plane and cylinder are parallel.", py::arg("P"), py::arg("C"), py::arg("Tolang"), py::arg("Tol"), py::arg("H"));
	cls_IntAna_QuadQuadGeo.def("Perform", (void (IntAna_QuadQuadGeo::*)(const gp_Pln &, const gp_Sphere &)) &IntAna_QuadQuadGeo::Perform, "Intersects a plane and a sphere.", py::arg("P"), py::arg("S"));
	cls_IntAna_QuadQuadGeo.def("Perform", (void (IntAna_QuadQuadGeo::*)(const gp_Pln &, const gp_Cone &, const Standard_Real, const Standard_Real)) &IntAna_QuadQuadGeo::Perform, "Intersects a plane and a cone. TolAng is the angular tolerance used to determine if the axis of the cone is parallel or perpendicular to the plane, and if the generating line of the cone is parallel to the plane. Tol is the tolerance used to determine if the apex of the cone is in the plane.", py::arg("P"), py::arg("C"), py::arg("Tolang"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def("Perform", (void (IntAna_QuadQuadGeo::*)(const gp_Cylinder &, const gp_Cylinder &, const Standard_Real)) &IntAna_QuadQuadGeo::Perform, "Intersects two cylinders", py::arg("Cyl1"), py::arg("Cyl2"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def("Perform", (void (IntAna_QuadQuadGeo::*)(const gp_Cylinder &, const gp_Sphere &, const Standard_Real)) &IntAna_QuadQuadGeo::Perform, "Intersects a cylinder and a sphere.", py::arg("Cyl"), py::arg("Sph"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def("Perform", (void (IntAna_QuadQuadGeo::*)(const gp_Cylinder &, const gp_Cone &, const Standard_Real)) &IntAna_QuadQuadGeo::Perform, "Intersects a cylinder and a cone.", py::arg("Cyl"), py::arg("Con"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def("Perform", (void (IntAna_QuadQuadGeo::*)(const gp_Sphere &, const gp_Sphere &, const Standard_Real)) &IntAna_QuadQuadGeo::Perform, "Intersects a two spheres.", py::arg("Sph1"), py::arg("Sph2"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def("Perform", (void (IntAna_QuadQuadGeo::*)(const gp_Sphere &, const gp_Cone &, const Standard_Real)) &IntAna_QuadQuadGeo::Perform, "Intersects a sphere and a cone.", py::arg("Sph"), py::arg("Con"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def("Perform", (void (IntAna_QuadQuadGeo::*)(const gp_Cone &, const gp_Cone &, const Standard_Real)) &IntAna_QuadQuadGeo::Perform, "Intersects two cones.", py::arg("Con1"), py::arg("Con2"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def("Perform", (void (IntAna_QuadQuadGeo::*)(const gp_Pln &, const gp_Torus &, const Standard_Real)) &IntAna_QuadQuadGeo::Perform, "Intersects plane and torus.", py::arg("Pln"), py::arg("Tor"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def("Perform", (void (IntAna_QuadQuadGeo::*)(const gp_Cylinder &, const gp_Torus &, const Standard_Real)) &IntAna_QuadQuadGeo::Perform, "Intersects cylinder and torus.", py::arg("Cyl"), py::arg("Tor"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def("Perform", (void (IntAna_QuadQuadGeo::*)(const gp_Cone &, const gp_Torus &, const Standard_Real)) &IntAna_QuadQuadGeo::Perform, "Intersects cone and torus.", py::arg("Con"), py::arg("Tor"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def("Perform", (void (IntAna_QuadQuadGeo::*)(const gp_Sphere &, const gp_Torus &, const Standard_Real)) &IntAna_QuadQuadGeo::Perform, "Intersects sphere and torus.", py::arg("Sph"), py::arg("Tor"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def("Perform", (void (IntAna_QuadQuadGeo::*)(const gp_Torus &, const gp_Torus &, const Standard_Real)) &IntAna_QuadQuadGeo::Perform, "Intersects two toruses.", py::arg("Tor1"), py::arg("Tor2"), py::arg("Tol"));
	cls_IntAna_QuadQuadGeo.def("IsDone", (Standard_Boolean (IntAna_QuadQuadGeo::*)() const ) &IntAna_QuadQuadGeo::IsDone, "Returns Standard_True if the computation was successful.");
	cls_IntAna_QuadQuadGeo.def("TypeInter", (IntAna_ResultType (IntAna_QuadQuadGeo::*)() const ) &IntAna_QuadQuadGeo::TypeInter, "Returns the type of intersection.");
	cls_IntAna_QuadQuadGeo.def("NbSolutions", (Standard_Integer (IntAna_QuadQuadGeo::*)() const ) &IntAna_QuadQuadGeo::NbSolutions, "Returns the number of interesections. The possible intersections are : - 1 point - 1 or 2 line(s) - 1 Point and 1 Line - 1 circle - 1 ellipse - 1 parabola - 1 or 2 hyperbola(s).");
	cls_IntAna_QuadQuadGeo.def("Point", (gp_Pnt (IntAna_QuadQuadGeo::*)(const Standard_Integer) const ) &IntAna_QuadQuadGeo::Point, "Returns the point solution of range Num.", py::arg("Num"));
	cls_IntAna_QuadQuadGeo.def("Line", (gp_Lin (IntAna_QuadQuadGeo::*)(const Standard_Integer) const ) &IntAna_QuadQuadGeo::Line, "Returns the line solution of range Num.", py::arg("Num"));
	cls_IntAna_QuadQuadGeo.def("Circle", (gp_Circ (IntAna_QuadQuadGeo::*)(const Standard_Integer) const ) &IntAna_QuadQuadGeo::Circle, "Returns the circle solution of range Num.", py::arg("Num"));
	cls_IntAna_QuadQuadGeo.def("Ellipse", (gp_Elips (IntAna_QuadQuadGeo::*)(const Standard_Integer) const ) &IntAna_QuadQuadGeo::Ellipse, "Returns the ellipse solution of range Num.", py::arg("Num"));
	cls_IntAna_QuadQuadGeo.def("Parabola", (gp_Parab (IntAna_QuadQuadGeo::*)(const Standard_Integer) const ) &IntAna_QuadQuadGeo::Parabola, "Returns the parabola solution of range Num.", py::arg("Num"));
	cls_IntAna_QuadQuadGeo.def("Hyperbola", (gp_Hypr (IntAna_QuadQuadGeo::*)(const Standard_Integer) const ) &IntAna_QuadQuadGeo::Hyperbola, "Returns the hyperbola solution of range Num.", py::arg("Num"));
	cls_IntAna_QuadQuadGeo.def("HasCommonGen", (Standard_Boolean (IntAna_QuadQuadGeo::*)() const ) &IntAna_QuadQuadGeo::HasCommonGen, "None");
	cls_IntAna_QuadQuadGeo.def("PChar", (const gp_Pnt & (IntAna_QuadQuadGeo::*)() const ) &IntAna_QuadQuadGeo::PChar, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntAna_ListOfCurve.hxx
	bind_NCollection_List<IntAna_Curve>(mod, "IntAna_ListOfCurve");

	// C:\Miniconda\envs\occt\Library\include\opencascade\IntAna_ListOfCurve.hxx
	bind_NCollection_TListIterator<IntAna_Curve>(mod, "IntAna_ListIteratorOfListOfCurve");


}
