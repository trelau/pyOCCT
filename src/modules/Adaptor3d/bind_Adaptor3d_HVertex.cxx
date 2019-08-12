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
#include <gp_Pnt2d.hxx>
#include <TopAbs_Orientation.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <Adaptor3d_HVertex.hxx>
#include <Standard_Type.hxx>

void bind_Adaptor3d_HVertex(py::module &mod){

py::class_<Adaptor3d_HVertex, opencascade::handle<Adaptor3d_HVertex>, Standard_Transient> cls_Adaptor3d_HVertex(mod, "Adaptor3d_HVertex", "None");

// Constructors
cls_Adaptor3d_HVertex.def(py::init<>());
cls_Adaptor3d_HVertex.def(py::init<const gp_Pnt2d &, const TopAbs_Orientation, const Standard_Real>(), py::arg("P"), py::arg("Ori"), py::arg("Resolution"));

// Fields

// Methods
cls_Adaptor3d_HVertex.def("Value", (gp_Pnt2d (Adaptor3d_HVertex::*)()) &Adaptor3d_HVertex::Value, "None");
cls_Adaptor3d_HVertex.def("Parameter", (Standard_Real (Adaptor3d_HVertex::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Adaptor3d_HVertex::Parameter, "None", py::arg("C"));
cls_Adaptor3d_HVertex.def("Resolution", (Standard_Real (Adaptor3d_HVertex::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Adaptor3d_HVertex::Resolution, "Parametric resolution (2d).", py::arg("C"));
cls_Adaptor3d_HVertex.def("Orientation", (TopAbs_Orientation (Adaptor3d_HVertex::*)()) &Adaptor3d_HVertex::Orientation, "None");
cls_Adaptor3d_HVertex.def("IsSame", (Standard_Boolean (Adaptor3d_HVertex::*)(const opencascade::handle<Adaptor3d_HVertex> &)) &Adaptor3d_HVertex::IsSame, "None", py::arg("Other"));
cls_Adaptor3d_HVertex.def_static("get_type_name_", (const char * (*)()) &Adaptor3d_HVertex::get_type_name, "None");
cls_Adaptor3d_HVertex.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Adaptor3d_HVertex::get_type_descriptor, "None");
cls_Adaptor3d_HVertex.def("DynamicType", (const opencascade::handle<Standard_Type> & (Adaptor3d_HVertex::*)() const) &Adaptor3d_HVertex::DynamicType, "None");

// Enums

}