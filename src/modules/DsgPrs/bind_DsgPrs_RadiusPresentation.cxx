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
#include <Standard_TypeDef.hxx>
#include <DsgPrs_ArrowSide.hxx>
#include <DsgPrs_RadiusPresentation.hxx>

void bind_DsgPrs_RadiusPresentation(py::module &mod){

py::class_<DsgPrs_RadiusPresentation, std::unique_ptr<DsgPrs_RadiusPresentation, Deleter<DsgPrs_RadiusPresentation>>> cls_DsgPrs_RadiusPresentation(mod, "DsgPrs_RadiusPresentation", "A framework to define display of radii.");

// Constructors

// Fields

// Methods
// cls_DsgPrs_RadiusPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_RadiusPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_RadiusPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_RadiusPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_RadiusPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_RadiusPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_RadiusPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_RadiusPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_RadiusPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_RadiusPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_RadiusPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_RadiusPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_RadiusPresentation.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TCollection_ExtendedString & a2, const gp_Pnt & a3, const gp_Circ & a4, const Standard_Real a5, const Standard_Real a6) -> void { return DsgPrs_RadiusPresentation::Add(a0, a1, a2, a3, a4, a5, a6); });
cls_DsgPrs_RadiusPresentation.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TCollection_ExtendedString & a2, const gp_Pnt & a3, const gp_Circ & a4, const Standard_Real a5, const Standard_Real a6, const Standard_Boolean a7) -> void { return DsgPrs_RadiusPresentation::Add(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_DsgPrs_RadiusPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Circ &, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean)) &DsgPrs_RadiusPresentation::Add, "Adds the point AttachmentPoint, the circle aCircle, the text aText, and the parameters firstparam and lastparam to the presentation object aPresentation. The display attributes of these elements is defined by the attribute manager aDrawer. If the Boolean drawFromCenter is false, the arrowhead will point towards the center of aCircle. If the Boolean reverseArrow is true, the arrowhead will point away from the attachment point.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("AttachmentPoint"), py::arg("aCircle"), py::arg("firstparam"), py::arg("lastparam"), py::arg("drawFromCenter"), py::arg("reverseArrow"));
// cls_DsgPrs_RadiusPresentation.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TCollection_ExtendedString & a2, const gp_Pnt & a3, const gp_Circ & a4, const Standard_Real a5, const Standard_Real a6, const DsgPrs_ArrowSide a7) -> void { return DsgPrs_RadiusPresentation::Add(a0, a1, a2, a3, a4, a5, a6, a7); });
// cls_DsgPrs_RadiusPresentation.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TCollection_ExtendedString & a2, const gp_Pnt & a3, const gp_Circ & a4, const Standard_Real a5, const Standard_Real a6, const DsgPrs_ArrowSide a7, const Standard_Boolean a8) -> void { return DsgPrs_RadiusPresentation::Add(a0, a1, a2, a3, a4, a5, a6, a7, a8); });
// cls_DsgPrs_RadiusPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Circ &, const Standard_Real, const Standard_Real, const DsgPrs_ArrowSide, const Standard_Boolean, const Standard_Boolean)) &DsgPrs_RadiusPresentation::Add, "Adds the point AttachmentPoint, the circle aCircle, the text aText, and the parameters firstparam and lastparam to the presentation object aPresentation. The display attributes of these elements is defined by the attribute manager aDrawer. The value of the enumeration Arrowside determines the type of arrow displayed: whether there will be arrowheads at both ends or only one, for example. If the Boolean drawFromCenter is false, the arrowhead will point towards the center of aCircle. If the Boolean reverseArrow is true, the arrowhead will point away from the attachment point.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("AttachmentPoint"), py::arg("aCircle"), py::arg("firstparam"), py::arg("lastparam"), py::arg("ArrowSide"), py::arg("drawFromCenter"), py::arg("reverseArrow"));
cls_DsgPrs_RadiusPresentation.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TCollection_ExtendedString & a2, const gp_Pnt & a3, const gp_Pnt & a4, const gp_Pnt & a5, const DsgPrs_ArrowSide a6) -> void { return DsgPrs_RadiusPresentation::Add(a0, a1, a2, a3, a4, a5, a6); });
cls_DsgPrs_RadiusPresentation.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, const opencascade::handle<Prs3d_Drawer> & a1, const TCollection_ExtendedString & a2, const gp_Pnt & a3, const gp_Pnt & a4, const gp_Pnt & a5, const DsgPrs_ArrowSide a6, const Standard_Boolean a7) -> void { return DsgPrs_RadiusPresentation::Add(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_DsgPrs_RadiusPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const DsgPrs_ArrowSide, const Standard_Boolean, const Standard_Boolean)) &DsgPrs_RadiusPresentation::Add, "Adds the circle aCircle, the text aText, the points AttachmentPoint, Center and EndOfArrow to the presentation object aPresentation. The display attributes of these elements is defined by the attribute manager aDrawer. The value of the enumeration Arrowside determines the type of arrow displayed: whether there will be arrowheads at both ends or only one, for example. If the Boolean drawFromCenter is false, the arrowhead will point towards the center of aCircle. If the Boolean reverseArrow is true, the arrowhead will point away from the attachment point.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("AttachmentPoint"), py::arg("Center"), py::arg("EndOfArrow"), py::arg("ArrowSide"), py::arg("drawFromCenter"), py::arg("reverseArrow"));

// Enums

}