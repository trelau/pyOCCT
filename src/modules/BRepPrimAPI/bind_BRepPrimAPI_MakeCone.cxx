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
#include <BRepPrim_Cone.hxx>
#include <BRepPrimAPI_MakeCone.hxx>

void bind_BRepPrimAPI_MakeCone(py::module &mod){

py::class_<BRepPrimAPI_MakeCone, BRepPrimAPI_MakeOneAxis> cls_BRepPrimAPI_MakeCone(mod, "BRepPrimAPI_MakeCone", "Describes functions to build cones or portions of cones. A MakeCone object provides a framework for: - defining the construction of a cone, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_BRepPrimAPI_MakeCone.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("R1"), py::arg("R2"), py::arg("H"));
cls_BRepPrimAPI_MakeCone.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("R1"), py::arg("R2"), py::arg("H"), py::arg("angle"));
cls_BRepPrimAPI_MakeCone.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("R1"), py::arg("R2"), py::arg("H"));
cls_BRepPrimAPI_MakeCone.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("R1"), py::arg("R2"), py::arg("H"), py::arg("angle"));

// Fields

// Methods
// cls_BRepPrimAPI_MakeCone.def_static("operator new_", (void * (*)(size_t)) &BRepPrimAPI_MakeCone::operator new, "None", py::arg("theSize"));
// cls_BRepPrimAPI_MakeCone.def_static("operator delete_", (void (*)(void *)) &BRepPrimAPI_MakeCone::operator delete, "None", py::arg("theAddress"));
// cls_BRepPrimAPI_MakeCone.def_static("operator new[]_", (void * (*)(size_t)) &BRepPrimAPI_MakeCone::operator new[], "None", py::arg("theSize"));
// cls_BRepPrimAPI_MakeCone.def_static("operator delete[]_", (void (*)(void *)) &BRepPrimAPI_MakeCone::operator delete[], "None", py::arg("theAddress"));
// cls_BRepPrimAPI_MakeCone.def_static("operator new_", (void * (*)(size_t, void *)) &BRepPrimAPI_MakeCone::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepPrimAPI_MakeCone.def_static("operator delete_", (void (*)(void *, void *)) &BRepPrimAPI_MakeCone::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepPrimAPI_MakeCone.def("OneAxis", (Standard_Address (BRepPrimAPI_MakeCone::*)()) &BRepPrimAPI_MakeCone::OneAxis, "Returns the algorithm.");
cls_BRepPrimAPI_MakeCone.def("Cone", (BRepPrim_Cone & (BRepPrimAPI_MakeCone::*)()) &BRepPrimAPI_MakeCone::Cone, "Returns the algorithm.");

// Enums

}