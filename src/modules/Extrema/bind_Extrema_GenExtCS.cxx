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
#include <Adaptor3d_CurvePtr.hxx>
#include <Adaptor3d_SurfacePtr.hxx>
#include <Extrema_FuncExtCS.hxx>
#include <Standard_Handle.hxx>
#include <TColgp_HArray2OfPnt.hxx>
#include <Extrema_GenExtCS.hxx>

void bind_Extrema_GenExtCS(py::module &mod){

py::class_<Extrema_GenExtCS, std::unique_ptr<Extrema_GenExtCS, Deleter<Extrema_GenExtCS>>> cls_Extrema_GenExtCS(mod, "Extrema_GenExtCS", "It calculates all the extremum distances between acurve and a surface. These distances can be minimum or maximum.");

// Constructors
cls_Extrema_GenExtCS.def(py::init<>());
cls_Extrema_GenExtCS.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("S"), py::arg("NbT"), py::arg("NbU"), py::arg("NbV"), py::arg("Tol1"), py::arg("Tol2"));
cls_Extrema_GenExtCS.def(py::init<const Adaptor3d_Curve &, const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("C"), py::arg("S"), py::arg("NbT"), py::arg("NbU"), py::arg("NbV"), py::arg("tmin"), py::arg("tsup"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("Tol1"), py::arg("Tol2"));

// Fields

// Methods
// cls_Extrema_GenExtCS.def_static("operator new_", (void * (*)(size_t)) &Extrema_GenExtCS::operator new, "None", py::arg("theSize"));
// cls_Extrema_GenExtCS.def_static("operator delete_", (void (*)(void *)) &Extrema_GenExtCS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_GenExtCS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_GenExtCS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_GenExtCS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_GenExtCS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_GenExtCS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_GenExtCS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_GenExtCS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_GenExtCS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_GenExtCS.def("Initialize", (void (Extrema_GenExtCS::*)(const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real)) &Extrema_GenExtCS::Initialize, "None", py::arg("S"), py::arg("NbU"), py::arg("NbV"), py::arg("Tol2"));
cls_Extrema_GenExtCS.def("Initialize", (void (Extrema_GenExtCS::*)(const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_GenExtCS::Initialize, "None", py::arg("S"), py::arg("NbU"), py::arg("NbV"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("Tol2"));
cls_Extrema_GenExtCS.def("Perform", (void (Extrema_GenExtCS::*)(const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real)) &Extrema_GenExtCS::Perform, "the algorithm is done with S An exception is raised if the fields have not been initialized.", py::arg("C"), py::arg("NbT"), py::arg("Tol1"));
cls_Extrema_GenExtCS.def("Perform", (void (Extrema_GenExtCS::*)(const Adaptor3d_Curve &, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_GenExtCS::Perform, "the algorithm is done with C An exception is raised if the fields have not been initialized.", py::arg("C"), py::arg("NbT"), py::arg("tmin"), py::arg("tsup"), py::arg("Tol1"));
cls_Extrema_GenExtCS.def("IsDone", (Standard_Boolean (Extrema_GenExtCS::*)() const) &Extrema_GenExtCS::IsDone, "Returns True if the distances are found.");
cls_Extrema_GenExtCS.def("NbExt", (Standard_Integer (Extrema_GenExtCS::*)() const) &Extrema_GenExtCS::NbExt, "Returns the number of extremum distances.");
cls_Extrema_GenExtCS.def("SquareDistance", (Standard_Real (Extrema_GenExtCS::*)(const Standard_Integer) const) &Extrema_GenExtCS::SquareDistance, "Returns the value of the Nth resulting square distance.", py::arg("N"));
cls_Extrema_GenExtCS.def("PointOnCurve", (const Extrema_POnCurv & (Extrema_GenExtCS::*)(const Standard_Integer) const) &Extrema_GenExtCS::PointOnCurve, "Returns the point of the Nth resulting distance.", py::arg("N"));
cls_Extrema_GenExtCS.def("PointOnSurface", (const Extrema_POnSurf & (Extrema_GenExtCS::*)(const Standard_Integer) const) &Extrema_GenExtCS::PointOnSurface, "Returns the point of the Nth resulting distance.", py::arg("N"));

// Enums

}