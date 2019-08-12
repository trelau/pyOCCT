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
#include <TCollection_SeqNodePtr.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_SeqNode.hxx>
#include <Standard_Type.hxx>

void bind_TCollection_SeqNode(py::module &mod){

py::class_<TCollection_SeqNode, opencascade::handle<TCollection_SeqNode>, Standard_Transient> cls_TCollection_SeqNode(mod, "TCollection_SeqNode", "None");

// Constructors
cls_TCollection_SeqNode.def(py::init<const TCollection_SeqNodePtr &, const TCollection_SeqNodePtr &>(), py::arg("n"), py::arg("p"));

// Fields

// Methods
cls_TCollection_SeqNode.def("Next", (TCollection_SeqNodePtr & (TCollection_SeqNode::*)() const) &TCollection_SeqNode::Next, "None");
cls_TCollection_SeqNode.def("Previous", (TCollection_SeqNodePtr & (TCollection_SeqNode::*)() const) &TCollection_SeqNode::Previous, "None");
cls_TCollection_SeqNode.def_static("get_type_name_", (const char * (*)()) &TCollection_SeqNode::get_type_name, "None");
cls_TCollection_SeqNode.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TCollection_SeqNode::get_type_descriptor, "None");
cls_TCollection_SeqNode.def("DynamicType", (const opencascade::handle<Standard_Type> & (TCollection_SeqNode::*)() const) &TCollection_SeqNode::DynamicType, "None");

// Enums

}