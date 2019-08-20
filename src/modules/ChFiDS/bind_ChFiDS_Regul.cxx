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
#include <ChFiDS_Regul.hxx>

void bind_ChFiDS_Regul(py::module &mod){

py::class_<ChFiDS_Regul, std::unique_ptr<ChFiDS_Regul>> cls_ChFiDS_Regul(mod, "ChFiDS_Regul", "Storage of a curve and its 2 faces or surfaces of support.");

// Constructors
cls_ChFiDS_Regul.def(py::init<>());

// Fields

// Methods
// cls_ChFiDS_Regul.def_static("operator new_", (void * (*)(size_t)) &ChFiDS_Regul::operator new, "None", py::arg("theSize"));
// cls_ChFiDS_Regul.def_static("operator delete_", (void (*)(void *)) &ChFiDS_Regul::operator delete, "None", py::arg("theAddress"));
// cls_ChFiDS_Regul.def_static("operator new[]_", (void * (*)(size_t)) &ChFiDS_Regul::operator new[], "None", py::arg("theSize"));
// cls_ChFiDS_Regul.def_static("operator delete[]_", (void (*)(void *)) &ChFiDS_Regul::operator delete[], "None", py::arg("theAddress"));
// cls_ChFiDS_Regul.def_static("operator new_", (void * (*)(size_t, void *)) &ChFiDS_Regul::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ChFiDS_Regul.def_static("operator delete_", (void (*)(void *, void *)) &ChFiDS_Regul::operator delete, "None", py::arg(""), py::arg(""));
cls_ChFiDS_Regul.def("SetCurve", (void (ChFiDS_Regul::*)(const Standard_Integer)) &ChFiDS_Regul::SetCurve, "None", py::arg("IC"));
cls_ChFiDS_Regul.def("SetS1", [](ChFiDS_Regul &self, const Standard_Integer a0) -> void { return self.SetS1(a0); });
cls_ChFiDS_Regul.def("SetS1", (void (ChFiDS_Regul::*)(const Standard_Integer, const Standard_Boolean)) &ChFiDS_Regul::SetS1, "None", py::arg("IS1"), py::arg("IsFace"));
cls_ChFiDS_Regul.def("SetS2", [](ChFiDS_Regul &self, const Standard_Integer a0) -> void { return self.SetS2(a0); });
cls_ChFiDS_Regul.def("SetS2", (void (ChFiDS_Regul::*)(const Standard_Integer, const Standard_Boolean)) &ChFiDS_Regul::SetS2, "None", py::arg("IS2"), py::arg("IsFace"));
cls_ChFiDS_Regul.def("IsSurface1", (Standard_Boolean (ChFiDS_Regul::*)() const) &ChFiDS_Regul::IsSurface1, "None");
cls_ChFiDS_Regul.def("IsSurface2", (Standard_Boolean (ChFiDS_Regul::*)() const) &ChFiDS_Regul::IsSurface2, "None");
cls_ChFiDS_Regul.def("Curve", (Standard_Integer (ChFiDS_Regul::*)() const) &ChFiDS_Regul::Curve, "None");
cls_ChFiDS_Regul.def("S1", (Standard_Integer (ChFiDS_Regul::*)() const) &ChFiDS_Regul::S1, "None");
cls_ChFiDS_Regul.def("S2", (Standard_Integer (ChFiDS_Regul::*)() const) &ChFiDS_Regul::S2, "None");

// Enums

}