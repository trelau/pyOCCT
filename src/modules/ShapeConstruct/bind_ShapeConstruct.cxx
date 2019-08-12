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

void bind_ShapeConstruct(py::module &mod){

py::class_<ShapeConstruct, std::unique_ptr<ShapeConstruct, Deleter<ShapeConstruct>>> cls_ShapeConstruct(mod, "ShapeConstruct", "This package provides new algorithms for constructing new geometrical objects and topological shapes. It complements and extends algorithms available in Open CASCADE topological and geometrical toolkist. The functionality provided by this package are the following: projecting curves on surface, adjusting curve to have given start and end points. P");

// Constructors

// Fields

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

// Enums

}