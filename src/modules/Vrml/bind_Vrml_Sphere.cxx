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
#include <Vrml_Sphere.hxx>

void bind_Vrml_Sphere(py::module &mod){

py::class_<Vrml_Sphere, std::unique_ptr<Vrml_Sphere>> cls_Vrml_Sphere(mod, "Vrml_Sphere", "defines a Sphere node of VRML specifying geometry shapes. This node represents a sphere. By default , the sphere is centred at (0,0,0) and has a radius of 1.");

// Constructors
cls_Vrml_Sphere.def(py::init<>());
cls_Vrml_Sphere.def(py::init<const Standard_Real>(), py::arg("aRadius"));

// Fields

// Methods
// cls_Vrml_Sphere.def_static("operator new_", (void * (*)(size_t)) &Vrml_Sphere::operator new, "None", py::arg("theSize"));
// cls_Vrml_Sphere.def_static("operator delete_", (void (*)(void *)) &Vrml_Sphere::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_Sphere.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_Sphere::operator new[], "None", py::arg("theSize"));
// cls_Vrml_Sphere.def_static("operator delete[]_", (void (*)(void *)) &Vrml_Sphere::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_Sphere.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_Sphere::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_Sphere.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_Sphere::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_Sphere.def("SetRadius", (void (Vrml_Sphere::*)(const Standard_Real)) &Vrml_Sphere::SetRadius, "None", py::arg("aRadius"));
cls_Vrml_Sphere.def("Radius", (Standard_Real (Vrml_Sphere::*)() const) &Vrml_Sphere::Radius, "None");
cls_Vrml_Sphere.def("Print", (Standard_OStream & (Vrml_Sphere::*)(Standard_OStream &) const) &Vrml_Sphere::Print, "None", py::arg("anOStream"));

// Enums

}