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
#include <IGESAppli_RegionRestriction.hxx>
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
#include <IGESAppli_ToolRegionRestriction.hxx>

void bind_IGESAppli_ToolRegionRestriction(py::module &mod){

py::class_<IGESAppli_ToolRegionRestriction, std::unique_ptr<IGESAppli_ToolRegionRestriction>> cls_IGESAppli_ToolRegionRestriction(mod, "IGESAppli_ToolRegionRestriction", "Tool to work on a RegionRestriction. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESAppli_ToolRegionRestriction.def(py::init<>());

// Fields

// Methods
// cls_IGESAppli_ToolRegionRestriction.def_static("operator new_", (void * (*)(size_t)) &IGESAppli_ToolRegionRestriction::operator new, "None", py::arg("theSize"));
// cls_IGESAppli_ToolRegionRestriction.def_static("operator delete_", (void (*)(void *)) &IGESAppli_ToolRegionRestriction::operator delete, "None", py::arg("theAddress"));
// cls_IGESAppli_ToolRegionRestriction.def_static("operator new[]_", (void * (*)(size_t)) &IGESAppli_ToolRegionRestriction::operator new[], "None", py::arg("theSize"));
// cls_IGESAppli_ToolRegionRestriction.def_static("operator delete[]_", (void (*)(void *)) &IGESAppli_ToolRegionRestriction::operator delete[], "None", py::arg("theAddress"));
// cls_IGESAppli_ToolRegionRestriction.def_static("operator new_", (void * (*)(size_t, void *)) &IGESAppli_ToolRegionRestriction::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESAppli_ToolRegionRestriction.def_static("operator delete_", (void (*)(void *, void *)) &IGESAppli_ToolRegionRestriction::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESAppli_ToolRegionRestriction.def("ReadOwnParams", (void (IGESAppli_ToolRegionRestriction::*)(const opencascade::handle<IGESAppli_RegionRestriction> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESAppli_ToolRegionRestriction::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESAppli_ToolRegionRestriction.def("WriteOwnParams", (void (IGESAppli_ToolRegionRestriction::*)(const opencascade::handle<IGESAppli_RegionRestriction> &, IGESData_IGESWriter &) const) &IGESAppli_ToolRegionRestriction::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESAppli_ToolRegionRestriction.def("OwnShared", (void (IGESAppli_ToolRegionRestriction::*)(const opencascade::handle<IGESAppli_RegionRestriction> &, Interface_EntityIterator &) const) &IGESAppli_ToolRegionRestriction::OwnShared, "Lists the Entities shared by a RegionRestriction <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESAppli_ToolRegionRestriction.def("OwnCorrect", (Standard_Boolean (IGESAppli_ToolRegionRestriction::*)(const opencascade::handle<IGESAppli_RegionRestriction> &) const) &IGESAppli_ToolRegionRestriction::OwnCorrect, "Sets automatic unambiguous Correction on a RegionRestriction (NbPropertyValues forced to 3, Level cleared if Subordinate != 0)", py::arg("ent"));
cls_IGESAppli_ToolRegionRestriction.def("DirChecker", (IGESData_DirChecker (IGESAppli_ToolRegionRestriction::*)(const opencascade::handle<IGESAppli_RegionRestriction> &) const) &IGESAppli_ToolRegionRestriction::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESAppli_ToolRegionRestriction.def("OwnCheck", (void (IGESAppli_ToolRegionRestriction::*)(const opencascade::handle<IGESAppli_RegionRestriction> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESAppli_ToolRegionRestriction::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESAppli_ToolRegionRestriction.def("OwnCopy", (void (IGESAppli_ToolRegionRestriction::*)(const opencascade::handle<IGESAppli_RegionRestriction> &, const opencascade::handle<IGESAppli_RegionRestriction> &, Interface_CopyTool &) const) &IGESAppli_ToolRegionRestriction::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESAppli_ToolRegionRestriction.def("OwnDump", (void (IGESAppli_ToolRegionRestriction::*)(const opencascade::handle<IGESAppli_RegionRestriction> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESAppli_ToolRegionRestriction::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// Enums

}