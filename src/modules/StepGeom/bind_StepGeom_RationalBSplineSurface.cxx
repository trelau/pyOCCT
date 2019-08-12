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
#include <StepGeom_BSplineSurface.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_HArray2OfCartesianPoint.hxx>
#include <StepGeom_BSplineSurfaceForm.hxx>
#include <StepData_Logical.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <StepGeom_RationalBSplineSurface.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_RationalBSplineSurface(py::module &mod){

py::class_<StepGeom_RationalBSplineSurface, opencascade::handle<StepGeom_RationalBSplineSurface>, StepGeom_BSplineSurface> cls_StepGeom_RationalBSplineSurface(mod, "StepGeom_RationalBSplineSurface", "None");

// Constructors
cls_StepGeom_RationalBSplineSurface.def(py::init<>());

// Fields

// Methods
cls_StepGeom_RationalBSplineSurface.def("Init", (void (StepGeom_RationalBSplineSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Integer, const opencascade::handle<StepGeom_HArray2OfCartesianPoint> &, const StepGeom_BSplineSurfaceForm, const StepData_Logical, const StepData_Logical, const StepData_Logical, const opencascade::handle<TColStd_HArray2OfReal> &)) &StepGeom_RationalBSplineSurface::Init, "None", py::arg("aName"), py::arg("aUDegree"), py::arg("aVDegree"), py::arg("aControlPointsList"), py::arg("aSurfaceForm"), py::arg("aUClosed"), py::arg("aVClosed"), py::arg("aSelfIntersect"), py::arg("aWeightsData"));
cls_StepGeom_RationalBSplineSurface.def("SetWeightsData", (void (StepGeom_RationalBSplineSurface::*)(const opencascade::handle<TColStd_HArray2OfReal> &)) &StepGeom_RationalBSplineSurface::SetWeightsData, "None", py::arg("aWeightsData"));
cls_StepGeom_RationalBSplineSurface.def("WeightsData", (opencascade::handle<TColStd_HArray2OfReal> (StepGeom_RationalBSplineSurface::*)() const) &StepGeom_RationalBSplineSurface::WeightsData, "None");
cls_StepGeom_RationalBSplineSurface.def("WeightsDataValue", (Standard_Real (StepGeom_RationalBSplineSurface::*)(const Standard_Integer, const Standard_Integer) const) &StepGeom_RationalBSplineSurface::WeightsDataValue, "None", py::arg("num1"), py::arg("num2"));
cls_StepGeom_RationalBSplineSurface.def("NbWeightsDataI", (Standard_Integer (StepGeom_RationalBSplineSurface::*)() const) &StepGeom_RationalBSplineSurface::NbWeightsDataI, "None");
cls_StepGeom_RationalBSplineSurface.def("NbWeightsDataJ", (Standard_Integer (StepGeom_RationalBSplineSurface::*)() const) &StepGeom_RationalBSplineSurface::NbWeightsDataJ, "None");
cls_StepGeom_RationalBSplineSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_RationalBSplineSurface::get_type_name, "None");
cls_StepGeom_RationalBSplineSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_RationalBSplineSurface::get_type_descriptor, "None");
cls_StepGeom_RationalBSplineSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_RationalBSplineSurface::*)() const) &StepGeom_RationalBSplineSurface::DynamicType, "None");

// Enums

}