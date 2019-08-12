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
#include <IFSelect_Signature.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <IGESSelect_SignColor.hxx>
#include <Standard_Type.hxx>

void bind_IGESSelect_SignColor(py::module &mod){

py::class_<IGESSelect_SignColor, opencascade::handle<IGESSelect_SignColor>, IFSelect_Signature> cls_IGESSelect_SignColor(mod, "IGESSelect_SignColor", "Gives Color attached to an entity Several forms are possible, according to <mode> 1 : number : 'Dnn' for entity, 'Snn' for standard, '(none)' for 0 2 : name : Of standard color, or of the color entity, or '(none)' (if the color entity has no name, its label is taken) 3 : RGB values, form R:nn,G:nn,B:nn 4 : RED value : an integer 5 : GREEN value : an integer 6 : BLUE value : an integer Other computable values can be added if needed : CMY values, Percentages for Hue, Lightness, Saturation");

// Constructors
cls_IGESSelect_SignColor.def(py::init<const Standard_Integer>(), py::arg("mode"));

// Fields

// Methods
cls_IGESSelect_SignColor.def("Value", (Standard_CString (IGESSelect_SignColor::*)(const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IGESSelect_SignColor::Value, "Returns the value (see above)", py::arg("ent"), py::arg("model"));
cls_IGESSelect_SignColor.def_static("get_type_name_", (const char * (*)()) &IGESSelect_SignColor::get_type_name, "None");
cls_IGESSelect_SignColor.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSelect_SignColor::get_type_descriptor, "None");
cls_IGESSelect_SignColor.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSelect_SignColor::*)() const) &IGESSelect_SignColor::DynamicType, "None");

// Enums

}