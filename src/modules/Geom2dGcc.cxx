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
#include <Geom2dGcc_Type3.hxx>
#include <Geom2dGcc_Type1.hxx>
#include <Geom2dGcc_Type2.hxx>
#include <Standard.hxx>
#include <Geom2dGcc_QualifiedCurve.hxx>
#include <Geom2dAdaptor_Curve.hxx>
#include <Geom2dGcc_CurveTool.hxx>
#include <Geom2dGcc_Circ2d3Tan.hxx>
#include <Geom2dGcc_Circ2d2TanRad.hxx>
#include <Geom2dGcc_Circ2d2TanOn.hxx>
#include <Geom2dGcc_Circ2dTanOnRad.hxx>
#include <Geom2dGcc_Circ2dTanCen.hxx>
#include <Geom2dGcc_Lin2d2Tan.hxx>
#include <Geom2dGcc_Lin2dTanObl.hxx>
#include <Geom2dGcc_QCurve.hxx>
#include <Geom2dGcc_Circ2d2TanOnGeo.hxx>
#include <Geom2dGcc_Circ2d2TanRadGeo.hxx>
#include <Geom2dGcc_Circ2dTanCenGeo.hxx>
#include <Geom2dGcc_Circ2dTanOnRadGeo.hxx>
#include <Geom2dGcc_Circ2d3TanIter.hxx>
#include <Geom2dGcc_FunctionTanCuCuCu.hxx>
#include <Geom2dGcc_Circ2d2TanOnIter.hxx>
#include <Geom2dGcc_FunctionTanCuCuOnCu.hxx>
#include <Geom2dGcc_Lin2dTanOblIter.hxx>
#include <Geom2dGcc_FunctionTanObl.hxx>
#include <Geom2dGcc_Lin2d2TanIter.hxx>
#include <Geom2dGcc_FunctionTanCuCu.hxx>
#include <Geom2dGcc_FunctionTanCuPnt.hxx>
#include <Geom2dGcc_FunctionTanCirCu.hxx>
#include <Geom2dGcc.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Point.hxx>
#include <GccAna_Circ2d2TanOn.hxx>
#include <gp_Circ2d.hxx>
#include <GccEnt_Position.hxx>
#include <gp_Pnt2d.hxx>
#include <TColgp_Array1OfCirc2d.hxx>
#include <GccEnt_Array1OfPosition.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <GccEnt_QualifiedCirc.hxx>
#include <GccEnt_QualifiedLin.hxx>
#include <gp_Lin2d.hxx>
#include <GccAna_Circ2d2TanRad.hxx>
#include <GccAna_Circ2d3Tan.hxx>
#include <GccAna_Circ2dTanOnRad.hxx>
#include <gp_Vec2d.hxx>
#include <math_FunctionWithDerivative.hxx>
#include <math_FunctionSetWithDerivatives.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <gp_Dir2d.hxx>
#include <Standard_DomainError.hxx>
#include <Geom2dGcc_IsParallel.hxx>
#include <Standard_SStream.hxx>
#include <Standard_Std.hxx>
#include <Standard_Type.hxx>
#include <TColgp_Array1OfLin2d.hxx>

PYBIND11_MODULE(Geom2dGcc, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Geom2dAdaptor");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.GccAna");
py::module::import("OCCT.gp");
py::module::import("OCCT.GccEnt");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.math");

// ENUM: GEOM2DGCC_TYPE3
py::enum_<Geom2dGcc_Type3>(mod, "Geom2dGcc_Type3", "None")
	.value("Geom2dGcc_CuCu", Geom2dGcc_Type3::Geom2dGcc_CuCu)
	.value("Geom2dGcc_CiCu", Geom2dGcc_Type3::Geom2dGcc_CiCu)
	.export_values();


// ENUM: GEOM2DGCC_TYPE1
py::enum_<Geom2dGcc_Type1>(mod, "Geom2dGcc_Type1", "None")
	.value("Geom2dGcc_CuCuCu", Geom2dGcc_Type1::Geom2dGcc_CuCuCu)
	.value("Geom2dGcc_CiCuCu", Geom2dGcc_Type1::Geom2dGcc_CiCuCu)
	.value("Geom2dGcc_CiCiCu", Geom2dGcc_Type1::Geom2dGcc_CiCiCu)
	.value("Geom2dGcc_CiLiCu", Geom2dGcc_Type1::Geom2dGcc_CiLiCu)
	.value("Geom2dGcc_LiLiCu", Geom2dGcc_Type1::Geom2dGcc_LiLiCu)
	.value("Geom2dGcc_LiCuCu", Geom2dGcc_Type1::Geom2dGcc_LiCuCu)
	.export_values();


// ENUM: GEOM2DGCC_TYPE2
py::enum_<Geom2dGcc_Type2>(mod, "Geom2dGcc_Type2", "None")
	.value("Geom2dGcc_CuCuOnCu", Geom2dGcc_Type2::Geom2dGcc_CuCuOnCu)
	.value("Geom2dGcc_CiCuOnCu", Geom2dGcc_Type2::Geom2dGcc_CiCuOnCu)
	.value("Geom2dGcc_LiCuOnCu", Geom2dGcc_Type2::Geom2dGcc_LiCuOnCu)
	.value("Geom2dGcc_CuPtOnCu", Geom2dGcc_Type2::Geom2dGcc_CuPtOnCu)
	.value("Geom2dGcc_CuCuOnLi", Geom2dGcc_Type2::Geom2dGcc_CuCuOnLi)
	.value("Geom2dGcc_CiCuOnLi", Geom2dGcc_Type2::Geom2dGcc_CiCuOnLi)
	.value("Geom2dGcc_LiCuOnLi", Geom2dGcc_Type2::Geom2dGcc_LiCuOnLi)
	.value("Geom2dGcc_CuPtOnLi", Geom2dGcc_Type2::Geom2dGcc_CuPtOnLi)
	.value("Geom2dGcc_CuCuOnCi", Geom2dGcc_Type2::Geom2dGcc_CuCuOnCi)
	.value("Geom2dGcc_CiCuOnCi", Geom2dGcc_Type2::Geom2dGcc_CiCuOnCi)
	.value("Geom2dGcc_LiCuOnCi", Geom2dGcc_Type2::Geom2dGcc_LiCuOnCi)
	.value("Geom2dGcc_CuPtOnCi", Geom2dGcc_Type2::Geom2dGcc_CuPtOnCi)
	.export_values();


// CLASS: GEOM2DGCC
py::class_<Geom2dGcc> cls_Geom2dGcc(mod, "Geom2dGcc", "The Geom2dGcc package describes qualified 2D curves used in the construction of constrained geometric objects by an algorithm provided by the Geom2dGcc package. A qualified 2D curve is a curve with a qualifier which specifies whether the solution of a construction algorithm using the qualified curve (as an argument): - encloses the curve, or - is enclosed by the curve, or - is built so that both the curve and this solution are external to one another, or - is undefined (all solutions apply). These package methods provide simpler functions to construct a qualified curve. Note: the interior of a curve is defined as the left-hand side of the curve in relation to its orientation.");

// Methods
// cls_Geom2dGcc.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc.def_static("Unqualified_", (Geom2dGcc_QualifiedCurve (*)(const Geom2dAdaptor_Curve &)) &Geom2dGcc::Unqualified, "Constructs such a qualified curve that the relative position of the solution computed by a construction algorithm using the qualified curve to the circle or line is not qualified, i.e. all solutions apply. Warning Obj is an adapted curve, i.e. an object which is an interface between: - the services provided by a 2D curve from the package Geom2d, - and those required on the curve by a computation algorithm. The adapted curve is created in the following way: Handle(Geom2d_Curve) mycurve = ... ; Geom2dAdaptor_Curve Obj ( mycurve ) ; The qualified curve is then constructed with this object: Geom2dGcc_QualifiedCurve myQCurve = Geom2dGcc::Unqualified(Obj);", py::arg("Obj"));
cls_Geom2dGcc.def_static("Enclosing_", (Geom2dGcc_QualifiedCurve (*)(const Geom2dAdaptor_Curve &)) &Geom2dGcc::Enclosing, "Constructs such a qualified curve that the solution computed by a construction algorithm using the qualified curve encloses the curve. Warning Obj is an adapted curve, i.e. an object which is an interface between: - the services provided by a 2D curve from the package Geom2d, - and those required on the curve by a computation algorithm. The adapted curve is created in the following way: Handle(Geom2d_Curve) mycurve = ... ; Geom2dAdaptor_Curve Obj ( mycurve ) ; The qualified curve is then constructed with this object: Geom2dGcc_QualifiedCurve myQCurve = Geom2dGcc::Enclosing(Obj);", py::arg("Obj"));
cls_Geom2dGcc.def_static("Enclosed_", (Geom2dGcc_QualifiedCurve (*)(const Geom2dAdaptor_Curve &)) &Geom2dGcc::Enclosed, "Constructs such a qualified curve that the solution computed by a construction algorithm using the qualified curve is enclosed by the curve. Warning Obj is an adapted curve, i.e. an object which is an interface between: - the services provided by a 2D curve from the package Geom2d, - and those required on the curve by a computation algorithm. The adapted curve is created in the following way: Handle(Geom2d_Curve) mycurve = ... ; Geom2dAdaptor_Curve Obj ( mycurve ) ; The qualified curve is then constructed with this object: Geom2dGcc_QualifiedCurve myQCurve = Geom2dGcc::Enclosed(Obj);", py::arg("Obj"));
cls_Geom2dGcc.def_static("Outside_", (Geom2dGcc_QualifiedCurve (*)(const Geom2dAdaptor_Curve &)) &Geom2dGcc::Outside, "Constructs such a qualified curve that the solution computed by a construction algorithm using the qualified curve and the curve are external to one another. Warning Obj is an adapted curve, i.e. an object which is an interface between: - the services provided by a 2D curve from the package Geom2d, - and those required on the curve by a computation algorithm. The adapted curve is created in the following way: Handle(Geom2d_Curve) mycurve = ... ; Geom2dAdaptor_Curve Obj ( mycurve ) ; The qualified curve is then constructed with this object: Geom2dGcc_QualifiedCurve myQCurve = Geom2dGcc::Outside(Obj);", py::arg("Obj"));

// CLASS: GEOM2DGCC_CIRC2D2TANON
py::class_<Geom2dGcc_Circ2d2TanOn> cls_Geom2dGcc_Circ2d2TanOn(mod, "Geom2dGcc_Circ2d2TanOn", "This class implements the algorithms used to create 2d circles TANgent to 2 entities and having the center ON a curve. The order of the tangency argument is always QualifiedCirc, QualifiedLin, QualifiedCurv, Pnt2d. the arguments are : - The two tangency arguments. - The center line. - The parameter for each tangency argument which is a curve. - The tolerance.");

// Constructors
cls_Geom2dGcc_Circ2d2TanOn.def(py::init<const Geom2dGcc_QualifiedCurve &, const Geom2dGcc_QualifiedCurve &, const Geom2dAdaptor_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnCurve"), py::arg("Tolerance"), py::arg("Param1"), py::arg("Param2"), py::arg("ParamOn"));
cls_Geom2dGcc_Circ2d2TanOn.def(py::init<const Geom2dGcc_QualifiedCurve &, const opencascade::handle<Geom2d_Point> &, const Geom2dAdaptor_Curve &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Point"), py::arg("OnCurve"), py::arg("Tolerance"), py::arg("Param1"), py::arg("ParamOn"));
cls_Geom2dGcc_Circ2d2TanOn.def(py::init<const opencascade::handle<Geom2d_Point> &, const opencascade::handle<Geom2d_Point> &, const Geom2dAdaptor_Curve &, const Standard_Real>(), py::arg("Point1"), py::arg("Point2"), py::arg("OnCurve"), py::arg("Tolerance"));

// Methods
// cls_Geom2dGcc_Circ2d2TanOn.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Circ2d2TanOn::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d2TanOn.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Circ2d2TanOn::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanOn.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Circ2d2TanOn::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d2TanOn.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Circ2d2TanOn::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanOn.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Circ2d2TanOn::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanOn.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Circ2d2TanOn::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Circ2d2TanOn.def("Results", (void (Geom2dGcc_Circ2d2TanOn::*)(const GccAna_Circ2d2TanOn &)) &Geom2dGcc_Circ2d2TanOn::Results, "None", py::arg("Circ"));
cls_Geom2dGcc_Circ2d2TanOn.def("Results", (void (Geom2dGcc_Circ2d2TanOn::*)(const Geom2dGcc_Circ2d2TanOnGeo &)) &Geom2dGcc_Circ2d2TanOn::Results, "None", py::arg("Circ"));
cls_Geom2dGcc_Circ2d2TanOn.def("IsDone", (Standard_Boolean (Geom2dGcc_Circ2d2TanOn::*)() const) &Geom2dGcc_Circ2d2TanOn::IsDone, "Returns true if the construction algorithm does not fail (even if it finds no solution). Note: IsDone protects against a failure arising from a more internal intersection algorithm, which has reached its numeric limits.");
cls_Geom2dGcc_Circ2d2TanOn.def("NbSolutions", (Standard_Integer (Geom2dGcc_Circ2d2TanOn::*)() const) &Geom2dGcc_Circ2d2TanOn::NbSolutions, "This method returns the number of solutions. NotDone is raised if the algorithm failed.");
cls_Geom2dGcc_Circ2d2TanOn.def("ThisSolution", (gp_Circ2d (Geom2dGcc_Circ2d2TanOn::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d2TanOn::ThisSolution, "Returns the solution number Index and raises OutOfRange exception if Index is greater than the number of solutions. Be carefull: the Index is only a way to get all the solutions, but is not associated to theses outside the context of the algorithm-object. Exceptions Standard_OutOfRange if Index is less than or equal to zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"));
cls_Geom2dGcc_Circ2d2TanOn.def("WhichQualifier", (void (Geom2dGcc_Circ2d2TanOn::*)(const Standard_Integer, GccEnt_Position &, GccEnt_Position &) const) &Geom2dGcc_Circ2d2TanOn::WhichQualifier, "It returns the informations about the qualifiers of the tangency arguments concerning the solution number Index. It returns the real qualifiers (the qualifiers given to the constructor method in case of enclosed, enclosing and outside and the qualifiers computedin case of unqualified). Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("Qualif1"), py::arg("Qualif2"));
cls_Geom2dGcc_Circ2d2TanOn.def("Tangency1", [](Geom2dGcc_Circ2d2TanOn &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d2TanOn.def("Tangency2", [](Geom2dGcc_Circ2d2TanOn &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency2(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result and the second argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d2TanOn.def("CenterOn3", [](Geom2dGcc_Circ2d2TanOn &self, const Standard_Integer Index, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.CenterOn3(Index, ParArg, PntSol); return ParArg; }, "Returns the center PntSol of the solution of index Index computed by this algorithm. ParArg is the parameter of the point PntSol on the third argument. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d2TanOn.def("IsTheSame1", (Standard_Boolean (Geom2dGcc_Circ2d2TanOn::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d2TanOn::IsTheSame1, "Returns true if the solution of index Index and, respectively, the first or second argument of this algorithm are the same (i.e. there are 2 identical circles). If Rarg is the radius of the first or second argument, Rsol is the radius of the solution and dist is the distance between the two centers, we consider the two circles to be identical if |Rarg - Rsol| and dist are less than or equal to the tolerance criterion given at the time of construction of this algorithm. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"));
cls_Geom2dGcc_Circ2d2TanOn.def("IsTheSame2", (Standard_Boolean (Geom2dGcc_Circ2d2TanOn::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d2TanOn::IsTheSame2, "Returns true if the solution of index Index and, respectively, the first or second argument of this algorithm are the same (i.e. there are 2 identical circles). If Rarg is the radius of the first or second argument, Rsol is the radius of the solution and dist is the distance between the two centers, we consider the two circles to be identical if |Rarg - Rsol| and dist are less than or equal to the tolerance criterion given at the time of construction of this algorithm. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"));

// CLASS: GEOM2DGCC_CIRC2D2TANONGEO
py::class_<Geom2dGcc_Circ2d2TanOnGeo> cls_Geom2dGcc_Circ2d2TanOnGeo(mod, "Geom2dGcc_Circ2d2TanOnGeo", "This class implements the algorithms used to create 2d circles TANgent to 2 entities and having the center ON a curve. The order of the tangency argument is always QualifiedCirc, QualifiedLin, QualifiedCurv, Pnt2d. the arguments are : - The two tangency arguments (lines, circles or points). - The center line (a curve). - The parameter for each tangency argument which is a curve. - The tolerance.");

// Constructors
cls_Geom2dGcc_Circ2d2TanOnGeo.def(py::init<const GccEnt_QualifiedCirc &, const GccEnt_QualifiedCirc &, const Geom2dAdaptor_Curve &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnCurv"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnGeo.def(py::init<const GccEnt_QualifiedCirc &, const GccEnt_QualifiedLin &, const Geom2dAdaptor_Curve &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnCurv"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnGeo.def(py::init<const GccEnt_QualifiedCirc &, const gp_Pnt2d &, const Geom2dAdaptor_Curve &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Point2"), py::arg("OnCurv"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnGeo.def(py::init<const GccEnt_QualifiedLin &, const GccEnt_QualifiedLin &, const Geom2dAdaptor_Curve &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnCurv"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnGeo.def(py::init<const GccEnt_QualifiedLin &, const gp_Pnt2d &, const Geom2dAdaptor_Curve &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnCurv"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnGeo.def(py::init<const gp_Pnt2d &, const gp_Pnt2d &, const Geom2dAdaptor_Curve &, const Standard_Real>(), py::arg("Point1"), py::arg("Point2"), py::arg("OnCurv"), py::arg("Tolerance"));

// Methods
// cls_Geom2dGcc_Circ2d2TanOnGeo.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Circ2d2TanOnGeo::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d2TanOnGeo.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Circ2d2TanOnGeo::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanOnGeo.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Circ2d2TanOnGeo::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d2TanOnGeo.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Circ2d2TanOnGeo::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanOnGeo.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Circ2d2TanOnGeo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanOnGeo.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Circ2d2TanOnGeo::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Circ2d2TanOnGeo.def("IsDone", (Standard_Boolean (Geom2dGcc_Circ2d2TanOnGeo::*)() const) &Geom2dGcc_Circ2d2TanOnGeo::IsDone, "This method returns True if the construction algorithm succeeded.");
cls_Geom2dGcc_Circ2d2TanOnGeo.def("NbSolutions", (Standard_Integer (Geom2dGcc_Circ2d2TanOnGeo::*)() const) &Geom2dGcc_Circ2d2TanOnGeo::NbSolutions, "This method returns the number of solutions. It raises NotDone if the construction algorithm didn't succeed.");
cls_Geom2dGcc_Circ2d2TanOnGeo.def("ThisSolution", (gp_Circ2d (Geom2dGcc_Circ2d2TanOnGeo::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d2TanOnGeo::ThisSolution, "Returns the solution number Index and raises OutOfRange exception if Index is greater than the number of solutions. Be careful: the Index is only a way to get all the solutions, but is not associated to those outside the context of the algorithm-object. It raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"));
cls_Geom2dGcc_Circ2d2TanOnGeo.def("WhichQualifier", (void (Geom2dGcc_Circ2d2TanOnGeo::*)(const Standard_Integer, GccEnt_Position &, GccEnt_Position &) const) &Geom2dGcc_Circ2d2TanOnGeo::WhichQualifier, "It returns the informations about the qualifiers of the tangency arguments concerning the solution number Index. It returns the real qualifiers (the qualifiers given to the constructor method in case of enclosed, enclosing and outside and the qualifiers computedin case of unqualified).", py::arg("Index"), py::arg("Qualif1"), py::arg("Qualif2"));
cls_Geom2dGcc_Circ2d2TanOnGeo.def("Tangency1", [](Geom2dGcc_Circ2d2TanOnGeo &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result number Index and the first argument. ParSol is the intrinsic parameter of the point on the solution curv. ParArg is the intrinsic parameter of the point on the argument curv. PntSol is the tangency point on the solution curv. PntArg is the tangency point on the argument curv. It raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d2TanOnGeo.def("Tangency2", [](Geom2dGcc_Circ2d2TanOnGeo &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency2(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result number Index and the second argument. ParSol is the intrinsic parameter of the point on the solution curv. ParArg is the intrinsic parameter of the point on the argument curv. PntSol is the tangency point on the solution curv. PntArg is the tangency point on the argument curv. It raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d2TanOnGeo.def("CenterOn3", [](Geom2dGcc_Circ2d2TanOnGeo &self, const Standard_Integer Index, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.CenterOn3(Index, ParArg, PntSol); return ParArg; }, "Returns informations about the center (on the curv) of the result. ParArg is the intrinsic parameter of the point on the argument curv. PntSol is the center point of the solution curv. It raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d2TanOnGeo.def("IsTheSame1", (Standard_Boolean (Geom2dGcc_Circ2d2TanOnGeo::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d2TanOnGeo::IsTheSame1, "Returns True if the solution number Index is equal to the first argument and False in the other cases. It raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"));
cls_Geom2dGcc_Circ2d2TanOnGeo.def("IsTheSame2", (Standard_Boolean (Geom2dGcc_Circ2d2TanOnGeo::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d2TanOnGeo::IsTheSame2, "Returns True if the solution number Index is equal to the second argument and False in the other cases. It raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"));

// CLASS: GEOM2DGCC_CIRC2D2TANONITER
py::class_<Geom2dGcc_Circ2d2TanOnIter> cls_Geom2dGcc_Circ2d2TanOnIter(mod, "Geom2dGcc_Circ2d2TanOnIter", "This class implements the algorithms used to create 2d circles TANgent to 2 entities and having the center ON a curv. The order of the tangency argument is always QualifiedCirc, QualifiedLin, QualifiedCurv, Pnt2d. the arguments are : - The two tangency arguments. - The center line. - The parameter for each tangency argument which is a curve. - The tolerance.");

// Constructors
cls_Geom2dGcc_Circ2d2TanOnIter.def(py::init<const GccEnt_QualifiedCirc &, const Geom2dGcc_QCurve &, const gp_Lin2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnLine"), py::arg("Param1"), py::arg("Param2"), py::arg("Param3"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnIter.def(py::init<const GccEnt_QualifiedLin &, const Geom2dGcc_QCurve &, const gp_Lin2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnLine"), py::arg("Param1"), py::arg("Param2"), py::arg("Param3"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnIter.def(py::init<const Geom2dGcc_QCurve &, const Geom2dGcc_QCurve &, const gp_Lin2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnLine"), py::arg("Param1"), py::arg("Param2"), py::arg("Param3"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnIter.def(py::init<const Geom2dGcc_QCurve &, const gp_Pnt2d &, const gp_Lin2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Point2"), py::arg("OnLine"), py::arg("Param1"), py::arg("Param2"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnIter.def(py::init<const GccEnt_QualifiedCirc &, const Geom2dGcc_QCurve &, const gp_Circ2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnCirc"), py::arg("Param1"), py::arg("Param2"), py::arg("Param3"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnIter.def(py::init<const GccEnt_QualifiedLin &, const Geom2dGcc_QCurve &, const gp_Circ2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnCirc"), py::arg("Param1"), py::arg("Param2"), py::arg("Param3"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnIter.def(py::init<const Geom2dGcc_QCurve &, const Geom2dGcc_QCurve &, const gp_Circ2d &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnCirc"), py::arg("Param1"), py::arg("Param2"), py::arg("Param3"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnIter.def(py::init<const Geom2dGcc_QCurve &, const gp_Pnt2d &, const gp_Circ2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Point2"), py::arg("OnCirc"), py::arg("Param1"), py::arg("Param2"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnIter.def(py::init<const GccEnt_QualifiedCirc &, const Geom2dGcc_QCurve &, const Geom2dAdaptor_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnCurv"), py::arg("Param1"), py::arg("Param2"), py::arg("ParamOn"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnIter.def(py::init<const GccEnt_QualifiedLin &, const Geom2dGcc_QCurve &, const Geom2dAdaptor_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnCurve"), py::arg("Param1"), py::arg("Param2"), py::arg("ParamOn"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnIter.def(py::init<const Geom2dGcc_QCurve &, const gp_Pnt2d &, const Geom2dAdaptor_Curve &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Point2"), py::arg("OnCurve"), py::arg("Param1"), py::arg("ParamOn"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanOnIter.def(py::init<const Geom2dGcc_QCurve &, const Geom2dGcc_QCurve &, const Geom2dAdaptor_Curve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("OnCurve"), py::arg("Param1"), py::arg("Param2"), py::arg("ParamOn"), py::arg("Tolerance"));

// Methods
// cls_Geom2dGcc_Circ2d2TanOnIter.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Circ2d2TanOnIter::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d2TanOnIter.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Circ2d2TanOnIter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanOnIter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Circ2d2TanOnIter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d2TanOnIter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Circ2d2TanOnIter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanOnIter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Circ2d2TanOnIter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanOnIter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Circ2d2TanOnIter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Circ2d2TanOnIter.def("IsDone", (Standard_Boolean (Geom2dGcc_Circ2d2TanOnIter::*)() const) &Geom2dGcc_Circ2d2TanOnIter::IsDone, "This method returns True if the construction algorithm succeeded.");
cls_Geom2dGcc_Circ2d2TanOnIter.def("ThisSolution", (gp_Circ2d (Geom2dGcc_Circ2d2TanOnIter::*)() const) &Geom2dGcc_Circ2d2TanOnIter::ThisSolution, "Returns the solution. It raises NotDone if the construction algorithm didn't succeed.");
cls_Geom2dGcc_Circ2d2TanOnIter.def("WhichQualifier", (void (Geom2dGcc_Circ2d2TanOnIter::*)(GccEnt_Position &, GccEnt_Position &) const) &Geom2dGcc_Circ2d2TanOnIter::WhichQualifier, "None", py::arg("Qualif1"), py::arg("Qualif2"));
cls_Geom2dGcc_Circ2d2TanOnIter.def("Tangency1", [](Geom2dGcc_Circ2d2TanOnIter &self, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns information about the tangency point between the result and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv. It raises NotDone if the construction algorithm didn't succeed.", py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d2TanOnIter.def("Tangency2", [](Geom2dGcc_Circ2d2TanOnIter &self, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency2(ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns information about the tangency point between the result and the second argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv. It raises NotDone if the construction algorithm didn't succeed.", py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d2TanOnIter.def("CenterOn3", [](Geom2dGcc_Circ2d2TanOnIter &self, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.CenterOn3(ParArg, PntSol); return ParArg; }, "Returns information about the center (on the curv) of the result and the third argument. It raises NotDone if the construction algorithm didn't succeed.", py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d2TanOnIter.def("IsTheSame1", (Standard_Boolean (Geom2dGcc_Circ2d2TanOnIter::*)() const) &Geom2dGcc_Circ2d2TanOnIter::IsTheSame1, "It raises NotDone if the construction algorithm didn't succeed.");
cls_Geom2dGcc_Circ2d2TanOnIter.def("IsTheSame2", (Standard_Boolean (Geom2dGcc_Circ2d2TanOnIter::*)() const) &Geom2dGcc_Circ2d2TanOnIter::IsTheSame2, "It raises NotDone if the construction algorithm didn't succeed.");

// CLASS: GEOM2DGCC_CIRC2D2TANRAD
py::class_<Geom2dGcc_Circ2d2TanRad> cls_Geom2dGcc_Circ2d2TanRad(mod, "Geom2dGcc_Circ2d2TanRad", "This class implements the algorithms used to create 2d circles tangent to one curve and a point/line/circle/curv and with a given radius. For each construction methods arguments are: - Two Qualified elements for tangency constrains. (for example EnclosedCirc if we want the solution inside the argument EnclosedCirc). - Two Reals. One (Radius) for the radius and the other (Tolerance) for the tolerance. Tolerance is only used for the limit cases. For example : We want to create a circle inside a circle C1 and inside a curve Cu2 with a radius Radius and a tolerance Tolerance. If we did not used Tolerance it is impossible to find a solution in the the following case : Cu2 is inside C1 and there is no intersection point between the two elements. with Tolerance we will give a solution if the lowest distance between C1 and Cu2 is lower than or equal Tolerance.");

// Constructors
cls_Geom2dGcc_Circ2d2TanRad.def(py::init<const Geom2dGcc_QualifiedCurve &, const Geom2dGcc_QualifiedCurve &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Radius"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanRad.def(py::init<const Geom2dGcc_QualifiedCurve &, const opencascade::handle<Geom2d_Point> &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Point"), py::arg("Radius"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanRad.def(py::init<const opencascade::handle<Geom2d_Point> &, const opencascade::handle<Geom2d_Point> &, const Standard_Real, const Standard_Real>(), py::arg("Point1"), py::arg("Point2"), py::arg("Radius"), py::arg("Tolerance"));

// Methods
// cls_Geom2dGcc_Circ2d2TanRad.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Circ2d2TanRad::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d2TanRad.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Circ2d2TanRad::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanRad.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Circ2d2TanRad::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d2TanRad.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Circ2d2TanRad::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanRad.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Circ2d2TanRad::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanRad.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Circ2d2TanRad::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Circ2d2TanRad.def("Results", (void (Geom2dGcc_Circ2d2TanRad::*)(const GccAna_Circ2d2TanRad &)) &Geom2dGcc_Circ2d2TanRad::Results, "None", py::arg("Circ"));
cls_Geom2dGcc_Circ2d2TanRad.def("Results", (void (Geom2dGcc_Circ2d2TanRad::*)(const Geom2dGcc_Circ2d2TanRadGeo &)) &Geom2dGcc_Circ2d2TanRad::Results, "None", py::arg("Circ"));
cls_Geom2dGcc_Circ2d2TanRad.def("IsDone", (Standard_Boolean (Geom2dGcc_Circ2d2TanRad::*)() const) &Geom2dGcc_Circ2d2TanRad::IsDone, "This method returns True if the algorithm succeeded. Note: IsDone protects against a failure arising from a more internal intersection algorithm, which has reached its numeric limits.");
cls_Geom2dGcc_Circ2d2TanRad.def("NbSolutions", (Standard_Integer (Geom2dGcc_Circ2d2TanRad::*)() const) &Geom2dGcc_Circ2d2TanRad::NbSolutions, "This method returns the number of solutions. NotDone is raised if the algorithm failed. Exceptions StdFail_NotDone if the construction fails.");
cls_Geom2dGcc_Circ2d2TanRad.def("ThisSolution", (gp_Circ2d (Geom2dGcc_Circ2d2TanRad::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d2TanRad::ThisSolution, "Returns the solution number Index and raises OutOfRange exception if Index is greater than the number of solutions. Be carefull: the Index is only a way to get all the solutions, but is not associated to theses outside the context of the algorithm-object. Warning This indexing simply provides a means of consulting the solutions. The index values are not associated with these solutions outside the context of the algorithm object. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"));
cls_Geom2dGcc_Circ2d2TanRad.def("WhichQualifier", (void (Geom2dGcc_Circ2d2TanRad::*)(const Standard_Integer, GccEnt_Position &, GccEnt_Position &) const) &Geom2dGcc_Circ2d2TanRad::WhichQualifier, "Returns the qualifiers Qualif1 and Qualif2 of the tangency arguments for the solution of index Index computed by this algorithm. The returned qualifiers are: - those specified at the start of construction when the solutions are defined as enclosed, enclosing or outside with respect to the arguments, or - those computed during construction (i.e. enclosed, enclosing or outside) when the solutions are defined as unqualified with respect to the arguments, or - GccEnt_noqualifier if the tangency argument is a point, or - GccEnt_unqualified in certain limit cases where it is impossible to qualify the solution as enclosed, enclosing or outside. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("Qualif1"), py::arg("Qualif2"));
cls_Geom2dGcc_Circ2d2TanRad.def("Tangency1", [](Geom2dGcc_Circ2d2TanRad &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result number Index and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv. OutOfRange is raised if Index is greater than the number of solutions. notDone is raised if the construction algorithm did not succeed.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d2TanRad.def("Tangency2", [](Geom2dGcc_Circ2d2TanRad &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency2(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result number Index and the second argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv. OutOfRange is raised if Index is greater than the number of solutions. notDone is raised if the construction algorithm did not succeed.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d2TanRad.def("IsTheSame1", (Standard_Boolean (Geom2dGcc_Circ2d2TanRad::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d2TanRad::IsTheSame1, "Returns true if the solution of index Index and, respectively, the first or second argument of this algorithm are the same (i.e. there are 2 identical circles). If Rarg is the radius of the first or second argument, Rsol is the radius of the solution and dist is the distance between the two centers, we consider the two circles to be identical if |Rarg - Rsol| and dist are less than or equal to the tolerance criterion given at the time of construction of this algorithm. OutOfRange is raised if Index is greater than the number of solutions. notDone is raised if the construction algorithm did not succeed.", py::arg("Index"));
cls_Geom2dGcc_Circ2d2TanRad.def("IsTheSame2", (Standard_Boolean (Geom2dGcc_Circ2d2TanRad::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d2TanRad::IsTheSame2, "Returns true if the solution of index Index and, respectively, the first or second argument of this algorithm are the same (i.e. there are 2 identical circles). If Rarg is the radius of the first or second argument, Rsol is the radius of the solution and dist is the distance between the two centers, we consider the two circles to be identical if |Rarg - Rsol| and dist are less than or equal to the tolerance criterion given at the time of construction of this algorithm. OutOfRange is raised if Index is greater than the number of solutions. notDone is raised if the construction algorithm did not succeed.", py::arg("Index"));

// CLASS: GEOM2DGCC_CIRC2D2TANRADGEO
py::class_<Geom2dGcc_Circ2d2TanRadGeo> cls_Geom2dGcc_Circ2d2TanRadGeo(mod, "Geom2dGcc_Circ2d2TanRadGeo", "This class implements the algorithms used to create 2d circles tangent to one curve and a point/line/circle/curv and with a given radius. For each construction methods arguments are: - Two Qualified elements for tangency constrains. (for example EnclosedCirc if we want the solution inside the argument EnclosedCirc). - Two Reals. One (Radius) for the radius and the other (Tolerance) for the tolerance. Tolerance is only used for the limit cases. For example : We want to create a circle inside a circle C1 and inside a curve Cu2 with a radius Radius and a tolerance Tolerance. If we did not used Tolerance it is impossible to find a solution in the following case : Cu2 is inside C1 and there is no intersection point between the two elements. With Tolerance we will get a solution if the lowest distance between C1 and Cu2 is lower than or equal Tolerance.");

// Constructors
cls_Geom2dGcc_Circ2d2TanRadGeo.def(py::init<const GccEnt_QualifiedCirc &, const Geom2dGcc_QCurve &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Radius"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanRadGeo.def(py::init<const GccEnt_QualifiedLin &, const Geom2dGcc_QCurve &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Radius"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanRadGeo.def(py::init<const Geom2dGcc_QCurve &, const Geom2dGcc_QCurve &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Radius"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d2TanRadGeo.def(py::init<const Geom2dGcc_QCurve &, const gp_Pnt2d &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Point2"), py::arg("Radius"), py::arg("Tolerance"));

// Methods
// cls_Geom2dGcc_Circ2d2TanRadGeo.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Circ2d2TanRadGeo::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d2TanRadGeo.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Circ2d2TanRadGeo::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanRadGeo.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Circ2d2TanRadGeo::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d2TanRadGeo.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Circ2d2TanRadGeo::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanRadGeo.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Circ2d2TanRadGeo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d2TanRadGeo.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Circ2d2TanRadGeo::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Circ2d2TanRadGeo.def("IsDone", (Standard_Boolean (Geom2dGcc_Circ2d2TanRadGeo::*)() const) &Geom2dGcc_Circ2d2TanRadGeo::IsDone, "This method returns True if the algorithm succeeded.");
cls_Geom2dGcc_Circ2d2TanRadGeo.def("NbSolutions", (Standard_Integer (Geom2dGcc_Circ2d2TanRadGeo::*)() const) &Geom2dGcc_Circ2d2TanRadGeo::NbSolutions, "This method returns the number of solutions. It raises NotDone if the algorithm failed.");
cls_Geom2dGcc_Circ2d2TanRadGeo.def("ThisSolution", (gp_Circ2d (Geom2dGcc_Circ2d2TanRadGeo::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d2TanRadGeo::ThisSolution, "Returns the solution number Index. Be careful: the Index is only a way to get all the solutions, but is not associated to those outside the context of the algorithm-object. It raises OutOfRange exception if Index is greater than the number of solutions. It raises NotDone if the construction algorithm did not succeed.", py::arg("Index"));
cls_Geom2dGcc_Circ2d2TanRadGeo.def("WhichQualifier", (void (Geom2dGcc_Circ2d2TanRadGeo::*)(const Standard_Integer, GccEnt_Position &, GccEnt_Position &) const) &Geom2dGcc_Circ2d2TanRadGeo::WhichQualifier, "It returns the information about the qualifiers of the tangency arguments concerning the solution number Index. It returns the real qualifiers (the qualifiers given to the constructor method in case of enclosed, enclosing and outside and the qualifiers computedin case of unqualified).", py::arg("Index"), py::arg("Qualif1"), py::arg("Qualif2"));
cls_Geom2dGcc_Circ2d2TanRadGeo.def("Tangency1", [](Geom2dGcc_Circ2d2TanRadGeo &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns information about the tangency point between the result number Index and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution. ParArg is the intrinsic parameter of the point PntSol on the first argument. It raises OutOfRange if Index is greater than the number of solutions. It raises NotDone if the construction algorithm did not succeed.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d2TanRadGeo.def("Tangency2", [](Geom2dGcc_Circ2d2TanRadGeo &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency2(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns information about the tangency point between the result number Index and the second argument. ParSol is the intrinsic parameter of the point PntSol on the solution. ParArg is the intrinsic parameter of the point PntArg on the second argument. It raises OutOfRange if Index is greater than the number of solutions. It raises NotDone if the construction algorithm did not succeed.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d2TanRadGeo.def("IsTheSame1", (Standard_Boolean (Geom2dGcc_Circ2d2TanRadGeo::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d2TanRadGeo::IsTheSame1, "Returns True if the solution number Index is equal to the first argument. It raises OutOfRange if Index is greater than the number of solutions. It raises NotDone if the construction algorithm did not succeed.", py::arg("Index"));
cls_Geom2dGcc_Circ2d2TanRadGeo.def("IsTheSame2", (Standard_Boolean (Geom2dGcc_Circ2d2TanRadGeo::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d2TanRadGeo::IsTheSame2, "Returns True if the solution number Index is equal to the second argument. It raises OutOfRange if Index is greater than the number of solutions. It raises NotDone if the construction algorithm did not succeed.", py::arg("Index"));

// CLASS: GEOM2DGCC_CIRC2D3TAN
py::class_<Geom2dGcc_Circ2d3Tan> cls_Geom2dGcc_Circ2d3Tan(mod, "Geom2dGcc_Circ2d3Tan", "This class implements the algorithms used to create 2d circles tangent to 3 points/lines/circles/ curves with one curve or more. The arguments of all construction methods are : - The three qualifiied elements for the tangency constrains (QualifiedCirc, QualifiedLine, Qualifiedcurv, Points). - A parameter for each QualifiedCurv. Describes functions for building a 2D circle: - tangential to 3 curves, or - tangential to 2 curves and passing through a point, or - tangential to a curve and passing through 2 points, or - passing through 3 points. A Circ2d3Tan object provides a framework for: - defining the construction of 2D circles(s), - implementing the construction algorithm, and - consulting the result(s).");

// Constructors
cls_Geom2dGcc_Circ2d3Tan.def(py::init<const Geom2dGcc_QualifiedCurve &, const Geom2dGcc_QualifiedCurve &, const Geom2dGcc_QualifiedCurve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Qualified3"), py::arg("Tolerance"), py::arg("Param1"), py::arg("Param2"), py::arg("Param3"));
cls_Geom2dGcc_Circ2d3Tan.def(py::init<const Geom2dGcc_QualifiedCurve &, const Geom2dGcc_QualifiedCurve &, const opencascade::handle<Geom2d_Point> &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Point"), py::arg("Tolerance"), py::arg("Param1"), py::arg("Param2"));
cls_Geom2dGcc_Circ2d3Tan.def(py::init<const Geom2dGcc_QualifiedCurve &, const opencascade::handle<Geom2d_Point> &, const opencascade::handle<Geom2d_Point> &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Point1"), py::arg("Point2"), py::arg("Tolerance"), py::arg("Param1"));
cls_Geom2dGcc_Circ2d3Tan.def(py::init<const opencascade::handle<Geom2d_Point> &, const opencascade::handle<Geom2d_Point> &, const opencascade::handle<Geom2d_Point> &, const Standard_Real>(), py::arg("Point1"), py::arg("Point2"), py::arg("Point3"), py::arg("Tolerance"));

// Methods
// cls_Geom2dGcc_Circ2d3Tan.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Circ2d3Tan::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d3Tan.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Circ2d3Tan::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d3Tan.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Circ2d3Tan::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d3Tan.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Circ2d3Tan::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d3Tan.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Circ2d3Tan::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d3Tan.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Circ2d3Tan::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Circ2d3Tan.def("Results", (void (Geom2dGcc_Circ2d3Tan::*)(const GccAna_Circ2d3Tan &, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &Geom2dGcc_Circ2d3Tan::Results, "None", py::arg("Circ"), py::arg("Rank1"), py::arg("Rank2"), py::arg("Rank3"));
cls_Geom2dGcc_Circ2d3Tan.def("IsDone", (Standard_Boolean (Geom2dGcc_Circ2d3Tan::*)() const) &Geom2dGcc_Circ2d3Tan::IsDone, "Returns true if the construction algorithm does not fail (even if it finds no solution). Note: IsDone protects against a failure arising from a more internal intersection algorithm, which has reached its numeric limits.");
cls_Geom2dGcc_Circ2d3Tan.def("NbSolutions", (Standard_Integer (Geom2dGcc_Circ2d3Tan::*)() const) &Geom2dGcc_Circ2d3Tan::NbSolutions, "This method returns the number of solutions. NotDone is raised if the algorithm failed.");
cls_Geom2dGcc_Circ2d3Tan.def("ThisSolution", (gp_Circ2d (Geom2dGcc_Circ2d3Tan::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d3Tan::ThisSolution, "Returns the solution number Index and raises OutOfRange exception if Index is greater than the number of solutions. Be carefull: the Index is only a way to get all the solutions, but is not associated to theses outside the context of the algorithm-object.", py::arg("Index"));
cls_Geom2dGcc_Circ2d3Tan.def("WhichQualifier", (void (Geom2dGcc_Circ2d3Tan::*)(const Standard_Integer, GccEnt_Position &, GccEnt_Position &, GccEnt_Position &) const) &Geom2dGcc_Circ2d3Tan::WhichQualifier, "It returns the informations about the qualifiers of the tangency arguments concerning the solution number Index. It returns the real qualifiers (the qualifiers given to the constructor method in case of enclosed, enclosing and outside and the qualifiers computedin case of unqualified).", py::arg("Index"), py::arg("Qualif1"), py::arg("Qualif2"), py::arg("Qualif3"));
cls_Geom2dGcc_Circ2d3Tan.def("Tangency1", [](Geom2dGcc_Circ2d3Tan &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d3Tan.def("Tangency2", [](Geom2dGcc_Circ2d3Tan &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency2(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result and the second argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d3Tan.def("Tangency3", [](Geom2dGcc_Circ2d3Tan &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency3(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result and the third argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d3Tan.def("IsTheSame1", (Standard_Boolean (Geom2dGcc_Circ2d3Tan::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d3Tan::IsTheSame1, "Returns True if the solution is equal to the first argument.", py::arg("Index"));
cls_Geom2dGcc_Circ2d3Tan.def("IsTheSame2", (Standard_Boolean (Geom2dGcc_Circ2d3Tan::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d3Tan::IsTheSame2, "Returns True if the solution is equal to the second argument.", py::arg("Index"));
cls_Geom2dGcc_Circ2d3Tan.def("IsTheSame3", (Standard_Boolean (Geom2dGcc_Circ2d3Tan::*)(const Standard_Integer) const) &Geom2dGcc_Circ2d3Tan::IsTheSame3, "Returns True if the solution is equal to the third argument. If Rarg is the radius of the first, second or third argument, Rsol is the radius of the solution and dist is the distance between the two centers, we consider the two circles to be identical if |Rarg - Rsol| and dist are less than or equal to the tolerance criterion given at the time of construction of this algorithm. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"));

// CLASS: GEOM2DGCC_CIRC2D3TANITER
py::class_<Geom2dGcc_Circ2d3TanIter> cls_Geom2dGcc_Circ2d3TanIter(mod, "Geom2dGcc_Circ2d3TanIter", "This class implements the algorithms used to create 2d circles tangent to 3 points/lines/circles/ curves with one curve or more. The arguments of all construction methods are : - The three qualifiied elements for the tangency constrains (QualifiedCirc, QualifiedLine, Qualifiedcurv, Points). - A parameter for each QualifiedCurv.");

// Constructors
cls_Geom2dGcc_Circ2d3TanIter.def(py::init<const GccEnt_QualifiedCirc &, const GccEnt_QualifiedCirc &, const Geom2dGcc_QCurve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Qualified3"), py::arg("Param1"), py::arg("Param2"), py::arg("Param3"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d3TanIter.def(py::init<const GccEnt_QualifiedCirc &, const Geom2dGcc_QCurve &, const Geom2dGcc_QCurve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Qualified3"), py::arg("Param1"), py::arg("Param2"), py::arg("Param3"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d3TanIter.def(py::init<const GccEnt_QualifiedCirc &, const GccEnt_QualifiedLin &, const Geom2dGcc_QCurve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Qualified3"), py::arg("Param1"), py::arg("Param2"), py::arg("Param3"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d3TanIter.def(py::init<const GccEnt_QualifiedCirc &, const Geom2dGcc_QCurve &, const gp_Pnt2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Point3"), py::arg("Param1"), py::arg("Param2"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d3TanIter.def(py::init<const GccEnt_QualifiedLin &, const GccEnt_QualifiedLin &, const Geom2dGcc_QCurve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Qualified3"), py::arg("Param1"), py::arg("Param2"), py::arg("Param3"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d3TanIter.def(py::init<const GccEnt_QualifiedLin &, const Geom2dGcc_QCurve &, const Geom2dGcc_QCurve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Qualified3"), py::arg("Param1"), py::arg("Param2"), py::arg("Param3"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d3TanIter.def(py::init<const GccEnt_QualifiedLin &, const Geom2dGcc_QCurve &, const gp_Pnt2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Point3"), py::arg("Param1"), py::arg("Param2"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d3TanIter.def(py::init<const Geom2dGcc_QCurve &, const gp_Pnt2d &, const gp_Pnt2d &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Point1"), py::arg("Point2"), py::arg("Param1"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d3TanIter.def(py::init<const Geom2dGcc_QCurve &, const Geom2dGcc_QCurve &, const gp_Pnt2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Point2"), py::arg("Param1"), py::arg("Param2"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2d3TanIter.def(py::init<const Geom2dGcc_QCurve &, const Geom2dGcc_QCurve &, const Geom2dGcc_QCurve &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Qualified3"), py::arg("Param1"), py::arg("Param2"), py::arg("Param3"), py::arg("Tolerance"));

// Methods
// cls_Geom2dGcc_Circ2d3TanIter.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Circ2d3TanIter::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d3TanIter.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Circ2d3TanIter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d3TanIter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Circ2d3TanIter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2d3TanIter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Circ2d3TanIter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d3TanIter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Circ2d3TanIter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Circ2d3TanIter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Circ2d3TanIter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Circ2d3TanIter.def("IsDone", (Standard_Boolean (Geom2dGcc_Circ2d3TanIter::*)() const) &Geom2dGcc_Circ2d3TanIter::IsDone, "This method returns True if the construction algorithm succeeded.");
cls_Geom2dGcc_Circ2d3TanIter.def("ThisSolution", (gp_Circ2d (Geom2dGcc_Circ2d3TanIter::*)() const) &Geom2dGcc_Circ2d3TanIter::ThisSolution, "Returns the solution. It raises NotDone if the construction algorithm didn't succeed.");
cls_Geom2dGcc_Circ2d3TanIter.def("WhichQualifier", (void (Geom2dGcc_Circ2d3TanIter::*)(GccEnt_Position &, GccEnt_Position &, GccEnt_Position &) const) &Geom2dGcc_Circ2d3TanIter::WhichQualifier, "None", py::arg("Qualif1"), py::arg("Qualif2"), py::arg("Qualif3"));
cls_Geom2dGcc_Circ2d3TanIter.def("Tangency1", [](Geom2dGcc_Circ2d3TanIter &self, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv. It raises NotDone if the construction algorithm didn't succeed.", py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d3TanIter.def("Tangency2", [](Geom2dGcc_Circ2d3TanIter &self, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency2(ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result and the second argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv. It raises NotDone if the construction algorithm didn't succeed.", py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d3TanIter.def("Tangency3", [](Geom2dGcc_Circ2d3TanIter &self, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency3(ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result and the third argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv. It raises NotDone if the construction algorithm didn't succeed.", py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2d3TanIter.def("IsTheSame1", (Standard_Boolean (Geom2dGcc_Circ2d3TanIter::*)() const) &Geom2dGcc_Circ2d3TanIter::IsTheSame1, "It raises NotDone if the construction algorithm didn't succeed.");
cls_Geom2dGcc_Circ2d3TanIter.def("IsTheSame2", (Standard_Boolean (Geom2dGcc_Circ2d3TanIter::*)() const) &Geom2dGcc_Circ2d3TanIter::IsTheSame2, "It raises NotDone if the construction algorithm didn't succeed.");
cls_Geom2dGcc_Circ2d3TanIter.def("IsTheSame3", (Standard_Boolean (Geom2dGcc_Circ2d3TanIter::*)() const) &Geom2dGcc_Circ2d3TanIter::IsTheSame3, "It raises NotDone if the construction algorithm didn't succeed.");

// CLASS: GEOM2DGCC_CIRC2DTANCEN
py::class_<Geom2dGcc_Circ2dTanCen> cls_Geom2dGcc_Circ2dTanCen(mod, "Geom2dGcc_Circ2dTanCen", "This class implements the algorithms used to create 2d circles tangent to a curve and centered on a point. The arguments of all construction methods are : - The qualified element for the tangency constrains (QualifiedCurv). -The center point Pcenter. - A real Tolerance. Tolerance is only used in the limits cases. For example : We want to create a circle tangent to an EnclosedCurv C1 with a tolerance Tolerance. If we did not used Tolerance it is impossible to find a solution in the the following case : Pcenter is outside C1. With Tolerance we will give a solution if the distance between C1 and Pcenter is lower than or equal Tolerance/2.");

// Constructors
cls_Geom2dGcc_Circ2dTanCen.def(py::init<const Geom2dGcc_QualifiedCurve &, const opencascade::handle<Geom2d_Point> &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Pcenter"), py::arg("Tolerance"));

// Methods
// cls_Geom2dGcc_Circ2dTanCen.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Circ2dTanCen::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2dTanCen.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Circ2dTanCen::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2dTanCen.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Circ2dTanCen::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2dTanCen.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Circ2dTanCen::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2dTanCen.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Circ2dTanCen::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Circ2dTanCen.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Circ2dTanCen::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Circ2dTanCen.def("IsDone", (Standard_Boolean (Geom2dGcc_Circ2dTanCen::*)() const) &Geom2dGcc_Circ2dTanCen::IsDone, "Returns true if the construction algorithm does not fail (even if it finds no solution). Note: IsDone protects against a failure arising from a more internal intersection algorithm, which has reached its numeric limits.");
cls_Geom2dGcc_Circ2dTanCen.def("NbSolutions", (Standard_Integer (Geom2dGcc_Circ2dTanCen::*)() const) &Geom2dGcc_Circ2dTanCen::NbSolutions, "Returns the number of circles, representing solutions computed by this algorithm. Exceptions StdFail_NotDone if the construction fails.");
cls_Geom2dGcc_Circ2dTanCen.def("ThisSolution", (gp_Circ2d (Geom2dGcc_Circ2dTanCen::*)(const Standard_Integer) const) &Geom2dGcc_Circ2dTanCen::ThisSolution, "Returns a circle, representing the solution of index Index computed by this algorithm. Warning This indexing simply provides a means of consulting the solutions. The index values are not associated with these solutions outside the context of the algorithm object. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails", py::arg("Index"));
cls_Geom2dGcc_Circ2dTanCen.def("WhichQualifier", (void (Geom2dGcc_Circ2dTanCen::*)(const Standard_Integer, GccEnt_Position &) const) &Geom2dGcc_Circ2dTanCen::WhichQualifier, "Returns the qualifier Qualif1 of the tangency argument for the solution of index Index computed by this algorithm. The returned qualifier is: - that specified at the start of construction when the solutions are defined as enclosed, enclosing or outside with respect to the argument, or - that computed during construction (i.e. enclosed, enclosing or outside) when the solutions are defined as unqualified with respect to the argument. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("Qualif1"));
cls_Geom2dGcc_Circ2dTanCen.def("Tangency1", [](Geom2dGcc_Circ2dTanCen &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result number Index and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2dTanCen.def("IsTheSame1", (Standard_Boolean (Geom2dGcc_Circ2dTanCen::*)(const Standard_Integer) const) &Geom2dGcc_Circ2dTanCen::IsTheSame1, "Returns true if the solution of index Index and the first argument of this algorithm are the same (i.e. there are 2 identical circles). If Rarg is the radius of the first argument, Rsol is the radius of the solution and dist is the distance between the two centers, we consider the two circles to be identical if |Rarg - Rsol| and dist are less than or equal to the tolerance criterion given at the time of construction of this algorithm. NotDone is raised if the construction algorithm didn't succeed. OutOfRange is raised if Index is greater than the number of solutions.", py::arg("Index"));

// CLASS: GEOM2DGCC_CIRC2DTANCENGEO
py::class_<Geom2dGcc_Circ2dTanCenGeo> cls_Geom2dGcc_Circ2dTanCenGeo(mod, "Geom2dGcc_Circ2dTanCenGeo", "This class implements the algorithms used to create 2d circles tangent to a curve and centered on a point. The arguments of all construction methods are : - The qualified element for the tangency constrains (QualifiedCurv). -The center point Pcenter. - A real Tolerance. Tolerance is only used in the limits cases. For example : We want to create a circle tangent to an EnclosedCurv C1 with a tolerance Tolerance. If we did not use Tolerance it is impossible to find a solution in the following case : Pcenter is outside C1. With Tolerance we will give a solution if the distance between C1 and Pcenter is lower than or equal Tolerance/2.");

// Constructors
cls_Geom2dGcc_Circ2dTanCenGeo.def(py::init<const Geom2dGcc_QCurve &, const gp_Pnt2d &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Pcenter"), py::arg("Tolerance"));

// Methods
// cls_Geom2dGcc_Circ2dTanCenGeo.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Circ2dTanCenGeo::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2dTanCenGeo.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Circ2dTanCenGeo::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2dTanCenGeo.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Circ2dTanCenGeo::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2dTanCenGeo.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Circ2dTanCenGeo::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2dTanCenGeo.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Circ2dTanCenGeo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Circ2dTanCenGeo.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Circ2dTanCenGeo::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Circ2dTanCenGeo.def("IsDone", (Standard_Boolean (Geom2dGcc_Circ2dTanCenGeo::*)() const) &Geom2dGcc_Circ2dTanCenGeo::IsDone, "This method returns True if the construction algorithm succeeded.");
cls_Geom2dGcc_Circ2dTanCenGeo.def("NbSolutions", (Standard_Integer (Geom2dGcc_Circ2dTanCenGeo::*)() const) &Geom2dGcc_Circ2dTanCenGeo::NbSolutions, "Returns the number of solutions and raises NotDone exception if the algorithm didn't succeed. It raises NotDone if the construction algorithm didn't succeed.");
cls_Geom2dGcc_Circ2dTanCenGeo.def("ThisSolution", (gp_Circ2d (Geom2dGcc_Circ2dTanCenGeo::*)(const Standard_Integer) const) &Geom2dGcc_Circ2dTanCenGeo::ThisSolution, "Returns the solution number Index and raises OutOfRange exception if Index is greater than the number of solutions. Be carefull: the Index is only a way to get all the solutions, but is not associated to theses outside the context of the algorithm-object. It raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions or less than zero.", py::arg("Index"));
cls_Geom2dGcc_Circ2dTanCenGeo.def("WhichQualifier", (void (Geom2dGcc_Circ2dTanCenGeo::*)(const Standard_Integer, GccEnt_Position &) const) &Geom2dGcc_Circ2dTanCenGeo::WhichQualifier, "None", py::arg("Index"), py::arg("Qualif1"));
cls_Geom2dGcc_Circ2dTanCenGeo.def("Tangency1", [](Geom2dGcc_Circ2dTanCenGeo &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result number Index and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntArg on the argument curv. It raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions or less than zero.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));

// CLASS: GEOM2DGCC_CIRC2DTANONRAD
py::class_<Geom2dGcc_Circ2dTanOnRad> cls_Geom2dGcc_Circ2dTanOnRad(mod, "Geom2dGcc_Circ2dTanOnRad", "This class implements the algorithms used to create a 2d circle tangent to a 2d entity, centered on a 2d entity and with a given radius. More than one argument must be a curve. The arguments of all construction methods are : - The qualified element for the tangency constrains (QualifiedCirc, QualifiedLin, QualifiedCurvPoints). - The Center element (circle, line, curve). - A real Tolerance. Tolerance is only used in the limits cases. For example : We want to create a circle tangent to an OutsideCurv Cu1 centered on a line OnLine with a radius Radius and with a tolerance Tolerance. If we did not used Tolerance it is impossible to find a solution in the the following case : OnLine is outside Cu1. There is no intersection point between Cu1 and OnLine. The distance between the line and the circle is greater than Radius. With Tolerance we will give a solution if the distance between Cu1 and OnLine is lower than or equal Tolerance.");

// Constructors
cls_Geom2dGcc_Circ2dTanOnRad.def(py::init<const Geom2dGcc_QualifiedCurve &, const Geom2dAdaptor_Curve &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("OnCurv"), py::arg("Radius"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2dTanOnRad.def(py::init<const opencascade::handle<Geom2d_Point> &, const Geom2dAdaptor_Curve &, const Standard_Real, const Standard_Real>(), py::arg("Point1"), py::arg("OnCurv"), py::arg("Radius"), py::arg("Tolerance"));

// Methods
// cls_Geom2dGcc_Circ2dTanOnRad.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Circ2dTanOnRad::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2dTanOnRad.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Circ2dTanOnRad::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2dTanOnRad.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Circ2dTanOnRad::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2dTanOnRad.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Circ2dTanOnRad::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2dTanOnRad.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Circ2dTanOnRad::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Circ2dTanOnRad.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Circ2dTanOnRad::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Circ2dTanOnRad.def("Results", (void (Geom2dGcc_Circ2dTanOnRad::*)(const GccAna_Circ2dTanOnRad &)) &Geom2dGcc_Circ2dTanOnRad::Results, "None", py::arg("Circ"));
cls_Geom2dGcc_Circ2dTanOnRad.def("Results", (void (Geom2dGcc_Circ2dTanOnRad::*)(const Geom2dGcc_Circ2dTanOnRadGeo &)) &Geom2dGcc_Circ2dTanOnRad::Results, "None", py::arg("Circ"));
cls_Geom2dGcc_Circ2dTanOnRad.def("IsDone", (Standard_Boolean (Geom2dGcc_Circ2dTanOnRad::*)() const) &Geom2dGcc_Circ2dTanOnRad::IsDone, "Returns true if the construction algorithm does not fail (even if it finds no solution). Note: IsDone protects against a failure arising from a more internal intersection algorithm which has reached its numeric limits.");
cls_Geom2dGcc_Circ2dTanOnRad.def("NbSolutions", (Standard_Integer (Geom2dGcc_Circ2dTanOnRad::*)() const) &Geom2dGcc_Circ2dTanOnRad::NbSolutions, "Returns the number of circles, representing solutions computed by this algorithm. Exceptions: StdFail_NotDone if the construction fails.");
cls_Geom2dGcc_Circ2dTanOnRad.def("ThisSolution", (gp_Circ2d (Geom2dGcc_Circ2dTanOnRad::*)(const Standard_Integer) const) &Geom2dGcc_Circ2dTanOnRad::ThisSolution, "Returns the solution number Index and raises OutOfRange exception if Index is greater than the number of solutions. Be carefull: the Index is only a way to get all the solutions, but is not associated to theses outside the context of the algorithm-object. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"));
cls_Geom2dGcc_Circ2dTanOnRad.def("WhichQualifier", (void (Geom2dGcc_Circ2dTanOnRad::*)(const Standard_Integer, GccEnt_Position &) const) &Geom2dGcc_Circ2dTanOnRad::WhichQualifier, "Returns the qualifier Qualif1 of the tangency argument for the solution of index Index computed by this algorithm. The returned qualifier is: - that specified at the start of construction when the solutions are defined as enclosed, enclosing or outside with respect to the arguments, or - that computed during construction (i.e. enclosed, enclosing or outside) when the solutions are defined as unqualified with respect to the arguments, or - GccEnt_noqualifier if the tangency argument is a point. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("Qualif1"));
cls_Geom2dGcc_Circ2dTanOnRad.def("Tangency1", [](Geom2dGcc_Circ2dTanOnRad &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result number Index and the first argument. ParSol is the intrinsic parameter of the point on the solution curv. ParArg is the intrinsic parameter of the point on the argument curv. PntSol is the tangency point on the solution curv. PntArg is the tangency point on the argument curv. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2dTanOnRad.def("CenterOn3", [](Geom2dGcc_Circ2dTanOnRad &self, const Standard_Integer Index, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.CenterOn3(Index, ParArg, PntSol); return ParArg; }, "Returns the center PntSol on the second argument (i.e. line or circle) of the solution of index Index computed by this algorithm. ParArg is the intrinsic parameter of the point on the argument curv. PntSol is the center point of the solution curv. PntArg is the projection of PntSol on the argument curv. Exceptions: Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2dTanOnRad.def("IsTheSame1", (Standard_Boolean (Geom2dGcc_Circ2dTanOnRad::*)(const Standard_Integer) const) &Geom2dGcc_Circ2dTanOnRad::IsTheSame1, "Returns true if the solution of index Index and the first argument of this algorithm are the same (i.e. there are 2 identical circles). If Rarg is the radius of the first argument, Rsol is the radius of the solution and dist is the distance between the two centers, we consider the two circles to be identical if |Rarg - Rsol| and dist are less than or equal to the tolerance criterion given at the time of construction of this algorithm. OutOfRange is raised if Index is greater than the number of solutions. notDone is raised if the construction algorithm did not succeed.", py::arg("Index"));

// CLASS: GEOM2DGCC_CIRC2DTANONRADGEO
py::class_<Geom2dGcc_Circ2dTanOnRadGeo> cls_Geom2dGcc_Circ2dTanOnRadGeo(mod, "Geom2dGcc_Circ2dTanOnRadGeo", "This class implements the algorithms used to create a 2d circle tangent to a 2d entity, centered on a 2d entity and with a given radius. More than one argument must be a curve. The arguments of all construction methods are : - The qualified element for the tangency constrains (QualifiedCirc, QualifiedLin, QualifiedCurvPoints). - The Center element (circle, line, curve). - A real Tolerance. Tolerance is only used in the limits cases. For example : We want to create a circle tangent to an OutsideCurv Cu1 centered on a line OnLine with a radius Radius and with a tolerance Tolerance. If we did not use Tolerance it is impossible to find a solution in the following case : OnLine is outside Cu1. There is no intersection point between Cu1 and OnLine. The distance between the line and the circle is greater than Radius. With Tolerance we will give a solution if the distance between Cu1 and OnLine is lower than or equal Tolerance.");

// Constructors
cls_Geom2dGcc_Circ2dTanOnRadGeo.def(py::init<const Geom2dGcc_QCurve &, const gp_Lin2d &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("OnLine"), py::arg("Radius"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2dTanOnRadGeo.def(py::init<const Geom2dGcc_QCurve &, const gp_Circ2d &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("OnCirc"), py::arg("Radius"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2dTanOnRadGeo.def(py::init<const GccEnt_QualifiedCirc &, const Geom2dAdaptor_Curve &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("OnCurv"), py::arg("Radius"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2dTanOnRadGeo.def(py::init<const GccEnt_QualifiedLin &, const Geom2dAdaptor_Curve &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("OnCurv"), py::arg("Radius"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2dTanOnRadGeo.def(py::init<const Geom2dGcc_QCurve &, const Geom2dAdaptor_Curve &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("OnCurv"), py::arg("Radius"), py::arg("Tolerance"));
cls_Geom2dGcc_Circ2dTanOnRadGeo.def(py::init<const gp_Pnt2d &, const Geom2dAdaptor_Curve &, const Standard_Real, const Standard_Real>(), py::arg("Point1"), py::arg("OnCurv"), py::arg("Radius"), py::arg("Tolerance"));

// Methods
// cls_Geom2dGcc_Circ2dTanOnRadGeo.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Circ2dTanOnRadGeo::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2dTanOnRadGeo.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Circ2dTanOnRadGeo::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2dTanOnRadGeo.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Circ2dTanOnRadGeo::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Circ2dTanOnRadGeo.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Circ2dTanOnRadGeo::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Circ2dTanOnRadGeo.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Circ2dTanOnRadGeo::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Circ2dTanOnRadGeo.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Circ2dTanOnRadGeo::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Circ2dTanOnRadGeo.def("IsDone", (Standard_Boolean (Geom2dGcc_Circ2dTanOnRadGeo::*)() const) &Geom2dGcc_Circ2dTanOnRadGeo::IsDone, "This method returns True if the construction algorithm succeeded.");
cls_Geom2dGcc_Circ2dTanOnRadGeo.def("NbSolutions", (Standard_Integer (Geom2dGcc_Circ2dTanOnRadGeo::*)() const) &Geom2dGcc_Circ2dTanOnRadGeo::NbSolutions, "This method returns the number of solutions. It raises NotDone if the construction algorithm didn't succeed.");
cls_Geom2dGcc_Circ2dTanOnRadGeo.def("ThisSolution", (gp_Circ2d (Geom2dGcc_Circ2dTanOnRadGeo::*)(const Standard_Integer) const) &Geom2dGcc_Circ2dTanOnRadGeo::ThisSolution, "Returns the solution number Index and raises OutOfRange exception if Index is greater than the number of solutions. Be careful: the Index is only a way to get all the solutions, but is not associated to theses outside the context of the algorithm-object. It raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"));
cls_Geom2dGcc_Circ2dTanOnRadGeo.def("WhichQualifier", (void (Geom2dGcc_Circ2dTanOnRadGeo::*)(const Standard_Integer, GccEnt_Position &) const) &Geom2dGcc_Circ2dTanOnRadGeo::WhichQualifier, "None", py::arg("Index"), py::arg("Qualif1"));
cls_Geom2dGcc_Circ2dTanOnRadGeo.def("Tangency1", [](Geom2dGcc_Circ2dTanOnRadGeo &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result number Index and the first argument. ParSol is the intrinsic parameter of the point on the solution curv. ParArg is the intrinsic parameter of the point on the argument curv. PntSol is the tangency point on the solution curv. PntArg is the tangency point on the argument curv. It raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2dTanOnRadGeo.def("CenterOn3", [](Geom2dGcc_Circ2dTanOnRadGeo &self, const Standard_Integer Index, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.CenterOn3(Index, ParArg, PntSol); return ParArg; }, "Returns informations about the center (on the curv) of the result. ParArg is the intrinsic parameter of the point on the argument curv. PntSol is the center point of the solution curv. It raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Circ2dTanOnRadGeo.def("IsTheSame1", (Standard_Boolean (Geom2dGcc_Circ2dTanOnRadGeo::*)(const Standard_Integer) const) &Geom2dGcc_Circ2dTanOnRadGeo::IsTheSame1, "Returns True if the solution number Index is equal to the first argument and False in the other cases. It raises NotDone if the construction algorithm didn't succeed. It raises OutOfRange if Index is greater than the number of solutions.", py::arg("Index"));

// CLASS: GEOM2DGCC_CURVETOOL
py::class_<Geom2dGcc_CurveTool> cls_Geom2dGcc_CurveTool(mod, "Geom2dGcc_CurveTool", "None");

// Methods
// cls_Geom2dGcc_CurveTool.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_CurveTool::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_CurveTool.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_CurveTool::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_CurveTool.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_CurveTool::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_CurveTool.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_CurveTool::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_CurveTool.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_CurveTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_CurveTool.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_CurveTool::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_CurveTool.def_static("FirstParameter_", (Standard_Real (*)(const Geom2dAdaptor_Curve &)) &Geom2dGcc_CurveTool::FirstParameter, "None", py::arg("C"));
cls_Geom2dGcc_CurveTool.def_static("LastParameter_", (Standard_Real (*)(const Geom2dAdaptor_Curve &)) &Geom2dGcc_CurveTool::LastParameter, "None", py::arg("C"));
cls_Geom2dGcc_CurveTool.def_static("EpsX_", (Standard_Real (*)(const Geom2dAdaptor_Curve &, const Standard_Real)) &Geom2dGcc_CurveTool::EpsX, "None", py::arg("C"), py::arg("Tol"));
cls_Geom2dGcc_CurveTool.def_static("NbSamples_", (Standard_Integer (*)(const Geom2dAdaptor_Curve &)) &Geom2dGcc_CurveTool::NbSamples, "None", py::arg("C"));
cls_Geom2dGcc_CurveTool.def_static("Value_", (gp_Pnt2d (*)(const Geom2dAdaptor_Curve &, const Standard_Real)) &Geom2dGcc_CurveTool::Value, "None", py::arg("C"), py::arg("X"));
cls_Geom2dGcc_CurveTool.def_static("D1_", (void (*)(const Geom2dAdaptor_Curve &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &)) &Geom2dGcc_CurveTool::D1, "None", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("T"));
cls_Geom2dGcc_CurveTool.def_static("D2_", (void (*)(const Geom2dAdaptor_Curve &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &)) &Geom2dGcc_CurveTool::D2, "None", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("T"), py::arg("N"));
cls_Geom2dGcc_CurveTool.def_static("D3_", (void (*)(const Geom2dAdaptor_Curve &, const Standard_Real, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &)) &Geom2dGcc_CurveTool::D3, "None", py::arg("C"), py::arg("U"), py::arg("P"), py::arg("T"), py::arg("N"), py::arg("dN"));

// CLASS: GEOM2DGCC_FUNCTIONTANCIRCU
py::class_<Geom2dGcc_FunctionTanCirCu, math_FunctionWithDerivative> cls_Geom2dGcc_FunctionTanCirCu(mod, "Geom2dGcc_FunctionTanCirCu", "This abstract class describes a Function of 1 Variable used to find a line tangent to a curve and a circle.");

// Constructors
cls_Geom2dGcc_FunctionTanCirCu.def(py::init<const gp_Circ2d &, const Geom2dAdaptor_Curve &>(), py::arg("Circ"), py::arg("Curv"));

// Methods
// cls_Geom2dGcc_FunctionTanCirCu.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_FunctionTanCirCu::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_FunctionTanCirCu.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_FunctionTanCirCu::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_FunctionTanCirCu.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_FunctionTanCirCu::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_FunctionTanCirCu.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_FunctionTanCirCu::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_FunctionTanCirCu.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_FunctionTanCirCu::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_FunctionTanCirCu.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_FunctionTanCirCu::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_FunctionTanCirCu.def("Value", [](Geom2dGcc_FunctionTanCirCu &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Computes the value of the function F for the variable X. It returns True if the computation is successfully done, False otherwise.", py::arg("X"), py::arg("F"));
cls_Geom2dGcc_FunctionTanCirCu.def("Derivative", [](Geom2dGcc_FunctionTanCirCu &self, const Standard_Real X, Standard_Real & Deriv){ Standard_Boolean rv = self.Derivative(X, Deriv); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Deriv); }, "Computes the derivative of the function F for the variable X. It returns True if the computation is successfully done, False otherwise.", py::arg("X"), py::arg("Deriv"));
cls_Geom2dGcc_FunctionTanCirCu.def("Values", [](Geom2dGcc_FunctionTanCirCu &self, const Standard_Real X, Standard_Real & F, Standard_Real & Deriv){ Standard_Boolean rv = self.Values(X, F, Deriv); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, Deriv); }, "Computes the value and the derivative of the function F for the variable X. It returns True if the computation is successfully done, False otherwise.", py::arg("X"), py::arg("F"), py::arg("Deriv"));

// CLASS: GEOM2DGCC_FUNCTIONTANCUCU
py::class_<Geom2dGcc_FunctionTanCuCu, math_FunctionSetWithDerivatives> cls_Geom2dGcc_FunctionTanCuCu(mod, "Geom2dGcc_FunctionTanCuCu", "This abstract class describes a Function of 1 Variable used to find a line tangent to two curves.");

// Constructors
cls_Geom2dGcc_FunctionTanCuCu.def(py::init<const Geom2dAdaptor_Curve &, const Geom2dAdaptor_Curve &>(), py::arg("Curv1"), py::arg("Curv2"));
cls_Geom2dGcc_FunctionTanCuCu.def(py::init<const gp_Circ2d &, const Geom2dAdaptor_Curve &>(), py::arg("Circ1"), py::arg("Curv2"));

// Methods
// cls_Geom2dGcc_FunctionTanCuCu.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_FunctionTanCuCu::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_FunctionTanCuCu.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_FunctionTanCuCu::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_FunctionTanCuCu.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_FunctionTanCuCu::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_FunctionTanCuCu.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_FunctionTanCuCu::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_FunctionTanCuCu.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_FunctionTanCuCu::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_FunctionTanCuCu.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_FunctionTanCuCu::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_FunctionTanCuCu.def("InitDerivative", (void (Geom2dGcc_FunctionTanCuCu::*)(const math_Vector &, gp_Pnt2d &, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &)) &Geom2dGcc_FunctionTanCuCu::InitDerivative, "None", py::arg("X"), py::arg("Point1"), py::arg("Point2"), py::arg("Tan1"), py::arg("Tan2"), py::arg("D21"), py::arg("D22"));
cls_Geom2dGcc_FunctionTanCuCu.def("NbVariables", (Standard_Integer (Geom2dGcc_FunctionTanCuCu::*)() const) &Geom2dGcc_FunctionTanCuCu::NbVariables, "returns the number of variables of the function.");
cls_Geom2dGcc_FunctionTanCuCu.def("NbEquations", (Standard_Integer (Geom2dGcc_FunctionTanCuCu::*)() const) &Geom2dGcc_FunctionTanCuCu::NbEquations, "returns the number of equations of the function.");
cls_Geom2dGcc_FunctionTanCuCu.def("Value", (Standard_Boolean (Geom2dGcc_FunctionTanCuCu::*)(const math_Vector &, math_Vector &)) &Geom2dGcc_FunctionTanCuCu::Value, "Computes the value of the function F for the variable X. It returns True if the computation is successfully done, False otherwise.", py::arg("X"), py::arg("F"));
cls_Geom2dGcc_FunctionTanCuCu.def("Derivatives", (Standard_Boolean (Geom2dGcc_FunctionTanCuCu::*)(const math_Vector &, math_Matrix &)) &Geom2dGcc_FunctionTanCuCu::Derivatives, "Computes the derivative of the function F for the variable X. It returns True if the computation is successfully done, False otherwise.", py::arg("X"), py::arg("Deriv"));
cls_Geom2dGcc_FunctionTanCuCu.def("Values", (Standard_Boolean (Geom2dGcc_FunctionTanCuCu::*)(const math_Vector &, math_Vector &, math_Matrix &)) &Geom2dGcc_FunctionTanCuCu::Values, "Computes the value and the derivative of the function F for the variable X. It returns True if the computation is successfully done, False otherwise.", py::arg("X"), py::arg("F"), py::arg("Deriv"));

// CLASS: GEOM2DGCC_FUNCTIONTANCUCUCU
py::class_<Geom2dGcc_FunctionTanCuCuCu, math_FunctionSetWithDerivatives> cls_Geom2dGcc_FunctionTanCuCuCu(mod, "Geom2dGcc_FunctionTanCuCuCu", "This abstract class describes a set on N Functions of M independant variables.");

// Constructors
cls_Geom2dGcc_FunctionTanCuCuCu.def(py::init<const Geom2dAdaptor_Curve &, const Geom2dAdaptor_Curve &, const Geom2dAdaptor_Curve &>(), py::arg("C1"), py::arg("C2"), py::arg("C3"));
cls_Geom2dGcc_FunctionTanCuCuCu.def(py::init<const gp_Circ2d &, const Geom2dAdaptor_Curve &, const Geom2dAdaptor_Curve &>(), py::arg("C1"), py::arg("C2"), py::arg("C3"));
cls_Geom2dGcc_FunctionTanCuCuCu.def(py::init<const gp_Circ2d &, const gp_Circ2d &, const Geom2dAdaptor_Curve &>(), py::arg("C1"), py::arg("C2"), py::arg("C3"));
cls_Geom2dGcc_FunctionTanCuCuCu.def(py::init<const gp_Circ2d &, const gp_Lin2d &, const Geom2dAdaptor_Curve &>(), py::arg("C1"), py::arg("L2"), py::arg("C3"));
cls_Geom2dGcc_FunctionTanCuCuCu.def(py::init<const gp_Lin2d &, const gp_Lin2d &, const Geom2dAdaptor_Curve &>(), py::arg("L1"), py::arg("L2"), py::arg("C3"));
cls_Geom2dGcc_FunctionTanCuCuCu.def(py::init<const gp_Lin2d &, const Geom2dAdaptor_Curve &, const Geom2dAdaptor_Curve &>(), py::arg("L1"), py::arg("C2"), py::arg("C3"));
// cls_Geom2dGcc_FunctionTanCuCuCu.def(py::init<const gp_Circ2d &, const Geom2dAdaptor_Curve &, const gp_Pnt2d &>(), py::arg("C1"), py::arg("C2"), py::arg("P3"));
// cls_Geom2dGcc_FunctionTanCuCuCu.def(py::init<const gp_Lin2d &, const Geom2dAdaptor_Curve &, const gp_Pnt2d &>(), py::arg("L1"), py::arg("C2"), py::arg("P3"));
// cls_Geom2dGcc_FunctionTanCuCuCu.def(py::init<const Geom2dAdaptor_Curve &, const gp_Pnt2d &, const gp_Pnt2d &>(), py::arg("C1"), py::arg("P2"), py::arg("P3"));

// Methods
// cls_Geom2dGcc_FunctionTanCuCuCu.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_FunctionTanCuCuCu::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_FunctionTanCuCuCu.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_FunctionTanCuCuCu::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_FunctionTanCuCuCu.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_FunctionTanCuCuCu::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_FunctionTanCuCuCu.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_FunctionTanCuCuCu::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_FunctionTanCuCuCu.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_FunctionTanCuCuCu::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_FunctionTanCuCuCu.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_FunctionTanCuCuCu::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_FunctionTanCuCuCu.def("InitDerivative", (void (Geom2dGcc_FunctionTanCuCuCu::*)(const math_Vector &, gp_Pnt2d &, gp_Pnt2d &, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &)) &Geom2dGcc_FunctionTanCuCuCu::InitDerivative, "None", py::arg("X"), py::arg("Point1"), py::arg("Point2"), py::arg("Point3"), py::arg("Tan1"), py::arg("Tan2"), py::arg("Tan3"), py::arg("D21"), py::arg("D22"), py::arg("D23"));
cls_Geom2dGcc_FunctionTanCuCuCu.def("NbVariables", (Standard_Integer (Geom2dGcc_FunctionTanCuCuCu::*)() const) &Geom2dGcc_FunctionTanCuCuCu::NbVariables, "Returns the number of variables of the function.");
cls_Geom2dGcc_FunctionTanCuCuCu.def("NbEquations", (Standard_Integer (Geom2dGcc_FunctionTanCuCuCu::*)() const) &Geom2dGcc_FunctionTanCuCuCu::NbEquations, "Returns the number of equations of the function.");
cls_Geom2dGcc_FunctionTanCuCuCu.def("Value", (Standard_Boolean (Geom2dGcc_FunctionTanCuCuCu::*)(const math_Vector &, math_Vector &)) &Geom2dGcc_FunctionTanCuCuCu::Value, "Computes the values of the Functions for the variable <X>.", py::arg("X"), py::arg("F"));
cls_Geom2dGcc_FunctionTanCuCuCu.def("Derivatives", (Standard_Boolean (Geom2dGcc_FunctionTanCuCuCu::*)(const math_Vector &, math_Matrix &)) &Geom2dGcc_FunctionTanCuCuCu::Derivatives, "Returns the values of the derivatives for the variable <X>.", py::arg("X"), py::arg("D"));
cls_Geom2dGcc_FunctionTanCuCuCu.def("Values", (Standard_Boolean (Geom2dGcc_FunctionTanCuCuCu::*)(const math_Vector &, math_Vector &, math_Matrix &)) &Geom2dGcc_FunctionTanCuCuCu::Values, "Returns the values of the functions and the derivatives for the variable <X>.", py::arg("X"), py::arg("F"), py::arg("D"));

// CLASS: GEOM2DGCC_FUNCTIONTANCUCUONCU
py::class_<Geom2dGcc_FunctionTanCuCuOnCu, math_FunctionSetWithDerivatives> cls_Geom2dGcc_FunctionTanCuCuOnCu(mod, "Geom2dGcc_FunctionTanCuCuOnCu", "This abstract class describes a set on N Functions of M independant variables.");

// Constructors
cls_Geom2dGcc_FunctionTanCuCuOnCu.def(py::init<const Geom2dAdaptor_Curve &, const Geom2dAdaptor_Curve &, const gp_Circ2d &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("OnCi"), py::arg("Rad"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def(py::init<const gp_Circ2d &, const Geom2dAdaptor_Curve &, const gp_Circ2d &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("OnCi"), py::arg("Rad"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def(py::init<const gp_Lin2d &, const Geom2dAdaptor_Curve &, const gp_Circ2d &, const Standard_Real>(), py::arg("L1"), py::arg("C2"), py::arg("OnCi"), py::arg("Rad"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def(py::init<const Geom2dAdaptor_Curve &, const gp_Pnt2d &, const gp_Circ2d &, const Standard_Real>(), py::arg("C1"), py::arg("P2"), py::arg("OnCi"), py::arg("Rad"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def(py::init<const Geom2dAdaptor_Curve &, const Geom2dAdaptor_Curve &, const gp_Lin2d &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("OnLi"), py::arg("Rad"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def(py::init<const gp_Circ2d &, const Geom2dAdaptor_Curve &, const gp_Lin2d &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("OnLi"), py::arg("Rad"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def(py::init<const gp_Lin2d &, const Geom2dAdaptor_Curve &, const gp_Lin2d &, const Standard_Real>(), py::arg("L1"), py::arg("C2"), py::arg("OnLi"), py::arg("Rad"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def(py::init<const Geom2dAdaptor_Curve &, const gp_Pnt2d &, const gp_Lin2d &, const Standard_Real>(), py::arg("C1"), py::arg("P2"), py::arg("OnLi"), py::arg("Rad"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def(py::init<const Geom2dAdaptor_Curve &, const Geom2dAdaptor_Curve &, const Geom2dAdaptor_Curve &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("OnCu"), py::arg("Rad"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def(py::init<const gp_Circ2d &, const Geom2dAdaptor_Curve &, const Geom2dAdaptor_Curve &, const Standard_Real>(), py::arg("C1"), py::arg("C2"), py::arg("OnCu"), py::arg("Rad"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def(py::init<const gp_Lin2d &, const Geom2dAdaptor_Curve &, const Geom2dAdaptor_Curve &, const Standard_Real>(), py::arg("L1"), py::arg("C2"), py::arg("OnCu"), py::arg("Rad"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def(py::init<const Geom2dAdaptor_Curve &, const gp_Pnt2d &, const Geom2dAdaptor_Curve &, const Standard_Real>(), py::arg("C1"), py::arg("P1"), py::arg("OnCu"), py::arg("Rad"));

// Methods
// cls_Geom2dGcc_FunctionTanCuCuOnCu.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_FunctionTanCuCuOnCu::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_FunctionTanCuCuOnCu.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_FunctionTanCuCuOnCu::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_FunctionTanCuCuOnCu.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_FunctionTanCuCuOnCu::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_FunctionTanCuCuOnCu.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_FunctionTanCuCuOnCu::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_FunctionTanCuCuOnCu.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_FunctionTanCuCuOnCu::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_FunctionTanCuCuOnCu.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_FunctionTanCuCuOnCu::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def("InitDerivative", (void (Geom2dGcc_FunctionTanCuCuOnCu::*)(const math_Vector &, gp_Pnt2d &, gp_Pnt2d &, gp_Pnt2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &, gp_Vec2d &)) &Geom2dGcc_FunctionTanCuCuOnCu::InitDerivative, "None", py::arg("X"), py::arg("Point1"), py::arg("Point2"), py::arg("Point3"), py::arg("Tan1"), py::arg("Tan2"), py::arg("Tan3"), py::arg("D21"), py::arg("D22"), py::arg("D23"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def("NbVariables", (Standard_Integer (Geom2dGcc_FunctionTanCuCuOnCu::*)() const) &Geom2dGcc_FunctionTanCuCuOnCu::NbVariables, "Returns the number of variables of the function.");
cls_Geom2dGcc_FunctionTanCuCuOnCu.def("NbEquations", (Standard_Integer (Geom2dGcc_FunctionTanCuCuOnCu::*)() const) &Geom2dGcc_FunctionTanCuCuOnCu::NbEquations, "Returns the number of equations of the function.");
cls_Geom2dGcc_FunctionTanCuCuOnCu.def("Value", (Standard_Boolean (Geom2dGcc_FunctionTanCuCuOnCu::*)(const math_Vector &, math_Vector &)) &Geom2dGcc_FunctionTanCuCuOnCu::Value, "Computes the values of the Functions for the variable <X>.", py::arg("X"), py::arg("F"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def("Derivatives", (Standard_Boolean (Geom2dGcc_FunctionTanCuCuOnCu::*)(const math_Vector &, math_Matrix &)) &Geom2dGcc_FunctionTanCuCuOnCu::Derivatives, "Returns the values of the derivatives for the variable <X>.", py::arg("X"), py::arg("D"));
cls_Geom2dGcc_FunctionTanCuCuOnCu.def("Values", (Standard_Boolean (Geom2dGcc_FunctionTanCuCuOnCu::*)(const math_Vector &, math_Vector &, math_Matrix &)) &Geom2dGcc_FunctionTanCuCuOnCu::Values, "Returns the values of the functions and the derivatives for the variable <X>.", py::arg("X"), py::arg("F"), py::arg("D"));

// CLASS: GEOM2DGCC_FUNCTIONTANCUPNT
py::class_<Geom2dGcc_FunctionTanCuPnt, math_FunctionWithDerivative> cls_Geom2dGcc_FunctionTanCuPnt(mod, "Geom2dGcc_FunctionTanCuPnt", "This abstract class describes a Function of 1 Variable used to find a line tangent to a curve and passing through a point.");

// Constructors
cls_Geom2dGcc_FunctionTanCuPnt.def(py::init<const Geom2dAdaptor_Curve &, const gp_Pnt2d &>(), py::arg("C"), py::arg("Point"));

// Methods
// cls_Geom2dGcc_FunctionTanCuPnt.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_FunctionTanCuPnt::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_FunctionTanCuPnt.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_FunctionTanCuPnt::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_FunctionTanCuPnt.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_FunctionTanCuPnt::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_FunctionTanCuPnt.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_FunctionTanCuPnt::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_FunctionTanCuPnt.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_FunctionTanCuPnt::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_FunctionTanCuPnt.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_FunctionTanCuPnt::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_FunctionTanCuPnt.def("Value", [](Geom2dGcc_FunctionTanCuPnt &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Computes the value of the function F for the variable X. It returns True if the computation is successfully done, False otherwise.", py::arg("X"), py::arg("F"));
cls_Geom2dGcc_FunctionTanCuPnt.def("Derivative", [](Geom2dGcc_FunctionTanCuPnt &self, const Standard_Real X, Standard_Real & Deriv){ Standard_Boolean rv = self.Derivative(X, Deriv); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Deriv); }, "Computes the derivative of the function F for the variable X. It returns True if the computation is successfully done, False otherwise.", py::arg("X"), py::arg("Deriv"));
cls_Geom2dGcc_FunctionTanCuPnt.def("Values", [](Geom2dGcc_FunctionTanCuPnt &self, const Standard_Real X, Standard_Real & F, Standard_Real & Deriv){ Standard_Boolean rv = self.Values(X, F, Deriv); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, Deriv); }, "Computes the value and the derivative of the function F for the variable X. It returns True if the computation is successfully done, False otherwise.", py::arg("X"), py::arg("F"), py::arg("Deriv"));

// CLASS: GEOM2DGCC_FUNCTIONTANOBL
py::class_<Geom2dGcc_FunctionTanObl, math_FunctionWithDerivative> cls_Geom2dGcc_FunctionTanObl(mod, "Geom2dGcc_FunctionTanObl", "This class describe a function of a single variable.");

// Constructors
cls_Geom2dGcc_FunctionTanObl.def(py::init<const Geom2dAdaptor_Curve &, const gp_Dir2d &>(), py::arg("Curve"), py::arg("Dir"));

// Methods
// cls_Geom2dGcc_FunctionTanObl.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_FunctionTanObl::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_FunctionTanObl.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_FunctionTanObl::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_FunctionTanObl.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_FunctionTanObl::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_FunctionTanObl.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_FunctionTanObl::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_FunctionTanObl.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_FunctionTanObl::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_FunctionTanObl.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_FunctionTanObl::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_FunctionTanObl.def("Value", [](Geom2dGcc_FunctionTanObl &self, const Standard_Real X, Standard_Real & F){ Standard_Boolean rv = self.Value(X, F); return std::tuple<Standard_Boolean, Standard_Real &>(rv, F); }, "Computes the value of the function F for the variable X. It returns True if the computation is successfully done, False otherwise.", py::arg("X"), py::arg("F"));
cls_Geom2dGcc_FunctionTanObl.def("Derivative", [](Geom2dGcc_FunctionTanObl &self, const Standard_Real X, Standard_Real & Deriv){ Standard_Boolean rv = self.Derivative(X, Deriv); return std::tuple<Standard_Boolean, Standard_Real &>(rv, Deriv); }, "Computes the derivative of the function F for the variable X. It returns True if the computation is successfully done, False otherwise.", py::arg("X"), py::arg("Deriv"));
cls_Geom2dGcc_FunctionTanObl.def("Values", [](Geom2dGcc_FunctionTanObl &self, const Standard_Real X, Standard_Real & F, Standard_Real & Deriv){ Standard_Boolean rv = self.Values(X, F, Deriv); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, F, Deriv); }, "Computes the value and the derivative of the function F for the variable X. It returns True if the computation is successfully done, False otherwise.", py::arg("X"), py::arg("F"), py::arg("Deriv"));

// CLASS: GEOM2DGCC_ISPARALLEL
py::class_<Geom2dGcc_IsParallel, opencascade::handle<Geom2dGcc_IsParallel>, Standard_DomainError> cls_Geom2dGcc_IsParallel(mod, "Geom2dGcc_IsParallel", "None");

// Constructors
cls_Geom2dGcc_IsParallel.def(py::init<>());
cls_Geom2dGcc_IsParallel.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_Geom2dGcc_IsParallel.def_static("Raise_", (void (*)(const Standard_CString)) &Geom2dGcc_IsParallel::Raise, "None", py::arg("theMessage"));
cls_Geom2dGcc_IsParallel.def_static("Raise_", (void (*)(Standard_SStream &)) &Geom2dGcc_IsParallel::Raise, "None", py::arg("theMessage"));
cls_Geom2dGcc_IsParallel.def_static("NewInstance_", (opencascade::handle<Geom2dGcc_IsParallel> (*)(const Standard_CString)) &Geom2dGcc_IsParallel::NewInstance, "None", py::arg("theMessage"));
cls_Geom2dGcc_IsParallel.def_static("get_type_name_", (const char * (*)()) &Geom2dGcc_IsParallel::get_type_name, "None");
cls_Geom2dGcc_IsParallel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Geom2dGcc_IsParallel::get_type_descriptor, "None");
cls_Geom2dGcc_IsParallel.def("DynamicType", (const opencascade::handle<Standard_Type> & (Geom2dGcc_IsParallel::*)() const) &Geom2dGcc_IsParallel::DynamicType, "None");

// CLASS: GEOM2DGCC_LIN2D2TAN
py::class_<Geom2dGcc_Lin2d2Tan> cls_Geom2dGcc_Lin2d2Tan(mod, "Geom2dGcc_Lin2d2Tan", "This class implements the algorithms used to create 2d lines tangent to 2 other elements which can be circles, curves or points. More than one argument must be a curve. Describes functions for building a 2D line: - tangential to 2 curves, or - tangential to a curve and passing through a point. A Lin2d2Tan object provides a framework for: - defining the construction of 2D line(s), - implementing the construction algorithm, and - consulting the result(s).");

// Constructors
cls_Geom2dGcc_Lin2d2Tan.def(py::init<const Geom2dGcc_QualifiedCurve &, const Geom2dGcc_QualifiedCurve &, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Tolang"));
cls_Geom2dGcc_Lin2d2Tan.def(py::init<const Geom2dGcc_QualifiedCurve &, const gp_Pnt2d &, const Standard_Real>(), py::arg("Qualified1"), py::arg("ThePoint"), py::arg("Tolang"));
cls_Geom2dGcc_Lin2d2Tan.def(py::init<const Geom2dGcc_QualifiedCurve &, const Geom2dGcc_QualifiedCurve &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Tolang"), py::arg("Param1"), py::arg("Param2"));
cls_Geom2dGcc_Lin2d2Tan.def(py::init<const Geom2dGcc_QualifiedCurve &, const gp_Pnt2d &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("ThePoint"), py::arg("Tolang"), py::arg("Param1"));

// Methods
// cls_Geom2dGcc_Lin2d2Tan.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Lin2d2Tan::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Lin2d2Tan.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Lin2d2Tan::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Lin2d2Tan.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Lin2d2Tan::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Lin2d2Tan.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Lin2d2Tan::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Lin2d2Tan.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Lin2d2Tan::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Lin2d2Tan.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Lin2d2Tan::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Lin2d2Tan.def("IsDone", (Standard_Boolean (Geom2dGcc_Lin2d2Tan::*)() const) &Geom2dGcc_Lin2d2Tan::IsDone, "Returns true if the construction algorithm does not fail (even if it finds no solution). Note: IsDone protects against a failure arising from a more internal intersection algorithm, which has reached its numeric limits.");
cls_Geom2dGcc_Lin2d2Tan.def("NbSolutions", (Standard_Integer (Geom2dGcc_Lin2d2Tan::*)() const) &Geom2dGcc_Lin2d2Tan::NbSolutions, "Returns the number of lines, representing solutions computed by this algorithm. Exceptions StdFail_NotDone if the construction fails.R");
cls_Geom2dGcc_Lin2d2Tan.def("ThisSolution", (gp_Lin2d (Geom2dGcc_Lin2d2Tan::*)(const Standard_Integer) const) &Geom2dGcc_Lin2d2Tan::ThisSolution, "Returns a line, representing the solution of index Index computed by this algorithm. Warning This indexing simply provides a means of consulting the solutions. The index values are not associated with these solutions outside the context of the algorithm object. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"));
cls_Geom2dGcc_Lin2d2Tan.def("WhichQualifier", (void (Geom2dGcc_Lin2d2Tan::*)(const Standard_Integer, GccEnt_Position &, GccEnt_Position &) const) &Geom2dGcc_Lin2d2Tan::WhichQualifier, "Returns the qualifiers Qualif1 and Qualif2 of the tangency arguments for the solution of index Index computed by this algorithm. The returned qualifiers are: - those specified at the start of construction when the solutions are defined as enclosing or outside with respect to the arguments, or - those computed during construction (i.e. enclosing or outside) when the solutions are defined as unqualified with respect to the arguments, or - GccEnt_noqualifier if the tangency argument is a point. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("Qualif1"), py::arg("Qualif2"));
cls_Geom2dGcc_Lin2d2Tan.def("Tangency1", [](Geom2dGcc_Lin2d2Tan &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Lin2d2Tan.def("Tangency2", [](Geom2dGcc_Lin2d2Tan &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency2(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));

// CLASS: GEOM2DGCC_LIN2D2TANITER
py::class_<Geom2dGcc_Lin2d2TanIter> cls_Geom2dGcc_Lin2d2TanIter(mod, "Geom2dGcc_Lin2d2TanIter", "This class implements the algorithms used to create 2d lines tangent to 2 other elements which can be circles, curves or points. More than one argument must be a curve.");

// Constructors
cls_Geom2dGcc_Lin2d2TanIter.def(py::init<const Geom2dGcc_QCurve &, const gp_Pnt2d &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("ThePoint"), py::arg("Param1"), py::arg("Tolang"));
cls_Geom2dGcc_Lin2d2TanIter.def(py::init<const GccEnt_QualifiedCirc &, const Geom2dGcc_QCurve &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Param2"), py::arg("Tolang"));
cls_Geom2dGcc_Lin2d2TanIter.def(py::init<const Geom2dGcc_QCurve &, const Geom2dGcc_QCurve &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("Qualified2"), py::arg("Param1"), py::arg("Param2"), py::arg("Tolang"));

// Methods
// cls_Geom2dGcc_Lin2d2TanIter.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Lin2d2TanIter::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Lin2d2TanIter.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Lin2d2TanIter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Lin2d2TanIter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Lin2d2TanIter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Lin2d2TanIter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Lin2d2TanIter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Lin2d2TanIter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Lin2d2TanIter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Lin2d2TanIter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Lin2d2TanIter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Lin2d2TanIter.def("IsDone", (Standard_Boolean (Geom2dGcc_Lin2d2TanIter::*)() const) &Geom2dGcc_Lin2d2TanIter::IsDone, "This methode returns true when there is a solution and false in the other cases.");
cls_Geom2dGcc_Lin2d2TanIter.def("ThisSolution", (gp_Lin2d (Geom2dGcc_Lin2d2TanIter::*)() const) &Geom2dGcc_Lin2d2TanIter::ThisSolution, "Returns the solution.");
cls_Geom2dGcc_Lin2d2TanIter.def("WhichQualifier", (void (Geom2dGcc_Lin2d2TanIter::*)(GccEnt_Position &, GccEnt_Position &) const) &Geom2dGcc_Lin2d2TanIter::WhichQualifier, "None", py::arg("Qualif1"), py::arg("Qualif2"));
cls_Geom2dGcc_Lin2d2TanIter.def("Tangency1", [](Geom2dGcc_Lin2d2TanIter &self, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv.", py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Lin2d2TanIter.def("Tangency2", [](Geom2dGcc_Lin2d2TanIter &self, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency2(ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "None", py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));

// CLASS: GEOM2DGCC_LIN2DTANOBL
py::class_<Geom2dGcc_Lin2dTanObl> cls_Geom2dGcc_Lin2dTanObl(mod, "Geom2dGcc_Lin2dTanObl", "This class implements the algorithms used to create 2d line tangent to a curve QualifiedCurv and doing an angle Angle with a line TheLin. The angle must be in Radian. Describes functions for building a 2D line making a given angle with a line and tangential to a curve. A Lin2dTanObl object provides a framework for: - defining the construction of 2D line(s), - implementing the construction algorithm, and - consulting the result(s).");

// Constructors
cls_Geom2dGcc_Lin2dTanObl.def(py::init<const Geom2dGcc_QualifiedCurve &, const gp_Lin2d &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("TheLin"), py::arg("TolAng"), py::arg("Angle"));
cls_Geom2dGcc_Lin2dTanObl.def(py::init<const Geom2dGcc_QualifiedCurve &, const gp_Lin2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("TheLin"), py::arg("TolAng"), py::arg("Param1"), py::arg("Angle"));

// Methods
// cls_Geom2dGcc_Lin2dTanObl.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Lin2dTanObl::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Lin2dTanObl.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Lin2dTanObl::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Lin2dTanObl.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Lin2dTanObl::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Lin2dTanObl.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Lin2dTanObl::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Lin2dTanObl.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Lin2dTanObl::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Lin2dTanObl.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Lin2dTanObl::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Lin2dTanObl.def("IsDone", (Standard_Boolean (Geom2dGcc_Lin2dTanObl::*)() const) &Geom2dGcc_Lin2dTanObl::IsDone, "Returns true if the construction algorithm does not fail (even if it finds no solution). Note: IsDone protects against a failure arising from a more internal intersection algorithm, which has reached its numeric limits.");
cls_Geom2dGcc_Lin2dTanObl.def("NbSolutions", (Standard_Integer (Geom2dGcc_Lin2dTanObl::*)() const) &Geom2dGcc_Lin2dTanObl::NbSolutions, "Returns the number of lines, representing solutions computed by this algorithm. Exceptions StdFail_NotDone if the construction fails.");
cls_Geom2dGcc_Lin2dTanObl.def("ThisSolution", (gp_Lin2d (Geom2dGcc_Lin2dTanObl::*)(const Standard_Integer) const) &Geom2dGcc_Lin2dTanObl::ThisSolution, "Returns a line, representing the solution of index Index computed by this algorithm. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"));
cls_Geom2dGcc_Lin2dTanObl.def("WhichQualifier", (void (Geom2dGcc_Lin2dTanObl::*)(const Standard_Integer, GccEnt_Position &) const) &Geom2dGcc_Lin2dTanObl::WhichQualifier, "Returns the qualifier Qualif1 of the tangency argument for the solution of index Index computed by this algorithm. The returned qualifier is: - that specified at the start of construction when the solutions are defined as enclosing or outside with respect to the argument, or - that computed during construction (i.e. enclosing or outside) when the solutions are defined as unqualified with respect to the argument, or - GccEnt_noqualifier if the tangency argument is a point. Exceptions Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm. StdFail_NotDone if the construction fails.", py::arg("Index"), py::arg("Qualif1"));
cls_Geom2dGcc_Lin2dTanObl.def("Tangency1", [](Geom2dGcc_Lin2dTanObl &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns informations about the tangency point between the result and the first argument. ParSol is the intrinsic parameter of the point PntSol on the solution curv. ParArg is the intrinsic parameter of the point PntSol on the argument curv.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Lin2dTanObl.def("Intersection2", [](Geom2dGcc_Lin2dTanObl &self, const Standard_Integer Index, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Intersection2(Index, ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "Returns the point of intersection PntSol between the solution of index Index and the second argument (the line) of this algorithm. ParSol is the parameter of the point PntSol on the solution. ParArg is the parameter of the point PntSol on the second argument (the line). Exceptions StdFail_NotDone if the construction fails. Geom2dGcc_IsParallel if the solution and the second argument (the line) are parallel. Standard_OutOfRange if Index is less than zero or greater than the number of solutions computed by this algorithm.", py::arg("Index"), py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
// cls_Geom2dGcc_Lin2dTanObl.def("IsParallel2", (Standard_Boolean (Geom2dGcc_Lin2dTanObl::*)() const) &Geom2dGcc_Lin2dTanObl::IsParallel2, "Returns true if the line and the solution are parallel. This is the case when the angle given at the time of construction is equal to 0 or Pi. Exceptions StdFail_NotDone if the construction fails.");

// CLASS: GEOM2DGCC_LIN2DTANOBLITER
py::class_<Geom2dGcc_Lin2dTanOblIter> cls_Geom2dGcc_Lin2dTanOblIter(mod, "Geom2dGcc_Lin2dTanOblIter", "This class implements the algorithms used to create 2d line tangent to a curve QualifiedCurv and doing an angle Angle with a line TheLin. The angle must be in Radian.");

// Constructors
cls_Geom2dGcc_Lin2dTanOblIter.def(py::init<const Geom2dGcc_QCurve &, const gp_Lin2d &, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("TheLin"), py::arg("Param1"), py::arg("TolAng"));
cls_Geom2dGcc_Lin2dTanOblIter.def(py::init<const Geom2dGcc_QCurve &, const gp_Lin2d &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Qualified1"), py::arg("TheLin"), py::arg("Param1"), py::arg("TolAng"), py::arg("Angle"));

// Methods
// cls_Geom2dGcc_Lin2dTanOblIter.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_Lin2dTanOblIter::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_Lin2dTanOblIter.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_Lin2dTanOblIter::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_Lin2dTanOblIter.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_Lin2dTanOblIter::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_Lin2dTanOblIter.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_Lin2dTanOblIter::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_Lin2dTanOblIter.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_Lin2dTanOblIter::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_Lin2dTanOblIter.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_Lin2dTanOblIter::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_Lin2dTanOblIter.def("IsDone", (Standard_Boolean (Geom2dGcc_Lin2dTanOblIter::*)() const) &Geom2dGcc_Lin2dTanOblIter::IsDone, "This method returns true when there is a solution and false in the other cases.");
cls_Geom2dGcc_Lin2dTanOblIter.def("ThisSolution", (gp_Lin2d (Geom2dGcc_Lin2dTanOblIter::*)() const) &Geom2dGcc_Lin2dTanOblIter::ThisSolution, "None");
cls_Geom2dGcc_Lin2dTanOblIter.def("WhichQualifier", (void (Geom2dGcc_Lin2dTanOblIter::*)(GccEnt_Position &) const) &Geom2dGcc_Lin2dTanOblIter::WhichQualifier, "None", py::arg("Qualif1"));
cls_Geom2dGcc_Lin2dTanOblIter.def("Tangency1", [](Geom2dGcc_Lin2dTanOblIter &self, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Tangency1(ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "None", py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Lin2dTanOblIter.def("Intersection2", [](Geom2dGcc_Lin2dTanOblIter &self, Standard_Real & ParSol, Standard_Real & ParArg, gp_Pnt2d & PntSol){ self.Intersection2(ParSol, ParArg, PntSol); return std::tuple<Standard_Real &, Standard_Real &>(ParSol, ParArg); }, "None", py::arg("ParSol"), py::arg("ParArg"), py::arg("PntSol"));
cls_Geom2dGcc_Lin2dTanOblIter.def("IsParallel2", (Standard_Boolean (Geom2dGcc_Lin2dTanOblIter::*)() const) &Geom2dGcc_Lin2dTanOblIter::IsParallel2, "None");

// CLASS: GEOM2DGCC_QCURVE
py::class_<Geom2dGcc_QCurve> cls_Geom2dGcc_QCurve(mod, "Geom2dGcc_QCurve", "Creates a qualified 2d line.");

// Constructors
cls_Geom2dGcc_QCurve.def(py::init<const Geom2dAdaptor_Curve &, const GccEnt_Position>(), py::arg("Curve"), py::arg("Qualifier"));

// Methods
// cls_Geom2dGcc_QCurve.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_QCurve::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_QCurve.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_QCurve::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_QCurve.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_QCurve::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_QCurve.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_QCurve::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_QCurve.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_QCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_QCurve.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_QCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_QCurve.def("Qualified", (Geom2dAdaptor_Curve (Geom2dGcc_QCurve::*)() const) &Geom2dGcc_QCurve::Qualified, "None");
cls_Geom2dGcc_QCurve.def("Qualifier", (GccEnt_Position (Geom2dGcc_QCurve::*)() const) &Geom2dGcc_QCurve::Qualifier, "None");
cls_Geom2dGcc_QCurve.def("IsUnqualified", (Standard_Boolean (Geom2dGcc_QCurve::*)() const) &Geom2dGcc_QCurve::IsUnqualified, "Returns true if the solution is unqualified and false in the other cases.");
cls_Geom2dGcc_QCurve.def("IsEnclosing", (Standard_Boolean (Geom2dGcc_QCurve::*)() const) &Geom2dGcc_QCurve::IsEnclosing, "Returns true if the solution is Enclosing the Curv and false in the other cases.");
cls_Geom2dGcc_QCurve.def("IsEnclosed", (Standard_Boolean (Geom2dGcc_QCurve::*)() const) &Geom2dGcc_QCurve::IsEnclosed, "Returns true if the solution is Enclosed in the Curv and false in the other cases.");
cls_Geom2dGcc_QCurve.def("IsOutside", (Standard_Boolean (Geom2dGcc_QCurve::*)() const) &Geom2dGcc_QCurve::IsOutside, "Returns true if the solution is Outside the Curv and false in the other cases.");

// CLASS: GEOM2DGCC_QUALIFIEDCURVE
py::class_<Geom2dGcc_QualifiedCurve> cls_Geom2dGcc_QualifiedCurve(mod, "Geom2dGcc_QualifiedCurve", "Describes functions for building a qualified 2D curve. A qualified 2D curve is a curve with a qualifier which specifies whether the solution of a construction algorithm using the qualified curve (as an argument): - encloses the curve, or - is enclosed by the curve, or - is built so that both the curve and it are external to one another, or - is undefined (all solutions apply).");

// Constructors
cls_Geom2dGcc_QualifiedCurve.def(py::init<const Geom2dAdaptor_Curve &, const GccEnt_Position>(), py::arg("Curve"), py::arg("Qualifier"));

// Methods
// cls_Geom2dGcc_QualifiedCurve.def_static("operator new_", (void * (*)(size_t)) &Geom2dGcc_QualifiedCurve::operator new, "None", py::arg("theSize"));
// cls_Geom2dGcc_QualifiedCurve.def_static("operator delete_", (void (*)(void *)) &Geom2dGcc_QualifiedCurve::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dGcc_QualifiedCurve.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dGcc_QualifiedCurve::operator new[], "None", py::arg("theSize"));
// cls_Geom2dGcc_QualifiedCurve.def_static("operator delete[]_", (void (*)(void *)) &Geom2dGcc_QualifiedCurve::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dGcc_QualifiedCurve.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dGcc_QualifiedCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dGcc_QualifiedCurve.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dGcc_QualifiedCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dGcc_QualifiedCurve.def("Qualified", (Geom2dAdaptor_Curve (Geom2dGcc_QualifiedCurve::*)() const) &Geom2dGcc_QualifiedCurve::Qualified, "Returns a 2D curve to which the qualifier is assigned. Warning The returned curve is an adapted curve, i.e. an object which is an interface between: - the services provided by a 2D curve from the package Geom2d, - and those required on the curve by a computation algorithm. The Geom2d curve on which the adapted curve is based can be obtained in the following way: myQualifiedCurve = ... ; Geom2dAdaptor_Curve myAdaptedCurve = myQualifiedCurve.Qualified(); Handle(Geom2d_Curve) = myAdaptedCurve.Curve();");
cls_Geom2dGcc_QualifiedCurve.def("Qualifier", (GccEnt_Position (Geom2dGcc_QualifiedCurve::*)() const) &Geom2dGcc_QualifiedCurve::Qualifier, "Returns - the qualifier of this qualified curve if it is enclosing, enclosed or outside, or - GccEnt_noqualifier if it is unqualified.");
cls_Geom2dGcc_QualifiedCurve.def("IsUnqualified", (Standard_Boolean (Geom2dGcc_QualifiedCurve::*)() const) &Geom2dGcc_QualifiedCurve::IsUnqualified, "Returns true if the solution is unqualified and false in the other cases.");
cls_Geom2dGcc_QualifiedCurve.def("IsEnclosing", (Standard_Boolean (Geom2dGcc_QualifiedCurve::*)() const) &Geom2dGcc_QualifiedCurve::IsEnclosing, "It returns true if the solution is Enclosing the Curv and false in the other cases.");
cls_Geom2dGcc_QualifiedCurve.def("IsEnclosed", (Standard_Boolean (Geom2dGcc_QualifiedCurve::*)() const) &Geom2dGcc_QualifiedCurve::IsEnclosed, "It returns true if the solution is Enclosed in the Curv and false in the other cases.");
cls_Geom2dGcc_QualifiedCurve.def("IsOutside", (Standard_Boolean (Geom2dGcc_QualifiedCurve::*)() const) &Geom2dGcc_QualifiedCurve::IsOutside, "It returns true if the solution is Outside the Curv and false in the other cases.");


}
