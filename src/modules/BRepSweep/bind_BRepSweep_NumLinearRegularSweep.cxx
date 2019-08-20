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
#include <TopoDS_Shape.hxx>
#include <Sweep_NumShape.hxx>
#include <TopAbs_Orientation.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepSweep_Builder.hxx>
#include <BRepSweep_Tool.hxx>
#include <Sweep_NumShapeTool.hxx>
#include <TopTools_Array2OfShape.hxx>
#include <TColStd_Array2OfBoolean.hxx>
#include <BRepSweep_NumLinearRegularSweep.hxx>

void bind_BRepSweep_NumLinearRegularSweep(py::module &mod){

py::class_<BRepSweep_NumLinearRegularSweep, std::unique_ptr<BRepSweep_NumLinearRegularSweep>> cls_BRepSweep_NumLinearRegularSweep(mod, "BRepSweep_NumLinearRegularSweep", "This a generic class is used to build Sweept primitives with a generating 'shape' and a directing 'line'.");

// Fields

// Methods
// cls_BRepSweep_NumLinearRegularSweep.def_static("operator new_", (void * (*)(size_t)) &BRepSweep_NumLinearRegularSweep::operator new, "None", py::arg("theSize"));
// cls_BRepSweep_NumLinearRegularSweep.def_static("operator delete_", (void (*)(void *)) &BRepSweep_NumLinearRegularSweep::operator delete, "None", py::arg("theAddress"));
// cls_BRepSweep_NumLinearRegularSweep.def_static("operator new[]_", (void * (*)(size_t)) &BRepSweep_NumLinearRegularSweep::operator new[], "None", py::arg("theSize"));
// cls_BRepSweep_NumLinearRegularSweep.def_static("operator delete[]_", (void (*)(void *)) &BRepSweep_NumLinearRegularSweep::operator delete[], "None", py::arg("theAddress"));
// cls_BRepSweep_NumLinearRegularSweep.def_static("operator new_", (void * (*)(size_t, void *)) &BRepSweep_NumLinearRegularSweep::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepSweep_NumLinearRegularSweep.def_static("operator delete_", (void (*)(void *, void *)) &BRepSweep_NumLinearRegularSweep::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepSweep_NumLinearRegularSweep.def("MakeEmptyVertex", (TopoDS_Shape (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_NumLinearRegularSweep::MakeEmptyVertex, "Builds the vertex addressed by [aGenV,aDirV], with its geometric part, but without subcomponents.", py::arg("aGenV"), py::arg("aDirV"));
cls_BRepSweep_NumLinearRegularSweep.def("MakeEmptyDirectingEdge", (TopoDS_Shape (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_NumLinearRegularSweep::MakeEmptyDirectingEdge, "Builds the edge addressed by [aGenV,aDirE], with its geometric part, but without subcomponents.", py::arg("aGenV"), py::arg("aDirE"));
cls_BRepSweep_NumLinearRegularSweep.def("MakeEmptyGeneratingEdge", (TopoDS_Shape (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_NumLinearRegularSweep::MakeEmptyGeneratingEdge, "Builds the edge addressed by [aGenE,aDirV], with its geometric part, but without subcomponents.", py::arg("aGenE"), py::arg("aDirV"));
cls_BRepSweep_NumLinearRegularSweep.def("SetParameters", (void (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &, TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_NumLinearRegularSweep::SetParameters, "Sets the parameters of the new vertex on the new face. The new face and new vertex where generated from aGenF, aGenV and aDirV .", py::arg("aNewFace"), py::arg("aNewVertex"), py::arg("aGenF"), py::arg("aGenV"), py::arg("aDirV"));
cls_BRepSweep_NumLinearRegularSweep.def("SetDirectingParameter", (void (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &, TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &, const Sweep_NumShape &)) &BRepSweep_NumLinearRegularSweep::SetDirectingParameter, "Sets the parameter of the new vertex on the new edge. The new edge and new vertex where generated from aGenV aDirE, and aDirV.", py::arg("aNewEdge"), py::arg("aNewVertex"), py::arg("aGenV"), py::arg("aDirE"), py::arg("aDirV"));
cls_BRepSweep_NumLinearRegularSweep.def("SetGeneratingParameter", (void (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &, TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_NumLinearRegularSweep::SetGeneratingParameter, "Sets the parameter of the new vertex on the new edge. The new edge and new vertex where generated from aGenE, aGenV and aDirV .", py::arg("aNewEdge"), py::arg("aNewVertex"), py::arg("aGenE"), py::arg("aGenV"), py::arg("aDirV"));
cls_BRepSweep_NumLinearRegularSweep.def("MakeEmptyFace", (TopoDS_Shape (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_NumLinearRegularSweep::MakeEmptyFace, "Builds the face addressed by [aGenS,aDirS], with its geometric part, but without subcomponents. The couple aGenS, aDirS can be a 'generating face and a directing vertex' or 'a generating edge and a directing edge'.", py::arg("aGenS"), py::arg("aDirS"));
cls_BRepSweep_NumLinearRegularSweep.def("SetPCurve", (void (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &, TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &, const TopAbs_Orientation)) &BRepSweep_NumLinearRegularSweep::SetPCurve, "Sets the PCurve for a new edge on a new face. The new edge and the new face were generated using aGenF, aGenE and aDirV.", py::arg("aNewFace"), py::arg("aNewEdge"), py::arg("aGenF"), py::arg("aGenE"), py::arg("aDirV"), py::arg("orien"));
cls_BRepSweep_NumLinearRegularSweep.def("SetGeneratingPCurve", (void (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &, TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &, const Sweep_NumShape &, const TopAbs_Orientation)) &BRepSweep_NumLinearRegularSweep::SetGeneratingPCurve, "Sets the PCurve for a new edge on a new face. The new edge and the new face were generated using aGenE, aDirE and aDirV.", py::arg("aNewFace"), py::arg("aNewEdge"), py::arg("aGenE"), py::arg("aDirE"), py::arg("aDirV"), py::arg("orien"));
cls_BRepSweep_NumLinearRegularSweep.def("SetDirectingPCurve", (void (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &, TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &, const TopAbs_Orientation)) &BRepSweep_NumLinearRegularSweep::SetDirectingPCurve, "Sets the PCurve for a new edge on a new face. The new edge and the new face were generated using aGenE, aDirE and aGenV.", py::arg("aNewFace"), py::arg("aNewEdge"), py::arg("aGenE"), py::arg("aGenV"), py::arg("aDirE"), py::arg("orien"));
cls_BRepSweep_NumLinearRegularSweep.def("DirectSolid", (TopAbs_Orientation (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_NumLinearRegularSweep::DirectSolid, "Returns the Orientation of the shell in the solid generated by the face aGenS with the edge aDirS. It is REVERSED if the surface is swept in the direction of the normal.", py::arg("aGenS"), py::arg("aDirS"));
cls_BRepSweep_NumLinearRegularSweep.def("GGDShapeIsToAdd", (Standard_Boolean (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &) const) &BRepSweep_NumLinearRegularSweep::GGDShapeIsToAdd, "Returns true if aNewSubShape (addressed by aSubGenS and aDirS) must be added in aNewShape (addressed by aGenS and aDirS).", py::arg("aNewShape"), py::arg("aNewSubShape"), py::arg("aGenS"), py::arg("aSubGenS"), py::arg("aDirS"));
cls_BRepSweep_NumLinearRegularSweep.def("GDDShapeIsToAdd", (Standard_Boolean (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &, const Sweep_NumShape &) const) &BRepSweep_NumLinearRegularSweep::GDDShapeIsToAdd, "Returns true if aNewSubShape (addressed by aGenS and aSubDirS) must be added in aNewShape (addressed by aGenS and aDirS).", py::arg("aNewShape"), py::arg("aNewSubShape"), py::arg("aGenS"), py::arg("aDirS"), py::arg("aSubDirS"));
cls_BRepSweep_NumLinearRegularSweep.def("SeparatedWires", (Standard_Boolean (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &) const) &BRepSweep_NumLinearRegularSweep::SeparatedWires, "In some particular cases the topology of a generated face must be composed of independant closed wires, in this case this function returns true.", py::arg("aNewShape"), py::arg("aNewSubShape"), py::arg("aGenS"), py::arg("aSubGenS"), py::arg("aDirS"));
cls_BRepSweep_NumLinearRegularSweep.def("SplitShell", (TopoDS_Shape (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &) const) &BRepSweep_NumLinearRegularSweep::SplitShell, "In some particular cases the topology of a generated Shell must be composed of independant closed Shells, in this case this function returns a Compound of independant Shells.", py::arg("aNewShape"));
cls_BRepSweep_NumLinearRegularSweep.def("SetContinuity", (void (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_NumLinearRegularSweep::SetContinuity, "Called to propagate the continuity of every vertex between two edges of the generating wire aGenS on the generated edge and faces.", py::arg("aGenS"), py::arg("aDirS"));
cls_BRepSweep_NumLinearRegularSweep.def("HasShape", (Standard_Boolean (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &, const Sweep_NumShape &) const) &BRepSweep_NumLinearRegularSweep::HasShape, "Returns true if aDirS and aGenS addresses a resulting Shape. In some specific cases the shape can be geometrically inexsistant, then this function returns false.", py::arg("aGenS"), py::arg("aDirS"));
cls_BRepSweep_NumLinearRegularSweep.def("Shape", (TopoDS_Shape (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_NumLinearRegularSweep::Shape, "Returns the resulting Shape indexed by aDirS and aGenS.", py::arg("aGenS"), py::arg("aDirS"));
cls_BRepSweep_NumLinearRegularSweep.def("Shape", (TopoDS_Shape (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &)) &BRepSweep_NumLinearRegularSweep::Shape, "Returns the resulting Shape indexed by myDirWire and aGenS.", py::arg("aGenS"));
cls_BRepSweep_NumLinearRegularSweep.def("Shape", (TopoDS_Shape (BRepSweep_NumLinearRegularSweep::*)()) &BRepSweep_NumLinearRegularSweep::Shape, "Returns the resulting Shape indexed by myDirWire and myGenShape.");
cls_BRepSweep_NumLinearRegularSweep.def("FirstShape", (TopoDS_Shape (BRepSweep_NumLinearRegularSweep::*)()) &BRepSweep_NumLinearRegularSweep::FirstShape, "Returns the resulting Shape indexed by the first Vertex of myDirWire and myGenShape.");
cls_BRepSweep_NumLinearRegularSweep.def("LastShape", (TopoDS_Shape (BRepSweep_NumLinearRegularSweep::*)()) &BRepSweep_NumLinearRegularSweep::LastShape, "Returns the resulting Shape indexed by the last Vertex of myDirWire and myGenShape.");
cls_BRepSweep_NumLinearRegularSweep.def("FirstShape", (TopoDS_Shape (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &)) &BRepSweep_NumLinearRegularSweep::FirstShape, "Returns the resulting Shape indexed by the first Vertex of myDirWire and aGenS.", py::arg("aGenS"));
cls_BRepSweep_NumLinearRegularSweep.def("LastShape", (TopoDS_Shape (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &)) &BRepSweep_NumLinearRegularSweep::LastShape, "Returns the resulting Shape indexed by the last Vertex of myDirWire and aGenS.", py::arg("aGenS"));
cls_BRepSweep_NumLinearRegularSweep.def("Closed", (Standard_Boolean (BRepSweep_NumLinearRegularSweep::*)() const) &BRepSweep_NumLinearRegularSweep::Closed, "None");

// Enums

}