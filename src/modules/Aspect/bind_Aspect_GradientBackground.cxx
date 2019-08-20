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
#include <Aspect_Background.hxx>
#include <Standard.hxx>
#include <Quantity_Color.hxx>
#include <Aspect_GradientFillMethod.hxx>
#include <Aspect_GradientBackground.hxx>

void bind_Aspect_GradientBackground(py::module &mod){

py::class_<Aspect_GradientBackground, std::unique_ptr<Aspect_GradientBackground>, Aspect_Background> cls_Aspect_GradientBackground(mod, "Aspect_GradientBackground", "This class allows the definition of a window gradient background.");

// Constructors
cls_Aspect_GradientBackground.def(py::init<>());
cls_Aspect_GradientBackground.def(py::init<const Quantity_Color &, const Quantity_Color &>(), py::arg("AColor1"), py::arg("AColor2"));
cls_Aspect_GradientBackground.def(py::init<const Quantity_Color &, const Quantity_Color &, const Aspect_GradientFillMethod>(), py::arg("AColor1"), py::arg("AColor2"), py::arg("AMethod"));

// Fields

// Methods
// cls_Aspect_GradientBackground.def_static("operator new_", (void * (*)(size_t)) &Aspect_GradientBackground::operator new, "None", py::arg("theSize"));
// cls_Aspect_GradientBackground.def_static("operator delete_", (void (*)(void *)) &Aspect_GradientBackground::operator delete, "None", py::arg("theAddress"));
// cls_Aspect_GradientBackground.def_static("operator new[]_", (void * (*)(size_t)) &Aspect_GradientBackground::operator new[], "None", py::arg("theSize"));
// cls_Aspect_GradientBackground.def_static("operator delete[]_", (void (*)(void *)) &Aspect_GradientBackground::operator delete[], "None", py::arg("theAddress"));
// cls_Aspect_GradientBackground.def_static("operator new_", (void * (*)(size_t, void *)) &Aspect_GradientBackground::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Aspect_GradientBackground.def_static("operator delete_", (void (*)(void *, void *)) &Aspect_GradientBackground::operator delete, "None", py::arg(""), py::arg(""));
cls_Aspect_GradientBackground.def("SetColors", [](Aspect_GradientBackground &self, const Quantity_Color & a0, const Quantity_Color & a1) -> void { return self.SetColors(a0, a1); });
cls_Aspect_GradientBackground.def("SetColors", (void (Aspect_GradientBackground::*)(const Quantity_Color &, const Quantity_Color &, const Aspect_GradientFillMethod)) &Aspect_GradientBackground::SetColors, "Modifies the colours of the window gradient background <me>.", py::arg("AColor1"), py::arg("AColor2"), py::arg("AMethod"));
cls_Aspect_GradientBackground.def("Colors", (void (Aspect_GradientBackground::*)(Quantity_Color &, Quantity_Color &) const) &Aspect_GradientBackground::Colors, "Returns colours of the window gradient background <me>.", py::arg("AColor1"), py::arg("AColor2"));
cls_Aspect_GradientBackground.def("BgGradientFillMethod", (Aspect_GradientFillMethod (Aspect_GradientBackground::*)() const) &Aspect_GradientBackground::BgGradientFillMethod, "Returns the current gradient background fill mode.");

// Enums

}