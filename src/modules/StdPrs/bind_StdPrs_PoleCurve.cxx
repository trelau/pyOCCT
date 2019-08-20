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
#include <Adaptor3d_Curve.hxx>
#include <Prs3d_Drawer.hxx>
#include <Standard_TypeDef.hxx>
#include <StdPrs_PoleCurve.hxx>

void bind_StdPrs_PoleCurve(py::module &mod){

py::class_<StdPrs_PoleCurve, std::unique_ptr<StdPrs_PoleCurve>, Prs3d_Root> cls_StdPrs_PoleCurve(mod, "StdPrs_PoleCurve", "A framework to provide display of Bezier or BSpline curves (by drawing a broken line linking the poles of the curve).");

// Constructors

// Fields

// Methods
// cls_StdPrs_PoleCurve.def_static("operator new_", (void * (*)(size_t)) &StdPrs_PoleCurve::operator new, "None", py::arg("theSize"));
// cls_StdPrs_PoleCurve.def_static("operator delete_", (void (*)(void *)) &StdPrs_PoleCurve::operator delete, "None", py::arg("theAddress"));
// cls_StdPrs_PoleCurve.def_static("operator new[]_", (void * (*)(size_t)) &StdPrs_PoleCurve::operator new[], "None", py::arg("theSize"));
// cls_StdPrs_PoleCurve.def_static("operator delete[]_", (void (*)(void *)) &StdPrs_PoleCurve::operator delete[], "None", py::arg("theAddress"));
// cls_StdPrs_PoleCurve.def_static("operator new_", (void * (*)(size_t, void *)) &StdPrs_PoleCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdPrs_PoleCurve.def_static("operator delete_", (void (*)(void *, void *)) &StdPrs_PoleCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_StdPrs_PoleCurve.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const Adaptor3d_Curve &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_PoleCurve::Add, "Defines display of BSpline and Bezier curves. Adds the 3D curve aCurve to the StdPrs_PoleCurve algorithm. This shape is found in the presentation object aPresentation, and its display attributes are set in the attribute manager aDrawer. The curve object from Adaptor3d provides data from a Geom curve. This makes it possible to use the surface in a geometric algorithm.", py::arg("aPresentation"), py::arg("aCurve"), py::arg("aDrawer"));
cls_StdPrs_PoleCurve.def_static("Match_", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Adaptor3d_Curve &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_PoleCurve::Match, "returns true if the distance between the point (X,Y,Z) and the broken line made of the poles is less then aDistance.", py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("aDistance"), py::arg("aCurve"), py::arg("aDrawer"));
cls_StdPrs_PoleCurve.def_static("Pick_", (Standard_Integer (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Adaptor3d_Curve &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_PoleCurve::Pick, "returns the pole the most near of the point (X,Y,Z) and returns its range. The distance between the pole and (X,Y,Z) must be less then aDistance. If no pole corresponds, 0 is returned.", py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("aDistance"), py::arg("aCurve"), py::arg("aDrawer"));

// Enums

}