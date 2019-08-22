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
#include <gp_Pnt.hxx>
#include <STEPConstruct_PointHasher.hxx>

void bind_STEPConstruct_PointHasher(py::module &mod){

py::class_<STEPConstruct_PointHasher> cls_STEPConstruct_PointHasher(mod, "STEPConstruct_PointHasher", "None");

// Constructors

// Fields

// Methods
// cls_STEPConstruct_PointHasher.def_static("operator new_", (void * (*)(size_t)) &STEPConstruct_PointHasher::operator new, "None", py::arg("theSize"));
// cls_STEPConstruct_PointHasher.def_static("operator delete_", (void (*)(void *)) &STEPConstruct_PointHasher::operator delete, "None", py::arg("theAddress"));
// cls_STEPConstruct_PointHasher.def_static("operator new[]_", (void * (*)(size_t)) &STEPConstruct_PointHasher::operator new[], "None", py::arg("theSize"));
// cls_STEPConstruct_PointHasher.def_static("operator delete[]_", (void (*)(void *)) &STEPConstruct_PointHasher::operator delete[], "None", py::arg("theAddress"));
// cls_STEPConstruct_PointHasher.def_static("operator new_", (void * (*)(size_t, void *)) &STEPConstruct_PointHasher::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPConstruct_PointHasher.def_static("operator delete_", (void (*)(void *, void *)) &STEPConstruct_PointHasher::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPConstruct_PointHasher.def_static("HashCode_", (Standard_Integer (*)(const gp_Pnt &, const Standard_Integer)) &STEPConstruct_PointHasher::HashCode, "Returns a HasCode value for the Key <K> in the range 0..Upper.", py::arg("Point"), py::arg("Upper"));
cls_STEPConstruct_PointHasher.def_static("IsEqual_", (Standard_Boolean (*)(const gp_Pnt &, const gp_Pnt &)) &STEPConstruct_PointHasher::IsEqual, "Returns True when the two keys are the same. Two same keys must have the same hashcode, the contrary is not necessary.", py::arg("Point1"), py::arg("Point2"));

// Enums

}