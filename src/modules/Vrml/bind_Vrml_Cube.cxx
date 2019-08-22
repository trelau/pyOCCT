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
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <Vrml_Cube.hxx>

void bind_Vrml_Cube(py::module &mod){

py::class_<Vrml_Cube> cls_Vrml_Cube(mod, "Vrml_Cube", "defines a Cube node of VRML specifying geometry shapes. This node represents a cuboid aligned with the coordinate axes. By default , the cube is centred at (0,0,0) and measures 2 units in each dimension, from -1 to +1. A cube's width is its extent along its object-space X axis, its height is its extent along the object-space Y axis, and its depth is its extent along its object-space Z axis.");

// Constructors
cls_Vrml_Cube.def(py::init<>());
cls_Vrml_Cube.def(py::init<const Standard_Real>(), py::arg("aWidth"));
cls_Vrml_Cube.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("aWidth"), py::arg("aHeight"));
cls_Vrml_Cube.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("aWidth"), py::arg("aHeight"), py::arg("aDepth"));

// Fields

// Methods
// cls_Vrml_Cube.def_static("operator new_", (void * (*)(size_t)) &Vrml_Cube::operator new, "None", py::arg("theSize"));
// cls_Vrml_Cube.def_static("operator delete_", (void (*)(void *)) &Vrml_Cube::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_Cube.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_Cube::operator new[], "None", py::arg("theSize"));
// cls_Vrml_Cube.def_static("operator delete[]_", (void (*)(void *)) &Vrml_Cube::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_Cube.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_Cube::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_Cube.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_Cube::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_Cube.def("SetWidth", (void (Vrml_Cube::*)(const Standard_Real)) &Vrml_Cube::SetWidth, "None", py::arg("aWidth"));
cls_Vrml_Cube.def("Width", (Standard_Real (Vrml_Cube::*)() const) &Vrml_Cube::Width, "None");
cls_Vrml_Cube.def("SetHeight", (void (Vrml_Cube::*)(const Standard_Real)) &Vrml_Cube::SetHeight, "None", py::arg("aHeight"));
cls_Vrml_Cube.def("Height", (Standard_Real (Vrml_Cube::*)() const) &Vrml_Cube::Height, "None");
cls_Vrml_Cube.def("SetDepth", (void (Vrml_Cube::*)(const Standard_Real)) &Vrml_Cube::SetDepth, "None", py::arg("aDepth"));
cls_Vrml_Cube.def("Depth", (Standard_Real (Vrml_Cube::*)() const) &Vrml_Cube::Depth, "None");
cls_Vrml_Cube.def("Print", (Standard_OStream & (Vrml_Cube::*)(Standard_OStream &) const) &Vrml_Cube::Print, "None", py::arg("anOStream"));

// Enums

}