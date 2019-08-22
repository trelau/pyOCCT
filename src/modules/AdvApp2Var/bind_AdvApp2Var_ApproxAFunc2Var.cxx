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
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <GeomAbs_IsoType.hxx>
#include <GeomAbs_Shape.hxx>
#include <AdvApp2Var_EvaluatorFunc2Var.hxx>
#include <AdvApprox_Cutting.hxx>
#include <AdvApp2Var_Criterion.hxx>
#include <Geom_BSplineSurface.hxx>
#include <Standard_OStream.hxx>
#include <AdvApp2Var_Context.hxx>
#include <AdvApp2Var_Network.hxx>
#include <AdvApp2Var_Framework.hxx>
#include <TColGeom_HArray1OfSurface.hxx>
#include <AdvApp2Var_ApproxAFunc2Var.hxx>

void bind_AdvApp2Var_ApproxAFunc2Var(py::module &mod){

py::class_<AdvApp2Var_ApproxAFunc2Var> cls_AdvApp2Var_ApproxAFunc2Var(mod, "AdvApp2Var_ApproxAFunc2Var", "Perform the approximation of <Func> F(U,V) Arguments are : Num1DSS, Num2DSS, Num3DSS :The numbers of 1,2,3 dimensional subspaces OneDTol, TwoDTol, ThreeDTol: The tolerance of approximation in each subspaces OneDTolFr, TwoDTolFr, ThreeDTolFr: The tolerance of approximation on the boundarys in each subspaces [FirstInU, LastInU]: The Bounds in U of the Approximation [FirstInV, LastInV]: The Bounds in V of the Approximation FavorIso : Give preference to extract u-iso or v-iso on F(U,V) This can be usefull to optimize the <Func> methode ContInU, ContInV : Continuity waiting in u and v PrecisCode : Precision on approximation's error mesurement 1 : Fast computation and average precision 2 : Average computation and good precision 3 : Slow computation and very good precision MaxDegInU : Maximum u-degree waiting in U MaxDegInV : Maximum u-degree waiting in V Warning: MaxDegInU (resp. MaxDegInV) must be >= 2*iu (resp. iv) + 1, where iu (resp. iv) = 0 if ContInU (resp. ContInV) = GeomAbs_C0, = 1 if = GeomAbs_C1, = 2 if = GeomAbs_C2. MaxPatch : Maximun number of Patch waiting number of Patch is number of u span * number of v span Func : The external method to evaluate F(U,V) Crit : To (re)defined condition of convergence UChoice, VChoice : To define the way in U (or V) Knot insertion Warning: for the moment, the result is a 3D Surface so Num1DSS and Num2DSS must be equals to 0 and Num3DSS must be equal to 1. Warning: the Function of type EvaluatorFunc2Var from Approx must be a subclass of AdvApp2Var_EvaluatorFunc2Var");

// Constructors
cls_AdvApp2Var_ApproxAFunc2Var.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray2OfReal> &, const opencascade::handle<TColStd_HArray2OfReal> &, const opencascade::handle<TColStd_HArray2OfReal> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_IsoType, const GeomAbs_Shape, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const AdvApp2Var_EvaluatorFunc2Var &, AdvApprox_Cutting &, AdvApprox_Cutting &>(), py::arg("Num1DSS"), py::arg("Num2DSS"), py::arg("Num3DSS"), py::arg("OneDTol"), py::arg("TwoDTol"), py::arg("ThreeDTol"), py::arg("OneDTolFr"), py::arg("TwoDTolFr"), py::arg("ThreeDTolFr"), py::arg("FirstInU"), py::arg("LastInU"), py::arg("FirstInV"), py::arg("LastInV"), py::arg("FavorIso"), py::arg("ContInU"), py::arg("ContInV"), py::arg("PrecisCode"), py::arg("MaxDegInU"), py::arg("MaxDegInV"), py::arg("MaxPatch"), py::arg("Func"), py::arg("UChoice"), py::arg("VChoice"));
cls_AdvApp2Var_ApproxAFunc2Var.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray2OfReal> &, const opencascade::handle<TColStd_HArray2OfReal> &, const opencascade::handle<TColStd_HArray2OfReal> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_IsoType, const GeomAbs_Shape, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const AdvApp2Var_EvaluatorFunc2Var &, const AdvApp2Var_Criterion &, AdvApprox_Cutting &, AdvApprox_Cutting &>(), py::arg("Num1DSS"), py::arg("Num2DSS"), py::arg("Num3DSS"), py::arg("OneDTol"), py::arg("TwoDTol"), py::arg("ThreeDTol"), py::arg("OneDTolFr"), py::arg("TwoDTolFr"), py::arg("ThreeDTolFr"), py::arg("FirstInU"), py::arg("LastInU"), py::arg("FirstInV"), py::arg("LastInV"), py::arg("FavorIso"), py::arg("ContInU"), py::arg("ContInV"), py::arg("PrecisCode"), py::arg("MaxDegInU"), py::arg("MaxDegInV"), py::arg("MaxPatch"), py::arg("Func"), py::arg("Crit"), py::arg("UChoice"), py::arg("VChoice"));

// Fields

// Methods
// cls_AdvApp2Var_ApproxAFunc2Var.def_static("operator new_", (void * (*)(size_t)) &AdvApp2Var_ApproxAFunc2Var::operator new, "None", py::arg("theSize"));
// cls_AdvApp2Var_ApproxAFunc2Var.def_static("operator delete_", (void (*)(void *)) &AdvApp2Var_ApproxAFunc2Var::operator delete, "None", py::arg("theAddress"));
// cls_AdvApp2Var_ApproxAFunc2Var.def_static("operator new[]_", (void * (*)(size_t)) &AdvApp2Var_ApproxAFunc2Var::operator new[], "None", py::arg("theSize"));
// cls_AdvApp2Var_ApproxAFunc2Var.def_static("operator delete[]_", (void (*)(void *)) &AdvApp2Var_ApproxAFunc2Var::operator delete[], "None", py::arg("theAddress"));
// cls_AdvApp2Var_ApproxAFunc2Var.def_static("operator new_", (void * (*)(size_t, void *)) &AdvApp2Var_ApproxAFunc2Var::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AdvApp2Var_ApproxAFunc2Var.def_static("operator delete_", (void (*)(void *, void *)) &AdvApp2Var_ApproxAFunc2Var::operator delete, "None", py::arg(""), py::arg(""));
cls_AdvApp2Var_ApproxAFunc2Var.def("IsDone", (Standard_Boolean (AdvApp2Var_ApproxAFunc2Var::*)() const) &AdvApp2Var_ApproxAFunc2Var::IsDone, "True if the approximation succeeded within the imposed tolerances and the wished continuities");
cls_AdvApp2Var_ApproxAFunc2Var.def("HasResult", (Standard_Boolean (AdvApp2Var_ApproxAFunc2Var::*)() const) &AdvApp2Var_ApproxAFunc2Var::HasResult, "True if the approximation did come out with a result that is not NECESSARELY within the required tolerance or a result that is not recognized with the wished continuities");
cls_AdvApp2Var_ApproxAFunc2Var.def("Surface", (opencascade::handle<Geom_BSplineSurface> (AdvApp2Var_ApproxAFunc2Var::*)(const Standard_Integer) const) &AdvApp2Var_ApproxAFunc2Var::Surface, "returns the BSplineSurface of range Index", py::arg("Index"));
cls_AdvApp2Var_ApproxAFunc2Var.def("UDegree", (Standard_Integer (AdvApp2Var_ApproxAFunc2Var::*)() const) &AdvApp2Var_ApproxAFunc2Var::UDegree, "None");
cls_AdvApp2Var_ApproxAFunc2Var.def("VDegree", (Standard_Integer (AdvApp2Var_ApproxAFunc2Var::*)() const) &AdvApp2Var_ApproxAFunc2Var::VDegree, "None");
cls_AdvApp2Var_ApproxAFunc2Var.def("NumSubSpaces", (Standard_Integer (AdvApp2Var_ApproxAFunc2Var::*)(const Standard_Integer) const) &AdvApp2Var_ApproxAFunc2Var::NumSubSpaces, "None", py::arg("Dimension"));
cls_AdvApp2Var_ApproxAFunc2Var.def("MaxError", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_ApproxAFunc2Var::*)(const Standard_Integer) const) &AdvApp2Var_ApproxAFunc2Var::MaxError, "returns the errors max", py::arg("Dimension"));
cls_AdvApp2Var_ApproxAFunc2Var.def("AverageError", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_ApproxAFunc2Var::*)(const Standard_Integer) const) &AdvApp2Var_ApproxAFunc2Var::AverageError, "returns the average errors", py::arg("Dimension"));
cls_AdvApp2Var_ApproxAFunc2Var.def("UFrontError", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_ApproxAFunc2Var::*)(const Standard_Integer) const) &AdvApp2Var_ApproxAFunc2Var::UFrontError, "returns the errors max on UFrontiers Warning: Dimension must be equal to 3.", py::arg("Dimension"));
cls_AdvApp2Var_ApproxAFunc2Var.def("VFrontError", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_ApproxAFunc2Var::*)(const Standard_Integer) const) &AdvApp2Var_ApproxAFunc2Var::VFrontError, "returns the errors max on VFrontiers Warning: Dimension must be equal to 3.", py::arg("Dimension"));
cls_AdvApp2Var_ApproxAFunc2Var.def("MaxError", (Standard_Real (AdvApp2Var_ApproxAFunc2Var::*)(const Standard_Integer, const Standard_Integer) const) &AdvApp2Var_ApproxAFunc2Var::MaxError, "returns the error max of the BSplineSurface of range Index", py::arg("Dimension"), py::arg("Index"));
cls_AdvApp2Var_ApproxAFunc2Var.def("AverageError", (Standard_Real (AdvApp2Var_ApproxAFunc2Var::*)(const Standard_Integer, const Standard_Integer) const) &AdvApp2Var_ApproxAFunc2Var::AverageError, "returns the average error of the BSplineSurface of range Index", py::arg("Dimension"), py::arg("Index"));
cls_AdvApp2Var_ApproxAFunc2Var.def("UFrontError", (Standard_Real (AdvApp2Var_ApproxAFunc2Var::*)(const Standard_Integer, const Standard_Integer) const) &AdvApp2Var_ApproxAFunc2Var::UFrontError, "returns the error max of the BSplineSurface of range Index on a UFrontier", py::arg("Dimension"), py::arg("Index"));
cls_AdvApp2Var_ApproxAFunc2Var.def("VFrontError", (Standard_Real (AdvApp2Var_ApproxAFunc2Var::*)(const Standard_Integer, const Standard_Integer) const) &AdvApp2Var_ApproxAFunc2Var::VFrontError, "returns the error max of the BSplineSurface of range Index on a VFrontier", py::arg("Dimension"), py::arg("Index"));
cls_AdvApp2Var_ApproxAFunc2Var.def("CritError", (Standard_Real (AdvApp2Var_ApproxAFunc2Var::*)(const Standard_Integer, const Standard_Integer) const) &AdvApp2Var_ApproxAFunc2Var::CritError, "None", py::arg("Dimension"), py::arg("Index"));
cls_AdvApp2Var_ApproxAFunc2Var.def("Dump", (void (AdvApp2Var_ApproxAFunc2Var::*)(Standard_OStream &) const) &AdvApp2Var_ApproxAFunc2Var::Dump, "Prints on the stream o informations on the current state of the object.", py::arg("o"));

// Enums

}