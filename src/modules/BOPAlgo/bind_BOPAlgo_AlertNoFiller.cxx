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
#include <Message_Alert.hxx>
#include <Standard_Handle.hxx>
#include <BOPAlgo_Alerts.hxx>
#include <Standard_Type.hxx>

void bind_BOPAlgo_AlertNoFiller(py::module &mod){

py::class_<BOPAlgo_AlertNoFiller, opencascade::handle<BOPAlgo_AlertNoFiller>, Message_Alert> cls_BOPAlgo_AlertNoFiller(mod, "BOPAlgo_AlertNoFiller", "The Pave Filler (the intersection tool) has not been created");

// Constructors

// Fields

// Methods
cls_BOPAlgo_AlertNoFiller.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertNoFiller::get_type_name, "None");
cls_BOPAlgo_AlertNoFiller.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertNoFiller::get_type_descriptor, "None");
cls_BOPAlgo_AlertNoFiller.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertNoFiller::*)() const) &BOPAlgo_AlertNoFiller::DynamicType, "None");

// Enums

}