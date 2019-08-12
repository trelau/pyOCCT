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
#include <IFSelect_Editor.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_EditForm.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <IGESSelect_EditDirPart.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_EditDirPart(py::module &mod){

py::class_<IGESSelect_EditDirPart, opencascade::handle<IGESSelect_EditDirPart>, IFSelect_Editor> cls_IGESSelect_EditDirPart(mod, "IGESSelect_EditDirPart", "This class is aimed to display and edit the Directory Part of an IGESEntity");

// Constructors
cls_IGESSelect_EditDirPart.def(py::init<>());

// Fields

// Methods
cls_IGESSelect_EditDirPart.def("Label", (TCollection_AsciiString (IGESSelect_EditDirPart::*)() const) &IGESSelect_EditDirPart::Label, "None");
cls_IGESSelect_EditDirPart.def("Recognize", (Standard_Boolean (IGESSelect_EditDirPart::*)(const opencascade::handle<IFSelect_EditForm> &) const) &IGESSelect_EditDirPart::Recognize, "None", py::arg("form"));
cls_IGESSelect_EditDirPart.def("StringValue", (opencascade::handle<TCollection_HAsciiString> (IGESSelect_EditDirPart::*)(const opencascade::handle<IFSelect_EditForm> &, const Standard_Integer) const) &IGESSelect_EditDirPart::StringValue, "None", py::arg("form"), py::arg("num"));
cls_IGESSelect_EditDirPart.def("Load", (Standard_Boolean (IGESSelect_EditDirPart::*)(const opencascade::handle<IFSelect_EditForm> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IGESSelect_EditDirPart::Load, "None", py::arg("form"), py::arg("ent"), py::arg("model"));
cls_IGESSelect_EditDirPart.def("Update", (Standard_Boolean (IGESSelect_EditDirPart::*)(const opencascade::handle<IFSelect_EditForm> &, const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean) const) &IGESSelect_EditDirPart::Update, "None", py::arg("form"), py::arg("num"), py::arg("newval"), py::arg("enforce"));
cls_IGESSelect_EditDirPart.def("Apply", (Standard_Boolean (IGESSelect_EditDirPart::*)(const opencascade::handle<IFSelect_EditForm> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IGESSelect_EditDirPart::Apply, "None", py::arg("form"), py::arg("ent"), py::arg("model"));
cls_IGESSelect_EditDirPart.def_static("get_type_name_", (const char * (*)()) &IGESSelect_EditDirPart::get_type_name, "None");
cls_IGESSelect_EditDirPart.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_EditDirPart::get_type_descriptor, "None");
cls_IGESSelect_EditDirPart.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_EditDirPart::*)() const) &IGESSelect_EditDirPart::DynamicType, "None");

// Enums

}