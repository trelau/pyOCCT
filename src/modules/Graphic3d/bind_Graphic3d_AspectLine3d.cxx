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
#include <Graphic3d_AspectLine3d.hxx>
#include <Standard_Type.hxx>
#include <Quantity_Color.hxx>
#include <Aspect_TypeOfLine.hxx>
#include <Standard_TypeDef.hxx>
#include <Quantity_ColorRGBA.hxx>
#include <Aspect_AspectLineDefinitionError.hxx>
#include <Graphic3d_ShaderProgram.hxx>

void bind_Graphic3d_AspectLine3d(py::module &mod){

py::class_<Graphic3d_AspectLine3d, opencascade::handle<Graphic3d_AspectLine3d>, Standard_Transient> cls_Graphic3d_AspectLine3d(mod, "Graphic3d_AspectLine3d", "Creates and updates a group of attributes for 3d line primitives. This group contains the color, the type of line, and its thickness.");

// Constructors
cls_Graphic3d_AspectLine3d.def(py::init<>());
cls_Graphic3d_AspectLine3d.def(py::init<const Quantity_Color &, const Aspect_TypeOfLine, const Standard_Real>(), py::arg("theColor"), py::arg("theType"), py::arg("theWidth"));

// Fields

// Methods
cls_Graphic3d_AspectLine3d.def_static("get_type_name_", (const char * (*)()) &Graphic3d_AspectLine3d::get_type_name, "None");
cls_Graphic3d_AspectLine3d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_AspectLine3d::get_type_descriptor, "None");
cls_Graphic3d_AspectLine3d.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_AspectLine3d::*)() const) &Graphic3d_AspectLine3d::DynamicType, "None");
cls_Graphic3d_AspectLine3d.def("ColorRGBA", (const Quantity_ColorRGBA & (Graphic3d_AspectLine3d::*)() const) &Graphic3d_AspectLine3d::ColorRGBA, "Return color.");
cls_Graphic3d_AspectLine3d.def("Color", (const Quantity_Color & (Graphic3d_AspectLine3d::*)() const) &Graphic3d_AspectLine3d::Color, "Return color.");
cls_Graphic3d_AspectLine3d.def("SetColor", (void (Graphic3d_AspectLine3d::*)(const Quantity_Color &)) &Graphic3d_AspectLine3d::SetColor, "Modifies the color.", py::arg("theColor"));
cls_Graphic3d_AspectLine3d.def("Type", (Aspect_TypeOfLine (Graphic3d_AspectLine3d::*)() const) &Graphic3d_AspectLine3d::Type, "Return line type.");
cls_Graphic3d_AspectLine3d.def("SetType", (void (Graphic3d_AspectLine3d::*)(const Aspect_TypeOfLine)) &Graphic3d_AspectLine3d::SetType, "Modifies the type of line.", py::arg("theType"));
cls_Graphic3d_AspectLine3d.def("Width", (Standard_ShortReal (Graphic3d_AspectLine3d::*)() const) &Graphic3d_AspectLine3d::Width, "Return line width.");
cls_Graphic3d_AspectLine3d.def("SetWidth", (void (Graphic3d_AspectLine3d::*)(const Standard_Real)) &Graphic3d_AspectLine3d::SetWidth, "Modifies the line thickness. Warning: Raises AspectLineDefinitionError if the width is a negative value.", py::arg("theWidth"));
cls_Graphic3d_AspectLine3d.def("SetWidth", (void (Graphic3d_AspectLine3d::*)(const Standard_ShortReal)) &Graphic3d_AspectLine3d::SetWidth, "Modifies the line thickness. Warning: Raises AspectLineDefinitionError if the width is a negative value.", py::arg("theWidth"));
cls_Graphic3d_AspectLine3d.def("ShaderProgram", (const opencascade::handle<Graphic3d_ShaderProgram> & (Graphic3d_AspectLine3d::*)() const) &Graphic3d_AspectLine3d::ShaderProgram, "Return shader program.");
cls_Graphic3d_AspectLine3d.def("SetShaderProgram", (void (Graphic3d_AspectLine3d::*)(const opencascade::handle<Graphic3d_ShaderProgram> &)) &Graphic3d_AspectLine3d::SetShaderProgram, "Sets up OpenGL/GLSL shader program.", py::arg("theProgram"));
cls_Graphic3d_AspectLine3d.def("IsEqual", (bool (Graphic3d_AspectLine3d::*)(const Graphic3d_AspectLine3d &)) &Graphic3d_AspectLine3d::IsEqual, "Check for equality with another line aspect.", py::arg("theOther"));
cls_Graphic3d_AspectLine3d.def("Values", [](Graphic3d_AspectLine3d &self, Quantity_Color & theColor, Aspect_TypeOfLine & theType, Standard_Real & theWidth){ self.Values(theColor, theType, theWidth); return theWidth; }, "Returns the current values of the group.", py::arg("theColor"), py::arg("theType"), py::arg("theWidth"));

// Enums

}