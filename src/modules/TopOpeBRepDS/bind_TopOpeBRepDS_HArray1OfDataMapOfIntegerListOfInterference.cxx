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
#include <TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.hxx>
#include <Standard_Type.hxx>

void bind_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference(py::module &mod){

py::class_<TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference, opencascade::handle<TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference>, Standard_Transient> cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference(mod, "TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference", "None", py::multiple_inheritance());

// Constructors
cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def(py::init<const Standard_Integer, const Standard_Integer, const TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def(py::init<const TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference &>(), py::arg("theOther"));

// Fields

// Methods
// cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::operator delete, "None", py::arg(""), py::arg(""));
// cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def("Array1", (const TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference & (TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::*)() const) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::Array1, "None");
cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def("ChangeArray1", (TopOpeBRepDS_Array1OfDataMapOfIntegerListOfInterference & (TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::*)()) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::ChangeArray1, "None");
cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::get_type_name, "None");
cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::get_type_descriptor, "None");
cls_TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::*)() const) &TopOpeBRepDS_HArray1OfDataMapOfIntegerListOfInterference::DynamicType, "None");

// Enums

}