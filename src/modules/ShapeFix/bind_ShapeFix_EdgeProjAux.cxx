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
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <ShapeFix_EdgeProjAux.hxx>
#include <Standard_Type.hxx>

void bind_ShapeFix_EdgeProjAux(py::module &mod){

py::class_<ShapeFix_EdgeProjAux, opencascade::handle<ShapeFix_EdgeProjAux>, Standard_Transient> cls_ShapeFix_EdgeProjAux(mod, "ShapeFix_EdgeProjAux", "Project 3D point (vertex) on pcurves to find Vertex Parameter on parametric representation of an edge");

// Constructors
cls_ShapeFix_EdgeProjAux.def(py::init<>());
cls_ShapeFix_EdgeProjAux.def(py::init<const TopoDS_Face &, const TopoDS_Edge &>(), py::arg("F"), py::arg("E"));

// Fields

// Methods
cls_ShapeFix_EdgeProjAux.def("Init", (void (ShapeFix_EdgeProjAux::*)(const TopoDS_Face &, const TopoDS_Edge &)) &ShapeFix_EdgeProjAux::Init, "None", py::arg("F"), py::arg("E"));
cls_ShapeFix_EdgeProjAux.def("Compute", (void (ShapeFix_EdgeProjAux::*)(const Standard_Real)) &ShapeFix_EdgeProjAux::Compute, "None", py::arg("preci"));
cls_ShapeFix_EdgeProjAux.def("IsFirstDone", (Standard_Boolean (ShapeFix_EdgeProjAux::*)() const) &ShapeFix_EdgeProjAux::IsFirstDone, "None");
cls_ShapeFix_EdgeProjAux.def("IsLastDone", (Standard_Boolean (ShapeFix_EdgeProjAux::*)() const) &ShapeFix_EdgeProjAux::IsLastDone, "None");
cls_ShapeFix_EdgeProjAux.def("FirstParam", (Standard_Real (ShapeFix_EdgeProjAux::*)() const) &ShapeFix_EdgeProjAux::FirstParam, "None");
cls_ShapeFix_EdgeProjAux.def("LastParam", (Standard_Real (ShapeFix_EdgeProjAux::*)() const) &ShapeFix_EdgeProjAux::LastParam, "None");
cls_ShapeFix_EdgeProjAux.def("IsIso", (Standard_Boolean (ShapeFix_EdgeProjAux::*)(const opencascade::handle<Geom2d_Curve> &)) &ShapeFix_EdgeProjAux::IsIso, "None", py::arg("C"));
cls_ShapeFix_EdgeProjAux.def_static("get_type_name_", (const char * (*)()) &ShapeFix_EdgeProjAux::get_type_name, "None");
cls_ShapeFix_EdgeProjAux.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeFix_EdgeProjAux::get_type_descriptor, "None");
cls_ShapeFix_EdgeProjAux.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeFix_EdgeProjAux::*)() const) &ShapeFix_EdgeProjAux::DynamicType, "None");

// Enums

}