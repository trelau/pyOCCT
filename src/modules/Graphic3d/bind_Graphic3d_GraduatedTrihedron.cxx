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
#include <Graphic3d_CView.hxx>
#include <TCollection_AsciiString.hxx>
#include <Font_FontAspect.hxx>
#include <Standard_TypeDef.hxx>
#include <Quantity_Color.hxx>
#include <Graphic3d_GraduatedTrihedron.hxx>
#include <Standard_OutOfRange.hxx>
#include <NCollection_Array1.hxx>

void bind_Graphic3d_GraduatedTrihedron(py::module &mod){

py::class_<Graphic3d_GraduatedTrihedron, std::unique_ptr<Graphic3d_GraduatedTrihedron, Deleter<Graphic3d_GraduatedTrihedron>>> cls_Graphic3d_GraduatedTrihedron(mod, "Graphic3d_GraduatedTrihedron", "Defines the class of a graduated trihedron. It contains main style parameters for implementation of graduated trihedron");

// Constructors
cls_Graphic3d_GraduatedTrihedron.def(py::init<>());
cls_Graphic3d_GraduatedTrihedron.def(py::init<const TCollection_AsciiString &>(), py::arg("theNamesFont"));
cls_Graphic3d_GraduatedTrihedron.def(py::init<const TCollection_AsciiString &, const Font_FontAspect &>(), py::arg("theNamesFont"), py::arg("theNamesStyle"));
cls_Graphic3d_GraduatedTrihedron.def(py::init<const TCollection_AsciiString &, const Font_FontAspect &, const Standard_Integer>(), py::arg("theNamesFont"), py::arg("theNamesStyle"), py::arg("theNamesSize"));
cls_Graphic3d_GraduatedTrihedron.def(py::init<const TCollection_AsciiString &, const Font_FontAspect &, const Standard_Integer, const TCollection_AsciiString &>(), py::arg("theNamesFont"), py::arg("theNamesStyle"), py::arg("theNamesSize"), py::arg("theValuesFont"));
cls_Graphic3d_GraduatedTrihedron.def(py::init<const TCollection_AsciiString &, const Font_FontAspect &, const Standard_Integer, const TCollection_AsciiString &, const Font_FontAspect &>(), py::arg("theNamesFont"), py::arg("theNamesStyle"), py::arg("theNamesSize"), py::arg("theValuesFont"), py::arg("theValuesStyle"));
cls_Graphic3d_GraduatedTrihedron.def(py::init<const TCollection_AsciiString &, const Font_FontAspect &, const Standard_Integer, const TCollection_AsciiString &, const Font_FontAspect &, const Standard_Integer>(), py::arg("theNamesFont"), py::arg("theNamesStyle"), py::arg("theNamesSize"), py::arg("theValuesFont"), py::arg("theValuesStyle"), py::arg("theValuesSize"));
cls_Graphic3d_GraduatedTrihedron.def(py::init<const TCollection_AsciiString &, const Font_FontAspect &, const Standard_Integer, const TCollection_AsciiString &, const Font_FontAspect &, const Standard_Integer, const Standard_ShortReal>(), py::arg("theNamesFont"), py::arg("theNamesStyle"), py::arg("theNamesSize"), py::arg("theValuesFont"), py::arg("theValuesStyle"), py::arg("theValuesSize"), py::arg("theArrowsLength"));
cls_Graphic3d_GraduatedTrihedron.def(py::init<const TCollection_AsciiString &, const Font_FontAspect &, const Standard_Integer, const TCollection_AsciiString &, const Font_FontAspect &, const Standard_Integer, const Standard_ShortReal, const Quantity_Color>(), py::arg("theNamesFont"), py::arg("theNamesStyle"), py::arg("theNamesSize"), py::arg("theValuesFont"), py::arg("theValuesStyle"), py::arg("theValuesSize"), py::arg("theArrowsLength"), py::arg("theGridColor"));
cls_Graphic3d_GraduatedTrihedron.def(py::init<const TCollection_AsciiString &, const Font_FontAspect &, const Standard_Integer, const TCollection_AsciiString &, const Font_FontAspect &, const Standard_Integer, const Standard_ShortReal, const Quantity_Color, const Standard_Boolean>(), py::arg("theNamesFont"), py::arg("theNamesStyle"), py::arg("theNamesSize"), py::arg("theValuesFont"), py::arg("theValuesStyle"), py::arg("theValuesSize"), py::arg("theArrowsLength"), py::arg("theGridColor"), py::arg("theToDrawGrid"));
cls_Graphic3d_GraduatedTrihedron.def(py::init<const TCollection_AsciiString &, const Font_FontAspect &, const Standard_Integer, const TCollection_AsciiString &, const Font_FontAspect &, const Standard_Integer, const Standard_ShortReal, const Quantity_Color, const Standard_Boolean, const Standard_Boolean>(), py::arg("theNamesFont"), py::arg("theNamesStyle"), py::arg("theNamesSize"), py::arg("theValuesFont"), py::arg("theValuesStyle"), py::arg("theValuesSize"), py::arg("theArrowsLength"), py::arg("theGridColor"), py::arg("theToDrawGrid"), py::arg("theToDrawAxes"));

// Fields
cls_Graphic3d_GraduatedTrihedron.def_readwrite("CubicAxesCallback", &Graphic3d_GraduatedTrihedron::CubicAxesCallback, "Callback function to define boundary box of displayed objects");
cls_Graphic3d_GraduatedTrihedron.def_readwrite("PtrView", &Graphic3d_GraduatedTrihedron::PtrView, "None");

// Methods
cls_Graphic3d_GraduatedTrihedron.def("ChangeXAxisAspect", (Graphic3d_AxisAspect & (Graphic3d_GraduatedTrihedron::*)()) &Graphic3d_GraduatedTrihedron::ChangeXAxisAspect, "None");
cls_Graphic3d_GraduatedTrihedron.def("ChangeYAxisAspect", (Graphic3d_AxisAspect & (Graphic3d_GraduatedTrihedron::*)()) &Graphic3d_GraduatedTrihedron::ChangeYAxisAspect, "None");
cls_Graphic3d_GraduatedTrihedron.def("ChangeZAxisAspect", (Graphic3d_AxisAspect & (Graphic3d_GraduatedTrihedron::*)()) &Graphic3d_GraduatedTrihedron::ChangeZAxisAspect, "None");
cls_Graphic3d_GraduatedTrihedron.def("ChangeAxisAspect", (Graphic3d_AxisAspect & (Graphic3d_GraduatedTrihedron::*)(const Standard_Integer)) &Graphic3d_GraduatedTrihedron::ChangeAxisAspect, "None", py::arg("theIndex"));
cls_Graphic3d_GraduatedTrihedron.def("XAxisAspect", (const Graphic3d_AxisAspect & (Graphic3d_GraduatedTrihedron::*)() const) &Graphic3d_GraduatedTrihedron::XAxisAspect, "None");
cls_Graphic3d_GraduatedTrihedron.def("YAxisAspect", (const Graphic3d_AxisAspect & (Graphic3d_GraduatedTrihedron::*)() const) &Graphic3d_GraduatedTrihedron::YAxisAspect, "None");
cls_Graphic3d_GraduatedTrihedron.def("ZAxisAspect", (const Graphic3d_AxisAspect & (Graphic3d_GraduatedTrihedron::*)() const) &Graphic3d_GraduatedTrihedron::ZAxisAspect, "None");
cls_Graphic3d_GraduatedTrihedron.def("AxisAspect", (const Graphic3d_AxisAspect & (Graphic3d_GraduatedTrihedron::*)(const Standard_Integer) const) &Graphic3d_GraduatedTrihedron::AxisAspect, "None", py::arg("theIndex"));
cls_Graphic3d_GraduatedTrihedron.def("ArrowsLength", (Standard_ShortReal (Graphic3d_GraduatedTrihedron::*)() const) &Graphic3d_GraduatedTrihedron::ArrowsLength, "None");
cls_Graphic3d_GraduatedTrihedron.def("SetArrowsLength", (void (Graphic3d_GraduatedTrihedron::*)(const Standard_ShortReal)) &Graphic3d_GraduatedTrihedron::SetArrowsLength, "None", py::arg("theValue"));
cls_Graphic3d_GraduatedTrihedron.def("GridColor", (const Quantity_Color & (Graphic3d_GraduatedTrihedron::*)() const) &Graphic3d_GraduatedTrihedron::GridColor, "None");
cls_Graphic3d_GraduatedTrihedron.def("SetGridColor", (void (Graphic3d_GraduatedTrihedron::*)(const Quantity_Color &)) &Graphic3d_GraduatedTrihedron::SetGridColor, "None", py::arg("theColor"));
cls_Graphic3d_GraduatedTrihedron.def("ToDrawGrid", (Standard_Boolean (Graphic3d_GraduatedTrihedron::*)() const) &Graphic3d_GraduatedTrihedron::ToDrawGrid, "None");
cls_Graphic3d_GraduatedTrihedron.def("SetDrawGrid", (void (Graphic3d_GraduatedTrihedron::*)(const Standard_Boolean)) &Graphic3d_GraduatedTrihedron::SetDrawGrid, "None", py::arg("theToDraw"));
cls_Graphic3d_GraduatedTrihedron.def("ToDrawAxes", (Standard_Boolean (Graphic3d_GraduatedTrihedron::*)() const) &Graphic3d_GraduatedTrihedron::ToDrawAxes, "None");
cls_Graphic3d_GraduatedTrihedron.def("SetDrawAxes", (void (Graphic3d_GraduatedTrihedron::*)(const Standard_Boolean)) &Graphic3d_GraduatedTrihedron::SetDrawAxes, "None", py::arg("theToDraw"));
cls_Graphic3d_GraduatedTrihedron.def("NamesFont", (const TCollection_AsciiString & (Graphic3d_GraduatedTrihedron::*)() const) &Graphic3d_GraduatedTrihedron::NamesFont, "None");
cls_Graphic3d_GraduatedTrihedron.def("SetNamesFont", (void (Graphic3d_GraduatedTrihedron::*)(const TCollection_AsciiString &)) &Graphic3d_GraduatedTrihedron::SetNamesFont, "None", py::arg("theFont"));
cls_Graphic3d_GraduatedTrihedron.def("NamesFontAspect", (Font_FontAspect (Graphic3d_GraduatedTrihedron::*)() const) &Graphic3d_GraduatedTrihedron::NamesFontAspect, "None");
cls_Graphic3d_GraduatedTrihedron.def("SetNamesFontAspect", (void (Graphic3d_GraduatedTrihedron::*)(Font_FontAspect)) &Graphic3d_GraduatedTrihedron::SetNamesFontAspect, "None", py::arg("theAspect"));
cls_Graphic3d_GraduatedTrihedron.def("NamesSize", (Standard_Integer (Graphic3d_GraduatedTrihedron::*)() const) &Graphic3d_GraduatedTrihedron::NamesSize, "None");
cls_Graphic3d_GraduatedTrihedron.def("SetNamesSize", (void (Graphic3d_GraduatedTrihedron::*)(const Standard_Integer)) &Graphic3d_GraduatedTrihedron::SetNamesSize, "None", py::arg("theValue"));
cls_Graphic3d_GraduatedTrihedron.def("ValuesFont", (const TCollection_AsciiString & (Graphic3d_GraduatedTrihedron::*)() const) &Graphic3d_GraduatedTrihedron::ValuesFont, "None");
cls_Graphic3d_GraduatedTrihedron.def("SetValuesFont", (void (Graphic3d_GraduatedTrihedron::*)(const TCollection_AsciiString &)) &Graphic3d_GraduatedTrihedron::SetValuesFont, "None", py::arg("theFont"));
cls_Graphic3d_GraduatedTrihedron.def("ValuesFontAspect", (Font_FontAspect (Graphic3d_GraduatedTrihedron::*)() const) &Graphic3d_GraduatedTrihedron::ValuesFontAspect, "None");
cls_Graphic3d_GraduatedTrihedron.def("SetValuesFontAspect", (void (Graphic3d_GraduatedTrihedron::*)(Font_FontAspect)) &Graphic3d_GraduatedTrihedron::SetValuesFontAspect, "None", py::arg("theAspect"));
cls_Graphic3d_GraduatedTrihedron.def("ValuesSize", (Standard_Integer (Graphic3d_GraduatedTrihedron::*)() const) &Graphic3d_GraduatedTrihedron::ValuesSize, "None");
cls_Graphic3d_GraduatedTrihedron.def("SetValuesSize", (void (Graphic3d_GraduatedTrihedron::*)(const Standard_Integer)) &Graphic3d_GraduatedTrihedron::SetValuesSize, "None", py::arg("theValue"));

// Enums

}