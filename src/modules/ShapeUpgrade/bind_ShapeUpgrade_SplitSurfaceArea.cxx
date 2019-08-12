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
#include <ShapeUpgrade_SplitSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <ShapeUpgrade_SplitSurfaceArea.hxx>
#include <Standard_Type.hxx>

void bind_ShapeUpgrade_SplitSurfaceArea(py::module &mod){

py::class_<ShapeUpgrade_SplitSurfaceArea, opencascade::handle<ShapeUpgrade_SplitSurfaceArea>, ShapeUpgrade_SplitSurface> cls_ShapeUpgrade_SplitSurfaceArea(mod, "ShapeUpgrade_SplitSurfaceArea", "Split surface in the parametric space in according specified number of splits on the");

// Constructors
cls_ShapeUpgrade_SplitSurfaceArea.def(py::init<>());

// Fields

// Methods
cls_ShapeUpgrade_SplitSurfaceArea.def("NbParts", (Standard_Integer & (ShapeUpgrade_SplitSurfaceArea::*)()) &ShapeUpgrade_SplitSurfaceArea::NbParts, "Set number of split for surfaces");
cls_ShapeUpgrade_SplitSurfaceArea.def("Compute", [](ShapeUpgrade_SplitSurfaceArea &self) -> void { return self.Compute(); });
cls_ShapeUpgrade_SplitSurfaceArea.def("Compute", (void (ShapeUpgrade_SplitSurfaceArea::*)(const Standard_Boolean)) &ShapeUpgrade_SplitSurfaceArea::Compute, "None", py::arg("Segment"));
cls_ShapeUpgrade_SplitSurfaceArea.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_SplitSurfaceArea::get_type_name, "None");
cls_ShapeUpgrade_SplitSurfaceArea.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_SplitSurfaceArea::get_type_descriptor, "None");
cls_ShapeUpgrade_SplitSurfaceArea.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_SplitSurfaceArea::*)() const) &ShapeUpgrade_SplitSurfaceArea::DynamicType, "None");

// Enums

}