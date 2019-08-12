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
#include <GeomFill_TrihedronLaw.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <GeomFill_TrihedronWithGuide.hxx>
#include <Standard_Type.hxx>

void bind_GeomFill_TrihedronWithGuide(py::module &mod){

py::class_<GeomFill_TrihedronWithGuide, opencascade::handle<GeomFill_TrihedronWithGuide>, GeomFill_TrihedronLaw> cls_GeomFill_TrihedronWithGuide(mod, "GeomFill_TrihedronWithGuide", "To define Trihedron along one Curve with a guide");

// Fields

// Methods
cls_GeomFill_TrihedronWithGuide.def("Guide", (opencascade::handle<Adaptor3d_HCurve> (GeomFill_TrihedronWithGuide::*)() const) &GeomFill_TrihedronWithGuide::Guide, "None");
cls_GeomFill_TrihedronWithGuide.def("Origine", (void (GeomFill_TrihedronWithGuide::*)(const Standard_Real, const Standard_Real)) &GeomFill_TrihedronWithGuide::Origine, "None", py::arg("Param1"), py::arg("Param2"));
cls_GeomFill_TrihedronWithGuide.def("CurrentPointOnGuide", (gp_Pnt (GeomFill_TrihedronWithGuide::*)() const) &GeomFill_TrihedronWithGuide::CurrentPointOnGuide, "Returns the current point on guide found by D0, D1 or D2.");
cls_GeomFill_TrihedronWithGuide.def_static("get_type_name_", (const char * (*)()) &GeomFill_TrihedronWithGuide::get_type_name, "None");
cls_GeomFill_TrihedronWithGuide.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &GeomFill_TrihedronWithGuide::get_type_descriptor, "None");
cls_GeomFill_TrihedronWithGuide.def("DynamicType", (const opencascade::handle<Standard_Type> & (GeomFill_TrihedronWithGuide::*)() const) &GeomFill_TrihedronWithGuide::DynamicType, "None");

// Enums

}