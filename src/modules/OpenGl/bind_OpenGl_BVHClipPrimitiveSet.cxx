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
#include <BVH_PrimitiveSet3d.hxx>
#include <Standard_Handle.hxx>
#include <OpenGl_BVHClipPrimitiveSet.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_BndBox3d.hxx>
#include <OpenGl_Structure.hxx>
#include <NCollection_IndexedMap.hxx>

void bind_OpenGl_BVHClipPrimitiveSet(py::module &mod){

/*
py::class_<OpenGl_BVHClipPrimitiveSet, std::unique_ptr<OpenGl_BVHClipPrimitiveSet, Deleter<OpenGl_BVHClipPrimitiveSet>>, BVH_PrimitiveSet3d> cls_OpenGl_BVHClipPrimitiveSet(mod, "OpenGl_BVHClipPrimitiveSet", "Set of OpenGl_Structures for building BVH tree.");

// Constructors
cls_OpenGl_BVHClipPrimitiveSet.def(py::init<>());

// Fields

// Methods
cls_OpenGl_BVHClipPrimitiveSet.def_static("get_type_name_", (const char * (*)()) &OpenGl_BVHClipPrimitiveSet::get_type_name, "None");
cls_OpenGl_BVHClipPrimitiveSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &OpenGl_BVHClipPrimitiveSet::get_type_descriptor, "None");
cls_OpenGl_BVHClipPrimitiveSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (OpenGl_BVHClipPrimitiveSet::*)() const) &OpenGl_BVHClipPrimitiveSet::DynamicType, "None");
cls_OpenGl_BVHClipPrimitiveSet.def("Size", (Standard_Integer (OpenGl_BVHClipPrimitiveSet::*)() const) &OpenGl_BVHClipPrimitiveSet::Size, "Returns total number of structures.");
cls_OpenGl_BVHClipPrimitiveSet.def("Box", (Graphic3d_BndBox3d (OpenGl_BVHClipPrimitiveSet::*)(const Standard_Integer) const) &OpenGl_BVHClipPrimitiveSet::Box, "Returns AABB of the structure.", py::arg("theIdx"));
cls_OpenGl_BVHClipPrimitiveSet.def("Center", (Standard_Real (OpenGl_BVHClipPrimitiveSet::*)(const Standard_Integer, const Standard_Integer) const) &OpenGl_BVHClipPrimitiveSet::Center, "Calculates center of the AABB along given axis.", py::arg("theIdx"), py::arg("theAxis"));
cls_OpenGl_BVHClipPrimitiveSet.def("Swap", (void (OpenGl_BVHClipPrimitiveSet::*)(const Standard_Integer, const Standard_Integer)) &OpenGl_BVHClipPrimitiveSet::Swap, "Swaps structures with the given indices.", py::arg("theIdx1"), py::arg("theIdx2"));
cls_OpenGl_BVHClipPrimitiveSet.def("Add", (Standard_Boolean (OpenGl_BVHClipPrimitiveSet::*)(const OpenGl_Structure *)) &OpenGl_BVHClipPrimitiveSet::Add, "Adds structure to the set.", py::arg("theStruct"));
cls_OpenGl_BVHClipPrimitiveSet.def("Remove", (Standard_Boolean (OpenGl_BVHClipPrimitiveSet::*)(const OpenGl_Structure *)) &OpenGl_BVHClipPrimitiveSet::Remove, "Removes the given structure from the set.", py::arg("theStruct"));
cls_OpenGl_BVHClipPrimitiveSet.def("Clear", (void (OpenGl_BVHClipPrimitiveSet::*)()) &OpenGl_BVHClipPrimitiveSet::Clear, "Cleans the whole primitive set.");
cls_OpenGl_BVHClipPrimitiveSet.def("GetStructureById", (const OpenGl_Structure * (OpenGl_BVHClipPrimitiveSet::*)(Standard_Integer)) &OpenGl_BVHClipPrimitiveSet::GetStructureById, "Returns the structure corresponding to the given ID.", py::arg("theId"));
cls_OpenGl_BVHClipPrimitiveSet.def("Structures", (const NCollection_IndexedMap<const OpenGl_Structure *> & (OpenGl_BVHClipPrimitiveSet::*)() const) &OpenGl_BVHClipPrimitiveSet::Structures, "Access directly a collection of structures.");

// Enums
*/

}