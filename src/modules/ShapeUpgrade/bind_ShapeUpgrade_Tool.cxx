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
#include <ShapeUpgrade_Tool.hxx>
#include <ShapeBuild_ReShape.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>

void bind_ShapeUpgrade_Tool(py::module &mod){

py::class_<ShapeUpgrade_Tool, opencascade::handle<ShapeUpgrade_Tool>, Standard_Transient> cls_ShapeUpgrade_Tool(mod, "ShapeUpgrade_Tool", "Tool is a root class for splitting classes Provides context for recording changes, basic precision value and limit (minimal and maximal) values for tolerances");

// Constructors
cls_ShapeUpgrade_Tool.def(py::init<>());

// Fields

// Methods
cls_ShapeUpgrade_Tool.def("Set", (void (ShapeUpgrade_Tool::*)(const opencascade::handle<ShapeUpgrade_Tool> &)) &ShapeUpgrade_Tool::Set, "Copy all fields from another Root object", py::arg("tool"));
cls_ShapeUpgrade_Tool.def("SetContext", (void (ShapeUpgrade_Tool::*)(const opencascade::handle<ShapeBuild_ReShape> &)) &ShapeUpgrade_Tool::SetContext, "Sets context", py::arg("context"));
cls_ShapeUpgrade_Tool.def("Context", (opencascade::handle<ShapeBuild_ReShape> (ShapeUpgrade_Tool::*)() const) &ShapeUpgrade_Tool::Context, "Returns context");
cls_ShapeUpgrade_Tool.def("SetPrecision", (void (ShapeUpgrade_Tool::*)(const Standard_Real)) &ShapeUpgrade_Tool::SetPrecision, "Sets basic precision value", py::arg("preci"));
cls_ShapeUpgrade_Tool.def("Precision", (Standard_Real (ShapeUpgrade_Tool::*)() const) &ShapeUpgrade_Tool::Precision, "Returns basic precision value");
cls_ShapeUpgrade_Tool.def("SetMinTolerance", (void (ShapeUpgrade_Tool::*)(const Standard_Real)) &ShapeUpgrade_Tool::SetMinTolerance, "Sets minimal allowed tolerance", py::arg("mintol"));
cls_ShapeUpgrade_Tool.def("MinTolerance", (Standard_Real (ShapeUpgrade_Tool::*)() const) &ShapeUpgrade_Tool::MinTolerance, "Returns minimal allowed tolerance");
cls_ShapeUpgrade_Tool.def("SetMaxTolerance", (void (ShapeUpgrade_Tool::*)(const Standard_Real)) &ShapeUpgrade_Tool::SetMaxTolerance, "Sets maximal allowed tolerance", py::arg("maxtol"));
cls_ShapeUpgrade_Tool.def("MaxTolerance", (Standard_Real (ShapeUpgrade_Tool::*)() const) &ShapeUpgrade_Tool::MaxTolerance, "Returns maximal allowed tolerance");
cls_ShapeUpgrade_Tool.def("LimitTolerance", (Standard_Real (ShapeUpgrade_Tool::*)(const Standard_Real) const) &ShapeUpgrade_Tool::LimitTolerance, "Returns tolerance limited by [myMinTol,myMaxTol]", py::arg("toler"));
cls_ShapeUpgrade_Tool.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_Tool::get_type_name, "None");
cls_ShapeUpgrade_Tool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_Tool::get_type_descriptor, "None");
cls_ShapeUpgrade_Tool.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_Tool::*)() const) &ShapeUpgrade_Tool::DynamicType, "None");

// Enums

}