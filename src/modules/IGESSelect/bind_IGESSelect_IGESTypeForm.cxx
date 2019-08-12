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
#include <IFSelect_Signature.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <IGESSelect_IGESTypeForm.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_IGESTypeForm(py::module &mod){

py::class_<IGESSelect_IGESTypeForm, opencascade::handle<IGESSelect_IGESTypeForm>, IFSelect_Signature> cls_IGESSelect_IGESTypeForm(mod, "IGESSelect_IGESTypeForm", "IGESTypeForm is a Signature specific to the IGES Norm : it gives the signature under two possible forms : - as 'mmm nnn', with 'mmm' as IGES Type Number, and 'nnn' as IGES From Number (even if = 0) [Default] - as 'mmm' alone, which gives only the IGES Type Number");

// Constructors
cls_IGESSelect_IGESTypeForm.def(py::init<>());
cls_IGESSelect_IGESTypeForm.def(py::init<const Standard_Boolean>(), py::arg("withform"));

// Fields

// Methods
cls_IGESSelect_IGESTypeForm.def("SetForm", (void (IGESSelect_IGESTypeForm::*)(const Standard_Boolean)) &IGESSelect_IGESTypeForm::SetForm, "Changes the mode for giving the Form Number", py::arg("withform"));
cls_IGESSelect_IGESTypeForm.def("Value", (Standard_CString (IGESSelect_IGESTypeForm::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IGESSelect_IGESTypeForm::Value, "Returns the signature for IGES, 'mmm nnn' or 'mmm' according creation choice (Type & Form or Type only)", py::arg("ent"), py::arg("model"));
cls_IGESSelect_IGESTypeForm.def_static("get_type_name_", (const char * (*)()) &IGESSelect_IGESTypeForm::get_type_name, "None");
cls_IGESSelect_IGESTypeForm.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_IGESTypeForm::get_type_descriptor, "None");
cls_IGESSelect_IGESTypeForm.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_IGESTypeForm::*)() const) &IGESSelect_IGESTypeForm::DynamicType, "None");

// Enums

}