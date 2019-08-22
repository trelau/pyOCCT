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
#include <Standard.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <Vrml_SFImage.hxx>
#include <Vrml_Texture2Wrap.hxx>
#include <Standard_OStream.hxx>
#include <Vrml_Texture2.hxx>

void bind_Vrml_Texture2(py::module &mod){

py::class_<Vrml_Texture2> cls_Vrml_Texture2(mod, "Vrml_Texture2", "defines a Texture2 node of VRML specifying properties of geometry and its appearance. This property node defines a texture map and parameters for that map The texture can be read from the URL specified by the filename field. To turn off texturing, set the filename field to an empty string (''). Textures can alsobe specified inline by setting the image field to contain the texture data. By default : myFilename ('') myImage (0 0 0) myWrapS (Vrml_REPEAT) myWrapT (Vrml_REPEAT)");

// Constructors
cls_Vrml_Texture2.def(py::init<>());
cls_Vrml_Texture2.def(py::init<const TCollection_AsciiString &, const opencascade::handle<Vrml_SFImage> &, const Vrml_Texture2Wrap, const Vrml_Texture2Wrap>(), py::arg("aFilename"), py::arg("aImage"), py::arg("aWrapS"), py::arg("aWrapT"));

// Fields

// Methods
// cls_Vrml_Texture2.def_static("operator new_", (void * (*)(size_t)) &Vrml_Texture2::operator new, "None", py::arg("theSize"));
// cls_Vrml_Texture2.def_static("operator delete_", (void (*)(void *)) &Vrml_Texture2::operator delete, "None", py::arg("theAddress"));
// cls_Vrml_Texture2.def_static("operator new[]_", (void * (*)(size_t)) &Vrml_Texture2::operator new[], "None", py::arg("theSize"));
// cls_Vrml_Texture2.def_static("operator delete[]_", (void (*)(void *)) &Vrml_Texture2::operator delete[], "None", py::arg("theAddress"));
// cls_Vrml_Texture2.def_static("operator new_", (void * (*)(size_t, void *)) &Vrml_Texture2::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Vrml_Texture2.def_static("operator delete_", (void (*)(void *, void *)) &Vrml_Texture2::operator delete, "None", py::arg(""), py::arg(""));
cls_Vrml_Texture2.def("SetFilename", (void (Vrml_Texture2::*)(const TCollection_AsciiString &)) &Vrml_Texture2::SetFilename, "None", py::arg("aFilename"));
cls_Vrml_Texture2.def("Filename", (TCollection_AsciiString (Vrml_Texture2::*)() const) &Vrml_Texture2::Filename, "None");
cls_Vrml_Texture2.def("SetImage", (void (Vrml_Texture2::*)(const opencascade::handle<Vrml_SFImage> &)) &Vrml_Texture2::SetImage, "None", py::arg("aImage"));
cls_Vrml_Texture2.def("Image", (opencascade::handle<Vrml_SFImage> (Vrml_Texture2::*)() const) &Vrml_Texture2::Image, "None");
cls_Vrml_Texture2.def("SetWrapS", (void (Vrml_Texture2::*)(const Vrml_Texture2Wrap)) &Vrml_Texture2::SetWrapS, "None", py::arg("aWrapS"));
cls_Vrml_Texture2.def("WrapS", (Vrml_Texture2Wrap (Vrml_Texture2::*)() const) &Vrml_Texture2::WrapS, "None");
cls_Vrml_Texture2.def("SetWrapT", (void (Vrml_Texture2::*)(const Vrml_Texture2Wrap)) &Vrml_Texture2::SetWrapT, "None", py::arg("aWrapT"));
cls_Vrml_Texture2.def("WrapT", (Vrml_Texture2Wrap (Vrml_Texture2::*)() const) &Vrml_Texture2::WrapT, "None");
cls_Vrml_Texture2.def("Print", (Standard_OStream & (Vrml_Texture2::*)(Standard_OStream &) const) &Vrml_Texture2::Print, "None", py::arg("anOStream"));

// Enums

}