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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <Vrml_AsciiTextJustification.hxx>
#include <Standard_OStream.hxx>
#include <Vrml_AsciiText.hxx>
#include <Standard_Type.hxx>

void bind_Vrml_AsciiText(py::module &mod){

py::class_<Vrml_AsciiText, opencascade::handle<Vrml_AsciiText>, Standard_Transient> cls_Vrml_AsciiText(mod, "Vrml_AsciiText", "defines a AsciiText node of VRML specifying geometry shapes. This node represents strings of text characters from ASCII coded character set. All subsequent strings advance y by -( size * spacing). The justification field determines the placement of the strings in the x dimension. LEFT (the default) places the left edge of each string at x=0. CENTER places the center of each string at x=0. RIGHT places the right edge of each string at x=0. Text is rendered from left to right, top to bottom in the font set by FontStyle. The default value for the wigth field indicates the natural width should be used for that string.");

// Constructors
cls_Vrml_AsciiText.def(py::init<>());
cls_Vrml_AsciiText.def(py::init<const opencascade::handle<TColStd_HArray1OfAsciiString> &, const Standard_Real, const Vrml_AsciiTextJustification, const Standard_Real>(), py::arg("aString"), py::arg("aSpacing"), py::arg("aJustification"), py::arg("aWidth"));

// Fields

// Methods
cls_Vrml_AsciiText.def("SetString", (void (Vrml_AsciiText::*)(const opencascade::handle<TColStd_HArray1OfAsciiString> &)) &Vrml_AsciiText::SetString, "None", py::arg("aString"));
cls_Vrml_AsciiText.def("String", (opencascade::handle<TColStd_HArray1OfAsciiString> (Vrml_AsciiText::*)() const) &Vrml_AsciiText::String, "None");
cls_Vrml_AsciiText.def("SetSpacing", (void (Vrml_AsciiText::*)(const Standard_Real)) &Vrml_AsciiText::SetSpacing, "None", py::arg("aSpacing"));
cls_Vrml_AsciiText.def("Spacing", (Standard_Real (Vrml_AsciiText::*)() const) &Vrml_AsciiText::Spacing, "None");
cls_Vrml_AsciiText.def("SetJustification", (void (Vrml_AsciiText::*)(const Vrml_AsciiTextJustification)) &Vrml_AsciiText::SetJustification, "None", py::arg("aJustification"));
cls_Vrml_AsciiText.def("Justification", (Vrml_AsciiTextJustification (Vrml_AsciiText::*)() const) &Vrml_AsciiText::Justification, "None");
cls_Vrml_AsciiText.def("SetWidth", (void (Vrml_AsciiText::*)(const Standard_Real)) &Vrml_AsciiText::SetWidth, "None", py::arg("aWidth"));
cls_Vrml_AsciiText.def("Width", (Standard_Real (Vrml_AsciiText::*)() const) &Vrml_AsciiText::Width, "None");
cls_Vrml_AsciiText.def("Print", (Standard_OStream & (Vrml_AsciiText::*)(Standard_OStream &) const) &Vrml_AsciiText::Print, "None", py::arg("anOStream"));
cls_Vrml_AsciiText.def_static("get_type_name_", (const char * (*)()) &Vrml_AsciiText::get_type_name, "None");
cls_Vrml_AsciiText.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Vrml_AsciiText::get_type_descriptor, "None");
cls_Vrml_AsciiText.def("DynamicType", (const opencascade::handle<Standard_Type> & (Vrml_AsciiText::*)() const) &Vrml_AsciiText::DynamicType, "None");

// Enums

}