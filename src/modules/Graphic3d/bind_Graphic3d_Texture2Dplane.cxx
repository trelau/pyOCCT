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
#include <Graphic3d_Texture2D.hxx>
#include <TCollection_AsciiString.hxx>
#include <Graphic3d_NameOfTexture2D.hxx>
#include <Standard_Handle.hxx>
#include <Image_PixMap.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_NameOfTexturePlane.hxx>
#include <Graphic3d_Texture2Dplane.hxx>
#include <Standard_Type.hxx>

void bind_Graphic3d_Texture2Dplane(py::module &mod){

py::class_<Graphic3d_Texture2Dplane, opencascade::handle<Graphic3d_Texture2Dplane>, Graphic3d_Texture2D> cls_Graphic3d_Texture2Dplane(mod, "Graphic3d_Texture2Dplane", "This class allows the management of a 2D texture defined from a plane equation Use the SetXXX() methods for positioning the texture as you want.");

// Constructors
cls_Graphic3d_Texture2Dplane.def(py::init<const TCollection_AsciiString &>(), py::arg("theFileName"));
cls_Graphic3d_Texture2Dplane.def(py::init<const Graphic3d_NameOfTexture2D>(), py::arg("theNOT"));
cls_Graphic3d_Texture2Dplane.def(py::init<const opencascade::handle<Image_PixMap> &>(), py::arg("thePixMap"));

// Fields

// Methods
cls_Graphic3d_Texture2Dplane.def("SetPlaneS", (void (Graphic3d_Texture2Dplane::*)(const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal)) &Graphic3d_Texture2Dplane::SetPlaneS, "Defines the texture projection plane for texture coordinate S default is <1.0, 0.0, 0.0, 0.0>", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"));
cls_Graphic3d_Texture2Dplane.def("SetPlaneT", (void (Graphic3d_Texture2Dplane::*)(const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal)) &Graphic3d_Texture2Dplane::SetPlaneT, "Defines the texture projection plane for texture coordinate T default is <0.0, 1.0, 0.0, 0.0>", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"));
cls_Graphic3d_Texture2Dplane.def("SetPlane", (void (Graphic3d_Texture2Dplane::*)(const Graphic3d_NameOfTexturePlane)) &Graphic3d_Texture2Dplane::SetPlane, "Defines the texture projection plane for both S and T texture coordinate default is NOTP_XY meaning: <1.0, 0.0, 0.0, 0.0> for S and <0.0, 1.0, 0.0, 0.0> for T", py::arg("thePlane"));
cls_Graphic3d_Texture2Dplane.def("SetScaleS", (void (Graphic3d_Texture2Dplane::*)(const Standard_ShortReal)) &Graphic3d_Texture2Dplane::SetScaleS, "Defines the texture scale for the S texture coordinate much easier than recomputing the S plane equation but the result is the same default to 1.0", py::arg("theVal"));
cls_Graphic3d_Texture2Dplane.def("SetScaleT", (void (Graphic3d_Texture2Dplane::*)(const Standard_ShortReal)) &Graphic3d_Texture2Dplane::SetScaleT, "Defines the texture scale for the T texture coordinate much easier than recompution the T plane equation but the result is the same default to 1.0", py::arg("theVal"));
cls_Graphic3d_Texture2Dplane.def("SetTranslateS", (void (Graphic3d_Texture2Dplane::*)(const Standard_ShortReal)) &Graphic3d_Texture2Dplane::SetTranslateS, "Defines the texture translation for the S texture coordinate you can obtain the same effect by modifying the S plane equation but its not easier. default to 0.0", py::arg("theVal"));
cls_Graphic3d_Texture2Dplane.def("SetTranslateT", (void (Graphic3d_Texture2Dplane::*)(const Standard_ShortReal)) &Graphic3d_Texture2Dplane::SetTranslateT, "Defines the texture translation for the T texture coordinate you can obtain the same effect by modifying the T plane equation but its not easier. default to 0.0", py::arg("theVal"));
cls_Graphic3d_Texture2Dplane.def("SetRotation", (void (Graphic3d_Texture2Dplane::*)(const Standard_ShortReal)) &Graphic3d_Texture2Dplane::SetRotation, "Sets the rotation angle of the whole texture. the same result might be achieved by recomputing the S and T plane equation but it's not the easiest way... the angle is expressed in degrees default is 0.0", py::arg("theVal"));
cls_Graphic3d_Texture2Dplane.def("Plane", (Graphic3d_NameOfTexturePlane (Graphic3d_Texture2Dplane::*)() const) &Graphic3d_Texture2Dplane::Plane, "Returns the current texture plane name or NOTP_UNKNOWN when the plane is user defined.");
cls_Graphic3d_Texture2Dplane.def("PlaneS", (void (Graphic3d_Texture2Dplane::*)(Standard_ShortReal &, Standard_ShortReal &, Standard_ShortReal &, Standard_ShortReal &) const) &Graphic3d_Texture2Dplane::PlaneS, "Returns the current texture plane S equation", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"));
cls_Graphic3d_Texture2Dplane.def("PlaneT", (void (Graphic3d_Texture2Dplane::*)(Standard_ShortReal &, Standard_ShortReal &, Standard_ShortReal &, Standard_ShortReal &) const) &Graphic3d_Texture2Dplane::PlaneT, "Returns the current texture plane T equation", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"));
cls_Graphic3d_Texture2Dplane.def("TranslateS", (void (Graphic3d_Texture2Dplane::*)(Standard_ShortReal &) const) &Graphic3d_Texture2Dplane::TranslateS, "Returns the current texture S translation value", py::arg("theVal"));
cls_Graphic3d_Texture2Dplane.def("TranslateT", (void (Graphic3d_Texture2Dplane::*)(Standard_ShortReal &) const) &Graphic3d_Texture2Dplane::TranslateT, "Returns the current texture T translation value", py::arg("theVal"));
cls_Graphic3d_Texture2Dplane.def("ScaleS", (void (Graphic3d_Texture2Dplane::*)(Standard_ShortReal &) const) &Graphic3d_Texture2Dplane::ScaleS, "Returns the current texture S scale value", py::arg("theVal"));
cls_Graphic3d_Texture2Dplane.def("ScaleT", (void (Graphic3d_Texture2Dplane::*)(Standard_ShortReal &) const) &Graphic3d_Texture2Dplane::ScaleT, "Returns the current texture T scale value", py::arg("theVal"));
cls_Graphic3d_Texture2Dplane.def("Rotation", (void (Graphic3d_Texture2Dplane::*)(Standard_ShortReal &) const) &Graphic3d_Texture2Dplane::Rotation, "Returns the current texture rotation angle", py::arg("theVal"));
cls_Graphic3d_Texture2Dplane.def_static("get_type_name_", (const char * (*)()) &Graphic3d_Texture2Dplane::get_type_name, "None");
cls_Graphic3d_Texture2Dplane.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_Texture2Dplane::get_type_descriptor, "None");
cls_Graphic3d_Texture2Dplane.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_Texture2Dplane::*)() const) &Graphic3d_Texture2Dplane::DynamicType, "None");

// Enums

}