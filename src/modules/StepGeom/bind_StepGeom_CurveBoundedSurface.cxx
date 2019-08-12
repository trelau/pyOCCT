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
#include <StepGeom_BoundedSurface.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepGeom_Surface.hxx>
#include <StepGeom_HArray1OfSurfaceBoundary.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_CurveBoundedSurface.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_CurveBoundedSurface(py::module &mod){

py::class_<StepGeom_CurveBoundedSurface, opencascade::handle<StepGeom_CurveBoundedSurface>, StepGeom_BoundedSurface> cls_StepGeom_CurveBoundedSurface(mod, "StepGeom_CurveBoundedSurface", "Representation of STEP entity CurveBoundedSurface");

// Constructors
cls_StepGeom_CurveBoundedSurface.def(py::init<>());

// Fields

// Methods
cls_StepGeom_CurveBoundedSurface.def("Init", (void (StepGeom_CurveBoundedSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Surface> &, const opencascade::handle<StepGeom_HArray1OfSurfaceBoundary> &, const Standard_Boolean)) &StepGeom_CurveBoundedSurface::Init, "Initialize all fields (own and inherited)", py::arg("aRepresentationItem_Name"), py::arg("aBasisSurface"), py::arg("aBoundaries"), py::arg("aImplicitOuter"));
cls_StepGeom_CurveBoundedSurface.def("BasisSurface", (opencascade::handle<StepGeom_Surface> (StepGeom_CurveBoundedSurface::*)() const) &StepGeom_CurveBoundedSurface::BasisSurface, "Returns field BasisSurface");
cls_StepGeom_CurveBoundedSurface.def("SetBasisSurface", (void (StepGeom_CurveBoundedSurface::*)(const opencascade::handle<StepGeom_Surface> &)) &StepGeom_CurveBoundedSurface::SetBasisSurface, "Set field BasisSurface", py::arg("BasisSurface"));
cls_StepGeom_CurveBoundedSurface.def("Boundaries", (opencascade::handle<StepGeom_HArray1OfSurfaceBoundary> (StepGeom_CurveBoundedSurface::*)() const) &StepGeom_CurveBoundedSurface::Boundaries, "Returns field Boundaries");
cls_StepGeom_CurveBoundedSurface.def("SetBoundaries", (void (StepGeom_CurveBoundedSurface::*)(const opencascade::handle<StepGeom_HArray1OfSurfaceBoundary> &)) &StepGeom_CurveBoundedSurface::SetBoundaries, "Set field Boundaries", py::arg("Boundaries"));
cls_StepGeom_CurveBoundedSurface.def("ImplicitOuter", (Standard_Boolean (StepGeom_CurveBoundedSurface::*)() const) &StepGeom_CurveBoundedSurface::ImplicitOuter, "Returns field ImplicitOuter");
cls_StepGeom_CurveBoundedSurface.def("SetImplicitOuter", (void (StepGeom_CurveBoundedSurface::*)(const Standard_Boolean)) &StepGeom_CurveBoundedSurface::SetImplicitOuter, "Set field ImplicitOuter", py::arg("ImplicitOuter"));
cls_StepGeom_CurveBoundedSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_CurveBoundedSurface::get_type_name, "None");
cls_StepGeom_CurveBoundedSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_CurveBoundedSurface::get_type_descriptor, "None");
cls_StepGeom_CurveBoundedSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_CurveBoundedSurface::*)() const) &StepGeom_CurveBoundedSurface::DynamicType, "None");

// Enums

}