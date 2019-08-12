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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_HArray2OfInteger.hxx>
#include <math_Matrix.hxx>
#include <math_Vector.hxx>
#include <FEmTool_ElementaryCriterion.hxx>
#include <Standard_Type.hxx>

void bind_FEmTool_ElementaryCriterion(py::module &mod){

py::class_<FEmTool_ElementaryCriterion, opencascade::handle<FEmTool_ElementaryCriterion>, Standard_Transient> cls_FEmTool_ElementaryCriterion(mod, "FEmTool_ElementaryCriterion", "defined J Criteria to used in minimisation");

// Fields

// Methods
cls_FEmTool_ElementaryCriterion.def("Set", (void (FEmTool_ElementaryCriterion::*)(const opencascade::handle<TColStd_HArray2OfReal> &)) &FEmTool_ElementaryCriterion::Set, "Set the coefficient of the Element (the Curve)", py::arg("Coeff"));
cls_FEmTool_ElementaryCriterion.def("Set", (void (FEmTool_ElementaryCriterion::*)(const Standard_Real, const Standard_Real)) &FEmTool_ElementaryCriterion::Set, "Set the definition interval of the Element", py::arg("FirstKnot"), py::arg("LastKnot"));
cls_FEmTool_ElementaryCriterion.def("DependenceTable", (opencascade::handle<TColStd_HArray2OfInteger> (FEmTool_ElementaryCriterion::*)() const) &FEmTool_ElementaryCriterion::DependenceTable, "To know if two dimension are independent.");
cls_FEmTool_ElementaryCriterion.def("Value", (Standard_Real (FEmTool_ElementaryCriterion::*)()) &FEmTool_ElementaryCriterion::Value, "To Compute J(E) where E is the current Element");
cls_FEmTool_ElementaryCriterion.def("Hessian", (void (FEmTool_ElementaryCriterion::*)(const Standard_Integer, const Standard_Integer, math_Matrix &)) &FEmTool_ElementaryCriterion::Hessian, "To Compute J(E) the coefficients of Hessian matrix of J(E) wich are crossed derivatives in dimensions <Dim1> and <Dim2>. If DependenceTable(Dimension1,Dimension2) is False", py::arg("Dim1"), py::arg("Dim2"), py::arg("H"));
cls_FEmTool_ElementaryCriterion.def("Gradient", (void (FEmTool_ElementaryCriterion::*)(const Standard_Integer, math_Vector &)) &FEmTool_ElementaryCriterion::Gradient, "To Compute the coefficients in the dimension <dim> of the J(E)'s Gradient where E is the current Element", py::arg("Dim"), py::arg("G"));
cls_FEmTool_ElementaryCriterion.def_static("get_type_name_", (const char * (*)()) &FEmTool_ElementaryCriterion::get_type_name, "None");
cls_FEmTool_ElementaryCriterion.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &FEmTool_ElementaryCriterion::get_type_descriptor, "None");
cls_FEmTool_ElementaryCriterion.def("DynamicType", (const opencascade::handle<Standard_Type> & (FEmTool_ElementaryCriterion::*)() const) &FEmTool_ElementaryCriterion::DynamicType, "None");

// Enums

}