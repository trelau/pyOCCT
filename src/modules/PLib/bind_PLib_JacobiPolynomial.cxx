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
#include <PLib_Base.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <Standard_Handle.hxx>
#include <PLib_JacobiPolynomial.hxx>
#include <Standard_Type.hxx>
#include <TColStd_HArray1OfReal.hxx>

void bind_PLib_JacobiPolynomial(py::module &mod){

py::class_<PLib_JacobiPolynomial, opencascade::handle<PLib_JacobiPolynomial>, PLib_Base> cls_PLib_JacobiPolynomial(mod, "PLib_JacobiPolynomial", "This class provides method to work with Jacobi Polynomials relativly to an order of constraint q = myWorkDegree-2*(myNivConstr+1) Jk(t) for k=0,q compose the Jacobi Polynomial base relativly to the weigth W(t) iorder is the integer value for the constraints: iorder = 0 <=> ConstraintOrder = GeomAbs_C0 iorder = 1 <=> ConstraintOrder = GeomAbs_C1 iorder = 2 <=> ConstraintOrder = GeomAbs_C2 P(t) = R(t) + W(t) * Q(t) Where W(t) = (1-t**2)**(2*iordre+2) the coefficients JacCoeff represents P(t) JacCoeff are stored as follow:");

// Constructors
cls_PLib_JacobiPolynomial.def(py::init<const Standard_Integer, const GeomAbs_Shape>(), py::arg("WorkDegree"), py::arg("ConstraintOrder"));

// Fields

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

// Enums

}