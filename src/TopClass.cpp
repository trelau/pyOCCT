#include <pyOCCT_Common.hpp>

#include <gp_Lin.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <IntCurveSurface_IntersectionPoint.hxx>
#include <TopAbs_State.hxx>
#include <TopClass_Intersection3d.hxx>
#include <gp_Pnt.hxx>
#include <TopClass_SolidExplorer.hxx>

PYBIND11_MODULE(TopClass, mod) {

	// IMPORT
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.IntCurveSurface");
	py::module::import("OCCT.TopAbs");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopClass_Intersection3d.hxx
	py::class_<TopClass_Intersection3d, std::unique_ptr<TopClass_Intersection3d, Deleter<TopClass_Intersection3d>>> cls_TopClass_Intersection3d(mod, "TopClass_Intersection3d", "Template class for the intersection algorithm required by the 3D classifications.");
	cls_TopClass_Intersection3d.def("Perform", (void (TopClass_Intersection3d::*)(const gp_Lin &, const Standard_Real, const Standard_Real, const TopoDS_Face &)) &TopClass_Intersection3d::Perform, "Perform the intersection between the segment L(0) ... L(Prm) and the Face <Face>.", py::arg("L"), py::arg("Prm"), py::arg("Tol"), py::arg("Face"));
	cls_TopClass_Intersection3d.def("IsDone", (Standard_Boolean (TopClass_Intersection3d::*)() const ) &TopClass_Intersection3d::IsDone, "True is returned when the intersection have been computed.");
	cls_TopClass_Intersection3d.def("HasAPoint", (Standard_Boolean (TopClass_Intersection3d::*)() const ) &TopClass_Intersection3d::HasAPoint, "True is returned if a point has been found.");
	cls_TopClass_Intersection3d.def("Point", (const IntCurveSurface_IntersectionPoint & (TopClass_Intersection3d::*)() const ) &TopClass_Intersection3d::Point, "Returns the Intersection Point.");
	cls_TopClass_Intersection3d.def("State", (TopAbs_State (TopClass_Intersection3d::*)() const ) &TopClass_Intersection3d::State, "Returns the state of the point on the face. The values can be either TopAbs_IN ( the point is in the face) or TopAbs_ON ( the point is on a boudary of the face).");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopClass_SolidExplorer.hxx
	py::class_<TopClass_SolidExplorer, std::unique_ptr<TopClass_SolidExplorer, Deleter<TopClass_SolidExplorer>>> cls_TopClass_SolidExplorer(mod, "TopClass_SolidExplorer", "Provide an exploration of a BRep Shape for the classification. Defines the description of a solid for the SolidClassifier.");
	cls_TopClass_SolidExplorer.def("Reject", (Standard_Boolean (TopClass_SolidExplorer::*)(const gp_Pnt &) const ) &TopClass_SolidExplorer::Reject, "Should return True if the point is outside a bounding volume of the shape.", py::arg("P"));
	cls_TopClass_SolidExplorer.def("Segment", (void (TopClass_SolidExplorer::*)(const gp_Pnt &, gp_Lin &, Standard_Real &)) &TopClass_SolidExplorer::Segment, "Returns in <L>, <Par> a segment having at least one intersection with the shape boundary to compute intersections.", py::arg("P"), py::arg("L"), py::arg("Par"));
	cls_TopClass_SolidExplorer.def("OtherSegment", (void (TopClass_SolidExplorer::*)(const gp_Pnt &, gp_Lin &, Standard_Real &)) &TopClass_SolidExplorer::OtherSegment, "Returns in <L>, <Par> a segment having at least one intersection with the shape boundary to compute intersections.", py::arg("P"), py::arg("L"), py::arg("Par"));
	cls_TopClass_SolidExplorer.def("InitShell", (void (TopClass_SolidExplorer::*)()) &TopClass_SolidExplorer::InitShell, "Starts an exploration of the shells.");
	cls_TopClass_SolidExplorer.def("MoreShells", (Standard_Boolean (TopClass_SolidExplorer::*)() const ) &TopClass_SolidExplorer::MoreShells, "Returns True if there is a current shell.");
	cls_TopClass_SolidExplorer.def("NextShell", (void (TopClass_SolidExplorer::*)()) &TopClass_SolidExplorer::NextShell, "Sets the explorer to the next shell and returns False if there are no more wires.");
	cls_TopClass_SolidExplorer.def("RejectShell", (Standard_Boolean (TopClass_SolidExplorer::*)(const gp_Lin &, const Standard_Real) const ) &TopClass_SolidExplorer::RejectShell, "Returns True if the shell bounding volume does not intersect the segment.", py::arg("L"), py::arg("Par"));
	cls_TopClass_SolidExplorer.def("InitFace", (void (TopClass_SolidExplorer::*)()) &TopClass_SolidExplorer::InitFace, "Starts an exploration of the faces.");
	cls_TopClass_SolidExplorer.def("MoreFaces", (Standard_Boolean (TopClass_SolidExplorer::*)() const ) &TopClass_SolidExplorer::MoreFaces, "Returns True if there is a current face.");
	cls_TopClass_SolidExplorer.def("NextFace", (void (TopClass_SolidExplorer::*)()) &TopClass_SolidExplorer::NextFace, "Sets the explorer to the next face and returns False if there are no more wires.");
	cls_TopClass_SolidExplorer.def("CurrentFace", (TopoDS_Face (TopClass_SolidExplorer::*)() const ) &TopClass_SolidExplorer::CurrentFace, "Returns the current face.");
	cls_TopClass_SolidExplorer.def("RejectFace", (Standard_Boolean (TopClass_SolidExplorer::*)(const gp_Lin &, const Standard_Real) const ) &TopClass_SolidExplorer::RejectFace, "Returns True if the face bounding volume does not intersect the segment.", py::arg("L"), py::arg("Par"));


}
