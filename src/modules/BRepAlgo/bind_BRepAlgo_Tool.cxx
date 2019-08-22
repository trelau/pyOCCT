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
#include <TopoDS_Shape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <BRepAlgo_Tool.hxx>

void bind_BRepAlgo_Tool(py::module &mod){

py::class_<BRepAlgo_Tool> cls_BRepAlgo_Tool(mod, "BRepAlgo_Tool", "None");

// Constructors

// Fields

// Methods
// cls_BRepAlgo_Tool.def_static("operator new_", (void * (*)(size_t)) &BRepAlgo_Tool::operator new, "None", py::arg("theSize"));
// cls_BRepAlgo_Tool.def_static("operator delete_", (void (*)(void *)) &BRepAlgo_Tool::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgo_Tool.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgo_Tool::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgo_Tool.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgo_Tool::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgo_Tool.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgo_Tool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgo_Tool.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgo_Tool::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepAlgo_Tool.def_static("Deboucle3D_", (TopoDS_Shape (*)(const TopoDS_Shape &, const TopTools_MapOfShape &)) &BRepAlgo_Tool::Deboucle3D, "Remove the non valid part of an offsetshape 1 - Remove all the free boundary and the faces connex to such edges. 2 - Remove all the shapes not valid in the result (according to the side of offseting) in this verion only the first point is implemented.", py::arg("S"), py::arg("Boundary"));

// Enums

}