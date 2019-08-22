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
#include <Standard_Handle.hxx>
#include <PLib_JacobiPolynomial.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <PLib_DoubleJacobiPolynomial.hxx>

void bind_PLib_DoubleJacobiPolynomial(py::module &mod){

py::class_<PLib_DoubleJacobiPolynomial> cls_PLib_DoubleJacobiPolynomial(mod, "PLib_DoubleJacobiPolynomial", "None");

// Constructors
cls_PLib_DoubleJacobiPolynomial.def(py::init<>());
cls_PLib_DoubleJacobiPolynomial.def(py::init<const opencascade::handle<PLib_JacobiPolynomial> &, const opencascade::handle<PLib_JacobiPolynomial> &>(), py::arg("JacPolU"), py::arg("JacPolV"));

// Fields

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

// Enums

}