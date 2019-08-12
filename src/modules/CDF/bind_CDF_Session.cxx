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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <CDF_Session.hxx>
#include <CDF_Directory.hxx>
#include <CDF_Application.hxx>
#include <CDF_MetaDataDriver.hxx>
#include <Standard_Type.hxx>

void bind_CDF_Session(py::module &mod){

py::class_<CDF_Session, opencascade::handle<CDF_Session>, Standard_Transient> cls_CDF_Session(mod, "CDF_Session", "None");

// Constructors
cls_CDF_Session.def(py::init<>());

// Fields

// Methods
cls_CDF_Session.def_static("Exists_", (Standard_Boolean (*)()) &CDF_Session::Exists, "returns true if a session has been created.");
cls_CDF_Session.def_static("CurrentSession_", (opencascade::handle<CDF_Session> (*)()) &CDF_Session::CurrentSession, "returns the only one instance of Session that has been created.");
cls_CDF_Session.def("Directory", (opencascade::handle<CDF_Directory> (CDF_Session::*)() const) &CDF_Session::Directory, "returns the directory of the session;");
cls_CDF_Session.def("HasCurrentApplication", (Standard_Boolean (CDF_Session::*)() const) &CDF_Session::HasCurrentApplication, "None");
cls_CDF_Session.def("CurrentApplication", (opencascade::handle<CDF_Application> (CDF_Session::*)() const) &CDF_Session::CurrentApplication, "None");
cls_CDF_Session.def("SetCurrentApplication", (void (CDF_Session::*)(const opencascade::handle<CDF_Application> &)) &CDF_Session::SetCurrentApplication, "None", py::arg("anApplication"));
cls_CDF_Session.def("UnsetCurrentApplication", (void (CDF_Session::*)()) &CDF_Session::UnsetCurrentApplication, "None");
cls_CDF_Session.def("MetaDataDriver", (opencascade::handle<CDF_MetaDataDriver> (CDF_Session::*)() const) &CDF_Session::MetaDataDriver, "None");
cls_CDF_Session.def("LoadDriver", (void (CDF_Session::*)()) &CDF_Session::LoadDriver, "None");
cls_CDF_Session.def_static("get_type_name_", (const char * (*)()) &CDF_Session::get_type_name, "None");
cls_CDF_Session.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &CDF_Session::get_type_descriptor, "None");
cls_CDF_Session.def("DynamicType", (const opencascade::handle<Standard_Type> & (CDF_Session::*)() const) &CDF_Session::DynamicType, "None");

// Enums

}