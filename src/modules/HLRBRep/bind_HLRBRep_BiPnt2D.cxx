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
#include <gp_XY.hxx>
#include <gp_Pnt2d.hxx>
#include <HLRBRep_BiPnt2D.hxx>

void bind_HLRBRep_BiPnt2D(py::module &mod){

py::class_<HLRBRep_BiPnt2D, std::unique_ptr<HLRBRep_BiPnt2D, Deleter<HLRBRep_BiPnt2D>>> cls_HLRBRep_BiPnt2D(mod, "HLRBRep_BiPnt2D", "Contains the colors of a shape.");

// Constructors
cls_HLRBRep_BiPnt2D.def(py::init<>());
cls_HLRBRep_BiPnt2D.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("x1"), py::arg("y1"), py::arg("x2"), py::arg("y2"), py::arg("S"), py::arg("reg1"), py::arg("regn"), py::arg("outl"), py::arg("intl"));
cls_HLRBRep_BiPnt2D.def(py::init<const gp_XY &, const gp_XY &, const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("thePoint1"), py::arg("thePoint2"), py::arg("S"), py::arg("reg1"), py::arg("regn"), py::arg("outl"), py::arg("intl"));

// Fields

// Methods
// cls_HLRBRep_BiPnt2D.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_BiPnt2D::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_BiPnt2D.def_static("operator delete_", (void (*)(void *)) &HLRBRep_BiPnt2D::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_BiPnt2D.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_BiPnt2D::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_BiPnt2D.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_BiPnt2D::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_BiPnt2D.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_BiPnt2D::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_BiPnt2D.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_BiPnt2D::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_BiPnt2D.def("P1", (const gp_Pnt2d & (HLRBRep_BiPnt2D::*)() const) &HLRBRep_BiPnt2D::P1, "None");
cls_HLRBRep_BiPnt2D.def("P2", (const gp_Pnt2d & (HLRBRep_BiPnt2D::*)() const) &HLRBRep_BiPnt2D::P2, "None");
cls_HLRBRep_BiPnt2D.def("Shape", (const TopoDS_Shape & (HLRBRep_BiPnt2D::*)() const) &HLRBRep_BiPnt2D::Shape, "None");
cls_HLRBRep_BiPnt2D.def("Shape", (void (HLRBRep_BiPnt2D::*)(const TopoDS_Shape &)) &HLRBRep_BiPnt2D::Shape, "None", py::arg("S"));
cls_HLRBRep_BiPnt2D.def("Rg1Line", (Standard_Boolean (HLRBRep_BiPnt2D::*)() const) &HLRBRep_BiPnt2D::Rg1Line, "None");
cls_HLRBRep_BiPnt2D.def("Rg1Line", (void (HLRBRep_BiPnt2D::*)(const Standard_Boolean)) &HLRBRep_BiPnt2D::Rg1Line, "None", py::arg("B"));
cls_HLRBRep_BiPnt2D.def("RgNLine", (Standard_Boolean (HLRBRep_BiPnt2D::*)() const) &HLRBRep_BiPnt2D::RgNLine, "None");
cls_HLRBRep_BiPnt2D.def("RgNLine", (void (HLRBRep_BiPnt2D::*)(const Standard_Boolean)) &HLRBRep_BiPnt2D::RgNLine, "None", py::arg("B"));
cls_HLRBRep_BiPnt2D.def("OutLine", (Standard_Boolean (HLRBRep_BiPnt2D::*)() const) &HLRBRep_BiPnt2D::OutLine, "None");
cls_HLRBRep_BiPnt2D.def("OutLine", (void (HLRBRep_BiPnt2D::*)(const Standard_Boolean)) &HLRBRep_BiPnt2D::OutLine, "None", py::arg("B"));
cls_HLRBRep_BiPnt2D.def("IntLine", (Standard_Boolean (HLRBRep_BiPnt2D::*)() const) &HLRBRep_BiPnt2D::IntLine, "None");
cls_HLRBRep_BiPnt2D.def("IntLine", (void (HLRBRep_BiPnt2D::*)(const Standard_Boolean)) &HLRBRep_BiPnt2D::IntLine, "None", py::arg("B"));

// Enums

}