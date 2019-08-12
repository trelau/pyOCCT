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
#include <BRepAdaptor_Curve.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <BRepGProp_EdgeTool.hxx>

void bind_BRepGProp_EdgeTool(py::module &mod){

py::class_<BRepGProp_EdgeTool, std::unique_ptr<BRepGProp_EdgeTool, Deleter<BRepGProp_EdgeTool>>> cls_BRepGProp_EdgeTool(mod, "BRepGProp_EdgeTool", "Provides the required methods to instantiate CGProps from GProp with a Curve from BRepAdaptor.");

// Constructors

// Fields

// Methods
// cls_BRepGProp_EdgeTool.def_static("operator new_", (void * (*)(size_t)) &BRepGProp_EdgeTool::operator new, "None", py::arg("theSize"));
// cls_BRepGProp_EdgeTool.def_static("operator delete_", (void (*)(void *)) &BRepGProp_EdgeTool::operator delete, "None", py::arg("theAddress"));
// cls_BRepGProp_EdgeTool.def_static("operator new[]_", (void * (*)(size_t)) &BRepGProp_EdgeTool::operator new[], "None", py::arg("theSize"));
// cls_BRepGProp_EdgeTool.def_static("operator delete[]_", (void (*)(void *)) &BRepGProp_EdgeTool::operator delete[], "None", py::arg("theAddress"));
// cls_BRepGProp_EdgeTool.def_static("operator new_", (void * (*)(size_t, void *)) &BRepGProp_EdgeTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepGProp_EdgeTool.def_static("operator delete_", (void (*)(void *, void *)) &BRepGProp_EdgeTool::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepGProp_EdgeTool.def_static("FirstParameter_", (Standard_Real (*)(const BRepAdaptor_Curve &)) &BRepGProp_EdgeTool::FirstParameter, "Returns the parametric value of the start point of the curve. The curve is oriented from the start point to the end point.", py::arg("C"));
cls_BRepGProp_EdgeTool.def_static("LastParameter_", (Standard_Real (*)(const BRepAdaptor_Curve &)) &BRepGProp_EdgeTool::LastParameter, "Returns the parametric value of the end point of the curve. The curve is oriented from the start point to the end point.", py::arg("C"));
cls_BRepGProp_EdgeTool.def_static("IntegrationOrder_", (Standard_Integer (*)(const BRepAdaptor_Curve &)) &BRepGProp_EdgeTool::IntegrationOrder, "Returns the number of Gauss points required to do the integration with a good accuracy using the Gauss method. For a polynomial curve of degree n the maxima of accuracy is obtained with an order of integration equal to 2*n-1.", py::arg("C"));
cls_BRepGProp_EdgeTool.def_static("Value_", (gp_Pnt (*)(const BRepAdaptor_Curve &, const Standard_Real)) &BRepGProp_EdgeTool::Value, "Returns the point of parameter U on the loaded curve.", py::arg("C"), py::arg("U"));
cls_BRepGProp_EdgeTool.def_static("D1_", (void (*)(const BRepAdaptor_Curve &, const Standard_Real, gp_Pnt &, gp_Vec &)) &BRepGProp_EdgeTool::D1, "Returns the point of parameter U and the first derivative at this point.", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("V1"));
cls_BRepGProp_EdgeTool.def_static("NbIntervals_", (Standard_Integer (*)(const BRepAdaptor_Curve &, const GeomAbs_Shape)) &BRepGProp_EdgeTool::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("C"), py::arg("S"));
cls_BRepGProp_EdgeTool.def_static("Intervals_", (void (*)(const BRepAdaptor_Curve &, TColStd_Array1OfReal &, const GeomAbs_Shape)) &BRepGProp_EdgeTool::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("C"), py::arg("T"), py::arg("S"));

// Enums

}