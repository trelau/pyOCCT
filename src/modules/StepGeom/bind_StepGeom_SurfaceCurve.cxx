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
#include <StepGeom_HArray1OfPcurveOrSurface.hxx>
#include <StepGeom_PreferredSurfaceCurveRepresentation.hxx>
#include <StepGeom_PcurveOrSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_SurfaceCurve.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_SurfaceCurve(py::module &mod){

py::class_<StepGeom_SurfaceCurve, opencascade::handle<StepGeom_SurfaceCurve>, StepGeom_Curve> cls_StepGeom_SurfaceCurve(mod, "StepGeom_SurfaceCurve", "None");

// Constructors
cls_StepGeom_SurfaceCurve.def(py::init<>());

// Fields

// Methods
cls_StepGeom_SurfaceCurve.def("Init", (void (StepGeom_SurfaceCurve::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Curve> &, const opencascade::handle<StepGeom_HArray1OfPcurveOrSurface> &, const StepGeom_PreferredSurfaceCurveRepresentation)) &StepGeom_SurfaceCurve::Init, "None", py::arg("aName"), py::arg("aCurve3d"), py::arg("aAssociatedGeometry"), py::arg("aMasterRepresentation"));
cls_StepGeom_SurfaceCurve.def("SetCurve3d", (void (StepGeom_SurfaceCurve::*)(const opencascade::handle<StepGeom_Curve> &)) &StepGeom_SurfaceCurve::SetCurve3d, "None", py::arg("aCurve3d"));
cls_StepGeom_SurfaceCurve.def("Curve3d", (opencascade::handle<StepGeom_Curve> (StepGeom_SurfaceCurve::*)() const) &StepGeom_SurfaceCurve::Curve3d, "None");
cls_StepGeom_SurfaceCurve.def("SetAssociatedGeometry", (void (StepGeom_SurfaceCurve::*)(const opencascade::handle<StepGeom_HArray1OfPcurveOrSurface> &)) &StepGeom_SurfaceCurve::SetAssociatedGeometry, "None", py::arg("aAssociatedGeometry"));
cls_StepGeom_SurfaceCurve.def("AssociatedGeometry", (opencascade::handle<StepGeom_HArray1OfPcurveOrSurface> (StepGeom_SurfaceCurve::*)() const) &StepGeom_SurfaceCurve::AssociatedGeometry, "None");
cls_StepGeom_SurfaceCurve.def("AssociatedGeometryValue", (StepGeom_PcurveOrSurface (StepGeom_SurfaceCurve::*)(const Standard_Integer) const) &StepGeom_SurfaceCurve::AssociatedGeometryValue, "None", py::arg("num"));
cls_StepGeom_SurfaceCurve.def("NbAssociatedGeometry", (Standard_Integer (StepGeom_SurfaceCurve::*)() const) &StepGeom_SurfaceCurve::NbAssociatedGeometry, "None");
cls_StepGeom_SurfaceCurve.def("SetMasterRepresentation", (void (StepGeom_SurfaceCurve::*)(const StepGeom_PreferredSurfaceCurveRepresentation)) &StepGeom_SurfaceCurve::SetMasterRepresentation, "None", py::arg("aMasterRepresentation"));
cls_StepGeom_SurfaceCurve.def("MasterRepresentation", (StepGeom_PreferredSurfaceCurveRepresentation (StepGeom_SurfaceCurve::*)() const) &StepGeom_SurfaceCurve::MasterRepresentation, "None");
cls_StepGeom_SurfaceCurve.def_static("get_type_name_", (const char * (*)()) &StepGeom_SurfaceCurve::get_type_name, "None");
cls_StepGeom_SurfaceCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_SurfaceCurve::get_type_descriptor, "None");
cls_StepGeom_SurfaceCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_SurfaceCurve::*)() const) &StepGeom_SurfaceCurve::DynamicType, "None");

// Enums

}