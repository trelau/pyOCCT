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
#include <gp_XY.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepMesh_Circle.hxx>

void bind_BRepMesh_Circle(py::module &mod){

py::class_<BRepMesh_Circle, std::unique_ptr<BRepMesh_Circle>> cls_BRepMesh_Circle(mod, "BRepMesh_Circle", "Describes a 2d circle with a size of only 3 Standard_Real numbers instead of gp who needs 7 Standard_Real numbers.");

// Constructors
cls_BRepMesh_Circle.def(py::init<>());
cls_BRepMesh_Circle.def(py::init<const gp_XY &, const Standard_Real>(), py::arg("theLocation"), py::arg("theRadius"));

// Fields

// Methods
// cls_BRepMesh_Circle.def_static("operator new_", (void * (*)(size_t)) &BRepMesh_Circle::operator new, "None", py::arg("theSize"));
// cls_BRepMesh_Circle.def_static("operator delete_", (void (*)(void *)) &BRepMesh_Circle::operator delete, "None", py::arg("theAddress"));
// cls_BRepMesh_Circle.def_static("operator new[]_", (void * (*)(size_t)) &BRepMesh_Circle::operator new[], "None", py::arg("theSize"));
// cls_BRepMesh_Circle.def_static("operator delete[]_", (void (*)(void *)) &BRepMesh_Circle::operator delete[], "None", py::arg("theAddress"));
// cls_BRepMesh_Circle.def_static("operator new_", (void * (*)(size_t, void *)) &BRepMesh_Circle::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepMesh_Circle.def_static("operator delete_", (void (*)(void *, void *)) &BRepMesh_Circle::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepMesh_Circle.def("SetLocation", (void (BRepMesh_Circle::*)(const gp_XY &)) &BRepMesh_Circle::SetLocation, "Sets location of a circle.", py::arg("theLocation"));
cls_BRepMesh_Circle.def("SetRadius", (void (BRepMesh_Circle::*)(const Standard_Real)) &BRepMesh_Circle::SetRadius, "Sets radius of a circle.", py::arg("theRadius"));
cls_BRepMesh_Circle.def("Location", (const gp_XY & (BRepMesh_Circle::*)() const) &BRepMesh_Circle::Location, "Returns location of a circle.");
cls_BRepMesh_Circle.def("Radius", (const Standard_Real & (BRepMesh_Circle::*)() const) &BRepMesh_Circle::Radius, "Returns radius of a circle.");

// Enums

}