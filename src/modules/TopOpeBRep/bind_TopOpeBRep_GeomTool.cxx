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
#include <Standard_TypeDef.hxx>
#include <TopOpeBRep_LineInter.hxx>
#include <TopoDS_Shape.hxx>
#include <TopOpeBRepDS_Curve.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Curve.hxx>
#include <TopOpeBRep_GeomTool.hxx>

void bind_TopOpeBRep_GeomTool(py::module &mod){

py::class_<TopOpeBRep_GeomTool> cls_TopOpeBRep_GeomTool(mod, "TopOpeBRep_GeomTool", "Provide services needed by the DSFiller");

// Constructors

// Fields

// Methods
// cls_TopOpeBRep_GeomTool.def_static("operator new_", (void * (*)(size_t)) &TopOpeBRep_GeomTool::operator new, "None", py::arg("theSize"));
// cls_TopOpeBRep_GeomTool.def_static("operator delete_", (void (*)(void *)) &TopOpeBRep_GeomTool::operator delete, "None", py::arg("theAddress"));
// cls_TopOpeBRep_GeomTool.def_static("operator new[]_", (void * (*)(size_t)) &TopOpeBRep_GeomTool::operator new[], "None", py::arg("theSize"));
// cls_TopOpeBRep_GeomTool.def_static("operator delete[]_", (void (*)(void *)) &TopOpeBRep_GeomTool::operator delete[], "None", py::arg("theAddress"));
// cls_TopOpeBRep_GeomTool.def_static("operator new_", (void * (*)(size_t, void *)) &TopOpeBRep_GeomTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TopOpeBRep_GeomTool.def_static("operator delete_", (void (*)(void *, void *)) &TopOpeBRep_GeomTool::operator delete, "None", py::arg(""), py::arg(""));
cls_TopOpeBRep_GeomTool.def_static("MakeCurves_", (void (*)(const Standard_Real, const Standard_Real, const TopOpeBRep_LineInter &, const TopoDS_Shape &, const TopoDS_Shape &, TopOpeBRepDS_Curve &, opencascade::handle<Geom2d_Curve> &, opencascade::handle<Geom2d_Curve> &)) &TopOpeBRep_GeomTool::MakeCurves, "Make the DS curve <C> and the pcurves <PC1,PC2> from intersection line <L> lying on shapes <S1,S2>. <min,max> = <L> bounds", py::arg("min"), py::arg("max"), py::arg("L"), py::arg("S1"), py::arg("S2"), py::arg("C"), py::arg("PC1"), py::arg("PC2"));
cls_TopOpeBRep_GeomTool.def_static("MakeCurve_", (void (*)(const Standard_Real, const Standard_Real, const TopOpeBRep_LineInter &, opencascade::handle<Geom_Curve> &)) &TopOpeBRep_GeomTool::MakeCurve, "None", py::arg("min"), py::arg("max"), py::arg("L"), py::arg("C"));
cls_TopOpeBRep_GeomTool.def_static("MakeBSpline1fromWALKING3d_", (opencascade::handle<Geom_Curve> (*)(const TopOpeBRep_LineInter &)) &TopOpeBRep_GeomTool::MakeBSpline1fromWALKING3d, "None", py::arg("L"));
cls_TopOpeBRep_GeomTool.def_static("MakeBSpline1fromWALKING2d_", (opencascade::handle<Geom2d_Curve> (*)(const TopOpeBRep_LineInter &, const Standard_Integer)) &TopOpeBRep_GeomTool::MakeBSpline1fromWALKING2d, "None", py::arg("L"), py::arg("SI"));

// Enums

}