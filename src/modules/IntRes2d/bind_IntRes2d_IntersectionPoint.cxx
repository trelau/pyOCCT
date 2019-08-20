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
#include <gp_Pnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <IntRes2d_Transition.hxx>
#include <IntRes2d_IntersectionPoint.hxx>

void bind_IntRes2d_IntersectionPoint(py::module &mod){

py::class_<IntRes2d_IntersectionPoint, std::unique_ptr<IntRes2d_IntersectionPoint>> cls_IntRes2d_IntersectionPoint(mod, "IntRes2d_IntersectionPoint", "Definition of an intersection point between two 2D curves.");

// Constructors
cls_IntRes2d_IntersectionPoint.def(py::init<>());
cls_IntRes2d_IntersectionPoint.def(py::init<const gp_Pnt2d &, const Standard_Real, const Standard_Real, const IntRes2d_Transition &, const IntRes2d_Transition &, const Standard_Boolean>(), py::arg("P"), py::arg("Uc1"), py::arg("Uc2"), py::arg("Trans1"), py::arg("Trans2"), py::arg("ReversedFlag"));

// Fields

// Methods
// cls_IntRes2d_IntersectionPoint.def_static("operator new_", (void * (*)(size_t)) &IntRes2d_IntersectionPoint::operator new, "None", py::arg("theSize"));
// cls_IntRes2d_IntersectionPoint.def_static("operator delete_", (void (*)(void *)) &IntRes2d_IntersectionPoint::operator delete, "None", py::arg("theAddress"));
// cls_IntRes2d_IntersectionPoint.def_static("operator new[]_", (void * (*)(size_t)) &IntRes2d_IntersectionPoint::operator new[], "None", py::arg("theSize"));
// cls_IntRes2d_IntersectionPoint.def_static("operator delete[]_", (void (*)(void *)) &IntRes2d_IntersectionPoint::operator delete[], "None", py::arg("theAddress"));
// cls_IntRes2d_IntersectionPoint.def_static("operator new_", (void * (*)(size_t, void *)) &IntRes2d_IntersectionPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntRes2d_IntersectionPoint.def_static("operator delete_", (void (*)(void *, void *)) &IntRes2d_IntersectionPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_IntRes2d_IntersectionPoint.def("SetValues", (void (IntRes2d_IntersectionPoint::*)(const gp_Pnt2d &, const Standard_Real, const Standard_Real, const IntRes2d_Transition &, const IntRes2d_Transition &, const Standard_Boolean)) &IntRes2d_IntersectionPoint::SetValues, "Sets the values for an existing intersection point. The meaning of the parameters are the same as for the Create.", py::arg("P"), py::arg("Uc1"), py::arg("Uc2"), py::arg("Trans1"), py::arg("Trans2"), py::arg("ReversedFlag"));
cls_IntRes2d_IntersectionPoint.def("Value", (const gp_Pnt2d & (IntRes2d_IntersectionPoint::*)() const) &IntRes2d_IntersectionPoint::Value, "Returns the value of the coordinates of the intersection point in the 2D space.");
cls_IntRes2d_IntersectionPoint.def("ParamOnFirst", (Standard_Real (IntRes2d_IntersectionPoint::*)() const) &IntRes2d_IntersectionPoint::ParamOnFirst, "Returns the parameter on the first curve.");
cls_IntRes2d_IntersectionPoint.def("ParamOnSecond", (Standard_Real (IntRes2d_IntersectionPoint::*)() const) &IntRes2d_IntersectionPoint::ParamOnSecond, "Returns the parameter on the second curve.");
cls_IntRes2d_IntersectionPoint.def("TransitionOfFirst", (const IntRes2d_Transition & (IntRes2d_IntersectionPoint::*)() const) &IntRes2d_IntersectionPoint::TransitionOfFirst, "Returns the transition of the 1st curve compared to the 2nd one.");
cls_IntRes2d_IntersectionPoint.def("TransitionOfSecond", (const IntRes2d_Transition & (IntRes2d_IntersectionPoint::*)() const) &IntRes2d_IntersectionPoint::TransitionOfSecond, "returns the transition of the 2nd curve compared to the 1st one.");

// Enums

}