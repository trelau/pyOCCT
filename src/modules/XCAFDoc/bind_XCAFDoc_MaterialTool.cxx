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
#include <Standard_Handle.hxx>
#include <XCAFDoc_MaterialTool.hxx>
#include <TDF_Label.hxx>
#include <Standard_GUID.hxx>
#include <XCAFDoc_ShapeTool.hxx>
#include <Standard_TypeDef.hxx>
#include <TDF_LabelSequence.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_Type.hxx>

void bind_XCAFDoc_MaterialTool(py::module &mod){

py::class_<XCAFDoc_MaterialTool, opencascade::handle<XCAFDoc_MaterialTool>, TDF_Attribute> cls_XCAFDoc_MaterialTool(mod, "XCAFDoc_MaterialTool", "Provides tools to store and retrieve attributes (materials) of TopoDS_Shape in and from TDocStd_Document A Document is intended to hold different attributes of ONE shape and it's sub-shapes Provide tools for management of Materialss section of document.");

// Constructors
cls_XCAFDoc_MaterialTool.def(py::init<>());

// Fields

// Methods
cls_XCAFDoc_MaterialTool.def_static("Set_", (opencascade::handle<XCAFDoc_MaterialTool> (*)(const TDF_Label &)) &XCAFDoc_MaterialTool::Set, "Creates (if not exist) MaterialTool.", py::arg("L"));
cls_XCAFDoc_MaterialTool.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_MaterialTool::GetID, "None");
cls_XCAFDoc_MaterialTool.def("BaseLabel", (TDF_Label (XCAFDoc_MaterialTool::*)() const) &XCAFDoc_MaterialTool::BaseLabel, "returns the label under which colors are stored");
cls_XCAFDoc_MaterialTool.def("ShapeTool", (const opencascade::handle<XCAFDoc_ShapeTool> & (XCAFDoc_MaterialTool::*)()) &XCAFDoc_MaterialTool::ShapeTool, "Returns internal XCAFDoc_ShapeTool tool");
cls_XCAFDoc_MaterialTool.def("IsMaterial", (Standard_Boolean (XCAFDoc_MaterialTool::*)(const TDF_Label &) const) &XCAFDoc_MaterialTool::IsMaterial, "Returns True if label belongs to a material table and is a Material definition", py::arg("lab"));
cls_XCAFDoc_MaterialTool.def("GetMaterialLabels", (void (XCAFDoc_MaterialTool::*)(TDF_LabelSequence &) const) &XCAFDoc_MaterialTool::GetMaterialLabels, "Returns a sequence of materials currently stored in the material table", py::arg("Labels"));
cls_XCAFDoc_MaterialTool.def("AddMaterial", (TDF_Label (XCAFDoc_MaterialTool::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &) const) &XCAFDoc_MaterialTool::AddMaterial, "Adds a Material definition to a table and returns its label", py::arg("aName"), py::arg("aDescription"), py::arg("aDensity"), py::arg("aDensName"), py::arg("aDensValType"));
cls_XCAFDoc_MaterialTool.def("SetMaterial", (void (XCAFDoc_MaterialTool::*)(const TDF_Label &, const TDF_Label &) const) &XCAFDoc_MaterialTool::SetMaterial, "Sets a link with GUID", py::arg("L"), py::arg("MatL"));
cls_XCAFDoc_MaterialTool.def("SetMaterial", (void (XCAFDoc_MaterialTool::*)(const TDF_Label &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &) const) &XCAFDoc_MaterialTool::SetMaterial, "Sets a link with GUID Adds a Material as necessary", py::arg("L"), py::arg("aName"), py::arg("aDescription"), py::arg("aDensity"), py::arg("aDensName"), py::arg("aDensValType"));
cls_XCAFDoc_MaterialTool.def("GetMaterial", [](XCAFDoc_MaterialTool &self, const TDF_Label & MatL, opencascade::handle<TCollection_HAsciiString> & aName, opencascade::handle<TCollection_HAsciiString> & aDescription, Standard_Real & aDensity, opencascade::handle<TCollection_HAsciiString> & aDensName, opencascade::handle<TCollection_HAsciiString> & aDensValType){ Standard_Boolean rv = self.GetMaterial(MatL, aName, aDescription, aDensity, aDensName, aDensValType); return std::tuple<Standard_Boolean, Standard_Real &>(rv, aDensity); }, "Returns Material assigned to <MatL> Returns False if no such Material is assigned", py::arg("MatL"), py::arg("aName"), py::arg("aDescription"), py::arg("aDensity"), py::arg("aDensName"), py::arg("aDensValType"));
cls_XCAFDoc_MaterialTool.def_static("GetDensityForShape_", (Standard_Real (*)(const TDF_Label &)) &XCAFDoc_MaterialTool::GetDensityForShape, "Find referred material and return density from it if no material --> return 0", py::arg("ShapeL"));
cls_XCAFDoc_MaterialTool.def("ID", (const Standard_GUID & (XCAFDoc_MaterialTool::*)() const) &XCAFDoc_MaterialTool::ID, "None");
cls_XCAFDoc_MaterialTool.def("Restore", (void (XCAFDoc_MaterialTool::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_MaterialTool::Restore, "None", py::arg("with"));
cls_XCAFDoc_MaterialTool.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_MaterialTool::*)() const) &XCAFDoc_MaterialTool::NewEmpty, "None");
cls_XCAFDoc_MaterialTool.def("Paste", (void (XCAFDoc_MaterialTool::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_MaterialTool::Paste, "None", py::arg("into"), py::arg("RT"));
cls_XCAFDoc_MaterialTool.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_MaterialTool::get_type_name, "None");
cls_XCAFDoc_MaterialTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_MaterialTool::get_type_descriptor, "None");
cls_XCAFDoc_MaterialTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_MaterialTool::*)() const) &XCAFDoc_MaterialTool::DynamicType, "None");

// Enums

}