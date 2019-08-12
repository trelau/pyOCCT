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
#include <IGESSelect_UpdateFileName.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_UpdateFileName(py::module &mod){

py::class_<IGESSelect_UpdateFileName, opencascade::handle<IGESSelect_UpdateFileName>, IGESSelect_ModelModifier> cls_IGESSelect_UpdateFileName(mod, "IGESSelect_UpdateFileName", "Sets the File Name in Header to be the actual name of the file If new file name is unknown, the former one is kept Remark : this works well only when it is Applied and send time If it is run immediately, new file name is unknown and nothing is done The Selection of the Modifier is not used : it simply acts as a criterium to select IGES Files to touch up");

// Constructors
cls_IGESSelect_UpdateFileName.def(py::init<>());

// Fields

// Methods
cls_IGESSelect_UpdateFileName.def("Performing", (void (IGESSelect_UpdateFileName::*)(IFSelect_ContextModif &, const opencascade::handle<IGESData_IGESModel> &, Interface_CopyTool &) const) &IGESSelect_UpdateFileName::Performing, "Specific action : only <target> is used : the system Date is set to Global Section Item n0 18.", py::arg("ctx"), py::arg("target"), py::arg("TC"));
cls_IGESSelect_UpdateFileName.def("Label", (TCollection_AsciiString (IGESSelect_UpdateFileName::*)() const) &IGESSelect_UpdateFileName::Label, "Returns a text which is 'Updates IGES File Name to new current one'");
cls_IGESSelect_UpdateFileName.def_static("get_type_name_", (const char * (*)()) &IGESSelect_UpdateFileName::get_type_name, "None");
cls_IGESSelect_UpdateFileName.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_UpdateFileName::get_type_descriptor, "None");
cls_IGESSelect_UpdateFileName.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_UpdateFileName::*)() const) &IGESSelect_UpdateFileName::DynamicType, "None");

// Enums

}