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
#include <IntSurf_PathPoint.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Vec.hxx>
#include <gp_Dir2d.hxx>
#include <IntSurf_PathPointTool.hxx>

void bind_IntSurf_PathPointTool(py::module &mod){

py::class_<IntSurf_PathPointTool> cls_IntSurf_PathPointTool(mod, "IntSurf_PathPointTool", "None");

// Constructors

// Fields

// Methods
// cls_IntSurf_PathPointTool.def_static("operator new_", (void * (*)(size_t)) &IntSurf_PathPointTool::operator new, "None", py::arg("theSize"));
// cls_IntSurf_PathPointTool.def_static("operator delete_", (void (*)(void *)) &IntSurf_PathPointTool::operator delete, "None", py::arg("theAddress"));
// cls_IntSurf_PathPointTool.def_static("operator new[]_", (void * (*)(size_t)) &IntSurf_PathPointTool::operator new[], "None", py::arg("theSize"));
// cls_IntSurf_PathPointTool.def_static("operator delete[]_", (void (*)(void *)) &IntSurf_PathPointTool::operator delete[], "None", py::arg("theAddress"));
// cls_IntSurf_PathPointTool.def_static("operator new_", (void * (*)(size_t, void *)) &IntSurf_PathPointTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntSurf_PathPointTool.def_static("operator delete_", (void (*)(void *, void *)) &IntSurf_PathPointTool::operator delete, "None", py::arg(""), py::arg(""));
cls_IntSurf_PathPointTool.def_static("Value3d_", (gp_Pnt (*)(const IntSurf_PathPoint &)) &IntSurf_PathPointTool::Value3d, "Returns the 3d coordinates of the starting point.", py::arg("PStart"));
cls_IntSurf_PathPointTool.def_static("Value2d_", [](const IntSurf_PathPoint & PStart, Standard_Real & U, Standard_Real & V){ IntSurf_PathPointTool::Value2d(PStart, U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Returns the <U, V> parameters which are associated with <P> it's the parameters which start the marching algorithm", py::arg("PStart"), py::arg("U"), py::arg("V"));
cls_IntSurf_PathPointTool.def_static("IsPassingPnt_", (Standard_Boolean (*)(const IntSurf_PathPoint &)) &IntSurf_PathPointTool::IsPassingPnt, "Returns True if the point is a point on a non-oriented arc, which means that the intersection line does not stop at such a point but just go through such a point. IsPassingPnt is True when IsOnArc is True", py::arg("PStart"));
cls_IntSurf_PathPointTool.def_static("IsTangent_", (Standard_Boolean (*)(const IntSurf_PathPoint &)) &IntSurf_PathPointTool::IsTangent, "Returns True if the surfaces are tangent at this point. IsTangent can be True when IsOnArc is True if IsPassingPnt is True and IsTangent is True,this point is a stopped point.", py::arg("PStart"));
cls_IntSurf_PathPointTool.def_static("Direction3d_", (gp_Vec (*)(const IntSurf_PathPoint &)) &IntSurf_PathPointTool::Direction3d, "returns the tangent at the intersection in 3d space associated to <P> an exception is raised if IsTangent is true.", py::arg("PStart"));
cls_IntSurf_PathPointTool.def_static("Direction2d_", (gp_Dir2d (*)(const IntSurf_PathPoint &)) &IntSurf_PathPointTool::Direction2d, "returns the tangent at the intersection in the parametric space of the parametrized surface.This tangent is associated to the value2d la tangente a un sens signifiant (indique le sens de chemin ement) an exception is raised if IsTangent is true.", py::arg("PStart"));
cls_IntSurf_PathPointTool.def_static("Multiplicity_", (Standard_Integer (*)(const IntSurf_PathPoint &)) &IntSurf_PathPointTool::Multiplicity, "Returns the multiplicity of the point i-e the number of auxillar parameters associated to the point which the principal parameters are given by Value2d", py::arg("PStart"));
cls_IntSurf_PathPointTool.def_static("Parameters_", [](const IntSurf_PathPoint & PStart, const Standard_Integer Mult, Standard_Real & U, Standard_Real & V){ IntSurf_PathPointTool::Parameters(PStart, Mult, U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Parametric coordinates associated to the multiplicity. An exception is raised if Mult<=0 or Mult>multiplicity.", py::arg("PStart"), py::arg("Mult"), py::arg("U"), py::arg("V"));

// Enums

}