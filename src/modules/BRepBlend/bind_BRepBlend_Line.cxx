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
#include <Blend_Point.hxx>
#include <Standard_TypeDef.hxx>
#include <IntSurf_TypeTrans.hxx>
#include <BRepBlend_Extremity.hxx>
#include <Standard_Handle.hxx>
#include <BRepBlend_Line.hxx>
#include <Standard_Type.hxx>
#include <Blend_SequenceOfPoint.hxx>

void bind_BRepBlend_Line(py::module &mod){

py::class_<BRepBlend_Line, opencascade::handle<BRepBlend_Line>, Standard_Transient> cls_BRepBlend_Line(mod, "BRepBlend_Line", "None");

// Constructors
cls_BRepBlend_Line.def(py::init<>());

// Fields

// Methods
cls_BRepBlend_Line.def("Clear", (void (BRepBlend_Line::*)()) &BRepBlend_Line::Clear, "Clears the content of the line.");
cls_BRepBlend_Line.def("Append", (void (BRepBlend_Line::*)(const Blend_Point &)) &BRepBlend_Line::Append, "Adds a point in the line.", py::arg("P"));
cls_BRepBlend_Line.def("Prepend", (void (BRepBlend_Line::*)(const Blend_Point &)) &BRepBlend_Line::Prepend, "Adds a point in the line at the first place.", py::arg("P"));
cls_BRepBlend_Line.def("InsertBefore", (void (BRepBlend_Line::*)(const Standard_Integer, const Blend_Point &)) &BRepBlend_Line::InsertBefore, "Adds a point in the line at the first place.", py::arg("Index"), py::arg("P"));
cls_BRepBlend_Line.def("Remove", (void (BRepBlend_Line::*)(const Standard_Integer, const Standard_Integer)) &BRepBlend_Line::Remove, "Removes from <me> all the items of positions between <FromIndex> and <ToIndex>. Raises an exception if the indices are out of bounds.", py::arg("FromIndex"), py::arg("ToIndex"));
cls_BRepBlend_Line.def("Set", (void (BRepBlend_Line::*)(const IntSurf_TypeTrans, const IntSurf_TypeTrans)) &BRepBlend_Line::Set, "Sets the value of the transition of the line on S1 and the line on S2.", py::arg("TranS1"), py::arg("TranS2"));
cls_BRepBlend_Line.def("Set", (void (BRepBlend_Line::*)(const IntSurf_TypeTrans)) &BRepBlend_Line::Set, "Sets the value of the transition of the line on a surface", py::arg("Trans"));
cls_BRepBlend_Line.def("SetStartPoints", (void (BRepBlend_Line::*)(const BRepBlend_Extremity &, const BRepBlend_Extremity &)) &BRepBlend_Line::SetStartPoints, "Sets the values of the start points for the line.", py::arg("StartPt1"), py::arg("StartPt2"));
cls_BRepBlend_Line.def("SetEndPoints", (void (BRepBlend_Line::*)(const BRepBlend_Extremity &, const BRepBlend_Extremity &)) &BRepBlend_Line::SetEndPoints, "Sets tne values of the end points for the line.", py::arg("EndPt1"), py::arg("EndPt2"));
cls_BRepBlend_Line.def("NbPoints", (Standard_Integer (BRepBlend_Line::*)() const) &BRepBlend_Line::NbPoints, "Returns the number of points in the line.");
cls_BRepBlend_Line.def("Point", (const Blend_Point & (BRepBlend_Line::*)(const Standard_Integer) const) &BRepBlend_Line::Point, "Returns the point of range Index.", py::arg("Index"));
cls_BRepBlend_Line.def("TransitionOnS1", (IntSurf_TypeTrans (BRepBlend_Line::*)() const) &BRepBlend_Line::TransitionOnS1, "Returns the type of the transition of the line defined on the first surface. The transition is 'constant' along the line. The transition is IN if the line is oriented in such a way that the system of vectors (N,DRac,T) is right-handed, where N is the normal to the first surface at a point P, DRac is a vector tangent to the blending patch, oriented towards the valid part of this patch, T is the tangent to the line on S1 at P. The transitioon is OUT when the system of vectors is left-handed.");
cls_BRepBlend_Line.def("TransitionOnS2", (IntSurf_TypeTrans (BRepBlend_Line::*)() const) &BRepBlend_Line::TransitionOnS2, "Returns the type of the transition of the line defined on the second surface. The transition is 'constant' along the line.");
cls_BRepBlend_Line.def("StartPointOnFirst", (const BRepBlend_Extremity & (BRepBlend_Line::*)() const) &BRepBlend_Line::StartPointOnFirst, "Returns the start point on S1.");
cls_BRepBlend_Line.def("StartPointOnSecond", (const BRepBlend_Extremity & (BRepBlend_Line::*)() const) &BRepBlend_Line::StartPointOnSecond, "Returns the start point on S2");
cls_BRepBlend_Line.def("EndPointOnFirst", (const BRepBlend_Extremity & (BRepBlend_Line::*)() const) &BRepBlend_Line::EndPointOnFirst, "Returns the end point on S1.");
cls_BRepBlend_Line.def("EndPointOnSecond", (const BRepBlend_Extremity & (BRepBlend_Line::*)() const) &BRepBlend_Line::EndPointOnSecond, "Returns the point on S2.");
cls_BRepBlend_Line.def("TransitionOnS", (IntSurf_TypeTrans (BRepBlend_Line::*)() const) &BRepBlend_Line::TransitionOnS, "Returns the type of the transition of the line defined on the surface.");
cls_BRepBlend_Line.def_static("get_type_name_", (const char * (*)()) &BRepBlend_Line::get_type_name, "None");
cls_BRepBlend_Line.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BRepBlend_Line::get_type_descriptor, "None");
cls_BRepBlend_Line.def("DynamicType", (const opencascade::handle<Standard_Type> & (BRepBlend_Line::*)() const) &BRepBlend_Line::DynamicType, "None");

// Enums

}