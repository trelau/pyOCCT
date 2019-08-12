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
#include <GProp_UndefinedAxis.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Type.hxx>

void bind_GProp_UndefinedAxis(py::module &mod){

py::class_<GProp_UndefinedAxis, opencascade::handle<GProp_UndefinedAxis>, Standard_DomainError> cls_GProp_UndefinedAxis(mod, "GProp_UndefinedAxis", "This exception is raised when a method makes reference to an undefined inertia axis of symmetry.");

// Constructors
cls_GProp_UndefinedAxis.def(py::init<>());
cls_GProp_UndefinedAxis.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Fields

// Methods
cls_GProp_UndefinedAxis.def_static("Raise_", (void (*)(const Standard_CString)) &GProp_UndefinedAxis::Raise, "None", py::arg("theMessage"));
cls_GProp_UndefinedAxis.def_static("Raise_", (void (*)(Standard_SStream &)) &GProp_UndefinedAxis::Raise, "None", py::arg("theMessage"));
cls_GProp_UndefinedAxis.def_static("NewInstance_", (opencascade::handle<GProp_UndefinedAxis> (*)(const Standard_CString)) &GProp_UndefinedAxis::NewInstance, "None", py::arg("theMessage"));
cls_GProp_UndefinedAxis.def_static("get_type_name_", (const char * (*)()) &GProp_UndefinedAxis::get_type_name, "None");
cls_GProp_UndefinedAxis.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GProp_UndefinedAxis::get_type_descriptor, "None");
cls_GProp_UndefinedAxis.def("DynamicType", (const opencascade::handle<Standard_Type> & (GProp_UndefinedAxis::*)() const) &GProp_UndefinedAxis::DynamicType, "None");

// Enums

}