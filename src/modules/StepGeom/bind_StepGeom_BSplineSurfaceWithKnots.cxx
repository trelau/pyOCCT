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
#include <TColStd_HArray1OfInteger.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <StepGeom_KnotType.hxx>
#include <StepGeom_BSplineSurfaceWithKnots.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_BSplineSurfaceWithKnots(py::module &mod){

py::class_<StepGeom_BSplineSurfaceWithKnots, opencascade::handle<StepGeom_BSplineSurfaceWithKnots>, StepGeom_BSplineSurface> cls_StepGeom_BSplineSurfaceWithKnots(mod, "StepGeom_BSplineSurfaceWithKnots", "None");

// Constructors
cls_StepGeom_BSplineSurfaceWithKnots.def(py::init<>());

// Fields

// Methods
cls_StepGeom_BSplineSurfaceWithKnots.def("Init", (void (StepGeom_BSplineSurfaceWithKnots::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer, const Standard_Integer, const opencascade::handle<StepGeom_HArray2OfCartesianPoint> &, const StepGeom_BSplineSurfaceForm, const StepData_Logical, const StepData_Logical, const StepData_Logical, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const StepGeom_KnotType)) &StepGeom_BSplineSurfaceWithKnots::Init, "None", py::arg("aName"), py::arg("aUDegree"), py::arg("aVDegree"), py::arg("aControlPointsList"), py::arg("aSurfaceForm"), py::arg("aUClosed"), py::arg("aVClosed"), py::arg("aSelfIntersect"), py::arg("aUMultiplicities"), py::arg("aVMultiplicities"), py::arg("aUKnots"), py::arg("aVKnots"), py::arg("aKnotSpec"));
cls_StepGeom_BSplineSurfaceWithKnots.def("SetUMultiplicities", (void (StepGeom_BSplineSurfaceWithKnots::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &StepGeom_BSplineSurfaceWithKnots::SetUMultiplicities, "None", py::arg("aUMultiplicities"));
cls_StepGeom_BSplineSurfaceWithKnots.def("UMultiplicities", (opencascade::handle<TColStd_HArray1OfInteger> (StepGeom_BSplineSurfaceWithKnots::*)() const) &StepGeom_BSplineSurfaceWithKnots::UMultiplicities, "None");
cls_StepGeom_BSplineSurfaceWithKnots.def("UMultiplicitiesValue", (Standard_Integer (StepGeom_BSplineSurfaceWithKnots::*)(const Standard_Integer) const) &StepGeom_BSplineSurfaceWithKnots::UMultiplicitiesValue, "None", py::arg("num"));
cls_StepGeom_BSplineSurfaceWithKnots.def("NbUMultiplicities", (Standard_Integer (StepGeom_BSplineSurfaceWithKnots::*)() const) &StepGeom_BSplineSurfaceWithKnots::NbUMultiplicities, "None");
cls_StepGeom_BSplineSurfaceWithKnots.def("SetVMultiplicities", (void (StepGeom_BSplineSurfaceWithKnots::*)(const opencascade::handle<TColStd_HArray1OfInteger> &)) &StepGeom_BSplineSurfaceWithKnots::SetVMultiplicities, "None", py::arg("aVMultiplicities"));
cls_StepGeom_BSplineSurfaceWithKnots.def("VMultiplicities", (opencascade::handle<TColStd_HArray1OfInteger> (StepGeom_BSplineSurfaceWithKnots::*)() const) &StepGeom_BSplineSurfaceWithKnots::VMultiplicities, "None");
cls_StepGeom_BSplineSurfaceWithKnots.def("VMultiplicitiesValue", (Standard_Integer (StepGeom_BSplineSurfaceWithKnots::*)(const Standard_Integer) const) &StepGeom_BSplineSurfaceWithKnots::VMultiplicitiesValue, "None", py::arg("num"));
cls_StepGeom_BSplineSurfaceWithKnots.def("NbVMultiplicities", (Standard_Integer (StepGeom_BSplineSurfaceWithKnots::*)() const) &StepGeom_BSplineSurfaceWithKnots::NbVMultiplicities, "None");
cls_StepGeom_BSplineSurfaceWithKnots.def("SetUKnots", (void (StepGeom_BSplineSurfaceWithKnots::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_BSplineSurfaceWithKnots::SetUKnots, "None", py::arg("aUKnots"));
cls_StepGeom_BSplineSurfaceWithKnots.def("UKnots", (opencascade::handle<TColStd_HArray1OfReal> (StepGeom_BSplineSurfaceWithKnots::*)() const) &StepGeom_BSplineSurfaceWithKnots::UKnots, "None");
cls_StepGeom_BSplineSurfaceWithKnots.def("UKnotsValue", (Standard_Real (StepGeom_BSplineSurfaceWithKnots::*)(const Standard_Integer) const) &StepGeom_BSplineSurfaceWithKnots::UKnotsValue, "None", py::arg("num"));
cls_StepGeom_BSplineSurfaceWithKnots.def("NbUKnots", (Standard_Integer (StepGeom_BSplineSurfaceWithKnots::*)() const) &StepGeom_BSplineSurfaceWithKnots::NbUKnots, "None");
cls_StepGeom_BSplineSurfaceWithKnots.def("SetVKnots", (void (StepGeom_BSplineSurfaceWithKnots::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepGeom_BSplineSurfaceWithKnots::SetVKnots, "None", py::arg("aVKnots"));
cls_StepGeom_BSplineSurfaceWithKnots.def("VKnots", (opencascade::handle<TColStd_HArray1OfReal> (StepGeom_BSplineSurfaceWithKnots::*)() const) &StepGeom_BSplineSurfaceWithKnots::VKnots, "None");
cls_StepGeom_BSplineSurfaceWithKnots.def("VKnotsValue", (Standard_Real (StepGeom_BSplineSurfaceWithKnots::*)(const Standard_Integer) const) &StepGeom_BSplineSurfaceWithKnots::VKnotsValue, "None", py::arg("num"));
cls_StepGeom_BSplineSurfaceWithKnots.def("NbVKnots", (Standard_Integer (StepGeom_BSplineSurfaceWithKnots::*)() const) &StepGeom_BSplineSurfaceWithKnots::NbVKnots, "None");
cls_StepGeom_BSplineSurfaceWithKnots.def("SetKnotSpec", (void (StepGeom_BSplineSurfaceWithKnots::*)(const StepGeom_KnotType)) &StepGeom_BSplineSurfaceWithKnots::SetKnotSpec, "None", py::arg("aKnotSpec"));
cls_StepGeom_BSplineSurfaceWithKnots.def("KnotSpec", (StepGeom_KnotType (StepGeom_BSplineSurfaceWithKnots::*)() const) &StepGeom_BSplineSurfaceWithKnots::KnotSpec, "None");
cls_StepGeom_BSplineSurfaceWithKnots.def_static("get_type_name_", (const char * (*)()) &StepGeom_BSplineSurfaceWithKnots::get_type_name, "None");
cls_StepGeom_BSplineSurfaceWithKnots.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_BSplineSurfaceWithKnots::get_type_descriptor, "None");
cls_StepGeom_BSplineSurfaceWithKnots.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_BSplineSurfaceWithKnots::*)() const) &StepGeom_BSplineSurfaceWithKnots::DynamicType, "None");

// Enums

}