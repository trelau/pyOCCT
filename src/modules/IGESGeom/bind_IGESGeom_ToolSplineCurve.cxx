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
#include <IGESGeom_SplineCurve.hxx>
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
#include <IGESGeom_ToolSplineCurve.hxx>

void bind_IGESGeom_ToolSplineCurve(py::module &mod){

py::class_<IGESGeom_ToolSplineCurve, std::unique_ptr<IGESGeom_ToolSplineCurve, Deleter<IGESGeom_ToolSplineCurve>>> cls_IGESGeom_ToolSplineCurve(mod, "IGESGeom_ToolSplineCurve", "Tool to work on a SplineCurve. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESGeom_ToolSplineCurve.def(py::init<>());

// Fields

// Methods
// cls_IGESGeom_ToolSplineCurve.def_static("operator new_", (void * (*)(size_t)) &IGESGeom_ToolSplineCurve::operator new, "None", py::arg("theSize"));
// cls_IGESGeom_ToolSplineCurve.def_static("operator delete_", (void (*)(void *)) &IGESGeom_ToolSplineCurve::operator delete, "None", py::arg("theAddress"));
// cls_IGESGeom_ToolSplineCurve.def_static("operator new[]_", (void * (*)(size_t)) &IGESGeom_ToolSplineCurve::operator new[], "None", py::arg("theSize"));
// cls_IGESGeom_ToolSplineCurve.def_static("operator delete[]_", (void (*)(void *)) &IGESGeom_ToolSplineCurve::operator delete[], "None", py::arg("theAddress"));
// cls_IGESGeom_ToolSplineCurve.def_static("operator new_", (void * (*)(size_t, void *)) &IGESGeom_ToolSplineCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESGeom_ToolSplineCurve.def_static("operator delete_", (void (*)(void *, void *)) &IGESGeom_ToolSplineCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESGeom_ToolSplineCurve.def("ReadOwnParams", (void (IGESGeom_ToolSplineCurve::*)(const opencascade::handle<IGESGeom_SplineCurve> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESGeom_ToolSplineCurve::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESGeom_ToolSplineCurve.def("WriteOwnParams", (void (IGESGeom_ToolSplineCurve::*)(const opencascade::handle<IGESGeom_SplineCurve> &, IGESData_IGESWriter &) const) &IGESGeom_ToolSplineCurve::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESGeom_ToolSplineCurve.def("OwnShared", (void (IGESGeom_ToolSplineCurve::*)(const opencascade::handle<IGESGeom_SplineCurve> &, Interface_EntityIterator &) const) &IGESGeom_ToolSplineCurve::OwnShared, "Lists the Entities shared by a SplineCurve <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESGeom_ToolSplineCurve.def("DirChecker", (IGESData_DirChecker (IGESGeom_ToolSplineCurve::*)(const opencascade::handle<IGESGeom_SplineCurve> &) const) &IGESGeom_ToolSplineCurve::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESGeom_ToolSplineCurve.def("OwnCheck", (void (IGESGeom_ToolSplineCurve::*)(const opencascade::handle<IGESGeom_SplineCurve> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESGeom_ToolSplineCurve::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESGeom_ToolSplineCurve.def("OwnCopy", (void (IGESGeom_ToolSplineCurve::*)(const opencascade::handle<IGESGeom_SplineCurve> &, const opencascade::handle<IGESGeom_SplineCurve> &, Interface_CopyTool &) const) &IGESGeom_ToolSplineCurve::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESGeom_ToolSplineCurve.def("OwnDump", (void (IGESGeom_ToolSplineCurve::*)(const opencascade::handle<IGESGeom_SplineCurve> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESGeom_ToolSplineCurve::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// Enums

}