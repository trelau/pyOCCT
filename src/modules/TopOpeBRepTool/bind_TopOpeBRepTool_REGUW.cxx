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
#include <TopoDS_Face.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopOpeBRepTool_connexity.hxx>
#include <TopOpeBRepTool_CORRISO.hxx>
#include <TopOpeBRepTool_IndexedDataMapOfShapeconnexity.hxx>
#include <TopTools_MapOfShape.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Dir2d.hxx>
#include <TopOpeBRepTool_REGUW.hxx>

void bind_TopOpeBRepTool_REGUW(py::module &mod){

py::class_<TopOpeBRepTool_REGUW, std::unique_ptr<TopOpeBRepTool_REGUW>> cls_TopOpeBRepTool_REGUW(mod, "TopOpeBRepTool_REGUW", "None");

// Constructors
cls_TopOpeBRepTool_REGUW.def(py::init<const TopoDS_Face &>(), py::arg("FRef"));

// Fields

// Methods
// cls_TopOpeBRepTool_REGUW.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_REGUW::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_REGUW.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_REGUW::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_REGUW.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_REGUW::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_REGUW.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_REGUW::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_REGUW.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_REGUW::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_REGUW.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_REGUW::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_REGUW.def("Fref", (const TopoDS_Face & (TopOpeBRepTool_REGUW::*)() const) &TopOpeBRepTool_REGUW::Fref, "None");
cls_TopOpeBRepTool_REGUW.def("SetEsplits", (void (TopOpeBRepTool_REGUW::*)(TopTools_DataMapOfShapeListOfShape &)) &TopOpeBRepTool_REGUW::SetEsplits, "None", py::arg("Esplits"));
cls_TopOpeBRepTool_REGUW.def("GetEsplits", (void (TopOpeBRepTool_REGUW::*)(TopTools_DataMapOfShapeListOfShape &) const) &TopOpeBRepTool_REGUW::GetEsplits, "None", py::arg("Esplits"));
cls_TopOpeBRepTool_REGUW.def("SetOwNw", (void (TopOpeBRepTool_REGUW::*)(TopTools_DataMapOfShapeListOfShape &)) &TopOpeBRepTool_REGUW::SetOwNw, "None", py::arg("OwNw"));
cls_TopOpeBRepTool_REGUW.def("GetOwNw", (void (TopOpeBRepTool_REGUW::*)(TopTools_DataMapOfShapeListOfShape &) const) &TopOpeBRepTool_REGUW::GetOwNw, "None", py::arg("OwNw"));
cls_TopOpeBRepTool_REGUW.def("SplitEds", (Standard_Boolean (TopOpeBRepTool_REGUW::*)()) &TopOpeBRepTool_REGUW::SplitEds, "None");
cls_TopOpeBRepTool_REGUW.def("Init", (void (TopOpeBRepTool_REGUW::*)(const TopoDS_Shape &)) &TopOpeBRepTool_REGUW::Init, "None", py::arg("S"));
cls_TopOpeBRepTool_REGUW.def("S", (const TopoDS_Shape & (TopOpeBRepTool_REGUW::*)() const) &TopOpeBRepTool_REGUW::S, "None");
cls_TopOpeBRepTool_REGUW.def("HasInit", (Standard_Boolean (TopOpeBRepTool_REGUW::*)() const) &TopOpeBRepTool_REGUW::HasInit, "None");
cls_TopOpeBRepTool_REGUW.def("MapS", (Standard_Boolean (TopOpeBRepTool_REGUW::*)()) &TopOpeBRepTool_REGUW::MapS, "None");
cls_TopOpeBRepTool_REGUW.def("REGU", (Standard_Boolean (TopOpeBRepTool_REGUW::*)(const Standard_Integer, const TopoDS_Shape &, TopTools_ListOfShape &)) &TopOpeBRepTool_REGUW::REGU, "None", py::arg("istep"), py::arg("Scur"), py::arg("Splits"));
cls_TopOpeBRepTool_REGUW.def("REGU", (Standard_Boolean (TopOpeBRepTool_REGUW::*)()) &TopOpeBRepTool_REGUW::REGU, "None");
cls_TopOpeBRepTool_REGUW.def("GetSplits", (Standard_Boolean (TopOpeBRepTool_REGUW::*)(TopTools_ListOfShape &) const) &TopOpeBRepTool_REGUW::GetSplits, "None", py::arg("Splits"));
cls_TopOpeBRepTool_REGUW.def("InitBlock", (Standard_Boolean (TopOpeBRepTool_REGUW::*)()) &TopOpeBRepTool_REGUW::InitBlock, "None");
cls_TopOpeBRepTool_REGUW.def("NextinBlock", (Standard_Boolean (TopOpeBRepTool_REGUW::*)()) &TopOpeBRepTool_REGUW::NextinBlock, "None");
cls_TopOpeBRepTool_REGUW.def("NearestE", (Standard_Boolean (TopOpeBRepTool_REGUW::*)(const TopTools_ListOfShape &, TopoDS_Edge &) const) &TopOpeBRepTool_REGUW::NearestE, "None", py::arg("loe"), py::arg("efound"));
cls_TopOpeBRepTool_REGUW.def("Connexity", (Standard_Boolean (TopOpeBRepTool_REGUW::*)(const TopoDS_Vertex &, TopOpeBRepTool_connexity &) const) &TopOpeBRepTool_REGUW::Connexity, "None", py::arg("v"), py::arg("co"));
cls_TopOpeBRepTool_REGUW.def("AddNewConnexity", (Standard_Boolean (TopOpeBRepTool_REGUW::*)(const TopoDS_Vertex &, const Standard_Integer, const TopoDS_Edge &)) &TopOpeBRepTool_REGUW::AddNewConnexity, "None", py::arg("v"), py::arg("OriKey"), py::arg("e"));
cls_TopOpeBRepTool_REGUW.def("RemoveOldConnexity", (Standard_Boolean (TopOpeBRepTool_REGUW::*)(const TopoDS_Vertex &, const Standard_Integer, const TopoDS_Edge &)) &TopOpeBRepTool_REGUW::RemoveOldConnexity, "None", py::arg("v"), py::arg("OriKey"), py::arg("e"));
cls_TopOpeBRepTool_REGUW.def("UpdateMultiple", (Standard_Boolean (TopOpeBRepTool_REGUW::*)(const TopoDS_Vertex &)) &TopOpeBRepTool_REGUW::UpdateMultiple, "None", py::arg("v"));

// Enums

}