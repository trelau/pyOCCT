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
#include <BRepBuilderAPI_ModifyShape.hxx>
#include <Standard.hxx>
#include <gp_GTrsf.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BRepBuilderAPI_Collect.hxx>
#include <BRepBuilderAPI_GTransform.hxx>

void bind_BRepBuilderAPI_GTransform(py::module &mod){

py::class_<BRepBuilderAPI_GTransform, BRepBuilderAPI_ModifyShape> cls_BRepBuilderAPI_GTransform(mod, "BRepBuilderAPI_GTransform", "Geometric transformation on a shape. The transformation to be applied is defined as a gp_GTrsf transformation. It may be: - a transformation equivalent to a gp_Trsf transformation, the most common case: you should , however, use a BRepAPI_Transform object to perform this kind of transformation; or - an affinity, or - more generally, any type of point transformation which may be defined by a three row, four column matrix of transformation. In the last two cases, the underlying geometry of the following shapes may change: - a curve which supports an edge of the shape, or - a surface which supports a face of the shape; For example, a circle may be transformed into an ellipse when applying an affinity transformation. The transformation is applied to: - all the curves which support edges of the shape, and - all the surfaces which support faces of the shape. A GTransform object provides a framework for: - defining the geometric transformation to be applied, - implementing the transformation algorithm, and - consulting the result.");

// Constructors
cls_BRepBuilderAPI_GTransform.def(py::init<const gp_GTrsf &>(), py::arg("T"));
cls_BRepBuilderAPI_GTransform.def(py::init<const TopoDS_Shape &, const gp_GTrsf &>(), py::arg("S"), py::arg("T"));
cls_BRepBuilderAPI_GTransform.def(py::init<const TopoDS_Shape &, const gp_GTrsf &, const Standard_Boolean>(), py::arg("S"), py::arg("T"), py::arg("Copy"));

// Fields

// Methods
// cls_BRepBuilderAPI_GTransform.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_GTransform::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_GTransform.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_GTransform::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_GTransform.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_GTransform::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_GTransform.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_GTransform::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_GTransform.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_GTransform::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_GTransform.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_GTransform::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_GTransform.def("Perform", [](BRepBuilderAPI_GTransform &self, const TopoDS_Shape & a0) -> void { return self.Perform(a0); });
cls_BRepBuilderAPI_GTransform.def("Perform", (void (BRepBuilderAPI_GTransform::*)(const TopoDS_Shape &, const Standard_Boolean)) &BRepBuilderAPI_GTransform::Perform, "Applies the geometric transformation defined at the time of construction of this framework to the shape S. - If the transformation T is direct and isometric (i.e. if the determinant of the vectorial part of T is equal to 1.), and if Copy equals false (default value), the resulting shape is the same as the original but with a new location assigned to it. - In all other cases, the transformation is applied to a duplicate of S. Use the function Shape to access the result. Note: this framework can be reused to apply the same geometric transformation to other shapes: just specify them by calling the function Perform again.", py::arg("S"), py::arg("Copy"));
cls_BRepBuilderAPI_GTransform.def("Modified", (const TopTools_ListOfShape & (BRepBuilderAPI_GTransform::*)(const TopoDS_Shape &)) &BRepBuilderAPI_GTransform::Modified, "Returns the list of shapes modified from the shape <S>.", py::arg("S"));
cls_BRepBuilderAPI_GTransform.def("ModifiedShape", (TopoDS_Shape (BRepBuilderAPI_GTransform::*)(const TopoDS_Shape &) const) &BRepBuilderAPI_GTransform::ModifiedShape, "Returns the modified shape corresponding to <S>.", py::arg("S"));

// Enums

}