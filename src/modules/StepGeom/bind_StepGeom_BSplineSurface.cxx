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
#include <StepGeom_BoundedSurface.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_HArray2OfCartesianPoint.hxx>
#include <StepGeom_BSplineSurfaceForm.hxx>
#include <StepData_Logical.hxx>
#include <StepGeom_CartesianPoint.hxx>
#include <StepGeom_BSplineSurface.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_BSplineSurface(py::module &mod){

py::class_<StepGeom_BSplineSurface, opencascade::handle<StepGeom_BSplineSurface>, StepGeom_BoundedSurface> cls_StepGeom_BSplineSurface(mod, "StepGeom_BSplineSurface", "None");

// Constructors
cls_StepGeom_BSplineSurface.def(py::init<>());

// Fields

// Methods
cls_StepGeom_BSplineSurface.def("Init", (void (StepGeom_BSplineSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Integer, const opencascade::handle<StepGeom_HArray2OfCartesianPoint> &, const StepGeom_BSplineSurfaceForm, const StepData_Logical, const StepData_Logical, const StepData_Logical)) &StepGeom_BSplineSurface::Init, "None", py::arg("aName"), py::arg("aUDegree"), py::arg("aVDegree"), py::arg("aControlPointsList"), py::arg("aSurfaceForm"), py::arg("aUClosed"), py::arg("aVClosed"), py::arg("aSelfIntersect"));
cls_StepGeom_BSplineSurface.def("SetUDegree", (void (StepGeom_BSplineSurface::*)(const Standard_Integer)) &StepGeom_BSplineSurface::SetUDegree, "None", py::arg("aUDegree"));
cls_StepGeom_BSplineSurface.def("UDegree", (Standard_Integer (StepGeom_BSplineSurface::*)() const) &StepGeom_BSplineSurface::UDegree, "None");
cls_StepGeom_BSplineSurface.def("SetVDegree", (void (StepGeom_BSplineSurface::*)(const Standard_Integer)) &StepGeom_BSplineSurface::SetVDegree, "None", py::arg("aVDegree"));
cls_StepGeom_BSplineSurface.def("VDegree", (Standard_Integer (StepGeom_BSplineSurface::*)() const) &StepGeom_BSplineSurface::VDegree, "None");
cls_StepGeom_BSplineSurface.def("SetControlPointsList", (void (StepGeom_BSplineSurface::*)(const opencascade::handle<StepGeom_HArray2OfCartesianPoint> &)) &StepGeom_BSplineSurface::SetControlPointsList, "None", py::arg("aControlPointsList"));
cls_StepGeom_BSplineSurface.def("ControlPointsList", (opencascade::handle<StepGeom_HArray2OfCartesianPoint> (StepGeom_BSplineSurface::*)() const) &StepGeom_BSplineSurface::ControlPointsList, "None");
cls_StepGeom_BSplineSurface.def("ControlPointsListValue", (opencascade::handle<StepGeom_CartesianPoint> (StepGeom_BSplineSurface::*)(const Standard_Integer, const Standard_Integer) const) &StepGeom_BSplineSurface::ControlPointsListValue, "None", py::arg("num1"), py::arg("num2"));
cls_StepGeom_BSplineSurface.def("NbControlPointsListI", (Standard_Integer (StepGeom_BSplineSurface::*)() const) &StepGeom_BSplineSurface::NbControlPointsListI, "None");
cls_StepGeom_BSplineSurface.def("NbControlPointsListJ", (Standard_Integer (StepGeom_BSplineSurface::*)() const) &StepGeom_BSplineSurface::NbControlPointsListJ, "None");
cls_StepGeom_BSplineSurface.def("SetSurfaceForm", (void (StepGeom_BSplineSurface::*)(const StepGeom_BSplineSurfaceForm)) &StepGeom_BSplineSurface::SetSurfaceForm, "None", py::arg("aSurfaceForm"));
cls_StepGeom_BSplineSurface.def("SurfaceForm", (StepGeom_BSplineSurfaceForm (StepGeom_BSplineSurface::*)() const) &StepGeom_BSplineSurface::SurfaceForm, "None");
cls_StepGeom_BSplineSurface.def("SetUClosed", (void (StepGeom_BSplineSurface::*)(const StepData_Logical)) &StepGeom_BSplineSurface::SetUClosed, "None", py::arg("aUClosed"));
cls_StepGeom_BSplineSurface.def("UClosed", (StepData_Logical (StepGeom_BSplineSurface::*)() const) &StepGeom_BSplineSurface::UClosed, "None");
cls_StepGeom_BSplineSurface.def("SetVClosed", (void (StepGeom_BSplineSurface::*)(const StepData_Logical)) &StepGeom_BSplineSurface::SetVClosed, "None", py::arg("aVClosed"));
cls_StepGeom_BSplineSurface.def("VClosed", (StepData_Logical (StepGeom_BSplineSurface::*)() const) &StepGeom_BSplineSurface::VClosed, "None");
cls_StepGeom_BSplineSurface.def("SetSelfIntersect", (void (StepGeom_BSplineSurface::*)(const StepData_Logical)) &StepGeom_BSplineSurface::SetSelfIntersect, "None", py::arg("aSelfIntersect"));
cls_StepGeom_BSplineSurface.def("SelfIntersect", (StepData_Logical (StepGeom_BSplineSurface::*)() const) &StepGeom_BSplineSurface::SelfIntersect, "None");
cls_StepGeom_BSplineSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_BSplineSurface::get_type_name, "None");
cls_StepGeom_BSplineSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_BSplineSurface::get_type_descriptor, "None");
cls_StepGeom_BSplineSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_BSplineSurface::*)() const) &StepGeom_BSplineSurface::DynamicType, "None");

// Enums

}