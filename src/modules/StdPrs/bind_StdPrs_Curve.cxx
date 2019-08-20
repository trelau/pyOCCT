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
#include <TColgp_SequenceOfPnt.hxx>
#include <StdPrs_Curve.hxx>

void bind_StdPrs_Curve(py::module &mod){

py::class_<StdPrs_Curve, std::unique_ptr<StdPrs_Curve>, Prs3d_Root> cls_StdPrs_Curve(mod, "StdPrs_Curve", "A framework to define display of lines, arcs of circles and conic sections. This is done with a fixed number of points, which can be modified.");

// Constructors

// Fields

// Methods
// cls_StdPrs_Curve.def_static("operator new_", (void * (*)(size_t)) &StdPrs_Curve::operator new, "None", py::arg("theSize"));
// cls_StdPrs_Curve.def_static("operator delete_", (void (*)(void *)) &StdPrs_Curve::operator delete, "None", py::arg("theAddress"));
// cls_StdPrs_Curve.def_static("operator new[]_", (void * (*)(size_t)) &StdPrs_Curve::operator new[], "None", py::arg("theSize"));
// cls_StdPrs_Curve.def_static("operator delete[]_", (void (*)(void *)) &StdPrs_Curve::operator delete[], "None", py::arg("theAddress"));
// cls_StdPrs_Curve.def_static("operator new_", (void * (*)(size_t, void *)) &StdPrs_Curve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdPrs_Curve.def_static("operator delete_", (void (*)(void *, void *)) &StdPrs_Curve::operator delete, "None", py::arg(""), py::arg(""));
cls_StdPrs_Curve.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, const Adaptor3d_Curve & a1, const opencascade::handle<Prs3d_Drawer> & a2) -> void { return StdPrs_Curve::Add(a0, a1, a2); });
cls_StdPrs_Curve.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const Adaptor3d_Curve &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Boolean)) &StdPrs_Curve::Add, "Adds to the presentation aPresentation the drawing of the curve aCurve. The aspect is defined by LineAspect in aDrawer. If drawCurve equals Standard_False the curve will not be displayed, it is used if the curve is a part of some shape and PrimitiveArray visualization approach is activated (it is activated by default).", py::arg("aPresentation"), py::arg("aCurve"), py::arg("aDrawer"), py::arg("drawCurve"));
cls_StdPrs_Curve.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, const Adaptor3d_Curve & a1, const Standard_Real a2, const Standard_Real a3, const opencascade::handle<Prs3d_Drawer> & a4) -> void { return StdPrs_Curve::Add(a0, a1, a2, a3, a4); });
cls_StdPrs_Curve.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const opencascade::handle<Prs3d_Drawer> &, const Standard_Boolean)) &StdPrs_Curve::Add, "Adds to the presentation aPresentation the drawing of the curve aCurve. The aspect is defined by LineAspect in aDrawer. The drawing will be limited between the points of parameter U1 and U2. If drawCurve equals Standard_False the curve will not be displayed, it is used if the curve is a part of some shape and PrimitiveArray visualization approach is activated (it is activated by default).", py::arg("aPresentation"), py::arg("aCurve"), py::arg("U1"), py::arg("U2"), py::arg("aDrawer"), py::arg("drawCurve"));
cls_StdPrs_Curve.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, const Adaptor3d_Curve & a1, const opencascade::handle<Prs3d_Drawer> & a2, TColgp_SequenceOfPnt & a3) -> void { return StdPrs_Curve::Add(a0, a1, a2, a3); });
cls_StdPrs_Curve.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const Adaptor3d_Curve &, const opencascade::handle<Prs3d_Drawer> &, TColgp_SequenceOfPnt &, const Standard_Boolean)) &StdPrs_Curve::Add, "adds to the presentation aPresentation the drawing of the curve aCurve. The aspect is the current aspect. aDeflection is used in the circle case. Points give a sequence of curve points. If drawCurve equals Standard_False the curve will not be displayed, it is used if the curve is a part of some shape and PrimitiveArray visualization approach is activated (it is activated by default).", py::arg("aPresentation"), py::arg("aCurve"), py::arg("aDrawer"), py::arg("Points"), py::arg("drawCurve"));
cls_StdPrs_Curve.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, const Adaptor3d_Curve & a1, const Standard_Real a2, const Standard_Real a3, TColgp_SequenceOfPnt & a4) -> void { return StdPrs_Curve::Add(a0, a1, a2, a3, a4); });
cls_StdPrs_Curve.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, const Adaptor3d_Curve & a1, const Standard_Real a2, const Standard_Real a3, TColgp_SequenceOfPnt & a4, const Standard_Integer a5) -> void { return StdPrs_Curve::Add(a0, a1, a2, a3, a4, a5); });
cls_StdPrs_Curve.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, TColgp_SequenceOfPnt &, const Standard_Integer, const Standard_Boolean)) &StdPrs_Curve::Add, "adds to the presentation aPresentation the drawing of the curve aCurve. The aspect is the current aspect. The drawing will be limited between the points of parameter U1 and U2. aDeflection is used in the circle case. Points give a sequence of curve points. If drawCurve equals Standard_False the curve will not be displayed, it is used if the curve is a part of some shape and PrimitiveArray visualization approach is activated (it is activated by default).", py::arg("aPresentation"), py::arg("aCurve"), py::arg("U1"), py::arg("U2"), py::arg("Points"), py::arg("aNbPoints"), py::arg("drawCurve"));
cls_StdPrs_Curve.def_static("Match_", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Adaptor3d_Curve &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_Curve::Match, "returns true if the distance between the point (X,Y,Z) and the drawing of the curve is less than aDistance.", py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("aDistance"), py::arg("aCurve"), py::arg("aDrawer"));
cls_StdPrs_Curve.def_static("Match_", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Integer)) &StdPrs_Curve::Match, "returns true if the distance between the point (X,Y,Z) and the drawing of the curve is less than aDistance.", py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("aDistance"), py::arg("aCurve"), py::arg("aDeflection"), py::arg("aLimit"), py::arg("aNbPoints"));
cls_StdPrs_Curve.def_static("Match_", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_Curve::Match, "returns true if the distance between the point (X,Y,Z) and the drawing of the curve aCurve is less than aDistance. The drawing is considered between the points of parameter U1 and U2;", py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("aDistance"), py::arg("aCurve"), py::arg("U1"), py::arg("U2"), py::arg("aDrawer"));
cls_StdPrs_Curve.def_static("Match_", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer)) &StdPrs_Curve::Match, "returns true if the distance between the point (X,Y,Z) and the drawing of the curve aCurve is less than aDistance. The drawing is considered between the points of parameter U1 and U2;", py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("aDistance"), py::arg("aCurve"), py::arg("U1"), py::arg("U2"), py::arg("aDeflection"), py::arg("aNbPoints"));

// Enums

}