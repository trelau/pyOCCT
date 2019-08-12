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
#include <IGESAppli_DrilledHole.hxx>
#include <Standard_Type.hxx>

void bind_IGESAppli_DrilledHole(py::module &mod){

py::class_<IGESAppli_DrilledHole, opencascade::handle<IGESAppli_DrilledHole>, IGESData_IGESEntity> cls_IGESAppli_DrilledHole(mod, "IGESAppli_DrilledHole", "defines DrilledHole, Type <406> Form <6> in package IGESAppli Identifies an entity representing a drilled hole through a printed circuit board.");

// Constructors
cls_IGESAppli_DrilledHole.def(py::init<>());

// Fields

// Methods
cls_IGESAppli_DrilledHole.def("Init", (void (IGESAppli_DrilledHole::*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &IGESAppli_DrilledHole::Init, "This method is used to set the fields of the class DrilledHole - nbPropVal : Number of property values = 5 - aSize : Drill diameter size - anotherSize : Finish diameter size - aPlating : Plating indication flag False = not plating True = is plating - aLayer : Lower numbered layer - anotherLayer : Higher numbered layer", py::arg("nbPropVal"), py::arg("aSize"), py::arg("anotherSize"), py::arg("aPlating"), py::arg("aLayer"), py::arg("anotherLayer"));
cls_IGESAppli_DrilledHole.def("NbPropertyValues", (Standard_Integer (IGESAppli_DrilledHole::*)() const) &IGESAppli_DrilledHole::NbPropertyValues, "is always 5");
cls_IGESAppli_DrilledHole.def("DrillDiaSize", (Standard_Real (IGESAppli_DrilledHole::*)() const) &IGESAppli_DrilledHole::DrillDiaSize, "returns the drill diameter size");
cls_IGESAppli_DrilledHole.def("FinishDiaSize", (Standard_Real (IGESAppli_DrilledHole::*)() const) &IGESAppli_DrilledHole::FinishDiaSize, "returns the finish diameter size");
cls_IGESAppli_DrilledHole.def("IsPlating", (Standard_Boolean (IGESAppli_DrilledHole::*)() const) &IGESAppli_DrilledHole::IsPlating, "Returns Plating Status : False = not plating / True = is plating");
cls_IGESAppli_DrilledHole.def("NbLowerLayer", (Standard_Integer (IGESAppli_DrilledHole::*)() const) &IGESAppli_DrilledHole::NbLowerLayer, "returns the lower numbered layer");
cls_IGESAppli_DrilledHole.def("NbHigherLayer", (Standard_Integer (IGESAppli_DrilledHole::*)() const) &IGESAppli_DrilledHole::NbHigherLayer, "returns the higher numbered layer");
cls_IGESAppli_DrilledHole.def_static("get_type_name_", (const char * (*)()) &IGESAppli_DrilledHole::get_type_name, "None");
cls_IGESAppli_DrilledHole.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESAppli_DrilledHole::get_type_descriptor, "None");
cls_IGESAppli_DrilledHole.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESAppli_DrilledHole::*)() const) &IGESAppli_DrilledHole::DynamicType, "None");

// Enums

}