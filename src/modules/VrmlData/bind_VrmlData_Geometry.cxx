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
#include <VrmlData_Node.hxx>
#include <VrmlData_Scene.hxx>
#include <Standard_Handle.hxx>
#include <TopoDS_TShape.hxx>
#include <Standard_TypeDef.hxx>
#include <VrmlData_Geometry.hxx>
#include <Standard_Type.hxx>

void bind_VrmlData_Geometry(py::module &mod){

py::class_<VrmlData_Geometry, opencascade::handle<VrmlData_Geometry>, VrmlData_Node> cls_VrmlData_Geometry(mod, "VrmlData_Geometry", "Implementation of the Geometry node. Contains the topological representation (TopoDS_Shell) of the VRML geometry");

// Fields

// Methods
cls_VrmlData_Geometry.def("TShape", (const opencascade::handle<TopoDS_TShape> & (VrmlData_Geometry::*)()) &VrmlData_Geometry::TShape, "Query the shape. This method checks the flag myIsModified; if True it should rebuild the shape presentation.");
cls_VrmlData_Geometry.def_static("get_type_name_", (const char * (*)()) &VrmlData_Geometry::get_type_name, "None");
cls_VrmlData_Geometry.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_Geometry::get_type_descriptor, "None");
cls_VrmlData_Geometry.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_Geometry::*)() const) &VrmlData_Geometry::DynamicType, "None");

// Enums

}