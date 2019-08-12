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
#include <gp_GTrsf.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_TransfEntity.hxx>
#include <Standard_Type.hxx>

void bind_IGESData_TransfEntity(py::module &mod){

py::class_<IGESData_TransfEntity, opencascade::handle<IGESData_TransfEntity>, IGESData_IGESEntity> cls_IGESData_TransfEntity(mod, "IGESData_TransfEntity", "defines required type for Transf in directory part an effective Transf entity must inherits it");

// Fields

// Methods
cls_IGESData_TransfEntity.def("Value", (gp_GTrsf (IGESData_TransfEntity::*)() const) &IGESData_TransfEntity::Value, "gives value of the transformation, as a GTrsf To be defined by an effective class of Transformation Entity Warning : Must take in account Composition : if a TransfEntity has in its Directory Part, a Transf, this means that it is Compound, Value must return the global result");
cls_IGESData_TransfEntity.def_static("get_type_name_", (const char * (*)()) &IGESData_TransfEntity::get_type_name, "None");
cls_IGESData_TransfEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESData_TransfEntity::get_type_descriptor, "None");
cls_IGESData_TransfEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESData_TransfEntity::*)() const) &IGESData_TransfEntity::DynamicType, "None");

// Enums

}