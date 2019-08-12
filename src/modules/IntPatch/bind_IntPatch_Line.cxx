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
#include <Standard_TypeDef.hxx>
#include <IntPatch_IType.hxx>
#include <IntSurf_TypeTrans.hxx>
#include <IntSurf_Situation.hxx>
#include <Standard_Handle.hxx>
#include <IntPatch_Line.hxx>
#include <Standard_Type.hxx>

void bind_IntPatch_Line(py::module &mod){

py::class_<IntPatch_Line, opencascade::handle<IntPatch_Line>, Standard_Transient> cls_IntPatch_Line(mod, "IntPatch_Line", "Definition of an intersection line between two surfaces. A line may be either geometric : line, circle, ellipse, parabola, hyperbola, as defined in the class GLine, or analytic, as defined in the class ALine, or defined by a set of points (coming from a walking algorithm) as defined in the class WLine.");

// Constructors

// Fields

// Methods
cls_IntPatch_Line.def("SetValue", (void (IntPatch_Line::*)(const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &IntPatch_Line::SetValue, "To set the values returned by IsUIsoS1,.... The default values are False.", py::arg("Uiso1"), py::arg("Viso1"), py::arg("Uiso2"), py::arg("Viso2"));
cls_IntPatch_Line.def("ArcType", (IntPatch_IType (IntPatch_Line::*)() const) &IntPatch_Line::ArcType, "Returns the type of geometry 3d (Line, Circle, Parabola, Hyperbola, Ellipse, Analytic, Walking, Restriction)");
cls_IntPatch_Line.def("IsTangent", (Standard_Boolean (IntPatch_Line::*)() const) &IntPatch_Line::IsTangent, "Returns TRUE if the intersection is a line of tangency between the 2 patches.");
cls_IntPatch_Line.def("TransitionOnS1", (IntSurf_TypeTrans (IntPatch_Line::*)() const) &IntPatch_Line::TransitionOnS1, "Returns the type of the transition of the line for the first surface. The transition is 'constant' along the line. The transition is IN if the line is oriented in such a way that the system of vector (N1,N2,T) is right-handed, where N1 is the normal to the first surface at a point P, N2 is the normal to the second surface at a point P, T is the tangent to the intersection line at P. If the system of vector is left-handed, the transition is OUT. When N1 and N2 are colinear all along the intersection line, the transition will be - TOUCH, if it is possible to use the 2nd derivatives to determine the position of one surafce compared to the other (see Situation) - UNDECIDED otherwise.");
cls_IntPatch_Line.def("TransitionOnS2", (IntSurf_TypeTrans (IntPatch_Line::*)() const) &IntPatch_Line::TransitionOnS2, "Returns the type of the transition of the line for the second surface. The transition is 'constant' along the line.");
cls_IntPatch_Line.def("SituationS1", (IntSurf_Situation (IntPatch_Line::*)() const) &IntPatch_Line::SituationS1, "Returns the situation (INSIDE/OUTSIDE/UNKNOWN) of the first patch compared to the second one, when TransitionOnS1 or TransitionOnS2 returns TOUCH. Otherwise, an exception is raised.");
cls_IntPatch_Line.def("SituationS2", (IntSurf_Situation (IntPatch_Line::*)() const) &IntPatch_Line::SituationS2, "Returns the situation (INSIDE/OUTSIDE/UNKNOWN) of the second patch compared to the first one, when TransitionOnS1 or TransitionOnS2 returns TOUCH. Otherwise, an exception is raised.");
cls_IntPatch_Line.def("IsUIsoOnS1", (Standard_Boolean (IntPatch_Line::*)() const) &IntPatch_Line::IsUIsoOnS1, "Returns TRUE if the intersection is a U isoparametric curve on the first patch.");
cls_IntPatch_Line.def("IsVIsoOnS1", (Standard_Boolean (IntPatch_Line::*)() const) &IntPatch_Line::IsVIsoOnS1, "Returns TRUE if the intersection is a V isoparametric curve on the first patch.");
cls_IntPatch_Line.def("IsUIsoOnS2", (Standard_Boolean (IntPatch_Line::*)() const) &IntPatch_Line::IsUIsoOnS2, "Returns TRUE if the intersection is a U isoparametric curve on the second patch.");
cls_IntPatch_Line.def("IsVIsoOnS2", (Standard_Boolean (IntPatch_Line::*)() const) &IntPatch_Line::IsVIsoOnS2, "Returns TRUE if the intersection is a V isoparametric curve on the second patch.");
cls_IntPatch_Line.def_static("get_type_name_", (const char * (*)()) &IntPatch_Line::get_type_name, "None");
cls_IntPatch_Line.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IntPatch_Line::get_type_descriptor, "None");
cls_IntPatch_Line.def("DynamicType", (const opencascade::handle<Standard_Type> & (IntPatch_Line::*)() const) &IntPatch_Line::DynamicType, "None");

// Enums

}