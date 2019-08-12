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
#include <IGESData_IGESType.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESEntity.hxx>
#include <IGESData_DefType.hxx>
#include <IGESData_LineFontEntity.hxx>
#include <IGESData_DefList.hxx>
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
#include <IGESData_DefSwitch.hxx>

void bind_IGESData_IGESEntity(py::module &mod){

py::class_<IGESData_IGESEntity, opencascade::handle<IGESData_IGESEntity>, Standard_Transient> cls_IGESData_IGESEntity(mod, "IGESData_IGESEntity", "defines root of IGES Entity definition, including Directory Part, lists of (optionnal) Properties and Associativities");

// Constructors

// Fields

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

// Enums

}