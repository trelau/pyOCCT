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
#include <IntPatch_Polyhedron.hxx>
#include <Standard_Handle.hxx>
#include <Bnd_HArray1OfBox.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <IntPatch_PolyhedronTool.hxx>

void bind_IntPatch_PolyhedronTool(py::module &mod){

py::class_<IntPatch_PolyhedronTool> cls_IntPatch_PolyhedronTool(mod, "IntPatch_PolyhedronTool", "Describe the signature of a polyedral surface with only triangular facets and the necessary informations to compute the interferences.");

// Constructors

// Fields

// Methods
// cls_IntPatch_PolyhedronTool.def_static("operator new_", (void * (*)(size_t)) &IntPatch_PolyhedronTool::operator new, "None", py::arg("theSize"));
// cls_IntPatch_PolyhedronTool.def_static("operator delete_", (void (*)(void *)) &IntPatch_PolyhedronTool::operator delete, "None", py::arg("theAddress"));
// cls_IntPatch_PolyhedronTool.def_static("operator new[]_", (void * (*)(size_t)) &IntPatch_PolyhedronTool::operator new[], "None", py::arg("theSize"));
// cls_IntPatch_PolyhedronTool.def_static("operator delete[]_", (void (*)(void *)) &IntPatch_PolyhedronTool::operator delete[], "None", py::arg("theAddress"));
// cls_IntPatch_PolyhedronTool.def_static("operator new_", (void * (*)(size_t, void *)) &IntPatch_PolyhedronTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPatch_PolyhedronTool.def_static("operator delete_", (void (*)(void *, void *)) &IntPatch_PolyhedronTool::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPatch_PolyhedronTool.def_static("Bounding_", (const Bnd_Box & (*)(const IntPatch_Polyhedron &)) &IntPatch_PolyhedronTool::Bounding, "Give the bounding box of the Polyhedron.", py::arg("thePolyh"));
cls_IntPatch_PolyhedronTool.def_static("ComponentsBounding_", (const opencascade::handle<Bnd_HArray1OfBox> & (*)(const IntPatch_Polyhedron &)) &IntPatch_PolyhedronTool::ComponentsBounding, "Give the array of boxes. The box <n> corresponding to the triangle <n>.", py::arg("thePolyh"));
cls_IntPatch_PolyhedronTool.def_static("DeflectionOverEstimation_", (Standard_Real (*)(const IntPatch_Polyhedron &)) &IntPatch_PolyhedronTool::DeflectionOverEstimation, "Give the tolerance of the polygon.", py::arg("thePolyh"));
cls_IntPatch_PolyhedronTool.def_static("NbTriangles_", (Standard_Integer (*)(const IntPatch_Polyhedron &)) &IntPatch_PolyhedronTool::NbTriangles, "Give the number of triangles in this polyedral surface.", py::arg("thePolyh"));
cls_IntPatch_PolyhedronTool.def_static("Triangle_", [](const IntPatch_Polyhedron & thePolyh, const Standard_Integer Index, Standard_Integer & P1, Standard_Integer & P2, Standard_Integer & P3){ IntPatch_PolyhedronTool::Triangle(thePolyh, Index, P1, P2, P3); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(P1, P2, P3); }, "Give the indices of the 3 points of the triangle of address Index in the Polyhedron.", py::arg("thePolyh"), py::arg("Index"), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_IntPatch_PolyhedronTool.def_static("Point_", (const gp_Pnt & (*)(const IntPatch_Polyhedron &, const Standard_Integer)) &IntPatch_PolyhedronTool::Point, "Give the point of index i in the polyedral surface.", py::arg("thePolyh"), py::arg("Index"));
cls_IntPatch_PolyhedronTool.def_static("TriConnex_", [](const IntPatch_Polyhedron & thePolyh, const Standard_Integer Triang, const Standard_Integer Pivot, const Standard_Integer Pedge, Standard_Integer & TriCon, Standard_Integer & OtherP){ Standard_Integer rv = IntPatch_PolyhedronTool::TriConnex(thePolyh, Triang, Pivot, Pedge, TriCon, OtherP); return std::tuple<Standard_Integer, Standard_Integer &, Standard_Integer &>(rv, TriCon, OtherP); }, "Gives the addresse Tricon of the triangle connexe to the triangle of address Triang by the edge Pivot Pedge and the third point of this connexe triangle. When we are on a free edge TriCon==0 but the function return the value of the triangle in the other side of Pivot on the free edge. Used to turn around a vertex.", py::arg("thePolyh"), py::arg("Triang"), py::arg("Pivot"), py::arg("Pedge"), py::arg("TriCon"), py::arg("OtherP"));

// Enums

}