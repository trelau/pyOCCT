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
#include <HLRBRep_InternalAlgo.hxx>
#include <HLRAlgo_Projector.hxx>
#include <HLRTopoBRep_OutLiner.hxx>
#include <Standard_TypeDef.hxx>
#include <HLRBRep_SeqOfShapeBounds.hxx>
#include <HLRBRep_ShapeBounds.hxx>
#include <HLRBRep_Data.hxx>
#include <Standard_Type.hxx>
#include <BRepTopAdaptor_MapOfShapeTool.hxx>

void bind_HLRBRep_InternalAlgo(py::module &mod){

py::class_<HLRBRep_InternalAlgo, opencascade::handle<HLRBRep_InternalAlgo>, Standard_Transient> cls_HLRBRep_InternalAlgo(mod, "HLRBRep_InternalAlgo", "None");

// Constructors
cls_HLRBRep_InternalAlgo.def(py::init<>());
cls_HLRBRep_InternalAlgo.def(py::init<const opencascade::handle<HLRBRep_InternalAlgo> &>(), py::arg("A"));

// Fields

// Methods
cls_HLRBRep_InternalAlgo.def("Projector", (void (HLRBRep_InternalAlgo::*)(const HLRAlgo_Projector &)) &HLRBRep_InternalAlgo::Projector, "set the projector.", py::arg("P"));
cls_HLRBRep_InternalAlgo.def("Projector", (HLRAlgo_Projector & (HLRBRep_InternalAlgo::*)()) &HLRBRep_InternalAlgo::Projector, "set the projector.");
cls_HLRBRep_InternalAlgo.def("Update", (void (HLRBRep_InternalAlgo::*)()) &HLRBRep_InternalAlgo::Update, "update the DataStructure.");
cls_HLRBRep_InternalAlgo.def("Load", [](HLRBRep_InternalAlgo &self, const opencascade::handle<HLRTopoBRep_OutLiner> & a0, const opencascade::handle<Standard_Transient> & a1) -> void { return self.Load(a0, a1); });
cls_HLRBRep_InternalAlgo.def("Load", (void (HLRBRep_InternalAlgo::*)(const opencascade::handle<HLRTopoBRep_OutLiner> &, const opencascade::handle<Standard_Transient> &, const Standard_Integer)) &HLRBRep_InternalAlgo::Load, "add the shape <S>.", py::arg("S"), py::arg("SData"), py::arg("nbIso"));
cls_HLRBRep_InternalAlgo.def("Load", [](HLRBRep_InternalAlgo &self, const opencascade::handle<HLRTopoBRep_OutLiner> & a0) -> void { return self.Load(a0); });
cls_HLRBRep_InternalAlgo.def("Load", (void (HLRBRep_InternalAlgo::*)(const opencascade::handle<HLRTopoBRep_OutLiner> &, const Standard_Integer)) &HLRBRep_InternalAlgo::Load, "add the shape <S>.", py::arg("S"), py::arg("nbIso"));
cls_HLRBRep_InternalAlgo.def("Index", (Standard_Integer (HLRBRep_InternalAlgo::*)(const opencascade::handle<HLRTopoBRep_OutLiner> &) const) &HLRBRep_InternalAlgo::Index, "return the index of the Shape <S> and return 0 if the Shape <S> is not found.", py::arg("S"));
cls_HLRBRep_InternalAlgo.def("Remove", (void (HLRBRep_InternalAlgo::*)(const Standard_Integer)) &HLRBRep_InternalAlgo::Remove, "remove the Shape of Index <I>.", py::arg("I"));
cls_HLRBRep_InternalAlgo.def("ShapeData", (void (HLRBRep_InternalAlgo::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &)) &HLRBRep_InternalAlgo::ShapeData, "Change the Shape Data of the Shape of index <I>.", py::arg("I"), py::arg("SData"));
cls_HLRBRep_InternalAlgo.def("SeqOfShapeBounds", (HLRBRep_SeqOfShapeBounds & (HLRBRep_InternalAlgo::*)()) &HLRBRep_InternalAlgo::SeqOfShapeBounds, "None");
cls_HLRBRep_InternalAlgo.def("NbShapes", (Standard_Integer (HLRBRep_InternalAlgo::*)() const) &HLRBRep_InternalAlgo::NbShapes, "None");
cls_HLRBRep_InternalAlgo.def("ShapeBounds", (HLRBRep_ShapeBounds & (HLRBRep_InternalAlgo::*)(const Standard_Integer)) &HLRBRep_InternalAlgo::ShapeBounds, "None", py::arg("I"));
cls_HLRBRep_InternalAlgo.def("InitEdgeStatus", (void (HLRBRep_InternalAlgo::*)()) &HLRBRep_InternalAlgo::InitEdgeStatus, "init the status of the selected edges depending of the back faces of a closed shell.");
cls_HLRBRep_InternalAlgo.def("Select", (void (HLRBRep_InternalAlgo::*)()) &HLRBRep_InternalAlgo::Select, "select all the DataStructure.");
cls_HLRBRep_InternalAlgo.def("Select", (void (HLRBRep_InternalAlgo::*)(const Standard_Integer)) &HLRBRep_InternalAlgo::Select, "select only the Shape of index <I>.", py::arg("I"));
cls_HLRBRep_InternalAlgo.def("SelectEdge", (void (HLRBRep_InternalAlgo::*)(const Standard_Integer)) &HLRBRep_InternalAlgo::SelectEdge, "select only the edges of the Shape <S>.", py::arg("I"));
cls_HLRBRep_InternalAlgo.def("SelectFace", (void (HLRBRep_InternalAlgo::*)(const Standard_Integer)) &HLRBRep_InternalAlgo::SelectFace, "select only the faces of the Shape <S>.", py::arg("I"));
cls_HLRBRep_InternalAlgo.def("ShowAll", (void (HLRBRep_InternalAlgo::*)()) &HLRBRep_InternalAlgo::ShowAll, "set to visible all the edges.");
cls_HLRBRep_InternalAlgo.def("ShowAll", (void (HLRBRep_InternalAlgo::*)(const Standard_Integer)) &HLRBRep_InternalAlgo::ShowAll, "set to visible all the edges of the Shape <S>.", py::arg("I"));
cls_HLRBRep_InternalAlgo.def("HideAll", (void (HLRBRep_InternalAlgo::*)()) &HLRBRep_InternalAlgo::HideAll, "set to hide all the edges.");
cls_HLRBRep_InternalAlgo.def("HideAll", (void (HLRBRep_InternalAlgo::*)(const Standard_Integer)) &HLRBRep_InternalAlgo::HideAll, "set to hide all the edges of the Shape <S>.", py::arg("I"));
cls_HLRBRep_InternalAlgo.def("PartialHide", (void (HLRBRep_InternalAlgo::*)()) &HLRBRep_InternalAlgo::PartialHide, "own hiding of all the shapes of the DataStructure without hiding by each other.");
cls_HLRBRep_InternalAlgo.def("Hide", (void (HLRBRep_InternalAlgo::*)()) &HLRBRep_InternalAlgo::Hide, "hide all the DataStructure.");
cls_HLRBRep_InternalAlgo.def("Hide", (void (HLRBRep_InternalAlgo::*)(const Standard_Integer)) &HLRBRep_InternalAlgo::Hide, "hide the Shape <S> by itself.", py::arg("I"));
cls_HLRBRep_InternalAlgo.def("Hide", (void (HLRBRep_InternalAlgo::*)(const Standard_Integer, const Standard_Integer)) &HLRBRep_InternalAlgo::Hide, "hide the Shape <S1> by the shape <S2>.", py::arg("I"), py::arg("J"));
cls_HLRBRep_InternalAlgo.def("Debug", (void (HLRBRep_InternalAlgo::*)(const Standard_Boolean)) &HLRBRep_InternalAlgo::Debug, "None", py::arg("deb"));
cls_HLRBRep_InternalAlgo.def("Debug", (Standard_Boolean (HLRBRep_InternalAlgo::*)() const) &HLRBRep_InternalAlgo::Debug, "None");
cls_HLRBRep_InternalAlgo.def("DataStructure", (opencascade::handle<HLRBRep_Data> (HLRBRep_InternalAlgo::*)() const) &HLRBRep_InternalAlgo::DataStructure, "None");
cls_HLRBRep_InternalAlgo.def_static("get_type_name_", (const char * (*)()) &HLRBRep_InternalAlgo::get_type_name, "None");
cls_HLRBRep_InternalAlgo.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRBRep_InternalAlgo::get_type_descriptor, "None");
cls_HLRBRep_InternalAlgo.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRBRep_InternalAlgo::*)() const) &HLRBRep_InternalAlgo::DynamicType, "None");

// Enums

}