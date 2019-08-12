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
#include <AIS_Relation.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Plane.hxx>
#include <Prs3d_Projector.hxx>
#include <Geom_Transformation.hxx>
#include <Prs3d_Presentation.hxx>
#include <Prs3d_Drawer.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <Bnd_Box.hxx>
#include <gp_Pnt.hxx>
#include <DsgPrs_ArrowSide.hxx>
#include <TopoDS_Vertex.hxx>
#include <AIS_TypeOfDist.hxx>
#include <AIS_EqualDistanceRelation.hxx>
#include <Standard_Type.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <SelectMgr_Selection.hxx>

void bind_AIS_EqualDistanceRelation(py::module &mod){

py::class_<AIS_EqualDistanceRelation, opencascade::handle<AIS_EqualDistanceRelation>, AIS_Relation> cls_AIS_EqualDistanceRelation(mod, "AIS_EqualDistanceRelation", "A framework to display equivalent distances between shapes and a given plane. The distance is the length of a projection from the shape to the plane. These distances are used to compare shapes by this vector alone.");

// Constructors
cls_AIS_EqualDistanceRelation.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &>(), py::arg("aShape1"), py::arg("aShape2"), py::arg("aShape3"), py::arg("aShape4"), py::arg("aPlane"));

// Fields

// Methods
cls_AIS_EqualDistanceRelation.def("SetShape3", (void (AIS_EqualDistanceRelation::*)(const TopoDS_Shape &)) &AIS_EqualDistanceRelation::SetShape3, "Sets the shape aShape to be used as the shape aShape3 in the framework created at construction time.", py::arg("aShape"));
cls_AIS_EqualDistanceRelation.def("Shape3", (const TopoDS_Shape & (AIS_EqualDistanceRelation::*)() const) &AIS_EqualDistanceRelation::Shape3, "Returns the shape aShape3 from the framework created at construction time.");
cls_AIS_EqualDistanceRelation.def("SetShape4", (void (AIS_EqualDistanceRelation::*)(const TopoDS_Shape &)) &AIS_EqualDistanceRelation::SetShape4, "Sets the shape aShape to be used as the shape aShape4 in the framework created at construction time.", py::arg("aShape"));
cls_AIS_EqualDistanceRelation.def("Shape4", (const TopoDS_Shape & (AIS_EqualDistanceRelation::*)() const) &AIS_EqualDistanceRelation::Shape4, "Returns the shape aShape4 from the framework created at construction time.");
cls_AIS_EqualDistanceRelation.def("Compute", (void (AIS_EqualDistanceRelation::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_EqualDistanceRelation::Compute, "Computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));
cls_AIS_EqualDistanceRelation.def_static("ComputeTwoEdgesLength_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const TopoDS_Edge &, const TopoDS_Edge &, const opencascade::handle<Geom_Plane> &, const Standard_Boolean, const Standard_Boolean, const Bnd_Box &, gp_Pnt &, gp_Pnt &, gp_Pnt &, gp_Pnt &, gp_Pnt &, DsgPrs_ArrowSide &)) &AIS_EqualDistanceRelation::ComputeTwoEdgesLength, "Computes the location of an intreval between between two edges. FirstAttach , SecondAttach are the returned extreme points of the interval.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("ArrowSize"), py::arg("FirstEdge"), py::arg("SecondEdge"), py::arg("Plane"), py::arg("AutomaticPos"), py::arg("IsSetBndBox"), py::arg("BndBox"), py::arg("Position"), py::arg("FirstAttach"), py::arg("SecondAttach"), py::arg("FirstExtreme"), py::arg("SecondExtreme"), py::arg("SymbolPrs"));
cls_AIS_EqualDistanceRelation.def_static("ComputeTwoVerticesLength_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const TopoDS_Vertex &, const TopoDS_Vertex &, const opencascade::handle<Geom_Plane> &, const Standard_Boolean, const Standard_Boolean, const Bnd_Box &, const AIS_TypeOfDist, gp_Pnt &, gp_Pnt &, gp_Pnt &, gp_Pnt &, gp_Pnt &, DsgPrs_ArrowSide &)) &AIS_EqualDistanceRelation::ComputeTwoVerticesLength, "Computes the interval position between two vertexs. FirstAttach, SecondAttach are the returned extreme points of the interval.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("ArrowSize"), py::arg("FirstVertex"), py::arg("SecondVertex"), py::arg("Plane"), py::arg("AutomaticPos"), py::arg("IsSetBndBox"), py::arg("BndBox"), py::arg("TypeDist"), py::arg("Position"), py::arg("FirstAttach"), py::arg("SecondAttach"), py::arg("FirstExtreme"), py::arg("SecondExtreme"), py::arg("SymbolPrs"));
cls_AIS_EqualDistanceRelation.def_static("ComputeOneEdgeOneVertexLength_", (void (*)(const opencascade::handle<Prs3d_Presentation> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Real, const TopoDS_Shape &, const TopoDS_Shape &, const opencascade::handle<Geom_Plane> &, const Standard_Boolean, const Standard_Boolean, const Bnd_Box &, gp_Pnt &, gp_Pnt &, gp_Pnt &, gp_Pnt &, gp_Pnt &, DsgPrs_ArrowSide &)) &AIS_EqualDistanceRelation::ComputeOneEdgeOneVertexLength, "Compute the interval location between a vertex and an edge. Edge may be a line or a circle.", py::arg("aPresentation"), py::arg("aDrawer"), py::arg("ArrowSize"), py::arg("FirstShape"), py::arg("SecondShape"), py::arg("Plane"), py::arg("AutomaticPos"), py::arg("IsSetBndBox"), py::arg("BndBox"), py::arg("Position"), py::arg("FirstAttach"), py::arg("SecondAttach"), py::arg("FirstExtreme"), py::arg("SecondExtreme"), py::arg("SymbolPrs"));
cls_AIS_EqualDistanceRelation.def_static("get_type_name_", (const char * (*)()) &AIS_EqualDistanceRelation::get_type_name, "None");
cls_AIS_EqualDistanceRelation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_EqualDistanceRelation::get_type_descriptor, "None");
cls_AIS_EqualDistanceRelation.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_EqualDistanceRelation::*)() const) &AIS_EqualDistanceRelation::DynamicType, "None");

// Enums

}