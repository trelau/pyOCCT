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
#include <gp_Ax2.hxx>
#include <gp_Elips.hxx>
#include <DsgPrs_IdenticPresentation.hxx>

void bind_DsgPrs_IdenticPresentation(py::module &mod){

py::class_<DsgPrs_IdenticPresentation, std::unique_ptr<DsgPrs_IdenticPresentation>> cls_DsgPrs_IdenticPresentation(mod, "DsgPrs_IdenticPresentation", "None");

// Constructors

// Fields

// Methods
// cls_DsgPrs_IdenticPresentation.def_static("operator new_", (void * (*)(size_t)) &DsgPrs_IdenticPresentation::operator new, "None", py::arg("theSize"));
// cls_DsgPrs_IdenticPresentation.def_static("operator delete_", (void (*)(void *)) &DsgPrs_IdenticPresentation::operator delete, "None", py::arg("theAddress"));
// cls_DsgPrs_IdenticPresentation.def_static("operator new[]_", (void * (*)(size_t)) &DsgPrs_IdenticPresentation::operator new[], "None", py::arg("theSize"));
// cls_DsgPrs_IdenticPresentation.def_static("operator delete[]_", (void (*)(void *)) &DsgPrs_IdenticPresentation::operator delete[], "None", py::arg("theAddress"));
// cls_DsgPrs_IdenticPresentation.def_static("operator new_", (void * (*)(size_t, void *)) &DsgPrs_IdenticPresentation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_DsgPrs_IdenticPresentation.def_static("operator delete_", (void (*)(void *, void *)) &DsgPrs_IdenticPresentation::operator delete, "None", py::arg(""), py::arg(""));
cls_DsgPrs_IdenticPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &)) &DsgPrs_IdenticPresentation::Add, "draws a line between <aPntAttach> and <aPntOffset>.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("aPntAttach"), py::arg("aPntOffset"));
cls_DsgPrs_IdenticPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &)) &DsgPrs_IdenticPresentation::Add, "draws the 'identic' presentation by drawing a line between <aFAttach> and <aSAttach> , and a linkimg segment between <aPntOffset> and its projection on the precedent line.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("aFAttach"), py::arg("aSAttach"), py::arg("aPntOffset"));
cls_DsgPrs_IdenticPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Ax2 &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &)) &DsgPrs_IdenticPresentation::Add, "draws the 'identic' presentation in the case of circles : draws an arc of circle between <aFAttach> and <aSAttach> of center <aCenter> and of radius dist(aCenter, aFAttach), and draws a segment between <aPntOffset> and its projection on the arc.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("aAx2"), py::arg("aCenter"), py::arg("aFAttach"), py::arg("aSAttach"), py::arg("aPntOffset"));
cls_DsgPrs_IdenticPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Ax2 &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &)) &DsgPrs_IdenticPresentation::Add, "draws the 'identic' presentation in the case of circles : draws an arc of circle between <aFAttach> and <aSAttach> of center <aCenter> and of radius dist(aCenter, aFAttach), and draws a segment between <aPntOffset> and <aPntOnCirc>", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("aAx2"), py::arg("aCenter"), py::arg("aFAttach"), py::arg("aSAttach"), py::arg("aPntOffset"), py::arg("aPntOnCirc"));
cls_DsgPrs_IdenticPresentation.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const TCollection_ExtendedString &, const gp_Elips &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &)) &DsgPrs_IdenticPresentation::Add, "draws the 'identic' presentation in the case of ellipses: draws an arc of the anEllipse between <aFAttach> and <aSAttach> and draws a segment between <aPntOffset> and <aPntOnElli>", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("aText"), py::arg("anEllipse"), py::arg("aFAttach"), py::arg("aSAttach"), py::arg("aPntOffset"), py::arg("aPntOnElli"));

// Enums

}