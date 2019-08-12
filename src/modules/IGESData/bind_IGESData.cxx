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
#include <IGESData_Protocol.hxx>
#include <IGESData_IGESModel.hxx>
#include <IGESData_IGESEntity.hxx>
#include <IGESData_LineFontEntity.hxx>
#include <IGESData_LevelListEntity.hxx>
#include <IGESData_TransfEntity.hxx>
#include <IGESData_ViewKindEntity.hxx>
#include <IGESData_LabelDisplayEntity.hxx>
#include <IGESData_ColorEntity.hxx>
#include <IGESData_NameEntity.hxx>
#include <IGESData_SingleParentEntity.hxx>
#include <IGESData_UndefinedEntity.hxx>
#include <IGESData_FreeFormatEntity.hxx>
#include <IGESData_GlobalSection.hxx>
#include <IGESData_DefSwitch.hxx>
#include <IGESData_DirChecker.hxx>
#include <IGESData_IGESReaderData.hxx>
#include <IGESData_IGESReaderTool.hxx>
#include <IGESData_ParamReader.hxx>
#include <IGESData_ParamCursor.hxx>
#include <IGESData_DirPart.hxx>
#include <IGESData_IGESType.hxx>
#include <IGESData_FileRecognizer.hxx>
#include <IGESData_IGESWriter.hxx>
#include <IGESData_IGESDumper.hxx>
#include <IGESData_BasicEditor.hxx>
#include <IGESData_ToolLocation.hxx>
#include <IGESData_GeneralModule.hxx>
#include <IGESData_DefaultGeneral.hxx>
#include <IGESData_ReadWriteModule.hxx>
#include <IGESData_SpecificModule.hxx>
#include <IGESData_DefaultSpecific.hxx>
#include <IGESData_FileProtocol.hxx>
#include <IGESData_WriterLib.hxx>
#include <IGESData_SpecificLib.hxx>
#include <IGESData_GlobalNodeOfWriterLib.hxx>
#include <IGESData_NodeOfWriterLib.hxx>
#include <IGESData_GlobalNodeOfSpecificLib.hxx>
#include <IGESData_NodeOfSpecificLib.hxx>
#include <IGESData.hxx>

void bind_IGESData(py::module &mod){

py::class_<IGESData, std::unique_ptr<IGESData, Deleter<IGESData>>> cls_IGESData(mod, "IGESData", "basic description of an IGES Interface");

// Constructors

// Fields

// Methods
// cls_IGESData.def_static("operator new_", (void * (*)(size_t)) &IGESData::operator new, "None", py::arg("theSize"));
// cls_IGESData.def_static("operator delete_", (void (*)(void *)) &IGESData::operator delete, "None", py::arg("theAddress"));
// cls_IGESData.def_static("operator new[]_", (void * (*)(size_t)) &IGESData::operator new[], "None", py::arg("theSize"));
// cls_IGESData.def_static("operator delete[]_", (void (*)(void *)) &IGESData::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData.def_static("operator delete_", (void (*)(void *, void *)) &IGESData::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESData.def_static("Init_", (void (*)()) &IGESData::Init, "Prepares General dynamic data used for IGESData specifically : Protocol and Modules, which treat UndefinedEntity");
cls_IGESData.def_static("Protocol_", (opencascade::handle<IGESData_Protocol> (*)()) &IGESData::Protocol, "Returns a Protocol from IGESData (avoids to create it)");

// Enums

}