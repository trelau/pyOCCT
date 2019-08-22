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
#include <IGESDraw_Drawing.hxx>
#include <IGESData_IGESReaderData.hxx>
#include <IGESData_ParamReader.hxx>
#include <IGESData_IGESWriter.hxx>
#include <Interface_EntityIterator.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESData_DirChecker.hxx>
#include <Interface_ShareTool.hxx>
#include <Interface_Check.hxx>
#include <Interface_CopyTool.hxx>
#include <IGESData_IGESDumper.hxx>
#include <Message_Messenger.hxx>
#include <IGESDraw_ToolDrawing.hxx>

void bind_IGESDraw_ToolDrawing(py::module &mod){

py::class_<IGESDraw_ToolDrawing> cls_IGESDraw_ToolDrawing(mod, "IGESDraw_ToolDrawing", "Tool to work on a Drawing. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDraw_ToolDrawing.def(py::init<>());

// Fields

// Methods
// cls_IGESDraw_ToolDrawing.def_static("operator new_", (void * (*)(size_t)) &IGESDraw_ToolDrawing::operator new, "None", py::arg("theSize"));
// cls_IGESDraw_ToolDrawing.def_static("operator delete_", (void (*)(void *)) &IGESDraw_ToolDrawing::operator delete, "None", py::arg("theAddress"));
// cls_IGESDraw_ToolDrawing.def_static("operator new[]_", (void * (*)(size_t)) &IGESDraw_ToolDrawing::operator new[], "None", py::arg("theSize"));
// cls_IGESDraw_ToolDrawing.def_static("operator delete[]_", (void (*)(void *)) &IGESDraw_ToolDrawing::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDraw_ToolDrawing.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDraw_ToolDrawing::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDraw_ToolDrawing.def_static("operator delete_", (void (*)(void *, void *)) &IGESDraw_ToolDrawing::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDraw_ToolDrawing.def("ReadOwnParams", (void (IGESDraw_ToolDrawing::*)(const opencascade::handle<IGESDraw_Drawing> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDraw_ToolDrawing::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDraw_ToolDrawing.def("WriteOwnParams", (void (IGESDraw_ToolDrawing::*)(const opencascade::handle<IGESDraw_Drawing> &, IGESData_IGESWriter &) const) &IGESDraw_ToolDrawing::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDraw_ToolDrawing.def("OwnShared", (void (IGESDraw_ToolDrawing::*)(const opencascade::handle<IGESDraw_Drawing> &, Interface_EntityIterator &) const) &IGESDraw_ToolDrawing::OwnShared, "Lists the Entities shared by a Drawing <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDraw_ToolDrawing.def("OwnCorrect", (Standard_Boolean (IGESDraw_ToolDrawing::*)(const opencascade::handle<IGESDraw_Drawing> &) const) &IGESDraw_ToolDrawing::OwnCorrect, "Sets automatic unambiguous Correction on a Drawing (Null Views are removed from list)", py::arg("ent"));
cls_IGESDraw_ToolDrawing.def("DirChecker", (IGESData_DirChecker (IGESDraw_ToolDrawing::*)(const opencascade::handle<IGESDraw_Drawing> &) const) &IGESDraw_ToolDrawing::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDraw_ToolDrawing.def("OwnCheck", (void (IGESDraw_ToolDrawing::*)(const opencascade::handle<IGESDraw_Drawing> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDraw_ToolDrawing::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDraw_ToolDrawing.def("OwnCopy", (void (IGESDraw_ToolDrawing::*)(const opencascade::handle<IGESDraw_Drawing> &, const opencascade::handle<IGESDraw_Drawing> &, Interface_CopyTool &) const) &IGESDraw_ToolDrawing::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDraw_ToolDrawing.def("OwnDump", (void (IGESDraw_ToolDrawing::*)(const opencascade::handle<IGESDraw_Drawing> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDraw_ToolDrawing::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// Enums

}