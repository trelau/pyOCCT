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
#include <Standard.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <BRepTopAdaptor_TopolTool.hxx>
#include <BRepTopAdaptor_Tool.hxx>
#include <NCollection_DataMap.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ShapeMapHasher.hxx>
#include <BRepTopAdaptor_MapOfShapeTool.hxx>
#include <TColStd_SequenceOfAddress.hxx>
#include <BRepTopAdaptor_SeqOfPtr.hxx>
#include <TopAbs_State.hxx>
#include <gp_Pnt2d.hxx>
#include <BRepTopAdaptor_FClass2d.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <Adaptor3d_HVertex.hxx>
#include <TopoDS_Vertex.hxx>
#include <BRepAdaptor_HCurve2d.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <TopAbs_Orientation.hxx>
#include <Standard_Std.hxx>
#include <BRepTopAdaptor_HVertex.hxx>
#include <Standard_Type.hxx>
#include <Adaptor3d_TopolTool.hxx>
#include <gp_Pnt.hxx>
#include <TopExp_Explorer.hxx>
#include <TColStd_ListOfTransient.hxx>
#include <bind_NCollection_DataMap.hxx>
#include <bind_NCollection_Sequence.hxx>

PYBIND11_MODULE(BRepTopAdaptor, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.gp");
py::module::import("OCCT.BRepAdaptor");
py::module::import("OCCT.Adaptor2d");
py::module::import("OCCT.TopExp");

// CLASS: BREPTOPADAPTOR_TOOL
py::class_<BRepTopAdaptor_Tool> cls_BRepTopAdaptor_Tool(mod, "BRepTopAdaptor_Tool", "None");

// Constructors
cls_BRepTopAdaptor_Tool.def(py::init<>());
cls_BRepTopAdaptor_Tool.def(py::init<const TopoDS_Face &, const Standard_Real>(), py::arg("F"), py::arg("Tol2d"));
cls_BRepTopAdaptor_Tool.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real>(), py::arg("Surface"), py::arg("Tol2d"));

// Methods
// cls_BRepTopAdaptor_Tool.def_static("operator new_", (void * (*)(size_t)) &BRepTopAdaptor_Tool::operator new, "None", py::arg("theSize"));
// cls_BRepTopAdaptor_Tool.def_static("operator delete_", (void (*)(void *)) &BRepTopAdaptor_Tool::operator delete, "None", py::arg("theAddress"));
// cls_BRepTopAdaptor_Tool.def_static("operator new[]_", (void * (*)(size_t)) &BRepTopAdaptor_Tool::operator new[], "None", py::arg("theSize"));
// cls_BRepTopAdaptor_Tool.def_static("operator delete[]_", (void (*)(void *)) &BRepTopAdaptor_Tool::operator delete[], "None", py::arg("theAddress"));
// cls_BRepTopAdaptor_Tool.def_static("operator new_", (void * (*)(size_t, void *)) &BRepTopAdaptor_Tool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepTopAdaptor_Tool.def_static("operator delete_", (void (*)(void *, void *)) &BRepTopAdaptor_Tool::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepTopAdaptor_Tool.def("Init", (void (BRepTopAdaptor_Tool::*)(const TopoDS_Face &, const Standard_Real)) &BRepTopAdaptor_Tool::Init, "None", py::arg("F"), py::arg("Tol2d"));
cls_BRepTopAdaptor_Tool.def("Init", (void (BRepTopAdaptor_Tool::*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real)) &BRepTopAdaptor_Tool::Init, "None", py::arg("Surface"), py::arg("Tol2d"));
cls_BRepTopAdaptor_Tool.def("GetTopolTool", (opencascade::handle<BRepTopAdaptor_TopolTool> (BRepTopAdaptor_Tool::*)()) &BRepTopAdaptor_Tool::GetTopolTool, "None");
cls_BRepTopAdaptor_Tool.def("SetTopolTool", (void (BRepTopAdaptor_Tool::*)(const opencascade::handle<BRepTopAdaptor_TopolTool> &)) &BRepTopAdaptor_Tool::SetTopolTool, "None", py::arg("TT"));
cls_BRepTopAdaptor_Tool.def("GetSurface", (opencascade::handle<Adaptor3d_HSurface> (BRepTopAdaptor_Tool::*)()) &BRepTopAdaptor_Tool::GetSurface, "None");
cls_BRepTopAdaptor_Tool.def("Destroy", (void (BRepTopAdaptor_Tool::*)()) &BRepTopAdaptor_Tool::Destroy, "None");

// TYPEDEF: BREPTOPADAPTOR_MAPOFSHAPETOOL
bind_NCollection_DataMap<TopoDS_Shape, BRepTopAdaptor_Tool, TopTools_ShapeMapHasher>(mod, "BRepTopAdaptor_MapOfShapeTool", py::module_local(false));

// TYPEDEF: BREPTOPADAPTOR_DATAMAPITERATOROFMAPOFSHAPETOOL

// TYPEDEF: BREPTOPADAPTOR_SEQOFPTR
bind_NCollection_Sequence<void *>(mod, "BRepTopAdaptor_SeqOfPtr", py::module_local());

// CLASS: BREPTOPADAPTOR_FCLASS2D
py::class_<BRepTopAdaptor_FClass2d> cls_BRepTopAdaptor_FClass2d(mod, "BRepTopAdaptor_FClass2d", "None");

// Constructors
cls_BRepTopAdaptor_FClass2d.def(py::init<const TopoDS_Face &, const Standard_Real>(), py::arg("F"), py::arg("Tol"));

// Methods
// cls_BRepTopAdaptor_FClass2d.def_static("operator new_", (void * (*)(size_t)) &BRepTopAdaptor_FClass2d::operator new, "None", py::arg("theSize"));
// cls_BRepTopAdaptor_FClass2d.def_static("operator delete_", (void (*)(void *)) &BRepTopAdaptor_FClass2d::operator delete, "None", py::arg("theAddress"));
// cls_BRepTopAdaptor_FClass2d.def_static("operator new[]_", (void * (*)(size_t)) &BRepTopAdaptor_FClass2d::operator new[], "None", py::arg("theSize"));
// cls_BRepTopAdaptor_FClass2d.def_static("operator delete[]_", (void (*)(void *)) &BRepTopAdaptor_FClass2d::operator delete[], "None", py::arg("theAddress"));
// cls_BRepTopAdaptor_FClass2d.def_static("operator new_", (void * (*)(size_t, void *)) &BRepTopAdaptor_FClass2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepTopAdaptor_FClass2d.def_static("operator delete_", (void (*)(void *, void *)) &BRepTopAdaptor_FClass2d::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepTopAdaptor_FClass2d.def("PerformInfinitePoint", (TopAbs_State (BRepTopAdaptor_FClass2d::*)() const) &BRepTopAdaptor_FClass2d::PerformInfinitePoint, "None");
cls_BRepTopAdaptor_FClass2d.def("Perform", [](BRepTopAdaptor_FClass2d &self, const gp_Pnt2d & a0) -> TopAbs_State { return self.Perform(a0); });
cls_BRepTopAdaptor_FClass2d.def("Perform", (TopAbs_State (BRepTopAdaptor_FClass2d::*)(const gp_Pnt2d &, const Standard_Boolean) const) &BRepTopAdaptor_FClass2d::Perform, "None", py::arg("Puv"), py::arg("RecadreOnPeriodic"));
cls_BRepTopAdaptor_FClass2d.def("Destroy", (void (BRepTopAdaptor_FClass2d::*)()) &BRepTopAdaptor_FClass2d::Destroy, "None");
cls_BRepTopAdaptor_FClass2d.def("Copy", (const BRepTopAdaptor_FClass2d & (BRepTopAdaptor_FClass2d::*)(const BRepTopAdaptor_FClass2d &) const) &BRepTopAdaptor_FClass2d::Copy, "None", py::arg("Other"));
// cls_BRepTopAdaptor_FClass2d.def("operator=", (const BRepTopAdaptor_FClass2d & (BRepTopAdaptor_FClass2d::*)(const BRepTopAdaptor_FClass2d &) const) &BRepTopAdaptor_FClass2d::operator=, "None", py::arg("Other"));
cls_BRepTopAdaptor_FClass2d.def("TestOnRestriction", [](BRepTopAdaptor_FClass2d &self, const gp_Pnt2d & a0, const Standard_Real a1) -> TopAbs_State { return self.TestOnRestriction(a0, a1); });
cls_BRepTopAdaptor_FClass2d.def("TestOnRestriction", (TopAbs_State (BRepTopAdaptor_FClass2d::*)(const gp_Pnt2d &, const Standard_Real, const Standard_Boolean) const) &BRepTopAdaptor_FClass2d::TestOnRestriction, "Test a point with +- an offset (Tol) and returns On if some points are OUT an some are IN (Caution: Internal use . see the code for more details)", py::arg("Puv"), py::arg("Tol"), py::arg("RecadreOnPeriodic"));

// CLASS: BREPTOPADAPTOR_HVERTEX
py::class_<BRepTopAdaptor_HVertex, opencascade::handle<BRepTopAdaptor_HVertex>, Adaptor3d_HVertex> cls_BRepTopAdaptor_HVertex(mod, "BRepTopAdaptor_HVertex", "None");

// Constructors
cls_BRepTopAdaptor_HVertex.def(py::init<const TopoDS_Vertex &, const opencascade::handle<BRepAdaptor_HCurve2d> &>(), py::arg("Vtx"), py::arg("Curve"));

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

// CLASS: BREPTOPADAPTOR_TOPOLTOOL
py::class_<BRepTopAdaptor_TopolTool, opencascade::handle<BRepTopAdaptor_TopolTool>, Adaptor3d_TopolTool> cls_BRepTopAdaptor_TopolTool(mod, "BRepTopAdaptor_TopolTool", "None");

// Constructors
cls_BRepTopAdaptor_TopolTool.def(py::init<>());
cls_BRepTopAdaptor_TopolTool.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("Surface"));

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


}
