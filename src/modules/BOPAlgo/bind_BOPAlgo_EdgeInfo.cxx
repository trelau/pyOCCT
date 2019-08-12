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
#include <TopoDS_Edge.hxx>
#include <Standard_TypeDef.hxx>
#include <BOPAlgo_WireSplitter.hxx>

void bind_BOPAlgo_EdgeInfo(py::module &mod){

py::class_<BOPAlgo_EdgeInfo, std::unique_ptr<BOPAlgo_EdgeInfo, Deleter<BOPAlgo_EdgeInfo>>> cls_BOPAlgo_EdgeInfo(mod, "BOPAlgo_EdgeInfo", "None");

// Constructors
cls_BOPAlgo_EdgeInfo.def(py::init<>());

// Fields

// Methods
cls_BOPAlgo_EdgeInfo.def("SetEdge", (void (BOPAlgo_EdgeInfo::*)(const TopoDS_Edge &)) &BOPAlgo_EdgeInfo::SetEdge, "None", py::arg("theE"));
cls_BOPAlgo_EdgeInfo.def("Edge", (const TopoDS_Edge & (BOPAlgo_EdgeInfo::*)() const) &BOPAlgo_EdgeInfo::Edge, "None");
cls_BOPAlgo_EdgeInfo.def("SetPassed", (void (BOPAlgo_EdgeInfo::*)(const Standard_Boolean)) &BOPAlgo_EdgeInfo::SetPassed, "None", py::arg("theFlag"));
cls_BOPAlgo_EdgeInfo.def("Passed", (Standard_Boolean (BOPAlgo_EdgeInfo::*)() const) &BOPAlgo_EdgeInfo::Passed, "None");
cls_BOPAlgo_EdgeInfo.def("SetInFlag", (void (BOPAlgo_EdgeInfo::*)(const Standard_Boolean)) &BOPAlgo_EdgeInfo::SetInFlag, "None", py::arg("theFlag"));
cls_BOPAlgo_EdgeInfo.def("IsIn", (Standard_Boolean (BOPAlgo_EdgeInfo::*)() const) &BOPAlgo_EdgeInfo::IsIn, "None");
cls_BOPAlgo_EdgeInfo.def("SetAngle", (void (BOPAlgo_EdgeInfo::*)(const Standard_Real)) &BOPAlgo_EdgeInfo::SetAngle, "None", py::arg("theAngle"));
cls_BOPAlgo_EdgeInfo.def("Angle", (Standard_Real (BOPAlgo_EdgeInfo::*)() const) &BOPAlgo_EdgeInfo::Angle, "None");

// Enums

}