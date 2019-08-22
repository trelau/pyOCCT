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
#include <gp_Circ.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Lin.hxx>
#include <ChFiDS_CircSection.hxx>

void bind_ChFiDS_CircSection(py::module &mod){

py::class_<ChFiDS_CircSection> cls_ChFiDS_CircSection(mod, "ChFiDS_CircSection", "A Section of fillet.");

// Constructors
cls_ChFiDS_CircSection.def(py::init<>());

// Fields

// Methods
// cls_ChFiDS_CircSection.def_static("operator new_", (void * (*)(size_t)) &ChFiDS_CircSection::operator new, "None", py::arg("theSize"));
// cls_ChFiDS_CircSection.def_static("operator delete_", (void (*)(void *)) &ChFiDS_CircSection::operator delete, "None", py::arg("theAddress"));
// cls_ChFiDS_CircSection.def_static("operator new[]_", (void * (*)(size_t)) &ChFiDS_CircSection::operator new[], "None", py::arg("theSize"));
// cls_ChFiDS_CircSection.def_static("operator delete[]_", (void (*)(void *)) &ChFiDS_CircSection::operator delete[], "None", py::arg("theAddress"));
// cls_ChFiDS_CircSection.def_static("operator new_", (void * (*)(size_t, void *)) &ChFiDS_CircSection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ChFiDS_CircSection.def_static("operator delete_", (void (*)(void *, void *)) &ChFiDS_CircSection::operator delete, "None", py::arg(""), py::arg(""));
cls_ChFiDS_CircSection.def("Set", (void (ChFiDS_CircSection::*)(const gp_Circ &, const Standard_Real, const Standard_Real)) &ChFiDS_CircSection::Set, "None", py::arg("C"), py::arg("F"), py::arg("L"));
cls_ChFiDS_CircSection.def("Set", (void (ChFiDS_CircSection::*)(const gp_Lin &, const Standard_Real, const Standard_Real)) &ChFiDS_CircSection::Set, "None", py::arg("C"), py::arg("F"), py::arg("L"));
cls_ChFiDS_CircSection.def("Get", [](ChFiDS_CircSection &self, gp_Circ & C, Standard_Real & F, Standard_Real & L){ self.Get(C, F, L); return std::tuple<Standard_Real &, Standard_Real &>(F, L); }, "None", py::arg("C"), py::arg("F"), py::arg("L"));
cls_ChFiDS_CircSection.def("Get", [](ChFiDS_CircSection &self, gp_Lin & C, Standard_Real & F, Standard_Real & L){ self.Get(C, F, L); return std::tuple<Standard_Real &, Standard_Real &>(F, L); }, "None", py::arg("C"), py::arg("F"), py::arg("L"));

// Enums

}