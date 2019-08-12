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
#include <Standard_Handle.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <IntPatch_ThePathPointOfTheSOnBounds.hxx>
#include <Standard_TypeDef.hxx>
#include <IntPatch_TheSegmentOfTheSOnBounds.hxx>

void bind_IntPatch_TheSegmentOfTheSOnBounds(py::module &mod){

py::class_<IntPatch_TheSegmentOfTheSOnBounds, std::unique_ptr<IntPatch_TheSegmentOfTheSOnBounds, Deleter<IntPatch_TheSegmentOfTheSOnBounds>>> cls_IntPatch_TheSegmentOfTheSOnBounds(mod, "IntPatch_TheSegmentOfTheSOnBounds", "None");

// Constructors
cls_IntPatch_TheSegmentOfTheSOnBounds.def(py::init<>());

// Fields

// Methods
// cls_IntPatch_TheSegmentOfTheSOnBounds.def_static("operator new_", (void * (*)(size_t)) &IntPatch_TheSegmentOfTheSOnBounds::operator new, "None", py::arg("theSize"));
// cls_IntPatch_TheSegmentOfTheSOnBounds.def_static("operator delete_", (void (*)(void *)) &IntPatch_TheSegmentOfTheSOnBounds::operator delete, "None", py::arg("theAddress"));
// cls_IntPatch_TheSegmentOfTheSOnBounds.def_static("operator new[]_", (void * (*)(size_t)) &IntPatch_TheSegmentOfTheSOnBounds::operator new[], "None", py::arg("theSize"));
// cls_IntPatch_TheSegmentOfTheSOnBounds.def_static("operator delete[]_", (void (*)(void *)) &IntPatch_TheSegmentOfTheSOnBounds::operator delete[], "None", py::arg("theAddress"));
// cls_IntPatch_TheSegmentOfTheSOnBounds.def_static("operator new_", (void * (*)(size_t, void *)) &IntPatch_TheSegmentOfTheSOnBounds::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPatch_TheSegmentOfTheSOnBounds.def_static("operator delete_", (void (*)(void *, void *)) &IntPatch_TheSegmentOfTheSOnBounds::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPatch_TheSegmentOfTheSOnBounds.def("SetValue", (void (IntPatch_TheSegmentOfTheSOnBounds::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &IntPatch_TheSegmentOfTheSOnBounds::SetValue, "Defines the concerned arc.", py::arg("A"));
cls_IntPatch_TheSegmentOfTheSOnBounds.def("SetLimitPoint", (void (IntPatch_TheSegmentOfTheSOnBounds::*)(const IntPatch_ThePathPointOfTheSOnBounds &, const Standard_Boolean)) &IntPatch_TheSegmentOfTheSOnBounds::SetLimitPoint, "Defines the first point or the last point, depending on the value of the boolean First.", py::arg("V"), py::arg("First"));
cls_IntPatch_TheSegmentOfTheSOnBounds.def("Curve", (const opencascade::handle<Adaptor2d_HCurve2d> & (IntPatch_TheSegmentOfTheSOnBounds::*)() const) &IntPatch_TheSegmentOfTheSOnBounds::Curve, "Returns the geometric curve on the surface 's domain which is solution.");
cls_IntPatch_TheSegmentOfTheSOnBounds.def("HasFirstPoint", (Standard_Boolean (IntPatch_TheSegmentOfTheSOnBounds::*)() const) &IntPatch_TheSegmentOfTheSOnBounds::HasFirstPoint, "Returns True if there is a vertex (ThePathPoint) defining the lowest valid parameter on the arc.");
cls_IntPatch_TheSegmentOfTheSOnBounds.def("FirstPoint", (const IntPatch_ThePathPointOfTheSOnBounds & (IntPatch_TheSegmentOfTheSOnBounds::*)() const) &IntPatch_TheSegmentOfTheSOnBounds::FirstPoint, "Returns the first point.");
cls_IntPatch_TheSegmentOfTheSOnBounds.def("HasLastPoint", (Standard_Boolean (IntPatch_TheSegmentOfTheSOnBounds::*)() const) &IntPatch_TheSegmentOfTheSOnBounds::HasLastPoint, "Returns True if there is a vertex (ThePathPoint) defining the greatest valid parameter on the arc.");
cls_IntPatch_TheSegmentOfTheSOnBounds.def("LastPoint", (const IntPatch_ThePathPointOfTheSOnBounds & (IntPatch_TheSegmentOfTheSOnBounds::*)() const) &IntPatch_TheSegmentOfTheSOnBounds::LastPoint, "Returns the last point.");

// Enums

}