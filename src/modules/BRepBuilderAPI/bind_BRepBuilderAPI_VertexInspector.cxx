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
#include <gp_XY.hxx>
#include <gp_XYZ.hxx>
#include <NCollection_CellFilter.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <BRepBuilderAPI_VertexInspector.hxx>

void bind_BRepBuilderAPI_VertexInspector(py::module &mod){

py::class_<BRepBuilderAPI_VertexInspector, std::unique_ptr<BRepBuilderAPI_VertexInspector, Deleter<BRepBuilderAPI_VertexInspector>>, NCollection_CellFilter_InspectorXYZ> cls_BRepBuilderAPI_VertexInspector(mod, "BRepBuilderAPI_VertexInspector", "Class BRepBuilderAPI_VertexInspector derived from NCollection_CellFilter_InspectorXYZ This class define the Inspector interface for CellFilter algorithm, working with gp_XYZ points in 3d space. Used in search of coincidence points with a certain tolerance.");

// Constructors
cls_BRepBuilderAPI_VertexInspector.def(py::init<const Standard_Real>(), py::arg("theTol"));

// Fields

// Methods
cls_BRepBuilderAPI_VertexInspector.def("Add", (void (BRepBuilderAPI_VertexInspector::*)(const gp_XYZ &)) &BRepBuilderAPI_VertexInspector::Add, "Keep the points used for comparison", py::arg("thePnt"));
cls_BRepBuilderAPI_VertexInspector.def("ClearResList", (void (BRepBuilderAPI_VertexInspector::*)()) &BRepBuilderAPI_VertexInspector::ClearResList, "Clear the list of adjacent points");
cls_BRepBuilderAPI_VertexInspector.def("SetCurrent", (void (BRepBuilderAPI_VertexInspector::*)(const gp_XYZ &)) &BRepBuilderAPI_VertexInspector::SetCurrent, "Set current point to search for coincidence", py::arg("theCurPnt"));
cls_BRepBuilderAPI_VertexInspector.def("ResInd", (const TColStd_ListOfInteger & (BRepBuilderAPI_VertexInspector::*)()) &BRepBuilderAPI_VertexInspector::ResInd, "Get list of indexes of points adjacent with the current");
cls_BRepBuilderAPI_VertexInspector.def("Inspect", (NCollection_CellFilter_Action (BRepBuilderAPI_VertexInspector::*)(const Standard_Integer)) &BRepBuilderAPI_VertexInspector::Inspect, "Implementation of inspection method", py::arg("theTarget"));

// Enums

}