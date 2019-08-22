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
#include <TopoDS_Face.hxx>
#include <TopTools_IndexedMapOfOrientedShape.hxx>
#include <TopTools_IndexedDataMapOfShapeShape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <gp_Pnt2d.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopoDS_Shape.hxx>
#include <gp_Vec2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <TopoDS_Wire.hxx>
#include <Bnd_Box2d.hxx>
#include <TopOpeBRepBuild_CorrectFace2d.hxx>

void bind_TopOpeBRepBuild_CorrectFace2d(py::module &mod){

py::class_<TopOpeBRepBuild_CorrectFace2d> cls_TopOpeBRepBuild_CorrectFace2d(mod, "TopOpeBRepBuild_CorrectFace2d", "None");

// Constructors
cls_TopOpeBRepBuild_CorrectFace2d.def(py::init<>());
cls_TopOpeBRepBuild_CorrectFace2d.def(py::init<const TopoDS_Face &, const TopTools_IndexedMapOfOrientedShape &, TopTools_IndexedDataMapOfShapeShape &>(), py::arg("aFace"), py::arg("anAvoidMap"), py::arg("aMap"));

// Fields

// Methods
// cls_TopOpeBRepBuild_CorrectFace2d.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRepBuild_CorrectFace2d::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_CorrectFace2d.def_static("operator delete_", (void (*)(void *)) &TopOpeBRepBuild_CorrectFace2d::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_CorrectFace2d.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRepBuild_CorrectFace2d::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRepBuild_CorrectFace2d.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRepBuild_CorrectFace2d::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRepBuild_CorrectFace2d.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRepBuild_CorrectFace2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRepBuild_CorrectFace2d.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRepBuild_CorrectFace2d::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRepBuild_CorrectFace2d.def("Face", (const TopoDS_Face & (TopOpeBRepBuild_CorrectFace2d::*)() const) &TopOpeBRepBuild_CorrectFace2d::Face, "None");
cls_TopOpeBRepBuild_CorrectFace2d.def("Perform", (void (TopOpeBRepBuild_CorrectFace2d::*)()) &TopOpeBRepBuild_CorrectFace2d::Perform, "None");
cls_TopOpeBRepBuild_CorrectFace2d.def("IsDone", (Standard_Boolean (TopOpeBRepBuild_CorrectFace2d::*)() const) &TopOpeBRepBuild_CorrectFace2d::IsDone, "None");
cls_TopOpeBRepBuild_CorrectFace2d.def("ErrorStatus", (Standard_Integer (TopOpeBRepBuild_CorrectFace2d::*)() const) &TopOpeBRepBuild_CorrectFace2d::ErrorStatus, "None");
cls_TopOpeBRepBuild_CorrectFace2d.def("CorrectedFace", (const TopoDS_Face & (TopOpeBRepBuild_CorrectFace2d::*)() const) &TopOpeBRepBuild_CorrectFace2d::CorrectedFace, "None");
cls_TopOpeBRepBuild_CorrectFace2d.def("SetMapOfTrans2dInfo", (void (TopOpeBRepBuild_CorrectFace2d::*)(TopTools_IndexedDataMapOfShapeShape &)) &TopOpeBRepBuild_CorrectFace2d::SetMapOfTrans2dInfo, "None", py::arg("aMap"));
cls_TopOpeBRepBuild_CorrectFace2d.def("MapOfTrans2dInfo", (TopTools_IndexedDataMapOfShapeShape & (TopOpeBRepBuild_CorrectFace2d::*)()) &TopOpeBRepBuild_CorrectFace2d::MapOfTrans2dInfo, "None");
cls_TopOpeBRepBuild_CorrectFace2d.def_static("GetP2dFL_", (void (*)(const TopoDS_Face &, const TopoDS_Edge &, gp_Pnt2d &, gp_Pnt2d &)) &TopOpeBRepBuild_CorrectFace2d::GetP2dFL, "None", py::arg("aFace"), py::arg("anEdge"), py::arg("P2dF"), py::arg("P2dL"));
cls_TopOpeBRepBuild_CorrectFace2d.def_static("CheckList_", (void (*)(const TopoDS_Face &, TopTools_ListOfShape &)) &TopOpeBRepBuild_CorrectFace2d::CheckList, "None", py::arg("aFace"), py::arg("aHeadList"));

// Enums

}