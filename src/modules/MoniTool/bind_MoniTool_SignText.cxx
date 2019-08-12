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
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <MoniTool_SignText.hxx>
#include <Standard_Type.hxx>

void bind_MoniTool_SignText(py::module &mod){

py::class_<MoniTool_SignText, opencascade::handle<MoniTool_SignText>, Standard_Transient> cls_MoniTool_SignText(mod, "MoniTool_SignText", "Provides the basic service to get a text which identifies an object in a context It can be used for other classes (general signatures ...) It can also be used to build a message in which an object is to be identified");

// Fields

// Methods
cls_MoniTool_SignText.def("Name", (Standard_CString (MoniTool_SignText::*)() const) &MoniTool_SignText::Name, "Returns an identification of the Signature (a word), given at initialization time");
cls_MoniTool_SignText.def("TextAlone", (TCollection_AsciiString (MoniTool_SignText::*)(const opencascade::handle<Standard_Transient> &) const) &MoniTool_SignText::TextAlone, "Gives a text as a signature for a transient object alone, i.e. without defined context. By default, calls Text with undefined context (Null Handle) and if empty, then returns DynamicType", py::arg("ent"));
cls_MoniTool_SignText.def("Text", (TCollection_AsciiString (MoniTool_SignText::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &) const) &MoniTool_SignText::Text, "Gives a text as a signature for a transient object in a context If the context is senseless, it can be given as Null Handle empty result if nothing to give (at least the DynamicType could be sent ?)", py::arg("ent"), py::arg("context"));
cls_MoniTool_SignText.def_static("get_type_name_", (const char * (*)()) &MoniTool_SignText::get_type_name, "None");
cls_MoniTool_SignText.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &MoniTool_SignText::get_type_descriptor, "None");
cls_MoniTool_SignText.def("DynamicType", (const opencascade::handle<Standard_Type> & (MoniTool_SignText::*)() const) &MoniTool_SignText::DynamicType, "None");

// Enums

}