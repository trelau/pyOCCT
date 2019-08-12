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
#include <Standard_Handle.hxx>
#include <PLib_HermitJacobi.hxx>
#include <Standard_Type.hxx>
#include <math_Matrix.hxx>
#include <PLib_JacobiPolynomial.hxx>

void bind_PLib_HermitJacobi(py::module &mod){

py::class_<PLib_HermitJacobi, opencascade::handle<PLib_HermitJacobi>, PLib_Base> cls_PLib_HermitJacobi(mod, "PLib_HermitJacobi", "This class provides method to work with Jacobi Polynomials relativly to an order of constraint q = myWorkDegree-2*(myNivConstr+1) Jk(t) for k=0,q compose the Jacobi Polynomial base relativly to the weigth W(t) iorder is the integer value for the constraints: iorder = 0 <=> ConstraintOrder = GeomAbs_C0 iorder = 1 <=> ConstraintOrder = GeomAbs_C1 iorder = 2 <=> ConstraintOrder = GeomAbs_C2 P(t) = H(t) + W(t) * Q(t) Where W(t) = (1-t**2)**(2*iordre+2) the coefficients JacCoeff represents P(t) JacCoeff are stored as follow:");

// Constructors
cls_PLib_HermitJacobi.def(py::init<const Standard_Integer, const GeomAbs_Shape>(), py::arg("WorkDegree"), py::arg("ConstraintOrder"));

// Fields

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

// Enums

}