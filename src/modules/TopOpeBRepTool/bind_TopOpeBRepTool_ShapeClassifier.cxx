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
#include <TopAbs_State.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopOpeBRepTool_SolidClassifier.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Pnt.hxx>
#include <TopOpeBRepTool_Plos.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <TopOpeBRepTool_ShapeClassifier.hxx>

void bind_TopOpeBRepTool_ShapeClassifier(py::module &mod){

py::class_<TopOpeBRepTool_ShapeClassifier, std::unique_ptr<TopOpeBRepTool_ShapeClassifier, Deleter<TopOpeBRepTool_ShapeClassifier>>> cls_TopOpeBRepTool_ShapeClassifier(mod, "TopOpeBRepTool_ShapeClassifier", "None");

// Constructors
cls_TopOpeBRepTool_ShapeClassifier.def(py::init<>());
cls_TopOpeBRepTool_ShapeClassifier.def(py::init<const TopoDS_Shape &>(), py::arg("SRef"));

// Fields

// Methods
// cls_TopOpeBRepTool_ShapeClassifier.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepTool_ShapeClassifier::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepTool_ShapeClassifier.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepTool_ShapeClassifier::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_ShapeClassifier.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepTool_ShapeClassifier::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepTool_ShapeClassifier.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepTool_ShapeClassifier::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepTool_ShapeClassifier.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepTool_ShapeClassifier::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepTool_ShapeClassifier.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepTool_ShapeClassifier::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepTool_ShapeClassifier.def("ClearAll", (void (TopOpeBRepTool_ShapeClassifier::*)()) &TopOpeBRepTool_ShapeClassifier::ClearAll, "reset all internal data (SolidClassifier included)");
cls_TopOpeBRepTool_ShapeClassifier.def("ClearCurrent", (void (TopOpeBRepTool_ShapeClassifier::*)()) &TopOpeBRepTool_ShapeClassifier::ClearCurrent, "reset all internal data (except SolidClassified)");
cls_TopOpeBRepTool_ShapeClassifier.def("SetReference", (void (TopOpeBRepTool_ShapeClassifier::*)(const TopoDS_Shape &)) &TopOpeBRepTool_ShapeClassifier::SetReference, "Set SRef as reference shape the next StateShapeReference(S,AvoidS) calls will classify S with SRef.", py::arg("SRef"));
cls_TopOpeBRepTool_ShapeClassifier.def("StateShapeShape", [](TopOpeBRepTool_ShapeClassifier &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1) -> TopAbs_State { return self.StateShapeShape(a0, a1); });
cls_TopOpeBRepTool_ShapeClassifier.def("StateShapeShape", (TopAbs_State (TopOpeBRepTool_ShapeClassifier::*)(const TopoDS_Shape &, const TopoDS_Shape &, const Standard_Integer)) &TopOpeBRepTool_ShapeClassifier::StateShapeShape, "classify shape S compared with shape SRef. samedomain = 0 : S1,S2 are not same domain samedomain = 1 : S1,S2 are same domain", py::arg("S"), py::arg("SRef"), py::arg("samedomain"));
cls_TopOpeBRepTool_ShapeClassifier.def("SameDomain", (Standard_Integer (TopOpeBRepTool_ShapeClassifier::*)() const) &TopOpeBRepTool_ShapeClassifier::SameDomain, "None");
cls_TopOpeBRepTool_ShapeClassifier.def("SameDomain", (void (TopOpeBRepTool_ShapeClassifier::*)(const Standard_Integer)) &TopOpeBRepTool_ShapeClassifier::SameDomain, "set mode for next StateShapeShape call samedomain = true --> S,Sref are same domain --> point on restriction (ON S) is used to classify S. samedomain = false --> S,Sref are not domain --> point not on restriction of S (IN S) is used to classify S. samedomain value is used only in next StateShapeShape call", py::arg("samedomain"));
cls_TopOpeBRepTool_ShapeClassifier.def("StateShapeShape", (TopAbs_State (TopOpeBRepTool_ShapeClassifier::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepTool_ShapeClassifier::StateShapeShape, "classify shape S compared with shape SRef. AvoidS is not used in classification; AvoidS may be IsNull(). (usefull to avoid ON or UNKNOWN state in special cases)", py::arg("S"), py::arg("AvoidS"), py::arg("SRef"));
cls_TopOpeBRepTool_ShapeClassifier.def("StateShapeShape", (TopAbs_State (TopOpeBRepTool_ShapeClassifier::*)(const TopoDS_Shape &, const TopTools_ListOfShape &, const TopoDS_Shape &)) &TopOpeBRepTool_ShapeClassifier::StateShapeShape, "classify shape S compared with shape SRef. LAvoidS is list of S subshapes to avoid in classification AvoidS is not used in classification; AvoidS may be IsNull(). (usefull to avoid ON or UNKNOWN state in special cases)", py::arg("S"), py::arg("LAvoidS"), py::arg("SRef"));
cls_TopOpeBRepTool_ShapeClassifier.def("StateShapeReference", (TopAbs_State (TopOpeBRepTool_ShapeClassifier::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &TopOpeBRepTool_ShapeClassifier::StateShapeReference, "classify shape S compared with reference shape. AvoidS is not used in classification; AvoidS may be IsNull(). (usefull to avoid ON or UNKNOWN state in special cases)", py::arg("S"), py::arg("AvoidS"));
cls_TopOpeBRepTool_ShapeClassifier.def("StateShapeReference", (TopAbs_State (TopOpeBRepTool_ShapeClassifier::*)(const TopoDS_Shape &, const TopTools_ListOfShape &)) &TopOpeBRepTool_ShapeClassifier::StateShapeReference, "classify shape S compared with reference shape. LAvoidS is list of S subshapes to avoid in classification (usefull to avoid ON or UNKNOWN state in special cases)", py::arg("S"), py::arg("LAvoidS"));
cls_TopOpeBRepTool_ShapeClassifier.def("ChangeSolidClassifier", (TopOpeBRepTool_SolidClassifier & (TopOpeBRepTool_ShapeClassifier::*)()) &TopOpeBRepTool_ShapeClassifier::ChangeSolidClassifier, "None");
cls_TopOpeBRepTool_ShapeClassifier.def("StateP2DReference", (void (TopOpeBRepTool_ShapeClassifier::*)(const gp_Pnt2d &)) &TopOpeBRepTool_ShapeClassifier::StateP2DReference, "classify point P2D with myRef", py::arg("P2D"));
cls_TopOpeBRepTool_ShapeClassifier.def("StateP3DReference", (void (TopOpeBRepTool_ShapeClassifier::*)(const gp_Pnt &)) &TopOpeBRepTool_ShapeClassifier::StateP3DReference, "classify point P3D with myRef", py::arg("P3D"));
cls_TopOpeBRepTool_ShapeClassifier.def("State", (TopAbs_State (TopOpeBRepTool_ShapeClassifier::*)() const) &TopOpeBRepTool_ShapeClassifier::State, "return field myState");
cls_TopOpeBRepTool_ShapeClassifier.def("P2D", (const gp_Pnt2d & (TopOpeBRepTool_ShapeClassifier::*)() const) &TopOpeBRepTool_ShapeClassifier::P2D, "None");
cls_TopOpeBRepTool_ShapeClassifier.def("P3D", (const gp_Pnt & (TopOpeBRepTool_ShapeClassifier::*)() const) &TopOpeBRepTool_ShapeClassifier::P3D, "None");

// Enums

}