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
#include <Poly_Array1OfTriangle.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <Poly_HArray1OfTriangle.hxx>
#include <Standard_Type.hxx>

void bind_Poly_HArray1OfTriangle(py::module &mod){

py::class_<Poly_HArray1OfTriangle, opencascade::handle<Poly_HArray1OfTriangle>, Standard_Transient> cls_Poly_HArray1OfTriangle(mod, "Poly_HArray1OfTriangle", "None", py::multiple_inheritance());

// Constructors
cls_Poly_HArray1OfTriangle.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_Poly_HArray1OfTriangle.def(py::init<const Standard_Integer, const Standard_Integer, const Poly_Array1OfTriangle::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_Poly_HArray1OfTriangle.def(py::init<const Poly_Array1OfTriangle &>(), py::arg("theOther"));

// Fields

// Methods
// cls_Poly_HArray1OfTriangle.def_static("operator new_", (void * (*)(size_t)) &Poly_HArray1OfTriangle::operator new, "None", py::arg("theSize"));
// cls_Poly_HArray1OfTriangle.def_static("operator delete_", (void (*)(void *)) &Poly_HArray1OfTriangle::operator delete, "None", py::arg("theAddress"));
// cls_Poly_HArray1OfTriangle.def_static("operator new[]_", (void * (*)(size_t)) &Poly_HArray1OfTriangle::operator new[], "None", py::arg("theSize"));
// cls_Poly_HArray1OfTriangle.def_static("operator delete[]_", (void (*)(void *)) &Poly_HArray1OfTriangle::operator delete[], "None", py::arg("theAddress"));
// cls_Poly_HArray1OfTriangle.def_static("operator new_", (void * (*)(size_t, void *)) &Poly_HArray1OfTriangle::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Poly_HArray1OfTriangle.def_static("operator delete_", (void (*)(void *, void *)) &Poly_HArray1OfTriangle::operator delete, "None", py::arg(""), py::arg(""));
// cls_Poly_HArray1OfTriangle.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Poly_HArray1OfTriangle::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Poly_HArray1OfTriangle.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Poly_HArray1OfTriangle::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Poly_HArray1OfTriangle.def("Array1", (const Poly_Array1OfTriangle & (Poly_HArray1OfTriangle::*)() const) &Poly_HArray1OfTriangle::Array1, "None");
cls_Poly_HArray1OfTriangle.def("ChangeArray1", (Poly_Array1OfTriangle & (Poly_HArray1OfTriangle::*)()) &Poly_HArray1OfTriangle::ChangeArray1, "None");
cls_Poly_HArray1OfTriangle.def_static("get_type_name_", (const char * (*)()) &Poly_HArray1OfTriangle::get_type_name, "None");
cls_Poly_HArray1OfTriangle.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Poly_HArray1OfTriangle::get_type_descriptor, "None");
cls_Poly_HArray1OfTriangle.def("DynamicType", (const opencascade::handle<Standard_Type> & (Poly_HArray1OfTriangle::*)() const) &Poly_HArray1OfTriangle::DynamicType, "None");

// Enums

}