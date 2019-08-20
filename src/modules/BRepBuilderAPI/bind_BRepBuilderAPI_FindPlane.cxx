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
#include <Standard_Handle.hxx>
#include <Geom_Plane.hxx>
#include <BRepBuilderAPI_FindPlane.hxx>

void bind_BRepBuilderAPI_FindPlane(py::module &mod){

py::class_<BRepBuilderAPI_FindPlane, std::unique_ptr<BRepBuilderAPI_FindPlane>> cls_BRepBuilderAPI_FindPlane(mod, "BRepBuilderAPI_FindPlane", "Describes functions to find the plane in which the edges of a given shape are located. A FindPlane object provides a framework for: - extracting the edges of a given shape, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_BRepBuilderAPI_FindPlane.def(py::init<>());
cls_BRepBuilderAPI_FindPlane.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
cls_BRepBuilderAPI_FindPlane.def(py::init<const TopoDS_Shape &, const Standard_Real>(), py::arg("S"), py::arg("Tol"));

// Fields

// Methods
// cls_BRepBuilderAPI_FindPlane.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_FindPlane::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_FindPlane.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_FindPlane::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_FindPlane.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_FindPlane::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_FindPlane.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_FindPlane::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_FindPlane.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_FindPlane::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_FindPlane.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_FindPlane::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_FindPlane.def("Init", [](BRepBuilderAPI_FindPlane &self, const TopoDS_Shape & a0) -> void { return self.Init(a0); });
cls_BRepBuilderAPI_FindPlane.def("Init", (void (BRepBuilderAPI_FindPlane::*)(const TopoDS_Shape &, const Standard_Real)) &BRepBuilderAPI_FindPlane::Init, "Constructs the plane containing the edges of the shape S. A plane is built only if all the edges are within a distance of less than or equal to tolerance from a planar surface. This tolerance value is equal to the larger of the following two values: - Tol, where the default value is negative, or - the largest of the tolerance values assigned to the individual edges of S. Use the function Found to verify that a plane is built. The resulting plane is then retrieved using the function Plane.", py::arg("S"), py::arg("Tol"));
cls_BRepBuilderAPI_FindPlane.def("Found", (Standard_Boolean (BRepBuilderAPI_FindPlane::*)() const) &BRepBuilderAPI_FindPlane::Found, "Returns true if a plane containing the edges of the shape is found and built. Use the function Plane to consult the result.");
cls_BRepBuilderAPI_FindPlane.def("Plane", (opencascade::handle<Geom_Plane> (BRepBuilderAPI_FindPlane::*)() const) &BRepBuilderAPI_FindPlane::Plane, "Returns the plane containing the edges of the shape. Warning Use the function Found to verify that the plane is built. If a plane is not found, Plane returns a null handle.");

// Enums

}