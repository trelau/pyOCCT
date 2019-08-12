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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <MAT_Arc.hxx>
#include <MAT_SequenceOfArc.hxx>
#include <MAT_SequenceOfBasicElt.hxx>
#include <MAT_Node.hxx>
#include <Standard_Type.hxx>

void bind_MAT_Node(py::module &mod){

py::class_<MAT_Node, opencascade::handle<MAT_Node>, Standard_Transient> cls_MAT_Node(mod, "MAT_Node", "Node of Graph.");

// Constructors
cls_MAT_Node.def(py::init<const Standard_Integer, const opencascade::handle<MAT_Arc> &, const Standard_Real>(), py::arg("GeomIndex"), py::arg("LinkedArc"), py::arg("Distance"));

// Fields

// Methods
cls_MAT_Node.def("GeomIndex", (Standard_Integer (MAT_Node::*)() const) &MAT_Node::GeomIndex, "Returns the index associated of the geometric representation of <me>.");
cls_MAT_Node.def("Index", (Standard_Integer (MAT_Node::*)() const) &MAT_Node::Index, "Returns the index associated of the node");
cls_MAT_Node.def("LinkedArcs", (void (MAT_Node::*)(MAT_SequenceOfArc &) const) &MAT_Node::LinkedArcs, "Returns in <S> the Arcs linked to <me>.", py::arg("S"));
cls_MAT_Node.def("NearElts", (void (MAT_Node::*)(MAT_SequenceOfBasicElt &) const) &MAT_Node::NearElts, "Returns in <S> the BasicElts equidistant to <me>.", py::arg("S"));
cls_MAT_Node.def("Distance", (Standard_Real (MAT_Node::*)() const) &MAT_Node::Distance, "None");
cls_MAT_Node.def("PendingNode", (Standard_Boolean (MAT_Node::*)() const) &MAT_Node::PendingNode, "Returns True if <me> is a pending Node. (ie : the number of Arc Linked = 1)");
cls_MAT_Node.def("OnBasicElt", (Standard_Boolean (MAT_Node::*)() const) &MAT_Node::OnBasicElt, "Returns True if <me> belongs to the figure.");
cls_MAT_Node.def("Infinite", (Standard_Boolean (MAT_Node::*)() const) &MAT_Node::Infinite, "Returns True if the distance of <me> is Infinite");
cls_MAT_Node.def("SetIndex", (void (MAT_Node::*)(const Standard_Integer)) &MAT_Node::SetIndex, "Set the index associated of the node", py::arg("anIndex"));
cls_MAT_Node.def("SetLinkedArc", (void (MAT_Node::*)(const opencascade::handle<MAT_Arc> &)) &MAT_Node::SetLinkedArc, "None", py::arg("anArc"));
cls_MAT_Node.def_static("get_type_name_", (const char * (*)()) &MAT_Node::get_type_name, "None");
cls_MAT_Node.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MAT_Node::get_type_descriptor, "None");
cls_MAT_Node.def("DynamicType", (const opencascade::handle<Standard_Type> & (MAT_Node::*)() const) &MAT_Node::DynamicType, "None");

// Enums

}