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
#include <StepGeom_BSplineSurfaceWithKnots.hxx>
#include <StepGeom_RationalBSplineSurface.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <StepGeom_KnotType.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface(py::module &mod){

py::class_<StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface, opencascade::handle<StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface>, StepGeom_BSplineSurface> cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface(mod, "StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface", "None");

// Constructors
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def(py::init<>());

// Fields

// Methods
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("Init", (void (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Integer, const opencascade::handle<StepGeom_HArray2OfCartesianPoint> &, const StepGeom_BSplineSurfaceForm, const StepData_Logical, const StepData_Logical, const StepData_Logical, const opencascade::handle<StepGeom_BSplineSurfaceWithKnots> &, const opencascade::handle<StepGeom_RationalBSplineSurface> &)) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::Init, "None", py::arg("aName"), py::arg("aUDegree"), py::arg("aVDegree"), py::arg("aControlPointsList"), py::arg("aSurfaceForm"), py::arg("aUClosed"), py::arg("aVClosed"), py::arg("aSelfIntersect"), py::arg("aBSplineSurfaceWithKnots"), py::arg("aRationalBSplineSurface"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("Init", (void (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Integer, const opencascade::handle<StepGeom_HArray2OfCartesianPoint> &, const StepGeom_BSplineSurfaceForm, const StepData_Logical, const StepData_Logical, const StepData_Logical, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const StepGeom_KnotType, const opencascade::handle<TColStd_HArray2OfReal> &)) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::Init, "None", py::arg("aName"), py::arg("aUDegree"), py::arg("aVDegree"), py::arg("aControlPointsList"), py::arg("aSurfaceForm"), py::arg("aUClosed"), py::arg("aVClosed"), py::arg("aSelfIntersect"), py::arg("aUMultiplicities"), py::arg("aVMultiplicities"), py::arg("aUKnots"), py::arg("aVKnots"), py::arg("aKnotSpec"), py::arg("aWeightsData"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("SetBSplineSurfaceWithKnots", (void (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const opencascade::handle<StepGeom_BSplineSurfaceWithKnots> &)) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::SetBSplineSurfaceWithKnots, "None", py::arg("aBSplineSurfaceWithKnots"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("BSplineSurfaceWithKnots", (opencascade::handle<StepGeom_BSplineSurfaceWithKnots> (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::BSplineSurfaceWithKnots, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("SetRationalBSplineSurface", (void (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const opencascade::handle<StepGeom_RationalBSplineSurface> &)) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::SetRationalBSplineSurface, "None", py::arg("aRationalBSplineSurface"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("RationalBSplineSurface", (opencascade::handle<StepGeom_RationalBSplineSurface> (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::RationalBSplineSurface, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("SetUMultiplicities", (void (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::SetUMultiplicities, "None", py::arg("aUMultiplicities"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("UMultiplicities", (opencascade::handle<TColStd_HArray1OfInteger> (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::UMultiplicities, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("UMultiplicitiesValue", (Standard_Integer (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const Standard_Integer) const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::UMultiplicitiesValue, "None", py::arg("num"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("NbUMultiplicities", (Standard_Integer (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::NbUMultiplicities, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("SetVMultiplicities", (void (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::SetVMultiplicities, "None", py::arg("aVMultiplicities"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("VMultiplicities", (opencascade::handle<TColStd_HArray1OfInteger> (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::VMultiplicities, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("VMultiplicitiesValue", (Standard_Integer (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const Standard_Integer) const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::VMultiplicitiesValue, "None", py::arg("num"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("NbVMultiplicities", (Standard_Integer (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::NbVMultiplicities, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("SetUKnots", (void (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::SetUKnots, "None", py::arg("aUKnots"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("UKnots", (opencascade::handle<TColStd_HArray1OfReal> (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::UKnots, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("UKnotsValue", (Standard_Real (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const Standard_Integer) const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::UKnotsValue, "None", py::arg("num"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("NbUKnots", (Standard_Integer (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::NbUKnots, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("SetVKnots", (void (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::SetVKnots, "None", py::arg("aVKnots"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("VKnots", (opencascade::handle<TColStd_HArray1OfReal> (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::VKnots, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("VKnotsValue", (Standard_Real (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const Standard_Integer) const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::VKnotsValue, "None", py::arg("num"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("NbVKnots", (Standard_Integer (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::NbVKnots, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("SetKnotSpec", (void (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const StepGeom_KnotType)) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::SetKnotSpec, "None", py::arg("aKnotSpec"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("KnotSpec", (StepGeom_KnotType (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::KnotSpec, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("SetWeightsData", (void (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const opencascade::handle<TColStd_HArray2OfReal> &)) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::SetWeightsData, "None", py::arg("aWeightsData"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("WeightsData", (opencascade::handle<TColStd_HArray2OfReal> (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::WeightsData, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("WeightsDataValue", (Standard_Real (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)(const Standard_Integer, const Standard_Integer) const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::WeightsDataValue, "None", py::arg("num1"), py::arg("num2"));
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("NbWeightsDataI", (Standard_Integer (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::NbWeightsDataI, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("NbWeightsDataJ", (Standard_Integer (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::NbWeightsDataJ, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::get_type_name, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::get_type_descriptor, "None");
cls_StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::*)() const) &StepGeom_BSplineSurfaceWithKnotsAndRationalBSplineSurface::DynamicType, "None");

// Enums

}