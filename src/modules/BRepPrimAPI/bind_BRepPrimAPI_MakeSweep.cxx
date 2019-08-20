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
#include <TopoDS_Shape.hxx>
#include <BRepPrimAPI_MakeSweep.hxx>

void bind_BRepPrimAPI_MakeSweep(py::module &mod){

py::class_<BRepPrimAPI_MakeSweep, std::unique_ptr<BRepPrimAPI_MakeSweep>, BRepBuilderAPI_MakeShape> cls_BRepPrimAPI_MakeSweep(mod, "BRepPrimAPI_MakeSweep", "The abstract class MakeSweep is the root class of swept primitives. Sweeps are objects you obtain by sweeping a profile along a path. The profile can be any topology and the path is usually a curve or a wire. The profile generates objects according to the following rules: - Vertices generate Edges - Edges generate Faces. - Wires generate Shells. - Faces generate Solids. - Shells generate Composite Solids. You are not allowed to sweep Solids and Composite Solids. Two kinds of sweeps are implemented in the BRepPrimAPI package: - The linear sweep called a Prism - The rotational sweep called a Revol Swept constructions along complex profiles such as BSpline curves are also available in the BRepOffsetAPI package..");

// Fields

// Methods
// cls_BRepPrimAPI_MakeSweep.def_static("operator new_", (void * (*)(size_t)) &BRepPrimAPI_MakeSweep::operator new, "None", py::arg("theSize"));
// cls_BRepPrimAPI_MakeSweep.def_static("operator delete_", (void (*)(void *)) &BRepPrimAPI_MakeSweep::operator delete, "None", py::arg("theAddress"));
// cls_BRepPrimAPI_MakeSweep.def_static("operator new[]_", (void * (*)(size_t)) &BRepPrimAPI_MakeSweep::operator new[], "None", py::arg("theSize"));
// cls_BRepPrimAPI_MakeSweep.def_static("operator delete[]_", (void (*)(void *)) &BRepPrimAPI_MakeSweep::operator delete[], "None", py::arg("theAddress"));
// cls_BRepPrimAPI_MakeSweep.def_static("operator new_", (void * (*)(size_t, void *)) &BRepPrimAPI_MakeSweep::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepPrimAPI_MakeSweep.def_static("operator delete_", (void (*)(void *, void *)) &BRepPrimAPI_MakeSweep::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepPrimAPI_MakeSweep.def("FirstShape", (TopoDS_Shape (BRepPrimAPI_MakeSweep::*)()) &BRepPrimAPI_MakeSweep::FirstShape, "Returns the TopoDS Shape of the bottom of the sweep.");
cls_BRepPrimAPI_MakeSweep.def("LastShape", (TopoDS_Shape (BRepPrimAPI_MakeSweep::*)()) &BRepPrimAPI_MakeSweep::LastShape, "Returns the TopoDS Shape of the top of the sweep.");

// Enums

}