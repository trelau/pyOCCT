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
#include <gp_Vec.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Dir.hxx>
#include <Sweep_NumShape.hxx>
#include <TopLoc_Location.hxx>
#include <BRepSweep_Translation.hxx>
#include <BRepSweep_Prism.hxx>

void bind_BRepSweep_Prism(py::module &mod){

py::class_<BRepSweep_Prism, std::unique_ptr<BRepSweep_Prism>> cls_BRepSweep_Prism(mod, "BRepSweep_Prism", "Provides natural constructors to build BRepSweep translated swept Primitives.");

// Constructors
cls_BRepSweep_Prism.def(py::init<const TopoDS_Shape &, const gp_Vec &>(), py::arg("S"), py::arg("V"));
cls_BRepSweep_Prism.def(py::init<const TopoDS_Shape &, const gp_Vec &, const Standard_Boolean>(), py::arg("S"), py::arg("V"), py::arg("Copy"));
cls_BRepSweep_Prism.def(py::init<const TopoDS_Shape &, const gp_Vec &, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("V"), py::arg("Copy"), py::arg("Canonize"));
cls_BRepSweep_Prism.def(py::init<const TopoDS_Shape &, const gp_Dir &>(), py::arg("S"), py::arg("D"));
cls_BRepSweep_Prism.def(py::init<const TopoDS_Shape &, const gp_Dir &, const Standard_Boolean>(), py::arg("S"), py::arg("D"), py::arg("Inf"));
cls_BRepSweep_Prism.def(py::init<const TopoDS_Shape &, const gp_Dir &, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("D"), py::arg("Inf"), py::arg("Copy"));
cls_BRepSweep_Prism.def(py::init<const TopoDS_Shape &, const gp_Dir &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("D"), py::arg("Inf"), py::arg("Copy"), py::arg("Canonize"));

// Fields

// Methods
// cls_BRepSweep_Prism.def_static("operator new_", (void * (*)(size_t)) &BRepSweep_Prism::operator new, "None", py::arg("theSize"));
// cls_BRepSweep_Prism.def_static("operator delete_", (void (*)(void *)) &BRepSweep_Prism::operator delete, "None", py::arg("theAddress"));
// cls_BRepSweep_Prism.def_static("operator new[]_", (void * (*)(size_t)) &BRepSweep_Prism::operator new[], "None", py::arg("theSize"));
// cls_BRepSweep_Prism.def_static("operator delete[]_", (void (*)(void *)) &BRepSweep_Prism::operator delete[], "None", py::arg("theAddress"));
// cls_BRepSweep_Prism.def_static("operator new_", (void * (*)(size_t, void *)) &BRepSweep_Prism::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepSweep_Prism.def_static("operator delete_", (void (*)(void *, void *)) &BRepSweep_Prism::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepSweep_Prism.def("Shape", (TopoDS_Shape (BRepSweep_Prism::*)()) &BRepSweep_Prism::Shape, "Returns the TopoDS Shape attached to the prism.");
cls_BRepSweep_Prism.def("Shape", (TopoDS_Shape (BRepSweep_Prism::*)(const TopoDS_Shape &)) &BRepSweep_Prism::Shape, "Returns the TopoDS Shape generated with aGenS (subShape of the generating shape).", py::arg("aGenS"));
cls_BRepSweep_Prism.def("FirstShape", (TopoDS_Shape (BRepSweep_Prism::*)()) &BRepSweep_Prism::FirstShape, "Returns the TopoDS Shape of the bottom of the prism.");
cls_BRepSweep_Prism.def("FirstShape", (TopoDS_Shape (BRepSweep_Prism::*)(const TopoDS_Shape &)) &BRepSweep_Prism::FirstShape, "Returns the TopoDS Shape of the bottom of the prism. generated with aGenS (subShape of the generating shape).", py::arg("aGenS"));
cls_BRepSweep_Prism.def("LastShape", (TopoDS_Shape (BRepSweep_Prism::*)()) &BRepSweep_Prism::LastShape, "Returns the TopoDS Shape of the top of the prism.");
cls_BRepSweep_Prism.def("LastShape", (TopoDS_Shape (BRepSweep_Prism::*)(const TopoDS_Shape &)) &BRepSweep_Prism::LastShape, "Returns the TopoDS Shape of the top of the prism. generated with aGenS (subShape of the generating shape).", py::arg("aGenS"));
cls_BRepSweep_Prism.def("Vec", (gp_Vec (BRepSweep_Prism::*)() const) &BRepSweep_Prism::Vec, "Returns the Vector of the Prism, if it is an infinite prism the Vec is unitar.");

// Enums

}