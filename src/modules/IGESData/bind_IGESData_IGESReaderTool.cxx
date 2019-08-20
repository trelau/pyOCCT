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
#include <Interface_FileReaderTool.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESReaderData.hxx>
#include <IGESData_Protocol.hxx>
#include <IGESData_FileRecognizer.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_Check.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <IGESData_IGESEntity.hxx>
#include <IGESData_DirPart.hxx>
#include <IGESData_ParamReader.hxx>
#include <Interface_ParamList.hxx>
#include <Interface_GeneralLib.hxx>
#include <Interface_ReaderLib.hxx>
#include <IGESData_IGESType.hxx>
#include <IGESData_ReadStage.hxx>
#include <IGESData_IGESReaderTool.hxx>

void bind_IGESData_IGESReaderTool(py::module &mod){

py::class_<IGESData_IGESReaderTool, std::unique_ptr<IGESData_IGESReaderTool>, Interface_FileReaderTool> cls_IGESData_IGESReaderTool(mod, "IGESData_IGESReaderTool", "specific FileReaderTool for IGES Parameters are accessed through specific objects, ParamReaders");

// Constructors
cls_IGESData_IGESReaderTool.def(py::init<const opencascade::handle<IGESData_IGESReaderData> &, const opencascade::handle<IGESData_Protocol> &>(), py::arg("reader"), py::arg("protocol"));

// Fields

// Methods
// cls_IGESData_IGESReaderTool.def_static("operator new_", (void * (*)(size_t)) &IGESData_IGESReaderTool::operator new, "None", py::arg("theSize"));
// cls_IGESData_IGESReaderTool.def_static("operator delete_", (void (*)(void *)) &IGESData_IGESReaderTool::operator delete, "None", py::arg("theAddress"));
// cls_IGESData_IGESReaderTool.def_static("operator new[]_", (void * (*)(size_t)) &IGESData_IGESReaderTool::operator new[], "None", py::arg("theSize"));
// cls_IGESData_IGESReaderTool.def_static("operator delete[]_", (void (*)(void *)) &IGESData_IGESReaderTool::operator delete[], "None", py::arg("theAddress"));
// cls_IGESData_IGESReaderTool.def_static("operator new_", (void * (*)(size_t, void *)) &IGESData_IGESReaderTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESData_IGESReaderTool.def_static("operator delete_", (void (*)(void *, void *)) &IGESData_IGESReaderTool::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESData_IGESReaderTool.def("Prepare", (void (IGESData_IGESReaderTool::*)(const opencascade::handle<IGESData_FileRecognizer> &)) &IGESData_IGESReaderTool::Prepare, "binds empty entities to records, works with the Protocol (from IGESData) stored and later used RQ : Actually, sets DNum into IGES Entities Also loads the list of parameters for ParamReader", py::arg("reco"));
cls_IGESData_IGESReaderTool.def("Recognize", (Standard_Boolean (IGESData_IGESReaderTool::*)(const Standard_Integer, opencascade::handle<Interface_Check> &, opencascade::handle<Standard_Transient> &)) &IGESData_IGESReaderTool::Recognize, "recognizes records by asking Protocol (on data of DirType)", py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_IGESData_IGESReaderTool.def("BeginRead", (void (IGESData_IGESReaderTool::*)(const opencascade::handle<Interface_InterfaceModel> &)) &IGESData_IGESReaderTool::BeginRead, "fills model's header, that is, its GlobalSection", py::arg("amodel"));
cls_IGESData_IGESReaderTool.def("AnalyseRecord", (Standard_Boolean (IGESData_IGESReaderTool::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, opencascade::handle<Interface_Check> &)) &IGESData_IGESReaderTool::AnalyseRecord, "fills an entity, given record no; works by calling ReadDirPart then ReadParams (with help of a ParamReader), then if required ReadProps and ReadAssocs, from IGESEntity Returns True if no fail has been recorded", py::arg("num"), py::arg("anent"), py::arg("acheck"));
cls_IGESData_IGESReaderTool.def("EndRead", (void (IGESData_IGESReaderTool::*)(const opencascade::handle<Interface_InterfaceModel> &)) &IGESData_IGESReaderTool::EndRead, "after reading entities, true line weights can be computed", py::arg("amodel"));
cls_IGESData_IGESReaderTool.def("ReadDir", (void (IGESData_IGESReaderTool::*)(const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESReaderData> &, const IGESData_DirPart &, opencascade::handle<Interface_Check> &) const) &IGESData_IGESReaderTool::ReadDir, "Reads directory part componants from file; DP is the litteral directory part, IR detains entities referenced by DP", py::arg("ent"), py::arg("IR"), py::arg("DP"), py::arg("ach"));
cls_IGESData_IGESReaderTool.def("ReadOwnParams", (void (IGESData_IGESReaderTool::*)(const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESData_IGESReaderTool::ReadOwnParams, "Performs Reading of own Parameters for each IGESEntity Works with the ReaderLib loaded with ReadWriteModules for IGES In case of failure, tries UndefinedEntity from IGES", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESData_IGESReaderTool.def("ReadProps", (void (IGESData_IGESReaderTool::*)(const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESData_IGESReaderTool::ReadProps, "Reads Property List, if there is (if not, does nothing) criterium is : current parameter of PR remains inside params list, and Stage is 'Own' Current parameter must be a positive integer, which value gives the length of the list; else, a Fail is produced (into Check of PR) and reading process is stopped", py::arg("ent"), py::arg("IR"), py::arg("PR"));
cls_IGESData_IGESReaderTool.def("ReadAssocs", (void (IGESData_IGESReaderTool::*)(const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_IGESReaderData> &, IGESData_ParamReader &) const) &IGESData_IGESReaderTool::ReadAssocs, "Reads Associativity List, if there is (if not, does nothing) criterium is : current parameter of PR remains inside params list, and Stage is 'Own' Same conditions as above; in addition, no parameter must be let after the list once read Note that 'Associated' entities are not declared 'Shared'", py::arg("ent"), py::arg("IR"), py::arg("PR"));

// Enums

}