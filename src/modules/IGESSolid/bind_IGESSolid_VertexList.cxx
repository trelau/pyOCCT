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
#include <TColgp_HArray1OfXYZ.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <IGESSolid_VertexList.hxx>
#include <Standard_Type.hxx>

void bind_IGESSolid_VertexList(py::module &mod){

py::class_<IGESSolid_VertexList, opencascade::handle<IGESSolid_VertexList>, IGESData_IGESEntity> cls_IGESSolid_VertexList(mod, "IGESSolid_VertexList", "defines VertexList, Type <502> Form Number <1> in package IGESSolid A vertex is a point in R3. A vertex is the bound of an edge and can participate in the bounds of a face. It contains one or more vertices.");

// Constructors
cls_IGESSolid_VertexList.def(py::init<>());

// Fields

// Methods
cls_IGESSolid_VertexList.def("Init", (void (IGESSolid_VertexList::*)(const opencascade::handle<TColgp_HArray1OfXYZ> &)) &IGESSolid_VertexList::Init, "This method is used to set the fields of the class VertexList - vertices : the vertices in the list", py::arg("vertices"));
cls_IGESSolid_VertexList.def("NbVertices", (Standard_Integer (IGESSolid_VertexList::*)() const) &IGESSolid_VertexList::NbVertices, "return the number of vertices in the list");
cls_IGESSolid_VertexList.def("Vertex", (gp_Pnt (IGESSolid_VertexList::*)(const Standard_Integer) const) &IGESSolid_VertexList::Vertex, "returns the num'th vertex in the list raises exception if num <= 0 or num > NbVertices()", py::arg("num"));
cls_IGESSolid_VertexList.def_static("get_type_name_", (const char * (*)()) &IGESSolid_VertexList::get_type_name, "None");
cls_IGESSolid_VertexList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESSolid_VertexList::get_type_descriptor, "None");
cls_IGESSolid_VertexList.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESSolid_VertexList::*)() const) &IGESSolid_VertexList::DynamicType, "None");

// Enums

}