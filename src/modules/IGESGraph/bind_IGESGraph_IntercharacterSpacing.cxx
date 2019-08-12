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
#include <IGESGraph_IntercharacterSpacing.hxx>
#include <Standard_Type.hxx>

void bind_IGESGraph_IntercharacterSpacing(py::module &mod){

py::class_<IGESGraph_IntercharacterSpacing, opencascade::handle<IGESGraph_IntercharacterSpacing>, IGESData_IGESEntity> cls_IGESGraph_IntercharacterSpacing(mod, "IGESGraph_IntercharacterSpacing", "defines IGESIntercharacterSpacing, Type <406> Form <18> in package IGESGraph");

// Constructors
cls_IGESGraph_IntercharacterSpacing.def(py::init<>());

// Fields

// Methods
cls_IGESGraph_IntercharacterSpacing.def("Init", (void (IGESGraph_IntercharacterSpacing::*)(const Standard_Integer, const Standard_Real)) &IGESGraph_IntercharacterSpacing::Init, "This method is used to set the fields of the class IntercharacterSpacing - nbProps : Number of property values (NP = 1) - anISpace : Intercharacter spacing percentage", py::arg("nbProps"), py::arg("anISpace"));
cls_IGESGraph_IntercharacterSpacing.def("NbPropertyValues", (Standard_Integer (IGESGraph_IntercharacterSpacing::*)() const) &IGESGraph_IntercharacterSpacing::NbPropertyValues, "returns the number of property values in <me>");
cls_IGESGraph_IntercharacterSpacing.def("ISpace", (Standard_Real (IGESGraph_IntercharacterSpacing::*)() const) &IGESGraph_IntercharacterSpacing::ISpace, "returns the Intercharacter Space of <me> in percentage of the text height (Range = 0..100)");
cls_IGESGraph_IntercharacterSpacing.def_static("get_type_name_", (const char * (*)()) &IGESGraph_IntercharacterSpacing::get_type_name, "None");
cls_IGESGraph_IntercharacterSpacing.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_IntercharacterSpacing::get_type_descriptor, "None");
cls_IGESGraph_IntercharacterSpacing.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_IntercharacterSpacing::*)() const) &IGESGraph_IntercharacterSpacing::DynamicType, "None");

// Enums

}