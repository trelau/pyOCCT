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
#include <Standard_Transient.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopOpeBRepDS_DataStructure.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRepDS_Surface.hxx>
#include <TopOpeBRepDS_CurveIterator.hxx>
#include <TopOpeBRepDS_Curve.hxx>
#include <TopOpeBRepDS_PointIterator.hxx>
#include <TopOpeBRepDS_Point.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopOpeBRepDS_Config.hxx>
#include <TopOpeBRepDS_SurfaceIterator.hxx>
#include <TopOpeBRepDS_Kind.hxx>
#include <TopOpeBRepDS_ListOfInterference.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_Interference.hxx>
#include <TCollection_AsciiString.hxx>
#include <TopOpeBRepDS_HDataStructure.hxx>
#include <Standard_Type.hxx>

void bind_TopOpeBRepDS_HDataStructure(py::module &mod){

py::class_<TopOpeBRepDS_HDataStructure, opencascade::handle<TopOpeBRepDS_HDataStructure>, Standard_Transient> cls_TopOpeBRepDS_HDataStructure(mod, "TopOpeBRepDS_HDataStructure", "None");

// Constructors
cls_TopOpeBRepDS_HDataStructure.def(py::init<>());

// Fields

// Methods
cls_TopOpeBRepDS_HDataStructure.def("AddAncestors", (void (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &)) &TopOpeBRepDS_HDataStructure::AddAncestors, "None", py::arg("S"));
cls_TopOpeBRepDS_HDataStructure.def("AddAncestors", (void (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const TopAbs_ShapeEnum)) &TopOpeBRepDS_HDataStructure::AddAncestors, "Update the data structure with shapes of type T1 containing a subshape of type T2 which is stored in the DS. Used by the previous one.", py::arg("S"), py::arg("T1"), py::arg("T2"));
cls_TopOpeBRepDS_HDataStructure.def("ChkIntg", (void (TopOpeBRepDS_HDataStructure::*)()) &TopOpeBRepDS_HDataStructure::ChkIntg, "Check the integrity of the DS");
cls_TopOpeBRepDS_HDataStructure.def("DS", (const TopOpeBRepDS_DataStructure & (TopOpeBRepDS_HDataStructure::*)() const) &TopOpeBRepDS_HDataStructure::DS, "None");
cls_TopOpeBRepDS_HDataStructure.def("ChangeDS", (TopOpeBRepDS_DataStructure & (TopOpeBRepDS_HDataStructure::*)()) &TopOpeBRepDS_HDataStructure::ChangeDS, "None");
cls_TopOpeBRepDS_HDataStructure.def("NbSurfaces", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)() const) &TopOpeBRepDS_HDataStructure::NbSurfaces, "None");
cls_TopOpeBRepDS_HDataStructure.def("NbCurves", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)() const) &TopOpeBRepDS_HDataStructure::NbCurves, "None");
cls_TopOpeBRepDS_HDataStructure.def("NbPoints", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)() const) &TopOpeBRepDS_HDataStructure::NbPoints, "None");
cls_TopOpeBRepDS_HDataStructure.def("Surface", (const TopOpeBRepDS_Surface & (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_HDataStructure::Surface, "Returns the surface of index <I>.", py::arg("I"));
cls_TopOpeBRepDS_HDataStructure.def("SurfaceCurves", (TopOpeBRepDS_CurveIterator (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_HDataStructure::SurfaceCurves, "Returns an iterator on the curves on the surface <I>.", py::arg("I"));
cls_TopOpeBRepDS_HDataStructure.def("Curve", (const TopOpeBRepDS_Curve & (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_HDataStructure::Curve, "Returns the Curve of index <I>.", py::arg("I"));
cls_TopOpeBRepDS_HDataStructure.def("ChangeCurve", (TopOpeBRepDS_Curve & (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_HDataStructure::ChangeCurve, "Returns the Curve of index <I>.", py::arg("I"));
cls_TopOpeBRepDS_HDataStructure.def("CurvePoints", (TopOpeBRepDS_PointIterator (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_HDataStructure::CurvePoints, "Returns an iterator on the points on the curve <I>.", py::arg("I"));
cls_TopOpeBRepDS_HDataStructure.def("Point", (const TopOpeBRepDS_Point & (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_HDataStructure::Point, "Returns the point of index <I>.", py::arg("I"));
cls_TopOpeBRepDS_HDataStructure.def("NbShapes", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)() const) &TopOpeBRepDS_HDataStructure::NbShapes, "None");
cls_TopOpeBRepDS_HDataStructure.def("Shape", [](TopOpeBRepDS_HDataStructure &self, const Standard_Integer a0) -> const TopoDS_Shape & { return self.Shape(a0); });
cls_TopOpeBRepDS_HDataStructure.def("Shape", (const TopoDS_Shape & (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer, const Standard_Boolean) const) &TopOpeBRepDS_HDataStructure::Shape, "Returns the shape of index <I> in the DS", py::arg("I"), py::arg("FindKeep"));
cls_TopOpeBRepDS_HDataStructure.def("Shape", [](TopOpeBRepDS_HDataStructure &self, const TopoDS_Shape & a0) -> Standard_Integer { return self.Shape(a0); });
cls_TopOpeBRepDS_HDataStructure.def("Shape", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &, const Standard_Boolean) const) &TopOpeBRepDS_HDataStructure::Shape, "Returns the index of shape <S> in the DS returns 0 if <S> is not in the DS", py::arg("S"), py::arg("FindKeep"));
cls_TopOpeBRepDS_HDataStructure.def("HasGeometry", (Standard_Boolean (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_HDataStructure::HasGeometry, "Returns True if <S> has new geometries.", py::arg("S"));
cls_TopOpeBRepDS_HDataStructure.def("HasShape", [](TopOpeBRepDS_HDataStructure &self, const TopoDS_Shape & a0) -> Standard_Boolean { return self.HasShape(a0); });
cls_TopOpeBRepDS_HDataStructure.def("HasShape", (Standard_Boolean (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &, const Standard_Boolean) const) &TopOpeBRepDS_HDataStructure::HasShape, "Returns True if <S> has new geometries (SOLID,FACE,EDGE) or if <S> (SHELL,WIRE) has sub-shape (FACE,EDGE) with new geometries", py::arg("S"), py::arg("FindKeep"));
cls_TopOpeBRepDS_HDataStructure.def("HasSameDomain", [](TopOpeBRepDS_HDataStructure &self, const TopoDS_Shape & a0) -> Standard_Boolean { return self.HasSameDomain(a0); });
cls_TopOpeBRepDS_HDataStructure.def("HasSameDomain", (Standard_Boolean (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &, const Standard_Boolean) const) &TopOpeBRepDS_HDataStructure::HasSameDomain, "Returns True if <S> share a geometrical domain with some other shapes.", py::arg("S"), py::arg("FindKeep"));
cls_TopOpeBRepDS_HDataStructure.def("SameDomain", (TopTools_ListIteratorOfListOfShape (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_HDataStructure::SameDomain, "Returns an iterator on the SameDomain shapes attached to the shape <S>.", py::arg("S"));
cls_TopOpeBRepDS_HDataStructure.def("SameDomainOrientation", (TopOpeBRepDS_Config (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_HDataStructure::SameDomainOrientation, "Returns orientation of shape <S> compared with its reference shape", py::arg("S"));
cls_TopOpeBRepDS_HDataStructure.def("SameDomainReference", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_HDataStructure::SameDomainReference, "Returns orientation of shape <S> compared with its reference shape", py::arg("S"));
cls_TopOpeBRepDS_HDataStructure.def("SolidSurfaces", (TopOpeBRepDS_SurfaceIterator (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_HDataStructure::SolidSurfaces, "Returns an iterator on the surfaces attached to the solid <S>.", py::arg("S"));
cls_TopOpeBRepDS_HDataStructure.def("SolidSurfaces", (TopOpeBRepDS_SurfaceIterator (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_HDataStructure::SolidSurfaces, "Returns an iterator on the surfaces attached to the solid <I>.", py::arg("I"));
cls_TopOpeBRepDS_HDataStructure.def("FaceCurves", (TopOpeBRepDS_CurveIterator (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_HDataStructure::FaceCurves, "Returns an iterator on the curves attached to the face <F>.", py::arg("F"));
cls_TopOpeBRepDS_HDataStructure.def("FaceCurves", (TopOpeBRepDS_CurveIterator (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer) const) &TopOpeBRepDS_HDataStructure::FaceCurves, "Returns an iterator on the curves attached to the face <I>.", py::arg("I"));
cls_TopOpeBRepDS_HDataStructure.def("EdgePoints", (TopOpeBRepDS_PointIterator (TopOpeBRepDS_HDataStructure::*)(const TopoDS_Shape &) const) &TopOpeBRepDS_HDataStructure::EdgePoints, "Returns an iterator on the points attached to the edge <E>.", py::arg("E"));
cls_TopOpeBRepDS_HDataStructure.def("MakeCurve", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)(const TopOpeBRepDS_Curve &, TopOpeBRepDS_Curve &)) &TopOpeBRepDS_HDataStructure::MakeCurve, "None", py::arg("C1"), py::arg("C2"));
cls_TopOpeBRepDS_HDataStructure.def("RemoveCurve", (void (TopOpeBRepDS_HDataStructure::*)(const Standard_Integer)) &TopOpeBRepDS_HDataStructure::RemoveCurve, "None", py::arg("iC"));
cls_TopOpeBRepDS_HDataStructure.def("NbGeometry", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)(const TopOpeBRepDS_Kind) const) &TopOpeBRepDS_HDataStructure::NbGeometry, "None", py::arg("K"));
cls_TopOpeBRepDS_HDataStructure.def("NbTopology", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)(const TopOpeBRepDS_Kind) const) &TopOpeBRepDS_HDataStructure::NbTopology, "None", py::arg("K"));
cls_TopOpeBRepDS_HDataStructure.def("NbTopology", (Standard_Integer (TopOpeBRepDS_HDataStructure::*)() const) &TopOpeBRepDS_HDataStructure::NbTopology, "None");
cls_TopOpeBRepDS_HDataStructure.def("EdgesSameParameter", (Standard_Boolean (TopOpeBRepDS_HDataStructure::*)() const) &TopOpeBRepDS_HDataStructure::EdgesSameParameter, "returns True if all the edges stored as shapes in the DS are SameParameter, otherwise False.");
cls_TopOpeBRepDS_HDataStructure.def("SortOnParameter", (void (TopOpeBRepDS_HDataStructure::*)(const TopOpeBRepDS_ListOfInterference &, TopOpeBRepDS_ListOfInterference &) const) &TopOpeBRepDS_HDataStructure::SortOnParameter, "None", py::arg("L1"), py::arg("L2"));
cls_TopOpeBRepDS_HDataStructure.def("SortOnParameter", (void (TopOpeBRepDS_HDataStructure::*)(TopOpeBRepDS_ListOfInterference &) const) &TopOpeBRepDS_HDataStructure::SortOnParameter, "None", py::arg("L"));
cls_TopOpeBRepDS_HDataStructure.def("MinMaxOnParameter", [](TopOpeBRepDS_HDataStructure &self, const TopOpeBRepDS_ListOfInterference & L, Standard_Real & Min, Standard_Real & Max){ self.MinMaxOnParameter(L, Min, Max); return std::tuple<Standard_Real &, Standard_Real &>(Min, Max); }, "None", py::arg("L"), py::arg("Min"), py::arg("Max"));
cls_TopOpeBRepDS_HDataStructure.def("ScanInterfList", (Standard_Boolean (TopOpeBRepDS_HDataStructure::*)(TopOpeBRepDS_ListIteratorOfListOfInterference &, const TopOpeBRepDS_Point &) const) &TopOpeBRepDS_HDataStructure::ScanInterfList, "Search, among a list of interferences accessed by the iterator <IT>, a geometry <G> whose 3D point is identical to the 3D point of the TheDSPoint <PDS>. returns True if such an interference has been found, False else. if True, iterator It points (by the Value() method) on the first interference accessing an identical 3D point.", py::arg("IT"), py::arg("PDS"));
cls_TopOpeBRepDS_HDataStructure.def("GetGeometry", [](TopOpeBRepDS_HDataStructure &self, TopOpeBRepDS_ListIteratorOfListOfInterference & IT, const TopOpeBRepDS_Point & PDS, Standard_Integer & G, TopOpeBRepDS_Kind & K){ Standard_Boolean rv = self.GetGeometry(IT, PDS, G, K); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, G); }, "Get the geometry of a DS point <PDS>. Search for it with ScanInterfList (previous method). if found, set <G,K> to the geometry,kind of the interference found. returns the value of ScanInterfList().", py::arg("IT"), py::arg("PDS"), py::arg("G"), py::arg("K"));
cls_TopOpeBRepDS_HDataStructure.def("StoreInterference", [](TopOpeBRepDS_HDataStructure &self, const opencascade::handle<TopOpeBRepDS_Interference> & a0, TopOpeBRepDS_ListOfInterference & a1) -> void { return self.StoreInterference(a0, a1); });
cls_TopOpeBRepDS_HDataStructure.def("StoreInterference", (void (TopOpeBRepDS_HDataStructure::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, TopOpeBRepDS_ListOfInterference &, const TCollection_AsciiString &)) &TopOpeBRepDS_HDataStructure::StoreInterference, "Add interference <I> to list <LI>.", py::arg("I"), py::arg("LI"), py::arg("str"));
cls_TopOpeBRepDS_HDataStructure.def("StoreInterference", [](TopOpeBRepDS_HDataStructure &self, const opencascade::handle<TopOpeBRepDS_Interference> & a0, const TopoDS_Shape & a1) -> void { return self.StoreInterference(a0, a1); });
cls_TopOpeBRepDS_HDataStructure.def("StoreInterference", (void (TopOpeBRepDS_HDataStructure::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const TopoDS_Shape &, const TCollection_AsciiString &)) &TopOpeBRepDS_HDataStructure::StoreInterference, "Add interference <I> to list of interference of shape <S>.", py::arg("I"), py::arg("S"), py::arg("str"));
cls_TopOpeBRepDS_HDataStructure.def("StoreInterference", [](TopOpeBRepDS_HDataStructure &self, const opencascade::handle<TopOpeBRepDS_Interference> & a0, const Standard_Integer a1) -> void { return self.StoreInterference(a0, a1); });
cls_TopOpeBRepDS_HDataStructure.def("StoreInterference", (void (TopOpeBRepDS_HDataStructure::*)(const opencascade::handle<TopOpeBRepDS_Interference> &, const Standard_Integer, const TCollection_AsciiString &)) &TopOpeBRepDS_HDataStructure::StoreInterference, "Add interference <I> to list of interference of shape <IS>.", py::arg("I"), py::arg("IS"), py::arg("str"));
cls_TopOpeBRepDS_HDataStructure.def("StoreInterferences", [](TopOpeBRepDS_HDataStructure &self, const TopOpeBRepDS_ListOfInterference & a0, const TopoDS_Shape & a1) -> void { return self.StoreInterferences(a0, a1); });
cls_TopOpeBRepDS_HDataStructure.def("StoreInterferences", (void (TopOpeBRepDS_HDataStructure::*)(const TopOpeBRepDS_ListOfInterference &, const TopoDS_Shape &, const TCollection_AsciiString &)) &TopOpeBRepDS_HDataStructure::StoreInterferences, "None", py::arg("LI"), py::arg("S"), py::arg("str"));
cls_TopOpeBRepDS_HDataStructure.def("StoreInterferences", [](TopOpeBRepDS_HDataStructure &self, const TopOpeBRepDS_ListOfInterference & a0, const Standard_Integer a1) -> void { return self.StoreInterferences(a0, a1); });
cls_TopOpeBRepDS_HDataStructure.def("StoreInterferences", (void (TopOpeBRepDS_HDataStructure::*)(const TopOpeBRepDS_ListOfInterference &, const Standard_Integer, const TCollection_AsciiString &)) &TopOpeBRepDS_HDataStructure::StoreInterferences, "None", py::arg("LI"), py::arg("IS"), py::arg("str"));
cls_TopOpeBRepDS_HDataStructure.def("ClearStoreInterferences", [](TopOpeBRepDS_HDataStructure &self, const TopOpeBRepDS_ListOfInterference & a0, const TopoDS_Shape & a1) -> void { return self.ClearStoreInterferences(a0, a1); });
cls_TopOpeBRepDS_HDataStructure.def("ClearStoreInterferences", (void (TopOpeBRepDS_HDataStructure::*)(const TopOpeBRepDS_ListOfInterference &, const TopoDS_Shape &, const TCollection_AsciiString &)) &TopOpeBRepDS_HDataStructure::ClearStoreInterferences, "None", py::arg("LI"), py::arg("S"), py::arg("str"));
cls_TopOpeBRepDS_HDataStructure.def("ClearStoreInterferences", [](TopOpeBRepDS_HDataStructure &self, const TopOpeBRepDS_ListOfInterference & a0, const Standard_Integer a1) -> void { return self.ClearStoreInterferences(a0, a1); });
cls_TopOpeBRepDS_HDataStructure.def("ClearStoreInterferences", (void (TopOpeBRepDS_HDataStructure::*)(const TopOpeBRepDS_ListOfInterference &, const Standard_Integer, const TCollection_AsciiString &)) &TopOpeBRepDS_HDataStructure::ClearStoreInterferences, "None", py::arg("LI"), py::arg("IS"), py::arg("str"));
cls_TopOpeBRepDS_HDataStructure.def_static("get_type_name_", (const char * (*)()) &TopOpeBRepDS_HDataStructure::get_type_name, "None");
cls_TopOpeBRepDS_HDataStructure.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TopOpeBRepDS_HDataStructure::get_type_descriptor, "None");
cls_TopOpeBRepDS_HDataStructure.def("DynamicType", (const opencascade::handle<Standard_Type> & (TopOpeBRepDS_HDataStructure::*)() const) &TopOpeBRepDS_HDataStructure::DynamicType, "None");

// Enums

}