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
#include <Bnd_Box.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRep_HArray1OfLineInter.hxx>
#include <TopOpeBRep_LineInter.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <IntPatch_Intersection.hxx>
#include <TopoDS_Face.hxx>
#include <BRepAdaptor_HSurface.hxx>
#include <GeomAbs_SurfaceType.hxx>
#include <BRepTopAdaptor_TopolTool.hxx>
#include <TopOpeBRep_FacesIntersector.hxx>

void bind_TopOpeBRep_FacesIntersector(py::module &mod){

py::class_<TopOpeBRep_FacesIntersector, std::unique_ptr<TopOpeBRep_FacesIntersector>> cls_TopOpeBRep_FacesIntersector(mod, "TopOpeBRep_FacesIntersector", "Describes the intersection of two faces.");

// Constructors
cls_TopOpeBRep_FacesIntersector.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRep_FacesIntersector.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRep_FacesIntersector::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRep_FacesIntersector.def_static("operator delete_", (void (*)(void *)) &TopOpeBRep_FacesIntersector::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRep_FacesIntersector.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRep_FacesIntersector::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRep_FacesIntersector.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRep_FacesIntersector::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRep_FacesIntersector.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRep_FacesIntersector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRep_FacesIntersector.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRep_FacesIntersector::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRep_FacesIntersector.def("Perform", (void (TopOpeBRep_FacesIntersector::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRep_FacesIntersector::Perform, "Computes the intersection of faces S1 and S2.", py::arg("S1"), py::arg("S2"));
cls_TopOpeBRep_FacesIntersector.def("Perform", (void (TopOpeBRep_FacesIntersector::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Bnd_Box &, const Bnd_Box &)) &TopOpeBRep_FacesIntersector::Perform, "Computes the intersection of faces S1 and S2.", py::arg("S1"), py::arg("S2"), py::arg("B1"), py::arg("B2"));
cls_TopOpeBRep_FacesIntersector.def("IsEmpty", (Standard_Boolean (TopOpeBRep_FacesIntersector::*)()) &TopOpeBRep_FacesIntersector::IsEmpty, "None");
cls_TopOpeBRep_FacesIntersector.def("IsDone", (Standard_Boolean (TopOpeBRep_FacesIntersector::*)() const) &TopOpeBRep_FacesIntersector::IsDone, "None");
cls_TopOpeBRep_FacesIntersector.def("SameDomain", (Standard_Boolean (TopOpeBRep_FacesIntersector::*)() const) &TopOpeBRep_FacesIntersector::SameDomain, "Returns True if Perform() arguments are two faces with the same surface.");
cls_TopOpeBRep_FacesIntersector.def("Face", (const TopoDS_Shape & (TopOpeBRep_FacesIntersector::*)(const Standard_Integer) const) &TopOpeBRep_FacesIntersector::Face, "returns first or second intersected face.", py::arg("Index"));
cls_TopOpeBRep_FacesIntersector.def("SurfacesSameOriented", (Standard_Boolean (TopOpeBRep_FacesIntersector::*)() const) &TopOpeBRep_FacesIntersector::SurfacesSameOriented, "Returns True if Perform() arguments are two faces SameDomain() and normals on both side. Raise if SameDomain is False");
cls_TopOpeBRep_FacesIntersector.def("IsRestriction", (Standard_Boolean (TopOpeBRep_FacesIntersector::*)(const TopoDS_Shape &) const) &TopOpeBRep_FacesIntersector::IsRestriction, "returns true if edge <E> is found as same as the edge associated with a RESTRICTION line.", py::arg("E"));
cls_TopOpeBRep_FacesIntersector.def("Restrictions", (const TopTools_IndexedMapOfShape & (TopOpeBRep_FacesIntersector::*)() const) &TopOpeBRep_FacesIntersector::Restrictions, "returns the map of edges found as TopeBRepBRep_RESTRICTION");
cls_TopOpeBRep_FacesIntersector.def("PrepareLines", (void (TopOpeBRep_FacesIntersector::*)()) &TopOpeBRep_FacesIntersector::PrepareLines, "None");
cls_TopOpeBRep_FacesIntersector.def("Lines", (opencascade::handle<TopOpeBRep_HArray1OfLineInter> (TopOpeBRep_FacesIntersector::*)()) &TopOpeBRep_FacesIntersector::Lines, "None");
cls_TopOpeBRep_FacesIntersector.def("NbLines", (Standard_Integer (TopOpeBRep_FacesIntersector::*)() const) &TopOpeBRep_FacesIntersector::NbLines, "None");
cls_TopOpeBRep_FacesIntersector.def("InitLine", (void (TopOpeBRep_FacesIntersector::*)()) &TopOpeBRep_FacesIntersector::InitLine, "None");
cls_TopOpeBRep_FacesIntersector.def("MoreLine", (Standard_Boolean (TopOpeBRep_FacesIntersector::*)() const) &TopOpeBRep_FacesIntersector::MoreLine, "None");
cls_TopOpeBRep_FacesIntersector.def("NextLine", (void (TopOpeBRep_FacesIntersector::*)()) &TopOpeBRep_FacesIntersector::NextLine, "None");
cls_TopOpeBRep_FacesIntersector.def("CurrentLine", (TopOpeBRep_LineInter & (TopOpeBRep_FacesIntersector::*)()) &TopOpeBRep_FacesIntersector::CurrentLine, "None");
cls_TopOpeBRep_FacesIntersector.def("CurrentLineIndex", (Standard_Integer (TopOpeBRep_FacesIntersector::*)() const) &TopOpeBRep_FacesIntersector::CurrentLineIndex, "None");
cls_TopOpeBRep_FacesIntersector.def("ChangeLine", (TopOpeBRep_LineInter & (TopOpeBRep_FacesIntersector::*)(const Standard_Integer)) &TopOpeBRep_FacesIntersector::ChangeLine, "None", py::arg("IL"));
cls_TopOpeBRep_FacesIntersector.def("ForceTolerances", (void (TopOpeBRep_FacesIntersector::*)(const Standard_Real, const Standard_Real)) &TopOpeBRep_FacesIntersector::ForceTolerances, "Force the tolerance values used by the next Perform(S1,S2) call.", py::arg("tolarc"), py::arg("toltang"));
cls_TopOpeBRep_FacesIntersector.def("GetTolerances", [](TopOpeBRep_FacesIntersector &self, Standard_Real & tolarc, Standard_Real & toltang){ self.GetTolerances(tolarc, toltang); return std::tuple<Standard_Real &, Standard_Real &>(tolarc, toltang); }, "Return the tolerance values used in the last Perform() call If ForceTolerances() has been called, return the given values. If not, return values extracted from shapes.", py::arg("tolarc"), py::arg("toltang"));

// Enums

}