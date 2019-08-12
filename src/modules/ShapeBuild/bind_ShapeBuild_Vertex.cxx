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
#include <TopoDS_Vertex.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <ShapeBuild_Vertex.hxx>

void bind_ShapeBuild_Vertex(py::module &mod){

py::class_<ShapeBuild_Vertex, std::unique_ptr<ShapeBuild_Vertex, Deleter<ShapeBuild_Vertex>>> cls_ShapeBuild_Vertex(mod, "ShapeBuild_Vertex", "Provides low-level functions used for constructing vertices");

// Constructors

// Fields

// Methods
// cls_ShapeBuild_Vertex.def_static("operator new_", (void * (*)(size_t)) &ShapeBuild_Vertex::operator new, "None", py::arg("theSize"));
// cls_ShapeBuild_Vertex.def_static("operator delete_", (void (*)(void *)) &ShapeBuild_Vertex::operator delete, "None", py::arg("theAddress"));
// cls_ShapeBuild_Vertex.def_static("operator new[]_", (void * (*)(size_t)) &ShapeBuild_Vertex::operator new[], "None", py::arg("theSize"));
// cls_ShapeBuild_Vertex.def_static("operator delete[]_", (void (*)(void *)) &ShapeBuild_Vertex::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeBuild_Vertex.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeBuild_Vertex::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeBuild_Vertex.def_static("operator delete_", (void (*)(void *, void *)) &ShapeBuild_Vertex::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeBuild_Vertex.def("CombineVertex", [](ShapeBuild_Vertex &self, const TopoDS_Vertex & a0, const TopoDS_Vertex & a1) -> TopoDS_Vertex { return self.CombineVertex(a0, a1); });
cls_ShapeBuild_Vertex.def("CombineVertex", (TopoDS_Vertex (ShapeBuild_Vertex::*)(const TopoDS_Vertex &, const TopoDS_Vertex &, const Standard_Real) const) &ShapeBuild_Vertex::CombineVertex, "Combines new vertex from two others. This new one is the smallest vertex which comprises both of the source vertices. The function takes into account the positions and tolerances of the source vertices. The tolerance of the new vertex will be equal to the minimal tolerance that is required to comprise source vertices multiplied by tolFactor (in order to avoid errors because of discreteness of calculations).", py::arg("V1"), py::arg("V2"), py::arg("tolFactor"));
cls_ShapeBuild_Vertex.def("CombineVertex", [](ShapeBuild_Vertex &self, const gp_Pnt & a0, const gp_Pnt & a1, const Standard_Real a2, const Standard_Real a3) -> TopoDS_Vertex { return self.CombineVertex(a0, a1, a2, a3); });
cls_ShapeBuild_Vertex.def("CombineVertex", (TopoDS_Vertex (ShapeBuild_Vertex::*)(const gp_Pnt &, const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real) const) &ShapeBuild_Vertex::CombineVertex, "The same function as above, except that it accepts two points and two tolerances instead of vertices", py::arg("pnt1"), py::arg("pnt2"), py::arg("tol1"), py::arg("tol2"), py::arg("tolFactor"));

// Enums

}