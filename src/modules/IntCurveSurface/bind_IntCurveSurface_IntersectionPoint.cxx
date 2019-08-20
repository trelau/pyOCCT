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
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <IntCurveSurface_TransitionOnCurve.hxx>
#include <IntCurveSurface_IntersectionPoint.hxx>

void bind_IntCurveSurface_IntersectionPoint(py::module &mod){

py::class_<IntCurveSurface_IntersectionPoint, std::unique_ptr<IntCurveSurface_IntersectionPoint>> cls_IntCurveSurface_IntersectionPoint(mod, "IntCurveSurface_IntersectionPoint", "Definition of an interserction point between a curve and a surface.");

// Constructors
cls_IntCurveSurface_IntersectionPoint.def(py::init<>());
cls_IntCurveSurface_IntersectionPoint.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const IntCurveSurface_TransitionOnCurve>(), py::arg("P"), py::arg("USurf"), py::arg("VSurf"), py::arg("UCurv"), py::arg("TrCurv"));

// Fields

// Methods
// cls_IntCurveSurface_IntersectionPoint.def_static("operator new_", (void * (*)(size_t)) &IntCurveSurface_IntersectionPoint::operator new, "None", py::arg("theSize"));
// cls_IntCurveSurface_IntersectionPoint.def_static("operator delete_", (void (*)(void *)) &IntCurveSurface_IntersectionPoint::operator delete, "None", py::arg("theAddress"));
// cls_IntCurveSurface_IntersectionPoint.def_static("operator new[]_", (void * (*)(size_t)) &IntCurveSurface_IntersectionPoint::operator new[], "None", py::arg("theSize"));
// cls_IntCurveSurface_IntersectionPoint.def_static("operator delete[]_", (void (*)(void *)) &IntCurveSurface_IntersectionPoint::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurveSurface_IntersectionPoint.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurveSurface_IntersectionPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurveSurface_IntersectionPoint.def_static("operator delete_", (void (*)(void *, void *)) &IntCurveSurface_IntersectionPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurveSurface_IntersectionPoint.def("SetValues", (void (IntCurveSurface_IntersectionPoint::*)(const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const IntCurveSurface_TransitionOnCurve)) &IntCurveSurface_IntersectionPoint::SetValues, "Set the fields of the current IntersectionPoint.", py::arg("P"), py::arg("USurf"), py::arg("VSurf"), py::arg("UCurv"), py::arg("TrCurv"));
cls_IntCurveSurface_IntersectionPoint.def("Values", [](IntCurveSurface_IntersectionPoint &self, gp_Pnt & P, Standard_Real & USurf, Standard_Real & VSurf, Standard_Real & UCurv, IntCurveSurface_TransitionOnCurve & TrCurv){ self.Values(P, USurf, VSurf, UCurv, TrCurv); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(USurf, VSurf, UCurv); }, "Get the fields of the current IntersectionPoint.", py::arg("P"), py::arg("USurf"), py::arg("VSurf"), py::arg("UCurv"), py::arg("TrCurv"));
cls_IntCurveSurface_IntersectionPoint.def("Pnt", (const gp_Pnt & (IntCurveSurface_IntersectionPoint::*)() const) &IntCurveSurface_IntersectionPoint::Pnt, "returns the geometric point.");
cls_IntCurveSurface_IntersectionPoint.def("U", (Standard_Real (IntCurveSurface_IntersectionPoint::*)() const) &IntCurveSurface_IntersectionPoint::U, "returns the U parameter on the surface.");
cls_IntCurveSurface_IntersectionPoint.def("V", (Standard_Real (IntCurveSurface_IntersectionPoint::*)() const) &IntCurveSurface_IntersectionPoint::V, "returns the V parameter on the surface.");
cls_IntCurveSurface_IntersectionPoint.def("W", (Standard_Real (IntCurveSurface_IntersectionPoint::*)() const) &IntCurveSurface_IntersectionPoint::W, "returns the parameter on the curve.");
cls_IntCurveSurface_IntersectionPoint.def("Transition", (IntCurveSurface_TransitionOnCurve (IntCurveSurface_IntersectionPoint::*)() const) &IntCurveSurface_IntersectionPoint::Transition, "returns the Transition of the point.");
cls_IntCurveSurface_IntersectionPoint.def("Dump", (void (IntCurveSurface_IntersectionPoint::*)() const) &IntCurveSurface_IntersectionPoint::Dump, "Dump all the fields.");

// Enums

}