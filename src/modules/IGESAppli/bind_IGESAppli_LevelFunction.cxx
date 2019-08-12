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
#include <TCollection_HAsciiString.hxx>
#include <IGESAppli_LevelFunction.hxx>
#include <Standard_Type.hxx>

void bind_IGESAppli_LevelFunction(py::module &mod){

py::class_<IGESAppli_LevelFunction, opencascade::handle<IGESAppli_LevelFunction>, IGESData_IGESEntity> cls_IGESAppli_LevelFunction(mod, "IGESAppli_LevelFunction", "defines LevelFunction, Type <406> Form <3> in package IGESAppli Used to transfer the meaning or intended use of a level in the sending system");

// Constructors
cls_IGESAppli_LevelFunction.def(py::init<>());

// Fields

// Methods
cls_IGESAppli_LevelFunction.def("Init", (void (IGESAppli_LevelFunction::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &)) &IGESAppli_LevelFunction::Init, "This method is used to set the fields of the class LevelFunction - nbPropVal : Number of Properties, always = 2 - aCode : Function Description code default = 0 - aFuncDescrip : Function Description default = null string", py::arg("nbPropVal"), py::arg("aCode"), py::arg("aFuncDescrip"));
cls_IGESAppli_LevelFunction.def("NbPropertyValues", (Standard_Integer (IGESAppli_LevelFunction::*)() const) &IGESAppli_LevelFunction::NbPropertyValues, "is always 2");
cls_IGESAppli_LevelFunction.def("FuncDescriptionCode", (Standard_Integer (IGESAppli_LevelFunction::*)() const) &IGESAppli_LevelFunction::FuncDescriptionCode, "returns the function description code . Default = 0");
cls_IGESAppli_LevelFunction.def("FuncDescription", (opencascade::handle<TCollection_HAsciiString> (IGESAppli_LevelFunction::*)() const) &IGESAppli_LevelFunction::FuncDescription, "returns the function description Default = null string");
cls_IGESAppli_LevelFunction.def_static("get_type_name_", (const char * (*)()) &IGESAppli_LevelFunction::get_type_name, "None");
cls_IGESAppli_LevelFunction.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESAppli_LevelFunction::get_type_descriptor, "None");
cls_IGESAppli_LevelFunction.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESAppli_LevelFunction::*)() const) &IGESAppli_LevelFunction::DynamicType, "None");

// Enums

}