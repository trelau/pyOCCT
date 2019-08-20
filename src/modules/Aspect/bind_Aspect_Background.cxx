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
#include <Quantity_Color.hxx>
#include <Aspect_Background.hxx>

void bind_Aspect_Background(py::module &mod){

py::class_<Aspect_Background, std::unique_ptr<Aspect_Background>> cls_Aspect_Background(mod, "Aspect_Background", "This class allows the definition of a window background.");

// Constructors
cls_Aspect_Background.def(py::init<>());
cls_Aspect_Background.def(py::init<const Quantity_Color &>(), py::arg("AColor"));

// Fields

// Methods
// cls_Aspect_Background.def_static("operator new_", (void * (*)(size_t)) &Aspect_Background::operator new, "None", py::arg("theSize"));
// cls_Aspect_Background.def_static("operator delete_", (void (*)(void *)) &Aspect_Background::operator delete, "None", py::arg("theAddress"));
// cls_Aspect_Background.def_static("operator new[]_", (void * (*)(size_t)) &Aspect_Background::operator new[], "None", py::arg("theSize"));
// cls_Aspect_Background.def_static("operator delete[]_", (void (*)(void *)) &Aspect_Background::operator delete[], "None", py::arg("theAddress"));
// cls_Aspect_Background.def_static("operator new_", (void * (*)(size_t, void *)) &Aspect_Background::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Aspect_Background.def_static("operator delete_", (void (*)(void *, void *)) &Aspect_Background::operator delete, "None", py::arg(""), py::arg(""));
cls_Aspect_Background.def("SetColor", (void (Aspect_Background::*)(const Quantity_Color &)) &Aspect_Background::SetColor, "Modifies the colour of the window background <me>.", py::arg("AColor"));
cls_Aspect_Background.def("Color", (Quantity_Color (Aspect_Background::*)() const) &Aspect_Background::Color, "Returns the colour of the window background <me>.");

// Enums

}