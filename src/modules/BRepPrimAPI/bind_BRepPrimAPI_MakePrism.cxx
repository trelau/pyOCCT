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
#include <BRepPrimAPI_MakeSweep.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <gp_Vec.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Dir.hxx>
#include <BRepSweep_Prism.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BRepPrimAPI_MakePrism.hxx>

void bind_BRepPrimAPI_MakePrism(py::module &mod){

py::class_<BRepPrimAPI_MakePrism, BRepPrimAPI_MakeSweep> cls_BRepPrimAPI_MakePrism(mod, "BRepPrimAPI_MakePrism", "Describes functions to build linear swept topologies, called prisms. A prism is defined by: - a basis shape, which is swept, and - a sweeping direction, which is: - a vector for finite prisms, or - a direction for infinite or semi-infinite prisms. The basis shape must not contain any solids. The profile generates objects according to the following rules: - Vertices generate Edges - Edges generate Faces. - Wires generate Shells. - Faces generate Solids. - Shells generate Composite Solids A MakePrism object provides a framework for: - defining the construction of a prism, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_BRepPrimAPI_MakePrism.def(py::init<const TopoDS_Shape &, const gp_Vec &>(), py::arg("S"), py::arg("V"));
cls_BRepPrimAPI_MakePrism.def(py::init<const TopoDS_Shape &, const gp_Vec &, const Standard_Boolean>(), py::arg("S"), py::arg("V"), py::arg("Copy"));
cls_BRepPrimAPI_MakePrism.def(py::init<const TopoDS_Shape &, const gp_Vec &, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("V"), py::arg("Copy"), py::arg("Canonize"));
cls_BRepPrimAPI_MakePrism.def(py::init<const TopoDS_Shape &, const gp_Dir &>(), py::arg("S"), py::arg("D"));
cls_BRepPrimAPI_MakePrism.def(py::init<const TopoDS_Shape &, const gp_Dir &, const Standard_Boolean>(), py::arg("S"), py::arg("D"), py::arg("Inf"));
cls_BRepPrimAPI_MakePrism.def(py::init<const TopoDS_Shape &, const gp_Dir &, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("D"), py::arg("Inf"), py::arg("Copy"));
cls_BRepPrimAPI_MakePrism.def(py::init<const TopoDS_Shape &, const gp_Dir &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("D"), py::arg("Inf"), py::arg("Copy"), py::arg("Canonize"));

// Fields

// Methods
// cls_BRepPrimAPI_MakePrism.def_static("operator new_", (void * (*)(size_t)) &BRepPrimAPI_MakePrism::operator new, "None", py::arg("theSize"));
// cls_BRepPrimAPI_MakePrism.def_static("operator delete_", (void (*)(void *)) &BRepPrimAPI_MakePrism::operator delete, "None", py::arg("theAddress"));
// cls_BRepPrimAPI_MakePrism.def_static("operator new[]_", (void * (*)(size_t)) &BRepPrimAPI_MakePrism::operator new[], "None", py::arg("theSize"));
// cls_BRepPrimAPI_MakePrism.def_static("operator delete[]_", (void (*)(void *)) &BRepPrimAPI_MakePrism::operator delete[], "None", py::arg("theAddress"));
// cls_BRepPrimAPI_MakePrism.def_static("operator new_", (void * (*)(size_t, void *)) &BRepPrimAPI_MakePrism::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepPrimAPI_MakePrism.def_static("operator delete_", (void (*)(void *, void *)) &BRepPrimAPI_MakePrism::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepPrimAPI_MakePrism.def("Prism", (const BRepSweep_Prism & (BRepPrimAPI_MakePrism::*)() const) &BRepPrimAPI_MakePrism::Prism, "Returns the internal sweeping algorithm.");
cls_BRepPrimAPI_MakePrism.def("Build", (void (BRepPrimAPI_MakePrism::*)()) &BRepPrimAPI_MakePrism::Build, "Builds the resulting shape (redefined from MakeShape).");
cls_BRepPrimAPI_MakePrism.def("FirstShape", (TopoDS_Shape (BRepPrimAPI_MakePrism::*)()) &BRepPrimAPI_MakePrism::FirstShape, "Returns the TopoDS Shape of the bottom of the prism.");
cls_BRepPrimAPI_MakePrism.def("LastShape", (TopoDS_Shape (BRepPrimAPI_MakePrism::*)()) &BRepPrimAPI_MakePrism::LastShape, "Returns the TopoDS Shape of the top of the prism. In the case of a finite prism, FirstShape returns the basis of the prism, in other words, S if Copy is false; otherwise, the copy of S belonging to the prism. LastShape returns the copy of S translated by V at the time of construction.");
cls_BRepPrimAPI_MakePrism.def("Generated", (const TopTools_ListOfShape & (BRepPrimAPI_MakePrism::*)(const TopoDS_Shape &)) &BRepPrimAPI_MakePrism::Generated, "Returns ListOfShape from TopTools.", py::arg("S"));
cls_BRepPrimAPI_MakePrism.def("FirstShape", (TopoDS_Shape (BRepPrimAPI_MakePrism::*)(const TopoDS_Shape &)) &BRepPrimAPI_MakePrism::FirstShape, "Returns the TopoDS Shape of the bottom of the prism. generated with theShape (subShape of the generating shape).", py::arg("theShape"));
cls_BRepPrimAPI_MakePrism.def("LastShape", (TopoDS_Shape (BRepPrimAPI_MakePrism::*)(const TopoDS_Shape &)) &BRepPrimAPI_MakePrism::LastShape, "Returns the TopoDS Shape of the top of the prism. generated with theShape (subShape of the generating shape).", py::arg("theShape"));

// Enums

}