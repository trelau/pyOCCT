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
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepBuilderAPI_Copy.hxx>

void bind_BRepBuilderAPI_Copy(py::module &mod){

py::class_<BRepBuilderAPI_Copy, std::unique_ptr<BRepBuilderAPI_Copy>, BRepBuilderAPI_ModifyShape> cls_BRepBuilderAPI_Copy(mod, "BRepBuilderAPI_Copy", "Duplication of a shape. A Copy object provides a framework for: - defining the construction of a duplicate shape, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_BRepBuilderAPI_Copy.def(py::init<>());
cls_BRepBuilderAPI_Copy.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
cls_BRepBuilderAPI_Copy.def(py::init<const TopoDS_Shape &, const Standard_Boolean>(), py::arg("S"), py::arg("copyGeom"));
cls_BRepBuilderAPI_Copy.def(py::init<const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("copyGeom"), py::arg("copyMesh"));

// Fields

// Methods
// cls_BRepBuilderAPI_Copy.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_Copy::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_Copy.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_Copy::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_Copy.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_Copy::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_Copy.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_Copy::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_Copy.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_Copy::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_Copy.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_Copy::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_Copy.def("Perform", [](BRepBuilderAPI_Copy &self, const TopoDS_Shape & a0) -> void { return self.Perform(a0); });
cls_BRepBuilderAPI_Copy.def("Perform", [](BRepBuilderAPI_Copy &self, const TopoDS_Shape & a0, const Standard_Boolean a1) -> void { return self.Perform(a0, a1); });
cls_BRepBuilderAPI_Copy.def("Perform", (void (BRepBuilderAPI_Copy::*)(const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean)) &BRepBuilderAPI_Copy::Perform, "Copies the shape S. Use the function Shape to access the result. If copyMesh is True, triangulation contained in original shape will be copied along with geometry (by default, triangulation gets lost). If copyGeom is False, only topological objects will be copied, while geometry and triangulation will be shared with original shape.", py::arg("S"), py::arg("copyGeom"), py::arg("copyMesh"));

// Enums

}