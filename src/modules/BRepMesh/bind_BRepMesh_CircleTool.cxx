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
#include <Standard_Handle.hxx>
#include <NCollection_IncAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <Precision.hxx>
#include <NCollection_Array1.hxx>
#include <gp_XY.hxx>
#include <gp_Circ2d.hxx>
#include <BRepMesh.hxx>
#include <BRepMesh_CircleInspector.hxx>
#include <BRepMesh_CircleTool.hxx>

void bind_BRepMesh_CircleTool(py::module &mod){

py::class_<BRepMesh_CircleTool> cls_BRepMesh_CircleTool(mod, "BRepMesh_CircleTool", "Create sort and destroy the circles used in triangulation.");

// Constructors
cls_BRepMesh_CircleTool.def(py::init<const opencascade::handle<NCollection_IncAllocator> &>(), py::arg("theAllocator"));
cls_BRepMesh_CircleTool.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_IncAllocator> &>(), py::arg("theReservedSize"), py::arg("theAllocator"));

// Fields

// Methods
// cls_BRepMesh_CircleTool.def_static("operator new_", (void * (*)(size_t)) &BRepMesh_CircleTool::operator new, "None", py::arg("theSize"));
// cls_BRepMesh_CircleTool.def_static("operator delete_", (void (*)(void *)) &BRepMesh_CircleTool::operator delete, "None", py::arg("theAddress"));
// cls_BRepMesh_CircleTool.def_static("operator new[]_", (void * (*)(size_t)) &BRepMesh_CircleTool::operator new[], "None", py::arg("theSize"));
// cls_BRepMesh_CircleTool.def_static("operator delete[]_", (void (*)(void *)) &BRepMesh_CircleTool::operator delete[], "None", py::arg("theAddress"));
// cls_BRepMesh_CircleTool.def_static("operator new_", (void * (*)(size_t, void *)) &BRepMesh_CircleTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepMesh_CircleTool.def_static("operator delete_", (void (*)(void *, void *)) &BRepMesh_CircleTool::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepMesh_CircleTool.def("Init", (void (BRepMesh_CircleTool::*)(const Standard_Integer)) &BRepMesh_CircleTool::Init, "Initializes the tool.", py::arg(""));
cls_BRepMesh_CircleTool.def("SetCellSize", (void (BRepMesh_CircleTool::*)(const Standard_Real)) &BRepMesh_CircleTool::SetCellSize, "Sets new size for cell filter.", py::arg("theSize"));
cls_BRepMesh_CircleTool.def("SetCellSize", (void (BRepMesh_CircleTool::*)(const Standard_Real, const Standard_Real)) &BRepMesh_CircleTool::SetCellSize, "Sets new size for cell filter.", py::arg("theSizeX"), py::arg("theSizeY"));
cls_BRepMesh_CircleTool.def("SetMinMaxSize", (void (BRepMesh_CircleTool::*)(const gp_XY &, const gp_XY &)) &BRepMesh_CircleTool::SetMinMaxSize, "Sets limits of inspection area.", py::arg("theMin"), py::arg("theMax"));
cls_BRepMesh_CircleTool.def("Bind", (void (BRepMesh_CircleTool::*)(const Standard_Integer, const gp_Circ2d &)) &BRepMesh_CircleTool::Bind, "Binds the circle to the tool.", py::arg("theIndex"), py::arg("theCircle"));
cls_BRepMesh_CircleTool.def_static("MakeCircle_", [](const gp_XY & thePoint1, const gp_XY & thePoint2, const gp_XY & thePoint3, gp_XY & theLocation, Standard_Real & theRadius){ Standard_Boolean rv = BRepMesh_CircleTool::MakeCircle(thePoint1, thePoint2, thePoint3, theLocation, theRadius); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theRadius); }, "Computes circle on three points.", py::arg("thePoint1"), py::arg("thePoint2"), py::arg("thePoint3"), py::arg("theLocation"), py::arg("theRadius"));
cls_BRepMesh_CircleTool.def("Bind", (Standard_Boolean (BRepMesh_CircleTool::*)(const Standard_Integer, const gp_XY &, const gp_XY &, const gp_XY &)) &BRepMesh_CircleTool::Bind, "Computes circle on three points and bind it to the tool.", py::arg("theIndex"), py::arg("thePoint1"), py::arg("thePoint2"), py::arg("thePoint3"));
cls_BRepMesh_CircleTool.def("MocBind", (void (BRepMesh_CircleTool::*)(const Standard_Integer)) &BRepMesh_CircleTool::MocBind, "Binds implicit zero circle.", py::arg("theIndex"));
cls_BRepMesh_CircleTool.def("Delete", (void (BRepMesh_CircleTool::*)(const Standard_Integer)) &BRepMesh_CircleTool::Delete, "Deletes a circle from the tool.", py::arg("theIndex"));
cls_BRepMesh_CircleTool.def("Select", (BRepMesh::ListOfInteger & (BRepMesh_CircleTool::*)(const gp_XY &)) &BRepMesh_CircleTool::Select, "Select the circles shot by the given point.", py::arg("thePoint"));

// Enums

}