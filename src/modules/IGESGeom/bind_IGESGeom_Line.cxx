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
#include <IGESData_IGESEntity.hxx>
#include <gp_XYZ.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Handle.hxx>
#include <IGESGeom_Line.hxx>
#include <Standard_Type.hxx>

void bind_IGESGeom_Line(py::module &mod){

py::class_<IGESGeom_Line, opencascade::handle<IGESGeom_Line>, IGESData_IGESEntity> cls_IGESGeom_Line(mod, "IGESGeom_Line", "defines IGESLine, Type <110> Form <0> in package IGESGeom A line is a bounded, connected portion of a parent straight line which consists of more than one point. A line is defined by its end points.");

// Constructors
cls_IGESGeom_Line.def(py::init<>());

// Fields

// Methods
cls_IGESGeom_Line.def("Init", (void (IGESGeom_Line::*)(const gp_XYZ &, const gp_XYZ &)) &IGESGeom_Line::Init, "This method is used to set the fields of the class Line - aStart : Start point of the line - anEnd : End point of the line", py::arg("aStart"), py::arg("anEnd"));
cls_IGESGeom_Line.def("Infinite", (Standard_Integer (IGESGeom_Line::*)() const) &IGESGeom_Line::Infinite, "Returns the Infinite status i.e. the Form Number : 0 1 2");
cls_IGESGeom_Line.def("SetInfinite", (void (IGESGeom_Line::*)(const Standard_Integer)) &IGESGeom_Line::SetInfinite, "Sets the Infinite status Does nothing if <status> is not 0 1 or 2", py::arg("status"));
cls_IGESGeom_Line.def("StartPoint", (gp_Pnt (IGESGeom_Line::*)() const) &IGESGeom_Line::StartPoint, "returns the start point of the line");
cls_IGESGeom_Line.def("TransformedStartPoint", (gp_Pnt (IGESGeom_Line::*)() const) &IGESGeom_Line::TransformedStartPoint, "returns the start point of the line after applying Transf. Matrix");
cls_IGESGeom_Line.def("EndPoint", (gp_Pnt (IGESGeom_Line::*)() const) &IGESGeom_Line::EndPoint, "returns the end point of the line");
cls_IGESGeom_Line.def("TransformedEndPoint", (gp_Pnt (IGESGeom_Line::*)() const) &IGESGeom_Line::TransformedEndPoint, "returns the end point of the line after applying Transf. Matrix");
cls_IGESGeom_Line.def_static("get_type_name_", (const char * (*)()) &IGESGeom_Line::get_type_name, "None");
cls_IGESGeom_Line.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGeom_Line::get_type_descriptor, "None");
cls_IGESGeom_Line.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGeom_Line::*)() const) &IGESGeom_Line::DynamicType, "None");

// Enums

}