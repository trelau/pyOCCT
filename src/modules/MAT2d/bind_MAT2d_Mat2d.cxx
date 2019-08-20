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
#include <MAT2d_Tool2d.hxx>
#include <Standard_Handle.hxx>
#include <MAT_Bisector.hxx>
#include <MAT_ListOfEdge.hxx>
#include <TColStd_DataMapOfIntegerInteger.hxx>
#include <MAT_DataMapOfIntegerBisector.hxx>
#include <MAT_ListOfBisector.hxx>
#include <MAT2d_Mat2d.hxx>

void bind_MAT2d_Mat2d(py::module &mod){

py::class_<MAT2d_Mat2d, std::unique_ptr<MAT2d_Mat2d>> cls_MAT2d_Mat2d(mod, "MAT2d_Mat2d", "this class contains the generic algoritm of computation of the bisecting locus.");

// Constructors
cls_MAT2d_Mat2d.def(py::init<>());
cls_MAT2d_Mat2d.def(py::init<const Standard_Boolean>(), py::arg("IsOpenResult"));

// Fields

// Methods
// cls_MAT2d_Mat2d.def_static("operator new_", (void * (*)(size_t)) &MAT2d_Mat2d::operator new, "None", py::arg("theSize"));
// cls_MAT2d_Mat2d.def_static("operator delete_", (void (*)(void *)) &MAT2d_Mat2d::operator delete, "None", py::arg("theAddress"));
// cls_MAT2d_Mat2d.def_static("operator new[]_", (void * (*)(size_t)) &MAT2d_Mat2d::operator new[], "None", py::arg("theSize"));
// cls_MAT2d_Mat2d.def_static("operator delete[]_", (void (*)(void *)) &MAT2d_Mat2d::operator delete[], "None", py::arg("theAddress"));
// cls_MAT2d_Mat2d.def_static("operator new_", (void * (*)(size_t, void *)) &MAT2d_Mat2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_MAT2d_Mat2d.def_static("operator delete_", (void (*)(void *, void *)) &MAT2d_Mat2d::operator delete, "None", py::arg(""), py::arg(""));
cls_MAT2d_Mat2d.def("CreateMat", (void (MAT2d_Mat2d::*)(MAT2d_Tool2d &)) &MAT2d_Mat2d::CreateMat, "Algoritm of computation of the bisecting locus.", py::arg("aTool"));
cls_MAT2d_Mat2d.def("CreateMatOpen", (void (MAT2d_Mat2d::*)(MAT2d_Tool2d &)) &MAT2d_Mat2d::CreateMatOpen, "Algoritm of computation of the bisecting locus for open wire.", py::arg("aTool"));
cls_MAT2d_Mat2d.def("IsDone", (Standard_Boolean (MAT2d_Mat2d::*)() const) &MAT2d_Mat2d::IsDone, "Returns <TRUE> if CreateMat has succeeded.");
cls_MAT2d_Mat2d.def("Init", (void (MAT2d_Mat2d::*)()) &MAT2d_Mat2d::Init, "Initialize an iterator on the set of the roots of the trees of bisectors.");
cls_MAT2d_Mat2d.def("More", (Standard_Boolean (MAT2d_Mat2d::*)() const) &MAT2d_Mat2d::More, "Return False if there is no more roots.");
cls_MAT2d_Mat2d.def("Next", (void (MAT2d_Mat2d::*)()) &MAT2d_Mat2d::Next, "Move to the next root.");
cls_MAT2d_Mat2d.def("Bisector", (opencascade::handle<MAT_Bisector> (MAT2d_Mat2d::*)() const) &MAT2d_Mat2d::Bisector, "Returns the current root.");
cls_MAT2d_Mat2d.def("SemiInfinite", (Standard_Boolean (MAT2d_Mat2d::*)() const) &MAT2d_Mat2d::SemiInfinite, "Returns True if there are semi_infinite bisectors. So there is a tree for each semi_infinte bisector.");
cls_MAT2d_Mat2d.def("NumberOfBisectors", (Standard_Integer (MAT2d_Mat2d::*)() const) &MAT2d_Mat2d::NumberOfBisectors, "Returns the total number of bisectors.");

// Enums

}