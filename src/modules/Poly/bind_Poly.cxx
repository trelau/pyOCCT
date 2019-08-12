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
#include <Poly_ListOfTriangulation.hxx>
#include <Standard_OStream.hxx>
#include <Standard_TypeDef.hxx>
#include <Poly_Polygon3D.hxx>
#include <Poly_Polygon2D.hxx>
#include <Standard_IStream.hxx>
#include <gp_XY.hxx>
#include <Poly_Triangle.hxx>
#include <Poly_PolygonOnTriangulation.hxx>
#include <Poly_Connect.hxx>
#include <Poly.hxx>

void bind_Poly(py::module &mod){

py::class_<Poly, std::unique_ptr<Poly, Deleter<Poly>>> cls_Poly(mod, "Poly", "This package provides classes and services to handle :");

// Constructors

// Fields

// Methods
// cls_Poly.def_static("operator new_", (void * (*)(size_t)) &Poly::operator new, "None", py::arg("theSize"));
// cls_Poly.def_static("operator delete_", (void (*)(void *)) &Poly::operator delete, "None", py::arg("theAddress"));
// cls_Poly.def_static("operator new[]_", (void * (*)(size_t)) &Poly::operator new[], "None", py::arg("theSize"));
// cls_Poly.def_static("operator delete[]_", (void (*)(void *)) &Poly::operator delete[], "None", py::arg("theAddress"));
// cls_Poly.def_static("operator new_", (void * (*)(size_t, void *)) &Poly::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Poly.def_static("operator delete_", (void (*)(void *, void *)) &Poly::operator delete, "None", py::arg(""), py::arg(""));
cls_Poly.def_static("Catenate_", (opencascade::handle<Poly_Triangulation> (*)(const Poly_ListOfTriangulation &)) &Poly::Catenate, "Computes and stores the link from nodes to triangles and from triangles to neighbouring triangles. This tool is obsolete, replaced by Poly_CoherentTriangulation Algorithm to make minimal loops in a graph Join several triangulations to one new triangulation object. The new triangulation is just a mechanical sum of input triangulations, without node sharing. UV coordinates are dropped in the result.", py::arg("lstTri"));
cls_Poly.def_static("Write_", [](const opencascade::handle<Poly_Triangulation> & a0, Standard_OStream & a1) -> void { return Poly::Write(a0, a1); });
cls_Poly.def_static("Write_", (void (*)(const opencascade::handle<Poly_Triangulation> &, Standard_OStream &, const Standard_Boolean)) &Poly::Write, "Writes the content of the triangulation <T> on the stream <OS>. If <Compact> is true this is a 'save' format intended to be read back with the Read method. If compact is False it is a 'Dump' format intended to be informative.", py::arg("T"), py::arg("OS"), py::arg("Compact"));
cls_Poly.def_static("Write_", [](const opencascade::handle<Poly_Polygon3D> & a0, Standard_OStream & a1) -> void { return Poly::Write(a0, a1); });
cls_Poly.def_static("Write_", (void (*)(const opencascade::handle<Poly_Polygon3D> &, Standard_OStream &, const Standard_Boolean)) &Poly::Write, "Writes the content of the 3D polygon <P> on the stream <OS>. If <Compact> is true this is a 'save' format intended to be read back with the Read method. If compact is False it is a 'Dump' format intended to be informative.", py::arg("P"), py::arg("OS"), py::arg("Compact"));
cls_Poly.def_static("Write_", [](const opencascade::handle<Poly_Polygon2D> & a0, Standard_OStream & a1) -> void { return Poly::Write(a0, a1); });
cls_Poly.def_static("Write_", (void (*)(const opencascade::handle<Poly_Polygon2D> &, Standard_OStream &, const Standard_Boolean)) &Poly::Write, "Writes the content of the 2D polygon <P> on the stream <OS>. If <Compact> is true this is a 'save' format intended to be read back with the Read method. If compact is False it is a 'Dump' format intended to be informative.", py::arg("P"), py::arg("OS"), py::arg("Compact"));
cls_Poly.def_static("Dump_", (void (*)(const opencascade::handle<Poly_Triangulation> &, Standard_OStream &)) &Poly::Dump, "Dumps the triangulation. This is a call to the previous method with Comapct set to False.", py::arg("T"), py::arg("OS"));
cls_Poly.def_static("Dump_", (void (*)(const opencascade::handle<Poly_Polygon3D> &, Standard_OStream &)) &Poly::Dump, "Dumps the 3D polygon. This is a call to the previous method with Comapct set to False.", py::arg("P"), py::arg("OS"));
cls_Poly.def_static("Dump_", (void (*)(const opencascade::handle<Poly_Polygon2D> &, Standard_OStream &)) &Poly::Dump, "Dumps the 2D polygon. This is a call to the previous method with Comapct set to False.", py::arg("P"), py::arg("OS"));
cls_Poly.def_static("ReadTriangulation_", (opencascade::handle<Poly_Triangulation> (*)(Standard_IStream &)) &Poly::ReadTriangulation, "Reads a triangulation from the stream <IS>.", py::arg("IS"));
cls_Poly.def_static("ReadPolygon3D_", (opencascade::handle<Poly_Polygon3D> (*)(Standard_IStream &)) &Poly::ReadPolygon3D, "Reads a 3d polygon from the stream <IS>.", py::arg("IS"));
cls_Poly.def_static("ReadPolygon2D_", (opencascade::handle<Poly_Polygon2D> (*)(Standard_IStream &)) &Poly::ReadPolygon2D, "Reads a 2D polygon from the stream <IS>.", py::arg("IS"));
cls_Poly.def_static("ComputeNormals_", (void (*)(const opencascade::handle<Poly_Triangulation> &)) &Poly::ComputeNormals, "Compute node normals for face triangulation as mean normal of surrounding triangles", py::arg("Tri"));
cls_Poly.def_static("PointOnTriangle_", (Standard_Real (*)(const gp_XY &, const gp_XY &, const gp_XY &, const gp_XY &, gp_XY &)) &Poly::PointOnTriangle, "Computes parameters of the point P on triangle defined by points P1, P2, and P3, in 2d. The parameters U and V are defined so that P = P1 + U * (P2 - P1) + V * (P3 - P1), with U >= 0, V >= 0, U + V <= 1. If P is located outside of triangle, or triangle is degenerated, the returned parameters correspond to closest point, and returned value is square of the distance from original point to triangle (0 if point is inside).", py::arg("P1"), py::arg("P2"), py::arg("P3"), py::arg("P"), py::arg("UV"));

// Enums

}