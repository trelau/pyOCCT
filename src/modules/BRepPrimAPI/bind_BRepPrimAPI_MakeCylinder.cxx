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
#include <gp_Ax2.hxx>
#include <BRepPrim_Cylinder.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>

void bind_BRepPrimAPI_MakeCylinder(py::module &mod){

py::class_<BRepPrimAPI_MakeCylinder, std::unique_ptr<BRepPrimAPI_MakeCylinder, Deleter<BRepPrimAPI_MakeCylinder>>, BRepPrimAPI_MakeOneAxis> cls_BRepPrimAPI_MakeCylinder(mod, "BRepPrimAPI_MakeCylinder", "Describes functions to build cylinders or portions of cylinders. A MakeCylinder object provides a framework for: - defining the construction of a cylinder, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_BRepPrimAPI_MakeCylinder.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("R"), py::arg("H"));
cls_BRepPrimAPI_MakeCylinder.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("R"), py::arg("H"), py::arg("Angle"));
cls_BRepPrimAPI_MakeCylinder.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("R"), py::arg("H"));
cls_BRepPrimAPI_MakeCylinder.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("R"), py::arg("H"), py::arg("Angle"));

// Fields

// Methods
// cls_BRepPrimAPI_MakeCylinder.def_static("operator new_", (void * (*)(size_t)) &BRepPrimAPI_MakeCylinder::operator new, "None", py::arg("theSize"));
// cls_BRepPrimAPI_MakeCylinder.def_static("operator delete_", (void (*)(void *)) &BRepPrimAPI_MakeCylinder::operator delete, "None", py::arg("theAddress"));
// cls_BRepPrimAPI_MakeCylinder.def_static("operator new[]_", (void * (*)(size_t)) &BRepPrimAPI_MakeCylinder::operator new[], "None", py::arg("theSize"));
// cls_BRepPrimAPI_MakeCylinder.def_static("operator delete[]_", (void (*)(void *)) &BRepPrimAPI_MakeCylinder::operator delete[], "None", py::arg("theAddress"));
// cls_BRepPrimAPI_MakeCylinder.def_static("operator new_", (void * (*)(size_t, void *)) &BRepPrimAPI_MakeCylinder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepPrimAPI_MakeCylinder.def_static("operator delete_", (void (*)(void *, void *)) &BRepPrimAPI_MakeCylinder::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepPrimAPI_MakeCylinder.def("OneAxis", (Standard_Address (BRepPrimAPI_MakeCylinder::*)()) &BRepPrimAPI_MakeCylinder::OneAxis, "Returns the algorithm.");
cls_BRepPrimAPI_MakeCylinder.def("Cylinder", (BRepPrim_Cylinder & (BRepPrimAPI_MakeCylinder::*)()) &BRepPrimAPI_MakeCylinder::Cylinder, "Returns the algorithm.");

// Enums

}