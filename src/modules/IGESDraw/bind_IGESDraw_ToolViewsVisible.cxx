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
#include <IGESDraw_ViewsVisible.hxx>
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
#include <IGESDraw_ToolViewsVisible.hxx>

void bind_IGESDraw_ToolViewsVisible(py::module &mod){

py::class_<IGESDraw_ToolViewsVisible> cls_IGESDraw_ToolViewsVisible(mod, "IGESDraw_ToolViewsVisible", "Tool to work on a ViewsVisible. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDraw_ToolViewsVisible.def(py::init<>());

// Fields

// Methods
// cls_IGESDraw_ToolViewsVisible.def_static("operator new_", (void * (*)(size_t)) &IGESDraw_ToolViewsVisible::operator new, "None", py::arg("theSize"));
// cls_IGESDraw_ToolViewsVisible.def_static("operator delete_", (void (*)(void *)) &IGESDraw_ToolViewsVisible::operator delete, "None", py::arg("theAddress"));
// cls_IGESDraw_ToolViewsVisible.def_static("operator new[]_", (void * (*)(size_t)) &IGESDraw_ToolViewsVisible::operator new[], "None", py::arg("theSize"));
// cls_IGESDraw_ToolViewsVisible.def_static("operator delete[]_", (void (*)(void *)) &IGESDraw_ToolViewsVisible::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDraw_ToolViewsVisible.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDraw_ToolViewsVisible::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDraw_ToolViewsVisible.def_static("operator delete_", (void (*)(void *, void *)) &IGESDraw_ToolViewsVisible::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDraw_ToolViewsVisible.def("ReadOwnParams", (void (IGESDraw_ToolViewsVisible::*)(const opencascade::handle<IGESDraw_ViewsVisible> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDraw_ToolViewsVisible::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDraw_ToolViewsVisible.def("WriteOwnParams", (void (IGESDraw_ToolViewsVisible::*)(const opencascade::handle<IGESDraw_ViewsVisible> &, IGESData_IGESWriter &) const) &IGESDraw_ToolViewsVisible::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDraw_ToolViewsVisible.def("OwnShared", (void (IGESDraw_ToolViewsVisible::*)(const opencascade::handle<IGESDraw_ViewsVisible> &, Interface_EntityIterator &) const) &IGESDraw_ToolViewsVisible::OwnShared, "Lists the Entities shared by a ViewsVisible <ent>, from its specific (own) parameters shared not implied (the Views)", py::arg("ent"), py::arg("iter"));
cls_IGESDraw_ToolViewsVisible.def("OwnImplied", (void (IGESDraw_ToolViewsVisible::*)(const opencascade::handle<IGESDraw_ViewsVisible> &, Interface_EntityIterator &) const) &IGESDraw_ToolViewsVisible::OwnImplied, "Lists the Entities shared by a ViewsVisible <ent>, from its specific (own) implied parameters : the Displayed Entities", py::arg("ent"), py::arg("iter"));
cls_IGESDraw_ToolViewsVisible.def("DirChecker", (IGESData_DirChecker (IGESDraw_ToolViewsVisible::*)(const opencascade::handle<IGESDraw_ViewsVisible> &) const) &IGESDraw_ToolViewsVisible::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDraw_ToolViewsVisible.def("OwnCheck", (void (IGESDraw_ToolViewsVisible::*)(const opencascade::handle<IGESDraw_ViewsVisible> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDraw_ToolViewsVisible::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDraw_ToolViewsVisible.def("OwnCopy", (void (IGESDraw_ToolViewsVisible::*)(const opencascade::handle<IGESDraw_ViewsVisible> &, const opencascade::handle<IGESDraw_ViewsVisible> &, Interface_CopyTool &) const) &IGESDraw_ToolViewsVisible::OwnCopy, "Copies Specific Parameters shared not implied, i.e. all but the Displayed Entities", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDraw_ToolViewsVisible.def("OwnRenew", (void (IGESDraw_ToolViewsVisible::*)(const opencascade::handle<IGESDraw_ViewsVisible> &, const opencascade::handle<IGESDraw_ViewsVisible> &, const Interface_CopyTool &) const) &IGESDraw_ToolViewsVisible::OwnRenew, "Copies Specific implied Parameters : the Displayed Entities which have already been copied", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDraw_ToolViewsVisible.def("OwnWhenDelete", (void (IGESDraw_ToolViewsVisible::*)(const opencascade::handle<IGESDraw_ViewsVisible> &) const) &IGESDraw_ToolViewsVisible::OwnWhenDelete, "Clears specific implied parameters, which cause looping structures; required for deletion", py::arg("ent"));
cls_IGESDraw_ToolViewsVisible.def("OwnDump", (void (IGESDraw_ToolViewsVisible::*)(const opencascade::handle<IGESDraw_ViewsVisible> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDraw_ToolViewsVisible::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));
cls_IGESDraw_ToolViewsVisible.def("OwnCorrect", (Standard_Boolean (IGESDraw_ToolViewsVisible::*)(const opencascade::handle<IGESDraw_ViewsVisible> &) const) &IGESDraw_ToolViewsVisible::OwnCorrect, "Sets automatic unambiguous Correction on a ViewsVisible (all displayed entities must refer to <ent> in directory part, else the list is cleared)", py::arg("ent"));

// Enums

}