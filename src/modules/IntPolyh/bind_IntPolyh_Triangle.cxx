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
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <IntPolyh_ArrayOfPoints.hxx>
#include <IntPolyh_ArrayOfEdges.hxx>
#include <IntPolyh_ArrayOfTriangles.hxx>
#include <Bnd_Box.hxx>
#include <IntPolyh_Edge.hxx>
#include <IntPolyh_Triangle.hxx>

void bind_IntPolyh_Triangle(py::module &mod){

py::class_<IntPolyh_Triangle> cls_IntPolyh_Triangle(mod, "IntPolyh_Triangle", "The class represents the triangle built from three IntPolyh points and three IntPolyh edges.");

// Constructors
cls_IntPolyh_Triangle.def(py::init<>());
cls_IntPolyh_Triangle.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("thePoint1"), py::arg("thePoint2"), py::arg("thePoint3"));

// Fields

// Methods
// cls_IntPolyh_Triangle.def_static("operator new_", (void * (*)(size_t)) &IntPolyh_Triangle::operator new, "None", py::arg("theSize"));
// cls_IntPolyh_Triangle.def_static("operator delete_", (void (*)(void *)) &IntPolyh_Triangle::operator delete, "None", py::arg("theAddress"));
// cls_IntPolyh_Triangle.def_static("operator new[]_", (void * (*)(size_t)) &IntPolyh_Triangle::operator new[], "None", py::arg("theSize"));
// cls_IntPolyh_Triangle.def_static("operator delete[]_", (void (*)(void *)) &IntPolyh_Triangle::operator delete[], "None", py::arg("theAddress"));
// cls_IntPolyh_Triangle.def_static("operator new_", (void * (*)(size_t, void *)) &IntPolyh_Triangle::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntPolyh_Triangle.def_static("operator delete_", (void (*)(void *, void *)) &IntPolyh_Triangle::operator delete, "None", py::arg(""), py::arg(""));
cls_IntPolyh_Triangle.def("FirstPoint", (Standard_Integer (IntPolyh_Triangle::*)() const) &IntPolyh_Triangle::FirstPoint, "Returns the first point");
cls_IntPolyh_Triangle.def("SecondPoint", (Standard_Integer (IntPolyh_Triangle::*)() const) &IntPolyh_Triangle::SecondPoint, "Returns the second point");
cls_IntPolyh_Triangle.def("ThirdPoint", (Standard_Integer (IntPolyh_Triangle::*)() const) &IntPolyh_Triangle::ThirdPoint, "Returns the third point");
cls_IntPolyh_Triangle.def("FirstEdge", (Standard_Integer (IntPolyh_Triangle::*)() const) &IntPolyh_Triangle::FirstEdge, "Returns the first edge");
cls_IntPolyh_Triangle.def("FirstEdgeOrientation", (Standard_Integer (IntPolyh_Triangle::*)() const) &IntPolyh_Triangle::FirstEdgeOrientation, "Returns the orientation of the first edge");
cls_IntPolyh_Triangle.def("SecondEdge", (Standard_Integer (IntPolyh_Triangle::*)() const) &IntPolyh_Triangle::SecondEdge, "Returns the second edge");
cls_IntPolyh_Triangle.def("SecondEdgeOrientation", (Standard_Integer (IntPolyh_Triangle::*)() const) &IntPolyh_Triangle::SecondEdgeOrientation, "Returns the orientation of the second edge");
cls_IntPolyh_Triangle.def("ThirdEdge", (Standard_Integer (IntPolyh_Triangle::*)() const) &IntPolyh_Triangle::ThirdEdge, "Returns the third edge");
cls_IntPolyh_Triangle.def("ThirdEdgeOrientation", (Standard_Integer (IntPolyh_Triangle::*)() const) &IntPolyh_Triangle::ThirdEdgeOrientation, "Returns the orientation of the third edge");
cls_IntPolyh_Triangle.def("Deflection", (Standard_Real (IntPolyh_Triangle::*)() const) &IntPolyh_Triangle::Deflection, "Returns the deflection of the triangle");
cls_IntPolyh_Triangle.def("IsIntersectionPossible", (Standard_Boolean (IntPolyh_Triangle::*)() const) &IntPolyh_Triangle::IsIntersectionPossible, "Returns possibility of the intersection");
cls_IntPolyh_Triangle.def("HasIntersection", (Standard_Boolean (IntPolyh_Triangle::*)() const) &IntPolyh_Triangle::HasIntersection, "Returns true if the triangle has interfered the other triangle");
cls_IntPolyh_Triangle.def("IsDegenerated", (Standard_Boolean (IntPolyh_Triangle::*)() const) &IntPolyh_Triangle::IsDegenerated, "Returns the Degenerated flag");
cls_IntPolyh_Triangle.def("SetFirstPoint", (void (IntPolyh_Triangle::*)(const Standard_Integer)) &IntPolyh_Triangle::SetFirstPoint, "Sets the first point", py::arg("thePoint"));
cls_IntPolyh_Triangle.def("SetSecondPoint", (void (IntPolyh_Triangle::*)(const Standard_Integer)) &IntPolyh_Triangle::SetSecondPoint, "Sets the second point", py::arg("thePoint"));
cls_IntPolyh_Triangle.def("SetThirdPoint", (void (IntPolyh_Triangle::*)(const Standard_Integer)) &IntPolyh_Triangle::SetThirdPoint, "Sets the third point", py::arg("thePoint"));
cls_IntPolyh_Triangle.def("SetFirstEdge", (void (IntPolyh_Triangle::*)(const Standard_Integer, const Standard_Integer)) &IntPolyh_Triangle::SetFirstEdge, "Sets the first edge", py::arg("theEdge"), py::arg("theEdgeOrientation"));
cls_IntPolyh_Triangle.def("SetSecondEdge", (void (IntPolyh_Triangle::*)(const Standard_Integer, const Standard_Integer)) &IntPolyh_Triangle::SetSecondEdge, "Sets the second edge", py::arg("theEdge"), py::arg("theEdgeOrientation"));
cls_IntPolyh_Triangle.def("SetThirdEdge", (void (IntPolyh_Triangle::*)(const Standard_Integer, const Standard_Integer)) &IntPolyh_Triangle::SetThirdEdge, "Sets the third edge", py::arg("theEdge"), py::arg("theEdgeOrientation"));
cls_IntPolyh_Triangle.def("SetDeflection", (void (IntPolyh_Triangle::*)(const Standard_Real)) &IntPolyh_Triangle::SetDeflection, "Sets the deflection", py::arg("theDeflection"));
cls_IntPolyh_Triangle.def("SetIntersectionPossible", (void (IntPolyh_Triangle::*)(const Standard_Boolean)) &IntPolyh_Triangle::SetIntersectionPossible, "Sets the flag of possibility of intersection", py::arg("theIP"));
cls_IntPolyh_Triangle.def("SetIntersection", (void (IntPolyh_Triangle::*)(const Standard_Boolean)) &IntPolyh_Triangle::SetIntersection, "Sets the flag of intersection", py::arg("theInt"));
cls_IntPolyh_Triangle.def("SetDegenerated", (void (IntPolyh_Triangle::*)(const Standard_Boolean)) &IntPolyh_Triangle::SetDegenerated, "Sets the degenerated flag", py::arg("theDegFlag"));
cls_IntPolyh_Triangle.def("GetEdgeNumber", (Standard_Integer (IntPolyh_Triangle::*)(const Standard_Integer) const) &IntPolyh_Triangle::GetEdgeNumber, "Gets the edge number by the index", py::arg("theEdgeIndex"));
cls_IntPolyh_Triangle.def("SetEdge", (void (IntPolyh_Triangle::*)(const Standard_Integer, const Standard_Integer)) &IntPolyh_Triangle::SetEdge, "Sets the edge by the index", py::arg("theEdgeIndex"), py::arg("theEdgeNumber"));
cls_IntPolyh_Triangle.def("GetEdgeOrientation", (Standard_Integer (IntPolyh_Triangle::*)(const Standard_Integer) const) &IntPolyh_Triangle::GetEdgeOrientation, "Gets the edges orientation by the index", py::arg("theEdgeIndex"));
cls_IntPolyh_Triangle.def("SetEdgeOrientation", (void (IntPolyh_Triangle::*)(const Standard_Integer, const Standard_Integer)) &IntPolyh_Triangle::SetEdgeOrientation, "Sets the edges orientation by the index", py::arg("theEdgeIndex"), py::arg("theEdgeOrientation"));
cls_IntPolyh_Triangle.def("ComputeDeflection", (Standard_Real (IntPolyh_Triangle::*)(const opencascade::handle<Adaptor3d_HSurface> &, const IntPolyh_ArrayOfPoints &)) &IntPolyh_Triangle::ComputeDeflection, "Computes the deflection for the triangle", py::arg("theSurface"), py::arg("thePoints"));
cls_IntPolyh_Triangle.def("GetNextTriangle", (Standard_Integer (IntPolyh_Triangle::*)(const Standard_Integer, const Standard_Integer, const IntPolyh_ArrayOfEdges &) const) &IntPolyh_Triangle::GetNextTriangle, "Gets the adjacent triangle", py::arg("theTriangle"), py::arg("theEdgeNum"), py::arg("TEdges"));
cls_IntPolyh_Triangle.def("MiddleRefinement", (void (IntPolyh_Triangle::*)(const Standard_Integer, const opencascade::handle<Adaptor3d_HSurface> &, IntPolyh_ArrayOfPoints &, IntPolyh_ArrayOfTriangles &, IntPolyh_ArrayOfEdges &)) &IntPolyh_Triangle::MiddleRefinement, "Splits the triangle on two to decrease its deflection", py::arg("theTriangleNumber"), py::arg("theSurface"), py::arg("TPoints"), py::arg("TTriangles"), py::arg("TEdges"));
cls_IntPolyh_Triangle.def("MultipleMiddleRefinement", (void (IntPolyh_Triangle::*)(const Standard_Real, const Bnd_Box &, const Standard_Integer, const opencascade::handle<Adaptor3d_HSurface> &, IntPolyh_ArrayOfPoints &, IntPolyh_ArrayOfTriangles &, IntPolyh_ArrayOfEdges &)) &IntPolyh_Triangle::MultipleMiddleRefinement, "Splits the current triangle and new triangles until the refinement criterion is not achieved", py::arg("theRefineCriterion"), py::arg("theBox"), py::arg("theTriangleNumber"), py::arg("theSurface"), py::arg("TPoints"), py::arg("TTriangles"), py::arg("TEdges"));
cls_IntPolyh_Triangle.def("LinkEdges2Triangle", (void (IntPolyh_Triangle::*)(const IntPolyh_ArrayOfEdges &, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &IntPolyh_Triangle::LinkEdges2Triangle, "Links edges to triangle", py::arg("TEdges"), py::arg("theEdge1"), py::arg("theEdge2"), py::arg("theEdge3"));
cls_IntPolyh_Triangle.def("SetEdgeAndOrientation", (void (IntPolyh_Triangle::*)(const IntPolyh_Edge &, const Standard_Integer)) &IntPolyh_Triangle::SetEdgeAndOrientation, "Sets the appropriate edge and orientation for the triangle.", py::arg("theEdge"), py::arg("theEdgeIndex"));
cls_IntPolyh_Triangle.def("BoundingBox", (const Bnd_Box & (IntPolyh_Triangle::*)(const IntPolyh_ArrayOfPoints &)) &IntPolyh_Triangle::BoundingBox, "Returns the bounding box of the triangle.", py::arg("thePoints"));
cls_IntPolyh_Triangle.def("Dump", (void (IntPolyh_Triangle::*)(const Standard_Integer) const) &IntPolyh_Triangle::Dump, "Dumps the contents of the triangle.", py::arg("v"));

// Enums

}