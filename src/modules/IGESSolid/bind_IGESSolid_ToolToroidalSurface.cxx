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
#include <IGESSolid_ToroidalSurface.hxx>
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
#include <IGESSolid_ToolToroidalSurface.hxx>

void bind_IGESSolid_ToolToroidalSurface(py::module &mod){

py::class_<IGESSolid_ToolToroidalSurface, std::unique_ptr<IGESSolid_ToolToroidalSurface, Deleter<IGESSolid_ToolToroidalSurface>>> cls_IGESSolid_ToolToroidalSurface(mod, "IGESSolid_ToolToroidalSurface", "Tool to work on a ToroidalSurface. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESSolid_ToolToroidalSurface.def(py::init<>());

// Fields

// Methods
// cls_IGESSolid_ToolToroidalSurface.def_static("operator new_", (void * (*)(size_t)) &IGESSolid_ToolToroidalSurface::operator new, "None", py::arg("theSize"));
// cls_IGESSolid_ToolToroidalSurface.def_static("operator delete_", (void (*)(void *)) &IGESSolid_ToolToroidalSurface::operator delete, "None", py::arg("theAddress"));
// cls_IGESSolid_ToolToroidalSurface.def_static("operator new[]_", (void * (*)(size_t)) &IGESSolid_ToolToroidalSurface::operator new[], "None", py::arg("theSize"));
// cls_IGESSolid_ToolToroidalSurface.def_static("operator delete[]_", (void (*)(void *)) &IGESSolid_ToolToroidalSurface::operator delete[], "None", py::arg("theAddress"));
// cls_IGESSolid_ToolToroidalSurface.def_static("operator new_", (void * (*)(size_t, void *)) &IGESSolid_ToolToroidalSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESSolid_ToolToroidalSurface.def_static("operator delete_", (void (*)(void *, void *)) &IGESSolid_ToolToroidalSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESSolid_ToolToroidalSurface.def("ReadOwnParams", (void (IGESSolid_ToolToroidalSurface::*)(const opencascade::handle<IGESSolid_ToroidalSurface> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESSolid_ToolToroidalSurface::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESSolid_ToolToroidalSurface.def("WriteOwnParams", (void (IGESSolid_ToolToroidalSurface::*)(const opencascade::handle<IGESSolid_ToroidalSurface> &, IGESData_IGESWriter &) const) &IGESSolid_ToolToroidalSurface::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESSolid_ToolToroidalSurface.def("OwnShared", (void (IGESSolid_ToolToroidalSurface::*)(const opencascade::handle<IGESSolid_ToroidalSurface> &, Interface_EntityIterator &) const) &IGESSolid_ToolToroidalSurface::OwnShared, "Lists the Entities shared by a ToroidalSurface <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESSolid_ToolToroidalSurface.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolToroidalSurface::*)(const opencascade::handle<IGESSolid_ToroidalSurface> &) const) &IGESSolid_ToolToroidalSurface::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESSolid_ToolToroidalSurface.def("OwnCheck", (void (IGESSolid_ToolToroidalSurface::*)(const opencascade::handle<IGESSolid_ToroidalSurface> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESSolid_ToolToroidalSurface::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESSolid_ToolToroidalSurface.def("OwnCopy", (void (IGESSolid_ToolToroidalSurface::*)(const opencascade::handle<IGESSolid_ToroidalSurface> &, const opencascade::handle<IGESSolid_ToroidalSurface> &, Interface_CopyTool &) const) &IGESSolid_ToolToroidalSurface::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESSolid_ToolToroidalSurface.def("OwnDump", (void (IGESSolid_ToolToroidalSurface::*)(const opencascade::handle<IGESSolid_ToroidalSurface> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESSolid_ToolToroidalSurface::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// Enums

}