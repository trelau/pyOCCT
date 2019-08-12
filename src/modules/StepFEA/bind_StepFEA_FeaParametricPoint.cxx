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
#include <StepGeom_Point.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <StepFEA_FeaParametricPoint.hxx>
#include <Standard_Type.hxx>

void bind_StepFEA_FeaParametricPoint(py::module &mod){

py::class_<StepFEA_FeaParametricPoint, opencascade::handle<StepFEA_FeaParametricPoint>, StepGeom_Point> cls_StepFEA_FeaParametricPoint(mod, "StepFEA_FeaParametricPoint", "Representation of STEP entity FeaParametricPoint");

// Constructors
cls_StepFEA_FeaParametricPoint.def(py::init<>());

// Fields

// Methods
cls_StepFEA_FeaParametricPoint.def("Init", (void (StepFEA_FeaParametricPoint::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TColStd_HArray1OfReal> &)) &StepFEA_FeaParametricPoint::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aCoordinates"));
cls_StepFEA_FeaParametricPoint.def("Coordinates", (opencascade::handle<TColStd_HArray1OfReal> (StepFEA_FeaParametricPoint::*)() const) &StepFEA_FeaParametricPoint::Coordinates, "Returns field Coordinates");
cls_StepFEA_FeaParametricPoint.def("SetCoordinates", (void (StepFEA_FeaParametricPoint::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepFEA_FeaParametricPoint::SetCoordinates, "Set field Coordinates", py::arg("Coordinates"));
cls_StepFEA_FeaParametricPoint.def_static("get_type_name_", (const char * (*)()) &StepFEA_FeaParametricPoint::get_type_name, "None");
cls_StepFEA_FeaParametricPoint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepFEA_FeaParametricPoint::get_type_descriptor, "None");
cls_StepFEA_FeaParametricPoint.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepFEA_FeaParametricPoint::*)() const) &StepFEA_FeaParametricPoint::DynamicType, "None");

// Enums

}