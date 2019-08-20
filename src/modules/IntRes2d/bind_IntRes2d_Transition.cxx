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
#include <IntRes2d_Position.hxx>
#include <IntRes2d_TypeTrans.hxx>
#include <IntRes2d_Situation.hxx>
#include <IntRes2d_Transition.hxx>

void bind_IntRes2d_Transition(py::module &mod){

py::class_<IntRes2d_Transition, std::unique_ptr<IntRes2d_Transition>> cls_IntRes2d_Transition(mod, "IntRes2d_Transition", "Definition of the type of transition near an intersection point between two curves. The transition is either a 'true transition', which means that one of the curves goes inside or outside the area defined by the other curve near the intersection, or a 'touch transition' which means that the first curve does not cross the other one, or an 'undecided' transition, which means that the curves are superposed.");

// Constructors
cls_IntRes2d_Transition.def(py::init<>());
cls_IntRes2d_Transition.def(py::init<const Standard_Boolean, const IntRes2d_Position, const IntRes2d_TypeTrans>(), py::arg("Tangent"), py::arg("Pos"), py::arg("Type"));
cls_IntRes2d_Transition.def(py::init<const Standard_Boolean, const IntRes2d_Position, const IntRes2d_Situation, const Standard_Boolean>(), py::arg("Tangent"), py::arg("Pos"), py::arg("Situ"), py::arg("Oppos"));
cls_IntRes2d_Transition.def(py::init<const IntRes2d_Position>(), py::arg("Pos"));

// Fields

// Methods
// cls_IntRes2d_Transition.def_static("operator new_", (void * (*)(size_t)) &IntRes2d_Transition::operator new, "None", py::arg("theSize"));
// cls_IntRes2d_Transition.def_static("operator delete_", (void (*)(void *)) &IntRes2d_Transition::operator delete, "None", py::arg("theAddress"));
// cls_IntRes2d_Transition.def_static("operator new[]_", (void * (*)(size_t)) &IntRes2d_Transition::operator new[], "None", py::arg("theSize"));
// cls_IntRes2d_Transition.def_static("operator delete[]_", (void (*)(void *)) &IntRes2d_Transition::operator delete[], "None", py::arg("theAddress"));
// cls_IntRes2d_Transition.def_static("operator new_", (void * (*)(size_t, void *)) &IntRes2d_Transition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntRes2d_Transition.def_static("operator delete_", (void (*)(void *, void *)) &IntRes2d_Transition::operator delete, "None", py::arg(""), py::arg(""));
cls_IntRes2d_Transition.def("SetValue", (void (IntRes2d_Transition::*)(const Standard_Boolean, const IntRes2d_Position, const IntRes2d_TypeTrans)) &IntRes2d_Transition::SetValue, "Sets the values of an IN or OUT transition.", py::arg("Tangent"), py::arg("Pos"), py::arg("Type"));
cls_IntRes2d_Transition.def("SetValue", (void (IntRes2d_Transition::*)(const Standard_Boolean, const IntRes2d_Position, const IntRes2d_Situation, const Standard_Boolean)) &IntRes2d_Transition::SetValue, "Sets the values of a TOUCH transition.", py::arg("Tangent"), py::arg("Pos"), py::arg("Situ"), py::arg("Oppos"));
cls_IntRes2d_Transition.def("SetValue", (void (IntRes2d_Transition::*)(const IntRes2d_Position)) &IntRes2d_Transition::SetValue, "Sets the values of an UNDECIDED transition.", py::arg("Pos"));
cls_IntRes2d_Transition.def("SetPosition", (void (IntRes2d_Transition::*)(const IntRes2d_Position)) &IntRes2d_Transition::SetPosition, "Sets the value of the position.", py::arg("Pos"));
cls_IntRes2d_Transition.def("PositionOnCurve", (IntRes2d_Position (IntRes2d_Transition::*)() const) &IntRes2d_Transition::PositionOnCurve, "Indicates if the intersection is at the beginning (IntRes2d_Head), at the end (IntRes2d_End), or in the middle (IntRes2d_Middle) of the curve.");
cls_IntRes2d_Transition.def("TransitionType", (IntRes2d_TypeTrans (IntRes2d_Transition::*)() const) &IntRes2d_Transition::TransitionType, "Returns the type of transition at the intersection. It may be IN or OUT or TOUCH, or UNDECIDED if the two first derivatives are not enough to give the tangent to one of the two curves.");
cls_IntRes2d_Transition.def("IsTangent", (Standard_Boolean (IntRes2d_Transition::*)() const) &IntRes2d_Transition::IsTangent, "Returns TRUE when the 2 curves are tangent at the intersection point. Theexception DomainError is raised if the type of transition is UNDECIDED.");
cls_IntRes2d_Transition.def("Situation", (IntRes2d_Situation (IntRes2d_Transition::*)() const) &IntRes2d_Transition::Situation, "returns a significant value if TransitionType returns TOUCH. In this case, the function returns : INSIDE when the curve remains inside the other one, OUTSIDE when it remains outside the other one, UNKNOWN when the calculus, based on the second derivatives cannot give the result. If TransitionType returns IN or OUT or UNDECIDED, the exception DomainError is raised.");
cls_IntRes2d_Transition.def("IsOpposite", (Standard_Boolean (IntRes2d_Transition::*)() const) &IntRes2d_Transition::IsOpposite, "returns a significant value if TransitionType returns TOUCH. In this case, the function returns true when the 2 curves locally define two different parts of the space. If TransitionType returns IN or OUT or UNDECIDED, the exception DomainError is raised.");

// Enums

}