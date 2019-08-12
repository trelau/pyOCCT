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
#include <Standard_Handle.hxx>
#include <Interface_TypedValue.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_InterfaceModel.hxx>
#include <TColStd_HSequenceOfHAsciiString.hxx>
#include <TCollection_HAsciiString.hxx>
#include <IFSelect_ListEditor.hxx>
#include <Standard_Type.hxx>
#include <TColStd_HSequenceOfInteger.hxx>

void bind_IFSelect_ListEditor(py::module &mod){

py::class_<IFSelect_ListEditor, opencascade::handle<IFSelect_ListEditor>, Standard_Transient> cls_IFSelect_ListEditor(mod, "IFSelect_ListEditor", "A ListEditor is an auxiliary operator for Editor/EditForm I.E. it works on parameter values expressed as strings");

// Constructors
cls_IFSelect_ListEditor.def(py::init<>());
cls_IFSelect_ListEditor.def(py::init<const opencascade::handle<Interface_TypedValue> &>(), py::arg("def"));
cls_IFSelect_ListEditor.def(py::init<const opencascade::handle<Interface_TypedValue> &, const Standard_Integer>(), py::arg("def"), py::arg("max"));

// Fields

// Methods
cls_IFSelect_ListEditor.def("LoadModel", (void (IFSelect_ListEditor::*)(const opencascade::handle<Interface_InterfaceModel> &)) &IFSelect_ListEditor::LoadModel, "Loads a Model. It is used to check items of type Entity(Ident)", py::arg("model"));
cls_IFSelect_ListEditor.def("LoadValues", (void (IFSelect_ListEditor::*)(const opencascade::handle<TColStd_HSequenceOfHAsciiString> &)) &IFSelect_ListEditor::LoadValues, "Loads the original values for the list Remark : If its length is mor then MaxLength, editions remain allowed, except Add", py::arg("vals"));
cls_IFSelect_ListEditor.def("SetTouched", (void (IFSelect_ListEditor::*)()) &IFSelect_ListEditor::SetTouched, "Declares this ListEditor to have been touched (whatever action)");
cls_IFSelect_ListEditor.def("ClearEdit", (void (IFSelect_ListEditor::*)()) &IFSelect_ListEditor::ClearEdit, "Clears all editions already recorded");
cls_IFSelect_ListEditor.def("LoadEdited", (Standard_Boolean (IFSelect_ListEditor::*)(const opencascade::handle<TColStd_HSequenceOfHAsciiString> &)) &IFSelect_ListEditor::LoadEdited, "Loads a new list to replace the older one, in once ! By default (can be redefined) checks the length of the list and the value of each item according to the def Items are all recorded as Modified", py::arg("list"));
cls_IFSelect_ListEditor.def("SetValue", (Standard_Boolean (IFSelect_ListEditor::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &)) &IFSelect_ListEditor::SetValue, "Sets a new value for the item <num> (in edited list) <val> may be a Null Handle, then the value will be cleared but not removed Returns True when done. False if <num> is out of range or if <val> does not satisfy the definition", py::arg("num"), py::arg("val"));
cls_IFSelect_ListEditor.def("AddValue", [](IFSelect_ListEditor &self, const opencascade::handle<TCollection_HAsciiString> & a0) -> Standard_Boolean { return self.AddValue(a0); });
cls_IFSelect_ListEditor.def("AddValue", (Standard_Boolean (IFSelect_ListEditor::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer)) &IFSelect_ListEditor::AddValue, "Adds a new item. By default appends (at the end of the list) Can insert before a given rank <num>, if positive Returns True when done. False if MaxLength may be overpassed or if <val> does not satisfy the definition", py::arg("val"), py::arg("atnum"));
cls_IFSelect_ListEditor.def("Remove", [](IFSelect_ListEditor &self) -> Standard_Boolean { return self.Remove(); });
cls_IFSelect_ListEditor.def("Remove", [](IFSelect_ListEditor &self, const Standard_Integer a0) -> Standard_Boolean { return self.Remove(a0); });
cls_IFSelect_ListEditor.def("Remove", (Standard_Boolean (IFSelect_ListEditor::*)(const Standard_Integer, const Standard_Integer)) &IFSelect_ListEditor::Remove, "Removes items from the list By default removes one item. Else, count given by <howmany> Remove from rank <num> included. By default, from the end Returns True when done, False (and does not work) if case of out of range of if <howmany> is greater than current length", py::arg("num"), py::arg("howmany"));
cls_IFSelect_ListEditor.def("OriginalValues", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (IFSelect_ListEditor::*)() const) &IFSelect_ListEditor::OriginalValues, "Returns the value from which the edition started");
cls_IFSelect_ListEditor.def("EditedValues", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (IFSelect_ListEditor::*)() const) &IFSelect_ListEditor::EditedValues, "Returns the result of the edition");
cls_IFSelect_ListEditor.def("NbValues", [](IFSelect_ListEditor &self) -> Standard_Integer { return self.NbValues(); });
cls_IFSelect_ListEditor.def("NbValues", (Standard_Integer (IFSelect_ListEditor::*)(const Standard_Boolean) const) &IFSelect_ListEditor::NbValues, "Returns count of values, edited (D) or original", py::arg("edited"));
cls_IFSelect_ListEditor.def("Value", [](IFSelect_ListEditor &self, const Standard_Integer a0) -> opencascade::handle<TCollection_HAsciiString> { return self.Value(a0); });
cls_IFSelect_ListEditor.def("Value", (opencascade::handle<TCollection_HAsciiString> (IFSelect_ListEditor::*)(const Standard_Integer, const Standard_Boolean) const) &IFSelect_ListEditor::Value, "Returns a value given its rank. Edited (D) or Original A Null String means the value is cleared but not removed", py::arg("num"), py::arg("edited"));
cls_IFSelect_ListEditor.def("IsChanged", (Standard_Boolean (IFSelect_ListEditor::*)(const Standard_Integer) const) &IFSelect_ListEditor::IsChanged, "Tells if a value (in edited list) has been changed, i.e. either modified-value, or added", py::arg("num"));
cls_IFSelect_ListEditor.def("IsModified", (Standard_Boolean (IFSelect_ListEditor::*)(const Standard_Integer) const) &IFSelect_ListEditor::IsModified, "Tells if a value (in edited list) has been modified-value (not added)", py::arg("num"));
cls_IFSelect_ListEditor.def("IsAdded", (Standard_Boolean (IFSelect_ListEditor::*)(const Standard_Integer) const) &IFSelect_ListEditor::IsAdded, "Tells if a value (in edited list) has been added (new one)", py::arg("num"));
cls_IFSelect_ListEditor.def("IsTouched", (Standard_Boolean (IFSelect_ListEditor::*)() const) &IFSelect_ListEditor::IsTouched, "Tells if at least one edition (SetValue-AddValue-Remove) has been recorded");
cls_IFSelect_ListEditor.def_static("get_type_name_", (const char * (*)()) &IFSelect_ListEditor::get_type_name, "None");
cls_IFSelect_ListEditor.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_ListEditor::get_type_descriptor, "None");
cls_IFSelect_ListEditor.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_ListEditor::*)() const) &IFSelect_ListEditor::DynamicType, "None");

// Enums

}