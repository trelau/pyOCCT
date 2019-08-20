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
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAdaptor_HSurface.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <IntPatch_RLine.hxx>
#include <Bnd_Box2d.hxx>
#include <GeomInt_VectorOfReal.hxx>
#include <IntPatch_WLine.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <Adaptor3d_TopolTool.hxx>
#include <IntPatch_Intersection.hxx>
#include <GeomInt_LineConstructor.hxx>
#include <TColGeom_SequenceOfCurve.hxx>
#include <TColGeom2d_SequenceOfCurve.hxx>
#include <GeomInt_IntSS.hxx>

void bind_GeomInt_IntSS(py::module &mod){

py::class_<GeomInt_IntSS, std::unique_ptr<GeomInt_IntSS>> cls_GeomInt_IntSS(mod, "GeomInt_IntSS", "None");

// Constructors
cls_GeomInt_IntSS.def(py::init<>());
cls_GeomInt_IntSS.def(py::init<const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const Standard_Real>(), py::arg("S1"), py::arg("S2"), py::arg("Tol"));
cls_GeomInt_IntSS.def(py::init<const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Boolean>(), py::arg("S1"), py::arg("S2"), py::arg("Tol"), py::arg("Approx"));
cls_GeomInt_IntSS.def(py::init<const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Boolean, const Standard_Boolean>(), py::arg("S1"), py::arg("S2"), py::arg("Tol"), py::arg("Approx"), py::arg("ApproxS1"));
cls_GeomInt_IntSS.def(py::init<const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("S1"), py::arg("S2"), py::arg("Tol"), py::arg("Approx"), py::arg("ApproxS1"), py::arg("ApproxS2"));

// Fields

// Methods
// cls_GeomInt_IntSS.def_static("operator new_", (void * (*)(size_t)) &GeomInt_IntSS::operator new, "None", py::arg("theSize"));
// cls_GeomInt_IntSS.def_static("operator delete_", (void (*)(void *)) &GeomInt_IntSS::operator delete, "None", py::arg("theAddress"));
// cls_GeomInt_IntSS.def_static("operator new[]_", (void * (*)(size_t)) &GeomInt_IntSS::operator new[], "None", py::arg("theSize"));
// cls_GeomInt_IntSS.def_static("operator delete[]_", (void (*)(void *)) &GeomInt_IntSS::operator delete[], "None", py::arg("theAddress"));
// cls_GeomInt_IntSS.def_static("operator new_", (void * (*)(size_t, void *)) &GeomInt_IntSS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomInt_IntSS.def_static("operator delete_", (void (*)(void *, void *)) &GeomInt_IntSS::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomInt_IntSS.def("Perform", [](GeomInt_IntSS &self, const opencascade::handle<Geom_Surface> & a0, const opencascade::handle<Geom_Surface> & a1, const Standard_Real a2) -> void { return self.Perform(a0, a1, a2); });
cls_GeomInt_IntSS.def("Perform", [](GeomInt_IntSS &self, const opencascade::handle<Geom_Surface> & a0, const opencascade::handle<Geom_Surface> & a1, const Standard_Real a2, const Standard_Boolean a3) -> void { return self.Perform(a0, a1, a2, a3); });
cls_GeomInt_IntSS.def("Perform", [](GeomInt_IntSS &self, const opencascade::handle<Geom_Surface> & a0, const opencascade::handle<Geom_Surface> & a1, const Standard_Real a2, const Standard_Boolean a3, const Standard_Boolean a4) -> void { return self.Perform(a0, a1, a2, a3, a4); });
cls_GeomInt_IntSS.def("Perform", (void (GeomInt_IntSS::*)(const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &GeomInt_IntSS::Perform, "general intersection of two surfaces", py::arg("S1"), py::arg("S2"), py::arg("Tol"), py::arg("Approx"), py::arg("ApproxS1"), py::arg("ApproxS2"));
cls_GeomInt_IntSS.def("Perform", [](GeomInt_IntSS &self, const opencascade::handle<GeomAdaptor_HSurface> & a0, const opencascade::handle<GeomAdaptor_HSurface> & a1, const Standard_Real a2) -> void { return self.Perform(a0, a1, a2); });
cls_GeomInt_IntSS.def("Perform", [](GeomInt_IntSS &self, const opencascade::handle<GeomAdaptor_HSurface> & a0, const opencascade::handle<GeomAdaptor_HSurface> & a1, const Standard_Real a2, const Standard_Boolean a3) -> void { return self.Perform(a0, a1, a2, a3); });
cls_GeomInt_IntSS.def("Perform", [](GeomInt_IntSS &self, const opencascade::handle<GeomAdaptor_HSurface> & a0, const opencascade::handle<GeomAdaptor_HSurface> & a1, const Standard_Real a2, const Standard_Boolean a3, const Standard_Boolean a4) -> void { return self.Perform(a0, a1, a2, a3, a4); });
cls_GeomInt_IntSS.def("Perform", (void (GeomInt_IntSS::*)(const opencascade::handle<GeomAdaptor_HSurface> &, const opencascade::handle<GeomAdaptor_HSurface> &, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &GeomInt_IntSS::Perform, "intersection of adapted surfaces", py::arg("HS1"), py::arg("HS2"), py::arg("Tol"), py::arg("Approx"), py::arg("ApproxS1"), py::arg("ApproxS2"));
cls_GeomInt_IntSS.def("Perform", [](GeomInt_IntSS &self, const opencascade::handle<Geom_Surface> & a0, const opencascade::handle<Geom_Surface> & a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Real a5, const Standard_Real a6) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6); });
cls_GeomInt_IntSS.def("Perform", [](GeomInt_IntSS &self, const opencascade::handle<Geom_Surface> & a0, const opencascade::handle<Geom_Surface> & a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Real a5, const Standard_Real a6, const Standard_Boolean a7) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_GeomInt_IntSS.def("Perform", [](GeomInt_IntSS &self, const opencascade::handle<Geom_Surface> & a0, const opencascade::handle<Geom_Surface> & a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Real a5, const Standard_Real a6, const Standard_Boolean a7, const Standard_Boolean a8) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7, a8); });
cls_GeomInt_IntSS.def("Perform", (void (GeomInt_IntSS::*)(const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &GeomInt_IntSS::Perform, "general intersection using a starting point", py::arg("S1"), py::arg("S2"), py::arg("Tol"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("Approx"), py::arg("ApproxS1"), py::arg("ApproxS2"));
cls_GeomInt_IntSS.def("Perform", [](GeomInt_IntSS &self, const opencascade::handle<GeomAdaptor_HSurface> & a0, const opencascade::handle<GeomAdaptor_HSurface> & a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Real a5, const Standard_Real a6) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6); });
cls_GeomInt_IntSS.def("Perform", [](GeomInt_IntSS &self, const opencascade::handle<GeomAdaptor_HSurface> & a0, const opencascade::handle<GeomAdaptor_HSurface> & a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Real a5, const Standard_Real a6, const Standard_Boolean a7) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7); });
cls_GeomInt_IntSS.def("Perform", [](GeomInt_IntSS &self, const opencascade::handle<GeomAdaptor_HSurface> & a0, const opencascade::handle<GeomAdaptor_HSurface> & a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Real a5, const Standard_Real a6, const Standard_Boolean a7, const Standard_Boolean a8) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7, a8); });
cls_GeomInt_IntSS.def("Perform", (void (GeomInt_IntSS::*)(const opencascade::handle<GeomAdaptor_HSurface> &, const opencascade::handle<GeomAdaptor_HSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &GeomInt_IntSS::Perform, "intersection of adapted surfaces using a starting point", py::arg("HS1"), py::arg("HS2"), py::arg("Tol"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("Approx"), py::arg("ApproxS1"), py::arg("ApproxS2"));
cls_GeomInt_IntSS.def("IsDone", (Standard_Boolean (GeomInt_IntSS::*)() const) &GeomInt_IntSS::IsDone, "None");
cls_GeomInt_IntSS.def("TolReached3d", (Standard_Real (GeomInt_IntSS::*)() const) &GeomInt_IntSS::TolReached3d, "None");
cls_GeomInt_IntSS.def("TolReached2d", (Standard_Real (GeomInt_IntSS::*)() const) &GeomInt_IntSS::TolReached2d, "None");
cls_GeomInt_IntSS.def("NbLines", (Standard_Integer (GeomInt_IntSS::*)() const) &GeomInt_IntSS::NbLines, "None");
cls_GeomInt_IntSS.def("Line", (const opencascade::handle<Geom_Curve> & (GeomInt_IntSS::*)(const Standard_Integer) const) &GeomInt_IntSS::Line, "None", py::arg("Index"));
cls_GeomInt_IntSS.def("HasLineOnS1", (Standard_Boolean (GeomInt_IntSS::*)(const Standard_Integer) const) &GeomInt_IntSS::HasLineOnS1, "None", py::arg("Index"));
cls_GeomInt_IntSS.def("LineOnS1", (const opencascade::handle<Geom2d_Curve> & (GeomInt_IntSS::*)(const Standard_Integer) const) &GeomInt_IntSS::LineOnS1, "None", py::arg("Index"));
cls_GeomInt_IntSS.def("HasLineOnS2", (Standard_Boolean (GeomInt_IntSS::*)(const Standard_Integer) const) &GeomInt_IntSS::HasLineOnS2, "None", py::arg("Index"));
cls_GeomInt_IntSS.def("LineOnS2", (const opencascade::handle<Geom2d_Curve> & (GeomInt_IntSS::*)(const Standard_Integer) const) &GeomInt_IntSS::LineOnS2, "None", py::arg("Index"));
cls_GeomInt_IntSS.def("NbBoundaries", (Standard_Integer (GeomInt_IntSS::*)() const) &GeomInt_IntSS::NbBoundaries, "None");
cls_GeomInt_IntSS.def("Boundary", (const opencascade::handle<Geom_Curve> & (GeomInt_IntSS::*)(const Standard_Integer) const) &GeomInt_IntSS::Boundary, "None", py::arg("Index"));
cls_GeomInt_IntSS.def("NbPoints", (Standard_Integer (GeomInt_IntSS::*)() const) &GeomInt_IntSS::NbPoints, "None");
cls_GeomInt_IntSS.def("Point", (gp_Pnt (GeomInt_IntSS::*)(const Standard_Integer) const) &GeomInt_IntSS::Point, "None", py::arg("Index"));
cls_GeomInt_IntSS.def("Pnt2d", (gp_Pnt2d (GeomInt_IntSS::*)(const Standard_Integer, const Standard_Boolean) const) &GeomInt_IntSS::Pnt2d, "None", py::arg("Index"), py::arg("OnFirst"));
// cls_GeomInt_IntSS.def("SetTolFixTangents", (void (GeomInt_IntSS::*)(const Standard_Real, const Standard_Real)) &GeomInt_IntSS::SetTolFixTangents, "None", py::arg("aTolCheck"), py::arg("aTolAngCheck"));
// cls_GeomInt_IntSS.def("TolFixTangents", [](GeomInt_IntSS &self, Standard_Real & aTolCheck, Standard_Real & aTolAngCheck){ self.TolFixTangents(aTolCheck, aTolAngCheck); return std::tuple<Standard_Real &, Standard_Real &>(aTolCheck, aTolAngCheck); }, "None", py::arg("aTolCheck"), py::arg("aTolAngCheck"));
cls_GeomInt_IntSS.def_static("TreatRLine_", [](const opencascade::handle<IntPatch_RLine> & theRL, const opencascade::handle<GeomAdaptor_HSurface> & theHS1, const opencascade::handle<GeomAdaptor_HSurface> & theHS2, opencascade::handle<Geom_Curve> & theC3d, opencascade::handle<Geom2d_Curve> & theC2d1, opencascade::handle<Geom2d_Curve> & theC2d2, Standard_Real & theTolReached){ GeomInt_IntSS::TreatRLine(theRL, theHS1, theHS2, theC3d, theC2d1, theC2d2, theTolReached); return theTolReached; }, "converts RLine to Geom(2d)_Curve.", py::arg("theRL"), py::arg("theHS1"), py::arg("theHS2"), py::arg("theC3d"), py::arg("theC2d1"), py::arg("theC2d2"), py::arg("theTolReached"));
cls_GeomInt_IntSS.def_static("BuildPCurves_", [](const Standard_Real f, const Standard_Real l, Standard_Real & Tol, const opencascade::handle<Geom_Surface> & S, const opencascade::handle<Geom_Curve> & C, opencascade::handle<Geom2d_Curve> & C2d){ GeomInt_IntSS::BuildPCurves(f, l, Tol, S, C, C2d); return Tol; }, "creates 2D-curve on given surface from given 3D-curve", py::arg("f"), py::arg("l"), py::arg("Tol"), py::arg("S"), py::arg("C"), py::arg("C2d"));
cls_GeomInt_IntSS.def_static("TrimILineOnSurfBoundaries_", (void (*)(const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Bnd_Box2d &, const Bnd_Box2d &, GeomInt_VectorOfReal &)) &GeomInt_IntSS::TrimILineOnSurfBoundaries, "puts into theArrayOfParameters the parameters of intersection points of given theC2d1 and theC2d2 curves with the boundaries of the source surface.", py::arg("theC2d1"), py::arg("theC2d2"), py::arg("theBound1"), py::arg("theBound2"), py::arg("theArrayOfParameters"));
cls_GeomInt_IntSS.def_static("MakeBSpline_", (opencascade::handle<Geom_Curve> (*)(const opencascade::handle<IntPatch_WLine> &, const Standard_Integer, const Standard_Integer)) &GeomInt_IntSS::MakeBSpline, "None", py::arg("WL"), py::arg("ideb"), py::arg("ifin"));
cls_GeomInt_IntSS.def_static("MakeBSpline2d_", (opencascade::handle<Geom2d_BSplineCurve> (*)(const opencascade::handle<IntPatch_WLine> &, const Standard_Integer, const Standard_Integer, const Standard_Boolean)) &GeomInt_IntSS::MakeBSpline2d, "None", py::arg("theWLine"), py::arg("ideb"), py::arg("ifin"), py::arg("onFirst"));

// Enums

}