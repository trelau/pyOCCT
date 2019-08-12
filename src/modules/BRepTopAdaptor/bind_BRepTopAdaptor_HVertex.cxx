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
#include <Adaptor3d_HVertex.hxx>
#include <TopoDS_Vertex.hxx>
#include <Standard_Handle.hxx>
#include <BRepAdaptor_HCurve2d.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <TopAbs_Orientation.hxx>
#include <BRepTopAdaptor_HVertex.hxx>
#include <Standard_Type.hxx>

void bind_BRepTopAdaptor_HVertex(py::module &mod){

py::class_<BRepTopAdaptor_HVertex, opencascade::handle<BRepTopAdaptor_HVertex>, Adaptor3d_HVertex> cls_BRepTopAdaptor_HVertex(mod, "BRepTopAdaptor_HVertex", "None");

// Constructors
cls_BRepTopAdaptor_HVertex.def(py::init<const TopoDS_Vertex &, const opencascade::handle<BRepAdaptor_HCurve2d> &>(), py::arg("Vtx"), py::arg("Curve"));

// Fields

// Methods
cls_BRepTopAdaptor_HVertex.def("Vertex", (const TopoDS_Vertex & (BRepTopAdaptor_HVertex::*)() const) &BRepTopAdaptor_HVertex::Vertex, "None");
cls_BRepTopAdaptor_HVertex.def("ChangeVertex", (TopoDS_Vertex & (BRepTopAdaptor_HVertex::*)()) &BRepTopAdaptor_HVertex::ChangeVertex, "None");
cls_BRepTopAdaptor_HVertex.def("Value", (gp_Pnt2d (BRepTopAdaptor_HVertex::*)()) &BRepTopAdaptor_HVertex::Value, "None");
cls_BRepTopAdaptor_HVertex.def("Parameter", (Standard_Real (BRepTopAdaptor_HVertex::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepTopAdaptor_HVertex::Parameter, "None", py::arg("C"));
cls_BRepTopAdaptor_HVertex.def("Resolution", (Standard_Real (BRepTopAdaptor_HVertex::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepTopAdaptor_HVertex::Resolution, "Parametric resolution (2d).", py::arg("C"));
cls_BRepTopAdaptor_HVertex.def("Orientation", (TopAbs_Orientation (BRepTopAdaptor_HVertex::*)()) &BRepTopAdaptor_HVertex::Orientation, "None");
cls_BRepTopAdaptor_HVertex.def("IsSame", (Standard_Boolean (BRepTopAdaptor_HVertex::*)(const opencascade::handle<Adaptor3d_HVertex> &)) &BRepTopAdaptor_HVertex::IsSame, "None", py::arg("Other"));
cls_BRepTopAdaptor_HVertex.def_static("get_type_name_", (const char * (*)()) &BRepTopAdaptor_HVertex::get_type_name, "None");
cls_BRepTopAdaptor_HVertex.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepTopAdaptor_HVertex::get_type_descriptor, "None");
cls_BRepTopAdaptor_HVertex.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepTopAdaptor_HVertex::*)() const) &BRepTopAdaptor_HVertex::DynamicType, "None");

// Enums

}