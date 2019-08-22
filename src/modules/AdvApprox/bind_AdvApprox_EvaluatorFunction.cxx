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
#include <Standard_TypeDef.hxx>
#include <AdvApprox_EvaluatorFunction.hxx>

void bind_AdvApprox_EvaluatorFunction(py::module &mod){

py::class_<AdvApprox_EvaluatorFunction> cls_AdvApprox_EvaluatorFunction(mod, "AdvApprox_EvaluatorFunction", "Interface for a class implementing a function to be approximated by AdvApprox_ApproxAFunction");

// Fields

// Methods
// cls_AdvApprox_EvaluatorFunction.def("Evaluate", [](AdvApprox_EvaluatorFunction &self, Standard_Integer * Dimension, Standard_Real [2] StartEnd, Standard_Real * Parameter, Standard_Integer * DerivativeRequest, Standard_Real * Result, Standard_Integer * ErrorCode){ self.Evaluate(Dimension, StartEnd, Parameter, DerivativeRequest, Result, ErrorCode); return std::tuple<Standard_Integer *, Standard_Real *, Standard_Integer *, Standard_Real *, Standard_Integer *>(Dimension, Parameter, DerivativeRequest, Result, ErrorCode); }, "Function evaluation method to be defined by descendant", py::arg("Dimension"), py::arg("StartEnd"), py::arg("Parameter"), py::arg("DerivativeRequest"), py::arg("Result"), py::arg("ErrorCode"));
// cls_AdvApprox_EvaluatorFunction.def("__call__", [](AdvApprox_EvaluatorFunction &self, Standard_Integer * Dimension, Standard_Real [2] StartEnd, Standard_Real * Parameter, Standard_Integer * DerivativeRequest, Standard_Real * Result, Standard_Integer * ErrorCode){ self.operator()(Dimension, StartEnd, Parameter, DerivativeRequest, Result, ErrorCode); return std::tuple<Standard_Integer *, Standard_Real *, Standard_Integer *, Standard_Real *, Standard_Integer *>(Dimension, Parameter, DerivativeRequest, Result, ErrorCode); }, "Shortcut for function-call style usage", py::arg("Dimension"), py::arg("StartEnd"), py::arg("Parameter"), py::arg("DerivativeRequest"), py::arg("Result"), py::arg("ErrorCode"));

// Enums

}