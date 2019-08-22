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

void bind_PLib(py::module &mod){

py::class_<PLib> cls_PLib(mod, "PLib", "PLib means Polynomial functions library. This pk provides basic computation functions for polynomial functions. Note: weight arrays can be passed by pointer for some functions so that NULL pointer is valid. That means no weights passed.");

// Constructors

// Fields

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

// Enums

}