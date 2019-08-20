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

void bind_IntAna_IntConicQuad(py::module &mod){

py::class_<IntAna_IntConicQuad, std::unique_ptr<IntAna_IntConicQuad>> cls_IntAna_IntConicQuad(mod, "IntAna_IntConicQuad", "This class provides the analytic intersection between a conic defined as an element of gp (Lin,Circ,Elips, Parab,Hypr) and a quadric as defined in the class Quadric from IntAna. The intersection between a conic and a plane is treated as a special case.");

// Constructors
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

// Fields

// Methods
// cls_IntAna_IntConicQuad.def_static("operator new_", (void * (*)(size_t)) &IntAna_IntConicQuad::operator new, "None", py::arg("theSize"));
// cls_IntAna_IntConicQuad.def_static("operator delete_", (void (*)(void *)) &IntAna_IntConicQuad::operator delete, "None", py::arg("theAddress"));
// cls_IntAna_IntConicQuad.def_static("operator new[]_", (void * (*)(size_t)) &IntAna_IntConicQuad::operator new[], "None", py::arg("theSize"));
// cls_IntAna_IntConicQuad.def_static("operator delete[]_", (void (*)(void *)) &IntAna_IntConicQuad::operator delete[], "None", py::arg("theAddress"));
// cls_IntAna_IntConicQuad.def_static("operator new_", (void * (*)(size_t, void *)) &IntAna_IntConicQuad::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntAna_IntConicQuad.def_static("operator delete_", (void (*)(void *, void *)) &IntAna_IntConicQuad::operator delete, "None", py::arg(""), py::arg(""));
cls_IntAna_IntConicQuad.def("Perform", (void (IntAna_IntConicQuad::*)(const gp_Lin &, const IntAna_Quadric &)) &IntAna_IntConicQuad::Perform, "Intersects a line and a quadric.", py::arg("L"), py::arg("Q"));
cls_IntAna_IntConicQuad.def("Perform", (void (IntAna_IntConicQuad::*)(const gp_Circ &, const IntAna_Quadric &)) &IntAna_IntConicQuad::Perform, "Intersects a circle and a quadric.", py::arg("C"), py::arg("Q"));
cls_IntAna_IntConicQuad.def("Perform", (void (IntAna_IntConicQuad::*)(const gp_Elips &, const IntAna_Quadric &)) &IntAna_IntConicQuad::Perform, "Intersects an ellipse and a quadric.", py::arg("E"), py::arg("Q"));
cls_IntAna_IntConicQuad.def("Perform", (void (IntAna_IntConicQuad::*)(const gp_Parab &, const IntAna_Quadric &)) &IntAna_IntConicQuad::Perform, "Intersects a parabola and a quadric.", py::arg("P"), py::arg("Q"));
cls_IntAna_IntConicQuad.def("Perform", (void (IntAna_IntConicQuad::*)(const gp_Hypr &, const IntAna_Quadric &)) &IntAna_IntConicQuad::Perform, "Intersects an hyperbola and a quadric.", py::arg("H"), py::arg("Q"));
cls_IntAna_IntConicQuad.def("Perform", [](IntAna_IntConicQuad &self, const gp_Lin & a0, const gp_Pln & a1, const Standard_Real a2) -> void { return self.Perform(a0, a1, a2); });
cls_IntAna_IntConicQuad.def("Perform", [](IntAna_IntConicQuad &self, const gp_Lin & a0, const gp_Pln & a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Perform(a0, a1, a2, a3); });
cls_IntAna_IntConicQuad.def("Perform", (void (IntAna_IntConicQuad::*)(const gp_Lin &, const gp_Pln &, const Standard_Real, const Standard_Real, const Standard_Real)) &IntAna_IntConicQuad::Perform, "Intersects a line and a plane. Tolang is used to determine if the angle between two vectors is null. Tol is used to check the distance between line and plane on the distance <Len> from the origin of the line.", py::arg("L"), py::arg("P"), py::arg("Tolang"), py::arg("Tol"), py::arg("Len"));
cls_IntAna_IntConicQuad.def("Perform", (void (IntAna_IntConicQuad::*)(const gp_Circ &, const gp_Pln &, const Standard_Real, const Standard_Real)) &IntAna_IntConicQuad::Perform, "Intersects a circle and a plane. Tolang is used to determine if the angle between two vectors is null. Tol is used to determine if a distance is null.", py::arg("C"), py::arg("P"), py::arg("Tolang"), py::arg("Tol"));
cls_IntAna_IntConicQuad.def("Perform", (void (IntAna_IntConicQuad::*)(const gp_Elips &, const gp_Pln &, const Standard_Real, const Standard_Real)) &IntAna_IntConicQuad::Perform, "Intersects an ellipse and a plane. Tolang is used to determine if the angle between two vectors is null. Tol is used to determine if a distance is null.", py::arg("E"), py::arg("P"), py::arg("Tolang"), py::arg("Tol"));
cls_IntAna_IntConicQuad.def("Perform", (void (IntAna_IntConicQuad::*)(const gp_Parab &, const gp_Pln &, const Standard_Real)) &IntAna_IntConicQuad::Perform, "Intersects a parabola and a plane. Tolang is used to determine if the angle between two vectors is null.", py::arg("Pb"), py::arg("P"), py::arg("Tolang"));
cls_IntAna_IntConicQuad.def("Perform", (void (IntAna_IntConicQuad::*)(const gp_Hypr &, const gp_Pln &, const Standard_Real)) &IntAna_IntConicQuad::Perform, "Intersects an hyperbola and a plane. Tolang is used to determine if the angle between two vectors is null.", py::arg("H"), py::arg("P"), py::arg("Tolang"));
cls_IntAna_IntConicQuad.def("IsDone", (Standard_Boolean (IntAna_IntConicQuad::*)() const) &IntAna_IntConicQuad::IsDone, "Returns TRUE if the creation completed.");
cls_IntAna_IntConicQuad.def("IsInQuadric", (Standard_Boolean (IntAna_IntConicQuad::*)() const) &IntAna_IntConicQuad::IsInQuadric, "Returns TRUE if the conic is in the quadric.");
cls_IntAna_IntConicQuad.def("IsParallel", (Standard_Boolean (IntAna_IntConicQuad::*)() const) &IntAna_IntConicQuad::IsParallel, "Returns TRUE if the line is in a quadric which is parallel to the quadric.");
cls_IntAna_IntConicQuad.def("NbPoints", (Standard_Integer (IntAna_IntConicQuad::*)() const) &IntAna_IntConicQuad::NbPoints, "Returns the number of intersection point.");
cls_IntAna_IntConicQuad.def("Point", (const gp_Pnt & (IntAna_IntConicQuad::*)(const Standard_Integer) const) &IntAna_IntConicQuad::Point, "Returns the point of range N.", py::arg("N"));
cls_IntAna_IntConicQuad.def("ParamOnConic", (Standard_Real (IntAna_IntConicQuad::*)(const Standard_Integer) const) &IntAna_IntConicQuad::ParamOnConic, "Returns the parameter on the line of the intersection point of range N.", py::arg("N"));

// Enums

}