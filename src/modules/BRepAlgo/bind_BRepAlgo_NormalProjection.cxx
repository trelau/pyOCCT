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
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <TopoDS_Edge.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Adaptor3d_Curve.hxx>
#include <TopTools_DataMapOfShapeShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <BRepAlgo_NormalProjection.hxx>

void bind_BRepAlgo_NormalProjection(py::module &mod){

py::class_<BRepAlgo_NormalProjection> cls_BRepAlgo_NormalProjection(mod, "BRepAlgo_NormalProjection", "This class makes the projection of a wire on a shape.");

// Constructors
cls_BRepAlgo_NormalProjection.def(py::init<>());
cls_BRepAlgo_NormalProjection.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Fields

// Methods
// cls_BRepAlgo_NormalProjection.def_static("operator new_", (void * (*)(size_t)) &BRepAlgo_NormalProjection::operator new, "None", py::arg("theSize"));
// cls_BRepAlgo_NormalProjection.def_static("operator delete_", (void (*)(void *)) &BRepAlgo_NormalProjection::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgo_NormalProjection.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgo_NormalProjection::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgo_NormalProjection.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgo_NormalProjection::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgo_NormalProjection.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgo_NormalProjection::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgo_NormalProjection.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgo_NormalProjection::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepAlgo_NormalProjection.def("Init", (void (BRepAlgo_NormalProjection::*)(const TopoDS_Shape &)) &BRepAlgo_NormalProjection::Init, "None", py::arg("S"));
cls_BRepAlgo_NormalProjection.def("Add", (void (BRepAlgo_NormalProjection::*)(const TopoDS_Shape &)) &BRepAlgo_NormalProjection::Add, "Add an edge or a wire to the list of shape to project", py::arg("ToProj"));
cls_BRepAlgo_NormalProjection.def("SetParams", (void (BRepAlgo_NormalProjection::*)(const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer)) &BRepAlgo_NormalProjection::SetParams, "Set the parameters used for computation Tol3d is the requiered tolerance between the 3d projected curve and its 2d representation InternalContinuity is the order of constraints used for approximation. MaxDeg and MaxSeg are the maximum degree and the maximum number of segment for BSpline resulting of an approximation.", py::arg("Tol3D"), py::arg("Tol2D"), py::arg("InternalContinuity"), py::arg("MaxDegree"), py::arg("MaxSeg"));
cls_BRepAlgo_NormalProjection.def("SetDefaultParams", (void (BRepAlgo_NormalProjection::*)()) &BRepAlgo_NormalProjection::SetDefaultParams, "Set the parameters used for computation in their default values");
cls_BRepAlgo_NormalProjection.def("SetMaxDistance", (void (BRepAlgo_NormalProjection::*)(const Standard_Real)) &BRepAlgo_NormalProjection::SetMaxDistance, "Sets the maximum distance between target shape and shape to project. If this condition is not satisfied then corresponding part of solution is discarded. if MaxDist < 0 then this method does not affect the algorithm", py::arg("MaxDist"));
cls_BRepAlgo_NormalProjection.def("Compute3d", [](BRepAlgo_NormalProjection &self) -> void { return self.Compute3d(); });
cls_BRepAlgo_NormalProjection.def("Compute3d", (void (BRepAlgo_NormalProjection::*)(const Standard_Boolean)) &BRepAlgo_NormalProjection::Compute3d, "if With3d = Standard_False the 3dcurve is not computed the initial 3dcurve is kept to build the resulting edges.", py::arg("With3d"));
cls_BRepAlgo_NormalProjection.def("SetLimit", [](BRepAlgo_NormalProjection &self) -> void { return self.SetLimit(); });
cls_BRepAlgo_NormalProjection.def("SetLimit", (void (BRepAlgo_NormalProjection::*)(const Standard_Boolean)) &BRepAlgo_NormalProjection::SetLimit, "Manage limitation of projected edges.", py::arg("FaceBoundaries"));
cls_BRepAlgo_NormalProjection.def("Build", (void (BRepAlgo_NormalProjection::*)()) &BRepAlgo_NormalProjection::Build, "Builds the result as a compound.");
cls_BRepAlgo_NormalProjection.def("IsDone", (Standard_Boolean (BRepAlgo_NormalProjection::*)() const) &BRepAlgo_NormalProjection::IsDone, "None");
cls_BRepAlgo_NormalProjection.def("Projection", (const TopoDS_Shape & (BRepAlgo_NormalProjection::*)() const) &BRepAlgo_NormalProjection::Projection, "returns the result");
cls_BRepAlgo_NormalProjection.def("Ancestor", (const TopoDS_Shape & (BRepAlgo_NormalProjection::*)(const TopoDS_Edge &) const) &BRepAlgo_NormalProjection::Ancestor, "For a resulting edge, returns the corresponding initial edge.", py::arg("E"));
cls_BRepAlgo_NormalProjection.def("Couple", (const TopoDS_Shape & (BRepAlgo_NormalProjection::*)(const TopoDS_Edge &) const) &BRepAlgo_NormalProjection::Couple, "For a projected edge, returns the corresponding initial face.", py::arg("E"));
cls_BRepAlgo_NormalProjection.def("Generated", (const TopTools_ListOfShape & (BRepAlgo_NormalProjection::*)(const TopoDS_Shape &)) &BRepAlgo_NormalProjection::Generated, "Returns the list of shapes generated from the shape <S>.", py::arg("S"));
cls_BRepAlgo_NormalProjection.def("IsElementary", (Standard_Boolean (BRepAlgo_NormalProjection::*)(const Adaptor3d_Curve &) const) &BRepAlgo_NormalProjection::IsElementary, "None", py::arg("C"));
cls_BRepAlgo_NormalProjection.def("BuildWire", (Standard_Boolean (BRepAlgo_NormalProjection::*)(TopTools_ListOfShape &) const) &BRepAlgo_NormalProjection::BuildWire, "build the result as a list of wire if possible in -- a first returns a wire only if there is only a wire.", py::arg("Liste"));

// Enums

}