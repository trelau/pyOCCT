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
#include <SelectMgr_Filter.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <Standard_Handle.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <TopoDS_Edge.hxx>
#include <AIS_BadEdgeFilter.hxx>
#include <Standard_Type.hxx>
#include <TopTools_DataMapOfIntegerListOfShape.hxx>

void bind_AIS_BadEdgeFilter(py::module &mod){

py::class_<AIS_BadEdgeFilter, opencascade::handle<AIS_BadEdgeFilter>, SelectMgr_Filter> cls_AIS_BadEdgeFilter(mod, "AIS_BadEdgeFilter", "A Class");

// Constructors
cls_AIS_BadEdgeFilter.def(py::init<>());

// Fields

// Methods
cls_AIS_BadEdgeFilter.def("ActsOn", (Standard_Boolean (AIS_BadEdgeFilter::*)(const TopAbs_ShapeEnum) const) &AIS_BadEdgeFilter::ActsOn, "None", py::arg("aType"));
cls_AIS_BadEdgeFilter.def("IsOk", (Standard_Boolean (AIS_BadEdgeFilter::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &AIS_BadEdgeFilter::IsOk, "None", py::arg("EO"));
cls_AIS_BadEdgeFilter.def("SetContour", (void (AIS_BadEdgeFilter::*)(const Standard_Integer)) &AIS_BadEdgeFilter::SetContour, "sets <myContour> with current contour. used by IsOk.", py::arg("Index"));
cls_AIS_BadEdgeFilter.def("AddEdge", (void (AIS_BadEdgeFilter::*)(const TopoDS_Edge &, const Standard_Integer)) &AIS_BadEdgeFilter::AddEdge, "Adds an edge to the list of non-selectionnable edges.", py::arg("anEdge"), py::arg("Index"));
cls_AIS_BadEdgeFilter.def("RemoveEdges", (void (AIS_BadEdgeFilter::*)(const Standard_Integer)) &AIS_BadEdgeFilter::RemoveEdges, "removes from the list of non-selectionnable edges all edges in the contour <Index>.", py::arg("Index"));
cls_AIS_BadEdgeFilter.def_static("get_type_name_", (const char * (*)()) &AIS_BadEdgeFilter::get_type_name, "None");
cls_AIS_BadEdgeFilter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_BadEdgeFilter::get_type_descriptor, "None");
cls_AIS_BadEdgeFilter.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_BadEdgeFilter::*)() const) &AIS_BadEdgeFilter::DynamicType, "None");

// Enums

}