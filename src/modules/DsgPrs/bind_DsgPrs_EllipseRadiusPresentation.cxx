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
#include <Standard_TypeDef.hxx>
#include <TCollection_ExtendedString.hxx>
#include <gp_Pnt.hxx>
#include <DsgPrs_ArrowSide.hxx>
#include <gp_Elips.hxx>
#include <Geom_OffsetCurve.hxx>
#include <DsgPrs_EllipseRadiusPresentation.hxx>

void bind_DsgPrs_EllipseRadiusPresentation(py::module &mod){

py::class_<DsgPrs_EllipseRadiusPresentation, std::unique_ptr<DsgPrs_EllipseRadiusPresentation, Deleter<DsgPrs_EllipseRadiusPresentation>>> cls_DsgPrs_EllipseRadiusPresentation(mod, "DsgPrs_EllipseRadiusPresentation", "None");

// Constructors

// Fields

// Methods
// cls_DsgPrs_EllipseRadiusPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_EllipseRadiusPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_EllipseRadiusPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_EllipseRadiusPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_EllipseRadiusPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_EllipseRadiusPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_EllipseRadiusPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_EllipseRadiusPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_EllipseRadiusPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_EllipseRadiusPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_EllipseRadiusPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_EllipseRadiusPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_EllipseRadiusPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean, const DsgPrs_ArrowSide)) &DsgPrs_EllipseRadiusPresentation::Add, "draws a Radius (Major or Minor) representation for whole ellipse case", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("theval"), py::arg("aText"), py::arg("AttachmentPoint"), py::arg("anEndOfArrow"), py::arg("aCenter"), py::arg("IsMaxRadius"), py::arg("ArrowSide"));
cls_DsgPrs_EllipseRadiusPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const TCollection_ExtendedString &, const gp_Elips &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const DsgPrs_ArrowSide)) &DsgPrs_EllipseRadiusPresentation::Add, "draws a Radius (Major or Minor) representation for arc of an ellipse case", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("theval"), py::arg("aText"), py::arg("anEllipse"), py::arg("AttachmentPoint"), py::arg("anEndOfArrow"), py::arg("aCenter"), py::arg("uFirst"), py::arg("IsInDomain"), py::arg("IsMaxRadius"), py::arg("ArrowSide"));
cls_DsgPrs_EllipseRadiusPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const TCollection_ExtendedString &, const opencascade::handle<Geom_OffsetCurve> &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const DsgPrs_ArrowSide)) &DsgPrs_EllipseRadiusPresentation::Add, "draws a Radius (Major or Minor) representation for arc of an offset curve from ellipse", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("theval"), py::arg("aText"), py::arg("aCurve"), py::arg("AttachmentPoint"), py::arg("anEndOfArrow"), py::arg("aCenter"), py::arg("uFirst"), py::arg("IsInDomain"), py::arg("IsMaxRadius"), py::arg("ArrowSide"));

// Enums

}