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
#include <Standard_Handle.hxx>
#include <IGESBasic_Protocol.hxx>
#include <IGESBasic_SubfigureDef.hxx>
#include <IGESBasic_Group.hxx>
#include <IGESBasic_GroupWithoutBackP.hxx>
#include <IGESBasic_SingleParent.hxx>
#include <IGESBasic_ExternalRefFileIndex.hxx>
#include <IGESBasic_OrderedGroup.hxx>
#include <IGESBasic_OrderedGroupWithoutBackP.hxx>
#include <IGESBasic_Hierarchy.hxx>
#include <IGESBasic_ExternalReferenceFile.hxx>
#include <IGESBasic_Name.hxx>
#include <IGESBasic_AssocGroupType.hxx>
#include <IGESBasic_SingularSubfigure.hxx>
#include <IGESBasic_ExternalRefFileName.hxx>
#include <IGESBasic_ExternalRefFile.hxx>
#include <IGESBasic_ExternalRefName.hxx>
#include <IGESBasic_ExternalRefLibName.hxx>
#include <IGESBasic_ToolSubfigureDef.hxx>
#include <IGESBasic_ToolGroup.hxx>
#include <IGESBasic_ToolGroupWithoutBackP.hxx>
#include <IGESBasic_ToolSingleParent.hxx>
#include <IGESBasic_ToolExternalRefFileIndex.hxx>
#include <IGESBasic_ToolOrderedGroup.hxx>
#include <IGESBasic_ToolOrderedGroupWithoutBackP.hxx>
#include <IGESBasic_ToolHierarchy.hxx>
#include <IGESBasic_ToolExternalReferenceFile.hxx>
#include <IGESBasic_ToolName.hxx>
#include <IGESBasic_ToolAssocGroupType.hxx>
#include <IGESBasic_ToolSingularSubfigure.hxx>
#include <IGESBasic_ToolExternalRefFileName.hxx>
#include <IGESBasic_ToolExternalRefFile.hxx>
#include <IGESBasic_ToolExternalRefName.hxx>
#include <IGESBasic_ToolExternalRefLibName.hxx>
#include <IGESBasic_ReadWriteModule.hxx>
#include <IGESBasic_GeneralModule.hxx>
#include <IGESBasic_SpecificModule.hxx>
#include <IGESBasic_HArray1OfHArray1OfInteger.hxx>
#include <IGESBasic_HArray1OfHArray1OfReal.hxx>
#include <IGESBasic_HArray1OfHArray1OfXY.hxx>
#include <IGESBasic_HArray1OfHArray1OfXYZ.hxx>
#include <IGESBasic_HArray1OfHArray1OfIGESEntity.hxx>
#include <IGESBasic.hxx>
#include <NCollection_Array1.hxx>
#include <IGESData_LineFontEntity.hxx>
#include <IGESBasic_Array1OfLineFontEntity.hxx>
#include <NCollection_Array2.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <IGESBasic_Array2OfHArray1OfReal.hxx>
#include <IGESData_IGESEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <Interface_HArray1OfHAsciiString.hxx>
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <IGESData_GeneralModule.hxx>
#include <Interface_EntityIterator.hxx>
#include <IGESData_DirChecker.hxx>
#include <Interface_ShareTool.hxx>
#include <Interface_Check.hxx>
#include <Standard_Transient.hxx>
#include <Interface_CopyTool.hxx>
#include <TColStd_Array1OfTransient.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TColgp_HArray1OfXY.hxx>
#include <TColgp_HArray1OfXYZ.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <IGESBasic_HArray1OfLineFontEntity.hxx>
#include <IGESBasic_HArray2OfHArray1OfReal.hxx>
#include <IGESData_NameEntity.hxx>
#include <IGESData_Protocol.hxx>
#include <Interface_Protocol.hxx>
#include <IGESData_ReadWriteModule.hxx>
#include <IGESData_IGESReaderData.hxx>
#include <IGESData_ParamReader.hxx>
#include <IGESData_IGESWriter.hxx>
#include <IGESData_SingleParentEntity.hxx>
#include <gp_XYZ.hxx>
#include <IGESData_SpecificModule.hxx>
#include <IGESData_IGESDumper.hxx>
#include <Message_Messenger.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_NCollection_Array2.hxx>

PYBIND11_MODULE(IGESBasic, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.IGESData");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.Interface");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.gp");
py::module::import("OCCT.Message");

// CLASS: IGESBASIC
py::class_<IGESBasic> cls_IGESBasic(mod, "IGESBasic", "This package represents basic entities from IGES");

// Methods
// cls_IGESBasic.def_static("operator new_", (void * (*)(size_t)) &IGESBasic::operator new, "None", py::arg("theSize"));
// cls_IGESBasic.def_static("operator delete_", (void (*)(void *)) &IGESBasic::operator delete, "None", py::arg("theAddress"));
// cls_IGESBasic.def_static("operator new[]_", (void * (*)(size_t)) &IGESBasic::operator new[], "None", py::arg("theSize"));
// cls_IGESBasic.def_static("operator delete[]_", (void (*)(void *)) &IGESBasic::operator delete[], "None", py::arg("theAddress"));
// cls_IGESBasic.def_static("operator new_", (void * (*)(size_t, void *)) &IGESBasic::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESBasic.def_static("operator delete_", (void (*)(void *, void *)) &IGESBasic::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESBasic.def_static("Init_", (void (*)()) &IGESBasic::Init, "Prepares dynqmic data (Protocol, Modules) for this package");
cls_IGESBasic.def_static("Protocol_", (opencascade::handle<IGESBasic_Protocol> (*)()) &IGESBasic::Protocol, "Returns the Protocol for this Package");

// TYPEDEF: IGESBASIC_ARRAY1OFLINEFONTENTITY
bind_NCollection_Array1<opencascade::handle<IGESData_LineFontEntity> >(mod, "IGESBasic_Array1OfLineFontEntity", py::module_local(false));

// TYPEDEF: IGESBASIC_ARRAY2OFHARRAY1OFREAL
bind_NCollection_Array2<opencascade::handle<TColStd_HArray1OfReal> >(mod, "IGESBasic_Array2OfHArray1OfReal", py::module_local(false));

// CLASS: IGESBASIC_ASSOCGROUPTYPE
py::class_<IGESBasic_AssocGroupType, opencascade::handle<IGESBasic_AssocGroupType>, IGESData_IGESEntity> cls_IGESBasic_AssocGroupType(mod, "IGESBasic_AssocGroupType", "defines AssocGroupType, Type <406> Form <23> in package IGESBasic Used to assign an unambiguous identification to a Group Associativity.");

// Constructors
cls_IGESBasic_AssocGroupType.def(py::init<>());

// Methods
cls_IGESBasic_AssocGroupType.def("Init", (void (IGESBasic_AssocGroupType::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &)) &IGESBasic_AssocGroupType::Init, "This method is used to set the fields of the class AssocGroupType - nbDataFields : number of parameter data fields = 2 - aType : type of attached associativity - aName : identifier of associativity of type AType", py::arg("nbDataFields"), py::arg("aType"), py::arg("aName"));
cls_IGESBasic_AssocGroupType.def("NbData", (Standard_Integer (IGESBasic_AssocGroupType::*)() const) &IGESBasic_AssocGroupType::NbData, "returns the number of parameter data fields, always = 2");
cls_IGESBasic_AssocGroupType.def("AssocType", (Standard_Integer (IGESBasic_AssocGroupType::*)() const) &IGESBasic_AssocGroupType::AssocType, "returns the type of attached associativity");
cls_IGESBasic_AssocGroupType.def("Name", (opencascade::handle<TCollection_HAsciiString> (IGESBasic_AssocGroupType::*)() const) &IGESBasic_AssocGroupType::Name, "returns identifier of instance of specified associativity");
cls_IGESBasic_AssocGroupType.def_static("get_type_name_", (const char * (*)()) &IGESBasic_AssocGroupType::get_type_name, "None");
cls_IGESBasic_AssocGroupType.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_AssocGroupType::get_type_descriptor, "None");
cls_IGESBasic_AssocGroupType.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_AssocGroupType::*)() const) &IGESBasic_AssocGroupType::DynamicType, "None");

// CLASS: IGESBASIC_EXTERNALREFERENCEFILE
py::class_<IGESBasic_ExternalReferenceFile, opencascade::handle<IGESBasic_ExternalReferenceFile>, IGESData_IGESEntity> cls_IGESBasic_ExternalReferenceFile(mod, "IGESBasic_ExternalReferenceFile", "defines ExternalReferenceFile, Type <406> Form <12> in package IGESBasic References definitions residing in another file");

// Constructors
cls_IGESBasic_ExternalReferenceFile.def(py::init<>());

// Methods
cls_IGESBasic_ExternalReferenceFile.def("Init", (void (IGESBasic_ExternalReferenceFile::*)(const opencascade::handle<Interface_HArray1OfHAsciiString> &)) &IGESBasic_ExternalReferenceFile::Init, "This method is used to set the fields of the class ExternalReferenceFile - aNameArray : External Reference File Names", py::arg("aNameArray"));
cls_IGESBasic_ExternalReferenceFile.def("NbListEntries", (Standard_Integer (IGESBasic_ExternalReferenceFile::*)() const) &IGESBasic_ExternalReferenceFile::NbListEntries, "returns number of External Reference File Names");
cls_IGESBasic_ExternalReferenceFile.def("Name", (opencascade::handle<TCollection_HAsciiString> (IGESBasic_ExternalReferenceFile::*)(const Standard_Integer) const) &IGESBasic_ExternalReferenceFile::Name, "returns External Reference File Name raises exception if Index <= 0 or Index > NbListEntries()", py::arg("Index"));
cls_IGESBasic_ExternalReferenceFile.def_static("get_type_name_", (const char * (*)()) &IGESBasic_ExternalReferenceFile::get_type_name, "None");
cls_IGESBasic_ExternalReferenceFile.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_ExternalReferenceFile::get_type_descriptor, "None");
cls_IGESBasic_ExternalReferenceFile.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_ExternalReferenceFile::*)() const) &IGESBasic_ExternalReferenceFile::DynamicType, "None");

// CLASS: IGESBASIC_EXTERNALREFFILE
py::class_<IGESBasic_ExternalRefFile, opencascade::handle<IGESBasic_ExternalRefFile>, IGESData_IGESEntity> cls_IGESBasic_ExternalRefFile(mod, "IGESBasic_ExternalRefFile", "defines ExternalRefFile, Type <416> Form <1> in package IGESBasic Used when entire reference file is to be instanced");

// Constructors
cls_IGESBasic_ExternalRefFile.def(py::init<>());

// Methods
cls_IGESBasic_ExternalRefFile.def("Init", (void (IGESBasic_ExternalRefFile::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESBasic_ExternalRefFile::Init, "This method is used to set the field of the class ExternalRefFile - aFileIdent : External Reference File Identifier", py::arg("aFileIdent"));
cls_IGESBasic_ExternalRefFile.def("FileId", (opencascade::handle<TCollection_HAsciiString> (IGESBasic_ExternalRefFile::*)() const) &IGESBasic_ExternalRefFile::FileId, "returns External Reference File Identifier");
cls_IGESBasic_ExternalRefFile.def_static("get_type_name_", (const char * (*)()) &IGESBasic_ExternalRefFile::get_type_name, "None");
cls_IGESBasic_ExternalRefFile.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_ExternalRefFile::get_type_descriptor, "None");
cls_IGESBasic_ExternalRefFile.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_ExternalRefFile::*)() const) &IGESBasic_ExternalRefFile::DynamicType, "None");

// CLASS: IGESBASIC_EXTERNALREFFILEINDEX
py::class_<IGESBasic_ExternalRefFileIndex, opencascade::handle<IGESBasic_ExternalRefFileIndex>, IGESData_IGESEntity> cls_IGESBasic_ExternalRefFileIndex(mod, "IGESBasic_ExternalRefFileIndex", "defines ExternalRefFileIndex, Type <402> Form <12> in package IGESBasic Contains a list of the symbolic names used by the referencing files and the DE pointers to the corresponding definitions within the referenced file");

// Constructors
cls_IGESBasic_ExternalRefFileIndex.def(py::init<>());

// Methods
cls_IGESBasic_ExternalRefFileIndex.def("Init", (void (IGESBasic_ExternalRefFileIndex::*)(const opencascade::handle<Interface_HArray1OfHAsciiString> &, const opencascade::handle<IGESData_HArray1OfIGESEntity> &)) &IGESBasic_ExternalRefFileIndex::Init, "This method is used to set the fields of the class ExternalRefFileIndex - aNameArray : External Reference Entity symbolic names - allEntities : External Reference Entities raises exception if array lengths are not equal if size of aNameArray is not equal to size of allEntities", py::arg("aNameArray"), py::arg("allEntities"));
cls_IGESBasic_ExternalRefFileIndex.def("NbEntries", (Standard_Integer (IGESBasic_ExternalRefFileIndex::*)() const) &IGESBasic_ExternalRefFileIndex::NbEntries, "returns number of index entries");
cls_IGESBasic_ExternalRefFileIndex.def("Name", (opencascade::handle<TCollection_HAsciiString> (IGESBasic_ExternalRefFileIndex::*)(const Standard_Integer) const) &IGESBasic_ExternalRefFileIndex::Name, "returns the External Reference Entity symbolic name raises exception if Index <= 0 or Index > NbEntries()", py::arg("Index"));
cls_IGESBasic_ExternalRefFileIndex.def("Entity", (opencascade::handle<IGESData_IGESEntity> (IGESBasic_ExternalRefFileIndex::*)(const Standard_Integer) const) &IGESBasic_ExternalRefFileIndex::Entity, "returns the internal entity raises exception if Index <= 0 or Index > NbEntries()", py::arg("Index"));
cls_IGESBasic_ExternalRefFileIndex.def_static("get_type_name_", (const char * (*)()) &IGESBasic_ExternalRefFileIndex::get_type_name, "None");
cls_IGESBasic_ExternalRefFileIndex.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_ExternalRefFileIndex::get_type_descriptor, "None");
cls_IGESBasic_ExternalRefFileIndex.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_ExternalRefFileIndex::*)() const) &IGESBasic_ExternalRefFileIndex::DynamicType, "None");

// CLASS: IGESBASIC_EXTERNALREFFILENAME
py::class_<IGESBasic_ExternalRefFileName, opencascade::handle<IGESBasic_ExternalRefFileName>, IGESData_IGESEntity> cls_IGESBasic_ExternalRefFileName(mod, "IGESBasic_ExternalRefFileName", "defines ExternalRefFileName, Type <416> Form <0-2> in package IGESBasic Used when single definition from the reference file is required or for external logical references where an entity in one file relates to an entity in another file");

// Constructors
cls_IGESBasic_ExternalRefFileName.def(py::init<>());

// Methods
cls_IGESBasic_ExternalRefFileName.def("Init", (void (IGESBasic_ExternalRefFileName::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &IGESBasic_ExternalRefFileName::Init, "This method is used to set the fields of the class ExternalRefFileName - aFileIdent : External Reference File Identifier - anExtName : External Reference Entity Symbolic Name", py::arg("aFileIdent"), py::arg("anExtName"));
cls_IGESBasic_ExternalRefFileName.def("SetForEntity", (void (IGESBasic_ExternalRefFileName::*)(const Standard_Boolean)) &IGESBasic_ExternalRefFileName::SetForEntity, "Changes FormNumber to be 2 if <mode> is True (For Entity) or 0 if <mode> is False (For Definition)", py::arg("mode"));
cls_IGESBasic_ExternalRefFileName.def("FileId", (opencascade::handle<TCollection_HAsciiString> (IGESBasic_ExternalRefFileName::*)() const) &IGESBasic_ExternalRefFileName::FileId, "returns External Reference File Identifier");
cls_IGESBasic_ExternalRefFileName.def("ReferenceName", (opencascade::handle<TCollection_HAsciiString> (IGESBasic_ExternalRefFileName::*)() const) &IGESBasic_ExternalRefFileName::ReferenceName, "returns External Reference Entity Symbolic Name");
cls_IGESBasic_ExternalRefFileName.def_static("get_type_name_", (const char * (*)()) &IGESBasic_ExternalRefFileName::get_type_name, "None");
cls_IGESBasic_ExternalRefFileName.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_ExternalRefFileName::get_type_descriptor, "None");
cls_IGESBasic_ExternalRefFileName.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_ExternalRefFileName::*)() const) &IGESBasic_ExternalRefFileName::DynamicType, "None");

// CLASS: IGESBASIC_EXTERNALREFLIBNAME
py::class_<IGESBasic_ExternalRefLibName, opencascade::handle<IGESBasic_ExternalRefLibName>, IGESData_IGESEntity> cls_IGESBasic_ExternalRefLibName(mod, "IGESBasic_ExternalRefLibName", "defines ExternalRefLibName, Type <416> Form <4> in package IGESBasic Used when it is assumed that a copy of the subfigure exists in native form in a library on the receiving system");

// Constructors
cls_IGESBasic_ExternalRefLibName.def(py::init<>());

// Methods
cls_IGESBasic_ExternalRefLibName.def("Init", (void (IGESBasic_ExternalRefLibName::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &IGESBasic_ExternalRefLibName::Init, "This method is used to set the fields of the class ExternalRefLibName - aLibName : Name of library in which ExtName resides - anExtName : External Reference Entity Symbolic Name", py::arg("aLibName"), py::arg("anExtName"));
cls_IGESBasic_ExternalRefLibName.def("LibraryName", (opencascade::handle<TCollection_HAsciiString> (IGESBasic_ExternalRefLibName::*)() const) &IGESBasic_ExternalRefLibName::LibraryName, "returns name of library in which External Reference Entity Symbolic Name resides");
cls_IGESBasic_ExternalRefLibName.def("ReferenceName", (opencascade::handle<TCollection_HAsciiString> (IGESBasic_ExternalRefLibName::*)() const) &IGESBasic_ExternalRefLibName::ReferenceName, "returns External Reference Entity Symbolic Name");
cls_IGESBasic_ExternalRefLibName.def_static("get_type_name_", (const char * (*)()) &IGESBasic_ExternalRefLibName::get_type_name, "None");
cls_IGESBasic_ExternalRefLibName.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_ExternalRefLibName::get_type_descriptor, "None");
cls_IGESBasic_ExternalRefLibName.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_ExternalRefLibName::*)() const) &IGESBasic_ExternalRefLibName::DynamicType, "None");

// CLASS: IGESBASIC_EXTERNALREFNAME
py::class_<IGESBasic_ExternalRefName, opencascade::handle<IGESBasic_ExternalRefName>, IGESData_IGESEntity> cls_IGESBasic_ExternalRefName(mod, "IGESBasic_ExternalRefName", "defines ExternalRefName, Type <416> Form <3> in package IGESBasic Used when it is assumed that a copy of the subfigure exists in native form on the receiving system");

// Constructors
cls_IGESBasic_ExternalRefName.def(py::init<>());

// Methods
cls_IGESBasic_ExternalRefName.def("Init", (void (IGESBasic_ExternalRefName::*)(const opencascade::handle<TCollection_HAsciiString> &)) &IGESBasic_ExternalRefName::Init, "This method is used to set the fields of the class ExternalRefName - anExtName : External Reference Entity Symbolic Name", py::arg("anExtName"));
cls_IGESBasic_ExternalRefName.def("ReferenceName", (opencascade::handle<TCollection_HAsciiString> (IGESBasic_ExternalRefName::*)() const) &IGESBasic_ExternalRefName::ReferenceName, "returns External Reference Entity Symbolic Name");
cls_IGESBasic_ExternalRefName.def_static("get_type_name_", (const char * (*)()) &IGESBasic_ExternalRefName::get_type_name, "None");
cls_IGESBasic_ExternalRefName.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_ExternalRefName::get_type_descriptor, "None");
cls_IGESBasic_ExternalRefName.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_ExternalRefName::*)() const) &IGESBasic_ExternalRefName::DynamicType, "None");

// CLASS: IGESBASIC_GENERALMODULE
py::class_<IGESBasic_GeneralModule, opencascade::handle<IGESBasic_GeneralModule>, IGESData_GeneralModule> cls_IGESBasic_GeneralModule(mod, "IGESBasic_GeneralModule", "Definition of General Services for IGESBasic (specific part) This Services comprise : Shared & Implied Lists, Copy, Check");

// Constructors
cls_IGESBasic_GeneralModule.def(py::init<>());

// Methods
cls_IGESBasic_GeneralModule.def("OwnSharedCase", (void (IGESBasic_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, Interface_EntityIterator &) const) &IGESBasic_GeneralModule::OwnSharedCase, "Lists the Entities shared by a given IGESEntity <ent>, from its specific parameters : specific for each type", py::arg("CN"), py::arg("ent"), py::arg("iter"));
cls_IGESBasic_GeneralModule.def("DirChecker", (IGESData_DirChecker (IGESBasic_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &) const) &IGESBasic_GeneralModule::DirChecker, "Returns a DirChecker, specific for each type of Entity (identified by its Case Number) : this DirChecker defines constraints which must be respected by the DirectoryPart", py::arg("CN"), py::arg("ent"));
cls_IGESBasic_GeneralModule.def("OwnCheckCase", (void (IGESBasic_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESBasic_GeneralModule::OwnCheckCase, "Performs Specific Semantic Check for each type of Entity", py::arg("CN"), py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESBasic_GeneralModule.def("NewVoid", (Standard_Boolean (IGESBasic_GeneralModule::*)(const Standard_Integer, opencascade::handle<Standard_Transient> &) const) &IGESBasic_GeneralModule::NewVoid, "Specific creation of a new void entity", py::arg("CN"), py::arg("entto"));
cls_IGESBasic_GeneralModule.def("OwnCopyCase", (void (IGESBasic_GeneralModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESEntity> &, Interface_CopyTool &) const) &IGESBasic_GeneralModule::OwnCopyCase, "Copies parameters which are specific of each Type of Entity", py::arg("CN"), py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESBasic_GeneralModule.def("CategoryNumber", (Standard_Integer (IGESBasic_GeneralModule::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const Interface_ShareTool &) const) &IGESBasic_GeneralModule::CategoryNumber, "Returns a category number which characterizes an entity Structure for Groups, Figures & Co Description for External Refs Auxiliary for other", py::arg("CN"), py::arg("ent"), py::arg("shares"));
cls_IGESBasic_GeneralModule.def_static("get_type_name_", (const char * (*)()) &IGESBasic_GeneralModule::get_type_name, "None");
cls_IGESBasic_GeneralModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_GeneralModule::get_type_descriptor, "None");
cls_IGESBasic_GeneralModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_GeneralModule::*)() const) &IGESBasic_GeneralModule::DynamicType, "None");

// CLASS: IGESBASIC_GROUP
py::class_<IGESBasic_Group, opencascade::handle<IGESBasic_Group>, IGESData_IGESEntity> cls_IGESBasic_Group(mod, "IGESBasic_Group", "defines Group, Type <402> Form <1> in package IGESBasic The Group Associativity allows a collection of a set of entities to be maintained as a single, logical entity");

// Constructors
cls_IGESBasic_Group.def(py::init<>());
cls_IGESBasic_Group.def(py::init<const Standard_Integer>(), py::arg("nb"));

// Methods
cls_IGESBasic_Group.def("Init", (void (IGESBasic_Group::*)(const opencascade::handle<IGESData_HArray1OfIGESEntity> &)) &IGESBasic_Group::Init, "This method is used to set the fields of the class Group - allEntities : Used to store pointers to members of the Group.", py::arg("allEntities"));
cls_IGESBasic_Group.def("SetOrdered", (void (IGESBasic_Group::*)(const Standard_Boolean)) &IGESBasic_Group::SetOrdered, "Sets a Group to be, or not to be Ordered (according mode)", py::arg("mode"));
cls_IGESBasic_Group.def("SetWithoutBackP", (void (IGESBasic_Group::*)(const Standard_Boolean)) &IGESBasic_Group::SetWithoutBackP, "Sets a Group to be, or not to be WithoutBackP", py::arg("mode"));
cls_IGESBasic_Group.def("IsOrdered", (Standard_Boolean (IGESBasic_Group::*)() const) &IGESBasic_Group::IsOrdered, "Returns True if <me> is Ordered");
cls_IGESBasic_Group.def("IsWithoutBackP", (Standard_Boolean (IGESBasic_Group::*)() const) &IGESBasic_Group::IsWithoutBackP, "Returns True if <me> is WithoutBackP");
cls_IGESBasic_Group.def("SetUser", (void (IGESBasic_Group::*)(const Standard_Integer, const Standard_Integer)) &IGESBasic_Group::SetUser, "Enforce a new value for the type and form", py::arg("type"), py::arg("form"));
cls_IGESBasic_Group.def("SetNb", (void (IGESBasic_Group::*)(const Standard_Integer)) &IGESBasic_Group::SetNb, "Changes the count of item If greater, new items are null If lower, old items are lost", py::arg("nb"));
cls_IGESBasic_Group.def("NbEntities", (Standard_Integer (IGESBasic_Group::*)() const) &IGESBasic_Group::NbEntities, "returns the number of IGESEntities in the Group");
cls_IGESBasic_Group.def("Entity", (opencascade::handle<IGESData_IGESEntity> (IGESBasic_Group::*)(const Standard_Integer) const) &IGESBasic_Group::Entity, "returns the specific entity from the Group", py::arg("Index"));
cls_IGESBasic_Group.def("Value", (opencascade::handle<Standard_Transient> (IGESBasic_Group::*)(const Standard_Integer) const) &IGESBasic_Group::Value, "returns the specific entity from the Group", py::arg("Index"));
cls_IGESBasic_Group.def("SetValue", (void (IGESBasic_Group::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &)) &IGESBasic_Group::SetValue, "Sets a new value for item <Index>", py::arg("Index"), py::arg("ent"));
cls_IGESBasic_Group.def_static("get_type_name_", (const char * (*)()) &IGESBasic_Group::get_type_name, "None");
cls_IGESBasic_Group.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_Group::get_type_descriptor, "None");
cls_IGESBasic_Group.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_Group::*)() const) &IGESBasic_Group::DynamicType, "None");

// CLASS: IGESBASIC_GROUPWITHOUTBACKP
py::class_<IGESBasic_GroupWithoutBackP, opencascade::handle<IGESBasic_GroupWithoutBackP>, IGESBasic_Group> cls_IGESBasic_GroupWithoutBackP(mod, "IGESBasic_GroupWithoutBackP", "defines GroupWithoutBackP, Type <402> Form <7> in package IGESBasic this class defines a Group without back pointers");

// Constructors
cls_IGESBasic_GroupWithoutBackP.def(py::init<>());

// Methods
cls_IGESBasic_GroupWithoutBackP.def_static("get_type_name_", (const char * (*)()) &IGESBasic_GroupWithoutBackP::get_type_name, "None");
cls_IGESBasic_GroupWithoutBackP.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_GroupWithoutBackP::get_type_descriptor, "None");
cls_IGESBasic_GroupWithoutBackP.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_GroupWithoutBackP::*)() const) &IGESBasic_GroupWithoutBackP::DynamicType, "None");

// CLASS: IGESBASIC_HARRAY1OFHARRAY1OFIGESENTITY
py::class_<IGESBasic_HArray1OfHArray1OfIGESEntity, opencascade::handle<IGESBasic_HArray1OfHArray1OfIGESEntity>, Standard_Transient> cls_IGESBasic_HArray1OfHArray1OfIGESEntity(mod, "IGESBasic_HArray1OfHArray1OfIGESEntity", "None");

// Constructors
cls_IGESBasic_HArray1OfHArray1OfIGESEntity.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("low"), py::arg("up"));

// Methods
cls_IGESBasic_HArray1OfHArray1OfIGESEntity.def("Lower", (Standard_Integer (IGESBasic_HArray1OfHArray1OfIGESEntity::*)() const) &IGESBasic_HArray1OfHArray1OfIGESEntity::Lower, "None");
cls_IGESBasic_HArray1OfHArray1OfIGESEntity.def("Upper", (Standard_Integer (IGESBasic_HArray1OfHArray1OfIGESEntity::*)() const) &IGESBasic_HArray1OfHArray1OfIGESEntity::Upper, "None");
cls_IGESBasic_HArray1OfHArray1OfIGESEntity.def("Length", (Standard_Integer (IGESBasic_HArray1OfHArray1OfIGESEntity::*)() const) &IGESBasic_HArray1OfHArray1OfIGESEntity::Length, "None");
cls_IGESBasic_HArray1OfHArray1OfIGESEntity.def("SetValue", (void (IGESBasic_HArray1OfHArray1OfIGESEntity::*)(const Standard_Integer, const opencascade::handle<IGESData_HArray1OfIGESEntity> &)) &IGESBasic_HArray1OfHArray1OfIGESEntity::SetValue, "None", py::arg("num"), py::arg("val"));
cls_IGESBasic_HArray1OfHArray1OfIGESEntity.def("Value", (opencascade::handle<IGESData_HArray1OfIGESEntity> (IGESBasic_HArray1OfHArray1OfIGESEntity::*)(const Standard_Integer) const) &IGESBasic_HArray1OfHArray1OfIGESEntity::Value, "None", py::arg("num"));
cls_IGESBasic_HArray1OfHArray1OfIGESEntity.def_static("get_type_name_", (const char * (*)()) &IGESBasic_HArray1OfHArray1OfIGESEntity::get_type_name, "None");
cls_IGESBasic_HArray1OfHArray1OfIGESEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_HArray1OfHArray1OfIGESEntity::get_type_descriptor, "None");
cls_IGESBasic_HArray1OfHArray1OfIGESEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_HArray1OfHArray1OfIGESEntity::*)() const) &IGESBasic_HArray1OfHArray1OfIGESEntity::DynamicType, "None");

// CLASS: IGESBASIC_HARRAY1OFHARRAY1OFINTEGER
py::class_<IGESBasic_HArray1OfHArray1OfInteger, opencascade::handle<IGESBasic_HArray1OfHArray1OfInteger>, Standard_Transient> cls_IGESBasic_HArray1OfHArray1OfInteger(mod, "IGESBasic_HArray1OfHArray1OfInteger", "None");

// Constructors
cls_IGESBasic_HArray1OfHArray1OfInteger.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("low"), py::arg("up"));

// Methods
cls_IGESBasic_HArray1OfHArray1OfInteger.def("Lower", (Standard_Integer (IGESBasic_HArray1OfHArray1OfInteger::*)() const) &IGESBasic_HArray1OfHArray1OfInteger::Lower, "None");
cls_IGESBasic_HArray1OfHArray1OfInteger.def("Upper", (Standard_Integer (IGESBasic_HArray1OfHArray1OfInteger::*)() const) &IGESBasic_HArray1OfHArray1OfInteger::Upper, "None");
cls_IGESBasic_HArray1OfHArray1OfInteger.def("Length", (Standard_Integer (IGESBasic_HArray1OfHArray1OfInteger::*)() const) &IGESBasic_HArray1OfHArray1OfInteger::Length, "None");
cls_IGESBasic_HArray1OfHArray1OfInteger.def("SetValue", (void (IGESBasic_HArray1OfHArray1OfInteger::*)(const Standard_Integer, const opencascade::handle<TColStd_HArray1OfInteger> &)) &IGESBasic_HArray1OfHArray1OfInteger::SetValue, "None", py::arg("num"), py::arg("val"));
cls_IGESBasic_HArray1OfHArray1OfInteger.def("Value", (opencascade::handle<TColStd_HArray1OfInteger> (IGESBasic_HArray1OfHArray1OfInteger::*)(const Standard_Integer) const) &IGESBasic_HArray1OfHArray1OfInteger::Value, "None", py::arg("num"));
cls_IGESBasic_HArray1OfHArray1OfInteger.def_static("get_type_name_", (const char * (*)()) &IGESBasic_HArray1OfHArray1OfInteger::get_type_name, "None");
cls_IGESBasic_HArray1OfHArray1OfInteger.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_HArray1OfHArray1OfInteger::get_type_descriptor, "None");
cls_IGESBasic_HArray1OfHArray1OfInteger.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_HArray1OfHArray1OfInteger::*)() const) &IGESBasic_HArray1OfHArray1OfInteger::DynamicType, "None");

// CLASS: IGESBASIC_HARRAY1OFHARRAY1OFREAL
py::class_<IGESBasic_HArray1OfHArray1OfReal, opencascade::handle<IGESBasic_HArray1OfHArray1OfReal>, Standard_Transient> cls_IGESBasic_HArray1OfHArray1OfReal(mod, "IGESBasic_HArray1OfHArray1OfReal", "None");

// Constructors
cls_IGESBasic_HArray1OfHArray1OfReal.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("low"), py::arg("up"));

// Methods
cls_IGESBasic_HArray1OfHArray1OfReal.def("Lower", (Standard_Integer (IGESBasic_HArray1OfHArray1OfReal::*)() const) &IGESBasic_HArray1OfHArray1OfReal::Lower, "None");
cls_IGESBasic_HArray1OfHArray1OfReal.def("Upper", (Standard_Integer (IGESBasic_HArray1OfHArray1OfReal::*)() const) &IGESBasic_HArray1OfHArray1OfReal::Upper, "None");
cls_IGESBasic_HArray1OfHArray1OfReal.def("Length", (Standard_Integer (IGESBasic_HArray1OfHArray1OfReal::*)() const) &IGESBasic_HArray1OfHArray1OfReal::Length, "None");
cls_IGESBasic_HArray1OfHArray1OfReal.def("SetValue", (void (IGESBasic_HArray1OfHArray1OfReal::*)(const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &)) &IGESBasic_HArray1OfHArray1OfReal::SetValue, "None", py::arg("num"), py::arg("val"));
cls_IGESBasic_HArray1OfHArray1OfReal.def("Value", (opencascade::handle<TColStd_HArray1OfReal> (IGESBasic_HArray1OfHArray1OfReal::*)(const Standard_Integer) const) &IGESBasic_HArray1OfHArray1OfReal::Value, "None", py::arg("num"));
cls_IGESBasic_HArray1OfHArray1OfReal.def_static("get_type_name_", (const char * (*)()) &IGESBasic_HArray1OfHArray1OfReal::get_type_name, "None");
cls_IGESBasic_HArray1OfHArray1OfReal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_HArray1OfHArray1OfReal::get_type_descriptor, "None");
cls_IGESBasic_HArray1OfHArray1OfReal.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_HArray1OfHArray1OfReal::*)() const) &IGESBasic_HArray1OfHArray1OfReal::DynamicType, "None");

// CLASS: IGESBASIC_HARRAY1OFHARRAY1OFXY
py::class_<IGESBasic_HArray1OfHArray1OfXY, opencascade::handle<IGESBasic_HArray1OfHArray1OfXY>, Standard_Transient> cls_IGESBasic_HArray1OfHArray1OfXY(mod, "IGESBasic_HArray1OfHArray1OfXY", "None");

// Constructors
cls_IGESBasic_HArray1OfHArray1OfXY.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("low"), py::arg("up"));

// Methods
cls_IGESBasic_HArray1OfHArray1OfXY.def("Lower", (Standard_Integer (IGESBasic_HArray1OfHArray1OfXY::*)() const) &IGESBasic_HArray1OfHArray1OfXY::Lower, "None");
cls_IGESBasic_HArray1OfHArray1OfXY.def("Upper", (Standard_Integer (IGESBasic_HArray1OfHArray1OfXY::*)() const) &IGESBasic_HArray1OfHArray1OfXY::Upper, "None");
cls_IGESBasic_HArray1OfHArray1OfXY.def("Length", (Standard_Integer (IGESBasic_HArray1OfHArray1OfXY::*)() const) &IGESBasic_HArray1OfHArray1OfXY::Length, "None");
cls_IGESBasic_HArray1OfHArray1OfXY.def("SetValue", (void (IGESBasic_HArray1OfHArray1OfXY::*)(const Standard_Integer, const opencascade::handle<TColgp_HArray1OfXY> &)) &IGESBasic_HArray1OfHArray1OfXY::SetValue, "None", py::arg("num"), py::arg("val"));
cls_IGESBasic_HArray1OfHArray1OfXY.def("Value", (opencascade::handle<TColgp_HArray1OfXY> (IGESBasic_HArray1OfHArray1OfXY::*)(const Standard_Integer) const) &IGESBasic_HArray1OfHArray1OfXY::Value, "None", py::arg("num"));
cls_IGESBasic_HArray1OfHArray1OfXY.def_static("get_type_name_", (const char * (*)()) &IGESBasic_HArray1OfHArray1OfXY::get_type_name, "None");
cls_IGESBasic_HArray1OfHArray1OfXY.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_HArray1OfHArray1OfXY::get_type_descriptor, "None");
cls_IGESBasic_HArray1OfHArray1OfXY.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_HArray1OfHArray1OfXY::*)() const) &IGESBasic_HArray1OfHArray1OfXY::DynamicType, "None");

// CLASS: IGESBASIC_HARRAY1OFHARRAY1OFXYZ
py::class_<IGESBasic_HArray1OfHArray1OfXYZ, opencascade::handle<IGESBasic_HArray1OfHArray1OfXYZ>, Standard_Transient> cls_IGESBasic_HArray1OfHArray1OfXYZ(mod, "IGESBasic_HArray1OfHArray1OfXYZ", "None");

// Constructors
cls_IGESBasic_HArray1OfHArray1OfXYZ.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("low"), py::arg("up"));

// Methods
cls_IGESBasic_HArray1OfHArray1OfXYZ.def("Lower", (Standard_Integer (IGESBasic_HArray1OfHArray1OfXYZ::*)() const) &IGESBasic_HArray1OfHArray1OfXYZ::Lower, "None");
cls_IGESBasic_HArray1OfHArray1OfXYZ.def("Upper", (Standard_Integer (IGESBasic_HArray1OfHArray1OfXYZ::*)() const) &IGESBasic_HArray1OfHArray1OfXYZ::Upper, "None");
cls_IGESBasic_HArray1OfHArray1OfXYZ.def("Length", (Standard_Integer (IGESBasic_HArray1OfHArray1OfXYZ::*)() const) &IGESBasic_HArray1OfHArray1OfXYZ::Length, "None");
cls_IGESBasic_HArray1OfHArray1OfXYZ.def("SetValue", (void (IGESBasic_HArray1OfHArray1OfXYZ::*)(const Standard_Integer, const opencascade::handle<TColgp_HArray1OfXYZ> &)) &IGESBasic_HArray1OfHArray1OfXYZ::SetValue, "None", py::arg("num"), py::arg("val"));
cls_IGESBasic_HArray1OfHArray1OfXYZ.def("Value", (opencascade::handle<TColgp_HArray1OfXYZ> (IGESBasic_HArray1OfHArray1OfXYZ::*)(const Standard_Integer) const) &IGESBasic_HArray1OfHArray1OfXYZ::Value, "None", py::arg("num"));
cls_IGESBasic_HArray1OfHArray1OfXYZ.def_static("get_type_name_", (const char * (*)()) &IGESBasic_HArray1OfHArray1OfXYZ::get_type_name, "None");
cls_IGESBasic_HArray1OfHArray1OfXYZ.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_HArray1OfHArray1OfXYZ::get_type_descriptor, "None");
cls_IGESBasic_HArray1OfHArray1OfXYZ.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_HArray1OfHArray1OfXYZ::*)() const) &IGESBasic_HArray1OfHArray1OfXYZ::DynamicType, "None");

// CLASS: IGESBASIC_HARRAY1OFLINEFONTENTITY
py::class_<IGESBasic_HArray1OfLineFontEntity, opencascade::handle<IGESBasic_HArray1OfLineFontEntity>, Standard_Transient> cls_IGESBasic_HArray1OfLineFontEntity(mod, "IGESBasic_HArray1OfLineFontEntity", "None", py::multiple_inheritance());

// Constructors
cls_IGESBasic_HArray1OfLineFontEntity.def(py::init<>());
cls_IGESBasic_HArray1OfLineFontEntity.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_IGESBasic_HArray1OfLineFontEntity.def(py::init<const Standard_Integer, const Standard_Integer, const IGESBasic_Array1OfLineFontEntity::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_IGESBasic_HArray1OfLineFontEntity.def(py::init<const IGESBasic_Array1OfLineFontEntity &>(), py::arg("theOther"));

// Methods
// cls_IGESBasic_HArray1OfLineFontEntity.def_static("operator new_", (void * (*)(size_t)) &IGESBasic_HArray1OfLineFontEntity::operator new, "None", py::arg("theSize"));
// cls_IGESBasic_HArray1OfLineFontEntity.def_static("operator delete_", (void (*)(void *)) &IGESBasic_HArray1OfLineFontEntity::operator delete, "None", py::arg("theAddress"));
// cls_IGESBasic_HArray1OfLineFontEntity.def_static("operator new[]_", (void * (*)(size_t)) &IGESBasic_HArray1OfLineFontEntity::operator new[], "None", py::arg("theSize"));
// cls_IGESBasic_HArray1OfLineFontEntity.def_static("operator delete[]_", (void (*)(void *)) &IGESBasic_HArray1OfLineFontEntity::operator delete[], "None", py::arg("theAddress"));
// cls_IGESBasic_HArray1OfLineFontEntity.def_static("operator new_", (void * (*)(size_t, void *)) &IGESBasic_HArray1OfLineFontEntity::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESBasic_HArray1OfLineFontEntity.def_static("operator delete_", (void (*)(void *, void *)) &IGESBasic_HArray1OfLineFontEntity::operator delete, "None", py::arg(""), py::arg(""));
// cls_IGESBasic_HArray1OfLineFontEntity.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &IGESBasic_HArray1OfLineFontEntity::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_IGESBasic_HArray1OfLineFontEntity.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &IGESBasic_HArray1OfLineFontEntity::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_IGESBasic_HArray1OfLineFontEntity.def("Array1", (const IGESBasic_Array1OfLineFontEntity & (IGESBasic_HArray1OfLineFontEntity::*)() const) &IGESBasic_HArray1OfLineFontEntity::Array1, "None");
cls_IGESBasic_HArray1OfLineFontEntity.def("ChangeArray1", (IGESBasic_Array1OfLineFontEntity & (IGESBasic_HArray1OfLineFontEntity::*)()) &IGESBasic_HArray1OfLineFontEntity::ChangeArray1, "None");
cls_IGESBasic_HArray1OfLineFontEntity.def_static("get_type_name_", (const char * (*)()) &IGESBasic_HArray1OfLineFontEntity::get_type_name, "None");
cls_IGESBasic_HArray1OfLineFontEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_HArray1OfLineFontEntity::get_type_descriptor, "None");
cls_IGESBasic_HArray1OfLineFontEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_HArray1OfLineFontEntity::*)() const) &IGESBasic_HArray1OfLineFontEntity::DynamicType, "None");

// CLASS: IGESBASIC_HARRAY2OFHARRAY1OFREAL
py::class_<IGESBasic_HArray2OfHArray1OfReal, opencascade::handle<IGESBasic_HArray2OfHArray1OfReal>, Standard_Transient> cls_IGESBasic_HArray2OfHArray1OfReal(mod, "IGESBasic_HArray2OfHArray1OfReal", "None", py::multiple_inheritance());

// Constructors
cls_IGESBasic_HArray2OfHArray1OfReal.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_IGESBasic_HArray2OfHArray1OfReal.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const IGESBasic_Array2OfHArray1OfReal::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_IGESBasic_HArray2OfHArray1OfReal.def(py::init<const IGESBasic_Array2OfHArray1OfReal &>(), py::arg("theOther"));

// Methods
// cls_IGESBasic_HArray2OfHArray1OfReal.def_static("operator new_", (void * (*)(size_t)) &IGESBasic_HArray2OfHArray1OfReal::operator new, "None", py::arg("theSize"));
// cls_IGESBasic_HArray2OfHArray1OfReal.def_static("operator delete_", (void (*)(void *)) &IGESBasic_HArray2OfHArray1OfReal::operator delete, "None", py::arg("theAddress"));
// cls_IGESBasic_HArray2OfHArray1OfReal.def_static("operator new[]_", (void * (*)(size_t)) &IGESBasic_HArray2OfHArray1OfReal::operator new[], "None", py::arg("theSize"));
// cls_IGESBasic_HArray2OfHArray1OfReal.def_static("operator delete[]_", (void (*)(void *)) &IGESBasic_HArray2OfHArray1OfReal::operator delete[], "None", py::arg("theAddress"));
// cls_IGESBasic_HArray2OfHArray1OfReal.def_static("operator new_", (void * (*)(size_t, void *)) &IGESBasic_HArray2OfHArray1OfReal::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESBasic_HArray2OfHArray1OfReal.def_static("operator delete_", (void (*)(void *, void *)) &IGESBasic_HArray2OfHArray1OfReal::operator delete, "None", py::arg(""), py::arg(""));
// cls_IGESBasic_HArray2OfHArray1OfReal.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &IGESBasic_HArray2OfHArray1OfReal::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_IGESBasic_HArray2OfHArray1OfReal.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &IGESBasic_HArray2OfHArray1OfReal::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_IGESBasic_HArray2OfHArray1OfReal.def("Array2", (const IGESBasic_Array2OfHArray1OfReal & (IGESBasic_HArray2OfHArray1OfReal::*)() const) &IGESBasic_HArray2OfHArray1OfReal::Array2, "None");
cls_IGESBasic_HArray2OfHArray1OfReal.def("ChangeArray2", (IGESBasic_Array2OfHArray1OfReal & (IGESBasic_HArray2OfHArray1OfReal::*)()) &IGESBasic_HArray2OfHArray1OfReal::ChangeArray2, "None");
cls_IGESBasic_HArray2OfHArray1OfReal.def_static("get_type_name_", (const char * (*)()) &IGESBasic_HArray2OfHArray1OfReal::get_type_name, "None");
cls_IGESBasic_HArray2OfHArray1OfReal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_HArray2OfHArray1OfReal::get_type_descriptor, "None");
cls_IGESBasic_HArray2OfHArray1OfReal.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_HArray2OfHArray1OfReal::*)() const) &IGESBasic_HArray2OfHArray1OfReal::DynamicType, "None");

// CLASS: IGESBASIC_HIERARCHY
py::class_<IGESBasic_Hierarchy, opencascade::handle<IGESBasic_Hierarchy>, IGESData_IGESEntity> cls_IGESBasic_Hierarchy(mod, "IGESBasic_Hierarchy", "defines Hierarchy, Type <406> Form <10> in package IGESBasic Provides ability to control the hierarchy of each directory entry attribute.");

// Constructors
cls_IGESBasic_Hierarchy.def(py::init<>());

// Methods
cls_IGESBasic_Hierarchy.def("Init", (void (IGESBasic_Hierarchy::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &IGESBasic_Hierarchy::Init, "This method is used to set the fields of the class Hierarchy - nbPropVal : Number of Property values = 6 - aLineFont : indicates the line font - aView : indicates the view - aEntityLevel : indicates the entity level - aBlankStatus : indicates the blank status - aLineWt : indicates the line weight - aColorNum : indicates the color num aLineFont, aView, aEntityLevel, aBlankStatus, aLineWt and aColorNum can take 0 or 1. 0 : The directory entry attribute will apply to entities physically subordinate to this entity. 1 : The directory entry attribute of this entity will not apply to physically subordinate entities.", py::arg("nbPropVal"), py::arg("aLineFont"), py::arg("aView"), py::arg("anEntityLevel"), py::arg("aBlankStatus"), py::arg("aLineWt"), py::arg("aColorNum"));
cls_IGESBasic_Hierarchy.def("NbPropertyValues", (Standard_Integer (IGESBasic_Hierarchy::*)() const) &IGESBasic_Hierarchy::NbPropertyValues, "returns the number of property values, which should be 6");
cls_IGESBasic_Hierarchy.def("NewLineFont", (Standard_Integer (IGESBasic_Hierarchy::*)() const) &IGESBasic_Hierarchy::NewLineFont, "returns the line font");
cls_IGESBasic_Hierarchy.def("NewView", (Standard_Integer (IGESBasic_Hierarchy::*)() const) &IGESBasic_Hierarchy::NewView, "returns the view");
cls_IGESBasic_Hierarchy.def("NewEntityLevel", (Standard_Integer (IGESBasic_Hierarchy::*)() const) &IGESBasic_Hierarchy::NewEntityLevel, "returns the entity level");
cls_IGESBasic_Hierarchy.def("NewBlankStatus", (Standard_Integer (IGESBasic_Hierarchy::*)() const) &IGESBasic_Hierarchy::NewBlankStatus, "returns the blank status");
cls_IGESBasic_Hierarchy.def("NewLineWeight", (Standard_Integer (IGESBasic_Hierarchy::*)() const) &IGESBasic_Hierarchy::NewLineWeight, "returns the line weight");
cls_IGESBasic_Hierarchy.def("NewColorNum", (Standard_Integer (IGESBasic_Hierarchy::*)() const) &IGESBasic_Hierarchy::NewColorNum, "returns the color number");
cls_IGESBasic_Hierarchy.def_static("get_type_name_", (const char * (*)()) &IGESBasic_Hierarchy::get_type_name, "None");
cls_IGESBasic_Hierarchy.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_Hierarchy::get_type_descriptor, "None");
cls_IGESBasic_Hierarchy.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_Hierarchy::*)() const) &IGESBasic_Hierarchy::DynamicType, "None");

// CLASS: IGESBASIC_NAME
py::class_<IGESBasic_Name, opencascade::handle<IGESBasic_Name>, IGESData_NameEntity> cls_IGESBasic_Name(mod, "IGESBasic_Name", "defines Name, Type <406> Form <15> in package IGESBasic Used to specify a user defined name");

// Constructors
cls_IGESBasic_Name.def(py::init<>());

// Methods
cls_IGESBasic_Name.def("Init", (void (IGESBasic_Name::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &)) &IGESBasic_Name::Init, "This method is used to set the fields of the class Name - nbPropVal : Number of property values, always = 1 - aName : Stores the Name", py::arg("nbPropVal"), py::arg("aName"));
cls_IGESBasic_Name.def("NbPropertyValues", (Standard_Integer (IGESBasic_Name::*)() const) &IGESBasic_Name::NbPropertyValues, "returns the number of property values, which should be 1");
cls_IGESBasic_Name.def("Value", (opencascade::handle<TCollection_HAsciiString> (IGESBasic_Name::*)() const) &IGESBasic_Name::Value, "returns the user defined Name");
cls_IGESBasic_Name.def_static("get_type_name_", (const char * (*)()) &IGESBasic_Name::get_type_name, "None");
cls_IGESBasic_Name.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_Name::get_type_descriptor, "None");
cls_IGESBasic_Name.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_Name::*)() const) &IGESBasic_Name::DynamicType, "None");

// CLASS: IGESBASIC_ORDEREDGROUP
py::class_<IGESBasic_OrderedGroup, opencascade::handle<IGESBasic_OrderedGroup>, IGESBasic_Group> cls_IGESBasic_OrderedGroup(mod, "IGESBasic_OrderedGroup", "defines OrderedGroup, Type <402> Form <14> in package IGESBasic this class defines an Ordered Group with back pointers Allows a collection of a set of entities to be maintained as a single entity, but the group is ordered. It inherits from Group");

// Constructors
cls_IGESBasic_OrderedGroup.def(py::init<>());

// Methods
cls_IGESBasic_OrderedGroup.def_static("get_type_name_", (const char * (*)()) &IGESBasic_OrderedGroup::get_type_name, "None");
cls_IGESBasic_OrderedGroup.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_OrderedGroup::get_type_descriptor, "None");
cls_IGESBasic_OrderedGroup.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_OrderedGroup::*)() const) &IGESBasic_OrderedGroup::DynamicType, "None");

// CLASS: IGESBASIC_ORDEREDGROUPWITHOUTBACKP
py::class_<IGESBasic_OrderedGroupWithoutBackP, opencascade::handle<IGESBasic_OrderedGroupWithoutBackP>, IGESBasic_Group> cls_IGESBasic_OrderedGroupWithoutBackP(mod, "IGESBasic_OrderedGroupWithoutBackP", "defines OrderedGroupWithoutBackP, Type <402> Form <15> in package IGESBasic Allows a collection of a set of entities to be maintained as a single entity, but the group is ordered and there are no back pointers. It inherits from Group");

// Constructors
cls_IGESBasic_OrderedGroupWithoutBackP.def(py::init<>());

// Methods
cls_IGESBasic_OrderedGroupWithoutBackP.def_static("get_type_name_", (const char * (*)()) &IGESBasic_OrderedGroupWithoutBackP::get_type_name, "None");
cls_IGESBasic_OrderedGroupWithoutBackP.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_OrderedGroupWithoutBackP::get_type_descriptor, "None");
cls_IGESBasic_OrderedGroupWithoutBackP.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_OrderedGroupWithoutBackP::*)() const) &IGESBasic_OrderedGroupWithoutBackP::DynamicType, "None");

// CLASS: IGESBASIC_PROTOCOL
py::class_<IGESBasic_Protocol, opencascade::handle<IGESBasic_Protocol>, IGESData_Protocol> cls_IGESBasic_Protocol(mod, "IGESBasic_Protocol", "Description of Protocol for IGESBasic");

// Constructors
cls_IGESBasic_Protocol.def(py::init<>());

// Methods
cls_IGESBasic_Protocol.def("NbResources", (Standard_Integer (IGESBasic_Protocol::*)() const) &IGESBasic_Protocol::NbResources, "Gives the count of Resource Protocol. Here, one (Protocol from IGESData)");
cls_IGESBasic_Protocol.def("Resource", (opencascade::handle<Interface_Protocol> (IGESBasic_Protocol::*)(const Standard_Integer) const) &IGESBasic_Protocol::Resource, "Returns a Resource, given a rank.", py::arg("num"));
cls_IGESBasic_Protocol.def("TypeNumber", (Standard_Integer (IGESBasic_Protocol::*)(const opencascade::handle<Standard_Type> &) const) &IGESBasic_Protocol::TypeNumber, "Returns a Case Number, specific of each recognized Type This Case Number is then used in Libraries : the various Modules attached to this class of Protocol must use them in accordance (for a given value of TypeNumber, they must consider the same Type as the Protocol defines)", py::arg("atype"));
cls_IGESBasic_Protocol.def_static("get_type_name_", (const char * (*)()) &IGESBasic_Protocol::get_type_name, "None");
cls_IGESBasic_Protocol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_Protocol::get_type_descriptor, "None");
cls_IGESBasic_Protocol.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_Protocol::*)() const) &IGESBasic_Protocol::DynamicType, "None");

// CLASS: IGESBASIC_READWRITEMODULE
py::class_<IGESBasic_ReadWriteModule, opencascade::handle<IGESBasic_ReadWriteModule>, IGESData_ReadWriteModule> cls_IGESBasic_ReadWriteModule(mod, "IGESBasic_ReadWriteModule", "Defines basic File Access Module for IGESBasic (specific parts) Specific actions concern : Read and Write Own Parameters of an IGESEntity.");

// Constructors
cls_IGESBasic_ReadWriteModule.def(py::init<>());

// Methods
cls_IGESBasic_ReadWriteModule.def("CaseIGES", (Standard_Integer (IGESBasic_ReadWriteModule::*)(const Standard_Integer, const Standard_Integer) const) &IGESBasic_ReadWriteModule::CaseIGES, "Defines Case Numbers for Entities of IGESBasic", py::arg("typenum"), py::arg("formnum"));
cls_IGESBasic_ReadWriteModule.def("ReadOwnParams", (void (IGESBasic_ReadWriteModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESBasic_ReadWriteModule::ReadOwnParams, "Reads own parameters from file for an Entity of IGESBasic", py::arg("CN"), py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESBasic_ReadWriteModule.def("WriteOwnParams", (void (IGESBasic_ReadWriteModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, IGESData_IGESWriter &) const) &IGESBasic_ReadWriteModule::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("CN"), py::arg("ent"), py::arg("IW"));
cls_IGESBasic_ReadWriteModule.def_static("get_type_name_", (const char * (*)()) &IGESBasic_ReadWriteModule::get_type_name, "None");
cls_IGESBasic_ReadWriteModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_ReadWriteModule::get_type_descriptor, "None");
cls_IGESBasic_ReadWriteModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_ReadWriteModule::*)() const) &IGESBasic_ReadWriteModule::DynamicType, "None");

// CLASS: IGESBASIC_SINGLEPARENT
py::class_<IGESBasic_SingleParent, opencascade::handle<IGESBasic_SingleParent>, IGESData_SingleParentEntity> cls_IGESBasic_SingleParent(mod, "IGESBasic_SingleParent", "defines SingleParent, Type <402> Form <9> in package IGESBasic It defines a logical structure of one independent (parent) entity and one or more subordinate (children) entities");

// Constructors
cls_IGESBasic_SingleParent.def(py::init<>());

// Methods
cls_IGESBasic_SingleParent.def("Init", (void (IGESBasic_SingleParent::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_HArray1OfIGESEntity> &)) &IGESBasic_SingleParent::Init, "This method is used to set the fields of the class SingleParent - nbParentEntities : Indicates number of Parents, always = 1 - aParentEntity : Used to hold the Parent Entity - allChildren : Used to hold the children", py::arg("nbParentEntities"), py::arg("aParentEntity"), py::arg("allChildren"));
cls_IGESBasic_SingleParent.def("NbParentEntities", (Standard_Integer (IGESBasic_SingleParent::*)() const) &IGESBasic_SingleParent::NbParentEntities, "returns the number of Parent Entities, which should be 1");
cls_IGESBasic_SingleParent.def("SingleParent", (opencascade::handle<IGESData_IGESEntity> (IGESBasic_SingleParent::*)() const) &IGESBasic_SingleParent::SingleParent, "Returns the Parent Entity (inherited method)");
cls_IGESBasic_SingleParent.def("NbChildren", (Standard_Integer (IGESBasic_SingleParent::*)() const) &IGESBasic_SingleParent::NbChildren, "returns the number of children of the Parent");
cls_IGESBasic_SingleParent.def("Child", (opencascade::handle<IGESData_IGESEntity> (IGESBasic_SingleParent::*)(const Standard_Integer) const) &IGESBasic_SingleParent::Child, "returns the specific child as indicated by Index raises exception if Index <= 0 or Index > NbChildren()", py::arg("Index"));
cls_IGESBasic_SingleParent.def_static("get_type_name_", (const char * (*)()) &IGESBasic_SingleParent::get_type_name, "None");
cls_IGESBasic_SingleParent.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_SingleParent::get_type_descriptor, "None");
cls_IGESBasic_SingleParent.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_SingleParent::*)() const) &IGESBasic_SingleParent::DynamicType, "None");

// CLASS: IGESBASIC_SINGULARSUBFIGURE
py::class_<IGESBasic_SingularSubfigure, opencascade::handle<IGESBasic_SingularSubfigure>, IGESData_IGESEntity> cls_IGESBasic_SingularSubfigure(mod, "IGESBasic_SingularSubfigure", "defines SingularSubfigure, Type <408> Form <0> in package IGESBasic Defines the occurrence of a single instance of the defined Subfigure.");

// Constructors
cls_IGESBasic_SingularSubfigure.def(py::init<>());

// Methods
cls_IGESBasic_SingularSubfigure.def("Init", (void (IGESBasic_SingularSubfigure::*)(const opencascade::handle<IGESBasic_SubfigureDef> &, const gp_XYZ &, const Standard_Boolean, const Standard_Real)) &IGESBasic_SingularSubfigure::Init, "This method is used to set the fields of the class SingularSubfigure - aSubfigureDef : the Subfigure Definition entity - aTranslation : used to store the X,Y,Z coord - hasScale : Indicates the presence of scale factor - aScale : Used to store the scale factor", py::arg("aSubfigureDef"), py::arg("aTranslation"), py::arg("hasScale"), py::arg("aScale"));
cls_IGESBasic_SingularSubfigure.def("Subfigure", (opencascade::handle<IGESBasic_SubfigureDef> (IGESBasic_SingularSubfigure::*)() const) &IGESBasic_SingularSubfigure::Subfigure, "returns the subfigure definition entity");
cls_IGESBasic_SingularSubfigure.def("Translation", (gp_XYZ (IGESBasic_SingularSubfigure::*)() const) &IGESBasic_SingularSubfigure::Translation, "returns the X, Y, Z coordinates");
cls_IGESBasic_SingularSubfigure.def("ScaleFactor", (Standard_Real (IGESBasic_SingularSubfigure::*)() const) &IGESBasic_SingularSubfigure::ScaleFactor, "returns the scale factor if hasScaleFactor is False, returns 1.0 (default)");
cls_IGESBasic_SingularSubfigure.def("HasScaleFactor", (Standard_Boolean (IGESBasic_SingularSubfigure::*)() const) &IGESBasic_SingularSubfigure::HasScaleFactor, "returns a boolean indicating whether scale factor is present or not");
cls_IGESBasic_SingularSubfigure.def("TransformedTranslation", (gp_XYZ (IGESBasic_SingularSubfigure::*)() const) &IGESBasic_SingularSubfigure::TransformedTranslation, "returns the Translation after transformation");
cls_IGESBasic_SingularSubfigure.def_static("get_type_name_", (const char * (*)()) &IGESBasic_SingularSubfigure::get_type_name, "None");
cls_IGESBasic_SingularSubfigure.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_SingularSubfigure::get_type_descriptor, "None");
cls_IGESBasic_SingularSubfigure.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_SingularSubfigure::*)() const) &IGESBasic_SingularSubfigure::DynamicType, "None");

// CLASS: IGESBASIC_SPECIFICMODULE
py::class_<IGESBasic_SpecificModule, opencascade::handle<IGESBasic_SpecificModule>, IGESData_SpecificModule> cls_IGESBasic_SpecificModule(mod, "IGESBasic_SpecificModule", "Defines Services attached to IGES Entities : Dump & OwnCorrect, for IGESBasic");

// Constructors
cls_IGESBasic_SpecificModule.def(py::init<>());

// Methods
cls_IGESBasic_SpecificModule.def("OwnDump", (void (IGESBasic_SpecificModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESBasic_SpecificModule::OwnDump, "Specific Dump (own parameters) for IGESBasic", py::arg("CN"), py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));
cls_IGESBasic_SpecificModule.def("OwnCorrect", (Standard_Boolean (IGESBasic_SpecificModule::*)(const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &) const) &IGESBasic_SpecificModule::OwnCorrect, "Performs non-ambiguous Corrections on Entities which support them (AssocGroupType,Hierarchy,Name,SingleParent)", py::arg("CN"), py::arg("ent"));
cls_IGESBasic_SpecificModule.def_static("get_type_name_", (const char * (*)()) &IGESBasic_SpecificModule::get_type_name, "None");
cls_IGESBasic_SpecificModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_SpecificModule::get_type_descriptor, "None");
cls_IGESBasic_SpecificModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_SpecificModule::*)() const) &IGESBasic_SpecificModule::DynamicType, "None");

// CLASS: IGESBASIC_SUBFIGUREDEF
py::class_<IGESBasic_SubfigureDef, opencascade::handle<IGESBasic_SubfigureDef>, IGESData_IGESEntity> cls_IGESBasic_SubfigureDef(mod, "IGESBasic_SubfigureDef", "defines SubfigureDef, Type <308> Form <0> in package IGESBasic This Entity permits a single definition of a detail to be utilized in multiple instances in the creation of the whole picture");

// Constructors
cls_IGESBasic_SubfigureDef.def(py::init<>());

// Methods
cls_IGESBasic_SubfigureDef.def("Init", (void (IGESBasic_SubfigureDef::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<IGESData_HArray1OfIGESEntity> &)) &IGESBasic_SubfigureDef::Init, "This method is used to set the fields of the class SubfigureDef - aDepth : It indicates the amount of nesting - aName : the subfigure name - allAssocEntities : the associated entities", py::arg("aDepth"), py::arg("aName"), py::arg("allAssocEntities"));
cls_IGESBasic_SubfigureDef.def("Depth", (Standard_Integer (IGESBasic_SubfigureDef::*)() const) &IGESBasic_SubfigureDef::Depth, "returns depth of the Subfigure if theDepth = 0 - No reference to any subfigure instance.");
cls_IGESBasic_SubfigureDef.def("Name", (opencascade::handle<TCollection_HAsciiString> (IGESBasic_SubfigureDef::*)() const) &IGESBasic_SubfigureDef::Name, "returns the name of Subfigure");
cls_IGESBasic_SubfigureDef.def("NbEntities", (Standard_Integer (IGESBasic_SubfigureDef::*)() const) &IGESBasic_SubfigureDef::NbEntities, "returns number of entities. Is greater than or equal to zero.");
cls_IGESBasic_SubfigureDef.def("AssociatedEntity", (opencascade::handle<IGESData_IGESEntity> (IGESBasic_SubfigureDef::*)(const Standard_Integer) const) &IGESBasic_SubfigureDef::AssociatedEntity, "returns the specific entity as indicated by Index raises exception if Index <= 0 or Index > NbEntities()", py::arg("Index"));
cls_IGESBasic_SubfigureDef.def("Value", (opencascade::handle<Standard_Transient> (IGESBasic_SubfigureDef::*)(const Standard_Integer) const) &IGESBasic_SubfigureDef::Value, "returns the specific entity as indicated by Index raises exception if Index <= 0 or Index > NbEntities()", py::arg("Index"));
cls_IGESBasic_SubfigureDef.def_static("get_type_name_", (const char * (*)()) &IGESBasic_SubfigureDef::get_type_name, "None");
cls_IGESBasic_SubfigureDef.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_SubfigureDef::get_type_descriptor, "None");
cls_IGESBasic_SubfigureDef.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_SubfigureDef::*)() const) &IGESBasic_SubfigureDef::DynamicType, "None");

// CLASS: IGESBASIC_TOOLASSOCGROUPTYPE
py::class_<IGESBasic_ToolAssocGroupType> cls_IGESBasic_ToolAssocGroupType(mod, "IGESBasic_ToolAssocGroupType", "Tool to work on a AssocGroupType. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESBasic_ToolAssocGroupType.def(py::init<>());

// Methods
// cls_IGESBasic_ToolAssocGroupType.def_static("operator new_", (void * (*)(size_t)) &IGESBasic_ToolAssocGroupType::operator new, "None", py::arg("theSize"));
// cls_IGESBasic_ToolAssocGroupType.def_static("operator delete_", (void (*)(void *)) &IGESBasic_ToolAssocGroupType::operator delete, "None", py::arg("theAddress"));
// cls_IGESBasic_ToolAssocGroupType.def_static("operator new[]_", (void * (*)(size_t)) &IGESBasic_ToolAssocGroupType::operator new[], "None", py::arg("theSize"));
// cls_IGESBasic_ToolAssocGroupType.def_static("operator delete[]_", (void (*)(void *)) &IGESBasic_ToolAssocGroupType::operator delete[], "None", py::arg("theAddress"));
// cls_IGESBasic_ToolAssocGroupType.def_static("operator new_", (void * (*)(size_t, void *)) &IGESBasic_ToolAssocGroupType::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESBasic_ToolAssocGroupType.def_static("operator delete_", (void (*)(void *, void *)) &IGESBasic_ToolAssocGroupType::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESBasic_ToolAssocGroupType.def("ReadOwnParams", (void (IGESBasic_ToolAssocGroupType::*)(const opencascade::handle<IGESBasic_AssocGroupType> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESBasic_ToolAssocGroupType::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESBasic_ToolAssocGroupType.def("WriteOwnParams", (void (IGESBasic_ToolAssocGroupType::*)(const opencascade::handle<IGESBasic_AssocGroupType> &, IGESData_IGESWriter &) const) &IGESBasic_ToolAssocGroupType::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESBasic_ToolAssocGroupType.def("OwnShared", (void (IGESBasic_ToolAssocGroupType::*)(const opencascade::handle<IGESBasic_AssocGroupType> &, Interface_EntityIterator &) const) &IGESBasic_ToolAssocGroupType::OwnShared, "Lists the Entities shared by a AssocGroupType <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESBasic_ToolAssocGroupType.def("OwnCorrect", (Standard_Boolean (IGESBasic_ToolAssocGroupType::*)(const opencascade::handle<IGESBasic_AssocGroupType> &) const) &IGESBasic_ToolAssocGroupType::OwnCorrect, "Sets automatic unambiguous Correction on a AssocGroupType (NbData forced to 2)", py::arg("ent"));
cls_IGESBasic_ToolAssocGroupType.def("DirChecker", (IGESData_DirChecker (IGESBasic_ToolAssocGroupType::*)(const opencascade::handle<IGESBasic_AssocGroupType> &) const) &IGESBasic_ToolAssocGroupType::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESBasic_ToolAssocGroupType.def("OwnCheck", (void (IGESBasic_ToolAssocGroupType::*)(const opencascade::handle<IGESBasic_AssocGroupType> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESBasic_ToolAssocGroupType::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESBasic_ToolAssocGroupType.def("OwnCopy", (void (IGESBasic_ToolAssocGroupType::*)(const opencascade::handle<IGESBasic_AssocGroupType> &, const opencascade::handle<IGESBasic_AssocGroupType> &, Interface_CopyTool &) const) &IGESBasic_ToolAssocGroupType::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESBasic_ToolAssocGroupType.def("OwnDump", (void (IGESBasic_ToolAssocGroupType::*)(const opencascade::handle<IGESBasic_AssocGroupType> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESBasic_ToolAssocGroupType::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESBASIC_TOOLEXTERNALREFERENCEFILE
py::class_<IGESBasic_ToolExternalReferenceFile> cls_IGESBasic_ToolExternalReferenceFile(mod, "IGESBasic_ToolExternalReferenceFile", "Tool to work on a ExternalReferenceFile. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESBasic_ToolExternalReferenceFile.def(py::init<>());

// Methods
// cls_IGESBasic_ToolExternalReferenceFile.def_static("operator new_", (void * (*)(size_t)) &IGESBasic_ToolExternalReferenceFile::operator new, "None", py::arg("theSize"));
// cls_IGESBasic_ToolExternalReferenceFile.def_static("operator delete_", (void (*)(void *)) &IGESBasic_ToolExternalReferenceFile::operator delete, "None", py::arg("theAddress"));
// cls_IGESBasic_ToolExternalReferenceFile.def_static("operator new[]_", (void * (*)(size_t)) &IGESBasic_ToolExternalReferenceFile::operator new[], "None", py::arg("theSize"));
// cls_IGESBasic_ToolExternalReferenceFile.def_static("operator delete[]_", (void (*)(void *)) &IGESBasic_ToolExternalReferenceFile::operator delete[], "None", py::arg("theAddress"));
// cls_IGESBasic_ToolExternalReferenceFile.def_static("operator new_", (void * (*)(size_t, void *)) &IGESBasic_ToolExternalReferenceFile::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESBasic_ToolExternalReferenceFile.def_static("operator delete_", (void (*)(void *, void *)) &IGESBasic_ToolExternalReferenceFile::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESBasic_ToolExternalReferenceFile.def("ReadOwnParams", (void (IGESBasic_ToolExternalReferenceFile::*)(const opencascade::handle<IGESBasic_ExternalReferenceFile> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESBasic_ToolExternalReferenceFile::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESBasic_ToolExternalReferenceFile.def("WriteOwnParams", (void (IGESBasic_ToolExternalReferenceFile::*)(const opencascade::handle<IGESBasic_ExternalReferenceFile> &, IGESData_IGESWriter &) const) &IGESBasic_ToolExternalReferenceFile::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESBasic_ToolExternalReferenceFile.def("OwnShared", (void (IGESBasic_ToolExternalReferenceFile::*)(const opencascade::handle<IGESBasic_ExternalReferenceFile> &, Interface_EntityIterator &) const) &IGESBasic_ToolExternalReferenceFile::OwnShared, "Lists the Entities shared by a ExternalReferenceFile <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESBasic_ToolExternalReferenceFile.def("DirChecker", (IGESData_DirChecker (IGESBasic_ToolExternalReferenceFile::*)(const opencascade::handle<IGESBasic_ExternalReferenceFile> &) const) &IGESBasic_ToolExternalReferenceFile::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESBasic_ToolExternalReferenceFile.def("OwnCheck", (void (IGESBasic_ToolExternalReferenceFile::*)(const opencascade::handle<IGESBasic_ExternalReferenceFile> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESBasic_ToolExternalReferenceFile::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESBasic_ToolExternalReferenceFile.def("OwnCopy", (void (IGESBasic_ToolExternalReferenceFile::*)(const opencascade::handle<IGESBasic_ExternalReferenceFile> &, const opencascade::handle<IGESBasic_ExternalReferenceFile> &, Interface_CopyTool &) const) &IGESBasic_ToolExternalReferenceFile::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESBasic_ToolExternalReferenceFile.def("OwnDump", (void (IGESBasic_ToolExternalReferenceFile::*)(const opencascade::handle<IGESBasic_ExternalReferenceFile> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESBasic_ToolExternalReferenceFile::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESBASIC_TOOLEXTERNALREFFILE
py::class_<IGESBasic_ToolExternalRefFile> cls_IGESBasic_ToolExternalRefFile(mod, "IGESBasic_ToolExternalRefFile", "Tool to work on a ExternalRefFile. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESBasic_ToolExternalRefFile.def(py::init<>());

// Methods
// cls_IGESBasic_ToolExternalRefFile.def_static("operator new_", (void * (*)(size_t)) &IGESBasic_ToolExternalRefFile::operator new, "None", py::arg("theSize"));
// cls_IGESBasic_ToolExternalRefFile.def_static("operator delete_", (void (*)(void *)) &IGESBasic_ToolExternalRefFile::operator delete, "None", py::arg("theAddress"));
// cls_IGESBasic_ToolExternalRefFile.def_static("operator new[]_", (void * (*)(size_t)) &IGESBasic_ToolExternalRefFile::operator new[], "None", py::arg("theSize"));
// cls_IGESBasic_ToolExternalRefFile.def_static("operator delete[]_", (void (*)(void *)) &IGESBasic_ToolExternalRefFile::operator delete[], "None", py::arg("theAddress"));
// cls_IGESBasic_ToolExternalRefFile.def_static("operator new_", (void * (*)(size_t, void *)) &IGESBasic_ToolExternalRefFile::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESBasic_ToolExternalRefFile.def_static("operator delete_", (void (*)(void *, void *)) &IGESBasic_ToolExternalRefFile::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESBasic_ToolExternalRefFile.def("ReadOwnParams", (void (IGESBasic_ToolExternalRefFile::*)(const opencascade::handle<IGESBasic_ExternalRefFile> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESBasic_ToolExternalRefFile::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESBasic_ToolExternalRefFile.def("WriteOwnParams", (void (IGESBasic_ToolExternalRefFile::*)(const opencascade::handle<IGESBasic_ExternalRefFile> &, IGESData_IGESWriter &) const) &IGESBasic_ToolExternalRefFile::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESBasic_ToolExternalRefFile.def("OwnShared", (void (IGESBasic_ToolExternalRefFile::*)(const opencascade::handle<IGESBasic_ExternalRefFile> &, Interface_EntityIterator &) const) &IGESBasic_ToolExternalRefFile::OwnShared, "Lists the Entities shared by a ExternalRefFile <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESBasic_ToolExternalRefFile.def("DirChecker", (IGESData_DirChecker (IGESBasic_ToolExternalRefFile::*)(const opencascade::handle<IGESBasic_ExternalRefFile> &) const) &IGESBasic_ToolExternalRefFile::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESBasic_ToolExternalRefFile.def("OwnCheck", (void (IGESBasic_ToolExternalRefFile::*)(const opencascade::handle<IGESBasic_ExternalRefFile> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESBasic_ToolExternalRefFile::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESBasic_ToolExternalRefFile.def("OwnCopy", (void (IGESBasic_ToolExternalRefFile::*)(const opencascade::handle<IGESBasic_ExternalRefFile> &, const opencascade::handle<IGESBasic_ExternalRefFile> &, Interface_CopyTool &) const) &IGESBasic_ToolExternalRefFile::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESBasic_ToolExternalRefFile.def("OwnDump", (void (IGESBasic_ToolExternalRefFile::*)(const opencascade::handle<IGESBasic_ExternalRefFile> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESBasic_ToolExternalRefFile::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESBASIC_TOOLEXTERNALREFFILEINDEX
py::class_<IGESBasic_ToolExternalRefFileIndex> cls_IGESBasic_ToolExternalRefFileIndex(mod, "IGESBasic_ToolExternalRefFileIndex", "Tool to work on a ExternalRefFileIndex. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESBasic_ToolExternalRefFileIndex.def(py::init<>());

// Methods
// cls_IGESBasic_ToolExternalRefFileIndex.def_static("operator new_", (void * (*)(size_t)) &IGESBasic_ToolExternalRefFileIndex::operator new, "None", py::arg("theSize"));
// cls_IGESBasic_ToolExternalRefFileIndex.def_static("operator delete_", (void (*)(void *)) &IGESBasic_ToolExternalRefFileIndex::operator delete, "None", py::arg("theAddress"));
// cls_IGESBasic_ToolExternalRefFileIndex.def_static("operator new[]_", (void * (*)(size_t)) &IGESBasic_ToolExternalRefFileIndex::operator new[], "None", py::arg("theSize"));
// cls_IGESBasic_ToolExternalRefFileIndex.def_static("operator delete[]_", (void (*)(void *)) &IGESBasic_ToolExternalRefFileIndex::operator delete[], "None", py::arg("theAddress"));
// cls_IGESBasic_ToolExternalRefFileIndex.def_static("operator new_", (void * (*)(size_t, void *)) &IGESBasic_ToolExternalRefFileIndex::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESBasic_ToolExternalRefFileIndex.def_static("operator delete_", (void (*)(void *, void *)) &IGESBasic_ToolExternalRefFileIndex::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESBasic_ToolExternalRefFileIndex.def("ReadOwnParams", (void (IGESBasic_ToolExternalRefFileIndex::*)(const opencascade::handle<IGESBasic_ExternalRefFileIndex> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESBasic_ToolExternalRefFileIndex::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESBasic_ToolExternalRefFileIndex.def("WriteOwnParams", (void (IGESBasic_ToolExternalRefFileIndex::*)(const opencascade::handle<IGESBasic_ExternalRefFileIndex> &, IGESData_IGESWriter &) const) &IGESBasic_ToolExternalRefFileIndex::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESBasic_ToolExternalRefFileIndex.def("OwnShared", (void (IGESBasic_ToolExternalRefFileIndex::*)(const opencascade::handle<IGESBasic_ExternalRefFileIndex> &, Interface_EntityIterator &) const) &IGESBasic_ToolExternalRefFileIndex::OwnShared, "Lists the Entities shared by a ExternalRefFileIndex <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESBasic_ToolExternalRefFileIndex.def("DirChecker", (IGESData_DirChecker (IGESBasic_ToolExternalRefFileIndex::*)(const opencascade::handle<IGESBasic_ExternalRefFileIndex> &) const) &IGESBasic_ToolExternalRefFileIndex::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESBasic_ToolExternalRefFileIndex.def("OwnCheck", (void (IGESBasic_ToolExternalRefFileIndex::*)(const opencascade::handle<IGESBasic_ExternalRefFileIndex> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESBasic_ToolExternalRefFileIndex::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESBasic_ToolExternalRefFileIndex.def("OwnCopy", (void (IGESBasic_ToolExternalRefFileIndex::*)(const opencascade::handle<IGESBasic_ExternalRefFileIndex> &, const opencascade::handle<IGESBasic_ExternalRefFileIndex> &, Interface_CopyTool &) const) &IGESBasic_ToolExternalRefFileIndex::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESBasic_ToolExternalRefFileIndex.def("OwnDump", (void (IGESBasic_ToolExternalRefFileIndex::*)(const opencascade::handle<IGESBasic_ExternalRefFileIndex> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESBasic_ToolExternalRefFileIndex::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESBASIC_TOOLEXTERNALREFFILENAME
py::class_<IGESBasic_ToolExternalRefFileName> cls_IGESBasic_ToolExternalRefFileName(mod, "IGESBasic_ToolExternalRefFileName", "Tool to work on a ExternalRefFileName. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESBasic_ToolExternalRefFileName.def(py::init<>());

// Methods
// cls_IGESBasic_ToolExternalRefFileName.def_static("operator new_", (void * (*)(size_t)) &IGESBasic_ToolExternalRefFileName::operator new, "None", py::arg("theSize"));
// cls_IGESBasic_ToolExternalRefFileName.def_static("operator delete_", (void (*)(void *)) &IGESBasic_ToolExternalRefFileName::operator delete, "None", py::arg("theAddress"));
// cls_IGESBasic_ToolExternalRefFileName.def_static("operator new[]_", (void * (*)(size_t)) &IGESBasic_ToolExternalRefFileName::operator new[], "None", py::arg("theSize"));
// cls_IGESBasic_ToolExternalRefFileName.def_static("operator delete[]_", (void (*)(void *)) &IGESBasic_ToolExternalRefFileName::operator delete[], "None", py::arg("theAddress"));
// cls_IGESBasic_ToolExternalRefFileName.def_static("operator new_", (void * (*)(size_t, void *)) &IGESBasic_ToolExternalRefFileName::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESBasic_ToolExternalRefFileName.def_static("operator delete_", (void (*)(void *, void *)) &IGESBasic_ToolExternalRefFileName::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESBasic_ToolExternalRefFileName.def("ReadOwnParams", (void (IGESBasic_ToolExternalRefFileName::*)(const opencascade::handle<IGESBasic_ExternalRefFileName> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESBasic_ToolExternalRefFileName::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESBasic_ToolExternalRefFileName.def("WriteOwnParams", (void (IGESBasic_ToolExternalRefFileName::*)(const opencascade::handle<IGESBasic_ExternalRefFileName> &, IGESData_IGESWriter &) const) &IGESBasic_ToolExternalRefFileName::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESBasic_ToolExternalRefFileName.def("OwnShared", (void (IGESBasic_ToolExternalRefFileName::*)(const opencascade::handle<IGESBasic_ExternalRefFileName> &, Interface_EntityIterator &) const) &IGESBasic_ToolExternalRefFileName::OwnShared, "Lists the Entities shared by a ExternalRefFileName <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESBasic_ToolExternalRefFileName.def("DirChecker", (IGESData_DirChecker (IGESBasic_ToolExternalRefFileName::*)(const opencascade::handle<IGESBasic_ExternalRefFileName> &) const) &IGESBasic_ToolExternalRefFileName::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESBasic_ToolExternalRefFileName.def("OwnCheck", (void (IGESBasic_ToolExternalRefFileName::*)(const opencascade::handle<IGESBasic_ExternalRefFileName> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESBasic_ToolExternalRefFileName::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESBasic_ToolExternalRefFileName.def("OwnCopy", (void (IGESBasic_ToolExternalRefFileName::*)(const opencascade::handle<IGESBasic_ExternalRefFileName> &, const opencascade::handle<IGESBasic_ExternalRefFileName> &, Interface_CopyTool &) const) &IGESBasic_ToolExternalRefFileName::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESBasic_ToolExternalRefFileName.def("OwnDump", (void (IGESBasic_ToolExternalRefFileName::*)(const opencascade::handle<IGESBasic_ExternalRefFileName> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESBasic_ToolExternalRefFileName::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESBASIC_TOOLEXTERNALREFLIBNAME
py::class_<IGESBasic_ToolExternalRefLibName> cls_IGESBasic_ToolExternalRefLibName(mod, "IGESBasic_ToolExternalRefLibName", "Tool to work on a ExternalRefLibName. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESBasic_ToolExternalRefLibName.def(py::init<>());

// Methods
// cls_IGESBasic_ToolExternalRefLibName.def_static("operator new_", (void * (*)(size_t)) &IGESBasic_ToolExternalRefLibName::operator new, "None", py::arg("theSize"));
// cls_IGESBasic_ToolExternalRefLibName.def_static("operator delete_", (void (*)(void *)) &IGESBasic_ToolExternalRefLibName::operator delete, "None", py::arg("theAddress"));
// cls_IGESBasic_ToolExternalRefLibName.def_static("operator new[]_", (void * (*)(size_t)) &IGESBasic_ToolExternalRefLibName::operator new[], "None", py::arg("theSize"));
// cls_IGESBasic_ToolExternalRefLibName.def_static("operator delete[]_", (void (*)(void *)) &IGESBasic_ToolExternalRefLibName::operator delete[], "None", py::arg("theAddress"));
// cls_IGESBasic_ToolExternalRefLibName.def_static("operator new_", (void * (*)(size_t, void *)) &IGESBasic_ToolExternalRefLibName::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESBasic_ToolExternalRefLibName.def_static("operator delete_", (void (*)(void *, void *)) &IGESBasic_ToolExternalRefLibName::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESBasic_ToolExternalRefLibName.def("ReadOwnParams", (void (IGESBasic_ToolExternalRefLibName::*)(const opencascade::handle<IGESBasic_ExternalRefLibName> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESBasic_ToolExternalRefLibName::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESBasic_ToolExternalRefLibName.def("WriteOwnParams", (void (IGESBasic_ToolExternalRefLibName::*)(const opencascade::handle<IGESBasic_ExternalRefLibName> &, IGESData_IGESWriter &) const) &IGESBasic_ToolExternalRefLibName::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESBasic_ToolExternalRefLibName.def("OwnShared", (void (IGESBasic_ToolExternalRefLibName::*)(const opencascade::handle<IGESBasic_ExternalRefLibName> &, Interface_EntityIterator &) const) &IGESBasic_ToolExternalRefLibName::OwnShared, "Lists the Entities shared by a ExternalRefLibName <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESBasic_ToolExternalRefLibName.def("DirChecker", (IGESData_DirChecker (IGESBasic_ToolExternalRefLibName::*)(const opencascade::handle<IGESBasic_ExternalRefLibName> &) const) &IGESBasic_ToolExternalRefLibName::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESBasic_ToolExternalRefLibName.def("OwnCheck", (void (IGESBasic_ToolExternalRefLibName::*)(const opencascade::handle<IGESBasic_ExternalRefLibName> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESBasic_ToolExternalRefLibName::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESBasic_ToolExternalRefLibName.def("OwnCopy", (void (IGESBasic_ToolExternalRefLibName::*)(const opencascade::handle<IGESBasic_ExternalRefLibName> &, const opencascade::handle<IGESBasic_ExternalRefLibName> &, Interface_CopyTool &) const) &IGESBasic_ToolExternalRefLibName::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESBasic_ToolExternalRefLibName.def("OwnDump", (void (IGESBasic_ToolExternalRefLibName::*)(const opencascade::handle<IGESBasic_ExternalRefLibName> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESBasic_ToolExternalRefLibName::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESBASIC_TOOLEXTERNALREFNAME
py::class_<IGESBasic_ToolExternalRefName> cls_IGESBasic_ToolExternalRefName(mod, "IGESBasic_ToolExternalRefName", "Tool to work on a ExternalRefName. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESBasic_ToolExternalRefName.def(py::init<>());

// Methods
// cls_IGESBasic_ToolExternalRefName.def_static("operator new_", (void * (*)(size_t)) &IGESBasic_ToolExternalRefName::operator new, "None", py::arg("theSize"));
// cls_IGESBasic_ToolExternalRefName.def_static("operator delete_", (void (*)(void *)) &IGESBasic_ToolExternalRefName::operator delete, "None", py::arg("theAddress"));
// cls_IGESBasic_ToolExternalRefName.def_static("operator new[]_", (void * (*)(size_t)) &IGESBasic_ToolExternalRefName::operator new[], "None", py::arg("theSize"));
// cls_IGESBasic_ToolExternalRefName.def_static("operator delete[]_", (void (*)(void *)) &IGESBasic_ToolExternalRefName::operator delete[], "None", py::arg("theAddress"));
// cls_IGESBasic_ToolExternalRefName.def_static("operator new_", (void * (*)(size_t, void *)) &IGESBasic_ToolExternalRefName::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESBasic_ToolExternalRefName.def_static("operator delete_", (void (*)(void *, void *)) &IGESBasic_ToolExternalRefName::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESBasic_ToolExternalRefName.def("ReadOwnParams", (void (IGESBasic_ToolExternalRefName::*)(const opencascade::handle<IGESBasic_ExternalRefName> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESBasic_ToolExternalRefName::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESBasic_ToolExternalRefName.def("WriteOwnParams", (void (IGESBasic_ToolExternalRefName::*)(const opencascade::handle<IGESBasic_ExternalRefName> &, IGESData_IGESWriter &) const) &IGESBasic_ToolExternalRefName::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESBasic_ToolExternalRefName.def("OwnShared", (void (IGESBasic_ToolExternalRefName::*)(const opencascade::handle<IGESBasic_ExternalRefName> &, Interface_EntityIterator &) const) &IGESBasic_ToolExternalRefName::OwnShared, "Lists the Entities shared by a ExternalRefName <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESBasic_ToolExternalRefName.def("DirChecker", (IGESData_DirChecker (IGESBasic_ToolExternalRefName::*)(const opencascade::handle<IGESBasic_ExternalRefName> &) const) &IGESBasic_ToolExternalRefName::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESBasic_ToolExternalRefName.def("OwnCheck", (void (IGESBasic_ToolExternalRefName::*)(const opencascade::handle<IGESBasic_ExternalRefName> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESBasic_ToolExternalRefName::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESBasic_ToolExternalRefName.def("OwnCopy", (void (IGESBasic_ToolExternalRefName::*)(const opencascade::handle<IGESBasic_ExternalRefName> &, const opencascade::handle<IGESBasic_ExternalRefName> &, Interface_CopyTool &) const) &IGESBasic_ToolExternalRefName::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESBasic_ToolExternalRefName.def("OwnDump", (void (IGESBasic_ToolExternalRefName::*)(const opencascade::handle<IGESBasic_ExternalRefName> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESBasic_ToolExternalRefName::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESBASIC_TOOLGROUP
py::class_<IGESBasic_ToolGroup> cls_IGESBasic_ToolGroup(mod, "IGESBasic_ToolGroup", "Tool to work on a Group. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESBasic_ToolGroup.def(py::init<>());

// Methods
// cls_IGESBasic_ToolGroup.def_static("operator new_", (void * (*)(size_t)) &IGESBasic_ToolGroup::operator new, "None", py::arg("theSize"));
// cls_IGESBasic_ToolGroup.def_static("operator delete_", (void (*)(void *)) &IGESBasic_ToolGroup::operator delete, "None", py::arg("theAddress"));
// cls_IGESBasic_ToolGroup.def_static("operator new[]_", (void * (*)(size_t)) &IGESBasic_ToolGroup::operator new[], "None", py::arg("theSize"));
// cls_IGESBasic_ToolGroup.def_static("operator delete[]_", (void (*)(void *)) &IGESBasic_ToolGroup::operator delete[], "None", py::arg("theAddress"));
// cls_IGESBasic_ToolGroup.def_static("operator new_", (void * (*)(size_t, void *)) &IGESBasic_ToolGroup::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESBasic_ToolGroup.def_static("operator delete_", (void (*)(void *, void *)) &IGESBasic_ToolGroup::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESBasic_ToolGroup.def("ReadOwnParams", (void (IGESBasic_ToolGroup::*)(const opencascade::handle<IGESBasic_Group> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESBasic_ToolGroup::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESBasic_ToolGroup.def("WriteOwnParams", (void (IGESBasic_ToolGroup::*)(const opencascade::handle<IGESBasic_Group> &, IGESData_IGESWriter &) const) &IGESBasic_ToolGroup::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESBasic_ToolGroup.def("OwnShared", (void (IGESBasic_ToolGroup::*)(const opencascade::handle<IGESBasic_Group> &, Interface_EntityIterator &) const) &IGESBasic_ToolGroup::OwnShared, "Lists the Entities shared by a Group <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESBasic_ToolGroup.def("OwnCorrect", (Standard_Boolean (IGESBasic_ToolGroup::*)(const opencascade::handle<IGESBasic_Group> &) const) &IGESBasic_ToolGroup::OwnCorrect, "Sets automatic unambiguous Correction on a Group (Null Elements are removed from list)", py::arg("ent"));
cls_IGESBasic_ToolGroup.def("DirChecker", (IGESData_DirChecker (IGESBasic_ToolGroup::*)(const opencascade::handle<IGESBasic_Group> &) const) &IGESBasic_ToolGroup::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESBasic_ToolGroup.def("OwnCheck", (void (IGESBasic_ToolGroup::*)(const opencascade::handle<IGESBasic_Group> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESBasic_ToolGroup::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESBasic_ToolGroup.def("OwnCopy", (void (IGESBasic_ToolGroup::*)(const opencascade::handle<IGESBasic_Group> &, const opencascade::handle<IGESBasic_Group> &, Interface_CopyTool &) const) &IGESBasic_ToolGroup::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESBasic_ToolGroup.def("OwnDump", (void (IGESBasic_ToolGroup::*)(const opencascade::handle<IGESBasic_Group> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESBasic_ToolGroup::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESBASIC_TOOLGROUPWITHOUTBACKP
py::class_<IGESBasic_ToolGroupWithoutBackP> cls_IGESBasic_ToolGroupWithoutBackP(mod, "IGESBasic_ToolGroupWithoutBackP", "Tool to work on a GroupWithoutBackP. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESBasic_ToolGroupWithoutBackP.def(py::init<>());

// Methods
// cls_IGESBasic_ToolGroupWithoutBackP.def_static("operator new_", (void * (*)(size_t)) &IGESBasic_ToolGroupWithoutBackP::operator new, "None", py::arg("theSize"));
// cls_IGESBasic_ToolGroupWithoutBackP.def_static("operator delete_", (void (*)(void *)) &IGESBasic_ToolGroupWithoutBackP::operator delete, "None", py::arg("theAddress"));
// cls_IGESBasic_ToolGroupWithoutBackP.def_static("operator new[]_", (void * (*)(size_t)) &IGESBasic_ToolGroupWithoutBackP::operator new[], "None", py::arg("theSize"));
// cls_IGESBasic_ToolGroupWithoutBackP.def_static("operator delete[]_", (void (*)(void *)) &IGESBasic_ToolGroupWithoutBackP::operator delete[], "None", py::arg("theAddress"));
// cls_IGESBasic_ToolGroupWithoutBackP.def_static("operator new_", (void * (*)(size_t, void *)) &IGESBasic_ToolGroupWithoutBackP::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESBasic_ToolGroupWithoutBackP.def_static("operator delete_", (void (*)(void *, void *)) &IGESBasic_ToolGroupWithoutBackP::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESBasic_ToolGroupWithoutBackP.def("ReadOwnParams", (void (IGESBasic_ToolGroupWithoutBackP::*)(const opencascade::handle<IGESBasic_GroupWithoutBackP> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESBasic_ToolGroupWithoutBackP::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESBasic_ToolGroupWithoutBackP.def("WriteOwnParams", (void (IGESBasic_ToolGroupWithoutBackP::*)(const opencascade::handle<IGESBasic_GroupWithoutBackP> &, IGESData_IGESWriter &) const) &IGESBasic_ToolGroupWithoutBackP::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESBasic_ToolGroupWithoutBackP.def("OwnShared", (void (IGESBasic_ToolGroupWithoutBackP::*)(const opencascade::handle<IGESBasic_GroupWithoutBackP> &, Interface_EntityIterator &) const) &IGESBasic_ToolGroupWithoutBackP::OwnShared, "Lists the Entities shared by a GroupWithoutBackP <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESBasic_ToolGroupWithoutBackP.def("OwnCorrect", (Standard_Boolean (IGESBasic_ToolGroupWithoutBackP::*)(const opencascade::handle<IGESBasic_GroupWithoutBackP> &) const) &IGESBasic_ToolGroupWithoutBackP::OwnCorrect, "Sets automatic unambiguous Correction on a GroupWithoutBackP (Null Elements are removed from list)", py::arg("ent"));
cls_IGESBasic_ToolGroupWithoutBackP.def("DirChecker", (IGESData_DirChecker (IGESBasic_ToolGroupWithoutBackP::*)(const opencascade::handle<IGESBasic_GroupWithoutBackP> &) const) &IGESBasic_ToolGroupWithoutBackP::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESBasic_ToolGroupWithoutBackP.def("OwnCheck", (void (IGESBasic_ToolGroupWithoutBackP::*)(const opencascade::handle<IGESBasic_GroupWithoutBackP> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESBasic_ToolGroupWithoutBackP::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESBasic_ToolGroupWithoutBackP.def("OwnCopy", (void (IGESBasic_ToolGroupWithoutBackP::*)(const opencascade::handle<IGESBasic_GroupWithoutBackP> &, const opencascade::handle<IGESBasic_GroupWithoutBackP> &, Interface_CopyTool &) const) &IGESBasic_ToolGroupWithoutBackP::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESBasic_ToolGroupWithoutBackP.def("OwnDump", (void (IGESBasic_ToolGroupWithoutBackP::*)(const opencascade::handle<IGESBasic_GroupWithoutBackP> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESBasic_ToolGroupWithoutBackP::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESBASIC_TOOLHIERARCHY
py::class_<IGESBasic_ToolHierarchy> cls_IGESBasic_ToolHierarchy(mod, "IGESBasic_ToolHierarchy", "Tool to work on a Hierarchy. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESBasic_ToolHierarchy.def(py::init<>());

// Methods
// cls_IGESBasic_ToolHierarchy.def_static("operator new_", (void * (*)(size_t)) &IGESBasic_ToolHierarchy::operator new, "None", py::arg("theSize"));
// cls_IGESBasic_ToolHierarchy.def_static("operator delete_", (void (*)(void *)) &IGESBasic_ToolHierarchy::operator delete, "None", py::arg("theAddress"));
// cls_IGESBasic_ToolHierarchy.def_static("operator new[]_", (void * (*)(size_t)) &IGESBasic_ToolHierarchy::operator new[], "None", py::arg("theSize"));
// cls_IGESBasic_ToolHierarchy.def_static("operator delete[]_", (void (*)(void *)) &IGESBasic_ToolHierarchy::operator delete[], "None", py::arg("theAddress"));
// cls_IGESBasic_ToolHierarchy.def_static("operator new_", (void * (*)(size_t, void *)) &IGESBasic_ToolHierarchy::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESBasic_ToolHierarchy.def_static("operator delete_", (void (*)(void *, void *)) &IGESBasic_ToolHierarchy::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESBasic_ToolHierarchy.def("ReadOwnParams", (void (IGESBasic_ToolHierarchy::*)(const opencascade::handle<IGESBasic_Hierarchy> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESBasic_ToolHierarchy::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESBasic_ToolHierarchy.def("WriteOwnParams", (void (IGESBasic_ToolHierarchy::*)(const opencascade::handle<IGESBasic_Hierarchy> &, IGESData_IGESWriter &) const) &IGESBasic_ToolHierarchy::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESBasic_ToolHierarchy.def("OwnShared", (void (IGESBasic_ToolHierarchy::*)(const opencascade::handle<IGESBasic_Hierarchy> &, Interface_EntityIterator &) const) &IGESBasic_ToolHierarchy::OwnShared, "Lists the Entities shared by a Hierarchy <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESBasic_ToolHierarchy.def("OwnCorrect", (Standard_Boolean (IGESBasic_ToolHierarchy::*)(const opencascade::handle<IGESBasic_Hierarchy> &) const) &IGESBasic_ToolHierarchy::OwnCorrect, "Sets automatic unambiguous Correction on a Hierarchy (NbPropertyValues forced to 6)", py::arg("ent"));
cls_IGESBasic_ToolHierarchy.def("DirChecker", (IGESData_DirChecker (IGESBasic_ToolHierarchy::*)(const opencascade::handle<IGESBasic_Hierarchy> &) const) &IGESBasic_ToolHierarchy::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESBasic_ToolHierarchy.def("OwnCheck", (void (IGESBasic_ToolHierarchy::*)(const opencascade::handle<IGESBasic_Hierarchy> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESBasic_ToolHierarchy::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESBasic_ToolHierarchy.def("OwnCopy", (void (IGESBasic_ToolHierarchy::*)(const opencascade::handle<IGESBasic_Hierarchy> &, const opencascade::handle<IGESBasic_Hierarchy> &, Interface_CopyTool &) const) &IGESBasic_ToolHierarchy::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESBasic_ToolHierarchy.def("OwnDump", (void (IGESBasic_ToolHierarchy::*)(const opencascade::handle<IGESBasic_Hierarchy> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESBasic_ToolHierarchy::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESBASIC_TOOLNAME
py::class_<IGESBasic_ToolName> cls_IGESBasic_ToolName(mod, "IGESBasic_ToolName", "Tool to work on a Name. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESBasic_ToolName.def(py::init<>());

// Methods
// cls_IGESBasic_ToolName.def_static("operator new_", (void * (*)(size_t)) &IGESBasic_ToolName::operator new, "None", py::arg("theSize"));
// cls_IGESBasic_ToolName.def_static("operator delete_", (void (*)(void *)) &IGESBasic_ToolName::operator delete, "None", py::arg("theAddress"));
// cls_IGESBasic_ToolName.def_static("operator new[]_", (void * (*)(size_t)) &IGESBasic_ToolName::operator new[], "None", py::arg("theSize"));
// cls_IGESBasic_ToolName.def_static("operator delete[]_", (void (*)(void *)) &IGESBasic_ToolName::operator delete[], "None", py::arg("theAddress"));
// cls_IGESBasic_ToolName.def_static("operator new_", (void * (*)(size_t, void *)) &IGESBasic_ToolName::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESBasic_ToolName.def_static("operator delete_", (void (*)(void *, void *)) &IGESBasic_ToolName::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESBasic_ToolName.def("ReadOwnParams", (void (IGESBasic_ToolName::*)(const opencascade::handle<IGESBasic_Name> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESBasic_ToolName::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESBasic_ToolName.def("WriteOwnParams", (void (IGESBasic_ToolName::*)(const opencascade::handle<IGESBasic_Name> &, IGESData_IGESWriter &) const) &IGESBasic_ToolName::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESBasic_ToolName.def("OwnShared", (void (IGESBasic_ToolName::*)(const opencascade::handle<IGESBasic_Name> &, Interface_EntityIterator &) const) &IGESBasic_ToolName::OwnShared, "Lists the Entities shared by a Name <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESBasic_ToolName.def("OwnCorrect", (Standard_Boolean (IGESBasic_ToolName::*)(const opencascade::handle<IGESBasic_Name> &) const) &IGESBasic_ToolName::OwnCorrect, "Sets automatic unambiguous Correction on a Name (NbPropertyValues forced to 1)", py::arg("ent"));
cls_IGESBasic_ToolName.def("DirChecker", (IGESData_DirChecker (IGESBasic_ToolName::*)(const opencascade::handle<IGESBasic_Name> &) const) &IGESBasic_ToolName::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESBasic_ToolName.def("OwnCheck", (void (IGESBasic_ToolName::*)(const opencascade::handle<IGESBasic_Name> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESBasic_ToolName::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESBasic_ToolName.def("OwnCopy", (void (IGESBasic_ToolName::*)(const opencascade::handle<IGESBasic_Name> &, const opencascade::handle<IGESBasic_Name> &, Interface_CopyTool &) const) &IGESBasic_ToolName::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESBasic_ToolName.def("OwnDump", (void (IGESBasic_ToolName::*)(const opencascade::handle<IGESBasic_Name> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESBasic_ToolName::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESBASIC_TOOLORDEREDGROUP
py::class_<IGESBasic_ToolOrderedGroup> cls_IGESBasic_ToolOrderedGroup(mod, "IGESBasic_ToolOrderedGroup", "Tool to work on a OrderedGroup. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESBasic_ToolOrderedGroup.def(py::init<>());

// Methods
// cls_IGESBasic_ToolOrderedGroup.def_static("operator new_", (void * (*)(size_t)) &IGESBasic_ToolOrderedGroup::operator new, "None", py::arg("theSize"));
// cls_IGESBasic_ToolOrderedGroup.def_static("operator delete_", (void (*)(void *)) &IGESBasic_ToolOrderedGroup::operator delete, "None", py::arg("theAddress"));
// cls_IGESBasic_ToolOrderedGroup.def_static("operator new[]_", (void * (*)(size_t)) &IGESBasic_ToolOrderedGroup::operator new[], "None", py::arg("theSize"));
// cls_IGESBasic_ToolOrderedGroup.def_static("operator delete[]_", (void (*)(void *)) &IGESBasic_ToolOrderedGroup::operator delete[], "None", py::arg("theAddress"));
// cls_IGESBasic_ToolOrderedGroup.def_static("operator new_", (void * (*)(size_t, void *)) &IGESBasic_ToolOrderedGroup::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESBasic_ToolOrderedGroup.def_static("operator delete_", (void (*)(void *, void *)) &IGESBasic_ToolOrderedGroup::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESBasic_ToolOrderedGroup.def("ReadOwnParams", (void (IGESBasic_ToolOrderedGroup::*)(const opencascade::handle<IGESBasic_OrderedGroup> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESBasic_ToolOrderedGroup::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESBasic_ToolOrderedGroup.def("WriteOwnParams", (void (IGESBasic_ToolOrderedGroup::*)(const opencascade::handle<IGESBasic_OrderedGroup> &, IGESData_IGESWriter &) const) &IGESBasic_ToolOrderedGroup::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESBasic_ToolOrderedGroup.def("OwnShared", (void (IGESBasic_ToolOrderedGroup::*)(const opencascade::handle<IGESBasic_OrderedGroup> &, Interface_EntityIterator &) const) &IGESBasic_ToolOrderedGroup::OwnShared, "Lists the Entities shared by a OrderedGroup <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESBasic_ToolOrderedGroup.def("OwnCorrect", (Standard_Boolean (IGESBasic_ToolOrderedGroup::*)(const opencascade::handle<IGESBasic_OrderedGroup> &) const) &IGESBasic_ToolOrderedGroup::OwnCorrect, "Sets automatic unambiguous Correction on an OrderedGroup (Null Elements are removed from list)", py::arg("ent"));
cls_IGESBasic_ToolOrderedGroup.def("DirChecker", (IGESData_DirChecker (IGESBasic_ToolOrderedGroup::*)(const opencascade::handle<IGESBasic_OrderedGroup> &) const) &IGESBasic_ToolOrderedGroup::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESBasic_ToolOrderedGroup.def("OwnCheck", (void (IGESBasic_ToolOrderedGroup::*)(const opencascade::handle<IGESBasic_OrderedGroup> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESBasic_ToolOrderedGroup::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESBasic_ToolOrderedGroup.def("OwnCopy", (void (IGESBasic_ToolOrderedGroup::*)(const opencascade::handle<IGESBasic_OrderedGroup> &, const opencascade::handle<IGESBasic_OrderedGroup> &, Interface_CopyTool &) const) &IGESBasic_ToolOrderedGroup::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESBasic_ToolOrderedGroup.def("OwnDump", (void (IGESBasic_ToolOrderedGroup::*)(const opencascade::handle<IGESBasic_OrderedGroup> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESBasic_ToolOrderedGroup::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESBASIC_TOOLORDEREDGROUPWITHOUTBACKP
py::class_<IGESBasic_ToolOrderedGroupWithoutBackP> cls_IGESBasic_ToolOrderedGroupWithoutBackP(mod, "IGESBasic_ToolOrderedGroupWithoutBackP", "Tool to work on a OrderedGroupWithoutBackP. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESBasic_ToolOrderedGroupWithoutBackP.def(py::init<>());

// Methods
// cls_IGESBasic_ToolOrderedGroupWithoutBackP.def_static("operator new_", (void * (*)(size_t)) &IGESBasic_ToolOrderedGroupWithoutBackP::operator new, "None", py::arg("theSize"));
// cls_IGESBasic_ToolOrderedGroupWithoutBackP.def_static("operator delete_", (void (*)(void *)) &IGESBasic_ToolOrderedGroupWithoutBackP::operator delete, "None", py::arg("theAddress"));
// cls_IGESBasic_ToolOrderedGroupWithoutBackP.def_static("operator new[]_", (void * (*)(size_t)) &IGESBasic_ToolOrderedGroupWithoutBackP::operator new[], "None", py::arg("theSize"));
// cls_IGESBasic_ToolOrderedGroupWithoutBackP.def_static("operator delete[]_", (void (*)(void *)) &IGESBasic_ToolOrderedGroupWithoutBackP::operator delete[], "None", py::arg("theAddress"));
// cls_IGESBasic_ToolOrderedGroupWithoutBackP.def_static("operator new_", (void * (*)(size_t, void *)) &IGESBasic_ToolOrderedGroupWithoutBackP::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESBasic_ToolOrderedGroupWithoutBackP.def_static("operator delete_", (void (*)(void *, void *)) &IGESBasic_ToolOrderedGroupWithoutBackP::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESBasic_ToolOrderedGroupWithoutBackP.def("ReadOwnParams", (void (IGESBasic_ToolOrderedGroupWithoutBackP::*)(const opencascade::handle<IGESBasic_OrderedGroupWithoutBackP> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESBasic_ToolOrderedGroupWithoutBackP::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESBasic_ToolOrderedGroupWithoutBackP.def("WriteOwnParams", (void (IGESBasic_ToolOrderedGroupWithoutBackP::*)(const opencascade::handle<IGESBasic_OrderedGroupWithoutBackP> &, IGESData_IGESWriter &) const) &IGESBasic_ToolOrderedGroupWithoutBackP::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESBasic_ToolOrderedGroupWithoutBackP.def("OwnShared", (void (IGESBasic_ToolOrderedGroupWithoutBackP::*)(const opencascade::handle<IGESBasic_OrderedGroupWithoutBackP> &, Interface_EntityIterator &) const) &IGESBasic_ToolOrderedGroupWithoutBackP::OwnShared, "Lists the Entities shared by a OrderedGroupWithoutBackP <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESBasic_ToolOrderedGroupWithoutBackP.def("OwnCorrect", (Standard_Boolean (IGESBasic_ToolOrderedGroupWithoutBackP::*)(const opencascade::handle<IGESBasic_OrderedGroupWithoutBackP> &) const) &IGESBasic_ToolOrderedGroupWithoutBackP::OwnCorrect, "Sets automatic unambiguous Correction on an OrderedGroupWithoutBackP (Null Elements are removed from list)", py::arg("ent"));
cls_IGESBasic_ToolOrderedGroupWithoutBackP.def("DirChecker", (IGESData_DirChecker (IGESBasic_ToolOrderedGroupWithoutBackP::*)(const opencascade::handle<IGESBasic_OrderedGroupWithoutBackP> &) const) &IGESBasic_ToolOrderedGroupWithoutBackP::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESBasic_ToolOrderedGroupWithoutBackP.def("OwnCheck", (void (IGESBasic_ToolOrderedGroupWithoutBackP::*)(const opencascade::handle<IGESBasic_OrderedGroupWithoutBackP> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESBasic_ToolOrderedGroupWithoutBackP::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESBasic_ToolOrderedGroupWithoutBackP.def("OwnCopy", (void (IGESBasic_ToolOrderedGroupWithoutBackP::*)(const opencascade::handle<IGESBasic_OrderedGroupWithoutBackP> &, const opencascade::handle<IGESBasic_OrderedGroupWithoutBackP> &, Interface_CopyTool &) const) &IGESBasic_ToolOrderedGroupWithoutBackP::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESBasic_ToolOrderedGroupWithoutBackP.def("OwnDump", (void (IGESBasic_ToolOrderedGroupWithoutBackP::*)(const opencascade::handle<IGESBasic_OrderedGroupWithoutBackP> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESBasic_ToolOrderedGroupWithoutBackP::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESBASIC_TOOLSINGLEPARENT
py::class_<IGESBasic_ToolSingleParent> cls_IGESBasic_ToolSingleParent(mod, "IGESBasic_ToolSingleParent", "Tool to work on a SingleParent. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESBasic_ToolSingleParent.def(py::init<>());

// Methods
// cls_IGESBasic_ToolSingleParent.def_static("operator new_", (void * (*)(size_t)) &IGESBasic_ToolSingleParent::operator new, "None", py::arg("theSize"));
// cls_IGESBasic_ToolSingleParent.def_static("operator delete_", (void (*)(void *)) &IGESBasic_ToolSingleParent::operator delete, "None", py::arg("theAddress"));
// cls_IGESBasic_ToolSingleParent.def_static("operator new[]_", (void * (*)(size_t)) &IGESBasic_ToolSingleParent::operator new[], "None", py::arg("theSize"));
// cls_IGESBasic_ToolSingleParent.def_static("operator delete[]_", (void (*)(void *)) &IGESBasic_ToolSingleParent::operator delete[], "None", py::arg("theAddress"));
// cls_IGESBasic_ToolSingleParent.def_static("operator new_", (void * (*)(size_t, void *)) &IGESBasic_ToolSingleParent::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESBasic_ToolSingleParent.def_static("operator delete_", (void (*)(void *, void *)) &IGESBasic_ToolSingleParent::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESBasic_ToolSingleParent.def("ReadOwnParams", (void (IGESBasic_ToolSingleParent::*)(const opencascade::handle<IGESBasic_SingleParent> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESBasic_ToolSingleParent::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESBasic_ToolSingleParent.def("WriteOwnParams", (void (IGESBasic_ToolSingleParent::*)(const opencascade::handle<IGESBasic_SingleParent> &, IGESData_IGESWriter &) const) &IGESBasic_ToolSingleParent::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESBasic_ToolSingleParent.def("OwnShared", (void (IGESBasic_ToolSingleParent::*)(const opencascade::handle<IGESBasic_SingleParent> &, Interface_EntityIterator &) const) &IGESBasic_ToolSingleParent::OwnShared, "Lists the Entities shared by a SingleParent <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESBasic_ToolSingleParent.def("OwnCorrect", (Standard_Boolean (IGESBasic_ToolSingleParent::*)(const opencascade::handle<IGESBasic_SingleParent> &) const) &IGESBasic_ToolSingleParent::OwnCorrect, "Sets automatic unambiguous Correction on a SingleParent (NbParents forced to 1)", py::arg("ent"));
cls_IGESBasic_ToolSingleParent.def("DirChecker", (IGESData_DirChecker (IGESBasic_ToolSingleParent::*)(const opencascade::handle<IGESBasic_SingleParent> &) const) &IGESBasic_ToolSingleParent::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESBasic_ToolSingleParent.def("OwnCheck", (void (IGESBasic_ToolSingleParent::*)(const opencascade::handle<IGESBasic_SingleParent> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESBasic_ToolSingleParent::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESBasic_ToolSingleParent.def("OwnCopy", (void (IGESBasic_ToolSingleParent::*)(const opencascade::handle<IGESBasic_SingleParent> &, const opencascade::handle<IGESBasic_SingleParent> &, Interface_CopyTool &) const) &IGESBasic_ToolSingleParent::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESBasic_ToolSingleParent.def("OwnDump", (void (IGESBasic_ToolSingleParent::*)(const opencascade::handle<IGESBasic_SingleParent> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESBasic_ToolSingleParent::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESBASIC_TOOLSINGULARSUBFIGURE
py::class_<IGESBasic_ToolSingularSubfigure> cls_IGESBasic_ToolSingularSubfigure(mod, "IGESBasic_ToolSingularSubfigure", "Tool to work on a SingularSubfigure. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESBasic_ToolSingularSubfigure.def(py::init<>());

// Methods
// cls_IGESBasic_ToolSingularSubfigure.def_static("operator new_", (void * (*)(size_t)) &IGESBasic_ToolSingularSubfigure::operator new, "None", py::arg("theSize"));
// cls_IGESBasic_ToolSingularSubfigure.def_static("operator delete_", (void (*)(void *)) &IGESBasic_ToolSingularSubfigure::operator delete, "None", py::arg("theAddress"));
// cls_IGESBasic_ToolSingularSubfigure.def_static("operator new[]_", (void * (*)(size_t)) &IGESBasic_ToolSingularSubfigure::operator new[], "None", py::arg("theSize"));
// cls_IGESBasic_ToolSingularSubfigure.def_static("operator delete[]_", (void (*)(void *)) &IGESBasic_ToolSingularSubfigure::operator delete[], "None", py::arg("theAddress"));
// cls_IGESBasic_ToolSingularSubfigure.def_static("operator new_", (void * (*)(size_t, void *)) &IGESBasic_ToolSingularSubfigure::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESBasic_ToolSingularSubfigure.def_static("operator delete_", (void (*)(void *, void *)) &IGESBasic_ToolSingularSubfigure::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESBasic_ToolSingularSubfigure.def("ReadOwnParams", (void (IGESBasic_ToolSingularSubfigure::*)(const opencascade::handle<IGESBasic_SingularSubfigure> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESBasic_ToolSingularSubfigure::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESBasic_ToolSingularSubfigure.def("WriteOwnParams", (void (IGESBasic_ToolSingularSubfigure::*)(const opencascade::handle<IGESBasic_SingularSubfigure> &, IGESData_IGESWriter &) const) &IGESBasic_ToolSingularSubfigure::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESBasic_ToolSingularSubfigure.def("OwnShared", (void (IGESBasic_ToolSingularSubfigure::*)(const opencascade::handle<IGESBasic_SingularSubfigure> &, Interface_EntityIterator &) const) &IGESBasic_ToolSingularSubfigure::OwnShared, "Lists the Entities shared by a SingularSubfigure <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESBasic_ToolSingularSubfigure.def("DirChecker", (IGESData_DirChecker (IGESBasic_ToolSingularSubfigure::*)(const opencascade::handle<IGESBasic_SingularSubfigure> &) const) &IGESBasic_ToolSingularSubfigure::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESBasic_ToolSingularSubfigure.def("OwnCheck", (void (IGESBasic_ToolSingularSubfigure::*)(const opencascade::handle<IGESBasic_SingularSubfigure> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESBasic_ToolSingularSubfigure::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESBasic_ToolSingularSubfigure.def("OwnCopy", (void (IGESBasic_ToolSingularSubfigure::*)(const opencascade::handle<IGESBasic_SingularSubfigure> &, const opencascade::handle<IGESBasic_SingularSubfigure> &, Interface_CopyTool &) const) &IGESBasic_ToolSingularSubfigure::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESBasic_ToolSingularSubfigure.def("OwnDump", (void (IGESBasic_ToolSingularSubfigure::*)(const opencascade::handle<IGESBasic_SingularSubfigure> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESBasic_ToolSingularSubfigure::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// CLASS: IGESBASIC_TOOLSUBFIGUREDEF
py::class_<IGESBasic_ToolSubfigureDef> cls_IGESBasic_ToolSubfigureDef(mod, "IGESBasic_ToolSubfigureDef", "Tool to work on a SubfigureDef. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESBasic_ToolSubfigureDef.def(py::init<>());

// Methods
// cls_IGESBasic_ToolSubfigureDef.def_static("operator new_", (void * (*)(size_t)) &IGESBasic_ToolSubfigureDef::operator new, "None", py::arg("theSize"));
// cls_IGESBasic_ToolSubfigureDef.def_static("operator delete_", (void (*)(void *)) &IGESBasic_ToolSubfigureDef::operator delete, "None", py::arg("theAddress"));
// cls_IGESBasic_ToolSubfigureDef.def_static("operator new[]_", (void * (*)(size_t)) &IGESBasic_ToolSubfigureDef::operator new[], "None", py::arg("theSize"));
// cls_IGESBasic_ToolSubfigureDef.def_static("operator delete[]_", (void (*)(void *)) &IGESBasic_ToolSubfigureDef::operator delete[], "None", py::arg("theAddress"));
// cls_IGESBasic_ToolSubfigureDef.def_static("operator new_", (void * (*)(size_t, void *)) &IGESBasic_ToolSubfigureDef::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESBasic_ToolSubfigureDef.def_static("operator delete_", (void (*)(void *, void *)) &IGESBasic_ToolSubfigureDef::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESBasic_ToolSubfigureDef.def("ReadOwnParams", (void (IGESBasic_ToolSubfigureDef::*)(const opencascade::handle<IGESBasic_SubfigureDef> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESBasic_ToolSubfigureDef::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESBasic_ToolSubfigureDef.def("WriteOwnParams", (void (IGESBasic_ToolSubfigureDef::*)(const opencascade::handle<IGESBasic_SubfigureDef> &, IGESData_IGESWriter &) const) &IGESBasic_ToolSubfigureDef::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESBasic_ToolSubfigureDef.def("OwnShared", (void (IGESBasic_ToolSubfigureDef::*)(const opencascade::handle<IGESBasic_SubfigureDef> &, Interface_EntityIterator &) const) &IGESBasic_ToolSubfigureDef::OwnShared, "Lists the Entities shared by a SubfigureDef <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESBasic_ToolSubfigureDef.def("DirChecker", (IGESData_DirChecker (IGESBasic_ToolSubfigureDef::*)(const opencascade::handle<IGESBasic_SubfigureDef> &) const) &IGESBasic_ToolSubfigureDef::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESBasic_ToolSubfigureDef.def("OwnCheck", (void (IGESBasic_ToolSubfigureDef::*)(const opencascade::handle<IGESBasic_SubfigureDef> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESBasic_ToolSubfigureDef::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESBasic_ToolSubfigureDef.def("OwnCopy", (void (IGESBasic_ToolSubfigureDef::*)(const opencascade::handle<IGESBasic_SubfigureDef> &, const opencascade::handle<IGESBasic_SubfigureDef> &, Interface_CopyTool &) const) &IGESBasic_ToolSubfigureDef::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESBasic_ToolSubfigureDef.def("OwnDump", (void (IGESBasic_ToolSubfigureDef::*)(const opencascade::handle<IGESBasic_SubfigureDef> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESBasic_ToolSubfigureDef::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));


}
