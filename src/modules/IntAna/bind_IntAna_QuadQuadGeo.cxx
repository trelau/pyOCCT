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
#include <gp_Pln.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Sphere.hxx>
#include <gp_Cone.hxx>
#include <gp_Torus.hxx>
#include <IntAna_ResultType.hxx>
#include <gp_Pnt.hxx>
#include <gp_Lin.hxx>
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Parab.hxx>
#include <gp_Hypr.hxx>
#include <gp_Dir.hxx>
#include <IntAna_QuadQuadGeo.hxx>

void bind_IntAna_QuadQuadGeo(py::module &mod){

py::class_<IntAna_QuadQuadGeo, std::unique_ptr<IntAna_QuadQuadGeo>> cls_IntAna_QuadQuadGeo(mod, "IntAna_QuadQuadGeo", "Geometric intersections between two natural quadrics (Sphere , Cylinder , Cone , Pln from gp). The possible intersections are : - 1 point - 1 or 2 line(s) - 1 Point and 1 Line - 1 circle - 1 ellipse - 1 parabola - 1 or 2 hyperbola(s). - Empty : there is no intersection between the two quadrics. - Same : the quadrics are identical - NoGeometricSolution : there may be an intersection, but it is necessary to use an analytic algorithm to determine it. See class IntQuadQuad from IntAna.");

// Constructors
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

// Fields

// Methods
// cls_IntAna_QuadQuadGeo.def_static("operator new_", (void * (*)(size_t)) &IntAna_QuadQuadGeo::operator new, "None", py::arg("theSize"));
// cls_IntAna_QuadQuadGeo.def_static("operator delete_", (void (*)(void *)) &IntAna_QuadQuadGeo::operator delete, "None", py::arg("theAddress"));
// cls_IntAna_QuadQuadGeo.def_static("operator new[]_", (void * (*)(size_t)) &IntAna_QuadQuadGeo::operator new[], "None", py::arg("theSize"));
// cls_IntAna_QuadQuadGeo.def_static("operator delete[]_", (void (*)(void *)) &IntAna_QuadQuadGeo::operator delete[], "None", py::arg("theAddress"));
// cls_IntAna_QuadQuadGeo.def_static("operator new_", (void * (*)(size_t, void *)) &IntAna_QuadQuadGeo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntAna_QuadQuadGeo.def_static("operator delete_", (void (*)(void *, void *)) &IntAna_QuadQuadGeo::operator delete, "None", py::arg(""), py::arg(""));
cls_IntAna_QuadQuadGeo.def("Perform", (void (IntAna_QuadQuadGeo::*)(const gp_Pln &, const gp_Pln &, const Standard_Real, const Standard_Real)) &IntAna_QuadQuadGeo::Perform, "Intersects two planes. TolAng is the angular tolerance used to determine if the planes are parallel. Tol is the tolerance used to determine if the planes are identical (only when they are parallel).", py::arg("P1"), py::arg("P2"), py::arg("TolAng"), py::arg("Tol"));
cls_IntAna_QuadQuadGeo.def("Perform", [](IntAna_QuadQuadGeo &self, const gp_Pln & a0, const gp_Cylinder & a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Perform(a0, a1, a2, a3); });
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
cls_IntAna_QuadQuadGeo.def("IsDone", (Standard_Boolean (IntAna_QuadQuadGeo::*)() const) &IntAna_QuadQuadGeo::IsDone, "Returns Standard_True if the computation was successful.");
cls_IntAna_QuadQuadGeo.def("TypeInter", (IntAna_ResultType (IntAna_QuadQuadGeo::*)() const) &IntAna_QuadQuadGeo::TypeInter, "Returns the type of intersection.");
cls_IntAna_QuadQuadGeo.def("NbSolutions", (Standard_Integer (IntAna_QuadQuadGeo::*)() const) &IntAna_QuadQuadGeo::NbSolutions, "Returns the number of interesections. The possible intersections are : - 1 point - 1 or 2 line(s) - 1 Point and 1 Line - 1 circle - 1 ellipse - 1 parabola - 1 or 2 hyperbola(s).");
cls_IntAna_QuadQuadGeo.def("Point", (gp_Pnt (IntAna_QuadQuadGeo::*)(const Standard_Integer) const) &IntAna_QuadQuadGeo::Point, "Returns the point solution of range Num.", py::arg("Num"));
cls_IntAna_QuadQuadGeo.def("Line", (gp_Lin (IntAna_QuadQuadGeo::*)(const Standard_Integer) const) &IntAna_QuadQuadGeo::Line, "Returns the line solution of range Num.", py::arg("Num"));
cls_IntAna_QuadQuadGeo.def("Circle", (gp_Circ (IntAna_QuadQuadGeo::*)(const Standard_Integer) const) &IntAna_QuadQuadGeo::Circle, "Returns the circle solution of range Num.", py::arg("Num"));
cls_IntAna_QuadQuadGeo.def("Ellipse", (gp_Elips (IntAna_QuadQuadGeo::*)(const Standard_Integer) const) &IntAna_QuadQuadGeo::Ellipse, "Returns the ellipse solution of range Num.", py::arg("Num"));
cls_IntAna_QuadQuadGeo.def("Parabola", (gp_Parab (IntAna_QuadQuadGeo::*)(const Standard_Integer) const) &IntAna_QuadQuadGeo::Parabola, "Returns the parabola solution of range Num.", py::arg("Num"));
cls_IntAna_QuadQuadGeo.def("Hyperbola", (gp_Hypr (IntAna_QuadQuadGeo::*)(const Standard_Integer) const) &IntAna_QuadQuadGeo::Hyperbola, "Returns the hyperbola solution of range Num.", py::arg("Num"));
cls_IntAna_QuadQuadGeo.def("HasCommonGen", (Standard_Boolean (IntAna_QuadQuadGeo::*)() const) &IntAna_QuadQuadGeo::HasCommonGen, "None");
cls_IntAna_QuadQuadGeo.def("PChar", (const gp_Pnt & (IntAna_QuadQuadGeo::*)() const) &IntAna_QuadQuadGeo::PChar, "None");

// Enums

}