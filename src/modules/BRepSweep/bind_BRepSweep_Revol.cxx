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
#include <gp_Ax1.hxx>
#include <Standard_TypeDef.hxx>
#include <Sweep_NumShape.hxx>
#include <TopLoc_Location.hxx>
#include <BRepSweep_Rotation.hxx>
#include <BRepSweep_Revol.hxx>

void bind_BRepSweep_Revol(py::module &mod){

py::class_<BRepSweep_Revol> cls_BRepSweep_Revol(mod, "BRepSweep_Revol", "Provides natural constructors to build BRepSweep rotated swept Primitives.");

// Constructors
cls_BRepSweep_Revol.def(py::init<const TopoDS_Shape &, const gp_Ax1 &, const Standard_Real>(), py::arg("S"), py::arg("A"), py::arg("D"));
cls_BRepSweep_Revol.def(py::init<const TopoDS_Shape &, const gp_Ax1 &, const Standard_Real, const Standard_Boolean>(), py::arg("S"), py::arg("A"), py::arg("D"), py::arg("C"));
cls_BRepSweep_Revol.def(py::init<const TopoDS_Shape &, const gp_Ax1 &>(), py::arg("S"), py::arg("A"));
cls_BRepSweep_Revol.def(py::init<const TopoDS_Shape &, const gp_Ax1 &, const Standard_Boolean>(), py::arg("S"), py::arg("A"), py::arg("C"));

// Fields

// Methods
// cls_BRepSweep_Revol.def_static("operator new_", (void * (*)(size_t)) &BRepSweep_Revol::operator new, "None", py::arg("theSize"));
// cls_BRepSweep_Revol.def_static("operator delete_", (void (*)(void *)) &BRepSweep_Revol::operator delete, "None", py::arg("theAddress"));
// cls_BRepSweep_Revol.def_static("operator new[]_", (void * (*)(size_t)) &BRepSweep_Revol::operator new[], "None", py::arg("theSize"));
// cls_BRepSweep_Revol.def_static("operator delete[]_", (void (*)(void *)) &BRepSweep_Revol::operator delete[], "None", py::arg("theAddress"));
// cls_BRepSweep_Revol.def_static("operator new_", (void * (*)(size_t, void *)) &BRepSweep_Revol::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepSweep_Revol.def_static("operator delete_", (void (*)(void *, void *)) &BRepSweep_Revol::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepSweep_Revol.def("Shape", (TopoDS_Shape (BRepSweep_Revol::*)()) &BRepSweep_Revol::Shape, "Returns the TopoDS Shape attached to the Revol.");
cls_BRepSweep_Revol.def("Shape", (TopoDS_Shape (BRepSweep_Revol::*)(const TopoDS_Shape &)) &BRepSweep_Revol::Shape, "Returns the TopoDS Shape generated with aGenS (subShape of the generating shape).", py::arg("aGenS"));
cls_BRepSweep_Revol.def("FirstShape", (TopoDS_Shape (BRepSweep_Revol::*)()) &BRepSweep_Revol::FirstShape, "Returns the first shape of the revol (coinciding with the generating shape).");
cls_BRepSweep_Revol.def("FirstShape", (TopoDS_Shape (BRepSweep_Revol::*)(const TopoDS_Shape &)) &BRepSweep_Revol::FirstShape, "Returns the first shape of the revol (coinciding with the generating shape).", py::arg("aGenS"));
cls_BRepSweep_Revol.def("LastShape", (TopoDS_Shape (BRepSweep_Revol::*)()) &BRepSweep_Revol::LastShape, "Returns the TopoDS Shape of the top of the prism.");
cls_BRepSweep_Revol.def("LastShape", (TopoDS_Shape (BRepSweep_Revol::*)(const TopoDS_Shape &)) &BRepSweep_Revol::LastShape, "Returns the TopoDS Shape of the top of the prism. generated with aGenS (subShape of the generating shape).", py::arg("aGenS"));
cls_BRepSweep_Revol.def("Axe", (gp_Ax1 (BRepSweep_Revol::*)() const) &BRepSweep_Revol::Axe, "returns the axis");
cls_BRepSweep_Revol.def("Angle", (Standard_Real (BRepSweep_Revol::*)() const) &BRepSweep_Revol::Angle, "returns the angle.");

// Enums

}