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
#include <Graphic3d_TextureRoot.hxx>
#include <Standard_Type.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <OSD_Path.hxx>
#include <Graphic3d_TypeOfTexture.hxx>
#include <Image_PixMap.hxx>
#include <Graphic3d_TextureParams.hxx>

void bind_Graphic3d_TextureRoot(py::module &mod){

py::class_<Graphic3d_TextureRoot, opencascade::handle<Graphic3d_TextureRoot>, Standard_Transient> cls_Graphic3d_TextureRoot(mod, "Graphic3d_TextureRoot", "This is the texture root class enable the dialog with the GraphicDriver allows the loading of texture.");

// Constructors

// Fields

// Methods
cls_Graphic3d_TextureRoot.def_static("get_type_name_", (const char * (*)()) &Graphic3d_TextureRoot::get_type_name, "None");
cls_Graphic3d_TextureRoot.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_TextureRoot::get_type_descriptor, "None");
cls_Graphic3d_TextureRoot.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_TextureRoot::*)() const) &Graphic3d_TextureRoot::DynamicType, "None");
cls_Graphic3d_TextureRoot.def_static("TexturesFolder_", (TCollection_AsciiString (*)()) &Graphic3d_TextureRoot::TexturesFolder, "The path to textures determined from CSF_MDTVTexturesDirectory or CASROOT environment variables.");
cls_Graphic3d_TextureRoot.def("IsDone", (Standard_Boolean (Graphic3d_TextureRoot::*)() const) &Graphic3d_TextureRoot::IsDone, "Checks if a texture class is valid or not.");
cls_Graphic3d_TextureRoot.def("Path", (const OSD_Path & (Graphic3d_TextureRoot::*)() const) &Graphic3d_TextureRoot::Path, "Returns the full path of the defined texture. It could be empty path if GetImage() is overridden to load image not from file.");
cls_Graphic3d_TextureRoot.def("Type", (Graphic3d_TypeOfTexture (Graphic3d_TextureRoot::*)() const) &Graphic3d_TextureRoot::Type, "Returns the texture type.");
cls_Graphic3d_TextureRoot.def("GetId", (const TCollection_AsciiString & (Graphic3d_TextureRoot::*)() const) &Graphic3d_TextureRoot::GetId, "This ID will be used to manage resource in graphic driver.");
cls_Graphic3d_TextureRoot.def("Revision", (Standard_Size (Graphic3d_TextureRoot::*)() const) &Graphic3d_TextureRoot::Revision, "Return image revision.");
cls_Graphic3d_TextureRoot.def("UpdateRevision", (void (Graphic3d_TextureRoot::*)()) &Graphic3d_TextureRoot::UpdateRevision, "Update image revision. Can be used for signaling changes in the texture source (e.g. file update, pixmap update) without re-creating texture source itself (since unique id should be never modified).");
cls_Graphic3d_TextureRoot.def("GetImage", (opencascade::handle<Image_PixMap> (Graphic3d_TextureRoot::*)() const) &Graphic3d_TextureRoot::GetImage, "This method will be called by graphic driver each time when texture resource should be created. Default constructors allow defining the texture source as path to texture image or directly as pixmap. If the source is defined as path, then the image will be dynamically loaded when this method is called (and no copy will be preserved in this class instance). Inheritors may dynamically generate the image. Notice, image data should be in Bottom-Up order (see Image_PixMap::IsTopDown())!");
cls_Graphic3d_TextureRoot.def("GetParams", (const opencascade::handle<Graphic3d_TextureParams> & (Graphic3d_TextureRoot::*)() const) &Graphic3d_TextureRoot::GetParams, "Returns low-level texture parameters");

// Enums

}