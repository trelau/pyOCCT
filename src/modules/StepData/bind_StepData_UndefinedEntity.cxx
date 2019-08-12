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
#include <Interface_UndefinedContent.hxx>
#include <StepData_UndefinedEntity.hxx>
#include <StepData_StepReaderData.hxx>
#include <Interface_Check.hxx>
#include <StepData_StepWriter.hxx>
#include <Interface_CopyTool.hxx>
#include <Interface_EntityIterator.hxx>
#include <Standard_Type.hxx>
#include <TCollection_HAsciiString.hxx>

void bind_StepData_UndefinedEntity(py::module &mod){

py::class_<StepData_UndefinedEntity, opencascade::handle<StepData_UndefinedEntity>, Standard_Transient> cls_StepData_UndefinedEntity(mod, "StepData_UndefinedEntity", "Undefined entity specific to Step Interface, in which StepType is defined at each instance, or is a SubList of another one Uses an UndefinedContent, that from Interface is suitable. Also an Entity defined by STEP can be 'Complex Type' (see ANDOR clause in Express).");

// Constructors
cls_StepData_UndefinedEntity.def(py::init<>());
cls_StepData_UndefinedEntity.def(py::init<const Standard_Boolean>(), py::arg("issub"));

// Fields

// Methods
cls_StepData_UndefinedEntity.def("UndefinedContent", (opencascade::handle<Interface_UndefinedContent> (StepData_UndefinedEntity::*)() const) &StepData_UndefinedEntity::UndefinedContent, "Returns the UndefinedContent which brings the Parameters");
cls_StepData_UndefinedEntity.def("IsSub", (Standard_Boolean (StepData_UndefinedEntity::*)() const) &StepData_UndefinedEntity::IsSub, "Returns True if an Unndefined Entity is SubPart of another one");
// cls_StepData_UndefinedEntity.def("Super", (opencascade::handle<StepData_UndefinedEntity> (StepData_UndefinedEntity::*)() const) &StepData_UndefinedEntity::Super, "Returns the 'super-entity' of a sub-part");
cls_StepData_UndefinedEntity.def("IsComplex", (Standard_Boolean (StepData_UndefinedEntity::*)() const) &StepData_UndefinedEntity::IsComplex, "Returns True if <me> defines a Multiple Type Entity (see ANDOR)");
cls_StepData_UndefinedEntity.def("Next", (opencascade::handle<StepData_UndefinedEntity> (StepData_UndefinedEntity::*)() const) &StepData_UndefinedEntity::Next, "For a Multiple Type Entity, returns the Next 'Componant' For more than two Types, iterative definition (Next->Next...) Returns a Null Handle for the end of the List");
cls_StepData_UndefinedEntity.def("StepType", (Standard_CString (StepData_UndefinedEntity::*)() const) &StepData_UndefinedEntity::StepType, "gives entity type, read from file For a Complex Type Entity, gives the first Type read, each 'Next' gives its 'partial' type was C++ : return const");
cls_StepData_UndefinedEntity.def("ReadRecord", (void (StepData_UndefinedEntity::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &)) &StepData_UndefinedEntity::ReadRecord, "reads data from StepReaderData (i.e. from file), by filling StepType and parameters stored in the UndefinedContent", py::arg("SR"), py::arg("num"), py::arg("ach"));
cls_StepData_UndefinedEntity.def("WriteParams", (void (StepData_UndefinedEntity::*)(StepData_StepWriter &) const) &StepData_UndefinedEntity::WriteParams, "write data to StepWriter, taken from UndefinedContent", py::arg("SW"));
cls_StepData_UndefinedEntity.def("GetFromAnother", (void (StepData_UndefinedEntity::*)(const opencascade::handle<StepData_UndefinedEntity> &, Interface_CopyTool &)) &StepData_UndefinedEntity::GetFromAnother, "reads another UndefinedEntity from StepData", py::arg("other"), py::arg("TC"));
cls_StepData_UndefinedEntity.def("FillShared", (void (StepData_UndefinedEntity::*)(Interface_EntityIterator &) const) &StepData_UndefinedEntity::FillShared, "Fills the list of shared entities", py::arg("list"));
cls_StepData_UndefinedEntity.def_static("get_type_name_", (const char * (*)()) &StepData_UndefinedEntity::get_type_name, "None");
cls_StepData_UndefinedEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepData_UndefinedEntity::get_type_descriptor, "None");
cls_StepData_UndefinedEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepData_UndefinedEntity::*)() const) &StepData_UndefinedEntity::DynamicType, "None");

// Enums

}