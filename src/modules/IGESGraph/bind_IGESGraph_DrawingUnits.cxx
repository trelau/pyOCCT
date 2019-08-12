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
#include <IGESGraph_DrawingUnits.hxx>
#include <Standard_Type.hxx>

void bind_IGESGraph_DrawingUnits(py::module &mod){

py::class_<IGESGraph_DrawingUnits, opencascade::handle<IGESGraph_DrawingUnits>, IGESData_IGESEntity> cls_IGESGraph_DrawingUnits(mod, "IGESGraph_DrawingUnits", "defines IGESDrawingUnits, Type <406> Form <17> in package IGESGraph");

// Constructors
cls_IGESGraph_DrawingUnits.def(py::init<>());

// Fields

// Methods
cls_IGESGraph_DrawingUnits.def("Init", (void (IGESGraph_DrawingUnits::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &)) &IGESGraph_DrawingUnits::Init, "This method is used to set the fields of the class DrawingUnits - nbProps : Number of property values (NP = 2) - aFlag : DrawingUnits Flag - aUnit : DrawingUnits Name", py::arg("nbProps"), py::arg("aFlag"), py::arg("aUnit"));
cls_IGESGraph_DrawingUnits.def("NbPropertyValues", (Standard_Integer (IGESGraph_DrawingUnits::*)() const) &IGESGraph_DrawingUnits::NbPropertyValues, "returns the number of property values in <me>");
cls_IGESGraph_DrawingUnits.def("Flag", (Standard_Integer (IGESGraph_DrawingUnits::*)() const) &IGESGraph_DrawingUnits::Flag, "returns the drawing space units of <me>");
cls_IGESGraph_DrawingUnits.def("Unit", (opencascade::handle<TCollection_HAsciiString> (IGESGraph_DrawingUnits::*)() const) &IGESGraph_DrawingUnits::Unit, "returns the name of the drawing space units of <me>");
cls_IGESGraph_DrawingUnits.def("UnitValue", (Standard_Real (IGESGraph_DrawingUnits::*)() const) &IGESGraph_DrawingUnits::UnitValue, "Computes the value of the unit, in meters, according Flag (same values as for GlobalSection from IGESData)");
cls_IGESGraph_DrawingUnits.def_static("get_type_name_", (const char * (*)()) &IGESGraph_DrawingUnits::get_type_name, "None");
cls_IGESGraph_DrawingUnits.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGraph_DrawingUnits::get_type_descriptor, "None");
cls_IGESGraph_DrawingUnits.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGraph_DrawingUnits::*)() const) &IGESGraph_DrawingUnits::DynamicType, "None");

// Enums

}