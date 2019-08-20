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
#include <TopoDS_Shape.hxx>
#include <Standard.hxx>
#include <TopoDS_Face.hxx>

void bind_TopoDS_Face(py::module &mod){

py::class_<TopoDS_Face, std::unique_ptr<TopoDS_Face>, TopoDS_Shape> cls_TopoDS_Face(mod, "TopoDS_Face", "Describes a face which - references an underlying face with the potential to be given a location and an orientation - has a location for the underlying face, giving its placement in the local coordinate system - has an orientation for the underlying face, in terms of its geometry (as opposed to orientation in relation to other shapes).");

// Constructors
cls_TopoDS_Face.def(py::init<>());

// Fields

// Methods
// cls_TopoDS_Face.def_static("operator new_", (void * (*)(size_t)) &TopoDS_Face::operator new, "None", py::arg("theSize"));
// cls_TopoDS_Face.def_static("operator delete_", (void (*)(void *)) &TopoDS_Face::operator delete, "None", py::arg("theAddress"));
// cls_TopoDS_Face.def_static("operator new[]_", (void * (*)(size_t)) &TopoDS_Face::operator new[], "None", py::arg("theSize"));
// cls_TopoDS_Face.def_static("operator delete[]_", (void (*)(void *)) &TopoDS_Face::operator delete[], "None", py::arg("theAddress"));
// cls_TopoDS_Face.def_static("operator new_", (void * (*)(size_t, void *)) &TopoDS_Face::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopoDS_Face.def_static("operator delete_", (void (*)(void *, void *)) &TopoDS_Face::operator delete, "None", py::arg(""), py::arg(""));

// Enums

}