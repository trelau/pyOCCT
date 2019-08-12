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
#include <Standard_DomainError.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_UndefinedDerivative.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Type.hxx>

void bind_Geom_UndefinedDerivative(py::module &mod){

py::class_<Geom_UndefinedDerivative, opencascade::handle<Geom_UndefinedDerivative>, Standard_DomainError> cls_Geom_UndefinedDerivative(mod, "Geom_UndefinedDerivative", "None");

// Constructors
cls_Geom_UndefinedDerivative.def(py::init<>());
cls_Geom_UndefinedDerivative.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Fields

// Methods
cls_Geom_UndefinedDerivative.def_static("Raise_", (void (*)(const Standard_CString)) &Geom_UndefinedDerivative::Raise, "None", py::arg("theMessage"));
cls_Geom_UndefinedDerivative.def_static("Raise_", (void (*)(Standard_SStream &)) &Geom_UndefinedDerivative::Raise, "None", py::arg("theMessage"));
cls_Geom_UndefinedDerivative.def_static("NewInstance_", (opencascade::handle<Geom_UndefinedDerivative> (*)(const Standard_CString)) &Geom_UndefinedDerivative::NewInstance, "None", py::arg("theMessage"));
cls_Geom_UndefinedDerivative.def_static("get_type_name_", (const char * (*)()) &Geom_UndefinedDerivative::get_type_name, "None");
cls_Geom_UndefinedDerivative.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom_UndefinedDerivative::get_type_descriptor, "None");
cls_Geom_UndefinedDerivative.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom_UndefinedDerivative::*)() const) &Geom_UndefinedDerivative::DynamicType, "None");

// Enums

}