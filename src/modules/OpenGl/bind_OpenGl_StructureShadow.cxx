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
#include <OpenGl_Structure.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_StructureManager.hxx>
#include <Graphic3d_CStructure.hxx>
#include <OpenGl_StructureShadow.hxx>
#include <Standard_Type.hxx>

void bind_OpenGl_StructureShadow(py::module &mod){

py::class_<OpenGl_StructureShadow, opencascade::handle<OpenGl_StructureShadow>> cls_OpenGl_StructureShadow(mod, "OpenGl_StructureShadow", "Dummy structure which just redirects to groups of another structure.");

// Constructors
cls_OpenGl_StructureShadow.def(py::init<const opencascade::handle<Graphic3d_StructureManager> &, const opencascade::handle<OpenGl_Structure> &>(), py::arg("theManager"), py::arg("theStructure"));

// Fields

// Methods
cls_OpenGl_StructureShadow.def("Connect", (void (OpenGl_StructureShadow::*)(Graphic3d_CStructure &)) &OpenGl_StructureShadow::Connect, "Raise exception on API misuse.", py::arg(""));
cls_OpenGl_StructureShadow.def("Disconnect", (void (OpenGl_StructureShadow::*)(Graphic3d_CStructure &)) &OpenGl_StructureShadow::Disconnect, "Raise exception on API misuse.", py::arg(""));
cls_OpenGl_StructureShadow.def_static("get_type_name_", (const char * (*)()) &OpenGl_StructureShadow::get_type_name, "None");
cls_OpenGl_StructureShadow.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_StructureShadow::get_type_descriptor, "None");
cls_OpenGl_StructureShadow.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_StructureShadow::*)() const) &OpenGl_StructureShadow::DynamicType, "None");

// Enums

}