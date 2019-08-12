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
#include <Standard_TypeDef.hxx>
#include <TColStd_PackedMapOfInteger.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HPackedMapOfInteger.hxx>
#include <Standard_Type.hxx>

void bind_TColStd_HPackedMapOfInteger(py::module &mod){

py::class_<TColStd_HPackedMapOfInteger, opencascade::handle<TColStd_HPackedMapOfInteger>, Standard_Transient> cls_TColStd_HPackedMapOfInteger(mod, "TColStd_HPackedMapOfInteger", "Extension of TColStd_PackedMapOfInteger class to be manipulated by handle.");

// Constructors
cls_TColStd_HPackedMapOfInteger.def(py::init<>());
cls_TColStd_HPackedMapOfInteger.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
cls_TColStd_HPackedMapOfInteger.def(py::init<const TColStd_PackedMapOfInteger &>(), py::arg("theOther"));

// Fields

// Methods
cls_TColStd_HPackedMapOfInteger.def("Map", (const TColStd_PackedMapOfInteger & (TColStd_HPackedMapOfInteger::*)() const) &TColStd_HPackedMapOfInteger::Map, "Access to the map");
cls_TColStd_HPackedMapOfInteger.def("ChangeMap", (TColStd_PackedMapOfInteger & (TColStd_HPackedMapOfInteger::*)()) &TColStd_HPackedMapOfInteger::ChangeMap, "Access to the map for modification");
cls_TColStd_HPackedMapOfInteger.def_static("get_type_name_", (const char * (*)()) &TColStd_HPackedMapOfInteger::get_type_name, "None");
cls_TColStd_HPackedMapOfInteger.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColStd_HPackedMapOfInteger::get_type_descriptor, "None");
cls_TColStd_HPackedMapOfInteger.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColStd_HPackedMapOfInteger::*)() const) &TColStd_HPackedMapOfInteger::DynamicType, "None");

// Enums

}