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
#include <Standard_TypeDef.hxx>
#include <IntPolyh_Point.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>

void bind_IntPolyh_Point(py::module &mod){

py::class_<IntPolyh_Point> cls_IntPolyh_Point(mod, "IntPolyh_Point", "The class represents the point on the surface with both 3D and 2D points.");

// Constructors
cls_IntPolyh_Point.def(py::init<>());
cls_IntPolyh_Point.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("x"), py::arg("y"), py::arg("z"), py::arg("u"), py::arg("v"));

// Fields

// Methods
// cls_IntPolyh_Point.def_static("operator new_", (void * (*)(size_t)) &IntPolyh_Point::operator new, "None", py::arg("theSize"));
// cls_IntPolyh_Point.def_static("operator delete_", (void (*)(void *)) &IntPolyh_Point::operator delete, "None", py::arg("theAddress"));
// cls_IntPolyh_Point.def_static("operator new[]_", (void * (*)(size_t)) &IntPolyh_Point::operator new[], "None", py::arg("theSize"));
// cls_IntPolyh_Point.def_static("operator delete[]_", (void (*)(void *)) &IntPolyh_Point::operator delete[], "None", py::arg("theAddress"));
// cls_IntPolyh_Point.def_static("operator new_", (void * (*)(size_t, void *)) &IntPolyh_Point::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPolyh_Point.def_static("operator delete_", (void (*)(void *, void *)) &IntPolyh_Point::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPolyh_Point.def("X", (Standard_Real (IntPolyh_Point::*)() const) &IntPolyh_Point::X, "Returns X coordinate of the 3D point");
cls_IntPolyh_Point.def("Y", (Standard_Real (IntPolyh_Point::*)() const) &IntPolyh_Point::Y, "Returns Y coordinate of the 3D point");
cls_IntPolyh_Point.def("Z", (Standard_Real (IntPolyh_Point::*)() const) &IntPolyh_Point::Z, "Returns the Z coordinate of the 3D point");
cls_IntPolyh_Point.def("U", (Standard_Real (IntPolyh_Point::*)() const) &IntPolyh_Point::U, "Returns the U coordinate of the 2D point");
cls_IntPolyh_Point.def("V", (Standard_Real (IntPolyh_Point::*)() const) &IntPolyh_Point::V, "Returns the V coordinate of the 2D point");
cls_IntPolyh_Point.def("PartOfCommon", (Standard_Integer (IntPolyh_Point::*)() const) &IntPolyh_Point::PartOfCommon, "Returns 0 if the point is not common with the other surface");
cls_IntPolyh_Point.def("Equal", (void (IntPolyh_Point::*)(const IntPolyh_Point &)) &IntPolyh_Point::Equal, "Assignment operator", py::arg("Pt"));
// cls_IntPolyh_Point.def("operator=", (void (IntPolyh_Point::*)(const IntPolyh_Point &)) &IntPolyh_Point::operator=, "None", py::arg("Pt"));
cls_IntPolyh_Point.def("Set", [](IntPolyh_Point &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4) -> void { return self.Set(a0, a1, a2, a3, a4); });
cls_IntPolyh_Point.def("Set", (void (IntPolyh_Point::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer)) &IntPolyh_Point::Set, "Sets the point", py::arg("x"), py::arg("y"), py::arg("z"), py::arg("u"), py::arg("v"), py::arg("II"));
cls_IntPolyh_Point.def("SetX", (void (IntPolyh_Point::*)(const Standard_Real)) &IntPolyh_Point::SetX, "Sets the X coordinate for the 3D point", py::arg("x"));
cls_IntPolyh_Point.def("SetY", (void (IntPolyh_Point::*)(const Standard_Real)) &IntPolyh_Point::SetY, "Sets the Y coordinate for the 3D point", py::arg("y"));
cls_IntPolyh_Point.def("SetZ", (void (IntPolyh_Point::*)(const Standard_Real)) &IntPolyh_Point::SetZ, "Sets the Z coordinate for the 3D point", py::arg("z"));
cls_IntPolyh_Point.def("SetU", (void (IntPolyh_Point::*)(const Standard_Real)) &IntPolyh_Point::SetU, "Sets the U coordinate for the 2D point", py::arg("u"));
cls_IntPolyh_Point.def("SetV", (void (IntPolyh_Point::*)(const Standard_Real)) &IntPolyh_Point::SetV, "Sets the V coordinate for the 2D point", py::arg("v"));
cls_IntPolyh_Point.def("SetPartOfCommon", (void (IntPolyh_Point::*)(const Standard_Integer)) &IntPolyh_Point::SetPartOfCommon, "Sets the part of common", py::arg("ii"));
cls_IntPolyh_Point.def("Middle", (void (IntPolyh_Point::*)(const opencascade::handle<Adaptor3d_HSurface> &, const IntPolyh_Point &, const IntPolyh_Point &)) &IntPolyh_Point::Middle, "Creates middle point from P1 and P2 and stores it to this", py::arg("MySurface"), py::arg("P1"), py::arg("P2"));
cls_IntPolyh_Point.def("Add", (IntPolyh_Point (IntPolyh_Point::*)(const IntPolyh_Point &) const) &IntPolyh_Point::Add, "Addition", py::arg("P1"));
cls_IntPolyh_Point.def("__add__", (IntPolyh_Point (IntPolyh_Point::*)(const IntPolyh_Point &) const) &IntPolyh_Point::operator+, py::is_operator(), "None", py::arg("P1"));
cls_IntPolyh_Point.def("Sub", (IntPolyh_Point (IntPolyh_Point::*)(const IntPolyh_Point &) const) &IntPolyh_Point::Sub, "Subtraction", py::arg("P1"));
cls_IntPolyh_Point.def("__sub__", (IntPolyh_Point (IntPolyh_Point::*)(const IntPolyh_Point &) const) &IntPolyh_Point::operator-, py::is_operator(), "None", py::arg("P1"));
cls_IntPolyh_Point.def("Divide", (IntPolyh_Point (IntPolyh_Point::*)(const Standard_Real) const) &IntPolyh_Point::Divide, "Division", py::arg("rr"));
cls_IntPolyh_Point.def("__truediv__", (IntPolyh_Point (IntPolyh_Point::*)(const Standard_Real) const) &IntPolyh_Point::operator/, py::is_operator(), "None", py::arg("rr"));
cls_IntPolyh_Point.def("Multiplication", (IntPolyh_Point (IntPolyh_Point::*)(const Standard_Real) const) &IntPolyh_Point::Multiplication, "Multiplication", py::arg("rr"));
cls_IntPolyh_Point.def("__mul__", (IntPolyh_Point (IntPolyh_Point::*)(const Standard_Real) const) &IntPolyh_Point::operator*, py::is_operator(), "None", py::arg("rr"));
cls_IntPolyh_Point.def("SquareModulus", (Standard_Real (IntPolyh_Point::*)() const) &IntPolyh_Point::SquareModulus, "Square modulus");
cls_IntPolyh_Point.def("SquareDistance", (Standard_Real (IntPolyh_Point::*)(const IntPolyh_Point &) const) &IntPolyh_Point::SquareDistance, "Square distance to the other point", py::arg("P2"));
cls_IntPolyh_Point.def("Dot", (Standard_Real (IntPolyh_Point::*)(const IntPolyh_Point &) const) &IntPolyh_Point::Dot, "Dot", py::arg("P2"));
cls_IntPolyh_Point.def("Cross", (void (IntPolyh_Point::*)(const IntPolyh_Point &, const IntPolyh_Point &)) &IntPolyh_Point::Cross, "Cross", py::arg("P1"), py::arg("P2"));
cls_IntPolyh_Point.def("Dump", (void (IntPolyh_Point::*)() const) &IntPolyh_Point::Dump, "Dump");
cls_IntPolyh_Point.def("Dump", (void (IntPolyh_Point::*)(const Standard_Integer) const) &IntPolyh_Point::Dump, "Dump", py::arg("i"));
cls_IntPolyh_Point.def("SetDegenerated", (void (IntPolyh_Point::*)(const Standard_Boolean)) &IntPolyh_Point::SetDegenerated, "Sets the degenerated flag", py::arg("theFlag"));
cls_IntPolyh_Point.def("Degenerated", (Standard_Boolean (IntPolyh_Point::*)() const) &IntPolyh_Point::Degenerated, "Returns the degenerated flag");

// Enums

}