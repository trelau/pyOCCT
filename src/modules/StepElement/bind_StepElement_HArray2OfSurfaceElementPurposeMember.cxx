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
#include <StepElement_Array2OfSurfaceElementPurposeMember.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array2.hxx>
#include <StepElement_HArray2OfSurfaceElementPurposeMember.hxx>
#include <Standard_Type.hxx>

void bind_StepElement_HArray2OfSurfaceElementPurposeMember(py::module &mod){

py::class_<StepElement_HArray2OfSurfaceElementPurposeMember, opencascade::handle<StepElement_HArray2OfSurfaceElementPurposeMember>, Standard_Transient> cls_StepElement_HArray2OfSurfaceElementPurposeMember(mod, "StepElement_HArray2OfSurfaceElementPurposeMember", "None", py::multiple_inheritance());

// Constructors
cls_StepElement_HArray2OfSurfaceElementPurposeMember.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_StepElement_HArray2OfSurfaceElementPurposeMember.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const StepElement_Array2OfSurfaceElementPurposeMember::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_StepElement_HArray2OfSurfaceElementPurposeMember.def(py::init<const StepElement_Array2OfSurfaceElementPurposeMember &>(), py::arg("theOther"));

// Fields

// Methods
// cls_StepElement_HArray2OfSurfaceElementPurposeMember.def_static("operator new_", (void * (*)(size_t)) &StepElement_HArray2OfSurfaceElementPurposeMember::operator new, "None", py::arg("theSize"));
// cls_StepElement_HArray2OfSurfaceElementPurposeMember.def_static("operator delete_", (void (*)(void *)) &StepElement_HArray2OfSurfaceElementPurposeMember::operator delete, "None", py::arg("theAddress"));
// cls_StepElement_HArray2OfSurfaceElementPurposeMember.def_static("operator new[]_", (void * (*)(size_t)) &StepElement_HArray2OfSurfaceElementPurposeMember::operator new[], "None", py::arg("theSize"));
// cls_StepElement_HArray2OfSurfaceElementPurposeMember.def_static("operator delete[]_", (void (*)(void *)) &StepElement_HArray2OfSurfaceElementPurposeMember::operator delete[], "None", py::arg("theAddress"));
// cls_StepElement_HArray2OfSurfaceElementPurposeMember.def_static("operator new_", (void * (*)(size_t, void *)) &StepElement_HArray2OfSurfaceElementPurposeMember::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepElement_HArray2OfSurfaceElementPurposeMember.def_static("operator delete_", (void (*)(void *, void *)) &StepElement_HArray2OfSurfaceElementPurposeMember::operator delete, "None", py::arg(""), py::arg(""));
// cls_StepElement_HArray2OfSurfaceElementPurposeMember.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray2OfSurfaceElementPurposeMember::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_StepElement_HArray2OfSurfaceElementPurposeMember.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &StepElement_HArray2OfSurfaceElementPurposeMember::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_StepElement_HArray2OfSurfaceElementPurposeMember.def("Array2", (const StepElement_Array2OfSurfaceElementPurposeMember & (StepElement_HArray2OfSurfaceElementPurposeMember::*)() const) &StepElement_HArray2OfSurfaceElementPurposeMember::Array2, "None");
cls_StepElement_HArray2OfSurfaceElementPurposeMember.def("ChangeArray2", (StepElement_Array2OfSurfaceElementPurposeMember & (StepElement_HArray2OfSurfaceElementPurposeMember::*)()) &StepElement_HArray2OfSurfaceElementPurposeMember::ChangeArray2, "None");
cls_StepElement_HArray2OfSurfaceElementPurposeMember.def_static("get_type_name_", (const char * (*)()) &StepElement_HArray2OfSurfaceElementPurposeMember::get_type_name, "None");
cls_StepElement_HArray2OfSurfaceElementPurposeMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_HArray2OfSurfaceElementPurposeMember::get_type_descriptor, "None");
cls_StepElement_HArray2OfSurfaceElementPurposeMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_HArray2OfSurfaceElementPurposeMember::*)() const) &StepElement_HArray2OfSurfaceElementPurposeMember::DynamicType, "None");

// Enums

}