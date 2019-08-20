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
#include <StepData_SelectType.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Transient.hxx>
#include <StepGeom_BoundaryCurve.hxx>
#include <StepGeom_DegeneratePcurve.hxx>
#include <StepGeom_SurfaceBoundary.hxx>

void bind_StepGeom_SurfaceBoundary(py::module &mod){

py::class_<StepGeom_SurfaceBoundary, std::unique_ptr<StepGeom_SurfaceBoundary>, StepData_SelectType> cls_StepGeom_SurfaceBoundary(mod, "StepGeom_SurfaceBoundary", "Representation of STEP SELECT type SurfaceBoundary");

// Constructors
cls_StepGeom_SurfaceBoundary.def(py::init<>());

// Fields

// Methods
// cls_StepGeom_SurfaceBoundary.def_static("operator new_", (void * (*)(size_t)) &StepGeom_SurfaceBoundary::operator new, "None", py::arg("theSize"));
// cls_StepGeom_SurfaceBoundary.def_static("operator delete_", (void (*)(void *)) &StepGeom_SurfaceBoundary::operator delete, "None", py::arg("theAddress"));
// cls_StepGeom_SurfaceBoundary.def_static("operator new[]_", (void * (*)(size_t)) &StepGeom_SurfaceBoundary::operator new[], "None", py::arg("theSize"));
// cls_StepGeom_SurfaceBoundary.def_static("operator delete[]_", (void (*)(void *)) &StepGeom_SurfaceBoundary::operator delete[], "None", py::arg("theAddress"));
// cls_StepGeom_SurfaceBoundary.def_static("operator new_", (void * (*)(size_t, void *)) &StepGeom_SurfaceBoundary::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepGeom_SurfaceBoundary.def_static("operator delete_", (void (*)(void *, void *)) &StepGeom_SurfaceBoundary::operator delete, "None", py::arg(""), py::arg(""));
cls_StepGeom_SurfaceBoundary.def("CaseNum", (Standard_Integer (StepGeom_SurfaceBoundary::*)(const opencascade::handle<Standard_Transient> &) const) &StepGeom_SurfaceBoundary::CaseNum, "Recognizes a kind of SurfaceBoundary select type 1 -> BoundaryCurve from StepGeom 2 -> DegeneratePcurve from StepGeom 0 else", py::arg("ent"));
cls_StepGeom_SurfaceBoundary.def("BoundaryCurve", (opencascade::handle<StepGeom_BoundaryCurve> (StepGeom_SurfaceBoundary::*)() const) &StepGeom_SurfaceBoundary::BoundaryCurve, "Returns Value as BoundaryCurve (or Null if another type)");
cls_StepGeom_SurfaceBoundary.def("DegeneratePcurve", (opencascade::handle<StepGeom_DegeneratePcurve> (StepGeom_SurfaceBoundary::*)() const) &StepGeom_SurfaceBoundary::DegeneratePcurve, "Returns Value as DegeneratePcurve (or Null if another type)");

// Enums

}