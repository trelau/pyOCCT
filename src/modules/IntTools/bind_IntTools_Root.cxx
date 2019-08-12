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
#include <TopAbs_State.hxx>
#include <IntTools_Root.hxx>

void bind_IntTools_Root(py::module &mod){

py::class_<IntTools_Root, std::unique_ptr<IntTools_Root, Deleter<IntTools_Root>>> cls_IntTools_Root(mod, "IntTools_Root", "The class is to describe the root of function of one variable for Edge/Edge and Edge/Surface algorithms.");

// Constructors
cls_IntTools_Root.def(py::init<>());
cls_IntTools_Root.def(py::init<const Standard_Real, const Standard_Integer>(), py::arg("aRoot"), py::arg("aType"));

// Fields

// Methods
// cls_IntTools_Root.def_static("operator new_", (void * (*)(size_t)) &IntTools_Root::operator new, "None", py::arg("theSize"));
// cls_IntTools_Root.def_static("operator delete_", (void (*)(void *)) &IntTools_Root::operator delete, "None", py::arg("theAddress"));
// cls_IntTools_Root.def_static("operator new[]_", (void * (*)(size_t)) &IntTools_Root::operator new[], "None", py::arg("theSize"));
// cls_IntTools_Root.def_static("operator delete[]_", (void (*)(void *)) &IntTools_Root::operator delete[], "None", py::arg("theAddress"));
// cls_IntTools_Root.def_static("operator new_", (void * (*)(size_t, void *)) &IntTools_Root::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntTools_Root.def_static("operator delete_", (void (*)(void *, void *)) &IntTools_Root::operator delete, "None", py::arg(""), py::arg(""));
cls_IntTools_Root.def("SetRoot", (void (IntTools_Root::*)(const Standard_Real)) &IntTools_Root::SetRoot, "Sets the Root's value", py::arg("aRoot"));
cls_IntTools_Root.def("SetType", (void (IntTools_Root::*)(const Standard_Integer)) &IntTools_Root::SetType, "Sets the Root's Type", py::arg("aType"));
cls_IntTools_Root.def("SetStateBefore", (void (IntTools_Root::*)(const TopAbs_State)) &IntTools_Root::SetStateBefore, "Set the value of the state before the root (at t=Root-dt)", py::arg("aState"));
cls_IntTools_Root.def("SetStateAfter", (void (IntTools_Root::*)(const TopAbs_State)) &IntTools_Root::SetStateAfter, "Set the value of the state after the root (at t=Root-dt)", py::arg("aState"));
cls_IntTools_Root.def("SetLayerHeight", (void (IntTools_Root::*)(const Standard_Real)) &IntTools_Root::SetLayerHeight, "Not used in Edge/Edge algorithm", py::arg("aHeight"));
cls_IntTools_Root.def("SetInterval", (void (IntTools_Root::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntTools_Root::SetInterval, "Sets the interval from which the Root was found [t1,t2] and the corresponding values of the function on the bounds f(t1), f(t2).", py::arg("t1"), py::arg("t2"), py::arg("f1"), py::arg("f2"));
cls_IntTools_Root.def("Root", (Standard_Real (IntTools_Root::*)() const) &IntTools_Root::Root, "Returns the Root value");
cls_IntTools_Root.def("Type", (Standard_Integer (IntTools_Root::*)() const) &IntTools_Root::Type, "Returns the type of the root =0 - Simple (was found by bisection method); =2 - Smart when f1=0, f2!=0 or vice versa (was found by Fibbonacci method); =1 - Pure (pure zero for all t [t1,t2] );");
cls_IntTools_Root.def("StateBefore", (TopAbs_State (IntTools_Root::*)() const) &IntTools_Root::StateBefore, "Returns the state before the root");
cls_IntTools_Root.def("StateAfter", (TopAbs_State (IntTools_Root::*)() const) &IntTools_Root::StateAfter, "Returns the state after the root");
cls_IntTools_Root.def("LayerHeight", (Standard_Real (IntTools_Root::*)() const) &IntTools_Root::LayerHeight, "Not used in Edge/Edge algorithm");
cls_IntTools_Root.def("IsValid", (Standard_Boolean (IntTools_Root::*)() const) &IntTools_Root::IsValid, "Returns the validity flag for the root, True if myStateBefore==TopAbs_OUT && myStateAfter==TopAbs_IN or myStateBefore==TopAbs_OUT && myStateAfter==TopAbs_ON or myStateBefore==TopAbs_ON && myStateAfter==TopAbs_OUT or myStateBefore==TopAbs_IN && myStateAfter==TopAbs_OUT . For other cases it returns False.");
cls_IntTools_Root.def("Interval", [](IntTools_Root &self, Standard_Real & t1, Standard_Real & t2, Standard_Real & f1, Standard_Real & f2){ self.Interval(t1, t2, f1, f2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(t1, t2, f1, f2); }, "Returns the values of interval from which the Root was found [t1,t2] and the corresponding values of the function on the bounds f(t1), f(t2).", py::arg("t1"), py::arg("t2"), py::arg("f1"), py::arg("f2"));

// Enums

}