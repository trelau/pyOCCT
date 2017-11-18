#include <pyOCCT_Common.hpp>

#include <Draft_ErrorStatus.hxx>
#include <BRepTools_Modification.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <gp_Dir.hxx>
#include <gp_Pln.hxx>
#include <TopTools_ListOfShape.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <TopLoc_Location.hxx>
#include <TopoDS_Edge.hxx>
#include <Geom_Curve.hxx>
#include <TopoDS_Vertex.hxx>
#include <gp_Pnt.hxx>
#include <Geom2d_Curve.hxx>
#include <GeomAbs_Shape.hxx>
#include <Standard_Type.hxx>
#include <Draft_Modification.hxx>
#include <Draft_FaceInfo.hxx>
#include <Draft_EdgeInfo.hxx>
#include <Draft_VertexInfo.hxx>
#include <Draft.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <Draft_IndexedDataMapOfEdgeEdgeInfo.hxx>
#include <Draft_IndexedDataMapOfFaceFaceInfo.hxx>
#include <Draft_IndexedDataMapOfVertexVertexInfo.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(Draft, mod) {

	// IMPORT
	py::module::import("OCCT.BRepTools");
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.TopTools");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.TopLoc");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\Draft_ErrorStatus.hxx
	py::enum_<Draft_ErrorStatus>(mod, "Draft_ErrorStatus", "None")
		.value("Draft_NoError", Draft_ErrorStatus::Draft_NoError)
		.value("Draft_FaceRecomputation", Draft_ErrorStatus::Draft_FaceRecomputation)
		.value("Draft_EdgeRecomputation", Draft_ErrorStatus::Draft_EdgeRecomputation)
		.value("Draft_VertexRecomputation", Draft_ErrorStatus::Draft_VertexRecomputation)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Draft_Modification.hxx
	py::class_<Draft_Modification, opencascade::handle<Draft_Modification>, BRepTools_Modification> cls_Draft_Modification(mod, "Draft_Modification", "None");
	cls_Draft_Modification.def(py::init<const TopoDS_Shape &>(), py::arg("S"));
	cls_Draft_Modification.def("Clear", (void (Draft_Modification::*)()) &Draft_Modification::Clear, "Resets on the same shape.");
	cls_Draft_Modification.def("Init", (void (Draft_Modification::*)(const TopoDS_Shape &)) &Draft_Modification::Init, "Changes the basis shape and resets.", py::arg("S"));
	cls_Draft_Modification.def("Add", [](Draft_Modification &self, const TopoDS_Face & a0, const gp_Dir & a1, const Standard_Real a2, const gp_Pln & a3) -> Standard_Boolean { return self.Add(a0, a1, a2, a3); }, py::arg("F"), py::arg("Direction"), py::arg("Angle"), py::arg("NeutralPlane"));
	cls_Draft_Modification.def("Add", (Standard_Boolean (Draft_Modification::*)(const TopoDS_Face &, const gp_Dir &, const Standard_Real, const gp_Pln &, const Standard_Boolean)) &Draft_Modification::Add, "Adds the face F and propagates the draft modification to its neighbour faces if they are tangent. If an error occurs, will return False and ProblematicShape will return the 'bad' face.", py::arg("F"), py::arg("Direction"), py::arg("Angle"), py::arg("NeutralPlane"), py::arg("Flag"));
	cls_Draft_Modification.def("Remove", (void (Draft_Modification::*)(const TopoDS_Face &)) &Draft_Modification::Remove, "Removes the face F and the neighbour faces if they are tangent. It will be necessary to call this method if the method Add returns Standard_False, to unset ProblematicFace.", py::arg("F"));
	cls_Draft_Modification.def("Perform", (void (Draft_Modification::*)()) &Draft_Modification::Perform, "Performs the draft angle modification and sets the value returned by the method IsDone. If an error occurs, IsDone will return Standard_False, and an error status will be given by the method Error, and the shape on which the problem appeared will be given by ProblematicShape");
	cls_Draft_Modification.def("IsDone", (Standard_Boolean (Draft_Modification::*)() const ) &Draft_Modification::IsDone, "Returns True if Perform has been succesfully called. Otherwise more information can be obtained using the methods Error() and ProblematicShape().");
	cls_Draft_Modification.def("Error", (Draft_ErrorStatus (Draft_Modification::*)() const ) &Draft_Modification::Error, "None");
	cls_Draft_Modification.def("ProblematicShape", (const TopoDS_Shape & (Draft_Modification::*)() const ) &Draft_Modification::ProblematicShape, "Returns the shape (Face, Edge or Vertex) on which an error occured.");
	cls_Draft_Modification.def("ConnectedFaces", (const TopTools_ListOfShape & (Draft_Modification::*)(const TopoDS_Face &)) &Draft_Modification::ConnectedFaces, "Returns all the faces which have been added together with the face <F>.", py::arg("F"));
	cls_Draft_Modification.def("ModifiedFaces", (const TopTools_ListOfShape & (Draft_Modification::*)()) &Draft_Modification::ModifiedFaces, "Returns all the faces on which a modification has been given.");
	cls_Draft_Modification.def("NewSurface", (Standard_Boolean (Draft_Modification::*)(const TopoDS_Face &, opencascade::handle<Geom_Surface> &, TopLoc_Location &, Standard_Real &, Standard_Boolean &, Standard_Boolean &)) &Draft_Modification::NewSurface, "Returns Standard_True if the face <F> has been modified. In this case, <S> is the new geometric support of the face, <L> the new location,<Tol> the new tolerance.<RevWires> has to be set to Standard_True when the modification reverses the normal of the surface.(the wires have to be reversed). <RevFace> has to be set to Standard_True if the orientation of the modified face changes in the shells which contain it. Here it will be set to Standard_False.", py::arg("F"), py::arg("S"), py::arg("L"), py::arg("Tol"), py::arg("RevWires"), py::arg("RevFace"));
	cls_Draft_Modification.def("NewCurve", (Standard_Boolean (Draft_Modification::*)(const TopoDS_Edge &, opencascade::handle<Geom_Curve> &, TopLoc_Location &, Standard_Real &)) &Draft_Modification::NewCurve, "Returns Standard_True if the edge <E> has been modified. In this case, <C> is the new geometric support of the edge, <L> the new location, <Tol> the new tolerance. Otherwise, returns Standard_False, and <C>, <L>, <Tol> are not significant.", py::arg("E"), py::arg("C"), py::arg("L"), py::arg("Tol"));
	cls_Draft_Modification.def("NewPoint", (Standard_Boolean (Draft_Modification::*)(const TopoDS_Vertex &, gp_Pnt &, Standard_Real &)) &Draft_Modification::NewPoint, "Returns Standard_True if the vertex <V> has been modified. In this case, <P> is the new geometric support of the vertex, <Tol> the new tolerance. Otherwise, returns Standard_False, and <P>, <Tol> are not significant.", py::arg("V"), py::arg("P"), py::arg("Tol"));
	cls_Draft_Modification.def("NewCurve2d", (Standard_Boolean (Draft_Modification::*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Edge &, const TopoDS_Face &, opencascade::handle<Geom2d_Curve> &, Standard_Real &)) &Draft_Modification::NewCurve2d, "Returns Standard_True if the edge <E> has a new curve on surface on the face <F>.In this case, <C> is the new geometric support of the edge, <L> the new location, <Tol> the new tolerance.", py::arg("E"), py::arg("F"), py::arg("NewE"), py::arg("NewF"), py::arg("C"), py::arg("Tol"));
	cls_Draft_Modification.def("NewParameter", (Standard_Boolean (Draft_Modification::*)(const TopoDS_Vertex &, const TopoDS_Edge &, Standard_Real &, Standard_Real &)) &Draft_Modification::NewParameter, "Returns Standard_True if the Vertex <V> has a new parameter on the edge <E>. In this case, <P> is the parameter, <Tol> the new tolerance. Otherwise, returns Standard_False, and <P>, <Tol> are not significant.", py::arg("V"), py::arg("E"), py::arg("P"), py::arg("Tol"));
	cls_Draft_Modification.def("Continuity", (GeomAbs_Shape (Draft_Modification::*)(const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &, const TopoDS_Edge &, const TopoDS_Face &, const TopoDS_Face &)) &Draft_Modification::Continuity, "Returns the continuity of <NewE> between <NewF1> and <NewF2>.", py::arg("E"), py::arg("F1"), py::arg("F2"), py::arg("NewE"), py::arg("NewF1"), py::arg("NewF2"));
	cls_Draft_Modification.def_static("get_type_name_", (const char * (*)()) &Draft_Modification::get_type_name, "None");
	cls_Draft_Modification.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Draft_Modification::get_type_descriptor, "None");
	cls_Draft_Modification.def("DynamicType", (const opencascade::handle<Standard_Type> & (Draft_Modification::*)() const ) &Draft_Modification::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Draft_FaceInfo.hxx
	py::class_<Draft_FaceInfo, std::unique_ptr<Draft_FaceInfo, Deleter<Draft_FaceInfo>>> cls_Draft_FaceInfo(mod, "Draft_FaceInfo", "None");
	cls_Draft_FaceInfo.def(py::init<>());
	cls_Draft_FaceInfo.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Boolean>(), py::arg("S"), py::arg("HasNewGeometry"));
	cls_Draft_FaceInfo.def("RootFace", (void (Draft_FaceInfo::*)(const TopoDS_Face &)) &Draft_FaceInfo::RootFace, "None", py::arg("F"));
	cls_Draft_FaceInfo.def("NewGeometry", (Standard_Boolean (Draft_FaceInfo::*)() const ) &Draft_FaceInfo::NewGeometry, "None");
	cls_Draft_FaceInfo.def("Add", (void (Draft_FaceInfo::*)(const TopoDS_Face &)) &Draft_FaceInfo::Add, "None", py::arg("F"));
	cls_Draft_FaceInfo.def("FirstFace", (const TopoDS_Face & (Draft_FaceInfo::*)() const ) &Draft_FaceInfo::FirstFace, "None");
	cls_Draft_FaceInfo.def("SecondFace", (const TopoDS_Face & (Draft_FaceInfo::*)() const ) &Draft_FaceInfo::SecondFace, "None");
	cls_Draft_FaceInfo.def("Geometry", (const opencascade::handle<Geom_Surface> & (Draft_FaceInfo::*)() const ) &Draft_FaceInfo::Geometry, "None");
	cls_Draft_FaceInfo.def("ChangeGeometry", (opencascade::handle<Geom_Surface> & (Draft_FaceInfo::*)()) &Draft_FaceInfo::ChangeGeometry, "None");
	cls_Draft_FaceInfo.def("RootFace", (const TopoDS_Face & (Draft_FaceInfo::*)() const ) &Draft_FaceInfo::RootFace, "None");
	cls_Draft_FaceInfo.def("ChangeCurve", (opencascade::handle<Geom_Curve> & (Draft_FaceInfo::*)()) &Draft_FaceInfo::ChangeCurve, "None");
	cls_Draft_FaceInfo.def("Curve", (const opencascade::handle<Geom_Curve> & (Draft_FaceInfo::*)() const ) &Draft_FaceInfo::Curve, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Draft_EdgeInfo.hxx
	py::class_<Draft_EdgeInfo, std::unique_ptr<Draft_EdgeInfo, Deleter<Draft_EdgeInfo>>> cls_Draft_EdgeInfo(mod, "Draft_EdgeInfo", "None");
	cls_Draft_EdgeInfo.def(py::init<>());
	cls_Draft_EdgeInfo.def(py::init<const Standard_Boolean>(), py::arg("HasNewGeometry"));
	cls_Draft_EdgeInfo.def("Add", (void (Draft_EdgeInfo::*)(const TopoDS_Face &)) &Draft_EdgeInfo::Add, "None", py::arg("F"));
	cls_Draft_EdgeInfo.def("RootFace", (void (Draft_EdgeInfo::*)(const TopoDS_Face &)) &Draft_EdgeInfo::RootFace, "None", py::arg("F"));
	cls_Draft_EdgeInfo.def("Tangent", (void (Draft_EdgeInfo::*)(const gp_Pnt &)) &Draft_EdgeInfo::Tangent, "None", py::arg("P"));
	cls_Draft_EdgeInfo.def("IsTangent", (Standard_Boolean (Draft_EdgeInfo::*)(gp_Pnt &) const ) &Draft_EdgeInfo::IsTangent, "None", py::arg("P"));
	cls_Draft_EdgeInfo.def("NewGeometry", (Standard_Boolean (Draft_EdgeInfo::*)() const ) &Draft_EdgeInfo::NewGeometry, "None");
	cls_Draft_EdgeInfo.def("SetNewGeometry", (void (Draft_EdgeInfo::*)(const Standard_Boolean)) &Draft_EdgeInfo::SetNewGeometry, "None", py::arg("NewGeom"));
	cls_Draft_EdgeInfo.def("Geometry", (const opencascade::handle<Geom_Curve> & (Draft_EdgeInfo::*)() const ) &Draft_EdgeInfo::Geometry, "None");
	cls_Draft_EdgeInfo.def("FirstFace", (const TopoDS_Face & (Draft_EdgeInfo::*)() const ) &Draft_EdgeInfo::FirstFace, "None");
	cls_Draft_EdgeInfo.def("SecondFace", (const TopoDS_Face & (Draft_EdgeInfo::*)() const ) &Draft_EdgeInfo::SecondFace, "None");
	cls_Draft_EdgeInfo.def("FirstPC", (const opencascade::handle<Geom2d_Curve> & (Draft_EdgeInfo::*)() const ) &Draft_EdgeInfo::FirstPC, "None");
	cls_Draft_EdgeInfo.def("SecondPC", (const opencascade::handle<Geom2d_Curve> & (Draft_EdgeInfo::*)() const ) &Draft_EdgeInfo::SecondPC, "None");
	cls_Draft_EdgeInfo.def("ChangeGeometry", (opencascade::handle<Geom_Curve> & (Draft_EdgeInfo::*)()) &Draft_EdgeInfo::ChangeGeometry, "None");
	cls_Draft_EdgeInfo.def("ChangeFirstPC", (opencascade::handle<Geom2d_Curve> & (Draft_EdgeInfo::*)()) &Draft_EdgeInfo::ChangeFirstPC, "None");
	cls_Draft_EdgeInfo.def("ChangeSecondPC", (opencascade::handle<Geom2d_Curve> & (Draft_EdgeInfo::*)()) &Draft_EdgeInfo::ChangeSecondPC, "None");
	cls_Draft_EdgeInfo.def("RootFace", (const TopoDS_Face & (Draft_EdgeInfo::*)() const ) &Draft_EdgeInfo::RootFace, "None");
	cls_Draft_EdgeInfo.def("Tolerance", (void (Draft_EdgeInfo::*)(const Standard_Real)) &Draft_EdgeInfo::Tolerance, "None", py::arg("tol"));
	cls_Draft_EdgeInfo.def("Tolerance", (Standard_Real (Draft_EdgeInfo::*)() const ) &Draft_EdgeInfo::Tolerance, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Draft_VertexInfo.hxx
	py::class_<Draft_VertexInfo, std::unique_ptr<Draft_VertexInfo, Deleter<Draft_VertexInfo>>> cls_Draft_VertexInfo(mod, "Draft_VertexInfo", "None");
	cls_Draft_VertexInfo.def(py::init<>());
	cls_Draft_VertexInfo.def("Add", (void (Draft_VertexInfo::*)(const TopoDS_Edge &)) &Draft_VertexInfo::Add, "None", py::arg("E"));
	cls_Draft_VertexInfo.def("Geometry", (const gp_Pnt & (Draft_VertexInfo::*)() const ) &Draft_VertexInfo::Geometry, "None");
	cls_Draft_VertexInfo.def("Parameter", (Standard_Real (Draft_VertexInfo::*)(const TopoDS_Edge &)) &Draft_VertexInfo::Parameter, "None", py::arg("E"));
	cls_Draft_VertexInfo.def("InitEdgeIterator", (void (Draft_VertexInfo::*)()) &Draft_VertexInfo::InitEdgeIterator, "None");
	cls_Draft_VertexInfo.def("Edge", (const TopoDS_Edge & (Draft_VertexInfo::*)() const ) &Draft_VertexInfo::Edge, "None");
	cls_Draft_VertexInfo.def("NextEdge", (void (Draft_VertexInfo::*)()) &Draft_VertexInfo::NextEdge, "None");
	cls_Draft_VertexInfo.def("MoreEdge", (Standard_Boolean (Draft_VertexInfo::*)() const ) &Draft_VertexInfo::MoreEdge, "None");
	cls_Draft_VertexInfo.def("ChangeGeometry", (gp_Pnt & (Draft_VertexInfo::*)()) &Draft_VertexInfo::ChangeGeometry, "None");
	cls_Draft_VertexInfo.def("ChangeParameter", (Standard_Real & (Draft_VertexInfo::*)(const TopoDS_Edge &)) &Draft_VertexInfo::ChangeParameter, "None", py::arg("E"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Draft.hxx
	py::class_<Draft, std::unique_ptr<Draft, Deleter<Draft>>> cls_Draft(mod, "Draft", "None");
	cls_Draft.def(py::init<>());
	cls_Draft.def_static("Angle_", (Standard_Real (*)(const TopoDS_Face &, const gp_Dir &)) &Draft::Angle, "Returns the draft angle of the face <F> using the direction <Direction>. The method is valid for : - Plane faces, - Cylindrical or conical faces, when the direction of the axis of the surface is colinear with the direction. Otherwise, the exception DomainError is raised.", py::arg("F"), py::arg("Direction"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Draft_IndexedDataMapOfEdgeEdgeInfo.hxx
	bind_NCollection_IndexedDataMap<TopoDS_Edge, Draft_EdgeInfo, TopTools_ShapeMapHasher>(mod, "Draft_IndexedDataMapOfEdgeEdgeInfo");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Draft_IndexedDataMapOfFaceFaceInfo.hxx
	bind_NCollection_IndexedDataMap<TopoDS_Face, Draft_FaceInfo, TopTools_ShapeMapHasher>(mod, "Draft_IndexedDataMapOfFaceFaceInfo");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Draft_IndexedDataMapOfVertexVertexInfo.hxx
	bind_NCollection_IndexedDataMap<TopoDS_Vertex, Draft_VertexInfo, TopTools_ShapeMapHasher>(mod, "Draft_IndexedDataMapOfVertexVertexInfo");


}
