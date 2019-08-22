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
#include <TopoDS_Shape.hxx>
#include <HLRAlgo_Projector.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <Standard_Handle.hxx>
#include <HLRBRep_Data.hxx>
#include <HLRAlgo_EdgeIterator.hxx>
#include <StdPrs_HLRToolShape.hxx>

void bind_StdPrs_HLRToolShape(py::module &mod){

py::class_<StdPrs_HLRToolShape> cls_StdPrs_HLRToolShape(mod, "StdPrs_HLRToolShape", "None");

// Constructors
cls_StdPrs_HLRToolShape.def(py::init<const TopoDS_Shape &, const HLRAlgo_Projector &>(), py::arg("TheShape"), py::arg("TheProjector"));

// Fields

// Methods
// cls_StdPrs_HLRToolShape.def_static("operator new_", (void * (*)(size_t)) &StdPrs_HLRToolShape::operator new, "None", py::arg("theSize"));
// cls_StdPrs_HLRToolShape.def_static("operator delete_", (void (*)(void *)) &StdPrs_HLRToolShape::operator delete, "None", py::arg("theAddress"));
// cls_StdPrs_HLRToolShape.def_static("operator new[]_", (void * (*)(size_t)) &StdPrs_HLRToolShape::operator new[], "None", py::arg("theSize"));
// cls_StdPrs_HLRToolShape.def_static("operator delete[]_", (void (*)(void *)) &StdPrs_HLRToolShape::operator delete[], "None", py::arg("theAddress"));
// cls_StdPrs_HLRToolShape.def_static("operator new_", (void * (*)(size_t, void *)) &StdPrs_HLRToolShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdPrs_HLRToolShape.def_static("operator delete_", (void (*)(void *, void *)) &StdPrs_HLRToolShape::operator delete, "None", py::arg(""), py::arg(""));
cls_StdPrs_HLRToolShape.def("NbEdges", (Standard_Integer (StdPrs_HLRToolShape::*)() const) &StdPrs_HLRToolShape::NbEdges, "None");
cls_StdPrs_HLRToolShape.def("InitVisible", (void (StdPrs_HLRToolShape::*)(const Standard_Integer)) &StdPrs_HLRToolShape::InitVisible, "None", py::arg("EdgeNumber"));
cls_StdPrs_HLRToolShape.def("MoreVisible", (Standard_Boolean (StdPrs_HLRToolShape::*)() const) &StdPrs_HLRToolShape::MoreVisible, "None");
cls_StdPrs_HLRToolShape.def("NextVisible", (void (StdPrs_HLRToolShape::*)()) &StdPrs_HLRToolShape::NextVisible, "None");
cls_StdPrs_HLRToolShape.def("Visible", [](StdPrs_HLRToolShape &self, BRepAdaptor_Curve & TheEdge, Standard_Real & U1, Standard_Real & U2){ self.Visible(TheEdge, U1, U2); return std::tuple<Standard_Real &, Standard_Real &>(U1, U2); }, "None", py::arg("TheEdge"), py::arg("U1"), py::arg("U2"));
cls_StdPrs_HLRToolShape.def("InitHidden", (void (StdPrs_HLRToolShape::*)(const Standard_Integer)) &StdPrs_HLRToolShape::InitHidden, "None", py::arg("EdgeNumber"));
cls_StdPrs_HLRToolShape.def("MoreHidden", (Standard_Boolean (StdPrs_HLRToolShape::*)() const) &StdPrs_HLRToolShape::MoreHidden, "None");
cls_StdPrs_HLRToolShape.def("NextHidden", (void (StdPrs_HLRToolShape::*)()) &StdPrs_HLRToolShape::NextHidden, "None");
cls_StdPrs_HLRToolShape.def("Hidden", [](StdPrs_HLRToolShape &self, BRepAdaptor_Curve & TheEdge, Standard_Real & U1, Standard_Real & U2){ self.Hidden(TheEdge, U1, U2); return std::tuple<Standard_Real &, Standard_Real &>(U1, U2); }, "None", py::arg("TheEdge"), py::arg("U1"), py::arg("U2"));

// Enums

}