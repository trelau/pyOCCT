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
#include <Graphic3d_AspectMarker3d.hxx>
#include <Standard_Type.hxx>
#include <Aspect_TypeOfMarker.hxx>
#include <Quantity_Color.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_HArray1OfByte.hxx>
#include <Image_PixMap.hxx>
#include <Quantity_ColorRGBA.hxx>
#include <Aspect_AspectMarkerDefinitionError.hxx>
#include <Graphic3d_MarkerImage.hxx>
#include <Graphic3d_ShaderProgram.hxx>

void bind_Graphic3d_AspectMarker3d(py::module &mod){

py::class_<Graphic3d_AspectMarker3d, opencascade::handle<Graphic3d_AspectMarker3d>, Standard_Transient> cls_Graphic3d_AspectMarker3d(mod, "Graphic3d_AspectMarker3d", "Creates and updates an attribute group for marker type primitives. This group contains the type of marker, its color, and its scale factor.");

// Constructors
cls_Graphic3d_AspectMarker3d.def(py::init<>());
cls_Graphic3d_AspectMarker3d.def(py::init<const Aspect_TypeOfMarker, const Quantity_Color &, const Standard_Real>(), py::arg("theType"), py::arg("theColor"), py::arg("theScale"));
cls_Graphic3d_AspectMarker3d.def(py::init<const Quantity_Color &, const Standard_Integer, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfByte> &>(), py::arg("theColor"), py::arg("theWidth"), py::arg("theHeight"), py::arg("theTextureBitmap"));
cls_Graphic3d_AspectMarker3d.def(py::init<const opencascade::handle<Image_PixMap> &>(), py::arg("theTextureImage"));

// Fields

// Methods
cls_Graphic3d_AspectMarker3d.def_static("get_type_name_", (const char * (*)()) &Graphic3d_AspectMarker3d::get_type_name, "None");
cls_Graphic3d_AspectMarker3d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_AspectMarker3d::get_type_descriptor, "None");
cls_Graphic3d_AspectMarker3d.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_AspectMarker3d::*)() const) &Graphic3d_AspectMarker3d::DynamicType, "None");
cls_Graphic3d_AspectMarker3d.def("ColorRGBA", (const Quantity_ColorRGBA & (Graphic3d_AspectMarker3d::*)() const) &Graphic3d_AspectMarker3d::ColorRGBA, "Return color.");
cls_Graphic3d_AspectMarker3d.def("Color", (const Quantity_Color & (Graphic3d_AspectMarker3d::*)() const) &Graphic3d_AspectMarker3d::Color, "Return the color.");
cls_Graphic3d_AspectMarker3d.def("SetColor", (void (Graphic3d_AspectMarker3d::*)(const Quantity_Color &)) &Graphic3d_AspectMarker3d::SetColor, "Modifies the color.", py::arg("theColor"));
cls_Graphic3d_AspectMarker3d.def("Scale", (Standard_ShortReal (Graphic3d_AspectMarker3d::*)() const) &Graphic3d_AspectMarker3d::Scale, "Return scale factor.");
cls_Graphic3d_AspectMarker3d.def("SetScale", (void (Graphic3d_AspectMarker3d::*)(const Standard_ShortReal)) &Graphic3d_AspectMarker3d::SetScale, "Modifies the scale factor. Marker type Aspect_TOM_POINT is not affected by the marker size scale factor. It is always the smallest displayable dot. Warning: Raises AspectMarkerDefinitionError if the scale is a negative value.", py::arg("theScale"));
cls_Graphic3d_AspectMarker3d.def("SetScale", (void (Graphic3d_AspectMarker3d::*)(const Standard_Real)) &Graphic3d_AspectMarker3d::SetScale, "Assign scale factor.", py::arg("theScale"));
cls_Graphic3d_AspectMarker3d.def("Type", (Aspect_TypeOfMarker (Graphic3d_AspectMarker3d::*)() const) &Graphic3d_AspectMarker3d::Type, "Return marker type.");
cls_Graphic3d_AspectMarker3d.def("SetType", (void (Graphic3d_AspectMarker3d::*)(const Aspect_TypeOfMarker)) &Graphic3d_AspectMarker3d::SetType, "Modifies the type of marker.", py::arg("theType"));
cls_Graphic3d_AspectMarker3d.def("GetTextureSize", [](Graphic3d_AspectMarker3d &self, Standard_Integer & theWidth, Standard_Integer & theHeight){ self.GetTextureSize(theWidth, theHeight); return std::tuple<Standard_Integer &, Standard_Integer &>(theWidth, theHeight); }, "Returns marker's texture size.", py::arg("theWidth"), py::arg("theHeight"));
cls_Graphic3d_AspectMarker3d.def("GetMarkerImage", (const opencascade::handle<Graphic3d_MarkerImage> & (Graphic3d_AspectMarker3d::*)() const) &Graphic3d_AspectMarker3d::GetMarkerImage, "Returns marker's image texture. Could be null handle if marker aspect has been initialized as default type of marker.");
cls_Graphic3d_AspectMarker3d.def("SetMarkerImage", (void (Graphic3d_AspectMarker3d::*)(const opencascade::handle<Graphic3d_MarkerImage> &)) &Graphic3d_AspectMarker3d::SetMarkerImage, "Set marker's image texture.", py::arg("theImage"));
cls_Graphic3d_AspectMarker3d.def("SetBitMap", (void (Graphic3d_AspectMarker3d::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfByte> &)) &Graphic3d_AspectMarker3d::SetBitMap, "None", py::arg("theWidth"), py::arg("theHeight"), py::arg("theTexture"));
cls_Graphic3d_AspectMarker3d.def("ShaderProgram", (const opencascade::handle<Graphic3d_ShaderProgram> & (Graphic3d_AspectMarker3d::*)() const) &Graphic3d_AspectMarker3d::ShaderProgram, "Return the program.");
cls_Graphic3d_AspectMarker3d.def("SetShaderProgram", (void (Graphic3d_AspectMarker3d::*)(const opencascade::handle<Graphic3d_ShaderProgram> &)) &Graphic3d_AspectMarker3d::SetShaderProgram, "Sets up OpenGL/GLSL shader program.", py::arg("theProgram"));
cls_Graphic3d_AspectMarker3d.def("Values", [](Graphic3d_AspectMarker3d &self, Quantity_Color & theColor, Aspect_TypeOfMarker & theType, Standard_Real & theScale){ self.Values(theColor, theType, theScale); return theScale; }, "Returns the current values of the group.", py::arg("theColor"), py::arg("theType"), py::arg("theScale"));

// Enums

}