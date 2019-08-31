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
#include <NCollection_Array1.hxx>
#include <Quantity_Length.hxx>
#include <TColQuantity_Array1OfLength.hxx>
#include <NCollection_Array2.hxx>
#include <TColQuantity_Array2OfLength.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <TColQuantity_HArray1OfLength.hxx>
#include <Standard_Type.hxx>
#include <TColQuantity_HArray2OfLength.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_NCollection_Array2.hxx>

PYBIND11_MODULE(TColQuantity, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.Standard");

// TYPEDEF: TCOLQUANTITY_ARRAY1OFLENGTH
bind_NCollection_Array1<double>(mod, "TColQuantity_Array1OfLength", py::module_local());

// TYPEDEF: TCOLQUANTITY_ARRAY2OFLENGTH
bind_NCollection_Array2<double>(mod, "TColQuantity_Array2OfLength", py::module_local());

// CLASS: TCOLQUANTITY_HARRAY1OFLENGTH
py::class_<TColQuantity_HArray1OfLength, opencascade::handle<TColQuantity_HArray1OfLength>, Standard_Transient> cls_TColQuantity_HArray1OfLength(mod, "TColQuantity_HArray1OfLength", "None", py::multiple_inheritance());

// Constructors
cls_TColQuantity_HArray1OfLength.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TColQuantity_HArray1OfLength.def(py::init<const Standard_Integer, const Standard_Integer, const TColQuantity_Array1OfLength::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TColQuantity_HArray1OfLength.def(py::init<const TColQuantity_Array1OfLength &>(), py::arg("theOther"));

// Methods
// cls_TColQuantity_HArray1OfLength.def_static("operator new_", (void * (*)(size_t)) &TColQuantity_HArray1OfLength::operator new, "None", py::arg("theSize"));
// cls_TColQuantity_HArray1OfLength.def_static("operator delete_", (void (*)(void *)) &TColQuantity_HArray1OfLength::operator delete, "None", py::arg("theAddress"));
// cls_TColQuantity_HArray1OfLength.def_static("operator new[]_", (void * (*)(size_t)) &TColQuantity_HArray1OfLength::operator new[], "None", py::arg("theSize"));
// cls_TColQuantity_HArray1OfLength.def_static("operator delete[]_", (void (*)(void *)) &TColQuantity_HArray1OfLength::operator delete[], "None", py::arg("theAddress"));
// cls_TColQuantity_HArray1OfLength.def_static("operator new_", (void * (*)(size_t, void *)) &TColQuantity_HArray1OfLength::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColQuantity_HArray1OfLength.def_static("operator delete_", (void (*)(void *, void *)) &TColQuantity_HArray1OfLength::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColQuantity_HArray1OfLength.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColQuantity_HArray1OfLength::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColQuantity_HArray1OfLength.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColQuantity_HArray1OfLength::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColQuantity_HArray1OfLength.def("Array1", (const TColQuantity_Array1OfLength & (TColQuantity_HArray1OfLength::*)() const) &TColQuantity_HArray1OfLength::Array1, "None");
cls_TColQuantity_HArray1OfLength.def("ChangeArray1", (TColQuantity_Array1OfLength & (TColQuantity_HArray1OfLength::*)()) &TColQuantity_HArray1OfLength::ChangeArray1, "None");
cls_TColQuantity_HArray1OfLength.def_static("get_type_name_", (const char * (*)()) &TColQuantity_HArray1OfLength::get_type_name, "None");
cls_TColQuantity_HArray1OfLength.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColQuantity_HArray1OfLength::get_type_descriptor, "None");
cls_TColQuantity_HArray1OfLength.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColQuantity_HArray1OfLength::*)() const) &TColQuantity_HArray1OfLength::DynamicType, "None");

// CLASS: TCOLQUANTITY_HARRAY2OFLENGTH
py::class_<TColQuantity_HArray2OfLength, opencascade::handle<TColQuantity_HArray2OfLength>, Standard_Transient> cls_TColQuantity_HArray2OfLength(mod, "TColQuantity_HArray2OfLength", "None", py::multiple_inheritance());

// Constructors
cls_TColQuantity_HArray2OfLength.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_TColQuantity_HArray2OfLength.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColQuantity_Array2OfLength::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_TColQuantity_HArray2OfLength.def(py::init<const TColQuantity_Array2OfLength &>(), py::arg("theOther"));

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


}
