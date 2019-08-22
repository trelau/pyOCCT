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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx.hxx>
#include <StepRepr_GlobalUnitAssignedContext.hxx>
#include <StepBasic_NamedUnit.hxx>
#include <StepRepr_GlobalUncertaintyAssignedContext.hxx>
#include <StepBasic_SiPrefix.hxx>
#include <StepBasic_SiUnit.hxx>
#include <STEPConstruct_UnitContext.hxx>

void bind_STEPConstruct_UnitContext(py::module &mod){

py::class_<STEPConstruct_UnitContext> cls_STEPConstruct_UnitContext(mod, "STEPConstruct_UnitContext", "Tool for creation (encoding) and decoding (for writing and reading accordingly) context defining units and tolerances (uncerntanties)");

// Constructors
cls_STEPConstruct_UnitContext.def(py::init<>());

// Fields

// Methods
// cls_STEPConstruct_UnitContext.def_static("operator new_", (void * (*)(size_t)) &STEPConstruct_UnitContext::operator new, "None", py::arg("theSize"));
// cls_STEPConstruct_UnitContext.def_static("operator delete_", (void (*)(void *)) &STEPConstruct_UnitContext::operator delete, "None", py::arg("theAddress"));
// cls_STEPConstruct_UnitContext.def_static("operator new[]_", (void * (*)(size_t)) &STEPConstruct_UnitContext::operator new[], "None", py::arg("theSize"));
// cls_STEPConstruct_UnitContext.def_static("operator delete[]_", (void (*)(void *)) &STEPConstruct_UnitContext::operator delete[], "None", py::arg("theAddress"));
// cls_STEPConstruct_UnitContext.def_static("operator new_", (void * (*)(size_t, void *)) &STEPConstruct_UnitContext::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPConstruct_UnitContext.def_static("operator delete_", (void (*)(void *, void *)) &STEPConstruct_UnitContext::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPConstruct_UnitContext.def("Init", (void (STEPConstruct_UnitContext::*)(const Standard_Real)) &STEPConstruct_UnitContext::Init, "Creates new context (units are MM and radians, uncertainty equal to Tol3d)", py::arg("Tol3d"));
cls_STEPConstruct_UnitContext.def("IsDone", (Standard_Boolean (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::IsDone, "Returns True if Init was called successfully");
cls_STEPConstruct_UnitContext.def("Value", (opencascade::handle<StepGeom_GeomRepContextAndGlobUnitAssCtxAndGlobUncertaintyAssCtx> (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::Value, "Returns context (or Null if not done)");
cls_STEPConstruct_UnitContext.def("ComputeFactors", (Standard_Integer (STEPConstruct_UnitContext::*)(const opencascade::handle<StepRepr_GlobalUnitAssignedContext> &)) &STEPConstruct_UnitContext::ComputeFactors, "Computes the length, plane angle and solid angle conversion factor . Returns a status, 0 if OK", py::arg("aContext"));
cls_STEPConstruct_UnitContext.def("ComputeFactors", (Standard_Integer (STEPConstruct_UnitContext::*)(const opencascade::handle<StepBasic_NamedUnit> &)) &STEPConstruct_UnitContext::ComputeFactors, "None", py::arg("aUnit"));
cls_STEPConstruct_UnitContext.def("ComputeTolerance", (Standard_Integer (STEPConstruct_UnitContext::*)(const opencascade::handle<StepRepr_GlobalUncertaintyAssignedContext> &)) &STEPConstruct_UnitContext::ComputeTolerance, "Computes the uncertainty value (for length)", py::arg("aContext"));
cls_STEPConstruct_UnitContext.def("LengthFactor", (Standard_Real (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::LengthFactor, "Returns the lengthFactor");
cls_STEPConstruct_UnitContext.def("PlaneAngleFactor", (Standard_Real (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::PlaneAngleFactor, "Returns the planeAngleFactor");
cls_STEPConstruct_UnitContext.def("SolidAngleFactor", (Standard_Real (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::SolidAngleFactor, "Returns the solidAngleFactor");
cls_STEPConstruct_UnitContext.def("Uncertainty", (Standard_Real (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::Uncertainty, "Returns the Uncertainty value (for length) It has been converted with LengthFactor");
cls_STEPConstruct_UnitContext.def("AreaFactor", (Standard_Real (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::AreaFactor, "Returns the areaFactor");
cls_STEPConstruct_UnitContext.def("VolumeFactor", (Standard_Real (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::VolumeFactor, "Returns the volumeFactor");
cls_STEPConstruct_UnitContext.def("HasUncertainty", (Standard_Boolean (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::HasUncertainty, "Tells if a Uncertainty (for length) is recorded");
cls_STEPConstruct_UnitContext.def("LengthDone", (Standard_Boolean (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::LengthDone, "Returns true if ComputeFactors has calculated a LengthFactor");
cls_STEPConstruct_UnitContext.def("PlaneAngleDone", (Standard_Boolean (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::PlaneAngleDone, "Returns true if ComputeFactors has calculated a PlaneAngleFactor");
cls_STEPConstruct_UnitContext.def("SolidAngleDone", (Standard_Boolean (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::SolidAngleDone, "Returns true if ComputeFactors has calculated a SolidAngleFactor");
cls_STEPConstruct_UnitContext.def("AreaDone", (Standard_Boolean (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::AreaDone, "Returns true if areaFactor is computed");
cls_STEPConstruct_UnitContext.def("VolumeDone", (Standard_Boolean (STEPConstruct_UnitContext::*)() const) &STEPConstruct_UnitContext::VolumeDone, "Returns true if volumeFactor is computed");
cls_STEPConstruct_UnitContext.def("StatusMessage", (Standard_CString (STEPConstruct_UnitContext::*)(const Standard_Integer) const) &STEPConstruct_UnitContext::StatusMessage, "Returns a message for a given status (0 - empty) This message can then be added as warning for transfer", py::arg("status"));
cls_STEPConstruct_UnitContext.def_static("ConvertSiPrefix_", (Standard_Real (*)(const StepBasic_SiPrefix)) &STEPConstruct_UnitContext::ConvertSiPrefix, "Convert SI prefix defined by enumertaion to corresponding real factor (e.g. 1e6 for mega)", py::arg("aPrefix"));

// Enums

}