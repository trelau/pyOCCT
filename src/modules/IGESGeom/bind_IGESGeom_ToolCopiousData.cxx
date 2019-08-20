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
#include <IGESGeom_CopiousData.hxx>
#include <IGESData_IGESReaderData.hxx>
#include <IGESData_ParamReader.hxx>
#include <IGESData_IGESWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <IGESData_DirChecker.hxx>
#include <Interface_ShareTool.hxx>
#include <Interface_Check.hxx>
#include <Interface_CopyTool.hxx>
#include <IGESData_IGESDumper.hxx>
#include <Message_Messenger.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESGeom_ToolCopiousData.hxx>

void bind_IGESGeom_ToolCopiousData(py::module &mod){

py::class_<IGESGeom_ToolCopiousData, std::unique_ptr<IGESGeom_ToolCopiousData>> cls_IGESGeom_ToolCopiousData(mod, "IGESGeom_ToolCopiousData", "Tool to work on a CopiousData. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESGeom_ToolCopiousData.def(py::init<>());

// Fields

// Methods
// cls_IGESGeom_ToolCopiousData.def_static("operator new_", (void * (*)(size_t)) &IGESGeom_ToolCopiousData::operator new, "None", py::arg("theSize"));
// cls_IGESGeom_ToolCopiousData.def_static("operator delete_", (void (*)(void *)) &IGESGeom_ToolCopiousData::operator delete, "None", py::arg("theAddress"));
// cls_IGESGeom_ToolCopiousData.def_static("operator new[]_", (void * (*)(size_t)) &IGESGeom_ToolCopiousData::operator new[], "None", py::arg("theSize"));
// cls_IGESGeom_ToolCopiousData.def_static("operator delete[]_", (void (*)(void *)) &IGESGeom_ToolCopiousData::operator delete[], "None", py::arg("theAddress"));
// cls_IGESGeom_ToolCopiousData.def_static("operator new_", (void * (*)(size_t, void *)) &IGESGeom_ToolCopiousData::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESGeom_ToolCopiousData.def_static("operator delete_", (void (*)(void *, void *)) &IGESGeom_ToolCopiousData::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESGeom_ToolCopiousData.def("ReadOwnParams", (void (IGESGeom_ToolCopiousData::*)(const opencascade::handle<IGESGeom_CopiousData> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESGeom_ToolCopiousData::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESGeom_ToolCopiousData.def("WriteOwnParams", (void (IGESGeom_ToolCopiousData::*)(const opencascade::handle<IGESGeom_CopiousData> &, IGESData_IGESWriter &) const) &IGESGeom_ToolCopiousData::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESGeom_ToolCopiousData.def("OwnShared", (void (IGESGeom_ToolCopiousData::*)(const opencascade::handle<IGESGeom_CopiousData> &, Interface_EntityIterator &) const) &IGESGeom_ToolCopiousData::OwnShared, "Lists the Entities shared by a CopiousData <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESGeom_ToolCopiousData.def("DirChecker", (IGESData_DirChecker (IGESGeom_ToolCopiousData::*)(const opencascade::handle<IGESGeom_CopiousData> &) const) &IGESGeom_ToolCopiousData::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESGeom_ToolCopiousData.def("OwnCheck", (void (IGESGeom_ToolCopiousData::*)(const opencascade::handle<IGESGeom_CopiousData> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESGeom_ToolCopiousData::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESGeom_ToolCopiousData.def("OwnCopy", (void (IGESGeom_ToolCopiousData::*)(const opencascade::handle<IGESGeom_CopiousData> &, const opencascade::handle<IGESGeom_CopiousData> &, Interface_CopyTool &) const) &IGESGeom_ToolCopiousData::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESGeom_ToolCopiousData.def("OwnDump", (void (IGESGeom_ToolCopiousData::*)(const opencascade::handle<IGESGeom_CopiousData> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESGeom_ToolCopiousData::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// Enums

}