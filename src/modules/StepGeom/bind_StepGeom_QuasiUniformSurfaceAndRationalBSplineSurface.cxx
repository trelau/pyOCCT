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
#include <StepGeom_QuasiUniformSurface.hxx>
#include <StepGeom_RationalBSplineSurface.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface(py::module &mod){

py::class_<StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface, opencascade::handle<StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface>, StepGeom_BSplineSurface> cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface(mod, "StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface", "None");

// Constructors
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def(py::init<>());

// Fields

// Methods
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def("Init", (void (StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Integer, const opencascade::handle<StepGeom_HArray2OfCartesianPoint> &, const StepGeom_BSplineSurfaceForm, const StepData_Logical, const StepData_Logical, const StepData_Logical, const opencascade::handle<StepGeom_QuasiUniformSurface> &, const opencascade::handle<StepGeom_RationalBSplineSurface> &)) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::Init, "None", py::arg("aName"), py::arg("aUDegree"), py::arg("aVDegree"), py::arg("aControlPointsList"), py::arg("aSurfaceForm"), py::arg("aUClosed"), py::arg("aVClosed"), py::arg("aSelfIntersect"), py::arg("aQuasiUniformSurface"), py::arg("aRationalBSplineSurface"));
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def("Init", (void (StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Integer, const opencascade::handle<StepGeom_HArray2OfCartesianPoint> &, const StepGeom_BSplineSurfaceForm, const StepData_Logical, const StepData_Logical, const StepData_Logical, const opencascade::handle<TColStd_HArray2OfReal> &)) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::Init, "None", py::arg("aName"), py::arg("aUDegree"), py::arg("aVDegree"), py::arg("aControlPointsList"), py::arg("aSurfaceForm"), py::arg("aUClosed"), py::arg("aVClosed"), py::arg("aSelfIntersect"), py::arg("aWeightsData"));
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def("SetQuasiUniformSurface", (void (StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::*)(const opencascade::handle<StepGeom_QuasiUniformSurface> &)) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::SetQuasiUniformSurface, "None", py::arg("aQuasiUniformSurface"));
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def("QuasiUniformSurface", (opencascade::handle<StepGeom_QuasiUniformSurface> (StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::QuasiUniformSurface, "None");
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def("SetRationalBSplineSurface", (void (StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::*)(const opencascade::handle<StepGeom_RationalBSplineSurface> &)) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::SetRationalBSplineSurface, "None", py::arg("aRationalBSplineSurface"));
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def("RationalBSplineSurface", (opencascade::handle<StepGeom_RationalBSplineSurface> (StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::RationalBSplineSurface, "None");
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def("SetWeightsData", (void (StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::*)(const opencascade::handle<TColStd_HArray2OfReal> &)) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::SetWeightsData, "None", py::arg("aWeightsData"));
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def("WeightsData", (opencascade::handle<TColStd_HArray2OfReal> (StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::WeightsData, "None");
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def("WeightsDataValue", (Standard_Real (StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::*)(const Standard_Integer, const Standard_Integer) const) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::WeightsDataValue, "None", py::arg("num1"), py::arg("num2"));
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def("NbWeightsDataI", (Standard_Integer (StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::NbWeightsDataI, "None");
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def("NbWeightsDataJ", (Standard_Integer (StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::NbWeightsDataJ, "None");
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::get_type_name, "None");
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::get_type_descriptor, "None");
cls_StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::*)() const) &StepGeom_QuasiUniformSurfaceAndRationalBSplineSurface::DynamicType, "None");

// Enums

}