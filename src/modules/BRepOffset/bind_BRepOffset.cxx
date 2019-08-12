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
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepOffset_Status.hxx>
#include <TopoDS_Face.hxx>
#include <BRepOffset.hxx>

void bind_BRepOffset(py::module &mod){

py::class_<BRepOffset, std::unique_ptr<BRepOffset, Deleter<BRepOffset>>> cls_BRepOffset(mod, "BRepOffset", "Auxiliary tools for offset algorithms");

// Constructors

// Fields

// Methods
cls_BRepOffset.def_static("Surface_", [](const opencascade::handle<Geom_Surface> & a0, const Standard_Real a1, BRepOffset_Status & a2) -> opencascade::handle<Geom_Surface> { return BRepOffset::Surface(a0, a1, a2); });
cls_BRepOffset.def_static("Surface_", (opencascade::handle<Geom_Surface> (*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, BRepOffset_Status &, Standard_Boolean)) &BRepOffset::Surface, "returns the Offset surface computed from the surface <Surface> at an OffsetDistance <Offset>.", py::arg("Surface"), py::arg("Offset"), py::arg("theStatus"), py::arg("allowC0"));
cls_BRepOffset.def_static("CollapseSingularities_", (opencascade::handle<Geom_Surface> (*)(const opencascade::handle<Geom_Surface> &, const TopoDS_Face &, Standard_Real)) &BRepOffset::CollapseSingularities, "Preprocess surface to be offset (bspline, bezier, or revolution based on bspline or bezier curve), by collapsing each singular side to single point.", py::arg("theSurface"), py::arg("theFace"), py::arg("thePrecision"));

// Enums

}