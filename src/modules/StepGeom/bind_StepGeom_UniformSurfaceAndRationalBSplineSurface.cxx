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
#include <StepGeom_UniformSurface.hxx>
#include <StepGeom_RationalBSplineSurface.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <StepGeom_UniformSurfaceAndRationalBSplineSurface.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_UniformSurfaceAndRationalBSplineSurface(py::module &mod){

py::class_<StepGeom_UniformSurfaceAndRationalBSplineSurface, opencascade::handle<StepGeom_UniformSurfaceAndRationalBSplineSurface>, StepGeom_BSplineSurface> cls_StepGeom_UniformSurfaceAndRationalBSplineSurface(mod, "StepGeom_UniformSurfaceAndRationalBSplineSurface", "None");

// Constructors
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def(py::init<>());

// Fields

// Methods
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def("Init", (void (StepGeom_UniformSurfaceAndRationalBSplineSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Integer, const opencascade::handle<StepGeom_HArray2OfCartesianPoint> &, const StepGeom_BSplineSurfaceForm, const StepData_Logical, const StepData_Logical, const StepData_Logical, const opencascade::handle<StepGeom_UniformSurface> &, const opencascade::handle<StepGeom_RationalBSplineSurface> &)) &StepGeom_UniformSurfaceAndRationalBSplineSurface::Init, "None", py::arg("aName"), py::arg("aUDegree"), py::arg("aVDegree"), py::arg("aControlPointsList"), py::arg("aSurfaceForm"), py::arg("aUClosed"), py::arg("aVClosed"), py::arg("aSelfIntersect"), py::arg("aUniformSurface"), py::arg("aRationalBSplineSurface"));
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def("Init", (void (StepGeom_UniformSurfaceAndRationalBSplineSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Integer, const opencascade::handle<StepGeom_HArray2OfCartesianPoint> &, const StepGeom_BSplineSurfaceForm, const StepData_Logical, const StepData_Logical, const StepData_Logical, const opencascade::handle<TColStd_HArray2OfReal> &)) &StepGeom_UniformSurfaceAndRationalBSplineSurface::Init, "None", py::arg("aName"), py::arg("aUDegree"), py::arg("aVDegree"), py::arg("aControlPointsList"), py::arg("aSurfaceForm"), py::arg("aUClosed"), py::arg("aVClosed"), py::arg("aSelfIntersect"), py::arg("aWeightsData"));
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def("SetUniformSurface", (void (StepGeom_UniformSurfaceAndRationalBSplineSurface::*)(const opencascade::handle<StepGeom_UniformSurface> &)) &StepGeom_UniformSurfaceAndRationalBSplineSurface::SetUniformSurface, "None", py::arg("aUniformSurface"));
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def("UniformSurface", (opencascade::handle<StepGeom_UniformSurface> (StepGeom_UniformSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_UniformSurfaceAndRationalBSplineSurface::UniformSurface, "None");
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def("SetRationalBSplineSurface", (void (StepGeom_UniformSurfaceAndRationalBSplineSurface::*)(const opencascade::handle<StepGeom_RationalBSplineSurface> &)) &StepGeom_UniformSurfaceAndRationalBSplineSurface::SetRationalBSplineSurface, "None", py::arg("aRationalBSplineSurface"));
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def("RationalBSplineSurface", (opencascade::handle<StepGeom_RationalBSplineSurface> (StepGeom_UniformSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_UniformSurfaceAndRationalBSplineSurface::RationalBSplineSurface, "None");
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def("SetWeightsData", (void (StepGeom_UniformSurfaceAndRationalBSplineSurface::*)(const opencascade::handle<TColStd_HArray2OfReal> &)) &StepGeom_UniformSurfaceAndRationalBSplineSurface::SetWeightsData, "None", py::arg("aWeightsData"));
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def("WeightsData", (opencascade::handle<TColStd_HArray2OfReal> (StepGeom_UniformSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_UniformSurfaceAndRationalBSplineSurface::WeightsData, "None");
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def("WeightsDataValue", (Standard_Real (StepGeom_UniformSurfaceAndRationalBSplineSurface::*)(const Standard_Integer, const Standard_Integer) const) &StepGeom_UniformSurfaceAndRationalBSplineSurface::WeightsDataValue, "None", py::arg("num1"), py::arg("num2"));
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def("NbWeightsDataI", (Standard_Integer (StepGeom_UniformSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_UniformSurfaceAndRationalBSplineSurface::NbWeightsDataI, "None");
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def("NbWeightsDataJ", (Standard_Integer (StepGeom_UniformSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_UniformSurfaceAndRationalBSplineSurface::NbWeightsDataJ, "None");
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_UniformSurfaceAndRationalBSplineSurface::get_type_name, "None");
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_UniformSurfaceAndRationalBSplineSurface::get_type_descriptor, "None");
cls_StepGeom_UniformSurfaceAndRationalBSplineSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_UniformSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_UniformSurfaceAndRationalBSplineSurface::DynamicType, "None");

// Enums

}