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
#include <AIS_RubberBand.hxx>
#include <Standard_Type.hxx>
#include <Quantity_Color.hxx>
#include <Aspect_TypeOfLine.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_Vec2.hxx>
#include <NCollection_Sequence.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_Presentation.hxx>
#include <SelectMgr_Selection.hxx>
#include <Graphic3d_ArrayOfTriangles.hxx>
#include <Graphic3d_ArrayOfPolylines.hxx>

void bind_AIS_RubberBand(py::module &mod){

py::class_<AIS_RubberBand, opencascade::handle<AIS_RubberBand>, AIS_InteractiveObject> cls_AIS_RubberBand(mod, "AIS_RubberBand", "Presentation for drawing rubber band selection. It supports rectangle and polygonal selection. It is constructed in 2d overlay. Default configaration is built without filling. For rectangle selection use SetRectangle() method. For polygonal selection use AddPoint() and GetPoints() methods.");

// Constructors
cls_AIS_RubberBand.def(py::init<>());
cls_AIS_RubberBand.def(py::init<const Quantity_Color &, const Aspect_TypeOfLine>(), py::arg("theLineColor"), py::arg("theType"));
cls_AIS_RubberBand.def(py::init<const Quantity_Color &, const Aspect_TypeOfLine, const Standard_Real>(), py::arg("theLineColor"), py::arg("theType"), py::arg("theLineWidth"));
cls_AIS_RubberBand.def(py::init<const Quantity_Color &, const Aspect_TypeOfLine, const Standard_Real, const Standard_Boolean>(), py::arg("theLineColor"), py::arg("theType"), py::arg("theLineWidth"), py::arg("theIsPolygonClosed"));
cls_AIS_RubberBand.def(py::init<const Quantity_Color &, const Aspect_TypeOfLine, const Quantity_Color>(), py::arg("theLineColor"), py::arg("theType"), py::arg("theFillColor"));
cls_AIS_RubberBand.def(py::init<const Quantity_Color &, const Aspect_TypeOfLine, const Quantity_Color, const Standard_Real>(), py::arg("theLineColor"), py::arg("theType"), py::arg("theFillColor"), py::arg("theTransparency"));
cls_AIS_RubberBand.def(py::init<const Quantity_Color &, const Aspect_TypeOfLine, const Quantity_Color, const Standard_Real, const Standard_Real>(), py::arg("theLineColor"), py::arg("theType"), py::arg("theFillColor"), py::arg("theTransparency"), py::arg("theLineWidth"));
cls_AIS_RubberBand.def(py::init<const Quantity_Color &, const Aspect_TypeOfLine, const Quantity_Color, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("theLineColor"), py::arg("theType"), py::arg("theFillColor"), py::arg("theTransparency"), py::arg("theLineWidth"), py::arg("theIsPolygonClosed"));

// Fields

// Methods
cls_AIS_RubberBand.def_static("get_type_name_", (const char * (*)()) &AIS_RubberBand::get_type_name, "None");
cls_AIS_RubberBand.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_RubberBand::get_type_descriptor, "None");
cls_AIS_RubberBand.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_RubberBand::*)() const) &AIS_RubberBand::DynamicType, "None");
cls_AIS_RubberBand.def("SetRectangle", (void (AIS_RubberBand::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &AIS_RubberBand::SetRectangle, "Sets rectangle bounds.", py::arg("theMinX"), py::arg("theMinY"), py::arg("theMaxX"), py::arg("theMaxY"));
cls_AIS_RubberBand.def("AddPoint", (void (AIS_RubberBand::*)(const Graphic3d_Vec2i &)) &AIS_RubberBand::AddPoint, "Adds last point to the list of points. They are used to build polygon for rubber band.", py::arg("thePoint"));
cls_AIS_RubberBand.def("RemoveLastPoint", (void (AIS_RubberBand::*)()) &AIS_RubberBand::RemoveLastPoint, "Remove last point from the list of points for the rubber band polygon.");
cls_AIS_RubberBand.def("Points", (const NCollection_Sequence<Graphic3d_Vec2i> & (AIS_RubberBand::*)() const) &AIS_RubberBand::Points, "Returns points for the rubber band polygon.");
cls_AIS_RubberBand.def("ClearPoints", (void (AIS_RubberBand::*)()) &AIS_RubberBand::ClearPoints, "Remove all points for the rubber band polygon.");
cls_AIS_RubberBand.def("LineColor", (Quantity_Color (AIS_RubberBand::*)() const) &AIS_RubberBand::LineColor, "Returns the Color attributes.");
cls_AIS_RubberBand.def("SetLineColor", (void (AIS_RubberBand::*)(const Quantity_Color &)) &AIS_RubberBand::SetLineColor, "Sets color of lines for rubber band presentation.", py::arg("theColor"));
cls_AIS_RubberBand.def("FillColor", (Quantity_Color (AIS_RubberBand::*)() const) &AIS_RubberBand::FillColor, "Returns the color of rubber band filling.");
cls_AIS_RubberBand.def("SetFillColor", (void (AIS_RubberBand::*)(const Quantity_Color &)) &AIS_RubberBand::SetFillColor, "Sets color of rubber band filling.", py::arg("theColor"));
cls_AIS_RubberBand.def("SetLineWidth", (void (AIS_RubberBand::*)(const Standard_Real) const) &AIS_RubberBand::SetLineWidth, "Sets width of line for rubber band presentation.", py::arg("theWidth"));
cls_AIS_RubberBand.def("LineWidth", (Standard_Real (AIS_RubberBand::*)() const) &AIS_RubberBand::LineWidth, "Returns width of lines.");
cls_AIS_RubberBand.def("SetLineType", (void (AIS_RubberBand::*)(const Aspect_TypeOfLine)) &AIS_RubberBand::SetLineType, "Sets type of line for rubber band presentation.", py::arg("theType"));
cls_AIS_RubberBand.def("LineType", (Aspect_TypeOfLine (AIS_RubberBand::*)() const) &AIS_RubberBand::LineType, "Returns type of lines.");
cls_AIS_RubberBand.def("SetFillTransparency", (void (AIS_RubberBand::*)(const Standard_Real) const) &AIS_RubberBand::SetFillTransparency, "Sets fill transparency.", py::arg("theValue"));
cls_AIS_RubberBand.def("FillTransparency", (Standard_Real (AIS_RubberBand::*)() const) &AIS_RubberBand::FillTransparency, "Returns fill transparency.");
cls_AIS_RubberBand.def("SetFilling", (void (AIS_RubberBand::*)(const Standard_Boolean)) &AIS_RubberBand::SetFilling, "Enable or disable filling of rubber band.", py::arg("theIsFilling"));
cls_AIS_RubberBand.def("SetFilling", (void (AIS_RubberBand::*)(const Quantity_Color, const Standard_Real)) &AIS_RubberBand::SetFilling, "Enable filling of rubber band with defined parameters.", py::arg("theColor"), py::arg("theTransparency"));
cls_AIS_RubberBand.def("IsFilling", (Standard_Boolean (AIS_RubberBand::*)() const) &AIS_RubberBand::IsFilling, "Returns true if filling of rubber band is enabled.");
cls_AIS_RubberBand.def("IsPolygonClosed", (Standard_Boolean (AIS_RubberBand::*)() const) &AIS_RubberBand::IsPolygonClosed, "Returns true if automatic closing of rubber band is enabled.");
cls_AIS_RubberBand.def("SetPolygonClosed", (void (AIS_RubberBand::*)(Standard_Boolean)) &AIS_RubberBand::SetPolygonClosed, "Automatically create an additional line connecting the first and the last screen points to close the boundary polyline", py::arg("theIsPolygonClosed"));

// Enums

}