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
#include <DsgPrs_OffsetPresentation.hxx>

void bind_DsgPrs_OffsetPresentation(py::module &mod){

py::class_<DsgPrs_OffsetPresentation, std::unique_ptr<DsgPrs_OffsetPresentation, Deleter<DsgPrs_OffsetPresentation>>> cls_DsgPrs_OffsetPresentation(mod, "DsgPrs_OffsetPresentation", "A framework to define display of offsets.");

// Constructors

// Fields

// Methods
// cls_DsgPrs_OffsetPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_OffsetPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_OffsetPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_OffsetPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_OffsetPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_OffsetPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_OffsetPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_OffsetPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_OffsetPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_OffsetPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_OffsetPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_OffsetPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_OffsetPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const gp_Dir &, const gp_Pnt &)) &DsgPrs_OffsetPresentation::Add, "Defines the display of elements showing offset shapes. These include the two points of attachment AttachmentPoint1 and AttachmentPoint1, the two directions aDirection and aDirection2, and the offset point OffsetPoint. These arguments are added to the presentation object aPresentation. Their display attributes are defined by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("aDirection"), py::arg("aDirection2"), py::arg("OffsetPoint"));
cls_DsgPrs_OffsetPresentation.def_static("AddAxes_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &, const gp_Dir &, const gp_Dir &, const gp_Pnt &)) &DsgPrs_OffsetPresentation::AddAxes, "draws the representation of axes alignement Constraint between the point AttachmentPoint1 and the point AttachmentPoint2, along direction aDirection, using the offset point OffsetPoint.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("AttachmentPoint1"), py::arg("AttachmentPoint2"), py::arg("aDirection"), py::arg("aDirection2"), py::arg("OffsetPoint"));

// Enums

}