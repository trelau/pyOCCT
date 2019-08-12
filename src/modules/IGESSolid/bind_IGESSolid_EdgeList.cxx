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
#include <IGESData_IGESEntity.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <IGESSolid_HArray1OfVertexList.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESSolid_VertexList.hxx>
#include <IGESSolid_EdgeList.hxx>
#include <Standard_Type.hxx>

void bind_IGESSolid_EdgeList(py::module &mod){

py::class_<IGESSolid_EdgeList, opencascade::handle<IGESSolid_EdgeList>, IGESData_IGESEntity> cls_IGESSolid_EdgeList(mod, "IGESSolid_EdgeList", "defines EdgeList, Type <504> Form <1> in package IGESSolid EdgeList is defined as a segment joining two vertices It contains one or more edge tuples.");

// Constructors
cls_IGESSolid_EdgeList.def(py::init<>());

// Fields

// Methods
cls_IGESSolid_EdgeList.def("Init", (void (IGESSolid_EdgeList::*)(const opencascade::handle<IGESData_HArray1OfIGESEntity> &, const opencascade::handle<IGESSolid_HArray1OfVertexList> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<IGESSolid_HArray1OfVertexList> &, const opencascade::handle<TColStd_HArray1OfInteger> &)) &IGESSolid_EdgeList::Init, "This method is used to set the fields of the class EdgeList - curves : the model space curves - startVertexList : the vertex list that contains the start vertices - startVertexIndex : the index of the vertex in the corresponding vertex list - endVertexList : the vertex list that contains the end vertices - endVertexIndex : the index of the vertex in the corresponding vertex list raises exception if size of curves,startVertexList,startVertexIndex, endVertexList and endVertexIndex do no match", py::arg("curves"), py::arg("startVertexList"), py::arg("startVertexIndex"), py::arg("endVertexList"), py::arg("endVertexIndex"));
cls_IGESSolid_EdgeList.def("NbEdges", (Standard_Integer (IGESSolid_EdgeList::*)() const) &IGESSolid_EdgeList::NbEdges, "returns the number of edges in the edge list");
cls_IGESSolid_EdgeList.def("Curve", (opencascade::handle<IGESData_IGESEntity> (IGESSolid_EdgeList::*)(const Standard_Integer) const) &IGESSolid_EdgeList::Curve, "returns the num'th model space curve raises Exception if num <= 0 or num > NbEdges()", py::arg("num"));
cls_IGESSolid_EdgeList.def("StartVertexList", (opencascade::handle<IGESSolid_VertexList> (IGESSolid_EdgeList::*)(const Standard_Integer) const) &IGESSolid_EdgeList::StartVertexList, "returns the num'th start vertex list raises Exception if num <= 0 or num > NbEdges()", py::arg("num"));
cls_IGESSolid_EdgeList.def("StartVertexIndex", (Standard_Integer (IGESSolid_EdgeList::*)(const Standard_Integer) const) &IGESSolid_EdgeList::StartVertexIndex, "returns the index of num'th start vertex in the corresponding start vertex list raises Exception if num <= 0 or num > NbEdges()", py::arg("num"));
cls_IGESSolid_EdgeList.def("EndVertexList", (opencascade::handle<IGESSolid_VertexList> (IGESSolid_EdgeList::*)(const Standard_Integer) const) &IGESSolid_EdgeList::EndVertexList, "returns the num'th end vertex list raises Exception if num <= 0 or num > NbEdges()", py::arg("num"));
cls_IGESSolid_EdgeList.def("EndVertexIndex", (Standard_Integer (IGESSolid_EdgeList::*)(const Standard_Integer) const) &IGESSolid_EdgeList::EndVertexIndex, "returns the index of num'th end vertex in the corresponding end vertex list raises Exception if num <= 0 or num > NbEdges()", py::arg("num"));
cls_IGESSolid_EdgeList.def_static("get_type_name_", (const char * (*)()) &IGESSolid_EdgeList::get_type_name, "None");
cls_IGESSolid_EdgeList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_EdgeList::get_type_descriptor, "None");
cls_IGESSolid_EdgeList.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_EdgeList::*)() const) &IGESSolid_EdgeList::DynamicType, "None");

// Enums

}