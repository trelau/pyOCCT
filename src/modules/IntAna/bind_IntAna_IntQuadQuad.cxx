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
#include <gp_Cylinder.hxx>
#include <IntAna_Quadric.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Cone.hxx>
#include <IntAna_Curve.hxx>
#include <gp_Pnt.hxx>
#include <IntAna_IntQuadQuad.hxx>

void bind_IntAna_IntQuadQuad(py::module &mod){

py::class_<IntAna_IntQuadQuad, std::unique_ptr<IntAna_IntQuadQuad, Deleter<IntAna_IntQuadQuad>>> cls_IntAna_IntQuadQuad(mod, "IntAna_IntQuadQuad", "This class provides the analytic intersection between a cylinder or a cone from gp and another quadric, as defined in the class Quadric from IntAna. This algorithm is used when the geometric intersection (class QuadQuadGeo from IntAna) returns no geometric solution. The result of the intersection may be - Curves as defined in the class Curve from IntAna - Points (Pnt from gp)");

// Constructors
cls_IntAna_IntQuadQuad.def(py::init<>());
cls_IntAna_IntQuadQuad.def(py::init<const gp_Cylinder &, const IntAna_Quadric &, const Standard_Real>(), py::arg("C"), py::arg("Q"), py::arg("Tol"));
cls_IntAna_IntQuadQuad.def(py::init<const gp_Cone &, const IntAna_Quadric &, const Standard_Real>(), py::arg("C"), py::arg("Q"), py::arg("Tol"));

// Fields

// Methods
// cls_IntAna_IntQuadQuad.def_static("operator new_", (void * (*)(size_t)) &IntAna_IntQuadQuad::operator new, "None", py::arg("theSize"));
// cls_IntAna_IntQuadQuad.def_static("operator delete_", (void (*)(void *)) &IntAna_IntQuadQuad::operator delete, "None", py::arg("theAddress"));
// cls_IntAna_IntQuadQuad.def_static("operator new[]_", (void * (*)(size_t)) &IntAna_IntQuadQuad::operator new[], "None", py::arg("theSize"));
// cls_IntAna_IntQuadQuad.def_static("operator delete[]_", (void (*)(void *)) &IntAna_IntQuadQuad::operator delete[], "None", py::arg("theAddress"));
// cls_IntAna_IntQuadQuad.def_static("operator new_", (void * (*)(size_t, void *)) &IntAna_IntQuadQuad::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntAna_IntQuadQuad.def_static("operator delete_", (void (*)(void *, void *)) &IntAna_IntQuadQuad::operator delete, "None", py::arg(""), py::arg(""));
cls_IntAna_IntQuadQuad.def("Perform", (void (IntAna_IntQuadQuad::*)(const gp_Cylinder &, const IntAna_Quadric &, const Standard_Real)) &IntAna_IntQuadQuad::Perform, "Intersects a cylinder and a quadric . Tol est a definir plus precisemment.", py::arg("C"), py::arg("Q"), py::arg("Tol"));
cls_IntAna_IntQuadQuad.def("Perform", (void (IntAna_IntQuadQuad::*)(const gp_Cone &, const IntAna_Quadric &, const Standard_Real)) &IntAna_IntQuadQuad::Perform, "Intersects a cone and a quadric. Tol est a definir plus precisemment.", py::arg("C"), py::arg("Q"), py::arg("Tol"));
cls_IntAna_IntQuadQuad.def("IsDone", (Standard_Boolean (IntAna_IntQuadQuad::*)() const) &IntAna_IntQuadQuad::IsDone, "Returns True if the computation was successful.");
cls_IntAna_IntQuadQuad.def("IdenticalElements", (Standard_Boolean (IntAna_IntQuadQuad::*)() const) &IntAna_IntQuadQuad::IdenticalElements, "Returns TRUE if the cylinder, the cone or the sphere is identical to the quadric.");
cls_IntAna_IntQuadQuad.def("NbCurve", (Standard_Integer (IntAna_IntQuadQuad::*)() const) &IntAna_IntQuadQuad::NbCurve, "Returns the number of curves solution.");
cls_IntAna_IntQuadQuad.def("Curve", (const IntAna_Curve & (IntAna_IntQuadQuad::*)(const Standard_Integer) const) &IntAna_IntQuadQuad::Curve, "Returns the curve of range N.", py::arg("N"));
cls_IntAna_IntQuadQuad.def("NbPnt", (Standard_Integer (IntAna_IntQuadQuad::*)() const) &IntAna_IntQuadQuad::NbPnt, "Returns the number of contact point.");
cls_IntAna_IntQuadQuad.def("Point", (const gp_Pnt & (IntAna_IntQuadQuad::*)(const Standard_Integer) const) &IntAna_IntQuadQuad::Point, "Returns the point of range N.", py::arg("N"));
cls_IntAna_IntQuadQuad.def("Parameters", [](IntAna_IntQuadQuad &self, const Standard_Integer N, Standard_Real & U1, Standard_Real & U2){ self.Parameters(N, U1, U2); return std::tuple<Standard_Real &, Standard_Real &>(U1, U2); }, "Returns the paramaters on the 'explicit quadric' (i.e the cylinder or the cone, the first argument given to the constructor) of the point of range N.", py::arg("N"), py::arg("U1"), py::arg("U2"));
cls_IntAna_IntQuadQuad.def("HasNextCurve", (Standard_Boolean (IntAna_IntQuadQuad::*)(const Standard_Integer) const) &IntAna_IntQuadQuad::HasNextCurve, "Returns True if the Curve I shares its last bound with another curve.", py::arg("I"));
cls_IntAna_IntQuadQuad.def("NextCurve", [](IntAna_IntQuadQuad &self, const Standard_Integer I, Standard_Boolean & theOpposite){ Standard_Integer rv = self.NextCurve(I, theOpposite); return std::tuple<Standard_Integer, Standard_Boolean &>(rv, theOpposite); }, "If HasNextCurve(I) returns True, this function returns the Index J of the curve which has a common bound with the curve I. If theOpposite == True , then the last parameter of the curve I, and the last parameter of the curve J give the same point. Else the last parameter of the curve I and the first parameter of the curve J are the same point.", py::arg("I"), py::arg("theOpposite"));
cls_IntAna_IntQuadQuad.def("HasPreviousCurve", (Standard_Boolean (IntAna_IntQuadQuad::*)(const Standard_Integer) const) &IntAna_IntQuadQuad::HasPreviousCurve, "Returns True if the Curve I shares its first bound with another curve.", py::arg("I"));
cls_IntAna_IntQuadQuad.def("PreviousCurve", [](IntAna_IntQuadQuad &self, const Standard_Integer I, Standard_Boolean & theOpposite){ Standard_Integer rv = self.PreviousCurve(I, theOpposite); return std::tuple<Standard_Integer, Standard_Boolean &>(rv, theOpposite); }, "if HasPreviousCurve(I) returns True, this function returns the Index J of the curve which has a common bound with the curve I. If theOpposite == True , then the first parameter of the curve I, and the first parameter of the curve J give the same point. Else the first parameter of the curve I and the last parameter of the curve J are the same point.", py::arg("I"), py::arg("theOpposite"));

// Enums

}