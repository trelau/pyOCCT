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

#include <TopoDS_Face.hxx>
#include <StdMeshers_Quadrangle_2D.hxx>
#include <gp_XY.hxx>
#include <TopoDS_Edge.hxx>
#include <SMESH_Mesh.hxx>
#include <SMESH_MesherHelper.hxx>
#include <SMESH_ProxyMesh.hxx>
#include <StdMeshers_FaceSide.hxx>
#include <SMDS_MeshNode.hxx>
#include <gp_Pnt2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <SMESH_TypeDefs.hxx>
#include <gp_Pnt.hxx>
#include <Adaptor2d_Curve2d.hxx>
#include <BRepAdaptor_CompCurve.hxx>
#include <TopoDS_Vertex.hxx>
#include <SMESH_Hypothesis.hxx>
#include <SMESH_Gen.hxx>
#include <TopoDS_Shape.hxx>
#include <StdMeshers_MaxElementArea.hxx>
#include <StdMeshers_LengthFromEdges.hxx>
#include <StdMeshers_ViscousLayers.hxx>
#include <SMESH_ComputeError.hxx>
#include <StdMeshers_MaxElementVolume.hxx>
#include <SMESH_Algo.hxx>
#include <StdMeshers_Adaptive1D.hxx>
#include <StdMeshers_FixedPoints1D.hxx>
#include <StdMeshers_SegmentLengthAroundVertex.hxx>
#include <SMESHDS_Hypothesis.hxx>
#include <SMESH_subMesh.hxx>
#include <StdMeshers_Regular_1D.hxx>
#include <StdMeshers_Arithmetic1D.hxx>
#include <StdMeshers_AutomaticLength.hxx>
#include <Bnd_Box.hxx>
#include <StdMeshers_CartesianParameters3D.hxx>
#include <StdMeshers_Cartesian_3D.hxx>
#include <StdMeshers_CompositeHexa_3D.hxx>
#include <StdMeshers_CompositeSegment_1D.hxx>
#include <StdMeshers_Deflection1D.hxx>
#include <StdMeshers_Reversible1D.hxx>
#include <StdMeshers_Geometric1D.hxx>
#include <StdMeshers_HexaFromSkin_3D.hxx>
#include <StdMeshers_Hexa_3D.hxx>
#include <SMESH_Group.hxx>
#include <SMESHDS_Mesh.hxx>
#include <StdMeshers_ImportSource.hxx>
#include <StdMeshers_Import_1D.hxx>
#include <StdMeshers_Import_1D2D.hxx>
#include <StdMeshers_LayerDistribution.hxx>
#include <StdMeshers_LayerDistribution2D.hxx>
#include <StdMeshers_LocalLength.hxx>
#include <StdMeshers_MaxLength.hxx>
#include <StdMeshers_MEFISTO_2D.hxx>
#include <Rn.h>
#include <StdMeshers_NotConformAllowed.hxx>
#include <StdMeshers_NumberOfLayers.hxx>
#include <StdMeshers_NumberOfLayers2D.hxx>
#include <StdMeshers_NumberOfSegments.hxx>
#include <StdMeshers_Penta_3D.hxx>
#include <TopoDS_Shell.hxx>
#include <gp_XYZ.hxx>
#include <SMESH_Block.hxx>
#include <StdMeshers_PolygonPerFace_2D.hxx>
#include <StdMeshers_Prism_3D.hxx>
#include <gp_Trsf.hxx>
#include <SMESHDS_SubMesh.hxx>
#include <StdMeshers_ProjectionSource1D.hxx>
#include <StdMeshers_ProjectionSource2D.hxx>
#include <StdMeshers_ProjectionSource3D.hxx>
#include <StdMeshers_ProjectionUtils.hxx>
#include <StdMeshers_Projection_1D.hxx>
#include <StdMeshers_Projection_2D.hxx>
#include <StdMeshers_Projection_1D2D.hxx>
#include <StdMeshers_Projection_3D.hxx>
#include <SMESH_HypoFilter.hxx>
#include <StdMeshers_Propagation.hxx>
#include <StdMeshers_QuadrangleParams.hxx>
#include <StdMeshers_QuadFromMedialAxis_1D2D.hxx>
#include <StdMeshers_QuadranglePreference.hxx>
#include <StdMeshers_QuadraticMesh.hxx>
#include <StdMeshers_QuadToTriaAdaptor.hxx>
#include <StdMeshers_RadialPrism_3D.hxx>
#include <StdMeshers_RadialQuadrangle_1D2D.hxx>
#include <StdMeshers_SegmentAroundVertex_0D.hxx>
#include <StdMeshers_StartEndLength.hxx>
#include <StdMeshers_UseExisting_1D2D.hxx>
#include <StdMeshers_ViscousLayers2D.hxx>

PYBIND11_MODULE(StdMeshers, mod) {

	// IMPORT
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.SMESH");
	py::module::import("OCCT.SMDS");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.Adaptor2d");
	py::module::import("OCCT.BRepAdaptor");
	py::module::import("OCCT.SMESHDS");
	py::module::import("OCCT.Bnd");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_QuadrangleParams.hxx
	py::enum_<StdMeshers_QuadType>(mod, "StdMeshers_QuadType", "None")
		.value("QUAD_STANDARD", StdMeshers_QuadType::QUAD_STANDARD)
		.value("QUAD_TRIANGLE_PREF", StdMeshers_QuadType::QUAD_TRIANGLE_PREF)
		.value("QUAD_QUADRANGLE_PREF", StdMeshers_QuadType::QUAD_QUADRANGLE_PREF)
		.value("QUAD_QUADRANGLE_PREF_REVERSED", StdMeshers_QuadType::QUAD_QUADRANGLE_PREF_REVERSED)
		.value("QUAD_REDUCED", StdMeshers_QuadType::QUAD_REDUCED)
		.value("QUAD_NB_TYPES", StdMeshers_QuadType::QUAD_NB_TYPES)
		.export_values();
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Quadrangle_2D.hxx
	py::enum_<TSideID>(mod, "TSideID", "None")
		.value("QUAD_BOTTOM_SIDE", TSideID::QUAD_BOTTOM_SIDE)
		.value("QUAD_RIGHT_SIDE", TSideID::QUAD_RIGHT_SIDE)
		.value("QUAD_TOP_SIDE", TSideID::QUAD_TOP_SIDE)
		.value("QUAD_LEFT_SIDE", TSideID::QUAD_LEFT_SIDE)
		.value("NB_QUAD_SIDES", TSideID::NB_QUAD_SIDES)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Quadrangle_2D.hxx
	py::class_<FaceQuadStruct, std::unique_ptr<FaceQuadStruct, Deleter<FaceQuadStruct>>> cls_FaceQuadStruct(mod, "FaceQuadStruct", "None");
	// cls_FaceQuadStruct.def(py::init<>());
	// cls_FaceQuadStruct.def(py::init<const TopoDS_Face &>(), py::arg("F"));
	// cls_FaceQuadStruct.def(py::init<const TopoDS_Face &, const std::string &>(), py::arg("F"), py::arg("nm"));
	cls_FaceQuadStruct.def("UVPt", (UVPtStruct & (FaceQuadStruct::*)(int, int)) &FaceQuadStruct::UVPt, "None", py::arg("i"), py::arg("j"));
	cls_FaceQuadStruct.def("U", (double & (FaceQuadStruct::*)(int, int)) &FaceQuadStruct::U, "None", py::arg("i"), py::arg("j"));
	cls_FaceQuadStruct.def("V", (double & (FaceQuadStruct::*)(int, int)) &FaceQuadStruct::V, "None", py::arg("i"), py::arg("j"));
	// cls_FaceQuadStruct.def("shift", [](FaceQuadStruct &self, size_t a0, bool a1) -> void { return self.shift(a0, a1); }, py::arg("nb"), py::arg("keepUnitOri"));
	// cls_FaceQuadStruct.def("shift", (void (FaceQuadStruct::*)(size_t, bool, bool)) &FaceQuadStruct::shift, "None", py::arg("nb"), py::arg("keepUnitOri"), py::arg("keepGrid"));
	cls_FaceQuadStruct.def("nbNodeOut", (int & (FaceQuadStruct::*)(int)) &FaceQuadStruct::nbNodeOut, "None", py::arg("iSide"));
	// cls_FaceQuadStruct.def("findCell", (bool (FaceQuadStruct::*)(const gp_XY &, int &, int &)) &FaceQuadStruct::findCell, "None", py::arg("uv"), py::arg("i"), py::arg("j"));
	// cls_FaceQuadStruct.def("isNear", [](FaceQuadStruct &self, const gp_XY & a0, int & a1, int & a2) -> bool { return self.isNear(a0, a1, a2); }, py::arg("uv"), py::arg("i"), py::arg("j"));
	// cls_FaceQuadStruct.def("isNear", (bool (FaceQuadStruct::*)(const gp_XY &, int &, int &, int)) &FaceQuadStruct::isNear, "None", py::arg("uv"), py::arg("i"), py::arg("j"), py::arg("nbLoops"));
	// cls_FaceQuadStruct.def("isEqual", (bool (FaceQuadStruct::*)(const gp_XY &, int, int)) &FaceQuadStruct::isEqual, "None", py::arg("uv"), py::arg("i"), py::arg("j"));
	// cls_FaceQuadStruct.def("normPa2IJ", (void (FaceQuadStruct::*)(double, double, int &, int &)) &FaceQuadStruct::normPa2IJ, "None", py::arg("x"), py::arg("y"), py::arg("i"), py::arg("j"));
	// cls_FaceQuadStruct.def("updateUV", (void (FaceQuadStruct::*)(const gp_XY &, int, int, bool)) &FaceQuadStruct::updateUV, "None", py::arg("uv"), py::arg("i"), py::arg("j"), py::arg("isVertical"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_FaceSide.hxx
	py::class_<StdMeshers_FaceSide, std::unique_ptr<StdMeshers_FaceSide, Deleter<StdMeshers_FaceSide>>> cls_StdMeshers_FaceSide(mod, "StdMeshers_FaceSide", "Represents a side of a quasi quadrilateral face. It can be composed of several edges. Gives access to geometry and 1D mesh of a side.");
	cls_StdMeshers_FaceSide.def(py::init<const TopoDS_Face &, const TopoDS_Edge &, SMESH_Mesh *, const bool, const bool>(), py::arg("theFace"), py::arg("theEdge"), py::arg("theMesh"), py::arg("theIsForward"), py::arg("theIgnoreMediumNodes"));
	cls_StdMeshers_FaceSide.def(py::init<const TopoDS_Face &, const TopoDS_Edge &, SMESH_Mesh *, const bool, const bool, SMESH_MesherHelper *>(), py::arg("theFace"), py::arg("theEdge"), py::arg("theMesh"), py::arg("theIsForward"), py::arg("theIgnoreMediumNodes"), py::arg("theFaceHelper"));
	cls_StdMeshers_FaceSide.def(py::init<const TopoDS_Face &, const TopoDS_Edge &, SMESH_Mesh *, const bool, const bool, SMESH_MesherHelper *, SMESH_ProxyMesh::Ptr>(), py::arg("theFace"), py::arg("theEdge"), py::arg("theMesh"), py::arg("theIsForward"), py::arg("theIgnoreMediumNodes"), py::arg("theFaceHelper"), py::arg("theProxyMesh"));
	cls_StdMeshers_FaceSide.def(py::init<const TopoDS_Face &, std::list<TopoDS_Edge> &, SMESH_Mesh *, const bool, const bool>(), py::arg("theFace"), py::arg("theEdges"), py::arg("theMesh"), py::arg("theIsForward"), py::arg("theIgnoreMediumNodes"));
	cls_StdMeshers_FaceSide.def(py::init<const TopoDS_Face &, std::list<TopoDS_Edge> &, SMESH_Mesh *, const bool, const bool, SMESH_MesherHelper *>(), py::arg("theFace"), py::arg("theEdges"), py::arg("theMesh"), py::arg("theIsForward"), py::arg("theIgnoreMediumNodes"), py::arg("theFaceHelper"));
	cls_StdMeshers_FaceSide.def(py::init<const TopoDS_Face &, std::list<TopoDS_Edge> &, SMESH_Mesh *, const bool, const bool, SMESH_MesherHelper *, SMESH_ProxyMesh::Ptr>(), py::arg("theFace"), py::arg("theEdges"), py::arg("theMesh"), py::arg("theIsForward"), py::arg("theIgnoreMediumNodes"), py::arg("theFaceHelper"), py::arg("theProxyMesh"));
	cls_StdMeshers_FaceSide.def(py::init<const StdMeshers_FaceSide *, const SMDS_MeshNode *, const gp_Pnt2d *>(), py::arg("theSide"), py::arg("theNode"), py::arg("thePnt2d1"));
	cls_StdMeshers_FaceSide.def(py::init<const StdMeshers_FaceSide *, const SMDS_MeshNode *, const gp_Pnt2d *, const gp_Pnt2d *>(), py::arg("theSide"), py::arg("theNode"), py::arg("thePnt2d1"), py::arg("thePnt2d2"));
	cls_StdMeshers_FaceSide.def(py::init<const StdMeshers_FaceSide *, const SMDS_MeshNode *, const gp_Pnt2d *, const gp_Pnt2d *, const opencascade::handle<Geom2d_Curve> &>(), py::arg("theSide"), py::arg("theNode"), py::arg("thePnt2d1"), py::arg("thePnt2d2"), py::arg("theC2d"));
	cls_StdMeshers_FaceSide.def(py::init<const StdMeshers_FaceSide *, const SMDS_MeshNode *, const gp_Pnt2d *, const gp_Pnt2d *, const opencascade::handle<Geom2d_Curve> &, const double>(), py::arg("theSide"), py::arg("theNode"), py::arg("thePnt2d1"), py::arg("thePnt2d2"), py::arg("theC2d"), py::arg("theUFirst"));
	cls_StdMeshers_FaceSide.def(py::init<const StdMeshers_FaceSide *, const SMDS_MeshNode *, const gp_Pnt2d *, const gp_Pnt2d *, const opencascade::handle<Geom2d_Curve> &, const double, const double>(), py::arg("theSide"), py::arg("theNode"), py::arg("thePnt2d1"), py::arg("thePnt2d2"), py::arg("theC2d"), py::arg("theUFirst"), py::arg("theULast"));
	cls_StdMeshers_FaceSide.def(py::init<UVPtStructVec &>(), py::arg("theSideNodes"));
	cls_StdMeshers_FaceSide.def(py::init<UVPtStructVec &, const TopoDS_Face &>(), py::arg("theSideNodes"), py::arg("theFace"));
	cls_StdMeshers_FaceSide.def(py::init<UVPtStructVec &, const TopoDS_Face &, const TopoDS_Edge &>(), py::arg("theSideNodes"), py::arg("theFace"), py::arg("theEdge"));
	cls_StdMeshers_FaceSide.def(py::init<UVPtStructVec &, const TopoDS_Face &, const TopoDS_Edge &, SMESH_Mesh *>(), py::arg("theSideNodes"), py::arg("theFace"), py::arg("theEdge"), py::arg("theMesh"));
	// FIXME cls_StdMeshers_FaceSide.def_static("New_", [](const TopoDS_Face & a0, const TopoDS_Edge & a1, SMESH_Mesh * a2, const bool a3, const bool a4) -> StdMeshers_FaceSidePtr { return StdMeshers_FaceSide::New(a0, a1, a2, a3, a4); }, py::arg("Face"), py::arg("Edge"), py::arg("Mesh"), py::arg("IsForward"), py::arg("IgnoreMediumNodes"));
	// FIXME cls_StdMeshers_FaceSide.def_static("New_", [](const TopoDS_Face & a0, const TopoDS_Edge & a1, SMESH_Mesh * a2, const bool a3, const bool a4, SMESH_MesherHelper * a5) -> StdMeshers_FaceSidePtr { return StdMeshers_FaceSide::New(a0, a1, a2, a3, a4, a5); }, py::arg("Face"), py::arg("Edge"), py::arg("Mesh"), py::arg("IsForward"), py::arg("IgnoreMediumNodes"), py::arg("FaceHelper"));
	// FIXME cls_StdMeshers_FaceSide.def_static("New_", (StdMeshers_FaceSidePtr (*)(const TopoDS_Face &, const TopoDS_Edge &, SMESH_Mesh *, const bool, const bool, SMESH_MesherHelper *, SMESH_ProxyMesh::Ptr)) &StdMeshers_FaceSide::New, "None", py::arg("Face"), py::arg("Edge"), py::arg("Mesh"), py::arg("IsForward"), py::arg("IgnoreMediumNodes"), py::arg("FaceHelper"), py::arg("ProxyMesh"));
	// FIXME cls_StdMeshers_FaceSide.def_static("New_", [](const TopoDS_Face & a0, std::list<TopoDS_Edge> & a1, SMESH_Mesh * a2, const bool a3, const bool a4) -> StdMeshers_FaceSidePtr { return StdMeshers_FaceSide::New(a0, a1, a2, a3, a4); }, py::arg("Face"), py::arg("Edges"), py::arg("Mesh"), py::arg("IsForward"), py::arg("IgnoreMediumNodes"));
	// FIXME cls_StdMeshers_FaceSide.def_static("New_", [](const TopoDS_Face & a0, std::list<TopoDS_Edge> & a1, SMESH_Mesh * a2, const bool a3, const bool a4, SMESH_MesherHelper * a5) -> StdMeshers_FaceSidePtr { return StdMeshers_FaceSide::New(a0, a1, a2, a3, a4, a5); }, py::arg("Face"), py::arg("Edges"), py::arg("Mesh"), py::arg("IsForward"), py::arg("IgnoreMediumNodes"), py::arg("FaceHelper"));
	// FIXME cls_StdMeshers_FaceSide.def_static("New_", (StdMeshers_FaceSidePtr (*)(const TopoDS_Face &, std::list<TopoDS_Edge> &, SMESH_Mesh *, const bool, const bool, SMESH_MesherHelper *, SMESH_ProxyMesh::Ptr)) &StdMeshers_FaceSide::New, "None", py::arg("Face"), py::arg("Edges"), py::arg("Mesh"), py::arg("IsForward"), py::arg("IgnoreMediumNodes"), py::arg("FaceHelper"), py::arg("ProxyMesh"));
	// FIXME cls_StdMeshers_FaceSide.def_static("New_", [](const StdMeshers_FaceSide * a0, const SMDS_MeshNode * a1, const gp_Pnt2d * a2) -> StdMeshers_FaceSidePtr { return StdMeshers_FaceSide::New(a0, a1, a2); }, py::arg("Side"), py::arg("Node"), py::arg("Pnt2d1"));
	// FIXME cls_StdMeshers_FaceSide.def_static("New_", [](const StdMeshers_FaceSide * a0, const SMDS_MeshNode * a1, const gp_Pnt2d * a2, const gp_Pnt2d * a3) -> StdMeshers_FaceSidePtr { return StdMeshers_FaceSide::New(a0, a1, a2, a3); }, py::arg("Side"), py::arg("Node"), py::arg("Pnt2d1"), py::arg("Pnt2d2"));
	// FIXME cls_StdMeshers_FaceSide.def_static("New_", [](const StdMeshers_FaceSide * a0, const SMDS_MeshNode * a1, const gp_Pnt2d * a2, const gp_Pnt2d * a3, const opencascade::handle<Geom2d_Curve> & a4) -> StdMeshers_FaceSidePtr { return StdMeshers_FaceSide::New(a0, a1, a2, a3, a4); }, py::arg("Side"), py::arg("Node"), py::arg("Pnt2d1"), py::arg("Pnt2d2"), py::arg("C2d"));
	// FIXME cls_StdMeshers_FaceSide.def_static("New_", [](const StdMeshers_FaceSide * a0, const SMDS_MeshNode * a1, const gp_Pnt2d * a2, const gp_Pnt2d * a3, const opencascade::handle<Geom2d_Curve> & a4, const double a5) -> StdMeshers_FaceSidePtr { return StdMeshers_FaceSide::New(a0, a1, a2, a3, a4, a5); }, py::arg("Side"), py::arg("Node"), py::arg("Pnt2d1"), py::arg("Pnt2d2"), py::arg("C2d"), py::arg("UFirst"));
	// FIXME cls_StdMeshers_FaceSide.def_static("New_", (StdMeshers_FaceSidePtr (*)(const StdMeshers_FaceSide *, const SMDS_MeshNode *, const gp_Pnt2d *, const gp_Pnt2d *, const opencascade::handle<Geom2d_Curve> &, const double, const double)) &StdMeshers_FaceSide::New, "None", py::arg("Side"), py::arg("Node"), py::arg("Pnt2d1"), py::arg("Pnt2d2"), py::arg("C2d"), py::arg("UFirst"), py::arg("ULast"));
	// FIXME cls_StdMeshers_FaceSide.def_static("New_", [](UVPtStructVec & a0) -> StdMeshers_FaceSidePtr { return StdMeshers_FaceSide::New(a0); }, py::arg("theSideNodes"));
	// FIXME cls_StdMeshers_FaceSide.def_static("New_", (StdMeshers_FaceSidePtr (*)(UVPtStructVec &, const TopoDS_Face &)) &StdMeshers_FaceSide::New, "None", py::arg("theSideNodes"), py::arg("theFace"));
	cls_StdMeshers_FaceSide.def_static("GetFaceWires_", [](const TopoDS_Face & a0, SMESH_Mesh & a1, const bool a2, TError & a3) -> TSideVector { return StdMeshers_FaceSide::GetFaceWires(a0, a1, a2, a3); }, py::arg("theFace"), py::arg("theMesh"), py::arg("theIgnoreMediumNodes"), py::arg("theError"));
	cls_StdMeshers_FaceSide.def_static("GetFaceWires_", [](const TopoDS_Face & a0, SMESH_Mesh & a1, const bool a2, TError & a3, SMESH_MesherHelper * a4) -> TSideVector { return StdMeshers_FaceSide::GetFaceWires(a0, a1, a2, a3, a4); }, py::arg("theFace"), py::arg("theMesh"), py::arg("theIgnoreMediumNodes"), py::arg("theError"), py::arg("theFaceHelper"));
	cls_StdMeshers_FaceSide.def_static("GetFaceWires_", [](const TopoDS_Face & a0, SMESH_Mesh & a1, const bool a2, TError & a3, SMESH_MesherHelper * a4, SMESH_ProxyMesh::Ptr a5) -> TSideVector { return StdMeshers_FaceSide::GetFaceWires(a0, a1, a2, a3, a4, a5); }, py::arg("theFace"), py::arg("theMesh"), py::arg("theIgnoreMediumNodes"), py::arg("theError"), py::arg("theFaceHelper"), py::arg("theProxyMesh"));
	cls_StdMeshers_FaceSide.def_static("GetFaceWires_", (TSideVector (*)(const TopoDS_Face &, SMESH_Mesh &, const bool, TError &, SMESH_MesherHelper *, SMESH_ProxyMesh::Ptr, const bool)) &StdMeshers_FaceSide::GetFaceWires, "Return wires of a face as StdMeshers_FaceSide's", py::arg("theFace"), py::arg("theMesh"), py::arg("theIgnoreMediumNodes"), py::arg("theError"), py::arg("theFaceHelper"), py::arg("theProxyMesh"), py::arg("theCheckVertexNodes"));
	cls_StdMeshers_FaceSide.def("Reverse", (void (StdMeshers_FaceSide::*)()) &StdMeshers_FaceSide::Reverse, "Change orientation of side geometry");
	cls_StdMeshers_FaceSide.def("SetIgnoreMediumNodes", (void (StdMeshers_FaceSide::*)(bool)) &StdMeshers_FaceSide::SetIgnoreMediumNodes, "Make ignore medium nodes", py::arg("toIgnore"));
	cls_StdMeshers_FaceSide.def("NbPoints", [](StdMeshers_FaceSide &self) -> int { return self.NbPoints(); });
	cls_StdMeshers_FaceSide.def("NbPoints", (int (StdMeshers_FaceSide::*)(const bool) const ) &StdMeshers_FaceSide::NbPoints, "Return nb nodes on edges and vertices (+1 to be == GetUVPtStruct().size() ). Call it with update == true if mesh of this side can be recomputed since creation of this side", py::arg("update"));
	cls_StdMeshers_FaceSide.def("NbSegments", [](StdMeshers_FaceSide &self) -> int { return self.NbSegments(); });
	cls_StdMeshers_FaceSide.def("NbSegments", (int (StdMeshers_FaceSide::*)(const bool) const ) &StdMeshers_FaceSide::NbSegments, "Return nb edges Call it with update == true if mesh of this side can be recomputed since creation of this side", py::arg("update"));
	cls_StdMeshers_FaceSide.def("GetMesh", (SMESH_Mesh * (StdMeshers_FaceSide::*)() const ) &StdMeshers_FaceSide::GetMesh, "Return mesh");
	cls_StdMeshers_FaceSide.def("MissVertexNode", (bool (StdMeshers_FaceSide::*)() const ) &StdMeshers_FaceSide::MissVertexNode, "Return true if there are vertices without nodes");
	cls_StdMeshers_FaceSide.def("GetUVPtStruct", [](StdMeshers_FaceSide &self) -> const UVPtStructVec & { return self.GetUVPtStruct(); });
	cls_StdMeshers_FaceSide.def("GetUVPtStruct", [](StdMeshers_FaceSide &self, bool a0) -> const UVPtStructVec & { return self.GetUVPtStruct(a0); }, py::arg("isXConst"));
	cls_StdMeshers_FaceSide.def("GetUVPtStruct", (const UVPtStructVec & (StdMeshers_FaceSide::*)(bool, double) const ) &StdMeshers_FaceSide::GetUVPtStruct, "Return detailed data on nodes", py::arg("isXConst"), py::arg("constValue"));
	cls_StdMeshers_FaceSide.def("SimulateUVPtStruct", [](StdMeshers_FaceSide &self, int a0) -> const UVPtStructVec & { return self.SimulateUVPtStruct(a0); }, py::arg("nbSeg"));
	cls_StdMeshers_FaceSide.def("SimulateUVPtStruct", [](StdMeshers_FaceSide &self, int a0, bool a1) -> const UVPtStructVec & { return self.SimulateUVPtStruct(a0, a1); }, py::arg("nbSeg"), py::arg("isXConst"));
	cls_StdMeshers_FaceSide.def("SimulateUVPtStruct", (const UVPtStructVec & (StdMeshers_FaceSide::*)(int, bool, double) const ) &StdMeshers_FaceSide::SimulateUVPtStruct, "Simulates detailed data on nodes", py::arg("nbSeg"), py::arg("isXConst"), py::arg("constValue"));
	cls_StdMeshers_FaceSide.def("GetOrderedNodes", [](StdMeshers_FaceSide &self) -> std::vector<const SMDS_MeshNode *> { return self.GetOrderedNodes(); });
	cls_StdMeshers_FaceSide.def("GetOrderedNodes", (std::vector<const SMDS_MeshNode *> (StdMeshers_FaceSide::*)(int) const ) &StdMeshers_FaceSide::GetOrderedNodes, "Return nodes in the order they encounter while walking along the while side or a specified EDGE. For a closed side, the 1st point repeats at end.", py::arg("iE"));
	cls_StdMeshers_FaceSide.def("GetEdgeNodes", [](StdMeshers_FaceSide &self, const size_t a0, std::vector<const SMDS_MeshNode *> & a1) -> bool { return self.GetEdgeNodes(a0, a1); }, py::arg("i"), py::arg("nodes"));
	cls_StdMeshers_FaceSide.def("GetEdgeNodes", [](StdMeshers_FaceSide &self, const size_t a0, std::vector<const SMDS_MeshNode *> & a1, bool a2) -> bool { return self.GetEdgeNodes(a0, a1, a2); }, py::arg("i"), py::arg("nodes"), py::arg("inlude1stVertex"));
	cls_StdMeshers_FaceSide.def("GetEdgeNodes", (bool (StdMeshers_FaceSide::*)(const size_t, std::vector<const SMDS_MeshNode *> &, bool, bool) const ) &StdMeshers_FaceSide::GetEdgeNodes, "Return nodes of the i-th EDGE. Nodes moved to other geometry by MergeNodes() are also returned. bool - is OK", py::arg("i"), py::arg("nodes"), py::arg("inlude1stVertex"), py::arg("inludeLastVertex"));
	cls_StdMeshers_FaceSide.def("VertexNode", [](StdMeshers_FaceSide &self, std::size_t a0) -> const SMDS_MeshNode * { return self.VertexNode(a0); }, py::arg("i"));
	cls_StdMeshers_FaceSide.def("VertexNode", (const SMDS_MeshNode * (StdMeshers_FaceSide::*)(std::size_t, bool *) const ) &StdMeshers_FaceSide::VertexNode, "Return a node from the i-th VERTEX (count starts from zero) Nodes moved to other geometry by MergeNodes() are also returned.", py::arg("i"), py::arg("isMoved"));
	cls_StdMeshers_FaceSide.def("Parameter", (double (StdMeshers_FaceSide::*)(double, TopoDS_Edge &) const ) &StdMeshers_FaceSide::Parameter, "Return an edge and parameter on the edge by a normalized parameter", py::arg("U"), py::arg("edge"));
	cls_StdMeshers_FaceSide.def("Parameter", (double (StdMeshers_FaceSide::*)(double, int &) const ) &StdMeshers_FaceSide::Parameter, "Return an edge ID and parameter on the edge by a normalized parameter", py::arg("U"), py::arg("edgeID"));
	cls_StdMeshers_FaceSide.def("Value2d", (gp_Pnt2d (StdMeshers_FaceSide::*)(double) const ) &StdMeshers_FaceSide::Value2d, "Return UV by normalized parameter", py::arg("U"));
	cls_StdMeshers_FaceSide.def("Value3d", (gp_Pnt (StdMeshers_FaceSide::*)(double) const ) &StdMeshers_FaceSide::Value3d, "Return XYZ by normalized parameter", py::arg("U"));
	cls_StdMeshers_FaceSide.def("GetCurve2d", (Adaptor2d_Curve2d * (StdMeshers_FaceSide::*)() const ) &StdMeshers_FaceSide::GetCurve2d, "Creates a Adaptor2d_Curve2d to be used in SMESH_Block");
	cls_StdMeshers_FaceSide.def("GetCurve3d", (BRepAdaptor_CompCurve * (StdMeshers_FaceSide::*)() const ) &StdMeshers_FaceSide::GetCurve3d, "Creates a fully functional Adaptor_Curve");
	cls_StdMeshers_FaceSide.def("NbEdges", (int (StdMeshers_FaceSide::*)() const ) &StdMeshers_FaceSide::NbEdges, "Return nb of wrapped edges");
	cls_StdMeshers_FaceSide.def("Edge", (const TopoDS_Edge & (StdMeshers_FaceSide::*)(int) const ) &StdMeshers_FaceSide::Edge, "Return i-th edge (count starts from zero)", py::arg("i"));
	cls_StdMeshers_FaceSide.def("Edges", (const std::vector<TopoDS_Edge> & (StdMeshers_FaceSide::*)() const ) &StdMeshers_FaceSide::Edges, "Return all edges");
	cls_StdMeshers_FaceSide.def("Face", (const TopoDS_Face & (StdMeshers_FaceSide::*)() const ) &StdMeshers_FaceSide::Face, "Return the FACE");
	cls_StdMeshers_FaceSide.def("FirstVertex", [](StdMeshers_FaceSide &self) -> TopoDS_Vertex { return self.FirstVertex(); });
	cls_StdMeshers_FaceSide.def("FirstVertex", (TopoDS_Vertex (StdMeshers_FaceSide::*)(int) const ) &StdMeshers_FaceSide::FirstVertex, "Return 1st vertex of the i-th edge (count starts from zero)", py::arg("i"));
	cls_StdMeshers_FaceSide.def("LastVertex", [](StdMeshers_FaceSide &self) -> TopoDS_Vertex { return self.LastVertex(); });
	cls_StdMeshers_FaceSide.def("LastVertex", (TopoDS_Vertex (StdMeshers_FaceSide::*)(int) const ) &StdMeshers_FaceSide::LastVertex, "Return last vertex of the i-th edge (count starts from zero)", py::arg("i"));
	cls_StdMeshers_FaceSide.def("IsClosed", (bool (StdMeshers_FaceSide::*)() const ) &StdMeshers_FaceSide::IsClosed, "Return true if the chain of EDGEs is closed");
	cls_StdMeshers_FaceSide.def("Length", (double (StdMeshers_FaceSide::*)() const ) &StdMeshers_FaceSide::Length, "Return side length");
	cls_StdMeshers_FaceSide.def("EdgeIndex", (int (StdMeshers_FaceSide::*)(double) const ) &StdMeshers_FaceSide::EdgeIndex, "Return edge index corresponding to normalized parameter", py::arg("U"));
	cls_StdMeshers_FaceSide.def("dump", [](StdMeshers_FaceSide &self) -> void { return self.dump(); });
	cls_StdMeshers_FaceSide.def("dump", (void (StdMeshers_FaceSide::*)(const char *) const ) &StdMeshers_FaceSide::dump, "None", py::arg("msg"));
	cls_StdMeshers_FaceSide.def("EdgeID", (int (StdMeshers_FaceSide::*)(int) const ) &StdMeshers_FaceSide::EdgeID, "Return ID of i-th wrapped edge (count starts from zero)", py::arg("i"));
	cls_StdMeshers_FaceSide.def("Curve2d", (opencascade::handle<Geom2d_Curve> (StdMeshers_FaceSide::*)(int) const ) &StdMeshers_FaceSide::Curve2d, "Return p-curve of i-th wrapped edge (count starts from zero)", py::arg("i"));
	cls_StdMeshers_FaceSide.def("FirstParameter", (double (StdMeshers_FaceSide::*)(int) const ) &StdMeshers_FaceSide::FirstParameter, "Return first normalized parameter of the i-th edge (count starts from zero)", py::arg("i"));
	cls_StdMeshers_FaceSide.def("LastParameter", (double (StdMeshers_FaceSide::*)(int) const ) &StdMeshers_FaceSide::LastParameter, "Return last normalized parameter of the i-th edge (count starts from zero)", py::arg("i"));
	cls_StdMeshers_FaceSide.def("FirstU", (double (StdMeshers_FaceSide::*)(int) const ) &StdMeshers_FaceSide::FirstU, "Return first parameter of the i-th edge (count starts from zero). EDGE orientation is taken into account", py::arg("i"));
	cls_StdMeshers_FaceSide.def("LastU", (double (StdMeshers_FaceSide::*)(int) const ) &StdMeshers_FaceSide::LastU, "Return last parameter of the i-th edge (count starts from zero). EDGE orientation is taken into account", py::arg("i"));
	cls_StdMeshers_FaceSide.def("EdgeLength", (double (StdMeshers_FaceSide::*)(int) const ) &StdMeshers_FaceSide::EdgeLength, "Return length of i-th wrapped edge (count starts from zero)", py::arg("i"));
	cls_StdMeshers_FaceSide.def("IsReversed", (bool (StdMeshers_FaceSide::*)(int) const ) &StdMeshers_FaceSide::IsReversed, "Return orientation of i-th wrapped edge (count starts from zero)", py::arg("i"));
	cls_StdMeshers_FaceSide.def("FaceHelper", (SMESH_MesherHelper * (StdMeshers_FaceSide::*)() const ) &StdMeshers_FaceSide::FaceHelper, "Return a helper initialized with the FACE");
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_FaceSide.hxx
	cls_StdMeshers_FaceSide.attr("ALL_EDGES") = py::cast(int(StdMeshers_FaceSide::ALL_EDGES));
	cls_StdMeshers_FaceSide.attr("LAST_EDGE") = py::cast(int(StdMeshers_FaceSide::LAST_EDGE));


	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_MaxElementArea.hxx
	py::class_<StdMeshers_MaxElementArea, std::unique_ptr<StdMeshers_MaxElementArea, py::nodelete>, SMESH_Hypothesis> cls_StdMeshers_MaxElementArea(mod, "StdMeshers_MaxElementArea", "None");
	cls_StdMeshers_MaxElementArea.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_MaxElementArea.def("SetMaxArea", (void (StdMeshers_MaxElementArea::*)(double)) &StdMeshers_MaxElementArea::SetMaxArea, "None", py::arg("maxArea"));
	cls_StdMeshers_MaxElementArea.def("GetMaxArea", (double (StdMeshers_MaxElementArea::*)() const ) &StdMeshers_MaxElementArea::GetMaxArea, "None");
	cls_StdMeshers_MaxElementArea.def("SaveTo", (std::ostream & (StdMeshers_MaxElementArea::*)(std::ostream &)) &StdMeshers_MaxElementArea::SaveTo, "None", py::arg("save"));
	cls_StdMeshers_MaxElementArea.def("LoadFrom", (std::istream & (StdMeshers_MaxElementArea::*)(std::istream &)) &StdMeshers_MaxElementArea::LoadFrom, "None", py::arg("load"));
	cls_StdMeshers_MaxElementArea.def("SetParametersByMesh", (bool (StdMeshers_MaxElementArea::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_MaxElementArea::SetParametersByMesh, "Initialize maximal area by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_MaxElementArea.def("SetParametersByDefaults", [](StdMeshers_MaxElementArea &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_MaxElementArea.def("SetParametersByDefaults", (bool (StdMeshers_MaxElementArea::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_MaxElementArea::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_LengthFromEdges.hxx
	py::class_<StdMeshers_LengthFromEdges, std::unique_ptr<StdMeshers_LengthFromEdges, py::nodelete>, SMESH_Hypothesis> cls_StdMeshers_LengthFromEdges(mod, "StdMeshers_LengthFromEdges", "None");
	cls_StdMeshers_LengthFromEdges.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_LengthFromEdges.def("SetMode", (void (StdMeshers_LengthFromEdges::*)(int)) &StdMeshers_LengthFromEdges::SetMode, "None", py::arg("mode"));
	cls_StdMeshers_LengthFromEdges.def("GetMode", (int (StdMeshers_LengthFromEdges::*)()) &StdMeshers_LengthFromEdges::GetMode, "None");
	cls_StdMeshers_LengthFromEdges.def("SaveTo", (std::ostream & (StdMeshers_LengthFromEdges::*)(std::ostream &)) &StdMeshers_LengthFromEdges::SaveTo, "None", py::arg("save"));
	cls_StdMeshers_LengthFromEdges.def("LoadFrom", (std::istream & (StdMeshers_LengthFromEdges::*)(std::istream &)) &StdMeshers_LengthFromEdges::LoadFrom, "None", py::arg("load"));
	cls_StdMeshers_LengthFromEdges.def("SetParametersByMesh", (bool (StdMeshers_LengthFromEdges::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_LengthFromEdges::SetParametersByMesh, "Initialize my parameter values by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_LengthFromEdges.def("SetParametersByDefaults", [](StdMeshers_LengthFromEdges &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_LengthFromEdges.def("SetParametersByDefaults", (bool (StdMeshers_LengthFromEdges::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_LengthFromEdges::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_ViscousLayers.hxx
	py::class_<StdMeshers_ViscousLayers, std::unique_ptr<StdMeshers_ViscousLayers, py::nodelete>, SMESH_Hypothesis> cls_StdMeshers_ViscousLayers(mod, "StdMeshers_ViscousLayers", "Hypothesis defining parameters of viscous layers");
	cls_StdMeshers_ViscousLayers.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_ViscousLayers.def("SetBndShapes", (void (StdMeshers_ViscousLayers::*)(const std::vector<int> &, bool)) &StdMeshers_ViscousLayers::SetBndShapes, "None", py::arg("shapeIds"), py::arg("toIgnore"));
	cls_StdMeshers_ViscousLayers.def("GetBndShapes", (std::vector<int> (StdMeshers_ViscousLayers::*)() const ) &StdMeshers_ViscousLayers::GetBndShapes, "None");
	cls_StdMeshers_ViscousLayers.def("IsToIgnoreShapes", (bool (StdMeshers_ViscousLayers::*)() const ) &StdMeshers_ViscousLayers::IsToIgnoreShapes, "None");
	cls_StdMeshers_ViscousLayers.def("SetTotalThickness", (void (StdMeshers_ViscousLayers::*)(double)) &StdMeshers_ViscousLayers::SetTotalThickness, "None", py::arg("thickness"));
	cls_StdMeshers_ViscousLayers.def("GetTotalThickness", (double (StdMeshers_ViscousLayers::*)() const ) &StdMeshers_ViscousLayers::GetTotalThickness, "None");
	cls_StdMeshers_ViscousLayers.def("SetNumberLayers", (void (StdMeshers_ViscousLayers::*)(int)) &StdMeshers_ViscousLayers::SetNumberLayers, "None", py::arg("nb"));
	cls_StdMeshers_ViscousLayers.def("GetNumberLayers", (int (StdMeshers_ViscousLayers::*)() const ) &StdMeshers_ViscousLayers::GetNumberLayers, "None");
	cls_StdMeshers_ViscousLayers.def("SetStretchFactor", (void (StdMeshers_ViscousLayers::*)(double)) &StdMeshers_ViscousLayers::SetStretchFactor, "None", py::arg("factor"));
	cls_StdMeshers_ViscousLayers.def("GetStretchFactor", (double (StdMeshers_ViscousLayers::*)() const ) &StdMeshers_ViscousLayers::GetStretchFactor, "None");
	cls_StdMeshers_ViscousLayers.def("SetMethod", (void (StdMeshers_ViscousLayers::*)(StdMeshers_ViscousLayers::ExtrusionMethod)) &StdMeshers_ViscousLayers::SetMethod, "None", py::arg("how"));
	cls_StdMeshers_ViscousLayers.def("GetMethod", (StdMeshers_ViscousLayers::ExtrusionMethod (StdMeshers_ViscousLayers::*)() const ) &StdMeshers_ViscousLayers::GetMethod, "None");
	cls_StdMeshers_ViscousLayers.def("Compute", [](StdMeshers_ViscousLayers &self, SMESH_Mesh & a0, const TopoDS_Shape & a1) -> SMESH_ProxyMesh::Ptr { return self.Compute(a0, a1); }, py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_ViscousLayers.def("Compute", (SMESH_ProxyMesh::Ptr (StdMeshers_ViscousLayers::*)(SMESH_Mesh &, const TopoDS_Shape &, const bool) const ) &StdMeshers_ViscousLayers::Compute, "None", py::arg("theMesh"), py::arg("theShape"), py::arg("toMakeN2NMap"));
	cls_StdMeshers_ViscousLayers.def_static("CheckHypothesis_", (SMESH_ComputeErrorPtr (*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &StdMeshers_ViscousLayers::CheckHypothesis, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));
	cls_StdMeshers_ViscousLayers.def("IsShapeWithLayers", (bool (StdMeshers_ViscousLayers::*)(int) const ) &StdMeshers_ViscousLayers::IsShapeWithLayers, "None", py::arg("shapeIndex"));
	cls_StdMeshers_ViscousLayers.def("SaveTo", (std::ostream & (StdMeshers_ViscousLayers::*)(std::ostream &)) &StdMeshers_ViscousLayers::SaveTo, "None", py::arg("save"));
	cls_StdMeshers_ViscousLayers.def("LoadFrom", (std::istream & (StdMeshers_ViscousLayers::*)(std::istream &)) &StdMeshers_ViscousLayers::LoadFrom, "None", py::arg("load"));
	cls_StdMeshers_ViscousLayers.def("SetParametersByMesh", (bool (StdMeshers_ViscousLayers::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_ViscousLayers::SetParametersByMesh, "Initialize my parameter values by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_ViscousLayers.def("SetParametersByDefaults", [](StdMeshers_ViscousLayers &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_ViscousLayers.def("SetParametersByDefaults", (bool (StdMeshers_ViscousLayers::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_ViscousLayers::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));
	cls_StdMeshers_ViscousLayers.def_static("GetHypType_", (const char * (*)()) &StdMeshers_ViscousLayers::GetHypType, "None");
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_ViscousLayers.hxx
	py::enum_<StdMeshers_ViscousLayers::ExtrusionMethod>(cls_StdMeshers_ViscousLayers, "ExtrusionMethod", "None")
		.value("SURF_OFFSET_SMOOTH", StdMeshers_ViscousLayers::ExtrusionMethod::SURF_OFFSET_SMOOTH)
		.value("FACE_OFFSET", StdMeshers_ViscousLayers::ExtrusionMethod::FACE_OFFSET)
		.value("NODE_OFFSET", StdMeshers_ViscousLayers::ExtrusionMethod::NODE_OFFSET)
		.export_values();

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_MaxElementVolume.hxx
	py::class_<StdMeshers_MaxElementVolume, std::unique_ptr<StdMeshers_MaxElementVolume, py::nodelete>, SMESH_Hypothesis> cls_StdMeshers_MaxElementVolume(mod, "StdMeshers_MaxElementVolume", "None");
	cls_StdMeshers_MaxElementVolume.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_MaxElementVolume.def("SetMaxVolume", (void (StdMeshers_MaxElementVolume::*)(double)) &StdMeshers_MaxElementVolume::SetMaxVolume, "None", py::arg("maxVolume"));
	cls_StdMeshers_MaxElementVolume.def("GetMaxVolume", (double (StdMeshers_MaxElementVolume::*)() const ) &StdMeshers_MaxElementVolume::GetMaxVolume, "None");
	cls_StdMeshers_MaxElementVolume.def("SaveTo", (std::ostream & (StdMeshers_MaxElementVolume::*)(std::ostream &)) &StdMeshers_MaxElementVolume::SaveTo, "None", py::arg("save"));
	cls_StdMeshers_MaxElementVolume.def("LoadFrom", (std::istream & (StdMeshers_MaxElementVolume::*)(std::istream &)) &StdMeshers_MaxElementVolume::LoadFrom, "None", py::arg("load"));
	cls_StdMeshers_MaxElementVolume.def("SetParametersByMesh", (bool (StdMeshers_MaxElementVolume::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_MaxElementVolume::SetParametersByMesh, "Initialize maximal volume by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_MaxElementVolume.def("SetParametersByDefaults", [](StdMeshers_MaxElementVolume &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_MaxElementVolume.def("SetParametersByDefaults", (bool (StdMeshers_MaxElementVolume::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_MaxElementVolume::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Adaptive1D.hxx
	py::class_<StdMeshers_Adaptive1D, std::unique_ptr<StdMeshers_Adaptive1D, py::nodelete>, SMESH_Hypothesis> cls_StdMeshers_Adaptive1D(mod, "StdMeshers_Adaptive1D", "Adaptive 1D hypothesis");
	cls_StdMeshers_Adaptive1D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_Adaptive1D.def("SetMinSize", (void (StdMeshers_Adaptive1D::*)(double)) &StdMeshers_Adaptive1D::SetMinSize, "Sets minimal allowed segment length", py::arg("minSegLen"));
	cls_StdMeshers_Adaptive1D.def("GetMinSize", (double (StdMeshers_Adaptive1D::*)() const ) &StdMeshers_Adaptive1D::GetMinSize, "None");
	cls_StdMeshers_Adaptive1D.def("SetMaxSize", (void (StdMeshers_Adaptive1D::*)(double)) &StdMeshers_Adaptive1D::SetMaxSize, "Sets maximal allowed segment length", py::arg("maxSegLen"));
	cls_StdMeshers_Adaptive1D.def("GetMaxSize", (double (StdMeshers_Adaptive1D::*)() const ) &StdMeshers_Adaptive1D::GetMaxSize, "None");
	cls_StdMeshers_Adaptive1D.def("SetDeflection", (void (StdMeshers_Adaptive1D::*)(double)) &StdMeshers_Adaptive1D::SetDeflection, "Sets <deflection> parameter value, i.e. a maximal allowed distance between a segment and an edge.", py::arg("value"));
	cls_StdMeshers_Adaptive1D.def("GetDeflection", (double (StdMeshers_Adaptive1D::*)() const ) &StdMeshers_Adaptive1D::GetDeflection, "None");
	cls_StdMeshers_Adaptive1D.def("SaveTo", (std::ostream & (StdMeshers_Adaptive1D::*)(std::ostream &)) &StdMeshers_Adaptive1D::SaveTo, "None", py::arg("save"));
	cls_StdMeshers_Adaptive1D.def("LoadFrom", (std::istream & (StdMeshers_Adaptive1D::*)(std::istream &)) &StdMeshers_Adaptive1D::LoadFrom, "None", py::arg("load"));
	cls_StdMeshers_Adaptive1D.def("SetParametersByMesh", (bool (StdMeshers_Adaptive1D::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_Adaptive1D::SetParametersByMesh, "Initialize deflection value by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_Adaptive1D.def("SetParametersByDefaults", [](StdMeshers_Adaptive1D &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_Adaptive1D.def("SetParametersByDefaults", (bool (StdMeshers_Adaptive1D::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_Adaptive1D::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));
	cls_StdMeshers_Adaptive1D.def("GetAlgo", (SMESH_Algo * (StdMeshers_Adaptive1D::*)() const ) &StdMeshers_Adaptive1D::GetAlgo, "Returns an algorithm that works using this hypothesis");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_FixedPoints1D.hxx
	py::class_<StdMeshers_FixedPoints1D, std::unique_ptr<StdMeshers_FixedPoints1D, py::nodelete>, SMESH_Hypothesis> cls_StdMeshers_FixedPoints1D(mod, "StdMeshers_FixedPoints1D", "None");
	cls_StdMeshers_FixedPoints1D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_FixedPoints1D.def("SetPoints", (void (StdMeshers_FixedPoints1D::*)(std::vector<double> &)) &StdMeshers_FixedPoints1D::SetPoints, "None", py::arg("listParams"));
	cls_StdMeshers_FixedPoints1D.def("SetNbSegments", (void (StdMeshers_FixedPoints1D::*)(std::vector<int> &)) &StdMeshers_FixedPoints1D::SetNbSegments, "None", py::arg("listNbSeg"));
	cls_StdMeshers_FixedPoints1D.def("GetPoints", (const std::vector<double> & (StdMeshers_FixedPoints1D::*)() const ) &StdMeshers_FixedPoints1D::GetPoints, "None");
	cls_StdMeshers_FixedPoints1D.def("GetNbSegments", (const std::vector<int> & (StdMeshers_FixedPoints1D::*)() const ) &StdMeshers_FixedPoints1D::GetNbSegments, "None");
	cls_StdMeshers_FixedPoints1D.def("SetReversedEdges", (void (StdMeshers_FixedPoints1D::*)(std::vector<int> &)) &StdMeshers_FixedPoints1D::SetReversedEdges, "None", py::arg("ids"));
	cls_StdMeshers_FixedPoints1D.def("SetObjectEntry", (void (StdMeshers_FixedPoints1D::*)(const char *)) &StdMeshers_FixedPoints1D::SetObjectEntry, "None", py::arg("entry"));
	cls_StdMeshers_FixedPoints1D.def("GetObjectEntry", (const char * (StdMeshers_FixedPoints1D::*)()) &StdMeshers_FixedPoints1D::GetObjectEntry, "None");
	cls_StdMeshers_FixedPoints1D.def("GetReversedEdges", (const std::vector<int> & (StdMeshers_FixedPoints1D::*)() const ) &StdMeshers_FixedPoints1D::GetReversedEdges, "None");
	cls_StdMeshers_FixedPoints1D.def("SaveTo", (std::ostream & (StdMeshers_FixedPoints1D::*)(std::ostream &)) &StdMeshers_FixedPoints1D::SaveTo, "None", py::arg("save"));
	cls_StdMeshers_FixedPoints1D.def("LoadFrom", (std::istream & (StdMeshers_FixedPoints1D::*)(std::istream &)) &StdMeshers_FixedPoints1D::LoadFrom, "None", py::arg("load"));
	cls_StdMeshers_FixedPoints1D.def("SetParametersByMesh", (bool (StdMeshers_FixedPoints1D::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_FixedPoints1D::SetParametersByMesh, "Initialize start and end length by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_FixedPoints1D.def("SetParametersByDefaults", [](StdMeshers_FixedPoints1D &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_FixedPoints1D.def("SetParametersByDefaults", (bool (StdMeshers_FixedPoints1D::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_FixedPoints1D::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_SegmentLengthAroundVertex.hxx
	py::class_<StdMeshers_SegmentLengthAroundVertex, std::unique_ptr<StdMeshers_SegmentLengthAroundVertex, py::nodelete>, SMESH_Hypothesis> cls_StdMeshers_SegmentLengthAroundVertex(mod, "StdMeshers_SegmentLengthAroundVertex", "This hypothesis specifies length of segments adjacent to the vertex the hypothesis is assigned to");
	cls_StdMeshers_SegmentLengthAroundVertex.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_SegmentLengthAroundVertex.def("SetLength", (void (StdMeshers_SegmentLengthAroundVertex::*)(double)) &StdMeshers_SegmentLengthAroundVertex::SetLength, "None", py::arg("length"));
	cls_StdMeshers_SegmentLengthAroundVertex.def("GetLength", (double (StdMeshers_SegmentLengthAroundVertex::*)() const ) &StdMeshers_SegmentLengthAroundVertex::GetLength, "None");
	cls_StdMeshers_SegmentLengthAroundVertex.def("SaveTo", (std::ostream & (StdMeshers_SegmentLengthAroundVertex::*)(std::ostream &)) &StdMeshers_SegmentLengthAroundVertex::SaveTo, "None", py::arg("save"));
	cls_StdMeshers_SegmentLengthAroundVertex.def("LoadFrom", (std::istream & (StdMeshers_SegmentLengthAroundVertex::*)(std::istream &)) &StdMeshers_SegmentLengthAroundVertex::LoadFrom, "None", py::arg("load"));
	cls_StdMeshers_SegmentLengthAroundVertex.def("SetParametersByMesh", (bool (StdMeshers_SegmentLengthAroundVertex::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_SegmentLengthAroundVertex::SetParametersByMesh, "Initialize segment length by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_SegmentLengthAroundVertex.def("SetParametersByDefaults", [](StdMeshers_SegmentLengthAroundVertex &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_SegmentLengthAroundVertex.def("SetParametersByDefaults", (bool (StdMeshers_SegmentLengthAroundVertex::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_SegmentLengthAroundVertex::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Regular_1D.hxx
	py::class_<StdMeshers_Regular_1D, std::unique_ptr<StdMeshers_Regular_1D, py::nodelete>, SMESH_1D_Algo> cls_StdMeshers_Regular_1D(mod, "StdMeshers_Regular_1D", "None");
	cls_StdMeshers_Regular_1D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_Regular_1D.def("CheckHypothesis", (bool (StdMeshers_Regular_1D::*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &StdMeshers_Regular_1D::CheckHypothesis, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));
	cls_StdMeshers_Regular_1D.def("Compute", (bool (StdMeshers_Regular_1D::*)(SMESH_Mesh &, const TopoDS_Shape &)) &StdMeshers_Regular_1D::Compute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_StdMeshers_Regular_1D.def("Evaluate", (bool (StdMeshers_Regular_1D::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &StdMeshers_Regular_1D::Evaluate, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));
	cls_StdMeshers_Regular_1D.def("CancelCompute", (void (StdMeshers_Regular_1D::*)()) &StdMeshers_Regular_1D::CancelCompute, "None");
	cls_StdMeshers_Regular_1D.def("GetUsedHypothesis", [](StdMeshers_Regular_1D &self, SMESH_Mesh & a0, const TopoDS_Shape & a1) -> const std::list<const SMESHDS_Hypothesis *> & { return self.GetUsedHypothesis(a0, a1); }, py::arg("aMesh"), py::arg("aShape"));
	cls_StdMeshers_Regular_1D.def("GetUsedHypothesis", (const std::list<const SMESHDS_Hypothesis *> & (StdMeshers_Regular_1D::*)(SMESH_Mesh &, const TopoDS_Shape &, const bool)) &StdMeshers_Regular_1D::GetUsedHypothesis, "None", py::arg("aMesh"), py::arg("aShape"), py::arg(""));
	cls_StdMeshers_Regular_1D.def("SetEventListener", (void (StdMeshers_Regular_1D::*)(SMESH_subMesh *)) &StdMeshers_Regular_1D::SetEventListener, "Sets event listener to submeshes if necessary", py::arg("subMesh"));
	cls_StdMeshers_Regular_1D.def("SubmeshRestored", (void (StdMeshers_Regular_1D::*)(SMESH_subMesh *)) &StdMeshers_Regular_1D::SubmeshRestored, "Allow algo to do something after persistent restoration", py::arg("subMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Arithmetic1D.hxx
	py::class_<StdMeshers_Arithmetic1D, std::unique_ptr<StdMeshers_Arithmetic1D, py::nodelete>, SMESH_Hypothesis> cls_StdMeshers_Arithmetic1D(mod, "StdMeshers_Arithmetic1D", "None");
	cls_StdMeshers_Arithmetic1D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_Arithmetic1D.def("SetLength", (void (StdMeshers_Arithmetic1D::*)(double, bool)) &StdMeshers_Arithmetic1D::SetLength, "None", py::arg("length"), py::arg("isStartLength"));
	cls_StdMeshers_Arithmetic1D.def("GetLength", (double (StdMeshers_Arithmetic1D::*)(bool) const ) &StdMeshers_Arithmetic1D::GetLength, "None", py::arg("isStartLength"));
	cls_StdMeshers_Arithmetic1D.def("SetReversedEdges", (void (StdMeshers_Arithmetic1D::*)(std::vector<int> &)) &StdMeshers_Arithmetic1D::SetReversedEdges, "None", py::arg("ids"));
	cls_StdMeshers_Arithmetic1D.def("SetObjectEntry", (void (StdMeshers_Arithmetic1D::*)(const char *)) &StdMeshers_Arithmetic1D::SetObjectEntry, "None", py::arg("entry"));
	cls_StdMeshers_Arithmetic1D.def("GetObjectEntry", (const char * (StdMeshers_Arithmetic1D::*)()) &StdMeshers_Arithmetic1D::GetObjectEntry, "None");
	cls_StdMeshers_Arithmetic1D.def("GetReversedEdges", (const std::vector<int> & (StdMeshers_Arithmetic1D::*)() const ) &StdMeshers_Arithmetic1D::GetReversedEdges, "None");
	cls_StdMeshers_Arithmetic1D.def("SaveTo", (std::ostream & (StdMeshers_Arithmetic1D::*)(std::ostream &)) &StdMeshers_Arithmetic1D::SaveTo, "None", py::arg("save"));
	cls_StdMeshers_Arithmetic1D.def("LoadFrom", (std::istream & (StdMeshers_Arithmetic1D::*)(std::istream &)) &StdMeshers_Arithmetic1D::LoadFrom, "None", py::arg("load"));
	cls_StdMeshers_Arithmetic1D.def("SetParametersByMesh", (bool (StdMeshers_Arithmetic1D::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_Arithmetic1D::SetParametersByMesh, "Initialize start and end length by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_Arithmetic1D.def("SetParametersByDefaults", [](StdMeshers_Arithmetic1D &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_Arithmetic1D.def("SetParametersByDefaults", (bool (StdMeshers_Arithmetic1D::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_Arithmetic1D::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_AutomaticLength.hxx
	py::class_<StdMeshers_AutomaticLength, std::unique_ptr<StdMeshers_AutomaticLength, py::nodelete>, SMESH_Hypothesis> cls_StdMeshers_AutomaticLength(mod, "StdMeshers_AutomaticLength", "1D Hypothesis to compute segment length free of thinking");
	cls_StdMeshers_AutomaticLength.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_AutomaticLength.def("GetLength", (double (StdMeshers_AutomaticLength::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_AutomaticLength::GetLength, "Computes segment for a given edge", py::arg("aMesh"), py::arg("anEdge"));
	cls_StdMeshers_AutomaticLength.def("GetLength", (double (StdMeshers_AutomaticLength::*)(const SMESH_Mesh *, const double)) &StdMeshers_AutomaticLength::GetLength, "Computes segment length for an edge of given length", py::arg("aMesh"), py::arg("edgeLength"));
	cls_StdMeshers_AutomaticLength.def("SetFineness", (void (StdMeshers_AutomaticLength::*)(double)) &StdMeshers_AutomaticLength::SetFineness, "Set Fineness", py::arg("theFineness"));
	cls_StdMeshers_AutomaticLength.def("GetFineness", (double (StdMeshers_AutomaticLength::*)() const ) &StdMeshers_AutomaticLength::GetFineness, "Return mesh Fineness double - Fineness value [0.0-1.0]");
	cls_StdMeshers_AutomaticLength.def("SaveTo", (std::ostream & (StdMeshers_AutomaticLength::*)(std::ostream &)) &StdMeshers_AutomaticLength::SaveTo, "None", py::arg("save"));
	cls_StdMeshers_AutomaticLength.def("LoadFrom", (std::istream & (StdMeshers_AutomaticLength::*)(std::istream &)) &StdMeshers_AutomaticLength::LoadFrom, "None", py::arg("load"));
	cls_StdMeshers_AutomaticLength.def("SetParametersByMesh", (bool (StdMeshers_AutomaticLength::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_AutomaticLength::SetParametersByMesh, "Initialize Fineness by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_AutomaticLength.def("SetParametersByDefaults", [](StdMeshers_AutomaticLength &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_AutomaticLength.def("SetParametersByDefaults", (bool (StdMeshers_AutomaticLength::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_AutomaticLength::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_CartesianParameters3D.hxx
	py::class_<StdMeshers_CartesianParameters3D, std::unique_ptr<StdMeshers_CartesianParameters3D, py::nodelete>, SMESH_Hypothesis> cls_StdMeshers_CartesianParameters3D(mod, "StdMeshers_CartesianParameters3D", "This hypothesis specifies - Definition of the Cartesian grid - Size threshold");
	cls_StdMeshers_CartesianParameters3D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_CartesianParameters3D.def("SetGrid", (void (StdMeshers_CartesianParameters3D::*)(std::vector<double> &, int)) &StdMeshers_CartesianParameters3D::SetGrid, "Sets coordinates of node positions along an axis (countered from 0)", py::arg("xNodes"), py::arg("axis"));
	cls_StdMeshers_CartesianParameters3D.def("GetGrid", (void (StdMeshers_CartesianParameters3D::*)(std::vector<double> &, int) const ) &StdMeshers_CartesianParameters3D::GetGrid, "Return coordinates of node positions along the three axes", py::arg("xNodes"), py::arg("axis"));
	cls_StdMeshers_CartesianParameters3D.def("SetGridSpacing", (void (StdMeshers_CartesianParameters3D::*)(std::vector<std::string> &, std::vector<double> &, const int)) &StdMeshers_CartesianParameters3D::SetGridSpacing, "Set grid spacing along the three axes", py::arg("spaceFunctions"), py::arg("internalPoints"), py::arg("axis"));
	cls_StdMeshers_CartesianParameters3D.def("GetGridSpacing", (void (StdMeshers_CartesianParameters3D::*)(std::vector<std::string> &, std::vector<double> &, const int) const ) &StdMeshers_CartesianParameters3D::GetGridSpacing, "None", py::arg("spaceFunctions"), py::arg("internalPoints"), py::arg("axis"));
	cls_StdMeshers_CartesianParameters3D.def("IsGridBySpacing", (bool (StdMeshers_CartesianParameters3D::*)(const int) const ) &StdMeshers_CartesianParameters3D::IsGridBySpacing, "None", py::arg("axis"));
	// FIXME cls_StdMeshers_CartesianParameters3D.def("SetFixedPoint", (void (StdMeshers_CartesianParameters3D::*)(const double [3], bool)) &StdMeshers_CartesianParameters3D::SetFixedPoint, "Set/unset a fixed point, at which a node will be created provided that grid is defined by spacing in all directions", py::arg("p"), py::arg("toUnset"));
	// FIXME cls_StdMeshers_CartesianParameters3D.def("GetFixedPoint", (bool (StdMeshers_CartesianParameters3D::*)(double [3]) const ) &StdMeshers_CartesianParameters3D::GetFixedPoint, "None", py::arg("p"));
	cls_StdMeshers_CartesianParameters3D.def_static("ComputeCoordinates_", [](const double a0, const double a1, std::vector<std::string> & a2, std::vector<double> & a3, std::vector<double> & a4, const std::string & a5) -> void { return StdMeshers_CartesianParameters3D::ComputeCoordinates(a0, a1, a2, a3, a4, a5); }, py::arg("x0"), py::arg("x1"), py::arg("spaceFuns"), py::arg("points"), py::arg("coords"), py::arg("axis"));
	cls_StdMeshers_CartesianParameters3D.def_static("ComputeCoordinates_", (void (*)(const double, const double, std::vector<std::string> &, std::vector<double> &, std::vector<double> &, const std::string &, const double *)) &StdMeshers_CartesianParameters3D::ComputeCoordinates, "Computes node coordinates by spacing functions", py::arg("x0"), py::arg("x1"), py::arg("spaceFuns"), py::arg("points"), py::arg("coords"), py::arg("axis"), py::arg("xForced"));
	cls_StdMeshers_CartesianParameters3D.def("GetCoordinates", (void (StdMeshers_CartesianParameters3D::*)(std::vector<double> &, std::vector<double> &, std::vector<double> &, const Bnd_Box &) const ) &StdMeshers_CartesianParameters3D::GetCoordinates, "Return coordinates of node positions along the three axes. If the grid is defined by spacing functions, the coordinates are computed", py::arg("xNodes"), py::arg("yNodes"), py::arg("zNodes"), py::arg("bndBox"));
	cls_StdMeshers_CartesianParameters3D.def("SetAxisDirs", (void (StdMeshers_CartesianParameters3D::*)(const double *)) &StdMeshers_CartesianParameters3D::SetAxisDirs, "Set custom direction of axes", py::arg("the9DirComps"));
	cls_StdMeshers_CartesianParameters3D.def("GetAxisDirs", (const double * (StdMeshers_CartesianParameters3D::*)() const ) &StdMeshers_CartesianParameters3D::GetAxisDirs, "None");
	// FIXME cls_StdMeshers_CartesianParameters3D.def_static("ComputeOptimalAxesDirs_", (void (*)(const TopoDS_Shape &, const bool, double [9])) &StdMeshers_CartesianParameters3D::ComputeOptimalAxesDirs, "Returns axes at which number of hexahedra is maximal", py::arg("shape"), py::arg("isOrthogonal"), py::arg("dirCoords"));
	cls_StdMeshers_CartesianParameters3D.def("SetSizeThreshold", (void (StdMeshers_CartesianParameters3D::*)(const double)) &StdMeshers_CartesianParameters3D::SetSizeThreshold, "Set size threshold. A polyhedral cell got by cutting an initial hexahedron by geometry boundary is considered small and is removed if it's size is times less than the size of the initial hexahedron.", py::arg("threshold"));
	cls_StdMeshers_CartesianParameters3D.def("GetSizeThreshold", (double (StdMeshers_CartesianParameters3D::*)() const ) &StdMeshers_CartesianParameters3D::GetSizeThreshold, "Return size threshold");
	cls_StdMeshers_CartesianParameters3D.def("SetToAddEdges", (void (StdMeshers_CartesianParameters3D::*)(bool)) &StdMeshers_CartesianParameters3D::SetToAddEdges, "Enables implementation of geometrical edges into the mesh. If this feature is disabled, sharp edges of the shape are lost ('smoothed') in the mesh if they don't coincide with the grid lines", py::arg("toAdd"));
	cls_StdMeshers_CartesianParameters3D.def("GetToAddEdges", (bool (StdMeshers_CartesianParameters3D::*)() const ) &StdMeshers_CartesianParameters3D::GetToAddEdges, "None");
	cls_StdMeshers_CartesianParameters3D.def("IsDefined", (bool (StdMeshers_CartesianParameters3D::*)() const ) &StdMeshers_CartesianParameters3D::IsDefined, "Return true if parameters are well defined");
	cls_StdMeshers_CartesianParameters3D.def("SaveTo", (std::ostream & (StdMeshers_CartesianParameters3D::*)(std::ostream &)) &StdMeshers_CartesianParameters3D::SaveTo, "Persistence methods", py::arg("save"));
	cls_StdMeshers_CartesianParameters3D.def("LoadFrom", (std::istream & (StdMeshers_CartesianParameters3D::*)(std::istream &)) &StdMeshers_CartesianParameters3D::LoadFrom, "None", py::arg("load"));
	cls_StdMeshers_CartesianParameters3D.def("SetParametersByMesh", (bool (StdMeshers_CartesianParameters3D::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_CartesianParameters3D::SetParametersByMesh, "Initialize my parameter values by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_CartesianParameters3D.def("SetParametersByDefaults", [](StdMeshers_CartesianParameters3D &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_CartesianParameters3D.def("SetParametersByDefaults", (bool (StdMeshers_CartesianParameters3D::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_CartesianParameters3D::SetParametersByDefaults, "Initialize my parameter values by default parameters.", py::arg("dflts"), py::arg("theMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Cartesian_3D.hxx
	py::class_<StdMeshers_Cartesian_3D, std::unique_ptr<StdMeshers_Cartesian_3D, py::nodelete>, SMESH_3D_Algo> cls_StdMeshers_Cartesian_3D(mod, "StdMeshers_Cartesian_3D", "None");
	cls_StdMeshers_Cartesian_3D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_Cartesian_3D.def("CheckHypothesis", (bool (StdMeshers_Cartesian_3D::*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &StdMeshers_Cartesian_3D::CheckHypothesis, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));
	cls_StdMeshers_Cartesian_3D.def("Compute", (bool (StdMeshers_Cartesian_3D::*)(SMESH_Mesh &, const TopoDS_Shape &)) &StdMeshers_Cartesian_3D::Compute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_StdMeshers_Cartesian_3D.def("Evaluate", (bool (StdMeshers_Cartesian_3D::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &StdMeshers_Cartesian_3D::Evaluate, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));
	cls_StdMeshers_Cartesian_3D.def("SetEventListener", (void (StdMeshers_Cartesian_3D::*)(SMESH_subMesh *)) &StdMeshers_Cartesian_3D::SetEventListener, "None", py::arg("subMesh"));

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_CompositeHexa_3D.hxx
	py::class_<_QuadFaceGrid, std::unique_ptr<_QuadFaceGrid, Deleter<_QuadFaceGrid>>> cls__QuadFaceGrid(mod, "_QuadFaceGrid", "None");
	cls__QuadFaceGrid.def(py::init<>());
	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_CompositeHexa_3D.hxx
	py::class_<StdMeshers_CompositeHexa_3D, std::unique_ptr<StdMeshers_CompositeHexa_3D, py::nodelete>, SMESH_3D_Algo> cls_StdMeshers_CompositeHexa_3D(mod, "StdMeshers_CompositeHexa_3D", "Computes hexahedral mesh on a box with composite sides");
	cls_StdMeshers_CompositeHexa_3D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_CompositeHexa_3D.def("Compute", (bool (StdMeshers_CompositeHexa_3D::*)(SMESH_Mesh &, const TopoDS_Shape &)) &StdMeshers_CompositeHexa_3D::Compute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_StdMeshers_CompositeHexa_3D.def("Evaluate", (bool (StdMeshers_CompositeHexa_3D::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &StdMeshers_CompositeHexa_3D::Evaluate, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));
	cls_StdMeshers_CompositeHexa_3D.def("CheckHypothesis", (bool (StdMeshers_CompositeHexa_3D::*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &StdMeshers_CompositeHexa_3D::CheckHypothesis, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_CompositeSegment_1D.hxx
	py::class_<StdMeshers_CompositeSegment_1D, std::unique_ptr<StdMeshers_CompositeSegment_1D, py::nodelete>, StdMeshers_Regular_1D> cls_StdMeshers_CompositeSegment_1D(mod, "StdMeshers_CompositeSegment_1D", "None");
	cls_StdMeshers_CompositeSegment_1D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_CompositeSegment_1D.def("Compute", (bool (StdMeshers_CompositeSegment_1D::*)(SMESH_Mesh &, const TopoDS_Shape &)) &StdMeshers_CompositeSegment_1D::Compute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_StdMeshers_CompositeSegment_1D.def("SetEventListener", (void (StdMeshers_CompositeSegment_1D::*)(SMESH_subMesh *)) &StdMeshers_CompositeSegment_1D::SetEventListener, "Sets event listener to submeshes if necessary", py::arg("subMesh"));
	cls_StdMeshers_CompositeSegment_1D.def_static("GetFaceSide_", (StdMeshers_FaceSide * (*)(SMESH_Mesh &, const TopoDS_Edge &, const TopoDS_Face &, const bool)) &StdMeshers_CompositeSegment_1D::GetFaceSide, "Return a face side the edge belongs to", py::arg("aMesh"), py::arg("anEdge"), py::arg("aFace"), py::arg("ignoreMeshed"));
	cls_StdMeshers_CompositeSegment_1D.def_static("AlgoName_", (std::string(*)()) &StdMeshers_CompositeSegment_1D::AlgoName, "Returns algo type name");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Deflection1D.hxx
	py::class_<StdMeshers_Deflection1D, std::unique_ptr<StdMeshers_Deflection1D, py::nodelete>, SMESH_Hypothesis> cls_StdMeshers_Deflection1D(mod, "StdMeshers_Deflection1D", "None");
	cls_StdMeshers_Deflection1D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_Deflection1D.def("SetDeflection", (void (StdMeshers_Deflection1D::*)(double)) &StdMeshers_Deflection1D::SetDeflection, "None", py::arg("value"));
	cls_StdMeshers_Deflection1D.def("GetDeflection", (double (StdMeshers_Deflection1D::*)() const ) &StdMeshers_Deflection1D::GetDeflection, "None");
	cls_StdMeshers_Deflection1D.def("SaveTo", (std::ostream & (StdMeshers_Deflection1D::*)(std::ostream &)) &StdMeshers_Deflection1D::SaveTo, "None", py::arg("save"));
	cls_StdMeshers_Deflection1D.def("LoadFrom", (std::istream & (StdMeshers_Deflection1D::*)(std::istream &)) &StdMeshers_Deflection1D::LoadFrom, "None", py::arg("load"));
	cls_StdMeshers_Deflection1D.def("SetParametersByMesh", (bool (StdMeshers_Deflection1D::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_Deflection1D::SetParametersByMesh, "Initialize deflection value by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_Deflection1D.def("SetParametersByDefaults", [](StdMeshers_Deflection1D &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_Deflection1D.def("SetParametersByDefaults", (bool (StdMeshers_Deflection1D::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_Deflection1D::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));

	// Callback for StdMeshers_Reversible1D.
	class PyCallback_StdMeshers_Reversible1D : public StdMeshers_Reversible1D {
	public:
		using StdMeshers_Reversible1D::StdMeshers_Reversible1D;

		bool SetParametersByMesh(const SMESH_Mesh * theMesh, const TopoDS_Shape & theShape) override { PYBIND11_OVERLOAD_PURE(bool, StdMeshers_Reversible1D, SetParametersByMesh, theMesh, theShape); }
		bool SetParametersByDefaults(const SMESH_Hypothesis::TDefaults & dflts, const SMESH_Mesh * theMesh) override { PYBIND11_OVERLOAD_PURE(bool, StdMeshers_Reversible1D, SetParametersByDefaults, dflts, theMesh); }
	};

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Reversible1D.hxx
	py::class_<StdMeshers_Reversible1D, std::unique_ptr<StdMeshers_Reversible1D, py::nodelete>, PyCallback_StdMeshers_Reversible1D, SMESH_Hypothesis> cls_StdMeshers_Reversible1D(mod, "StdMeshers_Reversible1D", "A base of reversible 1D hypotheses");
	cls_StdMeshers_Reversible1D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_Reversible1D.def("SetReversedEdges", (void (StdMeshers_Reversible1D::*)(const std::vector<int> &)) &StdMeshers_Reversible1D::SetReversedEdges, "None", py::arg("ids"));
	cls_StdMeshers_Reversible1D.def("SetObjectEntry", (void (StdMeshers_Reversible1D::*)(const char *)) &StdMeshers_Reversible1D::SetObjectEntry, "None", py::arg("entry"));
	cls_StdMeshers_Reversible1D.def("GetObjectEntry", (const char * (StdMeshers_Reversible1D::*)()) &StdMeshers_Reversible1D::GetObjectEntry, "None");
	cls_StdMeshers_Reversible1D.def("GetReversedEdges", (const std::vector<int> & (StdMeshers_Reversible1D::*)() const ) &StdMeshers_Reversible1D::GetReversedEdges, "None");
	cls_StdMeshers_Reversible1D.def("SaveTo", (std::ostream & (StdMeshers_Reversible1D::*)(std::ostream &)) &StdMeshers_Reversible1D::SaveTo, "None", py::arg("save"));
	cls_StdMeshers_Reversible1D.def("LoadFrom", (std::istream & (StdMeshers_Reversible1D::*)(std::istream &)) &StdMeshers_Reversible1D::LoadFrom, "None", py::arg("load"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Geometric1D.hxx
	py::class_<StdMeshers_Geometric1D, std::unique_ptr<StdMeshers_Geometric1D, py::nodelete>, StdMeshers_Reversible1D> cls_StdMeshers_Geometric1D(mod, "StdMeshers_Geometric1D", "None");
	cls_StdMeshers_Geometric1D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_Geometric1D.def("SetStartLength", (void (StdMeshers_Geometric1D::*)(double)) &StdMeshers_Geometric1D::SetStartLength, "None", py::arg("length"));
	cls_StdMeshers_Geometric1D.def("SetCommonRatio", (void (StdMeshers_Geometric1D::*)(double)) &StdMeshers_Geometric1D::SetCommonRatio, "None", py::arg("factor"));
	cls_StdMeshers_Geometric1D.def("GetStartLength", (double (StdMeshers_Geometric1D::*)() const ) &StdMeshers_Geometric1D::GetStartLength, "None");
	cls_StdMeshers_Geometric1D.def("GetCommonRatio", (double (StdMeshers_Geometric1D::*)() const ) &StdMeshers_Geometric1D::GetCommonRatio, "None");
	cls_StdMeshers_Geometric1D.def("SaveTo", (std::ostream & (StdMeshers_Geometric1D::*)(std::ostream &)) &StdMeshers_Geometric1D::SaveTo, "None", py::arg("save"));
	cls_StdMeshers_Geometric1D.def("LoadFrom", (std::istream & (StdMeshers_Geometric1D::*)(std::istream &)) &StdMeshers_Geometric1D::LoadFrom, "None", py::arg("load"));
	cls_StdMeshers_Geometric1D.def("SetParametersByMesh", (bool (StdMeshers_Geometric1D::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_Geometric1D::SetParametersByMesh, "Initialize start and end length by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_Geometric1D.def("SetParametersByDefaults", [](StdMeshers_Geometric1D &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_Geometric1D.def("SetParametersByDefaults", (bool (StdMeshers_Geometric1D::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_Geometric1D::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_HexaFromSkin_3D.hxx
	py::class_<StdMeshers_HexaFromSkin_3D, std::unique_ptr<StdMeshers_HexaFromSkin_3D, py::nodelete>, SMESH_3D_Algo> cls_StdMeshers_HexaFromSkin_3D(mod, "StdMeshers_HexaFromSkin_3D", "Alorithm generating hexahedral mesh from 2D skin of block");
	cls_StdMeshers_HexaFromSkin_3D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_HexaFromSkin_3D.def("Compute", (bool (StdMeshers_HexaFromSkin_3D::*)(SMESH_Mesh &, SMESH_MesherHelper *)) &StdMeshers_HexaFromSkin_3D::Compute, "None", py::arg("aMesh"), py::arg("aHelper"));
	cls_StdMeshers_HexaFromSkin_3D.def("CheckHypothesis", (bool (StdMeshers_HexaFromSkin_3D::*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &StdMeshers_HexaFromSkin_3D::CheckHypothesis, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));
	cls_StdMeshers_HexaFromSkin_3D.def("Compute", (bool (StdMeshers_HexaFromSkin_3D::*)(SMESH_Mesh &, const TopoDS_Shape &)) &StdMeshers_HexaFromSkin_3D::Compute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_StdMeshers_HexaFromSkin_3D.def("Evaluate", (bool (StdMeshers_HexaFromSkin_3D::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &StdMeshers_HexaFromSkin_3D::Evaluate, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Hexa_3D.hxx
	py::class_<StdMeshers_Hexa_3D, std::unique_ptr<StdMeshers_Hexa_3D, py::nodelete>, SMESH_3D_Algo> cls_StdMeshers_Hexa_3D(mod, "StdMeshers_Hexa_3D", "None");
	cls_StdMeshers_Hexa_3D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_Hexa_3D.def("CheckHypothesis", (bool (StdMeshers_Hexa_3D::*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &StdMeshers_Hexa_3D::CheckHypothesis, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));
	cls_StdMeshers_Hexa_3D.def("Compute", (bool (StdMeshers_Hexa_3D::*)(SMESH_Mesh &, const TopoDS_Shape &)) &StdMeshers_Hexa_3D::Compute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_StdMeshers_Hexa_3D.def("Compute", (bool (StdMeshers_Hexa_3D::*)(SMESH_Mesh &, SMESH_MesherHelper *)) &StdMeshers_Hexa_3D::Compute, "None", py::arg("aMesh"), py::arg("aHelper"));
	cls_StdMeshers_Hexa_3D.def("Evaluate", (bool (StdMeshers_Hexa_3D::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &StdMeshers_Hexa_3D::Evaluate, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));
	cls_StdMeshers_Hexa_3D.def_static("IsApplicable_", (bool (*)(const TopoDS_Shape &, bool)) &StdMeshers_Hexa_3D::IsApplicable, "None", py::arg("aShape"), py::arg("toCheckAll"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_ImportSource.hxx
	py::class_<StdMeshers_ImportSource1D, std::unique_ptr<StdMeshers_ImportSource1D, py::nodelete>, SMESH_Hypothesis> cls_StdMeshers_ImportSource1D(mod, "StdMeshers_ImportSource1D", "Stores groups to import elements from");
	cls_StdMeshers_ImportSource1D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_ImportSource1D.def("SetGroups", (void (StdMeshers_ImportSource1D::*)(const std::vector<SMESH_Group *> &)) &StdMeshers_ImportSource1D::SetGroups, "None", py::arg("groups"));
	cls_StdMeshers_ImportSource1D.def("GetGroups", [](StdMeshers_ImportSource1D &self) -> const std::vector<SMESH_Group *> & { return self.GetGroups(); });
	cls_StdMeshers_ImportSource1D.def("GetGroups", (const std::vector<SMESH_Group *> & (StdMeshers_ImportSource1D::*)(bool) const ) &StdMeshers_ImportSource1D::GetGroups, "None", py::arg("loaded"));
	cls_StdMeshers_ImportSource1D.def("SetCopySourceMesh", (void (StdMeshers_ImportSource1D::*)(bool, bool)) &StdMeshers_ImportSource1D::SetCopySourceMesh, "None", py::arg("toCopyMesh"), py::arg("toCopyGroups"));
	cls_StdMeshers_ImportSource1D.def("GetCopySourceMesh", (void (StdMeshers_ImportSource1D::*)(bool &, bool &) const ) &StdMeshers_ImportSource1D::GetCopySourceMesh, "None", py::arg("toCopyMesh"), py::arg("toCopyGroups"));
	cls_StdMeshers_ImportSource1D.def("SaveTo", (std::ostream & (StdMeshers_ImportSource1D::*)(std::ostream &)) &StdMeshers_ImportSource1D::SaveTo, "None", py::arg("save"));
	cls_StdMeshers_ImportSource1D.def("LoadFrom", (std::istream & (StdMeshers_ImportSource1D::*)(std::istream &)) &StdMeshers_ImportSource1D::LoadFrom, "None", py::arg("load"));
	cls_StdMeshers_ImportSource1D.def("SetParametersByMesh", (bool (StdMeshers_ImportSource1D::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_ImportSource1D::SetParametersByMesh, "None", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_ImportSource1D.def("SetParametersByDefaults", [](StdMeshers_ImportSource1D &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_ImportSource1D.def("SetParametersByDefaults", (bool (StdMeshers_ImportSource1D::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_ImportSource1D::SetParametersByDefaults, "None", py::arg("dflts"), py::arg("theMesh"));
	cls_StdMeshers_ImportSource1D.def("DataDependOnParams", (bool (StdMeshers_ImportSource1D::*)() const ) &StdMeshers_ImportSource1D::DataDependOnParams, "None");
	cls_StdMeshers_ImportSource1D.def("RestoreGroups", (void (StdMeshers_ImportSource1D::*)(const std::vector<SMESH_Group *> &)) &StdMeshers_ImportSource1D::RestoreGroups, "None", py::arg("groups"));
	cls_StdMeshers_ImportSource1D.def("StoreResultGroups", (void (StdMeshers_ImportSource1D::*)(const std::vector<SMESH_Group *> &, const SMESHDS_Mesh &, const SMESHDS_Mesh &)) &StdMeshers_ImportSource1D::StoreResultGroups, "None", py::arg("groups"), py::arg("srcMesh"), py::arg("tgtMesh"));
	cls_StdMeshers_ImportSource1D.def("GetResultGroups", (std::vector<SMESH_Group *> * (StdMeshers_ImportSource1D::*)(const SMESHDS_Mesh &, const SMESHDS_Mesh &)) &StdMeshers_ImportSource1D::GetResultGroups, "None", py::arg("srcMesh"), py::arg("tgtMesh"));
	cls_StdMeshers_ImportSource1D.def("GetSourceMeshes", (std::vector<SMESH_Mesh *> (StdMeshers_ImportSource1D::*)() const ) &StdMeshers_ImportSource1D::GetSourceMeshes, "None");
	cls_StdMeshers_ImportSource1D.def("GetSourceSubMeshes", (std::vector<SMESH_subMesh *> (StdMeshers_ImportSource1D::*)(const SMESH_Mesh *) const ) &StdMeshers_ImportSource1D::GetSourceSubMeshes, "None", py::arg("srcMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_ImportSource.hxx
	py::class_<StdMeshers_ImportSource2D, std::unique_ptr<StdMeshers_ImportSource2D, py::nodelete>, StdMeshers_ImportSource1D> cls_StdMeshers_ImportSource2D(mod, "StdMeshers_ImportSource2D", "Redefines name and dimension of inherited StdMeshers_ImportSource1D");
	cls_StdMeshers_ImportSource2D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Import_1D.hxx
	py::class_<StdMeshers_Import_1D, std::unique_ptr<StdMeshers_Import_1D, py::nodelete>, SMESH_1D_Algo> cls_StdMeshers_Import_1D(mod, "StdMeshers_Import_1D", "Copy elements from other the mesh");
	cls_StdMeshers_Import_1D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_Import_1D.def("CheckHypothesis", (bool (StdMeshers_Import_1D::*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &StdMeshers_Import_1D::CheckHypothesis, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));
	cls_StdMeshers_Import_1D.def("Compute", (bool (StdMeshers_Import_1D::*)(SMESH_Mesh &, const TopoDS_Shape &)) &StdMeshers_Import_1D::Compute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_StdMeshers_Import_1D.def("Evaluate", (bool (StdMeshers_Import_1D::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &StdMeshers_Import_1D::Evaluate, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));
	cls_StdMeshers_Import_1D.def("SetEventListener", (void (StdMeshers_Import_1D::*)(SMESH_subMesh *)) &StdMeshers_Import_1D::SetEventListener, "None", py::arg("subMesh"));
	cls_StdMeshers_Import_1D.def("SubmeshRestored", (void (StdMeshers_Import_1D::*)(SMESH_subMesh *)) &StdMeshers_Import_1D::SubmeshRestored, "None", py::arg("subMesh"));
	// FIXME cls_StdMeshers_Import_1D.def_static("getMaps_", (void (*)(const SMESH_Mesh *, SMESH_Mesh *, StdMeshers_Import_1D::TNodeNodeMap *&, StdMeshers_Import_1D::TElemElemMap *&)) &StdMeshers_Import_1D::getMaps, "None", py::arg("srcMesh"), py::arg("tgtMesh"), py::arg("n2n"), py::arg("e2e"));
	cls_StdMeshers_Import_1D.def_static("importMesh_", (void (*)(const SMESH_Mesh *, SMESH_Mesh &, StdMeshers_ImportSource1D *, const TopoDS_Shape &)) &StdMeshers_Import_1D::importMesh, "None", py::arg("srcMesh"), py::arg("tgtMesh"), py::arg("srcHyp"), py::arg("tgtShape"));
	cls_StdMeshers_Import_1D.def_static("setEventListener_", (void (*)(SMESH_subMesh *, StdMeshers_ImportSource1D *)) &StdMeshers_Import_1D::setEventListener, "None", py::arg("subMesh"), py::arg("sourceHyp"));
	cls_StdMeshers_Import_1D.def_static("getSubMeshOfCopiedMesh_", (SMESH_subMesh * (*)(SMESH_Mesh &, SMESH_Mesh &)) &StdMeshers_Import_1D::getSubMeshOfCopiedMesh, "None", py::arg("tgtMesh"), py::arg("srcMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Import_1D2D.hxx
	py::class_<StdMeshers_Import_1D2D, std::unique_ptr<StdMeshers_Import_1D2D, py::nodelete>, SMESH_2D_Algo> cls_StdMeshers_Import_1D2D(mod, "StdMeshers_Import_1D2D", "Copy elements from other the mesh");
	cls_StdMeshers_Import_1D2D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_Import_1D2D.def("CheckHypothesis", (bool (StdMeshers_Import_1D2D::*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &StdMeshers_Import_1D2D::CheckHypothesis, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));
	cls_StdMeshers_Import_1D2D.def("Compute", (bool (StdMeshers_Import_1D2D::*)(SMESH_Mesh &, const TopoDS_Shape &)) &StdMeshers_Import_1D2D::Compute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_StdMeshers_Import_1D2D.def("Evaluate", (bool (StdMeshers_Import_1D2D::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &StdMeshers_Import_1D2D::Evaluate, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));
	cls_StdMeshers_Import_1D2D.def("SetEventListener", (void (StdMeshers_Import_1D2D::*)(SMESH_subMesh *)) &StdMeshers_Import_1D2D::SetEventListener, "None", py::arg("subMesh"));
	cls_StdMeshers_Import_1D2D.def("SubmeshRestored", (void (StdMeshers_Import_1D2D::*)(SMESH_subMesh *)) &StdMeshers_Import_1D2D::SubmeshRestored, "None", py::arg("subMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_LayerDistribution.hxx
	py::class_<StdMeshers_LayerDistribution, std::unique_ptr<StdMeshers_LayerDistribution, py::nodelete>, SMESH_Hypothesis> cls_StdMeshers_LayerDistribution(mod, "StdMeshers_LayerDistribution", "This hypothesis is used by 'Radial prism' algorithm. It specifies 1D hypothesis defining distribution of segments between the internal and the external surfaces.");
	cls_StdMeshers_LayerDistribution.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_LayerDistribution.def("SetLayerDistribution", (void (StdMeshers_LayerDistribution::*)(SMESH_Hypothesis *)) &StdMeshers_LayerDistribution::SetLayerDistribution, "Sets 1D hypothesis specifying distribution of layers", py::arg("hyp1D"));
	cls_StdMeshers_LayerDistribution.def("GetLayerDistribution", (SMESH_Hypothesis * (StdMeshers_LayerDistribution::*)() const ) &StdMeshers_LayerDistribution::GetLayerDistribution, "Returns 1D hypothesis specifying distribution of layers SMESH::SMESH_Hypothesis_ptr - 1D hypothesis");
	cls_StdMeshers_LayerDistribution.def("SaveTo", (std::ostream & (StdMeshers_LayerDistribution::*)(std::ostream &)) &StdMeshers_LayerDistribution::SaveTo, "None", py::arg("save"));
	cls_StdMeshers_LayerDistribution.def("LoadFrom", (std::istream & (StdMeshers_LayerDistribution::*)(std::istream &)) &StdMeshers_LayerDistribution::LoadFrom, "None", py::arg("load"));
	cls_StdMeshers_LayerDistribution.def("SetParametersByMesh", (bool (StdMeshers_LayerDistribution::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_LayerDistribution::SetParametersByMesh, "Initialize parameters by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_LayerDistribution.def("SetParametersByDefaults", [](StdMeshers_LayerDistribution &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_LayerDistribution.def("SetParametersByDefaults", (bool (StdMeshers_LayerDistribution::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_LayerDistribution::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_LayerDistribution2D.hxx
	py::class_<StdMeshers_LayerDistribution2D, std::unique_ptr<StdMeshers_LayerDistribution2D, py::nodelete>, StdMeshers_LayerDistribution> cls_StdMeshers_LayerDistribution2D(mod, "StdMeshers_LayerDistribution2D", "This hypothesis is used by 'Radial quadrangle' algorithm. It specifies 1D hypothesis defining distribution of segments between the internal and the external surfaces.");
	cls_StdMeshers_LayerDistribution2D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_LocalLength.hxx
	py::class_<StdMeshers_LocalLength, std::unique_ptr<StdMeshers_LocalLength, py::nodelete>, SMESH_Hypothesis> cls_StdMeshers_LocalLength(mod, "StdMeshers_LocalLength", "None");
	cls_StdMeshers_LocalLength.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_LocalLength.def("SetLength", (void (StdMeshers_LocalLength::*)(double)) &StdMeshers_LocalLength::SetLength, "None", py::arg("length"));
	cls_StdMeshers_LocalLength.def("SetPrecision", (void (StdMeshers_LocalLength::*)(double)) &StdMeshers_LocalLength::SetPrecision, "None", py::arg("precision"));
	cls_StdMeshers_LocalLength.def("GetLength", (double (StdMeshers_LocalLength::*)() const ) &StdMeshers_LocalLength::GetLength, "None");
	cls_StdMeshers_LocalLength.def("GetPrecision", (double (StdMeshers_LocalLength::*)() const ) &StdMeshers_LocalLength::GetPrecision, "None");
	cls_StdMeshers_LocalLength.def("SaveTo", (std::ostream & (StdMeshers_LocalLength::*)(std::ostream &)) &StdMeshers_LocalLength::SaveTo, "None", py::arg("save"));
	cls_StdMeshers_LocalLength.def("LoadFrom", (std::istream & (StdMeshers_LocalLength::*)(std::istream &)) &StdMeshers_LocalLength::LoadFrom, "None", py::arg("load"));
	cls_StdMeshers_LocalLength.def("SetParametersByMesh", (bool (StdMeshers_LocalLength::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_LocalLength::SetParametersByMesh, "Initialize segment length by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_LocalLength.def("SetParametersByDefaults", [](StdMeshers_LocalLength &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_LocalLength.def("SetParametersByDefaults", (bool (StdMeshers_LocalLength::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_LocalLength::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_MaxLength.hxx
	py::class_<StdMeshers_MaxLength, std::unique_ptr<StdMeshers_MaxLength, py::nodelete>, SMESH_Hypothesis> cls_StdMeshers_MaxLength(mod, "StdMeshers_MaxLength", "None");
	cls_StdMeshers_MaxLength.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_MaxLength.def("SetLength", (void (StdMeshers_MaxLength::*)(double)) &StdMeshers_MaxLength::SetLength, "None", py::arg("length"));
	cls_StdMeshers_MaxLength.def("GetLength", (double (StdMeshers_MaxLength::*)() const ) &StdMeshers_MaxLength::GetLength, "None");
	cls_StdMeshers_MaxLength.def("HavePreestimatedLength", (bool (StdMeshers_MaxLength::*)() const ) &StdMeshers_MaxLength::HavePreestimatedLength, "None");
	cls_StdMeshers_MaxLength.def("GetPreestimatedLength", (double (StdMeshers_MaxLength::*)() const ) &StdMeshers_MaxLength::GetPreestimatedLength, "None");
	cls_StdMeshers_MaxLength.def("SetPreestimatedLength", (void (StdMeshers_MaxLength::*)(double)) &StdMeshers_MaxLength::SetPreestimatedLength, "None", py::arg("length"));
	cls_StdMeshers_MaxLength.def("SetUsePreestimatedLength", (void (StdMeshers_MaxLength::*)(bool)) &StdMeshers_MaxLength::SetUsePreestimatedLength, "None", py::arg("toUse"));
	cls_StdMeshers_MaxLength.def("GetUsePreestimatedLength", (bool (StdMeshers_MaxLength::*)() const ) &StdMeshers_MaxLength::GetUsePreestimatedLength, "None");
	cls_StdMeshers_MaxLength.def("SaveTo", (std::ostream & (StdMeshers_MaxLength::*)(std::ostream &)) &StdMeshers_MaxLength::SaveTo, "None", py::arg("save"));
	cls_StdMeshers_MaxLength.def("LoadFrom", (std::istream & (StdMeshers_MaxLength::*)(std::istream &)) &StdMeshers_MaxLength::LoadFrom, "None", py::arg("load"));
	cls_StdMeshers_MaxLength.def("SetParametersByMesh", (bool (StdMeshers_MaxLength::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_MaxLength::SetParametersByMesh, "Initialize segment length by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_MaxLength.def("SetParametersByDefaults", [](StdMeshers_MaxLength &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_MaxLength.def("SetParametersByDefaults", (bool (StdMeshers_MaxLength::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_MaxLength::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_MEFISTO_2D.hxx
	py::class_<StdMeshers_MEFISTO_2D, std::unique_ptr<StdMeshers_MEFISTO_2D, py::nodelete>, SMESH_2D_Algo> cls_StdMeshers_MEFISTO_2D(mod, "StdMeshers_MEFISTO_2D", "None");
	cls_StdMeshers_MEFISTO_2D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_MEFISTO_2D.def("CheckHypothesis", (bool (StdMeshers_MEFISTO_2D::*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &StdMeshers_MEFISTO_2D::CheckHypothesis, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));
	cls_StdMeshers_MEFISTO_2D.def("Compute", (bool (StdMeshers_MEFISTO_2D::*)(SMESH_Mesh &, const TopoDS_Shape &)) &StdMeshers_MEFISTO_2D::Compute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_StdMeshers_MEFISTO_2D.def("Evaluate", (bool (StdMeshers_MEFISTO_2D::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &StdMeshers_MEFISTO_2D::Evaluate, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));
	cls_StdMeshers_MEFISTO_2D.def("LoadPoints", (bool (StdMeshers_MEFISTO_2D::*)(StdMeshers_MEFISTO_2D::TWireVector &, R2 *, std::vector<const SMDS_MeshNode *> &, double, double)) &StdMeshers_MEFISTO_2D::LoadPoints, "None", py::arg("wires"), py::arg("uvslf"), py::arg("mefistoToDS"), py::arg("scalex"), py::arg("scaley"));
	cls_StdMeshers_MEFISTO_2D.def("ComputeScaleOnFace", (void (StdMeshers_MEFISTO_2D::*)(SMESH_Mesh &, const TopoDS_Face &, double &, double &)) &StdMeshers_MEFISTO_2D::ComputeScaleOnFace, "None", py::arg("aMesh"), py::arg("aFace"), py::arg("scalex"), py::arg("scaley"));
	cls_StdMeshers_MEFISTO_2D.def("StoreResult", (void (StdMeshers_MEFISTO_2D::*)(Z, R2 *, Z, Z *, std::vector<const SMDS_MeshNode *> &, double, double)) &StdMeshers_MEFISTO_2D::StoreResult, "None", py::arg("nbst"), py::arg("uvst"), py::arg("nbt"), py::arg("nust"), py::arg("mefistoToDS"), py::arg("scalex"), py::arg("scaley"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_NotConformAllowed.hxx
	py::class_<StdMeshers_NotConformAllowed, std::unique_ptr<StdMeshers_NotConformAllowed, py::nodelete>, SMESH_Hypothesis> cls_StdMeshers_NotConformAllowed(mod, "StdMeshers_NotConformAllowed", "None");
	cls_StdMeshers_NotConformAllowed.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_NotConformAllowed.def("SaveTo", (std::ostream & (StdMeshers_NotConformAllowed::*)(std::ostream &)) &StdMeshers_NotConformAllowed::SaveTo, "None", py::arg("save"));
	cls_StdMeshers_NotConformAllowed.def("LoadFrom", (std::istream & (StdMeshers_NotConformAllowed::*)(std::istream &)) &StdMeshers_NotConformAllowed::LoadFrom, "None", py::arg("load"));
	cls_StdMeshers_NotConformAllowed.def("SetParametersByMesh", (bool (StdMeshers_NotConformAllowed::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_NotConformAllowed::SetParametersByMesh, "Initialize my parameter values by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_NotConformAllowed.def("SetParametersByDefaults", [](StdMeshers_NotConformAllowed &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_NotConformAllowed.def("SetParametersByDefaults", (bool (StdMeshers_NotConformAllowed::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_NotConformAllowed::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_NumberOfLayers.hxx
	py::class_<StdMeshers_NumberOfLayers, std::unique_ptr<StdMeshers_NumberOfLayers, py::nodelete>, SMESH_Hypothesis> cls_StdMeshers_NumberOfLayers(mod, "StdMeshers_NumberOfLayers", "This hypothesis is used by 'Radial prism' algorithm. It specifies number of segments between the internal and the external surfaces.");
	cls_StdMeshers_NumberOfLayers.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_NumberOfLayers.def("SetNumberOfLayers", (void (StdMeshers_NumberOfLayers::*)(int)) &StdMeshers_NumberOfLayers::SetNumberOfLayers, "None", py::arg("numberOfLayers"));
	cls_StdMeshers_NumberOfLayers.def("GetNumberOfLayers", (int (StdMeshers_NumberOfLayers::*)() const ) &StdMeshers_NumberOfLayers::GetNumberOfLayers, "None");
	cls_StdMeshers_NumberOfLayers.def("SaveTo", (std::ostream & (StdMeshers_NumberOfLayers::*)(std::ostream &)) &StdMeshers_NumberOfLayers::SaveTo, "None", py::arg("save"));
	cls_StdMeshers_NumberOfLayers.def("LoadFrom", (std::istream & (StdMeshers_NumberOfLayers::*)(std::istream &)) &StdMeshers_NumberOfLayers::LoadFrom, "None", py::arg("load"));
	cls_StdMeshers_NumberOfLayers.def("SetParametersByMesh", (bool (StdMeshers_NumberOfLayers::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_NumberOfLayers::SetParametersByMesh, "Initialize parameters by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_NumberOfLayers.def("SetParametersByDefaults", [](StdMeshers_NumberOfLayers &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_NumberOfLayers.def("SetParametersByDefaults", (bool (StdMeshers_NumberOfLayers::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_NumberOfLayers::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_NumberOfLayers2D.hxx
	py::class_<StdMeshers_NumberOfLayers2D, std::unique_ptr<StdMeshers_NumberOfLayers2D, py::nodelete>, StdMeshers_NumberOfLayers> cls_StdMeshers_NumberOfLayers2D(mod, "StdMeshers_NumberOfLayers2D", "This hypothesis is used by 'Radial quadrangle' algorithm. It specifies number of segments between the internal and the external surfaces.");
	cls_StdMeshers_NumberOfLayers2D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_NumberOfSegments.hxx
	py::class_<StdMeshers_NumberOfSegments, std::unique_ptr<StdMeshers_NumberOfSegments, py::nodelete>, SMESH_Hypothesis> cls_StdMeshers_NumberOfSegments(mod, "StdMeshers_NumberOfSegments", "This class represents hypothesis for 1d algorithm");
	cls_StdMeshers_NumberOfSegments.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_NumberOfSegments.def("BuildDistributionExpr", (const std::vector<double> & (StdMeshers_NumberOfSegments::*)(const char *, int, int)) &StdMeshers_NumberOfSegments::BuildDistributionExpr, "None", py::arg(""), py::arg(""), py::arg(""));
	cls_StdMeshers_NumberOfSegments.def("BuildDistributionTab", (const std::vector<double> & (StdMeshers_NumberOfSegments::*)(const std::vector<double> &, int, int)) &StdMeshers_NumberOfSegments::BuildDistributionTab, "None", py::arg(""), py::arg(""), py::arg(""));
	cls_StdMeshers_NumberOfSegments.def("SetNumberOfSegments", (void (StdMeshers_NumberOfSegments::*)(int)) &StdMeshers_NumberOfSegments::SetNumberOfSegments, "Set the number of segments", py::arg("segmentsNumber"));
	cls_StdMeshers_NumberOfSegments.def("GetNumberOfSegments", (int (StdMeshers_NumberOfSegments::*)() const ) &StdMeshers_NumberOfSegments::GetNumberOfSegments, "Get the number of segments");
	cls_StdMeshers_NumberOfSegments.def("SetDistrType", (void (StdMeshers_NumberOfSegments::*)(StdMeshers_NumberOfSegments::DistrType)) &StdMeshers_NumberOfSegments::SetDistrType, "Set distribution type", py::arg("typ"));
	cls_StdMeshers_NumberOfSegments.def("GetDistrType", (StdMeshers_NumberOfSegments::DistrType (StdMeshers_NumberOfSegments::*)() const ) &StdMeshers_NumberOfSegments::GetDistrType, "Get distribution type");
	cls_StdMeshers_NumberOfSegments.def("SetScaleFactor", (void (StdMeshers_NumberOfSegments::*)(double)) &StdMeshers_NumberOfSegments::SetScaleFactor, "Set scale factor for scale distribution", py::arg("scaleFactor"));
	cls_StdMeshers_NumberOfSegments.def("GetScaleFactor", (double (StdMeshers_NumberOfSegments::*)() const ) &StdMeshers_NumberOfSegments::GetScaleFactor, "Get scale factor for scale distribution");
	cls_StdMeshers_NumberOfSegments.def("SetTableFunction", (void (StdMeshers_NumberOfSegments::*)(const std::vector<double> &)) &StdMeshers_NumberOfSegments::SetTableFunction, "Set table function for distribution DT_TabFunc", py::arg("table"));
	cls_StdMeshers_NumberOfSegments.def("GetTableFunction", (const std::vector<double> & (StdMeshers_NumberOfSegments::*)() const ) &StdMeshers_NumberOfSegments::GetTableFunction, "Get table function for distribution DT_TabFunc");
	cls_StdMeshers_NumberOfSegments.def("SetExpressionFunction", (void (StdMeshers_NumberOfSegments::*)(const char *)) &StdMeshers_NumberOfSegments::SetExpressionFunction, "Set expression function for distribution DT_ExprFunc", py::arg("expr"));
	cls_StdMeshers_NumberOfSegments.def("GetExpressionFunction", (const char * (StdMeshers_NumberOfSegments::*)() const ) &StdMeshers_NumberOfSegments::GetExpressionFunction, "Get expression function for distribution DT_ExprFunc");
	cls_StdMeshers_NumberOfSegments.def_static("CheckExpressionFunction_", (std::string (*)(const std::string &, const int)) &StdMeshers_NumberOfSegments::CheckExpressionFunction, "Checks validity of the expression of the function f(t), e.g. 'sin(t)'. In case of validity returns a cleaned expression", py::arg("expr"), py::arg("convMode"));
	cls_StdMeshers_NumberOfSegments.def("SetConversionMode", (void (StdMeshers_NumberOfSegments::*)(int)) &StdMeshers_NumberOfSegments::SetConversionMode, "Set conversion mode. When it is 0, it means 'exponent mode': the function of distribution of density is used as an exponent of 10, i,e, 10^f(t). When it is 1, it means 'cut negative mode'. The function of distribution is used as F(t), where F(t0)=f(t0), if f(t0)>=0, otherwise F(t0) = 0. This mode is sensible only when function distribution is used (DT_TabFunc or DT_ExprFunc)", py::arg("conv"));
	cls_StdMeshers_NumberOfSegments.def("ConversionMode", (int (StdMeshers_NumberOfSegments::*)() const ) &StdMeshers_NumberOfSegments::ConversionMode, "Returns conversion mode");
	cls_StdMeshers_NumberOfSegments.def("SetReversedEdges", (void (StdMeshers_NumberOfSegments::*)(std::vector<int> &)) &StdMeshers_NumberOfSegments::SetReversedEdges, "None", py::arg("ids"));
	cls_StdMeshers_NumberOfSegments.def("SetObjectEntry", (void (StdMeshers_NumberOfSegments::*)(const char *)) &StdMeshers_NumberOfSegments::SetObjectEntry, "None", py::arg("entry"));
	cls_StdMeshers_NumberOfSegments.def("GetObjectEntry", (const char * (StdMeshers_NumberOfSegments::*)()) &StdMeshers_NumberOfSegments::GetObjectEntry, "None");
	cls_StdMeshers_NumberOfSegments.def("GetReversedEdges", (const std::vector<int> & (StdMeshers_NumberOfSegments::*)() const ) &StdMeshers_NumberOfSegments::GetReversedEdges, "None");
	cls_StdMeshers_NumberOfSegments.def("SetParametersByMesh", (bool (StdMeshers_NumberOfSegments::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_NumberOfSegments::SetParametersByMesh, "Initialize number of segments by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_NumberOfSegments.def("SetParametersByDefaults", [](StdMeshers_NumberOfSegments &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_NumberOfSegments.def("SetParametersByDefaults", (bool (StdMeshers_NumberOfSegments::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_NumberOfSegments::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));
	cls_StdMeshers_NumberOfSegments.def("SaveTo", (std::ostream & (StdMeshers_NumberOfSegments::*)(std::ostream &)) &StdMeshers_NumberOfSegments::SaveTo, "None", py::arg("save"));
	cls_StdMeshers_NumberOfSegments.def("LoadFrom", (std::istream & (StdMeshers_NumberOfSegments::*)(std::istream &)) &StdMeshers_NumberOfSegments::LoadFrom, "None", py::arg("load"));
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_NumberOfSegments.hxx
	py::enum_<StdMeshers_NumberOfSegments::DistrType>(cls_StdMeshers_NumberOfSegments, "DistrType", "This enumeration presents available types of distribution")
		.value("DT_Regular", StdMeshers_NumberOfSegments::DistrType::DT_Regular)
		.value("DT_Scale", StdMeshers_NumberOfSegments::DistrType::DT_Scale)
		.value("DT_TabFunc", StdMeshers_NumberOfSegments::DistrType::DT_TabFunc)
		.value("DT_ExprFunc", StdMeshers_NumberOfSegments::DistrType::DT_ExprFunc)
		.export_values();

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Penta_3D.hxx
	py::class_<StdMeshers_SMESHBlock, std::unique_ptr<StdMeshers_SMESHBlock, Deleter<StdMeshers_SMESHBlock>>> cls_StdMeshers_SMESHBlock(mod, "StdMeshers_SMESHBlock", "None");
	cls_StdMeshers_SMESHBlock.def(py::init<>());
	cls_StdMeshers_SMESHBlock.def("Load", (void (StdMeshers_SMESHBlock::*)(const TopoDS_Shell &)) &StdMeshers_SMESHBlock::Load, "None", py::arg("theShell"));
	cls_StdMeshers_SMESHBlock.def("Load", (void (StdMeshers_SMESHBlock::*)(const TopoDS_Shell &, const TopoDS_Vertex &, const TopoDS_Vertex &)) &StdMeshers_SMESHBlock::Load, "None", py::arg("theShell"), py::arg("theV000"), py::arg("theV001"));
	cls_StdMeshers_SMESHBlock.def("ComputeParameters", (void (StdMeshers_SMESHBlock::*)(const gp_Pnt &, gp_XYZ &)) &StdMeshers_SMESHBlock::ComputeParameters, "None", py::arg("thePnt"), py::arg("theXYZ"));
	cls_StdMeshers_SMESHBlock.def("ComputeParameters", (void (StdMeshers_SMESHBlock::*)(const gp_Pnt &, const TopoDS_Shape &, gp_XYZ &)) &StdMeshers_SMESHBlock::ComputeParameters, "None", py::arg("thePnt"), py::arg("theShape"), py::arg("theXYZ"));
	cls_StdMeshers_SMESHBlock.def("ComputeParameters", (void (StdMeshers_SMESHBlock::*)(const double &, const TopoDS_Shape &, gp_XYZ &)) &StdMeshers_SMESHBlock::ComputeParameters, "None", py::arg("theU"), py::arg("theShape"), py::arg("theXYZ"));
	cls_StdMeshers_SMESHBlock.def("Point", (void (StdMeshers_SMESHBlock::*)(const gp_XYZ &, gp_Pnt &)) &StdMeshers_SMESHBlock::Point, "None", py::arg("theParams"), py::arg("thePnt"));
	cls_StdMeshers_SMESHBlock.def("Point", (void (StdMeshers_SMESHBlock::*)(const gp_XYZ &, const TopoDS_Shape &, gp_Pnt &)) &StdMeshers_SMESHBlock::Point, "None", py::arg("theParams"), py::arg("theShape"), py::arg("thePnt"));
	cls_StdMeshers_SMESHBlock.def("ShapeID", (int (StdMeshers_SMESHBlock::*)(const TopoDS_Shape &)) &StdMeshers_SMESHBlock::ShapeID, "None", py::arg("theShape"));
	cls_StdMeshers_SMESHBlock.def("Shape", (const TopoDS_Shape & (StdMeshers_SMESHBlock::*)(const int)) &StdMeshers_SMESHBlock::Shape, "None", py::arg("theID"));
	cls_StdMeshers_SMESHBlock.def("Block", (SMESH_Block & (StdMeshers_SMESHBlock::*)()) &StdMeshers_SMESHBlock::Block, "None");
	cls_StdMeshers_SMESHBlock.def("IsForwadEdge", (bool (StdMeshers_SMESHBlock::*)(const int)) &StdMeshers_SMESHBlock::IsForwadEdge, "None", py::arg("theEdgeID"));
	cls_StdMeshers_SMESHBlock.def("ErrorStatus", (int (StdMeshers_SMESHBlock::*)() const ) &StdMeshers_SMESHBlock::ErrorStatus, "None");
	cls_StdMeshers_SMESHBlock.def("GetError", (SMESH_ComputeErrorPtr (StdMeshers_SMESHBlock::*)() const ) &StdMeshers_SMESHBlock::GetError, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Penta_3D.hxx
	py::class_<StdMeshers_TNode, std::unique_ptr<StdMeshers_TNode, Deleter<StdMeshers_TNode>>> cls_StdMeshers_TNode(mod, "StdMeshers_TNode", "None");
	cls_StdMeshers_TNode.def(py::init<>());
	cls_StdMeshers_TNode.def("SetNode", (void (StdMeshers_TNode::*)(const SMDS_MeshNode *)) &StdMeshers_TNode::SetNode, "None", py::arg("theNode"));
	cls_StdMeshers_TNode.def("Node", (const SMDS_MeshNode * (StdMeshers_TNode::*)() const ) &StdMeshers_TNode::Node, "None");
	cls_StdMeshers_TNode.def("SetShapeSupportID", (void (StdMeshers_TNode::*)(const int)) &StdMeshers_TNode::SetShapeSupportID, "None", py::arg("theID"));
	cls_StdMeshers_TNode.def("ShapeSupportID", (int (StdMeshers_TNode::*)() const ) &StdMeshers_TNode::ShapeSupportID, "None");
	cls_StdMeshers_TNode.def("SetNormCoord", (void (StdMeshers_TNode::*)(const gp_XYZ &)) &StdMeshers_TNode::SetNormCoord, "None", py::arg("theXYZ"));
	cls_StdMeshers_TNode.def("NormCoord", (const gp_XYZ & (StdMeshers_TNode::*)() const ) &StdMeshers_TNode::NormCoord, "None");
	cls_StdMeshers_TNode.def("SetBaseNodeID", (void (StdMeshers_TNode::*)(const int)) &StdMeshers_TNode::SetBaseNodeID, "None", py::arg("theID"));
	cls_StdMeshers_TNode.def("BaseNodeID", (int (StdMeshers_TNode::*)() const ) &StdMeshers_TNode::BaseNodeID, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Penta_3D.hxx
	py::class_<StdMeshers_Penta_3D, std::unique_ptr<StdMeshers_Penta_3D, Deleter<StdMeshers_Penta_3D>>> cls_StdMeshers_Penta_3D(mod, "StdMeshers_Penta_3D", "None");
	cls_StdMeshers_Penta_3D.def(py::init<>());
	cls_StdMeshers_Penta_3D.def("Compute", (bool (StdMeshers_Penta_3D::*)(SMESH_Mesh &, const TopoDS_Shape &)) &StdMeshers_Penta_3D::Compute, "None", py::arg(""), py::arg(""));
	cls_StdMeshers_Penta_3D.def("ErrorStatus", (int (StdMeshers_Penta_3D::*)() const ) &StdMeshers_Penta_3D::ErrorStatus, "None");
	cls_StdMeshers_Penta_3D.def("GetComputeError", (SMESH_ComputeErrorPtr (StdMeshers_Penta_3D::*)() const ) &StdMeshers_Penta_3D::GetComputeError, "None");
	cls_StdMeshers_Penta_3D.def("SetTolerance", (void (StdMeshers_Penta_3D::*)(const double)) &StdMeshers_Penta_3D::SetTolerance, "None", py::arg("theTol3D"));
	cls_StdMeshers_Penta_3D.def("Tolerance", (double (StdMeshers_Penta_3D::*)() const ) &StdMeshers_Penta_3D::Tolerance, "None");
	cls_StdMeshers_Penta_3D.def("LoadIJNodes", (bool (StdMeshers_Penta_3D::*)(StdMeshers_IJNodeMap &, const TopoDS_Face &, const TopoDS_Edge &, SMESHDS_Mesh *)) &StdMeshers_Penta_3D::LoadIJNodes, "None", py::arg("theIJNodes"), py::arg("theFace"), py::arg("theBaseEdge"), py::arg("theMesh"));
	cls_StdMeshers_Penta_3D.def("Evaluate", (bool (StdMeshers_Penta_3D::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &StdMeshers_Penta_3D::Evaluate, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_PolygonPerFace_2D.hxx
	py::class_<StdMeshers_PolygonPerFace_2D, std::unique_ptr<StdMeshers_PolygonPerFace_2D, py::nodelete>, SMESH_2D_Algo> cls_StdMeshers_PolygonPerFace_2D(mod, "StdMeshers_PolygonPerFace_2D", "None");
	cls_StdMeshers_PolygonPerFace_2D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_PolygonPerFace_2D.def("CheckHypothesis", (bool (StdMeshers_PolygonPerFace_2D::*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &StdMeshers_PolygonPerFace_2D::CheckHypothesis, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));
	cls_StdMeshers_PolygonPerFace_2D.def("Compute", (bool (StdMeshers_PolygonPerFace_2D::*)(SMESH_Mesh &, const TopoDS_Shape &)) &StdMeshers_PolygonPerFace_2D::Compute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_StdMeshers_PolygonPerFace_2D.def("Evaluate", (bool (StdMeshers_PolygonPerFace_2D::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &StdMeshers_PolygonPerFace_2D::Evaluate, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Prism_3D.hxx
	py::class_<StdMeshers_PrismAsBlock, std::unique_ptr<StdMeshers_PrismAsBlock, Deleter<StdMeshers_PrismAsBlock>>, SMESH_Block> cls_StdMeshers_PrismAsBlock(mod, "StdMeshers_PrismAsBlock", "Tool analyzing and giving access to a prism geometry treating it like a block, i.e. the four side faces are emulated by division/uniting of missing/excess faces. It also manage associations between block sub-shapes and a mesh.");
	cls_StdMeshers_PrismAsBlock.def(py::init<>());
	cls_StdMeshers_PrismAsBlock.def("Init", (bool (StdMeshers_PrismAsBlock::*)(SMESH_MesherHelper *, const Prism_3D::TPrismTopo &)) &StdMeshers_PrismAsBlock::Init, "Initialization.", py::arg("helper"), py::arg("prism"));
	cls_StdMeshers_PrismAsBlock.def("GetError", (SMESH_ComputeErrorPtr (StdMeshers_PrismAsBlock::*)() const ) &StdMeshers_PrismAsBlock::GetError, "Return problem description");
	cls_StdMeshers_PrismAsBlock.def("Clear", (void (StdMeshers_PrismAsBlock::*)()) &StdMeshers_PrismAsBlock::Clear, "Free allocated memory");
	cls_StdMeshers_PrismAsBlock.def("VerticalSize", (int (StdMeshers_PrismAsBlock::*)() const ) &StdMeshers_PrismAsBlock::VerticalSize, "Return number of nodes on every vertical edge int - number of nodes including end nodes");
	cls_StdMeshers_PrismAsBlock.def("HasNotQuadElemOnTop", (bool (StdMeshers_PrismAsBlock::*)() const ) &StdMeshers_PrismAsBlock::HasNotQuadElemOnTop, "None");
	cls_StdMeshers_PrismAsBlock.def("GetNodeColumn", (const TNodeColumn * (StdMeshers_PrismAsBlock::*)(const SMDS_MeshNode *) const ) &StdMeshers_PrismAsBlock::GetNodeColumn, "Return pointer to column of nodes", py::arg("node"));
	cls_StdMeshers_PrismAsBlock.def("GetParam2ColumnMap", (const TParam2ColumnMap * (StdMeshers_PrismAsBlock::*)(const int, bool &) const ) &StdMeshers_PrismAsBlock::GetParam2ColumnMap, "Return TParam2ColumnMap for a base edge", py::arg("baseEdgeID"), py::arg("isReverse"));
	cls_StdMeshers_PrismAsBlock.def("HasNodeColumn", (bool (StdMeshers_PrismAsBlock::*)(const SMDS_MeshNode *) const ) &StdMeshers_PrismAsBlock::HasNodeColumn, "Return pointer to column of nodes", py::arg("node"));
	cls_StdMeshers_PrismAsBlock.def("GetLayersTransformation", (bool (StdMeshers_PrismAsBlock::*)(std::vector<gp_Trsf> &, const Prism_3D::TPrismTopo &) const ) &StdMeshers_PrismAsBlock::GetLayersTransformation, "Return transformations to get coordinates of nodes of each internal layer by nodes of the bottom. Layer is a set of nodes at a certain step from bottom to top.", py::arg("trsf"), py::arg("prism"));
	cls_StdMeshers_PrismAsBlock.def("Mesh", (SMESH_Mesh * (StdMeshers_PrismAsBlock::*)() const ) &StdMeshers_PrismAsBlock::Mesh, "Return pointer to mesh SMESH_Mesh - mesh");
	cls_StdMeshers_PrismAsBlock.def("MeshDS", (SMESHDS_Mesh * (StdMeshers_PrismAsBlock::*)() const ) &StdMeshers_PrismAsBlock::MeshDS, "Return pointer to mesh DS SMESHDS_Mesh - mesh DS");
	cls_StdMeshers_PrismAsBlock.def("SubMesh", (SMESH_subMesh * (StdMeshers_PrismAsBlock::*)(const int) const ) &StdMeshers_PrismAsBlock::SubMesh, "Return submesh of a shape", py::arg("shapeID"));
	cls_StdMeshers_PrismAsBlock.def("SubMeshDS", (SMESHDS_SubMesh * (StdMeshers_PrismAsBlock::*)(const int) const ) &StdMeshers_PrismAsBlock::SubMeshDS, "Return submesh DS of a shape", py::arg("shapeID"));
	cls_StdMeshers_PrismAsBlock.def("Shape", (const TopoDS_Shape & (StdMeshers_PrismAsBlock::*)(const int) const ) &StdMeshers_PrismAsBlock::Shape, "Return a in-block shape", py::arg("shapeID"));
	cls_StdMeshers_PrismAsBlock.def("ShapeID", (int (StdMeshers_PrismAsBlock::*)(const TopoDS_Shape &) const ) &StdMeshers_PrismAsBlock::ShapeID, "Return in-block ID of a shape", py::arg("shape"));
	cls_StdMeshers_PrismAsBlock.def_static("IsForwardEdge_", (bool (*)(SMESHDS_Mesh *, const TParam2ColumnMap &, const TopoDS_Edge &, const int)) &StdMeshers_PrismAsBlock::IsForwardEdge, "Check curve orientation of a bootom edge", py::arg("meshDS"), py::arg("columnsMap"), py::arg("bottomEdge"), py::arg("sideFaceID"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Prism_3D.hxx
	py::class_<StdMeshers_Sweeper, std::unique_ptr<StdMeshers_Sweeper, Deleter<StdMeshers_Sweeper>>> cls_StdMeshers_Sweeper(mod, "StdMeshers_Sweeper", "Tool building internal nodes in a prism");
	cls_StdMeshers_Sweeper.def(py::init<>());
	// FIXME cls_StdMeshers_Sweeper.def("ComputeNodes", (bool (StdMeshers_Sweeper::*)(SMESH_MesherHelper &, const double, const bool)) &StdMeshers_Sweeper::ComputeNodes, "None", py::arg("helper"), py::arg("tol"), py::arg("allowHighBndError"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Prism_3D.hxx
	py::class_<StdMeshers_Prism_3D, std::unique_ptr<StdMeshers_Prism_3D, py::nodelete>, SMESH_3D_Algo> cls_StdMeshers_Prism_3D(mod, "StdMeshers_Prism_3D", "Algo building prisms on a prism shape");
	cls_StdMeshers_Prism_3D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_Prism_3D.def("CheckHypothesis", (bool (StdMeshers_Prism_3D::*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &StdMeshers_Prism_3D::CheckHypothesis, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));
	cls_StdMeshers_Prism_3D.def("Compute", (bool (StdMeshers_Prism_3D::*)(SMESH_Mesh &, const TopoDS_Shape &)) &StdMeshers_Prism_3D::Compute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_StdMeshers_Prism_3D.def("Evaluate", (bool (StdMeshers_Prism_3D::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &StdMeshers_Prism_3D::Evaluate, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));
	cls_StdMeshers_Prism_3D.def("ProjectTriangles", (void (StdMeshers_Prism_3D::*)()) &StdMeshers_Prism_3D::ProjectTriangles, "Enable removal of quadrangles from the bottom face and triangles creation there by projection from the top (sole face meshed with triangles is considered to be a bottom one). If there are two faces with triangles, triangles must be of the same topology, else the algo fails. The method must be called before Compute()");
	cls_StdMeshers_Prism_3D.def_static("AddPrisms_", (bool (*)(std::vector<const TNodeColumn *> &, SMESH_MesherHelper *)) &StdMeshers_Prism_3D::AddPrisms, "Create prisms", py::arg("nodeColumns"), py::arg("helper"));
	cls_StdMeshers_Prism_3D.def_static("IsApplicable_", (bool (*)(const TopoDS_Shape &, bool)) &StdMeshers_Prism_3D::IsApplicable, "None", py::arg("aShape"), py::arg("toCheckAll"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_ProjectionSource1D.hxx
	py::class_<StdMeshers_ProjectionSource1D, std::unique_ptr<StdMeshers_ProjectionSource1D, py::nodelete>, SMESH_Hypothesis> cls_StdMeshers_ProjectionSource1D(mod, "StdMeshers_ProjectionSource1D", "This hypothesis specifies a meshed edge to take a mesh pattern from and optionally association of vertices between the source edge and a target one (where a hipothesis is assigned to)");
	cls_StdMeshers_ProjectionSource1D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_ProjectionSource1D.def("SetSourceEdge", (void (StdMeshers_ProjectionSource1D::*)(const TopoDS_Shape &)) &StdMeshers_ProjectionSource1D::SetSourceEdge, "Sets source <edge> to take a mesh pattern from", py::arg("edge"));
	cls_StdMeshers_ProjectionSource1D.def("GetSourceEdge", (TopoDS_Shape (StdMeshers_ProjectionSource1D::*)() const ) &StdMeshers_ProjectionSource1D::GetSourceEdge, "Returns the source edge or a group containing edges");
	cls_StdMeshers_ProjectionSource1D.def("IsCompoundSource", (bool (StdMeshers_ProjectionSource1D::*)() const ) &StdMeshers_ProjectionSource1D::IsCompoundSource, "Returns true the source edge is a group of edges");
	cls_StdMeshers_ProjectionSource1D.def("SetSourceMesh", (void (StdMeshers_ProjectionSource1D::*)(SMESH_Mesh *)) &StdMeshers_ProjectionSource1D::SetSourceMesh, "Sets source <mesh> to take a mesh pattern from", py::arg("mesh"));
	cls_StdMeshers_ProjectionSource1D.def("GetSourceMesh", (SMESH_Mesh * (StdMeshers_ProjectionSource1D::*)() const ) &StdMeshers_ProjectionSource1D::GetSourceMesh, "Return source mesh");
	cls_StdMeshers_ProjectionSource1D.def("SetVertexAssociation", (void (StdMeshers_ProjectionSource1D::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &StdMeshers_ProjectionSource1D::SetVertexAssociation, "Sets vertex association between the source edge and the target one. This parameter is optional", py::arg("sourceVertex"), py::arg("targetVertex"));
	cls_StdMeshers_ProjectionSource1D.def("GetSourceVertex", (TopoDS_Vertex (StdMeshers_ProjectionSource1D::*)() const ) &StdMeshers_ProjectionSource1D::GetSourceVertex, "Returns the vertex associated with the target vertex. Result may be nil if association not set");
	cls_StdMeshers_ProjectionSource1D.def("GetTargetVertex", (TopoDS_Vertex (StdMeshers_ProjectionSource1D::*)() const ) &StdMeshers_ProjectionSource1D::GetTargetVertex, "Returns the vertex associated with the source vertex. Result may be nil if association not set");
	cls_StdMeshers_ProjectionSource1D.def("HasVertexAssociation", (bool (StdMeshers_ProjectionSource1D::*)() const ) &StdMeshers_ProjectionSource1D::HasVertexAssociation, "Test if vertex association defined bool - test result");
	cls_StdMeshers_ProjectionSource1D.def("GetStoreParams", (void (StdMeshers_ProjectionSource1D::*)(TopoDS_Shape &, TopoDS_Shape &, TopoDS_Shape &) const ) &StdMeshers_ProjectionSource1D::GetStoreParams, "Return all parameters", py::arg("s1"), py::arg("s2"), py::arg("s3"));
	cls_StdMeshers_ProjectionSource1D.def("RestoreParams", (void (StdMeshers_ProjectionSource1D::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, SMESH_Mesh *)) &StdMeshers_ProjectionSource1D::RestoreParams, "Set all parameters without notifying on modification", py::arg("s1"), py::arg("s2"), py::arg("s3"), py::arg("mesh"));
	cls_StdMeshers_ProjectionSource1D.def("SaveTo", (std::ostream & (StdMeshers_ProjectionSource1D::*)(std::ostream &)) &StdMeshers_ProjectionSource1D::SaveTo, "None", py::arg("save"));
	cls_StdMeshers_ProjectionSource1D.def("LoadFrom", (std::istream & (StdMeshers_ProjectionSource1D::*)(std::istream &)) &StdMeshers_ProjectionSource1D::LoadFrom, "None", py::arg("load"));
	cls_StdMeshers_ProjectionSource1D.def("SetParametersByMesh", (bool (StdMeshers_ProjectionSource1D::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_ProjectionSource1D::SetParametersByMesh, "Initialize parameters by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_ProjectionSource1D.def("SetParametersByDefaults", [](StdMeshers_ProjectionSource1D &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_ProjectionSource1D.def("SetParametersByDefaults", (bool (StdMeshers_ProjectionSource1D::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_ProjectionSource1D::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_ProjectionSource2D.hxx
	py::class_<StdMeshers_ProjectionSource2D, std::unique_ptr<StdMeshers_ProjectionSource2D, py::nodelete>, SMESH_Hypothesis> cls_StdMeshers_ProjectionSource2D(mod, "StdMeshers_ProjectionSource2D", "This hypothesis specifies a meshed face to take a mesh pattern from and optionally association of vertices between the source face and a target one (where a hipothesis is assigned to)");
	cls_StdMeshers_ProjectionSource2D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_ProjectionSource2D.def("SetSourceFace", (void (StdMeshers_ProjectionSource2D::*)(const TopoDS_Shape &)) &StdMeshers_ProjectionSource2D::SetSourceFace, "Sets a source <face> to take a mesh pattern from", py::arg("face"));
	cls_StdMeshers_ProjectionSource2D.def("GetSourceFace", (TopoDS_Shape (StdMeshers_ProjectionSource2D::*)() const ) &StdMeshers_ProjectionSource2D::GetSourceFace, "Returns the source face or a group containing faces");
	cls_StdMeshers_ProjectionSource2D.def("IsCompoundSource", (bool (StdMeshers_ProjectionSource2D::*)() const ) &StdMeshers_ProjectionSource2D::IsCompoundSource, "Returns true the source face is a group of faces");
	cls_StdMeshers_ProjectionSource2D.def("SetSourceMesh", (void (StdMeshers_ProjectionSource2D::*)(SMESH_Mesh *)) &StdMeshers_ProjectionSource2D::SetSourceMesh, "Sets source <mesh> to take a mesh pattern from", py::arg("mesh"));
	cls_StdMeshers_ProjectionSource2D.def("GetSourceMesh", (SMESH_Mesh * (StdMeshers_ProjectionSource2D::*)() const ) &StdMeshers_ProjectionSource2D::GetSourceMesh, "Return source mesh");
	cls_StdMeshers_ProjectionSource2D.def("SetVertexAssociation", (void (StdMeshers_ProjectionSource2D::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &)) &StdMeshers_ProjectionSource2D::SetVertexAssociation, "Sets vertex association between the source face and the target one. This parameter is optional. Two vertices must belong to one edge of a face", py::arg("sourceVertex1"), py::arg("sourceVertex2"), py::arg("targetVertex1"), py::arg("targetVertex2"));
	cls_StdMeshers_ProjectionSource2D.def("GetSourceVertex", (TopoDS_Vertex (StdMeshers_ProjectionSource2D::*)(int) const ) &StdMeshers_ProjectionSource2D::GetSourceVertex, "Returns the -th source vertex associated with the -th target vertex. Result may be nil if association not set. Valid indices are 1 and 2", py::arg("i"));
	cls_StdMeshers_ProjectionSource2D.def("GetTargetVertex", (TopoDS_Vertex (StdMeshers_ProjectionSource2D::*)(int) const ) &StdMeshers_ProjectionSource2D::GetTargetVertex, "Returns the -th target vertex associated with the -th source vertex. Result may be nil if association not set. Valid indices are 1 and 2", py::arg("i"));
	cls_StdMeshers_ProjectionSource2D.def("HasVertexAssociation", (bool (StdMeshers_ProjectionSource2D::*)() const ) &StdMeshers_ProjectionSource2D::HasVertexAssociation, "Test if vertex association defined bool - test result");
	cls_StdMeshers_ProjectionSource2D.def("GetStoreParams", (void (StdMeshers_ProjectionSource2D::*)(TopoDS_Shape &, TopoDS_Shape &, TopoDS_Shape &, TopoDS_Shape &, TopoDS_Shape &) const ) &StdMeshers_ProjectionSource2D::GetStoreParams, "Return all parameters", py::arg("s1"), py::arg("s2"), py::arg("s3"), py::arg("s4"), py::arg("s5"));
	cls_StdMeshers_ProjectionSource2D.def("RestoreParams", (void (StdMeshers_ProjectionSource2D::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, SMESH_Mesh *)) &StdMeshers_ProjectionSource2D::RestoreParams, "Set all parameters without notifying on modification", py::arg("s1"), py::arg("s2"), py::arg("s3"), py::arg("s4"), py::arg("s5"), py::arg("mesh"));
	cls_StdMeshers_ProjectionSource2D.def("SaveTo", (std::ostream & (StdMeshers_ProjectionSource2D::*)(std::ostream &)) &StdMeshers_ProjectionSource2D::SaveTo, "None", py::arg("save"));
	cls_StdMeshers_ProjectionSource2D.def("LoadFrom", (std::istream & (StdMeshers_ProjectionSource2D::*)(std::istream &)) &StdMeshers_ProjectionSource2D::LoadFrom, "None", py::arg("load"));
	cls_StdMeshers_ProjectionSource2D.def("SetParametersByMesh", (bool (StdMeshers_ProjectionSource2D::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_ProjectionSource2D::SetParametersByMesh, "Initialize parameters by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_ProjectionSource2D.def("SetParametersByDefaults", [](StdMeshers_ProjectionSource2D &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_ProjectionSource2D.def("SetParametersByDefaults", (bool (StdMeshers_ProjectionSource2D::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_ProjectionSource2D::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_ProjectionSource3D.hxx
	py::class_<StdMeshers_ProjectionSource3D, std::unique_ptr<StdMeshers_ProjectionSource3D, py::nodelete>, SMESH_Hypothesis> cls_StdMeshers_ProjectionSource3D(mod, "StdMeshers_ProjectionSource3D", "This hypothesis specifies a meshed shell or solid to take a mesh pattern from and optionally association of vertices between the source shape and a target one (where a hipothesis is assigned to)");
	cls_StdMeshers_ProjectionSource3D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_ProjectionSource3D.def("SetSource3DShape", (void (StdMeshers_ProjectionSource3D::*)(const TopoDS_Shape &)) &StdMeshers_ProjectionSource3D::SetSource3DShape, "Sets a source <shape> to take a mesh pattern from", py::arg("shape"));
	cls_StdMeshers_ProjectionSource3D.def("GetSource3DShape", (TopoDS_Shape (StdMeshers_ProjectionSource3D::*)() const ) &StdMeshers_ProjectionSource3D::GetSource3DShape, "Returns the source shape");
	cls_StdMeshers_ProjectionSource3D.def("SetSourceMesh", (void (StdMeshers_ProjectionSource3D::*)(SMESH_Mesh *)) &StdMeshers_ProjectionSource3D::SetSourceMesh, "Sets source <mesh> to take a mesh pattern from", py::arg("mesh"));
	cls_StdMeshers_ProjectionSource3D.def("GetSourceMesh", (SMESH_Mesh * (StdMeshers_ProjectionSource3D::*)() const ) &StdMeshers_ProjectionSource3D::GetSourceMesh, "Return source mesh");
	cls_StdMeshers_ProjectionSource3D.def("SetVertexAssociation", (void (StdMeshers_ProjectionSource3D::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &)) &StdMeshers_ProjectionSource3D::SetVertexAssociation, "Sets vertex association between the source shape and the target one. This parameter is optional. Two vertices must belong to one edge of a shape", py::arg("sourceVertex1"), py::arg("sourceVertex2"), py::arg("targetVertex1"), py::arg("targetVertex2"));
	cls_StdMeshers_ProjectionSource3D.def("GetSourceVertex", (TopoDS_Vertex (StdMeshers_ProjectionSource3D::*)(int) const ) &StdMeshers_ProjectionSource3D::GetSourceVertex, "Returns the -th source vertex associated with the -th target vertex. Result may be nil if association not set.", py::arg("i"));
	cls_StdMeshers_ProjectionSource3D.def("GetTargetVertex", (TopoDS_Vertex (StdMeshers_ProjectionSource3D::*)(int) const ) &StdMeshers_ProjectionSource3D::GetTargetVertex, "Returns the -th target vertex associated with the -th source vertex. Result may be nil if association not set.", py::arg("i"));
	cls_StdMeshers_ProjectionSource3D.def("HasVertexAssociation", (bool (StdMeshers_ProjectionSource3D::*)() const ) &StdMeshers_ProjectionSource3D::HasVertexAssociation, "Test if vertex association defined bool - test result");
	cls_StdMeshers_ProjectionSource3D.def("GetStoreParams", (void (StdMeshers_ProjectionSource3D::*)(TopoDS_Shape &, TopoDS_Shape &, TopoDS_Shape &, TopoDS_Shape &, TopoDS_Shape &) const ) &StdMeshers_ProjectionSource3D::GetStoreParams, "Return all parameters", py::arg("s1"), py::arg("s2"), py::arg("s3"), py::arg("s4"), py::arg("s5"));
	cls_StdMeshers_ProjectionSource3D.def("RestoreParams", (void (StdMeshers_ProjectionSource3D::*)(const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, const TopoDS_Shape &, SMESH_Mesh *)) &StdMeshers_ProjectionSource3D::RestoreParams, "Set all parameters without notifying on modification", py::arg("s1"), py::arg("s2"), py::arg("s3"), py::arg("s4"), py::arg("s5"), py::arg("mesh"));
	cls_StdMeshers_ProjectionSource3D.def("SaveTo", (std::ostream & (StdMeshers_ProjectionSource3D::*)(std::ostream &)) &StdMeshers_ProjectionSource3D::SaveTo, "None", py::arg("save"));
	cls_StdMeshers_ProjectionSource3D.def("LoadFrom", (std::istream & (StdMeshers_ProjectionSource3D::*)(std::istream &)) &StdMeshers_ProjectionSource3D::LoadFrom, "None", py::arg("load"));
	cls_StdMeshers_ProjectionSource3D.def("SetParametersByMesh", (bool (StdMeshers_ProjectionSource3D::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_ProjectionSource3D::SetParametersByMesh, "Initialize parameters by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_ProjectionSource3D.def("SetParametersByDefaults", [](StdMeshers_ProjectionSource3D &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_ProjectionSource3D.def("SetParametersByDefaults", (bool (StdMeshers_ProjectionSource3D::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_ProjectionSource3D::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_ProjectionUtils.hxx
	py::class_<StdMeshers_ShapeShapeBiDirectionMap, std::unique_ptr<StdMeshers_ShapeShapeBiDirectionMap, Deleter<StdMeshers_ShapeShapeBiDirectionMap>>> cls_StdMeshers_ShapeShapeBiDirectionMap(mod, "StdMeshers_ShapeShapeBiDirectionMap", "Struct used instead of a sole TopTools_DataMapOfShapeShape to avoid problems with bidirectional bindings");
	cls_StdMeshers_ShapeShapeBiDirectionMap.def(py::init<>());
	cls_StdMeshers_ShapeShapeBiDirectionMap.def("Bind", (bool (StdMeshers_ShapeShapeBiDirectionMap::*)(const TopoDS_Shape &, const TopoDS_Shape &)) &StdMeshers_ShapeShapeBiDirectionMap::Bind, "None", py::arg("s1"), py::arg("s2"));
	cls_StdMeshers_ShapeShapeBiDirectionMap.def("IsBound", [](StdMeshers_ShapeShapeBiDirectionMap &self, const TopoDS_Shape & a0) -> bool { return self.IsBound(a0); }, py::arg("s"));
	cls_StdMeshers_ShapeShapeBiDirectionMap.def("IsBound", (bool (StdMeshers_ShapeShapeBiDirectionMap::*)(const TopoDS_Shape &, const bool) const ) &StdMeshers_ShapeShapeBiDirectionMap::IsBound, "None", py::arg("s"), py::arg("isShape2"));
	cls_StdMeshers_ShapeShapeBiDirectionMap.def("IsEmpty", (bool (StdMeshers_ShapeShapeBiDirectionMap::*)() const ) &StdMeshers_ShapeShapeBiDirectionMap::IsEmpty, "None");
	cls_StdMeshers_ShapeShapeBiDirectionMap.def("Extent", (int (StdMeshers_ShapeShapeBiDirectionMap::*)() const ) &StdMeshers_ShapeShapeBiDirectionMap::Extent, "None");
	cls_StdMeshers_ShapeShapeBiDirectionMap.def("Clear", (void (StdMeshers_ShapeShapeBiDirectionMap::*)()) &StdMeshers_ShapeShapeBiDirectionMap::Clear, "None");
	cls_StdMeshers_ShapeShapeBiDirectionMap.def("__call__", [](StdMeshers_ShapeShapeBiDirectionMap &self, const TopoDS_Shape & a0) -> const TopoDS_Shape & { return self.operator()(a0); }, py::arg("s"));
	cls_StdMeshers_ShapeShapeBiDirectionMap.def("__call__", (const TopoDS_Shape & (StdMeshers_ShapeShapeBiDirectionMap::*)(const TopoDS_Shape &, const bool) const ) &StdMeshers_ShapeShapeBiDirectionMap::operator(), py::is_operator(), "None", py::arg("s"), py::arg("isShape2"));
	cls_StdMeshers_ShapeShapeBiDirectionMap.def("SetAssocType", (void (StdMeshers_ShapeShapeBiDirectionMap::*)(StdMeshers_ShapeShapeBiDirectionMap::EAssocType)) &StdMeshers_ShapeShapeBiDirectionMap::SetAssocType, "None", py::arg("type"));
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_ProjectionUtils.hxx
	py::enum_<StdMeshers_ShapeShapeBiDirectionMap::EAssocType>(cls_StdMeshers_ShapeShapeBiDirectionMap, "EAssocType", "None")
		.value("UNDEF", StdMeshers_ShapeShapeBiDirectionMap::EAssocType::UNDEF)
		.value("INIT_VERTEX", StdMeshers_ShapeShapeBiDirectionMap::EAssocType::INIT_VERTEX)
		.value("PROPAGATION", StdMeshers_ShapeShapeBiDirectionMap::EAssocType::PROPAGATION)
		.value("PARTNER", StdMeshers_ShapeShapeBiDirectionMap::EAssocType::PARTNER)
		.value("CLOSE_VERTEX", StdMeshers_ShapeShapeBiDirectionMap::EAssocType::CLOSE_VERTEX)
		.value("COMMON_VERTEX", StdMeshers_ShapeShapeBiDirectionMap::EAssocType::COMMON_VERTEX)
		.value("FEW_EF", StdMeshers_ShapeShapeBiDirectionMap::EAssocType::FEW_EF)
		.export_values();

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Projection_1D.hxx
	py::class_<StdMeshers_Projection_1D, std::unique_ptr<StdMeshers_Projection_1D, py::nodelete>, SMESH_1D_Algo> cls_StdMeshers_Projection_1D(mod, "StdMeshers_Projection_1D", "None");
	cls_StdMeshers_Projection_1D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_Projection_1D.def("CheckHypothesis", (bool (StdMeshers_Projection_1D::*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &StdMeshers_Projection_1D::CheckHypothesis, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));
	cls_StdMeshers_Projection_1D.def("Compute", (bool (StdMeshers_Projection_1D::*)(SMESH_Mesh &, const TopoDS_Shape &)) &StdMeshers_Projection_1D::Compute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_StdMeshers_Projection_1D.def("Evaluate", (bool (StdMeshers_Projection_1D::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &StdMeshers_Projection_1D::Evaluate, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));
	cls_StdMeshers_Projection_1D.def("SetEventListener", (void (StdMeshers_Projection_1D::*)(SMESH_subMesh *)) &StdMeshers_Projection_1D::SetEventListener, "Sets a default event listener to submesh of the source edge", py::arg("whenSetToSubMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Projection_2D.hxx
	py::class_<StdMeshers_Projection_2D, std::unique_ptr<StdMeshers_Projection_2D, py::nodelete>, SMESH_2D_Algo> cls_StdMeshers_Projection_2D(mod, "StdMeshers_Projection_2D", "None");
	cls_StdMeshers_Projection_2D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_Projection_2D.def("CheckHypothesis", (bool (StdMeshers_Projection_2D::*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &StdMeshers_Projection_2D::CheckHypothesis, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));
	cls_StdMeshers_Projection_2D.def("Compute", (bool (StdMeshers_Projection_2D::*)(SMESH_Mesh &, const TopoDS_Shape &)) &StdMeshers_Projection_2D::Compute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_StdMeshers_Projection_2D.def("Evaluate", (bool (StdMeshers_Projection_2D::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &StdMeshers_Projection_2D::Evaluate, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));
	cls_StdMeshers_Projection_2D.def("SetEventListener", (void (StdMeshers_Projection_2D::*)(SMESH_subMesh *)) &StdMeshers_Projection_2D::SetEventListener, "Sets a default event listener to submesh of the source face", py::arg("whenSetToSubMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Projection_1D2D.hxx
	py::class_<StdMeshers_Projection_1D2D, std::unique_ptr<StdMeshers_Projection_1D2D, py::nodelete>, StdMeshers_Projection_2D> cls_StdMeshers_Projection_1D2D(mod, "StdMeshers_Projection_1D2D", "None");
	cls_StdMeshers_Projection_1D2D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_Projection_1D2D.def("Compute", (bool (StdMeshers_Projection_1D2D::*)(SMESH_Mesh &, const TopoDS_Shape &)) &StdMeshers_Projection_1D2D::Compute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_StdMeshers_Projection_1D2D.def("Evaluate", (bool (StdMeshers_Projection_1D2D::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &StdMeshers_Projection_1D2D::Evaluate, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));
	cls_StdMeshers_Projection_1D2D.def("SetEventListener", (void (StdMeshers_Projection_1D2D::*)(SMESH_subMesh *)) &StdMeshers_Projection_1D2D::SetEventListener, "Sets a default event listener to submesh of the source face", py::arg("whenSetToSubMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Projection_3D.hxx
	py::class_<StdMeshers_Projection_3D, std::unique_ptr<StdMeshers_Projection_3D, py::nodelete>, SMESH_3D_Algo> cls_StdMeshers_Projection_3D(mod, "StdMeshers_Projection_3D", "None");
	cls_StdMeshers_Projection_3D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_Projection_3D.def("CheckHypothesis", (bool (StdMeshers_Projection_3D::*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &StdMeshers_Projection_3D::CheckHypothesis, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));
	cls_StdMeshers_Projection_3D.def("Compute", (bool (StdMeshers_Projection_3D::*)(SMESH_Mesh &, const TopoDS_Shape &)) &StdMeshers_Projection_3D::Compute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_StdMeshers_Projection_3D.def("Evaluate", (bool (StdMeshers_Projection_3D::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &StdMeshers_Projection_3D::Evaluate, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));
	cls_StdMeshers_Projection_3D.def("SetEventListener", (void (StdMeshers_Projection_3D::*)(SMESH_subMesh *)) &StdMeshers_Projection_3D::SetEventListener, "Sets a default event listener to submesh of the source shape", py::arg("whenSetToSubMesh"));
	cls_StdMeshers_Projection_3D.def_static("IsApplicable_", (bool (*)(const TopoDS_Shape &, bool)) &StdMeshers_Projection_3D::IsApplicable, "None", py::arg("aShape"), py::arg("toCheckAll"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Propagation.hxx
	py::class_<StdMeshers_Propagation, std::unique_ptr<StdMeshers_Propagation, py::nodelete>, SMESH_Hypothesis> cls_StdMeshers_Propagation(mod, "StdMeshers_Propagation", "Propagation hypothesis");
	cls_StdMeshers_Propagation.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_Propagation.def("SaveTo", (std::ostream & (StdMeshers_Propagation::*)(std::ostream &)) &StdMeshers_Propagation::SaveTo, "None", py::arg("save"));
	cls_StdMeshers_Propagation.def("LoadFrom", (std::istream & (StdMeshers_Propagation::*)(std::istream &)) &StdMeshers_Propagation::LoadFrom, "None", py::arg("load"));
	cls_StdMeshers_Propagation.def_static("GetName_", (std::string (*)()) &StdMeshers_Propagation::GetName, "None");
	cls_StdMeshers_Propagation.def_static("GetFilter_", (const SMESH_HypoFilter & (*)()) &StdMeshers_Propagation::GetFilter, "Returns a filter selecting both StdMeshers_Propagation and StdMeshers_PropagOfDistribution hypotheses");
	cls_StdMeshers_Propagation.def_static("SetPropagationMgr_", (void (*)(SMESH_subMesh *)) &StdMeshers_Propagation::SetPropagationMgr, "Set EventListener managing propagation of hypotheses", py::arg("subMesh"));
	cls_StdMeshers_Propagation.def_static("GetPropagationSource_", (TopoDS_Edge (*)(SMESH_Mesh &, const TopoDS_Shape &, bool &)) &StdMeshers_Propagation::GetPropagationSource, "Return an edge from which hypotheses are propagated", py::arg("theMesh"), py::arg("theEdge"), py::arg("isPropagOfDistribution"));
	cls_StdMeshers_Propagation.def("SetParametersByMesh", (bool (StdMeshers_Propagation::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_Propagation::SetParametersByMesh, "Initialize my parameter values by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_Propagation.def("SetParametersByDefaults", [](StdMeshers_Propagation &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_Propagation.def("SetParametersByDefaults", (bool (StdMeshers_Propagation::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_Propagation::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Propagation.hxx
	py::class_<StdMeshers_PropagOfDistribution, std::unique_ptr<StdMeshers_PropagOfDistribution, py::nodelete>, StdMeshers_Propagation> cls_StdMeshers_PropagOfDistribution(mod, "StdMeshers_PropagOfDistribution", "Propagation Of Distribution hypothesis");
	cls_StdMeshers_PropagOfDistribution.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_PropagOfDistribution.def_static("GetName_", (std::string (*)()) &StdMeshers_PropagOfDistribution::GetName, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_QuadrangleParams.hxx
	py::class_<StdMeshers_QuadrangleParams, std::unique_ptr<StdMeshers_QuadrangleParams, py::nodelete>, SMESH_Hypothesis> cls_StdMeshers_QuadrangleParams(mod, "StdMeshers_QuadrangleParams", "None");
	cls_StdMeshers_QuadrangleParams.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_QuadrangleParams.def("SetTriaVertex", (void (StdMeshers_QuadrangleParams::*)(int)) &StdMeshers_QuadrangleParams::SetTriaVertex, "None", py::arg("id"));
	cls_StdMeshers_QuadrangleParams.def("GetTriaVertex", (int (StdMeshers_QuadrangleParams::*)() const ) &StdMeshers_QuadrangleParams::GetTriaVertex, "None");
	cls_StdMeshers_QuadrangleParams.def("SetObjectEntry", (void (StdMeshers_QuadrangleParams::*)(const char *)) &StdMeshers_QuadrangleParams::SetObjectEntry, "None", py::arg("entry"));
	cls_StdMeshers_QuadrangleParams.def("GetObjectEntry", (const char * (StdMeshers_QuadrangleParams::*)()) &StdMeshers_QuadrangleParams::GetObjectEntry, "None");
	cls_StdMeshers_QuadrangleParams.def("SetQuadType", (void (StdMeshers_QuadrangleParams::*)(StdMeshers_QuadType)) &StdMeshers_QuadrangleParams::SetQuadType, "None", py::arg("type"));
	cls_StdMeshers_QuadrangleParams.def("GetQuadType", (StdMeshers_QuadType (StdMeshers_QuadrangleParams::*)() const ) &StdMeshers_QuadrangleParams::GetQuadType, "None");
	cls_StdMeshers_QuadrangleParams.def("SetEnforcedNodes", (void (StdMeshers_QuadrangleParams::*)(const std::vector<TopoDS_Shape> &, const std::vector<gp_Pnt> &)) &StdMeshers_QuadrangleParams::SetEnforcedNodes, "None", py::arg("shapes"), py::arg("points"));
	cls_StdMeshers_QuadrangleParams.def("GetEnforcedNodes", (void (StdMeshers_QuadrangleParams::*)(std::vector<TopoDS_Shape> &, std::vector<gp_Pnt> &) const ) &StdMeshers_QuadrangleParams::GetEnforcedNodes, "None", py::arg("shapes"), py::arg("points"));
	cls_StdMeshers_QuadrangleParams.def("SaveTo", (std::ostream & (StdMeshers_QuadrangleParams::*)(std::ostream &)) &StdMeshers_QuadrangleParams::SaveTo, "None", py::arg("save"));
	cls_StdMeshers_QuadrangleParams.def("LoadFrom", (std::istream & (StdMeshers_QuadrangleParams::*)(std::istream &)) &StdMeshers_QuadrangleParams::LoadFrom, "None", py::arg("load"));
	cls_StdMeshers_QuadrangleParams.def("SetParametersByMesh", (bool (StdMeshers_QuadrangleParams::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_QuadrangleParams::SetParametersByMesh, "Initialize start and end length by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_QuadrangleParams.def("SetParametersByDefaults", [](StdMeshers_QuadrangleParams &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_QuadrangleParams.def("SetParametersByDefaults", (bool (StdMeshers_QuadrangleParams::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_QuadrangleParams::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Quadrangle_2D.hxx
	py::class_<StdMeshers_Quadrangle_2D, std::unique_ptr<StdMeshers_Quadrangle_2D, py::nodelete>, SMESH_2D_Algo> cls_StdMeshers_Quadrangle_2D(mod, "StdMeshers_Quadrangle_2D", "None");
	cls_StdMeshers_Quadrangle_2D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_Quadrangle_2D.def("CheckHypothesis", (bool (StdMeshers_Quadrangle_2D::*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &StdMeshers_Quadrangle_2D::CheckHypothesis, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));
	cls_StdMeshers_Quadrangle_2D.def("Compute", (bool (StdMeshers_Quadrangle_2D::*)(SMESH_Mesh &, const TopoDS_Shape &)) &StdMeshers_Quadrangle_2D::Compute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_StdMeshers_Quadrangle_2D.def("Evaluate", (bool (StdMeshers_Quadrangle_2D::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &StdMeshers_Quadrangle_2D::Evaluate, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));
	cls_StdMeshers_Quadrangle_2D.def("CheckAnd2Dcompute", (FaceQuadStruct::Ptr (StdMeshers_Quadrangle_2D::*)(SMESH_Mesh &, const TopoDS_Shape &, const bool)) &StdMeshers_Quadrangle_2D::CheckAnd2Dcompute, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("CreateQuadratic"));
	cls_StdMeshers_Quadrangle_2D.def("CheckNbEdges", [](StdMeshers_Quadrangle_2D &self, SMESH_Mesh & a0, const TopoDS_Shape & a1) -> FaceQuadStruct::Ptr { return self.CheckNbEdges(a0, a1); }, py::arg("aMesh"), py::arg("aShape"));
	cls_StdMeshers_Quadrangle_2D.def("CheckNbEdges", [](StdMeshers_Quadrangle_2D &self, SMESH_Mesh & a0, const TopoDS_Shape & a1, const bool a2) -> FaceQuadStruct::Ptr { return self.CheckNbEdges(a0, a1, a2); }, py::arg("aMesh"), py::arg("aShape"), py::arg("considerMesh"));
	cls_StdMeshers_Quadrangle_2D.def("CheckNbEdges", (FaceQuadStruct::Ptr (StdMeshers_Quadrangle_2D::*)(SMESH_Mesh &, const TopoDS_Shape &, const bool, SMESH_MesherHelper *)) &StdMeshers_Quadrangle_2D::CheckNbEdges, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("considerMesh"), py::arg("aFaceHelper"));
	cls_StdMeshers_Quadrangle_2D.def_static("IsApplicable_", (bool (*)(const TopoDS_Shape &, bool)) &StdMeshers_Quadrangle_2D::IsApplicable, "None", py::arg("aShape"), py::arg("toCheckAll"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_QuadFromMedialAxis_1D2D.hxx
	py::class_<StdMeshers_QuadFromMedialAxis_1D2D, std::unique_ptr<StdMeshers_QuadFromMedialAxis_1D2D, py::nodelete>, StdMeshers_Quadrangle_2D> cls_StdMeshers_QuadFromMedialAxis_1D2D(mod, "StdMeshers_QuadFromMedialAxis_1D2D", "Quadrangle mesher using Medial Axis");
	cls_StdMeshers_QuadFromMedialAxis_1D2D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_QuadFromMedialAxis_1D2D.def("CheckHypothesis", (bool (StdMeshers_QuadFromMedialAxis_1D2D::*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &StdMeshers_QuadFromMedialAxis_1D2D::CheckHypothesis, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));
	cls_StdMeshers_QuadFromMedialAxis_1D2D.def("Compute", (bool (StdMeshers_QuadFromMedialAxis_1D2D::*)(SMESH_Mesh &, const TopoDS_Shape &)) &StdMeshers_QuadFromMedialAxis_1D2D::Compute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_StdMeshers_QuadFromMedialAxis_1D2D.def("Evaluate", (bool (StdMeshers_QuadFromMedialAxis_1D2D::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &StdMeshers_QuadFromMedialAxis_1D2D::Evaluate, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));
	cls_StdMeshers_QuadFromMedialAxis_1D2D.def("SetEventListener", (void (StdMeshers_QuadFromMedialAxis_1D2D::*)(SMESH_subMesh *)) &StdMeshers_QuadFromMedialAxis_1D2D::SetEventListener, "None", py::arg("subMesh"));
	cls_StdMeshers_QuadFromMedialAxis_1D2D.def_static("IsApplicable_", (bool (*)(const TopoDS_Shape &, bool)) &StdMeshers_QuadFromMedialAxis_1D2D::IsApplicable, "None", py::arg("aShape"), py::arg("toCheckAll"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_QuadranglePreference.hxx
	py::class_<StdMeshers_QuadranglePreference, std::unique_ptr<StdMeshers_QuadranglePreference, py::nodelete>, SMESH_Hypothesis> cls_StdMeshers_QuadranglePreference(mod, "StdMeshers_QuadranglePreference", "Hypothesis for StdMeshers_Quadrangle_2D, forcing construction of quadrangles if the number of nodes on opposite edges is not the same. GIBI can do it if the global number of nodes is even (DALL operator). See PAL10467");
	cls_StdMeshers_QuadranglePreference.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_QuadranglePreference.def("SaveTo", (std::ostream & (StdMeshers_QuadranglePreference::*)(std::ostream &)) &StdMeshers_QuadranglePreference::SaveTo, "None", py::arg("save"));
	cls_StdMeshers_QuadranglePreference.def("LoadFrom", (std::istream & (StdMeshers_QuadranglePreference::*)(std::istream &)) &StdMeshers_QuadranglePreference::LoadFrom, "None", py::arg("load"));
	cls_StdMeshers_QuadranglePreference.def("SetParametersByMesh", (bool (StdMeshers_QuadranglePreference::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_QuadranglePreference::SetParametersByMesh, "Initialize my parameter values by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_QuadranglePreference.def("SetParametersByDefaults", [](StdMeshers_QuadranglePreference &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_QuadranglePreference.def("SetParametersByDefaults", (bool (StdMeshers_QuadranglePreference::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_QuadranglePreference::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_QuadraticMesh.hxx
	py::class_<StdMeshers_QuadraticMesh, std::unique_ptr<StdMeshers_QuadraticMesh, py::nodelete>, SMESH_Hypothesis> cls_StdMeshers_QuadraticMesh(mod, "StdMeshers_QuadraticMesh", "Hypothesis for StdMeshers_Regular_1D, forcing construction of quadratic edges. If the 2D mesher sees that all boundary edges are quadratic ones, it generates quadratic faces, else it generates linear faces using medium nodes as if they were vertex ones. The 3D mesher generates quadratic volumes only if all boundary faces are quadratic ones, else it fails.");
	cls_StdMeshers_QuadraticMesh.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_QuadraticMesh.def("SaveTo", (std::ostream & (StdMeshers_QuadraticMesh::*)(std::ostream &)) &StdMeshers_QuadraticMesh::SaveTo, "None", py::arg("save"));
	cls_StdMeshers_QuadraticMesh.def("LoadFrom", (std::istream & (StdMeshers_QuadraticMesh::*)(std::istream &)) &StdMeshers_QuadraticMesh::LoadFrom, "None", py::arg("load"));
	cls_StdMeshers_QuadraticMesh.def("SetParametersByMesh", (bool (StdMeshers_QuadraticMesh::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_QuadraticMesh::SetParametersByMesh, "Initialize my parameter values by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_QuadraticMesh.def("SetParametersByDefaults", [](StdMeshers_QuadraticMesh &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_QuadraticMesh.def("SetParametersByDefaults", (bool (StdMeshers_QuadraticMesh::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_QuadraticMesh::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_QuadToTriaAdaptor.hxx
	py::class_<StdMeshers_QuadToTriaAdaptor, std::unique_ptr<StdMeshers_QuadToTriaAdaptor, Deleter<StdMeshers_QuadToTriaAdaptor>>, SMESH_ProxyMesh> cls_StdMeshers_QuadToTriaAdaptor(mod, "StdMeshers_QuadToTriaAdaptor", "'Transforms' quadrilateral faces into triangular ones by creation of pyramids");
	cls_StdMeshers_QuadToTriaAdaptor.def(py::init<>());
	cls_StdMeshers_QuadToTriaAdaptor.def("Compute", [](StdMeshers_QuadToTriaAdaptor &self, SMESH_Mesh & a0, const TopoDS_Shape & a1) -> bool { return self.Compute(a0, a1); }, py::arg("aMesh"), py::arg("aShape"));
	cls_StdMeshers_QuadToTriaAdaptor.def("Compute", (bool (StdMeshers_QuadToTriaAdaptor::*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_ProxyMesh *)) &StdMeshers_QuadToTriaAdaptor::Compute, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aProxyMesh"));
	cls_StdMeshers_QuadToTriaAdaptor.def("Compute", (bool (StdMeshers_QuadToTriaAdaptor::*)(SMESH_Mesh &)) &StdMeshers_QuadToTriaAdaptor::Compute, "None", py::arg("aMesh"));
	cls_StdMeshers_QuadToTriaAdaptor.def("GetShape", (const TopoDS_Shape & (StdMeshers_QuadToTriaAdaptor::*)() const ) &StdMeshers_QuadToTriaAdaptor::GetShape, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_RadialPrism_3D.hxx
	py::class_<StdMeshers_RadialPrism_3D, std::unique_ptr<StdMeshers_RadialPrism_3D, py::nodelete>, SMESH_3D_Algo> cls_StdMeshers_RadialPrism_3D(mod, "StdMeshers_RadialPrism_3D", "None");
	cls_StdMeshers_RadialPrism_3D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_RadialPrism_3D.def("CheckHypothesis", (bool (StdMeshers_RadialPrism_3D::*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &StdMeshers_RadialPrism_3D::CheckHypothesis, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));
	cls_StdMeshers_RadialPrism_3D.def("Compute", (bool (StdMeshers_RadialPrism_3D::*)(SMESH_Mesh &, const TopoDS_Shape &)) &StdMeshers_RadialPrism_3D::Compute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_StdMeshers_RadialPrism_3D.def("Evaluate", (bool (StdMeshers_RadialPrism_3D::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &StdMeshers_RadialPrism_3D::Evaluate, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));
	cls_StdMeshers_RadialPrism_3D.def_static("IsApplicable_", (bool (*)(const TopoDS_Shape &, bool)) &StdMeshers_RadialPrism_3D::IsApplicable, "None", py::arg("aShape"), py::arg("toCheckAll"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_RadialQuadrangle_1D2D.hxx
	py::class_<StdMeshers_RadialQuadrangle_1D2D, std::unique_ptr<StdMeshers_RadialQuadrangle_1D2D, py::nodelete>, StdMeshers_Quadrangle_2D> cls_StdMeshers_RadialQuadrangle_1D2D(mod, "StdMeshers_RadialQuadrangle_1D2D", "Algorithm generating quadrangles on a full or a part of an elliptic face. Elements around an ellipse center are triangles.");
	cls_StdMeshers_RadialQuadrangle_1D2D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_RadialQuadrangle_1D2D.def("CheckHypothesis", (bool (StdMeshers_RadialQuadrangle_1D2D::*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &StdMeshers_RadialQuadrangle_1D2D::CheckHypothesis, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));
	cls_StdMeshers_RadialQuadrangle_1D2D.def("Compute", (bool (StdMeshers_RadialQuadrangle_1D2D::*)(SMESH_Mesh &, const TopoDS_Shape &)) &StdMeshers_RadialQuadrangle_1D2D::Compute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_StdMeshers_RadialQuadrangle_1D2D.def("Evaluate", (bool (StdMeshers_RadialQuadrangle_1D2D::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &StdMeshers_RadialQuadrangle_1D2D::Evaluate, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));
	cls_StdMeshers_RadialQuadrangle_1D2D.def("SubmeshRestored", (void (StdMeshers_RadialQuadrangle_1D2D::*)(SMESH_subMesh *)) &StdMeshers_RadialQuadrangle_1D2D::SubmeshRestored, "Allow algo to do something after persistent restoration", py::arg("subMesh"));
	cls_StdMeshers_RadialQuadrangle_1D2D.def_static("IsApplicable_", (bool (*)(const TopoDS_Shape &, bool)) &StdMeshers_RadialQuadrangle_1D2D::IsApplicable, "None", py::arg("aShape"), py::arg("toCheckAll"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_SegmentAroundVertex_0D.hxx
	py::class_<StdMeshers_SegmentAroundVertex_0D, std::unique_ptr<StdMeshers_SegmentAroundVertex_0D, py::nodelete>, SMESH_0D_Algo> cls_StdMeshers_SegmentAroundVertex_0D(mod, "StdMeshers_SegmentAroundVertex_0D", "Algorithm existing in order just to enable assignation of StdMeshers_SegmentLengthAroundVertex hypothesis");
	cls_StdMeshers_SegmentAroundVertex_0D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_SegmentAroundVertex_0D.def("CheckHypothesis", (bool (StdMeshers_SegmentAroundVertex_0D::*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &StdMeshers_SegmentAroundVertex_0D::CheckHypothesis, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));
	cls_StdMeshers_SegmentAroundVertex_0D.def("Compute", (bool (StdMeshers_SegmentAroundVertex_0D::*)(SMESH_Mesh &, const TopoDS_Shape &)) &StdMeshers_SegmentAroundVertex_0D::Compute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_StdMeshers_SegmentAroundVertex_0D.def("Evaluate", (bool (StdMeshers_SegmentAroundVertex_0D::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &StdMeshers_SegmentAroundVertex_0D::Evaluate, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_StartEndLength.hxx
	py::class_<StdMeshers_StartEndLength, std::unique_ptr<StdMeshers_StartEndLength, py::nodelete>, SMESH_Hypothesis> cls_StdMeshers_StartEndLength(mod, "StdMeshers_StartEndLength", "None");
	cls_StdMeshers_StartEndLength.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_StartEndLength.def("SetLength", (void (StdMeshers_StartEndLength::*)(double, bool)) &StdMeshers_StartEndLength::SetLength, "None", py::arg("length"), py::arg("isStartLength"));
	cls_StdMeshers_StartEndLength.def("GetLength", (double (StdMeshers_StartEndLength::*)(bool) const ) &StdMeshers_StartEndLength::GetLength, "None", py::arg("isStartLength"));
	cls_StdMeshers_StartEndLength.def("SetReversedEdges", (void (StdMeshers_StartEndLength::*)(std::vector<int> &)) &StdMeshers_StartEndLength::SetReversedEdges, "None", py::arg("ids"));
	cls_StdMeshers_StartEndLength.def("GetReversedEdges", (const std::vector<int> & (StdMeshers_StartEndLength::*)() const ) &StdMeshers_StartEndLength::GetReversedEdges, "None");
	cls_StdMeshers_StartEndLength.def("SetObjectEntry", (void (StdMeshers_StartEndLength::*)(const char *)) &StdMeshers_StartEndLength::SetObjectEntry, "None", py::arg("entry"));
	cls_StdMeshers_StartEndLength.def("GetObjectEntry", (const char * (StdMeshers_StartEndLength::*)()) &StdMeshers_StartEndLength::GetObjectEntry, "None");
	cls_StdMeshers_StartEndLength.def("SaveTo", (std::ostream & (StdMeshers_StartEndLength::*)(std::ostream &)) &StdMeshers_StartEndLength::SaveTo, "None", py::arg("save"));
	cls_StdMeshers_StartEndLength.def("LoadFrom", (std::istream & (StdMeshers_StartEndLength::*)(std::istream &)) &StdMeshers_StartEndLength::LoadFrom, "None", py::arg("load"));
	cls_StdMeshers_StartEndLength.def("SetParametersByMesh", (bool (StdMeshers_StartEndLength::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_StartEndLength::SetParametersByMesh, "Initialize start and end length by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_StartEndLength.def("SetParametersByDefaults", [](StdMeshers_StartEndLength &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_StartEndLength.def("SetParametersByDefaults", (bool (StdMeshers_StartEndLength::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_StartEndLength::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_UseExisting_1D2D.hxx
	py::class_<StdMeshers_UseExisting_2D, std::unique_ptr<StdMeshers_UseExisting_2D, py::nodelete>, SMESH_2D_Algo> cls_StdMeshers_UseExisting_2D(mod, "StdMeshers_UseExisting_2D", "1D and 2D algorithms doing nothing to allow mesh generation by mesh edition functions in TUI mode");
	cls_StdMeshers_UseExisting_2D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_UseExisting_2D.def("CheckHypothesis", (bool (StdMeshers_UseExisting_2D::*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &StdMeshers_UseExisting_2D::CheckHypothesis, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));
	cls_StdMeshers_UseExisting_2D.def("Compute", (bool (StdMeshers_UseExisting_2D::*)(SMESH_Mesh &, const TopoDS_Shape &)) &StdMeshers_UseExisting_2D::Compute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_StdMeshers_UseExisting_2D.def("Evaluate", (bool (StdMeshers_UseExisting_2D::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &StdMeshers_UseExisting_2D::Evaluate, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_UseExisting_1D2D.hxx
	py::class_<StdMeshers_UseExisting_1D, std::unique_ptr<StdMeshers_UseExisting_1D, py::nodelete>, SMESH_1D_Algo> cls_StdMeshers_UseExisting_1D(mod, "StdMeshers_UseExisting_1D", "None");
	cls_StdMeshers_UseExisting_1D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_UseExisting_1D.def("CheckHypothesis", (bool (StdMeshers_UseExisting_1D::*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &StdMeshers_UseExisting_1D::CheckHypothesis, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));
	cls_StdMeshers_UseExisting_1D.def("Compute", (bool (StdMeshers_UseExisting_1D::*)(SMESH_Mesh &, const TopoDS_Shape &)) &StdMeshers_UseExisting_1D::Compute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_StdMeshers_UseExisting_1D.def("Evaluate", (bool (StdMeshers_UseExisting_1D::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &StdMeshers_UseExisting_1D::Evaluate, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_ViscousLayers2D.hxx
	py::class_<StdMeshers_ViscousLayers2D, std::unique_ptr<StdMeshers_ViscousLayers2D, py::nodelete>, StdMeshers_ViscousLayers> cls_StdMeshers_ViscousLayers2D(mod, "StdMeshers_ViscousLayers2D", "Hypothesis defining parameters of viscous layers");
	cls_StdMeshers_ViscousLayers2D.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_StdMeshers_ViscousLayers2D.def_static("Compute_", (SMESH_ProxyMesh::Ptr (*)(SMESH_Mesh &, const TopoDS_Face &)) &StdMeshers_ViscousLayers2D::Compute, "Computes temporary 2D mesh to be used by 2D algorithm. Return SMESH_ProxyMesh for the given FACE, or NULL in case of error", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_ViscousLayers2D.def("RestoreListeners", (void (StdMeshers_ViscousLayers2D::*)() const ) &StdMeshers_ViscousLayers2D::RestoreListeners, "At study restoration, restore event listeners used to clear an inferior dim sub-mesh modified by viscous layers");
	cls_StdMeshers_ViscousLayers2D.def_static("CheckHypothesis_", (SMESH_ComputeErrorPtr (*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &StdMeshers_ViscousLayers2D::CheckHypothesis, "Checks compatibility of assigned StdMeshers_ViscousLayers2D hypotheses", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));
	cls_StdMeshers_ViscousLayers2D.def("SetParametersByMesh", (bool (StdMeshers_ViscousLayers2D::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &StdMeshers_ViscousLayers2D::SetParametersByMesh, "Initialize my parameter values by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_StdMeshers_ViscousLayers2D.def("SetParametersByDefaults", [](StdMeshers_ViscousLayers2D &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_StdMeshers_ViscousLayers2D.def("SetParametersByDefaults", (bool (StdMeshers_ViscousLayers2D::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &StdMeshers_ViscousLayers2D::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));
	cls_StdMeshers_ViscousLayers2D.def_static("GetHypType_", (const char * (*)()) &StdMeshers_ViscousLayers2D::GetHypType, "None");
	cls_StdMeshers_ViscousLayers2D.def_static("SetProxyMeshOfEdge_", (void (*)(const StdMeshers_FaceSide &)) &StdMeshers_ViscousLayers2D::SetProxyMeshOfEdge, "None", py::arg("edgeNodes"));
	cls_StdMeshers_ViscousLayers2D.def_static("HasProxyMesh_", (bool (*)(const TopoDS_Face &, SMESH_Mesh &)) &StdMeshers_ViscousLayers2D::HasProxyMesh, "None", py::arg("face"), py::arg("theMesh"));

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_FaceSide.hxx
	other_mod = py::module::import("OCCT.SMESH");
	if (py::hasattr(other_mod, "SMESH_ComputeErrorPtr")) {
		mod.attr("TError") = other_mod.attr("SMESH_ComputeErrorPtr");
	}

	*/

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_FaceSide.hxx
	// FIXME bind_boost::shared_ptr<StdMeshers_FaceSide>(mod, "StdMeshers_FaceSidePtr");

	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_FaceSide.hxx
	// FIXME bind_std::vector<boost::shared_ptr<StdMeshers_FaceSide>, std::allocator<boost::shared_ptr<StdMeshers_FaceSide> > >(mod, "TSideVector");

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Penta_3D.hxx
	other_mod = py::module::import("OCCT.SMESH");
	if (py::hasattr(other_mod, "TParam2ColumnMap")) {
		mod.attr("StdMeshers_IJNodeMap") = other_mod.attr("TParam2ColumnMap");
	}

	*/

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Prism_3D.hxx
	other_mod = py::module::import("OCCT.TopTools");
	if (py::hasattr(other_mod, "TopTools_IndexedMapOfOrientedShape")) {
		mod.attr("TBlockShapes") = other_mod.attr("TopTools_IndexedMapOfOrientedShape");
	}

	*/

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Prism_3D.hxx
	other_mod = py::module::import("OCCT.SMESH");
	if (py::hasattr(other_mod, "TNodeColumn")) {
		mod.attr("TNodeColumn") = other_mod.attr("TNodeColumn");
	}

	*/

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Prism_3D.hxx
	other_mod = py::module::import("OCCT.SMESH");
	if (py::hasattr(other_mod, "TParam2ColumnMap")) {
		mod.attr("TParam2ColumnMap") = other_mod.attr("TParam2ColumnMap");
	}

	*/

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Prism_3D.hxx
	// FIXME bind_std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const double, std::vector<const SMDS_MeshNode *, std::allocator<const SMDS_MeshNode *> > > > > >(mod, "TParam2ColumnIt");

	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Prism_3D.hxx
	// FIXME bind_std::map<Prism_3D::TNode, std::vector<const SMDS_MeshNode *, std::allocator<const SMDS_MeshNode *> >, std::less<Prism_3D::TNode>, std::allocator<std::pair<const Prism_3D::TNode, std::vector<const SMDS_MeshNode *, std::allocator<const SMDS_MeshNode *> > > > >(mod, "TNode2ColumnMap");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\StdMeshers_Quadrangle_2D.hxx
	other_mod = py::module::import("OCCT.SMESH");
	if (py::hasattr(other_mod, "UVPtStruct")) {
		mod.attr("UVPtStruct") = other_mod.attr("UVPtStruct");
	}


}
