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
#include <TColStd_HArray1OfInteger.hxx>
#include <IGESBasic_HArray1OfHArray1OfReal.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <IGESDefs_TabularData.hxx>
#include <Standard_Type.hxx>

void bind_IGESDefs_TabularData(py::module &mod){

py::class_<IGESDefs_TabularData, opencascade::handle<IGESDefs_TabularData>, IGESData_IGESEntity> cls_IGESDefs_TabularData(mod, "IGESDefs_TabularData", "Defines IGES Tabular Data, Type <406> Form <11>, in package IGESDefs This Class is used to provide a Structure to accomodate point form data.");

// Constructors
cls_IGESDefs_TabularData.def(py::init<>());

// Fields

// Methods
cls_IGESDefs_TabularData.def("Init", (void (IGESDefs_TabularData::*)(const Standard_Integer, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<IGESBasic_HArray1OfHArray1OfReal> &, const opencascade::handle<IGESBasic_HArray1OfHArray1OfReal> &)) &IGESDefs_TabularData::Init, "This method is used to set the fields of the class TabularData - nbProps : Number of property values - propType : Property Type - typesInd : Type of independent variables - nbValuesInd : Number of values of independent variables - valuesInd : Values of independent variables - valuesDep : Values of dependent variables raises exception if lengths of typeInd and nbValuesInd are not same", py::arg("nbProps"), py::arg("propType"), py::arg("typesInd"), py::arg("nbValuesInd"), py::arg("valuesInd"), py::arg("valuesDep"));
cls_IGESDefs_TabularData.def("NbPropertyValues", (Standard_Integer (IGESDefs_TabularData::*)() const) &IGESDefs_TabularData::NbPropertyValues, "returns the number of property values (recorded)");
cls_IGESDefs_TabularData.def("ComputedNbPropertyValues", (Standard_Integer (IGESDefs_TabularData::*)() const) &IGESDefs_TabularData::ComputedNbPropertyValues, "determines the number of property values required");
cls_IGESDefs_TabularData.def("OwnCorrect", (Standard_Boolean (IGESDefs_TabularData::*)()) &IGESDefs_TabularData::OwnCorrect, "checks, and correct as necessary, the number of property values. Returns True if corrected, False if already OK");
cls_IGESDefs_TabularData.def("PropertyType", (Standard_Integer (IGESDefs_TabularData::*)() const) &IGESDefs_TabularData::PropertyType, "returns the property type");
cls_IGESDefs_TabularData.def("NbDependents", (Standard_Integer (IGESDefs_TabularData::*)() const) &IGESDefs_TabularData::NbDependents, "returns the number of dependent variables");
cls_IGESDefs_TabularData.def("NbIndependents", (Standard_Integer (IGESDefs_TabularData::*)() const) &IGESDefs_TabularData::NbIndependents, "returns the number of independent variables");
cls_IGESDefs_TabularData.def("TypeOfIndependents", (Standard_Integer (IGESDefs_TabularData::*)(const Standard_Integer) const) &IGESDefs_TabularData::TypeOfIndependents, "returns the type of the num'th independent variable raises exception if num <= 0 or num > NbIndependents()", py::arg("num"));
cls_IGESDefs_TabularData.def("NbValues", (Standard_Integer (IGESDefs_TabularData::*)(const Standard_Integer) const) &IGESDefs_TabularData::NbValues, "returns the number of different values of the num'th indep. variable raises exception if num <= 0 or num > NbIndependents()", py::arg("num"));
cls_IGESDefs_TabularData.def("IndependentValue", (Standard_Real (IGESDefs_TabularData::*)(const Standard_Integer, const Standard_Integer) const) &IGESDefs_TabularData::IndependentValue, "None", py::arg("variablenum"), py::arg("valuenum"));
cls_IGESDefs_TabularData.def("DependentValues", (opencascade::handle<TColStd_HArray1OfReal> (IGESDefs_TabularData::*)(const Standard_Integer) const) &IGESDefs_TabularData::DependentValues, "None", py::arg("num"));
cls_IGESDefs_TabularData.def("DependentValue", (Standard_Real (IGESDefs_TabularData::*)(const Standard_Integer, const Standard_Integer) const) &IGESDefs_TabularData::DependentValue, "None", py::arg("variablenum"), py::arg("valuenum"));
cls_IGESDefs_TabularData.def_static("get_type_name_", (const char * (*)()) &IGESDefs_TabularData::get_type_name, "None");
cls_IGESDefs_TabularData.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESDefs_TabularData::get_type_descriptor, "None");
cls_IGESDefs_TabularData.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESDefs_TabularData::*)() const) &IGESDefs_TabularData::DynamicType, "None");

// Enums

}