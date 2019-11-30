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
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Matrix.hxx>
#include <TColgp_Array2OfPnt.hxx>
#include <GeomAbs_Shape.hxx>
#include <PLib_Base.hxx>
#include <PLib_JacobiPolynomial.hxx>
#include <PLib_HermitJacobi.hxx>
#include <PLib_DoubleJacobiPolynomial.hxx>
#include <PLib.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Std.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <TColStd_HArray1OfReal.hxx>

PYBIND11_MODULE(PLib, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.math");
py::module::import("OCCT.GeomAbs");

// CLASS: PLIB
py::class_<PLib> cls_PLib(mod, "PLib", "PLib means Polynomial functions library. This pk provides basic computation functions for polynomial functions. Note: weight arrays can be passed by pointer for some functions so that NULL pointer is valid. That means no weights passed.");

// Methods
// cls_PLib.def_static("operator new_", (void * (*)(size_t)) &PLib::operator new, "None", py::arg("theSize"));
// cls_PLib.def_static("operator delete_", (void (*)(void *)) &PLib::operator delete, "None", py::arg("theAddress"));
// cls_PLib.def_static("operator new[]_", (void * (*)(size_t)) &PLib::operator new[], "None", py::arg("theSize"));
// cls_PLib.def_static("operator delete[]_", (void (*)(void *)) &PLib::operator delete[], "None", py::arg("theAddress"));
// cls_PLib.def_static("operator new_", (void * (*)(size_t, void *)) &PLib::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_PLib.def_static("operator delete_", (void (*)(void *, void *)) &PLib::operator delete, "None", py::arg(""), py::arg(""));
cls_PLib.def_static("NoWeights_", (TColStd_Array1OfReal * (*)()) &PLib::NoWeights, "Used as argument for a non rational functions");
cls_PLib.def_static("NoWeights2_", (TColStd_Array2OfReal * (*)()) &PLib::NoWeights2, "Used as argument for a non rational functions");
cls_PLib.def_static("SetPoles_", (void (*)(const TColgp_Array1OfPnt &, TColStd_Array1OfReal &)) &PLib::SetPoles, "Copy in FP the coordinates of the poles.", py::arg("Poles"), py::arg("FP"));
cls_PLib.def_static("SetPoles_", (void (*)(const TColgp_Array1OfPnt &, const TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &PLib::SetPoles, "Copy in FP the coordinates of the poles.", py::arg("Poles"), py::arg("Weights"), py::arg("FP"));
cls_PLib.def_static("GetPoles_", (void (*)(const TColStd_Array1OfReal &, TColgp_Array1OfPnt &)) &PLib::GetPoles, "Get from FP the coordinates of the poles.", py::arg("FP"), py::arg("Poles"));
cls_PLib.def_static("GetPoles_", (void (*)(const TColStd_Array1OfReal &, TColgp_Array1OfPnt &, TColStd_Array1OfReal &)) &PLib::GetPoles, "Get from FP the coordinates of the poles.", py::arg("FP"), py::arg("Poles"), py::arg("Weights"));
cls_PLib.def_static("SetPoles_", (void (*)(const TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &PLib::SetPoles, "Copy in FP the coordinates of the poles.", py::arg("Poles"), py::arg("FP"));
cls_PLib.def_static("SetPoles_", (void (*)(const TColgp_Array1OfPnt2d &, const TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &PLib::SetPoles, "Copy in FP the coordinates of the poles.", py::arg("Poles"), py::arg("Weights"), py::arg("FP"));
cls_PLib.def_static("GetPoles_", (void (*)(const TColStd_Array1OfReal &, TColgp_Array1OfPnt2d &)) &PLib::GetPoles, "Get from FP the coordinates of the poles.", py::arg("FP"), py::arg("Poles"));
cls_PLib.def_static("GetPoles_", (void (*)(const TColStd_Array1OfReal &, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal &)) &PLib::GetPoles, "Get from FP the coordinates of the poles.", py::arg("FP"), py::arg("Poles"), py::arg("Weights"));
cls_PLib.def_static("Bin_", (Standard_Real (*)(const Standard_Integer, const Standard_Integer)) &PLib::Bin, "Returns the Binomial Cnp. N should be <= BSplCLib::MaxDegree().", py::arg("N"), py::arg("P"));
cls_PLib.def_static("RationalDerivative_", [](const Standard_Integer Degree, const Standard_Integer N, const Standard_Integer Dimension, Standard_Real & Ders, Standard_Real & RDers, const Standard_Boolean All){ PLib::RationalDerivative(Degree, N, Dimension, Ders, RDers, All); return std::tuple<Standard_Real &, Standard_Real &>(Ders, RDers); }, "Computes the derivatives of a ratio at order <N> in dimension <Dimension>.", py::arg("Degree"), py::arg("N"), py::arg("Dimension"), py::arg("Ders"), py::arg("RDers"), py::arg("All"));
cls_PLib.def_static("RationalDerivatives_", [](const Standard_Integer DerivativesRequest, const Standard_Integer Dimension, Standard_Real & PolesDerivatives, Standard_Real & WeightsDerivatives, Standard_Real & RationalDerivates){ PLib::RationalDerivatives(DerivativesRequest, Dimension, PolesDerivatives, WeightsDerivatives, RationalDerivates); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(PolesDerivatives, WeightsDerivatives, RationalDerivates); }, "Computes DerivativesRequest derivatives of a ratio at of a BSpline function of degree <Degree> dimension <Dimension>.", py::arg("DerivativesRequest"), py::arg("Dimension"), py::arg("PolesDerivatives"), py::arg("WeightsDerivatives"), py::arg("RationalDerivates"));
cls_PLib.def_static("EvalPolynomial_", [](const Standard_Real U, const Standard_Integer DerivativeOrder, const Standard_Integer Degree, const Standard_Integer Dimension, Standard_Real & PolynomialCoeff, Standard_Real & Results){ PLib::EvalPolynomial(U, DerivativeOrder, Degree, Dimension, PolynomialCoeff, Results); return std::tuple<Standard_Real &, Standard_Real &>(PolynomialCoeff, Results); }, "Performs Horner method with synthethic division for derivatives parameter <U>, with <Degree> and <Dimension>. PolynomialCoeff are stored in the following fashion c0(1) c0(2) .... c0(Dimension) c1(1) c1(2) .... c1(Dimension)", py::arg("U"), py::arg("DerivativeOrder"), py::arg("Degree"), py::arg("Dimension"), py::arg("PolynomialCoeff"), py::arg("Results"));
cls_PLib.def_static("NoDerivativeEvalPolynomial_", [](const Standard_Real U, const Standard_Integer Degree, const Standard_Integer Dimension, const Standard_Integer DegreeDimension, Standard_Real & PolynomialCoeff, Standard_Real & Results){ PLib::NoDerivativeEvalPolynomial(U, Degree, Dimension, DegreeDimension, PolynomialCoeff, Results); return std::tuple<Standard_Real &, Standard_Real &>(PolynomialCoeff, Results); }, "Same as above with DerivativeOrder = 0;", py::arg("U"), py::arg("Degree"), py::arg("Dimension"), py::arg("DegreeDimension"), py::arg("PolynomialCoeff"), py::arg("Results"));
cls_PLib.def_static("EvalPoly2Var_", [](const Standard_Real U, const Standard_Real V, const Standard_Integer UDerivativeOrder, const Standard_Integer VDerivativeOrder, const Standard_Integer UDegree, const Standard_Integer VDegree, const Standard_Integer Dimension, Standard_Real & PolynomialCoeff, Standard_Real & Results){ PLib::EvalPoly2Var(U, V, UDerivativeOrder, VDerivativeOrder, UDegree, VDegree, Dimension, PolynomialCoeff, Results); return std::tuple<Standard_Real &, Standard_Real &>(PolynomialCoeff, Results); }, "Applies EvalPolynomial twice to evaluate the derivative of orders UDerivativeOrder in U, VDerivativeOrder in V at parameters U,V", py::arg("U"), py::arg("V"), py::arg("UDerivativeOrder"), py::arg("VDerivativeOrder"), py::arg("UDegree"), py::arg("VDegree"), py::arg("Dimension"), py::arg("PolynomialCoeff"), py::arg("Results"));
cls_PLib.def_static("EvalLagrange_", [](const Standard_Real U, const Standard_Integer DerivativeOrder, const Standard_Integer Degree, const Standard_Integer Dimension, Standard_Real & ValueArray, Standard_Real & ParameterArray, Standard_Real & Results){ Standard_Integer rv = PLib::EvalLagrange(U, DerivativeOrder, Degree, Dimension, ValueArray, ParameterArray, Results); return std::tuple<Standard_Integer, Standard_Real &, Standard_Real &, Standard_Real &>(rv, ValueArray, ParameterArray, Results); }, "Performs the Lagrange Interpolation of given series of points with given parameters with the requested derivative order Results will store things in the following format with d = DerivativeOrder", py::arg("U"), py::arg("DerivativeOrder"), py::arg("Degree"), py::arg("Dimension"), py::arg("ValueArray"), py::arg("ParameterArray"), py::arg("Results"));
cls_PLib.def_static("EvalCubicHermite_", [](const Standard_Real U, const Standard_Integer DerivativeOrder, const Standard_Integer Dimension, Standard_Real & ValueArray, Standard_Real & DerivativeArray, Standard_Real & ParameterArray, Standard_Real & Results){ Standard_Integer rv = PLib::EvalCubicHermite(U, DerivativeOrder, Dimension, ValueArray, DerivativeArray, ParameterArray, Results); return std::tuple<Standard_Integer, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(rv, ValueArray, DerivativeArray, ParameterArray, Results); }, "Performs the Cubic Hermite Interpolation of given series of points with given parameters with the requested derivative order. ValueArray stores the value at the first and last parameter. It has the following format : [0], [Dimension-1] : value at first param [Dimension], [Dimension + Dimension-1] : value at last param Derivative array stores the value of the derivatives at the first parameter and at the last parameter in the following format [0], [Dimension-1] : derivative at first param [Dimension], [Dimension + Dimension-1] : derivative at last param", py::arg("U"), py::arg("DerivativeOrder"), py::arg("Dimension"), py::arg("ValueArray"), py::arg("DerivativeArray"), py::arg("ParameterArray"), py::arg("Results"));
cls_PLib.def_static("HermiteCoefficients_", (Standard_Boolean (*)(const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, math_Matrix &)) &PLib::HermiteCoefficients, "This build the coefficient of Hermite's polynomes on [FirstParameter, LastParameter]", py::arg("FirstParameter"), py::arg("LastParameter"), py::arg("FirstOrder"), py::arg("LastOrder"), py::arg("MatrixCoefs"));
cls_PLib.def_static("CoefficientsPoles_", (void (*)(const TColgp_Array1OfPnt &, const TColStd_Array1OfReal *, TColgp_Array1OfPnt &, TColStd_Array1OfReal *)) &PLib::CoefficientsPoles, "None", py::arg("Coefs"), py::arg("WCoefs"), py::arg("Poles"), py::arg("WPoles"));
cls_PLib.def_static("CoefficientsPoles_", (void (*)(const TColgp_Array1OfPnt2d &, const TColStd_Array1OfReal *, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal *)) &PLib::CoefficientsPoles, "None", py::arg("Coefs"), py::arg("WCoefs"), py::arg("Poles"), py::arg("WPoles"));
cls_PLib.def_static("CoefficientsPoles_", (void (*)(const TColStd_Array1OfReal &, const TColStd_Array1OfReal *, TColStd_Array1OfReal &, TColStd_Array1OfReal *)) &PLib::CoefficientsPoles, "None", py::arg("Coefs"), py::arg("WCoefs"), py::arg("Poles"), py::arg("WPoles"));
cls_PLib.def_static("CoefficientsPoles_", (void (*)(const Standard_Integer, const TColStd_Array1OfReal &, const TColStd_Array1OfReal *, TColStd_Array1OfReal &, TColStd_Array1OfReal *)) &PLib::CoefficientsPoles, "None", py::arg("dim"), py::arg("Coefs"), py::arg("WCoefs"), py::arg("Poles"), py::arg("WPoles"));
cls_PLib.def_static("Trimming_", (void (*)(const Standard_Real, const Standard_Real, TColgp_Array1OfPnt &, TColStd_Array1OfReal *)) &PLib::Trimming, "None", py::arg("U1"), py::arg("U2"), py::arg("Coeffs"), py::arg("WCoeffs"));
cls_PLib.def_static("Trimming_", (void (*)(const Standard_Real, const Standard_Real, TColgp_Array1OfPnt2d &, TColStd_Array1OfReal *)) &PLib::Trimming, "None", py::arg("U1"), py::arg("U2"), py::arg("Coeffs"), py::arg("WCoeffs"));
cls_PLib.def_static("Trimming_", (void (*)(const Standard_Real, const Standard_Real, TColStd_Array1OfReal &, TColStd_Array1OfReal *)) &PLib::Trimming, "None", py::arg("U1"), py::arg("U2"), py::arg("Coeffs"), py::arg("WCoeffs"));
cls_PLib.def_static("Trimming_", (void (*)(const Standard_Real, const Standard_Real, const Standard_Integer, TColStd_Array1OfReal &, TColStd_Array1OfReal *)) &PLib::Trimming, "None", py::arg("U1"), py::arg("U2"), py::arg("dim"), py::arg("Coeffs"), py::arg("WCoeffs"));
cls_PLib.def_static("CoefficientsPoles_", (void (*)(const TColgp_Array2OfPnt &, const TColStd_Array2OfReal *, TColgp_Array2OfPnt &, TColStd_Array2OfReal *)) &PLib::CoefficientsPoles, "None", py::arg("Coefs"), py::arg("WCoefs"), py::arg("Poles"), py::arg("WPoles"));
cls_PLib.def_static("UTrimming_", (void (*)(const Standard_Real, const Standard_Real, TColgp_Array2OfPnt &, TColStd_Array2OfReal *)) &PLib::UTrimming, "None", py::arg("U1"), py::arg("U2"), py::arg("Coeffs"), py::arg("WCoeffs"));
cls_PLib.def_static("VTrimming_", (void (*)(const Standard_Real, const Standard_Real, TColgp_Array2OfPnt &, TColStd_Array2OfReal *)) &PLib::VTrimming, "None", py::arg("V1"), py::arg("V2"), py::arg("Coeffs"), py::arg("WCoeffs"));
cls_PLib.def_static("HermiteInterpolate_", (Standard_Boolean (*)(const Standard_Integer, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Integer, const TColStd_Array2OfReal &, const TColStd_Array2OfReal &, TColStd_Array1OfReal &)) &PLib::HermiteInterpolate, "Compute the coefficients in the canonical base of the polynomial satisfying the given constraints at the given parameters The array FirstContr(i,j) i=1,Dimension j=0,FirstOrder contains the values of the constraint at parameter FirstParameter idem for LastConstr", py::arg("Dimension"), py::arg("FirstParameter"), py::arg("LastParameter"), py::arg("FirstOrder"), py::arg("LastOrder"), py::arg("FirstConstr"), py::arg("LastConstr"), py::arg("Coefficients"));
cls_PLib.def_static("JacobiParameters_", [](const GeomAbs_Shape ConstraintOrder, const Standard_Integer MaxDegree, const Standard_Integer Code, Standard_Integer & NbGaussPoints, Standard_Integer & WorkDegree){ PLib::JacobiParameters(ConstraintOrder, MaxDegree, Code, NbGaussPoints, WorkDegree); return std::tuple<Standard_Integer &, Standard_Integer &>(NbGaussPoints, WorkDegree); }, "Compute the number of points used for integral computations (NbGaussPoints) and the degree of Jacobi Polynomial (WorkDegree). ConstraintOrder has to be GeomAbs_C0, GeomAbs_C1 or GeomAbs_C2 Code: Code d' init. des parametres de discretisation. = -5 = -4 = -3 = -2 = -1 = 1 calcul rapide avec precision moyenne. = 2 calcul rapide avec meilleure precision. = 3 calcul un peu plus lent avec bonne precision. = 4 calcul lent avec la meilleure precision possible.", py::arg("ConstraintOrder"), py::arg("MaxDegree"), py::arg("Code"), py::arg("NbGaussPoints"), py::arg("WorkDegree"));
cls_PLib.def_static("NivConstr_", (Standard_Integer (*)(const GeomAbs_Shape)) &PLib::NivConstr, "translates from GeomAbs_Shape to Integer", py::arg("ConstraintOrder"));
cls_PLib.def_static("ConstraintOrder_", (GeomAbs_Shape (*)(const Standard_Integer)) &PLib::ConstraintOrder, "translates from Integer to GeomAbs_Shape", py::arg("NivConstr"));
cls_PLib.def_static("EvalLength_", [](const Standard_Integer Degree, const Standard_Integer Dimension, Standard_Real & PolynomialCoeff, const Standard_Real U1, const Standard_Real U2, Standard_Real & Length){ PLib::EvalLength(Degree, Dimension, PolynomialCoeff, U1, U2, Length); return std::tuple<Standard_Real &, Standard_Real &>(PolynomialCoeff, Length); }, "None", py::arg("Degree"), py::arg("Dimension"), py::arg("PolynomialCoeff"), py::arg("U1"), py::arg("U2"), py::arg("Length"));
cls_PLib.def_static("EvalLength_", [](const Standard_Integer Degree, const Standard_Integer Dimension, Standard_Real & PolynomialCoeff, const Standard_Real U1, const Standard_Real U2, const Standard_Real Tol, Standard_Real & Length, Standard_Real & Error){ PLib::EvalLength(Degree, Dimension, PolynomialCoeff, U1, U2, Tol, Length, Error); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(PolynomialCoeff, Length, Error); }, "None", py::arg("Degree"), py::arg("Dimension"), py::arg("PolynomialCoeff"), py::arg("U1"), py::arg("U2"), py::arg("Tol"), py::arg("Length"), py::arg("Error"));

// CLASS: PLIB_BASE
py::class_<PLib_Base, opencascade::handle<PLib_Base>, Standard_Transient> cls_PLib_Base(mod, "PLib_Base", "To work with different polynomial's Bases");

// Methods
cls_PLib_Base.def("ToCoefficients", (void (PLib_Base::*)(const Standard_Integer, const Standard_Integer, const TColStd_Array1OfReal &, TColStd_Array1OfReal &) const) &PLib_Base::ToCoefficients, "Convert the polynomial P(t) in the canonical base.", py::arg("Dimension"), py::arg("Degree"), py::arg("CoeffinBase"), py::arg("Coefficients"));
cls_PLib_Base.def("D0", (void (PLib_Base::*)(const Standard_Real, TColStd_Array1OfReal &)) &PLib_Base::D0, "Compute the values of the basis functions in u", py::arg("U"), py::arg("BasisValue"));
cls_PLib_Base.def("D1", (void (PLib_Base::*)(const Standard_Real, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &PLib_Base::D1, "Compute the values and the derivatives values of the basis functions in u", py::arg("U"), py::arg("BasisValue"), py::arg("BasisD1"));
cls_PLib_Base.def("D2", (void (PLib_Base::*)(const Standard_Real, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &PLib_Base::D2, "Compute the values and the derivatives values of the basis functions in u", py::arg("U"), py::arg("BasisValue"), py::arg("BasisD1"), py::arg("BasisD2"));
cls_PLib_Base.def("D3", (void (PLib_Base::*)(const Standard_Real, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &PLib_Base::D3, "Compute the values and the derivatives values of the basis functions in u", py::arg("U"), py::arg("BasisValue"), py::arg("BasisD1"), py::arg("BasisD2"), py::arg("BasisD3"));
cls_PLib_Base.def("WorkDegree", (Standard_Integer (PLib_Base::*)() const) &PLib_Base::WorkDegree, "returns WorkDegree");
cls_PLib_Base.def("ReduceDegree", [](PLib_Base &self, const Standard_Integer Dimension, const Standard_Integer MaxDegree, const Standard_Real Tol, Standard_Real & BaseCoeff, Standard_Integer & NewDegree, Standard_Real & MaxError){ self.ReduceDegree(Dimension, MaxDegree, Tol, BaseCoeff, NewDegree, MaxError); return std::tuple<Standard_Real &, Standard_Integer &, Standard_Real &>(BaseCoeff, NewDegree, MaxError); }, "Compute NewDegree <= MaxDegree so that MaxError is lower than Tol. MaxError can be greater than Tol if it is not possible to find a NewDegree <= MaxDegree. In this case NewDegree = MaxDegree", py::arg("Dimension"), py::arg("MaxDegree"), py::arg("Tol"), py::arg("BaseCoeff"), py::arg("NewDegree"), py::arg("MaxError"));
cls_PLib_Base.def_static("get_type_name_", (const char * (*)()) &PLib_Base::get_type_name, "None");
cls_PLib_Base.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PLib_Base::get_type_descriptor, "None");
cls_PLib_Base.def("DynamicType", (const opencascade::handle<Standard_Type> & (PLib_Base::*)() const) &PLib_Base::DynamicType, "None");

// CLASS: PLIB_DOUBLEJACOBIPOLYNOMIAL
py::class_<PLib_DoubleJacobiPolynomial> cls_PLib_DoubleJacobiPolynomial(mod, "PLib_DoubleJacobiPolynomial", "None");

// Constructors
cls_PLib_DoubleJacobiPolynomial.def(py::init<>());
cls_PLib_DoubleJacobiPolynomial.def(py::init<const opencascade::handle<PLib_JacobiPolynomial> &, const opencascade::handle<PLib_JacobiPolynomial> &>(), py::arg("JacPolU"), py::arg("JacPolV"));

// Methods
// cls_PLib_DoubleJacobiPolynomial.def_static("operator new_", (void * (*)(size_t)) &PLib_DoubleJacobiPolynomial::operator new, "None", py::arg("theSize"));
// cls_PLib_DoubleJacobiPolynomial.def_static("operator delete_", (void (*)(void *)) &PLib_DoubleJacobiPolynomial::operator delete, "None", py::arg("theAddress"));
// cls_PLib_DoubleJacobiPolynomial.def_static("operator new[]_", (void * (*)(size_t)) &PLib_DoubleJacobiPolynomial::operator new[], "None", py::arg("theSize"));
// cls_PLib_DoubleJacobiPolynomial.def_static("operator delete[]_", (void (*)(void *)) &PLib_DoubleJacobiPolynomial::operator delete[], "None", py::arg("theAddress"));
// cls_PLib_DoubleJacobiPolynomial.def_static("operator new_", (void * (*)(size_t, void *)) &PLib_DoubleJacobiPolynomial::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_PLib_DoubleJacobiPolynomial.def_static("operator delete_", (void (*)(void *, void *)) &PLib_DoubleJacobiPolynomial::operator delete, "None", py::arg(""), py::arg(""));
cls_PLib_DoubleJacobiPolynomial.def("MaxErrorU", (Standard_Real (PLib_DoubleJacobiPolynomial::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColStd_Array1OfReal &) const) &PLib_DoubleJacobiPolynomial::MaxErrorU, "None", py::arg("Dimension"), py::arg("DegreeU"), py::arg("DegreeV"), py::arg("dJacCoeff"), py::arg("JacCoeff"));
cls_PLib_DoubleJacobiPolynomial.def("MaxErrorV", (Standard_Real (PLib_DoubleJacobiPolynomial::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColStd_Array1OfReal &) const) &PLib_DoubleJacobiPolynomial::MaxErrorV, "None", py::arg("Dimension"), py::arg("DegreeU"), py::arg("DegreeV"), py::arg("dJacCoeff"), py::arg("JacCoeff"));
cls_PLib_DoubleJacobiPolynomial.def("MaxError", (Standard_Real (PLib_DoubleJacobiPolynomial::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColStd_Array1OfReal &, const Standard_Real) const) &PLib_DoubleJacobiPolynomial::MaxError, "None", py::arg("Dimension"), py::arg("MinDegreeU"), py::arg("MaxDegreeU"), py::arg("MinDegreeV"), py::arg("MaxDegreeV"), py::arg("dJacCoeff"), py::arg("JacCoeff"), py::arg("Error"));
cls_PLib_DoubleJacobiPolynomial.def("ReduceDegree", [](PLib_DoubleJacobiPolynomial &self, const Standard_Integer Dimension, const Standard_Integer MinDegreeU, const Standard_Integer MaxDegreeU, const Standard_Integer MinDegreeV, const Standard_Integer MaxDegreeV, const Standard_Integer dJacCoeff, const TColStd_Array1OfReal & JacCoeff, const Standard_Real EpmsCut, Standard_Real & MaxError, Standard_Integer & NewDegreeU, Standard_Integer & NewDegreeV){ self.ReduceDegree(Dimension, MinDegreeU, MaxDegreeU, MinDegreeV, MaxDegreeV, dJacCoeff, JacCoeff, EpmsCut, MaxError, NewDegreeU, NewDegreeV); return std::tuple<Standard_Real &, Standard_Integer &, Standard_Integer &>(MaxError, NewDegreeU, NewDegreeV); }, "None", py::arg("Dimension"), py::arg("MinDegreeU"), py::arg("MaxDegreeU"), py::arg("MinDegreeV"), py::arg("MaxDegreeV"), py::arg("dJacCoeff"), py::arg("JacCoeff"), py::arg("EpmsCut"), py::arg("MaxError"), py::arg("NewDegreeU"), py::arg("NewDegreeV"));
cls_PLib_DoubleJacobiPolynomial.def("AverageError", (Standard_Real (PLib_DoubleJacobiPolynomial::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColStd_Array1OfReal &) const) &PLib_DoubleJacobiPolynomial::AverageError, "None", py::arg("Dimension"), py::arg("DegreeU"), py::arg("DegreeV"), py::arg("dJacCoeff"), py::arg("JacCoeff"));
cls_PLib_DoubleJacobiPolynomial.def("WDoubleJacobiToCoefficients", (void (PLib_DoubleJacobiPolynomial::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColStd_Array1OfReal &, TColStd_Array1OfReal &) const) &PLib_DoubleJacobiPolynomial::WDoubleJacobiToCoefficients, "None", py::arg("Dimension"), py::arg("DegreeU"), py::arg("DegreeV"), py::arg("JacCoeff"), py::arg("Coefficients"));
cls_PLib_DoubleJacobiPolynomial.def("U", (opencascade::handle<PLib_JacobiPolynomial> (PLib_DoubleJacobiPolynomial::*)() const) &PLib_DoubleJacobiPolynomial::U, "returns myJacPolU;");
cls_PLib_DoubleJacobiPolynomial.def("V", (opencascade::handle<PLib_JacobiPolynomial> (PLib_DoubleJacobiPolynomial::*)() const) &PLib_DoubleJacobiPolynomial::V, "returns myJacPolV;");
cls_PLib_DoubleJacobiPolynomial.def("TabMaxU", (opencascade::handle<TColStd_HArray1OfReal> (PLib_DoubleJacobiPolynomial::*)() const) &PLib_DoubleJacobiPolynomial::TabMaxU, "returns myTabMaxU;");
cls_PLib_DoubleJacobiPolynomial.def("TabMaxV", (opencascade::handle<TColStd_HArray1OfReal> (PLib_DoubleJacobiPolynomial::*)() const) &PLib_DoubleJacobiPolynomial::TabMaxV, "returns myTabMaxV;");

// CLASS: PLIB_HERMITJACOBI
py::class_<PLib_HermitJacobi, opencascade::handle<PLib_HermitJacobi>, PLib_Base> cls_PLib_HermitJacobi(mod, "PLib_HermitJacobi", "This class provides method to work with Jacobi Polynomials relativly to an order of constraint q = myWorkDegree-2*(myNivConstr+1) Jk(t) for k=0,q compose the Jacobi Polynomial base relativly to the weigth W(t) iorder is the integer value for the constraints: iorder = 0 <=> ConstraintOrder = GeomAbs_C0 iorder = 1 <=> ConstraintOrder = GeomAbs_C1 iorder = 2 <=> ConstraintOrder = GeomAbs_C2 P(t) = H(t) + W(t) * Q(t) Where W(t) = (1-t**2)**(2*iordre+2) the coefficients JacCoeff represents P(t) JacCoeff are stored as follow:");

// Constructors
cls_PLib_HermitJacobi.def(py::init<const Standard_Integer, const GeomAbs_Shape>(), py::arg("WorkDegree"), py::arg("ConstraintOrder"));

// Methods
cls_PLib_HermitJacobi.def("MaxError", [](PLib_HermitJacobi &self, const Standard_Integer Dimension, Standard_Real & HermJacCoeff, const Standard_Integer NewDegree){ Standard_Real rv = self.MaxError(Dimension, HermJacCoeff, NewDegree); return std::tuple<Standard_Real, Standard_Real &>(rv, HermJacCoeff); }, "This method computes the maximum error on the polynomial W(t) Q(t) obtained by missing the coefficients of JacCoeff from NewDegree +1 to Degree", py::arg("Dimension"), py::arg("HermJacCoeff"), py::arg("NewDegree"));
cls_PLib_HermitJacobi.def("ReduceDegree", [](PLib_HermitJacobi &self, const Standard_Integer Dimension, const Standard_Integer MaxDegree, const Standard_Real Tol, Standard_Real & HermJacCoeff, Standard_Integer & NewDegree, Standard_Real & MaxError){ self.ReduceDegree(Dimension, MaxDegree, Tol, HermJacCoeff, NewDegree, MaxError); return std::tuple<Standard_Real &, Standard_Integer &, Standard_Real &>(HermJacCoeff, NewDegree, MaxError); }, "Compute NewDegree <= MaxDegree so that MaxError is lower than Tol. MaxError can be greater than Tol if it is not possible to find a NewDegree <= MaxDegree. In this case NewDegree = MaxDegree", py::arg("Dimension"), py::arg("MaxDegree"), py::arg("Tol"), py::arg("HermJacCoeff"), py::arg("NewDegree"), py::arg("MaxError"));
cls_PLib_HermitJacobi.def("AverageError", [](PLib_HermitJacobi &self, const Standard_Integer Dimension, Standard_Real & HermJacCoeff, const Standard_Integer NewDegree){ Standard_Real rv = self.AverageError(Dimension, HermJacCoeff, NewDegree); return std::tuple<Standard_Real, Standard_Real &>(rv, HermJacCoeff); }, "None", py::arg("Dimension"), py::arg("HermJacCoeff"), py::arg("NewDegree"));
cls_PLib_HermitJacobi.def("ToCoefficients", (void (PLib_HermitJacobi::*)(const Standard_Integer, const Standard_Integer, const TColStd_Array1OfReal &, TColStd_Array1OfReal &) const) &PLib_HermitJacobi::ToCoefficients, "Convert the polynomial P(t) = H(t) + W(t) Q(t) in the canonical base.", py::arg("Dimension"), py::arg("Degree"), py::arg("HermJacCoeff"), py::arg("Coefficients"));
cls_PLib_HermitJacobi.def("D0", (void (PLib_HermitJacobi::*)(const Standard_Real, TColStd_Array1OfReal &)) &PLib_HermitJacobi::D0, "Compute the values of the basis functions in u", py::arg("U"), py::arg("BasisValue"));
cls_PLib_HermitJacobi.def("D1", (void (PLib_HermitJacobi::*)(const Standard_Real, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &PLib_HermitJacobi::D1, "Compute the values and the derivatives values of the basis functions in u", py::arg("U"), py::arg("BasisValue"), py::arg("BasisD1"));
cls_PLib_HermitJacobi.def("D2", (void (PLib_HermitJacobi::*)(const Standard_Real, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &PLib_HermitJacobi::D2, "Compute the values and the derivatives values of the basis functions in u", py::arg("U"), py::arg("BasisValue"), py::arg("BasisD1"), py::arg("BasisD2"));
cls_PLib_HermitJacobi.def("D3", (void (PLib_HermitJacobi::*)(const Standard_Real, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &PLib_HermitJacobi::D3, "Compute the values and the derivatives values of the basis functions in u", py::arg("U"), py::arg("BasisValue"), py::arg("BasisD1"), py::arg("BasisD2"), py::arg("BasisD3"));
cls_PLib_HermitJacobi.def("WorkDegree", (Standard_Integer (PLib_HermitJacobi::*)() const) &PLib_HermitJacobi::WorkDegree, "returns WorkDegree");
cls_PLib_HermitJacobi.def("NivConstr", (Standard_Integer (PLib_HermitJacobi::*)() const) &PLib_HermitJacobi::NivConstr, "returns NivConstr");
cls_PLib_HermitJacobi.def_static("get_type_name_", (const char * (*)()) &PLib_HermitJacobi::get_type_name, "None");
cls_PLib_HermitJacobi.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PLib_HermitJacobi::get_type_descriptor, "None");
cls_PLib_HermitJacobi.def("DynamicType", (const opencascade::handle<Standard_Type> & (PLib_HermitJacobi::*)() const) &PLib_HermitJacobi::DynamicType, "None");

// CLASS: PLIB_JACOBIPOLYNOMIAL
py::class_<PLib_JacobiPolynomial, opencascade::handle<PLib_JacobiPolynomial>, PLib_Base> cls_PLib_JacobiPolynomial(mod, "PLib_JacobiPolynomial", "This class provides method to work with Jacobi Polynomials relativly to an order of constraint q = myWorkDegree-2*(myNivConstr+1) Jk(t) for k=0,q compose the Jacobi Polynomial base relativly to the weigth W(t) iorder is the integer value for the constraints: iorder = 0 <=> ConstraintOrder = GeomAbs_C0 iorder = 1 <=> ConstraintOrder = GeomAbs_C1 iorder = 2 <=> ConstraintOrder = GeomAbs_C2 P(t) = R(t) + W(t) * Q(t) Where W(t) = (1-t**2)**(2*iordre+2) the coefficients JacCoeff represents P(t) JacCoeff are stored as follow:");

// Constructors
cls_PLib_JacobiPolynomial.def(py::init<const Standard_Integer, const GeomAbs_Shape>(), py::arg("WorkDegree"), py::arg("ConstraintOrder"));

// Methods
cls_PLib_JacobiPolynomial.def("Points", (void (PLib_JacobiPolynomial::*)(const Standard_Integer, TColStd_Array1OfReal &) const) &PLib_JacobiPolynomial::Points, "returns the Jacobi Points for Gauss integration ie the positive values of the Legendre roots by increasing values NbGaussPoints is the number of points choosen for the integral computation. TabPoints (0,NbGaussPoints/2) TabPoints (0) is loaded only for the odd values of NbGaussPoints The possible values for NbGaussPoints are : 8, 10, 15, 20, 25, 30, 35, 40, 50, 61 NbGaussPoints must be greater than Degree", py::arg("NbGaussPoints"), py::arg("TabPoints"));
cls_PLib_JacobiPolynomial.def("Weights", (void (PLib_JacobiPolynomial::*)(const Standard_Integer, TColStd_Array2OfReal &) const) &PLib_JacobiPolynomial::Weights, "returns the Jacobi weigths for Gauss integration only for the positive values of the Legendre roots in the order they are given by the method Points NbGaussPoints is the number of points choosen for the integral computation. TabWeights (0,NbGaussPoints/2,0,Degree) TabWeights (0,.) are only loaded for the odd values of NbGaussPoints The possible values for NbGaussPoints are : 8 , 10 , 15 ,20 ,25 , 30, 35 , 40 , 50 , 61 NbGaussPoints must be greater than Degree", py::arg("NbGaussPoints"), py::arg("TabWeights"));
cls_PLib_JacobiPolynomial.def("MaxValue", (void (PLib_JacobiPolynomial::*)(TColStd_Array1OfReal &) const) &PLib_JacobiPolynomial::MaxValue, "this method loads for k=0,q the maximum value of abs ( W(t)*Jk(t) )for t bellonging to [-1,1] This values are loaded is the array TabMax(0,myWorkDegree-2*(myNivConst+1)) MaxValue ( me ; TabMaxPointer : in out Real );", py::arg("TabMax"));
cls_PLib_JacobiPolynomial.def("MaxError", [](PLib_JacobiPolynomial &self, const Standard_Integer Dimension, Standard_Real & JacCoeff, const Standard_Integer NewDegree){ Standard_Real rv = self.MaxError(Dimension, JacCoeff, NewDegree); return std::tuple<Standard_Real, Standard_Real &>(rv, JacCoeff); }, "This method computes the maximum error on the polynomial W(t) Q(t) obtained by missing the coefficients of JacCoeff from NewDegree +1 to Degree", py::arg("Dimension"), py::arg("JacCoeff"), py::arg("NewDegree"));
cls_PLib_JacobiPolynomial.def("ReduceDegree", [](PLib_JacobiPolynomial &self, const Standard_Integer Dimension, const Standard_Integer MaxDegree, const Standard_Real Tol, Standard_Real & JacCoeff, Standard_Integer & NewDegree, Standard_Real & MaxError){ self.ReduceDegree(Dimension, MaxDegree, Tol, JacCoeff, NewDegree, MaxError); return std::tuple<Standard_Real &, Standard_Integer &, Standard_Real &>(JacCoeff, NewDegree, MaxError); }, "Compute NewDegree <= MaxDegree so that MaxError is lower than Tol. MaxError can be greater than Tol if it is not possible to find a NewDegree <= MaxDegree. In this case NewDegree = MaxDegree", py::arg("Dimension"), py::arg("MaxDegree"), py::arg("Tol"), py::arg("JacCoeff"), py::arg("NewDegree"), py::arg("MaxError"));
cls_PLib_JacobiPolynomial.def("AverageError", [](PLib_JacobiPolynomial &self, const Standard_Integer Dimension, Standard_Real & JacCoeff, const Standard_Integer NewDegree){ Standard_Real rv = self.AverageError(Dimension, JacCoeff, NewDegree); return std::tuple<Standard_Real, Standard_Real &>(rv, JacCoeff); }, "None", py::arg("Dimension"), py::arg("JacCoeff"), py::arg("NewDegree"));
cls_PLib_JacobiPolynomial.def("ToCoefficients", (void (PLib_JacobiPolynomial::*)(const Standard_Integer, const Standard_Integer, const TColStd_Array1OfReal &, TColStd_Array1OfReal &) const) &PLib_JacobiPolynomial::ToCoefficients, "Convert the polynomial P(t) = R(t) + W(t) Q(t) in the canonical base.", py::arg("Dimension"), py::arg("Degree"), py::arg("JacCoeff"), py::arg("Coefficients"));
cls_PLib_JacobiPolynomial.def("D0", (void (PLib_JacobiPolynomial::*)(const Standard_Real, TColStd_Array1OfReal &)) &PLib_JacobiPolynomial::D0, "Compute the values of the basis functions in u", py::arg("U"), py::arg("BasisValue"));
cls_PLib_JacobiPolynomial.def("D1", (void (PLib_JacobiPolynomial::*)(const Standard_Real, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &PLib_JacobiPolynomial::D1, "Compute the values and the derivatives values of the basis functions in u", py::arg("U"), py::arg("BasisValue"), py::arg("BasisD1"));
cls_PLib_JacobiPolynomial.def("D2", (void (PLib_JacobiPolynomial::*)(const Standard_Real, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &PLib_JacobiPolynomial::D2, "Compute the values and the derivatives values of the basis functions in u", py::arg("U"), py::arg("BasisValue"), py::arg("BasisD1"), py::arg("BasisD2"));
cls_PLib_JacobiPolynomial.def("D3", (void (PLib_JacobiPolynomial::*)(const Standard_Real, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &PLib_JacobiPolynomial::D3, "Compute the values and the derivatives values of the basis functions in u", py::arg("U"), py::arg("BasisValue"), py::arg("BasisD1"), py::arg("BasisD2"), py::arg("BasisD3"));
cls_PLib_JacobiPolynomial.def("WorkDegree", (Standard_Integer (PLib_JacobiPolynomial::*)() const) &PLib_JacobiPolynomial::WorkDegree, "returns WorkDegree");
cls_PLib_JacobiPolynomial.def("NivConstr", (Standard_Integer (PLib_JacobiPolynomial::*)() const) &PLib_JacobiPolynomial::NivConstr, "returns NivConstr");
cls_PLib_JacobiPolynomial.def_static("get_type_name_", (const char * (*)()) &PLib_JacobiPolynomial::get_type_name, "None");
cls_PLib_JacobiPolynomial.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &PLib_JacobiPolynomial::get_type_descriptor, "None");
cls_PLib_JacobiPolynomial.def("DynamicType", (const opencascade::handle<Standard_Type> & (PLib_JacobiPolynomial::*)() const) &PLib_JacobiPolynomial::DynamicType, "None");


}
