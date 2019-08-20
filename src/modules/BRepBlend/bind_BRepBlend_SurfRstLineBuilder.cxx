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
#include <Adaptor3d_TopolTool.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <Blend_SurfRstFunction.hxx>
#include <Blend_FuncInv.hxx>
#include <Blend_SurfPointFuncInv.hxx>
#include <Blend_SurfCurvFuncInv.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <gp_Pnt2d.hxx>
#include <BRepBlend_Line.hxx>
#include <Adaptor3d_HVertex.hxx>
#include <IntSurf_Transition.hxx>
#include <BRepBlend_Extremity.hxx>
#include <Blend_Status.hxx>
#include <Blend_Point.hxx>
#include <TopAbs_State.hxx>
#include <BRepBlend_SurfRstLineBuilder.hxx>

void bind_BRepBlend_SurfRstLineBuilder(py::module &mod){

py::class_<BRepBlend_SurfRstLineBuilder, std::unique_ptr<BRepBlend_SurfRstLineBuilder>> cls_BRepBlend_SurfRstLineBuilder(mod, "BRepBlend_SurfRstLineBuilder", "This class processes data resulting from Blend_CSWalking taking in consideration the Surface supporting the curve to detect the breakpoint.");

// Constructors
cls_BRepBlend_SurfRstLineBuilder.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor2d_HCurve2d> &, const opencascade::handle<Adaptor3d_TopolTool> &>(), py::arg("Surf1"), py::arg("Domain1"), py::arg("Surf2"), py::arg("Rst"), py::arg("Domain2"));

// Fields

// Methods
// cls_BRepBlend_SurfRstLineBuilder.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_SurfRstLineBuilder::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_SurfRstLineBuilder.def_static("operator delete_", (void (*)(void *)) &BRepBlend_SurfRstLineBuilder::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_SurfRstLineBuilder.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_SurfRstLineBuilder::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_SurfRstLineBuilder.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_SurfRstLineBuilder::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_SurfRstLineBuilder.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_SurfRstLineBuilder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_SurfRstLineBuilder.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_SurfRstLineBuilder::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_SurfRstLineBuilder.def("Perform", [](BRepBlend_SurfRstLineBuilder &self, Blend_SurfRstFunction & a0, Blend_FuncInv & a1, Blend_SurfPointFuncInv & a2, Blend_SurfCurvFuncInv & a3, const Standard_Real a4, const Standard_Real a5, const Standard_Real a6, const Standard_Real a7, const math_Vector & a8, const Standard_Real a9, const Standard_Real a10) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10); });
cls_BRepBlend_SurfRstLineBuilder.def("Perform", (void (BRepBlend_SurfRstLineBuilder::*)(Blend_SurfRstFunction &, Blend_FuncInv &, Blend_SurfPointFuncInv &, Blend_SurfCurvFuncInv &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const math_Vector &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &BRepBlend_SurfRstLineBuilder::Perform, "None", py::arg("Func"), py::arg("Finv"), py::arg("FinvP"), py::arg("FinvC"), py::arg("Pdep"), py::arg("Pmax"), py::arg("MaxStep"), py::arg("TolGuide"), py::arg("Soldep"), py::arg("Tolesp"), py::arg("Fleche"), py::arg("Appro"));
cls_BRepBlend_SurfRstLineBuilder.def("PerformFirstSection", [](BRepBlend_SurfRstLineBuilder &self, Blend_SurfRstFunction & Func, Blend_FuncInv & Finv, Blend_SurfPointFuncInv & FinvP, Blend_SurfCurvFuncInv & FinvC, const Standard_Real Pdep, const Standard_Real Pmax, const math_Vector & Soldep, const Standard_Real Tolesp, const Standard_Real TolGuide, const Standard_Boolean RecRst, const Standard_Boolean RecP, const Standard_Boolean RecS, Standard_Real & Psol, math_Vector & ParSol){ Standard_Boolean rv = self.PerformFirstSection(Func, Finv, FinvP, FinvC, Pdep, Pmax, Soldep, Tolesp, TolGuide, RecRst, RecP, RecS, Psol, ParSol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Psol); }, "None", py::arg("Func"), py::arg("Finv"), py::arg("FinvP"), py::arg("FinvC"), py::arg("Pdep"), py::arg("Pmax"), py::arg("Soldep"), py::arg("Tolesp"), py::arg("TolGuide"), py::arg("RecRst"), py::arg("RecP"), py::arg("RecS"), py::arg("Psol"), py::arg("ParSol"));
cls_BRepBlend_SurfRstLineBuilder.def("Complete", (Standard_Boolean (BRepBlend_SurfRstLineBuilder::*)(Blend_SurfRstFunction &, Blend_FuncInv &, Blend_SurfPointFuncInv &, Blend_SurfCurvFuncInv &, const Standard_Real)) &BRepBlend_SurfRstLineBuilder::Complete, "None", py::arg("Func"), py::arg("Finv"), py::arg("FinvP"), py::arg("FinvC"), py::arg("Pmin"));
cls_BRepBlend_SurfRstLineBuilder.def("ArcToRecadre", [](BRepBlend_SurfRstLineBuilder &self, const math_Vector & Sol, const Standard_Integer PrevIndex, gp_Pnt2d & pt2d, gp_Pnt2d & lastpt2d, Standard_Real & ponarc){ Standard_Integer rv = self.ArcToRecadre(Sol, PrevIndex, pt2d, lastpt2d, ponarc); return std::tuple<Standard_Integer, Standard_Real &>(rv, ponarc); }, "None", py::arg("Sol"), py::arg("PrevIndex"), py::arg("pt2d"), py::arg("lastpt2d"), py::arg("ponarc"));
cls_BRepBlend_SurfRstLineBuilder.def("IsDone", (Standard_Boolean (BRepBlend_SurfRstLineBuilder::*)() const) &BRepBlend_SurfRstLineBuilder::IsDone, "None");
cls_BRepBlend_SurfRstLineBuilder.def("Line", (const opencascade::handle<BRepBlend_Line> & (BRepBlend_SurfRstLineBuilder::*)() const) &BRepBlend_SurfRstLineBuilder::Line, "None");
cls_BRepBlend_SurfRstLineBuilder.def("DecrochStart", (Standard_Boolean (BRepBlend_SurfRstLineBuilder::*)() const) &BRepBlend_SurfRstLineBuilder::DecrochStart, "None");
cls_BRepBlend_SurfRstLineBuilder.def("DecrochEnd", (Standard_Boolean (BRepBlend_SurfRstLineBuilder::*)() const) &BRepBlend_SurfRstLineBuilder::DecrochEnd, "None");

// Enums

}