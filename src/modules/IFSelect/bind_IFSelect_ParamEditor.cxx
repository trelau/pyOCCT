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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Interface_TypedValue.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_EditForm.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <IFSelect_ParamEditor.hxx>
#include <TColStd_HSequenceOfHAsciiString.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_ParamEditor(py::module &mod){

py::class_<IFSelect_ParamEditor, opencascade::handle<IFSelect_ParamEditor>, IFSelect_Editor> cls_IFSelect_ParamEditor(mod, "IFSelect_ParamEditor", "A ParamEditor gives access for edition to a list of TypedValue (i.e. of Static too) Its definition is made of the TypedValue to edit themselves, and can add some constants, which can then be displayed but not changed (for instance, system name, processor version ...)");

// Constructors
cls_IFSelect_ParamEditor.def(py::init<>());
cls_IFSelect_ParamEditor.def(py::init<const Standard_Integer>(), py::arg("nbmax"));
cls_IFSelect_ParamEditor.def(py::init<const Standard_Integer, const Standard_CString>(), py::arg("nbmax"), py::arg("label"));

// Fields

// Methods
cls_IFSelect_ParamEditor.def("AddValue", [](IFSelect_ParamEditor &self, const opencascade::handle<Interface_TypedValue> & a0) -> void { return self.AddValue(a0); });
cls_IFSelect_ParamEditor.def("AddValue", (void (IFSelect_ParamEditor::*)(const opencascade::handle<Interface_TypedValue> &, const Standard_CString)) &IFSelect_ParamEditor::AddValue, "Adds a TypedValue By default, its short name equates its complete name, it can be explicited", py::arg("val"), py::arg("shortname"));
cls_IFSelect_ParamEditor.def("AddConstantText", [](IFSelect_ParamEditor &self, const Standard_CString a0, const Standard_CString a1) -> void { return self.AddConstantText(a0, a1); });
cls_IFSelect_ParamEditor.def("AddConstantText", (void (IFSelect_ParamEditor::*)(const Standard_CString, const Standard_CString, const Standard_CString)) &IFSelect_ParamEditor::AddConstantText, "Adds a Constant Text, it will be Read Only By default, its long name equates its shortname", py::arg("val"), py::arg("shortname"), py::arg("completename"));
cls_IFSelect_ParamEditor.def("Label", (TCollection_AsciiString (IFSelect_ParamEditor::*)() const) &IFSelect_ParamEditor::Label, "None");
cls_IFSelect_ParamEditor.def("Recognize", (Standard_Boolean (IFSelect_ParamEditor::*)(const opencascade::handle<IFSelect_EditForm> &) const) &IFSelect_ParamEditor::Recognize, "None", py::arg("form"));
cls_IFSelect_ParamEditor.def("StringValue", (opencascade::handle<TCollection_HAsciiString> (IFSelect_ParamEditor::*)(const opencascade::handle<IFSelect_EditForm> &, const Standard_Integer) const) &IFSelect_ParamEditor::StringValue, "None", py::arg("form"), py::arg("num"));
cls_IFSelect_ParamEditor.def("Load", (Standard_Boolean (IFSelect_ParamEditor::*)(const opencascade::handle<IFSelect_EditForm> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_ParamEditor::Load, "None", py::arg("form"), py::arg("ent"), py::arg("model"));
cls_IFSelect_ParamEditor.def("Apply", (Standard_Boolean (IFSelect_ParamEditor::*)(const opencascade::handle<IFSelect_EditForm> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_ParamEditor::Apply, "None", py::arg("form"), py::arg("ent"), py::arg("model"));
cls_IFSelect_ParamEditor.def_static("StaticEditor_", [](const opencascade::handle<TColStd_HSequenceOfHAsciiString> & a0) -> opencascade::handle<IFSelect_ParamEditor> { return IFSelect_ParamEditor::StaticEditor(a0); });
cls_IFSelect_ParamEditor.def_static("StaticEditor_", (opencascade::handle<IFSelect_ParamEditor> (*)(const opencascade::handle<TColStd_HSequenceOfHAsciiString> &, const Standard_CString)) &IFSelect_ParamEditor::StaticEditor, "Returns a ParamEditor to work on the Static Parameters of which names are listed in <list> Null Handle if <list> is null or empty", py::arg("list"), py::arg("label"));
cls_IFSelect_ParamEditor.def_static("get_type_name_", (const char * (*)()) &IFSelect_ParamEditor::get_type_name, "None");
cls_IFSelect_ParamEditor.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_ParamEditor::get_type_descriptor, "None");
cls_IFSelect_ParamEditor.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_ParamEditor::*)() const) &IFSelect_ParamEditor::DynamicType, "None");

// Enums

}