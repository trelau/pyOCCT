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
#include <TColStd_Array2OfReal.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array2.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <Standard_Type.hxx>

void bind_TColStd_HArray2OfReal(py::module &mod){

py::class_<TColStd_HArray2OfReal, opencascade::handle<TColStd_HArray2OfReal>, Standard_Transient> cls_TColStd_HArray2OfReal(mod, "TColStd_HArray2OfReal", "None", py::multiple_inheritance());

// Constructors
cls_TColStd_HArray2OfReal.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_TColStd_HArray2OfReal.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColStd_Array2OfReal::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_TColStd_HArray2OfReal.def(py::init<const TColStd_Array2OfReal &>(), py::arg("theOther"));

// Fields

// Methods
// cls_TColStd_HArray2OfReal.def_static("operator new_", (void * (*)(size_t)) &TColStd_HArray2OfReal::operator new, "None", py::arg("theSize"));
// cls_TColStd_HArray2OfReal.def_static("operator delete_", (void (*)(void *)) &TColStd_HArray2OfReal::operator delete, "None", py::arg("theAddress"));
// cls_TColStd_HArray2OfReal.def_static("operator new[]_", (void * (*)(size_t)) &TColStd_HArray2OfReal::operator new[], "None", py::arg("theSize"));
// cls_TColStd_HArray2OfReal.def_static("operator delete[]_", (void (*)(void *)) &TColStd_HArray2OfReal::operator delete[], "None", py::arg("theAddress"));
// cls_TColStd_HArray2OfReal.def_static("operator new_", (void * (*)(size_t, void *)) &TColStd_HArray2OfReal::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColStd_HArray2OfReal.def_static("operator delete_", (void (*)(void *, void *)) &TColStd_HArray2OfReal::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColStd_HArray2OfReal.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_HArray2OfReal::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColStd_HArray2OfReal.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColStd_HArray2OfReal::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColStd_HArray2OfReal.def("Array2", (const TColStd_Array2OfReal & (TColStd_HArray2OfReal::*)() const) &TColStd_HArray2OfReal::Array2, "None");
cls_TColStd_HArray2OfReal.def("ChangeArray2", (TColStd_Array2OfReal & (TColStd_HArray2OfReal::*)()) &TColStd_HArray2OfReal::ChangeArray2, "None");
cls_TColStd_HArray2OfReal.def_static("get_type_name_", (const char * (*)()) &TColStd_HArray2OfReal::get_type_name, "None");
cls_TColStd_HArray2OfReal.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HArray2OfReal::get_type_descriptor, "None");
cls_TColStd_HArray2OfReal.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HArray2OfReal::*)() const) &TColStd_HArray2OfReal::DynamicType, "None");

// Enums

}