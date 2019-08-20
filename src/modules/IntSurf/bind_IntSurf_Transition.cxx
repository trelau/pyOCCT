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
#include <IntSurf_TypeTrans.hxx>
#include <IntSurf_Situation.hxx>
#include <IntSurf_Transition.hxx>

void bind_IntSurf_Transition(py::module &mod){

py::class_<IntSurf_Transition, std::unique_ptr<IntSurf_Transition>> cls_IntSurf_Transition(mod, "IntSurf_Transition", "Definition of the transition at the intersection between an intersection line and a restriction curve on a surface.");

// Constructors
cls_IntSurf_Transition.def(py::init<>());
cls_IntSurf_Transition.def(py::init<const Standard_Boolean, const IntSurf_TypeTrans>(), py::arg("Tangent"), py::arg("Type"));
cls_IntSurf_Transition.def(py::init<const Standard_Boolean, const IntSurf_Situation, const Standard_Boolean>(), py::arg("Tangent"), py::arg("Situ"), py::arg("Oppos"));

// Fields

// Methods
// cls_IntSurf_Transition.def_static("operator new_", (void * (*)(size_t)) &IntSurf_Transition::operator new, "None", py::arg("theSize"));
// cls_IntSurf_Transition.def_static("operator delete_", (void (*)(void *)) &IntSurf_Transition::operator delete, "None", py::arg("theAddress"));
// cls_IntSurf_Transition.def_static("operator new[]_", (void * (*)(size_t)) &IntSurf_Transition::operator new[], "None", py::arg("theSize"));
// cls_IntSurf_Transition.def_static("operator delete[]_", (void (*)(void *)) &IntSurf_Transition::operator delete[], "None", py::arg("theAddress"));
// cls_IntSurf_Transition.def_static("operator new_", (void * (*)(size_t, void *)) &IntSurf_Transition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntSurf_Transition.def_static("operator delete_", (void (*)(void *, void *)) &IntSurf_Transition::operator delete, "None", py::arg(""), py::arg(""));
cls_IntSurf_Transition.def("SetValue", (void (IntSurf_Transition::*)(const Standard_Boolean, const IntSurf_TypeTrans)) &IntSurf_Transition::SetValue, "Set the values of an IN or OUT transition.", py::arg("Tangent"), py::arg("Type"));
cls_IntSurf_Transition.def("SetValue", (void (IntSurf_Transition::*)(const Standard_Boolean, const IntSurf_Situation, const Standard_Boolean)) &IntSurf_Transition::SetValue, "Set the values of a TOUCH transition.", py::arg("Tangent"), py::arg("Situ"), py::arg("Oppos"));
cls_IntSurf_Transition.def("SetValue", (void (IntSurf_Transition::*)()) &IntSurf_Transition::SetValue, "Set the values of an UNDECIDED transition.");
cls_IntSurf_Transition.def("TransitionType", (IntSurf_TypeTrans (IntSurf_Transition::*)() const) &IntSurf_Transition::TransitionType, "Returns the type of Transition (in/out/touch/undecided) for the arc given by value. This the transition of the intersection line compared to the Arc of restriction, i-e when the function returns INSIDE for example, it means that the intersection line goes inside the part of plane limited by the arc of restriction.");
cls_IntSurf_Transition.def("IsTangent", (Standard_Boolean (IntSurf_Transition::*)() const) &IntSurf_Transition::IsTangent, "Returns TRUE if the point is tangent to the arc given by Value. An exception is raised if TransitionType returns UNDECIDED.");
cls_IntSurf_Transition.def("Situation", (IntSurf_Situation (IntSurf_Transition::*)() const) &IntSurf_Transition::Situation, "Returns a significant value if TransitionType returns TOUCH. In this case, the function returns : INSIDE when the intersection line remains inside the Arc, OUTSIDE when it remains outside the Arc, UNKNOWN when the calsulus cannot give results. If TransitionType returns IN, or OUT, or UNDECIDED, a exception is raised.");
cls_IntSurf_Transition.def("IsOpposite", (Standard_Boolean (IntSurf_Transition::*)() const) &IntSurf_Transition::IsOpposite, "returns a significant value if TransitionType returns TOUCH. In this case, the function returns true when the 2 curves locally define two different parts of the space. If TransitionType returns IN or OUT or UNDECIDED, an exception is raised.");

// Enums

}