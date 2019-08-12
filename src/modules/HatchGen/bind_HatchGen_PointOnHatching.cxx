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
#include <HatchGen_PointOnHatching.hxx>
#include <IntRes2d_IntersectionPoint.hxx>
#include <HatchGen_PointOnElement.hxx>
#include <Standard_TypeDef.hxx>
#include <HatchGen_PointsOnElement.hxx>

void bind_HatchGen_PointOnHatching(py::module &mod){

py::class_<HatchGen_PointOnHatching, std::unique_ptr<HatchGen_PointOnHatching, Deleter<HatchGen_PointOnHatching>>, HatchGen_IntersectionPoint> cls_HatchGen_PointOnHatching(mod, "HatchGen_PointOnHatching", "None");

// Constructors
cls_HatchGen_PointOnHatching.def(py::init<>());
cls_HatchGen_PointOnHatching.def(py::init<const HatchGen_PointOnHatching &>(), py::arg("Point"));
cls_HatchGen_PointOnHatching.def(py::init<const IntRes2d_IntersectionPoint &>(), py::arg("Point"));

// Fields

// Methods
// cls_HatchGen_PointOnHatching.def_static("operator new_", (void * (*)(size_t)) &HatchGen_PointOnHatching::operator new, "None", py::arg("theSize"));
// cls_HatchGen_PointOnHatching.def_static("operator delete_", (void (*)(void *)) &HatchGen_PointOnHatching::operator delete, "None", py::arg("theAddress"));
// cls_HatchGen_PointOnHatching.def_static("operator new[]_", (void * (*)(size_t)) &HatchGen_PointOnHatching::operator new[], "None", py::arg("theSize"));
// cls_HatchGen_PointOnHatching.def_static("operator delete[]_", (void (*)(void *)) &HatchGen_PointOnHatching::operator delete[], "None", py::arg("theAddress"));
// cls_HatchGen_PointOnHatching.def_static("operator new_", (void * (*)(size_t, void *)) &HatchGen_PointOnHatching::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HatchGen_PointOnHatching.def_static("operator delete_", (void (*)(void *, void *)) &HatchGen_PointOnHatching::operator delete, "None", py::arg(""), py::arg(""));
cls_HatchGen_PointOnHatching.def("AddPoint", (void (HatchGen_PointOnHatching::*)(const HatchGen_PointOnElement &, const Standard_Real)) &HatchGen_PointOnHatching::AddPoint, "Adds a point on element to the point.", py::arg("Point"), py::arg("Confusion"));
cls_HatchGen_PointOnHatching.def("NbPoints", (Standard_Integer (HatchGen_PointOnHatching::*)() const) &HatchGen_PointOnHatching::NbPoints, "Returns the number of elements intersecting the hatching at this point.");
cls_HatchGen_PointOnHatching.def("Point", (const HatchGen_PointOnElement & (HatchGen_PointOnHatching::*)(const Standard_Integer) const) &HatchGen_PointOnHatching::Point, "Returns the Index-th point on element of the point. The exception OutOfRange is raised if Index > NbPoints.", py::arg("Index"));
cls_HatchGen_PointOnHatching.def("RemPoint", (void (HatchGen_PointOnHatching::*)(const Standard_Integer)) &HatchGen_PointOnHatching::RemPoint, "Removes the Index-th point on element of the point. The exception OutOfRange is raised if Index > NbPoints.", py::arg("Index"));
cls_HatchGen_PointOnHatching.def("ClrPoints", (void (HatchGen_PointOnHatching::*)()) &HatchGen_PointOnHatching::ClrPoints, "Removes all the points on element of the point.");
cls_HatchGen_PointOnHatching.def("IsLower", (Standard_Boolean (HatchGen_PointOnHatching::*)(const HatchGen_PointOnHatching &, const Standard_Real) const) &HatchGen_PointOnHatching::IsLower, "Tests if the point is lower than an other. A point on hatching P1 is said to be lower than an other P2 if : P2.myParam - P1.myParam > Confusion", py::arg("Point"), py::arg("Confusion"));
cls_HatchGen_PointOnHatching.def("IsEqual", (Standard_Boolean (HatchGen_PointOnHatching::*)(const HatchGen_PointOnHatching &, const Standard_Real) const) &HatchGen_PointOnHatching::IsEqual, "Tests if the point is equal to an other. A point on hatching P1 is said to be equal to an other P2 if : | P2.myParam - P1.myParam | <= Confusion", py::arg("Point"), py::arg("Confusion"));
cls_HatchGen_PointOnHatching.def("IsGreater", (Standard_Boolean (HatchGen_PointOnHatching::*)(const HatchGen_PointOnHatching &, const Standard_Real) const) &HatchGen_PointOnHatching::IsGreater, "Tests if the point is greater than an other. A point on hatching P1 is said to be greater than an other P2 if : P1.myParam - P2.myParam > Confusion", py::arg("Point"), py::arg("Confusion"));
cls_HatchGen_PointOnHatching.def("Dump", [](HatchGen_PointOnHatching &self) -> void { return self.Dump(); });
cls_HatchGen_PointOnHatching.def("Dump", (void (HatchGen_PointOnHatching::*)(const Standard_Integer) const) &HatchGen_PointOnHatching::Dump, "Dump of the point.", py::arg("Index"));

// Enums

}