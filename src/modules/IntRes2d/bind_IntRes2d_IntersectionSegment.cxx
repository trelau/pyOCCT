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
#include <IntRes2d_IntersectionPoint.hxx>
#include <Standard_TypeDef.hxx>
#include <IntRes2d_IntersectionSegment.hxx>

void bind_IntRes2d_IntersectionSegment(py::module &mod){

py::class_<IntRes2d_IntersectionSegment, std::unique_ptr<IntRes2d_IntersectionSegment>> cls_IntRes2d_IntersectionSegment(mod, "IntRes2d_IntersectionSegment", "Definition of an intersection curve between two 2D curves.");

// Constructors
cls_IntRes2d_IntersectionSegment.def(py::init<>());
cls_IntRes2d_IntersectionSegment.def(py::init<const IntRes2d_IntersectionPoint &, const IntRes2d_IntersectionPoint &, const Standard_Boolean, const Standard_Boolean>(), py::arg("P1"), py::arg("P2"), py::arg("Oppos"), py::arg("ReverseFlag"));
cls_IntRes2d_IntersectionSegment.def(py::init<const IntRes2d_IntersectionPoint &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("P"), py::arg("First"), py::arg("Oppos"), py::arg("ReverseFlag"));
cls_IntRes2d_IntersectionSegment.def(py::init<const Standard_Boolean>(), py::arg("Oppos"));

// Fields

// Methods
// cls_IntRes2d_IntersectionSegment.def_static("operator new_", (void * (*)(size_t)) &IntRes2d_IntersectionSegment::operator new, "None", py::arg("theSize"));
// cls_IntRes2d_IntersectionSegment.def_static("operator delete_", (void (*)(void *)) &IntRes2d_IntersectionSegment::operator delete, "None", py::arg("theAddress"));
// cls_IntRes2d_IntersectionSegment.def_static("operator new[]_", (void * (*)(size_t)) &IntRes2d_IntersectionSegment::operator new[], "None", py::arg("theSize"));
// cls_IntRes2d_IntersectionSegment.def_static("operator delete[]_", (void (*)(void *)) &IntRes2d_IntersectionSegment::operator delete[], "None", py::arg("theAddress"));
// cls_IntRes2d_IntersectionSegment.def_static("operator new_", (void * (*)(size_t, void *)) &IntRes2d_IntersectionSegment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntRes2d_IntersectionSegment.def_static("operator delete_", (void (*)(void *, void *)) &IntRes2d_IntersectionSegment::operator delete, "None", py::arg(""), py::arg(""));
cls_IntRes2d_IntersectionSegment.def("IsOpposite", (Standard_Boolean (IntRes2d_IntersectionSegment::*)() const) &IntRes2d_IntersectionSegment::IsOpposite, "Returns FALSE if the intersection segment has got the same orientation on both curves.");
cls_IntRes2d_IntersectionSegment.def("HasFirstPoint", (Standard_Boolean (IntRes2d_IntersectionSegment::*)() const) &IntRes2d_IntersectionSegment::HasFirstPoint, "Returns True if the segment is limited by a first point. This point defines the lowest parameter admitted on the first curve for the segment. If IsOpposite returns False, it defines the lowest parameter on the second curve, otherwise, it is the highest parameter on the second curve.");
cls_IntRes2d_IntersectionSegment.def("FirstPoint", (const IntRes2d_IntersectionPoint & (IntRes2d_IntersectionSegment::*)() const) &IntRes2d_IntersectionSegment::FirstPoint, "Returns the first point of the segment as an IntersectionPoint (with a transition). The exception DomainError is raised if HasFirstPoint returns False.");
cls_IntRes2d_IntersectionSegment.def("HasLastPoint", (Standard_Boolean (IntRes2d_IntersectionSegment::*)() const) &IntRes2d_IntersectionSegment::HasLastPoint, "Returns True if the segment is limited by a last point. This point defines the highest parameter admitted on the first curve for the segment. If IsOpposite returns False, it defines the highest parameter on the second curve, otherwise, it is the lowest parameter on the second curve.");
cls_IntRes2d_IntersectionSegment.def("LastPoint", (const IntRes2d_IntersectionPoint & (IntRes2d_IntersectionSegment::*)() const) &IntRes2d_IntersectionSegment::LastPoint, "Returns the last point of the segment as an IntersectionPoint (with a transition). The exception DomainError is raised if HasLastExtremity returns False.");

// Enums

}