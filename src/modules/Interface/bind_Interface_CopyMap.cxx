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
#include <Interface_CopyControl.hxx>
#include <Standard_Handle.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_CopyMap.hxx>
#include <Standard_Type.hxx>
#include <TColStd_Array1OfTransient.hxx>

void bind_Interface_CopyMap(py::module &mod){

py::class_<Interface_CopyMap, opencascade::handle<Interface_CopyMap>, Interface_CopyControl> cls_Interface_CopyMap(mod, "Interface_CopyMap", "Manages a Map for the need of single Transfers, such as Copies In such transfer, Starting Entities are read from a unique Starting Model, and each transferred Entity is bound to one and only one Result, which cannot be changed later.");

// Constructors
cls_Interface_CopyMap.def(py::init<const opencascade::handle<Interface_InterfaceModel> &>(), py::arg("amodel"));

// Fields

// Methods
cls_Interface_CopyMap.def("Clear", (void (Interface_CopyMap::*)()) &Interface_CopyMap::Clear, "Clears Transfer List. Gets Ready to begin another Transfer");
cls_Interface_CopyMap.def("Model", (opencascade::handle<Interface_InterfaceModel> (Interface_CopyMap::*)() const) &Interface_CopyMap::Model, "Returns the InterfaceModel used at Creation time");
cls_Interface_CopyMap.def("Bind", (void (Interface_CopyMap::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &)) &Interface_CopyMap::Bind, "Binds a Starting Entity identified by its Number <num> in the Starting Model, to a Result of Transfer <res>", py::arg("ent"), py::arg("res"));
cls_Interface_CopyMap.def("Search", (Standard_Boolean (Interface_CopyMap::*)(const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &) const) &Interface_CopyMap::Search, "Search for the result of a Starting Object (i.e. an Entity, identified by its Number <num> in the Starting Model) Returns True if a Result is Bound (and fills <res>) Returns False if no result is Bound (and nullifies <res>)", py::arg("ent"), py::arg("res"));
cls_Interface_CopyMap.def_static("get_type_name_", (const char * (*)()) &Interface_CopyMap::get_type_name, "None");
cls_Interface_CopyMap.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_CopyMap::get_type_descriptor, "None");
cls_Interface_CopyMap.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_CopyMap::*)() const) &Interface_CopyMap::DynamicType, "None");

// Enums

}