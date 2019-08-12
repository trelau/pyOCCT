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
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Standard_Handle.hxx>
#include <IGESSolid_Block.hxx>
#include <Standard_Type.hxx>

void bind_IGESSolid_Block(py::module &mod){

py::class_<IGESSolid_Block, opencascade::handle<IGESSolid_Block>, IGESData_IGESEntity> cls_IGESSolid_Block(mod, "IGESSolid_Block", "defines Block, Type <150> Form Number <0> in package IGESSolid The Block is a rectangular parallelopiped, defined with one vertex at (X1, Y1, Z1) and three edges lying along the local +X, +Y, +Z axes.");

// Constructors
cls_IGESSolid_Block.def(py::init<>());

// Fields

// Methods
cls_IGESSolid_Block.def("Init", (void (IGESSolid_Block::*)(const gp_XYZ &, const gp_XYZ &, const gp_XYZ &, const gp_XYZ &)) &IGESSolid_Block::Init, "This method is used to set the fields of the class Block - aSize : Length in each local directions - aCorner : Corner point coordinates. Default (0,0,0) - aXAxis : Unit vector defining local X-axis default (1,0,0) - aZAxis : Unit vector defining local Z-axis default (0,0,1)", py::arg("aSize"), py::arg("aCorner"), py::arg("aXAxis"), py::arg("aZAxis"));
cls_IGESSolid_Block.def("Size", (gp_XYZ (IGESSolid_Block::*)() const) &IGESSolid_Block::Size, "returns the size of the block");
cls_IGESSolid_Block.def("XLength", (Standard_Real (IGESSolid_Block::*)() const) &IGESSolid_Block::XLength, "returns the length of the Block along the local X-direction");
cls_IGESSolid_Block.def("YLength", (Standard_Real (IGESSolid_Block::*)() const) &IGESSolid_Block::YLength, "returns the length of the Block along the local Y-direction");
cls_IGESSolid_Block.def("ZLength", (Standard_Real (IGESSolid_Block::*)() const) &IGESSolid_Block::ZLength, "returns the length of the Block along the local Z-direction");
cls_IGESSolid_Block.def("Corner", (gp_Pnt (IGESSolid_Block::*)() const) &IGESSolid_Block::Corner, "returns the corner point coordinates of the Block");
cls_IGESSolid_Block.def("TransformedCorner", (gp_Pnt (IGESSolid_Block::*)() const) &IGESSolid_Block::TransformedCorner, "returns the corner point coordinates of the Block after applying the TransformationMatrix");
cls_IGESSolid_Block.def("XAxis", (gp_Dir (IGESSolid_Block::*)() const) &IGESSolid_Block::XAxis, "returns the direction defining the local X-axis");
cls_IGESSolid_Block.def("TransformedXAxis", (gp_Dir (IGESSolid_Block::*)() const) &IGESSolid_Block::TransformedXAxis, "returns the direction defining the local X-axis after applying TransformationMatrix");
cls_IGESSolid_Block.def("YAxis", (gp_Dir (IGESSolid_Block::*)() const) &IGESSolid_Block::YAxis, "returns the direction defining the local Y-axis it is the cross product of ZAxis and XAxis");
cls_IGESSolid_Block.def("TransformedYAxis", (gp_Dir (IGESSolid_Block::*)() const) &IGESSolid_Block::TransformedYAxis, "returns the direction defining the local Y-axis after applying TransformationMatrix");
cls_IGESSolid_Block.def("ZAxis", (gp_Dir (IGESSolid_Block::*)() const) &IGESSolid_Block::ZAxis, "returns the direction defining the local X-axis");
cls_IGESSolid_Block.def("TransformedZAxis", (gp_Dir (IGESSolid_Block::*)() const) &IGESSolid_Block::TransformedZAxis, "returns the direction defining the local Z-axis after applying TransformationMatrix");
cls_IGESSolid_Block.def_static("get_type_name_", (const char * (*)()) &IGESSolid_Block::get_type_name, "None");
cls_IGESSolid_Block.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_Block::get_type_descriptor, "None");
cls_IGESSolid_Block.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_Block::*)() const) &IGESSolid_Block::DynamicType, "None");

// Enums

}