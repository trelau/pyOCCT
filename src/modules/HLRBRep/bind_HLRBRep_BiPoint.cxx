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
#include <TopoDS_Shape.hxx>
#include <gp_Pnt.hxx>
#include <HLRBRep_BiPoint.hxx>

void bind_HLRBRep_BiPoint(py::module &mod){

py::class_<HLRBRep_BiPoint> cls_HLRBRep_BiPoint(mod, "HLRBRep_BiPoint", "Contains the colors of a shape.");

// Constructors
cls_HLRBRep_BiPoint.def(py::init<>());
cls_HLRBRep_BiPoint.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("x1"), py::arg("y1"), py::arg("z1"), py::arg("x2"), py::arg("y2"), py::arg("z2"), py::arg("S"), py::arg("reg1"), py::arg("regn"), py::arg("outl"), py::arg("intl"));

// Fields

// Methods
// cls_HLRBRep_BiPoint.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_BiPoint::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_BiPoint.def_static("operator delete_", (void (*)(void *)) &HLRBRep_BiPoint::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_BiPoint.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_BiPoint::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_BiPoint.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_BiPoint::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_BiPoint.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_BiPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_BiPoint.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_BiPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_BiPoint.def("P1", (const gp_Pnt & (HLRBRep_BiPoint::*)() const) &HLRBRep_BiPoint::P1, "None");
cls_HLRBRep_BiPoint.def("P2", (const gp_Pnt & (HLRBRep_BiPoint::*)() const) &HLRBRep_BiPoint::P2, "None");
cls_HLRBRep_BiPoint.def("Shape", (const TopoDS_Shape & (HLRBRep_BiPoint::*)() const) &HLRBRep_BiPoint::Shape, "None");
cls_HLRBRep_BiPoint.def("Shape", (void (HLRBRep_BiPoint::*)(const TopoDS_Shape &)) &HLRBRep_BiPoint::Shape, "None", py::arg("S"));
cls_HLRBRep_BiPoint.def("Rg1Line", (Standard_Boolean (HLRBRep_BiPoint::*)() const) &HLRBRep_BiPoint::Rg1Line, "None");
cls_HLRBRep_BiPoint.def("Rg1Line", (void (HLRBRep_BiPoint::*)(const Standard_Boolean)) &HLRBRep_BiPoint::Rg1Line, "None", py::arg("B"));
cls_HLRBRep_BiPoint.def("RgNLine", (Standard_Boolean (HLRBRep_BiPoint::*)() const) &HLRBRep_BiPoint::RgNLine, "None");
cls_HLRBRep_BiPoint.def("RgNLine", (void (HLRBRep_BiPoint::*)(const Standard_Boolean)) &HLRBRep_BiPoint::RgNLine, "None", py::arg("B"));
cls_HLRBRep_BiPoint.def("OutLine", (Standard_Boolean (HLRBRep_BiPoint::*)() const) &HLRBRep_BiPoint::OutLine, "None");
cls_HLRBRep_BiPoint.def("OutLine", (void (HLRBRep_BiPoint::*)(const Standard_Boolean)) &HLRBRep_BiPoint::OutLine, "None", py::arg("B"));
cls_HLRBRep_BiPoint.def("IntLine", (Standard_Boolean (HLRBRep_BiPoint::*)() const) &HLRBRep_BiPoint::IntLine, "None");
cls_HLRBRep_BiPoint.def("IntLine", (void (HLRBRep_BiPoint::*)(const Standard_Boolean)) &HLRBRep_BiPoint::IntLine, "None", py::arg("B"));

// Enums

}