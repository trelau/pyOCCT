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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TopOpeBRepDS_HDataStructure.hxx>
#include <TopoDS_Edge.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Shape.hxx>
#include <TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State.hxx>
#include <TopOpeBRepDS_TOOL.hxx>

void bind_TopOpeBRepDS_TOOL(py::module &mod){

py::class_<TopOpeBRepDS_TOOL, std::unique_ptr<TopOpeBRepDS_TOOL>> cls_TopOpeBRepDS_TOOL(mod, "TopOpeBRepDS_TOOL", "None");

// Constructors

// Fields

// Methods
// cls_TopOpeBRepDS_TOOL.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepDS_TOOL::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepDS_TOOL.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepDS_TOOL::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_TOOL.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepDS_TOOL::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepDS_TOOL.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepDS_TOOL::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepDS_TOOL.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepDS_TOOL::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepDS_TOOL.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepDS_TOOL::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepDS_TOOL.def_static("EShareG_", (Standard_Integer (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const TopoDS_Edge &, TopTools_ListOfShape &)) &TopOpeBRepDS_TOOL::EShareG, "None", py::arg("HDS"), py::arg("E"), py::arg("lEsd"));
cls_TopOpeBRepDS_TOOL.def_static("ShareG_", (Standard_Boolean (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const Standard_Integer, const Standard_Integer)) &TopOpeBRepDS_TOOL::ShareG, "None", py::arg("HDS"), py::arg("is1"), py::arg("is2"));
cls_TopOpeBRepDS_TOOL.def_static("GetEsd_", [](const opencascade::handle<TopOpeBRepDS_HDataStructure> & HDS, const TopoDS_Shape & S, const Standard_Integer ie, Standard_Integer & iesd){ Standard_Boolean rv = TopOpeBRepDS_TOOL::GetEsd(HDS, S, ie, iesd); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, iesd); }, "None", py::arg("HDS"), py::arg("S"), py::arg("ie"), py::arg("iesd"));
cls_TopOpeBRepDS_TOOL.def_static("ShareSplitON_", (Standard_Boolean (*)(const opencascade::handle<TopOpeBRepDS_HDataStructure> &, const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State &, const Standard_Integer, const Standard_Integer, TopoDS_Shape &)) &TopOpeBRepDS_TOOL::ShareSplitON, "None", py::arg("HDS"), py::arg("MspON"), py::arg("i1"), py::arg("i2"), py::arg("spON"));
cls_TopOpeBRepDS_TOOL.def_static("GetConfig_", [](const opencascade::handle<TopOpeBRepDS_HDataStructure> & HDS, const TopOpeBRepDS_DataMapOfShapeListOfShapeOn1State & MEspON, const Standard_Integer ie, const Standard_Integer iesd, Standard_Integer & conf){ Standard_Boolean rv = TopOpeBRepDS_TOOL::GetConfig(HDS, MEspON, ie, iesd, conf); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, conf); }, "None", py::arg("HDS"), py::arg("MEspON"), py::arg("ie"), py::arg("iesd"), py::arg("conf"));

// Enums

}