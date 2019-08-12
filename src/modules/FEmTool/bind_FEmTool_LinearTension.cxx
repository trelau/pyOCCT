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
#include <FEmTool_LinearTension.hxx>
#include <Standard_Type.hxx>

void bind_FEmTool_LinearTension(py::module &mod){

py::class_<FEmTool_LinearTension, opencascade::handle<FEmTool_LinearTension>, FEmTool_ElementaryCriterion> cls_FEmTool_LinearTension(mod, "FEmTool_LinearTension", "Criterium of LinearTension To Hermit-Jacobi elements");

// Constructors
cls_FEmTool_LinearTension.def(py::init<const Standard_Integer, const GeomAbs_Shape>(), py::arg("WorkDegree"), py::arg("ConstraintOrder"));

// Fields

// Methods
cls_FEmTool_LinearTension.def("DependenceTable", (opencascade::handle<TColStd_HArray2OfInteger> (FEmTool_LinearTension::*)() const) &FEmTool_LinearTension::DependenceTable, "None");
cls_FEmTool_LinearTension.def("Value", (Standard_Real (FEmTool_LinearTension::*)()) &FEmTool_LinearTension::Value, "None");
cls_FEmTool_LinearTension.def("Hessian", (void (FEmTool_LinearTension::*)(const Standard_Integer, const Standard_Integer, math_Matrix &)) &FEmTool_LinearTension::Hessian, "None", py::arg("Dimension1"), py::arg("Dimension2"), py::arg("H"));
cls_FEmTool_LinearTension.def("Gradient", (void (FEmTool_LinearTension::*)(const Standard_Integer, math_Vector &)) &FEmTool_LinearTension::Gradient, "None", py::arg("Dimension"), py::arg("G"));
cls_FEmTool_LinearTension.def_static("get_type_name_", (const char * (*)()) &FEmTool_LinearTension::get_type_name, "None");
cls_FEmTool_LinearTension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &FEmTool_LinearTension::get_type_descriptor, "None");
cls_FEmTool_LinearTension.def("DynamicType", (const opencascade::handle<Standard_Type> & (FEmTool_LinearTension::*)() const) &FEmTool_LinearTension::DynamicType, "None");

// Enums

}