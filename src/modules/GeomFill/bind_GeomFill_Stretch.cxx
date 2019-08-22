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
#include <GeomFill_Filling.hxx>
#include <Standard.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <GeomFill_Stretch.hxx>

void bind_GeomFill_Stretch(py::module &mod){

py::class_<GeomFill_Stretch, GeomFill_Filling> cls_GeomFill_Stretch(mod, "GeomFill_Stretch", "None");

// Constructors
cls_GeomFill_Stretch.def(py::init<>());
cls_GeomFill_Stretch.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"));
cls_GeomFill_Stretch.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"), py::arg("W1"), py::arg("W2"), py::arg("W3"), py::arg("W4"));

// Fields

// Methods
// cls_GeomFill_Stretch.def_static("operator new_", (void * (*)(size_t)) &GeomFill_Stretch::operator new, "None", py::arg("theSize"));
// cls_GeomFill_Stretch.def_static("operator delete_", (void (*)(void *)) &GeomFill_Stretch::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_Stretch.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_Stretch::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_Stretch.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_Stretch::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_Stretch.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_Stretch::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_Stretch.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_Stretch::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_Stretch.def("Init", (void (GeomFill_Stretch::*)(const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &)) &GeomFill_Stretch::Init, "None", py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"));
cls_GeomFill_Stretch.def("Init", (void (GeomFill_Stretch::*)(const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &)) &GeomFill_Stretch::Init, "None", py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"), py::arg("W1"), py::arg("W2"), py::arg("W3"), py::arg("W4"));

// Enums

}