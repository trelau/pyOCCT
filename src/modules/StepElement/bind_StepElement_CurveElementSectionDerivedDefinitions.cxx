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
#include <StepElement_CurveElementSectionDefinition.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <StepElement_HArray1OfMeasureOrUnspecifiedValue.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <StepElement_MeasureOrUnspecifiedValue.hxx>
#include <StepElement_CurveElementSectionDerivedDefinitions.hxx>
#include <Standard_Type.hxx>

void bind_StepElement_CurveElementSectionDerivedDefinitions(py::module &mod){

py::class_<StepElement_CurveElementSectionDerivedDefinitions, opencascade::handle<StepElement_CurveElementSectionDerivedDefinitions>, StepElement_CurveElementSectionDefinition> cls_StepElement_CurveElementSectionDerivedDefinitions(mod, "StepElement_CurveElementSectionDerivedDefinitions", "Representation of STEP entity CurveElementSectionDerivedDefinitions");

// Constructors
cls_StepElement_CurveElementSectionDerivedDefinitions.def(py::init<>());

// Fields

// Methods
cls_StepElement_CurveElementSectionDerivedDefinitions.def("Init", (void (StepElement_CurveElementSectionDerivedDefinitions::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const Standard_Real, const opencascade::handle<StepElement_HArray1OfMeasureOrUnspecifiedValue> &, const opencascade::handle<TColStd_HArray1OfReal> &, const Standard_Real, const StepElement_MeasureOrUnspecifiedValue &, const opencascade::handle<StepElement_HArray1OfMeasureOrUnspecifiedValue> &, const opencascade::handle<StepElement_HArray1OfMeasureOrUnspecifiedValue> &, const opencascade::handle<StepElement_HArray1OfMeasureOrUnspecifiedValue> &, const StepElement_MeasureOrUnspecifiedValue &, const StepElement_MeasureOrUnspecifiedValue &)) &StepElement_CurveElementSectionDerivedDefinitions::Init, "Initialize all fields (own and inherited)", py::arg("aCurveElementSectionDefinition_Description"), py::arg("aCurveElementSectionDefinition_SectionAngle"), py::arg("aCrossSectionalArea"), py::arg("aShearArea"), py::arg("aSecondMomentOfArea"), py::arg("aTorsionalConstant"), py::arg("aWarpingConstant"), py::arg("aLocationOfCentroid"), py::arg("aLocationOfShearCentre"), py::arg("aLocationOfNonStructuralMass"), py::arg("aNonStructuralMass"), py::arg("aPolarMoment"));
cls_StepElement_CurveElementSectionDerivedDefinitions.def("CrossSectionalArea", (Standard_Real (StepElement_CurveElementSectionDerivedDefinitions::*)() const) &StepElement_CurveElementSectionDerivedDefinitions::CrossSectionalArea, "Returns field CrossSectionalArea");
cls_StepElement_CurveElementSectionDerivedDefinitions.def("SetCrossSectionalArea", (void (StepElement_CurveElementSectionDerivedDefinitions::*)(const Standard_Real)) &StepElement_CurveElementSectionDerivedDefinitions::SetCrossSectionalArea, "Set field CrossSectionalArea", py::arg("CrossSectionalArea"));
cls_StepElement_CurveElementSectionDerivedDefinitions.def("ShearArea", (opencascade::handle<StepElement_HArray1OfMeasureOrUnspecifiedValue> (StepElement_CurveElementSectionDerivedDefinitions::*)() const) &StepElement_CurveElementSectionDerivedDefinitions::ShearArea, "Returns field ShearArea");
cls_StepElement_CurveElementSectionDerivedDefinitions.def("SetShearArea", (void (StepElement_CurveElementSectionDerivedDefinitions::*)(const opencascade::handle<StepElement_HArray1OfMeasureOrUnspecifiedValue> &)) &StepElement_CurveElementSectionDerivedDefinitions::SetShearArea, "Set field ShearArea", py::arg("ShearArea"));
cls_StepElement_CurveElementSectionDerivedDefinitions.def("SecondMomentOfArea", (opencascade::handle<TColStd_HArray1OfReal> (StepElement_CurveElementSectionDerivedDefinitions::*)() const) &StepElement_CurveElementSectionDerivedDefinitions::SecondMomentOfArea, "Returns field SecondMomentOfArea");
cls_StepElement_CurveElementSectionDerivedDefinitions.def("SetSecondMomentOfArea", (void (StepElement_CurveElementSectionDerivedDefinitions::*)(const opencascade::handle<TColStd_HArray1OfReal> &)) &StepElement_CurveElementSectionDerivedDefinitions::SetSecondMomentOfArea, "Set field SecondMomentOfArea", py::arg("SecondMomentOfArea"));
cls_StepElement_CurveElementSectionDerivedDefinitions.def("TorsionalConstant", (Standard_Real (StepElement_CurveElementSectionDerivedDefinitions::*)() const) &StepElement_CurveElementSectionDerivedDefinitions::TorsionalConstant, "Returns field TorsionalConstant");
cls_StepElement_CurveElementSectionDerivedDefinitions.def("SetTorsionalConstant", (void (StepElement_CurveElementSectionDerivedDefinitions::*)(const Standard_Real)) &StepElement_CurveElementSectionDerivedDefinitions::SetTorsionalConstant, "Set field TorsionalConstant", py::arg("TorsionalConstant"));
cls_StepElement_CurveElementSectionDerivedDefinitions.def("WarpingConstant", (StepElement_MeasureOrUnspecifiedValue (StepElement_CurveElementSectionDerivedDefinitions::*)() const) &StepElement_CurveElementSectionDerivedDefinitions::WarpingConstant, "Returns field WarpingConstant");
cls_StepElement_CurveElementSectionDerivedDefinitions.def("SetWarpingConstant", (void (StepElement_CurveElementSectionDerivedDefinitions::*)(const StepElement_MeasureOrUnspecifiedValue &)) &StepElement_CurveElementSectionDerivedDefinitions::SetWarpingConstant, "Set field WarpingConstant", py::arg("WarpingConstant"));
cls_StepElement_CurveElementSectionDerivedDefinitions.def("LocationOfCentroid", (opencascade::handle<StepElement_HArray1OfMeasureOrUnspecifiedValue> (StepElement_CurveElementSectionDerivedDefinitions::*)() const) &StepElement_CurveElementSectionDerivedDefinitions::LocationOfCentroid, "Returns field LocationOfCentroid");
cls_StepElement_CurveElementSectionDerivedDefinitions.def("SetLocationOfCentroid", (void (StepElement_CurveElementSectionDerivedDefinitions::*)(const opencascade::handle<StepElement_HArray1OfMeasureOrUnspecifiedValue> &)) &StepElement_CurveElementSectionDerivedDefinitions::SetLocationOfCentroid, "Set field LocationOfCentroid", py::arg("LocationOfCentroid"));
cls_StepElement_CurveElementSectionDerivedDefinitions.def("LocationOfShearCentre", (opencascade::handle<StepElement_HArray1OfMeasureOrUnspecifiedValue> (StepElement_CurveElementSectionDerivedDefinitions::*)() const) &StepElement_CurveElementSectionDerivedDefinitions::LocationOfShearCentre, "Returns field LocationOfShearCentre");
cls_StepElement_CurveElementSectionDerivedDefinitions.def("SetLocationOfShearCentre", (void (StepElement_CurveElementSectionDerivedDefinitions::*)(const opencascade::handle<StepElement_HArray1OfMeasureOrUnspecifiedValue> &)) &StepElement_CurveElementSectionDerivedDefinitions::SetLocationOfShearCentre, "Set field LocationOfShearCentre", py::arg("LocationOfShearCentre"));
cls_StepElement_CurveElementSectionDerivedDefinitions.def("LocationOfNonStructuralMass", (opencascade::handle<StepElement_HArray1OfMeasureOrUnspecifiedValue> (StepElement_CurveElementSectionDerivedDefinitions::*)() const) &StepElement_CurveElementSectionDerivedDefinitions::LocationOfNonStructuralMass, "Returns field LocationOfNonStructuralMass");
cls_StepElement_CurveElementSectionDerivedDefinitions.def("SetLocationOfNonStructuralMass", (void (StepElement_CurveElementSectionDerivedDefinitions::*)(const opencascade::handle<StepElement_HArray1OfMeasureOrUnspecifiedValue> &)) &StepElement_CurveElementSectionDerivedDefinitions::SetLocationOfNonStructuralMass, "Set field LocationOfNonStructuralMass", py::arg("LocationOfNonStructuralMass"));
cls_StepElement_CurveElementSectionDerivedDefinitions.def("NonStructuralMass", (StepElement_MeasureOrUnspecifiedValue (StepElement_CurveElementSectionDerivedDefinitions::*)() const) &StepElement_CurveElementSectionDerivedDefinitions::NonStructuralMass, "Returns field NonStructuralMass");
cls_StepElement_CurveElementSectionDerivedDefinitions.def("SetNonStructuralMass", (void (StepElement_CurveElementSectionDerivedDefinitions::*)(const StepElement_MeasureOrUnspecifiedValue &)) &StepElement_CurveElementSectionDerivedDefinitions::SetNonStructuralMass, "Set field NonStructuralMass", py::arg("NonStructuralMass"));
cls_StepElement_CurveElementSectionDerivedDefinitions.def("PolarMoment", (StepElement_MeasureOrUnspecifiedValue (StepElement_CurveElementSectionDerivedDefinitions::*)() const) &StepElement_CurveElementSectionDerivedDefinitions::PolarMoment, "Returns field PolarMoment");
cls_StepElement_CurveElementSectionDerivedDefinitions.def("SetPolarMoment", (void (StepElement_CurveElementSectionDerivedDefinitions::*)(const StepElement_MeasureOrUnspecifiedValue &)) &StepElement_CurveElementSectionDerivedDefinitions::SetPolarMoment, "Set field PolarMoment", py::arg("PolarMoment"));
cls_StepElement_CurveElementSectionDerivedDefinitions.def_static("get_type_name_", (const char * (*)()) &StepElement_CurveElementSectionDerivedDefinitions::get_type_name, "None");
cls_StepElement_CurveElementSectionDerivedDefinitions.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepElement_CurveElementSectionDerivedDefinitions::get_type_descriptor, "None");
cls_StepElement_CurveElementSectionDerivedDefinitions.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepElement_CurveElementSectionDerivedDefinitions::*)() const) &StepElement_CurveElementSectionDerivedDefinitions::DynamicType, "None");

// Enums

}