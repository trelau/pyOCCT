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
#include <IGESBasic_Group.hxx>
#include <Standard_Handle.hxx>
#include <IGESBasic_GroupWithoutBackP.hxx>
#include <Standard_Type.hxx>

void bind_IGESBasic_GroupWithoutBackP(py::module &mod){

py::class_<IGESBasic_GroupWithoutBackP, opencascade::handle<IGESBasic_GroupWithoutBackP>, IGESBasic_Group> cls_IGESBasic_GroupWithoutBackP(mod, "IGESBasic_GroupWithoutBackP", "defines GroupWithoutBackP, Type <402> Form <7> in package IGESBasic this class defines a Group without back pointers");

// Constructors
cls_IGESBasic_GroupWithoutBackP.def(py::init<>());

// Fields

// Methods
cls_IGESBasic_GroupWithoutBackP.def_static("get_type_name_", (const char * (*)()) &IGESBasic_GroupWithoutBackP::get_type_name, "None");
cls_IGESBasic_GroupWithoutBackP.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_GroupWithoutBackP::get_type_descriptor, "None");
cls_IGESBasic_GroupWithoutBackP.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_GroupWithoutBackP::*)() const) &IGESBasic_GroupWithoutBackP::DynamicType, "None");

// Enums

}