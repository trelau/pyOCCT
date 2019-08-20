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
#include <Geom_Plane.hxx>
#include <ShapeBuild_Vertex.hxx>
#include <ShapeBuild_Edge.hxx>
#include <ShapeBuild_ReShape.hxx>
#include <ShapeBuild.hxx>

void bind_ShapeBuild(py::module &mod){

py::class_<ShapeBuild, std::unique_ptr<ShapeBuild>> cls_ShapeBuild(mod, "ShapeBuild", "This package provides basic building tools for other packages in ShapeHealing. These tools are rather internal for ShapeHealing .");

// Constructors

// Fields

// Methods
// cls_ShapeBuild.def_static("operator new_", (void * (*)(size_t)) &ShapeBuild::operator new, "None", py::arg("theSize"));
// cls_ShapeBuild.def_static("operator delete_", (void (*)(void *)) &ShapeBuild::operator delete, "None", py::arg("theAddress"));
// cls_ShapeBuild.def_static("operator new[]_", (void * (*)(size_t)) &ShapeBuild::operator new[], "None", py::arg("theSize"));
// cls_ShapeBuild.def_static("operator delete[]_", (void (*)(void *)) &ShapeBuild::operator delete[], "None", py::arg("theAddress"));
// cls_ShapeBuild.def_static("operator new_", (void * (*)(size_t, void *)) &ShapeBuild::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ShapeBuild.def_static("operator delete_", (void (*)(void *, void *)) &ShapeBuild::operator delete, "None", py::arg(""), py::arg(""));
cls_ShapeBuild.def_static("PlaneXOY_", (opencascade::handle<Geom_Plane> (*)()) &ShapeBuild::PlaneXOY, "Rebuilds a shape with substitution of some components Returns a Geom_Surface which is the Plane XOY (Z positive) This allows to consider an UV space homologous to a 3D space, with this support surface");

// Enums

}