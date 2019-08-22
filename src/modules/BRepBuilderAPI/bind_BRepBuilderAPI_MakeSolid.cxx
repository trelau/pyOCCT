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
#include <TopoDS_CompSolid.hxx>
#include <TopoDS_Shell.hxx>
#include <TopoDS_Solid.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepLib_MakeSolid.hxx>
#include <BRepBuilderAPI_MakeSolid.hxx>

void bind_BRepBuilderAPI_MakeSolid(py::module &mod){

py::class_<BRepBuilderAPI_MakeSolid, BRepBuilderAPI_MakeShape> cls_BRepBuilderAPI_MakeSolid(mod, "BRepBuilderAPI_MakeSolid", "Describes functions to build a solid from shells. A solid is made of one shell, or a series of shells, which do not intersect each other. One of these shells constitutes the outside skin of the solid. It may be closed (a finite solid) or open (an infinite solid). Other shells form hollows (cavities) in these previous ones. Each must bound a closed volume. A MakeSolid object provides a framework for: - defining and implementing the construction of a solid, and - consulting the result.");

// Constructors
cls_BRepBuilderAPI_MakeSolid.def(py::init<>());
cls_BRepBuilderAPI_MakeSolid.def(py::init<const TopoDS_CompSolid &>(), py::arg("S"));
cls_BRepBuilderAPI_MakeSolid.def(py::init<const TopoDS_Shell &>(), py::arg("S"));
cls_BRepBuilderAPI_MakeSolid.def(py::init<const TopoDS_Shell &, const TopoDS_Shell &>(), py::arg("S1"), py::arg("S2"));
cls_BRepBuilderAPI_MakeSolid.def(py::init<const TopoDS_Shell &, const TopoDS_Shell &, const TopoDS_Shell &>(), py::arg("S1"), py::arg("S2"), py::arg("S3"));
cls_BRepBuilderAPI_MakeSolid.def(py::init<const TopoDS_Solid &>(), py::arg("So"));
cls_BRepBuilderAPI_MakeSolid.def(py::init<const TopoDS_Solid &, const TopoDS_Shell &>(), py::arg("So"), py::arg("S"));

// Fields

// Methods
// cls_BRepBuilderAPI_MakeSolid.def_static("operator new_", (void * (*)(size_t)) &BRepBuilderAPI_MakeSolid::operator new, "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeSolid.def_static("operator delete_", (void (*)(void *)) &BRepBuilderAPI_MakeSolid::operator delete, "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeSolid.def_static("operator new[]_", (void * (*)(size_t)) &BRepBuilderAPI_MakeSolid::operator new[], "None", py::arg("theSize"));
// cls_BRepBuilderAPI_MakeSolid.def_static("operator delete[]_", (void (*)(void *)) &BRepBuilderAPI_MakeSolid::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeSolid.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBuilderAPI_MakeSolid::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBuilderAPI_MakeSolid.def_static("operator delete_", (void (*)(void *, void *)) &BRepBuilderAPI_MakeSolid::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBuilderAPI_MakeSolid.def("Add", (void (BRepBuilderAPI_MakeSolid::*)(const TopoDS_Shell &)) &BRepBuilderAPI_MakeSolid::Add, "Adds the shell to the current solid. Warning No check is done to verify the conditions of coherence of the resulting solid. In particular, S must not intersect other shells of the solid under construction. Besides, after all shells have been added, one of these shells should constitute the outside skin of the solid. It may be closed (a finite solid) or open (an infinite solid). Other shells form hollows (cavities) in these previous ones. Each must bound a closed volume.", py::arg("S"));
cls_BRepBuilderAPI_MakeSolid.def("IsDone", (Standard_Boolean (BRepBuilderAPI_MakeSolid::*)() const) &BRepBuilderAPI_MakeSolid::IsDone, "Returns true if the solid is built. For this class, a solid under construction is always valid. If no shell has been added, it could be a whole-space solid. However, no check was done to verify the conditions of coherence of the resulting solid.");
cls_BRepBuilderAPI_MakeSolid.def("Solid", (const TopoDS_Solid & (BRepBuilderAPI_MakeSolid::*)()) &BRepBuilderAPI_MakeSolid::Solid, "Returns the new Solid.");
cls_BRepBuilderAPI_MakeSolid.def("IsDeleted", (Standard_Boolean (BRepBuilderAPI_MakeSolid::*)(const TopoDS_Shape &)) &BRepBuilderAPI_MakeSolid::IsDeleted, "None", py::arg("S"));

// Enums

}