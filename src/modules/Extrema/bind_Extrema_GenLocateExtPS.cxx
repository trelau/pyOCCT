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
#include <Adaptor3d_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <Precision.hxx>
#include <gp_Pnt.hxx>
#include <Extrema_POnSurf.hxx>
#include <Extrema_GenLocateExtPS.hxx>

void bind_Extrema_GenLocateExtPS(py::module &mod){

py::class_<Extrema_GenLocateExtPS, std::unique_ptr<Extrema_GenLocateExtPS, Deleter<Extrema_GenLocateExtPS>>> cls_Extrema_GenLocateExtPS(mod, "Extrema_GenLocateExtPS", "With a close point, it calculates the distance between a point and a surface. Criteria type is defined in 'Perform' method.");

// Constructors
cls_Extrema_GenLocateExtPS.def(py::init<const Adaptor3d_Surface &>(), py::arg("theS"));
cls_Extrema_GenLocateExtPS.def(py::init<const Adaptor3d_Surface &, const Standard_Real>(), py::arg("theS"), py::arg("theTolU"));
cls_Extrema_GenLocateExtPS.def(py::init<const Adaptor3d_Surface &, const Standard_Real, const Standard_Real>(), py::arg("theS"), py::arg("theTolU"), py::arg("theTolV"));

// Fields

// Methods
// cls_Extrema_GenLocateExtPS.def_static("operator new_", (void * (*)(size_t)) &Extrema_GenLocateExtPS::operator new, "None", py::arg("theSize"));
// cls_Extrema_GenLocateExtPS.def_static("operator delete_", (void (*)(void *)) &Extrema_GenLocateExtPS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_GenLocateExtPS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_GenLocateExtPS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_GenLocateExtPS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_GenLocateExtPS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_GenLocateExtPS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_GenLocateExtPS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_GenLocateExtPS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_GenLocateExtPS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_GenLocateExtPS.def("Perform", [](Extrema_GenLocateExtPS &self, const gp_Pnt & a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Perform(a0, a1, a2); });
cls_Extrema_GenLocateExtPS.def("Perform", (void (Extrema_GenLocateExtPS::*)(const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &Extrema_GenLocateExtPS::Perform, "Calculates the extrema between the point and the surface using a close point. The close point is defined by the parameter values theU0 and theV0. Type of the algorithm depends on the isDistanceCriteria flag. If flag value is false - normal projection criteria will be used. If flag value is true - distance criteria will be used.", py::arg("theP"), py::arg("theU0"), py::arg("theV0"), py::arg("isDistanceCriteria"));
cls_Extrema_GenLocateExtPS.def("IsDone", (Standard_Boolean (Extrema_GenLocateExtPS::*)() const) &Extrema_GenLocateExtPS::IsDone, "Returns True if the distance is found.");
cls_Extrema_GenLocateExtPS.def("SquareDistance", (Standard_Real (Extrema_GenLocateExtPS::*)() const) &Extrema_GenLocateExtPS::SquareDistance, "Returns the value of the extremum square distance.");
cls_Extrema_GenLocateExtPS.def("Point", (const Extrema_POnSurf & (Extrema_GenLocateExtPS::*)() const) &Extrema_GenLocateExtPS::Point, "Returns the point of the extremum distance.");

// Enums

}