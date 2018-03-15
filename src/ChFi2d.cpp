/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <ChFi2d_ConstructionError.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <Standard_TypeDef.hxx>
#include <TopTools_SequenceOfShape.hxx>
#include <ChFi2d_Builder.hxx>
#include <ChFi2d.hxx>
#include <TopoDS_Wire.hxx>
#include <gp_Pln.hxx>
#include <ChFi2d_AnaFilletAlgo.hxx>
#include <ChFi2d_ChamferAPI.hxx>
#include <gp_Pnt2d.hxx>
#include <ChFi2d_FilletAlgo.hxx>
#include <gp_Pnt.hxx>
#include <ChFi2d_FilletAPI.hxx>

PYBIND11_MODULE(ChFi2d, mod) {

	// IMPORT
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.gp");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi2d_ConstructionError.hxx
	py::enum_<ChFi2d_ConstructionError>(mod, "ChFi2d_ConstructionError", "error that can occur during the fillet construction on planar wire//! the face is not planar//! the face is null//! the two faces used for the initialisation are uncompatible.//! the parameters as distances or angle for chamfer are less or equal to zero.//! the initialization has been succesfull.//! the algorithm could not find a solution.//! the vertex given to locate the fillet or the chamfer is not connected to 2 edges.//! the two edges connected to the vertex are tangent.//! the first edge is degenerated.//! the last edge is degenerated.//! the two edges are degenerated.//! One or the two edges connected to the vertex is a fillet or a chamfer One or the two edges connected to the vertex is not a line or a circle")
		.value("ChFi2d_NotPlanar", ChFi2d_ConstructionError::ChFi2d_NotPlanar)
		.value("ChFi2d_NoFace", ChFi2d_ConstructionError::ChFi2d_NoFace)
		.value("ChFi2d_InitialisationError", ChFi2d_ConstructionError::ChFi2d_InitialisationError)
		.value("ChFi2d_ParametersError", ChFi2d_ConstructionError::ChFi2d_ParametersError)
		.value("ChFi2d_Ready", ChFi2d_ConstructionError::ChFi2d_Ready)
		.value("ChFi2d_IsDone", ChFi2d_ConstructionError::ChFi2d_IsDone)
		.value("ChFi2d_ComputationError", ChFi2d_ConstructionError::ChFi2d_ComputationError)
		.value("ChFi2d_ConnexionError", ChFi2d_ConstructionError::ChFi2d_ConnexionError)
		.value("ChFi2d_TangencyError", ChFi2d_ConstructionError::ChFi2d_TangencyError)
		.value("ChFi2d_FirstEdgeDegenerated", ChFi2d_ConstructionError::ChFi2d_FirstEdgeDegenerated)
		.value("ChFi2d_LastEdgeDegenerated", ChFi2d_ConstructionError::ChFi2d_LastEdgeDegenerated)
		.value("ChFi2d_BothEdgesDegenerated", ChFi2d_ConstructionError::ChFi2d_BothEdgesDegenerated)
		.value("ChFi2d_NotAuthorized", ChFi2d_ConstructionError::ChFi2d_NotAuthorized)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi2d_Builder.hxx
	py::class_<ChFi2d_Builder, std::unique_ptr<ChFi2d_Builder, Deleter<ChFi2d_Builder>>> cls_ChFi2d_Builder(mod, "ChFi2d_Builder", "This class contains the algorithm used to build fillet on planar wire.");
	cls_ChFi2d_Builder.def(py::init<>());
	cls_ChFi2d_Builder.def(py::init<const TopoDS_Face &>(), py::arg("F"));
	cls_ChFi2d_Builder.def("Init", (void (ChFi2d_Builder::*)(const TopoDS_Face &)) &ChFi2d_Builder::Init, "None", py::arg("F"));
	cls_ChFi2d_Builder.def("Init", (void (ChFi2d_Builder::*)(const TopoDS_Face &, const TopoDS_Face &)) &ChFi2d_Builder::Init, "None", py::arg("RefFace"), py::arg("ModFace"));
	cls_ChFi2d_Builder.def("AddFillet", (TopoDS_Edge (ChFi2d_Builder::*)(const TopoDS_Vertex &, const Standard_Real)) &ChFi2d_Builder::AddFillet, "Add a fillet of radius <Radius> on the wire between the two edges connected to the vertex <V>. <AddFillet> returns the fillet edge. The returned edge has sense only if the status <status> is <IsDone>", py::arg("V"), py::arg("Radius"));
	cls_ChFi2d_Builder.def("ModifyFillet", (TopoDS_Edge (ChFi2d_Builder::*)(const TopoDS_Edge &, const Standard_Real)) &ChFi2d_Builder::ModifyFillet, "modify the fillet radius and return the new fillet edge. this edge has sense only if the status <status> is <IsDone>.", py::arg("Fillet"), py::arg("Radius"));
	cls_ChFi2d_Builder.def("RemoveFillet", (TopoDS_Vertex (ChFi2d_Builder::*)(const TopoDS_Edge &)) &ChFi2d_Builder::RemoveFillet, "removes the fillet <Fillet> and returns the vertex connecting the two adjacent edges to this fillet.", py::arg("Fillet"));
	cls_ChFi2d_Builder.def("AddChamfer", (TopoDS_Edge (ChFi2d_Builder::*)(const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const Standard_Real)) &ChFi2d_Builder::AddChamfer, "Add a chamfer on the wire between the two edges connected <E1> and <E2>. <AddChamfer> returns the chamfer edge. This edge has sense only if the status <status> is <IsDone>.", py::arg("E1"), py::arg("E2"), py::arg("D1"), py::arg("D2"));
	cls_ChFi2d_Builder.def("AddChamfer", (TopoDS_Edge (ChFi2d_Builder::*)(const TopoDS_Edge &, const TopoDS_Vertex &, const Standard_Real, const Standard_Real)) &ChFi2d_Builder::AddChamfer, "Add a chamfer on the wire between the two edges connected to the vertex <V>. The chamfer will make an angle <Ang> with the edge <E>, and one of its extremities will be on <E> at distance <D>. The returned edge has sense only if the status <status> is <IsDone>. Warning: The value of <Ang> must be expressed in Radian.", py::arg("E"), py::arg("V"), py::arg("D"), py::arg("Ang"));
	cls_ChFi2d_Builder.def("ModifyChamfer", (TopoDS_Edge (ChFi2d_Builder::*)(const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const Standard_Real)) &ChFi2d_Builder::ModifyChamfer, "modify the chamfer <Chamfer> and returns the new chamfer edge. This edge as sense only if the status <status> is <IsDone>.", py::arg("Chamfer"), py::arg("E1"), py::arg("E2"), py::arg("D1"), py::arg("D2"));
	cls_ChFi2d_Builder.def("ModifyChamfer", (TopoDS_Edge (ChFi2d_Builder::*)(const TopoDS_Edge &, const TopoDS_Edge &, const Standard_Real, const Standard_Real)) &ChFi2d_Builder::ModifyChamfer, "modify the chamfer <Chamfer> and returns the new chamfer edge. This edge as sense only if the status <status> is <IsDone>. Warning: The value of <Ang> must be expressed in Radian.", py::arg("Chamfer"), py::arg("E"), py::arg("D"), py::arg("Ang"));
	cls_ChFi2d_Builder.def("RemoveChamfer", (TopoDS_Vertex (ChFi2d_Builder::*)(const TopoDS_Edge &)) &ChFi2d_Builder::RemoveChamfer, "removes the chamfer <Chamfer> and returns the vertex connecting the two adjacent edges to this chamfer.", py::arg("Chamfer"));
	cls_ChFi2d_Builder.def("Result", (TopoDS_Face (ChFi2d_Builder::*)() const ) &ChFi2d_Builder::Result, "returns the modified face");
	cls_ChFi2d_Builder.def("IsModified", (Standard_Boolean (ChFi2d_Builder::*)(const TopoDS_Edge &) const ) &ChFi2d_Builder::IsModified, "None", py::arg("E"));
	cls_ChFi2d_Builder.def("FilletEdges", (const TopTools_SequenceOfShape & (ChFi2d_Builder::*)() const ) &ChFi2d_Builder::FilletEdges, "returns the list of new edges");
	cls_ChFi2d_Builder.def("NbFillet", (Standard_Integer (ChFi2d_Builder::*)() const ) &ChFi2d_Builder::NbFillet, "None");
	cls_ChFi2d_Builder.def("ChamferEdges", (const TopTools_SequenceOfShape & (ChFi2d_Builder::*)() const ) &ChFi2d_Builder::ChamferEdges, "returns the list of new edges");
	cls_ChFi2d_Builder.def("NbChamfer", (Standard_Integer (ChFi2d_Builder::*)() const ) &ChFi2d_Builder::NbChamfer, "None");
	cls_ChFi2d_Builder.def("HasDescendant", (Standard_Boolean (ChFi2d_Builder::*)(const TopoDS_Edge &) const ) &ChFi2d_Builder::HasDescendant, "None", py::arg("E"));
	cls_ChFi2d_Builder.def("DescendantEdge", (const TopoDS_Edge & (ChFi2d_Builder::*)(const TopoDS_Edge &) const ) &ChFi2d_Builder::DescendantEdge, "returns the modified edge if <E> has descendant or <E> in the other case.", py::arg("E"));
	cls_ChFi2d_Builder.def("BasisEdge", (const TopoDS_Edge & (ChFi2d_Builder::*)(const TopoDS_Edge &) const ) &ChFi2d_Builder::BasisEdge, "Returns the parent edge of <E> Warning: If <E>is a basis edge, the returned edge would be equal to <E>", py::arg("E"));
	cls_ChFi2d_Builder.def("Status", (ChFi2d_ConstructionError (ChFi2d_Builder::*)() const ) &ChFi2d_Builder::Status, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi2d.hxx
	py::class_<ChFi2d, std::unique_ptr<ChFi2d, Deleter<ChFi2d>>> cls_ChFi2d(mod, "ChFi2d", "This package contains the algorithms used to build fillets or chamfers on planar wire.");
	cls_ChFi2d.def(py::init<>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi2d_AnaFilletAlgo.hxx
	py::class_<ChFi2d_AnaFilletAlgo, std::unique_ptr<ChFi2d_AnaFilletAlgo, Deleter<ChFi2d_AnaFilletAlgo>>> cls_ChFi2d_AnaFilletAlgo(mod, "ChFi2d_AnaFilletAlgo", "An analytical algorithm for calculation of the fillets. It is implemented for segments and arcs of circle only.");
	cls_ChFi2d_AnaFilletAlgo.def(py::init<>());
	cls_ChFi2d_AnaFilletAlgo.def(py::init<const TopoDS_Wire &, const gp_Pln &>(), py::arg("theWire"), py::arg("thePlane"));
	cls_ChFi2d_AnaFilletAlgo.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const gp_Pln &>(), py::arg("theEdge1"), py::arg("theEdge2"), py::arg("thePlane"));
	cls_ChFi2d_AnaFilletAlgo.def("Init", (void (ChFi2d_AnaFilletAlgo::*)(const TopoDS_Wire &, const gp_Pln &)) &ChFi2d_AnaFilletAlgo::Init, "Initializes the class by a wire consisting of two edges.", py::arg("theWire"), py::arg("thePlane"));
	cls_ChFi2d_AnaFilletAlgo.def("Init", (void (ChFi2d_AnaFilletAlgo::*)(const TopoDS_Edge &, const TopoDS_Edge &, const gp_Pln &)) &ChFi2d_AnaFilletAlgo::Init, "Initializes the class by two edges.", py::arg("theEdge1"), py::arg("theEdge2"), py::arg("thePlane"));
	cls_ChFi2d_AnaFilletAlgo.def("Perform", (Standard_Boolean (ChFi2d_AnaFilletAlgo::*)(const Standard_Real)) &ChFi2d_AnaFilletAlgo::Perform, "Calculates a fillet.", py::arg("radius"));
	cls_ChFi2d_AnaFilletAlgo.def("Result", (const TopoDS_Edge & (ChFi2d_AnaFilletAlgo::*)(TopoDS_Edge &, TopoDS_Edge &)) &ChFi2d_AnaFilletAlgo::Result, "Retrieves a result (fillet and shrinked neighbours).", py::arg("e1"), py::arg("e2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi2d_ChamferAPI.hxx
	py::class_<ChFi2d_ChamferAPI, std::unique_ptr<ChFi2d_ChamferAPI, Deleter<ChFi2d_ChamferAPI>>> cls_ChFi2d_ChamferAPI(mod, "ChFi2d_ChamferAPI", "A class making a chamfer between two linear edges.");
	cls_ChFi2d_ChamferAPI.def(py::init<>());
	cls_ChFi2d_ChamferAPI.def(py::init<const TopoDS_Wire &>(), py::arg("theWire"));
	cls_ChFi2d_ChamferAPI.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &>(), py::arg("theEdge1"), py::arg("theEdge2"));
	cls_ChFi2d_ChamferAPI.def("Init", (void (ChFi2d_ChamferAPI::*)(const TopoDS_Wire &)) &ChFi2d_ChamferAPI::Init, "Initializes the class by a wire consisting of two libear edges.", py::arg("theWire"));
	cls_ChFi2d_ChamferAPI.def("Init", (void (ChFi2d_ChamferAPI::*)(const TopoDS_Edge &, const TopoDS_Edge &)) &ChFi2d_ChamferAPI::Init, "Initializes the class by two linear edges.", py::arg("theEdge1"), py::arg("theEdge2"));
	cls_ChFi2d_ChamferAPI.def("Perform", (Standard_Boolean (ChFi2d_ChamferAPI::*)()) &ChFi2d_ChamferAPI::Perform, "Constructs a chamfer edge. Returns true if the edge is constructed.");
	cls_ChFi2d_ChamferAPI.def("Result", (TopoDS_Edge (ChFi2d_ChamferAPI::*)(TopoDS_Edge &, TopoDS_Edge &, const Standard_Real, const Standard_Real)) &ChFi2d_ChamferAPI::Result, "None", py::arg("theEdge1"), py::arg("theEdge2"), py::arg("theLength1"), py::arg("theLength2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi2d_FilletAlgo.hxx
	py::class_<FilletPoint, std::unique_ptr<FilletPoint, Deleter<FilletPoint>>> cls_FilletPoint(mod, "FilletPoint", "Private class. Corresponds to the point on the first curve, computed fillet function and derivative on it.");
	// cls_FilletPoint.def(py::init<const Standard_Real>(), py::arg("theParam"));
	cls_FilletPoint.def("setParam", (void (FilletPoint::*)(Standard_Real)) &FilletPoint::setParam, "Changes the point position by changing point parameter on the first curve.", py::arg("theParam"));
	cls_FilletPoint.def("getParam", (Standard_Real (FilletPoint::*)() const ) &FilletPoint::getParam, "Returns the point parameter on the first curve.");
	cls_FilletPoint.def("getNBValues", (Standard_Integer (FilletPoint::*)()) &FilletPoint::getNBValues, "Returns number of found values of function in this point.");
	cls_FilletPoint.def("getValue", (Standard_Real (FilletPoint::*)(int)) &FilletPoint::getValue, "Returns value of function in this point.", py::arg("theIndex"));
	cls_FilletPoint.def("getDiff", (Standard_Real (FilletPoint::*)(int)) &FilletPoint::getDiff, "Returns derivatives of function in this point.", py::arg("theIndex"));
	cls_FilletPoint.def("isValid", (Standard_Boolean (FilletPoint::*)(int)) &FilletPoint::isValid, "Returns true if function is valid (rediuses vectors of fillet do not intersect any curve).", py::arg("theIndex"));
	cls_FilletPoint.def("getNear", (int (FilletPoint::*)(int)) &FilletPoint::getNear, "Returns the index of the nearest value", py::arg("theIndex"));
	cls_FilletPoint.def("setParam2", (void (FilletPoint::*)(const Standard_Real)) &FilletPoint::setParam2, "Defines the parameter of the projected point on the second curve.", py::arg("theParam2"));
	cls_FilletPoint.def("getParam2", (Standard_Real (FilletPoint::*)()) &FilletPoint::getParam2, "Returns the parameter of the projected point on the second curve.");
	cls_FilletPoint.def("setCenter", (void (FilletPoint::*)(const gp_Pnt2d)) &FilletPoint::setCenter, "Center of the fillet.", py::arg("thePoint"));
	cls_FilletPoint.def("getCenter", (const gp_Pnt2d (FilletPoint::*)()) &FilletPoint::getCenter, "Center of the fillet.");
	// cls_FilletPoint.def("appendValue", (void (FilletPoint::*)(Standard_Real, Standard_Boolean)) &FilletPoint::appendValue, "Appends value of the function.", py::arg("theValue"), py::arg("theValid"));
	// cls_FilletPoint.def("calculateDiff", (Standard_Boolean (FilletPoint::*)(FilletPoint *)) &FilletPoint::calculateDiff, "Computes difference between this point and the given. Stores difference in myD.", py::arg(""));
	// cls_FilletPoint.def("FilterPoints", (void (FilletPoint::*)(FilletPoint *)) &FilletPoint::FilterPoints, "Filters out the values and leaves the most optimal one.", py::arg(""));
	// cls_FilletPoint.def("Copy", (FilletPoint * (FilletPoint::*)()) &FilletPoint::Copy, "Returns a pointer to created copy of the point warning: this is not the full copy! Copies only: myParam, myV, myD, myValid");
	// cls_FilletPoint.def("hasSolution", (Standard_Integer (FilletPoint::*)(Standard_Real)) &FilletPoint::hasSolution, "Returns the index of the solution or zero if there is no solution", py::arg("theRadius"));
	cls_FilletPoint.def("LowerValue", (Standard_Real (FilletPoint::*)()) &FilletPoint::LowerValue, "For debug only");
	// cls_FilletPoint.def("remove", (void (FilletPoint::*)(Standard_Integer)) &FilletPoint::remove, "Removes the found value by the given index.", py::arg("theIndex"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi2d_FilletAlgo.hxx
	py::class_<ChFi2d_FilletAlgo, std::unique_ptr<ChFi2d_FilletAlgo, Deleter<ChFi2d_FilletAlgo>>> cls_ChFi2d_FilletAlgo(mod, "ChFi2d_FilletAlgo", "Algorithm that creates fillet edge: arc tangent to two edges in the start and in the end vertices. Initial edges must be located on the plane and must be connected by the end or start points (shared vertices are not obligatory). Created fillet arc is created with the given radius, that is useful in sketcher applications.");
	cls_ChFi2d_FilletAlgo.def(py::init<>());
	cls_ChFi2d_FilletAlgo.def(py::init<const TopoDS_Wire &, const gp_Pln &>(), py::arg("theWire"), py::arg("thePlane"));
	cls_ChFi2d_FilletAlgo.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const gp_Pln &>(), py::arg("theEdge1"), py::arg("theEdge2"), py::arg("thePlane"));
	cls_ChFi2d_FilletAlgo.def("Init", (void (ChFi2d_FilletAlgo::*)(const TopoDS_Wire &, const gp_Pln &)) &ChFi2d_FilletAlgo::Init, "Initializes a fillet algorithm: accepts a wire consisting of two edges in a plane.", py::arg("theWire"), py::arg("thePlane"));
	cls_ChFi2d_FilletAlgo.def("Init", (void (ChFi2d_FilletAlgo::*)(const TopoDS_Edge &, const TopoDS_Edge &, const gp_Pln &)) &ChFi2d_FilletAlgo::Init, "Initializes a fillet algorithm: accepts two edges in a plane.", py::arg("theEdge1"), py::arg("theEdge2"), py::arg("thePlane"));
	cls_ChFi2d_FilletAlgo.def("Perform", (Standard_Boolean (ChFi2d_FilletAlgo::*)(const Standard_Real)) &ChFi2d_FilletAlgo::Perform, "Constructs a fillet edge. Returns true, if at least one result was found", py::arg("theRadius"));
	cls_ChFi2d_FilletAlgo.def("NbResults", (Standard_Integer (ChFi2d_FilletAlgo::*)(const gp_Pnt &)) &ChFi2d_FilletAlgo::NbResults, "Returns number of possible solutions. <thePoint> chooses a particular fillet in case of several fillets may be constructed (for example, a circle intersecting a segment in 2 points). Put the intersecting (or common) point of the edges.", py::arg("thePoint"));
	cls_ChFi2d_FilletAlgo.def("Result", [](ChFi2d_FilletAlgo &self, const gp_Pnt & a0, TopoDS_Edge & a1, TopoDS_Edge & a2) -> TopoDS_Edge { return self.Result(a0, a1, a2); }, py::arg("thePoint"), py::arg("theEdge1"), py::arg("theEdge2"));
	cls_ChFi2d_FilletAlgo.def("Result", (TopoDS_Edge (ChFi2d_FilletAlgo::*)(const gp_Pnt &, TopoDS_Edge &, TopoDS_Edge &, const Standard_Integer)) &ChFi2d_FilletAlgo::Result, "Returns result (fillet edge, modified edge1, modified edge2), nearest to the given point <thePoint> if iSolution == -1. <thePoint> chooses a particular fillet in case of several fillets may be constructed (for example, a circle intersecting a segment in 2 points). Put the intersecting (or common) point of the edges.", py::arg("thePoint"), py::arg("theEdge1"), py::arg("theEdge2"), py::arg("iSolution"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ChFi2d_FilletAPI.hxx
	py::class_<ChFi2d_FilletAPI, std::unique_ptr<ChFi2d_FilletAPI, Deleter<ChFi2d_FilletAPI>>> cls_ChFi2d_FilletAPI(mod, "ChFi2d_FilletAPI", "An interface class for 2D fillets. Open CASCADE provides two algorithms for 2D fillets: ChFi2d_Builder - it constructs a fillet or chamfer for linear and circular edges of a face. ChFi2d_FilletAPI - it encapsulates two algorithms: ChFi2d_AnaFilletAlgo - analytical constructor of the fillet. It works only for linear and circular edges, having a common point. ChFi2d_FilletAlgo - iteration recursive method constructing the fillet edge for any type of edges including ellipses and b-splines. The edges may even have no common point.");
	cls_ChFi2d_FilletAPI.def(py::init<>());
	cls_ChFi2d_FilletAPI.def(py::init<const TopoDS_Wire &, const gp_Pln &>(), py::arg("theWire"), py::arg("thePlane"));
	cls_ChFi2d_FilletAPI.def(py::init<const TopoDS_Edge &, const TopoDS_Edge &, const gp_Pln &>(), py::arg("theEdge1"), py::arg("theEdge2"), py::arg("thePlane"));
	cls_ChFi2d_FilletAPI.def("Init", (void (ChFi2d_FilletAPI::*)(const TopoDS_Wire &, const gp_Pln &)) &ChFi2d_FilletAPI::Init, "Initializes a fillet algorithm: accepts a wire consisting of two edges in a plane.", py::arg("theWire"), py::arg("thePlane"));
	cls_ChFi2d_FilletAPI.def("Init", (void (ChFi2d_FilletAPI::*)(const TopoDS_Edge &, const TopoDS_Edge &, const gp_Pln &)) &ChFi2d_FilletAPI::Init, "Initializes a fillet algorithm: accepts two edges in a plane.", py::arg("theEdge1"), py::arg("theEdge2"), py::arg("thePlane"));
	cls_ChFi2d_FilletAPI.def("Perform", (Standard_Boolean (ChFi2d_FilletAPI::*)(const Standard_Real)) &ChFi2d_FilletAPI::Perform, "Constructs a fillet edge. Returns true if at least one result was found.", py::arg("theRadius"));
	cls_ChFi2d_FilletAPI.def("NbResults", (Standard_Integer (ChFi2d_FilletAPI::*)(const gp_Pnt &)) &ChFi2d_FilletAPI::NbResults, "Returns number of possible solutions. <thePoint> chooses a particular fillet in case of several fillets may be constructed (for example, a circle intersecting a segment in 2 points). Put the intersecting (or common) point of the edges.", py::arg("thePoint"));
	cls_ChFi2d_FilletAPI.def("Result", [](ChFi2d_FilletAPI &self, const gp_Pnt & a0, TopoDS_Edge & a1, TopoDS_Edge & a2) -> TopoDS_Edge { return self.Result(a0, a1, a2); }, py::arg("thePoint"), py::arg("theEdge1"), py::arg("theEdge2"));
	cls_ChFi2d_FilletAPI.def("Result", (TopoDS_Edge (ChFi2d_FilletAPI::*)(const gp_Pnt &, TopoDS_Edge &, TopoDS_Edge &, const Standard_Integer)) &ChFi2d_FilletAPI::Result, "Returns result (fillet edge, modified edge1, modified edge2), nearest to the given point <thePoint> if iSolution == -1 <thePoint> chooses a particular fillet in case of several fillets may be constructed (for example, a circle intersecting a segment in 2 points). Put the intersecting (or common) point of the edges.", py::arg("thePoint"), py::arg("theEdge1"), py::arg("theEdge2"), py::arg("iSolution"));


}
