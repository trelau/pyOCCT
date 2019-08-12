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
#include <gp_Trsf.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopLoc_Location.hxx>
#include <BRepBuilderAPI_Transform.hxx>

void bind_BRepBuilderAPI_Transform(py::module &mod){

py::class_<BRepBuilderAPI_Transform, std::unique_ptr<BRepBuilderAPI_Transform, Deleter<BRepBuilderAPI_Transform>>, BRepBuilderAPI_ModifyShape> cls_BRepBuilderAPI_Transform(mod, "BRepBuilderAPI_Transform", "Geometric transformation on a shape. The transformation to be applied is defined as a gp_Trsf transformation, i.e. a transformation which does not modify the underlying geometry of shapes. The transformation is applied to: - all curves which support edges of a shape, and - all surfaces which support its faces. A Transform object provides a framework for: - defining the geometric transformation to be applied, - implementing the transformation algorithm, and - consulting the results.");

// Constructors
cls_BRepBuilderAPI_Transform.def(py::init<const gp_Trsf &>(), py::arg("T"));
cls_BRepBuilderAPI_Transform.def(py::init<const TopoDS_Shape &, const gp_Trsf &>(), py::arg("S"), py::arg("T"));
cls_BRepBuilderAPI_Transform.def(py::init<const TopoDS_Shape &, const gp_Trsf &, const Standard_Boolean>(), py::arg("S"), py::arg("T"), py::arg("Copy"));

// Fields

// Methods
// cls_BRepBuilderAPI_Transform.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_Transform::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_Transform.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_Transform::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_Transform.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_Transform::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_Transform.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_Transform::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_Transform.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_Transform::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_Transform.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_Transform::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_Transform.def("Perform", [](BRepBuilderAPI_Transform &self, const TopoDS_Shape & a0) -> void { return self.Perform(a0); });
cls_BRepBuilderAPI_Transform.def("Perform", (void (BRepBuilderAPI_Transform::*)(const TopoDS_Shape &, const Standard_Boolean)) &BRepBuilderAPI_Transform::Perform, "pplies the geometric transformation defined at the time of construction of this framework to the shape S. - If the transformation T is direct and isometric, in other words, if the determinant of the vectorial part of T is equal to 1., and if Copy equals false (the default value), the resulting shape is the same as the original but with a new location assigned to it. - In all other cases, the transformation is applied to a duplicate of S. Use the function Shape to access the result. Note: this framework can be reused to apply the same geometric transformation to other shapes. You only need to specify them by calling the function Perform again.", py::arg("S"), py::arg("Copy"));
cls_BRepBuilderAPI_Transform.def("ModifiedShape", (TopoDS_Shape (BRepBuilderAPI_Transform::*)(const TopoDS_Shape &) const) &BRepBuilderAPI_Transform::ModifiedShape, "Returns the modified shape corresponding to <S>.", py::arg("S"));
cls_BRepBuilderAPI_Transform.def("Modified", (const TopTools_ListOfShape & (BRepBuilderAPI_Transform::*)(const TopoDS_Shape &)) &BRepBuilderAPI_Transform::Modified, "Returns the list of shapes modified from the shape <S>.", py::arg("S"));

// Enums

}