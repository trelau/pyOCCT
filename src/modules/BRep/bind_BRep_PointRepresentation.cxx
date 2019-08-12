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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <TopLoc_Location.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Surface.hxx>
#include <BRep_PointRepresentation.hxx>
#include <Standard_Type.hxx>

void bind_BRep_PointRepresentation(py::module &mod){

py::class_<BRep_PointRepresentation, opencascade::handle<BRep_PointRepresentation>, Standard_Transient> cls_BRep_PointRepresentation(mod, "BRep_PointRepresentation", "Root class for the points representations. Contains a location and a parameter.");

// Constructors

// Fields

// Methods
cls_BRep_PointRepresentation.def("IsPointOnCurve", (Standard_Boolean (BRep_PointRepresentation::*)() const) &BRep_PointRepresentation::IsPointOnCurve, "A point on a 3d curve.");
cls_BRep_PointRepresentation.def("IsPointOnCurveOnSurface", (Standard_Boolean (BRep_PointRepresentation::*)() const) &BRep_PointRepresentation::IsPointOnCurveOnSurface, "A point on a 2d curve on a surface.");
cls_BRep_PointRepresentation.def("IsPointOnSurface", (Standard_Boolean (BRep_PointRepresentation::*)() const) &BRep_PointRepresentation::IsPointOnSurface, "A point on a surface.");
cls_BRep_PointRepresentation.def("IsPointOnCurve", (Standard_Boolean (BRep_PointRepresentation::*)(const opencascade::handle<Geom_Curve> &, const TopLoc_Location &) const) &BRep_PointRepresentation::IsPointOnCurve, "A point on the curve <C>.", py::arg("C"), py::arg("L"));
cls_BRep_PointRepresentation.def("IsPointOnCurveOnSurface", (Standard_Boolean (BRep_PointRepresentation::*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom_Surface> &, const TopLoc_Location &) const) &BRep_PointRepresentation::IsPointOnCurveOnSurface, "A point on the 2d curve <PC> on the surface <S>.", py::arg("PC"), py::arg("S"), py::arg("L"));
cls_BRep_PointRepresentation.def("IsPointOnSurface", (Standard_Boolean (BRep_PointRepresentation::*)(const opencascade::handle<Geom_Surface> &, const TopLoc_Location &) const) &BRep_PointRepresentation::IsPointOnSurface, "A point on the surface <S>.", py::arg("S"), py::arg("L"));
cls_BRep_PointRepresentation.def("Location", (const TopLoc_Location & (BRep_PointRepresentation::*)() const) &BRep_PointRepresentation::Location, "None");
cls_BRep_PointRepresentation.def("Location", (void (BRep_PointRepresentation::*)(const TopLoc_Location &)) &BRep_PointRepresentation::Location, "None", py::arg("L"));
cls_BRep_PointRepresentation.def("Parameter", (Standard_Real (BRep_PointRepresentation::*)() const) &BRep_PointRepresentation::Parameter, "None");
cls_BRep_PointRepresentation.def("Parameter", (void (BRep_PointRepresentation::*)(const Standard_Real)) &BRep_PointRepresentation::Parameter, "None", py::arg("P"));
cls_BRep_PointRepresentation.def("Parameter2", (Standard_Real (BRep_PointRepresentation::*)() const) &BRep_PointRepresentation::Parameter2, "None");
cls_BRep_PointRepresentation.def("Parameter2", (void (BRep_PointRepresentation::*)(const Standard_Real)) &BRep_PointRepresentation::Parameter2, "None", py::arg("P"));
cls_BRep_PointRepresentation.def("Curve", (const opencascade::handle<Geom_Curve> & (BRep_PointRepresentation::*)() const) &BRep_PointRepresentation::Curve, "None");
cls_BRep_PointRepresentation.def("Curve", (void (BRep_PointRepresentation::*)(const opencascade::handle<Geom_Curve> &)) &BRep_PointRepresentation::Curve, "None", py::arg("C"));
cls_BRep_PointRepresentation.def("PCurve", (const opencascade::handle<Geom2d_Curve> & (BRep_PointRepresentation::*)() const) &BRep_PointRepresentation::PCurve, "None");
cls_BRep_PointRepresentation.def("PCurve", (void (BRep_PointRepresentation::*)(const opencascade::handle<Geom2d_Curve> &)) &BRep_PointRepresentation::PCurve, "None", py::arg("C"));
cls_BRep_PointRepresentation.def("Surface", (const opencascade::handle<Geom_Surface> & (BRep_PointRepresentation::*)() const) &BRep_PointRepresentation::Surface, "None");
cls_BRep_PointRepresentation.def("Surface", (void (BRep_PointRepresentation::*)(const opencascade::handle<Geom_Surface> &)) &BRep_PointRepresentation::Surface, "None", py::arg("S"));
cls_BRep_PointRepresentation.def_static("get_type_name_", (const char * (*)()) &BRep_PointRepresentation::get_type_name, "None");
cls_BRep_PointRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_PointRepresentation::get_type_descriptor, "None");
cls_BRep_PointRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_PointRepresentation::*)() const) &BRep_PointRepresentation::DynamicType, "None");

// Enums

}