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
#include <AIS_Shape.hxx>
#include <TopoDS_Shape.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <Image_PixMap.hxx>
#include <Standard_TypeDef.hxx>
#include <Quantity_Color.hxx>
#include <Graphic3d_MaterialAspect.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_Presentation.hxx>
#include <Graphic3d_Texture2Dmanual.hxx>
#include <Graphic3d_AspectFillArea3d.hxx>
#include <Graphic3d_NameOfTexture2D.hxx>
#include <AIS_TexturedShape.hxx>
#include <Standard_Type.hxx>

void bind_AIS_TexturedShape(py::module &mod){

py::class_<AIS_TexturedShape, opencascade::handle<AIS_TexturedShape>, AIS_Shape> cls_AIS_TexturedShape(mod, "AIS_TexturedShape", "This class allows to map textures on shapes. Presentations modes AIS_WireFrame (0) and AIS_Shaded (1) behave in the same manner as in AIS_Shape, whilst new modes 2 (bounding box) and 3 (texture mapping) extends it functionality.");

// Constructors
cls_AIS_TexturedShape.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));

// Fields

// Methods
cls_AIS_TexturedShape.def("SetTextureFileName", (void (AIS_TexturedShape::*)(const TCollection_AsciiString &)) &AIS_TexturedShape::SetTextureFileName, "Sets the texture source. <theTextureFileName> can specify path to texture image or one of the standard predefined textures. The accepted file types are those used in Image_AlienPixMap with extensions such as rgb, png, jpg and more. To specify the standard predefined texture, the <theTextureFileName> should contain integer - the Graphic3d_NameOfTexture2D enumeration index. Setting texture source using this method resets the source pixmap (if was set previously).", py::arg("theTextureFileName"));
cls_AIS_TexturedShape.def("SetTexturePixMap", (void (AIS_TexturedShape::*)(const opencascade::handle<Image_PixMap> &)) &AIS_TexturedShape::SetTexturePixMap, "Sets the texture source. <theTexturePixMap> specifies image data. Please note that the data should be in Bottom-Up order, the flag of Image_PixMap::IsTopDown() will be ignored by graphic driver. Setting texture source using this method resets the source by filename (if was set previously).", py::arg("theTexturePixMap"));
cls_AIS_TexturedShape.def("TextureMapState", (Standard_Boolean (AIS_TexturedShape::*)() const) &AIS_TexturedShape::TextureMapState, "Returns flag to control texture mapping (for presentation mode 3)");
cls_AIS_TexturedShape.def("SetTextureMapOn", (void (AIS_TexturedShape::*)()) &AIS_TexturedShape::SetTextureMapOn, "Enables texture mapping");
cls_AIS_TexturedShape.def("SetTextureMapOff", (void (AIS_TexturedShape::*)()) &AIS_TexturedShape::SetTextureMapOff, "Disables texture mapping");
cls_AIS_TexturedShape.def("TextureFile", (Standard_CString (AIS_TexturedShape::*)() const) &AIS_TexturedShape::TextureFile, "Returns path to the texture file");
cls_AIS_TexturedShape.def("TexturePixMap", (const opencascade::handle<Image_PixMap> & (AIS_TexturedShape::*)() const) &AIS_TexturedShape::TexturePixMap, "Returns the source pixmap for texture map");
cls_AIS_TexturedShape.def("UpdateAttributes", (void (AIS_TexturedShape::*)()) &AIS_TexturedShape::UpdateAttributes, "Use this method to display the textured shape without recomputing the whole presentation. Use this method when ONLY the texture content has been changed. If other parameters (ie: scale factors, texture origin, texture repeat...) have changed, the whole presentation has to be recomputed:");
cls_AIS_TexturedShape.def("SetColor", (void (AIS_TexturedShape::*)(const Quantity_Color &)) &AIS_TexturedShape::SetColor, "Sets the color.", py::arg("theColor"));
cls_AIS_TexturedShape.def("UnsetColor", (void (AIS_TexturedShape::*)()) &AIS_TexturedShape::UnsetColor, "Removes settings for the color.");
cls_AIS_TexturedShape.def("SetMaterial", (void (AIS_TexturedShape::*)(const Graphic3d_MaterialAspect &)) &AIS_TexturedShape::SetMaterial, "Sets the material aspect.", py::arg("theAspect"));
cls_AIS_TexturedShape.def("UnsetMaterial", (void (AIS_TexturedShape::*)()) &AIS_TexturedShape::UnsetMaterial, "Removes settings for material aspect.");
cls_AIS_TexturedShape.def("EnableTextureModulate", (void (AIS_TexturedShape::*)()) &AIS_TexturedShape::EnableTextureModulate, "Enables texture modulation");
cls_AIS_TexturedShape.def("DisableTextureModulate", (void (AIS_TexturedShape::*)()) &AIS_TexturedShape::DisableTextureModulate, "Disables texture modulation");
cls_AIS_TexturedShape.def("TextureRepeat", (Standard_Boolean (AIS_TexturedShape::*)() const) &AIS_TexturedShape::TextureRepeat, "Returns texture repeat flag");
cls_AIS_TexturedShape.def("URepeat", (Standard_Real (AIS_TexturedShape::*)() const) &AIS_TexturedShape::URepeat, "Returns texture repeat U value");
cls_AIS_TexturedShape.def("VRepeat", (Standard_Real (AIS_TexturedShape::*)() const) &AIS_TexturedShape::VRepeat, "Returns texture repeat V value");
cls_AIS_TexturedShape.def("SetTextureRepeat", [](AIS_TexturedShape &self, const Standard_Boolean a0) -> void { return self.SetTextureRepeat(a0); });
cls_AIS_TexturedShape.def("SetTextureRepeat", [](AIS_TexturedShape &self, const Standard_Boolean a0, const Standard_Real a1) -> void { return self.SetTextureRepeat(a0, a1); });
cls_AIS_TexturedShape.def("SetTextureRepeat", (void (AIS_TexturedShape::*)(const Standard_Boolean, const Standard_Real, const Standard_Real)) &AIS_TexturedShape::SetTextureRepeat, "Sets the number of occurrences of the texture on each face. The texture itself is parameterized in (0,1) by (0,1). Each face of the shape to be textured is parameterized in UV space (Umin,Umax) by (Vmin,Vmax). If RepeatYN is set to false, texture coordinates are clamped in the range (0,1)x(0,1) of the face.", py::arg("theToRepeat"), py::arg("theURepeat"), py::arg("theVRepeat"));
cls_AIS_TexturedShape.def("TextureOrigin", (Standard_Boolean (AIS_TexturedShape::*)() const) &AIS_TexturedShape::TextureOrigin, "Returns true if texture UV origin has been modified");
cls_AIS_TexturedShape.def("TextureUOrigin", (Standard_Real (AIS_TexturedShape::*)() const) &AIS_TexturedShape::TextureUOrigin, "Returns texture origin U position (0.0 by default)");
cls_AIS_TexturedShape.def("TextureVOrigin", (Standard_Real (AIS_TexturedShape::*)() const) &AIS_TexturedShape::TextureVOrigin, "Returns texture origin V position (0.0 by default)");
cls_AIS_TexturedShape.def("SetTextureOrigin", [](AIS_TexturedShape &self, const Standard_Boolean a0) -> void { return self.SetTextureOrigin(a0); });
cls_AIS_TexturedShape.def("SetTextureOrigin", [](AIS_TexturedShape &self, const Standard_Boolean a0, const Standard_Real a1) -> void { return self.SetTextureOrigin(a0, a1); });
cls_AIS_TexturedShape.def("SetTextureOrigin", (void (AIS_TexturedShape::*)(const Standard_Boolean, const Standard_Real, const Standard_Real)) &AIS_TexturedShape::SetTextureOrigin, "Use this method to change the origin of the texture. The texel (0,0) will be mapped to the surface (UOrigin,VOrigin)", py::arg("theToSetTextureOrigin"), py::arg("theUOrigin"), py::arg("theVOrigin"));
cls_AIS_TexturedShape.def("TextureScale", (Standard_Boolean (AIS_TexturedShape::*)() const) &AIS_TexturedShape::TextureScale, "Returns true if scale factor should be applied to texture mapping");
cls_AIS_TexturedShape.def("TextureScaleU", (Standard_Real (AIS_TexturedShape::*)() const) &AIS_TexturedShape::TextureScaleU, "Returns scale factor for U coordinate (1.0 by default)");
cls_AIS_TexturedShape.def("TextureScaleV", (Standard_Real (AIS_TexturedShape::*)() const) &AIS_TexturedShape::TextureScaleV, "Returns scale factor for V coordinate (1.0 by default)");
cls_AIS_TexturedShape.def("SetTextureScale", [](AIS_TexturedShape &self, const Standard_Boolean a0) -> void { return self.SetTextureScale(a0); });
cls_AIS_TexturedShape.def("SetTextureScale", [](AIS_TexturedShape &self, const Standard_Boolean a0, const Standard_Real a1) -> void { return self.SetTextureScale(a0, a1); });
cls_AIS_TexturedShape.def("SetTextureScale", (void (AIS_TexturedShape::*)(const Standard_Boolean, const Standard_Real, const Standard_Real)) &AIS_TexturedShape::SetTextureScale, "Use this method to scale the texture (percent of the face). You can specify a scale factor for both U and V. Example: if you set ScaleU and ScaleV to 0.5 and you enable texture repeat, the texture will appear twice on the face in each direction.", py::arg("theToSetTextureScale"), py::arg("theScaleU"), py::arg("theScaleV"));
cls_AIS_TexturedShape.def("ShowTriangles", (Standard_Boolean (AIS_TexturedShape::*)() const) &AIS_TexturedShape::ShowTriangles, "Returns true if displaying of triangles is requested");
cls_AIS_TexturedShape.def("ShowTriangles", (void (AIS_TexturedShape::*)(const Standard_Boolean)) &AIS_TexturedShape::ShowTriangles, "Use this method to show the triangulation of the shape (for debugging etc.).", py::arg("theToShowTriangles"));
cls_AIS_TexturedShape.def("TextureModulate", (Standard_Boolean (AIS_TexturedShape::*)() const) &AIS_TexturedShape::TextureModulate, "Returns true if texture color modulation is turned on");
cls_AIS_TexturedShape.def_static("get_type_name_", (const char * (*)()) &AIS_TexturedShape::get_type_name, "None");
cls_AIS_TexturedShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_TexturedShape::get_type_descriptor, "None");
cls_AIS_TexturedShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_TexturedShape::*)() const) &AIS_TexturedShape::DynamicType, "None");

// Enums

}