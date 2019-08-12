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
#include <TDocStd_Application.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <AppStdL_Application.hxx>
#include <Standard_Type.hxx>

void bind_AppStdL_Application(py::module &mod){

py::class_<AppStdL_Application, opencascade::handle<AppStdL_Application>, TDocStd_Application> cls_AppStdL_Application(mod, "AppStdL_Application", "Legacy class defining resources name for lite OCAF documents");

// Constructors

// Fields

// Methods
cls_AppStdL_Application.def("ResourcesName", (Standard_CString (AppStdL_Application::*)()) &AppStdL_Application::ResourcesName, "returns the file name which contains application resources");
cls_AppStdL_Application.def_static("get_type_name_", (const char * (*)()) &AppStdL_Application::get_type_name, "None");
cls_AppStdL_Application.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AppStdL_Application::get_type_descriptor, "None");
cls_AppStdL_Application.def("DynamicType", (const opencascade::handle<Standard_Type> & (AppStdL_Application::*)() const) &AppStdL_Application::DynamicType, "None");

// Enums

}