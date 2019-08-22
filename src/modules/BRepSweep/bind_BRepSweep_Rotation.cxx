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
#include <BRepSweep_Trsf.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <Sweep_NumShape.hxx>
#include <TopLoc_Location.hxx>
#include <gp_Ax1.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_Orientation.hxx>
#include <BRepSweep_Rotation.hxx>

void bind_BRepSweep_Rotation(py::module &mod){

py::class_<BRepSweep_Rotation, BRepSweep_Trsf> cls_BRepSweep_Rotation(mod, "BRepSweep_Rotation", "Provides an algorithm to build object by Rotation sweep.");

// Constructors
cls_BRepSweep_Rotation.def(py::init<const TopoDS_Shape &, const Sweep_NumShape &, const TopLoc_Location &, const gp_Ax1 &, const Standard_Real, const Standard_Boolean>(), py::arg("S"), py::arg("N"), py::arg("L"), py::arg("A"), py::arg("D"), py::arg("C"));

// Fields

// Methods
// cls_BRepSweep_Rotation.def_static("operator new_", (void * (*)(size_t)) &BRepSweep_Rotation::operator new, "None", py::arg("theSize"));
// cls_BRepSweep_Rotation.def_static("operator delete_", (void (*)(void *)) &BRepSweep_Rotation::operator delete, "None", py::arg("theAddress"));
// cls_BRepSweep_Rotation.def_static("operator new[]_", (void * (*)(size_t)) &BRepSweep_Rotation::operator new[], "None", py::arg("theSize"));
// cls_BRepSweep_Rotation.def_static("operator delete[]_", (void (*)(void *)) &BRepSweep_Rotation::operator delete[], "None", py::arg("theAddress"));
// cls_BRepSweep_Rotation.def_static("operator new_", (void * (*)(size_t, void *)) &BRepSweep_Rotation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepSweep_Rotation.def_static("operator delete_", (void (*)(void *, void *)) &BRepSweep_Rotation::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepSweep_Rotation.def("MakeEmptyVertex", (TopoDS_Shape (BRepSweep_Rotation::*)(const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_Rotation::MakeEmptyVertex, "Builds the vertex addressed by [aGenV,aDirV], with its geometric part, but without subcomponents.", py::arg("aGenV"), py::arg("aDirV"));
cls_BRepSweep_Rotation.def("MakeEmptyDirectingEdge", (TopoDS_Shape (BRepSweep_Rotation::*)(const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_Rotation::MakeEmptyDirectingEdge, "Builds the edge addressed by [aGenV,aDirE], with its geometric part, but without subcomponents.", py::arg("aGenV"), py::arg("aDirE"));
cls_BRepSweep_Rotation.def("MakeEmptyGeneratingEdge", (TopoDS_Shape (BRepSweep_Rotation::*)(const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_Rotation::MakeEmptyGeneratingEdge, "Builds the edge addressed by [aGenE,aDirV], with its geometric part, but without subcomponents.", py::arg("aGenE"), py::arg("aDirV"));
cls_BRepSweep_Rotation.def("SetParameters", (void (BRepSweep_Rotation::*)(const TopoDS_Shape &, TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_Rotation::SetParameters, "Sets the parameters of the new vertex on the new face. The new face and new vertex where generated from aGenF, aGenV and aDirV .", py::arg("aNewFace"), py::arg("aNewVertex"), py::arg("aGenF"), py::arg("aGenV"), py::arg("aDirV"));
cls_BRepSweep_Rotation.def("SetDirectingParameter", (void (BRepSweep_Rotation::*)(const TopoDS_Shape &, TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &, const Sweep_NumShape &)) &BRepSweep_Rotation::SetDirectingParameter, "Sets the parameter of the new vertex on the new edge. The new edge and new vertex where generated from aGenV aDirE, and aDirV.", py::arg("aNewEdge"), py::arg("aNewVertex"), py::arg("aGenV"), py::arg("aDirE"), py::arg("aDirV"));
cls_BRepSweep_Rotation.def("SetGeneratingParameter", (void (BRepSweep_Rotation::*)(const TopoDS_Shape &, TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_Rotation::SetGeneratingParameter, "Sets the parameter of the new vertex on the new edge. The new edge and new vertex where generated from aGenE, aGenV and aDirV .", py::arg("aNewEdge"), py::arg("aNewVertex"), py::arg("aGenE"), py::arg("aGenV"), py::arg("aDirV"));
cls_BRepSweep_Rotation.def("MakeEmptyFace", (TopoDS_Shape (BRepSweep_Rotation::*)(const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_Rotation::MakeEmptyFace, "Builds the face addressed by [aGenS,aDirS], with its geometric part, but without subcomponents. The couple aGenS, aDirS can be a 'generating face and a directing vertex' or 'a generating edge and a directing edge'.", py::arg("aGenS"), py::arg("aDirS"));
cls_BRepSweep_Rotation.def("SetPCurve", (void (BRepSweep_Rotation::*)(const TopoDS_Shape &, TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &, const TopAbs_Orientation)) &BRepSweep_Rotation::SetPCurve, "Sets the PCurve for a new edge on a new face. The new edge and the new face were generated using aGenF, aGenE and aDirV.", py::arg("aNewFace"), py::arg("aNewEdge"), py::arg("aGenF"), py::arg("aGenE"), py::arg("aDirV"), py::arg("orien"));
cls_BRepSweep_Rotation.def("SetGeneratingPCurve", (void (BRepSweep_Rotation::*)(const TopoDS_Shape &, TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &, const Sweep_NumShape &, const TopAbs_Orientation)) &BRepSweep_Rotation::SetGeneratingPCurve, "Sets the PCurve for a new edge on a new face. The new edge and the new face were generated using aGenE, aDirE and aDirV.", py::arg("aNewFace"), py::arg("aNewEdge"), py::arg("aGenE"), py::arg("aDirE"), py::arg("aDirV"), py::arg("orien"));
cls_BRepSweep_Rotation.def("SetDirectingPCurve", (void (BRepSweep_Rotation::*)(const TopoDS_Shape &, TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &, const TopAbs_Orientation)) &BRepSweep_Rotation::SetDirectingPCurve, "Sets the PCurve for a new edge on a new face. The new edge and the new face were generated using aGenE, aDirE and aGenV.", py::arg("aNewFace"), py::arg("aNewEdge"), py::arg("aGenE"), py::arg("aGenV"), py::arg("aDirE"), py::arg("orien"));
cls_BRepSweep_Rotation.def("DirectSolid", (TopAbs_Orientation (BRepSweep_Rotation::*)(const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_Rotation::DirectSolid, "Returns the Orientation of the shell in the solid generated by the face aGenS with the edge aDirS. It is REVERSED if the surface is swept in the direction of the normal.", py::arg("aGenS"), py::arg("aDirS"));
cls_BRepSweep_Rotation.def("GGDShapeIsToAdd", (Standard_Boolean (BRepSweep_Rotation::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &) const) &BRepSweep_Rotation::GGDShapeIsToAdd, "Returns true if aNewSubShape (addressed by aSubGenS and aDirS) must be added in aNewShape (addressed by aGenS and aDirS).", py::arg("aNewShape"), py::arg("aNewSubShape"), py::arg("aGenS"), py::arg("aSubGenS"), py::arg("aDirS"));
cls_BRepSweep_Rotation.def("GDDShapeIsToAdd", (Standard_Boolean (BRepSweep_Rotation::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &, const Sweep_NumShape &) const) &BRepSweep_Rotation::GDDShapeIsToAdd, "Returns true if aNewSubShape (addressed by aGenS and aSubDirS) must be added in aNewShape (addressed by aGenS and aDirS).", py::arg("aNewShape"), py::arg("aNewSubShape"), py::arg("aGenS"), py::arg("aDirS"), py::arg("aSubDirS"));
cls_BRepSweep_Rotation.def("SeparatedWires", (Standard_Boolean (BRepSweep_Rotation::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &) const) &BRepSweep_Rotation::SeparatedWires, "In some particular cases the topology of a generated face must be composed of independant closed wires, in this case this function returns true. The only case in whitch the function may return true is a planar face in a closed revol.", py::arg("aNewShape"), py::arg("aNewSubShape"), py::arg("aGenS"), py::arg("aSubGenS"), py::arg("aDirS"));
cls_BRepSweep_Rotation.def("SplitShell", (TopoDS_Shape (BRepSweep_Rotation::*)(const TopoDS_Shape &) const) &BRepSweep_Rotation::SplitShell, "In some particular cases the topology of a generated Shell must be composed of independant closed Shells, in this case this function returns a Compound of independant Shells.", py::arg("aNewShape"));
cls_BRepSweep_Rotation.def("HasShape", (Standard_Boolean (BRepSweep_Rotation::*)(const TopoDS_Shape &, const Sweep_NumShape &) const) &BRepSweep_Rotation::HasShape, "Returns true if aDirS and aGenS addresses a resulting Shape. In some specific cases the shape can be geometrically inexsistant, then this function returns false.", py::arg("aGenS"), py::arg("aDirS"));
cls_BRepSweep_Rotation.def("IsInvariant", (Standard_Boolean (BRepSweep_Rotation::*)(const TopoDS_Shape &) const) &BRepSweep_Rotation::IsInvariant, "Returns true when the geometry of aGenS is not modified by the rotation.", py::arg("aGenS"));
cls_BRepSweep_Rotation.def("Axe", (gp_Ax1 (BRepSweep_Rotation::*)() const) &BRepSweep_Rotation::Axe, "returns the axis");
cls_BRepSweep_Rotation.def("Angle", (Standard_Real (BRepSweep_Rotation::*)() const) &BRepSweep_Rotation::Angle, "returns the angle.");

// Enums

}