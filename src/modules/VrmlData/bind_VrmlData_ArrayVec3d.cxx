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
#include <NCollection_SparseArrayBase.hxx>
#include <gp_XYZ.hxx>
#include <Standard_TypeDef.hxx>
#include <VrmlData_ErrorStatus.hxx>
#include <VrmlData_InBuffer.hxx>
#include <Standard_Handle.hxx>
#include <VrmlData_ArrayVec3d.hxx>
#include <Standard_Type.hxx>

void bind_VrmlData_ArrayVec3d(py::module &mod){

py::class_<VrmlData_ArrayVec3d, opencascade::handle<VrmlData_ArrayVec3d>, VrmlData_Node> cls_VrmlData_ArrayVec3d(mod, "VrmlData_ArrayVec3d", "Implementatioon of basic node for Coordinate, Normal and Color (array of triplets).");

// Fields

// Methods
cls_VrmlData_ArrayVec3d.def("Length", (Standard_Size (VrmlData_ArrayVec3d::*)() const) &VrmlData_ArrayVec3d::Length, "Query the number of vectors");
cls_VrmlData_ArrayVec3d.def("Values", (const gp_XYZ * (VrmlData_ArrayVec3d::*)() const) &VrmlData_ArrayVec3d::Values, "Query the array");
cls_VrmlData_ArrayVec3d.def("AllocateValues", (Standard_Boolean (VrmlData_ArrayVec3d::*)(const Standard_Size)) &VrmlData_ArrayVec3d::AllocateValues, "Create a data array and assign the field myArray.", py::arg("theLength"));
cls_VrmlData_ArrayVec3d.def("SetValues", (void (VrmlData_ArrayVec3d::*)(const Standard_Size, const gp_XYZ *)) &VrmlData_ArrayVec3d::SetValues, "Set the array data", py::arg("nValues"), py::arg("arrValues"));
cls_VrmlData_ArrayVec3d.def("ReadArray", (VrmlData_ErrorStatus (VrmlData_ArrayVec3d::*)(VrmlData_InBuffer &, const char *, const Standard_Boolean)) &VrmlData_ArrayVec3d::ReadArray, "Read the Node from input stream.", py::arg("theBuffer"), py::arg("theName"), py::arg("isScale"));
cls_VrmlData_ArrayVec3d.def("WriteArray", (VrmlData_ErrorStatus (VrmlData_ArrayVec3d::*)(const char *, const Standard_Boolean) const) &VrmlData_ArrayVec3d::WriteArray, "Write the Node to the output stream currently opened in Scene.", py::arg("theName"), py::arg("isScale"));
cls_VrmlData_ArrayVec3d.def("IsDefault", (Standard_Boolean (VrmlData_ArrayVec3d::*)() const) &VrmlData_ArrayVec3d::IsDefault, "Returns True if the node is default, so that it should not be written.");
cls_VrmlData_ArrayVec3d.def_static("get_type_name_", (const char * (*)()) &VrmlData_ArrayVec3d::get_type_name, "None");
cls_VrmlData_ArrayVec3d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_ArrayVec3d::get_type_descriptor, "None");
cls_VrmlData_ArrayVec3d.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_ArrayVec3d::*)() const) &VrmlData_ArrayVec3d::DynamicType, "None");

// Enums

}