#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

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

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedDataMap.hxx
	py::class_<Draft_IndexedDataMapOfEdgeEdgeInfo, std::unique_ptr<Draft_IndexedDataMapOfEdgeEdgeInfo, Deleter<Draft_IndexedDataMapOfEdgeEdgeInfo>>, NCollection_BaseMap> cls_Draft_IndexedDataMapOfEdgeEdgeInfo(mod, "Draft_IndexedDataMapOfEdgeEdgeInfo", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1.. Extent. An Item is stored with each key.");
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def(py::init<>());
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def(py::init([] (const Draft_IndexedDataMapOfEdgeEdgeInfo &other) {return new Draft_IndexedDataMapOfEdgeEdgeInfo(other);}), "Copy constructor", py::arg("other"));
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("begin", (Draft_IndexedDataMapOfEdgeEdgeInfo::iterator (Draft_IndexedDataMapOfEdgeEdgeInfo::*)() const ) &Draft_IndexedDataMapOfEdgeEdgeInfo::begin, "Returns an iterator pointing to the first element in the map.");
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("end", (Draft_IndexedDataMapOfEdgeEdgeInfo::iterator (Draft_IndexedDataMapOfEdgeEdgeInfo::*)() const ) &Draft_IndexedDataMapOfEdgeEdgeInfo::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("cbegin", (Draft_IndexedDataMapOfEdgeEdgeInfo::const_iterator (Draft_IndexedDataMapOfEdgeEdgeInfo::*)() const ) &Draft_IndexedDataMapOfEdgeEdgeInfo::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("cend", (Draft_IndexedDataMapOfEdgeEdgeInfo::const_iterator (Draft_IndexedDataMapOfEdgeEdgeInfo::*)() const ) &Draft_IndexedDataMapOfEdgeEdgeInfo::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("Exchange", (void (Draft_IndexedDataMapOfEdgeEdgeInfo::*)(Draft_IndexedDataMapOfEdgeEdgeInfo &)) &Draft_IndexedDataMapOfEdgeEdgeInfo::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("Assign", (Draft_IndexedDataMapOfEdgeEdgeInfo & (Draft_IndexedDataMapOfEdgeEdgeInfo::*)(const Draft_IndexedDataMapOfEdgeEdgeInfo &)) &Draft_IndexedDataMapOfEdgeEdgeInfo::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("assign", (Draft_IndexedDataMapOfEdgeEdgeInfo & (Draft_IndexedDataMapOfEdgeEdgeInfo::*)(const Draft_IndexedDataMapOfEdgeEdgeInfo &)) &Draft_IndexedDataMapOfEdgeEdgeInfo::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("ReSize", (void (Draft_IndexedDataMapOfEdgeEdgeInfo::*)(const Standard_Integer)) &Draft_IndexedDataMapOfEdgeEdgeInfo::ReSize, "ReSize", py::arg("N"));
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("Add", (Standard_Integer (Draft_IndexedDataMapOfEdgeEdgeInfo::*)(const TopoDS_Edge &, const Draft_EdgeInfo &)) &Draft_IndexedDataMapOfEdgeEdgeInfo::Add, "Add", py::arg("theKey1"), py::arg("theItem"));
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("Contains", (Standard_Boolean (Draft_IndexedDataMapOfEdgeEdgeInfo::*)(const TopoDS_Edge &) const ) &Draft_IndexedDataMapOfEdgeEdgeInfo::Contains, "Contains", py::arg("theKey1"));
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("Substitute", (void (Draft_IndexedDataMapOfEdgeEdgeInfo::*)(const Standard_Integer, const TopoDS_Edge &, const Draft_EdgeInfo &)) &Draft_IndexedDataMapOfEdgeEdgeInfo::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"), py::arg("theItem"));
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("Swap", (void (Draft_IndexedDataMapOfEdgeEdgeInfo::*)(const Standard_Integer, const Standard_Integer)) &Draft_IndexedDataMapOfEdgeEdgeInfo::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("RemoveLast", (void (Draft_IndexedDataMapOfEdgeEdgeInfo::*)()) &Draft_IndexedDataMapOfEdgeEdgeInfo::RemoveLast, "RemoveLast");
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("RemoveFromIndex", (void (Draft_IndexedDataMapOfEdgeEdgeInfo::*)(const Standard_Integer)) &Draft_IndexedDataMapOfEdgeEdgeInfo::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("RemoveKey", (void (Draft_IndexedDataMapOfEdgeEdgeInfo::*)(const TopoDS_Edge &)) &Draft_IndexedDataMapOfEdgeEdgeInfo::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("FindKey", (const TopoDS_Edge & (Draft_IndexedDataMapOfEdgeEdgeInfo::*)(const Standard_Integer) const ) &Draft_IndexedDataMapOfEdgeEdgeInfo::FindKey, "FindKey", py::arg("theKey2"));
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("FindFromIndex", (const Draft_EdgeInfo & (Draft_IndexedDataMapOfEdgeEdgeInfo::*)(const Standard_Integer) const ) &Draft_IndexedDataMapOfEdgeEdgeInfo::FindFromIndex, "FindFromIndex", py::arg("theKey2"));
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("__call__", (const Draft_EdgeInfo & (Draft_IndexedDataMapOfEdgeEdgeInfo::*)(const Standard_Integer) const ) &Draft_IndexedDataMapOfEdgeEdgeInfo::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("ChangeFromIndex", (Draft_EdgeInfo & (Draft_IndexedDataMapOfEdgeEdgeInfo::*)(const Standard_Integer)) &Draft_IndexedDataMapOfEdgeEdgeInfo::ChangeFromIndex, "ChangeFromIndex", py::arg("theKey2"));
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("__call__", (Draft_EdgeInfo & (Draft_IndexedDataMapOfEdgeEdgeInfo::*)(const Standard_Integer)) &Draft_IndexedDataMapOfEdgeEdgeInfo::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("FindIndex", (Standard_Integer (Draft_IndexedDataMapOfEdgeEdgeInfo::*)(const TopoDS_Edge &) const ) &Draft_IndexedDataMapOfEdgeEdgeInfo::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("FindFromKey", (const Draft_EdgeInfo & (Draft_IndexedDataMapOfEdgeEdgeInfo::*)(const TopoDS_Edge &) const ) &Draft_IndexedDataMapOfEdgeEdgeInfo::FindFromKey, "FindFromKey", py::arg("theKey1"));
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("ChangeFromKey", (Draft_EdgeInfo & (Draft_IndexedDataMapOfEdgeEdgeInfo::*)(const TopoDS_Edge &)) &Draft_IndexedDataMapOfEdgeEdgeInfo::ChangeFromKey, "ChangeFromKey", py::arg("theKey1"));
	// FIXME cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("Seek", (const Draft_EdgeInfo * (Draft_IndexedDataMapOfEdgeEdgeInfo::*)(const TopoDS_Edge &) const ) &Draft_IndexedDataMapOfEdgeEdgeInfo::Seek, "Seek returns pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	// FIXME cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("ChangeSeek", (Draft_EdgeInfo * (Draft_IndexedDataMapOfEdgeEdgeInfo::*)(const TopoDS_Edge &)) &Draft_IndexedDataMapOfEdgeEdgeInfo::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("FindFromKey", (Standard_Boolean (Draft_IndexedDataMapOfEdgeEdgeInfo::*)(const TopoDS_Edge &, Draft_EdgeInfo &) const ) &Draft_IndexedDataMapOfEdgeEdgeInfo::FindFromKey, "Find value for key with copying.", py::arg("theKey1"), py::arg("theValue"));
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("Clear", [](Draft_IndexedDataMapOfEdgeEdgeInfo &self) -> void { return self.Clear(); });
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("Clear", (void (Draft_IndexedDataMapOfEdgeEdgeInfo::*)(const Standard_Boolean)) &Draft_IndexedDataMapOfEdgeEdgeInfo::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("Clear", (void (Draft_IndexedDataMapOfEdgeEdgeInfo::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &Draft_IndexedDataMapOfEdgeEdgeInfo::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("Size", (Standard_Integer (Draft_IndexedDataMapOfEdgeEdgeInfo::*)() const ) &Draft_IndexedDataMapOfEdgeEdgeInfo::Size, "Size");
	cls_Draft_IndexedDataMapOfEdgeEdgeInfo.def("__iter__", [](const Draft_IndexedDataMapOfEdgeEdgeInfo &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedDataMap.hxx
	py::class_<Draft_IndexedDataMapOfFaceFaceInfo, std::unique_ptr<Draft_IndexedDataMapOfFaceFaceInfo, Deleter<Draft_IndexedDataMapOfFaceFaceInfo>>, NCollection_BaseMap> cls_Draft_IndexedDataMapOfFaceFaceInfo(mod, "Draft_IndexedDataMapOfFaceFaceInfo", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1.. Extent. An Item is stored with each key.");
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def(py::init<>());
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def(py::init([] (const Draft_IndexedDataMapOfFaceFaceInfo &other) {return new Draft_IndexedDataMapOfFaceFaceInfo(other);}), "Copy constructor", py::arg("other"));
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("begin", (Draft_IndexedDataMapOfFaceFaceInfo::iterator (Draft_IndexedDataMapOfFaceFaceInfo::*)() const ) &Draft_IndexedDataMapOfFaceFaceInfo::begin, "Returns an iterator pointing to the first element in the map.");
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("end", (Draft_IndexedDataMapOfFaceFaceInfo::iterator (Draft_IndexedDataMapOfFaceFaceInfo::*)() const ) &Draft_IndexedDataMapOfFaceFaceInfo::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("cbegin", (Draft_IndexedDataMapOfFaceFaceInfo::const_iterator (Draft_IndexedDataMapOfFaceFaceInfo::*)() const ) &Draft_IndexedDataMapOfFaceFaceInfo::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("cend", (Draft_IndexedDataMapOfFaceFaceInfo::const_iterator (Draft_IndexedDataMapOfFaceFaceInfo::*)() const ) &Draft_IndexedDataMapOfFaceFaceInfo::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("Exchange", (void (Draft_IndexedDataMapOfFaceFaceInfo::*)(Draft_IndexedDataMapOfFaceFaceInfo &)) &Draft_IndexedDataMapOfFaceFaceInfo::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("Assign", (Draft_IndexedDataMapOfFaceFaceInfo & (Draft_IndexedDataMapOfFaceFaceInfo::*)(const Draft_IndexedDataMapOfFaceFaceInfo &)) &Draft_IndexedDataMapOfFaceFaceInfo::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("assign", (Draft_IndexedDataMapOfFaceFaceInfo & (Draft_IndexedDataMapOfFaceFaceInfo::*)(const Draft_IndexedDataMapOfFaceFaceInfo &)) &Draft_IndexedDataMapOfFaceFaceInfo::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("ReSize", (void (Draft_IndexedDataMapOfFaceFaceInfo::*)(const Standard_Integer)) &Draft_IndexedDataMapOfFaceFaceInfo::ReSize, "ReSize", py::arg("N"));
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("Add", (Standard_Integer (Draft_IndexedDataMapOfFaceFaceInfo::*)(const TopoDS_Face &, const Draft_FaceInfo &)) &Draft_IndexedDataMapOfFaceFaceInfo::Add, "Add", py::arg("theKey1"), py::arg("theItem"));
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("Contains", (Standard_Boolean (Draft_IndexedDataMapOfFaceFaceInfo::*)(const TopoDS_Face &) const ) &Draft_IndexedDataMapOfFaceFaceInfo::Contains, "Contains", py::arg("theKey1"));
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("Substitute", (void (Draft_IndexedDataMapOfFaceFaceInfo::*)(const Standard_Integer, const TopoDS_Face &, const Draft_FaceInfo &)) &Draft_IndexedDataMapOfFaceFaceInfo::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"), py::arg("theItem"));
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("Swap", (void (Draft_IndexedDataMapOfFaceFaceInfo::*)(const Standard_Integer, const Standard_Integer)) &Draft_IndexedDataMapOfFaceFaceInfo::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("RemoveLast", (void (Draft_IndexedDataMapOfFaceFaceInfo::*)()) &Draft_IndexedDataMapOfFaceFaceInfo::RemoveLast, "RemoveLast");
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("RemoveFromIndex", (void (Draft_IndexedDataMapOfFaceFaceInfo::*)(const Standard_Integer)) &Draft_IndexedDataMapOfFaceFaceInfo::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("RemoveKey", (void (Draft_IndexedDataMapOfFaceFaceInfo::*)(const TopoDS_Face &)) &Draft_IndexedDataMapOfFaceFaceInfo::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("FindKey", (const TopoDS_Face & (Draft_IndexedDataMapOfFaceFaceInfo::*)(const Standard_Integer) const ) &Draft_IndexedDataMapOfFaceFaceInfo::FindKey, "FindKey", py::arg("theKey2"));
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("FindFromIndex", (const Draft_FaceInfo & (Draft_IndexedDataMapOfFaceFaceInfo::*)(const Standard_Integer) const ) &Draft_IndexedDataMapOfFaceFaceInfo::FindFromIndex, "FindFromIndex", py::arg("theKey2"));
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("__call__", (const Draft_FaceInfo & (Draft_IndexedDataMapOfFaceFaceInfo::*)(const Standard_Integer) const ) &Draft_IndexedDataMapOfFaceFaceInfo::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("ChangeFromIndex", (Draft_FaceInfo & (Draft_IndexedDataMapOfFaceFaceInfo::*)(const Standard_Integer)) &Draft_IndexedDataMapOfFaceFaceInfo::ChangeFromIndex, "ChangeFromIndex", py::arg("theKey2"));
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("__call__", (Draft_FaceInfo & (Draft_IndexedDataMapOfFaceFaceInfo::*)(const Standard_Integer)) &Draft_IndexedDataMapOfFaceFaceInfo::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("FindIndex", (Standard_Integer (Draft_IndexedDataMapOfFaceFaceInfo::*)(const TopoDS_Face &) const ) &Draft_IndexedDataMapOfFaceFaceInfo::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("FindFromKey", (const Draft_FaceInfo & (Draft_IndexedDataMapOfFaceFaceInfo::*)(const TopoDS_Face &) const ) &Draft_IndexedDataMapOfFaceFaceInfo::FindFromKey, "FindFromKey", py::arg("theKey1"));
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("ChangeFromKey", (Draft_FaceInfo & (Draft_IndexedDataMapOfFaceFaceInfo::*)(const TopoDS_Face &)) &Draft_IndexedDataMapOfFaceFaceInfo::ChangeFromKey, "ChangeFromKey", py::arg("theKey1"));
	// FIXME cls_Draft_IndexedDataMapOfFaceFaceInfo.def("Seek", (const Draft_FaceInfo * (Draft_IndexedDataMapOfFaceFaceInfo::*)(const TopoDS_Face &) const ) &Draft_IndexedDataMapOfFaceFaceInfo::Seek, "Seek returns pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	// FIXME cls_Draft_IndexedDataMapOfFaceFaceInfo.def("ChangeSeek", (Draft_FaceInfo * (Draft_IndexedDataMapOfFaceFaceInfo::*)(const TopoDS_Face &)) &Draft_IndexedDataMapOfFaceFaceInfo::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("FindFromKey", (Standard_Boolean (Draft_IndexedDataMapOfFaceFaceInfo::*)(const TopoDS_Face &, Draft_FaceInfo &) const ) &Draft_IndexedDataMapOfFaceFaceInfo::FindFromKey, "Find value for key with copying.", py::arg("theKey1"), py::arg("theValue"));
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("Clear", [](Draft_IndexedDataMapOfFaceFaceInfo &self) -> void { return self.Clear(); });
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("Clear", (void (Draft_IndexedDataMapOfFaceFaceInfo::*)(const Standard_Boolean)) &Draft_IndexedDataMapOfFaceFaceInfo::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("Clear", (void (Draft_IndexedDataMapOfFaceFaceInfo::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &Draft_IndexedDataMapOfFaceFaceInfo::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("Size", (Standard_Integer (Draft_IndexedDataMapOfFaceFaceInfo::*)() const ) &Draft_IndexedDataMapOfFaceFaceInfo::Size, "Size");
	cls_Draft_IndexedDataMapOfFaceFaceInfo.def("__iter__", [](const Draft_IndexedDataMapOfFaceFaceInfo &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());

	// C:\Miniconda\envs\occt\Library\include\opencascade\NCollection_IndexedDataMap.hxx
	py::class_<Draft_IndexedDataMapOfVertexVertexInfo, std::unique_ptr<Draft_IndexedDataMapOfVertexVertexInfo, Deleter<Draft_IndexedDataMapOfVertexVertexInfo>>, NCollection_BaseMap> cls_Draft_IndexedDataMapOfVertexVertexInfo(mod, "Draft_IndexedDataMapOfVertexVertexInfo", "Purpose: An indexed map is used to store keys and to bind an index to them. Each new key stored in the map gets an index. Index are incremented as keys are stored in the map. A key can be found by the index and an index by the key. No key but the last can be removed so the indices are in the range 1.. Extent. An Item is stored with each key.");
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def(py::init<>());
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def(py::init<const Standard_Integer>(), py::arg("NbBuckets"));
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def(py::init<const Standard_Integer, const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("NbBuckets"), py::arg("theAllocator"));
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def(py::init([] (const Draft_IndexedDataMapOfVertexVertexInfo &other) {return new Draft_IndexedDataMapOfVertexVertexInfo(other);}), "Copy constructor", py::arg("other"));
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("begin", (Draft_IndexedDataMapOfVertexVertexInfo::iterator (Draft_IndexedDataMapOfVertexVertexInfo::*)() const ) &Draft_IndexedDataMapOfVertexVertexInfo::begin, "Returns an iterator pointing to the first element in the map.");
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("end", (Draft_IndexedDataMapOfVertexVertexInfo::iterator (Draft_IndexedDataMapOfVertexVertexInfo::*)() const ) &Draft_IndexedDataMapOfVertexVertexInfo::end, "Returns an iterator referring to the past-the-end element in the map.");
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("cbegin", (Draft_IndexedDataMapOfVertexVertexInfo::const_iterator (Draft_IndexedDataMapOfVertexVertexInfo::*)() const ) &Draft_IndexedDataMapOfVertexVertexInfo::cbegin, "Returns a const iterator pointing to the first element in the map.");
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("cend", (Draft_IndexedDataMapOfVertexVertexInfo::const_iterator (Draft_IndexedDataMapOfVertexVertexInfo::*)() const ) &Draft_IndexedDataMapOfVertexVertexInfo::cend, "Returns a const iterator referring to the past-the-end element in the map.");
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("Exchange", (void (Draft_IndexedDataMapOfVertexVertexInfo::*)(Draft_IndexedDataMapOfVertexVertexInfo &)) &Draft_IndexedDataMapOfVertexVertexInfo::Exchange, "Exchange the content of two maps without re-allocations. Notice that allocators will be swapped as well!", py::arg("theOther"));
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("Assign", (Draft_IndexedDataMapOfVertexVertexInfo & (Draft_IndexedDataMapOfVertexVertexInfo::*)(const Draft_IndexedDataMapOfVertexVertexInfo &)) &Draft_IndexedDataMapOfVertexVertexInfo::Assign, "Assignment. This method does not change the internal allocator.", py::arg("theOther"));
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("assign", (Draft_IndexedDataMapOfVertexVertexInfo & (Draft_IndexedDataMapOfVertexVertexInfo::*)(const Draft_IndexedDataMapOfVertexVertexInfo &)) &Draft_IndexedDataMapOfVertexVertexInfo::operator=, py::is_operator(), "Assignment operator", py::arg("theOther"));
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("ReSize", (void (Draft_IndexedDataMapOfVertexVertexInfo::*)(const Standard_Integer)) &Draft_IndexedDataMapOfVertexVertexInfo::ReSize, "ReSize", py::arg("N"));
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("Add", (Standard_Integer (Draft_IndexedDataMapOfVertexVertexInfo::*)(const TopoDS_Vertex &, const Draft_VertexInfo &)) &Draft_IndexedDataMapOfVertexVertexInfo::Add, "Add", py::arg("theKey1"), py::arg("theItem"));
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("Contains", (Standard_Boolean (Draft_IndexedDataMapOfVertexVertexInfo::*)(const TopoDS_Vertex &) const ) &Draft_IndexedDataMapOfVertexVertexInfo::Contains, "Contains", py::arg("theKey1"));
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("Substitute", (void (Draft_IndexedDataMapOfVertexVertexInfo::*)(const Standard_Integer, const TopoDS_Vertex &, const Draft_VertexInfo &)) &Draft_IndexedDataMapOfVertexVertexInfo::Substitute, "Substitute", py::arg("theIndex"), py::arg("theKey1"), py::arg("theItem"));
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("Swap", (void (Draft_IndexedDataMapOfVertexVertexInfo::*)(const Standard_Integer, const Standard_Integer)) &Draft_IndexedDataMapOfVertexVertexInfo::Swap, "Swaps two elements with the given indices.", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("RemoveLast", (void (Draft_IndexedDataMapOfVertexVertexInfo::*)()) &Draft_IndexedDataMapOfVertexVertexInfo::RemoveLast, "RemoveLast");
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("RemoveFromIndex", (void (Draft_IndexedDataMapOfVertexVertexInfo::*)(const Standard_Integer)) &Draft_IndexedDataMapOfVertexVertexInfo::RemoveFromIndex, "Remove the key of the given index. Caution! The index of the last key can be changed.", py::arg("theKey2"));
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("RemoveKey", (void (Draft_IndexedDataMapOfVertexVertexInfo::*)(const TopoDS_Vertex &)) &Draft_IndexedDataMapOfVertexVertexInfo::RemoveKey, "Remove the given key. Caution! The index of the last key can be changed.", py::arg("theKey1"));
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("FindKey", (const TopoDS_Vertex & (Draft_IndexedDataMapOfVertexVertexInfo::*)(const Standard_Integer) const ) &Draft_IndexedDataMapOfVertexVertexInfo::FindKey, "FindKey", py::arg("theKey2"));
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("FindFromIndex", (const Draft_VertexInfo & (Draft_IndexedDataMapOfVertexVertexInfo::*)(const Standard_Integer) const ) &Draft_IndexedDataMapOfVertexVertexInfo::FindFromIndex, "FindFromIndex", py::arg("theKey2"));
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("__call__", (const Draft_VertexInfo & (Draft_IndexedDataMapOfVertexVertexInfo::*)(const Standard_Integer) const ) &Draft_IndexedDataMapOfVertexVertexInfo::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("ChangeFromIndex", (Draft_VertexInfo & (Draft_IndexedDataMapOfVertexVertexInfo::*)(const Standard_Integer)) &Draft_IndexedDataMapOfVertexVertexInfo::ChangeFromIndex, "ChangeFromIndex", py::arg("theKey2"));
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("__call__", (Draft_VertexInfo & (Draft_IndexedDataMapOfVertexVertexInfo::*)(const Standard_Integer)) &Draft_IndexedDataMapOfVertexVertexInfo::operator(), py::is_operator(), "operator ()", py::arg("theKey2"));
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("FindIndex", (Standard_Integer (Draft_IndexedDataMapOfVertexVertexInfo::*)(const TopoDS_Vertex &) const ) &Draft_IndexedDataMapOfVertexVertexInfo::FindIndex, "FindIndex", py::arg("theKey1"));
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("FindFromKey", (const Draft_VertexInfo & (Draft_IndexedDataMapOfVertexVertexInfo::*)(const TopoDS_Vertex &) const ) &Draft_IndexedDataMapOfVertexVertexInfo::FindFromKey, "FindFromKey", py::arg("theKey1"));
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("ChangeFromKey", (Draft_VertexInfo & (Draft_IndexedDataMapOfVertexVertexInfo::*)(const TopoDS_Vertex &)) &Draft_IndexedDataMapOfVertexVertexInfo::ChangeFromKey, "ChangeFromKey", py::arg("theKey1"));
	// FIXME cls_Draft_IndexedDataMapOfVertexVertexInfo.def("Seek", (const Draft_VertexInfo * (Draft_IndexedDataMapOfVertexVertexInfo::*)(const TopoDS_Vertex &) const ) &Draft_IndexedDataMapOfVertexVertexInfo::Seek, "Seek returns pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	// FIXME cls_Draft_IndexedDataMapOfVertexVertexInfo.def("ChangeSeek", (Draft_VertexInfo * (Draft_IndexedDataMapOfVertexVertexInfo::*)(const TopoDS_Vertex &)) &Draft_IndexedDataMapOfVertexVertexInfo::ChangeSeek, "ChangeSeek returns modifiable pointer to Item by Key. Returns NULL if Key was not found.", py::arg("theKey1"));
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("FindFromKey", (Standard_Boolean (Draft_IndexedDataMapOfVertexVertexInfo::*)(const TopoDS_Vertex &, Draft_VertexInfo &) const ) &Draft_IndexedDataMapOfVertexVertexInfo::FindFromKey, "Find value for key with copying.", py::arg("theKey1"), py::arg("theValue"));
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("Clear", [](Draft_IndexedDataMapOfVertexVertexInfo &self) -> void { return self.Clear(); });
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("Clear", (void (Draft_IndexedDataMapOfVertexVertexInfo::*)(const Standard_Boolean)) &Draft_IndexedDataMapOfVertexVertexInfo::Clear, "Clear data. If doReleaseMemory is false then the table of buckets is not released and will be reused.", py::arg("doReleaseMemory"));
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("Clear", (void (Draft_IndexedDataMapOfVertexVertexInfo::*)(const opencascade::handle<NCollection_BaseAllocator> &)) &Draft_IndexedDataMapOfVertexVertexInfo::Clear, "Clear data and reset allocator", py::arg("theAllocator"));
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("Size", (Standard_Integer (Draft_IndexedDataMapOfVertexVertexInfo::*)() const ) &Draft_IndexedDataMapOfVertexVertexInfo::Size, "Size");
	cls_Draft_IndexedDataMapOfVertexVertexInfo.def("__iter__", [](const Draft_IndexedDataMapOfVertexVertexInfo &s) { return py::make_iterator(s.begin(), s.end()); }, py::keep_alive<0, 1>());


}
