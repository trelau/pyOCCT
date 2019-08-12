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
#include <Standard_Handle.hxx>
#include <IGESDimen_GeneralNote.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <IGESAppli_HArray1OfFiniteElement.hxx>
#include <IGESBasic_HArray1OfHArray1OfInteger.hxx>
#include <IGESBasic_HArray1OfHArray1OfReal.hxx>
#include <IGESAppli_FiniteElement.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <IGESAppli_ElementResults.hxx>
#include <Standard_Type.hxx>

void bind_IGESAppli_ElementResults(py::module &mod){

py::class_<IGESAppli_ElementResults, opencascade::handle<IGESAppli_ElementResults>, IGESData_IGESEntity> cls_IGESAppli_ElementResults(mod, "IGESAppli_ElementResults", "defines ElementResults, Type <148> in package IGESAppli Used to find the results of FEM analysis");

// Constructors
cls_IGESAppli_ElementResults.def(py::init<>());

// Fields

// Methods
cls_IGESAppli_ElementResults.def("Init", (void (IGESAppli_ElementResults::*)(const opencascade::handle<IGESDimen_GeneralNote> &, const Standard_Integer, const Standard_Real, const Standard_Integer, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<IGESAppli_HArray1OfFiniteElement> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<IGESBasic_HArray1OfHArray1OfInteger> &, const opencascade::handle<IGESBasic_HArray1OfHArray1OfReal> &)) &IGESAppli_ElementResults::Init, "This method is used to set the fields of the class ElementResults - aNote : GeneralNote Entity describing analysis - aSubCase : Analysis Subcase number - aTime : Analysis time value - nbResults : Number of result values per FEM - aResRepFlag : Results Reporting Flag - allElementIdents : FEM element number for elements - allFiniteElems : FEM element - allTopTypes : Element Topology Types - nbLayers : Number of layers per result data location - allDataLayerFlags : Data Layer Flags - allnbResDataLocs : Number of result data report locations - allResDataLocs : Result Data Report Locations - allResults : List of Result data values of FEM analysis", py::arg("aNote"), py::arg("aSubCase"), py::arg("aTime"), py::arg("nbResults"), py::arg("aResRepFlag"), py::arg("allElementIdents"), py::arg("allFiniteElems"), py::arg("allTopTypes"), py::arg("nbLayers"), py::arg("allDataLayerFlags"), py::arg("allnbResDataLocs"), py::arg("allResDataLocs"), py::arg("allResults"));
cls_IGESAppli_ElementResults.def("SetFormNumber", (void (IGESAppli_ElementResults::*)(const Standard_Integer)) &IGESAppli_ElementResults::SetFormNumber, "Changes the FormNumber (which indicates Type of Result) Error if not in range [0-34]", py::arg("form"));
cls_IGESAppli_ElementResults.def("Note", (opencascade::handle<IGESDimen_GeneralNote> (IGESAppli_ElementResults::*)() const) &IGESAppli_ElementResults::Note, "returns General Note Entity describing analysis case");
cls_IGESAppli_ElementResults.def("SubCaseNumber", (Standard_Integer (IGESAppli_ElementResults::*)() const) &IGESAppli_ElementResults::SubCaseNumber, "returns analysis Subcase number");
cls_IGESAppli_ElementResults.def("Time", (Standard_Real (IGESAppli_ElementResults::*)() const) &IGESAppli_ElementResults::Time, "returns analysis time value");
cls_IGESAppli_ElementResults.def("NbResultValues", (Standard_Integer (IGESAppli_ElementResults::*)() const) &IGESAppli_ElementResults::NbResultValues, "returns number of result values per FEM");
cls_IGESAppli_ElementResults.def("ResultReportFlag", (Standard_Integer (IGESAppli_ElementResults::*)() const) &IGESAppli_ElementResults::ResultReportFlag, "returns Results Reporting Flag");
cls_IGESAppli_ElementResults.def("NbElements", (Standard_Integer (IGESAppli_ElementResults::*)() const) &IGESAppli_ElementResults::NbElements, "returns number of FEM elements");
cls_IGESAppli_ElementResults.def("ElementIdentifier", (Standard_Integer (IGESAppli_ElementResults::*)(const Standard_Integer) const) &IGESAppli_ElementResults::ElementIdentifier, "returns FEM element number for elements", py::arg("Index"));
cls_IGESAppli_ElementResults.def("Element", (opencascade::handle<IGESAppli_FiniteElement> (IGESAppli_ElementResults::*)(const Standard_Integer) const) &IGESAppli_ElementResults::Element, "returns FEM element", py::arg("Index"));
cls_IGESAppli_ElementResults.def("ElementTopologyType", (Standard_Integer (IGESAppli_ElementResults::*)(const Standard_Integer) const) &IGESAppli_ElementResults::ElementTopologyType, "returns element Topology Types", py::arg("Index"));
cls_IGESAppli_ElementResults.def("NbLayers", (Standard_Integer (IGESAppli_ElementResults::*)(const Standard_Integer) const) &IGESAppli_ElementResults::NbLayers, "returns number of layers per result data location", py::arg("Index"));
cls_IGESAppli_ElementResults.def("DataLayerFlag", (Standard_Integer (IGESAppli_ElementResults::*)(const Standard_Integer) const) &IGESAppli_ElementResults::DataLayerFlag, "returns Data Layer Flags", py::arg("Index"));
cls_IGESAppli_ElementResults.def("NbResultDataLocs", (Standard_Integer (IGESAppli_ElementResults::*)(const Standard_Integer) const) &IGESAppli_ElementResults::NbResultDataLocs, "returns number of result data report locations", py::arg("Index"));
cls_IGESAppli_ElementResults.def("ResultDataLoc", (Standard_Integer (IGESAppli_ElementResults::*)(const Standard_Integer, const Standard_Integer) const) &IGESAppli_ElementResults::ResultDataLoc, "returns Result Data Report Locations UNFINISHED", py::arg("NElem"), py::arg("NLoc"));
cls_IGESAppli_ElementResults.def("NbResults", (Standard_Integer (IGESAppli_ElementResults::*)(const Standard_Integer) const) &IGESAppli_ElementResults::NbResults, "returns total number of results", py::arg("Index"));
cls_IGESAppli_ElementResults.def("ResultData", (Standard_Real (IGESAppli_ElementResults::*)(const Standard_Integer, const Standard_Integer) const) &IGESAppli_ElementResults::ResultData, "returns Result data value for an Element, given its order between 1 and <NbResults(NElem)> (direct access) For a more comprehensive access, see below", py::arg("NElem"), py::arg("num"));
cls_IGESAppli_ElementResults.def("ResultRank", (Standard_Integer (IGESAppli_ElementResults::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer) const) &IGESAppli_ElementResults::ResultRank, "Computes, for a given Element <NElem>, the rank of a individual Result Data, given <NVal>,<NLay>,<NLoc>", py::arg("NElem"), py::arg("NVal"), py::arg("NLay"), py::arg("NLoc"));
cls_IGESAppli_ElementResults.def("ResultData", (Standard_Real (IGESAppli_ElementResults::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer) const) &IGESAppli_ElementResults::ResultData, "returns Result data values of FEM analysis, according this definition : - <NElem> : n0 of the Element to be considered - <NVal> : n0 of the Value between 1 and NbResultValues - <NLay> : n0 of the Layer for this Element - <NLoc> : n0 of the Data Location for this Element This gives for each Element, the corresponding rank computed by ResultRank, in which the leftmost subscript changes most rapidly", py::arg("NElem"), py::arg("NVal"), py::arg("NLay"), py::arg("NLoc"));
cls_IGESAppli_ElementResults.def("ResultList", (opencascade::handle<TColStd_HArray1OfReal> (IGESAppli_ElementResults::*)(const Standard_Integer) const) &IGESAppli_ElementResults::ResultList, "Returns in once the entire list of data for an Element, addressed as by ResultRank (See above)", py::arg("NElem"));
cls_IGESAppli_ElementResults.def_static("get_type_name_", (const char * (*)()) &IGESAppli_ElementResults::get_type_name, "None");
cls_IGESAppli_ElementResults.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESAppli_ElementResults::get_type_descriptor, "None");
cls_IGESAppli_ElementResults.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESAppli_ElementResults::*)() const) &IGESAppli_ElementResults::DynamicType, "None");

// Enums

}