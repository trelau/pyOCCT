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
#include <Standard_TypeDef.hxx>
#include <Interface_CopyControl.hxx>
#include <Standard_Type.hxx>

void bind_Interface_CopyControl(py::module &mod){

py::class_<Interface_CopyControl, opencascade::handle<Interface_CopyControl>, Standard_Transient> cls_Interface_CopyControl(mod, "Interface_CopyControl", "This deferred class describes the services required by CopyTool to work. They are very simple and correspond basically to the management of an indexed map. But they can be provided by various classes which can control a Transfer. Each Starting Entity have at most one Result (Mapping one-one)");

// Fields

// Methods
cls_Interface_CopyControl.def("Clear", (void (Interface_CopyControl::*)()) &Interface_CopyControl::Clear, "Clears List of Copy Results. Gets Ready to begin another Copy Process.");
cls_Interface_CopyControl.def("Bind", (void (Interface_CopyControl::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &)) &Interface_CopyControl::Bind, "Bind a Result to a Starting Entity identified by its Number", py::arg("ent"), py::arg("res"));
cls_Interface_CopyControl.def("Search", (Standard_Boolean (Interface_CopyControl::*)(const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &) const) &Interface_CopyControl::Search, "Searches for the Result bound to a Startingf Entity identified by its Number. If Found, returns True and fills <res> Else, returns False and nullifies <res>", py::arg("ent"), py::arg("res"));
cls_Interface_CopyControl.def_static("get_type_name_", (const char * (*)()) &Interface_CopyControl::get_type_name, "None");
cls_Interface_CopyControl.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_CopyControl::get_type_descriptor, "None");
cls_Interface_CopyControl.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_CopyControl::*)() const) &Interface_CopyControl::DynamicType, "None");

// Enums

}