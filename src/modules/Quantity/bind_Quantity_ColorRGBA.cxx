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
#include <Quantity_Color.hxx>
#include <NCollection_Vec4.hxx>
#include <Standard_TypeDef.hxx>
#include <Quantity_ColorRGBA.hxx>
#include <Standard_Assert.hxx>

void bind_Quantity_ColorRGBA(py::module &mod){

py::class_<Quantity_ColorRGBA, std::unique_ptr<Quantity_ColorRGBA>> cls_Quantity_ColorRGBA(mod, "Quantity_ColorRGBA", "The pair of Quantity_Color and Alpha component (1.0 opaque, 0.0 transparent).");

// Constructors
cls_Quantity_ColorRGBA.def(py::init<>());
cls_Quantity_ColorRGBA.def(py::init<const Quantity_Color &>(), py::arg("theRgb"));
cls_Quantity_ColorRGBA.def(py::init<const Quantity_Color &, float>(), py::arg("theRgb"), py::arg("theAlpha"));
cls_Quantity_ColorRGBA.def(py::init<const NCollection_Vec4<float> &>(), py::arg("theRgba"));
cls_Quantity_ColorRGBA.def(py::init<float, float, float, float>(), py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"), py::arg("theAlpha"));

// Fields

// Methods
cls_Quantity_ColorRGBA.def("SetValues", (void (Quantity_ColorRGBA::*)(float, float, float, float)) &Quantity_ColorRGBA::SetValues, "Assign new values to the color.", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"), py::arg("theAlpha"));
cls_Quantity_ColorRGBA.def("GetRGB", (const Quantity_Color & (Quantity_ColorRGBA::*)() const) &Quantity_ColorRGBA::GetRGB, "Return RGB color value.");
cls_Quantity_ColorRGBA.def("ChangeRGB", (Quantity_Color & (Quantity_ColorRGBA::*)()) &Quantity_ColorRGBA::ChangeRGB, "Modify RGB color components without affecting alpha value.");
cls_Quantity_ColorRGBA.def("SetRGB", (void (Quantity_ColorRGBA::*)(const Quantity_Color &)) &Quantity_ColorRGBA::SetRGB, "Assign RGB color components without affecting alpha value.", py::arg("theRgb"));
cls_Quantity_ColorRGBA.def("Alpha", (Standard_ShortReal (Quantity_ColorRGBA::*)() const) &Quantity_ColorRGBA::Alpha, "Return alpha value (1.0 means opaque, 0.0 means fully transparent).");
cls_Quantity_ColorRGBA.def("SetAlpha", (void (Quantity_ColorRGBA::*)(const Standard_ShortReal)) &Quantity_ColorRGBA::SetAlpha, "Assign the alpha value.", py::arg("theAlpha"));
cls_Quantity_ColorRGBA.def("IsDifferent", (bool (Quantity_ColorRGBA::*)(const Quantity_ColorRGBA &) const) &Quantity_ColorRGBA::IsDifferent, "Returns true if the distance between colors is greater than Epsilon().", py::arg("theOther"));
cls_Quantity_ColorRGBA.def("__ne__", (bool (Quantity_ColorRGBA::*)(const Quantity_ColorRGBA &) const) &Quantity_ColorRGBA::operator!=, py::is_operator(), "Returns true if the distance between colors is greater than Epsilon().", py::arg("theOther"));
cls_Quantity_ColorRGBA.def("IsEqual", (bool (Quantity_ColorRGBA::*)(const Quantity_ColorRGBA &) const) &Quantity_ColorRGBA::IsEqual, "Two colors are considered to be equal if their distance is no greater than Epsilon().", py::arg("theOther"));
cls_Quantity_ColorRGBA.def("__eq__", (bool (Quantity_ColorRGBA::*)(const Quantity_ColorRGBA &) const) &Quantity_ColorRGBA::operator==, py::is_operator(), "Two colors are considered to be equal if their distance is no greater than Epsilon().", py::arg("theOther"));

// Enums

}