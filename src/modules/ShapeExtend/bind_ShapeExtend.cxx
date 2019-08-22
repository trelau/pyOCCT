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
#include <ShapeExtend_Status.hxx>
#include <ShapeExtend_ComplexCurve.hxx>
#include <ShapeExtend_CompositeSurface.hxx>
#include <ShapeExtend_WireData.hxx>
#include <ShapeExtend_BasicMsgRegistrator.hxx>
#include <ShapeExtend_MsgRegistrator.hxx>
#include <ShapeExtend_Explorer.hxx>
#include <ShapeExtend.hxx>

void bind_ShapeExtend(py::module &mod){

py::class_<ShapeExtend> cls_ShapeExtend(mod, "ShapeExtend", "This package provides general tools and data structures common for other packages in SHAPEWORKS and extending CAS.CADE structures. The following items are provided by this package: - enumeration Status used for coding status flags in methods inside the SHAPEWORKS - enumeration Parametrisation used for setting global parametrisation on the composite surface - class CompositeSurface representing a composite surface made of a grid of surface patches - class WireData representing a wire in the form of ordered list of edges - class MsgRegistrator for attaching messages to the objects - tools for exploring the shapes - tools for creating new shapes.");

// Constructors

// Fields

// Methods
// cls_ShapeExtend.def_static("operator new_", (void * (*)(size_t)) &ShapeExtend::operator new, "None", py::arg("theSize"));
// cls_ShapeExtend.def_static("operator delete_", (void (*)(void *)) &ShapeExtend::operator delete, "None", py::arg("theAddress"));
// cls_ShapeExtend.def_static("operator new[]_", (void * (*)(size_t)) &ShapeExtend::operator new[], "None", py::arg("theSize"));
// cls_ShapeExtend.def_static("operator delete[]_", (void (*)(void *)) &ShapeExtend::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeExtend.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeExtend::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeExtend.def_static("operator delete_", (void (*)(void *, void *)) &ShapeExtend::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeExtend.def_static("Init_", (void (*)()) &ShapeExtend::Init, "Inits using of ShapeExtend. Currently, loads messages output by ShapeHealing algorithms.");
cls_ShapeExtend.def_static("EncodeStatus_", (Standard_Integer (*)(const ShapeExtend_Status)) &ShapeExtend::EncodeStatus, "Encodes status (enumeration) to a bit flag", py::arg("status"));
cls_ShapeExtend.def_static("DecodeStatus_", (Standard_Boolean (*)(const Standard_Integer, const ShapeExtend_Status)) &ShapeExtend::DecodeStatus, "Tells if a bit flag contains bit corresponding to enumerated status", py::arg("flag"), py::arg("status"));

// Enums

}