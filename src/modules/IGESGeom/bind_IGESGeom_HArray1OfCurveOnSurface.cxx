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
#include <IGESGeom_Array1OfCurveOnSurface.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <IGESGeom_HArray1OfCurveOnSurface.hxx>
#include <Standard_Type.hxx>

void bind_IGESGeom_HArray1OfCurveOnSurface(py::module &mod){

py::class_<IGESGeom_HArray1OfCurveOnSurface, opencascade::handle<IGESGeom_HArray1OfCurveOnSurface>, Standard_Transient> cls_IGESGeom_HArray1OfCurveOnSurface(mod, "IGESGeom_HArray1OfCurveOnSurface", "None", py::multiple_inheritance());

// Constructors
cls_IGESGeom_HArray1OfCurveOnSurface.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_IGESGeom_HArray1OfCurveOnSurface.def(py::init<const Standard_Integer, const Standard_Integer, const IGESGeom_Array1OfCurveOnSurface::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_IGESGeom_HArray1OfCurveOnSurface.def(py::init<const IGESGeom_Array1OfCurveOnSurface &>(), py::arg("theOther"));

// Fields

// Methods
// cls_IGESGeom_HArray1OfCurveOnSurface.def_static("operator new_", (void * (*)(size_t)) &IGESGeom_HArray1OfCurveOnSurface::operator new, "None", py::arg("theSize"));
// cls_IGESGeom_HArray1OfCurveOnSurface.def_static("operator delete_", (void (*)(void *)) &IGESGeom_HArray1OfCurveOnSurface::operator delete, "None", py::arg("theAddress"));
// cls_IGESGeom_HArray1OfCurveOnSurface.def_static("operator new[]_", (void * (*)(size_t)) &IGESGeom_HArray1OfCurveOnSurface::operator new[], "None", py::arg("theSize"));
// cls_IGESGeom_HArray1OfCurveOnSurface.def_static("operator delete[]_", (void (*)(void *)) &IGESGeom_HArray1OfCurveOnSurface::operator delete[], "None", py::arg("theAddress"));
// cls_IGESGeom_HArray1OfCurveOnSurface.def_static("operator new_", (void * (*)(size_t, void *)) &IGESGeom_HArray1OfCurveOnSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESGeom_HArray1OfCurveOnSurface.def_static("operator delete_", (void (*)(void *, void *)) &IGESGeom_HArray1OfCurveOnSurface::operator delete, "None", py::arg(""), py::arg(""));
// cls_IGESGeom_HArray1OfCurveOnSurface.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &IGESGeom_HArray1OfCurveOnSurface::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_IGESGeom_HArray1OfCurveOnSurface.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &IGESGeom_HArray1OfCurveOnSurface::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_IGESGeom_HArray1OfCurveOnSurface.def("Array1", (const IGESGeom_Array1OfCurveOnSurface & (IGESGeom_HArray1OfCurveOnSurface::*)() const) &IGESGeom_HArray1OfCurveOnSurface::Array1, "None");
cls_IGESGeom_HArray1OfCurveOnSurface.def("ChangeArray1", (IGESGeom_Array1OfCurveOnSurface & (IGESGeom_HArray1OfCurveOnSurface::*)()) &IGESGeom_HArray1OfCurveOnSurface::ChangeArray1, "None");
cls_IGESGeom_HArray1OfCurveOnSurface.def_static("get_type_name_", (const char * (*)()) &IGESGeom_HArray1OfCurveOnSurface::get_type_name, "None");
cls_IGESGeom_HArray1OfCurveOnSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGeom_HArray1OfCurveOnSurface::get_type_descriptor, "None");
cls_IGESGeom_HArray1OfCurveOnSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGeom_HArray1OfCurveOnSurface::*)() const) &IGESGeom_HArray1OfCurveOnSurface::DynamicType, "None");

// Enums

}