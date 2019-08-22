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
#include <StepData_StepReaderData.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <StepData_Protocol.hxx>
#include <StepData_FileProtocol.hxx>
#include <Standard_OStream.hxx>
#include <StepData_HeaderTool.hxx>

void bind_StepData_HeaderTool(py::module &mod){

py::class_<StepData_HeaderTool> cls_StepData_HeaderTool(mod, "StepData_HeaderTool", "HeaderTool exploits data from Header to build a Protocol : it uses the Header Entity FileSchema to do this. It builds a Protocol from the Global List of Protocols stored in the Library ReaderLib");

// Constructors
cls_StepData_HeaderTool.def(py::init<const opencascade::handle<StepData_StepReaderData> &>(), py::arg("data"));
cls_StepData_HeaderTool.def(py::init<const TColStd_SequenceOfAsciiString &>(), py::arg("names"));

// Fields

// Methods
// cls_StepData_HeaderTool.def_static("operator new_", (void * (*)(size_t)) &StepData_HeaderTool::operator new, "None", py::arg("theSize"));
// cls_StepData_HeaderTool.def_static("operator delete_", (void (*)(void *)) &StepData_HeaderTool::operator delete, "None", py::arg("theAddress"));
// cls_StepData_HeaderTool.def_static("operator new[]_", (void * (*)(size_t)) &StepData_HeaderTool::operator new[], "None", py::arg("theSize"));
// cls_StepData_HeaderTool.def_static("operator delete[]_", (void (*)(void *)) &StepData_HeaderTool::operator delete[], "None", py::arg("theAddress"));
// cls_StepData_HeaderTool.def_static("operator new_", (void * (*)(size_t, void *)) &StepData_HeaderTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepData_HeaderTool.def_static("operator delete_", (void (*)(void *, void *)) &StepData_HeaderTool::operator delete, "None", py::arg(""), py::arg(""));
cls_StepData_HeaderTool.def("NbSchemaNames", (Standard_Integer (StepData_HeaderTool::*)() const) &StepData_HeaderTool::NbSchemaNames, "Returns the count of SchemaNames");
cls_StepData_HeaderTool.def("SchemaName", (const TCollection_AsciiString & (StepData_HeaderTool::*)(const Standard_Integer) const) &StepData_HeaderTool::SchemaName, "Returns a SchemaName, given its rank", py::arg("num"));
cls_StepData_HeaderTool.def("NamedProtocol", (opencascade::handle<StepData_Protocol> (StepData_HeaderTool::*)(const TCollection_AsciiString &) const) &StepData_HeaderTool::NamedProtocol, "Returns the Protocol which corresponds to a Schema Name Returns a Null Handle if this Schema Name is attached to no Protocol recorded in the Global List of ReaderLib", py::arg("name"));
cls_StepData_HeaderTool.def("Build", (void (StepData_HeaderTool::*)(const opencascade::handle<StepData_FileProtocol> &)) &StepData_HeaderTool::Build, "Fills a FileProtocol with the list of Protocols attached to the list of Schema Names. It can remain empty ...", py::arg("protocol"));
cls_StepData_HeaderTool.def("Protocol", (opencascade::handle<StepData_Protocol> (StepData_HeaderTool::*)()) &StepData_HeaderTool::Protocol, "Returns a Protocol computed from the list of Schema Names : - a Null Handle if no SchemaName has been recognized (or list empty) - a single Protocol if only one SchemaName has been recognized - a FileProtocol with its componants if several SchemaNames have been recognized");
cls_StepData_HeaderTool.def("IsDone", (Standard_Boolean (StepData_HeaderTool::*)() const) &StepData_HeaderTool::IsDone, "Returns True if either Build or Protocol has been called If it is False, Ignored and NbIgnored should not be called");
cls_StepData_HeaderTool.def("NbIgnoreds", (Standard_Integer (StepData_HeaderTool::*)() const) &StepData_HeaderTool::NbIgnoreds, "Returns the count of ignored SchemaNames (0 if all were OK)");
cls_StepData_HeaderTool.def("Ignored", (const TCollection_AsciiString & (StepData_HeaderTool::*)(const Standard_Integer) const) &StepData_HeaderTool::Ignored, "Returns an ignored SchemaName, given its rank in the list of Ignored SchemaNames (not in the total list)", py::arg("num"));
cls_StepData_HeaderTool.def("Print", (void (StepData_HeaderTool::*)(Standard_OStream &) const) &StepData_HeaderTool::Print, "Sends the state of the HeaderTool in a comprehensive way, to an output stream", py::arg("S"));

// Enums

}