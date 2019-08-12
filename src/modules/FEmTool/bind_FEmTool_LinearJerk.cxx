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
#include <FEmTool_ElementaryCriterion.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray2OfInteger.hxx>
#include <math_Matrix.hxx>
#include <math_Vector.hxx>
#include <FEmTool_LinearJerk.hxx>
#include <Standard_Type.hxx>

void bind_FEmTool_LinearJerk(py::module &mod){

py::class_<FEmTool_LinearJerk, opencascade::handle<FEmTool_LinearJerk>, FEmTool_ElementaryCriterion> cls_FEmTool_LinearJerk(mod, "FEmTool_LinearJerk", "Criterion of LinearJerk To Hermit-Jacobi elements");

// Constructors
cls_FEmTool_LinearJerk.def(py::init<const Standard_Integer, const GeomAbs_Shape>(), py::arg("WorkDegree"), py::arg("ConstraintOrder"));

// Fields

// Methods
cls_FEmTool_LinearJerk.def("DependenceTable", (opencascade::handle<TColStd_HArray2OfInteger> (FEmTool_LinearJerk::*)() const) &FEmTool_LinearJerk::DependenceTable, "None");
cls_FEmTool_LinearJerk.def("Value", (Standard_Real (FEmTool_LinearJerk::*)()) &FEmTool_LinearJerk::Value, "None");
cls_FEmTool_LinearJerk.def("Hessian", (void (FEmTool_LinearJerk::*)(const Standard_Integer, const Standard_Integer, math_Matrix &)) &FEmTool_LinearJerk::Hessian, "None", py::arg("Dimension1"), py::arg("Dimension2"), py::arg("H"));
cls_FEmTool_LinearJerk.def("Gradient", (void (FEmTool_LinearJerk::*)(const Standard_Integer, math_Vector &)) &FEmTool_LinearJerk::Gradient, "None", py::arg("Dimension"), py::arg("G"));
cls_FEmTool_LinearJerk.def_static("get_type_name_", (const char * (*)()) &FEmTool_LinearJerk::get_type_name, "None");
cls_FEmTool_LinearJerk.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &FEmTool_LinearJerk::get_type_descriptor, "None");
cls_FEmTool_LinearJerk.def("DynamicType", (const opencascade::handle<Standard_Type> & (FEmTool_LinearJerk::*)() const) &FEmTool_LinearJerk::DynamicType, "None");

// Enums

}