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
#include <ChFiDS_Spine.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <gp_XY.hxx>
#include <Standard_Handle.hxx>
#include <Law_Function.hxx>
#include <ChFiDS_HElSpine.hxx>
#include <Law_Composite.hxx>
#include <ChFiDS_FilSpine.hxx>
#include <Standard_Type.hxx>
#include <TColgp_SequenceOfXY.hxx>
#include <Law_Laws.hxx>

void bind_ChFiDS_FilSpine(py::module &mod){

py::class_<ChFiDS_FilSpine, opencascade::handle<ChFiDS_FilSpine>, ChFiDS_Spine> cls_ChFiDS_FilSpine(mod, "ChFiDS_FilSpine", "Provides data specific to the fillets - vector or rule of evolution (C2).");

// Constructors
cls_ChFiDS_FilSpine.def(py::init<>());
cls_ChFiDS_FilSpine.def(py::init<const Standard_Real>(), py::arg("Tol"));

// Fields

// Methods
cls_ChFiDS_FilSpine.def("Reset", [](ChFiDS_FilSpine &self) -> void { return self.Reset(); });
cls_ChFiDS_FilSpine.def("Reset", (void (ChFiDS_FilSpine::*)(const Standard_Boolean)) &ChFiDS_FilSpine::Reset, "None", py::arg("AllData"));
cls_ChFiDS_FilSpine.def("SetRadius", (void (ChFiDS_FilSpine::*)(const Standard_Real, const TopoDS_Edge &)) &ChFiDS_FilSpine::SetRadius, "initializes the constant vector on edge E.", py::arg("Radius"), py::arg("E"));
cls_ChFiDS_FilSpine.def("UnSetRadius", (void (ChFiDS_FilSpine::*)(const TopoDS_Edge &)) &ChFiDS_FilSpine::UnSetRadius, "resets the constant vector on edge E.", py::arg("E"));
cls_ChFiDS_FilSpine.def("SetRadius", (void (ChFiDS_FilSpine::*)(const Standard_Real, const TopoDS_Vertex &)) &ChFiDS_FilSpine::SetRadius, "initializes the vector on Vertex V.", py::arg("Radius"), py::arg("V"));
cls_ChFiDS_FilSpine.def("UnSetRadius", (void (ChFiDS_FilSpine::*)(const TopoDS_Vertex &)) &ChFiDS_FilSpine::UnSetRadius, "resets the vector on Vertex V.", py::arg("V"));
cls_ChFiDS_FilSpine.def("SetRadius", (void (ChFiDS_FilSpine::*)(const gp_XY &, const Standard_Integer)) &ChFiDS_FilSpine::SetRadius, "initializes the vector on the point of parameter W.", py::arg("UandR"), py::arg("IinC"));
cls_ChFiDS_FilSpine.def("SetRadius", (void (ChFiDS_FilSpine::*)(const Standard_Real)) &ChFiDS_FilSpine::SetRadius, "initializes the constant vector on all spine.", py::arg("Radius"));
cls_ChFiDS_FilSpine.def("SetRadius", (void (ChFiDS_FilSpine::*)(const opencascade::handle<Law_Function> &, const Standard_Integer)) &ChFiDS_FilSpine::SetRadius, "initializes the rule of evolution on all spine.", py::arg("C"), py::arg("IinC"));
cls_ChFiDS_FilSpine.def("IsConstant", (Standard_Boolean (ChFiDS_FilSpine::*)() const) &ChFiDS_FilSpine::IsConstant, "returns true if the radius is constant all along the spine.");
cls_ChFiDS_FilSpine.def("IsConstant", (Standard_Boolean (ChFiDS_FilSpine::*)(const Standard_Integer) const) &ChFiDS_FilSpine::IsConstant, "returns true if the radius is constant all along the edge E.", py::arg("IE"));
cls_ChFiDS_FilSpine.def("Radius", (Standard_Real (ChFiDS_FilSpine::*)() const) &ChFiDS_FilSpine::Radius, "returns the radius if the fillet is constant all along the spine.");
cls_ChFiDS_FilSpine.def("Radius", (Standard_Real (ChFiDS_FilSpine::*)(const Standard_Integer) const) &ChFiDS_FilSpine::Radius, "returns the radius if the fillet is constant all along the edge E.", py::arg("IE"));
cls_ChFiDS_FilSpine.def("Radius", (Standard_Real (ChFiDS_FilSpine::*)(const TopoDS_Edge &) const) &ChFiDS_FilSpine::Radius, "returns the radius if the fillet is constant all along the edge E.", py::arg("E"));
cls_ChFiDS_FilSpine.def("AppendElSpine", (void (ChFiDS_FilSpine::*)(const opencascade::handle<ChFiDS_HElSpine> &)) &ChFiDS_FilSpine::AppendElSpine, "None", py::arg("Els"));
cls_ChFiDS_FilSpine.def("Law", (opencascade::handle<Law_Composite> (ChFiDS_FilSpine::*)(const opencascade::handle<ChFiDS_HElSpine> &) const) &ChFiDS_FilSpine::Law, "None", py::arg("Els"));
cls_ChFiDS_FilSpine.def("ChangeLaw", (opencascade::handle<Law_Function> & (ChFiDS_FilSpine::*)(const TopoDS_Edge &)) &ChFiDS_FilSpine::ChangeLaw, "returns the elementary law", py::arg("E"));
cls_ChFiDS_FilSpine.def("MaxRadFromSeqAndLaws", (Standard_Real (ChFiDS_FilSpine::*)() const) &ChFiDS_FilSpine::MaxRadFromSeqAndLaws, "returns the maximum radius if the fillet is non-constant");
cls_ChFiDS_FilSpine.def_static("get_type_name_", (const char * (*)()) &ChFiDS_FilSpine::get_type_name, "None");
cls_ChFiDS_FilSpine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ChFiDS_FilSpine::get_type_descriptor, "None");
cls_ChFiDS_FilSpine.def("DynamicType", (const opencascade::handle<Standard_Type> & (ChFiDS_FilSpine::*)() const) &ChFiDS_FilSpine::DynamicType, "None");

// Enums

}