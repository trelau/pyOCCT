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
#include <StdPrs_DeflectionCurve.hxx>

void bind_StdPrs_DeflectionCurve(py::module &mod){

py::class_<StdPrs_DeflectionCurve, std::unique_ptr<StdPrs_DeflectionCurve, Deleter<StdPrs_DeflectionCurve>>, Prs3d_Root> cls_StdPrs_DeflectionCurve(mod, "StdPrs_DeflectionCurve", "A framework to provide display of any curve with respect to the maximal chordal deviation defined in the Prs3d_Drawer attributes manager.");

// Constructors

// Fields

// Methods
// cls_StdPrs_DeflectionCurve.def_static("operator new_", (void * (*)(size_t)) &StdPrs_DeflectionCurve::operator new, "None", py::arg("theSize"));
// cls_StdPrs_DeflectionCurve.def_static("operator delete_", (void (*)(void *)) &StdPrs_DeflectionCurve::operator delete, "None", py::arg("theAddress"));
// cls_StdPrs_DeflectionCurve.def_static("operator new[]_", (void * (*)(size_t)) &StdPrs_DeflectionCurve::operator new[], "None", py::arg("theSize"));
// cls_StdPrs_DeflectionCurve.def_static("operator delete[]_", (void (*)(void *)) &StdPrs_DeflectionCurve::operator delete[], "None", py::arg("theAddress"));
// cls_StdPrs_DeflectionCurve.def_static("operator new_", (void * (*)(size_t, void *)) &StdPrs_DeflectionCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdPrs_DeflectionCurve.def_static("operator delete_", (void (*)(void *, void *)) &StdPrs_DeflectionCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_StdPrs_DeflectionCurve.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, Adaptor3d_Curve & a1, const opencascade::handle<Prs3d_Drawer> & a2) -> void { return StdPrs_DeflectionCurve::Add(a0, a1, a2); });
cls_StdPrs_DeflectionCurve.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, Adaptor3d_Curve &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Boolean)) &StdPrs_DeflectionCurve::Add, "adds to the presentation aPresentation the drawing of the curve aCurve with respect to the maximal chordial deviation defined by the drawer aDrawer. The aspect is defined by LineAspect in aDrawer. If drawCurve equals Standard_False the curve will not be displayed, it is used if the curve is a part of some shape and PrimitiveArray visualization approach is activated (it is activated by default).", py::arg("aPresentation"), py::arg("aCurve"), py::arg("aDrawer"), py::arg("drawCurve"));
cls_StdPrs_DeflectionCurve.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, Adaptor3d_Curve & a1, const Standard_Real a2, const Standard_Real a3, const opencascade::handle<Prs3d_Drawer> & a4) -> void { return StdPrs_DeflectionCurve::Add(a0, a1, a2, a3, a4); });
cls_StdPrs_DeflectionCurve.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const opencascade::handle<Prs3d_Drawer> &, const Standard_Boolean)) &StdPrs_DeflectionCurve::Add, "adds to the presentation aPresentation the drawing of the curve aCurve with respect to the maximal chordial deviation defined by the drawer aDrawer. The aspect is defined by LineAspect in aDrawer. The drawing will be limited between the points of parameter U1 and U2. If drawCurve equals Standard_False the curve will not be displayed, it is used if the curve is a part of some shape and PrimitiveArray visualization approach is activated (it is activated by default).", py::arg("aPresentation"), py::arg("aCurve"), py::arg("U1"), py::arg("U2"), py::arg("aDrawer"), py::arg("drawCurve"));
cls_StdPrs_DeflectionCurve.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, Adaptor3d_Curve & a1, const Standard_Real a2, const Standard_Real a3) -> void { return StdPrs_DeflectionCurve::Add(a0, a1, a2, a3); });
cls_StdPrs_DeflectionCurve.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, Adaptor3d_Curve & a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4) -> void { return StdPrs_DeflectionCurve::Add(a0, a1, a2, a3, a4); });
cls_StdPrs_DeflectionCurve.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &StdPrs_DeflectionCurve::Add, "adds to the presentation aPresentation the drawing of the curve aCurve with respect to the maximal chordial deviation aDeflection. The aspect is the current aspect If drawCurve equals Standard_False the curve will not be displayed, it is used if the curve is a part of some shape and PrimitiveArray visualization approach is activated (it is activated by default).", py::arg("aPresentation"), py::arg("aCurve"), py::arg("aDeflection"), py::arg("aLimit"), py::arg("anAngle"), py::arg("drawCurve"));
cls_StdPrs_DeflectionCurve.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, Adaptor3d_Curve & a1, const Standard_Real a2, const opencascade::handle<Prs3d_Drawer> & a3, TColgp_SequenceOfPnt & a4) -> void { return StdPrs_DeflectionCurve::Add(a0, a1, a2, a3, a4); });
cls_StdPrs_DeflectionCurve.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, Adaptor3d_Curve &, const Standard_Real, const opencascade::handle<Prs3d_Drawer> &, TColgp_SequenceOfPnt &, const Standard_Boolean)) &StdPrs_DeflectionCurve::Add, "adds to the presentation aPresentation the drawing of the curve aCurve with respect to the maximal chordial deviation aDeflection. The aspect is the current aspect Points give a sequence of curve points. If drawCurve equals Standard_False the curve will not be displayed, it is used if the curve is a part of some shape and PrimitiveArray visualization approach is activated (it is activated by default).", py::arg("aPresentation"), py::arg("aCurve"), py::arg("aDeflection"), py::arg("aDrawer"), py::arg("Points"), py::arg("drawCurve"));
cls_StdPrs_DeflectionCurve.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, Adaptor3d_Curve & a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, TColgp_SequenceOfPnt & a5) -> void { return StdPrs_DeflectionCurve::Add(a0, a1, a2, a3, a4, a5); });
cls_StdPrs_DeflectionCurve.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, Adaptor3d_Curve & a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, TColgp_SequenceOfPnt & a5, const Standard_Real a6) -> void { return StdPrs_DeflectionCurve::Add(a0, a1, a2, a3, a4, a5, a6); });
cls_StdPrs_DeflectionCurve.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, TColgp_SequenceOfPnt &, const Standard_Real, const Standard_Boolean)) &StdPrs_DeflectionCurve::Add, "adds to the presentation aPresentation the drawing of the curve aCurve with respect to the maximal chordial deviation aDeflection. The aspect is the current aspect The drawing will be limited between the points of parameter U1 and U2. Points give a sequence of curve points. If drawCurve equals Standard_False the curve will not be displayed, it is used if the curve is a part of some shape and PrimitiveArray visualization approach is activated (it is activated by default).", py::arg("aPresentation"), py::arg("aCurve"), py::arg("U1"), py::arg("U2"), py::arg("aDeflection"), py::arg("Points"), py::arg("anAngle"), py::arg("drawCurve"));
cls_StdPrs_DeflectionCurve.def_static("Match_", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Adaptor3d_Curve &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_DeflectionCurve::Match, "returns true if the distance between the point (X,Y,Z) and the drawing of the curve aCurve with respect of the maximal chordial deviation defined by the drawer aDrawer is less then aDistance.", py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("aDistance"), py::arg("aCurve"), py::arg("aDrawer"));
cls_StdPrs_DeflectionCurve.def_static("Match_", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_DeflectionCurve::Match, "returns true if the distance between the point (X,Y,Z) and the drawing of the curve aCurve with respect of the maximal chordial deviation defined by the drawer aDrawer is less then aDistance. The drawing is considered between the points of parameter U1 and U2;", py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("aDistance"), py::arg("aCurve"), py::arg("U1"), py::arg("U2"), py::arg("aDrawer"));
cls_StdPrs_DeflectionCurve.def_static("Match_", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real)) &StdPrs_DeflectionCurve::Match, "Returns true if the distance between the point (theX, theY, theZ) and the drawing with respect of the maximal chordial deviation theDeflection is less then theDistance.", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theDistance"), py::arg("theCurve"), py::arg("theDeflection"), py::arg("theLimit"), py::arg("theAngle"));
cls_StdPrs_DeflectionCurve.def_static("Match_", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Adaptor3d_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &StdPrs_DeflectionCurve::Match, "Returns true if the distance between the point (theX, theY, theZ) and the drawing with respect of the maximal chordial deviation theDeflection is less then theDistance. The drawing is considered between the points of parameter theU1 and theU2.", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theDistance"), py::arg("theCurve"), py::arg("theU1"), py::arg("theU2"), py::arg("theDeflection"), py::arg("theAngle"));

// Enums

}