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
#include <gp_Lin2d.hxx>
#include <gp_Circ2d.hxx>
#include <IntAna2d_Conic.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Parab2d.hxx>
#include <gp_Hypr2d.hxx>
#include <Standard_TypeDef.hxx>
#include <IntAna2d_IntPoint.hxx>
#include <IntAna2d_AnaIntersection.hxx>

void bind_IntAna2d_AnaIntersection(py::module &mod){

py::class_<IntAna2d_AnaIntersection, std::unique_ptr<IntAna2d_AnaIntersection>> cls_IntAna2d_AnaIntersection(mod, "IntAna2d_AnaIntersection", "Implementation of the analytical intersection between: - two Lin2d, - two Circ2d, - a Lin2d and a Circ2d, - an element of gp (Lin2d, Circ2d, Elips2d, Parab2d, Hypr2d) and another conic. No tolerance is given for all the intersections: the tolerance will be the 'precision machine'.");

// Constructors
cls_IntAna2d_AnaIntersection.def(py::init<>());
cls_IntAna2d_AnaIntersection.def(py::init<const gp_Lin2d &, const gp_Lin2d &>(), py::arg("L1"), py::arg("L2"));
cls_IntAna2d_AnaIntersection.def(py::init<const gp_Circ2d &, const gp_Circ2d &>(), py::arg("C1"), py::arg("C2"));
cls_IntAna2d_AnaIntersection.def(py::init<const gp_Lin2d &, const gp_Circ2d &>(), py::arg("L"), py::arg("C"));
cls_IntAna2d_AnaIntersection.def(py::init<const gp_Lin2d &, const IntAna2d_Conic &>(), py::arg("L"), py::arg("C"));
cls_IntAna2d_AnaIntersection.def(py::init<const gp_Circ2d &, const IntAna2d_Conic &>(), py::arg("C"), py::arg("Co"));
cls_IntAna2d_AnaIntersection.def(py::init<const gp_Elips2d &, const IntAna2d_Conic &>(), py::arg("E"), py::arg("C"));
cls_IntAna2d_AnaIntersection.def(py::init<const gp_Parab2d &, const IntAna2d_Conic &>(), py::arg("P"), py::arg("C"));
cls_IntAna2d_AnaIntersection.def(py::init<const gp_Hypr2d &, const IntAna2d_Conic &>(), py::arg("H"), py::arg("C"));

// Fields

// Methods
// cls_IntAna2d_AnaIntersection.def_static("operator new_", (void * (*)(size_t)) &IntAna2d_AnaIntersection::operator new, "None", py::arg("theSize"));
// cls_IntAna2d_AnaIntersection.def_static("operator delete_", (void (*)(void *)) &IntAna2d_AnaIntersection::operator delete, "None", py::arg("theAddress"));
// cls_IntAna2d_AnaIntersection.def_static("operator new[]_", (void * (*)(size_t)) &IntAna2d_AnaIntersection::operator new[], "None", py::arg("theSize"));
// cls_IntAna2d_AnaIntersection.def_static("operator delete[]_", (void (*)(void *)) &IntAna2d_AnaIntersection::operator delete[], "None", py::arg("theAddress"));
// cls_IntAna2d_AnaIntersection.def_static("operator new_", (void * (*)(size_t, void *)) &IntAna2d_AnaIntersection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntAna2d_AnaIntersection.def_static("operator delete_", (void (*)(void *, void *)) &IntAna2d_AnaIntersection::operator delete, "None", py::arg(""), py::arg(""));
cls_IntAna2d_AnaIntersection.def("Perform", (void (IntAna2d_AnaIntersection::*)(const gp_Lin2d &, const gp_Lin2d &)) &IntAna2d_AnaIntersection::Perform, "Intersection between two lines.", py::arg("L1"), py::arg("L2"));
cls_IntAna2d_AnaIntersection.def("Perform", (void (IntAna2d_AnaIntersection::*)(const gp_Circ2d &, const gp_Circ2d &)) &IntAna2d_AnaIntersection::Perform, "Intersection between two circles.", py::arg("C1"), py::arg("C2"));
cls_IntAna2d_AnaIntersection.def("Perform", (void (IntAna2d_AnaIntersection::*)(const gp_Lin2d &, const gp_Circ2d &)) &IntAna2d_AnaIntersection::Perform, "Intersection between a line and a circle.", py::arg("L"), py::arg("C"));
cls_IntAna2d_AnaIntersection.def("Perform", (void (IntAna2d_AnaIntersection::*)(const gp_Lin2d &, const IntAna2d_Conic &)) &IntAna2d_AnaIntersection::Perform, "Intersection between a line and a conic.", py::arg("L"), py::arg("C"));
cls_IntAna2d_AnaIntersection.def("Perform", (void (IntAna2d_AnaIntersection::*)(const gp_Circ2d &, const IntAna2d_Conic &)) &IntAna2d_AnaIntersection::Perform, "Intersection between a circle and another conic.", py::arg("C"), py::arg("Co"));
cls_IntAna2d_AnaIntersection.def("Perform", (void (IntAna2d_AnaIntersection::*)(const gp_Elips2d &, const IntAna2d_Conic &)) &IntAna2d_AnaIntersection::Perform, "Intersection between an ellipse and another conic.", py::arg("E"), py::arg("C"));
cls_IntAna2d_AnaIntersection.def("Perform", (void (IntAna2d_AnaIntersection::*)(const gp_Parab2d &, const IntAna2d_Conic &)) &IntAna2d_AnaIntersection::Perform, "Intersection between a parabola and another conic.", py::arg("P"), py::arg("C"));
cls_IntAna2d_AnaIntersection.def("Perform", (void (IntAna2d_AnaIntersection::*)(const gp_Hypr2d &, const IntAna2d_Conic &)) &IntAna2d_AnaIntersection::Perform, "Intersection between an hyperbola and another conic.", py::arg("H"), py::arg("C"));
cls_IntAna2d_AnaIntersection.def("IsDone", (Standard_Boolean (IntAna2d_AnaIntersection::*)() const) &IntAna2d_AnaIntersection::IsDone, "Returns TRUE if the computation was succesfull.");
cls_IntAna2d_AnaIntersection.def("IsEmpty", (Standard_Boolean (IntAna2d_AnaIntersection::*)() const) &IntAna2d_AnaIntersection::IsEmpty, "Returns TRUE when there is no intersection, i-e - no intersection point - the elements are not identical. The element may be parallel in this case.");
cls_IntAna2d_AnaIntersection.def("IdenticalElements", (Standard_Boolean (IntAna2d_AnaIntersection::*)() const) &IntAna2d_AnaIntersection::IdenticalElements, "For the intersection between an element of gp and a conic known by an implicit equation, the result will be TRUE if the element of gp verifies the implicit equation. For the intersection between two Lin2d or two Circ2d, the result will be TRUE if the elements are identical. The function returns FALSE in all the other cases.");
cls_IntAna2d_AnaIntersection.def("ParallelElements", (Standard_Boolean (IntAna2d_AnaIntersection::*)() const) &IntAna2d_AnaIntersection::ParallelElements, "For the intersection between two Lin2d or two Circ2d, the function returns TRUE if the elements are parallel. The function returns FALSE in all the other cases.");
cls_IntAna2d_AnaIntersection.def("NbPoints", (Standard_Integer (IntAna2d_AnaIntersection::*)() const) &IntAna2d_AnaIntersection::NbPoints, "returns the number of IntPoint between the 2 curves.");
cls_IntAna2d_AnaIntersection.def("Point", (const IntAna2d_IntPoint & (IntAna2d_AnaIntersection::*)(const Standard_Integer) const) &IntAna2d_AnaIntersection::Point, "returns the intersection point of range N; If (N<=0) or (N>NbPoints), an exception is raised.", py::arg("N"));

// Enums

}