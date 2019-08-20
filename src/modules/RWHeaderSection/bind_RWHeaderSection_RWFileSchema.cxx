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
#include <Standard_TypeDef.hxx>
#include <Interface_Check.hxx>
#include <HeaderSection_FileSchema.hxx>
#include <StepData_StepWriter.hxx>
#include <RWHeaderSection_RWFileSchema.hxx>

void bind_RWHeaderSection_RWFileSchema(py::module &mod){

py::class_<RWHeaderSection_RWFileSchema, std::unique_ptr<RWHeaderSection_RWFileSchema>> cls_RWHeaderSection_RWFileSchema(mod, "RWHeaderSection_RWFileSchema", "Read & Write Module for FileSchema");

// Constructors
cls_RWHeaderSection_RWFileSchema.def(py::init<>());

// Fields

// Methods
// cls_RWHeaderSection_RWFileSchema.def_static("operator new_", (void * (*)(size_t)) &RWHeaderSection_RWFileSchema::operator new, "None", py::arg("theSize"));
// cls_RWHeaderSection_RWFileSchema.def_static("operator delete_", (void (*)(void *)) &RWHeaderSection_RWFileSchema::operator delete, "None", py::arg("theAddress"));
// cls_RWHeaderSection_RWFileSchema.def_static("operator new[]_", (void * (*)(size_t)) &RWHeaderSection_RWFileSchema::operator new[], "None", py::arg("theSize"));
// cls_RWHeaderSection_RWFileSchema.def_static("operator delete[]_", (void (*)(void *)) &RWHeaderSection_RWFileSchema::operator delete[], "None", py::arg("theAddress"));
// cls_RWHeaderSection_RWFileSchema.def_static("operator new_", (void * (*)(size_t, void *)) &RWHeaderSection_RWFileSchema::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_RWHeaderSection_RWFileSchema.def_static("operator delete_", (void (*)(void *, void *)) &RWHeaderSection_RWFileSchema::operator delete, "None", py::arg(""), py::arg(""));
cls_RWHeaderSection_RWFileSchema.def("ReadStep", (void (RWHeaderSection_RWFileSchema::*)(const opencascade::handle<StepData_StepReaderData> &, const Standard_Integer, opencascade::handle<Interface_Check> &, const opencascade::handle<HeaderSection_FileSchema> &) const) &RWHeaderSection_RWFileSchema::ReadStep, "None", py::arg("data"), py::arg("num"), py::arg("ach"), py::arg("ent"));
cls_RWHeaderSection_RWFileSchema.def("WriteStep", (void (RWHeaderSection_RWFileSchema::*)(StepData_StepWriter &, const opencascade::handle<HeaderSection_FileSchema> &) const) &RWHeaderSection_RWFileSchema::WriteStep, "None", py::arg("SW"), py::arg("ent"));

// Enums

}