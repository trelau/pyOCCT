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
#include <IntPatch_ArcFunction.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_TopolTool.hxx>
#include <Standard_TypeDef.hxx>
#include <IntPatch_ThePathPointOfTheSOnBounds.hxx>
#include <IntPatch_TheSegmentOfTheSOnBounds.hxx>
#include <IntPatch_SequenceOfSegmentOfTheSOnBounds.hxx>
#include <IntPatch_SequenceOfPathPointOfTheSOnBounds.hxx>
#include <IntPatch_TheSOnBounds.hxx>

void bind_IntPatch_TheSOnBounds(py::module &mod){

py::class_<IntPatch_TheSOnBounds> cls_IntPatch_TheSOnBounds(mod, "IntPatch_TheSOnBounds", "None");

// Constructors
cls_IntPatch_TheSOnBounds.def(py::init<>());

// Fields

// Methods
// cls_IntPatch_TheSOnBounds.def_static("operator new_", (void * (*)(size_t)) &IntPatch_TheSOnBounds::operator new, "None", py::arg("theSize"));
// cls_IntPatch_TheSOnBounds.def_static("operator delete_", (void (*)(void *)) &IntPatch_TheSOnBounds::operator delete, "None", py::arg("theAddress"));
// cls_IntPatch_TheSOnBounds.def_static("operator new[]_", (void * (*)(size_t)) &IntPatch_TheSOnBounds::operator new[], "None", py::arg("theSize"));
// cls_IntPatch_TheSOnBounds.def_static("operator delete[]_", (void (*)(void *)) &IntPatch_TheSOnBounds::operator delete[], "None", py::arg("theAddress"));
// cls_IntPatch_TheSOnBounds.def_static("operator new_", (void * (*)(size_t, void *)) &IntPatch_TheSOnBounds::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPatch_TheSOnBounds.def_static("operator delete_", (void (*)(void *, void *)) &IntPatch_TheSOnBounds::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPatch_TheSOnBounds.def("Perform", [](IntPatch_TheSOnBounds &self, IntPatch_ArcFunction & a0, const opencascade::handle<Adaptor3d_TopolTool> & a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.Perform(a0, a1, a2, a3); });
cls_IntPatch_TheSOnBounds.def("Perform", (void (IntPatch_TheSOnBounds::*)(IntPatch_ArcFunction &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &IntPatch_TheSOnBounds::Perform, "Algorithm to find the points and parts of curves of Domain (domain of of restriction of a surface) which verify F = 0. TolBoundary defines if a curve is on Q. TolTangency defines if a point is on Q.", py::arg("F"), py::arg("Domain"), py::arg("TolBoundary"), py::arg("TolTangency"), py::arg("RecheckOnRegularity"));
cls_IntPatch_TheSOnBounds.def("IsDone", (Standard_Boolean (IntPatch_TheSOnBounds::*)() const) &IntPatch_TheSOnBounds::IsDone, "Returns True if the calculus was successful.");
cls_IntPatch_TheSOnBounds.def("AllArcSolution", (Standard_Boolean (IntPatch_TheSOnBounds::*)() const) &IntPatch_TheSOnBounds::AllArcSolution, "Returns true if all arc of the Arcs are solution (inside the surface). An exception is raised if IsDone returns False.");
cls_IntPatch_TheSOnBounds.def("NbPoints", (Standard_Integer (IntPatch_TheSOnBounds::*)() const) &IntPatch_TheSOnBounds::NbPoints, "Returns the number of resulting points. An exception is raised if IsDone returns False (NotDone).");
cls_IntPatch_TheSOnBounds.def("Point", (const IntPatch_ThePathPointOfTheSOnBounds & (IntPatch_TheSOnBounds::*)(const Standard_Integer) const) &IntPatch_TheSOnBounds::Point, "Returns the resulting point of range Index. The exception NotDone is raised if IsDone() returns False. The exception OutOfRange is raised if Index <= 0 or Index > NbPoints.", py::arg("Index"));
cls_IntPatch_TheSOnBounds.def("NbSegments", (Standard_Integer (IntPatch_TheSOnBounds::*)() const) &IntPatch_TheSOnBounds::NbSegments, "Returns the number of the resulting segments. An exception is raised if IsDone returns False (NotDone).");
cls_IntPatch_TheSOnBounds.def("Segment", (const IntPatch_TheSegmentOfTheSOnBounds & (IntPatch_TheSOnBounds::*)(const Standard_Integer) const) &IntPatch_TheSOnBounds::Segment, "Returns the resulting segment of range Index. The exception NotDone is raised if IsDone() returns False. The exception OutOfRange is raised if Index <= 0 or Index > NbPoints.", py::arg("Index"));

// Enums

}