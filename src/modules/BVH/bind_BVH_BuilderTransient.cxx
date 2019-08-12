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
#include <BVH_Builder.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>

void bind_BVH_BuilderTransient(py::module &mod){

py::class_<BVH_BuilderTransient, opencascade::handle<BVH_BuilderTransient>, Standard_Transient> cls_BVH_BuilderTransient(mod, "BVH_BuilderTransient", "A non-template class for using as base for BVH_Builder (just to have a named base class).");

// Constructors

// Fields

// Methods
cls_BVH_BuilderTransient.def_static("get_type_name_", (const char * (*)()) &BVH_BuilderTransient::get_type_name, "None");
cls_BVH_BuilderTransient.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BVH_BuilderTransient::get_type_descriptor, "None");
cls_BVH_BuilderTransient.def("DynamicType", (const opencascade::handle<Standard_Type> & (BVH_BuilderTransient::*)() const) &BVH_BuilderTransient::DynamicType, "None");
cls_BVH_BuilderTransient.def("MaxTreeDepth", (Standard_Integer (BVH_BuilderTransient::*)() const) &BVH_BuilderTransient::MaxTreeDepth, "Returns the maximum depth of constructed BVH.");
cls_BVH_BuilderTransient.def("LeafNodeSize", (Standard_Integer (BVH_BuilderTransient::*)() const) &BVH_BuilderTransient::LeafNodeSize, "Returns the maximum number of sub-elements in the leaf.");

// Enums

}