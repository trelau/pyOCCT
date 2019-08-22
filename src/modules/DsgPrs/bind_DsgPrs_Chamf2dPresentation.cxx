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
#include <Standard_Handle.hxx>
#include <Prs3d_Presentation.hxx>
#include <Prs3d_Drawer.hxx>
#include <gp_Pnt.hxx>
#include <TCollection_ExtendedString.hxx>
#include <DsgPrs_ArrowSide.hxx>
#include <DsgPrs_Chamf2dPresentation.hxx>

void bind_DsgPrs_Chamf2dPresentation(py::module &mod){

py::class_<DsgPrs_Chamf2dPresentation> cls_DsgPrs_Chamf2dPresentation(mod, "DsgPrs_Chamf2dPresentation", "Framework for display of 2D chamfers.");

// Constructors

// Fields

// Methods
// cls_DsgPrs_Chamf2dPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_Chamf2dPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_Chamf2dPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_Chamf2dPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_Chamf2dPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_Chamf2dPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_Chamf2dPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_Chamf2dPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_Chamf2dPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_Chamf2dPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_Chamf2dPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_Chamf2dPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_Chamf2dPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Pnt &, const gp_Pnt &, const TCollection_ExtendedString &)) &DsgPrs_Chamf2dPresentation::Add, "Defines the display of elements showing 2D chamfers on shapes. These include the text aText, the point of attachment, aPntAttach and the end point aPntEnd. These arguments are added to the presentation object aPresentation. Their display attributes are defined by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aPntAttach"), py::arg("aPntEnd"), py::arg("aText"));
cls_DsgPrs_Chamf2dPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Pnt &, const gp_Pnt &, const TCollection_ExtendedString &, const DsgPrs_ArrowSide)) &DsgPrs_Chamf2dPresentation::Add, "Defines the display of texts, symbols and icons used to present 2D chamfers. These include the text aText, the point of attachment, aPntAttach and the end point aPntEnd. These arguments are added to the presentation object aPresentation. Their display attributes are defined by the attribute manager aDrawer. The arrow at the point of attachment has a display defined by a value of the enumeration DsgPrs_Arrowside.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aPntAttach"), py::arg("aPntEnd"), py::arg("aText"), py::arg("ArrowSide"));

// Enums

}