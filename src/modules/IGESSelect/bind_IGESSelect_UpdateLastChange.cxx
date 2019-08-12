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
#include <IGESSelect_UpdateLastChange.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_UpdateLastChange(py::module &mod){

py::class_<IGESSelect_UpdateLastChange, opencascade::handle<IGESSelect_UpdateLastChange>, IGESSelect_ModelModifier> cls_IGESSelect_UpdateLastChange(mod, "IGESSelect_UpdateLastChange", "Allows to Change the Last Change Date indication in the Header (Global Section) of IGES File. It is taken from the operating system (time of application of the Modifier). The Selection of the Modifier is not used : it simply acts as a criterium to select IGES Files to touch up. Remark : IGES Models noted as version before IGES 5.1 are in addition changed to 5.1");

// Constructors
cls_IGESSelect_UpdateLastChange.def(py::init<>());

// Fields

// Methods
cls_IGESSelect_UpdateLastChange.def("Performing", (void (IGESSelect_UpdateLastChange::*)(IFSelect_ContextModif &, const opencascade::handle<IGESData_IGESModel> &, Interface_CopyTool &) const) &IGESSelect_UpdateLastChange::Performing, "Specific action : only <target> is used : the system Date is set to Global Section Item n0 25. Also sets IGES Version (Item n0 23) to IGES5 if it was older.", py::arg("ctx"), py::arg("target"), py::arg("TC"));
cls_IGESSelect_UpdateLastChange.def("Label", (TCollection_AsciiString (IGESSelect_UpdateLastChange::*)() const) &IGESSelect_UpdateLastChange::Label, "Returns a text which is 'Update IGES Header Last Change Date'");
cls_IGESSelect_UpdateLastChange.def_static("get_type_name_", (const char * (*)()) &IGESSelect_UpdateLastChange::get_type_name, "None");
cls_IGESSelect_UpdateLastChange.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_UpdateLastChange::get_type_descriptor, "None");
cls_IGESSelect_UpdateLastChange.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_UpdateLastChange::*)() const) &IGESSelect_UpdateLastChange::DynamicType, "None");

// Enums

}