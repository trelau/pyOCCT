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
#include <StepElement_Array1OfHSequenceOfCurveElementPurposeMember.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.hxx>
#include <Standard_Type.hxx>

void bind_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember(py::module &mod){

py::class_<StepElement_HArray1OfHSequenceOfCurveElementPurposeMember, opencascade::handle<StepElement_HArray1OfHSequenceOfCurveElementPurposeMember>, Standard_Transient> cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember(mod, "StepElement_HArray1OfHSequenceOfCurveElementPurposeMember", "None", py::multiple_inheritance());

// Constructors
cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def(py::init<const Standard_Integer, const Standard_Integer, const StepElement_Array1OfHSequenceOfCurveElementPurposeMember::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def(py::init<const StepElement_Array1OfHSequenceOfCurveElementPurposeMember &>(), py::arg("theOther"));

// Fields

// Methods
// cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def_static("operator new_", (void * (*)(size_t)) &StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::operator new, "None", py::arg("theSize"));
// cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def_static("operator delete_", (void (*)(void *)) &StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::operator new[], "None", py::arg("theSize"));
// cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def_static("operator delete[]_", (void (*)(void *)) &StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def("Array1", (const StepElement_Array1OfHSequenceOfCurveElementPurposeMember & (StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::*)() const) &StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::Array1, "None");
cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def("ChangeArray1", (StepElement_Array1OfHSequenceOfCurveElementPurposeMember & (StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::*)()) &StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::ChangeArray1, "None");
cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def_static("get_type_name_", (const char * (*)()) &StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::get_type_name, "None");
cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::get_type_descriptor, "None");
cls_StepElement_HArray1OfHSequenceOfCurveElementPurposeMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::*)() const) &StepElement_HArray1OfHSequenceOfCurveElementPurposeMember::DynamicType, "None");

// Enums

}