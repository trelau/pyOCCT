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
#include <IGESDraw_CircArraySubfigure.hxx>
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
#include <IGESDraw_ToolCircArraySubfigure.hxx>

void bind_IGESDraw_ToolCircArraySubfigure(py::module &mod){

py::class_<IGESDraw_ToolCircArraySubfigure, std::unique_ptr<IGESDraw_ToolCircArraySubfigure>> cls_IGESDraw_ToolCircArraySubfigure(mod, "IGESDraw_ToolCircArraySubfigure", "Tool to work on a CircArraySubfigure. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDraw_ToolCircArraySubfigure.def(py::init<>());

// Fields

// Methods
// cls_IGESDraw_ToolCircArraySubfigure.def_static("operator new_", (void * (*)(size_t)) &IGESDraw_ToolCircArraySubfigure::operator new, "None", py::arg("theSize"));
// cls_IGESDraw_ToolCircArraySubfigure.def_static("operator delete_", (void (*)(void *)) &IGESDraw_ToolCircArraySubfigure::operator delete, "None", py::arg("theAddress"));
// cls_IGESDraw_ToolCircArraySubfigure.def_static("operator new[]_", (void * (*)(size_t)) &IGESDraw_ToolCircArraySubfigure::operator new[], "None", py::arg("theSize"));
// cls_IGESDraw_ToolCircArraySubfigure.def_static("operator delete[]_", (void (*)(void *)) &IGESDraw_ToolCircArraySubfigure::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDraw_ToolCircArraySubfigure.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDraw_ToolCircArraySubfigure::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDraw_ToolCircArraySubfigure.def_static("operator delete_", (void (*)(void *, void *)) &IGESDraw_ToolCircArraySubfigure::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDraw_ToolCircArraySubfigure.def("ReadOwnParams", (void (IGESDraw_ToolCircArraySubfigure::*)(const opencascade::handle<IGESDraw_CircArraySubfigure> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDraw_ToolCircArraySubfigure::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDraw_ToolCircArraySubfigure.def("WriteOwnParams", (void (IGESDraw_ToolCircArraySubfigure::*)(const opencascade::handle<IGESDraw_CircArraySubfigure> &, IGESData_IGESWriter &) const) &IGESDraw_ToolCircArraySubfigure::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDraw_ToolCircArraySubfigure.def("OwnShared", (void (IGESDraw_ToolCircArraySubfigure::*)(const opencascade::handle<IGESDraw_CircArraySubfigure> &, Interface_EntityIterator &) const) &IGESDraw_ToolCircArraySubfigure::OwnShared, "Lists the Entities shared by a CircArraySubfigure <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDraw_ToolCircArraySubfigure.def("DirChecker", (IGESData_DirChecker (IGESDraw_ToolCircArraySubfigure::*)(const opencascade::handle<IGESDraw_CircArraySubfigure> &) const) &IGESDraw_ToolCircArraySubfigure::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDraw_ToolCircArraySubfigure.def("OwnCheck", (void (IGESDraw_ToolCircArraySubfigure::*)(const opencascade::handle<IGESDraw_CircArraySubfigure> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDraw_ToolCircArraySubfigure::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDraw_ToolCircArraySubfigure.def("OwnCopy", (void (IGESDraw_ToolCircArraySubfigure::*)(const opencascade::handle<IGESDraw_CircArraySubfigure> &, const opencascade::handle<IGESDraw_CircArraySubfigure> &, Interface_CopyTool &) const) &IGESDraw_ToolCircArraySubfigure::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDraw_ToolCircArraySubfigure.def("OwnDump", (void (IGESDraw_ToolCircArraySubfigure::*)(const opencascade::handle<IGESDraw_CircArraySubfigure> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDraw_ToolCircArraySubfigure::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// Enums

}