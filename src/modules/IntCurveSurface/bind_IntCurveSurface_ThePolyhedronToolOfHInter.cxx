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
#include <Bnd_Box.hxx>
#include <IntCurveSurface_ThePolyhedronOfHInter.hxx>
#include <Standard_Handle.hxx>
#include <Bnd_HArray1OfBox.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <IntCurveSurface_ThePolyhedronToolOfHInter.hxx>

void bind_IntCurveSurface_ThePolyhedronToolOfHInter(py::module &mod){

py::class_<IntCurveSurface_ThePolyhedronToolOfHInter, std::unique_ptr<IntCurveSurface_ThePolyhedronToolOfHInter, Deleter<IntCurveSurface_ThePolyhedronToolOfHInter>>> cls_IntCurveSurface_ThePolyhedronToolOfHInter(mod, "IntCurveSurface_ThePolyhedronToolOfHInter", "None");

// Constructors

// Fields

// Methods
// cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("operator new_", (void * (*)(size_t)) &IntCurveSurface_ThePolyhedronToolOfHInter::operator new, "None", py::arg("theSize"));
// cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("operator delete_", (void (*)(void *)) &IntCurveSurface_ThePolyhedronToolOfHInter::operator delete, "None", py::arg("theAddress"));
// cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("operator new[]_", (void * (*)(size_t)) &IntCurveSurface_ThePolyhedronToolOfHInter::operator new[], "None", py::arg("theSize"));
// cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("operator delete[]_", (void (*)(void *)) &IntCurveSurface_ThePolyhedronToolOfHInter::operator delete[], "None", py::arg("theAddress"));
// cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("operator new_", (void * (*)(size_t, void *)) &IntCurveSurface_ThePolyhedronToolOfHInter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("operator delete_", (void (*)(void *, void *)) &IntCurveSurface_ThePolyhedronToolOfHInter::operator delete, "None", py::arg(""), py::arg(""));
cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("Bounding_", (const Bnd_Box & (*)(const IntCurveSurface_ThePolyhedronOfHInter &)) &IntCurveSurface_ThePolyhedronToolOfHInter::Bounding, "Give the bounding box of the PolyhedronTool.", py::arg("thePolyh"));
cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("ComponentsBounding_", (const opencascade::handle<Bnd_HArray1OfBox> & (*)(const IntCurveSurface_ThePolyhedronOfHInter &)) &IntCurveSurface_ThePolyhedronToolOfHInter::ComponentsBounding, "Give the array of boxes. The box <n> corresponding to the triangle <n>.", py::arg("thePolyh"));
cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("DeflectionOverEstimation_", (Standard_Real (*)(const IntCurveSurface_ThePolyhedronOfHInter &)) &IntCurveSurface_ThePolyhedronToolOfHInter::DeflectionOverEstimation, "Give the tolerance of the polygon.", py::arg("thePolyh"));
cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("NbTriangles_", (Standard_Integer (*)(const IntCurveSurface_ThePolyhedronOfHInter &)) &IntCurveSurface_ThePolyhedronToolOfHInter::NbTriangles, "Give the number of triangles in this polyedral surface.", py::arg("thePolyh"));
cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("Triangle_", [](const IntCurveSurface_ThePolyhedronOfHInter & thePolyh, const Standard_Integer Index, Standard_Integer & P1, Standard_Integer & P2, Standard_Integer & P3){ IntCurveSurface_ThePolyhedronToolOfHInter::Triangle(thePolyh, Index, P1, P2, P3); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(P1, P2, P3); }, "Give the indices of the 3 points of the triangle of address Index in the PolyhedronTool.", py::arg("thePolyh"), py::arg("Index"), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("Point_", (const gp_Pnt & (*)(const IntCurveSurface_ThePolyhedronOfHInter &, const Standard_Integer)) &IntCurveSurface_ThePolyhedronToolOfHInter::Point, "Give the point of index i in the polyedral surface.", py::arg("thePolyh"), py::arg("Index"));
cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("TriConnex_", [](const IntCurveSurface_ThePolyhedronOfHInter & thePolyh, const Standard_Integer Triang, const Standard_Integer Pivot, const Standard_Integer Pedge, Standard_Integer & TriCon, Standard_Integer & OtherP){ Standard_Integer rv = IntCurveSurface_ThePolyhedronToolOfHInter::TriConnex(thePolyh, Triang, Pivot, Pedge, TriCon, OtherP); return std::tuple<Standard_Integer, Standard_Integer &, Standard_Integer &>(rv, TriCon, OtherP); }, "Give the addresse Tricon of the triangle connexe to the triangle of address Triang by the edge Pivot Pedge and the third point of this connexe triangle. When we are on a free edge TriCon==0 but the function return the value of the triangle in the other side of Pivot on the free edge. Used to turn around a vertex.", py::arg("thePolyh"), py::arg("Triang"), py::arg("Pivot"), py::arg("Pedge"), py::arg("TriCon"), py::arg("OtherP"));
cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("IsOnBound_", (Standard_Boolean (*)(const IntCurveSurface_ThePolyhedronOfHInter &, const Standard_Integer, const Standard_Integer)) &IntCurveSurface_ThePolyhedronToolOfHInter::IsOnBound, "This method returns true if the edge based on points with indices Index1 and Index2 represents a boundary edge. It is necessary to take into account the boundary deflection for this edge.", py::arg("thePolyh"), py::arg("Index1"), py::arg("Index2"));
cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("GetBorderDeflection_", (Standard_Real (*)(const IntCurveSurface_ThePolyhedronOfHInter &)) &IntCurveSurface_ThePolyhedronToolOfHInter::GetBorderDeflection, "This method returns a border deflection of the polyhedron.", py::arg("thePolyh"));
cls_IntCurveSurface_ThePolyhedronToolOfHInter.def_static("Dump_", (void (*)(const IntCurveSurface_ThePolyhedronOfHInter &)) &IntCurveSurface_ThePolyhedronToolOfHInter::Dump, "None", py::arg("thePolyh"));

// Enums

}