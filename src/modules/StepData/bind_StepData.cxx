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
#include <StepData_Protocol.hxx>
#include <StepData_StepModel.hxx>
#include <StepData_UndefinedEntity.hxx>
#include <StepData_SelectType.hxx>
#include <StepData_Field.hxx>
#include <StepData_SelectMember.hxx>
#include <StepData_SelectInt.hxx>
#include <StepData_SelectReal.hxx>
#include <StepData_SelectNamed.hxx>
#include <StepData_SelectArrReal.hxx>
#include <StepData_PDescr.hxx>
#include <StepData_FieldList.hxx>
#include <StepData_FieldList1.hxx>
#include <StepData_FieldListN.hxx>
#include <StepData_FieldListD.hxx>
#include <StepData_EDescr.hxx>
#include <StepData_ESDescr.hxx>
#include <StepData_ECDescr.hxx>
#include <StepData_Described.hxx>
#include <StepData_Simple.hxx>
#include <StepData_Plex.hxx>
#include <StepData_FreeFormEntity.hxx>
#include <StepData_GeneralModule.hxx>
#include <StepData_FileRecognizer.hxx>
#include <StepData_FileProtocol.hxx>
#include <StepData_HeaderTool.hxx>
#include <StepData_EnumTool.hxx>
#include <StepData_DescrProtocol.hxx>
#include <StepData_DescrGeneral.hxx>
#include <StepData_DescrReadWrite.hxx>
#include <StepData_StepReaderData.hxx>
#include <StepData_StepReaderTool.hxx>
#include <StepData_ReadWriteModule.hxx>
#include <StepData_StepWriter.hxx>
#include <StepData_StepDumper.hxx>
#include <StepData_WriterLib.hxx>
#include <StepData_DefaultGeneral.hxx>
#include <StepData_GlobalNodeOfWriterLib.hxx>
#include <StepData_NodeOfWriterLib.hxx>
#include <StepData.hxx>

void bind_StepData(py::module &mod){

py::class_<StepData, std::unique_ptr<StepData>> cls_StepData(mod, "StepData", "Gives basic data definition for Step Interface. Any class of a data model described in EXPRESS Language is candidate to be managed by a Step Interface");

// Constructors

// Fields

// Methods
// cls_StepData.def_static("operator new_", (void * (*)(size_t)) &StepData::operator new, "None", py::arg("theSize"));
// cls_StepData.def_static("operator delete_", (void (*)(void *)) &StepData::operator delete, "None", py::arg("theAddress"));
// cls_StepData.def_static("operator new[]_", (void * (*)(size_t)) &StepData::operator new[], "None", py::arg("theSize"));
// cls_StepData.def_static("operator delete[]_", (void (*)(void *)) &StepData::operator delete[], "None", py::arg("theAddress"));
// cls_StepData.def_static("operator new_", (void * (*)(size_t, void *)) &StepData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepData.def_static("operator delete_", (void (*)(void *, void *)) &StepData::operator delete, "None", py::arg(""), py::arg(""));
cls_StepData.def_static("HeaderProtocol_", (opencascade::handle<StepData_Protocol> (*)()) &StepData::HeaderProtocol, "Returns the recorded HeaderProtocol, which can be : - a Null Handle if no Header Protocol was yet defined - a simple Protocol if only one was defined - a FileProtocol if more than one Protocol was yet defined");
cls_StepData.def_static("AddHeaderProtocol_", (void (*)(const opencascade::handle<StepData_Protocol> &)) &StepData::AddHeaderProtocol, "Adds a new Header Protocol to the Header Definition", py::arg("headerproto"));
cls_StepData.def_static("Init_", (void (*)()) &StepData::Init, "Prepares General Data required to work with this package, which are the Protocol and Modules to be loaded into Libraries");
cls_StepData.def_static("Protocol_", (opencascade::handle<StepData_Protocol> (*)()) &StepData::Protocol, "Returns a Protocol from StepData (avoids to create it)");

// Enums

}