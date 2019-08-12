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
#include <AppParCurves_Array1OfMultiCurve.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <AppParCurves_HArray1OfMultiCurve.hxx>
#include <Standard_Type.hxx>

void bind_AppParCurves_HArray1OfMultiCurve(py::module &mod){

py::class_<AppParCurves_HArray1OfMultiCurve, opencascade::handle<AppParCurves_HArray1OfMultiCurve>, Standard_Transient> cls_AppParCurves_HArray1OfMultiCurve(mod, "AppParCurves_HArray1OfMultiCurve", "None", py::multiple_inheritance());

// Constructors
cls_AppParCurves_HArray1OfMultiCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_AppParCurves_HArray1OfMultiCurve.def(py::init<const Standard_Integer, const Standard_Integer, const AppParCurves_Array1OfMultiCurve::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_AppParCurves_HArray1OfMultiCurve.def(py::init<const AppParCurves_Array1OfMultiCurve &>(), py::arg("theOther"));

// Fields

// Methods
// cls_AppParCurves_HArray1OfMultiCurve.def_static("operator new_", (void * (*)(size_t)) &AppParCurves_HArray1OfMultiCurve::operator new, "None", py::arg("theSize"));
// cls_AppParCurves_HArray1OfMultiCurve.def_static("operator delete_", (void (*)(void *)) &AppParCurves_HArray1OfMultiCurve::operator delete, "None", py::arg("theAddress"));
// cls_AppParCurves_HArray1OfMultiCurve.def_static("operator new[]_", (void * (*)(size_t)) &AppParCurves_HArray1OfMultiCurve::operator new[], "None", py::arg("theSize"));
// cls_AppParCurves_HArray1OfMultiCurve.def_static("operator delete[]_", (void (*)(void *)) &AppParCurves_HArray1OfMultiCurve::operator delete[], "None", py::arg("theAddress"));
// cls_AppParCurves_HArray1OfMultiCurve.def_static("operator new_", (void * (*)(size_t, void *)) &AppParCurves_HArray1OfMultiCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AppParCurves_HArray1OfMultiCurve.def_static("operator delete_", (void (*)(void *, void *)) &AppParCurves_HArray1OfMultiCurve::operator delete, "None", py::arg(""), py::arg(""));
// cls_AppParCurves_HArray1OfMultiCurve.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &AppParCurves_HArray1OfMultiCurve::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_AppParCurves_HArray1OfMultiCurve.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &AppParCurves_HArray1OfMultiCurve::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_AppParCurves_HArray1OfMultiCurve.def("Array1", (const AppParCurves_Array1OfMultiCurve & (AppParCurves_HArray1OfMultiCurve::*)() const) &AppParCurves_HArray1OfMultiCurve::Array1, "None");
cls_AppParCurves_HArray1OfMultiCurve.def("ChangeArray1", (AppParCurves_Array1OfMultiCurve & (AppParCurves_HArray1OfMultiCurve::*)()) &AppParCurves_HArray1OfMultiCurve::ChangeArray1, "None");
cls_AppParCurves_HArray1OfMultiCurve.def_static("get_type_name_", (const char * (*)()) &AppParCurves_HArray1OfMultiCurve::get_type_name, "None");
cls_AppParCurves_HArray1OfMultiCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AppParCurves_HArray1OfMultiCurve::get_type_descriptor, "None");
cls_AppParCurves_HArray1OfMultiCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (AppParCurves_HArray1OfMultiCurve::*)() const) &AppParCurves_HArray1OfMultiCurve::DynamicType, "None");

// Enums

}