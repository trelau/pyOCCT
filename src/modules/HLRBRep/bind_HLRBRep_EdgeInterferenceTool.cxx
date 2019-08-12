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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <HLRBRep_Data.hxx>
#include <Standard_TypeDef.hxx>
#include <HLRAlgo_Intersection.hxx>
#include <TopAbs_Orientation.hxx>
#include <gp_Dir.hxx>
#include <HLRAlgo_Interference.hxx>
#include <HLRBRep_EdgeInterferenceTool.hxx>

void bind_HLRBRep_EdgeInterferenceTool(py::module &mod){

py::class_<HLRBRep_EdgeInterferenceTool, std::unique_ptr<HLRBRep_EdgeInterferenceTool, Deleter<HLRBRep_EdgeInterferenceTool>>> cls_HLRBRep_EdgeInterferenceTool(mod, "HLRBRep_EdgeInterferenceTool", "Implements the methods required to instantiates the EdgeInterferenceList from HLRAlgo.");

// Constructors
cls_HLRBRep_EdgeInterferenceTool.def(py::init<const opencascade::handle<HLRBRep_Data> &>(), py::arg("DS"));

// Fields

// Methods
// cls_HLRBRep_EdgeInterferenceTool.def_static("operator new_", (void * (*)(size_t)) &HLRBRep_EdgeInterferenceTool::operator new, "None", py::arg("theSize"));
// cls_HLRBRep_EdgeInterferenceTool.def_static("operator delete_", (void (*)(void *)) &HLRBRep_EdgeInterferenceTool::operator delete, "None", py::arg("theAddress"));
// cls_HLRBRep_EdgeInterferenceTool.def_static("operator new[]_", (void * (*)(size_t)) &HLRBRep_EdgeInterferenceTool::operator new[], "None", py::arg("theSize"));
// cls_HLRBRep_EdgeInterferenceTool.def_static("operator delete[]_", (void (*)(void *)) &HLRBRep_EdgeInterferenceTool::operator delete[], "None", py::arg("theAddress"));
// cls_HLRBRep_EdgeInterferenceTool.def_static("operator new_", (void * (*)(size_t, void *)) &HLRBRep_EdgeInterferenceTool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_HLRBRep_EdgeInterferenceTool.def_static("operator delete_", (void (*)(void *, void *)) &HLRBRep_EdgeInterferenceTool::operator delete, "None", py::arg(""), py::arg(""));
cls_HLRBRep_EdgeInterferenceTool.def("LoadEdge", (void (HLRBRep_EdgeInterferenceTool::*)()) &HLRBRep_EdgeInterferenceTool::LoadEdge, "None");
cls_HLRBRep_EdgeInterferenceTool.def("InitVertices", (void (HLRBRep_EdgeInterferenceTool::*)()) &HLRBRep_EdgeInterferenceTool::InitVertices, "None");
cls_HLRBRep_EdgeInterferenceTool.def("MoreVertices", (Standard_Boolean (HLRBRep_EdgeInterferenceTool::*)() const) &HLRBRep_EdgeInterferenceTool::MoreVertices, "None");
cls_HLRBRep_EdgeInterferenceTool.def("NextVertex", (void (HLRBRep_EdgeInterferenceTool::*)()) &HLRBRep_EdgeInterferenceTool::NextVertex, "None");
cls_HLRBRep_EdgeInterferenceTool.def("CurrentVertex", (const HLRAlgo_Intersection & (HLRBRep_EdgeInterferenceTool::*)() const) &HLRBRep_EdgeInterferenceTool::CurrentVertex, "None");
cls_HLRBRep_EdgeInterferenceTool.def("CurrentOrientation", (TopAbs_Orientation (HLRBRep_EdgeInterferenceTool::*)() const) &HLRBRep_EdgeInterferenceTool::CurrentOrientation, "None");
cls_HLRBRep_EdgeInterferenceTool.def("CurrentParameter", (Standard_Real (HLRBRep_EdgeInterferenceTool::*)() const) &HLRBRep_EdgeInterferenceTool::CurrentParameter, "None");
cls_HLRBRep_EdgeInterferenceTool.def("IsPeriodic", (Standard_Boolean (HLRBRep_EdgeInterferenceTool::*)() const) &HLRBRep_EdgeInterferenceTool::IsPeriodic, "None");
cls_HLRBRep_EdgeInterferenceTool.def("EdgeGeometry", [](HLRBRep_EdgeInterferenceTool &self, const Standard_Real Param, gp_Dir & Tgt, gp_Dir & Nrm, Standard_Real & Curv){ self.EdgeGeometry(Param, Tgt, Nrm, Curv); return Curv; }, "Returns local geometric description of the Edge at parameter <Para>. See method Reset of class EdgeFaceTransition from TopCnx for other arguments.", py::arg("Param"), py::arg("Tgt"), py::arg("Nrm"), py::arg("Curv"));
cls_HLRBRep_EdgeInterferenceTool.def("ParameterOfInterference", (Standard_Real (HLRBRep_EdgeInterferenceTool::*)(const HLRAlgo_Interference &) const) &HLRBRep_EdgeInterferenceTool::ParameterOfInterference, "None", py::arg("I"));
cls_HLRBRep_EdgeInterferenceTool.def("SameInterferences", (Standard_Boolean (HLRBRep_EdgeInterferenceTool::*)(const HLRAlgo_Interference &, const HLRAlgo_Interference &) const) &HLRBRep_EdgeInterferenceTool::SameInterferences, "True if the two interferences are on the same geometric locus.", py::arg("I1"), py::arg("I2"));
cls_HLRBRep_EdgeInterferenceTool.def("SameVertexAndInterference", (Standard_Boolean (HLRBRep_EdgeInterferenceTool::*)(const HLRAlgo_Interference &) const) &HLRBRep_EdgeInterferenceTool::SameVertexAndInterference, "True if the Interference and the current Vertex are on the same geometric locus.", py::arg("I"));
cls_HLRBRep_EdgeInterferenceTool.def("InterferenceBoundaryGeometry", [](HLRBRep_EdgeInterferenceTool &self, const HLRAlgo_Interference & I, gp_Dir & Tang, gp_Dir & Norm, Standard_Real & Curv){ self.InterferenceBoundaryGeometry(I, Tang, Norm, Curv); return Curv; }, "Returns the geometry of the boundary at the interference <I>. See the AddInterference method of the class EdgeFaceTransition from TopCnx for the other arguments.", py::arg("I"), py::arg("Tang"), py::arg("Norm"), py::arg("Curv"));

// Enums

}