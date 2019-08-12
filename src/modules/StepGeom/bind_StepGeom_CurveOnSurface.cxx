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
#include <StepGeom_Pcurve.hxx>
#include <StepGeom_SurfaceCurve.hxx>
#include <StepGeom_CompositeCurveOnSurface.hxx>
#include <StepGeom_CurveOnSurface.hxx>

void bind_StepGeom_CurveOnSurface(py::module &mod){

py::class_<StepGeom_CurveOnSurface, std::unique_ptr<StepGeom_CurveOnSurface, Deleter<StepGeom_CurveOnSurface>>, StepData_SelectType> cls_StepGeom_CurveOnSurface(mod, "StepGeom_CurveOnSurface", "None");

// Constructors
cls_StepGeom_CurveOnSurface.def(py::init<>());

// Fields

// Methods
// cls_StepGeom_CurveOnSurface.def_static("operator new_", (void * (*)(size_t)) &StepGeom_CurveOnSurface::operator new, "None", py::arg("theSize"));
// cls_StepGeom_CurveOnSurface.def_static("operator delete_", (void (*)(void *)) &StepGeom_CurveOnSurface::operator delete, "None", py::arg("theAddress"));
// cls_StepGeom_CurveOnSurface.def_static("operator new[]_", (void * (*)(size_t)) &StepGeom_CurveOnSurface::operator new[], "None", py::arg("theSize"));
// cls_StepGeom_CurveOnSurface.def_static("operator delete[]_", (void (*)(void *)) &StepGeom_CurveOnSurface::operator delete[], "None", py::arg("theAddress"));
// cls_StepGeom_CurveOnSurface.def_static("operator new_", (void * (*)(size_t, void *)) &StepGeom_CurveOnSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepGeom_CurveOnSurface.def_static("operator delete_", (void (*)(void *, void *)) &StepGeom_CurveOnSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_StepGeom_CurveOnSurface.def("CaseNum", (Standard_Integer (StepGeom_CurveOnSurface::*)(const opencascade::handle<Standard_Transient> &) const) &StepGeom_CurveOnSurface::CaseNum, "Recognizes a CurveOnSurface Kind Entity that is : 1 -> Pcurve 2 -> SurfaceCurve 3 -> CompositeCurveOnSurface 0 else", py::arg("ent"));
cls_StepGeom_CurveOnSurface.def("Pcurve", (opencascade::handle<StepGeom_Pcurve> (StepGeom_CurveOnSurface::*)() const) &StepGeom_CurveOnSurface::Pcurve, "returns Value as a Pcurve (Null if another type)");
cls_StepGeom_CurveOnSurface.def("SurfaceCurve", (opencascade::handle<StepGeom_SurfaceCurve> (StepGeom_CurveOnSurface::*)() const) &StepGeom_CurveOnSurface::SurfaceCurve, "returns Value as a SurfaceCurve (Null if another type)");
cls_StepGeom_CurveOnSurface.def("CompositeCurveOnSurface", (opencascade::handle<StepGeom_CompositeCurveOnSurface> (StepGeom_CurveOnSurface::*)() const) &StepGeom_CurveOnSurface::CompositeCurveOnSurface, "returns Value as a CompositeCurveOnSurface (Null if another type)");

// Enums

}