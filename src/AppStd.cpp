/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <TDocStd_Application.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <AppStd_Application.hxx>

PYBIND11_MODULE(AppStd, mod) {

	// IMPORT
	py::module::import("OCCT.TDocStd");
	py::module::import("OCCT.Standard");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\AppStd_Application.hxx
	py::class_<AppStd_Application, opencascade::handle<AppStd_Application>, TDocStd_Application> cls_AppStd_Application(mod, "AppStd_Application", "Legacy class defining resources name for standard OCAF documents");
	cls_AppStd_Application.def("ResourcesName", (Standard_CString (AppStd_Application::*)()) &AppStd_Application::ResourcesName, "returns the file name which contains application resources");
	cls_AppStd_Application.def_static("get_type_name_", (const char * (*)()) &AppStd_Application::get_type_name, "None");
	cls_AppStd_Application.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AppStd_Application::get_type_descriptor, "None");
	cls_AppStd_Application.def("DynamicType", (const opencascade::handle<Standard_Type> & (AppStd_Application::*)() const ) &AppStd_Application::DynamicType, "None");


}
