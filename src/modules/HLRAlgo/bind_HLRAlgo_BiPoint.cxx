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
#include <Standard_TypeDef.hxx>
#include <gp_XYZ.hxx>
#include <gp_XY.hxx>
#include <Standard.hxx>
#include <HLRAlgo_BiPoint.hxx>

void bind_HLRAlgo_BiPoint(py::module &mod){

py::class_<HLRAlgo_BiPoint, std::unique_ptr<HLRAlgo_BiPoint>> cls_HLRAlgo_BiPoint(mod, "HLRAlgo_BiPoint", "None");

// Constructors
cls_HLRAlgo_BiPoint.def(py::init<>());
cls_HLRAlgo_BiPoint.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("X1"), py::arg("Y1"), py::arg("Z1"), py::arg("X2"), py::arg("Y2"), py::arg("Z2"), py::arg("XT1"), py::arg("YT1"), py::arg("ZT1"), py::arg("XT2"), py::arg("YT2"), py::arg("ZT2"), py::arg("Index"), py::arg("reg1"), py::arg("regn"), py::arg("outl"), py::arg("intl"));
cls_HLRAlgo_BiPoint.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer>(), py::arg("X1"), py::arg("Y1"), py::arg("Z1"), py::arg("X2"), py::arg("Y2"), py::arg("Z2"), py::arg("XT1"), py::arg("YT1"), py::arg("ZT1"), py::arg("XT2"), py::arg("YT2"), py::arg("ZT2"), py::arg("Index"), py::arg("flag"));
cls_HLRAlgo_BiPoint.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("X1"), py::arg("Y1"), py::arg("Z1"), py::arg("X2"), py::arg("Y2"), py::arg("Z2"), py::arg("XT1"), py::arg("YT1"), py::arg("ZT1"), py::arg("XT2"), py::arg("YT2"), py::arg("ZT2"), py::arg("Index"), py::arg("i1"), py::arg("i1p1"), py::arg("i1p2"), py::arg("reg1"), py::arg("regn"), py::arg("outl"), py::arg("intl"));
cls_HLRAlgo_BiPoint.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("X1"), py::arg("Y1"), py::arg("Z1"), py::arg("X2"), py::arg("Y2"), py::arg("Z2"), py::arg("XT1"), py::arg("YT1"), py::arg("ZT1"), py::arg("XT2"), py::arg("YT2"), py::arg("ZT2"), py::arg("Index"), py::arg("i1"), py::arg("i1p1"), py::arg("i1p2"), py::arg("flag"));
cls_HLRAlgo_BiPoint.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("X1"), py::arg("Y1"), py::arg("Z1"), py::arg("X2"), py::arg("Y2"), py::arg("Z2"), py::arg("XT1"), py::arg("YT1"), py::arg("ZT1"), py::arg("XT2"), py::arg("YT2"), py::arg("ZT2"), py::arg("Index"), py::arg("i1"), py::arg("i1p1"), py::arg("i1p2"), py::arg("i2"), py::arg("i2p1"), py::arg("i2p2"), py::arg("reg1"), py::arg("regn"), py::arg("outl"), py::arg("intl"));
cls_HLRAlgo_BiPoint.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("X1"), py::arg("Y1"), py::arg("Z1"), py::arg("X2"), py::arg("Y2"), py::arg("Z2"), py::arg("XT1"), py::arg("YT1"), py::arg("ZT1"), py::arg("XT2"), py::arg("YT2"), py::arg("ZT2"), py::arg("Index"), py::arg("i1"), py::arg("i1p1"), py::arg("i1p2"), py::arg("i2"), py::arg("i2p1"), py::arg("i2p2"), py::arg("flag"));

// Fields

// Methods
// cls_HLRAlgo_BiPoint.def_static("operator new_", (void * (*)(size_t)) &HLRAlgo_BiPoint::operator new, "None", py::arg("theSize"));
// cls_HLRAlgo_BiPoint.def_static("operator delete_", (void (*)(void *)) &HLRAlgo_BiPoint::operator delete, "None", py::arg("theAddress"));
// cls_HLRAlgo_BiPoint.def_static("operator new[]_", (void * (*)(size_t)) &HLRAlgo_BiPoint::operator new[], "None", py::arg("theSize"));
// cls_HLRAlgo_BiPoint.def_static("operator delete[]_", (void (*)(void *)) &HLRAlgo_BiPoint::operator delete[], "None", py::arg("theAddress"));
// cls_HLRAlgo_BiPoint.def_static("operator new_", (void * (*)(size_t, void *)) &HLRAlgo_BiPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRAlgo_BiPoint.def_static("operator delete_", (void (*)(void *, void *)) &HLRAlgo_BiPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRAlgo_BiPoint.def("Rg1Line", (Standard_Boolean (HLRAlgo_BiPoint::*)() const) &HLRAlgo_BiPoint::Rg1Line, "None");
cls_HLRAlgo_BiPoint.def("Rg1Line", (void (HLRAlgo_BiPoint::*)(const Standard_Boolean)) &HLRAlgo_BiPoint::Rg1Line, "None", py::arg("B"));
cls_HLRAlgo_BiPoint.def("RgNLine", (Standard_Boolean (HLRAlgo_BiPoint::*)() const) &HLRAlgo_BiPoint::RgNLine, "None");
cls_HLRAlgo_BiPoint.def("RgNLine", (void (HLRAlgo_BiPoint::*)(const Standard_Boolean)) &HLRAlgo_BiPoint::RgNLine, "None", py::arg("B"));
cls_HLRAlgo_BiPoint.def("OutLine", (Standard_Boolean (HLRAlgo_BiPoint::*)() const) &HLRAlgo_BiPoint::OutLine, "None");
cls_HLRAlgo_BiPoint.def("OutLine", (void (HLRAlgo_BiPoint::*)(const Standard_Boolean)) &HLRAlgo_BiPoint::OutLine, "None", py::arg("B"));
cls_HLRAlgo_BiPoint.def("IntLine", (Standard_Boolean (HLRAlgo_BiPoint::*)() const) &HLRAlgo_BiPoint::IntLine, "None");
cls_HLRAlgo_BiPoint.def("IntLine", (void (HLRAlgo_BiPoint::*)(const Standard_Boolean)) &HLRAlgo_BiPoint::IntLine, "None", py::arg("B"));
cls_HLRAlgo_BiPoint.def("Hidden", (Standard_Boolean (HLRAlgo_BiPoint::*)() const) &HLRAlgo_BiPoint::Hidden, "None");
cls_HLRAlgo_BiPoint.def("Hidden", (void (HLRAlgo_BiPoint::*)(const Standard_Boolean)) &HLRAlgo_BiPoint::Hidden, "None", py::arg("B"));
cls_HLRAlgo_BiPoint.def("Indices", (HLRAlgo_BiPoint::IndicesT & (HLRAlgo_BiPoint::*)()) &HLRAlgo_BiPoint::Indices, "None");
cls_HLRAlgo_BiPoint.def("Points", (HLRAlgo_BiPoint::PointsT & (HLRAlgo_BiPoint::*)()) &HLRAlgo_BiPoint::Points, "None");

// Enums

}