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
#include <TopoDS_Vertex.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <TopTools_IndexedMapOfOrientedShape.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopOpeBRepBuild_VertexInfo.hxx>

void bind_TopOpeBRepBuild_VertexInfo(py::module &mod){

py::class_<TopOpeBRepBuild_VertexInfo> cls_TopOpeBRepBuild_VertexInfo(mod, "TopOpeBRepBuild_VertexInfo", "None");

// Constructors
cls_TopOpeBRepBuild_VertexInfo.def(py::init<>());

// Fields

// Methods
// cls_TopOpeBRepBuild_VertexInfo.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_VertexInfo::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_VertexInfo.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_VertexInfo::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_VertexInfo.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_VertexInfo::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_VertexInfo.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_VertexInfo::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_VertexInfo.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_VertexInfo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_VertexInfo.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_VertexInfo::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_VertexInfo.def("SetVertex", (void (TopOpeBRepBuild_VertexInfo::*)(const TopoDS_Vertex &)) &TopOpeBRepBuild_VertexInfo::SetVertex, "None", py::arg("aV"));
cls_TopOpeBRepBuild_VertexInfo.def("Vertex", (const TopoDS_Vertex & (TopOpeBRepBuild_VertexInfo::*)() const) &TopOpeBRepBuild_VertexInfo::Vertex, "None");
cls_TopOpeBRepBuild_VertexInfo.def("SetSmart", (void (TopOpeBRepBuild_VertexInfo::*)(const Standard_Boolean)) &TopOpeBRepBuild_VertexInfo::SetSmart, "None", py::arg("aFlag"));
cls_TopOpeBRepBuild_VertexInfo.def("Smart", (Standard_Boolean (TopOpeBRepBuild_VertexInfo::*)() const) &TopOpeBRepBuild_VertexInfo::Smart, "None");
cls_TopOpeBRepBuild_VertexInfo.def("NbCases", (Standard_Integer (TopOpeBRepBuild_VertexInfo::*)() const) &TopOpeBRepBuild_VertexInfo::NbCases, "None");
cls_TopOpeBRepBuild_VertexInfo.def("FoundOut", (Standard_Integer (TopOpeBRepBuild_VertexInfo::*)() const) &TopOpeBRepBuild_VertexInfo::FoundOut, "None");
cls_TopOpeBRepBuild_VertexInfo.def("AddIn", (void (TopOpeBRepBuild_VertexInfo::*)(const TopoDS_Edge &)) &TopOpeBRepBuild_VertexInfo::AddIn, "None", py::arg("anE"));
cls_TopOpeBRepBuild_VertexInfo.def("AddOut", (void (TopOpeBRepBuild_VertexInfo::*)(const TopoDS_Edge &)) &TopOpeBRepBuild_VertexInfo::AddOut, "None", py::arg("anE"));
cls_TopOpeBRepBuild_VertexInfo.def("SetCurrentIn", (void (TopOpeBRepBuild_VertexInfo::*)(const TopoDS_Edge &)) &TopOpeBRepBuild_VertexInfo::SetCurrentIn, "None", py::arg("anE"));
cls_TopOpeBRepBuild_VertexInfo.def("EdgesIn", (const TopTools_IndexedMapOfOrientedShape & (TopOpeBRepBuild_VertexInfo::*)() const) &TopOpeBRepBuild_VertexInfo::EdgesIn, "None");
cls_TopOpeBRepBuild_VertexInfo.def("EdgesOut", (const TopTools_IndexedMapOfOrientedShape & (TopOpeBRepBuild_VertexInfo::*)() const) &TopOpeBRepBuild_VertexInfo::EdgesOut, "None");
cls_TopOpeBRepBuild_VertexInfo.def("ChangeEdgesOut", (TopTools_IndexedMapOfOrientedShape & (TopOpeBRepBuild_VertexInfo::*)()) &TopOpeBRepBuild_VertexInfo::ChangeEdgesOut, "None");
cls_TopOpeBRepBuild_VertexInfo.def("Dump", (void (TopOpeBRepBuild_VertexInfo::*)() const) &TopOpeBRepBuild_VertexInfo::Dump, "None");
cls_TopOpeBRepBuild_VertexInfo.def("CurrentOut", (const TopoDS_Edge & (TopOpeBRepBuild_VertexInfo::*)()) &TopOpeBRepBuild_VertexInfo::CurrentOut, "None");
cls_TopOpeBRepBuild_VertexInfo.def("AppendPassed", (void (TopOpeBRepBuild_VertexInfo::*)(const TopoDS_Edge &)) &TopOpeBRepBuild_VertexInfo::AppendPassed, "None", py::arg("anE"));
cls_TopOpeBRepBuild_VertexInfo.def("RemovePassed", (void (TopOpeBRepBuild_VertexInfo::*)()) &TopOpeBRepBuild_VertexInfo::RemovePassed, "None");
cls_TopOpeBRepBuild_VertexInfo.def("ListPassed", (const TopTools_ListOfShape & (TopOpeBRepBuild_VertexInfo::*)() const) &TopOpeBRepBuild_VertexInfo::ListPassed, "None");
cls_TopOpeBRepBuild_VertexInfo.def("Prepare", (void (TopOpeBRepBuild_VertexInfo::*)(const TopTools_ListOfShape &)) &TopOpeBRepBuild_VertexInfo::Prepare, "None", py::arg("aL"));

// Enums

}