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
#include <IGESDimen_HArray1OfGeneralNote.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <IGESAppli_HArray1OfNode.hxx>
#include <IGESBasic_HArray1OfHArray1OfXYZ.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESDimen_GeneralNote.hxx>
#include <IGESAppli_Node.hxx>
#include <gp_XYZ.hxx>
#include <IGESAppli_NodalDisplAndRot.hxx>
#include <Standard_Type.hxx>

void bind_IGESAppli_NodalDisplAndRot(py::module &mod){

py::class_<IGESAppli_NodalDisplAndRot, opencascade::handle<IGESAppli_NodalDisplAndRot>, IGESData_IGESEntity> cls_IGESAppli_NodalDisplAndRot(mod, "IGESAppli_NodalDisplAndRot", "defines NodalDisplAndRot, Type <138> Form <0> in package IGESAppli Used to communicate finite element post processing data.");

// Constructors
cls_IGESAppli_NodalDisplAndRot.def(py::init<>());

// Fields

// Methods
cls_IGESAppli_NodalDisplAndRot.def("Init", (void (IGESAppli_NodalDisplAndRot::*)(const opencascade::handle<IGESDimen_HArray1OfGeneralNote> &, const opencascade::handle<TColStd_HArray1OfInteger> &, const opencascade::handle<IGESAppli_HArray1OfNode> &, const opencascade::handle<IGESBasic_HArray1OfHArray1OfXYZ> &, const opencascade::handle<IGESBasic_HArray1OfHArray1OfXYZ> &)) &IGESAppli_NodalDisplAndRot::Init, "This method is used to set the fields of the class NodalDisplAndRot - allNotes : Used to store the general note describing the analysis cases - allIdentifiers : Used to store the node number identifier for the nodes - allNodes : Used to store the nodes - allRotParams : Used to store the rotation for the nodes - allTransParams : Used to store the incremental displacements for the nodes raises exception if Lengths of allIdentifiers, allNodes, allRotParams, and allTransParams are not same or if length of allNotes and size of each element of allRotParams and allTransParam are not same", py::arg("allNotes"), py::arg("allIdentifiers"), py::arg("allNodes"), py::arg("allRotParams"), py::arg("allTransParams"));
cls_IGESAppli_NodalDisplAndRot.def("NbCases", (Standard_Integer (IGESAppli_NodalDisplAndRot::*)() const) &IGESAppli_NodalDisplAndRot::NbCases, "returns the number of analysis cases");
cls_IGESAppli_NodalDisplAndRot.def("NbNodes", (Standard_Integer (IGESAppli_NodalDisplAndRot::*)() const) &IGESAppli_NodalDisplAndRot::NbNodes, "returns the number of nodes");
cls_IGESAppli_NodalDisplAndRot.def("Note", (opencascade::handle<IGESDimen_GeneralNote> (IGESAppli_NodalDisplAndRot::*)(const Standard_Integer) const) &IGESAppli_NodalDisplAndRot::Note, "returns the General Note that describes the Index analysis case raises exception if Index <= 0 or Index > NbCases", py::arg("Index"));
cls_IGESAppli_NodalDisplAndRot.def("NodeIdentifier", (Standard_Integer (IGESAppli_NodalDisplAndRot::*)(const Standard_Integer) const) &IGESAppli_NodalDisplAndRot::NodeIdentifier, "returns the node identifier as specified by the Index raises exception if Index <= 0 or Index > NbNodes", py::arg("Index"));
cls_IGESAppli_NodalDisplAndRot.def("Node", (opencascade::handle<IGESAppli_Node> (IGESAppli_NodalDisplAndRot::*)(const Standard_Integer) const) &IGESAppli_NodalDisplAndRot::Node, "returns the node as specified by the Index raises exception if Index <= 0 or Index > NbNodes", py::arg("Index"));
cls_IGESAppli_NodalDisplAndRot.def("TranslationParameter", (gp_XYZ (IGESAppli_NodalDisplAndRot::*)(const Standard_Integer, const Standard_Integer) const) &IGESAppli_NodalDisplAndRot::TranslationParameter, "returns the Translational Parameters for the particular Index Exception raised if NodeNum <= 0 or NodeNum > NbNodes() or CaseNum <= 0 or CaseNum > NbCases()", py::arg("NodeNum"), py::arg("CaseNum"));
cls_IGESAppli_NodalDisplAndRot.def("RotationalParameter", (gp_XYZ (IGESAppli_NodalDisplAndRot::*)(const Standard_Integer, const Standard_Integer) const) &IGESAppli_NodalDisplAndRot::RotationalParameter, "returns the Rotational Parameters for Index Exception raised if NodeNum <= 0 or NodeNum > NbNodes() or CaseNum <= 0 or CaseNum > NbCases()", py::arg("NodeNum"), py::arg("CaseNum"));
cls_IGESAppli_NodalDisplAndRot.def_static("get_type_name_", (const char * (*)()) &IGESAppli_NodalDisplAndRot::get_type_name, "None");
cls_IGESAppli_NodalDisplAndRot.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IGESAppli_NodalDisplAndRot::get_type_descriptor, "None");
cls_IGESAppli_NodalDisplAndRot.def("DynamicType", (const opencascade::handle<Standard_Type> & (IGESAppli_NodalDisplAndRot::*)() const) &IGESAppli_NodalDisplAndRot::DynamicType, "None");

// Enums

}