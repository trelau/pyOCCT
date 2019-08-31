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
#include <IGESData_DefType.hxx>
#include <IGESData_DefList.hxx>
#include <IGESData_ReadStage.hxx>
#include <IGESData_Status.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESData_DefSwitch.hxx>
#include <Standard_Transient.hxx>
#include <IGESData_IGESType.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESEntity.hxx>
#include <IGESData_LineFontEntity.hxx>
#include <IGESData_LevelListEntity.hxx>
#include <IGESData_ViewKindEntity.hxx>
#include <IGESData_TransfEntity.hxx>
#include <IGESData_LabelDisplayEntity.hxx>
#include <IGESData_ColorEntity.hxx>
#include <TCollection_HAsciiString.hxx>
#include <gp_GTrsf.hxx>
#include <Interface_EntityIterator.hxx>
#include <Standard_Type.hxx>
#include <IGESData_ReadWriteModule.hxx>
#include <IGESData_GeneralModule.hxx>
#include <IGESData_IGESReaderTool.hxx>
#include <IGESData_DirChecker.hxx>
#include <Interface_EntityList.hxx>
#include <NCollection_Array1.hxx>
#include <IGESData_Array1OfIGESEntity.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <Interface_GeneralModule.hxx>
#include <Interface_ShareTool.hxx>
#include <Interface_Check.hxx>
#include <Interface_CopyTool.hxx>
#include <Interface_Protocol.hxx>
#include <Interface_InterfaceModel.hxx>
#include <IGESData_Protocol.hxx>
#include <Interface_ReaderModule.hxx>
#include <Interface_FileReaderData.hxx>
#include <IGESData_IGESReaderData.hxx>
#include <IGESData_ParamReader.hxx>
#include <IGESData_IGESWriter.hxx>
#include <IGESData_IGESDumper.hxx>
#include <Message_Messenger.hxx>
#include <IGESData_SpecificModule.hxx>
#include <IGESData_NameEntity.hxx>
#include <IGESData_SingleParentEntity.hxx>
#include <IGESData_NodeOfSpecificLib.hxx>
#include <IGESData_SpecificLib.hxx>
#include <IGESData_IGESModel.hxx>
#include <Interface_GeneralLib.hxx>
#include <IGESData_BasicEditor.hxx>
#include <IGESData_UndefinedEntity.hxx>
#include <IGESData_FreeFormatEntity.hxx>
#include <IGESData_GlobalSection.hxx>
#include <IGESData_ParamCursor.hxx>
#include <IGESData_DirPart.hxx>
#include <IGESData_FileRecognizer.hxx>
#include <IGESData_ToolLocation.hxx>
#include <IGESData_DefaultGeneral.hxx>
#include <IGESData_DefaultSpecific.hxx>
#include <IGESData_FileProtocol.hxx>
#include <IGESData_WriterLib.hxx>
#include <IGESData_GlobalNodeOfWriterLib.hxx>
#include <IGESData_NodeOfWriterLib.hxx>
#include <IGESData_GlobalNodeOfSpecificLib.hxx>
#include <IGESData.hxx>
#include <IGESData_Array1OfDirPart.hxx>
#include <Interface_UndefinedContent.hxx>
#include <Interface_ParamType.hxx>
#include <TColStd_HSequenceOfInteger.hxx>
#include <Interface_ParamSet.hxx>
#include <gp_XYZ.hxx>
#include <TColStd_HSequenceOfHAsciiString.hxx>
#include <Interface_FileReaderTool.hxx>
#include <Interface_ParamList.hxx>
#include <Interface_ReaderLib.hxx>
#include <Interface_FloatWriter.hxx>
#include <gp_XY.hxx>
#include <Standard_OStream.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <Interface_LineBuffer.hxx>
#include <Message_Msg.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <Interface_HArray1OfHAsciiString.hxx>
#include <gp_Trsf.hxx>
#include <bind_NCollection_Array1.hxx>

PYBIND11_MODULE(IGESData, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.gp");
py::module::import("OCCT.Interface");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Message");
py::module::import("OCCT.TColStd");

// ENUM: IGESDATA_DEFTYPE
py::enum_<IGESData_DefType>(mod, "IGESData_DefType", "Some fields of an IGES entity may be - Undefined - Defined as a positive integer - Defined as a reference to a specialized entity. A typical example of this kind of variation is color. This enumeration allows you to identify which of the above is the case. The semantics of the terms are as follows: - DefVoid indicates that the item contained in the field is undefined - DefValue indicates that the item is defined as an immediate positive integer value (i.e. not a pointer) - DefReference indicates that the item is defined as an entity - DefAny indicates the item could not be determined - ErrorVal indicates that the item is defined as an integer but its value is incorrect (it could be out of range, for example) - ErrorRef indicates that the item is defined as an entity but is not of the required type.")
	.value("IGESData_DefVoid", IGESData_DefType::IGESData_DefVoid)
	.value("IGESData_DefValue", IGESData_DefType::IGESData_DefValue)
	.value("IGESData_DefReference", IGESData_DefType::IGESData_DefReference)
	.value("IGESData_DefAny", IGESData_DefType::IGESData_DefAny)
	.value("IGESData_ErrorVal", IGESData_DefType::IGESData_ErrorVal)
	.value("IGESData_ErrorRef", IGESData_DefType::IGESData_ErrorRef)
	.export_values();


// ENUM: IGESDATA_DEFLIST
py::enum_<IGESData_DefList>(mod, "IGESData_DefList", "Some fields of an IGES entity may be - Undefined - Defined as a single item - Defined as a list of items. A typical example, which presents this kind of variation, is a level number. This enumeration allows you to identify which of the above is the case. The semantics of the terms is as follows: - DefNone indicates that the list is empty (there is not even a single item). - DefOne indicates that the list contains a single item. - DefSeveral indicates that the list contains several items. - ErrorOne indicates that the list contains one item, but that this item is incorrect - ErrorSeveral indicates that the list contains several items, but that at least one of them is incorrect.")
	.value("IGESData_DefNone", IGESData_DefList::IGESData_DefNone)
	.value("IGESData_DefOne", IGESData_DefList::IGESData_DefOne)
	.value("IGESData_DefSeveral", IGESData_DefList::IGESData_DefSeveral)
	.value("IGESData_ErrorOne", IGESData_DefList::IGESData_ErrorOne)
	.value("IGESData_ErrorSeveral", IGESData_DefList::IGESData_ErrorSeveral)
	.export_values();


// ENUM: IGESDATA_READSTAGE
py::enum_<IGESData_ReadStage>(mod, "IGESData_ReadStage", "gives successive stages of reading an entity (see ParamReader)")
	.value("IGESData_ReadDir", IGESData_ReadStage::IGESData_ReadDir)
	.value("IGESData_ReadOwn", IGESData_ReadStage::IGESData_ReadOwn)
	.value("IGESData_ReadAssocs", IGESData_ReadStage::IGESData_ReadAssocs)
	.value("IGESData_ReadProps", IGESData_ReadStage::IGESData_ReadProps)
	.value("IGESData_ReadEnd", IGESData_ReadStage::IGESData_ReadEnd)
	.export_values();


// ENUM: IGESDATA_STATUS
py::enum_<IGESData_Status>(mod, "IGESData_Status", "None")
	.value("IGESData_EntityOK", IGESData_Status::IGESData_EntityOK)
	.value("IGESData_EntityError", IGESData_Status::IGESData_EntityError)
	.value("IGESData_ReferenceError", IGESData_Status::IGESData_ReferenceError)
	.value("IGESData_TypeError", IGESData_Status::IGESData_TypeError)
	.export_values();


// CLASS: IGESDATA_DEFSWITCH
py::class_<IGESData_DefSwitch> cls_IGESData_DefSwitch(mod, "IGESData_DefSwitch", "description of a directory componant which can be either undefined (let Void), defined as a Reference to an entity, or as a Rank, integer value adressing a builtin table The entity reference is not included here, only reference status is kept (because entity type must be adapted)");

// Constructors
cls_IGESData_DefSwitch.def(py::init<>());

// Methods
// cls_IGESData_DefSwitch.def_static("operator new_", (void * (*)(size_t)) &IGESData_DefSwitch::operator new, "None", py::arg("theSize"));
// cls_IGESData_DefSwitch.def_static("operator delete_", (void (*)(void *)) &IGESData_DefSwitch::operator delete, "None", py::arg("theAddress"));
// cls_IGESData_DefSwitch.def_static("operator new[]_", (void * (*)(size_t)) &IGESData_DefSwitch::operator new[], "None", py::arg("theSize"));
// cls_IGESData_DefSwitch.def_static("operator delete[]_", (void (*)(void *)) &IGESData_DefSwitch::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData_DefSwitch.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData_DefSwitch::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData_DefSwitch.def_static("operator delete_", (void (*)(void *, void *)) &IGESData_DefSwitch::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESData_DefSwitch.def("SetVoid", (void (IGESData_DefSwitch::*)()) &IGESData_DefSwitch::SetVoid, "sets DefSwitch to 'Void' status (in file : Integer = 0)");
cls_IGESData_DefSwitch.def("SetReference", (void (IGESData_DefSwitch::*)()) &IGESData_DefSwitch::SetReference, "sets DefSwitch to 'Reference' Status (in file : Integer < 0)");
cls_IGESData_DefSwitch.def("SetRank", (void (IGESData_DefSwitch::*)(const Standard_Integer)) &IGESData_DefSwitch::SetRank, "sets DefSwitch to 'Rank' with a Value (in file : Integer > 0)", py::arg("val"));
cls_IGESData_DefSwitch.def("DefType", (IGESData_DefType (IGESData_DefSwitch::*)() const) &IGESData_DefSwitch::DefType, "returns DefType status (Void,Reference,Rank)");
cls_IGESData_DefSwitch.def("Value", (Standard_Integer (IGESData_DefSwitch::*)() const) &IGESData_DefSwitch::Value, "returns Value as Integer (sensefull for a Rank)");

// CLASS: IGESDATA_IGESENTITY
py::class_<IGESData_IGESEntity, opencascade::handle<IGESData_IGESEntity>, Standard_Transient> cls_IGESData_IGESEntity(mod, "IGESData_IGESEntity", "defines root of IGES Entity definition, including Directory Part, lists of (optionnal) Properties and Associativities");

// Methods
cls_IGESData_IGESEntity.def("IGESType", (IGESData_IGESType (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::IGESType, "gives IGES typing info (includes 'Type' and 'Form' data)");
cls_IGESData_IGESEntity.def("TypeNumber", (Standard_Integer (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::TypeNumber, "gives IGES Type Number (often coupled with Form Number)");
cls_IGESData_IGESEntity.def("FormNumber", (Standard_Integer (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::FormNumber, "Returns the form number for that type of an IGES entity. The default form number is 0.");
cls_IGESData_IGESEntity.def("DirFieldEntity", (opencascade::handle<IGESData_IGESEntity> (IGESData_IGESEntity::*)(const Standard_Integer) const) &IGESData_IGESEntity::DirFieldEntity, "Returns the Entity which has been recorded for a given Field Number, i.e. without any cast. Maps with : 3 : Structure 4 : LineFont 5 : LevelList 6 : View 7 : Transf(ormation Matrix) 8 : LabelDisplay 13 : Color. Other values give a null handle It can then be of any kind, while specific items have a Type", py::arg("fieldnum"));
cls_IGESData_IGESEntity.def("HasStructure", (Standard_Boolean (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::HasStructure, "returns True if an IGESEntity is defined with a Structure (it is normally reserved for certain classes, such as Macros)");
cls_IGESData_IGESEntity.def("Structure", (opencascade::handle<IGESData_IGESEntity> (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::Structure, "Returns Structure (used by some types of IGES Entities only) Returns a Null Handle if Structure is not defined");
cls_IGESData_IGESEntity.def("DefLineFont", (IGESData_DefType (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::DefLineFont, "Returns the definition status of LineFont");
cls_IGESData_IGESEntity.def("RankLineFont", (Standard_Integer (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::RankLineFont, "Returns LineFont definition as an Integer (if defined as Rank) If LineFont is defined as an Entity, returns a negative value");
cls_IGESData_IGESEntity.def("LineFont", (opencascade::handle<IGESData_LineFontEntity> (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::LineFont, "Returns LineFont as an Entity (if defined as Reference) Returns a Null Handle if DefLineFont is not 'DefReference'");
cls_IGESData_IGESEntity.def("DefLevel", (IGESData_DefList (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::DefLevel, "Returns the definition status of Level");
cls_IGESData_IGESEntity.def("Level", (Standard_Integer (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::Level, "Returns the level the entity belongs to. Returns -1 if the entity belongs to more than one level.");
cls_IGESData_IGESEntity.def("LevelList", (opencascade::handle<IGESData_LevelListEntity> (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::LevelList, "Returns LevelList if Level is defined as a list. Returns a null handle if DefLevel is not DefSeveral.");
cls_IGESData_IGESEntity.def("DefView", (IGESData_DefList (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::DefView, "Returns the definition status of the view. This can be: none, one or several.");
cls_IGESData_IGESEntity.def("View", (opencascade::handle<IGESData_ViewKindEntity> (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::View, "Returns the view of this IGES entity. This view can be a single view or a list of views. Warning A null handle is returned if the view is not defined.");
cls_IGESData_IGESEntity.def("SingleView", (opencascade::handle<IGESData_ViewKindEntity> (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::SingleView, "Returns the view as a single view if it was defined as such and not as a list of views. Warning A null handle is returned if DefView does not have the value DefOne.");
cls_IGESData_IGESEntity.def("ViewList", (opencascade::handle<IGESData_ViewKindEntity> (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::ViewList, "Returns the view of this IGES entity as a list. Warning A null handle is returned if the definition status does not have the value DefSeveral.");
cls_IGESData_IGESEntity.def("HasTransf", (Standard_Boolean (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::HasTransf, "Returns True if a Transformation Matrix is defined");
cls_IGESData_IGESEntity.def("Transf", (opencascade::handle<IGESData_TransfEntity> (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::Transf, "Returns the Transformation Matrix (under IGES definition) Returns a Null Handle if there is none for a more complete use, see Location & CompoundLocation");
cls_IGESData_IGESEntity.def("HasLabelDisplay", (Standard_Boolean (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::HasLabelDisplay, "Returns True if a LabelDisplay mode is defined for this entity");
cls_IGESData_IGESEntity.def("LabelDisplay", (opencascade::handle<IGESData_LabelDisplayEntity> (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::LabelDisplay, "Returns the Label Display Associativity Entity if there is one. Returns a null handle if there is none.");
cls_IGESData_IGESEntity.def("BlankStatus", (Standard_Integer (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::BlankStatus, "gives Blank Status (0 visible, 1 blanked)");
cls_IGESData_IGESEntity.def("SubordinateStatus", (Standard_Integer (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::SubordinateStatus, "gives Subordinate Switch (0-1-2-3)");
cls_IGESData_IGESEntity.def("UseFlag", (Standard_Integer (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::UseFlag, "gives Entity's Use Flag (0 to 5)");
cls_IGESData_IGESEntity.def("HierarchyStatus", (Standard_Integer (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::HierarchyStatus, "gives Hierarchy status (0-1-2)");
cls_IGESData_IGESEntity.def("LineWeightNumber", (Standard_Integer (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::LineWeightNumber, "Returns the LineWeight Number (0 not defined), see also LineWeight");
cls_IGESData_IGESEntity.def("LineWeight", (Standard_Real (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::LineWeight, "Returns the true Line Weight, computed from LineWeightNumber and Global Parameter in the Model by call to SetLineWeight");
cls_IGESData_IGESEntity.def("DefColor", (IGESData_DefType (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::DefColor, "Returns the definition status of Color.");
cls_IGESData_IGESEntity.def("RankColor", (Standard_Integer (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::RankColor, "Returns the color definition as an integer value if the color was defined as a rank. Warning A negative value is returned if the color was defined as an entity.");
cls_IGESData_IGESEntity.def("Color", (opencascade::handle<IGESData_ColorEntity> (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::Color, "Returns the IGES entity which describes the color of the entity. Returns a null handle if this entity was defined as an integer.");
cls_IGESData_IGESEntity.def("CResValues", (Standard_Boolean (IGESData_IGESEntity::*)(const Standard_CString, const Standard_CString) const) &IGESData_IGESEntity::CResValues, "returns 'reserved' alphanumeric values res1 and res2 res1 and res2 have to be reserved as Character[9 at least] (remark : their content is changed) returned values are ended by null character in 9th returned Boolean is False if res1 and res2 are blank, true else", py::arg("res1"), py::arg("res2"));
cls_IGESData_IGESEntity.def("HasShortLabel", (Standard_Boolean (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::HasShortLabel, "Returns true if a short label is defined. A short label is a non-blank 8-character string.");
cls_IGESData_IGESEntity.def("ShortLabel", (opencascade::handle<TCollection_HAsciiString> (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::ShortLabel, "Returns the label value for this IGES entity as a string. Warning If the label is blank, this string is null.");
cls_IGESData_IGESEntity.def("HasSubScriptNumber", (Standard_Boolean (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::HasSubScriptNumber, "Returns true if a subscript number is defined. A subscript number is an integer used to identify a label.");
cls_IGESData_IGESEntity.def("SubScriptNumber", (Standard_Integer (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::SubScriptNumber, "Returns the integer subscript number used to identify this IGES entity. Warning 0 is returned if no subscript number is defined for this IGES entity.");
cls_IGESData_IGESEntity.def("InitDirFieldEntity", (void (IGESData_IGESEntity::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &)) &IGESData_IGESEntity::InitDirFieldEntity, "Initializes a directory field as an Entiy of any kind See DirFieldEntity for more details", py::arg("fieldnum"), py::arg("ent"));
cls_IGESData_IGESEntity.def("InitTransf", (void (IGESData_IGESEntity::*)(const opencascade::handle<IGESData_TransfEntity> &)) &IGESData_IGESEntity::InitTransf, "Initializes Transf, or erases it if <ent> is given Null", py::arg("ent"));
cls_IGESData_IGESEntity.def("InitView", (void (IGESData_IGESEntity::*)(const opencascade::handle<IGESData_ViewKindEntity> &)) &IGESData_IGESEntity::InitView, "Initializes View, or erases it if <ent> is given Null", py::arg("ent"));
cls_IGESData_IGESEntity.def("InitLineFont", [](IGESData_IGESEntity &self, const opencascade::handle<IGESData_LineFontEntity> & a0) -> void { return self.InitLineFont(a0); });
cls_IGESData_IGESEntity.def("InitLineFont", (void (IGESData_IGESEntity::*)(const opencascade::handle<IGESData_LineFontEntity> &, const Standard_Integer)) &IGESData_IGESEntity::InitLineFont, "Initializes LineFont : if <ent> is not Null, it gives LineFont, else <rank> gives or erases (if zero) RankLineFont", py::arg("ent"), py::arg("rank"));
cls_IGESData_IGESEntity.def("InitLevel", [](IGESData_IGESEntity &self, const opencascade::handle<IGESData_LevelListEntity> & a0) -> void { return self.InitLevel(a0); });
cls_IGESData_IGESEntity.def("InitLevel", (void (IGESData_IGESEntity::*)(const opencascade::handle<IGESData_LevelListEntity> &, const Standard_Integer)) &IGESData_IGESEntity::InitLevel, "Initializes Level : if <ent> is not Null, it gives LevelList, else <val> gives or erases (if zero) unique Level", py::arg("ent"), py::arg("val"));
cls_IGESData_IGESEntity.def("InitColor", [](IGESData_IGESEntity &self, const opencascade::handle<IGESData_ColorEntity> & a0) -> void { return self.InitColor(a0); });
cls_IGESData_IGESEntity.def("InitColor", (void (IGESData_IGESEntity::*)(const opencascade::handle<IGESData_ColorEntity> &, const Standard_Integer)) &IGESData_IGESEntity::InitColor, "Initializes Color data : if <ent> is not Null, it gives Color, else <rank> gives or erases (if zero) RankColor", py::arg("ent"), py::arg("rank"));
cls_IGESData_IGESEntity.def("InitStatus", (void (IGESData_IGESEntity::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &IGESData_IGESEntity::InitStatus, "Initializes the Status of Directory Part", py::arg("blank"), py::arg("subordinate"), py::arg("useflag"), py::arg("hierarchy"));
cls_IGESData_IGESEntity.def("SetLabel", [](IGESData_IGESEntity &self, const opencascade::handle<TCollection_HAsciiString> & a0) -> void { return self.SetLabel(a0); });
cls_IGESData_IGESEntity.def("SetLabel", (void (IGESData_IGESEntity::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer)) &IGESData_IGESEntity::SetLabel, "Sets a new Label to an IGES Entity If is given, it sets value of SubScriptNumber else, SubScriptNumber is erased", py::arg("label"), py::arg("sub"));
cls_IGESData_IGESEntity.def("InitMisc", (void (IGESData_IGESEntity::*)(const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_LabelDisplayEntity> &, const Standard_Integer)) &IGESData_IGESEntity::InitMisc, "Initializes various data (those not yet seen above), or erases them if they are given as Null (Zero for <weightnum>) : <str> for Structure, <lab> for LabelDisplay, and <weightnum> for WeightNumber", py::arg("str"), py::arg("lab"), py::arg("weightnum"));
cls_IGESData_IGESEntity.def("HasOneParent", (Standard_Boolean (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::HasOneParent, "Returns True if an entity has one and only one parent, defined by a SingleParentEntity Type Associativity (explicit sharing). Thus, implicit sharing remains defined at model level (see class ToolLocation)");
cls_IGESData_IGESEntity.def("UniqueParent", (opencascade::handle<IGESData_IGESEntity> (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::UniqueParent, "Returns the Unique Parent (in the sense given by HasOneParent) Error if there is none or several");
cls_IGESData_IGESEntity.def("Location", (gp_GTrsf (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::Location, "Returns Location given by Transf in Directory Part (see above) It must be considered for local definition : if the Entity is set in a 'Parent', that one can add its one Location, but this is not taken in account here : see CompoundLocation for that. If no Transf is defined, returns Identity If Transf is itself compound, gives the final result");
cls_IGESData_IGESEntity.def("VectorLocation", (gp_GTrsf (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::VectorLocation, "Returns Location considered for Vectors, i.e. without its Translation Part. As Location, it gives local definition.");
cls_IGESData_IGESEntity.def("CompoundLocation", (gp_GTrsf (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::CompoundLocation, "Returns Location by taking in account a Parent which has its own Location : that one will be combined to that of <me> The Parent is considered only if HasOneParent is True, else it is ignored and CompoundLocation = Location");
cls_IGESData_IGESEntity.def("HasName", (Standard_Boolean (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::HasName, "says if a Name is defined, as Short Label or as Name Property (Property is looked first, else ShortLabel is considered)");
cls_IGESData_IGESEntity.def("NameValue", (opencascade::handle<TCollection_HAsciiString> (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::NameValue, "returns Name value as a String (Property Name or ShortLabel) if SubNumber is defined, it is concatenated after ShortLabel as follows label(number). Ignored with a Property Name");
cls_IGESData_IGESEntity.def("ArePresentAssociativities", (Standard_Boolean (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::ArePresentAssociativities, "Returns True if the Entity is defined with an Associativity list, even empty (that is, file contains its length 0) Else, the file contained NO idencation at all about this list.");
cls_IGESData_IGESEntity.def("NbAssociativities", (Standard_Integer (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::NbAssociativities, "gives number of recorded associativities (0 no list defined)");
cls_IGESData_IGESEntity.def("Associativities", (Interface_EntityIterator (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::Associativities, "Returns the Associativity List under the form of an EntityIterator.");
cls_IGESData_IGESEntity.def("NbTypedAssociativities", (Standard_Integer (IGESData_IGESEntity::*)(const opencascade::handle<Standard_Type> &) const) &IGESData_IGESEntity::NbTypedAssociativities, "gives how many Associativities have a given type", py::arg("atype"));
cls_IGESData_IGESEntity.def("TypedAssociativity", (opencascade::handle<IGESData_IGESEntity> (IGESData_IGESEntity::*)(const opencascade::handle<Standard_Type> &) const) &IGESData_IGESEntity::TypedAssociativity, "returns the Associativity of a given Type (if only one exists) Error if none or more than one", py::arg("atype"));
cls_IGESData_IGESEntity.def("Associate", (void (IGESData_IGESEntity::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_IGESEntity::Associate, "Sets 'me' in the Associativity list of another Entity", py::arg("ent"));
cls_IGESData_IGESEntity.def("Dissociate", (void (IGESData_IGESEntity::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_IGESEntity::Dissociate, "Resets 'me' from the Associativity list of another Entity", py::arg("ent"));
cls_IGESData_IGESEntity.def("ArePresentProperties", (Standard_Boolean (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::ArePresentProperties, "Returns True if the Entity is defined with a Property list, even empty (that is, file contains its length 0) Else, the file contained NO idencation at all about this list");
cls_IGESData_IGESEntity.def("NbProperties", (Standard_Integer (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::NbProperties, "Gives number of recorded properties (0 no list defined)");
cls_IGESData_IGESEntity.def("Properties", (Interface_EntityIterator (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::Properties, "Returns Property List under the form of an EntityIterator");
cls_IGESData_IGESEntity.def("NbTypedProperties", (Standard_Integer (IGESData_IGESEntity::*)(const opencascade::handle<Standard_Type> &) const) &IGESData_IGESEntity::NbTypedProperties, "gives how many Properties have a given type", py::arg("atype"));
cls_IGESData_IGESEntity.def("TypedProperty", [](IGESData_IGESEntity &self, const opencascade::handle<Standard_Type> & a0) -> opencascade::handle<IGESData_IGESEntity> { return self.TypedProperty(a0); });
cls_IGESData_IGESEntity.def("TypedProperty", (opencascade::handle<IGESData_IGESEntity> (IGESData_IGESEntity::*)(const opencascade::handle<Standard_Type> &, const Standard_Integer) const) &IGESData_IGESEntity::TypedProperty, "returns the Property of a given Type Error if none or more than one", py::arg("atype"), py::arg("anum"));
cls_IGESData_IGESEntity.def("AddProperty", (void (IGESData_IGESEntity::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESData_IGESEntity::AddProperty, "Adds a Property in the list", py::arg("ent"));
cls_IGESData_IGESEntity.def("RemoveProperty", (void (IGESData_IGESEntity::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESData_IGESEntity::RemoveProperty, "Removes a Property from the list", py::arg("ent"));
cls_IGESData_IGESEntity.def("SetLineWeight", (void (IGESData_IGESEntity::*)(const Standard_Real, const Standard_Real, const Standard_Integer)) &IGESData_IGESEntity::SetLineWeight, "computes and sets 'true' line weight according IGES rules from global data MaxLineWeight (maxv) and LineWeightGrad (gradw), or sets it to defw (Default) if LineWeightNumber is null", py::arg("defw"), py::arg("maxw"), py::arg("gradw"));
cls_IGESData_IGESEntity.def_static("get_type_name_", (const char * (*)()) &IGESData_IGESEntity::get_type_name, "None");
cls_IGESData_IGESEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_IGESEntity::get_type_descriptor, "None");
cls_IGESData_IGESEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_IGESEntity::*)() const) &IGESData_IGESEntity::DynamicType, "None");

// TYPEDEF: IGESDATA_ARRAY1OFIGESENTITY
bind_NCollection_Array1<opencascade::handle<IGESData_IGESEntity> >(mod, "IGESData_Array1OfIGESEntity", py::module_local(false));

// CLASS: IGESDATA_HARRAY1OFIGESENTITY
py::class_<IGESData_HArray1OfIGESEntity, opencascade::handle<IGESData_HArray1OfIGESEntity>, Standard_Transient> cls_IGESData_HArray1OfIGESEntity(mod, "IGESData_HArray1OfIGESEntity", "None", py::multiple_inheritance());

// Constructors
cls_IGESData_HArray1OfIGESEntity.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_IGESData_HArray1OfIGESEntity.def(py::init<const Standard_Integer, const Standard_Integer, const IGESData_Array1OfIGESEntity::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_IGESData_HArray1OfIGESEntity.def(py::init<const IGESData_Array1OfIGESEntity &>(), py::arg("theOther"));

// Methods
// cls_IGESData_HArray1OfIGESEntity.def_static("operator new_", (void * (*)(size_t)) &IGESData_HArray1OfIGESEntity::operator new, "None", py::arg("theSize"));
// cls_IGESData_HArray1OfIGESEntity.def_static("operator delete_", (void (*)(void *)) &IGESData_HArray1OfIGESEntity::operator delete, "None", py::arg("theAddress"));
// cls_IGESData_HArray1OfIGESEntity.def_static("operator new[]_", (void * (*)(size_t)) &IGESData_HArray1OfIGESEntity::operator new[], "None", py::arg("theSize"));
// cls_IGESData_HArray1OfIGESEntity.def_static("operator delete[]_", (void (*)(void *)) &IGESData_HArray1OfIGESEntity::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData_HArray1OfIGESEntity.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData_HArray1OfIGESEntity::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData_HArray1OfIGESEntity.def_static("operator delete_", (void (*)(void *, void *)) &IGESData_HArray1OfIGESEntity::operator delete, "None", py::arg(""), py::arg(""));
// cls_IGESData_HArray1OfIGESEntity.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &IGESData_HArray1OfIGESEntity::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_IGESData_HArray1OfIGESEntity.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &IGESData_HArray1OfIGESEntity::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_IGESData_HArray1OfIGESEntity.def("Array1", (const IGESData_Array1OfIGESEntity & (IGESData_HArray1OfIGESEntity::*)() const) &IGESData_HArray1OfIGESEntity::Array1, "None");
cls_IGESData_HArray1OfIGESEntity.def("ChangeArray1", (IGESData_Array1OfIGESEntity & (IGESData_HArray1OfIGESEntity::*)()) &IGESData_HArray1OfIGESEntity::ChangeArray1, "None");
cls_IGESData_HArray1OfIGESEntity.def_static("get_type_name_", (const char * (*)()) &IGESData_HArray1OfIGESEntity::get_type_name, "None");
cls_IGESData_HArray1OfIGESEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_HArray1OfIGESEntity::get_type_descriptor, "None");
cls_IGESData_HArray1OfIGESEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_HArray1OfIGESEntity::*)() const) &IGESData_HArray1OfIGESEntity::DynamicType, "None");

// CLASS: IGESDATA_GENERALMODULE
py::class_<IGESData_GeneralModule, opencascade::handle<IGESData_GeneralModule>, Interface_GeneralModule> cls_IGESData_GeneralModule(mod, "IGESData_GeneralModule", "Definition of General Services adapted to IGES. This Services comprise : Shared & Implied Lists, Copy, Check They are adapted according to the organisation of IGES Entities : Directory Part, Lists of Associativities and Properties are specifically processed");

// Methods
cls_IGESData_GeneralModule.def("FillSharedCase", (void (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, Interface_EntityIterator &) const) &IGESData_GeneralModule::FillSharedCase, "Fills the list of Entities shared by an IGESEntity <ent>, according a Case Number <CN> (formerly computed by CaseNum). Considers Properties and Directory Part, and calls OwnSharedCase (which is adapted to each Type of Entity)", py::arg("CN"), py::arg("ent"), py::arg("iter"));
cls_IGESData_GeneralModule.def("OwnSharedCase", (void (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, Interface_EntityIterator &) const) &IGESData_GeneralModule::OwnSharedCase, "Lists the Entities shared by a given IGESEntity <ent>, from its specific parameters : specific for each type", py::arg("CN"), py::arg("ent"), py::arg("iter"));
cls_IGESData_GeneralModule.def("ListImpliedCase", (void (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, Interface_EntityIterator &) const) &IGESData_GeneralModule::ListImpliedCase, "Lists the Implied References of <ent>. Here, these are the Associativities, plus the Entities defined by OwnSharedCase", py::arg("CN"), py::arg("ent"), py::arg("iter"));
cls_IGESData_GeneralModule.def("OwnImpliedCase", (void (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, Interface_EntityIterator &) const) &IGESData_GeneralModule::OwnImpliedCase, "Specific list of Entities implied by a given IGESEntity <ent> (in addition to Associativities). By default, there are none, but this method can be redefined as required", py::arg("CN"), py::arg("ent"), py::arg("iter"));
cls_IGESData_GeneralModule.def("CheckCase", (void (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESData_GeneralModule::CheckCase, "Semantic Checking of an IGESEntity. Performs general Checks, which use DirChecker, then call OwnCheck which does a check specific for each type of Entity", py::arg("CN"), py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESData_GeneralModule.def("DirChecker", (IGESData_DirChecker (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_GeneralModule::DirChecker, "Returns a DirChecker, specific for each type of Entity (identified by its Case Number) : this DirChecker defines constraints which must be respected by the DirectoryPart", py::arg("CN"), py::arg("ent"));
cls_IGESData_GeneralModule.def("OwnCheckCase", (void (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESData_GeneralModule::OwnCheckCase, "Performs Specific Semantic Check for each type of Entity", py::arg("CN"), py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESData_GeneralModule.def("CanCopy", (Standard_Boolean (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &) const) &IGESData_GeneralModule::CanCopy, "Specific answer to the question 'is Copy properly implemented' For IGES, answer is always True", py::arg("CN"), py::arg("ent"));
cls_IGESData_GeneralModule.def("NewVoid", (Standard_Boolean (IGESData_GeneralModule::*)(const Standard_Integer, opencascade::handle<Standard_Transient> &) const) &IGESData_GeneralModule::NewVoid, "Specific creation of a new void entity", py::arg("CN"), py::arg("entto"));
cls_IGESData_GeneralModule.def("CopyCase", (void (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &, Interface_CopyTool &) const) &IGESData_GeneralModule::CopyCase, "Copy ('Deep') from <entfrom> to <entto> (same type) by using a CopyTool which provides its working Map. For IGESEntities, Copies general data (Directory Part, List of Properties) and call OwnCopyCase", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESData_GeneralModule.def("OwnCopyCase", (void (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESEntity> &, Interface_CopyTool &) const) &IGESData_GeneralModule::OwnCopyCase, "Copies parameters which are specific of each Type of Entity", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESData_GeneralModule.def("RenewImpliedCase", (void (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &, const Interface_CopyTool &) const) &IGESData_GeneralModule::RenewImpliedCase, "Renewing of Implied References. For IGESEntities, Copies general data(List of Associativities) and calls OwnRenewCase", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESData_GeneralModule.def("OwnRenewCase", (void (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESEntity> &, const Interface_CopyTool &) const) &IGESData_GeneralModule::OwnRenewCase, "Renews parameters which are specific of each Type of Entity : the provided default does nothing, but this method may be redefined as required", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESData_GeneralModule.def("WhenDeleteCase", (void (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Standard_Boolean) const) &IGESData_GeneralModule::WhenDeleteCase, "Prepares an IGES Entity for delete : works on directory part then calls OwnDeleteCase While dispatch requires to copy the entities, <dispatched> is ignored, entities are cleared in any case", py::arg("CN"), py::arg("ent"), py::arg("dispatched"));
cls_IGESData_GeneralModule.def("OwnDeleteCase", (void (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_GeneralModule::OwnDeleteCase, "Specific preparation for delete, acts on own parameters Default does nothing, to be redefined as required", py::arg("CN"), py::arg("ent"));
cls_IGESData_GeneralModule.def("Name", (opencascade::handle<TCollection_HAsciiString> (IGESData_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &) const) &IGESData_GeneralModule::Name, "Returns the name of an IGES Entity (its NameValue) Can be redefined for an even more specific case ...", py::arg("CN"), py::arg("ent"), py::arg("shares"));
cls_IGESData_GeneralModule.def_static("get_type_name_", (const char * (*)()) &IGESData_GeneralModule::get_type_name, "None");
cls_IGESData_GeneralModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_GeneralModule::get_type_descriptor, "None");
cls_IGESData_GeneralModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_GeneralModule::*)() const) &IGESData_GeneralModule::DynamicType, "None");

// CLASS: IGESDATA_PROTOCOL
py::class_<IGESData_Protocol, opencascade::handle<IGESData_Protocol>, Interface_Protocol> cls_IGESData_Protocol(mod, "IGESData_Protocol", "Description of basic Protocol for IGES This comprises treatement of IGESModel and Recognition of Undefined-FreeFormat-Entity");

// Constructors
cls_IGESData_Protocol.def(py::init<>());

// Methods
cls_IGESData_Protocol.def("NbResources", (Standard_Integer (IGESData_Protocol::*)() const) &IGESData_Protocol::NbResources, "Gives the count of Resource Protocol. Here, none");
cls_IGESData_Protocol.def("Resource", (opencascade::handle<Interface_Protocol> (IGESData_Protocol::*)(const Standard_Integer) const) &IGESData_Protocol::Resource, "Returns a Resource, given a rank. Here, none", py::arg("num"));
cls_IGESData_Protocol.def("TypeNumber", (Standard_Integer (IGESData_Protocol::*)(const opencascade::handle<Standard_Type> &) const) &IGESData_Protocol::TypeNumber, "Returns a Case Number, specific of each recognized Type Here, Undefined and Free Format Entities have the Number 1.", py::arg("atype"));
cls_IGESData_Protocol.def("NewModel", (opencascade::handle<Interface_InterfaceModel> (IGESData_Protocol::*)() const) &IGESData_Protocol::NewModel, "Creates an empty Model for IGES Norm");
cls_IGESData_Protocol.def("IsSuitableModel", (Standard_Boolean (IGESData_Protocol::*)(const opencascade::handle<Interface_InterfaceModel> &) const) &IGESData_Protocol::IsSuitableModel, "Returns True if <model> is a Model of IGES Norm", py::arg("model"));
cls_IGESData_Protocol.def("UnknownEntity", (opencascade::handle<Standard_Transient> (IGESData_Protocol::*)() const) &IGESData_Protocol::UnknownEntity, "Creates a new Unknown Entity for IGES (UndefinedEntity)");
cls_IGESData_Protocol.def("IsUnknownEntity", (Standard_Boolean (IGESData_Protocol::*)(const opencascade::handle<Standard_Transient> &) const) &IGESData_Protocol::IsUnknownEntity, "Returns True if <ent> is an Unknown Entity for the Norm, i.e. Type UndefinedEntity, status Unknown", py::arg("ent"));
cls_IGESData_Protocol.def_static("get_type_name_", (const char * (*)()) &IGESData_Protocol::get_type_name, "None");
cls_IGESData_Protocol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_Protocol::get_type_descriptor, "None");
cls_IGESData_Protocol.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_Protocol::*)() const) &IGESData_Protocol::DynamicType, "None");

// CLASS: IGESDATA_READWRITEMODULE
py::class_<IGESData_ReadWriteModule, opencascade::handle<IGESData_ReadWriteModule>, Interface_ReaderModule> cls_IGESData_ReadWriteModule(mod, "IGESData_ReadWriteModule", "Defines basic File Access Module, under the control of IGESReaderTool for Reading and IGESWriter for Writing : Specific actions concern : Read and Write Own Parameters of an IGESEntity. The common parts (Directory Entry, Lists of Associativities and Properties) are processed by IGESReaderTool & IGESWriter");

// Methods
cls_IGESData_ReadWriteModule.def("CaseNum", (Standard_Integer (IGESData_ReadWriteModule::*)(const opencascade::handle<Interface_FileReaderData> &, const Standard_Integer) const) &IGESData_ReadWriteModule::CaseNum, "Translates the Type of record <num> in <data> to a positive Case Number, or 0 if failed. Works with IGESReaderData which provides Type & Form Numbers, and calls CaseIGES (see below)", py::arg("data"), py::arg("num"));
cls_IGESData_ReadWriteModule.def("CaseIGES", (Standard_Integer (IGESData_ReadWriteModule::*)(const Standard_Integer, const Standard_Integer) const) &IGESData_ReadWriteModule::CaseIGES, "Defines Case Numbers corresponding to the Entity Types taken into account by a sub-class of ReadWriteModule (hence, each sub-class of ReadWriteModule has to redefine this method) Called by CaseNum. Its result will then be used to call Read, etc ...", py::arg("typenum"), py::arg("formnum"));
cls_IGESData_ReadWriteModule.def("Read", (void (IGESData_ReadWriteModule::*)(const Standard_Integer, const opencascade::handle<Interface_FileReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<Standard_Transient> &) const) &IGESData_ReadWriteModule::Read, "General Read Function. See IGESReaderTool for more info", py::arg("CN"), py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_IGESData_ReadWriteModule.def("ReadOwnParams", (void (IGESData_ReadWriteModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESData_ReadWriteModule::ReadOwnParams, "Reads own parameters from file for an Entity; <PR> gives access to them, <IR> detains parameter types and values For each class, there must be a specific action provided Note that Properties and Associativities Lists are Read by specific methods (see below), they are called under control of reading process (only one call) according Stage recorded in ParamReader", py::arg("CN"), py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESData_ReadWriteModule.def("WriteOwnParams", (void (IGESData_ReadWriteModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, IGESData_IGESWriter &) const) &IGESData_ReadWriteModule::WriteOwnParams, "Writes own parameters to IGESWriter; defined for each class (to be redefined for other IGES ReadWriteModules) Warning : Properties and Associativities are directly managed by WriteIGES, must not be sent by this method", py::arg("CN"), py::arg("ent"), py::arg("IW"));
cls_IGESData_ReadWriteModule.def_static("get_type_name_", (const char * (*)()) &IGESData_ReadWriteModule::get_type_name, "None");
cls_IGESData_ReadWriteModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_ReadWriteModule::get_type_descriptor, "None");
cls_IGESData_ReadWriteModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_ReadWriteModule::*)() const) &IGESData_ReadWriteModule::DynamicType, "None");

// CLASS: IGESDATA_SPECIFICMODULE
py::class_<IGESData_SpecificModule, opencascade::handle<IGESData_SpecificModule>, Standard_Transient> cls_IGESData_SpecificModule(mod, "IGESData_SpecificModule", "This class defines some Services which are specifically attached to IGES Entities : Dump");

// Methods
cls_IGESData_SpecificModule.def("OwnDump", (void (IGESData_SpecificModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESData_SpecificModule::OwnDump, "Specific Dump for each type of IGES Entity : it concerns only own parameters, the general data (Directory Part, Lists) are taken into account by the IGESDumper See class IGESDumper for the rules to follow for <own> and <attached> level", py::arg("CN"), py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));
cls_IGESData_SpecificModule.def("OwnCorrect", (Standard_Boolean (IGESData_SpecificModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_SpecificModule::OwnCorrect, "Specific Automatic Correction on own Parameters of an Entity. It works by setting in accordance redundant data, if there are when there is no ambiguity (else, it does nothing). Remark that classic Corrections on Directory Entry (to set void data) are taken into account alsewhere.", py::arg("CN"), py::arg("ent"));
cls_IGESData_SpecificModule.def_static("get_type_name_", (const char * (*)()) &IGESData_SpecificModule::get_type_name, "None");
cls_IGESData_SpecificModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_SpecificModule::get_type_descriptor, "None");
cls_IGESData_SpecificModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_SpecificModule::*)() const) &IGESData_SpecificModule::DynamicType, "None");

// CLASS: IGESDATA_LINEFONTENTITY
py::class_<IGESData_LineFontEntity, opencascade::handle<IGESData_LineFontEntity>, IGESData_IGESEntity> cls_IGESData_LineFontEntity(mod, "IGESData_LineFontEntity", "defines required type for LineFont in directory part an effective LineFont entity must inherits it");

// Methods
cls_IGESData_LineFontEntity.def_static("get_type_name_", (const char * (*)()) &IGESData_LineFontEntity::get_type_name, "None");
cls_IGESData_LineFontEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_LineFontEntity::get_type_descriptor, "None");
cls_IGESData_LineFontEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_LineFontEntity::*)() const) &IGESData_LineFontEntity::DynamicType, "None");

// CLASS: IGESDATA_NAMEENTITY
py::class_<IGESData_NameEntity, opencascade::handle<IGESData_NameEntity>, IGESData_IGESEntity> cls_IGESData_NameEntity(mod, "IGESData_NameEntity", "a NameEntity is a kind of IGESEntity which can provide a Name under alphanumeric (String) form, from Properties list an effective Name entity must inherit it");

// Methods
cls_IGESData_NameEntity.def("Value", (opencascade::handle<TCollection_HAsciiString> (IGESData_NameEntity::*)() const) &IGESData_NameEntity::Value, "Retyrns the alphanumeric value of the Name, to be defined");
cls_IGESData_NameEntity.def_static("get_type_name_", (const char * (*)()) &IGESData_NameEntity::get_type_name, "None");
cls_IGESData_NameEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_NameEntity::get_type_descriptor, "None");
cls_IGESData_NameEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_NameEntity::*)() const) &IGESData_NameEntity::DynamicType, "None");

// CLASS: IGESDATA_SINGLEPARENTENTITY
py::class_<IGESData_SingleParentEntity, opencascade::handle<IGESData_SingleParentEntity>, IGESData_IGESEntity> cls_IGESData_SingleParentEntity(mod, "IGESData_SingleParentEntity", "a SingleParentEntity is a kind of IGESEntity which can refer to a (Single) Parent, from Associativities list of an Entity a effective SingleParent definition entity must inherit it");

// Methods
cls_IGESData_SingleParentEntity.def("SingleParent", (opencascade::handle<IGESData_IGESEntity> (IGESData_SingleParentEntity::*)() const) &IGESData_SingleParentEntity::SingleParent, "Returns the parent designated by the Entity, if only one !");
cls_IGESData_SingleParentEntity.def("NbChildren", (Standard_Integer (IGESData_SingleParentEntity::*)() const) &IGESData_SingleParentEntity::NbChildren, "Returns the count of Entities designated as children");
cls_IGESData_SingleParentEntity.def("Child", (opencascade::handle<IGESData_IGESEntity> (IGESData_SingleParentEntity::*)(const Standard_Integer) const) &IGESData_SingleParentEntity::Child, "Returns a Child given its rank", py::arg("num"));
cls_IGESData_SingleParentEntity.def_static("get_type_name_", (const char * (*)()) &IGESData_SingleParentEntity::get_type_name, "None");
cls_IGESData_SingleParentEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_SingleParentEntity::get_type_descriptor, "None");
cls_IGESData_SingleParentEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_SingleParentEntity::*)() const) &IGESData_SingleParentEntity::DynamicType, "None");

// CLASS: IGESDATA_SPECIFICLIB
py::class_<IGESData_SpecificLib> cls_IGESData_SpecificLib(mod, "IGESData_SpecificLib", "None");

// Constructors
cls_IGESData_SpecificLib.def(py::init<const opencascade::handle<IGESData_Protocol> &>(), py::arg("aprotocol"));
cls_IGESData_SpecificLib.def(py::init<>());

// Methods
// cls_IGESData_SpecificLib.def_static("operator new_", (void * (*)(size_t)) &IGESData_SpecificLib::operator new, "None", py::arg("theSize"));
// cls_IGESData_SpecificLib.def_static("operator delete_", (void (*)(void *)) &IGESData_SpecificLib::operator delete, "None", py::arg("theAddress"));
// cls_IGESData_SpecificLib.def_static("operator new[]_", (void * (*)(size_t)) &IGESData_SpecificLib::operator new[], "None", py::arg("theSize"));
// cls_IGESData_SpecificLib.def_static("operator delete[]_", (void (*)(void *)) &IGESData_SpecificLib::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData_SpecificLib.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData_SpecificLib::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData_SpecificLib.def_static("operator delete_", (void (*)(void *, void *)) &IGESData_SpecificLib::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESData_SpecificLib.def_static("SetGlobal_", (void (*)(const opencascade::handle<IGESData_SpecificModule> &, const opencascade::handle<IGESData_Protocol> &)) &IGESData_SpecificLib::SetGlobal, "Adds a couple (Module-Protocol) into the global definition set for this class of Library.", py::arg("amodule"), py::arg("aprotocol"));
cls_IGESData_SpecificLib.def("AddProtocol", (void (IGESData_SpecificLib::*)(const opencascade::handle<Standard_Transient> &)) &IGESData_SpecificLib::AddProtocol, "Adds a couple (Module-Protocol) to the Library, given the class of a Protocol. Takes Resources into account. (if <aprotocol> is not of type TheProtocol, it is not added)", py::arg("aprotocol"));
cls_IGESData_SpecificLib.def("Clear", (void (IGESData_SpecificLib::*)()) &IGESData_SpecificLib::Clear, "Clears the list of Modules of a library (can be used to redefine the order of Modules before action : Clear then refill the Library by calls to AddProtocol)");
cls_IGESData_SpecificLib.def("SetComplete", (void (IGESData_SpecificLib::*)()) &IGESData_SpecificLib::SetComplete, "Sets a library to be defined with the complete Global list (all the couples Protocol/Modules recorded in it)");
cls_IGESData_SpecificLib.def("Select", [](IGESData_SpecificLib &self, const opencascade::handle<IGESData_IGESEntity> & obj, opencascade::handle<IGESData_SpecificModule> & module, Standard_Integer & CN){ Standard_Boolean rv = self.Select(obj, module, CN); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, CN); }, "Selects a Module from the Library, given an Object. Returns True if Select has succeeded, False else. Also Returns (as arguments) the selected Module and the Case Number determined by the associated Protocol. If Select has failed, <module> is Null Handle and CN is zero. (Select can work on any criterium, such as Object DynamicType)", py::arg("obj"), py::arg("module"), py::arg("CN"));
cls_IGESData_SpecificLib.def("Start", (void (IGESData_SpecificLib::*)()) &IGESData_SpecificLib::Start, "Starts Iteration on the Modules (sets it on the first one)");
cls_IGESData_SpecificLib.def("More", (Standard_Boolean (IGESData_SpecificLib::*)() const) &IGESData_SpecificLib::More, "Returns True if there are more Modules to iterate on");
cls_IGESData_SpecificLib.def("Next", (void (IGESData_SpecificLib::*)()) &IGESData_SpecificLib::Next, "Iterates by getting the next Module in the list If there is none, the exception will be raised by Value");
cls_IGESData_SpecificLib.def("Module", (const opencascade::handle<IGESData_SpecificModule> & (IGESData_SpecificLib::*)() const) &IGESData_SpecificLib::Module, "Returns the current Module in the Iteration");
cls_IGESData_SpecificLib.def("Protocol", (const opencascade::handle<IGESData_Protocol> & (IGESData_SpecificLib::*)() const) &IGESData_SpecificLib::Protocol, "Returns the current Protocol in the Iteration");

// CLASS: IGESDATA_BASICEDITOR
py::class_<IGESData_BasicEditor> cls_IGESData_BasicEditor(mod, "IGESData_BasicEditor", "This class provides various functions of basic edition, such as : - setting header unit (WARNING : DOES NOT convert entities) - computation of the status (Subordinate, UseFlag) of entities of IGES Entities on a whole model - auto correction of IGES Entities, defined both by DirChecker and by specific service AutoCorrect (this auto correction performs non-ambigious, rather logic, editions)");

// Constructors
cls_IGESData_BasicEditor.def(py::init<>());
cls_IGESData_BasicEditor.def(py::init<const opencascade::handle<IGESData_Protocol> &>(), py::arg("protocol"));
cls_IGESData_BasicEditor.def(py::init<const opencascade::handle<IGESData_IGESModel> &, const opencascade::handle<IGESData_Protocol> &>(), py::arg("model"), py::arg("protocol"));

// Methods
// cls_IGESData_BasicEditor.def_static("operator new_", (void * (*)(size_t)) &IGESData_BasicEditor::operator new, "None", py::arg("theSize"));
// cls_IGESData_BasicEditor.def_static("operator delete_", (void (*)(void *)) &IGESData_BasicEditor::operator delete, "None", py::arg("theAddress"));
// cls_IGESData_BasicEditor.def_static("operator new[]_", (void * (*)(size_t)) &IGESData_BasicEditor::operator new[], "None", py::arg("theSize"));
// cls_IGESData_BasicEditor.def_static("operator delete[]_", (void (*)(void *)) &IGESData_BasicEditor::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData_BasicEditor.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData_BasicEditor::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData_BasicEditor.def_static("operator delete_", (void (*)(void *, void *)) &IGESData_BasicEditor::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESData_BasicEditor.def("Init", (void (IGESData_BasicEditor::*)(const opencascade::handle<IGESData_Protocol> &)) &IGESData_BasicEditor::Init, "Initialize a Basic Editor, with a new IGESModel, ready to run", py::arg("protocol"));
cls_IGESData_BasicEditor.def("Init", (void (IGESData_BasicEditor::*)(const opencascade::handle<IGESData_IGESModel> &, const opencascade::handle<IGESData_Protocol> &)) &IGESData_BasicEditor::Init, "Initialize a Basic Editor for IGES Data, ready to run", py::arg("model"), py::arg("protocol"));
cls_IGESData_BasicEditor.def("Model", (opencascade::handle<IGESData_IGESModel> (IGESData_BasicEditor::*)() const) &IGESData_BasicEditor::Model, "Returns the designated model");
cls_IGESData_BasicEditor.def("SetUnitFlag", (Standard_Boolean (IGESData_BasicEditor::*)(const Standard_Integer)) &IGESData_BasicEditor::SetUnitFlag, "Sets a new unit from its flag (param 14 of Global Section) Returns True if done, False if <flag> is incorrect", py::arg("flag"));
cls_IGESData_BasicEditor.def("SetUnitValue", (Standard_Boolean (IGESData_BasicEditor::*)(const Standard_Real)) &IGESData_BasicEditor::SetUnitValue, "Sets a new unit from its value in meters (rounded to the closest one, max gap 1%) Returns True if done, False if <val> is too far from a suitable value", py::arg("val"));
cls_IGESData_BasicEditor.def("SetUnitName", (Standard_Boolean (IGESData_BasicEditor::*)(const Standard_CString)) &IGESData_BasicEditor::SetUnitName, "Sets a new unit from its name (param 15 of Global Section) Returns True if done, False if <name> is incorrect Remark : if <flag> has been set to 3 (user defined), <name> is then free", py::arg("name"));
cls_IGESData_BasicEditor.def("ApplyUnit", [](IGESData_BasicEditor &self) -> void { return self.ApplyUnit(); });
cls_IGESData_BasicEditor.def("ApplyUnit", (void (IGESData_BasicEditor::*)(const Standard_Boolean)) &IGESData_BasicEditor::ApplyUnit, "Applies unit value to convert header data : Resolution, MaxCoord, MaxLineWeight Applies unit only once after SetUnit... has been called, if <enforce> is given as True. It can be called just before writing the model to a file, i.e. when definitive values are finally known", py::arg("enforce"));
cls_IGESData_BasicEditor.def("ComputeStatus", (void (IGESData_BasicEditor::*)()) &IGESData_BasicEditor::ComputeStatus, "Performs the re-computation of status on the whole model (Subordinate Status and Use Flag of each IGES Entity), which can have required values according the way they are referenced (see definitions of Logical use, Physical use, etc...)");
cls_IGESData_BasicEditor.def("AutoCorrect", (Standard_Boolean (IGESData_BasicEditor::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESData_BasicEditor::AutoCorrect, "Performs auto-correction on an IGESEntity Returns True if something has changed, False if nothing done.", py::arg("ent"));
cls_IGESData_BasicEditor.def("AutoCorrectModel", (Standard_Integer (IGESData_BasicEditor::*)()) &IGESData_BasicEditor::AutoCorrectModel, "Performs auto-correction on the whole Model Returns the count of modified entities");
cls_IGESData_BasicEditor.def_static("UnitNameFlag_", (Standard_Integer (*)(const Standard_CString)) &IGESData_BasicEditor::UnitNameFlag, "From the name of unit, computes flag number, 0 if incorrect (in this case, user defined entity remains possible)", py::arg("name"));
cls_IGESData_BasicEditor.def_static("UnitFlagValue_", (Standard_Real (*)(const Standard_Integer)) &IGESData_BasicEditor::UnitFlagValue, "From the flag of unit, determines value in MM, 0 if incorrect", py::arg("flag"));
cls_IGESData_BasicEditor.def_static("UnitFlagName_", (Standard_CString (*)(const Standard_Integer)) &IGESData_BasicEditor::UnitFlagName, "From the flag of unit, determines its name, '' if incorrect", py::arg("flag"));
cls_IGESData_BasicEditor.def_static("IGESVersionName_", (Standard_CString (*)(const Standard_Integer)) &IGESData_BasicEditor::IGESVersionName, "From the flag of IGES version, returns name, '' if incorrect", py::arg("flag"));
cls_IGESData_BasicEditor.def_static("IGESVersionMax_", (Standard_Integer (*)()) &IGESData_BasicEditor::IGESVersionMax, "Returns the maximum allowed value for IGESVersion Flag");
cls_IGESData_BasicEditor.def_static("DraftingName_", (Standard_CString (*)(const Standard_Integer)) &IGESData_BasicEditor::DraftingName, "From the flag of drafting standard, returns name, '' if incorrect", py::arg("flag"));
cls_IGESData_BasicEditor.def_static("DraftingMax_", (Standard_Integer (*)()) &IGESData_BasicEditor::DraftingMax, "Returns the maximum allowed value for Drafting Flag");

// CLASS: IGESDATA
py::class_<IGESData> cls_IGESData(mod, "IGESData", "basic description of an IGES Interface");

// Methods
// cls_IGESData.def_static("operator new_", (void * (*)(size_t)) &IGESData::operator new, "None", py::arg("theSize"));
// cls_IGESData.def_static("operator delete_", (void (*)(void *)) &IGESData::operator delete, "None", py::arg("theAddress"));
// cls_IGESData.def_static("operator new[]_", (void * (*)(size_t)) &IGESData::operator new[], "None", py::arg("theSize"));
// cls_IGESData.def_static("operator delete[]_", (void (*)(void *)) &IGESData::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData.def_static("operator delete_", (void (*)(void *, void *)) &IGESData::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESData.def_static("Init_", (void (*)()) &IGESData::Init, "Prepares General dynamic data used for IGESData specifically : Protocol and Modules, which treat UndefinedEntity");
cls_IGESData.def_static("Protocol_", (opencascade::handle<IGESData_Protocol> (*)()) &IGESData::Protocol, "Returns a Protocol from IGESData (avoids to create it)");

// CLASS: IGESDATA_DIRPART
py::class_<IGESData_DirPart> cls_IGESData_DirPart(mod, "IGESData_DirPart", "litteral/numeric description of an entity's directory section, taken from file");

// Constructors
cls_IGESData_DirPart.def(py::init<>());

// Methods
// cls_IGESData_DirPart.def_static("operator new_", (void * (*)(size_t)) &IGESData_DirPart::operator new, "None", py::arg("theSize"));
// cls_IGESData_DirPart.def_static("operator delete_", (void (*)(void *)) &IGESData_DirPart::operator delete, "None", py::arg("theAddress"));
// cls_IGESData_DirPart.def_static("operator new[]_", (void * (*)(size_t)) &IGESData_DirPart::operator new[], "None", py::arg("theSize"));
// cls_IGESData_DirPart.def_static("operator delete[]_", (void (*)(void *)) &IGESData_DirPart::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData_DirPart.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData_DirPart::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData_DirPart.def_static("operator delete_", (void (*)(void *, void *)) &IGESData_DirPart::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESData_DirPart.def("Init", (void (IGESData_DirPart::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_CString, const Standard_CString, const Standard_CString, const Standard_CString)) &IGESData_DirPart::Init, "fills DirPart with consistant data read from file", py::arg("i1"), py::arg("i2"), py::arg("i3"), py::arg("i4"), py::arg("i5"), py::arg("i6"), py::arg("i7"), py::arg("i8"), py::arg("i9"), py::arg("i19"), py::arg("i11"), py::arg("i12"), py::arg("i13"), py::arg("i14"), py::arg("i15"), py::arg("i16"), py::arg("i17"), py::arg("res1"), py::arg("res2"), py::arg("label"), py::arg("subscript"));
cls_IGESData_DirPart.def("Values", [](IGESData_DirPart &self, Standard_Integer & i1, Standard_Integer & i2, Standard_Integer & i3, Standard_Integer & i4, Standard_Integer & i5, Standard_Integer & i6, Standard_Integer & i7, Standard_Integer & i8, Standard_Integer & i9, Standard_Integer & i19, Standard_Integer & i11, Standard_Integer & i12, Standard_Integer & i13, Standard_Integer & i14, Standard_Integer & i15, Standard_Integer & i16, Standard_Integer & i17, const Standard_CString res1, const Standard_CString res2, const Standard_CString label, const Standard_CString subscript){ self.Values(i1, i2, i3, i4, i5, i6, i7, i8, i9, i19, i11, i12, i13, i14, i15, i16, i17, res1, res2, label, subscript); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(i1, i2, i3, i4, i5, i6, i7, i8, i9, i19, i11, i12, i13, i14, i15, i16, i17); }, "returns values recorded in DirPart (content of cstrings are modified)", py::arg("i1"), py::arg("i2"), py::arg("i3"), py::arg("i4"), py::arg("i5"), py::arg("i6"), py::arg("i7"), py::arg("i8"), py::arg("i9"), py::arg("i19"), py::arg("i11"), py::arg("i12"), py::arg("i13"), py::arg("i14"), py::arg("i15"), py::arg("i16"), py::arg("i17"), py::arg("res1"), py::arg("res2"), py::arg("label"), py::arg("subscript"));
cls_IGESData_DirPart.def("Type", (IGESData_IGESType (IGESData_DirPart::*)() const) &IGESData_DirPart::Type, "returns 'type' and 'form' info, used to recognize the entity");

// TYPEDEF: IGESDATA_ARRAY1OFDIRPART
bind_NCollection_Array1<IGESData_DirPart>(mod, "IGESData_Array1OfDirPart", py::module_local(false));

// CLASS: IGESDATA_COLORENTITY
py::class_<IGESData_ColorEntity, opencascade::handle<IGESData_ColorEntity>, IGESData_IGESEntity> cls_IGESData_ColorEntity(mod, "IGESData_ColorEntity", "defines required type for Color in directory part an effective Color entity must inherits it");

// Methods
cls_IGESData_ColorEntity.def_static("get_type_name_", (const char * (*)()) &IGESData_ColorEntity::get_type_name, "None");
cls_IGESData_ColorEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_ColorEntity::get_type_descriptor, "None");
cls_IGESData_ColorEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_ColorEntity::*)() const) &IGESData_ColorEntity::DynamicType, "None");

// CLASS: IGESDATA_DEFAULTGENERAL
py::class_<IGESData_DefaultGeneral, opencascade::handle<IGESData_DefaultGeneral>, IGESData_GeneralModule> cls_IGESData_DefaultGeneral(mod, "IGESData_DefaultGeneral", "Processes the specific case of UndefinedEntity from IGESData (Case Number 1)");

// Constructors
cls_IGESData_DefaultGeneral.def(py::init<>());

// Methods
cls_IGESData_DefaultGeneral.def("OwnSharedCase", (void (IGESData_DefaultGeneral::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, Interface_EntityIterator &) const) &IGESData_DefaultGeneral::OwnSharedCase, "Lists the Entities shared by an IGESEntity, which must be an UndefinedEntity", py::arg("CN"), py::arg("ent"), py::arg("iter"));
cls_IGESData_DefaultGeneral.def("DirChecker", (IGESData_DirChecker (IGESData_DefaultGeneral::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_DefaultGeneral::DirChecker, "Returns a DirChecker, specific for each type of Entity Here, Returns an empty DirChecker (no constraint to check)", py::arg("CN"), py::arg("ent"));
cls_IGESData_DefaultGeneral.def("OwnCheckCase", (void (IGESData_DefaultGeneral::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESData_DefaultGeneral::OwnCheckCase, "Performs Specific Semantic Check for each type of Entity Here, does nothing (no constraint to check)", py::arg("CN"), py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESData_DefaultGeneral.def("NewVoid", (Standard_Boolean (IGESData_DefaultGeneral::*)(const Standard_Integer, opencascade::handle<Standard_Transient> &) const) &IGESData_DefaultGeneral::NewVoid, "Specific creation of a new void entity (UndefinedEntity only)", py::arg("CN"), py::arg("entto"));
cls_IGESData_DefaultGeneral.def("OwnCopyCase", (void (IGESData_DefaultGeneral::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESEntity> &, Interface_CopyTool &) const) &IGESData_DefaultGeneral::OwnCopyCase, "Copies parameters which are specific of each Type of Entity", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESData_DefaultGeneral.def_static("get_type_name_", (const char * (*)()) &IGESData_DefaultGeneral::get_type_name, "None");
cls_IGESData_DefaultGeneral.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_DefaultGeneral::get_type_descriptor, "None");
cls_IGESData_DefaultGeneral.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_DefaultGeneral::*)() const) &IGESData_DefaultGeneral::DynamicType, "None");

// CLASS: IGESDATA_DEFAULTSPECIFIC
py::class_<IGESData_DefaultSpecific, opencascade::handle<IGESData_DefaultSpecific>, IGESData_SpecificModule> cls_IGESData_DefaultSpecific(mod, "IGESData_DefaultSpecific", "Specific IGES Services for UndefinedEntity, FreeFormatEntity");

// Constructors
cls_IGESData_DefaultSpecific.def(py::init<>());

// Methods
cls_IGESData_DefaultSpecific.def("OwnDump", (void (IGESData_DefaultSpecific::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESData_DefaultSpecific::OwnDump, "Specific Dump for UndefinedEntity : it concerns only own parameters, the general data (Directory Part, Lists) are taken into account by the IGESDumper", py::arg("CN"), py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));
cls_IGESData_DefaultSpecific.def_static("get_type_name_", (const char * (*)()) &IGESData_DefaultSpecific::get_type_name, "None");
cls_IGESData_DefaultSpecific.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_DefaultSpecific::get_type_descriptor, "None");
cls_IGESData_DefaultSpecific.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_DefaultSpecific::*)() const) &IGESData_DefaultSpecific::DynamicType, "None");

// CLASS: IGESDATA_DIRCHECKER
py::class_<IGESData_DirChecker> cls_IGESData_DirChecker(mod, "IGESData_DirChecker", "This class centralizes general Checks upon an IGES Entity's Directory Part. That is : such field Ignored or Required, or Required with a given Value (for an Integer field) More precise checks can be performed as necessary, by each Entity (method OwnCheck).");

// Constructors
cls_IGESData_DirChecker.def(py::init<>());
cls_IGESData_DirChecker.def(py::init<const Standard_Integer>(), py::arg("atype"));
cls_IGESData_DirChecker.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("atype"), py::arg("aform"));
cls_IGESData_DirChecker.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("atype"), py::arg("aform1"), py::arg("aform2"));

// Methods
// cls_IGESData_DirChecker.def_static("operator new_", (void * (*)(size_t)) &IGESData_DirChecker::operator new, "None", py::arg("theSize"));
// cls_IGESData_DirChecker.def_static("operator delete_", (void (*)(void *)) &IGESData_DirChecker::operator delete, "None", py::arg("theAddress"));
// cls_IGESData_DirChecker.def_static("operator new[]_", (void * (*)(size_t)) &IGESData_DirChecker::operator new[], "None", py::arg("theSize"));
// cls_IGESData_DirChecker.def_static("operator delete[]_", (void (*)(void *)) &IGESData_DirChecker::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData_DirChecker.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData_DirChecker::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData_DirChecker.def_static("operator delete_", (void (*)(void *, void *)) &IGESData_DirChecker::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESData_DirChecker.def("IsSet", (Standard_Boolean (IGESData_DirChecker::*)() const) &IGESData_DirChecker::IsSet, "Returns True if at least one criterium has already been set Allows user to store a DirChecker (static variable) then ask if it has been set before setting it");
cls_IGESData_DirChecker.def("SetDefault", (void (IGESData_DirChecker::*)()) &IGESData_DirChecker::SetDefault, "Sets a DirChecker with most current criteria, that is : Structure Ignored ( worths call Structure(crit = DefVoid) )");
cls_IGESData_DirChecker.def("Structure", (void (IGESData_DirChecker::*)(const IGESData_DefType)) &IGESData_DirChecker::Structure, "Sets Structure criterium. If crit is DefVoid, Ignored : should not be defined If crit is DefReference, Required : must be defined Other values are not taken in account", py::arg("crit"));
cls_IGESData_DirChecker.def("LineFont", (void (IGESData_DirChecker::*)(const IGESData_DefType)) &IGESData_DirChecker::LineFont, "Sets LineFont criterium If crit is DefVoid, Ignored : should not be defined If crit is DefAny, Required : must be defined (value or ref) If crit is DefValue, Required as a Value (error if Reference) Other values are not taken in account", py::arg("crit"));
cls_IGESData_DirChecker.def("LineWeight", (void (IGESData_DirChecker::*)(const IGESData_DefType)) &IGESData_DirChecker::LineWeight, "Sets LineWeight criterium If crit is DefVoid, Ignored : should not be defined If crit is DefValue, Required Other values are not taken in account", py::arg("crit"));
cls_IGESData_DirChecker.def("Color", (void (IGESData_DirChecker::*)(const IGESData_DefType)) &IGESData_DirChecker::Color, "Sets Color criterium If crit is DefVoid, Ignored : should not be defined If crit is DefAny, Required : must be defined (value or ref) Other values are not taken in account", py::arg("crit"));
cls_IGESData_DirChecker.def("GraphicsIgnored", [](IGESData_DirChecker &self) -> void { return self.GraphicsIgnored(); });
cls_IGESData_DirChecker.def("GraphicsIgnored", (void (IGESData_DirChecker::*)(const Standard_Integer)) &IGESData_DirChecker::GraphicsIgnored, "Sets Graphics data (LineFont, LineWeight, Color, Level, View) to be ignored according value of Hierarchy status : If hierarchy is not given, they are Ignored any way (that is, they should not be defined) If hierarchy is given, Graphics are Ignored if the Hierarchy status has the value given in argument 'hierarchy'", py::arg("hierarchy"));
cls_IGESData_DirChecker.def("BlankStatusIgnored", (void (IGESData_DirChecker::*)()) &IGESData_DirChecker::BlankStatusIgnored, "Sets Blank Status to be ignored (should not be defined, or its value should be 0)");
cls_IGESData_DirChecker.def("BlankStatusRequired", (void (IGESData_DirChecker::*)(const Standard_Integer)) &IGESData_DirChecker::BlankStatusRequired, "Sets Blank Status to be required at a given value", py::arg("val"));
cls_IGESData_DirChecker.def("SubordinateStatusIgnored", (void (IGESData_DirChecker::*)()) &IGESData_DirChecker::SubordinateStatusIgnored, "Sets Subordinate Status to be ignored (should not be defined, or its value should be 0)");
cls_IGESData_DirChecker.def("SubordinateStatusRequired", (void (IGESData_DirChecker::*)(const Standard_Integer)) &IGESData_DirChecker::SubordinateStatusRequired, "Sets Subordinate Status to be required at a given value", py::arg("val"));
cls_IGESData_DirChecker.def("UseFlagIgnored", (void (IGESData_DirChecker::*)()) &IGESData_DirChecker::UseFlagIgnored, "Sets Blank Status to be ignored (should not be defined, or its value should be 0)");
cls_IGESData_DirChecker.def("UseFlagRequired", (void (IGESData_DirChecker::*)(const Standard_Integer)) &IGESData_DirChecker::UseFlagRequired, "Sets Blank Status to be required at a given value Give -1 to demand UseFlag not zero (but no precise value req.)", py::arg("val"));
cls_IGESData_DirChecker.def("HierarchyStatusIgnored", (void (IGESData_DirChecker::*)()) &IGESData_DirChecker::HierarchyStatusIgnored, "Sets Hierarchy Status to be ignored (should not be defined, or its value should be 0)");
cls_IGESData_DirChecker.def("HierarchyStatusRequired", (void (IGESData_DirChecker::*)(const Standard_Integer)) &IGESData_DirChecker::HierarchyStatusRequired, "Sets Hierarchy Status to be required at a given value", py::arg("val"));
cls_IGESData_DirChecker.def("Check", (void (IGESData_DirChecker::*)(opencascade::handle<Interface_Check> &, const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_DirChecker::Check, "Performs the Checks on an IGESEntity, according to the recorded criteria In addition, does minimal Checks, such as admitted range for Status, or presence of Error status in some data (Color, ...)", py::arg("ach"), py::arg("ent"));
cls_IGESData_DirChecker.def("CheckTypeAndForm", (void (IGESData_DirChecker::*)(opencascade::handle<Interface_Check> &, const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_DirChecker::CheckTypeAndForm, "Performs a Check only on Values of Type Number and Form Number This allows to do a check on an Entity not yet completely filled but of which Type and Form Number have been already set", py::arg("ach"), py::arg("ent"));
cls_IGESData_DirChecker.def("Correct", (Standard_Boolean (IGESData_DirChecker::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_DirChecker::Correct, "Corrects the Directory Entry of an IGES Entity as far as it is possible according recorded criteria without any ambiguity : - if a numeric Status is required a given value, this value is enforced - if an item is required to be Void, or if it recorded as Erroneous, it is cleared (set to Void) - Type Number is enforced - finally Form Number is enforced only if one and only Value is admitted (no range, see Constructors of DirChecker)", py::arg("ent"));

// CLASS: IGESDATA_FILEPROTOCOL
py::class_<IGESData_FileProtocol, opencascade::handle<IGESData_FileProtocol>, IGESData_Protocol> cls_IGESData_FileProtocol(mod, "IGESData_FileProtocol", "This class allows to define complex protocols, in order to treat various sub-sets (or the complete set) of the IGES Norm, such as Solid + Draw (which are normally independant), etc... While it inherits Protocol from IGESData, it admits UndefinedEntity too");

// Constructors
cls_IGESData_FileProtocol.def(py::init<>());

// Methods
cls_IGESData_FileProtocol.def("Add", (void (IGESData_FileProtocol::*)(const opencascade::handle<IGESData_Protocol> &)) &IGESData_FileProtocol::Add, "Adds a resource", py::arg("protocol"));
cls_IGESData_FileProtocol.def("NbResources", (Standard_Integer (IGESData_FileProtocol::*)() const) &IGESData_FileProtocol::NbResources, "Gives the count of Resources : the count of Added Protocols");
cls_IGESData_FileProtocol.def("Resource", (opencascade::handle<Interface_Protocol> (IGESData_FileProtocol::*)(const Standard_Integer) const) &IGESData_FileProtocol::Resource, "Returns a Resource, given a rank (rank of call to Add)", py::arg("num"));
cls_IGESData_FileProtocol.def_static("get_type_name_", (const char * (*)()) &IGESData_FileProtocol::get_type_name, "None");
cls_IGESData_FileProtocol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_FileProtocol::get_type_descriptor, "None");
cls_IGESData_FileProtocol.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_FileProtocol::*)() const) &IGESData_FileProtocol::DynamicType, "None");

// CLASS: IGESDATA_FILERECOGNIZER
py::class_<IGESData_FileRecognizer, opencascade::handle<IGESData_FileRecognizer>, Standard_Transient> cls_IGESData_FileRecognizer(mod, "IGESData_FileRecognizer", "None");

// Methods
cls_IGESData_FileRecognizer.def("Evaluate", (Standard_Boolean (IGESData_FileRecognizer::*)(const IGESData_IGESType &, opencascade::handle<IGESData_IGESEntity> &)) &IGESData_FileRecognizer::Evaluate, "Evaluates if recognition has a result, returns it if yes In case of success, Returns True and puts result in 'res' In case of Failure, simply Returns False Works by calling deferred method Eval, and in case of failure, looks for Added Recognizers to work", py::arg("akey"), py::arg("res"));
cls_IGESData_FileRecognizer.def("Result", (opencascade::handle<IGESData_IGESEntity> (IGESData_FileRecognizer::*)() const) &IGESData_FileRecognizer::Result, "Returns result of last recognition (call of Evaluate)");
cls_IGESData_FileRecognizer.def("Add", (void (IGESData_FileRecognizer::*)(const opencascade::handle<IGESData_FileRecognizer> &)) &IGESData_FileRecognizer::Add, "Adds a new Recognizer to the Compound, at the end Several calls to Add work by adding in the order of calls : Hence, when Eval has failed to recognize, Evaluate will call Evaluate from the first added Recognizer if there is one, and to the second if there is still no result, and so on", py::arg("reco"));
cls_IGESData_FileRecognizer.def_static("get_type_name_", (const char * (*)()) &IGESData_FileRecognizer::get_type_name, "None");
cls_IGESData_FileRecognizer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_FileRecognizer::get_type_descriptor, "None");
cls_IGESData_FileRecognizer.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_FileRecognizer::*)() const) &IGESData_FileRecognizer::DynamicType, "None");

// CLASS: IGESDATA_UNDEFINEDENTITY
py::class_<IGESData_UndefinedEntity, opencascade::handle<IGESData_UndefinedEntity>, IGESData_IGESEntity> cls_IGESData_UndefinedEntity(mod, "IGESData_UndefinedEntity", "undefined (unknown or error) entity specific of IGES DirPart can be correct or not : if it is not, a flag indicates it, and each corrupted field has an associated error flag");

// Constructors
cls_IGESData_UndefinedEntity.def(py::init<>());

// Methods
cls_IGESData_UndefinedEntity.def("UndefinedContent", (opencascade::handle<Interface_UndefinedContent> (IGESData_UndefinedEntity::*)() const) &IGESData_UndefinedEntity::UndefinedContent, "Returns own data as an UndefinedContent");
cls_IGESData_UndefinedEntity.def("ChangeableContent", (opencascade::handle<Interface_UndefinedContent> (IGESData_UndefinedEntity::*)()) &IGESData_UndefinedEntity::ChangeableContent, "Returns own data as an UndefinedContent, in order to touch it");
cls_IGESData_UndefinedEntity.def("SetNewContent", (void (IGESData_UndefinedEntity::*)(const opencascade::handle<Interface_UndefinedContent> &)) &IGESData_UndefinedEntity::SetNewContent, "Redefines a completely new UndefinedContent Used by a Copy which begins by ShallowCopy, for instance", py::arg("cont"));
cls_IGESData_UndefinedEntity.def("IsOKDirPart", (Standard_Boolean (IGESData_UndefinedEntity::*)() const) &IGESData_UndefinedEntity::IsOKDirPart, "says if DirPart is OK or not (if not, it is erroneous) Note that if it is not, Def* methods can return Error status");
cls_IGESData_UndefinedEntity.def("DirStatus", (Standard_Integer (IGESData_UndefinedEntity::*)() const) &IGESData_UndefinedEntity::DirStatus, "returns Directory Error Status (used for Copy)");
cls_IGESData_UndefinedEntity.def("SetOKDirPart", (void (IGESData_UndefinedEntity::*)()) &IGESData_UndefinedEntity::SetOKDirPart, "Erases the Directory Error Status Warning : Be sure that data are consistent to call this method ...");
cls_IGESData_UndefinedEntity.def("DefLineFont", (IGESData_DefType (IGESData_UndefinedEntity::*)() const) &IGESData_UndefinedEntity::DefLineFont, "returns Error status if necessary, else calls original method");
cls_IGESData_UndefinedEntity.def("DefLevel", (IGESData_DefList (IGESData_UndefinedEntity::*)() const) &IGESData_UndefinedEntity::DefLevel, "returns Error status if necessary, else calls original method");
cls_IGESData_UndefinedEntity.def("DefView", (IGESData_DefList (IGESData_UndefinedEntity::*)() const) &IGESData_UndefinedEntity::DefView, "returns Error status if necessary, else calls original method");
cls_IGESData_UndefinedEntity.def("DefColor", (IGESData_DefType (IGESData_UndefinedEntity::*)() const) &IGESData_UndefinedEntity::DefColor, "returns Error status if necessary, else calls original method");
cls_IGESData_UndefinedEntity.def("HasSubScriptNumber", (Standard_Boolean (IGESData_UndefinedEntity::*)() const) &IGESData_UndefinedEntity::HasSubScriptNumber, "returns Error status if necessary, else calls original method (that is, if SubScript field is not blank or positive integer)");
cls_IGESData_UndefinedEntity.def("ReadDir", (Standard_Boolean (IGESData_UndefinedEntity::*)(const opencascade::handle<IGESData_IGESReaderData> &, IGESData_DirPart &, opencascade::handle<Interface_Check> &)) &IGESData_UndefinedEntity::ReadDir, "Computes the Directory Error Status, to be called before standard ReadDir from IGESReaderTool Returns True if OK (hence, Directory can be loaded), Else returns False and the DirPart <DP> is modified (hence, Directory Error Status is non null; and standard Read will work with an acceptable DirectoryPart)", py::arg("IR"), py::arg("DP"), py::arg("ach"));
cls_IGESData_UndefinedEntity.def("ReadOwnParams", (void (IGESData_UndefinedEntity::*)(const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &)) &IGESData_UndefinedEntity::ReadOwnParams, "reads own parameters from file; PR gives access to them, IR detains parameter types and values Here, reads all parameters, integers are considered as entity reference unless they cannot be; no list interpretation No property or associativity list is managed", py::arg("IR"), py::arg("PR"));
cls_IGESData_UndefinedEntity.def("WriteOwnParams", (void (IGESData_UndefinedEntity::*)(IGESData_IGESWriter &) const) &IGESData_UndefinedEntity::WriteOwnParams, "writes parameters to IGESWriter, taken from UndefinedContent", py::arg("IW"));
cls_IGESData_UndefinedEntity.def_static("get_type_name_", (const char * (*)()) &IGESData_UndefinedEntity::get_type_name, "None");
cls_IGESData_UndefinedEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_UndefinedEntity::get_type_descriptor, "None");
cls_IGESData_UndefinedEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_UndefinedEntity::*)() const) &IGESData_UndefinedEntity::DynamicType, "None");

// CLASS: IGESDATA_FREEFORMATENTITY
py::class_<IGESData_FreeFormatEntity, opencascade::handle<IGESData_FreeFormatEntity>, IGESData_UndefinedEntity> cls_IGESData_FreeFormatEntity(mod, "IGESData_FreeFormatEntity", "This class allows to create IGES Entities in a literal form : their definition is free, but they are not recognized as instances of specific classes.");

// Constructors
cls_IGESData_FreeFormatEntity.def(py::init<>());

// Methods
cls_IGESData_FreeFormatEntity.def("SetTypeNumber", (void (IGESData_FreeFormatEntity::*)(const Standard_Integer)) &IGESData_FreeFormatEntity::SetTypeNumber, "Sets Type Number to a new Value, and Form Number to Zero", py::arg("typenum"));
cls_IGESData_FreeFormatEntity.def("SetFormNumber", (void (IGESData_FreeFormatEntity::*)(const Standard_Integer)) &IGESData_FreeFormatEntity::SetFormNumber, "Sets Form Number to a new Value (to called after SetTypeNumber)", py::arg("formnum"));
cls_IGESData_FreeFormatEntity.def("NbParams", (Standard_Integer (IGESData_FreeFormatEntity::*)() const) &IGESData_FreeFormatEntity::NbParams, "Gives count of recorded parameters");
cls_IGESData_FreeFormatEntity.def("ParamData", (Standard_Boolean (IGESData_FreeFormatEntity::*)(const Standard_Integer, Interface_ParamType &, opencascade::handle<IGESData_IGESEntity> &, opencascade::handle<TCollection_HAsciiString> &) const) &IGESData_FreeFormatEntity::ParamData, "Returns data of a Parameter : its type, and the entity if it designates en entity ('ent') or its literal value else ('str') Returned value (Boolean) : True if it is an Entity, False else", py::arg("num"), py::arg("ptype"), py::arg("ent"), py::arg("val"));
cls_IGESData_FreeFormatEntity.def("ParamType", (Interface_ParamType (IGESData_FreeFormatEntity::*)(const Standard_Integer) const) &IGESData_FreeFormatEntity::ParamType, "Returns the ParamType of a Param, given its rank Error if num is not between 1 and NbParams", py::arg("num"));
cls_IGESData_FreeFormatEntity.def("IsParamEntity", (Standard_Boolean (IGESData_FreeFormatEntity::*)(const Standard_Integer) const) &IGESData_FreeFormatEntity::IsParamEntity, "Returns True if a Parameter is recorded as an entity Error if num is not between 1 and NbParams", py::arg("num"));
cls_IGESData_FreeFormatEntity.def("ParamEntity", (opencascade::handle<IGESData_IGESEntity> (IGESData_FreeFormatEntity::*)(const Standard_Integer) const) &IGESData_FreeFormatEntity::ParamEntity, "Returns Entity corresponding to a Param, given its rank Error if out of range or if Param num does not designate an Entity", py::arg("num"));
cls_IGESData_FreeFormatEntity.def("IsNegativePointer", (Standard_Boolean (IGESData_FreeFormatEntity::*)(const Standard_Integer) const) &IGESData_FreeFormatEntity::IsNegativePointer, "Returns True if <num> is noted as for a 'Negative Pointer' (see AddEntity for details). Senseful only if IsParamEntity answers True for <num>, else returns False.", py::arg("num"));
cls_IGESData_FreeFormatEntity.def("ParamValue", (opencascade::handle<TCollection_HAsciiString> (IGESData_FreeFormatEntity::*)(const Standard_Integer) const) &IGESData_FreeFormatEntity::ParamValue, "Returns litteral value of a Parameter, given its rank Error if num is out of range, or if Parameter is not literal", py::arg("num"));
cls_IGESData_FreeFormatEntity.def("NegativePointers", (opencascade::handle<TColStd_HSequenceOfInteger> (IGESData_FreeFormatEntity::*)() const) &IGESData_FreeFormatEntity::NegativePointers, "Returns the complete list of Ramks of Parameters which have been noted as Negative Pointers Warning : It is returned as a Null Handle if none was noted");
cls_IGESData_FreeFormatEntity.def("AddLiteral", (void (IGESData_FreeFormatEntity::*)(const Interface_ParamType, const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_FreeFormatEntity::AddLiteral, "Adds a literal Parameter to the list (as such)", py::arg("ptype"), py::arg("val"));
cls_IGESData_FreeFormatEntity.def("AddLiteral", (void (IGESData_FreeFormatEntity::*)(const Interface_ParamType, const Standard_CString)) &IGESData_FreeFormatEntity::AddLiteral, "Adds a literal Parameter to the list (builds an HAsciiString)", py::arg("ptype"), py::arg("val"));
cls_IGESData_FreeFormatEntity.def("AddEntity", [](IGESData_FreeFormatEntity &self, const Interface_ParamType a0, const opencascade::handle<IGESData_IGESEntity> & a1) -> void { return self.AddEntity(a0, a1); });
cls_IGESData_FreeFormatEntity.def("AddEntity", (void (IGESData_FreeFormatEntity::*)(const Interface_ParamType, const opencascade::handle<IGESData_IGESEntity> &, const Standard_Boolean)) &IGESData_FreeFormatEntity::AddEntity, "Adds a Parameter which references an Entity. If the Entity is Null, the added parameter will define a 'Null Pointer' (0) If <negative> is given True, this will command Sending to File (see IGESWriter) to produce a 'Negative Pointer' (Default is False)", py::arg("ptype"), py::arg("ent"), py::arg("negative"));
cls_IGESData_FreeFormatEntity.def("AddEntities", (void (IGESData_FreeFormatEntity::*)(const opencascade::handle<IGESData_HArray1OfIGESEntity> &)) &IGESData_FreeFormatEntity::AddEntities, "Adds a set of Entities, given as a HArray1OfIGESEntity Causes creation of : an Integer Parameter which gives count of Entities, then the list of Entities of the Array Error if an Entity is not an IGESEntity All these Entities will be interpreted as 'Positive Pointers' by IGESWriter", py::arg("ents"));
cls_IGESData_FreeFormatEntity.def("AddNegativePointers", (void (IGESData_FreeFormatEntity::*)(const opencascade::handle<TColStd_HSequenceOfInteger> &)) &IGESData_FreeFormatEntity::AddNegativePointers, "Adds a list of Ranks of Parameters to be noted as Negative Pointers (this will be taken into account for Parameters which are Entities)", py::arg("list"));
cls_IGESData_FreeFormatEntity.def("ClearNegativePointers", (void (IGESData_FreeFormatEntity::*)()) &IGESData_FreeFormatEntity::ClearNegativePointers, "Clears all informations about Negative Pointers, hence every Entity kind Parameter will be send normally, as Positive");
cls_IGESData_FreeFormatEntity.def("WriteOwnParams", (void (IGESData_FreeFormatEntity::*)(IGESData_IGESWriter &) const) &IGESData_FreeFormatEntity::WriteOwnParams, "WriteOwnParams is redefined for FreeFormatEntity to take into account the supplementary information 'Negative Pointer'", py::arg("IW"));
cls_IGESData_FreeFormatEntity.def_static("get_type_name_", (const char * (*)()) &IGESData_FreeFormatEntity::get_type_name, "None");
cls_IGESData_FreeFormatEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_FreeFormatEntity::get_type_descriptor, "None");
cls_IGESData_FreeFormatEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_FreeFormatEntity::*)() const) &IGESData_FreeFormatEntity::DynamicType, "None");

// CLASS: IGESDATA_GLOBALNODEOFSPECIFICLIB
py::class_<IGESData_GlobalNodeOfSpecificLib, opencascade::handle<IGESData_GlobalNodeOfSpecificLib>, Standard_Transient> cls_IGESData_GlobalNodeOfSpecificLib(mod, "IGESData_GlobalNodeOfSpecificLib", "None");

// Constructors
cls_IGESData_GlobalNodeOfSpecificLib.def(py::init<>());

// Methods
cls_IGESData_GlobalNodeOfSpecificLib.def("Add", (void (IGESData_GlobalNodeOfSpecificLib::*)(const opencascade::handle<IGESData_SpecificModule> &, const opencascade::handle<IGESData_Protocol> &)) &IGESData_GlobalNodeOfSpecificLib::Add, "Adds a Module bound with a Protocol to the list : does nothing if already in the list, THAT IS, Same Type (exact match) and Same State (that is, IsEqual is not required) Once added, stores its attached Protocol in correspondance", py::arg("amodule"), py::arg("aprotocol"));
cls_IGESData_GlobalNodeOfSpecificLib.def("Module", (const opencascade::handle<IGESData_SpecificModule> & (IGESData_GlobalNodeOfSpecificLib::*)() const) &IGESData_GlobalNodeOfSpecificLib::Module, "Returns the Module stored in a given GlobalNode");
cls_IGESData_GlobalNodeOfSpecificLib.def("Protocol", (const opencascade::handle<IGESData_Protocol> & (IGESData_GlobalNodeOfSpecificLib::*)() const) &IGESData_GlobalNodeOfSpecificLib::Protocol, "Returns the attached Protocol stored in a given GlobalNode");
cls_IGESData_GlobalNodeOfSpecificLib.def("Next", (const opencascade::handle<IGESData_GlobalNodeOfSpecificLib> & (IGESData_GlobalNodeOfSpecificLib::*)() const) &IGESData_GlobalNodeOfSpecificLib::Next, "Returns the Next GlobalNode. If none is defined, returned value is a Null Handle");
cls_IGESData_GlobalNodeOfSpecificLib.def_static("get_type_name_", (const char * (*)()) &IGESData_GlobalNodeOfSpecificLib::get_type_name, "None");
cls_IGESData_GlobalNodeOfSpecificLib.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_GlobalNodeOfSpecificLib::get_type_descriptor, "None");
cls_IGESData_GlobalNodeOfSpecificLib.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_GlobalNodeOfSpecificLib::*)() const) &IGESData_GlobalNodeOfSpecificLib::DynamicType, "None");

// CLASS: IGESDATA_GLOBALNODEOFWRITERLIB
py::class_<IGESData_GlobalNodeOfWriterLib, opencascade::handle<IGESData_GlobalNodeOfWriterLib>, Standard_Transient> cls_IGESData_GlobalNodeOfWriterLib(mod, "IGESData_GlobalNodeOfWriterLib", "None");

// Constructors
cls_IGESData_GlobalNodeOfWriterLib.def(py::init<>());

// Methods
cls_IGESData_GlobalNodeOfWriterLib.def("Add", (void (IGESData_GlobalNodeOfWriterLib::*)(const opencascade::handle<IGESData_ReadWriteModule> &, const opencascade::handle<IGESData_Protocol> &)) &IGESData_GlobalNodeOfWriterLib::Add, "Adds a Module bound with a Protocol to the list : does nothing if already in the list, THAT IS, Same Type (exact match) and Same State (that is, IsEqual is not required) Once added, stores its attached Protocol in correspondance", py::arg("amodule"), py::arg("aprotocol"));
cls_IGESData_GlobalNodeOfWriterLib.def("Module", (const opencascade::handle<IGESData_ReadWriteModule> & (IGESData_GlobalNodeOfWriterLib::*)() const) &IGESData_GlobalNodeOfWriterLib::Module, "Returns the Module stored in a given GlobalNode");
cls_IGESData_GlobalNodeOfWriterLib.def("Protocol", (const opencascade::handle<IGESData_Protocol> & (IGESData_GlobalNodeOfWriterLib::*)() const) &IGESData_GlobalNodeOfWriterLib::Protocol, "Returns the attached Protocol stored in a given GlobalNode");
cls_IGESData_GlobalNodeOfWriterLib.def("Next", (const opencascade::handle<IGESData_GlobalNodeOfWriterLib> & (IGESData_GlobalNodeOfWriterLib::*)() const) &IGESData_GlobalNodeOfWriterLib::Next, "Returns the Next GlobalNode. If none is defined, returned value is a Null Handle");
cls_IGESData_GlobalNodeOfWriterLib.def_static("get_type_name_", (const char * (*)()) &IGESData_GlobalNodeOfWriterLib::get_type_name, "None");
cls_IGESData_GlobalNodeOfWriterLib.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_GlobalNodeOfWriterLib::get_type_descriptor, "None");
cls_IGESData_GlobalNodeOfWriterLib.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_GlobalNodeOfWriterLib::*)() const) &IGESData_GlobalNodeOfWriterLib::DynamicType, "None");

// CLASS: IGESDATA_GLOBALSECTION
py::class_<IGESData_GlobalSection> cls_IGESData_GlobalSection(mod, "IGESData_GlobalSection", "Description of a global section (corresponds to file header) used as well in IGESModel, IGESReader and IGESWriter Warning : From IGES-5.1, a parameter is added : LastChangeDate (concerns transferred set of data, not the file itself) Of course, it can be absent if read from earlier versions (a default is then to be set to current date) From 5.3, one more : ApplicationProtocol (optional)");

// Constructors
cls_IGESData_GlobalSection.def(py::init<>());

// Methods
// cls_IGESData_GlobalSection.def_static("operator new_", (void * (*)(size_t)) &IGESData_GlobalSection::operator new, "None", py::arg("theSize"));
// cls_IGESData_GlobalSection.def_static("operator delete_", (void (*)(void *)) &IGESData_GlobalSection::operator delete, "None", py::arg("theAddress"));
// cls_IGESData_GlobalSection.def_static("operator new[]_", (void * (*)(size_t)) &IGESData_GlobalSection::operator new[], "None", py::arg("theSize"));
// cls_IGESData_GlobalSection.def_static("operator delete[]_", (void (*)(void *)) &IGESData_GlobalSection::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData_GlobalSection.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData_GlobalSection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData_GlobalSection.def_static("operator delete_", (void (*)(void *, void *)) &IGESData_GlobalSection::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESData_GlobalSection.def("Init", (void (IGESData_GlobalSection::*)(const opencascade::handle<Interface_ParamSet> &, opencascade::handle<Interface_Check> &)) &IGESData_GlobalSection::Init, "Fills GlobalSection from a ParamSet (i.e. taken from file) undefined parameters do not change default values when defined Fills Check about Corrections or Fails", py::arg("params"), py::arg("ach"));
cls_IGESData_GlobalSection.def("CopyRefs", (void (IGESData_GlobalSection::*)()) &IGESData_GlobalSection::CopyRefs, "Copies data referenced by Handle (that is, Strings) usefull to 'isolate' a GlobalSection after copy by '=' (from a Model to another Model for instance)");
cls_IGESData_GlobalSection.def("Params", (opencascade::handle<Interface_ParamSet> (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::Params, "Returns all contained data in the form of a ParamSet Remark : Strings are given under Hollerith form");
cls_IGESData_GlobalSection.def("TranslatedFromHollerith", (opencascade::handle<TCollection_HAsciiString> (IGESData_GlobalSection::*)(const opencascade::handle<TCollection_HAsciiString> &) const) &IGESData_GlobalSection::TranslatedFromHollerith, "Returns a string withpout its Hollerith marks (nnnH ahead). Remark : all strings stored in GlobalSection are expurged from Hollerith informations (without nnnH) If <astr> is not Hollerith form, it is simply copied", py::arg("astr"));
cls_IGESData_GlobalSection.def("Separator", (Standard_Character (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::Separator, "Returns the parameter delimiter character.");
cls_IGESData_GlobalSection.def("EndMark", (Standard_Character (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::EndMark, "Returns the record delimiter character.");
cls_IGESData_GlobalSection.def("SendName", (opencascade::handle<TCollection_HAsciiString> (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::SendName, "Returns the name of the sending system.");
cls_IGESData_GlobalSection.def("FileName", (opencascade::handle<TCollection_HAsciiString> (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::FileName, "Returns the name of the IGES file.");
cls_IGESData_GlobalSection.def("SystemId", (opencascade::handle<TCollection_HAsciiString> (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::SystemId, "Returns the Native System ID of the system that created the IGES file.");
cls_IGESData_GlobalSection.def("InterfaceVersion", (opencascade::handle<TCollection_HAsciiString> (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::InterfaceVersion, "Returns the name of the pre-processor used to write the IGES file.");
cls_IGESData_GlobalSection.def("IntegerBits", (Standard_Integer (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::IntegerBits, "Returns the number of binary bits for integer representations.");
cls_IGESData_GlobalSection.def("MaxPower10Single", (Standard_Integer (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::MaxPower10Single, "Returns the maximum power of a decimal representation of a single-precision floating point number in the sending system.");
cls_IGESData_GlobalSection.def("MaxDigitsSingle", (Standard_Integer (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::MaxDigitsSingle, "None");
cls_IGESData_GlobalSection.def("MaxPower10Double", (Standard_Integer (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::MaxPower10Double, "Returns the maximum power of a decimal representation of a double-precision floating point number in the sending system.");
cls_IGESData_GlobalSection.def("MaxDigitsDouble", (Standard_Integer (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::MaxDigitsDouble, "None");
cls_IGESData_GlobalSection.def("ReceiveName", (opencascade::handle<TCollection_HAsciiString> (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::ReceiveName, "Returns the name of the receiving system.");
cls_IGESData_GlobalSection.def("Scale", (Standard_Real (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::Scale, "Returns the scale used in the IGES file.");
cls_IGESData_GlobalSection.def("UnitFlag", (Standard_Integer (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::UnitFlag, "Returns the unit flag that was used to write the IGES file.");
cls_IGESData_GlobalSection.def("UnitName", (opencascade::handle<TCollection_HAsciiString> (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::UnitName, "Returns the name of the unit the IGES file was written in.");
cls_IGESData_GlobalSection.def("LineWeightGrad", (Standard_Integer (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::LineWeightGrad, "Returns the maximum number of line weight gradations.");
cls_IGESData_GlobalSection.def("MaxLineWeight", (Standard_Real (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::MaxLineWeight, "Returns the of maximum line weight width in IGES file units.");
cls_IGESData_GlobalSection.def("Date", (opencascade::handle<TCollection_HAsciiString> (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::Date, "Returns the IGES file creation date.");
cls_IGESData_GlobalSection.def("Resolution", (Standard_Real (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::Resolution, "Returns the resolution used in the IGES file.");
cls_IGESData_GlobalSection.def("MaxCoord", (Standard_Real (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::MaxCoord, "Returns the approximate maximum coordinate value found in the model.");
cls_IGESData_GlobalSection.def("HasMaxCoord", (Standard_Boolean (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::HasMaxCoord, "Returns True if the approximate maximum coordinate value found in the model is greater than 0.");
cls_IGESData_GlobalSection.def("AuthorName", (opencascade::handle<TCollection_HAsciiString> (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::AuthorName, "Returns the name of the IGES file author.");
cls_IGESData_GlobalSection.def("CompanyName", (opencascade::handle<TCollection_HAsciiString> (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::CompanyName, "Returns the name of the company where the IGES file was written.");
cls_IGESData_GlobalSection.def("IGESVersion", (Standard_Integer (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::IGESVersion, "Returns the IGES version that the IGES file was written in.");
cls_IGESData_GlobalSection.def("DraftingStandard", (Standard_Integer (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::DraftingStandard, "None");
cls_IGESData_GlobalSection.def("LastChangeDate", (opencascade::handle<TCollection_HAsciiString> (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::LastChangeDate, "Returns the date and time when the model was created or last modified (for IGES 5.1 and later).");
cls_IGESData_GlobalSection.def("HasLastChangeDate", (Standard_Boolean (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::HasLastChangeDate, "Returns True if the date and time when the model was created or last modified are specified, i.e. not defaulted to NULL.");
cls_IGESData_GlobalSection.def("SetLastChangeDate", (void (IGESData_GlobalSection::*)()) &IGESData_GlobalSection::SetLastChangeDate, "None");
cls_IGESData_GlobalSection.def("ApplicationProtocol", (opencascade::handle<TCollection_HAsciiString> (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::ApplicationProtocol, "None");
cls_IGESData_GlobalSection.def("HasApplicationProtocol", (Standard_Boolean (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::HasApplicationProtocol, "None");
cls_IGESData_GlobalSection.def_static("NewDateString_", [](const Standard_Integer a0, const Standard_Integer a1, const Standard_Integer a2, const Standard_Integer a3, const Standard_Integer a4, const Standard_Integer a5) -> opencascade::handle<TCollection_HAsciiString> { return IGESData_GlobalSection::NewDateString(a0, a1, a2, a3, a4, a5); });
cls_IGESData_GlobalSection.def_static("NewDateString_", (opencascade::handle<TCollection_HAsciiString> (*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &IGESData_GlobalSection::NewDateString, "Returns a string built from year, month, day, hour, minute and second values. The form of the resulting string is defined as follows: - -1: YYMMDD.HHNNSS, - 0: YYYYMMDD.HHNNSS, - 1: YYYY-MM-DD:HH-NN-SS, where: - YYYY or YY is 4 or 2 digit year, - HH is hour (00-23), - MM is month (01-12), - NN is minute (00-59) - DD is day (01-31), - SS is second (00-59).", py::arg("year"), py::arg("month"), py::arg("day"), py::arg("hour"), py::arg("minut"), py::arg("second"), py::arg("mode"));
cls_IGESData_GlobalSection.def_static("NewDateString_", [](const opencascade::handle<TCollection_HAsciiString> & a0) -> opencascade::handle<TCollection_HAsciiString> { return IGESData_GlobalSection::NewDateString(a0); });
cls_IGESData_GlobalSection.def_static("NewDateString_", (opencascade::handle<TCollection_HAsciiString> (*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer)) &IGESData_GlobalSection::NewDateString, "Converts the string given in the form YYMMDD.HHNNSS or YYYYMMDD.HHNNSS to either YYMMDD.HHNNSS, YYYYMMDD.HHNNSS or YYYY-MM-DD:HH-NN-SS.", py::arg("date"), py::arg("mode"));
cls_IGESData_GlobalSection.def("UnitValue", (Standard_Real (IGESData_GlobalSection::*)() const) &IGESData_GlobalSection::UnitValue, "Returns the unit value (in meters) that the IGES file was written in.");
cls_IGESData_GlobalSection.def("SetSeparator", (void (IGESData_GlobalSection::*)(const Standard_Character)) &IGESData_GlobalSection::SetSeparator, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetEndMark", (void (IGESData_GlobalSection::*)(const Standard_Character)) &IGESData_GlobalSection::SetEndMark, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetSendName", (void (IGESData_GlobalSection::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_GlobalSection::SetSendName, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetFileName", (void (IGESData_GlobalSection::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_GlobalSection::SetFileName, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetSystemId", (void (IGESData_GlobalSection::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_GlobalSection::SetSystemId, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetInterfaceVersion", (void (IGESData_GlobalSection::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_GlobalSection::SetInterfaceVersion, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetIntegerBits", (void (IGESData_GlobalSection::*)(const Standard_Integer)) &IGESData_GlobalSection::SetIntegerBits, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetMaxPower10Single", (void (IGESData_GlobalSection::*)(const Standard_Integer)) &IGESData_GlobalSection::SetMaxPower10Single, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetMaxDigitsSingle", (void (IGESData_GlobalSection::*)(const Standard_Integer)) &IGESData_GlobalSection::SetMaxDigitsSingle, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetMaxPower10Double", (void (IGESData_GlobalSection::*)(const Standard_Integer)) &IGESData_GlobalSection::SetMaxPower10Double, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetMaxDigitsDouble", (void (IGESData_GlobalSection::*)(const Standard_Integer)) &IGESData_GlobalSection::SetMaxDigitsDouble, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetReceiveName", (void (IGESData_GlobalSection::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_GlobalSection::SetReceiveName, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetScale", (void (IGESData_GlobalSection::*)(const Standard_Real)) &IGESData_GlobalSection::SetScale, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetUnitFlag", (void (IGESData_GlobalSection::*)(const Standard_Integer)) &IGESData_GlobalSection::SetUnitFlag, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetUnitName", (void (IGESData_GlobalSection::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_GlobalSection::SetUnitName, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetLineWeightGrad", (void (IGESData_GlobalSection::*)(const Standard_Integer)) &IGESData_GlobalSection::SetLineWeightGrad, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetMaxLineWeight", (void (IGESData_GlobalSection::*)(const Standard_Real)) &IGESData_GlobalSection::SetMaxLineWeight, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetDate", (void (IGESData_GlobalSection::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_GlobalSection::SetDate, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetResolution", (void (IGESData_GlobalSection::*)(const Standard_Real)) &IGESData_GlobalSection::SetResolution, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetMaxCoord", [](IGESData_GlobalSection &self) -> void { return self.SetMaxCoord(); });
cls_IGESData_GlobalSection.def("SetMaxCoord", (void (IGESData_GlobalSection::*)(const Standard_Real)) &IGESData_GlobalSection::SetMaxCoord, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("MaxMaxCoord", [](IGESData_GlobalSection &self) -> void { return self.MaxMaxCoord(); });
cls_IGESData_GlobalSection.def("MaxMaxCoord", (void (IGESData_GlobalSection::*)(const Standard_Real)) &IGESData_GlobalSection::MaxMaxCoord, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("MaxMaxCoords", (void (IGESData_GlobalSection::*)(const gp_XYZ &)) &IGESData_GlobalSection::MaxMaxCoords, "None", py::arg("xyz"));
cls_IGESData_GlobalSection.def("SetAuthorName", (void (IGESData_GlobalSection::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_GlobalSection::SetAuthorName, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetCompanyName", (void (IGESData_GlobalSection::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_GlobalSection::SetCompanyName, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetIGESVersion", (void (IGESData_GlobalSection::*)(const Standard_Integer)) &IGESData_GlobalSection::SetIGESVersion, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetDraftingStandard", (void (IGESData_GlobalSection::*)(const Standard_Integer)) &IGESData_GlobalSection::SetDraftingStandard, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetLastChangeDate", (void (IGESData_GlobalSection::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_GlobalSection::SetLastChangeDate, "None", py::arg("val"));
cls_IGESData_GlobalSection.def("SetApplicationProtocol", (void (IGESData_GlobalSection::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_GlobalSection::SetApplicationProtocol, "None", py::arg("val"));

// CLASS: IGESDATA_IGESDUMPER
py::class_<IGESData_IGESDumper> cls_IGESData_IGESDumper(mod, "IGESData_IGESDumper", "Provides a way to obtain a clear Dump of an IGESEntity (distinct from normalized output). It works with tools attached to Entities, as for normalized Reade and Write");

// Constructors
cls_IGESData_IGESDumper.def(py::init<const opencascade::handle<IGESData_IGESModel> &, const opencascade::handle<IGESData_Protocol> &>(), py::arg("model"), py::arg("protocol"));

// Methods
// cls_IGESData_IGESDumper.def_static("operator new_", (void * (*)(size_t)) &IGESData_IGESDumper::operator new, "None", py::arg("theSize"));
// cls_IGESData_IGESDumper.def_static("operator delete_", (void (*)(void *)) &IGESData_IGESDumper::operator delete, "None", py::arg("theAddress"));
// cls_IGESData_IGESDumper.def_static("operator new[]_", (void * (*)(size_t)) &IGESData_IGESDumper::operator new[], "None", py::arg("theSize"));
// cls_IGESData_IGESDumper.def_static("operator delete[]_", (void (*)(void *)) &IGESData_IGESDumper::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData_IGESDumper.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData_IGESDumper::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData_IGESDumper.def_static("operator delete_", (void (*)(void *, void *)) &IGESData_IGESDumper::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESData_IGESDumper.def("PrintDNum", (void (IGESData_IGESDumper::*)(const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<Message_Messenger> &) const) &IGESData_IGESDumper::PrintDNum, "Prints onto an output, the 'Number of Directory Entry' which corresponds to an IGESEntity in the IGESModel, under the form 'D#nnn' (a Null Handle gives D#0)", py::arg("ent"), py::arg("S"));
cls_IGESData_IGESDumper.def("PrintShort", (void (IGESData_IGESDumper::*)(const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<Message_Messenger> &) const) &IGESData_IGESDumper::PrintShort, "Prints onto an output, the 'Number of Directory Entry' (see PrintDNum) plus IGES Type and Form Numbers, which gives 'D#nnn Type nnn Form nnn'", py::arg("ent"), py::arg("S"));
cls_IGESData_IGESDumper.def("Dump", [](IGESData_IGESDumper &self, const opencascade::handle<IGESData_IGESEntity> & a0, const opencascade::handle<Message_Messenger> & a1, const Standard_Integer a2) -> void { return self.Dump(a0, a1, a2); });
cls_IGESData_IGESDumper.def("Dump", (void (IGESData_IGESDumper::*)(const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<Message_Messenger> &, const Standard_Integer, const Standard_Integer) const) &IGESData_IGESDumper::Dump, "None", py::arg("ent"), py::arg("S"), py::arg("own"), py::arg("attached"));
cls_IGESData_IGESDumper.def("OwnDump", (void (IGESData_IGESDumper::*)(const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESData_IGESDumper::OwnDump, "Specific Dump for each IGES Entity, call by Dump (just above) <own> is the parameter <own> from Dump", py::arg("ent"), py::arg("S"), py::arg("own"));

// CLASS: IGESDATA_IGESMODEL
py::class_<IGESData_IGESModel, opencascade::handle<IGESData_IGESModel>, Interface_InterfaceModel> cls_IGESData_IGESModel(mod, "IGESData_IGESModel", "Defines the file header and entities for IGES files. These headers and entities result from a complete data translation using the IGES data exchange processor. Each entity is contained in a single model only and has a unique identifier. You can access this identifier using the method Number. Gives an access to the general data in the Start and the Global sections of an IGES file. The IGES file includes the following sections: -Start, -Global, -Directory Entry, -Parameter Data, -Terminate");

// Constructors
cls_IGESData_IGESModel.def(py::init<>());

// Methods
cls_IGESData_IGESModel.def("ClearHeader", (void (IGESData_IGESModel::*)()) &IGESData_IGESModel::ClearHeader, "Erases all data specific to IGES file Header (Start + Global)");
cls_IGESData_IGESModel.def("DumpHeader", [](IGESData_IGESModel &self, const opencascade::handle<Message_Messenger> & a0) -> void { return self.DumpHeader(a0); });
cls_IGESData_IGESModel.def("DumpHeader", (void (IGESData_IGESModel::*)(const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESData_IGESModel::DumpHeader, "Prints the IGES file header (Start and Global Sections) to the log file. The integer parameter is intended to be used as a level indicator but is not used at present.", py::arg("S"), py::arg("level"));
cls_IGESData_IGESModel.def("StartSection", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (IGESData_IGESModel::*)() const) &IGESData_IGESModel::StartSection, "Returns Model's Start Section (list of comment lines)");
cls_IGESData_IGESModel.def("NbStartLines", (Standard_Integer (IGESData_IGESModel::*)() const) &IGESData_IGESModel::NbStartLines, "Returns the count of recorded Start Lines");
cls_IGESData_IGESModel.def("StartLine", (Standard_CString (IGESData_IGESModel::*)(const Standard_Integer) const) &IGESData_IGESModel::StartLine, "Returns a line from the IGES file Start section by specifying its number. An empty string is returned if the number given is out of range, the range being from 1 to NbStartLines.", py::arg("num"));
cls_IGESData_IGESModel.def("ClearStartSection", (void (IGESData_IGESModel::*)()) &IGESData_IGESModel::ClearStartSection, "Clears the IGES file Start Section");
cls_IGESData_IGESModel.def("SetStartSection", [](IGESData_IGESModel &self, const opencascade::handle<TColStd_HSequenceOfHAsciiString> & a0) -> void { return self.SetStartSection(a0); });
cls_IGESData_IGESModel.def("SetStartSection", (void (IGESData_IGESModel::*)(const opencascade::handle<TColStd_HSequenceOfHAsciiString> &, const Standard_Boolean)) &IGESData_IGESModel::SetStartSection, "Sets a new Start section from a list of strings. If copy is false, the Start section will be shared. Any modifications made to the strings later on, will have an effect on the Start section. If copy is true (default value), an independent copy of the strings is created and used as the Start section. Any modifications made to the strings later on, will have no effect on the Start section.", py::arg("list"), py::arg("copy"));
cls_IGESData_IGESModel.def("AddStartLine", [](IGESData_IGESModel &self, const Standard_CString a0) -> void { return self.AddStartLine(a0); });
cls_IGESData_IGESModel.def("AddStartLine", (void (IGESData_IGESModel::*)(const Standard_CString, const Standard_Integer)) &IGESData_IGESModel::AddStartLine, "Adds a new string to the existing Start section at the end if atnum is 0 or not given, or before atnumth line.", py::arg("line"), py::arg("atnum"));
cls_IGESData_IGESModel.def("GlobalSection", (const IGESData_GlobalSection & (IGESData_IGESModel::*)() const) &IGESData_IGESModel::GlobalSection, "Returns the Global section of the IGES file.");
cls_IGESData_IGESModel.def("SetGlobalSection", (void (IGESData_IGESModel::*)(const IGESData_GlobalSection &)) &IGESData_IGESModel::SetGlobalSection, "Sets the Global section of the IGES file.", py::arg("header"));
cls_IGESData_IGESModel.def("ApplyStatic", [](IGESData_IGESModel &self) -> Standard_Boolean { return self.ApplyStatic(); });
cls_IGESData_IGESModel.def("ApplyStatic", (Standard_Boolean (IGESData_IGESModel::*)(const Standard_CString)) &IGESData_IGESModel::ApplyStatic, "Sets some of the Global section parameters with the values defined by the translation parameters. param may be: - receiver (value read in XSTEP.iges.header.receiver), - author (value read in XSTEP.iges.header.author), - company (value read in XSTEP.iges.header.company). The default value for param is an empty string. Returns True when done and if param is given, False if param is unknown or empty. Note: Set the unit in the IGES file Global section via IGESData_BasicEditor class.", py::arg("param"));
cls_IGESData_IGESModel.def("Entity", (opencascade::handle<IGESData_IGESEntity> (IGESData_IGESModel::*)(const Standard_Integer) const) &IGESData_IGESModel::Entity, "Returns an IGES entity given by its rank number.", py::arg("num"));
cls_IGESData_IGESModel.def("DNum", (Standard_Integer (IGESData_IGESModel::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_IGESModel::DNum, "Returns the equivalent DE Number for an Entity, i.e. 2*Number(ent)-1 , or 0 if <ent> is unknown from <me> This DE Number is used for File Writing for instance", py::arg("ent"));
cls_IGESData_IGESModel.def("GetFromAnother", (void (IGESData_IGESModel::*)(const opencascade::handle<Interface_InterfaceModel> &)) &IGESData_IGESModel::GetFromAnother, "gets Header (GlobalSection) from another Model", py::arg("other"));
cls_IGESData_IGESModel.def("NewEmptyModel", (opencascade::handle<Interface_InterfaceModel> (IGESData_IGESModel::*)() const) &IGESData_IGESModel::NewEmptyModel, "Returns a New Empty Model, same type as <me> i.e. IGESModel");
cls_IGESData_IGESModel.def("VerifyCheck", (void (IGESData_IGESModel::*)(opencascade::handle<Interface_Check> &) const) &IGESData_IGESModel::VerifyCheck, "Checks that the IGES file Global section contains valid data that conforms to the IGES specifications.", py::arg("ach"));
cls_IGESData_IGESModel.def("SetLineWeights", (void (IGESData_IGESModel::*)(const Standard_Real)) &IGESData_IGESModel::SetLineWeights, "Sets LineWeights of contained Entities according header data (MaxLineWeight and LineWeightGrad) or to a default value for undefined weights", py::arg("defw"));
cls_IGESData_IGESModel.def("ClearLabels", (void (IGESData_IGESModel::*)()) &IGESData_IGESModel::ClearLabels, "erases specific labels, i.e. does nothing");
cls_IGESData_IGESModel.def("PrintLabel", (void (IGESData_IGESModel::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Message_Messenger> &) const) &IGESData_IGESModel::PrintLabel, "Prints label specific to IGES norm for a given entity, i.e. its directory entry number (2*Number-1)", py::arg("ent"), py::arg("S"));
cls_IGESData_IGESModel.def("PrintToLog", (void (IGESData_IGESModel::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Message_Messenger> &) const) &IGESData_IGESModel::PrintToLog, "Prints label specific to IGES norm for a given -- -- entity, i.e. its directory entry number (2*Number-1) in the log file format.", py::arg("ent"), py::arg("S"));
cls_IGESData_IGESModel.def("PrintInfo", (void (IGESData_IGESModel::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Message_Messenger> &) const) &IGESData_IGESModel::PrintInfo, "Prints label specific to IGES norm for a given entity, i.e. its directory entry number (2*Number-1)", py::arg("ent"), py::arg("S"));
cls_IGESData_IGESModel.def("StringLabel", (opencascade::handle<TCollection_HAsciiString> (IGESData_IGESModel::*)(const opencascade::handle<Standard_Transient> &) const) &IGESData_IGESModel::StringLabel, "Returns a string with the label attached to a given entity, i.e. a string 'Dnn' with nn = directory entry number (2*N-1)", py::arg("ent"));
cls_IGESData_IGESModel.def_static("get_type_name_", (const char * (*)()) &IGESData_IGESModel::get_type_name, "None");
cls_IGESData_IGESModel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_IGESModel::get_type_descriptor, "None");
cls_IGESData_IGESModel.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_IGESModel::*)() const) &IGESData_IGESModel::DynamicType, "None");

// CLASS: IGESDATA_IGESTYPE
py::class_<IGESData_IGESType> cls_IGESData_IGESType(mod, "IGESData_IGESType", "taken from directory part of an entity (from file or model), gives 'type' and 'form' data, used to recognize entity's type");

// Constructors
cls_IGESData_IGESType.def(py::init<>());
cls_IGESData_IGESType.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("atype"), py::arg("aform"));

// Methods
// cls_IGESData_IGESType.def_static("operator new_", (void * (*)(size_t)) &IGESData_IGESType::operator new, "None", py::arg("theSize"));
// cls_IGESData_IGESType.def_static("operator delete_", (void (*)(void *)) &IGESData_IGESType::operator delete, "None", py::arg("theAddress"));
// cls_IGESData_IGESType.def_static("operator new[]_", (void * (*)(size_t)) &IGESData_IGESType::operator new[], "None", py::arg("theSize"));
// cls_IGESData_IGESType.def_static("operator delete[]_", (void (*)(void *)) &IGESData_IGESType::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData_IGESType.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData_IGESType::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData_IGESType.def_static("operator delete_", (void (*)(void *, void *)) &IGESData_IGESType::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESData_IGESType.def("Type", (Standard_Integer (IGESData_IGESType::*)() const) &IGESData_IGESType::Type, "returns 'type' data");
cls_IGESData_IGESType.def("Form", (Standard_Integer (IGESData_IGESType::*)() const) &IGESData_IGESType::Form, "returns 'form' data");
cls_IGESData_IGESType.def("IsEqual", (Standard_Boolean (IGESData_IGESType::*)(const IGESData_IGESType &) const) &IGESData_IGESType::IsEqual, "compares two IGESTypes, avoiding comparing their fields", py::arg("another"));
cls_IGESData_IGESType.def("__eq__", (Standard_Boolean (IGESData_IGESType::*)(const IGESData_IGESType &) const) &IGESData_IGESType::operator==, py::is_operator(), "None", py::arg("another"));
cls_IGESData_IGESType.def("Nullify", (void (IGESData_IGESType::*)()) &IGESData_IGESType::Nullify, "resets fields (usefull when an IGESType is stored as mask)");

// CLASS: IGESDATA_IGESREADERDATA
py::class_<IGESData_IGESReaderData, opencascade::handle<IGESData_IGESReaderData>, Interface_FileReaderData> cls_IGESData_IGESReaderData(mod, "IGESData_IGESReaderData", "specific FileReaderData for IGES contains header as GlobalSection, and for each Entity, its directory part as DirPart, list of Parameters as ParamSet Each Item has a DirPart, plus classically a ParamSet and the correspondant recognized Entity (inherited from FileReaderData) Parameters are accessed through specific objects, ParamReaders");

// Constructors
cls_IGESData_IGESReaderData.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("nbe"), py::arg("nbp"));

// Methods
cls_IGESData_IGESReaderData.def("AddStartLine", (void (IGESData_IGESReaderData::*)(const Standard_CString)) &IGESData_IGESReaderData::AddStartLine, "adds a start line to start section", py::arg("aval"));
cls_IGESData_IGESReaderData.def("StartSection", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (IGESData_IGESReaderData::*)() const) &IGESData_IGESReaderData::StartSection, "Returns the Start Section in once");
cls_IGESData_IGESReaderData.def("AddGlobal", (void (IGESData_IGESReaderData::*)(const Interface_ParamType, const Standard_CString)) &IGESData_IGESReaderData::AddGlobal, "adds a parameter to global section's parameter list", py::arg("atype"), py::arg("aval"));
cls_IGESData_IGESReaderData.def("SetGlobalSection", (void (IGESData_IGESReaderData::*)()) &IGESData_IGESReaderData::SetGlobalSection, "reads header (as GlobalSection) content from the ParamSet after it has been filled by successive calls to AddGlobal");
cls_IGESData_IGESReaderData.def("GlobalSection", (const IGESData_GlobalSection & (IGESData_IGESReaderData::*)() const) &IGESData_IGESReaderData::GlobalSection, "returns header as GlobalSection");
cls_IGESData_IGESReaderData.def("SetDirPart", (void (IGESData_IGESReaderData::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_CString, const Standard_CString, const Standard_CString, const Standard_CString)) &IGESData_IGESReaderData::SetDirPart, "fills a DirPart, designated by its rank (that is, (N+1)/2 if N is its first number in section D)", py::arg("num"), py::arg("i1"), py::arg("i2"), py::arg("i3"), py::arg("i4"), py::arg("i5"), py::arg("i6"), py::arg("i7"), py::arg("i8"), py::arg("i9"), py::arg("i10"), py::arg("i11"), py::arg("i12"), py::arg("i13"), py::arg("i14"), py::arg("i15"), py::arg("i16"), py::arg("i17"), py::arg("res1"), py::arg("res2"), py::arg("label"), py::arg("subs"));
cls_IGESData_IGESReaderData.def("DirPart", (const IGESData_DirPart & (IGESData_IGESReaderData::*)(const Standard_Integer) const) &IGESData_IGESReaderData::DirPart, "returns DirPart identified by record no (half Dsect number)", py::arg("num"));
// cls_IGESData_IGESReaderData.def("DirValues", [](IGESData_IGESReaderData &self, const Standard_Integer num, Standard_Integer & i1, Standard_Integer & i2, Standard_Integer & i3, Standard_Integer & i4, Standard_Integer & i5, Standard_Integer & i6, Standard_Integer & i7, Standard_Integer & i8, Standard_Integer & i9, Standard_Integer & i10, Standard_Integer & i11, Standard_Integer & i12, Standard_Integer & i13, Standard_Integer & i14, Standard_Integer & i15, Standard_Integer & i16, Standard_Integer & i17, Standard_CString & res1, Standard_CString & res2, Standard_CString & label, Standard_CString & subs){ self.DirValues(num, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, res1, res2, label, subs); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_CString &, Standard_CString &, Standard_CString &, Standard_CString &>(i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, res1, res2, label, subs); }, "returns values recorded in directory part n0 <num>", py::arg("num"), py::arg("i1"), py::arg("i2"), py::arg("i3"), py::arg("i4"), py::arg("i5"), py::arg("i6"), py::arg("i7"), py::arg("i8"), py::arg("i9"), py::arg("i10"), py::arg("i11"), py::arg("i12"), py::arg("i13"), py::arg("i14"), py::arg("i15"), py::arg("i16"), py::arg("i17"), py::arg("res1"), py::arg("res2"), py::arg("label"), py::arg("subs"));
cls_IGESData_IGESReaderData.def("DirType", (IGESData_IGESType (IGESData_IGESReaderData::*)(const Standard_Integer) const) &IGESData_IGESReaderData::DirType, "returns 'type' and 'form' info from a directory part", py::arg("num"));
cls_IGESData_IGESReaderData.def("NbEntities", (Standard_Integer (IGESData_IGESReaderData::*)() const) &IGESData_IGESReaderData::NbEntities, "Returns count of recorded Entities (i.e. size of Directory)");
cls_IGESData_IGESReaderData.def("FindNextRecord", (Standard_Integer (IGESData_IGESReaderData::*)(const Standard_Integer) const) &IGESData_IGESReaderData::FindNextRecord, "determines next suitable record from num; that is num+1 except for last one which gives 0", py::arg("num"));
cls_IGESData_IGESReaderData.def("SetEntityNumbers", (void (IGESData_IGESReaderData::*)()) &IGESData_IGESReaderData::SetEntityNumbers, "determines reference numbers in EntityNumber fields (called by SetEntities from IGESReaderTool) works on 'Integer' type Parameters, because IGES does not distinguish Integer and Entity Refs : every Integer which is odd and less than twice NbRecords can be an Entity Ref ... (Ref Number is then (N+1)/2 if N is the Integer Value)");
cls_IGESData_IGESReaderData.def("GlobalCheck", (opencascade::handle<Interface_Check> (IGESData_IGESReaderData::*)() const) &IGESData_IGESReaderData::GlobalCheck, "Returns the recorded Global Check");
cls_IGESData_IGESReaderData.def("SetDefaultLineWeight", (void (IGESData_IGESReaderData::*)(const Standard_Real)) &IGESData_IGESReaderData::SetDefaultLineWeight, "allows to set a default line weight, will be later applied at load time, on Entities which have no specified line weight", py::arg("defw"));
cls_IGESData_IGESReaderData.def("DefaultLineWeight", (Standard_Real (IGESData_IGESReaderData::*)() const) &IGESData_IGESReaderData::DefaultLineWeight, "Returns the recorded Default Line Weight, if there is (else, returns 0)");
cls_IGESData_IGESReaderData.def_static("get_type_name_", (const char * (*)()) &IGESData_IGESReaderData::get_type_name, "None");
cls_IGESData_IGESReaderData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_IGESReaderData::get_type_descriptor, "None");
cls_IGESData_IGESReaderData.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_IGESReaderData::*)() const) &IGESData_IGESReaderData::DynamicType, "None");

// CLASS: IGESDATA_IGESREADERTOOL
py::class_<IGESData_IGESReaderTool, Interface_FileReaderTool> cls_IGESData_IGESReaderTool(mod, "IGESData_IGESReaderTool", "specific FileReaderTool for IGES Parameters are accessed through specific objects, ParamReaders");

// Constructors
cls_IGESData_IGESReaderTool.def(py::init<const opencascade::handle<IGESData_IGESReaderData> &, const opencascade::handle<IGESData_Protocol> &>(), py::arg("reader"), py::arg("protocol"));

// Methods
// cls_IGESData_IGESReaderTool.def_static("operator new_", (void * (*)(size_t)) &IGESData_IGESReaderTool::operator new, "None", py::arg("theSize"));
// cls_IGESData_IGESReaderTool.def_static("operator delete_", (void (*)(void *)) &IGESData_IGESReaderTool::operator delete, "None", py::arg("theAddress"));
// cls_IGESData_IGESReaderTool.def_static("operator new[]_", (void * (*)(size_t)) &IGESData_IGESReaderTool::operator new[], "None", py::arg("theSize"));
// cls_IGESData_IGESReaderTool.def_static("operator delete[]_", (void (*)(void *)) &IGESData_IGESReaderTool::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData_IGESReaderTool.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData_IGESReaderTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData_IGESReaderTool.def_static("operator delete_", (void (*)(void *, void *)) &IGESData_IGESReaderTool::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESData_IGESReaderTool.def("Prepare", (void (IGESData_IGESReaderTool::*)(const opencascade::handle<IGESData_FileRecognizer> &)) &IGESData_IGESReaderTool::Prepare, "binds empty entities to records, works with the Protocol (from IGESData) stored and later used RQ : Actually, sets DNum into IGES Entities Also loads the list of parameters for ParamReader", py::arg("reco"));
cls_IGESData_IGESReaderTool.def("Recognize", (Standard_Boolean (IGESData_IGESReaderTool::*)(const Standard_Integer, opencascade::handle<Interface_Check> &, opencascade::handle<Standard_Transient> &)) &IGESData_IGESReaderTool::Recognize, "recognizes records by asking Protocol (on data of DirType)", py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_IGESData_IGESReaderTool.def("BeginRead", (void (IGESData_IGESReaderTool::*)(const opencascade::handle<Interface_InterfaceModel> &)) &IGESData_IGESReaderTool::BeginRead, "fills model's header, that is, its GlobalSection", py::arg("amodel"));
cls_IGESData_IGESReaderTool.def("AnalyseRecord", (Standard_Boolean (IGESData_IGESReaderTool::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, opencascade::handle<Interface_Check> &)) &IGESData_IGESReaderTool::AnalyseRecord, "fills an entity, given record no; works by calling ReadDirPart then ReadParams (with help of a ParamReader), then if required ReadProps and ReadAssocs, from IGESEntity Returns True if no fail has been recorded", py::arg("num"), py::arg("anent"), py::arg("acheck"));
cls_IGESData_IGESReaderTool.def("EndRead", (void (IGESData_IGESReaderTool::*)(const opencascade::handle<Interface_InterfaceModel> &)) &IGESData_IGESReaderTool::EndRead, "after reading entities, true line weights can be computed", py::arg("amodel"));
cls_IGESData_IGESReaderTool.def("ReadDir", (void (IGESData_IGESReaderTool::*)(const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESReaderData> &, const IGESData_DirPart &, opencascade::handle<Interface_Check> &) const) &IGESData_IGESReaderTool::ReadDir, "Reads directory part componants from file; DP is the litteral directory part, IR detains entities referenced by DP", py::arg("ent"), py::arg("IR"), py::arg("DP"), py::arg("ach"));
cls_IGESData_IGESReaderTool.def("ReadOwnParams", (void (IGESData_IGESReaderTool::*)(const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESData_IGESReaderTool::ReadOwnParams, "Performs Reading of own Parameters for each IGESEntity Works with the ReaderLib loaded with ReadWriteModules for IGES In case of failure, tries UndefinedEntity from IGES", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESData_IGESReaderTool.def("ReadProps", (void (IGESData_IGESReaderTool::*)(const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESData_IGESReaderTool::ReadProps, "Reads Property List, if there is (if not, does nothing) criterium is : current parameter of PR remains inside params list, and Stage is 'Own' Current parameter must be a positive integer, which value gives the length of the list; else, a Fail is produced (into Check of PR) and reading process is stopped", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESData_IGESReaderTool.def("ReadAssocs", (void (IGESData_IGESReaderTool::*)(const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESData_IGESReaderTool::ReadAssocs, "Reads Associativity List, if there is (if not, does nothing) criterium is : current parameter of PR remains inside params list, and Stage is 'Own' Same conditions as above; in addition, no parameter must be let after the list once read Note that 'Associated' entities are not declared 'Shared'", py::arg("ent"), py::arg("IR"), py::arg("PR"));

// CLASS: IGESDATA_IGESWRITER
py::class_<IGESData_IGESWriter> cls_IGESData_IGESWriter(mod, "IGESData_IGESWriter", "manages atomic file writing, under control of IGESModel : prepare text to be sent then sends it takes into account distinction between successive Sections");

// Constructors
cls_IGESData_IGESWriter.def(py::init<const opencascade::handle<IGESData_IGESModel> &>(), py::arg("amodel"));
cls_IGESData_IGESWriter.def(py::init<>());
cls_IGESData_IGESWriter.def(py::init<const IGESData_IGESWriter &>(), py::arg("other"));

// Methods
// cls_IGESData_IGESWriter.def_static("operator new_", (void * (*)(size_t)) &IGESData_IGESWriter::operator new, "None", py::arg("theSize"));
// cls_IGESData_IGESWriter.def_static("operator delete_", (void (*)(void *)) &IGESData_IGESWriter::operator delete, "None", py::arg("theAddress"));
// cls_IGESData_IGESWriter.def_static("operator new[]_", (void * (*)(size_t)) &IGESData_IGESWriter::operator new[], "None", py::arg("theSize"));
// cls_IGESData_IGESWriter.def_static("operator delete[]_", (void (*)(void *)) &IGESData_IGESWriter::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData_IGESWriter.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData_IGESWriter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData_IGESWriter.def_static("operator delete_", (void (*)(void *, void *)) &IGESData_IGESWriter::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESData_IGESWriter.def("FloatWriter", (Interface_FloatWriter & (IGESData_IGESWriter::*)()) &IGESData_IGESWriter::FloatWriter, "Returns the embedded FloatWriter, which controls sending Reals Use this method to access FloatWriter in order to consult or change its options (MainFormat, FormatForRange,ZeroSuppress), because it is returned as the address of its field");
cls_IGESData_IGESWriter.def("WriteMode", (Standard_Integer & (IGESData_IGESWriter::*)()) &IGESData_IGESWriter::WriteMode, "Returns the write mode, in order to be read and/or changed Write Mode controls the way final print works 0 (D) : Normal IGES, 10 : FNES");
cls_IGESData_IGESWriter.def("SendStartLine", (void (IGESData_IGESWriter::*)(const Standard_CString)) &IGESData_IGESWriter::SendStartLine, "Sends an additionnal Starting Line : this is the way used to send comments in an IGES File (at beginning of the file). If the line is more than 72 char.s long, it is splited into as many lines as required to send it completely", py::arg("startline"));
cls_IGESData_IGESWriter.def("SendModel", (void (IGESData_IGESWriter::*)(const opencascade::handle<IGESData_Protocol> &)) &IGESData_IGESWriter::SendModel, "Sends the complete IGESModel (Global Section, Entities as Directory Entries & Parameter Lists, etc...) i.e. fills a list of texts. Once filled, it can be sent by method Print", py::arg("protocol"));
cls_IGESData_IGESWriter.def("SectionS", (void (IGESData_IGESWriter::*)()) &IGESData_IGESWriter::SectionS, "declares sending of S section (only a declaration) error if state is not initial");
cls_IGESData_IGESWriter.def("SectionG", (void (IGESData_IGESWriter::*)(const IGESData_GlobalSection &)) &IGESData_IGESWriter::SectionG, "prepares sending of header, from a GlobalSection (stores it) error if SectionS was not called just before takes in account special characters (Separator, EndMark)", py::arg("header"));
cls_IGESData_IGESWriter.def("SectionsDP", (void (IGESData_IGESWriter::*)()) &IGESData_IGESWriter::SectionsDP, "prepares sending of list of entities, as Sections D (directory list) and P (Parameters lists, one per entity) Entities will be then processed, one after the other error if SectionG has not be called just before");
cls_IGESData_IGESWriter.def("SectionT", (void (IGESData_IGESWriter::*)()) &IGESData_IGESWriter::SectionT, "declares sending of T section (only a declaration) error if does not follow Entities sending");
cls_IGESData_IGESWriter.def("DirPart", (void (IGESData_IGESWriter::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESData_IGESWriter::DirPart, "translates directory part of an Entity into a litteral DirPart Some infos are computed after sending parameters Error if not in sections DP or Stage not 'Dir'", py::arg("anent"));
cls_IGESData_IGESWriter.def("OwnParams", (void (IGESData_IGESWriter::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESData_IGESWriter::OwnParams, "sends own parameters of the entity, by sending firstly its type, then calling specific method WriteOwnParams Error if not in sections DP or Stage not 'Own'", py::arg("anent"));
cls_IGESData_IGESWriter.def("Associativities", (void (IGESData_IGESWriter::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESData_IGESWriter::Associativities, "sends associativity list, as complement of parameters list error if not in sections DP or Stage not 'Associativity'", py::arg("anent"));
cls_IGESData_IGESWriter.def("Properties", (void (IGESData_IGESWriter::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESData_IGESWriter::Properties, "sends property list, as complement of parameters list error if not in sections DP or Stage not 'Property'", py::arg("anent"));
cls_IGESData_IGESWriter.def("EndEntity", (void (IGESData_IGESWriter::*)()) &IGESData_IGESWriter::EndEntity, "declares end of sending an entity (ends param list by ';')");
cls_IGESData_IGESWriter.def("SendVoid", (void (IGESData_IGESWriter::*)()) &IGESData_IGESWriter::SendVoid, "sends a void parameter, that is null text");
cls_IGESData_IGESWriter.def("Send", (void (IGESData_IGESWriter::*)(const Standard_Integer)) &IGESData_IGESWriter::Send, "sends an Integer parameter", py::arg("val"));
cls_IGESData_IGESWriter.def("SendBoolean", (void (IGESData_IGESWriter::*)(const Standard_Boolean)) &IGESData_IGESWriter::SendBoolean, "sends a Boolean parameter as an Integer value 0(False)/1(True)", py::arg("val"));
cls_IGESData_IGESWriter.def("Send", (void (IGESData_IGESWriter::*)(const Standard_Real)) &IGESData_IGESWriter::Send, "sends a Real parameter. Works with FloatWriter", py::arg("val"));
cls_IGESData_IGESWriter.def("Send", (void (IGESData_IGESWriter::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_IGESWriter::Send, "sends a Text parameter under Hollerith form", py::arg("val"));
cls_IGESData_IGESWriter.def("Send", [](IGESData_IGESWriter &self, const opencascade::handle<IGESData_IGESEntity> & a0) -> void { return self.Send(a0); });
cls_IGESData_IGESWriter.def("Send", (void (IGESData_IGESWriter::*)(const opencascade::handle<IGESData_IGESEntity> &, const Standard_Boolean)) &IGESData_IGESWriter::Send, "sends a Reference to an Entity (if its Number is N, its pointer is 2*N-1) If <val> is Null, '0' will be sent If <negative> is True, 'Pointer' is sent as negative", py::arg("val"), py::arg("negative"));
cls_IGESData_IGESWriter.def("SendString", (void (IGESData_IGESWriter::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_IGESWriter::SendString, "sends a parameter under its exact form given as a string", py::arg("val"));
cls_IGESData_IGESWriter.def("Send", (void (IGESData_IGESWriter::*)(const gp_XY &)) &IGESData_IGESWriter::Send, "Sends a XY, interpreted as a couple of 2 Reals (X & Y)", py::arg("val"));
cls_IGESData_IGESWriter.def("Send", (void (IGESData_IGESWriter::*)(const gp_XYZ &)) &IGESData_IGESWriter::Send, "Sends a XYZ, interpreted as a couple of 2 Reals (X , Y & Z)", py::arg("val"));
cls_IGESData_IGESWriter.def("SectionStrings", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (IGESData_IGESWriter::*)(const Standard_Integer) const) &IGESData_IGESWriter::SectionStrings, "Returns the list of strings for a section given its rank 1 : Start (if not empty) 2 : Global 3 or 4 : Parameters RQ: no string list for Directory section An empty section gives a null handle", py::arg("numsec"));
cls_IGESData_IGESWriter.def("Print", (Standard_Boolean (IGESData_IGESWriter::*)(Standard_OStream &) const) &IGESData_IGESWriter::Print, "Writes result on an output defined as an OStream resolves stored infos at this time; in particular, numbers of lines used to adress P-section from D-section and final totals Takes WriteMode into account", py::arg("S"));

// CLASS: IGESDATA_LABELDISPLAYENTITY
py::class_<IGESData_LabelDisplayEntity, opencascade::handle<IGESData_LabelDisplayEntity>, IGESData_IGESEntity> cls_IGESData_LabelDisplayEntity(mod, "IGESData_LabelDisplayEntity", "defines required type for LabelDisplay in directory part an effective LabelDisplay entity must inherits it");

// Methods
cls_IGESData_LabelDisplayEntity.def_static("get_type_name_", (const char * (*)()) &IGESData_LabelDisplayEntity::get_type_name, "None");
cls_IGESData_LabelDisplayEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_LabelDisplayEntity::get_type_descriptor, "None");
cls_IGESData_LabelDisplayEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_LabelDisplayEntity::*)() const) &IGESData_LabelDisplayEntity::DynamicType, "None");

// CLASS: IGESDATA_LEVELLISTENTITY
py::class_<IGESData_LevelListEntity, opencascade::handle<IGESData_LevelListEntity>, IGESData_IGESEntity> cls_IGESData_LevelListEntity(mod, "IGESData_LevelListEntity", "defines required type for LevelList in directory part an effective LevelList entity must inherits it");

// Methods
cls_IGESData_LevelListEntity.def("NbLevelNumbers", (Standard_Integer (IGESData_LevelListEntity::*)() const) &IGESData_LevelListEntity::NbLevelNumbers, "Must return the count of levels");
cls_IGESData_LevelListEntity.def("LevelNumber", (Standard_Integer (IGESData_LevelListEntity::*)(const Standard_Integer) const) &IGESData_LevelListEntity::LevelNumber, "returns the Level Number of <me>, indicated by <num> raises an exception if num is out of range", py::arg("num"));
cls_IGESData_LevelListEntity.def("HasLevelNumber", (Standard_Boolean (IGESData_LevelListEntity::*)(const Standard_Integer) const) &IGESData_LevelListEntity::HasLevelNumber, "returns True if <level> is in the list", py::arg("level"));
cls_IGESData_LevelListEntity.def_static("get_type_name_", (const char * (*)()) &IGESData_LevelListEntity::get_type_name, "None");
cls_IGESData_LevelListEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_LevelListEntity::get_type_descriptor, "None");
cls_IGESData_LevelListEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_LevelListEntity::*)() const) &IGESData_LevelListEntity::DynamicType, "None");

// CLASS: IGESDATA_NODEOFSPECIFICLIB
py::class_<IGESData_NodeOfSpecificLib, opencascade::handle<IGESData_NodeOfSpecificLib>, Standard_Transient> cls_IGESData_NodeOfSpecificLib(mod, "IGESData_NodeOfSpecificLib", "None");

// Constructors
cls_IGESData_NodeOfSpecificLib.def(py::init<>());

// Methods
cls_IGESData_NodeOfSpecificLib.def("AddNode", (void (IGESData_NodeOfSpecificLib::*)(const opencascade::handle<IGESData_GlobalNodeOfSpecificLib> &)) &IGESData_NodeOfSpecificLib::AddNode, "Adds a couple (Module,Protocol), that is, stores it into itself if not yet done, else creates a Next Node to do it", py::arg("anode"));
cls_IGESData_NodeOfSpecificLib.def("Module", (const opencascade::handle<IGESData_SpecificModule> & (IGESData_NodeOfSpecificLib::*)() const) &IGESData_NodeOfSpecificLib::Module, "Returns the Module designated by a precise Node");
cls_IGESData_NodeOfSpecificLib.def("Protocol", (const opencascade::handle<IGESData_Protocol> & (IGESData_NodeOfSpecificLib::*)() const) &IGESData_NodeOfSpecificLib::Protocol, "Returns the Protocol designated by a precise Node");
cls_IGESData_NodeOfSpecificLib.def("Next", (const opencascade::handle<IGESData_NodeOfSpecificLib> & (IGESData_NodeOfSpecificLib::*)() const) &IGESData_NodeOfSpecificLib::Next, "Returns the Next Node. If none was defined, returned value is a Null Handle");
cls_IGESData_NodeOfSpecificLib.def_static("get_type_name_", (const char * (*)()) &IGESData_NodeOfSpecificLib::get_type_name, "None");
cls_IGESData_NodeOfSpecificLib.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_NodeOfSpecificLib::get_type_descriptor, "None");
cls_IGESData_NodeOfSpecificLib.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_NodeOfSpecificLib::*)() const) &IGESData_NodeOfSpecificLib::DynamicType, "None");

// CLASS: IGESDATA_NODEOFWRITERLIB
py::class_<IGESData_NodeOfWriterLib, opencascade::handle<IGESData_NodeOfWriterLib>, Standard_Transient> cls_IGESData_NodeOfWriterLib(mod, "IGESData_NodeOfWriterLib", "None");

// Constructors
cls_IGESData_NodeOfWriterLib.def(py::init<>());

// Methods
cls_IGESData_NodeOfWriterLib.def("AddNode", (void (IGESData_NodeOfWriterLib::*)(const opencascade::handle<IGESData_GlobalNodeOfWriterLib> &)) &IGESData_NodeOfWriterLib::AddNode, "Adds a couple (Module,Protocol), that is, stores it into itself if not yet done, else creates a Next Node to do it", py::arg("anode"));
cls_IGESData_NodeOfWriterLib.def("Module", (const opencascade::handle<IGESData_ReadWriteModule> & (IGESData_NodeOfWriterLib::*)() const) &IGESData_NodeOfWriterLib::Module, "Returns the Module designated by a precise Node");
cls_IGESData_NodeOfWriterLib.def("Protocol", (const opencascade::handle<IGESData_Protocol> & (IGESData_NodeOfWriterLib::*)() const) &IGESData_NodeOfWriterLib::Protocol, "Returns the Protocol designated by a precise Node");
cls_IGESData_NodeOfWriterLib.def("Next", (const opencascade::handle<IGESData_NodeOfWriterLib> & (IGESData_NodeOfWriterLib::*)() const) &IGESData_NodeOfWriterLib::Next, "Returns the Next Node. If none was defined, returned value is a Null Handle");
cls_IGESData_NodeOfWriterLib.def_static("get_type_name_", (const char * (*)()) &IGESData_NodeOfWriterLib::get_type_name, "None");
cls_IGESData_NodeOfWriterLib.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_NodeOfWriterLib::get_type_descriptor, "None");
cls_IGESData_NodeOfWriterLib.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_NodeOfWriterLib::*)() const) &IGESData_NodeOfWriterLib::DynamicType, "None");

// CLASS: IGESDATA_PARAMCURSOR
py::class_<IGESData_ParamCursor> cls_IGESData_ParamCursor(mod, "IGESData_ParamCursor", "Auxiliary class for ParamReader. It stores commands for a ParamReader to manage the current parameter number. Used by methods Read... from ParamReader. It allows to define the following commands : - read a parameter specified by a precise Number (basic case) - read a parameter then set Current Number to follow its number - read the current parameter (with Current Number) then advance Current Number by one - idem with several : read 'nb' parameters from one specified, included, with or without setting Current Number to follow last parameter read - read several parameter from the current one, then advance Current Number to follow the last one read - Read several parameters (as above) but in interlaced lists, i.e. from complex items (each one including successively for instance, an Integer, a Real, an Entity ...)");

// Constructors
cls_IGESData_ParamCursor.def(py::init<const Standard_Integer>(), py::arg("num"));
cls_IGESData_ParamCursor.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("num"), py::arg("nb"));
cls_IGESData_ParamCursor.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("num"), py::arg("nb"), py::arg("size"));

// Methods
// cls_IGESData_ParamCursor.def_static("operator new_", (void * (*)(size_t)) &IGESData_ParamCursor::operator new, "None", py::arg("theSize"));
// cls_IGESData_ParamCursor.def_static("operator delete_", (void (*)(void *)) &IGESData_ParamCursor::operator delete, "None", py::arg("theAddress"));
// cls_IGESData_ParamCursor.def_static("operator new[]_", (void * (*)(size_t)) &IGESData_ParamCursor::operator new[], "None", py::arg("theSize"));
// cls_IGESData_ParamCursor.def_static("operator delete[]_", (void (*)(void *)) &IGESData_ParamCursor::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData_ParamCursor.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData_ParamCursor::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData_ParamCursor.def_static("operator delete_", (void (*)(void *, void *)) &IGESData_ParamCursor::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESData_ParamCursor.def("SetTerm", [](IGESData_ParamCursor &self, const Standard_Integer a0) -> void { return self.SetTerm(a0); });
cls_IGESData_ParamCursor.def("SetTerm", (void (IGESData_ParamCursor::*)(const Standard_Integer, const Standard_Boolean)) &IGESData_ParamCursor::SetTerm, "Defines the size of a term to read in the item : this commands ParamReader to read 'size' parameters for each item, then skip the remainder of the item to the same term of next Item (that is, skip 'item size' - 'term size')", py::arg("size"), py::arg("autoadv"));
cls_IGESData_ParamCursor.def("SetOne", [](IGESData_ParamCursor &self) -> void { return self.SetOne(); });
cls_IGESData_ParamCursor.def("SetOne", (void (IGESData_ParamCursor::*)(const Standard_Boolean)) &IGESData_ParamCursor::SetOne, "Defines a term of one Parameter (very current case)", py::arg("autoadv"));
cls_IGESData_ParamCursor.def("SetXY", [](IGESData_ParamCursor &self) -> void { return self.SetXY(); });
cls_IGESData_ParamCursor.def("SetXY", (void (IGESData_ParamCursor::*)(const Standard_Boolean)) &IGESData_ParamCursor::SetXY, "Defines a term of two Parameters for a XY (current case)", py::arg("autoadv"));
cls_IGESData_ParamCursor.def("SetXYZ", [](IGESData_ParamCursor &self) -> void { return self.SetXYZ(); });
cls_IGESData_ParamCursor.def("SetXYZ", (void (IGESData_ParamCursor::*)(const Standard_Boolean)) &IGESData_ParamCursor::SetXYZ, "Defines a term of three Parameters for XYZ (current case)", py::arg("autoadv"));
cls_IGESData_ParamCursor.def("SetAdvance", (void (IGESData_ParamCursor::*)(const Standard_Boolean)) &IGESData_ParamCursor::SetAdvance, "Changes command to advance current cursor after reading parameters. If 'advance' True, sets advance, if 'False', resets it. ParamCursor is created by default with True.", py::arg("advance"));
cls_IGESData_ParamCursor.def("Start", (Standard_Integer (IGESData_ParamCursor::*)() const) &IGESData_ParamCursor::Start, "Returns (included) starting number for reading parameters");
cls_IGESData_ParamCursor.def("Limit", (Standard_Integer (IGESData_ParamCursor::*)() const) &IGESData_ParamCursor::Limit, "Returns (excluded) upper limit number for reading parameters");
cls_IGESData_ParamCursor.def("Count", (Standard_Integer (IGESData_ParamCursor::*)() const) &IGESData_ParamCursor::Count, "Returns required count of items to be read");
cls_IGESData_ParamCursor.def("ItemSize", (Standard_Integer (IGESData_ParamCursor::*)() const) &IGESData_ParamCursor::ItemSize, "Returns length of item (count of parameters per item)");
cls_IGESData_ParamCursor.def("TermSize", (Standard_Integer (IGESData_ParamCursor::*)() const) &IGESData_ParamCursor::TermSize, "Returns length of current term (count of parameters) in item");
cls_IGESData_ParamCursor.def("Offset", (Standard_Integer (IGESData_ParamCursor::*)() const) &IGESData_ParamCursor::Offset, "Returns offset from which current term must be read in item");
cls_IGESData_ParamCursor.def("Advance", (Standard_Boolean (IGESData_ParamCursor::*)() const) &IGESData_ParamCursor::Advance, "Returns True if Advance command has been set");

// CLASS: IGESDATA_PARAMREADER
py::class_<IGESData_ParamReader> cls_IGESData_ParamReader(mod, "IGESData_ParamReader", "access to a list of parameters, with management of read stage (owned parameters, properties, associativities) and current parameter number, read errors (which feed a Check), plus convenient facilities to read parameters, in particular : - first parameter is ignored (it repeats entity type), hence number 1 gives 2nd parameter, etc... - lists are not explicit, list-reading methods are provided which manage a current param. number - interpretation is made as possible (texts, reals, entities ...) (in particular, Reading a Real accepts an Integer)");

// Constructors
cls_IGESData_ParamReader.def(py::init<const opencascade::handle<Interface_ParamList> &, const opencascade::handle<Interface_Check> &>(), py::arg("list"), py::arg("ach"));
cls_IGESData_ParamReader.def(py::init<const opencascade::handle<Interface_ParamList> &, const opencascade::handle<Interface_Check> &, const Standard_Integer>(), py::arg("list"), py::arg("ach"), py::arg("base"));
cls_IGESData_ParamReader.def(py::init<const opencascade::handle<Interface_ParamList> &, const opencascade::handle<Interface_Check> &, const Standard_Integer, const Standard_Integer>(), py::arg("list"), py::arg("ach"), py::arg("base"), py::arg("nbpar"));
cls_IGESData_ParamReader.def(py::init<const opencascade::handle<Interface_ParamList> &, const opencascade::handle<Interface_Check> &, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("list"), py::arg("ach"), py::arg("base"), py::arg("nbpar"), py::arg("num"));

// Methods
// cls_IGESData_ParamReader.def_static("operator new_", (void * (*)(size_t)) &IGESData_ParamReader::operator new, "None", py::arg("theSize"));
// cls_IGESData_ParamReader.def_static("operator delete_", (void (*)(void *)) &IGESData_ParamReader::operator delete, "None", py::arg("theAddress"));
// cls_IGESData_ParamReader.def_static("operator new[]_", (void * (*)(size_t)) &IGESData_ParamReader::operator new[], "None", py::arg("theSize"));
// cls_IGESData_ParamReader.def_static("operator delete[]_", (void (*)(void *)) &IGESData_ParamReader::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData_ParamReader.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData_ParamReader::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData_ParamReader.def_static("operator delete_", (void (*)(void *, void *)) &IGESData_ParamReader::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESData_ParamReader.def("EntityNumber", (Standard_Integer (IGESData_ParamReader::*)() const) &IGESData_ParamReader::EntityNumber, "Returns the entity number in the file");
cls_IGESData_ParamReader.def("Clear", (void (IGESData_ParamReader::*)()) &IGESData_ParamReader::Clear, "resets state (stage, current param number, check with no fail)");
cls_IGESData_ParamReader.def("CurrentNumber", (Standard_Integer (IGESData_ParamReader::*)() const) &IGESData_ParamReader::CurrentNumber, "returns the current parameter number This notion is involved by the organisation of an IGES list of parameter : it can be ended by two lists (Associativities and Properties), which can be empty, or even absent. Hence, it is necessary to know, at the end of specific reading, how many parameters have been read : the optionnal lists follow");
cls_IGESData_ParamReader.def("SetCurrentNumber", (void (IGESData_ParamReader::*)(const Standard_Integer)) &IGESData_ParamReader::SetCurrentNumber, "sets current parameter number to a new value must be done at end of each step : set on first parameter following last read one; is done by some Read... methods (must be done directly if these method are not used) num greater than NbParams means that following lists are empty If current num is not managed, it remains at 1, which probably will cause error when successive steps of reading are made", py::arg("num"));
cls_IGESData_ParamReader.def("Stage", (IGESData_ReadStage (IGESData_ParamReader::*)() const) &IGESData_ParamReader::Stage, "gives current stage (Own-Props-Assocs-End, begins at Own)");
cls_IGESData_ParamReader.def("NextStage", (void (IGESData_ParamReader::*)()) &IGESData_ParamReader::NextStage, "passes to next stage (must be linked with setting Current)");
cls_IGESData_ParamReader.def("EndAll", (void (IGESData_ParamReader::*)()) &IGESData_ParamReader::EndAll, "passes directly to the end of reading process");
cls_IGESData_ParamReader.def("NbParams", (Standard_Integer (IGESData_ParamReader::*)() const) &IGESData_ParamReader::NbParams, "returns number of parameters (minus the first one) following method skip the first parameter (1 gives the 2nd)");
cls_IGESData_ParamReader.def("ParamType", (Interface_ParamType (IGESData_ParamReader::*)(const Standard_Integer) const) &IGESData_ParamReader::ParamType, "returns type of parameter; note that 'Ident' or 'Sub' cannot be encountered, they correspond to 'Integer', see also below", py::arg("num"));
cls_IGESData_ParamReader.def("ParamValue", (Standard_CString (IGESData_ParamReader::*)(const Standard_Integer) const) &IGESData_ParamReader::ParamValue, "returns litteral value of a parameter, as it was in file", py::arg("num"));
cls_IGESData_ParamReader.def("IsParamDefined", (Standard_Boolean (IGESData_ParamReader::*)(const Standard_Integer) const) &IGESData_ParamReader::IsParamDefined, "says if a parameter is defined (not void) See also DefinedElseSkip", py::arg("num"));
cls_IGESData_ParamReader.def("IsParamEntity", (Standard_Boolean (IGESData_ParamReader::*)(const Standard_Integer) const) &IGESData_ParamReader::IsParamEntity, "says if a parameter can be regarded as an entity reference (see Prepare from IGESReaderData for more explanation) Note that such a parameter can seen as be a plain Integer too", py::arg("num"));
cls_IGESData_ParamReader.def("ParamNumber", (Standard_Integer (IGESData_ParamReader::*)(const Standard_Integer) const) &IGESData_ParamReader::ParamNumber, "returns entity number corresponding to a parameter if there is otherwise zero (according criterium IsParamEntity)", py::arg("num"));
cls_IGESData_ParamReader.def("ParamEntity", (opencascade::handle<IGESData_IGESEntity> (IGESData_ParamReader::*)(const opencascade::handle<IGESData_IGESReaderData> &, const Standard_Integer)) &IGESData_ParamReader::ParamEntity, "directly returns entity referenced by a parameter", py::arg("IR"), py::arg("num"));
cls_IGESData_ParamReader.def("Current", (IGESData_ParamCursor (IGESData_ParamReader::*)() const) &IGESData_ParamReader::Current, "Creates a ParamCursor from the Current Number, to read one parameter, and to advance Current Number after reading");
cls_IGESData_ParamReader.def("CurrentList", [](IGESData_ParamReader &self, const Standard_Integer a0) -> IGESData_ParamCursor { return self.CurrentList(a0); });
cls_IGESData_ParamReader.def("CurrentList", (IGESData_ParamCursor (IGESData_ParamReader::*)(const Standard_Integer, const Standard_Integer) const) &IGESData_ParamReader::CurrentList, "Creates a ParamCursor from the Current Number, to read a list of 'nb' items, and to advance Current Number after reading By default, each item is made of one parameter If size is given, it precises the number of params per item", py::arg("nb"), py::arg("size"));
cls_IGESData_ParamReader.def("DefinedElseSkip", (Standard_Boolean (IGESData_ParamReader::*)()) &IGESData_ParamReader::DefinedElseSkip, "Allows to simply process a parameter which can be defaulted. Waits on the Current Number a defined parameter or skips it : If the parameter <num> is defined, changes nothing and returns True Hence, the next reading with current cursor will concern <num> If it is void, advances Current Position by one, and returns False The next reading will concern <num+1> (except if <num> = NbParams)");
cls_IGESData_ParamReader.def("ReadInteger", [](IGESData_ParamReader &self, const IGESData_ParamCursor & PC, Standard_Integer & val){ Standard_Boolean rv = self.ReadInteger(PC, val); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, val); }, "None", py::arg("PC"), py::arg("val"));
cls_IGESData_ParamReader.def("ReadInteger", [](IGESData_ParamReader &self, const IGESData_ParamCursor & PC, const Standard_CString mess, Standard_Integer & val){ Standard_Boolean rv = self.ReadInteger(PC, mess, val); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, val); }, "Reads an Integer value designated by PC The method Current designates the current parameter and advances the Current Number by one after reading Note that if a count (not 1) is given, it is ignored If it is not an Integer, fills Check with a Fail (using mess) and returns False", py::arg("PC"), py::arg("mess"), py::arg("val"));
cls_IGESData_ParamReader.def("ReadBoolean", [](IGESData_ParamReader &self, const IGESData_ParamCursor & PC, const Message_Msg & amsg, Standard_Boolean & val, const Standard_Boolean exact){ Standard_Boolean rv = self.ReadBoolean(PC, amsg, val, exact); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, val); }, "None", py::arg("PC"), py::arg("amsg"), py::arg("val"), py::arg("exact"));
cls_IGESData_ParamReader.def("ReadBoolean", [](IGESData_ParamReader &self, const IGESData_ParamCursor & PC, const Standard_CString mess, Standard_Boolean & val, const Standard_Boolean exact){ Standard_Boolean rv = self.ReadBoolean(PC, mess, val, exact); return std::tuple<Standard_Boolean, Standard_Boolean &>(rv, val); }, "Reads a Boolean value from parameter 'num' A Boolean is given as an Integer value 0 (False) or 1 (True) Anyway, an Integer is demanded (else, Check is filled) If exact is given True, those precise values are demanded Else, Correction is done, as False for 0 or <0, True for >0 (with a Warning error message, and return is True) In case of error (not an Integer, or not 0/1 and exact True), Check is filled with a Fail (using mess) and return is False", py::arg("PC"), py::arg("mess"), py::arg("val"), py::arg("exact"));
cls_IGESData_ParamReader.def("ReadReal", [](IGESData_ParamReader &self, const IGESData_ParamCursor & PC, Standard_Real & val){ Standard_Boolean rv = self.ReadReal(PC, val); return std::tuple<Standard_Boolean, Standard_Real &>(rv, val); }, "None", py::arg("PC"), py::arg("val"));
cls_IGESData_ParamReader.def("ReadReal", [](IGESData_ParamReader &self, const IGESData_ParamCursor & PC, const Standard_CString mess, Standard_Real & val){ Standard_Boolean rv = self.ReadReal(PC, mess, val); return std::tuple<Standard_Boolean, Standard_Real &>(rv, val); }, "Reads a Real value from parameter 'num' An Integer is accepted (Check is filled with a Warning message) and causes return to be True (as normal case) In other cases, Check is filled with a Fail and return is False", py::arg("PC"), py::arg("mess"), py::arg("val"));
cls_IGESData_ParamReader.def("ReadXY", (Standard_Boolean (IGESData_ParamReader::*)(const IGESData_ParamCursor &, Message_Msg &, gp_XY &)) &IGESData_ParamReader::ReadXY, "None", py::arg("PC"), py::arg("amsg"), py::arg("val"));
cls_IGESData_ParamReader.def("ReadXY", (Standard_Boolean (IGESData_ParamReader::*)(const IGESData_ParamCursor &, const Standard_CString, gp_XY &)) &IGESData_ParamReader::ReadXY, "Reads a couple of Real values (X,Y) from parameter 'num' Integers are accepted (Check is filled with a Warning message) and cause return to be True (as normal case) In other cases, Check is filled with a Fail and return is False", py::arg("PC"), py::arg("mess"), py::arg("val"));
cls_IGESData_ParamReader.def("ReadXYZ", (Standard_Boolean (IGESData_ParamReader::*)(const IGESData_ParamCursor &, Message_Msg &, gp_XYZ &)) &IGESData_ParamReader::ReadXYZ, "None", py::arg("PC"), py::arg("amsg"), py::arg("val"));
cls_IGESData_ParamReader.def("ReadXYZ", (Standard_Boolean (IGESData_ParamReader::*)(const IGESData_ParamCursor &, const Standard_CString, gp_XYZ &)) &IGESData_ParamReader::ReadXYZ, "Reads a triplet of Real values (X,Y,Z) from parameter 'num' Integers are accepted (Check is filled with a Warning message) and cause return to be True (as normal case) In other cases, Check is filled with a Fail and return is False For Message", py::arg("PC"), py::arg("mess"), py::arg("val"));
cls_IGESData_ParamReader.def("ReadText", (Standard_Boolean (IGESData_ParamReader::*)(const IGESData_ParamCursor &, const Message_Msg &, opencascade::handle<TCollection_HAsciiString> &)) &IGESData_ParamReader::ReadText, "None", py::arg("PC"), py::arg("amsg"), py::arg("val"));
cls_IGESData_ParamReader.def("ReadText", (Standard_Boolean (IGESData_ParamReader::*)(const IGESData_ParamCursor &, const Standard_CString, opencascade::handle<TCollection_HAsciiString> &)) &IGESData_ParamReader::ReadText, "Reads a Text value from parameter 'num', as a String from Collection, that is, Hollerith text without leading 'nnnH' If it is not a String, fills Check with a Fail (using mess) and returns False", py::arg("PC"), py::arg("mess"), py::arg("val"));
cls_IGESData_ParamReader.def("ReadEntity", [](IGESData_ParamReader &self, const opencascade::handle<IGESData_IGESReaderData> & a0, const IGESData_ParamCursor & a1, IGESData_Status & a2, opencascade::handle<IGESData_IGESEntity> & a3) -> Standard_Boolean { return self.ReadEntity(a0, a1, a2, a3); });
cls_IGESData_ParamReader.def("ReadEntity", (Standard_Boolean (IGESData_ParamReader::*)(const opencascade::handle<IGESData_IGESReaderData> &, const IGESData_ParamCursor &, IGESData_Status &, opencascade::handle<IGESData_IGESEntity> &, const Standard_Boolean)) &IGESData_ParamReader::ReadEntity, "None", py::arg("IR"), py::arg("PC"), py::arg("aStatus"), py::arg("val"), py::arg("canbenul"));
cls_IGESData_ParamReader.def("ReadEntity", [](IGESData_ParamReader &self, const opencascade::handle<IGESData_IGESReaderData> & a0, const IGESData_ParamCursor & a1, const Standard_CString a2, opencascade::handle<IGESData_IGESEntity> & a3) -> Standard_Boolean { return self.ReadEntity(a0, a1, a2, a3); });
cls_IGESData_ParamReader.def("ReadEntity", (Standard_Boolean (IGESData_ParamReader::*)(const opencascade::handle<IGESData_IGESReaderData> &, const IGESData_ParamCursor &, const Standard_CString, opencascade::handle<IGESData_IGESEntity> &, const Standard_Boolean)) &IGESData_ParamReader::ReadEntity, "Reads an IGES entity from parameter 'num' An Entity is known by its reference, which has the form of an odd Integer Value (a number in the Directory) If <canbenul> is given True, a Reference can also be Null : in this case, the result is a Null Handle with no Error If <canbenul> is False, a Null Reference causes an Error If the parameter cannot refer to an entity (or null), fills Check with a Fail (using mess) and returns False", py::arg("IR"), py::arg("PC"), py::arg("mess"), py::arg("val"), py::arg("canbenul"));
cls_IGESData_ParamReader.def("ReadEntity", [](IGESData_ParamReader &self, const opencascade::handle<IGESData_IGESReaderData> & a0, const IGESData_ParamCursor & a1, IGESData_Status & a2, const opencascade::handle<Standard_Type> & a3, opencascade::handle<IGESData_IGESEntity> & a4) -> Standard_Boolean { return self.ReadEntity(a0, a1, a2, a3, a4); });
cls_IGESData_ParamReader.def("ReadEntity", (Standard_Boolean (IGESData_ParamReader::*)(const opencascade::handle<IGESData_IGESReaderData> &, const IGESData_ParamCursor &, IGESData_Status &, const opencascade::handle<Standard_Type> &, opencascade::handle<IGESData_IGESEntity> &, const Standard_Boolean)) &IGESData_ParamReader::ReadEntity, "None", py::arg("IR"), py::arg("PC"), py::arg("aStatus"), py::arg("type"), py::arg("val"), py::arg("canbenul"));
cls_IGESData_ParamReader.def("ReadEntity", [](IGESData_ParamReader &self, const opencascade::handle<IGESData_IGESReaderData> & a0, const IGESData_ParamCursor & a1, const Standard_CString a2, const opencascade::handle<Standard_Type> & a3, opencascade::handle<IGESData_IGESEntity> & a4) -> Standard_Boolean { return self.ReadEntity(a0, a1, a2, a3, a4); });
cls_IGESData_ParamReader.def("ReadEntity", (Standard_Boolean (IGESData_ParamReader::*)(const opencascade::handle<IGESData_IGESReaderData> &, const IGESData_ParamCursor &, const Standard_CString, const opencascade::handle<Standard_Type> &, opencascade::handle<IGESData_IGESEntity> &, const Standard_Boolean)) &IGESData_ParamReader::ReadEntity, "Works as ReadEntity without Type, but in addition checks the Type of the Entity, which must be 'kind of' a given <type> Then, gives the same fail cases as ReadEntity without Type, plus the case 'Incorrect Type' (in such a case, returns False and givel <val> = Null)", py::arg("IR"), py::arg("PC"), py::arg("mess"), py::arg("type"), py::arg("val"), py::arg("canbenul"));
cls_IGESData_ParamReader.def("ReadInts", [](IGESData_ParamReader &self, const IGESData_ParamCursor & a0, const Message_Msg & a1, opencascade::handle<TColStd_HArray1OfInteger> & a2) -> Standard_Boolean { return self.ReadInts(a0, a1, a2); });
cls_IGESData_ParamReader.def("ReadInts", (Standard_Boolean (IGESData_ParamReader::*)(const IGESData_ParamCursor &, const Message_Msg &, opencascade::handle<TColStd_HArray1OfInteger> &, const Standard_Integer)) &IGESData_ParamReader::ReadInts, "None", py::arg("PC"), py::arg("amsg"), py::arg("val"), py::arg("index"));
cls_IGESData_ParamReader.def("ReadInts", [](IGESData_ParamReader &self, const IGESData_ParamCursor & a0, const Standard_CString a1, opencascade::handle<TColStd_HArray1OfInteger> & a2) -> Standard_Boolean { return self.ReadInts(a0, a1, a2); });
cls_IGESData_ParamReader.def("ReadInts", (Standard_Boolean (IGESData_ParamReader::*)(const IGESData_ParamCursor &, const Standard_CString, opencascade::handle<TColStd_HArray1OfInteger> &, const Standard_Integer)) &IGESData_ParamReader::ReadInts, "Reads a list of Integer values, defined by PC (with a count of parameters). PC can start from Current Number and command it to advance after reading (use method CurrentList to do this) The list is given as a HArray1, numered from 'index' If all params are not Integer, Check is filled (using mess) and return value is False", py::arg("PC"), py::arg("mess"), py::arg("val"), py::arg("index"));
cls_IGESData_ParamReader.def("ReadReals", [](IGESData_ParamReader &self, const IGESData_ParamCursor & a0, Message_Msg & a1, opencascade::handle<TColStd_HArray1OfReal> & a2) -> Standard_Boolean { return self.ReadReals(a0, a1, a2); });
cls_IGESData_ParamReader.def("ReadReals", (Standard_Boolean (IGESData_ParamReader::*)(const IGESData_ParamCursor &, Message_Msg &, opencascade::handle<TColStd_HArray1OfReal> &, const Standard_Integer)) &IGESData_ParamReader::ReadReals, "None", py::arg("PC"), py::arg("amsg"), py::arg("val"), py::arg("index"));
cls_IGESData_ParamReader.def("ReadReals", [](IGESData_ParamReader &self, const IGESData_ParamCursor & a0, const Standard_CString a1, opencascade::handle<TColStd_HArray1OfReal> & a2) -> Standard_Boolean { return self.ReadReals(a0, a1, a2); });
cls_IGESData_ParamReader.def("ReadReals", (Standard_Boolean (IGESData_ParamReader::*)(const IGESData_ParamCursor &, const Standard_CString, opencascade::handle<TColStd_HArray1OfReal> &, const Standard_Integer)) &IGESData_ParamReader::ReadReals, "Reads a list of Real values defined by PC Same conditions as for ReadInts, for PC and index An Integer parameter is accepted, if at least one parameter is Integer, Check is filled with a 'Warning' message If all params are neither Real nor Integer, Check is filled (using mess) and return value is False", py::arg("PC"), py::arg("mess"), py::arg("val"), py::arg("index"));
cls_IGESData_ParamReader.def("ReadTexts", [](IGESData_ParamReader &self, const IGESData_ParamCursor & a0, const Message_Msg & a1, opencascade::handle<Interface_HArray1OfHAsciiString> & a2) -> Standard_Boolean { return self.ReadTexts(a0, a1, a2); });
cls_IGESData_ParamReader.def("ReadTexts", (Standard_Boolean (IGESData_ParamReader::*)(const IGESData_ParamCursor &, const Message_Msg &, opencascade::handle<Interface_HArray1OfHAsciiString> &, const Standard_Integer)) &IGESData_ParamReader::ReadTexts, "None", py::arg("PC"), py::arg("amsg"), py::arg("val"), py::arg("index"));
cls_IGESData_ParamReader.def("ReadTexts", [](IGESData_ParamReader &self, const IGESData_ParamCursor & a0, const Standard_CString a1, opencascade::handle<Interface_HArray1OfHAsciiString> & a2) -> Standard_Boolean { return self.ReadTexts(a0, a1, a2); });
cls_IGESData_ParamReader.def("ReadTexts", (Standard_Boolean (IGESData_ParamReader::*)(const IGESData_ParamCursor &, const Standard_CString, opencascade::handle<Interface_HArray1OfHAsciiString> &, const Standard_Integer)) &IGESData_ParamReader::ReadTexts, "Reads a list of Hollerith Texts, defined by PC Texts are read as Hollerith texts without leading 'nnnH' Same conditions as for ReadInts, for PC and index If all params are not Text, Check is filled (using mess) and return value is False", py::arg("PC"), py::arg("mess"), py::arg("val"), py::arg("index"));
cls_IGESData_ParamReader.def("ReadEnts", [](IGESData_ParamReader &self, const opencascade::handle<IGESData_IGESReaderData> & a0, const IGESData_ParamCursor & a1, const Message_Msg & a2, opencascade::handle<IGESData_HArray1OfIGESEntity> & a3) -> Standard_Boolean { return self.ReadEnts(a0, a1, a2, a3); });
cls_IGESData_ParamReader.def("ReadEnts", (Standard_Boolean (IGESData_ParamReader::*)(const opencascade::handle<IGESData_IGESReaderData> &, const IGESData_ParamCursor &, const Message_Msg &, opencascade::handle<IGESData_HArray1OfIGESEntity> &, const Standard_Integer)) &IGESData_ParamReader::ReadEnts, "None", py::arg("IR"), py::arg("PC"), py::arg("amsg"), py::arg("val"), py::arg("index"));
cls_IGESData_ParamReader.def("ReadEnts", [](IGESData_ParamReader &self, const opencascade::handle<IGESData_IGESReaderData> & a0, const IGESData_ParamCursor & a1, const Standard_CString a2, opencascade::handle<IGESData_HArray1OfIGESEntity> & a3) -> Standard_Boolean { return self.ReadEnts(a0, a1, a2, a3); });
cls_IGESData_ParamReader.def("ReadEnts", (Standard_Boolean (IGESData_ParamReader::*)(const opencascade::handle<IGESData_IGESReaderData> &, const IGESData_ParamCursor &, const Standard_CString, opencascade::handle<IGESData_HArray1OfIGESEntity> &, const Standard_Integer)) &IGESData_ParamReader::ReadEnts, "Reads a list of Entities defined by PC Same conditions as for ReadInts, for PC and index The list is given as a HArray1, numered from 'index' If all params cannot be read as Entities, Check is filled (using mess) and return value is False Remark : Null references are accepted, they are ignored (negative pointers too : they provoke a Warning message) If the caller wants to check them, a loop on ReadEntity should be used", py::arg("IR"), py::arg("PC"), py::arg("mess"), py::arg("val"), py::arg("index"));
cls_IGESData_ParamReader.def("ReadEntList", [](IGESData_ParamReader &self, const opencascade::handle<IGESData_IGESReaderData> & a0, const IGESData_ParamCursor & a1, Message_Msg & a2, Interface_EntityList & a3) -> Standard_Boolean { return self.ReadEntList(a0, a1, a2, a3); });
cls_IGESData_ParamReader.def("ReadEntList", (Standard_Boolean (IGESData_ParamReader::*)(const opencascade::handle<IGESData_IGESReaderData> &, const IGESData_ParamCursor &, Message_Msg &, Interface_EntityList &, const Standard_Boolean)) &IGESData_ParamReader::ReadEntList, "None", py::arg("IR"), py::arg("PC"), py::arg("amsg"), py::arg("val"), py::arg("ord"));
cls_IGESData_ParamReader.def("ReadEntList", [](IGESData_ParamReader &self, const opencascade::handle<IGESData_IGESReaderData> & a0, const IGESData_ParamCursor & a1, const Standard_CString a2, Interface_EntityList & a3) -> Standard_Boolean { return self.ReadEntList(a0, a1, a2, a3); });
cls_IGESData_ParamReader.def("ReadEntList", (Standard_Boolean (IGESData_ParamReader::*)(const opencascade::handle<IGESData_IGESReaderData> &, const IGESData_ParamCursor &, const Standard_CString, Interface_EntityList &, const Standard_Boolean)) &IGESData_ParamReader::ReadEntList, "Reads a list of Entities defined by PC Same conditions as for ReadEnts, for PC The list is given as an EntityList (index has no meaning; the EntityList starts from clear) If 'ord' is given True (default), entities will be added to the list in their original order Remark : Negative or Null Pointers are ignored Else ('ord' False), order is not garanteed (faster mode) If all params cannot be read as Entities, same as above Warning Give 'ord' to False ONLY if order is not significant", py::arg("IR"), py::arg("PC"), py::arg("mess"), py::arg("val"), py::arg("ord"));
cls_IGESData_ParamReader.def("ReadingReal", [](IGESData_ParamReader &self, const Standard_Integer num, Standard_Real & val){ Standard_Boolean rv = self.ReadingReal(num, val); return std::tuple<Standard_Boolean, Standard_Real &>(rv, val); }, "None", py::arg("num"), py::arg("val"));
cls_IGESData_ParamReader.def("ReadingReal", [](IGESData_ParamReader &self, const Standard_Integer num, const Standard_CString mess, Standard_Real & val){ Standard_Boolean rv = self.ReadingReal(num, mess, val); return std::tuple<Standard_Boolean, Standard_Real &>(rv, val); }, "Routine which reads a Real parameter, given its number Same conditions as ReadReal for mess, val, and return value", py::arg("num"), py::arg("mess"), py::arg("val"));
cls_IGESData_ParamReader.def("ReadingEntityNumber", [](IGESData_ParamReader &self, const Standard_Integer num, Standard_Integer & val){ Standard_Boolean rv = self.ReadingEntityNumber(num, val); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, val); }, "None", py::arg("num"), py::arg("val"));
cls_IGESData_ParamReader.def("ReadingEntityNumber", [](IGESData_ParamReader &self, const Standard_Integer num, const Standard_CString mess, Standard_Integer & val){ Standard_Boolean rv = self.ReadingEntityNumber(num, mess, val); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, val); }, "Routine which reads an Entity Number (which allows to read the Entity in the IGESReaderData by BoundEntity), given its number in the list of Parameters Same conditions as ReadEntity for mess, val, and return value In particular, returns True and val to zero means Null Entity, and val not zero means Entity read by BoundEntity", py::arg("num"), py::arg("mess"), py::arg("val"));
cls_IGESData_ParamReader.def("SendFail", (void (IGESData_ParamReader::*)(const Message_Msg &)) &IGESData_ParamReader::SendFail, "None", py::arg("amsg"));
cls_IGESData_ParamReader.def("SendWarning", (void (IGESData_ParamReader::*)(const Message_Msg &)) &IGESData_ParamReader::SendWarning, "None", py::arg("amsg"));
cls_IGESData_ParamReader.def("AddFail", [](IGESData_ParamReader &self, const Standard_CString a0) -> void { return self.AddFail(a0); });
cls_IGESData_ParamReader.def("AddFail", (void (IGESData_ParamReader::*)(const Standard_CString, const Standard_CString)) &IGESData_ParamReader::AddFail, "None", py::arg("afail"), py::arg("bfail"));
cls_IGESData_ParamReader.def("AddFail", (void (IGESData_ParamReader::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_ParamReader::AddFail, "feeds the Check with a new fail (as a String or as a CString)", py::arg("af"), py::arg("bf"));
cls_IGESData_ParamReader.def("AddWarning", [](IGESData_ParamReader &self, const Standard_CString a0) -> void { return self.AddWarning(a0); });
cls_IGESData_ParamReader.def("AddWarning", (void (IGESData_ParamReader::*)(const Standard_CString, const Standard_CString)) &IGESData_ParamReader::AddWarning, "None", py::arg("awarn"), py::arg("bwarn"));
cls_IGESData_ParamReader.def("AddWarning", (void (IGESData_ParamReader::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &IGESData_ParamReader::AddWarning, "feeds the Check with a new Warning message", py::arg("aw"), py::arg("bw"));
cls_IGESData_ParamReader.def("Mend", [](IGESData_ParamReader &self) -> void { return self.Mend(); });
cls_IGESData_ParamReader.def("Mend", (void (IGESData_ParamReader::*)(const Standard_CString)) &IGESData_ParamReader::Mend, "None", py::arg("pref"));
cls_IGESData_ParamReader.def("HasFailed", (Standard_Boolean (IGESData_ParamReader::*)() const) &IGESData_ParamReader::HasFailed, "says if fails have been recorded into the Check");
cls_IGESData_ParamReader.def("Check", (const opencascade::handle<Interface_Check> & (IGESData_ParamReader::*)() const) &IGESData_ParamReader::Check, "returns the Check Note that any error signaled above is also recorded into it");
cls_IGESData_ParamReader.def("CCheck", (opencascade::handle<Interface_Check> & (IGESData_ParamReader::*)()) &IGESData_ParamReader::CCheck, "returns the check in a way which allows to work on it directly (i.e. messages added to the Check are added to ParamReader too)");
cls_IGESData_ParamReader.def("IsCheckEmpty", (Standard_Boolean (IGESData_ParamReader::*)() const) &IGESData_ParamReader::IsCheckEmpty, "Returns True if the Check is Empty Else, it has to be recorded with the Read Entity");

// CLASS: IGESDATA_TOOLLOCATION
py::class_<IGESData_ToolLocation, opencascade::handle<IGESData_ToolLocation>, Standard_Transient> cls_IGESData_ToolLocation(mod, "IGESData_ToolLocation", "This Tool determines and gives access to effective Locations of IGES Entities as defined by the IGES Norm. These Locations can be for each Entity : - on one part, explicitly defined by a Transf in Directory Part (this Transf can be itself compound); if not defined, no proper Transformation is defined - on the other part, implicitly defined by a reference from another Entity : its Parent Both implicit and explicit locations are combinable.");

// Constructors
cls_IGESData_ToolLocation.def(py::init<const opencascade::handle<IGESData_IGESModel> &, const opencascade::handle<IGESData_Protocol> &>(), py::arg("amodel"), py::arg("protocol"));

// Methods
cls_IGESData_ToolLocation.def("Load", (void (IGESData_ToolLocation::*)()) &IGESData_ToolLocation::Load, "Does the effective work of determining Locations of Entities");
cls_IGESData_ToolLocation.def("SetPrecision", (void (IGESData_ToolLocation::*)(const Standard_Real)) &IGESData_ToolLocation::SetPrecision, "Sets a precision for the Analysis of Locations (default by constructor is 1.E-05)", py::arg("prec"));
cls_IGESData_ToolLocation.def("SetReference", (void (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESEntity> &)) &IGESData_ToolLocation::SetReference, "Sets the 'Reference' information for <child> as being <parent> Sets an Error Status if already set (see method IsAmbiguous)", py::arg("parent"), py::arg("child"));
cls_IGESData_ToolLocation.def("SetParentAssoc", (void (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESEntity> &)) &IGESData_ToolLocation::SetParentAssoc, "Sets the 'Associativity' information for <child> as being <parent> (it must be the Parent itself, not the Associativity)", py::arg("parent"), py::arg("child"));
cls_IGESData_ToolLocation.def("ResetDependences", (void (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESData_ToolLocation::ResetDependences, "Resets all informations about dependences for <child>", py::arg("child"));
cls_IGESData_ToolLocation.def("SetOwnAsDependent", (void (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESData_ToolLocation::SetOwnAsDependent, "Unitary action which defines Entities referenced by <ent> (except those in Directory Part and Associativities List) as Dependent (their Locations are related to that of <ent>)", py::arg("ent"));
cls_IGESData_ToolLocation.def("IsTransf", (Standard_Boolean (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_ToolLocation::IsTransf, "Returns True if <ent> is kind of TransfEntity. Then, it has no location, while it can be used to define a Location)", py::arg("ent"));
cls_IGESData_ToolLocation.def("IsAssociativity", (Standard_Boolean (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_ToolLocation::IsAssociativity, "Returns True if <ent> is an Associativity (IGES Type 402). Then, Location does not apply.", py::arg("ent"));
cls_IGESData_ToolLocation.def("HasTransf", (Standard_Boolean (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_ToolLocation::HasTransf, "Returns True if <ent> has a Transformation Matrix in proper (referenced from its Directory Part)", py::arg("ent"));
cls_IGESData_ToolLocation.def("ExplicitLocation", (gp_GTrsf (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_ToolLocation::ExplicitLocation, "Returns the Explicit Location defined by the Transformation Matrix of <ent>. Identity if there is none", py::arg("ent"));
cls_IGESData_ToolLocation.def("IsAmbiguous", (Standard_Boolean (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_ToolLocation::IsAmbiguous, "Returns True if more than one Parent has been determined for <ent>, by adding direct References and Associativities", py::arg("ent"));
cls_IGESData_ToolLocation.def("HasParent", (Standard_Boolean (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_ToolLocation::HasParent, "Returns True if <ent> is dependent from one and only one other Entity, either by Reference or by Associativity", py::arg("ent"));
cls_IGESData_ToolLocation.def("Parent", (opencascade::handle<IGESData_IGESEntity> (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_ToolLocation::Parent, "Returns the unique Parent recorded for <ent>. Returns a Null Handle if there is none", py::arg("ent"));
cls_IGESData_ToolLocation.def("HasParentByAssociativity", (Standard_Boolean (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_ToolLocation::HasParentByAssociativity, "Returns True if the Parent, if there is one, is defined by a SingleParentEntity Associativity Else, if HasParent is True, it is by Reference", py::arg("ent"));
cls_IGESData_ToolLocation.def("ParentLocation", (gp_GTrsf (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_ToolLocation::ParentLocation, "Returns the effective Location of the Parent of <ent>, if there is one : this Location is itself given as compound according dependences on the Parent, if there are some. Returns an Identity Transformation if no Parent is recorded.", py::arg("ent"));
cls_IGESData_ToolLocation.def("EffectiveLocation", (gp_GTrsf (IGESData_ToolLocation::*)(const opencascade::handle<IGESData_IGESEntity> &) const) &IGESData_ToolLocation::EffectiveLocation, "Returns the effective Location of an Entity, i.e. the composition of its proper Transformation Matrix (returned by Transf) and its Parent's Location (returned by ParentLocation)", py::arg("ent"));
cls_IGESData_ToolLocation.def("AnalyseLocation", (Standard_Boolean (IGESData_ToolLocation::*)(const gp_GTrsf &, gp_Trsf &) const) &IGESData_ToolLocation::AnalyseLocation, "Analysis a Location given as a GTrsf, by trying to convert it to a Trsf (i.e. to a True Location of which effect is described by an Isometry or a Similarity) Works with the Precision given by default or by SetPrecision Calls ConvertLocation (see below)", py::arg("loc"), py::arg("result"));
cls_IGESData_ToolLocation.def_static("ConvertLocation_", [](const Standard_Real a0, const gp_GTrsf & a1, gp_Trsf & a2) -> Standard_Boolean { return IGESData_ToolLocation::ConvertLocation(a0, a1, a2); });
cls_IGESData_ToolLocation.def_static("ConvertLocation_", (Standard_Boolean (*)(const Standard_Real, const gp_GTrsf &, gp_Trsf &, const Standard_Real)) &IGESData_ToolLocation::ConvertLocation, "Convertion of a Location, from GTrsf form to Trsf form Works with a precision given as argument. Returns True if the Conversion is possible, (hence, <result> contains the converted location), False else <unit>, if given, indicates the unit in which <loc> is defined in meters. It concerns the translation part (to be converted.", py::arg("prec"), py::arg("loc"), py::arg("result"), py::arg("uni"));
cls_IGESData_ToolLocation.def_static("get_type_name_", (const char * (*)()) &IGESData_ToolLocation::get_type_name, "None");
cls_IGESData_ToolLocation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_ToolLocation::get_type_descriptor, "None");
cls_IGESData_ToolLocation.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_ToolLocation::*)() const) &IGESData_ToolLocation::DynamicType, "None");

// CLASS: IGESDATA_TRANSFENTITY
py::class_<IGESData_TransfEntity, opencascade::handle<IGESData_TransfEntity>, IGESData_IGESEntity> cls_IGESData_TransfEntity(mod, "IGESData_TransfEntity", "defines required type for Transf in directory part an effective Transf entity must inherits it");

// Methods
cls_IGESData_TransfEntity.def("Value", (gp_GTrsf (IGESData_TransfEntity::*)() const) &IGESData_TransfEntity::Value, "gives value of the transformation, as a GTrsf To be defined by an effective class of Transformation Entity Warning : Must take in account Composition : if a TransfEntity has in its Directory Part, a Transf, this means that it is Compound, Value must return the global result");
cls_IGESData_TransfEntity.def_static("get_type_name_", (const char * (*)()) &IGESData_TransfEntity::get_type_name, "None");
cls_IGESData_TransfEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_TransfEntity::get_type_descriptor, "None");
cls_IGESData_TransfEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_TransfEntity::*)() const) &IGESData_TransfEntity::DynamicType, "None");

// CLASS: IGESDATA_VIEWKINDENTITY
py::class_<IGESData_ViewKindEntity, opencascade::handle<IGESData_ViewKindEntity>, IGESData_IGESEntity> cls_IGESData_ViewKindEntity(mod, "IGESData_ViewKindEntity", "defines required type for ViewKind in directory part that is, Single view or Multiple view An effective ViewKind entity must inherit it and define IsSingle (True for Single, False for List of Views), NbViews and ViewItem (especially for a List)");

// Methods
cls_IGESData_ViewKindEntity.def("IsSingle", (Standard_Boolean (IGESData_ViewKindEntity::*)() const) &IGESData_ViewKindEntity::IsSingle, "says if 'me' is a Single View (True) or a List of Views (False)");
cls_IGESData_ViewKindEntity.def("NbViews", (Standard_Integer (IGESData_ViewKindEntity::*)() const) &IGESData_ViewKindEntity::NbViews, "Returns the count of Views for a List of Views. For a Single View, may return simply 1");
cls_IGESData_ViewKindEntity.def("ViewItem", (opencascade::handle<IGESData_ViewKindEntity> (IGESData_ViewKindEntity::*)(const Standard_Integer) const) &IGESData_ViewKindEntity::ViewItem, "Returns the View n0. <num> for a List of Views. For a Single Views, may return <me> itself", py::arg("num"));
cls_IGESData_ViewKindEntity.def_static("get_type_name_", (const char * (*)()) &IGESData_ViewKindEntity::get_type_name, "None");
cls_IGESData_ViewKindEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_ViewKindEntity::get_type_descriptor, "None");
cls_IGESData_ViewKindEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_ViewKindEntity::*)() const) &IGESData_ViewKindEntity::DynamicType, "None");

// CLASS: IGESDATA_WRITERLIB
py::class_<IGESData_WriterLib> cls_IGESData_WriterLib(mod, "IGESData_WriterLib", "None");

// Constructors
cls_IGESData_WriterLib.def(py::init<const opencascade::handle<IGESData_Protocol> &>(), py::arg("aprotocol"));
cls_IGESData_WriterLib.def(py::init<>());

// Methods
// cls_IGESData_WriterLib.def_static("operator new_", (void * (*)(size_t)) &IGESData_WriterLib::operator new, "None", py::arg("theSize"));
// cls_IGESData_WriterLib.def_static("operator delete_", (void (*)(void *)) &IGESData_WriterLib::operator delete, "None", py::arg("theAddress"));
// cls_IGESData_WriterLib.def_static("operator new[]_", (void * (*)(size_t)) &IGESData_WriterLib::operator new[], "None", py::arg("theSize"));
// cls_IGESData_WriterLib.def_static("operator delete[]_", (void (*)(void *)) &IGESData_WriterLib::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData_WriterLib.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData_WriterLib::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData_WriterLib.def_static("operator delete_", (void (*)(void *, void *)) &IGESData_WriterLib::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESData_WriterLib.def_static("SetGlobal_", (void (*)(const opencascade::handle<IGESData_ReadWriteModule> &, const opencascade::handle<IGESData_Protocol> &)) &IGESData_WriterLib::SetGlobal, "Adds a couple (Module-Protocol) into the global definition set for this class of Library.", py::arg("amodule"), py::arg("aprotocol"));
cls_IGESData_WriterLib.def("AddProtocol", (void (IGESData_WriterLib::*)(const opencascade::handle<Standard_Transient> &)) &IGESData_WriterLib::AddProtocol, "Adds a couple (Module-Protocol) to the Library, given the class of a Protocol. Takes Resources into account. (if <aprotocol> is not of type TheProtocol, it is not added)", py::arg("aprotocol"));
cls_IGESData_WriterLib.def("Clear", (void (IGESData_WriterLib::*)()) &IGESData_WriterLib::Clear, "Clears the list of Modules of a library (can be used to redefine the order of Modules before action : Clear then refill the Library by calls to AddProtocol)");
cls_IGESData_WriterLib.def("SetComplete", (void (IGESData_WriterLib::*)()) &IGESData_WriterLib::SetComplete, "Sets a library to be defined with the complete Global list (all the couples Protocol/Modules recorded in it)");
cls_IGESData_WriterLib.def("Select", [](IGESData_WriterLib &self, const opencascade::handle<IGESData_IGESEntity> & obj, opencascade::handle<IGESData_ReadWriteModule> & module, Standard_Integer & CN){ Standard_Boolean rv = self.Select(obj, module, CN); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, CN); }, "Selects a Module from the Library, given an Object. Returns True if Select has succeeded, False else. Also Returns (as arguments) the selected Module and the Case Number determined by the associated Protocol. If Select has failed, <module> is Null Handle and CN is zero. (Select can work on any criterium, such as Object DynamicType)", py::arg("obj"), py::arg("module"), py::arg("CN"));
cls_IGESData_WriterLib.def("Start", (void (IGESData_WriterLib::*)()) &IGESData_WriterLib::Start, "Starts Iteration on the Modules (sets it on the first one)");
cls_IGESData_WriterLib.def("More", (Standard_Boolean (IGESData_WriterLib::*)() const) &IGESData_WriterLib::More, "Returns True if there are more Modules to iterate on");
cls_IGESData_WriterLib.def("Next", (void (IGESData_WriterLib::*)()) &IGESData_WriterLib::Next, "Iterates by getting the next Module in the list If there is none, the exception will be raised by Value");
cls_IGESData_WriterLib.def("Module", (const opencascade::handle<IGESData_ReadWriteModule> & (IGESData_WriterLib::*)() const) &IGESData_WriterLib::Module, "Returns the current Module in the Iteration");
cls_IGESData_WriterLib.def("Protocol", (const opencascade::handle<IGESData_Protocol> & (IGESData_WriterLib::*)() const) &IGESData_WriterLib::Protocol, "Returns the current Protocol in the Iteration");


}
