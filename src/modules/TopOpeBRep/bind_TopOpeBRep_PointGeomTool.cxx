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
#include <TopOpeBRepDS_Point.hxx>
#include <TopOpeBRep_VPointInter.hxx>
#include <TopOpeBRep_Point2d.hxx>
#include <TopOpeBRep_FaceEdgeIntersector.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopOpeBRep_PointGeomTool.hxx>

void bind_TopOpeBRep_PointGeomTool(py::module &mod){

py::class_<TopOpeBRep_PointGeomTool> cls_TopOpeBRep_PointGeomTool(mod, "TopOpeBRep_PointGeomTool", "Provide services needed by the Fillers");

// Constructors

// Fields

// Methods
// cls_TopOpeBRep_PointGeomTool.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRep_PointGeomTool::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRep_PointGeomTool.def_static("operator delete_", (void (*)(void *)) &TopOpeBRep_PointGeomTool::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRep_PointGeomTool.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRep_PointGeomTool::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRep_PointGeomTool.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRep_PointGeomTool::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRep_PointGeomTool.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRep_PointGeomTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRep_PointGeomTool.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRep_PointGeomTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRep_PointGeomTool.def_static("MakePoint_", (TopOpeBRepDS_Point (*)(const TopOpeBRep_VPointInter &)) &TopOpeBRep_PointGeomTool::MakePoint, "None", py::arg("IP"));
cls_TopOpeBRep_PointGeomTool.def_static("MakePoint_", (TopOpeBRepDS_Point (*)(const TopOpeBRep_Point2d &)) &TopOpeBRep_PointGeomTool::MakePoint, "None", py::arg("P2D"));
cls_TopOpeBRep_PointGeomTool.def_static("MakePoint_", (TopOpeBRepDS_Point (*)(const TopOpeBRep_FaceEdgeIntersector &)) &TopOpeBRep_PointGeomTool::MakePoint, "None", py::arg("FEI"));
cls_TopOpeBRep_PointGeomTool.def_static("MakePoint_", (TopOpeBRepDS_Point (*)(const TopoDS_Shape &)) &TopOpeBRep_PointGeomTool::MakePoint, "None", py::arg("S"));
cls_TopOpeBRep_PointGeomTool.def_static("IsEqual_", (Standard_Boolean (*)(const TopOpeBRepDS_Point &, const TopOpeBRepDS_Point &)) &TopOpeBRep_PointGeomTool::IsEqual, "None", py::arg("DSP1"), py::arg("DSP2"));

// Enums

}