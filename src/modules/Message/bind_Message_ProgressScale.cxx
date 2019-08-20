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
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Message_ProgressScale.hxx>

void bind_Message_ProgressScale(py::module &mod){

py::class_<Message_ProgressScale, std::unique_ptr<Message_ProgressScale>> cls_Message_ProgressScale(mod, "Message_ProgressScale", "Internal data structure for scale in ProgressIndicator");

// Constructors
cls_Message_ProgressScale.def(py::init<>());

// Fields

// Methods
// cls_Message_ProgressScale.def_static("operator new_", (void * (*)(size_t)) &Message_ProgressScale::operator new, "None", py::arg("theSize"));
// cls_Message_ProgressScale.def_static("operator delete_", (void (*)(void *)) &Message_ProgressScale::operator delete, "None", py::arg("theAddress"));
// cls_Message_ProgressScale.def_static("operator new[]_", (void * (*)(size_t)) &Message_ProgressScale::operator new[], "None", py::arg("theSize"));
// cls_Message_ProgressScale.def_static("operator delete[]_", (void (*)(void *)) &Message_ProgressScale::operator delete[], "None", py::arg("theAddress"));
// cls_Message_ProgressScale.def_static("operator new_", (void * (*)(size_t, void *)) &Message_ProgressScale::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Message_ProgressScale.def_static("operator delete_", (void (*)(void *, void *)) &Message_ProgressScale::operator delete, "None", py::arg(""), py::arg(""));
cls_Message_ProgressScale.def("SetName", (void (Message_ProgressScale::*)(const Standard_CString)) &Message_ProgressScale::SetName, "None", py::arg("theName"));
cls_Message_ProgressScale.def("SetName", (void (Message_ProgressScale::*)(const opencascade::handle<TCollection_HAsciiString> &)) &Message_ProgressScale::SetName, "Sets scale name", py::arg("theName"));
cls_Message_ProgressScale.def("GetName", (opencascade::handle<TCollection_HAsciiString> (Message_ProgressScale::*)() const) &Message_ProgressScale::GetName, "Gets scale name Name may be Null handle if not set");
cls_Message_ProgressScale.def("SetMin", (void (Message_ProgressScale::*)(const Standard_Real)) &Message_ProgressScale::SetMin, "Sets minimum value of scale", py::arg("theMin"));
cls_Message_ProgressScale.def("GetMin", (Standard_Real (Message_ProgressScale::*)() const) &Message_ProgressScale::GetMin, "Gets minimum value of scale");
cls_Message_ProgressScale.def("SetMax", (void (Message_ProgressScale::*)(const Standard_Real)) &Message_ProgressScale::SetMax, "Sets minimum value of scale", py::arg("theMax"));
cls_Message_ProgressScale.def("GetMax", (Standard_Real (Message_ProgressScale::*)() const) &Message_ProgressScale::GetMax, "Gets minimum value of scale");
cls_Message_ProgressScale.def("SetRange", (void (Message_ProgressScale::*)(const Standard_Real, const Standard_Real)) &Message_ProgressScale::SetRange, "Set both min and max", py::arg("min"), py::arg("max"));
cls_Message_ProgressScale.def("SetStep", (void (Message_ProgressScale::*)(const Standard_Real)) &Message_ProgressScale::SetStep, "Sets default step", py::arg("theStep"));
cls_Message_ProgressScale.def("GetStep", (Standard_Real (Message_ProgressScale::*)() const) &Message_ProgressScale::GetStep, "Gets default step");
cls_Message_ProgressScale.def("SetInfinite", [](Message_ProgressScale &self) -> void { return self.SetInfinite(); });
cls_Message_ProgressScale.def("SetInfinite", (void (Message_ProgressScale::*)(const Standard_Boolean)) &Message_ProgressScale::SetInfinite, "Sets flag for infinite scale", py::arg("theInfinite"));
cls_Message_ProgressScale.def("GetInfinite", (Standard_Boolean (Message_ProgressScale::*)() const) &Message_ProgressScale::GetInfinite, "Gets flag for infinite scale");
cls_Message_ProgressScale.def("SetScale", [](Message_ProgressScale &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.SetScale(a0, a1, a2); });
cls_Message_ProgressScale.def("SetScale", (void (Message_ProgressScale::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Message_ProgressScale::SetScale, "Set all scale parameters", py::arg("min"), py::arg("max"), py::arg("step"), py::arg("theInfinite"));
cls_Message_ProgressScale.def("SetSpan", (void (Message_ProgressScale::*)(const Standard_Real, const Standard_Real)) &Message_ProgressScale::SetSpan, "Defines span occupied by the scale on the basis scale", py::arg("first"), py::arg("last"));
cls_Message_ProgressScale.def("GetFirst", (Standard_Real (Message_ProgressScale::*)() const) &Message_ProgressScale::GetFirst, "None");
cls_Message_ProgressScale.def("GetLast", (Standard_Real (Message_ProgressScale::*)() const) &Message_ProgressScale::GetLast, "Return information on span occupied by the scale on the base scale");
cls_Message_ProgressScale.def("LocalToBase", (Standard_Real (Message_ProgressScale::*)(const Standard_Real) const) &Message_ProgressScale::LocalToBase, "None", py::arg("val"));
cls_Message_ProgressScale.def("BaseToLocal", (Standard_Real (Message_ProgressScale::*)(const Standard_Real) const) &Message_ProgressScale::BaseToLocal, "Convert value from this scale to base one and back", py::arg("val"));

// Enums

}