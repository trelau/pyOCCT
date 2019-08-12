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
#include <Prs3d_LineAspect.hxx>
#include <Standard_Type.hxx>
#include <Quantity_Color.hxx>
#include <Aspect_TypeOfLine.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_AspectLine3d.hxx>

void bind_Prs3d_LineAspect(py::module &mod){

py::class_<Prs3d_LineAspect, opencascade::handle<Prs3d_LineAspect>, Prs3d_BasicAspect> cls_Prs3d_LineAspect(mod, "Prs3d_LineAspect", "A framework for defining how a line will be displayed in a presentation. Aspects of line display include width, color and type of line. The definition set by this class is then passed to the attribute manager Prs3d_Drawer. Any object which requires a value for line aspect as an argument may then be given the attribute manager as a substitute argument in the form of a field such as myDrawer for example.");

// Constructors
cls_Prs3d_LineAspect.def(py::init<const Quantity_Color &, const Aspect_TypeOfLine, const Standard_Real>(), py::arg("theColor"), py::arg("theType"), py::arg("theWidth"));
cls_Prs3d_LineAspect.def(py::init<const opencascade::handle<Graphic3d_AspectLine3d> &>(), py::arg("theAspect"));

// Fields

// Methods
cls_Prs3d_LineAspect.def_static("get_type_name_", (const char * (*)()) &Prs3d_LineAspect::get_type_name, "None");
cls_Prs3d_LineAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Prs3d_LineAspect::get_type_descriptor, "None");
cls_Prs3d_LineAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (Prs3d_LineAspect::*)() const) &Prs3d_LineAspect::DynamicType, "None");
cls_Prs3d_LineAspect.def("SetColor", (void (Prs3d_LineAspect::*)(const Quantity_Color &)) &Prs3d_LineAspect::SetColor, "Sets the line color defined at the time of construction. Default value: Quantity_NOC_YELLOW", py::arg("theColor"));
cls_Prs3d_LineAspect.def("SetTypeOfLine", (void (Prs3d_LineAspect::*)(const Aspect_TypeOfLine)) &Prs3d_LineAspect::SetTypeOfLine, "Sets the type of line defined at the time of construction. This could, for example, be solid, dotted or made up of dashes. Default value: Aspect_TOL_SOLID", py::arg("theType"));
cls_Prs3d_LineAspect.def("SetWidth", (void (Prs3d_LineAspect::*)(const Standard_Real)) &Prs3d_LineAspect::SetWidth, "Sets the line width defined at the time of construction. Default value: 1.", py::arg("theWidth"));
cls_Prs3d_LineAspect.def("Aspect", (const opencascade::handle<Graphic3d_AspectLine3d> & (Prs3d_LineAspect::*)() const) &Prs3d_LineAspect::Aspect, "Returns the line aspect. This is defined as the set of color, type and thickness attributes.");
cls_Prs3d_LineAspect.def("SetAspect", (void (Prs3d_LineAspect::*)(const opencascade::handle<Graphic3d_AspectLine3d> &)) &Prs3d_LineAspect::SetAspect, "None", py::arg("theAspect"));

// Enums

}