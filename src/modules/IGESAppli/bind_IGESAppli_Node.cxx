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
#include <gp_XYZ.hxx>
#include <Standard_Handle.hxx>
#include <IGESGeom_TransformationMatrix.hxx>
#include <gp_Pnt.hxx>
#include <IGESData_TransfEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESAppli_Node.hxx>
#include <Standard_Type.hxx>

void bind_IGESAppli_Node(py::module &mod){

py::class_<IGESAppli_Node, opencascade::handle<IGESAppli_Node>, IGESData_IGESEntity> cls_IGESAppli_Node(mod, "IGESAppli_Node", "defines Node, Type <134> Form <0> in package IGESAppli Geometric point used in the definition of a finite element.");

// Constructors
cls_IGESAppli_Node.def(py::init<>());

// Fields

// Methods
cls_IGESAppli_Node.def("Init", (void (IGESAppli_Node::*)(const gp_XYZ &, const opencascade::handle<IGESGeom_TransformationMatrix> &)) &IGESAppli_Node::Init, "This method is used to set the fields of the class Node - aCoord : Nodal Coordinates - aCoordSystem : the Nodal Displacement Coordinate System Entity (default 0 is Global Cartesian Coordinate system)", py::arg("aCoord"), py::arg("aCoordSystem"));
cls_IGESAppli_Node.def("Coord", (gp_Pnt (IGESAppli_Node::*)() const) &IGESAppli_Node::Coord, "returns the nodal coordinates");
cls_IGESAppli_Node.def("System", (opencascade::handle<IGESData_TransfEntity> (IGESAppli_Node::*)() const) &IGESAppli_Node::System, "returns TransfEntity if a Nodal Displacement Coordinate System Entity is defined else (for Global Cartesien) returns Null Handle");
cls_IGESAppli_Node.def("SystemType", (Standard_Integer (IGESAppli_Node::*)() const) &IGESAppli_Node::SystemType, "Computes & returns the Type of Coordinate System : 0 GlobalCartesian, 1 Cartesian, 2 Cylindrical, 3 Spherical");
cls_IGESAppli_Node.def("TransformedNodalCoord", (gp_Pnt (IGESAppli_Node::*)() const) &IGESAppli_Node::TransformedNodalCoord, "returns the Nodal coordinates after transformation");
cls_IGESAppli_Node.def_static("get_type_name_", (const char * (*)()) &IGESAppli_Node::get_type_name, "None");
cls_IGESAppli_Node.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESAppli_Node::get_type_descriptor, "None");
cls_IGESAppli_Node.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESAppli_Node::*)() const) &IGESAppli_Node::DynamicType, "None");

// Enums

}