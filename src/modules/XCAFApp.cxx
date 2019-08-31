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
#include <TDocStd_Document.hxx>
#include <XCAFApp_Application.hxx>
#include <Standard_Type.hxx>

PYBIND11_MODULE(XCAFApp, mod) {

py::module::import("OCCT.TDocStd");
py::module::import("OCCT.Standard");

// CLASS: XCAFAPP_APPLICATION
py::class_<XCAFApp_Application, opencascade::handle<XCAFApp_Application>, TDocStd_Application> cls_XCAFApp_Application(mod, "XCAFApp_Application", "Implements an Application for the DECAF documents");

// Methods
cls_XCAFApp_Application.def("ResourcesName", (Standard_CString (XCAFApp_Application::*)()) &XCAFApp_Application::ResourcesName, "methods from TDocStd_Application ================================");
cls_XCAFApp_Application.def("InitDocument", (void (XCAFApp_Application::*)(const opencascade::handle<TDocStd_Document> &) const) &XCAFApp_Application::InitDocument, "Set XCAFDoc_DocumentTool attribute", py::arg("aDoc"));
cls_XCAFApp_Application.def_static("GetApplication_", (opencascade::handle<XCAFApp_Application> (*)()) &XCAFApp_Application::GetApplication, "Initializes (for the first time) and returns the static object (XCAFApp_Application) This is the only valid method to get XCAFApp_Application object, and it should be called at least once before any actions with documents in order to init application");
cls_XCAFApp_Application.def_static("get_type_name_", (const char * (*)()) &XCAFApp_Application::get_type_name, "None");
cls_XCAFApp_Application.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFApp_Application::get_type_descriptor, "None");
cls_XCAFApp_Application.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFApp_Application::*)() const) &XCAFApp_Application::DynamicType, "None");


}
