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
#include <AdvApp2Var_CriterionType.hxx>
#include <AdvApp2Var_CriterionRepartition.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <AdvApp2Var_Context.hxx>
#include <AdvApp2Var_EvaluatorFunc2Var.hxx>
#include <AdvApp2Var_Framework.hxx>
#include <AdvApp2Var_Criterion.hxx>
#include <TColgp_HArray2OfPnt.hxx>
#include <AdvApp2Var_Patch.hxx>
#include <NCollection_Sequence.hxx>
#include <AdvApp2Var_SequenceOfPatch.hxx>
#include <TColStd_SequenceOfReal.hxx>
#include <AdvApp2Var_Network.hxx>
#include <gp_XY.hxx>
#include <gp_Pnt.hxx>
#include <AdvApp2Var_Node.hxx>
#include <AdvApp2Var_SequenceOfNode.hxx>
#include <GeomAbs_IsoType.hxx>
#include <AdvApp2Var_Iso.hxx>
#include <AdvApp2Var_Strip.hxx>
#include <AdvApp2Var_SequenceOfStrip.hxx>
#include <GeomAbs_Shape.hxx>
#include <AdvApprox_Cutting.hxx>
#include <Geom_BSplineSurface.hxx>
#include <Standard_OStream.hxx>
#include <TColGeom_HArray1OfSurface.hxx>
#include <AdvApp2Var_ApproxAFunc2Var.hxx>
#include <AdvApp2Var_ApproxF2var.hxx>
#include <AdvApp2Var_Data.hxx>
#include <AdvApp2Var_MathBase.hxx>
#include <AdvApp2Var_SysBase.hxx>
#include <bind_NCollection_Sequence.hxx>

PYBIND11_MODULE(AdvApp2Var, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.gp");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.AdvApprox");
py::module::import("OCCT.Geom");
py::module::import("OCCT.TColGeom");

// ENUM: ADVAPP2VAR_CRITERIONTYPE
py::enum_<AdvApp2Var_CriterionType>(mod, "AdvApp2Var_CriterionType", "influency of the criterion on cutting process//! cutting when criterion is not satisfied desactivation of the compute of the error max//! cutting when error max is not good or if error max is good and criterion is not satisfied")
	.value("AdvApp2Var_Absolute", AdvApp2Var_CriterionType::AdvApp2Var_Absolute)
	.value("AdvApp2Var_Relative", AdvApp2Var_CriterionType::AdvApp2Var_Relative)
	.export_values();


// ENUM: ADVAPP2VAR_CRITERIONREPARTITION
py::enum_<AdvApp2Var_CriterionRepartition>(mod, "AdvApp2Var_CriterionRepartition", "way of cutting process//! all new cutting points at each step of cutting process : (a+i(b-a)/N)i at step N, (a+i(b-a)/(N+1))i at step N+1,... where (a,b) is the global interval//! add one new cutting point at each step of cutting process")
	.value("AdvApp2Var_Regular", AdvApp2Var_CriterionRepartition::AdvApp2Var_Regular)
	.value("AdvApp2Var_Incremental", AdvApp2Var_CriterionRepartition::AdvApp2Var_Incremental)
	.export_values();


// CLASS: ADVAPP2VAR_CONTEXT
py::class_<AdvApp2Var_Context> cls_AdvApp2Var_Context(mod, "AdvApp2Var_Context", "contains all the parameters for approximation ( tolerancy, computing option, ...)");

// Constructors
cls_AdvApp2Var_Context.def(py::init<>());
cls_AdvApp2Var_Context.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray2OfReal> &, const opencascade::handle<TColStd_HArray2OfReal> &, const opencascade::handle<TColStd_HArray2OfReal> &>(), py::arg("ifav"), py::arg("iu"), py::arg("iv"), py::arg("nlimu"), py::arg("nlimv"), py::arg("iprecis"), py::arg("nb1Dss"), py::arg("nb2Dss"), py::arg("nb3Dss"), py::arg("tol1D"), py::arg("tol2D"), py::arg("tol3D"), py::arg("tof1D"), py::arg("tof2D"), py::arg("tof3D"));

// Methods
// cls_AdvApp2Var_Context.def_static("operator new_", (void * (*)(size_t)) &AdvApp2Var_Context::operator new, "None", py::arg("theSize"));
// cls_AdvApp2Var_Context.def_static("operator delete_", (void (*)(void *)) &AdvApp2Var_Context::operator delete, "None", py::arg("theAddress"));
// cls_AdvApp2Var_Context.def_static("operator new[]_", (void * (*)(size_t)) &AdvApp2Var_Context::operator new[], "None", py::arg("theSize"));
// cls_AdvApp2Var_Context.def_static("operator delete[]_", (void (*)(void *)) &AdvApp2Var_Context::operator delete[], "None", py::arg("theAddress"));
// cls_AdvApp2Var_Context.def_static("operator new_", (void * (*)(size_t, void *)) &AdvApp2Var_Context::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AdvApp2Var_Context.def_static("operator delete_", (void (*)(void *, void *)) &AdvApp2Var_Context::operator delete, "None", py::arg(""), py::arg(""));
cls_AdvApp2Var_Context.def("TotalDimension", (Standard_Integer (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::TotalDimension, "None");
cls_AdvApp2Var_Context.def("TotalNumberSSP", (Standard_Integer (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::TotalNumberSSP, "None");
cls_AdvApp2Var_Context.def("FavorIso", (Standard_Integer (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::FavorIso, "None");
cls_AdvApp2Var_Context.def("UOrder", (Standard_Integer (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::UOrder, "None");
cls_AdvApp2Var_Context.def("VOrder", (Standard_Integer (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::VOrder, "None");
cls_AdvApp2Var_Context.def("ULimit", (Standard_Integer (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::ULimit, "None");
cls_AdvApp2Var_Context.def("VLimit", (Standard_Integer (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::VLimit, "None");
cls_AdvApp2Var_Context.def("UJacDeg", (Standard_Integer (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::UJacDeg, "None");
cls_AdvApp2Var_Context.def("VJacDeg", (Standard_Integer (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::VJacDeg, "None");
cls_AdvApp2Var_Context.def("UJacMax", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::UJacMax, "None");
cls_AdvApp2Var_Context.def("VJacMax", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::VJacMax, "None");
cls_AdvApp2Var_Context.def("URoots", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::URoots, "None");
cls_AdvApp2Var_Context.def("VRoots", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::VRoots, "None");
cls_AdvApp2Var_Context.def("UGauss", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::UGauss, "None");
cls_AdvApp2Var_Context.def("VGauss", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::VGauss, "None");
cls_AdvApp2Var_Context.def("IToler", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::IToler, "None");
cls_AdvApp2Var_Context.def("FToler", (opencascade::handle<TColStd_HArray2OfReal> (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::FToler, "None");
cls_AdvApp2Var_Context.def("CToler", (opencascade::handle<TColStd_HArray2OfReal> (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::CToler, "None");

// CLASS: ADVAPP2VAR_EVALUATORFUNC2VAR
py::class_<AdvApp2Var_EvaluatorFunc2Var> cls_AdvApp2Var_EvaluatorFunc2Var(mod, "AdvApp2Var_EvaluatorFunc2Var", "None");

// Methods
cls_AdvApp2Var_EvaluatorFunc2Var.def("Evaluate", [](AdvApp2Var_EvaluatorFunc2Var &self, Standard_Integer * theDimension, Standard_Real * theUStartEnd, Standard_Real * theVStartEnd, Standard_Integer * theFavorIso, Standard_Real * theConstParam, Standard_Integer * theNbParams, Standard_Real * theParameters, Standard_Integer * theUOrder, Standard_Integer * theVOrder, Standard_Real * theResult, Standard_Integer * theErrorCode){ self.Evaluate(theDimension, theUStartEnd, theVStartEnd, theFavorIso, theConstParam, theNbParams, theParameters, theUOrder, theVOrder, theResult, theErrorCode); return std::tuple<Standard_Integer *, Standard_Real *, Standard_Real *, Standard_Integer *, Standard_Real *, Standard_Integer *, Standard_Real *, Standard_Integer *, Standard_Integer *, Standard_Real *, Standard_Integer *>(theDimension, theUStartEnd, theVStartEnd, theFavorIso, theConstParam, theNbParams, theParameters, theUOrder, theVOrder, theResult, theErrorCode); }, "Function evaluation method to be defined by descendant", py::arg("theDimension"), py::arg("theUStartEnd"), py::arg("theVStartEnd"), py::arg("theFavorIso"), py::arg("theConstParam"), py::arg("theNbParams"), py::arg("theParameters"), py::arg("theUOrder"), py::arg("theVOrder"), py::arg("theResult"), py::arg("theErrorCode"));
cls_AdvApp2Var_EvaluatorFunc2Var.def("__call__", [](AdvApp2Var_EvaluatorFunc2Var &self, Standard_Integer * theDimension, Standard_Real * theUStartEnd, Standard_Real * theVStartEnd, Standard_Integer * theFavorIso, Standard_Real * theConstParam, Standard_Integer * theNbParams, Standard_Real * theParameters, Standard_Integer * theUOrder, Standard_Integer * theVOrder, Standard_Real * theResult, Standard_Integer * theErrorCode){ self.operator()(theDimension, theUStartEnd, theVStartEnd, theFavorIso, theConstParam, theNbParams, theParameters, theUOrder, theVOrder, theResult, theErrorCode); return std::tuple<Standard_Integer *, Standard_Real *, Standard_Real *, Standard_Integer *, Standard_Real *, Standard_Integer *, Standard_Real *, Standard_Integer *, Standard_Integer *, Standard_Real *, Standard_Integer *>(theDimension, theUStartEnd, theVStartEnd, theFavorIso, theConstParam, theNbParams, theParameters, theUOrder, theVOrder, theResult, theErrorCode); }, "Shortcut for function-call style usage", py::arg("theDimension"), py::arg("theUStartEnd"), py::arg("theVStartEnd"), py::arg("theFavorIso"), py::arg("theConstParam"), py::arg("theNbParams"), py::arg("theParameters"), py::arg("theUOrder"), py::arg("theVOrder"), py::arg("theResult"), py::arg("theErrorCode"));

// CLASS: ADVAPP2VAR_PATCH
py::class_<AdvApp2Var_Patch> cls_AdvApp2Var_Patch(mod, "AdvApp2Var_Patch", "used to store results on a domain [Ui,Ui+1]x[Vj,Vj+1]");

// Constructors
cls_AdvApp2Var_Patch.def(py::init<>());
cls_AdvApp2Var_Patch.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer>(), py::arg("U0"), py::arg("U1"), py::arg("V0"), py::arg("V1"), py::arg("iu"), py::arg("iv"));

// Methods
// cls_AdvApp2Var_Patch.def_static("operator new_", (void * (*)(size_t)) &AdvApp2Var_Patch::operator new, "None", py::arg("theSize"));
// cls_AdvApp2Var_Patch.def_static("operator delete_", (void (*)(void *)) &AdvApp2Var_Patch::operator delete, "None", py::arg("theAddress"));
// cls_AdvApp2Var_Patch.def_static("operator new[]_", (void * (*)(size_t)) &AdvApp2Var_Patch::operator new[], "None", py::arg("theSize"));
// cls_AdvApp2Var_Patch.def_static("operator delete[]_", (void (*)(void *)) &AdvApp2Var_Patch::operator delete[], "None", py::arg("theAddress"));
// cls_AdvApp2Var_Patch.def_static("operator new_", (void * (*)(size_t, void *)) &AdvApp2Var_Patch::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AdvApp2Var_Patch.def_static("operator delete_", (void (*)(void *, void *)) &AdvApp2Var_Patch::operator delete, "None", py::arg(""), py::arg(""));
cls_AdvApp2Var_Patch.def("IsDiscretised", (Standard_Boolean (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::IsDiscretised, "None");
cls_AdvApp2Var_Patch.def("Discretise", (void (AdvApp2Var_Patch::*)(const AdvApp2Var_Context &, const AdvApp2Var_Framework &, const AdvApp2Var_EvaluatorFunc2Var &)) &AdvApp2Var_Patch::Discretise, "None", py::arg("Conditions"), py::arg("Constraints"), py::arg("func"));
cls_AdvApp2Var_Patch.def("IsApproximated", (Standard_Boolean (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::IsApproximated, "None");
cls_AdvApp2Var_Patch.def("HasResult", (Standard_Boolean (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::HasResult, "None");
cls_AdvApp2Var_Patch.def("MakeApprox", (void (AdvApp2Var_Patch::*)(const AdvApp2Var_Context &, const AdvApp2Var_Framework &, const Standard_Integer)) &AdvApp2Var_Patch::MakeApprox, "None", py::arg("Conditions"), py::arg("Constraints"), py::arg("NumDec"));
cls_AdvApp2Var_Patch.def("AddConstraints", (void (AdvApp2Var_Patch::*)(const AdvApp2Var_Context &, const AdvApp2Var_Framework &)) &AdvApp2Var_Patch::AddConstraints, "None", py::arg("Conditions"), py::arg("Constraints"));
cls_AdvApp2Var_Patch.def("AddErrors", (void (AdvApp2Var_Patch::*)(const AdvApp2Var_Framework &)) &AdvApp2Var_Patch::AddErrors, "None", py::arg("Constraints"));
cls_AdvApp2Var_Patch.def("ChangeDomain", (void (AdvApp2Var_Patch::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &AdvApp2Var_Patch::ChangeDomain, "None", py::arg("a"), py::arg("b"), py::arg("c"), py::arg("d"));
cls_AdvApp2Var_Patch.def("ResetApprox", (void (AdvApp2Var_Patch::*)()) &AdvApp2Var_Patch::ResetApprox, "None");
cls_AdvApp2Var_Patch.def("OverwriteApprox", (void (AdvApp2Var_Patch::*)()) &AdvApp2Var_Patch::OverwriteApprox, "None");
cls_AdvApp2Var_Patch.def("U0", (Standard_Real (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::U0, "None");
cls_AdvApp2Var_Patch.def("U1", (Standard_Real (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::U1, "None");
cls_AdvApp2Var_Patch.def("V0", (Standard_Real (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::V0, "None");
cls_AdvApp2Var_Patch.def("V1", (Standard_Real (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::V1, "None");
cls_AdvApp2Var_Patch.def("UOrder", (Standard_Integer (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::UOrder, "None");
cls_AdvApp2Var_Patch.def("VOrder", (Standard_Integer (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::VOrder, "None");
cls_AdvApp2Var_Patch.def("CutSense", (Standard_Integer (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::CutSense, "None");
cls_AdvApp2Var_Patch.def("CutSense", (Standard_Integer (AdvApp2Var_Patch::*)(const AdvApp2Var_Criterion &, const Standard_Integer) const) &AdvApp2Var_Patch::CutSense, "None", py::arg("Crit"), py::arg("NumDec"));
cls_AdvApp2Var_Patch.def("NbCoeffInU", (Standard_Integer (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::NbCoeffInU, "None");
cls_AdvApp2Var_Patch.def("NbCoeffInV", (Standard_Integer (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::NbCoeffInV, "None");
cls_AdvApp2Var_Patch.def("ChangeNbCoeff", (void (AdvApp2Var_Patch::*)(const Standard_Integer, const Standard_Integer)) &AdvApp2Var_Patch::ChangeNbCoeff, "None", py::arg("NbCoeffU"), py::arg("NbCoeffV"));
cls_AdvApp2Var_Patch.def("Poles", (opencascade::handle<TColgp_HArray2OfPnt> (AdvApp2Var_Patch::*)(const Standard_Integer, const AdvApp2Var_Context &) const) &AdvApp2Var_Patch::Poles, "None", py::arg("SSPIndex"), py::arg("Conditions"));
cls_AdvApp2Var_Patch.def("Coefficients", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_Patch::*)(const Standard_Integer, const AdvApp2Var_Context &) const) &AdvApp2Var_Patch::Coefficients, "None", py::arg("SSPIndex"), py::arg("Conditions"));
cls_AdvApp2Var_Patch.def("MaxErrors", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::MaxErrors, "None");
cls_AdvApp2Var_Patch.def("AverageErrors", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::AverageErrors, "None");
cls_AdvApp2Var_Patch.def("IsoErrors", (opencascade::handle<TColStd_HArray2OfReal> (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::IsoErrors, "None");
cls_AdvApp2Var_Patch.def("CritValue", (Standard_Real (AdvApp2Var_Patch::*)() const) &AdvApp2Var_Patch::CritValue, "None");
cls_AdvApp2Var_Patch.def("SetCritValue", (void (AdvApp2Var_Patch::*)(const Standard_Real)) &AdvApp2Var_Patch::SetCritValue, "None", py::arg("dist"));

// TYPEDEF: ADVAPP2VAR_SEQUENCEOFPATCH
bind_NCollection_Sequence<AdvApp2Var_Patch>(mod, "AdvApp2Var_SequenceOfPatch", py::module_local(false));

// CLASS: ADVAPP2VAR_NETWORK
py::class_<AdvApp2Var_Network> cls_AdvApp2Var_Network(mod, "AdvApp2Var_Network", "None");

// Constructors
cls_AdvApp2Var_Network.def(py::init<>());
cls_AdvApp2Var_Network.def(py::init<const AdvApp2Var_SequenceOfPatch &, const TColStd_SequenceOfReal &, const TColStd_SequenceOfReal &>(), py::arg("Net"), py::arg("TheU"), py::arg("TheV"));

// Methods
// cls_AdvApp2Var_Network.def_static("operator new_", (void * (*)(size_t)) &AdvApp2Var_Network::operator new, "None", py::arg("theSize"));
// cls_AdvApp2Var_Network.def_static("operator delete_", (void (*)(void *)) &AdvApp2Var_Network::operator delete, "None", py::arg("theAddress"));
// cls_AdvApp2Var_Network.def_static("operator new[]_", (void * (*)(size_t)) &AdvApp2Var_Network::operator new[], "None", py::arg("theSize"));
// cls_AdvApp2Var_Network.def_static("operator delete[]_", (void (*)(void *)) &AdvApp2Var_Network::operator delete[], "None", py::arg("theAddress"));
// cls_AdvApp2Var_Network.def_static("operator new_", (void * (*)(size_t, void *)) &AdvApp2Var_Network::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AdvApp2Var_Network.def_static("operator delete_", (void (*)(void *, void *)) &AdvApp2Var_Network::operator delete, "None", py::arg(""), py::arg(""));
cls_AdvApp2Var_Network.def("FirstNotApprox", [](AdvApp2Var_Network &self, Standard_Integer & Index){ Standard_Boolean rv = self.FirstNotApprox(Index); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, Index); }, "search the Index of the first Patch not approximated, if all Patches are approximated Standard_False is returned", py::arg("Index"));
cls_AdvApp2Var_Network.def("ChangePatch", (AdvApp2Var_Patch & (AdvApp2Var_Network::*)(const Standard_Integer)) &AdvApp2Var_Network::ChangePatch, "None", py::arg("Index"));
cls_AdvApp2Var_Network.def("__call__", (AdvApp2Var_Patch & (AdvApp2Var_Network::*)(const Standard_Integer)) &AdvApp2Var_Network::operator(), py::is_operator(), "None", py::arg("Index"));
cls_AdvApp2Var_Network.def("UpdateInU", (void (AdvApp2Var_Network::*)(const Standard_Real)) &AdvApp2Var_Network::UpdateInU, "None", py::arg("CuttingValue"));
cls_AdvApp2Var_Network.def("UpdateInV", (void (AdvApp2Var_Network::*)(const Standard_Real)) &AdvApp2Var_Network::UpdateInV, "None", py::arg("CuttingValue"));
cls_AdvApp2Var_Network.def("SameDegree", [](AdvApp2Var_Network &self, const Standard_Integer iu, const Standard_Integer iv, Standard_Integer & ncfu, Standard_Integer & ncfv){ self.SameDegree(iu, iv, ncfu, ncfv); return std::tuple<Standard_Integer &, Standard_Integer &>(ncfu, ncfv); }, "None", py::arg("iu"), py::arg("iv"), py::arg("ncfu"), py::arg("ncfv"));
cls_AdvApp2Var_Network.def("NbPatch", (Standard_Integer (AdvApp2Var_Network::*)() const) &AdvApp2Var_Network::NbPatch, "None");
cls_AdvApp2Var_Network.def("NbPatchInU", (Standard_Integer (AdvApp2Var_Network::*)() const) &AdvApp2Var_Network::NbPatchInU, "None");
cls_AdvApp2Var_Network.def("NbPatchInV", (Standard_Integer (AdvApp2Var_Network::*)() const) &AdvApp2Var_Network::NbPatchInV, "None");
cls_AdvApp2Var_Network.def("UParameter", (Standard_Real (AdvApp2Var_Network::*)(const Standard_Integer) const) &AdvApp2Var_Network::UParameter, "None", py::arg("Index"));
cls_AdvApp2Var_Network.def("VParameter", (Standard_Real (AdvApp2Var_Network::*)(const Standard_Integer) const) &AdvApp2Var_Network::VParameter, "None", py::arg("Index"));
cls_AdvApp2Var_Network.def("Patch", (const AdvApp2Var_Patch & (AdvApp2Var_Network::*)(const Standard_Integer, const Standard_Integer) const) &AdvApp2Var_Network::Patch, "None", py::arg("UIndex"), py::arg("VIndex"));
cls_AdvApp2Var_Network.def("__call__", (const AdvApp2Var_Patch & (AdvApp2Var_Network::*)(const Standard_Integer, const Standard_Integer) const) &AdvApp2Var_Network::operator(), py::is_operator(), "None", py::arg("UIndex"), py::arg("VIndex"));

// CLASS: ADVAPP2VAR_NODE
py::class_<AdvApp2Var_Node> cls_AdvApp2Var_Node(mod, "AdvApp2Var_Node", "used to store constraints on a (Ui,Vj) point");

// Constructors
cls_AdvApp2Var_Node.def(py::init<>());
cls_AdvApp2Var_Node.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("iu"), py::arg("iv"));
cls_AdvApp2Var_Node.def(py::init<const gp_XY &, const Standard_Integer, const Standard_Integer>(), py::arg("UV"), py::arg("iu"), py::arg("iv"));

// Methods
// cls_AdvApp2Var_Node.def_static("operator new_", (void * (*)(size_t)) &AdvApp2Var_Node::operator new, "None", py::arg("theSize"));
// cls_AdvApp2Var_Node.def_static("operator delete_", (void (*)(void *)) &AdvApp2Var_Node::operator delete, "None", py::arg("theAddress"));
// cls_AdvApp2Var_Node.def_static("operator new[]_", (void * (*)(size_t)) &AdvApp2Var_Node::operator new[], "None", py::arg("theSize"));
// cls_AdvApp2Var_Node.def_static("operator delete[]_", (void (*)(void *)) &AdvApp2Var_Node::operator delete[], "None", py::arg("theAddress"));
// cls_AdvApp2Var_Node.def_static("operator new_", (void * (*)(size_t, void *)) &AdvApp2Var_Node::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AdvApp2Var_Node.def_static("operator delete_", (void (*)(void *, void *)) &AdvApp2Var_Node::operator delete, "None", py::arg(""), py::arg(""));
cls_AdvApp2Var_Node.def("Coord", (gp_XY (AdvApp2Var_Node::*)() const) &AdvApp2Var_Node::Coord, "None");
cls_AdvApp2Var_Node.def("SetCoord", (void (AdvApp2Var_Node::*)(const Standard_Real, const Standard_Real)) &AdvApp2Var_Node::SetCoord, "None", py::arg("x1"), py::arg("x2"));
cls_AdvApp2Var_Node.def("UOrder", (Standard_Integer (AdvApp2Var_Node::*)() const) &AdvApp2Var_Node::UOrder, "None");
cls_AdvApp2Var_Node.def("VOrder", (Standard_Integer (AdvApp2Var_Node::*)() const) &AdvApp2Var_Node::VOrder, "None");
cls_AdvApp2Var_Node.def("SetPoint", (void (AdvApp2Var_Node::*)(const Standard_Integer, const Standard_Integer, const gp_Pnt &)) &AdvApp2Var_Node::SetPoint, "None", py::arg("iu"), py::arg("iv"), py::arg("Cte"));
cls_AdvApp2Var_Node.def("Point", (gp_Pnt (AdvApp2Var_Node::*)(const Standard_Integer, const Standard_Integer) const) &AdvApp2Var_Node::Point, "None", py::arg("iu"), py::arg("iv"));
cls_AdvApp2Var_Node.def("SetError", (void (AdvApp2Var_Node::*)(const Standard_Integer, const Standard_Integer, const Standard_Real)) &AdvApp2Var_Node::SetError, "None", py::arg("iu"), py::arg("iv"), py::arg("error"));
cls_AdvApp2Var_Node.def("Error", (Standard_Real (AdvApp2Var_Node::*)(const Standard_Integer, const Standard_Integer) const) &AdvApp2Var_Node::Error, "None", py::arg("iu"), py::arg("iv"));

// TYPEDEF: ADVAPP2VAR_SEQUENCEOFNODE
bind_NCollection_Sequence<AdvApp2Var_Node>(mod, "AdvApp2Var_SequenceOfNode", py::module_local(false));

// CLASS: ADVAPP2VAR_ISO
py::class_<AdvApp2Var_Iso> cls_AdvApp2Var_Iso(mod, "AdvApp2Var_Iso", "used to store constraints on a line U = Ui or V = Vj");

// Constructors
cls_AdvApp2Var_Iso.def(py::init<>());
// cls_AdvApp2Var_Iso.def(py::init<const GeomAbs_IsoType, const Standard_Integer, const Standard_Integer>(), py::arg("type"), py::arg("iu"), py::arg("iv"));
cls_AdvApp2Var_Iso.def(py::init<const GeomAbs_IsoType, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("type"), py::arg("cte"), py::arg("Ufirst"), py::arg("Ulast"), py::arg("Vfirst"), py::arg("Vlast"), py::arg("pos"), py::arg("iu"), py::arg("iv"));

// Methods
// cls_AdvApp2Var_Iso.def_static("operator new_", (void * (*)(size_t)) &AdvApp2Var_Iso::operator new, "None", py::arg("theSize"));
// cls_AdvApp2Var_Iso.def_static("operator delete_", (void (*)(void *)) &AdvApp2Var_Iso::operator delete, "None", py::arg("theAddress"));
// cls_AdvApp2Var_Iso.def_static("operator new[]_", (void * (*)(size_t)) &AdvApp2Var_Iso::operator new[], "None", py::arg("theSize"));
// cls_AdvApp2Var_Iso.def_static("operator delete[]_", (void (*)(void *)) &AdvApp2Var_Iso::operator delete[], "None", py::arg("theAddress"));
// cls_AdvApp2Var_Iso.def_static("operator new_", (void * (*)(size_t, void *)) &AdvApp2Var_Iso::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AdvApp2Var_Iso.def_static("operator delete_", (void (*)(void *, void *)) &AdvApp2Var_Iso::operator delete, "None", py::arg(""), py::arg(""));
cls_AdvApp2Var_Iso.def("IsApproximated", (Standard_Boolean (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::IsApproximated, "None");
cls_AdvApp2Var_Iso.def("HasResult", (Standard_Boolean (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::HasResult, "None");
cls_AdvApp2Var_Iso.def("MakeApprox", (void (AdvApp2Var_Iso::*)(const AdvApp2Var_Context &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const AdvApp2Var_EvaluatorFunc2Var &, AdvApp2Var_Node &, AdvApp2Var_Node &)) &AdvApp2Var_Iso::MakeApprox, "None", py::arg("Conditions"), py::arg("a"), py::arg("b"), py::arg("c"), py::arg("d"), py::arg("func"), py::arg("NodeBegin"), py::arg("NodeEnd"));
cls_AdvApp2Var_Iso.def("ChangeDomain", (void (AdvApp2Var_Iso::*)(const Standard_Real, const Standard_Real)) &AdvApp2Var_Iso::ChangeDomain, "None", py::arg("a"), py::arg("b"));
cls_AdvApp2Var_Iso.def("ChangeDomain", (void (AdvApp2Var_Iso::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &AdvApp2Var_Iso::ChangeDomain, "None", py::arg("a"), py::arg("b"), py::arg("c"), py::arg("d"));
cls_AdvApp2Var_Iso.def("SetConstante", (void (AdvApp2Var_Iso::*)(const Standard_Real)) &AdvApp2Var_Iso::SetConstante, "None", py::arg("newcte"));
cls_AdvApp2Var_Iso.def("SetPosition", (void (AdvApp2Var_Iso::*)(const Standard_Integer)) &AdvApp2Var_Iso::SetPosition, "None", py::arg("newpos"));
cls_AdvApp2Var_Iso.def("ResetApprox", (void (AdvApp2Var_Iso::*)()) &AdvApp2Var_Iso::ResetApprox, "None");
cls_AdvApp2Var_Iso.def("OverwriteApprox", (void (AdvApp2Var_Iso::*)()) &AdvApp2Var_Iso::OverwriteApprox, "None");
cls_AdvApp2Var_Iso.def("Type", (GeomAbs_IsoType (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::Type, "None");
cls_AdvApp2Var_Iso.def("Constante", (Standard_Real (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::Constante, "None");
cls_AdvApp2Var_Iso.def("T0", (Standard_Real (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::T0, "None");
cls_AdvApp2Var_Iso.def("T1", (Standard_Real (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::T1, "None");
cls_AdvApp2Var_Iso.def("U0", (Standard_Real (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::U0, "None");
cls_AdvApp2Var_Iso.def("U1", (Standard_Real (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::U1, "None");
cls_AdvApp2Var_Iso.def("V0", (Standard_Real (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::V0, "None");
cls_AdvApp2Var_Iso.def("V1", (Standard_Real (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::V1, "None");
cls_AdvApp2Var_Iso.def("UOrder", (Standard_Integer (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::UOrder, "None");
cls_AdvApp2Var_Iso.def("VOrder", (Standard_Integer (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::VOrder, "None");
cls_AdvApp2Var_Iso.def("Position", (Standard_Integer (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::Position, "None");
cls_AdvApp2Var_Iso.def("NbCoeff", (Standard_Integer (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::NbCoeff, "None");
cls_AdvApp2Var_Iso.def("Polynom", (const opencascade::handle<TColStd_HArray1OfReal> & (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::Polynom, "None");
cls_AdvApp2Var_Iso.def("SomTab", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::SomTab, "None");
cls_AdvApp2Var_Iso.def("DifTab", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::DifTab, "None");
cls_AdvApp2Var_Iso.def("MaxErrors", (opencascade::handle<TColStd_HArray2OfReal> (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::MaxErrors, "None");
cls_AdvApp2Var_Iso.def("MoyErrors", (opencascade::handle<TColStd_HArray2OfReal> (AdvApp2Var_Iso::*)() const) &AdvApp2Var_Iso::MoyErrors, "None");

// TYPEDEF: ADVAPP2VAR_STRIP
bind_NCollection_Sequence<AdvApp2Var_Iso>(mod, "AdvApp2Var_Strip", py::module_local(false));

// TYPEDEF: ADVAPP2VAR_SEQUENCEOFSTRIP
bind_NCollection_Sequence<NCollection_Sequence<AdvApp2Var_Iso> >(mod, "AdvApp2Var_SequenceOfStrip", py::module_local(false));

// CLASS: ADVAPP2VAR_FRAMEWORK
py::class_<AdvApp2Var_Framework> cls_AdvApp2Var_Framework(mod, "AdvApp2Var_Framework", "None");

// Constructors
cls_AdvApp2Var_Framework.def(py::init<>());
cls_AdvApp2Var_Framework.def(py::init<const AdvApp2Var_SequenceOfNode &, const AdvApp2Var_SequenceOfStrip &, const AdvApp2Var_SequenceOfStrip &>(), py::arg("Frame"), py::arg("UFrontier"), py::arg("VFrontier"));

// Methods
// cls_AdvApp2Var_Framework.def_static("operator new_", (void * (*)(size_t)) &AdvApp2Var_Framework::operator new, "None", py::arg("theSize"));
// cls_AdvApp2Var_Framework.def_static("operator delete_", (void (*)(void *)) &AdvApp2Var_Framework::operator delete, "None", py::arg("theAddress"));
// cls_AdvApp2Var_Framework.def_static("operator new[]_", (void * (*)(size_t)) &AdvApp2Var_Framework::operator new[], "None", py::arg("theSize"));
// cls_AdvApp2Var_Framework.def_static("operator delete[]_", (void (*)(void *)) &AdvApp2Var_Framework::operator delete[], "None", py::arg("theAddress"));
// cls_AdvApp2Var_Framework.def_static("operator new_", (void * (*)(size_t, void *)) &AdvApp2Var_Framework::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AdvApp2Var_Framework.def_static("operator delete_", (void (*)(void *, void *)) &AdvApp2Var_Framework::operator delete, "None", py::arg(""), py::arg(""));
cls_AdvApp2Var_Framework.def("FirstNotApprox", [](AdvApp2Var_Framework &self, Standard_Integer & IndexIso, Standard_Integer & IndexStrip, AdvApp2Var_Iso & anIso){ Standard_Boolean rv = self.FirstNotApprox(IndexIso, IndexStrip, anIso); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Integer &>(rv, IndexIso, IndexStrip); }, "search the Index of the first Iso not approximated, if all Isos are approximated Standard_False is returned.", py::arg("IndexIso"), py::arg("IndexStrip"), py::arg("anIso"));
cls_AdvApp2Var_Framework.def("FirstNode", (Standard_Integer (AdvApp2Var_Framework::*)(const GeomAbs_IsoType, const Standard_Integer, const Standard_Integer) const) &AdvApp2Var_Framework::FirstNode, "None", py::arg("Type"), py::arg("IndexIso"), py::arg("IndexStrip"));
cls_AdvApp2Var_Framework.def("LastNode", (Standard_Integer (AdvApp2Var_Framework::*)(const GeomAbs_IsoType, const Standard_Integer, const Standard_Integer) const) &AdvApp2Var_Framework::LastNode, "None", py::arg("Type"), py::arg("IndexIso"), py::arg("IndexStrip"));
cls_AdvApp2Var_Framework.def("ChangeIso", (void (AdvApp2Var_Framework::*)(const Standard_Integer, const Standard_Integer, const AdvApp2Var_Iso &)) &AdvApp2Var_Framework::ChangeIso, "None", py::arg("IndexIso"), py::arg("IndexStrip"), py::arg("anIso"));
cls_AdvApp2Var_Framework.def("Node", (const AdvApp2Var_Node & (AdvApp2Var_Framework::*)(const Standard_Integer) const) &AdvApp2Var_Framework::Node, "None", py::arg("IndexNode"));
cls_AdvApp2Var_Framework.def("Node", (const AdvApp2Var_Node & (AdvApp2Var_Framework::*)(const Standard_Real, const Standard_Real) const) &AdvApp2Var_Framework::Node, "None", py::arg("U"), py::arg("V"));
cls_AdvApp2Var_Framework.def("IsoU", (const AdvApp2Var_Iso & (AdvApp2Var_Framework::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &AdvApp2Var_Framework::IsoU, "None", py::arg("U"), py::arg("V0"), py::arg("V1"));
cls_AdvApp2Var_Framework.def("IsoV", (const AdvApp2Var_Iso & (AdvApp2Var_Framework::*)(const Standard_Real, const Standard_Real, const Standard_Real) const) &AdvApp2Var_Framework::IsoV, "None", py::arg("U0"), py::arg("U1"), py::arg("V"));
cls_AdvApp2Var_Framework.def("ChangeNode", (AdvApp2Var_Node & (AdvApp2Var_Framework::*)(const Standard_Integer)) &AdvApp2Var_Framework::ChangeNode, "None", py::arg("IndexNode"));
cls_AdvApp2Var_Framework.def("UpdateInU", (void (AdvApp2Var_Framework::*)(const Standard_Real)) &AdvApp2Var_Framework::UpdateInU, "None", py::arg("CuttingValue"));
cls_AdvApp2Var_Framework.def("UpdateInV", (void (AdvApp2Var_Framework::*)(const Standard_Real)) &AdvApp2Var_Framework::UpdateInV, "None", py::arg("CuttingValue"));
cls_AdvApp2Var_Framework.def("UEquation", (const opencascade::handle<TColStd_HArray1OfReal> & (AdvApp2Var_Framework::*)(const Standard_Integer, const Standard_Integer) const) &AdvApp2Var_Framework::UEquation, "None", py::arg("IndexIso"), py::arg("IndexStrip"));
cls_AdvApp2Var_Framework.def("VEquation", (const opencascade::handle<TColStd_HArray1OfReal> & (AdvApp2Var_Framework::*)(const Standard_Integer, const Standard_Integer) const) &AdvApp2Var_Framework::VEquation, "None", py::arg("IndexIso"), py::arg("IndexStrip"));

// CLASS: ADVAPP2VAR_APPROXAFUNC2VAR
py::class_<AdvApp2Var_ApproxAFunc2Var> cls_AdvApp2Var_ApproxAFunc2Var(mod, "AdvApp2Var_ApproxAFunc2Var", "Perform the approximation of <Func> F(U,V) Arguments are : Num1DSS, Num2DSS, Num3DSS :The numbers of 1,2,3 dimensional subspaces OneDTol, TwoDTol, ThreeDTol: The tolerance of approximation in each subspaces OneDTolFr, TwoDTolFr, ThreeDTolFr: The tolerance of approximation on the boundarys in each subspaces [FirstInU, LastInU]: The Bounds in U of the Approximation [FirstInV, LastInV]: The Bounds in V of the Approximation FavorIso : Give preference to extract u-iso or v-iso on F(U,V) This can be usefull to optimize the <Func> methode ContInU, ContInV : Continuity waiting in u and v PrecisCode : Precision on approximation's error mesurement 1 : Fast computation and average precision 2 : Average computation and good precision 3 : Slow computation and very good precision MaxDegInU : Maximum u-degree waiting in U MaxDegInV : Maximum u-degree waiting in V Warning: MaxDegInU (resp. MaxDegInV) must be >= 2*iu (resp. iv) + 1, where iu (resp. iv) = 0 if ContInU (resp. ContInV) = GeomAbs_C0, = 1 if = GeomAbs_C1, = 2 if = GeomAbs_C2. MaxPatch : Maximun number of Patch waiting number of Patch is number of u span * number of v span Func : The external method to evaluate F(U,V) Crit : To (re)defined condition of convergence UChoice, VChoice : To define the way in U (or V) Knot insertion Warning: for the moment, the result is a 3D Surface so Num1DSS and Num2DSS must be equals to 0 and Num3DSS must be equal to 1. Warning: the Function of type EvaluatorFunc2Var from Approx must be a subclass of AdvApp2Var_EvaluatorFunc2Var");

// Constructors
cls_AdvApp2Var_ApproxAFunc2Var.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray2OfReal> &, const opencascade::handle<TColStd_HArray2OfReal> &, const opencascade::handle<TColStd_HArray2OfReal> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_IsoType, const GeomAbs_Shape, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const AdvApp2Var_EvaluatorFunc2Var &, AdvApprox_Cutting &, AdvApprox_Cutting &>(), py::arg("Num1DSS"), py::arg("Num2DSS"), py::arg("Num3DSS"), py::arg("OneDTol"), py::arg("TwoDTol"), py::arg("ThreeDTol"), py::arg("OneDTolFr"), py::arg("TwoDTolFr"), py::arg("ThreeDTolFr"), py::arg("FirstInU"), py::arg("LastInU"), py::arg("FirstInV"), py::arg("LastInV"), py::arg("FavorIso"), py::arg("ContInU"), py::arg("ContInV"), py::arg("PrecisCode"), py::arg("MaxDegInU"), py::arg("MaxDegInV"), py::arg("MaxPatch"), py::arg("Func"), py::arg("UChoice"), py::arg("VChoice"));
cls_AdvApp2Var_ApproxAFunc2Var.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray2OfReal> &, const opencascade::handle<TColStd_HArray2OfReal> &, const opencascade::handle<TColStd_HArray2OfReal> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const GeomAbs_IsoType, const GeomAbs_Shape, const GeomAbs_Shape, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const AdvApp2Var_EvaluatorFunc2Var &, const AdvApp2Var_Criterion &, AdvApprox_Cutting &, AdvApprox_Cutting &>(), py::arg("Num1DSS"), py::arg("Num2DSS"), py::arg("Num3DSS"), py::arg("OneDTol"), py::arg("TwoDTol"), py::arg("ThreeDTol"), py::arg("OneDTolFr"), py::arg("TwoDTolFr"), py::arg("ThreeDTolFr"), py::arg("FirstInU"), py::arg("LastInU"), py::arg("FirstInV"), py::arg("LastInV"), py::arg("FavorIso"), py::arg("ContInU"), py::arg("ContInV"), py::arg("PrecisCode"), py::arg("MaxDegInU"), py::arg("MaxDegInV"), py::arg("MaxPatch"), py::arg("Func"), py::arg("Crit"), py::arg("UChoice"), py::arg("VChoice"));

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

// CLASS: ADVAPP2VAR_APPROXF2VAR
py::class_<AdvApp2Var_ApproxF2var> cls_AdvApp2Var_ApproxF2var(mod, "AdvApp2Var_ApproxF2var", "None");

// Constructors
cls_AdvApp2Var_ApproxF2var.def(py::init<>());

// Methods
cls_AdvApp2Var_ApproxF2var.def_static("mma2fnc__", (int (*)(integer *, integer *, integer *, doublereal *, const AdvApp2Var_EvaluatorFunc2Var &, doublereal *, integer *, integer *, doublereal *, integer *, integer *, integer *, integer *, integer *, doublereal *, integer *, doublereal *, integer *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, integer *)) &AdvApp2Var_ApproxF2var::mma2fnc_, "None", py::arg("ndimen"), py::arg("nbsesp"), py::arg("ndimse"), py::arg("uvfonc"), py::arg("foncnp"), py::arg("tconst"), py::arg("isofav"), py::arg("nbroot"), py::arg("rootlg"), py::arg("iordre"), py::arg("ideriv"), py::arg("ndgjac"), py::arg("nbcrmx"), py::arg("ncflim"), py::arg("epsapr"), py::arg("ncoeff"), py::arg("courbe"), py::arg("nbcrbe"), py::arg("somtab"), py::arg("diftab"), py::arg("contr1"), py::arg("contr2"), py::arg("tabdec"), py::arg("errmax"), py::arg("errmoy"), py::arg("iercod"));
cls_AdvApp2Var_ApproxF2var.def_static("mma2roo__", (int (*)(integer *, integer *, doublereal *, doublereal *)) &AdvApp2Var_ApproxF2var::mma2roo_, "None", py::arg("nbpntu"), py::arg("nbpntv"), py::arg("urootl"), py::arg("vrootl"));
cls_AdvApp2Var_ApproxF2var.def_static("mma2jmx__", (int (*)(integer *, integer *, doublereal *)) &AdvApp2Var_ApproxF2var::mma2jmx_, "None", py::arg("ndgjac"), py::arg("iordre"), py::arg("xjacmx"));
cls_AdvApp2Var_ApproxF2var.def_static("mmapptt__", (int (*)(const integer *, const integer *, const integer *, doublereal *, integer *)) &AdvApp2Var_ApproxF2var::mmapptt_, "None", py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""));
cls_AdvApp2Var_ApproxF2var.def_static("mma2cdi__", (int (*)(integer *, integer *, doublereal *, integer *, doublereal *, integer *, integer *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, integer *)) &AdvApp2Var_ApproxF2var::mma2cdi_, "None", py::arg("ndimen"), py::arg("nbpntu"), py::arg("urootl"), py::arg("nbpntv"), py::arg("vrootl"), py::arg("iordru"), py::arg("iordrv"), py::arg("contr1"), py::arg("contr2"), py::arg("contr3"), py::arg("contr4"), py::arg("sotbu1"), py::arg("sotbu2"), py::arg("ditbu1"), py::arg("ditbu2"), py::arg("sotbv1"), py::arg("sotbv2"), py::arg("ditbv1"), py::arg("ditbv2"), py::arg("sosotb"), py::arg("soditb"), py::arg("disotb"), py::arg("diditb"), py::arg("iercod"));
cls_AdvApp2Var_ApproxF2var.def_static("mma2ds1__", (int (*)(integer *, doublereal *, doublereal *, const AdvApp2Var_EvaluatorFunc2Var &, integer *, integer *, doublereal *, doublereal *, integer *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, integer *)) &AdvApp2Var_ApproxF2var::mma2ds1_, "None", py::arg("ndimen"), py::arg("uintfn"), py::arg("vintfn"), py::arg("foncnp"), py::arg("nbpntu"), py::arg("nbpntv"), py::arg("urootb"), py::arg("vrootb"), py::arg("isofav"), py::arg("sosotb"), py::arg("disotb"), py::arg("soditb"), py::arg("diditb"), py::arg("fpntab"), py::arg("ttable"), py::arg("iercod"));
cls_AdvApp2Var_ApproxF2var.def_static("mma2ce1__", (int (*)(integer *, integer *, integer *, integer *, integer *, integer *, integer *, integer *, integer *, integer *, integer *, integer *, integer *, integer *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, integer *, integer *, integer *, integer *)) &AdvApp2Var_ApproxF2var::mma2ce1_, "None", py::arg("numdec"), py::arg("ndimen"), py::arg("nbsesp"), py::arg("ndimse"), py::arg("ndminu"), py::arg("ndminv"), py::arg("ndguli"), py::arg("ndgvli"), py::arg("ndjacu"), py::arg("ndjacv"), py::arg("iordru"), py::arg("iordrv"), py::arg("nbpntu"), py::arg("nbpntv"), py::arg("epsapr"), py::arg("sosotb"), py::arg("disotb"), py::arg("soditb"), py::arg("diditb"), py::arg("patjac"), py::arg("errmax"), py::arg("errmoy"), py::arg("ndegpu"), py::arg("ndegpv"), py::arg("itydec"), py::arg("iercod"));
cls_AdvApp2Var_ApproxF2var.def_static("mma2can__", (int (*)(const integer *, const integer *, const integer *, const integer *, const integer *, const integer *, const integer *, const doublereal *, doublereal *, doublereal *, integer *)) &AdvApp2Var_ApproxF2var::mma2can_, "None", py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""));
cls_AdvApp2Var_ApproxF2var.def_static("mma1her__", (int (*)(const integer *, doublereal *, integer *)) &AdvApp2Var_ApproxF2var::mma1her_, "None", py::arg(""), py::arg(""), py::arg(""));
cls_AdvApp2Var_ApproxF2var.def_static("mma2ac2__", (int (*)(const integer *, const integer *, const integer *, const integer *, const integer *, const integer *, const doublereal *, const integer *, const doublereal *, const doublereal *, doublereal *)) &AdvApp2Var_ApproxF2var::mma2ac2_, "None", py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""));
cls_AdvApp2Var_ApproxF2var.def_static("mma2ac3__", (int (*)(const integer *, const integer *, const integer *, const integer *, const integer *, const integer *, const doublereal *, const integer *, const doublereal *, const doublereal *, doublereal *)) &AdvApp2Var_ApproxF2var::mma2ac3_, "None", py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""));
cls_AdvApp2Var_ApproxF2var.def_static("mma2ac1__", (int (*)(const integer *, const integer *, const integer *, const integer *, const integer *, const doublereal *, const doublereal *, const doublereal *, const doublereal *, const doublereal *, const doublereal *, doublereal *)) &AdvApp2Var_ApproxF2var::mma2ac1_, "None", py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""));
cls_AdvApp2Var_ApproxF2var.def_static("mma2fx6__", (int (*)(integer *, integer *, integer *, integer *, integer *, integer *, integer *, integer *, integer *, doublereal *, doublereal *, doublereal *, doublereal *, integer *, integer *)) &AdvApp2Var_ApproxF2var::mma2fx6_, "None", py::arg("ncfmxu"), py::arg("ncfmxv"), py::arg("ndimen"), py::arg("nbsesp"), py::arg("ndimse"), py::arg("nbupat"), py::arg("nbvpat"), py::arg("iordru"), py::arg("iordrv"), py::arg("epsapr"), py::arg("epsfro"), py::arg("patcan"), py::arg("errmax"), py::arg("ncoefu"), py::arg("ncoefv"));

// CLASS: ADVAPP2VAR_CRITERION
py::class_<AdvApp2Var_Criterion> cls_AdvApp2Var_Criterion(mod, "AdvApp2Var_Criterion", "this class contains a given criterion to be satisfied");

// Methods
// cls_AdvApp2Var_Criterion.def_static("operator new_", (void * (*)(size_t)) &AdvApp2Var_Criterion::operator new, "None", py::arg("theSize"));
// cls_AdvApp2Var_Criterion.def_static("operator delete_", (void (*)(void *)) &AdvApp2Var_Criterion::operator delete, "None", py::arg("theAddress"));
// cls_AdvApp2Var_Criterion.def_static("operator new[]_", (void * (*)(size_t)) &AdvApp2Var_Criterion::operator new[], "None", py::arg("theSize"));
// cls_AdvApp2Var_Criterion.def_static("operator delete[]_", (void (*)(void *)) &AdvApp2Var_Criterion::operator delete[], "None", py::arg("theAddress"));
// cls_AdvApp2Var_Criterion.def_static("operator new_", (void * (*)(size_t, void *)) &AdvApp2Var_Criterion::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AdvApp2Var_Criterion.def_static("operator delete_", (void (*)(void *, void *)) &AdvApp2Var_Criterion::operator delete, "None", py::arg(""), py::arg(""));
cls_AdvApp2Var_Criterion.def("Value", (void (AdvApp2Var_Criterion::*)(AdvApp2Var_Patch &, const AdvApp2Var_Context &) const) &AdvApp2Var_Criterion::Value, "None", py::arg("P"), py::arg("C"));
cls_AdvApp2Var_Criterion.def("IsSatisfied", (Standard_Boolean (AdvApp2Var_Criterion::*)(const AdvApp2Var_Patch &) const) &AdvApp2Var_Criterion::IsSatisfied, "None", py::arg("P"));
cls_AdvApp2Var_Criterion.def("MaxValue", (Standard_Real (AdvApp2Var_Criterion::*)() const) &AdvApp2Var_Criterion::MaxValue, "None");
cls_AdvApp2Var_Criterion.def("Type", (AdvApp2Var_CriterionType (AdvApp2Var_Criterion::*)() const) &AdvApp2Var_Criterion::Type, "None");
cls_AdvApp2Var_Criterion.def("Repartition", (AdvApp2Var_CriterionRepartition (AdvApp2Var_Criterion::*)() const) &AdvApp2Var_Criterion::Repartition, "None");

// CLASS: MDNOMBR_1_
py::class_<mdnombr_1_> cls_mdnombr_1_(mod, "mdnombr_1_", "None");

// Constructors
cls_mdnombr_1_.def(py::init<>());

// Fields
cls_mdnombr_1_.def_readwrite("pi", &mdnombr_1_::pi, "None");
cls_mdnombr_1_.def_readwrite("deuxpi", &mdnombr_1_::deuxpi, "None");
cls_mdnombr_1_.def_readwrite("pisur2", &mdnombr_1_::pisur2, "None");
cls_mdnombr_1_.def_readwrite("pis180", &mdnombr_1_::pis180, "None");
cls_mdnombr_1_.def_readwrite("c180pi", &mdnombr_1_::c180pi, "None");
cls_mdnombr_1_.def_readwrite("zero", &mdnombr_1_::zero, "None");
cls_mdnombr_1_.def_readwrite("one", &mdnombr_1_::one, "None");
cls_mdnombr_1_.def_readwrite("a180", &mdnombr_1_::a180, "None");
cls_mdnombr_1_.def_readwrite("a360", &mdnombr_1_::a360, "None");
cls_mdnombr_1_.def_readwrite("a90", &mdnombr_1_::a90, "None");

// CLASS: MINOMBR_1_
py::class_<minombr_1_> cls_minombr_1_(mod, "minombr_1_", "None");

// Constructors
cls_minombr_1_.def(py::init<>());

// Fields
// cls_minombr_1_.def_readwrite("nbr", &minombr_1_::nbr, "None");

// CLASS: MAOVPAR_1_
py::class_<maovpar_1_> cls_maovpar_1_(mod, "maovpar_1_", "None");

// Constructors
cls_maovpar_1_.def(py::init<>());

// Fields
cls_maovpar_1_.def_readwrite("r8und", &maovpar_1_::r8und, "None");
cls_maovpar_1_.def_readwrite("r8ovr", &maovpar_1_::r8ovr, "None");
cls_maovpar_1_.def_readwrite("x4und", &maovpar_1_::x4und, "None");
cls_maovpar_1_.def_readwrite("x4ovr", &maovpar_1_::x4ovr, "None");
cls_maovpar_1_.def_readwrite("r4und", &maovpar_1_::r4und, "None");
cls_maovpar_1_.def_readwrite("r4ovr", &maovpar_1_::r4ovr, "None");
cls_maovpar_1_.def_readwrite("r4nbe", &maovpar_1_::r4nbe, "None");
cls_maovpar_1_.def_readwrite("r8nbm", &maovpar_1_::r8nbm, "None");
cls_maovpar_1_.def_readwrite("r8nbe", &maovpar_1_::r8nbe, "None");
cls_maovpar_1_.def_readwrite("i4ovr", &maovpar_1_::i4ovr, "None");
cls_maovpar_1_.def_readwrite("i4ovn", &maovpar_1_::i4ovn, "None");
cls_maovpar_1_.def_readwrite("r4exp", &maovpar_1_::r4exp, "None");
cls_maovpar_1_.def_readwrite("r8exp", &maovpar_1_::r8exp, "None");
cls_maovpar_1_.def_readwrite("r4exn", &maovpar_1_::r4exn, "None");
cls_maovpar_1_.def_readwrite("r8exn", &maovpar_1_::r8exn, "None");
cls_maovpar_1_.def_readwrite("r4ncs", &maovpar_1_::r4ncs, "None");
cls_maovpar_1_.def_readwrite("r8ncs", &maovpar_1_::r8ncs, "None");
cls_maovpar_1_.def_readwrite("r4nbm", &maovpar_1_::r4nbm, "None");
cls_maovpar_1_.def_readwrite("i2ovr", &maovpar_1_::i2ovr, "None");
cls_maovpar_1_.def_readwrite("i2ovn", &maovpar_1_::i2ovn, "None");

// CLASS: MAOVPCH_1_
py::class_<maovpch_1_> cls_maovpch_1_(mod, "maovpch_1_", "None");

// Constructors
cls_maovpch_1_.def(py::init<>());

// Fields
// cls_maovpch_1_.def_readwrite("cnmmac", &maovpch_1_::cnmmac, "None");
// cls_maovpch_1_.def_readwrite("frmr4", &maovpch_1_::frmr4, "None");
// cls_maovpch_1_.def_readwrite("frmr8", &maovpch_1_::frmr8, "None");
// cls_maovpch_1_.def_readwrite("cdcode", &maovpch_1_::cdcode, "None");

// CLASS: MLGDRTL_1_
py::class_<mlgdrtl_1_> cls_mlgdrtl_1_(mod, "mlgdrtl_1_", "None");

// Constructors
cls_mlgdrtl_1_.def(py::init<>());

// Fields
// cls_mlgdrtl_1_.def_readwrite("rootab", &mlgdrtl_1_::rootab, "None");
// cls_mlgdrtl_1_.def_readwrite("hiltab", &mlgdrtl_1_::hiltab, "None");
// cls_mlgdrtl_1_.def_readwrite("hi0tab", &mlgdrtl_1_::hi0tab, "None");

// CLASS: MMJCOBI_1_
py::class_<mmjcobi_1_> cls_mmjcobi_1_(mod, "mmjcobi_1_", "None");

// Constructors
cls_mmjcobi_1_.def(py::init<>());

// Fields
// cls_mmjcobi_1_.def_readwrite("plgcan", &mmjcobi_1_::plgcan, "None");
// cls_mmjcobi_1_.def_readwrite("canjac", &mmjcobi_1_::canjac, "None");

// CLASS: MMCMCNP_1_
py::class_<mmcmcnp_1_> cls_mmcmcnp_1_(mod, "mmcmcnp_1_", "None");

// Constructors
cls_mmcmcnp_1_.def(py::init<>());

// Fields
// cls_mmcmcnp_1_.def_readwrite("cnp", &mmcmcnp_1_::cnp, "None");

// CLASS: MMAPGSS_1_
py::class_<mmapgss_1_> cls_mmapgss_1_(mod, "mmapgss_1_", "None");

// Constructors
cls_mmapgss_1_.def(py::init<>());

// Fields
// cls_mmapgss_1_.def_readwrite("gslxjs", &mmapgss_1_::gslxjs, "None");
// cls_mmapgss_1_.def_readwrite("gsl0js", &mmapgss_1_::gsl0js, "None");

// CLASS: MMAPGS0_1_
py::class_<mmapgs0_1_> cls_mmapgs0_1_(mod, "mmapgs0_1_", "None");

// Constructors
cls_mmapgs0_1_.def(py::init<>());

// Fields
// cls_mmapgs0_1_.def_readwrite("gslxj0", &mmapgs0_1_::gslxj0, "None");
// cls_mmapgs0_1_.def_readwrite("gsl0j0", &mmapgs0_1_::gsl0j0, "None");

// CLASS: MMAPGS1_1_
py::class_<mmapgs1_1_> cls_mmapgs1_1_(mod, "mmapgs1_1_", "None");

// Constructors
cls_mmapgs1_1_.def(py::init<>());

// Fields
// cls_mmapgs1_1_.def_readwrite("gslxj1", &mmapgs1_1_::gslxj1, "None");
// cls_mmapgs1_1_.def_readwrite("gsl0j1", &mmapgs1_1_::gsl0j1, "None");

// CLASS: MMAPGS2_1_
py::class_<mmapgs2_1_> cls_mmapgs2_1_(mod, "mmapgs2_1_", "None");

// Constructors
cls_mmapgs2_1_.def(py::init<>());

// Fields
// cls_mmapgs2_1_.def_readwrite("gslxj2", &mmapgs2_1_::gslxj2, "None");
// cls_mmapgs2_1_.def_readwrite("gsl0j2", &mmapgs2_1_::gsl0j2, "None");

// CLASS: ADVAPP2VAR_DATA
py::class_<AdvApp2Var_Data> cls_AdvApp2Var_Data(mod, "AdvApp2Var_Data", "/");

// Constructors
cls_AdvApp2Var_Data.def(py::init<>());

// Methods
cls_AdvApp2Var_Data.def_static("Getmdnombr_", (mdnombr_1_ & (*)()) &AdvApp2Var_Data::Getmdnombr, "None");
cls_AdvApp2Var_Data.def_static("Getminombr_", (minombr_1_ & (*)()) &AdvApp2Var_Data::Getminombr, "None");
cls_AdvApp2Var_Data.def_static("Getmaovpar_", (maovpar_1_ & (*)()) &AdvApp2Var_Data::Getmaovpar, "None");
cls_AdvApp2Var_Data.def_static("Getmaovpch_", (maovpch_1_ & (*)()) &AdvApp2Var_Data::Getmaovpch, "None");
cls_AdvApp2Var_Data.def_static("Getmlgdrtl_", (mlgdrtl_1_ & (*)()) &AdvApp2Var_Data::Getmlgdrtl, "None");
cls_AdvApp2Var_Data.def_static("Getmmjcobi_", (mmjcobi_1_ & (*)()) &AdvApp2Var_Data::Getmmjcobi, "None");
cls_AdvApp2Var_Data.def_static("Getmmcmcnp_", (mmcmcnp_1_ & (*)()) &AdvApp2Var_Data::Getmmcmcnp, "None");
cls_AdvApp2Var_Data.def_static("Getmmapgss_", (mmapgss_1_ & (*)()) &AdvApp2Var_Data::Getmmapgss, "None");
cls_AdvApp2Var_Data.def_static("Getmmapgs0_", (mmapgs0_1_ & (*)()) &AdvApp2Var_Data::Getmmapgs0, "None");
cls_AdvApp2Var_Data.def_static("Getmmapgs1_", (mmapgs1_1_ & (*)()) &AdvApp2Var_Data::Getmmapgs1, "None");
cls_AdvApp2Var_Data.def_static("Getmmapgs2_", (mmapgs2_1_ & (*)()) &AdvApp2Var_Data::Getmmapgs2, "None");

// CLASS: ADVAPP2VAR_MATHBASE
py::class_<AdvApp2Var_MathBase> cls_AdvApp2Var_MathBase(mod, "AdvApp2Var_MathBase", "None");

// Constructors
cls_AdvApp2Var_MathBase.def(py::init<>());

// Methods
cls_AdvApp2Var_MathBase.def_static("mmapcmp__", (int (*)(integer *, integer *, integer *, double *, double *)) &AdvApp2Var_MathBase::mmapcmp_, "", py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""));
cls_AdvApp2Var_MathBase.def_static("mmdrc11__", (int (*)(integer *, integer *, integer *, doublereal *, doublereal *, doublereal *)) &AdvApp2Var_MathBase::mmdrc11_, "None", py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""));
cls_AdvApp2Var_MathBase.def_static("mmfmca9__", (int (*)(integer *, integer *, integer *, integer *, integer *, integer *, doublereal *, doublereal *)) &AdvApp2Var_MathBase::mmfmca9_, "None", py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""));
cls_AdvApp2Var_MathBase.def_static("mmfmcb5__", (int (*)(integer *, integer *, integer *, doublereal *, integer *, integer *, integer *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmfmcb5_, "None", py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""));
cls_AdvApp2Var_MathBase.def_static("mmwprcs__", (void (*)(doublereal *, doublereal *, doublereal *, doublereal *, integer *, integer *)) &AdvApp2Var_MathBase::mmwprcs_, "None", py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""), py::arg(""));
cls_AdvApp2Var_MathBase.def_static("mmcglc1__", (int (*)(integer *, integer *, integer *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmcglc1_, "", py::arg("ndimax"), py::arg("ndimen"), py::arg("ncoeff"), py::arg("courbe"), py::arg("tdebut"), py::arg("tfinal"), py::arg("epsiln"), py::arg("xlongc"), py::arg("erreur"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mmbulld__", (int (*)(integer *, integer *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmbulld_, "None", py::arg("nbcoln"), py::arg("nblign"), py::arg("dtabtr"), py::arg("numcle"));
cls_AdvApp2Var_MathBase.def_static("mmcdriv__", (int (*)(integer *, integer *, doublereal *, integer *, integer *, doublereal *)) &AdvApp2Var_MathBase::mmcdriv_, "None", py::arg("ndimen"), py::arg("ncoeff"), py::arg("courbe"), py::arg("ideriv"), py::arg("ncofdv"), py::arg("crvdrv"));
cls_AdvApp2Var_MathBase.def_static("mmcvctx__", (int (*)(integer *, integer *, integer *, doublereal *, doublereal *, doublereal *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmcvctx_, "None", py::arg("ndimen"), py::arg("ncofmx"), py::arg("nderiv"), py::arg("ctrtes"), py::arg("crvres"), py::arg("tabaux"), py::arg("xmatri"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mdsptpt__", (int (*)(integer *, doublereal *, doublereal *, doublereal *)) &AdvApp2Var_MathBase::mdsptpt_, "None", py::arg("ndimen"), py::arg("point1"), py::arg("point2"), py::arg("distan"));
cls_AdvApp2Var_MathBase.def_static("mmaperx__", (int (*)(integer *, integer *, integer *, integer *, doublereal *, integer *, doublereal *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmaperx_, "None", py::arg("ncofmx"), py::arg("ndimen"), py::arg("ncoeff"), py::arg("iordre"), py::arg("crvjac"), py::arg("ncfnew"), py::arg("ycvmax"), py::arg("errmax"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mmdrvck__", (int (*)(integer *, integer *, doublereal *, integer *, doublereal *, doublereal *)) &AdvApp2Var_MathBase::mmdrvck_, "None", py::arg("ncoeff"), py::arg("ndimen"), py::arg("courbe"), py::arg("ideriv"), py::arg("tparam"), py::arg("pntcrb"));
cls_AdvApp2Var_MathBase.def_static("mmeps1__", (int (*)(doublereal *)) &AdvApp2Var_MathBase::mmeps1_, "None", py::arg("epsilo"));
cls_AdvApp2Var_MathBase.def_static("mmfmca8__", (int (*)(const integer *, const integer *, const integer *, const integer *, const integer *, const integer *, doublereal *, doublereal *)) &AdvApp2Var_MathBase::mmfmca8_, "None", py::arg("ndimen"), py::arg("ncoefu"), py::arg("ncoefv"), py::arg("ndimax"), py::arg("ncfumx"), py::arg("ncfvmx"), py::arg("tabini"), py::arg("tabres"));
cls_AdvApp2Var_MathBase.def_static("mmfmcar__", (int (*)(integer *, integer *, integer *, integer *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmfmcar_, "None", py::arg("ndimen"), py::arg("ncofmx"), py::arg("ncoefu"), py::arg("ncoefv"), py::arg("patold"), py::arg("upara1"), py::arg("upara2"), py::arg("vpara1"), py::arg("vpara2"), py::arg("patnew"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mmfmtb1__", (int (*)(integer *, doublereal *, integer *, integer *, integer *, doublereal *, integer *, integer *, integer *)) &AdvApp2Var_MathBase::mmfmtb1_, "None", py::arg("maxsz1"), py::arg("table1"), py::arg("isize1"), py::arg("jsize1"), py::arg("maxsz2"), py::arg("table2"), py::arg("isize2"), py::arg("jsize2"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mmgaus1__", (int (*)(integer *, int (*)(integer *, doublereal *, doublereal *, integer *), integer *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, integer *, integer *)) &AdvApp2Var_MathBase::mmgaus1_, "None", py::arg("ndimf"), py::arg("bfunx"), py::arg("k"), py::arg("xd"), py::arg("xf"), py::arg("saux1"), py::arg("saux2"), py::arg("somme"), py::arg("niter"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mmhjcan__", (int (*)(integer *, integer *, integer *, integer *, integer *, doublereal *, doublereal *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmhjcan_, "None", py::arg("ndimen"), py::arg("ncourb"), py::arg("ncftab"), py::arg("orcont"), py::arg("ncflim"), py::arg("tcbold"), py::arg("tdecop"), py::arg("tcbnew"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mminltt__", (int (*)(integer *, integer *, doublereal *, integer *, integer *, doublereal *, doublereal *, integer *)) &AdvApp2Var_MathBase::mminltt_, "None", py::arg("ncolmx"), py::arg("nlgnmx"), py::arg("tabtri"), py::arg("nbrcol"), py::arg("nbrlgn"), py::arg("ajoute"), py::arg("epseg"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mmjaccv__", (int (*)(const integer *, const integer *, const integer *, const doublereal *, doublereal *, doublereal *)) &AdvApp2Var_MathBase::mmjaccv_, "None", py::arg("ncoef"), py::arg("ndim"), py::arg("ider"), py::arg("crvlgd"), py::arg("polaux"), py::arg("crvcan"));
cls_AdvApp2Var_MathBase.def_static("mmpobas__", (int (*)(doublereal *, integer *, integer *, integer *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmpobas_, "None", py::arg("tparam"), py::arg("iordre"), py::arg("ncoeff"), py::arg("nderiv"), py::arg("valbas"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mmmpocur__", (int (*)(integer *, integer *, integer *, doublereal *, doublereal *, doublereal *)) &AdvApp2Var_MathBase::mmmpocur_, "None", py::arg("ncofmx"), py::arg("ndim"), py::arg("ndeg"), py::arg("courbe"), py::arg("tparam"), py::arg("tabval"));
cls_AdvApp2Var_MathBase.def_static("mmposui__", (int (*)(integer *, integer *, integer *, integer *, integer *)) &AdvApp2Var_MathBase::mmposui_, "None", py::arg("dimmat"), py::arg("nistoc"), py::arg("aposit"), py::arg("posuiv"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mmresol__", (int (*)(integer *, integer *, integer *, integer *, integer *, doublereal *, doublereal *, doublereal *, doublereal *, integer *, integer *, integer *, integer *, integer *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmresol_, "None", py::arg("hdimen"), py::arg("gdimen"), py::arg("hnstoc"), py::arg("gnstoc"), py::arg("mnstoc"), py::arg("matsyh"), py::arg("matsyg"), py::arg("vecsyh"), py::arg("vecsyg"), py::arg("hposit"), py::arg("hposui"), py::arg("gposit"), py::arg("mmposui"), py::arg("mposit"), py::arg("vecsol"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mmrtptt__", (int (*)(integer *, doublereal *)) &AdvApp2Var_MathBase::mmrtptt_, "None", py::arg("ndglgd"), py::arg("rtlegd"));
cls_AdvApp2Var_MathBase.def_static("mmsrre2__", (int (*)(doublereal *, integer *, doublereal *, doublereal *, integer *, integer *, integer *)) &AdvApp2Var_MathBase::mmsrre2_, "None", py::arg("tparam"), py::arg("nbrval"), py::arg("tablev"), py::arg("epsil"), py::arg("numint"), py::arg("itypen"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mmtrpjj__", (int (*)(integer *, integer *, integer *, doublereal *, integer *, doublereal *, doublereal *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmtrpjj_, "None", py::arg("ncofmx"), py::arg("ndimen"), py::arg("ncoeff"), py::arg("epsi3d"), py::arg("iordre"), py::arg("crvlgd"), py::arg("ycvmax"), py::arg("errmax"), py::arg("ncfnew"));
cls_AdvApp2Var_MathBase.def_static("mmunivt__", (int (*)(integer *, doublereal *, doublereal *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmunivt_, "None", py::arg("ndimen"), py::arg("vector"), py::arg("vecnrm"), py::arg("epsiln"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mmvncol__", (int (*)(integer *, doublereal *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmvncol_, "None", py::arg("ndimen"), py::arg("vecin"), py::arg("vecout"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("msc__", (doublereal (*)(integer *, doublereal *, doublereal *)) &AdvApp2Var_MathBase::msc_, "None", py::arg("ndimen"), py::arg("vecte1"), py::arg("vecte2"));
cls_AdvApp2Var_MathBase.def_static("mvsheld__", (int (*)(integer *, integer *, doublereal *, integer *)) &AdvApp2Var_MathBase::mvsheld_, "None", py::arg("n"), py::arg("is"), py::arg("dtab"), py::arg("icle"));
cls_AdvApp2Var_MathBase.def_static("mmarcin__", (int (*)(integer *, integer *, integer *, doublereal *, doublereal *, doublereal *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmarcin_, "None", py::arg("ndimax"), py::arg("ndim"), py::arg("ncoeff"), py::arg("crvold"), py::arg("u0"), py::arg("u1"), py::arg("crvnew"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mmcvinv__", (int (*)(integer *, integer *, integer *, doublereal *, doublereal *)) &AdvApp2Var_MathBase::mmcvinv_, "None", py::arg("ndimax"), py::arg("ncoef"), py::arg("ndim"), py::arg("curveo"), py::arg("curve"));
cls_AdvApp2Var_MathBase.def_static("mmjacan__", (int (*)(const integer *, integer *, doublereal *, doublereal *)) &AdvApp2Var_MathBase::mmjacan_, "None", py::arg("ideriv"), py::arg("ndeg"), py::arg("poljac"), py::arg("polcan"));
cls_AdvApp2Var_MathBase.def_static("mmpocrb__", (int (*)(integer *, integer *, doublereal *, integer *, doublereal *, doublereal *)) &AdvApp2Var_MathBase::mmpocrb_, "None", py::arg("ndimax"), py::arg("ncoeff"), py::arg("courbe"), py::arg("ndim"), py::arg("tparam"), py::arg("pntcrb"));
cls_AdvApp2Var_MathBase.def_static("mmmrslwd__", (int (*)(integer *, integer *, integer *, doublereal *, doublereal *, doublereal *, doublereal *, doublereal *, integer *)) &AdvApp2Var_MathBase::mmmrslwd_, "None", py::arg("normax"), py::arg("nordre"), py::arg("ndim"), py::arg("amat"), py::arg("bmat"), py::arg("epspiv"), py::arg("aaux"), py::arg("xmat"), py::arg("iercod"));
cls_AdvApp2Var_MathBase.def_static("mmveps3__", (int (*)(doublereal *)) &AdvApp2Var_MathBase::mmveps3_, "None", py::arg("eps03"));
cls_AdvApp2Var_MathBase.def_static("pow__di_", (doublereal (*)(doublereal *, integer *)) &AdvApp2Var_MathBase::pow__di, "None", py::arg("x"), py::arg("n"));
cls_AdvApp2Var_MathBase.def_static("mzsnorm__", (doublereal (*)(integer *, doublereal *)) &AdvApp2Var_MathBase::mzsnorm_, "None", py::arg("ndimen"), py::arg("vecteu"));

// CLASS: ADVAPP2VAR_SYSBASE
py::class_<AdvApp2Var_SysBase> cls_AdvApp2Var_SysBase(mod, "AdvApp2Var_SysBase", "None");

// Constructors
cls_AdvApp2Var_SysBase.def(py::init<>());

// Methods
cls_AdvApp2Var_SysBase.def("mainial_", (int (AdvApp2Var_SysBase::*)()) &AdvApp2Var_SysBase::mainial_, "None");
cls_AdvApp2Var_SysBase.def_static("macinit__", (int (*)(int *, int *)) &AdvApp2Var_SysBase::macinit_, "None", py::arg(""), py::arg(""));
cls_AdvApp2Var_SysBase.def("mcrdelt_", (int (AdvApp2Var_SysBase::*)(integer *, integer *, void *, intptr_t *, integer *)) &AdvApp2Var_SysBase::mcrdelt_, "None", py::arg("iunit"), py::arg("isize"), py::arg("t"), py::arg("iofset"), py::arg("iercod"));
cls_AdvApp2Var_SysBase.def_static("mcrfill__", (int (*)(integer *, void *, void *)) &AdvApp2Var_SysBase::mcrfill_, "None", py::arg("size"), py::arg("tin"), py::arg("tout"));
cls_AdvApp2Var_SysBase.def("mcrrqst_", (int (AdvApp2Var_SysBase::*)(integer *, integer *, void *, intptr_t *, integer *)) &AdvApp2Var_SysBase::mcrrqst_, "None", py::arg("iunit"), py::arg("isize"), py::arg("t"), py::arg("iofset"), py::arg("iercod"));
cls_AdvApp2Var_SysBase.def_static("mnfndeb__", (integer (*)()) &AdvApp2Var_SysBase::mnfndeb_, "None");
cls_AdvApp2Var_SysBase.def_static("do__fio_", (int (*)()) &AdvApp2Var_SysBase::do__fio, "None");
cls_AdvApp2Var_SysBase.def_static("do__lio_", (int (*)()) &AdvApp2Var_SysBase::do__lio, "None");
cls_AdvApp2Var_SysBase.def("macrai4_", (int (AdvApp2Var_SysBase::*)(integer *, integer *, integer *, intptr_t *, integer *)) &AdvApp2Var_SysBase::macrai4_, "None", py::arg("nbelem"), py::arg("maxelm"), py::arg("itablo"), py::arg("iofset"), py::arg("iercod"));
cls_AdvApp2Var_SysBase.def("macrar8_", (int (AdvApp2Var_SysBase::*)(integer *, integer *, doublereal *, intptr_t *, integer *)) &AdvApp2Var_SysBase::macrar8_, "None", py::arg("nbelem"), py::arg("maxelm"), py::arg("xtablo"), py::arg("iofset"), py::arg("iercod"));
cls_AdvApp2Var_SysBase.def("macrdi4_", (int (AdvApp2Var_SysBase::*)(integer *, integer *, integer *, intptr_t *, integer *)) &AdvApp2Var_SysBase::macrdi4_, "None", py::arg("nbelem"), py::arg("maxelm"), py::arg("itablo"), py::arg("iofset"), py::arg("iercod"));
cls_AdvApp2Var_SysBase.def("macrdr8_", (int (AdvApp2Var_SysBase::*)(integer *, integer *, doublereal *, intptr_t *, integer *)) &AdvApp2Var_SysBase::macrdr8_, "None", py::arg("nbelem"), py::arg("maxelm"), py::arg("xtablo"), py::arg("iofset"), py::arg("iercod"));
cls_AdvApp2Var_SysBase.def_static("maermsg__", (int (*)(const char *, integer *, ftnlen)) &AdvApp2Var_SysBase::maermsg_, "None", py::arg("cnompg"), py::arg("icoder"), py::arg("cnompg_len"));
cls_AdvApp2Var_SysBase.def_static("maitbr8__", (int (*)(integer *, doublereal *, doublereal *)) &AdvApp2Var_SysBase::maitbr8_, "None", py::arg("itaill"), py::arg("xtab"), py::arg("xval"));
cls_AdvApp2Var_SysBase.def_static("maovsr8__", (int (*)(integer *)) &AdvApp2Var_SysBase::maovsr8_, "None", py::arg("ivalcs"));
cls_AdvApp2Var_SysBase.def_static("mgenmsg__", (int (*)(const char *, ftnlen)) &AdvApp2Var_SysBase::mgenmsg_, "None", py::arg("nomprg"), py::arg("nomprg_len"));
cls_AdvApp2Var_SysBase.def_static("mgsomsg__", (int (*)(const char *, ftnlen)) &AdvApp2Var_SysBase::mgsomsg_, "None", py::arg("nomprg"), py::arg("nomprg_len"));
cls_AdvApp2Var_SysBase.def_static("miraz__", (void (*)(integer *, void *)) &AdvApp2Var_SysBase::miraz_, "None", py::arg("taille"), py::arg("adt"));
cls_AdvApp2Var_SysBase.def_static("msifill__", (int (*)(integer *, integer *, integer *)) &AdvApp2Var_SysBase::msifill_, "None", py::arg("nbintg"), py::arg("ivecin"), py::arg("ivecou"));
cls_AdvApp2Var_SysBase.def_static("msrfill__", (int (*)(integer *, doublereal *, doublereal *)) &AdvApp2Var_SysBase::msrfill_, "None", py::arg("nbreel"), py::arg("vecent"), py::arg("vecsor"));
cls_AdvApp2Var_SysBase.def_static("mswrdbg__", (int (*)(const char *, ftnlen)) &AdvApp2Var_SysBase::mswrdbg_, "None", py::arg("ctexte"), py::arg("ctexte_len"));
cls_AdvApp2Var_SysBase.def_static("mvriraz__", (void (*)(integer *, void *)) &AdvApp2Var_SysBase::mvriraz_, "None", py::arg("taille"), py::arg("adt"));


}
