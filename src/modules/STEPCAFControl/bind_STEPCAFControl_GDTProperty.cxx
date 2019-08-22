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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <StepRepr_CompoundRepresentationItem.hxx>
#include <XCAFDimTolObjects_DimensionModifiersSequence.hxx>
#include <StepShape_LimitsAndFits.hxx>
#include <Standard_TypeDef.hxx>
#include <XCAFDimTolObjects_DimensionFormVariance.hxx>
#include <XCAFDimTolObjects_DimensionGrade.hxx>
#include <TCollection_HAsciiString.hxx>
#include <XCAFDimTolObjects_DimensionType.hxx>
#include <XCAFDimTolObjects_DatumTargetType.hxx>
#include <XCAFDimTolObjects_DimensionQualifier.hxx>
#include <XCAFDimTolObjects_GeomToleranceTypeValue.hxx>
#include <XCAFDimTolObjects_DimensionModif.hxx>
#include <StepDimTol_GeometricToleranceType.hxx>
#include <XCAFDimTolObjects_GeomToleranceType.hxx>
#include <StepDimTol_GeometricTolerance.hxx>
#include <StepDimTol_GeometricToleranceModifier.hxx>
#include <XCAFDimTolObjects_GeomToleranceModif.hxx>
#include <StepDimTol_HArray1OfDatumReferenceModifier.hxx>
#include <XCAFDimTolObjects_DatumModifiersSequence.hxx>
#include <XCAFDimTolObjects_DatumModifWithValue.hxx>
#include <StepBasic_Unit.hxx>
#include <StepVisual_TessellatedGeometricSet.hxx>
#include <TopoDS_Shape.hxx>
#include <STEPCAFControl_GDTProperty.hxx>

void bind_STEPCAFControl_GDTProperty(py::module &mod){

py::class_<STEPCAFControl_GDTProperty> cls_STEPCAFControl_GDTProperty(mod, "STEPCAFControl_GDTProperty", "This class provides tools for access (read) the GDT properties.");

// Constructors
cls_STEPCAFControl_GDTProperty.def(py::init<>());

// Fields

// Methods
// cls_STEPCAFControl_GDTProperty.def_static("operator new_", (void * (*)(size_t)) &STEPCAFControl_GDTProperty::operator new, "None", py::arg("theSize"));
// cls_STEPCAFControl_GDTProperty.def_static("operator delete_", (void (*)(void *)) &STEPCAFControl_GDTProperty::operator delete, "None", py::arg("theAddress"));
// cls_STEPCAFControl_GDTProperty.def_static("operator new[]_", (void * (*)(size_t)) &STEPCAFControl_GDTProperty::operator new[], "None", py::arg("theSize"));
// cls_STEPCAFControl_GDTProperty.def_static("operator delete[]_", (void (*)(void *)) &STEPCAFControl_GDTProperty::operator delete[], "None", py::arg("theAddress"));
// cls_STEPCAFControl_GDTProperty.def_static("operator new_", (void * (*)(size_t, void *)) &STEPCAFControl_GDTProperty::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPCAFControl_GDTProperty.def_static("operator delete_", (void (*)(void *, void *)) &STEPCAFControl_GDTProperty::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPCAFControl_GDTProperty.def_static("GetDimModifiers_", (void (*)(const opencascade::handle<StepRepr_CompoundRepresentationItem> &, XCAFDimTolObjects_DimensionModifiersSequence &)) &STEPCAFControl_GDTProperty::GetDimModifiers, "None", py::arg("theCRI"), py::arg("theModifiers"));
cls_STEPCAFControl_GDTProperty.def_static("GetDimClassOfTolerance_", [](const opencascade::handle<StepShape_LimitsAndFits> & theLAF, Standard_Boolean & theHolle, XCAFDimTolObjects_DimensionFormVariance & theFV, XCAFDimTolObjects_DimensionGrade & theG){ STEPCAFControl_GDTProperty::GetDimClassOfTolerance(theLAF, theHolle, theFV, theG); return theHolle; }, "None", py::arg("theLAF"), py::arg("theHolle"), py::arg("theFV"), py::arg("theG"));
cls_STEPCAFControl_GDTProperty.def_static("GetDimType_", (Standard_Boolean (*)(const opencascade::handle<TCollection_HAsciiString> &, XCAFDimTolObjects_DimensionType &)) &STEPCAFControl_GDTProperty::GetDimType, "None", py::arg("theName"), py::arg("theType"));
cls_STEPCAFControl_GDTProperty.def_static("GetDatumTargetType_", (Standard_Boolean (*)(const opencascade::handle<TCollection_HAsciiString> &, XCAFDimTolObjects_DatumTargetType &)) &STEPCAFControl_GDTProperty::GetDatumTargetType, "None", py::arg("theDescription"), py::arg("theType"));
cls_STEPCAFControl_GDTProperty.def_static("GetDimQualifierType_", (Standard_Boolean (*)(const opencascade::handle<TCollection_HAsciiString> &, XCAFDimTolObjects_DimensionQualifier &)) &STEPCAFControl_GDTProperty::GetDimQualifierType, "None", py::arg("theDescription"), py::arg("theType"));
cls_STEPCAFControl_GDTProperty.def_static("GetTolValueType_", (Standard_Boolean (*)(const opencascade::handle<TCollection_HAsciiString> &, XCAFDimTolObjects_GeomToleranceTypeValue &)) &STEPCAFControl_GDTProperty::GetTolValueType, "None", py::arg("theDescription"), py::arg("theType"));
cls_STEPCAFControl_GDTProperty.def_static("GetTolValueType_", (opencascade::handle<TCollection_HAsciiString> (*)(const XCAFDimTolObjects_GeomToleranceTypeValue &)) &STEPCAFControl_GDTProperty::GetTolValueType, "None", py::arg("theType"));
cls_STEPCAFControl_GDTProperty.def_static("GetDimTypeName_", (opencascade::handle<TCollection_HAsciiString> (*)(const XCAFDimTolObjects_DimensionType)) &STEPCAFControl_GDTProperty::GetDimTypeName, "None", py::arg("theType"));
cls_STEPCAFControl_GDTProperty.def_static("GetDimQualifierName_", (opencascade::handle<TCollection_HAsciiString> (*)(const XCAFDimTolObjects_DimensionQualifier)) &STEPCAFControl_GDTProperty::GetDimQualifierName, "None", py::arg("theQualifier"));
cls_STEPCAFControl_GDTProperty.def_static("GetDimModifierName_", (opencascade::handle<TCollection_HAsciiString> (*)(const XCAFDimTolObjects_DimensionModif)) &STEPCAFControl_GDTProperty::GetDimModifierName, "None", py::arg("theModifier"));
cls_STEPCAFControl_GDTProperty.def_static("GetLimitsAndFits_", (opencascade::handle<StepShape_LimitsAndFits> (*)(Standard_Boolean, XCAFDimTolObjects_DimensionFormVariance, XCAFDimTolObjects_DimensionGrade)) &STEPCAFControl_GDTProperty::GetLimitsAndFits, "None", py::arg("theHole"), py::arg("theFormVariance"), py::arg("theGrade"));
cls_STEPCAFControl_GDTProperty.def_static("GetDatumTargetName_", (opencascade::handle<TCollection_HAsciiString> (*)(const XCAFDimTolObjects_DatumTargetType)) &STEPCAFControl_GDTProperty::GetDatumTargetName, "None", py::arg("theDatumType"));
cls_STEPCAFControl_GDTProperty.def_static("IsDimensionalLocation_", (Standard_Boolean (*)(const XCAFDimTolObjects_DimensionType)) &STEPCAFControl_GDTProperty::IsDimensionalLocation, "None", py::arg("theType"));
cls_STEPCAFControl_GDTProperty.def_static("IsDimensionalSize_", (Standard_Boolean (*)(const XCAFDimTolObjects_DimensionType)) &STEPCAFControl_GDTProperty::IsDimensionalSize, "None", py::arg("theType"));
cls_STEPCAFControl_GDTProperty.def_static("GetGeomToleranceType_", (StepDimTol_GeometricToleranceType (*)(const XCAFDimTolObjects_GeomToleranceType)) &STEPCAFControl_GDTProperty::GetGeomToleranceType, "None", py::arg("theType"));
cls_STEPCAFControl_GDTProperty.def_static("GetGeomToleranceType_", (XCAFDimTolObjects_GeomToleranceType (*)(const StepDimTol_GeometricToleranceType)) &STEPCAFControl_GDTProperty::GetGeomToleranceType, "None", py::arg("theType"));
cls_STEPCAFControl_GDTProperty.def_static("GetGeomTolerance_", (opencascade::handle<StepDimTol_GeometricTolerance> (*)(const XCAFDimTolObjects_GeomToleranceType)) &STEPCAFControl_GDTProperty::GetGeomTolerance, "None", py::arg("theType"));
cls_STEPCAFControl_GDTProperty.def_static("GetGeomToleranceModifier_", (StepDimTol_GeometricToleranceModifier (*)(const XCAFDimTolObjects_GeomToleranceModif)) &STEPCAFControl_GDTProperty::GetGeomToleranceModifier, "None", py::arg("theModifier"));
cls_STEPCAFControl_GDTProperty.def_static("GetDatumRefModifiers_", (opencascade::handle<StepDimTol_HArray1OfDatumReferenceModifier> (*)(const XCAFDimTolObjects_DatumModifiersSequence, const XCAFDimTolObjects_DatumModifWithValue, const Standard_Real, const StepBasic_Unit)) &STEPCAFControl_GDTProperty::GetDatumRefModifiers, "None", py::arg("theModifiers"), py::arg("theModifWithVal"), py::arg("theValue"), py::arg("theUnit"));
cls_STEPCAFControl_GDTProperty.def_static("GetTessellation_", (opencascade::handle<StepVisual_TessellatedGeometricSet> (*)(const TopoDS_Shape)) &STEPCAFControl_GDTProperty::GetTessellation, "None", py::arg("theShape"));

// Enums

}