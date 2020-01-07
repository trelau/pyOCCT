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
#include <Geom_BSplineCurve.hxx>
#include <Geom_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_BSplineSurface.hxx>
#include <Geom_Surface.hxx>
#include <TopTools_HSequenceOfShape.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <TopAbs_Orientation.hxx>
#include <ShapeConstruct_Curve.hxx>
#include <ShapeConstruct_ProjectCurveOnSurface.hxx>
#include <ShapeConstruct_MakeTriangulation.hxx>
#include <ShapeConstruct.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <BRepBuilderAPI_MakeShape.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TopoDS_Wire.hxx>
#include <Standard_Transient.hxx>
#include <ShapeAnalysis_Surface.hxx>
#include <ShapeExtend_Status.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <TColgp_SequenceOfPnt2d.hxx>
#include <TColgp_HArray1OfPnt2d.hxx>
#include <TColgp_HArray1OfPnt.hxx>

PYBIND11_MODULE(ShapeConstruct, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Geom");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.gp");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.BRepBuilderAPI");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.ShapeAnalysis");
py::module::import("OCCT.ShapeExtend");

// CLASS: SHAPECONSTRUCT
py::class_<ShapeConstruct> cls_ShapeConstruct(mod, "ShapeConstruct", "This package provides new algorithms for constructing new geometrical objects and topological shapes. It complements and extends algorithms available in Open CASCADE topological and geometrical toolkist. The functionality provided by this package are the following: projecting curves on surface, adjusting curve to have given start and end points. P");

// Constructors
cls_ShapeConstruct.def(py::init<>());

// Methods
// cls_ShapeConstruct.def_static("operator new_", (void * (*)(size_t)) &ShapeConstruct::operator new, "None", py::arg("theSize"));
// cls_ShapeConstruct.def_static("operator delete_", (void (*)(void *)) &ShapeConstruct::operator delete, "None", py::arg("theAddress"));
// cls_ShapeConstruct.def_static("operator new[]_", (void * (*)(size_t)) &ShapeConstruct::operator new[], "None", py::arg("theSize"));
// cls_ShapeConstruct.def_static("operator delete[]_", (void (*)(void *)) &ShapeConstruct::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeConstruct.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeConstruct::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeConstruct.def_static("operator delete_", (void (*)(void *, void *)) &ShapeConstruct::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeConstruct.def_static("ConvertCurveToBSpline_", (opencascade::handle<Geom_BSplineCurve> (*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer)) &ShapeConstruct::ConvertCurveToBSpline, "Tool for wire triangulation", py::arg("C3D"), py::arg("First"), py::arg("Last"), py::arg("Tol3d"), py::arg("Continuity"), py::arg("MaxSegments"), py::arg("MaxDegree"));
cls_ShapeConstruct.def_static("ConvertCurveToBSpline_", (opencascade::handle<Geom2d_BSplineCurve> (*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer)) &ShapeConstruct::ConvertCurveToBSpline, "None", py::arg("C2D"), py::arg("First"), py::arg("Last"), py::arg("Tol2d"), py::arg("Continuity"), py::arg("MaxSegments"), py::arg("MaxDegree"));
cls_ShapeConstruct.def_static("ConvertSurfaceToBSpline_", (opencascade::handle<Geom_BSplineSurface> (*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer)) &ShapeConstruct::ConvertSurfaceToBSpline, "None", py::arg("surf"), py::arg("UF"), py::arg("UL"), py::arg("VF"), py::arg("VL"), py::arg("Tol3d"), py::arg("Continuity"), py::arg("MaxSegments"), py::arg("MaxDegree"));
cls_ShapeConstruct.def_static("JoinPCurves_", (Standard_Boolean (*)(const opencascade::handle<TopTools_HSequenceOfShape> &, const TopoDS_Face &, TopoDS_Edge &)) &ShapeConstruct::JoinPCurves, "join pcurves of the <theEdge> on the <theFace> try to use pcurves from originas edges <theEdges> Returns false if cannot join pcurves", py::arg("theEdges"), py::arg("theFace"), py::arg("theEdge"));
cls_ShapeConstruct.def_static("JoinCurves_", [](const opencascade::handle<Geom_Curve> & c3d1, const opencascade::handle<Geom_Curve> & ac3d2, const TopAbs_Orientation Orient1, const TopAbs_Orientation Orient2, Standard_Real & first1, Standard_Real & last1, Standard_Real & first2, Standard_Real & last2, opencascade::handle<Geom_Curve> & c3dOut, Standard_Boolean & isRev1, Standard_Boolean & isRev2){ Standard_Boolean rv = ShapeConstruct::JoinCurves(c3d1, ac3d2, Orient1, Orient2, first1, last1, first2, last2, c3dOut, isRev1, isRev2); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Boolean &, Standard_Boolean &>(rv, first1, last1, first2, last2, isRev1, isRev2); }, "Method for joininig curves 3D. Parameters : c3d1,ac3d2 - initial curves Orient1, Orient2 - initial edges orientations. first1,last1,first2,last2 - parameters for trimming curves (re-calculate with account of orientation edges) c3dOut - result curve isRev1,isRev2 - out parameters indicative on possible errors. Return value : True - if curves were joined successfully, else - False.", py::arg("c3d1"), py::arg("ac3d2"), py::arg("Orient1"), py::arg("Orient2"), py::arg("first1"), py::arg("last1"), py::arg("first2"), py::arg("last2"), py::arg("c3dOut"), py::arg("isRev1"), py::arg("isRev2"));
cls_ShapeConstruct.def_static("JoinCurves_", [](const opencascade::handle<Geom2d_Curve> & c2d1, const opencascade::handle<Geom2d_Curve> & ac2d2, const TopAbs_Orientation Orient1, const TopAbs_Orientation Orient2, Standard_Real & first1, Standard_Real & last1, Standard_Real & first2, Standard_Real & last2, opencascade::handle<Geom2d_Curve> & c2dOut, Standard_Boolean & isRev1, Standard_Boolean & isRev2, const Standard_Boolean isError){ Standard_Boolean rv = ShapeConstruct::JoinCurves(c2d1, ac2d2, Orient1, Orient2, first1, last1, first2, last2, c2dOut, isRev1, isRev2, isError); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Boolean &, Standard_Boolean &>(rv, first1, last1, first2, last2, isRev1, isRev2); }, "Method for joininig curves 3D. Parameters : c3d1,ac3d2 - initial curves Orient1, Orient2 - initial edges orientations. first1,last1,first2,last2 - parameters for trimming curves (re-calculate with account of orientation edges) c3dOut - result curve isRev1,isRev2 - out parameters indicative on possible errors. isError - input parameter indicative possible errors due to that one from edges have one vertex Return value : True - if curves were joined successfully, else - False.", py::arg("c2d1"), py::arg("ac2d2"), py::arg("Orient1"), py::arg("Orient2"), py::arg("first1"), py::arg("last1"), py::arg("first2"), py::arg("last2"), py::arg("c2dOut"), py::arg("isRev1"), py::arg("isRev2"), py::arg("isError"));

// CLASS: SHAPECONSTRUCT_CURVE
py::class_<ShapeConstruct_Curve> cls_ShapeConstruct_Curve(mod, "ShapeConstruct_Curve", "Adjusts curve to have start and end points at the given points (currently works on lines and B-Splines only)");

// Constructors
cls_ShapeConstruct_Curve.def(py::init<>());

// Methods
// cls_ShapeConstruct_Curve.def_static("operator new_", (void * (*)(size_t)) &ShapeConstruct_Curve::operator new, "None", py::arg("theSize"));
// cls_ShapeConstruct_Curve.def_static("operator delete_", (void (*)(void *)) &ShapeConstruct_Curve::operator delete, "None", py::arg("theAddress"));
// cls_ShapeConstruct_Curve.def_static("operator new[]_", (void * (*)(size_t)) &ShapeConstruct_Curve::operator new[], "None", py::arg("theSize"));
// cls_ShapeConstruct_Curve.def_static("operator delete[]_", (void (*)(void *)) &ShapeConstruct_Curve::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeConstruct_Curve.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeConstruct_Curve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeConstruct_Curve.def_static("operator delete_", (void (*)(void *, void *)) &ShapeConstruct_Curve::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeConstruct_Curve.def("AdjustCurve", [](ShapeConstruct_Curve &self, const opencascade::handle<Geom_Curve> & a0, const gp_Pnt & a1, const gp_Pnt & a2) -> Standard_Boolean { return self.AdjustCurve(a0, a1, a2); });
cls_ShapeConstruct_Curve.def("AdjustCurve", [](ShapeConstruct_Curve &self, const opencascade::handle<Geom_Curve> & a0, const gp_Pnt & a1, const gp_Pnt & a2, const Standard_Boolean a3) -> Standard_Boolean { return self.AdjustCurve(a0, a1, a2, a3); });
cls_ShapeConstruct_Curve.def("AdjustCurve", (Standard_Boolean (ShapeConstruct_Curve::*)(const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean, const Standard_Boolean) const) &ShapeConstruct_Curve::AdjustCurve, "Modifies a curve in order to make its bounds confused with given points. Works only on lines and B-Splines, returns True in this case, else returns False. For line considers both bounding points, for B-Splines only specified.", py::arg("C3D"), py::arg("P1"), py::arg("P2"), py::arg("take1"), py::arg("take2"));
cls_ShapeConstruct_Curve.def("AdjustCurveSegment", (Standard_Boolean (ShapeConstruct_Curve::*)(const opencascade::handle<Geom_Curve> &, const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real) const) &ShapeConstruct_Curve::AdjustCurveSegment, "Modifies a curve in order to make its bounds confused with given points. Works only on lines and B-Splines.", py::arg("C3D"), py::arg("P1"), py::arg("P2"), py::arg("U1"), py::arg("U2"));
cls_ShapeConstruct_Curve.def("AdjustCurve2d", [](ShapeConstruct_Curve &self, const opencascade::handle<Geom2d_Curve> & a0, const gp_Pnt2d & a1, const gp_Pnt2d & a2) -> Standard_Boolean { return self.AdjustCurve2d(a0, a1, a2); });
cls_ShapeConstruct_Curve.def("AdjustCurve2d", [](ShapeConstruct_Curve &self, const opencascade::handle<Geom2d_Curve> & a0, const gp_Pnt2d & a1, const gp_Pnt2d & a2, const Standard_Boolean a3) -> Standard_Boolean { return self.AdjustCurve2d(a0, a1, a2, a3); });
cls_ShapeConstruct_Curve.def("AdjustCurve2d", (Standard_Boolean (ShapeConstruct_Curve::*)(const opencascade::handle<Geom2d_Curve> &, const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Boolean, const Standard_Boolean) const) &ShapeConstruct_Curve::AdjustCurve2d, "Modifies a curve in order to make its bounds confused with given points. Works only on lines and B-Splines, returns True in this case, else returns False.", py::arg("C2D"), py::arg("P1"), py::arg("P2"), py::arg("take1"), py::arg("take2"));
cls_ShapeConstruct_Curve.def("ConvertToBSpline", (opencascade::handle<Geom_BSplineCurve> (ShapeConstruct_Curve::*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real) const) &ShapeConstruct_Curve::ConvertToBSpline, "Converts a curve of any type (only part from first to last) to bspline. The method of conversion depends on the type of original curve: BSpline -> C.Segment(first,last) Bezier and Line -> GeomConvert::CurveToBSplineCurve(C).Segment(first,last) Conic and Other -> Approx_Curve3d(C[first,last],prec,C1,9,1000)", py::arg("C"), py::arg("first"), py::arg("last"), py::arg("prec"));
cls_ShapeConstruct_Curve.def("ConvertToBSpline", (opencascade::handle<Geom2d_BSplineCurve> (ShapeConstruct_Curve::*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real) const) &ShapeConstruct_Curve::ConvertToBSpline, "Converts a curve of any type (only part from first to last) to bspline. The method of conversion depends on the type of original curve: BSpline -> C.Segment(first,last) Bezier and Line -> GeomConvert::CurveToBSplineCurve(C).Segment(first,last) Conic and Other -> Approx_Curve2d(C[first,last],prec,C1,9,1000)", py::arg("C"), py::arg("first"), py::arg("last"), py::arg("prec"));
cls_ShapeConstruct_Curve.def_static("FixKnots_", (Standard_Boolean (*)(opencascade::handle<TColStd_HArray1OfReal> &)) &ShapeConstruct_Curve::FixKnots, "None", py::arg("knots"));
cls_ShapeConstruct_Curve.def_static("FixKnots_", (Standard_Boolean (*)(TColStd_Array1OfReal &)) &ShapeConstruct_Curve::FixKnots, "Fix bspline knots to ensure that there is enough gap between neighbouring values Returns True if something fixed (by shifting knot)", py::arg("knots"));

// CLASS: SHAPECONSTRUCT_MAKETRIANGULATION
py::class_<ShapeConstruct_MakeTriangulation, BRepBuilderAPI_MakeShape> cls_ShapeConstruct_MakeTriangulation(mod, "ShapeConstruct_MakeTriangulation", "None");

// Constructors
cls_ShapeConstruct_MakeTriangulation.def(py::init<const TColgp_Array1OfPnt &>(), py::arg("pnts"));
cls_ShapeConstruct_MakeTriangulation.def(py::init<const TColgp_Array1OfPnt &, const Standard_Real>(), py::arg("pnts"), py::arg("prec"));
cls_ShapeConstruct_MakeTriangulation.def(py::init<const TopoDS_Wire &>(), py::arg("wire"));
cls_ShapeConstruct_MakeTriangulation.def(py::init<const TopoDS_Wire &, const Standard_Real>(), py::arg("wire"), py::arg("prec"));

// Methods
// cls_ShapeConstruct_MakeTriangulation.def_static("operator new_", (void * (*)(size_t)) &ShapeConstruct_MakeTriangulation::operator new, "None", py::arg("theSize"));
// cls_ShapeConstruct_MakeTriangulation.def_static("operator delete_", (void (*)(void *)) &ShapeConstruct_MakeTriangulation::operator delete, "None", py::arg("theAddress"));
// cls_ShapeConstruct_MakeTriangulation.def_static("operator new[]_", (void * (*)(size_t)) &ShapeConstruct_MakeTriangulation::operator new[], "None", py::arg("theSize"));
// cls_ShapeConstruct_MakeTriangulation.def_static("operator delete[]_", (void (*)(void *)) &ShapeConstruct_MakeTriangulation::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeConstruct_MakeTriangulation.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeConstruct_MakeTriangulation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeConstruct_MakeTriangulation.def_static("operator delete_", (void (*)(void *, void *)) &ShapeConstruct_MakeTriangulation::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeConstruct_MakeTriangulation.def("Build", (void (ShapeConstruct_MakeTriangulation::*)()) &ShapeConstruct_MakeTriangulation::Build, "None");
cls_ShapeConstruct_MakeTriangulation.def("IsDone", (Standard_Boolean (ShapeConstruct_MakeTriangulation::*)() const) &ShapeConstruct_MakeTriangulation::IsDone, "None");

// CLASS: SHAPECONSTRUCT_PROJECTCURVEONSURFACE
py::class_<ShapeConstruct_ProjectCurveOnSurface, opencascade::handle<ShapeConstruct_ProjectCurveOnSurface>, Standard_Transient> cls_ShapeConstruct_ProjectCurveOnSurface(mod, "ShapeConstruct_ProjectCurveOnSurface", "This tool provides a method for computing pcurve by projecting 3d curve onto a surface. Projection is done by 23 or more points (this number is changed for B-Splines according to the following rule: the total number of the points is not less than number of spans * (degree + 1); it is increased recursively starting with 23 and is added with 22 until the condition is fulfilled). Isoparametric cases (if curve corresponds to U=const or V=const on the surface) are recognized with the given precision.");

// Constructors
cls_ShapeConstruct_ProjectCurveOnSurface.def(py::init<>());

// Methods
cls_ShapeConstruct_ProjectCurveOnSurface.def("Init", (void (ShapeConstruct_ProjectCurveOnSurface::*)(const opencascade::handle<Geom_Surface> &, const Standard_Real)) &ShapeConstruct_ProjectCurveOnSurface::Init, "Initializes the object with all necessary parameters, i.e. surface and precision", py::arg("surf"), py::arg("preci"));
cls_ShapeConstruct_ProjectCurveOnSurface.def("Init", (void (ShapeConstruct_ProjectCurveOnSurface::*)(const opencascade::handle<ShapeAnalysis_Surface> &, const Standard_Real)) &ShapeConstruct_ProjectCurveOnSurface::Init, "Initializes the object with all necessary parameters, i.e. surface and precision", py::arg("surf"), py::arg("preci"));
cls_ShapeConstruct_ProjectCurveOnSurface.def("SetSurface", (void (ShapeConstruct_ProjectCurveOnSurface::*)(const opencascade::handle<Geom_Surface> &)) &ShapeConstruct_ProjectCurveOnSurface::SetSurface, "Loads a surface (in the form of Geom_Surface) to project on", py::arg("surf"));
cls_ShapeConstruct_ProjectCurveOnSurface.def("SetSurface", (void (ShapeConstruct_ProjectCurveOnSurface::*)(const opencascade::handle<ShapeAnalysis_Surface> &)) &ShapeConstruct_ProjectCurveOnSurface::SetSurface, "Loads a surface (in the form of ShapeAnalysis_Surface) to project on", py::arg("surf"));
cls_ShapeConstruct_ProjectCurveOnSurface.def("SetPrecision", (void (ShapeConstruct_ProjectCurveOnSurface::*)(const Standard_Real)) &ShapeConstruct_ProjectCurveOnSurface::SetPrecision, "Sets value for current precision", py::arg("preci"));
cls_ShapeConstruct_ProjectCurveOnSurface.def("BuildCurveMode", (Standard_Boolean & (ShapeConstruct_ProjectCurveOnSurface::*)()) &ShapeConstruct_ProjectCurveOnSurface::BuildCurveMode, "Returns (modifiable) the build-curve-3d mode, by default False If True, if the projected curve has been recomputed by interpolation, the 3d curve is also rebuild by interpolation");
cls_ShapeConstruct_ProjectCurveOnSurface.def("AdjustOverDegenMode", (Standard_Integer & (ShapeConstruct_ProjectCurveOnSurface::*)()) &ShapeConstruct_ProjectCurveOnSurface::AdjustOverDegenMode, "Returns (modifiable) the flag specifying to which side of parametrical space adjust part of pcurve which lies on seam. This is required in very rare case when 3d curve which is to be projected goes partly along the seam on the closed surface with singularity (e.g. sphere), goes through the degenerated point and paerly lies on internal area of surface.");
cls_ShapeConstruct_ProjectCurveOnSurface.def("Status", (Standard_Boolean (ShapeConstruct_ProjectCurveOnSurface::*)(const ShapeExtend_Status) const) &ShapeConstruct_ProjectCurveOnSurface::Status, "Returns the status of last Peform", py::arg("theStatus"));
cls_ShapeConstruct_ProjectCurveOnSurface.def("Perform", [](ShapeConstruct_ProjectCurveOnSurface &self, opencascade::handle<Geom_Curve> & a0, const Standard_Real a1, const Standard_Real a2, opencascade::handle<Geom2d_Curve> & a3) -> Standard_Boolean { return self.Perform(a0, a1, a2, a3); });
cls_ShapeConstruct_ProjectCurveOnSurface.def("Perform", [](ShapeConstruct_ProjectCurveOnSurface &self, opencascade::handle<Geom_Curve> & a0, const Standard_Real a1, const Standard_Real a2, opencascade::handle<Geom2d_Curve> & a3, const Standard_Real a4) -> Standard_Boolean { return self.Perform(a0, a1, a2, a3, a4); });
cls_ShapeConstruct_ProjectCurveOnSurface.def("Perform", (Standard_Boolean (ShapeConstruct_ProjectCurveOnSurface::*)(opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real)) &ShapeConstruct_ProjectCurveOnSurface::Perform, "Computes the projection of 3d curve onto a surface using the specialized algorithm. Returns False if projector fails, otherwise, if pcurve computed successfully, returns True. The output curve 2D is guaranteed to be same-parameter with input curve 3D on the interval [First, Last]. If the output curve lies on a direct line the infinite line is returned, in the case same-parameter condition is satisfied. TolFirst and TolLast are the tolerances at the ends of input curve 3D.", py::arg("c3d"), py::arg("First"), py::arg("Last"), py::arg("c2d"), py::arg("TolFirst"), py::arg("TolLast"));
cls_ShapeConstruct_ProjectCurveOnSurface.def("PerformByProjLib", [](ShapeConstruct_ProjectCurveOnSurface &self, opencascade::handle<Geom_Curve> & a0, const Standard_Real a1, const Standard_Real a2, opencascade::handle<Geom2d_Curve> & a3) -> Standard_Boolean { return self.PerformByProjLib(a0, a1, a2, a3); });
cls_ShapeConstruct_ProjectCurveOnSurface.def("PerformByProjLib", [](ShapeConstruct_ProjectCurveOnSurface &self, opencascade::handle<Geom_Curve> & a0, const Standard_Real a1, const Standard_Real a2, opencascade::handle<Geom2d_Curve> & a3, const GeomAbs_Shape a4) -> Standard_Boolean { return self.PerformByProjLib(a0, a1, a2, a3, a4); });
cls_ShapeConstruct_ProjectCurveOnSurface.def("PerformByProjLib", [](ShapeConstruct_ProjectCurveOnSurface &self, opencascade::handle<Geom_Curve> & a0, const Standard_Real a1, const Standard_Real a2, opencascade::handle<Geom2d_Curve> & a3, const GeomAbs_Shape a4, const Standard_Integer a5) -> Standard_Boolean { return self.PerformByProjLib(a0, a1, a2, a3, a4, a5); });
cls_ShapeConstruct_ProjectCurveOnSurface.def("PerformByProjLib", (Standard_Boolean (ShapeConstruct_ProjectCurveOnSurface::*)(opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, opencascade::handle<Geom2d_Curve> &, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer)) &ShapeConstruct_ProjectCurveOnSurface::PerformByProjLib, "Computes the projection of 3d curve onto a surface using the standard algorithm from ProjLib. Returns False if standard projector fails or raises an exception or cuts the curve by parametrical bounds of the surface. Else, if pcurve computed successfully, returns True. The continuity, maxdeg and nbinterval are parameters of call to Approx_CurveOnSurface. If nbinterval is equal to -1 (default), this value is computed depending on source 3d curve and surface.", py::arg("c3d"), py::arg("First"), py::arg("Last"), py::arg("c2d"), py::arg("continuity"), py::arg("maxdeg"), py::arg("nbinterval"));
cls_ShapeConstruct_ProjectCurveOnSurface.def_static("get_type_name_", (const char * (*)()) &ShapeConstruct_ProjectCurveOnSurface::get_type_name, "None");
cls_ShapeConstruct_ProjectCurveOnSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeConstruct_ProjectCurveOnSurface::get_type_descriptor, "None");
cls_ShapeConstruct_ProjectCurveOnSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeConstruct_ProjectCurveOnSurface::*)() const) &ShapeConstruct_ProjectCurveOnSurface::DynamicType, "None");


}
