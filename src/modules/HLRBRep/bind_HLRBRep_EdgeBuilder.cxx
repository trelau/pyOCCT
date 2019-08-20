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
#include <HLRBRep_VertexList.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_State.hxx>
#include <Standard_Handle.hxx>
#include <HLRBRep_AreaLimit.hxx>
#include <HLRAlgo_Intersection.hxx>
#include <TopAbs_Orientation.hxx>
#include <HLRBRep_EdgeBuilder.hxx>

void bind_HLRBRep_EdgeBuilder(py::module &mod){

py::class_<HLRBRep_EdgeBuilder, std::unique_ptr<HLRBRep_EdgeBuilder>> cls_HLRBRep_EdgeBuilder(mod, "HLRBRep_EdgeBuilder", "None");

// Constructors
cls_HLRBRep_EdgeBuilder.def(py::init<HLRBRep_VertexList &>(), py::arg("VList"));

// Fields

// Methods
// cls_HLRBRep_EdgeBuilder.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_EdgeBuilder::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_EdgeBuilder.def_static("operator delete_", (void (*)(void *)) &HLRBRep_EdgeBuilder::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_EdgeBuilder.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_EdgeBuilder::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_EdgeBuilder.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_EdgeBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_EdgeBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_EdgeBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_EdgeBuilder.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_EdgeBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_EdgeBuilder.def("InitAreas", (void (HLRBRep_EdgeBuilder::*)()) &HLRBRep_EdgeBuilder::InitAreas, "Initialize an iteration on the areas.");
cls_HLRBRep_EdgeBuilder.def("NextArea", (void (HLRBRep_EdgeBuilder::*)()) &HLRBRep_EdgeBuilder::NextArea, "Set the current area to the next area.");
cls_HLRBRep_EdgeBuilder.def("PreviousArea", (void (HLRBRep_EdgeBuilder::*)()) &HLRBRep_EdgeBuilder::PreviousArea, "Set the current area to the previous area.");
cls_HLRBRep_EdgeBuilder.def("HasArea", (Standard_Boolean (HLRBRep_EdgeBuilder::*)() const) &HLRBRep_EdgeBuilder::HasArea, "Returns True if there is a current area.");
cls_HLRBRep_EdgeBuilder.def("AreaState", (TopAbs_State (HLRBRep_EdgeBuilder::*)() const) &HLRBRep_EdgeBuilder::AreaState, "Returns the state of the current area.");
cls_HLRBRep_EdgeBuilder.def("AreaEdgeState", (TopAbs_State (HLRBRep_EdgeBuilder::*)() const) &HLRBRep_EdgeBuilder::AreaEdgeState, "Returns the edge state of the current area.");
cls_HLRBRep_EdgeBuilder.def("LeftLimit", (opencascade::handle<HLRBRep_AreaLimit> (HLRBRep_EdgeBuilder::*)() const) &HLRBRep_EdgeBuilder::LeftLimit, "Returns the AreaLimit beginning the current area. This is a NULL handle when the area is infinite on the left.");
cls_HLRBRep_EdgeBuilder.def("RightLimit", (opencascade::handle<HLRBRep_AreaLimit> (HLRBRep_EdgeBuilder::*)() const) &HLRBRep_EdgeBuilder::RightLimit, "Returns the AreaLimit ending the current area. This is a NULL handle when the area is infinite on the right.");
cls_HLRBRep_EdgeBuilder.def("Builds", (void (HLRBRep_EdgeBuilder::*)(const TopAbs_State)) &HLRBRep_EdgeBuilder::Builds, "Reinitialize the results iteration to the parts with State <ToBuild>. If this method is not called after construction the default is <ToBuild> = IN.", py::arg("ToBuild"));
cls_HLRBRep_EdgeBuilder.def("MoreEdges", (Standard_Boolean (HLRBRep_EdgeBuilder::*)() const) &HLRBRep_EdgeBuilder::MoreEdges, "Returns True if there are more new edges to build.");
cls_HLRBRep_EdgeBuilder.def("NextEdge", (void (HLRBRep_EdgeBuilder::*)()) &HLRBRep_EdgeBuilder::NextEdge, "Proceeds to the next edge to build. Skip all remaining vertices on the current edge.");
cls_HLRBRep_EdgeBuilder.def("MoreVertices", (Standard_Boolean (HLRBRep_EdgeBuilder::*)() const) &HLRBRep_EdgeBuilder::MoreVertices, "True if there are more vertices in the current new edge.");
cls_HLRBRep_EdgeBuilder.def("NextVertex", (void (HLRBRep_EdgeBuilder::*)()) &HLRBRep_EdgeBuilder::NextVertex, "Proceeds to the next vertex of the current edge.");
cls_HLRBRep_EdgeBuilder.def("Current", (const HLRAlgo_Intersection & (HLRBRep_EdgeBuilder::*)() const) &HLRBRep_EdgeBuilder::Current, "Returns the current vertex of the current edge.");
cls_HLRBRep_EdgeBuilder.def("IsBoundary", (Standard_Boolean (HLRBRep_EdgeBuilder::*)() const) &HLRBRep_EdgeBuilder::IsBoundary, "Returns True if the current vertex comes from the boundary of the edge.");
cls_HLRBRep_EdgeBuilder.def("IsInterference", (Standard_Boolean (HLRBRep_EdgeBuilder::*)() const) &HLRBRep_EdgeBuilder::IsInterference, "Returns True if the current vertex was an interference.");
cls_HLRBRep_EdgeBuilder.def("Orientation", (TopAbs_Orientation (HLRBRep_EdgeBuilder::*)() const) &HLRBRep_EdgeBuilder::Orientation, "Returns the new orientation of the current vertex.");
cls_HLRBRep_EdgeBuilder.def("Destroy", (void (HLRBRep_EdgeBuilder::*)()) &HLRBRep_EdgeBuilder::Destroy, "None");

// Enums

}