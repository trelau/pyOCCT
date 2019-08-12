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
#include <TopoDS_AlertWithShape.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <BOPAlgo_Alerts.hxx>
#include <Standard_Type.hxx>

void bind_BOPAlgo_AlertRemovalOfIBForEdgesFailed(py::module &mod){

py::class_<BOPAlgo_AlertRemovalOfIBForEdgesFailed, opencascade::handle<BOPAlgo_AlertRemovalOfIBForEdgesFailed>, TopoDS_AlertWithShape> cls_BOPAlgo_AlertRemovalOfIBForEdgesFailed(mod, "BOPAlgo_AlertRemovalOfIBForEdgesFailed", "Removal of internal boundaries among Edges has failed");

// Constructors
cls_BOPAlgo_AlertRemovalOfIBForEdgesFailed.def(py::init<const TopoDS_Shape &>(), py::arg("theShape"));

// Fields

// Methods
cls_BOPAlgo_AlertRemovalOfIBForEdgesFailed.def_static("get_type_name_", (const char * (*)()) &BOPAlgo_AlertRemovalOfIBForEdgesFailed::get_type_name, "None");
cls_BOPAlgo_AlertRemovalOfIBForEdgesFailed.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &BOPAlgo_AlertRemovalOfIBForEdgesFailed::get_type_descriptor, "None");
cls_BOPAlgo_AlertRemovalOfIBForEdgesFailed.def("DynamicType", (const opencascade::handle<Standard_Type> & (BOPAlgo_AlertRemovalOfIBForEdgesFailed::*)() const) &BOPAlgo_AlertRemovalOfIBForEdgesFailed::DynamicType, "None");

// Enums

}