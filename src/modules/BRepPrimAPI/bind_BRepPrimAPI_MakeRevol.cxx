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
#include <BRepPrimAPI_MakeSweep.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <gp_Ax1.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepSweep_Revol.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BRepPrimAPI_MakeRevol.hxx>

void bind_BRepPrimAPI_MakeRevol(py::module &mod){

py::class_<BRepPrimAPI_MakeRevol, std::unique_ptr<BRepPrimAPI_MakeRevol, Deleter<BRepPrimAPI_MakeRevol>>, BRepPrimAPI_MakeSweep> cls_BRepPrimAPI_MakeRevol(mod, "BRepPrimAPI_MakeRevol", "Class to make revolved sweep topologies.");

// Constructors
cls_BRepPrimAPI_MakeRevol.def(py::init<const TopoDS_Shape &, const gp_Ax1 &, const Standard_Real>(), py::arg("S"), py::arg("A"), py::arg("D"));
cls_BRepPrimAPI_MakeRevol.def(py::init<const TopoDS_Shape &, const gp_Ax1 &, const Standard_Real, const Standard_Boolean>(), py::arg("S"), py::arg("A"), py::arg("D"), py::arg("Copy"));
cls_BRepPrimAPI_MakeRevol.def(py::init<const TopoDS_Shape &, const gp_Ax1 &>(), py::arg("S"), py::arg("A"));
cls_BRepPrimAPI_MakeRevol.def(py::init<const TopoDS_Shape &, const gp_Ax1 &, const Standard_Boolean>(), py::arg("S"), py::arg("A"), py::arg("Copy"));

// Fields

// Methods
// cls_BRepPrimAPI_MakeRevol.def_static("operator new_", (void * (*)(size_t)) &BRepPrimAPI_MakeRevol::operator new, "None", py::arg("theSize"));
// cls_BRepPrimAPI_MakeRevol.def_static("operator delete_", (void (*)(void *)) &BRepPrimAPI_MakeRevol::operator delete, "None", py::arg("theAddress"));
// cls_BRepPrimAPI_MakeRevol.def_static("operator new[]_", (void * (*)(size_t)) &BRepPrimAPI_MakeRevol::operator new[], "None", py::arg("theSize"));
// cls_BRepPrimAPI_MakeRevol.def_static("operator delete[]_", (void (*)(void *)) &BRepPrimAPI_MakeRevol::operator delete[], "None", py::arg("theAddress"));
// cls_BRepPrimAPI_MakeRevol.def_static("operator new_", (void * (*)(size_t, void *)) &BRepPrimAPI_MakeRevol::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepPrimAPI_MakeRevol.def_static("operator delete_", (void (*)(void *, void *)) &BRepPrimAPI_MakeRevol::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepPrimAPI_MakeRevol.def("Revol", (const BRepSweep_Revol & (BRepPrimAPI_MakeRevol::*)() const) &BRepPrimAPI_MakeRevol::Revol, "Returns the internal sweeping algorithm.");
cls_BRepPrimAPI_MakeRevol.def("Build", (void (BRepPrimAPI_MakeRevol::*)()) &BRepPrimAPI_MakeRevol::Build, "Builds the resulting shape (redefined from MakeShape).");
cls_BRepPrimAPI_MakeRevol.def("FirstShape", (TopoDS_Shape (BRepPrimAPI_MakeRevol::*)()) &BRepPrimAPI_MakeRevol::FirstShape, "Returns the first shape of the revol (coinciding with the generating shape).");
cls_BRepPrimAPI_MakeRevol.def("LastShape", (TopoDS_Shape (BRepPrimAPI_MakeRevol::*)()) &BRepPrimAPI_MakeRevol::LastShape, "Returns the TopoDS Shape of the end of the revol.");
cls_BRepPrimAPI_MakeRevol.def("Generated", (const TopTools_ListOfShape & (BRepPrimAPI_MakeRevol::*)(const TopoDS_Shape &)) &BRepPrimAPI_MakeRevol::Generated, "None", py::arg("S"));
cls_BRepPrimAPI_MakeRevol.def("FirstShape", (TopoDS_Shape (BRepPrimAPI_MakeRevol::*)(const TopoDS_Shape &)) &BRepPrimAPI_MakeRevol::FirstShape, "Returns the TopoDS Shape of the beginning of the revolution, generated with theShape (subShape of the generating shape).", py::arg("theShape"));
cls_BRepPrimAPI_MakeRevol.def("LastShape", (TopoDS_Shape (BRepPrimAPI_MakeRevol::*)(const TopoDS_Shape &)) &BRepPrimAPI_MakeRevol::LastShape, "Returns the TopoDS Shape of the end of the revolution, generated with theShape (subShape of the generating shape).", py::arg("theShape"));
cls_BRepPrimAPI_MakeRevol.def("HasDegenerated", (Standard_Boolean (BRepPrimAPI_MakeRevol::*)() const) &BRepPrimAPI_MakeRevol::HasDegenerated, "Check if there are degenerated edges in the result.");
cls_BRepPrimAPI_MakeRevol.def("Degenerated", (const TopTools_ListOfShape & (BRepPrimAPI_MakeRevol::*)() const) &BRepPrimAPI_MakeRevol::Degenerated, "None");

// Enums

}