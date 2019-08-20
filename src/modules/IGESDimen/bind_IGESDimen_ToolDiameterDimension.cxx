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
#include <IGESDimen_DiameterDimension.hxx>
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
#include <IGESDimen_ToolDiameterDimension.hxx>

void bind_IGESDimen_ToolDiameterDimension(py::module &mod){

py::class_<IGESDimen_ToolDiameterDimension, std::unique_ptr<IGESDimen_ToolDiameterDimension>> cls_IGESDimen_ToolDiameterDimension(mod, "IGESDimen_ToolDiameterDimension", "Tool to work on a DiameterDimension. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDimen_ToolDiameterDimension.def(py::init<>());

// Fields

// Methods
// cls_IGESDimen_ToolDiameterDimension.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_ToolDiameterDimension::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_ToolDiameterDimension.def_static("operator delete_", (void (*)(void *)) &IGESDimen_ToolDiameterDimension::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_ToolDiameterDimension.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_ToolDiameterDimension::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_ToolDiameterDimension.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_ToolDiameterDimension::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_ToolDiameterDimension.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_ToolDiameterDimension::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_ToolDiameterDimension.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_ToolDiameterDimension::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen_ToolDiameterDimension.def("ReadOwnParams", (void (IGESDimen_ToolDiameterDimension::*)(const opencascade::handle<IGESDimen_DiameterDimension> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ToolDiameterDimension::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ToolDiameterDimension.def("WriteOwnParams", (void (IGESDimen_ToolDiameterDimension::*)(const opencascade::handle<IGESDimen_DiameterDimension> &, IGESData_IGESWriter &) const) &IGESDimen_ToolDiameterDimension::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ToolDiameterDimension.def("OwnShared", (void (IGESDimen_ToolDiameterDimension::*)(const opencascade::handle<IGESDimen_DiameterDimension> &, Interface_EntityIterator &) const) &IGESDimen_ToolDiameterDimension::OwnShared, "Lists the Entities shared by a DiameterDimension <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDimen_ToolDiameterDimension.def("DirChecker", (IGESData_DirChecker (IGESDimen_ToolDiameterDimension::*)(const opencascade::handle<IGESDimen_DiameterDimension> &) const) &IGESDimen_ToolDiameterDimension::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDimen_ToolDiameterDimension.def("OwnCheck", (void (IGESDimen_ToolDiameterDimension::*)(const opencascade::handle<IGESDimen_DiameterDimension> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_ToolDiameterDimension::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_ToolDiameterDimension.def("OwnCopy", (void (IGESDimen_ToolDiameterDimension::*)(const opencascade::handle<IGESDimen_DiameterDimension> &, const opencascade::handle<IGESDimen_DiameterDimension> &, Interface_CopyTool &) const) &IGESDimen_ToolDiameterDimension::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_ToolDiameterDimension.def("OwnDump", (void (IGESDimen_ToolDiameterDimension::*)(const opencascade::handle<IGESDimen_DiameterDimension> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_ToolDiameterDimension::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// Enums

}