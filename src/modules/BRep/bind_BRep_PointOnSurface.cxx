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
#include <BRep_PointsOnSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <TopLoc_Location.hxx>
#include <BRep_PointOnSurface.hxx>
#include <Standard_Type.hxx>

void bind_BRep_PointOnSurface(py::module &mod){

py::class_<BRep_PointOnSurface, opencascade::handle<BRep_PointOnSurface>, BRep_PointsOnSurface> cls_BRep_PointOnSurface(mod, "BRep_PointOnSurface", "Representation by two parameters on a surface.");

// Constructors
cls_BRep_PointOnSurface.def(py::init<const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &>(), py::arg("P1"), py::arg("P2"), py::arg("S"), py::arg("L"));

// Fields

// Methods
cls_BRep_PointOnSurface.def("IsPointOnSurface", (Standard_Boolean (BRep_PointOnSurface::*)() const) &BRep_PointOnSurface::IsPointOnSurface, "None");
cls_BRep_PointOnSurface.def("IsPointOnSurface", (Standard_Boolean (BRep_PointOnSurface::*)(const opencascade::handle<Geom_Surface> &, const TopLoc_Location &) const) &BRep_PointOnSurface::IsPointOnSurface, "None", py::arg("S"), py::arg("L"));
cls_BRep_PointOnSurface.def("Parameter2", (Standard_Real (BRep_PointOnSurface::*)() const) &BRep_PointOnSurface::Parameter2, "None");
cls_BRep_PointOnSurface.def("Parameter2", (void (BRep_PointOnSurface::*)(const Standard_Real)) &BRep_PointOnSurface::Parameter2, "None", py::arg("P"));
cls_BRep_PointOnSurface.def_static("get_type_name_", (const char * (*)()) &BRep_PointOnSurface::get_type_name, "None");
cls_BRep_PointOnSurface.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_PointOnSurface::get_type_descriptor, "None");
cls_BRep_PointOnSurface.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_PointOnSurface::*)() const) &BRep_PointOnSurface::DynamicType, "None");

// Enums

}