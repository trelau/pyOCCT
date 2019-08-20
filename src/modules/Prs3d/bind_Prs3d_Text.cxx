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
#include <Prs3d_Root.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_Group.hxx>
#include <Prs3d_TextAspect.hxx>
#include <TCollection_ExtendedString.hxx>
#include <gp_Pnt.hxx>
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <Prs3d_Presentation.hxx>
#include <Prs3d_Drawer.hxx>
#include <Prs3d_Text.hxx>

void bind_Prs3d_Text(py::module &mod){

py::class_<Prs3d_Text, std::unique_ptr<Prs3d_Text>, Prs3d_Root> cls_Prs3d_Text(mod, "Prs3d_Text", "A framework to define the display of texts.");

// Constructors

// Fields

// Methods
// cls_Prs3d_Text.def_static("operator new_", (void * (*)(size_t)) &Prs3d_Text::operator new, "None", py::arg("theSize"));
// cls_Prs3d_Text.def_static("operator delete_", (void (*)(void *)) &Prs3d_Text::operator delete, "None", py::arg("theAddress"));
// cls_Prs3d_Text.def_static("operator new[]_", (void * (*)(size_t)) &Prs3d_Text::operator new[], "None", py::arg("theSize"));
// cls_Prs3d_Text.def_static("operator delete[]_", (void (*)(void *)) &Prs3d_Text::operator delete[], "None", py::arg("theAddress"));
// cls_Prs3d_Text.def_static("operator new_", (void * (*)(size_t, void *)) &Prs3d_Text::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Prs3d_Text.def_static("operator delete_", (void (*)(void *, void *)) &Prs3d_Text::operator delete, "None", py::arg(""), py::arg(""));
cls_Prs3d_Text.def_static("Draw_", (void (*)(const opencascade::handle<Graphic3d_Group> &, const opencascade::handle<Prs3d_TextAspect> &, const TCollection_ExtendedString &, const gp_Pnt &)) &Prs3d_Text::Draw, "Defines the display of the text.", py::arg("theGroup"), py::arg("theAspect"), py::arg("theText"), py::arg("theAttachmentPoint"));
cls_Prs3d_Text.def_static("Draw_", [](const opencascade::handle<Graphic3d_Group> & a0, const opencascade::handle<Prs3d_TextAspect> & a1, const TCollection_ExtendedString & a2, const gp_Ax2 & a3) -> void { return Prs3d_Text::Draw(a0, a1, a2, a3); });
cls_Prs3d_Text.def_static("Draw_", (void (*)(const opencascade::handle<Graphic3d_Group> &, const opencascade::handle<Prs3d_TextAspect> &, const TCollection_ExtendedString &, const gp_Ax2 &, const Standard_Boolean)) &Prs3d_Text::Draw, "Draws the text label.", py::arg("theGroup"), py::arg("theAspect"), py::arg("theText"), py::arg("theOrientation"), py::arg("theHasOwnAnchor"));
cls_Prs3d_Text.def_static("Draw_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &)) &Prs3d_Text::Draw, "Alias to another method Draw() for backward compatibility.", py::arg("thePrs"), py::arg("theDrawer"), py::arg("theText"), py::arg("theAttachmentPoint"));
cls_Prs3d_Text.def_static("Draw_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_TextAspect> & a1, const TCollection_ExtendedString & a2, const gp_Ax2 & a3) -> void { return Prs3d_Text::Draw(a0, a1, a2, a3); });
cls_Prs3d_Text.def_static("Draw_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_TextAspect> &, const TCollection_ExtendedString &, const gp_Ax2 &, const Standard_Boolean)) &Prs3d_Text::Draw, "Alias to another method Draw() for backward compatibility.", py::arg("thePrs"), py::arg("theAspect"), py::arg("theText"), py::arg("theOrientation"), py::arg("theHasOwnAnchor"));
cls_Prs3d_Text.def_static("Draw_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_TextAspect> &, const TCollection_ExtendedString &, const gp_Pnt &)) &Prs3d_Text::Draw, "Alias to another method Draw() for backward compatibility.", py::arg("thePrs"), py::arg("theAspect"), py::arg("theText"), py::arg("theAttachmentPoint"));

// Enums

}