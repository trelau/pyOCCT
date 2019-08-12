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
#include <TColGeom_Array1OfSurface.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <TColGeom_HArray1OfSurface.hxx>
#include <Standard_Type.hxx>

void bind_TColGeom_HArray1OfSurface(py::module &mod){

py::class_<TColGeom_HArray1OfSurface, opencascade::handle<TColGeom_HArray1OfSurface>, Standard_Transient> cls_TColGeom_HArray1OfSurface(mod, "TColGeom_HArray1OfSurface", "None", py::multiple_inheritance());

// Constructors
cls_TColGeom_HArray1OfSurface.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TColGeom_HArray1OfSurface.def(py::init<const Standard_Integer, const Standard_Integer, const TColGeom_Array1OfSurface::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TColGeom_HArray1OfSurface.def(py::init<const TColGeom_Array1OfSurface &>(), py::arg("theOther"));

// Fields

// Methods
// cls_TColGeom_HArray1OfSurface.def_static("operator new_", (void * (*)(size_t)) &TColGeom_HArray1OfSurface::operator new, "None", py::arg("theSize"));
// cls_TColGeom_HArray1OfSurface.def_static("operator delete_", (void (*)(void *)) &TColGeom_HArray1OfSurface::operator delete, "None", py::arg("theAddress"));
// cls_TColGeom_HArray1OfSurface.def_static("operator new[]_", (void * (*)(size_t)) &TColGeom_HArray1OfSurface::operator new[], "None", py::arg("theSize"));
// cls_TColGeom_HArray1OfSurface.def_static("operator delete[]_", (void (*)(void *)) &TColGeom_HArray1OfSurface::operator delete[], "None", py::arg("theAddress"));
// cls_TColGeom_HArray1OfSurface.def_static("operator new_", (void * (*)(size_t, void *)) &TColGeom_HArray1OfSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColGeom_HArray1OfSurface.def_static("operator delete_", (void (*)(void *, void *)) &TColGeom_HArray1OfSurface::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColGeom_HArray1OfSurface.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom_HArray1OfSurface::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColGeom_HArray1OfSurface.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom_HArray1OfSurface::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColGeom_HArray1OfSurface.def("Array1", (const TColGeom_Array1OfSurface & (TColGeom_HArray1OfSurface::*)() const) &TColGeom_HArray1OfSurface::Array1, "None");
cls_TColGeom_HArray1OfSurface.def("ChangeArray1", (TColGeom_Array1OfSurface & (TColGeom_HArray1OfSurface::*)()) &TColGeom_HArray1OfSurface::ChangeArray1, "None");
cls_TColGeom_HArray1OfSurface.def_static("get_type_name_", (const char * (*)()) &TColGeom_HArray1OfSurface::get_type_name, "None");
cls_TColGeom_HArray1OfSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom_HArray1OfSurface::get_type_descriptor, "None");
cls_TColGeom_HArray1OfSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom_HArray1OfSurface::*)() const) &TColGeom_HArray1OfSurface::DynamicType, "None");

// Enums

}