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
#include <Adaptor3d_TopolTool.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Adaptor3d_HVertex.hxx>
#include <TopAbs_State.hxx>
#include <gp_Pnt2d.hxx>
#include <TopAbs_Orientation.hxx>
#include <gp_Pnt.hxx>
#include <BRepTopAdaptor_TopolTool.hxx>
#include <Standard_Type.hxx>
#include <TopExp_Explorer.hxx>
#include <TopoDS_Face.hxx>
#include <BRepAdaptor_HCurve2d.hxx>
#include <TColStd_ListOfTransient.hxx>

void bind_BRepTopAdaptor_TopolTool(py::module &mod){

py::class_<BRepTopAdaptor_TopolTool, opencascade::handle<BRepTopAdaptor_TopolTool>, Adaptor3d_TopolTool> cls_BRepTopAdaptor_TopolTool(mod, "BRepTopAdaptor_TopolTool", "None");

// Constructors
cls_BRepTopAdaptor_TopolTool.def(py::init<>());
cls_BRepTopAdaptor_TopolTool.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("Surface"));

// Fields

// Methods
cls_BRepTopAdaptor_TopolTool.def("Initialize", (void (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::Initialize, "None");
cls_BRepTopAdaptor_TopolTool.def("Initialize", (void (BRepTopAdaptor_TopolTool::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &BRepTopAdaptor_TopolTool::Initialize, "None", py::arg("S"));
cls_BRepTopAdaptor_TopolTool.def("Initialize", (void (BRepTopAdaptor_TopolTool::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepTopAdaptor_TopolTool::Initialize, "None", py::arg("Curve"));
cls_BRepTopAdaptor_TopolTool.def("Init", (void (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::Init, "None");
cls_BRepTopAdaptor_TopolTool.def("More", (Standard_Boolean (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::More, "None");
cls_BRepTopAdaptor_TopolTool.def("Value", (opencascade::handle<Adaptor2d_HCurve2d> (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::Value, "None");
cls_BRepTopAdaptor_TopolTool.def("Next", (void (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::Next, "None");
cls_BRepTopAdaptor_TopolTool.def("Edge", (Standard_Address (BRepTopAdaptor_TopolTool::*)() const) &BRepTopAdaptor_TopolTool::Edge, "None");
cls_BRepTopAdaptor_TopolTool.def("InitVertexIterator", (void (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::InitVertexIterator, "None");
cls_BRepTopAdaptor_TopolTool.def("MoreVertex", (Standard_Boolean (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::MoreVertex, "None");
cls_BRepTopAdaptor_TopolTool.def("Vertex", (opencascade::handle<Adaptor3d_HVertex> (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::Vertex, "None");
cls_BRepTopAdaptor_TopolTool.def("NextVertex", (void (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::NextVertex, "None");
cls_BRepTopAdaptor_TopolTool.def("Classify", [](BRepTopAdaptor_TopolTool &self, const gp_Pnt2d & a0, const Standard_Real a1) -> TopAbs_State { return self.Classify(a0, a1); });
cls_BRepTopAdaptor_TopolTool.def("Classify", (TopAbs_State (BRepTopAdaptor_TopolTool::*)(const gp_Pnt2d &, const Standard_Real, const Standard_Boolean)) &BRepTopAdaptor_TopolTool::Classify, "None", py::arg("P2d"), py::arg("Tol"), py::arg("RecadreOnPeriodic"));
cls_BRepTopAdaptor_TopolTool.def("IsThePointOn", [](BRepTopAdaptor_TopolTool &self, const gp_Pnt2d & a0, const Standard_Real a1) -> Standard_Boolean { return self.IsThePointOn(a0, a1); });
cls_BRepTopAdaptor_TopolTool.def("IsThePointOn", (Standard_Boolean (BRepTopAdaptor_TopolTool::*)(const gp_Pnt2d &, const Standard_Real, const Standard_Boolean)) &BRepTopAdaptor_TopolTool::IsThePointOn, "see the code for specifications)", py::arg("P2d"), py::arg("Tol"), py::arg("RecadreOnPeriodic"));
cls_BRepTopAdaptor_TopolTool.def("Orientation", (TopAbs_Orientation (BRepTopAdaptor_TopolTool::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &BRepTopAdaptor_TopolTool::Orientation, "If the function returns the orientation of the arc. If the orientation is FORWARD or REVERSED, the arc is a 'real' limit of the surface. If the orientation is INTERNAL or EXTERNAL, the arc is considered as an arc on the surface.", py::arg("C"));
cls_BRepTopAdaptor_TopolTool.def("Orientation", (TopAbs_Orientation (BRepTopAdaptor_TopolTool::*)(const opencascade::handle<Adaptor3d_HVertex> &)) &BRepTopAdaptor_TopolTool::Orientation, "If the function returns the orientation of the arc. If the orientation is FORWARD or REVERSED, the arc is a 'real' limit of the surface. If the orientation is INTERNAL or EXTERNAL, the arc is considered as an arc on the surface.", py::arg("C"));
cls_BRepTopAdaptor_TopolTool.def("Destroy", (void (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::Destroy, "None");
cls_BRepTopAdaptor_TopolTool.def("Has3d", (Standard_Boolean (BRepTopAdaptor_TopolTool::*)() const) &BRepTopAdaptor_TopolTool::Has3d, "answers if arcs and vertices may have 3d representations, so that we could use Tol3d and Pnt methods.");
cls_BRepTopAdaptor_TopolTool.def("Tol3d", (Standard_Real (BRepTopAdaptor_TopolTool::*)(const opencascade::handle<Adaptor2d_HCurve2d> &) const) &BRepTopAdaptor_TopolTool::Tol3d, "returns 3d tolerance of the arc C", py::arg("C"));
cls_BRepTopAdaptor_TopolTool.def("Tol3d", (Standard_Real (BRepTopAdaptor_TopolTool::*)(const opencascade::handle<Adaptor3d_HVertex> &) const) &BRepTopAdaptor_TopolTool::Tol3d, "returns 3d tolerance of the vertex V", py::arg("V"));
cls_BRepTopAdaptor_TopolTool.def("Pnt", (gp_Pnt (BRepTopAdaptor_TopolTool::*)(const opencascade::handle<Adaptor3d_HVertex> &) const) &BRepTopAdaptor_TopolTool::Pnt, "returns 3d point of the vertex V", py::arg("V"));
cls_BRepTopAdaptor_TopolTool.def("ComputeSamplePoints", (void (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::ComputeSamplePoints, "None");
cls_BRepTopAdaptor_TopolTool.def("NbSamplesU", (Standard_Integer (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::NbSamplesU, "compute the sample-points for the intersections algorithms");
cls_BRepTopAdaptor_TopolTool.def("NbSamplesV", (Standard_Integer (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::NbSamplesV, "compute the sample-points for the intersections algorithms");
cls_BRepTopAdaptor_TopolTool.def("NbSamples", (Standard_Integer (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::NbSamples, "compute the sample-points for the intersections algorithms");
cls_BRepTopAdaptor_TopolTool.def("SamplePoint", (void (BRepTopAdaptor_TopolTool::*)(const Standard_Integer, gp_Pnt2d &, gp_Pnt &)) &BRepTopAdaptor_TopolTool::SamplePoint, "None", py::arg("Index"), py::arg("P2d"), py::arg("P3d"));
cls_BRepTopAdaptor_TopolTool.def("DomainIsInfinite", (Standard_Boolean (BRepTopAdaptor_TopolTool::*)()) &BRepTopAdaptor_TopolTool::DomainIsInfinite, "None");
cls_BRepTopAdaptor_TopolTool.def_static("get_type_name_", (const char * (*)()) &BRepTopAdaptor_TopolTool::get_type_name, "None");
cls_BRepTopAdaptor_TopolTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepTopAdaptor_TopolTool::get_type_descriptor, "None");
cls_BRepTopAdaptor_TopolTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepTopAdaptor_TopolTool::*)() const) &BRepTopAdaptor_TopolTool::DynamicType, "None");

// Enums

}