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
#include <IGESSelect_UpdateCreationDate.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_UpdateCreationDate(py::module &mod){

py::class_<IGESSelect_UpdateCreationDate, opencascade::handle<IGESSelect_UpdateCreationDate>, IGESSelect_ModelModifier> cls_IGESSelect_UpdateCreationDate(mod, "IGESSelect_UpdateCreationDate", "Allows to Change the Creation Date indication in the Header (Global Section) of IGES File. It is taken from the operating system (time of application of the Modifier). The Selection of the Modifier is not used : it simply acts as a criterium to select IGES Files to touch up");

// Constructors
cls_IGESSelect_UpdateCreationDate.def(py::init<>());

// Fields

// Methods
cls_IGESSelect_UpdateCreationDate.def("Performing", (void (IGESSelect_UpdateCreationDate::*)(IFSelect_ContextModif &, const opencascade::handle<IGESData_IGESModel> &, Interface_CopyTool &) const) &IGESSelect_UpdateCreationDate::Performing, "Specific action : only <target> is used : the system Date is set to Global Section Item n0 18.", py::arg("ctx"), py::arg("target"), py::arg("TC"));
cls_IGESSelect_UpdateCreationDate.def("Label", (TCollection_AsciiString (IGESSelect_UpdateCreationDate::*)() const) &IGESSelect_UpdateCreationDate::Label, "Returns a text which is 'Update IGES Header Creation Date'");
cls_IGESSelect_UpdateCreationDate.def_static("get_type_name_", (const char * (*)()) &IGESSelect_UpdateCreationDate::get_type_name, "None");
cls_IGESSelect_UpdateCreationDate.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_UpdateCreationDate::get_type_descriptor, "None");
cls_IGESSelect_UpdateCreationDate.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_UpdateCreationDate::*)() const) &IGESSelect_UpdateCreationDate::DynamicType, "None");

// Enums

}