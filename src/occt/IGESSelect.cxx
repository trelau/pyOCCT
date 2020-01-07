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
#include <IGESData_IGESEntity.hxx>
#include <Interface_Graph.hxx>
#include <IGESSelect_EditHeader.hxx>
#include <IGESSelect_EditDirPart.hxx>
#include <IGESSelect_IGESTypeForm.hxx>
#include <IGESSelect_IGESName.hxx>
#include <IGESSelect_SignStatus.hxx>
#include <IGESSelect_SignLevelNumber.hxx>
#include <IGESSelect_SignColor.hxx>
#include <IGESSelect_CounterOfLevelNumber.hxx>
#include <IGESSelect_ViewSorter.hxx>
#include <IGESSelect_DispPerSingleView.hxx>
#include <IGESSelect_DispPerDrawing.hxx>
#include <IGESSelect_SelectVisibleStatus.hxx>
#include <IGESSelect_SelectSubordinate.hxx>
#include <IGESSelect_SelectLevelNumber.hxx>
#include <IGESSelect_SelectName.hxx>
#include <IGESSelect_SelectFromSingleView.hxx>
#include <IGESSelect_SelectFromDrawing.hxx>
#include <IGESSelect_SelectSingleViewFrom.hxx>
#include <IGESSelect_SelectDrawingFrom.hxx>
#include <IGESSelect_SelectBypassGroup.hxx>
#include <IGESSelect_SelectBypassSubfigure.hxx>
#include <IGESSelect_SelectBasicGeom.hxx>
#include <IGESSelect_SelectFaces.hxx>
#include <IGESSelect_SelectPCurves.hxx>
#include <IGESSelect_ModelModifier.hxx>
#include <IGESSelect_FileModifier.hxx>
#include <IGESSelect_FloatFormat.hxx>
#include <IGESSelect_AddFileComment.hxx>
#include <IGESSelect_UpdateFileName.hxx>
#include <IGESSelect_UpdateCreationDate.hxx>
#include <IGESSelect_UpdateLastChange.hxx>
#include <IGESSelect_SetVersion5.hxx>
#include <IGESSelect_SetGlobalParameter.hxx>
#include <IGESSelect_AutoCorrect.hxx>
#include <IGESSelect_ComputeStatus.hxx>
#include <IGESSelect_RebuildDrawings.hxx>
#include <IGESSelect_RebuildGroups.hxx>
#include <IGESSelect_AddGroup.hxx>
#include <IGESSelect_ChangeLevelNumber.hxx>
#include <IGESSelect_ChangeLevelList.hxx>
#include <IGESSelect_SplineToBSpline.hxx>
#include <IGESSelect_RemoveCurves.hxx>
#include <IGESSelect_SetLabel.hxx>
#include <IGESSelect_WorkLibrary.hxx>
#include <IGESSelect_Activator.hxx>
#include <IGESSelect_Dumper.hxx>
#include <IGESSelect.hxx>
#include <IFSelect_Activator.hxx>
#include <IFSelect_ReturnStatus.hxx>
#include <IFSelect_SessionPilot.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <IFSelect_GeneralModifier.hxx>
#include <IFSelect_ContextWrite.hxx>
#include <IGESData_IGESWriter.hxx>
#include <TColStd_HSequenceOfHAsciiString.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_Modifier.hxx>
#include <IFSelect_ContextModif.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_Protocol.hxx>
#include <Interface_CopyTool.hxx>
#include <IGESData_IGESModel.hxx>
#include <IGESData_Protocol.hxx>
#include <IFSelect_IntParam.hxx>
#include <IFSelect_SignCounter.hxx>
#include <Standard_Transient.hxx>
#include <TColStd_HSequenceOfInteger.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Message_Messenger.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <IFSelect_Dispatch.hxx>
#include <IFGraph_SubPartsIterator.hxx>
#include <Interface_EntityIterator.hxx>
#include <IFSelect_SessionDumper.hxx>
#include <IFSelect_SessionFile.hxx>
#include <IFSelect_Editor.hxx>
#include <IFSelect_EditForm.hxx>
#include <IFSelect_Signature.hxx>
#include <IFSelect_SelectExplore.hxx>
#include <IFSelect_SelectDeduct.hxx>
#include <IFSelect_SelectExtract.hxx>
#include <IFSelect_Transformer.hxx>
#include <Interface_CheckIterator.hxx>
#include <Interface_CopyControl.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <IFSelect_PacketList.hxx>
#include <TColStd_IndexedMapOfTransient.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <IFSelect_WorkLibrary.hxx>

PYBIND11_MODULE(IGESSelect, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.IGESData");
py::module::import("OCCT.Interface");
py::module::import("OCCT.IFSelect");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.Message");
py::module::import("OCCT.IFGraph");

// CLASS: IGESSELECT
py::class_<IGESSelect> cls_IGESSelect(mod, "IGESSelect", "This package defines the library of the most used tools for IGES Files : Selections & Modifiers specific to the IGES norm, and the most needed converters");

// Constructors
cls_IGESSelect.def(py::init<>());

// Methods
// cls_IGESSelect.def_static("operator new_", (void * (*)(size_t)) &IGESSelect::operator new, "None", py::arg("theSize"));
// cls_IGESSelect.def_static("operator delete_", (void (*)(void *)) &IGESSelect::operator delete, "None", py::arg("theAddress"));
// cls_IGESSelect.def_static("operator new[]_", (void * (*)(size_t)) &IGESSelect::operator new[], "None", py::arg("theSize"));
// cls_IGESSelect.def_static("operator delete[]_", (void (*)(void *)) &IGESSelect::operator delete[], "None", py::arg("theAddress"));
// cls_IGESSelect.def_static("operator new_", (void * (*)(size_t, void *)) &IGESSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESSelect.def_static("operator delete_", (void (*)(void *, void *)) &IGESSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESSelect.def_static("Run_", (void (*)()) &IGESSelect::Run, "Simply gives a prompt for a conversational action on standard input/output. Returns the status of a");
cls_IGESSelect.def_static("WhatIges_", [](const opencascade::handle<IGESData_IGESEntity> & ent, const Interface_Graph & G, opencascade::handle<IGESData_IGESEntity> & sup, Standard_Integer & index){ Standard_Integer rv = IGESSelect::WhatIges(ent, G, sup, index); return std::tuple<Standard_Integer, Standard_Integer &>(rv, index); }, "Gives a quick analysis of an IGES Entity in the context of a model (i.e. a File) described by a Graph. Returned values are : : the most meaningfull super entity, if any (else Null) <index> : meaningfull index relating to super entity, if any <returned> : a status which helps exploitation of , by giving a case (normally, types of <ent> and should suffice to known the case)", py::arg("ent"), py::arg("G"), py::arg("sup"), py::arg("index"));

// CLASS: IGESSELECT_ACTIVATOR
py::class_<IGESSelect_Activator, opencascade::handle<IGESSelect_Activator>, IFSelect_Activator> cls_IGESSelect_Activator(mod, "IGESSelect_Activator", "Performs Actions specific to IGESSelect, i.e. creation of IGES Selections and Dispatches, plus dumping specific to IGES");

// Constructors
cls_IGESSelect_Activator.def(py::init<>());

// Methods
cls_IGESSelect_Activator.def("Do", (IFSelect_ReturnStatus (IGESSelect_Activator::*)(const Standard_Integer, const opencascade::handle<IFSelect_SessionPilot> &)) &IGESSelect_Activator::Do, "Executes a Command Line for IGESSelect", py::arg("number"), py::arg("pilot"));
cls_IGESSelect_Activator.def("Help", (Standard_CString (IGESSelect_Activator::*)(const Standard_Integer) const) &IGESSelect_Activator::Help, "Sends a short help message for IGESSelect commands", py::arg("number"));
cls_IGESSelect_Activator.def_static("get_type_name_", (const char * (*)()) &IGESSelect_Activator::get_type_name, "None");
cls_IGESSelect_Activator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_Activator::get_type_descriptor, "None");
cls_IGESSelect_Activator.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_Activator::*)() const) &IGESSelect_Activator::DynamicType, "None");

// CLASS: IGESSELECT_FILEMODIFIER
py::class_<IGESSelect_FileModifier, opencascade::handle<IGESSelect_FileModifier>, IFSelect_GeneralModifier> cls_IGESSelect_FileModifier(mod, "IGESSelect_FileModifier", "None");

// Methods
cls_IGESSelect_FileModifier.def("Perform", (void (IGESSelect_FileModifier::*)(IFSelect_ContextWrite &, IGESData_IGESWriter &) const) &IGESSelect_FileModifier::Perform, "Perform the action specific to each class of File Modifier <ctx> is the ContextWrite, which brings : the model, the protocol, the file name, plus the object AppliedModifiers (not used here) and the CheckList Remark that the model has to be casted for specific access", py::arg("ctx"), py::arg("writer"));
cls_IGESSelect_FileModifier.def_static("get_type_name_", (const char * (*)()) &IGESSelect_FileModifier::get_type_name, "None");
cls_IGESSelect_FileModifier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_FileModifier::get_type_descriptor, "None");
cls_IGESSelect_FileModifier.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_FileModifier::*)() const) &IGESSelect_FileModifier::DynamicType, "None");

// CLASS: IGESSELECT_ADDFILECOMMENT
py::class_<IGESSelect_AddFileComment, opencascade::handle<IGESSelect_AddFileComment>, IGESSelect_FileModifier> cls_IGESSelect_AddFileComment(mod, "IGESSelect_AddFileComment", "This class allows to add comment lines on writing an IGES File These lines are added to Start Section, instead of the only one blank line written by default.");

// Constructors
cls_IGESSelect_AddFileComment.def(py::init<>());

// Methods
cls_IGESSelect_AddFileComment.def("Clear", (void (IGESSelect_AddFileComment::*)()) &IGESSelect_AddFileComment::Clear, "Clears the list of file comment lines already stored");
cls_IGESSelect_AddFileComment.def("AddLine", (void (IGESSelect_AddFileComment::*)(const Standard_CString)) &IGESSelect_AddFileComment::AddLine, "Adds a line for file comment Remark : Lines are limited to 72 useful char.s . A line of more than 72 char.s will be splited into several ones of 72 max each.", py::arg("line"));
cls_IGESSelect_AddFileComment.def("AddLines", (void (IGESSelect_AddFileComment::*)(const opencascade::handle<TColStd_HSequenceOfHAsciiString> &)) &IGESSelect_AddFileComment::AddLines, "Adds a list of lines for file comment Each of them must comply with demand of AddLine", py::arg("lines"));
cls_IGESSelect_AddFileComment.def("NbLines", (Standard_Integer (IGESSelect_AddFileComment::*)() const) &IGESSelect_AddFileComment::NbLines, "Returns the count of stored lines");
cls_IGESSelect_AddFileComment.def("Line", (Standard_CString (IGESSelect_AddFileComment::*)(const Standard_Integer) const) &IGESSelect_AddFileComment::Line, "Returns a stored line given its rank", py::arg("num"));
cls_IGESSelect_AddFileComment.def("Lines", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (IGESSelect_AddFileComment::*)() const) &IGESSelect_AddFileComment::Lines, "Returns the complete list of lines in once");
cls_IGESSelect_AddFileComment.def("Perform", (void (IGESSelect_AddFileComment::*)(IFSelect_ContextWrite &, IGESData_IGESWriter &) const) &IGESSelect_AddFileComment::Perform, "Sends the comment lines to the file (Start Section)", py::arg("ctx"), py::arg("writer"));
cls_IGESSelect_AddFileComment.def("Label", (TCollection_AsciiString (IGESSelect_AddFileComment::*)() const) &IGESSelect_AddFileComment::Label, "Returns specific Label, which is 'Add <nn> Comment Lines (Start Section)'");
cls_IGESSelect_AddFileComment.def_static("get_type_name_", (const char * (*)()) &IGESSelect_AddFileComment::get_type_name, "None");
cls_IGESSelect_AddFileComment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_AddFileComment::get_type_descriptor, "None");
cls_IGESSelect_AddFileComment.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_AddFileComment::*)() const) &IGESSelect_AddFileComment::DynamicType, "None");

// CLASS: IGESSELECT_MODELMODIFIER
py::class_<IGESSelect_ModelModifier, opencascade::handle<IGESSelect_ModelModifier>, IFSelect_Modifier> cls_IGESSelect_ModelModifier(mod, "IGESSelect_ModelModifier", "None");

// Methods
cls_IGESSelect_ModelModifier.def("Perform", (void (IGESSelect_ModelModifier::*)(IFSelect_ContextModif &, const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &, Interface_CopyTool &) const) &IGESSelect_ModelModifier::Perform, "The inherited Perform does the required cast (and refuses to go further if cast has failed) then calls the instantiated Performing", py::arg("ctx"), py::arg("target"), py::arg("protocol"), py::arg("TC"));
cls_IGESSelect_ModelModifier.def("PerformProtocol", (void (IGESSelect_ModelModifier::*)(IFSelect_ContextModif &, const opencascade::handle<IGESData_IGESModel> &, const opencascade::handle<IGESData_Protocol> &, Interface_CopyTool &) const) &IGESSelect_ModelModifier::PerformProtocol, "Specific Perform with Protocol. It is defined to let the Protocol unused and to call Performing without Protocol (most current case). It can be redefined if specific action requires Protocol.", py::arg("ctx"), py::arg("target"), py::arg("proto"), py::arg("TC"));
cls_IGESSelect_ModelModifier.def("Performing", (void (IGESSelect_ModelModifier::*)(IFSelect_ContextModif &, const opencascade::handle<IGESData_IGESModel> &, Interface_CopyTool &) const) &IGESSelect_ModelModifier::Performing, "Specific Perform, without Protocol. If Performing with Protocol is redefined, Performing without Protocol must though be defined to do nothing (not called, but demanded by the linker)", py::arg("ctx"), py::arg("target"), py::arg("TC"));
cls_IGESSelect_ModelModifier.def_static("get_type_name_", (const char * (*)()) &IGESSelect_ModelModifier::get_type_name, "None");
cls_IGESSelect_ModelModifier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_ModelModifier::get_type_descriptor, "None");
cls_IGESSelect_ModelModifier.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_ModelModifier::*)() const) &IGESSelect_ModelModifier::DynamicType, "None");

// CLASS: IGESSELECT_ADDGROUP
py::class_<IGESSelect_AddGroup, opencascade::handle<IGESSelect_AddGroup>, IGESSelect_ModelModifier> cls_IGESSelect_AddGroup(mod, "IGESSelect_AddGroup", "Adds a Group to contain the entities designated by the Selection. If no Selection is given, nothing is done");

// Constructors
cls_IGESSelect_AddGroup.def(py::init<>());

// Methods
cls_IGESSelect_AddGroup.def("Performing", (void (IGESSelect_AddGroup::*)(IFSelect_ContextModif &, const opencascade::handle<IGESData_IGESModel> &, Interface_CopyTool &) const) &IGESSelect_AddGroup::Performing, "Specific action : Adds a new group", py::arg("ctx"), py::arg("target"), py::arg("TC"));
cls_IGESSelect_AddGroup.def("Label", (TCollection_AsciiString (IGESSelect_AddGroup::*)() const) &IGESSelect_AddGroup::Label, "Returns a text which is 'Add Group'");
cls_IGESSelect_AddGroup.def_static("get_type_name_", (const char * (*)()) &IGESSelect_AddGroup::get_type_name, "None");
cls_IGESSelect_AddGroup.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_AddGroup::get_type_descriptor, "None");
cls_IGESSelect_AddGroup.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_AddGroup::*)() const) &IGESSelect_AddGroup::DynamicType, "None");

// CLASS: IGESSELECT_AUTOCORRECT
py::class_<IGESSelect_AutoCorrect, opencascade::handle<IGESSelect_AutoCorrect>, IGESSelect_ModelModifier> cls_IGESSelect_AutoCorrect(mod, "IGESSelect_AutoCorrect", "Does the absolutely effective corrections on IGES Entity. That is to say : regarding the norm in details, some values have mandatory values, or set of values with constraints. When such values/constraints are univoque, they can be forced. Also nullifies items of Directory Part, Associativities, and Properties, which are not (or not longer) in <target> Model.");

// Constructors
cls_IGESSelect_AutoCorrect.def(py::init<>());

// Methods
cls_IGESSelect_AutoCorrect.def("Performing", (void (IGESSelect_AutoCorrect::*)(IFSelect_ContextModif &, const opencascade::handle<IGESData_IGESModel> &, Interface_CopyTool &) const) &IGESSelect_AutoCorrect::Performing, "Specific action : corrects entities when it is absolutely obvious, i.e. non equivoque (by DirChecker and specific service OwnCorrect) : works with a protocol.", py::arg("ctx"), py::arg("target"), py::arg("TC"));
cls_IGESSelect_AutoCorrect.def("Label", (TCollection_AsciiString (IGESSelect_AutoCorrect::*)() const) &IGESSelect_AutoCorrect::Label, "Returns a text which is 'Auto-correction of IGES Entities'");
cls_IGESSelect_AutoCorrect.def_static("get_type_name_", (const char * (*)()) &IGESSelect_AutoCorrect::get_type_name, "None");
cls_IGESSelect_AutoCorrect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_AutoCorrect::get_type_descriptor, "None");
cls_IGESSelect_AutoCorrect.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_AutoCorrect::*)() const) &IGESSelect_AutoCorrect::DynamicType, "None");

// CLASS: IGESSELECT_CHANGELEVELLIST
py::class_<IGESSelect_ChangeLevelList, opencascade::handle<IGESSelect_ChangeLevelList>, IGESSelect_ModelModifier> cls_IGESSelect_ChangeLevelList(mod, "IGESSelect_ChangeLevelList", "Changes Level List (in directory part) to a new single value Only entities attached to a LevelListEntity are considered If OldNumber is defined, only entities whose LevelList contains its Value are processed. Else all LevelLists are.");

// Constructors
cls_IGESSelect_ChangeLevelList.def(py::init<>());

// Methods
cls_IGESSelect_ChangeLevelList.def("HasOldNumber", (Standard_Boolean (IGESSelect_ChangeLevelList::*)() const) &IGESSelect_ChangeLevelList::HasOldNumber, "Returns True if OldNumber is defined : then, only entities which have a LevelList which contains the value are processed. Else, all entities attached to a LevelList are.");
cls_IGESSelect_ChangeLevelList.def("OldNumber", (opencascade::handle<IFSelect_IntParam> (IGESSelect_ChangeLevelList::*)() const) &IGESSelect_ChangeLevelList::OldNumber, "Returns the parameter for OldNumber. If not defined (Null Handle), it will be interpreted as 'all level lists'");
cls_IGESSelect_ChangeLevelList.def("SetOldNumber", (void (IGESSelect_ChangeLevelList::*)(const opencascade::handle<IFSelect_IntParam> &)) &IGESSelect_ChangeLevelList::SetOldNumber, "Sets a parameter for OldNumber", py::arg("param"));
cls_IGESSelect_ChangeLevelList.def("HasNewNumber", (Standard_Boolean (IGESSelect_ChangeLevelList::*)() const) &IGESSelect_ChangeLevelList::HasNewNumber, "Returns True if NewNumber is defined : then, it gives the new value for Level Number. Else, the first value of the LevelList is used as new Level Number.");
cls_IGESSelect_ChangeLevelList.def("NewNumber", (opencascade::handle<IFSelect_IntParam> (IGESSelect_ChangeLevelList::*)() const) &IGESSelect_ChangeLevelList::NewNumber, "Returns the parameter for NewNumber. If not defined (Null Handle), it will be interpreted as 'new value 0'");
cls_IGESSelect_ChangeLevelList.def("SetNewNumber", (void (IGESSelect_ChangeLevelList::*)(const opencascade::handle<IFSelect_IntParam> &)) &IGESSelect_ChangeLevelList::SetNewNumber, "Sets a parameter for NewNumber", py::arg("param"));
cls_IGESSelect_ChangeLevelList.def("Performing", (void (IGESSelect_ChangeLevelList::*)(IFSelect_ContextModif &, const opencascade::handle<IGESData_IGESModel> &, Interface_CopyTool &) const) &IGESSelect_ChangeLevelList::Performing, "Specific action : considers selected target entities : If OldNumber is not defined, all entities attached to a Level List If OldNumber is defined (value not negative), entities with a Level List which contains this value Attaches all these entities to value given by NewNumber, or the first value of the Level List", py::arg("ctx"), py::arg("target"), py::arg("TC"));
cls_IGESSelect_ChangeLevelList.def("Label", (TCollection_AsciiString (IGESSelect_ChangeLevelList::*)() const) &IGESSelect_ChangeLevelList::Label, "Returns a text which begins by 'Changes Level Lists containing <old>', or 'Changes all Level Lists in D.E.', and ends by ' to Number <new>' or ' to Number = first value in List'");
cls_IGESSelect_ChangeLevelList.def_static("get_type_name_", (const char * (*)()) &IGESSelect_ChangeLevelList::get_type_name, "None");
cls_IGESSelect_ChangeLevelList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_ChangeLevelList::get_type_descriptor, "None");
cls_IGESSelect_ChangeLevelList.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_ChangeLevelList::*)() const) &IGESSelect_ChangeLevelList::DynamicType, "None");

// CLASS: IGESSELECT_CHANGELEVELNUMBER
py::class_<IGESSelect_ChangeLevelNumber, opencascade::handle<IGESSelect_ChangeLevelNumber>, IGESSelect_ModelModifier> cls_IGESSelect_ChangeLevelNumber(mod, "IGESSelect_ChangeLevelNumber", "Changes Level Number (as null or single) to a new single value Entities attached to a LevelListEntity are ignored Entities considered can be, either all Entities but those attached to a LevelListEntity, or Entities attached to a specific Level Number (0 for not defined).");

// Constructors
cls_IGESSelect_ChangeLevelNumber.def(py::init<>());

// Methods
cls_IGESSelect_ChangeLevelNumber.def("HasOldNumber", (Standard_Boolean (IGESSelect_ChangeLevelNumber::*)() const) &IGESSelect_ChangeLevelNumber::HasOldNumber, "Returns True if OldNumber is defined : then, only entities attached to the value of OldNumber will be considered. Else, all entities but those attached to a Level List will be.");
cls_IGESSelect_ChangeLevelNumber.def("OldNumber", (opencascade::handle<IFSelect_IntParam> (IGESSelect_ChangeLevelNumber::*)() const) &IGESSelect_ChangeLevelNumber::OldNumber, "Returns the parameter for OldNumber. If not defined (Null Handle), it will be interpreted as 'all level numbers'");
cls_IGESSelect_ChangeLevelNumber.def("SetOldNumber", (void (IGESSelect_ChangeLevelNumber::*)(const opencascade::handle<IFSelect_IntParam> &)) &IGESSelect_ChangeLevelNumber::SetOldNumber, "Sets a parameter for OldNumber", py::arg("param"));
cls_IGESSelect_ChangeLevelNumber.def("NewNumber", (opencascade::handle<IFSelect_IntParam> (IGESSelect_ChangeLevelNumber::*)() const) &IGESSelect_ChangeLevelNumber::NewNumber, "Returns the parameter for NewNumber. If not defined (Null Handle), it will be interpreted as 'new value 0'");
cls_IGESSelect_ChangeLevelNumber.def("SetNewNumber", (void (IGESSelect_ChangeLevelNumber::*)(const opencascade::handle<IFSelect_IntParam> &)) &IGESSelect_ChangeLevelNumber::SetNewNumber, "Sets a parameter for NewNumber", py::arg("param"));
cls_IGESSelect_ChangeLevelNumber.def("Performing", (void (IGESSelect_ChangeLevelNumber::*)(IFSelect_ContextModif &, const opencascade::handle<IGESData_IGESModel> &, Interface_CopyTool &) const) &IGESSelect_ChangeLevelNumber::Performing, "Specific action : considers selected target entities : If OldNumber is not defined, all entities but those attached to a Level List If OldNumber is defined (value not negative), entities with a defined Level Number (can be zero) Attaches all these entities to value given by NewNumber, or zero if not defined", py::arg("ctx"), py::arg("target"), py::arg("TC"));
cls_IGESSelect_ChangeLevelNumber.def("Label", (TCollection_AsciiString (IGESSelect_ChangeLevelNumber::*)() const) &IGESSelect_ChangeLevelNumber::Label, "Returns a text which is 'Changes Level Number <old> to <new>' , or 'Changes all Levels Numbers positive and zero to <new>'");
cls_IGESSelect_ChangeLevelNumber.def_static("get_type_name_", (const char * (*)()) &IGESSelect_ChangeLevelNumber::get_type_name, "None");
cls_IGESSelect_ChangeLevelNumber.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_ChangeLevelNumber::get_type_descriptor, "None");
cls_IGESSelect_ChangeLevelNumber.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_ChangeLevelNumber::*)() const) &IGESSelect_ChangeLevelNumber::DynamicType, "None");

// CLASS: IGESSELECT_COMPUTESTATUS
py::class_<IGESSelect_ComputeStatus, opencascade::handle<IGESSelect_ComputeStatus>, IGESSelect_ModelModifier> cls_IGESSelect_ComputeStatus(mod, "IGESSelect_ComputeStatus", "Computes Status of IGES Entities for a whole IGESModel. This concerns SubordinateStatus and UseFlag, which must have some definite values according the way they are referenced. (see definitions of Logical use, Physical use, etc...)");

// Constructors
cls_IGESSelect_ComputeStatus.def(py::init<>());

// Methods
cls_IGESSelect_ComputeStatus.def("Performing", (void (IGESSelect_ComputeStatus::*)(IFSelect_ContextModif &, const opencascade::handle<IGESData_IGESModel> &, Interface_CopyTool &) const) &IGESSelect_ComputeStatus::Performing, "Specific action : it first evaluates the required values for Subordinate Status and Use Flag (in Directory Part of each IGES Entity). Then it corrects them, for the whole target. Works with a Protocol. Implementation uses BasicEditor", py::arg("ctx"), py::arg("target"), py::arg("TC"));
cls_IGESSelect_ComputeStatus.def("Label", (TCollection_AsciiString (IGESSelect_ComputeStatus::*)() const) &IGESSelect_ComputeStatus::Label, "Returns a text which is 'Compute Subordinate Status and Use Flag'");
cls_IGESSelect_ComputeStatus.def_static("get_type_name_", (const char * (*)()) &IGESSelect_ComputeStatus::get_type_name, "None");
cls_IGESSelect_ComputeStatus.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_ComputeStatus::get_type_descriptor, "None");
cls_IGESSelect_ComputeStatus.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_ComputeStatus::*)() const) &IGESSelect_ComputeStatus::DynamicType, "None");

// CLASS: IGESSELECT_COUNTEROFLEVELNUMBER
py::class_<IGESSelect_CounterOfLevelNumber, opencascade::handle<IGESSelect_CounterOfLevelNumber>, IFSelect_SignCounter> cls_IGESSelect_CounterOfLevelNumber(mod, "IGESSelect_CounterOfLevelNumber", "This class gives information about Level Number. It counts entities according level number, considering also the multiple level (see the class LevelList) for which an entity is attached to each of the listed levels.");

// Constructors
cls_IGESSelect_CounterOfLevelNumber.def(py::init<>());
cls_IGESSelect_CounterOfLevelNumber.def(py::init<const Standard_Boolean>(), py::arg("withmap"));
cls_IGESSelect_CounterOfLevelNumber.def(py::init<const Standard_Boolean, const Standard_Boolean>(), py::arg("withmap"), py::arg("withlist"));

// Methods
cls_IGESSelect_CounterOfLevelNumber.def("Clear", (void (IGESSelect_CounterOfLevelNumber::*)()) &IGESSelect_CounterOfLevelNumber::Clear, "Resets already memorized informations : also numeric data");
cls_IGESSelect_CounterOfLevelNumber.def("AddSign", (void (IGESSelect_CounterOfLevelNumber::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &)) &IGESSelect_CounterOfLevelNumber::AddSign, "Adds an entity by considering its lrvrl number(s) A level is added both in numeric and alphanumeric form, i.e. LevelList gives 'LEVEL LIST', others (no level or positive level) displays level number on 7 digits (C : %7d) Remark : an entity attached to a Level List is added for ' LEVEL LIST', and for each of its constituant levels", py::arg("ent"), py::arg("model"));
cls_IGESSelect_CounterOfLevelNumber.def("AddLevel", (void (IGESSelect_CounterOfLevelNumber::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer)) &IGESSelect_CounterOfLevelNumber::AddLevel, "The internal action to record a new level number, positive, null (no level) or negative (level list)", py::arg("ent"), py::arg("level"));
cls_IGESSelect_CounterOfLevelNumber.def("HighestLevel", (Standard_Integer (IGESSelect_CounterOfLevelNumber::*)() const) &IGESSelect_CounterOfLevelNumber::HighestLevel, "Returns the highest value found for a level number");
cls_IGESSelect_CounterOfLevelNumber.def("NbTimesLevel", (Standard_Integer (IGESSelect_CounterOfLevelNumber::*)(const Standard_Integer) const) &IGESSelect_CounterOfLevelNumber::NbTimesLevel, "Returns the number of times a level is used, 0 if it has not been recorded at all <level> = 0 counts entities attached to no level <level> < 0 counts entities attached to a LevelList", py::arg("level"));
cls_IGESSelect_CounterOfLevelNumber.def("Levels", (opencascade::handle<TColStd_HSequenceOfInteger> (IGESSelect_CounterOfLevelNumber::*)() const) &IGESSelect_CounterOfLevelNumber::Levels, "Returns the ordered list of used positive Level numbers");
cls_IGESSelect_CounterOfLevelNumber.def("Sign", (opencascade::handle<TCollection_HAsciiString> (IGESSelect_CounterOfLevelNumber::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IGESSelect_CounterOfLevelNumber::Sign, "Determines and returns the value of the signature for an entity as an HAsciiString. Redefined, gives the same result as AddSign, see this method ('LEVEL LIST' or 'nnnnnnn')", py::arg("ent"), py::arg("model"));
cls_IGESSelect_CounterOfLevelNumber.def("PrintCount", (void (IGESSelect_CounterOfLevelNumber::*)(const opencascade::handle<Message_Messenger> &) const) &IGESSelect_CounterOfLevelNumber::PrintCount, "Prints the counts of items (not the list) then the Highest Level Number recorded", py::arg("S"));
cls_IGESSelect_CounterOfLevelNumber.def_static("get_type_name_", (const char * (*)()) &IGESSelect_CounterOfLevelNumber::get_type_name, "None");
cls_IGESSelect_CounterOfLevelNumber.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_CounterOfLevelNumber::get_type_descriptor, "None");
cls_IGESSelect_CounterOfLevelNumber.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_CounterOfLevelNumber::*)() const) &IGESSelect_CounterOfLevelNumber::DynamicType, "None");

// CLASS: IGESSELECT_DISPPERDRAWING
py::class_<IGESSelect_DispPerDrawing, opencascade::handle<IGESSelect_DispPerDrawing>, IFSelect_Dispatch> cls_IGESSelect_DispPerDrawing(mod, "IGESSelect_DispPerDrawing", "This type of dispatch defines sets of entities attached to distinct drawings. This information is taken from attached views which appear in the Directory Part. Also Drawing Frames are considered when Drawings are part of input list.");

// Constructors
cls_IGESSelect_DispPerDrawing.def(py::init<>());

// Methods
cls_IGESSelect_DispPerDrawing.def("Label", (TCollection_AsciiString (IGESSelect_DispPerDrawing::*)() const) &IGESSelect_DispPerDrawing::Label, "Returns as Label, 'One File per Drawing'");
cls_IGESSelect_DispPerDrawing.def("Packets", (void (IGESSelect_DispPerDrawing::*)(const Interface_Graph &, IFGraph_SubPartsIterator &) const) &IGESSelect_DispPerDrawing::Packets, "Computes the list of produced Packets. Packets are computed by a ViewSorter (SortDrawings with also frames).", py::arg("G"), py::arg("packs"));
cls_IGESSelect_DispPerDrawing.def("CanHaveRemainder", (Standard_Boolean (IGESSelect_DispPerDrawing::*)() const) &IGESSelect_DispPerDrawing::CanHaveRemainder, "Returns True, because of entities attached to no view.");
cls_IGESSelect_DispPerDrawing.def("Remainder", (Interface_EntityIterator (IGESSelect_DispPerDrawing::*)(const Interface_Graph &) const) &IGESSelect_DispPerDrawing::Remainder, "Returns Remainder which is a set of Entities. It is supposed to be called once Packets has been called.", py::arg("G"));
cls_IGESSelect_DispPerDrawing.def_static("get_type_name_", (const char * (*)()) &IGESSelect_DispPerDrawing::get_type_name, "None");
cls_IGESSelect_DispPerDrawing.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_DispPerDrawing::get_type_descriptor, "None");
cls_IGESSelect_DispPerDrawing.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_DispPerDrawing::*)() const) &IGESSelect_DispPerDrawing::DynamicType, "None");

// CLASS: IGESSELECT_DISPPERSINGLEVIEW
py::class_<IGESSelect_DispPerSingleView, opencascade::handle<IGESSelect_DispPerSingleView>, IFSelect_Dispatch> cls_IGESSelect_DispPerSingleView(mod, "IGESSelect_DispPerSingleView", "This type of dispatch defines sets of entities attached to distinct single views. This information appears in the Directory Part. Drawings are taken into account too, because of their frames (proper lists of annotations)");

// Constructors
cls_IGESSelect_DispPerSingleView.def(py::init<>());

// Methods
cls_IGESSelect_DispPerSingleView.def("Label", (TCollection_AsciiString (IGESSelect_DispPerSingleView::*)() const) &IGESSelect_DispPerSingleView::Label, "Returns as Label, 'One File per single View or Drawing Frame'");
cls_IGESSelect_DispPerSingleView.def("Packets", (void (IGESSelect_DispPerSingleView::*)(const Interface_Graph &, IFGraph_SubPartsIterator &) const) &IGESSelect_DispPerSingleView::Packets, "Computes the list of produced Packets. Packets are computed by a ViewSorter (SortSingleViews with also frames).", py::arg("G"), py::arg("packs"));
cls_IGESSelect_DispPerSingleView.def("CanHaveRemainder", (Standard_Boolean (IGESSelect_DispPerSingleView::*)() const) &IGESSelect_DispPerSingleView::CanHaveRemainder, "Returns True, because of entities attached to no view.");
cls_IGESSelect_DispPerSingleView.def("Remainder", (Interface_EntityIterator (IGESSelect_DispPerSingleView::*)(const Interface_Graph &) const) &IGESSelect_DispPerSingleView::Remainder, "Returns Remainder which is a set of Entities. It is supposed to be called once Packets has been called.", py::arg("G"));
cls_IGESSelect_DispPerSingleView.def_static("get_type_name_", (const char * (*)()) &IGESSelect_DispPerSingleView::get_type_name, "None");
cls_IGESSelect_DispPerSingleView.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_DispPerSingleView::get_type_descriptor, "None");
cls_IGESSelect_DispPerSingleView.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_DispPerSingleView::*)() const) &IGESSelect_DispPerSingleView::DynamicType, "None");

// CLASS: IGESSELECT_DUMPER
py::class_<IGESSelect_Dumper, opencascade::handle<IGESSelect_Dumper>, IFSelect_SessionDumper> cls_IGESSelect_Dumper(mod, "IGESSelect_Dumper", "Dumper from IGESSelect takes into account, for SessionFile, the classes defined in the package IGESSelect : Selections, Dispatches, Modifiers");

// Constructors
cls_IGESSelect_Dumper.def(py::init<>());

// Methods
cls_IGESSelect_Dumper.def("WriteOwn", (Standard_Boolean (IGESSelect_Dumper::*)(IFSelect_SessionFile &, const opencascade::handle<Standard_Transient> &) const) &IGESSelect_Dumper::WriteOwn, "Write the Own Parameters of Types defined in package IGESSelect Returns True if <item> has been processed, False else", py::arg("file"), py::arg("item"));
cls_IGESSelect_Dumper.def("ReadOwn", (Standard_Boolean (IGESSelect_Dumper::*)(IFSelect_SessionFile &, const TCollection_AsciiString &, opencascade::handle<Standard_Transient> &) const) &IGESSelect_Dumper::ReadOwn, "Recognizes and Read Own Parameters for Types of package IGESSelect. Returns True if done and <item> created, False else", py::arg("file"), py::arg("type"), py::arg("item"));
cls_IGESSelect_Dumper.def_static("get_type_name_", (const char * (*)()) &IGESSelect_Dumper::get_type_name, "None");
cls_IGESSelect_Dumper.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_Dumper::get_type_descriptor, "None");
cls_IGESSelect_Dumper.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_Dumper::*)() const) &IGESSelect_Dumper::DynamicType, "None");

// CLASS: IGESSELECT_EDITDIRPART
py::class_<IGESSelect_EditDirPart, opencascade::handle<IGESSelect_EditDirPart>, IFSelect_Editor> cls_IGESSelect_EditDirPart(mod, "IGESSelect_EditDirPart", "This class is aimed to display and edit the Directory Part of an IGESEntity");

// Constructors
cls_IGESSelect_EditDirPart.def(py::init<>());

// Methods
cls_IGESSelect_EditDirPart.def("Label", (TCollection_AsciiString (IGESSelect_EditDirPart::*)() const) &IGESSelect_EditDirPart::Label, "None");
cls_IGESSelect_EditDirPart.def("Recognize", (Standard_Boolean (IGESSelect_EditDirPart::*)(const opencascade::handle<IFSelect_EditForm> &) const) &IGESSelect_EditDirPart::Recognize, "None", py::arg("form"));
cls_IGESSelect_EditDirPart.def("StringValue", (opencascade::handle<TCollection_HAsciiString> (IGESSelect_EditDirPart::*)(const opencascade::handle<IFSelect_EditForm> &, const Standard_Integer) const) &IGESSelect_EditDirPart::StringValue, "None", py::arg("form"), py::arg("num"));
cls_IGESSelect_EditDirPart.def("Load", (Standard_Boolean (IGESSelect_EditDirPart::*)(const opencascade::handle<IFSelect_EditForm> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IGESSelect_EditDirPart::Load, "None", py::arg("form"), py::arg("ent"), py::arg("model"));
cls_IGESSelect_EditDirPart.def("Update", (Standard_Boolean (IGESSelect_EditDirPart::*)(const opencascade::handle<IFSelect_EditForm> &, const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean) const) &IGESSelect_EditDirPart::Update, "None", py::arg("form"), py::arg("num"), py::arg("newval"), py::arg("enforce"));
cls_IGESSelect_EditDirPart.def("Apply", (Standard_Boolean (IGESSelect_EditDirPart::*)(const opencascade::handle<IFSelect_EditForm> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IGESSelect_EditDirPart::Apply, "None", py::arg("form"), py::arg("ent"), py::arg("model"));
cls_IGESSelect_EditDirPart.def_static("get_type_name_", (const char * (*)()) &IGESSelect_EditDirPart::get_type_name, "None");
cls_IGESSelect_EditDirPart.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_EditDirPart::get_type_descriptor, "None");
cls_IGESSelect_EditDirPart.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_EditDirPart::*)() const) &IGESSelect_EditDirPart::DynamicType, "None");

// CLASS: IGESSELECT_EDITHEADER
py::class_<IGESSelect_EditHeader, opencascade::handle<IGESSelect_EditHeader>, IFSelect_Editor> cls_IGESSelect_EditHeader(mod, "IGESSelect_EditHeader", "This class is aimed to display and edit the Header of an IGES Model : Start Section and Global Section");

// Constructors
cls_IGESSelect_EditHeader.def(py::init<>());

// Methods
cls_IGESSelect_EditHeader.def("Label", (TCollection_AsciiString (IGESSelect_EditHeader::*)() const) &IGESSelect_EditHeader::Label, "None");
cls_IGESSelect_EditHeader.def("Recognize", (Standard_Boolean (IGESSelect_EditHeader::*)(const opencascade::handle<IFSelect_EditForm> &) const) &IGESSelect_EditHeader::Recognize, "None", py::arg("form"));
cls_IGESSelect_EditHeader.def("StringValue", (opencascade::handle<TCollection_HAsciiString> (IGESSelect_EditHeader::*)(const opencascade::handle<IFSelect_EditForm> &, const Standard_Integer) const) &IGESSelect_EditHeader::StringValue, "None", py::arg("form"), py::arg("num"));
cls_IGESSelect_EditHeader.def("Load", (Standard_Boolean (IGESSelect_EditHeader::*)(const opencascade::handle<IFSelect_EditForm> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IGESSelect_EditHeader::Load, "None", py::arg("form"), py::arg("ent"), py::arg("model"));
cls_IGESSelect_EditHeader.def("Update", (Standard_Boolean (IGESSelect_EditHeader::*)(const opencascade::handle<IFSelect_EditForm> &, const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean) const) &IGESSelect_EditHeader::Update, "None", py::arg("form"), py::arg("num"), py::arg("newval"), py::arg("enforce"));
cls_IGESSelect_EditHeader.def("Apply", (Standard_Boolean (IGESSelect_EditHeader::*)(const opencascade::handle<IFSelect_EditForm> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IGESSelect_EditHeader::Apply, "None", py::arg("form"), py::arg("ent"), py::arg("model"));
cls_IGESSelect_EditHeader.def_static("get_type_name_", (const char * (*)()) &IGESSelect_EditHeader::get_type_name, "None");
cls_IGESSelect_EditHeader.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_EditHeader::get_type_descriptor, "None");
cls_IGESSelect_EditHeader.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_EditHeader::*)() const) &IGESSelect_EditHeader::DynamicType, "None");

// CLASS: IGESSELECT_FLOATFORMAT
py::class_<IGESSelect_FloatFormat, opencascade::handle<IGESSelect_FloatFormat>, IGESSelect_FileModifier> cls_IGESSelect_FloatFormat(mod, "IGESSelect_FloatFormat", "This class gives control out format for floatting values : ZeroSuppress or no, Main Format, Format in Range (for values around 1.), as IGESWriter allows to manage it. Formats are given under C-printf form");

// Constructors
cls_IGESSelect_FloatFormat.def(py::init<>());

// Methods
cls_IGESSelect_FloatFormat.def("SetDefault", [](IGESSelect_FloatFormat &self) -> void { return self.SetDefault(); });
cls_IGESSelect_FloatFormat.def("SetDefault", (void (IGESSelect_FloatFormat::*)(const Standard_Integer)) &IGESSelect_FloatFormat::SetDefault, "Sets FloatFormat to default value (see Create) but if <digits> is given positive, it commands Formats (main and range) to ensure <digits> significant digits to be displayed", py::arg("digits"));
cls_IGESSelect_FloatFormat.def("SetZeroSuppress", (void (IGESSelect_FloatFormat::*)(const Standard_Boolean)) &IGESSelect_FloatFormat::SetZeroSuppress, "Sets ZeroSuppress mode to a new value", py::arg("mode"));
cls_IGESSelect_FloatFormat.def("SetFormat", [](IGESSelect_FloatFormat &self) -> void { return self.SetFormat(); });
cls_IGESSelect_FloatFormat.def("SetFormat", (void (IGESSelect_FloatFormat::*)(const Standard_CString)) &IGESSelect_FloatFormat::SetFormat, "Sets Main Format to a new value Remark : SetFormat, SetZeroSuppress and SetFormatForRange are independant", py::arg("format"));
cls_IGESSelect_FloatFormat.def("SetFormatForRange", [](IGESSelect_FloatFormat &self) -> void { return self.SetFormatForRange(); });
cls_IGESSelect_FloatFormat.def("SetFormatForRange", [](IGESSelect_FloatFormat &self, const Standard_CString a0) -> void { return self.SetFormatForRange(a0); });
cls_IGESSelect_FloatFormat.def("SetFormatForRange", [](IGESSelect_FloatFormat &self, const Standard_CString a0, const Standard_Real a1) -> void { return self.SetFormatForRange(a0, a1); });
cls_IGESSelect_FloatFormat.def("SetFormatForRange", (void (IGESSelect_FloatFormat::*)(const Standard_CString, const Standard_Real, const Standard_Real)) &IGESSelect_FloatFormat::SetFormatForRange, "Sets Format for Range to a new value with its range of application. To cancel it, give format as '' (empty string) Remark that if the condition (0. < Rmin < Rmax) is not verified, this secondary format will be ignored. Moreover, this secondary format is intended to be used in a range around 1.", py::arg("format"), py::arg("Rmin"), py::arg("Rmax"));
cls_IGESSelect_FloatFormat.def("Format", [](IGESSelect_FloatFormat &self, Standard_Boolean & zerosup, TCollection_AsciiString & mainform, Standard_Boolean & hasrange, TCollection_AsciiString & forminrange, Standard_Real & rangemin, Standard_Real & rangemax){ self.Format(zerosup, mainform, hasrange, forminrange, rangemin, rangemax); return std::tuple<Standard_Boolean &, Standard_Boolean &, Standard_Real &, Standard_Real &>(zerosup, hasrange, rangemin, rangemax); }, "Returns all recorded parameters : zerosup : ZeroSuppress status mainform : Main Format (which applies out of the range, or for every real if no range is set) hasrange : True if a FormatInRange is set, False else (following parameters do not apply if it is False) forminrange : Secondary Format (it applies inside the range) rangemin, rangemax : the range in which the secondary format applies", py::arg("zerosup"), py::arg("mainform"), py::arg("hasrange"), py::arg("forminrange"), py::arg("rangemin"), py::arg("rangemax"));
cls_IGESSelect_FloatFormat.def("Perform", (void (IGESSelect_FloatFormat::*)(IFSelect_ContextWrite &, IGESData_IGESWriter &) const) &IGESSelect_FloatFormat::Perform, "Sets the Floatting Formats of IGESWriter to the recorded parameters", py::arg("ctx"), py::arg("writer"));
cls_IGESSelect_FloatFormat.def("Label", (TCollection_AsciiString (IGESSelect_FloatFormat::*)() const) &IGESSelect_FloatFormat::Label, "Returns specific Label : for instance, 'Float Format [ZeroSuppress] %E [, in range R1-R2 %f]'");
cls_IGESSelect_FloatFormat.def_static("get_type_name_", (const char * (*)()) &IGESSelect_FloatFormat::get_type_name, "None");
cls_IGESSelect_FloatFormat.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_FloatFormat::get_type_descriptor, "None");
cls_IGESSelect_FloatFormat.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_FloatFormat::*)() const) &IGESSelect_FloatFormat::DynamicType, "None");

// CLASS: IGESSELECT_IGESNAME
py::class_<IGESSelect_IGESName, opencascade::handle<IGESSelect_IGESName>, IFSelect_Signature> cls_IGESSelect_IGESName(mod, "IGESSelect_IGESName", "IGESName is a Signature specific to IGESNorm : it considers the Name of an IGESEntity as being its ShortLabel (some sending systems use name, not to identify entities, but ratjer to classify them)");

// Constructors
cls_IGESSelect_IGESName.def(py::init<>());

// Methods
cls_IGESSelect_IGESName.def("Value", (Standard_CString (IGESSelect_IGESName::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IGESSelect_IGESName::Value, "Returns the ShortLabel as being the Name of an IGESEntity If <ent> has no name, it returns empty string ''", py::arg("ent"), py::arg("model"));
cls_IGESSelect_IGESName.def_static("get_type_name_", (const char * (*)()) &IGESSelect_IGESName::get_type_name, "None");
cls_IGESSelect_IGESName.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_IGESName::get_type_descriptor, "None");
cls_IGESSelect_IGESName.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_IGESName::*)() const) &IGESSelect_IGESName::DynamicType, "None");

// CLASS: IGESSELECT_IGESTYPEFORM
py::class_<IGESSelect_IGESTypeForm, opencascade::handle<IGESSelect_IGESTypeForm>, IFSelect_Signature> cls_IGESSelect_IGESTypeForm(mod, "IGESSelect_IGESTypeForm", "IGESTypeForm is a Signature specific to the IGES Norm : it gives the signature under two possible forms : - as 'mmm nnn', with 'mmm' as IGES Type Number, and 'nnn' as IGES From Number (even if = 0) [Default] - as 'mmm' alone, which gives only the IGES Type Number");

// Constructors
cls_IGESSelect_IGESTypeForm.def(py::init<>());
cls_IGESSelect_IGESTypeForm.def(py::init<const Standard_Boolean>(), py::arg("withform"));

// Methods
cls_IGESSelect_IGESTypeForm.def("SetForm", (void (IGESSelect_IGESTypeForm::*)(const Standard_Boolean)) &IGESSelect_IGESTypeForm::SetForm, "Changes the mode for giving the Form Number", py::arg("withform"));
cls_IGESSelect_IGESTypeForm.def("Value", (Standard_CString (IGESSelect_IGESTypeForm::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IGESSelect_IGESTypeForm::Value, "Returns the signature for IGES, 'mmm nnn' or 'mmm' according creation choice (Type & Form or Type only)", py::arg("ent"), py::arg("model"));
cls_IGESSelect_IGESTypeForm.def_static("get_type_name_", (const char * (*)()) &IGESSelect_IGESTypeForm::get_type_name, "None");
cls_IGESSelect_IGESTypeForm.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_IGESTypeForm::get_type_descriptor, "None");
cls_IGESSelect_IGESTypeForm.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_IGESTypeForm::*)() const) &IGESSelect_IGESTypeForm::DynamicType, "None");

// CLASS: IGESSELECT_REBUILDDRAWINGS
py::class_<IGESSelect_RebuildDrawings, opencascade::handle<IGESSelect_RebuildDrawings>, IGESSelect_ModelModifier> cls_IGESSelect_RebuildDrawings(mod, "IGESSelect_RebuildDrawings", "Rebuilds Drawings which were bypassed to produce new models. If a set of entities, all put into a same IGESModel, were attached to a same Drawing in the starting Model, this Modifier rebuilds the original Drawing, but only with the transferred entities. This includes that all its views are kept too, but empty; and annotations are not kept. Drawing Name is renewed.");

// Constructors
cls_IGESSelect_RebuildDrawings.def(py::init<>());

// Methods
cls_IGESSelect_RebuildDrawings.def("Performing", (void (IGESSelect_RebuildDrawings::*)(IFSelect_ContextModif &, const opencascade::handle<IGESData_IGESModel> &, Interface_CopyTool &) const) &IGESSelect_RebuildDrawings::Performing, "Specific action : Rebuilds the original Drawings", py::arg("ctx"), py::arg("target"), py::arg("TC"));
cls_IGESSelect_RebuildDrawings.def("Label", (TCollection_AsciiString (IGESSelect_RebuildDrawings::*)() const) &IGESSelect_RebuildDrawings::Label, "Returns a text which is 'Rebuild Drawings'");
cls_IGESSelect_RebuildDrawings.def_static("get_type_name_", (const char * (*)()) &IGESSelect_RebuildDrawings::get_type_name, "None");
cls_IGESSelect_RebuildDrawings.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_RebuildDrawings::get_type_descriptor, "None");
cls_IGESSelect_RebuildDrawings.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_RebuildDrawings::*)() const) &IGESSelect_RebuildDrawings::DynamicType, "None");

// CLASS: IGESSELECT_REBUILDGROUPS
py::class_<IGESSelect_RebuildGroups, opencascade::handle<IGESSelect_RebuildGroups>, IGESSelect_ModelModifier> cls_IGESSelect_RebuildGroups(mod, "IGESSelect_RebuildGroups", "Rebuilds Groups which were bypassed to produce new models. If a set of entities, all put into a same IGESModel, were part of a same Group in the starting Model, this Modifier rebuilds the original group, but only with the transferred entities. The distinctions (Ordered or not, 'WhithoutBackP' or not) are renewed, also the name of the group.");

// Constructors
cls_IGESSelect_RebuildGroups.def(py::init<>());

// Methods
cls_IGESSelect_RebuildGroups.def("Performing", (void (IGESSelect_RebuildGroups::*)(IFSelect_ContextModif &, const opencascade::handle<IGESData_IGESModel> &, Interface_CopyTool &) const) &IGESSelect_RebuildGroups::Performing, "Specific action : Rebuilds the original groups", py::arg("ctx"), py::arg("target"), py::arg("TC"));
cls_IGESSelect_RebuildGroups.def("Label", (TCollection_AsciiString (IGESSelect_RebuildGroups::*)() const) &IGESSelect_RebuildGroups::Label, "Returns a text which is 'Rebuild Groups'");
cls_IGESSelect_RebuildGroups.def_static("get_type_name_", (const char * (*)()) &IGESSelect_RebuildGroups::get_type_name, "None");
cls_IGESSelect_RebuildGroups.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_RebuildGroups::get_type_descriptor, "None");
cls_IGESSelect_RebuildGroups.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_RebuildGroups::*)() const) &IGESSelect_RebuildGroups::DynamicType, "None");

// CLASS: IGESSELECT_REMOVECURVES
py::class_<IGESSelect_RemoveCurves, opencascade::handle<IGESSelect_RemoveCurves>, IGESSelect_ModelModifier> cls_IGESSelect_RemoveCurves(mod, "IGESSelect_RemoveCurves", "Removes Curves UV or 3D (not both !) from Faces, those designated by the Selection. No Selection means all the file");

// Constructors
cls_IGESSelect_RemoveCurves.def(py::init<const Standard_Boolean>(), py::arg("UV"));

// Methods
cls_IGESSelect_RemoveCurves.def("Performing", (void (IGESSelect_RemoveCurves::*)(IFSelect_ContextModif &, const opencascade::handle<IGESData_IGESModel> &, Interface_CopyTool &) const) &IGESSelect_RemoveCurves::Performing, "Specific action : Removes the Curves", py::arg("ctx"), py::arg("target"), py::arg("TC"));
cls_IGESSelect_RemoveCurves.def("Label", (TCollection_AsciiString (IGESSelect_RemoveCurves::*)() const) &IGESSelect_RemoveCurves::Label, "Returns a text which is 'Remove Curves UV on Face' or 'Remove Curves 3D on Face'");
cls_IGESSelect_RemoveCurves.def_static("get_type_name_", (const char * (*)()) &IGESSelect_RemoveCurves::get_type_name, "None");
cls_IGESSelect_RemoveCurves.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_RemoveCurves::get_type_descriptor, "None");
cls_IGESSelect_RemoveCurves.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_RemoveCurves::*)() const) &IGESSelect_RemoveCurves::DynamicType, "None");

// CLASS: IGESSELECT_SELECTBASICGEOM
py::class_<IGESSelect_SelectBasicGeom, opencascade::handle<IGESSelect_SelectBasicGeom>, IFSelect_SelectExplore> cls_IGESSelect_SelectBasicGeom(mod, "IGESSelect_SelectBasicGeom", "This selection returns the basic geometric elements contained in an IGES Entity Intended to run a 'quick' transfer. I.E. : - for a Group, considers its Elements - for a Trimmed or Bounded Surface or a Face (BREP), considers the 3D curves of each of its loops - for a Plane (108), considers its Bounding Curve - for a Curve itself, takes it");

// Constructors
cls_IGESSelect_SelectBasicGeom.def(py::init<const Standard_Integer>(), py::arg("mode"));

// Methods
// cls_IGESSelect_SelectBasicGeom.def("CurvesOnly", (Standard_Boolean (IGESSelect_SelectBasicGeom::*)() const) &IGESSelect_SelectBasicGeom::CurvesOnly, "None");
cls_IGESSelect_SelectBasicGeom.def("Explore", (Standard_Boolean (IGESSelect_SelectBasicGeom::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_Graph &, Interface_EntityIterator &) const) &IGESSelect_SelectBasicGeom::Explore, "Explores an entity, to take its contained Curves 3d Works recursively", py::arg("level"), py::arg("ent"), py::arg("G"), py::arg("explored"));
cls_IGESSelect_SelectBasicGeom.def("ExploreLabel", (TCollection_AsciiString (IGESSelect_SelectBasicGeom::*)() const) &IGESSelect_SelectBasicGeom::ExploreLabel, "Returns a text defining the criterium : 'Curves 3d' or 'Basic Geometry'");
cls_IGESSelect_SelectBasicGeom.def_static("SubCurves_", (Standard_Boolean (*)(const opencascade::handle<IGESData_IGESEntity> &, Interface_EntityIterator &)) &IGESSelect_SelectBasicGeom::SubCurves, "This method can be called from everywhere to get the curves as sub-elements of a given curve : CompositeCurve : explored lists its subs + returns True Any Curve : explored is not filled but returned is True Other : returned is False", py::arg("ent"), py::arg("explored"));
cls_IGESSelect_SelectBasicGeom.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SelectBasicGeom::get_type_name, "None");
cls_IGESSelect_SelectBasicGeom.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SelectBasicGeom::get_type_descriptor, "None");
cls_IGESSelect_SelectBasicGeom.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SelectBasicGeom::*)() const) &IGESSelect_SelectBasicGeom::DynamicType, "None");

// CLASS: IGESSELECT_SELECTBYPASSGROUP
py::class_<IGESSelect_SelectBypassGroup, opencascade::handle<IGESSelect_SelectBypassGroup>, IFSelect_SelectExplore> cls_IGESSelect_SelectBypassGroup(mod, "IGESSelect_SelectBypassGroup", "Selects a list built as follows : Groups are entities type 402, forms 1,7,14,15 (Group, Ordered or not, 'WithoutBackPointer' or not)");

// Constructors
cls_IGESSelect_SelectBypassGroup.def(py::init<>());
cls_IGESSelect_SelectBypassGroup.def(py::init<const Standard_Integer>(), py::arg("level"));

// Methods
cls_IGESSelect_SelectBypassGroup.def("Explore", (Standard_Boolean (IGESSelect_SelectBypassGroup::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_Graph &, Interface_EntityIterator &) const) &IGESSelect_SelectBypassGroup::Explore, "Explores an entity : for a Group, gives its elements Else, takes the entity itself", py::arg("level"), py::arg("ent"), py::arg("G"), py::arg("explored"));
cls_IGESSelect_SelectBypassGroup.def("ExploreLabel", (TCollection_AsciiString (IGESSelect_SelectBypassGroup::*)() const) &IGESSelect_SelectBypassGroup::ExploreLabel, "Returns a text defining the criterium : 'Content of Group'");
cls_IGESSelect_SelectBypassGroup.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SelectBypassGroup::get_type_name, "None");
cls_IGESSelect_SelectBypassGroup.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SelectBypassGroup::get_type_descriptor, "None");
cls_IGESSelect_SelectBypassGroup.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SelectBypassGroup::*)() const) &IGESSelect_SelectBypassGroup::DynamicType, "None");

// CLASS: IGESSELECT_SELECTBYPASSSUBFIGURE
py::class_<IGESSelect_SelectBypassSubfigure, opencascade::handle<IGESSelect_SelectBypassSubfigure>, IFSelect_SelectExplore> cls_IGESSelect_SelectBypassSubfigure(mod, "IGESSelect_SelectBypassSubfigure", "Selects a list built as follows : Subfigures correspond to * Definition (basic : type 308, or Network : type 320) * Instance (Singular : type 408, or Network : 420, or patterns : 412,414)");

// Constructors
cls_IGESSelect_SelectBypassSubfigure.def(py::init<>());
cls_IGESSelect_SelectBypassSubfigure.def(py::init<const Standard_Integer>(), py::arg("level"));

// Methods
cls_IGESSelect_SelectBypassSubfigure.def("Explore", (Standard_Boolean (IGESSelect_SelectBypassSubfigure::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_Graph &, Interface_EntityIterator &) const) &IGESSelect_SelectBypassSubfigure::Explore, "Explores an entity : for a Subfigure, gives its elements Else, takes the entity itself", py::arg("level"), py::arg("ent"), py::arg("G"), py::arg("explored"));
cls_IGESSelect_SelectBypassSubfigure.def("ExploreLabel", (TCollection_AsciiString (IGESSelect_SelectBypassSubfigure::*)() const) &IGESSelect_SelectBypassSubfigure::ExploreLabel, "Returns a text defining the criterium : 'Content of Subfigure'");
cls_IGESSelect_SelectBypassSubfigure.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SelectBypassSubfigure::get_type_name, "None");
cls_IGESSelect_SelectBypassSubfigure.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SelectBypassSubfigure::get_type_descriptor, "None");
cls_IGESSelect_SelectBypassSubfigure.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SelectBypassSubfigure::*)() const) &IGESSelect_SelectBypassSubfigure::DynamicType, "None");

// CLASS: IGESSELECT_SELECTDRAWINGFROM
py::class_<IGESSelect_SelectDrawingFrom, opencascade::handle<IGESSelect_SelectDrawingFrom>, IFSelect_SelectDeduct> cls_IGESSelect_SelectDrawingFrom(mod, "IGESSelect_SelectDrawingFrom", "This selection gets the Drawings attached to its input IGES entities. They are read through thr Single Views, referenced in Directory Parts of the entities");

// Constructors
cls_IGESSelect_SelectDrawingFrom.def(py::init<>());

// Methods
cls_IGESSelect_SelectDrawingFrom.def("RootResult", (Interface_EntityIterator (IGESSelect_SelectDrawingFrom::*)(const Interface_Graph &) const) &IGESSelect_SelectDrawingFrom::RootResult, "Selects the Drawings attached (through Single Views in Directory Part) to input entities", py::arg("G"));
cls_IGESSelect_SelectDrawingFrom.def("Label", (TCollection_AsciiString (IGESSelect_SelectDrawingFrom::*)() const) &IGESSelect_SelectDrawingFrom::Label, "Returns the label, with is 'Drawings attached'");
cls_IGESSelect_SelectDrawingFrom.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SelectDrawingFrom::get_type_name, "None");
cls_IGESSelect_SelectDrawingFrom.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SelectDrawingFrom::get_type_descriptor, "None");
cls_IGESSelect_SelectDrawingFrom.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SelectDrawingFrom::*)() const) &IGESSelect_SelectDrawingFrom::DynamicType, "None");

// CLASS: IGESSELECT_SELECTFACES
py::class_<IGESSelect_SelectFaces, opencascade::handle<IGESSelect_SelectFaces>, IFSelect_SelectExplore> cls_IGESSelect_SelectFaces(mod, "IGESSelect_SelectFaces", "This selection returns the faces contained in an IGES Entity or itself if it is a Face Face means : - Face (510) of a ManifoldSolidBrep - TrimmedSurface (144) - BoundedSurface (143) - Plane with a Bounding Curve (108, form not 0) - Also, any Surface which is not in a TrimmedSurface, a BoundedSurface, or a Face (FREE Surface) -> i.e. a Face for which Natural Bounds will be considered");

// Constructors
cls_IGESSelect_SelectFaces.def(py::init<>());

// Methods
cls_IGESSelect_SelectFaces.def("Explore", (Standard_Boolean (IGESSelect_SelectFaces::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_Graph &, Interface_EntityIterator &) const) &IGESSelect_SelectFaces::Explore, "Explores an entity, to take its faces Works recursively", py::arg("level"), py::arg("ent"), py::arg("G"), py::arg("explored"));
cls_IGESSelect_SelectFaces.def("ExploreLabel", (TCollection_AsciiString (IGESSelect_SelectFaces::*)() const) &IGESSelect_SelectFaces::ExploreLabel, "Returns a text defining the criterium : 'Faces'");
cls_IGESSelect_SelectFaces.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SelectFaces::get_type_name, "None");
cls_IGESSelect_SelectFaces.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SelectFaces::get_type_descriptor, "None");
cls_IGESSelect_SelectFaces.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SelectFaces::*)() const) &IGESSelect_SelectFaces::DynamicType, "None");

// CLASS: IGESSELECT_SELECTFROMDRAWING
py::class_<IGESSelect_SelectFromDrawing, opencascade::handle<IGESSelect_SelectFromDrawing>, IFSelect_SelectDeduct> cls_IGESSelect_SelectFromDrawing(mod, "IGESSelect_SelectFromDrawing", "This selection gets in all the model, the entities which are attached to the drawing(s) given as input. This includes : - Drawing Frame (Annotations directky referenced by Drawings) - Entities attached to the single Views referenced by Drawings");

// Constructors
cls_IGESSelect_SelectFromDrawing.def(py::init<>());

// Methods
cls_IGESSelect_SelectFromDrawing.def("RootResult", (Interface_EntityIterator (IGESSelect_SelectFromDrawing::*)(const Interface_Graph &) const) &IGESSelect_SelectFromDrawing::RootResult, "Selects the Entities which are attached to the Drawing(s) present in the Input", py::arg("G"));
cls_IGESSelect_SelectFromDrawing.def("Label", (TCollection_AsciiString (IGESSelect_SelectFromDrawing::*)() const) &IGESSelect_SelectFromDrawing::Label, "Returns the label, with is 'Entities attached to Drawing'");
cls_IGESSelect_SelectFromDrawing.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SelectFromDrawing::get_type_name, "None");
cls_IGESSelect_SelectFromDrawing.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SelectFromDrawing::get_type_descriptor, "None");
cls_IGESSelect_SelectFromDrawing.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SelectFromDrawing::*)() const) &IGESSelect_SelectFromDrawing::DynamicType, "None");

// CLASS: IGESSELECT_SELECTFROMSINGLEVIEW
py::class_<IGESSelect_SelectFromSingleView, opencascade::handle<IGESSelect_SelectFromSingleView>, IFSelect_SelectDeduct> cls_IGESSelect_SelectFromSingleView(mod, "IGESSelect_SelectFromSingleView", "This selection gets in all the model, the entities which are attached to the views given as input. Only Single Views are considered. This information is kept from Directory Part (View Item).");

// Constructors
cls_IGESSelect_SelectFromSingleView.def(py::init<>());

// Methods
cls_IGESSelect_SelectFromSingleView.def("RootResult", (Interface_EntityIterator (IGESSelect_SelectFromSingleView::*)(const Interface_Graph &) const) &IGESSelect_SelectFromSingleView::RootResult, "Selects the Entities which are attached to the Single View(s) present in the Input", py::arg("G"));
cls_IGESSelect_SelectFromSingleView.def("Label", (TCollection_AsciiString (IGESSelect_SelectFromSingleView::*)() const) &IGESSelect_SelectFromSingleView::Label, "Returns the label, with is 'Entities attached to single View'");
cls_IGESSelect_SelectFromSingleView.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SelectFromSingleView::get_type_name, "None");
cls_IGESSelect_SelectFromSingleView.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SelectFromSingleView::get_type_descriptor, "None");
cls_IGESSelect_SelectFromSingleView.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SelectFromSingleView::*)() const) &IGESSelect_SelectFromSingleView::DynamicType, "None");

// CLASS: IGESSELECT_SELECTLEVELNUMBER
py::class_<IGESSelect_SelectLevelNumber, opencascade::handle<IGESSelect_SelectLevelNumber>, IFSelect_SelectExtract> cls_IGESSelect_SelectLevelNumber(mod, "IGESSelect_SelectLevelNumber", "This selection looks at Level Number of IGES Entities : it considers items attached, either to a single level with a given value, or to a level list which contains this value");

// Constructors
cls_IGESSelect_SelectLevelNumber.def(py::init<>());

// Methods
cls_IGESSelect_SelectLevelNumber.def("SetLevelNumber", (void (IGESSelect_SelectLevelNumber::*)(const opencascade::handle<IFSelect_IntParam> &)) &IGESSelect_SelectLevelNumber::SetLevelNumber, "Sets a Parameter as Level criterium", py::arg("levnum"));
cls_IGESSelect_SelectLevelNumber.def("LevelNumber", (opencascade::handle<IFSelect_IntParam> (IGESSelect_SelectLevelNumber::*)() const) &IGESSelect_SelectLevelNumber::LevelNumber, "Returns the Level criterium. NullHandle if not yet set (interpreted as Level = 0 : no level number attached)");
cls_IGESSelect_SelectLevelNumber.def("Sort", (Standard_Boolean (IGESSelect_SelectLevelNumber::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IGESSelect_SelectLevelNumber::Sort, "Returns True if <ent> is an IGES Entity with Level Number admits the criterium (= value if single level, or one of the attached level numbers = value if level list)", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_IGESSelect_SelectLevelNumber.def("ExtractLabel", (TCollection_AsciiString (IGESSelect_SelectLevelNumber::*)() const) &IGESSelect_SelectLevelNumber::ExtractLabel, "Returns the Selection criterium : 'IGES Entity, Level Number admits <nn>' (if nn > 0) or 'IGES Entity attached to no Level' (if nn = 0)");
cls_IGESSelect_SelectLevelNumber.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SelectLevelNumber::get_type_name, "None");
cls_IGESSelect_SelectLevelNumber.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SelectLevelNumber::get_type_descriptor, "None");
cls_IGESSelect_SelectLevelNumber.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SelectLevelNumber::*)() const) &IGESSelect_SelectLevelNumber::DynamicType, "None");

// CLASS: IGESSELECT_SELECTNAME
py::class_<IGESSelect_SelectName, opencascade::handle<IGESSelect_SelectName>, IFSelect_SelectExtract> cls_IGESSelect_SelectName(mod, "IGESSelect_SelectName", "Selects Entities which have a given name. Consider Property Name if present, else Short Label, but not the Subscript Number First version : keeps exact name Later : regular expression");

// Constructors
cls_IGESSelect_SelectName.def(py::init<>());

// Methods
cls_IGESSelect_SelectName.def("Sort", (Standard_Boolean (IGESSelect_SelectName::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IGESSelect_SelectName::Sort, "Returns True if Name of Entity complies with Name Filter", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_IGESSelect_SelectName.def("SetName", (void (IGESSelect_SelectName::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESSelect_SelectName::SetName, "Sets a Name as a criterium : IGES Entities which have this name are kept (without regular expression, there should be at most one). <name> can be regarded as a Text Parameter", py::arg("name"));
cls_IGESSelect_SelectName.def("Name", (opencascade::handle<TCollection_HAsciiString> (IGESSelect_SelectName::*)() const) &IGESSelect_SelectName::Name, "Returns the Name used as Filter");
cls_IGESSelect_SelectName.def("ExtractLabel", (TCollection_AsciiString (IGESSelect_SelectName::*)() const) &IGESSelect_SelectName::ExtractLabel, "Returns the Selection criterium : 'IGES Entity, Name : <name>'");
cls_IGESSelect_SelectName.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SelectName::get_type_name, "None");
cls_IGESSelect_SelectName.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SelectName::get_type_descriptor, "None");
cls_IGESSelect_SelectName.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SelectName::*)() const) &IGESSelect_SelectName::DynamicType, "None");

// CLASS: IGESSELECT_SELECTPCURVES
py::class_<IGESSelect_SelectPCurves, opencascade::handle<IGESSelect_SelectPCurves>, IFSelect_SelectExplore> cls_IGESSelect_SelectPCurves(mod, "IGESSelect_SelectPCurves", "This Selection returns the pcurves which lie on a face In two modes : global (i.e. a CompositeCurve is not explored) or basic (all the basic curves are listed)");

// Constructors
cls_IGESSelect_SelectPCurves.def(py::init<const Standard_Boolean>(), py::arg("basic"));

// Methods
cls_IGESSelect_SelectPCurves.def("Explore", (Standard_Boolean (IGESSelect_SelectPCurves::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_Graph &, Interface_EntityIterator &) const) &IGESSelect_SelectPCurves::Explore, "Explores an entity, to take its contained PCurves An independant curve is IGNORED : only faces are explored", py::arg("level"), py::arg("ent"), py::arg("G"), py::arg("explored"));
cls_IGESSelect_SelectPCurves.def("ExploreLabel", (TCollection_AsciiString (IGESSelect_SelectPCurves::*)() const) &IGESSelect_SelectPCurves::ExploreLabel, "Returns a text defining the criterium : 'Basic PCurves' or 'Global PCurves'");
cls_IGESSelect_SelectPCurves.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SelectPCurves::get_type_name, "None");
cls_IGESSelect_SelectPCurves.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SelectPCurves::get_type_descriptor, "None");
cls_IGESSelect_SelectPCurves.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SelectPCurves::*)() const) &IGESSelect_SelectPCurves::DynamicType, "None");

// CLASS: IGESSELECT_SELECTSINGLEVIEWFROM
py::class_<IGESSelect_SelectSingleViewFrom, opencascade::handle<IGESSelect_SelectSingleViewFrom>, IFSelect_SelectDeduct> cls_IGESSelect_SelectSingleViewFrom(mod, "IGESSelect_SelectSingleViewFrom", "This selection gets the Single Views attached to its input IGES entities. Single Views themselves or Drawings as passed as such (Drawings, for their Annotations)");

// Constructors
cls_IGESSelect_SelectSingleViewFrom.def(py::init<>());

// Methods
cls_IGESSelect_SelectSingleViewFrom.def("RootResult", (Interface_EntityIterator (IGESSelect_SelectSingleViewFrom::*)(const Interface_Graph &) const) &IGESSelect_SelectSingleViewFrom::RootResult, "Selects the Single Views attached (in Directory Part) to input entities", py::arg("G"));
cls_IGESSelect_SelectSingleViewFrom.def("Label", (TCollection_AsciiString (IGESSelect_SelectSingleViewFrom::*)() const) &IGESSelect_SelectSingleViewFrom::Label, "Returns the label, with is 'Single Views attached'");
cls_IGESSelect_SelectSingleViewFrom.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SelectSingleViewFrom::get_type_name, "None");
cls_IGESSelect_SelectSingleViewFrom.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SelectSingleViewFrom::get_type_descriptor, "None");
cls_IGESSelect_SelectSingleViewFrom.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SelectSingleViewFrom::*)() const) &IGESSelect_SelectSingleViewFrom::DynamicType, "None");

// CLASS: IGESSELECT_SELECTSUBORDINATE
py::class_<IGESSelect_SelectSubordinate, opencascade::handle<IGESSelect_SelectSubordinate>, IFSelect_SelectExtract> cls_IGESSelect_SelectSubordinate(mod, "IGESSelect_SelectSubordinate", "This selections uses Subordinate Status as sort criterium It is an integer number which can be : 0 Independant 1 Physically Dependant 2 Logically Dependant 3 Both (recorded) + to sort : 4 : 1 or 3 -> at least Physically 5 : 2 or 3 -> at least Logically 6 : 1 or 2 or 3 -> any kind of dependance (corresponds to 0 reversed)");

// Constructors
cls_IGESSelect_SelectSubordinate.def(py::init<const Standard_Integer>(), py::arg("status"));

// Methods
cls_IGESSelect_SelectSubordinate.def("Status", (Standard_Integer (IGESSelect_SelectSubordinate::*)() const) &IGESSelect_SelectSubordinate::Status, "Returns the status used for sorting");
cls_IGESSelect_SelectSubordinate.def("Sort", (Standard_Boolean (IGESSelect_SelectSubordinate::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IGESSelect_SelectSubordinate::Sort, "Returns True if <ent> is an IGES Entity with Subordinate Status matching the criterium", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_IGESSelect_SelectSubordinate.def("ExtractLabel", (TCollection_AsciiString (IGESSelect_SelectSubordinate::*)() const) &IGESSelect_SelectSubordinate::ExtractLabel, "Returns the Selection criterium : 'IGES Entity, Independant' etc...");
cls_IGESSelect_SelectSubordinate.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SelectSubordinate::get_type_name, "None");
cls_IGESSelect_SelectSubordinate.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SelectSubordinate::get_type_descriptor, "None");
cls_IGESSelect_SelectSubordinate.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SelectSubordinate::*)() const) &IGESSelect_SelectSubordinate::DynamicType, "None");

// CLASS: IGESSELECT_SELECTVISIBLESTATUS
py::class_<IGESSelect_SelectVisibleStatus, opencascade::handle<IGESSelect_SelectVisibleStatus>, IFSelect_SelectExtract> cls_IGESSelect_SelectVisibleStatus(mod, "IGESSelect_SelectVisibleStatus", "This selection looks at Blank Status of IGES Entities Direct selection keeps Visible Entities (Blank = 0), Reverse selection keeps Blanked Entities (Blank = 1)");

// Constructors
cls_IGESSelect_SelectVisibleStatus.def(py::init<>());

// Methods
cls_IGESSelect_SelectVisibleStatus.def("Sort", (Standard_Boolean (IGESSelect_SelectVisibleStatus::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IGESSelect_SelectVisibleStatus::Sort, "Returns True if <ent> is an IGES Entity with Blank Status = 0", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_IGESSelect_SelectVisibleStatus.def("ExtractLabel", (TCollection_AsciiString (IGESSelect_SelectVisibleStatus::*)() const) &IGESSelect_SelectVisibleStatus::ExtractLabel, "Returns the Selection criterium : 'IGES Entity, Status Visible'");
cls_IGESSelect_SelectVisibleStatus.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SelectVisibleStatus::get_type_name, "None");
cls_IGESSelect_SelectVisibleStatus.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SelectVisibleStatus::get_type_descriptor, "None");
cls_IGESSelect_SelectVisibleStatus.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SelectVisibleStatus::*)() const) &IGESSelect_SelectVisibleStatus::DynamicType, "None");

// CLASS: IGESSELECT_SETGLOBALPARAMETER
py::class_<IGESSelect_SetGlobalParameter, opencascade::handle<IGESSelect_SetGlobalParameter>, IGESSelect_ModelModifier> cls_IGESSelect_SetGlobalParameter(mod, "IGESSelect_SetGlobalParameter", "Sets a Global (Header) Parameter to a new value, directly given Controls the form of the parameter (Integer, Real, String with such or such form), but not the consistence of the new value regarding the rest of the file.");

// Constructors
cls_IGESSelect_SetGlobalParameter.def(py::init<const Standard_Integer>(), py::arg("numpar"));

// Methods
cls_IGESSelect_SetGlobalParameter.def("GlobalNumber", (Standard_Integer (IGESSelect_SetGlobalParameter::*)() const) &IGESSelect_SetGlobalParameter::GlobalNumber, "Returns the global parameter number to which this modifiers applies");
cls_IGESSelect_SetGlobalParameter.def("SetValue", (void (IGESSelect_SetGlobalParameter::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESSelect_SetGlobalParameter::SetValue, "Sets a Text Parameter for the new value", py::arg("text"));
cls_IGESSelect_SetGlobalParameter.def("Value", (opencascade::handle<TCollection_HAsciiString> (IGESSelect_SetGlobalParameter::*)() const) &IGESSelect_SetGlobalParameter::Value, "Returns the value to set to the global parameter (Text Param)");
cls_IGESSelect_SetGlobalParameter.def("Performing", (void (IGESSelect_SetGlobalParameter::*)(IFSelect_ContextModif &, const opencascade::handle<IGESData_IGESModel> &, Interface_CopyTool &) const) &IGESSelect_SetGlobalParameter::Performing, "Specific action : only <target> is used : the form of the new value is checked regarding the parameter number (given at creation time).", py::arg("ctx"), py::arg("target"), py::arg("TC"));
cls_IGESSelect_SetGlobalParameter.def("Label", (TCollection_AsciiString (IGESSelect_SetGlobalParameter::*)() const) &IGESSelect_SetGlobalParameter::Label, "Returns a text which is 'Sets Global Parameter <numpar> to <new value>'");
cls_IGESSelect_SetGlobalParameter.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SetGlobalParameter::get_type_name, "None");
cls_IGESSelect_SetGlobalParameter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SetGlobalParameter::get_type_descriptor, "None");
cls_IGESSelect_SetGlobalParameter.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SetGlobalParameter::*)() const) &IGESSelect_SetGlobalParameter::DynamicType, "None");

// CLASS: IGESSELECT_SETLABEL
py::class_<IGESSelect_SetLabel, opencascade::handle<IGESSelect_SetLabel>, IGESSelect_ModelModifier> cls_IGESSelect_SetLabel(mod, "IGESSelect_SetLabel", "Sets/Clears Short Label of Entities, those designated by the Selection. No Selection means all the file");

// Constructors
cls_IGESSelect_SetLabel.def(py::init<const Standard_Integer, const Standard_Boolean>(), py::arg("mode"), py::arg("enforce"));

// Methods
cls_IGESSelect_SetLabel.def("Performing", (void (IGESSelect_SetLabel::*)(IFSelect_ContextModif &, const opencascade::handle<IGESData_IGESModel> &, Interface_CopyTool &) const) &IGESSelect_SetLabel::Performing, "Specific action : Sets or Clears the Label", py::arg("ctx"), py::arg("target"), py::arg("TC"));
cls_IGESSelect_SetLabel.def("Label", (TCollection_AsciiString (IGESSelect_SetLabel::*)() const) &IGESSelect_SetLabel::Label, "Returns a text which is 'Clear Short Label' or 'Set Label to DE' With possible additional information ' (enforced)'");
cls_IGESSelect_SetLabel.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SetLabel::get_type_name, "None");
cls_IGESSelect_SetLabel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SetLabel::get_type_descriptor, "None");
cls_IGESSelect_SetLabel.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SetLabel::*)() const) &IGESSelect_SetLabel::DynamicType, "None");

// CLASS: IGESSELECT_SETVERSION5
py::class_<IGESSelect_SetVersion5, opencascade::handle<IGESSelect_SetVersion5>, IGESSelect_ModelModifier> cls_IGESSelect_SetVersion5(mod, "IGESSelect_SetVersion5", "Sets IGES Version (coded in global parameter 23) to be at least IGES 5.1 . If it is older, it is set to IGES 5.1, and LastChangeDate (new Global n0 25) is added (current time) Else, it does nothing (i.e. changes neither IGES Version nor LastChangeDate)");

// Constructors
cls_IGESSelect_SetVersion5.def(py::init<>());

// Methods
cls_IGESSelect_SetVersion5.def("Performing", (void (IGESSelect_SetVersion5::*)(IFSelect_ContextModif &, const opencascade::handle<IGESData_IGESModel> &, Interface_CopyTool &) const) &IGESSelect_SetVersion5::Performing, "Specific action : only <target> is used : IGES Version (coded) is upgraded to 5.1 if it is older, and it this case the new global parameter 25 (LastChangeDate) is set to current time", py::arg("ctx"), py::arg("target"), py::arg("TC"));
cls_IGESSelect_SetVersion5.def("Label", (TCollection_AsciiString (IGESSelect_SetVersion5::*)() const) &IGESSelect_SetVersion5::Label, "Returns a text which is 'Update IGES Version to 5.1'");
cls_IGESSelect_SetVersion5.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SetVersion5::get_type_name, "None");
cls_IGESSelect_SetVersion5.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SetVersion5::get_type_descriptor, "None");
cls_IGESSelect_SetVersion5.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SetVersion5::*)() const) &IGESSelect_SetVersion5::DynamicType, "None");

// CLASS: IGESSELECT_SIGNCOLOR
py::class_<IGESSelect_SignColor, opencascade::handle<IGESSelect_SignColor>, IFSelect_Signature> cls_IGESSelect_SignColor(mod, "IGESSelect_SignColor", "Gives Color attached to an entity Several forms are possible, according to <mode> 1 : number : 'Dnn' for entity, 'Snn' for standard, '(none)' for 0 2 : name : Of standard color, or of the color entity, or '(none)' (if the color entity has no name, its label is taken) 3 : RGB values, form R:nn,G:nn,B:nn 4 : RED value : an integer 5 : GREEN value : an integer 6 : BLUE value : an integer Other computable values can be added if needed : CMY values, Percentages for Hue, Lightness, Saturation");

// Constructors
cls_IGESSelect_SignColor.def(py::init<const Standard_Integer>(), py::arg("mode"));

// Methods
cls_IGESSelect_SignColor.def("Value", (Standard_CString (IGESSelect_SignColor::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IGESSelect_SignColor::Value, "Returns the value (see above)", py::arg("ent"), py::arg("model"));
cls_IGESSelect_SignColor.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SignColor::get_type_name, "None");
cls_IGESSelect_SignColor.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SignColor::get_type_descriptor, "None");
cls_IGESSelect_SignColor.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SignColor::*)() const) &IGESSelect_SignColor::DynamicType, "None");

// CLASS: IGESSELECT_SIGNLEVELNUMBER
py::class_<IGESSelect_SignLevelNumber, opencascade::handle<IGESSelect_SignLevelNumber>, IFSelect_Signature> cls_IGESSelect_SignLevelNumber(mod, "IGESSelect_SignLevelNumber", "Gives D.E. Level Number under two possible forms : * for counter : 'LEVEL nnnnnnn', ' NO LEVEL', ' LEVEL LIST' * for selection : '/nnn/', '/0/', '/1/2/nnn/'");

// Constructors
cls_IGESSelect_SignLevelNumber.def(py::init<const Standard_Boolean>(), py::arg("countmode"));

// Methods
cls_IGESSelect_SignLevelNumber.def("Value", (Standard_CString (IGESSelect_SignLevelNumber::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IGESSelect_SignLevelNumber::Value, "Returns the value (see above)", py::arg("ent"), py::arg("model"));
cls_IGESSelect_SignLevelNumber.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SignLevelNumber::get_type_name, "None");
cls_IGESSelect_SignLevelNumber.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SignLevelNumber::get_type_descriptor, "None");
cls_IGESSelect_SignLevelNumber.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SignLevelNumber::*)() const) &IGESSelect_SignLevelNumber::DynamicType, "None");

// CLASS: IGESSELECT_SIGNSTATUS
py::class_<IGESSelect_SignStatus, opencascade::handle<IGESSelect_SignStatus>, IFSelect_Signature> cls_IGESSelect_SignStatus(mod, "IGESSelect_SignStatus", "Gives D.E. Status under the form i,j,k,l (4 figures) i for BlankStatus j for SubordinateStatus k for UseFlag l for Hierarchy");

// Constructors
cls_IGESSelect_SignStatus.def(py::init<>());

// Methods
cls_IGESSelect_SignStatus.def("Value", (Standard_CString (IGESSelect_SignStatus::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IGESSelect_SignStatus::Value, "Returns the value (see above)", py::arg("ent"), py::arg("model"));
cls_IGESSelect_SignStatus.def("Matches", (Standard_Boolean (IGESSelect_SignStatus::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &, const TCollection_AsciiString &, const Standard_Boolean) const) &IGESSelect_SignStatus::Matches, "Performs the match rule (see above)", py::arg("ent"), py::arg("model"), py::arg("text"), py::arg("exact"));
cls_IGESSelect_SignStatus.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SignStatus::get_type_name, "None");
cls_IGESSelect_SignStatus.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SignStatus::get_type_descriptor, "None");
cls_IGESSelect_SignStatus.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SignStatus::*)() const) &IGESSelect_SignStatus::DynamicType, "None");

// CLASS: IGESSELECT_SPLINETOBSPLINE
py::class_<IGESSelect_SplineToBSpline, opencascade::handle<IGESSelect_SplineToBSpline>, IFSelect_Transformer> cls_IGESSelect_SplineToBSpline(mod, "IGESSelect_SplineToBSpline", "This type of Transformer allows to convert Spline Curves (IGES type 112) and Surfaces (IGES Type 126) to BSpline Curves (IGES type 114) and Surfac (IGES Type 128). All other entities are rebuilt as identical but on the basis of this conversion.");

// Constructors
cls_IGESSelect_SplineToBSpline.def(py::init<const Standard_Boolean>(), py::arg("tryC2"));

// Methods
cls_IGESSelect_SplineToBSpline.def("OptionTryC2", (Standard_Boolean (IGESSelect_SplineToBSpline::*)() const) &IGESSelect_SplineToBSpline::OptionTryC2, "Returns the option TryC2 given at creation time");
cls_IGESSelect_SplineToBSpline.def("Perform", (Standard_Boolean (IGESSelect_SplineToBSpline::*)(const Interface_Graph &, const opencascade::handle<Interface_Protocol> &, Interface_CheckIterator &, opencascade::handle<Interface_InterfaceModel> &)) &IGESSelect_SplineToBSpline::Perform, "Performs the transformation, if there is at least one Spline Curve (112) or Surface (126). Does nothing if there is none.", py::arg("G"), py::arg("protocol"), py::arg("checks"), py::arg("newmod"));
cls_IGESSelect_SplineToBSpline.def("Updated", (Standard_Boolean (IGESSelect_SplineToBSpline::*)(const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &) const) &IGESSelect_SplineToBSpline::Updated, "Returns the transformed entities. If original data contained no Spline Curve or Surface, the result is identity : <entto> = <entfrom> Else, the copied counterpart is returned : for a Spline Curve or Surface, it is a converted BSpline Curve or Surface. Else, it is the result of general service Copy (rebuilt as necessary by BSPlines replacing Splines).", py::arg("entfrom"), py::arg("entto"));
cls_IGESSelect_SplineToBSpline.def("Label", (TCollection_AsciiString (IGESSelect_SplineToBSpline::*)() const) &IGESSelect_SplineToBSpline::Label, "Returns a text which defines the way a Transformer works : 'Conversion Spline to BSpline' and as opted, ' trying to upgrade continuity'");
cls_IGESSelect_SplineToBSpline.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SplineToBSpline::get_type_name, "None");
cls_IGESSelect_SplineToBSpline.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SplineToBSpline::get_type_descriptor, "None");
cls_IGESSelect_SplineToBSpline.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SplineToBSpline::*)() const) &IGESSelect_SplineToBSpline::DynamicType, "None");

// CLASS: IGESSELECT_UPDATECREATIONDATE
py::class_<IGESSelect_UpdateCreationDate, opencascade::handle<IGESSelect_UpdateCreationDate>, IGESSelect_ModelModifier> cls_IGESSelect_UpdateCreationDate(mod, "IGESSelect_UpdateCreationDate", "Allows to Change the Creation Date indication in the Header (Global Section) of IGES File. It is taken from the operating system (time of application of the Modifier). The Selection of the Modifier is not used : it simply acts as a criterium to select IGES Files to touch up");

// Constructors
cls_IGESSelect_UpdateCreationDate.def(py::init<>());

// Methods
cls_IGESSelect_UpdateCreationDate.def("Performing", (void (IGESSelect_UpdateCreationDate::*)(IFSelect_ContextModif &, const opencascade::handle<IGESData_IGESModel> &, Interface_CopyTool &) const) &IGESSelect_UpdateCreationDate::Performing, "Specific action : only <target> is used : the system Date is set to Global Section Item n0 18.", py::arg("ctx"), py::arg("target"), py::arg("TC"));
cls_IGESSelect_UpdateCreationDate.def("Label", (TCollection_AsciiString (IGESSelect_UpdateCreationDate::*)() const) &IGESSelect_UpdateCreationDate::Label, "Returns a text which is 'Update IGES Header Creation Date'");
cls_IGESSelect_UpdateCreationDate.def_static("get_type_name_", (const char * (*)()) &IGESSelect_UpdateCreationDate::get_type_name, "None");
cls_IGESSelect_UpdateCreationDate.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_UpdateCreationDate::get_type_descriptor, "None");
cls_IGESSelect_UpdateCreationDate.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_UpdateCreationDate::*)() const) &IGESSelect_UpdateCreationDate::DynamicType, "None");

// CLASS: IGESSELECT_UPDATEFILENAME
py::class_<IGESSelect_UpdateFileName, opencascade::handle<IGESSelect_UpdateFileName>, IGESSelect_ModelModifier> cls_IGESSelect_UpdateFileName(mod, "IGESSelect_UpdateFileName", "Sets the File Name in Header to be the actual name of the file If new file name is unknown, the former one is kept Remark : this works well only when it is Applied and send time If it is run immediately, new file name is unknown and nothing is done The Selection of the Modifier is not used : it simply acts as a criterium to select IGES Files to touch up");

// Constructors
cls_IGESSelect_UpdateFileName.def(py::init<>());

// Methods
cls_IGESSelect_UpdateFileName.def("Performing", (void (IGESSelect_UpdateFileName::*)(IFSelect_ContextModif &, const opencascade::handle<IGESData_IGESModel> &, Interface_CopyTool &) const) &IGESSelect_UpdateFileName::Performing, "Specific action : only <target> is used : the system Date is set to Global Section Item n0 18.", py::arg("ctx"), py::arg("target"), py::arg("TC"));
cls_IGESSelect_UpdateFileName.def("Label", (TCollection_AsciiString (IGESSelect_UpdateFileName::*)() const) &IGESSelect_UpdateFileName::Label, "Returns a text which is 'Updates IGES File Name to new current one'");
cls_IGESSelect_UpdateFileName.def_static("get_type_name_", (const char * (*)()) &IGESSelect_UpdateFileName::get_type_name, "None");
cls_IGESSelect_UpdateFileName.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_UpdateFileName::get_type_descriptor, "None");
cls_IGESSelect_UpdateFileName.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_UpdateFileName::*)() const) &IGESSelect_UpdateFileName::DynamicType, "None");

// CLASS: IGESSELECT_UPDATELASTCHANGE
py::class_<IGESSelect_UpdateLastChange, opencascade::handle<IGESSelect_UpdateLastChange>, IGESSelect_ModelModifier> cls_IGESSelect_UpdateLastChange(mod, "IGESSelect_UpdateLastChange", "Allows to Change the Last Change Date indication in the Header (Global Section) of IGES File. It is taken from the operating system (time of application of the Modifier). The Selection of the Modifier is not used : it simply acts as a criterium to select IGES Files to touch up. Remark : IGES Models noted as version before IGES 5.1 are in addition changed to 5.1");

// Constructors
cls_IGESSelect_UpdateLastChange.def(py::init<>());

// Methods
cls_IGESSelect_UpdateLastChange.def("Performing", (void (IGESSelect_UpdateLastChange::*)(IFSelect_ContextModif &, const opencascade::handle<IGESData_IGESModel> &, Interface_CopyTool &) const) &IGESSelect_UpdateLastChange::Performing, "Specific action : only <target> is used : the system Date is set to Global Section Item n0 25. Also sets IGES Version (Item n0 23) to IGES5 if it was older.", py::arg("ctx"), py::arg("target"), py::arg("TC"));
cls_IGESSelect_UpdateLastChange.def("Label", (TCollection_AsciiString (IGESSelect_UpdateLastChange::*)() const) &IGESSelect_UpdateLastChange::Label, "Returns a text which is 'Update IGES Header Last Change Date'");
cls_IGESSelect_UpdateLastChange.def_static("get_type_name_", (const char * (*)()) &IGESSelect_UpdateLastChange::get_type_name, "None");
cls_IGESSelect_UpdateLastChange.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_UpdateLastChange::get_type_descriptor, "None");
cls_IGESSelect_UpdateLastChange.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_UpdateLastChange::*)() const) &IGESSelect_UpdateLastChange::DynamicType, "None");

// CLASS: IGESSELECT_VIEWSORTER
py::class_<IGESSelect_ViewSorter, opencascade::handle<IGESSelect_ViewSorter>, Standard_Transient> cls_IGESSelect_ViewSorter(mod, "IGESSelect_ViewSorter", "Sorts IGES Entities on the views and drawings. In a first step, it splits a set of entities according the different views they are attached to. Then, packets according single views (+ drawing frames), or according drawings (which refer to the views) can be determined");

// Constructors
cls_IGESSelect_ViewSorter.def(py::init<>());

// Methods
cls_IGESSelect_ViewSorter.def("SetModel", (void (IGESSelect_ViewSorter::*)(const opencascade::handle<IGESData_IGESModel> &)) &IGESSelect_ViewSorter::SetModel, "Sets the Model (for PacketList)", py::arg("model"));
cls_IGESSelect_ViewSorter.def("Clear", (void (IGESSelect_ViewSorter::*)()) &IGESSelect_ViewSorter::Clear, "Clears recorded data");
cls_IGESSelect_ViewSorter.def("Add", (Standard_Boolean (IGESSelect_ViewSorter::*)(const opencascade::handle<Standard_Transient> &)) &IGESSelect_ViewSorter::Add, "Adds an item according its type : AddEntity,AddList,AddModel", py::arg("ent"));
cls_IGESSelect_ViewSorter.def("AddEntity", (Standard_Boolean (IGESSelect_ViewSorter::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESSelect_ViewSorter::AddEntity, "Adds an IGES entity. Records the view it is attached to. Records directly <ent> if it is a ViewKindEntity or a Drawing Returns True if added, False if already in the map", py::arg("igesent"));
cls_IGESSelect_ViewSorter.def("AddList", (void (IGESSelect_ViewSorter::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &)) &IGESSelect_ViewSorter::AddList, "Adds a list of entities by adding each of the items", py::arg("list"));
cls_IGESSelect_ViewSorter.def("AddModel", (void (IGESSelect_ViewSorter::*)(const opencascade::handle<Interface_InterfaceModel> &)) &IGESSelect_ViewSorter::AddModel, "Adds all the entities contained in a Model", py::arg("model"));
cls_IGESSelect_ViewSorter.def("NbEntities", (Standard_Integer (IGESSelect_ViewSorter::*)() const) &IGESSelect_ViewSorter::NbEntities, "Returns the count of already recorded");
cls_IGESSelect_ViewSorter.def("SortSingleViews", (void (IGESSelect_ViewSorter::*)(const Standard_Boolean)) &IGESSelect_ViewSorter::SortSingleViews, "Prepares the result to keep only sets attached to Single Views If <alsoframes> is given True, it keeps also the Drawings as specific sets, in order to get their frames. Entities attached to no single view are put in Remaining List.", py::arg("alsoframes"));
cls_IGESSelect_ViewSorter.def("SortDrawings", (void (IGESSelect_ViewSorter::*)(const Interface_Graph &)) &IGESSelect_ViewSorter::SortDrawings, "Prepares the result to the sets attached to Drawings : All the single views referenced by a Drawing become bound to the set for this Drawing", py::arg("G"));
cls_IGESSelect_ViewSorter.def("NbSets", (Standard_Integer (IGESSelect_ViewSorter::*)(const Standard_Boolean) const) &IGESSelect_ViewSorter::NbSets, "Returns the count of sets recorded, one per distinct item. The Remaining List is not counted. If <final> is False, the sets are attached to distinct views determined by the method Add. If <final> is True, they are the sets determined by the last call to, either SortSingleViews, or SortDrawings.", py::arg("final"));
cls_IGESSelect_ViewSorter.def("SetItem", (opencascade::handle<IGESData_IGESEntity> (IGESSelect_ViewSorter::*)(const Standard_Integer, const Standard_Boolean) const) &IGESSelect_ViewSorter::SetItem, "Returns the Item which is attached to a set of entities For <final> and definition of sets, see method NbSets. This item can be a kind of View or a Drawing", py::arg("num"), py::arg("final"));
cls_IGESSelect_ViewSorter.def("Sets", (opencascade::handle<IFSelect_PacketList> (IGESSelect_ViewSorter::*)(const Standard_Boolean) const) &IGESSelect_ViewSorter::Sets, "Returns the complete content of the determined Sets, which include Duplicated and Remaining (duplication 0) lists For <final> and definition of sets, see method NbSets.", py::arg("final"));
cls_IGESSelect_ViewSorter.def_static("get_type_name_", (const char * (*)()) &IGESSelect_ViewSorter::get_type_name, "None");
cls_IGESSelect_ViewSorter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_ViewSorter::get_type_descriptor, "None");
cls_IGESSelect_ViewSorter.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_ViewSorter::*)() const) &IGESSelect_ViewSorter::DynamicType, "None");

// CLASS: IGESSELECT_WORKLIBRARY
py::class_<IGESSelect_WorkLibrary, opencascade::handle<IGESSelect_WorkLibrary>, IFSelect_WorkLibrary> cls_IGESSelect_WorkLibrary(mod, "IGESSelect_WorkLibrary", "Performs Read and Write an IGES File with an IGES Model");

// Constructors
cls_IGESSelect_WorkLibrary.def(py::init<>());
cls_IGESSelect_WorkLibrary.def(py::init<const Standard_Boolean>(), py::arg("modefnes"));

// Methods
cls_IGESSelect_WorkLibrary.def("ReadFile", (Standard_Integer (IGESSelect_WorkLibrary::*)(const Standard_CString, opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &) const) &IGESSelect_WorkLibrary::ReadFile, "Reads a IGES File and returns a IGES Model (into <mod>), or lets <mod> 'Null' in case of Error Returns 0 if OK, 1 if Read Error, -1 if File not opened", py::arg("name"), py::arg("model"), py::arg("protocol"));
cls_IGESSelect_WorkLibrary.def("WriteFile", (Standard_Boolean (IGESSelect_WorkLibrary::*)(IFSelect_ContextWrite &) const) &IGESSelect_WorkLibrary::WriteFile, "Writes a File from a IGES Model (brought by <ctx>) Returns False (and writes no file) if <ctx> is not for IGES", py::arg("ctx"));
cls_IGESSelect_WorkLibrary.def_static("DefineProtocol_", (opencascade::handle<IGESData_Protocol> (*)()) &IGESSelect_WorkLibrary::DefineProtocol, "Defines a protocol to be adequate for IGES (encompasses ALL the IGES norm including IGESSolid, IGESAppli)");
cls_IGESSelect_WorkLibrary.def("DumpEntity", (void (IGESSelect_WorkLibrary::*)(const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESSelect_WorkLibrary::DumpEntity, "Dumps an IGES Entity with an IGES Dumper. <level> is the one used by IGESDumper.", py::arg("model"), py::arg("protocol"), py::arg("entity"), py::arg("S"), py::arg("level"));
cls_IGESSelect_WorkLibrary.def_static("get_type_name_", (const char * (*)()) &IGESSelect_WorkLibrary::get_type_name, "None");
cls_IGESSelect_WorkLibrary.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_WorkLibrary::get_type_descriptor, "None");
cls_IGESSelect_WorkLibrary.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_WorkLibrary::*)() const) &IGESSelect_WorkLibrary::DynamicType, "None");


}
