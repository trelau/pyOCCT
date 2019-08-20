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
#include <BRepBuilderAPI_MakeShape.hxx>
#include <Standard.hxx>
#include <TopoDS_Face.hxx>
#include <gp_Pnt.hxx>
#include <TopoDS_Shell.hxx>
#include <TopoDS_Solid.hxx>
#include <BRepPrimAPI_MakeHalfSpace.hxx>

void bind_BRepPrimAPI_MakeHalfSpace(py::module &mod){

py::class_<BRepPrimAPI_MakeHalfSpace, std::unique_ptr<BRepPrimAPI_MakeHalfSpace>, BRepBuilderAPI_MakeShape> cls_BRepPrimAPI_MakeHalfSpace(mod, "BRepPrimAPI_MakeHalfSpace", "Describes functions to build half-spaces. A half-space is an infinite solid, limited by a surface. It is built from a face or a shell, which bounds it, and with a reference point, which specifies the side of the surface where the matter of the half-space is located. A half-space is a tool commonly used in topological operations to cut another shape. A MakeHalfSpace object provides a framework for: - defining and implementing the construction of a half-space, and - consulting the result.");

// Constructors
cls_BRepPrimAPI_MakeHalfSpace.def(py::init<const TopoDS_Face &, const gp_Pnt &>(), py::arg("Face"), py::arg("RefPnt"));
cls_BRepPrimAPI_MakeHalfSpace.def(py::init<const TopoDS_Shell &, const gp_Pnt &>(), py::arg("Shell"), py::arg("RefPnt"));

// Fields

// Methods
// cls_BRepPrimAPI_MakeHalfSpace.def_static("operator new_", (void * (*)(size_t)) &BRepPrimAPI_MakeHalfSpace::operator new, "None", py::arg("theSize"));
// cls_BRepPrimAPI_MakeHalfSpace.def_static("operator delete_", (void (*)(void *)) &BRepPrimAPI_MakeHalfSpace::operator delete, "None", py::arg("theAddress"));
// cls_BRepPrimAPI_MakeHalfSpace.def_static("operator new[]_", (void * (*)(size_t)) &BRepPrimAPI_MakeHalfSpace::operator new[], "None", py::arg("theSize"));
// cls_BRepPrimAPI_MakeHalfSpace.def_static("operator delete[]_", (void (*)(void *)) &BRepPrimAPI_MakeHalfSpace::operator delete[], "None", py::arg("theAddress"));
// cls_BRepPrimAPI_MakeHalfSpace.def_static("operator new_", (void * (*)(size_t, void *)) &BRepPrimAPI_MakeHalfSpace::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepPrimAPI_MakeHalfSpace.def_static("operator delete_", (void (*)(void *, void *)) &BRepPrimAPI_MakeHalfSpace::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepPrimAPI_MakeHalfSpace.def("Solid", (const TopoDS_Solid & (BRepPrimAPI_MakeHalfSpace::*)() const) &BRepPrimAPI_MakeHalfSpace::Solid, "Returns the constructed half-space as a solid.");

// Enums

}