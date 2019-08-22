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
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <BRepTools_Modification.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <BRepTools_Modifier.hxx>
#include <Message_ProgressIndicator.hxx>
#include <ShapeBuild_ReShape.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <ShapeCustom_RestrictionParameters.hxx>
#include <ShapeCustom_Surface.hxx>
#include <ShapeCustom_Curve.hxx>
#include <ShapeCustom_Curve2d.hxx>
#include <ShapeCustom_Modification.hxx>
#include <ShapeCustom_DirectModification.hxx>
#include <ShapeCustom_TrsfModification.hxx>
#include <ShapeCustom_BSplineRestriction.hxx>
#include <ShapeCustom_ConvertToRevolution.hxx>
#include <ShapeCustom_SweptToElementary.hxx>
#include <ShapeCustom_ConvertToBSpline.hxx>
#include <ShapeCustom.hxx>

void bind_ShapeCustom(py::module &mod){

py::class_<ShapeCustom> cls_ShapeCustom(mod, "ShapeCustom", "This package is intended to convert geometrical objects and topological. The modifications of one geometrical object to another (one) geometrical object are provided. The supported modifications are the following: conversion of BSpline and Bezier surfaces to analytical form, conversion of indirect elementary surfaces (with left-handed coordinate systems) into direct ones, conversion of elementary surfaces to surfaces of revolution, conversion of surface of linear extrusion, revolution, offset surface to bspline, modification of parameterization, degree, number of segments of bspline surfaces, scale the shape.");

// Constructors

// Fields

// Methods
// cls_ShapeCustom.def_static("operator new_", (void * (*)(size_t)) &ShapeCustom::operator new, "None", py::arg("theSize"));
// cls_ShapeCustom.def_static("operator delete_", (void (*)(void *)) &ShapeCustom::operator delete, "None", py::arg("theAddress"));
// cls_ShapeCustom.def_static("operator new[]_", (void * (*)(size_t)) &ShapeCustom::operator new[], "None", py::arg("theSize"));
// cls_ShapeCustom.def_static("operator delete[]_", (void (*)(void *)) &ShapeCustom::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeCustom.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeCustom::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeCustom.def_static("operator delete_", (void (*)(void *, void *)) &ShapeCustom::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeCustom.def_static("ApplyModifier_", [](const TopoDS_Shape & a0, const opencascade::handle<BRepTools_Modification> & a1, TopTools_DataMapOfShapeShape & a2, BRepTools_Modifier & a3) -> TopoDS_Shape { return ShapeCustom::ApplyModifier(a0, a1, a2, a3); });
cls_ShapeCustom.def_static("ApplyModifier_", [](const TopoDS_Shape & a0, const opencascade::handle<BRepTools_Modification> & a1, TopTools_DataMapOfShapeShape & a2, BRepTools_Modifier & a3, const opencascade::handle<Message_ProgressIndicator> & a4) -> TopoDS_Shape { return ShapeCustom::ApplyModifier(a0, a1, a2, a3, a4); });
cls_ShapeCustom.def_static("ApplyModifier_", (TopoDS_Shape (*)(const TopoDS_Shape &, const opencascade::handle<BRepTools_Modification> &, TopTools_DataMapOfShapeShape &, BRepTools_Modifier &, const opencascade::handle<Message_ProgressIndicator> &, const opencascade::handle<ShapeBuild_ReShape> &)) &ShapeCustom::ApplyModifier, "Applies modifier to shape and checks sharing in the case assemblies.", py::arg("S"), py::arg("M"), py::arg("context"), py::arg("MD"), py::arg("aProgress"), py::arg("aReShape"));
cls_ShapeCustom.def_static("DirectFaces_", (TopoDS_Shape (*)(const TopoDS_Shape &)) &ShapeCustom::DirectFaces, "Returns a new shape without indirect surfaces.", py::arg("S"));
cls_ShapeCustom.def_static("ScaleShape_", (TopoDS_Shape (*)(const TopoDS_Shape &, const Standard_Real)) &ShapeCustom::ScaleShape, "Returns a new shape which is scaled original", py::arg("S"), py::arg("scale"));
cls_ShapeCustom.def_static("BSplineRestriction_", (TopoDS_Shape (*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, const GeomAbs_Shape, const GeomAbs_Shape, const Standard_Boolean, const Standard_Boolean, const opencascade::handle<ShapeCustom_RestrictionParameters> &)) &ShapeCustom::BSplineRestriction, "Returns a new shape with all surfaces, curves and pcurves which type is BSpline/Bezier or based on them converted having Degree less than <MaxDegree> or number of spans less than <NbMaxSegment> in dependence on parameter priority <Degree>. <GmaxDegree> and <GMaxSegments> are maximum possible degree and number of spans correspondingly. These values will be used in those cases when approximation with specified parameters is impossible and one of GmaxDegree or GMaxSegments is selected in dependence on priority. Note that even if approximation is impossible with <GMaxDegree> then number of spans can exceed specified <GMaxSegment> <Rational> specifies if to convert Rational BSpline/Bezier into polynomial B-Spline. If flags ConvOffSurf,ConvOffCurve3d,ConvOffCurve2d are Standard_True there are means that Offset surfaces , Offset curves 3d and Offset curves 2d are converted to BSPline correspondingly.", py::arg("S"), py::arg("Tol3d"), py::arg("Tol2d"), py::arg("MaxDegree"), py::arg("MaxNbSegment"), py::arg("Continuity3d"), py::arg("Continuity2d"), py::arg("Degree"), py::arg("Rational"), py::arg("aParameters"));
cls_ShapeCustom.def_static("ConvertToRevolution_", (TopoDS_Shape (*)(const TopoDS_Shape &)) &ShapeCustom::ConvertToRevolution, "Returns a new shape with all elementary periodic surfaces converted to Geom_SurfaceOfRevolution", py::arg("S"));
cls_ShapeCustom.def_static("SweptToElementary_", (TopoDS_Shape (*)(const TopoDS_Shape &)) &ShapeCustom::SweptToElementary, "Returns a new shape with all surfaces of revolution and linear extrusion convert to elementary periodic surfaces", py::arg("S"));
cls_ShapeCustom.def_static("ConvertToBSpline_", [](const TopoDS_Shape & a0, const Standard_Boolean a1, const Standard_Boolean a2, const Standard_Boolean a3) -> TopoDS_Shape { return ShapeCustom::ConvertToBSpline(a0, a1, a2, a3); });
cls_ShapeCustom.def_static("ConvertToBSpline_", (TopoDS_Shape (*)(const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &ShapeCustom::ConvertToBSpline, "Returns a new shape with all surfaces of linear extrusion, revolution, offset, and planar surfaces converted according to flags to Geom_BSplineSurface (with same parameterisation).", py::arg("S"), py::arg("extrMode"), py::arg("revolMode"), py::arg("offsetMode"), py::arg("planeMode"));

// Enums

}