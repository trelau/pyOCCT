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
#include <StepToTopoDS_PointPair.hxx>
#include <StepToTopoDS_PointPairHasher.hxx>

void bind_StepToTopoDS_PointPairHasher(py::module &mod){

py::class_<StepToTopoDS_PointPairHasher> cls_StepToTopoDS_PointPairHasher(mod, "StepToTopoDS_PointPairHasher", "None");

// Constructors

// Fields

// Methods
// cls_StepToTopoDS_PointPairHasher.def_static("operator new_", (void * (*)(size_t)) &StepToTopoDS_PointPairHasher::operator new, "None", py::arg("theSize"));
// cls_StepToTopoDS_PointPairHasher.def_static("operator delete_", (void (*)(void *)) &StepToTopoDS_PointPairHasher::operator delete, "None", py::arg("theAddress"));
// cls_StepToTopoDS_PointPairHasher.def_static("operator new[]_", (void * (*)(size_t)) &StepToTopoDS_PointPairHasher::operator new[], "None", py::arg("theSize"));
// cls_StepToTopoDS_PointPairHasher.def_static("operator delete[]_", (void (*)(void *)) &StepToTopoDS_PointPairHasher::operator delete[], "None", py::arg("theAddress"));
// cls_StepToTopoDS_PointPairHasher.def_static("operator new_", (void * (*)(size_t, void *)) &StepToTopoDS_PointPairHasher::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepToTopoDS_PointPairHasher.def_static("operator delete_", (void (*)(void *, void *)) &StepToTopoDS_PointPairHasher::operator delete, "None", py::arg(""), py::arg(""));
cls_StepToTopoDS_PointPairHasher.def_static("HashCode_", (Standard_Integer (*)(const StepToTopoDS_PointPair &, const Standard_Integer)) &StepToTopoDS_PointPairHasher::HashCode, "Returns a HasCode value for the PointPair", py::arg("K"), py::arg("Upper"));
cls_StepToTopoDS_PointPairHasher.def_static("IsEqual_", (Standard_Boolean (*)(const StepToTopoDS_PointPair &, const StepToTopoDS_PointPair &)) &StepToTopoDS_PointPairHasher::IsEqual, "Returns True when the two PointPair are the same", py::arg("K1"), py::arg("K2"));

// Enums

}