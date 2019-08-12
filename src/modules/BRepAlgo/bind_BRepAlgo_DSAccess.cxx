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
#include <TopTools_ListOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopAbs_State.hxx>
#include <BRepAlgo_CheckStatus.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_HDataStructure.hxx>
#include <TopOpeBRepBuild_HBuilder.hxx>
#include <BRepAlgo_BooleanOperations.hxx>
#include <TopOpeBRepDS_Kind.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <TopOpeBRep_DSFiller.hxx>
#include <BRepAlgo_EdgeConnector.hxx>
#include <TopoDS_Wire.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TColStd_PackedMapOfInteger.hxx>
#include <BRepAlgo_DSAccess.hxx>

void bind_BRepAlgo_DSAccess(py::module &mod){

py::class_<BRepAlgo_DSAccess, std::unique_ptr<BRepAlgo_DSAccess, Deleter<BRepAlgo_DSAccess>>> cls_BRepAlgo_DSAccess(mod, "BRepAlgo_DSAccess", "None");

// Constructors
cls_BRepAlgo_DSAccess.def(py::init<>());

// Fields

// Methods
// cls_BRepAlgo_DSAccess.def_static("operator new_", (void * (*)(size_t)) &BRepAlgo_DSAccess::operator new, "None", py::arg("theSize"));
// cls_BRepAlgo_DSAccess.def_static("operator delete_", (void (*)(void *)) &BRepAlgo_DSAccess::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgo_DSAccess.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgo_DSAccess::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgo_DSAccess.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgo_DSAccess::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgo_DSAccess.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgo_DSAccess::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgo_DSAccess.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgo_DSAccess::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepAlgo_DSAccess.def("Init", (void (BRepAlgo_DSAccess::*)()) &BRepAlgo_DSAccess::Init, "Clears the internal data structure, including the");
cls_BRepAlgo_DSAccess.def("Load", (void (BRepAlgo_DSAccess::*)(const TopoDS_Shape &)) &BRepAlgo_DSAccess::Load, "Loads the shape in DS.", py::arg("S"));
cls_BRepAlgo_DSAccess.def("Load", (void (BRepAlgo_DSAccess::*)(TopoDS_Shape &, TopoDS_Shape &)) &BRepAlgo_DSAccess::Load, "Loads two shapes in the DS without intersecting them.", py::arg("S1"), py::arg("S2"));
cls_BRepAlgo_DSAccess.def("Intersect", (void (BRepAlgo_DSAccess::*)()) &BRepAlgo_DSAccess::Intersect, "Intersects two shapes at input and loads the DS with their intersection. Clears the TopOpeBRepBuild_HBuilder if necessary");
cls_BRepAlgo_DSAccess.def("Intersect", (void (BRepAlgo_DSAccess::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepAlgo_DSAccess::Intersect, "Intersects the faces contained in two given shapes and loads them in the DS. Clears the TopOpeBRepBuild_HBuilder if necessary", py::arg("S1"), py::arg("S2"));
cls_BRepAlgo_DSAccess.def("SameDomain", (void (BRepAlgo_DSAccess::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepAlgo_DSAccess::SameDomain, "This method does the same thing as the previous, but faster. There is no intersection face/face 3D. The faces have the same support(surface). No test of tangency (that is why it is faster). Intersects in 2d the faces tangent F1 anf F2.", py::arg("S1"), py::arg("S2"));
cls_BRepAlgo_DSAccess.def("GetSectionEdgeSet", (const TopTools_ListOfShape & (BRepAlgo_DSAccess::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepAlgo_DSAccess::GetSectionEdgeSet, "returns compounds of Edge connected with section, which contains sections between faces contained in S1 and S2. returns an empty list of Shape if S1 or S2 do not contain face. calls GetSectionEdgeSet() if it has not already been done", py::arg("S1"), py::arg("S2"));
cls_BRepAlgo_DSAccess.def("GetSectionEdgeSet", (const TopTools_ListOfShape & (BRepAlgo_DSAccess::*)()) &BRepAlgo_DSAccess::GetSectionEdgeSet, "returns all compounds of edges connected with section contained in the DS");
cls_BRepAlgo_DSAccess.def("IsWire", (Standard_Boolean (BRepAlgo_DSAccess::*)(const TopoDS_Shape &)) &BRepAlgo_DSAccess::IsWire, "NYI", py::arg("Compound"));
cls_BRepAlgo_DSAccess.def("Wire", (const TopoDS_Shape & (BRepAlgo_DSAccess::*)(const TopoDS_Shape &)) &BRepAlgo_DSAccess::Wire, "NYI", py::arg("Compound"));
cls_BRepAlgo_DSAccess.def("SectionVertex", (const TopTools_ListOfShape & (BRepAlgo_DSAccess::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepAlgo_DSAccess::SectionVertex, "NYI returns the vertex of section, which contains the section between face S1 and edge S2 (returns an empty Shape if S1 is not a face or if S2 is not an edge)", py::arg("S1"), py::arg("S2"));
cls_BRepAlgo_DSAccess.def("SuppressEdgeSet", (void (BRepAlgo_DSAccess::*)(const TopoDS_Shape &)) &BRepAlgo_DSAccess::SuppressEdgeSet, "Invalidates a complete line of section. All Edges connected by Vertex or a Wire. Can be a group of connected Edges, which do not form a standard Wire.", py::arg("Compound"));
cls_BRepAlgo_DSAccess.def("ChangeEdgeSet", (void (BRepAlgo_DSAccess::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &BRepAlgo_DSAccess::ChangeEdgeSet, "Modifies a line of section. <New> -- should be a Group of Edges connected by Vertex. -- Can be a Wire. Can be a group of connected Edges that do not form a standard Wire. <New> should be sub-groupn of <Old>", py::arg("Old"), py::arg("New"));
cls_BRepAlgo_DSAccess.def("SuppressSectionVertex", (void (BRepAlgo_DSAccess::*)(const TopoDS_Vertex &)) &BRepAlgo_DSAccess::SuppressSectionVertex, "NYI Make invalid a Vertex of section. The Vertex shoud be reconstructed from a point.", py::arg("V"));
cls_BRepAlgo_DSAccess.def("Merge", (const TopoDS_Shape & (BRepAlgo_DSAccess::*)(const TopAbs_State, const TopAbs_State)) &BRepAlgo_DSAccess::Merge, "None", py::arg("state1"), py::arg("state2"));
cls_BRepAlgo_DSAccess.def("Merge", (const TopoDS_Shape & (BRepAlgo_DSAccess::*)(const TopAbs_State)) &BRepAlgo_DSAccess::Merge, "None", py::arg("state1"));
cls_BRepAlgo_DSAccess.def("Propagate", (const TopoDS_Shape & (BRepAlgo_DSAccess::*)(const TopAbs_State, const TopoDS_Shape &, const TopoDS_Shape &)) &BRepAlgo_DSAccess::Propagate, "NYI Propagation of a state starting from the shape FromShape = edge or vertex of section, face or Coumpound de section. LoadShape is either S1, or S2 (see the method Load). Propagation from FromShape, on the states <what> of LoadShape. Return a Wire in 2d, a Shell in 3d. Specifications are incomplete, to be redefined for the typologies correpsonding to <FromShape> and the result : exemple : FromShape resultat vertex wire (or edge) edge of section face (or shell) compound of section shell ... ...", py::arg("what"), py::arg("FromShape"), py::arg("LoadShape"));
cls_BRepAlgo_DSAccess.def("PropagateFromSection", (const TopoDS_Shape & (BRepAlgo_DSAccess::*)(const TopoDS_Shape &)) &BRepAlgo_DSAccess::PropagateFromSection, "SectionShape est soit un Vertex de section(NYI), soit une Edge de section. Propagation des shapes de section en partant de SectionShape. return un Compound de section.", py::arg("SectionShape"));
cls_BRepAlgo_DSAccess.def("Modified", (const TopTools_ListOfShape & (BRepAlgo_DSAccess::*)(const TopoDS_Shape &)) &BRepAlgo_DSAccess::Modified, "Returns the list of the descendant shapes of the shape <S>.", py::arg("S"));
// cls_BRepAlgo_DSAccess.def("IsDeleted", (Standard_Boolean (BRepAlgo_DSAccess::*)(const TopoDS_Shape &)) &BRepAlgo_DSAccess::IsDeleted, "Returns the fact that the shape <S> has been deleted or not by the boolean operation.", py::arg("S"));
cls_BRepAlgo_DSAccess.def("Check", (BRepAlgo_CheckStatus (BRepAlgo_DSAccess::*)()) &BRepAlgo_DSAccess::Check, "NYI coherence of the internal Data Structure.");
cls_BRepAlgo_DSAccess.def("DS", (const opencascade::handle<TopOpeBRepDS_HDataStructure> & (BRepAlgo_DSAccess::*)() const) &BRepAlgo_DSAccess::DS, "None");
cls_BRepAlgo_DSAccess.def("ChangeDS", (opencascade::handle<TopOpeBRepDS_HDataStructure> & (BRepAlgo_DSAccess::*)()) &BRepAlgo_DSAccess::ChangeDS, "None");
cls_BRepAlgo_DSAccess.def("Builder", (const opencascade::handle<TopOpeBRepBuild_HBuilder> & (BRepAlgo_DSAccess::*)() const) &BRepAlgo_DSAccess::Builder, "None");
cls_BRepAlgo_DSAccess.def("ChangeBuilder", (opencascade::handle<TopOpeBRepBuild_HBuilder> & (BRepAlgo_DSAccess::*)()) &BRepAlgo_DSAccess::ChangeBuilder, "None");

// Enums

}