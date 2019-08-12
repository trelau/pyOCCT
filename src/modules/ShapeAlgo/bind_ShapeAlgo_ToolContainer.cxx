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
#include <Standard_Handle.hxx>
#include <ShapeFix_Shape.hxx>
#include <ShapeFix_EdgeProjAux.hxx>
#include <ShapeAlgo_ToolContainer.hxx>
#include <Standard_Type.hxx>

void bind_ShapeAlgo_ToolContainer(py::module &mod){

py::class_<ShapeAlgo_ToolContainer, opencascade::handle<ShapeAlgo_ToolContainer>, Standard_Transient> cls_ShapeAlgo_ToolContainer(mod, "ShapeAlgo_ToolContainer", "Returns tools used by AlgoContainer");

// Constructors
cls_ShapeAlgo_ToolContainer.def(py::init<>());

// Fields

// Methods
cls_ShapeAlgo_ToolContainer.def("FixShape", (opencascade::handle<ShapeFix_Shape> (ShapeAlgo_ToolContainer::*)() const) &ShapeAlgo_ToolContainer::FixShape, "Returns ShapeFix_Shape");
cls_ShapeAlgo_ToolContainer.def("EdgeProjAux", (opencascade::handle<ShapeFix_EdgeProjAux> (ShapeAlgo_ToolContainer::*)() const) &ShapeAlgo_ToolContainer::EdgeProjAux, "Returns ShapeFix_EdgeProjAux");
cls_ShapeAlgo_ToolContainer.def_static("get_type_name_", (const char * (*)()) &ShapeAlgo_ToolContainer::get_type_name, "None");
cls_ShapeAlgo_ToolContainer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeAlgo_ToolContainer::get_type_descriptor, "None");
cls_ShapeAlgo_ToolContainer.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeAlgo_ToolContainer::*)() const) &ShapeAlgo_ToolContainer::DynamicType, "None");

// Enums

}