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
#include <Adaptor3d_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <Extrema_ExtFlag.hxx>
#include <Extrema_ExtAlgo.hxx>
#include <Extrema_POnSurf.hxx>
#include <Adaptor3d_SurfacePtr.hxx>
#include <Extrema_POnSurfParams.hxx>
#include <Standard_Handle.hxx>
#include <Extrema_HArray2OfPOnSurfParams.hxx>
#include <Extrema_HUBTreeOfSphere.hxx>
#include <Bnd_HArray1OfSphere.hxx>
#include <Extrema_FuncPSNorm.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <Extrema_GenExtPS.hxx>

void bind_Extrema_GenExtPS(py::module &mod){

py::class_<Extrema_GenExtPS, std::unique_ptr<Extrema_GenExtPS>> cls_Extrema_GenExtPS(mod, "Extrema_GenExtPS", "It calculates all the extremum distances between a point and a surface. These distances can be minimum or maximum.");

// Constructors
cls_Extrema_GenExtPS.def(py::init<>());
cls_Extrema_GenExtPS.def(py::init<const gp_Pnt &, const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("S"), py::arg("NbU"), py::arg("NbV"), py::arg("TolU"), py::arg("TolV"));
cls_Extrema_GenExtPS.def(py::init<const gp_Pnt &, const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Extrema_ExtFlag>(), py::arg("P"), py::arg("S"), py::arg("NbU"), py::arg("NbV"), py::arg("TolU"), py::arg("TolV"), py::arg("F"));
cls_Extrema_GenExtPS.def(py::init<const gp_Pnt &, const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Extrema_ExtFlag, const Extrema_ExtAlgo>(), py::arg("P"), py::arg("S"), py::arg("NbU"), py::arg("NbV"), py::arg("TolU"), py::arg("TolV"), py::arg("F"), py::arg("A"));
cls_Extrema_GenExtPS.def(py::init<const gp_Pnt &, const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("S"), py::arg("NbU"), py::arg("NbV"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("TolU"), py::arg("TolV"));
cls_Extrema_GenExtPS.def(py::init<const gp_Pnt &, const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Extrema_ExtFlag>(), py::arg("P"), py::arg("S"), py::arg("NbU"), py::arg("NbV"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("TolU"), py::arg("TolV"), py::arg("F"));
cls_Extrema_GenExtPS.def(py::init<const gp_Pnt &, const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Extrema_ExtFlag, const Extrema_ExtAlgo>(), py::arg("P"), py::arg("S"), py::arg("NbU"), py::arg("NbV"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("TolU"), py::arg("TolV"), py::arg("F"), py::arg("A"));

// Fields

// Methods
// cls_Extrema_GenExtPS.def_static("operator new_", (void * (*)(size_t)) &Extrema_GenExtPS::operator new, "None", py::arg("theSize"));
// cls_Extrema_GenExtPS.def_static("operator delete_", (void (*)(void *)) &Extrema_GenExtPS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_GenExtPS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_GenExtPS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_GenExtPS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_GenExtPS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_GenExtPS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_GenExtPS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_GenExtPS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_GenExtPS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_GenExtPS.def("Initialize", (void (Extrema_GenExtPS::*)(const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real)) &Extrema_GenExtPS::Initialize, "None", py::arg("S"), py::arg("NbU"), py::arg("NbV"), py::arg("TolU"), py::arg("TolV"));
cls_Extrema_GenExtPS.def("Initialize", (void (Extrema_GenExtPS::*)(const Adaptor3d_Surface &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_GenExtPS::Initialize, "None", py::arg("S"), py::arg("NbU"), py::arg("NbV"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("TolU"), py::arg("TolV"));
cls_Extrema_GenExtPS.def("Perform", (void (Extrema_GenExtPS::*)(const gp_Pnt &)) &Extrema_GenExtPS::Perform, "the algorithm is done with the point P. An exception is raised if the fields have not been initialized.", py::arg("P"));
cls_Extrema_GenExtPS.def("SetFlag", (void (Extrema_GenExtPS::*)(const Extrema_ExtFlag)) &Extrema_GenExtPS::SetFlag, "None", py::arg("F"));
cls_Extrema_GenExtPS.def("SetAlgo", (void (Extrema_GenExtPS::*)(const Extrema_ExtAlgo)) &Extrema_GenExtPS::SetAlgo, "None", py::arg("A"));
cls_Extrema_GenExtPS.def("IsDone", (Standard_Boolean (Extrema_GenExtPS::*)() const) &Extrema_GenExtPS::IsDone, "Returns True if the distances are found.");
cls_Extrema_GenExtPS.def("NbExt", (Standard_Integer (Extrema_GenExtPS::*)() const) &Extrema_GenExtPS::NbExt, "Returns the number of extremum distances.");
cls_Extrema_GenExtPS.def("SquareDistance", (Standard_Real (Extrema_GenExtPS::*)(const Standard_Integer) const) &Extrema_GenExtPS::SquareDistance, "Returns the value of the Nth resulting square distance.", py::arg("N"));
cls_Extrema_GenExtPS.def("Point", (const Extrema_POnSurf & (Extrema_GenExtPS::*)(const Standard_Integer) const) &Extrema_GenExtPS::Point, "Returns the point of the Nth resulting distance.", py::arg("N"));

// Enums

}