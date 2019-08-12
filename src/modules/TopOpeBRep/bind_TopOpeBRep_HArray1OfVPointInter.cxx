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
#include <TopOpeBRep_Array1OfVPointInter.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <TopOpeBRep_HArray1OfVPointInter.hxx>
#include <Standard_Type.hxx>

void bind_TopOpeBRep_HArray1OfVPointInter(py::module &mod){

py::class_<TopOpeBRep_HArray1OfVPointInter, opencascade::handle<TopOpeBRep_HArray1OfVPointInter>, Standard_Transient> cls_TopOpeBRep_HArray1OfVPointInter(mod, "TopOpeBRep_HArray1OfVPointInter", "None", py::multiple_inheritance());

// Constructors
cls_TopOpeBRep_HArray1OfVPointInter.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TopOpeBRep_HArray1OfVPointInter.def(py::init<const Standard_Integer, const Standard_Integer, const TopOpeBRep_Array1OfVPointInter::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TopOpeBRep_HArray1OfVPointInter.def(py::init<const TopOpeBRep_Array1OfVPointInter &>(), py::arg("theOther"));

// Fields

// Methods
// cls_TopOpeBRep_HArray1OfVPointInter.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRep_HArray1OfVPointInter::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRep_HArray1OfVPointInter.def_static("operator delete_", (void (*)(void *)) &TopOpeBRep_HArray1OfVPointInter::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRep_HArray1OfVPointInter.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRep_HArray1OfVPointInter::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRep_HArray1OfVPointInter.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRep_HArray1OfVPointInter::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRep_HArray1OfVPointInter.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRep_HArray1OfVPointInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRep_HArray1OfVPointInter.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRep_HArray1OfVPointInter::operator delete, "None", py::arg(""), py::arg(""));
// cls_TopOpeBRep_HArray1OfVPointInter.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRep_HArray1OfVPointInter::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TopOpeBRep_HArray1OfVPointInter.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TopOpeBRep_HArray1OfVPointInter::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TopOpeBRep_HArray1OfVPointInter.def("Array1", (const TopOpeBRep_Array1OfVPointInter & (TopOpeBRep_HArray1OfVPointInter::*)() const) &TopOpeBRep_HArray1OfVPointInter::Array1, "None");
cls_TopOpeBRep_HArray1OfVPointInter.def("ChangeArray1", (TopOpeBRep_Array1OfVPointInter & (TopOpeBRep_HArray1OfVPointInter::*)()) &TopOpeBRep_HArray1OfVPointInter::ChangeArray1, "None");
cls_TopOpeBRep_HArray1OfVPointInter.def_static("get_type_name_", (const char * (*)()) &TopOpeBRep_HArray1OfVPointInter::get_type_name, "None");
cls_TopOpeBRep_HArray1OfVPointInter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRep_HArray1OfVPointInter::get_type_descriptor, "None");
cls_TopOpeBRep_HArray1OfVPointInter.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRep_HArray1OfVPointInter::*)() const) &TopOpeBRep_HArray1OfVPointInter::DynamicType, "None");

// Enums

}