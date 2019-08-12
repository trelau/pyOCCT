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
#include <StepGeom_HArray2OfSurfacePatch.hxx>
#include <StepGeom_SurfacePatch.hxx>
#include <Standard_TypeDef.hxx>
#include <StepGeom_RectangularCompositeSurface.hxx>
#include <Standard_Type.hxx>

void bind_StepGeom_RectangularCompositeSurface(py::module &mod){

py::class_<StepGeom_RectangularCompositeSurface, opencascade::handle<StepGeom_RectangularCompositeSurface>, StepGeom_BoundedSurface> cls_StepGeom_RectangularCompositeSurface(mod, "StepGeom_RectangularCompositeSurface", "None");

// Constructors
cls_StepGeom_RectangularCompositeSurface.def(py::init<>());

// Fields

// Methods
cls_StepGeom_RectangularCompositeSurface.def("Init", (void (StepGeom_RectangularCompositeSurface::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_HArray2OfSurfacePatch> &)) &StepGeom_RectangularCompositeSurface::Init, "None", py::arg("aName"), py::arg("aSegments"));
cls_StepGeom_RectangularCompositeSurface.def("SetSegments", (void (StepGeom_RectangularCompositeSurface::*)(const opencascade::handle<StepGeom_HArray2OfSurfacePatch> &)) &StepGeom_RectangularCompositeSurface::SetSegments, "None", py::arg("aSegments"));
cls_StepGeom_RectangularCompositeSurface.def("Segments", (opencascade::handle<StepGeom_HArray2OfSurfacePatch> (StepGeom_RectangularCompositeSurface::*)() const) &StepGeom_RectangularCompositeSurface::Segments, "None");
cls_StepGeom_RectangularCompositeSurface.def("SegmentsValue", (opencascade::handle<StepGeom_SurfacePatch> (StepGeom_RectangularCompositeSurface::*)(const Standard_Integer, const Standard_Integer) const) &StepGeom_RectangularCompositeSurface::SegmentsValue, "None", py::arg("num1"), py::arg("num2"));
cls_StepGeom_RectangularCompositeSurface.def("NbSegmentsI", (Standard_Integer (StepGeom_RectangularCompositeSurface::*)() const) &StepGeom_RectangularCompositeSurface::NbSegmentsI, "None");
cls_StepGeom_RectangularCompositeSurface.def("NbSegmentsJ", (Standard_Integer (StepGeom_RectangularCompositeSurface::*)() const) &StepGeom_RectangularCompositeSurface::NbSegmentsJ, "None");
cls_StepGeom_RectangularCompositeSurface.def_static("get_type_name_", (const char * (*)()) &StepGeom_RectangularCompositeSurface::get_type_name, "None");
cls_StepGeom_RectangularCompositeSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepGeom_RectangularCompositeSurface::get_type_descriptor, "None");
cls_StepGeom_RectangularCompositeSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepGeom_RectangularCompositeSurface::*)() const) &StepGeom_RectangularCompositeSurface::DynamicType, "None");

// Enums

}