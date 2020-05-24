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

#include <SMESH_ControlsDef.hxx>

#include <SMESH_Hypothesis.hxx>
#include <SMESH_Gen.hxx>
#include <SMESH_Algo.hxx>
#include <SMESH_Mesh.hxx>
#include <TopoDS_Shape.hxx>
#include <SMESH_MesherHelper.hxx>
#include <SMESHDS_Hypothesis.hxx>
#include <SMESH_HypoFilter.hxx>
#include <SMESH_ComputeError.hxx>
#include <SMESH_subMesh.hxx>
#include <SMESHDS_Mesh.hxx>
#include <TopoDS_Edge.hxx>
#include <SMDS_MeshNode.hxx>
#include <SMDSAbs_ElementType.hxx>
#include <TopoDS_Wire.hxx>
#include <GeomAbs_Shape.hxx>
#include <TopoDS_Vertex.hxx>
#include <SMESHDS_SubMesh.hxx>
#include <SMESH_File.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <SMESHDS_Document.hxx>
#include <TopoDS_Solid.hxx>
#include <SMESHDS_Command.hxx>
#include <TopTools_ListOfShape.hxx>
#include <SMESH_Group.hxx>
#include <SMESH_Controls.hxx>
#include <SMESHDS_GroupBase.hxx>
#include <SMESH_TypeDefs.hxx>
#include <SMESH_OctreeNode.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_XYZ.hxx>
#include <SMDS_MeshElement.hxx>
#include <gp_XY.hxx>
#include <NCollection_BaseSequence.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <SMESH_ProxyMesh.hxx>
#include <SMDS_ElemIterator.hxx>
#include <TopoDS_Face.hxx>
#include <TopAbs_Orientation.hxx>
#include <gp_Vec.hxx>
#include <SMDS_MeshEdge.hxx>
#include <SMDS_MeshFace.hxx>
#include <SMDS_MeshVolume.hxx>
#include <Geom_Surface.hxx>
#include <GeomAPI_ProjectPointOnSurf.hxx>
#include <TopLoc_Location.hxx>
#include <ShapeAnalysis_Surface.hxx>
#include <SMESH_Comment.hxx>
#include <math_FunctionSetWithDerivatives.hxx>
#include <TopoDS_Shell.hxx>
#include <TopTools_IndexedMapOfOrientedShape.hxx>
#include <gp_Pnt.hxx>
#include <math_Vector.hxx>
#include <math_Matrix.hxx>
#include <SMESH_Block.hxx>
#include <SMESH_MeshAlgos.hxx>
#include <gp_Ax1.hxx>
#include <TopAbs_State.hxx>
#include <SMESH_MeshEditor.hxx>
#include <gp_Dir.hxx>
#include <gp_Trsf.hxx>
#include <MeshVS_DataSource3D.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <MeshVS_EntityType.hxx>
#include <MeshVS_HArray1OfSequenceOfInteger.hxx>
#include <TColStd_Array1OfInteger.hxx>
#include <TColStd_PackedMapOfInteger.hxx>
#include <Standard_Type.hxx>
#include <SMESH_MeshVSLink.hxx>
#include <SMESH_Tree.hxx>
#include <Bnd_B3d.hxx>
#include <SMESH_Octree.hxx>
#include <SMESH_Pattern.hxx>
#include <Bnd_B2d.hxx>
#include <SMESH_Quadtree.hxx>
#include <SMESH_subMeshEventListener.hxx>
#include <NCollection_Templates.hxx>
#include <SMDS_Templates.hxx>
#include <STL_Templates.hxx>

PYBIND11_MAKE_OPAQUE(SMESH_MeshEditor::TListOfListOfNodes);
PYBIND11_MAKE_OPAQUE(SMESH_MeshEditor::TListOfListOfElementsID);
PYBIND11_MAKE_OPAQUE(std::list<int>);
PYBIND11_MAKE_OPAQUE(std::list <const SMDS_MeshNode*>);
PYBIND11_MAKE_OPAQUE(std::list <const SMDS_MeshElement*>);

PYBIND11_MODULE(SMESH, mod) {

	// IMPORT
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.SMESHDS");
	py::module::import("OCCT.SMDS");
	py::module::import("OCCT.SMDSAbs");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.GeomAPI");
	py::module::import("OCCT.TopLoc");
	py::module::import("OCCT.ShapeAnalysis");
	py::module::import("OCCT.math");
	py::module::import("OCCT.MeshVS");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.Bnd");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_ComputeError.hxx
	py::enum_<SMESH_ComputeErrorName>(mod, "SMESH_ComputeErrorName", "None")
		.value("COMPERR_OK", SMESH_ComputeErrorName::COMPERR_OK)
		.value("COMPERR_BAD_INPUT_MESH", SMESH_ComputeErrorName::COMPERR_BAD_INPUT_MESH)
		.value("COMPERR_STD_EXCEPTION", SMESH_ComputeErrorName::COMPERR_STD_EXCEPTION)
		.value("COMPERR_OCC_EXCEPTION", SMESH_ComputeErrorName::COMPERR_OCC_EXCEPTION)
		.value("COMPERR_SLM_EXCEPTION", SMESH_ComputeErrorName::COMPERR_SLM_EXCEPTION)
		.value("COMPERR_EXCEPTION", SMESH_ComputeErrorName::COMPERR_EXCEPTION)
		.value("COMPERR_MEMORY_PB", SMESH_ComputeErrorName::COMPERR_MEMORY_PB)
		.value("COMPERR_ALGO_FAILED", SMESH_ComputeErrorName::COMPERR_ALGO_FAILED)
		.value("COMPERR_BAD_SHAPE", SMESH_ComputeErrorName::COMPERR_BAD_SHAPE)
		.value("COMPERR_WARNING", SMESH_ComputeErrorName::COMPERR_WARNING)
		.value("COMPERR_CANCELED", SMESH_ComputeErrorName::COMPERR_CANCELED)
		.value("COMPERR_NO_MESH_ON_SHAPE", SMESH_ComputeErrorName::COMPERR_NO_MESH_ON_SHAPE)
		.value("COMPERR_BAD_PARMETERS", SMESH_ComputeErrorName::COMPERR_BAD_PARMETERS)
		.value("COMPERR_LAST_ALGO_ERROR", SMESH_ComputeErrorName::COMPERR_LAST_ALGO_ERROR)
		.value("EDITERR_NO_MEDIUM_ON_GEOM", SMESH_ComputeErrorName::EDITERR_NO_MEDIUM_ON_GEOM)
		.export_values();
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Hypothesis.hxx
	py::enum_<MeshDimension>(mod, "MeshDimension", "None")
		.value("MeshDim_0D", MeshDimension::MeshDim_0D)
		.value("MeshDim_1D", MeshDimension::MeshDim_1D)
		.value("MeshDim_2D", MeshDimension::MeshDim_2D)
		.value("MeshDim_3D", MeshDimension::MeshDim_3D)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// Callback for SMESH_Hypothesis.
	class PyCallback_SMESH_Hypothesis : public SMESH_Hypothesis {
	public:
		using SMESH_Hypothesis::SMESH_Hypothesis;

		std::ostream & SaveTo(std::ostream & save) override { PYBIND11_OVERLOAD_PURE(std::ostream &, SMESH_Hypothesis, SaveTo, save); }
		std::istream & LoadFrom(std::istream & load) override { PYBIND11_OVERLOAD_PURE(std::istream &, SMESH_Hypothesis, LoadFrom, load); }
		bool SetParametersByMesh(const SMESH_Mesh * theMesh, const TopoDS_Shape & theShape) override { PYBIND11_OVERLOAD_PURE(bool, SMESH_Hypothesis, SetParametersByMesh, theMesh, theShape); }
		bool SetParametersByDefaults(const SMESH_Hypothesis::TDefaults & dflts, const SMESH_Mesh * theMesh) override { PYBIND11_OVERLOAD_PURE(bool, SMESH_Hypothesis, SetParametersByDefaults, dflts, theMesh); }
	};

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Hypothesis.hxx
	py::class_<SMESH_Hypothesis, std::unique_ptr<SMESH_Hypothesis, py::nodelete>, PyCallback_SMESH_Hypothesis, SMESHDS_Hypothesis> cls_SMESH_Hypothesis(mod, "SMESH_Hypothesis", "None");
	cls_SMESH_Hypothesis.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_SMESH_Hypothesis.def_static("IsStatusFatal_", (bool (*)(SMESH_Hypothesis::Hypothesis_Status)) &SMESH_Hypothesis::IsStatusFatal, "None", py::arg("theStatus"));
	cls_SMESH_Hypothesis.def("GetDim", (int (SMESH_Hypothesis::*)() const ) &SMESH_Hypothesis::GetDim, "None");
	cls_SMESH_Hypothesis.def("GetStudyId", (int (SMESH_Hypothesis::*)() const ) &SMESH_Hypothesis::GetStudyId, "None");
	cls_SMESH_Hypothesis.def("GetGen", (SMESH_Gen * (SMESH_Hypothesis::*)() const ) &SMESH_Hypothesis::GetGen, "None");
	cls_SMESH_Hypothesis.def("GetShapeType", (int (SMESH_Hypothesis::*)() const ) &SMESH_Hypothesis::GetShapeType, "None");
	cls_SMESH_Hypothesis.def("GetLibName", (const char * (SMESH_Hypothesis::*)() const ) &SMESH_Hypothesis::GetLibName, "None");
	cls_SMESH_Hypothesis.def("NotifySubMeshesHypothesisModification", (void (SMESH_Hypothesis::*)()) &SMESH_Hypothesis::NotifySubMeshesHypothesisModification, "None");
	cls_SMESH_Hypothesis.def("SetLibName", (void (SMESH_Hypothesis::*)(const char *)) &SMESH_Hypothesis::SetLibName, "None", py::arg("theLibName"));
	cls_SMESH_Hypothesis.def("DataDependOnParams", (bool (SMESH_Hypothesis::*)() const ) &SMESH_Hypothesis::DataDependOnParams, "The returned value is used by NotifySubMeshesHypothesisModification() to decide to call subMesh->AlgoStateEngine( MODIF_HYP, hyp ) or not if subMesh is ready to be computed (algo+hyp==OK) but not yet computed. True result is reasonable for example if EventListeners depend on parameters of hypothesis.");
	cls_SMESH_Hypothesis.def("SetParametersByMesh", (bool (SMESH_Hypothesis::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &SMESH_Hypothesis::SetParametersByMesh, "Initialize my parameter values by the mesh built on the geometry", py::arg("theMesh"), py::arg("theShape"));
	cls_SMESH_Hypothesis.def("SetParametersByDefaults", [](SMESH_Hypothesis &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_SMESH_Hypothesis.def("SetParametersByDefaults", (bool (SMESH_Hypothesis::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &SMESH_Hypothesis::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));
	cls_SMESH_Hypothesis.def("IsAuxiliary", (bool (SMESH_Hypothesis::*)() const ) &SMESH_Hypothesis::IsAuxiliary, "Return true if me is an auxiliary hypothesis bool - auxiliary or not");
	cls_SMESH_Hypothesis.def("GetMeshByPersistentID", (SMESH_Mesh * (SMESH_Hypothesis::*)(int)) &SMESH_Hypothesis::GetMeshByPersistentID, "Find a mesh with given persistent ID", py::arg("id"));
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Hypothesis.hxx
	py::enum_<SMESH_Hypothesis::Hypothesis_Status>(cls_SMESH_Hypothesis, "Hypothesis_Status", "None")
		.value("HYP_OK", SMESH_Hypothesis::Hypothesis_Status::HYP_OK)
		.value("HYP_MISSING", SMESH_Hypothesis::Hypothesis_Status::HYP_MISSING)
		.value("HYP_CONCURENT", SMESH_Hypothesis::Hypothesis_Status::HYP_CONCURENT)
		.value("HYP_BAD_PARAMETER", SMESH_Hypothesis::Hypothesis_Status::HYP_BAD_PARAMETER)
		.value("HYP_HIDDEN_ALGO", SMESH_Hypothesis::Hypothesis_Status::HYP_HIDDEN_ALGO)
		.value("HYP_HIDING_ALGO", SMESH_Hypothesis::Hypothesis_Status::HYP_HIDING_ALGO)
		.value("HYP_UNKNOWN_FATAL", SMESH_Hypothesis::Hypothesis_Status::HYP_UNKNOWN_FATAL)
		.value("HYP_INCOMPATIBLE", SMESH_Hypothesis::Hypothesis_Status::HYP_INCOMPATIBLE)
		.value("HYP_NOTCONFORM", SMESH_Hypothesis::Hypothesis_Status::HYP_NOTCONFORM)
		.value("HYP_ALREADY_EXIST", SMESH_Hypothesis::Hypothesis_Status::HYP_ALREADY_EXIST)
		.value("HYP_BAD_DIM", SMESH_Hypothesis::Hypothesis_Status::HYP_BAD_DIM)
		.value("HYP_BAD_SUBSHAPE", SMESH_Hypothesis::Hypothesis_Status::HYP_BAD_SUBSHAPE)
		.value("HYP_BAD_GEOMETRY", SMESH_Hypothesis::Hypothesis_Status::HYP_BAD_GEOMETRY)
		.value("HYP_NEED_SHAPE", SMESH_Hypothesis::Hypothesis_Status::HYP_NEED_SHAPE)
		.value("HYP_INCOMPAT_HYPS", SMESH_Hypothesis::Hypothesis_Status::HYP_INCOMPAT_HYPS)
		.export_values();

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_ComputeError.hxx
	py::class_<SMESH_ComputeError, boost::shared_ptr<SMESH_ComputeError>> cls_SMESH_ComputeError(mod, "SMESH_ComputeError", "Contains an algorithm and description of an occurred error");
	cls_SMESH_ComputeError.def(py::init<>());
	cls_SMESH_ComputeError.def(py::init<int>(), py::arg("error"));
	cls_SMESH_ComputeError.def(py::init<int, std::string>(), py::arg("error"), py::arg("comment"));
	cls_SMESH_ComputeError.def(py::init<int, std::string, const SMESH_Algo *>(), py::arg("error"), py::arg("comment"), py::arg("algo"));
	cls_SMESH_ComputeError.def_static("New_", []() -> SMESH_ComputeErrorPtr { return SMESH_ComputeError::New(); });
	cls_SMESH_ComputeError.def_static("New_", [](int a0) -> SMESH_ComputeErrorPtr { return SMESH_ComputeError::New(a0); }, py::arg("error"));
	cls_SMESH_ComputeError.def_static("New_", [](int a0, std::string a1) -> SMESH_ComputeErrorPtr { return SMESH_ComputeError::New(a0, a1); }, py::arg("error"), py::arg("comment"));
	cls_SMESH_ComputeError.def_static("New_", (SMESH_ComputeErrorPtr (*)(int, std::string, const SMESH_Algo *)) &SMESH_ComputeError::New, "None", py::arg("error"), py::arg("comment"), py::arg("algo"));
	cls_SMESH_ComputeError.def("IsOK", (bool (SMESH_ComputeError::*)() const ) &SMESH_ComputeError::IsOK, "None");
	cls_SMESH_ComputeError.def("IsKO", (bool (SMESH_ComputeError::*)() const ) &SMESH_ComputeError::IsKO, "None");
	cls_SMESH_ComputeError.def("IsCommon", (bool (SMESH_ComputeError::*)() const ) &SMESH_ComputeError::IsCommon, "None");
	cls_SMESH_ComputeError.def("HasBadElems", (bool (SMESH_ComputeError::*)() const ) &SMESH_ComputeError::HasBadElems, "None");
	cls_SMESH_ComputeError.def("CommonName", (std::string (SMESH_ComputeError::*)() const ) &SMESH_ComputeError::CommonName, "None");
	cls_SMESH_ComputeError.def_static("Worst_", (SMESH_ComputeErrorPtr (*)(SMESH_ComputeErrorPtr, SMESH_ComputeErrorPtr)) &SMESH_ComputeError::Worst, "None", py::arg("er1"), py::arg("er2"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_File.hxx
	py::class_<SMESH_File, std::unique_ptr<SMESH_File, Deleter<SMESH_File>>> cls_SMESH_File(mod, "SMESH_File", "High level util for effective file reading and other file operations");
	cls_SMESH_File.def(py::init<const std::string &>(), py::arg("name"));
	cls_SMESH_File.def(py::init<const std::string &, bool>(), py::arg("name"), py::arg("openForReading"));
	cls_SMESH_File.def("getName", (std::string (SMESH_File::*)() const ) &SMESH_File::getName, "None");
	cls_SMESH_File.def("error", (const std::string & (SMESH_File::*)() const ) &SMESH_File::error, "None");
	cls_SMESH_File.def("close", (void (SMESH_File::*)()) &SMESH_File::close, "None");
	cls_SMESH_File.def("remove", (bool (SMESH_File::*)()) &SMESH_File::remove, "None");
	cls_SMESH_File.def("size", (long (SMESH_File::*)()) &SMESH_File::size, "None");
	cls_SMESH_File.def("exists", (bool (SMESH_File::*)()) &SMESH_File::exists, "None");
	cls_SMESH_File.def("isDirectory", (bool (SMESH_File::*)()) &SMESH_File::isDirectory, "None");
	cls_SMESH_File.def("open", (bool (SMESH_File::*)()) &SMESH_File::open, "None");
	cls_SMESH_File.def("plus_plus", (bool (SMESH_File::*)()) &SMESH_File::operator++, py::is_operator(), "None");
	cls_SMESH_File.def("__iadd__", (void (SMESH_File::*)(int)) &SMESH_File::operator+=, "None", py::arg("posDelta"));
	cls_SMESH_File.def("eof", (bool (SMESH_File::*)() const ) &SMESH_File::eof, "None");
	cls_SMESH_File.def("end", (const char * (SMESH_File::*)() const ) &SMESH_File::end, "None");
	cls_SMESH_File.def("getPos", (const char * (SMESH_File::*)() const ) &SMESH_File::getPos, "None");
	cls_SMESH_File.def("setPos", (void (SMESH_File::*)(const char *)) &SMESH_File::setPos, "None", py::arg("pos"));
	cls_SMESH_File.def("getLine", (std::string (SMESH_File::*)()) &SMESH_File::getLine, "None");
	cls_SMESH_File.def("rewind", (void (SMESH_File::*)()) &SMESH_File::rewind, "None");
	cls_SMESH_File.def("getInts", (bool (SMESH_File::*)(std::vector<int> &)) &SMESH_File::getInts, "None", py::arg("ids"));
	cls_SMESH_File.def("openForWriting", (bool (SMESH_File::*)()) &SMESH_File::openForWriting, "None");
	cls_SMESH_File.def("writeRaw", (bool (SMESH_File::*)(const void *, size_t)) &SMESH_File::writeRaw, "None", py::arg("data"), py::arg("size"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Gen.hxx
	py::class_<SMESH_Gen, std::unique_ptr<SMESH_Gen, Deleter<SMESH_Gen>>> cls_SMESH_Gen(mod, "SMESH_Gen", "None");
	cls_SMESH_Gen.def(py::init<>());
	cls_SMESH_Gen.def("CreateMesh", (SMESH_Mesh * (SMESH_Gen::*)(int, bool)) &SMESH_Gen::CreateMesh, "None", py::arg("theStudyId"), py::arg("theIsEmbeddedMode"));
	cls_SMESH_Gen.def("Compute", [](SMESH_Gen &self, ::SMESH_Mesh & a0, const TopoDS_Shape & a1) -> bool { return self.Compute(a0, a1); }, py::arg("aMesh"), py::arg("aShape"));
	cls_SMESH_Gen.def("Compute", [](SMESH_Gen &self, ::SMESH_Mesh & a0, const TopoDS_Shape & a1, const int a2) -> bool { return self.Compute(a0, a1, a2); }, py::arg("aMesh"), py::arg("aShape"), py::arg("aFlags"));
	cls_SMESH_Gen.def("Compute", [](SMESH_Gen &self, ::SMESH_Mesh & a0, const TopoDS_Shape & a1, const int a2, const ::MeshDimension a3) -> bool { return self.Compute(a0, a1, a2, a3); }, py::arg("aMesh"), py::arg("aShape"), py::arg("aFlags"), py::arg("aDim"));
	cls_SMESH_Gen.def("Compute", (bool (SMESH_Gen::*)(::SMESH_Mesh &, const TopoDS_Shape &, const int, const ::MeshDimension, TSetOfInt *)) &SMESH_Gen::Compute, "Computes aMesh on aShape", py::arg("aMesh"), py::arg("aShape"), py::arg("aFlags"), py::arg("aDim"), py::arg("aShapesId"));
	cls_SMESH_Gen.def("PrepareCompute", (void (SMESH_Gen::*)(::SMESH_Mesh &, const TopoDS_Shape &)) &SMESH_Gen::PrepareCompute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_SMESH_Gen.def("CancelCompute", (void (SMESH_Gen::*)(::SMESH_Mesh &, const TopoDS_Shape &)) &SMESH_Gen::CancelCompute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_SMESH_Gen.def("GetCurrentSubMesh", (const SMESH_subMesh * (SMESH_Gen::*)() const ) &SMESH_Gen::GetCurrentSubMesh, "None");
	cls_SMESH_Gen.def("Evaluate", [](SMESH_Gen &self, ::SMESH_Mesh & a0, const TopoDS_Shape & a1, MapShapeNbElems & a2) -> bool { return self.Evaluate(a0, a1, a2); }, py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));
	cls_SMESH_Gen.def("Evaluate", [](SMESH_Gen &self, ::SMESH_Mesh & a0, const TopoDS_Shape & a1, MapShapeNbElems & a2, const bool a3) -> bool { return self.Evaluate(a0, a1, a2, a3); }, py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"), py::arg("anUpward"));
	cls_SMESH_Gen.def("Evaluate", (bool (SMESH_Gen::*)(::SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &, const bool, TSetOfInt *)) &SMESH_Gen::Evaluate, "evaluates size of prospective mesh on a shape", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"), py::arg("anUpward"), py::arg("aShapesId"));
	cls_SMESH_Gen.def("CheckAlgoState", (bool (SMESH_Gen::*)(SMESH_Mesh &, const TopoDS_Shape &)) &SMESH_Gen::CheckAlgoState, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_SMESH_Gen.def("SetBoundaryBoxSegmentation", (void (SMESH_Gen::*)(int)) &SMESH_Gen::SetBoundaryBoxSegmentation, "Sets number of segments per diagonal of boundary box of geometry by which default segment length of appropriate 1D hypotheses is defined", py::arg("theNbSegments"));
	cls_SMESH_Gen.def("GetBoundaryBoxSegmentation", (int (SMESH_Gen::*)() const ) &SMESH_Gen::GetBoundaryBoxSegmentation, "None");
	cls_SMESH_Gen.def("SetDefaultNbSegments", (void (SMESH_Gen::*)(int)) &SMESH_Gen::SetDefaultNbSegments, "Sets default number of segments per edge", py::arg("nb"));
	cls_SMESH_Gen.def("GetDefaultNbSegments", (int (SMESH_Gen::*)() const ) &SMESH_Gen::GetDefaultNbSegments, "None");
	cls_SMESH_Gen.def("GetAlgoState", (bool (SMESH_Gen::*)(SMESH_Mesh &, const TopoDS_Shape &, std::list<SMESH_Gen::TAlgoStateError> &)) &SMESH_Gen::GetAlgoState, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("theErrors"));
	cls_SMESH_Gen.def("GetStudyContext", (StudyContextStruct * (SMESH_Gen::*)(int)) &SMESH_Gen::GetStudyContext, "None", py::arg("studyId"));
	cls_SMESH_Gen.def_static("GetShapeDim_", (int (*)(const TopAbs_ShapeEnum &)) &SMESH_Gen::GetShapeDim, "None", py::arg("aShapeType"));
	cls_SMESH_Gen.def_static("GetShapeDim_", (int (*)(const TopoDS_Shape &)) &SMESH_Gen::GetShapeDim, "None", py::arg("aShape"));
	cls_SMESH_Gen.def("GetAlgo", [](SMESH_Gen &self, SMESH_Mesh & a0, const TopoDS_Shape & a1) -> SMESH_Algo * { return self.GetAlgo(a0, a1); }, py::arg("aMesh"), py::arg("aShape"));
	cls_SMESH_Gen.def("GetAlgo", (SMESH_Algo * (SMESH_Gen::*)(SMESH_Mesh &, const TopoDS_Shape &, TopoDS_Shape *)) &SMESH_Gen::GetAlgo, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("assignedTo"));
	cls_SMESH_Gen.def("GetAlgo", [](SMESH_Gen &self, SMESH_subMesh * a0) -> SMESH_Algo * { return self.GetAlgo(a0); }, py::arg("aSubMesh"));
	cls_SMESH_Gen.def("GetAlgo", (SMESH_Algo * (SMESH_Gen::*)(SMESH_subMesh *, TopoDS_Shape *)) &SMESH_Gen::GetAlgo, "None", py::arg("aSubMesh"), py::arg("assignedTo"));
	cls_SMESH_Gen.def_static("IsGlobalHypothesis_", (bool (*)(const SMESH_Hypothesis *, SMESH_Mesh &)) &SMESH_Gen::IsGlobalHypothesis, "None", py::arg("theHyp"), py::arg("aMesh"));
	cls_SMESH_Gen.def_static("GetPluginXMLPaths_", (std::vector<std::string> (*)()) &SMESH_Gen::GetPluginXMLPaths, "None");
	cls_SMESH_Gen.def("GetANewId", (int (SMESH_Gen::*)()) &SMESH_Gen::GetANewId, "None");
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Gen.hxx
	py::enum_<SMESH_Gen::ComputeFlags>(cls_SMESH_Gen, "ComputeFlags", "None")
		.value("SHAPE_ONLY", SMESH_Gen::ComputeFlags::SHAPE_ONLY)
		.value("UPWARD", SMESH_Gen::ComputeFlags::UPWARD)
		.value("COMPACT_MESH", SMESH_Gen::ComputeFlags::COMPACT_MESH)
		.value("SHAPE_ONLY_UPWARD", SMESH_Gen::ComputeFlags::SHAPE_ONLY_UPWARD)
		.export_values();

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Mesh.hxx
	py::class_<SMESH_Mesh, std::unique_ptr<SMESH_Mesh, py::nodelete>> cls_SMESH_Mesh(mod, "SMESH_Mesh", "None");
	cls_SMESH_Mesh.def(py::init<int, int, SMESH_Gen *, bool, SMESHDS_Document *>(), py::arg("theLocalId"), py::arg("theStudyId"), py::arg("theGen"), py::arg("theIsEmbeddedMode"), py::arg("theDocument"));
	cls_SMESH_Mesh.def("ShapeToMesh", (void (SMESH_Mesh::*)(const TopoDS_Shape &)) &SMESH_Mesh::ShapeToMesh, "Set geometry to be meshed", py::arg("aShape"));
	cls_SMESH_Mesh.def("GetShapeToMesh", (TopoDS_Shape (SMESH_Mesh::*)() const ) &SMESH_Mesh::GetShapeToMesh, "Return geometry to be meshed. (It may be a PseudoShape()!)");
	cls_SMESH_Mesh.def("HasShapeToMesh", (bool (SMESH_Mesh::*)() const ) &SMESH_Mesh::HasShapeToMesh, "Return true if there is a geometry to be meshed, not PseudoShape()");
	cls_SMESH_Mesh.def("GetShapeDiagonalSize", (double (SMESH_Mesh::*)() const ) &SMESH_Mesh::GetShapeDiagonalSize, "Return diagonal size of bounding box of shape to mesh.");
	cls_SMESH_Mesh.def_static("GetShapeDiagonalSize_", (double (*)(const TopoDS_Shape &)) &SMESH_Mesh::GetShapeDiagonalSize, "Return diagonal size of bounding box of a shape.", py::arg("aShape"));
	cls_SMESH_Mesh.def_static("PseudoShape_", (const TopoDS_Solid & (*)()) &SMESH_Mesh::PseudoShape, "Return a solid which is returned by GetShapeToMesh() if a real geometry to be meshed was not set");
	cls_SMESH_Mesh.def("Load", (void (SMESH_Mesh::*)()) &SMESH_Mesh::Load, "Load mesh from study file");
	cls_SMESH_Mesh.def("Clear", (void (SMESH_Mesh::*)()) &SMESH_Mesh::Clear, "Remove all nodes and elements");
	cls_SMESH_Mesh.def("ClearSubMesh", (void (SMESH_Mesh::*)(const int)) &SMESH_Mesh::ClearSubMesh, "Remove all nodes and elements of indicated shape", py::arg("theShapeId"));
	cls_SMESH_Mesh.def("UNVToMesh", (int (SMESH_Mesh::*)(const char *)) &SMESH_Mesh::UNVToMesh, "consult DriverMED_R_SMESHDS_Mesh::ReadStatus for returned value", py::arg("theFileName"));
	cls_SMESH_Mesh.def("MEDToMesh", (int (SMESH_Mesh::*)(const char *, const char *)) &SMESH_Mesh::MEDToMesh, "None", py::arg("theFileName"), py::arg("theMeshName"));
	cls_SMESH_Mesh.def("STLToMesh", (std::string (SMESH_Mesh::*)(const char *)) &SMESH_Mesh::STLToMesh, "None", py::arg("theFileName"));
	cls_SMESH_Mesh.def("CGNSToMesh", (int (SMESH_Mesh::*)(const char *, const int, std::string &)) &SMESH_Mesh::CGNSToMesh, "None", py::arg("theFileName"), py::arg("theMeshIndex"), py::arg("theMeshName"));
	cls_SMESH_Mesh.def("GMFToMesh", [](SMESH_Mesh &self, const char * a0) -> SMESH_ComputeErrorPtr { return self.GMFToMesh(a0); }, py::arg("theFileName"));
	cls_SMESH_Mesh.def("GMFToMesh", (SMESH_ComputeErrorPtr (SMESH_Mesh::*)(const char *, bool)) &SMESH_Mesh::GMFToMesh, "None", py::arg("theFileName"), py::arg("theMakeRequiredGroups"));
	cls_SMESH_Mesh.def("AddHypothesis", [](SMESH_Mesh &self, const TopoDS_Shape & a0, int a1) -> SMESH_Hypothesis::Hypothesis_Status { return self.AddHypothesis(a0, a1); }, py::arg("aSubShape"), py::arg("anHypId"));
	cls_SMESH_Mesh.def("AddHypothesis", (SMESH_Hypothesis::Hypothesis_Status (SMESH_Mesh::*)(const TopoDS_Shape &, int, std::string *)) &SMESH_Mesh::AddHypothesis, "None", py::arg("aSubShape"), py::arg("anHypId"), py::arg("error"));
	cls_SMESH_Mesh.def("RemoveHypothesis", (SMESH_Hypothesis::Hypothesis_Status (SMESH_Mesh::*)(const TopoDS_Shape &, int)) &SMESH_Mesh::RemoveHypothesis, "None", py::arg("aSubShape"), py::arg("anHypId"));
	cls_SMESH_Mesh.def("GetHypothesisList", (const std::list<const SMESHDS_Hypothesis *> & (SMESH_Mesh::*)(const TopoDS_Shape &) const ) &SMESH_Mesh::GetHypothesisList, "None", py::arg("aSubShape"));
	cls_SMESH_Mesh.def("GetHypothesis", [](SMESH_Mesh &self, const TopoDS_Shape & a0, const SMESH_HypoFilter & a1, const bool a2) -> const SMESH_Hypothesis * { return self.GetHypothesis(a0, a1, a2); }, py::arg("aSubShape"), py::arg("aFilter"), py::arg("andAncestors"));
	cls_SMESH_Mesh.def("GetHypothesis", (const SMESH_Hypothesis * (SMESH_Mesh::*)(const TopoDS_Shape &, const SMESH_HypoFilter &, const bool, TopoDS_Shape *) const ) &SMESH_Mesh::GetHypothesis, "None", py::arg("aSubShape"), py::arg("aFilter"), py::arg("andAncestors"), py::arg("assignedTo"));
	cls_SMESH_Mesh.def("GetHypotheses", [](SMESH_Mesh &self, const TopoDS_Shape & a0, const SMESH_HypoFilter & a1, std::list<const SMESHDS_Hypothesis *> & a2, const bool a3) -> int { return self.GetHypotheses(a0, a1, a2, a3); }, py::arg("aSubShape"), py::arg("aFilter"), py::arg("aHypList"), py::arg("andAncestors"));
	cls_SMESH_Mesh.def("GetHypotheses", (int (SMESH_Mesh::*)(const TopoDS_Shape &, const SMESH_HypoFilter &, std::list<const SMESHDS_Hypothesis *> &, const bool, std::list<TopoDS_Shape> *) const ) &SMESH_Mesh::GetHypotheses, "None", py::arg("aSubShape"), py::arg("aFilter"), py::arg("aHypList"), py::arg("andAncestors"), py::arg("assignedTo"));
	cls_SMESH_Mesh.def("GetHypothesis", [](SMESH_Mesh &self, const SMESH_subMesh * a0, const SMESH_HypoFilter & a1, const bool a2) -> const SMESH_Hypothesis * { return self.GetHypothesis(a0, a1, a2); }, py::arg("aSubMesh"), py::arg("aFilter"), py::arg("andAncestors"));
	cls_SMESH_Mesh.def("GetHypothesis", (const SMESH_Hypothesis * (SMESH_Mesh::*)(const SMESH_subMesh *, const SMESH_HypoFilter &, const bool, TopoDS_Shape *) const ) &SMESH_Mesh::GetHypothesis, "None", py::arg("aSubMesh"), py::arg("aFilter"), py::arg("andAncestors"), py::arg("assignedTo"));
	cls_SMESH_Mesh.def("GetHypotheses", [](SMESH_Mesh &self, const SMESH_subMesh * a0, const SMESH_HypoFilter & a1, std::list<const SMESHDS_Hypothesis *> & a2, const bool a3) -> int { return self.GetHypotheses(a0, a1, a2, a3); }, py::arg("aSubMesh"), py::arg("aFilter"), py::arg("aHypList"), py::arg("andAncestors"));
	cls_SMESH_Mesh.def("GetHypotheses", (int (SMESH_Mesh::*)(const SMESH_subMesh *, const SMESH_HypoFilter &, std::list<const SMESHDS_Hypothesis *> &, const bool, std::list<TopoDS_Shape> *) const ) &SMESH_Mesh::GetHypotheses, "None", py::arg("aSubMesh"), py::arg("aFilter"), py::arg("aHypList"), py::arg("andAncestors"), py::arg("assignedTo"));
	cls_SMESH_Mesh.def("GetHypothesis", (SMESH_Hypothesis * (SMESH_Mesh::*)(const int) const ) &SMESH_Mesh::GetHypothesis, "None", py::arg("aHypID"));
	cls_SMESH_Mesh.def("GetLog", (const std::list<SMESHDS_Command *> & (SMESH_Mesh::*)()) &SMESH_Mesh::GetLog, "None");
	cls_SMESH_Mesh.def("ClearLog", (void (SMESH_Mesh::*)()) &SMESH_Mesh::ClearLog, "None");
	cls_SMESH_Mesh.def("GetId", (int (SMESH_Mesh::*)() const ) &SMESH_Mesh::GetId, "None");
	cls_SMESH_Mesh.def("MeshExists", (bool (SMESH_Mesh::*)(int) const ) &SMESH_Mesh::MeshExists, "None", py::arg("meshId"));
	cls_SMESH_Mesh.def("FindMesh", (SMESH_Mesh * (SMESH_Mesh::*)(int) const ) &SMESH_Mesh::FindMesh, "None", py::arg("meshId"));
	cls_SMESH_Mesh.def("GetMeshDS", (SMESHDS_Mesh * (SMESH_Mesh::*)()) &SMESH_Mesh::GetMeshDS, "None");
	cls_SMESH_Mesh.def("GetMeshDS", (const SMESHDS_Mesh * (SMESH_Mesh::*)() const ) &SMESH_Mesh::GetMeshDS, "None");
	cls_SMESH_Mesh.def("GetGen", (SMESH_Gen * (SMESH_Mesh::*)()) &SMESH_Mesh::GetGen, "None");
	cls_SMESH_Mesh.def("GetSubMesh", (SMESH_subMesh * (SMESH_Mesh::*)(const TopoDS_Shape &)) &SMESH_Mesh::GetSubMesh, "None", py::arg("aSubShape"));
	cls_SMESH_Mesh.def("GetSubMeshContaining", (SMESH_subMesh * (SMESH_Mesh::*)(const TopoDS_Shape &) const ) &SMESH_Mesh::GetSubMeshContaining, "None", py::arg("aSubShape"));
	cls_SMESH_Mesh.def("GetSubMeshContaining", (SMESH_subMesh * (SMESH_Mesh::*)(const int) const ) &SMESH_Mesh::GetSubMeshContaining, "None", py::arg("aShapeID"));
	cls_SMESH_Mesh.def("GetGroupSubMeshesContaining", (std::list<SMESH_subMesh *> (SMESH_Mesh::*)(const TopoDS_Shape &) const ) &SMESH_Mesh::GetGroupSubMeshesContaining, "Return submeshes of groups containing the given subshape", py::arg("shape"));
	cls_SMESH_Mesh.def("NotifySubMeshesHypothesisModification", (void (SMESH_Mesh::*)(const SMESH_Hypothesis *)) &SMESH_Mesh::NotifySubMeshesHypothesisModification, "Say all submeshes that theChangedHyp has been modified", py::arg("theChangedHyp"));
	cls_SMESH_Mesh.def("IsUsedHypothesis", (bool (SMESH_Mesh::*)(SMESHDS_Hypothesis *, const SMESH_subMesh *)) &SMESH_Mesh::IsUsedHypothesis, "Return True if anHyp is used to mesh aSubShape", py::arg("anHyp"), py::arg("aSubMesh"));
	cls_SMESH_Mesh.def("IsNotConformAllowed", (bool (SMESH_Mesh::*)() const ) &SMESH_Mesh::IsNotConformAllowed, "check if a hypothesis allowing notconform mesh is present");
	cls_SMESH_Mesh.def("IsMainShape", (bool (SMESH_Mesh::*)(const TopoDS_Shape &) const ) &SMESH_Mesh::IsMainShape, "None", py::arg("theShape"));
	cls_SMESH_Mesh.def("GetAncestors", (const TopTools_ListOfShape & (SMESH_Mesh::*)(const TopoDS_Shape &) const ) &SMESH_Mesh::GetAncestors, "Return list of ancestors of theSubShape in the order that lower dimension shapes come first", py::arg("theSubShape"));
	cls_SMESH_Mesh.def("SetAutoColor", (void (SMESH_Mesh::*)(bool)) &SMESH_Mesh::SetAutoColor, "None", py::arg("theAutoColor"));
	cls_SMESH_Mesh.def("GetAutoColor", (bool (SMESH_Mesh::*)()) &SMESH_Mesh::GetAutoColor, "None");
	cls_SMESH_Mesh.def("SetIsModified", (void (SMESH_Mesh::*)(bool)) &SMESH_Mesh::SetIsModified, "Set the flag meaning that the mesh has been edited 'manually'. It is to set to false after Clear() and to set to true by MeshEditor", py::arg("isModified"));
	cls_SMESH_Mesh.def("GetIsModified", (bool (SMESH_Mesh::*)() const ) &SMESH_Mesh::GetIsModified, "None");
	cls_SMESH_Mesh.def("HasModificationsToDiscard", (bool (SMESH_Mesh::*)() const ) &SMESH_Mesh::HasModificationsToDiscard, "Return true if the mesh has been edited since a total re-compute and those modifications may prevent successful partial re-compute. As a side effect reset _isModified flag if mesh is empty");
	cls_SMESH_Mesh.def("GetAncestorMap", (const SMESH_Mesh::TAncestorMap & (SMESH_Mesh::*)() const ) &SMESH_Mesh::GetAncestorMap, "None");
	cls_SMESH_Mesh.def("HasDuplicatedGroupNamesMED", (bool (SMESH_Mesh::*)()) &SMESH_Mesh::HasDuplicatedGroupNamesMED, "Check group names for duplications. Consider maximum group name length stored in MED file");
	cls_SMESH_Mesh.def("ExportMED", [](SMESH_Mesh &self, const char * a0) -> void { return self.ExportMED(a0); }, py::arg("theFile"));
	cls_SMESH_Mesh.def("ExportMED", [](SMESH_Mesh &self, const char * a0, const char * a1) -> void { return self.ExportMED(a0, a1); }, py::arg("theFile"), py::arg("theMeshName"));
	cls_SMESH_Mesh.def("ExportMED", [](SMESH_Mesh &self, const char * a0, const char * a1, bool a2) -> void { return self.ExportMED(a0, a1, a2); }, py::arg("theFile"), py::arg("theMeshName"), py::arg("theAutoGroups"));
	cls_SMESH_Mesh.def("ExportMED", [](SMESH_Mesh &self, const char * a0, const char * a1, bool a2, int a3) -> void { return self.ExportMED(a0, a1, a2, a3); }, py::arg("theFile"), py::arg("theMeshName"), py::arg("theAutoGroups"), py::arg("theVersion"));
	cls_SMESH_Mesh.def("ExportMED", [](SMESH_Mesh &self, const char * a0, const char * a1, bool a2, int a3, const SMESHDS_Mesh * a4) -> void { return self.ExportMED(a0, a1, a2, a3, a4); }, py::arg("theFile"), py::arg("theMeshName"), py::arg("theAutoGroups"), py::arg("theVersion"), py::arg("theMeshPart"));
	cls_SMESH_Mesh.def("ExportMED", [](SMESH_Mesh &self, const char * a0, const char * a1, bool a2, int a3, const SMESHDS_Mesh * a4, bool a5) -> void { return self.ExportMED(a0, a1, a2, a3, a4, a5); }, py::arg("theFile"), py::arg("theMeshName"), py::arg("theAutoGroups"), py::arg("theVersion"), py::arg("theMeshPart"), py::arg("theAutoDimension"));
	cls_SMESH_Mesh.def("ExportMED", [](SMESH_Mesh &self, const char * a0, const char * a1, bool a2, int a3, const SMESHDS_Mesh * a4, bool a5, bool a6) -> void { return self.ExportMED(a0, a1, a2, a3, a4, a5, a6); }, py::arg("theFile"), py::arg("theMeshName"), py::arg("theAutoGroups"), py::arg("theVersion"), py::arg("theMeshPart"), py::arg("theAutoDimension"), py::arg("theAddODOnVertices"));
	cls_SMESH_Mesh.def("ExportMED", (void (SMESH_Mesh::*)(const char *, const char *, bool, int, const SMESHDS_Mesh *, bool, bool, bool)) &SMESH_Mesh::ExportMED, "None", py::arg("theFile"), py::arg("theMeshName"), py::arg("theAutoGroups"), py::arg("theVersion"), py::arg("theMeshPart"), py::arg("theAutoDimension"), py::arg("theAddODOnVertices"), py::arg("theAllElemsToGroup"));
	cls_SMESH_Mesh.def("ExportDAT", [](SMESH_Mesh &self, const char * a0) -> void { return self.ExportDAT(a0); }, py::arg("file"));
	cls_SMESH_Mesh.def("ExportDAT", (void (SMESH_Mesh::*)(const char *, const SMESHDS_Mesh *)) &SMESH_Mesh::ExportDAT, "None", py::arg("file"), py::arg("meshPart"));
	cls_SMESH_Mesh.def("ExportUNV", [](SMESH_Mesh &self, const char * a0) -> void { return self.ExportUNV(a0); }, py::arg("file"));
	cls_SMESH_Mesh.def("ExportUNV", (void (SMESH_Mesh::*)(const char *, const SMESHDS_Mesh *)) &SMESH_Mesh::ExportUNV, "None", py::arg("file"), py::arg("meshPart"));
	cls_SMESH_Mesh.def("ExportSTL", [](SMESH_Mesh &self, const char * a0, const bool a1) -> void { return self.ExportSTL(a0, a1); }, py::arg("file"), py::arg("__isascii"));
	cls_SMESH_Mesh.def("ExportSTL", [](SMESH_Mesh &self, const char * a0, const bool a1, const char * a2) -> void { return self.ExportSTL(a0, a1, a2); }, py::arg("file"), py::arg("__isascii"), py::arg("name"));
	cls_SMESH_Mesh.def("ExportSTL", (void (SMESH_Mesh::*)(const char *, const bool, const char *, const SMESHDS_Mesh *)) &SMESH_Mesh::ExportSTL, "None", py::arg("file"), py::arg("__isascii"), py::arg("name"), py::arg("meshPart"));
	cls_SMESH_Mesh.def("ExportCGNS", [](SMESH_Mesh &self, const char * a0, const SMESHDS_Mesh * a1) -> void { return self.ExportCGNS(a0, a1); }, py::arg("file"), py::arg("mesh"));
	cls_SMESH_Mesh.def("ExportCGNS", (void (SMESH_Mesh::*)(const char *, const SMESHDS_Mesh *, const char *)) &SMESH_Mesh::ExportCGNS, "None", py::arg("file"), py::arg("mesh"), py::arg("meshName"));
	cls_SMESH_Mesh.def("ExportGMF", [](SMESH_Mesh &self, const char * a0, const SMESHDS_Mesh * a1) -> void { return self.ExportGMF(a0, a1); }, py::arg("file"), py::arg("mesh"));
	cls_SMESH_Mesh.def("ExportGMF", (void (SMESH_Mesh::*)(const char *, const SMESHDS_Mesh *, bool)) &SMESH_Mesh::ExportGMF, "None", py::arg("file"), py::arg("mesh"), py::arg("withRequiredGroups"));
	cls_SMESH_Mesh.def("ExportSAUV", [](SMESH_Mesh &self, const char * a0) -> void { return self.ExportSAUV(a0); }, py::arg("file"));
	cls_SMESH_Mesh.def("ExportSAUV", [](SMESH_Mesh &self, const char * a0, const char * a1) -> void { return self.ExportSAUV(a0, a1); }, py::arg("file"), py::arg("theMeshName"));
	cls_SMESH_Mesh.def("ExportSAUV", (void (SMESH_Mesh::*)(const char *, const char *, bool)) &SMESH_Mesh::ExportSAUV, "None", py::arg("file"), py::arg("theMeshName"), py::arg("theAutoGroups"));
	cls_SMESH_Mesh.def("GetComputeProgress", (double (SMESH_Mesh::*)() const ) &SMESH_Mesh::GetComputeProgress, "None");
	cls_SMESH_Mesh.def("NbNodes", (int (SMESH_Mesh::*)() const ) &SMESH_Mesh::NbNodes, "None");
	cls_SMESH_Mesh.def("Nb0DElements", (int (SMESH_Mesh::*)() const ) &SMESH_Mesh::Nb0DElements, "None");
	cls_SMESH_Mesh.def("NbBalls", (int (SMESH_Mesh::*)() const ) &SMESH_Mesh::NbBalls, "None");
	cls_SMESH_Mesh.def("NbEdges", [](SMESH_Mesh &self) -> int { return self.NbEdges(); });
	cls_SMESH_Mesh.def("NbEdges", (int (SMESH_Mesh::*)(SMDSAbs_ElementOrder) const ) &SMESH_Mesh::NbEdges, "None", py::arg("order"));
	cls_SMESH_Mesh.def("NbFaces", [](SMESH_Mesh &self) -> int { return self.NbFaces(); });
	cls_SMESH_Mesh.def("NbFaces", (int (SMESH_Mesh::*)(SMDSAbs_ElementOrder) const ) &SMESH_Mesh::NbFaces, "None", py::arg("order"));
	cls_SMESH_Mesh.def("NbTriangles", [](SMESH_Mesh &self) -> int { return self.NbTriangles(); });
	cls_SMESH_Mesh.def("NbTriangles", (int (SMESH_Mesh::*)(SMDSAbs_ElementOrder) const ) &SMESH_Mesh::NbTriangles, "None", py::arg("order"));
	cls_SMESH_Mesh.def("NbQuadrangles", [](SMESH_Mesh &self) -> int { return self.NbQuadrangles(); });
	cls_SMESH_Mesh.def("NbQuadrangles", (int (SMESH_Mesh::*)(SMDSAbs_ElementOrder) const ) &SMESH_Mesh::NbQuadrangles, "None", py::arg("order"));
	cls_SMESH_Mesh.def("NbBiQuadQuadrangles", (int (SMESH_Mesh::*)() const ) &SMESH_Mesh::NbBiQuadQuadrangles, "None");
	cls_SMESH_Mesh.def("NbBiQuadTriangles", (int (SMESH_Mesh::*)() const ) &SMESH_Mesh::NbBiQuadTriangles, "None");
	cls_SMESH_Mesh.def("NbPolygons", [](SMESH_Mesh &self) -> int { return self.NbPolygons(); });
	cls_SMESH_Mesh.def("NbPolygons", (int (SMESH_Mesh::*)(SMDSAbs_ElementOrder) const ) &SMESH_Mesh::NbPolygons, "None", py::arg("order"));
	cls_SMESH_Mesh.def("NbVolumes", [](SMESH_Mesh &self) -> int { return self.NbVolumes(); });
	cls_SMESH_Mesh.def("NbVolumes", (int (SMESH_Mesh::*)(SMDSAbs_ElementOrder) const ) &SMESH_Mesh::NbVolumes, "None", py::arg("order"));
	cls_SMESH_Mesh.def("NbTetras", [](SMESH_Mesh &self) -> int { return self.NbTetras(); });
	cls_SMESH_Mesh.def("NbTetras", (int (SMESH_Mesh::*)(SMDSAbs_ElementOrder) const ) &SMESH_Mesh::NbTetras, "None", py::arg("order"));
	cls_SMESH_Mesh.def("NbHexas", [](SMESH_Mesh &self) -> int { return self.NbHexas(); });
	cls_SMESH_Mesh.def("NbHexas", (int (SMESH_Mesh::*)(SMDSAbs_ElementOrder) const ) &SMESH_Mesh::NbHexas, "None", py::arg("order"));
	cls_SMESH_Mesh.def("NbTriQuadraticHexas", (int (SMESH_Mesh::*)() const ) &SMESH_Mesh::NbTriQuadraticHexas, "None");
	cls_SMESH_Mesh.def("NbPyramids", [](SMESH_Mesh &self) -> int { return self.NbPyramids(); });
	cls_SMESH_Mesh.def("NbPyramids", (int (SMESH_Mesh::*)(SMDSAbs_ElementOrder) const ) &SMESH_Mesh::NbPyramids, "None", py::arg("order"));
	cls_SMESH_Mesh.def("NbPrisms", [](SMESH_Mesh &self) -> int { return self.NbPrisms(); });
	cls_SMESH_Mesh.def("NbPrisms", (int (SMESH_Mesh::*)(SMDSAbs_ElementOrder) const ) &SMESH_Mesh::NbPrisms, "None", py::arg("order"));
	cls_SMESH_Mesh.def("NbHexagonalPrisms", (int (SMESH_Mesh::*)() const ) &SMESH_Mesh::NbHexagonalPrisms, "None");
	cls_SMESH_Mesh.def("NbPolyhedrons", (int (SMESH_Mesh::*)() const ) &SMESH_Mesh::NbPolyhedrons, "None");
	cls_SMESH_Mesh.def("NbSubMesh", (int (SMESH_Mesh::*)() const ) &SMESH_Mesh::NbSubMesh, "None");
	cls_SMESH_Mesh.def("NbGroup", (int (SMESH_Mesh::*)() const ) &SMESH_Mesh::NbGroup, "None");
	cls_SMESH_Mesh.def("NbMeshes", (int (SMESH_Mesh::*)() const ) &SMESH_Mesh::NbMeshes, "None");
	cls_SMESH_Mesh.def("AddGroup", [](SMESH_Mesh &self, const SMDSAbs_ElementType a0, const char * a1, int & a2) -> SMESH_Group * { return self.AddGroup(a0, a1, a2); }, py::arg("theType"), py::arg("theName"), py::arg("theId"));
	cls_SMESH_Mesh.def("AddGroup", [](SMESH_Mesh &self, const SMDSAbs_ElementType a0, const char * a1, int & a2, const TopoDS_Shape & a3) -> SMESH_Group * { return self.AddGroup(a0, a1, a2, a3); }, py::arg("theType"), py::arg("theName"), py::arg("theId"), py::arg("theShape"));
	cls_SMESH_Mesh.def("AddGroup", (SMESH_Group * (SMESH_Mesh::*)(const SMDSAbs_ElementType, const char *, int &, const TopoDS_Shape &, const SMESH_PredicatePtr &)) &SMESH_Mesh::AddGroup, "None", py::arg("theType"), py::arg("theName"), py::arg("theId"), py::arg("theShape"), py::arg("thePredicate"));
	cls_SMESH_Mesh.def("AddGroup", (SMESH_Group * (SMESH_Mesh::*)(SMESHDS_GroupBase *)) &SMESH_Mesh::AddGroup, "None", py::arg("groupDS"));
	cls_SMESH_Mesh.def("GetGroups", (SMESH_Mesh::GroupIteratorPtr (SMESH_Mesh::*)() const ) &SMESH_Mesh::GetGroups, "None");
	cls_SMESH_Mesh.def("GetGroupIds", (std::list<int> (SMESH_Mesh::*)() const ) &SMESH_Mesh::GetGroupIds, "None");
	cls_SMESH_Mesh.def("GetGroup", (SMESH_Group * (SMESH_Mesh::*)(const int)) &SMESH_Mesh::GetGroup, "None", py::arg("theGroupID"));
	cls_SMESH_Mesh.def("RemoveGroup", (bool (SMESH_Mesh::*)(const int)) &SMESH_Mesh::RemoveGroup, "None", py::arg("theGroupID"));
	cls_SMESH_Mesh.def("ConvertToStandalone", (SMESH_Group * (SMESH_Mesh::*)(int)) &SMESH_Mesh::ConvertToStandalone, "None", py::arg("theGroupID"));
	cls_SMESH_Mesh.def("SetCallUp", (void (SMESH_Mesh::*)(SMESH_Mesh::TCallUp *)) &SMESH_Mesh::SetCallUp, "None", py::arg("upCaller"));
	cls_SMESH_Mesh.def("SynchronizeGroups", (bool (SMESH_Mesh::*)()) &SMESH_Mesh::SynchronizeGroups, "None");
	cls_SMESH_Mesh.def("GetElementType", (SMDSAbs_ElementType (SMESH_Mesh::*)(const int, const bool)) &SMESH_Mesh::GetElementType, "None", py::arg("id"), py::arg("iselem"));
	cls_SMESH_Mesh.def("ClearMeshOrder", (void (SMESH_Mesh::*)()) &SMESH_Mesh::ClearMeshOrder, "None");
	cls_SMESH_Mesh.def("SetMeshOrder", (void (SMESH_Mesh::*)(const TListOfListOfInt &)) &SMESH_Mesh::SetMeshOrder, "None", py::arg("theOrder"));
	cls_SMESH_Mesh.def("GetMeshOrder", (const TListOfListOfInt & (SMESH_Mesh::*)() const ) &SMESH_Mesh::GetMeshOrder, "None");
	cls_SMESH_Mesh.def("SortByMeshOrder", (bool (SMESH_Mesh::*)(std::vector<SMESH_subMesh *> &) const ) &SMESH_Mesh::SortByMeshOrder, "None", py::arg("theListToSort"));
	cls_SMESH_Mesh.def("IsOrderOK", (bool (SMESH_Mesh::*)(const SMESH_subMesh *, const SMESH_subMesh *) const ) &SMESH_Mesh::IsOrderOK, "None", py::arg("smBefore"), py::arg("smAfter"));
	// FIXME cls_SMESH_Mesh.def("Dump", (std::ostream & (SMESH_Mesh::*)(std::ostream &)) &SMESH_Mesh::Dump, "None", py::arg("save"));

	// Callback for SMESH_Algo.
	class PyCallback_SMESH_Algo : public SMESH_Algo {
	public:
		using SMESH_Algo::SMESH_Algo;

		bool CheckHypothesis(SMESH_Mesh & aMesh, const TopoDS_Shape & aShape, SMESH_Hypothesis::Hypothesis_Status & aStatus) override { PYBIND11_OVERLOAD_PURE(bool, SMESH_Algo, CheckHypothesis, aMesh, aShape, aStatus); }
		bool Compute(SMESH_Mesh & aMesh, const TopoDS_Shape & aShape) override { PYBIND11_OVERLOAD_PURE(bool, SMESH_Algo, Compute, aMesh, aShape); }
		bool Evaluate(SMESH_Mesh & aMesh, const TopoDS_Shape & aShape, MapShapeNbElems & aResMap) override { PYBIND11_OVERLOAD_PURE(bool, SMESH_Algo, Evaluate, aMesh, aShape, aResMap); }
	};

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Algo.hxx
	py::class_<SMESH_Algo, std::unique_ptr<SMESH_Algo, py::nodelete>, PyCallback_SMESH_Algo, SMESH_Hypothesis> cls_SMESH_Algo(mod, "SMESH_Algo", "Root of all algorithms");
	cls_SMESH_Algo.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_SMESH_Algo.def_static("GetFeatures_", (const SMESH_Algo::Features & (*)(const std::string &)) &SMESH_Algo::GetFeatures, "Returns a structure describing algorithm features", py::arg("algoType"));
	cls_SMESH_Algo.def("GetFeatures", (const SMESH_Algo::Features & (SMESH_Algo::*)() const ) &SMESH_Algo::GetFeatures, "None");
	cls_SMESH_Algo.def("SaveTo", (std::ostream & (SMESH_Algo::*)(std::ostream &)) &SMESH_Algo::SaveTo, "Saves nothing in a stream", py::arg("save"));
	cls_SMESH_Algo.def("LoadFrom", (std::istream & (SMESH_Algo::*)(std::istream &)) &SMESH_Algo::LoadFrom, "Loads nothing from a stream", py::arg("load"));
	cls_SMESH_Algo.def("GetCompatibleHypothesis", (const std::vector<std::string> & (SMESH_Algo::*)()) &SMESH_Algo::GetCompatibleHypothesis, "Returns all types of compatible hypotheses");
	cls_SMESH_Algo.def("CheckHypothesis", (bool (SMESH_Algo::*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &SMESH_Algo::CheckHypothesis, "Check hypothesis definition to mesh a shape", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));
	cls_SMESH_Algo.def("Compute", (bool (SMESH_Algo::*)(SMESH_Mesh &, const TopoDS_Shape &)) &SMESH_Algo::Compute, "Computes mesh on a shape", py::arg("aMesh"), py::arg("aShape"));
	cls_SMESH_Algo.def("Compute", (bool (SMESH_Algo::*)(SMESH_Mesh &, SMESH_MesherHelper *)) &SMESH_Algo::Compute, "Computes mesh without geometry", py::arg("aMesh"), py::arg("aHelper"));
	cls_SMESH_Algo.def("CancelCompute", (void (SMESH_Algo::*)()) &SMESH_Algo::CancelCompute, "Sets _computeCanceled to true. It's usage depends on implementation of a particular mesher.");
	cls_SMESH_Algo.def("GetProgress", (double (SMESH_Algo::*)() const ) &SMESH_Algo::GetProgress, "If possible, returns progress of computation [0.,1.]");
	cls_SMESH_Algo.def("Evaluate", (bool (SMESH_Algo::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &SMESH_Algo::Evaluate, "evaluates size of prospective mesh on a shape", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));
	cls_SMESH_Algo.def("GetUsedHypothesis", [](SMESH_Algo &self, SMESH_Mesh & a0, const TopoDS_Shape & a1) -> const std::list<const SMESHDS_Hypothesis *> & { return self.GetUsedHypothesis(a0, a1); }, py::arg("aMesh"), py::arg("aShape"));
	cls_SMESH_Algo.def("GetUsedHypothesis", (const std::list<const SMESHDS_Hypothesis *> & (SMESH_Algo::*)(SMESH_Mesh &, const TopoDS_Shape &, const bool) const ) &SMESH_Algo::GetUsedHypothesis, "Returns a list of compatible hypotheses used to mesh a shape", py::arg("aMesh"), py::arg("aShape"), py::arg("ignoreAuxiliary"));
	cls_SMESH_Algo.def("GetAppliedHypothesis", [](SMESH_Algo &self, SMESH_Mesh & a0, const TopoDS_Shape & a1) -> const std::list<const SMESHDS_Hypothesis *> & { return self.GetAppliedHypothesis(a0, a1); }, py::arg("aMesh"), py::arg("aShape"));
	cls_SMESH_Algo.def("GetAppliedHypothesis", (const std::list<const SMESHDS_Hypothesis *> & (SMESH_Algo::*)(SMESH_Mesh &, const TopoDS_Shape &, const bool) const ) &SMESH_Algo::GetAppliedHypothesis, "Returns a list of compatible hypotheses assigned to a shape in a mesh", py::arg("aMesh"), py::arg("aShape"), py::arg("ignoreAuxiliary"));
	cls_SMESH_Algo.def("GetCompatibleHypoFilter", (const SMESH_HypoFilter * (SMESH_Algo::*)(const bool) const ) &SMESH_Algo::GetCompatibleHypoFilter, "Returns the filter recognizing only compatible hypotheses", py::arg("ignoreAuxiliary"));
	cls_SMESH_Algo.def("SetParametersByMesh", (bool (SMESH_Algo::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &SMESH_Algo::SetParametersByMesh, "Just return false as the algorithm does not hold parameters values", py::arg("theMesh"), py::arg("theShape"));
	cls_SMESH_Algo.def("SetParametersByDefaults", [](SMESH_Algo &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_SMESH_Algo.def("SetParametersByDefaults", (bool (SMESH_Algo::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &SMESH_Algo::SetParametersByDefaults, "None", py::arg("dflts"), py::arg("theMesh"));
	cls_SMESH_Algo.def("GetComputeError", (SMESH_ComputeErrorPtr (SMESH_Algo::*)() const ) &SMESH_Algo::GetComputeError, "return compute error");
	cls_SMESH_Algo.def("InitComputeError", (void (SMESH_Algo::*)()) &SMESH_Algo::InitComputeError, "initialize compute error etc. before call of Compute()");
	cls_SMESH_Algo.def("GetProgressByTic", (double (SMESH_Algo::*)() const ) &SMESH_Algo::GetProgressByTic, "Return compute progress by nb of calls of this method");
	cls_SMESH_Algo.def("SubMeshesToCompute", (std::vector<SMESH_subMesh *> & (SMESH_Algo::*)()) &SMESH_Algo::SubMeshesToCompute, "Return a vector of sub-meshes to Compute()");
	cls_SMESH_Algo.def("OnlyUnaryInput", (bool (SMESH_Algo::*)() const ) &SMESH_Algo::OnlyUnaryInput, "None");
	cls_SMESH_Algo.def("NeedDiscreteBoundary", (bool (SMESH_Algo::*)() const ) &SMESH_Algo::NeedDiscreteBoundary, "None");
	cls_SMESH_Algo.def("NeedShape", (bool (SMESH_Algo::*)() const ) &SMESH_Algo::NeedShape, "None");
	cls_SMESH_Algo.def("SupportSubmeshes", (bool (SMESH_Algo::*)() const ) &SMESH_Algo::SupportSubmeshes, "None");
	cls_SMESH_Algo.def("NeedLowerHyps", (bool (SMESH_Algo::*)(int) const ) &SMESH_Algo::NeedLowerHyps, "None", py::arg("dim"));
	cls_SMESH_Algo.def("SetEventListener", (void (SMESH_Algo::*)(SMESH_subMesh *)) &SMESH_Algo::SetEventListener, "Sets event listener to submeshes if necessary", py::arg("subMesh"));
	cls_SMESH_Algo.def("SubmeshRestored", (void (SMESH_Algo::*)(SMESH_subMesh *)) &SMESH_Algo::SubmeshRestored, "Allow algo to do something after persistent restoration", py::arg("subMesh"));
	cls_SMESH_Algo.def_static("GetNodeParamOnEdge_", (bool (*)(const SMESHDS_Mesh *, const TopoDS_Edge &, std::vector<double> &)) &SMESH_Algo::GetNodeParamOnEdge, "Fill vector of node parameters on geometrical edge, including vertex nodes", py::arg("theMesh"), py::arg("theEdge"), py::arg("theParams"));
	cls_SMESH_Algo.def_static("GetSortedNodesOnEdge_", [](const SMESHDS_Mesh * a0, const TopoDS_Edge & a1, const bool a2, std::map<double, const SMDS_MeshNode *> & a3) -> bool { return SMESH_Algo::GetSortedNodesOnEdge(a0, a1, a2, a3); }, py::arg("theMesh"), py::arg("theEdge"), py::arg("ignoreMediumNodes"), py::arg("theNodes"));
	cls_SMESH_Algo.def_static("GetSortedNodesOnEdge_", (bool (*)(const SMESHDS_Mesh *, const TopoDS_Edge &, const bool, std::map<double, const SMDS_MeshNode *> &, const SMDSAbs_ElementType)) &SMESH_Algo::GetSortedNodesOnEdge, "Fill map of node parameter on geometrical edge to node it-self", py::arg("theMesh"), py::arg("theEdge"), py::arg("ignoreMediumNodes"), py::arg("theNodes"), py::arg("typeToCheck"));
	cls_SMESH_Algo.def_static("EdgeLength_", (double (*)(const TopoDS_Edge &)) &SMESH_Algo::EdgeLength, "Compute length of an edge", py::arg("E"));
	cls_SMESH_Algo.def("NumberOfPoints", (int (SMESH_Algo::*)(SMESH_Mesh &, const TopoDS_Wire &)) &SMESH_Algo::NumberOfPoints, "None", py::arg("aMesh"), py::arg("W"));
	cls_SMESH_Algo.def_static("Continuity_", (GeomAbs_Shape (*)(const TopoDS_Edge &, const TopoDS_Edge &)) &SMESH_Algo::Continuity, "Return continuity of two edges", py::arg("E1"), py::arg("E2"));
	cls_SMESH_Algo.def_static("IsContinuous_", (bool (*)(const TopoDS_Edge &, const TopoDS_Edge &)) &SMESH_Algo::IsContinuous, "Return true if an edge can be considered as a continuation of another", py::arg("E1"), py::arg("E2"));
	cls_SMESH_Algo.def_static("IsStraight_", [](const TopoDS_Edge & a0) -> bool { return SMESH_Algo::IsStraight(a0); }, py::arg("E"));
	cls_SMESH_Algo.def_static("IsStraight_", (bool (*)(const TopoDS_Edge &, const bool)) &SMESH_Algo::IsStraight, "Return true if an edge can be considered straight", py::arg("E"), py::arg("degenResult"));
	cls_SMESH_Algo.def_static("isDegenerated_", [](const TopoDS_Edge & a0) -> bool { return SMESH_Algo::isDegenerated(a0); }, py::arg("E"));
	cls_SMESH_Algo.def_static("isDegenerated_", (bool (*)(const TopoDS_Edge &, const bool)) &SMESH_Algo::isDegenerated, "Return true if an edge has no 3D curve", py::arg("E"), py::arg("checkLength"));
	cls_SMESH_Algo.def_static("VertexNode_", (const SMDS_MeshNode * (*)(const TopoDS_Vertex &, const SMESHDS_Mesh *)) &SMESH_Algo::VertexNode, "Return the node built on a vertex", py::arg("V"), py::arg("meshDS"));
	cls_SMESH_Algo.def_static("VertexNode_", (const SMDS_MeshNode * (*)(const TopoDS_Vertex &, const SMESH_Mesh *)) &SMESH_Algo::VertexNode, "Return the node built on a vertex. A node moved to other geometry by MergeNodes() is also returned.", py::arg("V"), py::arg("mesh"));
	cls_SMESH_Algo.def_static("VertexNode_", [](const TopoDS_Vertex & a0, const SMESHDS_SubMesh * a1, const SMESH_Mesh * a2) -> const SMDS_MeshNode * { return SMESH_Algo::VertexNode(a0, a1, a2); }, py::arg("V"), py::arg("edgeSM"), py::arg("mesh"));
	cls_SMESH_Algo.def_static("VertexNode_", (const SMDS_MeshNode * (*)(const TopoDS_Vertex &, const SMESHDS_SubMesh *, const SMESH_Mesh *, const bool)) &SMESH_Algo::VertexNode, "Return the node built on a vertex. A node moved to other geometry by MergeNodes() is also returned.", py::arg("V"), py::arg("edgeSM"), py::arg("mesh"), py::arg("checkV"));
	cls_SMESH_Algo.def_static("GetMeshError_", (SMESH_Algo::EMeshError (*)(SMESH_subMesh *)) &SMESH_Algo::GetMeshError, "Finds topological errors of a sub-mesh", py::arg("subMesh"));
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Algo.hxx
	py::enum_<SMESH_Algo::EMeshError>(cls_SMESH_Algo, "EMeshError", "None")
		.value("MEr_OK", SMESH_Algo::EMeshError::MEr_OK)
		.value("MEr_HOLES", SMESH_Algo::EMeshError::MEr_HOLES)
		.value("MEr_BAD_ORI", SMESH_Algo::EMeshError::MEr_BAD_ORI)
		.value("MEr_EMPTY", SMESH_Algo::EMeshError::MEr_EMPTY)
		.export_values();

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_TypeDefs.hxx
	// FIXME bind_std::pair<const SMDS_MeshNode *, const SMDS_MeshNode *>(mod, "NLink");

	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_TypeDefs.hxx
	py::class_<SMESH_TLink, std::unique_ptr<SMESH_TLink, Deleter<SMESH_TLink>>> cls_SMESH_TLink(mod, "SMESH_TLink", "A sorted pair of nodes");
	cls_SMESH_TLink.def(py::init<const SMDS_MeshNode *, const SMDS_MeshNode *>(), py::arg("n1"), py::arg("n2"));
	cls_SMESH_TLink.def(py::init<const NLink &>(), py::arg("link"));
	cls_SMESH_TLink.def("node1", (const SMDS_MeshNode * (SMESH_TLink::*)() const ) &SMESH_TLink::node1, "None");
	cls_SMESH_TLink.def("node2", (const SMDS_MeshNode * (SMESH_TLink::*)() const ) &SMESH_TLink::node2, "None");
	cls_SMESH_TLink.def_static("HashCode_", (int (*)(const SMESH_TLink &, int)) &SMESH_TLink::HashCode, "None", py::arg("link"), py::arg("aLimit"));
	cls_SMESH_TLink.def_static("IsEqual_", (Standard_Boolean (*)(const SMESH_TLink &, const SMESH_TLink &)) &SMESH_TLink::IsEqual, "None", py::arg("l1"), py::arg("l2"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_TypeDefs.hxx
	py::class_<SMESH_TNodeXYZ, std::unique_ptr<SMESH_TNodeXYZ, Deleter<SMESH_TNodeXYZ>>, gp_XYZ> cls_SMESH_TNodeXYZ(mod, "SMESH_TNodeXYZ", "SMDS_MeshNode -> gp_XYZ convertor");
	cls_SMESH_TNodeXYZ.def(py::init<>());
	cls_SMESH_TNodeXYZ.def(py::init<const SMDS_MeshElement *>(), py::arg("e"));
	cls_SMESH_TNodeXYZ.def("Set", [](SMESH_TNodeXYZ &self) -> bool { return self.Set(); });
	cls_SMESH_TNodeXYZ.def("Set", (bool (SMESH_TNodeXYZ::*)(const SMDS_MeshElement *)) &SMESH_TNodeXYZ::Set, "None", py::arg("e"));
	cls_SMESH_TNodeXYZ.def("Distance", (double (SMESH_TNodeXYZ::*)(const SMDS_MeshNode *) const ) &SMESH_TNodeXYZ::Distance, "None", py::arg("n"));
	cls_SMESH_TNodeXYZ.def("SquareDistance", (double (SMESH_TNodeXYZ::*)(const SMDS_MeshNode *) const ) &SMESH_TNodeXYZ::SquareDistance, "None", py::arg("n"));
	cls_SMESH_TNodeXYZ.def("__eq__", (bool (SMESH_TNodeXYZ::*)(const SMESH_TNodeXYZ &) const ) &SMESH_TNodeXYZ::operator==, py::is_operator(), "None", py::arg("other"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_TypeDefs.hxx
	py::class_<uvPtStruct, std::unique_ptr<uvPtStruct, Deleter<uvPtStruct>>> cls_uvPtStruct(mod, "uvPtStruct", "Data of a node generated on FACE boundary");
	cls_uvPtStruct.def(py::init<>());
	cls_uvPtStruct.def("UV", (gp_XY (uvPtStruct::*)() const ) &uvPtStruct::UV, "None");
	cls_uvPtStruct.def("SetUV", (void (uvPtStruct::*)(const gp_XY &)) &uvPtStruct::SetUV, "None", py::arg("uv"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_ProxyMesh.hxx
	py::class_<SMESH_ProxyMesh, std::unique_ptr<SMESH_ProxyMesh, Deleter<SMESH_ProxyMesh>>> cls_SMESH_ProxyMesh(mod, "SMESH_ProxyMesh", "Container of xD mesh elements substituting other ones in the input mesh of an (x+1)D algorithm");
	cls_SMESH_ProxyMesh.def(py::init<>());
	cls_SMESH_ProxyMesh.def(py::init<std::vector<SMESH_ProxyMesh::Ptr> &>(), py::arg("components"));
	cls_SMESH_ProxyMesh.def(py::init<const SMESH_Mesh &>(), py::arg("mesh"));
	cls_SMESH_ProxyMesh.def("GetSubMesh", (const SMESHDS_SubMesh * (SMESH_ProxyMesh::*)(const TopoDS_Shape &) const ) &SMESH_ProxyMesh::GetSubMesh, "None", py::arg("shape"));
	cls_SMESH_ProxyMesh.def("GetProxySubMesh", (const SMESH_ProxyMesh::SubMesh * (SMESH_ProxyMesh::*)(const TopoDS_Shape &) const ) &SMESH_ProxyMesh::GetProxySubMesh, "None", py::arg("shape"));
	cls_SMESH_ProxyMesh.def("GetProxyNode", (const SMDS_MeshNode * (SMESH_ProxyMesh::*)(const SMDS_MeshNode *) const ) &SMESH_ProxyMesh::GetProxyNode, "None", py::arg("node"));
	cls_SMESH_ProxyMesh.def("NbProxySubMeshes", (int (SMESH_ProxyMesh::*)() const ) &SMESH_ProxyMesh::NbProxySubMeshes, "None");
	cls_SMESH_ProxyMesh.def("GetFaces", (SMDS_ElemIteratorPtr (SMESH_ProxyMesh::*)() const ) &SMESH_ProxyMesh::GetFaces, "None");
	cls_SMESH_ProxyMesh.def("GetFaces", (SMDS_ElemIteratorPtr (SMESH_ProxyMesh::*)(const TopoDS_Shape &) const ) &SMESH_ProxyMesh::GetFaces, "None", py::arg("face"));
	cls_SMESH_ProxyMesh.def("NbFaces", (int (SMESH_ProxyMesh::*)() const ) &SMESH_ProxyMesh::NbFaces, "None");
	cls_SMESH_ProxyMesh.def("IsTemporary", (bool (SMESH_ProxyMesh::*)(const SMDS_MeshElement *) const ) &SMESH_ProxyMesh::IsTemporary, "None", py::arg("elem"));
	cls_SMESH_ProxyMesh.def("GetMesh", (SMESH_Mesh * (SMESH_ProxyMesh::*)() const ) &SMESH_ProxyMesh::GetMesh, "None");
	cls_SMESH_ProxyMesh.def("GetMeshDS", (SMESHDS_Mesh * (SMESH_ProxyMesh::*)() const ) &SMESH_ProxyMesh::GetMeshDS, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_MesherHelper.hxx
	py::class_<SMESH_MesherHelper, std::unique_ptr<SMESH_MesherHelper, Deleter<SMESH_MesherHelper>>> cls_SMESH_MesherHelper(mod, "SMESH_MesherHelper", "It helps meshers to add elements and provides other utilities");
	cls_SMESH_MesherHelper.def(py::init<SMESH_Mesh &>(), py::arg("theMesh"));
	cls_SMESH_MesherHelper.def_static("IsSameElemGeometry_", [](const SMESHDS_SubMesh * a0, SMDSAbs_GeometryType a1) -> bool { return SMESH_MesherHelper::IsSameElemGeometry(a0, a1); }, py::arg("smDS"), py::arg("shape"));
	cls_SMESH_MesherHelper.def_static("IsSameElemGeometry_", (bool (*)(const SMESHDS_SubMesh *, SMDSAbs_GeometryType, const bool)) &SMESH_MesherHelper::IsSameElemGeometry, "Returns true if all elements of a sub-mesh are of same shape", py::arg("smDS"), py::arg("shape"), py::arg("nullSubMeshRes"));
	cls_SMESH_MesherHelper.def_static("LoadNodeColumns_", [](TParam2ColumnMap & a0, const TopoDS_Face & a1, const std::list<TopoDS_Edge> & a2, SMESHDS_Mesh * a3) -> bool { return SMESH_MesherHelper::LoadNodeColumns(a0, a1, a2, a3); }, py::arg("theParam2ColumnMap"), py::arg("theFace"), py::arg("theBaseSide"), py::arg("theMesh"));
	cls_SMESH_MesherHelper.def_static("LoadNodeColumns_", (bool (*)(TParam2ColumnMap &, const TopoDS_Face &, const std::list<TopoDS_Edge> &, SMESHDS_Mesh *, SMESH_ProxyMesh *)) &SMESH_MesherHelper::LoadNodeColumns, "Load nodes bound to face into a map of node columns", py::arg("theParam2ColumnMap"), py::arg("theFace"), py::arg("theBaseSide"), py::arg("theMesh"), py::arg("theProxyMesh"));
	cls_SMESH_MesherHelper.def_static("LoadNodeColumns_", [](TParam2ColumnMap & a0, const TopoDS_Face & a1, const TopoDS_Edge & a2, SMESHDS_Mesh * a3) -> bool { return SMESH_MesherHelper::LoadNodeColumns(a0, a1, a2, a3); }, py::arg("theParam2ColumnMap"), py::arg("theFace"), py::arg("theBaseEdge"), py::arg("theMesh"));
	cls_SMESH_MesherHelper.def_static("LoadNodeColumns_", (bool (*)(TParam2ColumnMap &, const TopoDS_Face &, const TopoDS_Edge &, SMESHDS_Mesh *, SMESH_ProxyMesh *)) &SMESH_MesherHelper::LoadNodeColumns, "Variant of LoadNodeColumns() above with theBaseSide given by one edge", py::arg("theParam2ColumnMap"), py::arg("theFace"), py::arg("theBaseEdge"), py::arg("theMesh"), py::arg("theProxyMesh"));
	cls_SMESH_MesherHelper.def_static("IsStructured_", (bool (*)(SMESH_subMesh *)) &SMESH_MesherHelper::IsStructured, "Return true if 2D mesh on FACE is structured", py::arg("faceSM"));
	cls_SMESH_MesherHelper.def_static("IsDistorted2D_", [](SMESH_subMesh * a0) -> bool { return SMESH_MesherHelper::IsDistorted2D(a0); }, py::arg("faceSM"));
	cls_SMESH_MesherHelper.def_static("IsDistorted2D_", [](SMESH_subMesh * a0, bool a1) -> bool { return SMESH_MesherHelper::IsDistorted2D(a0, a1); }, py::arg("faceSM"), py::arg("checkUV"));
	cls_SMESH_MesherHelper.def_static("IsDistorted2D_", (bool (*)(SMESH_subMesh *, bool, SMESH_MesherHelper *)) &SMESH_MesherHelper::IsDistorted2D, "Return true if 2D mesh on FACE is distored", py::arg("faceSM"), py::arg("checkUV"), py::arg("faceHelper"));
	cls_SMESH_MesherHelper.def_static("IsMedium_", [](const SMDS_MeshNode * a0) -> bool { return SMESH_MesherHelper::IsMedium(a0); }, py::arg("node"));
	cls_SMESH_MesherHelper.def_static("IsMedium_", (bool (*)(const SMDS_MeshNode *, const SMDSAbs_ElementType)) &SMESH_MesherHelper::IsMedium, "Returns true if given node is medium", py::arg("node"), py::arg("typeToCheck"));
	cls_SMESH_MesherHelper.def_static("GetSubShapeByNode_", (TopoDS_Shape (*)(const SMDS_MeshNode *, const SMESHDS_Mesh *)) &SMESH_MesherHelper::GetSubShapeByNode, "Return support shape of a node", py::arg("node"), py::arg("meshDS"));
	cls_SMESH_MesherHelper.def_static("WrapIndex_", (int (*)(int, const int)) &SMESH_MesherHelper::WrapIndex, "Return a valid node index, fixing the given one if necessary", py::arg("ind"), py::arg("nbNodes"));
	cls_SMESH_MesherHelper.def_static("calcTFI_", (gp_XY (*)(double, double, const gp_XY &, const gp_XY &, const gp_XY &, const gp_XY &, const gp_XY &, const gp_XY &, const gp_XY &, const gp_XY &)) &SMESH_MesherHelper::calcTFI, "Return UV of a point inside a quadrilateral FACE by it's normalized parameters within a unit quadrangle and the corresponding projections on sub-shapes of the real-world FACE. The used calculation method is called Trans-Finite Interpolation (TFI).", py::arg("x"), py::arg("y"), py::arg("a0"), py::arg("a1"), py::arg("a2"), py::arg("a3"), py::arg("p0"), py::arg("p1"), py::arg("p2"), py::arg("p3"));
	cls_SMESH_MesherHelper.def_static("calcTFI_", (gp_XYZ (*)(double, double, const gp_XYZ &, const gp_XYZ &, const gp_XYZ &, const gp_XYZ &, const gp_XYZ &, const gp_XYZ &, const gp_XYZ &, const gp_XYZ &)) &SMESH_MesherHelper::calcTFI, "Same as 'gp_XY calcTFI(...)' but in 3D", py::arg("x"), py::arg("y"), py::arg("a0"), py::arg("a1"), py::arg("a2"), py::arg("a3"), py::arg("p0"), py::arg("p1"), py::arg("p2"), py::arg("p3"));
	cls_SMESH_MesherHelper.def_static("Count_", (int (*)(const TopoDS_Shape &, const TopAbs_ShapeEnum, const bool)) &SMESH_MesherHelper::Count, "Count nb of sub-shapes", py::arg("shape"), py::arg("type"), py::arg("ignoreSame"));
	cls_SMESH_MesherHelper.def_static("NbAncestors_", [](const TopoDS_Shape & a0, const SMESH_Mesh & a1) -> int { return SMESH_MesherHelper::NbAncestors(a0, a1); }, py::arg("shape"), py::arg("mesh"));
	cls_SMESH_MesherHelper.def_static("NbAncestors_", (int (*)(const TopoDS_Shape &, const SMESH_Mesh &, TopAbs_ShapeEnum)) &SMESH_MesherHelper::NbAncestors, "Return number of unique ancestors of the shape", py::arg("shape"), py::arg("mesh"), py::arg("ancestorType"));
	cls_SMESH_MesherHelper.def_static("GetAncestors_", [](const TopoDS_Shape & a0, const SMESH_Mesh & a1, TopAbs_ShapeEnum a2) -> PShapeIteratorPtr { return SMESH_MesherHelper::GetAncestors(a0, a1, a2); }, py::arg("shape"), py::arg("mesh"), py::arg("ancestorType"));
	cls_SMESH_MesherHelper.def_static("GetAncestors_", (PShapeIteratorPtr (*)(const TopoDS_Shape &, const SMESH_Mesh &, TopAbs_ShapeEnum, const TopoDS_Shape *)) &SMESH_MesherHelper::GetAncestors, "Return iterator on ancestors of the given type, included into a container shape", py::arg("shape"), py::arg("mesh"), py::arg("ancestorType"), py::arg("container"));
	cls_SMESH_MesherHelper.def_static("GetCommonAncestor_", (TopoDS_Shape (*)(const TopoDS_Shape &, const TopoDS_Shape &, const SMESH_Mesh &, TopAbs_ShapeEnum)) &SMESH_MesherHelper::GetCommonAncestor, "Find a common ancestor, of the given type, of two shapes", py::arg("shape1"), py::arg("shape2"), py::arg("mesh"), py::arg("ancestorType"));
	cls_SMESH_MesherHelper.def_static("GetSubShapeOri_", (TopAbs_Orientation (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &SMESH_MesherHelper::GetSubShapeOri, "Return orientation of sub-shape in the main shape", py::arg("shape"), py::arg("subShape"));
	cls_SMESH_MesherHelper.def_static("IsSubShape_", (bool (*)(const TopoDS_Shape &, const TopoDS_Shape &)) &SMESH_MesherHelper::IsSubShape, "None", py::arg("shape"), py::arg("mainShape"));
	cls_SMESH_MesherHelper.def_static("IsSubShape_", (bool (*)(const TopoDS_Shape &, SMESH_Mesh *)) &SMESH_MesherHelper::IsSubShape, "None", py::arg("shape"), py::arg("aMesh"));
	cls_SMESH_MesherHelper.def_static("IsBlock_", (bool (*)(const TopoDS_Shape &)) &SMESH_MesherHelper::IsBlock, "None", py::arg("shape"));
	cls_SMESH_MesherHelper.def_static("MaxTolerance_", (double (*)(const TopoDS_Shape &)) &SMESH_MesherHelper::MaxTolerance, "None", py::arg("shape"));
	cls_SMESH_MesherHelper.def_static("GetAngle_", [](const TopoDS_Edge & a0, const TopoDS_Edge & a1, const TopoDS_Face & a2, const TopoDS_Vertex & a3) -> double { return SMESH_MesherHelper::GetAngle(a0, a1, a2, a3); }, py::arg("E1"), py::arg("E2"), py::arg("F"), py::arg("V"));
	cls_SMESH_MesherHelper.def_static("GetAngle_", (double (*)(const TopoDS_Edge &, const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Vertex &, gp_Vec *)) &SMESH_MesherHelper::GetAngle, "None", py::arg("E1"), py::arg("E2"), py::arg("F"), py::arg("V"), py::arg("faceNormal"));
	cls_SMESH_MesherHelper.def_static("IsClosedEdge_", (bool (*)(const TopoDS_Edge &)) &SMESH_MesherHelper::IsClosedEdge, "None", py::arg("anEdge"));
	cls_SMESH_MesherHelper.def_static("IthVertex_", [](const bool a0, TopoDS_Edge a1) -> TopoDS_Vertex { return SMESH_MesherHelper::IthVertex(a0, a1); }, py::arg("is2nd"), py::arg("anEdge"));
	cls_SMESH_MesherHelper.def_static("IthVertex_", (TopoDS_Vertex (*)(const bool, TopoDS_Edge, const bool)) &SMESH_MesherHelper::IthVertex, "None", py::arg("is2nd"), py::arg("anEdge"), py::arg("CumOri"));
	cls_SMESH_MesherHelper.def_static("GetGroupType_", [](const TopoDS_Shape & a0) -> TopAbs_ShapeEnum { return SMESH_MesherHelper::GetGroupType(a0); }, py::arg("group"));
	cls_SMESH_MesherHelper.def_static("GetGroupType_", (TopAbs_ShapeEnum (*)(const TopoDS_Shape &, const bool)) &SMESH_MesherHelper::GetGroupType, "None", py::arg("group"), py::arg("avoidCompound"));
	cls_SMESH_MesherHelper.def_static("GetShapeOfHypothesis_", (TopoDS_Shape (*)(const SMESHDS_Hypothesis *, const TopoDS_Shape &, SMESH_Mesh *)) &SMESH_MesherHelper::GetShapeOfHypothesis, "None", py::arg("hyp"), py::arg("shape"), py::arg("mesh"));
	cls_SMESH_MesherHelper.def("GetGen", (SMESH_Gen * (SMESH_MesherHelper::*)() const ) &SMESH_MesherHelper::GetGen, "None");
	cls_SMESH_MesherHelper.def("GetMesh", (SMESH_Mesh * (SMESH_MesherHelper::*)() const ) &SMESH_MesherHelper::GetMesh, "None");
	cls_SMESH_MesherHelper.def("GetMeshDS", (SMESHDS_Mesh * (SMESH_MesherHelper::*)() const ) &SMESH_MesherHelper::GetMeshDS, "None");
	cls_SMESH_MesherHelper.def("IsQuadraticSubMesh", (bool (SMESH_MesherHelper::*)(const TopoDS_Shape &)) &SMESH_MesherHelper::IsQuadraticSubMesh, "Check submesh for given shape: if all elements on this shape are quadratic, quadratic elements will be created. Also fill myTLinkNodeMap", py::arg("theShape"));
	cls_SMESH_MesherHelper.def("SetIsQuadratic", (void (SMESH_MesherHelper::*)(const bool)) &SMESH_MesherHelper::SetIsQuadratic, "Set order of elements to create without calling IsQuadraticSubMesh()", py::arg("theBuildQuadratic"));
	cls_SMESH_MesherHelper.def("SetIsBiQuadratic", (void (SMESH_MesherHelper::*)(const bool)) &SMESH_MesherHelper::SetIsBiQuadratic, "Set myCreateBiQuadratic flag", py::arg("theBuildBiQuadratic"));
	cls_SMESH_MesherHelper.def("GetIsQuadratic", (bool (SMESH_MesherHelper::*)() const ) &SMESH_MesherHelper::GetIsQuadratic, "Return myCreateQuadratic flag");
	cls_SMESH_MesherHelper.def("IsReversedSubMesh", (bool (SMESH_MesherHelper::*)(const TopoDS_Face &)) &SMESH_MesherHelper::IsReversedSubMesh, "None", py::arg("theFace"));
	cls_SMESH_MesherHelper.def("GetIsBiQuadratic", (bool (SMESH_MesherHelper::*)() const ) &SMESH_MesherHelper::GetIsBiQuadratic, "Return myCreateBiQuadratic flag");
	cls_SMESH_MesherHelper.def("FixQuadraticElements", [](SMESH_MesherHelper &self, SMESH_ComputeErrorPtr & a0) -> void { return self.FixQuadraticElements(a0); }, py::arg("error"));
	cls_SMESH_MesherHelper.def("FixQuadraticElements", (void (SMESH_MesherHelper::*)(SMESH_ComputeErrorPtr &, bool)) &SMESH_MesherHelper::FixQuadraticElements, "Move medium nodes of faces and volumes to fix distorted elements", py::arg("error"), py::arg("volumeOnly"));
	cls_SMESH_MesherHelper.def("SetElementsOnShape", (bool (SMESH_MesherHelper::*)(bool)) &SMESH_MesherHelper::SetElementsOnShape, "To set created elements on the shape set by IsQuadraticSubMesh() or the next methods. By defaul elements are set on the shape if a mesh has no shape to be meshed", py::arg("toSet"));
	cls_SMESH_MesherHelper.def("SetSubShape", (void (SMESH_MesherHelper::*)(const int)) &SMESH_MesherHelper::SetSubShape, "Set shape to make elements on without calling IsQuadraticSubMesh()", py::arg("subShapeID"));
	cls_SMESH_MesherHelper.def("SetSubShape", (void (SMESH_MesherHelper::*)(const TopoDS_Shape &)) &SMESH_MesherHelper::SetSubShape, "==SMESHDS_Mesh::ShapeToIndex(shape)", py::arg("subShape"));
	cls_SMESH_MesherHelper.def("GetSubShapeID", (int (SMESH_MesherHelper::*)() const ) &SMESH_MesherHelper::GetSubShapeID, "Return ID of the shape set by IsQuadraticSubMesh() or SetSubShape() int - shape index in SMESHDS");
	cls_SMESH_MesherHelper.def("GetSubShape", (const TopoDS_Shape & (SMESH_MesherHelper::*)() const ) &SMESH_MesherHelper::GetSubShape, "Return the shape set by IsQuadraticSubMesh() or SetSubShape()");
	cls_SMESH_MesherHelper.def("CopySubShapeInfo", (void (SMESH_MesherHelper::*)(const SMESH_MesherHelper &)) &SMESH_MesherHelper::CopySubShapeInfo, "Copy shape information from another helper to improve performance since SetSubShape() can be time consuming if there are many edges", py::arg("other"));
	cls_SMESH_MesherHelper.def("ShapeToIndex", (int (SMESH_MesherHelper::*)(const TopoDS_Shape &) const ) &SMESH_MesherHelper::ShapeToIndex, "Convert a shape to its index in the SMESHDS_Mesh", py::arg("S"));
	cls_SMESH_MesherHelper.def("AddNode", [](SMESH_MesherHelper &self, double a0, double a1, double a2) -> SMDS_MeshNode * { return self.AddNode(a0, a1, a2); }, py::arg("x"), py::arg("y"), py::arg("z"));
	cls_SMESH_MesherHelper.def("AddNode", [](SMESH_MesherHelper &self, double a0, double a1, double a2, int a3) -> SMDS_MeshNode * { return self.AddNode(a0, a1, a2, a3); }, py::arg("x"), py::arg("y"), py::arg("z"), py::arg("ID"));
	cls_SMESH_MesherHelper.def("AddNode", [](SMESH_MesherHelper &self, double a0, double a1, double a2, int a3, double a4) -> SMDS_MeshNode * { return self.AddNode(a0, a1, a2, a3, a4); }, py::arg("x"), py::arg("y"), py::arg("z"), py::arg("ID"), py::arg("u"));
	cls_SMESH_MesherHelper.def("AddNode", (SMDS_MeshNode * (SMESH_MesherHelper::*)(double, double, double, int, double, double)) &SMESH_MesherHelper::AddNode, "Creates a node (!Note ID before u=0.,v0.)", py::arg("x"), py::arg("y"), py::arg("z"), py::arg("ID"), py::arg("u"), py::arg("v"));
	cls_SMESH_MesherHelper.def("AddEdge", [](SMESH_MesherHelper &self, const SMDS_MeshNode * a0, const SMDS_MeshNode * a1) -> SMDS_MeshEdge * { return self.AddEdge(a0, a1); }, py::arg("n1"), py::arg("n2"));
	cls_SMESH_MesherHelper.def("AddEdge", [](SMESH_MesherHelper &self, const SMDS_MeshNode * a0, const SMDS_MeshNode * a1, const int a2) -> SMDS_MeshEdge * { return self.AddEdge(a0, a1, a2); }, py::arg("n1"), py::arg("n2"), py::arg("id"));
	cls_SMESH_MesherHelper.def("AddEdge", (SMDS_MeshEdge * (SMESH_MesherHelper::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const int, const bool)) &SMESH_MesherHelper::AddEdge, "Creates quadratic or linear edge", py::arg("n1"), py::arg("n2"), py::arg("id"), py::arg("force3d"));
	cls_SMESH_MesherHelper.def("AddFace", [](SMESH_MesherHelper &self, const SMDS_MeshNode * a0, const SMDS_MeshNode * a1, const SMDS_MeshNode * a2) -> SMDS_MeshFace * { return self.AddFace(a0, a1, a2); }, py::arg("n1"), py::arg("n2"), py::arg("n3"));
	cls_SMESH_MesherHelper.def("AddFace", [](SMESH_MesherHelper &self, const SMDS_MeshNode * a0, const SMDS_MeshNode * a1, const SMDS_MeshNode * a2, const int a3) -> SMDS_MeshFace * { return self.AddFace(a0, a1, a2, a3); }, py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("id"));
	cls_SMESH_MesherHelper.def("AddFace", (SMDS_MeshFace * (SMESH_MesherHelper::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const int, const bool)) &SMESH_MesherHelper::AddFace, "Creates quadratic or linear triangle", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("id"), py::arg("force3d"));
	cls_SMESH_MesherHelper.def("AddFace", [](SMESH_MesherHelper &self, const SMDS_MeshNode * a0, const SMDS_MeshNode * a1, const SMDS_MeshNode * a2, const SMDS_MeshNode * a3) -> SMDS_MeshFace * { return self.AddFace(a0, a1, a2, a3); }, py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"));
	cls_SMESH_MesherHelper.def("AddFace", [](SMESH_MesherHelper &self, const SMDS_MeshNode * a0, const SMDS_MeshNode * a1, const SMDS_MeshNode * a2, const SMDS_MeshNode * a3, const int a4) -> SMDS_MeshFace * { return self.AddFace(a0, a1, a2, a3, a4); }, py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("id"));
	cls_SMESH_MesherHelper.def("AddFace", (SMDS_MeshFace * (SMESH_MesherHelper::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const int, const bool)) &SMESH_MesherHelper::AddFace, "Creates bi-quadratic, quadratic or linear quadrangle", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("id"), py::arg("force3d"));
	cls_SMESH_MesherHelper.def("AddPolygonalFace", [](SMESH_MesherHelper &self, const std::vector<const SMDS_MeshNode *> & a0) -> SMDS_MeshFace * { return self.AddPolygonalFace(a0); }, py::arg("nodes"));
	cls_SMESH_MesherHelper.def("AddPolygonalFace", [](SMESH_MesherHelper &self, const std::vector<const SMDS_MeshNode *> & a0, const int a1) -> SMDS_MeshFace * { return self.AddPolygonalFace(a0, a1); }, py::arg("nodes"), py::arg("id"));
	cls_SMESH_MesherHelper.def("AddPolygonalFace", (SMDS_MeshFace * (SMESH_MesherHelper::*)(const std::vector<const SMDS_MeshNode *> &, const int, const bool)) &SMESH_MesherHelper::AddPolygonalFace, "Creates polygon, with additional nodes in quadratic mesh", py::arg("nodes"), py::arg("id"), py::arg("force3d"));
	cls_SMESH_MesherHelper.def("AddVolume", [](SMESH_MesherHelper &self, const SMDS_MeshNode * a0, const SMDS_MeshNode * a1, const SMDS_MeshNode * a2, const SMDS_MeshNode * a3) -> SMDS_MeshVolume * { return self.AddVolume(a0, a1, a2, a3); }, py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"));
	cls_SMESH_MesherHelper.def("AddVolume", [](SMESH_MesherHelper &self, const SMDS_MeshNode * a0, const SMDS_MeshNode * a1, const SMDS_MeshNode * a2, const SMDS_MeshNode * a3, const int a4) -> SMDS_MeshVolume * { return self.AddVolume(a0, a1, a2, a3, a4); }, py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("id"));
	cls_SMESH_MesherHelper.def("AddVolume", (SMDS_MeshVolume * (SMESH_MesherHelper::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const int, const bool)) &SMESH_MesherHelper::AddVolume, "Creates quadratic or linear tetrahedron", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("id"), py::arg("force3d"));
	cls_SMESH_MesherHelper.def("AddVolume", [](SMESH_MesherHelper &self, const SMDS_MeshNode * a0, const SMDS_MeshNode * a1, const SMDS_MeshNode * a2, const SMDS_MeshNode * a3, const SMDS_MeshNode * a4) -> SMDS_MeshVolume * { return self.AddVolume(a0, a1, a2, a3, a4); }, py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"));
	cls_SMESH_MesherHelper.def("AddVolume", [](SMESH_MesherHelper &self, const SMDS_MeshNode * a0, const SMDS_MeshNode * a1, const SMDS_MeshNode * a2, const SMDS_MeshNode * a3, const SMDS_MeshNode * a4, const int a5) -> SMDS_MeshVolume * { return self.AddVolume(a0, a1, a2, a3, a4, a5); }, py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("id"));
	cls_SMESH_MesherHelper.def("AddVolume", (SMDS_MeshVolume * (SMESH_MesherHelper::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const int, const bool)) &SMESH_MesherHelper::AddVolume, "Creates quadratic or linear pyramid", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("id"), py::arg("force3d"));
	cls_SMESH_MesherHelper.def("AddVolume", [](SMESH_MesherHelper &self, const SMDS_MeshNode * a0, const SMDS_MeshNode * a1, const SMDS_MeshNode * a2, const SMDS_MeshNode * a3, const SMDS_MeshNode * a4, const SMDS_MeshNode * a5) -> SMDS_MeshVolume * { return self.AddVolume(a0, a1, a2, a3, a4, a5); }, py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"));
	cls_SMESH_MesherHelper.def("AddVolume", [](SMESH_MesherHelper &self, const SMDS_MeshNode * a0, const SMDS_MeshNode * a1, const SMDS_MeshNode * a2, const SMDS_MeshNode * a3, const SMDS_MeshNode * a4, const SMDS_MeshNode * a5, const int a6) -> SMDS_MeshVolume * { return self.AddVolume(a0, a1, a2, a3, a4, a5, a6); }, py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("id"));
	cls_SMESH_MesherHelper.def("AddVolume", (SMDS_MeshVolume * (SMESH_MesherHelper::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const int, const bool)) &SMESH_MesherHelper::AddVolume, "Creates quadratic or linear pentahedron", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("id"), py::arg("force3d"));
	cls_SMESH_MesherHelper.def("AddVolume", [](SMESH_MesherHelper &self, const SMDS_MeshNode * a0, const SMDS_MeshNode * a1, const SMDS_MeshNode * a2, const SMDS_MeshNode * a3, const SMDS_MeshNode * a4, const SMDS_MeshNode * a5, const SMDS_MeshNode * a6, const SMDS_MeshNode * a7) -> SMDS_MeshVolume * { return self.AddVolume(a0, a1, a2, a3, a4, a5, a6, a7); }, py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"));
	cls_SMESH_MesherHelper.def("AddVolume", [](SMESH_MesherHelper &self, const SMDS_MeshNode * a0, const SMDS_MeshNode * a1, const SMDS_MeshNode * a2, const SMDS_MeshNode * a3, const SMDS_MeshNode * a4, const SMDS_MeshNode * a5, const SMDS_MeshNode * a6, const SMDS_MeshNode * a7, const int a8) -> SMDS_MeshVolume * { return self.AddVolume(a0, a1, a2, a3, a4, a5, a6, a7, a8); }, py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("id"));
	cls_SMESH_MesherHelper.def("AddVolume", (SMDS_MeshVolume * (SMESH_MesherHelper::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const int, bool)) &SMESH_MesherHelper::AddVolume, "Creates bi-quadratic, quadratic or linear hexahedron", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("id"), py::arg("force3d"));
	cls_SMESH_MesherHelper.def("AddVolume", [](SMESH_MesherHelper &self, const SMDS_MeshNode * a0, const SMDS_MeshNode * a1, const SMDS_MeshNode * a2, const SMDS_MeshNode * a3, const SMDS_MeshNode * a4, const SMDS_MeshNode * a5, const SMDS_MeshNode * a6, const SMDS_MeshNode * a7, const SMDS_MeshNode * a8, const SMDS_MeshNode * a9, const SMDS_MeshNode * a10, const SMDS_MeshNode * a11) -> SMDS_MeshVolume * { return self.AddVolume(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11); }, py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("n9"), py::arg("n10"), py::arg("n11"), py::arg("n12"));
	cls_SMESH_MesherHelper.def("AddVolume", [](SMESH_MesherHelper &self, const SMDS_MeshNode * a0, const SMDS_MeshNode * a1, const SMDS_MeshNode * a2, const SMDS_MeshNode * a3, const SMDS_MeshNode * a4, const SMDS_MeshNode * a5, const SMDS_MeshNode * a6, const SMDS_MeshNode * a7, const SMDS_MeshNode * a8, const SMDS_MeshNode * a9, const SMDS_MeshNode * a10, const SMDS_MeshNode * a11, const int a12) -> SMDS_MeshVolume * { return self.AddVolume(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12); }, py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("n9"), py::arg("n10"), py::arg("n11"), py::arg("n12"), py::arg("id"));
	cls_SMESH_MesherHelper.def("AddVolume", (SMDS_MeshVolume * (SMESH_MesherHelper::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const int, bool)) &SMESH_MesherHelper::AddVolume, "Creates LINEAR!!!!!!!!! octahedron", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n5"), py::arg("n6"), py::arg("n7"), py::arg("n8"), py::arg("n9"), py::arg("n10"), py::arg("n11"), py::arg("n12"), py::arg("id"), py::arg("force3d"));
	cls_SMESH_MesherHelper.def("AddPolyhedralVolume", [](SMESH_MesherHelper &self, const std::vector<const SMDS_MeshNode *> & a0, const std::vector<int> & a1) -> SMDS_MeshVolume * { return self.AddPolyhedralVolume(a0, a1); }, py::arg("nodes"), py::arg("quantities"));
	cls_SMESH_MesherHelper.def("AddPolyhedralVolume", [](SMESH_MesherHelper &self, const std::vector<const SMDS_MeshNode *> & a0, const std::vector<int> & a1, const int a2) -> SMDS_MeshVolume * { return self.AddPolyhedralVolume(a0, a1, a2); }, py::arg("nodes"), py::arg("quantities"), py::arg("ID"));
	cls_SMESH_MesherHelper.def("AddPolyhedralVolume", (SMDS_MeshVolume * (SMESH_MesherHelper::*)(const std::vector<const SMDS_MeshNode *> &, const std::vector<int> &, const int, const bool)) &SMESH_MesherHelper::AddPolyhedralVolume, "Creates polyhedron. In quadratic mesh, adds medium nodes", py::arg("nodes"), py::arg("quantities"), py::arg("ID"), py::arg("force3d"));
	cls_SMESH_MesherHelper.def("ToFixNodeParameters", (void (SMESH_MesherHelper::*)(bool)) &SMESH_MesherHelper::ToFixNodeParameters, "Enables fixing node parameters on EDGEs and FACEs by GetNodeU(...,check=true), GetNodeUV(...,check=true), CheckNodeUV() and CheckNodeU() in case if a node lies on a shape set via SetSubShape(). Default is False", py::arg("toFix"));
	cls_SMESH_MesherHelper.def("GetNodeU", [](SMESH_MesherHelper &self, const TopoDS_Edge & a0, const SMDS_MeshNode * a1) -> double { return self.GetNodeU(a0, a1); }, py::arg("theEdge"), py::arg("theNode"));
	cls_SMESH_MesherHelper.def("GetNodeU", [](SMESH_MesherHelper &self, const TopoDS_Edge & a0, const SMDS_MeshNode * a1, const SMDS_MeshNode * a2) -> double { return self.GetNodeU(a0, a1, a2); }, py::arg("theEdge"), py::arg("theNode"), py::arg("inEdgeNode"));
	cls_SMESH_MesherHelper.def("GetNodeU", (double (SMESH_MesherHelper::*)(const TopoDS_Edge &, const SMDS_MeshNode *, const SMDS_MeshNode *, bool *) const ) &SMESH_MesherHelper::GetNodeU, "Return U of the given node on the edge", py::arg("theEdge"), py::arg("theNode"), py::arg("inEdgeNode"), py::arg("check"));
	cls_SMESH_MesherHelper.def("GetNodeUV", [](SMESH_MesherHelper &self, const TopoDS_Face & a0, const SMDS_MeshNode * a1) -> gp_XY { return self.GetNodeUV(a0, a1); }, py::arg("F"), py::arg("n"));
	cls_SMESH_MesherHelper.def("GetNodeUV", [](SMESH_MesherHelper &self, const TopoDS_Face & a0, const SMDS_MeshNode * a1, const SMDS_MeshNode * a2) -> gp_XY { return self.GetNodeUV(a0, a1, a2); }, py::arg("F"), py::arg("n"), py::arg("inFaceNode"));
	cls_SMESH_MesherHelper.def("GetNodeUV", (gp_XY (SMESH_MesherHelper::*)(const TopoDS_Face &, const SMDS_MeshNode *, const SMDS_MeshNode *, bool *) const ) &SMESH_MesherHelper::GetNodeUV, "Return node UV on face", py::arg("F"), py::arg("n"), py::arg("inFaceNode"), py::arg("check"));
	// FIXME cls_SMESH_MesherHelper.def("CheckNodeUV", [](SMESH_MesherHelper &self, const TopoDS_Face & a0, const SMDS_MeshNode * a1, gp_XY & a2, const double a3) -> bool { return self.CheckNodeUV(a0, a1, a2, a3); }, py::arg("F"), py::arg("n"), py::arg("uv"), py::arg("tol"));
	// FIXME cls_SMESH_MesherHelper.def("CheckNodeUV", [](SMESH_MesherHelper &self, const TopoDS_Face & a0, const SMDS_MeshNode * a1, gp_XY & a2, const double a3, const bool a4) -> bool { return self.CheckNodeUV(a0, a1, a2, a3, a4); }, py::arg("F"), py::arg("n"), py::arg("uv"), py::arg("tol"), py::arg("force"));
	// FIXME cls_SMESH_MesherHelper.def("CheckNodeUV", (bool (SMESH_MesherHelper::*)(const TopoDS_Face &, const SMDS_MeshNode *, gp_XY &, const double, const bool, double [4]) const ) &SMESH_MesherHelper::CheckNodeUV, "Check and fix node UV on a face", py::arg("F"), py::arg("n"), py::arg("uv"), py::arg("tol"), py::arg("force"), py::arg("distXYZ"));
	// FIXME cls_SMESH_MesherHelper.def("CheckNodeU", [](SMESH_MesherHelper &self, const TopoDS_Edge & a0, const SMDS_MeshNode * a1, double & a2, const double a3) -> bool { return self.CheckNodeU(a0, a1, a2, a3); }, py::arg("E"), py::arg("n"), py::arg("u"), py::arg("tol"));
	// FIXME cls_SMESH_MesherHelper.def("CheckNodeU", [](SMESH_MesherHelper &self, const TopoDS_Edge & a0, const SMDS_MeshNode * a1, double & a2, const double a3, const bool a4) -> bool { return self.CheckNodeU(a0, a1, a2, a3, a4); }, py::arg("E"), py::arg("n"), py::arg("u"), py::arg("tol"), py::arg("force"));
	// FIXME cls_SMESH_MesherHelper.def("CheckNodeU", (bool (SMESH_MesherHelper::*)(const TopoDS_Edge &, const SMDS_MeshNode *, double &, const double, const bool, double [4]) const ) &SMESH_MesherHelper::CheckNodeU, "Check and fix node U on an edge", py::arg("E"), py::arg("n"), py::arg("u"), py::arg("tol"), py::arg("force"), py::arg("distXYZ"));
	cls_SMESH_MesherHelper.def_static("GetMiddleUV_", (gp_XY (*)(const opencascade::handle<Geom_Surface> &, const gp_XY &, const gp_XY &)) &SMESH_MesherHelper::GetMiddleUV, "Return middle UV taking in account surface period", py::arg("surface"), py::arg("uv1"), py::arg("uv2"));
	cls_SMESH_MesherHelper.def_static("GetCenterUV_", [](const gp_XY & a0, const gp_XY & a1, const gp_XY & a2, const gp_XY & a3, const gp_XY & a4, const gp_XY & a5) -> gp_XY { return SMESH_MesherHelper::GetCenterUV(a0, a1, a2, a3, a4, a5); }, py::arg("uv1"), py::arg("uv2"), py::arg("uv3"), py::arg("uv12"), py::arg("uv23"), py::arg("uv31"));
	cls_SMESH_MesherHelper.def_static("GetCenterUV_", (gp_XY (*)(const gp_XY &, const gp_XY &, const gp_XY &, const gp_XY &, const gp_XY &, const gp_XY &, bool *)) &SMESH_MesherHelper::GetCenterUV, "Return UV for the central node of a biquadratic triangle", py::arg("uv1"), py::arg("uv2"), py::arg("uv3"), py::arg("uv12"), py::arg("uv23"), py::arg("uv31"), py::arg("isBadTria"));
	cls_SMESH_MesherHelper.def_static("ApplyIn2D_", [](opencascade::handle<Geom_Surface> a0, const gp_XY & a1, const gp_XY & a2, xyFunPtr a3) -> gp_XY { return SMESH_MesherHelper::ApplyIn2D(a0, a1, a2, a3); }, py::arg("surface"), py::arg("uv1"), py::arg("uv2"), py::arg("fun"));
	cls_SMESH_MesherHelper.def_static("ApplyIn2D_", (gp_XY (*)(opencascade::handle<Geom_Surface>, const gp_XY &, const gp_XY &, xyFunPtr, const bool)) &SMESH_MesherHelper::ApplyIn2D, "Perform given operation on two 2d points in parameric space of given surface. It takes into account period of the surface. Use gp_XY_FunPtr macro to easily define pointer to function of gp_XY class.", py::arg("surface"), py::arg("uv1"), py::arg("uv2"), py::arg("fun"), py::arg("resultInPeriod"));
	// FIXME cls_SMESH_MesherHelper.def("AdjustByPeriod", (void (SMESH_MesherHelper::*)(const TopoDS_Face &, gp_XY [], const int)) &SMESH_MesherHelper::AdjustByPeriod, "Move node positions on a FACE within surface period", py::arg("face"), py::arg("uv"), py::arg("nbUV"));
	cls_SMESH_MesherHelper.def("GetNodeUVneedInFaceNode", [](SMESH_MesherHelper &self) -> bool { return self.GetNodeUVneedInFaceNode(); });
	cls_SMESH_MesherHelper.def("GetNodeUVneedInFaceNode", (bool (SMESH_MesherHelper::*)(const TopoDS_Face &) const ) &SMESH_MesherHelper::GetNodeUVneedInFaceNode, "Check if inFaceNode argument is necessary for call GetNodeUV(F,..) bool - return true if the face is periodic", py::arg("F"));
	cls_SMESH_MesherHelper.def("GetProjector", [](SMESH_MesherHelper &self, const TopoDS_Face & a0, TopLoc_Location & a1) -> GeomAPI_ProjectPointOnSurf & { return self.GetProjector(a0, a1); }, py::arg("F"), py::arg("loc"));
	cls_SMESH_MesherHelper.def("GetProjector", (GeomAPI_ProjectPointOnSurf & (SMESH_MesherHelper::*)(const TopoDS_Face &, TopLoc_Location &, double) const ) &SMESH_MesherHelper::GetProjector, "Return projector intitialized by given face without location, which is returned", py::arg("F"), py::arg("loc"), py::arg("tol"));
	cls_SMESH_MesherHelper.def("GetSurface", (opencascade::handle<ShapeAnalysis_Surface> (SMESH_MesherHelper::*)(const TopoDS_Face &) const ) &SMESH_MesherHelper::GetSurface, "Return a cached ShapeAnalysis_Surface of a FACE", py::arg("F"));
	cls_SMESH_MesherHelper.def("IsDegenShape", (bool (SMESH_MesherHelper::*)(const int) const ) &SMESH_MesherHelper::IsDegenShape, "Check if shape is a degenerated edge or it's vertex", py::arg("subShape"));
	cls_SMESH_MesherHelper.def("HasDegeneratedEdges", (bool (SMESH_MesherHelper::*)() const ) &SMESH_MesherHelper::HasDegeneratedEdges, "Check if the shape set through IsQuadraticSubMesh() or SetSubShape() has a degenerated edges bool - true if it has");
	cls_SMESH_MesherHelper.def("IsSeamShape", (bool (SMESH_MesherHelper::*)(const int) const ) &SMESH_MesherHelper::IsSeamShape, "Check if shape is a seam edge or it's vertex", py::arg("subShape"));
	cls_SMESH_MesherHelper.def("IsSeamShape", (bool (SMESH_MesherHelper::*)(const TopoDS_Shape &) const ) &SMESH_MesherHelper::IsSeamShape, "Check if shape is a seam edge or it's vertex", py::arg("subShape"));
	cls_SMESH_MesherHelper.def("IsRealSeam", (bool (SMESH_MesherHelper::*)(const int) const ) &SMESH_MesherHelper::IsRealSeam, "Return true if an edge or a vertex encounters twice in face wire", py::arg("subShape"));
	cls_SMESH_MesherHelper.def("IsRealSeam", (bool (SMESH_MesherHelper::*)(const TopoDS_Shape &) const ) &SMESH_MesherHelper::IsRealSeam, "Return true if an edge or a vertex encounters twice in face wire", py::arg("subShape"));
	cls_SMESH_MesherHelper.def("HasSeam", (bool (SMESH_MesherHelper::*)() const ) &SMESH_MesherHelper::HasSeam, "Check if the shape set through IsQuadraticSubMesh() or SetSubShape() has a seam edge, i.e. an edge that has two parametric representations on a surface bool - true if it has");
	cls_SMESH_MesherHelper.def("HasRealSeam", (bool (SMESH_MesherHelper::*)() const ) &SMESH_MesherHelper::HasRealSeam, "Check if the shape set through IsQuadraticSubMesh() or SetSubShape() has a seam edge that encounters twice in a wire bool - true if it has");
	cls_SMESH_MesherHelper.def("GetPeriodicIndex", (int (SMESH_MesherHelper::*)() const ) &SMESH_MesherHelper::GetPeriodicIndex, "Return index of periodic parametric direction of a closed face int - 1 for U, 2 for V direction");
	cls_SMESH_MesherHelper.def("GetOtherParam", (double (SMESH_MesherHelper::*)(const double) const ) &SMESH_MesherHelper::GetOtherParam, "Return an alternative parameter for a node on seam", py::arg("param"));
	cls_SMESH_MesherHelper.def("IsOnSeam", (int (SMESH_MesherHelper::*)(const gp_XY &) const ) &SMESH_MesherHelper::IsOnSeam, "Check if UV is on seam. Return 0 if not, 1 for U seam, 2 for V seam", py::arg("uv"));
	cls_SMESH_MesherHelper.def("GetMediumNode", [](SMESH_MesherHelper &self, const SMDS_MeshNode * a0, const SMDS_MeshNode * a1, const bool a2) -> const SMDS_MeshNode * { return self.GetMediumNode(a0, a1, a2); }, py::arg("n1"), py::arg("n2"), py::arg("force3d"));
	cls_SMESH_MesherHelper.def("GetMediumNode", (const SMDS_MeshNode * (SMESH_MesherHelper::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const bool, TopAbs_ShapeEnum)) &SMESH_MesherHelper::GetMediumNode, "Return existing or create new medium nodes between given ones", py::arg("n1"), py::arg("n2"), py::arg("force3d"), py::arg("expectedSupport"));
	cls_SMESH_MesherHelper.def("GetCentralNode", (const SMDS_MeshNode * (SMESH_MesherHelper::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, bool)) &SMESH_MesherHelper::GetCentralNode, "Return existing or create a new central node for a quardilateral quadratic face given its 8 nodes.", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n4"), py::arg("n12"), py::arg("n23"), py::arg("n34"), py::arg("n41"), py::arg("force3d"));
	cls_SMESH_MesherHelper.def("GetCentralNode", (const SMDS_MeshNode * (SMESH_MesherHelper::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, bool)) &SMESH_MesherHelper::GetCentralNode, "Return existing or create a new central node for a quadratic triangle given its 6 nodes.", py::arg("n1"), py::arg("n2"), py::arg("n3"), py::arg("n12"), py::arg("n23"), py::arg("n31"), py::arg("force3d"));
	cls_SMESH_MesherHelper.def("GetMediumPos", [](SMESH_MesherHelper &self, const SMDS_MeshNode * a0, const SMDS_MeshNode * a1) -> std::pair<int, TopAbs_ShapeEnum> { return self.GetMediumPos(a0, a1); }, py::arg("n1"), py::arg("n2"));
	cls_SMESH_MesherHelper.def("GetMediumPos", [](SMESH_MesherHelper &self, const SMDS_MeshNode * a0, const SMDS_MeshNode * a1, const bool a2) -> std::pair<int, TopAbs_ShapeEnum> { return self.GetMediumPos(a0, a1, a2); }, py::arg("n1"), py::arg("n2"), py::arg("useCurSubShape"));
	cls_SMESH_MesherHelper.def("GetMediumPos", (std::pair<int, TopAbs_ShapeEnum> (SMESH_MesherHelper::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const bool, TopAbs_ShapeEnum)) &SMESH_MesherHelper::GetMediumPos, "Return index and type of the shape (EDGE or FACE only) to set a medium node on", py::arg("n1"), py::arg("n2"), py::arg("useCurSubShape"), py::arg("expectedSupport"));
	cls_SMESH_MesherHelper.def("AddTLinkNode", (void (SMESH_MesherHelper::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMESH_MesherHelper::AddTLinkNode, "Add a link in my data structure", py::arg("n1"), py::arg("n2"), py::arg("n12"));
	cls_SMESH_MesherHelper.def("AddTLinkNodeMap", (void (SMESH_MesherHelper::*)(const TLinkNodeMap &)) &SMESH_MesherHelper::AddTLinkNodeMap, "Add many links in my data structure", py::arg("aMap"));
	cls_SMESH_MesherHelper.def("AddTLinks", (bool (SMESH_MesherHelper::*)(const SMDS_MeshEdge *)) &SMESH_MesherHelper::AddTLinks, "None", py::arg("edge"));
	cls_SMESH_MesherHelper.def("AddTLinks", (bool (SMESH_MesherHelper::*)(const SMDS_MeshFace *)) &SMESH_MesherHelper::AddTLinks, "None", py::arg("face"));
	cls_SMESH_MesherHelper.def("AddTLinks", (bool (SMESH_MesherHelper::*)(const SMDS_MeshVolume *)) &SMESH_MesherHelper::AddTLinks, "None", py::arg("vol"));
	cls_SMESH_MesherHelper.def("GetTLinkNodeMap", (const TLinkNodeMap & (SMESH_MesherHelper::*)() const ) &SMESH_MesherHelper::GetTLinkNodeMap, "Returns myTLinkNodeMap");
	cls_SMESH_MesherHelper.def("IsQuadraticMesh", (SMESH_MesherHelper::MType (SMESH_MesherHelper::*)()) &SMESH_MesherHelper::IsQuadraticMesh, "None");
	cls_SMESH_MesherHelper.def_static("WriteShape_", (void (*)(const TopoDS_Shape &)) &SMESH_MesherHelper::WriteShape, "None", py::arg("s"));
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_MesherHelper.hxx
	py::enum_<SMESH_MesherHelper::MType>(cls_SMESH_MesherHelper, "MType", "Check mesh without geometry for: if all elements on this shape are quadratic, quadratic elements will be created. Used then generated 3D mesh without geometry.")
		.value("LINEAR", SMESH_MesherHelper::MType::LINEAR)
		.value("QUADRATIC", SMESH_MesherHelper::MType::QUADRATIC)
		.value("COMP", SMESH_MesherHelper::MType::COMP)
		.export_values();

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Comment.hxx
	py::class_<SMESH_Comment, std::unique_ptr<SMESH_Comment, Deleter<SMESH_Comment>>, std::string> cls_SMESH_Comment(mod, "SMESH_Comment", "Class to generate string from any type");
	cls_SMESH_Comment.def(py::init<>());
	cls_SMESH_Comment.def(py::init([] (const SMESH_Comment &other) {return new SMESH_Comment(other);}), "Copy constructor", py::arg("other"));
	cls_SMESH_Comment.def("assign", (SMESH_Comment & (SMESH_Comment::*)(const SMESH_Comment &)) &SMESH_Comment::operator=, py::is_operator(), "None", py::arg("c"));
	cls_SMESH_Comment.def("Stream", (std::ostream & (SMESH_Comment::*)()) &SMESH_Comment::Stream, "None");
	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_HypoFilter.hxx
	py::class_<SMESH_HypoPredicate, std::unique_ptr<SMESH_HypoPredicate, Deleter<SMESH_HypoPredicate>>> cls_SMESH_HypoPredicate(mod, "SMESH_HypoPredicate", "None");
	cls_SMESH_HypoPredicate.def("IsOk", (bool (SMESH_HypoPredicate::*)(const SMESH_Hypothesis *, const TopoDS_Shape &) const ) &SMESH_HypoPredicate::IsOk, "None", py::arg("aHyp"), py::arg("aShape"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_subMesh.hxx
	py::class_<SMESH_subMesh, std::unique_ptr<SMESH_subMesh, py::nodelete>> cls_SMESH_subMesh(mod, "SMESH_subMesh", "None");
	cls_SMESH_subMesh.def(py::init<int, SMESH_Mesh *, SMESHDS_Mesh *, const TopoDS_Shape &>(), py::arg("Id"), py::arg("father"), py::arg("meshDS"), py::arg("aSubShape"));
	cls_SMESH_subMesh.def("GetId", (int (SMESH_subMesh::*)() const ) &SMESH_subMesh::GetId, "None");
	cls_SMESH_subMesh.def("GetFather", (SMESH_Mesh * (SMESH_subMesh::*)()) &SMESH_subMesh::GetFather, "None");
	cls_SMESH_subMesh.def("GetSubMeshDS", (SMESHDS_SubMesh * (SMESH_subMesh::*)()) &SMESH_subMesh::GetSubMeshDS, "None");
	cls_SMESH_subMesh.def("GetSubMeshDS", (const SMESHDS_SubMesh * (SMESH_subMesh::*)() const ) &SMESH_subMesh::GetSubMeshDS, "None");
	cls_SMESH_subMesh.def("CreateSubMeshDS", (SMESHDS_SubMesh * (SMESH_subMesh::*)()) &SMESH_subMesh::CreateSubMeshDS, "None");
	cls_SMESH_subMesh.def("GetFirstToCompute", (SMESH_subMesh * (SMESH_subMesh::*)()) &SMESH_subMesh::GetFirstToCompute, "None");
	cls_SMESH_subMesh.def("GetAlgo", (SMESH_Algo * (SMESH_subMesh::*)() const ) &SMESH_subMesh::GetAlgo, "None");
	cls_SMESH_subMesh.def("DependsOn", (const std::map<int, SMESH_subMesh *> & (SMESH_subMesh::*)()) &SMESH_subMesh::DependsOn, "None");
	cls_SMESH_subMesh.def("DependsOn", (bool (SMESH_subMesh::*)(const SMESH_subMesh *) const ) &SMESH_subMesh::DependsOn, "None", py::arg("other"));
	cls_SMESH_subMesh.def("DependsOn", (bool (SMESH_subMesh::*)(const int) const ) &SMESH_subMesh::DependsOn, "None", py::arg("shapeID"));
	cls_SMESH_subMesh.def("getDependsOnIterator", [](SMESH_subMesh &self, const bool a0) -> SMESH_subMeshIteratorPtr { return self.getDependsOnIterator(a0); }, py::arg("includeSelf"));
	cls_SMESH_subMesh.def("getDependsOnIterator", (SMESH_subMeshIteratorPtr (SMESH_subMesh::*)(const bool, const bool) const ) &SMESH_subMesh::getDependsOnIterator, "Return iterator on the sub-meshes this one depends on. By default most simple sub-meshes go first.", py::arg("includeSelf"), py::arg("complexShapeFirst"));
	cls_SMESH_subMesh.def("GetAncestors", (const std::vector<SMESH_subMesh *> & (SMESH_subMesh::*)() const ) &SMESH_subMesh::GetAncestors, "None");
	cls_SMESH_subMesh.def("ClearAncestors", (void (SMESH_subMesh::*)()) &SMESH_subMesh::ClearAncestors, "None");
	cls_SMESH_subMesh.def("GetSubShape", (const TopoDS_Shape & (SMESH_subMesh::*)() const ) &SMESH_subMesh::GetSubShape, "None");
	cls_SMESH_subMesh.def("SetEventListener", (void (SMESH_subMesh::*)(EventListener *, EventListenerData *, SMESH_subMesh *)) &SMESH_subMesh::SetEventListener, "Sets an event listener and its data to a submesh", py::arg("listener"), py::arg("data"), py::arg("where"));
	cls_SMESH_subMesh.def("GetEventListenerData", [](SMESH_subMesh &self, EventListener * a0) -> EventListenerData * { return self.GetEventListenerData(a0); }, py::arg("listener"));
	cls_SMESH_subMesh.def("GetEventListenerData", (EventListenerData * (SMESH_subMesh::*)(EventListener *, const bool) const ) &SMESH_subMesh::GetEventListenerData, "Return an event listener data", py::arg("listener"), py::arg("myOwn"));
	cls_SMESH_subMesh.def("GetEventListenerData", [](SMESH_subMesh &self, const std::string & a0) -> EventListenerData * { return self.GetEventListenerData(a0); }, py::arg("listenerName"));
	cls_SMESH_subMesh.def("GetEventListenerData", (EventListenerData * (SMESH_subMesh::*)(const std::string &, const bool) const ) &SMESH_subMesh::GetEventListenerData, "Return an event listener data", py::arg("listenerName"), py::arg("myOwn"));
	cls_SMESH_subMesh.def("DeleteEventListener", (void (SMESH_subMesh::*)(EventListener *)) &SMESH_subMesh::DeleteEventListener, "Unregister the listener and delete it and it's data", py::arg("listener"));
	cls_SMESH_subMesh.def("AlgoStateEngine", (SMESH_Hypothesis::Hypothesis_Status (SMESH_subMesh::*)(SMESH_subMesh::algo_event, SMESH_Hypothesis *)) &SMESH_subMesh::AlgoStateEngine, "None", py::arg("event"), py::arg("anHyp"));
	cls_SMESH_subMesh.def("SubMeshesAlgoStateEngine", [](SMESH_subMesh &self, SMESH_subMesh::algo_event a0, SMESH_Hypothesis * a1) -> SMESH_Hypothesis::Hypothesis_Status { return self.SubMeshesAlgoStateEngine(a0, a1); }, py::arg("event"), py::arg("anHyp"));
	cls_SMESH_subMesh.def("SubMeshesAlgoStateEngine", (SMESH_Hypothesis::Hypothesis_Status (SMESH_subMesh::*)(SMESH_subMesh::algo_event, SMESH_Hypothesis *, bool)) &SMESH_subMesh::SubMeshesAlgoStateEngine, "None", py::arg("event"), py::arg("anHyp"), py::arg("exitOnFatal"));
	cls_SMESH_subMesh.def("GetAlgoState", (SMESH_subMesh::algo_state (SMESH_subMesh::*)() const ) &SMESH_subMesh::GetAlgoState, "None");
	cls_SMESH_subMesh.def("GetComputeState", (SMESH_subMesh::compute_state (SMESH_subMesh::*)() const ) &SMESH_subMesh::GetComputeState, "None");
	cls_SMESH_subMesh.def("GetComputeError", (SMESH_ComputeErrorPtr & (SMESH_subMesh::*)()) &SMESH_subMesh::GetComputeError, "None");
	cls_SMESH_subMesh.def("DumpAlgoState", (void (SMESH_subMesh::*)(bool)) &SMESH_subMesh::DumpAlgoState, "None", py::arg("isMain"));
	cls_SMESH_subMesh.def("ComputeStateEngine", (bool (SMESH_subMesh::*)(SMESH_subMesh::compute_event)) &SMESH_subMesh::ComputeStateEngine, "None", py::arg("event"));
	cls_SMESH_subMesh.def("ComputeSubMeshStateEngine", [](SMESH_subMesh &self, SMESH_subMesh::compute_event a0) -> void { return self.ComputeSubMeshStateEngine(a0); }, py::arg("event"));
	cls_SMESH_subMesh.def("ComputeSubMeshStateEngine", (void (SMESH_subMesh::*)(SMESH_subMesh::compute_event, const bool)) &SMESH_subMesh::ComputeSubMeshStateEngine, "None", py::arg("event"), py::arg("includeSelf"));
	cls_SMESH_subMesh.def("Evaluate", (bool (SMESH_subMesh::*)(MapShapeNbElems &)) &SMESH_subMesh::Evaluate, "None", py::arg("aResMap"));
	cls_SMESH_subMesh.def("IsConform", (bool (SMESH_subMesh::*)(const SMESH_Algo *)) &SMESH_subMesh::IsConform, "None", py::arg("theAlgo"));
	cls_SMESH_subMesh.def("CanAddHypothesis", (bool (SMESH_subMesh::*)(const SMESH_Hypothesis *) const ) &SMESH_subMesh::CanAddHypothesis, "None", py::arg("theHypothesis"));
	cls_SMESH_subMesh.def_static("IsApplicableHypotesis_", (bool (*)(const SMESH_Hypothesis *, const TopAbs_ShapeEnum)) &SMESH_subMesh::IsApplicableHypotesis, "None", py::arg("theHypothesis"), py::arg("theShapeType"));
	cls_SMESH_subMesh.def("IsApplicableHypotesis", (bool (SMESH_subMesh::*)(const SMESH_Hypothesis *) const ) &SMESH_subMesh::IsApplicableHypotesis, "None", py::arg("theHypothesis"));
	cls_SMESH_subMesh.def("CheckConcurentHypothesis", (SMESH_Hypothesis::Hypothesis_Status (SMESH_subMesh::*)(const int)) &SMESH_subMesh::CheckConcurentHypothesis, "None", py::arg("theHypType"));
	cls_SMESH_subMesh.def("IsEmpty", (bool (SMESH_subMesh::*)() const ) &SMESH_subMesh::IsEmpty, "Return true if no mesh entities is bound to the submesh");
	cls_SMESH_subMesh.def("IsMeshComputed", (bool (SMESH_subMesh::*)() const ) &SMESH_subMesh::IsMeshComputed, "None");
	cls_SMESH_subMesh.def("SetIsAlwaysComputed", (void (SMESH_subMesh::*)(bool)) &SMESH_subMesh::SetIsAlwaysComputed, "Allow algo->Compute() if a subshape of lower dim is meshed but none mesh entity is bound to it", py::arg("isAlCo"));
	cls_SMESH_subMesh.def("IsAlwaysComputed", (bool (SMESH_subMesh::*)()) &SMESH_subMesh::IsAlwaysComputed, "None");
	cls_SMESH_subMesh.def("SubMeshesComputed", [](SMESH_subMesh &self) -> bool { return self.SubMeshesComputed(); });
	cls_SMESH_subMesh.def("SubMeshesComputed", (bool (SMESH_subMesh::*)(bool *) const ) &SMESH_subMesh::SubMeshesComputed, "None", py::arg("isFailedToCompute"));
	cls_SMESH_subMesh.def("GetComputeCost", (int (SMESH_subMesh::*)() const ) &SMESH_subMesh::GetComputeCost, "None");
	cls_SMESH_subMesh.def("FindIntersection", (bool (SMESH_subMesh::*)(const SMESH_subMesh *, std::set<const SMESH_subMesh *> &) const ) &SMESH_subMesh::FindIntersection, "Find common submeshes (based on shared subshapes with other", py::arg("theOther"), py::arg("theSetOfCommon"));
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_subMesh.hxx
	py::enum_<SMESH_subMesh::compute_state>(cls_SMESH_subMesh, "compute_state", "None")
		.value("NOT_READY", SMESH_subMesh::compute_state::NOT_READY)
		.value("READY_TO_COMPUTE", SMESH_subMesh::compute_state::READY_TO_COMPUTE)
		.value("COMPUTE_OK", SMESH_subMesh::compute_state::COMPUTE_OK)
		.value("FAILED_TO_COMPUTE", SMESH_subMesh::compute_state::FAILED_TO_COMPUTE)
		.export_values();
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_subMesh.hxx
	py::enum_<SMESH_subMesh::algo_state>(cls_SMESH_subMesh, "algo_state", "None")
		.value("NO_ALGO", SMESH_subMesh::algo_state::NO_ALGO)
		.value("MISSING_HYP", SMESH_subMesh::algo_state::MISSING_HYP)
		.value("HYP_OK", SMESH_subMesh::algo_state::HYP_OK)
		.export_values();
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_subMesh.hxx
	py::enum_<SMESH_subMesh::algo_event>(cls_SMESH_subMesh, "algo_event", "None")
		.value("ADD_HYP", SMESH_subMesh::algo_event::ADD_HYP)
		.value("ADD_ALGO", SMESH_subMesh::algo_event::ADD_ALGO)
		.value("REMOVE_HYP", SMESH_subMesh::algo_event::REMOVE_HYP)
		.value("REMOVE_ALGO", SMESH_subMesh::algo_event::REMOVE_ALGO)
		.value("ADD_FATHER_HYP", SMESH_subMesh::algo_event::ADD_FATHER_HYP)
		.value("ADD_FATHER_ALGO", SMESH_subMesh::algo_event::ADD_FATHER_ALGO)
		.value("REMOVE_FATHER_HYP", SMESH_subMesh::algo_event::REMOVE_FATHER_HYP)
		.value("REMOVE_FATHER_ALGO", SMESH_subMesh::algo_event::REMOVE_FATHER_ALGO)
		.value("MODIF_HYP", SMESH_subMesh::algo_event::MODIF_HYP)
		.export_values();
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_subMesh.hxx
	py::enum_<SMESH_subMesh::compute_event>(cls_SMESH_subMesh, "compute_event", "None")
		.value("MODIF_ALGO_STATE", SMESH_subMesh::compute_event::MODIF_ALGO_STATE)
		.value("COMPUTE", SMESH_subMesh::compute_event::COMPUTE)
		.value("COMPUTE_SUBMESH", SMESH_subMesh::compute_event::COMPUTE_SUBMESH)
		.value("COMPUTE_NOGEOM", SMESH_subMesh::compute_event::COMPUTE_NOGEOM)
		.value("COMPUTE_CANCELED", SMESH_subMesh::compute_event::COMPUTE_CANCELED)
		.value("CLEAN", SMESH_subMesh::compute_event::CLEAN)
		.value("SUBMESH_COMPUTED", SMESH_subMesh::compute_event::SUBMESH_COMPUTED)
		.value("SUBMESH_RESTORED", SMESH_subMesh::compute_event::SUBMESH_RESTORED)
		.value("SUBMESH_LOADED", SMESH_subMesh::compute_event::SUBMESH_LOADED)
		.value("MESH_ENTITY_REMOVED", SMESH_subMesh::compute_event::MESH_ENTITY_REMOVED)
		.value("CHECK_COMPUTE_STATE", SMESH_subMesh::compute_event::CHECK_COMPUTE_STATE)
		.export_values();
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_subMesh.hxx
	py::enum_<SMESH_subMesh::event_type>(cls_SMESH_subMesh, "event_type", "None")
		.value("ALGO_EVENT", SMESH_subMesh::event_type::ALGO_EVENT)
		.value("COMPUTE_EVENT", SMESH_subMesh::event_type::COMPUTE_EVENT)
		.export_values();

	// Callback for SMESH_0D_Algo.
	class PyCallback_SMESH_0D_Algo : public SMESH_0D_Algo {
	public:
		using SMESH_0D_Algo::SMESH_0D_Algo;

		bool CheckHypothesis(SMESH_Mesh & aMesh, const TopoDS_Shape & aShape, SMESH_Hypothesis::Hypothesis_Status & aStatus) override { PYBIND11_OVERLOAD_PURE(bool, SMESH_0D_Algo, CheckHypothesis, aMesh, aShape, aStatus); }
		bool Compute(SMESH_Mesh & aMesh, const TopoDS_Shape & aShape) override { PYBIND11_OVERLOAD_PURE(bool, SMESH_0D_Algo, Compute, aMesh, aShape); }
		bool Evaluate(SMESH_Mesh & aMesh, const TopoDS_Shape & aShape, MapShapeNbElems & aResMap) override { PYBIND11_OVERLOAD_PURE(bool, SMESH_0D_Algo, Evaluate, aMesh, aShape, aResMap); }
	};

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Algo.hxx
	py::class_<SMESH_0D_Algo, std::unique_ptr<SMESH_0D_Algo, py::nodelete>, PyCallback_SMESH_0D_Algo, SMESH_Algo> cls_SMESH_0D_Algo(mod, "SMESH_0D_Algo", "None");
	cls_SMESH_0D_Algo.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));

	// Callback for SMESH_1D_Algo.
	class PyCallback_SMESH_1D_Algo : public SMESH_1D_Algo {
	public:
		using SMESH_1D_Algo::SMESH_1D_Algo;

		bool CheckHypothesis(SMESH_Mesh & aMesh, const TopoDS_Shape & aShape, SMESH_Hypothesis::Hypothesis_Status & aStatus) override { PYBIND11_OVERLOAD_PURE(bool, SMESH_1D_Algo, CheckHypothesis, aMesh, aShape, aStatus); }
		bool Compute(SMESH_Mesh & aMesh, const TopoDS_Shape & aShape) override { PYBIND11_OVERLOAD_PURE(bool, SMESH_1D_Algo, Compute, aMesh, aShape); }
		bool Evaluate(SMESH_Mesh & aMesh, const TopoDS_Shape & aShape, MapShapeNbElems & aResMap) override { PYBIND11_OVERLOAD_PURE(bool, SMESH_1D_Algo, Evaluate, aMesh, aShape, aResMap); }
	};

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Algo.hxx
	py::class_<SMESH_1D_Algo, std::unique_ptr<SMESH_1D_Algo, py::nodelete>, PyCallback_SMESH_1D_Algo, SMESH_Algo> cls_SMESH_1D_Algo(mod, "SMESH_1D_Algo", "None");
	cls_SMESH_1D_Algo.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));

	// Callback for SMESH_2D_Algo.
	class PyCallback_SMESH_2D_Algo : public SMESH_2D_Algo {
	public:
		using SMESH_2D_Algo::SMESH_2D_Algo;

		bool CheckHypothesis(SMESH_Mesh & aMesh, const TopoDS_Shape & aShape, SMESH_Hypothesis::Hypothesis_Status & aStatus) override { PYBIND11_OVERLOAD_PURE(bool, SMESH_2D_Algo, CheckHypothesis, aMesh, aShape, aStatus); }
		bool Compute(SMESH_Mesh & aMesh, const TopoDS_Shape & aShape) override { PYBIND11_OVERLOAD_PURE(bool, SMESH_2D_Algo, Compute, aMesh, aShape); }
		bool Evaluate(SMESH_Mesh & aMesh, const TopoDS_Shape & aShape, MapShapeNbElems & aResMap) override { PYBIND11_OVERLOAD_PURE(bool, SMESH_2D_Algo, Evaluate, aMesh, aShape, aResMap); }
	};

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Algo.hxx
	py::class_<SMESH_2D_Algo, std::unique_ptr<SMESH_2D_Algo, py::nodelete>, PyCallback_SMESH_2D_Algo, SMESH_Algo> cls_SMESH_2D_Algo(mod, "SMESH_2D_Algo", "None");
	cls_SMESH_2D_Algo.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));
	cls_SMESH_2D_Algo.def("FixInternalNodes", (bool (SMESH_2D_Algo::*)(const SMESH_ProxyMesh &, const TopoDS_Face &)) &SMESH_2D_Algo::FixInternalNodes, "Method in which an algorithm generating a structured mesh fixes positions of in-face nodes after there movement due to insertion of viscous layers.", py::arg("mesh"), py::arg("face"));

	// Callback for SMESH_3D_Algo.
	class PyCallback_SMESH_3D_Algo : public SMESH_3D_Algo {
	public:
		using SMESH_3D_Algo::SMESH_3D_Algo;

		bool CheckHypothesis(SMESH_Mesh & aMesh, const TopoDS_Shape & aShape, SMESH_Hypothesis::Hypothesis_Status & aStatus) override { PYBIND11_OVERLOAD_PURE(bool, SMESH_3D_Algo, CheckHypothesis, aMesh, aShape, aStatus); }
		bool Compute(SMESH_Mesh & aMesh, const TopoDS_Shape & aShape) override { PYBIND11_OVERLOAD_PURE(bool, SMESH_3D_Algo, Compute, aMesh, aShape); }
		bool Evaluate(SMESH_Mesh & aMesh, const TopoDS_Shape & aShape, MapShapeNbElems & aResMap) override { PYBIND11_OVERLOAD_PURE(bool, SMESH_3D_Algo, Evaluate, aMesh, aShape, aResMap); }
	};

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Algo.hxx
	py::class_<SMESH_3D_Algo, std::unique_ptr<SMESH_3D_Algo, py::nodelete>, PyCallback_SMESH_3D_Algo, SMESH_Algo> cls_SMESH_3D_Algo(mod, "SMESH_3D_Algo", "None");
	cls_SMESH_3D_Algo.def(py::init<int, int, SMESH_Gen *>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Group.hxx
	py::class_<SMESH_Group, std::unique_ptr<SMESH_Group, py::nodelete>> cls_SMESH_Group(mod, "SMESH_Group", "None");
	cls_SMESH_Group.def(py::init<int, const SMESH_Mesh *, const SMDSAbs_ElementType, const char *>(), py::arg("theID"), py::arg("theMesh"), py::arg("theType"), py::arg("theName"));
	cls_SMESH_Group.def(py::init<int, const SMESH_Mesh *, const SMDSAbs_ElementType, const char *, const TopoDS_Shape &>(), py::arg("theID"), py::arg("theMesh"), py::arg("theType"), py::arg("theName"), py::arg("theShape"));
	cls_SMESH_Group.def(py::init<int, const SMESH_Mesh *, const SMDSAbs_ElementType, const char *, const TopoDS_Shape &, const SMESH_PredicatePtr &>(), py::arg("theID"), py::arg("theMesh"), py::arg("theType"), py::arg("theName"), py::arg("theShape"), py::arg("thePredicate"));
	cls_SMESH_Group.def(py::init<SMESHDS_GroupBase *>(), py::arg("groupDS"));
	cls_SMESH_Group.def("SetName", (void (SMESH_Group::*)(const char *)) &SMESH_Group::SetName, "None", py::arg("theName"));
	cls_SMESH_Group.def("GetName", (const char * (SMESH_Group::*)() const ) &SMESH_Group::GetName, "None");
	cls_SMESH_Group.def("GetGroupDS", (SMESHDS_GroupBase * (SMESH_Group::*)()) &SMESH_Group::GetGroupDS, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Block.hxx
	py::class_<SMESH_Block, std::unique_ptr<SMESH_Block, Deleter<SMESH_Block>>, math_FunctionSetWithDerivatives> cls_SMESH_Block(mod, "SMESH_Block", "None");
	cls_SMESH_Block.def(py::init<>());
	cls_SMESH_Block.def_static("NbVertices_", (int (*)()) &SMESH_Block::NbVertices, "None");
	cls_SMESH_Block.def_static("NbEdges_", (int (*)()) &SMESH_Block::NbEdges, "None");
	cls_SMESH_Block.def_static("NbFaces_", (int (*)()) &SMESH_Block::NbFaces, "None");
	cls_SMESH_Block.def_static("NbSubShapes_", (int (*)()) &SMESH_Block::NbSubShapes, "None");
	cls_SMESH_Block.def_static("IsVertexID_", (bool (*)(int)) &SMESH_Block::IsVertexID, "None", py::arg("theShapeID"));
	cls_SMESH_Block.def_static("IsEdgeID_", (bool (*)(int)) &SMESH_Block::IsEdgeID, "None", py::arg("theShapeID"));
	cls_SMESH_Block.def_static("IsFaceID_", (bool (*)(int)) &SMESH_Block::IsFaceID, "None", py::arg("theShapeID"));
	cls_SMESH_Block.def_static("ShapeIndex_", (int (*)(int)) &SMESH_Block::ShapeIndex, "None", py::arg("theShapeID"));
	cls_SMESH_Block.def_static("GetFaceEdgesIDs_", (void (*)(const int, std::vector<int> &)) &SMESH_Block::GetFaceEdgesIDs, "None", py::arg("faceID"), py::arg("edgeVec"));
	cls_SMESH_Block.def_static("GetEdgeVertexIDs_", (void (*)(const int, std::vector<int> &)) &SMESH_Block::GetEdgeVertexIDs, "None", py::arg("edgeID"), py::arg("vertexVec"));
	cls_SMESH_Block.def_static("GetCoordIndOnEdge_", (int (*)(const int)) &SMESH_Block::GetCoordIndOnEdge, "None", py::arg("theEdgeID"));
	cls_SMESH_Block.def_static("GetShapeCoef_", (double * (*)(const int)) &SMESH_Block::GetShapeCoef, "None", py::arg("theShapeID"));
	cls_SMESH_Block.def_static("GetShapeIDByParams_", (int (*)(const gp_XYZ &)) &SMESH_Block::GetShapeIDByParams, "None", py::arg("theParams"));
	cls_SMESH_Block.def_static("DumpShapeID_", (std::ostream & (*)(const int, std::ostream &)) &SMESH_Block::DumpShapeID, "None", py::arg("theBlockShapeID"), py::arg("stream"));
	cls_SMESH_Block.def("LoadBlockShapes", (bool (SMESH_Block::*)(const TopoDS_Shell &, const TopoDS_Vertex &, const TopoDS_Vertex &, TopTools_IndexedMapOfOrientedShape &)) &SMESH_Block::LoadBlockShapes, "None", py::arg("theShell"), py::arg("theVertex000"), py::arg("theVertex001"), py::arg("theShapeIDMap"));
	cls_SMESH_Block.def("LoadBlockShapes", (bool (SMESH_Block::*)(const TopTools_IndexedMapOfOrientedShape &)) &SMESH_Block::LoadBlockShapes, "None", py::arg("theShapeIDMap"));
	cls_SMESH_Block.def("LoadMeshBlock", (bool (SMESH_Block::*)(const SMDS_MeshVolume *, const int, const int, std::vector<const SMDS_MeshNode *> &)) &SMESH_Block::LoadMeshBlock, "None", py::arg("theVolume"), py::arg("theNode000Index"), py::arg("theNode001Index"), py::arg("theOrderedNodes"));
	cls_SMESH_Block.def("LoadFace", (bool (SMESH_Block::*)(const TopoDS_Face &, const int, const TopTools_IndexedMapOfOrientedShape &)) &SMESH_Block::LoadFace, "None", py::arg("theFace"), py::arg("theFaceID"), py::arg("theShapeIDMap"));
	cls_SMESH_Block.def_static("Insert_", (bool (*)(const TopoDS_Shape &, const int, TopTools_IndexedMapOfOrientedShape &)) &SMESH_Block::Insert, "None", py::arg("theShape"), py::arg("theShapeID"), py::arg("theShapeIDMap"));
	cls_SMESH_Block.def_static("FindBlockShapes_", (bool (*)(const TopoDS_Shell &, const TopoDS_Vertex &, const TopoDS_Vertex &, TopTools_IndexedMapOfOrientedShape &)) &SMESH_Block::FindBlockShapes, "None", py::arg("theShell"), py::arg("theVertex000"), py::arg("theVertex001"), py::arg("theShapeIDMap"));
	cls_SMESH_Block.def("VertexPoint", (bool (SMESH_Block::*)(const int, gp_XYZ &) const ) &SMESH_Block::VertexPoint, "None", py::arg("theVertexID"), py::arg("thePoint"));
	cls_SMESH_Block.def("EdgePoint", (bool (SMESH_Block::*)(const int, const gp_XYZ &, gp_XYZ &) const ) &SMESH_Block::EdgePoint, "None", py::arg("theEdgeID"), py::arg("theParams"), py::arg("thePoint"));
	cls_SMESH_Block.def("EdgeU", (bool (SMESH_Block::*)(const int, const gp_XYZ &, double &) const ) &SMESH_Block::EdgeU, "None", py::arg("theEdgeID"), py::arg("theParams"), py::arg("theU"));
	cls_SMESH_Block.def("FacePoint", (bool (SMESH_Block::*)(const int, const gp_XYZ &, gp_XYZ &) const ) &SMESH_Block::FacePoint, "None", py::arg("theFaceID"), py::arg("theParams"), py::arg("thePoint"));
	cls_SMESH_Block.def("FaceUV", (bool (SMESH_Block::*)(const int, const gp_XYZ &, gp_XY &) const ) &SMESH_Block::FaceUV, "None", py::arg("theFaceID"), py::arg("theParams"), py::arg("theUV"));
	cls_SMESH_Block.def("ShellPoint", (bool (SMESH_Block::*)(const gp_XYZ &, gp_XYZ &) const ) &SMESH_Block::ShellPoint, "None", py::arg("theParams"), py::arg("thePoint"));
	cls_SMESH_Block.def_static("ShellPoint_", (bool (*)(const gp_XYZ &, const std::vector<gp_XYZ> &, gp_XYZ &)) &SMESH_Block::ShellPoint, "None", py::arg("theParams"), py::arg("thePointOnShape"), py::arg("thePoint"));
	cls_SMESH_Block.def("ComputeParameters", [](SMESH_Block &self, const gp_Pnt & a0, gp_XYZ & a1) -> bool { return self.ComputeParameters(a0, a1); }, py::arg("thePoint"), py::arg("theParams"));
	cls_SMESH_Block.def("ComputeParameters", [](SMESH_Block &self, const gp_Pnt & a0, gp_XYZ & a1, const int a2) -> bool { return self.ComputeParameters(a0, a1, a2); }, py::arg("thePoint"), py::arg("theParams"), py::arg("theShapeID"));
	cls_SMESH_Block.def("ComputeParameters", (bool (SMESH_Block::*)(const gp_Pnt &, gp_XYZ &, const int, const gp_XYZ &)) &SMESH_Block::ComputeParameters, "None", py::arg("thePoint"), py::arg("theParams"), py::arg("theShapeID"), py::arg("theParamsHint"));
	cls_SMESH_Block.def("VertexParameters", (bool (SMESH_Block::*)(const int, gp_XYZ &)) &SMESH_Block::VertexParameters, "None", py::arg("theVertexID"), py::arg("theParams"));
	cls_SMESH_Block.def("EdgeParameters", (bool (SMESH_Block::*)(const int, const double, gp_XYZ &)) &SMESH_Block::EdgeParameters, "None", py::arg("theEdgeID"), py::arg("theU"), py::arg("theParams"));
	cls_SMESH_Block.def("SetTolerance", (void (SMESH_Block::*)(const double)) &SMESH_Block::SetTolerance, "None", py::arg("tol"));
	cls_SMESH_Block.def("GetTolerance", (double (SMESH_Block::*)() const ) &SMESH_Block::GetTolerance, "None");
	cls_SMESH_Block.def("IsToleranceReached", (bool (SMESH_Block::*)() const ) &SMESH_Block::IsToleranceReached, "None");
	cls_SMESH_Block.def("DistanceReached", (double (SMESH_Block::*)() const ) &SMESH_Block::DistanceReached, "None");
	cls_SMESH_Block.def_static("IsForwardEdge_", (bool (*)(const TopoDS_Edge &, const TopTools_IndexedMapOfOrientedShape &)) &SMESH_Block::IsForwardEdge, "None", py::arg("theEdge"), py::arg("theShapeIDMap"));
	cls_SMESH_Block.def_static("GetOrderedEdges_", [](const TopoDS_Face & a0, std::list<TopoDS_Edge> & a1, std::list<int> & a2) -> int { return SMESH_Block::GetOrderedEdges(a0, a1, a2); }, py::arg("theFace"), py::arg("theEdges"), py::arg("theNbEdgesInWires"));
	cls_SMESH_Block.def_static("GetOrderedEdges_", [](const TopoDS_Face & a0, std::list<TopoDS_Edge> & a1, std::list<int> & a2, TopoDS_Vertex a3) -> int { return SMESH_Block::GetOrderedEdges(a0, a1, a2, a3); }, py::arg("theFace"), py::arg("theEdges"), py::arg("theNbEdgesInWires"), py::arg("theFirstVertex"));
	cls_SMESH_Block.def_static("GetOrderedEdges_", (int (*)(const TopoDS_Face &, std::list<TopoDS_Edge> &, std::list<int> &, TopoDS_Vertex, const bool)) &SMESH_Block::GetOrderedEdges, "None", py::arg("theFace"), py::arg("theEdges"), py::arg("theNbEdgesInWires"), py::arg("theFirstVertex"), py::arg("theShapeAnalysisAlgo"));
	cls_SMESH_Block.def("NbVariables", (Standard_Integer (SMESH_Block::*)() const ) &SMESH_Block::NbVariables, "None");
	cls_SMESH_Block.def("NbEquations", (Standard_Integer (SMESH_Block::*)() const ) &SMESH_Block::NbEquations, "None");
	cls_SMESH_Block.def("Value", (Standard_Boolean (SMESH_Block::*)(const math_Vector &, math_Vector &)) &SMESH_Block::Value, "None", py::arg("X"), py::arg("F"));
	cls_SMESH_Block.def("Derivatives", (Standard_Boolean (SMESH_Block::*)(const math_Vector &, math_Matrix &)) &SMESH_Block::Derivatives, "None", py::arg("X"), py::arg("D"));
	cls_SMESH_Block.def("Values", (Standard_Boolean (SMESH_Block::*)(const math_Vector &, math_Vector &, math_Matrix &)) &SMESH_Block::Values, "None", py::arg("X"), py::arg("F"), py::arg("D"));
	cls_SMESH_Block.def("GetStateNumber", (Standard_Integer (SMESH_Block::*)()) &SMESH_Block::GetStateNumber, "None");
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Block.hxx
	py::enum_<SMESH_Block::TShapeID>(cls_SMESH_Block, "TShapeID", "None")
		.value("ID_NONE", SMESH_Block::TShapeID::ID_NONE)
		.value("ID_V000", SMESH_Block::TShapeID::ID_V000)
		.value("ID_V100", SMESH_Block::TShapeID::ID_V100)
		.value("ID_V010", SMESH_Block::TShapeID::ID_V010)
		.value("ID_V110", SMESH_Block::TShapeID::ID_V110)
		.value("ID_V001", SMESH_Block::TShapeID::ID_V001)
		.value("ID_V101", SMESH_Block::TShapeID::ID_V101)
		.value("ID_V011", SMESH_Block::TShapeID::ID_V011)
		.value("ID_V111", SMESH_Block::TShapeID::ID_V111)
		.value("ID_Ex00", SMESH_Block::TShapeID::ID_Ex00)
		.value("ID_Ex10", SMESH_Block::TShapeID::ID_Ex10)
		.value("ID_Ex01", SMESH_Block::TShapeID::ID_Ex01)
		.value("ID_Ex11", SMESH_Block::TShapeID::ID_Ex11)
		.value("ID_E0y0", SMESH_Block::TShapeID::ID_E0y0)
		.value("ID_E1y0", SMESH_Block::TShapeID::ID_E1y0)
		.value("ID_E0y1", SMESH_Block::TShapeID::ID_E0y1)
		.value("ID_E1y1", SMESH_Block::TShapeID::ID_E1y1)
		.value("ID_E00z", SMESH_Block::TShapeID::ID_E00z)
		.value("ID_E10z", SMESH_Block::TShapeID::ID_E10z)
		.value("ID_E01z", SMESH_Block::TShapeID::ID_E01z)
		.value("ID_E11z", SMESH_Block::TShapeID::ID_E11z)
		.value("ID_Fxy0", SMESH_Block::TShapeID::ID_Fxy0)
		.value("ID_Fxy1", SMESH_Block::TShapeID::ID_Fxy1)
		.value("ID_Fx0z", SMESH_Block::TShapeID::ID_Fx0z)
		.value("ID_Fx1z", SMESH_Block::TShapeID::ID_Fx1z)
		.value("ID_F0yz", SMESH_Block::TShapeID::ID_F0yz)
		.value("ID_F1yz", SMESH_Block::TShapeID::ID_F1yz)
		.value("ID_Shell", SMESH_Block::TShapeID::ID_Shell)
		.value("ID_FirstV", SMESH_Block::TShapeID::ID_FirstV)
		.value("ID_FirstE", SMESH_Block::TShapeID::ID_FirstE)
		.value("ID_FirstF", SMESH_Block::TShapeID::ID_FirstF)
		.export_values();

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Gen.hxx
	py::class_<studyContextStruct, std::unique_ptr<studyContextStruct, Deleter<studyContextStruct>>> cls_studyContextStruct(mod, "studyContextStruct", "None");
	cls_studyContextStruct.def(py::init<>());

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_HypoFilter.hxx
	py::class_<SMESH_HypoFilter, std::unique_ptr<SMESH_HypoFilter, Deleter<SMESH_HypoFilter>>, SMESH_HypoPredicate> cls_SMESH_HypoFilter(mod, "SMESH_HypoFilter", "None");
	cls_SMESH_HypoFilter.def(py::init<>());
	cls_SMESH_HypoFilter.def(py::init<SMESH_HypoPredicate *>(), py::arg("aPredicate"));
	cls_SMESH_HypoFilter.def(py::init<SMESH_HypoPredicate *, bool>(), py::arg("aPredicate"), py::arg("notNegate"));
	cls_SMESH_HypoFilter.def("Init", [](SMESH_HypoFilter &self, SMESH_HypoPredicate * a0) -> SMESH_HypoFilter & { return self.Init(a0); }, py::arg("aPredicate"));
	cls_SMESH_HypoFilter.def("Init", (SMESH_HypoFilter & (SMESH_HypoFilter::*)(SMESH_HypoPredicate *, bool)) &SMESH_HypoFilter::Init, "None", py::arg("aPredicate"), py::arg("notNegate"));
	cls_SMESH_HypoFilter.def("And", (SMESH_HypoFilter & (SMESH_HypoFilter::*)(SMESH_HypoPredicate *)) &SMESH_HypoFilter::And, "None", py::arg("aPredicate"));
	cls_SMESH_HypoFilter.def("AndNot", (SMESH_HypoFilter & (SMESH_HypoFilter::*)(SMESH_HypoPredicate *)) &SMESH_HypoFilter::AndNot, "None", py::arg("aPredicate"));
	cls_SMESH_HypoFilter.def("Or", (SMESH_HypoFilter & (SMESH_HypoFilter::*)(SMESH_HypoPredicate *)) &SMESH_HypoFilter::Or, "None", py::arg("aPredicate"));
	cls_SMESH_HypoFilter.def("OrNot", (SMESH_HypoFilter & (SMESH_HypoFilter::*)(SMESH_HypoPredicate *)) &SMESH_HypoFilter::OrNot, "None", py::arg("aPredicate"));
	cls_SMESH_HypoFilter.def_static("IsAlgo_", (SMESH_HypoPredicate * (*)()) &SMESH_HypoFilter::IsAlgo, "None");
	cls_SMESH_HypoFilter.def_static("IsAuxiliary_", (SMESH_HypoPredicate * (*)()) &SMESH_HypoFilter::IsAuxiliary, "None");
	cls_SMESH_HypoFilter.def_static("IsApplicableTo_", (SMESH_HypoPredicate * (*)(const TopoDS_Shape &)) &SMESH_HypoFilter::IsApplicableTo, "None", py::arg("theShape"));
	cls_SMESH_HypoFilter.def_static("IsAssignedTo_", (SMESH_HypoPredicate * (*)(const TopoDS_Shape &)) &SMESH_HypoFilter::IsAssignedTo, "None", py::arg("theShape"));
	cls_SMESH_HypoFilter.def_static("Is_", (SMESH_HypoPredicate * (*)(const SMESH_Hypothesis *)) &SMESH_HypoFilter::Is, "None", py::arg("theHypo"));
	cls_SMESH_HypoFilter.def_static("IsGlobal_", (SMESH_HypoPredicate * (*)(const TopoDS_Shape &)) &SMESH_HypoFilter::IsGlobal, "None", py::arg("theMainShape"));
	cls_SMESH_HypoFilter.def_static("IsMoreLocalThan_", (SMESH_HypoPredicate * (*)(const TopoDS_Shape &, const SMESH_Mesh &)) &SMESH_HypoFilter::IsMoreLocalThan, "None", py::arg("theShape"), py::arg("theMesh"));
	cls_SMESH_HypoFilter.def_static("HasName_", (SMESH_HypoPredicate * (*)(const std::string &)) &SMESH_HypoFilter::HasName, "None", py::arg("theName"));
	cls_SMESH_HypoFilter.def_static("HasDim_", (SMESH_HypoPredicate * (*)(const int)) &SMESH_HypoFilter::HasDim, "None", py::arg("theDim"));
	cls_SMESH_HypoFilter.def_static("HasType_", (SMESH_HypoPredicate * (*)(const int)) &SMESH_HypoFilter::HasType, "None", py::arg("theHypType"));
	cls_SMESH_HypoFilter.def("IsEmpty", (bool (SMESH_HypoFilter::*)() const ) &SMESH_HypoFilter::IsEmpty, "None");
	cls_SMESH_HypoFilter.def("IsOk", (bool (SMESH_HypoFilter::*)(const SMESH_Hypothesis *, const TopoDS_Shape &) const ) &SMESH_HypoFilter::IsOk, "check aHyp or/and aShape it is assigned to", py::arg("aHyp"), py::arg("aShape"));
	cls_SMESH_HypoFilter.def("IsAny", (bool (SMESH_HypoFilter::*)() const ) &SMESH_HypoFilter::IsAny, "return true if contains no predicates");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_MeshAlgos.hxx
	py::class_<SMESH_NodeSearcher, std::unique_ptr<SMESH_NodeSearcher, Deleter<SMESH_NodeSearcher>>> cls_SMESH_NodeSearcher(mod, "SMESH_NodeSearcher", "Searcher for the node closest to a point");
	cls_SMESH_NodeSearcher.def("FindClosestTo", (const SMDS_MeshNode * (SMESH_NodeSearcher::*)(const gp_Pnt &)) &SMESH_NodeSearcher::FindClosestTo, "None", py::arg("pnt"));
	cls_SMESH_NodeSearcher.def("MoveNode", (void (SMESH_NodeSearcher::*)(const SMDS_MeshNode *, const gp_Pnt &)) &SMESH_NodeSearcher::MoveNode, "None", py::arg("node"), py::arg("toPnt"));
	cls_SMESH_NodeSearcher.def("FindNearPoint", (int (SMESH_NodeSearcher::*)(const gp_Pnt &, const double, std::vector<const SMDS_MeshNode *> &)) &SMESH_NodeSearcher::FindNearPoint, "None", py::arg("point"), py::arg("tolerance"), py::arg("foundNodes"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_MeshAlgos.hxx
	py::class_<SMESH_ElementSearcher, std::unique_ptr<SMESH_ElementSearcher, Deleter<SMESH_ElementSearcher>>> cls_SMESH_ElementSearcher(mod, "SMESH_ElementSearcher", "Searcher for elements");
	cls_SMESH_ElementSearcher.def("FindElementsByPoint", (int (SMESH_ElementSearcher::*)(const gp_Pnt &, SMDSAbs_ElementType, std::vector<const SMDS_MeshElement *> &)) &SMESH_ElementSearcher::FindElementsByPoint, "Find elements of given type where the given point is IN or ON. Returns nb of found elements and elements them-selves.", py::arg("point"), py::arg("type"), py::arg("foundElems"));
	cls_SMESH_ElementSearcher.def("FindClosestTo", (const SMDS_MeshElement * (SMESH_ElementSearcher::*)(const gp_Pnt &, SMDSAbs_ElementType)) &SMESH_ElementSearcher::FindClosestTo, "Return an element most close to the given point", py::arg("point"), py::arg("type"));
	cls_SMESH_ElementSearcher.def("GetElementsNearLine", (void (SMESH_ElementSearcher::*)(const gp_Ax1 &, SMDSAbs_ElementType, std::vector<const SMDS_MeshElement *> &)) &SMESH_ElementSearcher::GetElementsNearLine, "Return elements possibly intersecting the line", py::arg("line"), py::arg("type"), py::arg("foundElems"));
	cls_SMESH_ElementSearcher.def("GetElementsInSphere", (void (SMESH_ElementSearcher::*)(const gp_XYZ &, const double, SMDSAbs_ElementType, std::vector<const SMDS_MeshElement *> &)) &SMESH_ElementSearcher::GetElementsInSphere, "Return elements whose bounding box intersects a sphere", py::arg("center"), py::arg("radius"), py::arg("type"), py::arg("foundElems"));
	cls_SMESH_ElementSearcher.def("GetPointState", (TopAbs_State (SMESH_ElementSearcher::*)(const gp_Pnt &)) &SMESH_ElementSearcher::GetPointState, "Find out if the given point is out of closed 2D mesh.", py::arg("point"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_MeshEditor.hxx
	py::class_<SMESH_MeshEditor, std::unique_ptr<SMESH_MeshEditor, Deleter<SMESH_MeshEditor>>> cls_SMESH_MeshEditor(mod, "SMESH_MeshEditor", "Editor of a mesh");
	cls_SMESH_MeshEditor.def(py::init<SMESH_Mesh *>(), py::arg("theMesh"));
	cls_SMESH_MeshEditor.def("GetMesh", (SMESH_Mesh * (SMESH_MeshEditor::*)()) &SMESH_MeshEditor::GetMesh, "None");
	cls_SMESH_MeshEditor.def("GetMeshDS", (SMESHDS_Mesh * (SMESH_MeshEditor::*)()) &SMESH_MeshEditor::GetMeshDS, "None");
	cls_SMESH_MeshEditor.def("GetLastCreatedNodes", (const SMESH_SequenceOfElemPtr & (SMESH_MeshEditor::*)() const ) &SMESH_MeshEditor::GetLastCreatedNodes, "None");
	cls_SMESH_MeshEditor.def("GetLastCreatedElems", (const SMESH_SequenceOfElemPtr & (SMESH_MeshEditor::*)() const ) &SMESH_MeshEditor::GetLastCreatedElems, "None");
	cls_SMESH_MeshEditor.def("ClearLastCreated", (void (SMESH_MeshEditor::*)()) &SMESH_MeshEditor::ClearLastCreated, "None");
	cls_SMESH_MeshEditor.def("GetError", (SMESH_ComputeErrorPtr & (SMESH_MeshEditor::*)()) &SMESH_MeshEditor::GetError, "None");
	cls_SMESH_MeshEditor.def("AddElement", (SMDS_MeshElement * (SMESH_MeshEditor::*)(const std::vector<const SMDS_MeshNode *> &, const SMESH_MeshEditor::ElemFeatures &)) &SMESH_MeshEditor::AddElement, "Add element", py::arg("nodes"), py::arg("features"));
	cls_SMESH_MeshEditor.def("AddElement", (SMDS_MeshElement * (SMESH_MeshEditor::*)(const std::vector<int> &, const SMESH_MeshEditor::ElemFeatures &)) &SMESH_MeshEditor::AddElement, "Add element", py::arg("nodeIDs"), py::arg("features"));
	cls_SMESH_MeshEditor.def("Remove", (int (SMESH_MeshEditor::*)(const std::list<int> &, const bool)) &SMESH_MeshEditor::Remove, "None", py::arg("theElemIDs"), py::arg("isNodes"));
	cls_SMESH_MeshEditor.def("Create0DElementsOnAllNodes", (void (SMESH_MeshEditor::*)(const TIDSortedElemSet &, TIDSortedElemSet &, const bool)) &SMESH_MeshEditor::Create0DElementsOnAllNodes, "None", py::arg("elements"), py::arg("all0DElems"), py::arg("duplicateElements"));
	cls_SMESH_MeshEditor.def("InverseDiag", (bool (SMESH_MeshEditor::*)(const SMDS_MeshElement *, const SMDS_MeshElement *)) &SMESH_MeshEditor::InverseDiag, "None", py::arg("theTria1"), py::arg("theTria2"));
	cls_SMESH_MeshEditor.def("InverseDiag", (bool (SMESH_MeshEditor::*)(const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMESH_MeshEditor::InverseDiag, "None", py::arg("theNode1"), py::arg("theNode2"));
	cls_SMESH_MeshEditor.def("DeleteDiag", (bool (SMESH_MeshEditor::*)(const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMESH_MeshEditor::DeleteDiag, "None", py::arg("theNode1"), py::arg("theNode2"));
	cls_SMESH_MeshEditor.def("Reorient", (bool (SMESH_MeshEditor::*)(const SMDS_MeshElement *)) &SMESH_MeshEditor::Reorient, "None", py::arg("theElement"));
	cls_SMESH_MeshEditor.def("Reorient2D", (int (SMESH_MeshEditor::*)(TIDSortedElemSet &, const gp_Dir &, const SMDS_MeshElement *)) &SMESH_MeshEditor::Reorient2D, "None", py::arg("theFaces"), py::arg("theDirection"), py::arg("theFace"));
	cls_SMESH_MeshEditor.def("Reorient2DBy3D", (int (SMESH_MeshEditor::*)(TIDSortedElemSet &, TIDSortedElemSet &, const bool)) &SMESH_MeshEditor::Reorient2DBy3D, "None", py::arg("theFaces"), py::arg("theVolumes"), py::arg("theOutsideNormal"));
	// cls_SMESH_MeshEditor.def("TriToQuad", (bool (SMESH_MeshEditor::*)(TIDSortedElemSet &, SMESH::Controls::NumericalFunctorPtr, const double)) &SMESH_MeshEditor::TriToQuad, "Fuse neighbour triangles into quadrangles.", py::arg("theElems"), py::arg("theCriterion"), py::arg("theMaxAngle"));
	cls_SMESH_MeshEditor.def("TriToQuadAspectRatio", ([](SMESH_MeshEditor &self, TIDSortedElemSet &elms, const double angle) -> bool {SMESH::Controls::AspectRatio *f = new SMESH::Controls::AspectRatio; boost::shared_ptr<SMESH::Controls::AspectRatio> fptr(f); return self.TriToQuad(elms, fptr, angle); }), "Convert triangles into quadrangles using aspect ratio.", py::arg("theElems"), py::arg("theMaxAngle"));
	cls_SMESH_MeshEditor.def("TriToQuadMinimumAngle", ([](SMESH_MeshEditor &self, TIDSortedElemSet &elms, const double angle) -> bool {SMESH::Controls::MinimumAngle *f = new SMESH::Controls::MinimumAngle; boost::shared_ptr<SMESH::Controls::MinimumAngle> fptr(f); return self.TriToQuad(elms, fptr, angle); }), "Convert triangles into quadrangles using minimum angle.", py::arg("theElems"), py::arg("theMaxAngle"));
	cls_SMESH_MeshEditor.def("TriToQuadSkew", ([](SMESH_MeshEditor &self, TIDSortedElemSet &elms, const double angle) -> bool {SMESH::Controls::Skew *f = new SMESH::Controls::Skew; boost::shared_ptr<SMESH::Controls::Skew> fptr(f); return self.TriToQuad(elms, fptr, angle); }), "Convert triangles into quadrangles using skew.", py::arg("theElems"), py::arg("theMaxAngle"));
	cls_SMESH_MeshEditor.def("TriToQuadArea", ([](SMESH_MeshEditor &self, TIDSortedElemSet &elms, const double angle) -> bool {SMESH::Controls::Area *f = new SMESH::Controls::Area; boost::shared_ptr<SMESH::Controls::Area> fptr(f); return self.TriToQuad(elms, fptr, angle); }), "Convert triangles into quadrangles using area.", py::arg("theElems"), py::arg("theMaxAngle"));
	cls_SMESH_MeshEditor.def("TriToQuadWarping", ([](SMESH_MeshEditor &self, TIDSortedElemSet &elms, const double angle) -> bool {SMESH::Controls::Warping *f = new SMESH::Controls::Warping; boost::shared_ptr<SMESH::Controls::Warping> fptr(f); return self.TriToQuad(elms, fptr, angle); }), "Convert triangles into quadrangles using warping.", py::arg("theElems"), py::arg("theMaxAngle"));
	cls_SMESH_MeshEditor.def("TriToQuadTaper", ([](SMESH_MeshEditor &self, TIDSortedElemSet &elms, const double angle) -> bool {SMESH::Controls::Taper *f = new SMESH::Controls::Taper; boost::shared_ptr<SMESH::Controls::Taper> fptr(f); return self.TriToQuad(elms, fptr, angle); }), "Convert triangles into quadrangles using taper.", py::arg("theElems"), py::arg("theMaxAngle"));
	cls_SMESH_MeshEditor.def("QuadToTri", (bool (SMESH_MeshEditor::*)(TIDSortedElemSet &, SMESH::Controls::NumericalFunctorPtr)) &SMESH_MeshEditor::QuadToTri, "Split quadrangles into triangles.", py::arg("theElems"), py::arg("theCriterion"));
	cls_SMESH_MeshEditor.def("QuadToTri", (bool (SMESH_MeshEditor::*)(TIDSortedElemSet &, const bool)) &SMESH_MeshEditor::QuadToTri, "Split quadrangles into triangles.", py::arg("theElems"), py::arg("the13Diag"));
	cls_SMESH_MeshEditor.def("QuadTo4Tri", (void (SMESH_MeshEditor::*)(TIDSortedElemSet &)) &SMESH_MeshEditor::QuadTo4Tri, "Split each of given quadrangles into 4 triangles.", py::arg("theElems"));
	cls_SMESH_MeshEditor.def("BestSplit", (int (SMESH_MeshEditor::*)(const SMDS_MeshElement *, SMESH::Controls::NumericalFunctorPtr)) &SMESH_MeshEditor::BestSplit, "Find better diagonal for splitting.", py::arg("theQuad"), py::arg("theCriterion"));
	cls_SMESH_MeshEditor.def("SplitVolumes", (void (SMESH_MeshEditor::*)(const SMESH_MeshEditor::TFacetOfElem &, const int)) &SMESH_MeshEditor::SplitVolumes, "Split volumic elements into tetrahedra or prisms. If facet ID < 0, element is split into tetrahedra, else a hexahedron is split into prisms so that the given facet is split into triangles", py::arg("theElems"), py::arg("theMethodFlags"));
	cls_SMESH_MeshEditor.def("GetHexaFacetsToSplit", (void (SMESH_MeshEditor::*)(TIDSortedElemSet &, const gp_Ax1 &, SMESH_MeshEditor::TFacetOfElem &)) &SMESH_MeshEditor::GetHexaFacetsToSplit, "For hexahedra that will be split into prisms, finds facets to split into triangles", py::arg("theHexas"), py::arg("theFacetNormal"), py::arg("theFacets"));
	cls_SMESH_MeshEditor.def("SplitBiQuadraticIntoLinear", (void (SMESH_MeshEditor::*)(TIDSortedElemSet &)) &SMESH_MeshEditor::SplitBiQuadraticIntoLinear, "Split bi-quadratic elements into linear ones without creation of additional nodes - bi-quadratic triangle will be split into 3 linear quadrangles; - bi-quadratic quadrangle will be split into 4 linear quadrangles; - tri-quadratic hexahedron will be split into 8 linear hexahedra; Quadratic elements of lower dimension adjacent to the split bi-quadratic element will be split in order to keep the mesh conformal.", py::arg("theElems"));
	cls_SMESH_MeshEditor.def("Smooth", [](SMESH_MeshEditor &self, TIDSortedElemSet & a0, std::set<const SMDS_MeshNode *> & a1, const SMESH_MeshEditor::SmoothMethod a2, const int a3) -> void { return self.Smooth(a0, a1, a2, a3); }, py::arg("theElements"), py::arg("theFixedNodes"), py::arg("theSmoothMethod"), py::arg("theNbIterations"));
	cls_SMESH_MeshEditor.def("Smooth", [](SMESH_MeshEditor &self, TIDSortedElemSet & a0, std::set<const SMDS_MeshNode *> & a1, const SMESH_MeshEditor::SmoothMethod a2, const int a3, double a4) -> void { return self.Smooth(a0, a1, a2, a3, a4); }, py::arg("theElements"), py::arg("theFixedNodes"), py::arg("theSmoothMethod"), py::arg("theNbIterations"), py::arg("theTgtAspectRatio"));
	cls_SMESH_MeshEditor.def("Smooth", (void (SMESH_MeshEditor::*)(TIDSortedElemSet &, std::set<const SMDS_MeshNode *> &, const SMESH_MeshEditor::SmoothMethod, const int, double, const bool)) &SMESH_MeshEditor::Smooth, "None", py::arg("theElements"), py::arg("theFixedNodes"), py::arg("theSmoothMethod"), py::arg("theNbIterations"), py::arg("theTgtAspectRatio"), py::arg("the2D"));
	// FIXME cls_SMESH_MeshEditor.def("RotationSweep", [](SMESH_MeshEditor &self, TIDSortedElemSet [2] a0, const gp_Ax1 & a1, const double a2, const int a3, const double a4, const bool a5) -> SMESH_MeshEditor::PGroupIDs { return self.RotationSweep(a0, a1, a2, a3, a4, a5); }, py::arg("theElements"), py::arg("theAxis"), py::arg("theAngle"), py::arg("theNbSteps"), py::arg("theToler"), py::arg("theMakeGroups"));
	// FIXME cls_SMESH_MeshEditor.def("RotationSweep", (SMESH_MeshEditor::PGroupIDs (SMESH_MeshEditor::*)(TIDSortedElemSet [2], const gp_Ax1 &, const double, const int, const double, const bool, const bool)) &SMESH_MeshEditor::RotationSweep, "None", py::arg("theElements"), py::arg("theAxis"), py::arg("theAngle"), py::arg("theNbSteps"), py::arg("theToler"), py::arg("theMakeGroups"), py::arg("theMakeWalls"));
	// FIXME cls_SMESH_MeshEditor.def("ExtrusionSweep", [](SMESH_MeshEditor &self, TIDSortedElemSet [2] a0, const gp_Vec & a1, const int a2, SMESH_MeshEditor::TTElemOfElemListMap & a3, const int a4) -> SMESH_MeshEditor::PGroupIDs { return self.ExtrusionSweep(a0, a1, a2, a3, a4); }, py::arg("theElems"), py::arg("theStep"), py::arg("theNbSteps"), py::arg("newElemsMap"), py::arg("theFlags"));
	// FIXME cls_SMESH_MeshEditor.def("ExtrusionSweep", (SMESH_MeshEditor::PGroupIDs (SMESH_MeshEditor::*)(TIDSortedElemSet [2], const gp_Vec &, const int, SMESH_MeshEditor::TTElemOfElemListMap &, const int, const double)) &SMESH_MeshEditor::ExtrusionSweep, "Generate new elements by extrusion of theElements It is a method used in .idl file. All functionality is implemented in the next method (see below) which is used in the current method.", py::arg("theElems"), py::arg("theStep"), py::arg("theNbSteps"), py::arg("newElemsMap"), py::arg("theFlags"), py::arg("theTolerance"));
	// FIXME cls_SMESH_MeshEditor.def("ExtrusionSweep", (SMESH_MeshEditor::PGroupIDs (SMESH_MeshEditor::*)(TIDSortedElemSet [2], SMESH_MeshEditor::ExtrusParam &, SMESH_MeshEditor::TTElemOfElemListMap &)) &SMESH_MeshEditor::ExtrusionSweep, "Generate new elements by extrusion of theElements", py::arg("theElems"), py::arg("theParams"), py::arg("newElemsMap"));
	// FIXME cls_SMESH_MeshEditor.def("ExtrusionAlongTrack", (SMESH_MeshEditor::Extrusion_Error (SMESH_MeshEditor::*)(TIDSortedElemSet [2], SMESH_subMesh *, const SMDS_MeshNode *, const bool, std::list<double> &, const bool, const bool, const gp_Pnt &, const bool)) &SMESH_MeshEditor::ExtrusionAlongTrack, "None", py::arg("theElements"), py::arg("theTrackPattern"), py::arg("theNodeStart"), py::arg("theHasAngles"), py::arg("theAngles"), py::arg("theLinearVariation"), py::arg("theHasRefPoint"), py::arg("theRefPoint"), py::arg("theMakeGroups"));
	// FIXME cls_SMESH_MeshEditor.def("ExtrusionAlongTrack", (SMESH_MeshEditor::Extrusion_Error (SMESH_MeshEditor::*)(TIDSortedElemSet [2], SMESH_Mesh *, const SMDS_MeshNode *, const bool, std::list<double> &, const bool, const bool, const gp_Pnt &, const bool)) &SMESH_MeshEditor::ExtrusionAlongTrack, "None", py::arg("theElements"), py::arg("theTrackPattern"), py::arg("theNodeStart"), py::arg("theHasAngles"), py::arg("theAngles"), py::arg("theLinearVariation"), py::arg("theHasRefPoint"), py::arg("theRefPoint"), py::arg("theMakeGroups"));
	cls_SMESH_MeshEditor.def("Transform", [](SMESH_MeshEditor &self, TIDSortedElemSet & a0, const gp_Trsf & a1, const bool a2, const bool a3) -> SMESH_MeshEditor::PGroupIDs { return self.Transform(a0, a1, a2, a3); }, py::arg("theElements"), py::arg("theTrsf"), py::arg("theCopy"), py::arg("theMakeGroups"));
	cls_SMESH_MeshEditor.def("Transform", (SMESH_MeshEditor::PGroupIDs (SMESH_MeshEditor::*)(TIDSortedElemSet &, const gp_Trsf &, const bool, const bool, SMESH_Mesh *)) &SMESH_MeshEditor::Transform, "None", py::arg("theElements"), py::arg("theTrsf"), py::arg("theCopy"), py::arg("theMakeGroups"), py::arg("theTargetMesh"));
	cls_SMESH_MeshEditor.def("FindCoincidentNodes", (void (SMESH_MeshEditor::*)(TIDSortedNodeSet &, const double, SMESH_MeshEditor::TListOfListOfNodes &, bool)) &SMESH_MeshEditor::FindCoincidentNodes, "None", py::arg("theNodes"), py::arg("theTolerance"), py::arg("theGroupsOfNodes"), py::arg("theSeparateCornersAndMedium"));
	cls_SMESH_MeshEditor.def("MergeNodes", [](SMESH_MeshEditor &self, SMESH_MeshEditor::TListOfListOfNodes & a0) -> void { return self.MergeNodes(a0); }, py::arg("theNodeGroups"));
	cls_SMESH_MeshEditor.def("MergeNodes", (void (SMESH_MeshEditor::*)(SMESH_MeshEditor::TListOfListOfNodes &, const bool)) &SMESH_MeshEditor::MergeNodes, "None", py::arg("theNodeGroups"), py::arg("theAvoidMakingHoles"));
	cls_SMESH_MeshEditor.def("FindEqualElements", (void (SMESH_MeshEditor::*)(TIDSortedElemSet &, SMESH_MeshEditor::TListOfListOfElementsID &)) &SMESH_MeshEditor::FindEqualElements, "None", py::arg("theElements"), py::arg("theGroupsOfElementsID"));
	cls_SMESH_MeshEditor.def("MergeElements", (void (SMESH_MeshEditor::*)(SMESH_MeshEditor::TListOfListOfElementsID &)) &SMESH_MeshEditor::MergeElements, "None", py::arg("theGroupsOfElementsID"));
	cls_SMESH_MeshEditor.def("MergeEqualElements", (void (SMESH_MeshEditor::*)()) &SMESH_MeshEditor::MergeEqualElements, "None");
	cls_SMESH_MeshEditor.def("SimplifyFace", (int (SMESH_MeshEditor::*)(const std::vector<const SMDS_MeshNode *> &, std::vector<const SMDS_MeshNode *> &, std::vector<int> &) const ) &SMESH_MeshEditor::SimplifyFace, "None", py::arg("faceNodes"), py::arg("poly_nodes"), py::arg("quantities"));
	cls_SMESH_MeshEditor.def_static("CheckFreeBorderNodes_", [](const SMDS_MeshNode * a0, const SMDS_MeshNode * a1) -> bool { return SMESH_MeshEditor::CheckFreeBorderNodes(a0, a1); }, py::arg("theNode1"), py::arg("theNode2"));
	cls_SMESH_MeshEditor.def_static("CheckFreeBorderNodes_", (bool (*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMESH_MeshEditor::CheckFreeBorderNodes, "None", py::arg("theNode1"), py::arg("theNode2"), py::arg("theNode3"));
	cls_SMESH_MeshEditor.def_static("FindFreeBorder_", (bool (*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, std::list<const SMDS_MeshNode *> &, std::list<const SMDS_MeshElement *> &)) &SMESH_MeshEditor::FindFreeBorder, "None", py::arg("theFirstNode"), py::arg("theSecondNode"), py::arg("theLastNode"), py::arg("theNodes"), py::arg("theFaces"));
	cls_SMESH_MeshEditor.def("SewFreeBorder", [](SMESH_MeshEditor &self, const SMDS_MeshNode * a0, const SMDS_MeshNode * a1, const SMDS_MeshNode * a2, const SMDS_MeshNode * a3, const SMDS_MeshNode * a4) -> SMESH_MeshEditor::Sew_Error { return self.SewFreeBorder(a0, a1, a2, a3, a4); }, py::arg("theBorderFirstNode"), py::arg("theBorderSecondNode"), py::arg("theBorderLastNode"), py::arg("theSide2FirstNode"), py::arg("theSide2SecondNode"));
	cls_SMESH_MeshEditor.def("SewFreeBorder", [](SMESH_MeshEditor &self, const SMDS_MeshNode * a0, const SMDS_MeshNode * a1, const SMDS_MeshNode * a2, const SMDS_MeshNode * a3, const SMDS_MeshNode * a4, const SMDS_MeshNode * a5) -> SMESH_MeshEditor::Sew_Error { return self.SewFreeBorder(a0, a1, a2, a3, a4, a5); }, py::arg("theBorderFirstNode"), py::arg("theBorderSecondNode"), py::arg("theBorderLastNode"), py::arg("theSide2FirstNode"), py::arg("theSide2SecondNode"), py::arg("theSide2ThirdNode"));
	cls_SMESH_MeshEditor.def("SewFreeBorder", [](SMESH_MeshEditor &self, const SMDS_MeshNode * a0, const SMDS_MeshNode * a1, const SMDS_MeshNode * a2, const SMDS_MeshNode * a3, const SMDS_MeshNode * a4, const SMDS_MeshNode * a5, const bool a6) -> SMESH_MeshEditor::Sew_Error { return self.SewFreeBorder(a0, a1, a2, a3, a4, a5, a6); }, py::arg("theBorderFirstNode"), py::arg("theBorderSecondNode"), py::arg("theBorderLastNode"), py::arg("theSide2FirstNode"), py::arg("theSide2SecondNode"), py::arg("theSide2ThirdNode"), py::arg("theSide2IsFreeBorder"));
	cls_SMESH_MeshEditor.def("SewFreeBorder", [](SMESH_MeshEditor &self, const SMDS_MeshNode * a0, const SMDS_MeshNode * a1, const SMDS_MeshNode * a2, const SMDS_MeshNode * a3, const SMDS_MeshNode * a4, const SMDS_MeshNode * a5, const bool a6, const bool a7) -> SMESH_MeshEditor::Sew_Error { return self.SewFreeBorder(a0, a1, a2, a3, a4, a5, a6, a7); }, py::arg("theBorderFirstNode"), py::arg("theBorderSecondNode"), py::arg("theBorderLastNode"), py::arg("theSide2FirstNode"), py::arg("theSide2SecondNode"), py::arg("theSide2ThirdNode"), py::arg("theSide2IsFreeBorder"), py::arg("toCreatePolygons"));
	cls_SMESH_MeshEditor.def("SewFreeBorder", (SMESH_MeshEditor::Sew_Error (SMESH_MeshEditor::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const bool, const bool, const bool)) &SMESH_MeshEditor::SewFreeBorder, "None", py::arg("theBorderFirstNode"), py::arg("theBorderSecondNode"), py::arg("theBorderLastNode"), py::arg("theSide2FirstNode"), py::arg("theSide2SecondNode"), py::arg("theSide2ThirdNode"), py::arg("theSide2IsFreeBorder"), py::arg("toCreatePolygons"), py::arg("toCreatePolyedrs"));
	cls_SMESH_MeshEditor.def("SewSideElements", (SMESH_MeshEditor::Sew_Error (SMESH_MeshEditor::*)(TIDSortedElemSet &, TIDSortedElemSet &, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *)) &SMESH_MeshEditor::SewSideElements, "None", py::arg("theSide1"), py::arg("theSide2"), py::arg("theFirstNode1ToMerge"), py::arg("theFirstNode2ToMerge"), py::arg("theSecondNode1ToMerge"), py::arg("theSecondNode2ToMerge"));
	cls_SMESH_MeshEditor.def("InsertNodesIntoLink", [](SMESH_MeshEditor &self, const SMDS_MeshElement * a0, const SMDS_MeshNode * a1, const SMDS_MeshNode * a2, std::list<const SMDS_MeshNode *> & a3) -> void { return self.InsertNodesIntoLink(a0, a1, a2, a3); }, py::arg("theFace"), py::arg("theBetweenNode1"), py::arg("theBetweenNode2"), py::arg("theNodesToInsert"));
	cls_SMESH_MeshEditor.def("InsertNodesIntoLink", (void (SMESH_MeshEditor::*)(const SMDS_MeshElement *, const SMDS_MeshNode *, const SMDS_MeshNode *, std::list<const SMDS_MeshNode *> &, const bool)) &SMESH_MeshEditor::InsertNodesIntoLink, "None", py::arg("theFace"), py::arg("theBetweenNode1"), py::arg("theBetweenNode2"), py::arg("theNodesToInsert"), py::arg("toCreatePoly"));
	cls_SMESH_MeshEditor.def("UpdateVolumes", (void (SMESH_MeshEditor::*)(const SMDS_MeshNode *, const SMDS_MeshNode *, std::list<const SMDS_MeshNode *> &)) &SMESH_MeshEditor::UpdateVolumes, "None", py::arg("theBetweenNode1"), py::arg("theBetweenNode2"), py::arg("theNodesToInsert"));
	cls_SMESH_MeshEditor.def("ConvertToQuadratic", (void (SMESH_MeshEditor::*)(const bool, const bool)) &SMESH_MeshEditor::ConvertToQuadratic, "None", py::arg("theForce3d"), py::arg("theToBiQuad"));
	cls_SMESH_MeshEditor.def("ConvertToQuadratic", (void (SMESH_MeshEditor::*)(const bool, TIDSortedElemSet &, const bool)) &SMESH_MeshEditor::ConvertToQuadratic, "None", py::arg("theForce3d"), py::arg("theElements"), py::arg("theToBiQuad"));
	cls_SMESH_MeshEditor.def("ConvertFromQuadratic", (bool (SMESH_MeshEditor::*)()) &SMESH_MeshEditor::ConvertFromQuadratic, "None");
	cls_SMESH_MeshEditor.def("ConvertFromQuadratic", (void (SMESH_MeshEditor::*)(TIDSortedElemSet &)) &SMESH_MeshEditor::ConvertFromQuadratic, "None", py::arg("theElements"));
	cls_SMESH_MeshEditor.def_static("AddToSameGroups_", (void (*)(const SMDS_MeshElement *, const SMDS_MeshElement *, SMESHDS_Mesh *)) &SMESH_MeshEditor::AddToSameGroups, "None", py::arg("elemToAdd"), py::arg("elemInGroups"), py::arg("aMesh"));
	cls_SMESH_MeshEditor.def_static("RemoveElemFromGroups_", (void (*)(const SMDS_MeshElement *, SMESHDS_Mesh *)) &SMESH_MeshEditor::RemoveElemFromGroups, "None", py::arg("element"), py::arg("aMesh"));
	cls_SMESH_MeshEditor.def_static("ReplaceElemInGroups_", (void (*)(const SMDS_MeshElement *, const SMDS_MeshElement *, SMESHDS_Mesh *)) &SMESH_MeshEditor::ReplaceElemInGroups, "None", py::arg("elemToRm"), py::arg("elemToAdd"), py::arg("aMesh"));
	cls_SMESH_MeshEditor.def_static("ReplaceElemInGroups_", (void (*)(const SMDS_MeshElement *, const std::vector<const SMDS_MeshElement *> &, SMESHDS_Mesh *)) &SMESH_MeshEditor::ReplaceElemInGroups, "None", py::arg("elemToRm"), py::arg("elemToAdd"), py::arg("aMesh"));
	cls_SMESH_MeshEditor.def_static("GetLinkedNodes_", [](const SMDS_MeshNode * a0, TIDSortedElemSet & a1) -> void { return SMESH_MeshEditor::GetLinkedNodes(a0, a1); }, py::arg("node"), py::arg("linkedNodes"));
	cls_SMESH_MeshEditor.def_static("GetLinkedNodes_", (void (*)(const SMDS_MeshNode *, TIDSortedElemSet &, SMDSAbs_ElementType)) &SMESH_MeshEditor::GetLinkedNodes, "Return nodes linked to the given one in elements of the type", py::arg("node"), py::arg("linkedNodes"), py::arg("type"));
	cls_SMESH_MeshEditor.def_static("FindMatchingNodes_", (SMESH_MeshEditor::Sew_Error (*)(std::set<const SMDS_MeshElement *> &, std::set<const SMDS_MeshElement *> &, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, const SMDS_MeshNode *, TNodeNodeMap &)) &SMESH_MeshEditor::FindMatchingNodes, "Find corresponding nodes in two sets of faces", py::arg("theSide1"), py::arg("theSide2"), py::arg("theFirstNode1"), py::arg("theFirstNode2"), py::arg("theSecondNode1"), py::arg("theSecondNode2"), py::arg("theNodeReplaceMap"));
	cls_SMESH_MeshEditor.def_static("IsMedium_", [](const SMDS_MeshNode * a0) -> bool { return SMESH_MeshEditor::IsMedium(a0); }, py::arg("node"));
	cls_SMESH_MeshEditor.def_static("IsMedium_", (bool (*)(const SMDS_MeshNode *, const SMDSAbs_ElementType)) &SMESH_MeshEditor::IsMedium, "Returns true if given node is medium", py::arg("node"), py::arg("typeToCheck"));
	cls_SMESH_MeshEditor.def("FindShape", (int (SMESH_MeshEditor::*)(const SMDS_MeshElement *)) &SMESH_MeshEditor::FindShape, "None", py::arg("theElem"));
	cls_SMESH_MeshEditor.def("DoubleElements", (void (SMESH_MeshEditor::*)(const TIDSortedElemSet &)) &SMESH_MeshEditor::DoubleElements, "None", py::arg("theElements"));
	cls_SMESH_MeshEditor.def("DoubleNodes", (bool (SMESH_MeshEditor::*)(const std::list<int> &, const std::list<int> &)) &SMESH_MeshEditor::DoubleNodes, "None", py::arg("theListOfNodes"), py::arg("theListOfModifiedElems"));
	cls_SMESH_MeshEditor.def("DoubleNodes", (bool (SMESH_MeshEditor::*)(const TIDSortedElemSet &, const TIDSortedElemSet &, const TIDSortedElemSet &)) &SMESH_MeshEditor::DoubleNodes, "None", py::arg("theElems"), py::arg("theNodesNot"), py::arg("theAffectedElems"));
	cls_SMESH_MeshEditor.def("AffectedElemGroupsInRegion", (bool (SMESH_MeshEditor::*)(const TIDSortedElemSet &, const TIDSortedElemSet &, const TopoDS_Shape &, TIDSortedElemSet &)) &SMESH_MeshEditor::AffectedElemGroupsInRegion, "None", py::arg("theElems"), py::arg("theNodesNot"), py::arg("theShape"), py::arg("theAffectedElems"));
	cls_SMESH_MeshEditor.def("DoubleNodesInRegion", (bool (SMESH_MeshEditor::*)(const TIDSortedElemSet &, const TIDSortedElemSet &, const TopoDS_Shape &)) &SMESH_MeshEditor::DoubleNodesInRegion, "None", py::arg("theElems"), py::arg("theNodesNot"), py::arg("theShape"));
	cls_SMESH_MeshEditor.def("OrientedAngle", (double (SMESH_MeshEditor::*)(const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &)) &SMESH_MeshEditor::OrientedAngle, "None", py::arg("p0"), py::arg("p1"), py::arg("g1"), py::arg("g2"));
	cls_SMESH_MeshEditor.def("DoubleNodesOnGroupBoundaries", (bool (SMESH_MeshEditor::*)(const std::vector<TIDSortedElemSet> &, bool, bool)) &SMESH_MeshEditor::DoubleNodesOnGroupBoundaries, "None", py::arg("theElems"), py::arg("createJointElems"), py::arg("onAllBoundaries"));
	cls_SMESH_MeshEditor.def("CreateFlatElementsOnFacesGroups", (bool (SMESH_MeshEditor::*)(const std::vector<TIDSortedElemSet> &)) &SMESH_MeshEditor::CreateFlatElementsOnFacesGroups, "None", py::arg("theElems"));
	cls_SMESH_MeshEditor.def("CreateHoleSkin", (void (SMESH_MeshEditor::*)(double, const TopoDS_Shape &, SMESH_NodeSearcher *, const char *, std::vector<double> &, std::vector<std::vector<int> > &)) &SMESH_MeshEditor::CreateHoleSkin, "None", py::arg("radius"), py::arg("theShape"), py::arg("theNodeSearcher"), py::arg("groupName"), py::arg("nodesCoords"), py::arg("listOfListOfNodes"));
	cls_SMESH_MeshEditor.def("Make2DMeshFrom3D", (bool (SMESH_MeshEditor::*)()) &SMESH_MeshEditor::Make2DMeshFrom3D, "Generated skin mesh (containing 2D cells) from 3D mesh The created 2D mesh elements based on nodes of free faces of boundary volumes");
	cls_SMESH_MeshEditor.def("MakeBoundaryMesh", [](SMESH_MeshEditor &self, const TIDSortedElemSet & a0, SMESH_MeshEditor::Bnd_Dimension a1) -> int { return self.MakeBoundaryMesh(a0, a1); }, py::arg("elements"), py::arg("dimension"));
	cls_SMESH_MeshEditor.def("MakeBoundaryMesh", [](SMESH_MeshEditor &self, const TIDSortedElemSet & a0, SMESH_MeshEditor::Bnd_Dimension a1, SMESH_Group * a2) -> int { return self.MakeBoundaryMesh(a0, a1, a2); }, py::arg("elements"), py::arg("dimension"), py::arg("group"));
	cls_SMESH_MeshEditor.def("MakeBoundaryMesh", [](SMESH_MeshEditor &self, const TIDSortedElemSet & a0, SMESH_MeshEditor::Bnd_Dimension a1, SMESH_Group * a2, SMESH_Mesh * a3) -> int { return self.MakeBoundaryMesh(a0, a1, a2, a3); }, py::arg("elements"), py::arg("dimension"), py::arg("group"), py::arg("targetMesh"));
	cls_SMESH_MeshEditor.def("MakeBoundaryMesh", [](SMESH_MeshEditor &self, const TIDSortedElemSet & a0, SMESH_MeshEditor::Bnd_Dimension a1, SMESH_Group * a2, SMESH_Mesh * a3, bool a4) -> int { return self.MakeBoundaryMesh(a0, a1, a2, a3, a4); }, py::arg("elements"), py::arg("dimension"), py::arg("group"), py::arg("targetMesh"), py::arg("toCopyElements"));
	cls_SMESH_MeshEditor.def("MakeBoundaryMesh", [](SMESH_MeshEditor &self, const TIDSortedElemSet & a0, SMESH_MeshEditor::Bnd_Dimension a1, SMESH_Group * a2, SMESH_Mesh * a3, bool a4, bool a5) -> int { return self.MakeBoundaryMesh(a0, a1, a2, a3, a4, a5); }, py::arg("elements"), py::arg("dimension"), py::arg("group"), py::arg("targetMesh"), py::arg("toCopyElements"), py::arg("toCopyExistingBondary"));
	cls_SMESH_MeshEditor.def("MakeBoundaryMesh", [](SMESH_MeshEditor &self, const TIDSortedElemSet & a0, SMESH_MeshEditor::Bnd_Dimension a1, SMESH_Group * a2, SMESH_Mesh * a3, bool a4, bool a5, bool a6) -> int { return self.MakeBoundaryMesh(a0, a1, a2, a3, a4, a5, a6); }, py::arg("elements"), py::arg("dimension"), py::arg("group"), py::arg("targetMesh"), py::arg("toCopyElements"), py::arg("toCopyExistingBondary"), py::arg("toAddExistingBondary"));
	cls_SMESH_MeshEditor.def("MakeBoundaryMesh", (int (SMESH_MeshEditor::*)(const TIDSortedElemSet &, SMESH_MeshEditor::Bnd_Dimension, SMESH_Group *, SMESH_Mesh *, bool, bool, bool, bool)) &SMESH_MeshEditor::MakeBoundaryMesh, "None", py::arg("elements"), py::arg("dimension"), py::arg("group"), py::arg("targetMesh"), py::arg("toCopyElements"), py::arg("toCopyExistingBondary"), py::arg("toAddExistingBondary"), py::arg("aroundElements"));
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_MeshEditor.hxx
	py::enum_<SMESH_MeshEditor::SplitVolumToTetraFlags>(cls_SMESH_MeshEditor, "SplitVolumToTetraFlags", "None")
		.value("HEXA_TO_5", SMESH_MeshEditor::SplitVolumToTetraFlags::HEXA_TO_5)
		.value("HEXA_TO_6", SMESH_MeshEditor::SplitVolumToTetraFlags::HEXA_TO_6)
		.value("HEXA_TO_24", SMESH_MeshEditor::SplitVolumToTetraFlags::HEXA_TO_24)
		.value("HEXA_TO_2_PRISMS", SMESH_MeshEditor::SplitVolumToTetraFlags::HEXA_TO_2_PRISMS)
		.value("HEXA_TO_4_PRISMS", SMESH_MeshEditor::SplitVolumToTetraFlags::HEXA_TO_4_PRISMS)
		.export_values();
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_MeshEditor.hxx
	py::enum_<SMESH_MeshEditor::SmoothMethod>(cls_SMESH_MeshEditor, "SmoothMethod", "None")
		.value("LAPLACIAN", SMESH_MeshEditor::SmoothMethod::LAPLACIAN)
		.value("CENTROIDAL", SMESH_MeshEditor::SmoothMethod::CENTROIDAL)
		.export_values();
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_MeshEditor.hxx
	py::enum_<SMESH_MeshEditor::ExtrusionFlags>(cls_SMESH_MeshEditor, "ExtrusionFlags", "Flags of extrusion. BOUNDARY: create or not boundary for result of extrusion SEW: try to use existing nodes or create new nodes in any case GROUPS: to create groups BY_AVG_NORMAL: step size is measured along average normal to elements, else step size is measured along average normal of any element USE_INPUT_ELEMS_ONLY: to use only input elements to compute extrusion direction for ExtrusionByNormal() SCALE_LINEAR_VARIATION: to make linear variation of scale factors")
		.value("EXTRUSION_FLAG_BOUNDARY", SMESH_MeshEditor::ExtrusionFlags::EXTRUSION_FLAG_BOUNDARY)
		.value("EXTRUSION_FLAG_SEW", SMESH_MeshEditor::ExtrusionFlags::EXTRUSION_FLAG_SEW)
		.value("EXTRUSION_FLAG_GROUPS", SMESH_MeshEditor::ExtrusionFlags::EXTRUSION_FLAG_GROUPS)
		.value("EXTRUSION_FLAG_BY_AVG_NORMAL", SMESH_MeshEditor::ExtrusionFlags::EXTRUSION_FLAG_BY_AVG_NORMAL)
		.value("EXTRUSION_FLAG_USE_INPUT_ELEMS_ONLY", SMESH_MeshEditor::ExtrusionFlags::EXTRUSION_FLAG_USE_INPUT_ELEMS_ONLY)
		.value("EXTRUSION_FLAG_SCALE_LINEAR_VARIATION", SMESH_MeshEditor::ExtrusionFlags::EXTRUSION_FLAG_SCALE_LINEAR_VARIATION)
		.export_values();
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_MeshEditor.hxx
	py::enum_<SMESH_MeshEditor::Extrusion_Error>(cls_SMESH_MeshEditor, "Extrusion_Error", "None")
		.value("EXTR_OK", SMESH_MeshEditor::Extrusion_Error::EXTR_OK)
		.value("EXTR_NO_ELEMENTS", SMESH_MeshEditor::Extrusion_Error::EXTR_NO_ELEMENTS)
		.value("EXTR_PATH_NOT_EDGE", SMESH_MeshEditor::Extrusion_Error::EXTR_PATH_NOT_EDGE)
		.value("EXTR_BAD_PATH_SHAPE", SMESH_MeshEditor::Extrusion_Error::EXTR_BAD_PATH_SHAPE)
		.value("EXTR_BAD_STARTING_NODE", SMESH_MeshEditor::Extrusion_Error::EXTR_BAD_STARTING_NODE)
		.value("EXTR_BAD_ANGLES_NUMBER", SMESH_MeshEditor::Extrusion_Error::EXTR_BAD_ANGLES_NUMBER)
		.value("EXTR_CANT_GET_TANGENT", SMESH_MeshEditor::Extrusion_Error::EXTR_CANT_GET_TANGENT)
		.export_values();
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_MeshEditor.hxx
	py::enum_<SMESH_MeshEditor::Sew_Error>(cls_SMESH_MeshEditor, "Sew_Error", "None")
		.value("SEW_OK", SMESH_MeshEditor::Sew_Error::SEW_OK)
		.value("SEW_BORDER1_NOT_FOUND", SMESH_MeshEditor::Sew_Error::SEW_BORDER1_NOT_FOUND)
		.value("SEW_BORDER2_NOT_FOUND", SMESH_MeshEditor::Sew_Error::SEW_BORDER2_NOT_FOUND)
		.value("SEW_BOTH_BORDERS_NOT_FOUND", SMESH_MeshEditor::Sew_Error::SEW_BOTH_BORDERS_NOT_FOUND)
		.value("SEW_BAD_SIDE_NODES", SMESH_MeshEditor::Sew_Error::SEW_BAD_SIDE_NODES)
		.value("SEW_VOLUMES_TO_SPLIT", SMESH_MeshEditor::Sew_Error::SEW_VOLUMES_TO_SPLIT)
		.value("SEW_DIFF_NB_OF_ELEMENTS", SMESH_MeshEditor::Sew_Error::SEW_DIFF_NB_OF_ELEMENTS)
		.value("SEW_TOPO_DIFF_SETS_OF_ELEMENTS", SMESH_MeshEditor::Sew_Error::SEW_TOPO_DIFF_SETS_OF_ELEMENTS)
		.value("SEW_BAD_SIDE1_NODES", SMESH_MeshEditor::Sew_Error::SEW_BAD_SIDE1_NODES)
		.value("SEW_BAD_SIDE2_NODES", SMESH_MeshEditor::Sew_Error::SEW_BAD_SIDE2_NODES)
		.value("SEW_INTERNAL_ERROR", SMESH_MeshEditor::Sew_Error::SEW_INTERNAL_ERROR)
		.export_values();
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_MeshEditor.hxx
	py::enum_<SMESH_MeshEditor::Bnd_Dimension>(cls_SMESH_MeshEditor, "Bnd_Dimension", "None")
		.value("BND_2DFROM3D", SMESH_MeshEditor::Bnd_Dimension::BND_2DFROM3D)
		.value("BND_1DFROM3D", SMESH_MeshEditor::Bnd_Dimension::BND_1DFROM3D)
		.value("BND_1DFROM2D", SMESH_MeshEditor::Bnd_Dimension::BND_1DFROM2D)
		.export_values();

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_MeshVSLink.hxx
	py::class_<SMESH_MeshVSLink, opencascade::handle<SMESH_MeshVSLink>, MeshVS_DataSource3D> cls_SMESH_MeshVSLink(mod, "SMESH_MeshVSLink", "None");
	cls_SMESH_MeshVSLink.def(py::init<const SMESH_Mesh *>(), py::arg("aMesh"));
	cls_SMESH_MeshVSLink.def(py::init<const SMESH_subMesh *>(), py::arg("aSubMesh"));
	cls_SMESH_MeshVSLink.def(py::init<const SMESH_Mesh *, const SMESH_Group *>(), py::arg("aMesh"), py::arg("aGroup"));
	cls_SMESH_MeshVSLink.def("GetGeom", [](SMESH_MeshVSLink &self, const Standard_Integer ID, const Standard_Boolean IsElement, TColStd_Array1OfReal & Coords, Standard_Integer & NbNodes, MeshVS_EntityType & Type){ Standard_Boolean rv = self.GetGeom(ID, IsElement, Coords, NbNodes, Type); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, NbNodes); }, "Returns geometry information about node ( if IsElement is False ) or element ( IsElement is True ) by co-ordinates. For element this method must return all its nodes co-ordinates in the strict order: X, Y, Z and with nodes order is the same as in wire bounding the face or link. NbNodes is number of nodes of element. It is recommended to return 1 for node. Type is an element type.", py::arg("ID"), py::arg("IsElement"), py::arg("Coords"), py::arg("NbNodes"), py::arg("Type"));
	cls_SMESH_MeshVSLink.def("Get3DGeom", [](SMESH_MeshVSLink &self, const Standard_Integer ID, Standard_Integer & NbNodes, opencascade::handle<MeshVS_HArray1OfSequenceOfInteger> & Data){ Standard_Boolean rv = self.Get3DGeom(ID, NbNodes, Data); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, NbNodes); }, "None", py::arg("ID"), py::arg("NbNodes"), py::arg("Data"));
	cls_SMESH_MeshVSLink.def("GetGeomType", (Standard_Boolean (SMESH_MeshVSLink::*)(const Standard_Integer, const Standard_Boolean, MeshVS_EntityType &) const ) &SMESH_MeshVSLink::GetGeomType, "This method is similar to GetGeom, but returns only element or node type. This method is provided for a fine performance.", py::arg("ID"), py::arg("IsElement"), py::arg("Type"));
	cls_SMESH_MeshVSLink.def("GetAddr", (Standard_Address (SMESH_MeshVSLink::*)(const Standard_Integer, const Standard_Boolean) const ) &SMESH_MeshVSLink::GetAddr, "This method returns by number an address of any entity which represents element or node data structure.", py::arg("ID"), py::arg("IsElement"));
	cls_SMESH_MeshVSLink.def("GetNodesByElement", [](SMESH_MeshVSLink &self, const Standard_Integer ID, TColStd_Array1OfInteger & NodeIDs, Standard_Integer & NbNodes){ Standard_Boolean rv = self.GetNodesByElement(ID, NodeIDs, NbNodes); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, NbNodes); }, "This method returns information about what node this element consist of.", py::arg("ID"), py::arg("NodeIDs"), py::arg("NbNodes"));
	cls_SMESH_MeshVSLink.def("GetAllNodes", (const TColStd_PackedMapOfInteger & (SMESH_MeshVSLink::*)() const ) &SMESH_MeshVSLink::GetAllNodes, "This method returns map of all nodes the object consist of.");
	cls_SMESH_MeshVSLink.def("GetAllElements", (const TColStd_PackedMapOfInteger & (SMESH_MeshVSLink::*)() const ) &SMESH_MeshVSLink::GetAllElements, "This method returns map of all elements the object consist of.");
	cls_SMESH_MeshVSLink.def("GetNormal", [](SMESH_MeshVSLink &self, const Standard_Integer Id, const Standard_Integer Max, Standard_Real & nx, Standard_Real & ny, Standard_Real & nz){ Standard_Boolean rv = self.GetNormal(Id, Max, nx, ny, nz); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &, Standard_Real &>(rv, nx, ny, nz); }, "This method calculates normal of face, which is using for correct reflection presentation. There is default method, for advance reflection this method can be redefined.", py::arg("Id"), py::arg("Max"), py::arg("nx"), py::arg("ny"), py::arg("nz"));
	cls_SMESH_MeshVSLink.def("GetAllGroups", (void (SMESH_MeshVSLink::*)(TColStd_PackedMapOfInteger &) const ) &SMESH_MeshVSLink::GetAllGroups, "This method returns map of all groups the object contains.", py::arg("Ids"));
	cls_SMESH_MeshVSLink.def_static("get_type_name_", (const char * (*)()) &SMESH_MeshVSLink::get_type_name, "None");
	cls_SMESH_MeshVSLink.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SMESH_MeshVSLink::get_type_descriptor, "None");
	cls_SMESH_MeshVSLink.def("DynamicType", (const opencascade::handle<Standard_Type> & (SMESH_MeshVSLink::*)() const ) &SMESH_MeshVSLink::DynamicType, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Tree.hxx
	py::class_<SMESH_TreeLimit, std::unique_ptr<SMESH_TreeLimit, Deleter<SMESH_TreeLimit>>> cls_SMESH_TreeLimit(mod, "SMESH_TreeLimit", "None");
	cls_SMESH_TreeLimit.def(py::init<>());
	cls_SMESH_TreeLimit.def(py::init<int>(), py::arg("maxLevel"));
	cls_SMESH_TreeLimit.def(py::init<int, double>(), py::arg("maxLevel"), py::arg("minSize"));

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Octree.hxx
	py::class_<SMESH_Octree, std::unique_ptr<SMESH_Octree, Deleter<SMESH_Octree>>, SMESH_Tree<Bnd_B3d, 8>> cls_SMESH_Octree(mod, "SMESH_Octree", "3D tree of anything. Methods to implement in a descendant are: - Bnd_B3d* buildRootBox(); // box of a tree - descendant* newChild() const; // a new child instance - void buildChildrenData(); // distribute own data among children");
	cls_SMESH_Octree.def(py::init<>());
	cls_SMESH_Octree.def(py::init<SMESH_TreeLimit *>(), py::arg("limit"));
	cls_SMESH_Octree.def("maxSize", (double (SMESH_Octree::*)() const ) &SMESH_Octree::maxSize, "None");
	cls_SMESH_Octree.def_static("getChildIndex_", (int (*)(double, double, double, const gp_XYZ &)) &SMESH_Octree::getChildIndex, "Return index of a child the given point is in", py::arg("x"), py::arg("y"), py::arg("z"), py::arg("boxMiddle"));
	*/

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_OctreeNode.hxx
	py::class_<SMESH_OctreeNode, std::unique_ptr<SMESH_OctreeNode, Deleter<SMESH_OctreeNode>>> cls_SMESH_OctreeNode(mod, "SMESH_OctreeNode", "None");
	cls_SMESH_OctreeNode.def(py::init<const TIDSortedNodeSet &>(), py::arg("theNodes"));
	cls_SMESH_OctreeNode.def(py::init<const TIDSortedNodeSet &, const int>(), py::arg("theNodes"), py::arg("maxLevel"));
	cls_SMESH_OctreeNode.def(py::init<const TIDSortedNodeSet &, const int, const int>(), py::arg("theNodes"), py::arg("maxLevel"), py::arg("maxNbNodes"));
	cls_SMESH_OctreeNode.def(py::init<const TIDSortedNodeSet &, const int, const int, const double>(), py::arg("theNodes"), py::arg("maxLevel"), py::arg("maxNbNodes"), py::arg("minBoxSize"));
	cls_SMESH_OctreeNode.def("isInside", [](SMESH_OctreeNode &self, const gp_XYZ & a0) -> const bool { return self.isInside(a0); }, py::arg("p"));
	cls_SMESH_OctreeNode.def("isInside", (const bool (SMESH_OctreeNode::*)(const gp_XYZ &, const double)) &SMESH_OctreeNode::isInside, "None", py::arg("p"), py::arg("precision"));
	cls_SMESH_OctreeNode.def("NodesAround", [](SMESH_OctreeNode &self, const SMDS_MeshNode * a0, std::list<const SMDS_MeshNode *> * a1) -> void { return self.NodesAround(a0, a1); }, py::arg("node"), py::arg("result"));
	cls_SMESH_OctreeNode.def("NodesAround", (void (SMESH_OctreeNode::*)(const SMDS_MeshNode *, std::list<const SMDS_MeshNode *> *, const double)) &SMESH_OctreeNode::NodesAround, "None", py::arg("node"), py::arg("result"), py::arg("precision"));
	cls_SMESH_OctreeNode.def("NodesAround", (bool (SMESH_OctreeNode::*)(const gp_XYZ &, std::map<double, const SMDS_MeshNode *> &, double)) &SMESH_OctreeNode::NodesAround, "None", py::arg("point"), py::arg("dist2Nodes"), py::arg("precision"));
	cls_SMESH_OctreeNode.def("NodesAround", (void (SMESH_OctreeNode::*)(const gp_XYZ &, std::vector<const SMDS_MeshNode *> &, double)) &SMESH_OctreeNode::NodesAround, "None", py::arg("point"), py::arg("nodes"), py::arg("precision"));
	cls_SMESH_OctreeNode.def("FindCoincidentNodes", (void (SMESH_OctreeNode::*)(TIDSortedNodeSet *, const double, std::list<std::list<const SMDS_MeshNode *> > *)) &SMESH_OctreeNode::FindCoincidentNodes, "None", py::arg("nodes"), py::arg("theTolerance"), py::arg("theGroupsOfNodes"));
	cls_SMESH_OctreeNode.def_static("FindCoincidentNodes_", [](TIDSortedNodeSet & a0, std::list<std::list<const SMDS_MeshNode *> > * a1) -> void { return SMESH_OctreeNode::FindCoincidentNodes(a0, a1); }, py::arg("nodes"), py::arg("theGroupsOfNodes"));
	cls_SMESH_OctreeNode.def_static("FindCoincidentNodes_", [](TIDSortedNodeSet & a0, std::list<std::list<const SMDS_MeshNode *> > * a1, const double a2) -> void { return SMESH_OctreeNode::FindCoincidentNodes(a0, a1, a2); }, py::arg("nodes"), py::arg("theGroupsOfNodes"), py::arg("theTolerance"));
	cls_SMESH_OctreeNode.def_static("FindCoincidentNodes_", [](TIDSortedNodeSet & a0, std::list<std::list<const SMDS_MeshNode *> > * a1, const double a2, const int a3) -> void { return SMESH_OctreeNode::FindCoincidentNodes(a0, a1, a2, a3); }, py::arg("nodes"), py::arg("theGroupsOfNodes"), py::arg("theTolerance"), py::arg("maxLevel"));
	cls_SMESH_OctreeNode.def_static("FindCoincidentNodes_", (void (*)(TIDSortedNodeSet &, std::list<std::list<const SMDS_MeshNode *> > *, const double, const int, const int)) &SMESH_OctreeNode::FindCoincidentNodes, "None", py::arg("nodes"), py::arg("theGroupsOfNodes"), py::arg("theTolerance"), py::arg("maxLevel"), py::arg("maxNbNodes"));
	cls_SMESH_OctreeNode.def("UpdateByMoveNode", (void (SMESH_OctreeNode::*)(const SMDS_MeshNode *, const gp_Pnt &)) &SMESH_OctreeNode::UpdateByMoveNode, "Update data according to node movement", py::arg("node"), py::arg("toPnt"));
	cls_SMESH_OctreeNode.def("GetChildrenIterator", (SMESH_OctreeNodeIteratorPtr (SMESH_OctreeNode::*)()) &SMESH_OctreeNode::GetChildrenIterator, "Return iterator over children");
	cls_SMESH_OctreeNode.def("GetNodeIterator", (SMDS_NodeIteratorPtr (SMESH_OctreeNode::*)()) &SMESH_OctreeNode::GetNodeIterator, "Return nodes iterator");
	cls_SMESH_OctreeNode.def("NbNodes", (int (SMESH_OctreeNode::*)() const ) &SMESH_OctreeNode::NbNodes, "Return nb nodes in a tree");
	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Pattern.hxx
	py::class_<SMESH_Pattern, std::unique_ptr<SMESH_Pattern, Deleter<SMESH_Pattern>>> cls_SMESH_Pattern(mod, "SMESH_Pattern", "None");
	cls_SMESH_Pattern.def(py::init<>());
	cls_SMESH_Pattern.def("Clear", (void (SMESH_Pattern::*)()) &SMESH_Pattern::Clear, "None");
	cls_SMESH_Pattern.def("Load", (bool (SMESH_Pattern::*)(const char *)) &SMESH_Pattern::Load, "None", py::arg("theFileContents"));
	cls_SMESH_Pattern.def("Load", [](SMESH_Pattern &self, SMESH_Mesh * a0, const TopoDS_Face & a1) -> bool { return self.Load(a0, a1); }, py::arg("theMesh"), py::arg("theFace"));
	cls_SMESH_Pattern.def("Load", [](SMESH_Pattern &self, SMESH_Mesh * a0, const TopoDS_Face & a1, bool a2) -> bool { return self.Load(a0, a1, a2); }, py::arg("theMesh"), py::arg("theFace"), py::arg("theProject"));
	cls_SMESH_Pattern.def("Load", [](SMESH_Pattern &self, SMESH_Mesh * a0, const TopoDS_Face & a1, bool a2, TopoDS_Vertex a3) -> bool { return self.Load(a0, a1, a2, a3); }, py::arg("theMesh"), py::arg("theFace"), py::arg("theProject"), py::arg("the1stVertex"));
	cls_SMESH_Pattern.def("Load", (bool (SMESH_Pattern::*)(SMESH_Mesh *, const TopoDS_Face &, bool, TopoDS_Vertex, bool)) &SMESH_Pattern::Load, "None", py::arg("theMesh"), py::arg("theFace"), py::arg("theProject"), py::arg("the1stVertex"), py::arg("theKeepNodes"));
	cls_SMESH_Pattern.def("Load", [](SMESH_Pattern &self, SMESH_Mesh * a0, const TopoDS_Shell & a1) -> bool { return self.Load(a0, a1); }, py::arg("theMesh"), py::arg("theBlock"));
	cls_SMESH_Pattern.def("Load", (bool (SMESH_Pattern::*)(SMESH_Mesh *, const TopoDS_Shell &, bool)) &SMESH_Pattern::Load, "None", py::arg("theMesh"), py::arg("theBlock"), py::arg("theKeepNodes"));
	cls_SMESH_Pattern.def("Save", (bool (SMESH_Pattern::*)(std::ostream &)) &SMESH_Pattern::Save, "None", py::arg("theFile"));
	cls_SMESH_Pattern.def("Apply", (bool (SMESH_Pattern::*)(const TopoDS_Face &, const TopoDS_Vertex &, const bool)) &SMESH_Pattern::Apply, "None", py::arg("theFace"), py::arg("theVertexOnKeyPoint1"), py::arg("theReverse"));
	cls_SMESH_Pattern.def("Apply", (bool (SMESH_Pattern::*)(const TopoDS_Shell &, const TopoDS_Vertex &, const TopoDS_Vertex &)) &SMESH_Pattern::Apply, "None", py::arg("theBlock"), py::arg("theVertex000"), py::arg("theVertex001"));
	cls_SMESH_Pattern.def("Apply", (bool (SMESH_Pattern::*)(const SMDS_MeshFace *, const int, const bool)) &SMESH_Pattern::Apply, "None", py::arg("theFace"), py::arg("theNodeIndexOnKeyPoint1"), py::arg("theReverse"));
	cls_SMESH_Pattern.def("Apply", (bool (SMESH_Pattern::*)(SMESH_Mesh *, const SMDS_MeshFace *, const TopoDS_Shape &, const int, const bool)) &SMESH_Pattern::Apply, "None", py::arg("theMesh"), py::arg("theFace"), py::arg("theSurface"), py::arg("theNodeIndexOnKeyPoint1"), py::arg("theReverse"));
	cls_SMESH_Pattern.def("Apply", (bool (SMESH_Pattern::*)(SMESH_Mesh *, std::set<const SMDS_MeshFace *> &, const int, const bool)) &SMESH_Pattern::Apply, "None", py::arg("theMesh"), py::arg("theFaces"), py::arg("theNodeIndexOnKeyPoint1"), py::arg("theReverse"));
	cls_SMESH_Pattern.def("Apply", (bool (SMESH_Pattern::*)(const SMDS_MeshVolume *, const int, const int)) &SMESH_Pattern::Apply, "None", py::arg("theVolume"), py::arg("theNode000Index"), py::arg("theNode001Index"));
	cls_SMESH_Pattern.def("Apply", (bool (SMESH_Pattern::*)(std::set<const SMDS_MeshVolume *> &, const int, const int)) &SMESH_Pattern::Apply, "None", py::arg("theVolumes"), py::arg("theNode000Index"), py::arg("theNode001Index"));
	cls_SMESH_Pattern.def("GetMappedPoints", (bool (SMESH_Pattern::*)(std::list<const gp_XYZ *> &) const ) &SMESH_Pattern::GetMappedPoints, "None", py::arg("thePoints"));
	cls_SMESH_Pattern.def("MakeMesh", [](SMESH_Pattern &self, SMESH_Mesh * a0) -> bool { return self.MakeMesh(a0); }, py::arg("theMesh"));
	cls_SMESH_Pattern.def("MakeMesh", [](SMESH_Pattern &self, SMESH_Mesh * a0, const bool a1) -> bool { return self.MakeMesh(a0, a1); }, py::arg("theMesh"), py::arg("toCreatePolygons"));
	cls_SMESH_Pattern.def("MakeMesh", (bool (SMESH_Pattern::*)(SMESH_Mesh *, const bool, const bool)) &SMESH_Pattern::MakeMesh, "None", py::arg("theMesh"), py::arg("toCreatePolygons"), py::arg("toCreatePolyedrs"));
	cls_SMESH_Pattern.def("GetErrorCode", (SMESH_Pattern::ErrorCode (SMESH_Pattern::*)() const ) &SMESH_Pattern::GetErrorCode, "None");
	cls_SMESH_Pattern.def("IsLoaded", (bool (SMESH_Pattern::*)() const ) &SMESH_Pattern::IsLoaded, "None");
	cls_SMESH_Pattern.def("Is2D", (bool (SMESH_Pattern::*)() const ) &SMESH_Pattern::Is2D, "None");
	cls_SMESH_Pattern.def("GetPoints", (bool (SMESH_Pattern::*)(std::list<const gp_XYZ *> &) const ) &SMESH_Pattern::GetPoints, "None", py::arg("thePoints"));
	cls_SMESH_Pattern.def("GetKeyPointIDs", (const std::list<int> & (SMESH_Pattern::*)() const ) &SMESH_Pattern::GetKeyPointIDs, "None");
	cls_SMESH_Pattern.def("GetElementPointIDs", (const std::list<std::list<int> > & (SMESH_Pattern::*)(bool) const ) &SMESH_Pattern::GetElementPointIDs, "None", py::arg("applied"));
	// FIXME cls_SMESH_Pattern.def("GetInOutNodes", (void (SMESH_Pattern::*)(std::vector<const SMDS_MeshNode *> *&, std::vector<const SMDS_MeshNode *> *&)) &SMESH_Pattern::GetInOutNodes, "None", py::arg("inNodes"), py::arg("outNodes"));
	cls_SMESH_Pattern.def("DumpPoints", (void (SMESH_Pattern::*)() const ) &SMESH_Pattern::DumpPoints, "None");
	cls_SMESH_Pattern.def("GetSubShape", (TopoDS_Shape (SMESH_Pattern::*)(const int) const ) &SMESH_Pattern::GetSubShape, "None", py::arg("i"));
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Pattern.hxx
	py::enum_<SMESH_Pattern::ErrorCode>(cls_SMESH_Pattern, "ErrorCode", "None")
		.value("ERR_OK", SMESH_Pattern::ErrorCode::ERR_OK)
		.value("ERR_READ_NB_POINTS", SMESH_Pattern::ErrorCode::ERR_READ_NB_POINTS)
		.value("ERR_READ_POINT_COORDS", SMESH_Pattern::ErrorCode::ERR_READ_POINT_COORDS)
		.value("ERR_READ_TOO_FEW_POINTS", SMESH_Pattern::ErrorCode::ERR_READ_TOO_FEW_POINTS)
		.value("ERR_READ_3D_COORD", SMESH_Pattern::ErrorCode::ERR_READ_3D_COORD)
		.value("ERR_READ_NO_KEYPOINT", SMESH_Pattern::ErrorCode::ERR_READ_NO_KEYPOINT)
		.value("ERR_READ_BAD_INDEX", SMESH_Pattern::ErrorCode::ERR_READ_BAD_INDEX)
		.value("ERR_READ_ELEM_POINTS", SMESH_Pattern::ErrorCode::ERR_READ_ELEM_POINTS)
		.value("ERR_READ_NO_ELEMS", SMESH_Pattern::ErrorCode::ERR_READ_NO_ELEMS)
		.value("ERR_READ_BAD_KEY_POINT", SMESH_Pattern::ErrorCode::ERR_READ_BAD_KEY_POINT)
		.value("ERR_SAVE_NOT_LOADED", SMESH_Pattern::ErrorCode::ERR_SAVE_NOT_LOADED)
		.value("ERR_LOAD_EMPTY_SUBMESH", SMESH_Pattern::ErrorCode::ERR_LOAD_EMPTY_SUBMESH)
		.value("ERR_LOADF_NARROW_FACE", SMESH_Pattern::ErrorCode::ERR_LOADF_NARROW_FACE)
		.value("ERR_LOADF_CLOSED_FACE", SMESH_Pattern::ErrorCode::ERR_LOADF_CLOSED_FACE)
		.value("ERR_LOADF_CANT_PROJECT", SMESH_Pattern::ErrorCode::ERR_LOADF_CANT_PROJECT)
		.value("ERR_LOADV_BAD_SHAPE", SMESH_Pattern::ErrorCode::ERR_LOADV_BAD_SHAPE)
		.value("ERR_LOADV_COMPUTE_PARAMS", SMESH_Pattern::ErrorCode::ERR_LOADV_COMPUTE_PARAMS)
		.value("ERR_APPL_NOT_COMPUTED", SMESH_Pattern::ErrorCode::ERR_APPL_NOT_COMPUTED)
		.value("ERR_APPL_NOT_LOADED", SMESH_Pattern::ErrorCode::ERR_APPL_NOT_LOADED)
		.value("ERR_APPL_BAD_DIMENTION", SMESH_Pattern::ErrorCode::ERR_APPL_BAD_DIMENTION)
		.value("ERR_APPL_BAD_NB_VERTICES", SMESH_Pattern::ErrorCode::ERR_APPL_BAD_NB_VERTICES)
		.value("ERR_APPLF_BAD_TOPOLOGY", SMESH_Pattern::ErrorCode::ERR_APPLF_BAD_TOPOLOGY)
		.value("ERR_APPLF_BAD_VERTEX", SMESH_Pattern::ErrorCode::ERR_APPLF_BAD_VERTEX)
		.value("ERR_APPLF_INTERNAL_EEROR", SMESH_Pattern::ErrorCode::ERR_APPLF_INTERNAL_EEROR)
		.value("ERR_APPLV_BAD_SHAPE", SMESH_Pattern::ErrorCode::ERR_APPLV_BAD_SHAPE)
		.value("ERR_APPLF_BAD_FACE_GEOM", SMESH_Pattern::ErrorCode::ERR_APPLF_BAD_FACE_GEOM)
		.value("ERR_MAKEM_NOT_COMPUTED", SMESH_Pattern::ErrorCode::ERR_MAKEM_NOT_COMPUTED)
		.value("ERR_UNEXPECTED", SMESH_Pattern::ErrorCode::ERR_UNEXPECTED)
		.export_values();

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Quadtree.hxx
	py::class_<SMESH_Quadtree, std::unique_ptr<SMESH_Quadtree, Deleter<SMESH_Quadtree>>, SMESH_Tree<Bnd_B2d, 4>> cls_SMESH_Quadtree(mod, "SMESH_Quadtree", "2D tree of anything. Methods to implement in a descendant are: - Bnd_B2d* buildRootBox(); // box of the whole tree - descendant* newChild() const; // a new child instance - void buildChildrenData(); // Fill in data of the children");
	cls_SMESH_Quadtree.def(py::init<>());
	cls_SMESH_Quadtree.def(py::init<SMESH_TreeLimit *>(), py::arg("limit"));
	cls_SMESH_Quadtree.def("maxSize", (double (SMESH_Quadtree::*)() const ) &SMESH_Quadtree::maxSize, "None");
	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_subMeshEventListener.hxx
	py::class_<SMESH_subMeshEventListener, std::unique_ptr<SMESH_subMeshEventListener, Deleter<SMESH_subMeshEventListener>>> cls_SMESH_subMeshEventListener(mod, "SMESH_subMeshEventListener", "A base for objects reacting on submesh events");
	cls_SMESH_subMeshEventListener.def(py::init<bool, const char *>(), py::arg("isDeletable"), py::arg("name"));
	cls_SMESH_subMeshEventListener.def("IsDeletable", (bool (SMESH_subMeshEventListener::*)() const ) &SMESH_subMeshEventListener::IsDeletable, "None");
	cls_SMESH_subMeshEventListener.def("GetName", (const char * (SMESH_subMeshEventListener::*)() const ) &SMESH_subMeshEventListener::GetName, "None");
	cls_SMESH_subMeshEventListener.def("BeforeDelete", (void (SMESH_subMeshEventListener::*)(SMESH_subMesh *, SMESH_subMeshEventListenerData *)) &SMESH_subMeshEventListener::BeforeDelete, "None", py::arg("subMesh"), py::arg("data"));
	cls_SMESH_subMeshEventListener.def("ProcessEvent", [](SMESH_subMeshEventListener &self, const int a0, const int a1, SMESH_subMesh * a2, SMESH_subMeshEventListenerData * a3) -> void { return self.ProcessEvent(a0, a1, a2, a3); }, py::arg("event"), py::arg("eventType"), py::arg("subMesh"), py::arg("data"));
	cls_SMESH_subMeshEventListener.def("ProcessEvent", (void (SMESH_subMeshEventListener::*)(const int, const int, SMESH_subMesh *, SMESH_subMeshEventListenerData *, const SMESH_Hypothesis *)) &SMESH_subMeshEventListener::ProcessEvent, "Do something on a certain event", py::arg("event"), py::arg("eventType"), py::arg("subMesh"), py::arg("data"), py::arg("hyp"));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_subMeshEventListener.hxx
	py::class_<SMESH_subMeshEventListenerData, std::unique_ptr<SMESH_subMeshEventListenerData, Deleter<SMESH_subMeshEventListenerData>>> cls_SMESH_subMeshEventListenerData(mod, "SMESH_subMeshEventListenerData", "Data specific for EventListener and to be stored in a submesh");
	cls_SMESH_subMeshEventListenerData.def(py::init<bool>(), py::arg("isDeletable"));
	cls_SMESH_subMeshEventListenerData.def("IsDeletable", (bool (SMESH_subMeshEventListenerData::*)() const ) &SMESH_subMeshEventListenerData::IsDeletable, "None");
	cls_SMESH_subMeshEventListenerData.def_static("MakeData_", [](SMESH_subMesh * a0) -> SMESH_subMeshEventListenerData * { return SMESH_subMeshEventListenerData::MakeData(a0); }, py::arg("dependentSM"));
	cls_SMESH_subMeshEventListenerData.def_static("MakeData_", (SMESH_subMeshEventListenerData * (*)(SMESH_subMesh *, const int)) &SMESH_subMeshEventListenerData::MakeData, "Create a default listener data.", py::arg("dependentSM"), py::arg("type"));

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_ComputeError.hxx
	// FIXME bind_boost::shared_ptr<SMESH_ComputeError>(mod, "SMESH_ComputeErrorPtr");

	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_TypeDefs.hxx
	// FIXME bind_std::map<const SMDS_MeshElement *, std::list<const SMDS_MeshElement *, std::allocator<const SMDS_MeshElement *> >, TIDCompare, std::allocator<std::pair<const SMDS_MeshElement *const, std::list<const SMDS_MeshElement *, std::allocator<const SMDS_MeshElement *> > > > >(mod, "TElemOfElemListMap");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_TypeDefs.hxx
	// FIXME bind_std::map<const SMDS_MeshElement *, std::list<const SMDS_MeshNode *, std::allocator<const SMDS_MeshNode *> >, TIDCompare, std::allocator<std::pair<const SMDS_MeshElement *const, std::list<const SMDS_MeshNode *, std::allocator<const SMDS_MeshNode *> > > > >(mod, "TElemOfNodeListMap");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_TypeDefs.hxx
	// FIXME bind_std::map<const SMDS_MeshNode *, const SMDS_MeshNode *, TIDCompare, std::allocator<std::pair<const SMDS_MeshNode *const, const SMDS_MeshNode *> > >(mod, "TNodeNodeMap");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_TypeDefs.hxx
	// FIXME bind_std::set<const SMDS_MeshElement *, TIDCompare, std::allocator<const SMDS_MeshElement *> >(mod, "TIDSortedElemSet");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_OctreeNode.hxx
	// FIXME bind_std::set<const SMDS_MeshNode *, TIDCompare, std::allocator<const SMDS_MeshNode *> >(mod, "TIDSortedNodeSet");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_TypeDefs.hxx
	py::class_<SMESH_OrientedLink, std::unique_ptr<SMESH_OrientedLink, Deleter<SMESH_OrientedLink>>, SMESH_TLink> cls_SMESH_OrientedLink(mod, "SMESH_OrientedLink", "SMESH_TLink knowing its orientation");
	cls_SMESH_OrientedLink.def(py::init<const SMDS_MeshNode *, const SMDS_MeshNode *>(), py::arg("n1"), py::arg("n2"));

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_TypeDefs.hxx
	// FIXME bind_boost::shared_ptr<FaceQuadStruct>(mod, "TFaceQuadStructPtr");

	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_TypeDefs.hxx
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_TypeDefs.hxx
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_TypeDefs.hxx
	// FIXME bind_std::vector<uvPtStruct, std::allocator<uvPtStruct> >(mod, "UVPtStructVec");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_TypeDefs.hxx
	other_mod = py::module::import("OCCT.SMDS");
	if (py::hasattr(other_mod, "SMDS_pElement")) {
		mod.attr("SMDS_MeshElementPtr") = other_mod.attr("SMDS_pElement");
	}

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_TypeDefs.hxx
	bind_NCollection_Sequence<const SMDS_MeshElement *>(mod, "SMESH_SequenceOfElemPtr");

	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_TypeDefs.hxx
	other_mod = py::module::import("OCCT.SMDS");
	if (py::hasattr(other_mod, "SMDS_pNode")) {
		mod.attr("SMDS_MeshNodePtr") = other_mod.attr("SMDS_pNode");
	}

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_TypeDefs.hxx
	bind_NCollection_Sequence<const SMDS_MeshNode *>(mod, "SMESH_SequenceOfNode", py::module_local(false));

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Algo.hxx
	// FIXME bind_std::map<SMESH_subMesh *, std::vector<int, std::allocator<int> >, std::less<SMESH_subMesh *>, std::allocator<std::pair<SMESH_subMesh *const, std::vector<int, std::allocator<int> > > > >(mod, "MapShapeNbElems");

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Algo.hxx
	// FIXME bind_std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<SMESH_subMesh *const, std::vector<int, std::allocator<int> > > > > >(mod, "MapShapeNbElemsItr");

	*/

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Controls.hxx
	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Mesh.hxx
	// FIXME bind_std::list<int, std::allocator<int> >(mod, "TListOfInt");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Mesh.hxx
	// FIXME bind_std::list<std::list<int, std::allocator<int> >, std::allocator<std::list<int, std::allocator<int> > > >(mod, "TListOfListOfInt");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Gen.hxx
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Gen.hxx
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_Gen.hxx
	// FIXME bind_std::set<int, std::less<int>, std::allocator<int> >(mod, "TSetOfInt");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_MesherHelper.hxx
	// FIXME bind_std::map<SMESH_TLink, const SMDS_MeshNode *, std::less<SMESH_TLink>, std::allocator<std::pair<const SMESH_TLink, const SMDS_MeshNode *> > >(mod, "TLinkNodeMap");

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_MesherHelper.hxx
	// FIXME bind_std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<const SMESH_TLink, const SMDS_MeshNode *> > > >(mod, "ItTLinkNode");

	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_MesherHelper.hxx
	bind_SMDS_Iterator<const TopoDS_Shape *>(mod, "PShapeIterator");

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_MesherHelper.hxx
	// FIXME bind_boost::shared_ptr<SMDS_Iterator<const TopoDS_Shape *> >(mod, "PShapeIteratorPtr");

	*/

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_MesherHelper.hxx
	// FIXME bind_std::vector<const SMDS_MeshNode *, std::allocator<const SMDS_MeshNode *> >(mod, "TNodeColumn");

	*/

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_MesherHelper.hxx
	// FIXME bind_std::map<double, std::vector<const SMDS_MeshNode *, std::allocator<const SMDS_MeshNode *> >, std::less<double>, std::allocator<std::pair<const double, std::vector<const SMDS_MeshNode *, std::allocator<const SMDS_MeshNode *> > > > >(mod, "TParam2ColumnMap");

	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_MesherHelper.hxx
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_OctreeNode.hxx
	bind_SMDS_Iterator<SMESH_OctreeNode *>(mod, "SMESH_OctreeNodeIterator");

	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_OctreeNode.hxx
	// FIXME bind_boost::shared_ptr<SMDS_Iterator<SMESH_OctreeNode *> >(mod, "SMESH_OctreeNodeIteratorPtr");

	*/

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_subMesh.hxx
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_subMesh.hxx
	/* FIXME
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\SMESH_subMesh.hxx
	// FIXME bind_boost::shared_ptr<SMDS_Iterator<SMESH_subMesh *> >(mod, "SMESH_subMeshIteratorPtr");

	*/

	// Group iterator
	bind_SMDS_Iterator<SMESH_Group *>(mod, "SMESH_GroupIterator");

	// SMESH_MeshEditor::TListOfListOfNodes
	bind_list<std::list<const SMDS_MeshNode *>>(cls_SMESH_MeshEditor, "TListOfListOfNodes");

	// SMESH_MeshEditor::TListOfListOfElementsID
	bind_list<std::list<int>>(cls_SMESH_MeshEditor, "TListOfListOfElementsID");

	// SMESH_MeshEditor::PGroupIDs
	bind_list<int>(cls_SMESH_MeshEditor, "PGroupIDs");
}
