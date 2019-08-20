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
#include <Geom_Curve.hxx>
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <IntCurveSurface_HInter.hxx>
#include <GeomAPI_IntCS.hxx>

void bind_GeomAPI_IntCS(py::module &mod){

py::class_<GeomAPI_IntCS, std::unique_ptr<GeomAPI_IntCS>> cls_GeomAPI_IntCS(mod, "GeomAPI_IntCS", "This class implements methods for computing intersection points and segments between a");

// Constructors
cls_GeomAPI_IntCS.def(py::init<>());
cls_GeomAPI_IntCS.def(py::init<const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Surface> &>(), py::arg("C"), py::arg("S"));

// Fields

// Methods
// cls_GeomAPI_IntCS.def_static("operator new_", (void * (*)(size_t)) &GeomAPI_IntCS::operator new, "None", py::arg("theSize"));
// cls_GeomAPI_IntCS.def_static("operator delete_", (void (*)(void *)) &GeomAPI_IntCS::operator delete, "None", py::arg("theAddress"));
// cls_GeomAPI_IntCS.def_static("operator new[]_", (void * (*)(size_t)) &GeomAPI_IntCS::operator new[], "None", py::arg("theSize"));
// cls_GeomAPI_IntCS.def_static("operator delete[]_", (void (*)(void *)) &GeomAPI_IntCS::operator delete[], "None", py::arg("theAddress"));
// cls_GeomAPI_IntCS.def_static("operator new_", (void * (*)(size_t, void *)) &GeomAPI_IntCS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomAPI_IntCS.def_static("operator delete_", (void (*)(void *, void *)) &GeomAPI_IntCS::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomAPI_IntCS.def("Perform", (void (GeomAPI_IntCS::*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Surface> &)) &GeomAPI_IntCS::Perform, "This function Initializes an algorithm with the curve C and the surface S and computes the intersections between C and S. Warning Use function IsDone to verify that the intersections are computed successfully.", py::arg("C"), py::arg("S"));
cls_GeomAPI_IntCS.def("IsDone", (Standard_Boolean (GeomAPI_IntCS::*)() const) &GeomAPI_IntCS::IsDone, "Returns true if the intersections are successfully computed.");
cls_GeomAPI_IntCS.def("NbPoints", (Standard_Integer (GeomAPI_IntCS::*)() const) &GeomAPI_IntCS::NbPoints, "Returns the number of Intersection Points if IsDone returns True. else NotDone is raised.");
cls_GeomAPI_IntCS.def("Point", (const gp_Pnt & (GeomAPI_IntCS::*)(const Standard_Integer) const) &GeomAPI_IntCS::Point, "Returns the Intersection Point of range <Index>in case of cross intersection. Raises NotDone if the computation has failed or if the computation has not been done raises OutOfRange if Index is not in the range <1..NbPoints>", py::arg("Index"));
cls_GeomAPI_IntCS.def("Parameters", [](GeomAPI_IntCS &self, const Standard_Integer Index, Standard_Real & U, Standard_Real & V, Standard_Real & W){ self.Parameters(Index, U, V, W); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(U, V, W); }, "Returns parameter W on the curve and (parameters U,V) on the surface of the computed intersection point of index Index in case of cross intersection. Exceptions StdFail_NotDone if intersection algorithm fails or is not initialized. Standard_OutOfRange if Index is not in the range [ 1,NbPoints ], where NbPoints is the number of computed intersection points.", py::arg("Index"), py::arg("U"), py::arg("V"), py::arg("W"));
cls_GeomAPI_IntCS.def("NbSegments", (Standard_Integer (GeomAPI_IntCS::*)() const) &GeomAPI_IntCS::NbSegments, "Returns the number of computed intersection segments in case of tangential intersection. Exceptions StdFail_NotDone if the intersection algorithm fails or is not initialized.");
cls_GeomAPI_IntCS.def("Segment", (opencascade::handle<Geom_Curve> (GeomAPI_IntCS::*)(const Standard_Integer) const) &GeomAPI_IntCS::Segment, "Returns the computed intersection segment of index Index in case of tangential intersection. Intersection segment is a portion of the initial curve tangent to surface. Exceptions StdFail_NotDone if intersection algorithm fails or is not initialized. Standard_OutOfRange if Index is not in the range [ 1,NbSegments ], where NbSegments is the number of computed intersection segments.", py::arg("Index"));
cls_GeomAPI_IntCS.def("Parameters", [](GeomAPI_IntCS &self, const Standard_Integer Index, Standard_Real & U1, Standard_Real & V1, Standard_Real & U2, Standard_Real & V2){ self.Parameters(Index, U1, V1, U2, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, V1, U2, V2); }, "Returns the parameters of the first (U1,V1) and the last (U2,V2) points of curve's segment on the surface in case of tangential intersection. Index is the number of computed intersection segments. Exceptions StdFail_NotDone if intersection algorithm fails or is not initialized. Standard_OutOfRange if Index is not in the range [ 1,NbSegments ], where NbSegments is the number of computed intersection segments.", py::arg("Index"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));

// Enums

}