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

void bind_HLRBRep_TypeOfResultingEdge(py::module &);
void bind_HLRBRep_ShapeBounds(py::module &);
void bind_HLRBRep_SeqOfShapeBounds(py::module &);
void bind_HLRBRep_InternalAlgo(py::module &);
void bind_HLRBRep_Algo(py::module &);
void bind_HLRBRep(py::module &);
void bind_HLRBRep_AreaLimit(py::module &);
void bind_HLRBRep_Curve(py::module &);
void bind_HLRBRep_BCurveTool(py::module &);
void bind_HLRBRep_EdgeData(py::module &);
void bind_HLRBRep_Array1OfEData(py::module &);
void bind_HLRBRep_Surface(py::module &);
void bind_HLRBRep_BSurfaceTool(py::module &);
void bind_HLRBRep_FaceData(py::module &);
void bind_HLRBRep_Array1OfFData(py::module &);
void bind_HLRBRep_BiPnt2D(py::module &);
void bind_HLRBRep_BiPoint(py::module &);
void bind_HLRBRep_TheIntConicCurveOfCInter(py::module &);
void bind_HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter(py::module &);
void bind_HLRBRep_TheIntPCurvePCurveOfCInter(py::module &);
void bind_HLRBRep_CInter(py::module &);
void bind_HLRBRep_CLProps(py::module &);
void bind_HLRBRep_CLPropsATool(py::module &);
void bind_HLRBRep_CurveTool(py::module &);
void bind_HLRBRep_SLProps(py::module &);
void bind_HLRBRep_FaceIterator(py::module &);
void bind_HLRBRep_InterCSurf(py::module &);
void bind_HLRBRep_Intersector(py::module &);
void bind_HLRBRep_Data(py::module &);
void bind_HLRBRep_EdgeBuilder(py::module &);
void bind_HLRBRep_EdgeFaceTool(py::module &);
void bind_HLRBRep_EdgeIList(py::module &);
void bind_HLRBRep_EdgeInterferenceTool(py::module &);
void bind_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter(py::module &);
void bind_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter(py::module &);
void bind_HLRBRep_Hider(py::module &);
void bind_HLRBRep_HLRToShape(py::module &);
void bind_HLRBRep_IntConicCurveOfCInter(py::module &);
void bind_HLRBRep_LineTool(py::module &);
void bind_HLRBRep_ListOfBPnt2D(py::module &);
void bind_HLRBRep_ListIteratorOfListOfBPnt2D(py::module &);
void bind_HLRBRep_ListOfBPoint(py::module &);
void bind_HLRBRep_ListIteratorOfListOfBPoint(py::module &);
void bind_HLRBRep_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfCInter(py::module &);
void bind_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter(py::module &);
void bind_HLRBRep_PolyAlgo(py::module &);
void bind_HLRBRep_PolyHLRToShape(py::module &);
void bind_HLRBRep_ShapeToHLR(py::module &);
void bind_HLRBRep_SLPropsATool(py::module &);
void bind_HLRBRep_SurfaceTool(py::module &);
void bind_HLRBRep_TheCSFunctionOfInterCSurf(py::module &);
void bind_HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter(py::module &);
void bind_HLRBRep_TheExactInterCSurf(py::module &);
void bind_HLRBRep_TheInterferenceOfInterCSurf(py::module &);
void bind_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter(py::module &);
void bind_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter(py::module &);
void bind_HLRBRep_ThePolygonOfInterCSurf(py::module &);
void bind_HLRBRep_ThePolygonToolOfInterCSurf(py::module &);
void bind_HLRBRep_ThePolyhedronOfInterCSurf(py::module &);
void bind_HLRBRep_ThePolyhedronToolOfInterCSurf(py::module &);
void bind_HLRBRep_TheProjPCurOfCInter(py::module &);
void bind_HLRBRep_TheQuadCurvExactInterCSurf(py::module &);
void bind_HLRBRep_TheQuadCurvFuncOfTheQuadCurvExactInterCSurf(py::module &);
void bind_HLRBRep_VertexList(py::module &);

PYBIND11_MODULE(HLRBRep, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.HLRTopoBRep");
py::module::import("OCCT.HLRAlgo");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.BRepTopAdaptor");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.BRepAdaptor");
py::module::import("OCCT.gp");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.IntRes2d");
py::module::import("OCCT.IntCurve");
py::module::import("OCCT.LProp");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.IntCurveSurface");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.IntAna");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.math");
py::module::import("OCCT.Extrema");
py::module::import("OCCT.Intf");
py::module::import("OCCT.IntSurf");

bind_HLRBRep_TypeOfResultingEdge(mod);
bind_HLRBRep_ShapeBounds(mod);
bind_HLRBRep_SeqOfShapeBounds(mod);
bind_HLRBRep_InternalAlgo(mod);
bind_HLRBRep_Algo(mod);
bind_HLRBRep(mod);
bind_HLRBRep_AreaLimit(mod);
bind_HLRBRep_Curve(mod);
bind_HLRBRep_BCurveTool(mod);
bind_HLRBRep_EdgeData(mod);
bind_HLRBRep_Array1OfEData(mod);
bind_HLRBRep_Surface(mod);
bind_HLRBRep_BSurfaceTool(mod);
bind_HLRBRep_FaceData(mod);
bind_HLRBRep_Array1OfFData(mod);
bind_HLRBRep_BiPnt2D(mod);
bind_HLRBRep_BiPoint(mod);
bind_HLRBRep_TheIntConicCurveOfCInter(mod);
bind_HLRBRep_TheIntersectorOfTheIntConicCurveOfCInter(mod);
bind_HLRBRep_TheIntPCurvePCurveOfCInter(mod);
bind_HLRBRep_CInter(mod);
bind_HLRBRep_CLProps(mod);
bind_HLRBRep_CLPropsATool(mod);
bind_HLRBRep_CurveTool(mod);
bind_HLRBRep_SLProps(mod);
bind_HLRBRep_FaceIterator(mod);
bind_HLRBRep_InterCSurf(mod);
bind_HLRBRep_Intersector(mod);
bind_HLRBRep_Data(mod);
bind_HLRBRep_EdgeBuilder(mod);
bind_HLRBRep_EdgeFaceTool(mod);
bind_HLRBRep_EdgeIList(mod);
bind_HLRBRep_EdgeInterferenceTool(mod);
bind_HLRBRep_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfCInter(mod);
bind_HLRBRep_ExactIntersectionPointOfTheIntPCurvePCurveOfCInter(mod);
bind_HLRBRep_Hider(mod);
bind_HLRBRep_HLRToShape(mod);
bind_HLRBRep_IntConicCurveOfCInter(mod);
bind_HLRBRep_LineTool(mod);
bind_HLRBRep_ListOfBPnt2D(mod);
bind_HLRBRep_ListIteratorOfListOfBPnt2D(mod);
bind_HLRBRep_ListOfBPoint(mod);
bind_HLRBRep_ListIteratorOfListOfBPoint(mod);
bind_HLRBRep_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfCInter(mod);
bind_HLRBRep_PCLocFOfTheLocateExtPCOfTheProjPCurOfCInter(mod);
bind_HLRBRep_PolyAlgo(mod);
bind_HLRBRep_PolyHLRToShape(mod);
bind_HLRBRep_ShapeToHLR(mod);
bind_HLRBRep_SLPropsATool(mod);
bind_HLRBRep_SurfaceTool(mod);
bind_HLRBRep_TheCSFunctionOfInterCSurf(mod);
bind_HLRBRep_TheCurveLocatorOfTheProjPCurOfCInter(mod);
bind_HLRBRep_TheExactInterCSurf(mod);
bind_HLRBRep_TheInterferenceOfInterCSurf(mod);
bind_HLRBRep_TheLocateExtPCOfTheProjPCurOfCInter(mod);
bind_HLRBRep_ThePolygon2dOfTheIntPCurvePCurveOfCInter(mod);
bind_HLRBRep_ThePolygonOfInterCSurf(mod);
bind_HLRBRep_ThePolygonToolOfInterCSurf(mod);
bind_HLRBRep_ThePolyhedronOfInterCSurf(mod);
bind_HLRBRep_ThePolyhedronToolOfInterCSurf(mod);
bind_HLRBRep_TheProjPCurOfCInter(mod);
bind_HLRBRep_TheQuadCurvExactInterCSurf(mod);
bind_HLRBRep_TheQuadCurvFuncOfTheQuadCurvExactInterCSurf(mod);
bind_HLRBRep_VertexList(mod);

}
