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
#include <AIS_Line.hxx>
#include <Standard_Type.hxx>
#include <Geom_Line.hxx>
#include <Geom_Point.hxx>
#include <Prs3d_Projector.hxx>
#include <Geom_Transformation.hxx>
#include <Prs3d_Presentation.hxx>
#include <Standard_TypeDef.hxx>
#include <AIS_KindOfInteractive.hxx>
#include <Quantity_Color.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <SelectMgr_Selection.hxx>

void bind_AIS_Line(py::module &mod){

py::class_<AIS_Line, opencascade::handle<AIS_Line>, AIS_InteractiveObject> cls_AIS_Line(mod, "AIS_Line", "Constructs line datums to be used in construction of composite shapes.");

// Constructors
cls_AIS_Line.def(py::init<const opencascade::handle<Geom_Line> &>(), py::arg("aLine"));
cls_AIS_Line.def(py::init<const opencascade::handle<Geom_Point> &, const opencascade::handle<Geom_Point> &>(), py::arg("aStartPoint"), py::arg("aEndPoint"));

// Fields

// Methods
cls_AIS_Line.def_static("get_type_name_", (const char * (*)()) &AIS_Line::get_type_name, "None");
cls_AIS_Line.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Line::get_type_descriptor, "None");
cls_AIS_Line.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Line::*)() const) &AIS_Line::DynamicType, "None");
cls_AIS_Line.def("Compute", (void (AIS_Line::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_Line::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));
cls_AIS_Line.def("Signature", (Standard_Integer (AIS_Line::*)() const) &AIS_Line::Signature, "Returns the signature 5.");
cls_AIS_Line.def("Type", (AIS_KindOfInteractive (AIS_Line::*)() const) &AIS_Line::Type, "Returns the type Datum.");
cls_AIS_Line.def("Line", (const opencascade::handle<Geom_Line> & (AIS_Line::*)() const) &AIS_Line::Line, "Constructs an infinite line.");
cls_AIS_Line.def("Points", (void (AIS_Line::*)(opencascade::handle<Geom_Point> &, opencascade::handle<Geom_Point> &) const) &AIS_Line::Points, "Returns the starting point thePStart and the end point thePEnd of the line set by SetPoints.", py::arg("thePStart"), py::arg("thePEnd"));
cls_AIS_Line.def("SetLine", (void (AIS_Line::*)(const opencascade::handle<Geom_Line> &)) &AIS_Line::SetLine, "instantiates an infinite line.", py::arg("theLine"));
cls_AIS_Line.def("SetPoints", (void (AIS_Line::*)(const opencascade::handle<Geom_Point> &, const opencascade::handle<Geom_Point> &)) &AIS_Line::SetPoints, "Sets the starting point thePStart and ending point thePEnd of the infinite line to create a finite line segment.", py::arg("thePStart"), py::arg("thePEnd"));
cls_AIS_Line.def("SetColor", (void (AIS_Line::*)(const Quantity_Color &)) &AIS_Line::SetColor, "Provides a new color setting aColor for the line in the drawing tool, or 'Drawer'.", py::arg("aColor"));
cls_AIS_Line.def("SetWidth", (void (AIS_Line::*)(const Standard_Real)) &AIS_Line::SetWidth, "Provides the new width setting aValue for the line in the drawing tool, or 'Drawer'.", py::arg("aValue"));
cls_AIS_Line.def("UnsetColor", (void (AIS_Line::*)()) &AIS_Line::UnsetColor, "Removes the color setting and returns the original color.");
cls_AIS_Line.def("UnsetWidth", (void (AIS_Line::*)()) &AIS_Line::UnsetWidth, "Removes the width setting and returns the original width.");

// Enums

}