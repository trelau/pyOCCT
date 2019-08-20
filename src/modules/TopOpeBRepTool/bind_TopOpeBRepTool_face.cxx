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
#include <TopoDS_Wire.hxx>
#include <TopoDS_Face.hxx>
#include <TopOpeBRepTool_face.hxx>

void bind_TopOpeBRepTool_face(py::module &mod){

py::class_<TopOpeBRepTool_face, std::unique_ptr<TopOpeBRepTool_face>> cls_TopOpeBRepTool_face(mod, "TopOpeBRepTool_face", "None");

// Constructors
cls_TopOpeBRepTool_face.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRepTool_face.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_face::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_face.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_face::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_face.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_face::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_face.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_face::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_face.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_face::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_face.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_face::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_face.def("Init", (Standard_Boolean (TopOpeBRepTool_face::*)(const TopoDS_Wire &, const TopoDS_Face &)) &TopOpeBRepTool_face::Init, "None", py::arg("W"), py::arg("Fref"));
cls_TopOpeBRepTool_face.def("W", (const TopoDS_Wire & (TopOpeBRepTool_face::*)() const) &TopOpeBRepTool_face::W, "None");
cls_TopOpeBRepTool_face.def("IsDone", (Standard_Boolean (TopOpeBRepTool_face::*)() const) &TopOpeBRepTool_face::IsDone, "None");
cls_TopOpeBRepTool_face.def("Finite", (Standard_Boolean (TopOpeBRepTool_face::*)() const) &TopOpeBRepTool_face::Finite, "None");
cls_TopOpeBRepTool_face.def("Ffinite", (const TopoDS_Face & (TopOpeBRepTool_face::*)() const) &TopOpeBRepTool_face::Ffinite, "None");
cls_TopOpeBRepTool_face.def("RealF", (TopoDS_Face (TopOpeBRepTool_face::*)() const) &TopOpeBRepTool_face::RealF, "None");

// Enums

}