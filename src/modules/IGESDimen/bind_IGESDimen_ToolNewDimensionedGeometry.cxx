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
#include <IGESDimen_NewDimensionedGeometry.hxx>
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
#include <IGESDimen_ToolNewDimensionedGeometry.hxx>

void bind_IGESDimen_ToolNewDimensionedGeometry(py::module &mod){

py::class_<IGESDimen_ToolNewDimensionedGeometry, std::unique_ptr<IGESDimen_ToolNewDimensionedGeometry, Deleter<IGESDimen_ToolNewDimensionedGeometry>>> cls_IGESDimen_ToolNewDimensionedGeometry(mod, "IGESDimen_ToolNewDimensionedGeometry", "Tool to work on a NewDimensionedGeometry. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESDimen_ToolNewDimensionedGeometry.def(py::init<>());

// Fields

// Methods
// cls_IGESDimen_ToolNewDimensionedGeometry.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_ToolNewDimensionedGeometry::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_ToolNewDimensionedGeometry.def_static("operator delete_", (void (*)(void *)) &IGESDimen_ToolNewDimensionedGeometry::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_ToolNewDimensionedGeometry.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_ToolNewDimensionedGeometry::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_ToolNewDimensionedGeometry.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_ToolNewDimensionedGeometry::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_ToolNewDimensionedGeometry.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_ToolNewDimensionedGeometry::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_ToolNewDimensionedGeometry.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_ToolNewDimensionedGeometry::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESDimen_ToolNewDimensionedGeometry.def("ReadOwnParams", (void (IGESDimen_ToolNewDimensionedGeometry::*)(const opencascade::handle<IGESDimen_NewDimensionedGeometry> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESDimen_ToolNewDimensionedGeometry::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESDimen_ToolNewDimensionedGeometry.def("WriteOwnParams", (void (IGESDimen_ToolNewDimensionedGeometry::*)(const opencascade::handle<IGESDimen_NewDimensionedGeometry> &, IGESData_IGESWriter &) const) &IGESDimen_ToolNewDimensionedGeometry::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESDimen_ToolNewDimensionedGeometry.def("OwnShared", (void (IGESDimen_ToolNewDimensionedGeometry::*)(const opencascade::handle<IGESDimen_NewDimensionedGeometry> &, Interface_EntityIterator &) const) &IGESDimen_ToolNewDimensionedGeometry::OwnShared, "Lists the Entities shared by a NewDimensionedGeometry <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESDimen_ToolNewDimensionedGeometry.def("OwnCorrect", (Standard_Boolean (IGESDimen_ToolNewDimensionedGeometry::*)(const opencascade::handle<IGESDimen_NewDimensionedGeometry> &) const) &IGESDimen_ToolNewDimensionedGeometry::OwnCorrect, "Sets automatic unambiguous Correction on a NewDimensionedGeometry (NbDimensions forced to 1, Transf Nullified in D.E.)", py::arg("ent"));
cls_IGESDimen_ToolNewDimensionedGeometry.def("DirChecker", (IGESData_DirChecker (IGESDimen_ToolNewDimensionedGeometry::*)(const opencascade::handle<IGESDimen_NewDimensionedGeometry> &) const) &IGESDimen_ToolNewDimensionedGeometry::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESDimen_ToolNewDimensionedGeometry.def("OwnCheck", (void (IGESDimen_ToolNewDimensionedGeometry::*)(const opencascade::handle<IGESDimen_NewDimensionedGeometry> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESDimen_ToolNewDimensionedGeometry::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESDimen_ToolNewDimensionedGeometry.def("OwnCopy", (void (IGESDimen_ToolNewDimensionedGeometry::*)(const opencascade::handle<IGESDimen_NewDimensionedGeometry> &, const opencascade::handle<IGESDimen_NewDimensionedGeometry> &, Interface_CopyTool &) const) &IGESDimen_ToolNewDimensionedGeometry::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESDimen_ToolNewDimensionedGeometry.def("OwnDump", (void (IGESDimen_ToolNewDimensionedGeometry::*)(const opencascade::handle<IGESDimen_NewDimensionedGeometry> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESDimen_ToolNewDimensionedGeometry::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// Enums

}