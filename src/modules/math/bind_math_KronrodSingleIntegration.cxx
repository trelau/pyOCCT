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
#include <math_Function.hxx>
#include <Standard_TypeDef.hxx>
#include <math_Vector.hxx>
#include <math_KronrodSingleIntegration.hxx>

void bind_math_KronrodSingleIntegration(py::module &mod){

py::class_<math_KronrodSingleIntegration> cls_math_KronrodSingleIntegration(mod, "math_KronrodSingleIntegration", "This class implements the Gauss-Kronrod method of integral computation.");

// Constructors
cls_math_KronrodSingleIntegration.def(py::init<>());
cls_math_KronrodSingleIntegration.def(py::init<math_Function &, const Standard_Real, const Standard_Real, const Standard_Integer>(), py::arg("theFunction"), py::arg("theLower"), py::arg("theUpper"), py::arg("theNbPnts"));
cls_math_KronrodSingleIntegration.def(py::init<math_Function &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Integer>(), py::arg("theFunction"), py::arg("theLower"), py::arg("theUpper"), py::arg("theNbPnts"), py::arg("theTolerance"), py::arg("theMaxNbIter"));

// Fields

// Methods
// cls_math_KronrodSingleIntegration.def_static("operator new_", (void * (*)(size_t)) &math_KronrodSingleIntegration::operator new, "None", py::arg("theSize"));
// cls_math_KronrodSingleIntegration.def_static("operator delete_", (void (*)(void *)) &math_KronrodSingleIntegration::operator delete, "None", py::arg("theAddress"));
// cls_math_KronrodSingleIntegration.def_static("operator new[]_", (void * (*)(size_t)) &math_KronrodSingleIntegration::operator new[], "None", py::arg("theSize"));
// cls_math_KronrodSingleIntegration.def_static("operator delete[]_", (void (*)(void *)) &math_KronrodSingleIntegration::operator delete[], "None", py::arg("theAddress"));
// cls_math_KronrodSingleIntegration.def_static("operator new_", (void * (*)(size_t, void *)) &math_KronrodSingleIntegration::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_math_KronrodSingleIntegration.def_static("operator delete_", (void (*)(void *, void *)) &math_KronrodSingleIntegration::operator delete, "None", py::arg(""), py::arg(""));
cls_math_KronrodSingleIntegration.def("Perform", (void (math_KronrodSingleIntegration::*)(math_Function &, const Standard_Real, const Standard_Real, const Standard_Integer)) &math_KronrodSingleIntegration::Perform, "Computation of the integral. Takes the function, the lower and upper bound values, the initial number of Kronrod points, the relative tolerance value and the maximal number of iterations as parameters. theNbPnts should be odd and greater then or equal to 3.", py::arg("theFunction"), py::arg("theLower"), py::arg("theUpper"), py::arg("theNbPnts"));
cls_math_KronrodSingleIntegration.def("Perform", (void (math_KronrodSingleIntegration::*)(math_Function &, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real, const Standard_Integer)) &math_KronrodSingleIntegration::Perform, "Computation of the integral. Takes the function, the lower and upper bound values, the initial number of Kronrod points, the relative tolerance value and the maximal number of iterations as parameters. theNbPnts should be odd and greater then or equal to 3. Note that theTolerance is relative, i.e. the criterion of solution reaching is: Abs(Kronrod - Gauss)/Abs(Kronrod) < theTolerance. theTolerance should be positive.", py::arg("theFunction"), py::arg("theLower"), py::arg("theUpper"), py::arg("theNbPnts"), py::arg("theTolerance"), py::arg("theMaxNbIter"));
cls_math_KronrodSingleIntegration.def("IsDone", (Standard_Boolean (math_KronrodSingleIntegration::*)() const) &math_KronrodSingleIntegration::IsDone, "Returns Standard_True if computation is performed successfully.");
cls_math_KronrodSingleIntegration.def("Value", (Standard_Real (math_KronrodSingleIntegration::*)() const) &math_KronrodSingleIntegration::Value, "Returns the value of the integral.");
cls_math_KronrodSingleIntegration.def("ErrorReached", (Standard_Real (math_KronrodSingleIntegration::*)() const) &math_KronrodSingleIntegration::ErrorReached, "Returns the value of the relative error reached.");
cls_math_KronrodSingleIntegration.def("AbsolutError", (Standard_Real (math_KronrodSingleIntegration::*)() const) &math_KronrodSingleIntegration::AbsolutError, "Returns the value of the relative error reached.");
cls_math_KronrodSingleIntegration.def("OrderReached", (Standard_Integer (math_KronrodSingleIntegration::*)() const) &math_KronrodSingleIntegration::OrderReached, "Returns the number of Kronrod points for which the result is computed.");
cls_math_KronrodSingleIntegration.def("NbIterReached", (Standard_Integer (math_KronrodSingleIntegration::*)() const) &math_KronrodSingleIntegration::NbIterReached, "Returns the number of iterations that were made to compute result.");
cls_math_KronrodSingleIntegration.def_static("GKRule_", [](math_Function & theFunction, const Standard_Real theLower, const Standard_Real theUpper, const math_Vector & theGaussP, const math_Vector & theGaussW, const math_Vector & theKronrodP, const math_Vector & theKronrodW, Standard_Real & theValue, Standard_Real & theError){ Standard_Boolean rv = math_KronrodSingleIntegration::GKRule(theFunction, theLower, theUpper, theGaussP, theGaussW, theKronrodP, theKronrodW, theValue, theError); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &>(rv, theValue, theError); }, "None", py::arg("theFunction"), py::arg("theLower"), py::arg("theUpper"), py::arg("theGaussP"), py::arg("theGaussW"), py::arg("theKronrodP"), py::arg("theKronrodW"), py::arg("theValue"), py::arg("theError"));

// Enums

}