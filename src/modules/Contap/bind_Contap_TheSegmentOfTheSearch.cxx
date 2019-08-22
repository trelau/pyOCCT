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
#include <Contap_ThePathPointOfTheSearch.hxx>
#include <Standard_TypeDef.hxx>
#include <Contap_TheSegmentOfTheSearch.hxx>

void bind_Contap_TheSegmentOfTheSearch(py::module &mod){

py::class_<Contap_TheSegmentOfTheSearch> cls_Contap_TheSegmentOfTheSearch(mod, "Contap_TheSegmentOfTheSearch", "None");

// Constructors
cls_Contap_TheSegmentOfTheSearch.def(py::init<>());

// Fields

// Methods
// cls_Contap_TheSegmentOfTheSearch.def_static("operator new_", (void * (*)(size_t)) &Contap_TheSegmentOfTheSearch::operator new, "None", py::arg("theSize"));
// cls_Contap_TheSegmentOfTheSearch.def_static("operator delete_", (void (*)(void *)) &Contap_TheSegmentOfTheSearch::operator delete, "None", py::arg("theAddress"));
// cls_Contap_TheSegmentOfTheSearch.def_static("operator new[]_", (void * (*)(size_t)) &Contap_TheSegmentOfTheSearch::operator new[], "None", py::arg("theSize"));
// cls_Contap_TheSegmentOfTheSearch.def_static("operator delete[]_", (void (*)(void *)) &Contap_TheSegmentOfTheSearch::operator delete[], "None", py::arg("theAddress"));
// cls_Contap_TheSegmentOfTheSearch.def_static("operator new_", (void * (*)(size_t, void *)) &Contap_TheSegmentOfTheSearch::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Contap_TheSegmentOfTheSearch.def_static("operator delete_", (void (*)(void *, void *)) &Contap_TheSegmentOfTheSearch::operator delete, "None", py::arg(""), py::arg(""));
cls_Contap_TheSegmentOfTheSearch.def("SetValue", (void (Contap_TheSegmentOfTheSearch::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Contap_TheSegmentOfTheSearch::SetValue, "Defines the concerned arc.", py::arg("A"));
cls_Contap_TheSegmentOfTheSearch.def("SetLimitPoint", (void (Contap_TheSegmentOfTheSearch::*)(const Contap_ThePathPointOfTheSearch &, const Standard_Boolean)) &Contap_TheSegmentOfTheSearch::SetLimitPoint, "Defines the first point or the last point, depending on the value of the boolean First.", py::arg("V"), py::arg("First"));
cls_Contap_TheSegmentOfTheSearch.def("Curve", (const opencascade::handle<Adaptor2d_HCurve2d> & (Contap_TheSegmentOfTheSearch::*)() const) &Contap_TheSegmentOfTheSearch::Curve, "Returns the geometric curve on the surface 's domain which is solution.");
cls_Contap_TheSegmentOfTheSearch.def("HasFirstPoint", (Standard_Boolean (Contap_TheSegmentOfTheSearch::*)() const) &Contap_TheSegmentOfTheSearch::HasFirstPoint, "Returns True if there is a vertex (ThePathPoint) defining the lowest valid parameter on the arc.");
cls_Contap_TheSegmentOfTheSearch.def("FirstPoint", (const Contap_ThePathPointOfTheSearch & (Contap_TheSegmentOfTheSearch::*)() const) &Contap_TheSegmentOfTheSearch::FirstPoint, "Returns the first point.");
cls_Contap_TheSegmentOfTheSearch.def("HasLastPoint", (Standard_Boolean (Contap_TheSegmentOfTheSearch::*)() const) &Contap_TheSegmentOfTheSearch::HasLastPoint, "Returns True if there is a vertex (ThePathPoint) defining the greatest valid parameter on the arc.");
cls_Contap_TheSegmentOfTheSearch.def("LastPoint", (const Contap_ThePathPointOfTheSearch & (Contap_TheSegmentOfTheSearch::*)() const) &Contap_TheSegmentOfTheSearch::LastPoint, "Returns the last point.");

// Enums

}