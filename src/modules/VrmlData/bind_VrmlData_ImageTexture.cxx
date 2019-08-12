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
#include <VrmlData_Texture.hxx>
#include <VrmlData_Scene.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_List.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <VrmlData_Node.hxx>
#include <VrmlData_ErrorStatus.hxx>
#include <VrmlData_InBuffer.hxx>
#include <VrmlData_ImageTexture.hxx>
#include <Standard_Type.hxx>

void bind_VrmlData_ImageTexture(py::module &mod){

py::class_<VrmlData_ImageTexture, opencascade::handle<VrmlData_ImageTexture>, VrmlData_Texture> cls_VrmlData_ImageTexture(mod, "VrmlData_ImageTexture", "Implementation of the ImageTexture node");

// Constructors
cls_VrmlData_ImageTexture.def(py::init<>());
cls_VrmlData_ImageTexture.def(py::init<const VrmlData_Scene &, const char *>(), py::arg("theScene"), py::arg("theName"));
cls_VrmlData_ImageTexture.def(py::init<const VrmlData_Scene &, const char *, const char *>(), py::arg("theScene"), py::arg("theName"), py::arg("theURL"));
cls_VrmlData_ImageTexture.def(py::init<const VrmlData_Scene &, const char *, const char *, const Standard_Boolean>(), py::arg("theScene"), py::arg("theName"), py::arg("theURL"), py::arg("theRepS"));
cls_VrmlData_ImageTexture.def(py::init<const VrmlData_Scene &, const char *, const char *, const Standard_Boolean, const Standard_Boolean>(), py::arg("theScene"), py::arg("theName"), py::arg("theURL"), py::arg("theRepS"), py::arg("theRepT"));

// Fields

// Methods
cls_VrmlData_ImageTexture.def("URL", (const NCollection_List<TCollection_AsciiString> & (VrmlData_ImageTexture::*)() const) &VrmlData_ImageTexture::URL, "Query the associated URL.");
cls_VrmlData_ImageTexture.def("Clone", (opencascade::handle<VrmlData_Node> (VrmlData_ImageTexture::*)(const opencascade::handle<VrmlData_Node> &) const) &VrmlData_ImageTexture::Clone, "Create a copy of this node. If the parameter is null, a new copied node is created. Otherwise new node is not created, but rather the given one is modified.", py::arg("theOther"));
cls_VrmlData_ImageTexture.def("Read", (VrmlData_ErrorStatus (VrmlData_ImageTexture::*)(VrmlData_InBuffer &)) &VrmlData_ImageTexture::Read, "Read the Node from input stream.", py::arg("theBuffer"));
cls_VrmlData_ImageTexture.def("Write", (VrmlData_ErrorStatus (VrmlData_ImageTexture::*)(const char *) const) &VrmlData_ImageTexture::Write, "Write the Node to output stream.", py::arg("thePrefix"));
cls_VrmlData_ImageTexture.def_static("get_type_name_", (const char * (*)()) &VrmlData_ImageTexture::get_type_name, "None");
cls_VrmlData_ImageTexture.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &VrmlData_ImageTexture::get_type_descriptor, "None");
cls_VrmlData_ImageTexture.def("DynamicType", (const opencascade::handle<Standard_Type> & (VrmlData_ImageTexture::*)() const) &VrmlData_ImageTexture::DynamicType, "None");

// Enums

}