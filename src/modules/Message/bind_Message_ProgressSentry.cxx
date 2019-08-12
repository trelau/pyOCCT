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
#include <Message_ProgressIndicator.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Message_ProgressSentry.hxx>

void bind_Message_ProgressSentry(py::module &mod){

py::class_<Message_ProgressSentry, std::unique_ptr<Message_ProgressSentry, Deleter<Message_ProgressSentry>>> cls_Message_ProgressSentry(mod, "Message_ProgressSentry", "This class is a tool allowing to manage opening/closing scopes in the ProgressIndicator in convenient and safe way.");

// Constructors
cls_Message_ProgressSentry.def(py::init<const opencascade::handle<Message_ProgressIndicator> &, const Standard_CString, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("PI"), py::arg("name"), py::arg("min"), py::arg("max"), py::arg("step"));
cls_Message_ProgressSentry.def(py::init<const opencascade::handle<Message_ProgressIndicator> &, const Standard_CString, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("PI"), py::arg("name"), py::arg("min"), py::arg("max"), py::arg("step"), py::arg("isInf"));
cls_Message_ProgressSentry.def(py::init<const opencascade::handle<Message_ProgressIndicator> &, const Standard_CString, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Real>(), py::arg("PI"), py::arg("name"), py::arg("min"), py::arg("max"), py::arg("step"), py::arg("isInf"), py::arg("newScopeSpan"));
cls_Message_ProgressSentry.def(py::init<const opencascade::handle<Message_ProgressIndicator> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("PI"), py::arg("name"), py::arg("min"), py::arg("max"), py::arg("step"));
cls_Message_ProgressSentry.def(py::init<const opencascade::handle<Message_ProgressIndicator> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("PI"), py::arg("name"), py::arg("min"), py::arg("max"), py::arg("step"), py::arg("isInf"));
cls_Message_ProgressSentry.def(py::init<const opencascade::handle<Message_ProgressIndicator> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Real>(), py::arg("PI"), py::arg("name"), py::arg("min"), py::arg("max"), py::arg("step"), py::arg("isInf"), py::arg("newScopeSpan"));

// Fields

// Methods
// cls_Message_ProgressSentry.def_static("operator new_", (void * (*)(size_t)) &Message_ProgressSentry::operator new, "None", py::arg("theSize"));
// cls_Message_ProgressSentry.def_static("operator delete_", (void (*)(void *)) &Message_ProgressSentry::operator delete, "None", py::arg("theAddress"));
// cls_Message_ProgressSentry.def_static("operator new[]_", (void * (*)(size_t)) &Message_ProgressSentry::operator new[], "None", py::arg("theSize"));
// cls_Message_ProgressSentry.def_static("operator delete[]_", (void (*)(void *)) &Message_ProgressSentry::operator delete[], "None", py::arg("theAddress"));
// cls_Message_ProgressSentry.def_static("operator new_", (void * (*)(size_t, void *)) &Message_ProgressSentry::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Message_ProgressSentry.def_static("operator delete_", (void (*)(void *, void *)) &Message_ProgressSentry::operator delete, "None", py::arg(""), py::arg(""));
cls_Message_ProgressSentry.def("Relieve", (void (Message_ProgressSentry::*)()) &Message_ProgressSentry::Relieve, "Moves progress indicator to the end of the current scale and relieves sentry from its duty. Methods other than Show() will do nothing after this one is called.");
cls_Message_ProgressSentry.def("Next", [](Message_ProgressSentry &self) -> void { return self.Next(); });
cls_Message_ProgressSentry.def("Next", (void (Message_ProgressSentry::*)(const Standard_CString) const) &Message_ProgressSentry::Next, "None", py::arg("name"));
cls_Message_ProgressSentry.def("Next", [](Message_ProgressSentry &self, const Standard_Real a0) -> void { return self.Next(a0); });
cls_Message_ProgressSentry.def("Next", (void (Message_ProgressSentry::*)(const Standard_Real, const Standard_CString) const) &Message_ProgressSentry::Next, "None", py::arg("span"), py::arg("name"));
cls_Message_ProgressSentry.def("Next", (void (Message_ProgressSentry::*)(const Standard_Real, const opencascade::handle<TCollection_HAsciiString> &) const) &Message_ProgressSentry::Next, "Closes current scope and opens next one with either specified or default span", py::arg("span"), py::arg("name"));
cls_Message_ProgressSentry.def("More", (Standard_Boolean (Message_ProgressSentry::*)() const) &Message_ProgressSentry::More, "Returns False if ProgressIndicator signals UserBreak");
cls_Message_ProgressSentry.def("Show", (void (Message_ProgressSentry::*)() const) &Message_ProgressSentry::Show, "Forces update of progress indicator display");

// Enums

}