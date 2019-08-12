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
#include <Standard_Transient.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_MapOfShape.hxx>
#include <Standard_Handle.hxx>
#include <BRepTools_History.hxx>
#include <ShapeUpgrade_UnifySameDomain.hxx>
#include <Standard_Type.hxx>
#include <TopTools_IndexedDataMapOfShapeListOfShape.hxx>
#include <ShapeBuild_ReShape.hxx>

void bind_ShapeUpgrade_UnifySameDomain(py::module &mod){

py::class_<ShapeUpgrade_UnifySameDomain, opencascade::handle<ShapeUpgrade_UnifySameDomain>, Standard_Transient> cls_ShapeUpgrade_UnifySameDomain(mod, "ShapeUpgrade_UnifySameDomain", "This tool tries to unify faces and edges of the shape which lie on the same geometry. Faces/edges are considering as 'same-domain' if a group of neighbouring faces/edges are lying on coincident surfaces/curves. In this case these faces/edges can be unified into one face/edge. ShapeUpgrade_UnifySameDomain is initialized by a shape and the next optional parameters: UnifyFaces - tries to unify all possible faces UnifyEdges - tries to unify all possible edges ConcatBSplines - if this flag is set to true then all neighbouring edges, which lay on BSpline or Bezier curves with C1 continuity on their common vertices, will be merged into one common edge.");

// Constructors
cls_ShapeUpgrade_UnifySameDomain.def(py::init<>());
cls_ShapeUpgrade_UnifySameDomain.def(py::init<const TopoDS_Shape &>(), py::arg("aShape"));
cls_ShapeUpgrade_UnifySameDomain.def(py::init<const TopoDS_Shape &, const Standard_Boolean>(), py::arg("aShape"), py::arg("UnifyEdges"));
cls_ShapeUpgrade_UnifySameDomain.def(py::init<const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean>(), py::arg("aShape"), py::arg("UnifyEdges"), py::arg("UnifyFaces"));
cls_ShapeUpgrade_UnifySameDomain.def(py::init<const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("aShape"), py::arg("UnifyEdges"), py::arg("UnifyFaces"), py::arg("ConcatBSplines"));

// Fields

// Methods
cls_ShapeUpgrade_UnifySameDomain.def("Initialize", [](ShapeUpgrade_UnifySameDomain &self, const TopoDS_Shape & a0) -> void { return self.Initialize(a0); });
cls_ShapeUpgrade_UnifySameDomain.def("Initialize", [](ShapeUpgrade_UnifySameDomain &self, const TopoDS_Shape & a0, const Standard_Boolean a1) -> void { return self.Initialize(a0, a1); });
cls_ShapeUpgrade_UnifySameDomain.def("Initialize", [](ShapeUpgrade_UnifySameDomain &self, const TopoDS_Shape & a0, const Standard_Boolean a1, const Standard_Boolean a2) -> void { return self.Initialize(a0, a1, a2); });
cls_ShapeUpgrade_UnifySameDomain.def("Initialize", (void (ShapeUpgrade_UnifySameDomain::*)(const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &ShapeUpgrade_UnifySameDomain::Initialize, "Initializes with a shape and necessary flags. It does not perform unification. If you intend to nullify the History place holder do it after initialization.", py::arg("aShape"), py::arg("UnifyEdges"), py::arg("UnifyFaces"), py::arg("ConcatBSplines"));
cls_ShapeUpgrade_UnifySameDomain.def("AllowInternalEdges", (void (ShapeUpgrade_UnifySameDomain::*)(const Standard_Boolean)) &ShapeUpgrade_UnifySameDomain::AllowInternalEdges, "Sets the flag defining whether it is allowed to create internal edges inside merged faces in the case of non-manifold topology. Without this flag merging through multi connected edge is forbidden. Default value is false.", py::arg("theValue"));
cls_ShapeUpgrade_UnifySameDomain.def("KeepShape", (void (ShapeUpgrade_UnifySameDomain::*)(const TopoDS_Shape &)) &ShapeUpgrade_UnifySameDomain::KeepShape, "Sets the shape for avoid merging of the faces/edges. This shape can be vertex or edge. If the shape is a vertex it forbids merging of connected edges. If the shape is a edge it forbids merging of connected faces. This method can be called several times to keep several shapes.", py::arg("theShape"));
cls_ShapeUpgrade_UnifySameDomain.def("KeepShapes", (void (ShapeUpgrade_UnifySameDomain::*)(const TopTools_MapOfShape &)) &ShapeUpgrade_UnifySameDomain::KeepShapes, "Sets the map of shapes for avoid merging of the faces/edges. It allows passing a ready to use map instead of calling many times the method KeepShape.", py::arg("theShapes"));
cls_ShapeUpgrade_UnifySameDomain.def("SetSafeInputMode", (void (ShapeUpgrade_UnifySameDomain::*)(Standard_Boolean)) &ShapeUpgrade_UnifySameDomain::SetSafeInputMode, "Sets the flag defining the behavior of the algorithm regarding modification of input shape. If this flag is equal to True then the input (original) shape can't be modified during modification process. Default value is true.", py::arg("theValue"));
cls_ShapeUpgrade_UnifySameDomain.def("SetLinearTolerance", (void (ShapeUpgrade_UnifySameDomain::*)(const Standard_Real)) &ShapeUpgrade_UnifySameDomain::SetLinearTolerance, "Sets the linear tolerance. It plays the role of chord error when taking decision about merging of shapes. Default value is Precision::Confusion().", py::arg("theValue"));
cls_ShapeUpgrade_UnifySameDomain.def("SetAngularTolerance", (void (ShapeUpgrade_UnifySameDomain::*)(const Standard_Real)) &ShapeUpgrade_UnifySameDomain::SetAngularTolerance, "Sets the angular tolerance. If two shapes form a connection angle greater than this value they will not be merged. Default value is Precision::Angular().", py::arg("theValue"));
cls_ShapeUpgrade_UnifySameDomain.def("Build", (void (ShapeUpgrade_UnifySameDomain::*)()) &ShapeUpgrade_UnifySameDomain::Build, "Performs unification and builds the resulting shape.");
cls_ShapeUpgrade_UnifySameDomain.def("Shape", (const TopoDS_Shape & (ShapeUpgrade_UnifySameDomain::*)() const) &ShapeUpgrade_UnifySameDomain::Shape, "Gives the resulting shape");
cls_ShapeUpgrade_UnifySameDomain.def("History", (const opencascade::handle<BRepTools_History> & (ShapeUpgrade_UnifySameDomain::*)() const) &ShapeUpgrade_UnifySameDomain::History, "Returns the history of the processed shapes.");
cls_ShapeUpgrade_UnifySameDomain.def("History", (opencascade::handle<BRepTools_History> & (ShapeUpgrade_UnifySameDomain::*)()) &ShapeUpgrade_UnifySameDomain::History, "Returns the history of the processed shapes.");
cls_ShapeUpgrade_UnifySameDomain.def_static("get_type_name_", (const char * (*)()) &ShapeUpgrade_UnifySameDomain::get_type_name, "None");
cls_ShapeUpgrade_UnifySameDomain.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeUpgrade_UnifySameDomain::get_type_descriptor, "None");
cls_ShapeUpgrade_UnifySameDomain.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeUpgrade_UnifySameDomain::*)() const) &ShapeUpgrade_UnifySameDomain::DynamicType, "None");

// Enums

}