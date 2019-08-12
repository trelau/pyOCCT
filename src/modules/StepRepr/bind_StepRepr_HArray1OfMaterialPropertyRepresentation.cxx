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
#include <StepRepr_Array1OfMaterialPropertyRepresentation.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <StepRepr_HArray1OfMaterialPropertyRepresentation.hxx>
#include <Standard_Type.hxx>

void bind_StepRepr_HArray1OfMaterialPropertyRepresentation(py::module &mod){

py::class_<StepRepr_HArray1OfMaterialPropertyRepresentation, opencascade::handle<StepRepr_HArray1OfMaterialPropertyRepresentation>, Standard_Transient> cls_StepRepr_HArray1OfMaterialPropertyRepresentation(mod, "StepRepr_HArray1OfMaterialPropertyRepresentation", "None", py::multiple_inheritance());

// Constructors
cls_StepRepr_HArray1OfMaterialPropertyRepresentation.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StepRepr_HArray1OfMaterialPropertyRepresentation.def(py::init<const Standard_Integer, const Standard_Integer, const StepRepr_Array1OfMaterialPropertyRepresentation::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StepRepr_HArray1OfMaterialPropertyRepresentation.def(py::init<const StepRepr_Array1OfMaterialPropertyRepresentation &>(), py::arg("theOther"));

// Fields

// Methods
// cls_StepRepr_HArray1OfMaterialPropertyRepresentation.def_static("operator new_", (void * (*)(size_t)) &StepRepr_HArray1OfMaterialPropertyRepresentation::operator new, "None", py::arg("theSize"));
// cls_StepRepr_HArray1OfMaterialPropertyRepresentation.def_static("operator delete_", (void (*)(void *)) &StepRepr_HArray1OfMaterialPropertyRepresentation::operator delete, "None", py::arg("theAddress"));
// cls_StepRepr_HArray1OfMaterialPropertyRepresentation.def_static("operator new[]_", (void * (*)(size_t)) &StepRepr_HArray1OfMaterialPropertyRepresentation::operator new[], "None", py::arg("theSize"));
// cls_StepRepr_HArray1OfMaterialPropertyRepresentation.def_static("operator delete[]_", (void (*)(void *)) &StepRepr_HArray1OfMaterialPropertyRepresentation::operator delete[], "None", py::arg("theAddress"));
// cls_StepRepr_HArray1OfMaterialPropertyRepresentation.def_static("operator new_", (void * (*)(size_t, void *)) &StepRepr_HArray1OfMaterialPropertyRepresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepRepr_HArray1OfMaterialPropertyRepresentation.def_static("operator delete_", (void (*)(void *, void *)) &StepRepr_HArray1OfMaterialPropertyRepresentation::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepRepr_HArray1OfMaterialPropertyRepresentation.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepRepr_HArray1OfMaterialPropertyRepresentation::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepRepr_HArray1OfMaterialPropertyRepresentation.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepRepr_HArray1OfMaterialPropertyRepresentation::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepRepr_HArray1OfMaterialPropertyRepresentation.def("Array1", (const StepRepr_Array1OfMaterialPropertyRepresentation & (StepRepr_HArray1OfMaterialPropertyRepresentation::*)() const) &StepRepr_HArray1OfMaterialPropertyRepresentation::Array1, "None");
cls_StepRepr_HArray1OfMaterialPropertyRepresentation.def("ChangeArray1", (StepRepr_Array1OfMaterialPropertyRepresentation & (StepRepr_HArray1OfMaterialPropertyRepresentation::*)()) &StepRepr_HArray1OfMaterialPropertyRepresentation::ChangeArray1, "None");
cls_StepRepr_HArray1OfMaterialPropertyRepresentation.def_static("get_type_name_", (const char * (*)()) &StepRepr_HArray1OfMaterialPropertyRepresentation::get_type_name, "None");
cls_StepRepr_HArray1OfMaterialPropertyRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_HArray1OfMaterialPropertyRepresentation::get_type_descriptor, "None");
cls_StepRepr_HArray1OfMaterialPropertyRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_HArray1OfMaterialPropertyRepresentation::*)() const) &StepRepr_HArray1OfMaterialPropertyRepresentation::DynamicType, "None");

// Enums

}