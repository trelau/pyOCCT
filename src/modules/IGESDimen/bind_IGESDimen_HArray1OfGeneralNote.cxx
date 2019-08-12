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
#include <IGESDimen_Array1OfGeneralNote.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <IGESDimen_HArray1OfGeneralNote.hxx>
#include <Standard_Type.hxx>

void bind_IGESDimen_HArray1OfGeneralNote(py::module &mod){

py::class_<IGESDimen_HArray1OfGeneralNote, opencascade::handle<IGESDimen_HArray1OfGeneralNote>, Standard_Transient> cls_IGESDimen_HArray1OfGeneralNote(mod, "IGESDimen_HArray1OfGeneralNote", "None", py::multiple_inheritance());

// Constructors
cls_IGESDimen_HArray1OfGeneralNote.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_IGESDimen_HArray1OfGeneralNote.def(py::init<const Standard_Integer, const Standard_Integer, const IGESDimen_Array1OfGeneralNote::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_IGESDimen_HArray1OfGeneralNote.def(py::init<const IGESDimen_Array1OfGeneralNote &>(), py::arg("theOther"));

// Fields

// Methods
// cls_IGESDimen_HArray1OfGeneralNote.def_static("operator new_", (void * (*)(size_t)) &IGESDimen_HArray1OfGeneralNote::operator new, "None", py::arg("theSize"));
// cls_IGESDimen_HArray1OfGeneralNote.def_static("operator delete_", (void (*)(void *)) &IGESDimen_HArray1OfGeneralNote::operator delete, "None", py::arg("theAddress"));
// cls_IGESDimen_HArray1OfGeneralNote.def_static("operator new[]_", (void * (*)(size_t)) &IGESDimen_HArray1OfGeneralNote::operator new[], "None", py::arg("theSize"));
// cls_IGESDimen_HArray1OfGeneralNote.def_static("operator delete[]_", (void (*)(void *)) &IGESDimen_HArray1OfGeneralNote::operator delete[], "None", py::arg("theAddress"));
// cls_IGESDimen_HArray1OfGeneralNote.def_static("operator new_", (void * (*)(size_t, void *)) &IGESDimen_HArray1OfGeneralNote::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESDimen_HArray1OfGeneralNote.def_static("operator delete_", (void (*)(void *, void *)) &IGESDimen_HArray1OfGeneralNote::operator delete, "None", py::arg(""), py::arg(""));
// cls_IGESDimen_HArray1OfGeneralNote.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &IGESDimen_HArray1OfGeneralNote::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_IGESDimen_HArray1OfGeneralNote.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &IGESDimen_HArray1OfGeneralNote::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_IGESDimen_HArray1OfGeneralNote.def("Array1", (const IGESDimen_Array1OfGeneralNote & (IGESDimen_HArray1OfGeneralNote::*)() const) &IGESDimen_HArray1OfGeneralNote::Array1, "None");
cls_IGESDimen_HArray1OfGeneralNote.def("ChangeArray1", (IGESDimen_Array1OfGeneralNote & (IGESDimen_HArray1OfGeneralNote::*)()) &IGESDimen_HArray1OfGeneralNote::ChangeArray1, "None");
cls_IGESDimen_HArray1OfGeneralNote.def_static("get_type_name_", (const char * (*)()) &IGESDimen_HArray1OfGeneralNote::get_type_name, "None");
cls_IGESDimen_HArray1OfGeneralNote.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_HArray1OfGeneralNote::get_type_descriptor, "None");
cls_IGESDimen_HArray1OfGeneralNote.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_HArray1OfGeneralNote::*)() const) &IGESDimen_HArray1OfGeneralNote::DynamicType, "None");

// Enums

}