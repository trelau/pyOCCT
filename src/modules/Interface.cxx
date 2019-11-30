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
#include <Interface_DataState.hxx>
#include <Interface_CheckStatus.hxx>
#include <Interface_ParamType.hxx>
#include <NCollection_Array1.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Interface_Array1OfHAsciiString.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Std.hxx>
#include <Interface_HArray1OfHAsciiString.hxx>
#include <Standard_Type.hxx>
#include <NCollection_DataMap.hxx>
#include <TColStd_MapTransientHasher.hxx>
#include <Interface_DataMapOfTransientInteger.hxx>
#include <Interface_Protocol.hxx>
#include <Interface_Graph.hxx>
#include <Interface_Check.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_BitMap.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TColStd_HSequenceOfAsciiString.hxx>
#include <Interface_GTool.hxx>
#include <Interface_ReportEntity.hxx>
#include <Interface_CheckIterator.hxx>
#include <Interface_GeneralLib.hxx>
#include <Interface_EntityIterator.hxx>
#include <Message_Messenger.hxx>
#include <TColStd_HSequenceOfHAsciiString.hxx>
#include <TColStd_IndexedMapOfTransient.hxx>
#include <TColStd_DataMapOfIntegerTransient.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <TColStd_HArray1OfListOfInteger.hxx>
#include <TCollection_AsciiString.hxx>
#include <Interface_IntVal.hxx>
#include <Interface_GraphContent.hxx>
#include <Interface_IntList.hxx>
#include <Message_Msg.hxx>
#include <NCollection_Sequence.hxx>
#include <Interface_SequenceOfCheck.hxx>
#include <Interface_HSequenceOfCheck.hxx>
#include <TColStd_HSequenceOfInteger.hxx>
#include <MoniTool_SignText.hxx>
#include <Interface_SignType.hxx>
#include <Interface_EntityList.hxx>
#include <Interface_ShareTool.hxx>
#include <Interface_CopyTool.hxx>
#include <Interface_GeneralModule.hxx>
#include <Interface_FileReaderData.hxx>
#include <Interface_ReaderModule.hxx>
#include <Interface_NodeOfGeneralLib.hxx>
#include <Standard_IStream.hxx>
#include <Standard_OStream.hxx>
#include <Standard_PCharacter.hxx>
#include <Interface_MSG.hxx>
#include <Interface_FileParameter.hxx>
#include <Interface_ParamList.hxx>
#include <Interface_ParamSet.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_Array1OfTransient.hxx>
#include <Interface_NodeOfReaderLib.hxx>
#include <Interface_ReaderLib.hxx>
#include <TColStd_HArray1OfTransient.hxx>
#include <Interface_FileReaderTool.hxx>
#include <Interface_LineBuffer.hxx>
#include <Interface_FloatWriter.hxx>
#include <Interface_Array1OfFileParameter.hxx>
#include <TColStd_IndexedDataMapOfTransientTransient.hxx>
#include <Interface_Category.hxx>
#include <Standard_Failure.hxx>
#include <Interface_InterfaceError.hxx>
#include <Standard_SStream.hxx>
#include <Interface_CheckFailure.hxx>
#include <Interface_HGraph.hxx>
#include <Interface_CheckTool.hxx>
#include <Interface_CopyControl.hxx>
#include <Interface_CopyMap.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <Interface_EntityCluster.hxx>
#include <Interface_GlobalNodeOfGeneralLib.hxx>
#include <Interface_GlobalNodeOfReaderLib.hxx>
#include <Interface_MapAsciiStringHasher.hxx>
#include <NCollection_IndexedMap.hxx>
#include <Interface_IndexedMapOfAsciiString.hxx>
#include <Interface_InterfaceMismatch.hxx>
#include <NCollection_Vector.hxx>
#include <Interface_VectorOfFileParameter.hxx>
#include <Interface_ShareFlags.hxx>
#include <Interface_SignLabel.hxx>
#include <Interface_STAT.hxx>
#include <TColStd_HSequenceOfReal.hxx>
#include <Interface_StaticSatisfies.hxx>
#include <MoniTool_TypedValue.hxx>
#include <MoniTool_ValueType.hxx>
#include <Interface_TypedValue.hxx>
#include <TColStd_HArray1OfAsciiString.hxx>
#include <Interface_Static.hxx>
#include <Interface_UndefinedContent.hxx>
#include <Interface_ValueInterpret.hxx>
#include <Interface_ValueSatisfies.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_NCollection_DataMap.hxx>
#include <bind_NCollection_Sequence.hxx>
#include <bind_NCollection_IndexedMap.hxx>
#include <bind_NCollection_Vector.hxx>

PYBIND11_MODULE(Interface, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Message");
py::module::import("OCCT.MoniTool");

// ENUM: INTERFACE_DATASTATE
py::enum_<Interface_DataState>(mod, "Interface_DataState", "validity state of anentity's content (see InterfaceModel)")
	.value("Interface_StateOK", Interface_DataState::Interface_StateOK)
	.value("Interface_LoadWarning", Interface_DataState::Interface_LoadWarning)
	.value("Interface_LoadFail", Interface_DataState::Interface_LoadFail)
	.value("Interface_DataWarning", Interface_DataState::Interface_DataWarning)
	.value("Interface_DataFail", Interface_DataState::Interface_DataFail)
	.value("Interface_StateUnloaded", Interface_DataState::Interface_StateUnloaded)
	.value("Interface_StateUnknown", Interface_DataState::Interface_StateUnknown)
	.export_values();


// ENUM: INTERFACE_CHECKSTATUS
py::enum_<Interface_CheckStatus>(mod, "Interface_CheckStatus", "Classifies checks OK : check is empty Warning : Warning, no Fail Fail : Fail Others to query : Any : any status Message : Warning/Fail NoFail : Warning/OK")
	.value("Interface_CheckOK", Interface_CheckStatus::Interface_CheckOK)
	.value("Interface_CheckWarning", Interface_CheckStatus::Interface_CheckWarning)
	.value("Interface_CheckFail", Interface_CheckStatus::Interface_CheckFail)
	.value("Interface_CheckAny", Interface_CheckStatus::Interface_CheckAny)
	.value("Interface_CheckMessage", Interface_CheckStatus::Interface_CheckMessage)
	.value("Interface_CheckNoFail", Interface_CheckStatus::Interface_CheckNoFail)
	.export_values();


// ENUM: INTERFACE_PARAMTYPE
py::enum_<Interface_ParamType>(mod, "Interface_ParamType", "None")
	.value("Interface_ParamMisc", Interface_ParamType::Interface_ParamMisc)
	.value("Interface_ParamInteger", Interface_ParamType::Interface_ParamInteger)
	.value("Interface_ParamReal", Interface_ParamType::Interface_ParamReal)
	.value("Interface_ParamIdent", Interface_ParamType::Interface_ParamIdent)
	.value("Interface_ParamVoid", Interface_ParamType::Interface_ParamVoid)
	.value("Interface_ParamText", Interface_ParamType::Interface_ParamText)
	.value("Interface_ParamEnum", Interface_ParamType::Interface_ParamEnum)
	.value("Interface_ParamLogical", Interface_ParamType::Interface_ParamLogical)
	.value("Interface_ParamSub", Interface_ParamType::Interface_ParamSub)
	.value("Interface_ParamHexa", Interface_ParamType::Interface_ParamHexa)
	.value("Interface_ParamBinary", Interface_ParamType::Interface_ParamBinary)
	.export_values();


// TYPEDEF: INTERFACE_ARRAY1OFHASCIISTRING
bind_NCollection_Array1<opencascade::handle<TCollection_HAsciiString> >(mod, "Interface_Array1OfHAsciiString", py::module_local(false));

// CLASS: INTERFACE_HARRAY1OFHASCIISTRING
py::class_<Interface_HArray1OfHAsciiString, opencascade::handle<Interface_HArray1OfHAsciiString>, Standard_Transient> cls_Interface_HArray1OfHAsciiString(mod, "Interface_HArray1OfHAsciiString", "None", py::multiple_inheritance());

// Constructors
cls_Interface_HArray1OfHAsciiString.def(py::init<>());
cls_Interface_HArray1OfHAsciiString.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_Interface_HArray1OfHAsciiString.def(py::init<const Standard_Integer, const Standard_Integer, const Interface_Array1OfHAsciiString::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_Interface_HArray1OfHAsciiString.def(py::init<const Interface_Array1OfHAsciiString &>(), py::arg("theOther"));

// Methods
// cls_Interface_HArray1OfHAsciiString.def_static("operator new_", (void * (*)(size_t)) &Interface_HArray1OfHAsciiString::operator new, "None", py::arg("theSize"));
// cls_Interface_HArray1OfHAsciiString.def_static("operator delete_", (void (*)(void *)) &Interface_HArray1OfHAsciiString::operator delete, "None", py::arg("theAddress"));
// cls_Interface_HArray1OfHAsciiString.def_static("operator new[]_", (void * (*)(size_t)) &Interface_HArray1OfHAsciiString::operator new[], "None", py::arg("theSize"));
// cls_Interface_HArray1OfHAsciiString.def_static("operator delete[]_", (void (*)(void *)) &Interface_HArray1OfHAsciiString::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_HArray1OfHAsciiString.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_HArray1OfHAsciiString::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_HArray1OfHAsciiString.def_static("operator delete_", (void (*)(void *, void *)) &Interface_HArray1OfHAsciiString::operator delete, "None", py::arg(""), py::arg(""));
// cls_Interface_HArray1OfHAsciiString.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Interface_HArray1OfHAsciiString::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Interface_HArray1OfHAsciiString.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Interface_HArray1OfHAsciiString::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Interface_HArray1OfHAsciiString.def("Array1", (const Interface_Array1OfHAsciiString & (Interface_HArray1OfHAsciiString::*)() const) &Interface_HArray1OfHAsciiString::Array1, "None");
cls_Interface_HArray1OfHAsciiString.def("ChangeArray1", (Interface_Array1OfHAsciiString & (Interface_HArray1OfHAsciiString::*)()) &Interface_HArray1OfHAsciiString::ChangeArray1, "None");
cls_Interface_HArray1OfHAsciiString.def_static("get_type_name_", (const char * (*)()) &Interface_HArray1OfHAsciiString::get_type_name, "None");
cls_Interface_HArray1OfHAsciiString.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_HArray1OfHAsciiString::get_type_descriptor, "None");
cls_Interface_HArray1OfHAsciiString.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_HArray1OfHAsciiString::*)() const) &Interface_HArray1OfHAsciiString::DynamicType, "None");

// TYPEDEF: INTERFACE_DATAMAPOFTRANSIENTINTEGER
bind_NCollection_DataMap<opencascade::handle<Standard_Transient>, int, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "Interface_DataMapOfTransientInteger", py::module_local(false));

// TYPEDEF: INTERFACE_DATAMAPITERATOROFDATAMAPOFTRANSIENTINTEGER

// CLASS: INTERFACE_PROTOCOL
py::class_<Interface_Protocol, opencascade::handle<Interface_Protocol>, Standard_Transient> cls_Interface_Protocol(mod, "Interface_Protocol", "General description of Interface Protocols. A Protocol defines a set of Entity types. This class provides also the notion of Active Protocol, as a working context, defined once then exploited by various Tools and Libraries.");

// Methods
cls_Interface_Protocol.def_static("Active_", (opencascade::handle<Interface_Protocol> (*)()) &Interface_Protocol::Active, "Returns the Active Protocol, if defined (else, returns a Null Handle, which means 'no defined active protocol')");
cls_Interface_Protocol.def_static("SetActive_", (void (*)(const opencascade::handle<Interface_Protocol> &)) &Interface_Protocol::SetActive, "Sets a given Protocol to be the Active one (for the users of Active, see just above). Applies to every sub-type of Protocol", py::arg("aprotocol"));
cls_Interface_Protocol.def_static("ClearActive_", (void (*)()) &Interface_Protocol::ClearActive, "Erases the Active Protocol (hence it becomes undefined)");
cls_Interface_Protocol.def("NbResources", (Standard_Integer (Interface_Protocol::*)() const) &Interface_Protocol::NbResources, "Returns count of Protocol used as Resources (level one)");
cls_Interface_Protocol.def("Resource", (opencascade::handle<Interface_Protocol> (Interface_Protocol::*)(const Standard_Integer) const) &Interface_Protocol::Resource, "Returns a Resource, given its rank (between 1 and NbResources)", py::arg("num"));
cls_Interface_Protocol.def("CaseNumber", (Standard_Integer (Interface_Protocol::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_Protocol::CaseNumber, "Returns a unique positive CaseNumber for each Recognized Object. By default, recognition is based on Type(1) By default, calls the following one which is deferred.", py::arg("obj"));
cls_Interface_Protocol.def("IsDynamicType", (Standard_Boolean (Interface_Protocol::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_Protocol::IsDynamicType, "Returns True if type of <obj> is that defined from CDL This is the default but it may change according implementation", py::arg("obj"));
cls_Interface_Protocol.def("NbTypes", (Standard_Integer (Interface_Protocol::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_Protocol::NbTypes, "Returns the count of DISTINCT types under which an entity may be processed. Each one is candidate to be recognized by TypeNumber, <obj> is then processed according it By default, returns 1 (the DynamicType)", py::arg("obj"));
cls_Interface_Protocol.def("Type", [](Interface_Protocol &self, const opencascade::handle<Standard_Transient> & a0) -> opencascade::handle<Standard_Type> { return self.Type(a0); });
cls_Interface_Protocol.def("Type", (opencascade::handle<Standard_Type> (Interface_Protocol::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer) const) &Interface_Protocol::Type, "Returns a type under which <obj> can be recognized and processed, according its rank in its definition list (see NbTypes). By default, returns DynamicType", py::arg("obj"), py::arg("nt"));
cls_Interface_Protocol.def("TypeNumber", (Standard_Integer (Interface_Protocol::*)(const opencascade::handle<Standard_Type> &) const) &Interface_Protocol::TypeNumber, "Returns a unique positive CaseNumber for each Recognized Type, Returns Zero for '<type> not recognized'", py::arg("atype"));
cls_Interface_Protocol.def("GlobalCheck", (Standard_Boolean (Interface_Protocol::*)(const Interface_Graph &, opencascade::handle<Interface_Check> &) const) &Interface_Protocol::GlobalCheck, "Evaluates a Global Check for a model (with its Graph) Returns True when done, False if data in model do not apply", py::arg("G"), py::arg("ach"));
cls_Interface_Protocol.def("NewModel", (opencascade::handle<Interface_InterfaceModel> (Interface_Protocol::*)() const) &Interface_Protocol::NewModel, "Creates an empty Model of the considered Norm");
cls_Interface_Protocol.def("IsSuitableModel", (Standard_Boolean (Interface_Protocol::*)(const opencascade::handle<Interface_InterfaceModel> &) const) &Interface_Protocol::IsSuitableModel, "Returns True if <model> is a Model of the considered Norm", py::arg("model"));
cls_Interface_Protocol.def("UnknownEntity", (opencascade::handle<Standard_Transient> (Interface_Protocol::*)() const) &Interface_Protocol::UnknownEntity, "Creates a new Unknown Entity for the considered Norm");
cls_Interface_Protocol.def("IsUnknownEntity", (Standard_Boolean (Interface_Protocol::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_Protocol::IsUnknownEntity, "Returns True if <ent> is an Unknown Entity for the Norm, i.e. same Type as them created by method UnknownEntity (for an Entity out of the Norm, answer can be unpredicable)", py::arg("ent"));
cls_Interface_Protocol.def_static("get_type_name_", (const char * (*)()) &Interface_Protocol::get_type_name, "None");
cls_Interface_Protocol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_Protocol::get_type_descriptor, "None");
cls_Interface_Protocol.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_Protocol::*)() const) &Interface_Protocol::DynamicType, "None");

// CLASS: INTERFACE_BITMAP
py::class_<Interface_BitMap> cls_Interface_BitMap(mod, "Interface_BitMap", "A bit map simply allows to associate a boolean flag to each item of a list, such as a list of entities, etc... numbered between 1 and a positive count nbitems");

// Constructors
cls_Interface_BitMap.def(py::init<>());
cls_Interface_BitMap.def(py::init<const Standard_Integer>(), py::arg("nbitems"));
cls_Interface_BitMap.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("nbitems"), py::arg("resflags"));
cls_Interface_BitMap.def(py::init<const Interface_BitMap &>(), py::arg("other"));
cls_Interface_BitMap.def(py::init<const Interface_BitMap &, const Standard_Boolean>(), py::arg("other"), py::arg("copied"));

// Methods
// cls_Interface_BitMap.def_static("operator new_", (void * (*)(size_t)) &Interface_BitMap::operator new, "None", py::arg("theSize"));
// cls_Interface_BitMap.def_static("operator delete_", (void (*)(void *)) &Interface_BitMap::operator delete, "None", py::arg("theAddress"));
// cls_Interface_BitMap.def_static("operator new[]_", (void * (*)(size_t)) &Interface_BitMap::operator new[], "None", py::arg("theSize"));
// cls_Interface_BitMap.def_static("operator delete[]_", (void (*)(void *)) &Interface_BitMap::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_BitMap.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_BitMap::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_BitMap.def_static("operator delete_", (void (*)(void *, void *)) &Interface_BitMap::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_BitMap.def("Initialize", [](Interface_BitMap &self, const Standard_Integer a0) -> void { return self.Initialize(a0); });
cls_Interface_BitMap.def("Initialize", (void (Interface_BitMap::*)(const Standard_Integer, const Standard_Integer)) &Interface_BitMap::Initialize, "Initialize empty bit by <nbitems> items One flag is defined, n0 0 <resflags> prepares allocation for <resflags> more flags Flags values start at false", py::arg("nbitems"), py::arg("resflags"));
cls_Interface_BitMap.def("Initialize", [](Interface_BitMap &self, const Interface_BitMap & a0) -> void { return self.Initialize(a0); });
cls_Interface_BitMap.def("Initialize", (void (Interface_BitMap::*)(const Interface_BitMap &, const Standard_Boolean)) &Interface_BitMap::Initialize, "Initialize a BitMap from another one", py::arg("other"), py::arg("copied"));
cls_Interface_BitMap.def("Internals", [](Interface_BitMap &self, Standard_Integer & nbitems, Standard_Integer & nbwords, Standard_Integer & nbflags, opencascade::handle<TColStd_HArray1OfInteger> & flags, opencascade::handle<TColStd_HSequenceOfAsciiString> & names){ self.Internals(nbitems, nbwords, nbflags, flags, names); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(nbitems, nbwords, nbflags); }, "Returns internal values, used for copying Flags values start at false", py::arg("nbitems"), py::arg("nbwords"), py::arg("nbflags"), py::arg("flags"), py::arg("names"));
cls_Interface_BitMap.def("Reservate", (void (Interface_BitMap::*)(const Standard_Integer)) &Interface_BitMap::Reservate, "Reservates for a count of more flags", py::arg("moreflags"));
cls_Interface_BitMap.def("SetLength", (void (Interface_BitMap::*)(const Standard_Integer)) &Interface_BitMap::SetLength, "Sets for a new count of items, which can be either less or greater than the former one For new items, their flags start at false", py::arg("nbitems"));
cls_Interface_BitMap.def("AddFlag", [](Interface_BitMap &self) -> Standard_Integer { return self.AddFlag(); });
cls_Interface_BitMap.def("AddFlag", (Standard_Integer (Interface_BitMap::*)(const Standard_CString)) &Interface_BitMap::AddFlag, "Adds a flag, a name can be attached to it Returns its flag number Makes required reservation", py::arg("name"));
cls_Interface_BitMap.def("AddSomeFlags", (Standard_Integer (Interface_BitMap::*)(const Standard_Integer)) &Interface_BitMap::AddSomeFlags, "Adds several flags (<more>) with no name Returns the number of last added flag", py::arg("more"));
cls_Interface_BitMap.def("RemoveFlag", (Standard_Boolean (Interface_BitMap::*)(const Standard_Integer)) &Interface_BitMap::RemoveFlag, "Removes a flag given its number. Returns True if done, false if num is out of range", py::arg("num"));
cls_Interface_BitMap.def("SetFlagName", (Standard_Boolean (Interface_BitMap::*)(const Standard_Integer, const Standard_CString)) &Interface_BitMap::SetFlagName, "Sets a name for a flag, given its number name can be empty (to erase the name of a flag) Returns True if done, false if : num is out of range, or name non-empty already set to another flag", py::arg("num"), py::arg("name"));
cls_Interface_BitMap.def("NbFlags", (Standard_Integer (Interface_BitMap::*)() const) &Interface_BitMap::NbFlags, "Returns the count of flags (flag 0 not included)");
cls_Interface_BitMap.def("Length", (Standard_Integer (Interface_BitMap::*)() const) &Interface_BitMap::Length, "Returns the count of items (i.e. the length of the bitmap)");
cls_Interface_BitMap.def("FlagName", (Standard_CString (Interface_BitMap::*)(const Standard_Integer) const) &Interface_BitMap::FlagName, "Returns the name recorded for a flag, or an empty string", py::arg("num"));
cls_Interface_BitMap.def("FlagNumber", (Standard_Integer (Interface_BitMap::*)(const Standard_CString) const) &Interface_BitMap::FlagNumber, "Returns the number or a flag given its name, or zero", py::arg("name"));
cls_Interface_BitMap.def("Value", [](Interface_BitMap &self, const Standard_Integer a0) -> Standard_Boolean { return self.Value(a0); });
cls_Interface_BitMap.def("Value", (Standard_Boolean (Interface_BitMap::*)(const Standard_Integer, const Standard_Integer) const) &Interface_BitMap::Value, "Returns the value (true/false) of a flag, from : - the number of the item - the flag number, by default 0", py::arg("item"), py::arg("flag"));
cls_Interface_BitMap.def("SetValue", [](Interface_BitMap &self, const Standard_Integer a0, const Standard_Boolean a1) -> void { return self.SetValue(a0, a1); });
cls_Interface_BitMap.def("SetValue", (void (Interface_BitMap::*)(const Standard_Integer, const Standard_Boolean, const Standard_Integer) const) &Interface_BitMap::SetValue, "Sets a new value for a flag", py::arg("item"), py::arg("val"), py::arg("flag"));
cls_Interface_BitMap.def("SetTrue", [](Interface_BitMap &self, const Standard_Integer a0) -> void { return self.SetTrue(a0); });
cls_Interface_BitMap.def("SetTrue", (void (Interface_BitMap::*)(const Standard_Integer, const Standard_Integer) const) &Interface_BitMap::SetTrue, "Sets a flag to True", py::arg("item"), py::arg("flag"));
cls_Interface_BitMap.def("SetFalse", [](Interface_BitMap &self, const Standard_Integer a0) -> void { return self.SetFalse(a0); });
cls_Interface_BitMap.def("SetFalse", (void (Interface_BitMap::*)(const Standard_Integer, const Standard_Integer) const) &Interface_BitMap::SetFalse, "Sets a flag to False", py::arg("item"), py::arg("flag"));
cls_Interface_BitMap.def("CTrue", [](Interface_BitMap &self, const Standard_Integer a0) -> Standard_Boolean { return self.CTrue(a0); });
cls_Interface_BitMap.def("CTrue", (Standard_Boolean (Interface_BitMap::*)(const Standard_Integer, const Standard_Integer) const) &Interface_BitMap::CTrue, "Returns the former value for a flag and sets it to True (before : value returned; after : True)", py::arg("item"), py::arg("flag"));
cls_Interface_BitMap.def("CFalse", [](Interface_BitMap &self, const Standard_Integer a0) -> Standard_Boolean { return self.CFalse(a0); });
cls_Interface_BitMap.def("CFalse", (Standard_Boolean (Interface_BitMap::*)(const Standard_Integer, const Standard_Integer) const) &Interface_BitMap::CFalse, "Returns the former value for a flag and sets it to False (before : value returned; after : False)", py::arg("item"), py::arg("flag"));
cls_Interface_BitMap.def("Init", [](Interface_BitMap &self, const Standard_Boolean a0) -> void { return self.Init(a0); });
cls_Interface_BitMap.def("Init", (void (Interface_BitMap::*)(const Standard_Boolean, const Standard_Integer) const) &Interface_BitMap::Init, "Initialises all the values of Flag Number <flag> to a given value <val>", py::arg("val"), py::arg("flag"));
cls_Interface_BitMap.def("Clear", (void (Interface_BitMap::*)()) &Interface_BitMap::Clear, "Clear all field of bit map");

// CLASS: INTERFACE_INTERFACEMODEL
py::class_<Interface_InterfaceModel, opencascade::handle<Interface_InterfaceModel>, Standard_Transient> cls_Interface_InterfaceModel(mod, "Interface_InterfaceModel", "Defines an (Indexed) Set of data corresponding to a complete Transfer by a File Interface, i.e. File Header and Transient Entities (Objects) contained in a File. Contained Entities are identified in the Model by unique and consecutive Numbers.");

// Methods
cls_Interface_InterfaceModel.def("Destroy", (void (Interface_InterfaceModel::*)()) &Interface_InterfaceModel::Destroy, "Clears the list of entities (service WhenDelete)");
cls_Interface_InterfaceModel.def("SetProtocol", (void (Interface_InterfaceModel::*)(const opencascade::handle<Interface_Protocol> &)) &Interface_InterfaceModel::SetProtocol, "Sets a Protocol for this Model It is also set by a call to AddWithRefs with Protocol It is used for : DumpHeader (as required), ClearEntities ...", py::arg("proto"));
cls_Interface_InterfaceModel.def("Protocol", (opencascade::handle<Interface_Protocol> (Interface_InterfaceModel::*)() const) &Interface_InterfaceModel::Protocol, "Returns the Protocol which has been set by SetProtocol, or AddWithRefs with Protocol");
cls_Interface_InterfaceModel.def("SetGTool", (void (Interface_InterfaceModel::*)(const opencascade::handle<Interface_GTool> &)) &Interface_InterfaceModel::SetGTool, "Sets a GTool for this model, which already defines a Protocol", py::arg("gtool"));
cls_Interface_InterfaceModel.def("GTool", (opencascade::handle<Interface_GTool> (Interface_InterfaceModel::*)() const) &Interface_InterfaceModel::GTool, "Returns the GTool, set by SetProtocol or by SetGTool");
cls_Interface_InterfaceModel.def("DispatchStatus", (Standard_Boolean & (Interface_InterfaceModel::*)()) &Interface_InterfaceModel::DispatchStatus, "Returns the Dispatch Status, either for get or set A Model which is produced from Dispatch may share entities with the original (according to the Protocol), hence these non-copied entities should not be deleted");
cls_Interface_InterfaceModel.def("Clear", (void (Interface_InterfaceModel::*)()) &Interface_InterfaceModel::Clear, "Erases contained data; used when a Model is copied to others : the new copied ones begin from clear Clear calls specific method ClearHeader (see below)");
cls_Interface_InterfaceModel.def("ClearEntities", (void (Interface_InterfaceModel::*)()) &Interface_InterfaceModel::ClearEntities, "Clears the entities; uses the general service WhenDelete, in addition to the standard Memory Manager; can be redefined");
cls_Interface_InterfaceModel.def("ClearLabels", (void (Interface_InterfaceModel::*)()) &Interface_InterfaceModel::ClearLabels, "Erases informations about labels, if any : specific to each norm");
cls_Interface_InterfaceModel.def("ClearHeader", (void (Interface_InterfaceModel::*)()) &Interface_InterfaceModel::ClearHeader, "Clears Model's header : specific to each norm");
cls_Interface_InterfaceModel.def("NbEntities", (Standard_Integer (Interface_InterfaceModel::*)() const) &Interface_InterfaceModel::NbEntities, "Returns count of contained Entities");
cls_Interface_InterfaceModel.def("Contains", (Standard_Boolean (Interface_InterfaceModel::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_InterfaceModel::Contains, "Returns True if a Model contains an Entity (for a ReportEntity, looks for the ReportEntity itself AND its Concerned Entity)", py::arg("anentity"));
cls_Interface_InterfaceModel.def("Number", (Standard_Integer (Interface_InterfaceModel::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_InterfaceModel::Number, "Returns the Number of an Entity in the Model if it contains it. Else returns 0. For a ReportEntity, looks at Concerned Entity. Returns the Directory entry Number of an Entity in the Model if it contains it. Else returns 0. For a ReportEntity, looks at Concerned Entity.", py::arg("anentity"));
cls_Interface_InterfaceModel.def("Value", (const opencascade::handle<Standard_Transient> & (Interface_InterfaceModel::*)(const Standard_Integer) const) &Interface_InterfaceModel::Value, "Returns an Entity identified by its number in the Model Each sub-class of InterfaceModel can define its own method Entity to return its specific class of Entity (e.g. for VDA, VDAModel returns a VDAEntity), working by calling Value Remark : For a Reported Entity, (Erroneous, Corrected, Unknown), this method returns this Reported Entity. See ReportEntity for other questions.", py::arg("num"));
cls_Interface_InterfaceModel.def("NbTypes", (Standard_Integer (Interface_InterfaceModel::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_InterfaceModel::NbTypes, "Returns the count of DISTINCT types under which an entity may be processed. Defined by the Protocol, which gives default as 1 (dynamic Type).", py::arg("ent"));
cls_Interface_InterfaceModel.def("Type", [](Interface_InterfaceModel &self, const opencascade::handle<Standard_Transient> & a0) -> opencascade::handle<Standard_Type> { return self.Type(a0); });
cls_Interface_InterfaceModel.def("Type", (opencascade::handle<Standard_Type> (Interface_InterfaceModel::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer) const) &Interface_InterfaceModel::Type, "Returns a type, given its rank : defined by the Protocol (by default, the first one)", py::arg("ent"), py::arg("num"));
cls_Interface_InterfaceModel.def("TypeName", [](Interface_InterfaceModel &self, const opencascade::handle<Standard_Transient> & a0) -> Standard_CString { return self.TypeName(a0); });
cls_Interface_InterfaceModel.def("TypeName", (Standard_CString (Interface_InterfaceModel::*)(const opencascade::handle<Standard_Transient> &, const Standard_Boolean) const) &Interface_InterfaceModel::TypeName, "Returns the type name of an entity, from the list of types (one or more ...) <complete> True (D) gives the complete type, else packages are removed WARNING : buffered, to be immediately copied or printed", py::arg("ent"), py::arg("complete"));
cls_Interface_InterfaceModel.def_static("ClassName_", (Standard_CString (*)(const Standard_CString)) &Interface_InterfaceModel::ClassName, "From a CDL Type Name, returns the Class part (package dropped) WARNING : buffered, to be immediately copied or printed", py::arg("typnam"));
cls_Interface_InterfaceModel.def("EntityState", (Interface_DataState (Interface_InterfaceModel::*)(const Standard_Integer) const) &Interface_InterfaceModel::EntityState, "Returns the State of an entity, given its number", py::arg("num"));
cls_Interface_InterfaceModel.def("IsReportEntity", [](Interface_InterfaceModel &self, const Standard_Integer a0) -> Standard_Boolean { return self.IsReportEntity(a0); });
cls_Interface_InterfaceModel.def("IsReportEntity", (Standard_Boolean (Interface_InterfaceModel::*)(const Standard_Integer, const Standard_Boolean) const) &Interface_InterfaceModel::IsReportEntity, "Returns True if <num> identifies a ReportEntity in the Model Hence, ReportEntity can be called.", py::arg("num"), py::arg("semantic"));
cls_Interface_InterfaceModel.def("ReportEntity", [](Interface_InterfaceModel &self, const Standard_Integer a0) -> opencascade::handle<Interface_ReportEntity> { return self.ReportEntity(a0); });
cls_Interface_InterfaceModel.def("ReportEntity", (opencascade::handle<Interface_ReportEntity> (Interface_InterfaceModel::*)(const Standard_Integer, const Standard_Boolean) const) &Interface_InterfaceModel::ReportEntity, "Returns a ReportEntity identified by its number in the Model, or a Null Handle If <num> does not identify a ReportEntity.", py::arg("num"), py::arg("semantic"));
cls_Interface_InterfaceModel.def("IsErrorEntity", (Standard_Boolean (Interface_InterfaceModel::*)(const Standard_Integer) const) &Interface_InterfaceModel::IsErrorEntity, "Returns True if <num> identifies an Error Entity : in this case, a ReportEntity brings Fail Messages and possibly an 'undefined' Content, see IsRedefinedEntity", py::arg("num"));
cls_Interface_InterfaceModel.def("IsRedefinedContent", (Standard_Boolean (Interface_InterfaceModel::*)(const Standard_Integer) const) &Interface_InterfaceModel::IsRedefinedContent, "Returns True if <num> identifies an Entity which content is redefined through a ReportEntity (i.e. with literal data only) This happens when an entity is syntactically erroneous in the way that its basic content remains empty. For more details (such as content itself), see ReportEntity", py::arg("num"));
cls_Interface_InterfaceModel.def("ClearReportEntity", (Standard_Boolean (Interface_InterfaceModel::*)(const Standard_Integer)) &Interface_InterfaceModel::ClearReportEntity, "Removes the ReportEntity attached to Entity <num>. Returns True if done, False if no ReportEntity was attached to <num>. Warning : the caller must assume that this clearing is meaningfull", py::arg("num"));
cls_Interface_InterfaceModel.def("SetReportEntity", (Standard_Boolean (Interface_InterfaceModel::*)(const Standard_Integer, const opencascade::handle<Interface_ReportEntity> &)) &Interface_InterfaceModel::SetReportEntity, "Sets or Replaces a ReportEntity for the Entity <num>. Returns True if Report is replaced, False if it has been replaced Warning : the caller must assume that this setting is meaningfull", py::arg("num"), py::arg("rep"));
cls_Interface_InterfaceModel.def("AddReportEntity", [](Interface_InterfaceModel &self, const opencascade::handle<Interface_ReportEntity> & a0) -> Standard_Boolean { return self.AddReportEntity(a0); });
cls_Interface_InterfaceModel.def("AddReportEntity", (Standard_Boolean (Interface_InterfaceModel::*)(const opencascade::handle<Interface_ReportEntity> &, const Standard_Boolean)) &Interface_InterfaceModel::AddReportEntity, "Adds a ReportEntity as such. Returns False if the concerned entity is not recorded in the Model Else, adds it into, either the main report list or the list for semantic checks, then returns True", py::arg("rep"), py::arg("semantic"));
cls_Interface_InterfaceModel.def("IsUnknownEntity", (Standard_Boolean (Interface_InterfaceModel::*)(const Standard_Integer) const) &Interface_InterfaceModel::IsUnknownEntity, "Returns True if <num> identifies an Unknown Entity : in this case, a ReportEntity with no Check Messages designates it.", py::arg("num"));
cls_Interface_InterfaceModel.def("FillSemanticChecks", [](Interface_InterfaceModel &self, const Interface_CheckIterator & a0) -> void { return self.FillSemanticChecks(a0); });
cls_Interface_InterfaceModel.def("FillSemanticChecks", (void (Interface_InterfaceModel::*)(const Interface_CheckIterator &, const Standard_Boolean)) &Interface_InterfaceModel::FillSemanticChecks, "Fills the list of semantic checks. This list is computed (by CheckTool). Hence, it can be stored in the model for later queries <clear> True (D) : new list replaces <clear> False : new list is cumulated", py::arg("checks"), py::arg("clear"));
cls_Interface_InterfaceModel.def("HasSemanticChecks", (Standard_Boolean (Interface_InterfaceModel::*)() const) &Interface_InterfaceModel::HasSemanticChecks, "Returns True if semantic checks have been filled");
cls_Interface_InterfaceModel.def("Check", (const opencascade::handle<Interface_Check> & (Interface_InterfaceModel::*)(const Standard_Integer, const Standard_Boolean) const) &Interface_InterfaceModel::Check, "Returns the check attached to an entity, designated by its Number. 0 for global check <semantic> True : recorded semantic check <semantic> False : recorded syntactic check (see ReportEntity) If no check is recorded for <num>, returns an empty Check", py::arg("num"), py::arg("syntactic"));
cls_Interface_InterfaceModel.def("Reservate", (void (Interface_InterfaceModel::*)(const Standard_Integer)) &Interface_InterfaceModel::Reservate, "Does a reservation for the List of Entities (for optimized storage management). If it is not called, storage management can be less efficient. <nbent> is the expected count of Entities to store", py::arg("nbent"));
cls_Interface_InterfaceModel.def("AddEntity", (void (Interface_InterfaceModel::*)(const opencascade::handle<Standard_Transient> &)) &Interface_InterfaceModel::AddEntity, "Internal method for adding an Entity. Used by file reading (defined by each Interface) and Transfer tools. It adds the entity required to be added, not its refs : see AddWithRefs. If <anentity> is a ReportEntity, it is added to the list of Reports, its Concerned Entity (Erroneous or Corrected, else Unknown) is added to the list of Entities. That is, the ReportEntity must be created before Adding", py::arg("anentity"));
cls_Interface_InterfaceModel.def("AddWithRefs", [](Interface_InterfaceModel &self, const opencascade::handle<Standard_Transient> & a0, const opencascade::handle<Interface_Protocol> & a1) -> void { return self.AddWithRefs(a0, a1); });
cls_Interface_InterfaceModel.def("AddWithRefs", [](Interface_InterfaceModel &self, const opencascade::handle<Standard_Transient> & a0, const opencascade::handle<Interface_Protocol> & a1, const Standard_Integer a2) -> void { return self.AddWithRefs(a0, a1, a2); });
cls_Interface_InterfaceModel.def("AddWithRefs", (void (Interface_InterfaceModel::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_Protocol> &, const Standard_Integer, const Standard_Boolean)) &Interface_InterfaceModel::AddWithRefs, "Adds to the Model, an Entity with all its References, as they are defined by General Services FillShared and ListImplied. Process is recursive (any sub-levels) if <level> = 0 (Default) Else, adds sub-entities until the required sub-level. Especially, if <level> = 1, adds immediate subs and that's all", py::arg("anent"), py::arg("proto"), py::arg("level"), py::arg("listall"));
cls_Interface_InterfaceModel.def("AddWithRefs", [](Interface_InterfaceModel &self, const opencascade::handle<Standard_Transient> & a0) -> void { return self.AddWithRefs(a0); });
cls_Interface_InterfaceModel.def("AddWithRefs", [](Interface_InterfaceModel &self, const opencascade::handle<Standard_Transient> & a0, const Standard_Integer a1) -> void { return self.AddWithRefs(a0, a1); });
cls_Interface_InterfaceModel.def("AddWithRefs", (void (Interface_InterfaceModel::*)(const opencascade::handle<Standard_Transient> &, const Standard_Integer, const Standard_Boolean)) &Interface_InterfaceModel::AddWithRefs, "Same as above, but works with the Protocol of the Model", py::arg("anent"), py::arg("level"), py::arg("listall"));
cls_Interface_InterfaceModel.def("AddWithRefs", [](Interface_InterfaceModel &self, const opencascade::handle<Standard_Transient> & a0, const Interface_GeneralLib & a1) -> void { return self.AddWithRefs(a0, a1); });
cls_Interface_InterfaceModel.def("AddWithRefs", [](Interface_InterfaceModel &self, const opencascade::handle<Standard_Transient> & a0, const Interface_GeneralLib & a1, const Standard_Integer a2) -> void { return self.AddWithRefs(a0, a1, a2); });
cls_Interface_InterfaceModel.def("AddWithRefs", (void (Interface_InterfaceModel::*)(const opencascade::handle<Standard_Transient> &, const Interface_GeneralLib &, const Standard_Integer, const Standard_Boolean)) &Interface_InterfaceModel::AddWithRefs, "Same as above, but works with an already created GeneralLib", py::arg("anent"), py::arg("lib"), py::arg("level"), py::arg("listall"));
cls_Interface_InterfaceModel.def("ReplaceEntity", (void (Interface_InterfaceModel::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &)) &Interface_InterfaceModel::ReplaceEntity, "Replace Entity with Number=nument on other entity - 'anent'", py::arg("nument"), py::arg("anent"));
cls_Interface_InterfaceModel.def("ReverseOrders", [](Interface_InterfaceModel &self) -> void { return self.ReverseOrders(); });
cls_Interface_InterfaceModel.def("ReverseOrders", (void (Interface_InterfaceModel::*)(const Standard_Integer)) &Interface_InterfaceModel::ReverseOrders, "Reverses the Numbers of the Entities, between <after> and the total count of Entities. Thus, the entities : 1,2 ... after, after+1 ... nb-1, nb become numbered as : 1,2 ... after, nb, nb-1 ... after+1 By default (after = 0) the whole list of Entities is reversed", py::arg("after"));
cls_Interface_InterfaceModel.def("ChangeOrder", [](Interface_InterfaceModel &self, const Standard_Integer a0, const Standard_Integer a1) -> void { return self.ChangeOrder(a0, a1); });
cls_Interface_InterfaceModel.def("ChangeOrder", (void (Interface_InterfaceModel::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &Interface_InterfaceModel::ChangeOrder, "Changes the Numbers of some Entities : <oldnum> is moved to <newnum>, same for <count> entities. Thus : 1,2 ... newnum-1 newnum ... oldnum .. oldnum+count oldnum+count+1 .. gives 1,2 ... newnum-1 oldnum .. oldnum+count newnum ... oldnum+count+1 (can be seen as a circular permutation)", py::arg("oldnum"), py::arg("newnum"), py::arg("count"));
cls_Interface_InterfaceModel.def("GetFromTransfer", (void (Interface_InterfaceModel::*)(const Interface_EntityIterator &)) &Interface_InterfaceModel::GetFromTransfer, "Gets contents from an EntityIterator, prepared by a Transfer tool (e.g TransferCopy). Starts from clear", py::arg("aniter"));
cls_Interface_InterfaceModel.def("GetFromAnother", (void (Interface_InterfaceModel::*)(const opencascade::handle<Interface_InterfaceModel> &)) &Interface_InterfaceModel::GetFromAnother, "Gets header (data specific of a defined Interface) from another InterfaceModel; called from TransferCopy", py::arg("other"));
cls_Interface_InterfaceModel.def("NewEmptyModel", (opencascade::handle<Interface_InterfaceModel> (Interface_InterfaceModel::*)() const) &Interface_InterfaceModel::NewEmptyModel, "Returns a New Empty Model, same type as <me> (whatever its Type); called to Copy parts a Model into other ones, then followed by a call to GetFromAnother (Header) then filling with specified Entities, themselves copied");
cls_Interface_InterfaceModel.def("SetCategoryNumber", (Standard_Boolean (Interface_InterfaceModel::*)(const Standard_Integer, const Standard_Integer)) &Interface_InterfaceModel::SetCategoryNumber, "Records a category number for an entity number Returns True when done, False if <num> is out of range", py::arg("num"), py::arg("val"));
cls_Interface_InterfaceModel.def("CategoryNumber", (Standard_Integer (Interface_InterfaceModel::*)(const Standard_Integer) const) &Interface_InterfaceModel::CategoryNumber, "Returns the recorded category number for a given entity number 0 if none was defined for this entity", py::arg("num"));
cls_Interface_InterfaceModel.def("FillIterator", (void (Interface_InterfaceModel::*)(Interface_EntityIterator &) const) &Interface_InterfaceModel::FillIterator, "Allows an EntityIterator to get a list of Entities", py::arg("iter"));
cls_Interface_InterfaceModel.def("Entities", (Interface_EntityIterator (Interface_InterfaceModel::*)() const) &Interface_InterfaceModel::Entities, "Returns the list of all Entities, as an Iterator on Entities (the Entities themselves, not the Reports)");
cls_Interface_InterfaceModel.def("Reports", [](Interface_InterfaceModel &self) -> Interface_EntityIterator { return self.Reports(); });
cls_Interface_InterfaceModel.def("Reports", (Interface_EntityIterator (Interface_InterfaceModel::*)(const Standard_Boolean) const) &Interface_InterfaceModel::Reports, "Returns the list of all ReportEntities, i.e. data about Entities read with Error or Warning informations (each item has to be casted to Report Entity then it can be queried for Concerned Entity, Content, Check ...) By default, returns the main reports, is <semantic> is True it returns the list for sematic checks", py::arg("semantic"));
cls_Interface_InterfaceModel.def("Redefineds", (Interface_EntityIterator (Interface_InterfaceModel::*)() const) &Interface_InterfaceModel::Redefineds, "Returns the list of ReportEntities which redefine data (generally, if concerned entity is 'Error', a literal content is added to it : this is a 'redefined entity'");
cls_Interface_InterfaceModel.def("GlobalCheck", [](Interface_InterfaceModel &self) -> const opencascade::handle<Interface_Check> & { return self.GlobalCheck(); });
cls_Interface_InterfaceModel.def("GlobalCheck", (const opencascade::handle<Interface_Check> & (Interface_InterfaceModel::*)(const Standard_Boolean) const) &Interface_InterfaceModel::GlobalCheck, "Returns the GlobalCheck, which memorizes messages global to the file (not specific to an Entity), especially Header", py::arg("syntactic"));
cls_Interface_InterfaceModel.def("SetGlobalCheck", (void (Interface_InterfaceModel::*)(const opencascade::handle<Interface_Check> &)) &Interface_InterfaceModel::SetGlobalCheck, "Allows to modify GlobalCheck, after getting then completing it Remark : it is SYNTACTIC check. Semantics, see FillChecks", py::arg("ach"));
cls_Interface_InterfaceModel.def("VerifyCheck", (void (Interface_InterfaceModel::*)(opencascade::handle<Interface_Check> &) const) &Interface_InterfaceModel::VerifyCheck, "Minimum Semantic Global Check on data in model (header) Can only check basic Data. See also GlobalCheck from Protocol for a check which takes the Graph into account Default does nothing, can be redefined", py::arg("ach"));
cls_Interface_InterfaceModel.def("DumpHeader", [](Interface_InterfaceModel &self, const opencascade::handle<Message_Messenger> & a0) -> void { return self.DumpHeader(a0); });
cls_Interface_InterfaceModel.def("DumpHeader", (void (Interface_InterfaceModel::*)(const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &Interface_InterfaceModel::DumpHeader, "Dumps Header in a short, easy to read, form, onto a Stream <level> allows to print more or less parts of the header, if necessary. 0 for basic print", py::arg("S"), py::arg("level"));
cls_Interface_InterfaceModel.def("Print", [](Interface_InterfaceModel &self, const opencascade::handle<Standard_Transient> & a0, const opencascade::handle<Message_Messenger> & a1) -> void { return self.Print(a0, a1); });
cls_Interface_InterfaceModel.def("Print", (void (Interface_InterfaceModel::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &Interface_InterfaceModel::Print, "Prints identification of a given entity in <me>, in order to be printed in a list or phrase <mode> < 0 : prints only its number <mode> = 1 : just calls PrintLabel <mode> = 0 (D) : prints its number plus '/' plus PrintLabel If <ent> == <me>, simply prints 'Global' If <ent> is unknown, prints '??/its type'", py::arg("ent"), py::arg("s"), py::arg("mode"));
cls_Interface_InterfaceModel.def("PrintLabel", (void (Interface_InterfaceModel::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Message_Messenger> &) const) &Interface_InterfaceModel::PrintLabel, "Prints label specific to each norm, for a given entity. Must only print label itself, in order to be included in a phrase. Can call the result of StringLabel, but not obliged.", py::arg("ent"), py::arg("S"));
cls_Interface_InterfaceModel.def("PrintToLog", (void (Interface_InterfaceModel::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Message_Messenger> &) const) &Interface_InterfaceModel::PrintToLog, "Prints label specific to each norm in log format, for a given entity. By default, just calls PrintLabel, can be redefined", py::arg("ent"), py::arg("S"));
cls_Interface_InterfaceModel.def("StringLabel", (opencascade::handle<TCollection_HAsciiString> (Interface_InterfaceModel::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_InterfaceModel::StringLabel, "Returns a string with the label attached to a given entity. Warning : While this string may be edited on the spot, if it is a read field, the returned value must be copied before.", py::arg("ent"));
cls_Interface_InterfaceModel.def("NextNumberForLabel", [](Interface_InterfaceModel &self, const Standard_CString a0) -> Standard_Integer { return self.NextNumberForLabel(a0); });
cls_Interface_InterfaceModel.def("NextNumberForLabel", [](Interface_InterfaceModel &self, const Standard_CString a0, const Standard_Integer a1) -> Standard_Integer { return self.NextNumberForLabel(a0, a1); });
cls_Interface_InterfaceModel.def("NextNumberForLabel", (Standard_Integer (Interface_InterfaceModel::*)(const Standard_CString, const Standard_Integer, const Standard_Boolean) const) &Interface_InterfaceModel::NextNumberForLabel, "Searches a label which matches with one entity. Begins from <lastnum>+1 (default:1) and scans the entities until <NbEntities>. For the first which matches <label>, this method returns its Number. Returns 0 if nothing found Can be called recursively (labels are not specified as unique) <exact> : if True (default), exact match is required else, checks the END of entity label", py::arg("label"), py::arg("lastnum"), py::arg("exact"));
cls_Interface_InterfaceModel.def_static("HasTemplate_", (Standard_Boolean (*)(const Standard_CString)) &Interface_InterfaceModel::HasTemplate, "Returns true if a template is attached to a given name", py::arg("name"));
cls_Interface_InterfaceModel.def_static("Template_", (opencascade::handle<Interface_InterfaceModel> (*)(const Standard_CString)) &Interface_InterfaceModel::Template, "Returns the template model attached to a name, or a Null Handle", py::arg("name"));
cls_Interface_InterfaceModel.def_static("SetTemplate_", (Standard_Boolean (*)(const Standard_CString, const opencascade::handle<Interface_InterfaceModel> &)) &Interface_InterfaceModel::SetTemplate, "Records a new template model with a name. If the name was already recorded, the corresponding template is replaced by the new one. Then, WARNING : test HasTemplate to avoid surprises", py::arg("name"), py::arg("model"));
cls_Interface_InterfaceModel.def_static("ListTemplates_", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (*)()) &Interface_InterfaceModel::ListTemplates, "Returns the complete list of names attached to template models");
cls_Interface_InterfaceModel.def_static("get_type_name_", (const char * (*)()) &Interface_InterfaceModel::get_type_name, "None");
cls_Interface_InterfaceModel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_InterfaceModel::get_type_descriptor, "None");
cls_Interface_InterfaceModel.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_InterfaceModel::*)() const) &Interface_InterfaceModel::DynamicType, "None");

// CLASS: INTERFACE_GRAPH
py::class_<Interface_Graph> cls_Interface_Graph(mod, "Interface_Graph", "Gives basic data structure for operating and storing graph results (usage is normally internal) Entities are Mapped according their Number in the Model");

// Constructors
cls_Interface_Graph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const Interface_GeneralLib &>(), py::arg("amodel"), py::arg("lib"));
cls_Interface_Graph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const Interface_GeneralLib &, const Standard_Boolean>(), py::arg("amodel"), py::arg("lib"), py::arg("theModeStats"));
cls_Interface_Graph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &>(), py::arg("amodel"), py::arg("protocol"));
cls_Interface_Graph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &, const Standard_Boolean>(), py::arg("amodel"), py::arg("protocol"), py::arg("theModeStats"));
cls_Interface_Graph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_GTool> &>(), py::arg("amodel"), py::arg("gtool"));
cls_Interface_Graph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_GTool> &, const Standard_Boolean>(), py::arg("amodel"), py::arg("gtool"), py::arg("theModeStats"));
cls_Interface_Graph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("amodel"));
cls_Interface_Graph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const Standard_Boolean>(), py::arg("amodel"), py::arg("theModeStats"));
cls_Interface_Graph.def(py::init<const Interface_Graph &>(), py::arg("agraph"));
cls_Interface_Graph.def(py::init<const Interface_Graph &, const Standard_Boolean>(), py::arg("agraph"), py::arg("copied"));

// Methods
// cls_Interface_Graph.def_static("operator new_", (void * (*)(size_t)) &Interface_Graph::operator new, "None", py::arg("theSize"));
// cls_Interface_Graph.def_static("operator delete_", (void (*)(void *)) &Interface_Graph::operator delete, "None", py::arg("theAddress"));
// cls_Interface_Graph.def_static("operator new[]_", (void * (*)(size_t)) &Interface_Graph::operator new[], "None", py::arg("theSize"));
// cls_Interface_Graph.def_static("operator delete[]_", (void (*)(void *)) &Interface_Graph::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_Graph.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_Graph::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_Graph.def_static("operator delete_", (void (*)(void *, void *)) &Interface_Graph::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_Graph.def("Reset", (void (Interface_Graph::*)()) &Interface_Graph::Reset, "Erases data, making graph ready to rebegin from void (also resets Shared lists redefinitions)");
cls_Interface_Graph.def("ResetStatus", (void (Interface_Graph::*)()) &Interface_Graph::ResetStatus, "Erases Status (Values and Flags of Presence), making graph ready to rebegin from void. Does not concerns Shared lists");
cls_Interface_Graph.def("Size", (Standard_Integer (Interface_Graph::*)() const) &Interface_Graph::Size, "Returns size (max nb of entities, i.e. Model's nb of entities)");
cls_Interface_Graph.def("NbStatuses", (Standard_Integer (Interface_Graph::*)() const) &Interface_Graph::NbStatuses, "Returns size of array of statuses");
cls_Interface_Graph.def("EntityNumber", (Standard_Integer (Interface_Graph::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_Graph::EntityNumber, "Returns the Number of the entity in the Map, computed at creation time (Entities loaded from the Model) Returns 0 if <ent> not contained by Model used to create <me> (that is, <ent> is unknown from <me>)", py::arg("ent"));
cls_Interface_Graph.def("IsPresent", (Standard_Boolean (Interface_Graph::*)(const Standard_Integer) const) &Interface_Graph::IsPresent, "Returns True if an Entity is noted as present in the graph (See methods Get... which determine this status) Returns False if <num> is out of range too", py::arg("num"));
cls_Interface_Graph.def("IsPresent", (Standard_Boolean (Interface_Graph::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_Graph::IsPresent, "Same as above but directly on an Entity <ent> : if it is not contained in the Model, returns False. Else calls IsPresent(num) with <num> given by EntityNumber", py::arg("ent"));
cls_Interface_Graph.def("Entity", (const opencascade::handle<Standard_Transient> & (Interface_Graph::*)(const Standard_Integer) const) &Interface_Graph::Entity, "Returns mapped Entity given its no (if it is present)", py::arg("num"));
cls_Interface_Graph.def("Status", (Standard_Integer (Interface_Graph::*)(const Standard_Integer) const) &Interface_Graph::Status, "Returns Status associated to a numero (only to read it)", py::arg("num"));
cls_Interface_Graph.def("SetStatus", (void (Interface_Graph::*)(const Standard_Integer, const Standard_Integer)) &Interface_Graph::SetStatus, "Modifies Status associated to a numero", py::arg("num"), py::arg("stat"));
cls_Interface_Graph.def("RemoveItem", (void (Interface_Graph::*)(const Standard_Integer)) &Interface_Graph::RemoveItem, "Clears Entity and sets Status to 0, for a numero", py::arg("num"));
cls_Interface_Graph.def("ChangeStatus", (void (Interface_Graph::*)(const Standard_Integer, const Standard_Integer)) &Interface_Graph::ChangeStatus, "Changes all status which value is oldstat to new value newstat", py::arg("oldstat"), py::arg("newstat"));
cls_Interface_Graph.def("RemoveStatus", (void (Interface_Graph::*)(const Standard_Integer)) &Interface_Graph::RemoveStatus, "Removes all items of which status has a given value stat", py::arg("stat"));
cls_Interface_Graph.def("BitMap", (const Interface_BitMap & (Interface_Graph::*)() const) &Interface_Graph::BitMap, "Returns the Bit Map in order to read or edit flag values");
cls_Interface_Graph.def("CBitMap", (Interface_BitMap & (Interface_Graph::*)()) &Interface_Graph::CBitMap, "Returns the Bit Map in order to edit it (add new flags)");
cls_Interface_Graph.def("Model", (const opencascade::handle<Interface_InterfaceModel> & (Interface_Graph::*)() const) &Interface_Graph::Model, "Returns the Model with which this Graph was created");
cls_Interface_Graph.def("GetFromModel", (void (Interface_Graph::*)()) &Interface_Graph::GetFromModel, "Loads Graph with all Entities contained in the Model");
cls_Interface_Graph.def("GetFromEntity", [](Interface_Graph &self, const opencascade::handle<Standard_Transient> & a0, const Standard_Boolean a1) -> void { return self.GetFromEntity(a0, a1); });
cls_Interface_Graph.def("GetFromEntity", (void (Interface_Graph::*)(const opencascade::handle<Standard_Transient> &, const Standard_Boolean, const Standard_Integer)) &Interface_Graph::GetFromEntity, "Gets an Entity, plus its shared ones (at every level) if 'shared' is True. New items are set to status 'newstat' Items already present in graph remain unchanged Of course, redefinitions of Shared lists are taken into account if there are some", py::arg("ent"), py::arg("shared"), py::arg("newstat"));
cls_Interface_Graph.def("GetFromEntity", (void (Interface_Graph::*)(const opencascade::handle<Standard_Transient> &, const Standard_Boolean, const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &Interface_Graph::GetFromEntity, "Gets an Entity, plus its shared ones (at every level) if 'shared' is True. New items are set to status 'newstat'. Items already present in graph are processed as follows : - if they already have status 'newstat', they remain unchanged - if they have another status, this one is modified : if cumul is True, to former status + overlapstat (cumul) if cumul is False, to overlapstat (enforce)", py::arg("ent"), py::arg("shared"), py::arg("newstat"), py::arg("overlapstat"), py::arg("cumul"));
cls_Interface_Graph.def("GetFromIter", (void (Interface_Graph::*)(const Interface_EntityIterator &, const Standard_Integer)) &Interface_Graph::GetFromIter, "Gets Entities given by an EntityIterator. Entities which were not yet present in the graph are mapped with status 'newstat' Entities already present remain unchanged", py::arg("iter"), py::arg("newstat"));
cls_Interface_Graph.def("GetFromIter", (void (Interface_Graph::*)(const Interface_EntityIterator &, const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &Interface_Graph::GetFromIter, "Gets Entities given by an EntityIterator and distinguishes those already present in the Graph : - new entities added to the Graph with status 'newstst' - entities already present with status = 'newstat' remain unchanged - entities already present with status different form 'newstat' have their status modified : if cumul is True, to former status + overlapstat (cumul) if cumul is False, to overlapstat (enforce) (Note : works as GetEntity, shared = False, for each entity)", py::arg("iter"), py::arg("newstat"), py::arg("overlapstat"), py::arg("cumul"));
cls_Interface_Graph.def("GetFromGraph", (void (Interface_Graph::*)(const Interface_Graph &)) &Interface_Graph::GetFromGraph, "Gets all present items from another graph", py::arg("agraph"));
cls_Interface_Graph.def("GetFromGraph", (void (Interface_Graph::*)(const Interface_Graph &, const Standard_Integer)) &Interface_Graph::GetFromGraph, "Gets items from another graph which have a specific Status", py::arg("agraph"), py::arg("stat"));
cls_Interface_Graph.def("HasShareErrors", (Standard_Boolean (Interface_Graph::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_Graph::HasShareErrors, "Returns True if <ent> or the list of entities shared by <ent> (not redefined) contains items unknown from this Graph Remark : apart from the status HasShareError, these items are ignored", py::arg("ent"));
cls_Interface_Graph.def("GetShareds", (opencascade::handle<TColStd_HSequenceOfTransient> (Interface_Graph::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_Graph::GetShareds, "Returns the sequence of Entities Shared by an Entity", py::arg("ent"));
cls_Interface_Graph.def("Shareds", (Interface_EntityIterator (Interface_Graph::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_Graph::Shareds, "Returns the list of Entities Shared by an Entity, as recorded by the Graph. That is, by default Basic Shared List, else it can be redefined by methods SetShare, SetNoShare ... see below", py::arg("ent"));
cls_Interface_Graph.def("Sharings", (Interface_EntityIterator (Interface_Graph::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_Graph::Sharings, "Returns the list of Entities which Share an Entity, computed from the Basic or Redefined Shared Lists", py::arg("ent"));
cls_Interface_Graph.def("GetSharings", (opencascade::handle<TColStd_HSequenceOfTransient> (Interface_Graph::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_Graph::GetSharings, "Returns the sequence of Entities Sharings by an Entity", py::arg("ent"));
cls_Interface_Graph.def("TypedSharings", (Interface_EntityIterator (Interface_Graph::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Type> &) const) &Interface_Graph::TypedSharings, "Returns the list of sharings entities, AT ANY LEVEL, which are kind of a given type. A sharing entity kind of this type ends the exploration of its branch", py::arg("ent"), py::arg("type"));
cls_Interface_Graph.def("RootEntities", (Interface_EntityIterator (Interface_Graph::*)() const) &Interface_Graph::RootEntities, "Returns the Entities which are not Shared (their Sharing List is empty) in the Model");
cls_Interface_Graph.def("Name", (opencascade::handle<TCollection_HAsciiString> (Interface_Graph::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_Graph::Name, "Determines the name attached to an entity, by using the general service Name in GeneralModule Returns a null handle if no name could be computed or if the entity is not in the model", py::arg("ent"));
cls_Interface_Graph.def("SharingTable", (const opencascade::handle<TColStd_HArray1OfListOfInteger> & (Interface_Graph::*)() const) &Interface_Graph::SharingTable, "Returns the Table of Sharing lists. Used to Create another Graph from <me>");
cls_Interface_Graph.def("ModeStat", (Standard_Boolean (Interface_Graph::*)() const) &Interface_Graph::ModeStat, "Returns mode resposible for computation of statuses;");

// CLASS: INTERFACE_ENTITYITERATOR
py::class_<Interface_EntityIterator> cls_Interface_EntityIterator(mod, "Interface_EntityIterator", "Defines an Iterator on Entities. Allows considering of various criteria");

// Constructors
cls_Interface_EntityIterator.def(py::init<>());
cls_Interface_EntityIterator.def(py::init<const opencascade::handle<TColStd_HSequenceOfTransient> &>(), py::arg("list"));

// Methods
// cls_Interface_EntityIterator.def_static("operator new_", (void * (*)(size_t)) &Interface_EntityIterator::operator new, "None", py::arg("theSize"));
// cls_Interface_EntityIterator.def_static("operator delete_", (void (*)(void *)) &Interface_EntityIterator::operator delete, "None", py::arg("theAddress"));
// cls_Interface_EntityIterator.def_static("operator new[]_", (void * (*)(size_t)) &Interface_EntityIterator::operator new[], "None", py::arg("theSize"));
// cls_Interface_EntityIterator.def_static("operator delete[]_", (void (*)(void *)) &Interface_EntityIterator::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_EntityIterator.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_EntityIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_EntityIterator.def_static("operator delete_", (void (*)(void *, void *)) &Interface_EntityIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_EntityIterator.def("AddList", (void (Interface_EntityIterator::*)(const opencascade::handle<TColStd_HSequenceOfTransient> &)) &Interface_EntityIterator::AddList, "Gets a list of entities and adds its to the iteration list", py::arg("list"));
cls_Interface_EntityIterator.def("AddItem", (void (Interface_EntityIterator::*)(const opencascade::handle<Standard_Transient> &)) &Interface_EntityIterator::AddItem, "Adds to the iteration list a defined entity", py::arg("anentity"));
cls_Interface_EntityIterator.def("GetOneItem", (void (Interface_EntityIterator::*)(const opencascade::handle<Standard_Transient> &)) &Interface_EntityIterator::GetOneItem, "same as AddItem (kept for compatibility)", py::arg("anentity"));
cls_Interface_EntityIterator.def("SelectType", (void (Interface_EntityIterator::*)(const opencascade::handle<Standard_Type> &, const Standard_Boolean)) &Interface_EntityIterator::SelectType, "Selects entities with are Kind of a given type, keep only them (is keep is True) or reject only them (if keep is False)", py::arg("atype"), py::arg("keep"));
cls_Interface_EntityIterator.def("NbEntities", (Standard_Integer (Interface_EntityIterator::*)() const) &Interface_EntityIterator::NbEntities, "Returns count of entities which will be iterated on Calls Start if not yet done");
cls_Interface_EntityIterator.def("NbTyped", (Standard_Integer (Interface_EntityIterator::*)(const opencascade::handle<Standard_Type> &) const) &Interface_EntityIterator::NbTyped, "Returns count of entities of a given type (kind of)", py::arg("type"));
cls_Interface_EntityIterator.def("Typed", (Interface_EntityIterator (Interface_EntityIterator::*)(const opencascade::handle<Standard_Type> &) const) &Interface_EntityIterator::Typed, "Returns the list of entities of a given type (kind of)", py::arg("type"));
cls_Interface_EntityIterator.def("Start", (void (Interface_EntityIterator::*)() const) &Interface_EntityIterator::Start, "Allows re-iteration (useless for the first iteration)");
cls_Interface_EntityIterator.def("More", (Standard_Boolean (Interface_EntityIterator::*)() const) &Interface_EntityIterator::More, "Says if there are other entities (vertices) to iterate the first time, calls Start");
cls_Interface_EntityIterator.def("Next", (void (Interface_EntityIterator::*)() const) &Interface_EntityIterator::Next, "Sets iteration to the next entity (vertex) to give");
cls_Interface_EntityIterator.def("Value", (const opencascade::handle<Standard_Transient> & (Interface_EntityIterator::*)() const) &Interface_EntityIterator::Value, "Returns the current Entity iterated, to be used by Interface tools");
cls_Interface_EntityIterator.def("Content", (opencascade::handle<TColStd_HSequenceOfTransient> (Interface_EntityIterator::*)() const) &Interface_EntityIterator::Content, "Returns the content of the Iterator, accessed through a Handle to be used by a frontal-engine logic Returns an empty Sequence if the Iterator is empty Calls Start if not yet done");
cls_Interface_EntityIterator.def("Destroy", (void (Interface_EntityIterator::*)()) &Interface_EntityIterator::Destroy, "Clears data of iteration");

// CLASS: INTERFACE_GRAPHCONTENT
py::class_<Interface_GraphContent, Interface_EntityIterator> cls_Interface_GraphContent(mod, "Interface_GraphContent", "Defines general form for classes of graph algorithms on Interfaces, this form is that of EntityIterator Each sub-class fills it according to its own algorithm This also allows to combine any graph result to others, all being given under one unique form");

// Constructors
cls_Interface_GraphContent.def(py::init<>());
cls_Interface_GraphContent.def(py::init<const Interface_Graph &>(), py::arg("agraph"));
cls_Interface_GraphContent.def(py::init<const Interface_Graph &, const Standard_Integer>(), py::arg("agraph"), py::arg("stat"));
cls_Interface_GraphContent.def(py::init<const Interface_Graph &, const opencascade::handle<Standard_Transient> &>(), py::arg("agraph"), py::arg("ent"));

// Methods
// cls_Interface_GraphContent.def_static("operator new_", (void * (*)(size_t)) &Interface_GraphContent::operator new, "None", py::arg("theSize"));
// cls_Interface_GraphContent.def_static("operator delete_", (void (*)(void *)) &Interface_GraphContent::operator delete, "None", py::arg("theAddress"));
// cls_Interface_GraphContent.def_static("operator new[]_", (void * (*)(size_t)) &Interface_GraphContent::operator new[], "None", py::arg("theSize"));
// cls_Interface_GraphContent.def_static("operator delete[]_", (void (*)(void *)) &Interface_GraphContent::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_GraphContent.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_GraphContent::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_GraphContent.def_static("operator delete_", (void (*)(void *, void *)) &Interface_GraphContent::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_GraphContent.def("GetFromGraph", (void (Interface_GraphContent::*)(const Interface_Graph &)) &Interface_GraphContent::GetFromGraph, "Gets all Entities designated by a Graph (once created), adds them to those already recorded", py::arg("agraph"));
cls_Interface_GraphContent.def("GetFromGraph", (void (Interface_GraphContent::*)(const Interface_Graph &, const Standard_Integer)) &Interface_GraphContent::GetFromGraph, "Gets entities from a graph which have a specific Status value (one created), adds them to those already recorded", py::arg("agraph"), py::arg("stat"));
cls_Interface_GraphContent.def("Result", (Interface_EntityIterator (Interface_GraphContent::*)()) &Interface_GraphContent::Result, "Returns Result under the exact form of an EntityIterator : Can be used when EntityIterator itself is required (as a returned value for instance), whitout way for a sub-class");
cls_Interface_GraphContent.def("Begin", (void (Interface_GraphContent::*)()) &Interface_GraphContent::Begin, "Does the Evaluation before starting the iteration itself (in out)");
cls_Interface_GraphContent.def("Evaluate", (void (Interface_GraphContent::*)()) &Interface_GraphContent::Evaluate, "Evaluates list of Entities to be iterated. Called by Start Default is set to doing nothing : intended to be redefined by each sub-class");

// CLASS: INTERFACE_INTLIST
py::class_<Interface_IntList> cls_Interface_IntList(mod, "Interface_IntList", "This class detains the data which describe a Graph. A Graph has two lists, one for shared refs, one for sharing refs (the reverses). Each list comprises, for each Entity of the Model of the Graph, a list of Entities (shared or sharing). In fact, entities are identified by their numbers in the Model or Graph : this gives better performances.");

// Constructors
cls_Interface_IntList.def(py::init<>());
cls_Interface_IntList.def(py::init<const Standard_Integer>(), py::arg("nbe"));
cls_Interface_IntList.def(py::init<const Interface_IntList &, const Standard_Boolean>(), py::arg("other"), py::arg("copied"));

// Methods
// cls_Interface_IntList.def_static("operator new_", (void * (*)(size_t)) &Interface_IntList::operator new, "None", py::arg("theSize"));
// cls_Interface_IntList.def_static("operator delete_", (void (*)(void *)) &Interface_IntList::operator delete, "None", py::arg("theAddress"));
// cls_Interface_IntList.def_static("operator new[]_", (void * (*)(size_t)) &Interface_IntList::operator new[], "None", py::arg("theSize"));
// cls_Interface_IntList.def_static("operator delete[]_", (void (*)(void *)) &Interface_IntList::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_IntList.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_IntList::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_IntList.def_static("operator delete_", (void (*)(void *, void *)) &Interface_IntList::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_IntList.def("Initialize", (void (Interface_IntList::*)(const Standard_Integer)) &Interface_IntList::Initialize, "Initialize IntList by number of entities.", py::arg("nbe"));
cls_Interface_IntList.def("Internals", [](Interface_IntList &self, Standard_Integer & nbrefs, opencascade::handle<TColStd_HArray1OfInteger> & ents, opencascade::handle<TColStd_HArray1OfInteger> & refs){ self.Internals(nbrefs, ents, refs); return nbrefs; }, "Returns internal values, used for copying", py::arg("nbrefs"), py::arg("ents"), py::arg("refs"));
cls_Interface_IntList.def("NbEntities", (Standard_Integer (Interface_IntList::*)() const) &Interface_IntList::NbEntities, "Returns count of entities to be aknowledged");
cls_Interface_IntList.def("SetNbEntities", (void (Interface_IntList::*)(const Standard_Integer)) &Interface_IntList::SetNbEntities, "Changes the count of entities (ignored if decreased)", py::arg("nbe"));
cls_Interface_IntList.def("SetNumber", (void (Interface_IntList::*)(const Standard_Integer)) &Interface_IntList::SetNumber, "Sets an entity number as current (for read and fill)", py::arg("number"));
cls_Interface_IntList.def("Number", (Standard_Integer (Interface_IntList::*)() const) &Interface_IntList::Number, "Returns the current entity number");
cls_Interface_IntList.def("List", [](Interface_IntList &self, const Standard_Integer a0) -> Interface_IntList { return self.List(a0); });
cls_Interface_IntList.def("List", (Interface_IntList (Interface_IntList::*)(const Standard_Integer, const Standard_Boolean) const) &Interface_IntList::List, "Returns an IntList, identical to <me> but set to a specified entity Number By default, not copied (in order to be read) Specified <copied> to produce another list and edit it", py::arg("number"), py::arg("copied"));
cls_Interface_IntList.def("SetRedefined", (void (Interface_IntList::*)(const Standard_Boolean)) &Interface_IntList::SetRedefined, "Sets current entity list to be redefined or not This is used in a Graph for redefinition list : it can be disable (no redefinition, i.e. list is cleared), or enabled (starts as empty). The original list has not to be 'redefined'", py::arg("mode"));
cls_Interface_IntList.def("Reservate", (void (Interface_IntList::*)(const Standard_Integer)) &Interface_IntList::Reservate, "Makes a reservation for <count> references to be later attached to the current entity. If required, it increases the size of array used to store refs. Remark that if count is less than two, it does nothing (because immediate storing)", py::arg("count"));
cls_Interface_IntList.def("Add", (void (Interface_IntList::*)(const Standard_Integer)) &Interface_IntList::Add, "Adds a reference (as an integer value, an entity number) to the current entity number. Zero is ignored", py::arg("ref"));
cls_Interface_IntList.def("Length", (Standard_Integer (Interface_IntList::*)() const) &Interface_IntList::Length, "Returns the count of refs attached to current entity number");
cls_Interface_IntList.def("IsRedefined", [](Interface_IntList &self) -> Standard_Boolean { return self.IsRedefined(); });
cls_Interface_IntList.def("IsRedefined", (Standard_Boolean (Interface_IntList::*)(const Standard_Integer) const) &Interface_IntList::IsRedefined, "Returns True if the list for a number (default is taken as current) is 'redefined' (usefull for empty list)", py::arg("num"));
cls_Interface_IntList.def("Value", (Standard_Integer (Interface_IntList::*)(const Standard_Integer) const) &Interface_IntList::Value, "Returns a reference number in the list for current number, according to its rank", py::arg("num"));
cls_Interface_IntList.def("Remove", (Standard_Boolean (Interface_IntList::*)(const Standard_Integer)) &Interface_IntList::Remove, "Removes an item in the list for current number, given its rank Returns True if done, False else", py::arg("num"));
cls_Interface_IntList.def("Clear", (void (Interface_IntList::*)()) &Interface_IntList::Clear, "Clears all data, hence each entity number has an empty list");
cls_Interface_IntList.def("AdjustSize", [](Interface_IntList &self) -> void { return self.AdjustSize(); });
cls_Interface_IntList.def("AdjustSize", (void (Interface_IntList::*)(const Standard_Integer)) &Interface_IntList::AdjustSize, "Resizes lists to exact sizes. For list of refs, a positive margin can be added.", py::arg("margin"));

// CLASS: INTERFACE_CHECK
py::class_<Interface_Check, opencascade::handle<Interface_Check>, Standard_Transient> cls_Interface_Check(mod, "Interface_Check", "Defines a Check, as a list of Fail or Warning Messages under a literal form, which can be empty. A Check can also bring an Entity, which is the Entity to which the messages apply (this Entity may be any Transient Object).");

// Constructors
cls_Interface_Check.def(py::init<>());
cls_Interface_Check.def(py::init<const opencascade::handle<Standard_Transient> &>(), py::arg("anentity"));

// Methods
cls_Interface_Check.def("SendFail", (void (Interface_Check::*)(const Message_Msg &)) &Interface_Check::SendFail, "New name for AddFail (Msg)", py::arg("amsg"));
cls_Interface_Check.def("AddFail", (void (Interface_Check::*)(const opencascade::handle<TCollection_HAsciiString> &)) &Interface_Check::AddFail, "Records a new Fail message", py::arg("amess"));
cls_Interface_Check.def("AddFail", (void (Interface_Check::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &Interface_Check::AddFail, "Records a new Fail message under two forms : final,original", py::arg("amess"), py::arg("orig"));
cls_Interface_Check.def("AddFail", [](Interface_Check &self, const Standard_CString a0) -> void { return self.AddFail(a0); });
cls_Interface_Check.def("AddFail", (void (Interface_Check::*)(const Standard_CString, const Standard_CString)) &Interface_Check::AddFail, "Records a new Fail message given as 'error text' directly If <orig> is given, a distinct original form is recorded else (D), the original form equates <amess>", py::arg("amess"), py::arg("orig"));
cls_Interface_Check.def("AddFail", (void (Interface_Check::*)(const Message_Msg &)) &Interface_Check::AddFail, "Records a new Fail from the definition of a Msg (Original+Value)", py::arg("amsg"));
cls_Interface_Check.def("HasFailed", (Standard_Boolean (Interface_Check::*)() const) &Interface_Check::HasFailed, "Returns True if Check brings at least one Fail Message");
cls_Interface_Check.def("NbFails", (Standard_Integer (Interface_Check::*)() const) &Interface_Check::NbFails, "Returns count of recorded Fails");
cls_Interface_Check.def("Fail", [](Interface_Check &self, const Standard_Integer a0) -> const opencascade::handle<TCollection_HAsciiString> & { return self.Fail(a0); });
cls_Interface_Check.def("Fail", (const opencascade::handle<TCollection_HAsciiString> & (Interface_Check::*)(const Standard_Integer, const Standard_Boolean) const) &Interface_Check::Fail, "Returns Fail Message as a String Final form by default, Original form if <final> is False", py::arg("num"), py::arg("final"));
cls_Interface_Check.def("CFail", [](Interface_Check &self, const Standard_Integer a0) -> Standard_CString { return self.CFail(a0); });
cls_Interface_Check.def("CFail", (Standard_CString (Interface_Check::*)(const Standard_Integer, const Standard_Boolean) const) &Interface_Check::CFail, "Same as above, but returns a CString (to be printed ...) Final form by default, Original form if <final> is False", py::arg("num"), py::arg("final"));
cls_Interface_Check.def("Fails", [](Interface_Check &self) -> opencascade::handle<TColStd_HSequenceOfHAsciiString> { return self.Fails(); });
cls_Interface_Check.def("Fails", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (Interface_Check::*)(const Standard_Boolean) const) &Interface_Check::Fails, "Returns the list of Fails, for a frontal-engine logic Final forms by default, Original forms if <final> is False Can be empty", py::arg("final"));
cls_Interface_Check.def("SendWarning", (void (Interface_Check::*)(const Message_Msg &)) &Interface_Check::SendWarning, "New name for AddWarning", py::arg("amsg"));
cls_Interface_Check.def("AddWarning", (void (Interface_Check::*)(const opencascade::handle<TCollection_HAsciiString> &)) &Interface_Check::AddWarning, "Records a new Warning message", py::arg("amess"));
cls_Interface_Check.def("AddWarning", (void (Interface_Check::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &Interface_Check::AddWarning, "Records a new Warning message under two forms : final,original", py::arg("amess"), py::arg("orig"));
cls_Interface_Check.def("AddWarning", [](Interface_Check &self, const Standard_CString a0) -> void { return self.AddWarning(a0); });
cls_Interface_Check.def("AddWarning", (void (Interface_Check::*)(const Standard_CString, const Standard_CString)) &Interface_Check::AddWarning, "Records a Warning message given as 'warning message' directly If <orig> is given, a distinct original form is recorded else (D), the original form equates <amess>", py::arg("amess"), py::arg("orig"));
cls_Interface_Check.def("AddWarning", (void (Interface_Check::*)(const Message_Msg &)) &Interface_Check::AddWarning, "Records a new Warning from the definition of a Msg (Original+Value)", py::arg("amsg"));
cls_Interface_Check.def("HasWarnings", (Standard_Boolean (Interface_Check::*)() const) &Interface_Check::HasWarnings, "Returns True if Check brings at least one Warning Message");
cls_Interface_Check.def("NbWarnings", (Standard_Integer (Interface_Check::*)() const) &Interface_Check::NbWarnings, "Returns count of recorded Warning messages");
cls_Interface_Check.def("Warning", [](Interface_Check &self, const Standard_Integer a0) -> const opencascade::handle<TCollection_HAsciiString> & { return self.Warning(a0); });
cls_Interface_Check.def("Warning", (const opencascade::handle<TCollection_HAsciiString> & (Interface_Check::*)(const Standard_Integer, const Standard_Boolean) const) &Interface_Check::Warning, "Returns Warning message as a String Final form by default, Original form if <final> is False", py::arg("num"), py::arg("final"));
cls_Interface_Check.def("CWarning", [](Interface_Check &self, const Standard_Integer a0) -> Standard_CString { return self.CWarning(a0); });
cls_Interface_Check.def("CWarning", (Standard_CString (Interface_Check::*)(const Standard_Integer, const Standard_Boolean) const) &Interface_Check::CWarning, "Same as above, but returns a CString (to be printed ...) Final form by default, Original form if <final> is False", py::arg("num"), py::arg("final"));
cls_Interface_Check.def("Warnings", [](Interface_Check &self) -> opencascade::handle<TColStd_HSequenceOfHAsciiString> { return self.Warnings(); });
cls_Interface_Check.def("Warnings", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (Interface_Check::*)(const Standard_Boolean) const) &Interface_Check::Warnings, "Returns the list of Warnings, for a frontal-engine logic Final forms by default, Original forms if <final> is False Can be empty", py::arg("final"));
cls_Interface_Check.def("SendMsg", (void (Interface_Check::*)(const Message_Msg &)) &Interface_Check::SendMsg, "Records an information message This does not change the status of the Check", py::arg("amsg"));
cls_Interface_Check.def("NbInfoMsgs", (Standard_Integer (Interface_Check::*)() const) &Interface_Check::NbInfoMsgs, "Returns the count of recorded information messages");
cls_Interface_Check.def("InfoMsg", [](Interface_Check &self, const Standard_Integer a0) -> const opencascade::handle<TCollection_HAsciiString> & { return self.InfoMsg(a0); });
cls_Interface_Check.def("InfoMsg", (const opencascade::handle<TCollection_HAsciiString> & (Interface_Check::*)(const Standard_Integer, const Standard_Boolean) const) &Interface_Check::InfoMsg, "Returns information message as a String", py::arg("num"), py::arg("final"));
cls_Interface_Check.def("CInfoMsg", [](Interface_Check &self, const Standard_Integer a0) -> Standard_CString { return self.CInfoMsg(a0); });
cls_Interface_Check.def("CInfoMsg", (Standard_CString (Interface_Check::*)(const Standard_Integer, const Standard_Boolean) const) &Interface_Check::CInfoMsg, "Same as above, but returns a CString (to be printed ...) Final form by default, Original form if <final> is False", py::arg("num"), py::arg("final"));
cls_Interface_Check.def("InfoMsgs", [](Interface_Check &self) -> opencascade::handle<TColStd_HSequenceOfHAsciiString> { return self.InfoMsgs(); });
cls_Interface_Check.def("InfoMsgs", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (Interface_Check::*)(const Standard_Boolean) const) &Interface_Check::InfoMsgs, "Returns the list of Info Msg, for a frontal-engine logic Final forms by default, Original forms if <final> is False Can be empty", py::arg("final"));
cls_Interface_Check.def("Status", (Interface_CheckStatus (Interface_Check::*)() const) &Interface_Check::Status, "Returns the Check Status : OK, Warning or Fail");
cls_Interface_Check.def("Complies", (Standard_Boolean (Interface_Check::*)(const Interface_CheckStatus) const) &Interface_Check::Complies, "Tells if Check Status complies with a given one (i.e. also status for query)", py::arg("status"));
cls_Interface_Check.def("Complies", (Standard_Boolean (Interface_Check::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Interface_CheckStatus) const) &Interface_Check::Complies, "Tells if a message is brought by a Check, as follows : <incl> = 0 : <mess> exactly matches one of the messages <incl> < 0 : <mess> is contained by one of the messages <incl> > 0 : <mess> contains one of the messages For <status> : for CheckWarning and CheckFail, considers only resp. Warning or Check messages. for CheckAny, considers all other values are ignored (answer will be false)", py::arg("mess"), py::arg("incl"), py::arg("status"));
cls_Interface_Check.def("HasEntity", (Standard_Boolean (Interface_Check::*)() const) &Interface_Check::HasEntity, "Returns True if a Check is devoted to an entity; else, it is global (for InterfaceModel's storing of global error messages)");
cls_Interface_Check.def("Entity", (const opencascade::handle<Standard_Transient> & (Interface_Check::*)() const) &Interface_Check::Entity, "Returns the entity on which the Check has been defined");
cls_Interface_Check.def("Clear", (void (Interface_Check::*)()) &Interface_Check::Clear, "Clears a check, in order to receive informations from transfer (Messages and Entity)");
cls_Interface_Check.def("ClearFails", (void (Interface_Check::*)()) &Interface_Check::ClearFails, "Clears the Fail Messages (for instance to keep only Warnings)");
cls_Interface_Check.def("ClearWarnings", (void (Interface_Check::*)()) &Interface_Check::ClearWarnings, "Clears the Warning Messages (for instance to keep only Fails)");
cls_Interface_Check.def("ClearInfoMsgs", (void (Interface_Check::*)()) &Interface_Check::ClearInfoMsgs, "Clears the Info Messages");
cls_Interface_Check.def("Remove", (Standard_Boolean (Interface_Check::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Interface_CheckStatus)) &Interface_Check::Remove, "Removes the messages which comply with <mess>, as follows : <incl> = 0 : <mess> exactly matches one of the messages <incl> < 0 : <mess> is contained by one of the messages <incl> > 0 : <mess> contains one of the messages For <status> : for CheckWarning and CheckFail, considers only resp. Warning or Check messages. for CheckAny, considers all other values are ignored (nothing is done) Returns True if at least one message has been removed, False else", py::arg("mess"), py::arg("incl"), py::arg("status"));
cls_Interface_Check.def("Mend", [](Interface_Check &self, const Standard_CString a0) -> Standard_Boolean { return self.Mend(a0); });
cls_Interface_Check.def("Mend", (Standard_Boolean (Interface_Check::*)(const Standard_CString, const Standard_Integer)) &Interface_Check::Mend, "Mends messages, according <pref> and <num> According to <num>, works on the whole list of Fails if = 0(D) or only one Fail message, given its rank If <pref> is empty, converts Fail(s) to Warning(s) Else, does the conversion but prefixes the new Warning(s) but <pref> followed by a semi-column Some reserved values of <pref> are : 'FM' : standard prefix 'Mended' (can be translated) 'CF' : clears Fail(s) 'CW' : clears Warning(s) : here, <num> refers to Warning list 'CA' : clears all messages : here, <num> is ignored", py::arg("pref"), py::arg("num"));
cls_Interface_Check.def("SetEntity", (void (Interface_Check::*)(const opencascade::handle<Standard_Transient> &)) &Interface_Check::SetEntity, "Receives an entity result of a Transfer", py::arg("anentity"));
cls_Interface_Check.def("GetEntity", (void (Interface_Check::*)(const opencascade::handle<Standard_Transient> &)) &Interface_Check::GetEntity, "same as SetEntity (old form kept for compatibility) Warning : Does nothing if Entity field is not yet clear", py::arg("anentity"));
cls_Interface_Check.def("GetMessages", (void (Interface_Check::*)(const opencascade::handle<Interface_Check> &)) &Interface_Check::GetMessages, "Copies messages stored in another Check, cumulating Does not regard other's Entity. Used to cumulate messages", py::arg("other"));
cls_Interface_Check.def("GetAsWarning", (void (Interface_Check::*)(const opencascade::handle<Interface_Check> &, const Standard_Boolean)) &Interface_Check::GetAsWarning, "Copies messages converted into Warning messages If failsonly is true, only Fails are taken, and converted else, Warnings are taken too. Does not regard Entity Used to keep Fail messages as Warning, after a recovery", py::arg("other"), py::arg("failsonly"));
cls_Interface_Check.def("Print", [](Interface_Check &self, const opencascade::handle<Message_Messenger> & a0, const Standard_Integer a1) -> void { return self.Print(a0, a1); });
cls_Interface_Check.def("Print", (void (Interface_Check::*)(const opencascade::handle<Message_Messenger> &, const Standard_Integer, const Standard_Integer) const) &Interface_Check::Print, "Prints the messages of the check to an Messenger <level> = 1 : only fails <level> = 2 : fails and warnings <level> = 3 : all (fails, warnings, info msg) <final> : if positive (D) prints final values of messages if negative, prints originals if null, prints both forms", py::arg("S"), py::arg("level"), py::arg("final"));
cls_Interface_Check.def("Trace", [](Interface_Check &self) -> void { return self.Trace(); });
cls_Interface_Check.def("Trace", [](Interface_Check &self, const Standard_Integer a0) -> void { return self.Trace(a0); });
cls_Interface_Check.def("Trace", (void (Interface_Check::*)(const Standard_Integer, const Standard_Integer) const) &Interface_Check::Trace, "Prints the messages of the check to the default trace file By default, according to the default standard level Else, according level (see method Print)", py::arg("level"), py::arg("final"));
cls_Interface_Check.def_static("get_type_name_", (const char * (*)()) &Interface_Check::get_type_name, "None");
cls_Interface_Check.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_Check::get_type_descriptor, "None");
cls_Interface_Check.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_Check::*)() const) &Interface_Check::DynamicType, "None");

// TYPEDEF: INTERFACE_SEQUENCEOFCHECK
bind_NCollection_Sequence<opencascade::handle<Interface_Check> >(mod, "Interface_SequenceOfCheck", py::module_local(false));

// CLASS: INTERFACE_HSEQUENCEOFCHECK
py::class_<Interface_HSequenceOfCheck, opencascade::handle<Interface_HSequenceOfCheck>, Standard_Transient> cls_Interface_HSequenceOfCheck(mod, "Interface_HSequenceOfCheck", "None", py::multiple_inheritance());

// Constructors
cls_Interface_HSequenceOfCheck.def(py::init<>());
cls_Interface_HSequenceOfCheck.def(py::init<const Interface_SequenceOfCheck &>(), py::arg("theOther"));

// Methods
// cls_Interface_HSequenceOfCheck.def_static("operator new_", (void * (*)(size_t)) &Interface_HSequenceOfCheck::operator new, "None", py::arg("theSize"));
// cls_Interface_HSequenceOfCheck.def_static("operator delete_", (void (*)(void *)) &Interface_HSequenceOfCheck::operator delete, "None", py::arg("theAddress"));
// cls_Interface_HSequenceOfCheck.def_static("operator new[]_", (void * (*)(size_t)) &Interface_HSequenceOfCheck::operator new[], "None", py::arg("theSize"));
// cls_Interface_HSequenceOfCheck.def_static("operator delete[]_", (void (*)(void *)) &Interface_HSequenceOfCheck::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_HSequenceOfCheck.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_HSequenceOfCheck::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_HSequenceOfCheck.def_static("operator delete_", (void (*)(void *, void *)) &Interface_HSequenceOfCheck::operator delete, "None", py::arg(""), py::arg(""));
// cls_Interface_HSequenceOfCheck.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Interface_HSequenceOfCheck::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Interface_HSequenceOfCheck.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Interface_HSequenceOfCheck::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Interface_HSequenceOfCheck.def("Sequence", (const Interface_SequenceOfCheck & (Interface_HSequenceOfCheck::*)() const) &Interface_HSequenceOfCheck::Sequence, "None");
cls_Interface_HSequenceOfCheck.def("Append", (void (Interface_HSequenceOfCheck::*)(const Interface_SequenceOfCheck::value_type &)) &Interface_HSequenceOfCheck::Append, "None", py::arg("theItem"));
cls_Interface_HSequenceOfCheck.def("Append", (void (Interface_HSequenceOfCheck::*)(Interface_SequenceOfCheck &)) &Interface_HSequenceOfCheck::Append, "None", py::arg("theSequence"));
cls_Interface_HSequenceOfCheck.def("ChangeSequence", (Interface_SequenceOfCheck & (Interface_HSequenceOfCheck::*)()) &Interface_HSequenceOfCheck::ChangeSequence, "None");
cls_Interface_HSequenceOfCheck.def_static("get_type_name_", (const char * (*)()) &Interface_HSequenceOfCheck::get_type_name, "None");
cls_Interface_HSequenceOfCheck.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_HSequenceOfCheck::get_type_descriptor, "None");
cls_Interface_HSequenceOfCheck.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_HSequenceOfCheck::*)() const) &Interface_HSequenceOfCheck::DynamicType, "None");

// CLASS: INTERFACE_CHECKITERATOR
py::class_<Interface_CheckIterator> cls_Interface_CheckIterator(mod, "Interface_CheckIterator", "Result of a Check operation (especially from InterfaceModel)");

// Constructors
cls_Interface_CheckIterator.def(py::init<>());
cls_Interface_CheckIterator.def(py::init<const Standard_CString>(), py::arg("name"));

// Methods
// cls_Interface_CheckIterator.def_static("operator new_", (void * (*)(size_t)) &Interface_CheckIterator::operator new, "None", py::arg("theSize"));
// cls_Interface_CheckIterator.def_static("operator delete_", (void (*)(void *)) &Interface_CheckIterator::operator delete, "None", py::arg("theAddress"));
// cls_Interface_CheckIterator.def_static("operator new[]_", (void * (*)(size_t)) &Interface_CheckIterator::operator new[], "None", py::arg("theSize"));
// cls_Interface_CheckIterator.def_static("operator delete[]_", (void (*)(void *)) &Interface_CheckIterator::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_CheckIterator.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_CheckIterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_CheckIterator.def_static("operator delete_", (void (*)(void *, void *)) &Interface_CheckIterator::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_CheckIterator.def("SetName", (void (Interface_CheckIterator::*)(const Standard_CString)) &Interface_CheckIterator::SetName, "Sets / Changes the name", py::arg("name"));
cls_Interface_CheckIterator.def("Name", (Standard_CString (Interface_CheckIterator::*)() const) &Interface_CheckIterator::Name, "Returns the recorded name (can be empty)");
cls_Interface_CheckIterator.def("SetModel", (void (Interface_CheckIterator::*)(const opencascade::handle<Interface_InterfaceModel> &)) &Interface_CheckIterator::SetModel, "Defines a Model, used to locate entities (not required, if it is absent, entities are simply less documented)", py::arg("model"));
cls_Interface_CheckIterator.def("Model", (opencascade::handle<Interface_InterfaceModel> (Interface_CheckIterator::*)() const) &Interface_CheckIterator::Model, "Returns the stored model (can be a null handle)");
cls_Interface_CheckIterator.def("Clear", (void (Interface_CheckIterator::*)()) &Interface_CheckIterator::Clear, "Clears the list of checks");
cls_Interface_CheckIterator.def("Merge", (void (Interface_CheckIterator::*)(Interface_CheckIterator &)) &Interface_CheckIterator::Merge, "Merges another CheckIterator into <me>, i.e. adds each of its Checks. Content of <other> remains unchanged. Takes also the Model but not the Name", py::arg("other"));
cls_Interface_CheckIterator.def("Add", [](Interface_CheckIterator &self, const opencascade::handle<Interface_Check> & a0) -> void { return self.Add(a0); });
cls_Interface_CheckIterator.def("Add", (void (Interface_CheckIterator::*)(const opencascade::handle<Interface_Check> &, const Standard_Integer)) &Interface_CheckIterator::Add, "Adds a Check to the list to be iterated This Check is Accompanied by Entity Number in the Model (0 for Global Check or Entity unknown in the Model), if 0 and Model is recorded in <me>, it is computed", py::arg("ach"), py::arg("num"));
cls_Interface_CheckIterator.def("Check", (const opencascade::handle<Interface_Check> & (Interface_CheckIterator::*)(const Standard_Integer) const) &Interface_CheckIterator::Check, "Returns the Check which was attached to an Entity given its Number in the Model. <num>=0 is for the Global Check. If no Check was recorded for this Number, returns an empty Check. Remark : Works apart from the iteration methods (no interference)", py::arg("num"));
cls_Interface_CheckIterator.def("Check", (const opencascade::handle<Interface_Check> & (Interface_CheckIterator::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_CheckIterator::Check, "Returns the Check attached to an Entity If no Check was recorded for this Entity, returns an empty Check. Remark : Works apart from the iteration methods (no interference)", py::arg("ent"));
cls_Interface_CheckIterator.def("CCheck", (opencascade::handle<Interface_Check> & (Interface_CheckIterator::*)(const Standard_Integer)) &Interface_CheckIterator::CCheck, "Returns the Check bound to an Entity Number (0 : Global) in order to be consulted or completed on the spot I.e. returns the Check if is already exists, or adds it then returns the new empty Check", py::arg("num"));
cls_Interface_CheckIterator.def("CCheck", (opencascade::handle<Interface_Check> & (Interface_CheckIterator::*)(const opencascade::handle<Standard_Transient> &)) &Interface_CheckIterator::CCheck, "Returns the Check bound to an Entity, in order to be consulted or completed on the spot I.e. returns the Check if is already exists, or adds it then returns the new empty Check", py::arg("ent"));
cls_Interface_CheckIterator.def("IsEmpty", (Standard_Boolean (Interface_CheckIterator::*)(const Standard_Boolean) const) &Interface_CheckIterator::IsEmpty, "Returns True if : no Fail has been recorded if <failsonly> is True, no Check at all if <failsonly> is False", py::arg("failsonly"));
cls_Interface_CheckIterator.def("Status", (Interface_CheckStatus (Interface_CheckIterator::*)() const) &Interface_CheckIterator::Status, "Returns worst status among : OK, Warning, Fail");
cls_Interface_CheckIterator.def("Complies", (Standard_Boolean (Interface_CheckIterator::*)(const Interface_CheckStatus) const) &Interface_CheckIterator::Complies, "Tells if this check list complies with a given status : OK (i.e. empty), Warning (at least one Warning, but no Fail), Fail (at least one), Message (not OK), NoFail, Any", py::arg("status"));
cls_Interface_CheckIterator.def("Extract", (Interface_CheckIterator (Interface_CheckIterator::*)(const Interface_CheckStatus) const) &Interface_CheckIterator::Extract, "Returns a CheckIterator which contains the checks which comply with a given status Each check is added completely (no split Warning/Fail)", py::arg("status"));
cls_Interface_CheckIterator.def("Extract", (Interface_CheckIterator (Interface_CheckIterator::*)(const Standard_CString, const Standard_Integer, const Interface_CheckStatus) const) &Interface_CheckIterator::Extract, "Returns a CheckIterator which contains the check which comply with a message, plus some conditions as follows : <incl> = 0 : <mess> exactly matches one of the messages <incl> < 0 : <mess> is contained by one of the messages <incl> > 0 : <mess> contains one of the messages For <status> : for CheckWarning and CheckFail, considers only resp. Warning or Check messages. for CheckAny, considers all other values are ignored (answer will be false) Each Check which complies is entirely taken", py::arg("mess"), py::arg("incl"), py::arg("status"));
cls_Interface_CheckIterator.def("Remove", (Standard_Boolean (Interface_CheckIterator::*)(const Standard_CString, const Standard_Integer, const Interface_CheckStatus)) &Interface_CheckIterator::Remove, "Removes the messages of all Checks, under these conditions : <incl> = 0 : <mess> exactly matches one of the messages <incl> < 0 : <mess> is contained by one of the messages <incl> > 0 : <mess> contains one of the messages For <status> : for CheckWarning and CheckFail, considers only resp. Warning or Check messages. for CheckAny, considers all other values are ignored (nothing is done) Returns True if at least one message has been removed, False else", py::arg("mess"), py::arg("incl"), py::arg("status"));
cls_Interface_CheckIterator.def("Checkeds", (opencascade::handle<TColStd_HSequenceOfTransient> (Interface_CheckIterator::*)(const Standard_Boolean, const Standard_Boolean) const) &Interface_CheckIterator::Checkeds, "Returns the list of entities concerned by a Check Only fails if <failsonly> is True, else all non-empty checks If <global> is true, adds the model for a global check Else, global check is ignored", py::arg("failsonly"), py::arg("global"));
cls_Interface_CheckIterator.def("Start", (void (Interface_CheckIterator::*)() const) &Interface_CheckIterator::Start, "Starts Iteration. Thus, it is possible to restart it Remark : an iteration may be done with a const Iterator While its content is modified (through a pointer), this allows to give it as a const argument to a function");
cls_Interface_CheckIterator.def("More", (Standard_Boolean (Interface_CheckIterator::*)() const) &Interface_CheckIterator::More, "Returns True if there are more Checks to get");
cls_Interface_CheckIterator.def("Next", (void (Interface_CheckIterator::*)() const) &Interface_CheckIterator::Next, "Sets Iteration to next Item");
cls_Interface_CheckIterator.def("Value", (const opencascade::handle<Interface_Check> & (Interface_CheckIterator::*)() const) &Interface_CheckIterator::Value, "Returns Check currently Iterated It brings all other informations (status, messages, ...) The Number of the Entity in the Model is given by Number below");
cls_Interface_CheckIterator.def("Number", (Standard_Integer (Interface_CheckIterator::*)() const) &Interface_CheckIterator::Number, "Returns Number of Entity for the Check currently iterated or 0 for GlobalCheck");
cls_Interface_CheckIterator.def("Print", [](Interface_CheckIterator &self, const opencascade::handle<Message_Messenger> & a0, const Standard_Boolean a1) -> void { return self.Print(a0, a1); });
cls_Interface_CheckIterator.def("Print", (void (Interface_CheckIterator::*)(const opencascade::handle<Message_Messenger> &, const Standard_Boolean, const Standard_Integer) const) &Interface_CheckIterator::Print, "Prints the list of Checks with their attached Numbers If <failsonly> is True, prints only Fail messages If <failsonly> is False, prints all messages If <final> = 0 (D), prints also original messages if different If <final> < 0, prints only original messages If <final> > 0, prints only final messages It uses the recorded Model if it is defined Remark : Works apart from the iteration methods (no interference)", py::arg("S"), py::arg("failsonly"), py::arg("final"));
cls_Interface_CheckIterator.def("Print", [](Interface_CheckIterator &self, const opencascade::handle<Message_Messenger> & a0, const opencascade::handle<Interface_InterfaceModel> & a1, const Standard_Boolean a2) -> void { return self.Print(a0, a1, a2); });
cls_Interface_CheckIterator.def("Print", (void (Interface_CheckIterator::*)(const opencascade::handle<Message_Messenger> &, const opencascade::handle<Interface_InterfaceModel> &, const Standard_Boolean, const Standard_Integer) const) &Interface_CheckIterator::Print, "Works as Print without a model, but for entities which have no attached number (Number not positive), tries to compute this Number from <model> and displays 'original' or 'computed'", py::arg("S"), py::arg("model"), py::arg("failsonly"), py::arg("final"));
cls_Interface_CheckIterator.def("Destroy", (void (Interface_CheckIterator::*)()) &Interface_CheckIterator::Destroy, "Clears data of iteration");

// CLASS: INTERFACE_SIGNTYPE
py::class_<Interface_SignType, opencascade::handle<Interface_SignType>, MoniTool_SignText> cls_Interface_SignType(mod, "Interface_SignType", "Provides the basic service to get a type name, according to a norm It can be used for other classes (general signatures ...)");

// Methods
cls_Interface_SignType.def("Text", (TCollection_AsciiString (Interface_SignType::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &) const) &Interface_SignType::Text, "Returns an identification of the Signature (a word), given at initialization time Specialised to consider context as an InterfaceModel", py::arg("ent"), py::arg("context"));
cls_Interface_SignType.def("Value", (Standard_CString (Interface_SignType::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &Interface_SignType::Value, "Returns the Signature for a Transient object. It is specific of each sub-class of Signature. For a Null Handle, it should provide '' It can work with the model which contains the entity", py::arg("ent"), py::arg("model"));
cls_Interface_SignType.def_static("ClassName_", (Standard_CString (*)(const Standard_CString)) &Interface_SignType::ClassName, "From a CDL Type Name, returns the Class part (package dropped) WARNING : buffered, to be immediately copied or printed", py::arg("typnam"));
cls_Interface_SignType.def_static("get_type_name_", (const char * (*)()) &Interface_SignType::get_type_name, "None");
cls_Interface_SignType.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_SignType::get_type_descriptor, "None");
cls_Interface_SignType.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_SignType::*)() const) &Interface_SignType::DynamicType, "None");

// CLASS: INTERFACE_ENTITYLIST
py::class_<Interface_EntityList> cls_Interface_EntityList(mod, "Interface_EntityList", "This class defines a list of Entities (Transient Objects), it can be used as a field of other Transient classes, with these features : - oriented to define a little list, that is, slower than an Array or a Map of Entities for a big count (about 100 and over), but faster than a Sequence - allows to work as a Sequence, limited to Clear, Append, Remove, Access to an Item identified by its rank in the list - space saving, compared to a Sequence, especially for little amounts; better than an Array for a very little amount (less than 10) but less good for a greater amount");

// Constructors
cls_Interface_EntityList.def(py::init<>());

// Methods
// cls_Interface_EntityList.def_static("operator new_", (void * (*)(size_t)) &Interface_EntityList::operator new, "None", py::arg("theSize"));
// cls_Interface_EntityList.def_static("operator delete_", (void (*)(void *)) &Interface_EntityList::operator delete, "None", py::arg("theAddress"));
// cls_Interface_EntityList.def_static("operator new[]_", (void * (*)(size_t)) &Interface_EntityList::operator new[], "None", py::arg("theSize"));
// cls_Interface_EntityList.def_static("operator delete[]_", (void (*)(void *)) &Interface_EntityList::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_EntityList.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_EntityList::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_EntityList.def_static("operator delete_", (void (*)(void *, void *)) &Interface_EntityList::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_EntityList.def("Clear", (void (Interface_EntityList::*)()) &Interface_EntityList::Clear, "Clears the List");
cls_Interface_EntityList.def("Append", (void (Interface_EntityList::*)(const opencascade::handle<Standard_Transient> &)) &Interface_EntityList::Append, "Appends an Entity, that is to the END of the list (keeps order, but works slowerly than Add, see below)", py::arg("ent"));
cls_Interface_EntityList.def("Add", (void (Interface_EntityList::*)(const opencascade::handle<Standard_Transient> &)) &Interface_EntityList::Add, "Adds an Entity to the list, that is, with NO REGARD about the order (faster than Append if count becomes greater than 10)", py::arg("ent"));
cls_Interface_EntityList.def("Remove", (void (Interface_EntityList::*)(const opencascade::handle<Standard_Transient> &)) &Interface_EntityList::Remove, "Removes an Entity from the list, if it is there", py::arg("ent"));
cls_Interface_EntityList.def("Remove", (void (Interface_EntityList::*)(const Standard_Integer)) &Interface_EntityList::Remove, "Removes an Entity from the list, given its rank", py::arg("num"));
cls_Interface_EntityList.def("IsEmpty", (Standard_Boolean (Interface_EntityList::*)() const) &Interface_EntityList::IsEmpty, "Returns True if the list is empty");
cls_Interface_EntityList.def("NbEntities", (Standard_Integer (Interface_EntityList::*)() const) &Interface_EntityList::NbEntities, "Returns count of recorded Entities");
cls_Interface_EntityList.def("Value", (const opencascade::handle<Standard_Transient> & (Interface_EntityList::*)(const Standard_Integer) const) &Interface_EntityList::Value, "Returns an Item given its number. Beware about the way the list was filled (see above, Add and Append)", py::arg("num"));
cls_Interface_EntityList.def("SetValue", (void (Interface_EntityList::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &)) &Interface_EntityList::SetValue, "Returns an Item given its number. Beware about the way the list was filled (see above, Add and Append)", py::arg("num"), py::arg("ent"));
cls_Interface_EntityList.def("FillIterator", (void (Interface_EntityList::*)(Interface_EntityIterator &) const) &Interface_EntityList::FillIterator, "fills an Iterator with the content of the list (normal way to consult a list which has been filled with Add)", py::arg("iter"));
cls_Interface_EntityList.def("NbTypedEntities", (Standard_Integer (Interface_EntityList::*)(const opencascade::handle<Standard_Type> &) const) &Interface_EntityList::NbTypedEntities, "Returns count of Entities of a given Type (0 : none)", py::arg("atype"));
cls_Interface_EntityList.def("TypedEntity", [](Interface_EntityList &self, const opencascade::handle<Standard_Type> & a0) -> opencascade::handle<Standard_Transient> { return self.TypedEntity(a0); });
cls_Interface_EntityList.def("TypedEntity", (opencascade::handle<Standard_Transient> (Interface_EntityList::*)(const opencascade::handle<Standard_Type> &, const Standard_Integer) const) &Interface_EntityList::TypedEntity, "Returns the Entity which is of a given type. If num = 0 (D), there must be ONE AND ONLY ONE If num > 0, returns the num-th entity of this type", py::arg("atype"), py::arg("num"));

// CLASS: INTERFACE_GENERALMODULE
py::class_<Interface_GeneralModule, opencascade::handle<Interface_GeneralModule>, Standard_Transient> cls_Interface_GeneralModule(mod, "Interface_GeneralModule", "This class defines general services, which must be provided for each type of Entity (i.e. of Transient Object processed by an Interface) : Shared List, Check, Copy, Delete, Category");

// Methods
cls_Interface_GeneralModule.def("FillShared", (void (Interface_GeneralModule::*)(const opencascade::handle<Interface_InterfaceModel> &, const Standard_Integer, const opencascade::handle<Standard_Transient> &, Interface_EntityIterator &) const) &Interface_GeneralModule::FillShared, "Specific filling of the list of Entities shared by an Entity <ent>, according a Case Number <CN> (formerly computed by CaseNum), considered in the context of a Model <model> Default calls FillSharedCase (i.e., ignores the model) Can be redefined to use the model for working", py::arg("model"), py::arg("CN"), py::arg("ent"), py::arg("iter"));
cls_Interface_GeneralModule.def("FillSharedCase", (void (Interface_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, Interface_EntityIterator &) const) &Interface_GeneralModule::FillSharedCase, "Specific filling of the list of Entities shared by an Entity <ent>, according a Case Number <CN> (formerly computed by CaseNum). Can use the internal utility method Share, below", py::arg("CN"), py::arg("ent"), py::arg("iter"));
cls_Interface_GeneralModule.def("Share", (void (Interface_GeneralModule::*)(Interface_EntityIterator &, const opencascade::handle<Standard_Transient> &) const) &Interface_GeneralModule::Share, "Adds an Entity to a Shared List (uses GetOneItem on <iter>)", py::arg("iter"), py::arg("shared"));
cls_Interface_GeneralModule.def("ListImplied", (void (Interface_GeneralModule::*)(const opencascade::handle<Interface_InterfaceModel> &, const Standard_Integer, const opencascade::handle<Standard_Transient> &, Interface_EntityIterator &) const) &Interface_GeneralModule::ListImplied, "List the Implied References of <ent> considered in the context of a Model <model> : i.e. the Entities which are Referenced while not considered as Shared (not copied if <ent> is, references not renewed by CopyCase but by ImpliedCase, only if referenced Entities have been Copied too) FillShared + ListImplied give the complete list of References Default calls ListImpliedCase (i.e. ignores the model) Can be redefined to use the model for working", py::arg("model"), py::arg("CN"), py::arg("ent"), py::arg("iter"));
cls_Interface_GeneralModule.def("ListImpliedCase", (void (Interface_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, Interface_EntityIterator &) const) &Interface_GeneralModule::ListImpliedCase, "List the Implied References of <ent> (see above) are Referenced while not considered as Shared (not copied if <ent> is, references not renewed by CopyCase but by ImpliedCase, only if referenced Entities have been Copied too) FillSharedCase + ListImpliedCase give the complete list of Referenced Entities The provided default method does nothing (Implied References are specific of a little amount of Entity Classes).", py::arg("CN"), py::arg("ent"), py::arg("iter"));
cls_Interface_GeneralModule.def("CheckCase", (void (Interface_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &Interface_GeneralModule::CheckCase, "Specific Checking of an Entity <ent> Can check context queried through a ShareTool, as required", py::arg("CN"), py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_Interface_GeneralModule.def("CanCopy", (Standard_Boolean (Interface_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &) const) &Interface_GeneralModule::CanCopy, "Specific answer to the question 'is Copy properly implemented' Remark that it should be in phase with the implementation of NewVoid+CopyCase/NewCopyCase Default returns always False, can be redefined", py::arg("CN"), py::arg("ent"));
cls_Interface_GeneralModule.def("Dispatch", (Standard_Boolean (Interface_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &, Interface_CopyTool &) const) &Interface_GeneralModule::Dispatch, "Dispatches an entity Returns True if it works by copy, False if it just duplicates the starting Handle", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_Interface_GeneralModule.def("NewVoid", (Standard_Boolean (Interface_GeneralModule::*)(const Standard_Integer, opencascade::handle<Standard_Transient> &) const) &Interface_GeneralModule::NewVoid, "Creates a new void entity <entto> according to a Case Number This entity remains to be filled, by reading from a file or by copying from another entity of same type (see CopyCase)", py::arg("CN"), py::arg("entto"));
cls_Interface_GeneralModule.def("CopyCase", (void (Interface_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &, Interface_CopyTool &) const) &Interface_GeneralModule::CopyCase, "Specific Copy ('Deep') from <entfrom> to <entto> (same type) by using a CopyTool which provides its working Map. Use method Transferred from CopyTool to work", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_Interface_GeneralModule.def("NewCopiedCase", (Standard_Boolean (Interface_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &, Interface_CopyTool &) const) &Interface_GeneralModule::NewCopiedCase, "Specific operator (create+copy) defaulted to do nothing. It can be redefined : When it is not possible to work in two steps (NewVoid then CopyCase). This can occur when there is no default constructor : hence the result <entto> must be created with an effective definition. Remark : if NewCopiedCase is defined, CopyCase has nothing to do Returns True if it has produced something, false else", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_Interface_GeneralModule.def("RenewImpliedCase", (void (Interface_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &, const Interface_CopyTool &) const) &Interface_GeneralModule::RenewImpliedCase, "Specific Copying of Implied References A Default is provided which does nothing (must current case !) Already copied references (by CopyFrom) must remain unchanged Use method Search from CopyTool to work", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_Interface_GeneralModule.def("WhenDeleteCase", (void (Interface_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Standard_Boolean) const) &Interface_GeneralModule::WhenDeleteCase, "Prepares an entity to be deleted. What does it mean : Basically, any class of entity may define its own destructor By default, it does nothing but calling destructors on fields With the Memory Manager, it is useless to call destructor, it is done automatically when the Handle is nullified(cleared) BUT this is ineffective in looping structures (whatever these are 'Implied' references or not).", py::arg("CN"), py::arg("ent"), py::arg("dispatched"));
cls_Interface_GeneralModule.def("CategoryNumber", (Standard_Integer (Interface_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &) const) &Interface_GeneralModule::CategoryNumber, "Returns a category number which characterizes an entity Category Numbers are managed by the class Category <shares> can be used to evaluate this number in the context Default returns 0 which means 'unspecified'", py::arg("CN"), py::arg("ent"), py::arg("shares"));
cls_Interface_GeneralModule.def("Name", (opencascade::handle<TCollection_HAsciiString> (Interface_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &) const) &Interface_GeneralModule::Name, "Determines if an entity brings a Name (or widerly, if a Name can be attached to it, through the ShareTool By default, returns a Null Handle (no name can be produced) Can be redefined", py::arg("CN"), py::arg("ent"), py::arg("shares"));
cls_Interface_GeneralModule.def_static("get_type_name_", (const char * (*)()) &Interface_GeneralModule::get_type_name, "None");
cls_Interface_GeneralModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_GeneralModule::get_type_descriptor, "None");
cls_Interface_GeneralModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_GeneralModule::*)() const) &Interface_GeneralModule::DynamicType, "None");

// CLASS: INTERFACE_READERMODULE
py::class_<Interface_ReaderModule, opencascade::handle<Interface_ReaderModule>, Standard_Transient> cls_Interface_ReaderModule(mod, "Interface_ReaderModule", "Defines unitary operations required to read an Entity from a File (see FileReaderData, FileReaderTool), under control of a FileReaderTool. The initial creation is performed by a GeneralModule (set in GeneralLib). Then, which remains is Loading data from the FileReaderData to the Entity");

// Methods
cls_Interface_ReaderModule.def("CaseNum", (Standard_Integer (Interface_ReaderModule::*)(const opencascade::handle<Interface_FileReaderData> &, const Standard_Integer) const) &Interface_ReaderModule::CaseNum, "Translates the type of record <num> in <data> to a positive Case Number. If Recognition fails, must return 0", py::arg("data"), py::arg("num"));
cls_Interface_ReaderModule.def("Read", (void (Interface_ReaderModule::*)(const Standard_Integer, const opencascade::handle<Interface_FileReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<Standard_Transient> &) const) &Interface_ReaderModule::Read, "Performs the effective loading from <data>, record <num>, to the Entity <ent> formerly created In case of Error or Warning, fills <ach> with messages Remark that the Case Number comes from translating a record", py::arg("casenum"), py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_Interface_ReaderModule.def("NewRead", (Standard_Boolean (Interface_ReaderModule::*)(const Standard_Integer, const opencascade::handle<Interface_FileReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, opencascade::handle<Standard_Transient> &) const) &Interface_ReaderModule::NewRead, "Specific operator (create+read) defaulted to do nothing. It can be redefined when it is not possible to work in two steps (NewVoid then Read). This occurs when no default constructor is defined : hence the result <ent> must be created with an effective definition from the reader. Remark : if NewRead is defined, Copy has nothing to do.", py::arg("casenum"), py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_Interface_ReaderModule.def_static("get_type_name_", (const char * (*)()) &Interface_ReaderModule::get_type_name, "None");
cls_Interface_ReaderModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_ReaderModule::get_type_descriptor, "None");
cls_Interface_ReaderModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_ReaderModule::*)() const) &Interface_ReaderModule::DynamicType, "None");

// CLASS: INTERFACE_GENERALLIB
py::class_<Interface_GeneralLib> cls_Interface_GeneralLib(mod, "Interface_GeneralLib", "None");

// Constructors
cls_Interface_GeneralLib.def(py::init<const opencascade::handle<Interface_Protocol> &>(), py::arg("aprotocol"));
cls_Interface_GeneralLib.def(py::init<>());

// Methods
// cls_Interface_GeneralLib.def_static("operator new_", (void * (*)(size_t)) &Interface_GeneralLib::operator new, "None", py::arg("theSize"));
// cls_Interface_GeneralLib.def_static("operator delete_", (void (*)(void *)) &Interface_GeneralLib::operator delete, "None", py::arg("theAddress"));
// cls_Interface_GeneralLib.def_static("operator new[]_", (void * (*)(size_t)) &Interface_GeneralLib::operator new[], "None", py::arg("theSize"));
// cls_Interface_GeneralLib.def_static("operator delete[]_", (void (*)(void *)) &Interface_GeneralLib::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_GeneralLib.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_GeneralLib::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_GeneralLib.def_static("operator delete_", (void (*)(void *, void *)) &Interface_GeneralLib::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_GeneralLib.def_static("SetGlobal_", (void (*)(const opencascade::handle<Interface_GeneralModule> &, const opencascade::handle<Interface_Protocol> &)) &Interface_GeneralLib::SetGlobal, "Adds a couple (Module-Protocol) into the global definition set for this class of Library.", py::arg("amodule"), py::arg("aprotocol"));
cls_Interface_GeneralLib.def("AddProtocol", (void (Interface_GeneralLib::*)(const opencascade::handle<Standard_Transient> &)) &Interface_GeneralLib::AddProtocol, "Adds a couple (Module-Protocol) to the Library, given the class of a Protocol. Takes Resources into account. (if <aprotocol> is not of type TheProtocol, it is not added)", py::arg("aprotocol"));
cls_Interface_GeneralLib.def("Clear", (void (Interface_GeneralLib::*)()) &Interface_GeneralLib::Clear, "Clears the list of Modules of a library (can be used to redefine the order of Modules before action : Clear then refill the Library by calls to AddProtocol)");
cls_Interface_GeneralLib.def("SetComplete", (void (Interface_GeneralLib::*)()) &Interface_GeneralLib::SetComplete, "Sets a library to be defined with the complete Global list (all the couples Protocol/Modules recorded in it)");
cls_Interface_GeneralLib.def("Select", [](Interface_GeneralLib &self, const opencascade::handle<Standard_Transient> & obj, opencascade::handle<Interface_GeneralModule> & module, Standard_Integer & CN){ Standard_Boolean rv = self.Select(obj, module, CN); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, CN); }, "Selects a Module from the Library, given an Object. Returns True if Select has succeeded, False else. Also Returns (as arguments) the selected Module and the Case Number determined by the associated Protocol. If Select has failed, <module> is Null Handle and CN is zero. (Select can work on any criterium, such as Object DynamicType)", py::arg("obj"), py::arg("module"), py::arg("CN"));
cls_Interface_GeneralLib.def("Start", (void (Interface_GeneralLib::*)()) &Interface_GeneralLib::Start, "Starts Iteration on the Modules (sets it on the first one)");
cls_Interface_GeneralLib.def("More", (Standard_Boolean (Interface_GeneralLib::*)() const) &Interface_GeneralLib::More, "Returns True if there are more Modules to iterate on");
cls_Interface_GeneralLib.def("Next", (void (Interface_GeneralLib::*)()) &Interface_GeneralLib::Next, "Iterates by getting the next Module in the list If there is none, the exception will be raised by Value");
cls_Interface_GeneralLib.def("Module", (const opencascade::handle<Interface_GeneralModule> & (Interface_GeneralLib::*)() const) &Interface_GeneralLib::Module, "Returns the current Module in the Iteration");
cls_Interface_GeneralLib.def("Protocol", (const opencascade::handle<Interface_Protocol> & (Interface_GeneralLib::*)() const) &Interface_GeneralLib::Protocol, "Returns the current Protocol in the Iteration");

// CLASS: INTERFACE_MSG
py::class_<Interface_MSG> cls_Interface_MSG(mod, "Interface_MSG", "This class gives a set of functions to manage and use a list of translated messages (messagery)");

// Constructors
cls_Interface_MSG.def(py::init<const Standard_CString>(), py::arg("key"));
cls_Interface_MSG.def(py::init<const Standard_CString, const Standard_Integer>(), py::arg("key"), py::arg("i1"));
cls_Interface_MSG.def(py::init<const Standard_CString, const Standard_Integer, const Standard_Integer>(), py::arg("key"), py::arg("i1"), py::arg("i2"));
cls_Interface_MSG.def(py::init<const Standard_CString, const Standard_Real>(), py::arg("key"), py::arg("r1"));
cls_Interface_MSG.def(py::init<const Standard_CString, const Standard_Real, const Standard_Integer>(), py::arg("key"), py::arg("r1"), py::arg("intervals"));
cls_Interface_MSG.def(py::init<const Standard_CString, const Standard_CString>(), py::arg("key"), py::arg("str"));
cls_Interface_MSG.def(py::init<const Standard_CString, const Standard_Integer, const Standard_CString>(), py::arg("key"), py::arg("ival"), py::arg("str"));

// Methods
// cls_Interface_MSG.def_static("operator new_", (void * (*)(size_t)) &Interface_MSG::operator new, "None", py::arg("theSize"));
// cls_Interface_MSG.def_static("operator delete_", (void (*)(void *)) &Interface_MSG::operator delete, "None", py::arg("theAddress"));
// cls_Interface_MSG.def_static("operator new[]_", (void * (*)(size_t)) &Interface_MSG::operator new[], "None", py::arg("theSize"));
// cls_Interface_MSG.def_static("operator delete[]_", (void (*)(void *)) &Interface_MSG::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_MSG.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_MSG::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_MSG.def_static("operator delete_", (void (*)(void *, void *)) &Interface_MSG::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_MSG.def("Destroy", (void (Interface_MSG::*)()) &Interface_MSG::Destroy, "Optimised destructor (applies for additional forms of Create)");
cls_Interface_MSG.def("Value", (Standard_CString (Interface_MSG::*)() const) &Interface_MSG::Value, "Returns the translated message, in a functional form with operator () was C++ : return const");
cls_Interface_MSG.def_static("Read_", (Standard_Integer (*)(Standard_IStream &)) &Interface_MSG::Read, "Reads a list of messages from a stream, returns read count 0 means empty file, -1 means error", py::arg("S"));
cls_Interface_MSG.def_static("Read_", (Standard_Integer (*)(const Standard_CString)) &Interface_MSG::Read, "Reads a list of messages from a file defined by its name", py::arg("file"));
cls_Interface_MSG.def_static("Write_", [](Standard_OStream & a0) -> Standard_Integer { return Interface_MSG::Write(a0); });
cls_Interface_MSG.def_static("Write_", (Standard_Integer (*)(Standard_OStream &, const Standard_CString)) &Interface_MSG::Write, "Writes the list of messages recorded to be translated, to a stream. Writes all the list (Default) or only keys which begin by <rootkey>. Returns the count of written messages", py::arg("S"), py::arg("rootkey"));
cls_Interface_MSG.def_static("IsKey_", (Standard_Boolean (*)(const Standard_CString)) &Interface_MSG::IsKey, "Returns True if a given message is surely a key (according to the form adopted for keys) (before activating messages, answer is false)", py::arg("mess"));
cls_Interface_MSG.def_static("Translated_", (Standard_CString (*)(const Standard_CString)) &Interface_MSG::Translated, "Returns the item recorded for a key. Returns the key itself if : - it is not recorded (then, the trace system is activated) - MSG has been required to be hung on", py::arg("key"));
cls_Interface_MSG.def_static("Record_", (void (*)(const Standard_CString, const Standard_CString)) &Interface_MSG::Record, "Fills the dictionary with a couple (key-item) If a key is already recorded, it is possible to : - keep the last definition, and activate the trace system", py::arg("key"), py::arg("item"));
cls_Interface_MSG.def_static("SetTrace_", (void (*)(const Standard_Boolean, const Standard_Boolean)) &Interface_MSG::SetTrace, "Sets the trace system to work when activated, as follow : - if <toprint> is True, print immediately on standard output - if <torecord> is True, record it for further print", py::arg("toprint"), py::arg("torecord"));
cls_Interface_MSG.def_static("SetMode_", (void (*)(const Standard_Boolean, const Standard_Boolean)) &Interface_MSG::SetMode, "Sets the main modes for MSG : - if <running> is True, translation works normally - if <running> is False, translated item equate keys - if <raising> is True, errors (from Record or Translate) cause MSG to raise an exception - if <raising> is False, MSG runs without exception, then see also Trace Modes above", py::arg("running"), py::arg("raising"));
cls_Interface_MSG.def_static("PrintTrace_", (void (*)(Standard_OStream &)) &Interface_MSG::PrintTrace, "Prints the recorded errors (without title; can be empty, this is the normally expected case)", py::arg("S"));
cls_Interface_MSG.def_static("Intervalled_", [](const Standard_Real a0) -> Standard_Real { return Interface_MSG::Intervalled(a0); });
cls_Interface_MSG.def_static("Intervalled_", [](const Standard_Real a0, const Standard_Integer a1) -> Standard_Real { return Interface_MSG::Intervalled(a0, a1); });
cls_Interface_MSG.def_static("Intervalled_", (Standard_Real (*)(const Standard_Real, const Standard_Integer, const Standard_Boolean)) &Interface_MSG::Intervalled, "Returns an 'intervalled' value from a starting real <val> : i.e. a value which is rounded on an interval limit Interval limits are defined to be in a coarsely 'geometric' progression (two successive intervals are inside a limit ratio)", py::arg("val"), py::arg("order"), py::arg("upper"));
cls_Interface_MSG.def_static("TDate_", [](const Standard_CString a0, const Standard_Integer a1, const Standard_Integer a2, const Standard_Integer a3, const Standard_Integer a4, const Standard_Integer a5, const Standard_Integer a6) -> void { return Interface_MSG::TDate(a0, a1, a2, a3, a4, a5, a6); });
cls_Interface_MSG.def_static("TDate_", (void (*)(const Standard_CString, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_CString)) &Interface_MSG::TDate, "Codes a date as a text, from its numeric value (-> seconds) : YYYY-MM-DD:HH-MN-SS fixed format, completed by leading zeros Another format can be provided, as follows : C:%d ... C like format, preceeded by C: S:... format to call system (not yet implemented)", py::arg("text"), py::arg("yy"), py::arg("mm"), py::arg("dd"), py::arg("hh"), py::arg("mn"), py::arg("ss"), py::arg("format"));
cls_Interface_MSG.def_static("NDate_", [](const Standard_CString text, Standard_Integer & yy, Standard_Integer & mm, Standard_Integer & dd, Standard_Integer & hh, Standard_Integer & mn, Standard_Integer & ss){ Standard_Boolean rv = Interface_MSG::NDate(text, yy, mm, dd, hh, mn, ss); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(rv, yy, mm, dd, hh, mn, ss); }, "Decodes a date to numeric integer values Returns True if OK, False if text does not fit with required format. Incomplete forms are allowed (for instance, for only YYYY-MM-DD, hour is zero)", py::arg("text"), py::arg("yy"), py::arg("mm"), py::arg("dd"), py::arg("hh"), py::arg("mn"), py::arg("ss"));
cls_Interface_MSG.def_static("CDate_", (Standard_Integer (*)(const Standard_CString, const Standard_CString)) &Interface_MSG::CDate, "Returns a value about comparison of two dates 0 : equal. <0 text1 anterior. >0 text1 posterior", py::arg("text1"), py::arg("text2"));
cls_Interface_MSG.def_static("Blanks_", (Standard_CString (*)(const Standard_Integer, const Standard_Integer)) &Interface_MSG::Blanks, "Returns a blank string, of length between 0 and <max>, to fill the printing of a numeric value <val>, i.e. : If val < 10 , max-1 blanks If val between 10 and 99, max-2 blanks ... etc...", py::arg("val"), py::arg("max"));
cls_Interface_MSG.def_static("Blanks_", (Standard_CString (*)(const Standard_CString, const Standard_Integer)) &Interface_MSG::Blanks, "Returns a blank string, to complete a given string <val> up to <max> characters : If strlen(val) is 0, max blanks If strlen(val) is 5, max-5 blanks etc...", py::arg("val"), py::arg("max"));
cls_Interface_MSG.def_static("Blanks_", (Standard_CString (*)(const Standard_Integer)) &Interface_MSG::Blanks, "Returns a blank string of <count> blanks (mini 0, maxi 76)", py::arg("count"));
cls_Interface_MSG.def_static("Print_", [](Standard_OStream & a0, const Standard_CString a1, const Standard_Integer a2) -> void { return Interface_MSG::Print(a0, a1, a2); });
cls_Interface_MSG.def_static("Print_", (void (*)(Standard_OStream &, const Standard_CString, const Standard_Integer, const Standard_Integer)) &Interface_MSG::Print, "Prints a String on an Output Stream, as follows : Accompagned with blanks, to give up to <max> charis at all, justified according just : -1 (D) : left 0 : center 1 : right Maximum 76 characters", py::arg("S"), py::arg("val"), py::arg("max"), py::arg("just"));

// CLASS: INTERFACE_FILEREADERDATA
py::class_<Interface_FileReaderData, opencascade::handle<Interface_FileReaderData>, Standard_Transient> cls_Interface_FileReaderData(mod, "Interface_FileReaderData", "This class defines services which permit to access Data issued from a File, in a form which does not depend of physical format : thus, each Record has an attached ParamList (to be managed) and resulting Entity.");

// Methods
cls_Interface_FileReaderData.def("NbRecords", (Standard_Integer (Interface_FileReaderData::*)() const) &Interface_FileReaderData::NbRecords, "Returns the count of registered records That is, value given for Initialization (can be redefined)");
cls_Interface_FileReaderData.def("NbEntities", (Standard_Integer (Interface_FileReaderData::*)() const) &Interface_FileReaderData::NbEntities, "Returns the count of entities. Depending of each norm, records can be Entities or SubParts (SubList in STEP, SubGroup in SET ...). NbEntities counts only Entities, not Subs Used for memory reservation in InterfaceModel Default implementation uses FindNextRecord Can be redefined into a more performant way");
cls_Interface_FileReaderData.def("FindNextRecord", (Standard_Integer (Interface_FileReaderData::*)(const Standard_Integer) const) &Interface_FileReaderData::FindNextRecord, "Determines the record number defining an Entity following a given record number. Specific to each sub-class of FileReaderData. Returning zero means no record found", py::arg("num"));
cls_Interface_FileReaderData.def("InitParams", (void (Interface_FileReaderData::*)(const Standard_Integer)) &Interface_FileReaderData::InitParams, "attaches an empty ParamList to a Record", py::arg("num"));
cls_Interface_FileReaderData.def("AddParam", [](Interface_FileReaderData &self, const Standard_Integer a0, const Standard_CString a1, const Interface_ParamType a2) -> void { return self.AddParam(a0, a1, a2); });
cls_Interface_FileReaderData.def("AddParam", (void (Interface_FileReaderData::*)(const Standard_Integer, const Standard_CString, const Interface_ParamType, const Standard_Integer)) &Interface_FileReaderData::AddParam, "Adds a parameter to record no 'num' and fills its fields (EntityNumber is optional) Warning : <aval> is assumed to be memory-managed elsewhere : it is NOT copied. This gives a best speed : strings remain stored in pages of characters", py::arg("num"), py::arg("aval"), py::arg("atype"), py::arg("nument"));
cls_Interface_FileReaderData.def("AddParam", [](Interface_FileReaderData &self, const Standard_Integer a0, const TCollection_AsciiString & a1, const Interface_ParamType a2) -> void { return self.AddParam(a0, a1, a2); });
cls_Interface_FileReaderData.def("AddParam", (void (Interface_FileReaderData::*)(const Standard_Integer, const TCollection_AsciiString &, const Interface_ParamType, const Standard_Integer)) &Interface_FileReaderData::AddParam, "Same as above, but gets a AsciiString from TCollection Remark that the content of the AsciiString is locally copied (because its content is most often lost after using)", py::arg("num"), py::arg("aval"), py::arg("atype"), py::arg("nument"));
cls_Interface_FileReaderData.def("AddParam", (void (Interface_FileReaderData::*)(const Standard_Integer, const Interface_FileParameter &)) &Interface_FileReaderData::AddParam, "Same as above, but gets a complete FileParameter Warning : Content of <FP> is NOT copied : its original address and space in memory are assumed to be managed elsewhere (see ParamSet)", py::arg("num"), py::arg("FP"));
cls_Interface_FileReaderData.def("SetParam", (void (Interface_FileReaderData::*)(const Standard_Integer, const Standard_Integer, const Interface_FileParameter &)) &Interface_FileReaderData::SetParam, "Sets a new value for a parameter of a record, given by : num : record number; nump : parameter number in the record", py::arg("num"), py::arg("nump"), py::arg("FP"));
cls_Interface_FileReaderData.def("NbParams", (Standard_Integer (Interface_FileReaderData::*)(const Standard_Integer) const) &Interface_FileReaderData::NbParams, "Returns count of parameters attached to record 'num' If <num> = 0, returns the total recorded count of parameters", py::arg("num"));
cls_Interface_FileReaderData.def("Params", (opencascade::handle<Interface_ParamList> (Interface_FileReaderData::*)(const Standard_Integer) const) &Interface_FileReaderData::Params, "Returns the complete ParamList of a record (read only) num = 0 to return the whole param list for the file", py::arg("num"));
cls_Interface_FileReaderData.def("Param", (const Interface_FileParameter & (Interface_FileReaderData::*)(const Standard_Integer, const Standard_Integer) const) &Interface_FileReaderData::Param, "Returns parameter 'nump' of record 'num', as a complete FileParameter", py::arg("num"), py::arg("nump"));
cls_Interface_FileReaderData.def("ChangeParam", (Interface_FileParameter & (Interface_FileReaderData::*)(const Standard_Integer, const Standard_Integer)) &Interface_FileReaderData::ChangeParam, "Same as above, but in order to be modified on place", py::arg("num"), py::arg("nump"));
cls_Interface_FileReaderData.def("ParamType", (Interface_ParamType (Interface_FileReaderData::*)(const Standard_Integer, const Standard_Integer) const) &Interface_FileReaderData::ParamType, "Returns type of parameter 'nump' of record 'num' Returns literal value of parameter 'nump' of record 'num' was C++ : return const &", py::arg("num"), py::arg("nump"));
cls_Interface_FileReaderData.def("ParamCValue", (Standard_CString (Interface_FileReaderData::*)(const Standard_Integer, const Standard_Integer) const) &Interface_FileReaderData::ParamCValue, "Same as above, but as a CString was C++ : return const", py::arg("num"), py::arg("nump"));
cls_Interface_FileReaderData.def("IsParamDefined", (Standard_Boolean (Interface_FileReaderData::*)(const Standard_Integer, const Standard_Integer) const) &Interface_FileReaderData::IsParamDefined, "Returns True if parameter 'nump' of record 'num' is defined (it is not if its type is ParamVoid)", py::arg("num"), py::arg("nump"));
cls_Interface_FileReaderData.def("ParamNumber", (Standard_Integer (Interface_FileReaderData::*)(const Standard_Integer, const Standard_Integer) const) &Interface_FileReaderData::ParamNumber, "Returns record number of an entity referenced by a parameter of type Ident; 0 if no EntityNumber has been determined Note that it is used to reference Entities but also Sublists (sublists are not objects, but internal descriptions)", py::arg("num"), py::arg("nump"));
cls_Interface_FileReaderData.def("ParamEntity", (const opencascade::handle<Standard_Transient> & (Interface_FileReaderData::*)(const Standard_Integer, const Standard_Integer) const) &Interface_FileReaderData::ParamEntity, "Returns the StepEntity referenced by a parameter Error if none", py::arg("num"), py::arg("nump"));
cls_Interface_FileReaderData.def("ParamFirstRank", (Standard_Integer (Interface_FileReaderData::*)(const Standard_Integer) const) &Interface_FileReaderData::ParamFirstRank, "Returns the absolute rank of the beginning of a record (its lsit is from ParamFirstRank+1 to ParamFirstRank+NbParams)", py::arg("num"));
cls_Interface_FileReaderData.def("BoundEntity", (const opencascade::handle<Standard_Transient> & (Interface_FileReaderData::*)(const Standard_Integer) const) &Interface_FileReaderData::BoundEntity, "Returns the entity bound to a record, set by SetEntities", py::arg("num"));
cls_Interface_FileReaderData.def("BindEntity", (void (Interface_FileReaderData::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &)) &Interface_FileReaderData::BindEntity, "Binds an entity to a record", py::arg("num"), py::arg("ent"));
cls_Interface_FileReaderData.def("SetErrorLoad", (void (Interface_FileReaderData::*)(const Standard_Boolean)) &Interface_FileReaderData::SetErrorLoad, "Sets the status 'Error Load' on, to overside check fails <val> True : declares unloaded <val> False : declares loaded If not called before loading (see FileReaderTool), check fails give the status IsErrorLoad says if SetErrorLoad has been called by user ResetErrorLoad resets it (called by FileReaderTool) This allows to specify that the currently loaded entity remains unloaded (because of syntactic fail)", py::arg("val"));
cls_Interface_FileReaderData.def("IsErrorLoad", (Standard_Boolean (Interface_FileReaderData::*)() const) &Interface_FileReaderData::IsErrorLoad, "Returns True if the status 'Error Load' has been set (to True or False)");
cls_Interface_FileReaderData.def("ResetErrorLoad", (Standard_Boolean (Interface_FileReaderData::*)()) &Interface_FileReaderData::ResetErrorLoad, "Returns the former value of status 'Error Load' then resets it Used to read the status then ensure it is reset");
cls_Interface_FileReaderData.def("Destroy", (void (Interface_FileReaderData::*)()) &Interface_FileReaderData::Destroy, "Destructor (waiting for memory management)");
cls_Interface_FileReaderData.def_static("Fastof_", (Standard_Real (*)(const Standard_CString)) &Interface_FileReaderData::Fastof, "Same spec.s as standard <atof> but 5 times faster", py::arg("str"));
cls_Interface_FileReaderData.def_static("get_type_name_", (const char * (*)()) &Interface_FileReaderData::get_type_name, "None");
cls_Interface_FileReaderData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_FileReaderData::get_type_descriptor, "None");
cls_Interface_FileReaderData.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_FileReaderData::*)() const) &Interface_FileReaderData::DynamicType, "None");

// CLASS: INTERFACE_READERLIB
py::class_<Interface_ReaderLib> cls_Interface_ReaderLib(mod, "Interface_ReaderLib", "None");

// Constructors
cls_Interface_ReaderLib.def(py::init<const opencascade::handle<Interface_Protocol> &>(), py::arg("aprotocol"));
cls_Interface_ReaderLib.def(py::init<>());

// Methods
// cls_Interface_ReaderLib.def_static("operator new_", (void * (*)(size_t)) &Interface_ReaderLib::operator new, "None", py::arg("theSize"));
// cls_Interface_ReaderLib.def_static("operator delete_", (void (*)(void *)) &Interface_ReaderLib::operator delete, "None", py::arg("theAddress"));
// cls_Interface_ReaderLib.def_static("operator new[]_", (void * (*)(size_t)) &Interface_ReaderLib::operator new[], "None", py::arg("theSize"));
// cls_Interface_ReaderLib.def_static("operator delete[]_", (void (*)(void *)) &Interface_ReaderLib::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_ReaderLib.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_ReaderLib::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_ReaderLib.def_static("operator delete_", (void (*)(void *, void *)) &Interface_ReaderLib::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_ReaderLib.def_static("SetGlobal_", (void (*)(const opencascade::handle<Interface_ReaderModule> &, const opencascade::handle<Interface_Protocol> &)) &Interface_ReaderLib::SetGlobal, "Adds a couple (Module-Protocol) into the global definition set for this class of Library.", py::arg("amodule"), py::arg("aprotocol"));
cls_Interface_ReaderLib.def("AddProtocol", (void (Interface_ReaderLib::*)(const opencascade::handle<Standard_Transient> &)) &Interface_ReaderLib::AddProtocol, "Adds a couple (Module-Protocol) to the Library, given the class of a Protocol. Takes Resources into account. (if <aprotocol> is not of type TheProtocol, it is not added)", py::arg("aprotocol"));
cls_Interface_ReaderLib.def("Clear", (void (Interface_ReaderLib::*)()) &Interface_ReaderLib::Clear, "Clears the list of Modules of a library (can be used to redefine the order of Modules before action : Clear then refill the Library by calls to AddProtocol)");
cls_Interface_ReaderLib.def("SetComplete", (void (Interface_ReaderLib::*)()) &Interface_ReaderLib::SetComplete, "Sets a library to be defined with the complete Global list (all the couples Protocol/Modules recorded in it)");
cls_Interface_ReaderLib.def("Select", [](Interface_ReaderLib &self, const opencascade::handle<Standard_Transient> & obj, opencascade::handle<Interface_ReaderModule> & module, Standard_Integer & CN){ Standard_Boolean rv = self.Select(obj, module, CN); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, CN); }, "Selects a Module from the Library, given an Object. Returns True if Select has succeeded, False else. Also Returns (as arguments) the selected Module and the Case Number determined by the associated Protocol. If Select has failed, <module> is Null Handle and CN is zero. (Select can work on any criterium, such as Object DynamicType)", py::arg("obj"), py::arg("module"), py::arg("CN"));
cls_Interface_ReaderLib.def("Start", (void (Interface_ReaderLib::*)()) &Interface_ReaderLib::Start, "Starts Iteration on the Modules (sets it on the first one)");
cls_Interface_ReaderLib.def("More", (Standard_Boolean (Interface_ReaderLib::*)() const) &Interface_ReaderLib::More, "Returns True if there are more Modules to iterate on");
cls_Interface_ReaderLib.def("Next", (void (Interface_ReaderLib::*)()) &Interface_ReaderLib::Next, "Iterates by getting the next Module in the list If there is none, the exception will be raised by Value");
cls_Interface_ReaderLib.def("Module", (const opencascade::handle<Interface_ReaderModule> & (Interface_ReaderLib::*)() const) &Interface_ReaderLib::Module, "Returns the current Module in the Iteration");
cls_Interface_ReaderLib.def("Protocol", (const opencascade::handle<Interface_Protocol> & (Interface_ReaderLib::*)() const) &Interface_ReaderLib::Protocol, "Returns the current Protocol in the Iteration");

// CLASS: INTERFACE_FILEREADERTOOL
py::class_<Interface_FileReaderTool> cls_Interface_FileReaderTool(mod, "Interface_FileReaderTool", "Defines services which are required to load an InterfaceModel from a File. Typically, it may firstly transform a system file into a FileReaderData object, then work on it, not longer considering file contents, to load an Interface Model. It may also work on a FileReaderData already loaded.");

// Methods
// cls_Interface_FileReaderTool.def_static("operator new_", (void * (*)(size_t)) &Interface_FileReaderTool::operator new, "None", py::arg("theSize"));
// cls_Interface_FileReaderTool.def_static("operator delete_", (void (*)(void *)) &Interface_FileReaderTool::operator delete, "None", py::arg("theAddress"));
// cls_Interface_FileReaderTool.def_static("operator new[]_", (void * (*)(size_t)) &Interface_FileReaderTool::operator new[], "None", py::arg("theSize"));
// cls_Interface_FileReaderTool.def_static("operator delete[]_", (void (*)(void *)) &Interface_FileReaderTool::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_FileReaderTool.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_FileReaderTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_FileReaderTool.def_static("operator delete_", (void (*)(void *, void *)) &Interface_FileReaderTool::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_FileReaderTool.def("SetData", (void (Interface_FileReaderTool::*)(const opencascade::handle<Interface_FileReaderData> &, const opencascade::handle<Interface_Protocol> &)) &Interface_FileReaderTool::SetData, "Sets Data to a FileReaderData. Works with a Protocol", py::arg("reader"), py::arg("protocol"));
cls_Interface_FileReaderTool.def("Protocol", (opencascade::handle<Interface_Protocol> (Interface_FileReaderTool::*)() const) &Interface_FileReaderTool::Protocol, "Returns the Protocol given at creation time");
cls_Interface_FileReaderTool.def("Data", (opencascade::handle<Interface_FileReaderData> (Interface_FileReaderTool::*)() const) &Interface_FileReaderTool::Data, "Returns the FileReaderData which is used to work");
cls_Interface_FileReaderTool.def("SetModel", (void (Interface_FileReaderTool::*)(const opencascade::handle<Interface_InterfaceModel> &)) &Interface_FileReaderTool::SetModel, "Stores a Model. Used when the Model has been loaded", py::arg("amodel"));
cls_Interface_FileReaderTool.def("Model", (opencascade::handle<Interface_InterfaceModel> (Interface_FileReaderTool::*)() const) &Interface_FileReaderTool::Model, "Returns the stored Model");
cls_Interface_FileReaderTool.def("SetMessenger", (void (Interface_FileReaderTool::*)(const opencascade::handle<Message_Messenger> &)) &Interface_FileReaderTool::SetMessenger, "Sets Messenger used for outputting messages", py::arg("messenger"));
cls_Interface_FileReaderTool.def("Messenger", (opencascade::handle<Message_Messenger> (Interface_FileReaderTool::*)() const) &Interface_FileReaderTool::Messenger, "Returns Messenger used for outputting messages. The returned object is guaranteed to be non-null; default is Message::Messenger().");
cls_Interface_FileReaderTool.def("SetTraceLevel", (void (Interface_FileReaderTool::*)(const Standard_Integer)) &Interface_FileReaderTool::SetTraceLevel, "Sets trace level used for outputting messages - 0: no trace at all - 1: errors - 2: errors and warnings - 3: all messages Default is 1 : Errors traced", py::arg("tracelev"));
cls_Interface_FileReaderTool.def("TraceLevel", (Standard_Integer (Interface_FileReaderTool::*)() const) &Interface_FileReaderTool::TraceLevel, "Returns trace level used for outputting messages.");
cls_Interface_FileReaderTool.def("SetErrorHandle", (void (Interface_FileReaderTool::*)(const Standard_Boolean)) &Interface_FileReaderTool::SetErrorHandle, "Allows controlling whether exception raisings are handled If err is False, they are not (hence, dbx can take control) If err is True, they are, and they are traced (by putting on messenger Entity's Number and file record num) Default given at Model's creation time is True", py::arg("err"));
cls_Interface_FileReaderTool.def("ErrorHandle", (Standard_Boolean (Interface_FileReaderTool::*)() const) &Interface_FileReaderTool::ErrorHandle, "Returns ErrorHandle flag");
cls_Interface_FileReaderTool.def("SetEntities", (void (Interface_FileReaderTool::*)()) &Interface_FileReaderTool::SetEntities, "Fills records with empty entities; once done, each entity can ask the FileReaderTool for any entity referenced through an identifier. Calls Recognize which is specific to each specific type of FileReaderTool");
cls_Interface_FileReaderTool.def("Recognize", (Standard_Boolean (Interface_FileReaderTool::*)(const Standard_Integer, opencascade::handle<Interface_Check> &, opencascade::handle<Standard_Transient> &)) &Interface_FileReaderTool::Recognize, "Recognizes a record, given its number. Specific to each Interface; called by SetEntities. It can call the basic method RecognizeByLib. Returns False if recognition has failed, True else. <ach> has not to be filled if simply Recognition has failed : it must record true error messages : RecognizeByLib can generate error messages if NewRead is called", py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_Interface_FileReaderTool.def("RecognizeByLib", (Standard_Boolean (Interface_FileReaderTool::*)(const Standard_Integer, Interface_GeneralLib &, Interface_ReaderLib &, opencascade::handle<Interface_Check> &, opencascade::handle<Standard_Transient> &) const) &Interface_FileReaderTool::RecognizeByLib, "Recognizes a record with the help of Libraries. Can be used to implement the method Recognize. <rlib> is used to find Protocol and CaseNumber to apply <glib> performs the creation (by service NewVoid, or NewRead if NewVoid gave no result) <ach> is a check, which is transmitted to NewRead if it is called, gives a result but which is false <ent> is the result Returns False if recognition has failed, True else", py::arg("num"), py::arg("glib"), py::arg("rlib"), py::arg("ach"), py::arg("ent"));
cls_Interface_FileReaderTool.def("UnknownEntity", (opencascade::handle<Standard_Transient> (Interface_FileReaderTool::*)() const) &Interface_FileReaderTool::UnknownEntity, "Provides an unknown entity, specific to the Interface called by SetEntities when Recognize has failed (Unknown alone) or by LoadModel when an Entity has caused a Fail on reading (to keep at least its literal description) Uses Protocol to do it");
cls_Interface_FileReaderTool.def("NewModel", (opencascade::handle<Interface_InterfaceModel> (Interface_FileReaderTool::*)() const) &Interface_FileReaderTool::NewModel, "Creates an empty Model of the norm. Uses Protocol to do it");
cls_Interface_FileReaderTool.def("LoadModel", (void (Interface_FileReaderTool::*)(const opencascade::handle<Interface_InterfaceModel> &)) &Interface_FileReaderTool::LoadModel, "Reads and fills Entities from the FileReaderData set by SetData to an InterfaceModel. It enchains required operations, the specific ones correspond to deferred methods (below) to be defined for each Norm. It manages also error recovery and trace. Remark : it calls SetModel. It Can raise any error which can occur during a load operation, unless Error Handling is set. This method can also be redefined if judged necessary.", py::arg("amodel"));
cls_Interface_FileReaderTool.def("LoadedEntity", (opencascade::handle<Standard_Transient> (Interface_FileReaderTool::*)(const Standard_Integer)) &Interface_FileReaderTool::LoadedEntity, "Reads, Fills and Returns one Entity read from a Record of the FileReaderData. This Method manages also case of Fail or Warning, by producing a ReportEntyty plus , for a Fail, a literal Content (as an UnknownEntity). Performs also Trace", py::arg("num"));
cls_Interface_FileReaderTool.def("BeginRead", (void (Interface_FileReaderTool::*)(const opencascade::handle<Interface_InterfaceModel> &)) &Interface_FileReaderTool::BeginRead, "Fills model's header; each Interface defines for its Model its own file header; this method fills it from FileReaderTool.+ It is called by AnalyseFile from InterfaceModel", py::arg("amodel"));
cls_Interface_FileReaderTool.def("AnalyseRecord", (Standard_Boolean (Interface_FileReaderTool::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, opencascade::handle<Interface_Check> &)) &Interface_FileReaderTool::AnalyseRecord, "Fills an Entity, given record no; specific to each Interface, called by AnalyseFile from InterfaceModel (which manages its calling arguments) To work, each Interface can define a method in its proper Transient class, like this (given as an example) : AnalyseRecord (me : mutable; FR : in out FileReaderTool; num : Integer; acheck : in out Check) returns Boolean; and call it from AnalyseRecord", py::arg("num"), py::arg("anent"), py::arg("acheck"));
cls_Interface_FileReaderTool.def("EndRead", (void (Interface_FileReaderTool::*)(const opencascade::handle<Interface_InterfaceModel> &)) &Interface_FileReaderTool::EndRead, "Ends file reading after reading all the entities default is doing nothing; redefinable as necessary", py::arg("amodel"));
cls_Interface_FileReaderTool.def("Clear", (void (Interface_FileReaderTool::*)()) &Interface_FileReaderTool::Clear, "Clear filelds");

// CLASS: INTERFACE_LINEBUFFER
py::class_<Interface_LineBuffer> cls_Interface_LineBuffer(mod, "Interface_LineBuffer", "Simple Management of a Line Buffer, to be used by Interface File Writers. While a String is suitable to do that, this class ensures an optimised Memory Management, because this is a hard point of File Writing.");

// Constructors
cls_Interface_LineBuffer.def(py::init<>());
cls_Interface_LineBuffer.def(py::init<const Standard_Integer>(), py::arg("size"));

// Methods
// cls_Interface_LineBuffer.def_static("operator new_", (void * (*)(size_t)) &Interface_LineBuffer::operator new, "None", py::arg("theSize"));
// cls_Interface_LineBuffer.def_static("operator delete_", (void (*)(void *)) &Interface_LineBuffer::operator delete, "None", py::arg("theAddress"));
// cls_Interface_LineBuffer.def_static("operator new[]_", (void * (*)(size_t)) &Interface_LineBuffer::operator new[], "None", py::arg("theSize"));
// cls_Interface_LineBuffer.def_static("operator delete[]_", (void (*)(void *)) &Interface_LineBuffer::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_LineBuffer.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_LineBuffer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_LineBuffer.def_static("operator delete_", (void (*)(void *, void *)) &Interface_LineBuffer::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_LineBuffer.def("SetMax", (void (Interface_LineBuffer::*)(const Standard_Integer)) &Interface_LineBuffer::SetMax, "Changes Maximum allowed size of Buffer. If <max> is Zero, Maximum size is set to the initial size.", py::arg("max"));
cls_Interface_LineBuffer.def("SetInitial", (void (Interface_LineBuffer::*)(const Standard_Integer)) &Interface_LineBuffer::SetInitial, "Sets an Initial reservation for Blank characters (this reservation is counted in the size of the current Line)", py::arg("initial"));
cls_Interface_LineBuffer.def("SetKeep", (void (Interface_LineBuffer::*)()) &Interface_LineBuffer::SetKeep, "Sets a Keep Status at current Length. It means that at next Move, the new line will begin by characters between Keep + 1 and current Length");
cls_Interface_LineBuffer.def("CanGet", (Standard_Boolean (Interface_LineBuffer::*)(const Standard_Integer)) &Interface_LineBuffer::CanGet, "Returns True if there is room enough to add <more> characters Else, it is required to Dump the Buffer before refilling it <more> is recorded to manage SetKeep status", py::arg("more"));
cls_Interface_LineBuffer.def("Content", (Standard_CString (Interface_LineBuffer::*)() const) &Interface_LineBuffer::Content, "Returns the Content of the LineBuffer");
cls_Interface_LineBuffer.def("Length", (Standard_Integer (Interface_LineBuffer::*)() const) &Interface_LineBuffer::Length, "Returns the Length of the LineBuffer");
cls_Interface_LineBuffer.def("Clear", (void (Interface_LineBuffer::*)()) &Interface_LineBuffer::Clear, "Clears completely the LineBuffer");
cls_Interface_LineBuffer.def("FreezeInitial", (void (Interface_LineBuffer::*)()) &Interface_LineBuffer::FreezeInitial, "Inhibits effect of SetInitial until the next Move (i.e. Keep) Then Prepare will not insert initial blanks, but further ones will. This allows to cancel initial blanks on an internal Split A call to SetInitial has no effect on this until Move");
cls_Interface_LineBuffer.def("Move", (void (Interface_LineBuffer::*)(TCollection_AsciiString &)) &Interface_LineBuffer::Move, "Fills a AsciiString <str> with the Content of the Line Buffer, then Clears the LineBuffer", py::arg("str"));
cls_Interface_LineBuffer.def("Move", (void (Interface_LineBuffer::*)(const opencascade::handle<TCollection_HAsciiString> &)) &Interface_LineBuffer::Move, "Same as above, but <str> is known through a Handle", py::arg("str"));
cls_Interface_LineBuffer.def("Moved", (opencascade::handle<TCollection_HAsciiString> (Interface_LineBuffer::*)()) &Interface_LineBuffer::Moved, "Same as above, but generates the HAsciiString");
cls_Interface_LineBuffer.def("Add", (void (Interface_LineBuffer::*)(const Standard_CString)) &Interface_LineBuffer::Add, "Adds a text as a CString. Its Length is evaluated from the text (by C function strlen)", py::arg("text"));
cls_Interface_LineBuffer.def("Add", (void (Interface_LineBuffer::*)(const Standard_CString, const Standard_Integer)) &Interface_LineBuffer::Add, "Adds a text as a CString. Its length is given as <lntext>", py::arg("text"), py::arg("lntext"));
cls_Interface_LineBuffer.def("Add", (void (Interface_LineBuffer::*)(const TCollection_AsciiString &)) &Interface_LineBuffer::Add, "Adds a text as a AsciiString from TCollection", py::arg("text"));
cls_Interface_LineBuffer.def("Add", (void (Interface_LineBuffer::*)(const Standard_Character)) &Interface_LineBuffer::Add, "Adds a text made of only ONE Character", py::arg("text"));

// CLASS: INTERFACE_FLOATWRITER
py::class_<Interface_FloatWriter> cls_Interface_FloatWriter(mod, "Interface_FloatWriter", "This class converts a floting number (Real) to a string It can be used if the standard C-C++ output functions (sprintf or std::cout<<) are not convenient. That is to say : - to suppress trailing '0' and 'E+00' (if desired) - to control exponant output and floating point output");

// Constructors
cls_Interface_FloatWriter.def(py::init<>());
cls_Interface_FloatWriter.def(py::init<const Standard_Integer>(), py::arg("chars"));

// Methods
// cls_Interface_FloatWriter.def_static("operator new_", (void * (*)(size_t)) &Interface_FloatWriter::operator new, "None", py::arg("theSize"));
// cls_Interface_FloatWriter.def_static("operator delete_", (void (*)(void *)) &Interface_FloatWriter::operator delete, "None", py::arg("theAddress"));
// cls_Interface_FloatWriter.def_static("operator new[]_", (void * (*)(size_t)) &Interface_FloatWriter::operator new[], "None", py::arg("theSize"));
// cls_Interface_FloatWriter.def_static("operator delete[]_", (void (*)(void *)) &Interface_FloatWriter::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_FloatWriter.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_FloatWriter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_FloatWriter.def_static("operator delete_", (void (*)(void *, void *)) &Interface_FloatWriter::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_FloatWriter.def("SetFormat", [](Interface_FloatWriter &self, const Standard_CString a0) -> void { return self.SetFormat(a0); });
cls_Interface_FloatWriter.def("SetFormat", (void (Interface_FloatWriter::*)(const Standard_CString, const Standard_Boolean)) &Interface_FloatWriter::SetFormat, "Sets a specific Format for Sending Reals (main format) (Default from Creation is '%E') If <reset> is given True (default), this call clears effects of former calls to SetFormatForRange and SetZeroSuppress", py::arg("form"), py::arg("reset"));
cls_Interface_FloatWriter.def("SetFormatForRange", (void (Interface_FloatWriter::*)(const Standard_CString, const Standard_Real, const Standard_Real)) &Interface_FloatWriter::SetFormatForRange, "Sets a secondary Format for Real, to be applied between R1 and R2 (in absolute values). A Call to SetRealForm cancels this secondary form if <reset> is True. (Default from Creation is '%f' between 0.1 and 1000.) Warning : if the condition (0. <= R1 < R2) is not fulfilled, this secondary form is canceled.", py::arg("form"), py::arg("R1"), py::arg("R2"));
cls_Interface_FloatWriter.def("SetZeroSuppress", (void (Interface_FloatWriter::*)(const Standard_Boolean)) &Interface_FloatWriter::SetZeroSuppress, "Sets Sending Real Parameters to suppress trailing Zeros and Null Exponant ('E+00'), if <mode> is given True, Resets this mode if <mode> is False (in addition to Real Forms) A call to SetRealFrom resets this mode to False ig <reset> is given True (Default from Creation is True)", py::arg("mode"));
cls_Interface_FloatWriter.def("SetDefaults", [](Interface_FloatWriter &self) -> void { return self.SetDefaults(); });
cls_Interface_FloatWriter.def("SetDefaults", (void (Interface_FloatWriter::*)(const Standard_Integer)) &Interface_FloatWriter::SetDefaults, "Sets again options to the defaults given by Create", py::arg("chars"));
cls_Interface_FloatWriter.def("Options", [](Interface_FloatWriter &self, Standard_Boolean & zerosup, Standard_Boolean & range, Standard_Real & R1, Standard_Real & R2){ self.Options(zerosup, range, R1, R2); return std::tuple<Standard_Boolean &, Standard_Boolean &, Standard_Real &, Standard_Real &>(zerosup, range, R1, R2); }, "Returns active options : <zerosup> is the option ZeroSuppress, <range> is True if a range is set, False else R1,R2 give the range (if it is set)", py::arg("zerosup"), py::arg("range"), py::arg("R1"), py::arg("R2"));
cls_Interface_FloatWriter.def("MainFormat", (Standard_CString (Interface_FloatWriter::*)() const) &Interface_FloatWriter::MainFormat, "Returns the main format was C++ : return const");
cls_Interface_FloatWriter.def("FormatForRange", (Standard_CString (Interface_FloatWriter::*)() const) &Interface_FloatWriter::FormatForRange, "Returns the format for range, if set Meaningful only if <range> from Options is True was C++ : return const");
cls_Interface_FloatWriter.def("Write", (Standard_Integer (Interface_FloatWriter::*)(const Standard_Real, const Standard_CString) const) &Interface_FloatWriter::Write, "Writes a Real value <val> to a string <text> by using the options. Returns the useful Length of produced string. It calls the class method Convert. Warning : <text> is assumed to be wide enough (20-30 is correct) And, even if declared in, its content will be modified", py::arg("val"), py::arg("text"));
cls_Interface_FloatWriter.def_static("Convert_", (Standard_Integer (*)(const Standard_Real, const Standard_CString, const Standard_Boolean, const Standard_Real, const Standard_Real, const Standard_CString, const Standard_CString)) &Interface_FloatWriter::Convert, "This class method converts a Real Value to a string, given options given as arguments. It can be called independantly. Warning : even if declared in, content of <text> will be modified", py::arg("val"), py::arg("text"), py::arg("zerosup"), py::arg("Range1"), py::arg("Range2"), py::arg("mainform"), py::arg("rangeform"));

// CLASS: INTERFACE_FILEPARAMETER
py::class_<Interface_FileParameter> cls_Interface_FileParameter(mod, "Interface_FileParameter", "Auxiliary class to store a litteral parameter in a file intermediate directory or in an UndefinedContent : a reference type Parameter detains an Integer which is used to address a record in the directory. FileParameter is intended to be stored in a ParamSet : hence memory management is performed by ParamSet, which calls Clear to work, while the Destructor (see Destroy) does nothing. Also a FileParameter can be read for consultation only, not to be read from a Structure to be included into another one.");

// Constructors
cls_Interface_FileParameter.def(py::init<>());

// Methods
// cls_Interface_FileParameter.def_static("operator new_", (void * (*)(size_t)) &Interface_FileParameter::operator new, "None", py::arg("theSize"));
// cls_Interface_FileParameter.def_static("operator delete_", (void (*)(void *)) &Interface_FileParameter::operator delete, "None", py::arg("theAddress"));
// cls_Interface_FileParameter.def_static("operator new[]_", (void * (*)(size_t)) &Interface_FileParameter::operator new[], "None", py::arg("theSize"));
// cls_Interface_FileParameter.def_static("operator delete[]_", (void (*)(void *)) &Interface_FileParameter::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_FileParameter.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_FileParameter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_FileParameter.def_static("operator delete_", (void (*)(void *, void *)) &Interface_FileParameter::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_FileParameter.def("Init", (void (Interface_FileParameter::*)(const TCollection_AsciiString &, const Interface_ParamType)) &Interface_FileParameter::Init, "Fills fields (with Entity Number set to zero)", py::arg("val"), py::arg("typ"));
cls_Interface_FileParameter.def("Init", (void (Interface_FileParameter::*)(const Standard_CString, const Interface_ParamType)) &Interface_FileParameter::Init, "Same as above, but builds the Value from a CString", py::arg("val"), py::arg("typ"));
cls_Interface_FileParameter.def("CValue", (Standard_CString (Interface_FileParameter::*)() const) &Interface_FileParameter::CValue, "Same as above, but as a CString (for immediate exploitation) was C++ : return const");
cls_Interface_FileParameter.def("ParamType", (Interface_ParamType (Interface_FileParameter::*)() const) &Interface_FileParameter::ParamType, "Returns the type of the parameter");
cls_Interface_FileParameter.def("SetEntityNumber", (void (Interface_FileParameter::*)(const Standard_Integer)) &Interface_FileParameter::SetEntityNumber, "Allows to set a reference to an Entity in a numbered list", py::arg("num"));
cls_Interface_FileParameter.def("EntityNumber", (Standard_Integer (Interface_FileParameter::*)() const) &Interface_FileParameter::EntityNumber, "Returns value set by SetEntityNumber");
cls_Interface_FileParameter.def("Clear", (void (Interface_FileParameter::*)()) &Interface_FileParameter::Clear, "Clears stored data : frees memory taken for the String Value");
cls_Interface_FileParameter.def("Destroy", (void (Interface_FileParameter::*)()) &Interface_FileParameter::Destroy, "Destructor. Does nothing because Memory is managed by ParamSet");

// TYPEDEF: INTERFACE_ARRAY1OFFILEPARAMETER
bind_NCollection_Array1<Interface_FileParameter>(mod, "Interface_Array1OfFileParameter", py::module_local(false));

// CLASS: INTERFACE_GTOOL
py::class_<Interface_GTool, opencascade::handle<Interface_GTool>, Standard_Transient> cls_Interface_GTool(mod, "Interface_GTool", "GTool - General Tool for a Model Provides the functions performed by Protocol/GeneralModule for entities of a Model, and recorded in a GeneralLib Optimized : once an entity has been queried, the GeneralLib is not longer queried Shareable between several users : as a Handle");

// Constructors
cls_Interface_GTool.def(py::init<>());
cls_Interface_GTool.def(py::init<const opencascade::handle<Interface_Protocol> &>(), py::arg("proto"));
cls_Interface_GTool.def(py::init<const opencascade::handle<Interface_Protocol> &, const Standard_Integer>(), py::arg("proto"), py::arg("nbent"));

// Methods
cls_Interface_GTool.def("SetSignType", (void (Interface_GTool::*)(const opencascade::handle<Interface_SignType> &)) &Interface_GTool::SetSignType, "Sets a new SignType", py::arg("sign"));
cls_Interface_GTool.def("SignType", (opencascade::handle<Interface_SignType> (Interface_GTool::*)() const) &Interface_GTool::SignType, "Returns the SignType. Can be null");
cls_Interface_GTool.def("SignValue", (Standard_CString (Interface_GTool::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &Interface_GTool::SignValue, "Returns the Signature for a Transient Object in a Model It calls SignType to do that If SignType is not defined, return ClassName of <ent>", py::arg("ent"), py::arg("model"));
cls_Interface_GTool.def("SignName", (Standard_CString (Interface_GTool::*)() const) &Interface_GTool::SignName, "Returns the Name of the SignType, or 'Class Name'");
cls_Interface_GTool.def("SetProtocol", [](Interface_GTool &self, const opencascade::handle<Interface_Protocol> & a0) -> void { return self.SetProtocol(a0); });
cls_Interface_GTool.def("SetProtocol", (void (Interface_GTool::*)(const opencascade::handle<Interface_Protocol> &, const Standard_Boolean)) &Interface_GTool::SetProtocol, "Sets a new Protocol if <enforce> is False and the new Protocol equates the old one then nothing is done", py::arg("proto"), py::arg("enforce"));
cls_Interface_GTool.def("Protocol", (opencascade::handle<Interface_Protocol> (Interface_GTool::*)() const) &Interface_GTool::Protocol, "Returns the Protocol. Warning : it can be Null");
cls_Interface_GTool.def("Lib", (Interface_GeneralLib & (Interface_GTool::*)()) &Interface_GTool::Lib, "Returns the GeneralLib itself");
cls_Interface_GTool.def("Reservate", [](Interface_GTool &self, const Standard_Integer a0) -> void { return self.Reservate(a0); });
cls_Interface_GTool.def("Reservate", (void (Interface_GTool::*)(const Standard_Integer, const Standard_Boolean)) &Interface_GTool::Reservate, "Reservates maps for a count of entities <enforce> False : minimum count <enforce> True : clears former reservations Does not clear the maps", py::arg("nb"), py::arg("enforce"));
cls_Interface_GTool.def("ClearEntities", (void (Interface_GTool::*)()) &Interface_GTool::ClearEntities, "Clears the maps which record, for each already recorded entity its Module and Case Number");
cls_Interface_GTool.def("Select", [](Interface_GTool &self, const opencascade::handle<Standard_Transient> & ent, opencascade::handle<Interface_GeneralModule> & gmod, Standard_Integer & CN, const Standard_Boolean enforce){ Standard_Boolean rv = self.Select(ent, gmod, CN, enforce); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, CN); }, "Selects for an entity, its Module and Case Number It is optimised : once done for each entity, the result is mapped and the GeneralLib is not longer queried <enforce> True overpasses this optimisation", py::arg("ent"), py::arg("gmod"), py::arg("CN"), py::arg("enforce"));
cls_Interface_GTool.def_static("get_type_name_", (const char * (*)()) &Interface_GTool::get_type_name, "None");
cls_Interface_GTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_GTool::get_type_descriptor, "None");
cls_Interface_GTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_GTool::*)() const) &Interface_GTool::DynamicType, "None");

// CLASS: INTERFACE_CATEGORY
py::class_<Interface_Category> cls_Interface_Category(mod, "Interface_Category", "This class manages categories A category is defined by a name and a number, and can be seen as a way of rough classification, i.e. less precise than a cdl type. Hence, it is possible to dispatch every entity in about a dozen of categories, twenty is a reasonable maximum.");

// Constructors
cls_Interface_Category.def(py::init<>());
cls_Interface_Category.def(py::init<const opencascade::handle<Interface_Protocol> &>(), py::arg("theProtocol"));
cls_Interface_Category.def(py::init<const opencascade::handle<Interface_GTool> &>(), py::arg("theGTool"));

// Methods
// cls_Interface_Category.def_static("operator new_", (void * (*)(size_t)) &Interface_Category::operator new, "None", py::arg("theSize"));
// cls_Interface_Category.def_static("operator delete_", (void (*)(void *)) &Interface_Category::operator delete, "None", py::arg("theAddress"));
// cls_Interface_Category.def_static("operator new[]_", (void * (*)(size_t)) &Interface_Category::operator new[], "None", py::arg("theSize"));
// cls_Interface_Category.def_static("operator delete[]_", (void (*)(void *)) &Interface_Category::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_Category.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_Category::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_Category.def_static("operator delete_", (void (*)(void *, void *)) &Interface_Category::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_Category.def("SetProtocol", (void (Interface_Category::*)(const opencascade::handle<Interface_Protocol> &)) &Interface_Category::SetProtocol, "Sets/Changes Protocol", py::arg("theProtocol"));
cls_Interface_Category.def("CatNum", (Standard_Integer (Interface_Category::*)(const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &)) &Interface_Category::CatNum, "Determines the Category Number for an entity in its context, by using general service CategoryNumber", py::arg("theEnt"), py::arg("theShares"));
cls_Interface_Category.def("ClearNums", (void (Interface_Category::*)()) &Interface_Category::ClearNums, "Clears the recorded list of category numbers for a Model");
cls_Interface_Category.def("Compute", (void (Interface_Category::*)(const opencascade::handle<Interface_InterfaceModel> &, const Interface_ShareTool &)) &Interface_Category::Compute, "Computes the Category Number for each entity and records it, in an array (ent.number -> category number) Hence, it can be queried by the method Num. The Model itself is not recorded, this method is intended to be used in a wider context (which detains also a Graph, etc)", py::arg("theModel"), py::arg("theShares"));
cls_Interface_Category.def("Num", (Standard_Integer (Interface_Category::*)(const Standard_Integer) const) &Interface_Category::Num, "Returns the category number recorded for an entity number Returns 0 if out of range", py::arg("theNumEnt"));
cls_Interface_Category.def_static("AddCategory_", (Standard_Integer (*)(const Standard_CString)) &Interface_Category::AddCategory, "Records a new Category defined by its names, produces a number New if not yet recorded", py::arg("theName"));
cls_Interface_Category.def_static("NbCategories_", (Standard_Integer (*)()) &Interface_Category::NbCategories, "Returns the count of recorded categories");
cls_Interface_Category.def_static("Name_", (Standard_CString (*)(const Standard_Integer)) &Interface_Category::Name, "Returns the name of a category, according to its number", py::arg("theNum"));
cls_Interface_Category.def_static("Number_", (Standard_Integer (*)(const Standard_CString)) &Interface_Category::Number, "Returns the number of a category, according to its name", py::arg("theName"));
cls_Interface_Category.def_static("Init_", (void (*)()) &Interface_Category::Init, "Default initialisation (protected against several calls : passes only once)");

// CLASS: INTERFACE_INTERFACEERROR
py::class_<Interface_InterfaceError, opencascade::handle<Interface_InterfaceError>, Standard_Failure> cls_Interface_InterfaceError(mod, "Interface_InterfaceError", "None");

// Constructors
cls_Interface_InterfaceError.def(py::init<>());
cls_Interface_InterfaceError.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Interface_InterfaceError.def_static("Raise_", (void (*)(const Standard_CString)) &Interface_InterfaceError::Raise, "None", py::arg("theMessage"));
cls_Interface_InterfaceError.def_static("Raise_", (void (*)(Standard_SStream &)) &Interface_InterfaceError::Raise, "None", py::arg("theMessage"));
cls_Interface_InterfaceError.def_static("NewInstance_", (opencascade::handle<Interface_InterfaceError> (*)(const Standard_CString)) &Interface_InterfaceError::NewInstance, "None", py::arg("theMessage"));
cls_Interface_InterfaceError.def_static("get_type_name_", (const char * (*)()) &Interface_InterfaceError::get_type_name, "None");
cls_Interface_InterfaceError.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_InterfaceError::get_type_descriptor, "None");
cls_Interface_InterfaceError.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_InterfaceError::*)() const) &Interface_InterfaceError::DynamicType, "None");

// CLASS: INTERFACE_CHECKFAILURE
py::class_<Interface_CheckFailure, opencascade::handle<Interface_CheckFailure>, Interface_InterfaceError> cls_Interface_CheckFailure(mod, "Interface_CheckFailure", "None");

// Constructors
cls_Interface_CheckFailure.def(py::init<>());
cls_Interface_CheckFailure.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Interface_CheckFailure.def_static("Raise_", (void (*)(const Standard_CString)) &Interface_CheckFailure::Raise, "None", py::arg("theMessage"));
cls_Interface_CheckFailure.def_static("Raise_", (void (*)(Standard_SStream &)) &Interface_CheckFailure::Raise, "None", py::arg("theMessage"));
cls_Interface_CheckFailure.def_static("NewInstance_", (opencascade::handle<Interface_CheckFailure> (*)(const Standard_CString)) &Interface_CheckFailure::NewInstance, "None", py::arg("theMessage"));
cls_Interface_CheckFailure.def_static("get_type_name_", (const char * (*)()) &Interface_CheckFailure::get_type_name, "None");
cls_Interface_CheckFailure.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_CheckFailure::get_type_descriptor, "None");
cls_Interface_CheckFailure.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_CheckFailure::*)() const) &Interface_CheckFailure::DynamicType, "None");

// CLASS: INTERFACE_SHARETOOL
py::class_<Interface_ShareTool> cls_Interface_ShareTool(mod, "Interface_ShareTool", "Builds the Graph of Dependancies, from the General Service 'Shared' -> builds for each Entity of a Model, the Shared and Sharing Lists, and gives access to them. Allows to complete with Implied References (which are not regarded as Shared Entities, but are nevertheless Referenced), this can be usefull for Reference Checking");

// Constructors
cls_Interface_ShareTool.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const Interface_GeneralLib &>(), py::arg("amodel"), py::arg("lib"));
cls_Interface_ShareTool.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_GTool> &>(), py::arg("amodel"), py::arg("gtool"));
cls_Interface_ShareTool.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &>(), py::arg("amodel"), py::arg("protocol"));
cls_Interface_ShareTool.def(py::init<const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("amodel"));
cls_Interface_ShareTool.def(py::init<const Interface_Graph &>(), py::arg("agraph"));
cls_Interface_ShareTool.def(py::init<const opencascade::handle<Interface_HGraph> &>(), py::arg("ahgraph"));

// Methods
// cls_Interface_ShareTool.def_static("operator new_", (void * (*)(size_t)) &Interface_ShareTool::operator new, "None", py::arg("theSize"));
// cls_Interface_ShareTool.def_static("operator delete_", (void (*)(void *)) &Interface_ShareTool::operator delete, "None", py::arg("theAddress"));
// cls_Interface_ShareTool.def_static("operator new[]_", (void * (*)(size_t)) &Interface_ShareTool::operator new[], "None", py::arg("theSize"));
// cls_Interface_ShareTool.def_static("operator delete[]_", (void (*)(void *)) &Interface_ShareTool::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_ShareTool.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_ShareTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_ShareTool.def_static("operator delete_", (void (*)(void *, void *)) &Interface_ShareTool::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_ShareTool.def("Model", (opencascade::handle<Interface_InterfaceModel> (Interface_ShareTool::*)() const) &Interface_ShareTool::Model, "Returns the Model used for Creation (directly or for Graph)");
cls_Interface_ShareTool.def("Graph", (const Interface_Graph & (Interface_ShareTool::*)() const) &Interface_ShareTool::Graph, "Returns the data used by the ShareTool to work Can then be used directly (read only)");
cls_Interface_ShareTool.def("RootEntities", (Interface_EntityIterator (Interface_ShareTool::*)() const) &Interface_ShareTool::RootEntities, "Returns the Entities which are not Shared (their Sharing List is empty) in the Model");
cls_Interface_ShareTool.def("IsShared", (Standard_Boolean (Interface_ShareTool::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_ShareTool::IsShared, "Returns True if <ent> is Shared by other Entities in the Model", py::arg("ent"));
cls_Interface_ShareTool.def("Shareds", (Interface_EntityIterator (Interface_ShareTool::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_ShareTool::Shareds, "Returns the List of Entities Shared by a given Entity <ent>", py::arg("ent"));
cls_Interface_ShareTool.def("Sharings", (Interface_EntityIterator (Interface_ShareTool::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_ShareTool::Sharings, "Returns the List of Entities Sharing a given Entity <ent>", py::arg("ent"));
cls_Interface_ShareTool.def("NbTypedSharings", (Standard_Integer (Interface_ShareTool::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Type> &) const) &Interface_ShareTool::NbTypedSharings, "Returns the count of Sharing Entities of an Entity, which are Kind of a given Type", py::arg("ent"), py::arg("atype"));
cls_Interface_ShareTool.def("TypedSharing", (opencascade::handle<Standard_Transient> (Interface_ShareTool::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Type> &) const) &Interface_ShareTool::TypedSharing, "Returns the Sharing Entity of an Entity, which is Kind of a given Type. Allows to access a Sharing Entity of a given type when there is one and only one (current case)", py::arg("ent"), py::arg("atype"));
cls_Interface_ShareTool.def("All", [](Interface_ShareTool &self, const opencascade::handle<Standard_Transient> & a0) -> Interface_EntityIterator { return self.All(a0); });
cls_Interface_ShareTool.def("All", (Interface_EntityIterator (Interface_ShareTool::*)(const opencascade::handle<Standard_Transient> &, const Standard_Boolean) const) &Interface_ShareTool::All, "Returns the complete list of entities shared by <ent> at any level, including <ent> itself If <ent> is the Model, considers the concatenation of AllShared for each root If <rootlast> is True (D), the list starts with lower level entities and ends by the root. Else, the root is first and the lower level entities are at end", py::arg("ent"), py::arg("rootlast"));
cls_Interface_ShareTool.def("Print", (void (Interface_ShareTool::*)(const Interface_EntityIterator &, const opencascade::handle<Message_Messenger> &) const) &Interface_ShareTool::Print, "Utility method which Prints the content of an iterator (by their Numbers)", py::arg("iter"), py::arg("S"));

// CLASS: INTERFACE_CHECKTOOL
py::class_<Interface_CheckTool> cls_Interface_CheckTool(mod, "Interface_CheckTool", "Performs Checks on Entities, using General Service Library and Modules to work. Works on one Entity or on a complete Model");

// Constructors
cls_Interface_CheckTool.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &>(), py::arg("model"), py::arg("protocol"));
cls_Interface_CheckTool.def(py::init<const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("model"));
cls_Interface_CheckTool.def(py::init<const Interface_Graph &>(), py::arg("graph"));
cls_Interface_CheckTool.def(py::init<const opencascade::handle<Interface_HGraph> &>(), py::arg("hgraph"));

// Methods
// cls_Interface_CheckTool.def_static("operator new_", (void * (*)(size_t)) &Interface_CheckTool::operator new, "None", py::arg("theSize"));
// cls_Interface_CheckTool.def_static("operator delete_", (void (*)(void *)) &Interface_CheckTool::operator delete, "None", py::arg("theAddress"));
// cls_Interface_CheckTool.def_static("operator new[]_", (void * (*)(size_t)) &Interface_CheckTool::operator new[], "None", py::arg("theSize"));
// cls_Interface_CheckTool.def_static("operator delete[]_", (void (*)(void *)) &Interface_CheckTool::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_CheckTool.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_CheckTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_CheckTool.def_static("operator delete_", (void (*)(void *, void *)) &Interface_CheckTool::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_CheckTool.def("FillCheck", (void (Interface_CheckTool::*)(const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &)) &Interface_CheckTool::FillCheck, "Fills as required a Check with the Error and Warning messages produced by Checking a given Entity. For an Erroneous or Corrected Entity : Check build at Analyse time; else, Check computed for Entity (Verify integrity), can use a Graph as required to control context", py::arg("ent"), py::arg("sh"), py::arg("ach"));
cls_Interface_CheckTool.def("Print", (void (Interface_CheckTool::*)(const opencascade::handle<Interface_Check> &, const opencascade::handle<Message_Messenger> &) const) &Interface_CheckTool::Print, "Utility method which Prints the content of a Check", py::arg("ach"), py::arg("S"));
cls_Interface_CheckTool.def("Print", (void (Interface_CheckTool::*)(const Interface_CheckIterator &, const opencascade::handle<Message_Messenger> &) const) &Interface_CheckTool::Print, "Simply Lists all the Checks and the Content (messages) and the Entity, if there is, of each Check (if all Checks are OK, nothing is Printed)", py::arg("list"), py::arg("S"));
cls_Interface_CheckTool.def("Check", (opencascade::handle<Interface_Check> (Interface_CheckTool::*)(const Standard_Integer)) &Interface_CheckTool::Check, "Returns the Check associated to an Entity identified by its Number in a Model.", py::arg("num"));
cls_Interface_CheckTool.def("CheckSuccess", [](Interface_CheckTool &self) -> void { return self.CheckSuccess(); });
cls_Interface_CheckTool.def("CheckSuccess", (void (Interface_CheckTool::*)(const Standard_Boolean)) &Interface_CheckTool::CheckSuccess, "Checks if any Error has been detected (CheckList not empty) Returns normally if none, raises exception if some exists. It reuses the last computations from other checking methods, unless the argument <resest> is given True", py::arg("reset"));
cls_Interface_CheckTool.def("CompleteCheckList", (Interface_CheckIterator (Interface_CheckTool::*)()) &Interface_CheckTool::CompleteCheckList, "Returns list of all 'remarkable' informations, which include : - GlobalCheck, if not empty - Error Checks, for all Errors (Verify + Analyse) - also Corrected Entities - and Unknown Entities : for those, each Unknown Entity is associated to an empty Check (it is neither an Error nor a Correction, but a remarkable information)");
cls_Interface_CheckTool.def("CheckList", (Interface_CheckIterator (Interface_CheckTool::*)()) &Interface_CheckTool::CheckList, "Returns list of all Errors detected Note that presence of Unknown Entities is not an error Cumulates : GlobalCheck if error + AnalyseCheckList + VerifyCheckList");
cls_Interface_CheckTool.def("AnalyseCheckList", (Interface_CheckIterator (Interface_CheckTool::*)()) &Interface_CheckTool::AnalyseCheckList, "Returns list of errors dectected at Analyse time (syntactic) (note that GlobalCheck is not in this list)");
cls_Interface_CheckTool.def("VerifyCheckList", (Interface_CheckIterator (Interface_CheckTool::*)()) &Interface_CheckTool::VerifyCheckList, "Returns list of integrity constraints errors (semantic) (note that GlobalCheck is not in this list)");
cls_Interface_CheckTool.def("WarningCheckList", (Interface_CheckIterator (Interface_CheckTool::*)()) &Interface_CheckTool::WarningCheckList, "Returns list of Corrections (includes GlobalCheck if corrected)");
cls_Interface_CheckTool.def("UnknownEntities", (Interface_EntityIterator (Interface_CheckTool::*)()) &Interface_CheckTool::UnknownEntities, "Returns list of Unknown Entities Note that Error and Erroneous Entities are not considered as Unknown");

// CLASS: INTERFACE_COPYCONTROL
py::class_<Interface_CopyControl, opencascade::handle<Interface_CopyControl>, Standard_Transient> cls_Interface_CopyControl(mod, "Interface_CopyControl", "This deferred class describes the services required by CopyTool to work. They are very simple and correspond basically to the management of an indexed map. But they can be provided by various classes which can control a Transfer. Each Starting Entity have at most one Result (Mapping one-one)");

// Methods
cls_Interface_CopyControl.def("Clear", (void (Interface_CopyControl::*)()) &Interface_CopyControl::Clear, "Clears List of Copy Results. Gets Ready to begin another Copy Process.");
cls_Interface_CopyControl.def("Bind", (void (Interface_CopyControl::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &)) &Interface_CopyControl::Bind, "Bind a Result to a Starting Entity identified by its Number", py::arg("ent"), py::arg("res"));
cls_Interface_CopyControl.def("Search", (Standard_Boolean (Interface_CopyControl::*)(const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &) const) &Interface_CopyControl::Search, "Searches for the Result bound to a Startingf Entity identified by its Number. If Found, returns True and fills <res> Else, returns False and nullifies <res>", py::arg("ent"), py::arg("res"));
cls_Interface_CopyControl.def_static("get_type_name_", (const char * (*)()) &Interface_CopyControl::get_type_name, "None");
cls_Interface_CopyControl.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_CopyControl::get_type_descriptor, "None");
cls_Interface_CopyControl.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_CopyControl::*)() const) &Interface_CopyControl::DynamicType, "None");

// CLASS: INTERFACE_COPYMAP
py::class_<Interface_CopyMap, opencascade::handle<Interface_CopyMap>, Interface_CopyControl> cls_Interface_CopyMap(mod, "Interface_CopyMap", "Manages a Map for the need of single Transfers, such as Copies In such transfer, Starting Entities are read from a unique Starting Model, and each transferred Entity is bound to one and only one Result, which cannot be changed later.");

// Constructors
cls_Interface_CopyMap.def(py::init<const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("amodel"));

// Methods
cls_Interface_CopyMap.def("Clear", (void (Interface_CopyMap::*)()) &Interface_CopyMap::Clear, "Clears Transfer List. Gets Ready to begin another Transfer");
cls_Interface_CopyMap.def("Model", (opencascade::handle<Interface_InterfaceModel> (Interface_CopyMap::*)() const) &Interface_CopyMap::Model, "Returns the InterfaceModel used at Creation time");
cls_Interface_CopyMap.def("Bind", (void (Interface_CopyMap::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &)) &Interface_CopyMap::Bind, "Binds a Starting Entity identified by its Number <num> in the Starting Model, to a Result of Transfer <res>", py::arg("ent"), py::arg("res"));
cls_Interface_CopyMap.def("Search", (Standard_Boolean (Interface_CopyMap::*)(const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &) const) &Interface_CopyMap::Search, "Search for the result of a Starting Object (i.e. an Entity, identified by its Number <num> in the Starting Model) Returns True if a Result is Bound (and fills <res>) Returns False if no result is Bound (and nullifies <res>)", py::arg("ent"), py::arg("res"));
cls_Interface_CopyMap.def_static("get_type_name_", (const char * (*)()) &Interface_CopyMap::get_type_name, "None");
cls_Interface_CopyMap.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_CopyMap::get_type_descriptor, "None");
cls_Interface_CopyMap.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_CopyMap::*)() const) &Interface_CopyMap::DynamicType, "None");

// CLASS: INTERFACE_COPYTOOL
py::class_<Interface_CopyTool> cls_Interface_CopyTool(mod, "Interface_CopyTool", "Performs Deep Copies of sets of Entities Allows to perform Copy of Interface Entities from a Model to another one. Works by calling general services GetFromAnother and GetImplied. Uses a CopyMap to bind a unique Result to each Copied Entity");

// Constructors
cls_Interface_CopyTool.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const Interface_GeneralLib &>(), py::arg("amodel"), py::arg("lib"));
cls_Interface_CopyTool.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &>(), py::arg("amodel"), py::arg("protocol"));
cls_Interface_CopyTool.def(py::init<const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("amodel"));

// Methods
// cls_Interface_CopyTool.def_static("operator new_", (void * (*)(size_t)) &Interface_CopyTool::operator new, "None", py::arg("theSize"));
// cls_Interface_CopyTool.def_static("operator delete_", (void (*)(void *)) &Interface_CopyTool::operator delete, "None", py::arg("theAddress"));
// cls_Interface_CopyTool.def_static("operator new[]_", (void * (*)(size_t)) &Interface_CopyTool::operator new[], "None", py::arg("theSize"));
// cls_Interface_CopyTool.def_static("operator delete[]_", (void (*)(void *)) &Interface_CopyTool::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_CopyTool.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_CopyTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_CopyTool.def_static("operator delete_", (void (*)(void *, void *)) &Interface_CopyTool::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_CopyTool.def("Model", (opencascade::handle<Interface_InterfaceModel> (Interface_CopyTool::*)() const) &Interface_CopyTool::Model, "Returns the Model on which the CopyTool works");
cls_Interface_CopyTool.def("SetControl", (void (Interface_CopyTool::*)(const opencascade::handle<Interface_CopyControl> &)) &Interface_CopyTool::SetControl, "Changes the Map of Result for another one. This allows to work with a more sophisticated Mapping Control than the Standard one which is CopyMap (e.g. TransferProcess from Transfer)", py::arg("othermap"));
cls_Interface_CopyTool.def("Control", (opencascade::handle<Interface_CopyControl> (Interface_CopyTool::*)() const) &Interface_CopyTool::Control, "Returns the object used for Control");
cls_Interface_CopyTool.def("Clear", (void (Interface_CopyTool::*)()) &Interface_CopyTool::Clear, "Clears Transfer List. Gets Ready to begin another Transfer");
cls_Interface_CopyTool.def("Copy", (Standard_Boolean (Interface_CopyTool::*)(const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &, const Standard_Boolean, const Standard_Boolean)) &Interface_CopyTool::Copy, "Creates the CounterPart of an Entity (by ShallowCopy), Binds it, then Copies the content of the former Entity to the other one (same Type), by call to the General Service Library It may command the Copy of Referenced Entities Then, its returns True.", py::arg("entfrom"), py::arg("entto"), py::arg("mapped"), py::arg("errstat"));
cls_Interface_CopyTool.def("Transferred", (opencascade::handle<Standard_Transient> (Interface_CopyTool::*)(const opencascade::handle<Standard_Transient> &)) &Interface_CopyTool::Transferred, "Transfers one Entity, if not yet bound to a result Remark : For an Entity which is reported in the Starting Model, the ReportEntity will also be copied with its Content if it has one (at least ShallowCopy; Complete Copy if the Protocol recognizes the Content : see method Copy)", py::arg("ent"));
cls_Interface_CopyTool.def("Bind", (void (Interface_CopyTool::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &)) &Interface_CopyTool::Bind, "Defines a Result for the Transfer of a Starting object. Used by method Transferred (which performs a normal Copy), but can also be called to enforce a result : in the latter case, the enforced result must be compatible with the other Transfers which are performed", py::arg("ent"), py::arg("res"));
cls_Interface_CopyTool.def("Search", (Standard_Boolean (Interface_CopyTool::*)(const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &) const) &Interface_CopyTool::Search, "Search for the result of a Starting Object (i.e. an Entity) Returns True if a Result is Bound (and fills 'result') Returns False if no result is Bound", py::arg("ent"), py::arg("res"));
cls_Interface_CopyTool.def("ClearLastFlags", (void (Interface_CopyTool::*)()) &Interface_CopyTool::ClearLastFlags, "Clears LastFlags only. This allows to know what Entities are copied after its call (see method LastCopiedAfter). It can be used when copies are done by increments, which must be distinghished. ClearLastFlags is also called by Clear.");
cls_Interface_CopyTool.def("LastCopiedAfter", (Standard_Integer (Interface_CopyTool::*)(const Standard_Integer, opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &) const) &Interface_CopyTool::LastCopiedAfter, "Returns an copied Entity and its Result which were operated after last call to ClearLastFlags. It returns the first 'Last Copied Entity' which Number follows <numfrom>, Zero if none. It is used in a loop as follow : Integer num = 0; while ( (num = CopyTool.LastCopiedAfter(num,ent,res)) ) { .. Process Starting <ent> and its Result <res> }", py::arg("numfrom"), py::arg("ent"), py::arg("res"));
cls_Interface_CopyTool.def("TransferEntity", (void (Interface_CopyTool::*)(const opencascade::handle<Standard_Transient> &)) &Interface_CopyTool::TransferEntity, "Transfers one Entity and records result into the Transfer List Calls method Transferred", py::arg("ent"));
cls_Interface_CopyTool.def("RenewImpliedRefs", (void (Interface_CopyTool::*)()) &Interface_CopyTool::RenewImpliedRefs, "Renews the Implied References. These References do not involve Copying of referenced Entities. For such a Reference, if the Entity which defines it AND the referenced Entity are both copied, then this Reference is renewed. Else it is deleted in the copied Entities. Remark : this concerns only some specific references, such as 'back pointers'.");
cls_Interface_CopyTool.def("FillModel", (void (Interface_CopyTool::*)(const opencascade::handle<Interface_InterfaceModel> &)) &Interface_CopyTool::FillModel, "Fills a Model with the result of the transfer (TransferList) Commands copy of Header too, and calls RenewImpliedRefs", py::arg("bmodel"));
cls_Interface_CopyTool.def("CompleteResult", [](Interface_CopyTool &self) -> Interface_EntityIterator { return self.CompleteResult(); });
cls_Interface_CopyTool.def("CompleteResult", (Interface_EntityIterator (Interface_CopyTool::*)(const Standard_Boolean) const) &Interface_CopyTool::CompleteResult, "Returns the complete list of copied Entities If <withreports> is given True, the entities which were reported in the Starting Model are replaced in the list by the copied ReportEntities", py::arg("withreports"));
cls_Interface_CopyTool.def("RootResult", [](Interface_CopyTool &self) -> Interface_EntityIterator { return self.RootResult(); });
cls_Interface_CopyTool.def("RootResult", (Interface_EntityIterator (Interface_CopyTool::*)(const Standard_Boolean) const) &Interface_CopyTool::RootResult, "Returns the list of Root copied Entities (those which were asked for copy by the user of CopyTool, not by copying another Entity)", py::arg("withreports"));

// CLASS: INTERFACE_ENTITYCLUSTER
py::class_<Interface_EntityCluster, opencascade::handle<Interface_EntityCluster>, Standard_Transient> cls_Interface_EntityCluster(mod, "Interface_EntityCluster", "Auxiliary class for EntityList. An EntityList designates an EntityCluster, which brings itself an fixed maximum count of Entities. If it is full, it gives access to another cluster ('Next'). This class is intended to give a good compromise between access time (faster than a Sequence, good for little count) and memory use (better than a Sequence in any case, overall for little count, better than an Array for a very little count. It is designed for a light management. Remark that a new Item may not be Null, because this is the criterium used for 'End of List'");

// Constructors
cls_Interface_EntityCluster.def(py::init<>());
cls_Interface_EntityCluster.def(py::init<const opencascade::handle<Standard_Transient> &>(), py::arg("ent"));
cls_Interface_EntityCluster.def(py::init<const opencascade::handle<Interface_EntityCluster> &>(), py::arg("ec"));
cls_Interface_EntityCluster.def(py::init<const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_EntityCluster> &>(), py::arg("ant"), py::arg("ec"));

// Methods
cls_Interface_EntityCluster.def("Append", (void (Interface_EntityCluster::*)(const opencascade::handle<Standard_Transient> &)) &Interface_EntityCluster::Append, "Appends an Entity to the Cluster. If it is not full, adds the entity directly inside itself. Else, transmits to its Next and Creates it if it does not yet exist", py::arg("ent"));
cls_Interface_EntityCluster.def("Remove", (Standard_Boolean (Interface_EntityCluster::*)(const opencascade::handle<Standard_Transient> &)) &Interface_EntityCluster::Remove, "Removes an Entity from the Cluster. If it is not found, calls its Next one to do so. Returns True if it becomes itself empty, False else (thus, a Cluster which becomes empty is deleted from the list)", py::arg("ent"));
cls_Interface_EntityCluster.def("Remove", (Standard_Boolean (Interface_EntityCluster::*)(const Standard_Integer)) &Interface_EntityCluster::Remove, "Removes an Entity from the Cluster, given its rank. If <num> is greater than NbLocal, calls its Next with (num - NbLocal), Returns True if it becomes itself empty, False else", py::arg("num"));
cls_Interface_EntityCluster.def("NbEntities", (Standard_Integer (Interface_EntityCluster::*)() const) &Interface_EntityCluster::NbEntities, "Returns total count of Entities (including Next)");
cls_Interface_EntityCluster.def("Value", (const opencascade::handle<Standard_Transient> & (Interface_EntityCluster::*)(const Standard_Integer) const) &Interface_EntityCluster::Value, "Returns the Entity identified by its rank in the list (including Next)", py::arg("num"));
cls_Interface_EntityCluster.def("SetValue", (void (Interface_EntityCluster::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &)) &Interface_EntityCluster::SetValue, "Changes an Entity given its rank.", py::arg("num"), py::arg("ent"));
cls_Interface_EntityCluster.def("FillIterator", (void (Interface_EntityCluster::*)(Interface_EntityIterator &) const) &Interface_EntityCluster::FillIterator, "Fills an Iterator with designated Entities (includes Next)", py::arg("iter"));
cls_Interface_EntityCluster.def_static("get_type_name_", (const char * (*)()) &Interface_EntityCluster::get_type_name, "None");
cls_Interface_EntityCluster.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_EntityCluster::get_type_descriptor, "None");
cls_Interface_EntityCluster.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_EntityCluster::*)() const) &Interface_EntityCluster::DynamicType, "None");

// CLASS: INTERFACE_GLOBALNODEOFGENERALLIB
py::class_<Interface_GlobalNodeOfGeneralLib, opencascade::handle<Interface_GlobalNodeOfGeneralLib>, Standard_Transient> cls_Interface_GlobalNodeOfGeneralLib(mod, "Interface_GlobalNodeOfGeneralLib", "None");

// Constructors
cls_Interface_GlobalNodeOfGeneralLib.def(py::init<>());

// Methods
cls_Interface_GlobalNodeOfGeneralLib.def("Add", (void (Interface_GlobalNodeOfGeneralLib::*)(const opencascade::handle<Interface_GeneralModule> &, const opencascade::handle<Interface_Protocol> &)) &Interface_GlobalNodeOfGeneralLib::Add, "Adds a Module bound with a Protocol to the list : does nothing if already in the list, THAT IS, Same Type (exact match) and Same State (that is, IsEqual is not required) Once added, stores its attached Protocol in correspondance", py::arg("amodule"), py::arg("aprotocol"));
cls_Interface_GlobalNodeOfGeneralLib.def("Module", (const opencascade::handle<Interface_GeneralModule> & (Interface_GlobalNodeOfGeneralLib::*)() const) &Interface_GlobalNodeOfGeneralLib::Module, "Returns the Module stored in a given GlobalNode");
cls_Interface_GlobalNodeOfGeneralLib.def("Protocol", (const opencascade::handle<Interface_Protocol> & (Interface_GlobalNodeOfGeneralLib::*)() const) &Interface_GlobalNodeOfGeneralLib::Protocol, "Returns the attached Protocol stored in a given GlobalNode");
cls_Interface_GlobalNodeOfGeneralLib.def("Next", (const opencascade::handle<Interface_GlobalNodeOfGeneralLib> & (Interface_GlobalNodeOfGeneralLib::*)() const) &Interface_GlobalNodeOfGeneralLib::Next, "Returns the Next GlobalNode. If none is defined, returned value is a Null Handle");
cls_Interface_GlobalNodeOfGeneralLib.def_static("get_type_name_", (const char * (*)()) &Interface_GlobalNodeOfGeneralLib::get_type_name, "None");
cls_Interface_GlobalNodeOfGeneralLib.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_GlobalNodeOfGeneralLib::get_type_descriptor, "None");
cls_Interface_GlobalNodeOfGeneralLib.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_GlobalNodeOfGeneralLib::*)() const) &Interface_GlobalNodeOfGeneralLib::DynamicType, "None");

// CLASS: INTERFACE_GLOBALNODEOFREADERLIB
py::class_<Interface_GlobalNodeOfReaderLib, opencascade::handle<Interface_GlobalNodeOfReaderLib>, Standard_Transient> cls_Interface_GlobalNodeOfReaderLib(mod, "Interface_GlobalNodeOfReaderLib", "None");

// Constructors
cls_Interface_GlobalNodeOfReaderLib.def(py::init<>());

// Methods
cls_Interface_GlobalNodeOfReaderLib.def("Add", (void (Interface_GlobalNodeOfReaderLib::*)(const opencascade::handle<Interface_ReaderModule> &, const opencascade::handle<Interface_Protocol> &)) &Interface_GlobalNodeOfReaderLib::Add, "Adds a Module bound with a Protocol to the list : does nothing if already in the list, THAT IS, Same Type (exact match) and Same State (that is, IsEqual is not required) Once added, stores its attached Protocol in correspondance", py::arg("amodule"), py::arg("aprotocol"));
cls_Interface_GlobalNodeOfReaderLib.def("Module", (const opencascade::handle<Interface_ReaderModule> & (Interface_GlobalNodeOfReaderLib::*)() const) &Interface_GlobalNodeOfReaderLib::Module, "Returns the Module stored in a given GlobalNode");
cls_Interface_GlobalNodeOfReaderLib.def("Protocol", (const opencascade::handle<Interface_Protocol> & (Interface_GlobalNodeOfReaderLib::*)() const) &Interface_GlobalNodeOfReaderLib::Protocol, "Returns the attached Protocol stored in a given GlobalNode");
cls_Interface_GlobalNodeOfReaderLib.def("Next", (const opencascade::handle<Interface_GlobalNodeOfReaderLib> & (Interface_GlobalNodeOfReaderLib::*)() const) &Interface_GlobalNodeOfReaderLib::Next, "Returns the Next GlobalNode. If none is defined, returned value is a Null Handle");
cls_Interface_GlobalNodeOfReaderLib.def_static("get_type_name_", (const char * (*)()) &Interface_GlobalNodeOfReaderLib::get_type_name, "None");
cls_Interface_GlobalNodeOfReaderLib.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_GlobalNodeOfReaderLib::get_type_descriptor, "None");
cls_Interface_GlobalNodeOfReaderLib.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_GlobalNodeOfReaderLib::*)() const) &Interface_GlobalNodeOfReaderLib::DynamicType, "None");

// CLASS: INTERFACE_HGRAPH
py::class_<Interface_HGraph, opencascade::handle<Interface_HGraph>, Standard_Transient> cls_Interface_HGraph(mod, "Interface_HGraph", "This class allows to store a redefinable Graph, via a Handle (usefull for an Object which can work on several successive Models, with the same general conditions)");

// Constructors
cls_Interface_HGraph.def(py::init<const Interface_Graph &>(), py::arg("agraph"));
cls_Interface_HGraph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const Interface_GeneralLib &>(), py::arg("amodel"), py::arg("lib"));
cls_Interface_HGraph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const Interface_GeneralLib &, const Standard_Boolean>(), py::arg("amodel"), py::arg("lib"), py::arg("theModeStats"));
cls_Interface_HGraph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &>(), py::arg("amodel"), py::arg("protocol"));
cls_Interface_HGraph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &, const Standard_Boolean>(), py::arg("amodel"), py::arg("protocol"), py::arg("theModeStats"));
cls_Interface_HGraph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_GTool> &>(), py::arg("amodel"), py::arg("gtool"));
cls_Interface_HGraph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_GTool> &, const Standard_Boolean>(), py::arg("amodel"), py::arg("gtool"), py::arg("theModeStats"));
cls_Interface_HGraph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("amodel"));
cls_Interface_HGraph.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const Standard_Boolean>(), py::arg("amodel"), py::arg("theModeStats"));

// Methods
cls_Interface_HGraph.def("Graph", (const Interface_Graph & (Interface_HGraph::*)() const) &Interface_HGraph::Graph, "Returns the Graph contained in <me>, for Read Only Operations Remark that it is returns as 'const &' Getting it in a new variable instead of a reference would be a pitty, because all the graph's content would be duplicated");
cls_Interface_HGraph.def("CGraph", (Interface_Graph & (Interface_HGraph::*)()) &Interface_HGraph::CGraph, "Same as above, but for Read-Write Operations Then, The Graph will be modified in the HGraph itself");
cls_Interface_HGraph.def_static("get_type_name_", (const char * (*)()) &Interface_HGraph::get_type_name, "None");
cls_Interface_HGraph.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_HGraph::get_type_descriptor, "None");
cls_Interface_HGraph.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_HGraph::*)() const) &Interface_HGraph::DynamicType, "None");

// CLASS: INTERFACE_MAPASCIISTRINGHASHER
py::class_<Interface_MapAsciiStringHasher> cls_Interface_MapAsciiStringHasher(mod, "Interface_MapAsciiStringHasher", "None");

// Methods
// cls_Interface_MapAsciiStringHasher.def_static("operator new_", (void * (*)(size_t)) &Interface_MapAsciiStringHasher::operator new, "None", py::arg("theSize"));
// cls_Interface_MapAsciiStringHasher.def_static("operator delete_", (void (*)(void *)) &Interface_MapAsciiStringHasher::operator delete, "None", py::arg("theAddress"));
// cls_Interface_MapAsciiStringHasher.def_static("operator new[]_", (void * (*)(size_t)) &Interface_MapAsciiStringHasher::operator new[], "None", py::arg("theSize"));
// cls_Interface_MapAsciiStringHasher.def_static("operator delete[]_", (void (*)(void *)) &Interface_MapAsciiStringHasher::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_MapAsciiStringHasher.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_MapAsciiStringHasher::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_MapAsciiStringHasher.def_static("operator delete_", (void (*)(void *, void *)) &Interface_MapAsciiStringHasher::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_MapAsciiStringHasher.def_static("HashCode_", (Standard_Integer (*)(const TCollection_AsciiString &, Standard_Integer)) &Interface_MapAsciiStringHasher::HashCode, "Computes a hash code for the given ASCII string, in the range [1, theUpperBound]", py::arg("theAsciiString"), py::arg("theUpperBound"));
cls_Interface_MapAsciiStringHasher.def_static("IsEqual_", (Standard_Boolean (*)(const TCollection_AsciiString &, const TCollection_AsciiString &)) &Interface_MapAsciiStringHasher::IsEqual, "None", py::arg("K1"), py::arg("K2"));

// TYPEDEF: INTERFACE_INDEXEDMAPOFASCIISTRING
bind_NCollection_IndexedMap<TCollection_AsciiString, Interface_MapAsciiStringHasher>(mod, "Interface_IndexedMapOfAsciiString", py::module_local(false));

// CLASS: INTERFACE_INTERFACEMISMATCH
py::class_<Interface_InterfaceMismatch, opencascade::handle<Interface_InterfaceMismatch>, Interface_InterfaceError> cls_Interface_InterfaceMismatch(mod, "Interface_InterfaceMismatch", "None");

// Constructors
cls_Interface_InterfaceMismatch.def(py::init<>());
cls_Interface_InterfaceMismatch.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Interface_InterfaceMismatch.def_static("Raise_", (void (*)(const Standard_CString)) &Interface_InterfaceMismatch::Raise, "None", py::arg("theMessage"));
cls_Interface_InterfaceMismatch.def_static("Raise_", (void (*)(Standard_SStream &)) &Interface_InterfaceMismatch::Raise, "None", py::arg("theMessage"));
cls_Interface_InterfaceMismatch.def_static("NewInstance_", (opencascade::handle<Interface_InterfaceMismatch> (*)(const Standard_CString)) &Interface_InterfaceMismatch::NewInstance, "None", py::arg("theMessage"));
cls_Interface_InterfaceMismatch.def_static("get_type_name_", (const char * (*)()) &Interface_InterfaceMismatch::get_type_name, "None");
cls_Interface_InterfaceMismatch.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_InterfaceMismatch::get_type_descriptor, "None");
cls_Interface_InterfaceMismatch.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_InterfaceMismatch::*)() const) &Interface_InterfaceMismatch::DynamicType, "None");

// CLASS: INTERFACE_INTVAL
py::class_<Interface_IntVal, opencascade::handle<Interface_IntVal>, Standard_Transient> cls_Interface_IntVal(mod, "Interface_IntVal", "An Integer through a Handle (i.e. managed as TShared)");

// Constructors
cls_Interface_IntVal.def(py::init<>());

// Methods
cls_Interface_IntVal.def("Value", (Standard_Integer (Interface_IntVal::*)() const) &Interface_IntVal::Value, "None");
cls_Interface_IntVal.def("CValue", (Standard_Integer & (Interface_IntVal::*)()) &Interface_IntVal::CValue, "None");
cls_Interface_IntVal.def_static("get_type_name_", (const char * (*)()) &Interface_IntVal::get_type_name, "None");
cls_Interface_IntVal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_IntVal::get_type_descriptor, "None");
cls_Interface_IntVal.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_IntVal::*)() const) &Interface_IntVal::DynamicType, "None");

// CLASS: INTERFACE_NODEOFGENERALLIB
py::class_<Interface_NodeOfGeneralLib, opencascade::handle<Interface_NodeOfGeneralLib>, Standard_Transient> cls_Interface_NodeOfGeneralLib(mod, "Interface_NodeOfGeneralLib", "None");

// Constructors
cls_Interface_NodeOfGeneralLib.def(py::init<>());

// Methods
cls_Interface_NodeOfGeneralLib.def("AddNode", (void (Interface_NodeOfGeneralLib::*)(const opencascade::handle<Interface_GlobalNodeOfGeneralLib> &)) &Interface_NodeOfGeneralLib::AddNode, "Adds a couple (Module,Protocol), that is, stores it into itself if not yet done, else creates a Next Node to do it", py::arg("anode"));
cls_Interface_NodeOfGeneralLib.def("Module", (const opencascade::handle<Interface_GeneralModule> & (Interface_NodeOfGeneralLib::*)() const) &Interface_NodeOfGeneralLib::Module, "Returns the Module designated by a precise Node");
cls_Interface_NodeOfGeneralLib.def("Protocol", (const opencascade::handle<Interface_Protocol> & (Interface_NodeOfGeneralLib::*)() const) &Interface_NodeOfGeneralLib::Protocol, "Returns the Protocol designated by a precise Node");
cls_Interface_NodeOfGeneralLib.def("Next", (const opencascade::handle<Interface_NodeOfGeneralLib> & (Interface_NodeOfGeneralLib::*)() const) &Interface_NodeOfGeneralLib::Next, "Returns the Next Node. If none was defined, returned value is a Null Handle");
cls_Interface_NodeOfGeneralLib.def_static("get_type_name_", (const char * (*)()) &Interface_NodeOfGeneralLib::get_type_name, "None");
cls_Interface_NodeOfGeneralLib.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_NodeOfGeneralLib::get_type_descriptor, "None");
cls_Interface_NodeOfGeneralLib.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_NodeOfGeneralLib::*)() const) &Interface_NodeOfGeneralLib::DynamicType, "None");

// CLASS: INTERFACE_NODEOFREADERLIB
py::class_<Interface_NodeOfReaderLib, opencascade::handle<Interface_NodeOfReaderLib>, Standard_Transient> cls_Interface_NodeOfReaderLib(mod, "Interface_NodeOfReaderLib", "None");

// Constructors
cls_Interface_NodeOfReaderLib.def(py::init<>());

// Methods
cls_Interface_NodeOfReaderLib.def("AddNode", (void (Interface_NodeOfReaderLib::*)(const opencascade::handle<Interface_GlobalNodeOfReaderLib> &)) &Interface_NodeOfReaderLib::AddNode, "Adds a couple (Module,Protocol), that is, stores it into itself if not yet done, else creates a Next Node to do it", py::arg("anode"));
cls_Interface_NodeOfReaderLib.def("Module", (const opencascade::handle<Interface_ReaderModule> & (Interface_NodeOfReaderLib::*)() const) &Interface_NodeOfReaderLib::Module, "Returns the Module designated by a precise Node");
cls_Interface_NodeOfReaderLib.def("Protocol", (const opencascade::handle<Interface_Protocol> & (Interface_NodeOfReaderLib::*)() const) &Interface_NodeOfReaderLib::Protocol, "Returns the Protocol designated by a precise Node");
cls_Interface_NodeOfReaderLib.def("Next", (const opencascade::handle<Interface_NodeOfReaderLib> & (Interface_NodeOfReaderLib::*)() const) &Interface_NodeOfReaderLib::Next, "Returns the Next Node. If none was defined, returned value is a Null Handle");
cls_Interface_NodeOfReaderLib.def_static("get_type_name_", (const char * (*)()) &Interface_NodeOfReaderLib::get_type_name, "None");
cls_Interface_NodeOfReaderLib.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_NodeOfReaderLib::get_type_descriptor, "None");
cls_Interface_NodeOfReaderLib.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_NodeOfReaderLib::*)() const) &Interface_NodeOfReaderLib::DynamicType, "None");

// TYPEDEF: INTERFACE_VECTOROFFILEPARAMETER
bind_NCollection_Vector<Interface_FileParameter>(mod, "Interface_VectorOfFileParameter", py::module_local(false));

// CLASS: INTERFACE_PARAMLIST
py::class_<Interface_ParamList, opencascade::handle<Interface_ParamList>, Standard_Transient> cls_Interface_ParamList(mod, "Interface_ParamList", "None");

// Constructors
cls_Interface_ParamList.def(py::init<>());
cls_Interface_ParamList.def(py::init<const Standard_Integer>(), py::arg("theIncrement"));

// Methods
cls_Interface_ParamList.def("Length", (Standard_Integer (Interface_ParamList::*)() const) &Interface_ParamList::Length, "Returns the number of elements of <me>.");
cls_Interface_ParamList.def("Lower", (Standard_Integer (Interface_ParamList::*)() const) &Interface_ParamList::Lower, "Returns the lower bound. Warning");
cls_Interface_ParamList.def("Upper", (Standard_Integer (Interface_ParamList::*)() const) &Interface_ParamList::Upper, "Returns the upper bound. Warning");
cls_Interface_ParamList.def("SetValue", (void (Interface_ParamList::*)(const Standard_Integer, const Interface_FileParameter &)) &Interface_ParamList::SetValue, "Assigns the value <Value> to the <Index>-th item of this array.", py::arg("Index"), py::arg("Value"));
cls_Interface_ParamList.def("Value", (const Interface_FileParameter & (Interface_ParamList::*)(const Standard_Integer) const) &Interface_ParamList::Value, "Return the value of the <Index>th element of the array.", py::arg("Index"));
cls_Interface_ParamList.def("__call__", (const Interface_FileParameter & (Interface_ParamList::*)(const Standard_Integer) const) &Interface_ParamList::operator(), py::is_operator(), "None", py::arg("Index"));
cls_Interface_ParamList.def("ChangeValue", (Interface_FileParameter & (Interface_ParamList::*)(const Standard_Integer)) &Interface_ParamList::ChangeValue, "return the value of the <Index>th element of the array.", py::arg("Index"));
cls_Interface_ParamList.def("__call__", (Interface_FileParameter & (Interface_ParamList::*)(const Standard_Integer)) &Interface_ParamList::operator(), py::is_operator(), "None", py::arg("Index"));
cls_Interface_ParamList.def("Clear", (void (Interface_ParamList::*)()) &Interface_ParamList::Clear, "None");
cls_Interface_ParamList.def_static("get_type_name_", (const char * (*)()) &Interface_ParamList::get_type_name, "None");
cls_Interface_ParamList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_ParamList::get_type_descriptor, "None");
cls_Interface_ParamList.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_ParamList::*)() const) &Interface_ParamList::DynamicType, "None");

// CLASS: INTERFACE_PARAMSET
py::class_<Interface_ParamSet, opencascade::handle<Interface_ParamSet>, Standard_Transient> cls_Interface_ParamSet(mod, "Interface_ParamSet", "Defines an ordered set of FileParameters, in a way to be efficient as in memory requirement or in speed");

// Constructors
cls_Interface_ParamSet.def(py::init<const Standard_Integer>(), py::arg("nres"));
cls_Interface_ParamSet.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("nres"), py::arg("nst"));

// Methods
cls_Interface_ParamSet.def("Append", (Standard_Integer (Interface_ParamSet::*)(const Standard_CString, const Standard_Integer, const Interface_ParamType, const Standard_Integer)) &Interface_ParamSet::Append, "Adds a parameter defined as its Value (CString and length) and Type. Optionnal EntityNumber (for FileReaderData) can be given Allows a better memory management than Appending a complete FileParameter If <lnval> < 0, <val> is assumed to be managed elsewhere : its adress is stored as such. Else, <val> is copied in a locally (quickly) managed Page of Characters Returns new count of recorded Parameters", py::arg("val"), py::arg("lnval"), py::arg("typ"), py::arg("nument"));
cls_Interface_ParamSet.def("Append", (Standard_Integer (Interface_ParamSet::*)(const Interface_FileParameter &)) &Interface_ParamSet::Append, "Adds a parameter at the end of the ParamSet (transparent about reservation and 'Next') Returns new count of recorded Parameters", py::arg("FP"));
cls_Interface_ParamSet.def("NbParams", (Standard_Integer (Interface_ParamSet::*)() const) &Interface_ParamSet::NbParams, "Returns the total count of parameters (including nexts)");
cls_Interface_ParamSet.def("Param", (const Interface_FileParameter & (Interface_ParamSet::*)(const Standard_Integer) const) &Interface_ParamSet::Param, "Returns a parameter identified by its number", py::arg("num"));
cls_Interface_ParamSet.def("ChangeParam", (Interface_FileParameter & (Interface_ParamSet::*)(const Standard_Integer)) &Interface_ParamSet::ChangeParam, "Same as above, but in order to be modified on place", py::arg("num"));
cls_Interface_ParamSet.def("SetParam", (void (Interface_ParamSet::*)(const Standard_Integer, const Interface_FileParameter &)) &Interface_ParamSet::SetParam, "Changes a parameter identified by its number", py::arg("num"), py::arg("FP"));
cls_Interface_ParamSet.def("Params", (opencascade::handle<Interface_ParamList> (Interface_ParamSet::*)(const Standard_Integer, const Standard_Integer) const) &Interface_ParamSet::Params, "Builds and returns the sub-list correspinding to parameters, from 'num' included, with count 'nb' If <num> and <nb> are zero, returns the whole list", py::arg("num"), py::arg("nb"));
cls_Interface_ParamSet.def("Destroy", (void (Interface_ParamSet::*)()) &Interface_ParamSet::Destroy, "Destructor (waiting for transparent memory management)");
cls_Interface_ParamSet.def_static("get_type_name_", (const char * (*)()) &Interface_ParamSet::get_type_name, "None");
cls_Interface_ParamSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_ParamSet::get_type_descriptor, "None");
cls_Interface_ParamSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_ParamSet::*)() const) &Interface_ParamSet::DynamicType, "None");

// CLASS: INTERFACE_REPORTENTITY
py::class_<Interface_ReportEntity, opencascade::handle<Interface_ReportEntity>, Standard_Transient> cls_Interface_ReportEntity(mod, "Interface_ReportEntity", "A ReportEntity is produced to aknowledge and memorize the binding between a Check and an Entity. The Check can bring Fails (+ Warnings if any), or only Warnings. If it is empty, the Report Entity is for an Unknown Entity.");

// Constructors
cls_Interface_ReportEntity.def(py::init<const opencascade::handle<Standard_Transient> &>(), py::arg("unknown"));
cls_Interface_ReportEntity.def(py::init<const opencascade::handle<Interface_Check> &, const opencascade::handle<Standard_Transient> &>(), py::arg("acheck"), py::arg("concerned"));

// Methods
cls_Interface_ReportEntity.def("SetContent", (void (Interface_ReportEntity::*)(const opencascade::handle<Standard_Transient> &)) &Interface_ReportEntity::SetContent, "Sets a Content : it brings non interpreted data which belong to the Concerned Entity. It can be empty then loaded later. Remark that for an Unknown Entity, Content is set by Create.", py::arg("content"));
cls_Interface_ReportEntity.def("Check", (const opencascade::handle<Interface_Check> & (Interface_ReportEntity::*)() const) &Interface_ReportEntity::Check, "Returns the stored Check");
cls_Interface_ReportEntity.def("CCheck", (opencascade::handle<Interface_Check> & (Interface_ReportEntity::*)()) &Interface_ReportEntity::CCheck, "Returns the stored Check in order to change it");
cls_Interface_ReportEntity.def("Concerned", (opencascade::handle<Standard_Transient> (Interface_ReportEntity::*)() const) &Interface_ReportEntity::Concerned, "Returns the stored Concerned Entity. It equates the Content in the case of an Unknown Entity");
cls_Interface_ReportEntity.def("HasContent", (Standard_Boolean (Interface_ReportEntity::*)() const) &Interface_ReportEntity::HasContent, "Returns True if a Content is stored (it can equate Concerned)");
cls_Interface_ReportEntity.def("HasNewContent", (Standard_Boolean (Interface_ReportEntity::*)() const) &Interface_ReportEntity::HasNewContent, "Returns True if a Content is stored AND differs from Concerned (i.e. redefines content) : used when Concerned could not be loaded");
cls_Interface_ReportEntity.def("Content", (opencascade::handle<Standard_Transient> (Interface_ReportEntity::*)() const) &Interface_ReportEntity::Content, "Returns the stored Content, or a Null Handle Remark that it must be an 'Unknown Entity' suitable for the norm of the containing Model");
cls_Interface_ReportEntity.def("IsError", (Standard_Boolean (Interface_ReportEntity::*)() const) &Interface_ReportEntity::IsError, "Returns True for an Error Entity, i.e. if the Check brings at least one Fail message");
cls_Interface_ReportEntity.def("IsUnknown", (Standard_Boolean (Interface_ReportEntity::*)() const) &Interface_ReportEntity::IsUnknown, "Returns True for an Unknown Entity, i,e. if the Check is empty and Concerned equates Content");
cls_Interface_ReportEntity.def_static("get_type_name_", (const char * (*)()) &Interface_ReportEntity::get_type_name, "None");
cls_Interface_ReportEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_ReportEntity::get_type_descriptor, "None");
cls_Interface_ReportEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_ReportEntity::*)() const) &Interface_ReportEntity::DynamicType, "None");

// CLASS: INTERFACE_SHAREFLAGS
py::class_<Interface_ShareFlags> cls_Interface_ShareFlags(mod, "Interface_ShareFlags", "This class only says for each Entity of a Model, if it is Shared or not by one or more other(s) of this Model It uses the General Service 'Shared'.");

// Constructors
cls_Interface_ShareFlags.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const Interface_GeneralLib &>(), py::arg("amodel"), py::arg("lib"));
cls_Interface_ShareFlags.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_GTool> &>(), py::arg("amodel"), py::arg("gtool"));
cls_Interface_ShareFlags.def(py::init<const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &>(), py::arg("amodel"), py::arg("protocol"));
cls_Interface_ShareFlags.def(py::init<const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("amodel"));
cls_Interface_ShareFlags.def(py::init<const Interface_Graph &>(), py::arg("agraph"));

// Methods
// cls_Interface_ShareFlags.def_static("operator new_", (void * (*)(size_t)) &Interface_ShareFlags::operator new, "None", py::arg("theSize"));
// cls_Interface_ShareFlags.def_static("operator delete_", (void (*)(void *)) &Interface_ShareFlags::operator delete, "None", py::arg("theAddress"));
// cls_Interface_ShareFlags.def_static("operator new[]_", (void * (*)(size_t)) &Interface_ShareFlags::operator new[], "None", py::arg("theSize"));
// cls_Interface_ShareFlags.def_static("operator delete[]_", (void (*)(void *)) &Interface_ShareFlags::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_ShareFlags.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_ShareFlags::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_ShareFlags.def_static("operator delete_", (void (*)(void *, void *)) &Interface_ShareFlags::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_ShareFlags.def("Model", (opencascade::handle<Interface_InterfaceModel> (Interface_ShareFlags::*)() const) &Interface_ShareFlags::Model, "Returns the Model used for the evaluation");
cls_Interface_ShareFlags.def("IsShared", (Standard_Boolean (Interface_ShareFlags::*)(const opencascade::handle<Standard_Transient> &) const) &Interface_ShareFlags::IsShared, "Returns True if <ent> is Shared by one or more other Entity(ies) of the Model", py::arg("ent"));
cls_Interface_ShareFlags.def("RootEntities", (Interface_EntityIterator (Interface_ShareFlags::*)() const) &Interface_ShareFlags::RootEntities, "Returns the Entities which are not Shared (see their flags)");
cls_Interface_ShareFlags.def("NbRoots", (Standard_Integer (Interface_ShareFlags::*)() const) &Interface_ShareFlags::NbRoots, "Returns the count of root entities");
cls_Interface_ShareFlags.def("Root", [](Interface_ShareFlags &self) -> opencascade::handle<Standard_Transient> { return self.Root(); });
cls_Interface_ShareFlags.def("Root", (opencascade::handle<Standard_Transient> (Interface_ShareFlags::*)(const Standard_Integer) const) &Interface_ShareFlags::Root, "Returns a root entity according its rank in the list of roots By default, it returns the first one", py::arg("num"));

// CLASS: INTERFACE_SIGNLABEL
py::class_<Interface_SignLabel, opencascade::handle<Interface_SignLabel>, MoniTool_SignText> cls_Interface_SignLabel(mod, "Interface_SignLabel", "Signature to give the Label from the Model");

// Constructors
cls_Interface_SignLabel.def(py::init<>());

// Methods
cls_Interface_SignLabel.def("Name", (Standard_CString (Interface_SignLabel::*)() const) &Interface_SignLabel::Name, "Returns 'Entity Label'");
cls_Interface_SignLabel.def("Text", (TCollection_AsciiString (Interface_SignLabel::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &) const) &Interface_SignLabel::Text, "Considers context as an InterfaceModel and returns the Label computed by it", py::arg("ent"), py::arg("context"));
cls_Interface_SignLabel.def_static("get_type_name_", (const char * (*)()) &Interface_SignLabel::get_type_name, "None");
cls_Interface_SignLabel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_SignLabel::get_type_descriptor, "None");
cls_Interface_SignLabel.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_SignLabel::*)() const) &Interface_SignLabel::DynamicType, "None");

// CLASS: INTERFACE_STAT
py::class_<Interface_STAT> cls_Interface_STAT(mod, "Interface_STAT", "This class manages statistics to be queried asynchronously. Way of use : An operator describes a STAT form then fills it according to its progression. This produces a state of advancement of the process. This state can then be queried asynchronously : typically it is summarised as a percentage. There are also an identification of the current state, and informations on processed volume.");

// Constructors
cls_Interface_STAT.def(py::init<>());
cls_Interface_STAT.def(py::init<const Standard_CString>(), py::arg("title"));
cls_Interface_STAT.def(py::init<const Interface_STAT &>(), py::arg("other"));

// Methods
// cls_Interface_STAT.def_static("operator new_", (void * (*)(size_t)) &Interface_STAT::operator new, "None", py::arg("theSize"));
// cls_Interface_STAT.def_static("operator delete_", (void (*)(void *)) &Interface_STAT::operator delete, "None", py::arg("theAddress"));
// cls_Interface_STAT.def_static("operator new[]_", (void * (*)(size_t)) &Interface_STAT::operator new[], "None", py::arg("theSize"));
// cls_Interface_STAT.def_static("operator delete[]_", (void (*)(void *)) &Interface_STAT::operator delete[], "None", py::arg("theAddress"));
// cls_Interface_STAT.def_static("operator new_", (void * (*)(size_t, void *)) &Interface_STAT::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Interface_STAT.def_static("operator delete_", (void (*)(void *, void *)) &Interface_STAT::operator delete, "None", py::arg(""), py::arg(""));
cls_Interface_STAT.def("Internals", [](Interface_STAT &self, opencascade::handle<TCollection_HAsciiString> & tit, Standard_Real & total, opencascade::handle<TColStd_HSequenceOfAsciiString> & phn, opencascade::handle<TColStd_HSequenceOfReal> & phw, opencascade::handle<TColStd_HSequenceOfInteger> & phdeb, opencascade::handle<TColStd_HSequenceOfInteger> & phfin, opencascade::handle<TColStd_HSequenceOfReal> & stw){ self.Internals(tit, total, phn, phw, phdeb, phfin, stw); return total; }, "Returns fields in once, without copying them, used for copy when starting", py::arg("tit"), py::arg("total"), py::arg("phn"), py::arg("phw"), py::arg("phdeb"), py::arg("phfin"), py::arg("stw"));
cls_Interface_STAT.def("AddPhase", [](Interface_STAT &self, const Standard_Real a0) -> void { return self.AddPhase(a0); });
cls_Interface_STAT.def("AddPhase", (void (Interface_STAT::*)(const Standard_Real, const Standard_CString)) &Interface_STAT::AddPhase, "Adds a new phase to the description. The first one after Create replaces the default unique one", py::arg("weight"), py::arg("name"));
cls_Interface_STAT.def("AddStep", [](Interface_STAT &self) -> void { return self.AddStep(); });
cls_Interface_STAT.def("AddStep", (void (Interface_STAT::*)(const Standard_Real)) &Interface_STAT::AddStep, "Adds a new step for the last added phase, the default unique one if no AddPhase has already been added Warning : AddStep before the first AddPhase are cancelled", py::arg("weight"));
// cls_Interface_STAT.def("Description", [](Interface_STAT &self, Standard_Integer & nbphases, Standard_Real & total, Standard_CString & title){ self.Description(nbphases, total, title); return std::tuple<Standard_Integer &, Standard_Real &, Standard_CString &>(nbphases, total, title); }, "Returns global description (cumulated weights of all phases, count of phases,1 for default, and title)", py::arg("nbphases"), py::arg("total"), py::arg("title"));
// cls_Interface_STAT.def("Phase", [](Interface_STAT &self, const Standard_Integer num, Standard_Integer & n0step, Standard_Integer & nbstep, Standard_Real & weight, Standard_CString & name){ self.Phase(num, n0step, nbstep, weight, name); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Real &, Standard_CString &>(n0step, nbstep, weight, name); }, "Returns description of a phase, given its rank (n0 for first step, count of steps, default gives one; weight, name)", py::arg("num"), py::arg("n0step"), py::arg("nbstep"), py::arg("weight"), py::arg("name"));
cls_Interface_STAT.def("Step", (Standard_Real (Interface_STAT::*)(const Standard_Integer) const) &Interface_STAT::Step, "Returns weight of a Step, related to the cumul given for the phase. <num> is given by <n0step> + i, i between 1 and <nbsteps> (default gives n0step < 0 then weight is one)", py::arg("num"));
cls_Interface_STAT.def("Start", [](Interface_STAT &self, const Standard_Integer a0) -> void { return self.Start(a0); });
cls_Interface_STAT.def("Start", (void (Interface_STAT::*)(const Standard_Integer, const Standard_Integer) const) &Interface_STAT::Start, "Starts a STAT on its first phase (or its default one) <items> gives the total count of items, <cycles> the count of cycles If <cycles> is more than one, the first Cycle must then be started by NextCycle (NextStep/NextItem are ignored). If it is one, NextItem/NextStep can then be called", py::arg("items"), py::arg("cycles"));
cls_Interface_STAT.def_static("StartCount_", [](const Standard_Integer a0) -> void { return Interface_STAT::StartCount(a0); });
cls_Interface_STAT.def_static("StartCount_", (void (*)(const Standard_Integer, const Standard_CString)) &Interface_STAT::StartCount, "Starts a default STAT, with no phase, no step, ready to just count items. <items> gives the total count of items Hence, NextItem is available to directly count", py::arg("items"), py::arg("title"));
cls_Interface_STAT.def_static("NextPhase_", [](const Standard_Integer a0) -> void { return Interface_STAT::NextPhase(a0); });
cls_Interface_STAT.def_static("NextPhase_", (void (*)(const Standard_Integer, const Standard_Integer)) &Interface_STAT::NextPhase, "Commands to resume the preceeding phase and start a new one <items> and <cycles> as for Start, but for this new phase Ignored if count of phases is already passed If <cycles> is more than one, the first Cycle must then be started by NextCycle (NextStep/NextItem are ignored). If it is one, NextItem/NextStep can then be called", py::arg("items"), py::arg("cycles"));
cls_Interface_STAT.def_static("SetPhase_", [](const Standard_Integer a0) -> void { return Interface_STAT::SetPhase(a0); });
cls_Interface_STAT.def_static("SetPhase_", (void (*)(const Standard_Integer, const Standard_Integer)) &Interface_STAT::SetPhase, "Changes the parameters of the phase to start To be used before first counting (i.e. just after NextPhase) Can be used by an operator which has to reajust counts on run", py::arg("items"), py::arg("cycles"));
cls_Interface_STAT.def_static("NextCycle_", (void (*)(const Standard_Integer)) &Interface_STAT::NextCycle, "Commands to resume the preceeding cycle and start a new one, with a count of items Ignored if count of cycles is already passed Then, first step is started (or default one) NextItem can be called for the first step, or NextStep to pass to the next one", py::arg("items"));
cls_Interface_STAT.def_static("NextStep_", (void (*)()) &Interface_STAT::NextStep, "Commands to resume the preceeding step of the cycle Ignored if count of steps is already passed NextItem can be called for this step, NextStep passes to next");
cls_Interface_STAT.def_static("NextItem_", []() -> void { return Interface_STAT::NextItem(); });
cls_Interface_STAT.def_static("NextItem_", (void (*)(const Standard_Integer)) &Interface_STAT::NextItem, "Commands to add an item in the current step of the current cycle of the current phase By default, one item per call, can be overpassed Ignored if count of items of this cycle is already passed", py::arg("nbitems"));
cls_Interface_STAT.def_static("End_", (void (*)()) &Interface_STAT::End, "Commands to declare the process ended (hence, advancement is forced to 100 %)");
cls_Interface_STAT.def_static("Where_", []() -> Standard_CString { return Interface_STAT::Where(); });
cls_Interface_STAT.def_static("Where_", (Standard_CString (*)(const Standard_Boolean)) &Interface_STAT::Where, "Returns an identification of the STAT : <phase> True (D) : the name of the current phase <phase> False : the title of the current STAT", py::arg("phase"));
cls_Interface_STAT.def_static("Percent_", []() -> Standard_Integer { return Interface_STAT::Percent(); });
cls_Interface_STAT.def_static("Percent_", (Standard_Integer (*)(const Standard_Boolean)) &Interface_STAT::Percent, "Returns the advancement as a percentage : <phase> True : inside the current phase <phase> False (D) : relative to the whole process", py::arg("phase"));

// TYPEDEF: INTERFACE_STATICSATISFIES

// CLASS: INTERFACE_TYPEDVALUE
py::class_<Interface_TypedValue, opencascade::handle<Interface_TypedValue>, MoniTool_TypedValue> cls_Interface_TypedValue(mod, "Interface_TypedValue", "Now strictly equivalent to TypedValue from MoniTool, except for ParamType which remains for compatibility reasons");

// Constructors
cls_Interface_TypedValue.def(py::init<const Standard_CString>(), py::arg("name"));
cls_Interface_TypedValue.def(py::init<const Standard_CString, const Interface_ParamType>(), py::arg("name"), py::arg("type"));
cls_Interface_TypedValue.def(py::init<const Standard_CString, const Interface_ParamType, const Standard_CString>(), py::arg("name"), py::arg("type"), py::arg("init"));

// Methods
cls_Interface_TypedValue.def("Type", (Interface_ParamType (Interface_TypedValue::*)() const) &Interface_TypedValue::Type, "Returns the type I.E. calls ValueType then makes correspondance between ParamType from Interface (which remains for compatibility reasons) and ValueType from MoniTool");
cls_Interface_TypedValue.def_static("ParamTypeToValueType_", (MoniTool_ValueType (*)(const Interface_ParamType)) &Interface_TypedValue::ParamTypeToValueType, "Correspondance ParamType from Interface to ValueType from MoniTool", py::arg("typ"));
cls_Interface_TypedValue.def_static("ValueTypeToParamType_", (Interface_ParamType (*)(const MoniTool_ValueType)) &Interface_TypedValue::ValueTypeToParamType, "Correspondance ParamType from Interface to ValueType from MoniTool", py::arg("typ"));
cls_Interface_TypedValue.def_static("get_type_name_", (const char * (*)()) &Interface_TypedValue::get_type_name, "None");
cls_Interface_TypedValue.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_TypedValue::get_type_descriptor, "None");
cls_Interface_TypedValue.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_TypedValue::*)() const) &Interface_TypedValue::DynamicType, "None");

// CLASS: INTERFACE_STATIC
py::class_<Interface_Static, opencascade::handle<Interface_Static>, Interface_TypedValue> cls_Interface_Static(mod, "Interface_Static", "This class gives a way to manage meaningfull static variables, used as 'global' parameters in various procedures.");

// Constructors
cls_Interface_Static.def(py::init<const Standard_CString, const Standard_CString>(), py::arg("family"), py::arg("name"));
cls_Interface_Static.def(py::init<const Standard_CString, const Standard_CString, const Interface_ParamType>(), py::arg("family"), py::arg("name"), py::arg("type"));
cls_Interface_Static.def(py::init<const Standard_CString, const Standard_CString, const Interface_ParamType, const Standard_CString>(), py::arg("family"), py::arg("name"), py::arg("type"), py::arg("init"));
cls_Interface_Static.def(py::init<const Standard_CString, const Standard_CString, const opencascade::handle<Interface_Static> &>(), py::arg("family"), py::arg("name"), py::arg("other"));

// Methods
cls_Interface_Static.def("PrintStatic", (void (Interface_Static::*)(const opencascade::handle<Message_Messenger> &) const) &Interface_Static::PrintStatic, "Writes the properties of a parameter in the diagnostic file. These include: - Name - Family, - Wildcard (if it has one) - Current status (empty string if it was updated or if it is the original one) - Value", py::arg("S"));
cls_Interface_Static.def("Family", (Standard_CString (Interface_Static::*)() const) &Interface_Static::Family, "Returns the family. It can be : a resource name for applis, an internal name between : $e (environment variables), $l (other, purely local)");
cls_Interface_Static.def("SetWild", (void (Interface_Static::*)(const opencascade::handle<Interface_Static> &)) &Interface_Static::SetWild, "Sets a 'wild-card' static : its value will be considered if <me> is not properly set. (reset by set a null one)", py::arg("wildcard"));
cls_Interface_Static.def("Wild", (opencascade::handle<Interface_Static> (Interface_Static::*)() const) &Interface_Static::Wild, "Returns the wildcard static, which can be (is most often) null");
cls_Interface_Static.def("SetUptodate", (void (Interface_Static::*)()) &Interface_Static::SetUptodate, "Records a Static has 'uptodate', i.e. its value has been taken into account by a reinitialisation procedure This flag is reset at each successful SetValue");
cls_Interface_Static.def("UpdatedStatus", (Standard_Boolean (Interface_Static::*)() const) &Interface_Static::UpdatedStatus, "Returns the status 'uptodate'");
cls_Interface_Static.def_static("Init_", [](const Standard_CString a0, const Standard_CString a1, const Interface_ParamType a2) -> Standard_Boolean { return Interface_Static::Init(a0, a1, a2); });
cls_Interface_Static.def_static("Init_", (Standard_Boolean (*)(const Standard_CString, const Standard_CString, const Interface_ParamType, const Standard_CString)) &Interface_Static::Init, "Declares a new Static (by calling its constructor) If this name is already taken, does nothing and returns False Else, creates it and returns True For additional definitions, get the Static then edit it", py::arg("family"), py::arg("name"), py::arg("type"), py::arg("init"));
cls_Interface_Static.def_static("Init_", [](const Standard_CString a0, const Standard_CString a1, const Standard_Character a2) -> Standard_Boolean { return Interface_Static::Init(a0, a1, a2); });
cls_Interface_Static.def_static("Init_", (Standard_Boolean (*)(const Standard_CString, const Standard_CString, const Standard_Character, const Standard_CString)) &Interface_Static::Init, "As Init with ParamType, but type is given as a character This allows a simpler call Types : 'i' Integer, 'r' Real, 't' Text, 'e' Enum, 'o' Object '=' for same definition as, <init> gives the initial Static Returns False if <type> does not match this list", py::arg("family"), py::arg("name"), py::arg("type"), py::arg("init"));
cls_Interface_Static.def_static("Static_", (opencascade::handle<Interface_Static> (*)(const Standard_CString)) &Interface_Static::Static, "Returns a Static from its name. Null Handle if not present", py::arg("name"));
cls_Interface_Static.def_static("IsPresent_", (Standard_Boolean (*)(const Standard_CString)) &Interface_Static::IsPresent, "Returns True if a Static named <name> is present, False else", py::arg("name"));
cls_Interface_Static.def_static("CDef_", (Standard_CString (*)(const Standard_CString, const Standard_CString)) &Interface_Static::CDef, "Returns a part of the definition of a Static, as a CString The part is designated by its name, as a CString If the required value is not a string, it is converted to a CString then returned If <name> is not present, or <part> not defined for <name>, this function returns an empty string", py::arg("name"), py::arg("part"));
cls_Interface_Static.def_static("IDef_", (Standard_Integer (*)(const Standard_CString, const Standard_CString)) &Interface_Static::IDef, "Returns a part of the definition of a Static, as an Integer The part is designated by its name, as a CString If the required value is not a string, returns zero For a Boolean, 0 for false, 1 for true If <name> is not present, or <part> not defined for <name>, this function returns zero", py::arg("name"), py::arg("part"));
cls_Interface_Static.def_static("IsSet_", [](const Standard_CString a0) -> Standard_Boolean { return Interface_Static::IsSet(a0); });
cls_Interface_Static.def_static("IsSet_", (Standard_Boolean (*)(const Standard_CString, const Standard_Boolean)) &Interface_Static::IsSet, "Returns True if <name> is present AND set <proper> True (D) : considers this item only <proper> False : if not set and attached to a wild-card, considers this wild-card", py::arg("name"), py::arg("proper"));
cls_Interface_Static.def_static("CVal_", (Standard_CString (*)(const Standard_CString)) &Interface_Static::CVal, "Returns the value of the parameter identified by the string name. If the specified parameter does not exist, an empty string is returned. Example Interface_Static::CVal('write.step.schema'); which could return: 'AP214'", py::arg("name"));
cls_Interface_Static.def_static("IVal_", (Standard_Integer (*)(const Standard_CString)) &Interface_Static::IVal, "Returns the integer value of the translation parameter identified by the string name. Returns the value 0 if the parameter does not exist. Example Interface_Static::IVal('write.step.schema'); which could return: 3", py::arg("name"));
cls_Interface_Static.def_static("RVal_", (Standard_Real (*)(const Standard_CString)) &Interface_Static::RVal, "Returns the value of a static translation parameter identified by the string name. Returns the value 0.0 if the parameter does not exist.", py::arg("name"));
cls_Interface_Static.def_static("SetCVal_", (Standard_Boolean (*)(const Standard_CString, const Standard_CString)) &Interface_Static::SetCVal, "Modifies the value of the parameter identified by name. The modification is specified by the string val. false is returned if the parameter does not exist. Example Interface_Static::SetCVal ('write.step.schema','AP203') This syntax specifies a switch from the default STEP 214 mode to STEP 203 mode.", py::arg("name"), py::arg("val"));
cls_Interface_Static.def_static("SetIVal_", (Standard_Boolean (*)(const Standard_CString, const Standard_Integer)) &Interface_Static::SetIVal, "Modifies the value of the parameter identified by name. The modification is specified by the integer value val. false is returned if the parameter does not exist. Example Interface_Static::SetIVal ('write.step.schema', 3) This syntax specifies a switch from the default STEP 214 mode to STEP 203 mode.S", py::arg("name"), py::arg("val"));
cls_Interface_Static.def_static("SetRVal_", (Standard_Boolean (*)(const Standard_CString, const Standard_Real)) &Interface_Static::SetRVal, "Modifies the value of a translation parameter. false is returned if the parameter does not exist. The modification is specified by the real number value val.", py::arg("name"), py::arg("val"));
cls_Interface_Static.def_static("Update_", (Standard_Boolean (*)(const Standard_CString)) &Interface_Static::Update, "Sets a Static to be 'uptodate' Returns False if <name> is not present This status can be used by a reinitialisation procedure to rerun if a value has been changed", py::arg("name"));
cls_Interface_Static.def_static("IsUpdated_", (Standard_Boolean (*)(const Standard_CString)) &Interface_Static::IsUpdated, "Returns the status 'uptodate' from a Static Returns False if <name> is not present", py::arg("name"));
cls_Interface_Static.def_static("Items_", []() -> opencascade::handle<TColStd_HSequenceOfHAsciiString> { return Interface_Static::Items(); });
cls_Interface_Static.def_static("Items_", [](const Standard_Integer a0) -> opencascade::handle<TColStd_HSequenceOfHAsciiString> { return Interface_Static::Items(a0); });
cls_Interface_Static.def_static("Items_", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (*)(const Standard_Integer, const Standard_CString)) &Interface_Static::Items, "Returns a list of names of statics : <mode> = 0 (D) : criter is for family <mode> = 1 : criter is regexp on names, takes final items (ignore wild cards) <mode> = 2 : idem but take only wilded, not final items <mode> = 3 : idem, take all items matching criter idem + 100 : takes only non-updated items idem + 200 : takes only updated items criter empty (D) : returns all names else returns names which match the given criter Remark : families beginning by '$' are not listed by criter '' they are listed only by criter '$'", py::arg("mode"), py::arg("criter"));
cls_Interface_Static.def_static("Standards_", (void (*)()) &Interface_Static::Standards, "Initializes all standard static parameters, which can be used by every function. statics specific of a norm or a function must be defined around it");
cls_Interface_Static.def_static("get_type_name_", (const char * (*)()) &Interface_Static::get_type_name, "None");
cls_Interface_Static.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_Static::get_type_descriptor, "None");
cls_Interface_Static.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_Static::*)() const) &Interface_Static::DynamicType, "None");

// CLASS: INTERFACE_UNDEFINEDCONTENT
py::class_<Interface_UndefinedContent, opencascade::handle<Interface_UndefinedContent>, Standard_Transient> cls_Interface_UndefinedContent(mod, "Interface_UndefinedContent", "Defines resources for an 'Undefined Entity' : such an Entity is used to describe an Entity which complies with the Norm, but of an Unknown Type : hence it is kept under a literal form (avoiding to loose data). UndefinedContent offers a way to store a list of Parameters, as literals or references to other Entities");

// Constructors
cls_Interface_UndefinedContent.def(py::init<>());

// Methods
cls_Interface_UndefinedContent.def("NbParams", (Standard_Integer (Interface_UndefinedContent::*)() const) &Interface_UndefinedContent::NbParams, "Gives count of recorded parameters");
cls_Interface_UndefinedContent.def("NbLiterals", (Standard_Integer (Interface_UndefinedContent::*)() const) &Interface_UndefinedContent::NbLiterals, "Gives count of Literal Parameters");
cls_Interface_UndefinedContent.def("ParamData", (Standard_Boolean (Interface_UndefinedContent::*)(const Standard_Integer, Interface_ParamType &, opencascade::handle<Standard_Transient> &, opencascade::handle<TCollection_HAsciiString> &) const) &Interface_UndefinedContent::ParamData, "Returns data of a Parameter : its type, and the entity if it designates en entity ('ent') or its literal value else ('str') Returned value (Boolean) : True if it is an Entity, False else", py::arg("num"), py::arg("ptype"), py::arg("ent"), py::arg("val"));
cls_Interface_UndefinedContent.def("ParamType", (Interface_ParamType (Interface_UndefinedContent::*)(const Standard_Integer) const) &Interface_UndefinedContent::ParamType, "Returns the ParamType of a Param, given its rank Error if num is not between 1 and NbParams", py::arg("num"));
cls_Interface_UndefinedContent.def("IsParamEntity", (Standard_Boolean (Interface_UndefinedContent::*)(const Standard_Integer) const) &Interface_UndefinedContent::IsParamEntity, "Returns True if a Parameter is recorded as an entity Error if num is not between 1 and NbParams", py::arg("num"));
cls_Interface_UndefinedContent.def("ParamEntity", (opencascade::handle<Standard_Transient> (Interface_UndefinedContent::*)(const Standard_Integer) const) &Interface_UndefinedContent::ParamEntity, "Returns Entity corresponding to a Param, given its rank", py::arg("num"));
cls_Interface_UndefinedContent.def("ParamValue", (opencascade::handle<TCollection_HAsciiString> (Interface_UndefinedContent::*)(const Standard_Integer) const) &Interface_UndefinedContent::ParamValue, "Returns litteral value of a Parameter, given its rank", py::arg("num"));
cls_Interface_UndefinedContent.def("Reservate", (void (Interface_UndefinedContent::*)(const Standard_Integer, const Standard_Integer)) &Interface_UndefinedContent::Reservate, "Manages reservation for parameters (internal use) (nb : total count of parameters, nblit : count of literals)", py::arg("nb"), py::arg("nblit"));
cls_Interface_UndefinedContent.def("AddLiteral", (void (Interface_UndefinedContent::*)(const Interface_ParamType, const opencascade::handle<TCollection_HAsciiString> &)) &Interface_UndefinedContent::AddLiteral, "Adds a literal Parameter to the list", py::arg("ptype"), py::arg("val"));
cls_Interface_UndefinedContent.def("AddEntity", (void (Interface_UndefinedContent::*)(const Interface_ParamType, const opencascade::handle<Standard_Transient> &)) &Interface_UndefinedContent::AddEntity, "Adds a Parameter which references an Entity", py::arg("ptype"), py::arg("ent"));
cls_Interface_UndefinedContent.def("RemoveParam", (void (Interface_UndefinedContent::*)(const Standard_Integer)) &Interface_UndefinedContent::RemoveParam, "Removes a Parameter given its rank", py::arg("num"));
cls_Interface_UndefinedContent.def("SetLiteral", (void (Interface_UndefinedContent::*)(const Standard_Integer, const Interface_ParamType, const opencascade::handle<TCollection_HAsciiString> &)) &Interface_UndefinedContent::SetLiteral, "Sets a new value for the Parameter <num>, to a literal value (if it referenced formerly an Entity, this Entity is removed)", py::arg("num"), py::arg("ptype"), py::arg("val"));
cls_Interface_UndefinedContent.def("SetEntity", (void (Interface_UndefinedContent::*)(const Standard_Integer, const Interface_ParamType, const opencascade::handle<Standard_Transient> &)) &Interface_UndefinedContent::SetEntity, "Sets a new value for the Parameter <num>, to reference an Entity. To simply change the Entity, see the variant below", py::arg("num"), py::arg("ptype"), py::arg("ent"));
cls_Interface_UndefinedContent.def("SetEntity", (void (Interface_UndefinedContent::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &)) &Interface_UndefinedContent::SetEntity, "Changes the Entity referenced by the Parameter <num> (with same ParamType)", py::arg("num"), py::arg("ent"));
cls_Interface_UndefinedContent.def("EntityList", (Interface_EntityList (Interface_UndefinedContent::*)() const) &Interface_UndefinedContent::EntityList, "Returns globally the list of param entities. Note that it can be used as shared entity list for the UndefinedEntity");
cls_Interface_UndefinedContent.def("GetFromAnother", (void (Interface_UndefinedContent::*)(const opencascade::handle<Interface_UndefinedContent> &, Interface_CopyTool &)) &Interface_UndefinedContent::GetFromAnother, "Copies contents of undefined entities; deigned to be called by GetFromAnother method from Undefined entity of each Interface (the basic operation is the same regardless the norm)", py::arg("other"), py::arg("TC"));
cls_Interface_UndefinedContent.def_static("get_type_name_", (const char * (*)()) &Interface_UndefinedContent::get_type_name, "None");
cls_Interface_UndefinedContent.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_UndefinedContent::get_type_descriptor, "None");
cls_Interface_UndefinedContent.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_UndefinedContent::*)() const) &Interface_UndefinedContent::DynamicType, "None");

// TYPEDEF: INTERFACE_VALUEINTERPRET

// TYPEDEF: INTERFACE_VALUESATISFIES
if (py::hasattr(mod, "Interface_StaticSatisfies")) {
	mod.attr("Interface_ValueSatisfies") = mod.attr("Interface_StaticSatisfies");
}


}
