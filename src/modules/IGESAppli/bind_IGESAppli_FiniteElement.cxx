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
#include <IGESData_IGESEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESAppli_HArray1OfNode.hxx>
#include <TCollection_HAsciiString.hxx>
#include <IGESAppli_Node.hxx>
#include <IGESAppli_FiniteElement.hxx>
#include <Standard_Type.hxx>

void bind_IGESAppli_FiniteElement(py::module &mod){

py::class_<IGESAppli_FiniteElement, opencascade::handle<IGESAppli_FiniteElement>, IGESData_IGESEntity> cls_IGESAppli_FiniteElement(mod, "IGESAppli_FiniteElement", "defines FiniteElement, Type <136> Form <0> in package IGESAppli Used to define a finite element with the help of an element topology.");

// Constructors
cls_IGESAppli_FiniteElement.def(py::init<>());

// Fields

// Methods
cls_IGESAppli_FiniteElement.def("Init", (void (IGESAppli_FiniteElement::*)(const Standard_Integer, const opencascade::handle<IGESAppli_HArray1OfNode> &, const opencascade::handle<TCollection_HAsciiString> &)) &IGESAppli_FiniteElement::Init, "This method is used to set the fields of the class FiniteElement - aType : Indicates the topology type - allNodes : List of Nodes defining the element - aName : Element type name", py::arg("aType"), py::arg("allNodes"), py::arg("aName"));
cls_IGESAppli_FiniteElement.def("Topology", (Standard_Integer (IGESAppli_FiniteElement::*)() const) &IGESAppli_FiniteElement::Topology, "returns Topology type");
cls_IGESAppli_FiniteElement.def("NbNodes", (Standard_Integer (IGESAppli_FiniteElement::*)() const) &IGESAppli_FiniteElement::NbNodes, "returns the number of nodes defining the element");
cls_IGESAppli_FiniteElement.def("Node", (opencascade::handle<IGESAppli_Node> (IGESAppli_FiniteElement::*)(const Standard_Integer) const) &IGESAppli_FiniteElement::Node, "returns Node defining element entity raises exception if Index <= 0 or Index > NbNodes()", py::arg("Index"));
cls_IGESAppli_FiniteElement.def("Name", (opencascade::handle<TCollection_HAsciiString> (IGESAppli_FiniteElement::*)() const) &IGESAppli_FiniteElement::Name, "returns Element Type Name");
cls_IGESAppli_FiniteElement.def_static("get_type_name_", (const char * (*)()) &IGESAppli_FiniteElement::get_type_name, "None");
cls_IGESAppli_FiniteElement.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESAppli_FiniteElement::get_type_descriptor, "None");
cls_IGESAppli_FiniteElement.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESAppli_FiniteElement::*)() const) &IGESAppli_FiniteElement::DynamicType, "None");

// Enums

}