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
#include <Standard_Handle.hxx>
#include <IGESDimen_GeneralNote.hxx>
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <IGESDimen_HArray1OfLeaderArrow.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESDimen_LeaderArrow.hxx>
#include <IGESDimen_GeneralSymbol.hxx>
#include <Standard_Type.hxx>

void bind_IGESDimen_GeneralSymbol(py::module &mod){

py::class_<IGESDimen_GeneralSymbol, opencascade::handle<IGESDimen_GeneralSymbol>, IGESData_IGESEntity> cls_IGESDimen_GeneralSymbol(mod, "IGESDimen_GeneralSymbol", "defines General Symbol, Type <228>, Form <0-3,5001-9999> in package IGESDimen Consists of zero or one (Form 0) or one (all other forms), one or more geometry entities which define a symbol, and zero, one or more associated leaders.");

// Constructors
cls_IGESDimen_GeneralSymbol.def(py::init<>());

// Fields

// Methods
cls_IGESDimen_GeneralSymbol.def("Init", (void (IGESDimen_GeneralSymbol::*)(const opencascade::handle<IGESDimen_GeneralNote> &, const opencascade::handle<IGESData_HArray1OfIGESEntity> &, const opencascade::handle<IGESDimen_HArray1OfLeaderArrow> &)) &IGESDimen_GeneralSymbol::Init, "This method is used to set the fields of the class GeneralSymbol - aNote : General Note, null for form 0 - allGeoms : Geometric Entities - allLeaders : Leader Arrows", py::arg("aNote"), py::arg("allGeoms"), py::arg("allLeaders"));
cls_IGESDimen_GeneralSymbol.def("SetFormNumber", (void (IGESDimen_GeneralSymbol::*)(const Standard_Integer)) &IGESDimen_GeneralSymbol::SetFormNumber, "Changes FormNumber (indicates the Nature of the Symbole) Error if not in ranges [0-3] or [> 5000]", py::arg("form"));
cls_IGESDimen_GeneralSymbol.def("HasNote", (Standard_Boolean (IGESDimen_GeneralSymbol::*)() const) &IGESDimen_GeneralSymbol::HasNote, "returns True if there is associated General Note Entity");
cls_IGESDimen_GeneralSymbol.def("Note", (opencascade::handle<IGESDimen_GeneralNote> (IGESDimen_GeneralSymbol::*)() const) &IGESDimen_GeneralSymbol::Note, "returns Null handle for form 0 only");
cls_IGESDimen_GeneralSymbol.def("NbGeomEntities", (Standard_Integer (IGESDimen_GeneralSymbol::*)() const) &IGESDimen_GeneralSymbol::NbGeomEntities, "returns number of Geometry Entities");
cls_IGESDimen_GeneralSymbol.def("GeomEntity", (opencascade::handle<IGESData_IGESEntity> (IGESDimen_GeneralSymbol::*)(const Standard_Integer) const) &IGESDimen_GeneralSymbol::GeomEntity, "returns the Index'th Geometry Entity raises exception if Index <= 0 or Index > NbGeomEntities()", py::arg("Index"));
cls_IGESDimen_GeneralSymbol.def("NbLeaders", (Standard_Integer (IGESDimen_GeneralSymbol::*)() const) &IGESDimen_GeneralSymbol::NbLeaders, "returns number of Leaders or zero if not specified");
cls_IGESDimen_GeneralSymbol.def("LeaderArrow", (opencascade::handle<IGESDimen_LeaderArrow> (IGESDimen_GeneralSymbol::*)(const Standard_Integer) const) &IGESDimen_GeneralSymbol::LeaderArrow, "returns the Index'th Leader Arrow raises exception if Index <= 0 or Index > NbLeaders()", py::arg("Index"));
cls_IGESDimen_GeneralSymbol.def_static("get_type_name_", (const char * (*)()) &IGESDimen_GeneralSymbol::get_type_name, "None");
cls_IGESDimen_GeneralSymbol.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDimen_GeneralSymbol::get_type_descriptor, "None");
cls_IGESDimen_GeneralSymbol.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDimen_GeneralSymbol::*)() const) &IGESDimen_GeneralSymbol::DynamicType, "None");

// Enums

}