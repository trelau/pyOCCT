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
#include <TCollection_AsciiString.hxx>
#include <TopAbs_State.hxx>
#include <Standard_OStream.hxx>
#include <TopOpeBRepDS_Kind.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopAbs_Orientation.hxx>
#include <TopOpeBRepDS_Config.hxx>
#include <TopOpeBRepDS_Interference.hxx>
#include <TopOpeBRepDS_InterferenceIterator.hxx>
#include <TopOpeBRepDS_TKI.hxx>
#include <TopOpeBRepDS_Transition.hxx>
#include <TopOpeBRepDS_CurvePointInterference.hxx>
#include <TopOpeBRepDS_SurfaceCurveInterference.hxx>
#include <TopOpeBRepDS_SolidSurfaceInterference.hxx>
#include <TopOpeBRepDS_ShapeShapeInterference.hxx>
#include <TopOpeBRepDS_EdgeVertexInterference.hxx>
#include <TopOpeBRepDS_FaceEdgeInterference.hxx>
#include <TopOpeBRepDS_Surface.hxx>
#include <TopOpeBRepDS_Curve.hxx>
#include <TopOpeBRepDS_Point.hxx>
#include <TopOpeBRepDS_GeometryData.hxx>
#include <TopOpeBRepDS_SurfaceData.hxx>
#include <TopOpeBRepDS_CurveData.hxx>
#include <TopOpeBRepDS_PointData.hxx>
#include <TopOpeBRepDS_ShapeData.hxx>
#include <TopOpeBRepDS_DataStructure.hxx>
#include <TopOpeBRepDS_SurfaceIterator.hxx>
#include <TopOpeBRepDS_CurveIterator.hxx>
#include <TopOpeBRepDS_PointIterator.hxx>
#include <TopOpeBRepDS_SurfaceExplorer.hxx>
#include <TopOpeBRepDS_CurveExplorer.hxx>
#include <TopOpeBRepDS_PointExplorer.hxx>
#include <TopOpeBRepDS_InterferenceTool.hxx>
#include <TopOpeBRepDS_BuildTool.hxx>
#include <TopOpeBRepDS_Dumper.hxx>
#include <TopOpeBRepDS_Marker.hxx>
#include <TopOpeBRepDS_HDataStructure.hxx>
#include <TopOpeBRepDS_EdgeInterferenceTool.hxx>
#include <TopOpeBRepDS_Edge3dInterferenceTool.hxx>
#include <TopOpeBRepDS_FaceInterferenceTool.hxx>
#include <TopOpeBRepDS_Filter.hxx>
#include <TopOpeBRepDS_Reducer.hxx>
#include <TopOpeBRepDS_TOOL.hxx>
#include <TopOpeBRepDS_FIR.hxx>
#include <TopOpeBRepDS_EIR.hxx>
#include <TopOpeBRepDS_Check.hxx>
#include <TopOpeBRepDS_GapFiller.hxx>
#include <TopOpeBRepDS_GapTool.hxx>
#include <TopOpeBRepDS_Association.hxx>
#include <TopOpeBRepDS_ListOfShapeOn1State.hxx>
#include <TopOpeBRepDS_Explorer.hxx>
#include <TopOpeBRepDS_ShapeWithState.hxx>
#include <TopOpeBRepDS.hxx>

void bind_TopOpeBRepDS(py::module &mod){

py::class_<TopOpeBRepDS, std::unique_ptr<TopOpeBRepDS, Deleter<TopOpeBRepDS>>> cls_TopOpeBRepDS(mod, "TopOpeBRepDS", "This package provides services used by the TopOpeBRepBuild package performing topological operations on the BRep data structure.");

// Constructors

// Fields

// Methods
// cls_TopOpeBRepDS.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS.def_static("SPrint_", (TCollection_AsciiString (*)(const TopAbs_State)) &TopOpeBRepDS::SPrint, "IN OU ON UN", py::arg("S"));
cls_TopOpeBRepDS.def_static("Print_", (Standard_OStream & (*)(const TopAbs_State, Standard_OStream &)) &TopOpeBRepDS::Print, "None", py::arg("S"), py::arg("OS"));
cls_TopOpeBRepDS.def_static("SPrint_", (TCollection_AsciiString (*)(const TopOpeBRepDS_Kind)) &TopOpeBRepDS::SPrint, "<K>", py::arg("K"));
cls_TopOpeBRepDS.def_static("SPrint_", [](const TopOpeBRepDS_Kind a0, const Standard_Integer a1) -> TCollection_AsciiString { return TopOpeBRepDS::SPrint(a0, a1); });
cls_TopOpeBRepDS.def_static("SPrint_", [](const TopOpeBRepDS_Kind a0, const Standard_Integer a1, const TCollection_AsciiString & a2) -> TCollection_AsciiString { return TopOpeBRepDS::SPrint(a0, a1, a2); });
cls_TopOpeBRepDS.def_static("SPrint_", (TCollection_AsciiString (*)(const TopOpeBRepDS_Kind, const Standard_Integer, const TCollection_AsciiString &, const TCollection_AsciiString &)) &TopOpeBRepDS::SPrint, "S1(<K>,<I>)S2", py::arg("K"), py::arg("I"), py::arg("B"), py::arg("A"));
cls_TopOpeBRepDS.def_static("Print_", (Standard_OStream & (*)(const TopOpeBRepDS_Kind, Standard_OStream &)) &TopOpeBRepDS::Print, "None", py::arg("K"), py::arg("S"));
cls_TopOpeBRepDS.def_static("Print_", [](const TopOpeBRepDS_Kind a0, const Standard_Integer a1, Standard_OStream & a2) -> Standard_OStream & { return TopOpeBRepDS::Print(a0, a1, a2); });
cls_TopOpeBRepDS.def_static("Print_", [](const TopOpeBRepDS_Kind a0, const Standard_Integer a1, Standard_OStream & a2, const TCollection_AsciiString & a3) -> Standard_OStream & { return TopOpeBRepDS::Print(a0, a1, a2, a3); });
cls_TopOpeBRepDS.def_static("Print_", (Standard_OStream & (*)(const TopOpeBRepDS_Kind, const Standard_Integer, Standard_OStream &, const TCollection_AsciiString &, const TCollection_AsciiString &)) &TopOpeBRepDS::Print, "None", py::arg("K"), py::arg("I"), py::arg("S"), py::arg("B"), py::arg("A"));
cls_TopOpeBRepDS.def_static("SPrint_", (TCollection_AsciiString (*)(const TopAbs_ShapeEnum)) &TopOpeBRepDS::SPrint, "None", py::arg("T"));
cls_TopOpeBRepDS.def_static("SPrint_", (TCollection_AsciiString (*)(const TopAbs_ShapeEnum, const Standard_Integer)) &TopOpeBRepDS::SPrint, "(<T>,<I>)", py::arg("T"), py::arg("I"));
cls_TopOpeBRepDS.def_static("Print_", (Standard_OStream & (*)(const TopAbs_ShapeEnum, const Standard_Integer, Standard_OStream &)) &TopOpeBRepDS::Print, "None", py::arg("T"), py::arg("I"), py::arg("S"));
cls_TopOpeBRepDS.def_static("SPrint_", (TCollection_AsciiString (*)(const TopAbs_Orientation)) &TopOpeBRepDS::SPrint, "None", py::arg("O"));
cls_TopOpeBRepDS.def_static("SPrint_", (TCollection_AsciiString (*)(const TopOpeBRepDS_Config)) &TopOpeBRepDS::SPrint, "None", py::arg("C"));
cls_TopOpeBRepDS.def_static("Print_", (Standard_OStream & (*)(const TopOpeBRepDS_Config, Standard_OStream &)) &TopOpeBRepDS::Print, "None", py::arg("C"), py::arg("S"));
cls_TopOpeBRepDS.def_static("IsGeometry_", (Standard_Boolean (*)(const TopOpeBRepDS_Kind)) &TopOpeBRepDS::IsGeometry, "None", py::arg("K"));
cls_TopOpeBRepDS.def_static("IsTopology_", (Standard_Boolean (*)(const TopOpeBRepDS_Kind)) &TopOpeBRepDS::IsTopology, "None", py::arg("K"));
cls_TopOpeBRepDS.def_static("KindToShape_", (TopAbs_ShapeEnum (*)(const TopOpeBRepDS_Kind)) &TopOpeBRepDS::KindToShape, "None", py::arg("K"));
cls_TopOpeBRepDS.def_static("ShapeToKind_", (TopOpeBRepDS_Kind (*)(const TopAbs_ShapeEnum)) &TopOpeBRepDS::ShapeToKind, "None", py::arg("S"));

// Enums

}