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
#include <AIS_InteractiveObject.hxx>
#include <Standard_Handle.hxx>
#include <AIS_Relation.hxx>
#include <Standard_Type.hxx>
#include <Quantity_Color.hxx>
#include <AIS_KindOfInteractive.hxx>
#include <AIS_KindOfDimension.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <Geom_Plane.hxx>
#include <gp_Pnt.hxx>
#include <TCollection_ExtendedString.hxx>
#include <DsgPrs_ArrowSide.hxx>
#include <PrsMgr_TypeOfPresentation3d.hxx>
#include <Prs3d_Presentation.hxx>
#include <TopoDS_Edge.hxx>
#include <Geom_Curve.hxx>
#include <Quantity_NameOfColor.hxx>
#include <Aspect_TypeOfLine.hxx>
#include <TopoDS_Vertex.hxx>
#include <Aspect_TypeOfMarker.hxx>
#include <gp_Pln.hxx>
#include <Geom_Surface.hxx>
#include <AIS_KindOfSurface.hxx>
#include <Bnd_Box.hxx>

void bind_AIS_Relation(py::module &mod){

py::class_<AIS_Relation, opencascade::handle<AIS_Relation>, AIS_InteractiveObject> cls_AIS_Relation(mod, "AIS_Relation", "One of the four types of interactive object in AIS,comprising dimensions and constraints. Serves as the abstract class for the seven relation classes as well as the seven dimension classes. The statuses available for relations between shapes are as follows: - 0 - there is no connection to a shape; - 1 - there is a connection to the first shape; - 2 - there is a connection to the second shape. The connection takes the form of an edge between the two shapes.");

// Fields

// Methods
cls_AIS_Relation.def_static("get_type_name_", (const char * (*)()) &AIS_Relation::get_type_name, "None");
cls_AIS_Relation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Relation::get_type_descriptor, "None");
cls_AIS_Relation.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Relation::*)() const) &AIS_Relation::DynamicType, "None");
cls_AIS_Relation.def("SetColor", (void (AIS_Relation::*)(const Quantity_Color &)) &AIS_Relation::SetColor, "Allows you to provide settings for the color theColor of the lines representing the relation between the two shapes.", py::arg("theColor"));
cls_AIS_Relation.def("UnsetColor", (void (AIS_Relation::*)()) &AIS_Relation::UnsetColor, "Allows you to remove settings for the color of the lines representing the relation between the two shapes.");
cls_AIS_Relation.def("Type", (AIS_KindOfInteractive (AIS_Relation::*)() const) &AIS_Relation::Type, "None");
cls_AIS_Relation.def("KindOfDimension", (AIS_KindOfDimension (AIS_Relation::*)() const) &AIS_Relation::KindOfDimension, "Indicates that the type of dimension is unknown.");
cls_AIS_Relation.def("IsMovable", (Standard_Boolean (AIS_Relation::*)() const) &AIS_Relation::IsMovable, "Returns true if the interactive object is movable.");
cls_AIS_Relation.def("FirstShape", (const TopoDS_Shape & (AIS_Relation::*)() const) &AIS_Relation::FirstShape, "None");
cls_AIS_Relation.def("SetFirstShape", (void (AIS_Relation::*)(const TopoDS_Shape &)) &AIS_Relation::SetFirstShape, "None", py::arg("aFShape"));
cls_AIS_Relation.def("SecondShape", (const TopoDS_Shape & (AIS_Relation::*)() const) &AIS_Relation::SecondShape, "Returns the second shape.");
cls_AIS_Relation.def("SetSecondShape", (void (AIS_Relation::*)(const TopoDS_Shape &)) &AIS_Relation::SetSecondShape, "Allows you to identify the second shape aSShape relative to the first.", py::arg("aSShape"));
cls_AIS_Relation.def("SetBndBox", (void (AIS_Relation::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &AIS_Relation::SetBndBox, "None", py::arg("theXmin"), py::arg("theYmin"), py::arg("theZmin"), py::arg("theXmax"), py::arg("theYmax"), py::arg("theZmax"));
cls_AIS_Relation.def("UnsetBndBox", (void (AIS_Relation::*)()) &AIS_Relation::UnsetBndBox, "None");
cls_AIS_Relation.def("Plane", (const opencascade::handle<Geom_Plane> & (AIS_Relation::*)() const) &AIS_Relation::Plane, "Returns the plane.");
cls_AIS_Relation.def("SetPlane", (void (AIS_Relation::*)(const opencascade::handle<Geom_Plane> &)) &AIS_Relation::SetPlane, "Allows you to set the plane thePlane. This is used to define relations and dimensions in several daughter classes.", py::arg("thePlane"));
cls_AIS_Relation.def("Value", (Standard_Real (AIS_Relation::*)() const) &AIS_Relation::Value, "Returns the value of each object in the relation.");
cls_AIS_Relation.def("SetValue", (void (AIS_Relation::*)(const Standard_Real)) &AIS_Relation::SetValue, "Allows you to provide settings for the value theVal for each object in the relation.", py::arg("theVal"));
cls_AIS_Relation.def("Position", (const gp_Pnt & (AIS_Relation::*)() const) &AIS_Relation::Position, "Returns the position set using SetPosition.");
cls_AIS_Relation.def("SetPosition", (void (AIS_Relation::*)(const gp_Pnt &)) &AIS_Relation::SetPosition, "Allows you to provide the objects in the relation with settings for a non-default position.", py::arg("thePosition"));
cls_AIS_Relation.def("Text", (const TCollection_ExtendedString & (AIS_Relation::*)() const) &AIS_Relation::Text, "Returns settings for text aspect.");
cls_AIS_Relation.def("SetText", (void (AIS_Relation::*)(const TCollection_ExtendedString &)) &AIS_Relation::SetText, "Allows you to provide the settings theText for text aspect.", py::arg("theText"));
cls_AIS_Relation.def("ArrowSize", (Standard_Real (AIS_Relation::*)() const) &AIS_Relation::ArrowSize, "Returns the value for the size of the arrow identifying the relation between the two shapes.");
cls_AIS_Relation.def("SetArrowSize", (void (AIS_Relation::*)(const Standard_Real)) &AIS_Relation::SetArrowSize, "Allows you to provide settings for the size of the arrow theArrowSize identifying the relation between the two shapes.", py::arg("theArrowSize"));
cls_AIS_Relation.def("SymbolPrs", (DsgPrs_ArrowSide (AIS_Relation::*)() const) &AIS_Relation::SymbolPrs, "Returns the value of the symbol presentation. This will be one of: - AS_NONE - none - AS_FIRSTAR - first arrow - AS_LASTAR - last arrow - AS_BOTHAR - both arrows - AS_FIRSTPT - first point - AS_LASTPT - last point - AS_BOTHPT - both points - AS_FIRSTAR_LASTPT - first arrow, last point - AS_FIRSTPT_LASTAR - first point, last arrow");
cls_AIS_Relation.def("SetSymbolPrs", (void (AIS_Relation::*)(const DsgPrs_ArrowSide)) &AIS_Relation::SetSymbolPrs, "Allows you to provide settings for the symbol presentation.", py::arg("theSymbolPrs"));
cls_AIS_Relation.def("SetExtShape", (void (AIS_Relation::*)(const Standard_Integer)) &AIS_Relation::SetExtShape, "Allows you to set the status of the extension shape by the index aIndex. The status will be one of the following: - 0 - there is no connection to a shape; - 1 - there is a connection to the first shape; - 2 - there is a connection to the second shape.", py::arg("theIndex"));
cls_AIS_Relation.def("ExtShape", (Standard_Integer (AIS_Relation::*)() const) &AIS_Relation::ExtShape, "Returns the status index of the extension shape.");
cls_AIS_Relation.def("AcceptDisplayMode", (Standard_Boolean (AIS_Relation::*)(const Standard_Integer) const) &AIS_Relation::AcceptDisplayMode, "Returns true if the display mode aMode is accepted for the Interactive Objects in the relation. ComputeProjPresentation(me; aPres : Presentation from Prs3d; Curve1 : Curve from Geom; Curve2 : Curve from Geom; FirstP1 : Pnt from gp; LastP1 : Pnt from gp; FirstP2 : Pnt from gp; LastP2 : Pnt from gp; aColor : NameOfColor from Quantity = Quantity_NOC_PURPLE; aWidth : Real from Standard = 2; aProjTOL : TypeOfLine from Aspect = Aspect_TOL_DASH; aCallTOL : TypeOfLine from Aspect = Aspect_TOL_DOT)", py::arg("aMode"));
cls_AIS_Relation.def("SetAutomaticPosition", (void (AIS_Relation::*)(const Standard_Boolean)) &AIS_Relation::SetAutomaticPosition, "None", py::arg("theStatus"));
cls_AIS_Relation.def("AutomaticPosition", (Standard_Boolean (AIS_Relation::*)() const) &AIS_Relation::AutomaticPosition, "None");

// Enums

}