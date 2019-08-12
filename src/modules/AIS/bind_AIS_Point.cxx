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
#include <AIS_Point.hxx>
#include <Standard_Type.hxx>
#include <Geom_Point.hxx>
#include <Standard_TypeDef.hxx>
#include <AIS_KindOfInteractive.hxx>
#include <Prs3d_Projector.hxx>
#include <Geom_Transformation.hxx>
#include <Prs3d_Presentation.hxx>
#include <Quantity_Color.hxx>
#include <Aspect_TypeOfMarker.hxx>
#include <TopoDS_Vertex.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <SelectMgr_Selection.hxx>

void bind_AIS_Point(py::module &mod){

py::class_<AIS_Point, opencascade::handle<AIS_Point>, AIS_InteractiveObject> cls_AIS_Point(mod, "AIS_Point", "Constructs point datums to be used in construction of composite shapes. The datum is displayed as the plus marker +.");

// Constructors
cls_AIS_Point.def(py::init<const opencascade::handle<Geom_Point> &>(), py::arg("aComponent"));

// Fields

// Methods
cls_AIS_Point.def_static("get_type_name_", (const char * (*)()) &AIS_Point::get_type_name, "None");
cls_AIS_Point.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_Point::get_type_descriptor, "None");
cls_AIS_Point.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_Point::*)() const) &AIS_Point::DynamicType, "None");
cls_AIS_Point.def("Signature", (Standard_Integer (AIS_Point::*)() const) &AIS_Point::Signature, "Returns index 1, the default index for a point.");
cls_AIS_Point.def("Type", (AIS_KindOfInteractive (AIS_Point::*)() const) &AIS_Point::Type, "Indicates that a point is a datum.");
cls_AIS_Point.def("Component", (opencascade::handle<Geom_Point> (AIS_Point::*)()) &AIS_Point::Component, "Returns the component specified in SetComponent.");
cls_AIS_Point.def("SetComponent", (void (AIS_Point::*)(const opencascade::handle<Geom_Point> &)) &AIS_Point::SetComponent, "Constructs an instance of the point aComponent.", py::arg("aComponent"));
cls_AIS_Point.def("AcceptDisplayMode", (Standard_Boolean (AIS_Point::*)(const Standard_Integer) const) &AIS_Point::AcceptDisplayMode, "Returns true if the display mode selected is valid for point datums.", py::arg("aMode"));
cls_AIS_Point.def("Compute", (void (AIS_Point::*)(const opencascade::handle<Prs3d_Projector> &, const opencascade::handle<Geom_Transformation> &, const opencascade::handle<Prs3d_Presentation> &)) &AIS_Point::Compute, "computes the presentation according to a point of view given by <aProjector>. To be Used when the associated degenerated Presentations have been transformed by <aTrsf> which is not a Pure Translation. The HLR Prs can't be deducted automatically WARNING :<aTrsf> must be applied to the object to display before computation !!!", py::arg("aProjector"), py::arg("aTrsf"), py::arg("aPresentation"));
cls_AIS_Point.def("SetColor", (void (AIS_Point::*)(const Quantity_Color &)) &AIS_Point::SetColor, "Allows you to provide settings for the Color.", py::arg("theColor"));
cls_AIS_Point.def("UnsetColor", (void (AIS_Point::*)()) &AIS_Point::UnsetColor, "Allows you to remove color settings.");
cls_AIS_Point.def("SetMarker", (void (AIS_Point::*)(const Aspect_TypeOfMarker)) &AIS_Point::SetMarker, "Allows you to provide settings for a marker. These include - type of marker, - marker color, - scale factor.", py::arg("aType"));
cls_AIS_Point.def("UnsetMarker", (void (AIS_Point::*)()) &AIS_Point::UnsetMarker, "Removes the marker settings.");
cls_AIS_Point.def("HasMarker", (Standard_Boolean (AIS_Point::*)() const) &AIS_Point::HasMarker, "Returns true if the point datum has a marker.");
cls_AIS_Point.def("Vertex", (TopoDS_Vertex (AIS_Point::*)() const) &AIS_Point::Vertex, "Converts a point into a vertex.");

// Enums

}