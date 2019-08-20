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
#include <Standard.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HVertex.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <IntSurf_Transition.hxx>
#include <Contap_Point.hxx>

void bind_Contap_Point(py::module &mod){

py::class_<Contap_Point, std::unique_ptr<Contap_Point>> cls_Contap_Point(mod, "Contap_Point", "Definition of a vertex on the contour line. Most of the time, such a point is an intersection between the contour and a restriction of the surface. When it is not tyhe method IsOnArc return False. Such a point is contains geometrical informations (see the Value method) and logical informations.");

// Constructors
cls_Contap_Point.def(py::init<>());
cls_Contap_Point.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real>(), py::arg("Pt"), py::arg("U"), py::arg("V"));

// Fields

// Methods
// cls_Contap_Point.def_static("operator new_", (void * (*)(size_t)) &Contap_Point::operator new, "None", py::arg("theSize"));
// cls_Contap_Point.def_static("operator delete_", (void (*)(void *)) &Contap_Point::operator delete, "None", py::arg("theAddress"));
// cls_Contap_Point.def_static("operator new[]_", (void * (*)(size_t)) &Contap_Point::operator new[], "None", py::arg("theSize"));
// cls_Contap_Point.def_static("operator delete[]_", (void (*)(void *)) &Contap_Point::operator delete[], "None", py::arg("theAddress"));
// cls_Contap_Point.def_static("operator new_", (void * (*)(size_t, void *)) &Contap_Point::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Contap_Point.def_static("operator delete_", (void (*)(void *, void *)) &Contap_Point::operator delete, "None", py::arg(""), py::arg(""));
cls_Contap_Point.def("SetValue", (void (Contap_Point::*)(const gp_Pnt &, const Standard_Real, const Standard_Real)) &Contap_Point::SetValue, "Sets the values for a point.", py::arg("Pt"), py::arg("U"), py::arg("V"));
cls_Contap_Point.def("SetParameter", (void (Contap_Point::*)(const Standard_Real)) &Contap_Point::SetParameter, "Set the value of the parameter on the intersection line.", py::arg("Para"));
cls_Contap_Point.def("SetVertex", (void (Contap_Point::*)(const opencascade::handle<Adaptor3d_HVertex> &)) &Contap_Point::SetVertex, "Sets the values of a point which is a vertex on the initial facet of restriction of one of the surface.", py::arg("V"));
cls_Contap_Point.def("SetArc", (void (Contap_Point::*)(const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const IntSurf_Transition &, const IntSurf_Transition &)) &Contap_Point::SetArc, "Sets the value of the arc and of the parameter on this arc of the point.", py::arg("A"), py::arg("Param"), py::arg("TLine"), py::arg("TArc"));
cls_Contap_Point.def("SetMultiple", (void (Contap_Point::*)()) &Contap_Point::SetMultiple, "None");
cls_Contap_Point.def("SetInternal", (void (Contap_Point::*)()) &Contap_Point::SetInternal, "None");
cls_Contap_Point.def("Value", (const gp_Pnt & (Contap_Point::*)() const) &Contap_Point::Value, "Returns the intersection point (geometric information).");
cls_Contap_Point.def("ParameterOnLine", (Standard_Real (Contap_Point::*)() const) &Contap_Point::ParameterOnLine, "This method returns the parameter of the point on the intersection line. If the points does not belong to an intersection line, the value returned does not have any sens.");
cls_Contap_Point.def("Parameters", [](Contap_Point &self, Standard_Real & U1, Standard_Real & V1){ self.Parameters(U1, V1); return std::tuple<Standard_Real &, Standard_Real &>(U1, V1); }, "Returns the parameters on the surface of the point.", py::arg("U1"), py::arg("V1"));
cls_Contap_Point.def("IsOnArc", (Standard_Boolean (Contap_Point::*)() const) &Contap_Point::IsOnArc, "Returns True when the point is an intersection between the contour and a restriction.");
cls_Contap_Point.def("Arc", (const opencascade::handle<Adaptor2d_HCurve2d> & (Contap_Point::*)() const) &Contap_Point::Arc, "Returns the arc of restriction containing the vertex.");
cls_Contap_Point.def("ParameterOnArc", (Standard_Real (Contap_Point::*)() const) &Contap_Point::ParameterOnArc, "Returns the parameter of the point on the arc returned by the method Arc().");
cls_Contap_Point.def("TransitionOnLine", (const IntSurf_Transition & (Contap_Point::*)() const) &Contap_Point::TransitionOnLine, "Returns the transition of the point on the contour.");
cls_Contap_Point.def("TransitionOnArc", (const IntSurf_Transition & (Contap_Point::*)() const) &Contap_Point::TransitionOnArc, "Returns the transition of the point on the arc.");
cls_Contap_Point.def("IsVertex", (Standard_Boolean (Contap_Point::*)() const) &Contap_Point::IsVertex, "Returns TRUE if the point is a vertex on the initial restriction facet of the surface.");
cls_Contap_Point.def("Vertex", (const opencascade::handle<Adaptor3d_HVertex> & (Contap_Point::*)() const) &Contap_Point::Vertex, "Returns the information about the point when it is on the domain of the patch, i-e when the function IsVertex returns True. Otherwise, an exception is raised.");
cls_Contap_Point.def("IsMultiple", (Standard_Boolean (Contap_Point::*)() const) &Contap_Point::IsMultiple, "Returns True if the point belongs to several lines.");
cls_Contap_Point.def("IsInternal", (Standard_Boolean (Contap_Point::*)() const) &Contap_Point::IsInternal, "Returns True if the point is an internal one, i.e if the tangent to the line on the point and the eye direction are parallel.");

// Enums

}