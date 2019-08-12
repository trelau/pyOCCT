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
#include <StepVisual_Array1OfDirectionCountSelect.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <StepVisual_HArray1OfDirectionCountSelect.hxx>
#include <Standard_Type.hxx>

void bind_StepVisual_HArray1OfDirectionCountSelect(py::module &mod){

py::class_<StepVisual_HArray1OfDirectionCountSelect, opencascade::handle<StepVisual_HArray1OfDirectionCountSelect>, Standard_Transient> cls_StepVisual_HArray1OfDirectionCountSelect(mod, "StepVisual_HArray1OfDirectionCountSelect", "None", py::multiple_inheritance());

// Constructors
cls_StepVisual_HArray1OfDirectionCountSelect.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StepVisual_HArray1OfDirectionCountSelect.def(py::init<const Standard_Integer, const Standard_Integer, const StepVisual_Array1OfDirectionCountSelect::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StepVisual_HArray1OfDirectionCountSelect.def(py::init<const StepVisual_Array1OfDirectionCountSelect &>(), py::arg("theOther"));

// Fields

// Methods
// cls_StepVisual_HArray1OfDirectionCountSelect.def_static("operator new_", (void * (*)(size_t)) &StepVisual_HArray1OfDirectionCountSelect::operator new, "None", py::arg("theSize"));
// cls_StepVisual_HArray1OfDirectionCountSelect.def_static("operator delete_", (void (*)(void *)) &StepVisual_HArray1OfDirectionCountSelect::operator delete, "None", py::arg("theAddress"));
// cls_StepVisual_HArray1OfDirectionCountSelect.def_static("operator new[]_", (void * (*)(size_t)) &StepVisual_HArray1OfDirectionCountSelect::operator new[], "None", py::arg("theSize"));
// cls_StepVisual_HArray1OfDirectionCountSelect.def_static("operator delete[]_", (void (*)(void *)) &StepVisual_HArray1OfDirectionCountSelect::operator delete[], "None", py::arg("theAddress"));
// cls_StepVisual_HArray1OfDirectionCountSelect.def_static("operator new_", (void * (*)(size_t, void *)) &StepVisual_HArray1OfDirectionCountSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepVisual_HArray1OfDirectionCountSelect.def_static("operator delete_", (void (*)(void *, void *)) &StepVisual_HArray1OfDirectionCountSelect::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepVisual_HArray1OfDirectionCountSelect.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepVisual_HArray1OfDirectionCountSelect::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepVisual_HArray1OfDirectionCountSelect.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepVisual_HArray1OfDirectionCountSelect::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepVisual_HArray1OfDirectionCountSelect.def("Array1", (const StepVisual_Array1OfDirectionCountSelect & (StepVisual_HArray1OfDirectionCountSelect::*)() const) &StepVisual_HArray1OfDirectionCountSelect::Array1, "None");
cls_StepVisual_HArray1OfDirectionCountSelect.def("ChangeArray1", (StepVisual_Array1OfDirectionCountSelect & (StepVisual_HArray1OfDirectionCountSelect::*)()) &StepVisual_HArray1OfDirectionCountSelect::ChangeArray1, "None");
cls_StepVisual_HArray1OfDirectionCountSelect.def_static("get_type_name_", (const char * (*)()) &StepVisual_HArray1OfDirectionCountSelect::get_type_name, "None");
cls_StepVisual_HArray1OfDirectionCountSelect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_HArray1OfDirectionCountSelect::get_type_descriptor, "None");
cls_StepVisual_HArray1OfDirectionCountSelect.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_HArray1OfDirectionCountSelect::*)() const) &StepVisual_HArray1OfDirectionCountSelect::DynamicType, "None");

// Enums

}