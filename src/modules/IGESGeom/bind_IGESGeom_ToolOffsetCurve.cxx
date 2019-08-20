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
#include <IGESGeom_OffsetCurve.hxx>
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
#include <IGESGeom_ToolOffsetCurve.hxx>

void bind_IGESGeom_ToolOffsetCurve(py::module &mod){

py::class_<IGESGeom_ToolOffsetCurve, std::unique_ptr<IGESGeom_ToolOffsetCurve>> cls_IGESGeom_ToolOffsetCurve(mod, "IGESGeom_ToolOffsetCurve", "Tool to work on a OffsetCurve. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESGeom_ToolOffsetCurve.def(py::init<>());

// Fields

// Methods
// cls_IGESGeom_ToolOffsetCurve.def_static("operator new_", (void * (*)(size_t)) &IGESGeom_ToolOffsetCurve::operator new, "None", py::arg("theSize"));
// cls_IGESGeom_ToolOffsetCurve.def_static("operator delete_", (void (*)(void *)) &IGESGeom_ToolOffsetCurve::operator delete, "None", py::arg("theAddress"));
// cls_IGESGeom_ToolOffsetCurve.def_static("operator new[]_", (void * (*)(size_t)) &IGESGeom_ToolOffsetCurve::operator new[], "None", py::arg("theSize"));
// cls_IGESGeom_ToolOffsetCurve.def_static("operator delete[]_", (void (*)(void *)) &IGESGeom_ToolOffsetCurve::operator delete[], "None", py::arg("theAddress"));
// cls_IGESGeom_ToolOffsetCurve.def_static("operator new_", (void * (*)(size_t, void *)) &IGESGeom_ToolOffsetCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESGeom_ToolOffsetCurve.def_static("operator delete_", (void (*)(void *, void *)) &IGESGeom_ToolOffsetCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESGeom_ToolOffsetCurve.def("ReadOwnParams", (void (IGESGeom_ToolOffsetCurve::*)(const opencascade::handle<IGESGeom_OffsetCurve> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESGeom_ToolOffsetCurve::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESGeom_ToolOffsetCurve.def("WriteOwnParams", (void (IGESGeom_ToolOffsetCurve::*)(const opencascade::handle<IGESGeom_OffsetCurve> &, IGESData_IGESWriter &) const) &IGESGeom_ToolOffsetCurve::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESGeom_ToolOffsetCurve.def("OwnShared", (void (IGESGeom_ToolOffsetCurve::*)(const opencascade::handle<IGESGeom_OffsetCurve> &, Interface_EntityIterator &) const) &IGESGeom_ToolOffsetCurve::OwnShared, "Lists the Entities shared by a OffsetCurve <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESGeom_ToolOffsetCurve.def("OwnCorrect", (Standard_Boolean (IGESGeom_ToolOffsetCurve::*)(const opencascade::handle<IGESGeom_OffsetCurve> &) const) &IGESGeom_ToolOffsetCurve::OwnCorrect, "Sets automatic unambiguous Correction on a OffsetCurve (if OffsetType is not 3, OffsetFunction is cleared)", py::arg("ent"));
cls_IGESGeom_ToolOffsetCurve.def("DirChecker", (IGESData_DirChecker (IGESGeom_ToolOffsetCurve::*)(const opencascade::handle<IGESGeom_OffsetCurve> &) const) &IGESGeom_ToolOffsetCurve::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESGeom_ToolOffsetCurve.def("OwnCheck", (void (IGESGeom_ToolOffsetCurve::*)(const opencascade::handle<IGESGeom_OffsetCurve> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESGeom_ToolOffsetCurve::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESGeom_ToolOffsetCurve.def("OwnCopy", (void (IGESGeom_ToolOffsetCurve::*)(const opencascade::handle<IGESGeom_OffsetCurve> &, const opencascade::handle<IGESGeom_OffsetCurve> &, Interface_CopyTool &) const) &IGESGeom_ToolOffsetCurve::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESGeom_ToolOffsetCurve.def("OwnDump", (void (IGESGeom_ToolOffsetCurve::*)(const opencascade::handle<IGESGeom_OffsetCurve> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESGeom_ToolOffsetCurve::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// Enums

}