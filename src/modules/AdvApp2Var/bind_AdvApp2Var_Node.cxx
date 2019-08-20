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
#include <gp_XY.hxx>
#include <gp_Pnt.hxx>
#include <AdvApp2Var_Node.hxx>
#include <Standard_Handle.hxx>
#include <TColgp_HArray2OfPnt.hxx>
#include <TColStd_HArray2OfReal.hxx>

void bind_AdvApp2Var_Node(py::module &mod){

py::class_<AdvApp2Var_Node, std::unique_ptr<AdvApp2Var_Node>> cls_AdvApp2Var_Node(mod, "AdvApp2Var_Node", "used to store constraints on a (Ui,Vj) point");

// Constructors
cls_AdvApp2Var_Node.def(py::init<>());
cls_AdvApp2Var_Node.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("iu"), py::arg("iv"));
cls_AdvApp2Var_Node.def(py::init<const gp_XY &, const Standard_Integer, const Standard_Integer>(), py::arg("UV"), py::arg("iu"), py::arg("iv"));

// Fields

// Methods
// cls_AdvApp2Var_Node.def_static("operator new_", (void * (*)(size_t)) &AdvApp2Var_Node::operator new, "None", py::arg("theSize"));
// cls_AdvApp2Var_Node.def_static("operator delete_", (void (*)(void *)) &AdvApp2Var_Node::operator delete, "None", py::arg("theAddress"));
// cls_AdvApp2Var_Node.def_static("operator new[]_", (void * (*)(size_t)) &AdvApp2Var_Node::operator new[], "None", py::arg("theSize"));
// cls_AdvApp2Var_Node.def_static("operator delete[]_", (void (*)(void *)) &AdvApp2Var_Node::operator delete[], "None", py::arg("theAddress"));
// cls_AdvApp2Var_Node.def_static("operator new_", (void * (*)(size_t, void *)) &AdvApp2Var_Node::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AdvApp2Var_Node.def_static("operator delete_", (void (*)(void *, void *)) &AdvApp2Var_Node::operator delete, "None", py::arg(""), py::arg(""));
cls_AdvApp2Var_Node.def("Coord", (gp_XY (AdvApp2Var_Node::*)() const) &AdvApp2Var_Node::Coord, "None");
cls_AdvApp2Var_Node.def("SetCoord", (void (AdvApp2Var_Node::*)(const Standard_Real, const Standard_Real)) &AdvApp2Var_Node::SetCoord, "None", py::arg("x1"), py::arg("x2"));
cls_AdvApp2Var_Node.def("UOrder", (Standard_Integer (AdvApp2Var_Node::*)() const) &AdvApp2Var_Node::UOrder, "None");
cls_AdvApp2Var_Node.def("VOrder", (Standard_Integer (AdvApp2Var_Node::*)() const) &AdvApp2Var_Node::VOrder, "None");
cls_AdvApp2Var_Node.def("SetPoint", (void (AdvApp2Var_Node::*)(const Standard_Integer, const Standard_Integer, const gp_Pnt &)) &AdvApp2Var_Node::SetPoint, "None", py::arg("iu"), py::arg("iv"), py::arg("Cte"));
cls_AdvApp2Var_Node.def("Point", (gp_Pnt (AdvApp2Var_Node::*)(const Standard_Integer, const Standard_Integer) const) &AdvApp2Var_Node::Point, "None", py::arg("iu"), py::arg("iv"));
cls_AdvApp2Var_Node.def("SetError", (void (AdvApp2Var_Node::*)(const Standard_Integer, const Standard_Integer, const Standard_Real)) &AdvApp2Var_Node::SetError, "None", py::arg("iu"), py::arg("iv"), py::arg("error"));
cls_AdvApp2Var_Node.def("Error", (Standard_Real (AdvApp2Var_Node::*)(const Standard_Integer, const Standard_Integer) const) &AdvApp2Var_Node::Error, "None", py::arg("iu"), py::arg("iv"));

// Enums

}