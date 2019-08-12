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
#include <IGESData_ColorEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <IGESGraph_Color.hxx>
#include <Standard_Type.hxx>

void bind_IGESGraph_Color(py::module &mod){

py::class_<IGESGraph_Color, opencascade::handle<IGESGraph_Color>, IGESData_ColorEntity> cls_IGESGraph_Color(mod, "IGESGraph_Color", "defines IGESColor, Type <314> Form <0> in package IGESGraph");

// Constructors
cls_IGESGraph_Color.def(py::init<>());

// Fields

// Methods
cls_IGESGraph_Color.def("Init", (void (IGESGraph_Color::*)(const Standard_Real, const Standard_Real, const Standard_Real, const opencascade::handle<TCollection_HAsciiString> &)) &IGESGraph_Color::Init, "This method is used to set the fields of the class Color - red : Red color intensity (range 0.0 to 100.0) - green : Green color intensity (range 0.0 to 100.0) - blue : Blue color intensity (range 0.0 to 100.0) - aColorName : Name of the color (optional)", py::arg("red"), py::arg("green"), py::arg("blue"), py::arg("aColorName"));
cls_IGESGraph_Color.def("RGBIntensity", [](IGESGraph_Color &self, Standard_Real & Red, Standard_Real & Green, Standard_Real & Blue){ self.RGBIntensity(Red, Green, Blue); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(Red, Green, Blue); }, "None", py::arg("Red"), py::arg("Green"), py::arg("Blue"));
cls_IGESGraph_Color.def("CMYIntensity", [](IGESGraph_Color &self, Standard_Real & Cyan, Standard_Real & Magenta, Standard_Real & Yellow){ self.CMYIntensity(Cyan, Magenta, Yellow); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(Cyan, Magenta, Yellow); }, "None", py::arg("Cyan"), py::arg("Magenta"), py::arg("Yellow"));
cls_IGESGraph_Color.def("HLSPercentage", [](IGESGraph_Color &self, Standard_Real & Hue, Standard_Real & Lightness, Standard_Real & Saturation){ self.HLSPercentage(Hue, Lightness, Saturation); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(Hue, Lightness, Saturation); }, "None", py::arg("Hue"), py::arg("Lightness"), py::arg("Saturation"));
cls_IGESGraph_Color.def("HasColorName", (Standard_Boolean (IGESGraph_Color::*)() const) &IGESGraph_Color::HasColorName, "returns True if optional character string is assigned, False otherwise.");
cls_IGESGraph_Color.def("ColorName", (opencascade::handle<TCollection_HAsciiString> (IGESGraph_Color::*)() const) &IGESGraph_Color::ColorName, "if HasColorName() is True returns the Verbal description of the Color.");
cls_IGESGraph_Color.def_static("get_type_name_", (const char * (*)()) &IGESGraph_Color::get_type_name, "None");
cls_IGESGraph_Color.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_Color::get_type_descriptor, "None");
cls_IGESGraph_Color.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_Color::*)() const) &IGESGraph_Color::DynamicType, "None");

// Enums

}