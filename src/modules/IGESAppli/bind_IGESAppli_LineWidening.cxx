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
#include <IGESData_IGESEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESAppli_LineWidening.hxx>
#include <Standard_Type.hxx>

void bind_IGESAppli_LineWidening(py::module &mod){

py::class_<IGESAppli_LineWidening, opencascade::handle<IGESAppli_LineWidening>, IGESData_IGESEntity> cls_IGESAppli_LineWidening(mod, "IGESAppli_LineWidening", "defines LineWidening, Type <406> Form <5> in package IGESAppli Defines the characteristics of entities when they are used to define locations of items.");

// Constructors
cls_IGESAppli_LineWidening.def(py::init<>());

// Fields

// Methods
cls_IGESAppli_LineWidening.def("Init", (void (IGESAppli_LineWidening::*)(const Standard_Integer, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real)) &IGESAppli_LineWidening::Init, "This method is used to set the fields of the class LineWidening - nbPropVal : Number of property values = 5 - aWidth : Width of metalization - aCornering : Cornering codes 0 = rounded 1 = squared - aExtnFlag : Extension Flag 0 = No Extension 1 = One-half width extension 2 = Extn set by ExtnVal - aJustifFlag : Justification flag 0 = Center justified 1 = left justified 2 = right justified - aExtnVal : Extension value if aExtnFlag = 2", py::arg("nbPropVal"), py::arg("aWidth"), py::arg("aCornering"), py::arg("aExtnFlag"), py::arg("aJustifFlag"), py::arg("aExtnVal"));
cls_IGESAppli_LineWidening.def("NbPropertyValues", (Standard_Integer (IGESAppli_LineWidening::*)() const) &IGESAppli_LineWidening::NbPropertyValues, "returns the number of property values is always 5");
cls_IGESAppli_LineWidening.def("WidthOfMetalization", (Standard_Real (IGESAppli_LineWidening::*)() const) &IGESAppli_LineWidening::WidthOfMetalization, "returns the width of metallization");
cls_IGESAppli_LineWidening.def("CorneringCode", (Standard_Integer (IGESAppli_LineWidening::*)() const) &IGESAppli_LineWidening::CorneringCode, "returns the cornering code 0 = Rounded / 1 = Squared");
cls_IGESAppli_LineWidening.def("ExtensionFlag", (Standard_Integer (IGESAppli_LineWidening::*)() const) &IGESAppli_LineWidening::ExtensionFlag, "returns the extension flag 0 = No extension 1 = One-half width extension 2 = Extension set by theExtnVal");
cls_IGESAppli_LineWidening.def("JustificationFlag", (Standard_Integer (IGESAppli_LineWidening::*)() const) &IGESAppli_LineWidening::JustificationFlag, "returns the justification flag 0 = Centre justified 1 = Left justified 2 = Right justified");
cls_IGESAppli_LineWidening.def("ExtensionValue", (Standard_Real (IGESAppli_LineWidening::*)() const) &IGESAppli_LineWidening::ExtensionValue, "returns the Extension Value Present only if theExtnFlag = 2");
cls_IGESAppli_LineWidening.def_static("get_type_name_", (const char * (*)()) &IGESAppli_LineWidening::get_type_name, "None");
cls_IGESAppli_LineWidening.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESAppli_LineWidening::get_type_descriptor, "None");
cls_IGESAppli_LineWidening.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESAppli_LineWidening::*)() const) &IGESAppli_LineWidening::DynamicType, "None");

// Enums

}