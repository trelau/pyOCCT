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
#include <StepData_StepReaderData.hxx>
#include <StepData_Protocol.hxx>
#include <Standard_TypeDef.hxx>
#include <StepData_FileRecognizer.hxx>
#include <Interface_Check.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_GeneralLib.hxx>
#include <Interface_ReaderLib.hxx>
#include <StepData_StepReaderTool.hxx>

void bind_StepData_StepReaderTool(py::module &mod){

py::class_<StepData_StepReaderTool, std::unique_ptr<StepData_StepReaderTool>, Interface_FileReaderTool> cls_StepData_StepReaderTool(mod, "StepData_StepReaderTool", "Specific FileReaderTool for Step; works with FileReaderData provides references evaluation, plus access to litteral data and specific methods defined by FileReaderTool Remarks : works with a ReaderLib to load Entities");

// Constructors
cls_StepData_StepReaderTool.def(py::init<const opencascade::handle<StepData_StepReaderData> &, const opencascade::handle<StepData_Protocol> &>(), py::arg("reader"), py::arg("protocol"));

// Fields

// Methods
// cls_StepData_StepReaderTool.def_static("operator new_", (void * (*)(size_t)) &StepData_StepReaderTool::operator new, "None", py::arg("theSize"));
// cls_StepData_StepReaderTool.def_static("operator delete_", (void (*)(void *)) &StepData_StepReaderTool::operator delete, "None", py::arg("theAddress"));
// cls_StepData_StepReaderTool.def_static("operator new[]_", (void * (*)(size_t)) &StepData_StepReaderTool::operator new[], "None", py::arg("theSize"));
// cls_StepData_StepReaderTool.def_static("operator delete[]_", (void (*)(void *)) &StepData_StepReaderTool::operator delete[], "None", py::arg("theAddress"));
// cls_StepData_StepReaderTool.def_static("operator new_", (void * (*)(size_t, void *)) &StepData_StepReaderTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepData_StepReaderTool.def_static("operator delete_", (void (*)(void *, void *)) &StepData_StepReaderTool::operator delete, "None", py::arg(""), py::arg(""));
cls_StepData_StepReaderTool.def("Prepare", [](StepData_StepReaderTool &self) -> void { return self.Prepare(); });
cls_StepData_StepReaderTool.def("Prepare", (void (StepData_StepReaderTool::*)(const Standard_Boolean)) &StepData_StepReaderTool::Prepare, "Bounds empty entities to records, uses default Recognition provided by ReaderLib and ReaderModule. Also calls computation of references (SetEntityNumbers from StepReaderData) Works only on data entities (skips header) <optimize> given False allows to test some internal algorithms which are normally avoided (see also StepReaderData)", py::arg("optimize"));
cls_StepData_StepReaderTool.def("Prepare", [](StepData_StepReaderTool &self, const opencascade::handle<StepData_FileRecognizer> & a0) -> void { return self.Prepare(a0); });
cls_StepData_StepReaderTool.def("Prepare", (void (StepData_StepReaderTool::*)(const opencascade::handle<StepData_FileRecognizer> &, const Standard_Boolean)) &StepData_StepReaderTool::Prepare, "Bounds empty entities to records, works with a specific FileRecognizer, stored and later used in Recognize Works only on data entities (skips header) <optimize : same as above", py::arg("reco"), py::arg("optimize"));
cls_StepData_StepReaderTool.def("Recognize", (Standard_Boolean (StepData_StepReaderTool::*)(const Standard_Integer, opencascade::handle<Interface_Check> &, opencascade::handle<Standard_Transient> &)) &StepData_StepReaderTool::Recognize, "recognizes records, by asking either ReaderLib (default) or FileRecognizer (if defined) to do so. <ach> is to call RecognizeByLib", py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_StepData_StepReaderTool.def("PrepareHeader", (void (StepData_StepReaderTool::*)(const opencascade::handle<StepData_FileRecognizer> &)) &StepData_StepReaderTool::PrepareHeader, "bounds empty entities and sub-lists to header records works like Prepare + SetEntityNumbers, but for header (N.B.: in Header, no Ident and no reference) FileRecognizer is to specify Entities which are allowed to be defined in the Header (not every type can be)", py::arg("reco"));
cls_StepData_StepReaderTool.def("BeginRead", (void (StepData_StepReaderTool::*)(const opencascade::handle<Interface_InterfaceModel> &)) &StepData_StepReaderTool::BeginRead, "fills model's header; that is, gives to it Header entities and commands their loading. Also fills StepModel's Global Check from StepReaderData's GlobalCheck", py::arg("amodel"));
cls_StepData_StepReaderTool.def("AnalyseRecord", (Standard_Boolean (StepData_StepReaderTool::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, opencascade::handle<Interface_Check> &)) &StepData_StepReaderTool::AnalyseRecord, "fills an entity, given record no; works by using a ReaderLib to load each entity, which must be a Transient Actually, returned value is True if no fail, False else", py::arg("num"), py::arg("anent"), py::arg("acheck"));
cls_StepData_StepReaderTool.def("EndRead", (void (StepData_StepReaderTool::*)(const opencascade::handle<Interface_InterfaceModel> &)) &StepData_StepReaderTool::EndRead, "Ends file reading after reading all the entities Here, it binds in the model, Idents to Entities (for checks)", py::arg("amodel"));

// Enums

}