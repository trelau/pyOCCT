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
#include <gp_Circ.hxx>
#include <DsgPrs_ArrowSide.hxx>
#include <Standard_TypeDef.hxx>
#include <DsgPrs_DiameterPresentation.hxx>

void bind_DsgPrs_DiameterPresentation(py::module &mod){

py::class_<DsgPrs_DiameterPresentation, std::unique_ptr<DsgPrs_DiameterPresentation>> cls_DsgPrs_DiameterPresentation(mod, "DsgPrs_DiameterPresentation", "A framework for displaying diameters in shapes.");

// Constructors

// Fields

// Methods
// cls_DsgPrs_DiameterPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_DiameterPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_DiameterPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_DiameterPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_DiameterPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_DiameterPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_DiameterPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_DiameterPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_DiameterPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_DiameterPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_DiameterPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_DiameterPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_DiameterPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Circ &, const DsgPrs_ArrowSide, const Standard_Boolean)) &DsgPrs_DiameterPresentation::Add, "Draws the diameter of the circle aCircle displayed in the presentation aPresentation and with attributes defined by the attribute manager aDrawer. The point AttachmentPoint defines the point of contact between the circle and the diameter presentation. The value of the enumeration ArrowSide controls whether arrows will be displayed at either or both ends of the length. The text aText labels the diameter.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("AttachmentPoint"), py::arg("aCircle"), py::arg("ArrowSide"), py::arg("IsDiamSymbol"));
cls_DsgPrs_DiameterPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Circ &, const Standard_Real, const Standard_Real, const DsgPrs_ArrowSide, const Standard_Boolean)) &DsgPrs_DiameterPresentation::Add, "Draws the diameter of the arc anArc displayed in the presentation aPresentation and with attributes defined by the attribute manager aDrawer. The point AttachmentPoint defines the point of contact between the arc and the diameter presentation. The value of the enumeration ArrowSide controls whether arrows will be displayed at either or both ends of the length. The parameters uFirst and uLast define the first and last points of the arc. The text aText labels the diameter.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("AttachmentPoint"), py::arg("aCircle"), py::arg("uFirst"), py::arg("uLast"), py::arg("ArrowSide"), py::arg("IsDiamSymbol"));

// Enums

}