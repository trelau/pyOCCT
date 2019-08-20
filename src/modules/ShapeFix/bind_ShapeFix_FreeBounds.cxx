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
#include <Standard_TypeDef.hxx>
#include <TopoDS_Compound.hxx>
#include <ShapeFix_FreeBounds.hxx>

void bind_ShapeFix_FreeBounds(py::module &mod){

py::class_<ShapeFix_FreeBounds, std::unique_ptr<ShapeFix_FreeBounds>> cls_ShapeFix_FreeBounds(mod, "ShapeFix_FreeBounds", "This class is intended to output free bounds of the shape (free bounds are the wires consisting of edges referenced by the only face). For building free bounds it uses ShapeAnalysis_FreeBounds class. This class complements it with the feature to reduce the number of open wires. This reduction is performed with help of connecting several adjacent open wires one to another what can lead to: 1. making an open wire with greater length out of several open wires 2. making closed wire out of several open wires");

// Constructors
cls_ShapeFix_FreeBounds.def(py::init<>());
cls_ShapeFix_FreeBounds.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("shape"), py::arg("sewtoler"), py::arg("closetoler"), py::arg("splitclosed"), py::arg("splitopen"));
cls_ShapeFix_FreeBounds.def(py::init<const TopoDS_Shape &, const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("shape"), py::arg("closetoler"), py::arg("splitclosed"), py::arg("splitopen"));

// Fields

// Methods
// cls_ShapeFix_FreeBounds.def_static("operator new_", (void * (*)(size_t)) &ShapeFix_FreeBounds::operator new, "None", py::arg("theSize"));
// cls_ShapeFix_FreeBounds.def_static("operator delete_", (void (*)(void *)) &ShapeFix_FreeBounds::operator delete, "None", py::arg("theAddress"));
// cls_ShapeFix_FreeBounds.def_static("operator new[]_", (void * (*)(size_t)) &ShapeFix_FreeBounds::operator new[], "None", py::arg("theSize"));
// cls_ShapeFix_FreeBounds.def_static("operator delete[]_", (void (*)(void *)) &ShapeFix_FreeBounds::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeFix_FreeBounds.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeFix_FreeBounds::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeFix_FreeBounds.def_static("operator delete_", (void (*)(void *, void *)) &ShapeFix_FreeBounds::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeFix_FreeBounds.def("GetClosedWires", (const TopoDS_Compound & (ShapeFix_FreeBounds::*)() const) &ShapeFix_FreeBounds::GetClosedWires, "Returns compound of closed wires out of free edges.");
cls_ShapeFix_FreeBounds.def("GetOpenWires", (const TopoDS_Compound & (ShapeFix_FreeBounds::*)() const) &ShapeFix_FreeBounds::GetOpenWires, "Returns compound of open wires out of free edges.");
cls_ShapeFix_FreeBounds.def("GetShape", (const TopoDS_Shape & (ShapeFix_FreeBounds::*)() const) &ShapeFix_FreeBounds::GetShape, "Returns modified source shape.");

// Enums

}