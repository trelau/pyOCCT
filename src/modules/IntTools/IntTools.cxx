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

void bind_IntTools_Curve(py::module &);
void bind_IntTools_ShrunkRange(py::module &);
void bind_IntTools_Context(py::module &);
void bind_IntTools_Range(py::module &);
void bind_IntTools_SequenceOfRanges(py::module &);
void bind_IntTools_CommonPrt(py::module &);
void bind_IntTools_Root(py::module &);
void bind_IntTools_SequenceOfRoots(py::module &);
void bind_IntTools(py::module &);
void bind_IntTools_Array1OfRange(py::module &);
void bind_IntTools_Array1OfRoots(py::module &);
void bind_IntTools_BaseRangeSample(py::module &);
void bind_IntTools_MarkedRangeSet(py::module &);
void bind_IntTools_CurveRangeSample(py::module &);
void bind_IntTools_ListOfCurveRangeSample(py::module &);
void bind_IntTools_ListIteratorOfListOfCurveRangeSample(py::module &);
void bind_IntTools_SurfaceRangeSample(py::module &);
void bind_IntTools_ListOfSurfaceRangeSample(py::module &);
void bind_IntTools_ListIteratorOfListOfSurfaceRangeSample(py::module &);
void bind_IntTools_BeanFaceIntersector(py::module &);
void bind_IntTools_CArray1OfInteger(py::module &);
void bind_IntTools_CArray1OfReal(py::module &);
void bind_IntTools_CurveRangeSampleMapHasher(py::module &);
void bind_IntTools_MapOfCurveSample(py::module &);
void bind_IntTools_MapIteratorOfMapOfCurveSample(py::module &);
void bind_IntTools_DataMapOfCurveSampleBox(py::module &);
void bind_IntTools_DataMapIteratorOfDataMapOfCurveSampleBox(py::module &);
void bind_IntTools_CurveRangeLocalizeData(py::module &);
void bind_IntTools_SurfaceRangeSampleMapHasher(py::module &);
void bind_IntTools_DataMapOfSurfaceSampleBox(py::module &);
void bind_IntTools_DataMapIteratorOfDataMapOfSurfaceSampleBox(py::module &);
void bind_IntTools_SequenceOfCommonPrts(py::module &);
void bind_IntTools_EdgeEdge(py::module &);
void bind_IntTools_EdgeFace(py::module &);
void bind_IntTools_SequenceOfCurves(py::module &);
void bind_IntTools_PntOnFace(py::module &);
void bind_IntTools_PntOn2Faces(py::module &);
void bind_IntTools_SequenceOfPntOn2Faces(py::module &);
void bind_IntTools_FaceFace(py::module &);
void bind_IntTools_FClass2d(py::module &);
void bind_IntTools_ListOfBox(py::module &);
void bind_IntTools_ListIteratorOfListOfBox(py::module &);
void bind_IntTools_MapOfSurfaceSample(py::module &);
void bind_IntTools_MapIteratorOfMapOfSurfaceSample(py::module &);
void bind_IntTools_SurfaceRangeLocalizeData(py::module &);
void bind_IntTools_Tools(py::module &);
void bind_IntTools_TopolTool(py::module &);
void bind_IntTools_WLineTool(py::module &);

PYBIND11_MODULE(IntTools, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Geom");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.gp");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.GeomAPI");
py::module::import("OCCT.BRepClass3d");
py::module::import("OCCT.Geom2dHatch");
py::module::import("OCCT.BRepAdaptor");
py::module::import("OCCT.Precision");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Extrema");
py::module::import("OCCT.IntSurf");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.IntPatch");
py::module::import("OCCT.GeomInt");
py::module::import("OCCT.GeomAdaptor");
py::module::import("OCCT.BRepTopAdaptor");
py::module::import("OCCT.TColgp");

bind_IntTools_Curve(mod);
bind_IntTools_ShrunkRange(mod);
bind_IntTools_Context(mod);
bind_IntTools_Range(mod);
bind_IntTools_SequenceOfRanges(mod);
bind_IntTools_CommonPrt(mod);
bind_IntTools_Root(mod);
bind_IntTools_SequenceOfRoots(mod);
bind_IntTools(mod);
bind_IntTools_Array1OfRange(mod);
bind_IntTools_Array1OfRoots(mod);
bind_IntTools_BaseRangeSample(mod);
bind_IntTools_MarkedRangeSet(mod);
bind_IntTools_CurveRangeSample(mod);
bind_IntTools_ListOfCurveRangeSample(mod);
bind_IntTools_ListIteratorOfListOfCurveRangeSample(mod);
bind_IntTools_SurfaceRangeSample(mod);
bind_IntTools_ListOfSurfaceRangeSample(mod);
bind_IntTools_ListIteratorOfListOfSurfaceRangeSample(mod);
bind_IntTools_BeanFaceIntersector(mod);
bind_IntTools_CArray1OfInteger(mod);
bind_IntTools_CArray1OfReal(mod);
bind_IntTools_CurveRangeSampleMapHasher(mod);
bind_IntTools_MapOfCurveSample(mod);
bind_IntTools_MapIteratorOfMapOfCurveSample(mod);
bind_IntTools_DataMapOfCurveSampleBox(mod);
bind_IntTools_DataMapIteratorOfDataMapOfCurveSampleBox(mod);
bind_IntTools_CurveRangeLocalizeData(mod);
bind_IntTools_SurfaceRangeSampleMapHasher(mod);
bind_IntTools_DataMapOfSurfaceSampleBox(mod);
bind_IntTools_DataMapIteratorOfDataMapOfSurfaceSampleBox(mod);
bind_IntTools_SequenceOfCommonPrts(mod);
bind_IntTools_EdgeEdge(mod);
bind_IntTools_EdgeFace(mod);
bind_IntTools_SequenceOfCurves(mod);
bind_IntTools_PntOnFace(mod);
bind_IntTools_PntOn2Faces(mod);
bind_IntTools_SequenceOfPntOn2Faces(mod);
bind_IntTools_FaceFace(mod);
bind_IntTools_FClass2d(mod);
bind_IntTools_ListOfBox(mod);
bind_IntTools_ListIteratorOfListOfBox(mod);
bind_IntTools_MapOfSurfaceSample(mod);
bind_IntTools_MapIteratorOfMapOfSurfaceSample(mod);
bind_IntTools_SurfaceRangeLocalizeData(mod);
bind_IntTools_Tools(mod);
bind_IntTools_TopolTool(mod);
bind_IntTools_WLineTool(mod);

}
