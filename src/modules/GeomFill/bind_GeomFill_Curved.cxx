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
#include <GeomFill_Curved.hxx>

void bind_GeomFill_Curved(py::module &mod){

py::class_<GeomFill_Curved, GeomFill_Filling> cls_GeomFill_Curved(mod, "GeomFill_Curved", "None");

// Constructors
cls_GeomFill_Curved.def(py::init<>());
cls_GeomFill_Curved.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"));
cls_GeomFill_Curved.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"), py::arg("W1"), py::arg("W2"), py::arg("W3"), py::arg("W4"));
cls_GeomFill_Curved.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &>(), py::arg("P1"), py::arg("P2"));
cls_GeomFill_Curved.def(py::init<const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &>(), py::arg("P1"), py::arg("P2"), py::arg("W1"), py::arg("W2"));

// Fields

// Methods
// cls_GeomFill_Curved.def_static("operator new_", (void * (*)(size_t)) &GeomFill_Curved::operator new, "None", py::arg("theSize"));
// cls_GeomFill_Curved.def_static("operator delete_", (void (*)(void *)) &GeomFill_Curved::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_Curved.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_Curved::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_Curved.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_Curved::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_Curved.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_Curved::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_Curved.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_Curved::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_Curved.def("Init", (void (GeomFill_Curved::*)(const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &)) &GeomFill_Curved::Init, "None", py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"));
cls_GeomFill_Curved.def("Init", (void (GeomFill_Curved::*)(const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &)) &GeomFill_Curved::Init, "None", py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P4"), py::arg("W1"), py::arg("W2"), py::arg("W3"), py::arg("W4"));
cls_GeomFill_Curved.def("Init", (void (GeomFill_Curved::*)(const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &)) &GeomFill_Curved::Init, "None", py::arg("P1"), py::arg("P2"));
cls_GeomFill_Curved.def("Init", (void (GeomFill_Curved::*)(const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &)) &GeomFill_Curved::Init, "None", py::arg("P1"), py::arg("P2"), py::arg("W1"), py::arg("W2"));

// Enums

}