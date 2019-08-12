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
#include <IFSelect_SelectExtract.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <Interface_InterfaceModel.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_SelectUnknownEntities.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_SelectUnknownEntities(py::module &mod){

py::class_<IFSelect_SelectUnknownEntities, opencascade::handle<IFSelect_SelectUnknownEntities>, IFSelect_SelectExtract> cls_IFSelect_SelectUnknownEntities(mod, "IFSelect_SelectUnknownEntities", "A SelectUnknownEntities sorts the Entities which are qualified as 'Unknown' (their Type has not been recognized)");

// Constructors
cls_IFSelect_SelectUnknownEntities.def(py::init<>());

// Fields

// Methods
cls_IFSelect_SelectUnknownEntities.def("Sort", (Standard_Boolean (IFSelect_SelectUnknownEntities::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &, const opencascade::handle<Interface_InterfaceModel> &) const) &IFSelect_SelectUnknownEntities::Sort, "Returns True for an Entity which is qualified as 'Unknown', i.e. if <model> known <ent> (through its Number) as Unknown", py::arg("rank"), py::arg("ent"), py::arg("model"));
cls_IFSelect_SelectUnknownEntities.def("ExtractLabel", (TCollection_AsciiString (IFSelect_SelectUnknownEntities::*)() const) &IFSelect_SelectUnknownEntities::ExtractLabel, "Returns a text defining the criterium : 'Recognized Entities'");
cls_IFSelect_SelectUnknownEntities.def_static("get_type_name_", (const char * (*)()) &IFSelect_SelectUnknownEntities::get_type_name, "None");
cls_IFSelect_SelectUnknownEntities.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_SelectUnknownEntities::get_type_descriptor, "None");
cls_IFSelect_SelectUnknownEntities.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_SelectUnknownEntities::*)() const) &IFSelect_SelectUnknownEntities::DynamicType, "None");

// Enums

}