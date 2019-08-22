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
#include <IntPatch_PrmPrmIntersection_T3Bits.hxx>

void bind_IntPatch_PrmPrmIntersection_T3Bits(py::module &mod){

py::class_<IntPatch_PrmPrmIntersection_T3Bits> cls_IntPatch_PrmPrmIntersection_T3Bits(mod, "IntPatch_PrmPrmIntersection_T3Bits", "None");

// Constructors
cls_IntPatch_PrmPrmIntersection_T3Bits.def(py::init<const Standard_Integer>(), py::arg("size"));

// Fields

// Methods
// cls_IntPatch_PrmPrmIntersection_T3Bits.def_static("operator new_", (void * (*)(size_t)) &IntPatch_PrmPrmIntersection_T3Bits::operator new, "None", py::arg("theSize"));
// cls_IntPatch_PrmPrmIntersection_T3Bits.def_static("operator delete_", (void (*)(void *)) &IntPatch_PrmPrmIntersection_T3Bits::operator delete, "None", py::arg("theAddress"));
// cls_IntPatch_PrmPrmIntersection_T3Bits.def_static("operator new[]_", (void * (*)(size_t)) &IntPatch_PrmPrmIntersection_T3Bits::operator new[], "None", py::arg("theSize"));
// cls_IntPatch_PrmPrmIntersection_T3Bits.def_static("operator delete[]_", (void (*)(void *)) &IntPatch_PrmPrmIntersection_T3Bits::operator delete[], "None", py::arg("theAddress"));
// cls_IntPatch_PrmPrmIntersection_T3Bits.def_static("operator new_", (void * (*)(size_t, void *)) &IntPatch_PrmPrmIntersection_T3Bits::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPatch_PrmPrmIntersection_T3Bits.def_static("operator delete_", (void (*)(void *, void *)) &IntPatch_PrmPrmIntersection_T3Bits::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPatch_PrmPrmIntersection_T3Bits.def("Destroy", (void (IntPatch_PrmPrmIntersection_T3Bits::*)()) &IntPatch_PrmPrmIntersection_T3Bits::Destroy, "None");
cls_IntPatch_PrmPrmIntersection_T3Bits.def("Add", (void (IntPatch_PrmPrmIntersection_T3Bits::*)(const Standard_Integer)) &IntPatch_PrmPrmIntersection_T3Bits::Add, "None", py::arg("t"));
cls_IntPatch_PrmPrmIntersection_T3Bits.def("Val", (Standard_Integer (IntPatch_PrmPrmIntersection_T3Bits::*)(const Standard_Integer) const) &IntPatch_PrmPrmIntersection_T3Bits::Val, "None", py::arg("t"));
cls_IntPatch_PrmPrmIntersection_T3Bits.def("Raz", (void (IntPatch_PrmPrmIntersection_T3Bits::*)(const Standard_Integer)) &IntPatch_PrmPrmIntersection_T3Bits::Raz, "None", py::arg("t"));
cls_IntPatch_PrmPrmIntersection_T3Bits.def("ResetAnd", (void (IntPatch_PrmPrmIntersection_T3Bits::*)()) &IntPatch_PrmPrmIntersection_T3Bits::ResetAnd, "None");
cls_IntPatch_PrmPrmIntersection_T3Bits.def("And", [](IntPatch_PrmPrmIntersection_T3Bits &self, IntPatch_PrmPrmIntersection_T3Bits & Oth, Standard_Integer & indiceprecedent){ Standard_Integer rv = self.And(Oth, indiceprecedent); return std::tuple<Standard_Integer, Standard_Integer &>(rv, indiceprecedent); }, "None", py::arg("Oth"), py::arg("indiceprecedent"));

// Enums

}