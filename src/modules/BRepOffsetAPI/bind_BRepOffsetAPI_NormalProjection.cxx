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
#include <BRepBuilderAPI_MakeShape.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <TopoDS_Edge.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BRepAlgo_NormalProjection.hxx>
#include <BRepOffsetAPI_NormalProjection.hxx>

void bind_BRepOffsetAPI_NormalProjection(py::module &mod){

py::class_<BRepOffsetAPI_NormalProjection, std::unique_ptr<BRepOffsetAPI_NormalProjection>, BRepBuilderAPI_MakeShape> cls_BRepOffsetAPI_NormalProjection(mod, "BRepOffsetAPI_NormalProjection", "A framework to define projection onto a shape according to the normal from each point to be projected. The target shape is a face, and the source shape is an edge or a wire.");

// Constructors
cls_BRepOffsetAPI_NormalProjection.def(py::init<>());
cls_BRepOffsetAPI_NormalProjection.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Fields

// Methods
// cls_BRepOffsetAPI_NormalProjection.def_static("operator new_", (void * (*)(size_t)) &BRepOffsetAPI_NormalProjection::operator new, "None", py::arg("theSize"));
// cls_BRepOffsetAPI_NormalProjection.def_static("operator delete_", (void (*)(void *)) &BRepOffsetAPI_NormalProjection::operator delete, "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_NormalProjection.def_static("operator new[]_", (void * (*)(size_t)) &BRepOffsetAPI_NormalProjection::operator new[], "None", py::arg("theSize"));
// cls_BRepOffsetAPI_NormalProjection.def_static("operator delete[]_", (void (*)(void *)) &BRepOffsetAPI_NormalProjection::operator delete[], "None", py::arg("theAddress"));
// cls_BRepOffsetAPI_NormalProjection.def_static("operator new_", (void * (*)(size_t, void *)) &BRepOffsetAPI_NormalProjection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepOffsetAPI_NormalProjection.def_static("operator delete_", (void (*)(void *, void *)) &BRepOffsetAPI_NormalProjection::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepOffsetAPI_NormalProjection.def("Init", (void (BRepOffsetAPI_NormalProjection::*)(const TopoDS_Shape &)) &BRepOffsetAPI_NormalProjection::Init, "Initializes the empty constructor framework with the shape S.", py::arg("S"));
cls_BRepOffsetAPI_NormalProjection.def("Add", (void (BRepOffsetAPI_NormalProjection::*)(const TopoDS_Shape &)) &BRepOffsetAPI_NormalProjection::Add, "Adds the shape ToProj to the framework for calculation of the projection by Compute3d. ToProj is an edge or a wire and will be projected onto the basis shape. Exceptions Standard_ConstructionError if ToProj is not added.", py::arg("ToProj"));
cls_BRepOffsetAPI_NormalProjection.def("SetParams", (void (BRepOffsetAPI_NormalProjection::*)(const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer)) &BRepOffsetAPI_NormalProjection::SetParams, "Sets the parameters used for computation Tol3 is the requiered tolerance between the 3d projected curve and its 2d representation InternalContinuity is the order of constraints used for approximation MaxDeg and MaxSeg are the maximum degree and the maximum number of segment for BSpline resulting of an approximation.", py::arg("Tol3D"), py::arg("Tol2D"), py::arg("InternalContinuity"), py::arg("MaxDegree"), py::arg("MaxSeg"));
cls_BRepOffsetAPI_NormalProjection.def("SetMaxDistance", (void (BRepOffsetAPI_NormalProjection::*)(const Standard_Real)) &BRepOffsetAPI_NormalProjection::SetMaxDistance, "Sets the maximum distance between target shape and shape to project. If this condition is not satisfied then corresponding part of solution is discarded. if MaxDist < 0 then this method does not affect the algorithm", py::arg("MaxDist"));
cls_BRepOffsetAPI_NormalProjection.def("SetLimit", [](BRepOffsetAPI_NormalProjection &self) -> void { return self.SetLimit(); });
cls_BRepOffsetAPI_NormalProjection.def("SetLimit", (void (BRepOffsetAPI_NormalProjection::*)(const Standard_Boolean)) &BRepOffsetAPI_NormalProjection::SetLimit, "Manage limitation of projected edges.", py::arg("FaceBoundaries"));
cls_BRepOffsetAPI_NormalProjection.def("Compute3d", [](BRepOffsetAPI_NormalProjection &self) -> void { return self.Compute3d(); });
cls_BRepOffsetAPI_NormalProjection.def("Compute3d", (void (BRepOffsetAPI_NormalProjection::*)(const Standard_Boolean)) &BRepOffsetAPI_NormalProjection::Compute3d, "Returns true if a 3D curve is computed. If not, false is returned and an initial 3D curve is kept to build the resulting edges.", py::arg("With3d"));
cls_BRepOffsetAPI_NormalProjection.def("Build", (void (BRepOffsetAPI_NormalProjection::*)()) &BRepOffsetAPI_NormalProjection::Build, "Builds the result of the projection as a compound of wires. Tries to build oriented wires.");
cls_BRepOffsetAPI_NormalProjection.def("IsDone", (Standard_Boolean (BRepOffsetAPI_NormalProjection::*)() const) &BRepOffsetAPI_NormalProjection::IsDone, "Returns true if the object was correctly built by the shape construction algorithm. If at the construction time of the shape, the algorithm cannot be completed, or the original data is corrupted, IsDone returns false and therefore protects the use of functions to access the result of the construction (typically the Shape function).");
cls_BRepOffsetAPI_NormalProjection.def("Projection", (const TopoDS_Shape & (BRepOffsetAPI_NormalProjection::*)() const) &BRepOffsetAPI_NormalProjection::Projection, "Performs the projection. The construction of the result is performed by Build. Exceptions StdFail_NotDone if the projection was not performed.");
cls_BRepOffsetAPI_NormalProjection.def("Couple", (const TopoDS_Shape & (BRepOffsetAPI_NormalProjection::*)(const TopoDS_Edge &) const) &BRepOffsetAPI_NormalProjection::Couple, "Returns the initial face corresponding to the projected edge E. Exceptions StdFail_NotDone if no face was found. Standard_NoSuchObject if if a face corresponding to E has already been found.", py::arg("E"));
cls_BRepOffsetAPI_NormalProjection.def("Generated", (const TopTools_ListOfShape & (BRepOffsetAPI_NormalProjection::*)(const TopoDS_Shape &)) &BRepOffsetAPI_NormalProjection::Generated, "Returns the list of shapes generated from the shape <S>.", py::arg("S"));
cls_BRepOffsetAPI_NormalProjection.def("Ancestor", (const TopoDS_Shape & (BRepOffsetAPI_NormalProjection::*)(const TopoDS_Edge &) const) &BRepOffsetAPI_NormalProjection::Ancestor, "Returns the initial edge corresponding to the edge E resulting from the computation of the projection. Exceptions StdFail_NotDone if no edge was found. Standard_NoSuchObject if an edge corresponding to E has already been found.", py::arg("E"));
cls_BRepOffsetAPI_NormalProjection.def("BuildWire", (Standard_Boolean (BRepOffsetAPI_NormalProjection::*)(TopTools_ListOfShape &) const) &BRepOffsetAPI_NormalProjection::BuildWire, "build the result as a list of wire if possible in -- a first returns a wire only if there is only a wire.", py::arg("Liste"));

// Enums

}