#include <pyOCCT_Common.hpp>

#include <SMESH_subMesh.hxx>

#include <TopoDS_Face.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <TopoDS_Edge.hxx>
#include <BLSURFPlugin_Attractor.hxx>
#include <SMESH_Hypothesis.hxx>
#include <SMESH_Gen.hxx>
#include <BLSURFPlugin_Hypothesis.hxx>
#include <SMESH_Mesh.hxx>
#include <SMESH_Algo.hxx>
#include <SMESH_MesherHelper.hxx>
#include <BLSURFPlugin_BLSURF.hxx>

PYBIND11_MODULE(BLSURFPlugin, mod) {

	// IMPORT
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.SMESH");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\BLSURFPlugin_Attractor.hxx
	py::class_<BLSURFPlugin_Attractor, std::unique_ptr<BLSURFPlugin_Attractor, Deleter<BLSURFPlugin_Attractor>>> cls_BLSURFPlugin_Attractor(mod, "BLSURFPlugin_Attractor", "None");
	cls_BLSURFPlugin_Attractor.def(py::init<>());
	cls_BLSURFPlugin_Attractor.def(py::init<const TopoDS_Face &, const TopoDS_Shape &, const std::string &>(), py::arg("Face"), py::arg("Attractor"), py::arg("attEntry"));
	cls_BLSURFPlugin_Attractor.def("init", (bool (BLSURFPlugin_Attractor::*)()) &BLSURFPlugin_Attractor::init, "None");
	cls_BLSURFPlugin_Attractor.def("edgeInit", (void (BLSURFPlugin_Attractor::*)(opencascade::handle<Geom_Surface>, const TopoDS_Edge &)) &BLSURFPlugin_Attractor::edgeInit, "None", py::arg("aSurf"), py::arg("anEdge"));
	cls_BLSURFPlugin_Attractor.def("GetSize", (double (BLSURFPlugin_Attractor::*)(double, double)) &BLSURFPlugin_Attractor::GetSize, "None", py::arg("u"), py::arg("v"));
	cls_BLSURFPlugin_Attractor.def("GetFace", (TopoDS_Face (BLSURFPlugin_Attractor::*)() const ) &BLSURFPlugin_Attractor::GetFace, "None");
	cls_BLSURFPlugin_Attractor.def("GetAttractorShape", (TopoDS_Shape (BLSURFPlugin_Attractor::*)() const ) &BLSURFPlugin_Attractor::GetAttractorShape, "None");
	cls_BLSURFPlugin_Attractor.def("GetAttractorEntry", (std::string (BLSURFPlugin_Attractor::*)() const ) &BLSURFPlugin_Attractor::GetAttractorEntry, "None");
	cls_BLSURFPlugin_Attractor.def("GetParameters", (std::vector<double> (BLSURFPlugin_Attractor::*)() const ) &BLSURFPlugin_Attractor::GetParameters, "None");
	cls_BLSURFPlugin_Attractor.def("SetParameters", (void (BLSURFPlugin_Attractor::*)(double, double, double, double)) &BLSURFPlugin_Attractor::SetParameters, "None", py::arg("Start_Size"), py::arg("End_Size"), py::arg("Action_Radius"), py::arg("Constant_Radius"));
	cls_BLSURFPlugin_Attractor.def("SetType", (void (BLSURFPlugin_Attractor::*)(int)) &BLSURFPlugin_Attractor::SetType, "None", py::arg("type"));
	cls_BLSURFPlugin_Attractor.def("BuildMap", (void (BLSURFPlugin_Attractor::*)()) &BLSURFPlugin_Attractor::BuildMap, "None");
	cls_BLSURFPlugin_Attractor.def("IsMapBuilt", (bool (BLSURFPlugin_Attractor::*)() const ) &BLSURFPlugin_Attractor::IsMapBuilt, "None");
	cls_BLSURFPlugin_Attractor.def("Empty", (bool (BLSURFPlugin_Attractor::*)() const ) &BLSURFPlugin_Attractor::Empty, "None");

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\BLSURFPlugin_Hypothesis.hxx
	py::class_<BLSURFPlugin_Hypothesis, std::unique_ptr<BLSURFPlugin_Hypothesis, py::nodelete>, SMESH_Hypothesis> cls_BLSURFPlugin_Hypothesis(mod, "BLSURFPlugin_Hypothesis", "None");
	cls_BLSURFPlugin_Hypothesis.def(py::init<int, int, SMESH_Gen *, bool>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"), py::arg("hasgeom"));
	cls_BLSURFPlugin_Hypothesis.def_static("GetHypType_", (const char * (*)(bool)) &BLSURFPlugin_Hypothesis::GetHypType, "None", py::arg("hasgeom"));
	cls_BLSURFPlugin_Hypothesis.def("entryToShape", (TopoDS_Shape (BLSURFPlugin_Hypothesis::*)(std::string)) &BLSURFPlugin_Hypothesis::entryToShape, "None", py::arg("entry"));
	cls_BLSURFPlugin_Hypothesis.def("SetPhysicalMesh", (void (BLSURFPlugin_Hypothesis::*)(BLSURFPlugin_Hypothesis::PhysicalMesh)) &BLSURFPlugin_Hypothesis::SetPhysicalMesh, "None", py::arg("thePhysicalMesh"));
	cls_BLSURFPlugin_Hypothesis.def("GetPhysicalMesh", (BLSURFPlugin_Hypothesis::PhysicalMesh (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetPhysicalMesh, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetGeometricMesh", (void (BLSURFPlugin_Hypothesis::*)(BLSURFPlugin_Hypothesis::GeometricMesh)) &BLSURFPlugin_Hypothesis::SetGeometricMesh, "None", py::arg("theGeometricMesh"));
	cls_BLSURFPlugin_Hypothesis.def("GetGeometricMesh", (BLSURFPlugin_Hypothesis::GeometricMesh (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetGeometricMesh, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetPhySize", [](BLSURFPlugin_Hypothesis &self, double a0) -> void { return self.SetPhySize(a0); }, py::arg("thePhySize"));
	cls_BLSURFPlugin_Hypothesis.def("SetPhySize", (void (BLSURFPlugin_Hypothesis::*)(double, bool)) &BLSURFPlugin_Hypothesis::SetPhySize, "None", py::arg("thePhySize"), py::arg("isRelative"));
	cls_BLSURFPlugin_Hypothesis.def("GetPhySize", (double (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetPhySize, "None");
	cls_BLSURFPlugin_Hypothesis.def("IsPhySizeRel", (bool (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::IsPhySizeRel, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetMinSize", [](BLSURFPlugin_Hypothesis &self, double a0) -> void { return self.SetMinSize(a0); }, py::arg("theMinSize"));
	cls_BLSURFPlugin_Hypothesis.def("SetMinSize", (void (BLSURFPlugin_Hypothesis::*)(double, bool)) &BLSURFPlugin_Hypothesis::SetMinSize, "None", py::arg("theMinSize"), py::arg("isRelative"));
	cls_BLSURFPlugin_Hypothesis.def("GetMinSize", (double (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetMinSize, "None");
	cls_BLSURFPlugin_Hypothesis.def("IsMinSizeRel", (bool (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::IsMinSizeRel, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetMaxSize", [](BLSURFPlugin_Hypothesis &self, double a0) -> void { return self.SetMaxSize(a0); }, py::arg("theMaxSize"));
	cls_BLSURFPlugin_Hypothesis.def("SetMaxSize", (void (BLSURFPlugin_Hypothesis::*)(double, bool)) &BLSURFPlugin_Hypothesis::SetMaxSize, "None", py::arg("theMaxSize"), py::arg("isRelative"));
	cls_BLSURFPlugin_Hypothesis.def("GetMaxSize", (double (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetMaxSize, "None");
	cls_BLSURFPlugin_Hypothesis.def("IsMaxSizeRel", (bool (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::IsMaxSizeRel, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetUseGradation", (void (BLSURFPlugin_Hypothesis::*)(bool)) &BLSURFPlugin_Hypothesis::SetUseGradation, "None", py::arg("toUse"));
	cls_BLSURFPlugin_Hypothesis.def("GetUseGradation", (bool (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetUseGradation, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetGradation", (void (BLSURFPlugin_Hypothesis::*)(double)) &BLSURFPlugin_Hypothesis::SetGradation, "None", py::arg("theGradation"));
	cls_BLSURFPlugin_Hypothesis.def("GetGradation", (double (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetGradation, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetUseVolumeGradation", (void (BLSURFPlugin_Hypothesis::*)(bool)) &BLSURFPlugin_Hypothesis::SetUseVolumeGradation, "None", py::arg("toUse"));
	cls_BLSURFPlugin_Hypothesis.def("GetUseVolumeGradation", (bool (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetUseVolumeGradation, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetVolumeGradation", (void (BLSURFPlugin_Hypothesis::*)(double)) &BLSURFPlugin_Hypothesis::SetVolumeGradation, "None", py::arg("theGradation"));
	cls_BLSURFPlugin_Hypothesis.def("GetVolumeGradation", (double (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetVolumeGradation, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetQuadAllowed", (void (BLSURFPlugin_Hypothesis::*)(bool)) &BLSURFPlugin_Hypothesis::SetQuadAllowed, "None", py::arg("theVal"));
	cls_BLSURFPlugin_Hypothesis.def("GetQuadAllowed", (bool (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetQuadAllowed, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetAngleMesh", (void (BLSURFPlugin_Hypothesis::*)(double)) &BLSURFPlugin_Hypothesis::SetAngleMesh, "None", py::arg("theAngle"));
	cls_BLSURFPlugin_Hypothesis.def("GetAngleMesh", (double (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetAngleMesh, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetChordalError", (void (BLSURFPlugin_Hypothesis::*)(double)) &BLSURFPlugin_Hypothesis::SetChordalError, "None", py::arg("theDistance"));
	cls_BLSURFPlugin_Hypothesis.def("GetChordalError", (double (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetChordalError, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetAnisotropic", (void (BLSURFPlugin_Hypothesis::*)(bool)) &BLSURFPlugin_Hypothesis::SetAnisotropic, "None", py::arg("theVal"));
	cls_BLSURFPlugin_Hypothesis.def("GetAnisotropic", (bool (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetAnisotropic, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetAnisotropicRatio", (void (BLSURFPlugin_Hypothesis::*)(double)) &BLSURFPlugin_Hypothesis::SetAnisotropicRatio, "None", py::arg("theVal"));
	cls_BLSURFPlugin_Hypothesis.def("GetAnisotropicRatio", (double (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetAnisotropicRatio, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetRemoveTinyEdges", (void (BLSURFPlugin_Hypothesis::*)(bool)) &BLSURFPlugin_Hypothesis::SetRemoveTinyEdges, "None", py::arg("theVal"));
	cls_BLSURFPlugin_Hypothesis.def("GetRemoveTinyEdges", (bool (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetRemoveTinyEdges, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetTinyEdgeLength", (void (BLSURFPlugin_Hypothesis::*)(double)) &BLSURFPlugin_Hypothesis::SetTinyEdgeLength, "None", py::arg("theVal"));
	cls_BLSURFPlugin_Hypothesis.def("GetTinyEdgeLength", (double (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetTinyEdgeLength, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetOptimiseTinyEdges", (void (BLSURFPlugin_Hypothesis::*)(bool)) &BLSURFPlugin_Hypothesis::SetOptimiseTinyEdges, "None", py::arg("theVal"));
	cls_BLSURFPlugin_Hypothesis.def("GetOptimiseTinyEdges", (bool (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetOptimiseTinyEdges, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetTinyEdgeOptimisationLength", (void (BLSURFPlugin_Hypothesis::*)(double)) &BLSURFPlugin_Hypothesis::SetTinyEdgeOptimisationLength, "None", py::arg("theVal"));
	cls_BLSURFPlugin_Hypothesis.def("GetTinyEdgeOptimisationLength", (double (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetTinyEdgeOptimisationLength, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetCorrectSurfaceIntersection", (void (BLSURFPlugin_Hypothesis::*)(bool)) &BLSURFPlugin_Hypothesis::SetCorrectSurfaceIntersection, "None", py::arg("theVal"));
	cls_BLSURFPlugin_Hypothesis.def("GetCorrectSurfaceIntersection", (bool (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetCorrectSurfaceIntersection, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetCorrectSurfaceIntersectionMaxCost", (void (BLSURFPlugin_Hypothesis::*)(double)) &BLSURFPlugin_Hypothesis::SetCorrectSurfaceIntersectionMaxCost, "None", py::arg("theVal"));
	cls_BLSURFPlugin_Hypothesis.def("GetCorrectSurfaceIntersectionMaxCost", (double (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetCorrectSurfaceIntersectionMaxCost, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetBadElementRemoval", (void (BLSURFPlugin_Hypothesis::*)(bool)) &BLSURFPlugin_Hypothesis::SetBadElementRemoval, "None", py::arg("theVal"));
	cls_BLSURFPlugin_Hypothesis.def("GetBadElementRemoval", (bool (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetBadElementRemoval, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetBadElementAspectRatio", (void (BLSURFPlugin_Hypothesis::*)(double)) &BLSURFPlugin_Hypothesis::SetBadElementAspectRatio, "None", py::arg("theVal"));
	cls_BLSURFPlugin_Hypothesis.def("GetBadElementAspectRatio", (double (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetBadElementAspectRatio, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetOptimizeMesh", (void (BLSURFPlugin_Hypothesis::*)(bool)) &BLSURFPlugin_Hypothesis::SetOptimizeMesh, "None", py::arg("theVal"));
	cls_BLSURFPlugin_Hypothesis.def("GetOptimizeMesh", (bool (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetOptimizeMesh, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetQuadraticMesh", (void (BLSURFPlugin_Hypothesis::*)(bool)) &BLSURFPlugin_Hypothesis::SetQuadraticMesh, "None", py::arg("theVal"));
	cls_BLSURFPlugin_Hypothesis.def("GetQuadraticMesh", (bool (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetQuadraticMesh, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetTopology", (void (BLSURFPlugin_Hypothesis::*)(BLSURFPlugin_Hypothesis::Topology)) &BLSURFPlugin_Hypothesis::SetTopology, "None", py::arg("theTopology"));
	cls_BLSURFPlugin_Hypothesis.def("GetTopology", (BLSURFPlugin_Hypothesis::Topology (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetTopology, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetVerbosity", (void (BLSURFPlugin_Hypothesis::*)(int)) &BLSURFPlugin_Hypothesis::SetVerbosity, "None", py::arg("theVal"));
	cls_BLSURFPlugin_Hypothesis.def("GetVerbosity", (int (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetVerbosity, "None");
	cls_BLSURFPlugin_Hypothesis.def("ClearEntry", [](BLSURFPlugin_Hypothesis &self, const std::string & a0) -> void { return self.ClearEntry(a0); }, py::arg("entry"));
	cls_BLSURFPlugin_Hypothesis.def("ClearEntry", (void (BLSURFPlugin_Hypothesis::*)(const std::string &, const char *)) &BLSURFPlugin_Hypothesis::ClearEntry, "None", py::arg("entry"), py::arg("attEntry"));
	cls_BLSURFPlugin_Hypothesis.def("ClearSizeMaps", (void (BLSURFPlugin_Hypothesis::*)()) &BLSURFPlugin_Hypothesis::ClearSizeMaps, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetEnforceCadEdgesSize", (void (BLSURFPlugin_Hypothesis::*)(bool)) &BLSURFPlugin_Hypothesis::SetEnforceCadEdgesSize, "None", py::arg("toEnforce"));
	cls_BLSURFPlugin_Hypothesis.def("GetEnforceCadEdgesSize", (bool (BLSURFPlugin_Hypothesis::*)()) &BLSURFPlugin_Hypothesis::GetEnforceCadEdgesSize, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetJacobianRectificationRespectGeometry", (void (BLSURFPlugin_Hypothesis::*)(bool)) &BLSURFPlugin_Hypothesis::SetJacobianRectificationRespectGeometry, "None", py::arg("allowRectification"));
	cls_BLSURFPlugin_Hypothesis.def("GetJacobianRectificationRespectGeometry", (bool (BLSURFPlugin_Hypothesis::*)()) &BLSURFPlugin_Hypothesis::GetJacobianRectificationRespectGeometry, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetUseDeprecatedPatchMesher", (void (BLSURFPlugin_Hypothesis::*)(bool)) &BLSURFPlugin_Hypothesis::SetUseDeprecatedPatchMesher, "None", py::arg("useDeprecatedPatchMesher"));
	cls_BLSURFPlugin_Hypothesis.def("GetUseDeprecatedPatchMesher", (bool (BLSURFPlugin_Hypothesis::*)()) &BLSURFPlugin_Hypothesis::GetUseDeprecatedPatchMesher, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetJacobianRectification", (void (BLSURFPlugin_Hypothesis::*)(bool)) &BLSURFPlugin_Hypothesis::SetJacobianRectification, "None", py::arg("allowRectification"));
	cls_BLSURFPlugin_Hypothesis.def("GetJacobianRectification", (bool (BLSURFPlugin_Hypothesis::*)()) &BLSURFPlugin_Hypothesis::GetJacobianRectification, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetMaxNumberOfPointsPerPatch", (void (BLSURFPlugin_Hypothesis::*)(int)) &BLSURFPlugin_Hypothesis::SetMaxNumberOfPointsPerPatch, "None", py::arg("nb"));
	cls_BLSURFPlugin_Hypothesis.def("GetMaxNumberOfPointsPerPatch", (int (BLSURFPlugin_Hypothesis::*)()) &BLSURFPlugin_Hypothesis::GetMaxNumberOfPointsPerPatch, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetMaxNumberOfThreads", (void (BLSURFPlugin_Hypothesis::*)(int)) &BLSURFPlugin_Hypothesis::SetMaxNumberOfThreads, "None", py::arg("nb"));
	cls_BLSURFPlugin_Hypothesis.def("GetMaxNumberOfThreads", (int (BLSURFPlugin_Hypothesis::*)()) &BLSURFPlugin_Hypothesis::GetMaxNumberOfThreads, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetRespectGeometry", (void (BLSURFPlugin_Hypothesis::*)(bool)) &BLSURFPlugin_Hypothesis::SetRespectGeometry, "None", py::arg("toRespect"));
	cls_BLSURFPlugin_Hypothesis.def("GetRespectGeometry", (bool (BLSURFPlugin_Hypothesis::*)()) &BLSURFPlugin_Hypothesis::GetRespectGeometry, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetTinyEdgesAvoidSurfaceIntersections", (void (BLSURFPlugin_Hypothesis::*)(bool)) &BLSURFPlugin_Hypothesis::SetTinyEdgesAvoidSurfaceIntersections, "None", py::arg("toAvoidIntersection"));
	cls_BLSURFPlugin_Hypothesis.def("GetTinyEdgesAvoidSurfaceIntersections", (bool (BLSURFPlugin_Hypothesis::*)()) &BLSURFPlugin_Hypothesis::GetTinyEdgesAvoidSurfaceIntersections, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetClosedGeometry", (void (BLSURFPlugin_Hypothesis::*)(bool)) &BLSURFPlugin_Hypothesis::SetClosedGeometry, "None", py::arg("isClosed"));
	cls_BLSURFPlugin_Hypothesis.def("GetClosedGeometry", (bool (BLSURFPlugin_Hypothesis::*)()) &BLSURFPlugin_Hypothesis::GetClosedGeometry, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetDebug", (void (BLSURFPlugin_Hypothesis::*)(bool)) &BLSURFPlugin_Hypothesis::SetDebug, "None", py::arg("isDebug"));
	cls_BLSURFPlugin_Hypothesis.def("GetDebug", (bool (BLSURFPlugin_Hypothesis::*)()) &BLSURFPlugin_Hypothesis::GetDebug, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetPeriodicTolerance", (void (BLSURFPlugin_Hypothesis::*)(double)) &BLSURFPlugin_Hypothesis::SetPeriodicTolerance, "None", py::arg("tol"));
	cls_BLSURFPlugin_Hypothesis.def("GetPeriodicTolerance", (double (BLSURFPlugin_Hypothesis::*)()) &BLSURFPlugin_Hypothesis::GetPeriodicTolerance, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetRequiredEntities", (void (BLSURFPlugin_Hypothesis::*)(const std::string &)) &BLSURFPlugin_Hypothesis::SetRequiredEntities, "None", py::arg("howToTreat"));
	cls_BLSURFPlugin_Hypothesis.def("GetRequiredEntities", (std::string (BLSURFPlugin_Hypothesis::*)()) &BLSURFPlugin_Hypothesis::GetRequiredEntities, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetSewingTolerance", (void (BLSURFPlugin_Hypothesis::*)(double)) &BLSURFPlugin_Hypothesis::SetSewingTolerance, "None", py::arg("tol"));
	cls_BLSURFPlugin_Hypothesis.def("GetSewingTolerance", (double (BLSURFPlugin_Hypothesis::*)()) &BLSURFPlugin_Hypothesis::GetSewingTolerance, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetTags", (void (BLSURFPlugin_Hypothesis::*)(const std::string &)) &BLSURFPlugin_Hypothesis::SetTags, "None", py::arg("howToTreat"));
	cls_BLSURFPlugin_Hypothesis.def("GetTags", (std::string (BLSURFPlugin_Hypothesis::*)()) &BLSURFPlugin_Hypothesis::GetTags, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetHyperPatches", (void (BLSURFPlugin_Hypothesis::*)(const BLSURFPlugin_Hypothesis::THyperPatchList &)) &BLSURFPlugin_Hypothesis::SetHyperPatches, "None", py::arg("hpl"));
	cls_BLSURFPlugin_Hypothesis.def("GetHyperPatches", (const BLSURFPlugin_Hypothesis::THyperPatchList & (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetHyperPatches, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetHyperPatchTag_", [](int a0, const BLSURFPlugin_Hypothesis * a1) -> int { return BLSURFPlugin_Hypothesis::GetHyperPatchTag(a0, a1); }, py::arg("faceTag"), py::arg("hyp"));
	cls_BLSURFPlugin_Hypothesis.def_static("GetHyperPatchTag_", (int (*)(int, const BLSURFPlugin_Hypothesis *, int *)) &BLSURFPlugin_Hypothesis::GetHyperPatchTag, "None", py::arg("faceTag"), py::arg("hyp"), py::arg("iPatch"));
	cls_BLSURFPlugin_Hypothesis.def("SetPreCADMergeEdges", (void (BLSURFPlugin_Hypothesis::*)(bool)) &BLSURFPlugin_Hypothesis::SetPreCADMergeEdges, "None", py::arg("theVal"));
	cls_BLSURFPlugin_Hypothesis.def("GetPreCADMergeEdges", (bool (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetPreCADMergeEdges, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetPreCADRemoveDuplicateCADFaces", (void (BLSURFPlugin_Hypothesis::*)(bool)) &BLSURFPlugin_Hypothesis::SetPreCADRemoveDuplicateCADFaces, "None", py::arg("theVal"));
	cls_BLSURFPlugin_Hypothesis.def("GetPreCADRemoveDuplicateCADFaces", (bool (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetPreCADRemoveDuplicateCADFaces, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetPreCADProcess3DTopology", (void (BLSURFPlugin_Hypothesis::*)(bool)) &BLSURFPlugin_Hypothesis::SetPreCADProcess3DTopology, "None", py::arg("theVal"));
	cls_BLSURFPlugin_Hypothesis.def("GetPreCADProcess3DTopology", (bool (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetPreCADProcess3DTopology, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetPreCADDiscardInput", (void (BLSURFPlugin_Hypothesis::*)(bool)) &BLSURFPlugin_Hypothesis::SetPreCADDiscardInput, "None", py::arg("theVal"));
	cls_BLSURFPlugin_Hypothesis.def("GetPreCADDiscardInput", (bool (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetPreCADDiscardInput, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("HasPreCADOptions_", (bool (*)(const BLSURFPlugin_Hypothesis *)) &BLSURFPlugin_Hypothesis::HasPreCADOptions, "None", py::arg("hyp"));
	cls_BLSURFPlugin_Hypothesis.def("SetSizeMapEntry", (void (BLSURFPlugin_Hypothesis::*)(const std::string &, const std::string &)) &BLSURFPlugin_Hypothesis::SetSizeMapEntry, "None", py::arg("entry"), py::arg("sizeMap"));
	cls_BLSURFPlugin_Hypothesis.def("GetSizeMapEntry", (std::string (BLSURFPlugin_Hypothesis::*)(const std::string &)) &BLSURFPlugin_Hypothesis::GetSizeMapEntry, "None", py::arg("entry"));
	cls_BLSURFPlugin_Hypothesis.def("_GetSizeMapEntries", (const BLSURFPlugin_Hypothesis::TSizeMap & (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::_GetSizeMapEntries, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetSizeMapEntries_", (BLSURFPlugin_Hypothesis::TSizeMap (*)(const BLSURFPlugin_Hypothesis *)) &BLSURFPlugin_Hypothesis::GetSizeMapEntries, "Return the size maps", py::arg("hyp"));
	cls_BLSURFPlugin_Hypothesis.def("SetAttractorEntry", (void (BLSURFPlugin_Hypothesis::*)(const std::string &, const std::string &)) &BLSURFPlugin_Hypothesis::SetAttractorEntry, "None", py::arg("entry"), py::arg("attractor"));
	cls_BLSURFPlugin_Hypothesis.def("GetAttractorEntry", (std::string (BLSURFPlugin_Hypothesis::*)(const std::string &)) &BLSURFPlugin_Hypothesis::GetAttractorEntry, "None", py::arg("entry"));
	cls_BLSURFPlugin_Hypothesis.def("_GetAttractorEntries", (const BLSURFPlugin_Hypothesis::TSizeMap & (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::_GetAttractorEntries, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetAttractorEntries_", (BLSURFPlugin_Hypothesis::TSizeMap (*)(const BLSURFPlugin_Hypothesis *)) &BLSURFPlugin_Hypothesis::GetAttractorEntries, "Return the attractors", py::arg("hyp"));
	cls_BLSURFPlugin_Hypothesis.def("SetClassAttractorEntry", (void (BLSURFPlugin_Hypothesis::*)(const std::string &, const std::string &, double, double, double, double)) &BLSURFPlugin_Hypothesis::SetClassAttractorEntry, "None", py::arg("entry"), py::arg("att_entry"), py::arg("StartSize"), py::arg("EndSize"), py::arg("ActionRadius"), py::arg("ConstantRadius"));
	cls_BLSURFPlugin_Hypothesis.def("GetClassAttractorEntry", (std::string (BLSURFPlugin_Hypothesis::*)(const std::string &)) &BLSURFPlugin_Hypothesis::GetClassAttractorEntry, "None", py::arg("entry"));
	cls_BLSURFPlugin_Hypothesis.def("_GetClassAttractorEntries", (const BLSURFPlugin_Hypothesis::TAttractorMap & (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::_GetClassAttractorEntries, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetClassAttractorEntries_", (BLSURFPlugin_Hypothesis::TAttractorMap (*)(const BLSURFPlugin_Hypothesis *)) &BLSURFPlugin_Hypothesis::GetClassAttractorEntries, "Return the attractors entries", py::arg("hyp"));
	cls_BLSURFPlugin_Hypothesis.def("SetEnforcedVertex", [](BLSURFPlugin_Hypothesis &self, BLSURFPlugin_Hypothesis::TEntry a0, BLSURFPlugin_Hypothesis::TEnfName a1, BLSURFPlugin_Hypothesis::TEntry a2, BLSURFPlugin_Hypothesis::TEnfGroupName a3) -> bool { return self.SetEnforcedVertex(a0, a1, a2, a3); }, py::arg("theFaceEntry"), py::arg("theVertexName"), py::arg("theVertexEntry"), py::arg("theGroupName"));
	cls_BLSURFPlugin_Hypothesis.def("SetEnforcedVertex", [](BLSURFPlugin_Hypothesis &self, BLSURFPlugin_Hypothesis::TEntry a0, BLSURFPlugin_Hypothesis::TEnfName a1, BLSURFPlugin_Hypothesis::TEntry a2, BLSURFPlugin_Hypothesis::TEnfGroupName a3, double a4) -> bool { return self.SetEnforcedVertex(a0, a1, a2, a3, a4); }, py::arg("theFaceEntry"), py::arg("theVertexName"), py::arg("theVertexEntry"), py::arg("theGroupName"), py::arg("x"));
	cls_BLSURFPlugin_Hypothesis.def("SetEnforcedVertex", [](BLSURFPlugin_Hypothesis &self, BLSURFPlugin_Hypothesis::TEntry a0, BLSURFPlugin_Hypothesis::TEnfName a1, BLSURFPlugin_Hypothesis::TEntry a2, BLSURFPlugin_Hypothesis::TEnfGroupName a3, double a4, double a5) -> bool { return self.SetEnforcedVertex(a0, a1, a2, a3, a4, a5); }, py::arg("theFaceEntry"), py::arg("theVertexName"), py::arg("theVertexEntry"), py::arg("theGroupName"), py::arg("x"), py::arg("y"));
	cls_BLSURFPlugin_Hypothesis.def("SetEnforcedVertex", (bool (BLSURFPlugin_Hypothesis::*)(BLSURFPlugin_Hypothesis::TEntry, BLSURFPlugin_Hypothesis::TEnfName, BLSURFPlugin_Hypothesis::TEntry, BLSURFPlugin_Hypothesis::TEnfGroupName, double, double, double)) &BLSURFPlugin_Hypothesis::SetEnforcedVertex, "None", py::arg("theFaceEntry"), py::arg("theVertexName"), py::arg("theVertexEntry"), py::arg("theGroupName"), py::arg("x"), py::arg("y"), py::arg("z"));
	cls_BLSURFPlugin_Hypothesis.def("GetEnfVertexList", (BLSURFPlugin_Hypothesis::TEnfVertexList (BLSURFPlugin_Hypothesis::*)(const BLSURFPlugin_Hypothesis::TEntry &)) &BLSURFPlugin_Hypothesis::GetEnfVertexList, "None", py::arg("theFaceEntry"));
	cls_BLSURFPlugin_Hypothesis.def("GetEnfVertexCoordsList", (BLSURFPlugin_Hypothesis::TEnfVertexCoordsList (BLSURFPlugin_Hypothesis::*)(const BLSURFPlugin_Hypothesis::TEntry &)) &BLSURFPlugin_Hypothesis::GetEnfVertexCoordsList, "None", py::arg("theFaceEntry"));
	cls_BLSURFPlugin_Hypothesis.def("GetEnfVertexEntryList", (BLSURFPlugin_Hypothesis::TEntryList (BLSURFPlugin_Hypothesis::*)(const BLSURFPlugin_Hypothesis::TEntry &)) &BLSURFPlugin_Hypothesis::GetEnfVertexEntryList, "None", py::arg("theFaceEntry"));
	cls_BLSURFPlugin_Hypothesis.def("GetEnfVertex", (BLSURFPlugin_Hypothesis::TEnfVertex * (BLSURFPlugin_Hypothesis::*)(BLSURFPlugin_Hypothesis::TEnfVertexCoords)) &BLSURFPlugin_Hypothesis::GetEnfVertex, "None", py::arg("coords"));
	cls_BLSURFPlugin_Hypothesis.def("GetEnfVertex", (BLSURFPlugin_Hypothesis::TEnfVertex * (BLSURFPlugin_Hypothesis::*)(const BLSURFPlugin_Hypothesis::TEntry &)) &BLSURFPlugin_Hypothesis::GetEnfVertex, "None", py::arg("theEnfVertexEntry"));
	cls_BLSURFPlugin_Hypothesis.def("AddEnfVertexNodeID", (void (BLSURFPlugin_Hypothesis::*)(BLSURFPlugin_Hypothesis::TEnfGroupName, int)) &BLSURFPlugin_Hypothesis::AddEnfVertexNodeID, "None", py::arg("theGroupName"), py::arg("theNodeID"));
	cls_BLSURFPlugin_Hypothesis.def("GetEnfVertexNodeIDs", (std::set<int> (BLSURFPlugin_Hypothesis::*)(BLSURFPlugin_Hypothesis::TEnfGroupName)) &BLSURFPlugin_Hypothesis::GetEnfVertexNodeIDs, "None", py::arg("theGroupName"));
	cls_BLSURFPlugin_Hypothesis.def("RemoveEnfVertexNodeID", (void (BLSURFPlugin_Hypothesis::*)(BLSURFPlugin_Hypothesis::TEnfGroupName, int)) &BLSURFPlugin_Hypothesis::RemoveEnfVertexNodeID, "None", py::arg("theGroupName"), py::arg("theNodeID"));
	cls_BLSURFPlugin_Hypothesis.def("ClearEnforcedVertex", [](BLSURFPlugin_Hypothesis &self, const BLSURFPlugin_Hypothesis::TEntry & a0) -> bool { return self.ClearEnforcedVertex(a0); }, py::arg("theFaceEntry"));
	cls_BLSURFPlugin_Hypothesis.def("ClearEnforcedVertex", [](BLSURFPlugin_Hypothesis &self, const BLSURFPlugin_Hypothesis::TEntry & a0, double a1) -> bool { return self.ClearEnforcedVertex(a0, a1); }, py::arg("theFaceEntry"), py::arg("x"));
	cls_BLSURFPlugin_Hypothesis.def("ClearEnforcedVertex", [](BLSURFPlugin_Hypothesis &self, const BLSURFPlugin_Hypothesis::TEntry & a0, double a1, double a2) -> bool { return self.ClearEnforcedVertex(a0, a1, a2); }, py::arg("theFaceEntry"), py::arg("x"), py::arg("y"));
	cls_BLSURFPlugin_Hypothesis.def("ClearEnforcedVertex", [](BLSURFPlugin_Hypothesis &self, const BLSURFPlugin_Hypothesis::TEntry & a0, double a1, double a2, double a3) -> bool { return self.ClearEnforcedVertex(a0, a1, a2, a3); }, py::arg("theFaceEntry"), py::arg("x"), py::arg("y"), py::arg("z"));
	cls_BLSURFPlugin_Hypothesis.def("ClearEnforcedVertex", (bool (BLSURFPlugin_Hypothesis::*)(const BLSURFPlugin_Hypothesis::TEntry &, double, double, double, const BLSURFPlugin_Hypothesis::TEntry &)) &BLSURFPlugin_Hypothesis::ClearEnforcedVertex, "None", py::arg("theFaceEntry"), py::arg("x"), py::arg("y"), py::arg("z"), py::arg("theVertexEntry"));
	cls_BLSURFPlugin_Hypothesis.def("ClearEnforcedVertices", (bool (BLSURFPlugin_Hypothesis::*)(const BLSURFPlugin_Hypothesis::TEntry &)) &BLSURFPlugin_Hypothesis::ClearEnforcedVertices, "None", py::arg("theFaceEntry"));
	cls_BLSURFPlugin_Hypothesis.def("ClearAllEnforcedVertices", (void (BLSURFPlugin_Hypothesis::*)()) &BLSURFPlugin_Hypothesis::ClearAllEnforcedVertices, "None");
	cls_BLSURFPlugin_Hypothesis.def("_GetAllEnforcedVerticesByFace", (const BLSURFPlugin_Hypothesis::TFaceEntryEnfVertexListMap (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::_GetAllEnforcedVerticesByFace, "None");
	cls_BLSURFPlugin_Hypothesis.def("_GetAllEnforcedVertices", (const BLSURFPlugin_Hypothesis::TEnfVertexList (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::_GetAllEnforcedVertices, "None");
	cls_BLSURFPlugin_Hypothesis.def("_GetAllCoordsByFace", (const BLSURFPlugin_Hypothesis::TFaceEntryCoordsListMap (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::_GetAllCoordsByFace, "None");
	cls_BLSURFPlugin_Hypothesis.def("_GetAllEnforcedVerticesByCoords", (const BLSURFPlugin_Hypothesis::TCoordsEnfVertexMap (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::_GetAllEnforcedVerticesByCoords, "None");
	cls_BLSURFPlugin_Hypothesis.def("_GetAllEnfVertexEntriesByFace", (const BLSURFPlugin_Hypothesis::TFaceEntryEnfVertexEntryListMap (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::_GetAllEnfVertexEntriesByFace, "None");
	cls_BLSURFPlugin_Hypothesis.def("_GetAllEnforcedVerticesByEnfVertexEntry", (const BLSURFPlugin_Hypothesis::TEnfVertexEntryEnfVertexMap (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::_GetAllEnforcedVerticesByEnfVertexEntry, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetAllEnforcedVerticesByFace_", (BLSURFPlugin_Hypothesis::TFaceEntryEnfVertexListMap (*)(const BLSURFPlugin_Hypothesis *)) &BLSURFPlugin_Hypothesis::GetAllEnforcedVerticesByFace, "Return the enforced vertices", py::arg("hyp"));
	cls_BLSURFPlugin_Hypothesis.def_static("GetAllEnforcedVertices_", (BLSURFPlugin_Hypothesis::TEnfVertexList (*)(const BLSURFPlugin_Hypothesis *)) &BLSURFPlugin_Hypothesis::GetAllEnforcedVertices, "None", py::arg("hyp"));
	cls_BLSURFPlugin_Hypothesis.def_static("GetAllCoordsByFace_", (BLSURFPlugin_Hypothesis::TFaceEntryCoordsListMap (*)(const BLSURFPlugin_Hypothesis *)) &BLSURFPlugin_Hypothesis::GetAllCoordsByFace, "None", py::arg("hyp"));
	cls_BLSURFPlugin_Hypothesis.def_static("GetAllEnforcedVerticesByCoords_", (BLSURFPlugin_Hypothesis::TCoordsEnfVertexMap (*)(const BLSURFPlugin_Hypothesis *)) &BLSURFPlugin_Hypothesis::GetAllEnforcedVerticesByCoords, "None", py::arg("hyp"));
	cls_BLSURFPlugin_Hypothesis.def_static("GetAllEnfVertexEntriesByFace_", (BLSURFPlugin_Hypothesis::TFaceEntryEnfVertexEntryListMap (*)(const BLSURFPlugin_Hypothesis *)) &BLSURFPlugin_Hypothesis::GetAllEnfVertexEntriesByFace, "None", py::arg("hyp"));
	cls_BLSURFPlugin_Hypothesis.def_static("GetAllEnforcedVerticesByEnfVertexEntry_", (BLSURFPlugin_Hypothesis::TEnfVertexEntryEnfVertexMap (*)(const BLSURFPlugin_Hypothesis *)) &BLSURFPlugin_Hypothesis::GetAllEnforcedVerticesByEnfVertexEntry, "None", py::arg("hyp"));
	cls_BLSURFPlugin_Hypothesis.def("SetInternalEnforcedVertexAllFaces", (void (BLSURFPlugin_Hypothesis::*)(bool)) &BLSURFPlugin_Hypothesis::SetInternalEnforcedVertexAllFaces, "Internal enforced vertices", py::arg("toEnforceInternalVertices"));
	cls_BLSURFPlugin_Hypothesis.def("_GetInternalEnforcedVertexAllFaces", (const bool (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::_GetInternalEnforcedVertexAllFaces, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetInternalEnforcedVertexAllFaces_", (bool (*)(const BLSURFPlugin_Hypothesis *)) &BLSURFPlugin_Hypothesis::GetInternalEnforcedVertexAllFaces, "None", py::arg("hyp"));
	cls_BLSURFPlugin_Hypothesis.def("SetInternalEnforcedVertexAllFacesGroup", (void (BLSURFPlugin_Hypothesis::*)(BLSURFPlugin_Hypothesis::TEnfGroupName)) &BLSURFPlugin_Hypothesis::SetInternalEnforcedVertexAllFacesGroup, "None", py::arg("theGroupName"));
	cls_BLSURFPlugin_Hypothesis.def("_GetInternalEnforcedVertexAllFacesGroup", (const BLSURFPlugin_Hypothesis::TEnfGroupName (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::_GetInternalEnforcedVertexAllFacesGroup, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetInternalEnforcedVertexAllFacesGroup_", (BLSURFPlugin_Hypothesis::TEnfGroupName (*)(const BLSURFPlugin_Hypothesis *)) &BLSURFPlugin_Hypothesis::GetInternalEnforcedVertexAllFacesGroup, "None", py::arg("hyp"));
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultPhysicalMesh_", (BLSURFPlugin_Hypothesis::PhysicalMesh (*)()) &BLSURFPlugin_Hypothesis::GetDefaultPhysicalMesh, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultGeometricMesh_", (BLSURFPlugin_Hypothesis::GeometricMesh (*)()) &BLSURFPlugin_Hypothesis::GetDefaultGeometricMesh, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultPhySize_", (double (*)(double, double)) &BLSURFPlugin_Hypothesis::GetDefaultPhySize, "None", py::arg("diagonal"), py::arg("bbSegmentation"));
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultPhySize_", (double (*)()) &BLSURFPlugin_Hypothesis::GetDefaultPhySize, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultPhySizeRel_", (bool (*)()) &BLSURFPlugin_Hypothesis::GetDefaultPhySizeRel, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultMinSize_", (double (*)(double)) &BLSURFPlugin_Hypothesis::GetDefaultMinSize, "None", py::arg("diagonal"));
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultMinSize_", (double (*)()) &BLSURFPlugin_Hypothesis::GetDefaultMinSize, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultMinSizeRel_", (bool (*)()) &BLSURFPlugin_Hypothesis::GetDefaultMinSizeRel, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultMaxSize_", (double (*)(double)) &BLSURFPlugin_Hypothesis::GetDefaultMaxSize, "None", py::arg("diagonal"));
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultMaxSize_", (double (*)()) &BLSURFPlugin_Hypothesis::GetDefaultMaxSize, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultMaxSizeRel_", (bool (*)()) &BLSURFPlugin_Hypothesis::GetDefaultMaxSizeRel, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultUseGradation_", (bool (*)()) &BLSURFPlugin_Hypothesis::GetDefaultUseGradation, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultGradation_", (double (*)()) &BLSURFPlugin_Hypothesis::GetDefaultGradation, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultUseVolumeGradation_", (bool (*)()) &BLSURFPlugin_Hypothesis::GetDefaultUseVolumeGradation, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultVolumeGradation_", (double (*)()) &BLSURFPlugin_Hypothesis::GetDefaultVolumeGradation, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultQuadAllowed_", (bool (*)()) &BLSURFPlugin_Hypothesis::GetDefaultQuadAllowed, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultAngleMesh_", (double (*)()) &BLSURFPlugin_Hypothesis::GetDefaultAngleMesh, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultChordalError_", (double (*)(double)) &BLSURFPlugin_Hypothesis::GetDefaultChordalError, "None", py::arg("diagonal"));
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultChordalError_", (double (*)()) &BLSURFPlugin_Hypothesis::GetDefaultChordalError, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultAnisotropic_", (bool (*)()) &BLSURFPlugin_Hypothesis::GetDefaultAnisotropic, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultAnisotropicRatio_", (double (*)()) &BLSURFPlugin_Hypothesis::GetDefaultAnisotropicRatio, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultRemoveTinyEdges_", (bool (*)()) &BLSURFPlugin_Hypothesis::GetDefaultRemoveTinyEdges, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultTinyEdgeLength_", (double (*)(double)) &BLSURFPlugin_Hypothesis::GetDefaultTinyEdgeLength, "None", py::arg("diagonal"));
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultTinyEdgeLength_", (double (*)()) &BLSURFPlugin_Hypothesis::GetDefaultTinyEdgeLength, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultOptimiseTinyEdges_", (bool (*)()) &BLSURFPlugin_Hypothesis::GetDefaultOptimiseTinyEdges, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultTinyEdgeOptimisationLength_", (double (*)(double)) &BLSURFPlugin_Hypothesis::GetDefaultTinyEdgeOptimisationLength, "None", py::arg("diagonal"));
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultTinyEdgeOptimisationLength_", (double (*)()) &BLSURFPlugin_Hypothesis::GetDefaultTinyEdgeOptimisationLength, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultCorrectSurfaceIntersection_", (bool (*)()) &BLSURFPlugin_Hypothesis::GetDefaultCorrectSurfaceIntersection, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultCorrectSurfaceIntersectionMaxCost_", (double (*)()) &BLSURFPlugin_Hypothesis::GetDefaultCorrectSurfaceIntersectionMaxCost, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultBadElementRemoval_", (bool (*)()) &BLSURFPlugin_Hypothesis::GetDefaultBadElementRemoval, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultBadElementAspectRatio_", (double (*)()) &BLSURFPlugin_Hypothesis::GetDefaultBadElementAspectRatio, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultOptimizeMesh_", (bool (*)()) &BLSURFPlugin_Hypothesis::GetDefaultOptimizeMesh, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultQuadraticMesh_", (bool (*)()) &BLSURFPlugin_Hypothesis::GetDefaultQuadraticMesh, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultVerbosity_", (int (*)()) &BLSURFPlugin_Hypothesis::GetDefaultVerbosity, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultTopology_", (BLSURFPlugin_Hypothesis::Topology (*)()) &BLSURFPlugin_Hypothesis::GetDefaultTopology, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultPreCADMergeEdges_", (bool (*)()) &BLSURFPlugin_Hypothesis::GetDefaultPreCADMergeEdges, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultPreCADRemoveDuplicateCADFaces_", (bool (*)()) &BLSURFPlugin_Hypothesis::GetDefaultPreCADRemoveDuplicateCADFaces, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultPreCADProcess3DTopology_", (bool (*)()) &BLSURFPlugin_Hypothesis::GetDefaultPreCADProcess3DTopology, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultPreCADDiscardInput_", (bool (*)()) &BLSURFPlugin_Hypothesis::GetDefaultPreCADDiscardInput, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultSizeMap_", (BLSURFPlugin_Hypothesis::TSizeMap (*)()) &BLSURFPlugin_Hypothesis::GetDefaultSizeMap, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultAttractorMap_", (BLSURFPlugin_Hypothesis::TAttractorMap (*)()) &BLSURFPlugin_Hypothesis::GetDefaultAttractorMap, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultFaceEntryEnfVertexListMap_", (BLSURFPlugin_Hypothesis::TFaceEntryEnfVertexListMap (*)()) &BLSURFPlugin_Hypothesis::GetDefaultFaceEntryEnfVertexListMap, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultEnfVertexList_", (BLSURFPlugin_Hypothesis::TEnfVertexList (*)()) &BLSURFPlugin_Hypothesis::GetDefaultEnfVertexList, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultFaceEntryCoordsListMap_", (BLSURFPlugin_Hypothesis::TFaceEntryCoordsListMap (*)()) &BLSURFPlugin_Hypothesis::GetDefaultFaceEntryCoordsListMap, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultCoordsEnfVertexMap_", (BLSURFPlugin_Hypothesis::TCoordsEnfVertexMap (*)()) &BLSURFPlugin_Hypothesis::GetDefaultCoordsEnfVertexMap, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultFaceEntryEnfVertexEntryListMap_", (BLSURFPlugin_Hypothesis::TFaceEntryEnfVertexEntryListMap (*)()) &BLSURFPlugin_Hypothesis::GetDefaultFaceEntryEnfVertexEntryListMap, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultEnfVertexEntryEnfVertexMap_", (BLSURFPlugin_Hypothesis::TEnfVertexEntryEnfVertexMap (*)()) &BLSURFPlugin_Hypothesis::GetDefaultEnfVertexEntryEnfVertexMap, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultGroupNameNodeIDMap_", (BLSURFPlugin_Hypothesis::TGroupNameNodeIDMap (*)()) &BLSURFPlugin_Hypothesis::GetDefaultGroupNameNodeIDMap, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultInternalEnforcedVertex_", (bool (*)()) &BLSURFPlugin_Hypothesis::GetDefaultInternalEnforcedVertex, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultPreCadFacesPeriodicityVector_", (BLSURFPlugin_Hypothesis::TPreCadPeriodicityVector (*)()) &BLSURFPlugin_Hypothesis::GetDefaultPreCadFacesPeriodicityVector, "None");
	cls_BLSURFPlugin_Hypothesis.def("_GetPreCadFacesPeriodicityVector", (const BLSURFPlugin_Hypothesis::TPreCadPeriodicityVector (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::_GetPreCadFacesPeriodicityVector, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetPreCadFacesPeriodicityVector_", (BLSURFPlugin_Hypothesis::TPreCadPeriodicityVector (*)(const BLSURFPlugin_Hypothesis *)) &BLSURFPlugin_Hypothesis::GetPreCadFacesPeriodicityVector, "None", py::arg("hyp"));
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultPreCadEdgesPeriodicityVector_", (BLSURFPlugin_Hypothesis::TPreCadPeriodicityVector (*)()) &BLSURFPlugin_Hypothesis::GetDefaultPreCadEdgesPeriodicityVector, "None");
	cls_BLSURFPlugin_Hypothesis.def("_GetPreCadEdgesPeriodicityVector", (const BLSURFPlugin_Hypothesis::TPreCadPeriodicityVector (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::_GetPreCadEdgesPeriodicityVector, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetPreCadEdgesPeriodicityVector_", (BLSURFPlugin_Hypothesis::TPreCadPeriodicityVector (*)(const BLSURFPlugin_Hypothesis *)) &BLSURFPlugin_Hypothesis::GetPreCadEdgesPeriodicityVector, "None", py::arg("hyp"));
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultFacesPeriodicityVector_", (BLSURFPlugin_Hypothesis::TFacesPeriodicityVector (*)()) &BLSURFPlugin_Hypothesis::GetDefaultFacesPeriodicityVector, "None");
	cls_BLSURFPlugin_Hypothesis.def("_GetFacesPeriodicityVector", (const BLSURFPlugin_Hypothesis::TFacesPeriodicityVector (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::_GetFacesPeriodicityVector, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetFacesPeriodicityVector_", (BLSURFPlugin_Hypothesis::TFacesPeriodicityVector (*)(const BLSURFPlugin_Hypothesis *)) &BLSURFPlugin_Hypothesis::GetFacesPeriodicityVector, "None", py::arg("hyp"));
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultEdgesPeriodicityVector_", (BLSURFPlugin_Hypothesis::TEdgesPeriodicityVector (*)()) &BLSURFPlugin_Hypothesis::GetDefaultEdgesPeriodicityVector, "None");
	cls_BLSURFPlugin_Hypothesis.def("_GetEdgesPeriodicityVector", (const BLSURFPlugin_Hypothesis::TEdgesPeriodicityVector (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::_GetEdgesPeriodicityVector, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetEdgesPeriodicityVector_", (BLSURFPlugin_Hypothesis::TEdgesPeriodicityVector (*)(const BLSURFPlugin_Hypothesis *)) &BLSURFPlugin_Hypothesis::GetEdgesPeriodicityVector, "None", py::arg("hyp"));
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultVerticesPeriodicityVector_", (BLSURFPlugin_Hypothesis::TVerticesPeriodicityVector (*)()) &BLSURFPlugin_Hypothesis::GetDefaultVerticesPeriodicityVector, "None");
	cls_BLSURFPlugin_Hypothesis.def("_GetVerticesPeriodicityVector", (const BLSURFPlugin_Hypothesis::TVerticesPeriodicityVector (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::_GetVerticesPeriodicityVector, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetVerticesPeriodicityVector_", (BLSURFPlugin_Hypothesis::TVerticesPeriodicityVector (*)(const BLSURFPlugin_Hypothesis *)) &BLSURFPlugin_Hypothesis::GetVerticesPeriodicityVector, "None", py::arg("hyp"));
	cls_BLSURFPlugin_Hypothesis.def("ClearPreCadPeriodicityVectors", (void (BLSURFPlugin_Hypothesis::*)()) &BLSURFPlugin_Hypothesis::ClearPreCadPeriodicityVectors, "None");
	cls_BLSURFPlugin_Hypothesis.def("AddPreCadFacesPeriodicity", (void (BLSURFPlugin_Hypothesis::*)(BLSURFPlugin_Hypothesis::TEntry, BLSURFPlugin_Hypothesis::TEntry, std::vector<std::string> &, std::vector<std::string> &)) &BLSURFPlugin_Hypothesis::AddPreCadFacesPeriodicity, "None", py::arg("theFace1Entry"), py::arg("theFace2Entry"), py::arg("theSourceVerticesEntries"), py::arg("theTargetVerticesEntries"));
	cls_BLSURFPlugin_Hypothesis.def("AddPreCadEdgesPeriodicity", (void (BLSURFPlugin_Hypothesis::*)(BLSURFPlugin_Hypothesis::TEntry, BLSURFPlugin_Hypothesis::TEntry, std::vector<std::string> &, std::vector<std::string> &)) &BLSURFPlugin_Hypothesis::AddPreCadEdgesPeriodicity, "None", py::arg("theEdge1Entry"), py::arg("theEdge2Entry"), py::arg("theSourceVerticesEntries"), py::arg("theTargetVerticesEntries"));
	cls_BLSURFPlugin_Hypothesis.def_static("undefinedDouble_", (double (*)()) &BLSURFPlugin_Hypothesis::undefinedDouble, "None");
	cls_BLSURFPlugin_Hypothesis.def("SetOptionValue", (void (BLSURFPlugin_Hypothesis::*)(const std::string &, const std::string &)) &BLSURFPlugin_Hypothesis::SetOptionValue, "None", py::arg("optionName"), py::arg("optionValue"));
	cls_BLSURFPlugin_Hypothesis.def("SetPreCADOptionValue", (void (BLSURFPlugin_Hypothesis::*)(const std::string &, const std::string &)) &BLSURFPlugin_Hypothesis::SetPreCADOptionValue, "None", py::arg("optionName"), py::arg("optionValue"));
	cls_BLSURFPlugin_Hypothesis.def("GetOptionValue", [](BLSURFPlugin_Hypothesis &self, const std::string & a0) -> std::string { return self.GetOptionValue(a0); }, py::arg("optionName"));
	cls_BLSURFPlugin_Hypothesis.def("GetOptionValue", (std::string (BLSURFPlugin_Hypothesis::*)(const std::string &, bool *) const ) &BLSURFPlugin_Hypothesis::GetOptionValue, "None", py::arg("optionName"), py::arg("isDefault"));
	cls_BLSURFPlugin_Hypothesis.def("GetPreCADOptionValue", [](BLSURFPlugin_Hypothesis &self, const std::string & a0) -> std::string { return self.GetPreCADOptionValue(a0); }, py::arg("optionName"));
	cls_BLSURFPlugin_Hypothesis.def("GetPreCADOptionValue", (std::string (BLSURFPlugin_Hypothesis::*)(const std::string &, bool *) const ) &BLSURFPlugin_Hypothesis::GetPreCADOptionValue, "None", py::arg("optionName"), py::arg("isDefault"));
	cls_BLSURFPlugin_Hypothesis.def("ClearOption", (void (BLSURFPlugin_Hypothesis::*)(const std::string &)) &BLSURFPlugin_Hypothesis::ClearOption, "None", py::arg("optionName"));
	cls_BLSURFPlugin_Hypothesis.def("ClearPreCADOption", (void (BLSURFPlugin_Hypothesis::*)(const std::string &)) &BLSURFPlugin_Hypothesis::ClearPreCADOption, "None", py::arg("optionName"));
	cls_BLSURFPlugin_Hypothesis.def("GetOptionValues", (BLSURFPlugin_Hypothesis::TOptionValues (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetOptionValues, "None");
	cls_BLSURFPlugin_Hypothesis.def("GetPreCADOptionValues", (BLSURFPlugin_Hypothesis::TOptionValues (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetPreCADOptionValues, "None");
	cls_BLSURFPlugin_Hypothesis.def("GetCustomOptionValues", (const BLSURFPlugin_Hypothesis::TOptionValues & (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetCustomOptionValues, "None");
	cls_BLSURFPlugin_Hypothesis.def("AddOption", (void (BLSURFPlugin_Hypothesis::*)(const std::string &, const std::string &)) &BLSURFPlugin_Hypothesis::AddOption, "None", py::arg("optionName"), py::arg("optionValue"));
	cls_BLSURFPlugin_Hypothesis.def("AddPreCADOption", (void (BLSURFPlugin_Hypothesis::*)(const std::string &, const std::string &)) &BLSURFPlugin_Hypothesis::AddPreCADOption, "None", py::arg("optionName"), py::arg("optionValue"));
	cls_BLSURFPlugin_Hypothesis.def("GetOption", (std::string (BLSURFPlugin_Hypothesis::*)(const std::string &) const ) &BLSURFPlugin_Hypothesis::GetOption, "None", py::arg("optionName"));
	cls_BLSURFPlugin_Hypothesis.def("GetPreCADOption", (std::string (BLSURFPlugin_Hypothesis::*)(const std::string &) const ) &BLSURFPlugin_Hypothesis::GetPreCADOption, "None", py::arg("optionName"));
	cls_BLSURFPlugin_Hypothesis.def_static("ToBool_", [](const std::string & a0) -> bool { return BLSURFPlugin_Hypothesis::ToBool(a0); }, py::arg("str"));
	cls_BLSURFPlugin_Hypothesis.def_static("ToBool_", (bool (*)(const std::string &, bool *)) &BLSURFPlugin_Hypothesis::ToBool, "None", py::arg("str"), py::arg("isOk"));
	cls_BLSURFPlugin_Hypothesis.def_static("ToDbl_", [](const std::string & a0) -> double { return BLSURFPlugin_Hypothesis::ToDbl(a0); }, py::arg("str"));
	cls_BLSURFPlugin_Hypothesis.def_static("ToDbl_", (double (*)(const std::string &, bool *)) &BLSURFPlugin_Hypothesis::ToDbl, "None", py::arg("str"), py::arg("isOk"));
	cls_BLSURFPlugin_Hypothesis.def_static("ToInt_", [](const std::string & a0) -> int { return BLSURFPlugin_Hypothesis::ToInt(a0); }, py::arg("str"));
	cls_BLSURFPlugin_Hypothesis.def_static("ToInt_", (int (*)(const std::string &, bool *)) &BLSURFPlugin_Hypothesis::ToInt, "None", py::arg("str"), py::arg("isOk"));
	cls_BLSURFPlugin_Hypothesis.def("SetGMFFile", (void (BLSURFPlugin_Hypothesis::*)(const std::string &)) &BLSURFPlugin_Hypothesis::SetGMFFile, "None", py::arg("theFileName"));
	cls_BLSURFPlugin_Hypothesis.def("GetGMFFile", (std::string (BLSURFPlugin_Hypothesis::*)() const ) &BLSURFPlugin_Hypothesis::GetGMFFile, "None");
	cls_BLSURFPlugin_Hypothesis.def_static("GetDefaultGMFFile_", (std::string (*)()) &BLSURFPlugin_Hypothesis::GetDefaultGMFFile, "None");
	cls_BLSURFPlugin_Hypothesis.def("SaveTo", (std::ostream & (BLSURFPlugin_Hypothesis::*)(std::ostream &)) &BLSURFPlugin_Hypothesis::SaveTo, "None", py::arg("save"));
	cls_BLSURFPlugin_Hypothesis.def("LoadFrom", (std::istream & (BLSURFPlugin_Hypothesis::*)(std::istream &)) &BLSURFPlugin_Hypothesis::LoadFrom, "None", py::arg("load"));
	cls_BLSURFPlugin_Hypothesis.def("SetParametersByMesh", (bool (BLSURFPlugin_Hypothesis::*)(const SMESH_Mesh *, const TopoDS_Shape &)) &BLSURFPlugin_Hypothesis::SetParametersByMesh, "Does nothing", py::arg("theMesh"), py::arg("theShape"));
	cls_BLSURFPlugin_Hypothesis.def("SetParametersByDefaults", [](BLSURFPlugin_Hypothesis &self, const SMESH_Hypothesis::TDefaults & a0) -> bool { return self.SetParametersByDefaults(a0); }, py::arg("dflts"));
	cls_BLSURFPlugin_Hypothesis.def("SetParametersByDefaults", (bool (BLSURFPlugin_Hypothesis::*)(const SMESH_Hypothesis::TDefaults &, const SMESH_Mesh *)) &BLSURFPlugin_Hypothesis::SetParametersByDefaults, "Initialize my parameter values by default parameters. bool - true if parameter values have been successfully defined", py::arg("dflts"), py::arg("theMesh"));
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\BLSURFPlugin_Hypothesis.hxx
	py::enum_<BLSURFPlugin_Hypothesis::Topology>(cls_BLSURFPlugin_Hypothesis, "Topology", "None")
		.value("FromCAD", BLSURFPlugin_Hypothesis::Topology::FromCAD)
		.value("Process", BLSURFPlugin_Hypothesis::Topology::Process)
		.value("Process2", BLSURFPlugin_Hypothesis::Topology::Process2)
		.value("PreCAD", BLSURFPlugin_Hypothesis::Topology::PreCAD)
		.export_values();
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\BLSURFPlugin_Hypothesis.hxx
	py::enum_<BLSURFPlugin_Hypothesis::PhysicalMesh>(cls_BLSURFPlugin_Hypothesis, "PhysicalMesh", "None")
		.value("DefaultSize", BLSURFPlugin_Hypothesis::PhysicalMesh::DefaultSize)
		.value("PhysicalGlobalSize", BLSURFPlugin_Hypothesis::PhysicalMesh::PhysicalGlobalSize)
		.value("PhysicalLocalSize", BLSURFPlugin_Hypothesis::PhysicalMesh::PhysicalLocalSize)
		.export_values();
	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\BLSURFPlugin_Hypothesis.hxx
	py::enum_<BLSURFPlugin_Hypothesis::GeometricMesh>(cls_BLSURFPlugin_Hypothesis, "GeometricMesh", "None")
		.value("DefaultGeom", BLSURFPlugin_Hypothesis::GeometricMesh::DefaultGeom)
		.value("GeometricalGlobalSize", BLSURFPlugin_Hypothesis::GeometricMesh::GeometricalGlobalSize)
		.value("GeometricalLocalSize", BLSURFPlugin_Hypothesis::GeometricMesh::GeometricalLocalSize)
		.export_values();

	// C:\Users\Trevor\Work\Products\SMESH\install\include\smesh\BLSURFPlugin_BLSURF.hxx
	py::class_<BLSURFPlugin_BLSURF, std::unique_ptr<BLSURFPlugin_BLSURF, py::nodelete>, SMESH_2D_Algo> cls_BLSURFPlugin_BLSURF(mod, "BLSURFPlugin_BLSURF", "None");
	cls_BLSURFPlugin_BLSURF.def(py::init<int, int, SMESH_Gen *, bool>(), py::arg("hypId"), py::arg("studyId"), py::arg("gen"), py::arg("theHasGEOM"));
	cls_BLSURFPlugin_BLSURF.def("CheckHypothesis", (bool (BLSURFPlugin_BLSURF::*)(SMESH_Mesh &, const TopoDS_Shape &, SMESH_Hypothesis::Hypothesis_Status &)) &BLSURFPlugin_BLSURF::CheckHypothesis, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aStatus"));
	// FIXME cls_BLSURFPlugin_BLSURF.def("SetParameters", (void (BLSURFPlugin_BLSURF::*)(const BLSURFPlugin_Hypothesis *, meshgems_cadsurf_session_t *, const TopoDS_Shape &)) &BLSURFPlugin_BLSURF::SetParameters, "None", py::arg("hyp"), py::arg("css"), py::arg("shape"));
	cls_BLSURFPlugin_BLSURF.def("Compute", (bool (BLSURFPlugin_BLSURF::*)(SMESH_Mesh &, const TopoDS_Shape &)) &BLSURFPlugin_BLSURF::Compute, "None", py::arg("aMesh"), py::arg("aShape"));
	cls_BLSURFPlugin_BLSURF.def("Compute", (bool (BLSURFPlugin_BLSURF::*)(SMESH_Mesh &, SMESH_MesherHelper *)) &BLSURFPlugin_BLSURF::Compute, "None", py::arg("aMesh"), py::arg("aHelper"));
	cls_BLSURFPlugin_BLSURF.def("CancelCompute", (void (BLSURFPlugin_BLSURF::*)()) &BLSURFPlugin_BLSURF::CancelCompute, "None");
	cls_BLSURFPlugin_BLSURF.def("computeCanceled", (bool (BLSURFPlugin_BLSURF::*)()) &BLSURFPlugin_BLSURF::computeCanceled, "None");
	cls_BLSURFPlugin_BLSURF.def("Evaluate", (bool (BLSURFPlugin_BLSURF::*)(SMESH_Mesh &, const TopoDS_Shape &, MapShapeNbElems &)) &BLSURFPlugin_BLSURF::Evaluate, "None", py::arg("aMesh"), py::arg("aShape"), py::arg("aResMap"));


}
