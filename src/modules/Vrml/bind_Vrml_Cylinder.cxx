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
#include <Vrml_CylinderParts.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_OStream.hxx>
#include <Vrml_Cylinder.hxx>

void bind_Vrml_Cylinder(py::module &mod){

py::class_<Vrml_Cylinder, std::unique_ptr<Vrml_Cylinder, Deleter<Vrml_Cylinder>>> cls_Vrml_Cylinder(mod, "Vrml_Cylinder", "defines a Cylinder node of VRML specifying geometry shapes. This node represents a simple capped cylinder centred around the y-axis. By default , the cylinder is centred at (0,0,0) and has size of -1 to +1 in the all three dimensions. The cylinder has three parts: the sides, the top (y=+1) and the bottom (y=-1)");

// Constructors
cls_Vrml_Cylinder.def(py::init<>());
cls_Vrml_Cylinder.def(py::init<const Vrml_CylinderParts>(), py::arg("aParts"));
cls_Vrml_Cylinder.def(py::init<const Vrml_CylinderParts, const Standard_Real>(), py::arg("aParts"), py::arg("aRadius"));
cls_Vrml_Cylinder.def(py::init<const Vrml_CylinderParts, const Standard_Real, const Standard_Real>(), py::arg("aParts"), py::arg("aRadius"), py::arg("aHeight"));

// Fields

// Methods
// cls_Vrml_Cylinder.def_static("operator new_", (void * (*)(size_t)) &Vrml_Cylinder::operator new, "None", py::arg("theSize"));
// cls_Vrml_Cylinder.def_static("operator delete_", (void (*)(void *)) &Vrml_Cylinder::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_Cylinder.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_Cylinder::operator new[], "None", py::arg("theSize"));
// cls_Vrml_Cylinder.def_static("operator delete[]_", (void (*)(void *)) &Vrml_Cylinder::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_Cylinder.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_Cylinder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_Cylinder.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_Cylinder::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_Cylinder.def("SetParts", (void (Vrml_Cylinder::*)(const Vrml_CylinderParts)) &Vrml_Cylinder::SetParts, "None", py::arg("aParts"));
cls_Vrml_Cylinder.def("Parts", (Vrml_CylinderParts (Vrml_Cylinder::*)() const) &Vrml_Cylinder::Parts, "None");
cls_Vrml_Cylinder.def("SetRadius", (void (Vrml_Cylinder::*)(const Standard_Real)) &Vrml_Cylinder::SetRadius, "None", py::arg("aRadius"));
cls_Vrml_Cylinder.def("Radius", (Standard_Real (Vrml_Cylinder::*)() const) &Vrml_Cylinder::Radius, "None");
cls_Vrml_Cylinder.def("SetHeight", (void (Vrml_Cylinder::*)(const Standard_Real)) &Vrml_Cylinder::SetHeight, "None", py::arg("aHeight"));
cls_Vrml_Cylinder.def("Height", (Standard_Real (Vrml_Cylinder::*)() const) &Vrml_Cylinder::Height, "None");
cls_Vrml_Cylinder.def("Print", (Standard_OStream & (Vrml_Cylinder::*)(Standard_OStream &) const) &Vrml_Cylinder::Print, "None", py::arg("anOStream"));

// Enums

}