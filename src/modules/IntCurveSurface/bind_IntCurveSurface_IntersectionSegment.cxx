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
#include <IntCurveSurface_IntersectionPoint.hxx>
#include <IntCurveSurface_IntersectionSegment.hxx>

void bind_IntCurveSurface_IntersectionSegment(py::module &mod){

py::class_<IntCurveSurface_IntersectionSegment, std::unique_ptr<IntCurveSurface_IntersectionSegment>> cls_IntCurveSurface_IntersectionSegment(mod, "IntCurveSurface_IntersectionSegment", "A IntersectionSegment describes a segment of curve (w1,w2) where distance(C(w),Surface) is less than a given tolerances.");

// Constructors
cls_IntCurveSurface_IntersectionSegment.def(py::init<>());
cls_IntCurveSurface_IntersectionSegment.def(py::init<const IntCurveSurface_IntersectionPoint &, const IntCurveSurface_IntersectionPoint &>(), py::arg("P1"), py::arg("P2"));

// Fields

// Methods
// cls_IntCurveSurface_IntersectionSegment.def_static("operator new_", (void * (*)(size_t)) &IntCurveSurface_IntersectionSegment::operator new, "None", py::arg("theSize"));
// cls_IntCurveSurface_IntersectionSegment.def_static("operator delete_", (void (*)(void *)) &IntCurveSurface_IntersectionSegment::operator delete, "None", py::arg("theAddress"));
// cls_IntCurveSurface_IntersectionSegment.def_static("operator new[]_", (void * (*)(size_t)) &IntCurveSurface_IntersectionSegment::operator new[], "None", py::arg("theSize"));
// cls_IntCurveSurface_IntersectionSegment.def_static("operator delete[]_", (void (*)(void *)) &IntCurveSurface_IntersectionSegment::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurveSurface_IntersectionSegment.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurveSurface_IntersectionSegment::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurveSurface_IntersectionSegment.def_static("operator delete_", (void (*)(void *, void *)) &IntCurveSurface_IntersectionSegment::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurveSurface_IntersectionSegment.def("SetValues", (void (IntCurveSurface_IntersectionSegment::*)(const IntCurveSurface_IntersectionPoint &, const IntCurveSurface_IntersectionPoint &)) &IntCurveSurface_IntersectionSegment::SetValues, "None", py::arg("P1"), py::arg("P2"));
cls_IntCurveSurface_IntersectionSegment.def("Values", (void (IntCurveSurface_IntersectionSegment::*)(IntCurveSurface_IntersectionPoint &, IntCurveSurface_IntersectionPoint &) const) &IntCurveSurface_IntersectionSegment::Values, "None", py::arg("P1"), py::arg("P2"));
cls_IntCurveSurface_IntersectionSegment.def("FirstPoint", (void (IntCurveSurface_IntersectionSegment::*)(IntCurveSurface_IntersectionPoint &) const) &IntCurveSurface_IntersectionSegment::FirstPoint, "None", py::arg("P1"));
cls_IntCurveSurface_IntersectionSegment.def("SecondPoint", (void (IntCurveSurface_IntersectionSegment::*)(IntCurveSurface_IntersectionPoint &) const) &IntCurveSurface_IntersectionSegment::SecondPoint, "None", py::arg("P2"));
cls_IntCurveSurface_IntersectionSegment.def("FirstPoint", (const IntCurveSurface_IntersectionPoint & (IntCurveSurface_IntersectionSegment::*)() const) &IntCurveSurface_IntersectionSegment::FirstPoint, "None");
cls_IntCurveSurface_IntersectionSegment.def("SecondPoint", (const IntCurveSurface_IntersectionPoint & (IntCurveSurface_IntersectionSegment::*)() const) &IntCurveSurface_IntersectionSegment::SecondPoint, "None");
cls_IntCurveSurface_IntersectionSegment.def("Dump", (void (IntCurveSurface_IntersectionSegment::*)() const) &IntCurveSurface_IntersectionSegment::Dump, "None");

// Enums

}