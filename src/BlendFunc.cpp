/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <BlendFunc_SectionShape.hxx>
#include <Blend_Function.hxx>
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Adaptor3d_HCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Vec2d.hxx>
#include <gp_Circ.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <Blend_Point.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <gp_Ax1.hxx>
#include <BlendFunc_ConstRad.hxx>
#include <Blend_FuncInv.hxx>
#include <Adaptor2d_HCurve2d.hxx>
#include <BlendFunc_ConstRadInv.hxx>
#include <BlendFunc_Ruled.hxx>
#include <BlendFunc_RuledInv.hxx>
#include <Law_Function.hxx>
#include <BlendFunc_EvolRad.hxx>
#include <BlendFunc_EvolRadInv.hxx>
#include <Blend_CSFunction.hxx>
#include <gp_Pnt2d.hxx>
#include <BlendFunc_CSConstRad.hxx>
#include <BlendFunc_CSCircular.hxx>
#include <BlendFunc_Corde.hxx>
#include <gp_Lin.hxx>
#include <BlendFunc_Chamfer.hxx>
#include <BlendFunc_ChamfInv.hxx>
#include <BlendFunc_ChAsym.hxx>
#include <BlendFunc_ChAsymInv.hxx>
#include <BlendFunc_Tensor.hxx>
#include <Convert_ParameterisationType.hxx>
#include <BlendFunc.hxx>

PYBIND11_MODULE(BlendFunc, mod) {

	// IMPORT
	py::module::import("OCCT.Blend");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Adaptor3d");
	py::module::import("OCCT.math");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.TColgp");
	py::module::import("OCCT.Adaptor2d");
	py::module::import("OCCT.Law");
	py::module::import("OCCT.Convert");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\BlendFunc_SectionShape.hxx
	py::enum_<BlendFunc_SectionShape>(mod, "BlendFunc_SectionShape", "None")
		.value("BlendFunc_Rational", BlendFunc_SectionShape::BlendFunc_Rational)
		.value("BlendFunc_QuasiAngular", BlendFunc_SectionShape::BlendFunc_QuasiAngular)
		.value("BlendFunc_Polynomial", BlendFunc_SectionShape::BlendFunc_Polynomial)
		.value("BlendFunc_Linear", BlendFunc_SectionShape::BlendFunc_Linear)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BlendFunc_ConstRad.hxx
	py::class_<BlendFunc_ConstRad, std::unique_ptr<BlendFunc_ConstRad, Deleter<BlendFunc_ConstRad>>, Blend_Function> cls_BlendFunc_ConstRad(mod, "BlendFunc_ConstRad", "None");
	cls_BlendFunc_ConstRad.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S1"), py::arg("S2"), py::arg("C"));
	cls_BlendFunc_ConstRad.def("NbEquations", (Standard_Integer (BlendFunc_ConstRad::*)() const ) &BlendFunc_ConstRad::NbEquations, "returns the number of equations of the function.");
	cls_BlendFunc_ConstRad.def("Value", (Standard_Boolean (BlendFunc_ConstRad::*)(const math_Vector &, math_Vector &)) &BlendFunc_ConstRad::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
	cls_BlendFunc_ConstRad.def("Derivatives", (Standard_Boolean (BlendFunc_ConstRad::*)(const math_Vector &, math_Matrix &)) &BlendFunc_ConstRad::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
	cls_BlendFunc_ConstRad.def("Values", (Standard_Boolean (BlendFunc_ConstRad::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_ConstRad::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
	cls_BlendFunc_ConstRad.def("Set", (void (BlendFunc_ConstRad::*)(const Standard_Real)) &BlendFunc_ConstRad::Set, "None", py::arg("Param"));
	cls_BlendFunc_ConstRad.def("Set", (void (BlendFunc_ConstRad::*)(const Standard_Real, const Standard_Real)) &BlendFunc_ConstRad::Set, "None", py::arg("First"), py::arg("Last"));
	cls_BlendFunc_ConstRad.def("GetTolerance", (void (BlendFunc_ConstRad::*)(math_Vector &, const Standard_Real) const ) &BlendFunc_ConstRad::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
	cls_BlendFunc_ConstRad.def("GetBounds", (void (BlendFunc_ConstRad::*)(math_Vector &, math_Vector &) const ) &BlendFunc_ConstRad::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
	cls_BlendFunc_ConstRad.def("IsSolution", (Standard_Boolean (BlendFunc_ConstRad::*)(const math_Vector &, const Standard_Real)) &BlendFunc_ConstRad::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
	cls_BlendFunc_ConstRad.def("GetMinimalDistance", (Standard_Real (BlendFunc_ConstRad::*)() const ) &BlendFunc_ConstRad::GetMinimalDistance, "Returns the minimal Distance beetween two extremitys of calculed sections.");
	cls_BlendFunc_ConstRad.def("PointOnS1", (const gp_Pnt & (BlendFunc_ConstRad::*)() const ) &BlendFunc_ConstRad::PointOnS1, "None");
	cls_BlendFunc_ConstRad.def("PointOnS2", (const gp_Pnt & (BlendFunc_ConstRad::*)() const ) &BlendFunc_ConstRad::PointOnS2, "None");
	cls_BlendFunc_ConstRad.def("IsTangencyPoint", (Standard_Boolean (BlendFunc_ConstRad::*)() const ) &BlendFunc_ConstRad::IsTangencyPoint, "None");
	cls_BlendFunc_ConstRad.def("TangentOnS1", (const gp_Vec & (BlendFunc_ConstRad::*)() const ) &BlendFunc_ConstRad::TangentOnS1, "None");
	cls_BlendFunc_ConstRad.def("Tangent2dOnS1", (const gp_Vec2d & (BlendFunc_ConstRad::*)() const ) &BlendFunc_ConstRad::Tangent2dOnS1, "None");
	cls_BlendFunc_ConstRad.def("TangentOnS2", (const gp_Vec & (BlendFunc_ConstRad::*)() const ) &BlendFunc_ConstRad::TangentOnS2, "None");
	cls_BlendFunc_ConstRad.def("Tangent2dOnS2", (const gp_Vec2d & (BlendFunc_ConstRad::*)() const ) &BlendFunc_ConstRad::Tangent2dOnS2, "None");
	cls_BlendFunc_ConstRad.def("Tangent", (void (BlendFunc_ConstRad::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &BlendFunc_ConstRad::Tangent, "Returns the tangent vector at the section, at the beginning and the end of the section, and returns the normal (of the surfaces) at these points.", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("TgFirst"), py::arg("TgLast"), py::arg("NormFirst"), py::arg("NormLast"));
	cls_BlendFunc_ConstRad.def("TwistOnS1", (Standard_Boolean (BlendFunc_ConstRad::*)() const ) &BlendFunc_ConstRad::TwistOnS1, "None");
	cls_BlendFunc_ConstRad.def("TwistOnS2", (Standard_Boolean (BlendFunc_ConstRad::*)() const ) &BlendFunc_ConstRad::TwistOnS2, "None");
	cls_BlendFunc_ConstRad.def("Set", (void (BlendFunc_ConstRad::*)(const Standard_Real, const Standard_Integer)) &BlendFunc_ConstRad::Set, "Inits the value of radius, and the 'quadrant'.", py::arg("Radius"), py::arg("Choix"));
	cls_BlendFunc_ConstRad.def("Set", (void (BlendFunc_ConstRad::*)(const BlendFunc_SectionShape)) &BlendFunc_ConstRad::Set, "Sets the type of section generation for the approximations.", py::arg("TypeSection"));
	cls_BlendFunc_ConstRad.def("Section", [](BlendFunc_ConstRad &self, const Standard_Real Param, const Standard_Real U1, const Standard_Real V1, const Standard_Real U2, const Standard_Real V2, Standard_Real & Pdeb, Standard_Real & Pfin, gp_Circ & C){ self.Section(Param, U1, V1, U2, V2, Pdeb, Pfin, C); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "Utile pour une visu rapide et approximative de la surface.", py::arg("Param"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("Pdeb"), py::arg("Pfin"), py::arg("C"));
	cls_BlendFunc_ConstRad.def("IsRational", (Standard_Boolean (BlendFunc_ConstRad::*)() const ) &BlendFunc_ConstRad::IsRational, "Returns if the section is rationnal");
	cls_BlendFunc_ConstRad.def("GetSectionSize", (Standard_Real (BlendFunc_ConstRad::*)() const ) &BlendFunc_ConstRad::GetSectionSize, "Returns the length of the maximum section");
	cls_BlendFunc_ConstRad.def("GetMinimalWeight", (void (BlendFunc_ConstRad::*)(TColStd_Array1OfReal &) const ) &BlendFunc_ConstRad::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
	cls_BlendFunc_ConstRad.def("NbIntervals", (Standard_Integer (BlendFunc_ConstRad::*)(const GeomAbs_Shape) const ) &BlendFunc_ConstRad::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
	cls_BlendFunc_ConstRad.def("Intervals", (void (BlendFunc_ConstRad::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &BlendFunc_ConstRad::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
	cls_BlendFunc_ConstRad.def("GetShape", [](BlendFunc_ConstRad &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
	cls_BlendFunc_ConstRad.def("GetTolerance", (void (BlendFunc_ConstRad::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const ) &BlendFunc_ConstRad::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
	cls_BlendFunc_ConstRad.def("Knots", (void (BlendFunc_ConstRad::*)(TColStd_Array1OfReal &)) &BlendFunc_ConstRad::Knots, "None", py::arg("TKnots"));
	cls_BlendFunc_ConstRad.def("Mults", (void (BlendFunc_ConstRad::*)(TColStd_Array1OfInteger &)) &BlendFunc_ConstRad::Mults, "None", py::arg("TMults"));
	cls_BlendFunc_ConstRad.def("Section", (Standard_Boolean (BlendFunc_ConstRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_ConstRad::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
	cls_BlendFunc_ConstRad.def("Section", (Standard_Boolean (BlendFunc_ConstRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_ConstRad::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
	cls_BlendFunc_ConstRad.def("Section", (void (BlendFunc_ConstRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BlendFunc_ConstRad::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
	cls_BlendFunc_ConstRad.def("AxeRot", (gp_Ax1 (BlendFunc_ConstRad::*)(const Standard_Real)) &BlendFunc_ConstRad::AxeRot, "None", py::arg("Prm"));
	cls_BlendFunc_ConstRad.def("Resolution", [](BlendFunc_ConstRad &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BlendFunc_ConstRadInv.hxx
	py::class_<BlendFunc_ConstRadInv, std::unique_ptr<BlendFunc_ConstRadInv, Deleter<BlendFunc_ConstRadInv>>, Blend_FuncInv> cls_BlendFunc_ConstRadInv(mod, "BlendFunc_ConstRadInv", "None");
	cls_BlendFunc_ConstRadInv.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S1"), py::arg("S2"), py::arg("C"));
	cls_BlendFunc_ConstRadInv.def("Set", (void (BlendFunc_ConstRadInv::*)(const Standard_Boolean, const opencascade::handle<Adaptor2d_HCurve2d> &)) &BlendFunc_ConstRadInv::Set, "None", py::arg("OnFirst"), py::arg("COnSurf"));
	cls_BlendFunc_ConstRadInv.def("GetTolerance", (void (BlendFunc_ConstRadInv::*)(math_Vector &, const Standard_Real) const ) &BlendFunc_ConstRadInv::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
	cls_BlendFunc_ConstRadInv.def("GetBounds", (void (BlendFunc_ConstRadInv::*)(math_Vector &, math_Vector &) const ) &BlendFunc_ConstRadInv::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
	cls_BlendFunc_ConstRadInv.def("IsSolution", (Standard_Boolean (BlendFunc_ConstRadInv::*)(const math_Vector &, const Standard_Real)) &BlendFunc_ConstRadInv::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
	cls_BlendFunc_ConstRadInv.def("NbEquations", (Standard_Integer (BlendFunc_ConstRadInv::*)() const ) &BlendFunc_ConstRadInv::NbEquations, "returns the number of equations of the function.");
	cls_BlendFunc_ConstRadInv.def("Value", (Standard_Boolean (BlendFunc_ConstRadInv::*)(const math_Vector &, math_Vector &)) &BlendFunc_ConstRadInv::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
	cls_BlendFunc_ConstRadInv.def("Derivatives", (Standard_Boolean (BlendFunc_ConstRadInv::*)(const math_Vector &, math_Matrix &)) &BlendFunc_ConstRadInv::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
	cls_BlendFunc_ConstRadInv.def("Values", (Standard_Boolean (BlendFunc_ConstRadInv::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_ConstRadInv::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
	cls_BlendFunc_ConstRadInv.def("Set", (void (BlendFunc_ConstRadInv::*)(const Standard_Real, const Standard_Integer)) &BlendFunc_ConstRadInv::Set, "None", py::arg("R"), py::arg("Choix"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BlendFunc_Ruled.hxx
	py::class_<BlendFunc_Ruled, std::unique_ptr<BlendFunc_Ruled, Deleter<BlendFunc_Ruled>>, Blend_Function> cls_BlendFunc_Ruled(mod, "BlendFunc_Ruled", "None");
	cls_BlendFunc_Ruled.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S1"), py::arg("S2"), py::arg("C"));
	cls_BlendFunc_Ruled.def("NbEquations", (Standard_Integer (BlendFunc_Ruled::*)() const ) &BlendFunc_Ruled::NbEquations, "returns the number of equations of the function.");
	cls_BlendFunc_Ruled.def("Value", (Standard_Boolean (BlendFunc_Ruled::*)(const math_Vector &, math_Vector &)) &BlendFunc_Ruled::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
	cls_BlendFunc_Ruled.def("Derivatives", (Standard_Boolean (BlendFunc_Ruled::*)(const math_Vector &, math_Matrix &)) &BlendFunc_Ruled::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
	cls_BlendFunc_Ruled.def("Values", (Standard_Boolean (BlendFunc_Ruled::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_Ruled::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
	cls_BlendFunc_Ruled.def("Set", (void (BlendFunc_Ruled::*)(const Standard_Real)) &BlendFunc_Ruled::Set, "None", py::arg("Param"));
	cls_BlendFunc_Ruled.def("Set", (void (BlendFunc_Ruled::*)(const Standard_Real, const Standard_Real)) &BlendFunc_Ruled::Set, "None", py::arg("First"), py::arg("Last"));
	cls_BlendFunc_Ruled.def("GetTolerance", (void (BlendFunc_Ruled::*)(math_Vector &, const Standard_Real) const ) &BlendFunc_Ruled::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
	cls_BlendFunc_Ruled.def("GetBounds", (void (BlendFunc_Ruled::*)(math_Vector &, math_Vector &) const ) &BlendFunc_Ruled::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
	cls_BlendFunc_Ruled.def("IsSolution", (Standard_Boolean (BlendFunc_Ruled::*)(const math_Vector &, const Standard_Real)) &BlendFunc_Ruled::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
	cls_BlendFunc_Ruled.def("GetMinimalDistance", (Standard_Real (BlendFunc_Ruled::*)() const ) &BlendFunc_Ruled::GetMinimalDistance, "Returns the minimal Distance beetween two extremitys of calculed sections.");
	cls_BlendFunc_Ruled.def("PointOnS1", (const gp_Pnt & (BlendFunc_Ruled::*)() const ) &BlendFunc_Ruled::PointOnS1, "None");
	cls_BlendFunc_Ruled.def("PointOnS2", (const gp_Pnt & (BlendFunc_Ruled::*)() const ) &BlendFunc_Ruled::PointOnS2, "None");
	cls_BlendFunc_Ruled.def("IsTangencyPoint", (Standard_Boolean (BlendFunc_Ruled::*)() const ) &BlendFunc_Ruled::IsTangencyPoint, "None");
	cls_BlendFunc_Ruled.def("TangentOnS1", (const gp_Vec & (BlendFunc_Ruled::*)() const ) &BlendFunc_Ruled::TangentOnS1, "None");
	cls_BlendFunc_Ruled.def("Tangent2dOnS1", (const gp_Vec2d & (BlendFunc_Ruled::*)() const ) &BlendFunc_Ruled::Tangent2dOnS1, "None");
	cls_BlendFunc_Ruled.def("TangentOnS2", (const gp_Vec & (BlendFunc_Ruled::*)() const ) &BlendFunc_Ruled::TangentOnS2, "None");
	cls_BlendFunc_Ruled.def("Tangent2dOnS2", (const gp_Vec2d & (BlendFunc_Ruled::*)() const ) &BlendFunc_Ruled::Tangent2dOnS2, "None");
	cls_BlendFunc_Ruled.def("Tangent", (void (BlendFunc_Ruled::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &BlendFunc_Ruled::Tangent, "Returns the tangent vector at the section, at the beginning and the end of the section, and returns the normal (of the surfaces) at these points.", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("TgFirst"), py::arg("TgLast"), py::arg("NormFirst"), py::arg("NormLast"));
	cls_BlendFunc_Ruled.def("GetSection", (Standard_Boolean (BlendFunc_Ruled::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &)) &BlendFunc_Ruled::GetSection, "None", py::arg("Param"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("tabP"), py::arg("tabV"));
	cls_BlendFunc_Ruled.def("IsRational", (Standard_Boolean (BlendFunc_Ruled::*)() const ) &BlendFunc_Ruled::IsRational, "Returns False");
	cls_BlendFunc_Ruled.def("GetSectionSize", (Standard_Real (BlendFunc_Ruled::*)() const ) &BlendFunc_Ruled::GetSectionSize, "Returns the length of the maximum section");
	cls_BlendFunc_Ruled.def("GetMinimalWeight", (void (BlendFunc_Ruled::*)(TColStd_Array1OfReal &) const ) &BlendFunc_Ruled::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
	cls_BlendFunc_Ruled.def("NbIntervals", (Standard_Integer (BlendFunc_Ruled::*)(const GeomAbs_Shape) const ) &BlendFunc_Ruled::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
	cls_BlendFunc_Ruled.def("Intervals", (void (BlendFunc_Ruled::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &BlendFunc_Ruled::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
	cls_BlendFunc_Ruled.def("GetShape", [](BlendFunc_Ruled &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
	cls_BlendFunc_Ruled.def("GetTolerance", (void (BlendFunc_Ruled::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const ) &BlendFunc_Ruled::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
	cls_BlendFunc_Ruled.def("Knots", (void (BlendFunc_Ruled::*)(TColStd_Array1OfReal &)) &BlendFunc_Ruled::Knots, "None", py::arg("TKnots"));
	cls_BlendFunc_Ruled.def("Mults", (void (BlendFunc_Ruled::*)(TColStd_Array1OfInteger &)) &BlendFunc_Ruled::Mults, "None", py::arg("TMults"));
	cls_BlendFunc_Ruled.def("Section", (Standard_Boolean (BlendFunc_Ruled::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_Ruled::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
	cls_BlendFunc_Ruled.def("Section", (Standard_Boolean (BlendFunc_Ruled::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_Ruled::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
	cls_BlendFunc_Ruled.def("Section", (void (BlendFunc_Ruled::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BlendFunc_Ruled::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
	cls_BlendFunc_Ruled.def("AxeRot", (gp_Ax1 (BlendFunc_Ruled::*)(const Standard_Real)) &BlendFunc_Ruled::AxeRot, "None", py::arg("Prm"));
	cls_BlendFunc_Ruled.def("Resolution", [](BlendFunc_Ruled &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BlendFunc_RuledInv.hxx
	py::class_<BlendFunc_RuledInv, std::unique_ptr<BlendFunc_RuledInv, Deleter<BlendFunc_RuledInv>>, Blend_FuncInv> cls_BlendFunc_RuledInv(mod, "BlendFunc_RuledInv", "None");
	cls_BlendFunc_RuledInv.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S1"), py::arg("S2"), py::arg("C"));
	cls_BlendFunc_RuledInv.def("Set", (void (BlendFunc_RuledInv::*)(const Standard_Boolean, const opencascade::handle<Adaptor2d_HCurve2d> &)) &BlendFunc_RuledInv::Set, "None", py::arg("OnFirst"), py::arg("COnSurf"));
	cls_BlendFunc_RuledInv.def("GetTolerance", (void (BlendFunc_RuledInv::*)(math_Vector &, const Standard_Real) const ) &BlendFunc_RuledInv::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
	cls_BlendFunc_RuledInv.def("GetBounds", (void (BlendFunc_RuledInv::*)(math_Vector &, math_Vector &) const ) &BlendFunc_RuledInv::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
	cls_BlendFunc_RuledInv.def("IsSolution", (Standard_Boolean (BlendFunc_RuledInv::*)(const math_Vector &, const Standard_Real)) &BlendFunc_RuledInv::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
	cls_BlendFunc_RuledInv.def("NbEquations", (Standard_Integer (BlendFunc_RuledInv::*)() const ) &BlendFunc_RuledInv::NbEquations, "returns the number of equations of the function.");
	cls_BlendFunc_RuledInv.def("Value", (Standard_Boolean (BlendFunc_RuledInv::*)(const math_Vector &, math_Vector &)) &BlendFunc_RuledInv::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
	cls_BlendFunc_RuledInv.def("Derivatives", (Standard_Boolean (BlendFunc_RuledInv::*)(const math_Vector &, math_Matrix &)) &BlendFunc_RuledInv::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
	cls_BlendFunc_RuledInv.def("Values", (Standard_Boolean (BlendFunc_RuledInv::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_RuledInv::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BlendFunc_EvolRad.hxx
	py::class_<BlendFunc_EvolRad, std::unique_ptr<BlendFunc_EvolRad, Deleter<BlendFunc_EvolRad>>, Blend_Function> cls_BlendFunc_EvolRad(mod, "BlendFunc_EvolRad", "None");
	cls_BlendFunc_EvolRad.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Law_Function> &>(), py::arg("S1"), py::arg("S2"), py::arg("C"), py::arg("Law"));
	cls_BlendFunc_EvolRad.def("NbEquations", (Standard_Integer (BlendFunc_EvolRad::*)() const ) &BlendFunc_EvolRad::NbEquations, "returns the number of equations of the function.");
	cls_BlendFunc_EvolRad.def("Value", (Standard_Boolean (BlendFunc_EvolRad::*)(const math_Vector &, math_Vector &)) &BlendFunc_EvolRad::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
	cls_BlendFunc_EvolRad.def("Derivatives", (Standard_Boolean (BlendFunc_EvolRad::*)(const math_Vector &, math_Matrix &)) &BlendFunc_EvolRad::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
	cls_BlendFunc_EvolRad.def("Values", (Standard_Boolean (BlendFunc_EvolRad::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_EvolRad::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
	cls_BlendFunc_EvolRad.def("Set", (void (BlendFunc_EvolRad::*)(const Standard_Real)) &BlendFunc_EvolRad::Set, "None", py::arg("Param"));
	cls_BlendFunc_EvolRad.def("Set", (void (BlendFunc_EvolRad::*)(const Standard_Real, const Standard_Real)) &BlendFunc_EvolRad::Set, "None", py::arg("First"), py::arg("Last"));
	cls_BlendFunc_EvolRad.def("GetTolerance", (void (BlendFunc_EvolRad::*)(math_Vector &, const Standard_Real) const ) &BlendFunc_EvolRad::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
	cls_BlendFunc_EvolRad.def("GetBounds", (void (BlendFunc_EvolRad::*)(math_Vector &, math_Vector &) const ) &BlendFunc_EvolRad::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
	cls_BlendFunc_EvolRad.def("IsSolution", (Standard_Boolean (BlendFunc_EvolRad::*)(const math_Vector &, const Standard_Real)) &BlendFunc_EvolRad::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
	cls_BlendFunc_EvolRad.def("GetMinimalDistance", (Standard_Real (BlendFunc_EvolRad::*)() const ) &BlendFunc_EvolRad::GetMinimalDistance, "Returns the minimal Distance beetween two extremitys of calculed sections.");
	cls_BlendFunc_EvolRad.def("PointOnS1", (const gp_Pnt & (BlendFunc_EvolRad::*)() const ) &BlendFunc_EvolRad::PointOnS1, "None");
	cls_BlendFunc_EvolRad.def("PointOnS2", (const gp_Pnt & (BlendFunc_EvolRad::*)() const ) &BlendFunc_EvolRad::PointOnS2, "None");
	cls_BlendFunc_EvolRad.def("IsTangencyPoint", (Standard_Boolean (BlendFunc_EvolRad::*)() const ) &BlendFunc_EvolRad::IsTangencyPoint, "None");
	cls_BlendFunc_EvolRad.def("TangentOnS1", (const gp_Vec & (BlendFunc_EvolRad::*)() const ) &BlendFunc_EvolRad::TangentOnS1, "None");
	cls_BlendFunc_EvolRad.def("Tangent2dOnS1", (const gp_Vec2d & (BlendFunc_EvolRad::*)() const ) &BlendFunc_EvolRad::Tangent2dOnS1, "None");
	cls_BlendFunc_EvolRad.def("TangentOnS2", (const gp_Vec & (BlendFunc_EvolRad::*)() const ) &BlendFunc_EvolRad::TangentOnS2, "None");
	cls_BlendFunc_EvolRad.def("Tangent2dOnS2", (const gp_Vec2d & (BlendFunc_EvolRad::*)() const ) &BlendFunc_EvolRad::Tangent2dOnS2, "None");
	cls_BlendFunc_EvolRad.def("Tangent", (void (BlendFunc_EvolRad::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &BlendFunc_EvolRad::Tangent, "Returns the tangent vector at the section, at the beginning and the end of the section, and returns the normal (of the surfaces) at these points.", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("TgFirst"), py::arg("TgLast"), py::arg("NormFirst"), py::arg("NormLast"));
	cls_BlendFunc_EvolRad.def("TwistOnS1", (Standard_Boolean (BlendFunc_EvolRad::*)() const ) &BlendFunc_EvolRad::TwistOnS1, "None");
	cls_BlendFunc_EvolRad.def("TwistOnS2", (Standard_Boolean (BlendFunc_EvolRad::*)() const ) &BlendFunc_EvolRad::TwistOnS2, "None");
	cls_BlendFunc_EvolRad.def("Set", (void (BlendFunc_EvolRad::*)(const Standard_Integer)) &BlendFunc_EvolRad::Set, "None", py::arg("Choix"));
	cls_BlendFunc_EvolRad.def("Set", (void (BlendFunc_EvolRad::*)(const BlendFunc_SectionShape)) &BlendFunc_EvolRad::Set, "Sets the type of section generation for the approximations.", py::arg("TypeSection"));
	cls_BlendFunc_EvolRad.def("Section", [](BlendFunc_EvolRad &self, const Standard_Real Param, const Standard_Real U1, const Standard_Real V1, const Standard_Real U2, const Standard_Real V2, Standard_Real & Pdeb, Standard_Real & Pfin, gp_Circ & C){ self.Section(Param, U1, V1, U2, V2, Pdeb, Pfin, C); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "Method for graphic traces", py::arg("Param"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("Pdeb"), py::arg("Pfin"), py::arg("C"));
	cls_BlendFunc_EvolRad.def("IsRational", (Standard_Boolean (BlendFunc_EvolRad::*)() const ) &BlendFunc_EvolRad::IsRational, "Returns if the section is rationnal");
	cls_BlendFunc_EvolRad.def("GetSectionSize", (Standard_Real (BlendFunc_EvolRad::*)() const ) &BlendFunc_EvolRad::GetSectionSize, "Returns the length of the maximum section");
	cls_BlendFunc_EvolRad.def("GetMinimalWeight", (void (BlendFunc_EvolRad::*)(TColStd_Array1OfReal &) const ) &BlendFunc_EvolRad::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
	cls_BlendFunc_EvolRad.def("NbIntervals", (Standard_Integer (BlendFunc_EvolRad::*)(const GeomAbs_Shape) const ) &BlendFunc_EvolRad::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
	cls_BlendFunc_EvolRad.def("Intervals", (void (BlendFunc_EvolRad::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &BlendFunc_EvolRad::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
	cls_BlendFunc_EvolRad.def("GetShape", [](BlendFunc_EvolRad &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
	cls_BlendFunc_EvolRad.def("GetTolerance", (void (BlendFunc_EvolRad::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const ) &BlendFunc_EvolRad::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
	cls_BlendFunc_EvolRad.def("Knots", (void (BlendFunc_EvolRad::*)(TColStd_Array1OfReal &)) &BlendFunc_EvolRad::Knots, "None", py::arg("TKnots"));
	cls_BlendFunc_EvolRad.def("Mults", (void (BlendFunc_EvolRad::*)(TColStd_Array1OfInteger &)) &BlendFunc_EvolRad::Mults, "None", py::arg("TMults"));
	cls_BlendFunc_EvolRad.def("Section", (Standard_Boolean (BlendFunc_EvolRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_EvolRad::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
	cls_BlendFunc_EvolRad.def("Section", (Standard_Boolean (BlendFunc_EvolRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_EvolRad::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
	cls_BlendFunc_EvolRad.def("Section", (void (BlendFunc_EvolRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BlendFunc_EvolRad::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
	cls_BlendFunc_EvolRad.def("Resolution", [](BlendFunc_EvolRad &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BlendFunc_EvolRadInv.hxx
	py::class_<BlendFunc_EvolRadInv, std::unique_ptr<BlendFunc_EvolRadInv, Deleter<BlendFunc_EvolRadInv>>, Blend_FuncInv> cls_BlendFunc_EvolRadInv(mod, "BlendFunc_EvolRadInv", "None");
	cls_BlendFunc_EvolRadInv.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Law_Function> &>(), py::arg("S1"), py::arg("S2"), py::arg("C"), py::arg("Law"));
	cls_BlendFunc_EvolRadInv.def("Set", (void (BlendFunc_EvolRadInv::*)(const Standard_Boolean, const opencascade::handle<Adaptor2d_HCurve2d> &)) &BlendFunc_EvolRadInv::Set, "None", py::arg("OnFirst"), py::arg("COnSurf"));
	cls_BlendFunc_EvolRadInv.def("GetTolerance", (void (BlendFunc_EvolRadInv::*)(math_Vector &, const Standard_Real) const ) &BlendFunc_EvolRadInv::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
	cls_BlendFunc_EvolRadInv.def("GetBounds", (void (BlendFunc_EvolRadInv::*)(math_Vector &, math_Vector &) const ) &BlendFunc_EvolRadInv::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
	cls_BlendFunc_EvolRadInv.def("IsSolution", (Standard_Boolean (BlendFunc_EvolRadInv::*)(const math_Vector &, const Standard_Real)) &BlendFunc_EvolRadInv::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
	cls_BlendFunc_EvolRadInv.def("NbEquations", (Standard_Integer (BlendFunc_EvolRadInv::*)() const ) &BlendFunc_EvolRadInv::NbEquations, "returns the number of equations of the function.");
	cls_BlendFunc_EvolRadInv.def("Value", (Standard_Boolean (BlendFunc_EvolRadInv::*)(const math_Vector &, math_Vector &)) &BlendFunc_EvolRadInv::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
	cls_BlendFunc_EvolRadInv.def("Derivatives", (Standard_Boolean (BlendFunc_EvolRadInv::*)(const math_Vector &, math_Matrix &)) &BlendFunc_EvolRadInv::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
	cls_BlendFunc_EvolRadInv.def("Values", (Standard_Boolean (BlendFunc_EvolRadInv::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_EvolRadInv::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
	cls_BlendFunc_EvolRadInv.def("Set", (void (BlendFunc_EvolRadInv::*)(const Standard_Integer)) &BlendFunc_EvolRadInv::Set, "None", py::arg("Choix"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BlendFunc_CSConstRad.hxx
	py::class_<BlendFunc_CSConstRad, std::unique_ptr<BlendFunc_CSConstRad, Deleter<BlendFunc_CSConstRad>>, Blend_CSFunction> cls_BlendFunc_CSConstRad(mod, "BlendFunc_CSConstRad", "None");
	cls_BlendFunc_CSConstRad.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S"), py::arg("C"), py::arg("CGuide"));
	cls_BlendFunc_CSConstRad.def("NbEquations", (Standard_Integer (BlendFunc_CSConstRad::*)() const ) &BlendFunc_CSConstRad::NbEquations, "returns the number of equations of the function (3).");
	cls_BlendFunc_CSConstRad.def("Value", (Standard_Boolean (BlendFunc_CSConstRad::*)(const math_Vector &, math_Vector &)) &BlendFunc_CSConstRad::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
	cls_BlendFunc_CSConstRad.def("Derivatives", (Standard_Boolean (BlendFunc_CSConstRad::*)(const math_Vector &, math_Matrix &)) &BlendFunc_CSConstRad::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
	cls_BlendFunc_CSConstRad.def("Values", (Standard_Boolean (BlendFunc_CSConstRad::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_CSConstRad::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
	cls_BlendFunc_CSConstRad.def("Set", (void (BlendFunc_CSConstRad::*)(const Standard_Real)) &BlendFunc_CSConstRad::Set, "None", py::arg("Param"));
	cls_BlendFunc_CSConstRad.def("Set", (void (BlendFunc_CSConstRad::*)(const Standard_Real, const Standard_Real)) &BlendFunc_CSConstRad::Set, "None", py::arg("First"), py::arg("Last"));
	cls_BlendFunc_CSConstRad.def("GetTolerance", (void (BlendFunc_CSConstRad::*)(math_Vector &, const Standard_Real) const ) &BlendFunc_CSConstRad::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
	cls_BlendFunc_CSConstRad.def("GetBounds", (void (BlendFunc_CSConstRad::*)(math_Vector &, math_Vector &) const ) &BlendFunc_CSConstRad::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
	cls_BlendFunc_CSConstRad.def("IsSolution", (Standard_Boolean (BlendFunc_CSConstRad::*)(const math_Vector &, const Standard_Real)) &BlendFunc_CSConstRad::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
	cls_BlendFunc_CSConstRad.def("PointOnS", (const gp_Pnt & (BlendFunc_CSConstRad::*)() const ) &BlendFunc_CSConstRad::PointOnS, "None");
	cls_BlendFunc_CSConstRad.def("PointOnC", (const gp_Pnt & (BlendFunc_CSConstRad::*)() const ) &BlendFunc_CSConstRad::PointOnC, "None");
	cls_BlendFunc_CSConstRad.def("Pnt2d", (const gp_Pnt2d & (BlendFunc_CSConstRad::*)() const ) &BlendFunc_CSConstRad::Pnt2d, "Returns U,V coordinates of the point on the surface.");
	cls_BlendFunc_CSConstRad.def("ParameterOnC", (Standard_Real (BlendFunc_CSConstRad::*)() const ) &BlendFunc_CSConstRad::ParameterOnC, "Returns parameter of the point on the curve.");
	cls_BlendFunc_CSConstRad.def("IsTangencyPoint", (Standard_Boolean (BlendFunc_CSConstRad::*)() const ) &BlendFunc_CSConstRad::IsTangencyPoint, "None");
	cls_BlendFunc_CSConstRad.def("TangentOnS", (const gp_Vec & (BlendFunc_CSConstRad::*)() const ) &BlendFunc_CSConstRad::TangentOnS, "None");
	cls_BlendFunc_CSConstRad.def("Tangent2d", (const gp_Vec2d & (BlendFunc_CSConstRad::*)() const ) &BlendFunc_CSConstRad::Tangent2d, "None");
	cls_BlendFunc_CSConstRad.def("TangentOnC", (const gp_Vec & (BlendFunc_CSConstRad::*)() const ) &BlendFunc_CSConstRad::TangentOnC, "None");
	cls_BlendFunc_CSConstRad.def("Tangent", (void (BlendFunc_CSConstRad::*)(const Standard_Real, const Standard_Real, gp_Vec &, gp_Vec &) const ) &BlendFunc_CSConstRad::Tangent, "Returns the tangent vector at the section, at the beginning and the end of the section, and returns the normal (of the surface) at these points.", py::arg("U"), py::arg("V"), py::arg("TgS"), py::arg("NormS"));
	cls_BlendFunc_CSConstRad.def("Set", (void (BlendFunc_CSConstRad::*)(const Standard_Real, const Standard_Integer)) &BlendFunc_CSConstRad::Set, "None", py::arg("Radius"), py::arg("Choix"));
	cls_BlendFunc_CSConstRad.def("Set", (void (BlendFunc_CSConstRad::*)(const BlendFunc_SectionShape)) &BlendFunc_CSConstRad::Set, "Sets the type of section generation for the approximations.", py::arg("TypeSection"));
	cls_BlendFunc_CSConstRad.def("Section", [](BlendFunc_CSConstRad &self, const Standard_Real Param, const Standard_Real U, const Standard_Real V, const Standard_Real W, Standard_Real & Pdeb, Standard_Real & Pfin, gp_Circ & C){ self.Section(Param, U, V, W, Pdeb, Pfin, C); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "None", py::arg("Param"), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("Pdeb"), py::arg("Pfin"), py::arg("C"));
	cls_BlendFunc_CSConstRad.def("Section", (Standard_Boolean (BlendFunc_CSConstRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_CSConstRad::Section, "Used for the first and last section The method returns Standard_True if the derivatives are computed, otherwise it returns Standard_False.", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
	cls_BlendFunc_CSConstRad.def("GetSection", (Standard_Boolean (BlendFunc_CSConstRad::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &)) &BlendFunc_CSConstRad::GetSection, "None", py::arg("Param"), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("tabP"), py::arg("tabV"));
	cls_BlendFunc_CSConstRad.def("IsRational", (Standard_Boolean (BlendFunc_CSConstRad::*)() const ) &BlendFunc_CSConstRad::IsRational, "Returns if the section is rationnal");
	cls_BlendFunc_CSConstRad.def("GetSectionSize", (Standard_Real (BlendFunc_CSConstRad::*)() const ) &BlendFunc_CSConstRad::GetSectionSize, "Returns the length of the maximum section");
	cls_BlendFunc_CSConstRad.def("GetMinimalWeight", (void (BlendFunc_CSConstRad::*)(TColStd_Array1OfReal &) const ) &BlendFunc_CSConstRad::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
	cls_BlendFunc_CSConstRad.def("NbIntervals", (Standard_Integer (BlendFunc_CSConstRad::*)(const GeomAbs_Shape) const ) &BlendFunc_CSConstRad::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
	cls_BlendFunc_CSConstRad.def("Intervals", (void (BlendFunc_CSConstRad::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &BlendFunc_CSConstRad::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>. The array must provide enough room to accomodate for the parameters. i.e. T.Length() > NbIntervals() raises OutOfRange from Standard", py::arg("T"), py::arg("S"));
	cls_BlendFunc_CSConstRad.def("GetShape", [](BlendFunc_CSConstRad &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
	cls_BlendFunc_CSConstRad.def("GetTolerance", (void (BlendFunc_CSConstRad::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const ) &BlendFunc_CSConstRad::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
	cls_BlendFunc_CSConstRad.def("Knots", (void (BlendFunc_CSConstRad::*)(TColStd_Array1OfReal &)) &BlendFunc_CSConstRad::Knots, "None", py::arg("TKnots"));
	cls_BlendFunc_CSConstRad.def("Mults", (void (BlendFunc_CSConstRad::*)(TColStd_Array1OfInteger &)) &BlendFunc_CSConstRad::Mults, "None", py::arg("TMults"));
	cls_BlendFunc_CSConstRad.def("Section", (Standard_Boolean (BlendFunc_CSConstRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_CSConstRad::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
	cls_BlendFunc_CSConstRad.def("Section", (void (BlendFunc_CSConstRad::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BlendFunc_CSConstRad::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
	cls_BlendFunc_CSConstRad.def("Resolution", [](BlendFunc_CSConstRad &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BlendFunc_CSCircular.hxx
	py::class_<BlendFunc_CSCircular, std::unique_ptr<BlendFunc_CSCircular, Deleter<BlendFunc_CSCircular>>, Blend_CSFunction> cls_BlendFunc_CSCircular(mod, "BlendFunc_CSCircular", "None");
	cls_BlendFunc_CSCircular.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Adaptor3d_HCurve> &, const opencascade::handle<Law_Function> &>(), py::arg("S"), py::arg("C"), py::arg("CGuide"), py::arg("L"));
	cls_BlendFunc_CSCircular.def("NbVariables", (Standard_Integer (BlendFunc_CSCircular::*)() const ) &BlendFunc_CSCircular::NbVariables, "None");
	cls_BlendFunc_CSCircular.def("NbEquations", (Standard_Integer (BlendFunc_CSCircular::*)() const ) &BlendFunc_CSCircular::NbEquations, "returns the number of equations of the function (3).");
	cls_BlendFunc_CSCircular.def("Value", (Standard_Boolean (BlendFunc_CSCircular::*)(const math_Vector &, math_Vector &)) &BlendFunc_CSCircular::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
	cls_BlendFunc_CSCircular.def("Derivatives", (Standard_Boolean (BlendFunc_CSCircular::*)(const math_Vector &, math_Matrix &)) &BlendFunc_CSCircular::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
	cls_BlendFunc_CSCircular.def("Values", (Standard_Boolean (BlendFunc_CSCircular::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_CSCircular::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
	cls_BlendFunc_CSCircular.def("Set", (void (BlendFunc_CSCircular::*)(const Standard_Real)) &BlendFunc_CSCircular::Set, "None", py::arg("Param"));
	cls_BlendFunc_CSCircular.def("Set", (void (BlendFunc_CSCircular::*)(const Standard_Real, const Standard_Real)) &BlendFunc_CSCircular::Set, "None", py::arg("First"), py::arg("Last"));
	cls_BlendFunc_CSCircular.def("GetTolerance", (void (BlendFunc_CSCircular::*)(math_Vector &, const Standard_Real) const ) &BlendFunc_CSCircular::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
	cls_BlendFunc_CSCircular.def("GetBounds", (void (BlendFunc_CSCircular::*)(math_Vector &, math_Vector &) const ) &BlendFunc_CSCircular::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
	cls_BlendFunc_CSCircular.def("IsSolution", (Standard_Boolean (BlendFunc_CSCircular::*)(const math_Vector &, const Standard_Real)) &BlendFunc_CSCircular::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
	cls_BlendFunc_CSCircular.def("PointOnS", (const gp_Pnt & (BlendFunc_CSCircular::*)() const ) &BlendFunc_CSCircular::PointOnS, "None");
	cls_BlendFunc_CSCircular.def("PointOnC", (const gp_Pnt & (BlendFunc_CSCircular::*)() const ) &BlendFunc_CSCircular::PointOnC, "None");
	cls_BlendFunc_CSCircular.def("Pnt2d", (const gp_Pnt2d & (BlendFunc_CSCircular::*)() const ) &BlendFunc_CSCircular::Pnt2d, "Returns U,V coordinates of the point on the surface.");
	cls_BlendFunc_CSCircular.def("ParameterOnC", (Standard_Real (BlendFunc_CSCircular::*)() const ) &BlendFunc_CSCircular::ParameterOnC, "Returns parameter of the point on the curve.");
	cls_BlendFunc_CSCircular.def("IsTangencyPoint", (Standard_Boolean (BlendFunc_CSCircular::*)() const ) &BlendFunc_CSCircular::IsTangencyPoint, "None");
	cls_BlendFunc_CSCircular.def("TangentOnS", (const gp_Vec & (BlendFunc_CSCircular::*)() const ) &BlendFunc_CSCircular::TangentOnS, "None");
	cls_BlendFunc_CSCircular.def("Tangent2d", (const gp_Vec2d & (BlendFunc_CSCircular::*)() const ) &BlendFunc_CSCircular::Tangent2d, "None");
	cls_BlendFunc_CSCircular.def("TangentOnC", (const gp_Vec & (BlendFunc_CSCircular::*)() const ) &BlendFunc_CSCircular::TangentOnC, "None");
	cls_BlendFunc_CSCircular.def("Tangent", (void (BlendFunc_CSCircular::*)(const Standard_Real, const Standard_Real, gp_Vec &, gp_Vec &) const ) &BlendFunc_CSCircular::Tangent, "Returns the tangent vector at the section, at the beginning and the end of the section, and returns the normal (of the surface) at these points.", py::arg("U"), py::arg("V"), py::arg("TgS"), py::arg("NormS"));
	cls_BlendFunc_CSCircular.def("Set", (void (BlendFunc_CSCircular::*)(const Standard_Real, const Standard_Integer)) &BlendFunc_CSCircular::Set, "None", py::arg("Radius"), py::arg("Choix"));
	cls_BlendFunc_CSCircular.def("Set", (void (BlendFunc_CSCircular::*)(const BlendFunc_SectionShape)) &BlendFunc_CSCircular::Set, "Sets the type of section generation for the approximations.", py::arg("TypeSection"));
	cls_BlendFunc_CSCircular.def("Section", [](BlendFunc_CSCircular &self, const Standard_Real Param, const Standard_Real U, const Standard_Real V, const Standard_Real W, Standard_Real & Pdeb, Standard_Real & Pfin, gp_Circ & C){ self.Section(Param, U, V, W, Pdeb, Pfin, C); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "None", py::arg("Param"), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("Pdeb"), py::arg("Pfin"), py::arg("C"));
	cls_BlendFunc_CSCircular.def("Section", (Standard_Boolean (BlendFunc_CSCircular::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_CSCircular::Section, "Used for the first and last section The method returns Standard_True if the derivatives are computed, otherwise it returns Standard_False.", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
	cls_BlendFunc_CSCircular.def("GetSection", (Standard_Boolean (BlendFunc_CSCircular::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColgp_Array1OfVec &)) &BlendFunc_CSCircular::GetSection, "None", py::arg("Param"), py::arg("U"), py::arg("V"), py::arg("W"), py::arg("tabP"), py::arg("tabV"));
	cls_BlendFunc_CSCircular.def("IsRational", (Standard_Boolean (BlendFunc_CSCircular::*)() const ) &BlendFunc_CSCircular::IsRational, "Returns if the section is rationnal");
	cls_BlendFunc_CSCircular.def("GetSectionSize", (Standard_Real (BlendFunc_CSCircular::*)() const ) &BlendFunc_CSCircular::GetSectionSize, "Returns the length of the maximum section");
	cls_BlendFunc_CSCircular.def("GetMinimalWeight", (void (BlendFunc_CSCircular::*)(TColStd_Array1OfReal &) const ) &BlendFunc_CSCircular::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
	cls_BlendFunc_CSCircular.def("NbIntervals", (Standard_Integer (BlendFunc_CSCircular::*)(const GeomAbs_Shape) const ) &BlendFunc_CSCircular::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
	cls_BlendFunc_CSCircular.def("Intervals", (void (BlendFunc_CSCircular::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &BlendFunc_CSCircular::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
	cls_BlendFunc_CSCircular.def("GetShape", [](BlendFunc_CSCircular &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
	cls_BlendFunc_CSCircular.def("GetTolerance", (void (BlendFunc_CSCircular::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const ) &BlendFunc_CSCircular::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
	cls_BlendFunc_CSCircular.def("Knots", (void (BlendFunc_CSCircular::*)(TColStd_Array1OfReal &)) &BlendFunc_CSCircular::Knots, "None", py::arg("TKnots"));
	cls_BlendFunc_CSCircular.def("Mults", (void (BlendFunc_CSCircular::*)(TColStd_Array1OfInteger &)) &BlendFunc_CSCircular::Mults, "None", py::arg("TMults"));
	cls_BlendFunc_CSCircular.def("Section", (Standard_Boolean (BlendFunc_CSCircular::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_CSCircular::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
	cls_BlendFunc_CSCircular.def("Section", (void (BlendFunc_CSCircular::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BlendFunc_CSCircular::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
	cls_BlendFunc_CSCircular.def("Resolution", [](BlendFunc_CSCircular &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BlendFunc_Corde.hxx
	py::class_<BlendFunc_Corde, std::unique_ptr<BlendFunc_Corde, Deleter<BlendFunc_Corde>>> cls_BlendFunc_Corde(mod, "BlendFunc_Corde", "This function calculates point (pts) on the curve of intersection between the normal to a curve (guide) in a chosen parameter and a surface (surf), so that pts was at a given distance from the guide. X(1),X(2) are the parameters U,V of pts on surf.");
	cls_BlendFunc_Corde.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S"), py::arg("CGuide"));
	cls_BlendFunc_Corde.def("SetParam", (void (BlendFunc_Corde::*)(const Standard_Real)) &BlendFunc_Corde::SetParam, "None", py::arg("Param"));
	cls_BlendFunc_Corde.def("SetDist", (void (BlendFunc_Corde::*)(const Standard_Real)) &BlendFunc_Corde::SetDist, "None", py::arg("Dist"));
	cls_BlendFunc_Corde.def("Value", (Standard_Boolean (BlendFunc_Corde::*)(const math_Vector &, math_Vector &)) &BlendFunc_Corde::Value, "computes the values <F> of the Function for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
	cls_BlendFunc_Corde.def("Derivatives", (Standard_Boolean (BlendFunc_Corde::*)(const math_Vector &, math_Matrix &)) &BlendFunc_Corde::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
	cls_BlendFunc_Corde.def("PointOnS", (const gp_Pnt & (BlendFunc_Corde::*)() const ) &BlendFunc_Corde::PointOnS, "None");
	cls_BlendFunc_Corde.def("PointOnGuide", (const gp_Pnt & (BlendFunc_Corde::*)() const ) &BlendFunc_Corde::PointOnGuide, "returns the point of parameter <Param> on CGuide");
	cls_BlendFunc_Corde.def("NPlan", (const gp_Vec & (BlendFunc_Corde::*)() const ) &BlendFunc_Corde::NPlan, "returns the normal to CGuide at Ptgui.");
	cls_BlendFunc_Corde.def("IsTangencyPoint", (Standard_Boolean (BlendFunc_Corde::*)() const ) &BlendFunc_Corde::IsTangencyPoint, "Returns True when it is not possible to compute the tangent vectors at PointOnS.");
	cls_BlendFunc_Corde.def("TangentOnS", (const gp_Vec & (BlendFunc_Corde::*)() const ) &BlendFunc_Corde::TangentOnS, "Returns the tangent vector at PointOnS, in 3d space.");
	cls_BlendFunc_Corde.def("Tangent2dOnS", (const gp_Vec2d & (BlendFunc_Corde::*)() const ) &BlendFunc_Corde::Tangent2dOnS, "Returns the tangent vector at PointOnS, in the parametric space of the first surface.");
	cls_BlendFunc_Corde.def("DerFguide", (void (BlendFunc_Corde::*)(const math_Vector &, gp_Vec2d &)) &BlendFunc_Corde::DerFguide, "Derived of the function compared to the parameter of the guideline", py::arg("Sol"), py::arg("DerF"));
	cls_BlendFunc_Corde.def("IsSolution", (Standard_Boolean (BlendFunc_Corde::*)(const math_Vector &, const Standard_Real)) &BlendFunc_Corde::IsSolution, "Returns False if Sol is not solution else returns True and updates the fields tgs and tg2d", py::arg("Sol"), py::arg("Tol"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BlendFunc_Chamfer.hxx
	py::class_<BlendFunc_Chamfer, std::unique_ptr<BlendFunc_Chamfer, Deleter<BlendFunc_Chamfer>>, Blend_Function> cls_BlendFunc_Chamfer(mod, "BlendFunc_Chamfer", "None");
	cls_BlendFunc_Chamfer.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S1"), py::arg("S2"), py::arg("CG"));
	cls_BlendFunc_Chamfer.def("NbEquations", (Standard_Integer (BlendFunc_Chamfer::*)() const ) &BlendFunc_Chamfer::NbEquations, "returns the number of equations of the function.");
	cls_BlendFunc_Chamfer.def("Value", (Standard_Boolean (BlendFunc_Chamfer::*)(const math_Vector &, math_Vector &)) &BlendFunc_Chamfer::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
	cls_BlendFunc_Chamfer.def("Derivatives", (Standard_Boolean (BlendFunc_Chamfer::*)(const math_Vector &, math_Matrix &)) &BlendFunc_Chamfer::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
	cls_BlendFunc_Chamfer.def("Values", (Standard_Boolean (BlendFunc_Chamfer::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_Chamfer::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
	cls_BlendFunc_Chamfer.def("Set", (void (BlendFunc_Chamfer::*)(const Standard_Real)) &BlendFunc_Chamfer::Set, "None", py::arg("Param"));
	cls_BlendFunc_Chamfer.def("Set", (void (BlendFunc_Chamfer::*)(const Standard_Real, const Standard_Real)) &BlendFunc_Chamfer::Set, "None", py::arg("First"), py::arg("Last"));
	cls_BlendFunc_Chamfer.def("GetTolerance", (void (BlendFunc_Chamfer::*)(math_Vector &, const Standard_Real) const ) &BlendFunc_Chamfer::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
	cls_BlendFunc_Chamfer.def("GetBounds", (void (BlendFunc_Chamfer::*)(math_Vector &, math_Vector &) const ) &BlendFunc_Chamfer::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
	cls_BlendFunc_Chamfer.def("IsSolution", (Standard_Boolean (BlendFunc_Chamfer::*)(const math_Vector &, const Standard_Real)) &BlendFunc_Chamfer::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
	cls_BlendFunc_Chamfer.def("GetMinimalDistance", (Standard_Real (BlendFunc_Chamfer::*)() const ) &BlendFunc_Chamfer::GetMinimalDistance, "Returns the minimal Distance beetween two extremitys of calculed sections.");
	cls_BlendFunc_Chamfer.def("PointOnS1", (const gp_Pnt & (BlendFunc_Chamfer::*)() const ) &BlendFunc_Chamfer::PointOnS1, "None");
	cls_BlendFunc_Chamfer.def("PointOnS2", (const gp_Pnt & (BlendFunc_Chamfer::*)() const ) &BlendFunc_Chamfer::PointOnS2, "None");
	cls_BlendFunc_Chamfer.def("IsTangencyPoint", (Standard_Boolean (BlendFunc_Chamfer::*)() const ) &BlendFunc_Chamfer::IsTangencyPoint, "None");
	cls_BlendFunc_Chamfer.def("TangentOnS1", (const gp_Vec & (BlendFunc_Chamfer::*)() const ) &BlendFunc_Chamfer::TangentOnS1, "None");
	cls_BlendFunc_Chamfer.def("Tangent2dOnS1", (const gp_Vec2d & (BlendFunc_Chamfer::*)() const ) &BlendFunc_Chamfer::Tangent2dOnS1, "None");
	cls_BlendFunc_Chamfer.def("TangentOnS2", (const gp_Vec & (BlendFunc_Chamfer::*)() const ) &BlendFunc_Chamfer::TangentOnS2, "None");
	cls_BlendFunc_Chamfer.def("Tangent2dOnS2", (const gp_Vec2d & (BlendFunc_Chamfer::*)() const ) &BlendFunc_Chamfer::Tangent2dOnS2, "None");
	cls_BlendFunc_Chamfer.def("Tangent", (void (BlendFunc_Chamfer::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &BlendFunc_Chamfer::Tangent, "Returns the tangent vector at the section, at the beginning and the end of the section, and returns the normal (of the surfaces) at these points.", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("TgFirst"), py::arg("TgLast"), py::arg("NormFirst"), py::arg("NormLast"));
	cls_BlendFunc_Chamfer.def("Set", (void (BlendFunc_Chamfer::*)(const Standard_Real, const Standard_Real, const Standard_Integer)) &BlendFunc_Chamfer::Set, "Sets the distances and the 'quadrant'.", py::arg("Dist1"), py::arg("Dist2"), py::arg("Choix"));
	cls_BlendFunc_Chamfer.def("IsRational", (Standard_Boolean (BlendFunc_Chamfer::*)() const ) &BlendFunc_Chamfer::IsRational, "Returns False");
	cls_BlendFunc_Chamfer.def("GetSectionSize", (Standard_Real (BlendFunc_Chamfer::*)() const ) &BlendFunc_Chamfer::GetSectionSize, "Returns the length of the maximum section");
	cls_BlendFunc_Chamfer.def("GetMinimalWeight", (void (BlendFunc_Chamfer::*)(TColStd_Array1OfReal &) const ) &BlendFunc_Chamfer::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
	cls_BlendFunc_Chamfer.def("NbIntervals", (Standard_Integer (BlendFunc_Chamfer::*)(const GeomAbs_Shape) const ) &BlendFunc_Chamfer::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
	cls_BlendFunc_Chamfer.def("Intervals", (void (BlendFunc_Chamfer::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &BlendFunc_Chamfer::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
	cls_BlendFunc_Chamfer.def("GetShape", [](BlendFunc_Chamfer &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
	cls_BlendFunc_Chamfer.def("GetTolerance", (void (BlendFunc_Chamfer::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const ) &BlendFunc_Chamfer::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
	cls_BlendFunc_Chamfer.def("Knots", (void (BlendFunc_Chamfer::*)(TColStd_Array1OfReal &)) &BlendFunc_Chamfer::Knots, "None", py::arg("TKnots"));
	cls_BlendFunc_Chamfer.def("Mults", (void (BlendFunc_Chamfer::*)(TColStd_Array1OfInteger &)) &BlendFunc_Chamfer::Mults, "None", py::arg("TMults"));
	cls_BlendFunc_Chamfer.def("Section", [](BlendFunc_Chamfer &self, const Standard_Real Param, const Standard_Real U1, const Standard_Real V1, const Standard_Real U2, const Standard_Real V2, Standard_Real & Pdeb, Standard_Real & Pfin, gp_Lin & C){ self.Section(Param, U1, V1, U2, V2, Pdeb, Pfin, C); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "Obsolete method", py::arg("Param"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("Pdeb"), py::arg("Pfin"), py::arg("C"));
	cls_BlendFunc_Chamfer.def("Section", (Standard_Boolean (BlendFunc_Chamfer::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_Chamfer::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
	cls_BlendFunc_Chamfer.def("Section", (Standard_Boolean (BlendFunc_Chamfer::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_Chamfer::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
	cls_BlendFunc_Chamfer.def("Section", (void (BlendFunc_Chamfer::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BlendFunc_Chamfer::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
	cls_BlendFunc_Chamfer.def("Resolution", [](BlendFunc_Chamfer &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BlendFunc_ChamfInv.hxx
	py::class_<BlendFunc_ChamfInv, std::unique_ptr<BlendFunc_ChamfInv, Deleter<BlendFunc_ChamfInv>>, Blend_FuncInv> cls_BlendFunc_ChamfInv(mod, "BlendFunc_ChamfInv", "None");
	cls_BlendFunc_ChamfInv.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S1"), py::arg("S2"), py::arg("C"));
	cls_BlendFunc_ChamfInv.def("Set", (void (BlendFunc_ChamfInv::*)(const Standard_Boolean, const opencascade::handle<Adaptor2d_HCurve2d> &)) &BlendFunc_ChamfInv::Set, "None", py::arg("OnFirst"), py::arg("COnSurf"));
	cls_BlendFunc_ChamfInv.def("GetTolerance", (void (BlendFunc_ChamfInv::*)(math_Vector &, const Standard_Real) const ) &BlendFunc_ChamfInv::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
	cls_BlendFunc_ChamfInv.def("GetBounds", (void (BlendFunc_ChamfInv::*)(math_Vector &, math_Vector &) const ) &BlendFunc_ChamfInv::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
	cls_BlendFunc_ChamfInv.def("IsSolution", (Standard_Boolean (BlendFunc_ChamfInv::*)(const math_Vector &, const Standard_Real)) &BlendFunc_ChamfInv::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
	cls_BlendFunc_ChamfInv.def("NbEquations", (Standard_Integer (BlendFunc_ChamfInv::*)() const ) &BlendFunc_ChamfInv::NbEquations, "returns the number of equations of the function.");
	cls_BlendFunc_ChamfInv.def("Value", (Standard_Boolean (BlendFunc_ChamfInv::*)(const math_Vector &, math_Vector &)) &BlendFunc_ChamfInv::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
	cls_BlendFunc_ChamfInv.def("Derivatives", (Standard_Boolean (BlendFunc_ChamfInv::*)(const math_Vector &, math_Matrix &)) &BlendFunc_ChamfInv::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
	cls_BlendFunc_ChamfInv.def("Values", (Standard_Boolean (BlendFunc_ChamfInv::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_ChamfInv::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
	cls_BlendFunc_ChamfInv.def("Set", (void (BlendFunc_ChamfInv::*)(const Standard_Real, const Standard_Real, const Standard_Integer)) &BlendFunc_ChamfInv::Set, "None", py::arg("Dist1"), py::arg("Dist2"), py::arg("Choix"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BlendFunc_ChAsym.hxx
	py::class_<BlendFunc_ChAsym, std::unique_ptr<BlendFunc_ChAsym, Deleter<BlendFunc_ChAsym>>, Blend_Function> cls_BlendFunc_ChAsym(mod, "BlendFunc_ChAsym", "None");
	cls_BlendFunc_ChAsym.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S1"), py::arg("S2"), py::arg("C"));
	cls_BlendFunc_ChAsym.def("NbEquations", (Standard_Integer (BlendFunc_ChAsym::*)() const ) &BlendFunc_ChAsym::NbEquations, "returns the number of equations of the function.");
	cls_BlendFunc_ChAsym.def("Set", (void (BlendFunc_ChAsym::*)(const Standard_Real)) &BlendFunc_ChAsym::Set, "None", py::arg("Param"));
	cls_BlendFunc_ChAsym.def("Set", (void (BlendFunc_ChAsym::*)(const Standard_Real, const Standard_Real)) &BlendFunc_ChAsym::Set, "None", py::arg("First"), py::arg("Last"));
	cls_BlendFunc_ChAsym.def("GetTolerance", (void (BlendFunc_ChAsym::*)(math_Vector &, const Standard_Real) const ) &BlendFunc_ChAsym::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
	cls_BlendFunc_ChAsym.def("GetBounds", (void (BlendFunc_ChAsym::*)(math_Vector &, math_Vector &) const ) &BlendFunc_ChAsym::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
	cls_BlendFunc_ChAsym.def("IsSolution", (Standard_Boolean (BlendFunc_ChAsym::*)(const math_Vector &, const Standard_Real)) &BlendFunc_ChAsym::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
	cls_BlendFunc_ChAsym.def("GetMinimalDistance", (Standard_Real (BlendFunc_ChAsym::*)() const ) &BlendFunc_ChAsym::GetMinimalDistance, "Returns the minimal Distance beetween two extremitys of calculed sections.");
	cls_BlendFunc_ChAsym.def("ComputeValues", (Standard_Boolean (BlendFunc_ChAsym::*)(const math_Vector &, const Standard_Integer, const Standard_Integer)) &BlendFunc_ChAsym::ComputeValues, "computes the values <F> of the derivatives for the variable <X> between DegF and DegL. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("DegF"), py::arg("DegL"));
	cls_BlendFunc_ChAsym.def("Value", (Standard_Boolean (BlendFunc_ChAsym::*)(const math_Vector &, math_Vector &)) &BlendFunc_ChAsym::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
	cls_BlendFunc_ChAsym.def("Derivatives", (Standard_Boolean (BlendFunc_ChAsym::*)(const math_Vector &, math_Matrix &)) &BlendFunc_ChAsym::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
	cls_BlendFunc_ChAsym.def("Values", (Standard_Boolean (BlendFunc_ChAsym::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_ChAsym::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
	cls_BlendFunc_ChAsym.def("PointOnS1", (const gp_Pnt & (BlendFunc_ChAsym::*)() const ) &BlendFunc_ChAsym::PointOnS1, "None");
	cls_BlendFunc_ChAsym.def("PointOnS2", (const gp_Pnt & (BlendFunc_ChAsym::*)() const ) &BlendFunc_ChAsym::PointOnS2, "None");
	cls_BlendFunc_ChAsym.def("IsTangencyPoint", (Standard_Boolean (BlendFunc_ChAsym::*)() const ) &BlendFunc_ChAsym::IsTangencyPoint, "None");
	cls_BlendFunc_ChAsym.def("TangentOnS1", (const gp_Vec & (BlendFunc_ChAsym::*)() const ) &BlendFunc_ChAsym::TangentOnS1, "None");
	cls_BlendFunc_ChAsym.def("Tangent2dOnS1", (const gp_Vec2d & (BlendFunc_ChAsym::*)() const ) &BlendFunc_ChAsym::Tangent2dOnS1, "None");
	cls_BlendFunc_ChAsym.def("TangentOnS2", (const gp_Vec & (BlendFunc_ChAsym::*)() const ) &BlendFunc_ChAsym::TangentOnS2, "None");
	cls_BlendFunc_ChAsym.def("Tangent2dOnS2", (const gp_Vec2d & (BlendFunc_ChAsym::*)() const ) &BlendFunc_ChAsym::Tangent2dOnS2, "None");
	cls_BlendFunc_ChAsym.def("TwistOnS1", (Standard_Boolean (BlendFunc_ChAsym::*)() const ) &BlendFunc_ChAsym::TwistOnS1, "None");
	cls_BlendFunc_ChAsym.def("TwistOnS2", (Standard_Boolean (BlendFunc_ChAsym::*)() const ) &BlendFunc_ChAsym::TwistOnS2, "None");
	cls_BlendFunc_ChAsym.def("Tangent", (void (BlendFunc_ChAsym::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec &, gp_Vec &, gp_Vec &, gp_Vec &) const ) &BlendFunc_ChAsym::Tangent, "Returns the tangent vector at the section, at the beginning and the end of the section, and returns the normal (of the surfaces) at these points.", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("TgFirst"), py::arg("TgLast"), py::arg("NormFirst"), py::arg("NormLast"));
	cls_BlendFunc_ChAsym.def("Section", [](BlendFunc_ChAsym &self, const Standard_Real Param, const Standard_Real U1, const Standard_Real V1, const Standard_Real U2, const Standard_Real V2, Standard_Real & Pdeb, Standard_Real & Pfin, gp_Lin & C){ self.Section(Param, U1, V1, U2, V2, Pdeb, Pfin, C); return std::tuple<Standard_Real &, Standard_Real &>(Pdeb, Pfin); }, "Utile pour une visu rapide et approximative de la surface.", py::arg("Param"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"), py::arg("Pdeb"), py::arg("Pfin"), py::arg("C"));
	cls_BlendFunc_ChAsym.def("IsRational", (Standard_Boolean (BlendFunc_ChAsym::*)() const ) &BlendFunc_ChAsym::IsRational, "Returns if the section is rationnal");
	cls_BlendFunc_ChAsym.def("GetSectionSize", (Standard_Real (BlendFunc_ChAsym::*)() const ) &BlendFunc_ChAsym::GetSectionSize, "Returns the length of the maximum section");
	cls_BlendFunc_ChAsym.def("GetMinimalWeight", (void (BlendFunc_ChAsym::*)(TColStd_Array1OfReal &) const ) &BlendFunc_ChAsym::GetMinimalWeight, "Compute the minimal value of weight for each poles of all sections.", py::arg("Weigths"));
	cls_BlendFunc_ChAsym.def("NbIntervals", (Standard_Integer (BlendFunc_ChAsym::*)(const GeomAbs_Shape) const ) &BlendFunc_ChAsym::NbIntervals, "Returns the number of intervals for continuity <S>. May be one if Continuity(me) >= <S>", py::arg("S"));
	cls_BlendFunc_ChAsym.def("Intervals", (void (BlendFunc_ChAsym::*)(TColStd_Array1OfReal &, const GeomAbs_Shape) const ) &BlendFunc_ChAsym::Intervals, "Stores in <T> the parameters bounding the intervals of continuity <S>.", py::arg("T"), py::arg("S"));
	cls_BlendFunc_ChAsym.def("GetShape", [](BlendFunc_ChAsym &self, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Standard_Integer & NbPoles2d){ self.GetShape(NbPoles, NbKnots, Degree, NbPoles2d); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree, NbPoles2d); }, "None", py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("NbPoles2d"));
	cls_BlendFunc_ChAsym.def("GetTolerance", (void (BlendFunc_ChAsym::*)(const Standard_Real, const Standard_Real, const Standard_Real, math_Vector &, math_Vector &) const ) &BlendFunc_ChAsym::GetTolerance, "Returns the tolerance to reach in approximation to respecte BoundTol error at the Boundary AngleTol tangent error at the Boundary SurfTol error inside the surface.", py::arg("BoundTol"), py::arg("SurfTol"), py::arg("AngleTol"), py::arg("Tol3d"), py::arg("Tol1D"));
	cls_BlendFunc_ChAsym.def("Knots", (void (BlendFunc_ChAsym::*)(TColStd_Array1OfReal &)) &BlendFunc_ChAsym::Knots, "None", py::arg("TKnots"));
	cls_BlendFunc_ChAsym.def("Mults", (void (BlendFunc_ChAsym::*)(TColStd_Array1OfInteger &)) &BlendFunc_ChAsym::Mults, "None", py::arg("TMults"));
	cls_BlendFunc_ChAsym.def("Section", (void (BlendFunc_ChAsym::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &BlendFunc_ChAsym::Section, "None", py::arg("P"), py::arg("Poles"), py::arg("Poles2d"), py::arg("Weigths"));
	cls_BlendFunc_ChAsym.def("Section", (Standard_Boolean (BlendFunc_ChAsym::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_ChAsym::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("Weigths"), py::arg("DWeigths"));
	cls_BlendFunc_ChAsym.def("Section", (Standard_Boolean (BlendFunc_ChAsym::*)(const Blend_Point &, TColgp_Array1OfPnt &, TColgp_Array1OfVec &, TColgp_Array1OfVec &, TColgp_Array1OfPnt2d &, TColgp_Array1OfVec2d &, TColgp_Array1OfVec2d &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &BlendFunc_ChAsym::Section, "Used for the first and last section", py::arg("P"), py::arg("Poles"), py::arg("DPoles"), py::arg("D2Poles"), py::arg("Poles2d"), py::arg("DPoles2d"), py::arg("D2Poles2d"), py::arg("Weigths"), py::arg("DWeigths"), py::arg("D2Weigths"));
	cls_BlendFunc_ChAsym.def("Resolution", [](BlendFunc_ChAsym &self, const Standard_Integer IC2d, const Standard_Real Tol, Standard_Real & TolU, Standard_Real & TolV){ self.Resolution(IC2d, Tol, TolU, TolV); return std::tuple<Standard_Real &, Standard_Real &>(TolU, TolV); }, "None", py::arg("IC2d"), py::arg("Tol"), py::arg("TolU"), py::arg("TolV"));
	cls_BlendFunc_ChAsym.def("Set", (void (BlendFunc_ChAsym::*)(const Standard_Real, const Standard_Real, const Standard_Integer)) &BlendFunc_ChAsym::Set, "Sets the distances and the angle.", py::arg("Dist1"), py::arg("Angle"), py::arg("Choix"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BlendFunc_ChAsymInv.hxx
	py::class_<BlendFunc_ChAsymInv, std::unique_ptr<BlendFunc_ChAsymInv, Deleter<BlendFunc_ChAsymInv>>, Blend_FuncInv> cls_BlendFunc_ChAsymInv(mod, "BlendFunc_ChAsymInv", "None");
	cls_BlendFunc_ChAsymInv.def(py::init<const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HSurface> &, const opencascade::handle<Adaptor3d_HCurve> &>(), py::arg("S1"), py::arg("S2"), py::arg("C"));
	cls_BlendFunc_ChAsymInv.def("Set", (void (BlendFunc_ChAsymInv::*)(const Standard_Boolean, const opencascade::handle<Adaptor2d_HCurve2d> &)) &BlendFunc_ChAsymInv::Set, "None", py::arg("OnFirst"), py::arg("COnSurf"));
	cls_BlendFunc_ChAsymInv.def("GetTolerance", (void (BlendFunc_ChAsymInv::*)(math_Vector &, const Standard_Real) const ) &BlendFunc_ChAsymInv::GetTolerance, "None", py::arg("Tolerance"), py::arg("Tol"));
	cls_BlendFunc_ChAsymInv.def("GetBounds", (void (BlendFunc_ChAsymInv::*)(math_Vector &, math_Vector &) const ) &BlendFunc_ChAsymInv::GetBounds, "None", py::arg("InfBound"), py::arg("SupBound"));
	cls_BlendFunc_ChAsymInv.def("IsSolution", (Standard_Boolean (BlendFunc_ChAsymInv::*)(const math_Vector &, const Standard_Real)) &BlendFunc_ChAsymInv::IsSolution, "None", py::arg("Sol"), py::arg("Tol"));
	cls_BlendFunc_ChAsymInv.def("NbEquations", (Standard_Integer (BlendFunc_ChAsymInv::*)() const ) &BlendFunc_ChAsymInv::NbEquations, "returns the number of equations of the function.");
	cls_BlendFunc_ChAsymInv.def("ComputeValues", (Standard_Boolean (BlendFunc_ChAsymInv::*)(const math_Vector &, const Standard_Integer, const Standard_Integer)) &BlendFunc_ChAsymInv::ComputeValues, "computes the values <F> of the derivatives for the variable <X> between DegF and DegL. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("DegF"), py::arg("DegL"));
	cls_BlendFunc_ChAsymInv.def("Value", (Standard_Boolean (BlendFunc_ChAsymInv::*)(const math_Vector &, math_Vector &)) &BlendFunc_ChAsymInv::Value, "computes the values <F> of the Functions for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"));
	cls_BlendFunc_ChAsymInv.def("Derivatives", (Standard_Boolean (BlendFunc_ChAsymInv::*)(const math_Vector &, math_Matrix &)) &BlendFunc_ChAsymInv::Derivatives, "returns the values <D> of the derivatives for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("D"));
	cls_BlendFunc_ChAsymInv.def("Values", (Standard_Boolean (BlendFunc_ChAsymInv::*)(const math_Vector &, math_Vector &, math_Matrix &)) &BlendFunc_ChAsymInv::Values, "returns the values <F> of the functions and the derivatives <D> for the variable <X>. Returns True if the computation was done successfully, False otherwise.", py::arg("X"), py::arg("F"), py::arg("D"));
	cls_BlendFunc_ChAsymInv.def("Set", (void (BlendFunc_ChAsymInv::*)(const Standard_Real, const Standard_Real, const Standard_Integer)) &BlendFunc_ChAsymInv::Set, "None", py::arg("Dist1"), py::arg("Angle"), py::arg("Choix"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BlendFunc_Tensor.hxx
	py::class_<BlendFunc_Tensor, std::unique_ptr<BlendFunc_Tensor, Deleter<BlendFunc_Tensor>>> cls_BlendFunc_Tensor(mod, "BlendFunc_Tensor", "used to store the 'gradient of gradient'");
	cls_BlendFunc_Tensor.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("NbRow"), py::arg("NbCol"), py::arg("NbMat"));
	cls_BlendFunc_Tensor.def("Init", (void (BlendFunc_Tensor::*)(const Standard_Real)) &BlendFunc_Tensor::Init, "Initialize all the elements of a Tensor to InitialValue.", py::arg("InitialValue"));
	cls_BlendFunc_Tensor.def("Value", (const Standard_Real & (BlendFunc_Tensor::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer) const ) &BlendFunc_Tensor::Value, "accesses (in read or write mode) the value of index <Row>, <Col> and <Mat> of a Tensor. An exception is raised if <Row>, <Col> or <Mat> are not in the correct range.", py::arg("Row"), py::arg("Col"), py::arg("Mat"));
	cls_BlendFunc_Tensor.def("__call__", (const Standard_Real & (BlendFunc_Tensor::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer) const ) &BlendFunc_Tensor::operator(), py::is_operator(), "None", py::arg("Row"), py::arg("Col"), py::arg("Mat"));
	cls_BlendFunc_Tensor.def("ChangeValue", (Standard_Real & (BlendFunc_Tensor::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &BlendFunc_Tensor::ChangeValue, "accesses (in read or write mode) the value of index <Row>, <Col> and <Mat> of a Tensor. An exception is raised if <Row>, <Col> or <Mat> are not in the correct range.", py::arg("Row"), py::arg("Col"), py::arg("Mat"));
	cls_BlendFunc_Tensor.def("__call__", (Standard_Real & (BlendFunc_Tensor::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &BlendFunc_Tensor::operator(), py::is_operator(), "None", py::arg("Row"), py::arg("Col"), py::arg("Mat"));
	cls_BlendFunc_Tensor.def("Multiply", (void (BlendFunc_Tensor::*)(const math_Vector &, math_Matrix &) const ) &BlendFunc_Tensor::Multiply, "None", py::arg("Right"), py::arg("Product"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\BlendFunc.hxx
	py::class_<BlendFunc, std::unique_ptr<BlendFunc, Deleter<BlendFunc>>> cls_BlendFunc(mod, "BlendFunc", "This package provides a set of generic functions, that can instantiated to compute blendings between two surfaces (Constant radius, Evolutive radius, Ruled surface).");
	cls_BlendFunc.def(py::init<>());
	cls_BlendFunc.def_static("GetShape_", [](const BlendFunc_SectionShape SectShape, const Standard_Real MaxAng, Standard_Integer & NbPoles, Standard_Integer & NbKnots, Standard_Integer & Degree, Convert_ParameterisationType & TypeConv){ BlendFunc::GetShape(SectShape, MaxAng, NbPoles, NbKnots, Degree, TypeConv); return std::tuple<Standard_Integer &, Standard_Integer &, Standard_Integer &>(NbPoles, NbKnots, Degree); }, "None", py::arg("SectShape"), py::arg("MaxAng"), py::arg("NbPoles"), py::arg("NbKnots"), py::arg("Degree"), py::arg("TypeConv"));
	// cls_BlendFunc.def_static("Knots_", (void (*)(const BlendFunc_SectionShape, TColStd_Array1OfReal &)) &BlendFunc::Knots, "None", py::arg("SectShape"), py::arg("TKnots"));
	// cls_BlendFunc.def_static("Mults_", (void (*)(const BlendFunc_SectionShape, TColStd_Array1OfInteger &)) &BlendFunc::Mults, "None", py::arg("SectShape"), py::arg("TMults"));
	cls_BlendFunc.def_static("GetMinimalWeights_", (void (*)(const BlendFunc_SectionShape, const Convert_ParameterisationType, const Standard_Real, const Standard_Real, TColStd_Array1OfReal &)) &BlendFunc::GetMinimalWeights, "None", py::arg("SectShape"), py::arg("TConv"), py::arg("AngleMin"), py::arg("AngleMax"), py::arg("Weigths"));
	cls_BlendFunc.def_static("NextShape_", (GeomAbs_Shape (*)(const GeomAbs_Shape)) &BlendFunc::NextShape, "Used to obtain the next level of continuity.", py::arg("S"));
	cls_BlendFunc.def_static("ComputeNormal_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &, const gp_Pnt2d &, gp_Vec &)) &BlendFunc::ComputeNormal, "None", py::arg("Surf"), py::arg("p2d"), py::arg("Normal"));
	cls_BlendFunc.def_static("ComputeDNormal_", (Standard_Boolean (*)(const opencascade::handle<Adaptor3d_HSurface> &, const gp_Pnt2d &, gp_Vec &, gp_Vec &, gp_Vec &)) &BlendFunc::ComputeDNormal, "None", py::arg("Surf"), py::arg("p2d"), py::arg("Normal"), py::arg("DNu"), py::arg("DNv"));


}
