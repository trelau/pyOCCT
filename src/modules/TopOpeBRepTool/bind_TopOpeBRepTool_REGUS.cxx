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
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopoDS_Edge.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <TopOpeBRepTool_REGUS.hxx>

void bind_TopOpeBRepTool_REGUS(py::module &mod){

py::class_<TopOpeBRepTool_REGUS> cls_TopOpeBRepTool_REGUS(mod, "TopOpeBRepTool_REGUS", "None");

// Constructors
cls_TopOpeBRepTool_REGUS.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRepTool_REGUS.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_REGUS::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_REGUS.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_REGUS::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_REGUS.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_REGUS::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_REGUS.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_REGUS::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_REGUS.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_REGUS::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_REGUS.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_REGUS::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_REGUS.def("Init", (void (TopOpeBRepTool_REGUS::*)(const TopoDS_Shape &)) &TopOpeBRepTool_REGUS::Init, "None", py::arg("S"));
cls_TopOpeBRepTool_REGUS.def("S", (const TopoDS_Shape & (TopOpeBRepTool_REGUS::*)() const) &TopOpeBRepTool_REGUS::S, "None");
cls_TopOpeBRepTool_REGUS.def("MapS", (Standard_Boolean (TopOpeBRepTool_REGUS::*)()) &TopOpeBRepTool_REGUS::MapS, "None");
cls_TopOpeBRepTool_REGUS.def_static("WireToFace_", (Standard_Boolean (*)(const TopoDS_Face &, const TopTools_ListOfShape &, TopTools_ListOfShape &)) &TopOpeBRepTool_REGUS::WireToFace, "None", py::arg("Fanc"), py::arg("nWs"), py::arg("nFs"));
cls_TopOpeBRepTool_REGUS.def_static("SplitF_", (Standard_Boolean (*)(const TopoDS_Face &, TopTools_ListOfShape &)) &TopOpeBRepTool_REGUS::SplitF, "None", py::arg("Fanc"), py::arg("FSplits"));
cls_TopOpeBRepTool_REGUS.def("SplitFaces", (Standard_Boolean (TopOpeBRepTool_REGUS::*)()) &TopOpeBRepTool_REGUS::SplitFaces, "None");
cls_TopOpeBRepTool_REGUS.def("REGU", (Standard_Boolean (TopOpeBRepTool_REGUS::*)()) &TopOpeBRepTool_REGUS::REGU, "None");
cls_TopOpeBRepTool_REGUS.def("SetFsplits", (void (TopOpeBRepTool_REGUS::*)(TopTools_DataMapOfShapeListOfShape &)) &TopOpeBRepTool_REGUS::SetFsplits, "None", py::arg("Fsplits"));
cls_TopOpeBRepTool_REGUS.def("GetFsplits", (void (TopOpeBRepTool_REGUS::*)(TopTools_DataMapOfShapeListOfShape &) const) &TopOpeBRepTool_REGUS::GetFsplits, "None", py::arg("Fsplits"));
cls_TopOpeBRepTool_REGUS.def("SetOshNsh", (void (TopOpeBRepTool_REGUS::*)(TopTools_DataMapOfShapeListOfShape &)) &TopOpeBRepTool_REGUS::SetOshNsh, "None", py::arg("OshNsh"));
cls_TopOpeBRepTool_REGUS.def("GetOshNsh", (void (TopOpeBRepTool_REGUS::*)(TopTools_DataMapOfShapeListOfShape &) const) &TopOpeBRepTool_REGUS::GetOshNsh, "None", py::arg("OshNsh"));
cls_TopOpeBRepTool_REGUS.def("InitBlock", (Standard_Boolean (TopOpeBRepTool_REGUS::*)()) &TopOpeBRepTool_REGUS::InitBlock, "None");
cls_TopOpeBRepTool_REGUS.def("NextinBlock", (Standard_Boolean (TopOpeBRepTool_REGUS::*)()) &TopOpeBRepTool_REGUS::NextinBlock, "None");
cls_TopOpeBRepTool_REGUS.def("NearestF", (Standard_Boolean (TopOpeBRepTool_REGUS::*)(const TopoDS_Edge &, const TopTools_ListOfShape &, TopoDS_Face &) const) &TopOpeBRepTool_REGUS::NearestF, "None", py::arg("e"), py::arg("lof"), py::arg("ffound"));

// Enums

}