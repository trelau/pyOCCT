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
#include <IGESAppli_ReferenceDesignator.hxx>
#include <Standard_Type.hxx>

void bind_IGESAppli_ReferenceDesignator(py::module &mod){

py::class_<IGESAppli_ReferenceDesignator, opencascade::handle<IGESAppli_ReferenceDesignator>, IGESData_IGESEntity> cls_IGESAppli_ReferenceDesignator(mod, "IGESAppli_ReferenceDesignator", "defines ReferenceDesignator, Type <406> Form <7> in package IGESAppli Used to attach a text string containing the value of a component reference designator to an entity being used to represent a component.");

// Constructors
cls_IGESAppli_ReferenceDesignator.def(py::init<>());

// Fields

// Methods
cls_IGESAppli_ReferenceDesignator.def("Init", (void (IGESAppli_ReferenceDesignator::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &)) &IGESAppli_ReferenceDesignator::Init, "This method is used to set the fields of the class ReferenceDesignator - nbPropVal : Number of property values = 1 - aText : Reference designator text", py::arg("nbPropVal"), py::arg("aText"));
cls_IGESAppli_ReferenceDesignator.def("NbPropertyValues", (Standard_Integer (IGESAppli_ReferenceDesignator::*)() const) &IGESAppli_ReferenceDesignator::NbPropertyValues, "returns the number of property values is always 1");
cls_IGESAppli_ReferenceDesignator.def("RefDesignatorText", (opencascade::handle<TCollection_HAsciiString> (IGESAppli_ReferenceDesignator::*)() const) &IGESAppli_ReferenceDesignator::RefDesignatorText, "returns the Reference designator text");
cls_IGESAppli_ReferenceDesignator.def_static("get_type_name_", (const char * (*)()) &IGESAppli_ReferenceDesignator::get_type_name, "None");
cls_IGESAppli_ReferenceDesignator.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESAppli_ReferenceDesignator::get_type_descriptor, "None");
cls_IGESAppli_ReferenceDesignator.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESAppli_ReferenceDesignator::*)() const) &IGESAppli_ReferenceDesignator::DynamicType, "None");

// Enums

}