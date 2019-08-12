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
#include <IGESData_IGESEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_HArray1OfIGESEntity.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <IGESBasic_HArray1OfHArray1OfIGESEntity.hxx>
#include <IGESGeom_Boundary.hxx>
#include <Standard_Type.hxx>

void bind_IGESGeom_Boundary(py::module &mod){

py::class_<IGESGeom_Boundary, opencascade::handle<IGESGeom_Boundary>, IGESData_IGESEntity> cls_IGESGeom_Boundary(mod, "IGESGeom_Boundary", "defines IGESBoundary, Type <141> Form <0> in package IGESGeom A boundary entity identifies a surface boundary consisting of a set of curves lying on the surface");

// Constructors
cls_IGESGeom_Boundary.def(py::init<>());

// Fields

// Methods
cls_IGESGeom_Boundary.def("Init", (void (IGESGeom_Boundary::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<IGESData_IGESEntity> &, const opencascade::handle<IGESData_HArray1OfIGESEntity> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<IGESBasic_HArray1OfHArray1OfIGESEntity> &)) &IGESGeom_Boundary::Init, "This method is used to set the fields of the class Boundary - aType : Type of bounded surface representation - aPreference : Preferred representation of Trimming Curve - aSurface : Untrimmed surface to be bounded - allModelCurves : Model Space Curves - allSenses : Orientation flags of all Model Space Curves - allParameterCurves : Parameter Space Curves raises exception if allSenses, allModelCurves and allParameterCurves do not have same dimensions", py::arg("aType"), py::arg("aPreference"), py::arg("aSurface"), py::arg("allModelCurves"), py::arg("allSenses"), py::arg("allParameterCurves"));
cls_IGESGeom_Boundary.def("BoundaryType", (Standard_Integer (IGESGeom_Boundary::*)() const) &IGESGeom_Boundary::BoundaryType, "returns type of bounded surface representation 0 = Boundary entities may only reference model space trimming curves. Associated surface representation may be parametric 1 = Boundary entities must reference model space curves and associated parameter space curve collections. Associated surface must be a parametric representation");
cls_IGESGeom_Boundary.def("PreferenceType", (Standard_Integer (IGESGeom_Boundary::*)() const) &IGESGeom_Boundary::PreferenceType, "returns preferred representation of trimming curves 0 = Unspecified 1 = Model space 2 = Parameter space 3 = Representations are of equal preference");
cls_IGESGeom_Boundary.def("Surface", (opencascade::handle<IGESData_IGESEntity> (IGESGeom_Boundary::*)() const) &IGESGeom_Boundary::Surface, "returns the surface to be bounded");
cls_IGESGeom_Boundary.def("NbModelSpaceCurves", (Standard_Integer (IGESGeom_Boundary::*)() const) &IGESGeom_Boundary::NbModelSpaceCurves, "returns the number of model space curves");
cls_IGESGeom_Boundary.def("ModelSpaceCurve", (opencascade::handle<IGESData_IGESEntity> (IGESGeom_Boundary::*)(const Standard_Integer) const) &IGESGeom_Boundary::ModelSpaceCurve, "returns Model Space Curve raises exception if Index <= 0 or Index > NbModelSpaceCurves()", py::arg("Index"));
cls_IGESGeom_Boundary.def("Sense", (Standard_Integer (IGESGeom_Boundary::*)(const Standard_Integer) const) &IGESGeom_Boundary::Sense, "returns the sense of a particular model space curve 1 = model curve direction does not need reversal 2 = model curve direction needs to be reversed raises exception if Index <= 0 or Index > NbModelSpaceCurves()", py::arg("Index"));
cls_IGESGeom_Boundary.def("NbParameterCurves", (Standard_Integer (IGESGeom_Boundary::*)(const Standard_Integer) const) &IGESGeom_Boundary::NbParameterCurves, "returns the number of parameter curves associated with one model space curve referred to by Index raises exception if Index <= 0 or Index > NbModelSpaceCurves()", py::arg("Index"));
cls_IGESGeom_Boundary.def("ParameterCurves", (opencascade::handle<IGESData_HArray1OfIGESEntity> (IGESGeom_Boundary::*)(const Standard_Integer) const) &IGESGeom_Boundary::ParameterCurves, "returns an array of parameter space curves associated with a model space curve referred to by the Index raises exception if Index <= 0 or Index > NbModelSpaceCurves()", py::arg("Index"));
cls_IGESGeom_Boundary.def("ParameterCurve", (opencascade::handle<IGESData_IGESEntity> (IGESGeom_Boundary::*)(const Standard_Integer, const Standard_Integer) const) &IGESGeom_Boundary::ParameterCurve, "returns an individual parameter curve raises exception if Index or Num is out of range", py::arg("Index"), py::arg("Num"));
cls_IGESGeom_Boundary.def_static("get_type_name_", (const char * (*)()) &IGESGeom_Boundary::get_type_name, "None");
cls_IGESGeom_Boundary.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESGeom_Boundary::get_type_descriptor, "None");
cls_IGESGeom_Boundary.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESGeom_Boundary::*)() const) &IGESGeom_Boundary::DynamicType, "None");

// Enums

}