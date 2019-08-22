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
#include <Extrema_ExtPElS.hxx>
#include <Extrema_GenExtPS.hxx>
#include <Extrema_SequenceOfPOnSurf.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <GeomAbs_SurfaceType.hxx>
#include <Standard_Handle.hxx>
#include <Extrema_ExtPExtS.hxx>
#include <Extrema_ExtPRevS.hxx>
#include <Extrema_ExtPS.hxx>

void bind_Extrema_ExtPS(py::module &mod){

py::class_<Extrema_ExtPS> cls_Extrema_ExtPS(mod, "Extrema_ExtPS", "It calculates all the extremum distances between a point and a surface. These distances can be minimum or maximum.");

// Constructors
cls_Extrema_ExtPS.def(py::init<>());
cls_Extrema_ExtPS.def(py::init<const gp_Pnt &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("S"), py::arg("TolU"), py::arg("TolV"));
cls_Extrema_ExtPS.def(py::init<const gp_Pnt &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Extrema_ExtFlag>(), py::arg("P"), py::arg("S"), py::arg("TolU"), py::arg("TolV"), py::arg("F"));
cls_Extrema_ExtPS.def(py::init<const gp_Pnt &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Extrema_ExtFlag, const Extrema_ExtAlgo>(), py::arg("P"), py::arg("S"), py::arg("TolU"), py::arg("TolV"), py::arg("F"), py::arg("A"));
cls_Extrema_ExtPS.def(py::init<const gp_Pnt &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("S"), py::arg("Uinf"), py::arg("Usup"), py::arg("Vinf"), py::arg("Vsup"), py::arg("TolU"), py::arg("TolV"));
cls_Extrema_ExtPS.def(py::init<const gp_Pnt &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Extrema_ExtFlag>(), py::arg("P"), py::arg("S"), py::arg("Uinf"), py::arg("Usup"), py::arg("Vinf"), py::arg("Vsup"), py::arg("TolU"), py::arg("TolV"), py::arg("F"));
cls_Extrema_ExtPS.def(py::init<const gp_Pnt &, const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Extrema_ExtFlag, const Extrema_ExtAlgo>(), py::arg("P"), py::arg("S"), py::arg("Uinf"), py::arg("Usup"), py::arg("Vinf"), py::arg("Vsup"), py::arg("TolU"), py::arg("TolV"), py::arg("F"), py::arg("A"));

// Fields

// Methods
// cls_Extrema_ExtPS.def_static("operator new_", (void * (*)(size_t)) &Extrema_ExtPS::operator new, "None", py::arg("theSize"));
// cls_Extrema_ExtPS.def_static("operator delete_", (void (*)(void *)) &Extrema_ExtPS::operator delete, "None", py::arg("theAddress"));
// cls_Extrema_ExtPS.def_static("operator new[]_", (void * (*)(size_t)) &Extrema_ExtPS::operator new[], "None", py::arg("theSize"));
// cls_Extrema_ExtPS.def_static("operator delete[]_", (void (*)(void *)) &Extrema_ExtPS::operator delete[], "None", py::arg("theAddress"));
// cls_Extrema_ExtPS.def_static("operator new_", (void * (*)(size_t, void *)) &Extrema_ExtPS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Extrema_ExtPS.def_static("operator delete_", (void (*)(void *, void *)) &Extrema_ExtPS::operator delete, "None", py::arg(""), py::arg(""));
cls_Extrema_ExtPS.def("Initialize", (void (Extrema_ExtPS::*)(const Adaptor3d_Surface &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &Extrema_ExtPS::Initialize, "Initializes the fields of the algorithm.", py::arg("S"), py::arg("Uinf"), py::arg("Usup"), py::arg("Vinf"), py::arg("Vsup"), py::arg("TolU"), py::arg("TolV"));
cls_Extrema_ExtPS.def("Perform", (void (Extrema_ExtPS::*)(const gp_Pnt &)) &Extrema_ExtPS::Perform, "Computes the distances. An exception is raised if the fieds have not been initialized.", py::arg("P"));
cls_Extrema_ExtPS.def("IsDone", (Standard_Boolean (Extrema_ExtPS::*)() const) &Extrema_ExtPS::IsDone, "Returns True if the distances are found.");
cls_Extrema_ExtPS.def("NbExt", (Standard_Integer (Extrema_ExtPS::*)() const) &Extrema_ExtPS::NbExt, "Returns the number of extremum distances.");
cls_Extrema_ExtPS.def("SquareDistance", (Standard_Real (Extrema_ExtPS::*)(const Standard_Integer) const) &Extrema_ExtPS::SquareDistance, "Returns the value of the Nth resulting square distance.", py::arg("N"));
cls_Extrema_ExtPS.def("Point", (const Extrema_POnSurf & (Extrema_ExtPS::*)(const Standard_Integer) const) &Extrema_ExtPS::Point, "Returns the point of the Nth resulting distance.", py::arg("N"));
cls_Extrema_ExtPS.def("TrimmedSquareDistances", [](Extrema_ExtPS &self, Standard_Real & dUfVf, Standard_Real & dUfVl, Standard_Real & dUlVf, Standard_Real & dUlVl, gp_Pnt & PUfVf, gp_Pnt & PUfVl, gp_Pnt & PUlVf, gp_Pnt & PUlVl){ self.TrimmedSquareDistances(dUfVf, dUfVl, dUlVf, dUlVl, PUfVf, PUfVl, PUlVf, PUlVl); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(dUfVf, dUfVl, dUlVf, dUlVl); }, "if the surface is a trimmed surface, dUfVf is a square distance between <P> and the point of parameter FirstUParameter and FirstVParameter <PUfVf>. dUfVl is a square distance between <P> and the point of parameter FirstUParameter and LastVParameter <PUfVl>. dUlVf is a square distance between <P> and the point of parameter LastUParameter and FirstVParameter <PUlVf>. dUlVl is a square distance between <P> and the point of parameter LastUParameter and LastVParameter <PUlVl>.", py::arg("dUfVf"), py::arg("dUfVl"), py::arg("dUlVf"), py::arg("dUlVl"), py::arg("PUfVf"), py::arg("PUfVl"), py::arg("PUlVf"), py::arg("PUlVl"));
cls_Extrema_ExtPS.def("SetFlag", (void (Extrema_ExtPS::*)(const Extrema_ExtFlag)) &Extrema_ExtPS::SetFlag, "None", py::arg("F"));
cls_Extrema_ExtPS.def("SetAlgo", (void (Extrema_ExtPS::*)(const Extrema_ExtAlgo)) &Extrema_ExtPS::SetAlgo, "None", py::arg("A"));

// Enums

}