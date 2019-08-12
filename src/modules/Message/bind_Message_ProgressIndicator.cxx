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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Message_ProgressScale.hxx>
#include <Message_ProgressIndicator.hxx>
#include <Standard_Type.hxx>
#include <Message_SequenceOfProgressScale.hxx>

void bind_Message_ProgressIndicator(py::module &mod){

py::class_<Message_ProgressIndicator, opencascade::handle<Message_ProgressIndicator>, Standard_Transient> cls_Message_ProgressIndicator(mod, "Message_ProgressIndicator", "Defines abstract interface from program to the 'user'. This includes progress indication and user break mechanisms.");

// Fields

// Methods
cls_Message_ProgressIndicator.def("Reset", (void (Message_ProgressIndicator::*)()) &Message_ProgressIndicator::Reset, "Drops all scopes and sets scale from 0 to 100, step 1 This scale has name 'Step'");
cls_Message_ProgressIndicator.def("SetName", (void (Message_ProgressIndicator::*)(const Standard_CString)) &Message_ProgressIndicator::SetName, "None", py::arg("name"));
cls_Message_ProgressIndicator.def("SetName", (void (Message_ProgressIndicator::*)(const opencascade::handle<TCollection_HAsciiString> &)) &Message_ProgressIndicator::SetName, "Set (optional) name for scale", py::arg("name"));
cls_Message_ProgressIndicator.def("SetRange", (void (Message_ProgressIndicator::*)(const Standard_Real, const Standard_Real)) &Message_ProgressIndicator::SetRange, "Set range for current scale", py::arg("min"), py::arg("max"));
cls_Message_ProgressIndicator.def("SetStep", (void (Message_ProgressIndicator::*)(const Standard_Real)) &Message_ProgressIndicator::SetStep, "Set step for current scale", py::arg("step"));
cls_Message_ProgressIndicator.def("SetInfinite", [](Message_ProgressIndicator &self) -> void { return self.SetInfinite(); });
cls_Message_ProgressIndicator.def("SetInfinite", (void (Message_ProgressIndicator::*)(const Standard_Boolean)) &Message_ProgressIndicator::SetInfinite, "Set or drop infinite mode for the current scale", py::arg("isInf"));
cls_Message_ProgressIndicator.def("SetScale", [](Message_ProgressIndicator &self, const Standard_CString a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3) -> void { return self.SetScale(a0, a1, a2, a3); });
cls_Message_ProgressIndicator.def("SetScale", (void (Message_ProgressIndicator::*)(const Standard_CString, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Message_ProgressIndicator::SetScale, "None", py::arg("name"), py::arg("min"), py::arg("max"), py::arg("step"), py::arg("isInf"));
cls_Message_ProgressIndicator.def("SetScale", [](Message_ProgressIndicator &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.SetScale(a0, a1, a2); });
cls_Message_ProgressIndicator.def("SetScale", (void (Message_ProgressIndicator::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Message_ProgressIndicator::SetScale, "Set all parameters for current scale", py::arg("min"), py::arg("max"), py::arg("step"), py::arg("isInf"));
cls_Message_ProgressIndicator.def("GetScale", [](Message_ProgressIndicator &self, Standard_Real & min, Standard_Real & max, Standard_Real & step, Standard_Boolean & isInf){ self.GetScale(min, max, step, isInf); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Boolean &>(min, max, step, isInf); }, "Returns all parameters for current scale", py::arg("min"), py::arg("max"), py::arg("step"), py::arg("isInf"));
cls_Message_ProgressIndicator.def("SetValue", (void (Message_ProgressIndicator::*)(const Standard_Real)) &Message_ProgressIndicator::SetValue, "None", py::arg("val"));
cls_Message_ProgressIndicator.def("GetValue", (Standard_Real (Message_ProgressIndicator::*)() const) &Message_ProgressIndicator::GetValue, "Set and get progress value at current scale If the value to be set is more than currently set one, or out of range for the current scale, it is limited by that range");
cls_Message_ProgressIndicator.def("Increment", (void (Message_ProgressIndicator::*)()) &Message_ProgressIndicator::Increment, "None");
cls_Message_ProgressIndicator.def("Increment", (void (Message_ProgressIndicator::*)(const Standard_Real)) &Message_ProgressIndicator::Increment, "Increment the progress value by the default of specified step", py::arg("step"));
cls_Message_ProgressIndicator.def("NewScope", [](Message_ProgressIndicator &self) -> Standard_Boolean { return self.NewScope(); });
cls_Message_ProgressIndicator.def("NewScope", (Standard_Boolean (Message_ProgressIndicator::*)(const Standard_CString)) &Message_ProgressIndicator::NewScope, "None", py::arg("name"));
cls_Message_ProgressIndicator.def("NewScope", (Standard_Boolean (Message_ProgressIndicator::*)(const opencascade::handle<TCollection_HAsciiString> &)) &Message_ProgressIndicator::NewScope, "None", py::arg("name"));
cls_Message_ProgressIndicator.def("NewScope", [](Message_ProgressIndicator &self, const Standard_Real a0) -> Standard_Boolean { return self.NewScope(a0); });
cls_Message_ProgressIndicator.def("NewScope", (Standard_Boolean (Message_ProgressIndicator::*)(const Standard_Real, const Standard_CString)) &Message_ProgressIndicator::NewScope, "None", py::arg("span"), py::arg("name"));
cls_Message_ProgressIndicator.def("NewScope", (Standard_Boolean (Message_ProgressIndicator::*)(const Standard_Real, const opencascade::handle<TCollection_HAsciiString> &)) &Message_ProgressIndicator::NewScope, "Creates new scope on a part of a current scale from current position with span either equal to default step, or specified The scale for the new scope will have specified name and ranged from 0 to 100 with step 1 Returns False if something is wrong in arguments or in current position of progress indicator; scope is opened anyway", py::arg("span"), py::arg("name"));
cls_Message_ProgressIndicator.def("EndScope", (Standard_Boolean (Message_ProgressIndicator::*)()) &Message_ProgressIndicator::EndScope, "Close the current scope and thus return to previous scale Updates position to be at the end of the closing scope Returns False if no scope is opened");
cls_Message_ProgressIndicator.def("NextScope", [](Message_ProgressIndicator &self) -> Standard_Boolean { return self.NextScope(); });
cls_Message_ProgressIndicator.def("NextScope", (Standard_Boolean (Message_ProgressIndicator::*)(const Standard_CString)) &Message_ProgressIndicator::NextScope, "None", py::arg("name"));
cls_Message_ProgressIndicator.def("NextScope", [](Message_ProgressIndicator &self, const Standard_Real a0) -> Standard_Boolean { return self.NextScope(a0); });
cls_Message_ProgressIndicator.def("NextScope", (Standard_Boolean (Message_ProgressIndicator::*)(const Standard_Real, const Standard_CString)) &Message_ProgressIndicator::NextScope, "Optimized version of { return EndScope() && NewScope(); }", py::arg("span"), py::arg("name"));
cls_Message_ProgressIndicator.def("UserBreak", (Standard_Boolean (Message_ProgressIndicator::*)()) &Message_ProgressIndicator::UserBreak, "Should return True if user has send a break signal. Default implementation returns False.");
cls_Message_ProgressIndicator.def("Show", [](Message_ProgressIndicator &self) -> Standard_Boolean { return self.Show(); });
cls_Message_ProgressIndicator.def("Show", (Standard_Boolean (Message_ProgressIndicator::*)(const Standard_Boolean)) &Message_ProgressIndicator::Show, "Update presentation of the progress indicator Called when progress position is changed Flag force is intended for forcing update in case if it is optimized; all internal calls from ProgressIndicator are done with this flag equal to False", py::arg("force"));
cls_Message_ProgressIndicator.def("GetPosition", (Standard_Real (Message_ProgressIndicator::*)() const) &Message_ProgressIndicator::GetPosition, "Returns total progress position on the basic scale ranged from 0. to 1.");
cls_Message_ProgressIndicator.def("GetNbScopes", (Standard_Integer (Message_ProgressIndicator::*)() const) &Message_ProgressIndicator::GetNbScopes, "Returns current number of opened scopes This number is always >=1 as top-level scale is always present");
cls_Message_ProgressIndicator.def("GetScope", (const Message_ProgressScale & (Message_ProgressIndicator::*)(const Standard_Integer) const) &Message_ProgressIndicator::GetScope, "Returns data for scale of index-th scope The first scope is current one, the last is the top-level one", py::arg("index"));
cls_Message_ProgressIndicator.def_static("get_type_name_", (const char * (*)()) &Message_ProgressIndicator::get_type_name, "None");
cls_Message_ProgressIndicator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Message_ProgressIndicator::get_type_descriptor, "None");
cls_Message_ProgressIndicator.def("DynamicType", (const opencascade::handle<Standard_Type> & (Message_ProgressIndicator::*)() const) &Message_ProgressIndicator::DynamicType, "None");

// Enums

}