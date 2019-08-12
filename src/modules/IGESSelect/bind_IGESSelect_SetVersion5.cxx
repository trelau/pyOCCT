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
#include <IGESSelect_SetVersion5.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_SetVersion5(py::module &mod){

py::class_<IGESSelect_SetVersion5, opencascade::handle<IGESSelect_SetVersion5>, IGESSelect_ModelModifier> cls_IGESSelect_SetVersion5(mod, "IGESSelect_SetVersion5", "Sets IGES Version (coded in global parameter 23) to be at least IGES 5.1 . If it is older, it is set to IGES 5.1, and LastChangeDate (new Global n0 25) is added (current time) Else, it does nothing (i.e. changes neither IGES Version nor LastChangeDate)");

// Constructors
cls_IGESSelect_SetVersion5.def(py::init<>());

// Fields

// Methods
cls_IGESSelect_SetVersion5.def("Performing", (void (IGESSelect_SetVersion5::*)(IFSelect_ContextModif &, const opencascade::handle<IGESData_IGESModel> &, Interface_CopyTool &) const) &IGESSelect_SetVersion5::Performing, "Specific action : only <target> is used : IGES Version (coded) is upgraded to 5.1 if it is older, and it this case the new global parameter 25 (LastChangeDate) is set to current time", py::arg("ctx"), py::arg("target"), py::arg("TC"));
cls_IGESSelect_SetVersion5.def("Label", (TCollection_AsciiString (IGESSelect_SetVersion5::*)() const) &IGESSelect_SetVersion5::Label, "Returns a text which is 'Update IGES Version to 5.1'");
cls_IGESSelect_SetVersion5.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SetVersion5::get_type_name, "None");
cls_IGESSelect_SetVersion5.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SetVersion5::get_type_descriptor, "None");
cls_IGESSelect_SetVersion5.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SetVersion5::*)() const) &IGESSelect_SetVersion5::DynamicType, "None");

// Enums

}