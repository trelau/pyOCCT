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
#include <IFSelect_EditValue.hxx>
#include <IFSelect_ReturnStatus.hxx>
#include <IFSelect_PrintCount.hxx>
#include <IFSelect_PrintFail.hxx>
#include <IFSelect_RemainMode.hxx>
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Interface_TypedValue.hxx>
#include <Message_Messenger.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_EditForm.hxx>
#include <TCollection_HAsciiString.hxx>
#include <IFSelect_ListEditor.hxx>
#include <TColStd_HSequenceOfHAsciiString.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Standard_Std.hxx>
#include <IFSelect_Editor.hxx>
#include <Standard_Type.hxx>
#include <NCollection_DataMap.hxx>
#include <TColStd_Array1OfTransient.hxx>
#include <TColStd_Array1OfAsciiString.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <Standard.hxx>
#include <IFSelect_WorkSession.hxx>
#include <IFSelect_Signature.hxx>
#include <IFSelect_SignMultiple.hxx>
#include <IFSelect_SignType.hxx>
#include <IFSelect_SignCategory.hxx>
#include <IFSelect_SignValidity.hxx>
#include <IFSelect_SignAncestor.hxx>
#include <IFSelect_ShareOut.hxx>
#include <IFSelect_AppliedModifiers.hxx>
#include <IFSelect_ShareOutResult.hxx>
#include <IFSelect_PacketList.hxx>
#include <IFSelect_Dispatch.hxx>
#include <IFSelect_DispGlobal.hxx>
#include <IFSelect_DispPerOne.hxx>
#include <IFSelect_DispPerCount.hxx>
#include <IFSelect_DispPerSignature.hxx>
#include <IFSelect_DispPerFiles.hxx>
#include <IFSelect_SelectionIterator.hxx>
#include <IFSelect_Selection.hxx>
#include <IFSelect_SelectBase.hxx>
#include <IFSelect_SelectModelRoots.hxx>
#include <IFSelect_SelectModelEntities.hxx>
#include <IFSelect_SelectEntityNumber.hxx>
#include <IFSelect_SelectPointed.hxx>
#include <IFSelect_SelectCombine.hxx>
#include <IFSelect_SelectUnion.hxx>
#include <IFSelect_SelectIntersection.hxx>
#include <IFSelect_SelectControl.hxx>
#include <IFSelect_SelectDiff.hxx>
#include <IFSelect_SelectDeduct.hxx>
#include <IFSelect_SelectShared.hxx>
#include <IFSelect_SelectSharing.hxx>
#include <IFSelect_SelectAnyList.hxx>
#include <IFSelect_SelectInList.hxx>
#include <IFSelect_SelectSuite.hxx>
#include <IFSelect_SelectExtract.hxx>
#include <IFSelect_SelectUnknownEntities.hxx>
#include <IFSelect_SelectErrorEntities.hxx>
#include <IFSelect_SelectIncorrectEntities.hxx>
#include <IFSelect_SelectRoots.hxx>
#include <IFSelect_SelectRootComps.hxx>
#include <IFSelect_SelectRange.hxx>
#include <IFSelect_SelectAnyType.hxx>
#include <IFSelect_SelectType.hxx>
#include <IFSelect_SelectSignature.hxx>
#include <IFSelect_SelectFlag.hxx>
#include <IFSelect_SelectSent.hxx>
#include <IFSelect_SelectExplore.hxx>
#include <IFSelect_SelectSignedShared.hxx>
#include <IFSelect_SelectSignedSharing.hxx>
#include <IFSelect_IntParam.hxx>
#include <IFSelect_SignatureList.hxx>
#include <IFSelect_CheckCounter.hxx>
#include <IFSelect_SignCounter.hxx>
#include <IFSelect_GraphCounter.hxx>
#include <IFSelect_ParamEditor.hxx>
#include <IFSelect_ContextModif.hxx>
#include <IFSelect_ContextWrite.hxx>
#include <IFSelect_Transformer.hxx>
#include <IFSelect_TransformStandard.hxx>
#include <IFSelect_ModelCopier.hxx>
#include <IFSelect_GeneralModifier.hxx>
#include <IFSelect_Modifier.hxx>
#include <IFSelect_ModifReorder.hxx>
#include <IFSelect_ModifEditForm.hxx>
#include <IFSelect_WorkLibrary.hxx>
#include <IFSelect_SessionFile.hxx>
#include <IFSelect_SessionDumper.hxx>
#include <IFSelect_BasicDumper.hxx>
#include <IFSelect_Activator.hxx>
#include <IFSelect_SessionPilot.hxx>
#include <IFSelect_Act.hxx>
#include <IFSelect_Functions.hxx>
#include <IFSelect.hxx>
#include <TColStd_HSequenceOfAsciiString.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <IFSelect_ActFunc.hxx>
#include <NCollection_Sequence.hxx>
#include <IFSelect_SequenceOfGeneralModifier.hxx>
#include <TColStd_HSequenceOfInteger.hxx>
#include <Interface_IntList.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <MoniTool_SignText.hxx>
#include <Interface_CheckIterator.hxx>
#include <Interface_Graph.hxx>
#include <Interface_CopyTool.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_Protocol.hxx>
#include <Interface_CopyControl.hxx>
#include <Interface_Check.hxx>
#include <Interface_HGraph.hxx>
#include <IFGraph_SubPartsIterator.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <TColStd_MapOfTransient.hxx>
#include <IFSelect_TSeqOfSelection.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <IFSelect_HSeqOfSelection.hxx>
#include <IFSelect_SequenceOfInterfaceModel.hxx>
#include <IFSelect_SequenceOfAppliedModifiers.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TColStd_SequenceOfTransient.hxx>
#include <IFSelect_TSeqOfDispatch.hxx>
#include <Interface_SignType.hxx>
#include <Interface_HArray1OfHAsciiString.hxx>
#include <NCollection_Vector.hxx>
#include <TColStd_IndexedDataMapOfTransientTransient.hxx>
#include <Interface_GTool.hxx>
#include <bind_NCollection_Sequence.hxx>

PYBIND11_MODULE(IFSelect, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Interface");
py::module::import("OCCT.Message");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.MoniTool");
py::module::import("OCCT.IFGraph");

// ENUM: IFSELECT_EDITVALUE
py::enum_<IFSelect_EditValue>(mod, "IFSelect_EditValue", "Controls access on Values by an Editor EditOptional : normal access, in addition may be removed Editable : normal access, must be present EditProtected : access must be validated EditComputed : why write it ? it will be recomputed EditRead : no way to write it, only for read EditDynamic : not a field, only to be displayed")
	.value("IFSelect_Optional", IFSelect_EditValue::IFSelect_Optional)
	.value("IFSelect_Editable", IFSelect_EditValue::IFSelect_Editable)
	.value("IFSelect_EditProtected", IFSelect_EditValue::IFSelect_EditProtected)
	.value("IFSelect_EditComputed", IFSelect_EditValue::IFSelect_EditComputed)
	.value("IFSelect_EditRead", IFSelect_EditValue::IFSelect_EditRead)
	.value("IFSelect_EditDynamic", IFSelect_EditValue::IFSelect_EditDynamic)
	.export_values();


// ENUM: IFSELECT_RETURNSTATUS
py::enum_<IFSelect_ReturnStatus>(mod, "IFSelect_ReturnStatus", "Qualifies an execution status : RetVoid : normal execution which created nothing, or no data to process RetDone : normal execution with a result RetError : error in command or input data, no execution RetFail : execution was run and has failed RetStop : indicates end or stop (such as Raise)")
	.value("IFSelect_RetVoid", IFSelect_ReturnStatus::IFSelect_RetVoid)
	.value("IFSelect_RetDone", IFSelect_ReturnStatus::IFSelect_RetDone)
	.value("IFSelect_RetError", IFSelect_ReturnStatus::IFSelect_RetError)
	.value("IFSelect_RetFail", IFSelect_ReturnStatus::IFSelect_RetFail)
	.value("IFSelect_RetStop", IFSelect_ReturnStatus::IFSelect_RetStop)
	.export_values();


// ENUM: IFSELECT_PRINTCOUNT
py::enum_<IFSelect_PrintCount>(mod, "IFSelect_PrintCount", "Lets you choose the manner in which you want to analyze an IGES or STEP file. Your analysis can be either message-oriented or entity-oriented. The specific values are as follows: - ItemsByEntity is a sequential list of all messages per entity of the defined type - CountByItem is the number of entities of the defined type, with their rank number per message - ShortByItem is the number of entities of the defined type, with their types per message; displays the rank numbers of the first five entities of the defined type per message - ListByItem is the number of entities of the defined type per message and the numbers of the entities - EntitiesByItem is the number of entities of the defined type, with their types, rank numbers and Directory Entry numbers per message - GeneralInfo is general information on transfer such as: - number of entities - number of roots - number of resulting Open CASCADE shapes - number of warnings and failures - CountSummary summary statistics for counters and signatures - ResultCount information that contains the number of roots in the IGES file and the number of resulting Open CASCADE shapes. - Mapping of the IGES root entities to the resulting Open CASCADE shape (including type and form of the IGES entity and type of the resulting shape).")
	.value("IFSelect_ItemsByEntity", IFSelect_PrintCount::IFSelect_ItemsByEntity)
	.value("IFSelect_CountByItem", IFSelect_PrintCount::IFSelect_CountByItem)
	.value("IFSelect_ShortByItem", IFSelect_PrintCount::IFSelect_ShortByItem)
	.value("IFSelect_ListByItem", IFSelect_PrintCount::IFSelect_ListByItem)
	.value("IFSelect_EntitiesByItem", IFSelect_PrintCount::IFSelect_EntitiesByItem)
	.value("IFSelect_CountSummary", IFSelect_PrintCount::IFSelect_CountSummary)
	.value("IFSelect_GeneralInfo", IFSelect_PrintCount::IFSelect_GeneralInfo)
	.value("IFSelect_Mapping", IFSelect_PrintCount::IFSelect_Mapping)
	.value("IFSelect_ResultCount", IFSelect_PrintCount::IFSelect_ResultCount)
	.export_values();


// ENUM: IFSELECT_PRINTFAIL
py::enum_<IFSelect_PrintFail>(mod, "IFSelect_PrintFail", "Indicates whether there will be information on warnings as well as on failures. The terms of this enumeration have the following semantics: - IFSelect_FailOnly gives information on failures only - IFSelect_FailAndWarn gives information on both failures and warnings. used to pilot PrintCheckList")
	.value("IFSelect_FailOnly", IFSelect_PrintFail::IFSelect_FailOnly)
	.value("IFSelect_FailAndWarn", IFSelect_PrintFail::IFSelect_FailAndWarn)
	.export_values();


// ENUM: IFSELECT_REMAINMODE
py::enum_<IFSelect_RemainMode>(mod, "IFSelect_RemainMode", "None")
	.value("IFSelect_RemainForget", IFSelect_RemainMode::IFSelect_RemainForget)
	.value("IFSelect_RemainCompute", IFSelect_RemainMode::IFSelect_RemainCompute)
	.value("IFSelect_RemainDisplay", IFSelect_RemainMode::IFSelect_RemainDisplay)
	.value("IFSelect_RemainUndo", IFSelect_RemainMode::IFSelect_RemainUndo)
	.export_values();


// CLASS: IFSELECT_EDITOR
py::class_<IFSelect_Editor, opencascade::handle<IFSelect_Editor>, Standard_Transient> cls_IFSelect_Editor(mod, "IFSelect_Editor", "An Editor defines a set of values and a way to edit them, on an entity or on the model (e.g. on its header)");

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

// CLASS: IFSELECT
py::class_<IFSelect> cls_IFSelect(mod, "IFSelect", "Gives tools to manage Selecting a group of Entities processed by an Interface, for instance to divide up an original Model (from a File) to several smaller ones They use description of an Interface Model as a graph");

// Constructors
cls_IFSelect.def(py::init<>());

// Methods
// cls_IFSelect.def_static("operator new_", (void * (*)(size_t)) &IFSelect::operator new, "None", py::arg("theSize"));
// cls_IFSelect.def_static("operator delete_", (void (*)(void *)) &IFSelect::operator delete, "None", py::arg("theAddress"));
// cls_IFSelect.def_static("operator new[]_", (void * (*)(size_t)) &IFSelect::operator new[], "None", py::arg("theSize"));
// cls_IFSelect.def_static("operator delete[]_", (void (*)(void *)) &IFSelect::operator delete[], "None", py::arg("theAddress"));
// cls_IFSelect.def_static("operator new_", (void * (*)(size_t, void *)) &IFSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IFSelect.def_static("operator delete_", (void (*)(void *, void *)) &IFSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_IFSelect.def_static("SaveSession_", (Standard_Boolean (*)(const opencascade::handle<IFSelect_WorkSession> &, const Standard_CString)) &IFSelect::SaveSession, "Saves the state of a WorkSession from IFSelect, by using a SessionFile from IFSelect. Returns True if Done, False in case of Error on Writing. <file> gives the name of the File to be produced (this avoids to export the class SessionFile).", py::arg("WS"), py::arg("file"));
cls_IFSelect.def_static("RestoreSession_", (Standard_Boolean (*)(const opencascade::handle<IFSelect_WorkSession> &, const Standard_CString)) &IFSelect::RestoreSession, "Restore the state of a WorkSession from IFSelect, by using a SessionFile from IFSelect. Returns True if Done, False in case of Error on Writing. <file> gives the name of the File to be used (this avoids to export the class SessionFile).", py::arg("WS"), py::arg("file"));

// CLASS: IFSELECT_ACTIVATOR
py::class_<IFSelect_Activator, opencascade::handle<IFSelect_Activator>, Standard_Transient> cls_IFSelect_Activator(mod, "IFSelect_Activator", "Defines the general frame for working with a SessionPilot. Each Activator treats a set of Commands. Commands are given as alphanumeric strings. They can be of two main forms : - classic, to list, evaluate, enrich the session (by itself) : no specific remark, its complete execution must be described - creation of a new item : instead of creatinf it plus adding it to the session (which is a classic way), it is possible to create it and make it recorded by the SessionPilot : then, the Pilot will add it to the session; this way allows the Pilot to manage itself named items");

// Methods
cls_IFSelect_Activator.def_static("Adding_", (void (*)(const opencascade::handle<IFSelect_Activator> &, const Standard_Integer, const Standard_CString, const Standard_Integer)) &IFSelect_Activator::Adding, "Records, in a Dictionary available for all the Activators, the command title an Activator can process, attached with its number, proper for this Activator <mode> allows to distinguish various execution modes 0: default mode; 1 : for xset", py::arg("actor"), py::arg("number"), py::arg("command"), py::arg("mode"));
cls_IFSelect_Activator.def("Add", (void (IFSelect_Activator::*)(const Standard_Integer, const Standard_CString) const) &IFSelect_Activator::Add, "Allows a self-definition by an Activator of the Commands it processes, call the class method Adding (mode 0)", py::arg("number"), py::arg("command"));
cls_IFSelect_Activator.def("AddSet", (void (IFSelect_Activator::*)(const Standard_Integer, const Standard_CString) const) &IFSelect_Activator::AddSet, "Same as Add but specifies that this command is candidate for xset (creation of items, xset : named items; mode 1)", py::arg("number"), py::arg("command"));
cls_IFSelect_Activator.def_static("Remove_", (void (*)(const Standard_CString)) &IFSelect_Activator::Remove, "Removes a Command, if it is recorded (else, does nothing)", py::arg("command"));
cls_IFSelect_Activator.def_static("Select_", [](const Standard_CString command, Standard_Integer & number, opencascade::handle<IFSelect_Activator> & actor){ Standard_Boolean rv = IFSelect_Activator::Select(command, number, actor); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, number); }, "Selects, for a Command given by its title, an actor with its command number. Returns True if found, False else", py::arg("command"), py::arg("number"), py::arg("actor"));
cls_IFSelect_Activator.def_static("Mode_", (Standard_Integer (*)(const Standard_CString)) &IFSelect_Activator::Mode, "Returns mode recorded for a command. -1 if not found", py::arg("command"));
cls_IFSelect_Activator.def_static("Commands_", []() -> opencascade::handle<TColStd_HSequenceOfAsciiString> { return IFSelect_Activator::Commands(); });
cls_IFSelect_Activator.def_static("Commands_", [](const Standard_Integer a0) -> opencascade::handle<TColStd_HSequenceOfAsciiString> { return IFSelect_Activator::Commands(a0); });
cls_IFSelect_Activator.def_static("Commands_", (opencascade::handle<TColStd_HSequenceOfAsciiString> (*)(const Standard_Integer, const Standard_CString)) &IFSelect_Activator::Commands, "Returns, for a root of command title, the list of possible commands. <mode> : -1 (D) for all commands if <commands> is empty -1 + command : about a Group , >= 0 see Adding By default, it returns the whole list of known commands.", py::arg("mode"), py::arg("command"));
cls_IFSelect_Activator.def("Do", (IFSelect_ReturnStatus (IFSelect_Activator::*)(const Standard_Integer, const opencascade::handle<IFSelect_SessionPilot> &)) &IFSelect_Activator::Do, "Tries to execute a Command Line. <number> is the number of the command for this Activator. It Must forecast to record the result of the execution, for need of Undo-Redo Must Returns : 0 for a void command (not to be recorded), 1 if execution OK, -1 if command incorrect, -2 if error on execution", py::arg("number"), py::arg("pilot"));
cls_IFSelect_Activator.def("Help", (Standard_CString (IFSelect_Activator::*)(const Standard_Integer) const) &IFSelect_Activator::Help, "Sends a short help message for a given command identified by it number for this Activator (must take one line max)", py::arg("number"));
cls_IFSelect_Activator.def("Group", (Standard_CString (IFSelect_Activator::*)() const) &IFSelect_Activator::Group, "None");
cls_IFSelect_Activator.def("File", (Standard_CString (IFSelect_Activator::*)() const) &IFSelect_Activator::File, "None");
cls_IFSelect_Activator.def("SetForGroup", [](IFSelect_Activator &self, const Standard_CString a0) -> void { return self.SetForGroup(a0); });
cls_IFSelect_Activator.def("SetForGroup", (void (IFSelect_Activator::*)(const Standard_CString, const Standard_CString)) &IFSelect_Activator::SetForGroup, "Group and SetGroup define a 'Group of commands' which correspond to an Activator. Default is 'XSTEP' Also a file may be attached", py::arg("group"), py::arg("file"));
cls_IFSelect_Activator.def_static("get_type_name_", (const char * (*)()) &IFSelect_Activator::get_type_name, "None");
cls_IFSelect_Activator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_Activator::get_type_descriptor, "None");
cls_IFSelect_Activator.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_Activator::*)() const) &IFSelect_Activator::DynamicType, "None");

// CLASS: IFSELECT_SESSIONPILOT
py::class_<IFSelect_SessionPilot, opencascade::handle<IFSelect_SessionPilot>, IFSelect_Activator> cls_IFSelect_SessionPilot(mod, "IFSelect_SessionPilot", "A SessionPilot is intended to make easier the use of a WorkSession. It receives commands, under alphanumeric form, then calls a library of Activators to interprete and run them.");

// Constructors
cls_IFSelect_SessionPilot.def(py::init<>());
cls_IFSelect_SessionPilot.def(py::init<const Standard_CString>(), py::arg("prompt"));

// Methods
cls_IFSelect_SessionPilot.def("Session", (opencascade::handle<IFSelect_WorkSession> (IFSelect_SessionPilot::*)() const) &IFSelect_SessionPilot::Session, "Returns the WorkSession which is worked on");
cls_IFSelect_SessionPilot.def("Library", (opencascade::handle<IFSelect_WorkLibrary> (IFSelect_SessionPilot::*)() const) &IFSelect_SessionPilot::Library, "Returns the WorKlibrary (Null if not set). WorkLibrary is used to Read and Write Files, according to the Norm");
cls_IFSelect_SessionPilot.def("RecordMode", (Standard_Boolean (IFSelect_SessionPilot::*)() const) &IFSelect_SessionPilot::RecordMode, "Returns the Record Mode for Commands. Default is False.");
cls_IFSelect_SessionPilot.def("SetSession", (void (IFSelect_SessionPilot::*)(const opencascade::handle<IFSelect_WorkSession> &)) &IFSelect_SessionPilot::SetSession, "Sets a WorkSession to be worked on", py::arg("WS"));
cls_IFSelect_SessionPilot.def("SetLibrary", (void (IFSelect_SessionPilot::*)(const opencascade::handle<IFSelect_WorkLibrary> &)) &IFSelect_SessionPilot::SetLibrary, "Sets a WorkLibrary", py::arg("WL"));
cls_IFSelect_SessionPilot.def("SetRecordMode", (void (IFSelect_SessionPilot::*)(const Standard_Boolean)) &IFSelect_SessionPilot::SetRecordMode, "Changes the RecordMode.", py::arg("mode"));
cls_IFSelect_SessionPilot.def("SetCommandLine", (void (IFSelect_SessionPilot::*)(const TCollection_AsciiString &)) &IFSelect_SessionPilot::SetCommandLine, "Sets the value of the Command Line to be interpreted Also prepares the interpretation (splitting by blanks)", py::arg("command"));
cls_IFSelect_SessionPilot.def("CommandLine", (const TCollection_AsciiString & (IFSelect_SessionPilot::*)() const) &IFSelect_SessionPilot::CommandLine, "Returns the Command Line to be interpreted");
cls_IFSelect_SessionPilot.def("CommandPart", [](IFSelect_SessionPilot &self) -> Standard_CString { return self.CommandPart(); });
cls_IFSelect_SessionPilot.def("CommandPart", (Standard_CString (IFSelect_SessionPilot::*)(const Standard_Integer) const) &IFSelect_SessionPilot::CommandPart, "Returns the part of the command line which begins at argument <numarg> between 0 and NbWords-1 (by default, all the line) Empty string if out of range", py::arg("numarg"));
cls_IFSelect_SessionPilot.def("NbWords", (Standard_Integer (IFSelect_SessionPilot::*)() const) &IFSelect_SessionPilot::NbWords, "Returns the count of words of the Command Line, separated by blanks : 0 if empty, one if a command without args, else it gives the count of args minus one. Warning : limited to 10 (command title + 9 args)");
cls_IFSelect_SessionPilot.def("Word", (const TCollection_AsciiString & (IFSelect_SessionPilot::*)(const Standard_Integer) const) &IFSelect_SessionPilot::Word, "Returns a word given its rank in the Command Line. Begins at 0 which is the Command Title, 1 is the 1st arg., etc...", py::arg("num"));
cls_IFSelect_SessionPilot.def("Arg", (Standard_CString (IFSelect_SessionPilot::*)(const Standard_Integer) const) &IFSelect_SessionPilot::Arg, "Returns a word given its rank, as a CString. As for Word, begins at 0 (the command name), etc...", py::arg("num"));
cls_IFSelect_SessionPilot.def("RemoveWord", (Standard_Boolean (IFSelect_SessionPilot::*)(const Standard_Integer)) &IFSelect_SessionPilot::RemoveWord, "Removes a word given its rank. Returns True if Done, False if <num> is out of range", py::arg("num"));
cls_IFSelect_SessionPilot.def("NbCommands", (Standard_Integer (IFSelect_SessionPilot::*)() const) &IFSelect_SessionPilot::NbCommands, "Returns the count of recorded Commands");
cls_IFSelect_SessionPilot.def("Command", (const TCollection_AsciiString & (IFSelect_SessionPilot::*)(const Standard_Integer) const) &IFSelect_SessionPilot::Command, "Returns a recorded Command, given its rank (from 1)", py::arg("num"));
cls_IFSelect_SessionPilot.def("RecordItem", (IFSelect_ReturnStatus (IFSelect_SessionPilot::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_SessionPilot::RecordItem, "Allows to associate a Transient Value with the last execution as a partial result Returns RetDone if item is not Null, RetFail if item is Null Remark : it is nullified for each Perform", py::arg("item"));
cls_IFSelect_SessionPilot.def("RecordedItem", (opencascade::handle<Standard_Transient> (IFSelect_SessionPilot::*)() const) &IFSelect_SessionPilot::RecordedItem, "Returns the Transient Object which was recorded with the current Line Command. If none was, returns a Null Handle");
cls_IFSelect_SessionPilot.def("Clear", (void (IFSelect_SessionPilot::*)()) &IFSelect_SessionPilot::Clear, "Clears the recorded informations (commands, objects)");
cls_IFSelect_SessionPilot.def("ReadScript", [](IFSelect_SessionPilot &self) -> IFSelect_ReturnStatus { return self.ReadScript(); });
cls_IFSelect_SessionPilot.def("ReadScript", (IFSelect_ReturnStatus (IFSelect_SessionPilot::*)(const Standard_CString)) &IFSelect_SessionPilot::ReadScript, "Reads commands from a Script File, named <file>. By default (file = ''), reads from standard input with a prompt Else (reading from a file), the read commands are displayed onto standard output. Allows nested reads. Reading is stopped either by command x or exit, or by reaching end of file Return Value follows the rules of Do : RetEnd for normal end, RetFail if script could not be opened", py::arg("file"));
cls_IFSelect_SessionPilot.def("Perform", (IFSelect_ReturnStatus (IFSelect_SessionPilot::*)()) &IFSelect_SessionPilot::Perform, "Executes the Command, itself (for built-in commands, which have priority) or by using the list of Activators. The value returned is : RetVoid if nothing done (void command) RetDone if execution OK, RetEnd if END OF SESSION, RetError if command unknown or incorrect, RetFail if error on execution If execution is OK and RecordMode is set, this Command Line is recorded to the list (see below).");
cls_IFSelect_SessionPilot.def("ExecuteAlias", (IFSelect_ReturnStatus (IFSelect_SessionPilot::*)(const TCollection_AsciiString &)) &IFSelect_SessionPilot::ExecuteAlias, "Executes the Commands, except that the command name (word 0) is aliased. The rest of the command line is unchanged If <alias> is empty, Executes with no change", py::arg("aliasname"));
cls_IFSelect_SessionPilot.def("Execute", (IFSelect_ReturnStatus (IFSelect_SessionPilot::*)(const TCollection_AsciiString &)) &IFSelect_SessionPilot::Execute, "Sets the Command then tries to execute it. Return value : same as for Perform", py::arg("command"));
cls_IFSelect_SessionPilot.def("ExecuteCounter", [](IFSelect_SessionPilot &self, const opencascade::handle<IFSelect_SignCounter> & a0, const Standard_Integer a1) -> IFSelect_ReturnStatus { return self.ExecuteCounter(a0, a1); });
cls_IFSelect_SessionPilot.def("ExecuteCounter", (IFSelect_ReturnStatus (IFSelect_SessionPilot::*)(const opencascade::handle<IFSelect_SignCounter> &, const Standard_Integer, const IFSelect_PrintCount)) &IFSelect_SessionPilot::ExecuteCounter, "Executes a Counter in a general way If <numword> is greater than count of command words, it counts all the model. Else it considers the word <numword> as the identifier of a Selection <mode> gives the mode of printing results, default is CountByItem", py::arg("counter"), py::arg("numword"), py::arg("mode"));
cls_IFSelect_SessionPilot.def("Number", (Standard_Integer (IFSelect_SessionPilot::*)(const Standard_CString) const) &IFSelect_SessionPilot::Number, "Interprets a string value as an entity number : if it gives an integer, returns its value else, considers it as ENtityLabel (preferably case sensitive) in case of failure, returns 0", py::arg("val"));
cls_IFSelect_SessionPilot.def("Do", (IFSelect_ReturnStatus (IFSelect_SessionPilot::*)(const Standard_Integer, const opencascade::handle<IFSelect_SessionPilot> &)) &IFSelect_SessionPilot::Do, "Processes specific commands, which are : x or exit for end of session ? or help for help messages xcommand to control command lines (Record Mode, List, Clear, File Output ...) xsource to execute a command file (no nesting allowed), in case of error, source is stopped and keyword recovers xstep is a simple prefix (useful in a wider environment, to avoid conflicts on command names) xset control commands which create items with names", py::arg("number"), py::arg("session"));
cls_IFSelect_SessionPilot.def("Help", (Standard_CString (IFSelect_SessionPilot::*)(const Standard_Integer) const) &IFSelect_SessionPilot::Help, "Help for specific commands (apart from general command help)", py::arg("number"));
cls_IFSelect_SessionPilot.def_static("get_type_name_", (const char * (*)()) &IFSelect_SessionPilot::get_type_name, "None");
cls_IFSelect_SessionPilot.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SessionPilot::get_type_descriptor, "None");
cls_IFSelect_SessionPilot.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SessionPilot::*)() const) &IFSelect_SessionPilot::DynamicType, "None");

// TYPEDEF: IFSELECT_ACTFUNC

// CLASS: IFSELECT_ACT
py::class_<IFSelect_Act, opencascade::handle<IFSelect_Act>, IFSelect_Activator> cls_IFSelect_Act(mod, "IFSelect_Act", "Act gives a simple way to define and add functions to be ran from a SessionPilot, as follows :");

// Constructors
cls_IFSelect_Act.def(py::init<const Standard_CString, const Standard_CString, const IFSelect_ActFunc>(), py::arg("name"), py::arg("help"), py::arg("func"));

// Methods
cls_IFSelect_Act.def("Do", (IFSelect_ReturnStatus (IFSelect_Act::*)(const Standard_Integer, const opencascade::handle<IFSelect_SessionPilot> &)) &IFSelect_Act::Do, "Execution of Command Line. remark that <number> is senseless because each Act brings one and only one function", py::arg("number"), py::arg("pilot"));
cls_IFSelect_Act.def("Help", (Standard_CString (IFSelect_Act::*)(const Standard_Integer) const) &IFSelect_Act::Help, "Short Help for commands : returns the help given to create", py::arg("number"));
cls_IFSelect_Act.def_static("SetGroup_", [](const Standard_CString a0) -> void { return IFSelect_Act::SetGroup(a0); });
cls_IFSelect_Act.def_static("SetGroup_", (void (*)(const Standard_CString, const Standard_CString)) &IFSelect_Act::SetGroup, "Changes the default group name for the following Acts group empty means to come back to default from Activator Also a file name can be precised (to query by getsource)", py::arg("group"), py::arg("file"));
cls_IFSelect_Act.def_static("AddFunc_", (void (*)(const Standard_CString, const Standard_CString, const IFSelect_ActFunc)) &IFSelect_Act::AddFunc, "Adds a function with its name and help : creates an Act then records it as normal function", py::arg("name"), py::arg("help"), py::arg("func"));
cls_IFSelect_Act.def_static("AddFSet_", (void (*)(const Standard_CString, const Standard_CString, const IFSelect_ActFunc)) &IFSelect_Act::AddFSet, "Adds a function with its name and help : creates an Act then records it as function for XSET (i.e. to create control item)", py::arg("name"), py::arg("help"), py::arg("func"));
cls_IFSelect_Act.def_static("get_type_name_", (const char * (*)()) &IFSelect_Act::get_type_name, "None");
cls_IFSelect_Act.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_Act::get_type_descriptor, "None");
cls_IFSelect_Act.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_Act::*)() const) &IFSelect_Act::DynamicType, "None");

// CLASS: IFSELECT_GENERALMODIFIER
py::class_<IFSelect_GeneralModifier, opencascade::handle<IFSelect_GeneralModifier>, Standard_Transient> cls_IFSelect_GeneralModifier(mod, "IFSelect_GeneralModifier", "This class gives a frame for Actions which modify the effect of a Dispatch, i.e. : By Selections and Dispatches, an original Model can be splitted into one or more 'target' Models : these Models contain Entities copied from the original one (that is, a part of it). Basically, these dispatched Entities are copied as identical to their original counterparts. Also the copied Models reproduce the Header of the original one.");

// Methods
cls_IFSelect_GeneralModifier.def("MayChangeGraph", (Standard_Boolean (IFSelect_GeneralModifier::*)() const) &IFSelect_GeneralModifier::MayChangeGraph, "Returns True if this modifier may change the graph of dependences (aknowledged at creation time)");
cls_IFSelect_GeneralModifier.def("SetDispatch", (void (IFSelect_GeneralModifier::*)(const opencascade::handle<IFSelect_Dispatch> &)) &IFSelect_GeneralModifier::SetDispatch, "Attaches to a Dispatch. If <disp> is Null, Resets it (to apply the Modifier on every Dispatch)", py::arg("disp"));
cls_IFSelect_GeneralModifier.def("Dispatch", (opencascade::handle<IFSelect_Dispatch> (IFSelect_GeneralModifier::*)() const) &IFSelect_GeneralModifier::Dispatch, "Returns the Dispatch to be matched, Null if not set");
cls_IFSelect_GeneralModifier.def("Applies", (Standard_Boolean (IFSelect_GeneralModifier::*)(const opencascade::handle<IFSelect_Dispatch> &) const) &IFSelect_GeneralModifier::Applies, "Returns True if a Model obtained from the Dispatch <disp> is to be treated (apart from the Selection criterium) If Dispatch(me) is Null, returns True. Else, checks <disp>", py::arg("disp"));
cls_IFSelect_GeneralModifier.def("SetSelection", (void (IFSelect_GeneralModifier::*)(const opencascade::handle<IFSelect_Selection> &)) &IFSelect_GeneralModifier::SetSelection, "Sets a Selection : a Model is treated if it contains one or more Entities designated by the Selection", py::arg("sel"));
cls_IFSelect_GeneralModifier.def("ResetSelection", (void (IFSelect_GeneralModifier::*)()) &IFSelect_GeneralModifier::ResetSelection, "Resets the Selection : this criterium is not longer active");
cls_IFSelect_GeneralModifier.def("HasSelection", (Standard_Boolean (IFSelect_GeneralModifier::*)() const) &IFSelect_GeneralModifier::HasSelection, "Returns True if a Selection is set as an additionnal criterium");
cls_IFSelect_GeneralModifier.def("Selection", (opencascade::handle<IFSelect_Selection> (IFSelect_GeneralModifier::*)() const) &IFSelect_GeneralModifier::Selection, "Returns the Selection, or a Null Handle if not set");
cls_IFSelect_GeneralModifier.def("Label", (TCollection_AsciiString (IFSelect_GeneralModifier::*)() const) &IFSelect_GeneralModifier::Label, "Returns a short text which defines the operation performed");
cls_IFSelect_GeneralModifier.def_static("get_type_name_", (const char * (*)()) &IFSelect_GeneralModifier::get_type_name, "None");
cls_IFSelect_GeneralModifier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_GeneralModifier::get_type_descriptor, "None");
cls_IFSelect_GeneralModifier.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_GeneralModifier::*)() const) &IFSelect_GeneralModifier::DynamicType, "None");

// TYPEDEF: IFSELECT_SEQUENCEOFGENERALMODIFIER
bind_NCollection_Sequence<opencascade::handle<IFSelect_GeneralModifier> >(mod, "IFSelect_SequenceOfGeneralModifier", py::module_local(false));

// CLASS: IFSELECT_APPLIEDMODIFIERS
py::class_<IFSelect_AppliedModifiers, opencascade::handle<IFSelect_AppliedModifiers>, Standard_Transient> cls_IFSelect_AppliedModifiers(mod, "IFSelect_AppliedModifiers", "This class allows to memorize and access to the modifiers which are to be applied to a file. To each modifier, is bound a list of integers (optionnal) : if this list is absent, the modifier applies to all the file. Else, it applies to the entities designated by these numbers in the produced file.");

// Constructors
cls_IFSelect_AppliedModifiers.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("nbmax"), py::arg("nbent"));

// Methods
cls_IFSelect_AppliedModifiers.def("AddModif", (Standard_Boolean (IFSelect_AppliedModifiers::*)(const opencascade::handle<IFSelect_GeneralModifier> &)) &IFSelect_AppliedModifiers::AddModif, "Records a modifier. By default, it is to apply on all a produced file. Further calls to AddNum will restrict this. Returns True if done, False if too many modifiers are already recorded", py::arg("modif"));
cls_IFSelect_AppliedModifiers.def("AddNum", (Standard_Boolean (IFSelect_AppliedModifiers::*)(const Standard_Integer)) &IFSelect_AppliedModifiers::AddNum, "Adds a number of entity of the output file to be applied on. If a sequence of AddNum is called after AddModif, this Modifier will be applied on the list of designated entities. Else, it will be applied on all the file Returns True if done, False if no modifier has yet been added", py::arg("nument"));
cls_IFSelect_AppliedModifiers.def("Count", (Standard_Integer (IFSelect_AppliedModifiers::*)() const) &IFSelect_AppliedModifiers::Count, "Returns the count of recorded modifiers");
cls_IFSelect_AppliedModifiers.def("Item", [](IFSelect_AppliedModifiers &self, const Standard_Integer num, opencascade::handle<IFSelect_GeneralModifier> & modif, Standard_Integer & entcount){ Standard_Boolean rv = self.Item(num, modif, entcount); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, entcount); }, "Returns the description for applied modifier n0 <num> : the modifier itself, and the count of entities to be applied on. If no specific list of number has been defined, returns the total count of entities of the file If this count is zero, then the modifier applies to all the file (see below). Else, the numbers are then queried by calls to ItemNum between 1 and <entcount> Returns True if OK, False if <num> is out of range", py::arg("num"), py::arg("modif"), py::arg("entcount"));
cls_IFSelect_AppliedModifiers.def("ItemNum", (Standard_Integer (IFSelect_AppliedModifiers::*)(const Standard_Integer) const) &IFSelect_AppliedModifiers::ItemNum, "Returns a numero of entity to be applied on, given its rank in the list. If no list is defined (i.e. for all the file), returns <nument> itself, to give all the entities of the file Returns 0 if <nument> out of range", py::arg("nument"));
cls_IFSelect_AppliedModifiers.def("ItemList", (opencascade::handle<TColStd_HSequenceOfInteger> (IFSelect_AppliedModifiers::*)() const) &IFSelect_AppliedModifiers::ItemList, "Returns the list of entities to be applied on (see Item) as a HSequence (IsForAll produces the complete list of all the entity numbers of the file");
cls_IFSelect_AppliedModifiers.def("IsForAll", (Standard_Boolean (IFSelect_AppliedModifiers::*)() const) &IFSelect_AppliedModifiers::IsForAll, "Returns True if the applied modifier queried by last call to Item is to be applied to all the produced file. Else, <entcount> returned by Item gives the count of entity numbers, each one is queried by ItemNum");
cls_IFSelect_AppliedModifiers.def_static("get_type_name_", (const char * (*)()) &IFSelect_AppliedModifiers::get_type_name, "None");
cls_IFSelect_AppliedModifiers.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_AppliedModifiers::get_type_descriptor, "None");
cls_IFSelect_AppliedModifiers.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_AppliedModifiers::*)() const) &IFSelect_AppliedModifiers::DynamicType, "None");

// CLASS: IFSELECT_SESSIONDUMPER
py::class_<IFSelect_SessionDumper, opencascade::handle<IFSelect_SessionDumper>, Standard_Transient> cls_IFSelect_SessionDumper(mod, "IFSelect_SessionDumper", "A SessionDumper is called by SessionFile. It takes into account a set of classes (such as Selections, Dispatches ...). SessionFile writes the Type (as defined by cdl) of each Item and its general Parameters. It manages the names of the Items.");

// Methods
cls_IFSelect_SessionDumper.def_static("First_", (opencascade::handle<IFSelect_SessionDumper> (*)()) &IFSelect_SessionDumper::First, "Returns the First item of the Library of Dumper. The Next ones are then obtained by Next on the returned items");
cls_IFSelect_SessionDumper.def("Next", (opencascade::handle<IFSelect_SessionDumper> (IFSelect_SessionDumper::*)() const) &IFSelect_SessionDumper::Next, "Returns the Next SesionDumper in the Library. Returns a Null Handle at the End.");
cls_IFSelect_SessionDumper.def("WriteOwn", (Standard_Boolean (IFSelect_SessionDumper::*)(IFSelect_SessionFile &, const opencascade::handle<Standard_Transient> &) const) &IFSelect_SessionDumper::WriteOwn, "Writes the Own Parameters of a given Item, if it forecast to manage its Type. Returns True if it has recognized the Type of the Item (in this case, it is assumed to have written the Own Parameters if there are some), False else : in that case, SessionFile will try another SessionDumper in the Library. WriteOwn can use these methods from SessionFile : SendVoid, SendItem, SendText, and if necessary, WorkSession.", py::arg("file"), py::arg("item"));
cls_IFSelect_SessionDumper.def("ReadOwn", (Standard_Boolean (IFSelect_SessionDumper::*)(IFSelect_SessionFile &, const TCollection_AsciiString &, opencascade::handle<Standard_Transient> &) const) &IFSelect_SessionDumper::ReadOwn, "Recognizes a Type (given as <type>) then Creates an Item of this Type with the Own Parameter, as required. Returns True if it has recognized the Type (in this case, it is assumed to have created the Item, returned as <item>), False else : in that case, SessionFile will try another SessionDumper in the Library. ReadOwn can use these methods from SessionFile to access Own Parameters : NbOwnParams, IsVoid, IsText, TextValue, ItemValue", py::arg("file"), py::arg("type"), py::arg("item"));
cls_IFSelect_SessionDumper.def_static("get_type_name_", (const char * (*)()) &IFSelect_SessionDumper::get_type_name, "None");
cls_IFSelect_SessionDumper.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SessionDumper::get_type_descriptor, "None");
cls_IFSelect_SessionDumper.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SessionDumper::*)() const) &IFSelect_SessionDumper::DynamicType, "None");

// CLASS: IFSELECT_BASICDUMPER
py::class_<IFSelect_BasicDumper, opencascade::handle<IFSelect_BasicDumper>, IFSelect_SessionDumper> cls_IFSelect_BasicDumper(mod, "IFSelect_BasicDumper", "BasicDumper takes into account, for SessionFile, all the classes defined in the package IFSelect : Selections, Dispatches (there is no Modifier)");

// Constructors
cls_IFSelect_BasicDumper.def(py::init<>());

// Methods
cls_IFSelect_BasicDumper.def("WriteOwn", (Standard_Boolean (IFSelect_BasicDumper::*)(IFSelect_SessionFile &, const opencascade::handle<Standard_Transient> &) const) &IFSelect_BasicDumper::WriteOwn, "Write the Own Parameters of Types defined in package IFSelect Returns True if <item> has been processed, False else", py::arg("file"), py::arg("item"));
cls_IFSelect_BasicDumper.def("ReadOwn", (Standard_Boolean (IFSelect_BasicDumper::*)(IFSelect_SessionFile &, const TCollection_AsciiString &, opencascade::handle<Standard_Transient> &) const) &IFSelect_BasicDumper::ReadOwn, "Recognizes and Read Own Parameters for Types of package IFSelect. Returns True if done and <item> created, False else", py::arg("file"), py::arg("type"), py::arg("item"));
cls_IFSelect_BasicDumper.def_static("get_type_name_", (const char * (*)()) &IFSelect_BasicDumper::get_type_name, "None");
cls_IFSelect_BasicDumper.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_BasicDumper::get_type_descriptor, "None");
cls_IFSelect_BasicDumper.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_BasicDumper::*)() const) &IFSelect_BasicDumper::DynamicType, "None");

// CLASS: IFSELECT_SIGNATURELIST
py::class_<IFSelect_SignatureList, opencascade::handle<IFSelect_SignatureList>, Standard_Transient> cls_IFSelect_SignatureList(mod, "IFSelect_SignatureList", "A SignatureList is given as result from a Counter (any kind) It gives access to a list of signatures, with counts, and optionally with list of corresponding entities");

// Constructors
cls_IFSelect_SignatureList.def(py::init<>());
cls_IFSelect_SignatureList.def(py::init<const Standard_Boolean>(), py::arg("withlist"));

// Methods
cls_IFSelect_SignatureList.def("SetList", (void (IFSelect_SignatureList::*)(const Standard_Boolean)) &IFSelect_SignatureList::SetList, "Changes the record-list status. The list is not cleared but its use changes", py::arg("withlist"));
cls_IFSelect_SignatureList.def("ModeSignOnly", (Standard_Boolean & (IFSelect_SignatureList::*)()) &IFSelect_SignatureList::ModeSignOnly, "Returns modifiable the SignOnly Mode If False (D), the counter normally counts If True, the counting work is turned off, Add only fills the LastValue, which can be used as signature, when a counter works from data which are not available from a Signature");
cls_IFSelect_SignatureList.def("Clear", (void (IFSelect_SignatureList::*)()) &IFSelect_SignatureList::Clear, "None");
cls_IFSelect_SignatureList.def("Add", (void (IFSelect_SignatureList::*)(const opencascade::handle<Standard_Transient> &, const Standard_CString)) &IFSelect_SignatureList::Add, "Adds an entity with its signature, i.e. : - counts an item more for <sign> - if record-list status is set, records the entity Accepts a null entity (the signature is then for the global model). But if the string is empty, counts a Null item.", py::arg("ent"), py::arg("sign"));
cls_IFSelect_SignatureList.def("LastValue", (Standard_CString (IFSelect_SignatureList::*)() const) &IFSelect_SignatureList::LastValue, "Returns the last value recorded by Add (only if SignMode set) Cleared by Clear or Init");
cls_IFSelect_SignatureList.def("Init", (void (IFSelect_SignatureList::*)(const Standard_CString, const NCollection_IndexedDataMap<TCollection_AsciiString, Standard_Integer> &, const NCollection_IndexedDataMap<TCollection_AsciiString, opencascade::handle<Standard_Transient> > &, const Standard_Integer)) &IFSelect_SignatureList::Init, "Aknowledges the list in once. Name identifies the Signature", py::arg("name"), py::arg("count"), py::arg("list"), py::arg("nbnuls"));
cls_IFSelect_SignatureList.def("List", [](IFSelect_SignatureList &self) -> opencascade::handle<TColStd_HSequenceOfHAsciiString> { return self.List(); });
cls_IFSelect_SignatureList.def("List", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (IFSelect_SignatureList::*)(const Standard_CString) const) &IFSelect_SignatureList::List, "Returns the list of signatures, as a sequence of strings (but without their respective counts). It is ordered. By default, for all the signatures. If <root> is given non empty, for the signatures which begin by <root>", py::arg("root"));
cls_IFSelect_SignatureList.def("HasEntities", (Standard_Boolean (IFSelect_SignatureList::*)() const) &IFSelect_SignatureList::HasEntities, "Returns True if the list of Entities is aknowledged, else the method Entities will always return a Null Handle");
cls_IFSelect_SignatureList.def("NbNulls", (Standard_Integer (IFSelect_SignatureList::*)() const) &IFSelect_SignatureList::NbNulls, "Returns the count of null entities");
cls_IFSelect_SignatureList.def("NbTimes", (Standard_Integer (IFSelect_SignatureList::*)(const Standard_CString) const) &IFSelect_SignatureList::NbTimes, "Returns the number of times a signature was counted, 0 if it has not been recorded at all", py::arg("sign"));
cls_IFSelect_SignatureList.def("Entities", (opencascade::handle<TColStd_HSequenceOfTransient> (IFSelect_SignatureList::*)(const Standard_CString) const) &IFSelect_SignatureList::Entities, "Returns the list of entities attached to a signature It is empty if <sign> has not been recorded It is a Null Handle if the list of entities is not known", py::arg("sign"));
cls_IFSelect_SignatureList.def("SetName", (void (IFSelect_SignatureList::*)(const Standard_CString)) &IFSelect_SignatureList::SetName, "Defines a name for a SignatureList (used to print it)", py::arg("name"));
cls_IFSelect_SignatureList.def("Name", (Standard_CString (IFSelect_SignatureList::*)() const) &IFSelect_SignatureList::Name, "Returns the recorded Name. Remark : default is '...' (no SetName called)");
cls_IFSelect_SignatureList.def("PrintCount", (void (IFSelect_SignatureList::*)(const opencascade::handle<Message_Messenger> &) const) &IFSelect_SignatureList::PrintCount, "Prints the counts of items (not the list)", py::arg("S"));
cls_IFSelect_SignatureList.def("PrintList", [](IFSelect_SignatureList &self, const opencascade::handle<Message_Messenger> & a0, const opencascade::handle<Interface_InterfaceModel> & a1) -> void { return self.PrintList(a0, a1); });
cls_IFSelect_SignatureList.def("PrintList", (void (IFSelect_SignatureList::*)(const opencascade::handle<Message_Messenger> &, const opencascade::handle<Interface_InterfaceModel> &, const IFSelect_PrintCount) const) &IFSelect_SignatureList::PrintList, "Prints the lists of items, if they are present (else, prints a message 'no list available') Uses <model> to determine for each entity to be listed, its number, and its specific identifier (by PrintLabel) <mod> gives a mode for printing : - CountByItem : just count (as PrintCount) - ShortByItem : minimum i.e. count plus 5 first entity numbers - ShortByItem(D) complete list of entity numbers (0: 'Global') - EntitiesByItem : list of (entity number/PrintLabel from the model) other modes are ignored", py::arg("S"), py::arg("model"), py::arg("mod"));
cls_IFSelect_SignatureList.def("PrintSum", (void (IFSelect_SignatureList::*)(const opencascade::handle<Message_Messenger> &) const) &IFSelect_SignatureList::PrintSum, "Prints a summary Item which has the greatest count of entities For items which are numeric values : their count, maximum, minimum values, cumul, average", py::arg("S"));
cls_IFSelect_SignatureList.def_static("get_type_name_", (const char * (*)()) &IFSelect_SignatureList::get_type_name, "None");
cls_IFSelect_SignatureList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SignatureList::get_type_descriptor, "None");
cls_IFSelect_SignatureList.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SignatureList::*)() const) &IFSelect_SignatureList::DynamicType, "None");

// CLASS: IFSELECT_CHECKCOUNTER
py::class_<IFSelect_CheckCounter, opencascade::handle<IFSelect_CheckCounter>, IFSelect_SignatureList> cls_IFSelect_CheckCounter(mod, "IFSelect_CheckCounter", "A CheckCounter allows to see a CheckList (i.e. CheckIterator) not per entity, its messages, but per message, the entities attached (count and list). Because many messages can be repeated if they are due to systematic errors");

// Constructors
cls_IFSelect_CheckCounter.def(py::init<>());
cls_IFSelect_CheckCounter.def(py::init<const Standard_Boolean>(), py::arg("withlist"));

// Methods
cls_IFSelect_CheckCounter.def("SetSignature", (void (IFSelect_CheckCounter::*)(const opencascade::handle<MoniTool_SignText> &)) &IFSelect_CheckCounter::SetSignature, "Sets a specific signature Else, the current SignType (in the model) is used", py::arg("sign"));
cls_IFSelect_CheckCounter.def("Signature", (opencascade::handle<MoniTool_SignText> (IFSelect_CheckCounter::*)() const) &IFSelect_CheckCounter::Signature, "Returns the Signature;");
cls_IFSelect_CheckCounter.def("Analyse", [](IFSelect_CheckCounter &self, const Interface_CheckIterator & a0, const opencascade::handle<Interface_InterfaceModel> & a1) -> void { return self.Analyse(a0, a1); });
cls_IFSelect_CheckCounter.def("Analyse", [](IFSelect_CheckCounter &self, const Interface_CheckIterator & a0, const opencascade::handle<Interface_InterfaceModel> & a1, const Standard_Boolean a2) -> void { return self.Analyse(a0, a1, a2); });
cls_IFSelect_CheckCounter.def("Analyse", (void (IFSelect_CheckCounter::*)(const Interface_CheckIterator &, const opencascade::handle<Interface_InterfaceModel> &, const Standard_Boolean, const Standard_Boolean)) &IFSelect_CheckCounter::Analyse, "Analyses a CheckIterator according a Model (which detains the entities for which the CheckIterator has messages), i.e. counts messages for entities If <original> is True, does not consider final messages but those before interpretation (such as inserting variables : integers, reals, strings) If <failsonly> is True, only Fails are considered Remark : global messages are recorded with a Null entity", py::arg("list"), py::arg("model"), py::arg("original"), py::arg("failsonly"));
cls_IFSelect_CheckCounter.def_static("get_type_name_", (const char * (*)()) &IFSelect_CheckCounter::get_type_name, "None");
cls_IFSelect_CheckCounter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_CheckCounter::get_type_descriptor, "None");
cls_IFSelect_CheckCounter.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_CheckCounter::*)() const) &IFSelect_CheckCounter::DynamicType, "None");

// CLASS: IFSELECT_CONTEXTMODIF
py::class_<IFSelect_ContextModif> cls_IFSelect_ContextModif(mod, "IFSelect_ContextModif", "This class gathers various informations used by Model Modifiers apart from the target model itself, and the CopyTool which must be passed directly.");

// Constructors
cls_IFSelect_ContextModif.def(py::init<const Interface_Graph &, const Interface_CopyTool &>(), py::arg("graph"), py::arg("TC"));
cls_IFSelect_ContextModif.def(py::init<const Interface_Graph &, const Interface_CopyTool &, const Standard_CString>(), py::arg("graph"), py::arg("TC"), py::arg("filename"));
cls_IFSelect_ContextModif.def(py::init<const Interface_Graph &>(), py::arg("graph"));
cls_IFSelect_ContextModif.def(py::init<const Interface_Graph &, const Standard_CString>(), py::arg("graph"), py::arg("filename"));

// Methods
// cls_IFSelect_ContextModif.def_static("operator new_", (void * (*)(size_t)) &IFSelect_ContextModif::operator new, "None", py::arg("theSize"));
// cls_IFSelect_ContextModif.def_static("operator delete_", (void (*)(void *)) &IFSelect_ContextModif::operator delete, "None", py::arg("theAddress"));
// cls_IFSelect_ContextModif.def_static("operator new[]_", (void * (*)(size_t)) &IFSelect_ContextModif::operator new[], "None", py::arg("theSize"));
// cls_IFSelect_ContextModif.def_static("operator delete[]_", (void (*)(void *)) &IFSelect_ContextModif::operator delete[], "None", py::arg("theAddress"));
// cls_IFSelect_ContextModif.def_static("operator new_", (void * (*)(size_t, void *)) &IFSelect_ContextModif::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IFSelect_ContextModif.def_static("operator delete_", (void (*)(void *, void *)) &IFSelect_ContextModif::operator delete, "None", py::arg(""), py::arg(""));
cls_IFSelect_ContextModif.def("Select", (void (IFSelect_ContextModif::*)(Interface_EntityIterator &)) &IFSelect_ContextModif::Select, "This method requires ContextModif to be applied with a filter. If a ModelModifier is defined with a Selection criterium, the result of this Selection is used as a filter : - if none of its items has been transferred, the modification does not apply at all - else, the Modifier can query for what entities were selected and what are their results - if this method is not called before working, the Modifier has to work on the whole Model", py::arg("list"));
cls_IFSelect_ContextModif.def("OriginalGraph", (const Interface_Graph & (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::OriginalGraph, "Returns the original Graph (compared to OriginalModel, it gives more query capabilitites)");
cls_IFSelect_ContextModif.def("OriginalModel", (opencascade::handle<Interface_InterfaceModel> (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::OriginalModel, "Returns the original model");
cls_IFSelect_ContextModif.def("SetProtocol", (void (IFSelect_ContextModif::*)(const opencascade::handle<Interface_Protocol> &)) &IFSelect_ContextModif::SetProtocol, "Allows to transmit a Protocol as part of a ContextModif", py::arg("proto"));
cls_IFSelect_ContextModif.def("Protocol", (opencascade::handle<Interface_Protocol> (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::Protocol, "Returns the Protocol (Null if not set)");
cls_IFSelect_ContextModif.def("HasFileName", (Standard_Boolean (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::HasFileName, "Returns True if a non empty file name has been defined");
cls_IFSelect_ContextModif.def("FileName", (Standard_CString (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::FileName, "Returns File Name (can be empty)");
cls_IFSelect_ContextModif.def("Control", (opencascade::handle<Interface_CopyControl> (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::Control, "Returns the map for a direct use, if required");
cls_IFSelect_ContextModif.def("IsForNone", (Standard_Boolean (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::IsForNone, "Returns True if Select has determined that a Modifier may not be run (filter defined and empty)");
cls_IFSelect_ContextModif.def("IsForAll", (Standard_Boolean (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::IsForAll, "Returns True if no filter is defined : a Modifier has to work on all entities of the resulting (target) model");
cls_IFSelect_ContextModif.def("IsTransferred", (Standard_Boolean (IFSelect_ContextModif::*)(const opencascade::handle<Standard_Transient> &) const) &IFSelect_ContextModif::IsTransferred, "Returns True if a starting item has been transferred", py::arg("ent"));
cls_IFSelect_ContextModif.def("IsSelected", (Standard_Boolean (IFSelect_ContextModif::*)(const opencascade::handle<Standard_Transient> &) const) &IFSelect_ContextModif::IsSelected, "Returns True if a starting item has been transferred and selected", py::arg("ent"));
// cls_IFSelect_ContextModif.def("Search", (Standard_Boolean (IFSelect_ContextModif::*)(const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &) const) &IFSelect_ContextModif::Search, "Returns True if a starting entity has been transferred, and the result is in <res>. Returns False else (direct call to the map)", py::arg("ent"), py::arg("res"));
cls_IFSelect_ContextModif.def("SelectedOriginal", (Interface_EntityIterator (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::SelectedOriginal, "Returns the list of original selected items. See also the iteration");
cls_IFSelect_ContextModif.def("SelectedResult", (Interface_EntityIterator (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::SelectedResult, "Returns the list of resulting counterparts of selected items. See also the iteration");
cls_IFSelect_ContextModif.def("SelectedCount", (Standard_Integer (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::SelectedCount, "Returns the count of selected and transferred items");
cls_IFSelect_ContextModif.def("Start", (void (IFSelect_ContextModif::*)()) &IFSelect_ContextModif::Start, "Starts an iteration on selected items. It takes into account IsForAll/IsForNone, by really iterating on all selected items.");
cls_IFSelect_ContextModif.def("More", (Standard_Boolean (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::More, "Returns True until the iteration has finished");
cls_IFSelect_ContextModif.def("Next", (void (IFSelect_ContextModif::*)()) &IFSelect_ContextModif::Next, "Advances the iteration");
cls_IFSelect_ContextModif.def("ValueOriginal", (opencascade::handle<Standard_Transient> (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::ValueOriginal, "Returns the current selected item in the original model");
cls_IFSelect_ContextModif.def("ValueResult", (opencascade::handle<Standard_Transient> (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::ValueResult, "Returns the result counterpart of current selected item (in the target model)");
cls_IFSelect_ContextModif.def("TraceModifier", (void (IFSelect_ContextModif::*)(const opencascade::handle<IFSelect_GeneralModifier> &)) &IFSelect_ContextModif::TraceModifier, "Traces the application of a Modifier. Works with default trace File and Level. Fills the trace if default trace level is at least 1. Traces the Modifier (its Label) and its Selection if there is one (its Label). To be called after Select (because status IsForAll is printed) Worths to trace a global modification. See also Trace below", py::arg("modif"));
cls_IFSelect_ContextModif.def("Trace", [](IFSelect_ContextModif &self) -> void { return self.Trace(); });
cls_IFSelect_ContextModif.def("Trace", (void (IFSelect_ContextModif::*)(const Standard_CString)) &IFSelect_ContextModif::Trace, "Traces the modification of the current entity (see above, ValueOriginal and ValueResult) for default trace level >= 2. To be called on each indivudual entity really modified <mess> is an optionnal additional message", py::arg("mess"));
cls_IFSelect_ContextModif.def("AddCheck", (void (IFSelect_ContextModif::*)(const opencascade::handle<Interface_Check> &)) &IFSelect_ContextModif::AddCheck, "Adds a Check to the CheckList. If it is empty, nothing is done If it concerns an Entity from the Original Model (by SetEntity) to which another Check is attached, it is merged to it. Else, it is added or merged as to GlobalCheck.", py::arg("check"));
cls_IFSelect_ContextModif.def("AddWarning", [](IFSelect_ContextModif &self, const opencascade::handle<Standard_Transient> & a0, const Standard_CString a1) -> void { return self.AddWarning(a0, a1); });
cls_IFSelect_ContextModif.def("AddWarning", (void (IFSelect_ContextModif::*)(const opencascade::handle<Standard_Transient> &, const Standard_CString, const Standard_CString)) &IFSelect_ContextModif::AddWarning, "Adds a Warning Message for an Entity from the original Model If <start> is not an Entity from the original model (e.g. the model itself) this message is added to Global Check.", py::arg("start"), py::arg("mess"), py::arg("orig"));
cls_IFSelect_ContextModif.def("AddFail", [](IFSelect_ContextModif &self, const opencascade::handle<Standard_Transient> & a0, const Standard_CString a1) -> void { return self.AddFail(a0, a1); });
cls_IFSelect_ContextModif.def("AddFail", (void (IFSelect_ContextModif::*)(const opencascade::handle<Standard_Transient> &, const Standard_CString, const Standard_CString)) &IFSelect_ContextModif::AddFail, "Adds a Fail Message for an Entity from the original Model If <start> is not an Entity from the original model (e.g. the model itself) this message is added to Global Check.", py::arg("start"), py::arg("mess"), py::arg("orig"));
cls_IFSelect_ContextModif.def("CCheck", [](IFSelect_ContextModif &self) -> opencascade::handle<Interface_Check> { return self.CCheck(); });
cls_IFSelect_ContextModif.def("CCheck", (opencascade::handle<Interface_Check> (IFSelect_ContextModif::*)(const Standard_Integer)) &IFSelect_ContextModif::CCheck, "Returns a Check given an Entity number (in the original Model) by default a Global Check. Creates it the first time. It can then be acknowledged on the spot, in condition that the caller works by reference ('Interface_Check& check = ...')", py::arg("num"));
cls_IFSelect_ContextModif.def("CCheck", (opencascade::handle<Interface_Check> (IFSelect_ContextModif::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_ContextModif::CCheck, "Returns a Check attached to an Entity from the original Model It can then be acknowledged on the spot, in condition that the caller works by reference ('Interface_Check& check = ...')", py::arg("start"));
cls_IFSelect_ContextModif.def("CheckList", (Interface_CheckIterator (IFSelect_ContextModif::*)() const) &IFSelect_ContextModif::CheckList, "Returns the complete CheckList");

// CLASS: IFSELECT_CONTEXTWRITE
py::class_<IFSelect_ContextWrite> cls_IFSelect_ContextWrite(mod, "IFSelect_ContextWrite", "This class gathers various informations used by File Modifiers apart from the writer object, which is specific of the norm and of the physical format");

// Constructors
cls_IFSelect_ContextWrite.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &, const opencascade::handle<IFSelect_AppliedModifiers> &, const Standard_CString>(), py::arg("model"), py::arg("proto"), py::arg("applieds"), py::arg("filename"));
cls_IFSelect_ContextWrite.def(py::init<const opencascade::handle<Interface_HGraph> &, const opencascade::handle<Interface_Protocol> &, const opencascade::handle<IFSelect_AppliedModifiers> &, const Standard_CString>(), py::arg("hgraph"), py::arg("proto"), py::arg("applieds"), py::arg("filename"));

// Methods
// cls_IFSelect_ContextWrite.def_static("operator new_", (void * (*)(size_t)) &IFSelect_ContextWrite::operator new, "None", py::arg("theSize"));
// cls_IFSelect_ContextWrite.def_static("operator delete_", (void (*)(void *)) &IFSelect_ContextWrite::operator delete, "None", py::arg("theAddress"));
// cls_IFSelect_ContextWrite.def_static("operator new[]_", (void * (*)(size_t)) &IFSelect_ContextWrite::operator new[], "None", py::arg("theSize"));
// cls_IFSelect_ContextWrite.def_static("operator delete[]_", (void (*)(void *)) &IFSelect_ContextWrite::operator delete[], "None", py::arg("theAddress"));
// cls_IFSelect_ContextWrite.def_static("operator new_", (void * (*)(size_t, void *)) &IFSelect_ContextWrite::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IFSelect_ContextWrite.def_static("operator delete_", (void (*)(void *, void *)) &IFSelect_ContextWrite::operator delete, "None", py::arg(""), py::arg(""));
cls_IFSelect_ContextWrite.def("Model", (opencascade::handle<Interface_InterfaceModel> (IFSelect_ContextWrite::*)() const) &IFSelect_ContextWrite::Model, "Returns the Model");
cls_IFSelect_ContextWrite.def("Protocol", (opencascade::handle<Interface_Protocol> (IFSelect_ContextWrite::*)() const) &IFSelect_ContextWrite::Protocol, "Returns the Protocol;");
cls_IFSelect_ContextWrite.def("FileName", (Standard_CString (IFSelect_ContextWrite::*)() const) &IFSelect_ContextWrite::FileName, "Returns the File Name");
cls_IFSelect_ContextWrite.def("AppliedModifiers", (opencascade::handle<IFSelect_AppliedModifiers> (IFSelect_ContextWrite::*)() const) &IFSelect_ContextWrite::AppliedModifiers, "Returns the object AppliedModifiers");
cls_IFSelect_ContextWrite.def("Graph", (const Interface_Graph & (IFSelect_ContextWrite::*)()) &IFSelect_ContextWrite::Graph, "Returns the Graph, either given when created, else created the first time it is queried");
cls_IFSelect_ContextWrite.def("NbModifiers", (Standard_Integer (IFSelect_ContextWrite::*)() const) &IFSelect_ContextWrite::NbModifiers, "Returns the count of recorded File Modifiers");
cls_IFSelect_ContextWrite.def("SetModifier", (Standard_Boolean (IFSelect_ContextWrite::*)(const Standard_Integer)) &IFSelect_ContextWrite::SetModifier, "Sets active the File Modifier n0 <numod> Then, it prepares the list of entities to consider, if any Returns False if <numod> out of range", py::arg("numod"));
cls_IFSelect_ContextWrite.def("FileModifier", (opencascade::handle<IFSelect_GeneralModifier> (IFSelect_ContextWrite::*)() const) &IFSelect_ContextWrite::FileModifier, "Returns the currently active File Modifier. Cast to be done Null if not properly set : must be test IsNull after casting");
cls_IFSelect_ContextWrite.def("IsForNone", (Standard_Boolean (IFSelect_ContextWrite::*)() const) &IFSelect_ContextWrite::IsForNone, "Returns True if no modifier is currently set");
cls_IFSelect_ContextWrite.def("IsForAll", (Standard_Boolean (IFSelect_ContextWrite::*)() const) &IFSelect_ContextWrite::IsForAll, "Returns True if the current modifier is to be applied to the whole model. Else, a restricted list of selected entities is defined, it can be exploited by the File Modifier");
cls_IFSelect_ContextWrite.def("NbEntities", (Standard_Integer (IFSelect_ContextWrite::*)() const) &IFSelect_ContextWrite::NbEntities, "Returns the total count of selected entities");
cls_IFSelect_ContextWrite.def("Start", (void (IFSelect_ContextWrite::*)()) &IFSelect_ContextWrite::Start, "Starts an iteration on selected items. It takes into account IsForAll/IsForNone, by really iterating on all selected items.");
cls_IFSelect_ContextWrite.def("More", (Standard_Boolean (IFSelect_ContextWrite::*)() const) &IFSelect_ContextWrite::More, "Returns True until the iteration has finished");
cls_IFSelect_ContextWrite.def("Next", (void (IFSelect_ContextWrite::*)()) &IFSelect_ContextWrite::Next, "Advances the iteration");
cls_IFSelect_ContextWrite.def("Value", (opencascade::handle<Standard_Transient> (IFSelect_ContextWrite::*)() const) &IFSelect_ContextWrite::Value, "Returns the current selected entity in the model");
cls_IFSelect_ContextWrite.def("AddCheck", (void (IFSelect_ContextWrite::*)(const opencascade::handle<Interface_Check> &)) &IFSelect_ContextWrite::AddCheck, "Adds a Check to the CheckList. If it is empty, nothing is done If it concerns an Entity from the Model (by SetEntity) to which another Check is attached, it is merged to it. Else, it is added or merged as to GlobalCheck.", py::arg("check"));
cls_IFSelect_ContextWrite.def("AddWarning", [](IFSelect_ContextWrite &self, const opencascade::handle<Standard_Transient> & a0, const Standard_CString a1) -> void { return self.AddWarning(a0, a1); });
cls_IFSelect_ContextWrite.def("AddWarning", (void (IFSelect_ContextWrite::*)(const opencascade::handle<Standard_Transient> &, const Standard_CString, const Standard_CString)) &IFSelect_ContextWrite::AddWarning, "Adds a Warning Message for an Entity from the Model If <start> is not an Entity from the model (e.g. the model itself) this message is added to Global Check.", py::arg("start"), py::arg("mess"), py::arg("orig"));
cls_IFSelect_ContextWrite.def("AddFail", [](IFSelect_ContextWrite &self, const opencascade::handle<Standard_Transient> & a0, const Standard_CString a1) -> void { return self.AddFail(a0, a1); });
cls_IFSelect_ContextWrite.def("AddFail", (void (IFSelect_ContextWrite::*)(const opencascade::handle<Standard_Transient> &, const Standard_CString, const Standard_CString)) &IFSelect_ContextWrite::AddFail, "Adds a Fail Message for an Entity from the Model If <start> is not an Entity from the model (e.g. the model itself) this message is added to Global Check.", py::arg("start"), py::arg("mess"), py::arg("orig"));
cls_IFSelect_ContextWrite.def("CCheck", [](IFSelect_ContextWrite &self) -> opencascade::handle<Interface_Check> { return self.CCheck(); });
cls_IFSelect_ContextWrite.def("CCheck", (opencascade::handle<Interface_Check> (IFSelect_ContextWrite::*)(const Standard_Integer)) &IFSelect_ContextWrite::CCheck, "Returns a Check given an Entity number (in the Model) by default a Global Check. Creates it the first time. It can then be acknowledged on the spot, in condition that the caller works by reference ('Interface_Check& check = ...')", py::arg("num"));
cls_IFSelect_ContextWrite.def("CCheck", (opencascade::handle<Interface_Check> (IFSelect_ContextWrite::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_ContextWrite::CCheck, "Returns a Check attached to an Entity from the Model It can then be acknowledged on the spot, in condition that the caller works by reference ('Interface_Check& check = ...')", py::arg("start"));
cls_IFSelect_ContextWrite.def("CheckList", (Interface_CheckIterator (IFSelect_ContextWrite::*)() const) &IFSelect_ContextWrite::CheckList, "Returns the complete CheckList");

// CLASS: IFSELECT_DISPATCH
py::class_<IFSelect_Dispatch, opencascade::handle<IFSelect_Dispatch>, Standard_Transient> cls_IFSelect_Dispatch(mod, "IFSelect_Dispatch", "This class allows to describe how a set of Entities has to be dispatched into resulting Packets : a Packet is a sub-set of the initial set of entities.");

// Methods
cls_IFSelect_Dispatch.def("SetRootName", (void (IFSelect_Dispatch::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IFSelect_Dispatch::SetRootName, "Sets a Root Name as an HAsciiString To reset it, give a Null Handle (then, a ShareOut will have to define the Default Root Name)", py::arg("name"));
cls_IFSelect_Dispatch.def("HasRootName", (Standard_Boolean (IFSelect_Dispatch::*)() const) &IFSelect_Dispatch::HasRootName, "Returns True if a specific Root Name has been set (else, the Default Root Name has to be used)");
cls_IFSelect_Dispatch.def("RootName", (const opencascade::handle<TCollection_HAsciiString> & (IFSelect_Dispatch::*)() const) &IFSelect_Dispatch::RootName, "Returns the Root Name for files produced by this dispatch It is empty if it has not been set or if it has been reset");
cls_IFSelect_Dispatch.def("SetFinalSelection", (void (IFSelect_Dispatch::*)(const opencascade::handle<IFSelect_Selection> &)) &IFSelect_Dispatch::SetFinalSelection, "Stores (or Changes) the Final Selection for a Dispatch", py::arg("sel"));
cls_IFSelect_Dispatch.def("FinalSelection", (opencascade::handle<IFSelect_Selection> (IFSelect_Dispatch::*)() const) &IFSelect_Dispatch::FinalSelection, "Returns the Final Selection of a Dispatch we 'd like : C++ : return const &");
cls_IFSelect_Dispatch.def("Selections", (IFSelect_SelectionIterator (IFSelect_Dispatch::*)() const) &IFSelect_Dispatch::Selections, "Returns the complete list of source Selections (starting from FinalSelection)");
cls_IFSelect_Dispatch.def("CanHaveRemainder", (Standard_Boolean (IFSelect_Dispatch::*)() const) &IFSelect_Dispatch::CanHaveRemainder, "Returns True if a Dispatch can have a Remainder, i.e. if its criterium can let entities apart. It is a potential answer, remainder can be empty at run-time even if answer is True. (to attach a RemainderFromDispatch Selection is not allowed if answer is True). Default answer given here is False (can be redefined)");
cls_IFSelect_Dispatch.def("LimitedMax", [](IFSelect_Dispatch &self, const Standard_Integer nbent, Standard_Integer & max){ Standard_Boolean rv = self.LimitedMax(nbent, max); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, max); }, "Returns True if a Dispatch generates a count of Packets always less than or equal to a maximum value : it can be computed from the total count of Entities to be dispatched : <nbent>. If answer is False, no limited maximum is expected for account If answer is True, expected maximum is given in argument <max> Default answer given here is False (can be redefined)", py::arg("nbent"), py::arg("max"));
cls_IFSelect_Dispatch.def("Label", (TCollection_AsciiString (IFSelect_Dispatch::*)() const) &IFSelect_Dispatch::Label, "Returns a text which defines the way a Dispatch produces packets (which will become files) from its Input");
cls_IFSelect_Dispatch.def("GetEntities", (Interface_EntityIterator (IFSelect_Dispatch::*)(const Interface_Graph &) const) &IFSelect_Dispatch::GetEntities, "Gets Unique Root Entities from the Final Selection, given an input Graph This the starting step for an Evaluation (Packets - Remainder)", py::arg("G"));
cls_IFSelect_Dispatch.def("Packets", (void (IFSelect_Dispatch::*)(const Interface_Graph &, IFGraph_SubPartsIterator &) const) &IFSelect_Dispatch::Packets, "Returns the list of produced Packets into argument <pack>. Each Packet corresponds to a Part, the Entities listed are the Roots given by the Selection. Input is given as a Graph. Thus, to create a file from a packet, it suffices to take the entities listed in a Part of Packets (that is, a Packet) without worrying about Shared entities This method can raise an Exception if data are not coherent", py::arg("G"), py::arg("packs"));
cls_IFSelect_Dispatch.def("Packeted", (Interface_EntityIterator (IFSelect_Dispatch::*)(const Interface_Graph &) const) &IFSelect_Dispatch::Packeted, "Returns the list of all Input Entities (see GetEntities) which are put in a Packet. That is, Entities listed in GetEntities but not in Remainder (see below). Input is given as a Graph.", py::arg("G"));
cls_IFSelect_Dispatch.def("Remainder", (Interface_EntityIterator (IFSelect_Dispatch::*)(const Interface_Graph &) const) &IFSelect_Dispatch::Remainder, "Returns Remainder which is a set of Entities. Can be empty. Default evaluation is empty (has to be redefined if CanHaveRemainder is redefined to return True).", py::arg("G"));
cls_IFSelect_Dispatch.def_static("get_type_name_", (const char * (*)()) &IFSelect_Dispatch::get_type_name, "None");
cls_IFSelect_Dispatch.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_Dispatch::get_type_descriptor, "None");
cls_IFSelect_Dispatch.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_Dispatch::*)() const) &IFSelect_Dispatch::DynamicType, "None");

// CLASS: IFSELECT_DISPGLOBAL
py::class_<IFSelect_DispGlobal, opencascade::handle<IFSelect_DispGlobal>, IFSelect_Dispatch> cls_IFSelect_DispGlobal(mod, "IFSelect_DispGlobal", "A DispGlobal gathers all the input Entities into only one global Packet");

// Constructors
cls_IFSelect_DispGlobal.def(py::init<>());

// Methods
cls_IFSelect_DispGlobal.def("Label", (TCollection_AsciiString (IFSelect_DispGlobal::*)() const) &IFSelect_DispGlobal::Label, "Returns as Label, 'One File for all Input'");
cls_IFSelect_DispGlobal.def("LimitedMax", [](IFSelect_DispGlobal &self, const Standard_Integer nbent, Standard_Integer & max){ Standard_Boolean rv = self.LimitedMax(nbent, max); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, max); }, "Returns True : maximum equates 1", py::arg("nbent"), py::arg("max"));
cls_IFSelect_DispGlobal.def("Packets", (void (IFSelect_DispGlobal::*)(const Interface_Graph &, IFGraph_SubPartsIterator &) const) &IFSelect_DispGlobal::Packets, "Computes the list of produced Packets. It is made of only ONE Packet, which gets the RootResult from the Final Selection. Remark : the inherited exception raising is never activated.", py::arg("G"), py::arg("packs"));
cls_IFSelect_DispGlobal.def_static("get_type_name_", (const char * (*)()) &IFSelect_DispGlobal::get_type_name, "None");
cls_IFSelect_DispGlobal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_DispGlobal::get_type_descriptor, "None");
cls_IFSelect_DispGlobal.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_DispGlobal::*)() const) &IFSelect_DispGlobal::DynamicType, "None");

// CLASS: IFSELECT_DISPPERCOUNT
py::class_<IFSelect_DispPerCount, opencascade::handle<IFSelect_DispPerCount>, IFSelect_Dispatch> cls_IFSelect_DispPerCount(mod, "IFSelect_DispPerCount", "A DispPerCount gathers all the input Entities into one or several Packets, each containing a defined count of Entity This count is a Parameter of the DispPerCount, given as an IntParam, thus allowing external control of its Value");

// Constructors
cls_IFSelect_DispPerCount.def(py::init<>());

// Methods
cls_IFSelect_DispPerCount.def("Count", (opencascade::handle<IFSelect_IntParam> (IFSelect_DispPerCount::*)() const) &IFSelect_DispPerCount::Count, "Returns the Count Parameter used for splitting");
cls_IFSelect_DispPerCount.def("SetCount", (void (IFSelect_DispPerCount::*)(const opencascade::handle<IFSelect_IntParam> &)) &IFSelect_DispPerCount::SetCount, "Sets a new Parameter for Count", py::arg("count"));
cls_IFSelect_DispPerCount.def("CountValue", (Standard_Integer (IFSelect_DispPerCount::*)() const) &IFSelect_DispPerCount::CountValue, "Returns the effective value of the count parameter (if Count Parameter not Set or value not positive, returns 1)");
cls_IFSelect_DispPerCount.def("Label", (TCollection_AsciiString (IFSelect_DispPerCount::*)() const) &IFSelect_DispPerCount::Label, "Returns as Label, 'One File per <count> Input Entities'");
cls_IFSelect_DispPerCount.def("LimitedMax", [](IFSelect_DispPerCount &self, const Standard_Integer nbent, Standard_Integer & max){ Standard_Boolean rv = self.LimitedMax(nbent, max); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, max); }, "Returns True, maximum count is given as <nbent>", py::arg("nbent"), py::arg("max"));
cls_IFSelect_DispPerCount.def("Packets", (void (IFSelect_DispPerCount::*)(const Interface_Graph &, IFGraph_SubPartsIterator &) const) &IFSelect_DispPerCount::Packets, "Computes the list of produced Packets. It defines Packets in order to have at most <Count> Entities per Packet, Entities are given by RootResult from the Final Selection.", py::arg("G"), py::arg("packs"));
cls_IFSelect_DispPerCount.def_static("get_type_name_", (const char * (*)()) &IFSelect_DispPerCount::get_type_name, "None");
cls_IFSelect_DispPerCount.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_DispPerCount::get_type_descriptor, "None");
cls_IFSelect_DispPerCount.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_DispPerCount::*)() const) &IFSelect_DispPerCount::DynamicType, "None");

// CLASS: IFSELECT_DISPPERFILES
py::class_<IFSelect_DispPerFiles, opencascade::handle<IFSelect_DispPerFiles>, IFSelect_Dispatch> cls_IFSelect_DispPerFiles(mod, "IFSelect_DispPerFiles", "A DispPerFiles produces a determined count of Packets from the input Entities. It divides, as equally as possible, the input list into a count of files. This count is the parameter of the DispPerFiles. If the input list has less than this count, of course there will be one packet per input entity. This count is a Parameter of the DispPerFiles, given as an IntParam, thus allowing external control of its Value");

// Constructors
cls_IFSelect_DispPerFiles.def(py::init<>());

// Methods
cls_IFSelect_DispPerFiles.def("Count", (opencascade::handle<IFSelect_IntParam> (IFSelect_DispPerFiles::*)() const) &IFSelect_DispPerFiles::Count, "Returns the Count Parameter used for splitting");
cls_IFSelect_DispPerFiles.def("SetCount", (void (IFSelect_DispPerFiles::*)(const opencascade::handle<IFSelect_IntParam> &)) &IFSelect_DispPerFiles::SetCount, "Sets a new Parameter for Count", py::arg("count"));
cls_IFSelect_DispPerFiles.def("CountValue", (Standard_Integer (IFSelect_DispPerFiles::*)() const) &IFSelect_DispPerFiles::CountValue, "Returns the effective value of the count parameter (if Count Parameter not Set or value not positive, returns 1)");
cls_IFSelect_DispPerFiles.def("Label", (TCollection_AsciiString (IFSelect_DispPerFiles::*)() const) &IFSelect_DispPerFiles::Label, "Returns as Label, 'Maximum <count> Files'");
cls_IFSelect_DispPerFiles.def("LimitedMax", [](IFSelect_DispPerFiles &self, const Standard_Integer nbent, Standard_Integer & max){ Standard_Boolean rv = self.LimitedMax(nbent, max); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, max); }, "Returns True, maximum count is given as CountValue", py::arg("nbent"), py::arg("max"));
cls_IFSelect_DispPerFiles.def("Packets", (void (IFSelect_DispPerFiles::*)(const Interface_Graph &, IFGraph_SubPartsIterator &) const) &IFSelect_DispPerFiles::Packets, "Computes the list of produced Packets. It defines Packets in order to have <Count> Packets, except if the input count of Entities is lower. Entities are given by RootResult from the Final Selection.", py::arg("G"), py::arg("packs"));
cls_IFSelect_DispPerFiles.def_static("get_type_name_", (const char * (*)()) &IFSelect_DispPerFiles::get_type_name, "None");
cls_IFSelect_DispPerFiles.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_DispPerFiles::get_type_descriptor, "None");
cls_IFSelect_DispPerFiles.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_DispPerFiles::*)() const) &IFSelect_DispPerFiles::DynamicType, "None");

// CLASS: IFSELECT_DISPPERONE
py::class_<IFSelect_DispPerOne, opencascade::handle<IFSelect_DispPerOne>, IFSelect_Dispatch> cls_IFSelect_DispPerOne(mod, "IFSelect_DispPerOne", "A DispPerOne gathers all the input Entities into as many Packets as there Root Entities from the Final Selection, that is, one Packet per Entity");

// Constructors
cls_IFSelect_DispPerOne.def(py::init<>());

// Methods
cls_IFSelect_DispPerOne.def("Label", (TCollection_AsciiString (IFSelect_DispPerOne::*)() const) &IFSelect_DispPerOne::Label, "Returns as Label, 'One File per Input Entity'");
cls_IFSelect_DispPerOne.def("LimitedMax", [](IFSelect_DispPerOne &self, const Standard_Integer nbent, Standard_Integer & max){ Standard_Boolean rv = self.LimitedMax(nbent, max); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, max); }, "Returns True, maximum limit is given as <nbent>", py::arg("nbent"), py::arg("max"));
cls_IFSelect_DispPerOne.def("Packets", (void (IFSelect_DispPerOne::*)(const Interface_Graph &, IFGraph_SubPartsIterator &) const) &IFSelect_DispPerOne::Packets, "Returns the list of produced Packets. It defines one Packet per Entity given by RootResult from the Final Selection.", py::arg("G"), py::arg("packs"));
cls_IFSelect_DispPerOne.def_static("get_type_name_", (const char * (*)()) &IFSelect_DispPerOne::get_type_name, "None");
cls_IFSelect_DispPerOne.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_DispPerOne::get_type_descriptor, "None");
cls_IFSelect_DispPerOne.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_DispPerOne::*)() const) &IFSelect_DispPerOne::DynamicType, "None");

// CLASS: IFSELECT_DISPPERSIGNATURE
py::class_<IFSelect_DispPerSignature, opencascade::handle<IFSelect_DispPerSignature>, IFSelect_Dispatch> cls_IFSelect_DispPerSignature(mod, "IFSelect_DispPerSignature", "A DispPerSignature sorts input Entities according to a Signature : it works with a SignCounter to do this.");

// Constructors
cls_IFSelect_DispPerSignature.def(py::init<>());

// Methods
cls_IFSelect_DispPerSignature.def("SignCounter", (opencascade::handle<IFSelect_SignCounter> (IFSelect_DispPerSignature::*)() const) &IFSelect_DispPerSignature::SignCounter, "Returns the SignCounter used for splitting");
cls_IFSelect_DispPerSignature.def("SetSignCounter", (void (IFSelect_DispPerSignature::*)(const opencascade::handle<IFSelect_SignCounter> &)) &IFSelect_DispPerSignature::SetSignCounter, "Sets a SignCounter for sort Remark : it is set to record lists of entities, not only counts", py::arg("sign"));
cls_IFSelect_DispPerSignature.def("SignName", (Standard_CString (IFSelect_DispPerSignature::*)() const) &IFSelect_DispPerSignature::SignName, "Returns the name of the SignCounter, which caracterises the sorting criterium for this Dispatch");
cls_IFSelect_DispPerSignature.def("Label", (TCollection_AsciiString (IFSelect_DispPerSignature::*)() const) &IFSelect_DispPerSignature::Label, "Returns as Label, 'One File per Signature <name>'");
cls_IFSelect_DispPerSignature.def("LimitedMax", [](IFSelect_DispPerSignature &self, const Standard_Integer nbent, Standard_Integer & max){ Standard_Boolean rv = self.LimitedMax(nbent, max); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, max); }, "Returns True, maximum count is given as <nbent>", py::arg("nbent"), py::arg("max"));
cls_IFSelect_DispPerSignature.def("Packets", (void (IFSelect_DispPerSignature::*)(const Interface_Graph &, IFGraph_SubPartsIterator &) const) &IFSelect_DispPerSignature::Packets, "Computes the list of produced Packets. It defines Packets from the SignCounter, which sirts the input Entities per Signature (specific of the SignCounter).", py::arg("G"), py::arg("packs"));
cls_IFSelect_DispPerSignature.def_static("get_type_name_", (const char * (*)()) &IFSelect_DispPerSignature::get_type_name, "None");
cls_IFSelect_DispPerSignature.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_DispPerSignature::get_type_descriptor, "None");
cls_IFSelect_DispPerSignature.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_DispPerSignature::*)() const) &IFSelect_DispPerSignature::DynamicType, "None");

// CLASS: IFSELECT_EDITFORM
py::class_<IFSelect_EditForm, opencascade::handle<IFSelect_EditForm>, Standard_Transient> cls_IFSelect_EditForm(mod, "IFSelect_EditForm", "An EditForm is the way to apply an Editor on an Entity or on the Model It gives read-only or read-write access, with or without undo");

// Constructors
cls_IFSelect_EditForm.def(py::init<const opencascade::handle<IFSelect_Editor> &, const Standard_Boolean, const Standard_Boolean>(), py::arg("editor"), py::arg("readonly"), py::arg("undoable"));
cls_IFSelect_EditForm.def(py::init<const opencascade::handle<IFSelect_Editor> &, const Standard_Boolean, const Standard_Boolean, const Standard_CString>(), py::arg("editor"), py::arg("readonly"), py::arg("undoable"), py::arg("label"));
cls_IFSelect_EditForm.def(py::init<const opencascade::handle<IFSelect_Editor> &, const TColStd_SequenceOfInteger &, const Standard_Boolean, const Standard_Boolean>(), py::arg("editor"), py::arg("nums"), py::arg("readonly"), py::arg("undoable"));
cls_IFSelect_EditForm.def(py::init<const opencascade::handle<IFSelect_Editor> &, const TColStd_SequenceOfInteger &, const Standard_Boolean, const Standard_Boolean, const Standard_CString>(), py::arg("editor"), py::arg("nums"), py::arg("readonly"), py::arg("undoable"), py::arg("label"));

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

// CLASS: IFSELECT_FUNCTIONS
py::class_<IFSelect_Functions> cls_IFSelect_Functions(mod, "IFSelect_Functions", "Functions gives access to all the actions which can be commanded with the resources provided by IFSelect : especially WorkSession and various types of Selections and Dispatches");

// Constructors
cls_IFSelect_Functions.def(py::init<>());

// Methods
// cls_IFSelect_Functions.def_static("operator new_", (void * (*)(size_t)) &IFSelect_Functions::operator new, "None", py::arg("theSize"));
// cls_IFSelect_Functions.def_static("operator delete_", (void (*)(void *)) &IFSelect_Functions::operator delete, "None", py::arg("theAddress"));
// cls_IFSelect_Functions.def_static("operator new[]_", (void * (*)(size_t)) &IFSelect_Functions::operator new[], "None", py::arg("theSize"));
// cls_IFSelect_Functions.def_static("operator delete[]_", (void (*)(void *)) &IFSelect_Functions::operator delete[], "None", py::arg("theAddress"));
// cls_IFSelect_Functions.def_static("operator new_", (void * (*)(size_t, void *)) &IFSelect_Functions::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IFSelect_Functions.def_static("operator delete_", (void (*)(void *, void *)) &IFSelect_Functions::operator delete, "None", py::arg(""), py::arg(""));
cls_IFSelect_Functions.def_static("GiveEntity_", [](const opencascade::handle<IFSelect_WorkSession> & a0) -> opencascade::handle<Standard_Transient> { return IFSelect_Functions::GiveEntity(a0); });
cls_IFSelect_Functions.def_static("GiveEntity_", (opencascade::handle<Standard_Transient> (*)(const opencascade::handle<IFSelect_WorkSession> &, const Standard_CString)) &IFSelect_Functions::GiveEntity, "Takes the name of an entity, either as argument, or (if <name> is empty) on keybord, and returns the entity name can be a label or a number (in alphanumeric), it is searched by NumberFromLabel from WorkSession. If <name> doesn't match en entity, a Null Handle is returned", py::arg("WS"), py::arg("name"));
cls_IFSelect_Functions.def_static("GiveEntityNumber_", [](const opencascade::handle<IFSelect_WorkSession> & a0) -> Standard_Integer { return IFSelect_Functions::GiveEntityNumber(a0); });
cls_IFSelect_Functions.def_static("GiveEntityNumber_", (Standard_Integer (*)(const opencascade::handle<IFSelect_WorkSession> &, const Standard_CString)) &IFSelect_Functions::GiveEntityNumber, "Same as GetEntity, but returns the number in the model of the entity. Returns 0 for null handle", py::arg("WS"), py::arg("name"));
cls_IFSelect_Functions.def_static("GiveList_", [](const opencascade::handle<IFSelect_WorkSession> & a0) -> opencascade::handle<TColStd_HSequenceOfTransient> { return IFSelect_Functions::GiveList(a0); });
cls_IFSelect_Functions.def_static("GiveList_", [](const opencascade::handle<IFSelect_WorkSession> & a0, const Standard_CString a1) -> opencascade::handle<TColStd_HSequenceOfTransient> { return IFSelect_Functions::GiveList(a0, a1); });
cls_IFSelect_Functions.def_static("GiveList_", (opencascade::handle<TColStd_HSequenceOfTransient> (*)(const opencascade::handle<IFSelect_WorkSession> &, const Standard_CString, const Standard_CString)) &IFSelect_Functions::GiveList, "Computes a List of entities from a WorkSession and two idents, first and second, as follows : if <first> is a Number or Label of an entity : this entity if <first> is the name of a Selection in <WS>, and <second> not defined, the standard result of this Selection if <first> is for a Selection and <second> is defined, the standard result of this selection from the list computed with <second> (an entity or a selection) If <second> is erroneous, it is ignored", py::arg("WS"), py::arg("first"), py::arg("second"));
cls_IFSelect_Functions.def_static("GiveDispatch_", [](const opencascade::handle<IFSelect_WorkSession> & a0, const Standard_CString a1) -> opencascade::handle<IFSelect_Dispatch> { return IFSelect_Functions::GiveDispatch(a0, a1); });
cls_IFSelect_Functions.def_static("GiveDispatch_", (opencascade::handle<IFSelect_Dispatch> (*)(const opencascade::handle<IFSelect_WorkSession> &, const Standard_CString, const Standard_Boolean)) &IFSelect_Functions::GiveDispatch, "Evaluates and returns a Dispatch, from data of a WorkSession if <mode> is False, searches for exact name of Dispatch in WS Else (D), allows a parameter between brackets : ex.: dispatch_name(parameter) The parameter can be: an integer for DispPerCount or DispPerFiles or the name of a Signature for DispPerSignature Returns Null Handle if not found not well evaluated", py::arg("WS"), py::arg("name"), py::arg("mode"));
cls_IFSelect_Functions.def_static("Init_", (void (*)()) &IFSelect_Functions::Init, "Defines and loads all basic functions (as ActFunc)");

// CLASS: IFSELECT_SIGNCOUNTER
py::class_<IFSelect_SignCounter, opencascade::handle<IFSelect_SignCounter>, IFSelect_SignatureList> cls_IFSelect_SignCounter(mod, "IFSelect_SignCounter", "SignCounter gives the frame to count signatures associated with entities, deducted from them. Ex.: their Dynamic Type.");

// Constructors
cls_IFSelect_SignCounter.def(py::init<>());
cls_IFSelect_SignCounter.def(py::init<const Standard_Boolean>(), py::arg("withmap"));
cls_IFSelect_SignCounter.def(py::init<const Standard_Boolean, const Standard_Boolean>(), py::arg("withmap"), py::arg("withlist"));
cls_IFSelect_SignCounter.def(py::init<const opencascade::handle<IFSelect_Signature> &>(), py::arg("matcher"));
cls_IFSelect_SignCounter.def(py::init<const opencascade::handle<IFSelect_Signature> &, const Standard_Boolean>(), py::arg("matcher"), py::arg("withmap"));
cls_IFSelect_SignCounter.def(py::init<const opencascade::handle<IFSelect_Signature> &, const Standard_Boolean, const Standard_Boolean>(), py::arg("matcher"), py::arg("withmap"), py::arg("withlist"));

// Methods
cls_IFSelect_SignCounter.def("Signature", (opencascade::handle<IFSelect_Signature> (IFSelect_SignCounter::*)() const) &IFSelect_SignCounter::Signature, "Returns the Signature used to count entities. It can be null.");
cls_IFSelect_SignCounter.def("SetMap", (void (IFSelect_SignCounter::*)(const Standard_Boolean)) &IFSelect_SignCounter::SetMap, "Changes the control status. The map is not cleared, simply its use changes", py::arg("withmap"));
cls_IFSelect_SignCounter.def("AddEntity", (Standard_Boolean (IFSelect_SignCounter::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &)) &IFSelect_SignCounter::AddEntity, "Adds an entity by considering its signature, which is given by call to method AddSign Returns True if added, False if already in the map (and map control status set)", py::arg("ent"), py::arg("model"));
cls_IFSelect_SignCounter.def("AddSign", (void (IFSelect_SignCounter::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &)) &IFSelect_SignCounter::AddSign, "Adds an entity (already filtered by Map) with its signature. This signature can be computed with the containing model. Its value is provided by the object Signature given at start, if no Signature is defined, it does nothing.", py::arg("ent"), py::arg("model"));
cls_IFSelect_SignCounter.def("AddList", (void (IFSelect_SignCounter::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &, const opencascade::handle<Interface_InterfaceModel> &)) &IFSelect_SignCounter::AddList, "Adds a list of entities by adding each of the items", py::arg("list"), py::arg("model"));
cls_IFSelect_SignCounter.def("AddWithGraph", (void (IFSelect_SignCounter::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &, const Interface_Graph &)) &IFSelect_SignCounter::AddWithGraph, "Adds a list of entities in the context given by the graph Default just call basic AddList Can be redefined to get a signature computed with the graph", py::arg("list"), py::arg("graph"));
cls_IFSelect_SignCounter.def("AddModel", (void (IFSelect_SignCounter::*)(const opencascade::handle<Interface_InterfaceModel> &)) &IFSelect_SignCounter::AddModel, "Adds all the entities contained in a Model", py::arg("model"));
cls_IFSelect_SignCounter.def("AddFromSelection", (void (IFSelect_SignCounter::*)(const opencascade::handle<IFSelect_Selection> &, const Interface_Graph &)) &IFSelect_SignCounter::AddFromSelection, "Adds the result determined by a Selection from a Graph Remark : does not impact at all data from SetSelection & Co", py::arg("sel"), py::arg("G"));
cls_IFSelect_SignCounter.def("SetSelection", (void (IFSelect_SignCounter::*)(const opencascade::handle<IFSelect_Selection> &)) &IFSelect_SignCounter::SetSelection, "Sets a Selection as input : this causes content to be cleared then the Selection to be ready to compute (but not immediatly)", py::arg("sel"));
cls_IFSelect_SignCounter.def("Selection", (opencascade::handle<IFSelect_Selection> (IFSelect_SignCounter::*)() const) &IFSelect_SignCounter::Selection, "Returns the selection, or a null Handle");
cls_IFSelect_SignCounter.def("SetSelMode", (void (IFSelect_SignCounter::*)(const Standard_Integer)) &IFSelect_SignCounter::SetSelMode, "Changes the mode of working with the selection : -1 just clears optimisation data and nothing else 0 clears it 1 inhibits it for computing (but no clearing) 2 sets it active for computing Default at creation is 0, after SetSelection (not null) is 2", py::arg("selmode"));
cls_IFSelect_SignCounter.def("SelMode", (Standard_Integer (IFSelect_SignCounter::*)() const) &IFSelect_SignCounter::SelMode, "Returns the mode of working with the selection");
cls_IFSelect_SignCounter.def("ComputeSelected", [](IFSelect_SignCounter &self, const Interface_Graph & a0) -> Standard_Boolean { return self.ComputeSelected(a0); });
cls_IFSelect_SignCounter.def("ComputeSelected", (Standard_Boolean (IFSelect_SignCounter::*)(const Interface_Graph &, const Standard_Boolean)) &IFSelect_SignCounter::ComputeSelected, "Computes from the selection result, if selection is active (mode 2). If selection is not defined (mode 0) or is inhibited (mode 1) does nothing. Returns True if computation is done (or optimised), False else This method is called by ComputeCounter from WorkSession", py::arg("G"), py::arg("forced"));
cls_IFSelect_SignCounter.def("Sign", (opencascade::handle<TCollection_HAsciiString> (IFSelect_SignCounter::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_SignCounter::Sign, "Determines and returns the value of the signature for an entity as an HAsciiString. This method works exactly as AddSign, which is optimized", py::arg("ent"), py::arg("model"));
cls_IFSelect_SignCounter.def("ComputedSign", (Standard_CString (IFSelect_SignCounter::*)(const opencascade::handle<Standard_Transient> &, const Interface_Graph &)) &IFSelect_SignCounter::ComputedSign, "Applies AddWithGraph on one entity, and returns the Signature Value which has been recorded To do this, Add is called with SignOnly Mode True during the call, the returned value is LastValue", py::arg("ent"), py::arg("G"));
cls_IFSelect_SignCounter.def_static("get_type_name_", (const char * (*)()) &IFSelect_SignCounter::get_type_name, "None");
cls_IFSelect_SignCounter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SignCounter::get_type_descriptor, "None");
cls_IFSelect_SignCounter.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SignCounter::*)() const) &IFSelect_SignCounter::DynamicType, "None");

// CLASS: IFSELECT_GRAPHCOUNTER
py::class_<IFSelect_GraphCounter, opencascade::handle<IFSelect_GraphCounter>, IFSelect_SignCounter> cls_IFSelect_GraphCounter(mod, "IFSelect_GraphCounter", "A GraphCounter computes values to be sorted with the help of a Graph. I.E. not from a Signature");

// Constructors
cls_IFSelect_GraphCounter.def(py::init<>());
cls_IFSelect_GraphCounter.def(py::init<const Standard_Boolean>(), py::arg("withmap"));
cls_IFSelect_GraphCounter.def(py::init<const Standard_Boolean, const Standard_Boolean>(), py::arg("withmap"), py::arg("withlist"));

// Methods
cls_IFSelect_GraphCounter.def("Applied", (opencascade::handle<IFSelect_SelectDeduct> (IFSelect_GraphCounter::*)() const) &IFSelect_GraphCounter::Applied, "Returns the applied selection");
cls_IFSelect_GraphCounter.def("SetApplied", (void (IFSelect_GraphCounter::*)(const opencascade::handle<IFSelect_SelectDeduct> &)) &IFSelect_GraphCounter::SetApplied, "Sets a new applied selection", py::arg("sel"));
cls_IFSelect_GraphCounter.def("AddWithGraph", (void (IFSelect_GraphCounter::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &, const Interface_Graph &)) &IFSelect_GraphCounter::AddWithGraph, "Adds a list of entities in the context given by the graph Default takes the count of entities selected by the applied selection, when it is given each entity of the list Can be redefined", py::arg("list"), py::arg("graph"));
cls_IFSelect_GraphCounter.def_static("get_type_name_", (const char * (*)()) &IFSelect_GraphCounter::get_type_name, "None");
cls_IFSelect_GraphCounter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_GraphCounter::get_type_descriptor, "None");
cls_IFSelect_GraphCounter.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_GraphCounter::*)() const) &IFSelect_GraphCounter::DynamicType, "None");

// CLASS: IFSELECT_SELECTION
py::class_<IFSelect_Selection, opencascade::handle<IFSelect_Selection>, Standard_Transient> cls_IFSelect_Selection(mod, "IFSelect_Selection", "A Selection allows to define a set of Interface Entities. Entities to be put on an output file should be identified in a way as independant from such or such execution as possible. This permits to handle comprehensive criteria, and to replay them when a new variant of an input file has to be processed.");

// Methods
cls_IFSelect_Selection.def("RootResult", (Interface_EntityIterator (IFSelect_Selection::*)(const Interface_Graph &) const) &IFSelect_Selection::RootResult, "Returns the list of selected entities, computed from Input given as a Graph. Specific to each class of Selection Note that uniqueness of each entity is not required here This method can raise an exception as necessary", py::arg("G"));
cls_IFSelect_Selection.def("UniqueResult", (Interface_EntityIterator (IFSelect_Selection::*)(const Interface_Graph &) const) &IFSelect_Selection::UniqueResult, "Returns the list of selected entities, each of them beeing unique. Default definition works from RootResult. According HasUniqueResult, UniqueResult returns directly RootResult, or build a Unique Result from it with a Graph.", py::arg("G"));
cls_IFSelect_Selection.def("CompleteResult", (Interface_EntityIterator (IFSelect_Selection::*)(const Interface_Graph &) const) &IFSelect_Selection::CompleteResult, "Returns the list of entities involved by a Selection, i.e. UniqueResult plus the shared entities (directly or not)", py::arg("G"));
cls_IFSelect_Selection.def("FillIterator", (void (IFSelect_Selection::*)(IFSelect_SelectionIterator &) const) &IFSelect_Selection::FillIterator, "Puts in an Iterator the Selections from which 'me' depends (there can be zero, or one, or a list). Specific to each class of Selection", py::arg("iter"));
cls_IFSelect_Selection.def("Label", (TCollection_AsciiString (IFSelect_Selection::*)() const) &IFSelect_Selection::Label, "Returns a text which defines the criterium applied by a Selection (can be used to be printed, displayed ...) Specific to each class");
cls_IFSelect_Selection.def_static("get_type_name_", (const char * (*)()) &IFSelect_Selection::get_type_name, "None");
cls_IFSelect_Selection.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_Selection::get_type_descriptor, "None");
cls_IFSelect_Selection.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_Selection::*)() const) &IFSelect_Selection::DynamicType, "None");

// TYPEDEF: IFSELECT_TSEQOFSELECTION
bind_NCollection_Sequence<opencascade::handle<IFSelect_Selection> >(mod, "IFSelect_TSeqOfSelection", py::module_local(false));

// CLASS: IFSELECT_HSEQOFSELECTION
py::class_<IFSelect_HSeqOfSelection, opencascade::handle<IFSelect_HSeqOfSelection>, Standard_Transient> cls_IFSelect_HSeqOfSelection(mod, "IFSelect_HSeqOfSelection", "None", py::multiple_inheritance());

// Constructors
cls_IFSelect_HSeqOfSelection.def(py::init<>());
cls_IFSelect_HSeqOfSelection.def(py::init<const IFSelect_TSeqOfSelection &>(), py::arg("theOther"));

// Methods
// cls_IFSelect_HSeqOfSelection.def_static("operator new_", (void * (*)(size_t)) &IFSelect_HSeqOfSelection::operator new, "None", py::arg("theSize"));
// cls_IFSelect_HSeqOfSelection.def_static("operator delete_", (void (*)(void *)) &IFSelect_HSeqOfSelection::operator delete, "None", py::arg("theAddress"));
// cls_IFSelect_HSeqOfSelection.def_static("operator new[]_", (void * (*)(size_t)) &IFSelect_HSeqOfSelection::operator new[], "None", py::arg("theSize"));
// cls_IFSelect_HSeqOfSelection.def_static("operator delete[]_", (void (*)(void *)) &IFSelect_HSeqOfSelection::operator delete[], "None", py::arg("theAddress"));
// cls_IFSelect_HSeqOfSelection.def_static("operator new_", (void * (*)(size_t, void *)) &IFSelect_HSeqOfSelection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IFSelect_HSeqOfSelection.def_static("operator delete_", (void (*)(void *, void *)) &IFSelect_HSeqOfSelection::operator delete, "None", py::arg(""), py::arg(""));
// cls_IFSelect_HSeqOfSelection.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &IFSelect_HSeqOfSelection::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_IFSelect_HSeqOfSelection.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &IFSelect_HSeqOfSelection::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_IFSelect_HSeqOfSelection.def("Sequence", (const IFSelect_TSeqOfSelection & (IFSelect_HSeqOfSelection::*)() const) &IFSelect_HSeqOfSelection::Sequence, "None");
cls_IFSelect_HSeqOfSelection.def("Append", (void (IFSelect_HSeqOfSelection::*)(const IFSelect_TSeqOfSelection::value_type &)) &IFSelect_HSeqOfSelection::Append, "None", py::arg("theItem"));
cls_IFSelect_HSeqOfSelection.def("Append", (void (IFSelect_HSeqOfSelection::*)(IFSelect_TSeqOfSelection &)) &IFSelect_HSeqOfSelection::Append, "None", py::arg("theSequence"));
cls_IFSelect_HSeqOfSelection.def("ChangeSequence", (IFSelect_TSeqOfSelection & (IFSelect_HSeqOfSelection::*)()) &IFSelect_HSeqOfSelection::ChangeSequence, "None");
cls_IFSelect_HSeqOfSelection.def_static("get_type_name_", (const char * (*)()) &IFSelect_HSeqOfSelection::get_type_name, "None");
cls_IFSelect_HSeqOfSelection.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_HSeqOfSelection::get_type_descriptor, "None");
cls_IFSelect_HSeqOfSelection.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_HSeqOfSelection::*)() const) &IFSelect_HSeqOfSelection::DynamicType, "None");

// CLASS: IFSELECT_INTPARAM
py::class_<IFSelect_IntParam, opencascade::handle<IFSelect_IntParam>, Standard_Transient> cls_IFSelect_IntParam(mod, "IFSelect_IntParam", "This class simply allows to access an Integer value through a Handle, as a String can be (by using HString). Hence, this value can be accessed : read and modified, without passing through the specific object which detains it. Thus, parameters of a Selection or a Dispatch (according its type) can be controlled directly from the ShareOut which contains them");

// Constructors
cls_IFSelect_IntParam.def(py::init<>());

// Methods
cls_IFSelect_IntParam.def("SetStaticName", (void (IFSelect_IntParam::*)(const Standard_CString)) &IFSelect_IntParam::SetStaticName, "Commands this IntParam to be bound to a Static Hence, Value will return the value if this Static if it is set Else, Value works on the locally stored value SetValue also will set the value of the Static This works only for a present static of type integer or enum Else, it is ignored", py::arg("statname"));
// cls_IFSelect_IntParam.def("StaticName", (Standard_CString (IFSelect_IntParam::*)() const) &IFSelect_IntParam::StaticName, "Returns the name of static parameter to which this IntParam is bound, empty if none");
cls_IFSelect_IntParam.def("Value", (Standard_Integer (IFSelect_IntParam::*)() const) &IFSelect_IntParam::Value, "Reads Integer Value of the IntParam. If a StaticName is defined and the Static is set, looks in priority the value of the static");
cls_IFSelect_IntParam.def("SetValue", (void (IFSelect_IntParam::*)(const Standard_Integer)) &IFSelect_IntParam::SetValue, "Sets a new Integer Value for the IntParam. If a StaticName is defined and the Static is set, also sets the value of the static", py::arg("val"));
cls_IFSelect_IntParam.def_static("get_type_name_", (const char * (*)()) &IFSelect_IntParam::get_type_name, "None");
cls_IFSelect_IntParam.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_IntParam::get_type_descriptor, "None");
cls_IFSelect_IntParam.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_IntParam::*)() const) &IFSelect_IntParam::DynamicType, "None");

// CLASS: IFSELECT_LISTEDITOR
py::class_<IFSelect_ListEditor, opencascade::handle<IFSelect_ListEditor>, Standard_Transient> cls_IFSelect_ListEditor(mod, "IFSelect_ListEditor", "A ListEditor is an auxiliary operator for Editor/EditForm I.E. it works on parameter values expressed as strings");

// Constructors
cls_IFSelect_ListEditor.def(py::init<>());
cls_IFSelect_ListEditor.def(py::init<const opencascade::handle<Interface_TypedValue> &>(), py::arg("def"));
cls_IFSelect_ListEditor.def(py::init<const opencascade::handle<Interface_TypedValue> &, const Standard_Integer>(), py::arg("def"), py::arg("max"));

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

// TYPEDEF: IFSELECT_SEQUENCEOFINTERFACEMODEL
bind_NCollection_Sequence<opencascade::handle<Interface_InterfaceModel> >(mod, "IFSelect_SequenceOfInterfaceModel", py::module_local(false));

// TYPEDEF: IFSELECT_SEQUENCEOFAPPLIEDMODIFIERS
bind_NCollection_Sequence<opencascade::handle<IFSelect_AppliedModifiers> >(mod, "IFSelect_SequenceOfAppliedModifiers", py::module_local(false));

// CLASS: IFSELECT_MODELCOPIER
py::class_<IFSelect_ModelCopier, opencascade::handle<IFSelect_ModelCopier>, Standard_Transient> cls_IFSelect_ModelCopier(mod, "IFSelect_ModelCopier", "This class performs the Copy operations involved by the description of a ShareOut (evaluated by a ShareOutResult) plus, if there are, the Modifications on the results, with the help of Modifiers. Each Modifier can work on one or more resulting packets, accoding its criteria : it operates on a Model once copied and filled with the content of the packet.");

// Constructors
cls_IFSelect_ModelCopier.def(py::init<>());

// Methods
cls_IFSelect_ModelCopier.def("SetShareOut", (void (IFSelect_ModelCopier::*)(const opencascade::handle<IFSelect_ShareOut> &)) &IFSelect_ModelCopier::SetShareOut, "Sets the ShareOut, which is used to define Modifiers to apply", py::arg("sho"));
cls_IFSelect_ModelCopier.def("ClearResult", (void (IFSelect_ModelCopier::*)()) &IFSelect_ModelCopier::ClearResult, "Clears the list of produced Models");
cls_IFSelect_ModelCopier.def("AddFile", (Standard_Boolean (IFSelect_ModelCopier::*)(const TCollection_AsciiString &, const opencascade::handle<Interface_InterfaceModel> &)) &IFSelect_ModelCopier::AddFile, "Records a new File to be sent, as a couple (Name as AsciiString, Content as InterfaceModel) Returns True if Done, False if <filename> is already attached to another File", py::arg("filename"), py::arg("content"));
cls_IFSelect_ModelCopier.def("NameFile", (Standard_Boolean (IFSelect_ModelCopier::*)(const Standard_Integer, const TCollection_AsciiString &)) &IFSelect_ModelCopier::NameFile, "Changes the Name attached to a File which was formerly defined by a call to AddFile Returns True if Done, False else : if <num> out of range or if the new <filename> is already attached to another File Remark : Giving an empty File Name is equivalent to ClearFile", py::arg("num"), py::arg("filename"));
cls_IFSelect_ModelCopier.def("ClearFile", (Standard_Boolean (IFSelect_ModelCopier::*)(const Standard_Integer)) &IFSelect_ModelCopier::ClearFile, "Clears the Name attached to a File which was formerly defined by a call to AddFile. This Clearing can be undone by a call to NameFile (with same <num>) Returns True if Done, False else : if <num> is out of range", py::arg("num"));
cls_IFSelect_ModelCopier.def("SetAppliedModifiers", (Standard_Boolean (IFSelect_ModelCopier::*)(const Standard_Integer, const opencascade::handle<IFSelect_AppliedModifiers> &)) &IFSelect_ModelCopier::SetAppliedModifiers, "Sets a list of File Modifiers to be applied on a file", py::arg("num"), py::arg("applied"));
cls_IFSelect_ModelCopier.def("ClearAppliedModifiers", (Standard_Boolean (IFSelect_ModelCopier::*)(const Standard_Integer)) &IFSelect_ModelCopier::ClearAppliedModifiers, "Clears the list of File Modifiers to be applied on a file", py::arg("num"));
cls_IFSelect_ModelCopier.def("Copy", (Interface_CheckIterator (IFSelect_ModelCopier::*)(IFSelect_ShareOutResult &, const opencascade::handle<IFSelect_WorkLibrary> &, const opencascade::handle<Interface_Protocol> &)) &IFSelect_ModelCopier::Copy, "Performs the Copy Operations, which include the Modifications defined by the list of Modifiers. Memorizes the result, as a list of InterfaceModels with the corresponding FileNames They can then be sent, by the method Send, or queried Copy calls internal method Copying. Returns the produced CheckList", py::arg("eval"), py::arg("WL"), py::arg("protocol"));
cls_IFSelect_ModelCopier.def("SendCopied", (Interface_CheckIterator (IFSelect_ModelCopier::*)(const opencascade::handle<IFSelect_WorkLibrary> &, const opencascade::handle<Interface_Protocol> &)) &IFSelect_ModelCopier::SendCopied, "Sends the formerly defined results (see method Copy) to files, then clears it Remark : A Null File Name cause file to be not produced", py::arg("WL"), py::arg("protocol"));
cls_IFSelect_ModelCopier.def("Send", (Interface_CheckIterator (IFSelect_ModelCopier::*)(IFSelect_ShareOutResult &, const opencascade::handle<IFSelect_WorkLibrary> &, const opencascade::handle<Interface_Protocol> &)) &IFSelect_ModelCopier::Send, "Performs the Copy Operations (which include the Modifications) and Sends the result on files, without memorizing it. (the memorized result is ignored : neither queried not filled)", py::arg("eval"), py::arg("WL"), py::arg("protocol"));
cls_IFSelect_ModelCopier.def("SendAll", (Interface_CheckIterator (IFSelect_ModelCopier::*)(const Standard_CString, const Interface_Graph &, const opencascade::handle<IFSelect_WorkLibrary> &, const opencascade::handle<Interface_Protocol> &)) &IFSelect_ModelCopier::SendAll, "Sends a model (defined in <G>) into one file, without managing remaining data, already sent files, etc. Applies the Model and File Modifiers. Returns True if well done, False else", py::arg("filename"), py::arg("G"), py::arg("WL"), py::arg("protocol"));
cls_IFSelect_ModelCopier.def("SendSelected", (Interface_CheckIterator (IFSelect_ModelCopier::*)(const Standard_CString, const Interface_Graph &, const opencascade::handle<IFSelect_WorkLibrary> &, const opencascade::handle<Interface_Protocol> &, const Interface_EntityIterator &)) &IFSelect_ModelCopier::SendSelected, "Sends a part of a model into one file. Model is gotten from <G>, the part is defined in <iter>. Remaining data are managed and can be later be worked on. Returns True if well done, False else", py::arg("filename"), py::arg("G"), py::arg("WL"), py::arg("protocol"), py::arg("iter"));
cls_IFSelect_ModelCopier.def("CopiedRemaining", (void (IFSelect_ModelCopier::*)(const Interface_Graph &, const opencascade::handle<IFSelect_WorkLibrary> &, Interface_CopyTool &, opencascade::handle<Interface_InterfaceModel> &)) &IFSelect_ModelCopier::CopiedRemaining, "Produces a Model copied from the Remaining List as <newmod> <newmod> is a Null Handle if this list is empty <WL> performs the copy by using <TC> <TC> is assumed to have been defined with the starting model same as defined by <G>.", py::arg("G"), py::arg("WL"), py::arg("TC"), py::arg("newmod"));
cls_IFSelect_ModelCopier.def("SetRemaining", (Standard_Boolean (IFSelect_ModelCopier::*)(Interface_Graph &) const) &IFSelect_ModelCopier::SetRemaining, "Updates Graph status for remaining data, for each entity : - Entities just Sent to file or Copied (by CopiedRemaining) have their status set to 1 - the other keep their former status (1 for Send/Copied, 0 for Remaining) These status are computed by Copying/Sending/CopiedRemaining Then, SetRemaining updates graph status, and mustr be called just after one of these method has been called Returns True if done, False if remaining info if not in phase which the Graph (not same counts of items)", py::arg("CG"));
cls_IFSelect_ModelCopier.def("NbFiles", (Standard_Integer (IFSelect_ModelCopier::*)() const) &IFSelect_ModelCopier::NbFiles, "Returns the count of Files produced, i.e. the count of Models memorized (produced by the mmethod Copy) with their file names");
cls_IFSelect_ModelCopier.def("FileName", (TCollection_AsciiString (IFSelect_ModelCopier::*)(const Standard_Integer) const) &IFSelect_ModelCopier::FileName, "Returns the File Name for a file given its rank It is empty after a call to ClearFile on same <num>", py::arg("num"));
cls_IFSelect_ModelCopier.def("FileModel", (opencascade::handle<Interface_InterfaceModel> (IFSelect_ModelCopier::*)(const Standard_Integer) const) &IFSelect_ModelCopier::FileModel, "Returns the content of a file before sending, under the form of an InterfaceModel, given its rank", py::arg("num"));
cls_IFSelect_ModelCopier.def("AppliedModifiers", (opencascade::handle<IFSelect_AppliedModifiers> (IFSelect_ModelCopier::*)(const Standard_Integer) const) &IFSelect_ModelCopier::AppliedModifiers, "Returns the list of File Modifiers to be applied on a file when it will be sent, as computed by CopiedModel : If it is a null handle, no File Modifier has to be applied.", py::arg("num"));
cls_IFSelect_ModelCopier.def("BeginSentFiles", (void (IFSelect_ModelCopier::*)(const opencascade::handle<IFSelect_ShareOut> &, const Standard_Boolean)) &IFSelect_ModelCopier::BeginSentFiles, "Begins a sequence of recording the really sent files <sho> : the default file numbering is cleared If <record> is False, clears the list and stops recording If <record> is True, clears the list and commands recording Creation time corresponds to 'stop recording'", py::arg("sho"), py::arg("record"));
cls_IFSelect_ModelCopier.def("AddSentFile", (void (IFSelect_ModelCopier::*)(const Standard_CString)) &IFSelect_ModelCopier::AddSentFile, "Adds the name of a just sent file, if BeginSentFiles has commanded recording; else does nothing It is called by methods SendCopied Sending", py::arg("filename"));
cls_IFSelect_ModelCopier.def("SentFiles", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (IFSelect_ModelCopier::*)() const) &IFSelect_ModelCopier::SentFiles, "Returns the list of recorded names of sent files. Can be empty (if no file has been sent). Returns a Null Handle if BeginSentFiles has stopped recording.");
cls_IFSelect_ModelCopier.def_static("get_type_name_", (const char * (*)()) &IFSelect_ModelCopier::get_type_name, "None");
cls_IFSelect_ModelCopier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_ModelCopier::get_type_descriptor, "None");
cls_IFSelect_ModelCopier.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_ModelCopier::*)() const) &IFSelect_ModelCopier::DynamicType, "None");

// CLASS: IFSELECT_MODIFIER
py::class_<IFSelect_Modifier, opencascade::handle<IFSelect_Modifier>, IFSelect_GeneralModifier> cls_IFSelect_Modifier(mod, "IFSelect_Modifier", "This class gives a frame for Actions which can work globally on a File once completely defined (i.e. afterwards)");

// Methods
cls_IFSelect_Modifier.def("Perform", (void (IFSelect_Modifier::*)(IFSelect_ContextModif &, const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &, Interface_CopyTool &) const) &IFSelect_Modifier::Perform, "This deferred method defines the action specific to each class of Modifier. It is called by a ModelCopier, once the Model generated and filled. ModelCopier has already checked the criteria (Dispatch, Model Rank, Selection) before calling it.", py::arg("ctx"), py::arg("target"), py::arg("protocol"), py::arg("TC"));
cls_IFSelect_Modifier.def_static("get_type_name_", (const char * (*)()) &IFSelect_Modifier::get_type_name, "None");
cls_IFSelect_Modifier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_Modifier::get_type_descriptor, "None");
cls_IFSelect_Modifier.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_Modifier::*)() const) &IFSelect_Modifier::DynamicType, "None");

// CLASS: IFSELECT_MODIFEDITFORM
py::class_<IFSelect_ModifEditForm, opencascade::handle<IFSelect_ModifEditForm>, IFSelect_Modifier> cls_IFSelect_ModifEditForm(mod, "IFSelect_ModifEditForm", "This modifier applies an EditForm on the entities selected");

// Constructors
cls_IFSelect_ModifEditForm.def(py::init<const opencascade::handle<IFSelect_EditForm> &>(), py::arg("editform"));

// Methods
cls_IFSelect_ModifEditForm.def("EditForm", (opencascade::handle<IFSelect_EditForm> (IFSelect_ModifEditForm::*)() const) &IFSelect_ModifEditForm::EditForm, "Returns the EditForm");
cls_IFSelect_ModifEditForm.def("Perform", (void (IFSelect_ModifEditForm::*)(IFSelect_ContextModif &, const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &, Interface_CopyTool &) const) &IFSelect_ModifEditForm::Perform, "Acts by applying an EditForm to entities, selected or all model", py::arg("ctx"), py::arg("target"), py::arg("protocol"), py::arg("TC"));
cls_IFSelect_ModifEditForm.def("Label", (TCollection_AsciiString (IFSelect_ModifEditForm::*)() const) &IFSelect_ModifEditForm::Label, "Returns Label as 'Apply EditForm <+ label of EditForm>'");
cls_IFSelect_ModifEditForm.def_static("get_type_name_", (const char * (*)()) &IFSelect_ModifEditForm::get_type_name, "None");
cls_IFSelect_ModifEditForm.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_ModifEditForm::get_type_descriptor, "None");
cls_IFSelect_ModifEditForm.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_ModifEditForm::*)() const) &IFSelect_ModifEditForm::DynamicType, "None");

// CLASS: IFSELECT_MODIFREORDER
py::class_<IFSelect_ModifReorder, opencascade::handle<IFSelect_ModifReorder>, IFSelect_Modifier> cls_IFSelect_ModifReorder(mod, "IFSelect_ModifReorder", "This modifier reorders a whole model from its roots, i.e. according to <rootlast> status, it considers each of its roots, then it orders all its shared entities at any level, the result begins by the lower level entities ... ends by the roots.");

// Constructors
cls_IFSelect_ModifReorder.def(py::init<>());
cls_IFSelect_ModifReorder.def(py::init<const Standard_Boolean>(), py::arg("rootlast"));

// Methods
cls_IFSelect_ModifReorder.def("Perform", (void (IFSelect_ModifReorder::*)(IFSelect_ContextModif &, const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &, Interface_CopyTool &) const) &IFSelect_ModifReorder::Perform, "Acts by computing orders (by method All from ShareTool) then forcing them in the model. Remark that selection is ignored : ALL the model is processed in once", py::arg("ctx"), py::arg("target"), py::arg("protocol"), py::arg("TC"));
cls_IFSelect_ModifReorder.def("Label", (TCollection_AsciiString (IFSelect_ModifReorder::*)() const) &IFSelect_ModifReorder::Label, "Returns Label as 'Reorder, Roots (last or first)'");
cls_IFSelect_ModifReorder.def_static("get_type_name_", (const char * (*)()) &IFSelect_ModifReorder::get_type_name, "None");
cls_IFSelect_ModifReorder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_ModifReorder::get_type_descriptor, "None");
cls_IFSelect_ModifReorder.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_ModifReorder::*)() const) &IFSelect_ModifReorder::DynamicType, "None");

// CLASS: IFSELECT_PACKETLIST
py::class_<IFSelect_PacketList, opencascade::handle<IFSelect_PacketList>, Standard_Transient> cls_IFSelect_PacketList(mod, "IFSelect_PacketList", "This class gives a simple way to return then consult a list of packets, determined from the content of a Model, by various criteria.");

// Constructors
cls_IFSelect_PacketList.def(py::init<const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("model"));

// Methods
cls_IFSelect_PacketList.def("SetName", (void (IFSelect_PacketList::*)(const Standard_CString)) &IFSelect_PacketList::SetName, "Sets a name to a packet list : this makes easier a general routine to print it. Default is 'Packets'", py::arg("name"));
cls_IFSelect_PacketList.def("Name", (Standard_CString (IFSelect_PacketList::*)() const) &IFSelect_PacketList::Name, "Returns the recorded name for a packet list");
cls_IFSelect_PacketList.def("Model", (opencascade::handle<Interface_InterfaceModel> (IFSelect_PacketList::*)() const) &IFSelect_PacketList::Model, "Returns the Model of reference");
cls_IFSelect_PacketList.def("AddPacket", (void (IFSelect_PacketList::*)()) &IFSelect_PacketList::AddPacket, "Declares a new Packet, ready to be filled The entities to be added will be added to this Packet");
cls_IFSelect_PacketList.def("Add", (void (IFSelect_PacketList::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_PacketList::Add, "Adds an entity from the Model into the current packet for Add", py::arg("ent"));
cls_IFSelect_PacketList.def("AddList", (void (IFSelect_PacketList::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &)) &IFSelect_PacketList::AddList, "Adds an list of entities into the current packet for Add", py::arg("list"));
cls_IFSelect_PacketList.def("NbPackets", (Standard_Integer (IFSelect_PacketList::*)() const) &IFSelect_PacketList::NbPackets, "Returns the count of non-empty packets");
cls_IFSelect_PacketList.def("NbEntities", (Standard_Integer (IFSelect_PacketList::*)(const Standard_Integer) const) &IFSelect_PacketList::NbEntities, "Returns the count of entities in a Packet given its rank, or 0", py::arg("numpack"));
cls_IFSelect_PacketList.def("Entities", (Interface_EntityIterator (IFSelect_PacketList::*)(const Standard_Integer) const) &IFSelect_PacketList::Entities, "Returns the content of a Packet given its rank Null Handle if <numpack> is out of range", py::arg("numpack"));
cls_IFSelect_PacketList.def("HighestDuplicationCount", (Standard_Integer (IFSelect_PacketList::*)() const) &IFSelect_PacketList::HighestDuplicationCount, "Returns the highest number of packets which know a same entity For no duplication, should be one");
cls_IFSelect_PacketList.def("NbDuplicated", (Standard_Integer (IFSelect_PacketList::*)(const Standard_Integer, const Standard_Boolean) const) &IFSelect_PacketList::NbDuplicated, "Returns the count of entities duplicated : <count> times, if <andmore> is False, or <count> or more times, if <andmore> is True See Duplicated for more details", py::arg("count"), py::arg("andmore"));
cls_IFSelect_PacketList.def("Duplicated", (Interface_EntityIterator (IFSelect_PacketList::*)(const Standard_Integer, const Standard_Boolean) const) &IFSelect_PacketList::Duplicated, "Returns a list of entities duplicated : <count> times, if <andmore> is False, or <count> or more times, if <andmore> is True Hence, count=2 & andmore=True gives all duplicated entities count=1 gives non-duplicated entities (in only one packet) count=0 gives remaining entities (in no packet at all)", py::arg("count"), py::arg("andmore"));
cls_IFSelect_PacketList.def_static("get_type_name_", (const char * (*)()) &IFSelect_PacketList::get_type_name, "None");
cls_IFSelect_PacketList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_PacketList::get_type_descriptor, "None");
cls_IFSelect_PacketList.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_PacketList::*)() const) &IFSelect_PacketList::DynamicType, "None");

// CLASS: IFSELECT_PARAMEDITOR
py::class_<IFSelect_ParamEditor, opencascade::handle<IFSelect_ParamEditor>, IFSelect_Editor> cls_IFSelect_ParamEditor(mod, "IFSelect_ParamEditor", "A ParamEditor gives access for edition to a list of TypedValue (i.e. of Static too) Its definition is made of the TypedValue to edit themselves, and can add some constants, which can then be displayed but not changed (for instance, system name, processor version ...)");

// Constructors
cls_IFSelect_ParamEditor.def(py::init<>());
cls_IFSelect_ParamEditor.def(py::init<const Standard_Integer>(), py::arg("nbmax"));
cls_IFSelect_ParamEditor.def(py::init<const Standard_Integer, const Standard_CString>(), py::arg("nbmax"), py::arg("label"));

// Methods
cls_IFSelect_ParamEditor.def("AddValue", [](IFSelect_ParamEditor &self, const opencascade::handle<Interface_TypedValue> & a0) -> void { return self.AddValue(a0); });
cls_IFSelect_ParamEditor.def("AddValue", (void (IFSelect_ParamEditor::*)(const opencascade::handle<Interface_TypedValue> &, const Standard_CString)) &IFSelect_ParamEditor::AddValue, "Adds a TypedValue By default, its short name equates its complete name, it can be explicited", py::arg("val"), py::arg("shortname"));
cls_IFSelect_ParamEditor.def("AddConstantText", [](IFSelect_ParamEditor &self, const Standard_CString a0, const Standard_CString a1) -> void { return self.AddConstantText(a0, a1); });
cls_IFSelect_ParamEditor.def("AddConstantText", (void (IFSelect_ParamEditor::*)(const Standard_CString, const Standard_CString, const Standard_CString)) &IFSelect_ParamEditor::AddConstantText, "Adds a Constant Text, it will be Read Only By default, its long name equates its shortname", py::arg("val"), py::arg("shortname"), py::arg("completename"));
cls_IFSelect_ParamEditor.def("Label", (TCollection_AsciiString (IFSelect_ParamEditor::*)() const) &IFSelect_ParamEditor::Label, "None");
cls_IFSelect_ParamEditor.def("Recognize", (Standard_Boolean (IFSelect_ParamEditor::*)(const opencascade::handle<IFSelect_EditForm> &) const) &IFSelect_ParamEditor::Recognize, "None", py::arg("form"));
cls_IFSelect_ParamEditor.def("StringValue", (opencascade::handle<TCollection_HAsciiString> (IFSelect_ParamEditor::*)(const opencascade::handle<IFSelect_EditForm> &, const Standard_Integer) const) &IFSelect_ParamEditor::StringValue, "None", py::arg("form"), py::arg("num"));
cls_IFSelect_ParamEditor.def("Load", (Standard_Boolean (IFSelect_ParamEditor::*)(const opencascade::handle<IFSelect_EditForm> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_ParamEditor::Load, "None", py::arg("form"), py::arg("ent"), py::arg("model"));
cls_IFSelect_ParamEditor.def("Apply", (Standard_Boolean (IFSelect_ParamEditor::*)(const opencascade::handle<IFSelect_EditForm> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_ParamEditor::Apply, "None", py::arg("form"), py::arg("ent"), py::arg("model"));
cls_IFSelect_ParamEditor.def_static("StaticEditor_", [](const opencascade::handle<TColStd_HSequenceOfHAsciiString> & a0) -> opencascade::handle<IFSelect_ParamEditor> { return IFSelect_ParamEditor::StaticEditor(a0); });
cls_IFSelect_ParamEditor.def_static("StaticEditor_", (opencascade::handle<IFSelect_ParamEditor> (*)(const opencascade::handle<TColStd_HSequenceOfHAsciiString> &, const Standard_CString)) &IFSelect_ParamEditor::StaticEditor, "Returns a ParamEditor to work on the Static Parameters of which names are listed in <list> Null Handle if <list> is null or empty", py::arg("list"), py::arg("label"));
cls_IFSelect_ParamEditor.def_static("get_type_name_", (const char * (*)()) &IFSelect_ParamEditor::get_type_name, "None");
cls_IFSelect_ParamEditor.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_ParamEditor::get_type_descriptor, "None");
cls_IFSelect_ParamEditor.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_ParamEditor::*)() const) &IFSelect_ParamEditor::DynamicType, "None");

// CLASS: IFSELECT_SELECTDEDUCT
py::class_<IFSelect_SelectDeduct, opencascade::handle<IFSelect_SelectDeduct>, IFSelect_Selection> cls_IFSelect_SelectDeduct(mod, "IFSelect_SelectDeduct", "A SelectDeduct determines a list of Entities from an Input Selection, by a computation : Output list is not obliged to be a sub-list of Input list (for more specific, see SelectExtract for filtered sub-lists, and SelectExplore for recurcive exploration)");

// Methods
cls_IFSelect_SelectDeduct.def("SetInput", (void (IFSelect_SelectDeduct::*)(const opencascade::handle<IFSelect_Selection> &)) &IFSelect_SelectDeduct::SetInput, "Defines or Changes the Input Selection", py::arg("sel"));
cls_IFSelect_SelectDeduct.def("Input", (opencascade::handle<IFSelect_Selection> (IFSelect_SelectDeduct::*)() const) &IFSelect_SelectDeduct::Input, "Returns the Input Selection");
cls_IFSelect_SelectDeduct.def("HasInput", (Standard_Boolean (IFSelect_SelectDeduct::*)() const) &IFSelect_SelectDeduct::HasInput, "Returns True if the Input Selection is defined, False else");
cls_IFSelect_SelectDeduct.def("HasAlternate", (Standard_Boolean (IFSelect_SelectDeduct::*)() const) &IFSelect_SelectDeduct::HasAlternate, "Tells if an Alternate List has been set, i.e. : the Alternate Definition is present and set");
cls_IFSelect_SelectDeduct.def("Alternate", (opencascade::handle<IFSelect_SelectPointed> & (IFSelect_SelectDeduct::*)()) &IFSelect_SelectDeduct::Alternate, "Returns the Alternate Definition It is returned modifiable, hence an already defined SelectPointed can be used But if it was not yet defined, it is created the first time");
cls_IFSelect_SelectDeduct.def("InputResult", (Interface_EntityIterator (IFSelect_SelectDeduct::*)(const Interface_Graph &) const) &IFSelect_SelectDeduct::InputResult, "Returns the Result determined by Input Selection, as Unique if Input Selection is not defined, returns an empty list.", py::arg("G"));
cls_IFSelect_SelectDeduct.def("FillIterator", (void (IFSelect_SelectDeduct::*)(IFSelect_SelectionIterator &) const) &IFSelect_SelectDeduct::FillIterator, "Puts in an Iterator the Selections from which 'me' depends This list contains one Selection : the InputSelection", py::arg("iter"));
cls_IFSelect_SelectDeduct.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectDeduct::get_type_name, "None");
cls_IFSelect_SelectDeduct.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectDeduct::get_type_descriptor, "None");
cls_IFSelect_SelectDeduct.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectDeduct::*)() const) &IFSelect_SelectDeduct::DynamicType, "None");

// CLASS: IFSELECT_SELECTANYLIST
py::class_<IFSelect_SelectAnyList, opencascade::handle<IFSelect_SelectAnyList>, IFSelect_SelectDeduct> cls_IFSelect_SelectAnyList(mod, "IFSelect_SelectAnyList", "A SelectAnyList kind Selection selects a List of an Entity, as well as this Entity contains some. A List contains sub-entities as one per Item, or several (for instance if an Entity binds couples of sub-entities, each item is one of these couples). Remark that only Entities are taken into account (neither Reals, nor Strings, etc...)");

// Methods
cls_IFSelect_SelectAnyList.def("KeepInputEntity", (void (IFSelect_SelectAnyList::*)(Interface_EntityIterator &) const) &IFSelect_SelectAnyList::KeepInputEntity, "Keeps Input Entity, as having required type. It works by keeping in <iter>, only suitable Entities (SelectType can be used). Called by RootResult (which waits for ONE ENTITY MAX)", py::arg("iter"));
cls_IFSelect_SelectAnyList.def("NbItems", (Standard_Integer (IFSelect_SelectAnyList::*)(const opencascade::handle<Standard_Transient> &) const) &IFSelect_SelectAnyList::NbItems, "Returns count of Items in the list in the Entity <ent> If <ent> has not required type, returned value must be Zero", py::arg("ent"));
cls_IFSelect_SelectAnyList.def("SetRange", (void (IFSelect_SelectAnyList::*)(const opencascade::handle<IFSelect_IntParam> &, const opencascade::handle<IFSelect_IntParam> &)) &IFSelect_SelectAnyList::SetRange, "Sets a Range for numbers, with a lower and a upper limits", py::arg("rankfrom"), py::arg("rankto"));
cls_IFSelect_SelectAnyList.def("SetOne", (void (IFSelect_SelectAnyList::*)(const opencascade::handle<IFSelect_IntParam> &)) &IFSelect_SelectAnyList::SetOne, "Sets a unique number (only one Entity will be sorted as True)", py::arg("rank"));
cls_IFSelect_SelectAnyList.def("SetFrom", (void (IFSelect_SelectAnyList::*)(const opencascade::handle<IFSelect_IntParam> &)) &IFSelect_SelectAnyList::SetFrom, "Sets a Lower limit but no upper limit", py::arg("rankfrom"));
cls_IFSelect_SelectAnyList.def("SetUntil", (void (IFSelect_SelectAnyList::*)(const opencascade::handle<IFSelect_IntParam> &)) &IFSelect_SelectAnyList::SetUntil, "Sets an Upper limit but no lower limit (equivalent to lower 1)", py::arg("rankto"));
cls_IFSelect_SelectAnyList.def("HasLower", (Standard_Boolean (IFSelect_SelectAnyList::*)() const) &IFSelect_SelectAnyList::HasLower, "Returns True if a Lower limit is defined");
cls_IFSelect_SelectAnyList.def("Lower", (opencascade::handle<IFSelect_IntParam> (IFSelect_SelectAnyList::*)() const) &IFSelect_SelectAnyList::Lower, "Returns Lower limit (if there is; else, value is senseless)");
cls_IFSelect_SelectAnyList.def("LowerValue", (Standard_Integer (IFSelect_SelectAnyList::*)() const) &IFSelect_SelectAnyList::LowerValue, "Returns Integer Value of Lower Limit (0 if none)");
cls_IFSelect_SelectAnyList.def("HasUpper", (Standard_Boolean (IFSelect_SelectAnyList::*)() const) &IFSelect_SelectAnyList::HasUpper, "Returns True if a Lower limit is defined");
cls_IFSelect_SelectAnyList.def("Upper", (opencascade::handle<IFSelect_IntParam> (IFSelect_SelectAnyList::*)() const) &IFSelect_SelectAnyList::Upper, "Returns Upper limit (if there is; else, value is senseless)");
cls_IFSelect_SelectAnyList.def("UpperValue", (Standard_Integer (IFSelect_SelectAnyList::*)() const) &IFSelect_SelectAnyList::UpperValue, "Returns Integer Value of Upper Limit (0 if none)");
cls_IFSelect_SelectAnyList.def("RootResult", (Interface_EntityIterator (IFSelect_SelectAnyList::*)(const Interface_Graph &) const) &IFSelect_SelectAnyList::RootResult, "Returns the list of selected entities (list of entities complying with rank criterium) Error if the input list has more than one Item", py::arg("G"));
cls_IFSelect_SelectAnyList.def("FillResult", (void (IFSelect_SelectAnyList::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<Standard_Transient> &, Interface_EntityIterator &) const) &IFSelect_SelectAnyList::FillResult, "Puts into <res>, the sub-entities of the list, from n1 to n2 included. Remark that adequation with Entity's type and length of list has already been made at this stage Called by RootResult", py::arg("n1"), py::arg("n2"), py::arg("ent"), py::arg("res"));
cls_IFSelect_SelectAnyList.def("Label", (TCollection_AsciiString (IFSelect_SelectAnyList::*)() const) &IFSelect_SelectAnyList::Label, "Returns a text defining the criterium : 'Componants of List ' then Specific List Label, then, following cases : ' From .. Until ..' or 'From ..' or 'Until ..' or 'Rank no ..' Specific type is given by deferred method ListLabel");
cls_IFSelect_SelectAnyList.def("ListLabel", (TCollection_AsciiString (IFSelect_SelectAnyList::*)() const) &IFSelect_SelectAnyList::ListLabel, "Returns the specific label for the list, which is included as a part of Label");
cls_IFSelect_SelectAnyList.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectAnyList::get_type_name, "None");
cls_IFSelect_SelectAnyList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectAnyList::get_type_descriptor, "None");
cls_IFSelect_SelectAnyList.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectAnyList::*)() const) &IFSelect_SelectAnyList::DynamicType, "None");

// CLASS: IFSELECT_SELECTEXTRACT
py::class_<IFSelect_SelectExtract, opencascade::handle<IFSelect_SelectExtract>, IFSelect_SelectDeduct> cls_IFSelect_SelectExtract(mod, "IFSelect_SelectExtract", "A SelectExtract determines a list of Entities from an Input Selection, as a sub-list of the Input Result It works by applying a sort criterium on each Entity of the Input. This criterium can be applied Direct to Pick Items (default case) or Reverse to Remove Item");

// Methods
cls_IFSelect_SelectExtract.def("IsDirect", (Standard_Boolean (IFSelect_SelectExtract::*)() const) &IFSelect_SelectExtract::IsDirect, "Returns True if Sort criterium is Direct, False if Reverse");
cls_IFSelect_SelectExtract.def("SetDirect", (void (IFSelect_SelectExtract::*)(const Standard_Boolean)) &IFSelect_SelectExtract::SetDirect, "Sets Sort criterium sense to a new value (True : Direct , False : Reverse)", py::arg("direct"));
cls_IFSelect_SelectExtract.def("RootResult", (Interface_EntityIterator (IFSelect_SelectExtract::*)(const Interface_Graph &) const) &IFSelect_SelectExtract::RootResult, "Returns the list of selected entities. Works by calling the method Sort on each input Entity : the Entity is kept as output if Sort returns the same value as Direct status", py::arg("G"));
cls_IFSelect_SelectExtract.def("Sort", (Standard_Boolean (IFSelect_SelectExtract::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_SelectExtract::Sort, "Returns True for an Entity if it satisfies the Sort criterium It receives : - <rank>, the rank of the Entity in the Iteration, - <ent> , the Entity itself, and - <model>, the Starting Model Hence, the Entity to check is 'model->Value(num)' (but an InterfaceModel allows other checks) This method is specific to each class of SelectExtract", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_IFSelect_SelectExtract.def("SortInGraph", (Standard_Boolean (IFSelect_SelectExtract::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_Graph &) const) &IFSelect_SelectExtract::SortInGraph, "Works as Sort but works on the Graph Default directly calls Sort, but it can be redefined If SortInGraph is redefined, Sort should be defined even if not called (to avoid deferred methods in a final class)", py::arg("rank"), py::arg("ent"), py::arg("G"));
cls_IFSelect_SelectExtract.def("Label", (TCollection_AsciiString (IFSelect_SelectExtract::*)() const) &IFSelect_SelectExtract::Label, "Returns a text saying 'Picked' or 'Removed', plus the specific criterium returned by ExtractLabel (see below)");
cls_IFSelect_SelectExtract.def("ExtractLabel", (TCollection_AsciiString (IFSelect_SelectExtract::*)() const) &IFSelect_SelectExtract::ExtractLabel, "Returns a text defining the criterium for extraction");
cls_IFSelect_SelectExtract.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectExtract::get_type_name, "None");
cls_IFSelect_SelectExtract.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectExtract::get_type_descriptor, "None");
cls_IFSelect_SelectExtract.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectExtract::*)() const) &IFSelect_SelectExtract::DynamicType, "None");

// CLASS: IFSELECT_SELECTANYTYPE
py::class_<IFSelect_SelectAnyType, opencascade::handle<IFSelect_SelectAnyType>, IFSelect_SelectExtract> cls_IFSelect_SelectAnyType(mod, "IFSelect_SelectAnyType", "A SelectAnyType sorts the Entities of which the Type is Kind of a given Type : this Type for Match is specific of each class of SelectAnyType");

// Methods
cls_IFSelect_SelectAnyType.def("TypeForMatch", (opencascade::handle<Standard_Type> (IFSelect_SelectAnyType::*)() const) &IFSelect_SelectAnyType::TypeForMatch, "Returns the Type which has to be matched for select");
cls_IFSelect_SelectAnyType.def("Sort", (Standard_Boolean (IFSelect_SelectAnyType::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_SelectAnyType::Sort, "Returns True for an Entity (model->Value(num)) which is kind of the choosen type, given by the method TypeForMatch. Criterium is IsKind.", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_IFSelect_SelectAnyType.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectAnyType::get_type_name, "None");
cls_IFSelect_SelectAnyType.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectAnyType::get_type_descriptor, "None");
cls_IFSelect_SelectAnyType.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectAnyType::*)() const) &IFSelect_SelectAnyType::DynamicType, "None");

// CLASS: IFSELECT_SELECTBASE
py::class_<IFSelect_SelectBase, opencascade::handle<IFSelect_SelectBase>, IFSelect_Selection> cls_IFSelect_SelectBase(mod, "IFSelect_SelectBase", "SelectBase works directly from an InterfaceModel : it is the first base for other Selections.");

// Methods
cls_IFSelect_SelectBase.def("FillIterator", (void (IFSelect_SelectBase::*)(IFSelect_SelectionIterator &) const) &IFSelect_SelectBase::FillIterator, "Puts in an Iterator the Selections from which 'me' depends This list is empty for all SelectBase type Selections", py::arg("iter"));
cls_IFSelect_SelectBase.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectBase::get_type_name, "None");
cls_IFSelect_SelectBase.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectBase::get_type_descriptor, "None");
cls_IFSelect_SelectBase.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectBase::*)() const) &IFSelect_SelectBase::DynamicType, "None");

// CLASS: IFSELECT_SELECTCOMBINE
py::class_<IFSelect_SelectCombine, opencascade::handle<IFSelect_SelectCombine>, IFSelect_Selection> cls_IFSelect_SelectCombine(mod, "IFSelect_SelectCombine", "A SelectCombine type Selection defines algebraic operations between results of several Selections It is a deferred class : sub-classes will have to define precise what operator is to be applied");

// Methods
cls_IFSelect_SelectCombine.def("NbInputs", (Standard_Integer (IFSelect_SelectCombine::*)() const) &IFSelect_SelectCombine::NbInputs, "Returns the count of Input Selections");
cls_IFSelect_SelectCombine.def("Input", (opencascade::handle<IFSelect_Selection> (IFSelect_SelectCombine::*)(const Standard_Integer) const) &IFSelect_SelectCombine::Input, "Returns an Input Selection, given its rank in the list", py::arg("num"));
cls_IFSelect_SelectCombine.def("InputRank", (Standard_Integer (IFSelect_SelectCombine::*)(const opencascade::handle<IFSelect_Selection> &) const) &IFSelect_SelectCombine::InputRank, "Returns the rank of an input Selection, 0 if not in the list. Most generally, its value is meaningless, except for testing the presence of an input Selection : - == 0 if <sel> is not an input for <me> - > 0 if <sel> is an input for <me>", py::arg("sel"));
cls_IFSelect_SelectCombine.def("Add", [](IFSelect_SelectCombine &self, const opencascade::handle<IFSelect_Selection> & a0) -> void { return self.Add(a0); });
cls_IFSelect_SelectCombine.def("Add", (void (IFSelect_SelectCombine::*)(const opencascade::handle<IFSelect_Selection> &, const Standard_Integer)) &IFSelect_SelectCombine::Add, "Adds a Selection to the filling list By default, adds it to the end of the list A Positive rank less then NbInputs gives an insertion rank (InsertBefore : the new <atnum>th item of the list is <sel>)", py::arg("sel"), py::arg("atnum"));
cls_IFSelect_SelectCombine.def("Remove", (Standard_Boolean (IFSelect_SelectCombine::*)(const opencascade::handle<IFSelect_Selection> &)) &IFSelect_SelectCombine::Remove, "Removes an input Selection. Returns True if Done, False, if <sel> is not an input for <me>", py::arg("sel"));
cls_IFSelect_SelectCombine.def("Remove", (Standard_Boolean (IFSelect_SelectCombine::*)(const Standard_Integer)) &IFSelect_SelectCombine::Remove, "Removes an input Selection, given its rank in the list Returns True if Done, False if <num> is out of range", py::arg("num"));
cls_IFSelect_SelectCombine.def("FillIterator", (void (IFSelect_SelectCombine::*)(IFSelect_SelectionIterator &) const) &IFSelect_SelectCombine::FillIterator, "Puts in an Iterator the Selections from which 'me' depends That is to say, the list of Input Selections", py::arg("iter"));
cls_IFSelect_SelectCombine.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectCombine::get_type_name, "None");
cls_IFSelect_SelectCombine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectCombine::get_type_descriptor, "None");
cls_IFSelect_SelectCombine.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectCombine::*)() const) &IFSelect_SelectCombine::DynamicType, "None");

// CLASS: IFSELECT_SELECTCONTROL
py::class_<IFSelect_SelectControl, opencascade::handle<IFSelect_SelectControl>, IFSelect_Selection> cls_IFSelect_SelectControl(mod, "IFSelect_SelectControl", "A SelectControl kind Selection works with two input Selections in a dissymmetric way : the Main Input which gives an input list of Entities, to be processed, and the Second Input which gives another list, to be used to filter the main input.");

// Methods
cls_IFSelect_SelectControl.def("MainInput", (opencascade::handle<IFSelect_Selection> (IFSelect_SelectControl::*)() const) &IFSelect_SelectControl::MainInput, "Returns the Main Input Selection");
cls_IFSelect_SelectControl.def("HasSecondInput", (Standard_Boolean (IFSelect_SelectControl::*)() const) &IFSelect_SelectControl::HasSecondInput, "Returns True if a Control Input is defined Thus, Result can be computed differently if there is a Control Input or if there is none");
cls_IFSelect_SelectControl.def("SecondInput", (opencascade::handle<IFSelect_Selection> (IFSelect_SelectControl::*)() const) &IFSelect_SelectControl::SecondInput, "Returns the Control Input Selection, or a Null Handle");
cls_IFSelect_SelectControl.def("SetMainInput", (void (IFSelect_SelectControl::*)(const opencascade::handle<IFSelect_Selection> &)) &IFSelect_SelectControl::SetMainInput, "Sets a Selection to be the Main Input", py::arg("sel"));
cls_IFSelect_SelectControl.def("SetSecondInput", (void (IFSelect_SelectControl::*)(const opencascade::handle<IFSelect_Selection> &)) &IFSelect_SelectControl::SetSecondInput, "Sets a Selection to be the Control Input", py::arg("sel"));
cls_IFSelect_SelectControl.def("FillIterator", (void (IFSelect_SelectControl::*)(IFSelect_SelectionIterator &) const) &IFSelect_SelectControl::FillIterator, "Puts in an Iterator the Selections from which 'me' depends That is to say, the list of Input Selections", py::arg("iter"));
cls_IFSelect_SelectControl.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectControl::get_type_name, "None");
cls_IFSelect_SelectControl.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectControl::get_type_descriptor, "None");
cls_IFSelect_SelectControl.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectControl::*)() const) &IFSelect_SelectControl::DynamicType, "None");

// CLASS: IFSELECT_SELECTDIFF
py::class_<IFSelect_SelectDiff, opencascade::handle<IFSelect_SelectDiff>, IFSelect_SelectControl> cls_IFSelect_SelectDiff(mod, "IFSelect_SelectDiff", "A SelectDiff keeps the entities from a Selection, the Main Input, which are not listed by the Second Input");

// Constructors
cls_IFSelect_SelectDiff.def(py::init<>());

// Methods
cls_IFSelect_SelectDiff.def("RootResult", (Interface_EntityIterator (IFSelect_SelectDiff::*)(const Interface_Graph &) const) &IFSelect_SelectDiff::RootResult, "Returns the list of selected entities : they are the Entities gotten from the Main Input but not from the Diff Input", py::arg("G"));
cls_IFSelect_SelectDiff.def("Label", (TCollection_AsciiString (IFSelect_SelectDiff::*)() const) &IFSelect_SelectDiff::Label, "Returns a text defining the criterium : 'Difference'");
cls_IFSelect_SelectDiff.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectDiff::get_type_name, "None");
cls_IFSelect_SelectDiff.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectDiff::get_type_descriptor, "None");
cls_IFSelect_SelectDiff.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectDiff::*)() const) &IFSelect_SelectDiff::DynamicType, "None");

// CLASS: IFSELECT_SELECTENTITYNUMBER
py::class_<IFSelect_SelectEntityNumber, opencascade::handle<IFSelect_SelectEntityNumber>, IFSelect_SelectBase> cls_IFSelect_SelectEntityNumber(mod, "IFSelect_SelectEntityNumber", "A SelectEntityNumber gets in an InterfaceModel (through a Graph), the Entity which has a specified Number (its rank of adding into the Model) : there can be zero (if none) or one. The Number is not directly defined as an Integer, but as a Parameter, which can be externally controled");

// Constructors
cls_IFSelect_SelectEntityNumber.def(py::init<>());

// Methods
cls_IFSelect_SelectEntityNumber.def("SetNumber", (void (IFSelect_SelectEntityNumber::*)(const opencascade::handle<IFSelect_IntParam> &)) &IFSelect_SelectEntityNumber::SetNumber, "Sets Entity Number to be taken (initially, none is set : 0)", py::arg("num"));
cls_IFSelect_SelectEntityNumber.def("Number", (opencascade::handle<IFSelect_IntParam> (IFSelect_SelectEntityNumber::*)() const) &IFSelect_SelectEntityNumber::Number, "Returns specified Number (as a Parameter)");
cls_IFSelect_SelectEntityNumber.def("RootResult", (Interface_EntityIterator (IFSelect_SelectEntityNumber::*)(const Interface_Graph &) const) &IFSelect_SelectEntityNumber::RootResult, "Returns the list of selected entities : the Entity having the specified Number (this result assures naturally uniqueness)", py::arg("G"));
cls_IFSelect_SelectEntityNumber.def("Label", (TCollection_AsciiString (IFSelect_SelectEntityNumber::*)() const) &IFSelect_SelectEntityNumber::Label, "Returns a text defining the criterium : 'Entity Number ...'");
cls_IFSelect_SelectEntityNumber.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectEntityNumber::get_type_name, "None");
cls_IFSelect_SelectEntityNumber.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectEntityNumber::get_type_descriptor, "None");
cls_IFSelect_SelectEntityNumber.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectEntityNumber::*)() const) &IFSelect_SelectEntityNumber::DynamicType, "None");

// CLASS: IFSELECT_SELECTERRORENTITIES
py::class_<IFSelect_SelectErrorEntities, opencascade::handle<IFSelect_SelectErrorEntities>, IFSelect_SelectExtract> cls_IFSelect_SelectErrorEntities(mod, "IFSelect_SelectErrorEntities", "A SelectErrorEntities sorts the Entities which are qualified as 'Error' (their Type has not been recognized) during reading a File. This does not concern Entities which are syntactically correct, but with incorrect data (for integrity constraints).");

// Constructors
cls_IFSelect_SelectErrorEntities.def(py::init<>());

// Methods
cls_IFSelect_SelectErrorEntities.def("Sort", (Standard_Boolean (IFSelect_SelectErrorEntities::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_SelectErrorEntities::Sort, "Returns True for an Entity which is qualified as 'Error', i.e. if <model> explicitly knows <ent> (through its Number) as Erroneous", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_IFSelect_SelectErrorEntities.def("ExtractLabel", (TCollection_AsciiString (IFSelect_SelectErrorEntities::*)() const) &IFSelect_SelectErrorEntities::ExtractLabel, "Returns a text defining the criterium : 'Error Entities'");
cls_IFSelect_SelectErrorEntities.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectErrorEntities::get_type_name, "None");
cls_IFSelect_SelectErrorEntities.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectErrorEntities::get_type_descriptor, "None");
cls_IFSelect_SelectErrorEntities.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectErrorEntities::*)() const) &IFSelect_SelectErrorEntities::DynamicType, "None");

// CLASS: IFSELECT_SELECTEXPLORE
py::class_<IFSelect_SelectExplore, opencascade::handle<IFSelect_SelectExplore>, IFSelect_SelectDeduct> cls_IFSelect_SelectExplore(mod, "IFSelect_SelectExplore", "A SelectExplore determines from an input list of Entities, a list obtained by a way of exploration. This implies the possibility of recursive exploration : the output list is itself reused as input, etc... Examples : Shared Entities, can be considered at one level (immediate shared) or more, or max level");

// Methods
cls_IFSelect_SelectExplore.def("Level", (Standard_Integer (IFSelect_SelectExplore::*)() const) &IFSelect_SelectExplore::Level, "Returns the required exploring level");
cls_IFSelect_SelectExplore.def("RootResult", (Interface_EntityIterator (IFSelect_SelectExplore::*)(const Interface_Graph &) const) &IFSelect_SelectExplore::RootResult, "Returns the list of selected entities. Works by calling the method Explore on each input entity : it can be rejected, taken for output, or to explore. If the maximum level has not yet been attained, or if no max level is specified, entities to be explored are themselves used as if they were input", py::arg("G"));
cls_IFSelect_SelectExplore.def("Explore", (Standard_Boolean (IFSelect_SelectExplore::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_Graph &, Interface_EntityIterator &) const) &IFSelect_SelectExplore::Explore, "Analyses and, if required, Explores an entity, as follows : The explored list starts as empty, it has to be filled by this method. If it returns False, <ent> is rejected for result (this is to be used only as safety) If it returns True and <explored> remains empty, <ent> is taken itself for result, not explored If it returns True and <explored> is not empty, the content of this list is considered : If maximum level is attained, it is taken for result Else (or no max), each of its entity will be itself explored", py::arg("level"), py::arg("ent"), py::arg("G"), py::arg("explored"));
cls_IFSelect_SelectExplore.def("Label", (TCollection_AsciiString (IFSelect_SelectExplore::*)() const) &IFSelect_SelectExplore::Label, "Returns a text saying '(Recursive)' or '(Level nn)' plus specific criterium returned by ExploreLabel (see below)");
cls_IFSelect_SelectExplore.def("ExploreLabel", (TCollection_AsciiString (IFSelect_SelectExplore::*)() const) &IFSelect_SelectExplore::ExploreLabel, "Returns a text defining the way of exploration");
cls_IFSelect_SelectExplore.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectExplore::get_type_name, "None");
cls_IFSelect_SelectExplore.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectExplore::get_type_descriptor, "None");
cls_IFSelect_SelectExplore.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectExplore::*)() const) &IFSelect_SelectExplore::DynamicType, "None");

// CLASS: IFSELECT_SELECTFLAG
py::class_<IFSelect_SelectFlag, opencascade::handle<IFSelect_SelectFlag>, IFSelect_SelectExtract> cls_IFSelect_SelectFlag(mod, "IFSelect_SelectFlag", "A SelectFlag queries a flag noted in the bitmap of the Graph. The Flag is designated by its Name. Flag Names are defined by Work Session and, as necessary, other functional objects");

// Constructors
cls_IFSelect_SelectFlag.def(py::init<const Standard_CString>(), py::arg("flagname"));

// Methods
cls_IFSelect_SelectFlag.def("FlagName", (Standard_CString (IFSelect_SelectFlag::*)() const) &IFSelect_SelectFlag::FlagName, "Returns the name of the flag");
cls_IFSelect_SelectFlag.def("RootResult", (Interface_EntityIterator (IFSelect_SelectFlag::*)(const Interface_Graph &) const) &IFSelect_SelectFlag::RootResult, "Returns the list of selected entities. It is redefined to work on the graph itself (not queried by sort)", py::arg("G"));
cls_IFSelect_SelectFlag.def("Sort", (Standard_Boolean (IFSelect_SelectFlag::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_SelectFlag::Sort, "Returns always False because RootResult has done the work", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_IFSelect_SelectFlag.def("ExtractLabel", (TCollection_AsciiString (IFSelect_SelectFlag::*)() const) &IFSelect_SelectFlag::ExtractLabel, "Returns a text defining the criterium, includes the flag name");
cls_IFSelect_SelectFlag.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectFlag::get_type_name, "None");
cls_IFSelect_SelectFlag.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectFlag::get_type_descriptor, "None");
cls_IFSelect_SelectFlag.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectFlag::*)() const) &IFSelect_SelectFlag::DynamicType, "None");

// CLASS: IFSELECT_SELECTINCORRECTENTITIES
py::class_<IFSelect_SelectIncorrectEntities, opencascade::handle<IFSelect_SelectIncorrectEntities>, IFSelect_SelectFlag> cls_IFSelect_SelectIncorrectEntities(mod, "IFSelect_SelectIncorrectEntities", "A SelectIncorrectEntities sorts the Entities which have been noted as Incorrect in the Graph of the Session (flag 'Incorrect') It can find a result only if ComputeCheck has formerly been called on the WorkSession. Else, its result will be empty.");

// Constructors
cls_IFSelect_SelectIncorrectEntities.def(py::init<>());

// Methods
cls_IFSelect_SelectIncorrectEntities.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectIncorrectEntities::get_type_name, "None");
cls_IFSelect_SelectIncorrectEntities.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectIncorrectEntities::get_type_descriptor, "None");
cls_IFSelect_SelectIncorrectEntities.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectIncorrectEntities::*)() const) &IFSelect_SelectIncorrectEntities::DynamicType, "None");

// CLASS: IFSELECT_SELECTINLIST
py::class_<IFSelect_SelectInList, opencascade::handle<IFSelect_SelectInList>, IFSelect_SelectAnyList> cls_IFSelect_SelectInList(mod, "IFSelect_SelectInList", "A SelectInList kind Selection selects a List of an Entity, which is composed of single Entities To know the list on which to work, SelectInList has two deferred methods : NbItems (inherited from SelectAnyList) and ListedEntity (which gives an item as an Entity) which must be defined to get a List in an Entity of the required Type (and consider that list is empty if Entity has not required Type)");

// Methods
cls_IFSelect_SelectInList.def("ListedEntity", (opencascade::handle<Standard_Transient> (IFSelect_SelectInList::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &) const) &IFSelect_SelectInList::ListedEntity, "Returns an Entity, given its rank in the list", py::arg("num"), py::arg("ent"));
cls_IFSelect_SelectInList.def("FillResult", (void (IFSelect_SelectInList::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<Standard_Transient> &, Interface_EntityIterator &) const) &IFSelect_SelectInList::FillResult, "Puts into the result, the sub-entities of the list, from n1 to n2 included. Remark that adequation with Entity's type and length of list has already been made at this stage Called by RootResult; calls ListedEntity (see below)", py::arg("n1"), py::arg("n2"), py::arg("ent"), py::arg("result"));
cls_IFSelect_SelectInList.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectInList::get_type_name, "None");
cls_IFSelect_SelectInList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectInList::get_type_descriptor, "None");
cls_IFSelect_SelectInList.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectInList::*)() const) &IFSelect_SelectInList::DynamicType, "None");

// CLASS: IFSELECT_SELECTINTERSECTION
py::class_<IFSelect_SelectIntersection, opencascade::handle<IFSelect_SelectIntersection>, IFSelect_SelectCombine> cls_IFSelect_SelectIntersection(mod, "IFSelect_SelectIntersection", "A SelectIntersection filters the Entities issued from several other Selections as Intersection of results : 'AND' operator");

// Constructors
cls_IFSelect_SelectIntersection.def(py::init<>());

// Methods
cls_IFSelect_SelectIntersection.def("RootResult", (Interface_EntityIterator (IFSelect_SelectIntersection::*)(const Interface_Graph &) const) &IFSelect_SelectIntersection::RootResult, "Returns the list of selected Entities, which is the common part of results from all input selections. Uniqueness is guaranteed.", py::arg("G"));
cls_IFSelect_SelectIntersection.def("Label", (TCollection_AsciiString (IFSelect_SelectIntersection::*)() const) &IFSelect_SelectIntersection::Label, "Returns a text defining the criterium : 'Intersection (AND)'");
cls_IFSelect_SelectIntersection.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectIntersection::get_type_name, "None");
cls_IFSelect_SelectIntersection.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectIntersection::get_type_descriptor, "None");
cls_IFSelect_SelectIntersection.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectIntersection::*)() const) &IFSelect_SelectIntersection::DynamicType, "None");

// CLASS: IFSELECT_SELECTIONITERATOR
py::class_<IFSelect_SelectionIterator> cls_IFSelect_SelectionIterator(mod, "IFSelect_SelectionIterator", "Defines an Iterator on a list of Selections");

// Constructors
cls_IFSelect_SelectionIterator.def(py::init<>());
cls_IFSelect_SelectionIterator.def(py::init<const opencascade::handle<IFSelect_Selection> &>(), py::arg("sel"));

// Methods
// cls_IFSelect_SelectionIterator.def_static("operator new_", (void * (*)(size_t)) &IFSelect_SelectionIterator::operator new, "None", py::arg("theSize"));
// cls_IFSelect_SelectionIterator.def_static("operator delete_", (void (*)(void *)) &IFSelect_SelectionIterator::operator delete, "None", py::arg("theAddress"));
// cls_IFSelect_SelectionIterator.def_static("operator new[]_", (void * (*)(size_t)) &IFSelect_SelectionIterator::operator new[], "None", py::arg("theSize"));
// cls_IFSelect_SelectionIterator.def_static("operator delete[]_", (void (*)(void *)) &IFSelect_SelectionIterator::operator delete[], "None", py::arg("theAddress"));
// cls_IFSelect_SelectionIterator.def_static("operator new_", (void * (*)(size_t, void *)) &IFSelect_SelectionIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IFSelect_SelectionIterator.def_static("operator delete_", (void (*)(void *, void *)) &IFSelect_SelectionIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_IFSelect_SelectionIterator.def("AddFromIter", (void (IFSelect_SelectionIterator::*)(IFSelect_SelectionIterator &)) &IFSelect_SelectionIterator::AddFromIter, "Adds to an iterator the content of another one (each selection is present only once in the result)", py::arg("iter"));
cls_IFSelect_SelectionIterator.def("AddItem", (void (IFSelect_SelectionIterator::*)(const opencascade::handle<IFSelect_Selection> &)) &IFSelect_SelectionIterator::AddItem, "Adds a Selection to an iterator (if not yet noted)", py::arg("sel"));
cls_IFSelect_SelectionIterator.def("AddList", (void (IFSelect_SelectionIterator::*)(const IFSelect_TSeqOfSelection &)) &IFSelect_SelectionIterator::AddList, "Adds a list of Selections to an iterator (this list comes from the description of a Selection or a Dispatch, etc...)", py::arg("list"));
cls_IFSelect_SelectionIterator.def("More", (Standard_Boolean (IFSelect_SelectionIterator::*)() const) &IFSelect_SelectionIterator::More, "Returns True if there are more Selections to get");
cls_IFSelect_SelectionIterator.def("Next", (void (IFSelect_SelectionIterator::*)()) &IFSelect_SelectionIterator::Next, "Sets iterator to the next item");
cls_IFSelect_SelectionIterator.def("Value", (const opencascade::handle<IFSelect_Selection> & (IFSelect_SelectionIterator::*)() const) &IFSelect_SelectionIterator::Value, "Returns the current Selction beeing iterated Error if count of Selection has been passed");

// CLASS: IFSELECT_SELECTMODELENTITIES
py::class_<IFSelect_SelectModelEntities, opencascade::handle<IFSelect_SelectModelEntities>, IFSelect_SelectBase> cls_IFSelect_SelectModelEntities(mod, "IFSelect_SelectModelEntities", "A SelectModelEntities gets all the Entities of an InterfaceModel.");

// Constructors
cls_IFSelect_SelectModelEntities.def(py::init<>());

// Methods
cls_IFSelect_SelectModelEntities.def("RootResult", (Interface_EntityIterator (IFSelect_SelectModelEntities::*)(const Interface_Graph &) const) &IFSelect_SelectModelEntities::RootResult, "Returns the list of selected entities : the Entities of the Model (note that this result assures naturally uniqueness)", py::arg("G"));
cls_IFSelect_SelectModelEntities.def("CompleteResult", (Interface_EntityIterator (IFSelect_SelectModelEntities::*)(const Interface_Graph &) const) &IFSelect_SelectModelEntities::CompleteResult, "The complete list of Entities (including shared ones) ... is exactly identical to RootResults in this case", py::arg("G"));
cls_IFSelect_SelectModelEntities.def("Label", (TCollection_AsciiString (IFSelect_SelectModelEntities::*)() const) &IFSelect_SelectModelEntities::Label, "Returns a text defining the criterium : 'Model Entities'");
cls_IFSelect_SelectModelEntities.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectModelEntities::get_type_name, "None");
cls_IFSelect_SelectModelEntities.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectModelEntities::get_type_descriptor, "None");
cls_IFSelect_SelectModelEntities.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectModelEntities::*)() const) &IFSelect_SelectModelEntities::DynamicType, "None");

// CLASS: IFSELECT_SELECTMODELROOTS
py::class_<IFSelect_SelectModelRoots, opencascade::handle<IFSelect_SelectModelRoots>, IFSelect_SelectBase> cls_IFSelect_SelectModelRoots(mod, "IFSelect_SelectModelRoots", "A SelectModelRoots gets all the Root Entities of an InterfaceModel. Remember that a 'Root Entity' is defined as having no Sharing Entity (if there is a Loop between Entities, none of them can be a 'Root').");

// Constructors
cls_IFSelect_SelectModelRoots.def(py::init<>());

// Methods
cls_IFSelect_SelectModelRoots.def("RootResult", (Interface_EntityIterator (IFSelect_SelectModelRoots::*)(const Interface_Graph &) const) &IFSelect_SelectModelRoots::RootResult, "Returns the list of selected entities : the Roots of the Model (note that this result assures naturally uniqueness)", py::arg("G"));
cls_IFSelect_SelectModelRoots.def("Label", (TCollection_AsciiString (IFSelect_SelectModelRoots::*)() const) &IFSelect_SelectModelRoots::Label, "Returns a text defining the criterium : 'Model Roots'");
cls_IFSelect_SelectModelRoots.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectModelRoots::get_type_name, "None");
cls_IFSelect_SelectModelRoots.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectModelRoots::get_type_descriptor, "None");
cls_IFSelect_SelectModelRoots.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectModelRoots::*)() const) &IFSelect_SelectModelRoots::DynamicType, "None");

// CLASS: IFSELECT_SELECTPOINTED
py::class_<IFSelect_SelectPointed, opencascade::handle<IFSelect_SelectPointed>, IFSelect_SelectBase> cls_IFSelect_SelectPointed(mod, "IFSelect_SelectPointed", "This type of Selection is intended to describe a direct selection without an explicit criterium, for instance the result of picking viewed entities on a graphic screen");

// Constructors
cls_IFSelect_SelectPointed.def(py::init<>());

// Methods
cls_IFSelect_SelectPointed.def("Clear", (void (IFSelect_SelectPointed::*)()) &IFSelect_SelectPointed::Clear, "Clears the list of selected items Also says the list is unset All Add* methods and SetList say the list is set");
cls_IFSelect_SelectPointed.def("IsSet", (Standard_Boolean (IFSelect_SelectPointed::*)() const) &IFSelect_SelectPointed::IsSet, "Tells if the list has been set. Even if empty");
cls_IFSelect_SelectPointed.def("SetEntity", (void (IFSelect_SelectPointed::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_SelectPointed::SetEntity, "As SetList but with only one entity If <ent> is Null, the list is said as being set but is empty", py::arg("item"));
cls_IFSelect_SelectPointed.def("SetList", (void (IFSelect_SelectPointed::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &)) &IFSelect_SelectPointed::SetList, "Sets a given list to define the list of selected items <list> can be empty or null : in this case, the list is said as being set, but it is empty", py::arg("list"));
cls_IFSelect_SelectPointed.def("Add", (Standard_Boolean (IFSelect_SelectPointed::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_SelectPointed::Add, "Adds an item. Returns True if Done, False if <item> is already in the selected list", py::arg("item"));
cls_IFSelect_SelectPointed.def("Remove", (Standard_Boolean (IFSelect_SelectPointed::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_SelectPointed::Remove, "Removes an item. Returns True if Done, False if <item> was not in the selected list", py::arg("item"));
cls_IFSelect_SelectPointed.def("Toggle", (Standard_Boolean (IFSelect_SelectPointed::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_SelectPointed::Toggle, "Toggles status of an item : adds it if not pointed or removes it if already pointed. Returns the new status (Pointed or not)", py::arg("item"));
cls_IFSelect_SelectPointed.def("AddList", (Standard_Boolean (IFSelect_SelectPointed::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &)) &IFSelect_SelectPointed::AddList, "Adds all the items defined in a list. Returns True if at least one item has been added, False else", py::arg("list"));
cls_IFSelect_SelectPointed.def("RemoveList", (Standard_Boolean (IFSelect_SelectPointed::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &)) &IFSelect_SelectPointed::RemoveList, "Removes all the items defined in a list. Returns True if at least one item has been removed, False else", py::arg("list"));
cls_IFSelect_SelectPointed.def("ToggleList", (Standard_Boolean (IFSelect_SelectPointed::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &)) &IFSelect_SelectPointed::ToggleList, "Toggles status of all the items defined in a list : adds it if not pointed or removes it if already pointed.", py::arg("list"));
cls_IFSelect_SelectPointed.def("Rank", (Standard_Integer (IFSelect_SelectPointed::*)(const opencascade::handle<Standard_Transient> &) const) &IFSelect_SelectPointed::Rank, "Returns the rank of an item in the selected list, or 0.", py::arg("item"));
cls_IFSelect_SelectPointed.def("NbItems", (Standard_Integer (IFSelect_SelectPointed::*)() const) &IFSelect_SelectPointed::NbItems, "Returns the count of selected items");
cls_IFSelect_SelectPointed.def("Item", (opencascade::handle<Standard_Transient> (IFSelect_SelectPointed::*)(const Standard_Integer) const) &IFSelect_SelectPointed::Item, "Returns an item given its rank, or a Null Handle", py::arg("num"));
cls_IFSelect_SelectPointed.def("Update", (void (IFSelect_SelectPointed::*)(const opencascade::handle<Interface_CopyControl> &)) &IFSelect_SelectPointed::Update, "Rebuilds the selected list. Any selected entity which has a bound result is replaced by this result, else it is removed.", py::arg("control"));
cls_IFSelect_SelectPointed.def("Update", (void (IFSelect_SelectPointed::*)(const opencascade::handle<IFSelect_Transformer> &)) &IFSelect_SelectPointed::Update, "Rebuilds the selected list, by querying a Transformer (same principle as from a CopyControl)", py::arg("trf"));
cls_IFSelect_SelectPointed.def("RootResult", (Interface_EntityIterator (IFSelect_SelectPointed::*)(const Interface_Graph &) const) &IFSelect_SelectPointed::RootResult, "Returns the list of selected items. Only the selected entities which are present in the graph are given (this result assures uniqueness).", py::arg("G"));
cls_IFSelect_SelectPointed.def("Label", (TCollection_AsciiString (IFSelect_SelectPointed::*)() const) &IFSelect_SelectPointed::Label, "Returns a text which identifies the type of selection made. It is 'Pointed Entities'");
cls_IFSelect_SelectPointed.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectPointed::get_type_name, "None");
cls_IFSelect_SelectPointed.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectPointed::get_type_descriptor, "None");
cls_IFSelect_SelectPointed.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectPointed::*)() const) &IFSelect_SelectPointed::DynamicType, "None");

// CLASS: IFSELECT_SELECTRANGE
py::class_<IFSelect_SelectRange, opencascade::handle<IFSelect_SelectRange>, IFSelect_SelectExtract> cls_IFSelect_SelectRange(mod, "IFSelect_SelectRange", "A SelectRange keeps or rejects a sub-set of the input set, that is the Entities of which rank in the iteration list is in a given range (for instance form 2nd to 6th, etc...)");

// Constructors
cls_IFSelect_SelectRange.def(py::init<>());

// Methods
cls_IFSelect_SelectRange.def("SetRange", (void (IFSelect_SelectRange::*)(const opencascade::handle<IFSelect_IntParam> &, const opencascade::handle<IFSelect_IntParam> &)) &IFSelect_SelectRange::SetRange, "Sets a Range for numbers, with a lower and a upper limits Error if rankto is lower then rankfrom", py::arg("rankfrom"), py::arg("rankto"));
cls_IFSelect_SelectRange.def("SetOne", (void (IFSelect_SelectRange::*)(const opencascade::handle<IFSelect_IntParam> &)) &IFSelect_SelectRange::SetOne, "Sets a unique number (only one Entity will be sorted as True)", py::arg("rank"));
cls_IFSelect_SelectRange.def("SetFrom", (void (IFSelect_SelectRange::*)(const opencascade::handle<IFSelect_IntParam> &)) &IFSelect_SelectRange::SetFrom, "Sets a Lower limit but no upper limit", py::arg("rankfrom"));
cls_IFSelect_SelectRange.def("SetUntil", (void (IFSelect_SelectRange::*)(const opencascade::handle<IFSelect_IntParam> &)) &IFSelect_SelectRange::SetUntil, "Sets an Upper limit but no lower limit (equivalent to lower 1)", py::arg("rankto"));
cls_IFSelect_SelectRange.def("HasLower", (Standard_Boolean (IFSelect_SelectRange::*)() const) &IFSelect_SelectRange::HasLower, "Returns True if a Lower limit is defined");
cls_IFSelect_SelectRange.def("Lower", (opencascade::handle<IFSelect_IntParam> (IFSelect_SelectRange::*)() const) &IFSelect_SelectRange::Lower, "Returns Lower limit (if there is; else, value is senseless)");
cls_IFSelect_SelectRange.def("LowerValue", (Standard_Integer (IFSelect_SelectRange::*)() const) &IFSelect_SelectRange::LowerValue, "Returns Value of Lower Limit (0 if none is defined)");
cls_IFSelect_SelectRange.def("HasUpper", (Standard_Boolean (IFSelect_SelectRange::*)() const) &IFSelect_SelectRange::HasUpper, "Returns True if a Lower limit is defined");
cls_IFSelect_SelectRange.def("Upper", (opencascade::handle<IFSelect_IntParam> (IFSelect_SelectRange::*)() const) &IFSelect_SelectRange::Upper, "Returns Upper limit (if there is; else, value is senseless)");
cls_IFSelect_SelectRange.def("UpperValue", (Standard_Integer (IFSelect_SelectRange::*)() const) &IFSelect_SelectRange::UpperValue, "Returns Value of Upper Limit (0 if none is defined)");
cls_IFSelect_SelectRange.def("Sort", (Standard_Boolean (IFSelect_SelectRange::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_SelectRange::Sort, "Returns True for an Entity of which occurence number in the iteration is inside the selected Range (considers <rank>)", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_IFSelect_SelectRange.def("ExtractLabel", (TCollection_AsciiString (IFSelect_SelectRange::*)() const) &IFSelect_SelectRange::ExtractLabel, "Returns a text defining the criterium : following cases, ' From .. Until ..' or 'From ..' or 'Until ..' or 'Rank no ..'");
cls_IFSelect_SelectRange.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectRange::get_type_name, "None");
cls_IFSelect_SelectRange.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectRange::get_type_descriptor, "None");
cls_IFSelect_SelectRange.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectRange::*)() const) &IFSelect_SelectRange::DynamicType, "None");

// CLASS: IFSELECT_SELECTROOTCOMPS
py::class_<IFSelect_SelectRootComps, opencascade::handle<IFSelect_SelectRootComps>, IFSelect_SelectExtract> cls_IFSelect_SelectRootComps(mod, "IFSelect_SelectRootComps", "A SelectRootComps sorts the Entities which are part of Strong Componants, local roots of a set of Entities : they can be Single Componants (containing one Entity) or Cycles This class gives a more secure result than SelectRoots (which considers only Single Componants) but is longer to work : it can be used when there can be or there are cycles in a Model For each cycle, one Entity is given arbitrarily Reject works as for SelectRoots : Strong Componants defined in the input list which are not local roots are given");

// Constructors
cls_IFSelect_SelectRootComps.def(py::init<>());

// Methods
cls_IFSelect_SelectRootComps.def("RootResult", (Interface_EntityIterator (IFSelect_SelectRootComps::*)(const Interface_Graph &) const) &IFSelect_SelectRootComps::RootResult, "Returns the list of local root strong componants, by one Entity par componant. It is redefined for a purpose of effeciency : calling a Sort routine for each Entity would cost more ressource than to work in once using a Map RootResult takes in account the Direct status", py::arg("G"));
cls_IFSelect_SelectRootComps.def("Sort", (Standard_Boolean (IFSelect_SelectRootComps::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_SelectRootComps::Sort, "Returns always True, because RootResult has done work", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_IFSelect_SelectRootComps.def("ExtractLabel", (TCollection_AsciiString (IFSelect_SelectRootComps::*)() const) &IFSelect_SelectRootComps::ExtractLabel, "Returns a text defining the criterium : 'Local Root Componants'");
cls_IFSelect_SelectRootComps.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectRootComps::get_type_name, "None");
cls_IFSelect_SelectRootComps.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectRootComps::get_type_descriptor, "None");
cls_IFSelect_SelectRootComps.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectRootComps::*)() const) &IFSelect_SelectRootComps::DynamicType, "None");

// CLASS: IFSELECT_SELECTROOTS
py::class_<IFSelect_SelectRoots, opencascade::handle<IFSelect_SelectRoots>, IFSelect_SelectExtract> cls_IFSelect_SelectRoots(mod, "IFSelect_SelectRoots", "A SelectRoots sorts the Entities which are local roots of a set of Entities (not shared by other Entities inside this set, even if they are shared by other Entities outside it)");

// Constructors
cls_IFSelect_SelectRoots.def(py::init<>());

// Methods
cls_IFSelect_SelectRoots.def("RootResult", (Interface_EntityIterator (IFSelect_SelectRoots::*)(const Interface_Graph &) const) &IFSelect_SelectRoots::RootResult, "Returns the list of local roots. It is redefined for a purpose of effeciency : calling a Sort routine for each Entity would cost more ressource than to work in once using a Map RootResult takes in account the Direct status", py::arg("G"));
cls_IFSelect_SelectRoots.def("Sort", (Standard_Boolean (IFSelect_SelectRoots::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_SelectRoots::Sort, "Returns always True, because RootResult has done work", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_IFSelect_SelectRoots.def("ExtractLabel", (TCollection_AsciiString (IFSelect_SelectRoots::*)() const) &IFSelect_SelectRoots::ExtractLabel, "Returns a text defining the criterium : 'Local Root Entities'");
cls_IFSelect_SelectRoots.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectRoots::get_type_name, "None");
cls_IFSelect_SelectRoots.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectRoots::get_type_descriptor, "None");
cls_IFSelect_SelectRoots.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectRoots::*)() const) &IFSelect_SelectRoots::DynamicType, "None");

// CLASS: IFSELECT_SELECTSENT
py::class_<IFSelect_SelectSent, opencascade::handle<IFSelect_SelectSent>, IFSelect_SelectExtract> cls_IFSelect_SelectSent(mod, "IFSelect_SelectSent", "This class returns entities according sending to a file Once a model has been loaded, further sendings are recorded as status in the graph (for each value, a count of sendings)");

// Constructors
cls_IFSelect_SelectSent.def(py::init<>());
cls_IFSelect_SelectSent.def(py::init<const Standard_Integer>(), py::arg("sentcount"));
cls_IFSelect_SelectSent.def(py::init<const Standard_Integer, const Standard_Boolean>(), py::arg("sentcount"), py::arg("atleast"));

// Methods
cls_IFSelect_SelectSent.def("SentCount", (Standard_Integer (IFSelect_SelectSent::*)() const) &IFSelect_SelectSent::SentCount, "Returns the queried count of sending");
cls_IFSelect_SelectSent.def("AtLeast", (Standard_Boolean (IFSelect_SelectSent::*)() const) &IFSelect_SelectSent::AtLeast, "Returns the <atleast> status, True for sending at least the sending count, False for sending exactly the sending count Remark : if SentCount is 0, AtLeast is ignored");
cls_IFSelect_SelectSent.def("RootResult", (Interface_EntityIterator (IFSelect_SelectSent::*)(const Interface_Graph &) const) &IFSelect_SelectSent::RootResult, "Returns the list of selected entities. It is redefined to work on the graph itself (not queried by sort)", py::arg("G"));
cls_IFSelect_SelectSent.def("Sort", (Standard_Boolean (IFSelect_SelectSent::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_SelectSent::Sort, "Returns always False because RootResult has done the work", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_IFSelect_SelectSent.def("ExtractLabel", (TCollection_AsciiString (IFSelect_SelectSent::*)() const) &IFSelect_SelectSent::ExtractLabel, "Returns a text defining the criterium : query : SentCount = 0 -> 'Remaining (non-sent) entities' SentCount = 1, AtLeast = True -> 'Sent entities' SentCount = 1, AtLeast = False -> 'Sent once (no duplicated)' SentCount = 2, AtLeast = True -> 'Sent several times entities' SentCount = 2, AtLeast = False -> 'Sent twice entities' SentCount > 2, AtLeast = True -> 'Sent at least <count> times entities' SentCount > 2, AtLeast = False -> 'Sent <count> times entities'");
cls_IFSelect_SelectSent.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectSent::get_type_name, "None");
cls_IFSelect_SelectSent.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectSent::get_type_descriptor, "None");
cls_IFSelect_SelectSent.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectSent::*)() const) &IFSelect_SelectSent::DynamicType, "None");

// CLASS: IFSELECT_SELECTSHARED
py::class_<IFSelect_SelectShared, opencascade::handle<IFSelect_SelectShared>, IFSelect_SelectDeduct> cls_IFSelect_SelectShared(mod, "IFSelect_SelectShared", "A SelectShared selects Entities which are directly Shared by the Entities of the Input list");

// Constructors
cls_IFSelect_SelectShared.def(py::init<>());

// Methods
cls_IFSelect_SelectShared.def("RootResult", (Interface_EntityIterator (IFSelect_SelectShared::*)(const Interface_Graph &) const) &IFSelect_SelectShared::RootResult, "Returns the list of selected entities (list of entities shared by those of input list)", py::arg("G"));
cls_IFSelect_SelectShared.def("Label", (TCollection_AsciiString (IFSelect_SelectShared::*)() const) &IFSelect_SelectShared::Label, "Returns a text defining the criterium : 'Shared (one level)'");
cls_IFSelect_SelectShared.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectShared::get_type_name, "None");
cls_IFSelect_SelectShared.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectShared::get_type_descriptor, "None");
cls_IFSelect_SelectShared.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectShared::*)() const) &IFSelect_SelectShared::DynamicType, "None");

// CLASS: IFSELECT_SELECTSHARING
py::class_<IFSelect_SelectSharing, opencascade::handle<IFSelect_SelectSharing>, IFSelect_SelectDeduct> cls_IFSelect_SelectSharing(mod, "IFSelect_SelectSharing", "A SelectSharing selects Entities which directly Share (Level One) the Entities of the Input list Remark : if an Entity of the Input List directly shares another one, it is of course present in the Result List");

// Constructors
cls_IFSelect_SelectSharing.def(py::init<>());

// Methods
cls_IFSelect_SelectSharing.def("RootResult", (Interface_EntityIterator (IFSelect_SelectSharing::*)(const Interface_Graph &) const) &IFSelect_SelectSharing::RootResult, "Returns the list of selected entities (list of entities which share (level one) those of input list)", py::arg("G"));
cls_IFSelect_SelectSharing.def("Label", (TCollection_AsciiString (IFSelect_SelectSharing::*)() const) &IFSelect_SelectSharing::Label, "Returns a text defining the criterium : 'Sharing (one level)'");
cls_IFSelect_SelectSharing.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectSharing::get_type_name, "None");
cls_IFSelect_SelectSharing.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectSharing::get_type_descriptor, "None");
cls_IFSelect_SelectSharing.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectSharing::*)() const) &IFSelect_SelectSharing::DynamicType, "None");

// CLASS: IFSELECT_SELECTSIGNATURE
py::class_<IFSelect_SelectSignature, opencascade::handle<IFSelect_SelectSignature>, IFSelect_SelectExtract> cls_IFSelect_SelectSignature(mod, "IFSelect_SelectSignature", "A SelectSignature sorts the Entities on a Signature Matching. The signature to match is given at creation time. Also, the required match is given at creation time : exact (IsEqual) or contains (the Type's Name must contain the criterium Text)");

// Constructors
cls_IFSelect_SelectSignature.def(py::init<const opencascade::handle<IFSelect_Signature> &, const Standard_CString>(), py::arg("matcher"), py::arg("signtext"));
cls_IFSelect_SelectSignature.def(py::init<const opencascade::handle<IFSelect_Signature> &, const Standard_CString, const Standard_Boolean>(), py::arg("matcher"), py::arg("signtext"), py::arg("exact"));
cls_IFSelect_SelectSignature.def(py::init<const opencascade::handle<IFSelect_Signature> &, const TCollection_AsciiString &>(), py::arg("matcher"), py::arg("signtext"));
cls_IFSelect_SelectSignature.def(py::init<const opencascade::handle<IFSelect_Signature> &, const TCollection_AsciiString &, const Standard_Boolean>(), py::arg("matcher"), py::arg("signtext"), py::arg("exact"));
cls_IFSelect_SelectSignature.def(py::init<const opencascade::handle<IFSelect_SignCounter> &, const Standard_CString>(), py::arg("matcher"), py::arg("signtext"));
cls_IFSelect_SelectSignature.def(py::init<const opencascade::handle<IFSelect_SignCounter> &, const Standard_CString, const Standard_Boolean>(), py::arg("matcher"), py::arg("signtext"), py::arg("exact"));

// Methods
cls_IFSelect_SelectSignature.def("Signature", (opencascade::handle<IFSelect_Signature> (IFSelect_SelectSignature::*)() const) &IFSelect_SelectSignature::Signature, "Returns the used Signature, then it is possible to access it, modify it as required. Can be null, hence see Counter");
cls_IFSelect_SelectSignature.def("Counter", (opencascade::handle<IFSelect_SignCounter> (IFSelect_SelectSignature::*)() const) &IFSelect_SelectSignature::Counter, "Returns the used SignCounter. Can be used as alternative for Signature");
cls_IFSelect_SelectSignature.def("SortInGraph", (Standard_Boolean (IFSelect_SelectSignature::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_Graph &) const) &IFSelect_SelectSignature::SortInGraph, "Returns True for an Entity (model->Value(num)) of which the signature matches the text given as creation time May also work with a Counter from the Graph", py::arg("rank"), py::arg("ent"), py::arg("G"));
cls_IFSelect_SelectSignature.def("Sort", (Standard_Boolean (IFSelect_SelectSignature::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_SelectSignature::Sort, "Not called, defined only to remove a deferred method here", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_IFSelect_SelectSignature.def("SignatureText", (const TCollection_AsciiString & (IFSelect_SelectSignature::*)() const) &IFSelect_SelectSignature::SignatureText, "Returns Text used to Sort Entity on its Signature or SignCounter");
cls_IFSelect_SelectSignature.def("IsExact", (Standard_Boolean (IFSelect_SelectSignature::*)() const) &IFSelect_SelectSignature::IsExact, "Returns True if match must be exact");
cls_IFSelect_SelectSignature.def("ExtractLabel", (TCollection_AsciiString (IFSelect_SelectSignature::*)() const) &IFSelect_SelectSignature::ExtractLabel, "Returns a text defining the criterium. (it refers to the text and exact flag to be matched, and is qualified by the Name provided by the Signature)");
cls_IFSelect_SelectSignature.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectSignature::get_type_name, "None");
cls_IFSelect_SelectSignature.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectSignature::get_type_descriptor, "None");
cls_IFSelect_SelectSignature.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectSignature::*)() const) &IFSelect_SelectSignature::DynamicType, "None");

// CLASS: IFSELECT_SELECTSIGNEDSHARED
py::class_<IFSelect_SelectSignedShared, opencascade::handle<IFSelect_SelectSignedShared>, IFSelect_SelectExplore> cls_IFSelect_SelectSignedShared(mod, "IFSelect_SelectSignedShared", "In the graph, explore the Shareds of the input entities, until it encounters some which match a given Signature (for a limited level, filters the returned list) By default, fitted for any level");

// Constructors
cls_IFSelect_SelectSignedShared.def(py::init<const opencascade::handle<IFSelect_Signature> &, const Standard_CString>(), py::arg("matcher"), py::arg("signtext"));
cls_IFSelect_SelectSignedShared.def(py::init<const opencascade::handle<IFSelect_Signature> &, const Standard_CString, const Standard_Boolean>(), py::arg("matcher"), py::arg("signtext"), py::arg("exact"));
cls_IFSelect_SelectSignedShared.def(py::init<const opencascade::handle<IFSelect_Signature> &, const Standard_CString, const Standard_Boolean, const Standard_Integer>(), py::arg("matcher"), py::arg("signtext"), py::arg("exact"), py::arg("level"));

// Methods
cls_IFSelect_SelectSignedShared.def("Signature", (opencascade::handle<IFSelect_Signature> (IFSelect_SelectSignedShared::*)() const) &IFSelect_SelectSignedShared::Signature, "Returns the used Signature, then it is possible to access it, modify it as required");
cls_IFSelect_SelectSignedShared.def("SignatureText", (const TCollection_AsciiString & (IFSelect_SelectSignedShared::*)() const) &IFSelect_SelectSignedShared::SignatureText, "Returns Text used to Sort Entity on its Signature");
cls_IFSelect_SelectSignedShared.def("IsExact", (Standard_Boolean (IFSelect_SelectSignedShared::*)() const) &IFSelect_SelectSignedShared::IsExact, "Returns True if match must be exact");
cls_IFSelect_SelectSignedShared.def("Explore", (Standard_Boolean (IFSelect_SelectSignedShared::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_Graph &, Interface_EntityIterator &) const) &IFSelect_SelectSignedShared::Explore, "Explores an entity : its Shared entities <ent> to take if it matches the Signature At level max, filters the result. Else gives all Shareds", py::arg("level"), py::arg("ent"), py::arg("G"), py::arg("explored"));
cls_IFSelect_SelectSignedShared.def("ExploreLabel", (TCollection_AsciiString (IFSelect_SelectSignedShared::*)() const) &IFSelect_SelectSignedShared::ExploreLabel, "Returns a text defining the criterium. (it refers to the text and exact flag to be matched, and is qualified by the Name provided by the Signature)");
cls_IFSelect_SelectSignedShared.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectSignedShared::get_type_name, "None");
cls_IFSelect_SelectSignedShared.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectSignedShared::get_type_descriptor, "None");
cls_IFSelect_SelectSignedShared.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectSignedShared::*)() const) &IFSelect_SelectSignedShared::DynamicType, "None");

// CLASS: IFSELECT_SELECTSIGNEDSHARING
py::class_<IFSelect_SelectSignedSharing, opencascade::handle<IFSelect_SelectSignedSharing>, IFSelect_SelectExplore> cls_IFSelect_SelectSignedSharing(mod, "IFSelect_SelectSignedSharing", "In the graph, explore the sharings of the input entities, until it encounters some which match a given Signature (for a limited level, filters the returned list) By default, fitted for any level");

// Constructors
cls_IFSelect_SelectSignedSharing.def(py::init<const opencascade::handle<IFSelect_Signature> &, const Standard_CString>(), py::arg("matcher"), py::arg("signtext"));
cls_IFSelect_SelectSignedSharing.def(py::init<const opencascade::handle<IFSelect_Signature> &, const Standard_CString, const Standard_Boolean>(), py::arg("matcher"), py::arg("signtext"), py::arg("exact"));
cls_IFSelect_SelectSignedSharing.def(py::init<const opencascade::handle<IFSelect_Signature> &, const Standard_CString, const Standard_Boolean, const Standard_Integer>(), py::arg("matcher"), py::arg("signtext"), py::arg("exact"), py::arg("level"));

// Methods
cls_IFSelect_SelectSignedSharing.def("Signature", (opencascade::handle<IFSelect_Signature> (IFSelect_SelectSignedSharing::*)() const) &IFSelect_SelectSignedSharing::Signature, "Returns the used Signature, then it is possible to access it, modify it as required");
cls_IFSelect_SelectSignedSharing.def("SignatureText", (const TCollection_AsciiString & (IFSelect_SelectSignedSharing::*)() const) &IFSelect_SelectSignedSharing::SignatureText, "Returns Text used to Sort Entity on its Signature");
cls_IFSelect_SelectSignedSharing.def("IsExact", (Standard_Boolean (IFSelect_SelectSignedSharing::*)() const) &IFSelect_SelectSignedSharing::IsExact, "Returns True if match must be exact");
cls_IFSelect_SelectSignedSharing.def("Explore", (Standard_Boolean (IFSelect_SelectSignedSharing::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_Graph &, Interface_EntityIterator &) const) &IFSelect_SelectSignedSharing::Explore, "Explores an entity : its sharing entities <ent> to take if it matches the Signature At level max, filters the result. Else gives all sharings", py::arg("level"), py::arg("ent"), py::arg("G"), py::arg("explored"));
cls_IFSelect_SelectSignedSharing.def("ExploreLabel", (TCollection_AsciiString (IFSelect_SelectSignedSharing::*)() const) &IFSelect_SelectSignedSharing::ExploreLabel, "Returns a text defining the criterium. (it refers to the text and exact flag to be matched, and is qualified by the Name provided by the Signature)");
cls_IFSelect_SelectSignedSharing.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectSignedSharing::get_type_name, "None");
cls_IFSelect_SelectSignedSharing.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectSignedSharing::get_type_descriptor, "None");
cls_IFSelect_SelectSignedSharing.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectSignedSharing::*)() const) &IFSelect_SelectSignedSharing::DynamicType, "None");

// CLASS: IFSELECT_SELECTSUITE
py::class_<IFSelect_SelectSuite, opencascade::handle<IFSelect_SelectSuite>, IFSelect_SelectDeduct> cls_IFSelect_SelectSuite(mod, "IFSelect_SelectSuite", "A SelectSuite can describe a suite of SelectDeduct as a unique one : in other words, it can be seen as a 'macro selection'");

// Constructors
cls_IFSelect_SelectSuite.def(py::init<>());

// Methods
cls_IFSelect_SelectSuite.def("AddInput", (Standard_Boolean (IFSelect_SelectSuite::*)(const opencascade::handle<IFSelect_Selection> &)) &IFSelect_SelectSuite::AddInput, "Adds an input selection. I.E. : If <item> is a SelectDeduct, adds it as Previous, not as Input Else, sets it as Input Returns True when done Returns False and refuses to work if Input is already defined", py::arg("item"));
cls_IFSelect_SelectSuite.def("AddPrevious", (void (IFSelect_SelectSuite::*)(const opencascade::handle<IFSelect_SelectDeduct> &)) &IFSelect_SelectSuite::AddPrevious, "Adds a new first item (prepends to the list). The Input is not touched If <item> is null, does nothing", py::arg("item"));
cls_IFSelect_SelectSuite.def("AddNext", (void (IFSelect_SelectSuite::*)(const opencascade::handle<IFSelect_SelectDeduct> &)) &IFSelect_SelectSuite::AddNext, "Adds a new last item (prepends to the list) If <item> is null, does nothing", py::arg("item"));
cls_IFSelect_SelectSuite.def("NbItems", (Standard_Integer (IFSelect_SelectSuite::*)() const) &IFSelect_SelectSuite::NbItems, "Returns the count of Items");
cls_IFSelect_SelectSuite.def("Item", (opencascade::handle<IFSelect_SelectDeduct> (IFSelect_SelectSuite::*)(const Standard_Integer) const) &IFSelect_SelectSuite::Item, "Returns an item from its rank in the list (the Input is always apart)", py::arg("num"));
cls_IFSelect_SelectSuite.def("SetLabel", (void (IFSelect_SelectSuite::*)(const Standard_CString)) &IFSelect_SelectSuite::SetLabel, "Sets a value for the Label", py::arg("lab"));
cls_IFSelect_SelectSuite.def("RootResult", (Interface_EntityIterator (IFSelect_SelectSuite::*)(const Interface_Graph &) const) &IFSelect_SelectSuite::RootResult, "Returns the list of selected entities To do this, once InputResult has been taken (if Input or Alternate has been defined, else the first Item gives it) : this result is set as alternate input for the first item, which computes its result : this result is set as alternate input for the second item, etc...", py::arg("G"));
cls_IFSelect_SelectSuite.def("Label", (TCollection_AsciiString (IFSelect_SelectSuite::*)() const) &IFSelect_SelectSuite::Label, "Returns the Label Either it has been defined by SetLabel, or it will give 'Suite of nn Selections'");
cls_IFSelect_SelectSuite.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectSuite::get_type_name, "None");
cls_IFSelect_SelectSuite.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectSuite::get_type_descriptor, "None");
cls_IFSelect_SelectSuite.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectSuite::*)() const) &IFSelect_SelectSuite::DynamicType, "None");

// CLASS: IFSELECT_SELECTTYPE
py::class_<IFSelect_SelectType, opencascade::handle<IFSelect_SelectType>, IFSelect_SelectAnyType> cls_IFSelect_SelectType(mod, "IFSelect_SelectType", "A SelectType keeps or rejects Entities of which the Type is Kind of a given Cdl Type");

// Constructors
cls_IFSelect_SelectType.def(py::init<>());
cls_IFSelect_SelectType.def(py::init<const opencascade::handle<Standard_Type> &>(), py::arg("atype"));

// Methods
cls_IFSelect_SelectType.def("SetType", (void (IFSelect_SelectType::*)(const opencascade::handle<Standard_Type> &)) &IFSelect_SelectType::SetType, "Sets a TYpe for filter", py::arg("atype"));
cls_IFSelect_SelectType.def("TypeForMatch", (opencascade::handle<Standard_Type> (IFSelect_SelectType::*)() const) &IFSelect_SelectType::TypeForMatch, "Returns the Type to be matched for select : this is the type given at instantiation time");
cls_IFSelect_SelectType.def("ExtractLabel", (TCollection_AsciiString (IFSelect_SelectType::*)() const) &IFSelect_SelectType::ExtractLabel, "Returns a text defining the criterium. (should by gotten from Type of Entity used for instantiation)");
cls_IFSelect_SelectType.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectType::get_type_name, "None");
cls_IFSelect_SelectType.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectType::get_type_descriptor, "None");
cls_IFSelect_SelectType.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectType::*)() const) &IFSelect_SelectType::DynamicType, "None");

// CLASS: IFSELECT_SELECTUNION
py::class_<IFSelect_SelectUnion, opencascade::handle<IFSelect_SelectUnion>, IFSelect_SelectCombine> cls_IFSelect_SelectUnion(mod, "IFSelect_SelectUnion", "A SelectUnion cumulates the Entities issued from several other Selections (union of results : 'OR' operator)");

// Constructors
cls_IFSelect_SelectUnion.def(py::init<>());

// Methods
cls_IFSelect_SelectUnion.def("RootResult", (Interface_EntityIterator (IFSelect_SelectUnion::*)(const Interface_Graph &) const) &IFSelect_SelectUnion::RootResult, "Returns the list of selected Entities, which is the addition result from all input selections. Uniqueness is guaranteed.", py::arg("G"));
cls_IFSelect_SelectUnion.def("Label", (TCollection_AsciiString (IFSelect_SelectUnion::*)() const) &IFSelect_SelectUnion::Label, "Returns a text defining the criterium : 'Union (OR)'");
cls_IFSelect_SelectUnion.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectUnion::get_type_name, "None");
cls_IFSelect_SelectUnion.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectUnion::get_type_descriptor, "None");
cls_IFSelect_SelectUnion.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectUnion::*)() const) &IFSelect_SelectUnion::DynamicType, "None");

// CLASS: IFSELECT_SELECTUNKNOWNENTITIES
py::class_<IFSelect_SelectUnknownEntities, opencascade::handle<IFSelect_SelectUnknownEntities>, IFSelect_SelectExtract> cls_IFSelect_SelectUnknownEntities(mod, "IFSelect_SelectUnknownEntities", "A SelectUnknownEntities sorts the Entities which are qualified as 'Unknown' (their Type has not been recognized)");

// Constructors
cls_IFSelect_SelectUnknownEntities.def(py::init<>());

// Methods
cls_IFSelect_SelectUnknownEntities.def("Sort", (Standard_Boolean (IFSelect_SelectUnknownEntities::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_SelectUnknownEntities::Sort, "Returns True for an Entity which is qualified as 'Unknown', i.e. if <model> known <ent> (through its Number) as Unknown", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_IFSelect_SelectUnknownEntities.def("ExtractLabel", (TCollection_AsciiString (IFSelect_SelectUnknownEntities::*)() const) &IFSelect_SelectUnknownEntities::ExtractLabel, "Returns a text defining the criterium : 'Recognized Entities'");
cls_IFSelect_SelectUnknownEntities.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectUnknownEntities::get_type_name, "None");
cls_IFSelect_SelectUnknownEntities.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectUnknownEntities::get_type_descriptor, "None");
cls_IFSelect_SelectUnknownEntities.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectUnknownEntities::*)() const) &IFSelect_SelectUnknownEntities::DynamicType, "None");

// CLASS: IFSELECT_SESSIONFILE
py::class_<IFSelect_SessionFile> cls_IFSelect_SessionFile(mod, "IFSelect_SessionFile", "A SessionFile is intended to manage access between a WorkSession and an Ascii Form, to be considered as a Dump. It allows to write the File from the WorkSession, and later read the File to the WorkSession, by keeping required descriptions (such as dependances).");

// Constructors
cls_IFSelect_SessionFile.def(py::init<const opencascade::handle<IFSelect_WorkSession> &>(), py::arg("WS"));
cls_IFSelect_SessionFile.def(py::init<const opencascade::handle<IFSelect_WorkSession> &, const Standard_CString>(), py::arg("WS"), py::arg("filename"));

// Methods
// cls_IFSelect_SessionFile.def_static("operator new_", (void * (*)(size_t)) &IFSelect_SessionFile::operator new, "None", py::arg("theSize"));
// cls_IFSelect_SessionFile.def_static("operator delete_", (void (*)(void *)) &IFSelect_SessionFile::operator delete, "None", py::arg("theAddress"));
// cls_IFSelect_SessionFile.def_static("operator new[]_", (void * (*)(size_t)) &IFSelect_SessionFile::operator new[], "None", py::arg("theSize"));
// cls_IFSelect_SessionFile.def_static("operator delete[]_", (void (*)(void *)) &IFSelect_SessionFile::operator delete[], "None", py::arg("theAddress"));
// cls_IFSelect_SessionFile.def_static("operator new_", (void * (*)(size_t, void *)) &IFSelect_SessionFile::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IFSelect_SessionFile.def_static("operator delete_", (void (*)(void *, void *)) &IFSelect_SessionFile::operator delete, "None", py::arg(""), py::arg(""));
cls_IFSelect_SessionFile.def("ClearLines", (void (IFSelect_SessionFile::*)()) &IFSelect_SessionFile::ClearLines, "Clears the lines recorded whatever for writing or for reading");
cls_IFSelect_SessionFile.def("NbLines", (Standard_Integer (IFSelect_SessionFile::*)() const) &IFSelect_SessionFile::NbLines, "Returns the count of recorded lines");
cls_IFSelect_SessionFile.def("Line", (const TCollection_AsciiString & (IFSelect_SessionFile::*)(const Standard_Integer) const) &IFSelect_SessionFile::Line, "Returns a line given its rank in the list of recorded lines", py::arg("num"));
cls_IFSelect_SessionFile.def("AddLine", (void (IFSelect_SessionFile::*)(const Standard_CString)) &IFSelect_SessionFile::AddLine, "Adds a line to the list of recorded lines", py::arg("line"));
cls_IFSelect_SessionFile.def("RemoveLastLine", (void (IFSelect_SessionFile::*)()) &IFSelect_SessionFile::RemoveLastLine, "Removes the last line. Can be called recursively. Does nothing if the list is empty");
cls_IFSelect_SessionFile.def("WriteFile", (Standard_Boolean (IFSelect_SessionFile::*)(const Standard_CString)) &IFSelect_SessionFile::WriteFile, "Writes the recorded lines to a file named <name> then clears the list of lines. Returns False (with no clearing) if the file could not be created", py::arg("name"));
cls_IFSelect_SessionFile.def("ReadFile", (Standard_Boolean (IFSelect_SessionFile::*)(const Standard_CString)) &IFSelect_SessionFile::ReadFile, "Reads the recorded lines from a file named <name>, after having cleared the list (stops if RecognizeFile fails) Returns False (with no clearing) if the file could not be read", py::arg("name"));
cls_IFSelect_SessionFile.def("RecognizeFile", (Standard_Boolean (IFSelect_SessionFile::*)(const Standard_CString)) &IFSelect_SessionFile::RecognizeFile, "Recognizes the header line. returns True if OK, False else", py::arg("headerline"));
cls_IFSelect_SessionFile.def("Write", (Standard_Integer (IFSelect_SessionFile::*)(const Standard_CString)) &IFSelect_SessionFile::Write, "Performs a Write Operation from a WorkSession to a File i.e. calls WriteSession then WriteEnd, and WriteFile Returned Value is : 0 for OK, -1 File could not be created, >0 Error during Write (see WriteSession) IsDone can be called too (will return True for OK)", py::arg("filename"));
cls_IFSelect_SessionFile.def("Read", (Standard_Integer (IFSelect_SessionFile::*)(const Standard_CString)) &IFSelect_SessionFile::Read, "Performs a Read Operation from a file to a WorkSession i.e. calls ReadFile, then ReadSession and ReadEnd Returned Value is : 0 for OK, -1 File could not be opened, >0 Error during Read (see WriteSession) IsDone can be called too (will return True for OK)", py::arg("filename"));
cls_IFSelect_SessionFile.def("WriteSession", (Standard_Integer (IFSelect_SessionFile::*)()) &IFSelect_SessionFile::WriteSession, "Prepares the Write operation from a WorkSession (IFSelect) to a File, i.e. fills the list of lines (the file itself remains to be written; or NbLines/Line may be called) Important Remark : this excludes the reading of the last line, which is performed by WriteEnd Returns 0 if OK, status > 0 in case of error");
cls_IFSelect_SessionFile.def("WriteEnd", (Standard_Integer (IFSelect_SessionFile::*)()) &IFSelect_SessionFile::WriteEnd, "Writes the trailing line. It is separate from WriteSession, in order to allow to redefine WriteSession without touching WriteEnd (WriteSession defines the body of the file) WriteEnd fills the list of lines. Returns a status of error, 0 if OK, >0 else");
cls_IFSelect_SessionFile.def("WriteLine", [](IFSelect_SessionFile &self, const Standard_CString a0) -> void { return self.WriteLine(a0); });
cls_IFSelect_SessionFile.def("WriteLine", (void (IFSelect_SessionFile::*)(const Standard_CString, const Standard_Character)) &IFSelect_SessionFile::WriteLine, "Writes a line to the File. If <follow> is given, it is added at the following of the line. '' must be added for the end.", py::arg("line"), py::arg("follow"));
cls_IFSelect_SessionFile.def("WriteOwn", (Standard_Boolean (IFSelect_SessionFile::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_SessionFile::WriteOwn, "Writes the Parameters own to each type of Item. Uses the Library of SessionDumpers Returns True if Done, False if <item> could not be treated (hence it remains written with no Own Parameter)", py::arg("item"));
cls_IFSelect_SessionFile.def("ReadSession", (Standard_Integer (IFSelect_SessionFile::*)()) &IFSelect_SessionFile::ReadSession, "Performs a Read Operation from a File to a WorkSession, i.e. reads the list of line (which must have already been loaded, by ReadFile or by calls to AddLine) Important Remark : this excludes the reading of the last line, which is performed by ReadEnd Returns 0 for OK, >0 status for Read Error (not a suitable File, or WorkSession given as Immutable at Creation Time) IsDone can be called too (will return True for OK)");
cls_IFSelect_SessionFile.def("ReadEnd", (Standard_Integer (IFSelect_SessionFile::*)()) &IFSelect_SessionFile::ReadEnd, "Reads the end of a file (its last line). Returns 0 if OK, status >0 in case of error (not a suitable end line).");
cls_IFSelect_SessionFile.def("ReadLine", (Standard_Boolean (IFSelect_SessionFile::*)()) &IFSelect_SessionFile::ReadLine, "Reads a Line and splits it into a set of alphanumeric items, which can then be queried by NbParams/ParamValue ...");
cls_IFSelect_SessionFile.def("SplitLine", (void (IFSelect_SessionFile::*)(const Standard_CString)) &IFSelect_SessionFile::SplitLine, "Internal routine which processes a line into words and prepares its exploration", py::arg("line"));
cls_IFSelect_SessionFile.def("ReadOwn", (Standard_Boolean (IFSelect_SessionFile::*)(opencascade::handle<Standard_Transient> &)) &IFSelect_SessionFile::ReadOwn, "Tries to Read an Item, by calling the Library of Dumpers Sets the list of parameters of the line to be read from the first own one", py::arg("item"));
cls_IFSelect_SessionFile.def("AddItem", [](IFSelect_SessionFile &self, const opencascade::handle<Standard_Transient> & a0) -> void { return self.AddItem(a0); });
cls_IFSelect_SessionFile.def("AddItem", (void (IFSelect_SessionFile::*)(const opencascade::handle<Standard_Transient> &, const Standard_Boolean)) &IFSelect_SessionFile::AddItem, "Adds an Item to the WorkSession, taken as Name the first item of the read Line. If this Name is not a Name but a Number or if this Name is already recorded in the WorkSession, it adds the Item but with no Name. Then the Name is recorded in order to be used by the method ItemValue <active> commands to make <item> active or not in the session", py::arg("item"), py::arg("active"));
cls_IFSelect_SessionFile.def("IsDone", (Standard_Boolean (IFSelect_SessionFile::*)() const) &IFSelect_SessionFile::IsDone, "Returns True if the last Read or Write operation has been corectly performed. ELse returns False.");
cls_IFSelect_SessionFile.def("WorkSession", (opencascade::handle<IFSelect_WorkSession> (IFSelect_SessionFile::*)() const) &IFSelect_SessionFile::WorkSession, "Returns the WorkSession on which a SessionFile works. Remark that it is returned as Immutable.");
cls_IFSelect_SessionFile.def("NewItem", (void (IFSelect_SessionFile::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &)) &IFSelect_SessionFile::NewItem, "At beginning of writing an Item, writes its basics : - either its name in the session if it has one - or its relative number of item in the file, else (preceeded by a '_') - then, its Dynamic Type (in the sense of cdl : pk_class) This basic description can be followed by the parameters which are used in the definition of the item.", py::arg("ident"), py::arg("par"));
cls_IFSelect_SessionFile.def("SetOwn", (void (IFSelect_SessionFile::*)(const Standard_Boolean)) &IFSelect_SessionFile::SetOwn, "Sets Parameters to be sent as Own if <mode> is True (their Name or Number or Void Mark or Text Value is preceeded by a Column sign ':') else they are sent normally Hence, the Own Parameter are clearly identified in the File", py::arg("mode"));
cls_IFSelect_SessionFile.def("SendVoid", (void (IFSelect_SessionFile::*)()) &IFSelect_SessionFile::SendVoid, "During a Write action, commands to send a Void Parameter i.e. a Parameter which is present but undefined Its form will be the dollar sign : $");
cls_IFSelect_SessionFile.def("SendItem", (void (IFSelect_SessionFile::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_SessionFile::SendItem, "During a Write action, commands to send the identification of a Parameter : if it is Null (undefined) it is send as Void ($) if it is Named in the WorkSession, its Name is sent preceeded by ':', else a relative Ident Number is sent preceeded by '#' (relative to the present Write, i.e. starting at one, without skip, and counted part from Named Items)", py::arg("par"));
cls_IFSelect_SessionFile.def("SendText", (void (IFSelect_SessionFile::*)(const Standard_CString)) &IFSelect_SessionFile::SendText, "During a Write action, commands to send a Text without interpretation. It will be sent as well", py::arg("text"));
cls_IFSelect_SessionFile.def("SetLastGeneral", (void (IFSelect_SessionFile::*)(const Standard_Integer)) &IFSelect_SessionFile::SetLastGeneral, "Sets the rank of Last General Parameter to a new value. It is followed by the Fist Own Parameter of the item. Used by SessionFile after reading general parameters.", py::arg("lastgen"));
cls_IFSelect_SessionFile.def("NbParams", (Standard_Integer (IFSelect_SessionFile::*)() const) &IFSelect_SessionFile::NbParams, "During a Read operation, SessionFile processes sequencially the Items to read. For each one, it gives access to the list of its Parameters : they were defined by calls to SendVoid/SendParam/SendText during Writing the File. NbParams returns the count of Parameters for the line currently read.");
cls_IFSelect_SessionFile.def("IsVoid", (Standard_Boolean (IFSelect_SessionFile::*)(const Standard_Integer) const) &IFSelect_SessionFile::IsVoid, "Returns True if a Parameter, given its rank in the Own List (see NbOwnParams), is Void. Returns also True if <num> is out of range (undefined parameters)", py::arg("num"));
cls_IFSelect_SessionFile.def("IsText", (Standard_Boolean (IFSelect_SessionFile::*)(const Standard_Integer) const) &IFSelect_SessionFile::IsText, "Returns True if a Parameter, in the Own List (see NbOwnParams) is a Text (between '...'). Else it is an Item (Parameter, Selection, Dispatch ...), which can be Void.", py::arg("num"));
cls_IFSelect_SessionFile.def("ParamValue", (const TCollection_AsciiString & (IFSelect_SessionFile::*)(const Standard_Integer) const) &IFSelect_SessionFile::ParamValue, "Returns a Parameter (alphanumeric item of a line) as it has been read", py::arg("num"));
cls_IFSelect_SessionFile.def("TextValue", (TCollection_AsciiString (IFSelect_SessionFile::*)(const Standard_Integer) const) &IFSelect_SessionFile::TextValue, "Returns the content of a Text Parameter (without the quotes). Returns an empty string if the Parameter is not a Text.", py::arg("num"));
cls_IFSelect_SessionFile.def("ItemValue", (opencascade::handle<Standard_Transient> (IFSelect_SessionFile::*)(const Standard_Integer) const) &IFSelect_SessionFile::ItemValue, "Returns a Parameter as an Item. Returns a Null Handle if the Parameter is a Text, or if it is defined as Void", py::arg("num"));
cls_IFSelect_SessionFile.def("Destroy", (void (IFSelect_SessionFile::*)()) &IFSelect_SessionFile::Destroy, "Specific Destructor (closes the File if not yet done)");

// TYPEDEF: IFSELECT_TSEQOFDISPATCH
bind_NCollection_Sequence<opencascade::handle<IFSelect_Dispatch> >(mod, "IFSelect_TSeqOfDispatch", py::module_local(false));

// CLASS: IFSELECT_SHAREOUT
py::class_<IFSelect_ShareOut, opencascade::handle<IFSelect_ShareOut>, Standard_Transient> cls_IFSelect_ShareOut(mod, "IFSelect_ShareOut", "This class gathers the informations required to produce one or several file(s) from the content of an InterfaceModel (passing through the creation of intermediate Models).");

// Constructors
cls_IFSelect_ShareOut.def(py::init<>());

// Methods
cls_IFSelect_ShareOut.def("Clear", (void (IFSelect_ShareOut::*)(const Standard_Boolean)) &IFSelect_ShareOut::Clear, "Removes in one operation all the Dispatches with their Idents Also clears all informations about Names, and all Results but naming informations which are : - kept if <onlydisp> is True. - cleared if <onlydisp> is False (complete clearing) If <onlydisp> is True, that's all. Else, clears also Modifiers", py::arg("onlydisp"));
cls_IFSelect_ShareOut.def("ClearResult", (void (IFSelect_ShareOut::*)(const Standard_Boolean)) &IFSelect_ShareOut::ClearResult, "Clears all data produced (apart from Dispatches, etc...) if <alsoname> is True, all is cleared. Else, informations about produced Names are kept (to maintain unicity of naming across clearings)", py::arg("alsoname"));
cls_IFSelect_ShareOut.def("RemoveItem", (Standard_Boolean (IFSelect_ShareOut::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_ShareOut::RemoveItem, "Removes an item, which can be, either a Dispatch (removed from the list of Dispatches), or a GeneralModifier (removed from the list of Model Modifiers or from the list of File Modifiers according to its type). Returns True if done, False if has not been found or if it is neither a Dispatch, nor a Modifier.", py::arg("item"));
cls_IFSelect_ShareOut.def("LastRun", (Standard_Integer (IFSelect_ShareOut::*)() const) &IFSelect_ShareOut::LastRun, "Returns the rank of last run item (ClearResult resets it to 0)");
cls_IFSelect_ShareOut.def("SetLastRun", (void (IFSelect_ShareOut::*)(const Standard_Integer)) &IFSelect_ShareOut::SetLastRun, "Records a new alue for the rank of last run item", py::arg("last"));
cls_IFSelect_ShareOut.def("NbDispatches", (Standard_Integer (IFSelect_ShareOut::*)() const) &IFSelect_ShareOut::NbDispatches, "Returns the count of Dispatches");
cls_IFSelect_ShareOut.def("DispatchRank", (Standard_Integer (IFSelect_ShareOut::*)(const opencascade::handle<IFSelect_Dispatch> &) const) &IFSelect_ShareOut::DispatchRank, "Returns the Rank of a Dispatch, given its Value (Handle). Returns 0 if the Dispatch is unknown in the ShareOut", py::arg("disp"));
cls_IFSelect_ShareOut.def("Dispatch", (const opencascade::handle<IFSelect_Dispatch> & (IFSelect_ShareOut::*)(const Standard_Integer) const) &IFSelect_ShareOut::Dispatch, "Returns a Dispatch, given its rank in the list", py::arg("num"));
cls_IFSelect_ShareOut.def("AddDispatch", (void (IFSelect_ShareOut::*)(const opencascade::handle<IFSelect_Dispatch> &)) &IFSelect_ShareOut::AddDispatch, "Adds a Dispatch to the list", py::arg("disp"));
cls_IFSelect_ShareOut.def("RemoveDispatch", (Standard_Boolean (IFSelect_ShareOut::*)(const Standard_Integer)) &IFSelect_ShareOut::RemoveDispatch, "Removes a Dispatch, given its rank in the list Returns True if done, False if rank is not between (LastRun + 1) and (NbDispatches)", py::arg("rank"));
cls_IFSelect_ShareOut.def("AddModifier", (void (IFSelect_ShareOut::*)(const opencascade::handle<IFSelect_GeneralModifier> &, const Standard_Integer)) &IFSelect_ShareOut::AddModifier, "Sets a Modifier to be applied on all Dispatches to be run If <modifier> is a ModelModifier, adds it to the list of Model Modifiers; else to the list of File Modifiers By default (atnum = 0) at the end of the list, else at <atnum> Each Modifier is used, after each copy of a packet of Entities into a Model : its criteria are checked and if they are OK, the method Perform of this Modifier is run.", py::arg("modifier"), py::arg("atnum"));
cls_IFSelect_ShareOut.def("AddModifier", (void (IFSelect_ShareOut::*)(const opencascade::handle<IFSelect_GeneralModifier> &, const Standard_Integer, const Standard_Integer)) &IFSelect_ShareOut::AddModifier, "Sets a Modifier to be applied on the Dispatch <dispnum> If <modifier> is a ModelModifier, adds it to the list of Model Modifiers; else to the list of File Modifiers This is the same list as for all Dispatches, but the Modifier is qualified to be applied to one Dispatch only Then, <atnum> refers to the entire list By default (atnum = 0) at the end of the list, else at <atnum> Remark : if the Modifier was already in the list and if <atnum> = 0, the Modifier is not moved, but only qualified for a Dispatch", py::arg("modifier"), py::arg("dispnum"), py::arg("atnum"));
cls_IFSelect_ShareOut.def("AddModif", [](IFSelect_ShareOut &self, const opencascade::handle<IFSelect_GeneralModifier> & a0, const Standard_Boolean a1) -> void { return self.AddModif(a0, a1); });
cls_IFSelect_ShareOut.def("AddModif", (void (IFSelect_ShareOut::*)(const opencascade::handle<IFSelect_GeneralModifier> &, const Standard_Boolean, const Standard_Integer)) &IFSelect_ShareOut::AddModif, "Adds a Modifier to the list of Modifiers : Model Modifiers if <formodel> is True, File Modifiers else (internal).", py::arg("modifier"), py::arg("formodel"), py::arg("atnum"));
cls_IFSelect_ShareOut.def("NbModifiers", (Standard_Integer (IFSelect_ShareOut::*)(const Standard_Boolean) const) &IFSelect_ShareOut::NbModifiers, "Returns count of Modifiers (which apply to complete Models) : Model Modifiers if <formodel> is True, File Modifiers else", py::arg("formodel"));
cls_IFSelect_ShareOut.def("GeneralModifier", (opencascade::handle<IFSelect_GeneralModifier> (IFSelect_ShareOut::*)(const Standard_Boolean, const Standard_Integer) const) &IFSelect_ShareOut::GeneralModifier, "Returns a Modifier of the list, given its rank : Model Modifiers if <formodel> is True, File Modifiers else", py::arg("formodel"), py::arg("num"));
cls_IFSelect_ShareOut.def("ModelModifier", (opencascade::handle<IFSelect_Modifier> (IFSelect_ShareOut::*)(const Standard_Integer) const) &IFSelect_ShareOut::ModelModifier, "Returns a Modifier of the list of Model Modifiers, duely casted", py::arg("num"));
cls_IFSelect_ShareOut.def("ModifierRank", (Standard_Integer (IFSelect_ShareOut::*)(const opencascade::handle<IFSelect_GeneralModifier> &) const) &IFSelect_ShareOut::ModifierRank, "Gives the rank of a Modifier in the list, 0 if not in the list Model Modifiers if <modifier> is kind of ModelModifer, File Modifiers else", py::arg("modifier"));
cls_IFSelect_ShareOut.def("RemoveModifier", (Standard_Boolean (IFSelect_ShareOut::*)(const Standard_Boolean, const Standard_Integer)) &IFSelect_ShareOut::RemoveModifier, "Removes a Modifier, given it rank in the list : Model Modifiers if <formodel> is True, File Modifiers else Returns True if done, False if <num> is out of range", py::arg("formodel"), py::arg("num"));
cls_IFSelect_ShareOut.def("ChangeModifierRank", (Standard_Boolean (IFSelect_ShareOut::*)(const Standard_Boolean, const Standard_Integer, const Standard_Integer)) &IFSelect_ShareOut::ChangeModifierRank, "Changes the rank of a modifier in the list : Model Modifiers if <formodel> is True, File Modifiers else from <before> to <after> Returns True if done, False else (before or after out of range)", py::arg("formodel"), py::arg("befor"), py::arg("after"));
cls_IFSelect_ShareOut.def("SetRootName", (Standard_Boolean (IFSelect_ShareOut::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &)) &IFSelect_ShareOut::SetRootName, "Attaches a Root Name to a Dispatch given its rank, as an HAsciiString (standard form). A Null Handle resets this name. Returns True if OK, False if this Name is already attached, for a Dispatch or for Default, or <num> out of range", py::arg("num"), py::arg("name"));
cls_IFSelect_ShareOut.def("HasRootName", (Standard_Boolean (IFSelect_ShareOut::*)(const Standard_Integer) const) &IFSelect_ShareOut::HasRootName, "Returns True if the Dispatch of rank <num> has an attached Root Name. False else, or if num is out of range", py::arg("num"));
cls_IFSelect_ShareOut.def("RootName", (opencascade::handle<TCollection_HAsciiString> (IFSelect_ShareOut::*)(const Standard_Integer) const) &IFSelect_ShareOut::RootName, "Returns the Root bound to a Dispatch, given its rank Returns a Null Handle if not defined", py::arg("num"));
cls_IFSelect_ShareOut.def("RootNumber", (Standard_Integer (IFSelect_ShareOut::*)(const opencascade::handle<TCollection_HAsciiString> &) const) &IFSelect_ShareOut::RootNumber, "Returns an integer value about a given root name : - positive : it's the rank of the Dispatch which has this name - null : this root name is unknown - negative (-1) : this root name is the default root name", py::arg("name"));
cls_IFSelect_ShareOut.def("SetPrefix", (void (IFSelect_ShareOut::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IFSelect_ShareOut::SetPrefix, "Defines or Changes the general Prefix (which is prepended to complete file name generated). If this method is not call, Prefix remains empty", py::arg("pref"));
cls_IFSelect_ShareOut.def("SetDefaultRootName", (Standard_Boolean (IFSelect_ShareOut::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IFSelect_ShareOut::SetDefaultRootName, "Defines or Changes the Default Root Name to a new value (which is used for dispatches which have no attached root name). If this method is not called, DefaultRootName remains empty Returns True if OK, False if this Name is already attached, for a Dispatch or for Default", py::arg("defrt"));
cls_IFSelect_ShareOut.def("SetExtension", (void (IFSelect_ShareOut::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IFSelect_ShareOut::SetExtension, "Defines or Changes the general Extension (which is appended to complete file name generated). If this method is not call, Extension remains empty", py::arg("ext"));
cls_IFSelect_ShareOut.def("Prefix", (opencascade::handle<TCollection_HAsciiString> (IFSelect_ShareOut::*)() const) &IFSelect_ShareOut::Prefix, "Returns the general Prefix. Can be empty.");
cls_IFSelect_ShareOut.def("DefaultRootName", (opencascade::handle<TCollection_HAsciiString> (IFSelect_ShareOut::*)() const) &IFSelect_ShareOut::DefaultRootName, "Returns the Default Root Name. Can be empty.");
cls_IFSelect_ShareOut.def("Extension", (opencascade::handle<TCollection_HAsciiString> (IFSelect_ShareOut::*)() const) &IFSelect_ShareOut::Extension, "Returns the general Extension. Can be empty (not recommanded)");
cls_IFSelect_ShareOut.def("FileName", [](IFSelect_ShareOut &self, const Standard_Integer a0, const Standard_Integer a1) -> TCollection_AsciiString { return self.FileName(a0, a1); });
cls_IFSelect_ShareOut.def("FileName", (TCollection_AsciiString (IFSelect_ShareOut::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &IFSelect_ShareOut::FileName, "Computes the complete file name for a Packet of a Dispatch, given Dispatch Number (Rank), Packet Number, and Count of Packets generated by this Dispatch (0 if unknown)", py::arg("dnum"), py::arg("pnum"), py::arg("nbpack"));
cls_IFSelect_ShareOut.def_static("get_type_name_", (const char * (*)()) &IFSelect_ShareOut::get_type_name, "None");
cls_IFSelect_ShareOut.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_ShareOut::get_type_descriptor, "None");
cls_IFSelect_ShareOut.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_ShareOut::*)() const) &IFSelect_ShareOut::DynamicType, "None");

// CLASS: IFSELECT_SHAREOUTRESULT
py::class_<IFSelect_ShareOutResult> cls_IFSelect_ShareOutResult(mod, "IFSelect_ShareOutResult", "This class gives results computed from a ShareOut : simulation before transfer, helps to list entities ... Transfer itself will later be performed, either by a TransferCopy to simply divide up a file, or a TransferDispatch which can be parametred with more details");

// Constructors
cls_IFSelect_ShareOutResult.def(py::init<const opencascade::handle<IFSelect_ShareOut> &, const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("sho"), py::arg("mod"));
cls_IFSelect_ShareOutResult.def(py::init<const opencascade::handle<IFSelect_ShareOut> &, const Interface_Graph &>(), py::arg("sho"), py::arg("G"));
cls_IFSelect_ShareOutResult.def(py::init<const opencascade::handle<IFSelect_Dispatch> &, const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("disp"), py::arg("mod"));
cls_IFSelect_ShareOutResult.def(py::init<const opencascade::handle<IFSelect_Dispatch> &, const Interface_Graph &>(), py::arg("disp"), py::arg("G"));

// Methods
// cls_IFSelect_ShareOutResult.def_static("operator new_", (void * (*)(size_t)) &IFSelect_ShareOutResult::operator new, "None", py::arg("theSize"));
// cls_IFSelect_ShareOutResult.def_static("operator delete_", (void (*)(void *)) &IFSelect_ShareOutResult::operator delete, "None", py::arg("theAddress"));
// cls_IFSelect_ShareOutResult.def_static("operator new[]_", (void * (*)(size_t)) &IFSelect_ShareOutResult::operator new[], "None", py::arg("theSize"));
// cls_IFSelect_ShareOutResult.def_static("operator delete[]_", (void (*)(void *)) &IFSelect_ShareOutResult::operator delete[], "None", py::arg("theAddress"));
// cls_IFSelect_ShareOutResult.def_static("operator new_", (void * (*)(size_t, void *)) &IFSelect_ShareOutResult::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IFSelect_ShareOutResult.def_static("operator delete_", (void (*)(void *, void *)) &IFSelect_ShareOutResult::operator delete, "None", py::arg(""), py::arg(""));
cls_IFSelect_ShareOutResult.def("ShareOut", (opencascade::handle<IFSelect_ShareOut> (IFSelect_ShareOutResult::*)() const) &IFSelect_ShareOutResult::ShareOut, "Returns the ShareOut used to create the ShareOutResult if creation from a Dispatch, returns a Null Handle");
cls_IFSelect_ShareOutResult.def("Graph", (const Interface_Graph & (IFSelect_ShareOutResult::*)() const) &IFSelect_ShareOutResult::Graph, "Returns the Graph used to create theShareOutResult");
cls_IFSelect_ShareOutResult.def("Reset", (void (IFSelect_ShareOutResult::*)()) &IFSelect_ShareOutResult::Reset, "Erases computed data, in order to command a new Evaluation");
cls_IFSelect_ShareOutResult.def("Evaluate", (void (IFSelect_ShareOutResult::*)()) &IFSelect_ShareOutResult::Evaluate, "Evaluates the result of a ShareOut : determines Entities to be forgotten by the ShareOut, Entities to be transferred several times (duplicated), prepares an iteration on the packets to be produced Called the first time anyone question is asked, or after a call to Reset. Works by calling the method Prepare.");
cls_IFSelect_ShareOutResult.def("Packets", [](IFSelect_ShareOutResult &self) -> opencascade::handle<IFSelect_PacketList> { return self.Packets(); });
cls_IFSelect_ShareOutResult.def("Packets", (opencascade::handle<IFSelect_PacketList> (IFSelect_ShareOutResult::*)(const Standard_Boolean)) &IFSelect_ShareOutResult::Packets, "Returns the list of recorded Packets, under two modes : - <complete> = False, the strict definition of Packets, i.e. for each one, the Root Entities, to be explicitely sent - <complete> = True (Default), the completely evaluated list, i.e. which really gives the destination of each entity : this mode allows to evaluate duplications Remark that to send packets, iteration remains preferable (file names are managed)", py::arg("complete"));
cls_IFSelect_ShareOutResult.def("NbPackets", (Standard_Integer (IFSelect_ShareOutResult::*)()) &IFSelect_ShareOutResult::NbPackets, "Returns the total count of produced non empty packets (in out : calls Evaluate as necessary)");
cls_IFSelect_ShareOutResult.def("Prepare", (void (IFSelect_ShareOutResult::*)()) &IFSelect_ShareOutResult::Prepare, "Prepares the iteration on the packets This method is called by Evaluate, but can be called anytime The iteration consists in taking each Dispatch of the ShareOut beginning by the first one, compute its packets, then iterate on these packets. Once all these packets are iterated, the iteration passes to the next Dispatch, or stops. For a creation from a unique Dispatch, same but with only this Dispatch. Each packet can be listed, or really transferred (producing a derived Model, from which a file can be generated)");
cls_IFSelect_ShareOutResult.def("More", (Standard_Boolean (IFSelect_ShareOutResult::*)()) &IFSelect_ShareOutResult::More, "Returns True if there is more packets in the current Dispatch, else if there is more Dispatch in the ShareOut");
cls_IFSelect_ShareOutResult.def("Next", (void (IFSelect_ShareOutResult::*)()) &IFSelect_ShareOutResult::Next, "Passes to the next Packet in the current Dispatch, or if there is none, to the next Dispatch in the ShareOut");
cls_IFSelect_ShareOutResult.def("NextDispatch", (void (IFSelect_ShareOutResult::*)()) &IFSelect_ShareOutResult::NextDispatch, "Passes to the next Dispatch, regardless about remaining packets");
cls_IFSelect_ShareOutResult.def("Dispatch", (opencascade::handle<IFSelect_Dispatch> (IFSelect_ShareOutResult::*)() const) &IFSelect_ShareOutResult::Dispatch, "Returns the current Dispatch");
cls_IFSelect_ShareOutResult.def("DispatchRank", (Standard_Integer (IFSelect_ShareOutResult::*)() const) &IFSelect_ShareOutResult::DispatchRank, "Returns the Rank of the current Dispatch in the ShareOut Returns Zero if there is none (iteration finished)");
cls_IFSelect_ShareOutResult.def("PacketsInDispatch", [](IFSelect_ShareOutResult &self, Standard_Integer & numpack, Standard_Integer & nbpacks){ self.PacketsInDispatch(numpack, nbpacks); return std::tuple<Standard_Integer &, Standard_Integer &>(numpack, nbpacks); }, "Returns Number (rank) of current Packet in current Dispatch, and total count of Packets in current Dispatch, as arguments", py::arg("numpack"), py::arg("nbpacks"));
cls_IFSelect_ShareOutResult.def("PacketRoot", (Interface_EntityIterator (IFSelect_ShareOutResult::*)()) &IFSelect_ShareOutResult::PacketRoot, "Returns the list of Roots of the current Packet (never empty) (i.e. the Entities to be themselves asked for transfer) Error if there is none (iteration finished)");
cls_IFSelect_ShareOutResult.def("PacketContent", (Interface_EntityIterator (IFSelect_ShareOutResult::*)()) &IFSelect_ShareOutResult::PacketContent, "Returns the complete content of the current Packet (i.e. with shared entities, which will also be put in the file)");
cls_IFSelect_ShareOutResult.def("FileName", (TCollection_AsciiString (IFSelect_ShareOutResult::*)() const) &IFSelect_ShareOutResult::FileName, "Returns the File Name which corresponds to current Packet (computed by ShareOut) If current Packet has no associated name (see ShareOut), the returned value is Null");

// CLASS: IFSELECT_SIGNATURE
py::class_<IFSelect_Signature, opencascade::handle<IFSelect_Signature>, Interface_SignType> cls_IFSelect_Signature(mod, "IFSelect_Signature", "Signature provides the basic service used by the classes SelectSignature and Counter (i.e. Name, Value), which is : - for an entity in a model, give a characteristic string, its signature This string has not to be unique in the model, but gives a value for such or such important feature. Exemples : Dynamic Type; Category; etc");

// Methods
cls_IFSelect_Signature.def("SetIntCase", (void (IFSelect_Signature::*)(const Standard_Boolean, const Standard_Integer, const Standard_Boolean, const Standard_Integer)) &IFSelect_Signature::SetIntCase, "Sets the information data to tell 'integer cases' with possible min and max values To be called when creating", py::arg("hasmin"), py::arg("valmin"), py::arg("hasmax"), py::arg("valmax"));
cls_IFSelect_Signature.def("IsIntCase", [](IFSelect_Signature &self, Standard_Boolean & hasmin, Standard_Integer & valmin, Standard_Boolean & hasmax, Standard_Integer & valmax){ Standard_Boolean rv = self.IsIntCase(hasmin, valmin, hasmax, valmax); return std::tuple<Standard_Boolean, Standard_Boolean &, Standard_Integer &, Standard_Boolean &, Standard_Integer &>(rv, hasmin, valmin, hasmax, valmax); }, "Tells if this Signature gives integer values and returns values from SetIntCase if True", py::arg("hasmin"), py::arg("valmin"), py::arg("hasmax"), py::arg("valmax"));
cls_IFSelect_Signature.def("AddCase", (void (IFSelect_Signature::*)(const Standard_CString)) &IFSelect_Signature::AddCase, "Adds a possible case To be called when creating, IF the list of possible cases for Value is known when starting For instance, for CDL types, rather do not fill this, but for a specific enumeration (such as a status), can be used", py::arg("acase"));
cls_IFSelect_Signature.def("CaseList", (opencascade::handle<TColStd_HSequenceOfAsciiString> (IFSelect_Signature::*)() const) &IFSelect_Signature::CaseList, "Returns the predefined list of possible cases, filled by AddCase Null Handle if no predefined list (hence, to be counted) Useful to filter on really possible vase, for instance, or for a help");
cls_IFSelect_Signature.def("Name", (Standard_CString (IFSelect_Signature::*)() const) &IFSelect_Signature::Name, "Returns an identification of the Signature (a word), given at initialization time Returns the Signature for a Transient object. It is specific of each sub-class of Signature. For a Null Handle, it should provide '' It can work with the model which contains the entity");
cls_IFSelect_Signature.def("Label", (TCollection_AsciiString (IFSelect_Signature::*)() const) &IFSelect_Signature::Label, "The label of a Signature uses its name as follow : 'Signature : <name>'");
cls_IFSelect_Signature.def("Matches", (Standard_Boolean (IFSelect_Signature::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &, const TCollection_AsciiString &, const Standard_Boolean) const) &IFSelect_Signature::Matches, "Tells if the value for <ent> in <model> matches a text, with a criterium <exact>. The default definition calls MatchValue Can be redefined", py::arg("ent"), py::arg("model"), py::arg("text"), py::arg("exact"));
cls_IFSelect_Signature.def_static("MatchValue_", (Standard_Boolean (*)(const Standard_CString, const TCollection_AsciiString &, const Standard_Boolean)) &IFSelect_Signature::MatchValue, "Default procedure to tell if a value <val> matches a text with a criterium <exact>. <exact> = True requires equality, else only contained (no reg-exp)", py::arg("val"), py::arg("text"), py::arg("exact"));
cls_IFSelect_Signature.def_static("IntValue_", (Standard_CString (*)(const Standard_Integer)) &IFSelect_Signature::IntValue, "This procedure converts an Integer to a CString It is a convenient way when the value of a signature has the form of a simple integer value The value is to be used immediately (one buffer only, no copy)", py::arg("val"));
cls_IFSelect_Signature.def_static("get_type_name_", (const char * (*)()) &IFSelect_Signature::get_type_name, "None");
cls_IFSelect_Signature.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_Signature::get_type_descriptor, "None");
cls_IFSelect_Signature.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_Signature::*)() const) &IFSelect_Signature::DynamicType, "None");

// CLASS: IFSELECT_SIGNTYPE
py::class_<IFSelect_SignType, opencascade::handle<IFSelect_SignType>, IFSelect_Signature> cls_IFSelect_SignType(mod, "IFSelect_SignType", "This Signature returns the cdl Type of an entity, under two forms : - complete dynamic type (package and class) - class type, without package name");

// Constructors
cls_IFSelect_SignType.def(py::init<>());
cls_IFSelect_SignType.def(py::init<const Standard_Boolean>(), py::arg("nopk"));

// Methods
cls_IFSelect_SignType.def("Value", (Standard_CString (IFSelect_SignType::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_SignType::Value, "Returns the Signature for a Transient object, as its Dynamic Type, with or without package name, according starting option", py::arg("ent"), py::arg("model"));
cls_IFSelect_SignType.def_static("get_type_name_", (const char * (*)()) &IFSelect_SignType::get_type_name, "None");
cls_IFSelect_SignType.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SignType::get_type_descriptor, "None");
cls_IFSelect_SignType.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SignType::*)() const) &IFSelect_SignType::DynamicType, "None");

// CLASS: IFSELECT_SIGNANCESTOR
py::class_<IFSelect_SignAncestor, opencascade::handle<IFSelect_SignAncestor>, IFSelect_SignType> cls_IFSelect_SignAncestor(mod, "IFSelect_SignAncestor", "None");

// Constructors
cls_IFSelect_SignAncestor.def(py::init<>());
cls_IFSelect_SignAncestor.def(py::init<const Standard_Boolean>(), py::arg("nopk"));

// Methods
cls_IFSelect_SignAncestor.def("Matches", (Standard_Boolean (IFSelect_SignAncestor::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &, const TCollection_AsciiString &, const Standard_Boolean) const) &IFSelect_SignAncestor::Matches, "None", py::arg("ent"), py::arg("model"), py::arg("text"), py::arg("exact"));
cls_IFSelect_SignAncestor.def_static("get_type_name_", (const char * (*)()) &IFSelect_SignAncestor::get_type_name, "None");
cls_IFSelect_SignAncestor.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SignAncestor::get_type_descriptor, "None");
cls_IFSelect_SignAncestor.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SignAncestor::*)() const) &IFSelect_SignAncestor::DynamicType, "None");

// CLASS: IFSELECT_SIGNCATEGORY
py::class_<IFSelect_SignCategory, opencascade::handle<IFSelect_SignCategory>, IFSelect_Signature> cls_IFSelect_SignCategory(mod, "IFSelect_SignCategory", "This Signature returns the Category of an entity, as recorded in the model");

// Constructors
cls_IFSelect_SignCategory.def(py::init<>());

// Methods
cls_IFSelect_SignCategory.def("Value", (Standard_CString (IFSelect_SignCategory::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_SignCategory::Value, "Returns the Signature for a Transient object, as its Category recorded in the model", py::arg("ent"), py::arg("model"));
cls_IFSelect_SignCategory.def_static("get_type_name_", (const char * (*)()) &IFSelect_SignCategory::get_type_name, "None");
cls_IFSelect_SignCategory.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SignCategory::get_type_descriptor, "None");
cls_IFSelect_SignCategory.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SignCategory::*)() const) &IFSelect_SignCategory::DynamicType, "None");

// CLASS: IFSELECT_SIGNMULTIPLE
py::class_<IFSelect_SignMultiple, opencascade::handle<IFSelect_SignMultiple>, IFSelect_Signature> cls_IFSelect_SignMultiple(mod, "IFSelect_SignMultiple", "Multiple Signature : ordered list of other Signatures It concatenates on a same line the result of its sub-items separated by sets of 3 blanks It is possible to define tabulations between sub-items Moreover, match rules are specific");

// Constructors
cls_IFSelect_SignMultiple.def(py::init<const Standard_CString>(), py::arg("name"));

// Methods
cls_IFSelect_SignMultiple.def("Add", [](IFSelect_SignMultiple &self, const opencascade::handle<IFSelect_Signature> & a0) -> void { return self.Add(a0); });
cls_IFSelect_SignMultiple.def("Add", [](IFSelect_SignMultiple &self, const opencascade::handle<IFSelect_Signature> & a0, const Standard_Integer a1) -> void { return self.Add(a0, a1); });
cls_IFSelect_SignMultiple.def("Add", (void (IFSelect_SignMultiple::*)(const opencascade::handle<IFSelect_Signature> &, const Standard_Integer, const Standard_Boolean)) &IFSelect_SignMultiple::Add, "Adds a Signature. Width, if given, gives the tabulation If <maxi> is True, it is a forced tabulation (overlength is replaced by a final dot) If <maxi> is False, just 3 blanks follow an overlength", py::arg("subsign"), py::arg("width"), py::arg("maxi"));
cls_IFSelect_SignMultiple.def("Value", (Standard_CString (IFSelect_SignMultiple::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_SignMultiple::Value, "Concatenates the values of sub-signatures, with their tabulations", py::arg("ent"), py::arg("model"));
cls_IFSelect_SignMultiple.def("Matches", (Standard_Boolean (IFSelect_SignMultiple::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &, const TCollection_AsciiString &, const Standard_Boolean) const) &IFSelect_SignMultiple::Matches, "Specialized Match Rule If <exact> is False, simply checks if at least one sub-item matches If <exact> is True, standard match with Value (i.e. tabulations must be respected)", py::arg("ent"), py::arg("model"), py::arg("text"), py::arg("exact"));
cls_IFSelect_SignMultiple.def_static("get_type_name_", (const char * (*)()) &IFSelect_SignMultiple::get_type_name, "None");
cls_IFSelect_SignMultiple.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SignMultiple::get_type_descriptor, "None");
cls_IFSelect_SignMultiple.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SignMultiple::*)() const) &IFSelect_SignMultiple::DynamicType, "None");

// CLASS: IFSELECT_SIGNVALIDITY
py::class_<IFSelect_SignValidity, opencascade::handle<IFSelect_SignValidity>, IFSelect_Signature> cls_IFSelect_SignValidity(mod, "IFSelect_SignValidity", "This Signature returns the Validity Status of an entity, as deducted from data in the model : it can be 'OK' 'Unknown' 'Unloaded' 'Syntactic Fail'(but loaded) 'Syntactic Warning' 'Semantic Fail' 'Semantic Warning'");

// Constructors
cls_IFSelect_SignValidity.def(py::init<>());

// Methods
cls_IFSelect_SignValidity.def_static("CVal_", (Standard_CString (*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &)) &IFSelect_SignValidity::CVal, "Returns the Signature for a Transient object, as a validity deducted from data (reports) stored in the model. Class method, can be called by any one", py::arg("ent"), py::arg("model"));
cls_IFSelect_SignValidity.def("Value", (Standard_CString (IFSelect_SignValidity::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_SignValidity::Value, "Returns the Signature for a Transient object, as a validity deducted from data (reports) stored in the model Calls the class method CVal", py::arg("ent"), py::arg("model"));
cls_IFSelect_SignValidity.def_static("get_type_name_", (const char * (*)()) &IFSelect_SignValidity::get_type_name, "None");
cls_IFSelect_SignValidity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SignValidity::get_type_descriptor, "None");
cls_IFSelect_SignValidity.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SignValidity::*)() const) &IFSelect_SignValidity::DynamicType, "None");

// CLASS: IFSELECT_TRANSFORMER
py::class_<IFSelect_Transformer, opencascade::handle<IFSelect_Transformer>, Standard_Transient> cls_IFSelect_Transformer(mod, "IFSelect_Transformer", "A Transformer defines the way an InterfaceModel is transformed (without sending it to a file). In order to work, each type of Transformer defines it method Perform, it can be parametred as needed.");

// Methods
cls_IFSelect_Transformer.def("Perform", (Standard_Boolean (IFSelect_Transformer::*)(const Interface_Graph &, const opencascade::handle<Interface_Protocol> &, Interface_CheckIterator &, opencascade::handle<Interface_InterfaceModel> &)) &IFSelect_Transformer::Perform, "Performs a Transformation (defined by each sub-class) : <G> gives the input data (especially the starting model) and can be used for queries (by Selections, etc...) <protocol> allows to work with General Services as necessary (it applies to input data) If the change corresponds to a conversion to a new protocol, see also the method ChangeProtocol <checks> stores produced checks messages if any <newmod> gives the result of the transformation : - if it is Null (i.e. has not been affected), the transformation has been made on the spot, it is assumed to cause no change to the graph of dependances - if it equates the starting Model, it has been transformed on the spot (possibiliy some entities were replaced inside it) - if it is new, it corresponds to a new data set which replaces the starting one", py::arg("G"), py::arg("protocol"), py::arg("checks"), py::arg("newmod"));
cls_IFSelect_Transformer.def("ChangeProtocol", (Standard_Boolean (IFSelect_Transformer::*)(opencascade::handle<Interface_Protocol> &) const) &IFSelect_Transformer::ChangeProtocol, "This methods allows to declare that the Protocol applied to the new Model has changed. It applies to the last call to Perform.", py::arg("newproto"));
cls_IFSelect_Transformer.def("Updated", (Standard_Boolean (IFSelect_Transformer::*)(const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &) const) &IFSelect_Transformer::Updated, "This method allows to know what happened to a starting entity after the last Perform. If <entfrom> (from starting model) has one and only one known item which corresponds in the new produced model, this method must return True and fill the argument <entto>. Else, it returns False.", py::arg("entfrom"), py::arg("entto"));
cls_IFSelect_Transformer.def("Label", (TCollection_AsciiString (IFSelect_Transformer::*)() const) &IFSelect_Transformer::Label, "Returns a text which defines the way a Transformer works (to identify the transformation it performs)");
cls_IFSelect_Transformer.def_static("get_type_name_", (const char * (*)()) &IFSelect_Transformer::get_type_name, "None");
cls_IFSelect_Transformer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_Transformer::get_type_descriptor, "None");
cls_IFSelect_Transformer.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_Transformer::*)() const) &IFSelect_Transformer::DynamicType, "None");

// CLASS: IFSELECT_TRANSFORMSTANDARD
py::class_<IFSelect_TransformStandard, opencascade::handle<IFSelect_TransformStandard>, IFSelect_Transformer> cls_IFSelect_TransformStandard(mod, "IFSelect_TransformStandard", "This class runs transformations made by Modifiers, as the ModelCopier does when it produces files (the same set of Modifiers can then be used, as to transform the starting Model, as at file sending time).");

// Constructors
cls_IFSelect_TransformStandard.def(py::init<>());

// Methods
cls_IFSelect_TransformStandard.def("SetCopyOption", (void (IFSelect_TransformStandard::*)(const Standard_Boolean)) &IFSelect_TransformStandard::SetCopyOption, "Sets the Copy option to a new value : - True for StandardCopy - False for OnTheSpot", py::arg("option"));
cls_IFSelect_TransformStandard.def("CopyOption", (Standard_Boolean (IFSelect_TransformStandard::*)() const) &IFSelect_TransformStandard::CopyOption, "Returns the Copy option");
cls_IFSelect_TransformStandard.def("SetSelection", (void (IFSelect_TransformStandard::*)(const opencascade::handle<IFSelect_Selection> &)) &IFSelect_TransformStandard::SetSelection, "Sets a Selection (or unsets if Null) This Selection then defines the list of entities on which the Modifiers will be applied If it is set, it has priority on Selections of Modifiers Else, for each Modifier its Selection is evaluated By default, all the Model is taken", py::arg("sel"));
cls_IFSelect_TransformStandard.def("Selection", (opencascade::handle<IFSelect_Selection> (IFSelect_TransformStandard::*)() const) &IFSelect_TransformStandard::Selection, "Returns the Selection, Null by default");
cls_IFSelect_TransformStandard.def("NbModifiers", (Standard_Integer (IFSelect_TransformStandard::*)() const) &IFSelect_TransformStandard::NbModifiers, "Returns the count of recorded Modifiers");
cls_IFSelect_TransformStandard.def("Modifier", (opencascade::handle<IFSelect_Modifier> (IFSelect_TransformStandard::*)(const Standard_Integer) const) &IFSelect_TransformStandard::Modifier, "Returns a Modifier given its rank in the list", py::arg("num"));
cls_IFSelect_TransformStandard.def("ModifierRank", (Standard_Integer (IFSelect_TransformStandard::*)(const opencascade::handle<IFSelect_Modifier> &) const) &IFSelect_TransformStandard::ModifierRank, "Returns the rank of a Modifier in the list, 0 if unknown", py::arg("modif"));
cls_IFSelect_TransformStandard.def("AddModifier", [](IFSelect_TransformStandard &self, const opencascade::handle<IFSelect_Modifier> & a0) -> Standard_Boolean { return self.AddModifier(a0); });
cls_IFSelect_TransformStandard.def("AddModifier", (Standard_Boolean (IFSelect_TransformStandard::*)(const opencascade::handle<IFSelect_Modifier> &, const Standard_Integer)) &IFSelect_TransformStandard::AddModifier, "Adds a Modifier to the list : - <atnum> = 0 (default) : at the end of the list - <atnum> > 0 : at rank <atnum> Returns True if done, False if <atnum> is out of range", py::arg("modif"), py::arg("atnum"));
cls_IFSelect_TransformStandard.def("RemoveModifier", (Standard_Boolean (IFSelect_TransformStandard::*)(const opencascade::handle<IFSelect_Modifier> &)) &IFSelect_TransformStandard::RemoveModifier, "Removes a Modifier from the list Returns True if done, False if <modif> not in the list", py::arg("modif"));
cls_IFSelect_TransformStandard.def("RemoveModifier", (Standard_Boolean (IFSelect_TransformStandard::*)(const Standard_Integer)) &IFSelect_TransformStandard::RemoveModifier, "Removes a Modifier from the list, given its rank Returns True if done, False if <num> is out of range", py::arg("num"));
cls_IFSelect_TransformStandard.def("Perform", (Standard_Boolean (IFSelect_TransformStandard::*)(const Interface_Graph &, const opencascade::handle<Interface_Protocol> &, Interface_CheckIterator &, opencascade::handle<Interface_InterfaceModel> &)) &IFSelect_TransformStandard::Perform, "Performs the Standard Transformation, by calling Copy then ApplyModifiers (which can return an error status)", py::arg("G"), py::arg("protocol"), py::arg("checks"), py::arg("newmod"));
cls_IFSelect_TransformStandard.def("Copy", (void (IFSelect_TransformStandard::*)(const Interface_Graph &, Interface_CopyTool &, opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_TransformStandard::Copy, "This the first operation. It calls StandardCopy or OnTheSpot according the option", py::arg("G"), py::arg("TC"), py::arg("newmod"));
cls_IFSelect_TransformStandard.def("StandardCopy", (void (IFSelect_TransformStandard::*)(const Interface_Graph &, Interface_CopyTool &, opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_TransformStandard::StandardCopy, "This is the standard action of Copy : its takes into account only the remaining entities (noted by Graph Status positive) and their proper dependances of course. Produces a new model.", py::arg("G"), py::arg("TC"), py::arg("newmod"));
cls_IFSelect_TransformStandard.def("OnTheSpot", (void (IFSelect_TransformStandard::*)(const Interface_Graph &, Interface_CopyTool &, opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_TransformStandard::OnTheSpot, "This is the OnTheSpot action : each entity is bound with ... itself. The produced model is the same as the starting one.", py::arg("G"), py::arg("TC"), py::arg("newmod"));
cls_IFSelect_TransformStandard.def("ApplyModifiers", (Standard_Boolean (IFSelect_TransformStandard::*)(const Interface_Graph &, const opencascade::handle<Interface_Protocol> &, Interface_CopyTool &, Interface_CheckIterator &, opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_TransformStandard::ApplyModifiers, "Applies the modifiers sequencially. For each one, prepares required data (if a Selection is associated as a filter). For the option OnTheSpot, it determines if the graph may be changed and updates <newmod> if required If a Modifier causes an error (check 'HasFailed'), ApplyModifier stops : the following Modifiers are ignored", py::arg("G"), py::arg("protocol"), py::arg("TC"), py::arg("checks"), py::arg("newmod"));
cls_IFSelect_TransformStandard.def("Updated", (Standard_Boolean (IFSelect_TransformStandard::*)(const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &) const) &IFSelect_TransformStandard::Updated, "This methods allows to know what happened to a starting entity after the last Perform. It reads result from the map which was filled by Perform.", py::arg("entfrom"), py::arg("entto"));
cls_IFSelect_TransformStandard.def("Label", (TCollection_AsciiString (IFSelect_TransformStandard::*)() const) &IFSelect_TransformStandard::Label, "Returns a text which defines the way a Transformer works : 'On the spot edition' or 'Standard Copy' followed by '<nn> Modifiers'");
cls_IFSelect_TransformStandard.def_static("get_type_name_", (const char * (*)()) &IFSelect_TransformStandard::get_type_name, "None");
cls_IFSelect_TransformStandard.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_TransformStandard::get_type_descriptor, "None");
cls_IFSelect_TransformStandard.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_TransformStandard::*)() const) &IFSelect_TransformStandard::DynamicType, "None");

// CLASS: IFSELECT_WORKLIBRARY
py::class_<IFSelect_WorkLibrary, opencascade::handle<IFSelect_WorkLibrary>, Standard_Transient> cls_IFSelect_WorkLibrary(mod, "IFSelect_WorkLibrary", "This class defines the (empty) frame which can be used to enrich a XSTEP set with new capabilities In particular, a specific WorkLibrary must give the way for Reading a File into a Model, and Writing a Model to a File Thus, it is possible to define several Work Libraries for each norm, but recommanded to define one general class for each one : this general class will define the Read and Write methods.");

// Methods
cls_IFSelect_WorkLibrary.def("ReadFile", (Standard_Integer (IFSelect_WorkLibrary::*)(const Standard_CString, opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &) const) &IFSelect_WorkLibrary::ReadFile, "Gives the way to Read a File and transfer it to a Model <mod> is the resulting Model, which has to be created by this method. In case of error, <mod> must be returned Null Return value is a status with free values. Simply, 0 is for 'Execution OK' The Protocol can be used to work (e.g. create the Model, read and recognize the Entities)", py::arg("name"), py::arg("model"), py::arg("protocol"));
cls_IFSelect_WorkLibrary.def("WriteFile", (Standard_Boolean (IFSelect_WorkLibrary::*)(IFSelect_ContextWrite &) const) &IFSelect_WorkLibrary::WriteFile, "Gives the way to Write a File from a Model. <ctx> contains all necessary informations : the model, the protocol, the file name, and the list of File Modifiers to be applied, also with restricted list of selected entities for each one, if required. In return, it brings the produced check-list", py::arg("ctx"));
cls_IFSelect_WorkLibrary.def("CopyModel", (Standard_Boolean (IFSelect_WorkLibrary::*)(const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_InterfaceModel> &, const Interface_EntityIterator &, Interface_CopyTool &) const) &IFSelect_WorkLibrary::CopyModel, "Performs the copy of entities from an original model to a new one. It must also copy headers if any. Returns True when done. The provided default works by copying the individual entities designated in the list, by using the general service class CopyTool. It can be redefined for a norm which, either implements Copy by another way (do not forget to Bind each copied result with its original entity in TC) and returns True, or does not know how to copy and returns False", py::arg("original"), py::arg("newmodel"), py::arg("list"), py::arg("TC"));
cls_IFSelect_WorkLibrary.def("DumpEntity", (void (IFSelect_WorkLibrary::*)(const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IFSelect_WorkLibrary::DumpEntity, "Gives the way of dumping an entity under a form comprehensive for each norm. <model> helps to identify, number ... entities. <level> is to be interpreted for each norm (because of the formats which can be very different)", py::arg("model"), py::arg("protocol"), py::arg("entity"), py::arg("S"), py::arg("level"));
cls_IFSelect_WorkLibrary.def("DumpEntity", (void (IFSelect_WorkLibrary::*)(const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Message_Messenger> &) const) &IFSelect_WorkLibrary::DumpEntity, "Calls deferred DumpEntity with the recorded default level", py::arg("model"), py::arg("protocol"), py::arg("entity"), py::arg("S"));
cls_IFSelect_WorkLibrary.def("SetDumpLevels", (void (IFSelect_WorkLibrary::*)(const Standard_Integer, const Standard_Integer)) &IFSelect_WorkLibrary::SetDumpLevels, "Records a default level and a maximum value for level level for DumpEntity can go between 0 and <max> default value will be <def>", py::arg("def"), py::arg("max"));
cls_IFSelect_WorkLibrary.def("DumpLevels", [](IFSelect_WorkLibrary &self, Standard_Integer & def, Standard_Integer & max){ self.DumpLevels(def, max); return std::tuple<Standard_Integer &, Standard_Integer &>(def, max); }, "Returns the recorded default and maximum dump levels If none was recorded, max is returned negative, def as zero", py::arg("def"), py::arg("max"));
cls_IFSelect_WorkLibrary.def("SetDumpHelp", (void (IFSelect_WorkLibrary::*)(const Standard_Integer, const Standard_CString)) &IFSelect_WorkLibrary::SetDumpHelp, "Records a short line of help for a level (0 - max)", py::arg("level"), py::arg("help"));
cls_IFSelect_WorkLibrary.def("DumpHelp", (Standard_CString (IFSelect_WorkLibrary::*)(const Standard_Integer) const) &IFSelect_WorkLibrary::DumpHelp, "Returns the help line recorded for <level>, or an empty string", py::arg("level"));
cls_IFSelect_WorkLibrary.def_static("get_type_name_", (const char * (*)()) &IFSelect_WorkLibrary::get_type_name, "None");
cls_IFSelect_WorkLibrary.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_WorkLibrary::get_type_descriptor, "None");
cls_IFSelect_WorkLibrary.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_WorkLibrary::*)() const) &IFSelect_WorkLibrary::DynamicType, "None");

// CLASS: IFSELECT_WORKSESSION
py::class_<IFSelect_WorkSession, opencascade::handle<IFSelect_WorkSession>, Standard_Transient> cls_IFSelect_WorkSession(mod, "IFSelect_WorkSession", "This class can be used to simply manage a process such as splitting a file, extracting a set of Entities ... It allows to manage different types of Variables : Integer or Text Parameters, Selections, Dispatches, in addition to a ShareOut. To each of these variables, a unique Integer Identifier is attached. A Name can be attached too as desired.");

// Constructors
cls_IFSelect_WorkSession.def(py::init<>());

// Methods
cls_IFSelect_WorkSession.def("SetErrorHandle", (void (IFSelect_WorkSession::*)(const Standard_Boolean)) &IFSelect_WorkSession::SetErrorHandle, "Changes the Error Handler status (by default, it is not set)", py::arg("toHandle"));
cls_IFSelect_WorkSession.def("ErrorHandle", (Standard_Boolean (IFSelect_WorkSession::*)() const) &IFSelect_WorkSession::ErrorHandle, "Returns the Error Handler status");
cls_IFSelect_WorkSession.def("ShareOut", (const opencascade::handle<IFSelect_ShareOut> & (IFSelect_WorkSession::*)() const) &IFSelect_WorkSession::ShareOut, "Returns the ShareOut defined at creation time");
cls_IFSelect_WorkSession.def("SetShareOut", (void (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_ShareOut> &)) &IFSelect_WorkSession::SetShareOut, "Sets a new ShareOut. Fills Items which its content Warning : data from the former ShareOut are lost", py::arg("shareout"));
cls_IFSelect_WorkSession.def("SetModeStat", (void (IFSelect_WorkSession::*)(const Standard_Boolean)) &IFSelect_WorkSession::SetModeStat, "Set value of mode responsible for precence of selections after loading If mode set to true that different selections will be accessible after loading else selections will be not accessible after loading( for economy memory in applicatios)", py::arg("theMode"));
cls_IFSelect_WorkSession.def("GetModeStat", (Standard_Boolean (IFSelect_WorkSession::*)() const) &IFSelect_WorkSession::GetModeStat, "Return value of mode defining of filling selection during loading");
cls_IFSelect_WorkSession.def("SetLibrary", (void (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_WorkLibrary> &)) &IFSelect_WorkSession::SetLibrary, "Sets a WorkLibrary, which will be used to Read and Write Files", py::arg("theLib"));
cls_IFSelect_WorkSession.def("WorkLibrary", (const opencascade::handle<IFSelect_WorkLibrary> & (IFSelect_WorkSession::*)() const) &IFSelect_WorkSession::WorkLibrary, "Returns the WorkLibrary. Null Handle if not yet set should be C++ : return const &");
cls_IFSelect_WorkSession.def("SetProtocol", (void (IFSelect_WorkSession::*)(const opencascade::handle<Interface_Protocol> &)) &IFSelect_WorkSession::SetProtocol, "Sets a Protocol, which will be used to determine Graphs, to Read and to Write Files", py::arg("protocol"));
cls_IFSelect_WorkSession.def("Protocol", (const opencascade::handle<Interface_Protocol> & (IFSelect_WorkSession::*)() const) &IFSelect_WorkSession::Protocol, "Returns the Protocol. Null Handle if not yet set should be C++ : return const &");
cls_IFSelect_WorkSession.def("SetSignType", (void (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_Signature> &)) &IFSelect_WorkSession::SetSignType, "Sets a specific Signature to be the SignType, i.e. the Signature which will determine TypeName from the Model (basic function). It is recorded in the GTool This Signature is also set as 'xst-sign-type' (reserved name)", py::arg("signtype"));
cls_IFSelect_WorkSession.def("SignType", (opencascade::handle<IFSelect_Signature> (IFSelect_WorkSession::*)() const) &IFSelect_WorkSession::SignType, "Returns the current SignType");
cls_IFSelect_WorkSession.def("HasModel", (Standard_Boolean (IFSelect_WorkSession::*)() const) &IFSelect_WorkSession::HasModel, "Returns True is a Model has been set");
cls_IFSelect_WorkSession.def("SetModel", [](IFSelect_WorkSession &self, const opencascade::handle<Interface_InterfaceModel> & a0) -> void { return self.SetModel(a0); });
cls_IFSelect_WorkSession.def("SetModel", (void (IFSelect_WorkSession::*)(const opencascade::handle<Interface_InterfaceModel> &, const Standard_Boolean)) &IFSelect_WorkSession::SetModel, "Sets a Model as input : this will be the Model from which the ShareOut will work if <clearpointed> is True (default) all SelectPointed items are cleared, else they must be managed by the caller Remark : SetModel clears the Graph, recomputes it if a Protocol is set and if the Model is not empty, of course", py::arg("model"), py::arg("clearpointed"));
cls_IFSelect_WorkSession.def("Model", (const opencascade::handle<Interface_InterfaceModel> & (IFSelect_WorkSession::*)() const) &IFSelect_WorkSession::Model, "Returns the Model of the Work Session (Null Handle if none) should be C++ : return const &");
cls_IFSelect_WorkSession.def("SetLoadedFile", (void (IFSelect_WorkSession::*)(const Standard_CString)) &IFSelect_WorkSession::SetLoadedFile, "Stores the filename used for read for setting the model It is cleared by SetModel and ClearData(1)", py::arg("theFileName"));
cls_IFSelect_WorkSession.def("LoadedFile", (Standard_CString (IFSelect_WorkSession::*)() const) &IFSelect_WorkSession::LoadedFile, "Returns the filename used to load current model empty if unknown");
cls_IFSelect_WorkSession.def("ReadFile", (IFSelect_ReturnStatus (IFSelect_WorkSession::*)(const Standard_CString)) &IFSelect_WorkSession::ReadFile, "Reads a file with the WorkLibrary (sets Model and LoadedFile) Returns a integer status which can be : RetDone if OK, RetVoid if no Protocol not defined, RetError for file not found, RetFail if fail during read", py::arg("filename"));
cls_IFSelect_WorkSession.def("NbStartingEntities", (Standard_Integer (IFSelect_WorkSession::*)() const) &IFSelect_WorkSession::NbStartingEntities, "Returns the count of Entities stored in the Model, or 0");
cls_IFSelect_WorkSession.def("StartingEntity", (opencascade::handle<Standard_Transient> (IFSelect_WorkSession::*)(const Standard_Integer) const) &IFSelect_WorkSession::StartingEntity, "Returns an Entity stored in the Model of the WorkSession (Null Handle is no Model or num out of range)", py::arg("num"));
cls_IFSelect_WorkSession.def("StartingNumber", (Standard_Integer (IFSelect_WorkSession::*)(const opencascade::handle<Standard_Transient> &) const) &IFSelect_WorkSession::StartingNumber, "Returns the Number of an Entity in the Model (0 if no Model set or <ent> not in the Model)", py::arg("ent"));
cls_IFSelect_WorkSession.def("NumberFromLabel", [](IFSelect_WorkSession &self, const Standard_CString a0) -> Standard_Integer { return self.NumberFromLabel(a0); });
cls_IFSelect_WorkSession.def("NumberFromLabel", (Standard_Integer (IFSelect_WorkSession::*)(const Standard_CString, const Standard_Integer) const) &IFSelect_WorkSession::NumberFromLabel, "From a given label in Model, returns the corresponding number Starts from first entity by Default, may start after a given number : this number may be given negative, its absolute value is then considered. Hence a loop on NumberFromLabel may be programmed (stop test is : returned value positive or null)", py::arg("val"), py::arg("afternum"));
cls_IFSelect_WorkSession.def("EntityLabel", (opencascade::handle<TCollection_HAsciiString> (IFSelect_WorkSession::*)(const opencascade::handle<Standard_Transient> &) const) &IFSelect_WorkSession::EntityLabel, "Returns the label for <ent>, as the Model does If <ent> is not in the Model or if no Model is loaded, a Null Handle is returned", py::arg("ent"));
cls_IFSelect_WorkSession.def("EntityName", (opencascade::handle<TCollection_HAsciiString> (IFSelect_WorkSession::*)(const opencascade::handle<Standard_Transient> &) const) &IFSelect_WorkSession::EntityName, "Returns the Name of an Entity This Name is computed by the general service Name Returns a Null Handle if fails", py::arg("ent"));
cls_IFSelect_WorkSession.def("CategoryNumber", (Standard_Integer (IFSelect_WorkSession::*)(const opencascade::handle<Standard_Transient> &) const) &IFSelect_WorkSession::CategoryNumber, "Returns the Category Number determined for an entity it is computed by the class Category An unknown entity (number 0) gives a value -1", py::arg("ent"));
cls_IFSelect_WorkSession.def("CategoryName", (Standard_CString (IFSelect_WorkSession::*)(const opencascade::handle<Standard_Transient> &) const) &IFSelect_WorkSession::CategoryName, "Returns the Category Name determined for an entity it is computed by the class Category Remark : an unknown entity gives an empty string", py::arg("ent"));
cls_IFSelect_WorkSession.def("ValidityName", (Standard_CString (IFSelect_WorkSession::*)(const opencascade::handle<Standard_Transient> &) const) &IFSelect_WorkSession::ValidityName, "Returns the Validity Name determined for an entity it is computed by the class SignValidity Remark : an unknown entity gives an empty string", py::arg("ent"));
cls_IFSelect_WorkSession.def("ClearData", (void (IFSelect_WorkSession::*)(const Standard_Integer)) &IFSelect_WorkSession::ClearData, "Clears recorded data (not the items) according mode : 1 : all Data : Model, Graph, CheckList, + ClearData 4 2 : Graph and CheckList (they will then be recomputed later) 3 : CheckList (it will be recomputed by ComputeCheck) 4 : just content of SelectPointed and Counters Plus 0 : does nothing but called by SetModel ClearData is virtual, hence it can be redefined to clear other data of a specialised Work Session", py::arg("mode"));
cls_IFSelect_WorkSession.def("ComputeGraph", [](IFSelect_WorkSession &self) -> Standard_Boolean { return self.ComputeGraph(); });
cls_IFSelect_WorkSession.def("ComputeGraph", (Standard_Boolean (IFSelect_WorkSession::*)(const Standard_Boolean)) &IFSelect_WorkSession::ComputeGraph, "Computes the Graph used for Selections, Displays ... If a HGraph is already set, with same model as given by method Model, does nothing. Else, computes a new Graph. If <enforce> is given True, computes a new Graph anyway. Remark that a call to ClearGraph will cause ComputeGraph to really compute a new Graph Returns True if Graph is OK, False else (i.e. if no Protocol is set, or if Model is absent or empty).", py::arg("enforce"));
cls_IFSelect_WorkSession.def("HGraph", (opencascade::handle<Interface_HGraph> (IFSelect_WorkSession::*)()) &IFSelect_WorkSession::HGraph, "Returns the Computed Graph as HGraph (Null Handle if not set)");
cls_IFSelect_WorkSession.def("Graph", (const Interface_Graph & (IFSelect_WorkSession::*)()) &IFSelect_WorkSession::Graph, "Returns the Computed Graph, for Read only");
cls_IFSelect_WorkSession.def("Shareds", (opencascade::handle<TColStd_HSequenceOfTransient> (IFSelect_WorkSession::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_WorkSession::Shareds, "Returns the list of entities shared by <ent> (can be empty) Returns a null Handle if <ent> is unknown", py::arg("ent"));
cls_IFSelect_WorkSession.def("Sharings", (opencascade::handle<TColStd_HSequenceOfTransient> (IFSelect_WorkSession::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_WorkSession::Sharings, "Returns the list of entities sharing <ent> (can be empty) Returns a null Handle if <ent> is unknown", py::arg("ent"));
cls_IFSelect_WorkSession.def("IsLoaded", (Standard_Boolean (IFSelect_WorkSession::*)() const) &IFSelect_WorkSession::IsLoaded, "Returns True if a Model is defined and really loaded (not empty), a Protocol is set and a Graph has been computed. In this case, the WorkSession can start to work");
cls_IFSelect_WorkSession.def("ComputeCheck", [](IFSelect_WorkSession &self) -> Standard_Boolean { return self.ComputeCheck(); });
cls_IFSelect_WorkSession.def("ComputeCheck", (Standard_Boolean (IFSelect_WorkSession::*)(const Standard_Boolean)) &IFSelect_WorkSession::ComputeCheck, "Computes the CheckList for the Model currently loaded It can then be used for displays, querries ... Returns True if OK, False else (i.e. no Protocol set, or Model absent). If <enforce> is False, works only if not already done or if a new Model has been loaded from last call. Remark : computation is enforced by every call to SetModel or RunTransformer", py::arg("enforce"));
cls_IFSelect_WorkSession.def("ModelCheckList", [](IFSelect_WorkSession &self) -> Interface_CheckIterator { return self.ModelCheckList(); });
cls_IFSelect_WorkSession.def("ModelCheckList", (Interface_CheckIterator (IFSelect_WorkSession::*)(const Standard_Boolean)) &IFSelect_WorkSession::ModelCheckList, "Returns the Check List for the Model currently loaded : <complete> = True : complete (syntactic & semantic messages), computed if not yet done <complete> = False : only syntactic (check file form)", py::arg("complete"));
cls_IFSelect_WorkSession.def("CheckOne", [](IFSelect_WorkSession &self, const opencascade::handle<Standard_Transient> & a0) -> Interface_CheckIterator { return self.CheckOne(a0); });
cls_IFSelect_WorkSession.def("CheckOne", (Interface_CheckIterator (IFSelect_WorkSession::*)(const opencascade::handle<Standard_Transient> &, const Standard_Boolean)) &IFSelect_WorkSession::CheckOne, "Returns a Check for a single entity, under the form of a CheckIterator (this gives only one form for the user) if <ent> is Null or equates the current Model, it gives the Global Check, else the Check for the given entity <complete> as for ModelCheckList", py::arg("ent"), py::arg("complete"));
cls_IFSelect_WorkSession.def("LastRunCheckList", (Interface_CheckIterator (IFSelect_WorkSession::*)() const) &IFSelect_WorkSession::LastRunCheckList, "Returns the Check List produced by the last execution of either : EvaluateFile(for Split), SendSplit, SendAll, SendSelected, RunTransformer-RunModifier Cleared by SetModel or ClearData(1) The field is protected, hence a specialized WorkSession may fill it");
cls_IFSelect_WorkSession.def("MaxIdent", (Standard_Integer (IFSelect_WorkSession::*)() const) &IFSelect_WorkSession::MaxIdent, "Returns the Maximum Value for an Item Identifier. It can be greater to the count of known Items, because some can have been removed");
cls_IFSelect_WorkSession.def("Item", (opencascade::handle<Standard_Transient> (IFSelect_WorkSession::*)(const Standard_Integer) const) &IFSelect_WorkSession::Item, "Returns an Item, given its Ident. Returns a Null Handle if no Item corresponds to this Ident.", py::arg("id"));
cls_IFSelect_WorkSession.def("ItemIdent", (Standard_Integer (IFSelect_WorkSession::*)(const opencascade::handle<Standard_Transient> &) const) &IFSelect_WorkSession::ItemIdent, "Returns the Ident attached to an Item in the WorkSession, or Zero if it is unknown", py::arg("item"));
cls_IFSelect_WorkSession.def("NamedItem", (opencascade::handle<Standard_Transient> (IFSelect_WorkSession::*)(const Standard_CString) const) &IFSelect_WorkSession::NamedItem, "Returns the Item which corresponds to a Variable, given its Name (whatever the type of this Item). Returns a Null Handle if this Name is not recorded", py::arg("name"));
cls_IFSelect_WorkSession.def("NamedItem", (opencascade::handle<Standard_Transient> (IFSelect_WorkSession::*)(const opencascade::handle<TCollection_HAsciiString> &) const) &IFSelect_WorkSession::NamedItem, "Same as above, but <name> is given through a Handle Especially Usefull with methods SelectionNames, etc...", py::arg("name"));
cls_IFSelect_WorkSession.def("NameIdent", (Standard_Integer (IFSelect_WorkSession::*)(const Standard_CString) const) &IFSelect_WorkSession::NameIdent, "Returns the Ident attached to a Name, 0 if name not recorded", py::arg("name"));
cls_IFSelect_WorkSession.def("HasName", (Standard_Boolean (IFSelect_WorkSession::*)(const opencascade::handle<Standard_Transient> &) const) &IFSelect_WorkSession::HasName, "Returns True if an Item of the WorkSession has an attached Name", py::arg("item"));
cls_IFSelect_WorkSession.def("Name", (opencascade::handle<TCollection_HAsciiString> (IFSelect_WorkSession::*)(const opencascade::handle<Standard_Transient> &) const) &IFSelect_WorkSession::Name, "Returns the Name attached to an Item as a Variable of this WorkSession. If <item> is Null or not recorded, returns an empty string.", py::arg("item"));
cls_IFSelect_WorkSession.def("AddItem", [](IFSelect_WorkSession &self, const opencascade::handle<Standard_Transient> & a0) -> Standard_Integer { return self.AddItem(a0); });
cls_IFSelect_WorkSession.def("AddItem", (Standard_Integer (IFSelect_WorkSession::*)(const opencascade::handle<Standard_Transient> &, const Standard_Boolean)) &IFSelect_WorkSession::AddItem, "Adds an Item and returns its attached Ident. Does nothing if <item> is already recorded (and returns its attached Ident) <active> if True commands call to SetActive (see below) Remark : the determined Ident is used if <item> is a Dispatch, to fill the ShareOut", py::arg("item"), py::arg("active"));
cls_IFSelect_WorkSession.def("AddNamedItem", [](IFSelect_WorkSession &self, const Standard_CString a0, const opencascade::handle<Standard_Transient> & a1) -> Standard_Integer { return self.AddNamedItem(a0, a1); });
cls_IFSelect_WorkSession.def("AddNamedItem", (Standard_Integer (IFSelect_WorkSession::*)(const Standard_CString, const opencascade::handle<Standard_Transient> &, const Standard_Boolean)) &IFSelect_WorkSession::AddNamedItem, "Adds an Item with an attached Name. If the Name is already known in the WorkSession, the older item losts it Returns Ident if Done, 0 else, i.e. if <item> is null If <name> is empty, works as AddItem (i.e. with no name) If <item> is already known but with no attached Name, this method tries to attached a Name to it <active> if True commands call to SetActive (see below)", py::arg("name"), py::arg("item"), py::arg("active"));
cls_IFSelect_WorkSession.def("SetActive", (Standard_Boolean (IFSelect_WorkSession::*)(const opencascade::handle<Standard_Transient> &, const Standard_Boolean)) &IFSelect_WorkSession::SetActive, "Following the type of <item> : - Dispatch : Adds or Removes it in the ShareOut & FileNaming - GeneralModifier : Adds or Removes it for final sending (i.e. in the ModelCopier) Returns True if it did something, False else (state unchanged)", py::arg("item"), py::arg("mode"));
cls_IFSelect_WorkSession.def("RemoveNamedItem", (Standard_Boolean (IFSelect_WorkSession::*)(const Standard_CString)) &IFSelect_WorkSession::RemoveNamedItem, "Removes an Item from the Session, given its Name Returns True if Done, False else (Name not recorded) (Applies only on Item which are Named)", py::arg("name"));
cls_IFSelect_WorkSession.def("RemoveName", (Standard_Boolean (IFSelect_WorkSession::*)(const Standard_CString)) &IFSelect_WorkSession::RemoveName, "Removes a Name without removing the Item Returns True if Done, False else (Name not recorded)", py::arg("name"));
cls_IFSelect_WorkSession.def("RemoveItem", (Standard_Boolean (IFSelect_WorkSession::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_WorkSession::RemoveItem, "Removes an Item given its Ident. Returns False if <id> is attached to no Item in the WorkSession. For a Named Item, also removes its Name.", py::arg("item"));
cls_IFSelect_WorkSession.def("ClearItems", (void (IFSelect_WorkSession::*)()) &IFSelect_WorkSession::ClearItems, "Clears all the recorded Items : Selections, Dispatches, Modifiers, and Strings & IntParams, with their Idents & Names. Remark that if a Model has been loaded, it is not cleared.");
cls_IFSelect_WorkSession.def("ItemLabel", (opencascade::handle<TCollection_HAsciiString> (IFSelect_WorkSession::*)(const Standard_Integer) const) &IFSelect_WorkSession::ItemLabel, "Returns a Label which illustrates the content of an Item, given its Ident. This Label is : - for a Text Parameter, 'Text:<text value>' - for an Integer Parameter, 'Integer:<integer value>' - for a Selection, a Dispatch or a Modifier, its Label (see these classes) - for any other kind of Variable, its cdl type", py::arg("id"));
cls_IFSelect_WorkSession.def("ItemIdents", (opencascade::handle<TColStd_HSequenceOfInteger> (IFSelect_WorkSession::*)(const opencascade::handle<Standard_Type> &) const) &IFSelect_WorkSession::ItemIdents, "Fills a Sequence with the List of Idents attached to the Items of which Type complies with (IsKind) <type> (alphabetic order) Remark : <type> = TYPE(Standard_Transient) gives all the Idents which are suitable in the WorkSession", py::arg("type"));
cls_IFSelect_WorkSession.def("ItemNames", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (IFSelect_WorkSession::*)(const opencascade::handle<Standard_Type> &) const) &IFSelect_WorkSession::ItemNames, "Fills a Sequence with the list of the Names attached to Items of which Type complies with (IsKind) <type> (alphabetic order) Remark : <type> = TYPE(Standard_Transient) gives all the Names", py::arg("type"));
cls_IFSelect_WorkSession.def("ItemNamesForLabel", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (IFSelect_WorkSession::*)(const Standard_CString) const) &IFSelect_WorkSession::ItemNamesForLabel, "Fills a Sequence with the NAMES of the control items, of which the label matches <label> (contain it) : see NextIdentForLabel Search mode is fixed to 'contained' If <label> is empty, returns all Names", py::arg("label"));
cls_IFSelect_WorkSession.def("NextIdentForLabel", [](IFSelect_WorkSession &self, const Standard_CString a0, const Standard_Integer a1) -> Standard_Integer { return self.NextIdentForLabel(a0, a1); });
cls_IFSelect_WorkSession.def("NextIdentForLabel", (Standard_Integer (IFSelect_WorkSession::*)(const Standard_CString, const Standard_Integer, const Standard_Integer) const) &IFSelect_WorkSession::NextIdentForLabel, "For query by Label with possible iterations Searches the Ident of which Item has a Label which matches a given one, the search starts from an initial Ident. Returns the first found Ident which follows <id>, or ZERO", py::arg("label"), py::arg("id"), py::arg("mode"));
cls_IFSelect_WorkSession.def("NewParamFromStatic", [](IFSelect_WorkSession &self, const Standard_CString a0) -> opencascade::handle<Standard_Transient> { return self.NewParamFromStatic(a0); });
cls_IFSelect_WorkSession.def("NewParamFromStatic", (opencascade::handle<Standard_Transient> (IFSelect_WorkSession::*)(const Standard_CString, const Standard_CString)) &IFSelect_WorkSession::NewParamFromStatic, "Creates a parameter as being bound to a Static If the Static is Integer, this creates an IntParam bound to it by its name. Else this creates a String which is the value of the Static. Returns a null handle if <statname> is unknown as a Static", py::arg("statname"), py::arg("name"));
cls_IFSelect_WorkSession.def("IntParam", (opencascade::handle<IFSelect_IntParam> (IFSelect_WorkSession::*)(const Standard_Integer) const) &IFSelect_WorkSession::IntParam, "Returns an IntParam, given its Ident in the Session Null result if <id> is not suitable for an IntParam (undefined, or defined for another kind of variable)", py::arg("id"));
cls_IFSelect_WorkSession.def("IntValue", (Standard_Integer (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_IntParam> &) const) &IFSelect_WorkSession::IntValue, "Returns Integer Value of an IntParam", py::arg("it"));
cls_IFSelect_WorkSession.def("NewIntParam", [](IFSelect_WorkSession &self) -> opencascade::handle<IFSelect_IntParam> { return self.NewIntParam(); });
cls_IFSelect_WorkSession.def("NewIntParam", (opencascade::handle<IFSelect_IntParam> (IFSelect_WorkSession::*)(const Standard_CString)) &IFSelect_WorkSession::NewIntParam, "Creates a new IntParam. A Name can be set (Optional) Returns the created IntParam, or a Null Handle in case of Failure (see AddItem/AddNamedItem)", py::arg("name"));
cls_IFSelect_WorkSession.def("SetIntValue", (Standard_Boolean (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_IntParam> &, const Standard_Integer)) &IFSelect_WorkSession::SetIntValue, "Changes the Integer Value of an IntParam Returns True if Done, False if <it> is not in the WorkSession", py::arg("it"), py::arg("val"));
cls_IFSelect_WorkSession.def("TextParam", (opencascade::handle<TCollection_HAsciiString> (IFSelect_WorkSession::*)(const Standard_Integer) const) &IFSelect_WorkSession::TextParam, "Returns a TextParam, given its Ident in the Session Null result if <id> is not suitable for a TextParam (undefined, or defined for another kind of variable)", py::arg("id"));
cls_IFSelect_WorkSession.def("TextValue", (TCollection_AsciiString (IFSelect_WorkSession::*)(const opencascade::handle<TCollection_HAsciiString> &) const) &IFSelect_WorkSession::TextValue, "Returns Text Value of a TextParam (a String) or an empty string if <it> is not in the WorkSession", py::arg("par"));
cls_IFSelect_WorkSession.def("NewTextParam", [](IFSelect_WorkSession &self) -> opencascade::handle<TCollection_HAsciiString> { return self.NewTextParam(); });
cls_IFSelect_WorkSession.def("NewTextParam", (opencascade::handle<TCollection_HAsciiString> (IFSelect_WorkSession::*)(const Standard_CString)) &IFSelect_WorkSession::NewTextParam, "Creates a new (empty) TextParam. A Name can be set (Optional) Returns the created TextParam (as an HAsciiString), or a Null Handle in case of Failure (see AddItem/AddNamedItem)", py::arg("name"));
cls_IFSelect_WorkSession.def("SetTextValue", (Standard_Boolean (IFSelect_WorkSession::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_CString)) &IFSelect_WorkSession::SetTextValue, "Changes the Text Value of a TextParam (an HAsciiString) Returns True if Done, False if <it> is not in the WorkSession", py::arg("par"), py::arg("val"));
cls_IFSelect_WorkSession.def("Signature", (opencascade::handle<IFSelect_Signature> (IFSelect_WorkSession::*)(const Standard_Integer) const) &IFSelect_WorkSession::Signature, "Returns a Signature, given its Ident in the Session Null result if <id> is not suitable for a Signature (undefined, or defined for another kind of variable)", py::arg("id"));
cls_IFSelect_WorkSession.def("SignValue", (Standard_CString (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_Signature> &, const opencascade::handle<Standard_Transient> &) const) &IFSelect_WorkSession::SignValue, "Returns the Value computed by a Signature for an Entity Returns an empty string if the entity does not belong to the loaded model", py::arg("sign"), py::arg("ent"));
cls_IFSelect_WorkSession.def("Selection", (opencascade::handle<IFSelect_Selection> (IFSelect_WorkSession::*)(const Standard_Integer) const) &IFSelect_WorkSession::Selection, "Returns a Selection, given its Ident in the Session Null result if <id> is not suitable for a Selection (undefined, or defined for another kind of variable)", py::arg("id"));
cls_IFSelect_WorkSession.def("EvalSelection", (Interface_EntityIterator (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_Selection> &) const) &IFSelect_WorkSession::EvalSelection, "Evaluates the effect of a Selection applied on the input Model Returned Result remains empty if no input Model has been set", py::arg("sel"));
cls_IFSelect_WorkSession.def("Sources", (IFSelect_SelectionIterator (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_Selection> &) const) &IFSelect_WorkSession::Sources, "Returns the Selections which are source of Selection, given its rank in the List of Selections (see SelectionIterator) Returned value is empty if <num> is out of range or if <sel> is not in the WorkSession", py::arg("sel"));
cls_IFSelect_WorkSession.def("SelectionResult", (opencascade::handle<TColStd_HSequenceOfTransient> (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_Selection> &) const) &IFSelect_WorkSession::SelectionResult, "Returns the result of a Selection, computed by EvalSelection (see above) under the form of a HSequence (hence, it can be used by a frontal-engine logic). It can be empty Returns a Null Handle if <sel> is not in the WorkSession", py::arg("sel"));
cls_IFSelect_WorkSession.def("SelectionResultFromList", (opencascade::handle<TColStd_HSequenceOfTransient> (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_Selection> &, const opencascade::handle<TColStd_HSequenceOfTransient> &) const) &IFSelect_WorkSession::SelectionResultFromList, "Returns the result of a Selection, by forcing its input with a given list <list> (unless <list> is Null). RULES : <list> applies only for a SelectDeduct kind Selection : its Input is considered : if it is a SelectDeduct kind Selection, its Input is considered, etc... until an Input is not a Deduct/Extract : its result is replaced by <list> and all the chain of deductions is applied", py::arg("sel"), py::arg("list"));
cls_IFSelect_WorkSession.def("SetItemSelection", (Standard_Boolean (IFSelect_WorkSession::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<IFSelect_Selection> &)) &IFSelect_WorkSession::SetItemSelection, "Sets a Selection as input for an item, according its type : if <item> is a Dispatch : as Final Selection if <item> is a GeneralModifier (i.e. any kind of Modifier) : as Selection used to filter entities to modify <sel> Null causes this Selection to be nullified Returns False if <item> is not of a suitable type, or <item> or <sel> is not in the WorkSession", py::arg("item"), py::arg("sel"));
cls_IFSelect_WorkSession.def("ResetItemSelection", (Standard_Boolean (IFSelect_WorkSession::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_WorkSession::ResetItemSelection, "Resets input Selection which was set by SetItemSelection Same conditions as for SetItemSelection Returns True if done, False if <item> is not in the WorkSession", py::arg("item"));
cls_IFSelect_WorkSession.def("ItemSelection", (opencascade::handle<IFSelect_Selection> (IFSelect_WorkSession::*)(const opencascade::handle<Standard_Transient> &) const) &IFSelect_WorkSession::ItemSelection, "Returns the Selection of a Dispatch or a GeneralModifier. Returns a Null Handle if none is defined or <item> not good type", py::arg("item"));
cls_IFSelect_WorkSession.def("SignCounter", (opencascade::handle<IFSelect_SignCounter> (IFSelect_WorkSession::*)(const Standard_Integer) const) &IFSelect_WorkSession::SignCounter, "Returns a SignCounter from its ident in the Session Null result if <id> is not suitable for a SignCounter (undefined, or defined for another kind of variable)", py::arg("id"));
cls_IFSelect_WorkSession.def("ComputeCounter", [](IFSelect_WorkSession &self, const opencascade::handle<IFSelect_SignCounter> & a0) -> Standard_Boolean { return self.ComputeCounter(a0); });
cls_IFSelect_WorkSession.def("ComputeCounter", (Standard_Boolean (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_SignCounter> &, const Standard_Boolean)) &IFSelect_WorkSession::ComputeCounter, "Computes the content of a SignCounter when it is defined with a Selection, then returns True Returns False if the SignCounter is not defined with a Selection, or if its Selection Mode is inhibited <forced> to work around optimisations", py::arg("counter"), py::arg("forced"));
cls_IFSelect_WorkSession.def("ComputeCounterFromList", [](IFSelect_WorkSession &self, const opencascade::handle<IFSelect_SignCounter> & a0, const opencascade::handle<TColStd_HSequenceOfTransient> & a1) -> Standard_Boolean { return self.ComputeCounterFromList(a0, a1); });
cls_IFSelect_WorkSession.def("ComputeCounterFromList", (Standard_Boolean (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_SignCounter> &, const opencascade::handle<TColStd_HSequenceOfTransient> &, const Standard_Boolean)) &IFSelect_WorkSession::ComputeCounterFromList, "Computes the content of a SignCounter from an input list If <list> is Null, uses internal definition of the Counter : a Selection, else the whole Model (recomputation forced) If <clear> is True (D), starts from scratch Else, cumulates computations", py::arg("counter"), py::arg("list"), py::arg("clear"));
cls_IFSelect_WorkSession.def("AppliedDispatches", (opencascade::handle<TColStd_HSequenceOfInteger> (IFSelect_WorkSession::*)() const) &IFSelect_WorkSession::AppliedDispatches, "Returns the ordered list of dispatches stored by the ShareOut");
cls_IFSelect_WorkSession.def("ClearShareOut", (void (IFSelect_WorkSession::*)(const Standard_Boolean)) &IFSelect_WorkSession::ClearShareOut, "Clears the list of Dispatches recorded by the ShareOut if <only> disp is True, tha's all. Else, clears also the lists of Modifiers recorded by the ShareOut", py::arg("onlydisp"));
cls_IFSelect_WorkSession.def("Dispatch", (opencascade::handle<IFSelect_Dispatch> (IFSelect_WorkSession::*)(const Standard_Integer) const) &IFSelect_WorkSession::Dispatch, "Returns a Dispatch, given its Ident in the Session Null result if <id> is not suitable for a Dispatch (undefined, or defined for another kind of variable)", py::arg("id"));
cls_IFSelect_WorkSession.def("DispatchRank", (Standard_Integer (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_Dispatch> &) const) &IFSelect_WorkSession::DispatchRank, "Returns the rank of a Dispatch in the ShareOut, or 0 if <disp> is not in the ShareOut or not in the WorkSession", py::arg("disp"));
cls_IFSelect_WorkSession.def("ModelCopier", (const opencascade::handle<IFSelect_ModelCopier> & (IFSelect_WorkSession::*)() const) &IFSelect_WorkSession::ModelCopier, "Gives access to the complete ModelCopier");
cls_IFSelect_WorkSession.def("SetModelCopier", (void (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_ModelCopier> &)) &IFSelect_WorkSession::SetModelCopier, "Sets a new ModelCopier. Fills Items which its content", py::arg("copier"));
cls_IFSelect_WorkSession.def("NbFinalModifiers", (Standard_Integer (IFSelect_WorkSession::*)(const Standard_Boolean) const) &IFSelect_WorkSession::NbFinalModifiers, "Returns the count of Modifiers applied to final sending Model Modifiers if <formodel> is True, File Modifiers else (i.e. Modifiers which apply once the Models have been filled)", py::arg("formodel"));
cls_IFSelect_WorkSession.def("FinalModifierIdents", (opencascade::handle<TColStd_HSequenceOfInteger> (IFSelect_WorkSession::*)(const Standard_Boolean) const) &IFSelect_WorkSession::FinalModifierIdents, "Fills a Sequence with a list of Idents, those attached to the Modifiers applied to final sending. Model Modifiers if <formodel> is True, File Modifiers else This list is given in the order in which they will be applied (which takes into account the Changes to Modifier Ranks)", py::arg("formodel"));
cls_IFSelect_WorkSession.def("GeneralModifier", (opencascade::handle<IFSelect_GeneralModifier> (IFSelect_WorkSession::*)(const Standard_Integer) const) &IFSelect_WorkSession::GeneralModifier, "Returns a Modifier, given its Ident in the Session Null result if <id> is not suitable for a Modifier (undefined, or defined for another kind of variable)", py::arg("id"));
cls_IFSelect_WorkSession.def("ModelModifier", (opencascade::handle<IFSelect_Modifier> (IFSelect_WorkSession::*)(const Standard_Integer) const) &IFSelect_WorkSession::ModelModifier, "Returns a Model Modifier, given its Ident in the Session, i.e. typed as a Modifier (not simply a GeneralModifier) Null result if <id> is not suitable for a Modifier (undefined, or defined for another kind of variable)", py::arg("id"));
cls_IFSelect_WorkSession.def("ModifierRank", (Standard_Integer (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_GeneralModifier> &) const) &IFSelect_WorkSession::ModifierRank, "Returns the Rank of a Modifier given its Ident. Model or File Modifier according its type (ModelModifier or not) Remember that Modifiers are applied sequencially following their Rank : first Model Modifiers then File Modifiers Rank is given by rank of call to AddItem and can be changed by ChangeModifierRank", py::arg("item"));
cls_IFSelect_WorkSession.def("ChangeModifierRank", (Standard_Boolean (IFSelect_WorkSession::*)(const Standard_Boolean, const Standard_Integer, const Standard_Integer)) &IFSelect_WorkSession::ChangeModifierRank, "Changes the Rank of a Modifier in the Session : Model Modifiers if <formodel> is True, File Modifiers else the Modifier n0 <before> is put to n0 <after> Return True if Done, False if <before> or <after> out of range", py::arg("formodel"), py::arg("before"), py::arg("after"));
cls_IFSelect_WorkSession.def("ClearFinalModifiers", (void (IFSelect_WorkSession::*)()) &IFSelect_WorkSession::ClearFinalModifiers, "Removes all the Modifiers active in the ModelCopier : they become inactive and they are removed from the Session");
cls_IFSelect_WorkSession.def("SetAppliedModifier", (Standard_Boolean (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_GeneralModifier> &, const opencascade::handle<Standard_Transient> &)) &IFSelect_WorkSession::SetAppliedModifier, "Sets a GeneralModifier to be applied to an item : - item = ShareOut : applies for final sending (all dispatches) - item is a Dispatch : applies for this dispatch only Returns True if done, False if <modif> or <item> not in <me>", py::arg("modif"), py::arg("item"));
cls_IFSelect_WorkSession.def("ResetAppliedModifier", (Standard_Boolean (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_GeneralModifier> &)) &IFSelect_WorkSession::ResetAppliedModifier, "Resets a GeneralModifier to be applied Returns True if done, False if <modif> was not applied", py::arg("modif"));
cls_IFSelect_WorkSession.def("UsesAppliedModifier", (opencascade::handle<Standard_Transient> (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_GeneralModifier> &) const) &IFSelect_WorkSession::UsesAppliedModifier, "Returns the item on which a GeneralModifier is applied : the ShareOut, or a given Dispatch Returns a Null Handle if <modif> is not applied", py::arg("modif"));
cls_IFSelect_WorkSession.def("Transformer", (opencascade::handle<IFSelect_Transformer> (IFSelect_WorkSession::*)(const Standard_Integer) const) &IFSelect_WorkSession::Transformer, "Returns a Transformer, given its Ident in the Session Null result if <id> is not suitable for a Transformer (undefined, or defined for another kind of variable)", py::arg("id"));
cls_IFSelect_WorkSession.def("RunTransformer", (Standard_Integer (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_Transformer> &)) &IFSelect_WorkSession::RunTransformer, "Runs a Transformer on starting Model, which can then be edited or replaced by a new one. The Protocol can also be changed. Fills LastRunCheckList", py::arg("transf"));
cls_IFSelect_WorkSession.def("RunModifier", (Standard_Integer (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_Modifier> &, const Standard_Boolean)) &IFSelect_WorkSession::RunModifier, "Runs a Modifier on Starting Model. It can modify entities, or add new ones. But the Model or the Protocol is unchanged. The Modifier is applied on each entity of the Model. See also RunModifierSelected Fills LastRunCheckList", py::arg("modif"), py::arg("copy"));
cls_IFSelect_WorkSession.def("RunModifierSelected", (Standard_Integer (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_Modifier> &, const opencascade::handle<IFSelect_Selection> &, const Standard_Boolean)) &IFSelect_WorkSession::RunModifierSelected, "Acts as RunModifier, but the Modifier is applied on the list determined by a Selection, rather than on the whole Model If the selection is a null handle, the whole model is taken", py::arg("modif"), py::arg("sel"), py::arg("copy"));
cls_IFSelect_WorkSession.def("NewTransformStandard", [](IFSelect_WorkSession &self, const Standard_Boolean a0) -> opencascade::handle<IFSelect_Transformer> { return self.NewTransformStandard(a0); });
cls_IFSelect_WorkSession.def("NewTransformStandard", (opencascade::handle<IFSelect_Transformer> (IFSelect_WorkSession::*)(const Standard_Boolean, const Standard_CString)) &IFSelect_WorkSession::NewTransformStandard, "Creates and returns a TransformStandard, empty, with its Copy Option (True = Copy, False = On the Spot) and an optional name. To a TransformStandard, the method SetAppliedModifier applies", py::arg("copy"), py::arg("name"));
cls_IFSelect_WorkSession.def("SetModelContent", (Standard_Boolean (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_Selection> &, const Standard_Boolean)) &IFSelect_WorkSession::SetModelContent, "Defines a new content from the former one If <keep> is True, it is given by entities selected by Selection <sel> (and all shared entities) Else, it is given by all the former content but entities selected by the Selection <sel> (and properly shared ones) Returns True if done. Returns False if the selected list (from <sel>) is empty, hence nothing is done", py::arg("sel"), py::arg("keep"));
cls_IFSelect_WorkSession.def("FilePrefix", (opencascade::handle<TCollection_HAsciiString> (IFSelect_WorkSession::*)() const) &IFSelect_WorkSession::FilePrefix, "Returns the defined File Prefix. Null Handle if not defined");
cls_IFSelect_WorkSession.def("DefaultFileRoot", (opencascade::handle<TCollection_HAsciiString> (IFSelect_WorkSession::*)() const) &IFSelect_WorkSession::DefaultFileRoot, "Returns the defined Default File Root. It is used for Dispatches which have no specific root attached. Null Handle if not defined");
cls_IFSelect_WorkSession.def("FileExtension", (opencascade::handle<TCollection_HAsciiString> (IFSelect_WorkSession::*)() const) &IFSelect_WorkSession::FileExtension, "Returns the defined File Extension. Null Handle if not defined");
cls_IFSelect_WorkSession.def("FileRoot", (opencascade::handle<TCollection_HAsciiString> (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_Dispatch> &) const) &IFSelect_WorkSession::FileRoot, "Returns the File Root defined for a Dispatch. Null if no Root Name is defined for it (hence, no File will be produced)", py::arg("disp"));
cls_IFSelect_WorkSession.def("SetFilePrefix", (void (IFSelect_WorkSession::*)(const Standard_CString)) &IFSelect_WorkSession::SetFilePrefix, "Defines a File Prefix", py::arg("name"));
cls_IFSelect_WorkSession.def("SetDefaultFileRoot", (Standard_Boolean (IFSelect_WorkSession::*)(const Standard_CString)) &IFSelect_WorkSession::SetDefaultFileRoot, "Defines a Default File Root Name. Clears it is <name> = '' Returns True if OK, False if <name> already set for a Dispatch", py::arg("name"));
cls_IFSelect_WorkSession.def("SetFileExtension", (void (IFSelect_WorkSession::*)(const Standard_CString)) &IFSelect_WorkSession::SetFileExtension, "Defines a File Extension", py::arg("name"));
cls_IFSelect_WorkSession.def("SetFileRoot", (Standard_Boolean (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_Dispatch> &, const Standard_CString)) &IFSelect_WorkSession::SetFileRoot, "Defines a Root for a Dispatch If <name> is empty, clears Root Name This has as effect to inhibit the production of File by <disp> Returns False if <disp> is not in the WorkSession or if a root name is already defined for it", py::arg("disp"), py::arg("name"));
cls_IFSelect_WorkSession.def("GiveFileRoot", (Standard_CString (IFSelect_WorkSession::*)(const Standard_CString) const) &IFSelect_WorkSession::GiveFileRoot, "Extracts File Root Name from a given complete file name (uses OSD_Path)", py::arg("file"));
cls_IFSelect_WorkSession.def("GiveFileComplete", (Standard_CString (IFSelect_WorkSession::*)(const Standard_CString) const) &IFSelect_WorkSession::GiveFileComplete, "Completes a file name as required, with Prefix and Extension (if defined; for a non-defined item, completes nothing)", py::arg("file"));
cls_IFSelect_WorkSession.def("ClearFile", (void (IFSelect_WorkSession::*)()) &IFSelect_WorkSession::ClearFile, "Erases all stored data from the File Evaluation (i.e. ALL former naming informations are lost)");
cls_IFSelect_WorkSession.def("EvaluateFile", (void (IFSelect_WorkSession::*)()) &IFSelect_WorkSession::EvaluateFile, "Performs and stores a File Evaluation. The Results are a List of produced Models and a List of names (Strings), in parallel Fills LastRunCheckList");
cls_IFSelect_WorkSession.def("NbFiles", (Standard_Integer (IFSelect_WorkSession::*)() const) &IFSelect_WorkSession::NbFiles, "Returns the count of produced Models");
cls_IFSelect_WorkSession.def("FileModel", (opencascade::handle<Interface_InterfaceModel> (IFSelect_WorkSession::*)(const Standard_Integer) const) &IFSelect_WorkSession::FileModel, "Returns a Model, given its rank in the Evaluation List", py::arg("num"));
cls_IFSelect_WorkSession.def("FileName", (TCollection_AsciiString (IFSelect_WorkSession::*)(const Standard_Integer) const) &IFSelect_WorkSession::FileName, "Returns the name of a file corresponding to a produced Model, given its rank in the Evaluation List", py::arg("num"));
cls_IFSelect_WorkSession.def("BeginSentFiles", (void (IFSelect_WorkSession::*)(const Standard_Boolean)) &IFSelect_WorkSession::BeginSentFiles, "Commands file sending to clear the list of already sent files, commands to record a new one if <record> is True This list is managed by the ModelCopier when SendSplit is called It allows a global exploitation of the set of sent files", py::arg("record"));
cls_IFSelect_WorkSession.def("SentFiles", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (IFSelect_WorkSession::*)() const) &IFSelect_WorkSession::SentFiles, "Returns the list of recorded sent files, or a Null Handle is recording has not been enabled");
cls_IFSelect_WorkSession.def("SendSplit", (Standard_Boolean (IFSelect_WorkSession::*)()) &IFSelect_WorkSession::SendSplit, "Performs creation of derived files from the input Model Takes its data (sub-models and names), from result EvaluateFile if active, else by dynamic Evaluation (not stored) After SendSplit, result of EvaluateFile is Cleared Fills LastRunCheckList");
cls_IFSelect_WorkSession.def("EvalSplit", (opencascade::handle<IFSelect_PacketList> (IFSelect_WorkSession::*)() const) &IFSelect_WorkSession::EvalSplit, "Returns an Evaluation of the whole ShareOut definition : i.e. how the entities of the starting model are forecast to be sent to various files : list of packets according the dispatches, effective lists of roots for each packet (which determine the content of the corresponding file); plus evaluation of which entities are : forgotten (sent into no file), duplicated (sent into more than one file), sent into a given file. See the class PacketList for more details.");
cls_IFSelect_WorkSession.def("SentList", [](IFSelect_WorkSession &self) -> Interface_EntityIterator { return self.SentList(); });
cls_IFSelect_WorkSession.def("SentList", (Interface_EntityIterator (IFSelect_WorkSession::*)(const Standard_Integer) const) &IFSelect_WorkSession::SentList, "Returns the list of Entities sent in files, accourding the count of files each one has been sent (these counts are reset by SetModel or SetRemaining(Forget) ) stored in Graph Status <count> = -1 (default) is for ENtities sent at least once <count> = 0 is for the Remaining List (entities not yet sent) <count> = 1 is for entities sent in one and only one file (the ideal case) Remaining Data are computed on each Sending/Copying output files (see methods EvaluateFile and SendSplit) Graph Status is 0 for Remaining Entity, <count> for Sent into <count> files This status is set to 0 (not yet sent) for all by SetModel and by SetRemaining(mode=Forget,Display)", py::arg("count"));
cls_IFSelect_WorkSession.def("MaxSendingCount", (Standard_Integer (IFSelect_WorkSession::*)() const) &IFSelect_WorkSession::MaxSendingCount, "Returns the greater count of different files in which any of the starting entities could be sent. Before any file output, this count is 0. Ideal count is 1. More than 1 means that duplications occur.");
cls_IFSelect_WorkSession.def("SetRemaining", (Standard_Boolean (IFSelect_WorkSession::*)(const IFSelect_RemainMode)) &IFSelect_WorkSession::SetRemaining, "Processes Remaining data (after having sent files), mode : Forget : forget remaining info (i.e. clear all 'Sent' status) Compute : compute and keep remaining (does nothing if : remaining is empty or if no files has been sent) Display : display entities recorded as remaining Undo : restore former state of data (after Remaining(1) ) Returns True if OK, False else (i.e. mode = 2 and Remaining List is either empty or takes all the entities, or mode = 3 and no former computation of remaining data was done)", py::arg("mode"));
cls_IFSelect_WorkSession.def("SendAll", [](IFSelect_WorkSession &self, const Standard_CString a0) -> IFSelect_ReturnStatus { return self.SendAll(a0); });
cls_IFSelect_WorkSession.def("SendAll", (IFSelect_ReturnStatus (IFSelect_WorkSession::*)(const Standard_CString, const Standard_Boolean)) &IFSelect_WorkSession::SendAll, "Sends the starting Model into one file, without splitting, managing remaining data or anything else. <computegraph> true commands the Graph to be recomputed before sending : required when a Model is filled in several steps", py::arg("filename"), py::arg("computegraph"));
cls_IFSelect_WorkSession.def("SendSelected", [](IFSelect_WorkSession &self, const Standard_CString a0, const opencascade::handle<IFSelect_Selection> & a1) -> IFSelect_ReturnStatus { return self.SendSelected(a0, a1); });
cls_IFSelect_WorkSession.def("SendSelected", (IFSelect_ReturnStatus (IFSelect_WorkSession::*)(const Standard_CString, const opencascade::handle<IFSelect_Selection> &, const Standard_Boolean)) &IFSelect_WorkSession::SendSelected, "Sends a part of the starting Model into one file, without splitting. But remaining data are managed. <computegraph> true commands the Graph to be recomputed before sending : required when a Model is filled in several steps", py::arg("filename"), py::arg("sel"), py::arg("computegraph"));
cls_IFSelect_WorkSession.def("WriteFile", (IFSelect_ReturnStatus (IFSelect_WorkSession::*)(const Standard_CString)) &IFSelect_WorkSession::WriteFile, "Writes the current Interface Model globally to a File, and returns a write status which can be : Done OK, Fail file could not be written, Error no norm is selected Remark : It is a simple, one-file writing, other operations are available (such as splitting ...) which calls SendAll", py::arg("filename"));
cls_IFSelect_WorkSession.def("WriteFile", (IFSelect_ReturnStatus (IFSelect_WorkSession::*)(const Standard_CString, const opencascade::handle<IFSelect_Selection> &)) &IFSelect_WorkSession::WriteFile, "Writes a sub-part of the current Interface Model to a File, as defined by a Selection <sel>, recomputes the Graph, and returns a write status which can be : Done OK, Fail file could not be written, Error no norm is selected Remark : It is a simple, one-file writing, other operations are available (such as splitting ...) which calls SendSelected", py::arg("filename"), py::arg("sel"));
cls_IFSelect_WorkSession.def("NbSources", (Standard_Integer (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_Selection> &) const) &IFSelect_WorkSession::NbSources, "Returns the count of Input Selections known for a Selection, or 0 if <sel> not in the WorkSession. This count is one for a SelectDeduct / SelectExtract kind, two for SelectControl kind, variable for a SelectCombine (Union/Intersection), zero else", py::arg("sel"));
cls_IFSelect_WorkSession.def("Source", [](IFSelect_WorkSession &self, const opencascade::handle<IFSelect_Selection> & a0) -> opencascade::handle<IFSelect_Selection> { return self.Source(a0); });
cls_IFSelect_WorkSession.def("Source", (opencascade::handle<IFSelect_Selection> (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_Selection> &, const Standard_Integer) const) &IFSelect_WorkSession::Source, "Returns the <num>th Input Selection of a Selection (see NbSources). Returns a Null Handle if <sel> is not in the WorkSession or if <num> is out of the range <1-NbSources> To obtain more details, see the method Sources", py::arg("sel"), py::arg("num"));
cls_IFSelect_WorkSession.def("IsReversedSelectExtract", (Standard_Boolean (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_Selection> &) const) &IFSelect_WorkSession::IsReversedSelectExtract, "Returns True if <sel> a Reversed SelectExtract, False else", py::arg("sel"));
cls_IFSelect_WorkSession.def("ToggleSelectExtract", (Standard_Boolean (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_Selection> &)) &IFSelect_WorkSession::ToggleSelectExtract, "Toggles the Sense (Direct <-> Reversed) of a SelectExtract Returns True if Done, False if <sel> is not a SelectExtract or is not in the WorkSession", py::arg("sel"));
cls_IFSelect_WorkSession.def("SetInputSelection", (Standard_Boolean (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_Selection> &, const opencascade::handle<IFSelect_Selection> &)) &IFSelect_WorkSession::SetInputSelection, "Sets an Input Selection (as <input>) to a SelectExtract or a SelectDeduct (as <sel>). Returns True if Done, False if <sel> is neither a SelectExtract nor a SelectDeduct, or not in the WorkSession", py::arg("sel"), py::arg("input"));
cls_IFSelect_WorkSession.def("SetControl", [](IFSelect_WorkSession &self, const opencascade::handle<IFSelect_Selection> & a0, const opencascade::handle<IFSelect_Selection> & a1) -> Standard_Boolean { return self.SetControl(a0, a1); });
cls_IFSelect_WorkSession.def("SetControl", (Standard_Boolean (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_Selection> &, const opencascade::handle<IFSelect_Selection> &, const Standard_Boolean)) &IFSelect_WorkSession::SetControl, "Sets an Input Selection, Main if <formain> is True, Second else (as <sc>) to a SelectControl (as <sel>). Returns True if Done, False if <sel> is not a SelectControl, or <sc> or <sel> is not in the WorkSession", py::arg("sel"), py::arg("sc"), py::arg("formain"));
cls_IFSelect_WorkSession.def("CombineAdd", [](IFSelect_WorkSession &self, const opencascade::handle<IFSelect_Selection> & a0, const opencascade::handle<IFSelect_Selection> & a1) -> Standard_Integer { return self.CombineAdd(a0, a1); });
cls_IFSelect_WorkSession.def("CombineAdd", (Standard_Integer (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_Selection> &, const opencascade::handle<IFSelect_Selection> &, const Standard_Integer)) &IFSelect_WorkSession::CombineAdd, "Adds an input selection to a SelectCombine (Union or Inters.). Returns new count of inputs for this SelectCombine if Done or 0 if <sel> is not kind of SelectCombine, or if <seladd> or <sel> is not in the WorkSession By default, adding is done at the end of the list Else, it is an insertion to rank <atnum> (usefull for Un-ReDo)", py::arg("selcomb"), py::arg("seladd"), py::arg("atnum"));
cls_IFSelect_WorkSession.def("CombineRemove", (Standard_Boolean (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_Selection> &, const opencascade::handle<IFSelect_Selection> &)) &IFSelect_WorkSession::CombineRemove, "Removes an input selection from a SelectCombine (Union or Intersection). Returns True if done, False if <selcomb> is not kind of SelectCombine or <selrem> is not source of <selcomb>", py::arg("selcomb"), py::arg("selrem"));
cls_IFSelect_WorkSession.def("NewSelectPointed", (opencascade::handle<IFSelect_Selection> (IFSelect_WorkSession::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &, const Standard_CString)) &IFSelect_WorkSession::NewSelectPointed, "Creates a new Selection, of type SelectPointed, its content starts with <list>. A name must be given (can be empty)", py::arg("list"), py::arg("name"));
cls_IFSelect_WorkSession.def("SetSelectPointed", (Standard_Boolean (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_Selection> &, const opencascade::handle<TColStd_HSequenceOfTransient> &, const Standard_Integer) const) &IFSelect_WorkSession::SetSelectPointed, "Changes the content of a Selection of type SelectPointed According <mode> : 0 set <list> as new content (clear former) 1 : adds <list> to actual content -1 : removes <list> from actual content Returns True if done, False if <sel> is not a SelectPointed", py::arg("sel"), py::arg("list"), py::arg("mode"));
cls_IFSelect_WorkSession.def("GiveSelection", (opencascade::handle<IFSelect_Selection> (IFSelect_WorkSession::*)(const Standard_CString) const) &IFSelect_WorkSession::GiveSelection, "Returns a Selection from a Name : - the name of a Selection : this Selection - the name of a Signature + criteria between (..) : a new Selection from this Signature - an entity or a list of entities : a new SelectPointed Else, returns a Null Handle", py::arg("selname"));
cls_IFSelect_WorkSession.def("GiveList", (opencascade::handle<TColStd_HSequenceOfTransient> (IFSelect_WorkSession::*)(const opencascade::handle<Standard_Transient> &) const) &IFSelect_WorkSession::GiveList, "Determines a list of entities from an object : <obj> already HSequenceOfTransient : returned itself <obj> Selection : its Result of Evaluation is returned <obj> an entity of the Model : a HSequence which contains it else, an empty HSequence <obj> the Model it self : ALL its content (not only the roots)", py::arg("obj"));
cls_IFSelect_WorkSession.def("GiveList", [](IFSelect_WorkSession &self, const Standard_CString a0) -> opencascade::handle<TColStd_HSequenceOfTransient> { return self.GiveList(a0); });
cls_IFSelect_WorkSession.def("GiveList", (opencascade::handle<TColStd_HSequenceOfTransient> (IFSelect_WorkSession::*)(const Standard_CString, const Standard_CString) const) &IFSelect_WorkSession::GiveList, "Computes a List of entities from two alphanums, first and second, as follows : if <first> is a Number or Label of an entity : this entity if <first> is a list of Numbers/Labels : the list of entities if <first> is the name of a Selection in <WS>, and <second> not defined, the standard result of this Selection else, let's consider 'first second' : this whole phrase is splitted by blanks, as follows (RECURSIVE CALL) : - the leftest term is the final selection - the other terms define the result of the selection - and so on (the 'leftest minus one' is a selection, of which the input is given by the remaining ...)", py::arg("first"), py::arg("second"));
cls_IFSelect_WorkSession.def("GiveListFromList", (opencascade::handle<TColStd_HSequenceOfTransient> (IFSelect_WorkSession::*)(const Standard_CString, const opencascade::handle<Standard_Transient> &) const) &IFSelect_WorkSession::GiveListFromList, "Computes a List of entities from the model as follows <first> beeing a Selection or a combination of Selections, <ent> beeing an entity or a list of entities (as a HSequenceOfTransient) : the standard result of this selection applied to this list if <ent> is Null, the standard definition of the selection is used (which contains a default input selection) if <selname> is erroneous, a null handle is returned", py::arg("selname"), py::arg("ent"));
cls_IFSelect_WorkSession.def("GiveListCombined", (opencascade::handle<TColStd_HSequenceOfTransient> (IFSelect_WorkSession::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &, const opencascade::handle<TColStd_HSequenceOfTransient> &, const Standard_Integer) const) &IFSelect_WorkSession::GiveListCombined, "Combines two lists and returns the result, according to mode : <mode> < 0 : entities in <l1> AND NOT in <l2> <mode> = 0 : entities in <l1> AND in <l2> <mode> > 0 : entities in <l1> OR in <l2>", py::arg("l1"), py::arg("l2"), py::arg("mode"));
cls_IFSelect_WorkSession.def("QueryCheckList", (void (IFSelect_WorkSession::*)(const Interface_CheckIterator &)) &IFSelect_WorkSession::QueryCheckList, "Loads data from a check iterator to query status on it", py::arg("chl"));
cls_IFSelect_WorkSession.def("QueryCheckStatus", (Standard_Integer (IFSelect_WorkSession::*)(const opencascade::handle<Standard_Transient> &) const) &IFSelect_WorkSession::QueryCheckStatus, "Determines check status for an entity regarding last call to QueryCheckList : -1 : <ent> unknown in the model, ignored 0 : no check at all, immediate or inherited thru Graph 1 : immediate warning (no fail), no inherited check 2 : immediate fail, no inherited check +10 : idem but some inherited warning (no fail) +20 : idem but some inherited fail", py::arg("ent"));
cls_IFSelect_WorkSession.def("QueryParent", (Standard_Integer (IFSelect_WorkSession::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &) const) &IFSelect_WorkSession::QueryParent, "Determines if <entdad> is parent of <entson> (in the graph), returns : -1 if no; 0 if <entdad> = <entson> 1 if immediate parent, > 1 if parent, gives count of steps", py::arg("entdad"), py::arg("entson"));
cls_IFSelect_WorkSession.def("SetParams", (void (IFSelect_WorkSession::*)(const NCollection_Vector<opencascade::handle<Standard_Transient> > &, const NCollection_Vector<Standard_Integer> &)) &IFSelect_WorkSession::SetParams, "Sets a list of Parameters, i.e. TypedValue, to be handled through an Editor The two lists are parallel, if <params> is longer than <uses>, surnumeral parameters are for general use", py::arg("params"), py::arg("uselist"));
cls_IFSelect_WorkSession.def("TraceStatics", [](IFSelect_WorkSession &self, const Standard_Integer a0) -> void { return self.TraceStatics(a0); });
cls_IFSelect_WorkSession.def("TraceStatics", (void (IFSelect_WorkSession::*)(const Standard_Integer, const Standard_Integer) const) &IFSelect_WorkSession::TraceStatics, "Traces the Statics attached to a given use number If <use> is given positive (normal), the trace is embedded with a header and a trailer If <use> is negative, just values are printed (this allows to make compositions) Remark : use number 5 commands use -2 to be traced Remark : use numbers 4 and 6 command use -3 to be traced", py::arg("use"), py::arg("mode"));
cls_IFSelect_WorkSession.def("DumpShare", (void (IFSelect_WorkSession::*)() const) &IFSelect_WorkSession::DumpShare, "Dumps contents of the ShareOut (on 'cout')");
cls_IFSelect_WorkSession.def("ListItems", [](IFSelect_WorkSession &self) -> void { return self.ListItems(); });
cls_IFSelect_WorkSession.def("ListItems", (void (IFSelect_WorkSession::*)(const Standard_CString) const) &IFSelect_WorkSession::ListItems, "Lists the Labels of all Items of the WorkSession If <label> is defined, lists labels which contain it", py::arg("label"));
cls_IFSelect_WorkSession.def("ListFinalModifiers", (void (IFSelect_WorkSession::*)(const Standard_Boolean) const) &IFSelect_WorkSession::ListFinalModifiers, "Lists the Modifiers of the session (for each one, displays its Label). Listing is done following Ranks (Modifiers are invoked following their ranks) Model Modifiers if <formodel> is True, File Modifiers else", py::arg("formodel"));
cls_IFSelect_WorkSession.def("DumpSelection", (void (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_Selection> &) const) &IFSelect_WorkSession::DumpSelection, "Lists a Selection and its Sources (see SelectionIterator), given its rank in the list", py::arg("sel"));
cls_IFSelect_WorkSession.def("DumpModel", (void (IFSelect_WorkSession::*)(const Standard_Integer, const opencascade::handle<Message_Messenger> &)) &IFSelect_WorkSession::DumpModel, "Lists the content of the Input Model (if there is one) According level : 0 -> gives only count of Entities and Roots 1 -> Lists also Roots; 2 -> Lists all Entities (by TraceType) 3 -> Performs a call to CheckList (Fails) and lists the result 4 -> as 3 but all CheckList (Fails + Warnings) 5,6,7 : as 3 but resp. Count,List,Labels by Fail 8,9,10 : as 4 but resp. Count,List,Labels by message", py::arg("level"), py::arg("S"));
cls_IFSelect_WorkSession.def("TraceDumpModel", (void (IFSelect_WorkSession::*)(const Standard_Integer)) &IFSelect_WorkSession::TraceDumpModel, "Dumps the current Model (as inherited DumpModel), on currently defined Default Trace File (default is standard output)", py::arg("mode"));
cls_IFSelect_WorkSession.def("DumpEntity", (void (IFSelect_WorkSession::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer, const opencascade::handle<Message_Messenger> &) const) &IFSelect_WorkSession::DumpEntity, "Dumps a starting entity according to the current norm. To do this, it calls DumpEntity from WorkLibrary. <level> is to be interpreted for each norm : see specific classes of WorkLibrary for it. Generally, 0 if for very basic (only type ...), greater values give more and more details.", py::arg("ent"), py::arg("level"), py::arg("S"));
cls_IFSelect_WorkSession.def("PrintEntityStatus", (void (IFSelect_WorkSession::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Message_Messenger> &)) &IFSelect_WorkSession::PrintEntityStatus, "Prints main informations about an entity : its number, type, validity (and checks if any), category, shareds and sharings.. mutable because it can recompute checks as necessary", py::arg("ent"), py::arg("S"));
cls_IFSelect_WorkSession.def("TraceDumpEntity", (void (IFSelect_WorkSession::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer) const) &IFSelect_WorkSession::TraceDumpEntity, "Dumps an entity from the current Model as inherited DumpEntity on currently defined Default Trace File (<level> interpreted according to the Norm, see WorkLibrary)", py::arg("ent"), py::arg("level"));
cls_IFSelect_WorkSession.def("PrintCheckList", (void (IFSelect_WorkSession::*)(const Interface_CheckIterator &, const Standard_Boolean, const IFSelect_PrintCount) const) &IFSelect_WorkSession::PrintCheckList, "Prints a CheckIterator to the current Trace File, controlled with the current Model complete or fails only, according to <failsonly> <mode> defines the mode of printing 0 : sequential, according entities; else with a CheckCounter 1 : according messages, count of entities 2 : id but with list of entities, designated by their numbers 3 : as 2 but with labels of entities", py::arg("checklist"), py::arg("failsonly"), py::arg("mode"));
cls_IFSelect_WorkSession.def("PrintSignatureList", (void (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_SignatureList> &, const IFSelect_PrintCount) const) &IFSelect_WorkSession::PrintSignatureList, "Prints a SignatureList to the current Trace File, controlled with the current Model <mode> defines the mode of printing (see SignatureList)", py::arg("signlist"), py::arg("mode"));
cls_IFSelect_WorkSession.def("EvaluateSelection", (void (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_Selection> &) const) &IFSelect_WorkSession::EvaluateSelection, "Displays the list of Entities selected by a Selection (i.e. the result of EvalSelection).", py::arg("sel"));
cls_IFSelect_WorkSession.def("EvaluateDispatch", [](IFSelect_WorkSession &self, const opencascade::handle<IFSelect_Dispatch> & a0) -> void { return self.EvaluateDispatch(a0); });
cls_IFSelect_WorkSession.def("EvaluateDispatch", (void (IFSelect_WorkSession::*)(const opencascade::handle<IFSelect_Dispatch> &, const Standard_Integer) const) &IFSelect_WorkSession::EvaluateDispatch, "Displays the result of applying a Dispatch on the input Model (also shows Remainder if there is) <mode> = 0 (default), displays nothing else <mode> = 1 : displays also duplicated entities (because of this dispatch) <mode> = 2 : displays the entities of the starting Model which are not taken by this dispatch (forgotten entities) <mode> = 3 : displays both duplicated and forgotten entities Remark : EvaluateComplete displays these data evaluated for for all the dispatches, if there are several", py::arg("disp"), py::arg("mode"));
cls_IFSelect_WorkSession.def("EvaluateComplete", [](IFSelect_WorkSession &self) -> void { return self.EvaluateComplete(); });
cls_IFSelect_WorkSession.def("EvaluateComplete", (void (IFSelect_WorkSession::*)(const Standard_Integer) const) &IFSelect_WorkSession::EvaluateComplete, "Displays the effect of applying the ShareOut on the input Model. <mode> = 0 (default) : displays only roots for each packet, <mode> = 1 : displays all entities for each packet, plus duplicated entities <mode> = 2 : same as <mode> = 1, plus displays forgotten entities (which are in no packet at all)", py::arg("mode"));
cls_IFSelect_WorkSession.def("ListEntities", (void (IFSelect_WorkSession::*)(const Interface_EntityIterator &, const Standard_Integer) const) &IFSelect_WorkSession::ListEntities, "Internal method which displays an EntityIterator <mode> 0 gives short display (only entity numbers) 1 gives a more complete trace (1 line per Entity) (can be used each time a trace has to be output from a list) 2 gives a form suitable for givelist : (n1,n2,n3...)", py::arg("iter"), py::arg("mode"));
cls_IFSelect_WorkSession.def_static("get_type_name_", (const char * (*)()) &IFSelect_WorkSession::get_type_name, "None");
cls_IFSelect_WorkSession.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_WorkSession::get_type_descriptor, "None");
cls_IFSelect_WorkSession.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_WorkSession::*)() const) &IFSelect_WorkSession::DynamicType, "None");


}
