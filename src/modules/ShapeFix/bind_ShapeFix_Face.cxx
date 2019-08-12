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
#include <ShapeFix_Root.hxx>
#include <TopoDS_Face.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <ShapeAnalysis_Surface.hxx>
#include <ShapeExtend_BasicMsgRegistrator.hxx>
#include <TopoDS_Shape.hxx>
#include <TopoDS_Wire.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <ShapeExtend_Status.hxx>
#include <ShapeFix_Wire.hxx>
#include <ShapeFix_Face.hxx>
#include <Standard_Type.hxx>
#include <ShapeExtend_WireData.hxx>
#include <TopoDS_Vertex.hxx>
#include <ShapeFix_DataMapOfShapeBox2d.hxx>

void bind_ShapeFix_Face(py::module &mod){

py::class_<ShapeFix_Face, opencascade::handle<ShapeFix_Face>, ShapeFix_Root> cls_ShapeFix_Face(mod, "ShapeFix_Face", "This operator allows to perform various fixes on face and its wires: fixes provided by ShapeFix_Wire, fixing orientation of wires, addition of natural bounds, fixing of missing seam edge, and detection and removal of null-area wires");

// Constructors
cls_ShapeFix_Face.def(py::init<>());
cls_ShapeFix_Face.def(py::init<const TopoDS_Face &>(), py::arg("face"));

// Fields

// Methods
cls_ShapeFix_Face.def("ClearModes", (void (ShapeFix_Face::*)()) &ShapeFix_Face::ClearModes, "Sets all modes to default");
cls_ShapeFix_Face.def("Init", (void (ShapeFix_Face::*)(const TopoDS_Face &)) &ShapeFix_Face::Init, "Loads a whole face already created, with its wires, sense and location", py::arg("face"));
cls_ShapeFix_Face.def("Init", [](ShapeFix_Face &self, const opencascade::handle<Geom_Surface> & a0, const Standard_Real a1) -> void { return self.Init(a0, a1); });
cls_ShapeFix_Face.def("Init", (void (ShapeFix_Face::*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Boolean)) &ShapeFix_Face::Init, "Starts the creation of the face By default it will be FORWARD, or REVERSED if <fwd> is False", py::arg("surf"), py::arg("preci"), py::arg("fwd"));
cls_ShapeFix_Face.def("Init", [](ShapeFix_Face &self, const opencascade::handle<ShapeAnalysis_Surface> & a0, const Standard_Real a1) -> void { return self.Init(a0, a1); });
cls_ShapeFix_Face.def("Init", (void (ShapeFix_Face::*)(const opencascade::handle<ShapeAnalysis_Surface> &, const Standard_Real, const Standard_Boolean)) &ShapeFix_Face::Init, "Starts the creation of the face By default it will be FORWARD, or REVERSED if <fwd> is False", py::arg("surf"), py::arg("preci"), py::arg("fwd"));
cls_ShapeFix_Face.def("SetMsgRegistrator", (void (ShapeFix_Face::*)(const opencascade::handle<ShapeExtend_BasicMsgRegistrator> &)) &ShapeFix_Face::SetMsgRegistrator, "Sets message registrator", py::arg("msgreg"));
cls_ShapeFix_Face.def("SetPrecision", (void (ShapeFix_Face::*)(const Standard_Real)) &ShapeFix_Face::SetPrecision, "Sets basic precision value (also to FixWireTool)", py::arg("preci"));
cls_ShapeFix_Face.def("SetMinTolerance", (void (ShapeFix_Face::*)(const Standard_Real)) &ShapeFix_Face::SetMinTolerance, "Sets minimal allowed tolerance (also to FixWireTool)", py::arg("mintol"));
cls_ShapeFix_Face.def("SetMaxTolerance", (void (ShapeFix_Face::*)(const Standard_Real)) &ShapeFix_Face::SetMaxTolerance, "Sets maximal allowed tolerance (also to FixWireTool)", py::arg("maxtol"));
cls_ShapeFix_Face.def("FixWireMode", (Standard_Integer & (ShapeFix_Face::*)()) &ShapeFix_Face::FixWireMode, "Returns (modifiable) the mode for applying fixes of ShapeFix_Wire, by default True.");
cls_ShapeFix_Face.def("FixOrientationMode", (Standard_Integer & (ShapeFix_Face::*)()) &ShapeFix_Face::FixOrientationMode, "Returns (modifiable) the fix orientation mode, by default True. If True, wires oriented to border limited square.");
cls_ShapeFix_Face.def("FixAddNaturalBoundMode", (Standard_Integer & (ShapeFix_Face::*)()) &ShapeFix_Face::FixAddNaturalBoundMode, "Returns (modifiable) the add natural bound mode. If true, natural boundary is added on faces that miss them. Default is False for faces with single wire (they are handled by FixOrientation in that case) and True for others.");
cls_ShapeFix_Face.def("FixMissingSeamMode", (Standard_Integer & (ShapeFix_Face::*)()) &ShapeFix_Face::FixMissingSeamMode, "Returns (modifiable) the fix missing seam mode, by default True. If True, tries to insert seam is missed.");
cls_ShapeFix_Face.def("FixSmallAreaWireMode", (Standard_Integer & (ShapeFix_Face::*)()) &ShapeFix_Face::FixSmallAreaWireMode, "Returns (modifiable) the fix small area wire mode, by default False. If True, drops small wires.");
cls_ShapeFix_Face.def("RemoveSmallAreaFaceMode", (Standard_Integer & (ShapeFix_Face::*)()) &ShapeFix_Face::RemoveSmallAreaFaceMode, "Returns (modifiable) the remove face with small area, by default False. If True, drops faces with small outer wires.");
cls_ShapeFix_Face.def("FixIntersectingWiresMode", (Standard_Integer & (ShapeFix_Face::*)()) &ShapeFix_Face::FixIntersectingWiresMode, "Returns (modifiable) the fix intersecting wires mode by default True.");
cls_ShapeFix_Face.def("FixLoopWiresMode", (Standard_Integer & (ShapeFix_Face::*)()) &ShapeFix_Face::FixLoopWiresMode, "Returns (modifiable) the fix loop wires mode by default True.");
cls_ShapeFix_Face.def("FixSplitFaceMode", (Standard_Integer & (ShapeFix_Face::*)()) &ShapeFix_Face::FixSplitFaceMode, "Returns (modifiable) the fix split face mode by default True.");
cls_ShapeFix_Face.def("AutoCorrectPrecisionMode", (Standard_Integer & (ShapeFix_Face::*)()) &ShapeFix_Face::AutoCorrectPrecisionMode, "Returns (modifiable) the auto-correct precision mode by default False.");
cls_ShapeFix_Face.def("FixPeriodicDegeneratedMode", (Standard_Integer & (ShapeFix_Face::*)()) &ShapeFix_Face::FixPeriodicDegeneratedMode, "Returns (modifiable) the activation flag for periodic degenerated fix. False by default.");
cls_ShapeFix_Face.def("Face", (TopoDS_Face (ShapeFix_Face::*)() const) &ShapeFix_Face::Face, "Returns a face which corresponds to the current state Warning: The finally produced face may be another one ... but with the same support");
cls_ShapeFix_Face.def("Result", (TopoDS_Shape (ShapeFix_Face::*)() const) &ShapeFix_Face::Result, "Returns resulting shape (Face or Shell if splitted) To be used instead of Face() if FixMissingSeam involved");
cls_ShapeFix_Face.def("Add", (void (ShapeFix_Face::*)(const TopoDS_Wire &)) &ShapeFix_Face::Add, "Add a wire to current face using BRep_Builder. Wire is added without taking into account orientation of face (as if face were FORWARD).", py::arg("wire"));
cls_ShapeFix_Face.def("Perform", (Standard_Boolean (ShapeFix_Face::*)()) &ShapeFix_Face::Perform, "Performs all the fixes, depending on modes Function Status returns the status of last call to Perform() ShapeExtend_OK : face was OK, nothing done ShapeExtend_DONE1: some wires are fixed ShapeExtend_DONE2: orientation of wires fixed ShapeExtend_DONE3: missing seam added ShapeExtend_DONE4: small area wire removed ShapeExtend_DONE5: natural bounds added ShapeExtend_FAIL1: some fails during fixing wires ShapeExtend_FAIL2: cannot fix orientation of wires ShapeExtend_FAIL3: cannot add missing seam ShapeExtend_FAIL4: cannot remove small area wire");
cls_ShapeFix_Face.def("FixOrientation", (Standard_Boolean (ShapeFix_Face::*)()) &ShapeFix_Face::FixOrientation, "Fixes orientation of wires on the face It tries to make all wires lie outside all others (according to orientation) by reversing orientation of some of them. If face lying on sphere or torus has single wire and AddNaturalBoundMode is True, that wire is not reversed in any case (supposing that natural bound will be added). Returns True if wires were reversed");
cls_ShapeFix_Face.def("FixOrientation", (Standard_Boolean (ShapeFix_Face::*)(TopTools_DataMapOfShapeListOfShape &)) &ShapeFix_Face::FixOrientation, "Fixes orientation of wires on the face It tries to make all wires lie outside all others (according to orientation) by reversing orientation of some of them. If face lying on sphere or torus has single wire and AddNaturalBoundMode is True, that wire is not reversed in any case (supposing that natural bound will be added). Returns True if wires were reversed OutWires return information about out wires + list of internal wires for each (for performing split face).", py::arg("MapWires"));
cls_ShapeFix_Face.def("FixAddNaturalBound", (Standard_Boolean (ShapeFix_Face::*)()) &ShapeFix_Face::FixAddNaturalBound, "Adds natural boundary on face if it is missing. Two cases are supported: - face has no wires - face lies on geometrically double-closed surface (sphere or torus) and none of wires is left-oriented Returns True if natural boundary was added");
cls_ShapeFix_Face.def("FixMissingSeam", (Standard_Boolean (ShapeFix_Face::*)()) &ShapeFix_Face::FixMissingSeam, "Detects and fixes the special case when face on a closed surface is given by two wires closed in 3d but with gap in 2d. In that case it creates a new wire from the two, and adds a missing seam edge Returns True if missing seam was added");
cls_ShapeFix_Face.def("FixSmallAreaWire", (Standard_Boolean (ShapeFix_Face::*)(const Standard_Boolean)) &ShapeFix_Face::FixSmallAreaWire, "Detects wires with small area (that is less than 100*Precision::PConfusion(). Removes these wires if they are internal. Returns : True if at least one small wire removed, False if does nothing.", py::arg("theIsRemoveSmallFace"));
cls_ShapeFix_Face.def("FixLoopWire", (Standard_Boolean (ShapeFix_Face::*)(TopTools_SequenceOfShape &)) &ShapeFix_Face::FixLoopWire, "Detects if wire has a loop and fixes this situation by splitting on the few parts. if wire has a loops and it was splitted Status was set to value ShapeExtend_DONE6.", py::arg("aResWires"));
cls_ShapeFix_Face.def("FixIntersectingWires", (Standard_Boolean (ShapeFix_Face::*)()) &ShapeFix_Face::FixIntersectingWires, "Detects and fixes the special case when face has more than one wire and this wires have intersection point");
cls_ShapeFix_Face.def("FixWiresTwoCoincEdges", (Standard_Boolean (ShapeFix_Face::*)()) &ShapeFix_Face::FixWiresTwoCoincEdges, "If wire contains two coincidence edges it must be removed Queries on status after Perform()");
cls_ShapeFix_Face.def("FixSplitFace", (Standard_Boolean (ShapeFix_Face::*)(const TopTools_DataMapOfShapeListOfShape &)) &ShapeFix_Face::FixSplitFace, "Split face if there are more than one out wire using inrormation after FixOrientation()", py::arg("MapWires"));
cls_ShapeFix_Face.def("FixPeriodicDegenerated", (Standard_Boolean (ShapeFix_Face::*)()) &ShapeFix_Face::FixPeriodicDegenerated, "Fixes topology for a specific case when face is composed by a single wire belting a periodic surface. In that case a degenerated edge is reconstructed in the degenerated pole of the surface. Initial wire gets consistent orientation. Must be used in couple and before FixMissingSeam routine");
cls_ShapeFix_Face.def("Status", (Standard_Boolean (ShapeFix_Face::*)(const ShapeExtend_Status) const) &ShapeFix_Face::Status, "Returns the status of last call to Perform() ShapeExtend_OK : face was OK, nothing done ShapeExtend_DONE1: some wires are fixed ShapeExtend_DONE2: orientation of wires fixed ShapeExtend_DONE3: missing seam added ShapeExtend_DONE4: small area wire removed ShapeExtend_DONE5: natural bounds added ShapeExtend_DONE8: face may be splited ShapeExtend_FAIL1: some fails during fixing wires ShapeExtend_FAIL2: cannot fix orientation of wires ShapeExtend_FAIL3: cannot add missing seam ShapeExtend_FAIL4: cannot remove small area wire", py::arg("status"));
cls_ShapeFix_Face.def("FixWireTool", (opencascade::handle<ShapeFix_Wire> (ShapeFix_Face::*)()) &ShapeFix_Face::FixWireTool, "Returns tool for fixing wires.");
cls_ShapeFix_Face.def_static("get_type_name_", (const char * (*)()) &ShapeFix_Face::get_type_name, "None");
cls_ShapeFix_Face.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &ShapeFix_Face::get_type_descriptor, "None");
cls_ShapeFix_Face.def("DynamicType", (const opencascade::handle<Standard_Type> & (ShapeFix_Face::*)() const) &ShapeFix_Face::DynamicType, "None");

// Enums

}