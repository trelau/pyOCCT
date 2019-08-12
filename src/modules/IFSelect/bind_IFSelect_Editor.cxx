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
#include <Interface_TypedValue.hxx>
#include <IFSelect_EditValue.hxx>
#include <Message_Messenger.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_EditForm.hxx>
#include <TCollection_HAsciiString.hxx>
#include <IFSelect_ListEditor.hxx>
#include <TColStd_HSequenceOfHAsciiString.hxx>
#include <Interface_InterfaceModel.hxx>
#include <IFSelect_Editor.hxx>
#include <Standard_Type.hxx>
#include <NCollection_DataMap.hxx>
#include <TColStd_Array1OfTransient.hxx>
#include <TColStd_Array1OfAsciiString.hxx>
#include <TColStd_Array1OfInteger.hxx>

void bind_IFSelect_Editor(py::module &mod){

py::class_<IFSelect_Editor, opencascade::handle<IFSelect_Editor>, Standard_Transient> cls_IFSelect_Editor(mod, "IFSelect_Editor", "An Editor defines a set of values and a way to edit them, on an entity or on the model (e.g. on its header)");

// Fields

// Methods
cls_IFSelect_Editor.def("SetValue", [](IFSelect_Editor &self, const Standard_Integer a0, const opencascade::handle<Interface_TypedValue> & a1) -> void { return self.SetValue(a0, a1); });
cls_IFSelect_Editor.def("SetValue", [](IFSelect_Editor &self, const Standard_Integer a0, const opencascade::handle<Interface_TypedValue> & a1, const Standard_CString a2) -> void { return self.SetValue(a0, a1, a2); });
cls_IFSelect_Editor.def("SetValue", (void (IFSelect_Editor::*)(const Standard_Integer, const opencascade::handle<Interface_TypedValue> &, const Standard_CString, const IFSelect_EditValue)) &IFSelect_Editor::SetValue, "Sets a Typed Value for a given ident and short name, with an Edit Mode", py::arg("num"), py::arg("typval"), py::arg("shortname"), py::arg("accessmode"));
cls_IFSelect_Editor.def("SetList", [](IFSelect_Editor &self, const Standard_Integer a0) -> void { return self.SetList(a0); });
cls_IFSelect_Editor.def("SetList", (void (IFSelect_Editor::*)(const Standard_Integer, const Standard_Integer)) &IFSelect_Editor::SetList, "Sets a parameter to be a List max < 0 : not for a list (set when starting) max = 0 : list with no length limit (default for SetList) max > 0 : list limited to <max> items", py::arg("num"), py::arg("max"));
cls_IFSelect_Editor.def("NbValues", (Standard_Integer (IFSelect_Editor::*)() const) &IFSelect_Editor::NbValues, "Returns the count of Typed Values");
cls_IFSelect_Editor.def("TypedValue", (opencascade::handle<Interface_TypedValue> (IFSelect_Editor::*)(const Standard_Integer) const) &IFSelect_Editor::TypedValue, "Returns a Typed Value from its ident", py::arg("num"));
cls_IFSelect_Editor.def("IsList", (Standard_Boolean (IFSelect_Editor::*)(const Standard_Integer) const) &IFSelect_Editor::IsList, "Tells if a parameter is a list", py::arg("num"));
cls_IFSelect_Editor.def("MaxList", (Standard_Integer (IFSelect_Editor::*)(const Standard_Integer) const) &IFSelect_Editor::MaxList, "Returns max length allowed for a list = 0 means : list with no limit < 0 means : not a list", py::arg("num"));
cls_IFSelect_Editor.def("Name", [](IFSelect_Editor &self, const Standard_Integer a0) -> Standard_CString { return self.Name(a0); });
cls_IFSelect_Editor.def("Name", (Standard_CString (IFSelect_Editor::*)(const Standard_Integer, const Standard_Boolean) const) &IFSelect_Editor::Name, "Returns the name of a Value (complete or short) from its ident Short Name can be empty", py::arg("num"), py::arg("isshort"));
cls_IFSelect_Editor.def("EditMode", (IFSelect_EditValue (IFSelect_Editor::*)(const Standard_Integer) const) &IFSelect_Editor::EditMode, "Returns the edit mode of a Value", py::arg("num"));
cls_IFSelect_Editor.def("NameNumber", (Standard_Integer (IFSelect_Editor::*)(const Standard_CString) const) &IFSelect_Editor::NameNumber, "Returns the number (ident) of a Value, from its name, short or complete. If not found, returns 0", py::arg("name"));
cls_IFSelect_Editor.def("PrintNames", (void (IFSelect_Editor::*)(const opencascade::handle<Message_Messenger> &) const) &IFSelect_Editor::PrintNames, "None", py::arg("S"));
cls_IFSelect_Editor.def("PrintDefs", [](IFSelect_Editor &self, const opencascade::handle<Message_Messenger> & a0) -> void { return self.PrintDefs(a0); });
cls_IFSelect_Editor.def("PrintDefs", (void (IFSelect_Editor::*)(const opencascade::handle<Message_Messenger> &, const Standard_Boolean) const) &IFSelect_Editor::PrintDefs, "None", py::arg("S"), py::arg("labels"));
cls_IFSelect_Editor.def("MaxNameLength", (Standard_Integer (IFSelect_Editor::*)(const Standard_Integer) const) &IFSelect_Editor::MaxNameLength, "Returns the MaxLength of, according to what : <what> = -1 : length of short names <what> = 0 : length of complete names <what> = 1 : length of values labels", py::arg("what"));
cls_IFSelect_Editor.def("Label", (TCollection_AsciiString (IFSelect_Editor::*)() const) &IFSelect_Editor::Label, "Returns the specific label");
cls_IFSelect_Editor.def("Form", [](IFSelect_Editor &self, const Standard_Boolean a0) -> opencascade::handle<IFSelect_EditForm> { return self.Form(a0); });
cls_IFSelect_Editor.def("Form", (opencascade::handle<IFSelect_EditForm> (IFSelect_Editor::*)(const Standard_Boolean, const Standard_Boolean) const) &IFSelect_Editor::Form, "Builds and Returns an EditForm, empty (no data yet) Can be redefined to return a specific type of EditForm", py::arg("readonly"), py::arg("undoable"));
cls_IFSelect_Editor.def("Recognize", (Standard_Boolean (IFSelect_Editor::*)(const opencascade::handle<IFSelect_EditForm> &) const) &IFSelect_Editor::Recognize, "Tells if this Editor can work on this EditForm and its content (model, entity ?)", py::arg("form"));
cls_IFSelect_Editor.def("StringValue", (opencascade::handle<TCollection_HAsciiString> (IFSelect_Editor::*)(const opencascade::handle<IFSelect_EditForm> &, const Standard_Integer) const) &IFSelect_Editor::StringValue, "Returns the value of an EditForm, for a given item (if not a list. for a list, a Null String may be returned)", py::arg("form"), py::arg("num"));
cls_IFSelect_Editor.def("ListEditor", (opencascade::handle<IFSelect_ListEditor> (IFSelect_Editor::*)(const Standard_Integer) const) &IFSelect_Editor::ListEditor, "Returns a ListEditor for a parameter which is a List Default returns a basic ListEditor for a List, a Null Handle if <num> is not for a List. Can be redefined", py::arg("num"));
cls_IFSelect_Editor.def("ListValue", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (IFSelect_Editor::*)(const opencascade::handle<IFSelect_EditForm> &, const Standard_Integer) const) &IFSelect_Editor::ListValue, "Returns the value of an EditForm as a List, for a given item If not a list, a Null Handle should be returned Default returns a Null Handle, because many Editors have no list to edit. To be redefined as required", py::arg("form"), py::arg("num"));
cls_IFSelect_Editor.def("Load", (Standard_Boolean (IFSelect_Editor::*)(const opencascade::handle<IFSelect_EditForm> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_Editor::Load, "Loads original values from some data, to an EditForm Remark: <ent> may be Null, this means all <model> is concerned Also <model> may be Null, if no context applies for <ent> And both <ent> and <model> may be Null, for a full static editor", py::arg("form"), py::arg("ent"), py::arg("model"));
cls_IFSelect_Editor.def("Update", (Standard_Boolean (IFSelect_Editor::*)(const opencascade::handle<IFSelect_EditForm> &, const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean) const) &IFSelect_Editor::Update, "Updates the EditForm when a parameter is modified I.E. default does nothing, can be redefined, as follows : Returns True when done (even if does nothing), False in case of refuse (for instance, if the new value is not suitable) <num> is the rank of the parameter for the EDITOR itself <enforce> True means that protected parameters can be touched", py::arg("form"), py::arg("num"), py::arg("newval"), py::arg("enforce"));
cls_IFSelect_Editor.def("UpdateList", (Standard_Boolean (IFSelect_Editor::*)(const opencascade::handle<IFSelect_EditForm> &, const Standard_Integer, const opencascade::handle<TColStd_HSequenceOfHAsciiString> &, const Standard_Boolean) const) &IFSelect_Editor::UpdateList, "Acts as Update, but when the value is a list", py::arg("form"), py::arg("num"), py::arg("newlist"), py::arg("enforce"));
cls_IFSelect_Editor.def("Apply", (Standard_Boolean (IFSelect_Editor::*)(const opencascade::handle<IFSelect_EditForm> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_Editor::Apply, "Applies modified values of the EditForm with some data Remark: <ent> may be Null, this means all <model> is concerned Also <model> may be Null, if no context applies for <ent> And both <ent> and <model> may be Null, for a full static editor", py::arg("form"), py::arg("ent"), py::arg("model"));
cls_IFSelect_Editor.def_static("get_type_name_", (const char * (*)()) &IFSelect_Editor::get_type_name, "None");
cls_IFSelect_Editor.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_Editor::get_type_descriptor, "None");
cls_IFSelect_Editor.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_Editor::*)() const) &IFSelect_Editor::DynamicType, "None");

// Enums

}