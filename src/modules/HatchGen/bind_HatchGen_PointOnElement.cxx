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
#include <HatchGen_IntersectionPoint.hxx>
#include <Standard.hxx>
#include <HatchGen_PointOnElement.hxx>
#include <IntRes2d_IntersectionPoint.hxx>
#include <HatchGen_IntersectionType.hxx>
#include <Standard_TypeDef.hxx>

void bind_HatchGen_PointOnElement(py::module &mod){

py::class_<HatchGen_PointOnElement, std::unique_ptr<HatchGen_PointOnElement>, HatchGen_IntersectionPoint> cls_HatchGen_PointOnElement(mod, "HatchGen_PointOnElement", "None");

// Constructors
cls_HatchGen_PointOnElement.def(py::init<>());
cls_HatchGen_PointOnElement.def(py::init<const HatchGen_PointOnElement &>(), py::arg("Point"));
cls_HatchGen_PointOnElement.def(py::init<const IntRes2d_IntersectionPoint &>(), py::arg("Point"));

// Fields

// Methods
// cls_HatchGen_PointOnElement.def_static("operator new_", (void * (*)(size_t)) &HatchGen_PointOnElement::operator new, "None", py::arg("theSize"));
// cls_HatchGen_PointOnElement.def_static("operator delete_", (void (*)(void *)) &HatchGen_PointOnElement::operator delete, "None", py::arg("theAddress"));
// cls_HatchGen_PointOnElement.def_static("operator new[]_", (void * (*)(size_t)) &HatchGen_PointOnElement::operator new[], "None", py::arg("theSize"));
// cls_HatchGen_PointOnElement.def_static("operator delete[]_", (void (*)(void *)) &HatchGen_PointOnElement::operator delete[], "None", py::arg("theAddress"));
// cls_HatchGen_PointOnElement.def_static("operator new_", (void * (*)(size_t, void *)) &HatchGen_PointOnElement::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HatchGen_PointOnElement.def_static("operator delete_", (void (*)(void *, void *)) &HatchGen_PointOnElement::operator delete, "None", py::arg(""), py::arg(""));
cls_HatchGen_PointOnElement.def("SetIntersectionType", (void (HatchGen_PointOnElement::*)(const HatchGen_IntersectionType)) &HatchGen_PointOnElement::SetIntersectionType, "Sets the intersection type at this point.", py::arg("Type"));
cls_HatchGen_PointOnElement.def("IntersectionType", (HatchGen_IntersectionType (HatchGen_PointOnElement::*)() const) &HatchGen_PointOnElement::IntersectionType, "Returns the intersection type at this point.");
cls_HatchGen_PointOnElement.def("IsIdentical", (Standard_Boolean (HatchGen_PointOnElement::*)(const HatchGen_PointOnElement &, const Standard_Real) const) &HatchGen_PointOnElement::IsIdentical, "Tests if the point is identical to an other. That is to say : P1.myIndex = P2.myIndex Abs (P1.myParam - P2.myParam) <= Confusion P1.myPosit = P2.myPosit P1.myBefore = P2.myBefore P1.myAfter = P2.myAfter P1.mySegBeg = P2.mySegBeg P1.mySegEnd = P2.mySegEnd P1.myType = P2.myType", py::arg("Point"), py::arg("Confusion"));
cls_HatchGen_PointOnElement.def("IsDifferent", (Standard_Boolean (HatchGen_PointOnElement::*)(const HatchGen_PointOnElement &, const Standard_Real) const) &HatchGen_PointOnElement::IsDifferent, "Tests if the point is different from an other.", py::arg("Point"), py::arg("Confusion"));
cls_HatchGen_PointOnElement.def("Dump", [](HatchGen_PointOnElement &self) -> void { return self.Dump(); });
cls_HatchGen_PointOnElement.def("Dump", (void (HatchGen_PointOnElement::*)(const Standard_Integer) const) &HatchGen_PointOnElement::Dump, "Dump of the point on element.", py::arg("Index"));

// Enums

}