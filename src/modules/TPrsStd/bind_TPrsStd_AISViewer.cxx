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
#include <TDF_Attribute.hxx>
#include <Standard_GUID.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_Label.hxx>
#include <Standard_Handle.hxx>
#include <TPrsStd_AISViewer.hxx>
#include <AIS_InteractiveContext.hxx>
#include <V3d_Viewer.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_Type.hxx>

void bind_TPrsStd_AISViewer(py::module &mod){

py::class_<TPrsStd_AISViewer, opencascade::handle<TPrsStd_AISViewer>, TDF_Attribute> cls_TPrsStd_AISViewer(mod, "TPrsStd_AISViewer", "The groundwork to define an interactive viewer attribute. This attribute stores an interactive context at the root label. You can only have one instance of this class per data framework.");

// Constructors
cls_TPrsStd_AISViewer.def(py::init<>());

// Fields

// Methods
cls_TPrsStd_AISViewer.def_static("GetID_", (const Standard_GUID & (*)()) &TPrsStd_AISViewer::GetID, "class methods =============");
cls_TPrsStd_AISViewer.def_static("Has_", (Standard_Boolean (*)(const TDF_Label &)) &TPrsStd_AISViewer::Has, "returns True if there is an AISViewer attribute in <acces> Data Framework.", py::arg("acces"));
cls_TPrsStd_AISViewer.def_static("New_", (opencascade::handle<TPrsStd_AISViewer> (*)(const TDF_Label &, const opencascade::handle<AIS_InteractiveContext> &)) &TPrsStd_AISViewer::New, "create and set an AISViewer at. Raise an exception if Has.", py::arg("access"), py::arg("selector"));
cls_TPrsStd_AISViewer.def_static("New_", (opencascade::handle<TPrsStd_AISViewer> (*)(const TDF_Label &, const opencascade::handle<V3d_Viewer> &)) &TPrsStd_AISViewer::New, "create and set an AISAttribute at root label. The interactive context is build. Raise an exception if Has.", py::arg("acces"), py::arg("viewer"));
cls_TPrsStd_AISViewer.def_static("Find_", (Standard_Boolean (*)(const TDF_Label &, opencascade::handle<TPrsStd_AISViewer> &)) &TPrsStd_AISViewer::Find, "Finds the viewer attribute at the label access, the root of the data framework. Calling this function can be used to initialize an AIS viewer", py::arg("acces"), py::arg("A"));
cls_TPrsStd_AISViewer.def_static("Find_", (Standard_Boolean (*)(const TDF_Label &, opencascade::handle<AIS_InteractiveContext> &)) &TPrsStd_AISViewer::Find, "None", py::arg("acces"), py::arg("IC"));
cls_TPrsStd_AISViewer.def_static("Find_", (Standard_Boolean (*)(const TDF_Label &, opencascade::handle<V3d_Viewer> &)) &TPrsStd_AISViewer::Find, "None", py::arg("acces"), py::arg("V"));
cls_TPrsStd_AISViewer.def_static("Update_", (void (*)(const TDF_Label &)) &TPrsStd_AISViewer::Update, "AISViewer methods =================", py::arg("acces"));
cls_TPrsStd_AISViewer.def("Update", (void (TPrsStd_AISViewer::*)() const) &TPrsStd_AISViewer::Update, "Updates the viewer at the label access. access is the root of the data framework.");
cls_TPrsStd_AISViewer.def("SetInteractiveContext", (void (TPrsStd_AISViewer::*)(const opencascade::handle<AIS_InteractiveContext> &)) &TPrsStd_AISViewer::SetInteractiveContext, "Sets the interactive context ctx for this attribute.", py::arg("ctx"));
cls_TPrsStd_AISViewer.def("GetInteractiveContext", (opencascade::handle<AIS_InteractiveContext> (TPrsStd_AISViewer::*)() const) &TPrsStd_AISViewer::GetInteractiveContext, "Returns the interactive context in this attribute.");
cls_TPrsStd_AISViewer.def("ID", (const Standard_GUID & (TPrsStd_AISViewer::*)() const) &TPrsStd_AISViewer::ID, "None");
cls_TPrsStd_AISViewer.def("Restore", (void (TPrsStd_AISViewer::*)(const opencascade::handle<TDF_Attribute> &)) &TPrsStd_AISViewer::Restore, "None", py::arg("with"));
cls_TPrsStd_AISViewer.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TPrsStd_AISViewer::*)() const) &TPrsStd_AISViewer::NewEmpty, "None");
cls_TPrsStd_AISViewer.def("Paste", (void (TPrsStd_AISViewer::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TPrsStd_AISViewer::Paste, "None", py::arg("into"), py::arg("RT"));
cls_TPrsStd_AISViewer.def_static("get_type_name_", (const char * (*)()) &TPrsStd_AISViewer::get_type_name, "None");
cls_TPrsStd_AISViewer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TPrsStd_AISViewer::get_type_descriptor, "None");
cls_TPrsStd_AISViewer.def("DynamicType", (const opencascade::handle<Standard_Type> & (TPrsStd_AISViewer::*)() const) &TPrsStd_AISViewer::DynamicType, "None");

// Enums

}