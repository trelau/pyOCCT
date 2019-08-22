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
#include <Adaptor3d_HSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <gp_Pnt.hxx>
#include <Bnd_Box.hxx>
#include <Bnd_HArray1OfBox.hxx>
#include <gp_XYZ.hxx>
#include <IntCurveSurface_ThePolyhedronOfHInter.hxx>

void bind_IntCurveSurface_ThePolyhedronOfHInter(py::module &mod){

py::class_<IntCurveSurface_ThePolyhedronOfHInter> cls_IntCurveSurface_ThePolyhedronOfHInter(mod, "IntCurveSurface_ThePolyhedronOfHInter", "None");

// Constructors
cls_IntCurveSurface_ThePolyhedronOfHInter.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Surface"), py::arg("nbdU"), py::arg("nbdV"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &>(), py::arg("Surface"), py::arg("Upars"), py::arg("Vpars"));

// Fields

// Methods
// cls_IntCurveSurface_ThePolyhedronOfHInter.def_static("operator new_", (void * (*)(size_t)) &IntCurveSurface_ThePolyhedronOfHInter::operator new, "None", py::arg("theSize"));
// cls_IntCurveSurface_ThePolyhedronOfHInter.def_static("operator delete_", (void (*)(void *)) &IntCurveSurface_ThePolyhedronOfHInter::operator delete, "None", py::arg("theAddress"));
// cls_IntCurveSurface_ThePolyhedronOfHInter.def_static("operator new[]_", (void * (*)(size_t)) &IntCurveSurface_ThePolyhedronOfHInter::operator new[], "None", py::arg("theSize"));
// cls_IntCurveSurface_ThePolyhedronOfHInter.def_static("operator delete[]_", (void (*)(void *)) &IntCurveSurface_ThePolyhedronOfHInter::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurveSurface_ThePolyhedronOfHInter.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurveSurface_ThePolyhedronOfHInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurveSurface_ThePolyhedronOfHInter.def_static("operator delete_", (void (*)(void *, void *)) &IntCurveSurface_ThePolyhedronOfHInter::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("Destroy", (void (IntCurveSurface_ThePolyhedronOfHInter::*)()) &IntCurveSurface_ThePolyhedronOfHInter::Destroy, "None");
cls_IntCurveSurface_ThePolyhedronOfHInter.def("DeflectionOverEstimation", (void (IntCurveSurface_ThePolyhedronOfHInter::*)(const Standard_Real)) &IntCurveSurface_ThePolyhedronOfHInter::DeflectionOverEstimation, "None", py::arg("flec"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("DeflectionOnTriangle", (Standard_Real (IntCurveSurface_ThePolyhedronOfHInter::*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer) const) &IntCurveSurface_ThePolyhedronOfHInter::DeflectionOnTriangle, "None", py::arg("Surface"), py::arg("Index"));
// cls_IntCurveSurface_ThePolyhedronOfHInter.def("UMinSingularity", (void (IntCurveSurface_ThePolyhedronOfHInter::*)(const Standard_Boolean)) &IntCurveSurface_ThePolyhedronOfHInter::UMinSingularity, "None", py::arg("Sing"));
// cls_IntCurveSurface_ThePolyhedronOfHInter.def("UMaxSingularity", (void (IntCurveSurface_ThePolyhedronOfHInter::*)(const Standard_Boolean)) &IntCurveSurface_ThePolyhedronOfHInter::UMaxSingularity, "None", py::arg("Sing"));
// cls_IntCurveSurface_ThePolyhedronOfHInter.def("VMinSingularity", (void (IntCurveSurface_ThePolyhedronOfHInter::*)(const Standard_Boolean)) &IntCurveSurface_ThePolyhedronOfHInter::VMinSingularity, "None", py::arg("Sing"));
// cls_IntCurveSurface_ThePolyhedronOfHInter.def("VMaxSingularity", (void (IntCurveSurface_ThePolyhedronOfHInter::*)(const Standard_Boolean)) &IntCurveSurface_ThePolyhedronOfHInter::VMaxSingularity, "None", py::arg("Sing"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("Size", [](IntCurveSurface_ThePolyhedronOfHInter &self, Standard_Integer & nbdu, Standard_Integer & nbdv){ self.Size(nbdu, nbdv); return std::tuple<Standard_Integer &, Standard_Integer &>(nbdu, nbdv); }, "get the size of the discretization.", py::arg("nbdu"), py::arg("nbdv"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("NbTriangles", (Standard_Integer (IntCurveSurface_ThePolyhedronOfHInter::*)() const) &IntCurveSurface_ThePolyhedronOfHInter::NbTriangles, "Give the number of triangles in this double array of");
cls_IntCurveSurface_ThePolyhedronOfHInter.def("Triangle", [](IntCurveSurface_ThePolyhedronOfHInter &self, const Standard_Integer Index, Standard_Integer & P1, Standard_Integer & P2, Standard_Integer & P3){ self.Triangle(Index, P1, P2, P3); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(P1, P2, P3); }, "Give the 3 points of the triangle of addresse Index in the double array of triangles.", py::arg("Index"), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("TriConnex", [](IntCurveSurface_ThePolyhedronOfHInter &self, const Standard_Integer Triang, const Standard_Integer Pivot, const Standard_Integer Pedge, Standard_Integer & TriCon, Standard_Integer & OtherP){ Standard_Integer rv = self.TriConnex(Triang, Pivot, Pedge, TriCon, OtherP); return std::tuple<Standard_Integer, Standard_Integer &, Standard_Integer &>(rv, TriCon, OtherP); }, "Give the addresse Tricon of the triangle connexe to the triangle of address Triang by the edge Pivot Pedge and the third point of this connexe triangle. When we are on a free edge TriCon==0 but the function return the value of the triangle in the other side of Pivot on the free edge. Used to turn around a vertex.", py::arg("Triang"), py::arg("Pivot"), py::arg("Pedge"), py::arg("TriCon"), py::arg("OtherP"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("NbPoints", (Standard_Integer (IntCurveSurface_ThePolyhedronOfHInter::*)() const) &IntCurveSurface_ThePolyhedronOfHInter::NbPoints, "Give the number of point in the double array of triangles ((nbdu+1)*(nbdv+1)).");
cls_IntCurveSurface_ThePolyhedronOfHInter.def("Point", (void (IntCurveSurface_ThePolyhedronOfHInter::*)(const gp_Pnt &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real)) &IntCurveSurface_ThePolyhedronOfHInter::Point, "Set the value of a field of the double array of points.", py::arg("thePnt"), py::arg("lig"), py::arg("col"), py::arg("U"), py::arg("V"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("Point", [](IntCurveSurface_ThePolyhedronOfHInter &self, const Standard_Integer Index, Standard_Real & U, Standard_Real & V){ const gp_Pnt & rv = self.Point(Index, U, V); return std::tuple<const gp_Pnt &, Standard_Real &, Standard_Real &>(rv, U, V); }, "Give the point of index i in the MaTriangle.", py::arg("Index"), py::arg("U"), py::arg("V"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("Point", (const gp_Pnt & (IntCurveSurface_ThePolyhedronOfHInter::*)(const Standard_Integer) const) &IntCurveSurface_ThePolyhedronOfHInter::Point, "Give the point of index i in the MaTriangle.", py::arg("Index"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("Point", (void (IntCurveSurface_ThePolyhedronOfHInter::*)(const Standard_Integer, gp_Pnt &) const) &IntCurveSurface_ThePolyhedronOfHInter::Point, "Give the point of index i in the MaTriangle.", py::arg("Index"), py::arg("P"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("Bounding", (const Bnd_Box & (IntCurveSurface_ThePolyhedronOfHInter::*)() const) &IntCurveSurface_ThePolyhedronOfHInter::Bounding, "Give the bounding box of the MaTriangle.");
cls_IntCurveSurface_ThePolyhedronOfHInter.def("FillBounding", (void (IntCurveSurface_ThePolyhedronOfHInter::*)()) &IntCurveSurface_ThePolyhedronOfHInter::FillBounding, "Compute the array of boxes. The box <n> corresponding to the triangle <n>.");
cls_IntCurveSurface_ThePolyhedronOfHInter.def("ComponentsBounding", (const opencascade::handle<Bnd_HArray1OfBox> & (IntCurveSurface_ThePolyhedronOfHInter::*)() const) &IntCurveSurface_ThePolyhedronOfHInter::ComponentsBounding, "Give the array of boxes. The box <n> corresponding to the triangle <n>.");
cls_IntCurveSurface_ThePolyhedronOfHInter.def("DeflectionOverEstimation", (Standard_Real (IntCurveSurface_ThePolyhedronOfHInter::*)() const) &IntCurveSurface_ThePolyhedronOfHInter::DeflectionOverEstimation, "None");
// cls_IntCurveSurface_ThePolyhedronOfHInter.def("HasUMinSingularity", (Standard_Boolean (IntCurveSurface_ThePolyhedronOfHInter::*)() const) &IntCurveSurface_ThePolyhedronOfHInter::HasUMinSingularity, "None");
// cls_IntCurveSurface_ThePolyhedronOfHInter.def("HasUMaxSingularity", (Standard_Boolean (IntCurveSurface_ThePolyhedronOfHInter::*)() const) &IntCurveSurface_ThePolyhedronOfHInter::HasUMaxSingularity, "None");
// cls_IntCurveSurface_ThePolyhedronOfHInter.def("HasVMinSingularity", (Standard_Boolean (IntCurveSurface_ThePolyhedronOfHInter::*)() const) &IntCurveSurface_ThePolyhedronOfHInter::HasVMinSingularity, "None");
// cls_IntCurveSurface_ThePolyhedronOfHInter.def("HasVMaxSingularity", (Standard_Boolean (IntCurveSurface_ThePolyhedronOfHInter::*)() const) &IntCurveSurface_ThePolyhedronOfHInter::HasVMaxSingularity, "None");
cls_IntCurveSurface_ThePolyhedronOfHInter.def("PlaneEquation", [](IntCurveSurface_ThePolyhedronOfHInter &self, const Standard_Integer Triang, gp_XYZ & NormalVector, Standard_Real & PolarDistance){ self.PlaneEquation(Triang, NormalVector, PolarDistance); return PolarDistance; }, "Give the plane equation of the triangle of addresse Triang.", py::arg("Triang"), py::arg("NormalVector"), py::arg("PolarDistance"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("Contain", (Standard_Boolean (IntCurveSurface_ThePolyhedronOfHInter::*)(const Standard_Integer, const gp_Pnt &) const) &IntCurveSurface_ThePolyhedronOfHInter::Contain, "Give the plane equation of the triangle of addresse Triang.", py::arg("Triang"), py::arg("ThePnt"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("Parameters", [](IntCurveSurface_ThePolyhedronOfHInter &self, const Standard_Integer Index, Standard_Real & U, Standard_Real & V){ self.Parameters(Index, U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "None", py::arg("Index"), py::arg("U"), py::arg("V"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("IsOnBound", (Standard_Boolean (IntCurveSurface_ThePolyhedronOfHInter::*)(const Standard_Integer, const Standard_Integer) const) &IntCurveSurface_ThePolyhedronOfHInter::IsOnBound, "This method returns true if the edge based on points with indices Index1 and Index2 represents a boundary edge. It is necessary to take into account the boundary deflection for this edge.", py::arg("Index1"), py::arg("Index2"));
cls_IntCurveSurface_ThePolyhedronOfHInter.def("GetBorderDeflection", (Standard_Real (IntCurveSurface_ThePolyhedronOfHInter::*)() const) &IntCurveSurface_ThePolyhedronOfHInter::GetBorderDeflection, "This method returns a border deflection.");
cls_IntCurveSurface_ThePolyhedronOfHInter.def("Dump", (void (IntCurveSurface_ThePolyhedronOfHInter::*)() const) &IntCurveSurface_ThePolyhedronOfHInter::Dump, "None");

// Enums

}