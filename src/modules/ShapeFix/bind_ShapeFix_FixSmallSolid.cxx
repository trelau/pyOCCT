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
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <ShapeBuild_ReShape.hxx>
#include <ShapeFix_FixSmallSolid.hxx>
#include <Standard_Type.hxx>

void bind_ShapeFix_FixSmallSolid(py::module &mod){

py::class_<ShapeFix_FixSmallSolid, opencascade::handle<ShapeFix_FixSmallSolid>, ShapeFix_Root> cls_ShapeFix_FixSmallSolid(mod, "ShapeFix_FixSmallSolid", "Fixing solids with small size");

// Constructors
cls_ShapeFix_FixSmallSolid.def(py::init<>());

// Fields

// Methods
cls_ShapeFix_FixSmallSolid.def("SetFixMode", (void (ShapeFix_FixSmallSolid::*)(const Standard_Integer)) &ShapeFix_FixSmallSolid::SetFixMode, "Set working mode for operator: - theMode = 0 use both WidthFactorThreshold and VolumeThreshold parameters - theMode = 1 use only WidthFactorThreshold parameter - theMode = 2 use only VolumeThreshold parameter", py::arg("theMode"));
cls_ShapeFix_FixSmallSolid.def("SetVolumeThreshold", [](ShapeFix_FixSmallSolid &self) -> void { return self.SetVolumeThreshold(); });
cls_ShapeFix_FixSmallSolid.def("SetVolumeThreshold", (void (ShapeFix_FixSmallSolid::*)(const Standard_Real)) &ShapeFix_FixSmallSolid::SetVolumeThreshold, "Set or clear volume threshold for small solids", py::arg("theThreshold"));
cls_ShapeFix_FixSmallSolid.def("SetWidthFactorThreshold", [](ShapeFix_FixSmallSolid &self) -> void { return self.SetWidthFactorThreshold(); });
cls_ShapeFix_FixSmallSolid.def("SetWidthFactorThreshold", (void (ShapeFix_FixSmallSolid::*)(const Standard_Real)) &ShapeFix_FixSmallSolid::SetWidthFactorThreshold, "Set or clear width factor threshold for small solids", py::arg("theThreshold"));
cls_ShapeFix_FixSmallSolid.def("Remove", (TopoDS_Shape (ShapeFix_FixSmallSolid::*)(const TopoDS_Shape &, const opencascade::handle<ShapeBuild_ReShape> &) const) &ShapeFix_FixSmallSolid::Remove, "Remove small solids from the given shape", py::arg("theShape"), py::arg("theContext"));
cls_ShapeFix_FixSmallSolid.def("Merge", (TopoDS_Shape (ShapeFix_FixSmallSolid::*)(const TopoDS_Shape &, const opencascade::handle<ShapeBuild_ReShape> &) const) &ShapeFix_FixSmallSolid::Merge, "Merge small solids in the given shape to adjacent non-small ones", py::arg("theShape"), py::arg("theContext"));
cls_ShapeFix_FixSmallSolid.def_static("get_type_name_", (const char * (*)()) &ShapeFix_FixSmallSolid::get_type_name, "None");
cls_ShapeFix_FixSmallSolid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeFix_FixSmallSolid::get_type_descriptor, "None");
cls_ShapeFix_FixSmallSolid.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeFix_FixSmallSolid::*)() const) &ShapeFix_FixSmallSolid::DynamicType, "None");

// Enums

}