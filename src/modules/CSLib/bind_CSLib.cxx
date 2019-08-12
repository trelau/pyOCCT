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
#include <gp_Vec.hxx>
#include <Standard_TypeDef.hxx>
#include <CSLib_DerivativeStatus.hxx>
#include <gp_Dir.hxx>
#include <CSLib_NormalStatus.hxx>
#include <TColgp_Array2OfVec.hxx>
#include <CSLib_Class2d.hxx>
#include <CSLib_NormalPolyDef.hxx>
#include <CSLib.hxx>

void bind_CSLib(py::module &mod){

py::class_<CSLib, std::unique_ptr<CSLib, Deleter<CSLib>>> cls_CSLib(mod, "CSLib", "This package implements functions for basis geometric computation on curves and surfaces. The tolerance criterions used in this package are Resolution from package gp and RealEpsilon from class Real of package Standard.");

// Constructors

// Fields

// Methods
// cls_CSLib.def_static("operator new_", (void * (*)(size_t)) &CSLib::operator new, "None", py::arg("theSize"));
// cls_CSLib.def_static("operator delete_", (void (*)(void *)) &CSLib::operator delete, "None", py::arg("theAddress"));
// cls_CSLib.def_static("operator new[]_", (void * (*)(size_t)) &CSLib::operator new[], "None", py::arg("theSize"));
// cls_CSLib.def_static("operator delete[]_", (void (*)(void *)) &CSLib::operator delete[], "None", py::arg("theAddress"));
// cls_CSLib.def_static("operator new_", (void * (*)(size_t, void *)) &CSLib::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_CSLib.def_static("operator delete_", (void (*)(void *, void *)) &CSLib::operator delete, "None", py::arg(""), py::arg(""));
cls_CSLib.def_static("Normal_", (void (*)(const gp_Vec &, const gp_Vec &, const Standard_Real, CSLib_DerivativeStatus &, gp_Dir &)) &CSLib::Normal, "The following functions computes the normal to a surface inherits FunctionWithDerivative from math", py::arg("D1U"), py::arg("D1V"), py::arg("SinTol"), py::arg("theStatus"), py::arg("Normal"));
cls_CSLib.def_static("Normal_", [](const gp_Vec & D1U, const gp_Vec & D1V, const gp_Vec & D2U, const gp_Vec & D2V, const gp_Vec & D2UV, const Standard_Real SinTol, Standard_Boolean & Done, CSLib_NormalStatus & theStatus, gp_Dir & Normal){ CSLib::Normal(D1U, D1V, D2U, D2V, D2UV, SinTol, Done, theStatus, Normal); return Done; }, "If there is a singularity on the surface the previous method cannot compute the local normal. This method computes an approched normal direction of a surface. It does a limited development and needs the second derivatives on the surface as input data. It computes the normal as follow : N(u, v) = D1U ^ D1V N(u0+du,v0+dv) = N0 + DN/du(u0,v0) * du + DN/dv(u0,v0) * dv + Eps with Eps->0 so we can have the equivalence N ~ dN/du + dN/dv. DNu = ||DN/du|| and DNv = ||DN/dv||", py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("SinTol"), py::arg("Done"), py::arg("theStatus"), py::arg("Normal"));
cls_CSLib.def_static("Normal_", (void (*)(const gp_Vec &, const gp_Vec &, const Standard_Real, CSLib_NormalStatus &, gp_Dir &)) &CSLib::Normal, "Computes the normal direction of a surface as the cross product between D1U and D1V.", py::arg("D1U"), py::arg("D1V"), py::arg("MagTol"), py::arg("theStatus"), py::arg("Normal"));
cls_CSLib.def_static("Normal_", [](const Standard_Integer MaxOrder, const TColgp_Array2OfVec & DerNUV, const Standard_Real MagTol, const Standard_Real U, const Standard_Real V, const Standard_Real Umin, const Standard_Real Umax, const Standard_Real Vmin, const Standard_Real Vmax, CSLib_NormalStatus & theStatus, gp_Dir & Normal, Standard_Integer & OrderU, Standard_Integer & OrderV){ CSLib::Normal(MaxOrder, DerNUV, MagTol, U, V, Umin, Umax, Vmin, Vmax, theStatus, Normal, OrderU, OrderV); return std::tuple<Standard_Integer &, Standard_Integer &>(OrderU, OrderV); }, "find the first order k0 of deriviative of NUV where: foreach order < k0 all the derivatives of NUV are null all the derivatives of NUV corresponding to the order k0 are collinear and have the same sens. In this case, normal at U,V is unique.", py::arg("MaxOrder"), py::arg("DerNUV"), py::arg("MagTol"), py::arg("U"), py::arg("V"), py::arg("Umin"), py::arg("Umax"), py::arg("Vmin"), py::arg("Vmax"), py::arg("theStatus"), py::arg("Normal"), py::arg("OrderU"), py::arg("OrderV"));
cls_CSLib.def_static("DNNUV_", (gp_Vec (*)(const Standard_Integer, const Standard_Integer, const TColgp_Array2OfVec &)) &CSLib::DNNUV, "-- Computes the derivative of order Nu in the -- direction U and Nv in the direction V of the not -- normalized normal vector at the point P(U,V) The array DerSurf contain the derivative (i,j) of the surface for i=0,Nu+1 ; j=0,Nv+1", py::arg("Nu"), py::arg("Nv"), py::arg("DerSurf"));
cls_CSLib.def_static("DNNUV_", (gp_Vec (*)(const Standard_Integer, const Standard_Integer, const TColgp_Array2OfVec &, const TColgp_Array2OfVec &)) &CSLib::DNNUV, "Computes the derivatives of order Nu in the direction Nu and Nv in the direction Nv of the not normalized vector N(u,v) = dS1/du * dS2/dv (cases where we use an osculating surface) DerSurf1 are the derivatives of S1", py::arg("Nu"), py::arg("Nv"), py::arg("DerSurf1"), py::arg("DerSurf2"));
cls_CSLib.def_static("DNNormal_", [](const Standard_Integer a0, const Standard_Integer a1, const TColgp_Array2OfVec & a2) -> gp_Vec { return CSLib::DNNormal(a0, a1, a2); });
cls_CSLib.def_static("DNNormal_", [](const Standard_Integer a0, const Standard_Integer a1, const TColgp_Array2OfVec & a2, const Standard_Integer a3) -> gp_Vec { return CSLib::DNNormal(a0, a1, a2, a3); });
cls_CSLib.def_static("DNNormal_", (gp_Vec (*)(const Standard_Integer, const Standard_Integer, const TColgp_Array2OfVec &, const Standard_Integer, const Standard_Integer)) &CSLib::DNNormal, "-- Computes the derivative of order Nu in the -- direction U and Nv in the direction V of the normalized normal vector at the point P(U,V) array DerNUV contain the derivative (i+Iduref,j+Idvref) of D1U ^ D1V for i=0,Nu ; j=0,Nv Iduref and Idvref correspond to a derivative of D1U ^ D1V which can be used to compute the normalized normal vector. In the regular cases , Iduref=Idvref=0.", py::arg("Nu"), py::arg("Nv"), py::arg("DerNUV"), py::arg("Iduref"), py::arg("Idvref"));

// Enums

}