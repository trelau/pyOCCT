#include <pyOCCT_Common.hpp>

#include <CSLib_DerivativeStatus.hxx>
#include <CSLib_NormalStatus.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <CSLib_Class2d.hxx>
#include <math_FunctionWithDerivative.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <CSLib_NormalPolyDef.hxx>
#include <gp_Vec.hxx>
#include <gp_Dir.hxx>
#include <TColgp_Array2OfVec.hxx>
#include <CSLib.hxx>

PYBIND11_MODULE(CSLib, mod) {

	// IMPORT
	py::module::import("OCCT.TColgp");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.math");
	py::module::import("OCCT.TColStd");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\CSLib_DerivativeStatus.hxx
	py::enum_<CSLib_DerivativeStatus>(mod, "CSLib_DerivativeStatus", "D1uIsNull : ||D1U|| <= Resolution")
		.value("CSLib_Done", CSLib_DerivativeStatus::CSLib_Done)
		.value("CSLib_D1uIsNull", CSLib_DerivativeStatus::CSLib_D1uIsNull)
		.value("CSLib_D1vIsNull", CSLib_DerivativeStatus::CSLib_D1vIsNull)
		.value("CSLib_D1IsNull", CSLib_DerivativeStatus::CSLib_D1IsNull)
		.value("CSLib_D1uD1vRatioIsNull", CSLib_DerivativeStatus::CSLib_D1uD1vRatioIsNull)
		.value("CSLib_D1vD1uRatioIsNull", CSLib_DerivativeStatus::CSLib_D1vD1uRatioIsNull)
		.value("CSLib_D1uIsParallelD1v", CSLib_DerivativeStatus::CSLib_D1uIsParallelD1v)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\CSLib_NormalStatus.hxx
	py::enum_<CSLib_NormalStatus>(mod, "CSLib_NormalStatus", "if N is the normal")
		.value("CSLib_Singular", CSLib_NormalStatus::CSLib_Singular)
		.value("CSLib_Defined", CSLib_NormalStatus::CSLib_Defined)
		.value("CSLib_InfinityOfSolutions", CSLib_NormalStatus::CSLib_InfinityOfSolutions)
		.value("CSLib_D1NuIsNull", CSLib_NormalStatus::CSLib_D1NuIsNull)
		.value("CSLib_D1NvIsNull", CSLib_NormalStatus::CSLib_D1NvIsNull)
		.value("CSLib_D1NIsNull", CSLib_NormalStatus::CSLib_D1NIsNull)
		.value("CSLib_D1NuNvRatioIsNull", CSLib_NormalStatus::CSLib_D1NuNvRatioIsNull)
		.value("CSLib_D1NvNuRatioIsNull", CSLib_NormalStatus::CSLib_D1NvNuRatioIsNull)
		.value("CSLib_D1NuIsParallelD1Nv", CSLib_NormalStatus::CSLib_D1NuIsParallelD1Nv)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\CSLib_Class2d.hxx
	py::class_<CSLib_Class2d, std::unique_ptr<CSLib_Class2d, Deleter<CSLib_Class2d>>> cls_CSLib_Class2d(mod, "CSLib_Class2d", "*** Class2d : Low level algorithm for 2d classification this class was moved from package BRepTopAdaptor");
	cls_CSLib_Class2d.def(py::init<const TColgp_Array1OfPnt2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("TP"), py::arg("aTolu"), py::arg("aTolv"), py::arg("umin"), py::arg("vmin"), py::arg("umax"), py::arg("vmax"));
	cls_CSLib_Class2d.def("SiDans", (Standard_Integer (CSLib_Class2d::*)(const gp_Pnt2d &) const ) &CSLib_Class2d::SiDans, "None", py::arg("P"));
	cls_CSLib_Class2d.def("SiDans_OnMode", (Standard_Integer (CSLib_Class2d::*)(const gp_Pnt2d &, const Standard_Real) const ) &CSLib_Class2d::SiDans_OnMode, "None", py::arg("P"), py::arg("Tol"));
	cls_CSLib_Class2d.def("InternalSiDans", (Standard_Integer (CSLib_Class2d::*)(const Standard_Real, const Standard_Real) const ) &CSLib_Class2d::InternalSiDans, "None", py::arg("X"), py::arg("Y"));
	cls_CSLib_Class2d.def("InternalSiDansOuOn", (Standard_Integer (CSLib_Class2d::*)(const Standard_Real, const Standard_Real) const ) &CSLib_Class2d::InternalSiDansOuOn, "None", py::arg("X"), py::arg("Y"));
	cls_CSLib_Class2d.def("Copy", (const CSLib_Class2d & (CSLib_Class2d::*)(const CSLib_Class2d &) const ) &CSLib_Class2d::Copy, "None", py::arg("Other"));
	cls_CSLib_Class2d.def("assign", (const CSLib_Class2d & (CSLib_Class2d::*)(const CSLib_Class2d &) const ) &CSLib_Class2d::operator=, py::is_operator(), "None", py::arg("Other"));
	cls_CSLib_Class2d.def("Destroy", (void (CSLib_Class2d::*)()) &CSLib_Class2d::Destroy, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\CSLib_NormalPolyDef.hxx
	py::class_<CSLib_NormalPolyDef, std::unique_ptr<CSLib_NormalPolyDef, Deleter<CSLib_NormalPolyDef>>, math_FunctionWithDerivative> cls_CSLib_NormalPolyDef(mod, "CSLib_NormalPolyDef", "None");
	cls_CSLib_NormalPolyDef.def(py::init<const Standard_Integer, const TColStd_Array1OfReal &>(), py::arg("k0"), py::arg("li"));
	cls_CSLib_NormalPolyDef.def("Value", [](CSLib_NormalPolyDef &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "computes the value <F>of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("F"));
	cls_CSLib_NormalPolyDef.def("Derivative", [](CSLib_NormalPolyDef &self, const Standard_Real X, Standard_Real & D){ Standard_Boolean rv = self.Derivative(X, D); return std::tuple<Standard_Boolean, Standard_Real &>(rv, D); }, "computes the derivative <D> of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("D"));
	cls_CSLib_NormalPolyDef.def("Values", [](CSLib_NormalPolyDef &self, const Standard_Real X, Standard_Real & F, Standard_Real & D){ Standard_Boolean rv = self.Values(X, F, D); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, D); }, "computes the value <F> and the derivative <D> of the function for the variable <X>. Returns True if the calculation were successfully done, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\CSLib.hxx
	py::class_<CSLib, std::unique_ptr<CSLib, Deleter<CSLib>>> cls_CSLib(mod, "CSLib", "This package implements functions for basis geometric computation on curves and surfaces. The tolerance criterions used in this package are Resolution from package gp and RealEpsilon from class Real of package Standard.");
	cls_CSLib.def(py::init<>());
	cls_CSLib.def_static("Normal_", (void (*)(const gp_Vec &, const gp_Vec &, const Standard_Real, CSLib_DerivativeStatus &, gp_Dir &)) &CSLib::Normal, "The following functions computes the normal to a surface inherits FunctionWithDerivative from math", py::arg("D1U"), py::arg("D1V"), py::arg("SinTol"), py::arg("theStatus"), py::arg("Normal"));
	cls_CSLib.def_static("Normal_", [](const gp_Vec & D1U, const gp_Vec & D1V, const gp_Vec & D2U, const gp_Vec & D2V, const gp_Vec & D2UV, const Standard_Real SinTol, Standard_Boolean & Done, CSLib_NormalStatus & theStatus, gp_Dir & Normal){ CSLib::Normal(D1U, D1V, D2U, D2V, D2UV, SinTol, Done, theStatus, Normal); return Done; }, "If there is a singularity on the surface the previous method cannot compute the local normal. This method computes an approched normal direction of a surface. It does a limited development and needs the second derivatives on the surface as input data. It computes the normal as follow : N(u, v) = D1U ^ D1V N(u0+du,v0+dv) = N0 + DN/du(u0,v0) * du + DN/dv(u0,v0) * dv + Eps with Eps->0 so we can have the equivalence N ~ dN/du + dN/dv. DNu = ||DN/du|| and DNv = ||DN/dv||", py::arg("D1U"), py::arg("D1V"), py::arg("D2U"), py::arg("D2V"), py::arg("D2UV"), py::arg("SinTol"), py::arg("Done"), py::arg("theStatus"), py::arg("Normal"));
	cls_CSLib.def_static("Normal_", (void (*)(const gp_Vec &, const gp_Vec &, const Standard_Real, CSLib_NormalStatus &, gp_Dir &)) &CSLib::Normal, "Computes the normal direction of a surface as the cross product between D1U and D1V.", py::arg("D1U"), py::arg("D1V"), py::arg("MagTol"), py::arg("theStatus"), py::arg("Normal"));
	cls_CSLib.def_static("Normal_", [](const Standard_Integer MaxOrder, const TColgp_Array2OfVec & DerNUV, const Standard_Real MagTol, const Standard_Real U, const Standard_Real V, const Standard_Real Umin, const Standard_Real Umax, const Standard_Real Vmin, const Standard_Real Vmax, CSLib_NormalStatus & theStatus, gp_Dir & Normal, Standard_Integer & OrderU, Standard_Integer & OrderV){ CSLib::Normal(MaxOrder, DerNUV, MagTol, U, V, Umin, Umax, Vmin, Vmax, theStatus, Normal, OrderU, OrderV); return std::tuple<Standard_Integer &, Standard_Integer &>(OrderU, OrderV); }, "find the first order k0 of deriviative of NUV where: foreach order < k0 all the derivatives of NUV are null all the derivatives of NUV corresponding to the order k0 are collinear and have the same sens. In this case, normal at U,V is unique.", py::arg("MaxOrder"), py::arg("DerNUV"), py::arg("MagTol"), py::arg("U"), py::arg("V"), py::arg("Umin"), py::arg("Umax"), py::arg("Vmin"), py::arg("Vmax"), py::arg("theStatus"), py::arg("Normal"), py::arg("OrderU"), py::arg("OrderV"));
	cls_CSLib.def_static("DNNUV_", (gp_Vec (*)(const Standard_Integer, const Standard_Integer, const TColgp_Array2OfVec &)) &CSLib::DNNUV, "-- Computes the derivative of order Nu in the -- direction U and Nv in the direction V of the not -- normalized normal vector at the point P(U,V) The array DerSurf contain the derivative (i,j) of the surface for i=0,Nu+1 ; j=0,Nv+1", py::arg("Nu"), py::arg("Nv"), py::arg("DerSurf"));
	cls_CSLib.def_static("DNNUV_", (gp_Vec (*)(const Standard_Integer, const Standard_Integer, const TColgp_Array2OfVec &, const TColgp_Array2OfVec &)) &CSLib::DNNUV, "Computes the derivatives of order Nu in the direction Nu and Nv in the direction Nv of the not normalized vector N(u,v) = dS1/du * dS2/dv (cases where we use an osculating surface) DerSurf1 are the derivatives of S1", py::arg("Nu"), py::arg("Nv"), py::arg("DerSurf1"), py::arg("DerSurf2"));
	cls_CSLib.def_static("DNNormal_", [](const Standard_Integer a0, const Standard_Integer a1, const TColgp_Array2OfVec & a2) -> gp_Vec { return CSLib::DNNormal(a0, a1, a2); }, py::arg("Nu"), py::arg("Nv"), py::arg("DerNUV"));
	cls_CSLib.def_static("DNNormal_", [](const Standard_Integer a0, const Standard_Integer a1, const TColgp_Array2OfVec & a2, const Standard_Integer a3) -> gp_Vec { return CSLib::DNNormal(a0, a1, a2, a3); }, py::arg("Nu"), py::arg("Nv"), py::arg("DerNUV"), py::arg("Iduref"));
	cls_CSLib.def_static("DNNormal_", (gp_Vec (*)(const Standard_Integer, const Standard_Integer, const TColgp_Array2OfVec &, const Standard_Integer, const Standard_Integer)) &CSLib::DNNormal, "-- Computes the derivative of order Nu in the -- direction U and Nv in the direction V of the normalized normal vector at the point P(U,V) array DerNUV contain the derivative (i+Iduref,j+Idvref) of D1U ^ D1V for i=0,Nu ; j=0,Nv Iduref and Idvref correspond to a derivative of D1U ^ D1V which can be used to compute the normalized normal vector. In the regular cases , Iduref=Idvref=0.", py::arg("Nu"), py::arg("Nv"), py::arg("DerNUV"), py::arg("Iduref"), py::arg("Idvref"));


}
