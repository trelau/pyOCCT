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
#include <gp_Pnt.hxx>
#include <Bnd_Box.hxx>
#include <Bnd_HArray1OfBox.hxx>
#include <gp_XYZ.hxx>
#include <IntPatch_Polyhedron.hxx>

void bind_IntPatch_Polyhedron(py::module &mod){

py::class_<IntPatch_Polyhedron, std::unique_ptr<IntPatch_Polyhedron>> cls_IntPatch_Polyhedron(mod, "IntPatch_Polyhedron", "This class provides a linear approximation of the PSurface. preview a constructor on a zone of a surface");

// Constructors
cls_IntPatch_Polyhedron.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer, const Standard_Integer>(), py::arg("Surface"), py::arg("nbdU"), py::arg("nbdV"));
cls_IntPatch_Polyhedron.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &>(), py::arg("Surface"));

// Fields

// Methods
// cls_IntPatch_Polyhedron.def_static("operator new_", (void * (*)(size_t)) &IntPatch_Polyhedron::operator new, "None", py::arg("theSize"));
// cls_IntPatch_Polyhedron.def_static("operator delete_", (void (*)(void *)) &IntPatch_Polyhedron::operator delete, "None", py::arg("theAddress"));
// cls_IntPatch_Polyhedron.def_static("operator new[]_", (void * (*)(size_t)) &IntPatch_Polyhedron::operator new[], "None", py::arg("theSize"));
// cls_IntPatch_Polyhedron.def_static("operator delete[]_", (void (*)(void *)) &IntPatch_Polyhedron::operator delete[], "None", py::arg("theAddress"));
// cls_IntPatch_Polyhedron.def_static("operator new_", (void * (*)(size_t, void *)) &IntPatch_Polyhedron::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPatch_Polyhedron.def_static("operator delete_", (void (*)(void *, void *)) &IntPatch_Polyhedron::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPatch_Polyhedron.def("Destroy", (void (IntPatch_Polyhedron::*)()) &IntPatch_Polyhedron::Destroy, "None");
// cls_IntPatch_Polyhedron.def("Perform", (void (IntPatch_Polyhedron::*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer, const Standard_Integer)) &IntPatch_Polyhedron::Perform, "None", py::arg("Surface"), py::arg("nbdU"), py::arg("nbdV"));
cls_IntPatch_Polyhedron.def("DeflectionOverEstimation", (void (IntPatch_Polyhedron::*)(const Standard_Real)) &IntPatch_Polyhedron::DeflectionOverEstimation, "None", py::arg("flec"));
cls_IntPatch_Polyhedron.def("DeflectionOnTriangle", (Standard_Real (IntPatch_Polyhedron::*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer) const) &IntPatch_Polyhedron::DeflectionOnTriangle, "None", py::arg("Surface"), py::arg("Index"));
// cls_IntPatch_Polyhedron.def("UMinSingularity", (void (IntPatch_Polyhedron::*)(const Standard_Boolean)) &IntPatch_Polyhedron::UMinSingularity, "None", py::arg("Sing"));
// cls_IntPatch_Polyhedron.def("UMaxSingularity", (void (IntPatch_Polyhedron::*)(const Standard_Boolean)) &IntPatch_Polyhedron::UMaxSingularity, "None", py::arg("Sing"));
// cls_IntPatch_Polyhedron.def("VMinSingularity", (void (IntPatch_Polyhedron::*)(const Standard_Boolean)) &IntPatch_Polyhedron::VMinSingularity, "None", py::arg("Sing"));
// cls_IntPatch_Polyhedron.def("VMaxSingularity", (void (IntPatch_Polyhedron::*)(const Standard_Boolean)) &IntPatch_Polyhedron::VMaxSingularity, "None", py::arg("Sing"));
cls_IntPatch_Polyhedron.def("Size", [](IntPatch_Polyhedron &self, Standard_Integer & nbdu, Standard_Integer & nbdv){ self.Size(nbdu, nbdv); return std::tuple<Standard_Integer &, Standard_Integer &>(nbdu, nbdv); }, "Get the size of the MaTriangle.", py::arg("nbdu"), py::arg("nbdv"));
cls_IntPatch_Polyhedron.def("NbTriangles", (Standard_Integer (IntPatch_Polyhedron::*)() const) &IntPatch_Polyhedron::NbTriangles, "Give the number of triangles in this double array of triangles (nbdu*nbdv*2).");
cls_IntPatch_Polyhedron.def("Triangle", [](IntPatch_Polyhedron &self, const Standard_Integer Index, Standard_Integer & P1, Standard_Integer & P2, Standard_Integer & P3){ self.Triangle(Index, P1, P2, P3); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(P1, P2, P3); }, "Give the 3 points of the triangle of addresse Index in the double array of triangles.", py::arg("Index"), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_IntPatch_Polyhedron.def("TriConnex", [](IntPatch_Polyhedron &self, const Standard_Integer Triang, const Standard_Integer Pivot, const Standard_Integer Pedge, Standard_Integer & TriCon, Standard_Integer & OtherP){ Standard_Integer rv = self.TriConnex(Triang, Pivot, Pedge, TriCon, OtherP); return std::tuple<Standard_Integer, Standard_Integer &, Standard_Integer &>(rv, TriCon, OtherP); }, "Give the addresse Tricon of the triangle connexe to the triangle of address Triang by the edge Pivot Pedge and the third point of this connexe triangle. When we are on a free edge TriCon==0 but the function return the value of the triangle in the other side of Pivot on the free edge. Used to turn around a vertex.", py::arg("Triang"), py::arg("Pivot"), py::arg("Pedge"), py::arg("TriCon"), py::arg("OtherP"));
cls_IntPatch_Polyhedron.def("NbPoints", (Standard_Integer (IntPatch_Polyhedron::*)() const) &IntPatch_Polyhedron::NbPoints, "Give the number of point in the double array of triangles ((nbdu+1)*(nbdv+1)).");
cls_IntPatch_Polyhedron.def("Point", (void (IntPatch_Polyhedron::*)(const gp_Pnt &, const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Real)) &IntPatch_Polyhedron::Point, "Set the value of a field of the double array of points.", py::arg("thePnt"), py::arg("lig"), py::arg("col"), py::arg("U"), py::arg("V"));
cls_IntPatch_Polyhedron.def("Point", [](IntPatch_Polyhedron &self, const Standard_Integer Index, Standard_Real & U, Standard_Real & V){ const gp_Pnt & rv = self.Point(Index, U, V); return std::tuple<const gp_Pnt &, Standard_Real &, Standard_Real &>(rv, U, V); }, "Give the point of index i in the MaTriangle.", py::arg("Index"), py::arg("U"), py::arg("V"));
cls_IntPatch_Polyhedron.def("Point", (const gp_Pnt & (IntPatch_Polyhedron::*)(const Standard_Integer) const) &IntPatch_Polyhedron::Point, "Give the point of index i in the MaTriangle.", py::arg("Index"));
cls_IntPatch_Polyhedron.def("Point", (void (IntPatch_Polyhedron::*)(const Standard_Integer, gp_Pnt &) const) &IntPatch_Polyhedron::Point, "Give the point of index i in the MaTriangle.", py::arg("Index"), py::arg("P"));
cls_IntPatch_Polyhedron.def("Bounding", (const Bnd_Box & (IntPatch_Polyhedron::*)() const) &IntPatch_Polyhedron::Bounding, "Give the bounding box of the MaTriangle.");
cls_IntPatch_Polyhedron.def("FillBounding", (void (IntPatch_Polyhedron::*)()) &IntPatch_Polyhedron::FillBounding, "Compute the array of boxes. The box <n> corresponding to the triangle <n>.");
cls_IntPatch_Polyhedron.def("ComponentsBounding", (const opencascade::handle<Bnd_HArray1OfBox> & (IntPatch_Polyhedron::*)() const) &IntPatch_Polyhedron::ComponentsBounding, "Give the array of boxes. The box <n> corresponding to the triangle <n>.");
cls_IntPatch_Polyhedron.def("DeflectionOverEstimation", (Standard_Real (IntPatch_Polyhedron::*)() const) &IntPatch_Polyhedron::DeflectionOverEstimation, "None");
// cls_IntPatch_Polyhedron.def("HasUMinSingularity", (Standard_Boolean (IntPatch_Polyhedron::*)() const) &IntPatch_Polyhedron::HasUMinSingularity, "None");
// cls_IntPatch_Polyhedron.def("HasUMaxSingularity", (Standard_Boolean (IntPatch_Polyhedron::*)() const) &IntPatch_Polyhedron::HasUMaxSingularity, "None");
// cls_IntPatch_Polyhedron.def("HasVMinSingularity", (Standard_Boolean (IntPatch_Polyhedron::*)() const) &IntPatch_Polyhedron::HasVMinSingularity, "None");
// cls_IntPatch_Polyhedron.def("HasVMaxSingularity", (Standard_Boolean (IntPatch_Polyhedron::*)() const) &IntPatch_Polyhedron::HasVMaxSingularity, "None");
cls_IntPatch_Polyhedron.def("PlaneEquation", [](IntPatch_Polyhedron &self, const Standard_Integer Triang, gp_XYZ & NormalVector, Standard_Real & PolarDistance){ self.PlaneEquation(Triang, NormalVector, PolarDistance); return PolarDistance; }, "Give the plane equation of the triangle of addresse Triang.", py::arg("Triang"), py::arg("NormalVector"), py::arg("PolarDistance"));
cls_IntPatch_Polyhedron.def("Contain", (Standard_Boolean (IntPatch_Polyhedron::*)(const Standard_Integer, const gp_Pnt &) const) &IntPatch_Polyhedron::Contain, "Give the plane equation of the triangle of addresse Triang.", py::arg("Triang"), py::arg("ThePnt"));
cls_IntPatch_Polyhedron.def("Parameters", [](IntPatch_Polyhedron &self, const Standard_Integer Index, Standard_Real & U, Standard_Real & V){ self.Parameters(Index, U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "None", py::arg("Index"), py::arg("U"), py::arg("V"));
cls_IntPatch_Polyhedron.def("Dump", (void (IntPatch_Polyhedron::*)() const) &IntPatch_Polyhedron::Dump, "None");

// Enums

}