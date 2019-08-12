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
#include <Standard_TypeDef.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <gp_Pnt.hxx>
#include <Bnd_Box.hxx>
#include <Standard_Handle.hxx>
#include <Bnd_HArray1OfBox.hxx>
#include <gp_XYZ.hxx>
#include <HLRBRep_ThePolyhedronOfInterCSurf.hxx>

void bind_HLRBRep_ThePolyhedronOfInterCSurf(py::module &mod){

py::class_<HLRBRep_ThePolyhedronOfInterCSurf, std::unique_ptr<HLRBRep_ThePolyhedronOfInterCSurf, Deleter<HLRBRep_ThePolyhedronOfInterCSurf>>> cls_HLRBRep_ThePolyhedronOfInterCSurf(mod, "HLRBRep_ThePolyhedronOfInterCSurf", "None");

// Constructors
cls_HLRBRep_ThePolyhedronOfInterCSurf.def(py::init<const Standard_Address &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Surface"), py::arg("nbdU"), py::arg("nbdV"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def(py::init<const Standard_Address &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &>(), py::arg("Surface"), py::arg("Upars"), py::arg("Vpars"));

// Fields

// Methods
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_ThePolyhedronOfInterCSurf::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def_static("operator delete_", (void (*)(void *)) &HLRBRep_ThePolyhedronOfInterCSurf::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_ThePolyhedronOfInterCSurf::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_ThePolyhedronOfInterCSurf::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_ThePolyhedronOfInterCSurf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_ThePolyhedronOfInterCSurf::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("Destroy", (void (HLRBRep_ThePolyhedronOfInterCSurf::*)()) &HLRBRep_ThePolyhedronOfInterCSurf::Destroy, "None");
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("DeflectionOverEstimation", (void (HLRBRep_ThePolyhedronOfInterCSurf::*)(const Standard_Real)) &HLRBRep_ThePolyhedronOfInterCSurf::DeflectionOverEstimation, "None", py::arg("flec"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("DeflectionOnTriangle", (Standard_Real (HLRBRep_ThePolyhedronOfInterCSurf::*)(const Standard_Address &, const Standard_Integer) const) &HLRBRep_ThePolyhedronOfInterCSurf::DeflectionOnTriangle, "None", py::arg("Surface"), py::arg("Index"));
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def("UMinSingularity", (void (HLRBRep_ThePolyhedronOfInterCSurf::*)(const Standard_Boolean)) &HLRBRep_ThePolyhedronOfInterCSurf::UMinSingularity, "None", py::arg("Sing"));
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def("UMaxSingularity", (void (HLRBRep_ThePolyhedronOfInterCSurf::*)(const Standard_Boolean)) &HLRBRep_ThePolyhedronOfInterCSurf::UMaxSingularity, "None", py::arg("Sing"));
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def("VMinSingularity", (void (HLRBRep_ThePolyhedronOfInterCSurf::*)(const Standard_Boolean)) &HLRBRep_ThePolyhedronOfInterCSurf::VMinSingularity, "None", py::arg("Sing"));
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def("VMaxSingularity", (void (HLRBRep_ThePolyhedronOfInterCSurf::*)(const Standard_Boolean)) &HLRBRep_ThePolyhedronOfInterCSurf::VMaxSingularity, "None", py::arg("Sing"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("Size", [](HLRBRep_ThePolyhedronOfInterCSurf &self, Standard_Integer & nbdu, Standard_Integer & nbdv){ self.Size(nbdu, nbdv); return std::tuple<Standard_Integer &, Standard_Integer &>(nbdu, nbdv); }, "get the size of the discretization.", py::arg("nbdu"), py::arg("nbdv"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("NbTriangles", (Standard_Integer (HLRBRep_ThePolyhedronOfInterCSurf::*)() const) &HLRBRep_ThePolyhedronOfInterCSurf::NbTriangles, "Give the number of triangles in this double array of");
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("Triangle", [](HLRBRep_ThePolyhedronOfInterCSurf &self, const Standard_Integer Index, Standard_Integer & P1, Standard_Integer & P2, Standard_Integer & P3){ self.Triangle(Index, P1, P2, P3); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(P1, P2, P3); }, "Give the 3 points of the triangle of addresse Index in the double array of triangles.", py::arg("Index"), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("TriConnex", [](HLRBRep_ThePolyhedronOfInterCSurf &self, const Standard_Integer Triang, const Standard_Integer Pivot, const Standard_Integer Pedge, Standard_Integer & TriCon, Standard_Integer & OtherP){ Standard_Integer rv = self.TriConnex(Triang, Pivot, Pedge, TriCon, OtherP); return std::tuple<Standard_Integer, Standard_Integer &, Standard_Integer &>(rv, TriCon, OtherP); }, "Give the addresse Tricon of the triangle connexe to the triangle of address Triang by the edge Pivot Pedge and the third point of this connexe triangle. When we are on a free edge TriCon==0 but the function return the value of the triangle in the other side of Pivot on the free edge. Used to turn around a vertex.", py::arg("Triang"), py::arg("Pivot"), py::arg("Pedge"), py::arg("TriCon"), py::arg("OtherP"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("NbPoints", (Standard_Integer (HLRBRep_ThePolyhedronOfInterCSurf::*)() const) &HLRBRep_ThePolyhedronOfInterCSurf::NbPoints, "Give the number of point in the double array of triangles ((nbdu+1)*(nbdv+1)).");
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("Point", (void (HLRBRep_ThePolyhedronOfInterCSurf::*)(const gp_Pnt &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real)) &HLRBRep_ThePolyhedronOfInterCSurf::Point, "Set the value of a field of the double array of points.", py::arg("thePnt"), py::arg("lig"), py::arg("col"), py::arg("U"), py::arg("V"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("Point", [](HLRBRep_ThePolyhedronOfInterCSurf &self, const Standard_Integer Index, Standard_Real & U, Standard_Real & V){ const gp_Pnt & rv = self.Point(Index, U, V); return std::tuple<const gp_Pnt &, Standard_Real &, Standard_Real &>(rv, U, V); }, "Give the point of index i in the MaTriangle.", py::arg("Index"), py::arg("U"), py::arg("V"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("Point", (const gp_Pnt & (HLRBRep_ThePolyhedronOfInterCSurf::*)(const Standard_Integer) const) &HLRBRep_ThePolyhedronOfInterCSurf::Point, "Give the point of index i in the MaTriangle.", py::arg("Index"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("Point", (void (HLRBRep_ThePolyhedronOfInterCSurf::*)(const Standard_Integer, gp_Pnt &) const) &HLRBRep_ThePolyhedronOfInterCSurf::Point, "Give the point of index i in the MaTriangle.", py::arg("Index"), py::arg("P"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("Bounding", (const Bnd_Box & (HLRBRep_ThePolyhedronOfInterCSurf::*)() const) &HLRBRep_ThePolyhedronOfInterCSurf::Bounding, "Give the bounding box of the MaTriangle.");
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("FillBounding", (void (HLRBRep_ThePolyhedronOfInterCSurf::*)()) &HLRBRep_ThePolyhedronOfInterCSurf::FillBounding, "Compute the array of boxes. The box <n> corresponding to the triangle <n>.");
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("ComponentsBounding", (const opencascade::handle<Bnd_HArray1OfBox> & (HLRBRep_ThePolyhedronOfInterCSurf::*)() const) &HLRBRep_ThePolyhedronOfInterCSurf::ComponentsBounding, "Give the array of boxes. The box <n> corresponding to the triangle <n>.");
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("DeflectionOverEstimation", (Standard_Real (HLRBRep_ThePolyhedronOfInterCSurf::*)() const) &HLRBRep_ThePolyhedronOfInterCSurf::DeflectionOverEstimation, "None");
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def("HasUMinSingularity", (Standard_Boolean (HLRBRep_ThePolyhedronOfInterCSurf::*)() const) &HLRBRep_ThePolyhedronOfInterCSurf::HasUMinSingularity, "None");
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def("HasUMaxSingularity", (Standard_Boolean (HLRBRep_ThePolyhedronOfInterCSurf::*)() const) &HLRBRep_ThePolyhedronOfInterCSurf::HasUMaxSingularity, "None");
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def("HasVMinSingularity", (Standard_Boolean (HLRBRep_ThePolyhedronOfInterCSurf::*)() const) &HLRBRep_ThePolyhedronOfInterCSurf::HasVMinSingularity, "None");
// cls_HLRBRep_ThePolyhedronOfInterCSurf.def("HasVMaxSingularity", (Standard_Boolean (HLRBRep_ThePolyhedronOfInterCSurf::*)() const) &HLRBRep_ThePolyhedronOfInterCSurf::HasVMaxSingularity, "None");
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("PlaneEquation", [](HLRBRep_ThePolyhedronOfInterCSurf &self, const Standard_Integer Triang, gp_XYZ & NormalVector, Standard_Real & PolarDistance){ self.PlaneEquation(Triang, NormalVector, PolarDistance); return PolarDistance; }, "Give the plane equation of the triangle of addresse Triang.", py::arg("Triang"), py::arg("NormalVector"), py::arg("PolarDistance"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("Contain", (Standard_Boolean (HLRBRep_ThePolyhedronOfInterCSurf::*)(const Standard_Integer, const gp_Pnt &) const) &HLRBRep_ThePolyhedronOfInterCSurf::Contain, "Give the plane equation of the triangle of addresse Triang.", py::arg("Triang"), py::arg("ThePnt"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("Parameters", [](HLRBRep_ThePolyhedronOfInterCSurf &self, const Standard_Integer Index, Standard_Real & U, Standard_Real & V){ self.Parameters(Index, U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "None", py::arg("Index"), py::arg("U"), py::arg("V"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("IsOnBound", (Standard_Boolean (HLRBRep_ThePolyhedronOfInterCSurf::*)(const Standard_Integer, const Standard_Integer) const) &HLRBRep_ThePolyhedronOfInterCSurf::IsOnBound, "This method returns true if the edge based on points with indices Index1 and Index2 represents a boundary edge. It is necessary to take into account the boundary deflection for this edge.", py::arg("Index1"), py::arg("Index2"));
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("GetBorderDeflection", (Standard_Real (HLRBRep_ThePolyhedronOfInterCSurf::*)() const) &HLRBRep_ThePolyhedronOfInterCSurf::GetBorderDeflection, "This method returns a border deflection.");
cls_HLRBRep_ThePolyhedronOfInterCSurf.def("Dump", (void (HLRBRep_ThePolyhedronOfInterCSurf::*)() const) &HLRBRep_ThePolyhedronOfInterCSurf::Dump, "None");

// Enums

}