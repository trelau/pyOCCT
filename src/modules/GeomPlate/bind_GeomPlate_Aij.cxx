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
#include <gp_Vec.hxx>
#include <GeomPlate_BuildAveragePlane.hxx>
#include <GeomPlate_Aij.hxx>

void bind_GeomPlate_Aij(py::module &mod){

py::class_<GeomPlate_Aij, std::unique_ptr<GeomPlate_Aij>> cls_GeomPlate_Aij(mod, "GeomPlate_Aij", "A structure containing indexes of two normals and its cross product");

// Constructors
cls_GeomPlate_Aij.def(py::init<>());
cls_GeomPlate_Aij.def(py::init<const Standard_Integer, const Standard_Integer, const gp_Vec &>(), py::arg("anInd1"), py::arg("anInd2"), py::arg("aVec"));

// Fields

// Methods
// cls_GeomPlate_Aij.def_static("operator new_", (void * (*)(size_t)) &GeomPlate_Aij::operator new, "None", py::arg("theSize"));
// cls_GeomPlate_Aij.def_static("operator delete_", (void (*)(void *)) &GeomPlate_Aij::operator delete, "None", py::arg("theAddress"));
// cls_GeomPlate_Aij.def_static("operator new[]_", (void * (*)(size_t)) &GeomPlate_Aij::operator new[], "None", py::arg("theSize"));
// cls_GeomPlate_Aij.def_static("operator delete[]_", (void (*)(void *)) &GeomPlate_Aij::operator delete[], "None", py::arg("theAddress"));
// cls_GeomPlate_Aij.def_static("operator new_", (void * (*)(size_t, void *)) &GeomPlate_Aij::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomPlate_Aij.def_static("operator delete_", (void (*)(void *, void *)) &GeomPlate_Aij::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}