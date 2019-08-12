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
#include <Interface_FileParameter.hxx>
#include <Standard_Handle.hxx>
#include <Interface_ParamList.hxx>
#include <Standard_Type.hxx>
#include <Interface_VectorOfFileParameter.hxx>

void bind_Interface_ParamList(py::module &mod){

py::class_<Interface_ParamList, opencascade::handle<Interface_ParamList>, Standard_Transient> cls_Interface_ParamList(mod, "Interface_ParamList", "None");

// Constructors
cls_Interface_ParamList.def(py::init<>());
cls_Interface_ParamList.def(py::init<const Standard_Integer>(), py::arg("theIncrement"));

// Fields

// Methods
cls_Interface_ParamList.def("Length", (Standard_Integer (Interface_ParamList::*)() const) &Interface_ParamList::Length, "Returns the number of elements of <me>.");
cls_Interface_ParamList.def("Lower", (Standard_Integer (Interface_ParamList::*)() const) &Interface_ParamList::Lower, "Returns the lower bound. Warning");
cls_Interface_ParamList.def("Upper", (Standard_Integer (Interface_ParamList::*)() const) &Interface_ParamList::Upper, "Returns the upper bound. Warning");
cls_Interface_ParamList.def("SetValue", (void (Interface_ParamList::*)(const Standard_Integer, const Interface_FileParameter &)) &Interface_ParamList::SetValue, "Assigns the value <Value> to the <Index>-th item of this array.", py::arg("Index"), py::arg("Value"));
cls_Interface_ParamList.def("Value", (const Interface_FileParameter & (Interface_ParamList::*)(const Standard_Integer) const) &Interface_ParamList::Value, "Return the value of the <Index>th element of the array.", py::arg("Index"));
cls_Interface_ParamList.def("__call__", (const Interface_FileParameter & (Interface_ParamList::*)(const Standard_Integer) const) &Interface_ParamList::operator(), py::is_operator(), "None", py::arg("Index"));
cls_Interface_ParamList.def("ChangeValue", (Interface_FileParameter & (Interface_ParamList::*)(const Standard_Integer)) &Interface_ParamList::ChangeValue, "return the value of the <Index>th element of the array.", py::arg("Index"));
cls_Interface_ParamList.def("__call__", (Interface_FileParameter & (Interface_ParamList::*)(const Standard_Integer)) &Interface_ParamList::operator(), py::is_operator(), "None", py::arg("Index"));
cls_Interface_ParamList.def("Clear", (void (Interface_ParamList::*)()) &Interface_ParamList::Clear, "None");
cls_Interface_ParamList.def_static("get_type_name_", (const char * (*)()) &Interface_ParamList::get_type_name, "None");
cls_Interface_ParamList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Interface_ParamList::get_type_descriptor, "None");
cls_Interface_ParamList.def("DynamicType", (const opencascade::handle<Standard_Type> & (Interface_ParamList::*)() const) &Interface_ParamList::DynamicType, "None");

// Enums

}