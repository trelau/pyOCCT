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
#include <Standard_Transient.hxx>
#include <StepFEA_CurveElementEndCoordinateSystem.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <StepFEA_CurveElementEndOffset.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_CurveElementEndOffset(py::module &mod){

py::class_<StepFEA_CurveElementEndOffset, opencascade::handle<StepFEA_CurveElementEndOffset>, Standard_Transient> cls_StepFEA_CurveElementEndOffset(mod, "StepFEA_CurveElementEndOffset", "Representation of STEP entity CurveElementEndOffset");

// Constructors
cls_StepFEA_CurveElementEndOffset.def(py::init<>());

// Fields

// Methods
cls_StepFEA_CurveElementEndOffset.def("Init", (void (StepFEA_CurveElementEndOffset::*)(const StepFEA_CurveElementEndCoordinateSystem &, const opencascade::handle<TColStd_HArray1OfReal> &)) &StepFEA_CurveElementEndOffset::Init, "Initialize all fields (own and inherited)", py::arg("aCoordinateSystem"), py::arg("aOffsetVector"));
cls_StepFEA_CurveElementEndOffset.def("CoordinateSystem", (StepFEA_CurveElementEndCoordinateSystem (StepFEA_CurveElementEndOffset::*)() const) &StepFEA_CurveElementEndOffset::CoordinateSystem, "Returns field CoordinateSystem");
cls_StepFEA_CurveElementEndOffset.def("SetCoordinateSystem", (void (StepFEA_CurveElementEndOffset::*)(const StepFEA_CurveElementEndCoordinateSystem &)) &StepFEA_CurveElementEndOffset::SetCoordinateSystem, "Set field CoordinateSystem", py::arg("CoordinateSystem"));
cls_StepFEA_CurveElementEndOffset.def("OffsetVector", (opencascade::handle<TColStd_HArray1OfReal> (StepFEA_CurveElementEndOffset::*)() const) &StepFEA_CurveElementEndOffset::OffsetVector, "Returns field OffsetVector");
cls_StepFEA_CurveElementEndOffset.def("SetOffsetVector", (void (StepFEA_CurveElementEndOffset::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepFEA_CurveElementEndOffset::SetOffsetVector, "Set field OffsetVector", py::arg("OffsetVector"));
cls_StepFEA_CurveElementEndOffset.def_static("get_type_name_", (const char * (*)()) &StepFEA_CurveElementEndOffset::get_type_name, "None");
cls_StepFEA_CurveElementEndOffset.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_CurveElementEndOffset::get_type_descriptor, "None");
cls_StepFEA_CurveElementEndOffset.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_CurveElementEndOffset::*)() const) &StepFEA_CurveElementEndOffset::DynamicType, "None");

// Enums

}