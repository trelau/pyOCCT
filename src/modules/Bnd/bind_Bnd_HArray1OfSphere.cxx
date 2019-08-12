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
#include <Bnd_Array1OfSphere.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <Bnd_HArray1OfSphere.hxx>
#include <Standard_Type.hxx>

void bind_Bnd_HArray1OfSphere(py::module &mod){

py::class_<Bnd_HArray1OfSphere, opencascade::handle<Bnd_HArray1OfSphere>, Standard_Transient> cls_Bnd_HArray1OfSphere(mod, "Bnd_HArray1OfSphere", "None", py::multiple_inheritance());

// Constructors
cls_Bnd_HArray1OfSphere.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_Bnd_HArray1OfSphere.def(py::init<const Standard_Integer, const Standard_Integer, const Bnd_Array1OfSphere::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_Bnd_HArray1OfSphere.def(py::init<const Bnd_Array1OfSphere &>(), py::arg("theOther"));

// Fields

// Methods
// cls_Bnd_HArray1OfSphere.def_static("operator new_", (void * (*)(size_t)) &Bnd_HArray1OfSphere::operator new, "None", py::arg("theSize"));
// cls_Bnd_HArray1OfSphere.def_static("operator delete_", (void (*)(void *)) &Bnd_HArray1OfSphere::operator delete, "None", py::arg("theAddress"));
// cls_Bnd_HArray1OfSphere.def_static("operator new[]_", (void * (*)(size_t)) &Bnd_HArray1OfSphere::operator new[], "None", py::arg("theSize"));
// cls_Bnd_HArray1OfSphere.def_static("operator delete[]_", (void (*)(void *)) &Bnd_HArray1OfSphere::operator delete[], "None", py::arg("theAddress"));
// cls_Bnd_HArray1OfSphere.def_static("operator new_", (void * (*)(size_t, void *)) &Bnd_HArray1OfSphere::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Bnd_HArray1OfSphere.def_static("operator delete_", (void (*)(void *, void *)) &Bnd_HArray1OfSphere::operator delete, "None", py::arg(""), py::arg(""));
// cls_Bnd_HArray1OfSphere.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Bnd_HArray1OfSphere::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Bnd_HArray1OfSphere.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Bnd_HArray1OfSphere::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Bnd_HArray1OfSphere.def("Array1", (const Bnd_Array1OfSphere & (Bnd_HArray1OfSphere::*)() const) &Bnd_HArray1OfSphere::Array1, "None");
cls_Bnd_HArray1OfSphere.def("ChangeArray1", (Bnd_Array1OfSphere & (Bnd_HArray1OfSphere::*)()) &Bnd_HArray1OfSphere::ChangeArray1, "None");
cls_Bnd_HArray1OfSphere.def_static("get_type_name_", (const char * (*)()) &Bnd_HArray1OfSphere::get_type_name, "None");
cls_Bnd_HArray1OfSphere.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Bnd_HArray1OfSphere::get_type_descriptor, "None");
cls_Bnd_HArray1OfSphere.def("DynamicType", (const opencascade::handle<Standard_Type> & (Bnd_HArray1OfSphere::*)() const) &Bnd_HArray1OfSphere::DynamicType, "None");

// Enums

}