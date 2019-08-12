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
#include <MeshVS_DataSource.hxx>
#include <Standard_Handle.hxx>
#include <MeshVS_HArray1OfSequenceOfInteger.hxx>
#include <Standard_TypeDef.hxx>
#include <MeshVS_DataSource3D.hxx>
#include <Standard_Type.hxx>
#include <MeshVS_DataMapOfHArray1OfSequenceOfInteger.hxx>

void bind_MeshVS_DataSource3D(py::module &mod){

py::class_<MeshVS_DataSource3D, opencascade::handle<MeshVS_DataSource3D>, MeshVS_DataSource> cls_MeshVS_DataSource3D(mod, "MeshVS_DataSource3D", "None");

// Fields

// Methods
cls_MeshVS_DataSource3D.def("GetPrismTopology", (opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> (MeshVS_DataSource3D::*)(const Standard_Integer) const) &MeshVS_DataSource3D::GetPrismTopology, "None", py::arg("BasePoints"));
cls_MeshVS_DataSource3D.def("GetPyramidTopology", (opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> (MeshVS_DataSource3D::*)(const Standard_Integer) const) &MeshVS_DataSource3D::GetPyramidTopology, "None", py::arg("BasePoints"));
cls_MeshVS_DataSource3D.def_static("CreatePrismTopology_", (opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> (*)(const Standard_Integer)) &MeshVS_DataSource3D::CreatePrismTopology, "None", py::arg("BasePoints"));
cls_MeshVS_DataSource3D.def_static("CreatePyramidTopology_", (opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> (*)(const Standard_Integer)) &MeshVS_DataSource3D::CreatePyramidTopology, "None", py::arg("BasePoints"));
cls_MeshVS_DataSource3D.def_static("get_type_name_", (const char * (*)()) &MeshVS_DataSource3D::get_type_name, "None");
cls_MeshVS_DataSource3D.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MeshVS_DataSource3D::get_type_descriptor, "None");
cls_MeshVS_DataSource3D.def("DynamicType", (const opencascade::handle<Standard_Type> & (MeshVS_DataSource3D::*)() const) &MeshVS_DataSource3D::DynamicType, "None");

// Enums

}