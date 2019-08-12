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
#include <ShapeUpgrade_FaceDivide.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <ShapeUpgrade_ClosedFaceDivide.hxx>
#include <Standard_Type.hxx>

void bind_ShapeUpgrade_ClosedFaceDivide(py::module &mod){

py::class_<ShapeUpgrade_ClosedFaceDivide, opencascade::handle<ShapeUpgrade_ClosedFaceDivide>, ShapeUpgrade_FaceDivide> cls_ShapeUpgrade_ClosedFaceDivide(mod, "ShapeUpgrade_ClosedFaceDivide", "Divides a Face with one or more seam edge to avoid closed faces. Splitting is performed by U and V direction. The number of resulting faces can be defined by user.");

// Constructors
cls_ShapeUpgrade_ClosedFaceDivide.def(py::init<>());
cls_ShapeUpgrade_ClosedFaceDivide.def(py::init<const TopoDS_Face &>(), py::arg("F"));

// Fields

// Methods
cls_ShapeUpgrade_ClosedFaceDivide.def("SplitSurface", (Standard_Boolean (ShapeUpgrade_ClosedFaceDivide::*)()) &ShapeUpgrade_ClosedFaceDivide::SplitSurface, "Performs splitting of surface and computes the shell from source face.");
cls_ShapeUpgrade_ClosedFaceDivide.def("SetNbSplitPoints", (void (ShapeUpgrade_ClosedFaceDivide::*)(const Standard_Integer)) &ShapeUpgrade_ClosedFaceDivide::SetNbSplitPoints, "Sets the number of cutting lines by which closed face will be splitted. The resulting faces will be num+1.", py::arg("num"));
cls_ShapeUpgrade_ClosedFaceDivide.def("GetNbSplitPoints", (Standard_Integer (ShapeUpgrade_ClosedFaceDivide::*)() const) &ShapeUpgrade_ClosedFaceDivide::GetNbSplitPoints, "Returns the number of splitting points");
cls_ShapeUpgrade_ClosedFaceDivide.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_ClosedFaceDivide::get_type_name, "None");
cls_ShapeUpgrade_ClosedFaceDivide.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_ClosedFaceDivide::get_type_descriptor, "None");
cls_ShapeUpgrade_ClosedFaceDivide.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_ClosedFaceDivide::*)() const) &ShapeUpgrade_ClosedFaceDivide::DynamicType, "None");

// Enums

}