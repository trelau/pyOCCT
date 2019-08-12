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
#include <BVH_Object.hxx>
#include <Standard_Type.hxx>
#include <BVH_Properties.hxx>
#include <Standard_TypeDef.hxx>

void bind_BVH_ObjectTransient(py::module &mod){

py::class_<BVH_ObjectTransient, opencascade::handle<BVH_ObjectTransient>, Standard_Transient> cls_BVH_ObjectTransient(mod, "BVH_ObjectTransient", "A non-template class for using as base for BVH_Object (just to have a named base class).");

// Constructors

// Fields

// Methods
cls_BVH_ObjectTransient.def_static("get_type_name_", (const char * (*)()) &BVH_ObjectTransient::get_type_name, "None");
cls_BVH_ObjectTransient.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BVH_ObjectTransient::get_type_descriptor, "None");
cls_BVH_ObjectTransient.def("DynamicType", (const opencascade::handle<Standard_Type> & (BVH_ObjectTransient::*)() const) &BVH_ObjectTransient::DynamicType, "None");
cls_BVH_ObjectTransient.def("Properties", (const opencascade::handle<BVH_Properties> & (BVH_ObjectTransient::*)() const) &BVH_ObjectTransient::Properties, "Returns properties of the geometric object.");
cls_BVH_ObjectTransient.def("SetProperties", (void (BVH_ObjectTransient::*)(const opencascade::handle<BVH_Properties> &)) &BVH_ObjectTransient::SetProperties, "Sets properties of the geometric object.", py::arg("theProperties"));
cls_BVH_ObjectTransient.def("IsDirty", (Standard_Boolean (BVH_ObjectTransient::*)() const) &BVH_ObjectTransient::IsDirty, "Returns TRUE if object state should be updated.");
cls_BVH_ObjectTransient.def("MarkDirty", (void (BVH_ObjectTransient::*)()) &BVH_ObjectTransient::MarkDirty, "Marks object state as outdated (needs BVH rebuilding).");

// Enums

}