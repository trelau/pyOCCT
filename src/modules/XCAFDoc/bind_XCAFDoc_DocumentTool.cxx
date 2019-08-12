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
#include <Standard_Handle.hxx>
#include <XCAFDoc_DocumentTool.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TDocStd_Document.hxx>
#include <XCAFDoc_ShapeTool.hxx>
#include <XCAFDoc_ColorTool.hxx>
#include <XCAFDoc_LayerTool.hxx>
#include <XCAFDoc_DimTolTool.hxx>
#include <XCAFDoc_MaterialTool.hxx>
#include <XCAFDoc_ViewTool.hxx>
#include <XCAFDoc_ClippingPlaneTool.hxx>
#include <XCAFDoc_NotesTool.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_Type.hxx>

void bind_XCAFDoc_DocumentTool(py::module &mod){

py::class_<XCAFDoc_DocumentTool, opencascade::handle<XCAFDoc_DocumentTool>, TDF_Attribute> cls_XCAFDoc_DocumentTool(mod, "XCAFDoc_DocumentTool", "Defines sections structure of an XDE document. attribute marking CAF document as being DECAF document. Creates the sections structure of the document.");

// Constructors
cls_XCAFDoc_DocumentTool.def(py::init<>());

// Fields

// Methods
cls_XCAFDoc_DocumentTool.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_DocumentTool::GetID, "None");
cls_XCAFDoc_DocumentTool.def_static("Set_", [](const TDF_Label & a0) -> opencascade::handle<XCAFDoc_DocumentTool> { return XCAFDoc_DocumentTool::Set(a0); });
cls_XCAFDoc_DocumentTool.def_static("Set_", (opencascade::handle<XCAFDoc_DocumentTool> (*)(const TDF_Label &, const Standard_Boolean)) &XCAFDoc_DocumentTool::Set, "Create (if not exist) DocumentTool attribute on 0.1 label if <IsAcces> is true, else on <L> label. This label will be returned by DocLabel(); If the attribute is already set it won't be reset on <L> even if <IsAcces> is false. ColorTool and ShapeTool attributes are also set by this method.", py::arg("L"), py::arg("IsAcces"));
cls_XCAFDoc_DocumentTool.def_static("IsXCAFDocument_", (Standard_Boolean (*)(const opencascade::handle<TDocStd_Document> &)) &XCAFDoc_DocumentTool::IsXCAFDocument, "None", py::arg("Doc"));
cls_XCAFDoc_DocumentTool.def_static("DocLabel_", (TDF_Label (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::DocLabel, "Returns label where the DocumentTool attribute is or 0.1 if DocumentTool is not yet set.", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("ShapesLabel_", (TDF_Label (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::ShapesLabel, "Returns sub-label of DocLabel() with tag 1.", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("ColorsLabel_", (TDF_Label (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::ColorsLabel, "Returns sub-label of DocLabel() with tag 2.", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("LayersLabel_", (TDF_Label (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::LayersLabel, "Returns sub-label of DocLabel() with tag 3.", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("DGTsLabel_", (TDF_Label (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::DGTsLabel, "Returns sub-label of DocLabel() with tag 4.", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("MaterialsLabel_", (TDF_Label (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::MaterialsLabel, "Returns sub-label of DocLabel() with tag 5.", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("ViewsLabel_", (TDF_Label (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::ViewsLabel, "Returns sub-label of DocLabel() with tag 7.", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("ClippingPlanesLabel_", (TDF_Label (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::ClippingPlanesLabel, "Returns sub-label of DocLabel() with tag 8.", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("NotesLabel_", (TDF_Label (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::NotesLabel, "Returns sub-label of DocLabel() with tag 9.", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("ShapeTool_", (opencascade::handle<XCAFDoc_ShapeTool> (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::ShapeTool, "Creates (if it does not exist) ShapeTool attribute on ShapesLabel().", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("ColorTool_", (opencascade::handle<XCAFDoc_ColorTool> (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::ColorTool, "Creates (if it does not exist) ColorTool attribute on ColorsLabel().", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("LayerTool_", (opencascade::handle<XCAFDoc_LayerTool> (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::LayerTool, "Creates (if it does not exist) LayerTool attribute on LayersLabel().", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("DimTolTool_", (opencascade::handle<XCAFDoc_DimTolTool> (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::DimTolTool, "Creates (if it does not exist) DimTolTool attribute on DGTsLabel().", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("MaterialTool_", (opencascade::handle<XCAFDoc_MaterialTool> (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::MaterialTool, "Creates (if it does not exist) DimTolTool attribute on DGTsLabel().", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("ViewTool_", (opencascade::handle<XCAFDoc_ViewTool> (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::ViewTool, "Creates (if it does not exist) ViewTool attribute on ViewsLabel().", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("ClippingPlaneTool_", (opencascade::handle<XCAFDoc_ClippingPlaneTool> (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::ClippingPlaneTool, "Creates (if it does not exist) ClippingPlaneTool attribute on ClippingPlanesLabel().", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def_static("NotesTool_", (opencascade::handle<XCAFDoc_NotesTool> (*)(const TDF_Label &)) &XCAFDoc_DocumentTool::NotesTool, "Creates (if it does not exist) NotesTool attribute on NotesLabel().", py::arg("acces"));
cls_XCAFDoc_DocumentTool.def("Init", (void (XCAFDoc_DocumentTool::*)() const) &XCAFDoc_DocumentTool::Init, "to be called when reading this attribute from file");
cls_XCAFDoc_DocumentTool.def("ID", (const Standard_GUID & (XCAFDoc_DocumentTool::*)() const) &XCAFDoc_DocumentTool::ID, "None");
cls_XCAFDoc_DocumentTool.def("Restore", (void (XCAFDoc_DocumentTool::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_DocumentTool::Restore, "None", py::arg("with"));
cls_XCAFDoc_DocumentTool.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_DocumentTool::*)() const) &XCAFDoc_DocumentTool::NewEmpty, "None");
cls_XCAFDoc_DocumentTool.def("Paste", (void (XCAFDoc_DocumentTool::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_DocumentTool::Paste, "None", py::arg("into"), py::arg("RT"));
cls_XCAFDoc_DocumentTool.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_DocumentTool::get_type_name, "None");
cls_XCAFDoc_DocumentTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_DocumentTool::get_type_descriptor, "None");
cls_XCAFDoc_DocumentTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_DocumentTool::*)() const) &XCAFDoc_DocumentTool::DynamicType, "None");

// Enums

}