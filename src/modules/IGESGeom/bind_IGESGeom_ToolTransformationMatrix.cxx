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
#include <IGESGeom_TransformationMatrix.hxx>
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
#include <IGESGeom_ToolTransformationMatrix.hxx>

void bind_IGESGeom_ToolTransformationMatrix(py::module &mod){

py::class_<IGESGeom_ToolTransformationMatrix, std::unique_ptr<IGESGeom_ToolTransformationMatrix>> cls_IGESGeom_ToolTransformationMatrix(mod, "IGESGeom_ToolTransformationMatrix", "Tool to work on a TransformationMatrix. Called by various Modules (ReadWriteModule, GeneralModule, SpecificModule)");

// Constructors
cls_IGESGeom_ToolTransformationMatrix.def(py::init<>());

// Fields

// Methods
// cls_IGESGeom_ToolTransformationMatrix.def_static("operator new_", (void * (*)(size_t)) &IGESGeom_ToolTransformationMatrix::operator new, "None", py::arg("theSize"));
// cls_IGESGeom_ToolTransformationMatrix.def_static("operator delete_", (void (*)(void *)) &IGESGeom_ToolTransformationMatrix::operator delete, "None", py::arg("theAddress"));
// cls_IGESGeom_ToolTransformationMatrix.def_static("operator new[]_", (void * (*)(size_t)) &IGESGeom_ToolTransformationMatrix::operator new[], "None", py::arg("theSize"));
// cls_IGESGeom_ToolTransformationMatrix.def_static("operator delete[]_", (void (*)(void *)) &IGESGeom_ToolTransformationMatrix::operator delete[], "None", py::arg("theAddress"));
// cls_IGESGeom_ToolTransformationMatrix.def_static("operator new_", (void * (*)(size_t, void *)) &IGESGeom_ToolTransformationMatrix::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESGeom_ToolTransformationMatrix.def_static("operator delete_", (void (*)(void *, void *)) &IGESGeom_ToolTransformationMatrix::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESGeom_ToolTransformationMatrix.def("ReadOwnParams", (void (IGESGeom_ToolTransformationMatrix::*)(const opencascade::handle<IGESGeom_TransformationMatrix> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESGeom_ToolTransformationMatrix::ReadOwnParams, "Reads own parameters from file. <PR> gives access to them, <IR> detains parameter types and values", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESGeom_ToolTransformationMatrix.def("WriteOwnParams", (void (IGESGeom_ToolTransformationMatrix::*)(const opencascade::handle<IGESGeom_TransformationMatrix> &, IGESData_IGESWriter &) const) &IGESGeom_ToolTransformationMatrix::WriteOwnParams, "Writes own parameters to IGESWriter", py::arg("ent"), py::arg("IW"));
cls_IGESGeom_ToolTransformationMatrix.def("OwnShared", (void (IGESGeom_ToolTransformationMatrix::*)(const opencascade::handle<IGESGeom_TransformationMatrix> &, Interface_EntityIterator &) const) &IGESGeom_ToolTransformationMatrix::OwnShared, "Lists the Entities shared by a TransformationMatrix <ent>, from its specific (own) parameters", py::arg("ent"), py::arg("iter"));
cls_IGESGeom_ToolTransformationMatrix.def("OwnCorrect", (Standard_Boolean (IGESGeom_ToolTransformationMatrix::*)(const opencascade::handle<IGESGeom_TransformationMatrix> &) const) &IGESGeom_ToolTransformationMatrix::OwnCorrect, "Sets automatic unambiguous Correction on a TransformationMatrix (FormNumber if 0 or 1, recomputed according Positive/Negative)", py::arg("ent"));
cls_IGESGeom_ToolTransformationMatrix.def("DirChecker", (IGESData_DirChecker (IGESGeom_ToolTransformationMatrix::*)(const opencascade::handle<IGESGeom_TransformationMatrix> &) const) &IGESGeom_ToolTransformationMatrix::DirChecker, "Returns specific DirChecker", py::arg("ent"));
cls_IGESGeom_ToolTransformationMatrix.def("OwnCheck", (void (IGESGeom_ToolTransformationMatrix::*)(const opencascade::handle<IGESGeom_TransformationMatrix> &, const Interface_ShareTool &, opencascade::handle<Interface_Check> &) const) &IGESGeom_ToolTransformationMatrix::OwnCheck, "Performs Specific Semantic Check", py::arg("ent"), py::arg("shares"), py::arg("ach"));
cls_IGESGeom_ToolTransformationMatrix.def("OwnCopy", (void (IGESGeom_ToolTransformationMatrix::*)(const opencascade::handle<IGESGeom_TransformationMatrix> &, const opencascade::handle<IGESGeom_TransformationMatrix> &, Interface_CopyTool &) const) &IGESGeom_ToolTransformationMatrix::OwnCopy, "Copies Specific Parameters", py::arg("entfrom"), py::arg("entto"), py::arg("TC"));
cls_IGESGeom_ToolTransformationMatrix.def("OwnDump", (void (IGESGeom_ToolTransformationMatrix::*)(const opencascade::handle<IGESGeom_TransformationMatrix> &, const IGESData_IGESDumper &, const opencascade::handle<Message_Messenger> &, const Standard_Integer) const) &IGESGeom_ToolTransformationMatrix::OwnDump, "Dump of Specific Parameters", py::arg("ent"), py::arg("dumper"), py::arg("S"), py::arg("own"));

// Enums

}