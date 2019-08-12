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
#include <StepGeom_SweptSurface.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepGeom_Curve.hxx>
#include <StepGeom_Vector.hxx>
#include <StepGeom_SurfaceOfLinearExtrusion.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_SurfaceOfLinearExtrusion(py::module &mod){

py::class_<StepGeom_SurfaceOfLinearExtrusion, opencascade::handle<StepGeom_SurfaceOfLinearExtrusion>, StepGeom_SweptSurface> cls_StepGeom_SurfaceOfLinearExtrusion(mod, "StepGeom_SurfaceOfLinearExtrusion", "None");

// Constructors
cls_StepGeom_SurfaceOfLinearExtrusion.def(py::init<>());

// Fields

// Methods
cls_StepGeom_SurfaceOfLinearExtrusion.def("Init", (void (StepGeom_SurfaceOfLinearExtrusion::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Curve> &, const opencascade::handle<StepGeom_Vector> &)) &StepGeom_SurfaceOfLinearExtrusion::Init, "None", py::arg("aName"), py::arg("aSweptCurve"), py::arg("aExtrusionAxis"));
cls_StepGeom_SurfaceOfLinearExtrusion.def("SetExtrusionAxis", (void (StepGeom_SurfaceOfLinearExtrusion::*)(const opencascade::handle<StepGeom_Vector> &)) &StepGeom_SurfaceOfLinearExtrusion::SetExtrusionAxis, "None", py::arg("aExtrusionAxis"));
cls_StepGeom_SurfaceOfLinearExtrusion.def("ExtrusionAxis", (opencascade::handle<StepGeom_Vector> (StepGeom_SurfaceOfLinearExtrusion::*)() const) &StepGeom_SurfaceOfLinearExtrusion::ExtrusionAxis, "None");
cls_StepGeom_SurfaceOfLinearExtrusion.def_static("get_type_name_", (const char * (*)()) &StepGeom_SurfaceOfLinearExtrusion::get_type_name, "None");
cls_StepGeom_SurfaceOfLinearExtrusion.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_SurfaceOfLinearExtrusion::get_type_descriptor, "None");
cls_StepGeom_SurfaceOfLinearExtrusion.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_SurfaceOfLinearExtrusion::*)() const) &StepGeom_SurfaceOfLinearExtrusion::DynamicType, "None");

// Enums

}