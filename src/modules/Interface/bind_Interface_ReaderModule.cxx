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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Interface_FileReaderData.hxx>
#include <Interface_Check.hxx>
#include <Interface_ReaderModule.hxx>
#include <Standard_Type.hxx>

void bind_Interface_ReaderModule(py::module &mod){

py::class_<Interface_ReaderModule, opencascade::handle<Interface_ReaderModule>, Standard_Transient> cls_Interface_ReaderModule(mod, "Interface_ReaderModule", "Defines unitary operations required to read an Entity from a File (see FileReaderData, FileReaderTool), under control of a FileReaderTool. The initial creation is performed by a GeneralModule (set in GeneralLib). Then, which remains is Loading data from the FileReaderData to the Entity");

// Fields

// Methods
cls_Interface_ReaderModule.def("CaseNum", (Standard_Integer (Interface_ReaderModule::*)(const opencascade::handle<Interface_FileReaderData> &, const Standard_Integer) const) &Interface_ReaderModule::CaseNum, "Translates the type of record <num> in <data> to a positive Case Number. If Recognition fails, must return 0", py::arg("data"), py::arg("num"));
cls_Interface_ReaderModule.def("Read", (void (Interface_ReaderModule::*)(const Standard_Integer, const opencascade::handle<Interface_FileReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<Standard_Transient> &) const) &Interface_ReaderModule::Read, "Performs the effective loading from <data>, record <num>, to the Entity <ent> formerly created In case of Error or Warning, fills <ach> with messages Remark that the Case Number comes from translating a record", py::arg("casenum"), py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_Interface_ReaderModule.def("NewRead", (Standard_Boolean (Interface_ReaderModule::*)(const Standard_Integer, const opencascade::handle<Interface_FileReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, opencascade::handle<Standard_Transient> &) const) &Interface_ReaderModule::NewRead, "Specific operator (create+read) defaulted to do nothing. It can be redefined when it is not possible to work in two steps (NewVoid then Read). This occurs when no default constructor is defined : hence the result <ent> must be created with an effective definition from the reader. Remark : if NewRead is defined, Copy has nothing to do.", py::arg("casenum"), py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_Interface_ReaderModule.def_static("get_type_name_", (const char * (*)()) &Interface_ReaderModule::get_type_name, "None");
cls_Interface_ReaderModule.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_ReaderModule::get_type_descriptor, "None");
cls_Interface_ReaderModule.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_ReaderModule::*)() const) &Interface_ReaderModule::DynamicType, "None");

// Enums

}