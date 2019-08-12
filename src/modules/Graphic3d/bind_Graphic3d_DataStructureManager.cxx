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
#include <Graphic3d_DataStructureManager.hxx>
#include <Standard_Type.hxx>

void bind_Graphic3d_DataStructureManager(py::module &mod){

py::class_<Graphic3d_DataStructureManager, opencascade::handle<Graphic3d_DataStructureManager>, Standard_Transient> cls_Graphic3d_DataStructureManager(mod, "Graphic3d_DataStructureManager", "This class allows the definition of a manager to which the graphic objects are associated. It allows them to be globally manipulated. It defines the global attributes.");

// Constructors

// Fields

// Methods
cls_Graphic3d_DataStructureManager.def_static("get_type_name_", (const char * (*)()) &Graphic3d_DataStructureManager::get_type_name, "None");
cls_Graphic3d_DataStructureManager.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_DataStructureManager::get_type_descriptor, "None");
cls_Graphic3d_DataStructureManager.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_DataStructureManager::*)() const) &Graphic3d_DataStructureManager::DynamicType, "None");

// Enums

}