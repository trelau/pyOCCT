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
#include <TopoDS_Shape.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_Handle.hxx>
#include <ShapeUpgrade_RemoveLocations.hxx>
#include <Standard_Type.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>

void bind_ShapeUpgrade_RemoveLocations(py::module &mod){

py::class_<ShapeUpgrade_RemoveLocations, opencascade::handle<ShapeUpgrade_RemoveLocations>, Standard_Transient> cls_ShapeUpgrade_RemoveLocations(mod, "ShapeUpgrade_RemoveLocations", "Removes all locations sub-shapes of specified shape");

// Constructors
cls_ShapeUpgrade_RemoveLocations.def(py::init<>());

// Fields

// Methods
cls_ShapeUpgrade_RemoveLocations.def("Remove", (Standard_Boolean (ShapeUpgrade_RemoveLocations::*)(const TopoDS_Shape &)) &ShapeUpgrade_RemoveLocations::Remove, "Removes all location correspodingly to RemoveLevel.", py::arg("theShape"));
cls_ShapeUpgrade_RemoveLocations.def("GetResult", (TopoDS_Shape (ShapeUpgrade_RemoveLocations::*)() const) &ShapeUpgrade_RemoveLocations::GetResult, "Returns shape with removed locatins.");
cls_ShapeUpgrade_RemoveLocations.def("SetRemoveLevel", (void (ShapeUpgrade_RemoveLocations::*)(const TopAbs_ShapeEnum)) &ShapeUpgrade_RemoveLocations::SetRemoveLevel, "sets level starting with that location will be removed, by default TopAbs_SHAPE. In this case locations will be kept for specified shape and if specified shape is TopAbs_COMPOUND for sub-shapes of first level.", py::arg("theLevel"));
cls_ShapeUpgrade_RemoveLocations.def("RemoveLevel", (TopAbs_ShapeEnum (ShapeUpgrade_RemoveLocations::*)() const) &ShapeUpgrade_RemoveLocations::RemoveLevel, "sets level starting with that location will be removed.Value of level can be set to TopAbs_SHAPE,TopAbs_COMPOUND,TopAbs_SOLID,TopAbs_SHELL,TopAbs_FACE.By default TopAbs_SHAPE. In this case location will be removed for all shape types for exception of compound.");
cls_ShapeUpgrade_RemoveLocations.def("ModifiedShape", (TopoDS_Shape (ShapeUpgrade_RemoveLocations::*)(const TopoDS_Shape &) const) &ShapeUpgrade_RemoveLocations::ModifiedShape, "Returns modified shape obtained from initial shape.", py::arg("theInitShape"));
cls_ShapeUpgrade_RemoveLocations.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_RemoveLocations::get_type_name, "None");
cls_ShapeUpgrade_RemoveLocations.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_RemoveLocations::get_type_descriptor, "None");
cls_ShapeUpgrade_RemoveLocations.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_RemoveLocations::*)() const) &ShapeUpgrade_RemoveLocations::DynamicType, "None");

// Enums

}