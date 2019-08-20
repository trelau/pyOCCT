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
#include <IntPatch_Point.hxx>
#include <Standard_TypeDef.hxx>
#include <IntSurf_Transition.hxx>
#include <gp_Pnt.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_State.hxx>
#include <gp_Pnt2d.hxx>
#include <TopOpeBRep_VPointInter.hxx>
#include <TopoDS_Edge.hxx>
#include <Standard_OStream.hxx>
#include <TopoDS_Face.hxx>
#include <TopOpeBRep_PThePointOfIntersection.hxx>

void bind_TopOpeBRep_VPointInter(py::module &mod){

py::class_<TopOpeBRep_VPointInter, std::unique_ptr<TopOpeBRep_VPointInter>> cls_TopOpeBRep_VPointInter(mod, "TopOpeBRep_VPointInter", "None");

// Constructors
cls_TopOpeBRep_VPointInter.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRep_VPointInter.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRep_VPointInter::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRep_VPointInter.def_static("operator delete_", (void (*)(void *)) &TopOpeBRep_VPointInter::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRep_VPointInter.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRep_VPointInter::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRep_VPointInter.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRep_VPointInter::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRep_VPointInter.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRep_VPointInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRep_VPointInter.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRep_VPointInter::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRep_VPointInter.def("SetPoint", (void (TopOpeBRep_VPointInter::*)(const IntPatch_Point &)) &TopOpeBRep_VPointInter::SetPoint, "None", py::arg("P"));
cls_TopOpeBRep_VPointInter.def("SetShapes", (void (TopOpeBRep_VPointInter::*)(const Standard_Integer, const Standard_Integer)) &TopOpeBRep_VPointInter::SetShapes, "None", py::arg("I1"), py::arg("I2"));
cls_TopOpeBRep_VPointInter.def("GetShapes", [](TopOpeBRep_VPointInter &self, Standard_Integer & I1, Standard_Integer & I2){ self.GetShapes(I1, I2); return std::tuple<Standard_Integer &, Standard_Integer &>(I1, I2); }, "None", py::arg("I1"), py::arg("I2"));
cls_TopOpeBRep_VPointInter.def("TransitionOnS1", (IntSurf_Transition (TopOpeBRep_VPointInter::*)() const) &TopOpeBRep_VPointInter::TransitionOnS1, "None");
cls_TopOpeBRep_VPointInter.def("TransitionOnS2", (IntSurf_Transition (TopOpeBRep_VPointInter::*)() const) &TopOpeBRep_VPointInter::TransitionOnS2, "None");
cls_TopOpeBRep_VPointInter.def("TransitionLineArc1", (IntSurf_Transition (TopOpeBRep_VPointInter::*)() const) &TopOpeBRep_VPointInter::TransitionLineArc1, "None");
cls_TopOpeBRep_VPointInter.def("TransitionLineArc2", (IntSurf_Transition (TopOpeBRep_VPointInter::*)() const) &TopOpeBRep_VPointInter::TransitionLineArc2, "None");
cls_TopOpeBRep_VPointInter.def("IsOnDomS1", (Standard_Boolean (TopOpeBRep_VPointInter::*)() const) &TopOpeBRep_VPointInter::IsOnDomS1, "None");
cls_TopOpeBRep_VPointInter.def("IsOnDomS2", (Standard_Boolean (TopOpeBRep_VPointInter::*)() const) &TopOpeBRep_VPointInter::IsOnDomS2, "None");
cls_TopOpeBRep_VPointInter.def("ParametersOnS1", [](TopOpeBRep_VPointInter &self, Standard_Real & u, Standard_Real & v){ self.ParametersOnS1(u, v); return std::tuple<Standard_Real &, Standard_Real &>(u, v); }, "None", py::arg("u"), py::arg("v"));
cls_TopOpeBRep_VPointInter.def("ParametersOnS2", [](TopOpeBRep_VPointInter &self, Standard_Real & u, Standard_Real & v){ self.ParametersOnS2(u, v); return std::tuple<Standard_Real &, Standard_Real &>(u, v); }, "None", py::arg("u"), py::arg("v"));
cls_TopOpeBRep_VPointInter.def("Value", (const gp_Pnt & (TopOpeBRep_VPointInter::*)() const) &TopOpeBRep_VPointInter::Value, "None");
cls_TopOpeBRep_VPointInter.def("Tolerance", (Standard_Real (TopOpeBRep_VPointInter::*)() const) &TopOpeBRep_VPointInter::Tolerance, "None");
cls_TopOpeBRep_VPointInter.def("ArcOnS1", (const TopoDS_Shape & (TopOpeBRep_VPointInter::*)() const) &TopOpeBRep_VPointInter::ArcOnS1, "None");
cls_TopOpeBRep_VPointInter.def("ArcOnS2", (const TopoDS_Shape & (TopOpeBRep_VPointInter::*)() const) &TopOpeBRep_VPointInter::ArcOnS2, "None");
cls_TopOpeBRep_VPointInter.def("ParameterOnLine", (Standard_Real (TopOpeBRep_VPointInter::*)() const) &TopOpeBRep_VPointInter::ParameterOnLine, "None");
cls_TopOpeBRep_VPointInter.def("ParameterOnArc1", (Standard_Real (TopOpeBRep_VPointInter::*)() const) &TopOpeBRep_VPointInter::ParameterOnArc1, "None");
cls_TopOpeBRep_VPointInter.def("IsVertexOnS1", (Standard_Boolean (TopOpeBRep_VPointInter::*)() const) &TopOpeBRep_VPointInter::IsVertexOnS1, "Returns TRUE if the point is a vertex on the initial restriction facet of the first surface.");
cls_TopOpeBRep_VPointInter.def("VertexOnS1", (const TopoDS_Shape & (TopOpeBRep_VPointInter::*)() const) &TopOpeBRep_VPointInter::VertexOnS1, "Returns the information about the point when it is on the domain of the first patch, i-e when the function IsVertexOnS1 returns True. Otherwise, an exception is raised.");
cls_TopOpeBRep_VPointInter.def("ParameterOnArc2", (Standard_Real (TopOpeBRep_VPointInter::*)() const) &TopOpeBRep_VPointInter::ParameterOnArc2, "None");
cls_TopOpeBRep_VPointInter.def("IsVertexOnS2", (Standard_Boolean (TopOpeBRep_VPointInter::*)() const) &TopOpeBRep_VPointInter::IsVertexOnS2, "Returns TRUE if the point is a vertex on the initial restriction facet of the second surface.");
cls_TopOpeBRep_VPointInter.def("VertexOnS2", (const TopoDS_Shape & (TopOpeBRep_VPointInter::*)() const) &TopOpeBRep_VPointInter::VertexOnS2, "Returns the information about the point when it is on the domain of the second patch, i-e when the function IsVertexOnS2 returns True. Otherwise, an exception is raised.");
cls_TopOpeBRep_VPointInter.def("IsInternal", (Standard_Boolean (TopOpeBRep_VPointInter::*)() const) &TopOpeBRep_VPointInter::IsInternal, "None");
cls_TopOpeBRep_VPointInter.def("IsMultiple", (Standard_Boolean (TopOpeBRep_VPointInter::*)() const) &TopOpeBRep_VPointInter::IsMultiple, "Returns True if the point belongs to several intersection lines.");
cls_TopOpeBRep_VPointInter.def("State", (TopAbs_State (TopOpeBRep_VPointInter::*)(const Standard_Integer) const) &TopOpeBRep_VPointInter::State, "get state of VPoint within the domain of geometric shape domain <I> (= 1 or 2).", py::arg("I"));
cls_TopOpeBRep_VPointInter.def("State", (void (TopOpeBRep_VPointInter::*)(const TopAbs_State, const Standard_Integer)) &TopOpeBRep_VPointInter::State, "Set the state of VPoint within the domain of the geometric shape <I> (= 1 or 2).", py::arg("S"), py::arg("I"));
cls_TopOpeBRep_VPointInter.def("EdgeON", (void (TopOpeBRep_VPointInter::*)(const TopoDS_Shape &, const Standard_Real, const Standard_Integer)) &TopOpeBRep_VPointInter::EdgeON, "set the shape Eon of shape I (1,2) containing the point, and parameter <Par> of point on <Eon>.", py::arg("Eon"), py::arg("Par"), py::arg("I"));
cls_TopOpeBRep_VPointInter.def("EdgeON", (const TopoDS_Shape & (TopOpeBRep_VPointInter::*)(const Standard_Integer) const) &TopOpeBRep_VPointInter::EdgeON, "get the edge of shape I (1,2) containing the point.", py::arg("I"));
cls_TopOpeBRep_VPointInter.def("EdgeONParameter", (Standard_Real (TopOpeBRep_VPointInter::*)(const Standard_Integer) const) &TopOpeBRep_VPointInter::EdgeONParameter, "get the parameter on edge of shape I (1,2) containing the point.", py::arg("I"));
cls_TopOpeBRep_VPointInter.def("ShapeIndex", (Standard_Integer (TopOpeBRep_VPointInter::*)() const) &TopOpeBRep_VPointInter::ShapeIndex, "returns value of filed myShapeIndex = 0,1,2,3 0 means the VPoint is on no restriction 1 means the VPoint is on the restriction 1 2 means the VPoint is on the restriction 2 3 means the VPoint is on the restrictions 1 and 2");
cls_TopOpeBRep_VPointInter.def("ShapeIndex", (void (TopOpeBRep_VPointInter::*)(const Standard_Integer)) &TopOpeBRep_VPointInter::ShapeIndex, "set value of shape supporting me (0,1,2,3).", py::arg("I"));
cls_TopOpeBRep_VPointInter.def("Edge", (const TopoDS_Shape & (TopOpeBRep_VPointInter::*)(const Standard_Integer) const) &TopOpeBRep_VPointInter::Edge, "get the edge of shape I (1,2) containing the point. Returned shape is null if the VPoint is not on an edge of shape I (1,2).", py::arg("I"));
cls_TopOpeBRep_VPointInter.def("EdgeParameter", (Standard_Real (TopOpeBRep_VPointInter::*)(const Standard_Integer) const) &TopOpeBRep_VPointInter::EdgeParameter, "get the parameter on edge of shape I (1,2) containing the point", py::arg("I"));
cls_TopOpeBRep_VPointInter.def("SurfaceParameters", (gp_Pnt2d (TopOpeBRep_VPointInter::*)(const Standard_Integer) const) &TopOpeBRep_VPointInter::SurfaceParameters, "get the parameter on surface of shape I (1,2) containing the point", py::arg("I"));
cls_TopOpeBRep_VPointInter.def("IsVertex", (Standard_Boolean (TopOpeBRep_VPointInter::*)(const Standard_Integer) const) &TopOpeBRep_VPointInter::IsVertex, "None", py::arg("I"));
cls_TopOpeBRep_VPointInter.def("Vertex", (const TopoDS_Shape & (TopOpeBRep_VPointInter::*)(const Standard_Integer) const) &TopOpeBRep_VPointInter::Vertex, "None", py::arg("I"));
cls_TopOpeBRep_VPointInter.def("UpdateKeep", (void (TopOpeBRep_VPointInter::*)()) &TopOpeBRep_VPointInter::UpdateKeep, "set myKeep value according to current states.");
cls_TopOpeBRep_VPointInter.def("Keep", (Standard_Boolean (TopOpeBRep_VPointInter::*)() const) &TopOpeBRep_VPointInter::Keep, "Returns value of myKeep (does not evaluate states) False at creation of VPoint. Updated by State(State from TopAbs,Integer from Standard)");
cls_TopOpeBRep_VPointInter.def("ChangeKeep", (void (TopOpeBRep_VPointInter::*)(const Standard_Boolean)) &TopOpeBRep_VPointInter::ChangeKeep, "updates VPointInter flag 'keep' with <keep>.", py::arg("keep"));
cls_TopOpeBRep_VPointInter.def("EqualpP", (Standard_Boolean (TopOpeBRep_VPointInter::*)(const TopOpeBRep_VPointInter &) const) &TopOpeBRep_VPointInter::EqualpP, "returns <True> if the 3d points and the parameters of the VPoints are same", py::arg("VP"));
cls_TopOpeBRep_VPointInter.def("ParonE", [](TopOpeBRep_VPointInter &self, const TopoDS_Edge & E, Standard_Real & par){ Standard_Boolean rv = self.ParonE(E, par); return std::tuple<Standard_Boolean, Standard_Real &>(rv, par); }, "returns <false> if the vpoint is not given on arc <E>, else returns <par> parameter on <E>", py::arg("E"), py::arg("par"));
cls_TopOpeBRep_VPointInter.def("Index", (void (TopOpeBRep_VPointInter::*)(const Standard_Integer)) &TopOpeBRep_VPointInter::Index, "None", py::arg("I"));
cls_TopOpeBRep_VPointInter.def("Index", (Standard_Integer (TopOpeBRep_VPointInter::*)() const) &TopOpeBRep_VPointInter::Index, "None");
cls_TopOpeBRep_VPointInter.def("Dump", (Standard_OStream & (TopOpeBRep_VPointInter::*)(const Standard_Integer, const TopoDS_Face &, Standard_OStream &) const) &TopOpeBRep_VPointInter::Dump, "None", py::arg("I"), py::arg("F"), py::arg("OS"));
cls_TopOpeBRep_VPointInter.def("Dump", (Standard_OStream & (TopOpeBRep_VPointInter::*)(const TopoDS_Face &, const TopoDS_Face &, Standard_OStream &) const) &TopOpeBRep_VPointInter::Dump, "None", py::arg("F1"), py::arg("F2"), py::arg("OS"));
cls_TopOpeBRep_VPointInter.def("PThePointOfIntersectionDummy", (TopOpeBRep_PThePointOfIntersection (TopOpeBRep_VPointInter::*)() const) &TopOpeBRep_VPointInter::PThePointOfIntersectionDummy, "None");

// Enums

}