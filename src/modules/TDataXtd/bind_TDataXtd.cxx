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
#include <TDF_IDList.hxx>
#include <Standard_OStream.hxx>
#include <TDataXtd_GeometryEnum.hxx>
#include <TDataXtd_ConstraintEnum.hxx>
#include <TDataXtd_Position.hxx>
#include <TDataXtd_Constraint.hxx>
#include <TDataXtd_Placement.hxx>
#include <TDataXtd_Geometry.hxx>
#include <TDataXtd_Point.hxx>
#include <TDataXtd_Axis.hxx>
#include <TDataXtd_Plane.hxx>
#include <TDataXtd_Pattern.hxx>
#include <TDataXtd_PatternStd.hxx>
#include <TDataXtd_Shape.hxx>
#include <TDataXtd_Triangulation.hxx>
#include <TDataXtd.hxx>

void bind_TDataXtd(py::module &mod){

py::class_<TDataXtd> cls_TDataXtd(mod, "TDataXtd", "This package defines extension of standard attributes for modelling (mainly for work with geometry).");

// Constructors

// Fields

// Methods
// cls_TDataXtd.def_static("operator new_", (void * (*)(size_t)) &TDataXtd::operator new, "None", py::arg("theSize"));
// cls_TDataXtd.def_static("operator delete_", (void (*)(void *)) &TDataXtd::operator delete, "None", py::arg("theAddress"));
// cls_TDataXtd.def_static("operator new[]_", (void * (*)(size_t)) &TDataXtd::operator new[], "None", py::arg("theSize"));
// cls_TDataXtd.def_static("operator delete[]_", (void (*)(void *)) &TDataXtd::operator delete[], "None", py::arg("theAddress"));
// cls_TDataXtd.def_static("operator new_", (void * (*)(size_t, void *)) &TDataXtd::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TDataXtd.def_static("operator delete_", (void (*)(void *, void *)) &TDataXtd::operator delete, "None", py::arg(""), py::arg(""));
cls_TDataXtd.def_static("IDList_", (void (*)(TDF_IDList &)) &TDataXtd::IDList, "Appends to <anIDList> the list of the attributes IDs of this package. CAUTION: <anIDList> is NOT cleared before use. Print of TDataExt enumeration =============================", py::arg("anIDList"));
cls_TDataXtd.def_static("Print_", (Standard_OStream & (*)(const TDataXtd_GeometryEnum, Standard_OStream &)) &TDataXtd::Print, "Prints the name of the geometry dimension <GEO> as a String on the Stream <S> and returns <S>.", py::arg("GEO"), py::arg("S"));
cls_TDataXtd.def_static("Print_", (Standard_OStream & (*)(const TDataXtd_ConstraintEnum, Standard_OStream &)) &TDataXtd::Print, "Prints the name of the constraint <CTR> as a String on the Stream <S> and returns <S>.", py::arg("CTR"), py::arg("S"));

// Enums

}