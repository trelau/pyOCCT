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
#include <Prs3d_BasicAspect.hxx>
#include <Standard_Type.hxx>

void bind_Prs3d_BasicAspect(py::module &mod){

py::class_<Prs3d_BasicAspect, opencascade::handle<Prs3d_BasicAspect>, Standard_Transient> cls_Prs3d_BasicAspect(mod, "Prs3d_BasicAspect", "All basic Prs3d_xxxAspect must inherits from this class The aspect classes qualifies how to represent a given kind of object.");

// Constructors

// Fields

// Methods
cls_Prs3d_BasicAspect.def_static("get_type_name_", (const char * (*)()) &Prs3d_BasicAspect::get_type_name, "None");
cls_Prs3d_BasicAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Prs3d_BasicAspect::get_type_descriptor, "None");
cls_Prs3d_BasicAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (Prs3d_BasicAspect::*)() const) &Prs3d_BasicAspect::DynamicType, "None");

// Enums

}