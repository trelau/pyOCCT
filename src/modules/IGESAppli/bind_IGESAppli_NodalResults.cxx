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
#include <IGESAppli_HArray1OfNode.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <IGESAppli_Node.hxx>
#include <IGESAppli_NodalResults.hxx>
#include <Standard_Type.hxx>

void bind_IGESAppli_NodalResults(py::module &mod){

py::class_<IGESAppli_NodalResults, opencascade::handle<IGESAppli_NodalResults>, IGESData_IGESEntity> cls_IGESAppli_NodalResults(mod, "IGESAppli_NodalResults", "defines NodalResults, Type <146> in package IGESAppli Used to store the Analysis Data results per FEM Node");

// Constructors
cls_IGESAppli_NodalResults.def(py::init<>());

// Fields

// Methods
cls_IGESAppli_NodalResults.def("Init", (void (IGESAppli_NodalResults::*)(const opencascade::handle<IGESDimen_GeneralNote> &, const Standard_Integer, const Standard_Real, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<IGESAppli_HArray1OfNode> &, const opencascade::handle<TColStd_HArray2OfReal> &)) &IGESAppli_NodalResults::Init, "This method is used to set the fields of the class NodalResults - aNote : General Note that describes the analysis case - aNumber : Analysis Subcase number - aTime : Analysis time - allNodeIdentifiers : Node identifiers for the nodes - allNodes : List of FEM Node Entities - allData : Values of the Finite Element analysis result data raises exception if Lengths of allNodeIdentifiers, allNodes and allData (Cols) are not same", py::arg("aNote"), py::arg("aNumber"), py::arg("aTime"), py::arg("allNodeIdentifiers"), py::arg("allNodes"), py::arg("allData"));
cls_IGESAppli_NodalResults.def("SetFormNumber", (void (IGESAppli_NodalResults::*)(const Standard_Integer)) &IGESAppli_NodalResults::SetFormNumber, "Changes the FormNumber (which indicates Type of Result) Error if not in range [0-34]", py::arg("form"));
cls_IGESAppli_NodalResults.def("Note", (opencascade::handle<IGESDimen_GeneralNote> (IGESAppli_NodalResults::*)() const) &IGESAppli_NodalResults::Note, "returns the General Note Entity that describes the analysis case");
cls_IGESAppli_NodalResults.def("SubCaseNumber", (Standard_Integer (IGESAppli_NodalResults::*)() const) &IGESAppli_NodalResults::SubCaseNumber, "returns zero if there is no subcase");
cls_IGESAppli_NodalResults.def("Time", (Standard_Real (IGESAppli_NodalResults::*)() const) &IGESAppli_NodalResults::Time, "returns the Analysis time value for this subcase. It is the time at which transient analysis results occur in the mathematical FEM model.");
cls_IGESAppli_NodalResults.def("NbData", (Standard_Integer (IGESAppli_NodalResults::*)() const) &IGESAppli_NodalResults::NbData, "returns number of real values in array V for a FEM node");
cls_IGESAppli_NodalResults.def("NbNodes", (Standard_Integer (IGESAppli_NodalResults::*)() const) &IGESAppli_NodalResults::NbNodes, "returns number of FEM nodes for which data is to be read.");
cls_IGESAppli_NodalResults.def("NodeIdentifier", (Standard_Integer (IGESAppli_NodalResults::*)(const Standard_Integer) const) &IGESAppli_NodalResults::NodeIdentifier, "returns FEM node number identifier for the (Index)th node raises exception if Index <= 0 or Index > NbNodes", py::arg("Index"));
cls_IGESAppli_NodalResults.def("Node", (opencascade::handle<IGESAppli_Node> (IGESAppli_NodalResults::*)(const Standard_Integer) const) &IGESAppli_NodalResults::Node, "returns the node as specified by the Index raises exception if Index <= 0 or Index > NbNodes", py::arg("Index"));
cls_IGESAppli_NodalResults.def("Data", (Standard_Real (IGESAppli_NodalResults::*)(const Standard_Integer, const Standard_Integer) const) &IGESAppli_NodalResults::Data, "returns the finite element analysis result value raises exception if (NodeNum <= 0 or NodeNum > NbNodes()) or if (DataNum <=0 or DataNum > NbData())", py::arg("NodeNum"), py::arg("DataNum"));
cls_IGESAppli_NodalResults.def_static("get_type_name_", (const char * (*)()) &IGESAppli_NodalResults::get_type_name, "None");
cls_IGESAppli_NodalResults.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESAppli_NodalResults::get_type_descriptor, "None");
cls_IGESAppli_NodalResults.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESAppli_NodalResults::*)() const) &IGESAppli_NodalResults::DynamicType, "None");

// Enums

}