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
#include <ShapePersistent_TriangleMode.hxx>
#include <StdObjMgt_MapOfInstantiators.hxx>
#include <ShapePersistent.hxx>
#include <StdPersistent_TopoDS.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <StdObject_Shape.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <StdObjMgt_WriteData.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TopoDS_TShape.hxx>
#include <TopoDS_Shape.hxx>
#include <ShapePersistent_TopoDS.hxx>
#include <StdObjMgt_SharedObject.hxx>
#include <StdLPersistent_HArray1.hxx>
#include <StdPersistent_HArray1.hxx>
#include <TopoDS_TWire.hxx>
#include <TopoDS_TShell.hxx>
#include <TopoDS_TSolid.hxx>
#include <TopoDS_TCompSolid.hxx>
#include <TopoDS_TCompound.hxx>
#include <StdObjMgt_TransientPersistentMap.hxx>
#include <ShapePersistent_Geom.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_CartesianPoint.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <Geom_Direction.hxx>
#include <gp_Dir.hxx>
#include <Geom_VectorWithMagnitude.hxx>
#include <gp_Ax1.hxx>
#include <Geom_Axis1Placement.hxx>
#include <Geom_Axis2Placement.hxx>
#include <Geom_Transformation.hxx>
#include <gp_Trsf.hxx>
#include <Geom_Curve.hxx>
#include <Geom_Surface.hxx>
#include <Geom2d_Geometry.hxx>
#include <ShapePersistent_Geom2d.hxx>
#include <Geom2d_CartesianPoint.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <Geom2d_Direction.hxx>
#include <gp_Dir2d.hxx>
#include <Geom2d_VectorWithMagnitude.hxx>
#include <Geom2d_AxisPlacement.hxx>
#include <gp_Ax2d.hxx>
#include <Geom2d_Transformation.hxx>
#include <gp_Trsf2d.hxx>
#include <Geom2d_Curve.hxx>
#include <TColgp_HArray1OfXYZ.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <TColgp_HArray1OfDir.hxx>
#include <TColgp_HArray1OfVec.hxx>
#include <TColgp_HArray1OfXY.hxx>
#include <TColgp_HArray1OfPnt2d.hxx>
#include <TColgp_HArray1OfDir2d.hxx>
#include <TColgp_HArray1OfVec2d.hxx>
#include <TColgp_HArray1OfLin2d.hxx>
#include <TColgp_HArray1OfCirc2d.hxx>
#include <Poly_HArray1OfTriangle.hxx>
#include <ShapePersistent_HArray1.hxx>
#include <Standard_Transient.hxx>
#include <ShapePersistent_Poly.hxx>
#include <Poly_Polygon2D.hxx>
#include <Poly_Polygon3D.hxx>
#include <Poly_PolygonOnTriangulation.hxx>
#include <Poly_Triangulation.hxx>
#include <ShapePersistent_BRep.hxx>
#include <BRep_ListOfPointRepresentation.hxx>
#include <BRep_PointRepresentation.hxx>
#include <StdObject_Location.hxx>
#include <BRep_ListOfCurveRepresentation.hxx>
#include <BRep_CurveRepresentation.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <TopLoc_Location.hxx>
#include <GeomAbs_Shape.hxx>
#include <ShapePersistent_Geom2d_Curve.hxx>
#include <Geom2d_Line.hxx>
#include <gp_Ax22d.hxx>
#include <Geom2d_Circle.hxx>
#include <gp_Circ2d.hxx>
#include <Geom2d_Ellipse.hxx>
#include <gp_Elips2d.hxx>
#include <Geom2d_Hyperbola.hxx>
#include <gp_Hypr2d.hxx>
#include <Geom2d_Parabola.hxx>
#include <gp_Parab2d.hxx>
#include <Geom2d_BezierCurve.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Geom2d_TrimmedCurve.hxx>
#include <Geom2d_OffsetCurve.hxx>
#include <ShapePersistent_Geom_Curve.hxx>
#include <Geom_Line.hxx>
#include <gp_Ax2.hxx>
#include <Geom_Circle.hxx>
#include <gp_Circ.hxx>
#include <Geom_Ellipse.hxx>
#include <gp_Elips.hxx>
#include <Geom_Hyperbola.hxx>
#include <gp_Hypr.hxx>
#include <Geom_Parabola.hxx>
#include <gp_Parab.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <Geom_OffsetCurve.hxx>
#include <StdLPersistent_HArray2.hxx>
#include <TColgp_HArray2OfXYZ.hxx>
#include <TColgp_HArray2OfPnt.hxx>
#include <TColgp_HArray2OfDir.hxx>
#include <TColgp_HArray2OfVec.hxx>
#include <TColgp_HArray2OfXY.hxx>
#include <TColgp_HArray2OfPnt2d.hxx>
#include <TColgp_HArray2OfDir2d.hxx>
#include <TColgp_HArray2OfVec2d.hxx>
#include <TColgp_HArray2OfLin2d.hxx>
#include <TColgp_HArray2OfCirc2d.hxx>
#include <ShapePersistent_HArray2.hxx>
#include <ShapePersistent_Geom_Surface.hxx>
#include <gp_Ax3.hxx>
#include <Geom_Plane.hxx>
#include <Geom_ConicalSurface.hxx>
#include <gp_Cone.hxx>
#include <Geom_CylindricalSurface.hxx>
#include <gp_Cylinder.hxx>
#include <Geom_SphericalSurface.hxx>
#include <gp_Sphere.hxx>
#include <Geom_ToroidalSurface.hxx>
#include <gp_Torus.hxx>
#include <Geom_SurfaceOfLinearExtrusion.hxx>
#include <Geom_SurfaceOfRevolution.hxx>
#include <Geom_BezierSurface.hxx>
#include <Geom_BSplineSurface.hxx>
#include <Geom_RectangularTrimmedSurface.hxx>
#include <Geom_OffsetSurface.hxx>
#include <ShapePersistent_HSequence.hxx>
#include <TColgp_HSequenceOfXYZ.hxx>
#include <TColgp_HSequenceOfPnt.hxx>
#include <TColgp_HSequenceOfDir.hxx>
#include <TColgp_HSequenceOfVec.hxx>

PYBIND11_MODULE(ShapePersistent, mod) {

py::module::import("OCCT.StdObjMgt");
py::module::import("OCCT.StdPersistent");
py::module::import("OCCT.StdObject");
py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.StdLPersistent");
py::module::import("OCCT.Geom");
py::module::import("OCCT.gp");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.Poly");
py::module::import("OCCT.BRep");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.GeomAbs");

// ENUM: SHAPEPERSISTENT_TRIANGLEMODE
py::enum_<ShapePersistent_TriangleMode>(mod, "ShapePersistent_TriangleMode", "None")
	.value("ShapePersistent_WithTriangle", ShapePersistent_TriangleMode::ShapePersistent_WithTriangle)
	.value("ShapePersistent_WithoutTriangle", ShapePersistent_TriangleMode::ShapePersistent_WithoutTriangle)
	.export_values();


// CLASS: SHAPEPERSISTENT
py::class_<ShapePersistent> cls_ShapePersistent(mod, "ShapePersistent", "None");

// Constructors
cls_ShapePersistent.def(py::init<>());

// Methods
cls_ShapePersistent.def_static("BindTypes_", (void (*)(StdObjMgt_MapOfInstantiators &)) &ShapePersistent::BindTypes, "Register types.", py::arg("theMap"));

// CLASS: SHAPEPERSISTENT_TOPODS
/*
py::class_<ShapePersistent_TopoDS, StdPersistent_TopoDS> cls_ShapePersistent_TopoDS(mod, "ShapePersistent_TopoDS", "None");

// Constructors
cls_ShapePersistent_TopoDS.def(py::init<>());

// Methods
cls_ShapePersistent_TopoDS.def_static("Translate_", (opencascade::handle<HShape> (*)(const TopoDS_Shape &, StdObjMgt_TransientPersistentMap &, ShapePersistent_TriangleMode)) &ShapePersistent_TopoDS::Translate, "Create a persistent object for a shape", py::arg("theShape"), py::arg("theMap"), py::arg("theTriangleMode"));
*/

// CLASS: SHAPEPERSISTENT_GEOM
/*
py::class_<ShapePersistent_Geom, StdObjMgt_SharedObject> cls_ShapePersistent_Geom(mod, "ShapePersistent_Geom", "None");

// Constructors
cls_ShapePersistent_Geom.def(py::init<>());

// Methods
cls_ShapePersistent_Geom.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom_Curve> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom::Translate, "Create a persistent object for a curve", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom.def_static("Translate_", (opencascade::handle<Surface> (*)(const opencascade::handle<Geom_Surface> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom::Translate, "Create a persistent object for a curve", py::arg("theSurf"), py::arg("theMap"));
*/

// CLASS: SHAPEPERSISTENT_GEOM2D
/*
py::class_<ShapePersistent_Geom2d> cls_ShapePersistent_Geom2d(mod, "ShapePersistent_Geom2d", "None");

// Constructors
cls_ShapePersistent_Geom2d.def(py::init<>());

// Methods
cls_ShapePersistent_Geom2d.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom2d_Curve> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom2d::Translate, "Create a persistent object for a curve", py::arg("theCurve"), py::arg("theMap"));
*/

// CLASS: SHAPEPERSISTENT_HARRAY1
py::class_<ShapePersistent_HArray1> cls_ShapePersistent_HArray1(mod, "ShapePersistent_HArray1", "None");

// Constructors
cls_ShapePersistent_HArray1.def(py::init<>());

// CLASS: SHAPEPERSISTENT_POLY
/*
py::class_<ShapePersistent_Poly> cls_ShapePersistent_Poly(mod, "ShapePersistent_Poly", "None");

// Constructors
cls_ShapePersistent_Poly.def(py::init<>());

// Methods
cls_ShapePersistent_Poly.def_static("Translate_", (opencascade::handle<Polygon2D> (*)(const opencascade::handle<Poly_Polygon2D> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Poly::Translate, "Create a persistent object for a 2D polygon", py::arg("thePoly"), py::arg("theMap"));
cls_ShapePersistent_Poly.def_static("Translate_", (opencascade::handle<Polygon3D> (*)(const opencascade::handle<Poly_Polygon3D> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Poly::Translate, "Create a persistent object for a 3D polygon", py::arg("thePoly"), py::arg("theMap"));
cls_ShapePersistent_Poly.def_static("Translate_", (opencascade::handle<PolygonOnTriangulation> (*)(const opencascade::handle<Poly_PolygonOnTriangulation> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Poly::Translate, "Create a persistent object for a triangulation", py::arg("thePolyOnTriang"), py::arg("theMap"));
cls_ShapePersistent_Poly.def_static("Translate_", (opencascade::handle<Triangulation> (*)(const opencascade::handle<Poly_Triangulation> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Poly::Translate, "Create a persistent object for a polygon on triangulation", py::arg("thePolyTriang"), py::arg("theMap"));
*/

// CLASS: SHAPEPERSISTENT_BREP
/*
py::class_<ShapePersistent_BRep> cls_ShapePersistent_BRep(mod, "ShapePersistent_BRep", "None");

// Constructors
cls_ShapePersistent_BRep.def(py::init<>());

// Methods
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<TVertex::pTObjectT> (*)(const TopoDS_Vertex &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_BRep::Translate, "Create a persistent object for a vertex", py::arg("theVertex"), py::arg("theMap"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<TEdge::pTObjectT> (*)(const TopoDS_Edge &, StdObjMgt_TransientPersistentMap &, ShapePersistent_TriangleMode)) &ShapePersistent_BRep::Translate, "Create a persistent object for an edge", py::arg("theEdge"), py::arg("theMap"), py::arg("theTriangleMode"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<TFace::pTObjectT> (*)(const TopoDS_Face &, StdObjMgt_TransientPersistentMap &, ShapePersistent_TriangleMode)) &ShapePersistent_BRep::Translate, "Create a persistent object for a face", py::arg("theFace"), py::arg("theMap"), py::arg("theTriangleMode"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<PointOnCurve> (*)(Standard_Real, const opencascade::handle<Geom_Curve> &, const TopLoc_Location &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_BRep::Translate, "Create a persistent object for a point on a 3D curve", py::arg("theParam"), py::arg("theCurve"), py::arg("theLoc"), py::arg("theMap"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<PointOnCurveOnSurface> (*)(Standard_Real, const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_BRep::Translate, "Create a persistent object for a point on a 3D curve on a surface", py::arg("theParam"), py::arg("theCurve"), py::arg("theSurf"), py::arg("theLoc"), py::arg("theMap"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<PointOnSurface> (*)(Standard_Real, Standard_Real, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_BRep::Translate, "Create a persistent object for a point on a surface", py::arg("theParam"), py::arg("theParam2"), py::arg("theSurf"), py::arg("theLoc"), py::arg("theMap"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<CurveOnSurface> (*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_BRep::Translate, "Create a persistent object for a curve on a surface", py::arg("theCurve"), py::arg("theFirstParam"), py::arg("theLastParam"), py::arg("theSurf"), py::arg("theLoc"), py::arg("theMap"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<CurveOnClosedSurface> (*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const GeomAbs_Shape, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_BRep::Translate, "Create a persistent object for a curve on a closed surface", py::arg("theCurve"), py::arg("theCurve2"), py::arg("theFirstParam"), py::arg("theLastParam"), py::arg("theSurf"), py::arg("theLoc"), py::arg("theContinuity"), py::arg("theMap"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<CurveOn2Surfaces> (*)(const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const TopLoc_Location &, const GeomAbs_Shape, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_BRep::Translate, "Create a persistent object for a curve on two surfaces", py::arg("theSurf"), py::arg("theSurf2"), py::arg("theLoc"), py::arg("theLoc2"), py::arg("theContinuity"), py::arg("theMap"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<Curve3D> (*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, const TopLoc_Location &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_BRep::Translate, "Create a persistent object for a 3D curve", py::arg("theCurve"), py::arg("theFirstParam"), py::arg("theLastParam"), py::arg("theLoc"), py::arg("theMap"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<Polygon3D> (*)(const opencascade::handle<Poly_Polygon3D> &, const TopLoc_Location &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_BRep::Translate, "Create a persistent object for a 3D polygon", py::arg("thePoly"), py::arg("theLoc"), py::arg("theMap"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<PolygonOnClosedSurface> (*)(const opencascade::handle<Poly_Polygon2D> &, const opencascade::handle<Poly_Polygon2D> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_BRep::Translate, "Create a persistent object for a polygon on a closed surface", py::arg("thePoly"), py::arg("thePoly2"), py::arg("theSurf"), py::arg("theLoc"), py::arg("theMap"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<PolygonOnSurface> (*)(const opencascade::handle<Poly_Polygon2D> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_BRep::Translate, "Create a persistent object for a polygon on a surface", py::arg("thePoly"), py::arg("theSurf"), py::arg("theLoc"), py::arg("theMap"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<PolygonOnClosedTriangulation> (*)(const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_BRep::Translate, "Create a persistent object for a polygon on a surface", py::arg("thePolyOnTriang"), py::arg("thePolyOnTriang2"), py::arg("thePolyTriang"), py::arg("theLoc"), py::arg("theMap"));
cls_ShapePersistent_BRep.def_static("Translate_", (opencascade::handle<PolygonOnTriangulation> (*)(const opencascade::handle<Poly_PolygonOnTriangulation> &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_BRep::Translate, "Create a persistent object for a polygon on a surface", py::arg("thePolyOnTriang"), py::arg("thePolyTriang"), py::arg("theLoc"), py::arg("theMap"));
*/

// CLASS: SHAPEPERSISTENT_GEOM2D_CURVE
/*
py::class_<ShapePersistent_Geom2d_Curve> cls_ShapePersistent_Geom2d_Curve(mod, "ShapePersistent_Geom2d_Curve", "None");

// Constructors
cls_ShapePersistent_Geom2d_Curve.def(py::init<>());

// Methods
cls_ShapePersistent_Geom2d_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom2d_Line> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom2d_Curve::Translate, "Create a persistent object for a line", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom2d_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom2d_Circle> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom2d_Curve::Translate, "Create a persistent object for a circle", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom2d_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom2d_Ellipse> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom2d_Curve::Translate, "Create a persistent object for a ellipse", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom2d_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom2d_Hyperbola> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom2d_Curve::Translate, "Create a persistent object for a hyperbola", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom2d_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom2d_Parabola> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom2d_Curve::Translate, "Create a persistent object for a parabola", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom2d_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom2d_BezierCurve> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom2d_Curve::Translate, "Create a persistent object for a Bezier curve", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom2d_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom2d_BSplineCurve> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom2d_Curve::Translate, "Create a persistent object for a BSpline curve", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom2d_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom2d_TrimmedCurve> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom2d_Curve::Translate, "Create a persistent object for a trimmed curve", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom2d_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom2d_OffsetCurve> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom2d_Curve::Translate, "Create a persistent object for an offset curve", py::arg("theCurve"), py::arg("theMap"));
*/

// CLASS: SHAPEPERSISTENT_GEOM_CURVE
/*
py::class_<ShapePersistent_Geom_Curve> cls_ShapePersistent_Geom_Curve(mod, "ShapePersistent_Geom_Curve", "None");

// Constructors
cls_ShapePersistent_Geom_Curve.def(py::init<>());

// Methods
cls_ShapePersistent_Geom_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom_Line> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Curve::Translate, "Create a persistent object for a line", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom_Circle> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Curve::Translate, "Create a persistent object for a circle", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom_Ellipse> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Curve::Translate, "Create a persistent object for a ellipse", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom_Hyperbola> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Curve::Translate, "Create a persistent object for a hyperbola", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom_Parabola> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Curve::Translate, "Create a persistent object for a parabola", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom_BezierCurve> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Curve::Translate, "Create a persistent object for a Bezier curve", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom_BSplineCurve> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Curve::Translate, "Create a persistent object for a BSpline curve", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom_TrimmedCurve> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Curve::Translate, "Create a persistent object for a trimmed curve", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom_Curve.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom_OffsetCurve> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Curve::Translate, "Create a persistent object for an offset curve", py::arg("theCurve"), py::arg("theMap"));
*/

// CLASS: SHAPEPERSISTENT_HARRAY2
py::class_<ShapePersistent_HArray2> cls_ShapePersistent_HArray2(mod, "ShapePersistent_HArray2", "None");

// Constructors
cls_ShapePersistent_HArray2.def(py::init<>());

// CLASS: SHAPEPERSISTENT_GEOM_SURFACE
/*
py::class_<ShapePersistent_Geom_Surface> cls_ShapePersistent_Geom_Surface(mod, "ShapePersistent_Geom_Surface", "None");

// Constructors
cls_ShapePersistent_Geom_Surface.def(py::init<>());

// Methods
cls_ShapePersistent_Geom_Surface.def_static("Translate_", (opencascade::handle<Surface> (*)(const opencascade::handle<Geom_Plane> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Surface::Translate, "Create a persistent object for a plane", py::arg("theSurf"), py::arg("theMap"));
cls_ShapePersistent_Geom_Surface.def_static("Translate_", (opencascade::handle<Surface> (*)(const opencascade::handle<Geom_CylindricalSurface> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Surface::Translate, "Create a persistent object for a cylinder", py::arg("theSurf"), py::arg("theMap"));
cls_ShapePersistent_Geom_Surface.def_static("Translate_", (opencascade::handle<Surface> (*)(const opencascade::handle<Geom_ConicalSurface> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Surface::Translate, "Create a persistent object for a cone", py::arg("theSurf"), py::arg("theMap"));
cls_ShapePersistent_Geom_Surface.def_static("Translate_", (opencascade::handle<Surface> (*)(const opencascade::handle<Geom_SphericalSurface> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Surface::Translate, "Create a persistent object for a sphere", py::arg("theSurf"), py::arg("theMap"));
cls_ShapePersistent_Geom_Surface.def_static("Translate_", (opencascade::handle<Surface> (*)(const opencascade::handle<Geom_ToroidalSurface> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Surface::Translate, "Create a persistent object for a torus", py::arg("theSurf"), py::arg("theMap"));
cls_ShapePersistent_Geom_Surface.def_static("Translate_", (opencascade::handle<Surface> (*)(const opencascade::handle<Geom_SurfaceOfLinearExtrusion> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Surface::Translate, "Create a persistent object for a surface of linear extrusion", py::arg("theSurf"), py::arg("theMap"));
cls_ShapePersistent_Geom_Surface.def_static("Translate_", (opencascade::handle<Surface> (*)(const opencascade::handle<Geom_SurfaceOfRevolution> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Surface::Translate, "Create a persistent object for a surface of evolution", py::arg("theSurf"), py::arg("theMap"));
cls_ShapePersistent_Geom_Surface.def_static("Translate_", (opencascade::handle<Surface> (*)(const opencascade::handle<Geom_BezierSurface> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Surface::Translate, "Create a persistent object for a Bezier surface", py::arg("theSurf"), py::arg("theMap"));
cls_ShapePersistent_Geom_Surface.def_static("Translate_", (opencascade::handle<Surface> (*)(const opencascade::handle<Geom_BSplineSurface> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Surface::Translate, "Create a persistent object for a BSpline surface", py::arg("theSurf"), py::arg("theMap"));
cls_ShapePersistent_Geom_Surface.def_static("Translate_", (opencascade::handle<Surface> (*)(const opencascade::handle<Geom_RectangularTrimmedSurface> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Surface::Translate, "Create a persistent object for a rectangylar trimmed surface", py::arg("theSurf"), py::arg("theMap"));
cls_ShapePersistent_Geom_Surface.def_static("Translate_", (opencascade::handle<Surface> (*)(const opencascade::handle<Geom_OffsetSurface> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Surface::Translate, "Create a persistent object for an offset surface", py::arg("theSurf"), py::arg("theMap"));
*/

// CLASS: SHAPEPERSISTENT_HSEQUENCE
py::class_<ShapePersistent_HSequence> cls_ShapePersistent_HSequence(mod, "ShapePersistent_HSequence", "None");

// Constructors
cls_ShapePersistent_HSequence.def(py::init<>());


}
