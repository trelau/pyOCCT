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
#include <ChFiDS_HElSpine.hxx>
#include <Blend_Point.hxx>
#include <Blend_Function.hxx>
#include <Blend_FuncInv.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <TopAbs_State.hxx>
#include <BRepBlend_Line.hxx>
#include <gp_Pnt.hxx>
#include <gp_Pnt2d.hxx>
#include <Adaptor3d_HVertex.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <IntSurf_Transition.hxx>
#include <BRepBlend_Extremity.hxx>
#include <Blend_Status.hxx>
#include <Blend_SequenceOfPoint.hxx>
#include <BRepBlend_Walking.hxx>

void bind_BRepBlend_Walking(py::module &mod){

py::class_<BRepBlend_Walking> cls_BRepBlend_Walking(mod, "BRepBlend_Walking", "None");

// Constructors
cls_BRepBlend_Walking.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<ChFiDS_HElSpine> &>(), py::arg("Surf1"), py::arg("Surf2"), py::arg("Domain1"), py::arg("Domain2"), py::arg("HGuide"));

// Fields

// Methods
// cls_BRepBlend_Walking.def_static("operator new_", (void * (*)(size_t)) &BRepBlend_Walking::operator new, "None", py::arg("theSize"));
// cls_BRepBlend_Walking.def_static("operator delete_", (void (*)(void *)) &BRepBlend_Walking::operator delete, "None", py::arg("theAddress"));
// cls_BRepBlend_Walking.def_static("operator new[]_", (void * (*)(size_t)) &BRepBlend_Walking::operator new[], "None", py::arg("theSize"));
// cls_BRepBlend_Walking.def_static("operator delete[]_", (void (*)(void *)) &BRepBlend_Walking::operator delete[], "None", py::arg("theAddress"));
// cls_BRepBlend_Walking.def_static("operator new_", (void * (*)(size_t, void *)) &BRepBlend_Walking::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepBlend_Walking.def_static("operator delete_", (void (*)(void *, void *)) &BRepBlend_Walking::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepBlend_Walking.def("SetDomainsToRecadre", (void (BRepBlend_Walking::*)(const opencascade::handle<Adaptor3d_TopolTool> &, const opencascade::handle<Adaptor3d_TopolTool> &)) &BRepBlend_Walking::SetDomainsToRecadre, "To define different domains for control and clipping.", py::arg("RecDomain1"), py::arg("RecDomain2"));
cls_BRepBlend_Walking.def("AddSingularPoint", (void (BRepBlend_Walking::*)(const Blend_Point &)) &BRepBlend_Walking::AddSingularPoint, "To define singular points computed before walking.", py::arg("P"));
cls_BRepBlend_Walking.def("Perform", [](BRepBlend_Walking &self, Blend_Function & a0, Blend_FuncInv & a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Real a5, const math_Vector & a6, const Standard_Real a7, const Standard_Real a8) -> void { return self.Perform(a0, a1, a2, a3, a4, a5, a6, a7, a8); });
cls_BRepBlend_Walking.def("Perform", (void (BRepBlend_Walking::*)(Blend_Function &, Blend_FuncInv &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const math_Vector &, const Standard_Real, const Standard_Real, const Standard_Boolean)) &BRepBlend_Walking::Perform, "None", py::arg("F"), py::arg("FInv"), py::arg("Pdep"), py::arg("Pmax"), py::arg("MaxStep"), py::arg("TolGuide"), py::arg("Soldep"), py::arg("Tolesp"), py::arg("Fleche"), py::arg("Appro"));
cls_BRepBlend_Walking.def("PerformFirstSection", (Standard_Boolean (BRepBlend_Walking::*)(Blend_Function &, const Standard_Real, math_Vector &, const Standard_Real, const Standard_Real, TopAbs_State &, TopAbs_State &)) &BRepBlend_Walking::PerformFirstSection, "None", py::arg("F"), py::arg("Pdep"), py::arg("ParDep"), py::arg("Tolesp"), py::arg("TolGuide"), py::arg("Pos1"), py::arg("Pos2"));
cls_BRepBlend_Walking.def("PerformFirstSection", [](BRepBlend_Walking &self, Blend_Function & F, Blend_FuncInv & FInv, const Standard_Real Pdep, const Standard_Real Pmax, const math_Vector & ParDep, const Standard_Real Tolesp, const Standard_Real TolGuide, const Standard_Boolean RecOnS1, const Standard_Boolean RecOnS2, Standard_Real & Psol, math_Vector & ParSol){ Standard_Boolean rv = self.PerformFirstSection(F, FInv, Pdep, Pmax, ParDep, Tolesp, TolGuide, RecOnS1, RecOnS2, Psol, ParSol); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Psol); }, "None", py::arg("F"), py::arg("FInv"), py::arg("Pdep"), py::arg("Pmax"), py::arg("ParDep"), py::arg("Tolesp"), py::arg("TolGuide"), py::arg("RecOnS1"), py::arg("RecOnS2"), py::arg("Psol"), py::arg("ParSol"));
cls_BRepBlend_Walking.def("Continu", (Standard_Boolean (BRepBlend_Walking::*)(Blend_Function &, Blend_FuncInv &, const Standard_Real)) &BRepBlend_Walking::Continu, "None", py::arg("F"), py::arg("FInv"), py::arg("P"));
cls_BRepBlend_Walking.def("Continu", (Standard_Boolean (BRepBlend_Walking::*)(Blend_Function &, Blend_FuncInv &, const Standard_Real, const Standard_Boolean)) &BRepBlend_Walking::Continu, "None", py::arg("F"), py::arg("FInv"), py::arg("P"), py::arg("OnS1"));
cls_BRepBlend_Walking.def("Complete", (Standard_Boolean (BRepBlend_Walking::*)(Blend_Function &, Blend_FuncInv &, const Standard_Real)) &BRepBlend_Walking::Complete, "None", py::arg("F"), py::arg("FInv"), py::arg("Pmin"));
cls_BRepBlend_Walking.def("ClassificationOnS1", (void (BRepBlend_Walking::*)(const Standard_Boolean)) &BRepBlend_Walking::ClassificationOnS1, "None", py::arg("C"));
cls_BRepBlend_Walking.def("ClassificationOnS2", (void (BRepBlend_Walking::*)(const Standard_Boolean)) &BRepBlend_Walking::ClassificationOnS2, "None", py::arg("C"));
cls_BRepBlend_Walking.def("Check2d", (void (BRepBlend_Walking::*)(const Standard_Boolean)) &BRepBlend_Walking::Check2d, "None", py::arg("C"));
cls_BRepBlend_Walking.def("Check", (void (BRepBlend_Walking::*)(const Standard_Boolean)) &BRepBlend_Walking::Check, "None", py::arg("C"));
cls_BRepBlend_Walking.def("TwistOnS1", (Standard_Boolean (BRepBlend_Walking::*)() const) &BRepBlend_Walking::TwistOnS1, "None");
cls_BRepBlend_Walking.def("TwistOnS2", (Standard_Boolean (BRepBlend_Walking::*)() const) &BRepBlend_Walking::TwistOnS2, "None");
cls_BRepBlend_Walking.def("IsDone", (Standard_Boolean (BRepBlend_Walking::*)() const) &BRepBlend_Walking::IsDone, "None");
cls_BRepBlend_Walking.def("Line", (const opencascade::handle<BRepBlend_Line> & (BRepBlend_Walking::*)() const) &BRepBlend_Walking::Line, "None");

// Enums

}