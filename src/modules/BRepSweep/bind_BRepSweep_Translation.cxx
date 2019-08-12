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
#include <gp_Vec.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_Orientation.hxx>
#include <BRepSweep_Translation.hxx>

void bind_BRepSweep_Translation(py::module &mod){

py::class_<BRepSweep_Translation, std::unique_ptr<BRepSweep_Translation, Deleter<BRepSweep_Translation>>, BRepSweep_Trsf> cls_BRepSweep_Translation(mod, "BRepSweep_Translation", "Provides an algorithm to build object by translation sweep.");

// Constructors
cls_BRepSweep_Translation.def(py::init<const TopoDS_Shape &, const Sweep_NumShape &, const TopLoc_Location &, const gp_Vec &, const Standard_Boolean>(), py::arg("S"), py::arg("N"), py::arg("L"), py::arg("V"), py::arg("C"));
cls_BRepSweep_Translation.def(py::init<const TopoDS_Shape &, const Sweep_NumShape &, const TopLoc_Location &, const gp_Vec &, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("N"), py::arg("L"), py::arg("V"), py::arg("C"), py::arg("Canonize"));

// Fields

// Methods
// cls_BRepSweep_Translation.def_static("operator new_", (void * (*)(size_t)) &BRepSweep_Translation::operator new, "None", py::arg("theSize"));
// cls_BRepSweep_Translation.def_static("operator delete_", (void (*)(void *)) &BRepSweep_Translation::operator delete, "None", py::arg("theAddress"));
// cls_BRepSweep_Translation.def_static("operator new[]_", (void * (*)(size_t)) &BRepSweep_Translation::operator new[], "None", py::arg("theSize"));
// cls_BRepSweep_Translation.def_static("operator delete[]_", (void (*)(void *)) &BRepSweep_Translation::operator delete[], "None", py::arg("theAddress"));
// cls_BRepSweep_Translation.def_static("operator new_", (void * (*)(size_t, void *)) &BRepSweep_Translation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepSweep_Translation.def_static("operator delete_", (void (*)(void *, void *)) &BRepSweep_Translation::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepSweep_Translation.def("MakeEmptyVertex", (TopoDS_Shape (BRepSweep_Translation::*)(const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_Translation::MakeEmptyVertex, "Builds the vertex addressed by [aGenV,aDirV], with its geometric part, but without subcomponents.", py::arg("aGenV"), py::arg("aDirV"));
cls_BRepSweep_Translation.def("MakeEmptyDirectingEdge", (TopoDS_Shape (BRepSweep_Translation::*)(const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_Translation::MakeEmptyDirectingEdge, "Builds the edge addressed by [aGenV,aDirE], with its geometric part, but without subcomponents.", py::arg("aGenV"), py::arg("aDirE"));
cls_BRepSweep_Translation.def("MakeEmptyGeneratingEdge", (TopoDS_Shape (BRepSweep_Translation::*)(const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_Translation::MakeEmptyGeneratingEdge, "Builds the edge addressed by [aGenE,aDirV], with its geometric part, but without subcomponents.", py::arg("aGenE"), py::arg("aDirV"));
cls_BRepSweep_Translation.def("SetParameters", (void (BRepSweep_Translation::*)(const TopoDS_Shape &, TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_Translation::SetParameters, "Sets the parameters of the new vertex on the new face. The new face and new vertex where generated from aGenF, aGenV and aDirV .", py::arg("aNewFace"), py::arg("aNewVertex"), py::arg("aGenF"), py::arg("aGenV"), py::arg("aDirV"));
cls_BRepSweep_Translation.def("SetDirectingParameter", (void (BRepSweep_Translation::*)(const TopoDS_Shape &, TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &, const Sweep_NumShape &)) &BRepSweep_Translation::SetDirectingParameter, "Sets the parameter of the new vertex on the new edge. The new edge and new vertex where generated from aGenV aDirE, and aDirV.", py::arg("aNewEdge"), py::arg("aNewVertex"), py::arg("aGenV"), py::arg("aDirE"), py::arg("aDirV"));
cls_BRepSweep_Translation.def("SetGeneratingParameter", (void (BRepSweep_Translation::*)(const TopoDS_Shape &, TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_Translation::SetGeneratingParameter, "Sets the parameter of the new vertex on the new edge. The new edge and new vertex where generated from aGenE, aGenV and aDirV .", py::arg("aNewEdge"), py::arg("aNewVertex"), py::arg("aGenE"), py::arg("aGenV"), py::arg("aDirV"));
cls_BRepSweep_Translation.def("MakeEmptyFace", (TopoDS_Shape (BRepSweep_Translation::*)(const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_Translation::MakeEmptyFace, "Builds the face addressed by [aGenS,aDirS], with its geometric part, but without subcomponents. The couple aGenS, aDirS can be a 'generating face and a directing vertex' or 'a generating edge and a directing edge'.", py::arg("aGenS"), py::arg("aDirS"));
cls_BRepSweep_Translation.def("SetPCurve", (void (BRepSweep_Translation::*)(const TopoDS_Shape &, TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &, const TopAbs_Orientation)) &BRepSweep_Translation::SetPCurve, "Sets the PCurve for a new edge on a new face. The new edge and the new face were generated using aGenF, aGenE and aDirV.", py::arg("aNewFace"), py::arg("aNewEdge"), py::arg("aGenF"), py::arg("aGenE"), py::arg("aDirV"), py::arg("orien"));
cls_BRepSweep_Translation.def("SetGeneratingPCurve", (void (BRepSweep_Translation::*)(const TopoDS_Shape &, TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &, const Sweep_NumShape &, const TopAbs_Orientation)) &BRepSweep_Translation::SetGeneratingPCurve, "Sets the PCurve for a new edge on a new face. The new edge and the new face were generated using aGenE, aDirE and aDirV.", py::arg("aNewFace"), py::arg("aNewEdge"), py::arg("aGenE"), py::arg("aDirE"), py::arg("aDirV"), py::arg("orien"));
cls_BRepSweep_Translation.def("SetDirectingPCurve", (void (BRepSweep_Translation::*)(const TopoDS_Shape &, TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &, const TopAbs_Orientation)) &BRepSweep_Translation::SetDirectingPCurve, "Sets the PCurve for a new edge on a new face. The new edge and the new face were generated using aGenE, aDirE and aGenV.", py::arg("aNewFace"), py::arg("aNewEdge"), py::arg("aGenE"), py::arg("aGenV"), py::arg("aDirE"), py::arg("orien"));
cls_BRepSweep_Translation.def("DirectSolid", (TopAbs_Orientation (BRepSweep_Translation::*)(const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_Translation::DirectSolid, "Returns the Orientation of the shell in the solid generated by the face aGenS with the edge aDirS. It is REVERSED if the surface is swept in the direction of the normal.", py::arg("aGenS"), py::arg("aDirS"));
cls_BRepSweep_Translation.def("GGDShapeIsToAdd", (Standard_Boolean (BRepSweep_Translation::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &) const) &BRepSweep_Translation::GGDShapeIsToAdd, "Returns true if aNewSubShape (addressed by aSubGenS and aDirS) must be added in aNewShape (addressed by aGenS and aDirS).", py::arg("aNewShape"), py::arg("aNewSubShape"), py::arg("aGenS"), py::arg("aSubGenS"), py::arg("aDirS"));
cls_BRepSweep_Translation.def("GDDShapeIsToAdd", (Standard_Boolean (BRepSweep_Translation::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &, const Sweep_NumShape &) const) &BRepSweep_Translation::GDDShapeIsToAdd, "Returns true if aNewSubShape (addressed by aGenS and aSubDirS) must be added in aNewShape (addressed by aGenS and aDirS).", py::arg("aNewShape"), py::arg("aNewSubShape"), py::arg("aGenS"), py::arg("aDirS"), py::arg("aSubDirS"));
cls_BRepSweep_Translation.def("SeparatedWires", (Standard_Boolean (BRepSweep_Translation::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &) const) &BRepSweep_Translation::SeparatedWires, "In some particular cases the topology of a generated face must be composed of independant closed wires, in this case this function returns true. Here it always returns false.", py::arg("aNewShape"), py::arg("aNewSubShape"), py::arg("aGenS"), py::arg("aSubGenS"), py::arg("aDirS"));
cls_BRepSweep_Translation.def("HasShape", (Standard_Boolean (BRepSweep_Translation::*)(const TopoDS_Shape &, const Sweep_NumShape &) const) &BRepSweep_Translation::HasShape, "Returns true if aDirS and aGenS addresses a resulting Shape. In some specific cases the shape can be geometrically inexsistant, then this function returns false.", py::arg("aGenS"), py::arg("aDirS"));
cls_BRepSweep_Translation.def("IsInvariant", (Standard_Boolean (BRepSweep_Translation::*)(const TopoDS_Shape &) const) &BRepSweep_Translation::IsInvariant, "Returns always false because here the transformation is a translation.", py::arg("aGenS"));
cls_BRepSweep_Translation.def("Vec", (gp_Vec (BRepSweep_Translation::*)() const) &BRepSweep_Translation::Vec, "Returns the Vector of the Prism, if it is an infinite prism the Vec is unitar.");

// Enums

}