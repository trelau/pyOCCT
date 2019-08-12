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
#include <IFSelect_Modifier.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_EditForm.hxx>
#include <IFSelect_ContextModif.hxx>
#include <Interface_InterfaceModel.hxx>
#include <Interface_Protocol.hxx>
#include <Interface_CopyTool.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_ModifEditForm.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_ModifEditForm(py::module &mod){

py::class_<IFSelect_ModifEditForm, opencascade::handle<IFSelect_ModifEditForm>, IFSelect_Modifier> cls_IFSelect_ModifEditForm(mod, "IFSelect_ModifEditForm", "This modifier applies an EditForm on the entities selected");

// Constructors
cls_IFSelect_ModifEditForm.def(py::init<const opencascade::handle<IFSelect_EditForm> &>(), py::arg("editform"));

// Fields

// Methods
cls_IFSelect_ModifEditForm.def("EditForm", (opencascade::handle<IFSelect_EditForm> (IFSelect_ModifEditForm::*)() const) &IFSelect_ModifEditForm::EditForm, "Returns the EditForm");
cls_IFSelect_ModifEditForm.def("Perform", (void (IFSelect_ModifEditForm::*)(IFSelect_ContextModif &, const opencascade::handle<Interface_InterfaceModel> &, const opencascade::handle<Interface_Protocol> &, Interface_CopyTool &) const) &IFSelect_ModifEditForm::Perform, "Acts by applying an EditForm to entities, selected or all model", py::arg("ctx"), py::arg("target"), py::arg("protocol"), py::arg("TC"));
cls_IFSelect_ModifEditForm.def("Label", (TCollection_AsciiString (IFSelect_ModifEditForm::*)() const) &IFSelect_ModifEditForm::Label, "Returns Label as 'Apply EditForm <+ label of EditForm>'");
cls_IFSelect_ModifEditForm.def_static("get_type_name_", (const char * (*)()) &IFSelect_ModifEditForm::get_type_name, "None");
cls_IFSelect_ModifEditForm.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_ModifEditForm::get_type_descriptor, "None");
cls_IFSelect_ModifEditForm.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_ModifEditForm::*)() const) &IFSelect_ModifEditForm::DynamicType, "None");

// Enums

}