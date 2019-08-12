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
#include <Standard_Handle.hxx>
#include <TObj_Application.hxx>
#include <Message_Messenger.hxx>
#include <Standard_TypeDef.hxx>
#include <TDocStd_Document.hxx>
#include <TCollection_ExtendedString.hxx>
#include <Message_Gravity.hxx>
#include <Standard_Type.hxx>

void bind_TObj_Application(py::module &mod){

py::class_<TObj_Application, opencascade::handle<TObj_Application>, TDocStd_Application> cls_TObj_Application(mod, "TObj_Application", "This is a base class for OCAF based TObj models with declared virtual methods");

// Constructors

// Fields

// Methods
cls_TObj_Application.def_static("GetInstance_", (opencascade::handle<TObj_Application> (*)()) &TObj_Application::GetInstance, "Returns static instance of the application");
cls_TObj_Application.def("Messenger", (opencascade::handle<Message_Messenger> & (TObj_Application::*)()) &TObj_Application::Messenger, "Returns reference to associated messenger handle");
cls_TObj_Application.def("SaveDocument", (Standard_Boolean (TObj_Application::*)(const opencascade::handle<TDocStd_Document> &, const TCollection_ExtendedString &)) &TObj_Application::SaveDocument, "Saving the OCAF document to a file", py::arg("theSourceDoc"), py::arg("theTargetFile"));
cls_TObj_Application.def("LoadDocument", (Standard_Boolean (TObj_Application::*)(const TCollection_ExtendedString &, opencascade::handle<TDocStd_Document> &)) &TObj_Application::LoadDocument, "Loading the OCAF document from a file", py::arg("theSourceFile"), py::arg("theTargetDoc"));
cls_TObj_Application.def("CreateNewDocument", (Standard_Boolean (TObj_Application::*)(opencascade::handle<TDocStd_Document> &, const TCollection_ExtendedString &)) &TObj_Application::CreateNewDocument, "Create the OCAF document from scratch", py::arg("theDoc"), py::arg("theFormat"));
cls_TObj_Application.def("ErrorMessage", (void (TObj_Application::*)(const TCollection_ExtendedString &, const Message_Gravity)) &TObj_Application::ErrorMessage, "Signal error during Load or Save Default imiplementation is empty", py::arg("theMsg"), py::arg("theLevel"));
cls_TObj_Application.def("ErrorMessage", (void (TObj_Application::*)(const TCollection_ExtendedString &)) &TObj_Application::ErrorMessage, "Signal error during Load or Save Default imiplementation invoke previous declaration with 0", py::arg("theMsg"));
cls_TObj_Application.def("SetVerbose", (void (TObj_Application::*)(const Standard_Boolean)) &TObj_Application::SetVerbose, "Sets the verbose flag, meaning that load/save models should show CPU and elapsed times", py::arg("isVerbose"));
cls_TObj_Application.def("IsVerbose", (Standard_Boolean (TObj_Application::*)() const) &TObj_Application::IsVerbose, "Returns the verbose flag");
cls_TObj_Application.def("ResourcesName", (Standard_CString (TObj_Application::*)()) &TObj_Application::ResourcesName, "Return name of resource (i.e. 'TObj')");
cls_TObj_Application.def_static("get_type_name_", (const char * (*)()) &TObj_Application::get_type_name, "None");
cls_TObj_Application.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TObj_Application::get_type_descriptor, "None");
cls_TObj_Application.def("DynamicType", (const opencascade::handle<Standard_Type> & (TObj_Application::*)() const) &TObj_Application::DynamicType, "None");

// Enums

}