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
#include <Graphic3d_ArrayOfTriangles.hxx>
#include <gp_Trsf.hxx>
#include <Poly_Triangulation.hxx>
#include <Standard_TypeDef.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <NCollection_Array1.hxx>
#include <gp_Dir.hxx>
#include <gp_Pnt.hxx>
#include <Prs3d_ToolQuadric.hxx>

void bind_Prs3d_ToolQuadric(py::module &mod){

py::class_<Prs3d_ToolQuadric> cls_Prs3d_ToolQuadric(mod, "Prs3d_ToolQuadric", "Base class to build 3D surfaces presentation of quadric surfaces.");

// Fields

// Methods
// cls_Prs3d_ToolQuadric.def_static("operator new_", (void * (*)(size_t)) &Prs3d_ToolQuadric::operator new, "None", py::arg("theSize"));
// cls_Prs3d_ToolQuadric.def_static("operator delete_", (void (*)(void *)) &Prs3d_ToolQuadric::operator delete, "None", py::arg("theAddress"));
// cls_Prs3d_ToolQuadric.def_static("operator new[]_", (void * (*)(size_t)) &Prs3d_ToolQuadric::operator new[], "None", py::arg("theSize"));
// cls_Prs3d_ToolQuadric.def_static("operator delete[]_", (void (*)(void *)) &Prs3d_ToolQuadric::operator delete[], "None", py::arg("theAddress"));
// cls_Prs3d_ToolQuadric.def_static("operator new_", (void * (*)(size_t, void *)) &Prs3d_ToolQuadric::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Prs3d_ToolQuadric.def_static("operator delete_", (void (*)(void *, void *)) &Prs3d_ToolQuadric::operator delete, "None", py::arg(""), py::arg(""));
cls_Prs3d_ToolQuadric.def("FillArray", (void (Prs3d_ToolQuadric::*)(opencascade::handle<Graphic3d_ArrayOfTriangles> &, const gp_Trsf &)) &Prs3d_ToolQuadric::FillArray, "Generate primitives for 3D quadric surface and fill the given array. Optional transformation is applied.", py::arg("theArray"), py::arg("theTrsf"));
cls_Prs3d_ToolQuadric.def("FillArray", (void (Prs3d_ToolQuadric::*)(opencascade::handle<Graphic3d_ArrayOfTriangles> &, opencascade::handle<Poly_Triangulation> &, const gp_Trsf &)) &Prs3d_ToolQuadric::FillArray, "Generate primitives for 3D quadric surface presentation and fill the given array and poly triangulation structure. Optional transformation is applied.", py::arg("theArray"), py::arg("theTriangulation"), py::arg("theTrsf"));
cls_Prs3d_ToolQuadric.def_static("TrianglesNb_", (Standard_Integer (*)(const Standard_Integer, const Standard_Integer)) &Prs3d_ToolQuadric::TrianglesNb, "Number of triangles for presentation with the given params.", py::arg("theSlicesNb"), py::arg("theStacksNb"));

// Enums

}