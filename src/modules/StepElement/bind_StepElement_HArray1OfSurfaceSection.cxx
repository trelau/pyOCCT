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
#include <StepElement_Array1OfSurfaceSection.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <StepElement_HArray1OfSurfaceSection.hxx>
#include <Standard_Type.hxx>

void bind_StepElement_HArray1OfSurfaceSection(py::module &mod){

py::class_<StepElement_HArray1OfSurfaceSection, opencascade::handle<StepElement_HArray1OfSurfaceSection>, Standard_Transient> cls_StepElement_HArray1OfSurfaceSection(mod, "StepElement_HArray1OfSurfaceSection", "None", py::multiple_inheritance());

// Constructors
cls_StepElement_HArray1OfSurfaceSection.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StepElement_HArray1OfSurfaceSection.def(py::init<const Standard_Integer, const Standard_Integer, const StepElement_Array1OfSurfaceSection::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StepElement_HArray1OfSurfaceSection.def(py::init<const StepElement_Array1OfSurfaceSection &>(), py::arg("theOther"));

// Fields

// Methods
// cls_StepElement_HArray1OfSurfaceSection.def_static("operator new_", (void * (*)(size_t)) &StepElement_HArray1OfSurfaceSection::operator new, "None", py::arg("theSize"));
// cls_StepElement_HArray1OfSurfaceSection.def_static("operator delete_", (void (*)(void *)) &StepElement_HArray1OfSurfaceSection::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_HArray1OfSurfaceSection.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_HArray1OfSurfaceSection::operator new[], "None", py::arg("theSize"));
// cls_StepElement_HArray1OfSurfaceSection.def_static("operator delete[]_", (void (*)(void *)) &StepElement_HArray1OfSurfaceSection::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_HArray1OfSurfaceSection.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_HArray1OfSurfaceSection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_HArray1OfSurfaceSection.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_HArray1OfSurfaceSection::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepElement_HArray1OfSurfaceSection.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray1OfSurfaceSection::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepElement_HArray1OfSurfaceSection.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray1OfSurfaceSection::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepElement_HArray1OfSurfaceSection.def("Array1", (const StepElement_Array1OfSurfaceSection & (StepElement_HArray1OfSurfaceSection::*)() const) &StepElement_HArray1OfSurfaceSection::Array1, "None");
cls_StepElement_HArray1OfSurfaceSection.def("ChangeArray1", (StepElement_Array1OfSurfaceSection & (StepElement_HArray1OfSurfaceSection::*)()) &StepElement_HArray1OfSurfaceSection::ChangeArray1, "None");
cls_StepElement_HArray1OfSurfaceSection.def_static("get_type_name_", (const char * (*)()) &StepElement_HArray1OfSurfaceSection::get_type_name, "None");
cls_StepElement_HArray1OfSurfaceSection.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_HArray1OfSurfaceSection::get_type_descriptor, "None");
cls_StepElement_HArray1OfSurfaceSection.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_HArray1OfSurfaceSection::*)() const) &StepElement_HArray1OfSurfaceSection::DynamicType, "None");

// Enums

}