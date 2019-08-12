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
#include <StepData_Array1OfField.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <StepData_HArray1OfField.hxx>
#include <Standard_Type.hxx>

void bind_StepData_HArray1OfField(py::module &mod){

py::class_<StepData_HArray1OfField, opencascade::handle<StepData_HArray1OfField>, Standard_Transient> cls_StepData_HArray1OfField(mod, "StepData_HArray1OfField", "None", py::multiple_inheritance());

// Constructors
cls_StepData_HArray1OfField.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StepData_HArray1OfField.def(py::init<const Standard_Integer, const Standard_Integer, const StepData_Array1OfField::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StepData_HArray1OfField.def(py::init<const StepData_Array1OfField &>(), py::arg("theOther"));

// Fields

// Methods
// cls_StepData_HArray1OfField.def_static("operator new_", (void * (*)(size_t)) &StepData_HArray1OfField::operator new, "None", py::arg("theSize"));
// cls_StepData_HArray1OfField.def_static("operator delete_", (void (*)(void *)) &StepData_HArray1OfField::operator delete, "None", py::arg("theAddress"));
// cls_StepData_HArray1OfField.def_static("operator new[]_", (void * (*)(size_t)) &StepData_HArray1OfField::operator new[], "None", py::arg("theSize"));
// cls_StepData_HArray1OfField.def_static("operator delete[]_", (void (*)(void *)) &StepData_HArray1OfField::operator delete[], "None", py::arg("theAddress"));
// cls_StepData_HArray1OfField.def_static("operator new_", (void * (*)(size_t, void *)) &StepData_HArray1OfField::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepData_HArray1OfField.def_static("operator delete_", (void (*)(void *, void *)) &StepData_HArray1OfField::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepData_HArray1OfField.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepData_HArray1OfField::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepData_HArray1OfField.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepData_HArray1OfField::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepData_HArray1OfField.def("Array1", (const StepData_Array1OfField & (StepData_HArray1OfField::*)() const) &StepData_HArray1OfField::Array1, "None");
cls_StepData_HArray1OfField.def("ChangeArray1", (StepData_Array1OfField & (StepData_HArray1OfField::*)()) &StepData_HArray1OfField::ChangeArray1, "None");
cls_StepData_HArray1OfField.def_static("get_type_name_", (const char * (*)()) &StepData_HArray1OfField::get_type_name, "None");
cls_StepData_HArray1OfField.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepData_HArray1OfField::get_type_descriptor, "None");
cls_StepData_HArray1OfField.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepData_HArray1OfField::*)() const) &StepData_HArray1OfField::DynamicType, "None");

// Enums

}