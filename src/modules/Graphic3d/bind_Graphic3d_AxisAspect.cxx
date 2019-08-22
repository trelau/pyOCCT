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
#include <TCollection_ExtendedString.hxx>
#include <Quantity_Color.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_GraduatedTrihedron.hxx>

void bind_Graphic3d_AxisAspect(py::module &mod){

py::class_<Graphic3d_AxisAspect> cls_Graphic3d_AxisAspect(mod, "Graphic3d_AxisAspect", "Class that stores style for one graduated trihedron axis such as colors, lengths and customization flags. It is used in Graphic3d_GraduatedTrihedron.");

// Constructors
cls_Graphic3d_AxisAspect.def(py::init<>());
cls_Graphic3d_AxisAspect.def(py::init<const TCollection_ExtendedString>(), py::arg("theName"));
cls_Graphic3d_AxisAspect.def(py::init<const TCollection_ExtendedString, const Quantity_Color>(), py::arg("theName"), py::arg("theNameColor"));
cls_Graphic3d_AxisAspect.def(py::init<const TCollection_ExtendedString, const Quantity_Color, const Quantity_Color>(), py::arg("theName"), py::arg("theNameColor"), py::arg("theColor"));
cls_Graphic3d_AxisAspect.def(py::init<const TCollection_ExtendedString, const Quantity_Color, const Quantity_Color, const Standard_Integer>(), py::arg("theName"), py::arg("theNameColor"), py::arg("theColor"), py::arg("theValuesOffset"));
cls_Graphic3d_AxisAspect.def(py::init<const TCollection_ExtendedString, const Quantity_Color, const Quantity_Color, const Standard_Integer, const Standard_Integer>(), py::arg("theName"), py::arg("theNameColor"), py::arg("theColor"), py::arg("theValuesOffset"), py::arg("theNameOffset"));
cls_Graphic3d_AxisAspect.def(py::init<const TCollection_ExtendedString, const Quantity_Color, const Quantity_Color, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theName"), py::arg("theNameColor"), py::arg("theColor"), py::arg("theValuesOffset"), py::arg("theNameOffset"), py::arg("theTickmarksNumber"));
cls_Graphic3d_AxisAspect.def(py::init<const TCollection_ExtendedString, const Quantity_Color, const Quantity_Color, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theName"), py::arg("theNameColor"), py::arg("theColor"), py::arg("theValuesOffset"), py::arg("theNameOffset"), py::arg("theTickmarksNumber"), py::arg("theTickmarksLength"));
cls_Graphic3d_AxisAspect.def(py::init<const TCollection_ExtendedString, const Quantity_Color, const Quantity_Color, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean>(), py::arg("theName"), py::arg("theNameColor"), py::arg("theColor"), py::arg("theValuesOffset"), py::arg("theNameOffset"), py::arg("theTickmarksNumber"), py::arg("theTickmarksLength"), py::arg("theToDrawName"));
cls_Graphic3d_AxisAspect.def(py::init<const TCollection_ExtendedString, const Quantity_Color, const Quantity_Color, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean>(), py::arg("theName"), py::arg("theNameColor"), py::arg("theColor"), py::arg("theValuesOffset"), py::arg("theNameOffset"), py::arg("theTickmarksNumber"), py::arg("theTickmarksLength"), py::arg("theToDrawName"), py::arg("theToDrawValues"));
cls_Graphic3d_AxisAspect.def(py::init<const TCollection_ExtendedString, const Quantity_Color, const Quantity_Color, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("theName"), py::arg("theNameColor"), py::arg("theColor"), py::arg("theValuesOffset"), py::arg("theNameOffset"), py::arg("theTickmarksNumber"), py::arg("theTickmarksLength"), py::arg("theToDrawName"), py::arg("theToDrawValues"), py::arg("theToDrawTickmarks"));

// Fields

// Methods
cls_Graphic3d_AxisAspect.def("SetName", (void (Graphic3d_AxisAspect::*)(const TCollection_ExtendedString &)) &Graphic3d_AxisAspect::SetName, "None", py::arg("theName"));
cls_Graphic3d_AxisAspect.def("Name", (const TCollection_ExtendedString & (Graphic3d_AxisAspect::*)() const) &Graphic3d_AxisAspect::Name, "None");
cls_Graphic3d_AxisAspect.def("ToDrawName", (Standard_Boolean (Graphic3d_AxisAspect::*)() const) &Graphic3d_AxisAspect::ToDrawName, "None");
cls_Graphic3d_AxisAspect.def("SetDrawName", (void (Graphic3d_AxisAspect::*)(const Standard_Boolean)) &Graphic3d_AxisAspect::SetDrawName, "None", py::arg("theToDraw"));
cls_Graphic3d_AxisAspect.def("ToDrawTickmarks", (Standard_Boolean (Graphic3d_AxisAspect::*)() const) &Graphic3d_AxisAspect::ToDrawTickmarks, "None");
cls_Graphic3d_AxisAspect.def("SetDrawTickmarks", (void (Graphic3d_AxisAspect::*)(const Standard_Boolean)) &Graphic3d_AxisAspect::SetDrawTickmarks, "None", py::arg("theToDraw"));
cls_Graphic3d_AxisAspect.def("ToDrawValues", (Standard_Boolean (Graphic3d_AxisAspect::*)() const) &Graphic3d_AxisAspect::ToDrawValues, "None");
cls_Graphic3d_AxisAspect.def("SetDrawValues", (void (Graphic3d_AxisAspect::*)(const Standard_Boolean)) &Graphic3d_AxisAspect::SetDrawValues, "None", py::arg("theToDraw"));
cls_Graphic3d_AxisAspect.def("NameColor", (const Quantity_Color & (Graphic3d_AxisAspect::*)() const) &Graphic3d_AxisAspect::NameColor, "None");
cls_Graphic3d_AxisAspect.def("SetNameColor", (void (Graphic3d_AxisAspect::*)(const Quantity_Color &)) &Graphic3d_AxisAspect::SetNameColor, "None", py::arg("theColor"));
cls_Graphic3d_AxisAspect.def("Color", (const Quantity_Color & (Graphic3d_AxisAspect::*)() const) &Graphic3d_AxisAspect::Color, "Color of axis and values");
cls_Graphic3d_AxisAspect.def("SetColor", (void (Graphic3d_AxisAspect::*)(const Quantity_Color &)) &Graphic3d_AxisAspect::SetColor, "Sets color of axis and values", py::arg("theColor"));
cls_Graphic3d_AxisAspect.def("TickmarksNumber", (Standard_Integer (Graphic3d_AxisAspect::*)() const) &Graphic3d_AxisAspect::TickmarksNumber, "None");
cls_Graphic3d_AxisAspect.def("SetTickmarksNumber", (void (Graphic3d_AxisAspect::*)(const Standard_Integer)) &Graphic3d_AxisAspect::SetTickmarksNumber, "None", py::arg("theValue"));
cls_Graphic3d_AxisAspect.def("TickmarksLength", (Standard_Integer (Graphic3d_AxisAspect::*)() const) &Graphic3d_AxisAspect::TickmarksLength, "None");
cls_Graphic3d_AxisAspect.def("SetTickmarksLength", (void (Graphic3d_AxisAspect::*)(const Standard_Integer)) &Graphic3d_AxisAspect::SetTickmarksLength, "None", py::arg("theValue"));
cls_Graphic3d_AxisAspect.def("ValuesOffset", (Standard_Integer (Graphic3d_AxisAspect::*)() const) &Graphic3d_AxisAspect::ValuesOffset, "None");
cls_Graphic3d_AxisAspect.def("SetValuesOffset", (void (Graphic3d_AxisAspect::*)(const Standard_Integer)) &Graphic3d_AxisAspect::SetValuesOffset, "None", py::arg("theValue"));
cls_Graphic3d_AxisAspect.def("NameOffset", (Standard_Integer (Graphic3d_AxisAspect::*)() const) &Graphic3d_AxisAspect::NameOffset, "None");
cls_Graphic3d_AxisAspect.def("SetNameOffset", (void (Graphic3d_AxisAspect::*)(const Standard_Integer)) &Graphic3d_AxisAspect::SetNameOffset, "None", py::arg("theValue"));

// Enums

}