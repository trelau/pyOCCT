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
#include <Standard_Handle.hxx>
#include <NCollection_IncAllocator.hxx>
#include <BRepMesh_Circle.hxx>
#include <BRepMesh.hxx>
#include <BRepMesh_CircleInspector.hxx>

void bind_BRepMesh_CircleInspector(py::module &mod){

py::class_<BRepMesh_CircleInspector, NCollection_CellFilter_InspectorXY> cls_BRepMesh_CircleInspector(mod, "BRepMesh_CircleInspector", "Auxilary class to find circles shot by the given point.");

// Constructors
cls_BRepMesh_CircleInspector.def(py::init<const Standard_Real, const Standard_Integer, const opencascade::handle<NCollection_IncAllocator> &>(), py::arg("theTolerance"), py::arg("theReservedSize"), py::arg("theAllocator"));

// Fields

// Methods
cls_BRepMesh_CircleInspector.def("Bind", (void (BRepMesh_CircleInspector::*)(const Standard_Integer, const BRepMesh_Circle &)) &BRepMesh_CircleInspector::Bind, "Adds the circle to vector of circles at the given position.", py::arg("theIndex"), py::arg("theCircle"));
cls_BRepMesh_CircleInspector.def("Circles", (const BRepMesh::VectorOfCircle & (BRepMesh_CircleInspector::*)() const) &BRepMesh_CircleInspector::Circles, "Resutns vector of registered circles.");
cls_BRepMesh_CircleInspector.def("Circle", (BRepMesh_Circle & (BRepMesh_CircleInspector::*)(const Standard_Integer)) &BRepMesh_CircleInspector::Circle, "Returns circle with the given index.", py::arg("theIndex"));
cls_BRepMesh_CircleInspector.def("SetPoint", (void (BRepMesh_CircleInspector::*)(const gp_XY &)) &BRepMesh_CircleInspector::SetPoint, "Set reference point to be checked.", py::arg("thePoint"));
cls_BRepMesh_CircleInspector.def("GetShotCircles", (BRepMesh::ListOfInteger & (BRepMesh_CircleInspector::*)()) &BRepMesh_CircleInspector::GetShotCircles, "Returns list of circles shot by the reference point.");
cls_BRepMesh_CircleInspector.def("Inspect", (NCollection_CellFilter_Action (BRepMesh_CircleInspector::*)(const Standard_Integer)) &BRepMesh_CircleInspector::Inspect, "Performs inspection of a circle with the given index.", py::arg("theTargetIndex"));
cls_BRepMesh_CircleInspector.def_static("IsEqual_", (Standard_Boolean (*)(const Standard_Integer, const Standard_Integer)) &BRepMesh_CircleInspector::IsEqual, "Checks indices for equlity.", py::arg("theIndex"), py::arg("theTargetIndex"));

// Enums

}