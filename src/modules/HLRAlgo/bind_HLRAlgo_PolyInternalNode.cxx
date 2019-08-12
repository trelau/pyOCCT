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
#include <gp_XYZ.hxx>
#include <gp_XY.hxx>
#include <HLRAlgo_PolyInternalNode.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>

void bind_HLRAlgo_PolyInternalNode(py::module &mod){

py::class_<HLRAlgo_PolyInternalNode, opencascade::handle<HLRAlgo_PolyInternalNode>, Standard_Transient> cls_HLRAlgo_PolyInternalNode(mod, "HLRAlgo_PolyInternalNode", "to Update OutLines.");

// Constructors
cls_HLRAlgo_PolyInternalNode.def(py::init<>());

// Fields

// Methods
cls_HLRAlgo_PolyInternalNode.def("Indices", (HLRAlgo_PolyInternalNode::NodeIndices & (HLRAlgo_PolyInternalNode::*)()) &HLRAlgo_PolyInternalNode::Indices, "None");
cls_HLRAlgo_PolyInternalNode.def("Data", (HLRAlgo_PolyInternalNode::NodeData & (HLRAlgo_PolyInternalNode::*)()) &HLRAlgo_PolyInternalNode::Data, "None");
cls_HLRAlgo_PolyInternalNode.def_static("get_type_name_", (const char * (*)()) &HLRAlgo_PolyInternalNode::get_type_name, "None");
cls_HLRAlgo_PolyInternalNode.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRAlgo_PolyInternalNode::get_type_descriptor, "None");
cls_HLRAlgo_PolyInternalNode.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRAlgo_PolyInternalNode::*)() const) &HLRAlgo_PolyInternalNode::DynamicType, "None");

// Enums

}