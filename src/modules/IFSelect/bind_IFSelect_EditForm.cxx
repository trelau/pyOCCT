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
#include <IFSelect_Editor.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <Interface_InterfaceModel.hxx>
#include <IFSelect_ListEditor.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TColStd_HSequenceOfHAsciiString.hxx>
#include <Message_Messenger.hxx>
#include <IFSelect_EditForm.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_Array1OfTransient.hxx>

void bind_IFSelect_EditForm(py::module &mod){

py::class_<IFSelect_EditForm, opencascade::handle<IFSelect_EditForm>, Standard_Transient> cls_IFSelect_EditForm(mod, "IFSelect_EditForm", "An EditForm is the way to apply an Editor on an Entity or on the Model It gives read-only or read-write access, with or without undo");

// Constructors
cls_IFSelect_EditForm.def(py::init<const opencascade::handle<IFSelect_Editor> &, const Standard_Boolean, const Standard_Boolean>(), py::arg("editor"), py::arg("readonly"), py::arg("undoable"));
cls_IFSelect_EditForm.def(py::init<const opencascade::handle<IFSelect_Editor> &, const Standard_Boolean, const Standard_Boolean, const Standard_CString>(), py::arg("editor"), py::arg("readonly"), py::arg("undoable"), py::arg("label"));
cls_IFSelect_EditForm.def(py::init<const opencascade::handle<IFSelect_Editor> &, const TColStd_SequenceOfInteger &, const Standard_Boolean, const Standard_Boolean>(), py::arg("editor"), py::arg("nums"), py::arg("readonly"), py::arg("undoable"));
cls_IFSelect_EditForm.def(py::init<const opencascade::handle<IFSelect_Editor> &, const TColStd_SequenceOfInteger &, const Standard_Boolean, const Standard_Boolean, const Standard_CString>(), py::arg("editor"), py::arg("nums"), py::arg("readonly"), py::arg("undoable"), py::arg("label"));

// Fields

// Methods
cls_IFSelect_EditForm.def("EditKeepStatus", (Standard_Boolean & (IFSelect_EditForm::*)()) &IFSelect_EditForm::EditKeepStatus, "Returns and may change the keep status on modif It starts as False If it is True, Apply does not clear modification status and the EditForm can be loaded again, modified value remain and may be applied again Remark that ApplyData does not clear the modification status, a call to ClearEdit does");
cls_IFSelect_EditForm.def("Label", (Standard_CString (IFSelect_EditForm::*)() const) &IFSelect_EditForm::Label, "None");
cls_IFSelect_EditForm.def("IsLoaded", (Standard_Boolean (IFSelect_EditForm::*)() const) &IFSelect_EditForm::IsLoaded, "Tells if the EditForm is loaded now");
cls_IFSelect_EditForm.def("ClearData", (void (IFSelect_EditForm::*)()) &IFSelect_EditForm::ClearData, "None");
cls_IFSelect_EditForm.def("SetData", (void (IFSelect_EditForm::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &)) &IFSelect_EditForm::SetData, "None", py::arg("ent"), py::arg("model"));
cls_IFSelect_EditForm.def("SetEntity", (void (IFSelect_EditForm::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_EditForm::SetEntity, "None", py::arg("ent"));
cls_IFSelect_EditForm.def("SetModel", (void (IFSelect_EditForm::*)(const opencascade::handle<Interface_InterfaceModel> &)) &IFSelect_EditForm::SetModel, "None", py::arg("model"));
cls_IFSelect_EditForm.def("Entity", (opencascade::handle<Standard_Transient> (IFSelect_EditForm::*)() const) &IFSelect_EditForm::Entity, "None");
cls_IFSelect_EditForm.def("Model", (opencascade::handle<Interface_InterfaceModel> (IFSelect_EditForm::*)() const) &IFSelect_EditForm::Model, "None");
cls_IFSelect_EditForm.def("Editor", (opencascade::handle<IFSelect_Editor> (IFSelect_EditForm::*)() const) &IFSelect_EditForm::Editor, "None");
cls_IFSelect_EditForm.def("IsComplete", (Standard_Boolean (IFSelect_EditForm::*)() const) &IFSelect_EditForm::IsComplete, "Tells if an EditForm is complete or is an extract from Editor");
cls_IFSelect_EditForm.def("NbValues", (Standard_Integer (IFSelect_EditForm::*)(const Standard_Boolean) const) &IFSelect_EditForm::NbValues, "Returns the count of values <editable> True : count of editable values, i.e. For a complete EditForm, it is given by the Editor Else, it is the length of the extraction map <editable> False : all the values from the Editor", py::arg("editable"));
cls_IFSelect_EditForm.def("NumberFromRank", (Standard_Integer (IFSelect_EditForm::*)(const Standard_Integer) const) &IFSelect_EditForm::NumberFromRank, "Returns the Value Number in the Editor from a given Rank in the EditForm For a complete EditForm, both are equal Else, it is given by the extraction map Returns 0 if <rank> exceeds the count of editable values,", py::arg("rank"));
cls_IFSelect_EditForm.def("RankFromNumber", (Standard_Integer (IFSelect_EditForm::*)(const Standard_Integer) const) &IFSelect_EditForm::RankFromNumber, "Returns the Rank in the EditForm from a given Number of Value for the Editor For a complete EditForm, both are equal Else, it is given by the extraction map Returns 0 if <number> is not forecast to be edited, or is out of range", py::arg("number"));
cls_IFSelect_EditForm.def("NameNumber", (Standard_Integer (IFSelect_EditForm::*)(const Standard_CString) const) &IFSelect_EditForm::NameNumber, "Returns the Value Number in the Editor for a given Name i.e. the true ValueNumber which can be used in various methods of EditForm If it is not complete, for a recorded (in the Editor) but non-loaded name, returns negative value (- number)", py::arg("name"));
cls_IFSelect_EditForm.def("NameRank", (Standard_Integer (IFSelect_EditForm::*)(const Standard_CString) const) &IFSelect_EditForm::NameRank, "Returns the Rank of Value in the EditForm for a given Name i.e. if it is not complete, for a recorded (in the Editor) but non-loaded name, returns 0", py::arg("name"));
cls_IFSelect_EditForm.def("LoadDefault", (void (IFSelect_EditForm::*)()) &IFSelect_EditForm::LoadDefault, "For a read-write undoable EditForm, loads original values from defaults stored in the Editor");
cls_IFSelect_EditForm.def("LoadData", (Standard_Boolean (IFSelect_EditForm::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &)) &IFSelect_EditForm::LoadData, "Loads modifications to data Default uses Editor. Can be redefined Remark that <ent> and/or <model> may be null, according to the kind of Editor. Shortcuts are available for these cases, but they finally call LoadData (hence, just ignore non-used args)", py::arg("ent"), py::arg("model"));
cls_IFSelect_EditForm.def("LoadEntity", (Standard_Boolean (IFSelect_EditForm::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_EditForm::LoadEntity, "Shortcut for LoadData when <model> is not used", py::arg("ent"));
cls_IFSelect_EditForm.def("LoadModel", (Standard_Boolean (IFSelect_EditForm::*)(const opencascade::handle<Interface_InterfaceModel> &)) &IFSelect_EditForm::LoadModel, "Shortcut for LoadData when only the model is concerned", py::arg("model"));
cls_IFSelect_EditForm.def("LoadData", (Standard_Boolean (IFSelect_EditForm::*)()) &IFSelect_EditForm::LoadData, "Shortcut when both <ent> and <model> are not used (when the Editor works on fully static or global data)");
cls_IFSelect_EditForm.def("ListEditor", (opencascade::handle<IFSelect_ListEditor> (IFSelect_EditForm::*)(const Standard_Integer) const) &IFSelect_EditForm::ListEditor, "Returns a ListEditor to edit the parameter <num> of the EditForm, if it is a List The Editor created it (by ListEditor) then loads it (by ListValue) For a single parameter, returns a Null Handle ...", py::arg("num"));
cls_IFSelect_EditForm.def("LoadValue", (void (IFSelect_EditForm::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &)) &IFSelect_EditForm::LoadValue, "Loads an original value (single). Called by the Editor only", py::arg("num"), py::arg("val"));
cls_IFSelect_EditForm.def("LoadList", (void (IFSelect_EditForm::*)(const Standard_Integer, const opencascade::handle<TColStd_HSequenceOfHAsciiString> &)) &IFSelect_EditForm::LoadList, "Loads an original value as a list. Called by the Editor only", py::arg("num"), py::arg("list"));
cls_IFSelect_EditForm.def("OriginalValue", (opencascade::handle<TCollection_HAsciiString> (IFSelect_EditForm::*)(const Standard_Integer) const) &IFSelect_EditForm::OriginalValue, "From an edited value, returns its ... value (original one) Null means that this value is not defined <num> is for the EditForm, not the Editor It is for a single parameter. For a list, gives a Null Handle", py::arg("num"));
cls_IFSelect_EditForm.def("OriginalList", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (IFSelect_EditForm::*)(const Standard_Integer) const) &IFSelect_EditForm::OriginalList, "Returns an original value, as a list <num> is for the EditForm, not the Editor For a single parameter, gives a Null Handle", py::arg("num"));
cls_IFSelect_EditForm.def("EditedValue", (opencascade::handle<TCollection_HAsciiString> (IFSelect_EditForm::*)(const Standard_Integer) const) &IFSelect_EditForm::EditedValue, "Returns the Edited (i.e. Modified) Value (string for single) <num> reports to the EditForm If IsModified is False, returns OriginalValue Null with IsModified True : means that this value is not defined or has been removed It is for a single parameter. For a list, gives a Null Handle", py::arg("num"));
cls_IFSelect_EditForm.def("EditedList", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (IFSelect_EditForm::*)(const Standard_Integer) const) &IFSelect_EditForm::EditedList, "Returns the Edited Value as a list If IsModified is False, returns OriginalValue Null with IsModified True : means that this value is not defined or has been removed For a single parameter, gives a Null Handle", py::arg("num"));
cls_IFSelect_EditForm.def("IsModified", (Standard_Boolean (IFSelect_EditForm::*)(const Standard_Integer) const) &IFSelect_EditForm::IsModified, "Tells if a Value (of the EditForm) is modified (directly or through touching by Update)", py::arg("num"));
cls_IFSelect_EditForm.def("IsTouched", (Standard_Boolean (IFSelect_EditForm::*)(const Standard_Integer) const) &IFSelect_EditForm::IsTouched, "Tells if a Value (of the EditForm) has been touched, i.e. not modified directly but by the modification of another one (by method Update from the Editor)", py::arg("num"));
cls_IFSelect_EditForm.def("Modify", [](IFSelect_EditForm &self, const Standard_Integer a0, const opencascade::handle<TCollection_HAsciiString> & a1) -> Standard_Boolean { return self.Modify(a0, a1); });
cls_IFSelect_EditForm.def("Modify", (Standard_Boolean (IFSelect_EditForm::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean)) &IFSelect_EditForm::Modify, "Gives a new value for the item <num> of the EditForm, if it is a single parameter (for a list, just returns False) Null means to Remove it <enforce> True to overpass Protected or Computed Access Mode Calls the method Update from the Editor, which can touch other parameters (see NbTouched) Returns True if well recorded, False if this value is not allowed Warning : Does not apply immediately : will be applied by the method Apply", py::arg("num"), py::arg("newval"), py::arg("enforce"));
cls_IFSelect_EditForm.def("ModifyList", [](IFSelect_EditForm &self, const Standard_Integer a0, const opencascade::handle<IFSelect_ListEditor> & a1) -> Standard_Boolean { return self.ModifyList(a0, a1); });
cls_IFSelect_EditForm.def("ModifyList", (Standard_Boolean (IFSelect_EditForm::*)(const Standard_Integer, const opencascade::handle<IFSelect_ListEditor> &, const Standard_Boolean)) &IFSelect_EditForm::ModifyList, "Changes the value of an item of the EditForm, if it is a List (else, just returns False) The ListEditor contains the edited values of the list If no edition was recorded, just returns False Calls the method Update from the Editor, which can touch other parameters (see NbTouched) Returns True if well recorded, False if this value is not allowed Warning : Does not apply immediately : will be applied by the method Apply", py::arg("num"), py::arg("edited"), py::arg("enforce"));
cls_IFSelect_EditForm.def("ModifyListValue", [](IFSelect_EditForm &self, const Standard_Integer a0, const opencascade::handle<TColStd_HSequenceOfHAsciiString> & a1) -> Standard_Boolean { return self.ModifyListValue(a0, a1); });
cls_IFSelect_EditForm.def("ModifyListValue", (Standard_Boolean (IFSelect_EditForm::*)(const Standard_Integer, const opencascade::handle<TColStd_HSequenceOfHAsciiString> &, const Standard_Boolean)) &IFSelect_EditForm::ModifyListValue, "As ModifyList but the new value is given as such Creates a ListEditor, Loads it, then calls ModifyList", py::arg("num"), py::arg("list"), py::arg("enforce"));
cls_IFSelect_EditForm.def("Touch", (Standard_Boolean (IFSelect_EditForm::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &)) &IFSelect_EditForm::Touch, "Gives a new value computed by the Editor, if another parameter commands the value of <num> It is generally the case for a Computed Parameter for instance Increments the counter of touched parameters Warning : it gives no protection for ReadOnly etc... while it is the internal way of touching parameters Does not work (returns False) if <num> is for a list", py::arg("num"), py::arg("newval"));
cls_IFSelect_EditForm.def("TouchList", (Standard_Boolean (IFSelect_EditForm::*)(const Standard_Integer, const opencascade::handle<TColStd_HSequenceOfHAsciiString> &)) &IFSelect_EditForm::TouchList, "Acts as Touch but for a list Does not work (returns False) if <num> is for a single param", py::arg("num"), py::arg("newlist"));
// cls_IFSelect_EditForm.def("NbTouched", (Standard_Integer (IFSelect_EditForm::*)() const) &IFSelect_EditForm::NbTouched, "Returns the count of parameters touched by the last Modify (apart from the modified parameter itself) Normally it is zero");
cls_IFSelect_EditForm.def("ClearEdit", [](IFSelect_EditForm &self) -> void { return self.ClearEdit(); });
cls_IFSelect_EditForm.def("ClearEdit", (void (IFSelect_EditForm::*)(const Standard_Integer)) &IFSelect_EditForm::ClearEdit, "Clears modification status : by default all, or one by its numbers (in the Editor)", py::arg("num"));
cls_IFSelect_EditForm.def("PrintDefs", (void (IFSelect_EditForm::*)(const opencascade::handle<Message_Messenger> &) const) &IFSelect_EditForm::PrintDefs, "Prints Definitions, relative to the Editor", py::arg("S"));
cls_IFSelect_EditForm.def("PrintValues", [](IFSelect_EditForm &self, const opencascade::handle<Message_Messenger> & a0, const Standard_Integer a1, const Standard_Boolean a2) -> void { return self.PrintValues(a0, a1, a2); });
cls_IFSelect_EditForm.def("PrintValues", (void (IFSelect_EditForm::*)(const opencascade::handle<Message_Messenger> &, const Standard_Integer, const Standard_Boolean, const Standard_Boolean) const) &IFSelect_EditForm::PrintValues, "Prints Values, according to what and alsolist <names> True : prints Long Names; False : prints Short Names <what> < 0 : prints Original Values (+ flag Modified) <what> > 0 : prints Final Values (+flag Modified) <what> = 0 : prints Modified Values (Original + Edited) <alsolist> False (D) : lists are printed only as their count <alsolist> True : lists are printed for all their items", py::arg("S"), py::arg("what"), py::arg("names"), py::arg("alsolist"));
cls_IFSelect_EditForm.def("Apply", (Standard_Boolean (IFSelect_EditForm::*)()) &IFSelect_EditForm::Apply, "Applies modifications to own data Calls ApplyData then Clears Status according EditKeepStatus");
cls_IFSelect_EditForm.def("Recognize", (Standard_Boolean (IFSelect_EditForm::*)() const) &IFSelect_EditForm::Recognize, "Tells if this EditForm can work with its Editor and its actual Data (Entity and Model) Default uses Editor. Can be redefined");
cls_IFSelect_EditForm.def("ApplyData", (Standard_Boolean (IFSelect_EditForm::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &)) &IFSelect_EditForm::ApplyData, "Applies modifications to data Default uses Editor. Can be redefined", py::arg("ent"), py::arg("model"));
cls_IFSelect_EditForm.def("Undo", (Standard_Boolean (IFSelect_EditForm::*)()) &IFSelect_EditForm::Undo, "For an undoable EditForm, Applies ... origibal values ! and clears modified ones Can be run only once");
cls_IFSelect_EditForm.def_static("get_type_name_", (const char * (*)()) &IFSelect_EditForm::get_type_name, "None");
cls_IFSelect_EditForm.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_EditForm::get_type_descriptor, "None");
cls_IFSelect_EditForm.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_EditForm::*)() const) &IFSelect_EditForm::DynamicType, "None");

// Enums

}