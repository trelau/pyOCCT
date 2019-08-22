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
#include <BRepAdaptor_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <BRepLProp_SurfaceTool.hxx>

void bind_BRepLProp_SurfaceTool(py::module &mod){

py::class_<BRepLProp_SurfaceTool> cls_BRepLProp_SurfaceTool(mod, "BRepLProp_SurfaceTool", "None");

// Constructors

// Fields

// Methods
// cls_BRepLProp_SurfaceTool.def_static("operator new_", (void * (*)(size_t)) &BRepLProp_SurfaceTool::operator new, "None", py::arg("theSize"));
// cls_BRepLProp_SurfaceTool.def_static("operator delete_", (void (*)(void *)) &BRepLProp_SurfaceTool::operator delete, "None", py::arg("theAddress"));
// cls_BRepLProp_SurfaceTool.def_static("operator new[]_", (void * (*)(size_t)) &BRepLProp_SurfaceTool::operator new[], "None", py::arg("theSize"));
// cls_BRepLProp_SurfaceTool.def_static("operator delete[]_", (void (*)(void *)) &BRepLProp_SurfaceTool::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLProp_SurfaceTool.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLProp_SurfaceTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLProp_SurfaceTool.def_static("operator delete_", (void (*)(void *, void *)) &BRepLProp_SurfaceTool::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLProp_SurfaceTool.def_static("Value_", (void (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, gp_Pnt &)) &BRepLProp_SurfaceTool::Value, "Computes the point <P> of parameter <U> and <V> on the Surface <S>.", py::arg("S"), py::arg("U"), py::arg("V"), py::arg("P"));
cls_BRepLProp_SurfaceTool.def_static("D1_", (void (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &)) &BRepLProp_SurfaceTool::D1, "Computes the point <P> and first derivative <D1*> of parameter <U> and <V> on the Surface <S>.", py::arg("S"), py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"));
cls_BRepLProp_SurfaceTool.def_static("D2_", (void (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &)) &BRepLProp_SurfaceTool::D2, "Computes the point <P>, the first derivative <D1*> and second derivative <D2*> of parameter <U> and <V> on the Surface <S>.", py::arg("S"), py::arg("U"), py::arg("V"), py::arg("P"), py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("DUV"));
cls_BRepLProp_SurfaceTool.def_static("DN_", (gp_Vec (*)(const BRepAdaptor_Surface &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer)) &BRepLProp_SurfaceTool::DN, "None", py::arg("S"), py::arg("U"), py::arg("V"), py::arg("IU"), py::arg("IV"));
cls_BRepLProp_SurfaceTool.def_static("Continuity_", (Standard_Integer (*)(const BRepAdaptor_Surface &)) &BRepLProp_SurfaceTool::Continuity, "returns the order of continuity of the Surface <S>. returns 1 : first derivative only is computable returns 2 : first and second derivative only are computable.", py::arg("S"));
cls_BRepLProp_SurfaceTool.def_static("Bounds_", [](const BRepAdaptor_Surface & S, Standard_Real & U1, Standard_Real & V1, Standard_Real & U2, Standard_Real & V2){ BRepLProp_SurfaceTool::Bounds(S, U1, V1, U2, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, V1, U2, V2); }, "returns the bounds of the Surface.", py::arg("S"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));

// Enums

}