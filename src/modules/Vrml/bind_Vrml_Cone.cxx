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
#include <Vrml_ConeParts.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <Vrml_Cone.hxx>

void bind_Vrml_Cone(py::module &mod){

py::class_<Vrml_Cone, std::unique_ptr<Vrml_Cone, Deleter<Vrml_Cone>>> cls_Vrml_Cone(mod, "Vrml_Cone", "defines a Cone node of VRML specifying geometry shapes. This node represents a simple cone, whose central axis is aligned with the y-axis. By default , the cone is centred at (0,0,0) and has size of -1 to +1 in the all three directions. the cone has a radius of 1 at the bottom and height of 2, with its apex at 1 and its bottom at -1. The cone has two parts: the sides and the bottom");

// Constructors
cls_Vrml_Cone.def(py::init<>());
cls_Vrml_Cone.def(py::init<const Vrml_ConeParts>(), py::arg("aParts"));
cls_Vrml_Cone.def(py::init<const Vrml_ConeParts, const Standard_Real>(), py::arg("aParts"), py::arg("aBottomRadius"));
cls_Vrml_Cone.def(py::init<const Vrml_ConeParts, const Standard_Real, const Standard_Real>(), py::arg("aParts"), py::arg("aBottomRadius"), py::arg("aHeight"));

// Fields

// Methods
// cls_Vrml_Cone.def_static("operator new_", (void * (*)(size_t)) &Vrml_Cone::operator new, "None", py::arg("theSize"));
// cls_Vrml_Cone.def_static("operator delete_", (void (*)(void *)) &Vrml_Cone::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_Cone.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_Cone::operator new[], "None", py::arg("theSize"));
// cls_Vrml_Cone.def_static("operator delete[]_", (void (*)(void *)) &Vrml_Cone::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_Cone.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_Cone::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_Cone.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_Cone::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_Cone.def("SetParts", (void (Vrml_Cone::*)(const Vrml_ConeParts)) &Vrml_Cone::SetParts, "None", py::arg("aParts"));
cls_Vrml_Cone.def("Parts", (Vrml_ConeParts (Vrml_Cone::*)() const) &Vrml_Cone::Parts, "None");
cls_Vrml_Cone.def("SetBottomRadius", (void (Vrml_Cone::*)(const Standard_Real)) &Vrml_Cone::SetBottomRadius, "None", py::arg("aBottomRadius"));
cls_Vrml_Cone.def("BottomRadius", (Standard_Real (Vrml_Cone::*)() const) &Vrml_Cone::BottomRadius, "None");
cls_Vrml_Cone.def("SetHeight", (void (Vrml_Cone::*)(const Standard_Real)) &Vrml_Cone::SetHeight, "None", py::arg("aHeight"));
cls_Vrml_Cone.def("Height", (Standard_Real (Vrml_Cone::*)() const) &Vrml_Cone::Height, "None");
cls_Vrml_Cone.def("Print", (Standard_OStream & (Vrml_Cone::*)(Standard_OStream &) const) &Vrml_Cone::Print, "None", py::arg("anOStream"));

// Enums

}