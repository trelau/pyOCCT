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
#include <TColQuantity_Array2OfLength.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array2.hxx>
#include <TColQuantity_HArray2OfLength.hxx>
#include <Standard_Type.hxx>

void bind_TColQuantity_HArray2OfLength(py::module &mod){

py::class_<TColQuantity_HArray2OfLength, opencascade::handle<TColQuantity_HArray2OfLength>, Standard_Transient> cls_TColQuantity_HArray2OfLength(mod, "TColQuantity_HArray2OfLength", "None", py::multiple_inheritance());

// Constructors
cls_TColQuantity_HArray2OfLength.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_TColQuantity_HArray2OfLength.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColQuantity_Array2OfLength::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_TColQuantity_HArray2OfLength.def(py::init<const TColQuantity_Array2OfLength &>(), py::arg("theOther"));

// Fields

// Methods
// cls_TColQuantity_HArray2OfLength.def_static("operator new_", (void * (*)(size_t)) &TColQuantity_HArray2OfLength::operator new, "None", py::arg("theSize"));
// cls_TColQuantity_HArray2OfLength.def_static("operator delete_", (void (*)(void *)) &TColQuantity_HArray2OfLength::operator delete, "None", py::arg("theAddress"));
// cls_TColQuantity_HArray2OfLength.def_static("operator new[]_", (void * (*)(size_t)) &TColQuantity_HArray2OfLength::operator new[], "None", py::arg("theSize"));
// cls_TColQuantity_HArray2OfLength.def_static("operator delete[]_", (void (*)(void *)) &TColQuantity_HArray2OfLength::operator delete[], "None", py::arg("theAddress"));
// cls_TColQuantity_HArray2OfLength.def_static("operator new_", (void * (*)(size_t, void *)) &TColQuantity_HArray2OfLength::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColQuantity_HArray2OfLength.def_static("operator delete_", (void (*)(void *, void *)) &TColQuantity_HArray2OfLength::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColQuantity_HArray2OfLength.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColQuantity_HArray2OfLength::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColQuantity_HArray2OfLength.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColQuantity_HArray2OfLength::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColQuantity_HArray2OfLength.def("Array2", (const TColQuantity_Array2OfLength & (TColQuantity_HArray2OfLength::*)() const) &TColQuantity_HArray2OfLength::Array2, "None");
cls_TColQuantity_HArray2OfLength.def("ChangeArray2", (TColQuantity_Array2OfLength & (TColQuantity_HArray2OfLength::*)()) &TColQuantity_HArray2OfLength::ChangeArray2, "None");
cls_TColQuantity_HArray2OfLength.def_static("get_type_name_", (const char * (*)()) &TColQuantity_HArray2OfLength::get_type_name, "None");
cls_TColQuantity_HArray2OfLength.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColQuantity_HArray2OfLength::get_type_descriptor, "None");
cls_TColQuantity_HArray2OfLength.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColQuantity_HArray2OfLength::*)() const) &TColQuantity_HArray2OfLength::DynamicType, "None");

// Enums

}