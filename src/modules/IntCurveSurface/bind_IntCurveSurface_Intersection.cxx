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
#include <IntCurveSurface_IntersectionPoint.hxx>
#include <IntCurveSurface_IntersectionSegment.hxx>
#include <IntCurveSurface_Intersection.hxx>
#include <IntCurveSurface_SequenceOfPnt.hxx>
#include <IntCurveSurface_SequenceOfSeg.hxx>

void bind_IntCurveSurface_Intersection(py::module &mod){

py::class_<IntCurveSurface_Intersection, std::unique_ptr<IntCurveSurface_Intersection, py::nodelete>> cls_IntCurveSurface_Intersection(mod, "IntCurveSurface_Intersection", "None");

// Constructors

// Fields

// Methods
// cls_IntCurveSurface_Intersection.def_static("operator new_", (void * (*)(size_t)) &IntCurveSurface_Intersection::operator new, "None", py::arg("theSize"));
// cls_IntCurveSurface_Intersection.def_static("operator delete_", (void (*)(void *)) &IntCurveSurface_Intersection::operator delete, "None", py::arg("theAddress"));
// cls_IntCurveSurface_Intersection.def_static("operator new[]_", (void * (*)(size_t)) &IntCurveSurface_Intersection::operator new[], "None", py::arg("theSize"));
// cls_IntCurveSurface_Intersection.def_static("operator delete[]_", (void (*)(void *)) &IntCurveSurface_Intersection::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurveSurface_Intersection.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurveSurface_Intersection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurveSurface_Intersection.def_static("operator delete_", (void (*)(void *, void *)) &IntCurveSurface_Intersection::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurveSurface_Intersection.def("IsDone", (Standard_Boolean (IntCurveSurface_Intersection::*)() const) &IntCurveSurface_Intersection::IsDone, "returns the <done> field.");
cls_IntCurveSurface_Intersection.def("NbPoints", (Standard_Integer (IntCurveSurface_Intersection::*)() const) &IntCurveSurface_Intersection::NbPoints, "returns the number of IntersectionPoint if IsDone returns True. else NotDone is raised.");
cls_IntCurveSurface_Intersection.def("Point", (const IntCurveSurface_IntersectionPoint & (IntCurveSurface_Intersection::*)(const Standard_Integer) const) &IntCurveSurface_Intersection::Point, "returns the IntersectionPoint of range <Index> raises NotDone if the computation has failed or if the computation has not been done raises OutOfRange if Index is not in the range <1..NbPoints>", py::arg("Index"));
cls_IntCurveSurface_Intersection.def("NbSegments", (Standard_Integer (IntCurveSurface_Intersection::*)() const) &IntCurveSurface_Intersection::NbSegments, "returns the number of IntersectionSegment if IsDone returns True. else NotDone is raised.");
cls_IntCurveSurface_Intersection.def("Segment", (const IntCurveSurface_IntersectionSegment & (IntCurveSurface_Intersection::*)(const Standard_Integer) const) &IntCurveSurface_Intersection::Segment, "returns the IntersectionSegment of range <Index> raises NotDone if the computation has failed or if the computation has not been done raises OutOfRange if Index is not in the range <1..NbSegment>", py::arg("Index"));
cls_IntCurveSurface_Intersection.def("IsParallel", (Standard_Boolean (IntCurveSurface_Intersection::*)() const) &IntCurveSurface_Intersection::IsParallel, "Returns true if curve is parallel or belongs surface This case is recognized only for some pairs of analytical curves and surfaces (plane - line, ...)");
cls_IntCurveSurface_Intersection.def("Dump", (void (IntCurveSurface_Intersection::*)() const) &IntCurveSurface_Intersection::Dump, "Dump all the fields.");

// Enums

}