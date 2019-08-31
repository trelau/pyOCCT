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
#include <StdPrs_Volume.hxx>
#include <Prs3d_Root.hxx>
#include <Standard_Handle.hxx>
#include <Prs3d_Presentation.hxx>
#include <Bnd_Box.hxx>
#include <Prs3d_Drawer.hxx>
#include <StdPrs_BndBox.hxx>
#include <Standard.hxx>
#include <Adaptor3d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <StdPrs_Curve.hxx>
#include <StdPrs_DeflectionCurve.hxx>
#include <TopoDS_Shape.hxx>
#include <Prs3d_Projector.hxx>
#include <StdPrs_HLRPolyShape.hxx>
#include <StdPrs_HLRShape.hxx>
#include <HLRAlgo_Projector.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <HLRBRep_Data.hxx>
#include <HLRAlgo_EdgeIterator.hxx>
#include <StdPrs_HLRToolShape.hxx>
#include <TopoDS_Face.hxx>
#include <Poly_Triangulation.hxx>
#include <Poly_Connect.hxx>
#include <TColgp_Array1OfDir.hxx>
#include <StdPrs_ToolTriangulatedShape.hxx>
#include <Prs3d_NListOfSequenceOfPnt.hxx>
#include <Geom_Surface.hxx>
#include <TopLoc_Location.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <BRepAdaptor_HSurface.hxx>
#include <gp_Pnt.hxx>
#include <StdPrs_Isolines.hxx>
#include <gp_Lin2d.hxx>
#include <gp_Pnt2d.hxx>
#include <Adaptor3d_Surface.hxx>
#include <StdPrs_Plane.hxx>
#include <Geom_Point.hxx>
#include <StdPrs_ToolPoint.hxx>
#include <Prs3d_Point.hxx>
#include <StdPrs_Point.hxx>
#include <StdPrs_PoleCurve.hxx>
#include <BRep_Builder.hxx>
#include <TopoDS_Compound.hxx>
#include <Graphic3d_ArrayOfTriangles.hxx>
#include <Graphic3d_ArrayOfSegments.hxx>
#include <StdPrs_ShadedShape.hxx>
#include <StdPrs_ShadedSurface.hxx>
#include <Adaptor2d_Curve2dPtr.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopExp_Explorer.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <StdPrs_ToolRFace.hxx>
#include <TopoDS_Vertex.hxx>
#include <StdPrs_ToolVertex.hxx>
#include <StdPrs_Vertex.hxx>
#include <StdPrs_WFDeflectionRestrictedFace.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <StdPrs_WFDeflectionSurface.hxx>
#include <StdPrs_WFPoleSurface.hxx>
#include <StdPrs_WFRestrictedFace.hxx>
#include <Graphic3d_ArrayOfPrimitives.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Prs3d_PointAspect.hxx>
#include <StdPrs_WFShape.hxx>
#include <StdPrs_WFSurface.hxx>
#include <bind_Prs3d_Point.hxx>

PYBIND11_MODULE(StdPrs, mod) {

py::module::import("OCCT.Prs3d");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.HLRAlgo");
py::module::import("OCCT.BRepAdaptor");
py::module::import("OCCT.HLRBRep");
py::module::import("OCCT.Poly");
py::module::import("OCCT.Geom");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.gp");
py::module::import("OCCT.BRep");
py::module::import("OCCT.Graphic3d");
py::module::import("OCCT.Adaptor2d");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.TopExp");
py::module::import("OCCT.Geom2dAdaptor");
py::module::import("OCCT.TopTools");

// ENUM: STDPRS_VOLUME
py::enum_<StdPrs_Volume>(mod, "StdPrs_Volume", "defines the way how to interpret input shapes Volume_Autodetection to perform Autodetection (would split input shape into two groups) Volume_Closed as Closed volumes (to activate back-face culling and capping plane algorithms) Volume_Opened as Open volumes (shells or solids with holes)")
	.value("StdPrs_Volume_Autodetection", StdPrs_Volume::StdPrs_Volume_Autodetection)
	.value("StdPrs_Volume_Closed", StdPrs_Volume::StdPrs_Volume_Closed)
	.value("StdPrs_Volume_Opened", StdPrs_Volume::StdPrs_Volume_Opened)
	.export_values();


// CLASS: STDPRS_BNDBOX
py::class_<StdPrs_BndBox, Prs3d_Root> cls_StdPrs_BndBox(mod, "StdPrs_BndBox", "Tool for computing bounding box presentation.");

// Methods
cls_StdPrs_BndBox.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const Bnd_Box &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_BndBox::Add, "Computes presentation of a bounding box.", py::arg("thePresentation"), py::arg("theBndBox"), py::arg("theDrawer"));

// CLASS: STDPRS_CURVE
py::class_<StdPrs_Curve, Prs3d_Root> cls_StdPrs_Curve(mod, "StdPrs_Curve", "A framework to define display of lines, arcs of circles and conic sections. This is done with a fixed number of points, which can be modified.");

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

// CLASS: STDPRS_DEFLECTIONCURVE
py::class_<StdPrs_DeflectionCurve, Prs3d_Root> cls_StdPrs_DeflectionCurve(mod, "StdPrs_DeflectionCurve", "A framework to provide display of any curve with respect to the maximal chordal deviation defined in the Prs3d_Drawer attributes manager.");

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

// CLASS: STDPRS_HLRPOLYSHAPE
py::class_<StdPrs_HLRPolyShape, Prs3d_Root> cls_StdPrs_HLRPolyShape(mod, "StdPrs_HLRPolyShape", "Instantiates Prs3d_PolyHLRShape to define a display of a shape where hidden and visible lines are identified with respect to a given projection. StdPrs_HLRPolyShape works with a polyhedral simplification of the shape whereas StdPrs_HLRShape takes the shape itself into account. When you use StdPrs_HLRShape, you obtain an exact result, whereas, when you use StdPrs_HLRPolyShape, you reduce computation time but obtain polygonal segments. The polygonal algorithm is used.");

// Methods
// cls_StdPrs_HLRPolyShape.def_static("operator new_", (void * (*)(size_t)) &StdPrs_HLRPolyShape::operator new, "None", py::arg("theSize"));
// cls_StdPrs_HLRPolyShape.def_static("operator delete_", (void (*)(void *)) &StdPrs_HLRPolyShape::operator delete, "None", py::arg("theAddress"));
// cls_StdPrs_HLRPolyShape.def_static("operator new[]_", (void * (*)(size_t)) &StdPrs_HLRPolyShape::operator new[], "None", py::arg("theSize"));
// cls_StdPrs_HLRPolyShape.def_static("operator delete[]_", (void (*)(void *)) &StdPrs_HLRPolyShape::operator delete[], "None", py::arg("theAddress"));
// cls_StdPrs_HLRPolyShape.def_static("operator new_", (void * (*)(size_t, void *)) &StdPrs_HLRPolyShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdPrs_HLRPolyShape.def_static("operator delete_", (void (*)(void *, void *)) &StdPrs_HLRPolyShape::operator delete, "None", py::arg(""), py::arg(""));
cls_StdPrs_HLRPolyShape.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const TopoDS_Shape &, const opencascade::handle<Prs3d_Drawer> &, const opencascade::handle<Prs3d_Projector> &)) &StdPrs_HLRPolyShape::Add, "Defines the hidden line removal display of the topology aShape in the projection defined by aProjector. The shape and the projection are added to the display aPresentation, and the attributes of the elements present in the aPresentation are defined by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aShape"), py::arg("aDrawer"), py::arg("aProjector"));

// CLASS: STDPRS_HLRSHAPE
py::class_<StdPrs_HLRShape, Prs3d_Root> cls_StdPrs_HLRShape(mod, "StdPrs_HLRShape", "None");

// Methods
// cls_StdPrs_HLRShape.def_static("operator new_", (void * (*)(size_t)) &StdPrs_HLRShape::operator new, "None", py::arg("theSize"));
// cls_StdPrs_HLRShape.def_static("operator delete_", (void (*)(void *)) &StdPrs_HLRShape::operator delete, "None", py::arg("theAddress"));
// cls_StdPrs_HLRShape.def_static("operator new[]_", (void * (*)(size_t)) &StdPrs_HLRShape::operator new[], "None", py::arg("theSize"));
// cls_StdPrs_HLRShape.def_static("operator delete[]_", (void (*)(void *)) &StdPrs_HLRShape::operator delete[], "None", py::arg("theAddress"));
// cls_StdPrs_HLRShape.def_static("operator new_", (void * (*)(size_t, void *)) &StdPrs_HLRShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdPrs_HLRShape.def_static("operator delete_", (void (*)(void *, void *)) &StdPrs_HLRShape::operator delete, "None", py::arg(""), py::arg(""));
cls_StdPrs_HLRShape.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const TopoDS_Shape &, const opencascade::handle<Prs3d_Drawer> &, const opencascade::handle<Prs3d_Projector> &)) &StdPrs_HLRShape::Add, "None", py::arg("thePresentation"), py::arg("theShape"), py::arg("theDrawer"), py::arg("theProjector"));

// CLASS: STDPRS_HLRTOOLSHAPE
py::class_<StdPrs_HLRToolShape> cls_StdPrs_HLRToolShape(mod, "StdPrs_HLRToolShape", "None");

// Constructors
cls_StdPrs_HLRToolShape.def(py::init<const TopoDS_Shape &, const HLRAlgo_Projector &>(), py::arg("TheShape"), py::arg("TheProjector"));

// Methods
// cls_StdPrs_HLRToolShape.def_static("operator new_", (void * (*)(size_t)) &StdPrs_HLRToolShape::operator new, "None", py::arg("theSize"));
// cls_StdPrs_HLRToolShape.def_static("operator delete_", (void (*)(void *)) &StdPrs_HLRToolShape::operator delete, "None", py::arg("theAddress"));
// cls_StdPrs_HLRToolShape.def_static("operator new[]_", (void * (*)(size_t)) &StdPrs_HLRToolShape::operator new[], "None", py::arg("theSize"));
// cls_StdPrs_HLRToolShape.def_static("operator delete[]_", (void (*)(void *)) &StdPrs_HLRToolShape::operator delete[], "None", py::arg("theAddress"));
// cls_StdPrs_HLRToolShape.def_static("operator new_", (void * (*)(size_t, void *)) &StdPrs_HLRToolShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdPrs_HLRToolShape.def_static("operator delete_", (void (*)(void *, void *)) &StdPrs_HLRToolShape::operator delete, "None", py::arg(""), py::arg(""));
cls_StdPrs_HLRToolShape.def("NbEdges", (Standard_Integer (StdPrs_HLRToolShape::*)() const) &StdPrs_HLRToolShape::NbEdges, "None");
cls_StdPrs_HLRToolShape.def("InitVisible", (void (StdPrs_HLRToolShape::*)(const Standard_Integer)) &StdPrs_HLRToolShape::InitVisible, "None", py::arg("EdgeNumber"));
cls_StdPrs_HLRToolShape.def("MoreVisible", (Standard_Boolean (StdPrs_HLRToolShape::*)() const) &StdPrs_HLRToolShape::MoreVisible, "None");
cls_StdPrs_HLRToolShape.def("NextVisible", (void (StdPrs_HLRToolShape::*)()) &StdPrs_HLRToolShape::NextVisible, "None");
cls_StdPrs_HLRToolShape.def("Visible", [](StdPrs_HLRToolShape &self, BRepAdaptor_Curve & TheEdge, Standard_Real & U1, Standard_Real & U2){ self.Visible(TheEdge, U1, U2); return std::tuple<Standard_Real &, Standard_Real &>(U1, U2); }, "None", py::arg("TheEdge"), py::arg("U1"), py::arg("U2"));
cls_StdPrs_HLRToolShape.def("InitHidden", (void (StdPrs_HLRToolShape::*)(const Standard_Integer)) &StdPrs_HLRToolShape::InitHidden, "None", py::arg("EdgeNumber"));
cls_StdPrs_HLRToolShape.def("MoreHidden", (Standard_Boolean (StdPrs_HLRToolShape::*)() const) &StdPrs_HLRToolShape::MoreHidden, "None");
cls_StdPrs_HLRToolShape.def("NextHidden", (void (StdPrs_HLRToolShape::*)()) &StdPrs_HLRToolShape::NextHidden, "None");
cls_StdPrs_HLRToolShape.def("Hidden", [](StdPrs_HLRToolShape &self, BRepAdaptor_Curve & TheEdge, Standard_Real & U1, Standard_Real & U2){ self.Hidden(TheEdge, U1, U2); return std::tuple<Standard_Real &, Standard_Real &>(U1, U2); }, "None", py::arg("TheEdge"), py::arg("U1"), py::arg("U2"));

// CLASS: STDPRS_TOOLTRIANGULATEDSHAPE
py::class_<StdPrs_ToolTriangulatedShape> cls_StdPrs_ToolTriangulatedShape(mod, "StdPrs_ToolTriangulatedShape", "None");

// Methods
cls_StdPrs_ToolTriangulatedShape.def_static("IsTriangulated_", (Standard_Boolean (*)(const TopoDS_Shape &)) &StdPrs_ToolTriangulatedShape::IsTriangulated, "Similar to BRepTools::Triangulation() but without extra checks.", py::arg("theShape"));
cls_StdPrs_ToolTriangulatedShape.def_static("IsClosed_", (Standard_Boolean (*)(const TopoDS_Shape &)) &StdPrs_ToolTriangulatedShape::IsClosed, "Checks back faces visibility for specified shape (to activate back-face culling).", py::arg("theShape"));
cls_StdPrs_ToolTriangulatedShape.def_static("ComputeNormals_", (void (*)(const TopoDS_Face &, const opencascade::handle<Poly_Triangulation> &)) &StdPrs_ToolTriangulatedShape::ComputeNormals, "Computes nodal normals for Poly_Triangulation structure using UV coordinates and surface. Does nothing if triangulation already defines normals.", py::arg("theFace"), py::arg("theTris"));
cls_StdPrs_ToolTriangulatedShape.def_static("ComputeNormals_", (void (*)(const TopoDS_Face &, const opencascade::handle<Poly_Triangulation> &, Poly_Connect &)) &StdPrs_ToolTriangulatedShape::ComputeNormals, "Computes nodal normals for Poly_Triangulation structure using UV coordinates and surface. Does nothing if triangulation already defines normals.", py::arg("theFace"), py::arg("theTris"), py::arg("thePolyConnect"));
cls_StdPrs_ToolTriangulatedShape.def_static("Normal_", (void (*)(const TopoDS_Face &, Poly_Connect &, TColgp_Array1OfDir &)) &StdPrs_ToolTriangulatedShape::Normal, "Evaluate normals for a triangle of a face.", py::arg("theFace"), py::arg("thePolyConnect"), py::arg("theNormals"));
cls_StdPrs_ToolTriangulatedShape.def_static("IsTessellated_", (Standard_Boolean (*)(const TopoDS_Shape &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_ToolTriangulatedShape::IsTessellated, "Checks whether the shape is properly triangulated for a given display settings.", py::arg("theShape"), py::arg("theDrawer"));
cls_StdPrs_ToolTriangulatedShape.def_static("Tessellate_", (Standard_Boolean (*)(const TopoDS_Shape &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_ToolTriangulatedShape::Tessellate, "Validates triangulation within the shape and performs tessellation if necessary.", py::arg("theShape"), py::arg("theDrawer"));
cls_StdPrs_ToolTriangulatedShape.def_static("ClearOnOwnDeflectionChange_", (void (*)(const TopoDS_Shape &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Boolean)) &StdPrs_ToolTriangulatedShape::ClearOnOwnDeflectionChange, "If presentation has own deviation coefficient and IsAutoTriangulation() is true, function will compare actual coefficients with previous values and will clear triangulation on their change (regardless actual tessellation quality). Function is placed here for compatibility reasons - new code should avoid using IsAutoTriangulation().", py::arg("theShape"), py::arg("theDrawer"), py::arg("theToResetCoeff"));

// CLASS: STDPRS_ISOLINES
py::class_<StdPrs_Isolines, Prs3d_Root> cls_StdPrs_Isolines(mod, "StdPrs_Isolines", "Tool for computing isoline representation for a face or surface. Depending on a flags set to the given Prs3d_Drawer instance, on-surface (is used by default) or on-triangulation isoline builder algorithm will be used. If the given shape is not triangulated, on-surface isoline builder will be applied regardless of Prs3d_Drawer flags.");

// Methods
cls_StdPrs_Isolines.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const TopoDS_Face &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real)) &StdPrs_Isolines::Add, "Computes isolines presentation for a TopoDS face. This method chooses proper version of isoline builder algorithm : on triangulation or surface depending on the flag passed from Prs3d_Drawer attributes. This method is a default way to display isolines for a given TopoDS face.", py::arg("thePresentation"), py::arg("theFace"), py::arg("theDrawer"), py::arg("theDeflection"));
cls_StdPrs_Isolines.def_static("Add_", (void (*)(const TopoDS_Face &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, Prs3d_NListOfSequenceOfPnt &, Prs3d_NListOfSequenceOfPnt &)) &StdPrs_Isolines::Add, "Computes isolines presentation for a TopoDS face. This method chooses proper version of isoline builder algorithm : on triangulation or surface depending on the flag passed from Prs3d_Drawer attributes. This method is a default way to display isolines for a given TopoDS face.", py::arg("theFace"), py::arg("theDrawer"), py::arg("theDeflection"), py::arg("theUPolylines"), py::arg("theVPolylines"));
cls_StdPrs_Isolines.def_static("AddOnTriangulation_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const TopoDS_Face &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_Isolines::AddOnTriangulation, "Computes isolines on triangulation and adds them to a presentation.", py::arg("thePresentation"), py::arg("theFace"), py::arg("theDrawer"));
cls_StdPrs_Isolines.def_static("AddOnTriangulation_", (void (*)(const TopoDS_Face &, const opencascade::handle<Prs3d_Drawer> &, Prs3d_NListOfSequenceOfPnt &, Prs3d_NListOfSequenceOfPnt &)) &StdPrs_Isolines::AddOnTriangulation, "Computes isolines on triangulation.", py::arg("theFace"), py::arg("theDrawer"), py::arg("theUPolylines"), py::arg("theVPolylines"));
cls_StdPrs_Isolines.def_static("AddOnTriangulation_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Poly_Triangulation> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const opencascade::handle<Prs3d_Drawer> &, const TColStd_SequenceOfReal &, const TColStd_SequenceOfReal &)) &StdPrs_Isolines::AddOnTriangulation, "Computes isolines on triangulation and adds them to a presentation.", py::arg("thePresentation"), py::arg("theTriangulation"), py::arg("theSurface"), py::arg("theLocation"), py::arg("theDrawer"), py::arg("theUIsoParams"), py::arg("theVIsoParams"));
cls_StdPrs_Isolines.def_static("AddOnSurface_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const TopoDS_Face &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real)) &StdPrs_Isolines::AddOnSurface, "Computes isolines on surface and adds them to presentation.", py::arg("thePresentation"), py::arg("theFace"), py::arg("theDrawer"), py::arg("theDeflection"));
cls_StdPrs_Isolines.def_static("AddOnSurface_", (void (*)(const TopoDS_Face &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, Prs3d_NListOfSequenceOfPnt &, Prs3d_NListOfSequenceOfPnt &)) &StdPrs_Isolines::AddOnSurface, "Computes isolines on surface and adds them to presentation.", py::arg("theFace"), py::arg("theDrawer"), py::arg("theDeflection"), py::arg("theUPolylines"), py::arg("theVPolylines"));
cls_StdPrs_Isolines.def_static("AddOnSurface_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<BRepAdaptor_HSurface> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const TColStd_SequenceOfReal &, const TColStd_SequenceOfReal &)) &StdPrs_Isolines::AddOnSurface, "Computes isolines on surface and adds them to presentation.", py::arg("thePresentation"), py::arg("theSurface"), py::arg("theDrawer"), py::arg("theDeflection"), py::arg("theUIsoParams"), py::arg("theVIsoParams"));
cls_StdPrs_Isolines.def_static("UVIsoParameters_", (void (*)(const TopoDS_Face &, const Standard_Integer, const Standard_Integer, const Standard_Real, TColStd_SequenceOfReal &, TColStd_SequenceOfReal &)) &StdPrs_Isolines::UVIsoParameters, "Evalute sequence of parameters for drawing uv isolines for a given face.", py::arg("theFace"), py::arg("theNbIsoU"), py::arg("theNbIsoV"), py::arg("theUVLimit"), py::arg("theUIsoParams"), py::arg("theVIsoParams"));

// CLASS: STDPRS_PLANE
py::class_<StdPrs_Plane, Prs3d_Root> cls_StdPrs_Plane(mod, "StdPrs_Plane", "A framework to display infinite planes.");

// Methods
// cls_StdPrs_Plane.def_static("operator new_", (void * (*)(size_t)) &StdPrs_Plane::operator new, "None", py::arg("theSize"));
// cls_StdPrs_Plane.def_static("operator delete_", (void (*)(void *)) &StdPrs_Plane::operator delete, "None", py::arg("theAddress"));
// cls_StdPrs_Plane.def_static("operator new[]_", (void * (*)(size_t)) &StdPrs_Plane::operator new[], "None", py::arg("theSize"));
// cls_StdPrs_Plane.def_static("operator delete[]_", (void (*)(void *)) &StdPrs_Plane::operator delete[], "None", py::arg("theAddress"));
// cls_StdPrs_Plane.def_static("operator new_", (void * (*)(size_t, void *)) &StdPrs_Plane::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdPrs_Plane.def_static("operator delete_", (void (*)(void *, void *)) &StdPrs_Plane::operator delete, "None", py::arg(""), py::arg(""));
cls_StdPrs_Plane.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const Adaptor3d_Surface &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_Plane::Add, "Defines display of infinite planes. The infinite plane aPlane is added to the display aPresentation, and the attributes of the display are defined by the attribute manager aDrawer.", py::arg("aPresentation"), py::arg("aPlane"), py::arg("aDrawer"));
cls_StdPrs_Plane.def_static("Match_", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Adaptor3d_Surface &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_Plane::Match, "returns true if the distance between the point (X,Y,Z) and the plane is less than aDistance.", py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("aDistance"), py::arg("aPlane"), py::arg("aDrawer"));

// CLASS: STDPRS_TOOLPOINT
py::class_<StdPrs_ToolPoint> cls_StdPrs_ToolPoint(mod, "StdPrs_ToolPoint", "None");

// Methods
// cls_StdPrs_ToolPoint.def_static("operator new_", (void * (*)(size_t)) &StdPrs_ToolPoint::operator new, "None", py::arg("theSize"));
// cls_StdPrs_ToolPoint.def_static("operator delete_", (void (*)(void *)) &StdPrs_ToolPoint::operator delete, "None", py::arg("theAddress"));
// cls_StdPrs_ToolPoint.def_static("operator new[]_", (void * (*)(size_t)) &StdPrs_ToolPoint::operator new[], "None", py::arg("theSize"));
// cls_StdPrs_ToolPoint.def_static("operator delete[]_", (void (*)(void *)) &StdPrs_ToolPoint::operator delete[], "None", py::arg("theAddress"));
// cls_StdPrs_ToolPoint.def_static("operator new_", (void * (*)(size_t, void *)) &StdPrs_ToolPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdPrs_ToolPoint.def_static("operator delete_", (void (*)(void *, void *)) &StdPrs_ToolPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_StdPrs_ToolPoint.def_static("Coord_", [](const opencascade::handle<Geom_Point> & aPoint, Standard_Real & X, Standard_Real & Y, Standard_Real & Z){ StdPrs_ToolPoint::Coord(aPoint, X, Y, Z); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(X, Y, Z); }, "None", py::arg("aPoint"), py::arg("X"), py::arg("Y"), py::arg("Z"));

// TYPEDEF: STDPRS_POINT
bind_Prs3d_Point<opencascade::handle<Geom_Point>, StdPrs_ToolPoint>(mod, "StdPrs_Point", py::module_local(false));

// CLASS: STDPRS_POLECURVE
py::class_<StdPrs_PoleCurve, Prs3d_Root> cls_StdPrs_PoleCurve(mod, "StdPrs_PoleCurve", "A framework to provide display of Bezier or BSpline curves (by drawing a broken line linking the poles of the curve).");

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

// CLASS: STDPRS_SHADEDSHAPE
py::class_<StdPrs_ShadedShape, Prs3d_Root> cls_StdPrs_ShadedShape(mod, "StdPrs_ShadedShape", "Auxiliary procedures to prepare Shaded presentation of specified shape.");

// Methods
cls_StdPrs_ShadedShape.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, const TopoDS_Shape & a1, const opencascade::handle<Prs3d_Drawer> & a2) -> void { return StdPrs_ShadedShape::Add(a0, a1, a2); });
cls_StdPrs_ShadedShape.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const TopoDS_Shape &, const opencascade::handle<Prs3d_Drawer> &, const StdPrs_Volume)) &StdPrs_ShadedShape::Add, "Shades <theShape>.", py::arg("thePresentation"), py::arg("theShape"), py::arg("theDrawer"), py::arg("theVolume"));
cls_StdPrs_ShadedShape.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, const TopoDS_Shape & a1, const opencascade::handle<Prs3d_Drawer> & a2, const Standard_Boolean a3, const gp_Pnt2d & a4, const gp_Pnt2d & a5, const gp_Pnt2d & a6) -> void { return StdPrs_ShadedShape::Add(a0, a1, a2, a3, a4, a5, a6); });
cls_StdPrs_ShadedShape.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const TopoDS_Shape &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Boolean, const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &, const StdPrs_Volume)) &StdPrs_ShadedShape::Add, "Shades <theShape> with texture coordinates.", py::arg("thePresentation"), py::arg("theShape"), py::arg("theDrawer"), py::arg("theHasTexels"), py::arg("theUVOrigin"), py::arg("theUVRepeat"), py::arg("theUVScale"), py::arg("theVolume"));
cls_StdPrs_ShadedShape.def_static("ExploreSolids_", (void (*)(const TopoDS_Shape &, const BRep_Builder &, TopoDS_Compound &, TopoDS_Compound &, const Standard_Boolean)) &StdPrs_ShadedShape::ExploreSolids, "Searches closed and unclosed subshapes in shape structure and puts them into two compounds for separate processing of closed and unclosed sub-shapes", py::arg("theShape"), py::arg("theBuilder"), py::arg("theClosed"), py::arg("theOpened"), py::arg("theIgnore1DSubShape"));
cls_StdPrs_ShadedShape.def_static("AddWireframeForFreeElements_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const TopoDS_Shape &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_ShadedShape::AddWireframeForFreeElements, "Computes wireframe presentation for free wires and vertices", py::arg("thePrs"), py::arg("theShape"), py::arg("theDrawer"));
cls_StdPrs_ShadedShape.def_static("AddWireframeForFacesWithoutTriangles_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const TopoDS_Shape &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_ShadedShape::AddWireframeForFacesWithoutTriangles, "Computes special wireframe presentation for faces without triangulation.", py::arg("thePrs"), py::arg("theShape"), py::arg("theDrawer"));
cls_StdPrs_ShadedShape.def_static("FillTriangles_", (opencascade::handle<Graphic3d_ArrayOfTriangles> (*)(const TopoDS_Shape &)) &StdPrs_ShadedShape::FillTriangles, "Create primitive array with triangles for specified shape.", py::arg("theShape"));
cls_StdPrs_ShadedShape.def_static("FillTriangles_", (opencascade::handle<Graphic3d_ArrayOfTriangles> (*)(const TopoDS_Shape &, const Standard_Boolean, const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &)) &StdPrs_ShadedShape::FillTriangles, "Create primitive array of triangles for specified shape.", py::arg("theShape"), py::arg("theHasTexels"), py::arg("theUVOrigin"), py::arg("theUVRepeat"), py::arg("theUVScale"));
cls_StdPrs_ShadedShape.def_static("FillFaceBoundaries_", (opencascade::handle<Graphic3d_ArrayOfSegments> (*)(const TopoDS_Shape &)) &StdPrs_ShadedShape::FillFaceBoundaries, "Define primitive array of boundary segments for specified shape.", py::arg("theShape"));

// CLASS: STDPRS_SHADEDSURFACE
py::class_<StdPrs_ShadedSurface, Prs3d_Root> cls_StdPrs_ShadedSurface(mod, "StdPrs_ShadedSurface", "Computes the shading presentation of surfaces. Draws a surface by drawing the isoparametric curves with respect to a maximal chordial deviation. The number of isoparametric curves to be drawn and their color are controlled by the furnished Drawer.");

// Methods
// cls_StdPrs_ShadedSurface.def_static("operator new_", (void * (*)(size_t)) &StdPrs_ShadedSurface::operator new, "None", py::arg("theSize"));
// cls_StdPrs_ShadedSurface.def_static("operator delete_", (void (*)(void *)) &StdPrs_ShadedSurface::operator delete, "None", py::arg("theAddress"));
// cls_StdPrs_ShadedSurface.def_static("operator new[]_", (void * (*)(size_t)) &StdPrs_ShadedSurface::operator new[], "None", py::arg("theSize"));
// cls_StdPrs_ShadedSurface.def_static("operator delete[]_", (void (*)(void *)) &StdPrs_ShadedSurface::operator delete[], "None", py::arg("theAddress"));
// cls_StdPrs_ShadedSurface.def_static("operator new_", (void * (*)(size_t, void *)) &StdPrs_ShadedSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdPrs_ShadedSurface.def_static("operator delete_", (void (*)(void *, void *)) &StdPrs_ShadedSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_StdPrs_ShadedSurface.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const Adaptor3d_Surface &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_ShadedSurface::Add, "Adds the surface aSurface to the presentation object aPresentation. The surface's display attributes are set in the attribute manager aDrawer. The surface object from Adaptor3d provides data from a Geom surface in order to use the surface in an algorithm.", py::arg("aPresentation"), py::arg("aSurface"), py::arg("aDrawer"));

// CLASS: STDPRS_TOOLRFACE
py::class_<StdPrs_ToolRFace> cls_StdPrs_ToolRFace(mod, "StdPrs_ToolRFace", "None");

// Constructors
cls_StdPrs_ToolRFace.def(py::init<>());
cls_StdPrs_ToolRFace.def(py::init<const opencascade::handle<BRepAdaptor_HSurface> &>(), py::arg("aSurface"));

// Methods
// cls_StdPrs_ToolRFace.def_static("operator new_", (void * (*)(size_t)) &StdPrs_ToolRFace::operator new, "None", py::arg("theSize"));
// cls_StdPrs_ToolRFace.def_static("operator delete_", (void (*)(void *)) &StdPrs_ToolRFace::operator delete, "None", py::arg("theAddress"));
// cls_StdPrs_ToolRFace.def_static("operator new[]_", (void * (*)(size_t)) &StdPrs_ToolRFace::operator new[], "None", py::arg("theSize"));
// cls_StdPrs_ToolRFace.def_static("operator delete[]_", (void (*)(void *)) &StdPrs_ToolRFace::operator delete[], "None", py::arg("theAddress"));
// cls_StdPrs_ToolRFace.def_static("operator new_", (void * (*)(size_t, void *)) &StdPrs_ToolRFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdPrs_ToolRFace.def_static("operator delete_", (void (*)(void *, void *)) &StdPrs_ToolRFace::operator delete, "None", py::arg(""), py::arg(""));
cls_StdPrs_ToolRFace.def("IsOriented", (Standard_Boolean (StdPrs_ToolRFace::*)() const) &StdPrs_ToolRFace::IsOriented, "None");
cls_StdPrs_ToolRFace.def("Init", (void (StdPrs_ToolRFace::*)()) &StdPrs_ToolRFace::Init, "None");
cls_StdPrs_ToolRFace.def("More", (Standard_Boolean (StdPrs_ToolRFace::*)() const) &StdPrs_ToolRFace::More, "None");
cls_StdPrs_ToolRFace.def("Next", (void (StdPrs_ToolRFace::*)()) &StdPrs_ToolRFace::Next, "None");
cls_StdPrs_ToolRFace.def("Value", (Adaptor2d_Curve2dPtr (StdPrs_ToolRFace::*)() const) &StdPrs_ToolRFace::Value, "None");
cls_StdPrs_ToolRFace.def("Orientation", (TopAbs_Orientation (StdPrs_ToolRFace::*)() const) &StdPrs_ToolRFace::Orientation, "None");

// CLASS: STDPRS_TOOLVERTEX
py::class_<StdPrs_ToolVertex> cls_StdPrs_ToolVertex(mod, "StdPrs_ToolVertex", "None");

// Methods
// cls_StdPrs_ToolVertex.def_static("operator new_", (void * (*)(size_t)) &StdPrs_ToolVertex::operator new, "None", py::arg("theSize"));
// cls_StdPrs_ToolVertex.def_static("operator delete_", (void (*)(void *)) &StdPrs_ToolVertex::operator delete, "None", py::arg("theAddress"));
// cls_StdPrs_ToolVertex.def_static("operator new[]_", (void * (*)(size_t)) &StdPrs_ToolVertex::operator new[], "None", py::arg("theSize"));
// cls_StdPrs_ToolVertex.def_static("operator delete[]_", (void (*)(void *)) &StdPrs_ToolVertex::operator delete[], "None", py::arg("theAddress"));
// cls_StdPrs_ToolVertex.def_static("operator new_", (void * (*)(size_t, void *)) &StdPrs_ToolVertex::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdPrs_ToolVertex.def_static("operator delete_", (void (*)(void *, void *)) &StdPrs_ToolVertex::operator delete, "None", py::arg(""), py::arg(""));
cls_StdPrs_ToolVertex.def_static("Coord_", [](const TopoDS_Vertex & aPoint, Standard_Real & X, Standard_Real & Y, Standard_Real & Z){ StdPrs_ToolVertex::Coord(aPoint, X, Y, Z); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(X, Y, Z); }, "None", py::arg("aPoint"), py::arg("X"), py::arg("Y"), py::arg("Z"));

// TYPEDEF: STDPRS_VERTEX
bind_Prs3d_Point<TopoDS_Vertex, StdPrs_ToolVertex>(mod, "StdPrs_Vertex", py::module_local(false));

// CLASS: STDPRS_WFDEFLECTIONRESTRICTEDFACE
py::class_<StdPrs_WFDeflectionRestrictedFace, Prs3d_Root> cls_StdPrs_WFDeflectionRestrictedFace(mod, "StdPrs_WFDeflectionRestrictedFace", "A framework to provide display of U and V isoparameters of faces, while allowing you to impose a deflection on them. Computes the wireframe presentation of faces with restrictions by displaying a given number of U and/or V isoparametric curves. The isoparametric curves are drawn with respect to a maximal chordial deviation. The presentation includes the restriction curves.");

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

// CLASS: STDPRS_WFDEFLECTIONSURFACE
py::class_<StdPrs_WFDeflectionSurface, Prs3d_Root> cls_StdPrs_WFDeflectionSurface(mod, "StdPrs_WFDeflectionSurface", "Draws a surface by drawing the isoparametric curves with respect to a maximal chordial deviation. The number of isoparametric curves to be drawn and their color are controlled by the furnished Drawer.");

// Methods
// cls_StdPrs_WFDeflectionSurface.def_static("operator new_", (void * (*)(size_t)) &StdPrs_WFDeflectionSurface::operator new, "None", py::arg("theSize"));
// cls_StdPrs_WFDeflectionSurface.def_static("operator delete_", (void (*)(void *)) &StdPrs_WFDeflectionSurface::operator delete, "None", py::arg("theAddress"));
// cls_StdPrs_WFDeflectionSurface.def_static("operator new[]_", (void * (*)(size_t)) &StdPrs_WFDeflectionSurface::operator new[], "None", py::arg("theSize"));
// cls_StdPrs_WFDeflectionSurface.def_static("operator delete[]_", (void (*)(void *)) &StdPrs_WFDeflectionSurface::operator delete[], "None", py::arg("theAddress"));
// cls_StdPrs_WFDeflectionSurface.def_static("operator new_", (void * (*)(size_t, void *)) &StdPrs_WFDeflectionSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdPrs_WFDeflectionSurface.def_static("operator delete_", (void (*)(void *, void *)) &StdPrs_WFDeflectionSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_StdPrs_WFDeflectionSurface.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_WFDeflectionSurface::Add, "Adds the surface aSurface to the presentation object aPresentation, and defines its boundaries and isoparameters. The shape's display attributes are set in the attribute manager aDrawer. These include whether deflection is absolute or relative to the size of the shape. The surface aSurface is a surface object from Adaptor, and provides data from a Geom surface. This makes it possible to use the surface in a geometric algorithm. Note that this surface object is manipulated by handles.", py::arg("aPresentation"), py::arg("aSurface"), py::arg("aDrawer"));

// CLASS: STDPRS_WFPOLESURFACE
py::class_<StdPrs_WFPoleSurface, Prs3d_Root> cls_StdPrs_WFPoleSurface(mod, "StdPrs_WFPoleSurface", "Computes the presentation of surfaces by drawing a double network of lines linking the poles of the surface in the two parametric direction. The number of lines to be drawn is controlled by the NetworkNumber of the given Drawer.");

// Methods
// cls_StdPrs_WFPoleSurface.def_static("operator new_", (void * (*)(size_t)) &StdPrs_WFPoleSurface::operator new, "None", py::arg("theSize"));
// cls_StdPrs_WFPoleSurface.def_static("operator delete_", (void (*)(void *)) &StdPrs_WFPoleSurface::operator delete, "None", py::arg("theAddress"));
// cls_StdPrs_WFPoleSurface.def_static("operator new[]_", (void * (*)(size_t)) &StdPrs_WFPoleSurface::operator new[], "None", py::arg("theSize"));
// cls_StdPrs_WFPoleSurface.def_static("operator delete[]_", (void (*)(void *)) &StdPrs_WFPoleSurface::operator delete[], "None", py::arg("theAddress"));
// cls_StdPrs_WFPoleSurface.def_static("operator new_", (void * (*)(size_t, void *)) &StdPrs_WFPoleSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdPrs_WFPoleSurface.def_static("operator delete_", (void (*)(void *, void *)) &StdPrs_WFPoleSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_StdPrs_WFPoleSurface.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const Adaptor3d_Surface &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_WFPoleSurface::Add, "Adds the surface aSurface to the presentation object aPresentation. The shape's display attributes are set in the attribute manager aDrawer. The surface aSurface is a surface object from Adaptor3d, and provides data from a Geom surface. This makes it possible to use the surface in a geometric algorithm.", py::arg("aPresentation"), py::arg("aSurface"), py::arg("aDrawer"));

// CLASS: STDPRS_WFRESTRICTEDFACE
py::class_<StdPrs_WFRestrictedFace, Prs3d_Root> cls_StdPrs_WFRestrictedFace(mod, "StdPrs_WFRestrictedFace", "None");

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

// CLASS: STDPRS_WFSHAPE
py::class_<StdPrs_WFShape, Prs3d_Root> cls_StdPrs_WFShape(mod, "StdPrs_WFShape", "Tool for computing wireframe presentation of a TopoDS_Shape.");

// Methods
cls_StdPrs_WFShape.def_static("Add_", [](const opencascade::handle<Prs3d_Presentation> & a0, const TopoDS_Shape & a1, const opencascade::handle<Prs3d_Drawer> & a2) -> void { return StdPrs_WFShape::Add(a0, a1, a2); });
cls_StdPrs_WFShape.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const TopoDS_Shape &, const opencascade::handle<Prs3d_Drawer> &, Standard_Boolean)) &StdPrs_WFShape::Add, "Computes wireframe presentation of a shape.", py::arg("thePresentation"), py::arg("theShape"), py::arg("theDrawer"), py::arg("theIsParallel"));
cls_StdPrs_WFShape.def_static("AddEdgesOnTriangulation_", [](const TopoDS_Shape & a0) -> opencascade::handle<Graphic3d_ArrayOfPrimitives> { return StdPrs_WFShape::AddEdgesOnTriangulation(a0); });
cls_StdPrs_WFShape.def_static("AddEdgesOnTriangulation_", (opencascade::handle<Graphic3d_ArrayOfPrimitives> (*)(const TopoDS_Shape &, const Standard_Boolean)) &StdPrs_WFShape::AddEdgesOnTriangulation, "Compute free and boundary edges on a triangulation of each face in the given shape.", py::arg("theShape"), py::arg("theToExcludeGeometric"));
cls_StdPrs_WFShape.def_static("AddEdgesOnTriangulation_", [](TColgp_SequenceOfPnt & a0, const TopoDS_Shape & a1) -> void { return StdPrs_WFShape::AddEdgesOnTriangulation(a0, a1); });
cls_StdPrs_WFShape.def_static("AddEdgesOnTriangulation_", (void (*)(TColgp_SequenceOfPnt &, const TopoDS_Shape &, const Standard_Boolean)) &StdPrs_WFShape::AddEdgesOnTriangulation, "Compute free and boundary edges on a triangulation of each face in the given shape.", py::arg("theSegments"), py::arg("theShape"), py::arg("theToExcludeGeometric"));

// CLASS: STDPRS_WFSURFACE
py::class_<StdPrs_WFSurface, Prs3d_Root> cls_StdPrs_WFSurface(mod, "StdPrs_WFSurface", "Computes the wireframe presentation of surfaces by displaying a given number of U and/or V isoparametric curves. The isoparametric curves are drawn with respect to a given number of points.");

// Methods
// cls_StdPrs_WFSurface.def_static("operator new_", (void * (*)(size_t)) &StdPrs_WFSurface::operator new, "None", py::arg("theSize"));
// cls_StdPrs_WFSurface.def_static("operator delete_", (void (*)(void *)) &StdPrs_WFSurface::operator delete, "None", py::arg("theAddress"));
// cls_StdPrs_WFSurface.def_static("operator new[]_", (void * (*)(size_t)) &StdPrs_WFSurface::operator new[], "None", py::arg("theSize"));
// cls_StdPrs_WFSurface.def_static("operator delete[]_", (void (*)(void *)) &StdPrs_WFSurface::operator delete[], "None", py::arg("theAddress"));
// cls_StdPrs_WFSurface.def_static("operator new_", (void * (*)(size_t, void *)) &StdPrs_WFSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StdPrs_WFSurface.def_static("operator delete_", (void (*)(void *, void *)) &StdPrs_WFSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_StdPrs_WFSurface.def_static("Add_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Prs3d_Drawer> &)) &StdPrs_WFSurface::Add, "Draws a surface by drawing the isoparametric curves with respect to a fixed number of points given by the Drawer. The number of isoparametric curves to be drawn and their color are controlled by the furnished Drawer.", py::arg("aPresentation"), py::arg("aSurface"), py::arg("aDrawer"));


}
