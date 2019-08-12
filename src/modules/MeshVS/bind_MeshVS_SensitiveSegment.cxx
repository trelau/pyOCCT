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
#include <Select3D_SensitiveSegment.hxx>
#include <Standard_Handle.hxx>
#include <SelectBasics_EntityOwner.hxx>
#include <gp_Pnt.hxx>
#include <MeshVS_SensitiveSegment.hxx>
#include <Standard_Type.hxx>

void bind_MeshVS_SensitiveSegment(py::module &mod){

py::class_<MeshVS_SensitiveSegment, opencascade::handle<MeshVS_SensitiveSegment>, Select3D_SensitiveSegment> cls_MeshVS_SensitiveSegment(mod, "MeshVS_SensitiveSegment", "This class provides custom sensitive face, which will be selected if it center is in rectangle.");

// Constructors
cls_MeshVS_SensitiveSegment.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const gp_Pnt &, const gp_Pnt &>(), py::arg("theOwner"), py::arg("theFirstPnt"), py::arg("theLastPnt"));

// Fields

// Methods
cls_MeshVS_SensitiveSegment.def_static("get_type_name_", (const char * (*)()) &MeshVS_SensitiveSegment::get_type_name, "None");
cls_MeshVS_SensitiveSegment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_SensitiveSegment::get_type_descriptor, "None");
cls_MeshVS_SensitiveSegment.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_SensitiveSegment::*)() const) &MeshVS_SensitiveSegment::DynamicType, "None");

// Enums

}