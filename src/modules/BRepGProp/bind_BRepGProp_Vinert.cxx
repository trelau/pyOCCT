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
#include <GProp_GProps.hxx>
#include <Standard.hxx>
#include <BRepGProp_Face.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pln.hxx>
#include <BRepGProp_Domain.hxx>
#include <BRepGProp_Vinert.hxx>

void bind_BRepGProp_Vinert(py::module &mod){

py::class_<BRepGProp_Vinert, GProp_GProps> cls_BRepGProp_Vinert(mod, "BRepGProp_Vinert", "Computes the global properties of a geometric solid (3D closed region of space) delimited with : . a surface . a point and a surface . a plane and a surface");

// Constructors
cls_BRepGProp_Vinert.def(py::init<>());
cls_BRepGProp_Vinert.def(py::init<const BRepGProp_Face &, const gp_Pnt &>(), py::arg("S"), py::arg("VLocation"));
cls_BRepGProp_Vinert.def(py::init<BRepGProp_Face &, const gp_Pnt &, const Standard_Real>(), py::arg("S"), py::arg("VLocation"), py::arg("Eps"));
cls_BRepGProp_Vinert.def(py::init<const BRepGProp_Face &, const gp_Pnt &, const gp_Pnt &>(), py::arg("S"), py::arg("O"), py::arg("VLocation"));
cls_BRepGProp_Vinert.def(py::init<BRepGProp_Face &, const gp_Pnt &, const gp_Pnt &, const Standard_Real>(), py::arg("S"), py::arg("O"), py::arg("VLocation"), py::arg("Eps"));
cls_BRepGProp_Vinert.def(py::init<const BRepGProp_Face &, const gp_Pln &, const gp_Pnt &>(), py::arg("S"), py::arg("Pl"), py::arg("VLocation"));
cls_BRepGProp_Vinert.def(py::init<BRepGProp_Face &, const gp_Pln &, const gp_Pnt &, const Standard_Real>(), py::arg("S"), py::arg("Pl"), py::arg("VLocation"), py::arg("Eps"));
cls_BRepGProp_Vinert.def(py::init<BRepGProp_Face &, BRepGProp_Domain &, const gp_Pnt &>(), py::arg("S"), py::arg("D"), py::arg("VLocation"));
cls_BRepGProp_Vinert.def(py::init<BRepGProp_Face &, BRepGProp_Domain &, const gp_Pnt &, const Standard_Real>(), py::arg("S"), py::arg("D"), py::arg("VLocation"), py::arg("Eps"));
cls_BRepGProp_Vinert.def(py::init<BRepGProp_Face &, BRepGProp_Domain &, const gp_Pnt &, const gp_Pnt &>(), py::arg("S"), py::arg("D"), py::arg("O"), py::arg("VLocation"));
cls_BRepGProp_Vinert.def(py::init<BRepGProp_Face &, BRepGProp_Domain &, const gp_Pnt &, const gp_Pnt &, const Standard_Real>(), py::arg("S"), py::arg("D"), py::arg("O"), py::arg("VLocation"), py::arg("Eps"));
cls_BRepGProp_Vinert.def(py::init<BRepGProp_Face &, BRepGProp_Domain &, const gp_Pln &, const gp_Pnt &>(), py::arg("S"), py::arg("D"), py::arg("Pl"), py::arg("VLocation"));
cls_BRepGProp_Vinert.def(py::init<BRepGProp_Face &, BRepGProp_Domain &, const gp_Pln &, const gp_Pnt &, const Standard_Real>(), py::arg("S"), py::arg("D"), py::arg("Pl"), py::arg("VLocation"), py::arg("Eps"));

// Fields

// Methods
// cls_BRepGProp_Vinert.def_static("operator new_", (void * (*)(size_t)) &BRepGProp_Vinert::operator new, "None", py::arg("theSize"));
// cls_BRepGProp_Vinert.def_static("operator delete_", (void (*)(void *)) &BRepGProp_Vinert::operator delete, "None", py::arg("theAddress"));
// cls_BRepGProp_Vinert.def_static("operator new[]_", (void * (*)(size_t)) &BRepGProp_Vinert::operator new[], "None", py::arg("theSize"));
// cls_BRepGProp_Vinert.def_static("operator delete[]_", (void (*)(void *)) &BRepGProp_Vinert::operator delete[], "None", py::arg("theAddress"));
// cls_BRepGProp_Vinert.def_static("operator new_", (void * (*)(size_t, void *)) &BRepGProp_Vinert::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepGProp_Vinert.def_static("operator delete_", (void (*)(void *, void *)) &BRepGProp_Vinert::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepGProp_Vinert.def("SetLocation", (void (BRepGProp_Vinert::*)(const gp_Pnt &)) &BRepGProp_Vinert::SetLocation, "None", py::arg("VLocation"));
cls_BRepGProp_Vinert.def("Perform", (void (BRepGProp_Vinert::*)(const BRepGProp_Face &)) &BRepGProp_Vinert::Perform, "None", py::arg("S"));
cls_BRepGProp_Vinert.def("Perform", (Standard_Real (BRepGProp_Vinert::*)(BRepGProp_Face &, const Standard_Real)) &BRepGProp_Vinert::Perform, "None", py::arg("S"), py::arg("Eps"));
cls_BRepGProp_Vinert.def("Perform", (void (BRepGProp_Vinert::*)(const BRepGProp_Face &, const gp_Pnt &)) &BRepGProp_Vinert::Perform, "None", py::arg("S"), py::arg("O"));
cls_BRepGProp_Vinert.def("Perform", (Standard_Real (BRepGProp_Vinert::*)(BRepGProp_Face &, const gp_Pnt &, const Standard_Real)) &BRepGProp_Vinert::Perform, "None", py::arg("S"), py::arg("O"), py::arg("Eps"));
cls_BRepGProp_Vinert.def("Perform", (void (BRepGProp_Vinert::*)(const BRepGProp_Face &, const gp_Pln &)) &BRepGProp_Vinert::Perform, "None", py::arg("S"), py::arg("Pl"));
cls_BRepGProp_Vinert.def("Perform", (Standard_Real (BRepGProp_Vinert::*)(BRepGProp_Face &, const gp_Pln &, const Standard_Real)) &BRepGProp_Vinert::Perform, "None", py::arg("S"), py::arg("Pl"), py::arg("Eps"));
cls_BRepGProp_Vinert.def("Perform", (void (BRepGProp_Vinert::*)(BRepGProp_Face &, BRepGProp_Domain &)) &BRepGProp_Vinert::Perform, "None", py::arg("S"), py::arg("D"));
cls_BRepGProp_Vinert.def("Perform", (Standard_Real (BRepGProp_Vinert::*)(BRepGProp_Face &, BRepGProp_Domain &, const Standard_Real)) &BRepGProp_Vinert::Perform, "None", py::arg("S"), py::arg("D"), py::arg("Eps"));
cls_BRepGProp_Vinert.def("Perform", (void (BRepGProp_Vinert::*)(BRepGProp_Face &, BRepGProp_Domain &, const gp_Pnt &)) &BRepGProp_Vinert::Perform, "None", py::arg("S"), py::arg("D"), py::arg("O"));
cls_BRepGProp_Vinert.def("Perform", (Standard_Real (BRepGProp_Vinert::*)(BRepGProp_Face &, BRepGProp_Domain &, const gp_Pnt &, const Standard_Real)) &BRepGProp_Vinert::Perform, "None", py::arg("S"), py::arg("D"), py::arg("O"), py::arg("Eps"));
cls_BRepGProp_Vinert.def("Perform", (void (BRepGProp_Vinert::*)(BRepGProp_Face &, BRepGProp_Domain &, const gp_Pln &)) &BRepGProp_Vinert::Perform, "None", py::arg("S"), py::arg("D"), py::arg("Pl"));
cls_BRepGProp_Vinert.def("Perform", (Standard_Real (BRepGProp_Vinert::*)(BRepGProp_Face &, BRepGProp_Domain &, const gp_Pln &, const Standard_Real)) &BRepGProp_Vinert::Perform, "None", py::arg("S"), py::arg("D"), py::arg("Pl"), py::arg("Eps"));
cls_BRepGProp_Vinert.def("GetEpsilon", (Standard_Real (BRepGProp_Vinert::*)()) &BRepGProp_Vinert::GetEpsilon, "If previously used methods containe Eps parameter gets actual relative error of the computation, else returns 1.0.");

// Enums

}