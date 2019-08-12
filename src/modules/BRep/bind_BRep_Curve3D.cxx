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
#include <BRep_GCurve.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <TopLoc_Location.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <BRep_CurveRepresentation.hxx>
#include <BRep_Curve3D.hxx>
#include <Standard_Type.hxx>

void bind_BRep_Curve3D(py::module &mod){

py::class_<BRep_Curve3D, opencascade::handle<BRep_Curve3D>, BRep_GCurve> cls_BRep_Curve3D(mod, "BRep_Curve3D", "Representation of a curve by a 3D curve.");

// Constructors
cls_BRep_Curve3D.def(py::init<const opencascade::handle<Geom_Curve> &, const TopLoc_Location &>(), py::arg("C"), py::arg("L"));

// Fields

// Methods
cls_BRep_Curve3D.def("D0", (void (BRep_Curve3D::*)(const Standard_Real, gp_Pnt &) const) &BRep_Curve3D::D0, "Computes the point at parameter U.", py::arg("U"), py::arg("P"));
cls_BRep_Curve3D.def("IsCurve3D", (Standard_Boolean (BRep_Curve3D::*)() const) &BRep_Curve3D::IsCurve3D, "Returns True.");
cls_BRep_Curve3D.def("Curve3D", (const opencascade::handle<Geom_Curve> & (BRep_Curve3D::*)() const) &BRep_Curve3D::Curve3D, "None");
cls_BRep_Curve3D.def("Curve3D", (void (BRep_Curve3D::*)(const opencascade::handle<Geom_Curve> &)) &BRep_Curve3D::Curve3D, "None", py::arg("C"));
cls_BRep_Curve3D.def("Copy", (opencascade::handle<BRep_CurveRepresentation> (BRep_Curve3D::*)() const) &BRep_Curve3D::Copy, "Return a copy of this representation.");
cls_BRep_Curve3D.def_static("get_type_name_", (const char * (*)()) &BRep_Curve3D::get_type_name, "None");
cls_BRep_Curve3D.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_Curve3D::get_type_descriptor, "None");
cls_BRep_Curve3D.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_Curve3D::*)() const) &BRep_Curve3D::DynamicType, "None");

// Enums

}