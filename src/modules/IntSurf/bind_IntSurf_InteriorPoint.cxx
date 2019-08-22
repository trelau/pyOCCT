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
#include <gp_Vec.hxx>
#include <gp_Vec2d.hxx>
#include <IntSurf_InteriorPoint.hxx>

void bind_IntSurf_InteriorPoint(py::module &mod){

py::class_<IntSurf_InteriorPoint> cls_IntSurf_InteriorPoint(mod, "IntSurf_InteriorPoint", "Definition of a point solution of the intersection between an implicit an a parametrised surface. These points are passing points on the intersection lines, or starting points for the closed lines on the parametrised surface.");

// Constructors
cls_IntSurf_InteriorPoint.def(py::init<>());
cls_IntSurf_InteriorPoint.def(py::init<const gp_Pnt &, const Standard_Real, const Standard_Real, const gp_Vec &, const gp_Vec2d &>(), py::arg("P"), py::arg("U"), py::arg("V"), py::arg("Direc"), py::arg("Direc2d"));

// Fields

// Methods
// cls_IntSurf_InteriorPoint.def_static("operator new_", (void * (*)(size_t)) &IntSurf_InteriorPoint::operator new, "None", py::arg("theSize"));
// cls_IntSurf_InteriorPoint.def_static("operator delete_", (void (*)(void *)) &IntSurf_InteriorPoint::operator delete, "None", py::arg("theAddress"));
// cls_IntSurf_InteriorPoint.def_static("operator new[]_", (void * (*)(size_t)) &IntSurf_InteriorPoint::operator new[], "None", py::arg("theSize"));
// cls_IntSurf_InteriorPoint.def_static("operator delete[]_", (void (*)(void *)) &IntSurf_InteriorPoint::operator delete[], "None", py::arg("theAddress"));
// cls_IntSurf_InteriorPoint.def_static("operator new_", (void * (*)(size_t, void *)) &IntSurf_InteriorPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntSurf_InteriorPoint.def_static("operator delete_", (void (*)(void *, void *)) &IntSurf_InteriorPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_IntSurf_InteriorPoint.def("SetValue", (void (IntSurf_InteriorPoint::*)(const gp_Pnt &, const Standard_Real, const Standard_Real, const gp_Vec &, const gp_Vec2d &)) &IntSurf_InteriorPoint::SetValue, "None", py::arg("P"), py::arg("U"), py::arg("V"), py::arg("Direc"), py::arg("Direc2d"));
cls_IntSurf_InteriorPoint.def("Value", (const gp_Pnt & (IntSurf_InteriorPoint::*)() const) &IntSurf_InteriorPoint::Value, "Returns the 3d coordinates of the interior point.");
cls_IntSurf_InteriorPoint.def("Parameters", [](IntSurf_InteriorPoint &self, Standard_Real & U, Standard_Real & V){ self.Parameters(U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Returns the parameters of the interior point on the parametric surface.", py::arg("U"), py::arg("V"));
cls_IntSurf_InteriorPoint.def("UParameter", (Standard_Real (IntSurf_InteriorPoint::*)() const) &IntSurf_InteriorPoint::UParameter, "Returns the first parameter of the interior point on the parametric surface.");
cls_IntSurf_InteriorPoint.def("VParameter", (Standard_Real (IntSurf_InteriorPoint::*)() const) &IntSurf_InteriorPoint::VParameter, "Returns the second parameter of the interior point on the parametric surface.");
cls_IntSurf_InteriorPoint.def("Direction", (const gp_Vec & (IntSurf_InteriorPoint::*)() const) &IntSurf_InteriorPoint::Direction, "Returns the tangent at the intersection in 3d space associated to the interior point.");
cls_IntSurf_InteriorPoint.def("Direction2d", (const gp_Vec2d & (IntSurf_InteriorPoint::*)() const) &IntSurf_InteriorPoint::Direction2d, "Returns the tangent at the intersection in the parametric space of the parametric surface.");

// Enums

}