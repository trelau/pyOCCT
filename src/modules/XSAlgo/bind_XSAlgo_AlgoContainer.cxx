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
#include <XSAlgo_ToolContainer.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <Message_ProgressIndicator.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <Transfer_TransientProcess.hxx>
#include <Transfer_FinderProcess.hxx>
#include <XSAlgo_AlgoContainer.hxx>
#include <Standard_Type.hxx>

void bind_XSAlgo_AlgoContainer(py::module &mod){

py::class_<XSAlgo_AlgoContainer, opencascade::handle<XSAlgo_AlgoContainer>, Standard_Transient> cls_XSAlgo_AlgoContainer(mod, "XSAlgo_AlgoContainer", "None");

// Constructors
cls_XSAlgo_AlgoContainer.def(py::init<>());

// Fields

// Methods
cls_XSAlgo_AlgoContainer.def("SetToolContainer", (void (XSAlgo_AlgoContainer::*)(const opencascade::handle<XSAlgo_ToolContainer> &)) &XSAlgo_AlgoContainer::SetToolContainer, "Sets ToolContainer", py::arg("TC"));
cls_XSAlgo_AlgoContainer.def("ToolContainer", (opencascade::handle<XSAlgo_ToolContainer> (XSAlgo_AlgoContainer::*)() const) &XSAlgo_AlgoContainer::ToolContainer, "Returns ToolContainer");
cls_XSAlgo_AlgoContainer.def("PrepareForTransfer", (void (XSAlgo_AlgoContainer::*)() const) &XSAlgo_AlgoContainer::PrepareForTransfer, "Performs actions necessary for preparing environment for transfer. Empty in Open version.");
cls_XSAlgo_AlgoContainer.def("ProcessShape", [](XSAlgo_AlgoContainer &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2, const Standard_CString a3, const Standard_CString a4, opencascade::handle<Standard_Transient> & a5) -> TopoDS_Shape { return self.ProcessShape(a0, a1, a2, a3, a4, a5); });
cls_XSAlgo_AlgoContainer.def("ProcessShape", [](XSAlgo_AlgoContainer &self, const TopoDS_Shape & a0, const Standard_Real a1, const Standard_Real a2, const Standard_CString a3, const Standard_CString a4, opencascade::handle<Standard_Transient> & a5, const opencascade::handle<Message_ProgressIndicator> & a6) -> TopoDS_Shape { return self.ProcessShape(a0, a1, a2, a3, a4, a5, a6); });
cls_XSAlgo_AlgoContainer.def("ProcessShape", (TopoDS_Shape (XSAlgo_AlgoContainer::*)(const TopoDS_Shape &, const Standard_Real, const Standard_Real, const Standard_CString, const Standard_CString, opencascade::handle<Standard_Transient> &, const opencascade::handle<Message_ProgressIndicator> &, const Standard_Boolean) const) &XSAlgo_AlgoContainer::ProcessShape, "Does shape processing with specified tolerances and returns resulting shape and associated information in the form of Transient. This information should be later transmitted to MergeTransferInfo in order to be recorded in the translation map", py::arg("shape"), py::arg("Prec"), py::arg("MaxTol"), py::arg("rscfile"), py::arg("seq"), py::arg("info"), py::arg("progress"), py::arg("NonManifold"));
cls_XSAlgo_AlgoContainer.def("CheckPCurve", (Standard_Boolean (XSAlgo_AlgoContainer::*)(const TopoDS_Edge &, const TopoDS_Face &, const Standard_Real, const Standard_Boolean) const) &XSAlgo_AlgoContainer::CheckPCurve, "Checks quality of pcurve of the edge on the given face, and corrects it if necessary.", py::arg("edge"), py::arg("face"), py::arg("preci"), py::arg("isSeam"));
cls_XSAlgo_AlgoContainer.def("MergeTransferInfo", [](XSAlgo_AlgoContainer &self, const opencascade::handle<Transfer_TransientProcess> & a0, const opencascade::handle<Standard_Transient> & a1) -> void { return self.MergeTransferInfo(a0, a1); });
cls_XSAlgo_AlgoContainer.def("MergeTransferInfo", (void (XSAlgo_AlgoContainer::*)(const opencascade::handle<Transfer_TransientProcess> &, const opencascade::handle<Standard_Transient> &, const Standard_Integer) const) &XSAlgo_AlgoContainer::MergeTransferInfo, "None", py::arg("TP"), py::arg("info"), py::arg("startTPitem"));
cls_XSAlgo_AlgoContainer.def("MergeTransferInfo", (void (XSAlgo_AlgoContainer::*)(const opencascade::handle<Transfer_FinderProcess> &, const opencascade::handle<Standard_Transient> &) const) &XSAlgo_AlgoContainer::MergeTransferInfo, "Updates translation map (TP or FP) with information resulting from ShapeProcessing Parameter startTPitem can be used for optimisation, to restrict modifications to entities stored in TP starting from item startTPitem", py::arg("FP"), py::arg("info"));
cls_XSAlgo_AlgoContainer.def_static("get_type_name_", (const char * (*)()) &XSAlgo_AlgoContainer::get_type_name, "None");
cls_XSAlgo_AlgoContainer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &XSAlgo_AlgoContainer::get_type_descriptor, "None");
cls_XSAlgo_AlgoContainer.def("DynamicType", (const opencascade::handle<Standard_Type> & (XSAlgo_AlgoContainer::*)() const) &XSAlgo_AlgoContainer::DynamicType, "None");

// Enums

}