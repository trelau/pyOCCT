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
#include <ShapeFix_Root.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <ShapeFix_SplitCommonVertex.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>

void bind_ShapeFix_SplitCommonVertex(py::module &mod){

py::class_<ShapeFix_SplitCommonVertex, opencascade::handle<ShapeFix_SplitCommonVertex>, ShapeFix_Root> cls_ShapeFix_SplitCommonVertex(mod, "ShapeFix_SplitCommonVertex", "Two wires have common vertex - this case is valid in BRep model and isn't valid in STEP => before writing into STEP it is necessary to split this vertex (each wire must has one vertex)");

// Constructors
cls_ShapeFix_SplitCommonVertex.def(py::init<>());

// Fields

// Methods
cls_ShapeFix_SplitCommonVertex.def("Init", (void (ShapeFix_SplitCommonVertex::*)(const TopoDS_Shape &)) &ShapeFix_SplitCommonVertex::Init, "None", py::arg("S"));
cls_ShapeFix_SplitCommonVertex.def("Perform", (void (ShapeFix_SplitCommonVertex::*)()) &ShapeFix_SplitCommonVertex::Perform, "None");
cls_ShapeFix_SplitCommonVertex.def("Shape", (TopoDS_Shape (ShapeFix_SplitCommonVertex::*)()) &ShapeFix_SplitCommonVertex::Shape, "None");
cls_ShapeFix_SplitCommonVertex.def_static("get_type_name_", (const char * (*)()) &ShapeFix_SplitCommonVertex::get_type_name, "None");
cls_ShapeFix_SplitCommonVertex.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeFix_SplitCommonVertex::get_type_descriptor, "None");
cls_ShapeFix_SplitCommonVertex.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeFix_SplitCommonVertex::*)() const) &ShapeFix_SplitCommonVertex::DynamicType, "None");

// Enums

}