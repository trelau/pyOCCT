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
#include <Prs3d_Presentation.hxx>
#include <BRepAdaptor_HSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <Prs3d_Drawer.hxx>
#include <Prs3d_NListOfSequenceOfPnt.hxx>
#include <StdPrs_WFRestrictedFace.hxx>

void bind_StdPrs_WFRestrictedFace(py::module &mod){

py::class_<StdPrs_WFRestrictedFace, Prs3d_Root> cls_StdPrs_WFRestrictedFace(mod, "StdPrs_WFRestrictedFace", "None");

// Constructors

// Fields

// Methods
// cls_StdPrs_WFRestrictedFace.def_static("operator new_", (void * (*)(size_t)) &StdPrs_WFRestrictedFace::operator new, "None", py::arg("theSize"));
// cls_StdPrs_WFRestrictedFace.def_static("operator delete_", (void (*)(void *)) &StdPrs_WFRestrictedFace::operator delete, "None", py::arg("theAddress"));
// cls_StdPrs_WFRestrictedFace.def_static("operator new[]_", (void * (*)(size_t)) &StdPrs_WFRestrictedFace::operator new[], "None", py::arg("theSize"));
// cls_StdPrs_WFRestrictedFace.def_static("operator delete[]_", (void (*)(void *)) &StdPrs_WFRestrictedFace::operator delete[], "None", py::arg("theAddress"));
// cls_StdPrs_WFRestrictedFace.def_static("operator new_", (void * (*)(size_t, void *)) &StdPrs_WFRestrictedFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdPrs_WFRestrictedFace.def_static("operator delete_", (void (*)(void *, void *)) &StdPrs_WFRestrictedFace::operator delete, "None", py::arg(""), py::arg(""));
cls_StdPrs_WFRestrictedFace.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<BRepAdaptor_HSurface> &, const Standard_Boolean, const Standard_Boolean, const Standard_Integer, const Standard_Integer, const opencascade::handle<Prs3d_Drawer> &, Prs3d_NListOfSequenceOfPnt &)) &StdPrs_WFRestrictedFace::Add, "None", py::arg("thePresentation"), py::arg("theFace"), py::arg("theDrawUIso"), py::arg("theDrawVIso"), py::arg("theNbUIso"), py::arg("theNbVIso"), py::arg("theDrawer"), py::arg("theCurves"));
cls_StdPrs_WFRestrictedFace.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_WFRestrictedFace::Add, "None", py::arg("thePresentation"), py::arg("theFace"), py::arg("theDrawer"));
cls_StdPrs_WFRestrictedFace.def_static("Match_", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const opencascade::handle<BRepAdaptor_HSurface> &, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Integer, const Standard_Integer, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_WFRestrictedFace::Match, "None", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theDistance"), py::arg("theFace"), py::arg("theDrawUIso"), py::arg("theDrawVIso"), py::arg("theDeflection"), py::arg("theNbUIso"), py::arg("theNbVIso"), py::arg("theDrawer"));
cls_StdPrs_WFRestrictedFace.def_static("Match_", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_WFRestrictedFace::Match, "None", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theDistance"), py::arg("theFace"), py::arg("theDrawer"));
cls_StdPrs_WFRestrictedFace.def_static("MatchUIso_", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_WFRestrictedFace::MatchUIso, "None", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theDistance"), py::arg("theFace"), py::arg("theDrawer"));
cls_StdPrs_WFRestrictedFace.def_static("MatchVIso_", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_WFRestrictedFace::MatchVIso, "None", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theDistance"), py::arg("theFace"), py::arg("theDrawer"));
cls_StdPrs_WFRestrictedFace.def_static("AddUIso_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_WFRestrictedFace::AddUIso, "None", py::arg("thePresentation"), py::arg("theFace"), py::arg("theDrawer"));
cls_StdPrs_WFRestrictedFace.def_static("AddVIso_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_WFRestrictedFace::AddVIso, "None", py::arg("thePresentation"), py::arg("theFace"), py::arg("theDrawer"));

// Enums

}