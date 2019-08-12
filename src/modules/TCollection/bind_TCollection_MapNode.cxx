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
#include <TCollection_MapNodePtr.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_MapNode.hxx>
#include <Standard_Type.hxx>

void bind_TCollection_MapNode(py::module &mod){

py::class_<TCollection_MapNode, opencascade::handle<TCollection_MapNode>, Standard_Transient> cls_TCollection_MapNode(mod, "TCollection_MapNode", "Basic class root of all the Maps.");

// Constructors
cls_TCollection_MapNode.def(py::init<const TCollection_MapNodePtr &>(), py::arg("n"));

// Fields

// Methods
cls_TCollection_MapNode.def("Next", (TCollection_MapNodePtr & (TCollection_MapNode::*)() const) &TCollection_MapNode::Next, "None");
cls_TCollection_MapNode.def_static("get_type_name_", (const char * (*)()) &TCollection_MapNode::get_type_name, "None");
cls_TCollection_MapNode.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TCollection_MapNode::get_type_descriptor, "None");
cls_TCollection_MapNode.def("DynamicType", (const opencascade::handle<Standard_Type> & (TCollection_MapNode::*)() const) &TCollection_MapNode::DynamicType, "None");

// Enums

}