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
#include <Extrema_Array1OfPOnCurv2d.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <Extrema_HArray1OfPOnCurv2d.hxx>
#include <Standard_Type.hxx>

void bind_Extrema_HArray1OfPOnCurv2d(py::module &mod){

py::class_<Extrema_HArray1OfPOnCurv2d, opencascade::handle<Extrema_HArray1OfPOnCurv2d>, Standard_Transient> cls_Extrema_HArray1OfPOnCurv2d(mod, "Extrema_HArray1OfPOnCurv2d", "None", py::multiple_inheritance());

// Constructors
cls_Extrema_HArray1OfPOnCurv2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_Extrema_HArray1OfPOnCurv2d.def(py::init<const Standard_Integer, const Standard_Integer, const Extrema_Array1OfPOnCurv2d::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_Extrema_HArray1OfPOnCurv2d.def(py::init<const Extrema_Array1OfPOnCurv2d &>(), py::arg("theOther"));

// Fields

// Methods
// cls_Extrema_HArray1OfPOnCurv2d.def_static("operator new_", (void * (*)(size_t)) &Extrema_HArray1OfPOnCurv2d::operator new, "None", py::arg("theSize"));
// cls_Extrema_HArray1OfPOnCurv2d.def_static("operator delete_", (void (*)(void *)) &Extrema_HArray1OfPOnCurv2d::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_HArray1OfPOnCurv2d.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_HArray1OfPOnCurv2d::operator new[], "None", py::arg("theSize"));
// cls_Extrema_HArray1OfPOnCurv2d.def_static("operator delete[]_", (void (*)(void *)) &Extrema_HArray1OfPOnCurv2d::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_HArray1OfPOnCurv2d.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_HArray1OfPOnCurv2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_HArray1OfPOnCurv2d.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_HArray1OfPOnCurv2d::operator delete, "None", py::arg(""), py::arg(""));
// cls_Extrema_HArray1OfPOnCurv2d.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &Extrema_HArray1OfPOnCurv2d::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_Extrema_HArray1OfPOnCurv2d.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &Extrema_HArray1OfPOnCurv2d::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_Extrema_HArray1OfPOnCurv2d.def("Array1", (const Extrema_Array1OfPOnCurv2d & (Extrema_HArray1OfPOnCurv2d::*)() const) &Extrema_HArray1OfPOnCurv2d::Array1, "None");
cls_Extrema_HArray1OfPOnCurv2d.def("ChangeArray1", (Extrema_Array1OfPOnCurv2d & (Extrema_HArray1OfPOnCurv2d::*)()) &Extrema_HArray1OfPOnCurv2d::ChangeArray1, "None");
cls_Extrema_HArray1OfPOnCurv2d.def_static("get_type_name_", (const char * (*)()) &Extrema_HArray1OfPOnCurv2d::get_type_name, "None");
cls_Extrema_HArray1OfPOnCurv2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Extrema_HArray1OfPOnCurv2d::get_type_descriptor, "None");
cls_Extrema_HArray1OfPOnCurv2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (Extrema_HArray1OfPOnCurv2d::*)() const) &Extrema_HArray1OfPOnCurv2d::DynamicType, "None");

// Enums

}