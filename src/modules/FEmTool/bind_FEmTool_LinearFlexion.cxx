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
#include <FEmTool_LinearFlexion.hxx>
#include <Standard_Type.hxx>

void bind_FEmTool_LinearFlexion(py::module &mod){

py::class_<FEmTool_LinearFlexion, opencascade::handle<FEmTool_LinearFlexion>, FEmTool_ElementaryCriterion> cls_FEmTool_LinearFlexion(mod, "FEmTool_LinearFlexion", "Criterium of LinearFlexion To Hermit-Jacobi elements");

// Constructors
cls_FEmTool_LinearFlexion.def(py::init<const Standard_Integer, const GeomAbs_Shape>(), py::arg("WorkDegree"), py::arg("ConstraintOrder"));

// Fields

// Methods
cls_FEmTool_LinearFlexion.def("DependenceTable", (opencascade::handle<TColStd_HArray2OfInteger> (FEmTool_LinearFlexion::*)() const) &FEmTool_LinearFlexion::DependenceTable, "None");
cls_FEmTool_LinearFlexion.def("Value", (Standard_Real (FEmTool_LinearFlexion::*)()) &FEmTool_LinearFlexion::Value, "None");
cls_FEmTool_LinearFlexion.def("Hessian", (void (FEmTool_LinearFlexion::*)(const Standard_Integer, const Standard_Integer, math_Matrix &)) &FEmTool_LinearFlexion::Hessian, "None", py::arg("Dimension1"), py::arg("Dimension2"), py::arg("H"));
cls_FEmTool_LinearFlexion.def("Gradient", (void (FEmTool_LinearFlexion::*)(const Standard_Integer, math_Vector &)) &FEmTool_LinearFlexion::Gradient, "None", py::arg("Dimension"), py::arg("G"));
cls_FEmTool_LinearFlexion.def_static("get_type_name_", (const char * (*)()) &FEmTool_LinearFlexion::get_type_name, "None");
cls_FEmTool_LinearFlexion.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &FEmTool_LinearFlexion::get_type_descriptor, "None");
cls_FEmTool_LinearFlexion.def("DynamicType", (const opencascade::handle<Standard_Type> & (FEmTool_LinearFlexion::*)() const) &FEmTool_LinearFlexion::DynamicType, "None");

// Enums

}