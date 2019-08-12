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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <HLRBRep_Data.hxx>
#include <HLRBRep_Array1OfEData.hxx>
#include <HLRBRep_Array1OfFData.hxx>
#include <HLRAlgo_Projector.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <HLRAlgo_EdgesBlock.hxx>
#include <BRepTopAdaptor_MapOfShapeTool.hxx>
#include <HLRAlgo_Interference.hxx>
#include <gp_Dir2d.hxx>
#include <TopAbs_State.hxx>
#include <HLRBRep_EdgeData.hxx>
#include <HLRAlgo_InterferenceList.hxx>
#include <Standard_Type.hxx>
#include <HLRBRep_FaceData.hxx>
#include <IntRes2d_IntersectionPoint.hxx>
#include <TopAbs_Orientation.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <HLRBRep_CLProps.hxx>
#include <HLRBRep_SLProps.hxx>
#include <HLRBRep_FaceIterator.hxx>
#include <GeomAbs_SurfaceType.hxx>
#include <HLRBRep_Curve.hxx>
#include <GeomAbs_CurveType.hxx>
#include <HLRBRep_Intersector.hxx>
#include <BRepTopAdaptor_TopolTool.hxx>

void bind_HLRBRep_Data(py::module &mod){

py::class_<HLRBRep_Data, opencascade::handle<HLRBRep_Data>, Standard_Transient> cls_HLRBRep_Data(mod, "HLRBRep_Data", "None");

// Constructors
cls_HLRBRep_Data.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("NV"), py::arg("NE"), py::arg("NF"));

// Fields

// Methods
cls_HLRBRep_Data.def("Write", (void (HLRBRep_Data::*)(const opencascade::handle<HLRBRep_Data> &, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &HLRBRep_Data::Write, "Write <DS> in me with a translation of <dv>,<de>,<df>.", py::arg("DS"), py::arg("dv"), py::arg("de"), py::arg("df"));
cls_HLRBRep_Data.def("EDataArray", (HLRBRep_Array1OfEData & (HLRBRep_Data::*)()) &HLRBRep_Data::EDataArray, "None");
cls_HLRBRep_Data.def("FDataArray", (HLRBRep_Array1OfFData & (HLRBRep_Data::*)()) &HLRBRep_Data::FDataArray, "None");
cls_HLRBRep_Data.def("Tolerance", (void (HLRBRep_Data::*)(const Standard_ShortReal)) &HLRBRep_Data::Tolerance, "Set the tolerance for the rejections during the exploration", py::arg("tol"));
cls_HLRBRep_Data.def("Tolerance", (Standard_ShortReal (HLRBRep_Data::*)() const) &HLRBRep_Data::Tolerance, "returns the tolerance for the rejections during the exploration");
cls_HLRBRep_Data.def("Update", (void (HLRBRep_Data::*)(const HLRAlgo_Projector &)) &HLRBRep_Data::Update, "end of building of the Data and updating all the informations linked to the projection.", py::arg("P"));
cls_HLRBRep_Data.def("Projector", (HLRAlgo_Projector & (HLRBRep_Data::*)()) &HLRBRep_Data::Projector, "None");
cls_HLRBRep_Data.def("NbVertices", (Standard_Integer (HLRBRep_Data::*)() const) &HLRBRep_Data::NbVertices, "None");
cls_HLRBRep_Data.def("NbEdges", (Standard_Integer (HLRBRep_Data::*)() const) &HLRBRep_Data::NbEdges, "None");
cls_HLRBRep_Data.def("NbFaces", (Standard_Integer (HLRBRep_Data::*)() const) &HLRBRep_Data::NbFaces, "None");
cls_HLRBRep_Data.def("EdgeMap", (TopTools_IndexedMapOfShape & (HLRBRep_Data::*)()) &HLRBRep_Data::EdgeMap, "None");
cls_HLRBRep_Data.def("FaceMap", (TopTools_IndexedMapOfShape & (HLRBRep_Data::*)()) &HLRBRep_Data::FaceMap, "None");
cls_HLRBRep_Data.def("InitBoundSort", (void (HLRBRep_Data::*)(const HLRAlgo_EdgesBlock::MinMaxIndices &, const Standard_Integer, const Standard_Integer)) &HLRBRep_Data::InitBoundSort, "to compare with only non rejected edges.", py::arg("MinMaxTot"), py::arg("e1"), py::arg("e2"));
cls_HLRBRep_Data.def("InitEdge", (void (HLRBRep_Data::*)(const Standard_Integer, BRepTopAdaptor_MapOfShapeTool &)) &HLRBRep_Data::InitEdge, "Begin an iteration only on visible Edges crossing the face number <FI>.", py::arg("FI"), py::arg("MST"));
cls_HLRBRep_Data.def("MoreEdge", (Standard_Boolean (HLRBRep_Data::*)()) &HLRBRep_Data::MoreEdge, "None");
cls_HLRBRep_Data.def("NextEdge", [](HLRBRep_Data &self) -> void { return self.NextEdge(); });
cls_HLRBRep_Data.def("NextEdge", (void (HLRBRep_Data::*)(const Standard_Boolean)) &HLRBRep_Data::NextEdge, "None", py::arg("skip"));
cls_HLRBRep_Data.def("Edge", (Standard_Integer (HLRBRep_Data::*)() const) &HLRBRep_Data::Edge, "Returns the current Edge");
cls_HLRBRep_Data.def("HidingTheFace", (Standard_Boolean (HLRBRep_Data::*)() const) &HLRBRep_Data::HidingTheFace, "Returns true if the current edge to be hidden belongs to the hiding face.");
cls_HLRBRep_Data.def("SimpleHidingFace", (Standard_Boolean (HLRBRep_Data::*)() const) &HLRBRep_Data::SimpleHidingFace, "Returns true if the current hiding face is not an auto-intersected one.");
cls_HLRBRep_Data.def("InitInterference", (void (HLRBRep_Data::*)()) &HLRBRep_Data::InitInterference, "Intersect the current Edge with the boundary of the hiding face. The interferences are given by the More, Next, and Value methods.");
cls_HLRBRep_Data.def("MoreInterference", (Standard_Boolean (HLRBRep_Data::*)() const) &HLRBRep_Data::MoreInterference, "None");
cls_HLRBRep_Data.def("NextInterference", (void (HLRBRep_Data::*)()) &HLRBRep_Data::NextInterference, "None");
cls_HLRBRep_Data.def("RejectedInterference", (Standard_Boolean (HLRBRep_Data::*)()) &HLRBRep_Data::RejectedInterference, "Returns True if the interference is rejected.");
cls_HLRBRep_Data.def("AboveInterference", (Standard_Boolean (HLRBRep_Data::*)()) &HLRBRep_Data::AboveInterference, "Returns True if the rejected interference is above the face.");
cls_HLRBRep_Data.def("Interference", (HLRAlgo_Interference & (HLRBRep_Data::*)()) &HLRBRep_Data::Interference, "None");
cls_HLRBRep_Data.def("LocalLEGeometry2D", [](HLRBRep_Data &self, const Standard_Real Param, gp_Dir2d & Tg, gp_Dir2d & Nm, Standard_Real & Cu){ self.LocalLEGeometry2D(Param, Tg, Nm, Cu); return Cu; }, "Returns the local description of the projection of the current LEdge at parameter <Param>.", py::arg("Param"), py::arg("Tg"), py::arg("Nm"), py::arg("Cu"));
cls_HLRBRep_Data.def("LocalFEGeometry2D", [](HLRBRep_Data &self, const Standard_Integer FE, const Standard_Real Param, gp_Dir2d & Tg, gp_Dir2d & Nm, Standard_Real & Cu){ self.LocalFEGeometry2D(FE, Param, Tg, Nm, Cu); return Cu; }, "Returns the local description of the projection of the current FEdge at parameter <Param>.", py::arg("FE"), py::arg("Param"), py::arg("Tg"), py::arg("Nm"), py::arg("Cu"));
cls_HLRBRep_Data.def("EdgeState", (void (HLRBRep_Data::*)(const Standard_Real, const Standard_Real, TopAbs_State &, TopAbs_State &)) &HLRBRep_Data::EdgeState, "Returns the local 3D state of the intersection between the current edge and the current face at the <p1> and <p2> parameters.", py::arg("p1"), py::arg("p2"), py::arg("stbef"), py::arg("staf"));
cls_HLRBRep_Data.def("EdgeOfTheHidingFace", (Standard_Boolean (HLRBRep_Data::*)(const Standard_Integer, const HLRBRep_EdgeData &) const) &HLRBRep_Data::EdgeOfTheHidingFace, "Returns the true if the Edge <ED> belongs to the Hiding Face.", py::arg("E"), py::arg("ED"));
cls_HLRBRep_Data.def("HidingStartLevel", (Standard_Integer (HLRBRep_Data::*)(const Standard_Integer, const HLRBRep_EdgeData &, const HLRAlgo_InterferenceList &)) &HLRBRep_Data::HidingStartLevel, "Returns the number of levels of hiding face above the first point of the edge <ED>. The InterferenceList is given to compute far away of the Interferences and then come back.", py::arg("E"), py::arg("ED"), py::arg("IL"));
cls_HLRBRep_Data.def("Compare", (TopAbs_State (HLRBRep_Data::*)(const Standard_Integer, const HLRBRep_EdgeData &)) &HLRBRep_Data::Compare, "Returns the state of the Edge <ED> after classification.", py::arg("E"), py::arg("ED"));
cls_HLRBRep_Data.def("SimplClassify", (TopAbs_State (HLRBRep_Data::*)(const Standard_Integer, const HLRBRep_EdgeData &, const Standard_Integer, const Standard_Real, const Standard_Real)) &HLRBRep_Data::SimplClassify, "Simple classification of part of edge [p1, p2] returns OUT if at least 1 of Nbp points of edge is out othewise returns IN It is used to check 'suspision' hided part of edge.", py::arg("E"), py::arg("ED"), py::arg("Nbp"), py::arg("p1"), py::arg("p2"));
cls_HLRBRep_Data.def("Classify", [](HLRBRep_Data &self, const Standard_Integer E, const HLRBRep_EdgeData & ED, const Standard_Boolean LevelFlag, Standard_Integer & Level, const Standard_Real param){ TopAbs_State rv = self.Classify(E, ED, LevelFlag, Level, param); return std::tuple<TopAbs_State, Standard_Integer &>(rv, Level); }, "Classification of an edge.", py::arg("E"), py::arg("ED"), py::arg("LevelFlag"), py::arg("Level"), py::arg("param"));
cls_HLRBRep_Data.def("IsBadFace", (Standard_Boolean (HLRBRep_Data::*)() const) &HLRBRep_Data::IsBadFace, "Returns true if the current face is bad.");
cls_HLRBRep_Data.def("Destroy", (void (HLRBRep_Data::*)()) &HLRBRep_Data::Destroy, "None");
cls_HLRBRep_Data.def_static("get_type_name_", (const char * (*)()) &HLRBRep_Data::get_type_name, "None");
cls_HLRBRep_Data.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &HLRBRep_Data::get_type_descriptor, "None");
cls_HLRBRep_Data.def("DynamicType", (const opencascade::handle<Standard_Type> & (HLRBRep_Data::*)() const) &HLRBRep_Data::DynamicType, "None");

// Enums

}