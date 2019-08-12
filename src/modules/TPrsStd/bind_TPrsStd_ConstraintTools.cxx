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
#include <TDataXtd_Constraint.hxx>
#include <AIS_InteractiveObject.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_ExtendedString.hxx>
#include <TopoDS_Shape.hxx>
#include <Geom_Geometry.hxx>
#include <TPrsStd_ConstraintTools.hxx>

void bind_TPrsStd_ConstraintTools(py::module &mod){

py::class_<TPrsStd_ConstraintTools, std::unique_ptr<TPrsStd_ConstraintTools, Deleter<TPrsStd_ConstraintTools>>> cls_TPrsStd_ConstraintTools(mod, "TPrsStd_ConstraintTools", "None");

// Constructors

// Fields

// Methods
// cls_TPrsStd_ConstraintTools.def_static("operator new_", (void * (*)(size_t)) &TPrsStd_ConstraintTools::operator new, "None", py::arg("theSize"));
// cls_TPrsStd_ConstraintTools.def_static("operator delete_", (void (*)(void *)) &TPrsStd_ConstraintTools::operator delete, "None", py::arg("theAddress"));
// cls_TPrsStd_ConstraintTools.def_static("operator new[]_", (void * (*)(size_t)) &TPrsStd_ConstraintTools::operator new[], "None", py::arg("theSize"));
// cls_TPrsStd_ConstraintTools.def_static("operator delete[]_", (void (*)(void *)) &TPrsStd_ConstraintTools::operator delete[], "None", py::arg("theAddress"));
// cls_TPrsStd_ConstraintTools.def_static("operator new_", (void * (*)(size_t, void *)) &TPrsStd_ConstraintTools::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TPrsStd_ConstraintTools.def_static("operator delete_", (void (*)(void *, void *)) &TPrsStd_ConstraintTools::operator delete, "None", py::arg(""), py::arg(""));
cls_TPrsStd_ConstraintTools.def_static("UpdateOnlyValue_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, const opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::UpdateOnlyValue, "None", py::arg("aConst"), py::arg("anAIS"));
cls_TPrsStd_ConstraintTools.def_static("ComputeDistance_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeDistance, "None", py::arg("aConst"), py::arg("anAIS"));
cls_TPrsStd_ConstraintTools.def_static("ComputeParallel_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeParallel, "None", py::arg("aConst"), py::arg("anAIS"));
cls_TPrsStd_ConstraintTools.def_static("ComputeTangent_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeTangent, "None", py::arg("aConst"), py::arg("anAIS"));
cls_TPrsStd_ConstraintTools.def_static("ComputePerpendicular_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputePerpendicular, "None", py::arg("aConst"), py::arg("anAIS"));
cls_TPrsStd_ConstraintTools.def_static("ComputeConcentric_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeConcentric, "None", py::arg("aConst"), py::arg("anAIS"));
cls_TPrsStd_ConstraintTools.def_static("ComputeSymmetry_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeSymmetry, "None", py::arg("aConst"), py::arg("anAIS"));
cls_TPrsStd_ConstraintTools.def_static("ComputeMidPoint_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeMidPoint, "None", py::arg("aConst"), py::arg("anAIS"));
cls_TPrsStd_ConstraintTools.def_static("ComputeAngle_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeAngle, "None", py::arg("aConst"), py::arg("anAIS"));
cls_TPrsStd_ConstraintTools.def_static("ComputeRadius_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeRadius, "None", py::arg("aConst"), py::arg("anAIS"));
cls_TPrsStd_ConstraintTools.def_static("ComputeMinRadius_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeMinRadius, "None", py::arg("aConst"), py::arg("anAIS"));
cls_TPrsStd_ConstraintTools.def_static("ComputeMaxRadius_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeMaxRadius, "None", py::arg("aConst"), py::arg("anAIS"));
cls_TPrsStd_ConstraintTools.def_static("ComputeEqualDistance_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeEqualDistance, "None", py::arg("aConst"), py::arg("anAIS"));
cls_TPrsStd_ConstraintTools.def_static("ComputeEqualRadius_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeEqualRadius, "None", py::arg("aConst"), py::arg("anAIS"));
cls_TPrsStd_ConstraintTools.def_static("ComputeFix_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeFix, "None", py::arg("aConst"), py::arg("anAIS"));
cls_TPrsStd_ConstraintTools.def_static("ComputeDiameter_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeDiameter, "None", py::arg("aConst"), py::arg("anAIS"));
cls_TPrsStd_ConstraintTools.def_static("ComputeOffset_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeOffset, "None", py::arg("aConst"), py::arg("anAIS"));
cls_TPrsStd_ConstraintTools.def_static("ComputePlacement_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputePlacement, "None", py::arg("aConst"), py::arg("anAIS"));
cls_TPrsStd_ConstraintTools.def_static("ComputeCoincident_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeCoincident, "None", py::arg("aConst"), py::arg("anAIS"));
cls_TPrsStd_ConstraintTools.def_static("ComputeRound_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeRound, "None", py::arg("aConst"), py::arg("anAIS"));
cls_TPrsStd_ConstraintTools.def_static("ComputeOthers_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeOthers, "None", py::arg("aConst"), py::arg("anAIS"));
cls_TPrsStd_ConstraintTools.def_static("ComputeTextAndValue_", [](const opencascade::handle<TDataXtd_Constraint> & aConst, Standard_Real & aValue, TCollection_ExtendedString & aText, const Standard_Boolean anIsAngle){ TPrsStd_ConstraintTools::ComputeTextAndValue(aConst, aValue, aText, anIsAngle); return aValue; }, "None", py::arg("aConst"), py::arg("aValue"), py::arg("aText"), py::arg("anIsAngle"));
cls_TPrsStd_ConstraintTools.def_static("ComputeAngleForOneFace_", (void (*)(const opencascade::handle<TDataXtd_Constraint> &, opencascade::handle<AIS_InteractiveObject> &)) &TPrsStd_ConstraintTools::ComputeAngleForOneFace, "None", py::arg("aConst"), py::arg("anAIS"));

// Enums

}