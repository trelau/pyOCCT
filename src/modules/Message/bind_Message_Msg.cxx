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
#include <Message_Msg.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TCollection_HExtendedString.hxx>
#include <TColStd_SequenceOfInteger.hxx>

void bind_Message_Msg(py::module &mod){

py::class_<Message_Msg, std::unique_ptr<Message_Msg, Deleter<Message_Msg>>> cls_Message_Msg(mod, "Message_Msg", "This class provides a tool for constructing the parametrized message basing on resources loaded by Message_MsgFile tool.");

// Constructors
cls_Message_Msg.def(py::init<>());
cls_Message_Msg.def(py::init<const Message_Msg &>(), py::arg("theMsg"));
cls_Message_Msg.def(py::init<const Standard_CString>(), py::arg("theKey"));
cls_Message_Msg.def(py::init<const TCollection_ExtendedString &>(), py::arg("theKey"));

// Fields

// Methods
// cls_Message_Msg.def_static("operator new_", (void * (*)(size_t)) &Message_Msg::operator new, "None", py::arg("theSize"));
// cls_Message_Msg.def_static("operator delete_", (void (*)(void *)) &Message_Msg::operator delete, "None", py::arg("theAddress"));
// cls_Message_Msg.def_static("operator new[]_", (void * (*)(size_t)) &Message_Msg::operator new[], "None", py::arg("theSize"));
// cls_Message_Msg.def_static("operator delete[]_", (void (*)(void *)) &Message_Msg::operator delete[], "None", py::arg("theAddress"));
// cls_Message_Msg.def_static("operator new_", (void * (*)(size_t, void *)) &Message_Msg::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Message_Msg.def_static("operator delete_", (void (*)(void *, void *)) &Message_Msg::operator delete, "None", py::arg(""), py::arg(""));
cls_Message_Msg.def("Set", (void (Message_Msg::*)(const Standard_CString)) &Message_Msg::Set, "Set a message body text -- can be used as alternative to using messages from resource file", py::arg("theMsg"));
cls_Message_Msg.def("Set", (void (Message_Msg::*)(const TCollection_ExtendedString &)) &Message_Msg::Set, "Set a message body text -- can be used as alternative to using messages from resource file", py::arg("theMsg"));
cls_Message_Msg.def("Arg", (Message_Msg & (Message_Msg::*)(const Standard_CString)) &Message_Msg::Arg, "Set a value for %..s conversion", py::arg("theString"));
cls_Message_Msg.def("bits_left", (Message_Msg & (Message_Msg::*)(const Standard_CString)) &Message_Msg::operator<<, py::is_operator(), "None", py::arg("theString"));
cls_Message_Msg.def("Arg", (Message_Msg & (Message_Msg::*)(const TCollection_AsciiString &)) &Message_Msg::Arg, "Set a value for %..s conversion", py::arg("theString"));
cls_Message_Msg.def("bits_left", (Message_Msg & (Message_Msg::*)(const TCollection_AsciiString &)) &Message_Msg::operator<<, py::is_operator(), "None", py::arg("theString"));
cls_Message_Msg.def("Arg", (Message_Msg & (Message_Msg::*)(const opencascade::handle<TCollection_HAsciiString> &)) &Message_Msg::Arg, "Set a value for %..s conversion", py::arg("theString"));
cls_Message_Msg.def("bits_left", (Message_Msg & (Message_Msg::*)(const opencascade::handle<TCollection_HAsciiString> &)) &Message_Msg::operator<<, py::is_operator(), "None", py::arg("theString"));
cls_Message_Msg.def("Arg", (Message_Msg & (Message_Msg::*)(const TCollection_ExtendedString &)) &Message_Msg::Arg, "Set a value for %..s conversion", py::arg("theString"));
cls_Message_Msg.def("bits_left", (Message_Msg & (Message_Msg::*)(const TCollection_ExtendedString &)) &Message_Msg::operator<<, py::is_operator(), "None", py::arg("theString"));
cls_Message_Msg.def("Arg", (Message_Msg & (Message_Msg::*)(const opencascade::handle<TCollection_HExtendedString> &)) &Message_Msg::Arg, "Set a value for %..s conversion", py::arg("theString"));
cls_Message_Msg.def("bits_left", (Message_Msg & (Message_Msg::*)(const opencascade::handle<TCollection_HExtendedString> &)) &Message_Msg::operator<<, py::is_operator(), "None", py::arg("theString"));
cls_Message_Msg.def("Arg", (Message_Msg & (Message_Msg::*)(const Standard_Integer)) &Message_Msg::Arg, "Set a value for %..d, %..i, %..o, %..u, %..x or %..X conversion", py::arg("theInt"));
cls_Message_Msg.def("bits_left", (Message_Msg & (Message_Msg::*)(const Standard_Integer)) &Message_Msg::operator<<, py::is_operator(), "None", py::arg("theInt"));
cls_Message_Msg.def("Arg", (Message_Msg & (Message_Msg::*)(const Standard_Real)) &Message_Msg::Arg, "Set a value for %..f, %..e, %..E, %..g or %..G conversion", py::arg("theReal"));
cls_Message_Msg.def("bits_left", (Message_Msg & (Message_Msg::*)(const Standard_Real)) &Message_Msg::operator<<, py::is_operator(), "None", py::arg("theReal"));
cls_Message_Msg.def("Original", (const TCollection_ExtendedString & (Message_Msg::*)() const) &Message_Msg::Original, "Returns the original message text");
cls_Message_Msg.def("Value", (const TCollection_ExtendedString & (Message_Msg::*)() const) &Message_Msg::Value, "Returns current state of the message text with parameters to the moment");
cls_Message_Msg.def("IsEdited", (Standard_Boolean (Message_Msg::*)() const) &Message_Msg::IsEdited, "Tells if Value differs from Original");
cls_Message_Msg.def("Get", (const TCollection_ExtendedString & (Message_Msg::*)()) &Message_Msg::Get, "Return the resulting message string with all parameters filled. If some parameters were not yet filled by calls to methods Arg (or <<), these parameters are filled by the word UNKNOWN");

// Enums

}