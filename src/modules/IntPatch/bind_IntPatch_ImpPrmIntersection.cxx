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
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_TopolTool.hxx>
#include <Standard_TypeDef.hxx>
#include <IntPatch_Point.hxx>
#include <IntPatch_Line.hxx>
#include <IntPatch_SequenceOfPoint.hxx>
#include <IntPatch_SequenceOfLine.hxx>
#include <IntPatch_TheSOnBounds.hxx>
#include <IntPatch_TheSearchInside.hxx>
#include <IntPatch_ImpPrmIntersection.hxx>

void bind_IntPatch_ImpPrmIntersection(py::module &mod){

py::class_<IntPatch_ImpPrmIntersection> cls_IntPatch_ImpPrmIntersection(mod, "IntPatch_ImpPrmIntersection", "Implementation of the intersection between a natural quadric patch : Plane, Cone, Cylinder or Sphere and a bi-parametrised surface.");

// Constructors
cls_IntPatch_ImpPrmIntersection.def(py::init<>());
cls_IntPatch_ImpPrmIntersection.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Surf1"), py::arg("D1"), py::arg("Surf2"), py::arg("D2"), py::arg("TolArc"), py::arg("TolTang"), py::arg("Fleche"), py::arg("Pas"));

// Fields

// Methods
// cls_IntPatch_ImpPrmIntersection.def_static("operator new_", (void * (*)(size_t)) &IntPatch_ImpPrmIntersection::operator new, "None", py::arg("theSize"));
// cls_IntPatch_ImpPrmIntersection.def_static("operator delete_", (void (*)(void *)) &IntPatch_ImpPrmIntersection::operator delete, "None", py::arg("theAddress"));
// cls_IntPatch_ImpPrmIntersection.def_static("operator new[]_", (void * (*)(size_t)) &IntPatch_ImpPrmIntersection::operator new[], "None", py::arg("theSize"));
// cls_IntPatch_ImpPrmIntersection.def_static("operator delete[]_", (void (*)(void *)) &IntPatch_ImpPrmIntersection::operator delete[], "None", py::arg("theAddress"));
// cls_IntPatch_ImpPrmIntersection.def_static("operator new_", (void * (*)(size_t, void *)) &IntPatch_ImpPrmIntersection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPatch_ImpPrmIntersection.def_static("operator delete_", (void (*)(void *, void *)) &IntPatch_ImpPrmIntersection::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPatch_ImpPrmIntersection.def("SetStartPoint", (void (IntPatch_ImpPrmIntersection::*)(const Standard_Real, const Standard_Real)) &IntPatch_ImpPrmIntersection::SetStartPoint, "to search for solution from the given point", py::arg("U"), py::arg("V"));
cls_IntPatch_ImpPrmIntersection.def("Perform", (void (IntPatch_ImpPrmIntersection::*)(const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntPatch_ImpPrmIntersection::Perform, "None", py::arg("Surf1"), py::arg("D1"), py::arg("Surf2"), py::arg("D2"), py::arg("TolArc"), py::arg("TolTang"), py::arg("Fleche"), py::arg("Pas"));
cls_IntPatch_ImpPrmIntersection.def("IsDone", (Standard_Boolean (IntPatch_ImpPrmIntersection::*)() const) &IntPatch_ImpPrmIntersection::IsDone, "Returns true if the calculus was succesfull.");
cls_IntPatch_ImpPrmIntersection.def("IsEmpty", (Standard_Boolean (IntPatch_ImpPrmIntersection::*)() const) &IntPatch_ImpPrmIntersection::IsEmpty, "Returns true if the is no intersection.");
cls_IntPatch_ImpPrmIntersection.def("NbPnts", (Standard_Integer (IntPatch_ImpPrmIntersection::*)() const) &IntPatch_ImpPrmIntersection::NbPnts, "Returns the number of 'single' points.");
cls_IntPatch_ImpPrmIntersection.def("Point", (const IntPatch_Point & (IntPatch_ImpPrmIntersection::*)(const Standard_Integer) const) &IntPatch_ImpPrmIntersection::Point, "Returns the point of range Index. An exception is raised if Index<=0 or Index>NbPnt.", py::arg("Index"));
cls_IntPatch_ImpPrmIntersection.def("NbLines", (Standard_Integer (IntPatch_ImpPrmIntersection::*)() const) &IntPatch_ImpPrmIntersection::NbLines, "Returns the number of intersection lines.");
cls_IntPatch_ImpPrmIntersection.def("Line", (const opencascade::handle<IntPatch_Line> & (IntPatch_ImpPrmIntersection::*)(const Standard_Integer) const) &IntPatch_ImpPrmIntersection::Line, "Returns the line of range Index. An exception is raised if Index<=0 or Index>NbLine.", py::arg("Index"));

// Enums

}