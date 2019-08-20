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
#include <Poly_Triangulation.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <Poly_Connect.hxx>

void bind_Poly_Connect(py::module &mod){

py::class_<Poly_Connect, std::unique_ptr<Poly_Connect>> cls_Poly_Connect(mod, "Poly_Connect", "Provides an algorithm to explore, inside a triangulation, the adjacency data for a node or a triangle. Adjacency data for a node consists of triangles which contain the node. Adjacency data for a triangle consists of: - the 3 adjacent triangles which share an edge of the triangle, - and the 3 nodes which are the other nodes of these adjacent triangles. Example Inside a triangulation, a triangle T has nodes n1, n2 and n3. It has adjacent triangles AT1, AT2 and AT3 where: - AT1 shares the nodes n2 and n3, - AT2 shares the nodes n3 and n1, - AT3 shares the nodes n1 and n2. It has adjacent nodes an1, an2 and an3 where: - an1 is the third node of AT1, - an2 is the third node of AT2, - an3 is the third node of AT3. So triangle AT1 is composed of nodes n2, n3 and an1. There are two ways of using this algorithm. - From a given node you can look for one triangle that passes through the node, then look for the triangles adjacent to this triangle, then the adjacent nodes. You can thus explore the triangulation step by step (functions Triangle, Triangles and Nodes). - From a given node you can look for all the triangles that pass through the node (iteration method, using the functions Initialize, More, Next and Value). A Connect object can be seen as a tool which analyzes a triangulation and translates it into a series of triangles. By doing this, it provides an interface with other tools and applications working on basic triangles, and which do not work directly with a Poly_Triangulation.");

// Constructors
cls_Poly_Connect.def(py::init<>());
cls_Poly_Connect.def(py::init<const opencascade::handle<Poly_Triangulation> &>(), py::arg("theTriangulation"));

// Fields

// Methods
// cls_Poly_Connect.def_static("operator new_", (void * (*)(size_t)) &Poly_Connect::operator new, "None", py::arg("theSize"));
// cls_Poly_Connect.def_static("operator delete_", (void (*)(void *)) &Poly_Connect::operator delete, "None", py::arg("theAddress"));
// cls_Poly_Connect.def_static("operator new[]_", (void * (*)(size_t)) &Poly_Connect::operator new[], "None", py::arg("theSize"));
// cls_Poly_Connect.def_static("operator delete[]_", (void (*)(void *)) &Poly_Connect::operator delete[], "None", py::arg("theAddress"));
// cls_Poly_Connect.def_static("operator new_", (void * (*)(size_t, void *)) &Poly_Connect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Poly_Connect.def_static("operator delete_", (void (*)(void *, void *)) &Poly_Connect::operator delete, "None", py::arg(""), py::arg(""));
cls_Poly_Connect.def("Load", (void (Poly_Connect::*)(const opencascade::handle<Poly_Triangulation> &)) &Poly_Connect::Load, "Initialize the algorithm to explore the adjacency data of nodes or triangles for the triangulation theTriangulation.", py::arg("theTriangulation"));
cls_Poly_Connect.def("Triangulation", (const opencascade::handle<Poly_Triangulation> & (Poly_Connect::*)() const) &Poly_Connect::Triangulation, "Returns the triangulation analyzed by this tool.");
cls_Poly_Connect.def("Triangle", (Standard_Integer (Poly_Connect::*)(const Standard_Integer) const) &Poly_Connect::Triangle, "Returns the index of a triangle containing the node at index N in the nodes table specific to the triangulation analyzed by this tool", py::arg("N"));
cls_Poly_Connect.def("Triangles", [](Poly_Connect &self, const Standard_Integer T, Standard_Integer & t1, Standard_Integer & t2, Standard_Integer & t3){ self.Triangles(T, t1, t2, t3); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(t1, t2, t3); }, "Returns in t1, t2 and t3, the indices of the 3 triangles adjacent to the triangle at index T in the triangles table specific to the triangulation analyzed by this tool. Warning Null indices are returned when there are fewer than 3 adjacent triangles.", py::arg("T"), py::arg("t1"), py::arg("t2"), py::arg("t3"));
cls_Poly_Connect.def("Nodes", [](Poly_Connect &self, const Standard_Integer T, Standard_Integer & n1, Standard_Integer & n2, Standard_Integer & n3){ self.Nodes(T, n1, n2, n3); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(n1, n2, n3); }, "Returns, in n1, n2 and n3, the indices of the 3 nodes adjacent to the triangle referenced at index T in the triangles table specific to the triangulation analyzed by this tool. Warning Null indices are returned when there are fewer than 3 adjacent nodes.", py::arg("T"), py::arg("n1"), py::arg("n2"), py::arg("n3"));
cls_Poly_Connect.def("Initialize", (void (Poly_Connect::*)(const Standard_Integer)) &Poly_Connect::Initialize, "Initializes an iterator to search for all the triangles containing the node referenced at index N in the nodes table, for the triangulation analyzed by this tool. The iterator is managed by the following functions: - More, which checks if there are still elements in the iterator - Next, which positions the iterator on the next element - Value, which returns the current element. The use of such an iterator provides direct access to the triangles around a particular node, i.e. it avoids iterating on all the component triangles of a triangulation. Example Poly_Connect C(Tr); for (C.Initialize(n1);C.More();C.Next()) { t = C.Value(); }", py::arg("N"));
cls_Poly_Connect.def("More", (Standard_Boolean (Poly_Connect::*)() const) &Poly_Connect::More, "Returns true if there is another element in the iterator defined with the function Initialize (i.e. if there is another triangle containing the given node).");
cls_Poly_Connect.def("Next", (void (Poly_Connect::*)()) &Poly_Connect::Next, "Advances the iterator defined with the function Initialize to access the next triangle. Note: There is no action if the iterator is empty (i.e. if the function More returns false).-");
cls_Poly_Connect.def("Value", (Standard_Integer (Poly_Connect::*)() const) &Poly_Connect::Value, "Returns the index of the current triangle to which the iterator, defined with the function Initialize, points. This is an index in the triangles table specific to the triangulation analyzed by this tool");

// Enums

}