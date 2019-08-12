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
#include <TDF_Attribute.hxx>
#include <Standard_GUID.hxx>
#include <Standard_Handle.hxx>
#include <TDataStd_Real.hxx>
#include <TDF_Label.hxx>
#include <Standard_TypeDef.hxx>
#include <TDataStd_RealEnum.hxx>
#include <TDF_RelocationTable.hxx>
#include <Standard_OStream.hxx>
#include <Standard_Type.hxx>

void bind_TDataStd_Real(py::module &mod){

py::class_<TDataStd_Real, opencascade::handle<TDataStd_Real>, TDF_Attribute> cls_TDataStd_Real(mod, "TDataStd_Real", "The basis to define a real number attribute.");

// Constructors
cls_TDataStd_Real.def(py::init<>());

// Fields

// Methods
cls_TDataStd_Real.def_static("GetID_", (const Standard_GUID & (*)()) &TDataStd_Real::GetID, "class methods ============= Returns the default GUID for real numbers.");
cls_TDataStd_Real.def_static("Set_", (opencascade::handle<TDataStd_Real> (*)(const TDF_Label &, const Standard_Real)) &TDataStd_Real::Set, "Finds, or creates, a Real attribute with default GUID and sets <value>. The Real attribute is returned. The Real dimension is Scalar by default. Use SetDimension to overwrite. Real methods ============", py::arg("label"), py::arg("value"));
cls_TDataStd_Real.def_static("Set_", (opencascade::handle<TDataStd_Real> (*)(const TDF_Label &, const Standard_GUID &, const Standard_Real)) &TDataStd_Real::Set, "Finds, or creates, a Real attribute with explicit GUID and sets <value>. The Real attribute is returned. Real methods ============", py::arg("label"), py::arg("guid"), py::arg("value"));
cls_TDataStd_Real.def("SetDimension", (void (TDataStd_Real::*)(const TDataStd_RealEnum)) &TDataStd_Real::SetDimension, "Obsolete method that will be removed in next versions. This field is not supported in the persistence mechanism.", py::arg("DIM"));
cls_TDataStd_Real.def("GetDimension", (TDataStd_RealEnum (TDataStd_Real::*)() const) &TDataStd_Real::GetDimension, "Obsolete method that will be removed in next versions. This field is not supported in the persistence mechanism.");
cls_TDataStd_Real.def("Set", (void (TDataStd_Real::*)(const Standard_Real)) &TDataStd_Real::Set, "Sets the real number V.", py::arg("V"));
cls_TDataStd_Real.def("SetID", (void (TDataStd_Real::*)(const Standard_GUID &)) &TDataStd_Real::SetID, "Sets the explicit GUID for the attribute.", py::arg("guid"));
cls_TDataStd_Real.def("SetID", (void (TDataStd_Real::*)()) &TDataStd_Real::SetID, "Sets default GUID for the attribute.");
cls_TDataStd_Real.def("Get", (Standard_Real (TDataStd_Real::*)() const) &TDataStd_Real::Get, "Returns the real number value contained in the attribute.");
cls_TDataStd_Real.def("IsCaptured", (Standard_Boolean (TDataStd_Real::*)() const) &TDataStd_Real::IsCaptured, "Returns True if there is a reference on the same label");
cls_TDataStd_Real.def("ID", (const Standard_GUID & (TDataStd_Real::*)() const) &TDataStd_Real::ID, "None");
cls_TDataStd_Real.def("Restore", (void (TDataStd_Real::*)(const opencascade::handle<TDF_Attribute> &)) &TDataStd_Real::Restore, "None", py::arg("With"));
cls_TDataStd_Real.def("NewEmpty", (opencascade::handle<TDF_Attribute> (TDataStd_Real::*)() const) &TDataStd_Real::NewEmpty, "None");
cls_TDataStd_Real.def("Paste", (void (TDataStd_Real::*)(const opencascade::handle<TDF_Attribute> &, const opencascade::handle<TDF_RelocationTable> &) const) &TDataStd_Real::Paste, "None", py::arg("Into"), py::arg("RT"));
cls_TDataStd_Real.def("Dump", (Standard_OStream & (TDataStd_Real::*)(Standard_OStream &) const) &TDataStd_Real::Dump, "None", py::arg("anOS"));
cls_TDataStd_Real.def_static("get_type_name_", (const char * (*)()) &TDataStd_Real::get_type_name, "None");
cls_TDataStd_Real.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TDataStd_Real::get_type_descriptor, "None");
cls_TDataStd_Real.def("DynamicType", (const opencascade::handle<Standard_Type> & (TDataStd_Real::*)() const) &TDataStd_Real::DynamicType, "None");

// Enums

}