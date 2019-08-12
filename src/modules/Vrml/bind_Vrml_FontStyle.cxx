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
#include <Vrml_FontStyleFamily.hxx>
#include <Vrml_FontStyleStyle.hxx>
#include <Standard_OStream.hxx>
#include <Vrml_FontStyle.hxx>

void bind_Vrml_FontStyle(py::module &mod){

py::class_<Vrml_FontStyle, std::unique_ptr<Vrml_FontStyle, Deleter<Vrml_FontStyle>>> cls_Vrml_FontStyle(mod, "Vrml_FontStyle", "defines a FontStyle node of VRML of properties of geometry and its appearance. The size field specifies the height (in object space units) of glyphs rendered and determines the vertical spacing of adjacent lines of text.");

// Constructors
cls_Vrml_FontStyle.def(py::init<>());
cls_Vrml_FontStyle.def(py::init<const Standard_Real>(), py::arg("aSize"));
cls_Vrml_FontStyle.def(py::init<const Standard_Real, const Vrml_FontStyleFamily>(), py::arg("aSize"), py::arg("aFamily"));
cls_Vrml_FontStyle.def(py::init<const Standard_Real, const Vrml_FontStyleFamily, const Vrml_FontStyleStyle>(), py::arg("aSize"), py::arg("aFamily"), py::arg("aStyle"));

// Fields

// Methods
// cls_Vrml_FontStyle.def_static("operator new_", (void * (*)(size_t)) &Vrml_FontStyle::operator new, "None", py::arg("theSize"));
// cls_Vrml_FontStyle.def_static("operator delete_", (void (*)(void *)) &Vrml_FontStyle::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_FontStyle.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_FontStyle::operator new[], "None", py::arg("theSize"));
// cls_Vrml_FontStyle.def_static("operator delete[]_", (void (*)(void *)) &Vrml_FontStyle::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_FontStyle.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_FontStyle::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_FontStyle.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_FontStyle::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_FontStyle.def("SetSize", (void (Vrml_FontStyle::*)(const Standard_Real)) &Vrml_FontStyle::SetSize, "None", py::arg("aSize"));
cls_Vrml_FontStyle.def("Size", (Standard_Real (Vrml_FontStyle::*)() const) &Vrml_FontStyle::Size, "None");
cls_Vrml_FontStyle.def("SetFamily", (void (Vrml_FontStyle::*)(const Vrml_FontStyleFamily)) &Vrml_FontStyle::SetFamily, "None", py::arg("aFamily"));
cls_Vrml_FontStyle.def("Family", (Vrml_FontStyleFamily (Vrml_FontStyle::*)() const) &Vrml_FontStyle::Family, "None");
cls_Vrml_FontStyle.def("SetStyle", (void (Vrml_FontStyle::*)(const Vrml_FontStyleStyle)) &Vrml_FontStyle::SetStyle, "None", py::arg("aStyle"));
cls_Vrml_FontStyle.def("Style", (Vrml_FontStyleStyle (Vrml_FontStyle::*)() const) &Vrml_FontStyle::Style, "None");
cls_Vrml_FontStyle.def("Print", (Standard_OStream & (Vrml_FontStyle::*)(Standard_OStream &) const) &Vrml_FontStyle::Print, "None", py::arg("anOStream"));

// Enums

}