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
#include <Select3D_SensitiveFace.hxx>
#include <Standard_Handle.hxx>
#include <SelectBasics_EntityOwner.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <Select3D_TypeOfSensitivity.hxx>
#include <MeshVS_SensitiveFace.hxx>
#include <Standard_Type.hxx>
#include <gp_Pnt.hxx>

void bind_MeshVS_SensitiveFace(py::module &mod){

py::class_<MeshVS_SensitiveFace, opencascade::handle<MeshVS_SensitiveFace>, Select3D_SensitiveFace> cls_MeshVS_SensitiveFace(mod, "MeshVS_SensitiveFace", "This class provides custom sensitive face, which will be selected if it center is in rectangle.");

// Constructors
cls_MeshVS_SensitiveFace.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const TColgp_Array1OfPnt &>(), py::arg("theOwner"), py::arg("thePoints"));
cls_MeshVS_SensitiveFace.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const TColgp_Array1OfPnt &, const Select3D_TypeOfSensitivity>(), py::arg("theOwner"), py::arg("thePoints"), py::arg("theSensType"));

// Fields

// Methods
cls_MeshVS_SensitiveFace.def_static("get_type_name_", (const char * (*)()) &MeshVS_SensitiveFace::get_type_name, "None");
cls_MeshVS_SensitiveFace.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_SensitiveFace::get_type_descriptor, "None");
cls_MeshVS_SensitiveFace.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_SensitiveFace::*)() const) &MeshVS_SensitiveFace::DynamicType, "None");

// Enums

}