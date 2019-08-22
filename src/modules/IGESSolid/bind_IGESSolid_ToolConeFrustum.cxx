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
#include <IGESSolid_ConeFrustum.hxx>
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
#include <IGESSolid_ToolConeFrustum.hxx>

void bind_IGESSolid_ToolConeFrustum(py::module &mod){

py::class_<IGESSolid_ToolConeFrustum> cls_IGESSolid_ToolConeFrustum(mod, "IGESSolid_ToolConeFrustum", "Tool to work on a ConeFrustum. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESSolid_ToolConeFrustum.def(py::init<>());

// Fields

// Methods
// cls_IGESSolid_ToolConeFrustum.def_static("operator new_", (void * (*)(size_t)) &IGESSolid_ToolConeFrustum::operator new, "None", py::arg("theSize"));
// cls_IGESSolid_ToolConeFrustum.def_static("operator delete_", (void (*)(void *)) &IGESSolid_ToolConeFrustum::operator delete, "None", py::arg("theAddress"));
// cls_IGESSolid_ToolConeFrustum.def_static("operator new[]_", (void * (*)(size_t)) &IGESSolid_ToolConeFrustum::operator new[], "None", py::arg("theSize"));
// cls_IGESSolid_ToolConeFrustum.def_static("operator delete[]_", (void (*)(void *)) &IGESSolid_ToolConeFrustum::operator delete[], "None", py::arg("theAddress"));
// cls_IGESSolid_ToolConeFrustum.def_static("operator new_", (void * (*)(size_t, void *)) &IGESSolid_ToolConeFrustum::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESSolid_ToolConeFrustum.def_static("operator delete_", (void (*)(void *, void *)) &IGESSolid_ToolConeFrustum::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESSolid_ToolConeFrustum.def("ReadOwnParams", (void (IGESSolid_ToolConeFrustum::*)(const opencascade::handle<IGESSolid_ConeFrustum> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESSolid_ToolConeFrustum::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESSolid_ToolConeFrustum.def("WriteOwnParams", (void (IGESSolid_ToolConeFrustum::*)(const opencascade::handle<IGESSolid_ConeFrustum> &, IGESData_IGESWriter &) const) &IGESSolid_ToolConeFrustum::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESSolid_ToolConeFrustum.def("OwnShared", (void (IGESSolid_ToolConeFrustum::*)(const opencascade::handle<IGESSolid_ConeFrustum> &, Interface_EntityIterator &) const) &IGESSolid_ToolConeFrustum::OwnShared, "Lists the Entities shared by a ConeFrustum <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESSolid_ToolConeFrustum.def("DirChecker", (IGESData_DirChecker (IGESSolid_ToolConeFrustum::*)(const opencascade::handle<IGESSolid_ConeFrustum> &) const) &IGESSolid_ToolConeFrustum::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESSolid_ToolConeFrustum.def("OwnCheck", (void (IGESSolid_ToolConeFrustum::*)(const opencascade::handle<IGESSolid_ConeFrustum> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESSolid_ToolConeFrustum::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESSolid_ToolConeFrustum.def("OwnCopy", (void (IGESSolid_ToolConeFrustum::*)(const opencascade::handle<IGESSolid_ConeFrustum> &, const opencascade::handle<IGESSolid_ConeFrustum> &, Interface_CopyTool &) const) &IGESSolid_ToolConeFrustum::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESSolid_ToolConeFrustum.def("OwnDump", (void (IGESSolid_ToolConeFrustum::*)(const opencascade::handle<IGESSolid_ConeFrustum> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESSolid_ToolConeFrustum::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// Enums

}