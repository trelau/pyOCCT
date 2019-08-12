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
#include <MoniTool_SignText.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Interface_SignLabel.hxx>
#include <Standard_Type.hxx>

void bind_Interface_SignLabel(py::module &mod){

py::class_<Interface_SignLabel, opencascade::handle<Interface_SignLabel>, MoniTool_SignText> cls_Interface_SignLabel(mod, "Interface_SignLabel", "Signature to give the Label from the Model");

// Constructors
cls_Interface_SignLabel.def(py::init<>());

// Fields

// Methods
cls_Interface_SignLabel.def("Name", (Standard_CString (Interface_SignLabel::*)() const) &Interface_SignLabel::Name, "Returns 'Entity Label'");
cls_Interface_SignLabel.def("Text", (TCollection_AsciiString (Interface_SignLabel::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Standard_Transient> &) const) &Interface_SignLabel::Text, "Considers context as an InterfaceModel and returns the Label computed by it", py::arg("ent"), py::arg("context"));
cls_Interface_SignLabel.def_static("get_type_name_", (const char * (*)()) &Interface_SignLabel::get_type_name, "None");
cls_Interface_SignLabel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_SignLabel::get_type_descriptor, "None");
cls_Interface_SignLabel.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_SignLabel::*)() const) &Interface_SignLabel::DynamicType, "None");

// Enums

}