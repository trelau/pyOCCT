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
#include <Adaptor3d_Curve.hxx>
#include <Adaptor3d_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <Extrema_POnCurv.hxx>
#include <Extrema_POnSurf.hxx>
#include <gp_Pnt.hxx>
#include <Adaptor3d_SurfacePtr.hxx>
#include <Extrema_ExtElCS.hxx>
#include <Extrema_SequenceOfPOnSurf.hxx>
#include <Extrema_SequenceOfPOnCurv.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <GeomAbs_SurfaceType.hxx>
#include <Extrema_ExtCS.hxx>

void bind_Extrema_ExtCS(py::module &mod){

py::class_<Extrema_ExtCS> cls_Extrema_ExtCS(mod, "Extrema_ExtCS", "It calculates all the extremum distances between a curve and a surface. These distances can be minimum or maximum.");

// Constructors
cls_Extrema_ExtCS.def(py::init<>());
cls_Extrema_ExtCS.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("S"), py::arg("TolC"), py::arg("TolS"));
cls_Extrema_ExtCS.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("S"), py::arg("UCinf"), py::arg("UCsup"), py::arg("Uinf"), py::arg("Usup"), py::arg("Vinf"), py::arg("Vsup"), py::arg("TolC"), py::arg("TolS"));

// Fields

// Methods
// cls_Extrema_ExtCS.def_static("operator new_", (void * (*)(size_t)) &Extrema_ExtCS::operator new, "None", py::arg("theSize"));
// cls_Extrema_ExtCS.def_static("operator delete_", (void (*)(void *)) &Extrema_ExtCS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ExtCS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ExtCS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ExtCS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ExtCS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ExtCS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ExtCS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ExtCS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ExtCS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ExtCS.def("Initialize", (void (Extrema_ExtCS::*)(const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtCS::Initialize, "Initializes the fields of the algorithm.", py::arg("S"), py::arg("Uinf"), py::arg("Usup"), py::arg("Vinf"), py::arg("Vsup"), py::arg("TolC"), py::arg("TolS"));
cls_Extrema_ExtCS.def("Perform", (void (Extrema_ExtCS::*)(const Adaptor3d_Curve &, const Standard_Real, const Standard_Real)) &Extrema_ExtCS::Perform, "Computes the distances. An exception is raised if the fieds have not been initialized.", py::arg("C"), py::arg("Uinf"), py::arg("Usup"));
cls_Extrema_ExtCS.def("IsDone", (Standard_Boolean (Extrema_ExtCS::*)() const) &Extrema_ExtCS::IsDone, "Returns True if the distances are found.");
cls_Extrema_ExtCS.def("IsParallel", (Standard_Boolean (Extrema_ExtCS::*)() const) &Extrema_ExtCS::IsParallel, "Returns True if the curve is on a parallel surface.");
cls_Extrema_ExtCS.def("NbExt", (Standard_Integer (Extrema_ExtCS::*)() const) &Extrema_ExtCS::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtCS.def("SquareDistance", (Standard_Real (Extrema_ExtCS::*)(const Standard_Integer) const) &Extrema_ExtCS::SquareDistance, "Returns the value of the Nth resulting square distance.", py::arg("N"));
cls_Extrema_ExtCS.def("Points", (void (Extrema_ExtCS::*)(const Standard_Integer, Extrema_POnCurv &, Extrema_POnSurf &) const) &Extrema_ExtCS::Points, "Returns the point of the Nth resulting distance.", py::arg("N"), py::arg("P1"), py::arg("P2"));

// Enums

}