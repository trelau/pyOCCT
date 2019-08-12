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
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Handle.hxx>
#include <BRep_GCurve.hxx>
#include <Standard_Type.hxx>
#include <TopLoc_Location.hxx>

void bind_BRep_GCurve(py::module &mod){

py::class_<BRep_GCurve, opencascade::handle<BRep_GCurve>, BRep_CurveRepresentation> cls_BRep_GCurve(mod, "BRep_GCurve", "Root class for the geometric curves representation. Contains a range. Contains a first and a last parameter.");

// Fields

// Methods
cls_BRep_GCurve.def("SetRange", (void (BRep_GCurve::*)(const Standard_Real, const Standard_Real)) &BRep_GCurve::SetRange, "None", py::arg("First"), py::arg("Last"));
cls_BRep_GCurve.def("Range", [](BRep_GCurve &self, Standard_Real & First, Standard_Real & Last){ self.Range(First, Last); return std::tuple<Standard_Real &, Standard_Real &>(First, Last); }, "None", py::arg("First"), py::arg("Last"));
cls_BRep_GCurve.def("First", (Standard_Real (BRep_GCurve::*)() const) &BRep_GCurve::First, "None");
cls_BRep_GCurve.def("Last", (Standard_Real (BRep_GCurve::*)() const) &BRep_GCurve::Last, "None");
cls_BRep_GCurve.def("First", (void (BRep_GCurve::*)(const Standard_Real)) &BRep_GCurve::First, "None", py::arg("F"));
cls_BRep_GCurve.def("Last", (void (BRep_GCurve::*)(const Standard_Real)) &BRep_GCurve::Last, "None", py::arg("L"));
cls_BRep_GCurve.def("D0", (void (BRep_GCurve::*)(const Standard_Real, gp_Pnt &) const) &BRep_GCurve::D0, "Computes the point at parameter U.", py::arg("U"), py::arg("P"));
cls_BRep_GCurve.def("Update", (void (BRep_GCurve::*)()) &BRep_GCurve::Update, "Recomputes any derived data after a modification. This is called when the range is modified.");
cls_BRep_GCurve.def_static("get_type_name_", (const char * (*)()) &BRep_GCurve::get_type_name, "None");
cls_BRep_GCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRep_GCurve::get_type_descriptor, "None");
cls_BRep_GCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRep_GCurve::*)() const) &BRep_GCurve::DynamicType, "None");

// Enums

}