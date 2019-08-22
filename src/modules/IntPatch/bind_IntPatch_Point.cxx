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
#include <IntSurf_PntOn2S.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HVertex.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <IntSurf_Transition.hxx>
#include <IntPatch_Point.hxx>

void bind_IntPatch_Point(py::module &mod){

py::class_<IntPatch_Point> cls_IntPatch_Point(mod, "IntPatch_Point", "Definition of an intersection point between two surfaces. Such a point is contains geometrical informations (see the Value method) and logical informations.");

// Constructors
cls_IntPatch_Point.def(py::init<>());

// Fields

// Methods
// cls_IntPatch_Point.def_static("operator new_", (void * (*)(size_t)) &IntPatch_Point::operator new, "None", py::arg("theSize"));
// cls_IntPatch_Point.def_static("operator delete_", (void (*)(void *)) &IntPatch_Point::operator delete, "None", py::arg("theAddress"));
// cls_IntPatch_Point.def_static("operator new[]_", (void * (*)(size_t)) &IntPatch_Point::operator new[], "None", py::arg("theSize"));
// cls_IntPatch_Point.def_static("operator delete[]_", (void (*)(void *)) &IntPatch_Point::operator delete[], "None", py::arg("theAddress"));
// cls_IntPatch_Point.def_static("operator new_", (void * (*)(size_t, void *)) &IntPatch_Point::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPatch_Point.def_static("operator delete_", (void (*)(void *, void *)) &IntPatch_Point::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPatch_Point.def("SetValue", (void (IntPatch_Point::*)(const gp_Pnt &, const Standard_Real, const Standard_Boolean)) &IntPatch_Point::SetValue, "Sets the values of a point which is on no domain, when both surfaces are implicit ones. If Tangent is True, the point is a point of tangency between the surfaces.", py::arg("Pt"), py::arg("Tol"), py::arg("Tangent"));
cls_IntPatch_Point.def("SetValue", (void (IntPatch_Point::*)(const gp_Pnt &)) &IntPatch_Point::SetValue, "None", py::arg("Pt"));
cls_IntPatch_Point.def("SetValue", (void (IntPatch_Point::*)(const IntSurf_PntOn2S &)) &IntPatch_Point::SetValue, "Sets the value of <pt> member", py::arg("thePOn2S"));
cls_IntPatch_Point.def("SetTolerance", (void (IntPatch_Point::*)(const Standard_Real)) &IntPatch_Point::SetTolerance, "None", py::arg("Tol"));
cls_IntPatch_Point.def("SetParameters", (void (IntPatch_Point::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntPatch_Point::SetParameters, "Sets the values of the parameters of the point on each surface.", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));
cls_IntPatch_Point.def("SetParameter", (void (IntPatch_Point::*)(const Standard_Real)) &IntPatch_Point::SetParameter, "Set the value of the parameter on the intersection line.", py::arg("Para"));
cls_IntPatch_Point.def("SetVertex", (void (IntPatch_Point::*)(const Standard_Boolean, const opencascade::handle<Adaptor3d_HVertex> &)) &IntPatch_Point::SetVertex, "Sets the values of a point which is a vertex on the initial facet of restriction of one of the surface. If OnFirst is True, the point is on the domain of the first patch, otherwise the point is on the domain of the second surface.", py::arg("OnFirst"), py::arg("V"));
cls_IntPatch_Point.def("SetArc", (void (IntPatch_Point::*)(const Standard_Boolean, const opencascade::handle<Adaptor2d_HCurve2d> &, const Standard_Real, const IntSurf_Transition &, const IntSurf_Transition &)) &IntPatch_Point::SetArc, "Sets the values of a point which is on one of the domain, when both surfaces are implicit ones. If OnFirst is True, the point is on the domain of the first patch, otherwise the point is on the domain of the second surface.", py::arg("OnFirst"), py::arg("A"), py::arg("Param"), py::arg("TLine"), py::arg("TArc"));
cls_IntPatch_Point.def("SetMultiple", (void (IntPatch_Point::*)(const Standard_Boolean)) &IntPatch_Point::SetMultiple, "Sets (or unsets) the point as a point on several intersection line.", py::arg("IsMult"));
cls_IntPatch_Point.def("Value", (const gp_Pnt & (IntPatch_Point::*)() const) &IntPatch_Point::Value, "Returns the intersection point (geometric information).");
cls_IntPatch_Point.def("ParameterOnLine", (Standard_Real (IntPatch_Point::*)() const) &IntPatch_Point::ParameterOnLine, "This method returns the parameter of the point on the intersection line. If the points does not belong to an intersection line, the value returned does not have any sens.");
cls_IntPatch_Point.def("Tolerance", (Standard_Real (IntPatch_Point::*)() const) &IntPatch_Point::Tolerance, "This method returns the fuzziness on the point.");
cls_IntPatch_Point.def("IsTangencyPoint", (Standard_Boolean (IntPatch_Point::*)() const) &IntPatch_Point::IsTangencyPoint, "Returns True if the Point is a tangency point between the surfaces. If the Point is on one of the domain (IsOnDomS1 returns True or IsOnDomS2 returns True), an exception is raised.");
cls_IntPatch_Point.def("ParametersOnS1", [](IntPatch_Point &self, Standard_Real & U1, Standard_Real & V1){ self.ParametersOnS1(U1, V1); return std::tuple<Standard_Real &, Standard_Real &>(U1, V1); }, "Returns the parameters on the first surface of the point.", py::arg("U1"), py::arg("V1"));
cls_IntPatch_Point.def("ParametersOnS2", [](IntPatch_Point &self, Standard_Real & U2, Standard_Real & V2){ self.ParametersOnS2(U2, V2); return std::tuple<Standard_Real &, Standard_Real &>(U2, V2); }, "Returns the parameters on the second surface of the point.", py::arg("U2"), py::arg("V2"));
cls_IntPatch_Point.def("IsMultiple", (Standard_Boolean (IntPatch_Point::*)() const) &IntPatch_Point::IsMultiple, "Returns True if the point belongs to several intersection lines.");
cls_IntPatch_Point.def("IsOnDomS1", (Standard_Boolean (IntPatch_Point::*)() const) &IntPatch_Point::IsOnDomS1, "Returns TRUE if the point is on a boundary of the domain of the first patch.");
cls_IntPatch_Point.def("IsVertexOnS1", (Standard_Boolean (IntPatch_Point::*)() const) &IntPatch_Point::IsVertexOnS1, "Returns TRUE if the point is a vertex on the initial restriction facet of the first surface.");
cls_IntPatch_Point.def("VertexOnS1", (const opencascade::handle<Adaptor3d_HVertex> & (IntPatch_Point::*)() const) &IntPatch_Point::VertexOnS1, "Returns the information about the point when it is on the domain of the first patch, i-e when the function IsVertexOnS1 returns True. Otherwise, an exception is raised.");
cls_IntPatch_Point.def("ArcOnS1", (const opencascade::handle<Adaptor2d_HCurve2d> & (IntPatch_Point::*)() const) &IntPatch_Point::ArcOnS1, "Returns the arc of restriction containing the vertex. The exception DomainError is raised if IsOnDomS1 returns False.");
cls_IntPatch_Point.def("TransitionLineArc1", (const IntSurf_Transition & (IntPatch_Point::*)() const) &IntPatch_Point::TransitionLineArc1, "Returns the transition of the point on the intersection line with the arc on S1. The exception DomainError is raised if IsOnDomS1 returns False.");
cls_IntPatch_Point.def("TransitionOnS1", (const IntSurf_Transition & (IntPatch_Point::*)() const) &IntPatch_Point::TransitionOnS1, "Returns the transition between the intersection line returned by the method Line and the arc on S1 returned by ArcOnS1(). The exception DomainError is raised if IsOnDomS1 returns False.");
cls_IntPatch_Point.def("ParameterOnArc1", (Standard_Real (IntPatch_Point::*)() const) &IntPatch_Point::ParameterOnArc1, "Returns the parameter of the point on the arc returned by the method ArcOnS2. The exception DomainError is raised if IsOnDomS1 returns False.");
cls_IntPatch_Point.def("IsOnDomS2", (Standard_Boolean (IntPatch_Point::*)() const) &IntPatch_Point::IsOnDomS2, "Returns TRUE if the point is on a boundary of the domain of the second patch.");
cls_IntPatch_Point.def("IsVertexOnS2", (Standard_Boolean (IntPatch_Point::*)() const) &IntPatch_Point::IsVertexOnS2, "Returns TRUE if the point is a vertex on the initial restriction facet of the first surface.");
cls_IntPatch_Point.def("VertexOnS2", (const opencascade::handle<Adaptor3d_HVertex> & (IntPatch_Point::*)() const) &IntPatch_Point::VertexOnS2, "Returns the information about the point when it is on the domain of the second patch, i-e when the function IsVertexOnS2 returns True. Otherwise, an exception is raised.");
cls_IntPatch_Point.def("ArcOnS2", (const opencascade::handle<Adaptor2d_HCurve2d> & (IntPatch_Point::*)() const) &IntPatch_Point::ArcOnS2, "Returns the arc of restriction containing the vertex. The exception DomainError is raised if IsOnDomS2 returns False.");
cls_IntPatch_Point.def("TransitionLineArc2", (const IntSurf_Transition & (IntPatch_Point::*)() const) &IntPatch_Point::TransitionLineArc2, "Returns the transition of the point on the intersection line with the arc on S2. The exception DomainError is raised if IsOnDomS2 returns False.");
cls_IntPatch_Point.def("TransitionOnS2", (const IntSurf_Transition & (IntPatch_Point::*)() const) &IntPatch_Point::TransitionOnS2, "Returns the transition between the intersection line returned by the method Line and the arc on S2 returned by ArcOnS2. The exception DomainError is raised if IsOnDomS2 returns False.");
cls_IntPatch_Point.def("ParameterOnArc2", (Standard_Real (IntPatch_Point::*)() const) &IntPatch_Point::ParameterOnArc2, "Returns the parameter of the point on the arc returned by the method ArcOnS2. The exception DomainError is raised if IsOnDomS2 returns False.");
cls_IntPatch_Point.def("PntOn2S", (const IntSurf_PntOn2S & (IntPatch_Point::*)() const) &IntPatch_Point::PntOn2S, "Returns the PntOn2S (geometric Point and the parameters)");
cls_IntPatch_Point.def("Parameters", [](IntPatch_Point &self, Standard_Real & U1, Standard_Real & V1, Standard_Real & U2, Standard_Real & V2){ self.Parameters(U1, V1, U2, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, V1, U2, V2); }, "Returns the parameters on the first and on the second surface of the point.", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));
cls_IntPatch_Point.def("ReverseTransition", (void (IntPatch_Point::*)()) &IntPatch_Point::ReverseTransition, "None");
cls_IntPatch_Point.def("Dump", (void (IntPatch_Point::*)() const) &IntPatch_Point::Dump, "None");

// Enums

}