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
#include <BRep_Builder.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_Orientation.hxx>
#include <BRepSweep_Builder.hxx>

void bind_BRepSweep_Builder(py::module &mod){

py::class_<BRepSweep_Builder, std::unique_ptr<BRepSweep_Builder>> cls_BRepSweep_Builder(mod, "BRepSweep_Builder", "implements the abstract Builder with the BRep Builder");

// Constructors
cls_BRepSweep_Builder.def(py::init<const BRep_Builder &>(), py::arg("aBuilder"));

// Fields

// Methods
// cls_BRepSweep_Builder.def_static("operator new_", (void * (*)(size_t)) &BRepSweep_Builder::operator new, "None", py::arg("theSize"));
// cls_BRepSweep_Builder.def_static("operator delete_", (void (*)(void *)) &BRepSweep_Builder::operator delete, "None", py::arg("theAddress"));
// cls_BRepSweep_Builder.def_static("operator new[]_", (void * (*)(size_t)) &BRepSweep_Builder::operator new[], "None", py::arg("theSize"));
// cls_BRepSweep_Builder.def_static("operator delete[]_", (void (*)(void *)) &BRepSweep_Builder::operator delete[], "None", py::arg("theAddress"));
// cls_BRepSweep_Builder.def_static("operator new_", (void * (*)(size_t, void *)) &BRepSweep_Builder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepSweep_Builder.def_static("operator delete_", (void (*)(void *, void *)) &BRepSweep_Builder::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepSweep_Builder.def("Builder", (const BRep_Builder & (BRepSweep_Builder::*)() const) &BRepSweep_Builder::Builder, "None");
cls_BRepSweep_Builder.def("MakeCompound", (void (BRepSweep_Builder::*)(TopoDS_Shape &) const) &BRepSweep_Builder::MakeCompound, "Returns an empty Compound.", py::arg("aCompound"));
cls_BRepSweep_Builder.def("MakeCompSolid", (void (BRepSweep_Builder::*)(TopoDS_Shape &) const) &BRepSweep_Builder::MakeCompSolid, "Returns an empty CompSolid.", py::arg("aCompSolid"));
cls_BRepSweep_Builder.def("MakeSolid", (void (BRepSweep_Builder::*)(TopoDS_Shape &) const) &BRepSweep_Builder::MakeSolid, "Returns an empty Solid.", py::arg("aSolid"));
cls_BRepSweep_Builder.def("MakeShell", (void (BRepSweep_Builder::*)(TopoDS_Shape &) const) &BRepSweep_Builder::MakeShell, "Returns an empty Shell.", py::arg("aShell"));
cls_BRepSweep_Builder.def("MakeWire", (void (BRepSweep_Builder::*)(TopoDS_Shape &) const) &BRepSweep_Builder::MakeWire, "Returns an empty Wire.", py::arg("aWire"));
cls_BRepSweep_Builder.def("Add", (void (BRepSweep_Builder::*)(TopoDS_Shape &, const TopoDS_Shape &, const TopAbs_Orientation) const) &BRepSweep_Builder::Add, "Adds the Shape 1 in the Shape 2, set to <Orient> orientation.", py::arg("aShape1"), py::arg("aShape2"), py::arg("Orient"));
cls_BRepSweep_Builder.def("Add", (void (BRepSweep_Builder::*)(TopoDS_Shape &, const TopoDS_Shape &) const) &BRepSweep_Builder::Add, "Adds the Shape 1 in the Shape 2.", py::arg("aShape1"), py::arg("aShape2"));

// Enums

}