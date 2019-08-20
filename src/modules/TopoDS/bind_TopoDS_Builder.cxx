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
#include <TopoDS_Shell.hxx>
#include <TopoDS_Solid.hxx>
#include <TopoDS_CompSolid.hxx>
#include <TopoDS_Compound.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <TopoDS_TShape.hxx>
#include <TopoDS_Builder.hxx>

void bind_TopoDS_Builder(py::module &mod){

py::class_<TopoDS_Builder, std::unique_ptr<TopoDS_Builder>> cls_TopoDS_Builder(mod, "TopoDS_Builder", "A Builder is used to create Topological Data Structures.It is the root of the Builder class hierarchy.");

// Constructors

// Fields

// Methods
// cls_TopoDS_Builder.def_static("operator new_", (void * (*)(size_t)) &TopoDS_Builder::operator new, "None", py::arg("theSize"));
// cls_TopoDS_Builder.def_static("operator delete_", (void (*)(void *)) &TopoDS_Builder::operator delete, "None", py::arg("theAddress"));
// cls_TopoDS_Builder.def_static("operator new[]_", (void * (*)(size_t)) &TopoDS_Builder::operator new[], "None", py::arg("theSize"));
// cls_TopoDS_Builder.def_static("operator delete[]_", (void (*)(void *)) &TopoDS_Builder::operator delete[], "None", py::arg("theAddress"));
// cls_TopoDS_Builder.def_static("operator new_", (void * (*)(size_t, void *)) &TopoDS_Builder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopoDS_Builder.def_static("operator delete_", (void (*)(void *, void *)) &TopoDS_Builder::operator delete, "None", py::arg(""), py::arg(""));
cls_TopoDS_Builder.def("MakeWire", (void (TopoDS_Builder::*)(TopoDS_Wire &) const) &TopoDS_Builder::MakeWire, "Make an empty Wire.", py::arg("W"));
cls_TopoDS_Builder.def("MakeShell", (void (TopoDS_Builder::*)(TopoDS_Shell &) const) &TopoDS_Builder::MakeShell, "Make an empty Shell.", py::arg("S"));
cls_TopoDS_Builder.def("MakeSolid", (void (TopoDS_Builder::*)(TopoDS_Solid &) const) &TopoDS_Builder::MakeSolid, "Make a Solid covering the whole 3D space.", py::arg("S"));
cls_TopoDS_Builder.def("MakeCompSolid", (void (TopoDS_Builder::*)(TopoDS_CompSolid &) const) &TopoDS_Builder::MakeCompSolid, "Make an empty Composite Solid.", py::arg("C"));
cls_TopoDS_Builder.def("MakeCompound", (void (TopoDS_Builder::*)(TopoDS_Compound &) const) &TopoDS_Builder::MakeCompound, "Make an empty Compound.", py::arg("C"));
cls_TopoDS_Builder.def("Add", (void (TopoDS_Builder::*)(TopoDS_Shape &, const TopoDS_Shape &) const) &TopoDS_Builder::Add, "Add the Shape C in the Shape S. Exceptions - TopoDS_FrozenShape if S is not free and cannot be modified. - TopoDS__UnCompatibleShapes if S and C are not compatible.", py::arg("S"), py::arg("C"));
cls_TopoDS_Builder.def("Remove", (void (TopoDS_Builder::*)(TopoDS_Shape &, const TopoDS_Shape &) const) &TopoDS_Builder::Remove, "Remove the Shape C from the Shape S. Exceptions TopoDS_FrozenShape if S is frozen and cannot be modified.", py::arg("S"), py::arg("C"));

// Enums

}