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
#include <BRepMesh.hxx>
#include <NCollection_UBTree.hxx>
#include <Standard_TypeDef.hxx>
#include <Bnd_Box2d.hxx>
#include <NCollection_List.hxx>
#include <TopoDS_Edge.hxx>
#include <NCollection_Sequence.hxx>
#include <BRepMesh_WireChecker.hxx>
#include <gp_Pnt2d.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_Handle.hxx>
#include <BRepMesh_DataStructureOfDelaun.hxx>
#include <BRepMesh_Status.hxx>

void bind_BRepMesh_WireChecker(py::module &mod){

py::class_<BRepMesh_WireChecker, std::unique_ptr<BRepMesh_WireChecker>> cls_BRepMesh_WireChecker(mod, "BRepMesh_WireChecker", "Auxilary class intended to check correctness of discretized face. In particular, checks boundaries of discretized face for self intersections and gaps.");

// Constructors
cls_BRepMesh_WireChecker.def(py::init<const TopoDS_Face &, const Standard_Real, const BRepMesh::HDMapOfShapePairOfPolygon &, const BRepMesh::HIMapOfInteger &, const opencascade::handle<BRepMesh_DataStructureOfDelaun> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("theFace"), py::arg("theTolUV"), py::arg("theEdges"), py::arg("theVertexMap"), py::arg("theStructure"), py::arg("theUmin"), py::arg("theUmax"), py::arg("theVmin"), py::arg("theVmax"), py::arg("isInParallel"));

// Fields

// Methods
cls_BRepMesh_WireChecker.def("ReCompute", (void (BRepMesh_WireChecker::*)(BRepMesh::HClassifier &)) &BRepMesh_WireChecker::ReCompute, "Recompute data using parameters passed in constructor.", py::arg("theClassifier"));
cls_BRepMesh_WireChecker.def("Status", (BRepMesh_Status (BRepMesh_WireChecker::*)() const) &BRepMesh_WireChecker::Status, "Returns status of the check.");

// Enums

}