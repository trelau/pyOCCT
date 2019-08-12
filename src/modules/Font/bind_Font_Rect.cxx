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
#include <NCollection_Vec2.hxx>
#include <Font_Rect.hxx>

void bind_Font_Rect(py::module &mod){

py::class_<Font_Rect, std::unique_ptr<Font_Rect, Deleter<Font_Rect>>> cls_Font_Rect(mod, "Font_Rect", "Auxiliary POD structure - 2D rectangle definition.");

// Constructors

// Fields
cls_Font_Rect.def_readwrite("Left", &Font_Rect::Left, "left position");
cls_Font_Rect.def_readwrite("Right", &Font_Rect::Right, "right position");
cls_Font_Rect.def_readwrite("Top", &Font_Rect::Top, "top position");
cls_Font_Rect.def_readwrite("Bottom", &Font_Rect::Bottom, "bottom position");

// Methods
cls_Font_Rect.def("TopLeft", (NCollection_Vec2<float> (Font_Rect::*)() const) &Font_Rect::TopLeft, "Top-left corner as vec2.");
cls_Font_Rect.def("TopLeft", (NCollection_Vec2<float> & (Font_Rect::*)(NCollection_Vec2<float> &) const) &Font_Rect::TopLeft, "Top-left corner as vec2.", py::arg("theVec"));
cls_Font_Rect.def("TopRight", (NCollection_Vec2<float> & (Font_Rect::*)(NCollection_Vec2<float> &) const) &Font_Rect::TopRight, "Top-right corner as vec2.", py::arg("theVec"));
cls_Font_Rect.def("BottomLeft", (NCollection_Vec2<float> & (Font_Rect::*)(NCollection_Vec2<float> &) const) &Font_Rect::BottomLeft, "Bottom-left corner as vec2.", py::arg("theVec"));
cls_Font_Rect.def("BottomRight", (NCollection_Vec2<float> & (Font_Rect::*)(NCollection_Vec2<float> &) const) &Font_Rect::BottomRight, "Bottom-right corner as vec2.", py::arg("theVec"));
cls_Font_Rect.def("Width", (float (Font_Rect::*)() const) &Font_Rect::Width, "Rectangle width.");
cls_Font_Rect.def("Height", (float (Font_Rect::*)() const) &Font_Rect::Height, "Rectangle height.");

// Enums

}