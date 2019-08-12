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
#include <TColStd_HArray1OfInteger.hxx>
#include <IGESAppli_PWBArtworkStackup.hxx>
#include <Standard_Type.hxx>

void bind_IGESAppli_PWBArtworkStackup(py::module &mod){

py::class_<IGESAppli_PWBArtworkStackup, opencascade::handle<IGESAppli_PWBArtworkStackup>, IGESData_IGESEntity> cls_IGESAppli_PWBArtworkStackup(mod, "IGESAppli_PWBArtworkStackup", "defines PWBArtworkStackup, Type <406> Form <25> in package IGESAppli Used to communicate which exchange file levels are to be combined in order to create the artwork for a printed wire board (PWB). This property should be attached to the entity defining the printed wire assembly (PWA) or if no such entity exists, then the property should stand alone in the file.");

// Constructors
cls_IGESAppli_PWBArtworkStackup.def(py::init<>());

// Fields

// Methods
cls_IGESAppli_PWBArtworkStackup.def("Init", (void (IGESAppli_PWBArtworkStackup::*)(const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TColStd_HArray1OfInteger> &)) &IGESAppli_PWBArtworkStackup::Init, "This method is used to set the fields of the class PWBArtworkStackup - nbPropVal : number of property values - anArtIdent : Artwork Stackup Identification - allLevelNums : Level Numbers", py::arg("nbPropVal"), py::arg("anArtIdent"), py::arg("allLevelNums"));
cls_IGESAppli_PWBArtworkStackup.def("NbPropertyValues", (Standard_Integer (IGESAppli_PWBArtworkStackup::*)() const) &IGESAppli_PWBArtworkStackup::NbPropertyValues, "returns number of property values");
cls_IGESAppli_PWBArtworkStackup.def("Identification", (opencascade::handle<TCollection_HAsciiString> (IGESAppli_PWBArtworkStackup::*)() const) &IGESAppli_PWBArtworkStackup::Identification, "returns Artwork Stackup Identification");
cls_IGESAppli_PWBArtworkStackup.def("NbLevelNumbers", (Standard_Integer (IGESAppli_PWBArtworkStackup::*)() const) &IGESAppli_PWBArtworkStackup::NbLevelNumbers, "returns total number of Level Numbers");
cls_IGESAppli_PWBArtworkStackup.def("LevelNumber", (Standard_Integer (IGESAppli_PWBArtworkStackup::*)(const Standard_Integer) const) &IGESAppli_PWBArtworkStackup::LevelNumber, "returns Level Number raises exception if Index <= 0 or Index > NbLevelNumbers", py::arg("Index"));
cls_IGESAppli_PWBArtworkStackup.def_static("get_type_name_", (const char * (*)()) &IGESAppli_PWBArtworkStackup::get_type_name, "None");
cls_IGESAppli_PWBArtworkStackup.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESAppli_PWBArtworkStackup::get_type_descriptor, "None");
cls_IGESAppli_PWBArtworkStackup.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESAppli_PWBArtworkStackup::*)() const) &IGESAppli_PWBArtworkStackup::DynamicType, "None");

// Enums

}