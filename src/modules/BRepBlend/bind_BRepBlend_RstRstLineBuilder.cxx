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
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <Adaptor3d_TopolTool.hxx>
#include <Blend_RstRstFunction.hxx>
#include <Blend_SurfCurvFuncInv.hxx>
#include <Blend_CurvPointFuncInv.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <BRepBlend_Line.hxx>
#include <Adaptor3d_HVertex.hxx>
#include <IntSurf_Transition.hxx>
#include <BRepBlend_Extremity.hxx>
#include <Blend_Status.hxx>
#include <Blend_Point.hxx>
#include <TopAbs_State.hxx>
#include <Blend_DecrochStatus.hxx>
#include <BRepBlend_RstRstLineBuilder.hxx>

void bind_BRepBlend_RstRstLineBuilder(py::module &mod){

py::class_<BRepBlend_RstRstLineBuilder, std::unique_ptr<BRepBlend_RstRstLineBuilder>> cls_BRepBlend_RstRstLineBuilder(mod, "BRepBlend_RstRstLineBuilder", "This class processes the data resulting from Blend_CSWalking but it takes in consideration the Surface supporting the curve to detect the breakpoint.");

// Constructors
cls_BRepBlend_RstRstLineBuilder.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_TopolTool> &>(), py::arg("Surf1"), py::arg("Rst1"), py::arg("Domain1"), py::arg("Surf2"), py::arg("Rst2"), py::arg("Domain2"));

// Fields

// Methods
// cls_BRepBlend_RstRstLineBuilder.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_RstRstLineBuilder::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_RstRstLineBuilder.def_static("operator delete_", (void (*)(void *)) &BRepBlend_RstRstLineBuilder::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_RstRstLineBuilder.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_RstRstLineBuilder::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_RstRstLineBuilder.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_RstRstLineBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_RstRstLineBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_RstRstLineBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_RstRstLineBuilder.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_RstRstLineBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_RstRstLineBuilder.def("Perform", [](BRepBlend_RstRstLineBuilder &self, Blend_RstRstFunction & a0, Blend_SurfCurvFuncInv & a1, Blend_CurvPointFuncInv & a2, Blend_SurfCurvFuncInv & a3, Blend_CurvPointFuncInv & a4, const Standard_Real a5, const Standard_Real a6, const Standard_Real a7, const Standard_Real a8, const math_Vector & a9, const Standard_Real a10, const Standard_Real a11) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); });
cls_BRepBlend_RstRstLineBuilder.def("Perform", (void (BRepBlend_RstRstLineBuilder::*)(Blend_RstRstFunction &, Blend_SurfCurvFuncInv &, Blend_CurvPointFuncInv &, Blend_SurfCurvFuncInv &, Blend_CurvPointFuncInv &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const math_Vector &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &BRepBlend_RstRstLineBuilder::Perform, "None", py::arg("Func"), py::arg("Finv1"), py::arg("FinvP1"), py::arg("Finv2"), py::arg("FinvP2"), py::arg("Pdep"), py::arg("Pmax"), py::arg("MaxStep"), py::arg("TolGuide"), py::arg("Soldep"), py::arg("Tolesp"), py::arg("Fleche"), py::arg("Appro"));
cls_BRepBlend_RstRstLineBuilder.def("PerformFirstSection", [](BRepBlend_RstRstLineBuilder &self, Blend_RstRstFunction & Func, Blend_SurfCurvFuncInv & Finv1, Blend_CurvPointFuncInv & FinvP1, Blend_SurfCurvFuncInv & Finv2, Blend_CurvPointFuncInv & FinvP2, const Standard_Real Pdep, const Standard_Real Pmax, const math_Vector & Soldep, const Standard_Real Tolesp, const Standard_Real TolGuide, const Standard_Boolean RecRst1, const Standard_Boolean RecP1, const Standard_Boolean RecRst2, const Standard_Boolean RecP2, Standard_Real & Psol, math_Vector & ParSol){ Standard_Boolean rv = self.PerformFirstSection(Func, Finv1, FinvP1, Finv2, FinvP2, Pdep, Pmax, Soldep, Tolesp, TolGuide, RecRst1, RecP1, RecRst2, RecP2, Psol, ParSol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Psol); }, "None", py::arg("Func"), py::arg("Finv1"), py::arg("FinvP1"), py::arg("Finv2"), py::arg("FinvP2"), py::arg("Pdep"), py::arg("Pmax"), py::arg("Soldep"), py::arg("Tolesp"), py::arg("TolGuide"), py::arg("RecRst1"), py::arg("RecP1"), py::arg("RecRst2"), py::arg("RecP2"), py::arg("Psol"), py::arg("ParSol"));
cls_BRepBlend_RstRstLineBuilder.def("Complete", (Standard_Boolean (BRepBlend_RstRstLineBuilder::*)(Blend_RstRstFunction &, Blend_SurfCurvFuncInv &, Blend_CurvPointFuncInv &, Blend_SurfCurvFuncInv &, Blend_CurvPointFuncInv &, const Standard_Real)) &BRepBlend_RstRstLineBuilder::Complete, "None", py::arg("Func"), py::arg("Finv1"), py::arg("FinvP1"), py::arg("Finv2"), py::arg("FinvP2"), py::arg("Pmin"));
cls_BRepBlend_RstRstLineBuilder.def("IsDone", (Standard_Boolean (BRepBlend_RstRstLineBuilder::*)() const) &BRepBlend_RstRstLineBuilder::IsDone, "None");
cls_BRepBlend_RstRstLineBuilder.def("Line", (const opencascade::handle<BRepBlend_Line> & (BRepBlend_RstRstLineBuilder::*)() const) &BRepBlend_RstRstLineBuilder::Line, "None");
cls_BRepBlend_RstRstLineBuilder.def("Decroch1Start", (Standard_Boolean (BRepBlend_RstRstLineBuilder::*)() const) &BRepBlend_RstRstLineBuilder::Decroch1Start, "None");
cls_BRepBlend_RstRstLineBuilder.def("Decroch1End", (Standard_Boolean (BRepBlend_RstRstLineBuilder::*)() const) &BRepBlend_RstRstLineBuilder::Decroch1End, "None");
cls_BRepBlend_RstRstLineBuilder.def("Decroch2Start", (Standard_Boolean (BRepBlend_RstRstLineBuilder::*)() const) &BRepBlend_RstRstLineBuilder::Decroch2Start, "None");
cls_BRepBlend_RstRstLineBuilder.def("Decroch2End", (Standard_Boolean (BRepBlend_RstRstLineBuilder::*)() const) &BRepBlend_RstRstLineBuilder::Decroch2End, "None");

// Enums

}