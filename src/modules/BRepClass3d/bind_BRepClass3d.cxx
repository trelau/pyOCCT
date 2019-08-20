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
#include <TopoDS_Shell.hxx>
#include <TopoDS_Solid.hxx>
#include <BRepClass3d_Intersector3d.hxx>
#include <BRepClass3d_SolidExplorer.hxx>
#include <BRepClass3d_SolidPassiveClassifier.hxx>
#include <BRepClass3d_SClassifier.hxx>
#include <BRepClass3d_SolidClassifier.hxx>
#include <BRepClass3d.hxx>

void bind_BRepClass3d(py::module &mod){

py::class_<BRepClass3d, std::unique_ptr<BRepClass3d>> cls_BRepClass3d(mod, "BRepClass3d", "None");

// Constructors

// Fields

// Methods
// cls_BRepClass3d.def_static("operator new_", (void * (*)(size_t)) &BRepClass3d::operator new, "None", py::arg("theSize"));
// cls_BRepClass3d.def_static("operator delete_", (void (*)(void *)) &BRepClass3d::operator delete, "None", py::arg("theAddress"));
// cls_BRepClass3d.def_static("operator new[]_", (void * (*)(size_t)) &BRepClass3d::operator new[], "None", py::arg("theSize"));
// cls_BRepClass3d.def_static("operator delete[]_", (void (*)(void *)) &BRepClass3d::operator delete[], "None", py::arg("theAddress"));
// cls_BRepClass3d.def_static("operator new_", (void * (*)(size_t, void *)) &BRepClass3d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepClass3d.def_static("operator delete_", (void (*)(void *, void *)) &BRepClass3d::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepClass3d.def_static("OuterShell_", (TopoDS_Shell (*)(const TopoDS_Solid &)) &BRepClass3d::OuterShell, "Returns the outer most shell of <S>. Returns a Null shell if <S> has no outer shell. If <S> has only one shell, then it will return, without checking orientation.", py::arg("S"));

// Enums

}