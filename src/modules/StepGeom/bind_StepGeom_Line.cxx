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
#include <StepGeom_Curve.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepGeom_CartesianPoint.hxx>
#include <StepGeom_Vector.hxx>
#include <StepGeom_Line.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_Line(py::module &mod){

py::class_<StepGeom_Line, opencascade::handle<StepGeom_Line>, StepGeom_Curve> cls_StepGeom_Line(mod, "StepGeom_Line", "None");

// Constructors
cls_StepGeom_Line.def(py::init<>());

// Fields

// Methods
cls_StepGeom_Line.def("Init", (void (StepGeom_Line::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_CartesianPoint> &, const opencascade::handle<StepGeom_Vector> &)) &StepGeom_Line::Init, "None", py::arg("aName"), py::arg("aPnt"), py::arg("aDir"));
cls_StepGeom_Line.def("SetPnt", (void (StepGeom_Line::*)(const opencascade::handle<StepGeom_CartesianPoint> &)) &StepGeom_Line::SetPnt, "None", py::arg("aPnt"));
cls_StepGeom_Line.def("Pnt", (opencascade::handle<StepGeom_CartesianPoint> (StepGeom_Line::*)() const) &StepGeom_Line::Pnt, "None");
cls_StepGeom_Line.def("SetDir", (void (StepGeom_Line::*)(const opencascade::handle<StepGeom_Vector> &)) &StepGeom_Line::SetDir, "None", py::arg("aDir"));
cls_StepGeom_Line.def("Dir", (opencascade::handle<StepGeom_Vector> (StepGeom_Line::*)() const) &StepGeom_Line::Dir, "None");
cls_StepGeom_Line.def_static("get_type_name_", (const char * (*)()) &StepGeom_Line::get_type_name, "None");
cls_StepGeom_Line.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_Line::get_type_descriptor, "None");
cls_StepGeom_Line.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_Line::*)() const) &StepGeom_Line::DynamicType, "None");

// Enums

}