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
#include <IGESGraph_LineFontPredefined.hxx>
#include <Standard_Type.hxx>

void bind_IGESGraph_LineFontPredefined(py::module &mod){

py::class_<IGESGraph_LineFontPredefined, opencascade::handle<IGESGraph_LineFontPredefined>, IGESData_IGESEntity> cls_IGESGraph_LineFontPredefined(mod, "IGESGraph_LineFontPredefined", "defines IGESLineFontPredefined, Type <406> Form <19> in package IGESGraph");

// Constructors
cls_IGESGraph_LineFontPredefined.def(py::init<>());

// Fields

// Methods
cls_IGESGraph_LineFontPredefined.def("Init", (void (IGESGraph_LineFontPredefined::*)(const Standard_Integer, const Standard_Integer)) &IGESGraph_LineFontPredefined::Init, "This method is used to set the fields of the class LineFontPredefined - nbProps : Number of property values (NP = 1) - aLineFontPatternCode : Line Font Pattern Code", py::arg("nbProps"), py::arg("aLineFontPatternCode"));
cls_IGESGraph_LineFontPredefined.def("NbPropertyValues", (Standard_Integer (IGESGraph_LineFontPredefined::*)() const) &IGESGraph_LineFontPredefined::NbPropertyValues, "returns the number of property values in <me>");
cls_IGESGraph_LineFontPredefined.def("LineFontPatternCode", (Standard_Integer (IGESGraph_LineFontPredefined::*)() const) &IGESGraph_LineFontPredefined::LineFontPatternCode, "returns the Line Font Pattern Code of <me>");
cls_IGESGraph_LineFontPredefined.def_static("get_type_name_", (const char * (*)()) &IGESGraph_LineFontPredefined::get_type_name, "None");
cls_IGESGraph_LineFontPredefined.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_LineFontPredefined::get_type_descriptor, "None");
cls_IGESGraph_LineFontPredefined.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_LineFontPredefined::*)() const) &IGESGraph_LineFontPredefined::DynamicType, "None");

// Enums

}