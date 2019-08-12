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
#include <AdvApp2Var_EvaluatorFunc2Var.hxx>

void bind_AdvApp2Var_EvaluatorFunc2Var(py::module &mod){

py::class_<AdvApp2Var_EvaluatorFunc2Var, std::unique_ptr<AdvApp2Var_EvaluatorFunc2Var, Deleter<AdvApp2Var_EvaluatorFunc2Var>>> cls_AdvApp2Var_EvaluatorFunc2Var(mod, "AdvApp2Var_EvaluatorFunc2Var", "None");

// Fields

// Methods
cls_AdvApp2Var_EvaluatorFunc2Var.def("Evaluate", [](AdvApp2Var_EvaluatorFunc2Var &self, Standard_Integer * theDimension, Standard_Real * theUStartEnd, Standard_Real * theVStartEnd, Standard_Integer * theFavorIso, Standard_Real * theConstParam, Standard_Integer * theNbParams, Standard_Real * theParameters, Standard_Integer * theUOrder, Standard_Integer * theVOrder, Standard_Real * theResult, Standard_Integer * theErrorCode){ self.Evaluate(theDimension, theUStartEnd, theVStartEnd, theFavorIso, theConstParam, theNbParams, theParameters, theUOrder, theVOrder, theResult, theErrorCode); return std::tuple<Standard_Integer *, Standard_Real *, Standard_Real *, Standard_Integer *, Standard_Real *, Standard_Integer *, Standard_Real *, Standard_Integer *, Standard_Integer *, Standard_Real *, Standard_Integer *>(theDimension, theUStartEnd, theVStartEnd, theFavorIso, theConstParam, theNbParams, theParameters, theUOrder, theVOrder, theResult, theErrorCode); }, "Function evaluation method to be defined by descendant", py::arg("theDimension"), py::arg("theUStartEnd"), py::arg("theVStartEnd"), py::arg("theFavorIso"), py::arg("theConstParam"), py::arg("theNbParams"), py::arg("theParameters"), py::arg("theUOrder"), py::arg("theVOrder"), py::arg("theResult"), py::arg("theErrorCode"));
cls_AdvApp2Var_EvaluatorFunc2Var.def("__call__", [](AdvApp2Var_EvaluatorFunc2Var &self, Standard_Integer * theDimension, Standard_Real * theUStartEnd, Standard_Real * theVStartEnd, Standard_Integer * theFavorIso, Standard_Real * theConstParam, Standard_Integer * theNbParams, Standard_Real * theParameters, Standard_Integer * theUOrder, Standard_Integer * theVOrder, Standard_Real * theResult, Standard_Integer * theErrorCode){ self.operator()(theDimension, theUStartEnd, theVStartEnd, theFavorIso, theConstParam, theNbParams, theParameters, theUOrder, theVOrder, theResult, theErrorCode); return std::tuple<Standard_Integer *, Standard_Real *, Standard_Real *, Standard_Integer *, Standard_Real *, Standard_Integer *, Standard_Real *, Standard_Integer *, Standard_Integer *, Standard_Real *, Standard_Integer *>(theDimension, theUStartEnd, theVStartEnd, theFavorIso, theConstParam, theNbParams, theParameters, theUOrder, theVOrder, theResult, theErrorCode); }, "Shortcut for function-call style usage", py::arg("theDimension"), py::arg("theUStartEnd"), py::arg("theVStartEnd"), py::arg("theFavorIso"), py::arg("theConstParam"), py::arg("theNbParams"), py::arg("theParameters"), py::arg("theUOrder"), py::arg("theVOrder"), py::arg("theResult"), py::arg("theErrorCode"));

// Enums

}