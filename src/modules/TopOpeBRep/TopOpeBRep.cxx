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

void bind_TopOpeBRep_TypeLineCurve(py::module &);
void bind_TopOpeBRep_P2Dstatus(py::module &);
void bind_TopOpeBRep_ShapeScanner(py::module &);
void bind_TopOpeBRep_PPntOn2S(py::module &);
void bind_TopOpeBRep_WPointInter(py::module &);
void bind_TopOpeBRep_PThePointOfIntersection(py::module &);
void bind_TopOpeBRep_VPointInter(py::module &);
void bind_TopOpeBRep_Array1OfVPointInter(py::module &);
void bind_TopOpeBRep_HArray1OfVPointInter(py::module &);
void bind_TopOpeBRep_LineInter(py::module &);
void bind_TopOpeBRep_Array1OfLineInter(py::module &);
void bind_TopOpeBRep_HArray1OfLineInter(py::module &);
void bind_TopOpeBRep_FacesIntersector(py::module &);
void bind_TopOpeBRep_Point2d(py::module &);
void bind_TopOpeBRep_SequenceOfPoint2d(py::module &);
void bind_TopOpeBRep_EdgesIntersector(py::module &);
void bind_TopOpeBRep_FaceEdgeIntersector(py::module &);
void bind_TopOpeBRep_ShapeIntersector(py::module &);
void bind_TopOpeBRep_ShapeIntersector2d(py::module &);
void bind_TopOpeBRep_PFacesIntersector(py::module &);
void bind_TopOpeBRep_PLineInter(py::module &);
void bind_TopOpeBRep_DataMapOfTopolTool(py::module &);
void bind_TopOpeBRep_DataMapIteratorOfDataMapOfTopolTool(py::module &);
void bind_TopOpeBRep_PointClassifier(py::module &);
void bind_TopOpeBRep_FacesFiller(py::module &);
void bind_TopOpeBRep_PEdgesIntersector(py::module &);
void bind_TopOpeBRep_EdgesFiller(py::module &);
void bind_TopOpeBRep_FaceEdgeFiller(py::module &);
void bind_TopOpeBRep_DSFiller(py::module &);
void bind_TopOpeBRep(py::module &);
void bind_TopOpeBRep_Bipoint(py::module &);
void bind_TopOpeBRep_PFacesFiller(py::module &);
void bind_TopOpeBRep_FFDumper(py::module &);
void bind_TopOpeBRep_FFTransitionTool(py::module &);
void bind_TopOpeBRep_GeomTool(py::module &);
void bind_TopOpeBRep_Hctxee2d(py::module &);
void bind_TopOpeBRep_Hctxff2d(py::module &);
void bind_TopOpeBRep_ListOfBipoint(py::module &);
void bind_TopOpeBRep_ListIteratorOfListOfBipoint(py::module &);
void bind_TopOpeBRep_PIntRes2d_IntersectionPoint(py::module &);
void bind_TopOpeBRep_PointGeomTool(py::module &);
void bind_TopOpeBRep_VPointInterClassifier(py::module &);
void bind_TopOpeBRep_VPointInterIterator(py::module &);
void bind_TopOpeBRep_WPointInterIterator(py::module &);

PYBIND11_MODULE(TopOpeBRep, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.TopOpeBRepTool");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.IntSurf");
py::module::import("OCCT.gp");
py::module::import("OCCT.IntPatch");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.BRepAdaptor");
py::module::import("OCCT.Geom");
py::module::import("OCCT.TopOpeBRepDS");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.BRepTopAdaptor");
py::module::import("OCCT.IntRes2d");
py::module::import("OCCT.Geom2dAdaptor");
py::module::import("OCCT.Geom2dInt");
py::module::import("OCCT.GeomAdaptor");
py::module::import("OCCT.IntCurveSurface");
py::module::import("OCCT.TopExp");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.BRepClass");

bind_TopOpeBRep_TypeLineCurve(mod);
bind_TopOpeBRep_P2Dstatus(mod);
bind_TopOpeBRep_ShapeScanner(mod);
bind_TopOpeBRep_PPntOn2S(mod);
bind_TopOpeBRep_WPointInter(mod);
bind_TopOpeBRep_PThePointOfIntersection(mod);
bind_TopOpeBRep_VPointInter(mod);
bind_TopOpeBRep_Array1OfVPointInter(mod);
bind_TopOpeBRep_HArray1OfVPointInter(mod);
bind_TopOpeBRep_LineInter(mod);
bind_TopOpeBRep_Array1OfLineInter(mod);
bind_TopOpeBRep_HArray1OfLineInter(mod);
bind_TopOpeBRep_FacesIntersector(mod);
bind_TopOpeBRep_Point2d(mod);
bind_TopOpeBRep_SequenceOfPoint2d(mod);
bind_TopOpeBRep_EdgesIntersector(mod);
bind_TopOpeBRep_FaceEdgeIntersector(mod);
bind_TopOpeBRep_ShapeIntersector(mod);
bind_TopOpeBRep_ShapeIntersector2d(mod);
bind_TopOpeBRep_PFacesIntersector(mod);
bind_TopOpeBRep_PLineInter(mod);
bind_TopOpeBRep_DataMapOfTopolTool(mod);
bind_TopOpeBRep_DataMapIteratorOfDataMapOfTopolTool(mod);
bind_TopOpeBRep_PointClassifier(mod);
bind_TopOpeBRep_FacesFiller(mod);
bind_TopOpeBRep_PEdgesIntersector(mod);
bind_TopOpeBRep_EdgesFiller(mod);
bind_TopOpeBRep_FaceEdgeFiller(mod);
bind_TopOpeBRep_DSFiller(mod);
bind_TopOpeBRep(mod);
bind_TopOpeBRep_Bipoint(mod);
bind_TopOpeBRep_PFacesFiller(mod);
bind_TopOpeBRep_FFDumper(mod);
bind_TopOpeBRep_FFTransitionTool(mod);
bind_TopOpeBRep_GeomTool(mod);
bind_TopOpeBRep_Hctxee2d(mod);
bind_TopOpeBRep_Hctxff2d(mod);
bind_TopOpeBRep_ListOfBipoint(mod);
bind_TopOpeBRep_ListIteratorOfListOfBipoint(mod);
bind_TopOpeBRep_PIntRes2d_IntersectionPoint(mod);
bind_TopOpeBRep_PointGeomTool(mod);
bind_TopOpeBRep_VPointInterClassifier(mod);
bind_TopOpeBRep_VPointInterIterator(mod);
bind_TopOpeBRep_WPointInterIterator(mod);

}
