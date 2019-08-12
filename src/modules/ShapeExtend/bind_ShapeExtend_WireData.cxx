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
#include <TopoDS_Wire.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <ShapeExtend_WireData.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Face.hxx>
#include <TopTools_HSequenceOfShape.hxx>
#include <Standard_Type.hxx>
#include <TColStd_HSequenceOfInteger.hxx>

void bind_ShapeExtend_WireData(py::module &mod){

py::class_<ShapeExtend_WireData, opencascade::handle<ShapeExtend_WireData>, Standard_Transient> cls_ShapeExtend_WireData(mod, "ShapeExtend_WireData", "This class provides a data structure necessary for work with the wire as with ordered list of edges, what is required for many algorithms. The advantage of this class is that it allows to work with wires which are not correct. The object of the class ShapeExtend_WireData can be initialized by TopoDS_Wire, and converted back to TopoDS_Wire. An edge in the wire is defined by its rank number. Operations of accessing, adding and removing edge at the given rank number are provided. On the whole wire, operations of circular permutation and reversing (both orientations of all edges and order of edges) are provided as well. This class also provides a method to check if the edge in the wire is a seam (if the wire lies on a face). This class is handled by reference. Such an approach gives the following advantages: 1. Sharing the object of this class strongly optimizes the processes of analysis and fixing performed in parallel on the wire stored in the form of this class. Fixing tool (e.g. ShapeFix_Wire) fixes problems one by one using analyzing tool (e.g. ShapeAnalysis_Wire). Sharing allows not to reinitialize each time the analyzing tool with modified ShapeExtend_WireData what consumes certain time. 2. No copying of contents. The object of ShapeExtend_WireData class has quite big size, returning it as a result of the function would cause additional copying of contents if this class were one handled by value. Moreover, this class is stored as a field in other classes which are they returned as results of functions, storing only a handle to ShapeExtend_WireData saves time and memory.");

// Constructors
cls_ShapeExtend_WireData.def(py::init<>());
cls_ShapeExtend_WireData.def(py::init<const TopoDS_Wire &>(), py::arg("wire"));
cls_ShapeExtend_WireData.def(py::init<const TopoDS_Wire &, const Standard_Boolean>(), py::arg("wire"), py::arg("chained"));
cls_ShapeExtend_WireData.def(py::init<const TopoDS_Wire &, const Standard_Boolean, const Standard_Boolean>(), py::arg("wire"), py::arg("chained"), py::arg("theManifoldMode"));

// Fields

// Methods
cls_ShapeExtend_WireData.def("Init", (void (ShapeExtend_WireData::*)(const opencascade::handle<ShapeExtend_WireData> &)) &ShapeExtend_WireData::Init, "Copies data from another WireData", py::arg("other"));
cls_ShapeExtend_WireData.def("Init", [](ShapeExtend_WireData &self, const TopoDS_Wire & a0) -> Standard_Boolean { return self.Init(a0); });
cls_ShapeExtend_WireData.def("Init", [](ShapeExtend_WireData &self, const TopoDS_Wire & a0, const Standard_Boolean a1) -> Standard_Boolean { return self.Init(a0, a1); });
cls_ShapeExtend_WireData.def("Init", (Standard_Boolean (ShapeExtend_WireData::*)(const TopoDS_Wire &, const Standard_Boolean, const Standard_Boolean)) &ShapeExtend_WireData::Init, "Loads an already existing wire If <chained> is True (default), edges are added in the sequence as they are explored by TopoDS_Iterator Else, if <chained> is False, wire is explored by BRepTools_WireExplorer and it is guaranteed that edges will be sequencially connected. Remark : In the latter case it can happen that not all edges will be found (because of limitations of BRepTools_WireExplorer for disconnected wires and wires with seam edges).", py::arg("wire"), py::arg("chained"), py::arg("theManifoldMode"));
cls_ShapeExtend_WireData.def("Clear", (void (ShapeExtend_WireData::*)()) &ShapeExtend_WireData::Clear, "Clears data about Wire.");
cls_ShapeExtend_WireData.def("ComputeSeams", [](ShapeExtend_WireData &self) -> void { return self.ComputeSeams(); });
cls_ShapeExtend_WireData.def("ComputeSeams", (void (ShapeExtend_WireData::*)(const Standard_Boolean)) &ShapeExtend_WireData::ComputeSeams, "Computes the list of seam edges By default (direct call), computing is enforced For indirect call (from IsSeam) it is redone only if not yet already done or if the list of edges has changed Remark : A Seam Edge is an Edge present twice in the list, once as FORWARD and once as REVERSED Each sense has its own PCurve, the one for FORWARD must be set in first", py::arg("enforce"));
cls_ShapeExtend_WireData.def("SetLast", (void (ShapeExtend_WireData::*)(const Standard_Integer)) &ShapeExtend_WireData::SetLast, "Does a circular permutation in order to set <num>th edge last", py::arg("num"));
cls_ShapeExtend_WireData.def("SetDegeneratedLast", (void (ShapeExtend_WireData::*)()) &ShapeExtend_WireData::SetDegeneratedLast, "When the wire contains at least one degenerated edge, sets it as last one Note : It is useful to process pcurves, for instance, while the pcurve of a DGNR may not be computed from its 3D part (there is none) it is computed after the other edges have been computed and chained.");
cls_ShapeExtend_WireData.def("Add", [](ShapeExtend_WireData &self, const TopoDS_Edge & a0) -> void { return self.Add(a0); });
cls_ShapeExtend_WireData.def("Add", (void (ShapeExtend_WireData::*)(const TopoDS_Edge &, const Standard_Integer)) &ShapeExtend_WireData::Add, "Adds an edge to a wire, being defined (not yet ended) This is the plain, basic, function to add an edge <num> = 0 (D): Appends at end <num> = 1: Preprends at start else, Insert before <num> Remark : Null Edge is simply ignored", py::arg("edge"), py::arg("atnum"));
cls_ShapeExtend_WireData.def("Add", [](ShapeExtend_WireData &self, const TopoDS_Wire & a0) -> void { return self.Add(a0); });
cls_ShapeExtend_WireData.def("Add", (void (ShapeExtend_WireData::*)(const TopoDS_Wire &, const Standard_Integer)) &ShapeExtend_WireData::Add, "Adds an entire wire, considered as a list of edges Remark : The wire is assumed to be ordered (TopoDS_Iterator is used)", py::arg("wire"), py::arg("atnum"));
cls_ShapeExtend_WireData.def("Add", [](ShapeExtend_WireData &self, const opencascade::handle<ShapeExtend_WireData> & a0) -> void { return self.Add(a0); });
cls_ShapeExtend_WireData.def("Add", (void (ShapeExtend_WireData::*)(const opencascade::handle<ShapeExtend_WireData> &, const Standard_Integer)) &ShapeExtend_WireData::Add, "Adds a wire in the form of WireData", py::arg("wire"), py::arg("atnum"));
cls_ShapeExtend_WireData.def("Add", [](ShapeExtend_WireData &self, const TopoDS_Shape & a0) -> void { return self.Add(a0); });
cls_ShapeExtend_WireData.def("Add", (void (ShapeExtend_WireData::*)(const TopoDS_Shape &, const Standard_Integer)) &ShapeExtend_WireData::Add, "Adds an edge or a wire invoking corresponding method Add", py::arg("shape"), py::arg("atnum"));
cls_ShapeExtend_WireData.def("AddOriented", (void (ShapeExtend_WireData::*)(const TopoDS_Edge &, const Standard_Integer)) &ShapeExtend_WireData::AddOriented, "Adds an edge to start or end of <me>, according to <mode> 0: at end, as direct 1: at end, as reversed 2: at start, as direct 3: at start, as reversed < 0: no adding", py::arg("edge"), py::arg("mode"));
cls_ShapeExtend_WireData.def("AddOriented", (void (ShapeExtend_WireData::*)(const TopoDS_Wire &, const Standard_Integer)) &ShapeExtend_WireData::AddOriented, "Adds a wire to start or end of <me>, according to <mode> 0: at end, as direct 1: at end, as reversed 2: at start, as direct 3: at start, as reversed < 0: no adding", py::arg("wire"), py::arg("mode"));
cls_ShapeExtend_WireData.def("AddOriented", (void (ShapeExtend_WireData::*)(const TopoDS_Shape &, const Standard_Integer)) &ShapeExtend_WireData::AddOriented, "Adds an edge or a wire invoking corresponding method AddOriented", py::arg("shape"), py::arg("mode"));
cls_ShapeExtend_WireData.def("Remove", [](ShapeExtend_WireData &self) -> void { return self.Remove(); });
cls_ShapeExtend_WireData.def("Remove", (void (ShapeExtend_WireData::*)(const Standard_Integer)) &ShapeExtend_WireData::Remove, "Removes an Edge, given its rank. By default removes the last edge.", py::arg("num"));
cls_ShapeExtend_WireData.def("Set", [](ShapeExtend_WireData &self, const TopoDS_Edge & a0) -> void { return self.Set(a0); });
cls_ShapeExtend_WireData.def("Set", (void (ShapeExtend_WireData::*)(const TopoDS_Edge &, const Standard_Integer)) &ShapeExtend_WireData::Set, "Replaces an edge at the given rank number <num> with new one. Default is last edge (<num> = 0).", py::arg("edge"), py::arg("num"));
cls_ShapeExtend_WireData.def("Reverse", (void (ShapeExtend_WireData::*)()) &ShapeExtend_WireData::Reverse, "Reverses the sense of the list and the orientation of each Edge This method should be called when either wire has no seam edges or face is not available");
cls_ShapeExtend_WireData.def("Reverse", (void (ShapeExtend_WireData::*)(const TopoDS_Face &)) &ShapeExtend_WireData::Reverse, "Reverses the sense of the list and the orientation of each Edge The face is necessary for swapping pcurves for seam edges (first pcurve corresponds to orientation FORWARD, and second to REVERSED; when edge is reversed, pcurves must be swapped) If face is NULL, no swapping is performed", py::arg("face"));
cls_ShapeExtend_WireData.def("NbEdges", (Standard_Integer (ShapeExtend_WireData::*)() const) &ShapeExtend_WireData::NbEdges, "Returns the count of currently recorded edges");
cls_ShapeExtend_WireData.def("NbNonManifoldEdges", (Standard_Integer (ShapeExtend_WireData::*)() const) &ShapeExtend_WireData::NbNonManifoldEdges, "Returns the count of currently recorded non-manifold edges");
cls_ShapeExtend_WireData.def("NonmanifoldEdge", (TopoDS_Edge (ShapeExtend_WireData::*)(const Standard_Integer) const) &ShapeExtend_WireData::NonmanifoldEdge, "Returns <num>th nonmanifold Edge", py::arg("num"));
cls_ShapeExtend_WireData.def("NonmanifoldEdges", (opencascade::handle<TopTools_HSequenceOfShape> (ShapeExtend_WireData::*)() const) &ShapeExtend_WireData::NonmanifoldEdges, "Returns sequence of non-manifold edges This sequence can be not empty if wire data set in manifold mode but initial wire has INTERNAL orientation or contains INTERNAL edges");
cls_ShapeExtend_WireData.def("ManifoldMode", (Standard_Boolean & (ShapeExtend_WireData::*)()) &ShapeExtend_WireData::ManifoldMode, "Returns mode defining manifold wire data or not. If manifold that nonmanifold edges will not be not consider during operations(previous behaviour) and they will be added only in result wire else non-manifold edges will consider during operations");
cls_ShapeExtend_WireData.def("Edge", (TopoDS_Edge (ShapeExtend_WireData::*)(const Standard_Integer) const) &ShapeExtend_WireData::Edge, "Returns <num>th Edge", py::arg("num"));
cls_ShapeExtend_WireData.def("Index", (Standard_Integer (ShapeExtend_WireData::*)(const TopoDS_Edge &)) &ShapeExtend_WireData::Index, "Returns the index of the edge If the edge is a seam the orientation is also checked Returns 0 if the edge is not found in the list", py::arg("edge"));
cls_ShapeExtend_WireData.def("IsSeam", (Standard_Boolean (ShapeExtend_WireData::*)(const Standard_Integer)) &ShapeExtend_WireData::IsSeam, "Tells if an Edge is seam (see ComputeSeams) An edge is considered as seam if it presents twice in the edge list, once as FORWARD and once as REVERSED.", py::arg("num"));
cls_ShapeExtend_WireData.def("Wire", (TopoDS_Wire (ShapeExtend_WireData::*)() const) &ShapeExtend_WireData::Wire, "Makes TopoDS_Wire using BRep_Builder (just creates the TopoDS_Wire object and adds all edges into it). This method should be called when the wire is correct (for example, after successful fixes by ShapeFix_Wire) and adjacent edges share common vertices. In case if adjacent edges do not share the same vertices the resulting TopoDS_Wire will be invalid.");
cls_ShapeExtend_WireData.def("WireAPIMake", (TopoDS_Wire (ShapeExtend_WireData::*)() const) &ShapeExtend_WireData::WireAPIMake, "Makes TopoDS_Wire using BRepAPI_MakeWire. Class BRepAPI_MakeWire merges geometrically coincided vertices and can disturb correct order of edges in the wire. If this class fails, null shape is returned.");
cls_ShapeExtend_WireData.def_static("get_type_name_", (const char * (*)()) &ShapeExtend_WireData::get_type_name, "None");
cls_ShapeExtend_WireData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeExtend_WireData::get_type_descriptor, "None");
cls_ShapeExtend_WireData.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeExtend_WireData::*)() const) &ShapeExtend_WireData::DynamicType, "None");

// Enums

}