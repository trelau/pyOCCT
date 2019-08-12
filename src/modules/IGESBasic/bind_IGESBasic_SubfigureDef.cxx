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
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <Standard_Transient.hxx>
#include <IGESBasic_SubfigureDef.hxx>
#include <Standard_Type.hxx>

void bind_IGESBasic_SubfigureDef(py::module &mod){

py::class_<IGESBasic_SubfigureDef, opencascade::handle<IGESBasic_SubfigureDef>, IGESData_IGESEntity> cls_IGESBasic_SubfigureDef(mod, "IGESBasic_SubfigureDef", "defines SubfigureDef, Type <308> Form <0> in package IGESBasic This Entity permits a single definition of a detail to be utilized in multiple instances in the creation of the whole picture");

// Constructors
cls_IGESBasic_SubfigureDef.def(py::init<>());

// Fields

// Methods
cls_IGESBasic_SubfigureDef.def("Init", (void (IGESBasic_SubfigureDef::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<IGESData_HArray1OfIGESEntity> &)) &IGESBasic_SubfigureDef::Init, "This method is used to set the fields of the class SubfigureDef - aDepth : It indicates the amount of nesting - aName : the subfigure name - allAssocEntities : the associated entities", py::arg("aDepth"), py::arg("aName"), py::arg("allAssocEntities"));
cls_IGESBasic_SubfigureDef.def("Depth", (Standard_Integer (IGESBasic_SubfigureDef::*)() const) &IGESBasic_SubfigureDef::Depth, "returns depth of the Subfigure if theDepth = 0 - No reference to any subfigure instance.");
cls_IGESBasic_SubfigureDef.def("Name", (opencascade::handle<TCollection_HAsciiString> (IGESBasic_SubfigureDef::*)() const) &IGESBasic_SubfigureDef::Name, "returns the name of Subfigure");
cls_IGESBasic_SubfigureDef.def("NbEntities", (Standard_Integer (IGESBasic_SubfigureDef::*)() const) &IGESBasic_SubfigureDef::NbEntities, "returns number of entities. Is greater than or equal to zero.");
cls_IGESBasic_SubfigureDef.def("AssociatedEntity", (opencascade::handle<IGESData_IGESEntity> (IGESBasic_SubfigureDef::*)(const Standard_Integer) const) &IGESBasic_SubfigureDef::AssociatedEntity, "returns the specific entity as indicated by Index raises exception if Index <= 0 or Index > NbEntities()", py::arg("Index"));
cls_IGESBasic_SubfigureDef.def("Value", (opencascade::handle<Standard_Transient> (IGESBasic_SubfigureDef::*)(const Standard_Integer) const) &IGESBasic_SubfigureDef::Value, "returns the specific entity as indicated by Index raises exception if Index <= 0 or Index > NbEntities()", py::arg("Index"));
cls_IGESBasic_SubfigureDef.def_static("get_type_name_", (const char * (*)()) &IGESBasic_SubfigureDef::get_type_name, "None");
cls_IGESBasic_SubfigureDef.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESBasic_SubfigureDef::get_type_descriptor, "None");
cls_IGESBasic_SubfigureDef.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESBasic_SubfigureDef::*)() const) &IGESBasic_SubfigureDef::DynamicType, "None");

// Enums

}