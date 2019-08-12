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
#include <StepGeom_SurfaceCurve.hxx>
#include <Standard_Handle.hxx>
#include <StepGeom_BoundedCurve.hxx>
#include <StepGeom_SurfaceCurveAndBoundedCurve.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_SurfaceCurveAndBoundedCurve(py::module &mod){

py::class_<StepGeom_SurfaceCurveAndBoundedCurve, opencascade::handle<StepGeom_SurfaceCurveAndBoundedCurve>, StepGeom_SurfaceCurve> cls_StepGeom_SurfaceCurveAndBoundedCurve(mod, "StepGeom_SurfaceCurveAndBoundedCurve", "complex type: bounded_curve + surface_curve needed for curve_bounded_surfaces (S4132)");

// Constructors
cls_StepGeom_SurfaceCurveAndBoundedCurve.def(py::init<>());

// Fields

// Methods
cls_StepGeom_SurfaceCurveAndBoundedCurve.def("BoundedCurve", (opencascade::handle<StepGeom_BoundedCurve> & (StepGeom_SurfaceCurveAndBoundedCurve::*)()) &StepGeom_SurfaceCurveAndBoundedCurve::BoundedCurve, "returns field BoundedCurve");
cls_StepGeom_SurfaceCurveAndBoundedCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_SurfaceCurveAndBoundedCurve::get_type_name, "None");
cls_StepGeom_SurfaceCurveAndBoundedCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_SurfaceCurveAndBoundedCurve::get_type_descriptor, "None");
cls_StepGeom_SurfaceCurveAndBoundedCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_SurfaceCurveAndBoundedCurve::*)() const) &StepGeom_SurfaceCurveAndBoundedCurve::DynamicType, "None");

// Enums

}