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
#include <TopoDS_Shape.hxx>
#include <HLRTopoBRep_Data.hxx>
#include <HLRAlgo_Projector.hxx>
#include <BRepTopAdaptor_MapOfShapeTool.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <HLRTopoBRep_OutLiner.hxx>
#include <Standard_Type.hxx>
#include <TopoDS_Face.hxx>

void bind_HLRTopoBRep_OutLiner(py::module &mod){

py::class_<HLRTopoBRep_OutLiner, opencascade::handle<HLRTopoBRep_OutLiner>, Standard_Transient> cls_HLRTopoBRep_OutLiner(mod, "HLRTopoBRep_OutLiner", "None");

// Constructors
cls_HLRTopoBRep_OutLiner.def(py::init<>());
cls_HLRTopoBRep_OutLiner.def(py::init<const TopoDS_Shape &>(), py::arg("OriSh"));
cls_HLRTopoBRep_OutLiner.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("OriS"), py::arg("OutS"));

// Fields

// Methods
cls_HLRTopoBRep_OutLiner.def("OriginalShape", (void (HLRTopoBRep_OutLiner::*)(const TopoDS_Shape &)) &HLRTopoBRep_OutLiner::OriginalShape, "None", py::arg("OriS"));
cls_HLRTopoBRep_OutLiner.def("OriginalShape", (TopoDS_Shape & (HLRTopoBRep_OutLiner::*)()) &HLRTopoBRep_OutLiner::OriginalShape, "None");
cls_HLRTopoBRep_OutLiner.def("OutLinedShape", (void (HLRTopoBRep_OutLiner::*)(const TopoDS_Shape &)) &HLRTopoBRep_OutLiner::OutLinedShape, "None", py::arg("OutS"));
cls_HLRTopoBRep_OutLiner.def("OutLinedShape", (TopoDS_Shape & (HLRTopoBRep_OutLiner::*)()) &HLRTopoBRep_OutLiner::OutLinedShape, "None");
cls_HLRTopoBRep_OutLiner.def("DataStructure", (HLRTopoBRep_Data & (HLRTopoBRep_OutLiner::*)()) &HLRTopoBRep_OutLiner::DataStructure, "None");
cls_HLRTopoBRep_OutLiner.def("Fill", (void (HLRTopoBRep_OutLiner::*)(const HLRAlgo_Projector &, BRepTopAdaptor_MapOfShapeTool &, const Standard_Integer)) &HLRTopoBRep_OutLiner::Fill, "None", py::arg("P"), py::arg("MST"), py::arg("nbIso"));
cls_HLRTopoBRep_OutLiner.def_static("get_type_name_", (const char * (*)()) &HLRTopoBRep_OutLiner::get_type_name, "None");
cls_HLRTopoBRep_OutLiner.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRTopoBRep_OutLiner::get_type_descriptor, "None");
cls_HLRTopoBRep_OutLiner.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRTopoBRep_OutLiner::*)() const) &HLRTopoBRep_OutLiner::DynamicType, "None");

// Enums

}