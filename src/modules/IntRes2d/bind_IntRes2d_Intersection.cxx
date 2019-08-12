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
#include <IntRes2d_IntersectionPoint.hxx>
#include <IntRes2d_IntersectionSegment.hxx>
#include <IntRes2d_Intersection.hxx>
#include <IntRes2d_SequenceOfIntersectionPoint.hxx>
#include <IntRes2d_SequenceOfIntersectionSegment.hxx>

void bind_IntRes2d_Intersection(py::module &mod){

py::class_<IntRes2d_Intersection, std::unique_ptr<IntRes2d_Intersection, py::nodelete>> cls_IntRes2d_Intersection(mod, "IntRes2d_Intersection", "Defines the root class of all the Intersections between two 2D-Curves, and provides all the methods about the results of the Intersections Algorithms.");

// Constructors

// Fields

// Methods
// cls_IntRes2d_Intersection.def_static("operator new_", (void * (*)(size_t)) &IntRes2d_Intersection::operator new, "None", py::arg("theSize"));
// cls_IntRes2d_Intersection.def_static("operator delete_", (void (*)(void *)) &IntRes2d_Intersection::operator delete, "None", py::arg("theAddress"));
// cls_IntRes2d_Intersection.def_static("operator new[]_", (void * (*)(size_t)) &IntRes2d_Intersection::operator new[], "None", py::arg("theSize"));
// cls_IntRes2d_Intersection.def_static("operator delete[]_", (void (*)(void *)) &IntRes2d_Intersection::operator delete[], "None", py::arg("theAddress"));
// cls_IntRes2d_Intersection.def_static("operator new_", (void * (*)(size_t, void *)) &IntRes2d_Intersection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntRes2d_Intersection.def_static("operator delete_", (void (*)(void *, void *)) &IntRes2d_Intersection::operator delete, "None", py::arg(""), py::arg(""));
cls_IntRes2d_Intersection.def("IsDone", (Standard_Boolean (IntRes2d_Intersection::*)() const) &IntRes2d_Intersection::IsDone, "returns TRUE when the computation was successful.");
cls_IntRes2d_Intersection.def("IsEmpty", (Standard_Boolean (IntRes2d_Intersection::*)() const) &IntRes2d_Intersection::IsEmpty, "Returns TRUE if there is no intersection between the given arguments. The exception NotDone is raised if IsDone returns FALSE.");
cls_IntRes2d_Intersection.def("NbPoints", (Standard_Integer (IntRes2d_Intersection::*)() const) &IntRes2d_Intersection::NbPoints, "This function returns the number of intersection points between the 2 curves. The exception NotDone is raised if IsDone returns FALSE.");
cls_IntRes2d_Intersection.def("Point", (const IntRes2d_IntersectionPoint & (IntRes2d_Intersection::*)(const Standard_Integer) const) &IntRes2d_Intersection::Point, "This function returns the intersection point of range N; The exception NotDone is raised if IsDone returns FALSE. The exception OutOfRange is raised if (N <= 0) or (N > NbPoints).", py::arg("N"));
cls_IntRes2d_Intersection.def("NbSegments", (Standard_Integer (IntRes2d_Intersection::*)() const) &IntRes2d_Intersection::NbSegments, "This function returns the number of intersection segments between the two curves. The exception NotDone is raised if IsDone returns FALSE.");
cls_IntRes2d_Intersection.def("Segment", (const IntRes2d_IntersectionSegment & (IntRes2d_Intersection::*)(const Standard_Integer) const) &IntRes2d_Intersection::Segment, "This function returns the intersection segment of range N; The exception NotDone is raised if IsDone returns FALSE. The exception OutOfRange is raised if (N <= 0) or (N > NbPoints).", py::arg("N"));
cls_IntRes2d_Intersection.def("SetReversedParameters", (void (IntRes2d_Intersection::*)(const Standard_Boolean)) &IntRes2d_Intersection::SetReversedParameters, "None", py::arg("Reverseflag"));

// Enums

}