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
#include <Transfer_StatusResult.hxx>
#include <Transfer_StatusExec.hxx>
#include <Transfer_UndefMode.hxx>
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Transfer_Finder.hxx>
#include <Standard_Type.hxx>
#include <Interface_ParamType.hxx>
#include <NCollection_DataMap.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Std.hxx>
#include <NCollection_Sequence.hxx>
#include <Transfer_SequenceOfFinder.hxx>
#include <Standard.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Transfer_HSequenceOfFinder.hxx>
#include <Transfer_Binder.hxx>
#include <Interface_Check.hxx>
#include <Transfer_FindHasher.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <Transfer_TransferMapOfProcessForFinder.hxx>
#include <Transfer_ProcessForFinder.hxx>
#include <Transfer_SimpleBinderOfTransient.hxx>
#include <Transfer_ActorOfProcessForFinder.hxx>
#include <Transfer_FinderProcess.hxx>
#include <Transfer_ActorOfFinderProcess.hxx>
#include <TColStd_MapTransientHasher.hxx>
#include <Transfer_TransferMapOfProcessForTransient.hxx>
#include <Message_Messenger.hxx>
#include <Transfer_ActorOfProcessForTransient.hxx>
#include <Message_Msg.hxx>
#include <Transfer_IteratorOfProcessForTransient.hxx>
#include <Interface_CheckIterator.hxx>
#include <Message_ProgressIndicator.hxx>
#include <Transfer_ProcessForTransient.hxx>
#include <TColStd_IndexedMapOfInteger.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_HGraph.hxx>
#include <Interface_Graph.hxx>
#include <Interface_EntityIterator.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <Transfer_TransientProcess.hxx>
#include <Transfer_ActorOfTransientProcess.hxx>
#include <Transfer_IteratorOfProcessForFinder.hxx>
#include <Transfer_TransientMapper.hxx>
#include <Interface_Protocol.hxx>
#include <Transfer_TransferOutput.hxx>
#include <Interface_CopyTool.hxx>
#include <Interface_GeneralLib.hxx>
#include <Transfer_TransferDispatch.hxx>
#include <Transfer_ActorDispatch.hxx>
#include <Transfer_BinderOfTransientInteger.hxx>
#include <Transfer_DataInfo.hxx>
#include <Interface_CopyControl.hxx>
#include <Transfer_DispatchControl.hxx>
#include <Transfer_SequenceOfBinder.hxx>
#include <Transfer_HSequenceOfBinder.hxx>
#include <TColStd_HSequenceOfInteger.hxx>
#include <Transfer_TransferIterator.hxx>
#include <TColStd_DataMapOfTransientTransient.hxx>
#include <Transfer_MapContainer.hxx>
#include <Transfer_MultipleBinder.hxx>
#include <Transfer_ResultFromTransient.hxx>
#include <Interface_CheckStatus.hxx>
#include <Transfer_ResultFromModel.hxx>
#include <TColStd_IndexedMapOfTransient.hxx>
#include <Interface_InterfaceError.hxx>
#include <Transfer_TransferFailure.hxx>
#include <Standard_SStream.hxx>
#include <Transfer_TransferDeadLoop.hxx>
#include <Transfer_TransferInput.hxx>
#include <Transfer_TransientListBinder.hxx>
#include <Transfer_VoidBinder.hxx>
#include <bind_NCollection_Sequence.hxx>
#include <bind_Define_HSequence.hxx>
#include <bind_NCollection_IndexedDataMap.hxx>

PYBIND11_MODULE(Transfer, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Interface");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Message");

// ENUM: TRANSFER_STATUSRESULT
py::enum_<Transfer_StatusResult>(mod, "Transfer_StatusResult", "result status of transferring an entity (see Transcriptor)")
	.value("Transfer_StatusVoid", Transfer_StatusResult::Transfer_StatusVoid)
	.value("Transfer_StatusDefined", Transfer_StatusResult::Transfer_StatusDefined)
	.value("Transfer_StatusUsed", Transfer_StatusResult::Transfer_StatusUsed)
	.export_values();


// ENUM: TRANSFER_STATUSEXEC
py::enum_<Transfer_StatusExec>(mod, "Transfer_StatusExec", "execution status of an individual transfer (see Transcriptor)")
	.value("Transfer_StatusInitial", Transfer_StatusExec::Transfer_StatusInitial)
	.value("Transfer_StatusRun", Transfer_StatusExec::Transfer_StatusRun)
	.value("Transfer_StatusDone", Transfer_StatusExec::Transfer_StatusDone)
	.value("Transfer_StatusError", Transfer_StatusExec::Transfer_StatusError)
	.value("Transfer_StatusLoop", Transfer_StatusExec::Transfer_StatusLoop)
	.export_values();


// ENUM: TRANSFER_UNDEFMODE
py::enum_<Transfer_UndefMode>(mod, "Transfer_UndefMode", "used on processing Undefined Entities (see TransferOutput)")
	.value("Transfer_UndefIgnore", Transfer_UndefMode::Transfer_UndefIgnore)
	.value("Transfer_UndefFailure", Transfer_UndefMode::Transfer_UndefFailure)
	.value("Transfer_UndefContent", Transfer_UndefMode::Transfer_UndefContent)
	.value("Transfer_UndefUser", Transfer_UndefMode::Transfer_UndefUser)
	.export_values();


// CLASS: TRANSFER_FINDER
py::class_<Transfer_Finder, opencascade::handle<Transfer_Finder>, Standard_Transient> cls_Transfer_Finder(mod, "Transfer_Finder", "a Finder allows to map any kind of object as a Key for a Map. This works by defining, for a Hash Code, that of the real Key, not of the Finder which acts only as an intermediate. When a Map asks for the HashCode of a Finder, this one returns the code it has determined at creation time");

// Methods
cls_Transfer_Finder.def("GetHashCode", (Standard_Integer (Transfer_Finder::*)() const) &Transfer_Finder::GetHashCode, "Returns the HashCode which has been stored by SetHashCode (remark that HashCode could be deferred then be defined by sub-classes, the result is the same)");
cls_Transfer_Finder.def("Equates", (Standard_Boolean (Transfer_Finder::*)(const opencascade::handle<Transfer_Finder> &) const) &Transfer_Finder::Equates, "Specific testof equallity : to be defined by each sub-class, must be False if Finders have not the same true Type, else their contents must be compared", py::arg("other"));
cls_Transfer_Finder.def("ValueType", (opencascade::handle<Standard_Type> (Transfer_Finder::*)() const) &Transfer_Finder::ValueType, "Returns the Type of the Value. By default, returns the DynamicType of <me>, but can be redefined");
cls_Transfer_Finder.def("ValueTypeName", (Standard_CString (Transfer_Finder::*)() const) &Transfer_Finder::ValueTypeName, "Returns the name of the Type of the Value. Default is name of ValueType, unless it is for a non-handled object");
cls_Transfer_Finder.def("SetAttribute", (void (Transfer_Finder::*)(const Standard_CString, const opencascade::handle<Standard_Transient> &)) &Transfer_Finder::SetAttribute, "Adds an attribute with a given name (replaces the former one with the same name if already exists)", py::arg("name"), py::arg("val"));
cls_Transfer_Finder.def("RemoveAttribute", (Standard_Boolean (Transfer_Finder::*)(const Standard_CString)) &Transfer_Finder::RemoveAttribute, "Removes an attribute Returns True when done, False if this attribute did not exist", py::arg("name"));
cls_Transfer_Finder.def("GetAttribute", (Standard_Boolean (Transfer_Finder::*)(const Standard_CString, const opencascade::handle<Standard_Type> &, opencascade::handle<Standard_Transient> &) const) &Transfer_Finder::GetAttribute, "Returns an attribute from its name, filtered by a type If no attribute has this name, or if it is not kind of this type, <val> is Null and returned value is False Else, it is True", py::arg("name"), py::arg("type"), py::arg("val"));
cls_Transfer_Finder.def("Attribute", (opencascade::handle<Standard_Transient> (Transfer_Finder::*)(const Standard_CString) const) &Transfer_Finder::Attribute, "Returns an attribute from its name. Null Handle if not recorded (whatever Transient, Integer, Real ...)", py::arg("name"));
cls_Transfer_Finder.def("AttributeType", (Interface_ParamType (Transfer_Finder::*)(const Standard_CString) const) &Transfer_Finder::AttributeType, "Returns the type of an attribute : ParamInt , ParamReal , ParamText (String) , ParamIdent (any) or ParamVoid (not recorded)", py::arg("name"));
cls_Transfer_Finder.def("SetIntegerAttribute", (void (Transfer_Finder::*)(const Standard_CString, const Standard_Integer)) &Transfer_Finder::SetIntegerAttribute, "Adds an integer value for an attribute", py::arg("name"), py::arg("val"));
cls_Transfer_Finder.def("GetIntegerAttribute", [](Transfer_Finder &self, const Standard_CString name, Standard_Integer & val){ Standard_Boolean rv = self.GetIntegerAttribute(name, val); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, val); }, "Returns an attribute from its name, as integer If no attribute has this name, or not an integer, <val> is 0 and returned value is False Else, it is True", py::arg("name"), py::arg("val"));
cls_Transfer_Finder.def("IntegerAttribute", (Standard_Integer (Transfer_Finder::*)(const Standard_CString) const) &Transfer_Finder::IntegerAttribute, "Returns an integer attribute from its name. 0 if not recorded", py::arg("name"));
cls_Transfer_Finder.def("SetRealAttribute", (void (Transfer_Finder::*)(const Standard_CString, const Standard_Real)) &Transfer_Finder::SetRealAttribute, "Adds a real value for an attribute", py::arg("name"), py::arg("val"));
cls_Transfer_Finder.def("GetRealAttribute", [](Transfer_Finder &self, const Standard_CString name, Standard_Real & val){ Standard_Boolean rv = self.GetRealAttribute(name, val); return std::tuple<Standard_Boolean, Standard_Real &>(rv, val); }, "Returns an attribute from its name, as real If no attribute has this name, or not a real <val> is 0.0 and returned value is False Else, it is True", py::arg("name"), py::arg("val"));
cls_Transfer_Finder.def("RealAttribute", (Standard_Real (Transfer_Finder::*)(const Standard_CString) const) &Transfer_Finder::RealAttribute, "Returns a real attribute from its name. 0.0 if not recorded", py::arg("name"));
cls_Transfer_Finder.def("SetStringAttribute", (void (Transfer_Finder::*)(const Standard_CString, const Standard_CString)) &Transfer_Finder::SetStringAttribute, "Adds a String value for an attribute", py::arg("name"), py::arg("val"));
// cls_Transfer_Finder.def("GetStringAttribute", [](Transfer_Finder &self, const Standard_CString name, Standard_CString & val){ Standard_Boolean rv = self.GetStringAttribute(name, val); return std::tuple<Standard_Boolean, Standard_CString &>(rv, val); }, "Returns an attribute from its name, as String If no attribute has this name, or not a String <val> is 0.0 and returned value is False Else, it is True", py::arg("name"), py::arg("val"));
cls_Transfer_Finder.def("StringAttribute", (Standard_CString (Transfer_Finder::*)(const Standard_CString) const) &Transfer_Finder::StringAttribute, "Returns a String attribute from its name. '' if not recorded", py::arg("name"));
cls_Transfer_Finder.def("AttrList", (NCollection_DataMap<TCollection_AsciiString, opencascade::handle<Standard_Transient> > & (Transfer_Finder::*)()) &Transfer_Finder::AttrList, "Returns the exhaustive list of attributes");
cls_Transfer_Finder.def("SameAttributes", (void (Transfer_Finder::*)(const opencascade::handle<Transfer_Finder> &)) &Transfer_Finder::SameAttributes, "Gets the list of attributes from <other>, as such, i.e. not copied : attributes are shared, any attribute edited, added, or removed in <other> is also in <me> and vice versa The former list of attributes of <me> is dropped", py::arg("other"));
cls_Transfer_Finder.def("GetAttributes", [](Transfer_Finder &self, const opencascade::handle<Transfer_Finder> & a0) -> void { return self.GetAttributes(a0); });
cls_Transfer_Finder.def("GetAttributes", [](Transfer_Finder &self, const opencascade::handle<Transfer_Finder> & a0, const Standard_CString a1) -> void { return self.GetAttributes(a0, a1); });
cls_Transfer_Finder.def("GetAttributes", (void (Transfer_Finder::*)(const opencascade::handle<Transfer_Finder> &, const Standard_CString, const Standard_Boolean)) &Transfer_Finder::GetAttributes, "Gets the list of attributes from <other>, by copying it By default, considers all the attributes from <other> If <fromname> is given, considers only the attributes with name beginning by <fromname>", py::arg("other"), py::arg("fromname"), py::arg("copied"));
cls_Transfer_Finder.def_static("get_type_name_", (const char * (*)()) &Transfer_Finder::get_type_name, "None");
cls_Transfer_Finder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_Finder::get_type_descriptor, "None");
cls_Transfer_Finder.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_Finder::*)() const) &Transfer_Finder::DynamicType, "None");

// TYPEDEF: TRANSFER_SEQUENCEOFFINDER
bind_NCollection_Sequence<opencascade::handle<Transfer_Finder> >(mod, "Transfer_SequenceOfFinder", py::module_local(false));

// CLASS: TRANSFER_HSEQUENCEOFFINDER
bind_Define_HSequence<Transfer_HSequenceOfFinder, Transfer_SequenceOfFinder>(mod, "Transfer_HSequenceOfFinder");

// CLASS: TRANSFER_BINDER
py::class_<Transfer_Binder, opencascade::handle<Transfer_Binder>, Standard_Transient> cls_Transfer_Binder(mod, "Transfer_Binder", "A Binder is an auxiliary object to Map the Result of the Transfer of a given Object : it records the Result of the Unitary Transfer (Resulting Object), status of progress and error (if any) of the Process");

// Methods
cls_Transfer_Binder.def("Merge", (void (Transfer_Binder::*)(const opencascade::handle<Transfer_Binder> &)) &Transfer_Binder::Merge, "Merges basic data (Check, ExecStatus) from another Binder but keeps its result. Used when a binder is replaced by another one, this allows to keep messages", py::arg("other"));
cls_Transfer_Binder.def("IsMultiple", (Standard_Boolean (Transfer_Binder::*)() const) &Transfer_Binder::IsMultiple, "Returns True if a Binder has several results, either by itself or because it has next results Can be defined by sub-classes.");
cls_Transfer_Binder.def("ResultType", (opencascade::handle<Standard_Type> (Transfer_Binder::*)() const) &Transfer_Binder::ResultType, "Returns the Type which characterizes the Result (if known)");
cls_Transfer_Binder.def("ResultTypeName", (Standard_CString (Transfer_Binder::*)() const) &Transfer_Binder::ResultTypeName, "Returns the Name of the Type which characterizes the Result Can be returned even if ResultType itself is unknown");
cls_Transfer_Binder.def("AddResult", (void (Transfer_Binder::*)(const opencascade::handle<Transfer_Binder> &)) &Transfer_Binder::AddResult, "Adds a next result (at the end of the list) Remark : this information is not processed by Merge", py::arg("next"));
cls_Transfer_Binder.def("NextResult", (opencascade::handle<Transfer_Binder> (Transfer_Binder::*)() const) &Transfer_Binder::NextResult, "Returns the next result, Null if none");
cls_Transfer_Binder.def("HasResult", (Standard_Boolean (Transfer_Binder::*)() const) &Transfer_Binder::HasResult, "Returns True if a Result is available (StatusResult = Defined) A Unique Result will be gotten by Result (which must be defined in each sub-class according to result type) For a Multiple Result, see class MultipleBinder For other case, specific access has to be forecast");
cls_Transfer_Binder.def("SetAlreadyUsed", (void (Transfer_Binder::*)()) &Transfer_Binder::SetAlreadyUsed, "Declares that result is now used by another one, it means that it cannot be modified (by Rebind)");
cls_Transfer_Binder.def("Status", (Transfer_StatusResult (Transfer_Binder::*)() const) &Transfer_Binder::Status, "Returns status, which can be Initial (not yet done), Made (a result is recorded, not yet shared), Used (it is shared and cannot be modified)");
cls_Transfer_Binder.def("StatusExec", (Transfer_StatusExec (Transfer_Binder::*)() const) &Transfer_Binder::StatusExec, "Returns execution status");
cls_Transfer_Binder.def("SetStatusExec", (void (Transfer_Binder::*)(const Transfer_StatusExec)) &Transfer_Binder::SetStatusExec, "Modifies execution status; called by TransferProcess only (for StatusError, rather use SetError, below)", py::arg("stat"));
cls_Transfer_Binder.def("AddFail", [](Transfer_Binder &self, const Standard_CString a0) -> void { return self.AddFail(a0); });
cls_Transfer_Binder.def("AddFail", (void (Transfer_Binder::*)(const Standard_CString, const Standard_CString)) &Transfer_Binder::AddFail, "Used to declare an individual transfer as beeing erroneous (Status is set to Void, StatusExec is set to Error, <errmess> is added to Check's list of Fails) It is possible to record several messages of error", py::arg("mess"), py::arg("orig"));
cls_Transfer_Binder.def("AddWarning", [](Transfer_Binder &self, const Standard_CString a0) -> void { return self.AddWarning(a0); });
cls_Transfer_Binder.def("AddWarning", (void (Transfer_Binder::*)(const Standard_CString, const Standard_CString)) &Transfer_Binder::AddWarning, "Used to attach a Warning Message to an individual Transfer It has no effect on the Status", py::arg("mess"), py::arg("orig"));
cls_Transfer_Binder.def("Check", (const opencascade::handle<Interface_Check> (Transfer_Binder::*)() const) &Transfer_Binder::Check, "Returns Check which stores Fail messages Note that no Entity is associated in this Check");
cls_Transfer_Binder.def("CCheck", (opencascade::handle<Interface_Check> (Transfer_Binder::*)()) &Transfer_Binder::CCheck, "Returns Check which stores Fail messages, in order to modify it (adding messages, or replacing it)");
cls_Transfer_Binder.def_static("get_type_name_", (const char * (*)()) &Transfer_Binder::get_type_name, "None");
cls_Transfer_Binder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_Binder::get_type_descriptor, "None");
cls_Transfer_Binder.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_Binder::*)() const) &Transfer_Binder::DynamicType, "None");

// CLASS: TRANSFER_FINDHASHER
py::class_<Transfer_FindHasher> cls_Transfer_FindHasher(mod, "Transfer_FindHasher", "FindHasher defines HashCode for Finder, which is : ask a Finder its HashCode ! Because this is the Finder itself which brings the HashCode for its Key");

// Constructors
cls_Transfer_FindHasher.def(py::init<>());

// Methods
// cls_Transfer_FindHasher.def_static("operator new_", (void * (*)(size_t)) &Transfer_FindHasher::operator new, "None", py::arg("theSize"));
// cls_Transfer_FindHasher.def_static("operator delete_", (void (*)(void *)) &Transfer_FindHasher::operator delete, "None", py::arg("theAddress"));
// cls_Transfer_FindHasher.def_static("operator new[]_", (void * (*)(size_t)) &Transfer_FindHasher::operator new[], "None", py::arg("theSize"));
// cls_Transfer_FindHasher.def_static("operator delete[]_", (void (*)(void *)) &Transfer_FindHasher::operator delete[], "None", py::arg("theAddress"));
// cls_Transfer_FindHasher.def_static("operator new_", (void * (*)(size_t, void *)) &Transfer_FindHasher::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Transfer_FindHasher.def_static("operator delete_", (void (*)(void *, void *)) &Transfer_FindHasher::operator delete, "None", py::arg(""), py::arg(""));
cls_Transfer_FindHasher.def_static("HashCode_", (Standard_Integer (*)(const opencascade::handle<Transfer_Finder> &, Standard_Integer)) &Transfer_FindHasher::HashCode, "Returns hash code for the given finder, in the range [1, theUpperBound]. Asks the finder its hash code, then transforms it to be in the required range", py::arg("theFinder"), py::arg("theUpperBound"));
cls_Transfer_FindHasher.def_static("IsEqual_", (Standard_Boolean (*)(const opencascade::handle<Transfer_Finder> &, const opencascade::handle<Transfer_Finder> &)) &Transfer_FindHasher::IsEqual, "Returns True if two keys are the same. The test does not work on the Finders themselves but by calling their methods Equates", py::arg("K1"), py::arg("K2"));

// TYPEDEF: TRANSFER_TRANSFERMAPOFPROCESSFORFINDER
bind_NCollection_IndexedDataMap<opencascade::handle<Transfer_Finder>, opencascade::handle<Transfer_Binder>, Transfer_FindHasher>(mod, "Transfer_TransferMapOfProcessForFinder", py::module_local(false));

// CLASS: TRANSFER_ACTOROFPROCESSFORFINDER
py::class_<Transfer_ActorOfProcessForFinder, opencascade::handle<Transfer_ActorOfProcessForFinder>, Standard_Transient> cls_Transfer_ActorOfProcessForFinder(mod, "Transfer_ActorOfProcessForFinder", "None");

// Constructors
cls_Transfer_ActorOfProcessForFinder.def(py::init<>());

// Methods
cls_Transfer_ActorOfProcessForFinder.def("Recognize", (Standard_Boolean (Transfer_ActorOfProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &)) &Transfer_ActorOfProcessForFinder::Recognize, "Prerequesite for Transfer : the method Transfer is called on a starting object only if Recognize has returned True on it This allows to define a list of Actors, each one processing a definite kind of data TransferProcess calls Recognize on each one before calling Transfer. But even if Recognize has returned True, Transfer can reject by returning a Null Binder (afterwards rejection), the next actor is then invoked", py::arg("start"));
cls_Transfer_ActorOfProcessForFinder.def("Transferring", (opencascade::handle<Transfer_Binder> (Transfer_ActorOfProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &, const opencascade::handle<Transfer_ProcessForFinder> &)) &Transfer_ActorOfProcessForFinder::Transferring, "Specific action of Transfer. The Result is stored in the returned Binder, or a Null Handle for 'No result' (Default defined as doing nothing; should be deffered) 'mutable' allows the Actor to record intermediate information, in addition to those of TransferProcess", py::arg("start"), py::arg("TP"));
cls_Transfer_ActorOfProcessForFinder.def("TransientResult", (opencascade::handle<Transfer_SimpleBinderOfTransient> (Transfer_ActorOfProcessForFinder::*)(const opencascade::handle<Standard_Transient> &) const) &Transfer_ActorOfProcessForFinder::TransientResult, "Prepares and Returns a Binder for a Transient Result Returns a Null Handle if <res> is itself Null", py::arg("res"));
cls_Transfer_ActorOfProcessForFinder.def("NullResult", (opencascade::handle<Transfer_Binder> (Transfer_ActorOfProcessForFinder::*)() const) &Transfer_ActorOfProcessForFinder::NullResult, "Returns a Binder for No Result, i.e. a Null Handle");
cls_Transfer_ActorOfProcessForFinder.def("SetLast", [](Transfer_ActorOfProcessForFinder &self) -> void { return self.SetLast(); });
cls_Transfer_ActorOfProcessForFinder.def("SetLast", (void (Transfer_ActorOfProcessForFinder::*)(const Standard_Boolean)) &Transfer_ActorOfProcessForFinder::SetLast, "If <mode> is True, commands an Actor to be set at the end of the list of Actors (see SetNext) If it is False (creation default), each add Actor is set at the beginning of the list This allows to define default Actors (which are Last)", py::arg("mode"));
cls_Transfer_ActorOfProcessForFinder.def("IsLast", (Standard_Boolean (Transfer_ActorOfProcessForFinder::*)() const) &Transfer_ActorOfProcessForFinder::IsLast, "Returns the Last status (see SetLast).");
cls_Transfer_ActorOfProcessForFinder.def("SetNext", (void (Transfer_ActorOfProcessForFinder::*)(const opencascade::handle<Transfer_ActorOfProcessForFinder> &)) &Transfer_ActorOfProcessForFinder::SetNext, "Defines a Next Actor : it can then be asked to work if <me> produces no result for a given type of Object. If Next is already set and is not 'Last', calls SetNext on it. If Next defined and 'Last', the new actor is added before it in the list", py::arg("next"));
cls_Transfer_ActorOfProcessForFinder.def("Next", (opencascade::handle<Transfer_ActorOfProcessForFinder> (Transfer_ActorOfProcessForFinder::*)() const) &Transfer_ActorOfProcessForFinder::Next, "Returns the Actor defined as Next, or a Null Handle");
cls_Transfer_ActorOfProcessForFinder.def_static("get_type_name_", (const char * (*)()) &Transfer_ActorOfProcessForFinder::get_type_name, "None");
cls_Transfer_ActorOfProcessForFinder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_ActorOfProcessForFinder::get_type_descriptor, "None");
cls_Transfer_ActorOfProcessForFinder.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_ActorOfProcessForFinder::*)() const) &Transfer_ActorOfProcessForFinder::DynamicType, "None");

// CLASS: TRANSFER_ACTOROFFINDERPROCESS
py::class_<Transfer_ActorOfFinderProcess, opencascade::handle<Transfer_ActorOfFinderProcess>, Transfer_ActorOfProcessForFinder> cls_Transfer_ActorOfFinderProcess(mod, "Transfer_ActorOfFinderProcess", "The original class was renamed. Compatibility only");

// Constructors
cls_Transfer_ActorOfFinderProcess.def(py::init<>());

// Methods
cls_Transfer_ActorOfFinderProcess.def("ModeTrans", (Standard_Integer & (Transfer_ActorOfFinderProcess::*)()) &Transfer_ActorOfFinderProcess::ModeTrans, "Returns the Transfer Mode, modifiable");
cls_Transfer_ActorOfFinderProcess.def("Transferring", (opencascade::handle<Transfer_Binder> (Transfer_ActorOfFinderProcess::*)(const opencascade::handle<Transfer_Finder> &, const opencascade::handle<Transfer_ProcessForFinder> &)) &Transfer_ActorOfFinderProcess::Transferring, "None", py::arg("start"), py::arg("TP"));
cls_Transfer_ActorOfFinderProcess.def("Transfer", (opencascade::handle<Transfer_Binder> (Transfer_ActorOfFinderProcess::*)(const opencascade::handle<Transfer_Finder> &, const opencascade::handle<Transfer_FinderProcess> &)) &Transfer_ActorOfFinderProcess::Transfer, "None", py::arg("start"), py::arg("TP"));
cls_Transfer_ActorOfFinderProcess.def("TransferTransient", (opencascade::handle<Standard_Transient> (Transfer_ActorOfFinderProcess::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Transfer_FinderProcess> &)) &Transfer_ActorOfFinderProcess::TransferTransient, "None", py::arg("start"), py::arg("TP"));
cls_Transfer_ActorOfFinderProcess.def_static("get_type_name_", (const char * (*)()) &Transfer_ActorOfFinderProcess::get_type_name, "None");
cls_Transfer_ActorOfFinderProcess.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_ActorOfFinderProcess::get_type_descriptor, "None");
cls_Transfer_ActorOfFinderProcess.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_ActorOfFinderProcess::*)() const) &Transfer_ActorOfFinderProcess::DynamicType, "None");

// TYPEDEF: TRANSFER_TRANSFERMAPOFPROCESSFORTRANSIENT
bind_NCollection_IndexedDataMap<opencascade::handle<Standard_Transient>, opencascade::handle<Transfer_Binder>, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "Transfer_TransferMapOfProcessForTransient", py::module_local(false));

// CLASS: TRANSFER_PROCESSFORTRANSIENT
py::class_<Transfer_ProcessForTransient, opencascade::handle<Transfer_ProcessForTransient>, Standard_Transient> cls_Transfer_ProcessForTransient(mod, "Transfer_ProcessForTransient", "Manages Transfer of Transient Objects. Produces also ActorOfTransientProcess (deferred class), IteratorOfTransientProcess (for Results), TransferMapOfTransientProcess (internally used) Normally uses as TransientProcess, which adds some specifics");

// Constructors
cls_Transfer_ProcessForTransient.def(py::init<>());
cls_Transfer_ProcessForTransient.def(py::init<const Standard_Integer>(), py::arg("nb"));
cls_Transfer_ProcessForTransient.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("printer"));
cls_Transfer_ProcessForTransient.def(py::init<const opencascade::handle<Message_Messenger> &, const Standard_Integer>(), py::arg("printer"), py::arg("nb"));

// Methods
cls_Transfer_ProcessForTransient.def("Clear", (void (Transfer_ProcessForTransient::*)()) &Transfer_ProcessForTransient::Clear, "Resets a TransferProcess as ready for a completely new work. Clears general data (roots) and the Map");
cls_Transfer_ProcessForTransient.def("Clean", (void (Transfer_ProcessForTransient::*)()) &Transfer_ProcessForTransient::Clean, "Rebuilds the Map and the roots to really remove Unbound items Because Unbind keeps the entity in place, even if not bound Hence, working by checking new items is meaningless if a formerly unbound item is rebound");
cls_Transfer_ProcessForTransient.def("Resize", (void (Transfer_ProcessForTransient::*)(const Standard_Integer)) &Transfer_ProcessForTransient::Resize, "Resizes the Map as required (if a new reliable value has been determined). Acts only if <nb> is greater than actual NbMapped", py::arg("nb"));
cls_Transfer_ProcessForTransient.def("SetActor", (void (Transfer_ProcessForTransient::*)(const opencascade::handle<Transfer_ActorOfProcessForTransient> &)) &Transfer_ProcessForTransient::SetActor, "Defines an Actor, which is used for automatic Transfer If already defined, the new Actor is cumulated (see SetNext from Actor)", py::arg("actor"));
cls_Transfer_ProcessForTransient.def("Actor", (opencascade::handle<Transfer_ActorOfProcessForTransient> (Transfer_ProcessForTransient::*)() const) &Transfer_ProcessForTransient::Actor, "Returns the defined Actor. Returns a Null Handle if not set.");
cls_Transfer_ProcessForTransient.def("Find", (opencascade::handle<Transfer_Binder> (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &) const) &Transfer_ProcessForTransient::Find, "Returns the Binder which is linked with a starting Object It can either bring a Result (Transfer done) or none (for a pre-binding). If no Binder is linked with <start>, returns a Null Handle Considers a category number, by default 0", py::arg("start"));
cls_Transfer_ProcessForTransient.def("IsBound", (Standard_Boolean (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &) const) &Transfer_ProcessForTransient::IsBound, "Returns True if a Result (whatever its form) is Bound with a starting Object. I.e., if a Binder with a Result set, is linked with it Considers a category number, by default 0", py::arg("start"));
cls_Transfer_ProcessForTransient.def("IsAlreadyUsed", (Standard_Boolean (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &) const) &Transfer_ProcessForTransient::IsAlreadyUsed, "Returns True if the result of the transfer of an object is already used in other ones. If it is, Rebind cannot change it. Considers a category number, by default 0", py::arg("start"));
cls_Transfer_ProcessForTransient.def("Bind", (void (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Transfer_Binder> &)) &Transfer_ProcessForTransient::Bind, "Creates a Link a starting Object with a Binder. This Binder can either bring a Result (effective Binding) or none (it can be set later : pre-binding). Considers a category number, by default 0", py::arg("start"), py::arg("binder"));
cls_Transfer_ProcessForTransient.def("Rebind", (void (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Transfer_Binder> &)) &Transfer_ProcessForTransient::Rebind, "Changes the Binder linked with a starting Object for its unitary transfer. This it can be useful when the exact form of the result is known once the transfer is widely engaged. This can be done only on first transfer. Considers a category number, by default 0", py::arg("start"), py::arg("binder"));
cls_Transfer_ProcessForTransient.def("Unbind", (Standard_Boolean (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &)) &Transfer_ProcessForTransient::Unbind, "Removes the Binder linked with a starting object If this Binder brings a non-empty Check, it is replaced by a VoidBinder. Also removes from the list of Roots as required. Returns True if done, False if <start> was not bound Considers a category number, by default 0", py::arg("start"));
cls_Transfer_ProcessForTransient.def("FindElseBind", (opencascade::handle<Transfer_Binder> (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &)) &Transfer_ProcessForTransient::FindElseBind, "Returns a Binder for a starting entity, as follows : Tries to Find the already bound one If none found, creates a VoidBinder and Binds it", py::arg("start"));
cls_Transfer_ProcessForTransient.def("SetMessenger", (void (Transfer_ProcessForTransient::*)(const opencascade::handle<Message_Messenger> &)) &Transfer_ProcessForTransient::SetMessenger, "Sets Messenger used for outputting messages.", py::arg("messenger"));
cls_Transfer_ProcessForTransient.def("Messenger", (opencascade::handle<Message_Messenger> (Transfer_ProcessForTransient::*)() const) &Transfer_ProcessForTransient::Messenger, "Returns Messenger used for outputting messages. The returned object is guaranteed to be non-null; default is Message::Messenger().");
cls_Transfer_ProcessForTransient.def("SetTraceLevel", (void (Transfer_ProcessForTransient::*)(const Standard_Integer)) &Transfer_ProcessForTransient::SetTraceLevel, "Sets trace level used for outputting messages: <trace> = 0 : no trace at all <trace> = 1 : handled exceptions and calls to AddError <trace> = 2 : also calls to AddWarning <trace> = 3 : also traces new Roots (uses method ErrorTrace). Default is 1 : Errors traced", py::arg("tracelev"));
cls_Transfer_ProcessForTransient.def("TraceLevel", (Standard_Integer (Transfer_ProcessForTransient::*)() const) &Transfer_ProcessForTransient::TraceLevel, "Returns trace level used for outputting messages.");
cls_Transfer_ProcessForTransient.def("SendFail", (void (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &, const Message_Msg &)) &Transfer_ProcessForTransient::SendFail, "New name for AddFail (Msg)", py::arg("start"), py::arg("amsg"));
cls_Transfer_ProcessForTransient.def("SendWarning", (void (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &, const Message_Msg &)) &Transfer_ProcessForTransient::SendWarning, "New name for AddWarning (Msg)", py::arg("start"), py::arg("amsg"));
cls_Transfer_ProcessForTransient.def("SendMsg", (void (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &, const Message_Msg &)) &Transfer_ProcessForTransient::SendMsg, "Adds an information message Trace is filled if trace level is at least 3", py::arg("start"), py::arg("amsg"));
cls_Transfer_ProcessForTransient.def("AddFail", [](Transfer_ProcessForTransient &self, const opencascade::handle<Standard_Transient> & a0, const Standard_CString a1) -> void { return self.AddFail(a0, a1); });
cls_Transfer_ProcessForTransient.def("AddFail", (void (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &, const Standard_CString, const Standard_CString)) &Transfer_ProcessForTransient::AddFail, "Adds an Error message to a starting entity (to the check of its Binder of category 0, as a Fail)", py::arg("start"), py::arg("mess"), py::arg("orig"));
cls_Transfer_ProcessForTransient.def("AddError", [](Transfer_ProcessForTransient &self, const opencascade::handle<Standard_Transient> & a0, const Standard_CString a1) -> void { return self.AddError(a0, a1); });
cls_Transfer_ProcessForTransient.def("AddError", (void (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &, const Standard_CString, const Standard_CString)) &Transfer_ProcessForTransient::AddError, "(other name of AddFail, maintained for compatibility)", py::arg("start"), py::arg("mess"), py::arg("orig"));
cls_Transfer_ProcessForTransient.def("AddFail", (void (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &, const Message_Msg &)) &Transfer_ProcessForTransient::AddFail, "Adds an Error Message to a starting entity from the definition of a Msg (Original+Value)", py::arg("start"), py::arg("amsg"));
cls_Transfer_ProcessForTransient.def("AddWarning", [](Transfer_ProcessForTransient &self, const opencascade::handle<Standard_Transient> & a0, const Standard_CString a1) -> void { return self.AddWarning(a0, a1); });
cls_Transfer_ProcessForTransient.def("AddWarning", (void (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &, const Standard_CString, const Standard_CString)) &Transfer_ProcessForTransient::AddWarning, "Adds a Warning message to a starting entity (to the check of its Binder of category 0)", py::arg("start"), py::arg("mess"), py::arg("orig"));
cls_Transfer_ProcessForTransient.def("AddWarning", (void (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &, const Message_Msg &)) &Transfer_ProcessForTransient::AddWarning, "Adds a Warning Message to a starting entity from the definition of a Msg (Original+Value)", py::arg("start"), py::arg("amsg"));
cls_Transfer_ProcessForTransient.def("Mend", [](Transfer_ProcessForTransient &self, const opencascade::handle<Standard_Transient> & a0) -> void { return self.Mend(a0); });
cls_Transfer_ProcessForTransient.def("Mend", (void (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &, const Standard_CString)) &Transfer_ProcessForTransient::Mend, "None", py::arg("start"), py::arg("pref"));
cls_Transfer_ProcessForTransient.def("Check", (opencascade::handle<Interface_Check> (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &) const) &Transfer_ProcessForTransient::Check, "Returns the Check attached to a starting entity. If <start> is unknown, returns an empty Check Adds a case name to a starting entity Adds a case value to a starting entity Returns the complete case list for an entity. Null Handle if empty In the list of mapped items (between 1 and NbMapped), searches for the first item which follows <num0>(not included) and which has an attribute named <name> Attributes are brought by Binders Hence, allows such an iteration", py::arg("start"));
cls_Transfer_ProcessForTransient.def("BindTransient", (void (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &)) &Transfer_ProcessForTransient::BindTransient, "Binds a starting object with a Transient Result. Uses a SimpleBinderOfTransient to work. If there is already one but with no Result set, sets its Result. Considers a category number, by default 0", py::arg("start"), py::arg("res"));
cls_Transfer_ProcessForTransient.def("FindTransient", (const opencascade::handle<Standard_Transient> & (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &) const) &Transfer_ProcessForTransient::FindTransient, "Returns the Result of the Transfer of an object <start> as a Transient Result. Returns a Null Handle if there is no Transient Result Considers a category number, by default 0 Warning : Supposes that Binding is done with a SimpleBinderOfTransient", py::arg("start"));
cls_Transfer_ProcessForTransient.def("BindMultiple", (void (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &)) &Transfer_ProcessForTransient::BindMultiple, "Prepares an object <start> to be bound with several results. If no Binder is yet attached to <obj>, a MultipleBinder is created, empty. If a Binder is already set, it must accept Multiple Binding. Considers a category number, by default 0", py::arg("start"));
cls_Transfer_ProcessForTransient.def("AddMultiple", (void (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &)) &Transfer_ProcessForTransient::AddMultiple, "Adds an item to a list of results bound to a starting object. Considers a category number, by default 0, for all results", py::arg("start"), py::arg("res"));
cls_Transfer_ProcessForTransient.def("FindTypedTransient", (Standard_Boolean (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Type> &, opencascade::handle<Standard_Transient> &) const) &Transfer_ProcessForTransient::FindTypedTransient, "Searches for a transient result attached to a starting object, according to its type, by criterium IsKind(atype)", py::arg("start"), py::arg("atype"), py::arg("val"));
cls_Transfer_ProcessForTransient.def("GetTypedTransient", (Standard_Boolean (Transfer_ProcessForTransient::*)(const opencascade::handle<Transfer_Binder> &, const opencascade::handle<Standard_Type> &, opencascade::handle<Standard_Transient> &) const) &Transfer_ProcessForTransient::GetTypedTransient, "Searches for a transient result recorded in a Binder, whatever this Binder is recorded or not in <me>", py::arg("binder"), py::arg("atype"), py::arg("val"));
cls_Transfer_ProcessForTransient.def("NbMapped", (Standard_Integer (Transfer_ProcessForTransient::*)() const) &Transfer_ProcessForTransient::NbMapped, "Returns the maximum possible value for Map Index (no result can be bound with a value greater than it)");
cls_Transfer_ProcessForTransient.def("Mapped", (const opencascade::handle<Standard_Transient> & (Transfer_ProcessForTransient::*)(const Standard_Integer) const) &Transfer_ProcessForTransient::Mapped, "Returns the Starting Object bound to an Index,", py::arg("num"));
cls_Transfer_ProcessForTransient.def("MapIndex", (Standard_Integer (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &) const) &Transfer_ProcessForTransient::MapIndex, "Returns the Index value bound to a Starting Object, 0 if none", py::arg("start"));
cls_Transfer_ProcessForTransient.def("MapItem", (opencascade::handle<Transfer_Binder> (Transfer_ProcessForTransient::*)(const Standard_Integer) const) &Transfer_ProcessForTransient::MapItem, "Returns the Binder bound to an Index Considers a category number, by default 0", py::arg("num"));
cls_Transfer_ProcessForTransient.def("SetRoot", (void (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &)) &Transfer_ProcessForTransient::SetRoot, "Declares <obj> (and its Result) as Root. This status will be later exploited by RootResult, see below (Result can be produced at any time)", py::arg("start"));
cls_Transfer_ProcessForTransient.def("SetRootManagement", (void (Transfer_ProcessForTransient::*)(const Standard_Boolean)) &Transfer_ProcessForTransient::SetRootManagement, "Enable (if <stat> True) or Disables (if <stat> False) Root Management. If it is set, Transfers are considered as stacked (a first Transfer commands other Transfers, and so on) and the Transfers commanded by an external caller are 'Root'. Remark : SetRoot can be called whatever this status, on every object. Default is set to True.", py::arg("stat"));
cls_Transfer_ProcessForTransient.def("NbRoots", (Standard_Integer (Transfer_ProcessForTransient::*)() const) &Transfer_ProcessForTransient::NbRoots, "Returns the count of recorded Roots");
cls_Transfer_ProcessForTransient.def("Root", (const opencascade::handle<Standard_Transient> & (Transfer_ProcessForTransient::*)(const Standard_Integer) const) &Transfer_ProcessForTransient::Root, "Returns a Root Entity given its number in the list (1-NbRoots)", py::arg("num"));
cls_Transfer_ProcessForTransient.def("RootItem", (opencascade::handle<Transfer_Binder> (Transfer_ProcessForTransient::*)(const Standard_Integer) const) &Transfer_ProcessForTransient::RootItem, "Returns the Binder bound with a Root Entity given its number Considers a category number, by default 0", py::arg("num"));
cls_Transfer_ProcessForTransient.def("RootIndex", (Standard_Integer (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &) const) &Transfer_ProcessForTransient::RootIndex, "Returns the index in the list of roots for a starting item, or 0 if it is not recorded as a root", py::arg("start"));
cls_Transfer_ProcessForTransient.def("NestingLevel", (Standard_Integer (Transfer_ProcessForTransient::*)() const) &Transfer_ProcessForTransient::NestingLevel, "Returns Nesting Level of Transfers (managed by methods TranscriptWith & Co). Starts to zero. If no automatic Transfer is used, it remains to zero. Zero means Root Level.");
cls_Transfer_ProcessForTransient.def("ResetNestingLevel", (void (Transfer_ProcessForTransient::*)()) &Transfer_ProcessForTransient::ResetNestingLevel, "Resets Nesting Level of Transfers to Zero (Root Level), whatever its current value.");
cls_Transfer_ProcessForTransient.def("Recognize", (Standard_Boolean (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &) const) &Transfer_ProcessForTransient::Recognize, "Tells if <start> has been recognized as good candidate for Transfer. i.e. queries the Actor and its Nexts", py::arg("start"));
cls_Transfer_ProcessForTransient.def("Transferring", (opencascade::handle<Transfer_Binder> (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &)) &Transfer_ProcessForTransient::Transferring, "Performs the Transfer of a Starting Object, by calling the method TransferProduct (see below). Mapping and Roots are managed : nothing is done if a Result is already Bound, an exception is raised in case of error.", py::arg("start"));
cls_Transfer_ProcessForTransient.def("Transfer", (Standard_Boolean (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &)) &Transfer_ProcessForTransient::Transfer, "Same as Transferring but does not return the Binder. Simply returns True in case of success (for user call)", py::arg("start"));
cls_Transfer_ProcessForTransient.def("SetErrorHandle", (void (Transfer_ProcessForTransient::*)(const Standard_Boolean)) &Transfer_ProcessForTransient::SetErrorHandle, "Allows controls if exceptions will be handled Transfer Operations <err> False : they are not handled with try {} catch {} <err> True : they are Default is False: no handling performed", py::arg("err"));
cls_Transfer_ProcessForTransient.def("ErrorHandle", (Standard_Boolean (Transfer_ProcessForTransient::*)() const) &Transfer_ProcessForTransient::ErrorHandle, "Returns error handling flag");
cls_Transfer_ProcessForTransient.def("StartTrace", (void (Transfer_ProcessForTransient::*)(const opencascade::handle<Transfer_Binder> &, const opencascade::handle<Standard_Transient> &, const Standard_Integer, const Standard_Integer) const) &Transfer_ProcessForTransient::StartTrace, "Method called when trace is asked Calls PrintTrace to display information relevant for starting objects (which can be redefined) <level> is Nesting Level of Transfer (0 = root) <mode> controls the way the trace is done : 0 neutral, 1 for Error, 2 for Warning message, 3 for new Root", py::arg("binder"), py::arg("start"), py::arg("level"), py::arg("mode"));
cls_Transfer_ProcessForTransient.def("PrintTrace", (void (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Message_Messenger> &) const) &Transfer_ProcessForTransient::PrintTrace, "Prints a short information on a starting object. By default prints its Dynamic Type. Can be redefined", py::arg("start"), py::arg("S"));
cls_Transfer_ProcessForTransient.def("IsLooping", (Standard_Boolean (Transfer_ProcessForTransient::*)(const Standard_Integer) const) &Transfer_ProcessForTransient::IsLooping, "Returns True if we are surely in a DeadLoop. Evaluation is not exact, it is a 'majorant' which must be computed fast. This 'majorant' is : <alevel> greater than NbMapped.", py::arg("alevel"));
cls_Transfer_ProcessForTransient.def("RootResult", [](Transfer_ProcessForTransient &self) -> Transfer_IteratorOfProcessForTransient { return self.RootResult(); });
cls_Transfer_ProcessForTransient.def("RootResult", (Transfer_IteratorOfProcessForTransient (Transfer_ProcessForTransient::*)(const Standard_Boolean) const) &Transfer_ProcessForTransient::RootResult, "Returns, as an iterator, the log of root transfer, i.e. the created objects and Binders bound to starting roots If withstart is given True, Starting Objets are also returned", py::arg("withstart"));
cls_Transfer_ProcessForTransient.def("CompleteResult", [](Transfer_ProcessForTransient &self) -> Transfer_IteratorOfProcessForTransient { return self.CompleteResult(); });
cls_Transfer_ProcessForTransient.def("CompleteResult", (Transfer_IteratorOfProcessForTransient (Transfer_ProcessForTransient::*)(const Standard_Boolean) const) &Transfer_ProcessForTransient::CompleteResult, "Returns, as an Iterator, the entire log of transfer (list of created objects and Binders which can bring errors) If withstart is given True, Starting Objets are also returned", py::arg("withstart"));
cls_Transfer_ProcessForTransient.def("AbnormalResult", (Transfer_IteratorOfProcessForTransient (Transfer_ProcessForTransient::*)() const) &Transfer_ProcessForTransient::AbnormalResult, "Returns Binders which are neither 'Done' nor 'Initial', that is Error,Loop or Run (abnormal states at end of Transfer) Starting Objects are given in correspondance in the iterator");
cls_Transfer_ProcessForTransient.def("CheckList", (Interface_CheckIterator (Transfer_ProcessForTransient::*)(const Standard_Boolean) const) &Transfer_ProcessForTransient::CheckList, "Returns a CheckList as a list of Check : each one is for a starting entity which have either check (warning or fail) messages are attached, or are in abnormal state : that case gives a specific message If <erronly> is True, checks with Warnings only are ignored", py::arg("erronly"));
cls_Transfer_ProcessForTransient.def("ResultOne", [](Transfer_ProcessForTransient &self, const opencascade::handle<Standard_Transient> & a0, const Standard_Integer a1) -> Transfer_IteratorOfProcessForTransient { return self.ResultOne(a0, a1); });
cls_Transfer_ProcessForTransient.def("ResultOne", (Transfer_IteratorOfProcessForTransient (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer, const Standard_Boolean) const) &Transfer_ProcessForTransient::ResultOne, "Returns, as an Iterator, the log of transfer for one object <level> = 0 : this object only and if <start> is a scope owner (else, <level> is ignored) : <level> = 1 : object plus its immediate scoped ones <level> = 2 : object plus all its scoped ones", py::arg("start"), py::arg("level"), py::arg("withstart"));
cls_Transfer_ProcessForTransient.def("CheckListOne", (Interface_CheckIterator (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer, const Standard_Boolean) const) &Transfer_ProcessForTransient::CheckListOne, "Returns a CheckList for one starting object <level> interpreted as by ResultOne If <erronly> is True, checks with Warnings only are ignored", py::arg("start"), py::arg("level"), py::arg("erronly"));
cls_Transfer_ProcessForTransient.def("IsCheckListEmpty", (Standard_Boolean (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer, const Standard_Boolean) const) &Transfer_ProcessForTransient::IsCheckListEmpty, "Returns True if no check message is attached to a starting object. <level> interpreted as by ResultOne If <erronly> is True, checks with Warnings only are ignored", py::arg("start"), py::arg("level"), py::arg("erronly"));
cls_Transfer_ProcessForTransient.def("RemoveResult", [](Transfer_ProcessForTransient &self, const opencascade::handle<Standard_Transient> & a0, const Standard_Integer a1) -> void { return self.RemoveResult(a0, a1); });
cls_Transfer_ProcessForTransient.def("RemoveResult", (void (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer, const Standard_Boolean)) &Transfer_ProcessForTransient::RemoveResult, "Removes Results attached to (== Unbinds) a given object and, according <level> : <level> = 0 : only it <level> = 1 : it plus its immediately owned sub-results(scope) <level> = 2 : it plus all its owned sub-results(scope)", py::arg("start"), py::arg("level"), py::arg("compute"));
cls_Transfer_ProcessForTransient.def("CheckNum", (Standard_Integer (Transfer_ProcessForTransient::*)(const opencascade::handle<Standard_Transient> &) const) &Transfer_ProcessForTransient::CheckNum, "Computes a number to be associated to a starting object in a check or a check-list By default, returns 0; can be redefined", py::arg("start"));
cls_Transfer_ProcessForTransient.def("SetProgress", (void (Transfer_ProcessForTransient::*)(const opencascade::handle<Message_ProgressIndicator> &)) &Transfer_ProcessForTransient::SetProgress, "Sets Progress indicator", py::arg("theProgress"));
cls_Transfer_ProcessForTransient.def("GetProgress", (opencascade::handle<Message_ProgressIndicator> (Transfer_ProcessForTransient::*)() const) &Transfer_ProcessForTransient::GetProgress, "Gets Progress indicator");
cls_Transfer_ProcessForTransient.def_static("get_type_name_", (const char * (*)()) &Transfer_ProcessForTransient::get_type_name, "None");
cls_Transfer_ProcessForTransient.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_ProcessForTransient::get_type_descriptor, "None");
cls_Transfer_ProcessForTransient.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_ProcessForTransient::*)() const) &Transfer_ProcessForTransient::DynamicType, "None");

// CLASS: TRANSFER_TRANSIENTPROCESS
py::class_<Transfer_TransientProcess, opencascade::handle<Transfer_TransientProcess>, Transfer_ProcessForTransient> cls_Transfer_TransientProcess(mod, "Transfer_TransientProcess", "Adds specific features to the generic definition : TransientProcess is intended to work from an InterfaceModel to a set of application objects.");

// Constructors
cls_Transfer_TransientProcess.def(py::init<>());
cls_Transfer_TransientProcess.def(py::init<const Standard_Integer>(), py::arg("nb"));

// Methods
cls_Transfer_TransientProcess.def("SetModel", (void (Transfer_TransientProcess::*)(const opencascade::handle<Interface_InterfaceModel> &)) &Transfer_TransientProcess::SetModel, "Sets an InterfaceModel, used by StartTrace, CheckList, queries on Integrity, to give informations significant for each norm.", py::arg("model"));
cls_Transfer_TransientProcess.def("Model", (opencascade::handle<Interface_InterfaceModel> (Transfer_TransientProcess::*)() const) &Transfer_TransientProcess::Model, "Returns the Model used for StartTrace");
cls_Transfer_TransientProcess.def("SetGraph", (void (Transfer_TransientProcess::*)(const opencascade::handle<Interface_HGraph> &)) &Transfer_TransientProcess::SetGraph, "Sets a Graph : superseedes SetModel if already done", py::arg("HG"));
cls_Transfer_TransientProcess.def("HasGraph", (Standard_Boolean (Transfer_TransientProcess::*)() const) &Transfer_TransientProcess::HasGraph, "None");
cls_Transfer_TransientProcess.def("HGraph", (opencascade::handle<Interface_HGraph> (Transfer_TransientProcess::*)() const) &Transfer_TransientProcess::HGraph, "None");
cls_Transfer_TransientProcess.def("Graph", (const Interface_Graph & (Transfer_TransientProcess::*)() const) &Transfer_TransientProcess::Graph, "None");
cls_Transfer_TransientProcess.def("SetContext", (void (Transfer_TransientProcess::*)(const Standard_CString, const opencascade::handle<Standard_Transient> &)) &Transfer_TransientProcess::SetContext, "Sets a Context : according to receiving appli, to be interpreted by the Actor", py::arg("name"), py::arg("ctx"));
cls_Transfer_TransientProcess.def("GetContext", (Standard_Boolean (Transfer_TransientProcess::*)(const Standard_CString, const opencascade::handle<Standard_Type> &, opencascade::handle<Standard_Transient> &) const) &Transfer_TransientProcess::GetContext, "Returns the Context attached to a name, if set and if it is Kind of the type, else a Null Handle Returns True if OK, False if no Context", py::arg("name"), py::arg("type"), py::arg("ctx"));
cls_Transfer_TransientProcess.def("Context", (NCollection_DataMap<TCollection_AsciiString, opencascade::handle<Standard_Transient> > & (Transfer_TransientProcess::*)()) &Transfer_TransientProcess::Context, "Returns (modifiable) the whole definition of Context Rather for internal use (ex.: preparing and setting in once)");
cls_Transfer_TransientProcess.def("PrintTrace", (void (Transfer_TransientProcess::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Message_Messenger> &) const) &Transfer_TransientProcess::PrintTrace, "Specific printing to trace an entity : prints label and type (if model is set)", py::arg("start"), py::arg("S"));
cls_Transfer_TransientProcess.def("CheckNum", (Standard_Integer (Transfer_TransientProcess::*)(const opencascade::handle<Standard_Transient> &) const) &Transfer_TransientProcess::CheckNum, "Specific number of a starting object for check-list : Number in model", py::arg("ent"));
cls_Transfer_TransientProcess.def("TypedSharings", (Interface_EntityIterator (Transfer_TransientProcess::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Type> &) const) &Transfer_TransientProcess::TypedSharings, "Returns the list of sharings entities, AT ANY LEVEL, which are kind of a given type. Calls TypedSharings from Graph Returns an empty list if the Graph has not been aknowledged", py::arg("start"), py::arg("type"));
cls_Transfer_TransientProcess.def("IsDataLoaded", (Standard_Boolean (Transfer_TransientProcess::*)(const opencascade::handle<Standard_Transient> &) const) &Transfer_TransientProcess::IsDataLoaded, "Tells if an entity is well loaded from file (even if its data fail on checking, they are present). Mostly often, answers True. Else, there was a syntactic error in the file. A non-loaded entity MAY NOT BE transferred, unless its Report (in the model) is interpreted", py::arg("ent"));
cls_Transfer_TransientProcess.def("IsDataFail", (Standard_Boolean (Transfer_TransientProcess::*)(const opencascade::handle<Standard_Transient> &) const) &Transfer_TransientProcess::IsDataFail, "Tells if an entity fails on data checking (load time, syntactic, or semantic check). Normally, should answer False. It is not prudent to try transferring an entity which fails on data checking", py::arg("ent"));
cls_Transfer_TransientProcess.def("PrintStats", (void (Transfer_TransientProcess::*)(const Standard_Integer, const opencascade::handle<Message_Messenger> &) const) &Transfer_TransientProcess::PrintStats, "Prints statistics on a given output, according mode", py::arg("mode"), py::arg("S"));
cls_Transfer_TransientProcess.def("RootsForTransfer", (opencascade::handle<TColStd_HSequenceOfTransient> (Transfer_TransientProcess::*)()) &Transfer_TransientProcess::RootsForTransfer, "None");
cls_Transfer_TransientProcess.def_static("get_type_name_", (const char * (*)()) &Transfer_TransientProcess::get_type_name, "None");
cls_Transfer_TransientProcess.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_TransientProcess::get_type_descriptor, "None");
cls_Transfer_TransientProcess.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_TransientProcess::*)() const) &Transfer_TransientProcess::DynamicType, "None");

// CLASS: TRANSFER_ACTOROFPROCESSFORTRANSIENT
py::class_<Transfer_ActorOfProcessForTransient, opencascade::handle<Transfer_ActorOfProcessForTransient>, Standard_Transient> cls_Transfer_ActorOfProcessForTransient(mod, "Transfer_ActorOfProcessForTransient", "None");

// Constructors
cls_Transfer_ActorOfProcessForTransient.def(py::init<>());

// Methods
cls_Transfer_ActorOfProcessForTransient.def("Recognize", (Standard_Boolean (Transfer_ActorOfProcessForTransient::*)(const opencascade::handle<Standard_Transient> &)) &Transfer_ActorOfProcessForTransient::Recognize, "Prerequesite for Transfer : the method Transfer is called on a starting object only if Recognize has returned True on it This allows to define a list of Actors, each one processing a definite kind of data TransferProcess calls Recognize on each one before calling Transfer. But even if Recognize has returned True, Transfer can reject by returning a Null Binder (afterwards rejection), the next actor is then invoked", py::arg("start"));
cls_Transfer_ActorOfProcessForTransient.def("Transferring", (opencascade::handle<Transfer_Binder> (Transfer_ActorOfProcessForTransient::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Transfer_ProcessForTransient> &)) &Transfer_ActorOfProcessForTransient::Transferring, "Specific action of Transfer. The Result is stored in the returned Binder, or a Null Handle for 'No result' (Default defined as doing nothing; should be deffered) 'mutable' allows the Actor to record intermediate information, in addition to those of TransferProcess", py::arg("start"), py::arg("TP"));
cls_Transfer_ActorOfProcessForTransient.def("TransientResult", (opencascade::handle<Transfer_SimpleBinderOfTransient> (Transfer_ActorOfProcessForTransient::*)(const opencascade::handle<Standard_Transient> &) const) &Transfer_ActorOfProcessForTransient::TransientResult, "Prepares and Returns a Binder for a Transient Result Returns a Null Handle if <res> is itself Null", py::arg("res"));
cls_Transfer_ActorOfProcessForTransient.def("NullResult", (opencascade::handle<Transfer_Binder> (Transfer_ActorOfProcessForTransient::*)() const) &Transfer_ActorOfProcessForTransient::NullResult, "Returns a Binder for No Result, i.e. a Null Handle");
cls_Transfer_ActorOfProcessForTransient.def("SetLast", [](Transfer_ActorOfProcessForTransient &self) -> void { return self.SetLast(); });
cls_Transfer_ActorOfProcessForTransient.def("SetLast", (void (Transfer_ActorOfProcessForTransient::*)(const Standard_Boolean)) &Transfer_ActorOfProcessForTransient::SetLast, "If <mode> is True, commands an Actor to be set at the end of the list of Actors (see SetNext) If it is False (creation default), each add Actor is set at the beginning of the list This allows to define default Actors (which are Last)", py::arg("mode"));
cls_Transfer_ActorOfProcessForTransient.def("IsLast", (Standard_Boolean (Transfer_ActorOfProcessForTransient::*)() const) &Transfer_ActorOfProcessForTransient::IsLast, "Returns the Last status (see SetLast).");
cls_Transfer_ActorOfProcessForTransient.def("SetNext", (void (Transfer_ActorOfProcessForTransient::*)(const opencascade::handle<Transfer_ActorOfProcessForTransient> &)) &Transfer_ActorOfProcessForTransient::SetNext, "Defines a Next Actor : it can then be asked to work if <me> produces no result for a given type of Object. If Next is already set and is not 'Last', calls SetNext on it. If Next defined and 'Last', the new actor is added before it in the list", py::arg("next"));
cls_Transfer_ActorOfProcessForTransient.def("Next", (opencascade::handle<Transfer_ActorOfProcessForTransient> (Transfer_ActorOfProcessForTransient::*)() const) &Transfer_ActorOfProcessForTransient::Next, "Returns the Actor defined as Next, or a Null Handle");
cls_Transfer_ActorOfProcessForTransient.def_static("get_type_name_", (const char * (*)()) &Transfer_ActorOfProcessForTransient::get_type_name, "None");
cls_Transfer_ActorOfProcessForTransient.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_ActorOfProcessForTransient::get_type_descriptor, "None");
cls_Transfer_ActorOfProcessForTransient.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_ActorOfProcessForTransient::*)() const) &Transfer_ActorOfProcessForTransient::DynamicType, "None");

// CLASS: TRANSFER_ACTOROFTRANSIENTPROCESS
py::class_<Transfer_ActorOfTransientProcess, opencascade::handle<Transfer_ActorOfTransientProcess>, Transfer_ActorOfProcessForTransient> cls_Transfer_ActorOfTransientProcess(mod, "Transfer_ActorOfTransientProcess", "The original class was renamed. Compatibility only");

// Constructors
cls_Transfer_ActorOfTransientProcess.def(py::init<>());

// Methods
cls_Transfer_ActorOfTransientProcess.def("Transferring", (opencascade::handle<Transfer_Binder> (Transfer_ActorOfTransientProcess::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Transfer_ProcessForTransient> &)) &Transfer_ActorOfTransientProcess::Transferring, "None", py::arg("start"), py::arg("TP"));
cls_Transfer_ActorOfTransientProcess.def("Transfer", (opencascade::handle<Transfer_Binder> (Transfer_ActorOfTransientProcess::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Transfer_TransientProcess> &)) &Transfer_ActorOfTransientProcess::Transfer, "None", py::arg("start"), py::arg("TP"));
cls_Transfer_ActorOfTransientProcess.def("TransferTransient", (opencascade::handle<Standard_Transient> (Transfer_ActorOfTransientProcess::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Transfer_TransientProcess> &)) &Transfer_ActorOfTransientProcess::TransferTransient, "None", py::arg("start"), py::arg("TP"));
cls_Transfer_ActorOfTransientProcess.def_static("get_type_name_", (const char * (*)()) &Transfer_ActorOfTransientProcess::get_type_name, "None");
cls_Transfer_ActorOfTransientProcess.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_ActorOfTransientProcess::get_type_descriptor, "None");
cls_Transfer_ActorOfTransientProcess.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_ActorOfTransientProcess::*)() const) &Transfer_ActorOfTransientProcess::DynamicType, "None");

// CLASS: TRANSFER_PROCESSFORFINDER
py::class_<Transfer_ProcessForFinder, opencascade::handle<Transfer_ProcessForFinder>, Standard_Transient> cls_Transfer_ProcessForFinder(mod, "Transfer_ProcessForFinder", "None");

// Constructors
cls_Transfer_ProcessForFinder.def(py::init<>());
cls_Transfer_ProcessForFinder.def(py::init<const Standard_Integer>(), py::arg("nb"));
cls_Transfer_ProcessForFinder.def(py::init<const opencascade::handle<Message_Messenger> &>(), py::arg("printer"));
cls_Transfer_ProcessForFinder.def(py::init<const opencascade::handle<Message_Messenger> &, const Standard_Integer>(), py::arg("printer"), py::arg("nb"));

// Methods
cls_Transfer_ProcessForFinder.def("Clear", (void (Transfer_ProcessForFinder::*)()) &Transfer_ProcessForFinder::Clear, "Resets a TransferProcess as ready for a completely new work. Clears general data (roots) and the Map");
cls_Transfer_ProcessForFinder.def("Clean", (void (Transfer_ProcessForFinder::*)()) &Transfer_ProcessForFinder::Clean, "Rebuilds the Map and the roots to really remove Unbound items Because Unbind keeps the entity in place, even if not bound Hence, working by checking new items is meaningless if a formerly unbound item is rebound");
cls_Transfer_ProcessForFinder.def("Resize", (void (Transfer_ProcessForFinder::*)(const Standard_Integer)) &Transfer_ProcessForFinder::Resize, "Resizes the Map as required (if a new reliable value has been determined). Acts only if <nb> is greater than actual NbMapped", py::arg("nb"));
cls_Transfer_ProcessForFinder.def("SetActor", (void (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_ActorOfProcessForFinder> &)) &Transfer_ProcessForFinder::SetActor, "Defines an Actor, which is used for automatic Transfer If already defined, the new Actor is cumulated (see SetNext from Actor)", py::arg("actor"));
cls_Transfer_ProcessForFinder.def("Actor", (opencascade::handle<Transfer_ActorOfProcessForFinder> (Transfer_ProcessForFinder::*)() const) &Transfer_ProcessForFinder::Actor, "Returns the defined Actor. Returns a Null Handle if not set.");
cls_Transfer_ProcessForFinder.def("Find", (opencascade::handle<Transfer_Binder> (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &) const) &Transfer_ProcessForFinder::Find, "Returns the Binder which is linked with a starting Object It can either bring a Result (Transfer done) or none (for a pre-binding). If no Binder is linked with <start>, returns a Null Handle Considers a category number, by default 0", py::arg("start"));
cls_Transfer_ProcessForFinder.def("IsBound", (Standard_Boolean (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &) const) &Transfer_ProcessForFinder::IsBound, "Returns True if a Result (whatever its form) is Bound with a starting Object. I.e., if a Binder with a Result set, is linked with it Considers a category number, by default 0", py::arg("start"));
cls_Transfer_ProcessForFinder.def("IsAlreadyUsed", (Standard_Boolean (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &) const) &Transfer_ProcessForFinder::IsAlreadyUsed, "Returns True if the result of the transfer of an object is already used in other ones. If it is, Rebind cannot change it. Considers a category number, by default 0", py::arg("start"));
cls_Transfer_ProcessForFinder.def("Bind", (void (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &, const opencascade::handle<Transfer_Binder> &)) &Transfer_ProcessForFinder::Bind, "Creates a Link a starting Object with a Binder. This Binder can either bring a Result (effective Binding) or none (it can be set later : pre-binding). Considers a category number, by default 0", py::arg("start"), py::arg("binder"));
cls_Transfer_ProcessForFinder.def("Rebind", (void (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &, const opencascade::handle<Transfer_Binder> &)) &Transfer_ProcessForFinder::Rebind, "Changes the Binder linked with a starting Object for its unitary transfer. This it can be useful when the exact form of the result is known once the transfer is widely engaged. This can be done only on first transfer. Considers a category number, by default 0", py::arg("start"), py::arg("binder"));
cls_Transfer_ProcessForFinder.def("Unbind", (Standard_Boolean (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &)) &Transfer_ProcessForFinder::Unbind, "Removes the Binder linked with a starting object If this Binder brings a non-empty Check, it is replaced by a VoidBinder. Also removes from the list of Roots as required. Returns True if done, False if <start> was not bound Considers a category number, by default 0", py::arg("start"));
cls_Transfer_ProcessForFinder.def("FindElseBind", (opencascade::handle<Transfer_Binder> (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &)) &Transfer_ProcessForFinder::FindElseBind, "Returns a Binder for a starting entity, as follows : Tries to Find the already bound one If none found, creates a VoidBinder and Binds it", py::arg("start"));
cls_Transfer_ProcessForFinder.def("SetMessenger", (void (Transfer_ProcessForFinder::*)(const opencascade::handle<Message_Messenger> &)) &Transfer_ProcessForFinder::SetMessenger, "Sets Messenger used for outputting messages.", py::arg("messenger"));
cls_Transfer_ProcessForFinder.def("Messenger", (opencascade::handle<Message_Messenger> (Transfer_ProcessForFinder::*)() const) &Transfer_ProcessForFinder::Messenger, "Returns Messenger used for outputting messages. The returned object is guaranteed to be non-null; default is Message::Messenger().");
cls_Transfer_ProcessForFinder.def("SetTraceLevel", (void (Transfer_ProcessForFinder::*)(const Standard_Integer)) &Transfer_ProcessForFinder::SetTraceLevel, "Sets trace level used for outputting messages: <trace> = 0 : no trace at all <trace> = 1 : handled exceptions and calls to AddError <trace> = 2 : also calls to AddWarning <trace> = 3 : also traces new Roots (uses method ErrorTrace). Default is 1 : Errors traced", py::arg("tracelev"));
cls_Transfer_ProcessForFinder.def("TraceLevel", (Standard_Integer (Transfer_ProcessForFinder::*)() const) &Transfer_ProcessForFinder::TraceLevel, "Returns trace level used for outputting messages.");
cls_Transfer_ProcessForFinder.def("SendFail", (void (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &, const Message_Msg &)) &Transfer_ProcessForFinder::SendFail, "New name for AddFail (Msg)", py::arg("start"), py::arg("amsg"));
cls_Transfer_ProcessForFinder.def("SendWarning", (void (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &, const Message_Msg &)) &Transfer_ProcessForFinder::SendWarning, "New name for AddWarning (Msg)", py::arg("start"), py::arg("amsg"));
cls_Transfer_ProcessForFinder.def("SendMsg", (void (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &, const Message_Msg &)) &Transfer_ProcessForFinder::SendMsg, "Adds an information message Trace is filled if trace level is at least 3", py::arg("start"), py::arg("amsg"));
cls_Transfer_ProcessForFinder.def("AddFail", [](Transfer_ProcessForFinder &self, const opencascade::handle<Transfer_Finder> & a0, const Standard_CString a1) -> void { return self.AddFail(a0, a1); });
cls_Transfer_ProcessForFinder.def("AddFail", (void (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &, const Standard_CString, const Standard_CString)) &Transfer_ProcessForFinder::AddFail, "Adds an Error message to a starting entity (to the check of its Binder of category 0, as a Fail)", py::arg("start"), py::arg("mess"), py::arg("orig"));
cls_Transfer_ProcessForFinder.def("AddError", [](Transfer_ProcessForFinder &self, const opencascade::handle<Transfer_Finder> & a0, const Standard_CString a1) -> void { return self.AddError(a0, a1); });
cls_Transfer_ProcessForFinder.def("AddError", (void (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &, const Standard_CString, const Standard_CString)) &Transfer_ProcessForFinder::AddError, "(other name of AddFail, maintained for compatibility)", py::arg("start"), py::arg("mess"), py::arg("orig"));
cls_Transfer_ProcessForFinder.def("AddFail", (void (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &, const Message_Msg &)) &Transfer_ProcessForFinder::AddFail, "Adds an Error Message to a starting entity from the definition of a Msg (Original+Value)", py::arg("start"), py::arg("amsg"));
cls_Transfer_ProcessForFinder.def("AddWarning", [](Transfer_ProcessForFinder &self, const opencascade::handle<Transfer_Finder> & a0, const Standard_CString a1) -> void { return self.AddWarning(a0, a1); });
cls_Transfer_ProcessForFinder.def("AddWarning", (void (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &, const Standard_CString, const Standard_CString)) &Transfer_ProcessForFinder::AddWarning, "Adds a Warning message to a starting entity (to the check of its Binder of category 0)", py::arg("start"), py::arg("mess"), py::arg("orig"));
cls_Transfer_ProcessForFinder.def("AddWarning", (void (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &, const Message_Msg &)) &Transfer_ProcessForFinder::AddWarning, "Adds a Warning Message to a starting entity from the definition of a Msg (Original+Value)", py::arg("start"), py::arg("amsg"));
cls_Transfer_ProcessForFinder.def("Mend", [](Transfer_ProcessForFinder &self, const opencascade::handle<Transfer_Finder> & a0) -> void { return self.Mend(a0); });
cls_Transfer_ProcessForFinder.def("Mend", (void (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &, const Standard_CString)) &Transfer_ProcessForFinder::Mend, "None", py::arg("start"), py::arg("pref"));
cls_Transfer_ProcessForFinder.def("Check", (opencascade::handle<Interface_Check> (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &) const) &Transfer_ProcessForFinder::Check, "Returns the Check attached to a starting entity. If <start> is unknown, returns an empty Check Adds a case name to a starting entity Adds a case value to a starting entity Returns the complete case list for an entity. Null Handle if empty In the list of mapped items (between 1 and NbMapped), searches for the first item which follows <num0>(not included) and which has an attribute named <name> Attributes are brought by Binders Hence, allows such an iteration", py::arg("start"));
cls_Transfer_ProcessForFinder.def("BindTransient", (void (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &, const opencascade::handle<Standard_Transient> &)) &Transfer_ProcessForFinder::BindTransient, "Binds a starting object with a Transient Result. Uses a SimpleBinderOfTransient to work. If there is already one but with no Result set, sets its Result. Considers a category number, by default 0", py::arg("start"), py::arg("res"));
cls_Transfer_ProcessForFinder.def("FindTransient", (const opencascade::handle<Standard_Transient> & (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &) const) &Transfer_ProcessForFinder::FindTransient, "Returns the Result of the Transfer of an object <start> as a Transient Result. Returns a Null Handle if there is no Transient Result Considers a category number, by default 0 Warning : Supposes that Binding is done with a SimpleBinderOfTransient", py::arg("start"));
cls_Transfer_ProcessForFinder.def("BindMultiple", (void (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &)) &Transfer_ProcessForFinder::BindMultiple, "Prepares an object <start> to be bound with several results. If no Binder is yet attached to <obj>, a MultipleBinder is created, empty. If a Binder is already set, it must accept Multiple Binding. Considers a category number, by default 0", py::arg("start"));
cls_Transfer_ProcessForFinder.def("AddMultiple", (void (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &, const opencascade::handle<Standard_Transient> &)) &Transfer_ProcessForFinder::AddMultiple, "Adds an item to a list of results bound to a starting object. Considers a category number, by default 0, for all results", py::arg("start"), py::arg("res"));
cls_Transfer_ProcessForFinder.def("FindTypedTransient", (Standard_Boolean (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &, const opencascade::handle<Standard_Type> &, opencascade::handle<Standard_Transient> &) const) &Transfer_ProcessForFinder::FindTypedTransient, "Searches for a transient result attached to a starting object, according to its type, by criterium IsKind(atype)", py::arg("start"), py::arg("atype"), py::arg("val"));
cls_Transfer_ProcessForFinder.def("GetTypedTransient", (Standard_Boolean (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Binder> &, const opencascade::handle<Standard_Type> &, opencascade::handle<Standard_Transient> &) const) &Transfer_ProcessForFinder::GetTypedTransient, "Searches for a transient result recorded in a Binder, whatever this Binder is recorded or not in <me>", py::arg("binder"), py::arg("atype"), py::arg("val"));
cls_Transfer_ProcessForFinder.def("NbMapped", (Standard_Integer (Transfer_ProcessForFinder::*)() const) &Transfer_ProcessForFinder::NbMapped, "Returns the maximum possible value for Map Index (no result can be bound with a value greater than it)");
cls_Transfer_ProcessForFinder.def("Mapped", (const opencascade::handle<Transfer_Finder> & (Transfer_ProcessForFinder::*)(const Standard_Integer) const) &Transfer_ProcessForFinder::Mapped, "Returns the Starting Object bound to an Index,", py::arg("num"));
cls_Transfer_ProcessForFinder.def("MapIndex", (Standard_Integer (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &) const) &Transfer_ProcessForFinder::MapIndex, "Returns the Index value bound to a Starting Object, 0 if none", py::arg("start"));
cls_Transfer_ProcessForFinder.def("MapItem", (opencascade::handle<Transfer_Binder> (Transfer_ProcessForFinder::*)(const Standard_Integer) const) &Transfer_ProcessForFinder::MapItem, "Returns the Binder bound to an Index Considers a category number, by default 0", py::arg("num"));
cls_Transfer_ProcessForFinder.def("SetRoot", (void (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &)) &Transfer_ProcessForFinder::SetRoot, "Declares <obj> (and its Result) as Root. This status will be later exploited by RootResult, see below (Result can be produced at any time)", py::arg("start"));
cls_Transfer_ProcessForFinder.def("SetRootManagement", (void (Transfer_ProcessForFinder::*)(const Standard_Boolean)) &Transfer_ProcessForFinder::SetRootManagement, "Enable (if <stat> True) or Disables (if <stat> False) Root Management. If it is set, Transfers are considered as stacked (a first Transfer commands other Transfers, and so on) and the Transfers commanded by an external caller are 'Root'. Remark : SetRoot can be called whatever this status, on every object. Default is set to True.", py::arg("stat"));
cls_Transfer_ProcessForFinder.def("NbRoots", (Standard_Integer (Transfer_ProcessForFinder::*)() const) &Transfer_ProcessForFinder::NbRoots, "Returns the count of recorded Roots");
cls_Transfer_ProcessForFinder.def("Root", (const opencascade::handle<Transfer_Finder> & (Transfer_ProcessForFinder::*)(const Standard_Integer) const) &Transfer_ProcessForFinder::Root, "Returns a Root Entity given its number in the list (1-NbRoots)", py::arg("num"));
cls_Transfer_ProcessForFinder.def("RootItem", (opencascade::handle<Transfer_Binder> (Transfer_ProcessForFinder::*)(const Standard_Integer) const) &Transfer_ProcessForFinder::RootItem, "Returns the Binder bound with a Root Entity given its number Considers a category number, by default 0", py::arg("num"));
cls_Transfer_ProcessForFinder.def("RootIndex", (Standard_Integer (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &) const) &Transfer_ProcessForFinder::RootIndex, "Returns the index in the list of roots for a starting item, or 0 if it is not recorded as a root", py::arg("start"));
cls_Transfer_ProcessForFinder.def("NestingLevel", (Standard_Integer (Transfer_ProcessForFinder::*)() const) &Transfer_ProcessForFinder::NestingLevel, "Returns Nesting Level of Transfers (managed by methods TranscriptWith & Co). Starts to zero. If no automatic Transfer is used, it remains to zero. Zero means Root Level.");
cls_Transfer_ProcessForFinder.def("ResetNestingLevel", (void (Transfer_ProcessForFinder::*)()) &Transfer_ProcessForFinder::ResetNestingLevel, "Resets Nesting Level of Transfers to Zero (Root Level), whatever its current value.");
cls_Transfer_ProcessForFinder.def("Recognize", (Standard_Boolean (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &) const) &Transfer_ProcessForFinder::Recognize, "Tells if <start> has been recognized as good candidate for Transfer. i.e. queries the Actor and its Nexts", py::arg("start"));
cls_Transfer_ProcessForFinder.def("Transferring", (opencascade::handle<Transfer_Binder> (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &)) &Transfer_ProcessForFinder::Transferring, "Performs the Transfer of a Starting Object, by calling the method TransferProduct (see below). Mapping and Roots are managed : nothing is done if a Result is already Bound, an exception is raised in case of error.", py::arg("start"));
cls_Transfer_ProcessForFinder.def("Transfer", (Standard_Boolean (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &)) &Transfer_ProcessForFinder::Transfer, "Same as Transferring but does not return the Binder. Simply returns True in case of success (for user call)", py::arg("start"));
cls_Transfer_ProcessForFinder.def("SetErrorHandle", (void (Transfer_ProcessForFinder::*)(const Standard_Boolean)) &Transfer_ProcessForFinder::SetErrorHandle, "Allows controls if exceptions will be handled Transfer Operations <err> False : they are not handled with try {} catch {} <err> True : they are Default is False: no handling performed", py::arg("err"));
cls_Transfer_ProcessForFinder.def("ErrorHandle", (Standard_Boolean (Transfer_ProcessForFinder::*)() const) &Transfer_ProcessForFinder::ErrorHandle, "Returns error handling flag");
cls_Transfer_ProcessForFinder.def("StartTrace", (void (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Binder> &, const opencascade::handle<Transfer_Finder> &, const Standard_Integer, const Standard_Integer) const) &Transfer_ProcessForFinder::StartTrace, "Method called when trace is asked Calls PrintTrace to display information relevant for starting objects (which can be redefined) <level> is Nesting Level of Transfer (0 = root) <mode> controls the way the trace is done : 0 neutral, 1 for Error, 2 for Warning message, 3 for new Root", py::arg("binder"), py::arg("start"), py::arg("level"), py::arg("mode"));
cls_Transfer_ProcessForFinder.def("PrintTrace", (void (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &, const opencascade::handle<Message_Messenger> &) const) &Transfer_ProcessForFinder::PrintTrace, "Prints a short information on a starting object. By default prints its Dynamic Type. Can be redefined", py::arg("start"), py::arg("S"));
cls_Transfer_ProcessForFinder.def("IsLooping", (Standard_Boolean (Transfer_ProcessForFinder::*)(const Standard_Integer) const) &Transfer_ProcessForFinder::IsLooping, "Returns True if we are surely in a DeadLoop. Evaluation is not exact, it is a 'majorant' which must be computed fast. This 'majorant' is : <alevel> greater than NbMapped.", py::arg("alevel"));
cls_Transfer_ProcessForFinder.def("RootResult", [](Transfer_ProcessForFinder &self) -> Transfer_IteratorOfProcessForFinder { return self.RootResult(); });
cls_Transfer_ProcessForFinder.def("RootResult", (Transfer_IteratorOfProcessForFinder (Transfer_ProcessForFinder::*)(const Standard_Boolean) const) &Transfer_ProcessForFinder::RootResult, "Returns, as an iterator, the log of root transfer, i.e. the created objects and Binders bound to starting roots If withstart is given True, Starting Objets are also returned", py::arg("withstart"));
cls_Transfer_ProcessForFinder.def("CompleteResult", [](Transfer_ProcessForFinder &self) -> Transfer_IteratorOfProcessForFinder { return self.CompleteResult(); });
cls_Transfer_ProcessForFinder.def("CompleteResult", (Transfer_IteratorOfProcessForFinder (Transfer_ProcessForFinder::*)(const Standard_Boolean) const) &Transfer_ProcessForFinder::CompleteResult, "Returns, as an Iterator, the entire log of transfer (list of created objects and Binders which can bring errors) If withstart is given True, Starting Objets are also returned", py::arg("withstart"));
cls_Transfer_ProcessForFinder.def("AbnormalResult", (Transfer_IteratorOfProcessForFinder (Transfer_ProcessForFinder::*)() const) &Transfer_ProcessForFinder::AbnormalResult, "Returns Binders which are neither 'Done' nor 'Initial', that is Error,Loop or Run (abnormal states at end of Transfer) Starting Objects are given in correspondance in the iterator");
cls_Transfer_ProcessForFinder.def("CheckList", (Interface_CheckIterator (Transfer_ProcessForFinder::*)(const Standard_Boolean) const) &Transfer_ProcessForFinder::CheckList, "Returns a CheckList as a list of Check : each one is for a starting entity which have either check (warning or fail) messages are attached, or are in abnormal state : that case gives a specific message If <erronly> is True, checks with Warnings only are ignored", py::arg("erronly"));
cls_Transfer_ProcessForFinder.def("ResultOne", [](Transfer_ProcessForFinder &self, const opencascade::handle<Transfer_Finder> & a0, const Standard_Integer a1) -> Transfer_IteratorOfProcessForFinder { return self.ResultOne(a0, a1); });
cls_Transfer_ProcessForFinder.def("ResultOne", (Transfer_IteratorOfProcessForFinder (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &, const Standard_Integer, const Standard_Boolean) const) &Transfer_ProcessForFinder::ResultOne, "Returns, as an Iterator, the log of transfer for one object <level> = 0 : this object only and if <start> is a scope owner (else, <level> is ignored) : <level> = 1 : object plus its immediate scoped ones <level> = 2 : object plus all its scoped ones", py::arg("start"), py::arg("level"), py::arg("withstart"));
cls_Transfer_ProcessForFinder.def("CheckListOne", (Interface_CheckIterator (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &, const Standard_Integer, const Standard_Boolean) const) &Transfer_ProcessForFinder::CheckListOne, "Returns a CheckList for one starting object <level> interpreted as by ResultOne If <erronly> is True, checks with Warnings only are ignored", py::arg("start"), py::arg("level"), py::arg("erronly"));
cls_Transfer_ProcessForFinder.def("IsCheckListEmpty", (Standard_Boolean (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &, const Standard_Integer, const Standard_Boolean) const) &Transfer_ProcessForFinder::IsCheckListEmpty, "Returns True if no check message is attached to a starting object. <level> interpreted as by ResultOne If <erronly> is True, checks with Warnings only are ignored", py::arg("start"), py::arg("level"), py::arg("erronly"));
cls_Transfer_ProcessForFinder.def("RemoveResult", [](Transfer_ProcessForFinder &self, const opencascade::handle<Transfer_Finder> & a0, const Standard_Integer a1) -> void { return self.RemoveResult(a0, a1); });
cls_Transfer_ProcessForFinder.def("RemoveResult", (void (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &, const Standard_Integer, const Standard_Boolean)) &Transfer_ProcessForFinder::RemoveResult, "Removes Results attached to (== Unbinds) a given object and, according <level> : <level> = 0 : only it <level> = 1 : it plus its immediately owned sub-results(scope) <level> = 2 : it plus all its owned sub-results(scope)", py::arg("start"), py::arg("level"), py::arg("compute"));
cls_Transfer_ProcessForFinder.def("CheckNum", (Standard_Integer (Transfer_ProcessForFinder::*)(const opencascade::handle<Transfer_Finder> &) const) &Transfer_ProcessForFinder::CheckNum, "Computes a number to be associated to a starting object in a check or a check-list By default, returns 0; can be redefined", py::arg("start"));
cls_Transfer_ProcessForFinder.def("SetProgress", (void (Transfer_ProcessForFinder::*)(const opencascade::handle<Message_ProgressIndicator> &)) &Transfer_ProcessForFinder::SetProgress, "Sets Progress indicator", py::arg("theProgress"));
cls_Transfer_ProcessForFinder.def("GetProgress", (opencascade::handle<Message_ProgressIndicator> (Transfer_ProcessForFinder::*)() const) &Transfer_ProcessForFinder::GetProgress, "Gets Progress indicator");
cls_Transfer_ProcessForFinder.def_static("get_type_name_", (const char * (*)()) &Transfer_ProcessForFinder::get_type_name, "None");
cls_Transfer_ProcessForFinder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_ProcessForFinder::get_type_descriptor, "None");
cls_Transfer_ProcessForFinder.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_ProcessForFinder::*)() const) &Transfer_ProcessForFinder::DynamicType, "None");

// CLASS: TRANSFER_FINDERPROCESS
py::class_<Transfer_FinderProcess, opencascade::handle<Transfer_FinderProcess>, Transfer_ProcessForFinder> cls_Transfer_FinderProcess(mod, "Transfer_FinderProcess", "Adds specific features to the generic definition : PrintTrace is adapted");

// Constructors
cls_Transfer_FinderProcess.def(py::init<>());
cls_Transfer_FinderProcess.def(py::init<const Standard_Integer>(), py::arg("nb"));

// Methods
cls_Transfer_FinderProcess.def("SetModel", (void (Transfer_FinderProcess::*)(const opencascade::handle<Interface_InterfaceModel> &)) &Transfer_FinderProcess::SetModel, "Sets an InterfaceModel, which can be used during transfer for instance if a context must be managed, it is in the Model", py::arg("model"));
cls_Transfer_FinderProcess.def("Model", (opencascade::handle<Interface_InterfaceModel> (Transfer_FinderProcess::*)() const) &Transfer_FinderProcess::Model, "Returns the Model which can be used for context");
cls_Transfer_FinderProcess.def("NextMappedWithAttribute", (Standard_Integer (Transfer_FinderProcess::*)(const Standard_CString, const Standard_Integer) const) &Transfer_FinderProcess::NextMappedWithAttribute, "In the list of mapped items (between 1 and NbMapped), searches for the first mapped item which follows <num0> (not included) and which has an attribute named <name> The considered Attributes are those brought by Finders,i.e. by Input data. While NextItemWithAttribute works on Result data (Binders)", py::arg("name"), py::arg("num0"));
cls_Transfer_FinderProcess.def("TransientMapper", (opencascade::handle<Transfer_TransientMapper> (Transfer_FinderProcess::*)(const opencascade::handle<Standard_Transient> &) const) &Transfer_FinderProcess::TransientMapper, "Returns a TransientMapper for a given Transient Object Either <obj> is already mapped, then its Mapper is returned Or it is not, then a new one is created then returned, BUT it is not mapped here (use Bind or FindElseBind to do this)", py::arg("obj"));
cls_Transfer_FinderProcess.def("PrintTrace", (void (Transfer_FinderProcess::*)(const opencascade::handle<Transfer_Finder> &, const opencascade::handle<Message_Messenger> &) const) &Transfer_FinderProcess::PrintTrace, "Specific printing to trace a Finder (by its method ValueType)", py::arg("start"), py::arg("S"));
cls_Transfer_FinderProcess.def("PrintStats", (void (Transfer_FinderProcess::*)(const Standard_Integer, const opencascade::handle<Message_Messenger> &) const) &Transfer_FinderProcess::PrintStats, "Prints statistics on a given output, according mode", py::arg("mode"), py::arg("S"));
cls_Transfer_FinderProcess.def_static("get_type_name_", (const char * (*)()) &Transfer_FinderProcess::get_type_name, "None");
cls_Transfer_FinderProcess.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_FinderProcess::get_type_descriptor, "None");
cls_Transfer_FinderProcess.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_FinderProcess::*)() const) &Transfer_FinderProcess::DynamicType, "None");

// CLASS: TRANSFER_TRANSFEROUTPUT
py::class_<Transfer_TransferOutput> cls_Transfer_TransferOutput(mod, "Transfer_TransferOutput", "A TransferOutput is a Tool which manages the transfer of entities created by an Interface, stored in an InterfaceModel, into a set of Objects suitable for an Application Objects to be transferred are given, by method Transfer (which calls Transfer from TransientProcess) A default action is available to get all roots of the Model Result is given as a TransferIterator (see TransferProcess) Also, it is possible to pilot directly the TransientProcess");

// Constructors
cls_Transfer_TransferOutput.def(py::init<const opencascade::handle<Transfer_ActorOfTransientProcess> &, const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("actor"), py::arg("amodel"));
cls_Transfer_TransferOutput.def(py::init<const opencascade::handle<Transfer_TransientProcess> &, const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("proc"), py::arg("amodel"));

// Methods
// cls_Transfer_TransferOutput.def_static("operator new_", (void * (*)(size_t)) &Transfer_TransferOutput::operator new, "None", py::arg("theSize"));
// cls_Transfer_TransferOutput.def_static("operator delete_", (void (*)(void *)) &Transfer_TransferOutput::operator delete, "None", py::arg("theAddress"));
// cls_Transfer_TransferOutput.def_static("operator new[]_", (void * (*)(size_t)) &Transfer_TransferOutput::operator new[], "None", py::arg("theSize"));
// cls_Transfer_TransferOutput.def_static("operator delete[]_", (void (*)(void *)) &Transfer_TransferOutput::operator delete[], "None", py::arg("theAddress"));
// cls_Transfer_TransferOutput.def_static("operator new_", (void * (*)(size_t, void *)) &Transfer_TransferOutput::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Transfer_TransferOutput.def_static("operator delete_", (void (*)(void *, void *)) &Transfer_TransferOutput::operator delete, "None", py::arg(""), py::arg(""));
cls_Transfer_TransferOutput.def("Model", (opencascade::handle<Interface_InterfaceModel> (Transfer_TransferOutput::*)() const) &Transfer_TransferOutput::Model, "Returns the Starting Model");
cls_Transfer_TransferOutput.def("TransientProcess", (opencascade::handle<Transfer_TransientProcess> (Transfer_TransferOutput::*)() const) &Transfer_TransferOutput::TransientProcess, "Returns the TransientProcess used to work");
cls_Transfer_TransferOutput.def("Transfer", (void (Transfer_TransferOutput::*)(const opencascade::handle<Standard_Transient> &)) &Transfer_TransferOutput::Transfer, "Transfer checks that all taken Entities come from the same Model, then calls Transfer from TransientProcess", py::arg("obj"));
cls_Transfer_TransferOutput.def("TransferRoots", (void (Transfer_TransferOutput::*)(const opencascade::handle<Interface_Protocol> &)) &Transfer_TransferOutput::TransferRoots, "Runs transfer on the roots of the Interface Model The Roots are computed with a ShareFlags created from a Protocol given as Argument", py::arg("protocol"));
cls_Transfer_TransferOutput.def("TransferRoots", (void (Transfer_TransferOutput::*)(const Interface_Graph &)) &Transfer_TransferOutput::TransferRoots, "Runs transfer on the roots defined by a Graph of dependences (which detains also a Model and its Entities) Roots are computed with a ShareFlags created from the Graph", py::arg("G"));
cls_Transfer_TransferOutput.def("TransferRoots", (void (Transfer_TransferOutput::*)()) &Transfer_TransferOutput::TransferRoots, "Runs transfer on the roots of the Interface Model Remark : the Roots are computed with a ShareFlags created from the Active Protocol");
cls_Transfer_TransferOutput.def("ListForStatus", [](Transfer_TransferOutput &self, const Standard_Boolean a0) -> Interface_EntityIterator { return self.ListForStatus(a0); });
cls_Transfer_TransferOutput.def("ListForStatus", (Interface_EntityIterator (Transfer_TransferOutput::*)(const Standard_Boolean, const Standard_Boolean) const) &Transfer_TransferOutput::ListForStatus, "Returns the list of Starting Entities with these criteria : - <normal> False, gives the entities bound with ABNORMAL STATUS (e.g. : Fail recorded, Exception raised during Transfer) - <normal> True, gives Entities with or without a Result, but with no Fail, no Exception (Warnings are not counted) - <roots> False, considers all entities recorded (either for Result, or for at least one Fail or Warning message) - <roots> True (Default), considers only roots of Transfer (the Entities recorded at highest level) This method is based on AbnormalResult from TransferProcess", py::arg("normal"), py::arg("roots"));
cls_Transfer_TransferOutput.def("ModelForStatus", [](Transfer_TransferOutput &self, const opencascade::handle<Interface_Protocol> & a0, const Standard_Boolean a1) -> opencascade::handle<Interface_InterfaceModel> { return self.ModelForStatus(a0, a1); });
cls_Transfer_TransferOutput.def("ModelForStatus", (opencascade::handle<Interface_InterfaceModel> (Transfer_TransferOutput::*)(const opencascade::handle<Interface_Protocol> &, const Standard_Boolean, const Standard_Boolean) const) &Transfer_TransferOutput::ModelForStatus, "Fills a Model with the list determined by ListForStatus This model starts from scratch (made by NewEmptyModel from the current Model), then is filled by AddWithRefs", py::arg("protocol"), py::arg("normal"), py::arg("roots"));

// CLASS: TRANSFER_TRANSFERDISPATCH
py::class_<Transfer_TransferDispatch, Interface_CopyTool> cls_Transfer_TransferDispatch(mod, "Transfer_TransferDispatch", "A TransferDispatch is aimed to dispatch Entities between two Interface Models, by default by copying them, as CopyTool, but with more capabilities of adapting : Copy is redefined to firstly pass the hand to a TransferProcess. If this gives no result, standard Copy is called.");

// Constructors
cls_Transfer_TransferDispatch.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const Interface_GeneralLib &>(), py::arg("amodel"), py::arg("lib"));
cls_Transfer_TransferDispatch.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &>(), py::arg("amodel"), py::arg("protocol"));
cls_Transfer_TransferDispatch.def(py::init<const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("amodel"));

// Methods
// cls_Transfer_TransferDispatch.def_static("operator new_", (void * (*)(size_t)) &Transfer_TransferDispatch::operator new, "None", py::arg("theSize"));
// cls_Transfer_TransferDispatch.def_static("operator delete_", (void (*)(void *)) &Transfer_TransferDispatch::operator delete, "None", py::arg("theAddress"));
// cls_Transfer_TransferDispatch.def_static("operator new[]_", (void * (*)(size_t)) &Transfer_TransferDispatch::operator new[], "None", py::arg("theSize"));
// cls_Transfer_TransferDispatch.def_static("operator delete[]_", (void (*)(void *)) &Transfer_TransferDispatch::operator delete[], "None", py::arg("theAddress"));
// cls_Transfer_TransferDispatch.def_static("operator new_", (void * (*)(size_t, void *)) &Transfer_TransferDispatch::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Transfer_TransferDispatch.def_static("operator delete_", (void (*)(void *, void *)) &Transfer_TransferDispatch::operator delete, "None", py::arg(""), py::arg(""));
cls_Transfer_TransferDispatch.def("TransientProcess", (opencascade::handle<Transfer_TransientProcess> (Transfer_TransferDispatch::*)() const) &Transfer_TransferDispatch::TransientProcess, "Returns the content of Control Object, as a TransientProcess");
cls_Transfer_TransferDispatch.def("Copy", (Standard_Boolean (Transfer_TransferDispatch::*)(const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &, const Standard_Boolean, const Standard_Boolean)) &Transfer_TransferDispatch::Copy, "Copies an Entity by calling the method Transferring from the TransferProcess. If this called produces a Null Binder, then the standard, inherited Copy is called", py::arg("entfrom"), py::arg("entto"), py::arg("mapped"), py::arg("errstat"));

// CLASS: TRANSFER_ACTORDISPATCH
py::class_<Transfer_ActorDispatch, opencascade::handle<Transfer_ActorDispatch>, Transfer_ActorOfTransientProcess> cls_Transfer_ActorDispatch(mod, "Transfer_ActorDispatch", "This class allows to work with a TransferDispatch, i.e. to transfer entities from a data set to another one defined by the same interface norm, with the following features : - ActorDispatch itself acts as a default actor, i.e. it copies entities with the general service Copy, as CopyTool does - it allows to add other actors for specific ways of transfer, which may include data modifications, conversions ... - and other features from TransferDispatch (such as mapping other than one-one)");

// Constructors
cls_Transfer_ActorDispatch.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const Interface_GeneralLib &>(), py::arg("amodel"), py::arg("lib"));
cls_Transfer_ActorDispatch.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &>(), py::arg("amodel"), py::arg("protocol"));
cls_Transfer_ActorDispatch.def(py::init<const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("amodel"));

// Methods
cls_Transfer_ActorDispatch.def("AddActor", (void (Transfer_ActorDispatch::*)(const opencascade::handle<Transfer_ActorOfTransientProcess> &)) &Transfer_ActorDispatch::AddActor, "Utility which adds an actor to the default <me> (it calls SetActor from the TransientProcess)", py::arg("actor"));
cls_Transfer_ActorDispatch.def("TransferDispatch", (Transfer_TransferDispatch & (Transfer_ActorDispatch::*)()) &Transfer_ActorDispatch::TransferDispatch, "Returns the TransferDispatch, which does the work, records the intermediate data, etc... See TransferDispatch & CopyTool, to see the available methods");
cls_Transfer_ActorDispatch.def("Transfer", (opencascade::handle<Transfer_Binder> (Transfer_ActorDispatch::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Transfer_TransientProcess> &)) &Transfer_ActorDispatch::Transfer, "Specific action : it calls the method Transfer from CopyTool i.e. the general service Copy, then returns the Binder produced by the TransientProcess", py::arg("start"), py::arg("TP"));
cls_Transfer_ActorDispatch.def_static("get_type_name_", (const char * (*)()) &Transfer_ActorDispatch::get_type_name, "None");
cls_Transfer_ActorDispatch.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_ActorDispatch::get_type_descriptor, "None");
cls_Transfer_ActorDispatch.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_ActorDispatch::*)() const) &Transfer_ActorDispatch::DynamicType, "None");

// CLASS: TRANSFER_SIMPLEBINDEROFTRANSIENT
py::class_<Transfer_SimpleBinderOfTransient, opencascade::handle<Transfer_SimpleBinderOfTransient>, Transfer_Binder> cls_Transfer_SimpleBinderOfTransient(mod, "Transfer_SimpleBinderOfTransient", "An adapted instantiation of SimpleBinder for Transient Result, i.e. ResultType can be computed from the Result itself, instead of being static");

// Constructors
cls_Transfer_SimpleBinderOfTransient.def(py::init<>());

// Methods
cls_Transfer_SimpleBinderOfTransient.def("ResultType", (opencascade::handle<Standard_Type> (Transfer_SimpleBinderOfTransient::*)() const) &Transfer_SimpleBinderOfTransient::ResultType, "Returns the Effective (Dynamic) Type of the Result (Standard_Transient if no Result is defined)");
cls_Transfer_SimpleBinderOfTransient.def("ResultTypeName", (Standard_CString (Transfer_SimpleBinderOfTransient::*)() const) &Transfer_SimpleBinderOfTransient::ResultTypeName, "Returns the Effective Name of (Dynamic) Type of the Result (void) if no result is defined");
cls_Transfer_SimpleBinderOfTransient.def("SetResult", (void (Transfer_SimpleBinderOfTransient::*)(const opencascade::handle<Standard_Transient> &)) &Transfer_SimpleBinderOfTransient::SetResult, "Defines the Result", py::arg("res"));
cls_Transfer_SimpleBinderOfTransient.def("Result", (const opencascade::handle<Standard_Transient> & (Transfer_SimpleBinderOfTransient::*)() const) &Transfer_SimpleBinderOfTransient::Result, "Returns the defined Result, if there is one");
cls_Transfer_SimpleBinderOfTransient.def_static("GetTypedResult_", (Standard_Boolean (*)(const opencascade::handle<Transfer_Binder> &, const opencascade::handle<Standard_Type> &, opencascade::handle<Standard_Transient> &)) &Transfer_SimpleBinderOfTransient::GetTypedResult, "Returns a transient result according to its type (IsKind) i.e. the result itself if IsKind(atype), else searches in NextResult, until first found, then returns True If not found, returns False (res is NOT touched)", py::arg("bnd"), py::arg("atype"), py::arg("res"));
cls_Transfer_SimpleBinderOfTransient.def_static("get_type_name_", (const char * (*)()) &Transfer_SimpleBinderOfTransient::get_type_name, "None");
cls_Transfer_SimpleBinderOfTransient.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_SimpleBinderOfTransient::get_type_descriptor, "None");
cls_Transfer_SimpleBinderOfTransient.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_SimpleBinderOfTransient::*)() const) &Transfer_SimpleBinderOfTransient::DynamicType, "None");

// CLASS: TRANSFER_BINDEROFTRANSIENTINTEGER
py::class_<Transfer_BinderOfTransientInteger, opencascade::handle<Transfer_BinderOfTransientInteger>, Transfer_SimpleBinderOfTransient> cls_Transfer_BinderOfTransientInteger(mod, "Transfer_BinderOfTransientInteger", "This type of Binder allows to attach as result, besides a Transient Object, an Integer Value, which can be an Index in the Object if it defines a List, for instance");

// Constructors
cls_Transfer_BinderOfTransientInteger.def(py::init<>());

// Methods
cls_Transfer_BinderOfTransientInteger.def("SetInteger", (void (Transfer_BinderOfTransientInteger::*)(const Standard_Integer)) &Transfer_BinderOfTransientInteger::SetInteger, "Sets a value for the integer part", py::arg("value"));
cls_Transfer_BinderOfTransientInteger.def("Integer", (Standard_Integer (Transfer_BinderOfTransientInteger::*)() const) &Transfer_BinderOfTransientInteger::Integer, "Returns the value set for the integer part");
cls_Transfer_BinderOfTransientInteger.def_static("get_type_name_", (const char * (*)()) &Transfer_BinderOfTransientInteger::get_type_name, "None");
cls_Transfer_BinderOfTransientInteger.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_BinderOfTransientInteger::get_type_descriptor, "None");
cls_Transfer_BinderOfTransientInteger.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_BinderOfTransientInteger::*)() const) &Transfer_BinderOfTransientInteger::DynamicType, "None");

// CLASS: TRANSFER_DATAINFO
py::class_<Transfer_DataInfo> cls_Transfer_DataInfo(mod, "Transfer_DataInfo", "Gives informations on an object Used as template to instantiate Mapper and SimpleBinder This class is for Transient");

// Constructors
cls_Transfer_DataInfo.def(py::init<>());

// Methods
// cls_Transfer_DataInfo.def_static("operator new_", (void * (*)(size_t)) &Transfer_DataInfo::operator new, "None", py::arg("theSize"));
// cls_Transfer_DataInfo.def_static("operator delete_", (void (*)(void *)) &Transfer_DataInfo::operator delete, "None", py::arg("theAddress"));
// cls_Transfer_DataInfo.def_static("operator new[]_", (void * (*)(size_t)) &Transfer_DataInfo::operator new[], "None", py::arg("theSize"));
// cls_Transfer_DataInfo.def_static("operator delete[]_", (void (*)(void *)) &Transfer_DataInfo::operator delete[], "None", py::arg("theAddress"));
// cls_Transfer_DataInfo.def_static("operator new_", (void * (*)(size_t, void *)) &Transfer_DataInfo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Transfer_DataInfo.def_static("operator delete_", (void (*)(void *, void *)) &Transfer_DataInfo::operator delete, "None", py::arg(""), py::arg(""));
cls_Transfer_DataInfo.def_static("Type_", (opencascade::handle<Standard_Type> (*)(const opencascade::handle<Standard_Transient> &)) &Transfer_DataInfo::Type, "Returns the Type attached to an object Here, the Dynamic Type of a Transient. Null Type if unknown", py::arg("ent"));
cls_Transfer_DataInfo.def_static("TypeName_", (Standard_CString (*)(const opencascade::handle<Standard_Transient> &)) &Transfer_DataInfo::TypeName, "Returns Type Name (string) Allows to name type of non-handled objects", py::arg("ent"));

// CLASS: TRANSFER_DISPATCHCONTROL
py::class_<Transfer_DispatchControl, opencascade::handle<Transfer_DispatchControl>, Interface_CopyControl> cls_Transfer_DispatchControl(mod, "Transfer_DispatchControl", "This is an auxiliary class for TransferDispatch, which allows to record simple copies, as CopyControl from Interface, but based on a TransientProcess. Hence, it allows in addition more actions (such as recording results of adaptations)");

// Constructors
cls_Transfer_DispatchControl.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Transfer_TransientProcess> &>(), py::arg("model"), py::arg("TP"));

// Methods
cls_Transfer_DispatchControl.def("TransientProcess", (const opencascade::handle<Transfer_TransientProcess> & (Transfer_DispatchControl::*)() const) &Transfer_DispatchControl::TransientProcess, "Returns the content of the DispatchControl : it can be used for a direct call, if the basic methods do not suffice");
cls_Transfer_DispatchControl.def("StartingModel", (const opencascade::handle<Interface_InterfaceModel> & (Transfer_DispatchControl::*)() const) &Transfer_DispatchControl::StartingModel, "Returns the Model from which the transfer is to be done");
cls_Transfer_DispatchControl.def("Clear", (void (Transfer_DispatchControl::*)()) &Transfer_DispatchControl::Clear, "Clears the List of Copied Results");
cls_Transfer_DispatchControl.def("Bind", (void (Transfer_DispatchControl::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &)) &Transfer_DispatchControl::Bind, "Binds a (Transient) Result to a (Transient) Starting Entity", py::arg("ent"), py::arg("res"));
cls_Transfer_DispatchControl.def("Search", (Standard_Boolean (Transfer_DispatchControl::*)(const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &) const) &Transfer_DispatchControl::Search, "Searches for the Result bound to a Starting Entity If Found, returns True and fills <res> Else, returns False and nullifies <res>", py::arg("ent"), py::arg("res"));
cls_Transfer_DispatchControl.def_static("get_type_name_", (const char * (*)()) &Transfer_DispatchControl::get_type_name, "None");
cls_Transfer_DispatchControl.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_DispatchControl::get_type_descriptor, "None");
cls_Transfer_DispatchControl.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_DispatchControl::*)() const) &Transfer_DispatchControl::DynamicType, "None");

// TYPEDEF: TRANSFER_SEQUENCEOFBINDER
bind_NCollection_Sequence<opencascade::handle<Transfer_Binder> >(mod, "Transfer_SequenceOfBinder", py::module_local(false));

// CLASS: TRANSFER_HSEQUENCEOFBINDER
bind_Define_HSequence<Transfer_HSequenceOfBinder, Transfer_SequenceOfBinder>(mod, "Transfer_HSequenceOfBinder");

// CLASS: TRANSFER_TRANSFERITERATOR
py::class_<Transfer_TransferIterator> cls_Transfer_TransferIterator(mod, "Transfer_TransferIterator", "Defines an Iterator on the result of a Transfer Available for Normal Results or not (Erroneous Transfer) It gives several kinds of Informations, and allows to consider various criteria (criteria are cumulative)");

// Constructors
cls_Transfer_TransferIterator.def(py::init<>());

// Methods
// cls_Transfer_TransferIterator.def_static("operator new_", (void * (*)(size_t)) &Transfer_TransferIterator::operator new, "None", py::arg("theSize"));
// cls_Transfer_TransferIterator.def_static("operator delete_", (void (*)(void *)) &Transfer_TransferIterator::operator delete, "None", py::arg("theAddress"));
// cls_Transfer_TransferIterator.def_static("operator new[]_", (void * (*)(size_t)) &Transfer_TransferIterator::operator new[], "None", py::arg("theSize"));
// cls_Transfer_TransferIterator.def_static("operator delete[]_", (void (*)(void *)) &Transfer_TransferIterator::operator delete[], "None", py::arg("theAddress"));
// cls_Transfer_TransferIterator.def_static("operator new_", (void * (*)(size_t, void *)) &Transfer_TransferIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Transfer_TransferIterator.def_static("operator delete_", (void (*)(void *, void *)) &Transfer_TransferIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_Transfer_TransferIterator.def("AddItem", (void (Transfer_TransferIterator::*)(const opencascade::handle<Transfer_Binder> &)) &Transfer_TransferIterator::AddItem, "Adds a Binder to the iteration list (construction)", py::arg("atr"));
cls_Transfer_TransferIterator.def("SelectBinder", (void (Transfer_TransferIterator::*)(const opencascade::handle<Standard_Type> &, const Standard_Boolean)) &Transfer_TransferIterator::SelectBinder, "Selects Items on the Type of Binder : keep only Binders which are of a given Type (if keep is True) or reject only them (if keep is False)", py::arg("atype"), py::arg("keep"));
cls_Transfer_TransferIterator.def("SelectResult", (void (Transfer_TransferIterator::*)(const opencascade::handle<Standard_Type> &, const Standard_Boolean)) &Transfer_TransferIterator::SelectResult, "Selects Items on the Type of Result. Considers only Unique Results. Considers Dynamic Type for Transient Result, Static Type (the one given to define the Binder) else.", py::arg("atype"), py::arg("keep"));
cls_Transfer_TransferIterator.def("SelectUnique", (void (Transfer_TransferIterator::*)(const Standard_Boolean)) &Transfer_TransferIterator::SelectUnique, "Select Items according Unicity : keep only Unique Results (if keep is True) or keep only Multiple Results (if keep is False)", py::arg("keep"));
cls_Transfer_TransferIterator.def("SelectItem", (void (Transfer_TransferIterator::*)(const Standard_Integer, const Standard_Boolean)) &Transfer_TransferIterator::SelectItem, "Selects/Unselect (according to <keep> an item designated by its rank <num> in the list Used by sub-classes which have specific criteria", py::arg("num"), py::arg("keep"));
cls_Transfer_TransferIterator.def("Number", (Standard_Integer (Transfer_TransferIterator::*)() const) &Transfer_TransferIterator::Number, "Returns count of Binders to be iterated");
cls_Transfer_TransferIterator.def("Start", (void (Transfer_TransferIterator::*)()) &Transfer_TransferIterator::Start, "Clears Iteration in progress, to allow it to be restarted");
cls_Transfer_TransferIterator.def("More", (Standard_Boolean (Transfer_TransferIterator::*)()) &Transfer_TransferIterator::More, "Returns True if there are other Items to iterate");
cls_Transfer_TransferIterator.def("Next", (void (Transfer_TransferIterator::*)()) &Transfer_TransferIterator::Next, "Sets Iteration to the next Item");
cls_Transfer_TransferIterator.def("Value", (const opencascade::handle<Transfer_Binder> & (Transfer_TransferIterator::*)() const) &Transfer_TransferIterator::Value, "Returns the current Binder");
cls_Transfer_TransferIterator.def("HasResult", (Standard_Boolean (Transfer_TransferIterator::*)() const) &Transfer_TransferIterator::HasResult, "Returns True if current Item brings a Result, Transient (Handle) or not or Multiple. That is to say, if it corresponds to a normally acheived Transfer, Transient Result is read by specific TransientResult below. Other kind of Result must be read specifically from its Binder");
cls_Transfer_TransferIterator.def("HasUniqueResult", (Standard_Boolean (Transfer_TransferIterator::*)() const) &Transfer_TransferIterator::HasUniqueResult, "Returns True if Current Item has a Unique Result");
cls_Transfer_TransferIterator.def("ResultType", (opencascade::handle<Standard_Type> (Transfer_TransferIterator::*)() const) &Transfer_TransferIterator::ResultType, "Returns the Type of the Result of the current Item, if Unique. If No Unique Result (Error Transfert or Multiple Result), returns a Null Handle The Type is : the Dynamic Type for a Transient Result, the Type defined by the Binder Class else");
cls_Transfer_TransferIterator.def("HasTransientResult", (Standard_Boolean (Transfer_TransferIterator::*)() const) &Transfer_TransferIterator::HasTransientResult, "Returns True if the current Item has a Transient Unique Result (if yes, use TransientResult to get it)");
cls_Transfer_TransferIterator.def("TransientResult", (const opencascade::handle<Standard_Transient> & (Transfer_TransferIterator::*)() const) &Transfer_TransferIterator::TransientResult, "Returns the Transient Result of the current Item if there is (else, returns a null Handle) Supposes that Binding is done by a SimpleBinderOfTransient");
cls_Transfer_TransferIterator.def("Status", (Transfer_StatusExec (Transfer_TransferIterator::*)() const) &Transfer_TransferIterator::Status, "Returns Execution Status of current Binder Normal transfer corresponds to StatusDone");
cls_Transfer_TransferIterator.def("HasFails", (Standard_Boolean (Transfer_TransferIterator::*)() const) &Transfer_TransferIterator::HasFails, "Returns True if Fail Messages are recorded with the current Binder. They can then be read through Check (see below)");
cls_Transfer_TransferIterator.def("HasWarnings", (Standard_Boolean (Transfer_TransferIterator::*)() const) &Transfer_TransferIterator::HasWarnings, "Returns True if Warning Messages are recorded with the current Binder. They can then be read through Check (see below)");
cls_Transfer_TransferIterator.def("Check", (const opencascade::handle<Interface_Check> (Transfer_TransferIterator::*)() const) &Transfer_TransferIterator::Check, "Returns Check associated to current Binder (in case of error, it brings Fail messages) (in case of warnings, it brings Warning messages)");

// CLASS: TRANSFER_ITERATOROFPROCESSFORFINDER
py::class_<Transfer_IteratorOfProcessForFinder, Transfer_TransferIterator> cls_Transfer_IteratorOfProcessForFinder(mod, "Transfer_IteratorOfProcessForFinder", "None");

// Constructors
cls_Transfer_IteratorOfProcessForFinder.def(py::init<const Standard_Boolean>(), py::arg("withstarts"));

// Methods
// cls_Transfer_IteratorOfProcessForFinder.def_static("operator new_", (void * (*)(size_t)) &Transfer_IteratorOfProcessForFinder::operator new, "None", py::arg("theSize"));
// cls_Transfer_IteratorOfProcessForFinder.def_static("operator delete_", (void (*)(void *)) &Transfer_IteratorOfProcessForFinder::operator delete, "None", py::arg("theAddress"));
// cls_Transfer_IteratorOfProcessForFinder.def_static("operator new[]_", (void * (*)(size_t)) &Transfer_IteratorOfProcessForFinder::operator new[], "None", py::arg("theSize"));
// cls_Transfer_IteratorOfProcessForFinder.def_static("operator delete[]_", (void (*)(void *)) &Transfer_IteratorOfProcessForFinder::operator delete[], "None", py::arg("theAddress"));
// cls_Transfer_IteratorOfProcessForFinder.def_static("operator new_", (void * (*)(size_t, void *)) &Transfer_IteratorOfProcessForFinder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Transfer_IteratorOfProcessForFinder.def_static("operator delete_", (void (*)(void *, void *)) &Transfer_IteratorOfProcessForFinder::operator delete, "None", py::arg(""), py::arg(""));
cls_Transfer_IteratorOfProcessForFinder.def("Add", (void (Transfer_IteratorOfProcessForFinder::*)(const opencascade::handle<Transfer_Binder> &)) &Transfer_IteratorOfProcessForFinder::Add, "Adds a Binder to the iteration list (construction) with no corresponding Starting Object (note that Result is brought by Binder)", py::arg("binder"));
cls_Transfer_IteratorOfProcessForFinder.def("Add", (void (Transfer_IteratorOfProcessForFinder::*)(const opencascade::handle<Transfer_Binder> &, const opencascade::handle<Transfer_Finder> &)) &Transfer_IteratorOfProcessForFinder::Add, "Adds a Binder to the iteration list, associated with its corresponding Starting Object 'start' Starting Object is ignored if not required at Creation time", py::arg("binder"), py::arg("start"));
cls_Transfer_IteratorOfProcessForFinder.def("Filter", [](Transfer_IteratorOfProcessForFinder &self, const opencascade::handle<Transfer_HSequenceOfFinder> & a0) -> void { return self.Filter(a0); });
cls_Transfer_IteratorOfProcessForFinder.def("Filter", (void (Transfer_IteratorOfProcessForFinder::*)(const opencascade::handle<Transfer_HSequenceOfFinder> &, const Standard_Boolean)) &Transfer_IteratorOfProcessForFinder::Filter, "After having added all items, keeps or rejects items which are attached to starting data given by <only> <keep> = True (D) : keeps. <keep> = False : rejects Does nothing if <withstarts> was False", py::arg("list"), py::arg("keep"));
cls_Transfer_IteratorOfProcessForFinder.def("HasStarting", (Standard_Boolean (Transfer_IteratorOfProcessForFinder::*)() const) &Transfer_IteratorOfProcessForFinder::HasStarting, "Returns True if Starting Object is available (defined at Creation Time)");
cls_Transfer_IteratorOfProcessForFinder.def("Starting", (const opencascade::handle<Transfer_Finder> & (Transfer_IteratorOfProcessForFinder::*)() const) &Transfer_IteratorOfProcessForFinder::Starting, "Returns corresponding Starting Object");

// CLASS: TRANSFER_ITERATOROFPROCESSFORTRANSIENT
py::class_<Transfer_IteratorOfProcessForTransient, Transfer_TransferIterator> cls_Transfer_IteratorOfProcessForTransient(mod, "Transfer_IteratorOfProcessForTransient", "None");

// Constructors
cls_Transfer_IteratorOfProcessForTransient.def(py::init<const Standard_Boolean>(), py::arg("withstarts"));

// Methods
// cls_Transfer_IteratorOfProcessForTransient.def_static("operator new_", (void * (*)(size_t)) &Transfer_IteratorOfProcessForTransient::operator new, "None", py::arg("theSize"));
// cls_Transfer_IteratorOfProcessForTransient.def_static("operator delete_", (void (*)(void *)) &Transfer_IteratorOfProcessForTransient::operator delete, "None", py::arg("theAddress"));
// cls_Transfer_IteratorOfProcessForTransient.def_static("operator new[]_", (void * (*)(size_t)) &Transfer_IteratorOfProcessForTransient::operator new[], "None", py::arg("theSize"));
// cls_Transfer_IteratorOfProcessForTransient.def_static("operator delete[]_", (void (*)(void *)) &Transfer_IteratorOfProcessForTransient::operator delete[], "None", py::arg("theAddress"));
// cls_Transfer_IteratorOfProcessForTransient.def_static("operator new_", (void * (*)(size_t, void *)) &Transfer_IteratorOfProcessForTransient::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Transfer_IteratorOfProcessForTransient.def_static("operator delete_", (void (*)(void *, void *)) &Transfer_IteratorOfProcessForTransient::operator delete, "None", py::arg(""), py::arg(""));
cls_Transfer_IteratorOfProcessForTransient.def("Add", (void (Transfer_IteratorOfProcessForTransient::*)(const opencascade::handle<Transfer_Binder> &)) &Transfer_IteratorOfProcessForTransient::Add, "Adds a Binder to the iteration list (construction) with no corresponding Starting Object (note that Result is brought by Binder)", py::arg("binder"));
cls_Transfer_IteratorOfProcessForTransient.def("Add", (void (Transfer_IteratorOfProcessForTransient::*)(const opencascade::handle<Transfer_Binder> &, const opencascade::handle<Standard_Transient> &)) &Transfer_IteratorOfProcessForTransient::Add, "Adds a Binder to the iteration list, associated with its corresponding Starting Object 'start' Starting Object is ignored if not required at Creation time", py::arg("binder"), py::arg("start"));
cls_Transfer_IteratorOfProcessForTransient.def("Filter", [](Transfer_IteratorOfProcessForTransient &self, const opencascade::handle<TColStd_HSequenceOfTransient> & a0) -> void { return self.Filter(a0); });
cls_Transfer_IteratorOfProcessForTransient.def("Filter", (void (Transfer_IteratorOfProcessForTransient::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &, const Standard_Boolean)) &Transfer_IteratorOfProcessForTransient::Filter, "After having added all items, keeps or rejects items which are attached to starting data given by <only> <keep> = True (D) : keeps. <keep> = False : rejects Does nothing if <withstarts> was False", py::arg("list"), py::arg("keep"));
cls_Transfer_IteratorOfProcessForTransient.def("HasStarting", (Standard_Boolean (Transfer_IteratorOfProcessForTransient::*)() const) &Transfer_IteratorOfProcessForTransient::HasStarting, "Returns True if Starting Object is available (defined at Creation Time)");
cls_Transfer_IteratorOfProcessForTransient.def("Starting", (const opencascade::handle<Standard_Transient> & (Transfer_IteratorOfProcessForTransient::*)() const) &Transfer_IteratorOfProcessForTransient::Starting, "Returns corresponding Starting Object");

// CLASS: TRANSFER_MAPCONTAINER
py::class_<Transfer_MapContainer, opencascade::handle<Transfer_MapContainer>, Standard_Transient> cls_Transfer_MapContainer(mod, "Transfer_MapContainer", "None");

// Constructors
cls_Transfer_MapContainer.def(py::init<>());

// Methods
cls_Transfer_MapContainer.def("SetMapObjects", (void (Transfer_MapContainer::*)(TColStd_DataMapOfTransientTransient &)) &Transfer_MapContainer::SetMapObjects, "Set map already translated geometry objects.", py::arg("theMapObjects"));
cls_Transfer_MapContainer.def("GetMapObjects", (TColStd_DataMapOfTransientTransient & (Transfer_MapContainer::*)()) &Transfer_MapContainer::GetMapObjects, "Get map already translated geometry objects.");
cls_Transfer_MapContainer.def_static("get_type_name_", (const char * (*)()) &Transfer_MapContainer::get_type_name, "None");
cls_Transfer_MapContainer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_MapContainer::get_type_descriptor, "None");
cls_Transfer_MapContainer.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_MapContainer::*)() const) &Transfer_MapContainer::DynamicType, "None");

// CLASS: TRANSFER_MULTIPLEBINDER
py::class_<Transfer_MultipleBinder, opencascade::handle<Transfer_MultipleBinder>, Transfer_Binder> cls_Transfer_MultipleBinder(mod, "Transfer_MultipleBinder", "Allows direct binding between a starting Object and the Result of its transfer, when it can be made of several Transient Objects. Compared to a Transcriptor, it has no Transfer Action");

// Constructors
cls_Transfer_MultipleBinder.def(py::init<>());

// Methods
cls_Transfer_MultipleBinder.def("IsMultiple", (Standard_Boolean (Transfer_MultipleBinder::*)() const) &Transfer_MultipleBinder::IsMultiple, "Returns True if a starting object is bound with SEVERAL results : Here, returns allways True");
cls_Transfer_MultipleBinder.def("ResultType", (opencascade::handle<Standard_Type> (Transfer_MultipleBinder::*)() const) &Transfer_MultipleBinder::ResultType, "Returns the Type permitted for Results, i.e. here Transient");
cls_Transfer_MultipleBinder.def("ResultTypeName", (Standard_CString (Transfer_MultipleBinder::*)() const) &Transfer_MultipleBinder::ResultTypeName, "Returns the Name of the Type which characterizes the Result Here, returns '(list)'");
cls_Transfer_MultipleBinder.def("AddResult", (void (Transfer_MultipleBinder::*)(const opencascade::handle<Standard_Transient> &)) &Transfer_MultipleBinder::AddResult, "Adds a new Item to the Multiple Result", py::arg("res"));
cls_Transfer_MultipleBinder.def("NbResults", (Standard_Integer (Transfer_MultipleBinder::*)() const) &Transfer_MultipleBinder::NbResults, "Returns the actual count of recorded (Transient) results");
cls_Transfer_MultipleBinder.def("ResultValue", (opencascade::handle<Standard_Transient> (Transfer_MultipleBinder::*)(const Standard_Integer) const) &Transfer_MultipleBinder::ResultValue, "Returns the value of the recorded result n0 <num>", py::arg("num"));
cls_Transfer_MultipleBinder.def("MultipleResult", (opencascade::handle<TColStd_HSequenceOfTransient> (Transfer_MultipleBinder::*)() const) &Transfer_MultipleBinder::MultipleResult, "Returns the Multiple Result, if it is defined (at least one Item). Else, returns a Null Handle");
cls_Transfer_MultipleBinder.def("SetMultipleResult", (void (Transfer_MultipleBinder::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &)) &Transfer_MultipleBinder::SetMultipleResult, "Defines a Binding with a Multiple Result, given as a Sequence Error if a Unique Result has yet been defined", py::arg("mulres"));
cls_Transfer_MultipleBinder.def_static("get_type_name_", (const char * (*)()) &Transfer_MultipleBinder::get_type_name, "None");
cls_Transfer_MultipleBinder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_MultipleBinder::get_type_descriptor, "None");
cls_Transfer_MultipleBinder.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_MultipleBinder::*)() const) &Transfer_MultipleBinder::DynamicType, "None");

// CLASS: TRANSFER_RESULTFROMMODEL
py::class_<Transfer_ResultFromModel, opencascade::handle<Transfer_ResultFromModel>, Standard_Transient> cls_Transfer_ResultFromModel(mod, "Transfer_ResultFromModel", "ResultFromModel is used to store a final result stored in a TransientProcess, respectfully to its structuration in scopes by using a set of ResultFromTransient Hence, it can be regarded as a passive equivalent of the stored data in the TransientProcess, while an Iterator gives a flat view of it.");

// Constructors
cls_Transfer_ResultFromModel.def(py::init<>());

// Methods
cls_Transfer_ResultFromModel.def("SetModel", (void (Transfer_ResultFromModel::*)(const opencascade::handle<Interface_InterfaceModel> &)) &Transfer_ResultFromModel::SetModel, "Sets starting Model", py::arg("model"));
cls_Transfer_ResultFromModel.def("SetFileName", (void (Transfer_ResultFromModel::*)(const Standard_CString)) &Transfer_ResultFromModel::SetFileName, "Sets starting File Name", py::arg("filename"));
cls_Transfer_ResultFromModel.def("Model", (opencascade::handle<Interface_InterfaceModel> (Transfer_ResultFromModel::*)() const) &Transfer_ResultFromModel::Model, "Returns starting Model (null if not set)");
cls_Transfer_ResultFromModel.def("FileName", (Standard_CString (Transfer_ResultFromModel::*)() const) &Transfer_ResultFromModel::FileName, "Returns starting File Name (empty if not set)");
cls_Transfer_ResultFromModel.def("Fill", (Standard_Boolean (Transfer_ResultFromModel::*)(const opencascade::handle<Transfer_TransientProcess> &, const opencascade::handle<Standard_Transient> &)) &Transfer_ResultFromModel::Fill, "Fills from a TransientProcess, with the result attached to a starting entity. Considers its Model if it is set. This action produces a structured set of ResultFromTransient, considering scopes, starting by that of <ent>. If <ent> has no recorded result, it remains empty Returns True if a result is recorded, False else", py::arg("TP"), py::arg("ent"));
cls_Transfer_ResultFromModel.def("Strip", (void (Transfer_ResultFromModel::*)(const Standard_Integer)) &Transfer_ResultFromModel::Strip, "Clears some data attached to binders used by TransientProcess, which become useless once the transfer has been done, by calling Strip on its ResultFromTransient", py::arg("mode"));
cls_Transfer_ResultFromModel.def("FillBack", (void (Transfer_ResultFromModel::*)(const opencascade::handle<Transfer_TransientProcess> &) const) &Transfer_ResultFromModel::FillBack, "Fills back a TransientProcess from the structured set of binders. Also sets the Model.", py::arg("TP"));
cls_Transfer_ResultFromModel.def("HasResult", (Standard_Boolean (Transfer_ResultFromModel::*)() const) &Transfer_ResultFromModel::HasResult, "Returns True if a Result is recorded");
cls_Transfer_ResultFromModel.def("MainResult", (opencascade::handle<Transfer_ResultFromTransient> (Transfer_ResultFromModel::*)() const) &Transfer_ResultFromModel::MainResult, "Returns the main recorded ResultFromTransient, or a null");
cls_Transfer_ResultFromModel.def("SetMainResult", (void (Transfer_ResultFromModel::*)(const opencascade::handle<Transfer_ResultFromTransient> &)) &Transfer_ResultFromModel::SetMainResult, "Sets a new value for the main recorded ResultFromTransient", py::arg("amain"));
cls_Transfer_ResultFromModel.def("MainLabel", (Standard_CString (Transfer_ResultFromModel::*)() const) &Transfer_ResultFromModel::MainLabel, "Returns the label in starting model attached to main entity (updated by Fill or SetMainResult, if Model is known)");
cls_Transfer_ResultFromModel.def("MainNumber", (Standard_Integer (Transfer_ResultFromModel::*)() const) &Transfer_ResultFromModel::MainNumber, "Returns the label in starting model attached to main entity");
cls_Transfer_ResultFromModel.def("ResultFromKey", (opencascade::handle<Transfer_ResultFromTransient> (Transfer_ResultFromModel::*)(const opencascade::handle<Standard_Transient> &) const) &Transfer_ResultFromModel::ResultFromKey, "Searches for a key (starting entity) and returns its result Returns a null handle if not found", py::arg("start"));
cls_Transfer_ResultFromModel.def("Results", (opencascade::handle<TColStd_HSequenceOfTransient> (Transfer_ResultFromModel::*)(const Standard_Integer) const) &Transfer_ResultFromModel::Results, "Internal method which returns the list of ResultFromTransient, according level (2:complete; 1:sub-level 1; 0:main only)", py::arg("level"));
cls_Transfer_ResultFromModel.def("TransferredList", [](Transfer_ResultFromModel &self) -> opencascade::handle<TColStd_HSequenceOfTransient> { return self.TransferredList(); });
cls_Transfer_ResultFromModel.def("TransferredList", (opencascade::handle<TColStd_HSequenceOfTransient> (Transfer_ResultFromModel::*)(const Standard_Integer) const) &Transfer_ResultFromModel::TransferredList, "Returns the list of recorded starting entities, ending by the root. Entities with check but no transfer result are ignored <level> = 2 (D), considers the complete list <level> = 1 considers the main result plus immediate subs <level> = 0 just the main result", py::arg("level"));
cls_Transfer_ResultFromModel.def("CheckedList", (opencascade::handle<TColStd_HSequenceOfTransient> (Transfer_ResultFromModel::*)(const Interface_CheckStatus, const Standard_Boolean) const) &Transfer_ResultFromModel::CheckedList, "Returns the list of starting entities to which a check status is attached. <check> = -2 , all entities whatever the check (see result) <check> = -1 , entities with no fail (warning allowed) <check> = 0 , entities with no check at all <check> = 1 , entities with warning but no fail <check> = 2 , entities with fail <result> : if True, only entities with an attached result Remark : result True and check=0 will give an empty list", py::arg("check"), py::arg("result"));
cls_Transfer_ResultFromModel.def("CheckList", [](Transfer_ResultFromModel &self, const Standard_Boolean a0) -> Interface_CheckIterator { return self.CheckList(a0); });
cls_Transfer_ResultFromModel.def("CheckList", (Interface_CheckIterator (Transfer_ResultFromModel::*)(const Standard_Boolean, const Standard_Integer) const) &Transfer_ResultFromModel::CheckList, "Returns the check-list of this set of results <erronly> true : only fails are considered <level> = 0 : considers only main binder <level> = 1 : considers main binder plus immediate subs <level> = 2 (D) : considers all checks", py::arg("erronly"), py::arg("level"));
cls_Transfer_ResultFromModel.def("CheckStatus", (Interface_CheckStatus (Transfer_ResultFromModel::*)() const) &Transfer_ResultFromModel::CheckStatus, "Returns the check status with corresponds to the content of this ResultFromModel; considers all levels of transfer (worst status). Returns CheckAny if not yet computed Reads it from recorded status if already computed, else recomputes one");
cls_Transfer_ResultFromModel.def("ComputeCheckStatus", (Interface_CheckStatus (Transfer_ResultFromModel::*)(const Standard_Boolean)) &Transfer_ResultFromModel::ComputeCheckStatus, "Computes and records check status (see CheckStatus) Does not computes it if already done and <enforce> False", py::arg("enforce"));
cls_Transfer_ResultFromModel.def_static("get_type_name_", (const char * (*)()) &Transfer_ResultFromModel::get_type_name, "None");
cls_Transfer_ResultFromModel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_ResultFromModel::get_type_descriptor, "None");
cls_Transfer_ResultFromModel.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_ResultFromModel::*)() const) &Transfer_ResultFromModel::DynamicType, "None");

// CLASS: TRANSFER_RESULTFROMTRANSIENT
py::class_<Transfer_ResultFromTransient, opencascade::handle<Transfer_ResultFromTransient>, Standard_Transient> cls_Transfer_ResultFromTransient(mod, "Transfer_ResultFromTransient", "This class, in conjunction with ResultFromModel, allows to record the result of a transfer initially stored in a TransientProcess.");

// Constructors
cls_Transfer_ResultFromTransient.def(py::init<>());

// Methods
cls_Transfer_ResultFromTransient.def("SetStart", (void (Transfer_ResultFromTransient::*)(const opencascade::handle<Standard_Transient> &)) &Transfer_ResultFromTransient::SetStart, "Sets starting entity", py::arg("start"));
cls_Transfer_ResultFromTransient.def("SetBinder", (void (Transfer_ResultFromTransient::*)(const opencascade::handle<Transfer_Binder> &)) &Transfer_ResultFromTransient::SetBinder, "Sets Binder (for result plus individual check)", py::arg("binder"));
cls_Transfer_ResultFromTransient.def("Start", (opencascade::handle<Standard_Transient> (Transfer_ResultFromTransient::*)() const) &Transfer_ResultFromTransient::Start, "Returns the starting entity");
cls_Transfer_ResultFromTransient.def("Binder", (opencascade::handle<Transfer_Binder> (Transfer_ResultFromTransient::*)() const) &Transfer_ResultFromTransient::Binder, "Returns the binder");
cls_Transfer_ResultFromTransient.def("HasResult", (Standard_Boolean (Transfer_ResultFromTransient::*)() const) &Transfer_ResultFromTransient::HasResult, "Returns True if a result is recorded");
cls_Transfer_ResultFromTransient.def("Check", (const opencascade::handle<Interface_Check> (Transfer_ResultFromTransient::*)() const) &Transfer_ResultFromTransient::Check, "Returns the check (or an empty one if no binder)");
cls_Transfer_ResultFromTransient.def("CheckStatus", (Interface_CheckStatus (Transfer_ResultFromTransient::*)() const) &Transfer_ResultFromTransient::CheckStatus, "Returns the check status");
cls_Transfer_ResultFromTransient.def("ClearSubs", (void (Transfer_ResultFromTransient::*)()) &Transfer_ResultFromTransient::ClearSubs, "Clears the list of (immediate) sub-results");
cls_Transfer_ResultFromTransient.def("AddSubResult", (void (Transfer_ResultFromTransient::*)(const opencascade::handle<Transfer_ResultFromTransient> &)) &Transfer_ResultFromTransient::AddSubResult, "Adds a sub-result", py::arg("sub"));
cls_Transfer_ResultFromTransient.def("NbSubResults", (Standard_Integer (Transfer_ResultFromTransient::*)() const) &Transfer_ResultFromTransient::NbSubResults, "Returns the count of recorded sub-results");
cls_Transfer_ResultFromTransient.def("SubResult", (opencascade::handle<Transfer_ResultFromTransient> (Transfer_ResultFromTransient::*)(const Standard_Integer) const) &Transfer_ResultFromTransient::SubResult, "Returns a sub-result, given its rank", py::arg("num"));
cls_Transfer_ResultFromTransient.def("ResultFromKey", (opencascade::handle<Transfer_ResultFromTransient> (Transfer_ResultFromTransient::*)(const opencascade::handle<Standard_Transient> &) const) &Transfer_ResultFromTransient::ResultFromKey, "Returns the ResultFromTransient attached to a given starting entity (the key). Returns a null handle if not found", py::arg("key"));
cls_Transfer_ResultFromTransient.def("FillMap", (void (Transfer_ResultFromTransient::*)(TColStd_IndexedMapOfTransient &) const) &Transfer_ResultFromTransient::FillMap, "This method is used by ResultFromModel to collate the list of ResultFromTransient, avoiding duplications with a map Remark : <me> is already in the map and has not to be bound", py::arg("map"));
cls_Transfer_ResultFromTransient.def("Fill", (void (Transfer_ResultFromTransient::*)(const opencascade::handle<Transfer_TransientProcess> &)) &Transfer_ResultFromTransient::Fill, "Fills from a TransientProcess, with the starting entity which must have been set before. It works with scopes, calls Fill on each of its sub-results", py::arg("TP"));
cls_Transfer_ResultFromTransient.def("Strip", (void (Transfer_ResultFromTransient::*)()) &Transfer_ResultFromTransient::Strip, "Clears some data attached to binders used by TransientProcess, which become useless once the transfer has been done : the list of sub-scoped binders, which is now recorded as sub-results");
cls_Transfer_ResultFromTransient.def("FillBack", (void (Transfer_ResultFromTransient::*)(const opencascade::handle<Transfer_TransientProcess> &) const) &Transfer_ResultFromTransient::FillBack, "Fills back a TransientProcess with definition of a ResultFromTransient, respectfully to its structuration in scopes", py::arg("TP"));
cls_Transfer_ResultFromTransient.def_static("get_type_name_", (const char * (*)()) &Transfer_ResultFromTransient::get_type_name, "None");
cls_Transfer_ResultFromTransient.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_ResultFromTransient::get_type_descriptor, "None");
cls_Transfer_ResultFromTransient.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_ResultFromTransient::*)() const) &Transfer_ResultFromTransient::DynamicType, "None");

// CLASS: TRANSFER_TRANSFERFAILURE
py::class_<Transfer_TransferFailure, opencascade::handle<Transfer_TransferFailure>, Interface_InterfaceError> cls_Transfer_TransferFailure(mod, "Transfer_TransferFailure", "None");

// Constructors
cls_Transfer_TransferFailure.def(py::init<>());
cls_Transfer_TransferFailure.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Transfer_TransferFailure.def_static("Raise_", (void (*)(const Standard_CString)) &Transfer_TransferFailure::Raise, "None", py::arg("theMessage"));
cls_Transfer_TransferFailure.def_static("Raise_", (void (*)(Standard_SStream &)) &Transfer_TransferFailure::Raise, "None", py::arg("theMessage"));
cls_Transfer_TransferFailure.def_static("NewInstance_", (opencascade::handle<Transfer_TransferFailure> (*)(const Standard_CString)) &Transfer_TransferFailure::NewInstance, "None", py::arg("theMessage"));
cls_Transfer_TransferFailure.def_static("get_type_name_", (const char * (*)()) &Transfer_TransferFailure::get_type_name, "None");
cls_Transfer_TransferFailure.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_TransferFailure::get_type_descriptor, "None");
cls_Transfer_TransferFailure.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_TransferFailure::*)() const) &Transfer_TransferFailure::DynamicType, "None");

// CLASS: TRANSFER_TRANSFERDEADLOOP
py::class_<Transfer_TransferDeadLoop, opencascade::handle<Transfer_TransferDeadLoop>, Transfer_TransferFailure> cls_Transfer_TransferDeadLoop(mod, "Transfer_TransferDeadLoop", "None");

// Constructors
cls_Transfer_TransferDeadLoop.def(py::init<>());
cls_Transfer_TransferDeadLoop.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Transfer_TransferDeadLoop.def_static("Raise_", (void (*)(const Standard_CString)) &Transfer_TransferDeadLoop::Raise, "None", py::arg("theMessage"));
cls_Transfer_TransferDeadLoop.def_static("Raise_", (void (*)(Standard_SStream &)) &Transfer_TransferDeadLoop::Raise, "None", py::arg("theMessage"));
cls_Transfer_TransferDeadLoop.def_static("NewInstance_", (opencascade::handle<Transfer_TransferDeadLoop> (*)(const Standard_CString)) &Transfer_TransferDeadLoop::NewInstance, "None", py::arg("theMessage"));
cls_Transfer_TransferDeadLoop.def_static("get_type_name_", (const char * (*)()) &Transfer_TransferDeadLoop::get_type_name, "None");
cls_Transfer_TransferDeadLoop.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_TransferDeadLoop::get_type_descriptor, "None");
cls_Transfer_TransferDeadLoop.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_TransferDeadLoop::*)() const) &Transfer_TransferDeadLoop::DynamicType, "None");

// CLASS: TRANSFER_TRANSFERINPUT
py::class_<Transfer_TransferInput> cls_Transfer_TransferInput(mod, "Transfer_TransferInput", "A TransferInput is a Tool which fills an InterfaceModel with the result of the Transfer of CasCade Objects, once determined The Result comes from a TransferProcess, either from Transient (the Complete Result is considered, it must contain only Transient Objects)");

// Constructors
cls_Transfer_TransferInput.def(py::init<>());

// Methods
// cls_Transfer_TransferInput.def_static("operator new_", (void * (*)(size_t)) &Transfer_TransferInput::operator new, "None", py::arg("theSize"));
// cls_Transfer_TransferInput.def_static("operator delete_", (void (*)(void *)) &Transfer_TransferInput::operator delete, "None", py::arg("theAddress"));
// cls_Transfer_TransferInput.def_static("operator new[]_", (void * (*)(size_t)) &Transfer_TransferInput::operator new[], "None", py::arg("theSize"));
// cls_Transfer_TransferInput.def_static("operator delete[]_", (void (*)(void *)) &Transfer_TransferInput::operator delete[], "None", py::arg("theAddress"));
// cls_Transfer_TransferInput.def_static("operator new_", (void * (*)(size_t, void *)) &Transfer_TransferInput::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Transfer_TransferInput.def_static("operator delete_", (void (*)(void *, void *)) &Transfer_TransferInput::operator delete, "None", py::arg(""), py::arg(""));
cls_Transfer_TransferInput.def("Entities", (Interface_EntityIterator (Transfer_TransferInput::*)(Transfer_TransferIterator &) const) &Transfer_TransferInput::Entities, "Takes the transient items stored in a TransferIterator", py::arg("list"));
cls_Transfer_TransferInput.def("FillModel", (void (Transfer_TransferInput::*)(const opencascade::handle<Transfer_TransientProcess> &, const opencascade::handle<Interface_InterfaceModel> &) const) &Transfer_TransferInput::FillModel, "Fills an InterfaceModel with the Complete Result of a Transfer stored in a TransientProcess (Starting Objects are Transient) The complete result is exactly added to the model", py::arg("proc"), py::arg("amodel"));
cls_Transfer_TransferInput.def("FillModel", [](Transfer_TransferInput &self, const opencascade::handle<Transfer_TransientProcess> & a0, const opencascade::handle<Interface_InterfaceModel> & a1, const opencascade::handle<Interface_Protocol> & a2) -> void { return self.FillModel(a0, a1, a2); });
cls_Transfer_TransferInput.def("FillModel", (void (Transfer_TransferInput::*)(const opencascade::handle<Transfer_TransientProcess> &, const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &, const Standard_Boolean) const) &Transfer_TransferInput::FillModel, "Fills an InterfaceModel with results of the Transfer recorded in a TransientProcess (Starting Objects are Transient) : Root Result if <roots> is True (Default), Complete Result else The entities added to the model are determined from the result by by adding the referenced entities", py::arg("proc"), py::arg("amodel"), py::arg("proto"), py::arg("roots"));
cls_Transfer_TransferInput.def("FillModel", (void (Transfer_TransferInput::*)(const opencascade::handle<Transfer_FinderProcess> &, const opencascade::handle<Interface_InterfaceModel> &) const) &Transfer_TransferInput::FillModel, "Fills an InterfaceModel with the Complete Result of a Transfer stored in a TransientProcess (Starting Objects are Transient) The complete result is exactly added to the model", py::arg("proc"), py::arg("amodel"));
cls_Transfer_TransferInput.def("FillModel", [](Transfer_TransferInput &self, const opencascade::handle<Transfer_FinderProcess> & a0, const opencascade::handle<Interface_InterfaceModel> & a1, const opencascade::handle<Interface_Protocol> & a2) -> void { return self.FillModel(a0, a1, a2); });
cls_Transfer_TransferInput.def("FillModel", (void (Transfer_TransferInput::*)(const opencascade::handle<Transfer_FinderProcess> &, const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &, const Standard_Boolean) const) &Transfer_TransferInput::FillModel, "Fills an InterfaceModel with results of the Transfer recorded in a TransientProcess (Starting Objects are Transient) : Root Result if <roots> is True (Default), Complete Result else The entities added to the model are determined from the result by by adding the referenced entities", py::arg("proc"), py::arg("amodel"), py::arg("proto"), py::arg("roots"));

// CLASS: TRANSFER_TRANSIENTLISTBINDER
py::class_<Transfer_TransientListBinder, opencascade::handle<Transfer_TransientListBinder>, Transfer_Binder> cls_Transfer_TransientListBinder(mod, "Transfer_TransientListBinder", "This binder binds several (a list of) Transients with a starting entity, when this entity itself corresponds to a simple list of Transients. Each part is not seen as a sub-result of an independant componant, but as an item of a built-in list");

// Constructors
cls_Transfer_TransientListBinder.def(py::init<>());
cls_Transfer_TransientListBinder.def(py::init<const opencascade::handle<TColStd_HSequenceOfTransient> &>(), py::arg("list"));

// Methods
cls_Transfer_TransientListBinder.def("IsMultiple", (Standard_Boolean (Transfer_TransientListBinder::*)() const) &Transfer_TransientListBinder::IsMultiple, "None");
cls_Transfer_TransientListBinder.def("ResultType", (opencascade::handle<Standard_Type> (Transfer_TransientListBinder::*)() const) &Transfer_TransientListBinder::ResultType, "None");
cls_Transfer_TransientListBinder.def("ResultTypeName", (Standard_CString (Transfer_TransientListBinder::*)() const) &Transfer_TransientListBinder::ResultTypeName, "None");
cls_Transfer_TransientListBinder.def("AddResult", (void (Transfer_TransientListBinder::*)(const opencascade::handle<Standard_Transient> &)) &Transfer_TransientListBinder::AddResult, "Adds an item to the result list", py::arg("res"));
cls_Transfer_TransientListBinder.def("Result", (opencascade::handle<TColStd_HSequenceOfTransient> (Transfer_TransientListBinder::*)() const) &Transfer_TransientListBinder::Result, "None");
cls_Transfer_TransientListBinder.def("SetResult", (void (Transfer_TransientListBinder::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &)) &Transfer_TransientListBinder::SetResult, "Changes an already defined sub-result", py::arg("num"), py::arg("res"));
cls_Transfer_TransientListBinder.def("NbTransients", (Standard_Integer (Transfer_TransientListBinder::*)() const) &Transfer_TransientListBinder::NbTransients, "None");
cls_Transfer_TransientListBinder.def("Transient", (const opencascade::handle<Standard_Transient> & (Transfer_TransientListBinder::*)(const Standard_Integer) const) &Transfer_TransientListBinder::Transient, "None", py::arg("num"));
cls_Transfer_TransientListBinder.def_static("get_type_name_", (const char * (*)()) &Transfer_TransientListBinder::get_type_name, "None");
cls_Transfer_TransientListBinder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_TransientListBinder::get_type_descriptor, "None");
cls_Transfer_TransientListBinder.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_TransientListBinder::*)() const) &Transfer_TransientListBinder::DynamicType, "None");

// CLASS: TRANSFER_TRANSIENTMAPPER
py::class_<Transfer_TransientMapper, opencascade::handle<Transfer_TransientMapper>, Transfer_Finder> cls_Transfer_TransientMapper(mod, "Transfer_TransientMapper", "None");

// Constructors
cls_Transfer_TransientMapper.def(py::init<const opencascade::handle<Standard_Transient> &>(), py::arg("akey"));

// Methods
cls_Transfer_TransientMapper.def("Value", (const opencascade::handle<Standard_Transient> & (Transfer_TransientMapper::*)() const) &Transfer_TransientMapper::Value, "Returns the contained value");
cls_Transfer_TransientMapper.def("Equates", (Standard_Boolean (Transfer_TransientMapper::*)(const opencascade::handle<Transfer_Finder> &) const) &Transfer_TransientMapper::Equates, "Specific testof equallity : defined as False if <other> has not the same true Type, else contents are compared (by C++ operator ==)", py::arg("other"));
cls_Transfer_TransientMapper.def("ValueType", (opencascade::handle<Standard_Type> (Transfer_TransientMapper::*)() const) &Transfer_TransientMapper::ValueType, "Returns the Type of the Value. By default, returns the DynamicType of <me>, but can be redefined");
cls_Transfer_TransientMapper.def("ValueTypeName", (Standard_CString (Transfer_TransientMapper::*)() const) &Transfer_TransientMapper::ValueTypeName, "Returns the name of the Type of the Value. Default is name of ValueType, unless it is for a non-handled object");
cls_Transfer_TransientMapper.def_static("get_type_name_", (const char * (*)()) &Transfer_TransientMapper::get_type_name, "None");
cls_Transfer_TransientMapper.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_TransientMapper::get_type_descriptor, "None");
cls_Transfer_TransientMapper.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_TransientMapper::*)() const) &Transfer_TransientMapper::DynamicType, "None");

// CLASS: TRANSFER_VOIDBINDER
py::class_<Transfer_VoidBinder, opencascade::handle<Transfer_VoidBinder>, Transfer_Binder> cls_Transfer_VoidBinder(mod, "Transfer_VoidBinder", "a VoidBinder is used to bind a starting item with a status, error or warning messages, but no result It is interpreted by TransferProcess, which admits a VoidBinder to be over-written, and copies its check to the new Binder");

// Constructors
cls_Transfer_VoidBinder.def(py::init<>());

// Methods
cls_Transfer_VoidBinder.def("ResultType", (opencascade::handle<Standard_Type> (Transfer_VoidBinder::*)() const) &Transfer_VoidBinder::ResultType, "while a VoidBinder admits no Result, its ResultType returns the type of <me>");
cls_Transfer_VoidBinder.def("ResultTypeName", (Standard_CString (Transfer_VoidBinder::*)() const) &Transfer_VoidBinder::ResultTypeName, "Returns '(void)'");
cls_Transfer_VoidBinder.def_static("get_type_name_", (const char * (*)()) &Transfer_VoidBinder::get_type_name, "None");
cls_Transfer_VoidBinder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Transfer_VoidBinder::get_type_descriptor, "None");
cls_Transfer_VoidBinder.def("DynamicType", (const opencascade::handle<Standard_Type> & (Transfer_VoidBinder::*)() const) &Transfer_VoidBinder::DynamicType, "None");


}
