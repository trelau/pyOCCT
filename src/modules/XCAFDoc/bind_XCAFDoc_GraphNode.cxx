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
#include <TDF_Attribute.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_Label.hxx>
#include <Standard_Handle.hxx>
#include <XCAFDoc_GraphNode.hxx>
#include <Standard_GUID.hxx>
#include <TDF_RelocationTable.hxx>
#include <TDF_DataSet.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>
#include <XCAFDoc_GraphNodeSequence.hxx>

void bind_XCAFDoc_GraphNode(py::module &mod){

py::class_<XCAFDoc_GraphNode, opencascade::handle<XCAFDoc_GraphNode>, TDF_Attribute> cls_XCAFDoc_GraphNode(mod, "XCAFDoc_GraphNode", "This attribute allow user multirelation tree of labels. This GraphNode is experimental Graph that not control looping and redundance. Attribute containg sequence of father's and child's labels. Provide create and work with Graph in XCAFDocument.");

// Constructors
cls_XCAFDoc_GraphNode.def(py::init<>());

// Fields

// Methods
cls_XCAFDoc_GraphNode.def_static("Find_", (Standard_Boolean (*)(const TDF_Label &, opencascade::handle<XCAFDoc_GraphNode> &)) &XCAFDoc_GraphNode::Find, "class methods working on the node =================================== Shortcut to search a Graph node attribute with default GraphID. Returns true if found.", py::arg("L"), py::arg("G"));
cls_XCAFDoc_GraphNode.def_static("Set_", (opencascade::handle<XCAFDoc_GraphNode> (*)(const TDF_Label &)) &XCAFDoc_GraphNode::Set, "Finds or Creates a GraphNode attribute on the label <L> with the default Graph ID, returned by the method <GetDefaultGraphID>. Returns the created/found GraphNode attribute.", py::arg("L"));
cls_XCAFDoc_GraphNode.def_static("Set_", (opencascade::handle<XCAFDoc_GraphNode> (*)(const TDF_Label &, const Standard_GUID &)) &XCAFDoc_GraphNode::Set, "Finds or Creates a GraphNode attribute on the label <L>, with an explicit tree ID. <ExplicitGraphID> is the ID returned by <TDF_Attribute::ID> method. Returns the found/created GraphNode attribute.", py::arg("L"), py::arg("ExplicitGraphID"));
cls_XCAFDoc_GraphNode.def_static("GetDefaultGraphID_", (const Standard_GUID & (*)()) &XCAFDoc_GraphNode::GetDefaultGraphID, "returns a default Graph ID. this ID is used by the <Set> method without explicit tree ID. Instance methods: ================");
cls_XCAFDoc_GraphNode.def("SetGraphID", (void (XCAFDoc_GraphNode::*)(const Standard_GUID &)) &XCAFDoc_GraphNode::SetGraphID, "None", py::arg("explicitID"));
cls_XCAFDoc_GraphNode.def("SetFather", (Standard_Integer (XCAFDoc_GraphNode::*)(const opencascade::handle<XCAFDoc_GraphNode> &)) &XCAFDoc_GraphNode::SetFather, "Set GraphNode <F> as father of me and returns index of <F> in Sequence that containing Fathers GraphNodes. return index of <F> from GraphNodeSequnece", py::arg("F"));
cls_XCAFDoc_GraphNode.def("SetChild", (Standard_Integer (XCAFDoc_GraphNode::*)(const opencascade::handle<XCAFDoc_GraphNode> &)) &XCAFDoc_GraphNode::SetChild, "Set GraphNode <Ch> as child of me and returns index of <Ch> in Sequence that containing Children GraphNodes. return index of <Ch> from GraphNodeSequnece", py::arg("Ch"));
cls_XCAFDoc_GraphNode.def("UnSetFather", (void (XCAFDoc_GraphNode::*)(const opencascade::handle<XCAFDoc_GraphNode> &)) &XCAFDoc_GraphNode::UnSetFather, "Remove <F> from Fathers GraphNodeSequence. and remove link between father and child.", py::arg("F"));
cls_XCAFDoc_GraphNode.def("UnSetFather", (void (XCAFDoc_GraphNode::*)(const Standard_Integer)) &XCAFDoc_GraphNode::UnSetFather, "Remove Father GraphNode by index from Fathers GraphNodeSequence. and remove link between father and child.", py::arg("Findex"));
cls_XCAFDoc_GraphNode.def("UnSetChild", (void (XCAFDoc_GraphNode::*)(const opencascade::handle<XCAFDoc_GraphNode> &)) &XCAFDoc_GraphNode::UnSetChild, "Remove <Ch> from GraphNodeSequence. and remove link between father and child.", py::arg("Ch"));
cls_XCAFDoc_GraphNode.def("UnSetChild", (void (XCAFDoc_GraphNode::*)(const Standard_Integer)) &XCAFDoc_GraphNode::UnSetChild, "Remove Child GraphNode by index from Children GraphNodeSequence. and remove link between father and child.", py::arg("Chindex"));
cls_XCAFDoc_GraphNode.def("GetFather", (opencascade::handle<XCAFDoc_GraphNode> (XCAFDoc_GraphNode::*)(const Standard_Integer) const) &XCAFDoc_GraphNode::GetFather, "Return GraphNode by index from GraphNodeSequence.", py::arg("Findex"));
cls_XCAFDoc_GraphNode.def("GetChild", (opencascade::handle<XCAFDoc_GraphNode> (XCAFDoc_GraphNode::*)(const Standard_Integer) const) &XCAFDoc_GraphNode::GetChild, "Return GraphNode by index from GraphNodeSequence.", py::arg("Chindex"));
cls_XCAFDoc_GraphNode.def("FatherIndex", (Standard_Integer (XCAFDoc_GraphNode::*)(const opencascade::handle<XCAFDoc_GraphNode> &) const) &XCAFDoc_GraphNode::FatherIndex, "Return index of <F>, or zero if there is no such Graphnode.", py::arg("F"));
cls_XCAFDoc_GraphNode.def("ChildIndex", (Standard_Integer (XCAFDoc_GraphNode::*)(const opencascade::handle<XCAFDoc_GraphNode> &) const) &XCAFDoc_GraphNode::ChildIndex, "Return index of <Ch>, or zero if there is no such Graphnode.", py::arg("Ch"));
cls_XCAFDoc_GraphNode.def("IsFather", (Standard_Boolean (XCAFDoc_GraphNode::*)(const opencascade::handle<XCAFDoc_GraphNode> &) const) &XCAFDoc_GraphNode::IsFather, "returns TRUE if <me> is father of <Ch>.", py::arg("Ch"));
cls_XCAFDoc_GraphNode.def("IsChild", (Standard_Boolean (XCAFDoc_GraphNode::*)(const opencascade::handle<XCAFDoc_GraphNode> &) const) &XCAFDoc_GraphNode::IsChild, "returns TRUE if <me> is child of <F>.", py::arg("F"));
cls_XCAFDoc_GraphNode.def("NbFathers", (Standard_Integer (XCAFDoc_GraphNode::*)() const) &XCAFDoc_GraphNode::NbFathers, "return Number of Fathers GraphNodes.");
cls_XCAFDoc_GraphNode.def("NbChildren", (Standard_Integer (XCAFDoc_GraphNode::*)() const) &XCAFDoc_GraphNode::NbChildren, "return Number of Childrens GraphNodes. Implementation of Attribute methods: ===================================");
cls_XCAFDoc_GraphNode.def("ID", (const Standard_GUID & (XCAFDoc_GraphNode::*)() const) &XCAFDoc_GraphNode::ID, "Returns the Graph ID (default or explicit one depending onthe Set method used).");
cls_XCAFDoc_GraphNode.def("Restore", (void (XCAFDoc_GraphNode::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_GraphNode::Restore, "None", py::arg("with"));
cls_XCAFDoc_GraphNode.def("Paste", (void (XCAFDoc_GraphNode::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_GraphNode::Paste, "None", py::arg("into"), py::arg("RT"));
cls_XCAFDoc_GraphNode.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_GraphNode::*)() const) &XCAFDoc_GraphNode::NewEmpty, "None");
cls_XCAFDoc_GraphNode.def("References", (void (XCAFDoc_GraphNode::*)(const opencascade::handle<TDF_DataSet> &) const) &XCAFDoc_GraphNode::References, "None", py::arg("aDataSet"));
cls_XCAFDoc_GraphNode.def("Dump", (Standard_OStream & (XCAFDoc_GraphNode::*)(Standard_OStream &) const) &XCAFDoc_GraphNode::Dump, "None", py::arg("anOS"));
cls_XCAFDoc_GraphNode.def("BeforeForget", (void (XCAFDoc_GraphNode::*)()) &XCAFDoc_GraphNode::BeforeForget, "None");
cls_XCAFDoc_GraphNode.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_GraphNode::get_type_name, "None");
cls_XCAFDoc_GraphNode.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_GraphNode::get_type_descriptor, "None");
cls_XCAFDoc_GraphNode.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_GraphNode::*)() const) &XCAFDoc_GraphNode::DynamicType, "None");

// Enums

}