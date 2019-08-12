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
#include <TColgp_Array1OfDir.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <TColgp_HArray1OfDir.hxx>
#include <Standard_Type.hxx>

void bind_TColgp_HArray1OfDir(py::module &mod){

py::class_<TColgp_HArray1OfDir, opencascade::handle<TColgp_HArray1OfDir>, Standard_Transient> cls_TColgp_HArray1OfDir(mod, "TColgp_HArray1OfDir", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HArray1OfDir.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TColgp_HArray1OfDir.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfDir::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TColgp_HArray1OfDir.def(py::init<const TColgp_Array1OfDir &>(), py::arg("theOther"));

// Fields

// Methods
// cls_TColgp_HArray1OfDir.def_static("operator new_", (void * (*)(size_t)) &TColgp_HArray1OfDir::operator new, "None", py::arg("theSize"));
// cls_TColgp_HArray1OfDir.def_static("operator delete_", (void (*)(void *)) &TColgp_HArray1OfDir::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HArray1OfDir.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HArray1OfDir::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HArray1OfDir.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HArray1OfDir::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HArray1OfDir.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HArray1OfDir::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HArray1OfDir.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HArray1OfDir::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HArray1OfDir.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray1OfDir::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HArray1OfDir.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray1OfDir::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HArray1OfDir.def("Array1", (const TColgp_Array1OfDir & (TColgp_HArray1OfDir::*)() const) &TColgp_HArray1OfDir::Array1, "None");
cls_TColgp_HArray1OfDir.def("ChangeArray1", (TColgp_Array1OfDir & (TColgp_HArray1OfDir::*)()) &TColgp_HArray1OfDir::ChangeArray1, "None");
cls_TColgp_HArray1OfDir.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfDir::get_type_name, "None");
cls_TColgp_HArray1OfDir.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfDir::get_type_descriptor, "None");
cls_TColgp_HArray1OfDir.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfDir::*)() const) &TColgp_HArray1OfDir::DynamicType, "None");

// Enums

}