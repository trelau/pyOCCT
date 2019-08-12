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
#include <StepGeom_Surface.hxx>
#include <StepRepr_DefinitionalRepresentation.hxx>
#include <StepGeom_DegeneratePcurve.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_DegeneratePcurve(py::module &mod){

py::class_<StepGeom_DegeneratePcurve, opencascade::handle<StepGeom_DegeneratePcurve>, StepGeom_Point> cls_StepGeom_DegeneratePcurve(mod, "StepGeom_DegeneratePcurve", "None");

// Constructors
cls_StepGeom_DegeneratePcurve.def(py::init<>());

// Fields

// Methods
cls_StepGeom_DegeneratePcurve.def("Init", (void (StepGeom_DegeneratePcurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Surface> &, const opencascade::handle<StepRepr_DefinitionalRepresentation> &)) &StepGeom_DegeneratePcurve::Init, "None", py::arg("aName"), py::arg("aBasisSurface"), py::arg("aReferenceToCurve"));
cls_StepGeom_DegeneratePcurve.def("SetBasisSurface", (void (StepGeom_DegeneratePcurve::*)(const opencascade::handle<StepGeom_Surface> &)) &StepGeom_DegeneratePcurve::SetBasisSurface, "None", py::arg("aBasisSurface"));
cls_StepGeom_DegeneratePcurve.def("BasisSurface", (opencascade::handle<StepGeom_Surface> (StepGeom_DegeneratePcurve::*)() const) &StepGeom_DegeneratePcurve::BasisSurface, "None");
cls_StepGeom_DegeneratePcurve.def("SetReferenceToCurve", (void (StepGeom_DegeneratePcurve::*)(const opencascade::handle<StepRepr_DefinitionalRepresentation> &)) &StepGeom_DegeneratePcurve::SetReferenceToCurve, "None", py::arg("aReferenceToCurve"));
cls_StepGeom_DegeneratePcurve.def("ReferenceToCurve", (opencascade::handle<StepRepr_DefinitionalRepresentation> (StepGeom_DegeneratePcurve::*)() const) &StepGeom_DegeneratePcurve::ReferenceToCurve, "None");
cls_StepGeom_DegeneratePcurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_DegeneratePcurve::get_type_name, "None");
cls_StepGeom_DegeneratePcurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_DegeneratePcurve::get_type_descriptor, "None");
cls_StepGeom_DegeneratePcurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_DegeneratePcurve::*)() const) &StepGeom_DegeneratePcurve::DynamicType, "None");

// Enums

}