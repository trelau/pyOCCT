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
#include <gp_XYZ.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESSolid_VertexList.hxx>
#include <IGESData_IGESEntity.hxx>
#include <IGESSolid_EdgeList.hxx>
#include <IGESSolid_Shell.hxx>
#include <IGESSolid_ManifoldSolid.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <TColStd_HSequenceOfInteger.hxx>
#include <IGESSolid_Face.hxx>
#include <IGESSolid_Loop.hxx>
#include <TColgp_HSequenceOfXYZ.hxx>
#include <IGESSolid_TopoBuilder.hxx>

void bind_IGESSolid_TopoBuilder(py::module &mod){

py::class_<IGESSolid_TopoBuilder, std::unique_ptr<IGESSolid_TopoBuilder, Deleter<IGESSolid_TopoBuilder>>> cls_IGESSolid_TopoBuilder(mod, "IGESSolid_TopoBuilder", "This class manages the creation of an IGES Topologic entity (BREP : ManifoldSolid, Shell, Face) This includes definiting of Vertex and Edge Lists, building of Edges and Loops");

// Constructors
cls_IGESSolid_TopoBuilder.def(py::init<>());

// Fields

// Methods
// cls_IGESSolid_TopoBuilder.def_static("operator new_", (void * (*)(size_t)) &IGESSolid_TopoBuilder::operator new, "None", py::arg("theSize"));
// cls_IGESSolid_TopoBuilder.def_static("operator delete_", (void (*)(void *)) &IGESSolid_TopoBuilder::operator delete, "None", py::arg("theAddress"));
// cls_IGESSolid_TopoBuilder.def_static("operator new[]_", (void * (*)(size_t)) &IGESSolid_TopoBuilder::operator new[], "None", py::arg("theSize"));
// cls_IGESSolid_TopoBuilder.def_static("operator delete[]_", (void (*)(void *)) &IGESSolid_TopoBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_IGESSolid_TopoBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &IGESSolid_TopoBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESSolid_TopoBuilder.def_static("operator delete_", (void (*)(void *, void *)) &IGESSolid_TopoBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESSolid_TopoBuilder.def("Clear", (void (IGESSolid_TopoBuilder::*)()) &IGESSolid_TopoBuilder::Clear, "Resets the TopoBuilder for an entirely new operation (with a new EdgeList, a new VertexList, new Shells, ...)");
cls_IGESSolid_TopoBuilder.def("AddVertex", (void (IGESSolid_TopoBuilder::*)(const gp_XYZ &)) &IGESSolid_TopoBuilder::AddVertex, "Adds a Vertex to the VertexList", py::arg("val"));
cls_IGESSolid_TopoBuilder.def("NbVertices", (Standard_Integer (IGESSolid_TopoBuilder::*)() const) &IGESSolid_TopoBuilder::NbVertices, "Returns the count of already recorded Vertices");
cls_IGESSolid_TopoBuilder.def("Vertex", (const gp_XYZ & (IGESSolid_TopoBuilder::*)(const Standard_Integer) const) &IGESSolid_TopoBuilder::Vertex, "Returns a Vertex, given its rank", py::arg("num"));
cls_IGESSolid_TopoBuilder.def("VertexList", (opencascade::handle<IGESSolid_VertexList> (IGESSolid_TopoBuilder::*)() const) &IGESSolid_TopoBuilder::VertexList, "Returns the VertexList. It can be referenced, but it remains empty until call to EndShell or EndSolid");
cls_IGESSolid_TopoBuilder.def("AddEdge", (void (IGESSolid_TopoBuilder::*)(const opencascade::handle<IGESData_IGESEntity> &, const Standard_Integer, const Standard_Integer)) &IGESSolid_TopoBuilder::AddEdge, "Adds an Edge (3D) to the EdgeList, defined by a Curve and two number of Vertex, for start and end", py::arg("curve"), py::arg("vstart"), py::arg("vend"));
cls_IGESSolid_TopoBuilder.def("NbEdges", (Standard_Integer (IGESSolid_TopoBuilder::*)() const) &IGESSolid_TopoBuilder::NbEdges, "Returns the count of recorded Edges (3D)");
cls_IGESSolid_TopoBuilder.def("Edge", [](IGESSolid_TopoBuilder &self, const Standard_Integer num, opencascade::handle<IGESData_IGESEntity> & curve, Standard_Integer & vstart, Standard_Integer & vend){ self.Edge(num, curve, vstart, vend); return std::tuple<Standard_Integer &, Standard_Integer &>(vstart, vend); }, "Returns the definition of an Edge (3D) given its rank", py::arg("num"), py::arg("curve"), py::arg("vstart"), py::arg("vend"));
cls_IGESSolid_TopoBuilder.def("EdgeList", (opencascade::handle<IGESSolid_EdgeList> (IGESSolid_TopoBuilder::*)() const) &IGESSolid_TopoBuilder::EdgeList, "Returns the EdgeList. It can be referenced, but it remains empty until call to EndShell or EndSolid");
cls_IGESSolid_TopoBuilder.def("MakeLoop", (void (IGESSolid_TopoBuilder::*)()) &IGESSolid_TopoBuilder::MakeLoop, "Begins the definition of a new Loop : it is the Current Loop All Edges (UV) defined by MakeEdge/EndEdge will be added in it The Loop can then be referenced but is empty. It will be filled with its Edges(UV) by EndLoop (from SetOuter/AddInner)");
cls_IGESSolid_TopoBuilder.def("MakeEdge", (void (IGESSolid_TopoBuilder::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &IGESSolid_TopoBuilder::MakeEdge, "Defines an Edge(UV), to be added in the current Loop by EndEdge <edgetype> gives the type of the edge <edge3d> identifies the Edge(3D) used as support The EdgeList is allways the current one <orientation gives the orientation flag It is then necessary to : - give the parametric curves - close the definition of this edge(UV) by EndEdge, else the next call to MakeEdge will erase this one", py::arg("edgetype"), py::arg("edge3d"), py::arg("orientation"));
cls_IGESSolid_TopoBuilder.def("AddCurveUV", (void (IGESSolid_TopoBuilder::*)(const opencascade::handle<IGESData_IGESEntity> &, const Standard_Integer)) &IGESSolid_TopoBuilder::AddCurveUV, "Adds a Parametric Curve (UV) to the current Edge(UV)", py::arg("curve"), py::arg("iso"));
cls_IGESSolid_TopoBuilder.def("EndEdge", (void (IGESSolid_TopoBuilder::*)()) &IGESSolid_TopoBuilder::EndEdge, "Closes the definition of an Edge(UV) and adds it to the current Loop");
cls_IGESSolid_TopoBuilder.def("MakeFace", (void (IGESSolid_TopoBuilder::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESSolid_TopoBuilder::MakeFace, "Begins the definition of a new Face, on a surface All Loops defined by MakeLoop will be added in it, according the closing call : SetOuter for the Outer Loop (by default, if SetOuter is not called, no OuterLoop is defined); AddInner for the list of Inner Loops (there can be none)", py::arg("surface"));
cls_IGESSolid_TopoBuilder.def("SetOuter", (void (IGESSolid_TopoBuilder::*)()) &IGESSolid_TopoBuilder::SetOuter, "Closes the current Loop and sets it Loop as Outer Loop. If no current Loop has yet been defined, does nothing.");
cls_IGESSolid_TopoBuilder.def("AddInner", (void (IGESSolid_TopoBuilder::*)()) &IGESSolid_TopoBuilder::AddInner, "Closes the current Loop and adds it to the list of Inner Loops for the current Face");
cls_IGESSolid_TopoBuilder.def("EndFace", (void (IGESSolid_TopoBuilder::*)(const Standard_Integer)) &IGESSolid_TopoBuilder::EndFace, "Closes the definition of the current Face, fills it and adds it to the current Shell with an orientation flag (0/1)", py::arg("orientation"));
cls_IGESSolid_TopoBuilder.def("MakeShell", (void (IGESSolid_TopoBuilder::*)()) &IGESSolid_TopoBuilder::MakeShell, "Begins the definition of a new Shell (either Simple or in a Solid)");
cls_IGESSolid_TopoBuilder.def("EndSimpleShell", (void (IGESSolid_TopoBuilder::*)()) &IGESSolid_TopoBuilder::EndSimpleShell, "Closes the whole definition as that of a simple Shell");
cls_IGESSolid_TopoBuilder.def("SetMainShell", (void (IGESSolid_TopoBuilder::*)(const Standard_Integer)) &IGESSolid_TopoBuilder::SetMainShell, "Closes the definition of the current Shell as for the Main Shell of a Solid, with an orientation flag (0/1)", py::arg("orientation"));
cls_IGESSolid_TopoBuilder.def("AddVoidShell", (void (IGESSolid_TopoBuilder::*)(const Standard_Integer)) &IGESSolid_TopoBuilder::AddVoidShell, "Closes the definition of the current Shell and adds it to the list of Void Shells of a Solid, with an orientation flag (0/1)", py::arg("orientation"));
cls_IGESSolid_TopoBuilder.def("EndSolid", (void (IGESSolid_TopoBuilder::*)()) &IGESSolid_TopoBuilder::EndSolid, "Closes the whole definition as that of a ManifoldSolid Its call is exclusive from that of EndSimpleShell");
cls_IGESSolid_TopoBuilder.def("Shell", (opencascade::handle<IGESSolid_Shell> (IGESSolid_TopoBuilder::*)() const) &IGESSolid_TopoBuilder::Shell, "Returns the current Shell. The current Shell is created empty by MakeShell and filled by EndShell");
cls_IGESSolid_TopoBuilder.def("Solid", (opencascade::handle<IGESSolid_ManifoldSolid> (IGESSolid_TopoBuilder::*)() const) &IGESSolid_TopoBuilder::Solid, "Returns the current ManifoldSolid. It is created empty by Create and filled by EndSolid");

// Enums

}