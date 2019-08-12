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
#include <Approx_Array1OfAdHSurface.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <Approx_HArray1OfAdHSurface.hxx>
#include <Standard_Type.hxx>

void bind_Approx_HArray1OfAdHSurface(py::module &mod){

py::class_<Approx_HArray1OfAdHSurface, opencascade::handle<Approx_HArray1OfAdHSurface>, Standard_Transient> cls_Approx_HArray1OfAdHSurface(mod, "Approx_HArray1OfAdHSurface", "None", py::multiple_inheritance());

// Constructors
cls_Approx_HArray1OfAdHSurface.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_Approx_HArray1OfAdHSurface.def(py::init<const Standard_Integer, const Standard_Integer, const Approx_Array1OfAdHSurface::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_Approx_HArray1OfAdHSurface.def(py::init<const Approx_Array1OfAdHSurface &>(), py::arg("theOther"));

// Fields

// Methods
// cls_Approx_HArray1OfAdHSurface.def_static("operator new_", (void * (*)(size_t)) &Approx_HArray1OfAdHSurface::operator new, "None", py::arg("theSize"));
// cls_Approx_HArray1OfAdHSurface.def_static("operator delete_", (void (*)(void *)) &Approx_HArray1OfAdHSurface::operator delete, "None", py::arg("theAddress"));
// cls_Approx_HArray1OfAdHSurface.def_static("operator new[]_", (void * (*)(size_t)) &Approx_HArray1OfAdHSurface::operator new[], "None", py::arg("theSize"));
// cls_Approx_HArray1OfAdHSurface.def_static("operator delete[]_", (void (*)(void *)) &Approx_HArray1OfAdHSurface::operator delete[], "None", py::arg("theAddress"));
// cls_Approx_HArray1OfAdHSurface.def_static("operator new_", (void * (*)(size_t, void *)) &Approx_HArray1OfAdHSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Approx_HArray1OfAdHSurface.def_static("operator delete_", (void (*)(void *, void *)) &Approx_HArray1OfAdHSurface::operator delete, "None", py::arg(""), py::arg(""));
// cls_Approx_HArray1OfAdHSurface.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Approx_HArray1OfAdHSurface::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Approx_HArray1OfAdHSurface.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Approx_HArray1OfAdHSurface::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Approx_HArray1OfAdHSurface.def("Array1", (const Approx_Array1OfAdHSurface & (Approx_HArray1OfAdHSurface::*)() const) &Approx_HArray1OfAdHSurface::Array1, "None");
cls_Approx_HArray1OfAdHSurface.def("ChangeArray1", (Approx_Array1OfAdHSurface & (Approx_HArray1OfAdHSurface::*)()) &Approx_HArray1OfAdHSurface::ChangeArray1, "None");
cls_Approx_HArray1OfAdHSurface.def_static("get_type_name_", (const char * (*)()) &Approx_HArray1OfAdHSurface::get_type_name, "None");
cls_Approx_HArray1OfAdHSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Approx_HArray1OfAdHSurface::get_type_descriptor, "None");
cls_Approx_HArray1OfAdHSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (Approx_HArray1OfAdHSurface::*)() const) &Approx_HArray1OfAdHSurface::DynamicType, "None");

// Enums

}