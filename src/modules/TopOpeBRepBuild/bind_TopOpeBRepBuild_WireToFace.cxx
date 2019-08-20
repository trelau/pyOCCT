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
#include <TopoDS_Wire.hxx>
#include <TopoDS_Face.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopOpeBRepBuild_WireToFace.hxx>

void bind_TopOpeBRepBuild_WireToFace(py::module &mod){

py::class_<TopOpeBRepBuild_WireToFace, std::unique_ptr<TopOpeBRepBuild_WireToFace>> cls_TopOpeBRepBuild_WireToFace(mod, "TopOpeBRepBuild_WireToFace", "This class builds faces from a set of wires SW and a face F. The face must have and underlying surface, say S. All of the edges of all of the wires must have a 2d representation on surface S (except if S is planar)");

// Constructors
cls_TopOpeBRepBuild_WireToFace.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRepBuild_WireToFace.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_WireToFace::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_WireToFace.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_WireToFace::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_WireToFace.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_WireToFace::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_WireToFace.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_WireToFace::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_WireToFace.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_WireToFace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_WireToFace.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_WireToFace::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_WireToFace.def("Init", (void (TopOpeBRepBuild_WireToFace::*)()) &TopOpeBRepBuild_WireToFace::Init, "None");
cls_TopOpeBRepBuild_WireToFace.def("AddWire", (void (TopOpeBRepBuild_WireToFace::*)(const TopoDS_Wire &)) &TopOpeBRepBuild_WireToFace::AddWire, "None", py::arg("W"));
cls_TopOpeBRepBuild_WireToFace.def("MakeFaces", (void (TopOpeBRepBuild_WireToFace::*)(const TopoDS_Face &, TopTools_ListOfShape &)) &TopOpeBRepBuild_WireToFace::MakeFaces, "None", py::arg("F"), py::arg("LF"));

// Enums

}