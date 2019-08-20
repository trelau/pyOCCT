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
#include <LProp_CurAndInf.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom2dLProp_CurAndInf2d.hxx>

void bind_Geom2dLProp_CurAndInf2d(py::module &mod){

py::class_<Geom2dLProp_CurAndInf2d, std::unique_ptr<Geom2dLProp_CurAndInf2d>, LProp_CurAndInf> cls_Geom2dLProp_CurAndInf2d(mod, "Geom2dLProp_CurAndInf2d", "An algorithm for computing local properties of a curve. These properties include: - the maximum and minimum curvatures - the inflection points. A CurAndInf2d object provides the framework for: - defining the curve to be analyzed - implementing the computation algorithms - consulting the results.");

// Constructors
cls_Geom2dLProp_CurAndInf2d.def(py::init<>());

// Fields

// Methods
// cls_Geom2dLProp_CurAndInf2d.def_static("operator new_", (void * (*)(size_t)) &Geom2dLProp_CurAndInf2d::operator new, "None", py::arg("theSize"));
// cls_Geom2dLProp_CurAndInf2d.def_static("operator delete_", (void (*)(void *)) &Geom2dLProp_CurAndInf2d::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dLProp_CurAndInf2d.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dLProp_CurAndInf2d::operator new[], "None", py::arg("theSize"));
// cls_Geom2dLProp_CurAndInf2d.def_static("operator delete[]_", (void (*)(void *)) &Geom2dLProp_CurAndInf2d::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dLProp_CurAndInf2d.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dLProp_CurAndInf2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dLProp_CurAndInf2d.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dLProp_CurAndInf2d::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dLProp_CurAndInf2d.def("Perform", (void (Geom2dLProp_CurAndInf2d::*)(const opencascade::handle<Geom2d_Curve> &)) &Geom2dLProp_CurAndInf2d::Perform, "For the curve C, Computes both the inflection points and the maximum and minimum curvatures.", py::arg("C"));
cls_Geom2dLProp_CurAndInf2d.def("PerformCurExt", (void (Geom2dLProp_CurAndInf2d::*)(const opencascade::handle<Geom2d_Curve> &)) &Geom2dLProp_CurAndInf2d::PerformCurExt, "For the curve C, Computes the locals extremas of curvature.", py::arg("C"));
cls_Geom2dLProp_CurAndInf2d.def("PerformInf", (void (Geom2dLProp_CurAndInf2d::*)(const opencascade::handle<Geom2d_Curve> &)) &Geom2dLProp_CurAndInf2d::PerformInf, "For the curve C, Computes the inflections. After computation, the following functions can be used: - IsDone to check if the computation was successful - NbPoints to obtain the number of computed particular points - Parameter to obtain the parameter on the curve for each particular point - Type to check if the point is an inflection point or an extremum of curvature of the curve C. Warning These functions can be used to analyze a series of curves, however it is necessary to clear the table of results between each computation.", py::arg("C"));
cls_Geom2dLProp_CurAndInf2d.def("IsDone", (Standard_Boolean (Geom2dLProp_CurAndInf2d::*)() const) &Geom2dLProp_CurAndInf2d::IsDone, "True if the solutions are found.");

// Enums

}