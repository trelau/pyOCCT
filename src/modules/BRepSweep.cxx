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
#include <BRep_Builder.hxx>
#include <TopoDS_Shape.hxx>
#include <TopAbs_Orientation.hxx>
#include <BRepSweep_Builder.hxx>
#include <Standard_TypeDef.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <BRepSweep_Tool.hxx>
#include <Sweep_NumShape.hxx>
#include <Sweep_NumShapeTool.hxx>
#include <TopTools_Array2OfShape.hxx>
#include <TColStd_Array2OfBoolean.hxx>
#include <BRepSweep_NumLinearRegularSweep.hxx>
#include <TopLoc_Location.hxx>
#include <BRepSweep_Trsf.hxx>
#include <gp_Vec.hxx>
#include <BRepSweep_Translation.hxx>
#include <gp_Dir.hxx>
#include <BRepSweep_Prism.hxx>
#include <gp_Ax1.hxx>
#include <BRepSweep_Rotation.hxx>
#include <BRepSweep_Revol.hxx>
#include <TopoDS_Iterator.hxx>
#include <BRepSweep_Iterator.hxx>

PYBIND11_MODULE(BRepSweep, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.BRep");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.Sweep");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.TopLoc");
py::module::import("OCCT.gp");

// CLASS: BREPSWEEP_BUILDER
py::class_<BRepSweep_Builder> cls_BRepSweep_Builder(mod, "BRepSweep_Builder", "implements the abstract Builder with the BRep Builder");

// Constructors
cls_BRepSweep_Builder.def(py::init<const BRep_Builder &>(), py::arg("aBuilder"));

// Methods
// cls_BRepSweep_Builder.def_static("operator new_", (void * (*)(size_t)) &BRepSweep_Builder::operator new, "None", py::arg("theSize"));
// cls_BRepSweep_Builder.def_static("operator delete_", (void (*)(void *)) &BRepSweep_Builder::operator delete, "None", py::arg("theAddress"));
// cls_BRepSweep_Builder.def_static("operator new[]_", (void * (*)(size_t)) &BRepSweep_Builder::operator new[], "None", py::arg("theSize"));
// cls_BRepSweep_Builder.def_static("operator delete[]_", (void (*)(void *)) &BRepSweep_Builder::operator delete[], "None", py::arg("theAddress"));
// cls_BRepSweep_Builder.def_static("operator new_", (void * (*)(size_t, void *)) &BRepSweep_Builder::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepSweep_Builder.def_static("operator delete_", (void (*)(void *, void *)) &BRepSweep_Builder::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepSweep_Builder.def("Builder", (const BRep_Builder & (BRepSweep_Builder::*)() const) &BRepSweep_Builder::Builder, "None");
cls_BRepSweep_Builder.def("MakeCompound", (void (BRepSweep_Builder::*)(TopoDS_Shape &) const) &BRepSweep_Builder::MakeCompound, "Returns an empty Compound.", py::arg("aCompound"));
cls_BRepSweep_Builder.def("MakeCompSolid", (void (BRepSweep_Builder::*)(TopoDS_Shape &) const) &BRepSweep_Builder::MakeCompSolid, "Returns an empty CompSolid.", py::arg("aCompSolid"));
cls_BRepSweep_Builder.def("MakeSolid", (void (BRepSweep_Builder::*)(TopoDS_Shape &) const) &BRepSweep_Builder::MakeSolid, "Returns an empty Solid.", py::arg("aSolid"));
cls_BRepSweep_Builder.def("MakeShell", (void (BRepSweep_Builder::*)(TopoDS_Shape &) const) &BRepSweep_Builder::MakeShell, "Returns an empty Shell.", py::arg("aShell"));
cls_BRepSweep_Builder.def("MakeWire", (void (BRepSweep_Builder::*)(TopoDS_Shape &) const) &BRepSweep_Builder::MakeWire, "Returns an empty Wire.", py::arg("aWire"));
cls_BRepSweep_Builder.def("Add", (void (BRepSweep_Builder::*)(TopoDS_Shape &, const TopoDS_Shape &, const TopAbs_Orientation) const) &BRepSweep_Builder::Add, "Adds the Shape 1 in the Shape 2, set to <Orient> orientation.", py::arg("aShape1"), py::arg("aShape2"), py::arg("Orient"));
cls_BRepSweep_Builder.def("Add", (void (BRepSweep_Builder::*)(TopoDS_Shape &, const TopoDS_Shape &) const) &BRepSweep_Builder::Add, "Adds the Shape 1 in the Shape 2.", py::arg("aShape1"), py::arg("aShape2"));

// CLASS: BREPSWEEP_TOOL
py::class_<BRepSweep_Tool> cls_BRepSweep_Tool(mod, "BRepSweep_Tool", "Provides the indexation and type analysis services required by the TopoDS generating Shape of BRepSweep.");

// Constructors
cls_BRepSweep_Tool.def(py::init<const TopoDS_Shape &>(), py::arg("aShape"));

// Methods
// cls_BRepSweep_Tool.def_static("operator new_", (void * (*)(size_t)) &BRepSweep_Tool::operator new, "None", py::arg("theSize"));
// cls_BRepSweep_Tool.def_static("operator delete_", (void (*)(void *)) &BRepSweep_Tool::operator delete, "None", py::arg("theAddress"));
// cls_BRepSweep_Tool.def_static("operator new[]_", (void * (*)(size_t)) &BRepSweep_Tool::operator new[], "None", py::arg("theSize"));
// cls_BRepSweep_Tool.def_static("operator delete[]_", (void (*)(void *)) &BRepSweep_Tool::operator delete[], "None", py::arg("theAddress"));
// cls_BRepSweep_Tool.def_static("operator new_", (void * (*)(size_t, void *)) &BRepSweep_Tool::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepSweep_Tool.def_static("operator delete_", (void (*)(void *, void *)) &BRepSweep_Tool::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepSweep_Tool.def("NbShapes", (Standard_Integer (BRepSweep_Tool::*)() const) &BRepSweep_Tool::NbShapes, "Returns the number of subshapes in the shape.");
cls_BRepSweep_Tool.def("Index", (Standard_Integer (BRepSweep_Tool::*)(const TopoDS_Shape &) const) &BRepSweep_Tool::Index, "Returns the index of <aShape>.", py::arg("aShape"));
cls_BRepSweep_Tool.def("Shape", (TopoDS_Shape (BRepSweep_Tool::*)(const Standard_Integer) const) &BRepSweep_Tool::Shape, "Returns the Shape at Index anIdex.", py::arg("anIndex"));
cls_BRepSweep_Tool.def("Type", (TopAbs_ShapeEnum (BRepSweep_Tool::*)(const TopoDS_Shape &) const) &BRepSweep_Tool::Type, "Returns the type of <aShape>.", py::arg("aShape"));
cls_BRepSweep_Tool.def("Orientation", (TopAbs_Orientation (BRepSweep_Tool::*)(const TopoDS_Shape &) const) &BRepSweep_Tool::Orientation, "Returns the Orientation of <aShape>.", py::arg("aShape"));
cls_BRepSweep_Tool.def("SetOrientation", (void (BRepSweep_Tool::*)(TopoDS_Shape &, const TopAbs_Orientation) const) &BRepSweep_Tool::SetOrientation, "Set the Orientation of <aShape> with Or.", py::arg("aShape"), py::arg("Or"));

// CLASS: BREPSWEEP_NUMLINEARREGULARSWEEP
py::class_<BRepSweep_NumLinearRegularSweep> cls_BRepSweep_NumLinearRegularSweep(mod, "BRepSweep_NumLinearRegularSweep", "This a generic class is used to build Sweept primitives with a generating 'shape' and a directing 'line'.");

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
cls_BRepSweep_NumLinearRegularSweep.def("IsInvariant", (Standard_Boolean (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &) const) &BRepSweep_NumLinearRegularSweep::IsInvariant, "Returns true if aGenS cannot be transformed.", py::arg("aGenS"));
cls_BRepSweep_NumLinearRegularSweep.def("Shape", (TopoDS_Shape (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_NumLinearRegularSweep::Shape, "Returns the resulting Shape indexed by aDirS and aGenS.", py::arg("aGenS"), py::arg("aDirS"));
cls_BRepSweep_NumLinearRegularSweep.def("Shape", (TopoDS_Shape (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &)) &BRepSweep_NumLinearRegularSweep::Shape, "Returns the resulting Shape indexed by myDirWire and aGenS.", py::arg("aGenS"));
cls_BRepSweep_NumLinearRegularSweep.def("IsUsed", (Standard_Boolean (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &) const) &BRepSweep_NumLinearRegularSweep::IsUsed, "Returns true if the initial shape aGenS is used in result shape", py::arg("aGenS"));
cls_BRepSweep_NumLinearRegularSweep.def("GenIsUsed", (Standard_Boolean (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &) const) &BRepSweep_NumLinearRegularSweep::GenIsUsed, "Returns true if the shape, generated from theS is used in result shape", py::arg("theS"));
cls_BRepSweep_NumLinearRegularSweep.def("Shape", (TopoDS_Shape (BRepSweep_NumLinearRegularSweep::*)()) &BRepSweep_NumLinearRegularSweep::Shape, "Returns the resulting Shape indexed by myDirWire and myGenShape.");
cls_BRepSweep_NumLinearRegularSweep.def("FirstShape", (TopoDS_Shape (BRepSweep_NumLinearRegularSweep::*)()) &BRepSweep_NumLinearRegularSweep::FirstShape, "Returns the resulting Shape indexed by the first Vertex of myDirWire and myGenShape.");
cls_BRepSweep_NumLinearRegularSweep.def("LastShape", (TopoDS_Shape (BRepSweep_NumLinearRegularSweep::*)()) &BRepSweep_NumLinearRegularSweep::LastShape, "Returns the resulting Shape indexed by the last Vertex of myDirWire and myGenShape.");
cls_BRepSweep_NumLinearRegularSweep.def("FirstShape", (TopoDS_Shape (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &)) &BRepSweep_NumLinearRegularSweep::FirstShape, "Returns the resulting Shape indexed by the first Vertex of myDirWire and aGenS.", py::arg("aGenS"));
cls_BRepSweep_NumLinearRegularSweep.def("LastShape", (TopoDS_Shape (BRepSweep_NumLinearRegularSweep::*)(const TopoDS_Shape &)) &BRepSweep_NumLinearRegularSweep::LastShape, "Returns the resulting Shape indexed by the last Vertex of myDirWire and aGenS.", py::arg("aGenS"));
cls_BRepSweep_NumLinearRegularSweep.def("Closed", (Standard_Boolean (BRepSweep_NumLinearRegularSweep::*)() const) &BRepSweep_NumLinearRegularSweep::Closed, "None");

// CLASS: BREPSWEEP_TRSF
py::class_<BRepSweep_Trsf, BRepSweep_NumLinearRegularSweep> cls_BRepSweep_Trsf(mod, "BRepSweep_Trsf", "This class is inherited from NumLinearRegularSweep to implement the simple swept primitives built moving a Shape with a Trsf. It often is possible to build the constructed subshapes by a simple move of the generating subshapes (shared topology and geometry). So two ways of construction are proposed :");

// Methods
// cls_BRepSweep_Trsf.def_static("operator new_", (void * (*)(size_t)) &BRepSweep_Trsf::operator new, "None", py::arg("theSize"));
// cls_BRepSweep_Trsf.def_static("operator delete_", (void (*)(void *)) &BRepSweep_Trsf::operator delete, "None", py::arg("theAddress"));
// cls_BRepSweep_Trsf.def_static("operator new[]_", (void * (*)(size_t)) &BRepSweep_Trsf::operator new[], "None", py::arg("theSize"));
// cls_BRepSweep_Trsf.def_static("operator delete[]_", (void (*)(void *)) &BRepSweep_Trsf::operator delete[], "None", py::arg("theAddress"));
// cls_BRepSweep_Trsf.def_static("operator new_", (void * (*)(size_t, void *)) &BRepSweep_Trsf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepSweep_Trsf.def_static("operator delete_", (void (*)(void *, void *)) &BRepSweep_Trsf::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepSweep_Trsf.def("Init", (void (BRepSweep_Trsf::*)()) &BRepSweep_Trsf::Init, "ends the construction of the swept primitive calling the virtual geometric functions that can't be called in the initialize.");
cls_BRepSweep_Trsf.def("Process", (Standard_Boolean (BRepSweep_Trsf::*)(const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_Trsf::Process, "function called to analize the way of construction of the shapes generated by aGenS and aDirV.", py::arg("aGenS"), py::arg("aDirV"));
cls_BRepSweep_Trsf.def("MakeEmptyVertex", (TopoDS_Shape (BRepSweep_Trsf::*)(const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_Trsf::MakeEmptyVertex, "Builds the vertex addressed by [aGenV,aDirV], with its geometric part, but without subcomponents.", py::arg("aGenV"), py::arg("aDirV"));
cls_BRepSweep_Trsf.def("MakeEmptyDirectingEdge", (TopoDS_Shape (BRepSweep_Trsf::*)(const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_Trsf::MakeEmptyDirectingEdge, "Builds the edge addressed by [aGenV,aDirE], with its geometric part, but without subcomponents.", py::arg("aGenV"), py::arg("aDirE"));
cls_BRepSweep_Trsf.def("MakeEmptyGeneratingEdge", (TopoDS_Shape (BRepSweep_Trsf::*)(const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_Trsf::MakeEmptyGeneratingEdge, "Builds the edge addressed by [aGenE,aDirV], with its geometric part, but without subcomponents.", py::arg("aGenE"), py::arg("aDirV"));
cls_BRepSweep_Trsf.def("SetParameters", (void (BRepSweep_Trsf::*)(const TopoDS_Shape &, TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_Trsf::SetParameters, "Sets the parameters of the new vertex on the new face. The new face and new vertex where generated from aGenF, aGenV and aDirV .", py::arg("aNewFace"), py::arg("aNewVertex"), py::arg("aGenF"), py::arg("aGenV"), py::arg("aDirV"));
cls_BRepSweep_Trsf.def("SetDirectingParameter", (void (BRepSweep_Trsf::*)(const TopoDS_Shape &, TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &, const Sweep_NumShape &)) &BRepSweep_Trsf::SetDirectingParameter, "Sets the parameter of the new vertex on the new edge. The new edge and new vertex where generated from aGenV aDirE, and aDirV.", py::arg("aNewEdge"), py::arg("aNewVertex"), py::arg("aGenV"), py::arg("aDirE"), py::arg("aDirV"));
cls_BRepSweep_Trsf.def("SetGeneratingParameter", (void (BRepSweep_Trsf::*)(const TopoDS_Shape &, TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_Trsf::SetGeneratingParameter, "Sets the parameter of the new vertex on the new edge. The new edge and new vertex where generated from aGenE, aGenV and aDirV .", py::arg("aNewEdge"), py::arg("aNewVertex"), py::arg("aGenE"), py::arg("aGenV"), py::arg("aDirV"));
cls_BRepSweep_Trsf.def("MakeEmptyFace", (TopoDS_Shape (BRepSweep_Trsf::*)(const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_Trsf::MakeEmptyFace, "Builds the face addressed by [aGenS,aDirS], with its geometric part, but without subcomponents. The couple aGenS, aDirS can be a 'generating face and a directing vertex' or 'a generating edge and a directing edge'.", py::arg("aGenS"), py::arg("aDirS"));
cls_BRepSweep_Trsf.def("SetPCurve", (void (BRepSweep_Trsf::*)(const TopoDS_Shape &, TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &, const TopAbs_Orientation)) &BRepSweep_Trsf::SetPCurve, "Sets the PCurve for a new edge on a new face. The new edge and the new face were generated using aGenF, aGenE and aDirV.", py::arg("aNewFace"), py::arg("aNewEdge"), py::arg("aGenF"), py::arg("aGenE"), py::arg("aDirV"), py::arg("orien"));
cls_BRepSweep_Trsf.def("SetGeneratingPCurve", (void (BRepSweep_Trsf::*)(const TopoDS_Shape &, TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &, const Sweep_NumShape &, const TopAbs_Orientation)) &BRepSweep_Trsf::SetGeneratingPCurve, "Sets the PCurve for a new edge on a new face. The new edge and the new face were generated using aGenE, aDirE and aDirV.", py::arg("aNewFace"), py::arg("aNewEdge"), py::arg("aGenE"), py::arg("aDirE"), py::arg("aDirV"), py::arg("orien"));
cls_BRepSweep_Trsf.def("SetDirectingPCurve", (void (BRepSweep_Trsf::*)(const TopoDS_Shape &, TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &, const TopAbs_Orientation)) &BRepSweep_Trsf::SetDirectingPCurve, "Sets the PCurve for a new edge on a new face. The new edge and the new face were generated using aGenE, aDirE and aGenV.", py::arg("aNewFace"), py::arg("aNewEdge"), py::arg("aGenE"), py::arg("aGenV"), py::arg("aDirE"), py::arg("orien"));
cls_BRepSweep_Trsf.def("GGDShapeIsToAdd", (Standard_Boolean (BRepSweep_Trsf::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &) const) &BRepSweep_Trsf::GGDShapeIsToAdd, "Returns true if aNewSubShape (addressed by aSubGenS and aDirS) must be added in aNewShape (addressed by aGenS and aDirS).", py::arg("aNewShape"), py::arg("aNewSubShape"), py::arg("aGenS"), py::arg("aSubGenS"), py::arg("aDirS"));
cls_BRepSweep_Trsf.def("GDDShapeIsToAdd", (Standard_Boolean (BRepSweep_Trsf::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &, const Sweep_NumShape &) const) &BRepSweep_Trsf::GDDShapeIsToAdd, "Returns true if aNewSubShape (addressed by aGenS and aSubDirS) must be added in aNewShape (addressed by aGenS and aDirS).", py::arg("aNewShape"), py::arg("aNewSubShape"), py::arg("aGenS"), py::arg("aDirS"), py::arg("aSubDirS"));
cls_BRepSweep_Trsf.def("SeparatedWires", (Standard_Boolean (BRepSweep_Trsf::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const Sweep_NumShape &) const) &BRepSweep_Trsf::SeparatedWires, "In some particular cases the topology of a generated face must be composed of independant closed wires, in this case this function returns true.", py::arg("aNewShape"), py::arg("aNewSubShape"), py::arg("aGenS"), py::arg("aSubGenS"), py::arg("aDirS"));
cls_BRepSweep_Trsf.def("HasShape", (Standard_Boolean (BRepSweep_Trsf::*)(const TopoDS_Shape &, const Sweep_NumShape &) const) &BRepSweep_Trsf::HasShape, "Returns true if aDirS and aGenS addresses a resulting Shape. In some specific cases the shape can be geometrically inexsistant, then this function returns false.", py::arg("aGenS"), py::arg("aDirS"));
cls_BRepSweep_Trsf.def("IsInvariant", (Standard_Boolean (BRepSweep_Trsf::*)(const TopoDS_Shape &) const) &BRepSweep_Trsf::IsInvariant, "Returns true if the geometry of aGenS is not modified by the trsf of the BRepSweep Trsf.", py::arg("aGenS"));
cls_BRepSweep_Trsf.def("SetContinuity", (void (BRepSweep_Trsf::*)(const TopoDS_Shape &, const Sweep_NumShape &)) &BRepSweep_Trsf::SetContinuity, "Called to propagate the continuity of every vertex between two edges of the generating wire aGenS on the generated edge and faces.", py::arg("aGenS"), py::arg("aDirS"));

// CLASS: BREPSWEEP_TRANSLATION
py::class_<BRepSweep_Translation, BRepSweep_Trsf> cls_BRepSweep_Translation(mod, "BRepSweep_Translation", "Provides an algorithm to build object by translation sweep.");

// Constructors
cls_BRepSweep_Translation.def(py::init<const TopoDS_Shape &, const Sweep_NumShape &, const TopLoc_Location &, const gp_Vec &, const Standard_Boolean>(), py::arg("S"), py::arg("N"), py::arg("L"), py::arg("V"), py::arg("C"));
cls_BRepSweep_Translation.def(py::init<const TopoDS_Shape &, const Sweep_NumShape &, const TopLoc_Location &, const gp_Vec &, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("N"), py::arg("L"), py::arg("V"), py::arg("C"), py::arg("Canonize"));

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

// CLASS: BREPSWEEP_PRISM
py::class_<BRepSweep_Prism> cls_BRepSweep_Prism(mod, "BRepSweep_Prism", "Provides natural constructors to build BRepSweep translated swept Primitives.");

// Constructors
cls_BRepSweep_Prism.def(py::init<const TopoDS_Shape &, const gp_Vec &>(), py::arg("S"), py::arg("V"));
cls_BRepSweep_Prism.def(py::init<const TopoDS_Shape &, const gp_Vec &, const Standard_Boolean>(), py::arg("S"), py::arg("V"), py::arg("Copy"));
cls_BRepSweep_Prism.def(py::init<const TopoDS_Shape &, const gp_Vec &, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("V"), py::arg("Copy"), py::arg("Canonize"));
cls_BRepSweep_Prism.def(py::init<const TopoDS_Shape &, const gp_Dir &>(), py::arg("S"), py::arg("D"));
cls_BRepSweep_Prism.def(py::init<const TopoDS_Shape &, const gp_Dir &, const Standard_Boolean>(), py::arg("S"), py::arg("D"), py::arg("Inf"));
cls_BRepSweep_Prism.def(py::init<const TopoDS_Shape &, const gp_Dir &, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("D"), py::arg("Inf"), py::arg("Copy"));
cls_BRepSweep_Prism.def(py::init<const TopoDS_Shape &, const gp_Dir &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("S"), py::arg("D"), py::arg("Inf"), py::arg("Copy"), py::arg("Canonize"));

// Methods
// cls_BRepSweep_Prism.def_static("operator new_", (void * (*)(size_t)) &BRepSweep_Prism::operator new, "None", py::arg("theSize"));
// cls_BRepSweep_Prism.def_static("operator delete_", (void (*)(void *)) &BRepSweep_Prism::operator delete, "None", py::arg("theAddress"));
// cls_BRepSweep_Prism.def_static("operator new[]_", (void * (*)(size_t)) &BRepSweep_Prism::operator new[], "None", py::arg("theSize"));
// cls_BRepSweep_Prism.def_static("operator delete[]_", (void (*)(void *)) &BRepSweep_Prism::operator delete[], "None", py::arg("theAddress"));
// cls_BRepSweep_Prism.def_static("operator new_", (void * (*)(size_t, void *)) &BRepSweep_Prism::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepSweep_Prism.def_static("operator delete_", (void (*)(void *, void *)) &BRepSweep_Prism::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepSweep_Prism.def("Shape", (TopoDS_Shape (BRepSweep_Prism::*)()) &BRepSweep_Prism::Shape, "Returns the TopoDS Shape attached to the prism.");
cls_BRepSweep_Prism.def("Shape", (TopoDS_Shape (BRepSweep_Prism::*)(const TopoDS_Shape &)) &BRepSweep_Prism::Shape, "Returns the TopoDS Shape generated with aGenS (subShape of the generating shape).", py::arg("aGenS"));
cls_BRepSweep_Prism.def("FirstShape", (TopoDS_Shape (BRepSweep_Prism::*)()) &BRepSweep_Prism::FirstShape, "Returns the TopoDS Shape of the bottom of the prism.");
cls_BRepSweep_Prism.def("FirstShape", (TopoDS_Shape (BRepSweep_Prism::*)(const TopoDS_Shape &)) &BRepSweep_Prism::FirstShape, "Returns the TopoDS Shape of the bottom of the prism. generated with aGenS (subShape of the generating shape).", py::arg("aGenS"));
cls_BRepSweep_Prism.def("LastShape", (TopoDS_Shape (BRepSweep_Prism::*)()) &BRepSweep_Prism::LastShape, "Returns the TopoDS Shape of the top of the prism.");
cls_BRepSweep_Prism.def("LastShape", (TopoDS_Shape (BRepSweep_Prism::*)(const TopoDS_Shape &)) &BRepSweep_Prism::LastShape, "Returns the TopoDS Shape of the top of the prism. generated with aGenS (subShape of the generating shape).", py::arg("aGenS"));
cls_BRepSweep_Prism.def("Vec", (gp_Vec (BRepSweep_Prism::*)() const) &BRepSweep_Prism::Vec, "Returns the Vector of the Prism, if it is an infinite prism the Vec is unitar.");
cls_BRepSweep_Prism.def("IsUsed", (Standard_Boolean (BRepSweep_Prism::*)(const TopoDS_Shape &) const) &BRepSweep_Prism::IsUsed, "Returns true if the aGenS is used in resulting shape", py::arg("aGenS"));
cls_BRepSweep_Prism.def("GenIsUsed", (Standard_Boolean (BRepSweep_Prism::*)(const TopoDS_Shape &) const) &BRepSweep_Prism::GenIsUsed, "Returns true if the shape, generated from theS is used in result shape", py::arg("theS"));

// CLASS: BREPSWEEP_ROTATION
py::class_<BRepSweep_Rotation, BRepSweep_Trsf> cls_BRepSweep_Rotation(mod, "BRepSweep_Rotation", "Provides an algorithm to build object by Rotation sweep.");

// Constructors
cls_BRepSweep_Rotation.def(py::init<const TopoDS_Shape &, const Sweep_NumShape &, const TopLoc_Location &, const gp_Ax1 &, const Standard_Real, const Standard_Boolean>(), py::arg("S"), py::arg("N"), py::arg("L"), py::arg("A"), py::arg("D"), py::arg("C"));

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

// CLASS: BREPSWEEP_REVOL
py::class_<BRepSweep_Revol> cls_BRepSweep_Revol(mod, "BRepSweep_Revol", "Provides natural constructors to build BRepSweep rotated swept Primitives.");

// Constructors
cls_BRepSweep_Revol.def(py::init<const TopoDS_Shape &, const gp_Ax1 &, const Standard_Real>(), py::arg("S"), py::arg("A"), py::arg("D"));
cls_BRepSweep_Revol.def(py::init<const TopoDS_Shape &, const gp_Ax1 &, const Standard_Real, const Standard_Boolean>(), py::arg("S"), py::arg("A"), py::arg("D"), py::arg("C"));
cls_BRepSweep_Revol.def(py::init<const TopoDS_Shape &, const gp_Ax1 &>(), py::arg("S"), py::arg("A"));
cls_BRepSweep_Revol.def(py::init<const TopoDS_Shape &, const gp_Ax1 &, const Standard_Boolean>(), py::arg("S"), py::arg("A"), py::arg("C"));

// Methods
// cls_BRepSweep_Revol.def_static("operator new_", (void * (*)(size_t)) &BRepSweep_Revol::operator new, "None", py::arg("theSize"));
// cls_BRepSweep_Revol.def_static("operator delete_", (void (*)(void *)) &BRepSweep_Revol::operator delete, "None", py::arg("theAddress"));
// cls_BRepSweep_Revol.def_static("operator new[]_", (void * (*)(size_t)) &BRepSweep_Revol::operator new[], "None", py::arg("theSize"));
// cls_BRepSweep_Revol.def_static("operator delete[]_", (void (*)(void *)) &BRepSweep_Revol::operator delete[], "None", py::arg("theAddress"));
// cls_BRepSweep_Revol.def_static("operator new_", (void * (*)(size_t, void *)) &BRepSweep_Revol::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepSweep_Revol.def_static("operator delete_", (void (*)(void *, void *)) &BRepSweep_Revol::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepSweep_Revol.def("Shape", (TopoDS_Shape (BRepSweep_Revol::*)()) &BRepSweep_Revol::Shape, "Returns the TopoDS Shape attached to the Revol.");
cls_BRepSweep_Revol.def("Shape", (TopoDS_Shape (BRepSweep_Revol::*)(const TopoDS_Shape &)) &BRepSweep_Revol::Shape, "Returns the TopoDS Shape generated with aGenS (subShape of the generating shape).", py::arg("aGenS"));
cls_BRepSweep_Revol.def("FirstShape", (TopoDS_Shape (BRepSweep_Revol::*)()) &BRepSweep_Revol::FirstShape, "Returns the first shape of the revol (coinciding with the generating shape).");
cls_BRepSweep_Revol.def("FirstShape", (TopoDS_Shape (BRepSweep_Revol::*)(const TopoDS_Shape &)) &BRepSweep_Revol::FirstShape, "Returns the first shape of the revol (coinciding with the generating shape).", py::arg("aGenS"));
cls_BRepSweep_Revol.def("LastShape", (TopoDS_Shape (BRepSweep_Revol::*)()) &BRepSweep_Revol::LastShape, "Returns the TopoDS Shape of the top of the prism.");
cls_BRepSweep_Revol.def("LastShape", (TopoDS_Shape (BRepSweep_Revol::*)(const TopoDS_Shape &)) &BRepSweep_Revol::LastShape, "Returns the TopoDS Shape of the top of the prism. generated with aGenS (subShape of the generating shape).", py::arg("aGenS"));
cls_BRepSweep_Revol.def("Axe", (gp_Ax1 (BRepSweep_Revol::*)() const) &BRepSweep_Revol::Axe, "returns the axis");
cls_BRepSweep_Revol.def("Angle", (Standard_Real (BRepSweep_Revol::*)() const) &BRepSweep_Revol::Angle, "returns the angle.");
cls_BRepSweep_Revol.def("IsUsed", (Standard_Boolean (BRepSweep_Revol::*)(const TopoDS_Shape &) const) &BRepSweep_Revol::IsUsed, "Returns true if the aGenS is used in resulting Shape", py::arg("aGenS"));

// CLASS: BREPSWEEP_ITERATOR
py::class_<BRepSweep_Iterator> cls_BRepSweep_Iterator(mod, "BRepSweep_Iterator", "This class provides iteration services required by the Generating Line (TopoDS Shape) of a BRepSweep. This tool is used to iterate on the direct sub-shapes of a Shape.");

// Constructors
cls_BRepSweep_Iterator.def(py::init<>());

// Methods
// cls_BRepSweep_Iterator.def_static("operator new_", (void * (*)(size_t)) &BRepSweep_Iterator::operator new, "None", py::arg("theSize"));
// cls_BRepSweep_Iterator.def_static("operator delete_", (void (*)(void *)) &BRepSweep_Iterator::operator delete, "None", py::arg("theAddress"));
// cls_BRepSweep_Iterator.def_static("operator new[]_", (void * (*)(size_t)) &BRepSweep_Iterator::operator new[], "None", py::arg("theSize"));
// cls_BRepSweep_Iterator.def_static("operator delete[]_", (void (*)(void *)) &BRepSweep_Iterator::operator delete[], "None", py::arg("theAddress"));
// cls_BRepSweep_Iterator.def_static("operator new_", (void * (*)(size_t, void *)) &BRepSweep_Iterator::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepSweep_Iterator.def_static("operator delete_", (void (*)(void *, void *)) &BRepSweep_Iterator::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepSweep_Iterator.def("Init", (void (BRepSweep_Iterator::*)(const TopoDS_Shape &)) &BRepSweep_Iterator::Init, "Resest the Iterator on sub-shapes of <aShape>.", py::arg("aShape"));
cls_BRepSweep_Iterator.def("More", (Standard_Boolean (BRepSweep_Iterator::*)() const) &BRepSweep_Iterator::More, "Returns True if there is a current sub-shape.");
cls_BRepSweep_Iterator.def("Next", (void (BRepSweep_Iterator::*)()) &BRepSweep_Iterator::Next, "Moves to the next sub-shape.");
cls_BRepSweep_Iterator.def("Value", (const TopoDS_Shape & (BRepSweep_Iterator::*)() const) &BRepSweep_Iterator::Value, "Returns the current sub-shape.");
cls_BRepSweep_Iterator.def("Orientation", (TopAbs_Orientation (BRepSweep_Iterator::*)() const) &BRepSweep_Iterator::Orientation, "Returns the orientation of the current sub-shape.");


}
