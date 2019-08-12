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
#include <Interface_Check.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_ReportEntity.hxx>
#include <Standard_Type.hxx>

void bind_Interface_ReportEntity(py::module &mod){

py::class_<Interface_ReportEntity, opencascade::handle<Interface_ReportEntity>, Standard_Transient> cls_Interface_ReportEntity(mod, "Interface_ReportEntity", "A ReportEntity is produced to aknowledge and memorize the binding between a Check and an Entity. The Check can bring Fails (+ Warnings if any), or only Warnings. If it is empty, the Report Entity is for an Unknown Entity.");

// Constructors
cls_Interface_ReportEntity.def(py::init<const opencascade::handle<Standard_Transient> &>(), py::arg("unknown"));
cls_Interface_ReportEntity.def(py::init<const opencascade::handle<Interface_Check> &, const opencascade::handle<Standard_Transient> &>(), py::arg("acheck"), py::arg("concerned"));

// Fields

// Methods
cls_Interface_ReportEntity.def("SetContent", (void (Interface_ReportEntity::*)(const opencascade::handle<Standard_Transient> &)) &Interface_ReportEntity::SetContent, "Sets a Content : it brings non interpreted data which belong to the Concerned Entity. It can be empty then loaded later. Remark that for an Unknown Entity, Content is set by Create.", py::arg("content"));
cls_Interface_ReportEntity.def("Check", (const opencascade::handle<Interface_Check> & (Interface_ReportEntity::*)() const) &Interface_ReportEntity::Check, "Returns the stored Check");
cls_Interface_ReportEntity.def("CCheck", (opencascade::handle<Interface_Check> & (Interface_ReportEntity::*)()) &Interface_ReportEntity::CCheck, "Returns the stored Check in order to change it");
cls_Interface_ReportEntity.def("Concerned", (opencascade::handle<Standard_Transient> (Interface_ReportEntity::*)() const) &Interface_ReportEntity::Concerned, "Returns the stored Concerned Entity. It equates the Content in the case of an Unknown Entity");
cls_Interface_ReportEntity.def("HasContent", (Standard_Boolean (Interface_ReportEntity::*)() const) &Interface_ReportEntity::HasContent, "Returns True if a Content is stored (it can equate Concerned)");
cls_Interface_ReportEntity.def("HasNewContent", (Standard_Boolean (Interface_ReportEntity::*)() const) &Interface_ReportEntity::HasNewContent, "Returns True if a Content is stored AND differs from Concerned (i.e. redefines content) : used when Concerned could not be loaded");
cls_Interface_ReportEntity.def("Content", (opencascade::handle<Standard_Transient> (Interface_ReportEntity::*)() const) &Interface_ReportEntity::Content, "Returns the stored Content, or a Null Handle Remark that it must be an 'Unknown Entity' suitable for the norm of the containing Model");
cls_Interface_ReportEntity.def("IsError", (Standard_Boolean (Interface_ReportEntity::*)() const) &Interface_ReportEntity::IsError, "Returns True for an Error Entity, i.e. if the Check brings at least one Fail message");
cls_Interface_ReportEntity.def("IsUnknown", (Standard_Boolean (Interface_ReportEntity::*)() const) &Interface_ReportEntity::IsUnknown, "Returns True for an Unknown Entity, i,e. if the Check is empty and Concerned equates Content");
cls_Interface_ReportEntity.def_static("get_type_name_", (const char * (*)()) &Interface_ReportEntity::get_type_name, "None");
cls_Interface_ReportEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_ReportEntity::get_type_descriptor, "None");
cls_Interface_ReportEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_ReportEntity::*)() const) &Interface_ReportEntity::DynamicType, "None");

// Enums

}