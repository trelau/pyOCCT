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
#include <StepGeom_Point.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_CartesianPoint.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_CartesianPoint(py::module &mod){

py::class_<StepGeom_CartesianPoint, opencascade::handle<StepGeom_CartesianPoint>, StepGeom_Point> cls_StepGeom_CartesianPoint(mod, "StepGeom_CartesianPoint", "None");

// Constructors
cls_StepGeom_CartesianPoint.def(py::init<>());

// Fields

// Methods
cls_StepGeom_CartesianPoint.def("Init", (void (StepGeom_CartesianPoint::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_CartesianPoint::Init, "None", py::arg("aName"), py::arg("aCoordinates"));
cls_StepGeom_CartesianPoint.def("Init2D", (void (StepGeom_CartesianPoint::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const Standard_Real)) &StepGeom_CartesianPoint::Init2D, "None", py::arg("aName"), py::arg("X"), py::arg("Y"));
cls_StepGeom_CartesianPoint.def("Init3D", (void (StepGeom_CartesianPoint::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const Standard_Real, const Standard_Real)) &StepGeom_CartesianPoint::Init3D, "None", py::arg("aName"), py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_StepGeom_CartesianPoint.def("SetCoordinates", (void (StepGeom_CartesianPoint::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_CartesianPoint::SetCoordinates, "None", py::arg("aCoordinates"));
cls_StepGeom_CartesianPoint.def("Coordinates", (opencascade::handle<TColStd_HArray1OfReal> (StepGeom_CartesianPoint::*)() const) &StepGeom_CartesianPoint::Coordinates, "None");
cls_StepGeom_CartesianPoint.def("CoordinatesValue", (Standard_Real (StepGeom_CartesianPoint::*)(const Standard_Integer) const) &StepGeom_CartesianPoint::CoordinatesValue, "None", py::arg("num"));
cls_StepGeom_CartesianPoint.def("NbCoordinates", (Standard_Integer (StepGeom_CartesianPoint::*)() const) &StepGeom_CartesianPoint::NbCoordinates, "None");
cls_StepGeom_CartesianPoint.def_static("get_type_name_", (const char * (*)()) &StepGeom_CartesianPoint::get_type_name, "None");
cls_StepGeom_CartesianPoint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_CartesianPoint::get_type_descriptor, "None");
cls_StepGeom_CartesianPoint.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_CartesianPoint::*)() const) &StepGeom_CartesianPoint::DynamicType, "None");

// Enums

}