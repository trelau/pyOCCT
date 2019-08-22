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
#include <BRepPrimAPI_MakeOneAxis.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Ax2.hxx>
#include <BRepPrim_Sphere.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>

void bind_BRepPrimAPI_MakeSphere(py::module &mod){

py::class_<BRepPrimAPI_MakeSphere, BRepPrimAPI_MakeOneAxis> cls_BRepPrimAPI_MakeSphere(mod, "BRepPrimAPI_MakeSphere", "Describes functions to build spheres or portions of spheres. A MakeSphere object provides a framework for: - defining the construction of a sphere, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_BRepPrimAPI_MakeSphere.def(py::init<const Standard_Real>(), py::arg("R"));
cls_BRepPrimAPI_MakeSphere.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("R"), py::arg("angle"));
cls_BRepPrimAPI_MakeSphere.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("R"), py::arg("angle1"), py::arg("angle2"));
cls_BRepPrimAPI_MakeSphere.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("R"), py::arg("angle1"), py::arg("angle2"), py::arg("angle3"));
cls_BRepPrimAPI_MakeSphere.def(py::init<const gp_Pnt &, const Standard_Real>(), py::arg("Center"), py::arg("R"));
cls_BRepPrimAPI_MakeSphere.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real>(), py::arg("Center"), py::arg("R"), py::arg("angle"));
cls_BRepPrimAPI_MakeSphere.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Center"), py::arg("R"), py::arg("angle1"), py::arg("angle2"));
cls_BRepPrimAPI_MakeSphere.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Center"), py::arg("R"), py::arg("angle1"), py::arg("angle2"), py::arg("angle3"));
cls_BRepPrimAPI_MakeSphere.def(py::init<const gp_Ax2 &, const Standard_Real>(), py::arg("Axis"), py::arg("R"));
cls_BRepPrimAPI_MakeSphere.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real>(), py::arg("Axis"), py::arg("R"), py::arg("angle"));
cls_BRepPrimAPI_MakeSphere.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axis"), py::arg("R"), py::arg("angle1"), py::arg("angle2"));
cls_BRepPrimAPI_MakeSphere.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axis"), py::arg("R"), py::arg("angle1"), py::arg("angle2"), py::arg("angle3"));

// Fields

// Methods
// cls_BRepPrimAPI_MakeSphere.def_static("operator new_", (void * (*)(size_t)) &BRepPrimAPI_MakeSphere::operator new, "None", py::arg("theSize"));
// cls_BRepPrimAPI_MakeSphere.def_static("operator delete_", (void (*)(void *)) &BRepPrimAPI_MakeSphere::operator delete, "None", py::arg("theAddress"));
// cls_BRepPrimAPI_MakeSphere.def_static("operator new[]_", (void * (*)(size_t)) &BRepPrimAPI_MakeSphere::operator new[], "None", py::arg("theSize"));
// cls_BRepPrimAPI_MakeSphere.def_static("operator delete[]_", (void (*)(void *)) &BRepPrimAPI_MakeSphere::operator delete[], "None", py::arg("theAddress"));
// cls_BRepPrimAPI_MakeSphere.def_static("operator new_", (void * (*)(size_t, void *)) &BRepPrimAPI_MakeSphere::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepPrimAPI_MakeSphere.def_static("operator delete_", (void (*)(void *, void *)) &BRepPrimAPI_MakeSphere::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepPrimAPI_MakeSphere.def("OneAxis", (Standard_Address (BRepPrimAPI_MakeSphere::*)()) &BRepPrimAPI_MakeSphere::OneAxis, "Returns the algorithm.");
cls_BRepPrimAPI_MakeSphere.def("Sphere", (BRepPrim_Sphere & (BRepPrimAPI_MakeSphere::*)()) &BRepPrimAPI_MakeSphere::Sphere, "Returns the algorithm.");

// Enums

}