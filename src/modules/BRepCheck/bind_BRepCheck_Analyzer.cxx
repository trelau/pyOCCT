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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <BRepCheck_Result.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <BRepCheck_DataMapOfShapeResult.hxx>
#include <BRepCheck_Analyzer.hxx>

void bind_BRepCheck_Analyzer(py::module &mod){

py::class_<BRepCheck_Analyzer> cls_BRepCheck_Analyzer(mod, "BRepCheck_Analyzer", "A framework to check the overall validity of a shape. For a shape to be valid in Open CASCADE, it - or its component subshapes - must respect certain criteria. These criteria are checked by the function IsValid. Once you have determined whether a shape is valid or not, you can diagnose its specific anomalies and correct them using the services of the ShapeAnalysis, ShapeUpgrade, and ShapeFix packages.");

// Constructors
cls_BRepCheck_Analyzer.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
cls_BRepCheck_Analyzer.def(py::init<const TopoDS_Shape &, const Standard_Boolean>(), py::arg("S"), py::arg("GeomControls"));

// Fields

// Methods
// cls_BRepCheck_Analyzer.def_static("operator new_", (void * (*)(size_t)) &BRepCheck_Analyzer::operator new, "None", py::arg("theSize"));
// cls_BRepCheck_Analyzer.def_static("operator delete_", (void (*)(void *)) &BRepCheck_Analyzer::operator delete, "None", py::arg("theAddress"));
// cls_BRepCheck_Analyzer.def_static("operator new[]_", (void * (*)(size_t)) &BRepCheck_Analyzer::operator new[], "None", py::arg("theSize"));
// cls_BRepCheck_Analyzer.def_static("operator delete[]_", (void (*)(void *)) &BRepCheck_Analyzer::operator delete[], "None", py::arg("theAddress"));
// cls_BRepCheck_Analyzer.def_static("operator new_", (void * (*)(size_t, void *)) &BRepCheck_Analyzer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepCheck_Analyzer.def_static("operator delete_", (void (*)(void *, void *)) &BRepCheck_Analyzer::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepCheck_Analyzer.def("Init", [](BRepCheck_Analyzer &self, const TopoDS_Shape & a0) -> void { return self.Init(a0); });
cls_BRepCheck_Analyzer.def("Init", (void (BRepCheck_Analyzer::*)(const TopoDS_Shape &, const Standard_Boolean)) &BRepCheck_Analyzer::Init, "<S> is the shape to control. <GeomControls> If False only topological informaions are checked. The geometricals controls are For a Vertex : BRepCheck_InvalidTolerance NYI For an Edge : BRepCheck_InvalidCurveOnClosedSurface, BRepCheck_InvalidCurveOnSurface, BRepCheck_InvalidSameParameterFlag, BRepCheck_InvalidTolerance NYI For a face : BRepCheck_UnorientableShape, BRepCheck_IntersectingWires, BRepCheck_InvalidTolerance NYI For a wire : BRepCheck_SelfIntersectingWire", py::arg("S"), py::arg("GeomControls"));
cls_BRepCheck_Analyzer.def("IsValid", (Standard_Boolean (BRepCheck_Analyzer::*)(const TopoDS_Shape &) const) &BRepCheck_Analyzer::IsValid, "<S> is a subshape of the original shape. Returns <STandard_True> if no default has been detected on <S> and any of its subshape.", py::arg("S"));
cls_BRepCheck_Analyzer.def("IsValid", (Standard_Boolean (BRepCheck_Analyzer::*)() const) &BRepCheck_Analyzer::IsValid, "Returns true if no defect is detected on the shape S or any of its subshapes. Returns true if the shape S is valid. This function checks whether a given shape is valid by checking that: - the topology is correct - parameterization of edges in particular is correct. For the topology to be correct, the following conditions must be satisfied: - edges should have at least two vertices if they are not degenerate edges. The vertices should be within the range of the bounding edges at the tolerance specified in the vertex, - edges should share at least one face. The representation of the edges should be within the tolerance criterion assigned to them. - wires defining a face should not self-intersect and should be closed, - there should be one wire which contains all other wires inside a face, - wires should be correctly oriented with respect to each of the edges, - faces should be correctly oriented, in particular with respect to adjacent faces if these faces define a solid, - shells defining a solid should be closed. There should be one enclosing shell if the shape is a solid; To check parameterization of edge, there are 2 approaches depending on the edge?s contextual situation. - if the edge is either single, or it is in the context of a wire or a compound, its parameterization is defined by the parameterization of its 3D curve and is considered as valid. - If the edge is in the context of a face, it should have SameParameter and SameRange flags set to Standard_True. To check these flags, you should call the function BRep_Tool::SameParameter and BRep_Tool::SameRange for an edge. If at least one of these flags is set to Standard_False, the edge is considered as invalid without any additional check. If the edge is contained by a face, and it has SameParameter and SameRange flags set to Standard_True, IsValid checks whether representation of the edge on face, in context of which the edge is considered, has the same parameterization up to the tolerance value coded on the edge. For a given parameter t on the edge having C as a 3D curve and one PCurve P on a surface S (base surface of the reference face), this checks that |C(t) - S(P(t))| is less than or equal to tolerance, where tolerance is the tolerance value coded on the edge.");
cls_BRepCheck_Analyzer.def("Result", (const opencascade::handle<BRepCheck_Result> & (BRepCheck_Analyzer::*)(const TopoDS_Shape &) const) &BRepCheck_Analyzer::Result, "None", py::arg("SubS"));

// Enums

}