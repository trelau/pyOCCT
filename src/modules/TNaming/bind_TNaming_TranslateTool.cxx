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
#include <Standard_Transient.hxx>
#include <TopoDS_Shape.hxx>
#include <TColStd_IndexedDataMapOfTransientTransient.hxx>
#include <Standard_Handle.hxx>
#include <TNaming_TranslateTool.hxx>
#include <Standard_Type.hxx>

void bind_TNaming_TranslateTool(py::module &mod){

py::class_<TNaming_TranslateTool, opencascade::handle<TNaming_TranslateTool>, Standard_Transient> cls_TNaming_TranslateTool(mod, "TNaming_TranslateTool", "tool to copy underlying TShape of a Shape. The TranslateTool class is provided to support the translation of topological data structures Transient to Transient.");

// Constructors

// Fields

// Methods
cls_TNaming_TranslateTool.def("Add", (void (TNaming_TranslateTool::*)(TopoDS_Shape &, const TopoDS_Shape &) const) &TNaming_TranslateTool::Add, "None", py::arg("S1"), py::arg("S2"));
cls_TNaming_TranslateTool.def("MakeVertex", (void (TNaming_TranslateTool::*)(TopoDS_Shape &) const) &TNaming_TranslateTool::MakeVertex, "None", py::arg("S"));
cls_TNaming_TranslateTool.def("MakeEdge", (void (TNaming_TranslateTool::*)(TopoDS_Shape &) const) &TNaming_TranslateTool::MakeEdge, "None", py::arg("S"));
cls_TNaming_TranslateTool.def("MakeWire", (void (TNaming_TranslateTool::*)(TopoDS_Shape &) const) &TNaming_TranslateTool::MakeWire, "None", py::arg("S"));
cls_TNaming_TranslateTool.def("MakeFace", (void (TNaming_TranslateTool::*)(TopoDS_Shape &) const) &TNaming_TranslateTool::MakeFace, "None", py::arg("S"));
cls_TNaming_TranslateTool.def("MakeShell", (void (TNaming_TranslateTool::*)(TopoDS_Shape &) const) &TNaming_TranslateTool::MakeShell, "None", py::arg("S"));
cls_TNaming_TranslateTool.def("MakeSolid", (void (TNaming_TranslateTool::*)(TopoDS_Shape &) const) &TNaming_TranslateTool::MakeSolid, "None", py::arg("S"));
cls_TNaming_TranslateTool.def("MakeCompSolid", (void (TNaming_TranslateTool::*)(TopoDS_Shape &) const) &TNaming_TranslateTool::MakeCompSolid, "None", py::arg("S"));
cls_TNaming_TranslateTool.def("MakeCompound", (void (TNaming_TranslateTool::*)(TopoDS_Shape &) const) &TNaming_TranslateTool::MakeCompound, "None", py::arg("S"));
cls_TNaming_TranslateTool.def("UpdateVertex", (void (TNaming_TranslateTool::*)(const TopoDS_Shape &, TopoDS_Shape &, TColStd_IndexedDataMapOfTransientTransient &) const) &TNaming_TranslateTool::UpdateVertex, "None", py::arg("S1"), py::arg("S2"), py::arg("M"));
cls_TNaming_TranslateTool.def("UpdateEdge", (void (TNaming_TranslateTool::*)(const TopoDS_Shape &, TopoDS_Shape &, TColStd_IndexedDataMapOfTransientTransient &) const) &TNaming_TranslateTool::UpdateEdge, "None", py::arg("S1"), py::arg("S2"), py::arg("M"));
cls_TNaming_TranslateTool.def("UpdateFace", (void (TNaming_TranslateTool::*)(const TopoDS_Shape &, TopoDS_Shape &, TColStd_IndexedDataMapOfTransientTransient &) const) &TNaming_TranslateTool::UpdateFace, "None", py::arg("S1"), py::arg("S2"), py::arg("M"));
cls_TNaming_TranslateTool.def("UpdateShape", (void (TNaming_TranslateTool::*)(const TopoDS_Shape &, TopoDS_Shape &) const) &TNaming_TranslateTool::UpdateShape, "None", py::arg("S1"), py::arg("S2"));
cls_TNaming_TranslateTool.def_static("get_type_name_", (const char * (*)()) &TNaming_TranslateTool::get_type_name, "None");
cls_TNaming_TranslateTool.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TNaming_TranslateTool::get_type_descriptor, "None");
cls_TNaming_TranslateTool.def("DynamicType", (const opencascade::handle<Standard_Type> & (TNaming_TranslateTool::*)() const) &TNaming_TranslateTool::DynamicType, "None");

// Enums

}