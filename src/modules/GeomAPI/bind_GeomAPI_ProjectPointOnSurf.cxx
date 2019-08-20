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
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <Extrema_ExtAlgo.hxx>
#include <Standard_TypeDef.hxx>
#include <Extrema_ExtFlag.hxx>
#include <Extrema_ExtPS.hxx>
#include <GeomAdaptor_Surface.hxx>
#include <GeomAPI_ProjectPointOnSurf.hxx>

void bind_GeomAPI_ProjectPointOnSurf(py::module &mod){

py::class_<GeomAPI_ProjectPointOnSurf, std::unique_ptr<GeomAPI_ProjectPointOnSurf>> cls_GeomAPI_ProjectPointOnSurf(mod, "GeomAPI_ProjectPointOnSurf", "This class implements methods for computing all the orthogonal projections of a point onto a surface.");

// Constructors
cls_GeomAPI_ProjectPointOnSurf.def(py::init<>());
cls_GeomAPI_ProjectPointOnSurf.def(py::init<const gp_Pnt &, const opencascade::handle<Geom_Surface> &>(), py::arg("P"), py::arg("Surface"));
cls_GeomAPI_ProjectPointOnSurf.def(py::init<const gp_Pnt &, const opencascade::handle<Geom_Surface> &, const Extrema_ExtAlgo>(), py::arg("P"), py::arg("Surface"), py::arg("Algo"));
cls_GeomAPI_ProjectPointOnSurf.def(py::init<const gp_Pnt &, const opencascade::handle<Geom_Surface> &, const Standard_Real>(), py::arg("P"), py::arg("Surface"), py::arg("Tolerance"));
cls_GeomAPI_ProjectPointOnSurf.def(py::init<const gp_Pnt &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Extrema_ExtAlgo>(), py::arg("P"), py::arg("Surface"), py::arg("Tolerance"), py::arg("Algo"));
cls_GeomAPI_ProjectPointOnSurf.def(py::init<const gp_Pnt &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("Surface"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("Tolerance"));
cls_GeomAPI_ProjectPointOnSurf.def(py::init<const gp_Pnt &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Extrema_ExtAlgo>(), py::arg("P"), py::arg("Surface"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("Tolerance"), py::arg("Algo"));
cls_GeomAPI_ProjectPointOnSurf.def(py::init<const gp_Pnt &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("P"), py::arg("Surface"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"));
cls_GeomAPI_ProjectPointOnSurf.def(py::init<const gp_Pnt &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Extrema_ExtAlgo>(), py::arg("P"), py::arg("Surface"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("Algo"));

// Fields

// Methods
// cls_GeomAPI_ProjectPointOnSurf.def_static("operator new_", (void * (*)(size_t)) &GeomAPI_ProjectPointOnSurf::operator new, "None", py::arg("theSize"));
// cls_GeomAPI_ProjectPointOnSurf.def_static("operator delete_", (void (*)(void *)) &GeomAPI_ProjectPointOnSurf::operator delete, "None", py::arg("theAddress"));
// cls_GeomAPI_ProjectPointOnSurf.def_static("operator new[]_", (void * (*)(size_t)) &GeomAPI_ProjectPointOnSurf::operator new[], "None", py::arg("theSize"));
// cls_GeomAPI_ProjectPointOnSurf.def_static("operator delete[]_", (void (*)(void *)) &GeomAPI_ProjectPointOnSurf::operator delete[], "None", py::arg("theAddress"));
// cls_GeomAPI_ProjectPointOnSurf.def_static("operator new_", (void * (*)(size_t, void *)) &GeomAPI_ProjectPointOnSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomAPI_ProjectPointOnSurf.def_static("operator delete_", (void (*)(void *, void *)) &GeomAPI_ProjectPointOnSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomAPI_ProjectPointOnSurf.def("Init", [](GeomAPI_ProjectPointOnSurf &self, const gp_Pnt & a0, const opencascade::handle<Geom_Surface> & a1, const Standard_Real a2) -> void { return self.Init(a0, a1, a2); });
cls_GeomAPI_ProjectPointOnSurf.def("Init", (void (GeomAPI_ProjectPointOnSurf::*)(const gp_Pnt &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Extrema_ExtAlgo)) &GeomAPI_ProjectPointOnSurf::Init, "None", py::arg("P"), py::arg("Surface"), py::arg("Tolerance"), py::arg("Algo"));
cls_GeomAPI_ProjectPointOnSurf.def("Init", [](GeomAPI_ProjectPointOnSurf &self, const gp_Pnt & a0, const opencascade::handle<Geom_Surface> & a1) -> void { return self.Init(a0, a1); });
cls_GeomAPI_ProjectPointOnSurf.def("Init", (void (GeomAPI_ProjectPointOnSurf::*)(const gp_Pnt &, const opencascade::handle<Geom_Surface> &, const Extrema_ExtAlgo)) &GeomAPI_ProjectPointOnSurf::Init, "Init the projection of a point <P> on a surface <Surface>. The solution are computed in the domain [Umin,Usup] [Vmin,Vsup] of the surface.", py::arg("P"), py::arg("Surface"), py::arg("Algo"));
cls_GeomAPI_ProjectPointOnSurf.def("Init", [](GeomAPI_ProjectPointOnSurf &self, const gp_Pnt & a0, const opencascade::handle<Geom_Surface> & a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Real a5, const Standard_Real a6) -> void { return self.Init(a0, a1, a2, a3, a4, a5, a6); });
cls_GeomAPI_ProjectPointOnSurf.def("Init", (void (GeomAPI_ProjectPointOnSurf::*)(const gp_Pnt &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Extrema_ExtAlgo)) &GeomAPI_ProjectPointOnSurf::Init, "None", py::arg("P"), py::arg("Surface"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("Tolerance"), py::arg("Algo"));
cls_GeomAPI_ProjectPointOnSurf.def("Init", [](GeomAPI_ProjectPointOnSurf &self, const gp_Pnt & a0, const opencascade::handle<Geom_Surface> & a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Real a5) -> void { return self.Init(a0, a1, a2, a3, a4, a5); });
cls_GeomAPI_ProjectPointOnSurf.def("Init", (void (GeomAPI_ProjectPointOnSurf::*)(const gp_Pnt &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Extrema_ExtAlgo)) &GeomAPI_ProjectPointOnSurf::Init, "Init the projection for many points on a surface <Surface>. The solutions will be computed in the domain [Umin,Usup] [Vmin,Vsup] of the surface.", py::arg("P"), py::arg("Surface"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("Algo"));
cls_GeomAPI_ProjectPointOnSurf.def("Init", [](GeomAPI_ProjectPointOnSurf &self, const opencascade::handle<Geom_Surface> & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Real a5) -> void { return self.Init(a0, a1, a2, a3, a4, a5); });
cls_GeomAPI_ProjectPointOnSurf.def("Init", (void (GeomAPI_ProjectPointOnSurf::*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Extrema_ExtAlgo)) &GeomAPI_ProjectPointOnSurf::Init, "None", py::arg("Surface"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("Tolerance"), py::arg("Algo"));
cls_GeomAPI_ProjectPointOnSurf.def("Init", [](GeomAPI_ProjectPointOnSurf &self, const opencascade::handle<Geom_Surface> & a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4) -> void { return self.Init(a0, a1, a2, a3, a4); });
cls_GeomAPI_ProjectPointOnSurf.def("Init", (void (GeomAPI_ProjectPointOnSurf::*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Extrema_ExtAlgo)) &GeomAPI_ProjectPointOnSurf::Init, "None", py::arg("Surface"), py::arg("Umin"), py::arg("Usup"), py::arg("Vmin"), py::arg("Vsup"), py::arg("Algo"));
cls_GeomAPI_ProjectPointOnSurf.def("SetExtremaAlgo", (void (GeomAPI_ProjectPointOnSurf::*)(const Extrema_ExtAlgo)) &GeomAPI_ProjectPointOnSurf::SetExtremaAlgo, "Sets the Extrema search algorithm - Grad or Tree. By default the Extrema is initialized with Grad algorithm.", py::arg("theAlgo"));
cls_GeomAPI_ProjectPointOnSurf.def("SetExtremaFlag", (void (GeomAPI_ProjectPointOnSurf::*)(const Extrema_ExtFlag)) &GeomAPI_ProjectPointOnSurf::SetExtremaFlag, "Sets the Extrema search flag - MIN or MAX or MINMAX. By default the Extrema is set to search the MinMax solutions.", py::arg("theExtFlag"));
cls_GeomAPI_ProjectPointOnSurf.def("Perform", (void (GeomAPI_ProjectPointOnSurf::*)(const gp_Pnt &)) &GeomAPI_ProjectPointOnSurf::Perform, "Performs the projection of a point on the current surface.", py::arg("P"));
cls_GeomAPI_ProjectPointOnSurf.def("IsDone", (Standard_Boolean (GeomAPI_ProjectPointOnSurf::*)() const) &GeomAPI_ProjectPointOnSurf::IsDone, "None");
cls_GeomAPI_ProjectPointOnSurf.def("NbPoints", (Standard_Integer (GeomAPI_ProjectPointOnSurf::*)() const) &GeomAPI_ProjectPointOnSurf::NbPoints, "Returns the number of computed orthogonal projection points. Note: if projection fails, NbPoints returns 0.");
cls_GeomAPI_ProjectPointOnSurf.def("Point", (gp_Pnt (GeomAPI_ProjectPointOnSurf::*)(const Standard_Integer) const) &GeomAPI_ProjectPointOnSurf::Point, "Returns the orthogonal projection on the surface. Index is a number of a computed point. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbPoints ], where NbPoints is the number of solution points.", py::arg("Index"));
cls_GeomAPI_ProjectPointOnSurf.def("Parameters", [](GeomAPI_ProjectPointOnSurf &self, const Standard_Integer Index, Standard_Real & U, Standard_Real & V){ self.Parameters(Index, U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Returns the parameters (U,V) on the surface of the orthogonal projection. Index is a number of a computed point. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbPoints ], where NbPoints is the number of solution points.", py::arg("Index"), py::arg("U"), py::arg("V"));
cls_GeomAPI_ProjectPointOnSurf.def("Distance", (Standard_Real (GeomAPI_ProjectPointOnSurf::*)(const Standard_Integer) const) &GeomAPI_ProjectPointOnSurf::Distance, "Computes the distance between the point and its orthogonal projection on the surface. Index is a number of a computed point. Exceptions Standard_OutOfRange if Index is not in the range [ 1,NbPoints ], where NbPoints is the number of solution points.", py::arg("Index"));
cls_GeomAPI_ProjectPointOnSurf.def("NearestPoint", (gp_Pnt (GeomAPI_ProjectPointOnSurf::*)() const) &GeomAPI_ProjectPointOnSurf::NearestPoint, "Returns the nearest orthogonal projection of the point on the surface. Exceptions StdFail_NotDone if projection fails.");
cls_GeomAPI_ProjectPointOnSurf.def("LowerDistanceParameters", [](GeomAPI_ProjectPointOnSurf &self, Standard_Real & U, Standard_Real & V){ self.LowerDistanceParameters(U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Returns the parameters (U,V) on the surface of the nearest computed orthogonal projection of the point. Exceptions StdFail_NotDone if projection fails.", py::arg("U"), py::arg("V"));
cls_GeomAPI_ProjectPointOnSurf.def("LowerDistance", (Standard_Real (GeomAPI_ProjectPointOnSurf::*)() const) &GeomAPI_ProjectPointOnSurf::LowerDistance, "Computes the distance between the point and its nearest orthogonal projection on the surface. Exceptions StdFail_NotDone if projection fails.");
cls_GeomAPI_ProjectPointOnSurf.def("Extrema", (const Extrema_ExtPS & (GeomAPI_ProjectPointOnSurf::*)() const) &GeomAPI_ProjectPointOnSurf::Extrema, "return the algorithmic object from Extrema");

// Enums

}