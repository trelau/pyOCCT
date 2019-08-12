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
#include <IGESGraph_NominalSize.hxx>
#include <Standard_Type.hxx>

void bind_IGESGraph_NominalSize(py::module &mod){

py::class_<IGESGraph_NominalSize, opencascade::handle<IGESGraph_NominalSize>, IGESData_IGESEntity> cls_IGESGraph_NominalSize(mod, "IGESGraph_NominalSize", "defines IGESNominalSize, Type <406> Form <13> in package IGESGraph");

// Constructors
cls_IGESGraph_NominalSize.def(py::init<>());

// Fields

// Methods
cls_IGESGraph_NominalSize.def("Init", (void (IGESGraph_NominalSize::*)(const Standard_Integer, const Standard_Real, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &IGESGraph_NominalSize::Init, "This method is used to set the fields of the class NominalSize - nbProps : Number of property values (2 or 3) - aNominalSizeValue : NominalSize Value - aNominalSizeName : NominalSize Name - aStandardName : Name of relevant engineering standard", py::arg("nbProps"), py::arg("aNominalSizeValue"), py::arg("aNominalSizeName"), py::arg("aStandardName"));
cls_IGESGraph_NominalSize.def("NbPropertyValues", (Standard_Integer (IGESGraph_NominalSize::*)() const) &IGESGraph_NominalSize::NbPropertyValues, "returns the number of property values in <me>");
cls_IGESGraph_NominalSize.def("NominalSizeValue", (Standard_Real (IGESGraph_NominalSize::*)() const) &IGESGraph_NominalSize::NominalSizeValue, "returns the value of <me>");
cls_IGESGraph_NominalSize.def("NominalSizeName", (opencascade::handle<TCollection_HAsciiString> (IGESGraph_NominalSize::*)() const) &IGESGraph_NominalSize::NominalSizeName, "returns the name of <me>");
cls_IGESGraph_NominalSize.def("HasStandardName", (Standard_Boolean (IGESGraph_NominalSize::*)() const) &IGESGraph_NominalSize::HasStandardName, "returns True if an engineering Standard is defined for <me> else, returns False");
cls_IGESGraph_NominalSize.def("StandardName", (opencascade::handle<TCollection_HAsciiString> (IGESGraph_NominalSize::*)() const) &IGESGraph_NominalSize::StandardName, "returns the name of the relevant engineering standard of <me>");
cls_IGESGraph_NominalSize.def_static("get_type_name_", (const char * (*)()) &IGESGraph_NominalSize::get_type_name, "None");
cls_IGESGraph_NominalSize.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_NominalSize::get_type_descriptor, "None");
cls_IGESGraph_NominalSize.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_NominalSize::*)() const) &IGESGraph_NominalSize::DynamicType, "None");

// Enums

}