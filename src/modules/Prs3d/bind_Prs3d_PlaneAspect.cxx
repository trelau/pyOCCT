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
#include <Prs3d_BasicAspect.hxx>
#include <Standard_Handle.hxx>
#include <Prs3d_PlaneAspect.hxx>
#include <Standard_Type.hxx>
#include <Prs3d_LineAspect.hxx>
#include <Standard_TypeDef.hxx>

void bind_Prs3d_PlaneAspect(py::module &mod){

py::class_<Prs3d_PlaneAspect, opencascade::handle<Prs3d_PlaneAspect>, Prs3d_BasicAspect> cls_Prs3d_PlaneAspect(mod, "Prs3d_PlaneAspect", "A framework to define the display of planes.");

// Constructors
cls_Prs3d_PlaneAspect.def(py::init<>());

// Fields

// Methods
cls_Prs3d_PlaneAspect.def_static("get_type_name_", (const char * (*)()) &Prs3d_PlaneAspect::get_type_name, "None");
cls_Prs3d_PlaneAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Prs3d_PlaneAspect::get_type_descriptor, "None");
cls_Prs3d_PlaneAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (Prs3d_PlaneAspect::*)() const) &Prs3d_PlaneAspect::DynamicType, "None");
cls_Prs3d_PlaneAspect.def("EdgesAspect", (const opencascade::handle<Prs3d_LineAspect> & (Prs3d_PlaneAspect::*)() const) &Prs3d_PlaneAspect::EdgesAspect, "Returns the attributes of displayed edges involved in the presentation of planes.");
cls_Prs3d_PlaneAspect.def("IsoAspect", (const opencascade::handle<Prs3d_LineAspect> & (Prs3d_PlaneAspect::*)() const) &Prs3d_PlaneAspect::IsoAspect, "Returns the attributes of displayed isoparameters involved in the presentation of planes.");
cls_Prs3d_PlaneAspect.def("ArrowAspect", (const opencascade::handle<Prs3d_LineAspect> & (Prs3d_PlaneAspect::*)() const) &Prs3d_PlaneAspect::ArrowAspect, "Returns the settings for displaying an arrow.");
cls_Prs3d_PlaneAspect.def("SetArrowsLength", (void (Prs3d_PlaneAspect::*)(const Standard_Real)) &Prs3d_PlaneAspect::SetArrowsLength, "None", py::arg("theLength"));
cls_Prs3d_PlaneAspect.def("ArrowsLength", (Standard_Real (Prs3d_PlaneAspect::*)() const) &Prs3d_PlaneAspect::ArrowsLength, "Returns the length of the arrow shaft used in the display of arrows.");
cls_Prs3d_PlaneAspect.def("SetArrowsSize", (void (Prs3d_PlaneAspect::*)(const Standard_Real)) &Prs3d_PlaneAspect::SetArrowsSize, "Sets the angle of the arrowhead used in the display of planes.", py::arg("theSize"));
cls_Prs3d_PlaneAspect.def("ArrowsSize", (Standard_Real (Prs3d_PlaneAspect::*)() const) &Prs3d_PlaneAspect::ArrowsSize, "Returns the size of arrows used in the display of planes.");
cls_Prs3d_PlaneAspect.def("SetArrowsAngle", (void (Prs3d_PlaneAspect::*)(const Standard_Real)) &Prs3d_PlaneAspect::SetArrowsAngle, "Sets the angle of the arrowhead used in the display of arrows involved in the presentation of planes.", py::arg("theAngle"));
cls_Prs3d_PlaneAspect.def("ArrowsAngle", (Standard_Real (Prs3d_PlaneAspect::*)() const) &Prs3d_PlaneAspect::ArrowsAngle, "Returns the angle of the arrowhead used in the display of arrows involved in the presentation of planes.");
cls_Prs3d_PlaneAspect.def("SetDisplayCenterArrow", (void (Prs3d_PlaneAspect::*)(const Standard_Boolean)) &Prs3d_PlaneAspect::SetDisplayCenterArrow, "Sets the display attributes defined in DisplayCenterArrow to active.", py::arg("theToDraw"));
cls_Prs3d_PlaneAspect.def("DisplayCenterArrow", (Standard_Boolean (Prs3d_PlaneAspect::*)() const) &Prs3d_PlaneAspect::DisplayCenterArrow, "Returns true if the display of center arrows is allowed.");
cls_Prs3d_PlaneAspect.def("SetDisplayEdgesArrows", (void (Prs3d_PlaneAspect::*)(const Standard_Boolean)) &Prs3d_PlaneAspect::SetDisplayEdgesArrows, "Sets the display attributes defined in DisplayEdgesArrows to active.", py::arg("theToDraw"));
cls_Prs3d_PlaneAspect.def("DisplayEdgesArrows", (Standard_Boolean (Prs3d_PlaneAspect::*)() const) &Prs3d_PlaneAspect::DisplayEdgesArrows, "Returns true if the display of edge arrows is allowed.");
cls_Prs3d_PlaneAspect.def("SetDisplayEdges", (void (Prs3d_PlaneAspect::*)(const Standard_Boolean)) &Prs3d_PlaneAspect::SetDisplayEdges, "None", py::arg("theToDraw"));
cls_Prs3d_PlaneAspect.def("DisplayEdges", (Standard_Boolean (Prs3d_PlaneAspect::*)() const) &Prs3d_PlaneAspect::DisplayEdges, "None");
cls_Prs3d_PlaneAspect.def("SetDisplayIso", (void (Prs3d_PlaneAspect::*)(const Standard_Boolean)) &Prs3d_PlaneAspect::SetDisplayIso, "Sets the display attributes defined in DisplayIso to active.", py::arg("theToDraw"));
cls_Prs3d_PlaneAspect.def("DisplayIso", (Standard_Boolean (Prs3d_PlaneAspect::*)() const) &Prs3d_PlaneAspect::DisplayIso, "Returns true if the display of isoparameters is allowed.");
cls_Prs3d_PlaneAspect.def("SetPlaneLength", (void (Prs3d_PlaneAspect::*)(const Standard_Real, const Standard_Real)) &Prs3d_PlaneAspect::SetPlaneLength, "None", py::arg("theLX"), py::arg("theLY"));
cls_Prs3d_PlaneAspect.def("PlaneXLength", (Standard_Real (Prs3d_PlaneAspect::*)() const) &Prs3d_PlaneAspect::PlaneXLength, "Returns the length of the x axis used in the display of planes.");
cls_Prs3d_PlaneAspect.def("PlaneYLength", (Standard_Real (Prs3d_PlaneAspect::*)() const) &Prs3d_PlaneAspect::PlaneYLength, "Returns the length of the y axis used in the display of planes.");
cls_Prs3d_PlaneAspect.def("SetIsoDistance", (void (Prs3d_PlaneAspect::*)(const Standard_Real)) &Prs3d_PlaneAspect::SetIsoDistance, "Sets the distance L between isoparameters used in the display of planes.", py::arg("theL"));
cls_Prs3d_PlaneAspect.def("IsoDistance", (Standard_Real (Prs3d_PlaneAspect::*)() const) &Prs3d_PlaneAspect::IsoDistance, "Returns the distance between isoparameters used in the display of planes.");

// Enums

}