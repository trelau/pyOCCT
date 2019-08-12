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
#include <StepShape_Loop.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepGeom_HArray1OfCartesianPoint.hxx>
#include <StepGeom_CartesianPoint.hxx>
#include <Standard_TypeDef.hxx>
#include <StepShape_PolyLoop.hxx>
#include <Standard_Type.hxx>

void bind_StepShape_PolyLoop(py::module &mod){

py::class_<StepShape_PolyLoop, opencascade::handle<StepShape_PolyLoop>, StepShape_Loop> cls_StepShape_PolyLoop(mod, "StepShape_PolyLoop", "None");

// Constructors
cls_StepShape_PolyLoop.def(py::init<>());

// Fields

// Methods
cls_StepShape_PolyLoop.def("Init", (void (StepShape_PolyLoop::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &)) &StepShape_PolyLoop::Init, "None", py::arg("aName"), py::arg("aPolygon"));
cls_StepShape_PolyLoop.def("SetPolygon", (void (StepShape_PolyLoop::*)(const opencascade::handle<StepGeom_HArray1OfCartesianPoint> &)) &StepShape_PolyLoop::SetPolygon, "None", py::arg("aPolygon"));
cls_StepShape_PolyLoop.def("Polygon", (opencascade::handle<StepGeom_HArray1OfCartesianPoint> (StepShape_PolyLoop::*)() const) &StepShape_PolyLoop::Polygon, "None");
cls_StepShape_PolyLoop.def("PolygonValue", (opencascade::handle<StepGeom_CartesianPoint> (StepShape_PolyLoop::*)(const Standard_Integer) const) &StepShape_PolyLoop::PolygonValue, "None", py::arg("num"));
cls_StepShape_PolyLoop.def("NbPolygon", (Standard_Integer (StepShape_PolyLoop::*)() const) &StepShape_PolyLoop::NbPolygon, "None");
cls_StepShape_PolyLoop.def_static("get_type_name_", (const char * (*)()) &StepShape_PolyLoop::get_type_name, "None");
cls_StepShape_PolyLoop.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepShape_PolyLoop::get_type_descriptor, "None");
cls_StepShape_PolyLoop.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepShape_PolyLoop::*)() const) &StepShape_PolyLoop::DynamicType, "None");

// Enums

}