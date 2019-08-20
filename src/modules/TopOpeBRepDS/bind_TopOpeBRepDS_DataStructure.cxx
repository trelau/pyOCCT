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
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepDS_Surface.hxx>
#include <TopOpeBRepDS_Curve.hxx>
#include <TopOpeBRepDS_Point.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Edge.hxx>
#include <TopOpeBRepDS_ListOfInterference.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopOpeBRepDS_MapOfShapeData.hxx>
#include <TopOpeBRepDS_Config.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_Interference.hxx>
#include <Geom_Surface.hxx>
#include <TopOpeBRepDS_IndexedDataMapOfShapeWithState.hxx>
#include <TopOpeBRepDS_ShapeWithState.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopOpeBRepDS_SurfaceExplorer.hxx>
#include <TopOpeBRepDS_CurveExplorer.hxx>
#include <TopOpeBRepDS_PointExplorer.hxx>
#include <TopOpeBRepDS_MapOfSurface.hxx>
#include <TopOpeBRepDS_MapOfCurve.hxx>
#include <TopOpeBRepDS_MapOfPoint.hxx>
#include <TopOpeBRepDS_ShapeSurface.hxx>
#include <TopOpeBRepDS_DataStructure.hxx>

void bind_TopOpeBRepDS_DataStructure(py::module &mod){

py::class_<TopOpeBRepDS_DataStructure, std::unique_ptr<TopOpeBRepDS_DataStructure>> cls_TopOpeBRepDS_DataStructure(mod, "TopOpeBRepDS_DataStructure", "The DataStructure stores :");

// Constructors
cls_TopOpeBRepDS_DataStructure.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRepDS_DataStructure.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_DataStructure::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_DataStructure.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_DataStructure::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_DataStructure.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_DataStructure::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_DataStructure.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_DataStructure::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_DataStructure.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_DataStructure::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_DataStructure.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_DataStructure::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_DataStructure.def("Init", (void (TopOpeBRepDS_DataStructure::*)()) &TopOpeBRepDS_DataStructure::Init, "reset the data structure");
cls_TopOpeBRepDS_DataStructure.def("AddSurface", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopOpeBRepDS_Surface &)) &TopOpeBRepDS_DataStructure::AddSurface, "Insert a new surface. Returns the index.", py::arg("S"));
cls_TopOpeBRepDS_DataStructure.def("RemoveSurface", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::RemoveSurface, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("KeepSurface", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::KeepSurface, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("KeepSurface", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(TopOpeBRepDS_Surface &) const) &TopOpeBRepDS_DataStructure::KeepSurface, "None", py::arg("S"));
cls_TopOpeBRepDS_DataStructure.def("ChangeKeepSurface", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::ChangeKeepSurface, "None", py::arg("I"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("ChangeKeepSurface", (void (TopOpeBRepDS_DataStructure::*)(TopOpeBRepDS_Surface &, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::ChangeKeepSurface, "None", py::arg("S"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("AddCurve", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopOpeBRepDS_Curve &)) &TopOpeBRepDS_DataStructure::AddCurve, "Insert a new curve. Returns the index.", py::arg("S"));
cls_TopOpeBRepDS_DataStructure.def("RemoveCurve", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::RemoveCurve, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("KeepCurve", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::KeepCurve, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("KeepCurve", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const TopOpeBRepDS_Curve &) const) &TopOpeBRepDS_DataStructure::KeepCurve, "None", py::arg("C"));
cls_TopOpeBRepDS_DataStructure.def("ChangeKeepCurve", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::ChangeKeepCurve, "None", py::arg("I"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("ChangeKeepCurve", (void (TopOpeBRepDS_DataStructure::*)(TopOpeBRepDS_Curve &, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::ChangeKeepCurve, "None", py::arg("C"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("AddPoint", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopOpeBRepDS_Point &)) &TopOpeBRepDS_DataStructure::AddPoint, "Insert a new point. Returns the index.", py::arg("PDS"));
cls_TopOpeBRepDS_DataStructure.def("AddPointSS", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopOpeBRepDS_Point &, const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepDS_DataStructure::AddPointSS, "Insert a new point. Returns the index.", py::arg("PDS"), py::arg("S1"), py::arg("S2"));
cls_TopOpeBRepDS_DataStructure.def("RemovePoint", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::RemovePoint, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("KeepPoint", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::KeepPoint, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("KeepPoint", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const TopOpeBRepDS_Point &) const) &TopOpeBRepDS_DataStructure::KeepPoint, "None", py::arg("P"));
cls_TopOpeBRepDS_DataStructure.def("ChangeKeepPoint", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::ChangeKeepPoint, "None", py::arg("I"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("ChangeKeepPoint", (void (TopOpeBRepDS_DataStructure::*)(TopOpeBRepDS_Point &, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::ChangeKeepPoint, "None", py::arg("P"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("AddShape", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &)) &TopOpeBRepDS_DataStructure::AddShape, "Insert a shape S. Returns the index.", py::arg("S"));
cls_TopOpeBRepDS_DataStructure.def("AddShape", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const Standard_Integer)) &TopOpeBRepDS_DataStructure::AddShape, "Insert a shape S which ancestor is I = 1 or 2. Returns the index.", py::arg("S"), py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("KeepShape", [](TopOpeBRepDS_DataStructure &self, const Standard_Integer a0) -> Standard_Boolean { return self.KeepShape(a0); });
cls_TopOpeBRepDS_DataStructure.def("KeepShape", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Boolean) const) &TopOpeBRepDS_DataStructure::KeepShape, "None", py::arg("I"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("KeepShape", [](TopOpeBRepDS_DataStructure &self, const TopoDS_Shape & a0) -> Standard_Boolean { return self.KeepShape(a0); });
cls_TopOpeBRepDS_DataStructure.def("KeepShape", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const Standard_Boolean) const) &TopOpeBRepDS_DataStructure::KeepShape, "None", py::arg("S"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("ChangeKeepShape", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::ChangeKeepShape, "None", py::arg("I"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("ChangeKeepShape", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::ChangeKeepShape, "None", py::arg("S"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("InitSectionEdges", (void (TopOpeBRepDS_DataStructure::*)()) &TopOpeBRepDS_DataStructure::InitSectionEdges, "None");
cls_TopOpeBRepDS_DataStructure.def("AddSectionEdge", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopoDS_Edge &)) &TopOpeBRepDS_DataStructure::AddSectionEdge, "None", py::arg("E"));
cls_TopOpeBRepDS_DataStructure.def("SurfaceInterferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::SurfaceInterferences, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("ChangeSurfaceInterferences", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::ChangeSurfaceInterferences, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("CurveInterferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::CurveInterferences, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("ChangeCurveInterferences", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::ChangeCurveInterferences, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("PointInterferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::PointInterferences, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("ChangePointInterferences", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::ChangePointInterferences, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("ShapeInterferences", [](TopOpeBRepDS_DataStructure &self, const TopoDS_Shape & a0) -> const TopOpeBRepDS_ListOfInterference & { return self.ShapeInterferences(a0); });
cls_TopOpeBRepDS_DataStructure.def("ShapeInterferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const Standard_Boolean) const) &TopOpeBRepDS_DataStructure::ShapeInterferences, "None", py::arg("S"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("ChangeShapeInterferences", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &)) &TopOpeBRepDS_DataStructure::ChangeShapeInterferences, "None", py::arg("S"));
cls_TopOpeBRepDS_DataStructure.def("ShapeInterferences", [](TopOpeBRepDS_DataStructure &self, const Standard_Integer a0) -> const TopOpeBRepDS_ListOfInterference & { return self.ShapeInterferences(a0); });
cls_TopOpeBRepDS_DataStructure.def("ShapeInterferences", (const TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Boolean) const) &TopOpeBRepDS_DataStructure::ShapeInterferences, "None", py::arg("I"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("ChangeShapeInterferences", (TopOpeBRepDS_ListOfInterference & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::ChangeShapeInterferences, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("ShapeSameDomain", (const TopTools_ListOfShape & (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_DataStructure::ShapeSameDomain, "None", py::arg("S"));
cls_TopOpeBRepDS_DataStructure.def("ChangeShapeSameDomain", (TopTools_ListOfShape & (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &)) &TopOpeBRepDS_DataStructure::ChangeShapeSameDomain, "None", py::arg("S"));
cls_TopOpeBRepDS_DataStructure.def("ShapeSameDomain", (const TopTools_ListOfShape & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::ShapeSameDomain, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("ChangeShapeSameDomain", (TopTools_ListOfShape & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::ChangeShapeSameDomain, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("ChangeShapes", (TopOpeBRepDS_MapOfShapeData & (TopOpeBRepDS_DataStructure::*)()) &TopOpeBRepDS_DataStructure::ChangeShapes, "None");
cls_TopOpeBRepDS_DataStructure.def("AddShapeSameDomain", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepDS_DataStructure::AddShapeSameDomain, "None", py::arg("S"), py::arg("SSD"));
cls_TopOpeBRepDS_DataStructure.def("RemoveShapeSameDomain", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepDS_DataStructure::RemoveShapeSameDomain, "None", py::arg("S"), py::arg("SSD"));
cls_TopOpeBRepDS_DataStructure.def("SameDomainRef", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::SameDomainRef, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("SameDomainRef", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_DataStructure::SameDomainRef, "None", py::arg("S"));
cls_TopOpeBRepDS_DataStructure.def("SameDomainRef", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRepDS_DataStructure::SameDomainRef, "None", py::arg("I"), py::arg("Ref"));
cls_TopOpeBRepDS_DataStructure.def("SameDomainRef", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const Standard_Integer)) &TopOpeBRepDS_DataStructure::SameDomainRef, "None", py::arg("S"), py::arg("Ref"));
cls_TopOpeBRepDS_DataStructure.def("SameDomainOri", (TopOpeBRepDS_Config (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::SameDomainOri, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("SameDomainOri", (TopOpeBRepDS_Config (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_DataStructure::SameDomainOri, "None", py::arg("S"));
cls_TopOpeBRepDS_DataStructure.def("SameDomainOri", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const TopOpeBRepDS_Config)) &TopOpeBRepDS_DataStructure::SameDomainOri, "None", py::arg("I"), py::arg("Ori"));
cls_TopOpeBRepDS_DataStructure.def("SameDomainOri", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const TopOpeBRepDS_Config)) &TopOpeBRepDS_DataStructure::SameDomainOri, "None", py::arg("S"), py::arg("Ori"));
cls_TopOpeBRepDS_DataStructure.def("SameDomainInd", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::SameDomainInd, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("SameDomainInd", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_DataStructure::SameDomainInd, "None", py::arg("S"));
cls_TopOpeBRepDS_DataStructure.def("SameDomainInd", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRepDS_DataStructure::SameDomainInd, "None", py::arg("I"), py::arg("Ind"));
cls_TopOpeBRepDS_DataStructure.def("SameDomainInd", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const Standard_Integer)) &TopOpeBRepDS_DataStructure::SameDomainInd, "None", py::arg("S"), py::arg("Ind"));
cls_TopOpeBRepDS_DataStructure.def("AncestorRank", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::AncestorRank, "None", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("AncestorRank", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_DataStructure::AncestorRank, "None", py::arg("S"));
cls_TopOpeBRepDS_DataStructure.def("AncestorRank", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRepDS_DataStructure::AncestorRank, "None", py::arg("I"), py::arg("Ianc"));
cls_TopOpeBRepDS_DataStructure.def("AncestorRank", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const Standard_Integer)) &TopOpeBRepDS_DataStructure::AncestorRank, "None", py::arg("S"), py::arg("Ianc"));
cls_TopOpeBRepDS_DataStructure.def("AddShapeInterference", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_DataStructure::AddShapeInterference, "None", py::arg("S"), py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("RemoveShapeInterference", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const opencascade::handle<TopOpeBRepDS_Interference> &)) &TopOpeBRepDS_DataStructure::RemoveShapeInterference, "None", py::arg("S"), py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("FillShapesSameDomain", [](TopOpeBRepDS_DataStructure &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1) -> void { return self.FillShapesSameDomain(a0, a1); });
cls_TopOpeBRepDS_DataStructure.def("FillShapesSameDomain", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::FillShapesSameDomain, "None", py::arg("S1"), py::arg("S2"), py::arg("refFirst"));
cls_TopOpeBRepDS_DataStructure.def("FillShapesSameDomain", [](TopOpeBRepDS_DataStructure &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1, const TopOpeBRepDS_Config a2, const TopOpeBRepDS_Config a3) -> void { return self.FillShapesSameDomain(a0, a1, a2, a3); });
cls_TopOpeBRepDS_DataStructure.def("FillShapesSameDomain", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopOpeBRepDS_Config, const TopOpeBRepDS_Config, const Standard_Boolean)) &TopOpeBRepDS_DataStructure::FillShapesSameDomain, "None", py::arg("S1"), py::arg("S2"), py::arg("c1"), py::arg("c2"), py::arg("refFirst"));
cls_TopOpeBRepDS_DataStructure.def("UnfillShapesSameDomain", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepDS_DataStructure::UnfillShapesSameDomain, "None", py::arg("S1"), py::arg("S2"));
cls_TopOpeBRepDS_DataStructure.def("NbSurfaces", (Standard_Integer (TopOpeBRepDS_DataStructure::*)() const) &TopOpeBRepDS_DataStructure::NbSurfaces, "None");
cls_TopOpeBRepDS_DataStructure.def("NbCurves", (Standard_Integer (TopOpeBRepDS_DataStructure::*)() const) &TopOpeBRepDS_DataStructure::NbCurves, "None");
cls_TopOpeBRepDS_DataStructure.def("ChangeNbCurves", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::ChangeNbCurves, "None", py::arg("N"));
cls_TopOpeBRepDS_DataStructure.def("NbPoints", (Standard_Integer (TopOpeBRepDS_DataStructure::*)() const) &TopOpeBRepDS_DataStructure::NbPoints, "None");
cls_TopOpeBRepDS_DataStructure.def("NbShapes", (Standard_Integer (TopOpeBRepDS_DataStructure::*)() const) &TopOpeBRepDS_DataStructure::NbShapes, "None");
cls_TopOpeBRepDS_DataStructure.def("NbSectionEdges", (Standard_Integer (TopOpeBRepDS_DataStructure::*)() const) &TopOpeBRepDS_DataStructure::NbSectionEdges, "None");
cls_TopOpeBRepDS_DataStructure.def("Surface", (const TopOpeBRepDS_Surface & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::Surface, "Returns the surface of index <I>.", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("ChangeSurface", (TopOpeBRepDS_Surface & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::ChangeSurface, "Returns the surface of index <I>.", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("Curve", (const TopOpeBRepDS_Curve & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::Curve, "Returns the Curve of index <I>.", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("ChangeCurve", (TopOpeBRepDS_Curve & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::ChangeCurve, "Returns the Curve of index <I>.", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("Point", (const TopOpeBRepDS_Point & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_DataStructure::Point, "Returns the point of index <I>.", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("ChangePoint", (TopOpeBRepDS_Point & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_DataStructure::ChangePoint, "Returns the point of index <I>.", py::arg("I"));
cls_TopOpeBRepDS_DataStructure.def("Shape", [](TopOpeBRepDS_DataStructure &self, const Standard_Integer a0) -> const TopoDS_Shape & { return self.Shape(a0); });
cls_TopOpeBRepDS_DataStructure.def("Shape", (const TopoDS_Shape & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Boolean) const) &TopOpeBRepDS_DataStructure::Shape, "returns the shape of index I stored in the map myShapes, accessing a list of interference.", py::arg("I"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("Shape", [](TopOpeBRepDS_DataStructure &self, const TopoDS_Shape & a0) -> Standard_Integer { return self.Shape(a0); });
cls_TopOpeBRepDS_DataStructure.def("Shape", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const Standard_Boolean) const) &TopOpeBRepDS_DataStructure::Shape, "returns the index of shape <S> stored in the map myShapes, accessing a list of interference. returns 0 if <S> is not in the map.", py::arg("S"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("SectionEdge", [](TopOpeBRepDS_DataStructure &self, const Standard_Integer a0) -> const TopoDS_Edge & { return self.SectionEdge(a0); });
cls_TopOpeBRepDS_DataStructure.def("SectionEdge", (const TopoDS_Edge & (TopOpeBRepDS_DataStructure::*)(const Standard_Integer, const Standard_Boolean) const) &TopOpeBRepDS_DataStructure::SectionEdge, "None", py::arg("I"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("SectionEdge", [](TopOpeBRepDS_DataStructure &self, const TopoDS_Edge & a0) -> Standard_Integer { return self.SectionEdge(a0); });
cls_TopOpeBRepDS_DataStructure.def("SectionEdge", (Standard_Integer (TopOpeBRepDS_DataStructure::*)(const TopoDS_Edge &, const Standard_Boolean) const) &TopOpeBRepDS_DataStructure::SectionEdge, "None", py::arg("E"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("IsSectionEdge", [](TopOpeBRepDS_DataStructure &self, const TopoDS_Edge & a0) -> Standard_Boolean { return self.IsSectionEdge(a0); });
cls_TopOpeBRepDS_DataStructure.def("IsSectionEdge", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const TopoDS_Edge &, const Standard_Boolean) const) &TopOpeBRepDS_DataStructure::IsSectionEdge, "None", py::arg("E"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("HasGeometry", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_DataStructure::HasGeometry, "Returns True if <S> has new geometries, i.e : True si : HasShape(S) True S a une liste d'interferences non vide. S = SOLID, FACE, EDGE : true/false S = SHELL, WIRE, VERTEX : false.", py::arg("S"));
cls_TopOpeBRepDS_DataStructure.def("HasShape", [](TopOpeBRepDS_DataStructure &self, const TopoDS_Shape & a0) -> Standard_Boolean { return self.HasShape(a0); });
cls_TopOpeBRepDS_DataStructure.def("HasShape", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const Standard_Boolean) const) &TopOpeBRepDS_DataStructure::HasShape, "Returns True if <S> est dans myShapes", py::arg("S"), py::arg("FindKeep"));
cls_TopOpeBRepDS_DataStructure.def("SetNewSurface", (void (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &, const opencascade::handle<Geom_Surface> &)) &TopOpeBRepDS_DataStructure::SetNewSurface, "None", py::arg("F"), py::arg("S"));
cls_TopOpeBRepDS_DataStructure.def("HasNewSurface", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_DataStructure::HasNewSurface, "None", py::arg("F"));
cls_TopOpeBRepDS_DataStructure.def("NewSurface", (const opencascade::handle<Geom_Surface> & (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_DataStructure::NewSurface, "None", py::arg("F"));
cls_TopOpeBRepDS_DataStructure.def("Isfafa", (void (TopOpeBRepDS_DataStructure::*)(const Standard_Boolean)) &TopOpeBRepDS_DataStructure::Isfafa, "None", py::arg("isfafa"));
cls_TopOpeBRepDS_DataStructure.def("Isfafa", (Standard_Boolean (TopOpeBRepDS_DataStructure::*)() const) &TopOpeBRepDS_DataStructure::Isfafa, "None");
cls_TopOpeBRepDS_DataStructure.def("ChangeMapOfShapeWithStateObj", (TopOpeBRepDS_IndexedDataMapOfShapeWithState & (TopOpeBRepDS_DataStructure::*)()) &TopOpeBRepDS_DataStructure::ChangeMapOfShapeWithStateObj, "None");
cls_TopOpeBRepDS_DataStructure.def("ChangeMapOfShapeWithStateTool", (TopOpeBRepDS_IndexedDataMapOfShapeWithState & (TopOpeBRepDS_DataStructure::*)()) &TopOpeBRepDS_DataStructure::ChangeMapOfShapeWithStateTool, "None");
cls_TopOpeBRepDS_DataStructure.def("ChangeMapOfShapeWithState", [](TopOpeBRepDS_DataStructure &self, const TopoDS_Shape & aShape, Standard_Boolean & aFlag){ TopOpeBRepDS_IndexedDataMapOfShapeWithState & rv = self.ChangeMapOfShapeWithState(aShape, aFlag); return std::tuple<TopOpeBRepDS_IndexedDataMapOfShapeWithState &, Standard_Boolean &>(rv, aFlag); }, "None", py::arg("aShape"), py::arg("aFlag"));
cls_TopOpeBRepDS_DataStructure.def("GetShapeWithState", (const TopOpeBRepDS_ShapeWithState & (TopOpeBRepDS_DataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_DataStructure::GetShapeWithState, "None", py::arg("aShape"));
cls_TopOpeBRepDS_DataStructure.def("ChangeMapOfRejectedShapesObj", (TopTools_IndexedMapOfShape & (TopOpeBRepDS_DataStructure::*)()) &TopOpeBRepDS_DataStructure::ChangeMapOfRejectedShapesObj, "None");
cls_TopOpeBRepDS_DataStructure.def("ChangeMapOfRejectedShapesTool", (TopTools_IndexedMapOfShape & (TopOpeBRepDS_DataStructure::*)()) &TopOpeBRepDS_DataStructure::ChangeMapOfRejectedShapesTool, "None");

// Enums

}