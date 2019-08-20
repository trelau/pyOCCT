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
#include <IGESGeom_SplineSurface.hxx>
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
#include <IGESGeom_ToolSplineSurface.hxx>

void bind_IGESGeom_ToolSplineSurface(py::module &mod){

py::class_<IGESGeom_ToolSplineSurface, std::unique_ptr<IGESGeom_ToolSplineSurface>> cls_IGESGeom_ToolSplineSurface(mod, "IGESGeom_ToolSplineSurface", "Tool to work on a SplineSurface. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESGeom_ToolSplineSurface.def(py::init<>());

// Fields

// Methods
// cls_IGESGeom_ToolSplineSurface.def_static("operator new_", (void * (*)(size_t)) &IGESGeom_ToolSplineSurface::operator new, "None", py::arg("theSize"));
// cls_IGESGeom_ToolSplineSurface.def_static("operator delete_", (void (*)(void *)) &IGESGeom_ToolSplineSurface::operator delete, "None", py::arg("theAddress"));
// cls_IGESGeom_ToolSplineSurface.def_static("operator new[]_", (void * (*)(size_t)) &IGESGeom_ToolSplineSurface::operator new[], "None", py::arg("theSize"));
// cls_IGESGeom_ToolSplineSurface.def_static("operator delete[]_", (void (*)(void *)) &IGESGeom_ToolSplineSurface::operator delete[], "None", py::arg("theAddress"));
// cls_IGESGeom_ToolSplineSurface.def_static("operator new_", (void * (*)(size_t, void *)) &IGESGeom_ToolSplineSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESGeom_ToolSplineSurface.def_static("operator delete_", (void (*)(void *, void *)) &IGESGeom_ToolSplineSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESGeom_ToolSplineSurface.def("ReadOwnParams", (void (IGESGeom_ToolSplineSurface::*)(const opencascade::handle<IGESGeom_SplineSurface> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESGeom_ToolSplineSurface::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESGeom_ToolSplineSurface.def("WriteOwnParams", (void (IGESGeom_ToolSplineSurface::*)(const opencascade::handle<IGESGeom_SplineSurface> &, IGESData_IGESWriter &) const) &IGESGeom_ToolSplineSurface::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESGeom_ToolSplineSurface.def("OwnShared", (void (IGESGeom_ToolSplineSurface::*)(const opencascade::handle<IGESGeom_SplineSurface> &, Interface_EntityIterator &) const) &IGESGeom_ToolSplineSurface::OwnShared, "Lists the Entities shared by a SplineSurface <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESGeom_ToolSplineSurface.def("DirChecker", (IGESData_DirChecker (IGESGeom_ToolSplineSurface::*)(const opencascade::handle<IGESGeom_SplineSurface> &) const) &IGESGeom_ToolSplineSurface::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESGeom_ToolSplineSurface.def("OwnCheck", (void (IGESGeom_ToolSplineSurface::*)(const opencascade::handle<IGESGeom_SplineSurface> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESGeom_ToolSplineSurface::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESGeom_ToolSplineSurface.def("OwnCopy", (void (IGESGeom_ToolSplineSurface::*)(const opencascade::handle<IGESGeom_SplineSurface> &, const opencascade::handle<IGESGeom_SplineSurface> &, Interface_CopyTool &) const) &IGESGeom_ToolSplineSurface::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESGeom_ToolSplineSurface.def("OwnDump", (void (IGESGeom_ToolSplineSurface::*)(const opencascade::handle<IGESGeom_SplineSurface> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESGeom_ToolSplineSurface::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// Enums

}