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
#include <IGESSolid_RightAngularWedge.hxx>
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
#include <IGESSolid_ToolRightAngularWedge.hxx>

void bind_IGESSolid_ToolRightAngularWedge(py::module &mod){

py::class_<IGESSolid_ToolRightAngularWedge> cls_IGESSolid_ToolRightAngularWedge(mod, "IGESSolid_ToolRightAngularWedge", "Tool to work on a RightAngularWedge. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESSolid_ToolRightAngularWedge.def(py::init<>());

// Fields

// Methods
// cls_IGESSolid_ToolRightAngularWedge.def_static("operator new_", (void * (*)(size_t)) &IGESSolid_ToolRightAngularWedge::operator new, "None", py::arg("theSize"));
// cls_IGESSolid_ToolRightAngularWedge.def_static("operator delete_", (void (*)(void *)) &IGESSolid_ToolRightAngularWedge::operator delete, "None", py::arg("theAddress"));
// cls_IGESSolid_ToolRightAngularWedge.def_static("operator new[]_", (void * (*)(size_t)) &IGESSolid_ToolRightAngularWedge::operator new[], "None", py::arg("theSize"));
// cls_IGESSolid_ToolRightAngularWedge.def_static("operator delete[]_", (void (*)(void *)) &IGESSolid_ToolRightAngularWedge::operator delete[], "None", py::arg("theAddress"));
// cls_IGESSolid_ToolRightAngularWedge.def_static("operator new_", (void * (*)(size_t, void *)) &IGESSolid_ToolRightAngularWedge::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESSolid_ToolRightAngularWedge.def_static("operator delete_", (void (*)(void *, void *)) &IGESSolid_ToolRightAngularWedge::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESSolid_ToolRightAngularWedge.def("ReadOwnParams", (void (IGESSolid_ToolRightAngularWedge::*)(const opencascade::handle<IGESSolid_RightAngularWedge> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESSolid_ToolRightAngularWedge::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESSolid_ToolRightAngularWedge.def("WriteOwnParams", (void (IGESSolid_ToolRightAngularWedge::*)(const opencascade::handle<IGESSolid_RightAngularWedge> &, IGESData_IGESWriter &) const) &IGESSolid_ToolRightAngularWedge::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESSolid_ToolRightAngularWedge.def("OwnShared", (void (IGESSolid_ToolRightAngularWedge::*)(const opencascade::handle<IGESSolid_RightAngularWedge> &, Interface_EntityIterator &) const) &IGESSolid_ToolRightAngularWedge::OwnShared, "Lists the Entities shared by a RightAngularWedge <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESSolid_ToolRightAngularWedge.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolRightAngularWedge::*)(const opencascade::handle<IGESSolid_RightAngularWedge> &) const) &IGESSolid_ToolRightAngularWedge::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESSolid_ToolRightAngularWedge.def("OwnCheck", (void (IGESSolid_ToolRightAngularWedge::*)(const opencascade::handle<IGESSolid_RightAngularWedge> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESSolid_ToolRightAngularWedge::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESSolid_ToolRightAngularWedge.def("OwnCopy", (void (IGESSolid_ToolRightAngularWedge::*)(const opencascade::handle<IGESSolid_RightAngularWedge> &, const opencascade::handle<IGESSolid_RightAngularWedge> &, Interface_CopyTool &) const) &IGESSolid_ToolRightAngularWedge::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESSolid_ToolRightAngularWedge.def("OwnDump", (void (IGESSolid_ToolRightAngularWedge::*)(const opencascade::handle<IGESSolid_RightAngularWedge> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESSolid_ToolRightAngularWedge::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// Enums

}