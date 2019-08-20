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
#include <TCollection_ExtendedString.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <DsgPrs_ArrowSide.hxx>
#include <gp_Pln.hxx>
#include <Geom_Surface.hxx>
#include <DsgPrs_LengthPresentation.hxx>

void bind_DsgPrs_LengthPresentation(py::module &mod){

py::class_<DsgPrs_LengthPresentation, std::unique_ptr<DsgPrs_LengthPresentation>> cls_DsgPrs_LengthPresentation(mod, "DsgPrs_LengthPresentation", "Framework for displaying lengths. The length displayed is indicated by line segments and text alone or by a combination of line segment, text and arrows at either or both of its ends.");

// Constructors

// Fields

// Methods
// cls_DsgPrs_LengthPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_LengthPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_LengthPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_LengthPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_LengthPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_LengthPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_LengthPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_LengthPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_LengthPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_LengthPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_LengthPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_LengthPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_LengthPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const gp_Pnt &)) &DsgPrs_LengthPresentation::Add, "Draws a line segment representing a length in the display aPresentation. This segment joins the points AttachmentPoint1 and AttachmentPoint2, along the direction aDirection. The text aText will be displayed at the offset point OffsetPoint. The line and text attributes are specified by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("aDirection"), py::arg("OffsetPoint"));
cls_DsgPrs_LengthPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const gp_Pnt &, const DsgPrs_ArrowSide)) &DsgPrs_LengthPresentation::Add, "Draws a line segment representing a length in the display aPresentation. This segment joins the points AttachmentPoint1 and AttachmentPoint2, along the direction aDirection. The text aText will be displayed at the offset point OffsetPoint. The value of the enumeration ArrowSide controls whether arrows will be displayed at either or both ends of the length. The line, text and arrow attributes are specified by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("aDirection"), py::arg("OffsetPoint"), py::arg("ArrowSide"));
cls_DsgPrs_LengthPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &, const gp_Pln &, const gp_Dir &, const gp_Pnt &, const DsgPrs_ArrowSide)) &DsgPrs_LengthPresentation::Add, "Draws a line segment representing a length in the display aPresentation. This segment joins the points AttachmentPoint1 and AttachmentPoint2, along the direction aDirection. The text aText will be displayed at the offset point OffsetPoint. The value of the enumeration ArrowSide controls whether arrows will be displayed at either or both ends of the length. The plane PlaneOfFaces is used if length is null. The line, text and arrow attributes are specified by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("PlaneOfFaces"), py::arg("aDirection"), py::arg("OffsetPoint"), py::arg("ArrowSide"));
cls_DsgPrs_LengthPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const opencascade::handle<Geom_Surface> &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const gp_Pnt &, const DsgPrs_ArrowSide)) &DsgPrs_LengthPresentation::Add, "Draws a line segment representing a length in the display aPresentation. This segment joins the points AttachmentPoint1 and AttachmentPoint2, along the direction aDirection. AttachmentPoint2 lies on the curvilinear faces SecondSurf. The text aText will be displayed at the offset point OffsetPoint. The value of the enumeration ArrowSide controls whether arrows will be displayed at either or both ends of the length. The line, text and arrow attributes are specified by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("SecondSurf"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("aDirection"), py::arg("OffsetPoint"), py::arg("ArrowSide"));
cls_DsgPrs_LengthPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const gp_Pnt &, const gp_Pnt &, const DsgPrs_ArrowSide)) &DsgPrs_LengthPresentation::Add, "Draws a line segment representing a length in the display aPresentation. This segment joins the points AttachmentPoint1 and AttachmentPoint2, along the direction aDirection. The value of the enumeration ArrowSide controls whether arrows will be displayed at either or both ends of the length. The line and arrow attributes are specified by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("Pt1"), py::arg("Pt2"), py::arg("ArrowSide"));

// Enums

}