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
#include <HLRBRep_PolyAlgo.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <HLRAlgo_PolyAlgo.hxx>
#include <HLRAlgo_Projector.hxx>
#include <HLRAlgo_BiPoint.hxx>
#include <HLRAlgo_EdgeStatus.hxx>
#include <Standard_Type.hxx>
#include <TColStd_Array1OfTransient.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TopTools_MapOfShape.hxx>
#include <HLRAlgo_PolyInternalNode.hxx>
#include <HLRAlgo_Array1OfTData.hxx>
#include <HLRAlgo_Array1OfPISeg.hxx>
#include <HLRAlgo_Array1OfPINod.hxx>
#include <gp_XYZ.hxx>
#include <TopoDS_Edge.hxx>
#include <HLRAlgo_ListOfBPoint.hxx>
#include <TopTools_ListOfShape.hxx>
#include <HLRAlgo_PolyInternalData.hxx>
#include <GeomAbs_Shape.hxx>
#include <HLRAlgo_TriangleData.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <Geom_Surface.hxx>
#include <BRepAdaptor_Surface.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <BRepAdaptor_Curve2d.hxx>

void bind_HLRBRep_PolyAlgo(py::module &mod){

py::class_<HLRBRep_PolyAlgo, opencascade::handle<HLRBRep_PolyAlgo>, Standard_Transient> cls_HLRBRep_PolyAlgo(mod, "HLRBRep_PolyAlgo", "to remove Hidden lines on Shapes with Triangulations. A framework to compute the shape as seen in a projection plane. This is done by calculating the visible and the hidden parts of the shape. HLRBRep_PolyAlgo works with three types of entity: - shapes to be visualized (these shapes must have already been triangulated.) - edges in these shapes (these edges are defined as polygonal lines on the triangulation of the shape, and are the basic entities which will be visualized or hidden), and - triangles in these shapes which hide the edges. HLRBRep_PolyAlgo is based on the principle of comparing each edge of the shape to be visualized with each of the triangles produced by the triangulation of the shape, and calculating the visible and the hidden parts of each edge. For a given projection, HLRBRep_PolyAlgo calculates a set of lines characteristic of the object being represented. It is also used in conjunction with the HLRBRep_PolyHLRToShape extraction utilities, which reconstruct a new, simplified shape from a selection of calculation results. This new shape is made up of edges, which represent the shape visualized in the projection. HLRBRep_PolyAlgo works with a polyhedral simplification of the shape whereas HLRBRep_Algo takes the shape itself into account. When you use HLRBRep_Algo, you obtain an exact result, whereas, when you use HLRBRep_PolyAlgo, you reduce computation time but obtain polygonal segments. An HLRBRep_PolyAlgo object provides a framework for: - defining the point of view - identifying the shape or shapes to be visualized - calculating the outlines - calculating the visible and hidden lines of the shape. Warning - Superimposed lines are not eliminated by this algorithm. - There must be no unfinished objects inside the shape you wish to visualize. - Points are not treated. - Note that this is not the sort of algorithm used in generating shading, which calculates the visible and hidden parts of each face in a shape to be visualized by comparing each face in the shape with every other face in the same shape.");

// Constructors
cls_HLRBRep_PolyAlgo.def(py::init<>());
cls_HLRBRep_PolyAlgo.def(py::init<const opencascade::handle<HLRBRep_PolyAlgo> &>(), py::arg("A"));
cls_HLRBRep_PolyAlgo.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Fields

// Methods
cls_HLRBRep_PolyAlgo.def("NbShapes", (Standard_Integer (HLRBRep_PolyAlgo::*)() const) &HLRBRep_PolyAlgo::NbShapes, "None");
cls_HLRBRep_PolyAlgo.def("Shape", (TopoDS_Shape & (HLRBRep_PolyAlgo::*)(const Standard_Integer)) &HLRBRep_PolyAlgo::Shape, "None", py::arg("I"));
cls_HLRBRep_PolyAlgo.def("Remove", (void (HLRBRep_PolyAlgo::*)(const Standard_Integer)) &HLRBRep_PolyAlgo::Remove, "remove the Shape of Index <I>.", py::arg("I"));
cls_HLRBRep_PolyAlgo.def("Index", (Standard_Integer (HLRBRep_PolyAlgo::*)(const TopoDS_Shape &) const) &HLRBRep_PolyAlgo::Index, "return the index of the Shape <S> and return 0 if the Shape <S> is not found.", py::arg("S"));
cls_HLRBRep_PolyAlgo.def("Load", (void (HLRBRep_PolyAlgo::*)(const TopoDS_Shape &)) &HLRBRep_PolyAlgo::Load, "Loads the shape S into this framework. Warning S must have already been triangulated.", py::arg("S"));
cls_HLRBRep_PolyAlgo.def("Algo", (opencascade::handle<HLRAlgo_PolyAlgo> (HLRBRep_PolyAlgo::*)() const) &HLRBRep_PolyAlgo::Algo, "None");
cls_HLRBRep_PolyAlgo.def("Projector", (const HLRAlgo_Projector & (HLRBRep_PolyAlgo::*)() const) &HLRBRep_PolyAlgo::Projector, "Sets the parameters of the view for this framework. These parameters are defined by an HLRAlgo_Projector object, which is returned by the Projector function on a Prs3d_Projector object.");
cls_HLRBRep_PolyAlgo.def("Projector", (void (HLRBRep_PolyAlgo::*)(const HLRAlgo_Projector &)) &HLRBRep_PolyAlgo::Projector, "None", py::arg("P"));
cls_HLRBRep_PolyAlgo.def("Angle", (Standard_Real (HLRBRep_PolyAlgo::*)() const) &HLRBRep_PolyAlgo::Angle, "None");
cls_HLRBRep_PolyAlgo.def("Angle", (void (HLRBRep_PolyAlgo::*)(const Standard_Real)) &HLRBRep_PolyAlgo::Angle, "None", py::arg("Ang"));
cls_HLRBRep_PolyAlgo.def("TolAngular", (Standard_Real (HLRBRep_PolyAlgo::*)() const) &HLRBRep_PolyAlgo::TolAngular, "None");
cls_HLRBRep_PolyAlgo.def("TolAngular", (void (HLRBRep_PolyAlgo::*)(const Standard_Real)) &HLRBRep_PolyAlgo::TolAngular, "None", py::arg("Tol"));
cls_HLRBRep_PolyAlgo.def("TolCoef", (Standard_Real (HLRBRep_PolyAlgo::*)() const) &HLRBRep_PolyAlgo::TolCoef, "None");
cls_HLRBRep_PolyAlgo.def("TolCoef", (void (HLRBRep_PolyAlgo::*)(const Standard_Real)) &HLRBRep_PolyAlgo::TolCoef, "None", py::arg("Tol"));
cls_HLRBRep_PolyAlgo.def("Update", (void (HLRBRep_PolyAlgo::*)()) &HLRBRep_PolyAlgo::Update, "Launches calculation of outlines of the shape visualized by this framework. Used after setting the point of view and defining the shape or shapes to be visualized.");
cls_HLRBRep_PolyAlgo.def("InitHide", (void (HLRBRep_PolyAlgo::*)()) &HLRBRep_PolyAlgo::InitHide, "None");
cls_HLRBRep_PolyAlgo.def("MoreHide", (Standard_Boolean (HLRBRep_PolyAlgo::*)() const) &HLRBRep_PolyAlgo::MoreHide, "None");
cls_HLRBRep_PolyAlgo.def("NextHide", (void (HLRBRep_PolyAlgo::*)()) &HLRBRep_PolyAlgo::NextHide, "None");
cls_HLRBRep_PolyAlgo.def("Hide", [](HLRBRep_PolyAlgo &self, HLRAlgo_EdgeStatus & status, TopoDS_Shape & S, Standard_Boolean & reg1, Standard_Boolean & regn, Standard_Boolean & outl, Standard_Boolean & intl){ HLRAlgo_BiPoint::PointsT & rv = self.Hide(status, S, reg1, regn, outl, intl); return std::tuple<HLRAlgo_BiPoint::PointsT &, Standard_Boolean &, Standard_Boolean &, Standard_Boolean &, Standard_Boolean &>(rv, reg1, regn, outl, intl); }, "None", py::arg("status"), py::arg("S"), py::arg("reg1"), py::arg("regn"), py::arg("outl"), py::arg("intl"));
cls_HLRBRep_PolyAlgo.def("InitShow", (void (HLRBRep_PolyAlgo::*)()) &HLRBRep_PolyAlgo::InitShow, "None");
cls_HLRBRep_PolyAlgo.def("MoreShow", (Standard_Boolean (HLRBRep_PolyAlgo::*)() const) &HLRBRep_PolyAlgo::MoreShow, "None");
cls_HLRBRep_PolyAlgo.def("NextShow", (void (HLRBRep_PolyAlgo::*)()) &HLRBRep_PolyAlgo::NextShow, "None");
cls_HLRBRep_PolyAlgo.def("Show", [](HLRBRep_PolyAlgo &self, TopoDS_Shape & S, Standard_Boolean & reg1, Standard_Boolean & regn, Standard_Boolean & outl, Standard_Boolean & intl){ HLRAlgo_BiPoint::PointsT & rv = self.Show(S, reg1, regn, outl, intl); return std::tuple<HLRAlgo_BiPoint::PointsT &, Standard_Boolean &, Standard_Boolean &, Standard_Boolean &, Standard_Boolean &>(rv, reg1, regn, outl, intl); }, "None", py::arg("S"), py::arg("reg1"), py::arg("regn"), py::arg("outl"), py::arg("intl"));
cls_HLRBRep_PolyAlgo.def("OutLinedShape", (TopoDS_Shape (HLRBRep_PolyAlgo::*)(const TopoDS_Shape &) const) &HLRBRep_PolyAlgo::OutLinedShape, "Make a shape with the internal outlines in each face.", py::arg("S"));
cls_HLRBRep_PolyAlgo.def("Debug", (Standard_Boolean (HLRBRep_PolyAlgo::*)() const) &HLRBRep_PolyAlgo::Debug, "None");
cls_HLRBRep_PolyAlgo.def("Debug", (void (HLRBRep_PolyAlgo::*)(const Standard_Boolean)) &HLRBRep_PolyAlgo::Debug, "None", py::arg("B"));
cls_HLRBRep_PolyAlgo.def_static("get_type_name_", (const char * (*)()) &HLRBRep_PolyAlgo::get_type_name, "None");
cls_HLRBRep_PolyAlgo.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRBRep_PolyAlgo::get_type_descriptor, "None");
cls_HLRBRep_PolyAlgo.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRBRep_PolyAlgo::*)() const) &HLRBRep_PolyAlgo::DynamicType, "None");

// Enums

}