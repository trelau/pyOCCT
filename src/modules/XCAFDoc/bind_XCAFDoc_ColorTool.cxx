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
#include <XCAFDoc_ColorTool.hxx>
#include <TDF_Label.hxx>
#include <Standard_GUID.hxx>
#include <XCAFDoc_ShapeTool.hxx>
#include <Standard_TypeDef.hxx>
#include <Quantity_Color.hxx>
#include <Quantity_ColorRGBA.hxx>
#include <TDF_LabelSequence.hxx>
#include <XCAFDoc_ColorType.hxx>
#include <TopoDS_Shape.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_Type.hxx>

void bind_XCAFDoc_ColorTool(py::module &mod){

py::class_<XCAFDoc_ColorTool, opencascade::handle<XCAFDoc_ColorTool>, TDF_Attribute> cls_XCAFDoc_ColorTool(mod, "XCAFDoc_ColorTool", "Provides tools to store and retrieve attributes (colors) of TopoDS_Shape in and from TDocStd_Document A Document is intended to hold different attributes of ONE shape and it's sub-shapes Provide tools for management of Colors section of document.");

// Constructors
cls_XCAFDoc_ColorTool.def(py::init<>());

// Fields

// Methods
cls_XCAFDoc_ColorTool.def_static("Set_", (opencascade::handle<XCAFDoc_ColorTool> (*)(const TDF_Label &)) &XCAFDoc_ColorTool::Set, "Creates (if not exist) ColorTool.", py::arg("L"));
cls_XCAFDoc_ColorTool.def_static("GetID_", (const Standard_GUID & (*)()) &XCAFDoc_ColorTool::GetID, "None");
cls_XCAFDoc_ColorTool.def("BaseLabel", (TDF_Label (XCAFDoc_ColorTool::*)() const) &XCAFDoc_ColorTool::BaseLabel, "returns the label under which colors are stored");
cls_XCAFDoc_ColorTool.def("ShapeTool", (const opencascade::handle<XCAFDoc_ShapeTool> & (XCAFDoc_ColorTool::*)()) &XCAFDoc_ColorTool::ShapeTool, "Returns internal XCAFDoc_ShapeTool tool");
cls_XCAFDoc_ColorTool.def("IsColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TDF_Label &) const) &XCAFDoc_ColorTool::IsColor, "Returns True if label belongs to a colortable and is a color definition", py::arg("lab"));
cls_XCAFDoc_ColorTool.def("GetColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TDF_Label &, Quantity_Color &) const) &XCAFDoc_ColorTool::GetColor, "Returns color defined by label lab Returns False if the label is not in colortable or does not define a color", py::arg("lab"), py::arg("col"));
cls_XCAFDoc_ColorTool.def("GetColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TDF_Label &, Quantity_ColorRGBA &) const) &XCAFDoc_ColorTool::GetColor, "Returns color defined by label lab Returns False if the label is not in colortable or does not define a color", py::arg("lab"), py::arg("col"));
cls_XCAFDoc_ColorTool.def("FindColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const Quantity_Color &, TDF_Label &) const) &XCAFDoc_ColorTool::FindColor, "Finds a color definition in a colortable and returns its label if found Returns False if color is not found in colortable", py::arg("col"), py::arg("lab"));
cls_XCAFDoc_ColorTool.def("FindColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const Quantity_ColorRGBA &, TDF_Label &) const) &XCAFDoc_ColorTool::FindColor, "Finds a color definition in a colortable and returns its label if found Returns False if color is not found in colortable", py::arg("col"), py::arg("lab"));
cls_XCAFDoc_ColorTool.def("FindColor", (TDF_Label (XCAFDoc_ColorTool::*)(const Quantity_Color &) const) &XCAFDoc_ColorTool::FindColor, "Finds a color definition in a colortable and returns its label if found (or Null label else)", py::arg("col"));
cls_XCAFDoc_ColorTool.def("FindColor", (TDF_Label (XCAFDoc_ColorTool::*)(const Quantity_ColorRGBA &) const) &XCAFDoc_ColorTool::FindColor, "Finds a color definition in a colortable and returns its label if found (or Null label else)", py::arg("col"));
cls_XCAFDoc_ColorTool.def("AddColor", (TDF_Label (XCAFDoc_ColorTool::*)(const Quantity_Color &) const) &XCAFDoc_ColorTool::AddColor, "Adds a color definition to a colortable and returns its label (returns existing label if the same color is already defined)", py::arg("col"));
cls_XCAFDoc_ColorTool.def("AddColor", (TDF_Label (XCAFDoc_ColorTool::*)(const Quantity_ColorRGBA &) const) &XCAFDoc_ColorTool::AddColor, "Adds a color definition to a colortable and returns its label (returns existing label if the same color is already defined)", py::arg("col"));
cls_XCAFDoc_ColorTool.def("RemoveColor", (void (XCAFDoc_ColorTool::*)(const TDF_Label &) const) &XCAFDoc_ColorTool::RemoveColor, "Removes color from the colortable", py::arg("lab"));
cls_XCAFDoc_ColorTool.def("GetColors", (void (XCAFDoc_ColorTool::*)(TDF_LabelSequence &) const) &XCAFDoc_ColorTool::GetColors, "Returns a sequence of colors currently stored in the colortable", py::arg("Labels"));
cls_XCAFDoc_ColorTool.def("SetColor", (void (XCAFDoc_ColorTool::*)(const TDF_Label &, const TDF_Label &, const XCAFDoc_ColorType) const) &XCAFDoc_ColorTool::SetColor, "Sets a link with GUID defined by <type> (see XCAFDoc::ColorRefGUID()) from label <L> to color defined by <colorL>. Color of shape is defined following way in dependance with type of color. If type of color is XCAFDoc_ColorGen - then this color defines default color for surfaces and curves. If for shape color with types XCAFDoc_ColorSurf or XCAFDoc_ColorCurv is specified then such color overrides generic color.", py::arg("L"), py::arg("colorL"), py::arg("type"));
cls_XCAFDoc_ColorTool.def("SetColor", (void (XCAFDoc_ColorTool::*)(const TDF_Label &, const Quantity_Color &, const XCAFDoc_ColorType) const) &XCAFDoc_ColorTool::SetColor, "Sets a link with GUID defined by <type> (see XCAFDoc::ColorRefGUID()) from label <L> to color <Color> in the colortable Adds a color as necessary", py::arg("L"), py::arg("Color"), py::arg("type"));
cls_XCAFDoc_ColorTool.def("SetColor", (void (XCAFDoc_ColorTool::*)(const TDF_Label &, const Quantity_ColorRGBA &, const XCAFDoc_ColorType) const) &XCAFDoc_ColorTool::SetColor, "Sets a link with GUID defined by <type> (see XCAFDoc::ColorRefGUID()) from label <L> to color <Color> in the colortable Adds a color as necessary", py::arg("L"), py::arg("Color"), py::arg("type"));
cls_XCAFDoc_ColorTool.def("UnSetColor", (void (XCAFDoc_ColorTool::*)(const TDF_Label &, const XCAFDoc_ColorType) const) &XCAFDoc_ColorTool::UnSetColor, "Removes a link with GUID defined by <type> (see XCAFDoc::ColorRefGUID()) from label <L> to color", py::arg("L"), py::arg("type"));
cls_XCAFDoc_ColorTool.def("IsSet", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TDF_Label &, const XCAFDoc_ColorType) const) &XCAFDoc_ColorTool::IsSet, "Returns True if label <L> has a color assignment of the type <type>", py::arg("L"), py::arg("type"));
cls_XCAFDoc_ColorTool.def_static("GetColor_", (Standard_Boolean (*)(const TDF_Label &, const XCAFDoc_ColorType, TDF_Label &)) &XCAFDoc_ColorTool::GetColor, "Returns label with color assigned to <L> as <type> Returns False if no such color is assigned", py::arg("L"), py::arg("type"), py::arg("colorL"));
cls_XCAFDoc_ColorTool.def("GetColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TDF_Label &, const XCAFDoc_ColorType, Quantity_Color &)) &XCAFDoc_ColorTool::GetColor, "Returns color assigned to <L> as <type> Returns False if no such color is assigned", py::arg("L"), py::arg("type"), py::arg("color"));
cls_XCAFDoc_ColorTool.def("GetColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TDF_Label &, const XCAFDoc_ColorType, Quantity_ColorRGBA &)) &XCAFDoc_ColorTool::GetColor, "Returns color assigned to <L> as <type> Returns False if no such color is assigned", py::arg("L"), py::arg("type"), py::arg("color"));
cls_XCAFDoc_ColorTool.def("SetColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TopoDS_Shape &, const TDF_Label &, const XCAFDoc_ColorType)) &XCAFDoc_ColorTool::SetColor, "Sets a link with GUID defined by <type> (see XCAFDoc::ColorRefGUID()) from label <L> to color defined by <colorL> Returns False if cannot find a label for shape S", py::arg("S"), py::arg("colorL"), py::arg("type"));
cls_XCAFDoc_ColorTool.def("SetColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TopoDS_Shape &, const Quantity_Color &, const XCAFDoc_ColorType)) &XCAFDoc_ColorTool::SetColor, "Sets a link with GUID defined by <type> (see XCAFDoc::ColorRefGUID()) from label <L> to color <Color> in the colortable Adds a color as necessary Returns False if cannot find a label for shape S", py::arg("S"), py::arg("Color"), py::arg("type"));
cls_XCAFDoc_ColorTool.def("SetColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TopoDS_Shape &, const Quantity_ColorRGBA &, const XCAFDoc_ColorType)) &XCAFDoc_ColorTool::SetColor, "Sets a link with GUID defined by <type> (see XCAFDoc::ColorRefGUID()) from label <L> to color <Color> in the colortable Adds a color as necessary Returns False if cannot find a label for shape S", py::arg("S"), py::arg("Color"), py::arg("type"));
cls_XCAFDoc_ColorTool.def("UnSetColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TopoDS_Shape &, const XCAFDoc_ColorType)) &XCAFDoc_ColorTool::UnSetColor, "Removes a link with GUID defined by <type> (see XCAFDoc::ColorRefGUID()) from label <L> to color Returns True if such link existed", py::arg("S"), py::arg("type"));
cls_XCAFDoc_ColorTool.def("IsSet", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TopoDS_Shape &, const XCAFDoc_ColorType)) &XCAFDoc_ColorTool::IsSet, "Returns True if label <L> has a color assignment of the type <type>", py::arg("S"), py::arg("type"));
cls_XCAFDoc_ColorTool.def("GetColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TopoDS_Shape &, const XCAFDoc_ColorType, TDF_Label &)) &XCAFDoc_ColorTool::GetColor, "Returns label with color assigned to <L> as <type> Returns False if no such color is assigned", py::arg("S"), py::arg("type"), py::arg("colorL"));
cls_XCAFDoc_ColorTool.def("GetColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TopoDS_Shape &, const XCAFDoc_ColorType, Quantity_Color &)) &XCAFDoc_ColorTool::GetColor, "Returns color assigned to <L> as <type> Returns False if no such color is assigned", py::arg("S"), py::arg("type"), py::arg("color"));
cls_XCAFDoc_ColorTool.def("GetColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TopoDS_Shape &, const XCAFDoc_ColorType, Quantity_ColorRGBA &)) &XCAFDoc_ColorTool::GetColor, "Returns color assigned to <L> as <type> Returns False if no such color is assigned", py::arg("S"), py::arg("type"), py::arg("color"));
cls_XCAFDoc_ColorTool.def("IsVisible", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TDF_Label &) const) &XCAFDoc_ColorTool::IsVisible, "Return TRUE if object on this label is visible, FALSE if invisible.", py::arg("L"));
cls_XCAFDoc_ColorTool.def("SetVisibility", [](XCAFDoc_ColorTool &self, const TDF_Label & a0) -> void { return self.SetVisibility(a0); });
cls_XCAFDoc_ColorTool.def("SetVisibility", (void (XCAFDoc_ColorTool::*)(const TDF_Label &, const Standard_Boolean)) &XCAFDoc_ColorTool::SetVisibility, "Set the visibility of object on label. Do nothing if there no any object. Set UAttribute with corresponding GUID.", py::arg("shapeLabel"), py::arg("isvisible"));
cls_XCAFDoc_ColorTool.def("IsColorByLayer", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TDF_Label &) const) &XCAFDoc_ColorTool::IsColorByLayer, "Return TRUE if object color defined by its Layer, FALSE if not.", py::arg("L"));
cls_XCAFDoc_ColorTool.def("SetColorByLayer", [](XCAFDoc_ColorTool &self, const TDF_Label & a0) -> void { return self.SetColorByLayer(a0); });
cls_XCAFDoc_ColorTool.def("SetColorByLayer", (void (XCAFDoc_ColorTool::*)(const TDF_Label &, const Standard_Boolean)) &XCAFDoc_ColorTool::SetColorByLayer, "Set the Color defined by Layer flag on label. Do nothing if there no any object. Set UAttribute with corresponding GUID.", py::arg("shapeLabel"), py::arg("isColorByLayer"));
cls_XCAFDoc_ColorTool.def("SetInstanceColor", [](XCAFDoc_ColorTool &self, const TopoDS_Shape & a0, const XCAFDoc_ColorType a1, const Quantity_Color & a2) -> Standard_Boolean { return self.SetInstanceColor(a0, a1, a2); });
cls_XCAFDoc_ColorTool.def("SetInstanceColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TopoDS_Shape &, const XCAFDoc_ColorType, const Quantity_Color &, const Standard_Boolean)) &XCAFDoc_ColorTool::SetInstanceColor, "Sets the color of component that styled with SHUO structure Returns FALSE if no sush component found NOTE: create SHUO structeure if it is necessary and if <isCreateSHUO>", py::arg("theShape"), py::arg("type"), py::arg("color"), py::arg("isCreateSHUO"));
cls_XCAFDoc_ColorTool.def("SetInstanceColor", [](XCAFDoc_ColorTool &self, const TopoDS_Shape & a0, const XCAFDoc_ColorType a1, const Quantity_ColorRGBA & a2) -> Standard_Boolean { return self.SetInstanceColor(a0, a1, a2); });
cls_XCAFDoc_ColorTool.def("SetInstanceColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TopoDS_Shape &, const XCAFDoc_ColorType, const Quantity_ColorRGBA &, const Standard_Boolean)) &XCAFDoc_ColorTool::SetInstanceColor, "Sets the color of component that styled with SHUO structure Returns FALSE if no sush component found NOTE: create SHUO structeure if it is necessary and if <isCreateSHUO>", py::arg("theShape"), py::arg("type"), py::arg("color"), py::arg("isCreateSHUO"));
cls_XCAFDoc_ColorTool.def("GetInstanceColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TopoDS_Shape &, const XCAFDoc_ColorType, Quantity_Color &)) &XCAFDoc_ColorTool::GetInstanceColor, "Gets the color of component that styled with SHUO structure Returns FALSE if no sush component or color type", py::arg("theShape"), py::arg("type"), py::arg("color"));
cls_XCAFDoc_ColorTool.def("GetInstanceColor", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TopoDS_Shape &, const XCAFDoc_ColorType, Quantity_ColorRGBA &)) &XCAFDoc_ColorTool::GetInstanceColor, "Gets the color of component that styled with SHUO structure Returns FALSE if no sush component or color type", py::arg("theShape"), py::arg("type"), py::arg("color"));
cls_XCAFDoc_ColorTool.def("IsInstanceVisible", (Standard_Boolean (XCAFDoc_ColorTool::*)(const TopoDS_Shape &)) &XCAFDoc_ColorTool::IsInstanceVisible, "Gets the visibility status of component that styled with SHUO structure Returns FALSE if no sush component", py::arg("theShape"));
cls_XCAFDoc_ColorTool.def("ReverseChainsOfTreeNodes", (Standard_Boolean (XCAFDoc_ColorTool::*)()) &XCAFDoc_ColorTool::ReverseChainsOfTreeNodes, "Reverses order in chains of TreeNodes (from Last to First) under each Color Label since we became to use function ::Prepend() instead of ::Append() in method SetColor() for acceleration");
cls_XCAFDoc_ColorTool.def("ID", (const Standard_GUID & (XCAFDoc_ColorTool::*)() const) &XCAFDoc_ColorTool::ID, "None");
cls_XCAFDoc_ColorTool.def("Restore", (void (XCAFDoc_ColorTool::*)(const opencascade::handle<TDF_Attribute> &)) &XCAFDoc_ColorTool::Restore, "None", py::arg("with"));
cls_XCAFDoc_ColorTool.def("NewEmpty", (opencascade::handle<TDF_Attribute> (XCAFDoc_ColorTool::*)() const) &XCAFDoc_ColorTool::NewEmpty, "None");
cls_XCAFDoc_ColorTool.def("Paste", (void (XCAFDoc_ColorTool::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &XCAFDoc_ColorTool::Paste, "None", py::arg("into"), py::arg("RT"));
cls_XCAFDoc_ColorTool.def_static("get_type_name_", (const char * (*)()) &XCAFDoc_ColorTool::get_type_name, "None");
cls_XCAFDoc_ColorTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XCAFDoc_ColorTool::get_type_descriptor, "None");
cls_XCAFDoc_ColorTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (XCAFDoc_ColorTool::*)() const) &XCAFDoc_ColorTool::DynamicType, "None");

// Enums

}