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
#include <Prs3d_Presentation.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_StructureManager.hxx>
#include <StdSelect_Prs.hxx>
#include <Standard_Type.hxx>

void bind_StdSelect_Prs(py::module &mod){

py::class_<StdSelect_Prs, opencascade::handle<StdSelect_Prs>, Prs3d_Presentation> cls_StdSelect_Prs(mod, "StdSelect_Prs", "allows entities owners to be hilighted independantly from PresentableObjects");

// Constructors
cls_StdSelect_Prs.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &>(), py::arg("aStructureManager"));

// Fields

// Methods
cls_StdSelect_Prs.def("Manager", (const opencascade::handle<Graphic3d_StructureManager> & (StdSelect_Prs::*)() const) &StdSelect_Prs::Manager, "None");
cls_StdSelect_Prs.def_static("get_type_name_", (const char * (*)()) &StdSelect_Prs::get_type_name, "None");
cls_StdSelect_Prs.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdSelect_Prs::get_type_descriptor, "None");
cls_StdSelect_Prs.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdSelect_Prs::*)() const) &StdSelect_Prs::DynamicType, "None");

// Enums

}