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
#include <StepBasic_Array1OfProductContext.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <StepBasic_HArray1OfProductContext.hxx>
#include <Standard_Type.hxx>

void bind_StepBasic_HArray1OfProductContext(py::module &mod){

py::class_<StepBasic_HArray1OfProductContext, opencascade::handle<StepBasic_HArray1OfProductContext>, Standard_Transient> cls_StepBasic_HArray1OfProductContext(mod, "StepBasic_HArray1OfProductContext", "None", py::multiple_inheritance());

// Constructors
cls_StepBasic_HArray1OfProductContext.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StepBasic_HArray1OfProductContext.def(py::init<const Standard_Integer, const Standard_Integer, const StepBasic_Array1OfProductContext::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StepBasic_HArray1OfProductContext.def(py::init<const StepBasic_Array1OfProductContext &>(), py::arg("theOther"));

// Fields

// Methods
// cls_StepBasic_HArray1OfProductContext.def_static("operator new_", (void * (*)(size_t)) &StepBasic_HArray1OfProductContext::operator new, "None", py::arg("theSize"));
// cls_StepBasic_HArray1OfProductContext.def_static("operator delete_", (void (*)(void *)) &StepBasic_HArray1OfProductContext::operator delete, "None", py::arg("theAddress"));
// cls_StepBasic_HArray1OfProductContext.def_static("operator new[]_", (void * (*)(size_t)) &StepBasic_HArray1OfProductContext::operator new[], "None", py::arg("theSize"));
// cls_StepBasic_HArray1OfProductContext.def_static("operator delete[]_", (void (*)(void *)) &StepBasic_HArray1OfProductContext::operator delete[], "None", py::arg("theAddress"));
// cls_StepBasic_HArray1OfProductContext.def_static("operator new_", (void * (*)(size_t, void *)) &StepBasic_HArray1OfProductContext::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepBasic_HArray1OfProductContext.def_static("operator delete_", (void (*)(void *, void *)) &StepBasic_HArray1OfProductContext::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepBasic_HArray1OfProductContext.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepBasic_HArray1OfProductContext::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepBasic_HArray1OfProductContext.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepBasic_HArray1OfProductContext::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepBasic_HArray1OfProductContext.def("Array1", (const StepBasic_Array1OfProductContext & (StepBasic_HArray1OfProductContext::*)() const) &StepBasic_HArray1OfProductContext::Array1, "None");
cls_StepBasic_HArray1OfProductContext.def("ChangeArray1", (StepBasic_Array1OfProductContext & (StepBasic_HArray1OfProductContext::*)()) &StepBasic_HArray1OfProductContext::ChangeArray1, "None");
cls_StepBasic_HArray1OfProductContext.def_static("get_type_name_", (const char * (*)()) &StepBasic_HArray1OfProductContext::get_type_name, "None");
cls_StepBasic_HArray1OfProductContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepBasic_HArray1OfProductContext::get_type_descriptor, "None");
cls_StepBasic_HArray1OfProductContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepBasic_HArray1OfProductContext::*)() const) &StepBasic_HArray1OfProductContext::DynamicType, "None");

// Enums

}