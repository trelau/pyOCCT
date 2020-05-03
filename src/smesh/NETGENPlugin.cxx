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
#include <pyOCCT_Common.hxx>

#include <SMESH_Hypothesis.hxx>
#include <SMESH_Gen.hxx>
#include <NETGENPlugin_Hypothesis.hxx>
#include <SMESH_Mesh.hxx>
#include <TopoDS_Shape.hxx>
#include <NETGENPlugin_Hypothesis_2D.hxx>
#include <NETGENPlugin_SimpleHypothesis_2D.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <SMDS_MeshElement.hxx>
#include <SMESH_subMesh.hxx>
#include <NETGENPlugin_Mesher.hxx>
#include <nglib.h>
#include <SMESH_Algo.hxx>
#include <gp_XYZ.hxx>
#include <SMDS_MeshNode.hxx>
#include <SMESH_Comment.hxx>
#include <SMESH_MesherHelper.hxx>
#include <SMESH_ProxyMesh.hxx>
#include <SMESH_ComputeError.hxx>
#include <StdMeshers_FaceSide.hxx>
#include <NETGENPlugin_NETGEN_2D.hxx>
#include <NETGENPlugin_NETGEN_2D3D.hxx>
#include <NETGENPlugin_NETGEN_2D_ONLY.hxx>
#include <NETGENPlugin_NETGEN_3D.hxx>
#include <NETGENPlugin_SimpleHypothesis_3D.hxx>

PYBIND11_MODULE(NETGENPlugin, mod) {

	// IMPORT
	py::module::import("OCCT.SMESH");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.SMDS");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.StdMeshers");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\NETGENPlugin_Hypothesis.hxx
	py::class_<NETGENPlugin_Hypothesis, std::unique_ptr<NETGENPlugin_Hypothesis, py::nodelete>, SMESH_Hypothesis> cls_NETGENPlugin_Hypothesis(mod, "NETGENPlugin_Hypothesis", "None");
	cls_NETGENPlugin_Hypothesis.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_NETGENPlugin_Hypothesis.def("SetMaxSize", (void (NETGENPlugin_Hypothesis::*)(double)) &NETGENPlugin_Hypothesis::SetMaxSize, "None", py::arg("theSize"));
	cls_NETGENPlugin_Hypothesis.def("GetMaxSize", (double (NETGENPlugin_Hypothesis::*)() const ) &NETGENPlugin_Hypothesis::GetMaxSize, "None");
	cls_NETGENPlugin_Hypothesis.def("SetMinSize", (void (NETGENPlugin_Hypothesis::*)(double)) &NETGENPlugin_Hypothesis::SetMinSize, "None", py::arg("theSize"));
	cls_NETGENPlugin_Hypothesis.def("GetMinSize", (double (NETGENPlugin_Hypothesis::*)() const ) &NETGENPlugin_Hypothesis::GetMinSize, "None");
	cls_NETGENPlugin_Hypothesis.def("SetSecondOrder", (void (NETGENPlugin_Hypothesis::*)(bool)) &NETGENPlugin_Hypothesis::SetSecondOrder, "None", py::arg("theVal"));
	cls_NETGENPlugin_Hypothesis.def("GetSecondOrder", (bool (NETGENPlugin_Hypothesis::*)() const ) &NETGENPlugin_Hypothesis::GetSecondOrder, "None");
	cls_NETGENPlugin_Hypothesis.def("SetOptimize", (void (NETGENPlugin_Hypothesis::*)(bool)) &NETGENPlugin_Hypothesis::SetOptimize, "None", py::arg("theVal"));
	cls_NETGENPlugin_Hypothesis.def("GetOptimize", (bool (NETGENPlugin_Hypothesis::*)() const ) &NETGENPlugin_Hypothesis::GetOptimize, "None");
	cls_NETGENPlugin_Hypothesis.def("SetFineness", (void (NETGENPlugin_Hypothesis::*)(NETGENPlugin_Hypothesis::Fineness)) &NETGENPlugin_Hypothesis::SetFineness, "None", py::arg("theFineness"));
	cls_NETGENPlugin_Hypothesis.def("GetFineness", (NETGENPlugin_Hypothesis::Fineness (NETGENPlugin_Hypothesis::*)() const ) &NETGENPlugin_Hypothesis::GetFineness, "None");
	cls_NETGENPlugin_Hypothesis.def("SetGrowthRate", (void (NETGENPlugin_Hypothesis::*)(double)) &NETGENPlugin_Hypothesis::SetGrowthRate, "None", py::arg("theRate"));
	cls_NETGENPlugin_Hypothesis.def("GetGrowthRate", (double (NETGENPlugin_Hypothesis::*)() const ) &NETGENPlugin_Hypothesis::GetGrowthRate, "None");
	cls_NETGENPlugin_Hypothesis.def("SetNbSegPerEdge", (void (NETGENPlugin_Hypothesis::*)(double)) &NETGENPlugin_Hypothesis::SetNbSegPerEdge, "None", py::arg("theVal"));
	cls_NETGENPlugin_Hypothesis.def("GetNbSegPerEdge", (double (NETGENPlugin_Hypothesis::*)() const ) &NETGENPlugin_Hypothesis::GetNbSegPerEdge, "None");
	cls_NETGENPlugin_Hypothesis.def("SetNbSegPerRadius", (void (NETGENPlugin_Hypothesis::*)(double)) &NETGENPlugin_Hypothesis::SetNbSegPerRadius, "None", py::arg("theVal"));
	cls_NETGENPlugin_Hypothesis.def("GetNbSegPerRadius", (double (NETGENPlugin_Hypothesis::*)() const ) &NETGENPlugin_Hypothesis::GetNbSegPerRadius, "None");
	cls_NETGENPlugin_Hypothesis.def_static("GetDefaultLocalSize_", (NETGENPlugin_Hypothesis::TLocalSize (*)()) &NETGENPlugin_Hypothesis::GetDefaultLocalSize, "None");
	cls_NETGENPlugin_Hypothesis.def("SetLocalSizeOnEntry", (void (NETGENPlugin_Hypothesis::*)(const std::string &, double)) &NETGENPlugin_Hypothesis::SetLocalSizeOnEntry, "None", py::arg("entry"), py::arg("localSize"));
	cls_NETGENPlugin_Hypothesis.def("GetLocalSizeOnEntry", (double (NETGENPlugin_Hypothesis::*)(const std::string &)) &NETGENPlugin_Hypothesis::GetLocalSizeOnEntry, "None", py::arg("entry"));
	cls_NETGENPlugin_Hypothesis.def("GetLocalSizesAndEntries", (const NETGENPlugin_Hypothesis::TLocalSize & (NETGENPlugin_Hypothesis::*)() const ) &NETGENPlugin_Hypothesis::GetLocalSizesAndEntries, "None");
	cls_NETGENPlugin_Hypothesis.def("UnsetLocalSizeOnEntry", (void (NETGENPlugin_Hypothesis::*)(const std::string &)) &NETGENPlugin_Hypothesis::UnsetLocalSizeOnEntry, "None", py::arg("entry"));
	cls_NETGENPlugin_Hypothesis.def("SetMeshSizeFile", (void (NETGENPlugin_Hypothesis::*)(const std::string &)) &NETGENPlugin_Hypothesis::SetMeshSizeFile, "None", py::arg("fileName"));
	cls_NETGENPlugin_Hypothesis.def("GetMeshSizeFile", (const std::string & (NETGENPlugin_Hypothesis::*)() const ) &NETGENPlugin_Hypothesis::GetMeshSizeFile, "None");
	cls_NETGENPlugin_Hypothesis.def("SetQuadAllowed", (void (NETGENPlugin_Hypothesis::*)(bool)) &NETGENPlugin_Hypothesis::SetQuadAllowed, "None", py::arg("theVal"));
	cls_NETGENPlugin_Hypothesis.def("GetQuadAllowed", (bool (NETGENPlugin_Hypothesis::*)() const ) &NETGENPlugin_Hypothesis::GetQuadAllowed, "None");
	cls_NETGENPlugin_Hypothesis.def("SetSurfaceCurvature", (void (NETGENPlugin_Hypothesis::*)(bool)) &NETGENPlugin_Hypothesis::SetSurfaceCurvature, "None", py::arg("theVal"));
	cls_NETGENPlugin_Hypothesis.def("GetSurfaceCurvature", (bool (NETGENPlugin_Hypothesis::*)() const ) &NETGENPlugin_Hypothesis::GetSurfaceCurvature, "None");
	cls_NETGENPlugin_Hypothesis.def("SetFuseEdges", (void (NETGENPlugin_Hypothesis::*)(bool)) &NETGENPlugin_Hypothesis::SetFuseEdges, "None", py::arg("theVal"));
	cls_NETGENPlugin_Hypothesis.def("GetFuseEdges", (bool (NETGENPlugin_Hypothesis::*)() const ) &NETGENPlugin_Hypothesis::GetFuseEdges, "None");
	cls_NETGENPlugin_Hypothesis.def_static("GetDefaultMaxSize_", (double (*)()) &NETGENPlugin_Hypothesis::GetDefaultMaxSize, "None");
	cls_NETGENPlugin_Hypothesis.def_static("GetDefaultFineness_", (NETGENPlugin_Hypothesis::Fineness (*)()) &NETGENPlugin_Hypothesis::GetDefaultFineness, "None");
	cls_NETGENPlugin_Hypothesis.def_static("GetDefaultGrowthRate_", (double (*)()) &NETGENPlugin_Hypothesis::GetDefaultGrowthRate, "None");
	cls_NETGENPlugin_Hypothesis.def_static("GetDefaultNbSegPerEdge_", (double (*)()) &NETGENPlugin_Hypothesis::GetDefaultNbSegPerEdge, "None");
	cls_NETGENPlugin_Hypothesis.def_static("GetDefaultNbSegPerRadius_", (double (*)()) &NETGENPlugin_Hypothesis::GetDefaultNbSegPerRadius, "None");
	cls_NETGENPlugin_Hypothesis.def_static("GetDefaultSecondOrder_", (bool (*)()) &NETGENPlugin_Hypothesis::GetDefaultSecondOrder, "None");
	cls_NETGENPlugin_Hypothesis.def_static("GetDefaultOptimize_", (bool (*)()) &NETGENPlugin_Hypothesis::GetDefaultOptimize, "None");
	cls_NETGENPlugin_Hypothesis.def_static("GetDefaultQuadAllowed_", (bool (*)()) &NETGENPlugin_Hypothesis::GetDefaultQuadAllowed, "None");
	cls_NETGENPlugin_Hypothesis.def_static("GetDefaultSurfaceCurvature_", (bool (*)()) &NETGENPlugin_Hypothesis::GetDefaultSurfaceCurvature, "None");
	cls_NETGENPlugin_Hypothesis.def_static("GetDefaultFuseEdges_", (bool (*)()) &NETGENPlugin_Hypothesis::GetDefaultFuseEdges, "None");
	cls_NETGENPlugin_Hypothesis.def("SaveTo", (std::ostream & (NETGENPlugin_Hypothesis::*)(std::ostream &)) &NETGENPlugin_Hypothesis::SaveTo, "None", py::arg("save"));
	cls_NETGENPlugin_Hypothesis.def("LoadFrom", (std::istream & (NETGENPlugin_Hypothesis::*)(std::istream &)) &NETGENPlugin_Hypothesis::LoadFrom, "None", py::arg("load"));
	cls_NETGENPlugin_Hypothesis.def("SetParametersByMesh", (bool (NETGENPlugin_Hypothesis::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &NETGENPlugin_Hypothesis::SetParametersByMesh, "Does nothing", py::arg("theMesh"), py::arg("theShape"));
	cls_NETGENPlugin_Hypothesis.def("SetParametersByDefaults", [](NETGENPlugin_Hypothesis &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_NETGENPlugin_Hypothesis.def("SetParametersByDefaults", (bool (NETGENPlugin_Hypothesis::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &NETGENPlugin_Hypothesis::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\NETGENPlugin_Hypothesis.hxx
	py::enum_<NETGENPlugin_Hypothesis::Fineness>(cls_NETGENPlugin_Hypothesis, "Fineness", "None")
		.value("VeryCoarse", NETGENPlugin_Hypothesis::Fineness::VeryCoarse)
		.value("Coarse", NETGENPlugin_Hypothesis::Fineness::Coarse)
		.value("Moderate", NETGENPlugin_Hypothesis::Fineness::Moderate)
		.value("Fine", NETGENPlugin_Hypothesis::Fineness::Fine)
		.value("VeryFine", NETGENPlugin_Hypothesis::Fineness::VeryFine)
		.value("UserDefined", NETGENPlugin_Hypothesis::Fineness::UserDefined)
		.export_values();

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\NETGENPlugin_Hypothesis_2D.hxx
	py::class_<NETGENPlugin_Hypothesis_2D, std::unique_ptr<NETGENPlugin_Hypothesis_2D, py::nodelete>, NETGENPlugin_Hypothesis> cls_NETGENPlugin_Hypothesis_2D(mod, "NETGENPlugin_Hypothesis_2D", "None");
	cls_NETGENPlugin_Hypothesis_2D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\NETGENPlugin_SimpleHypothesis_2D.hxx
	py::class_<NETGENPlugin_SimpleHypothesis_2D, std::unique_ptr<NETGENPlugin_SimpleHypothesis_2D, py::nodelete>, SMESH_Hypothesis> cls_NETGENPlugin_SimpleHypothesis_2D(mod, "NETGENPlugin_SimpleHypothesis_2D", "None");
	cls_NETGENPlugin_SimpleHypothesis_2D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_NETGENPlugin_SimpleHypothesis_2D.def("SetNumberOfSegments", (void (NETGENPlugin_SimpleHypothesis_2D::*)(int)) &NETGENPlugin_SimpleHypothesis_2D::SetNumberOfSegments, "Sets <number of segments> value", py::arg("nb"));
	cls_NETGENPlugin_SimpleHypothesis_2D.def("GetNumberOfSegments", (int (NETGENPlugin_SimpleHypothesis_2D::*)() const ) &NETGENPlugin_SimpleHypothesis_2D::GetNumberOfSegments, "Returns <number of segments> value. Can be zero in case if LocalLength() has been set");
	cls_NETGENPlugin_SimpleHypothesis_2D.def("SetLocalLength", (void (NETGENPlugin_SimpleHypothesis_2D::*)(double)) &NETGENPlugin_SimpleHypothesis_2D::SetLocalLength, "Sets <segment length> value", py::arg("segmentLength"));
	cls_NETGENPlugin_SimpleHypothesis_2D.def("GetLocalLength", (double (NETGENPlugin_SimpleHypothesis_2D::*)() const ) &NETGENPlugin_SimpleHypothesis_2D::GetLocalLength, "Returns <segment length> value. Can be zero in case if NumberOfSegments() has been set");
	cls_NETGENPlugin_SimpleHypothesis_2D.def("LengthFromEdges", (void (NETGENPlugin_SimpleHypothesis_2D::*)()) &NETGENPlugin_SimpleHypothesis_2D::LengthFromEdges, "Sets <maximum element area> to be dependent on 1D discretization");
	cls_NETGENPlugin_SimpleHypothesis_2D.def("SetMaxElementArea", (void (NETGENPlugin_SimpleHypothesis_2D::*)(double)) &NETGENPlugin_SimpleHypothesis_2D::SetMaxElementArea, "Sets <maximum element area> value. Zero or negative value means same as LengthFromEdges().", py::arg("area"));
	cls_NETGENPlugin_SimpleHypothesis_2D.def("GetMaxElementArea", (double (NETGENPlugin_SimpleHypothesis_2D::*)() const ) &NETGENPlugin_SimpleHypothesis_2D::GetMaxElementArea, "Returns <maximum element area> value. Can be zero in case of LengthFromEdges()");
	cls_NETGENPlugin_SimpleHypothesis_2D.def("SetAllowQuadrangles", (void (NETGENPlugin_SimpleHypothesis_2D::*)(bool)) &NETGENPlugin_SimpleHypothesis_2D::SetAllowQuadrangles, "Enables/disables generation of quadrangular faces", py::arg("toAllow"));
	cls_NETGENPlugin_SimpleHypothesis_2D.def("GetAllowQuadrangles", (bool (NETGENPlugin_SimpleHypothesis_2D::*)() const ) &NETGENPlugin_SimpleHypothesis_2D::GetAllowQuadrangles, "Returns true if generation of quadrangular faces is enabled");
	cls_NETGENPlugin_SimpleHypothesis_2D.def("SaveTo", (std::ostream & (NETGENPlugin_SimpleHypothesis_2D::*)(std::ostream &)) &NETGENPlugin_SimpleHypothesis_2D::SaveTo, "None", py::arg("save"));
	cls_NETGENPlugin_SimpleHypothesis_2D.def("LoadFrom", (std::istream & (NETGENPlugin_SimpleHypothesis_2D::*)(std::istream &)) &NETGENPlugin_SimpleHypothesis_2D::LoadFrom, "None", py::arg("load"));
	cls_NETGENPlugin_SimpleHypothesis_2D.def("SetParametersByMesh", (bool (NETGENPlugin_SimpleHypothesis_2D::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &NETGENPlugin_SimpleHypothesis_2D::SetParametersByMesh, "Set parameters by mesh", py::arg("theMesh"), py::arg("theShape"));
	cls_NETGENPlugin_SimpleHypothesis_2D.def("SetParametersByDefaults", [](NETGENPlugin_SimpleHypothesis_2D &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_NETGENPlugin_SimpleHypothesis_2D.def("SetParametersByDefaults", (bool (NETGENPlugin_SimpleHypothesis_2D::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &NETGENPlugin_SimpleHypothesis_2D::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\NETGENPlugin_Mesher.hxx
	py::class_<NETGENPlugin_Internals, std::unique_ptr<NETGENPlugin_Internals, Deleter<NETGENPlugin_Internals>>> cls_NETGENPlugin_Internals(mod, "NETGENPlugin_Internals", "Container of info needed to solve problems with internal shapes.");
	cls_NETGENPlugin_Internals.def(py::init<SMESH_Mesh &, const TopoDS_Shape &, bool>(), py::arg("mesh"), py::arg("shape"), py::arg("is3D"));
	cls_NETGENPlugin_Internals.def("getMesh", (SMESH_Mesh & (NETGENPlugin_Internals::*)() const ) &NETGENPlugin_Internals::getMesh, "None");
	cls_NETGENPlugin_Internals.def("isShapeToPrecompute", (bool (NETGENPlugin_Internals::*)(const TopoDS_Shape &)) &NETGENPlugin_Internals::isShapeToPrecompute, "None", py::arg("s"));
	cls_NETGENPlugin_Internals.def("hasInternalEdges", (bool (NETGENPlugin_Internals::*)() const ) &NETGENPlugin_Internals::hasInternalEdges, "None");
	cls_NETGENPlugin_Internals.def("isInternalEdge", (bool (NETGENPlugin_Internals::*)(int) const ) &NETGENPlugin_Internals::isInternalEdge, "None", py::arg("id"));
	cls_NETGENPlugin_Internals.def("getEdgesAndVerticesWithFaces", (const std::map<int, int> & (NETGENPlugin_Internals::*)() const ) &NETGENPlugin_Internals::getEdgesAndVerticesWithFaces, "None");
	// FIXME cls_NETGENPlugin_Internals.def("getInternalEdges", (void (NETGENPlugin_Internals::*)(TopTools_IndexedMapOfShape &, TopTools_IndexedMapOfShape &, TopTools_IndexedMapOfShape &, std::list<SMESH_subMesh *> [])) &NETGENPlugin_Internals::getInternalEdges, "None", py::arg("fmap"), py::arg("emap"), py::arg("vmap"), py::arg("smToPrecompute"));
	cls_NETGENPlugin_Internals.def("hasInternalVertexInFace", (bool (NETGENPlugin_Internals::*)() const ) &NETGENPlugin_Internals::hasInternalVertexInFace, "None");
	cls_NETGENPlugin_Internals.def("getFacesWithVertices", (const std::map<int, std::list<int> > & (NETGENPlugin_Internals::*)() const ) &NETGENPlugin_Internals::getFacesWithVertices, "None");
	cls_NETGENPlugin_Internals.def("hasInternalFaces", (bool (NETGENPlugin_Internals::*)() const ) &NETGENPlugin_Internals::hasInternalFaces, "None");
	cls_NETGENPlugin_Internals.def("isInternalShape", (bool (NETGENPlugin_Internals::*)(int) const ) &NETGENPlugin_Internals::isInternalShape, "None", py::arg("id"));
	cls_NETGENPlugin_Internals.def("findBorderElements", (void (NETGENPlugin_Internals::*)(std::set<const SMDS_MeshElement *, TIDCompare> &)) &NETGENPlugin_Internals::findBorderElements, "None", py::arg("borderElems"));
	cls_NETGENPlugin_Internals.def("isBorderFace", (bool (NETGENPlugin_Internals::*)(int) const ) &NETGENPlugin_Internals::isBorderFace, "None", py::arg("faceID"));
	cls_NETGENPlugin_Internals.def("getInternalFaces", (void (NETGENPlugin_Internals::*)(TopTools_IndexedMapOfShape &, TopTools_IndexedMapOfShape &, std::list<SMESH_subMesh *> &, std::list<SMESH_subMesh *> &)) &NETGENPlugin_Internals::getInternalFaces, "None", py::arg("fmap"), py::arg("emap"), py::arg("facesSM"), py::arg("boundarySM"));
	cls_NETGENPlugin_Internals.def("hasInternalVertexInSolid", (bool (NETGENPlugin_Internals::*)() const ) &NETGENPlugin_Internals::hasInternalVertexInSolid, "None");
	cls_NETGENPlugin_Internals.def("hasInternalVertexInSolid", (bool (NETGENPlugin_Internals::*)(int) const ) &NETGENPlugin_Internals::hasInternalVertexInSolid, "None", py::arg("soID"));
	cls_NETGENPlugin_Internals.def("getSolidsWithVertices", (const std::map<int, std::list<int> > & (NETGENPlugin_Internals::*)() const ) &NETGENPlugin_Internals::getSolidsWithVertices, "None");

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\NETGENPlugin_Mesher.hxx
	py::class_<NETGENPlugin_ngMeshInfo, std::unique_ptr<NETGENPlugin_ngMeshInfo, Deleter<NETGENPlugin_ngMeshInfo>>> cls_NETGENPlugin_ngMeshInfo(mod, "NETGENPlugin_ngMeshInfo", "Struct storing nb of entities in netgen mesh");
	cls_NETGENPlugin_ngMeshInfo.def(py::init<>());
	cls_NETGENPlugin_ngMeshInfo.def(py::init<netgen::Mesh *>(), py::arg("ngMesh"));
	cls_NETGENPlugin_ngMeshInfo.def("transferLocalH", (void (NETGENPlugin_ngMeshInfo::*)(netgen::Mesh *, netgen::Mesh *)) &NETGENPlugin_ngMeshInfo::transferLocalH, "None", py::arg("fromMesh"), py::arg("toMesh"));
	cls_NETGENPlugin_ngMeshInfo.def("restoreLocalH", (void (NETGENPlugin_ngMeshInfo::*)(netgen::Mesh *)) &NETGENPlugin_ngMeshInfo::restoreLocalH, "None", py::arg("ngMesh"));
	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\NETGENPlugin_Mesher.hxx
	py::class_<NETGENPlugin_NetgenLibWrapper, std::unique_ptr<NETGENPlugin_NetgenLibWrapper, Deleter<NETGENPlugin_NetgenLibWrapper>>> cls_NETGENPlugin_NetgenLibWrapper(mod, "NETGENPlugin_NetgenLibWrapper", "It correctly initializes netgen library at constructor and correctly finishes using netgen library at destructor");
	cls_NETGENPlugin_NetgenLibWrapper.def(py::init<>());
	// FIXME cls_NETGENPlugin_NetgenLibWrapper.def("setMesh", (void (NETGENPlugin_NetgenLibWrapper::*)(nglib::Ng_Mesh *)) &NETGENPlugin_NetgenLibWrapper::setMesh, "None", py::arg("mesh"));
	cls_NETGENPlugin_NetgenLibWrapper.def_static("RemoveTmpFiles_", (void (*)()) &NETGENPlugin_NetgenLibWrapper::RemoveTmpFiles, "None");
	cls_NETGENPlugin_NetgenLibWrapper.def_static("instanceCounter_", (int & (*)()) &NETGENPlugin_NetgenLibWrapper::instanceCounter, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\NETGENPlugin_Mesher.hxx
	py::class_<NETGENPlugin_Mesher, std::unique_ptr<NETGENPlugin_Mesher, Deleter<NETGENPlugin_Mesher>>> cls_NETGENPlugin_Mesher(mod, "NETGENPlugin_Mesher", "This class calls the NETGEN mesher of OCC geometry");
	cls_NETGENPlugin_Mesher.def(py::init<SMESH_Mesh *, const TopoDS_Shape &, const bool>(), py::arg("mesh"), py::arg("aShape"), py::arg("isVolume"));
	// FIXME cls_NETGENPlugin_Mesher.def("SetSelfPointer", (void (NETGENPlugin_Mesher::*)(NETGENPlugin_Mesher **)) &NETGENPlugin_Mesher::SetSelfPointer, "None", py::arg("ptr"));
	cls_NETGENPlugin_Mesher.def("SetParameters", (void (NETGENPlugin_Mesher::*)(const NETGENPlugin_Hypothesis *)) &NETGENPlugin_Mesher::SetParameters, "None", py::arg("hyp"));
	cls_NETGENPlugin_Mesher.def("SetParameters", (void (NETGENPlugin_Mesher::*)(const NETGENPlugin_SimpleHypothesis_2D *)) &NETGENPlugin_Mesher::SetParameters, "None", py::arg("hyp"));
	cls_NETGENPlugin_Mesher.def("SetViscousLayers2DAssigned", (void (NETGENPlugin_Mesher::*)(bool)) &NETGENPlugin_Mesher::SetViscousLayers2DAssigned, "None", py::arg("isAssigned"));
	// FIXME cls_NETGENPlugin_Mesher.def_static("SetLocalSize_", (void (*)(netgen::OCCGeometry &, netgen::Mesh &)) &NETGENPlugin_Mesher::SetLocalSize, "None", py::arg("occgeo"), py::arg("ngMesh"));
	cls_NETGENPlugin_Mesher.def("Compute", (bool (NETGENPlugin_Mesher::*)()) &NETGENPlugin_Mesher::Compute, "None");
	cls_NETGENPlugin_Mesher.def("Evaluate", (bool (NETGENPlugin_Mesher::*)(MapShapeNbElems &)) &NETGENPlugin_Mesher::Evaluate, "None", py::arg("aResMap"));
	cls_NETGENPlugin_Mesher.def("GetProgress", (double (NETGENPlugin_Mesher::*)(const SMESH_Algo *, const int *, const double *) const ) &NETGENPlugin_Mesher::GetProgress, "None", py::arg("holder"), py::arg("algoProgressTic"), py::arg("algoProgress"));
	// FIXME cls_NETGENPlugin_Mesher.def_static("PrepareOCCgeometry_", [](netgen::OCCGeometry & a0, const TopoDS_Shape & a1, SMESH_Mesh & a2) -> void { return NETGENPlugin_Mesher::PrepareOCCgeometry(a0, a1, a2); }, py::arg("occgeom"), py::arg("shape"), py::arg("mesh"));
	// FIXME cls_NETGENPlugin_Mesher.def_static("PrepareOCCgeometry_", [](netgen::OCCGeometry & a0, const TopoDS_Shape & a1, SMESH_Mesh & a2, std::list<SMESH_subMesh *> * a3) -> void { return NETGENPlugin_Mesher::PrepareOCCgeometry(a0, a1, a2, a3); }, py::arg("occgeom"), py::arg("shape"), py::arg("mesh"), py::arg("meshedSM"));
	// FIXME cls_NETGENPlugin_Mesher.def_static("PrepareOCCgeometry_", (void (*)(netgen::OCCGeometry &, const TopoDS_Shape &, SMESH_Mesh &, std::list<SMESH_subMesh *> *, NETGENPlugin_Internals *)) &NETGENPlugin_Mesher::PrepareOCCgeometry, "None", py::arg("occgeom"), py::arg("shape"), py::arg("mesh"), py::arg("meshedSM"), py::arg("internalShapes"));
	cls_NETGENPlugin_Mesher.def_static("GetDefaultMinSize_", (double (*)(const TopoDS_Shape &, const double)) &NETGENPlugin_Mesher::GetDefaultMinSize, "None", py::arg("shape"), py::arg("maxSize"));
	// FIXME cls_NETGENPlugin_Mesher.def_static("RestrictLocalSize_", [](netgen::Mesh & a0, const gp_XYZ & a1, double a2) -> void { return NETGENPlugin_Mesher::RestrictLocalSize(a0, a1, a2); }, py::arg("ngMesh"), py::arg("p"), py::arg("size"));
	// FIXME cls_NETGENPlugin_Mesher.def_static("RestrictLocalSize_", (void (*)(netgen::Mesh &, const gp_XYZ &, double, const bool)) &NETGENPlugin_Mesher::RestrictLocalSize, "None", py::arg("ngMesh"), py::arg("p"), py::arg("size"), py::arg("overrideMinH"));
	// FIXME cls_NETGENPlugin_Mesher.def_static("FillSMesh_", [](const netgen::OCCGeometry & a0, netgen::Mesh & a1, const NETGENPlugin_ngMeshInfo & a2, SMESH_Mesh & a3, std::vector<const SMDS_MeshNode *> & a4, SMESH_Comment & a5) -> int { return NETGENPlugin_Mesher::FillSMesh(a0, a1, a2, a3, a4, a5); }, py::arg("occgeom"), py::arg("ngMesh"), py::arg("initState"), py::arg("sMesh"), py::arg("nodeVec"), py::arg("comment"));
	// FIXME cls_NETGENPlugin_Mesher.def_static("FillSMesh_", (int (*)(const netgen::OCCGeometry &, netgen::Mesh &, const NETGENPlugin_ngMeshInfo &, SMESH_Mesh &, std::vector<const SMDS_MeshNode *> &, SMESH_Comment &, SMESH_MesherHelper *)) &NETGENPlugin_Mesher::FillSMesh, "None", py::arg("occgeom"), py::arg("ngMesh"), py::arg("initState"), py::arg("sMesh"), py::arg("nodeVec"), py::arg("comment"), py::arg("quadHelper"));
	// FIXME cls_NETGENPlugin_Mesher.def("FillNgMesh", [](NETGENPlugin_Mesher &self, netgen::OCCGeometry & a0, netgen::Mesh & a1, std::vector<const SMDS_MeshNode *> & a2, const std::list<SMESH_subMesh *> & a3) -> bool { return self.FillNgMesh(a0, a1, a2, a3); }, py::arg("occgeom"), py::arg("ngMesh"), py::arg("nodeVec"), py::arg("meshedSM"));
	// FIXME cls_NETGENPlugin_Mesher.def("FillNgMesh", [](NETGENPlugin_Mesher &self, netgen::OCCGeometry & a0, netgen::Mesh & a1, std::vector<const SMDS_MeshNode *> & a2, const std::list<SMESH_subMesh *> & a3, SMESH_MesherHelper * a4) -> bool { return self.FillNgMesh(a0, a1, a2, a3, a4); }, py::arg("occgeom"), py::arg("ngMesh"), py::arg("nodeVec"), py::arg("meshedSM"), py::arg("quadHelper"));
	// FIXME cls_NETGENPlugin_Mesher.def("FillNgMesh", (bool (NETGENPlugin_Mesher::*)(netgen::OCCGeometry &, netgen::Mesh &, std::vector<const SMDS_MeshNode *> &, const std::list<SMESH_subMesh *> &, SMESH_MesherHelper *, SMESH_ProxyMesh::Ptr)) &NETGENPlugin_Mesher::FillNgMesh, "None", py::arg("occgeom"), py::arg("ngMesh"), py::arg("nodeVec"), py::arg("meshedSM"), py::arg("quadHelper"), py::arg("proxyMesh"));
	// FIXME cls_NETGENPlugin_Mesher.def_static("FixIntFaces_", (void (*)(const netgen::OCCGeometry &, netgen::Mesh &, NETGENPlugin_Internals &)) &NETGENPlugin_Mesher::FixIntFaces, "None", py::arg("occgeom"), py::arg("ngMesh"), py::arg("internalShapes"));
	// FIXME cls_NETGENPlugin_Mesher.def_static("FixFaceMesh_", (bool (*)(const netgen::OCCGeometry &, netgen::Mesh &, const int)) &NETGENPlugin_Mesher::FixFaceMesh, "None", py::arg("occgeom"), py::arg("ngMesh"), py::arg("faceID"));
	// FIXME cls_NETGENPlugin_Mesher.def_static("AddIntVerticesInFaces_", (void (*)(const netgen::OCCGeometry &, netgen::Mesh &, std::vector<const SMDS_MeshNode *> &, NETGENPlugin_Internals &)) &NETGENPlugin_Mesher::AddIntVerticesInFaces, "None", py::arg("occgeom"), py::arg("ngMesh"), py::arg("nodeVec"), py::arg("internalShapes"));
	// FIXME cls_NETGENPlugin_Mesher.def_static("AddIntVerticesInSolids_", (void (*)(const netgen::OCCGeometry &, netgen::Mesh &, std::vector<const SMDS_MeshNode *> &, NETGENPlugin_Internals &)) &NETGENPlugin_Mesher::AddIntVerticesInSolids, "None", py::arg("occgeom"), py::arg("ngMesh"), py::arg("nodeVec"), py::arg("internalShapes"));
	// FIXME cls_NETGENPlugin_Mesher.def_static("AddSegmentsToMesh_", [](netgen::Mesh & a0, netgen::OCCGeometry & a1, const TSideVector & a2, SMESH_MesherHelper & a3, std::vector<const SMDS_MeshNode *> & a4) -> SMESH_ComputeErrorPtr { return NETGENPlugin_Mesher::AddSegmentsToMesh(a0, a1, a2, a3, a4); }, py::arg("ngMesh"), py::arg("geom"), py::arg("wires"), py::arg("helper"), py::arg("nodeVec"));
	// FIXME cls_NETGENPlugin_Mesher.def_static("AddSegmentsToMesh_", (SMESH_ComputeErrorPtr (*)(netgen::Mesh &, netgen::OCCGeometry &, const TSideVector &, SMESH_MesherHelper &, std::vector<const SMDS_MeshNode *> &, const bool)) &NETGENPlugin_Mesher::AddSegmentsToMesh, "None", py::arg("ngMesh"), py::arg("geom"), py::arg("wires"), py::arg("helper"), py::arg("nodeVec"), py::arg("overrideMinH"));
	cls_NETGENPlugin_Mesher.def("SetDefaultParameters", (void (NETGENPlugin_Mesher::*)()) &NETGENPlugin_Mesher::SetDefaultParameters, "None");
	cls_NETGENPlugin_Mesher.def_static("ReadErrors_", (SMESH_ComputeErrorPtr (*)(const std::vector<const SMDS_MeshNode *> &)) &NETGENPlugin_Mesher::ReadErrors, "None", py::arg("nodeVec"));
	// FIXME cls_NETGENPlugin_Mesher.def_static("toPython_", (void (*)(const netgen::Mesh *)) &NETGENPlugin_Mesher::toPython, "None", py::arg("ngMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\NETGENPlugin_NETGEN_2D.hxx
	py::class_<NETGENPlugin_NETGEN_2D, std::unique_ptr<NETGENPlugin_NETGEN_2D, py::nodelete>, SMESH_2D_Algo> cls_NETGENPlugin_NETGEN_2D(mod, "NETGENPlugin_NETGEN_2D", "None");
	cls_NETGENPlugin_NETGEN_2D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_NETGENPlugin_NETGEN_2D.def("CheckHypothesis", (bool (NETGENPlugin_NETGEN_2D::*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &NETGENPlugin_NETGEN_2D::CheckHypothesis, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));
	cls_NETGENPlugin_NETGEN_2D.def("Compute", (bool (NETGENPlugin_NETGEN_2D::*)(SMESH_Mesh &, const TopoDS_Shape &)) &NETGENPlugin_NETGEN_2D::Compute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_NETGENPlugin_NETGEN_2D.def("CancelCompute", (void (NETGENPlugin_NETGEN_2D::*)()) &NETGENPlugin_NETGEN_2D::CancelCompute, "None");
	cls_NETGENPlugin_NETGEN_2D.def("GetProgress", (double (NETGENPlugin_NETGEN_2D::*)() const ) &NETGENPlugin_NETGEN_2D::GetProgress, "None");
	cls_NETGENPlugin_NETGEN_2D.def("Evaluate", (bool (NETGENPlugin_NETGEN_2D::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &NETGENPlugin_NETGEN_2D::Evaluate, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\NETGENPlugin_NETGEN_2D3D.hxx
	py::class_<NETGENPlugin_NETGEN_2D3D, std::unique_ptr<NETGENPlugin_NETGEN_2D3D, py::nodelete>, SMESH_3D_Algo> cls_NETGENPlugin_NETGEN_2D3D(mod, "NETGENPlugin_NETGEN_2D3D", "None");
	cls_NETGENPlugin_NETGEN_2D3D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_NETGENPlugin_NETGEN_2D3D.def("CheckHypothesis", (bool (NETGENPlugin_NETGEN_2D3D::*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &NETGENPlugin_NETGEN_2D3D::CheckHypothesis, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));
	cls_NETGENPlugin_NETGEN_2D3D.def("Compute", (bool (NETGENPlugin_NETGEN_2D3D::*)(SMESH_Mesh &, const TopoDS_Shape &)) &NETGENPlugin_NETGEN_2D3D::Compute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_NETGENPlugin_NETGEN_2D3D.def("CancelCompute", (void (NETGENPlugin_NETGEN_2D3D::*)()) &NETGENPlugin_NETGEN_2D3D::CancelCompute, "None");
	cls_NETGENPlugin_NETGEN_2D3D.def("GetProgress", (double (NETGENPlugin_NETGEN_2D3D::*)() const ) &NETGENPlugin_NETGEN_2D3D::GetProgress, "None");
	cls_NETGENPlugin_NETGEN_2D3D.def("Evaluate", (bool (NETGENPlugin_NETGEN_2D3D::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &NETGENPlugin_NETGEN_2D3D::Evaluate, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\NETGENPlugin_NETGEN_2D_ONLY.hxx
	py::class_<NETGENPlugin_NETGEN_2D_ONLY, std::unique_ptr<NETGENPlugin_NETGEN_2D_ONLY, py::nodelete>, SMESH_2D_Algo> cls_NETGENPlugin_NETGEN_2D_ONLY(mod, "NETGENPlugin_NETGEN_2D_ONLY", "Mesher generating 2D elements on a geometrical face taking into account pre-existing nodes on face boundaries");
	cls_NETGENPlugin_NETGEN_2D_ONLY.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_NETGENPlugin_NETGEN_2D_ONLY.def("CheckHypothesis", (bool (NETGENPlugin_NETGEN_2D_ONLY::*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &NETGENPlugin_NETGEN_2D_ONLY::CheckHypothesis, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));
	cls_NETGENPlugin_NETGEN_2D_ONLY.def("Compute", (bool (NETGENPlugin_NETGEN_2D_ONLY::*)(SMESH_Mesh &, const TopoDS_Shape &)) &NETGENPlugin_NETGEN_2D_ONLY::Compute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_NETGENPlugin_NETGEN_2D_ONLY.def("CancelCompute", (void (NETGENPlugin_NETGEN_2D_ONLY::*)()) &NETGENPlugin_NETGEN_2D_ONLY::CancelCompute, "None");
	cls_NETGENPlugin_NETGEN_2D_ONLY.def("GetProgress", (double (NETGENPlugin_NETGEN_2D_ONLY::*)() const ) &NETGENPlugin_NETGEN_2D_ONLY::GetProgress, "None");
	cls_NETGENPlugin_NETGEN_2D_ONLY.def("Evaluate", (bool (NETGENPlugin_NETGEN_2D_ONLY::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &NETGENPlugin_NETGEN_2D_ONLY::Evaluate, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\NETGENPlugin_NETGEN_3D.hxx
	py::class_<NETGENPlugin_NETGEN_3D, std::unique_ptr<NETGENPlugin_NETGEN_3D, py::nodelete>, SMESH_3D_Algo> cls_NETGENPlugin_NETGEN_3D(mod, "NETGENPlugin_NETGEN_3D", "None");
	cls_NETGENPlugin_NETGEN_3D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_NETGENPlugin_NETGEN_3D.def("CheckHypothesis", (bool (NETGENPlugin_NETGEN_3D::*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &NETGENPlugin_NETGEN_3D::CheckHypothesis, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));
	cls_NETGENPlugin_NETGEN_3D.def("Compute", (bool (NETGENPlugin_NETGEN_3D::*)(SMESH_Mesh &, const TopoDS_Shape &)) &NETGENPlugin_NETGEN_3D::Compute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_NETGENPlugin_NETGEN_3D.def("Compute", (bool (NETGENPlugin_NETGEN_3D::*)(SMESH_Mesh &, SMESH_MesherHelper *)) &NETGENPlugin_NETGEN_3D::Compute, "None", py::arg("aMesh"), py::arg("aHelper"));
	cls_NETGENPlugin_NETGEN_3D.def("CancelCompute", (void (NETGENPlugin_NETGEN_3D::*)()) &NETGENPlugin_NETGEN_3D::CancelCompute, "None");
	cls_NETGENPlugin_NETGEN_3D.def("GetProgress", (double (NETGENPlugin_NETGEN_3D::*)() const ) &NETGENPlugin_NETGEN_3D::GetProgress, "None");
	cls_NETGENPlugin_NETGEN_3D.def("Evaluate", (bool (NETGENPlugin_NETGEN_3D::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &NETGENPlugin_NETGEN_3D::Evaluate, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\NETGENPlugin_SimpleHypothesis_3D.hxx
	py::class_<NETGENPlugin_SimpleHypothesis_3D, std::unique_ptr<NETGENPlugin_SimpleHypothesis_3D, py::nodelete>, NETGENPlugin_SimpleHypothesis_2D> cls_NETGENPlugin_SimpleHypothesis_3D(mod, "NETGENPlugin_SimpleHypothesis_3D", "None");
	cls_NETGENPlugin_SimpleHypothesis_3D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_NETGENPlugin_SimpleHypothesis_3D.def("LengthFromFaces", (void (NETGENPlugin_SimpleHypothesis_3D::*)()) &NETGENPlugin_SimpleHypothesis_3D::LengthFromFaces, "None");
	cls_NETGENPlugin_SimpleHypothesis_3D.def("SetMaxElementVolume", (void (NETGENPlugin_SimpleHypothesis_3D::*)(double)) &NETGENPlugin_SimpleHypothesis_3D::SetMaxElementVolume, "None", py::arg("value"));
	cls_NETGENPlugin_SimpleHypothesis_3D.def("GetMaxElementVolume", (double (NETGENPlugin_SimpleHypothesis_3D::*)() const ) &NETGENPlugin_SimpleHypothesis_3D::GetMaxElementVolume, "None");
	cls_NETGENPlugin_SimpleHypothesis_3D.def("SaveTo", (std::ostream & (NETGENPlugin_SimpleHypothesis_3D::*)(std::ostream &)) &NETGENPlugin_SimpleHypothesis_3D::SaveTo, "None", py::arg("save"));
	cls_NETGENPlugin_SimpleHypothesis_3D.def("LoadFrom", (std::istream & (NETGENPlugin_SimpleHypothesis_3D::*)(std::istream &)) &NETGENPlugin_SimpleHypothesis_3D::LoadFrom, "None", py::arg("load"));
	cls_NETGENPlugin_SimpleHypothesis_3D.def("SetParametersByMesh", (bool (NETGENPlugin_SimpleHypothesis_3D::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &NETGENPlugin_SimpleHypothesis_3D::SetParametersByMesh, "Set parameters by mesh", py::arg("theMesh"), py::arg("theShape"));


}
