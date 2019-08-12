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
#include <StepData_FieldList.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <StepData_Field.hxx>
#include <StepData_Array1OfField.hxx>
#include <StepData_FieldListN.hxx>

void bind_StepData_FieldListN(py::module &mod){

py::class_<StepData_FieldListN, std::unique_ptr<StepData_FieldListN, Deleter<StepData_FieldListN>>, StepData_FieldList> cls_StepData_FieldListN(mod, "StepData_FieldListN", "Describes a list of fields, in a general way This basic class is for a null size list Subclasses are for 1, N (fixed) or Dynamic sizes");

// Constructors
cls_StepData_FieldListN.def(py::init<const Standard_Integer>(), py::arg("nb"));

// Fields

// Methods
// cls_StepData_FieldListN.def_static("operator new_", (void * (*)(size_t)) &StepData_FieldListN::operator new, "None", py::arg("theSize"));
// cls_StepData_FieldListN.def_static("operator delete_", (void (*)(void *)) &StepData_FieldListN::operator delete, "None", py::arg("theAddress"));
// cls_StepData_FieldListN.def_static("operator new[]_", (void * (*)(size_t)) &StepData_FieldListN::operator new[], "None", py::arg("theSize"));
// cls_StepData_FieldListN.def_static("operator delete[]_", (void (*)(void *)) &StepData_FieldListN::operator delete[], "None", py::arg("theAddress"));
// cls_StepData_FieldListN.def_static("operator new_", (void * (*)(size_t, void *)) &StepData_FieldListN::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepData_FieldListN.def_static("operator delete_", (void (*)(void *, void *)) &StepData_FieldListN::operator delete, "None", py::arg(""), py::arg(""));
cls_StepData_FieldListN.def("NbFields", (Standard_Integer (StepData_FieldListN::*)() const) &StepData_FieldListN::NbFields, "Returns the count of fields. Here, returns starting <nb>");
cls_StepData_FieldListN.def("Field", (const StepData_Field & (StepData_FieldListN::*)(const Standard_Integer) const) &StepData_FieldListN::Field, "Returns the field n0 <num> between 1 and NbFields (read only)", py::arg("num"));
cls_StepData_FieldListN.def("CField", (StepData_Field & (StepData_FieldListN::*)(const Standard_Integer)) &StepData_FieldListN::CField, "Returns the field n0 <num> between 1 and NbFields, in order to modify its content", py::arg("num"));

// Enums

}