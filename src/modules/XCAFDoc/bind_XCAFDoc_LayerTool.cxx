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
#include <XCAFDoc_LayerTool.hxx>
#include <TDF_Label.hxx>
#include <Standard_GUID.hxx>
#include <XCAFDoc_ShapeTool.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TDF_LabelSequence.hxx>
#include <TColStd_HSequenceOfExtendedString.hxx>
#include <TopoDS_Shape.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_Type.hxx>

void bind_XCAFDoc_LayerTool(py::module &mod){

py::class_<XCAFDoc_LayerTool, opencascade::handle<XCAFDoc_LayerTool>, TDF_Attribute> cls_XCAFDoc_LayerTool(mod, "XCAFDoc_LayerTool", "Provides tools to store and retrieve attributes (Layers) of TopoDS_Shape in and from TDocStd_Document A Document is intended to hold different attributes of ONE shape and it's sub-shapes Provide tools for management of Layers section of document.");

// Constructors
cls_XCAFDoc_LayerTool.def(py::init<>());

// Fields

// Methods
cls_XCAFDoc_LayerTool.def_static("Set_", (opencascade::handle<XCAFDoc_LayerTool> (*)(const TDF_Label &)) &XCAFDoc_LayerTool::Set, "Creates (if not exist) LayerTool.", py::arg("L"));
cls_XCAFDoc_LayerTool.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_LayerTool::GetID, "None");
cls_XCAFDoc_LayerTool.def("BaseLabel", (TDF_Label (XCAFDoc_LayerTool::*)() const) &XCAFDoc_LayerTool::BaseLabel, "returns the label under which Layers are stored");
cls_XCAFDoc_LayerTool.def("ShapeTool", (const opencascade::handle<XCAFDoc_ShapeTool> & (XCAFDoc_LayerTool::*)()) &XCAFDoc_LayerTool::ShapeTool, "Returns internal XCAFDoc_ShapeTool tool");
cls_XCAFDoc_LayerTool.def("IsLayer", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TDF_Label &) const) &XCAFDoc_LayerTool::IsLayer, "Returns True if label belongs to a Layertable and is a Layer definition", py::arg("lab"));
cls_XCAFDoc_LayerTool.def("GetLayer", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TDF_Label &, TCollection_ExtendedString &) const) &XCAFDoc_LayerTool::GetLayer, "Returns Layer defined by label lab Returns False if the label is not in Layertable or does not define a Layer", py::arg("lab"), py::arg("aLayer"));
cls_XCAFDoc_LayerTool.def("FindLayer", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TCollection_ExtendedString &, TDF_Label &) const) &XCAFDoc_LayerTool::FindLayer, "Finds a Layer definition in a Layertable and returns its label if found Returns False if Layer is not found in Layertable", py::arg("aLayer"), py::arg("lab"));
cls_XCAFDoc_LayerTool.def("FindLayer", (TDF_Label (XCAFDoc_LayerTool::*)(const TCollection_ExtendedString &) const) &XCAFDoc_LayerTool::FindLayer, "Finds a Layer definition in a Layertable and returns its label if found (or Null label else)", py::arg("aLayer"));
cls_XCAFDoc_LayerTool.def("AddLayer", (TDF_Label (XCAFDoc_LayerTool::*)(const TCollection_ExtendedString &) const) &XCAFDoc_LayerTool::AddLayer, "Adds a Layer definition to a Layertable and returns its label (returns existing label if the same Layer is already defined)", py::arg("aLayer"));
cls_XCAFDoc_LayerTool.def("RemoveLayer", (void (XCAFDoc_LayerTool::*)(const TDF_Label &) const) &XCAFDoc_LayerTool::RemoveLayer, "Removes Layer from the Layertable", py::arg("lab"));
cls_XCAFDoc_LayerTool.def("GetLayerLabels", (void (XCAFDoc_LayerTool::*)(TDF_LabelSequence &) const) &XCAFDoc_LayerTool::GetLayerLabels, "Returns a sequence of Layers currently stored in the Layertable", py::arg("Labels"));
cls_XCAFDoc_LayerTool.def("SetLayer", [](XCAFDoc_LayerTool &self, const TDF_Label & a0, const TDF_Label & a1) -> void { return self.SetLayer(a0, a1); });
cls_XCAFDoc_LayerTool.def("SetLayer", (void (XCAFDoc_LayerTool::*)(const TDF_Label &, const TDF_Label &, const Standard_Boolean) const) &XCAFDoc_LayerTool::SetLayer, "Sets a link from label <L> to Layer defined by <LayerL> optional parametr <shapeInOneLayer> show could shape be in number of layers or only in one.", py::arg("L"), py::arg("LayerL"), py::arg("shapeInOneLayer"));
cls_XCAFDoc_LayerTool.def("SetLayer", [](XCAFDoc_LayerTool &self, const TDF_Label & a0, const TCollection_ExtendedString & a1) -> void { return self.SetLayer(a0, a1); });
cls_XCAFDoc_LayerTool.def("SetLayer", (void (XCAFDoc_LayerTool::*)(const TDF_Label &, const TCollection_ExtendedString &, const Standard_Boolean) const) &XCAFDoc_LayerTool::SetLayer, "Sets a link from label <L> to Layer <aLayer> in the Layertable Adds a Layer as necessary optional parametr <shapeInOneLayer> show could shape be in number of layers or only in one.", py::arg("L"), py::arg("aLayer"), py::arg("shapeInOneLayer"));
cls_XCAFDoc_LayerTool.def("UnSetLayers", (void (XCAFDoc_LayerTool::*)(const TDF_Label &) const) &XCAFDoc_LayerTool::UnSetLayers, "Removes a link from label <L> to all layers", py::arg("L"));
cls_XCAFDoc_LayerTool.def("UnSetOneLayer", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TDF_Label &, const TCollection_ExtendedString &) const) &XCAFDoc_LayerTool::UnSetOneLayer, "Remove link from label <L> and Layer <aLayer>. returns FALSE if no such layer.", py::arg("L"), py::arg("aLayer"));
cls_XCAFDoc_LayerTool.def("UnSetOneLayer", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TDF_Label &, const TDF_Label &) const) &XCAFDoc_LayerTool::UnSetOneLayer, "Remove link from label <L> and Layer <aLayerL>. returns FALSE if <aLayerL> is not a layer label.", py::arg("L"), py::arg("aLayerL"));
cls_XCAFDoc_LayerTool.def("IsSet", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TDF_Label &, const TCollection_ExtendedString &) const) &XCAFDoc_LayerTool::IsSet, "Returns True if label <L> has a Layer assosiated with the <aLayer>.", py::arg("L"), py::arg("aLayer"));
cls_XCAFDoc_LayerTool.def("IsSet", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TDF_Label &, const TDF_Label &) const) &XCAFDoc_LayerTool::IsSet, "Returns True if label <L> has a Layer assosiated with the <aLayerL> label.", py::arg("L"), py::arg("aLayerL"));
cls_XCAFDoc_LayerTool.def("GetLayers", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TDF_Label &, opencascade::handle<TColStd_HSequenceOfExtendedString> &)) &XCAFDoc_LayerTool::GetLayers, "Return sequence of strings <aLayerS> that assosiated with label <L>.", py::arg("L"), py::arg("aLayerS"));
cls_XCAFDoc_LayerTool.def("GetLayers", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TDF_Label &, TDF_LabelSequence &)) &XCAFDoc_LayerTool::GetLayers, "Return sequence of labels <aLayerSL> that assosiated with label <L>.", py::arg("L"), py::arg("aLayerLS"));
cls_XCAFDoc_LayerTool.def("GetLayers", (opencascade::handle<TColStd_HSequenceOfExtendedString> (XCAFDoc_LayerTool::*)(const TDF_Label &)) &XCAFDoc_LayerTool::GetLayers, "Return sequence of strings that assosiated with label <L>.", py::arg("L"));
cls_XCAFDoc_LayerTool.def("GetShapesOfLayer", (void (XCAFDoc_LayerTool::*)(const TDF_Label &, TDF_LabelSequence &) const) &XCAFDoc_LayerTool::GetShapesOfLayer, "Return sequanese of shape labels that assigned with layers to <ShLabels>.", py::arg("layerL"), py::arg("ShLabels"));
cls_XCAFDoc_LayerTool.def("IsVisible", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TDF_Label &) const) &XCAFDoc_LayerTool::IsVisible, "Return TRUE if layer is visible, FALSE if invisible.", py::arg("layerL"));
cls_XCAFDoc_LayerTool.def("SetVisibility", [](XCAFDoc_LayerTool &self, const TDF_Label & a0) -> void { return self.SetVisibility(a0); });
cls_XCAFDoc_LayerTool.def("SetVisibility", (void (XCAFDoc_LayerTool::*)(const TDF_Label &, const Standard_Boolean) const) &XCAFDoc_LayerTool::SetVisibility, "Set the visibility of layer. If layer is invisible when on it's layer will set UAttribute with corresponding GUID.", py::arg("layerL"), py::arg("isvisible"));
cls_XCAFDoc_LayerTool.def("SetLayer", [](XCAFDoc_LayerTool &self, const TopoDS_Shape & a0, const TDF_Label & a1) -> Standard_Boolean { return self.SetLayer(a0, a1); });
cls_XCAFDoc_LayerTool.def("SetLayer", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TopoDS_Shape &, const TDF_Label &, const Standard_Boolean)) &XCAFDoc_LayerTool::SetLayer, "Sets a link from label that containig shape <Sh> with layer that situated at label <LayerL>. optional parametr <shapeInOneLayer> show could shape be in number of layers or only in one. return FALSE if no such shape <Sh> or label <LayerL>", py::arg("Sh"), py::arg("LayerL"), py::arg("shapeInOneLayer"));
cls_XCAFDoc_LayerTool.def("SetLayer", [](XCAFDoc_LayerTool &self, const TopoDS_Shape & a0, const TCollection_ExtendedString & a1) -> Standard_Boolean { return self.SetLayer(a0, a1); });
cls_XCAFDoc_LayerTool.def("SetLayer", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TopoDS_Shape &, const TCollection_ExtendedString &, const Standard_Boolean)) &XCAFDoc_LayerTool::SetLayer, "Sets a link from label that containig shape <Sh> with layer <aLayer>. Add <aLayer> to LayerTable if nessesery. optional parametr <shapeInOneLayer> show could shape be in number of layers or only in one. return FALSE if no such shape <Sh>.", py::arg("Sh"), py::arg("aLayer"), py::arg("shapeInOneLayer"));
cls_XCAFDoc_LayerTool.def("UnSetLayers", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TopoDS_Shape &)) &XCAFDoc_LayerTool::UnSetLayers, "Remove link between shape <Sh> and all Layers at LayerTable. return FALSE if no such shape <Sh> in XCAF Document.", py::arg("Sh"));
cls_XCAFDoc_LayerTool.def("UnSetOneLayer", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TopoDS_Shape &, const TCollection_ExtendedString &)) &XCAFDoc_LayerTool::UnSetOneLayer, "Remove link between shape <Sh> and layer <aLayer>. returns FALSE if no such layer <aLayer> or shape <Sh>.", py::arg("Sh"), py::arg("aLayer"));
cls_XCAFDoc_LayerTool.def("UnSetOneLayer", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TopoDS_Shape &, const TDF_Label &)) &XCAFDoc_LayerTool::UnSetOneLayer, "Remove link between shape <Sh> and layer <aLayerL>. returns FALSE if no such layer <aLayerL> or shape <Sh>.", py::arg("Sh"), py::arg("aLayerL"));
cls_XCAFDoc_LayerTool.def("IsSet", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TopoDS_Shape &, const TCollection_ExtendedString &)) &XCAFDoc_LayerTool::IsSet, "Returns True if shape <Sh> has a Layer assosiated with the <aLayer>.", py::arg("Sh"), py::arg("aLayer"));
cls_XCAFDoc_LayerTool.def("IsSet", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TopoDS_Shape &, const TDF_Label &)) &XCAFDoc_LayerTool::IsSet, "Returns True if shape <Sh> has a Layer assosiated with the <aLayerL>.", py::arg("Sh"), py::arg("aLayerL"));
cls_XCAFDoc_LayerTool.def("GetLayers", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TopoDS_Shape &, opencascade::handle<TColStd_HSequenceOfExtendedString> &)) &XCAFDoc_LayerTool::GetLayers, "Return sequence of strings <aLayerS> that assosiated with shape <Sh>.", py::arg("Sh"), py::arg("aLayerS"));
cls_XCAFDoc_LayerTool.def("GetLayers", (Standard_Boolean (XCAFDoc_LayerTool::*)(const TopoDS_Shape &, TDF_LabelSequence &)) &XCAFDoc_LayerTool::GetLayers, "Return sequence of labels <aLayerLS> that assosiated with shape <Sh>.", py::arg("Sh"), py::arg("aLayerLS"));
cls_XCAFDoc_LayerTool.def("GetLayers", (opencascade::handle<TColStd_HSequenceOfExtendedString> (XCAFDoc_LayerTool::*)(const TopoDS_Shape &)) &XCAFDoc_LayerTool::GetLayers, "Return sequence of strings that assosiated with shape <Sh>.", py::arg("Sh"));
cls_XCAFDoc_LayerTool.def("ID", (const Standard_GUID & (XCAFDoc_LayerTool::*)() const) &XCAFDoc_LayerTool::ID, "None");
cls_XCAFDoc_LayerTool.def("Restore", (void (XCAFDoc_LayerTool::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_LayerTool::Restore, "None", py::arg("with"));
cls_XCAFDoc_LayerTool.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_LayerTool::*)() const) &XCAFDoc_LayerTool::NewEmpty, "None");
cls_XCAFDoc_LayerTool.def("Paste", (void (XCAFDoc_LayerTool::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_LayerTool::Paste, "None", py::arg("into"), py::arg("RT"));
cls_XCAFDoc_LayerTool.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_LayerTool::get_type_name, "None");
cls_XCAFDoc_LayerTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_LayerTool::get_type_descriptor, "None");
cls_XCAFDoc_LayerTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_LayerTool::*)() const) &XCAFDoc_LayerTool::DynamicType, "None");

// Enums

}