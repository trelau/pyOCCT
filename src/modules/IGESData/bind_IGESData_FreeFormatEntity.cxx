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
#include <IGESData_UndefinedEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_ParamType.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESEntity.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TColStd_HSequenceOfInteger.hxx>
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <IGESData_IGESWriter.hxx>
#include <IGESData_FreeFormatEntity.hxx>
#include <Standard_Type.hxx>

void bind_IGESData_FreeFormatEntity(py::module &mod){

py::class_<IGESData_FreeFormatEntity, opencascade::handle<IGESData_FreeFormatEntity>, IGESData_UndefinedEntity> cls_IGESData_FreeFormatEntity(mod, "IGESData_FreeFormatEntity", "This class allows to create IGES Entities in a literal form : their definition is free, but they are not recognized as instances of specific classes.");

// Constructors
cls_IGESData_FreeFormatEntity.def(py::init<>());

// Fields

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

// Enums

}