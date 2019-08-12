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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <Graphic3d_AspectFillArea3d.hxx>
#include <Standard_Type.hxx>
#include <Aspect_InteriorStyle.hxx>
#include <Quantity_Color.hxx>
#include <Aspect_TypeOfLine.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_MaterialAspect.hxx>
#include <Graphic3d_TypeOfShadingModel.hxx>
#include <Graphic3d_AlphaMode.hxx>
#include <Quantity_ColorRGBA.hxx>
#include <Graphic3d_ShaderProgram.hxx>
#include <Graphic3d_TextureSet.hxx>
#include <Graphic3d_TextureMap.hxx>
#include <Graphic3d_PolygonOffset.hxx>
#include <Aspect_PolygonOffsetMode.hxx>
#include <Aspect_AspectFillAreaDefinitionError.hxx>
#include <Graphic3d_HatchStyle.hxx>
#include <Aspect_HatchStyle.hxx>

void bind_Graphic3d_AspectFillArea3d(py::module &mod){

py::class_<Graphic3d_AspectFillArea3d, opencascade::handle<Graphic3d_AspectFillArea3d>, Standard_Transient> cls_Graphic3d_AspectFillArea3d(mod, "Graphic3d_AspectFillArea3d", "This class defines graphic attributes for opaque 3d primitives (polygons, triangles, quadrilaterals).");

// Constructors
cls_Graphic3d_AspectFillArea3d.def(py::init<>());
cls_Graphic3d_AspectFillArea3d.def(py::init<const Aspect_InteriorStyle, const Quantity_Color &, const Quantity_Color &, const Aspect_TypeOfLine, const Standard_Real, const Graphic3d_MaterialAspect &, const Graphic3d_MaterialAspect &>(), py::arg("theInterior"), py::arg("theInteriorColor"), py::arg("theEdgeColor"), py::arg("theEdgeLineType"), py::arg("theEdgeWidth"), py::arg("theFrontMaterial"), py::arg("theBackMaterial"));

// Fields

// Methods
cls_Graphic3d_AspectFillArea3d.def_static("get_type_name_", (const char * (*)()) &Graphic3d_AspectFillArea3d::get_type_name, "None");
cls_Graphic3d_AspectFillArea3d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_AspectFillArea3d::get_type_descriptor, "None");
cls_Graphic3d_AspectFillArea3d.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_AspectFillArea3d::*)() const) &Graphic3d_AspectFillArea3d::DynamicType, "None");
cls_Graphic3d_AspectFillArea3d.def("InteriorStyle", (Aspect_InteriorStyle (Graphic3d_AspectFillArea3d::*)() const) &Graphic3d_AspectFillArea3d::InteriorStyle, "Return interior rendering style (Aspect_IS_EMPTY by default, which means nothing will be rendered!).");
cls_Graphic3d_AspectFillArea3d.def("SetInteriorStyle", (void (Graphic3d_AspectFillArea3d::*)(const Aspect_InteriorStyle)) &Graphic3d_AspectFillArea3d::SetInteriorStyle, "Modifies the interior type used for rendering", py::arg("theStyle"));
cls_Graphic3d_AspectFillArea3d.def("ShadingModel", (Graphic3d_TypeOfShadingModel (Graphic3d_AspectFillArea3d::*)() const) &Graphic3d_AspectFillArea3d::ShadingModel, "Returns shading model (Graphic3d_TOSM_DEFAULT by default, which means that Shading Model set as default for entire Viewer will be used)");
cls_Graphic3d_AspectFillArea3d.def("SetShadingModel", (void (Graphic3d_AspectFillArea3d::*)(const Graphic3d_TypeOfShadingModel)) &Graphic3d_AspectFillArea3d::SetShadingModel, "Sets shading model", py::arg("theShadingModel"));
cls_Graphic3d_AspectFillArea3d.def("AlphaMode", (Graphic3d_AlphaMode (Graphic3d_AspectFillArea3d::*)() const) &Graphic3d_AspectFillArea3d::AlphaMode, "Returns the way how alpha value should be treated (Graphic3d_AlphaMode_BlendAuto by default, for backward compatibility).");
cls_Graphic3d_AspectFillArea3d.def("AlphaCutoff", (Standard_ShortReal (Graphic3d_AspectFillArea3d::*)() const) &Graphic3d_AspectFillArea3d::AlphaCutoff, "Returns alpha cutoff threshold, for discarding fragments within Graphic3d_AlphaMode_Mask mode (0.5 by default). If the alpha value is greater than or equal to this value then it is rendered as fully opaque, otherwise, it is rendered as fully transparent.");
cls_Graphic3d_AspectFillArea3d.def("SetAlphaMode", [](Graphic3d_AspectFillArea3d &self, Graphic3d_AlphaMode a0) -> void { return self.SetAlphaMode(a0); });
cls_Graphic3d_AspectFillArea3d.def("SetAlphaMode", (void (Graphic3d_AspectFillArea3d::*)(Graphic3d_AlphaMode, Standard_ShortReal)) &Graphic3d_AspectFillArea3d::SetAlphaMode, "Defines the way how alpha value should be treated.", py::arg("theMode"), py::arg("theAlphaCutoff"));
cls_Graphic3d_AspectFillArea3d.def("InteriorColor", (const Quantity_Color & (Graphic3d_AspectFillArea3d::*)() const) &Graphic3d_AspectFillArea3d::InteriorColor, "Return interior color.");
cls_Graphic3d_AspectFillArea3d.def("InteriorColorRGBA", (const Quantity_ColorRGBA & (Graphic3d_AspectFillArea3d::*)() const) &Graphic3d_AspectFillArea3d::InteriorColorRGBA, "Return interior color.");
cls_Graphic3d_AspectFillArea3d.def("SetInteriorColor", (void (Graphic3d_AspectFillArea3d::*)(const Quantity_Color &)) &Graphic3d_AspectFillArea3d::SetInteriorColor, "Modifies the color of the interior of the face", py::arg("theColor"));
cls_Graphic3d_AspectFillArea3d.def("SetInteriorColor", (void (Graphic3d_AspectFillArea3d::*)(const Quantity_ColorRGBA &)) &Graphic3d_AspectFillArea3d::SetInteriorColor, "Modifies the color of the interior of the face", py::arg("theColor"));
cls_Graphic3d_AspectFillArea3d.def("BackInteriorColor", (const Quantity_Color & (Graphic3d_AspectFillArea3d::*)() const) &Graphic3d_AspectFillArea3d::BackInteriorColor, "Return back interior color.");
cls_Graphic3d_AspectFillArea3d.def("BackInteriorColorRGBA", (const Quantity_ColorRGBA & (Graphic3d_AspectFillArea3d::*)() const) &Graphic3d_AspectFillArea3d::BackInteriorColorRGBA, "Return back interior color.");
cls_Graphic3d_AspectFillArea3d.def("SetBackInteriorColor", (void (Graphic3d_AspectFillArea3d::*)(const Quantity_Color &)) &Graphic3d_AspectFillArea3d::SetBackInteriorColor, "Modifies the color of the interior of the back face", py::arg("theColor"));
cls_Graphic3d_AspectFillArea3d.def("SetBackInteriorColor", (void (Graphic3d_AspectFillArea3d::*)(const Quantity_ColorRGBA &)) &Graphic3d_AspectFillArea3d::SetBackInteriorColor, "Modifies the color of the interior of the back face", py::arg("theColor"));
cls_Graphic3d_AspectFillArea3d.def("FrontMaterial", (const Graphic3d_MaterialAspect & (Graphic3d_AspectFillArea3d::*)() const) &Graphic3d_AspectFillArea3d::FrontMaterial, "Returns the surface material of external faces");
cls_Graphic3d_AspectFillArea3d.def("ChangeFrontMaterial", (Graphic3d_MaterialAspect & (Graphic3d_AspectFillArea3d::*)()) &Graphic3d_AspectFillArea3d::ChangeFrontMaterial, "Returns the surface material of external faces");
cls_Graphic3d_AspectFillArea3d.def("SetFrontMaterial", (void (Graphic3d_AspectFillArea3d::*)(const Graphic3d_MaterialAspect &)) &Graphic3d_AspectFillArea3d::SetFrontMaterial, "Modifies the surface material of external faces", py::arg("theMaterial"));
cls_Graphic3d_AspectFillArea3d.def("BackMaterial", (const Graphic3d_MaterialAspect & (Graphic3d_AspectFillArea3d::*)() const) &Graphic3d_AspectFillArea3d::BackMaterial, "Returns the surface material of internal faces");
cls_Graphic3d_AspectFillArea3d.def("ChangeBackMaterial", (Graphic3d_MaterialAspect & (Graphic3d_AspectFillArea3d::*)()) &Graphic3d_AspectFillArea3d::ChangeBackMaterial, "Returns the surface material of internal faces");
cls_Graphic3d_AspectFillArea3d.def("SetBackMaterial", (void (Graphic3d_AspectFillArea3d::*)(const Graphic3d_MaterialAspect &)) &Graphic3d_AspectFillArea3d::SetBackMaterial, "Modifies the surface material of internal faces", py::arg("theMaterial"));
cls_Graphic3d_AspectFillArea3d.def("ToSuppressBackFaces", (bool (Graphic3d_AspectFillArea3d::*)() const) &Graphic3d_AspectFillArea3d::ToSuppressBackFaces, "Returns true if back faces should be suppressed (true by default).");
cls_Graphic3d_AspectFillArea3d.def("SetSuppressBackFaces", (void (Graphic3d_AspectFillArea3d::*)(bool)) &Graphic3d_AspectFillArea3d::SetSuppressBackFaces, "Assign back faces culling flag.", py::arg("theToSuppress"));
cls_Graphic3d_AspectFillArea3d.def("BackFace", (bool (Graphic3d_AspectFillArea3d::*)() const) &Graphic3d_AspectFillArea3d::BackFace, "Returns true if back faces should be suppressed (true by default).");
cls_Graphic3d_AspectFillArea3d.def("AllowBackFace", (void (Graphic3d_AspectFillArea3d::*)()) &Graphic3d_AspectFillArea3d::AllowBackFace, "Allows the display of back-facing filled polygons.");
cls_Graphic3d_AspectFillArea3d.def("SuppressBackFace", (void (Graphic3d_AspectFillArea3d::*)()) &Graphic3d_AspectFillArea3d::SuppressBackFace, "Suppress the display of back-facing filled polygons. A back-facing polygon is defined as a polygon whose vertices are in a clockwise order with respect to screen coordinates.");
cls_Graphic3d_AspectFillArea3d.def("Distinguish", (bool (Graphic3d_AspectFillArea3d::*)() const) &Graphic3d_AspectFillArea3d::Distinguish, "Returns true if material properties should be distinguished for back and front faces (false by default).");
cls_Graphic3d_AspectFillArea3d.def("SetDistinguish", (void (Graphic3d_AspectFillArea3d::*)(bool)) &Graphic3d_AspectFillArea3d::SetDistinguish, "Set material distinction between front and back faces.", py::arg("toDistinguish"));
cls_Graphic3d_AspectFillArea3d.def("SetDistinguishOn", (void (Graphic3d_AspectFillArea3d::*)()) &Graphic3d_AspectFillArea3d::SetDistinguishOn, "Allows material distinction between front and back faces.");
cls_Graphic3d_AspectFillArea3d.def("SetDistinguishOff", (void (Graphic3d_AspectFillArea3d::*)()) &Graphic3d_AspectFillArea3d::SetDistinguishOff, "Forbids material distinction between front and back faces.");
cls_Graphic3d_AspectFillArea3d.def("ShaderProgram", (const opencascade::handle<Graphic3d_ShaderProgram> & (Graphic3d_AspectFillArea3d::*)() const) &Graphic3d_AspectFillArea3d::ShaderProgram, "Return shader program.");
cls_Graphic3d_AspectFillArea3d.def("SetShaderProgram", (void (Graphic3d_AspectFillArea3d::*)(const opencascade::handle<Graphic3d_ShaderProgram> &)) &Graphic3d_AspectFillArea3d::SetShaderProgram, "Sets up OpenGL/GLSL shader program.", py::arg("theProgram"));
cls_Graphic3d_AspectFillArea3d.def("TextureSet", (const opencascade::handle<Graphic3d_TextureSet> & (Graphic3d_AspectFillArea3d::*)() const) &Graphic3d_AspectFillArea3d::TextureSet, "Return texture array to be mapped.");
cls_Graphic3d_AspectFillArea3d.def("SetTextureSet", (void (Graphic3d_AspectFillArea3d::*)(const opencascade::handle<Graphic3d_TextureSet> &)) &Graphic3d_AspectFillArea3d::SetTextureSet, "Setup texture array to be mapped.", py::arg("theTextures"));
cls_Graphic3d_AspectFillArea3d.def("TextureMap", (opencascade::handle<Graphic3d_TextureMap> (Graphic3d_AspectFillArea3d::*)() const) &Graphic3d_AspectFillArea3d::TextureMap, "Return texture to be mapped.");
cls_Graphic3d_AspectFillArea3d.def("SetTextureMap", (void (Graphic3d_AspectFillArea3d::*)(const opencascade::handle<Graphic3d_TextureMap> &)) &Graphic3d_AspectFillArea3d::SetTextureMap, "Assign texture to be mapped. See also SetTextureMapOn() to actually activate texture mapping.", py::arg("theTexture"));
cls_Graphic3d_AspectFillArea3d.def("ToMapTexture", (bool (Graphic3d_AspectFillArea3d::*)() const) &Graphic3d_AspectFillArea3d::ToMapTexture, "Return true if texture mapping is enabled (false by default).");
cls_Graphic3d_AspectFillArea3d.def("TextureMapState", (bool (Graphic3d_AspectFillArea3d::*)() const) &Graphic3d_AspectFillArea3d::TextureMapState, "Return true if texture mapping is enabled (false by default).");
cls_Graphic3d_AspectFillArea3d.def("SetTextureMapOn", (void (Graphic3d_AspectFillArea3d::*)(bool)) &Graphic3d_AspectFillArea3d::SetTextureMapOn, "Enable or disable texture mapping (has no effect if texture is not set).", py::arg("theToMap"));
cls_Graphic3d_AspectFillArea3d.def("SetTextureMapOn", (void (Graphic3d_AspectFillArea3d::*)()) &Graphic3d_AspectFillArea3d::SetTextureMapOn, "Enable texture mapping (has no effect if texture is not set).");
cls_Graphic3d_AspectFillArea3d.def("SetTextureMapOff", (void (Graphic3d_AspectFillArea3d::*)()) &Graphic3d_AspectFillArea3d::SetTextureMapOff, "Disable texture mapping.");
cls_Graphic3d_AspectFillArea3d.def("PolygonOffset", (const Graphic3d_PolygonOffset & (Graphic3d_AspectFillArea3d::*)() const) &Graphic3d_AspectFillArea3d::PolygonOffset, "Returns current polygon offsets settings.");
cls_Graphic3d_AspectFillArea3d.def("PolygonOffsets", [](Graphic3d_AspectFillArea3d &self, Standard_Integer & theMode, Standard_ShortReal & theFactor, Standard_ShortReal & theUnits){ self.PolygonOffsets(theMode, theFactor, theUnits); return theMode; }, "Returns current polygon offsets settings.", py::arg("theMode"), py::arg("theFactor"), py::arg("theUnits"));
cls_Graphic3d_AspectFillArea3d.def("SetPolygonOffsets", [](Graphic3d_AspectFillArea3d &self, const Standard_Integer a0) -> void { return self.SetPolygonOffsets(a0); });
cls_Graphic3d_AspectFillArea3d.def("SetPolygonOffsets", [](Graphic3d_AspectFillArea3d &self, const Standard_Integer a0, const Standard_ShortReal a1) -> void { return self.SetPolygonOffsets(a0, a1); });
cls_Graphic3d_AspectFillArea3d.def("SetPolygonOffsets", (void (Graphic3d_AspectFillArea3d::*)(const Standard_Integer, const Standard_ShortReal, const Standard_ShortReal)) &Graphic3d_AspectFillArea3d::SetPolygonOffsets, "Sets up OpenGL polygon offsets mechanism. <aMode> parameter can contain various combinations of Aspect_PolygonOffsetMode enumeration elements (Aspect_POM_None means that polygon offsets are not changed). If <aMode> is different from Aspect_POM_Off and Aspect_POM_None, then <aFactor> and <aUnits> arguments are used by graphic renderer to calculate a depth offset value:", py::arg("theMode"), py::arg("theFactor"), py::arg("theUnits"));
cls_Graphic3d_AspectFillArea3d.def("ToDrawEdges", (bool (Graphic3d_AspectFillArea3d::*)() const) &Graphic3d_AspectFillArea3d::ToDrawEdges, "Returns true if edges should be drawn (false by default).");
cls_Graphic3d_AspectFillArea3d.def("SetDrawEdges", (void (Graphic3d_AspectFillArea3d::*)(bool)) &Graphic3d_AspectFillArea3d::SetDrawEdges, "Set if edges should be drawn or not.", py::arg("theToDraw"));
cls_Graphic3d_AspectFillArea3d.def("Edge", (bool (Graphic3d_AspectFillArea3d::*)() const) &Graphic3d_AspectFillArea3d::Edge, "Returns true if edges should be drawn.");
cls_Graphic3d_AspectFillArea3d.def("SetEdgeOn", (void (Graphic3d_AspectFillArea3d::*)()) &Graphic3d_AspectFillArea3d::SetEdgeOn, "The edges of FillAreas are drawn.");
cls_Graphic3d_AspectFillArea3d.def("SetEdgeOff", (void (Graphic3d_AspectFillArea3d::*)()) &Graphic3d_AspectFillArea3d::SetEdgeOff, "The edges of FillAreas are not drawn.");
cls_Graphic3d_AspectFillArea3d.def("EdgeColor", (const Quantity_Color & (Graphic3d_AspectFillArea3d::*)() const) &Graphic3d_AspectFillArea3d::EdgeColor, "Return color of edges.");
cls_Graphic3d_AspectFillArea3d.def("EdgeColorRGBA", (const Quantity_ColorRGBA & (Graphic3d_AspectFillArea3d::*)() const) &Graphic3d_AspectFillArea3d::EdgeColorRGBA, "Return color of edges.");
cls_Graphic3d_AspectFillArea3d.def("SetEdgeColor", (void (Graphic3d_AspectFillArea3d::*)(const Quantity_Color &)) &Graphic3d_AspectFillArea3d::SetEdgeColor, "Modifies the color of the edge of the face", py::arg("theColor"));
cls_Graphic3d_AspectFillArea3d.def("EdgeLineType", (Aspect_TypeOfLine (Graphic3d_AspectFillArea3d::*)() const) &Graphic3d_AspectFillArea3d::EdgeLineType, "Return edges line type.");
cls_Graphic3d_AspectFillArea3d.def("SetEdgeLineType", (void (Graphic3d_AspectFillArea3d::*)(const Aspect_TypeOfLine)) &Graphic3d_AspectFillArea3d::SetEdgeLineType, "Modifies the edge line type", py::arg("theType"));
cls_Graphic3d_AspectFillArea3d.def("EdgeWidth", (Standard_ShortReal (Graphic3d_AspectFillArea3d::*)() const) &Graphic3d_AspectFillArea3d::EdgeWidth, "Return width for edges in pixels.");
cls_Graphic3d_AspectFillArea3d.def("SetEdgeWidth", (void (Graphic3d_AspectFillArea3d::*)(const Standard_Real)) &Graphic3d_AspectFillArea3d::SetEdgeWidth, "Modifies the edge thickness Warning: Raises AspectFillAreaDefinitionError if the width is a negative value.", py::arg("theWidth"));
cls_Graphic3d_AspectFillArea3d.def("HatchStyle", (const opencascade::handle<Graphic3d_HatchStyle> & (Graphic3d_AspectFillArea3d::*)() const) &Graphic3d_AspectFillArea3d::HatchStyle, "Returns the hatch type used when InteriorStyle is IS_HATCH");
cls_Graphic3d_AspectFillArea3d.def("SetHatchStyle", (void (Graphic3d_AspectFillArea3d::*)(const opencascade::handle<Graphic3d_HatchStyle> &)) &Graphic3d_AspectFillArea3d::SetHatchStyle, "Modifies the hatch type used when InteriorStyle is IS_HATCH", py::arg("theStyle"));
cls_Graphic3d_AspectFillArea3d.def("SetHatchStyle", (void (Graphic3d_AspectFillArea3d::*)(const Aspect_HatchStyle)) &Graphic3d_AspectFillArea3d::SetHatchStyle, "Modifies the hatch type used when InteriorStyle is IS_HATCH", py::arg("theStyle"));
cls_Graphic3d_AspectFillArea3d.def("Values", [](Graphic3d_AspectFillArea3d &self, Aspect_InteriorStyle & theStyle, Quantity_Color & theIntColor, Quantity_Color & theEdgeColor, Aspect_TypeOfLine & theType, Standard_Real & theWidth){ self.Values(theStyle, theIntColor, theEdgeColor, theType, theWidth); return theWidth; }, "Returns the current values.", py::arg("theStyle"), py::arg("theIntColor"), py::arg("theEdgeColor"), py::arg("theType"), py::arg("theWidth"));
cls_Graphic3d_AspectFillArea3d.def("Values", [](Graphic3d_AspectFillArea3d &self, Aspect_InteriorStyle & theStyle, Quantity_Color & theIntColor, Quantity_Color & theBackIntColor, Quantity_Color & theEdgeColor, Aspect_TypeOfLine & theType, Standard_Real & theWidth){ self.Values(theStyle, theIntColor, theBackIntColor, theEdgeColor, theType, theWidth); return theWidth; }, "Returns the current values.", py::arg("theStyle"), py::arg("theIntColor"), py::arg("theBackIntColor"), py::arg("theEdgeColor"), py::arg("theType"), py::arg("theWidth"));

// Enums

}