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
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <Standard_TypeDef.hxx>
#include <Adaptor3d_HVertex.hxx>
#include <TopAbs_State.hxx>
#include <gp_Pnt2d.hxx>
#include <TopAbs_Orientation.hxx>
#include <gp_Pnt.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <Adaptor3d_TopolTool.hxx>
#include <Standard_Type.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <Adaptor2d_HLine2d.hxx>

void bind_Adaptor3d_TopolTool(py::module &mod){

py::class_<Adaptor3d_TopolTool, opencascade::handle<Adaptor3d_TopolTool>, Standard_Transient> cls_Adaptor3d_TopolTool(mod, "Adaptor3d_TopolTool", "This class provides a default topological tool, based on the Umin,Vmin,Umax,Vmax of an HSurface from Adaptor3d. All methods and fields may be redefined when inheriting from this class. This class is used to instantiate algorithmes as Intersection, outlines,...");

// Constructors
cls_Adaptor3d_TopolTool.def(py::init<>());
cls_Adaptor3d_TopolTool.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("Surface"));

// Fields

// Methods
cls_Adaptor3d_TopolTool.def("Initialize", (void (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::Initialize, "None");
cls_Adaptor3d_TopolTool.def("Initialize", (void (Adaptor3d_TopolTool::*)(const opencascade::handle<Adaptor3d_HSurface> &)) &Adaptor3d_TopolTool::Initialize, "None", py::arg("S"));
cls_Adaptor3d_TopolTool.def("Initialize", (void (Adaptor3d_TopolTool::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Adaptor3d_TopolTool::Initialize, "None", py::arg("Curve"));
cls_Adaptor3d_TopolTool.def("Init", (void (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::Init, "None");
cls_Adaptor3d_TopolTool.def("More", (Standard_Boolean (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::More, "None");
cls_Adaptor3d_TopolTool.def("Value", (opencascade::handle<Adaptor2d_HCurve2d> (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::Value, "None");
cls_Adaptor3d_TopolTool.def("Next", (void (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::Next, "None");
cls_Adaptor3d_TopolTool.def("InitVertexIterator", (void (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::InitVertexIterator, "None");
cls_Adaptor3d_TopolTool.def("MoreVertex", (Standard_Boolean (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::MoreVertex, "None");
cls_Adaptor3d_TopolTool.def("Vertex", (opencascade::handle<Adaptor3d_HVertex> (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::Vertex, "None");
cls_Adaptor3d_TopolTool.def("NextVertex", (void (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::NextVertex, "None");
cls_Adaptor3d_TopolTool.def("Classify", [](Adaptor3d_TopolTool &self, const gp_Pnt2d & a0, const Standard_Real a1) -> TopAbs_State { return self.Classify(a0, a1); });
cls_Adaptor3d_TopolTool.def("Classify", (TopAbs_State (Adaptor3d_TopolTool::*)(const gp_Pnt2d &, const Standard_Real, const Standard_Boolean)) &Adaptor3d_TopolTool::Classify, "None", py::arg("P"), py::arg("Tol"), py::arg("ReacdreOnPeriodic"));
cls_Adaptor3d_TopolTool.def("IsThePointOn", [](Adaptor3d_TopolTool &self, const gp_Pnt2d & a0, const Standard_Real a1) -> Standard_Boolean { return self.IsThePointOn(a0, a1); });
cls_Adaptor3d_TopolTool.def("IsThePointOn", (Standard_Boolean (Adaptor3d_TopolTool::*)(const gp_Pnt2d &, const Standard_Real, const Standard_Boolean)) &Adaptor3d_TopolTool::IsThePointOn, "None", py::arg("P"), py::arg("Tol"), py::arg("ReacdreOnPeriodic"));
cls_Adaptor3d_TopolTool.def("Orientation", (TopAbs_Orientation (Adaptor3d_TopolTool::*)(const opencascade::handle<Adaptor2d_HCurve2d> &)) &Adaptor3d_TopolTool::Orientation, "If the function returns the orientation of the arc. If the orientation is FORWARD or REVERSED, the arc is a 'real' limit of the surface. If the orientation is INTERNAL or EXTERNAL, the arc is considered as an arc on the surface.", py::arg("C"));
cls_Adaptor3d_TopolTool.def("Orientation", (TopAbs_Orientation (Adaptor3d_TopolTool::*)(const opencascade::handle<Adaptor3d_HVertex> &)) &Adaptor3d_TopolTool::Orientation, "Returns the orientation of the vertex V. The vertex has been found with an exploration on a given arc. The orientation is the orientation of the vertex on this arc.", py::arg("V"));
cls_Adaptor3d_TopolTool.def("Identical", (Standard_Boolean (Adaptor3d_TopolTool::*)(const opencascade::handle<Adaptor3d_HVertex> &, const opencascade::handle<Adaptor3d_HVertex> &)) &Adaptor3d_TopolTool::Identical, "Returns True if the vertices V1 and V2 are identical. This method does not take the orientation of the vertices in account.", py::arg("V1"), py::arg("V2"));
cls_Adaptor3d_TopolTool.def("Has3d", (Standard_Boolean (Adaptor3d_TopolTool::*)() const) &Adaptor3d_TopolTool::Has3d, "answers if arcs and vertices may have 3d representations, so that we could use Tol3d and Pnt methods.");
cls_Adaptor3d_TopolTool.def("Tol3d", (Standard_Real (Adaptor3d_TopolTool::*)(const opencascade::handle<Adaptor2d_HCurve2d> &) const) &Adaptor3d_TopolTool::Tol3d, "returns 3d tolerance of the arc C", py::arg("C"));
cls_Adaptor3d_TopolTool.def("Tol3d", (Standard_Real (Adaptor3d_TopolTool::*)(const opencascade::handle<Adaptor3d_HVertex> &) const) &Adaptor3d_TopolTool::Tol3d, "returns 3d tolerance of the vertex V", py::arg("V"));
cls_Adaptor3d_TopolTool.def("Pnt", (gp_Pnt (Adaptor3d_TopolTool::*)(const opencascade::handle<Adaptor3d_HVertex> &) const) &Adaptor3d_TopolTool::Pnt, "returns 3d point of the vertex V", py::arg("V"));
cls_Adaptor3d_TopolTool.def("ComputeSamplePoints", (void (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::ComputeSamplePoints, "None");
cls_Adaptor3d_TopolTool.def("NbSamplesU", (Standard_Integer (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::NbSamplesU, "compute the sample-points for the intersections algorithms");
cls_Adaptor3d_TopolTool.def("NbSamplesV", (Standard_Integer (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::NbSamplesV, "compute the sample-points for the intersections algorithms");
cls_Adaptor3d_TopolTool.def("NbSamples", (Standard_Integer (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::NbSamples, "compute the sample-points for the intersections algorithms");
cls_Adaptor3d_TopolTool.def("UParameters", (void (Adaptor3d_TopolTool::*)(TColStd_Array1OfReal &) const) &Adaptor3d_TopolTool::UParameters, "return the set of U parameters on the surface obtained by the method SamplePnts", py::arg("theArray"));
cls_Adaptor3d_TopolTool.def("VParameters", (void (Adaptor3d_TopolTool::*)(TColStd_Array1OfReal &) const) &Adaptor3d_TopolTool::VParameters, "return the set of V parameters on the surface obtained by the method SamplePnts", py::arg("theArray"));
cls_Adaptor3d_TopolTool.def("SamplePoint", (void (Adaptor3d_TopolTool::*)(const Standard_Integer, gp_Pnt2d &, gp_Pnt &)) &Adaptor3d_TopolTool::SamplePoint, "None", py::arg("Index"), py::arg("P2d"), py::arg("P3d"));
cls_Adaptor3d_TopolTool.def("DomainIsInfinite", (Standard_Boolean (Adaptor3d_TopolTool::*)()) &Adaptor3d_TopolTool::DomainIsInfinite, "None");
cls_Adaptor3d_TopolTool.def("Edge", (Standard_Address (Adaptor3d_TopolTool::*)() const) &Adaptor3d_TopolTool::Edge, "None");
cls_Adaptor3d_TopolTool.def("SamplePnts", (void (Adaptor3d_TopolTool::*)(const Standard_Real, const Standard_Integer, const Standard_Integer)) &Adaptor3d_TopolTool::SamplePnts, "compute the sample-points for the intersections algorithms by adaptive algorithm for BSpline surfaces. For other surfaces algorithm is the same as in method ComputeSamplePoints(), but only fill arrays of U and V sample parameters; theDefl is a requred deflection theNUmin, theNVmin are minimal nb points for U and V.", py::arg("theDefl"), py::arg("theNUmin"), py::arg("theNVmin"));
cls_Adaptor3d_TopolTool.def("BSplSamplePnts", (void (Adaptor3d_TopolTool::*)(const Standard_Real, const Standard_Integer, const Standard_Integer)) &Adaptor3d_TopolTool::BSplSamplePnts, "compute the sample-points for the intersections algorithms by adaptive algorithm for BSpline surfaces - is used in SamplePnts theDefl is a requred deflection theNUmin, theNVmin are minimal nb points for U and V.", py::arg("theDefl"), py::arg("theNUmin"), py::arg("theNVmin"));
cls_Adaptor3d_TopolTool.def("IsUniformSampling", (Standard_Boolean (Adaptor3d_TopolTool::*)() const) &Adaptor3d_TopolTool::IsUniformSampling, "Returns true if provide uniform sampling of points.");
cls_Adaptor3d_TopolTool.def_static("get_type_name_", (const char * (*)()) &Adaptor3d_TopolTool::get_type_name, "None");
cls_Adaptor3d_TopolTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Adaptor3d_TopolTool::get_type_descriptor, "None");
cls_Adaptor3d_TopolTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (Adaptor3d_TopolTool::*)() const) &Adaptor3d_TopolTool::DynamicType, "None");

// Enums

}