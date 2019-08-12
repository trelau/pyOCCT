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
#include <BRep_CurveRepresentation.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <TopLoc_Location.hxx>
#include <GeomAbs_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <BRep_CurveOn2Surfaces.hxx>
#include <Standard_Type.hxx>

void bind_BRep_CurveOn2Surfaces(py::module &mod){

py::class_<BRep_CurveOn2Surfaces, opencascade::handle<BRep_CurveOn2Surfaces>, BRep_CurveRepresentation> cls_BRep_CurveOn2Surfaces(mod, "BRep_CurveOn2Surfaces", "Defines a continuity between two surfaces.");

// Constructors
cls_BRep_CurveOn2Surfaces.def(py::init<const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const TopLoc_Location &, const GeomAbs_Shape>(), py::arg("S1"), py::arg("S2"), py::arg("L1"), py::arg("L2"), py::arg("C"));

// Fields

// Methods
cls_BRep_CurveOn2Surfaces.def("IsRegularity", (Standard_Boolean (BRep_CurveOn2Surfaces::*)() const) &BRep_CurveOn2Surfaces::IsRegularity, "Returns True.");
cls_BRep_CurveOn2Surfaces.def("IsRegularity", (Standard_Boolean (BRep_CurveOn2Surfaces::*)(const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &, const TopLoc_Location &) const) &BRep_CurveOn2Surfaces::IsRegularity, "A curve on two surfaces (continuity).", py::arg("S1"), py::arg("S2"), py::arg("L1"), py::arg("L2"));
cls_BRep_CurveOn2Surfaces.def("D0", (void (BRep_CurveOn2Surfaces::*)(const Standard_Real, gp_Pnt &) const) &BRep_CurveOn2Surfaces::D0, "Raises an error.", py::arg("U"), py::arg("P"));
cls_BRep_CurveOn2Surfaces.def("Surface", (const opencascade::handle<Geom_Surface> & (BRep_CurveOn2Surfaces::*)() const) &BRep_CurveOn2Surfaces::Surface, "None");
cls_BRep_CurveOn2Surfaces.def("Surface2", (const opencascade::handle<Geom_Surface> & (BRep_CurveOn2Surfaces::*)() const) &BRep_CurveOn2Surfaces::Surface2, "None");
cls_BRep_CurveOn2Surfaces.def("Location2", (const TopLoc_Location & (BRep_CurveOn2Surfaces::*)() const) &BRep_CurveOn2Surfaces::Location2, "None");
cls_BRep_CurveOn2Surfaces.def("Continuity", (const GeomAbs_Shape & (BRep_CurveOn2Surfaces::*)() const) &BRep_CurveOn2Surfaces::Continuity, "None");
cls_BRep_CurveOn2Surfaces.def("Continuity", (void (BRep_CurveOn2Surfaces::*)(const GeomAbs_Shape)) &BRep_CurveOn2Surfaces::Continuity, "None", py::arg("C"));
cls_BRep_CurveOn2Surfaces.def("Copy", (opencascade::handle<BRep_CurveRepresentation> (BRep_CurveOn2Surfaces::*)() const) &BRep_CurveOn2Surfaces::Copy, "Return a copy of this representation.");
cls_BRep_CurveOn2Surfaces.def_static("get_type_name_", (const char * (*)()) &BRep_CurveOn2Surfaces::get_type_name, "None");
cls_BRep_CurveOn2Surfaces.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_CurveOn2Surfaces::get_type_descriptor, "None");
cls_BRep_CurveOn2Surfaces.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_CurveOn2Surfaces::*)() const) &BRep_CurveOn2Surfaces::DynamicType, "None");

// Enums

}