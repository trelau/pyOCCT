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
#include <StepDimTol_GeometricTolerance.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepBasic_MeasureWithUnit.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <StepDimTol_HArray1OfDatumReference.hxx>
#include <StepDimTol_GeometricToleranceTarget.hxx>
#include <StepDimTol_HArray1OfDatumSystemOrReference.hxx>
#include <StepDimTol_GeometricToleranceWithDatumReference.hxx>
#include <Standard_Type.hxx>

void bind_StepDimTol_GeometricToleranceWithDatumReference(py::module &mod){

py::class_<StepDimTol_GeometricToleranceWithDatumReference, opencascade::handle<StepDimTol_GeometricToleranceWithDatumReference>, StepDimTol_GeometricTolerance> cls_StepDimTol_GeometricToleranceWithDatumReference(mod, "StepDimTol_GeometricToleranceWithDatumReference", "Representation of STEP entity GeometricToleranceWithDatumReference");

// Constructors
cls_StepDimTol_GeometricToleranceWithDatumReference.def(py::init<>());

// Fields

// Methods
cls_StepDimTol_GeometricToleranceWithDatumReference.def("Init", (void (StepDimTol_GeometricToleranceWithDatumReference::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepDimTol_HArray1OfDatumReference> &)) &StepDimTol_GeometricToleranceWithDatumReference::Init, "Initialize all fields (own and inherited) AP214", py::arg("theGeometricTolerance_Name"), py::arg("theGeometricTolerance_Description"), py::arg("theGeometricTolerance_Magnitude"), py::arg("theGeometricTolerance_TolerancedShapeAspect"), py::arg("theDatumSystem"));
cls_StepDimTol_GeometricToleranceWithDatumReference.def("Init", (void (StepDimTol_GeometricToleranceWithDatumReference::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &, const StepDimTol_GeometricToleranceTarget &, const opencascade::handle<StepDimTol_HArray1OfDatumSystemOrReference> &)) &StepDimTol_GeometricToleranceWithDatumReference::Init, "Initialize all fields (own and inherited) AP242", py::arg("theGeometricTolerance_Name"), py::arg("theGeometricTolerance_Description"), py::arg("theGeometricTolerance_Magnitude"), py::arg("theGeometricTolerance_TolerancedShapeAspect"), py::arg("theDatumSystem"));
cls_StepDimTol_GeometricToleranceWithDatumReference.def("DatumSystem", (opencascade::handle<StepDimTol_HArray1OfDatumReference> (StepDimTol_GeometricToleranceWithDatumReference::*)() const) &StepDimTol_GeometricToleranceWithDatumReference::DatumSystem, "Returns field DatumSystem AP214");
cls_StepDimTol_GeometricToleranceWithDatumReference.def("DatumSystemAP242", (opencascade::handle<StepDimTol_HArray1OfDatumSystemOrReference> (StepDimTol_GeometricToleranceWithDatumReference::*)() const) &StepDimTol_GeometricToleranceWithDatumReference::DatumSystemAP242, "Returns field DatumSystem AP242");
cls_StepDimTol_GeometricToleranceWithDatumReference.def("SetDatumSystem", (void (StepDimTol_GeometricToleranceWithDatumReference::*)(const opencascade::handle<StepDimTol_HArray1OfDatumReference> &)) &StepDimTol_GeometricToleranceWithDatumReference::SetDatumSystem, "Set field DatumSystem AP214", py::arg("theDatumSystem"));
cls_StepDimTol_GeometricToleranceWithDatumReference.def("SetDatumSystem", (void (StepDimTol_GeometricToleranceWithDatumReference::*)(const opencascade::handle<StepDimTol_HArray1OfDatumSystemOrReference> &)) &StepDimTol_GeometricToleranceWithDatumReference::SetDatumSystem, "Set field DatumSystem AP242", py::arg("theDatumSystem"));
cls_StepDimTol_GeometricToleranceWithDatumReference.def_static("get_type_name_", (const char * (*)()) &StepDimTol_GeometricToleranceWithDatumReference::get_type_name, "None");
cls_StepDimTol_GeometricToleranceWithDatumReference.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepDimTol_GeometricToleranceWithDatumReference::get_type_descriptor, "None");
cls_StepDimTol_GeometricToleranceWithDatumReference.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepDimTol_GeometricToleranceWithDatumReference::*)() const) &StepDimTol_GeometricToleranceWithDatumReference::DynamicType, "None");

// Enums

}