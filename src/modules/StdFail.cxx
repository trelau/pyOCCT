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
#include <StdFail_NotDone.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <Standard_DomainError.hxx>
#include <StdFail_UndefinedDerivative.hxx>
#include <StdFail_InfiniteSolutions.hxx>
#include <StdFail_Undefined.hxx>
#include <StdFail_UndefinedValue.hxx>

PYBIND11_MODULE(StdFail, mod) {

py::module::import("OCCT.Standard");

// CLASS: STDFAIL_NOTDONE
py::class_<StdFail_NotDone, opencascade::handle<StdFail_NotDone>, Standard_Failure> cls_StdFail_NotDone(mod, "StdFail_NotDone", "None");

// Constructors
cls_StdFail_NotDone.def(py::init<>());
cls_StdFail_NotDone.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_StdFail_NotDone.def_static("Raise_", (void (*)(const Standard_CString)) &StdFail_NotDone::Raise, "None", py::arg("theMessage"));
cls_StdFail_NotDone.def_static("Raise_", (void (*)(Standard_SStream &)) &StdFail_NotDone::Raise, "None", py::arg("theMessage"));
cls_StdFail_NotDone.def_static("NewInstance_", (opencascade::handle<StdFail_NotDone> (*)(const Standard_CString)) &StdFail_NotDone::NewInstance, "None", py::arg("theMessage"));
cls_StdFail_NotDone.def_static("get_type_name_", (const char * (*)()) &StdFail_NotDone::get_type_name, "None");
cls_StdFail_NotDone.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdFail_NotDone::get_type_descriptor, "None");
cls_StdFail_NotDone.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdFail_NotDone::*)() const) &StdFail_NotDone::DynamicType, "None");

// CLASS: STDFAIL_UNDEFINEDDERIVATIVE
py::class_<StdFail_UndefinedDerivative, opencascade::handle<StdFail_UndefinedDerivative>, Standard_DomainError> cls_StdFail_UndefinedDerivative(mod, "StdFail_UndefinedDerivative", "None");

// Constructors
cls_StdFail_UndefinedDerivative.def(py::init<>());
cls_StdFail_UndefinedDerivative.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_StdFail_UndefinedDerivative.def_static("Raise_", (void (*)(const Standard_CString)) &StdFail_UndefinedDerivative::Raise, "None", py::arg("theMessage"));
cls_StdFail_UndefinedDerivative.def_static("Raise_", (void (*)(Standard_SStream &)) &StdFail_UndefinedDerivative::Raise, "None", py::arg("theMessage"));
cls_StdFail_UndefinedDerivative.def_static("NewInstance_", (opencascade::handle<StdFail_UndefinedDerivative> (*)(const Standard_CString)) &StdFail_UndefinedDerivative::NewInstance, "None", py::arg("theMessage"));
cls_StdFail_UndefinedDerivative.def_static("get_type_name_", (const char * (*)()) &StdFail_UndefinedDerivative::get_type_name, "None");
cls_StdFail_UndefinedDerivative.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdFail_UndefinedDerivative::get_type_descriptor, "None");
cls_StdFail_UndefinedDerivative.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdFail_UndefinedDerivative::*)() const) &StdFail_UndefinedDerivative::DynamicType, "None");

// CLASS: STDFAIL_INFINITESOLUTIONS
py::class_<StdFail_InfiniteSolutions, opencascade::handle<StdFail_InfiniteSolutions>, Standard_Failure> cls_StdFail_InfiniteSolutions(mod, "StdFail_InfiniteSolutions", "None");

// Constructors
cls_StdFail_InfiniteSolutions.def(py::init<>());
cls_StdFail_InfiniteSolutions.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_StdFail_InfiniteSolutions.def_static("Raise_", (void (*)(const Standard_CString)) &StdFail_InfiniteSolutions::Raise, "None", py::arg("theMessage"));
cls_StdFail_InfiniteSolutions.def_static("Raise_", (void (*)(Standard_SStream &)) &StdFail_InfiniteSolutions::Raise, "None", py::arg("theMessage"));
cls_StdFail_InfiniteSolutions.def_static("NewInstance_", (opencascade::handle<StdFail_InfiniteSolutions> (*)(const Standard_CString)) &StdFail_InfiniteSolutions::NewInstance, "None", py::arg("theMessage"));
cls_StdFail_InfiniteSolutions.def_static("get_type_name_", (const char * (*)()) &StdFail_InfiniteSolutions::get_type_name, "None");
cls_StdFail_InfiniteSolutions.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdFail_InfiniteSolutions::get_type_descriptor, "None");
cls_StdFail_InfiniteSolutions.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdFail_InfiniteSolutions::*)() const) &StdFail_InfiniteSolutions::DynamicType, "None");

// CLASS: STDFAIL_UNDEFINED
py::class_<StdFail_Undefined, opencascade::handle<StdFail_Undefined>, Standard_Failure> cls_StdFail_Undefined(mod, "StdFail_Undefined", "None");

// Constructors
cls_StdFail_Undefined.def(py::init<>());
cls_StdFail_Undefined.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_StdFail_Undefined.def_static("Raise_", (void (*)(const Standard_CString)) &StdFail_Undefined::Raise, "None", py::arg("theMessage"));
cls_StdFail_Undefined.def_static("Raise_", (void (*)(Standard_SStream &)) &StdFail_Undefined::Raise, "None", py::arg("theMessage"));
cls_StdFail_Undefined.def_static("NewInstance_", (opencascade::handle<StdFail_Undefined> (*)(const Standard_CString)) &StdFail_Undefined::NewInstance, "None", py::arg("theMessage"));
cls_StdFail_Undefined.def_static("get_type_name_", (const char * (*)()) &StdFail_Undefined::get_type_name, "None");
cls_StdFail_Undefined.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdFail_Undefined::get_type_descriptor, "None");
cls_StdFail_Undefined.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdFail_Undefined::*)() const) &StdFail_Undefined::DynamicType, "None");

// CLASS: STDFAIL_UNDEFINEDVALUE
py::class_<StdFail_UndefinedValue, opencascade::handle<StdFail_UndefinedValue>, Standard_DomainError> cls_StdFail_UndefinedValue(mod, "StdFail_UndefinedValue", "None");

// Constructors
cls_StdFail_UndefinedValue.def(py::init<>());
cls_StdFail_UndefinedValue.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_StdFail_UndefinedValue.def_static("Raise_", (void (*)(const Standard_CString)) &StdFail_UndefinedValue::Raise, "None", py::arg("theMessage"));
cls_StdFail_UndefinedValue.def_static("Raise_", (void (*)(Standard_SStream &)) &StdFail_UndefinedValue::Raise, "None", py::arg("theMessage"));
cls_StdFail_UndefinedValue.def_static("NewInstance_", (opencascade::handle<StdFail_UndefinedValue> (*)(const Standard_CString)) &StdFail_UndefinedValue::NewInstance, "None", py::arg("theMessage"));
cls_StdFail_UndefinedValue.def_static("get_type_name_", (const char * (*)()) &StdFail_UndefinedValue::get_type_name, "None");
cls_StdFail_UndefinedValue.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StdFail_UndefinedValue::get_type_descriptor, "None");
cls_StdFail_UndefinedValue.def("DynamicType", (const opencascade::handle<Standard_Type> & (StdFail_UndefinedValue::*)() const) &StdFail_UndefinedValue::DynamicType, "None");


}
