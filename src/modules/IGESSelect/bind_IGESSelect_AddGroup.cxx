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
#include <IGESSelect_ModelModifier.hxx>
#include <IFSelect_ContextModif.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESModel.hxx>
#include <Interface_CopyTool.hxx>
#include <TCollection_AsciiString.hxx>
#include <IGESSelect_AddGroup.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_AddGroup(py::module &mod){

py::class_<IGESSelect_AddGroup, opencascade::handle<IGESSelect_AddGroup>, IGESSelect_ModelModifier> cls_IGESSelect_AddGroup(mod, "IGESSelect_AddGroup", "Adds a Group to contain the entities designated by the Selection. If no Selection is given, nothing is done");

// Constructors
cls_IGESSelect_AddGroup.def(py::init<>());

// Fields

// Methods
cls_IGESSelect_AddGroup.def("Performing", (void (IGESSelect_AddGroup::*)(IFSelect_ContextModif &, const opencascade::handle<IGESData_IGESModel> &, Interface_CopyTool &) const) &IGESSelect_AddGroup::Performing, "Specific action : Adds a new group", py::arg("ctx"), py::arg("target"), py::arg("TC"));
cls_IGESSelect_AddGroup.def("Label", (TCollection_AsciiString (IGESSelect_AddGroup::*)() const) &IGESSelect_AddGroup::Label, "Returns a text which is 'Add Group'");
cls_IGESSelect_AddGroup.def_static("get_type_name_", (const char * (*)()) &IGESSelect_AddGroup::get_type_name, "None");
cls_IGESSelect_AddGroup.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_AddGroup::get_type_descriptor, "None");
cls_IGESSelect_AddGroup.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_AddGroup::*)() const) &IGESSelect_AddGroup::DynamicType, "None");

// Enums

}