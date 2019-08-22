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
#include <IGESDraw_Planar.hxx>
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
#include <IGESDraw_ToolPlanar.hxx>

void bind_IGESDraw_ToolPlanar(py::module &mod){

py::class_<IGESDraw_ToolPlanar> cls_IGESDraw_ToolPlanar(mod, "IGESDraw_ToolPlanar", "Tool to work on a Planar. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDraw_ToolPlanar.def(py::init<>());

// Fields

// Methods
// cls_IGESDraw_ToolPlanar.def_static("operator new_", (void * (*)(size_t)) &IGESDraw_ToolPlanar::operator new, "None", py::arg("theSize"));
// cls_IGESDraw_ToolPlanar.def_static("operator delete_", (void (*)(void *)) &IGESDraw_ToolPlanar::operator delete, "None", py::arg("theAddress"));
// cls_IGESDraw_ToolPlanar.def_static("operator new[]_", (void * (*)(size_t)) &IGESDraw_ToolPlanar::operator new[], "None", py::arg("theSize"));
// cls_IGESDraw_ToolPlanar.def_static("operator delete[]_", (void (*)(void *)) &IGESDraw_ToolPlanar::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDraw_ToolPlanar.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDraw_ToolPlanar::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDraw_ToolPlanar.def_static("operator delete_", (void (*)(void *, void *)) &IGESDraw_ToolPlanar::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDraw_ToolPlanar.def("ReadOwnParams", (void (IGESDraw_ToolPlanar::*)(const opencascade::handle<IGESDraw_Planar> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDraw_ToolPlanar::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDraw_ToolPlanar.def("WriteOwnParams", (void (IGESDraw_ToolPlanar::*)(const opencascade::handle<IGESDraw_Planar> &, IGESData_IGESWriter &) const) &IGESDraw_ToolPlanar::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDraw_ToolPlanar.def("OwnShared", (void (IGESDraw_ToolPlanar::*)(const opencascade::handle<IGESDraw_Planar> &, Interface_EntityIterator &) const) &IGESDraw_ToolPlanar::OwnShared, "Lists the Entities shared by a Planar <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDraw_ToolPlanar.def("OwnCorrect", (Standard_Boolean (IGESDraw_ToolPlanar::*)(const opencascade::handle<IGESDraw_Planar> &) const) &IGESDraw_ToolPlanar::OwnCorrect, "Sets automatic unambiguous Correction on a Planar (NbMatrices forced to 1)", py::arg("ent"));
cls_IGESDraw_ToolPlanar.def("DirChecker", (IGESData_DirChecker (IGESDraw_ToolPlanar::*)(const opencascade::handle<IGESDraw_Planar> &) const) &IGESDraw_ToolPlanar::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDraw_ToolPlanar.def("OwnCheck", (void (IGESDraw_ToolPlanar::*)(const opencascade::handle<IGESDraw_Planar> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDraw_ToolPlanar::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDraw_ToolPlanar.def("OwnCopy", (void (IGESDraw_ToolPlanar::*)(const opencascade::handle<IGESDraw_Planar> &, const opencascade::handle<IGESDraw_Planar> &, Interface_CopyTool &) const) &IGESDraw_ToolPlanar::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDraw_ToolPlanar.def("OwnDump", (void (IGESDraw_ToolPlanar::*)(const opencascade::handle<IGESDraw_Planar> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDraw_ToolPlanar::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// Enums

}