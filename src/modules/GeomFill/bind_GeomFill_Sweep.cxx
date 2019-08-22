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
#include <GeomFill_LocationLaw.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomFill_SectionLaw.hxx>
#include <GeomFill_ApproxStyle.hxx>
#include <GeomAbs_Shape.hxx>
#include <Geom_Surface.hxx>
#include <Geom2d_Curve.hxx>
#include <TColGeom2d_HArray1OfCurve.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <GeomFill_Sweep.hxx>

void bind_GeomFill_Sweep(py::module &mod){

py::class_<GeomFill_Sweep> cls_GeomFill_Sweep(mod, "GeomFill_Sweep", "Geometrical Sweep Algorithm");

// Constructors
cls_GeomFill_Sweep.def(py::init<const opencascade::handle<GeomFill_LocationLaw> &>(), py::arg("Location"));
cls_GeomFill_Sweep.def(py::init<const opencascade::handle<GeomFill_LocationLaw> &, const Standard_Boolean>(), py::arg("Location"), py::arg("WithKpart"));

// Fields

// Methods
// cls_GeomFill_Sweep.def_static("operator new_", (void * (*)(size_t)) &GeomFill_Sweep::operator new, "None", py::arg("theSize"));
// cls_GeomFill_Sweep.def_static("operator delete_", (void (*)(void *)) &GeomFill_Sweep::operator delete, "None", py::arg("theAddress"));
// cls_GeomFill_Sweep.def_static("operator new[]_", (void * (*)(size_t)) &GeomFill_Sweep::operator new[], "None", py::arg("theSize"));
// cls_GeomFill_Sweep.def_static("operator delete[]_", (void (*)(void *)) &GeomFill_Sweep::operator delete[], "None", py::arg("theAddress"));
// cls_GeomFill_Sweep.def_static("operator new_", (void * (*)(size_t, void *)) &GeomFill_Sweep::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomFill_Sweep.def_static("operator delete_", (void (*)(void *, void *)) &GeomFill_Sweep::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomFill_Sweep.def("SetDomain", (void (GeomFill_Sweep::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomFill_Sweep::SetDomain, "Set parametric information [<First>, <Last>] Sets the parametric bound of the sweeping surface to build. <SectionFirst>, <SectionLast> gives coresponding bounds parameter on the section law of <First> and <Last>", py::arg("First"), py::arg("Last"), py::arg("SectionFirst"), py::arg("SectionLast"));
cls_GeomFill_Sweep.def("SetTolerance", [](GeomFill_Sweep &self, const Standard_Real a0) -> void { return self.SetTolerance(a0); });
cls_GeomFill_Sweep.def("SetTolerance", [](GeomFill_Sweep &self, const Standard_Real a0, const Standard_Real a1) -> void { return self.SetTolerance(a0, a1); });
cls_GeomFill_Sweep.def("SetTolerance", [](GeomFill_Sweep &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.SetTolerance(a0, a1, a2); });
cls_GeomFill_Sweep.def("SetTolerance", (void (GeomFill_Sweep::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomFill_Sweep::SetTolerance, "Set Approximation Tolerance Tol3d : Tolerance to surface approximation Tol2d : Tolerance used to perform curve approximation Normaly the 2d curve are approximated with a tolerance given by the resolution method define in <LocationLaw> but if this tolerance is too large Tol2d is used. TolAngular : Tolerance (in radian) to control the angle beetween tangents on the section law and tangent of iso-v on approximed surface", py::arg("Tol3d"), py::arg("BoundTol"), py::arg("Tol2d"), py::arg("TolAngular"));
cls_GeomFill_Sweep.def("SetForceApproxC1", (void (GeomFill_Sweep::*)(const Standard_Boolean)) &GeomFill_Sweep::SetForceApproxC1, "Set the flag that indicates attempt to approximate a C1-continuous surface if a swept surface proved to be C0.", py::arg("ForceApproxC1"));
cls_GeomFill_Sweep.def("ExchangeUV", (Standard_Boolean (GeomFill_Sweep::*)() const) &GeomFill_Sweep::ExchangeUV, "returns true if sections are U-Iso This can be produce in some cases when <WithKpart> is True.");
cls_GeomFill_Sweep.def("UReversed", (Standard_Boolean (GeomFill_Sweep::*)() const) &GeomFill_Sweep::UReversed, "returns true if Parametrisation sens in U is inverse of parametrisation sens of section (or of path if ExchangeUV)");
cls_GeomFill_Sweep.def("VReversed", (Standard_Boolean (GeomFill_Sweep::*)() const) &GeomFill_Sweep::VReversed, "returns true if Parametrisation sens in V is inverse of parametrisation sens of path (or of section if ExchangeUV)");
cls_GeomFill_Sweep.def("Build", [](GeomFill_Sweep &self, const opencascade::handle<GeomFill_SectionLaw> & a0) -> void { return self.Build(a0); });
cls_GeomFill_Sweep.def("Build", [](GeomFill_Sweep &self, const opencascade::handle<GeomFill_SectionLaw> & a0, const GeomFill_ApproxStyle a1) -> void { return self.Build(a0, a1); });
cls_GeomFill_Sweep.def("Build", [](GeomFill_Sweep &self, const opencascade::handle<GeomFill_SectionLaw> & a0, const GeomFill_ApproxStyle a1, const GeomAbs_Shape a2) -> void { return self.Build(a0, a1, a2); });
cls_GeomFill_Sweep.def("Build", [](GeomFill_Sweep &self, const opencascade::handle<GeomFill_SectionLaw> & a0, const GeomFill_ApproxStyle a1, const GeomAbs_Shape a2, const Standard_Integer a3) -> void { return self.Build(a0, a1, a2, a3); });
cls_GeomFill_Sweep.def("Build", (void (GeomFill_Sweep::*)(const opencascade::handle<GeomFill_SectionLaw> &, const GeomFill_ApproxStyle, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer)) &GeomFill_Sweep::Build, "Build the Sweeep Surface ApproxStyle defines Approximation Strategy - GeomFill_Section : The composed Function : Location X Section is directly approximed. - GeomFill_Location : The location law is approximed, and the SweepSurface is build algebric composition of approximed location law and section law This option is Ok, if Section.Surface() methode is effective. Continuity : The continuity in v waiting on the surface Degmax : The maximum degree in v requiered on the surface Segmax : The maximum number of span in v requiered on the surface", py::arg("Section"), py::arg("Methode"), py::arg("Continuity"), py::arg("Degmax"), py::arg("Segmax"));
cls_GeomFill_Sweep.def("IsDone", (Standard_Boolean (GeomFill_Sweep::*)() const) &GeomFill_Sweep::IsDone, "Tells if the Surface is Buildt.");
cls_GeomFill_Sweep.def("ErrorOnSurface", (Standard_Real (GeomFill_Sweep::*)() const) &GeomFill_Sweep::ErrorOnSurface, "Gets the Approximation error.");
cls_GeomFill_Sweep.def("ErrorOnRestriction", [](GeomFill_Sweep &self, const Standard_Boolean IsFirst, Standard_Real & UError, Standard_Real & VError){ self.ErrorOnRestriction(IsFirst, UError, VError); return std::tuple<Standard_Real &, Standard_Real &>(UError, VError); }, "Gets the Approximation error.", py::arg("IsFirst"), py::arg("UError"), py::arg("VError"));
cls_GeomFill_Sweep.def("ErrorOnTrace", [](GeomFill_Sweep &self, const Standard_Integer IndexOfTrace, Standard_Real & UError, Standard_Real & VError){ self.ErrorOnTrace(IndexOfTrace, UError, VError); return std::tuple<Standard_Real &, Standard_Real &>(UError, VError); }, "Gets the Approximation error.", py::arg("IndexOfTrace"), py::arg("UError"), py::arg("VError"));
cls_GeomFill_Sweep.def("Surface", (opencascade::handle<Geom_Surface> (GeomFill_Sweep::*)() const) &GeomFill_Sweep::Surface, "None");
cls_GeomFill_Sweep.def("Restriction", (opencascade::handle<Geom2d_Curve> (GeomFill_Sweep::*)(const Standard_Boolean) const) &GeomFill_Sweep::Restriction, "None", py::arg("IsFirst"));
cls_GeomFill_Sweep.def("NumberOfTrace", (Standard_Integer (GeomFill_Sweep::*)() const) &GeomFill_Sweep::NumberOfTrace, "None");
cls_GeomFill_Sweep.def("Trace", (opencascade::handle<Geom2d_Curve> (GeomFill_Sweep::*)(const Standard_Integer) const) &GeomFill_Sweep::Trace, "None", py::arg("IndexOfTrace"));

// Enums

}