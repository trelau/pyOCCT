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
#include <StepGeom_DegeneratePcurve.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepGeom_Surface.hxx>
#include <StepRepr_DefinitionalRepresentation.hxx>
#include <StepGeom_CartesianPoint.hxx>
#include <StepGeom_EvaluatedDegeneratePcurve.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_EvaluatedDegeneratePcurve(py::module &mod){

py::class_<StepGeom_EvaluatedDegeneratePcurve, opencascade::handle<StepGeom_EvaluatedDegeneratePcurve>, StepGeom_DegeneratePcurve> cls_StepGeom_EvaluatedDegeneratePcurve(mod, "StepGeom_EvaluatedDegeneratePcurve", "None");

// Constructors
cls_StepGeom_EvaluatedDegeneratePcurve.def(py::init<>());

// Fields

// Methods
cls_StepGeom_EvaluatedDegeneratePcurve.def("Init", (void (StepGeom_EvaluatedDegeneratePcurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Surface> &, const opencascade::handle<StepRepr_DefinitionalRepresentation> &, const opencascade::handle<StepGeom_CartesianPoint> &)) &StepGeom_EvaluatedDegeneratePcurve::Init, "None", py::arg("aName"), py::arg("aBasisSurface"), py::arg("aReferenceToCurve"), py::arg("aEquivalentPoint"));
cls_StepGeom_EvaluatedDegeneratePcurve.def("SetEquivalentPoint", (void (StepGeom_EvaluatedDegeneratePcurve::*)(const opencascade::handle<StepGeom_CartesianPoint> &)) &StepGeom_EvaluatedDegeneratePcurve::SetEquivalentPoint, "None", py::arg("aEquivalentPoint"));
cls_StepGeom_EvaluatedDegeneratePcurve.def("EquivalentPoint", (opencascade::handle<StepGeom_CartesianPoint> (StepGeom_EvaluatedDegeneratePcurve::*)() const) &StepGeom_EvaluatedDegeneratePcurve::EquivalentPoint, "None");
cls_StepGeom_EvaluatedDegeneratePcurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_EvaluatedDegeneratePcurve::get_type_name, "None");
cls_StepGeom_EvaluatedDegeneratePcurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_EvaluatedDegeneratePcurve::get_type_descriptor, "None");
cls_StepGeom_EvaluatedDegeneratePcurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_EvaluatedDegeneratePcurve::*)() const) &StepGeom_EvaluatedDegeneratePcurve::DynamicType, "None");

// Enums

}