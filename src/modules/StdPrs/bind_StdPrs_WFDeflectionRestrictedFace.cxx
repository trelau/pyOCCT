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
#include <Prs3d_Drawer.hxx>
#include <Standard_TypeDef.hxx>
#include <Prs3d_NListOfSequenceOfPnt.hxx>
#include <StdPrs_WFDeflectionRestrictedFace.hxx>

void bind_StdPrs_WFDeflectionRestrictedFace(py::module &mod){

py::class_<StdPrs_WFDeflectionRestrictedFace, std::unique_ptr<StdPrs_WFDeflectionRestrictedFace, Deleter<StdPrs_WFDeflectionRestrictedFace>>, Prs3d_Root> cls_StdPrs_WFDeflectionRestrictedFace(mod, "StdPrs_WFDeflectionRestrictedFace", "A framework to provide display of U and V isoparameters of faces, while allowing you to impose a deflection on them. Computes the wireframe presentation of faces with restrictions by displaying a given number of U and/or V isoparametric curves. The isoparametric curves are drawn with respect to a maximal chordial deviation. The presentation includes the restriction curves.");

// Constructors

// Fields

// Methods
// cls_StdPrs_WFDeflectionRestrictedFace.def_static("operator new_", (void * (*)(size_t)) &StdPrs_WFDeflectionRestrictedFace::operator new, "None", py::arg("theSize"));
// cls_StdPrs_WFDeflectionRestrictedFace.def_static("operator delete_", (void (*)(void *)) &StdPrs_WFDeflectionRestrictedFace::operator delete, "None", py::arg("theAddress"));
// cls_StdPrs_WFDeflectionRestrictedFace.def_static("operator new[]_", (void * (*)(size_t)) &StdPrs_WFDeflectionRestrictedFace::operator new[], "None", py::arg("theSize"));
// cls_StdPrs_WFDeflectionRestrictedFace.def_static("operator delete[]_", (void (*)(void *)) &StdPrs_WFDeflectionRestrictedFace::operator delete[], "None", py::arg("theAddress"));
// cls_StdPrs_WFDeflectionRestrictedFace.def_static("operator new_", (void * (*)(size_t, void *)) &StdPrs_WFDeflectionRestrictedFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdPrs_WFDeflectionRestrictedFace.def_static("operator delete_", (void (*)(void *, void *)) &StdPrs_WFDeflectionRestrictedFace::operator delete, "None", py::arg(""), py::arg(""));
cls_StdPrs_WFDeflectionRestrictedFace.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_WFDeflectionRestrictedFace::Add, "Defines a display featuring U and V isoparameters. Adds the surface aFace to the StdPrs_WFRestrictedFace algorithm. This face is found in a shape in the presentation object aPresentation, and its display attributes - in particular, the number of U and V isoparameters - are set in the attribute manager aDrawer. aFace is BRepAdaptor_HSurface surface created from a face in a topological shape. which is passed as an argument through the BRepAdaptor_HSurface surface created from it. This is what allows the topological face to be treated as a geometric surface.", py::arg("aPresentation"), py::arg("aFace"), py::arg("aDrawer"));
cls_StdPrs_WFDeflectionRestrictedFace.def_static("AddUIso_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_WFDeflectionRestrictedFace::AddUIso, "Defines a display featuring U isoparameters respectively. Add the surface aFace to the StdPrs_WFRestrictedFace algorithm. This face is found in a shape in the presentation object aPresentation, and its display attributes - in particular, the number of U isoparameters - are set in the attribute manager aDrawer. aFace is BRepAdaptor_HSurface surface created from a face in a topological shape. which is passed to the function as an argument through the BRepAdaptor_HSurface surface created from it. This is what allows the topological face to be treated as a geometric surface.", py::arg("aPresentation"), py::arg("aFace"), py::arg("aDrawer"));
cls_StdPrs_WFDeflectionRestrictedFace.def_static("AddVIso_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_WFDeflectionRestrictedFace::AddVIso, "Defines a display featuring V isoparameters respectively. Add the surface aFace to the StdPrs_WFRestrictedFace algorithm. This face is found in a shape in the presentation object aPresentation, and its display attributes - in particular, the number of V isoparameters - are set in the attribute manager aDrawer. aFace is BRepAdaptor_HSurface surface created from a face in a topological shape. which is passed to the function as an argument through the BRepAdaptor_HSurface surface created from it. This is what allows the topological face to be treated as a geometric surface.", py::arg("aPresentation"), py::arg("aFace"), py::arg("aDrawer"));
cls_StdPrs_WFDeflectionRestrictedFace.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<BRepAdaptor_HSurface> &, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Integer, const Standard_Integer, const opencascade::handle<Prs3d_Drawer> &, Prs3d_NListOfSequenceOfPnt &)) &StdPrs_WFDeflectionRestrictedFace::Add, "Defines a display of a delection-specified face. The display will feature U and V isoparameters. Adds the topology aShape to the StdPrs_WFRestrictedFace algorithm. This shape is found in the presentation object aPresentation, and its display attributes - except the number of U and V isoparameters - are set in the attribute manager aDrawer. The function sets the number of U and V isoparameters, NBUiso and NBViso, in the shape. To do this, the arguments DrawUIso and DrawVIso must be true. aFace is BRepAdaptor_HSurface surface created from a face in a topological shape. which is passed as an argument through the BRepAdaptor_HSurface surface created from it. This is what allows the topological face to be treated as a geometric surface. Curves give a sequence of face curves, it is used if the PrimitiveArray visualization approach is activated (it is activated by default).", py::arg("aPresentation"), py::arg("aFace"), py::arg("DrawUIso"), py::arg("DrawVIso"), py::arg("Deflection"), py::arg("NBUiso"), py::arg("NBViso"), py::arg("aDrawer"), py::arg("Curves"));
cls_StdPrs_WFDeflectionRestrictedFace.def_static("Match_", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_WFDeflectionRestrictedFace::Match, "None", py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("aDistance"), py::arg("aFace"), py::arg("aDrawer"));
cls_StdPrs_WFDeflectionRestrictedFace.def_static("MatchUIso_", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_WFDeflectionRestrictedFace::MatchUIso, "None", py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("aDistance"), py::arg("aFace"), py::arg("aDrawer"));
cls_StdPrs_WFDeflectionRestrictedFace.def_static("MatchVIso_", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_WFDeflectionRestrictedFace::MatchVIso, "None", py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("aDistance"), py::arg("aFace"), py::arg("aDrawer"));
cls_StdPrs_WFDeflectionRestrictedFace.def_static("Match_", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Boolean, const Standard_Boolean, const Standard_Real, const Standard_Integer, const Standard_Integer)) &StdPrs_WFDeflectionRestrictedFace::Match, "None", py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("aDistance"), py::arg("aFace"), py::arg("aDrawer"), py::arg("DrawUIso"), py::arg("DrawVIso"), py::arg("aDeflection"), py::arg("NBUiso"), py::arg("NBViso"));

// Enums

}