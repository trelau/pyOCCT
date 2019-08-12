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
#include <OpenGl_Element.hxx>
#include <Standard_TypeDef.hxx>
#include <OpenGl_Vec.hxx>
#include <OpenGl_TextParam.hxx>
#include <gp_Ax2.hxx>
#include <Standard_Handle.hxx>
#include <OpenGl_Context.hxx>
#include <OpenGl_Workspace.hxx>
#include <TCollection_AsciiString.hxx>
#include <OpenGl_AspectText.hxx>
#include <OpenGl_Font.hxx>
#include <NCollection_String.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Graphic3d_RenderingParams.hxx>
#include <OpenGl_GraduatedTrihedron.hxx>
#include <NCollection_Vector.hxx>
#include <OpenGl_VertexBuffer.hxx>
#include <Font_Rect.hxx>
#include <Standard.hxx>
#include <OpenGl_Text.hxx>

void bind_OpenGl_Text(py::module &mod){

py::class_<OpenGl_Text, std::unique_ptr<OpenGl_Text, py::nodelete>, OpenGl_Element> cls_OpenGl_Text(mod, "OpenGl_Text", "Text rendering");

// Constructors
cls_OpenGl_Text.def(py::init<const Standard_Utf8Char *, const OpenGl_Vec3 &, const OpenGl_TextParam &>(), py::arg("theText"), py::arg("thePoint"), py::arg("theParams"));
cls_OpenGl_Text.def(py::init<const Standard_Utf8Char *, const gp_Ax2 &, const OpenGl_TextParam &>(), py::arg("theText"), py::arg("theOrientation"), py::arg("theParams"));
cls_OpenGl_Text.def(py::init<const Standard_Utf8Char *, const gp_Ax2 &, const OpenGl_TextParam &, const bool>(), py::arg("theText"), py::arg("theOrientation"), py::arg("theParams"), py::arg("theHasOwnAnchor"));
cls_OpenGl_Text.def(py::init<>());

// Fields

// Methods
cls_OpenGl_Text.def("Init", (void (OpenGl_Text::*)(const opencascade::handle<OpenGl_Context> &, const Standard_Utf8Char *, const OpenGl_Vec3 &)) &OpenGl_Text::Init, "Setup new string and position", py::arg("theCtx"), py::arg("theText"), py::arg("thePoint"));
cls_OpenGl_Text.def("Init", (void (OpenGl_Text::*)(const opencascade::handle<OpenGl_Context> &, const Standard_Utf8Char *, const OpenGl_Vec3 &, const OpenGl_TextParam &)) &OpenGl_Text::Init, "Setup new string and parameters", py::arg("theCtx"), py::arg("theText"), py::arg("thePoint"), py::arg("theParams"));
cls_OpenGl_Text.def("SetPosition", (void (OpenGl_Text::*)(const OpenGl_Vec3 &)) &OpenGl_Text::SetPosition, "Setup new position", py::arg("thePoint"));
cls_OpenGl_Text.def("SetFontSize", (void (OpenGl_Text::*)(const opencascade::handle<OpenGl_Context> &, const Standard_Integer)) &OpenGl_Text::SetFontSize, "Setup new font size", py::arg("theContext"), py::arg("theFontSize"));
cls_OpenGl_Text.def("Render", (void (OpenGl_Text::*)(const opencascade::handle<OpenGl_Workspace> &) const) &OpenGl_Text::Render, "None", py::arg("theWorkspace"));
cls_OpenGl_Text.def("Release", (void (OpenGl_Text::*)(OpenGl_Context *)) &OpenGl_Text::Release, "None", py::arg("theContext"));
cls_OpenGl_Text.def_static("FontKey_", (TCollection_AsciiString (*)(const OpenGl_AspectText &, const Standard_Integer, const unsigned int)) &OpenGl_Text::FontKey, "Create key for shared resource", py::arg("theAspect"), py::arg("theHeight"), py::arg("theResolution"));
cls_OpenGl_Text.def_static("FindFont_", (opencascade::handle<OpenGl_Font> (*)(const opencascade::handle<OpenGl_Context> &, const OpenGl_AspectText &, const Standard_Integer, const unsigned int, const TCollection_AsciiString)) &OpenGl_Text::FindFont, "Find shared resource for specified font or initialize new one", py::arg("theCtx"), py::arg("theAspect"), py::arg("theHeight"), py::arg("theResolution"), py::arg("theKey"));
cls_OpenGl_Text.def_static("StringSize_", (void (*)(const opencascade::handle<OpenGl_Context> &, const NCollection_String &, const OpenGl_AspectText &, const OpenGl_TextParam &, const unsigned int, Standard_ShortReal &, Standard_ShortReal &, Standard_ShortReal &)) &OpenGl_Text::StringSize, "Compute text width", py::arg("theCtx"), py::arg("theText"), py::arg("theTextAspect"), py::arg("theParams"), py::arg("theResolution"), py::arg("theWidth"), py::arg("theAscent"), py::arg("theDescent"));
cls_OpenGl_Text.def("Init", (void (OpenGl_Text::*)(const opencascade::handle<OpenGl_Context> &, const TCollection_ExtendedString &, const OpenGl_Vec2 &, const OpenGl_TextParam &)) &OpenGl_Text::Init, "Setup new string and parameters", py::arg("theCtx"), py::arg("theText"), py::arg("thePoint"), py::arg("theParams"));
cls_OpenGl_Text.def("Render", [](OpenGl_Text &self, const opencascade::handle<OpenGl_Context> & a0, const OpenGl_AspectText & a1) -> void { return self.Render(a0, a1); });
cls_OpenGl_Text.def("Render", (void (OpenGl_Text::*)(const opencascade::handle<OpenGl_Context> &, const OpenGl_AspectText &, const unsigned int) const) &OpenGl_Text::Render, "Perform rendering", py::arg("theCtx"), py::arg("theTextAspect"), py::arg("theResolution"));
// cls_OpenGl_Text.def_static("operator new_", (void * (*)(size_t)) &OpenGl_Text::operator new, "None", py::arg("theSize"));
// cls_OpenGl_Text.def_static("operator delete_", (void (*)(void *)) &OpenGl_Text::operator delete, "None", py::arg("theAddress"));
// cls_OpenGl_Text.def_static("operator new[]_", (void * (*)(size_t)) &OpenGl_Text::operator new[], "None", py::arg("theSize"));
// cls_OpenGl_Text.def_static("operator delete[]_", (void (*)(void *)) &OpenGl_Text::operator delete[], "None", py::arg("theAddress"));
// cls_OpenGl_Text.def_static("operator new_", (void * (*)(size_t, void *)) &OpenGl_Text::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_OpenGl_Text.def_static("operator delete_", (void (*)(void *, void *)) &OpenGl_Text::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}