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
#include <BlendFunc_SectionShape.hxx>
#include <Standard_TypeDef.hxx>
#include <Convert_ParameterisationType.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <GeomAbs_Shape.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec.hxx>
#include <BlendFunc_ConstRad.hxx>
#include <BlendFunc_ConstRadInv.hxx>
#include <BlendFunc_Ruled.hxx>
#include <BlendFunc_RuledInv.hxx>
#include <BlendFunc_EvolRad.hxx>
#include <BlendFunc_EvolRadInv.hxx>
#include <BlendFunc_CSConstRad.hxx>
#include <BlendFunc_CSCircular.hxx>
#include <BlendFunc_Corde.hxx>
#include <BlendFunc_Chamfer.hxx>
#include <BlendFunc_ChamfInv.hxx>
#include <BlendFunc_ChAsym.hxx>
#include <BlendFunc_ChAsymInv.hxx>
#include <BlendFunc_Tensor.hxx>
#include <BlendFunc.hxx>

void bind_BlendFunc(py::module &mod){

py::class_<BlendFunc, std::unique_ptr<BlendFunc>> cls_BlendFunc(mod, "BlendFunc", "This package provides a set of generic functions, that can instantiated to compute blendings between two surfaces (Constant radius, Evolutive radius, Ruled surface).");

// Constructors

// Fields

// Methods
// cls_BlendFunc.def_static("operator new_", (void * (*)(size_t)) &BlendFunc::operator new, "None", py::arg("theSize"));
// cls_BlendFunc.def_static("operator delete_", (void (*)(void *)) &BlendFunc::operator delete, "None", py::arg("theAddress"));
// cls_BlendFunc.def_static("operator new[]_", (void * (*)(size_t)) &BlendFunc::operator new[], "None", py::arg("theSize"));
// cls_BlendFunc.def_static("operator delete[]_", (void (*)(void *)) &BlendFunc::operator delete[], "None", py::arg("theAddress"));
// cls_BlendFunc.def_static("operator new_", (void * (*)(size_t, void *)) &BlendFunc::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BlendFunc.def_static("operator delete_", (void (*)(void *, void *)) &BlendFunc::operator delete, "None", py::arg(""), py::arg(""));
cls_BlendFunc.def_static("GetShape_", [](const BlendFunc_SectionShape SectShape, const Standard_Real MaxAng, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Convert_ParameterisationType & TypeConv){ BlendFunc::GetShape(SectShape, MaxAng, NbPoles, NbKnots, Degree, TypeConv); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree); }, "None", py::arg("SectShape"), py::arg("MaxAng"), py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("TypeConv"));
// cls_BlendFunc.def_static("Knots_", (void (*)(const BlendFunc_SectionShape, TColStd_Array1OfReal &)) &BlendFunc::Knots, "None", py::arg("SectShape"), py::arg("TKnots"));
// cls_BlendFunc.def_static("Mults_", (void (*)(const BlendFunc_SectionShape, TColStd_Array1OfInteger &)) &BlendFunc::Mults, "None", py::arg("SectShape"), py::arg("TMults"));
cls_BlendFunc.def_static("GetMinimalWeights_", (void (*)(const BlendFunc_SectionShape, const Convert_ParameterisationType, const Standard_Real, const Standard_Real, TColStd_Array1OfReal &)) &BlendFunc::GetMinimalWeights, "None", py::arg("SectShape"), py::arg("TConv"), py::arg("AngleMin"), py::arg("AngleMax"), py::arg("Weigths"));
cls_BlendFunc.def_static("NextShape_", (GeomAbs_Shape (*)(const GeomAbs_Shape)) &BlendFunc::NextShape, "Used to obtain the next level of continuity.", py::arg("S"));
cls_BlendFunc.def_static("ComputeNormal_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &, const gp_Pnt2d &, gp_Vec &)) &BlendFunc::ComputeNormal, "None", py::arg("Surf"), py::arg("p2d"), py::arg("Normal"));
cls_BlendFunc.def_static("ComputeDNormal_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &, const gp_Pnt2d &, gp_Vec &, gp_Vec &, gp_Vec &)) &BlendFunc::ComputeDNormal, "None", py::arg("Surf"), py::arg("p2d"), py::arg("Normal"), py::arg("DNu"), py::arg("DNv"));

// Enums

}