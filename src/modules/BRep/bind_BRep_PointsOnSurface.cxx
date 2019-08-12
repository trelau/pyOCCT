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
#include <BRep_PointRepresentation.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <BRep_PointsOnSurface.hxx>
#include <Standard_Type.hxx>
#include <Standard_TypeDef.hxx>
#include <TopLoc_Location.hxx>

void bind_BRep_PointsOnSurface(py::module &mod){

py::class_<BRep_PointsOnSurface, opencascade::handle<BRep_PointsOnSurface>, BRep_PointRepresentation> cls_BRep_PointsOnSurface(mod, "BRep_PointsOnSurface", "Root for points on surface.");

// Constructors

// Fields

// Methods
cls_BRep_PointsOnSurface.def("Surface", (const opencascade::handle<Geom_Surface> & (BRep_PointsOnSurface::*)() const) &BRep_PointsOnSurface::Surface, "None");
cls_BRep_PointsOnSurface.def("Surface", (void (BRep_PointsOnSurface::*)(const opencascade::handle<Geom_Surface> &)) &BRep_PointsOnSurface::Surface, "None", py::arg("S"));
cls_BRep_PointsOnSurface.def_static("get_type_name_", (const char * (*)()) &BRep_PointsOnSurface::get_type_name, "None");
cls_BRep_PointsOnSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_PointsOnSurface::get_type_descriptor, "None");
cls_BRep_PointsOnSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_PointsOnSurface::*)() const) &BRep_PointsOnSurface::DynamicType, "None");

// Enums

}