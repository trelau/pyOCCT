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
#include <StepData_FreeFormEntity.hxx>
#include <TColStd_HSequenceOfAsciiString.hxx>
#include <StepData_Field.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>
#include <StepData_HArray1OfField.hxx>

void bind_StepData_FreeFormEntity(py::module &mod){

py::class_<StepData_FreeFormEntity, opencascade::handle<StepData_FreeFormEntity>, Standard_Transient> cls_StepData_FreeFormEntity(mod, "StepData_FreeFormEntity", "A Free Form Entity allows to record any kind of STEP parameters, in any way of typing It is implemented with an array of fields A Complex entity can be defined, as a chain of FreeFormEntity (see Next and As)");

// Constructors
// cls_StepData_FreeFormEntity.def(py::init<>());

// Fields

// Methods
cls_StepData_FreeFormEntity.def("SetStepType", (void (StepData_FreeFormEntity::*)(const Standard_CString)) &StepData_FreeFormEntity::SetStepType, "Sets the type of an entity For a complex one, the type of this member", py::arg("typenam"));
cls_StepData_FreeFormEntity.def("StepType", (Standard_CString (StepData_FreeFormEntity::*)() const) &StepData_FreeFormEntity::StepType, "Returns the recorded StepType For a complex one, the type of this member");
cls_StepData_FreeFormEntity.def("SetNext", [](StepData_FreeFormEntity &self, const opencascade::handle<StepData_FreeFormEntity> & a0) -> void { return self.SetNext(a0); });
cls_StepData_FreeFormEntity.def("SetNext", (void (StepData_FreeFormEntity::*)(const opencascade::handle<StepData_FreeFormEntity> &, const Standard_Boolean)) &StepData_FreeFormEntity::SetNext, "Sets a next member, in order to define or complete a Complex entity If <last> is True (D), this next will be set as last of list Else, it is inserted just as next of <me> If <next> is Null, Next is cleared", py::arg("next"), py::arg("last"));
cls_StepData_FreeFormEntity.def("Next", (opencascade::handle<StepData_FreeFormEntity> (StepData_FreeFormEntity::*)() const) &StepData_FreeFormEntity::Next, "Returns the next member of a Complex entity (remark : the last member has none)");
cls_StepData_FreeFormEntity.def("IsComplex", (Standard_Boolean (StepData_FreeFormEntity::*)() const) &StepData_FreeFormEntity::IsComplex, "Returns True if a FreeFormEntity is Complex (i.e. has Next)");
cls_StepData_FreeFormEntity.def("Typed", (opencascade::handle<StepData_FreeFormEntity> (StepData_FreeFormEntity::*)(const Standard_CString) const) &StepData_FreeFormEntity::Typed, "Returns the member of a FreeFormEntity of which the type name is given (exact match, no sub-type)", py::arg("typenam"));
cls_StepData_FreeFormEntity.def("TypeList", (opencascade::handle<TColStd_HSequenceOfAsciiString> (StepData_FreeFormEntity::*)() const) &StepData_FreeFormEntity::TypeList, "Returns the list of types (one type for a simple entity), as is (non reordered)");
cls_StepData_FreeFormEntity.def_static("Reorder_", (Standard_Boolean (*)(opencascade::handle<StepData_FreeFormEntity> &)) &StepData_FreeFormEntity::Reorder, "Reorders a Complex entity if required, i.e. if member types are not in alphabetic order Returns False if nothing done (order was OK or simple entity), True plus modified <ent> if <ent> has been reordered", py::arg("ent"));
cls_StepData_FreeFormEntity.def("SetNbFields", (void (StepData_FreeFormEntity::*)(const Standard_Integer)) &StepData_FreeFormEntity::SetNbFields, "Sets a count of Fields, from scratch", py::arg("nb"));
cls_StepData_FreeFormEntity.def("NbFields", (Standard_Integer (StepData_FreeFormEntity::*)() const) &StepData_FreeFormEntity::NbFields, "Returns the count of fields");
cls_StepData_FreeFormEntity.def("Field", (const StepData_Field & (StepData_FreeFormEntity::*)(const Standard_Integer) const) &StepData_FreeFormEntity::Field, "Returns a field from its rank, for read-only use", py::arg("num"));
cls_StepData_FreeFormEntity.def("CField", (StepData_Field & (StepData_FreeFormEntity::*)(const Standard_Integer)) &StepData_FreeFormEntity::CField, "Returns a field from its rank, in order to modify it", py::arg("num"));
cls_StepData_FreeFormEntity.def_static("get_type_name_", (const char * (*)()) &StepData_FreeFormEntity::get_type_name, "None");
cls_StepData_FreeFormEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepData_FreeFormEntity::get_type_descriptor, "None");
cls_StepData_FreeFormEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepData_FreeFormEntity::*)() const) &StepData_FreeFormEntity::DynamicType, "None");

// Enums

}