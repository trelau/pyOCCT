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
#include <Extrema_POnSurf.hxx>
#include <Adaptor3d_SurfacePtr.hxx>
#include <Standard_Handle.hxx>
#include <TColgp_HArray2OfPnt.hxx>
#include <Extrema_FuncExtSS.hxx>
#include <Extrema_GenExtSS.hxx>

void bind_Extrema_GenExtSS(py::module &mod){

py::class_<Extrema_GenExtSS, std::unique_ptr<Extrema_GenExtSS>> cls_Extrema_GenExtSS(mod, "Extrema_GenExtSS", "It calculates all the extremum distances between two surfaces. These distances can be minimum or maximum.");

// Constructors
cls_Extrema_GenExtSS.def(py::init<>());
cls_Extrema_GenExtSS.def(py::init<const Adaptor3d_Surface &, const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("S1"), py::arg("S2"), py::arg("NbU"), py::arg("NbV"), py::arg("Tol1"), py::arg("Tol2"));
cls_Extrema_GenExtSS.def(py::init<const Adaptor3d_Surface &, const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("S1"), py::arg("S2"), py::arg("NbU"), py::arg("NbV"), py::arg("U1min"), py::arg("U1sup"), py::arg("V1min"), py::arg("V1sup"), py::arg("U2min"), py::arg("U2sup"), py::arg("V2min"), py::arg("V2sup"), py::arg("Tol1"), py::arg("Tol2"));

// Fields

// Methods
// cls_Extrema_GenExtSS.def_static("operator new_", (void * (*)(size_t)) &Extrema_GenExtSS::operator new, "None", py::arg("theSize"));
// cls_Extrema_GenExtSS.def_static("operator delete_", (void (*)(void *)) &Extrema_GenExtSS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_GenExtSS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_GenExtSS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_GenExtSS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_GenExtSS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_GenExtSS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_GenExtSS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_GenExtSS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_GenExtSS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_GenExtSS.def("Initialize", (void (Extrema_GenExtSS::*)(const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real)) &Extrema_GenExtSS::Initialize, "None", py::arg("S2"), py::arg("NbU"), py::arg("NbV"), py::arg("Tol2"));
cls_Extrema_GenExtSS.def("Initialize", (void (Extrema_GenExtSS::*)(const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_GenExtSS::Initialize, "None", py::arg("S2"), py::arg("NbU"), py::arg("NbV"), py::arg("U2min"), py::arg("U2sup"), py::arg("V2min"), py::arg("V2sup"), py::arg("Tol2"));
cls_Extrema_GenExtSS.def("Perform", (void (Extrema_GenExtSS::*)(const Adaptor3d_Surface &, const Standard_Real)) &Extrema_GenExtSS::Perform, "the algorithm is done with S1 An exception is raised if the fields have not been initialized.", py::arg("S1"), py::arg("Tol1"));
cls_Extrema_GenExtSS.def("Perform", (void (Extrema_GenExtSS::*)(const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_GenExtSS::Perform, "the algorithm is done withS1 An exception is raised if the fields have not been initialized.", py::arg("S1"), py::arg("U1min"), py::arg("U1sup"), py::arg("V1min"), py::arg("V1sup"), py::arg("Tol1"));
cls_Extrema_GenExtSS.def("IsDone", (Standard_Boolean (Extrema_GenExtSS::*)() const) &Extrema_GenExtSS::IsDone, "Returns True if the distances are found.");
cls_Extrema_GenExtSS.def("NbExt", (Standard_Integer (Extrema_GenExtSS::*)() const) &Extrema_GenExtSS::NbExt, "Returns the number of extremum distances.");
cls_Extrema_GenExtSS.def("SquareDistance", (Standard_Real (Extrema_GenExtSS::*)(const Standard_Integer) const) &Extrema_GenExtSS::SquareDistance, "Returns the value of the Nth resulting square distance.", py::arg("N"));
cls_Extrema_GenExtSS.def("PointOnS1", (const Extrema_POnSurf & (Extrema_GenExtSS::*)(const Standard_Integer) const) &Extrema_GenExtSS::PointOnS1, "Returns the point of the Nth resulting distance.", py::arg("N"));
cls_Extrema_GenExtSS.def("PointOnS2", (const Extrema_POnSurf & (Extrema_GenExtSS::*)(const Standard_Integer) const) &Extrema_GenExtSS::PointOnS2, "Returns the point of the Nth resulting distance.", py::arg("N"));

// Enums

}