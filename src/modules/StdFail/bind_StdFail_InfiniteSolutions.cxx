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
#include <Standard_Failure.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StdFail_InfiniteSolutions.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Type.hxx>

void bind_StdFail_InfiniteSolutions(py::module &mod){

py::class_<StdFail_InfiniteSolutions, opencascade::handle<StdFail_InfiniteSolutions>, Standard_Failure> cls_StdFail_InfiniteSolutions(mod, "StdFail_InfiniteSolutions", "None");

// Constructors
cls_StdFail_InfiniteSolutions.def(py::init<>());
cls_StdFail_InfiniteSolutions.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Fields

// Methods
cls_StdFail_InfiniteSolutions.def_static("Raise_", (void (*)(const Standard_CString)) &StdFail_InfiniteSolutions::Raise, "None", py::arg("theMessage"));
cls_StdFail_InfiniteSolutions.def_static("Raise_", (void (*)(Standard_SStream &)) &StdFail_InfiniteSolutions::Raise, "None", py::arg("theMessage"));
cls_StdFail_InfiniteSolutions.def_static("NewInstance_", (opencascade::handle<StdFail_InfiniteSolutions> (*)(const Standard_CString)) &StdFail_InfiniteSolutions::NewInstance, "None", py::arg("theMessage"));
cls_StdFail_InfiniteSolutions.def_static("get_type_name_", (const char * (*)()) &StdFail_InfiniteSolutions::get_type_name, "None");
cls_StdFail_InfiniteSolutions.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdFail_InfiniteSolutions::get_type_descriptor, "None");
cls_StdFail_InfiniteSolutions.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdFail_InfiniteSolutions::*)() const) &StdFail_InfiniteSolutions::DynamicType, "None");

// Enums

}