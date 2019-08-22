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
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <TColgp_Array2OfPnt.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <Standard_Handle.hxx>
#include <TColgp_HArray2OfPnt.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <GeomFill_Filling.hxx>

void bind_GeomFill_Filling(py::module &mod){

py::class_<GeomFill_Filling> cls_GeomFill_Filling(mod, "GeomFill_Filling", "Root class for Filling;");

// Constructors
cls_GeomFill_Filling.def(py::init<>());

// Fields

// Methods
// cls_GeomFill_Filling.def_static("operator new_", (void * (*)(size_t)) &GeomFill_Filling::operator new, "None", py::arg("theSize"));
// cls_GeomFill_Filling.def_static("operator delete_", (void (*)(void *)) &GeomFill_Filling::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_Filling.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_Filling::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_Filling.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_Filling::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_Filling.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_Filling::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_Filling.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_Filling::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_Filling.def("NbUPoles", (Standard_Integer (GeomFill_Filling::*)() const) &GeomFill_Filling::NbUPoles, "None");
cls_GeomFill_Filling.def("NbVPoles", (Standard_Integer (GeomFill_Filling::*)() const) &GeomFill_Filling::NbVPoles, "None");
cls_GeomFill_Filling.def("Poles", (void (GeomFill_Filling::*)(TColgp_Array2OfPnt &) const) &GeomFill_Filling::Poles, "None", py::arg("Poles"));
cls_GeomFill_Filling.def("isRational", (Standard_Boolean (GeomFill_Filling::*)() const) &GeomFill_Filling::isRational, "None");
cls_GeomFill_Filling.def("Weights", (void (GeomFill_Filling::*)(TColStd_Array2OfReal &) const) &GeomFill_Filling::Weights, "None", py::arg("Weights"));

// Enums

}