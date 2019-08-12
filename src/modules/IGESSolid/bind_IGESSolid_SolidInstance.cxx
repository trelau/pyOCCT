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
#include <IGESData_IGESEntity.hxx>
#include <Standard_Handle.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESSolid_SolidInstance.hxx>
#include <Standard_Type.hxx>

void bind_IGESSolid_SolidInstance(py::module &mod){

py::class_<IGESSolid_SolidInstance, opencascade::handle<IGESSolid_SolidInstance>, IGESData_IGESEntity> cls_IGESSolid_SolidInstance(mod, "IGESSolid_SolidInstance", "defines SolidInstance, Type <430> Form Number <0> in package IGESSolid This provides a mechanism for replicating a solid representation.");

// Constructors
cls_IGESSolid_SolidInstance.def(py::init<>());

// Fields

// Methods
cls_IGESSolid_SolidInstance.def("Init", (void (IGESSolid_SolidInstance::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESSolid_SolidInstance::Init, "This method is used to set the fields of the class SolidInstance - anEntity : the entity corresponding to the solid", py::arg("anEntity"));
cls_IGESSolid_SolidInstance.def("IsBrep", (Standard_Boolean (IGESSolid_SolidInstance::*)() const) &IGESSolid_SolidInstance::IsBrep, "Tells if a SolidInstance is for a BREP Default is False");
cls_IGESSolid_SolidInstance.def("SetBrep", (void (IGESSolid_SolidInstance::*)(const Standard_Boolean)) &IGESSolid_SolidInstance::SetBrep, "Sets or unsets the Brep status (FormNumber = 1 else 0)", py::arg("brep"));
cls_IGESSolid_SolidInstance.def("Entity", (opencascade::handle<IGESData_IGESEntity> (IGESSolid_SolidInstance::*)() const) &IGESSolid_SolidInstance::Entity, "returns the solid entity");
cls_IGESSolid_SolidInstance.def_static("get_type_name_", (const char * (*)()) &IGESSolid_SolidInstance::get_type_name, "None");
cls_IGESSolid_SolidInstance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_SolidInstance::get_type_descriptor, "None");
cls_IGESSolid_SolidInstance.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_SolidInstance::*)() const) &IGESSolid_SolidInstance::DynamicType, "None");

// Enums

}