#include <pyOCCT_Common.hpp>

#include <BVH_Box.hxx>
#include <Standard_TypeDef.hxx>
#include <Select3D_BndBox3d.hxx>
#include <NCollection_Vec2.hxx>
#include <NCollection_Vec3.hxx>
#include <BVH_Builder.hxx>
#include <BVH_Set.hxx>
#include <BVH_Tree.hxx>
#include <Select3D_BVHBuilder3d.hxx>
#include <Select3D_TypeOfSensitivity.hxx>
#include <SelectBasics_SensitiveEntity.hxx>
#include <Standard_Handle.hxx>
#include <Select3D_SensitiveEntity.hxx>
#include <SelectBasics_SelectingVolumeManager.hxx>
#include <SelectBasics_PickResult.hxx>
#include <gp_Pnt.hxx>
#include <gp_GTrsf.hxx>
#include <Standard_Type.hxx>
#include <SelectBasics_EntityOwner.hxx>
#include <Select3D_SensitiveSet.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <Select3D_SensitiveFace.hxx>
#include <Select3D_SensitiveSegment.hxx>
#include <Graphic3d_Buffer.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Select3D_BVHIndexBuffer.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <Select3D_EntitySequence.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_IndexedMap.hxx>
#include <Select3D_IndexedMapOfEntity.hxx>
#include <Select3D_Pnt.hxx>
#include <Select3D_PointData.hxx>
#include <Select3D_SensitivePoly.hxx>
#include <NCollection_BaseVector.hxx>
#include <NCollection_Vector.hxx>
#include <Select3D_InteriorSensitivePointSet.hxx>
#include <Bnd_Box.hxx>
#include <Select3D_SensitiveBox.hxx>
#include <Geom_Circle.hxx>
#include <Select3D_SensitiveCircle.hxx>
#include <Geom_Curve.hxx>
#include <Select3D_SensitiveCurve.hxx>
#include <Select3D_SensitiveGroup.hxx>
#include <Select3D_SensitivePoint.hxx>
#include <Graphic3d_IndexBuffer.hxx>
#include <TopLoc_Location.hxx>
#include <TColStd_HPackedMapOfInteger.hxx>
#include <Select3D_SensitivePrimitiveArray.hxx>
#include <Select3D_SensitiveTriangle.hxx>
#include <Poly_Triangulation.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <Select3D_SensitiveTriangulation.hxx>
#include <Select3D_SensitiveWire.hxx>
#include <BVH_Templates.hpp>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(Select3D, mod) {

	// IMPORT
	py::module::import("OCCT.BVH");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.SelectBasics");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.TColgp");
	py::module::import("OCCT.Graphic3d");
	py::module::import("OCCT.Bnd");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.TopLoc");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.Poly");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\Select3D_TypeOfSensitivity.hxx
	py::enum_<Select3D_TypeOfSensitivity>(mod, "Select3D_TypeOfSensitivity", "Provides values for type of sensitivity in 3D. These are used to specify whether it is the interior, the boundary, or the exterior of a 3D sensitive entity which is sensitive.")
		.value("Select3D_TOS_INTERIOR", Select3D_TypeOfSensitivity::Select3D_TOS_INTERIOR)
		.value("Select3D_TOS_BOUNDARY", Select3D_TypeOfSensitivity::Select3D_TOS_BOUNDARY)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Select3D_SensitiveEntity.hxx
	py::class_<Select3D_SensitiveEntity, opencascade::handle<Select3D_SensitiveEntity>, SelectBasics_SensitiveEntity> cls_Select3D_SensitiveEntity(mod, "Select3D_SensitiveEntity", "Abstract framework to define 3D sensitive entities. As the selection process uses the principle of a projection of 3D shapes onto a 2D view where nearness to a rectangle determines whether a shape is picked or not, all 3D shapes need to be converted into 2D ones in order to be selected.");
	cls_Select3D_SensitiveEntity.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitiveEntity::*)()) &Select3D_SensitiveEntity::GetConnected, "Originally this method intended to return sensitive entity with new location aLocation, but currently sensitive entities do not hold a location, instead HasLocation() and Location() methods call corresponding entity owner's methods. Thus all entities returned by GetConnected() share the same location propagated from corresponding selectable object. You must redefine this function for any type of sensitive entity which can accept another connected sensitive entity.//can be connected to another sensitive entity.");
	cls_Select3D_SensitiveEntity.def("Matches", (Standard_Boolean (Select3D_SensitiveEntity::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &Select3D_SensitiveEntity::Matches, "Checks whether sensitive overlaps current selecting volume. Stores minimum depth, distance to center of geometry and closest point detected into thePickResult", py::arg("theMgr"), py::arg("thePickResult"));
	cls_Select3D_SensitiveEntity.def("NbSubElements", (Standard_Integer (Select3D_SensitiveEntity::*)()) &Select3D_SensitiveEntity::NbSubElements, "Returns the number of sub-entities or elements in sensitive entity. Is used to determine if entity is complex and needs to pre-build BVH at the creation of sensitive entity step or is light-weighted so the tree can be build on demand with unnoticeable delay");
	cls_Select3D_SensitiveEntity.def("BoundingBox", (Select3D_BndBox3d (Select3D_SensitiveEntity::*)()) &Select3D_SensitiveEntity::BoundingBox, "Returns bounding box of a sensitive with transformation applied");
	cls_Select3D_SensitiveEntity.def("CenterOfGeometry", (gp_Pnt (Select3D_SensitiveEntity::*)() const ) &Select3D_SensitiveEntity::CenterOfGeometry, "Returns center of a sensitive with transformation applied");
	cls_Select3D_SensitiveEntity.def("BVH", (void (Select3D_SensitiveEntity::*)()) &Select3D_SensitiveEntity::BVH, "Builds BVH tree for a sensitive if needed");
	cls_Select3D_SensitiveEntity.def("Clear", (void (Select3D_SensitiveEntity::*)()) &Select3D_SensitiveEntity::Clear, "Clears up all resources and memory");
	cls_Select3D_SensitiveEntity.def("HasInitLocation", (Standard_Boolean (Select3D_SensitiveEntity::*)() const ) &Select3D_SensitiveEntity::HasInitLocation, "Returns true if the shape corresponding to the entity has init location");
	cls_Select3D_SensitiveEntity.def("InvInitLocation", (gp_GTrsf (Select3D_SensitiveEntity::*)() const ) &Select3D_SensitiveEntity::InvInitLocation, "Returns inversed location transformation matrix if the shape corresponding to this entity has init location set. Otherwise, returns identity matrix.");
	cls_Select3D_SensitiveEntity.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitiveEntity::get_type_name, "None");
	cls_Select3D_SensitiveEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitiveEntity::get_type_descriptor, "None");
	cls_Select3D_SensitiveEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitiveEntity::*)() const ) &Select3D_SensitiveEntity::DynamicType, "None");

	// Callback for Select3D_SensitiveSet.
	class PyCallback_Select3D_SensitiveSet : public Select3D_SensitiveSet {
	public:
		using Select3D_SensitiveSet::Select3D_SensitiveSet;

		Standard_Integer NbSubElements() override { PYBIND11_OVERLOAD_PURE(Standard_Integer, Select3D_SensitiveSet, NbSubElements, ); }
		Standard_Integer Size() const  override { PYBIND11_OVERLOAD_PURE(Standard_Integer, Select3D_SensitiveSet, Size, ); }
		Select3D_BndBox3d Box(const Standard_Integer theIdx) const  override { PYBIND11_OVERLOAD_PURE(Select3D_BndBox3d, Select3D_SensitiveSet, Box, theIdx); }
		Standard_Real Center(const Standard_Integer theIdx, const Standard_Integer theAxis) const  override { PYBIND11_OVERLOAD_PURE(Standard_Real, Select3D_SensitiveSet, Center, theIdx, theAxis); }
		void Swap(const Standard_Integer theIdx1, const Standard_Integer theIdx2) override { PYBIND11_OVERLOAD_PURE(void, Select3D_SensitiveSet, Swap, theIdx1, theIdx2); }
		Standard_Boolean overlapsElement(SelectBasics_SelectingVolumeManager & theMgr, Standard_Integer theElemIdx, Standard_Real & theMatchDepth) override { PYBIND11_OVERLOAD_PURE(Standard_Boolean, Select3D_SensitiveSet, overlapsElement, theMgr, theElemIdx, theMatchDepth); }
		Standard_Boolean elementIsInside(SelectBasics_SelectingVolumeManager & theMgr, const Standard_Integer theElemIdx) override { PYBIND11_OVERLOAD_PURE(Standard_Boolean, Select3D_SensitiveSet, elementIsInside, theMgr, theElemIdx); }
		Standard_Real distanceToCOG(SelectBasics_SelectingVolumeManager & theMgr) override { PYBIND11_OVERLOAD_PURE(Standard_Real, Select3D_SensitiveSet, distanceToCOG, theMgr); }
	};

	// C:\Miniconda\envs\occt\Library\include\opencascade\Select3D_SensitiveSet.hxx
	py::class_<Select3D_SensitiveSet, opencascade::handle<Select3D_SensitiveSet>, PyCallback_Select3D_SensitiveSet, Select3D_SensitiveEntity> cls_Select3D_SensitiveSet(mod, "Select3D_SensitiveSet", "This class is base class for handling overlap detection of complex sensitive entities. It provides an interface for building BVH tree for some set of entities. Thereby, each iteration of overlap detection is a traverse of BVH tree in fact. To use speed-up hierarchical structure in a custom complex sensitive entity, it is necessary to make that custom entity a descendant of this class and organize sub-entities in some container which allows referencing to elements by index. Note that methods taking index as a parameter are used for BVH build and the range of given index is [0; Size() - 1]. For example of usage see Select3D_SensitiveTriangulation.");
	cls_Select3D_SensitiveSet.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &>(), py::arg("theOwnerId"));
	cls_Select3D_SensitiveSet.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitiveSet::get_type_name, "None");
	cls_Select3D_SensitiveSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitiveSet::get_type_descriptor, "None");
	cls_Select3D_SensitiveSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitiveSet::*)() const ) &Select3D_SensitiveSet::DynamicType, "None");
	cls_Select3D_SensitiveSet.def_static("DefaultBVHBuilder_", (const opencascade::handle<Select3D_BVHBuilder3d> & (*)()) &Select3D_SensitiveSet::DefaultBVHBuilder, "Return global instance to default BVH builder.");
	cls_Select3D_SensitiveSet.def_static("SetDefaultBVHBuilder_", (void (*)(const opencascade::handle<Select3D_BVHBuilder3d> &)) &Select3D_SensitiveSet::SetDefaultBVHBuilder, "Assign new BVH builder to be used by default for new sensitive sets (assigning is NOT thread-safe!).", py::arg("theBuilder"));
	cls_Select3D_SensitiveSet.def("Size", (Standard_Integer (Select3D_SensitiveSet::*)() const ) &Select3D_SensitiveSet::Size, "Returns the amount of sub-entities of the complex entity");
	cls_Select3D_SensitiveSet.def("Box", (Select3D_BndBox3d (Select3D_SensitiveSet::*)(const Standard_Integer) const ) &Select3D_SensitiveSet::Box, "Returns bounding box of sub-entity with index theIdx in sub-entity list", py::arg("theIdx"));
	cls_Select3D_SensitiveSet.def("Center", (Standard_Real (Select3D_SensitiveSet::*)(const Standard_Integer, const Standard_Integer) const ) &Select3D_SensitiveSet::Center, "Returns geometry center of sensitive entity index theIdx along the given axis theAxis", py::arg("theIdx"), py::arg("theAxis"));
	cls_Select3D_SensitiveSet.def("Swap", (void (Select3D_SensitiveSet::*)(const Standard_Integer, const Standard_Integer)) &Select3D_SensitiveSet::Swap, "Swaps items with indexes theIdx1 and theIdx2", py::arg("theIdx1"), py::arg("theIdx2"));
	cls_Select3D_SensitiveSet.def("Matches", (Standard_Boolean (Select3D_SensitiveSet::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &Select3D_SensitiveSet::Matches, "Checks whether one or more entities of the set overlap current selecting volume. Implements the traverse of BVH tree built for the set", py::arg("theMgr"), py::arg("thePickResult"));
	cls_Select3D_SensitiveSet.def("BVH", (void (Select3D_SensitiveSet::*)()) &Select3D_SensitiveSet::BVH, "Builds BVH tree for sensitive set. Must be called manually to build BVH tree for any sensitive set in case if its content was initialized not in a constructor, but element by element");
	cls_Select3D_SensitiveSet.def("SetBuilder", (void (Select3D_SensitiveSet::*)(const opencascade::handle<Select3D_BVHBuilder3d> &)) &Select3D_SensitiveSet::SetBuilder, "Sets the method (builder) used to construct BVH.", py::arg("theBuilder"));
	cls_Select3D_SensitiveSet.def("MarkDirty", (void (Select3D_SensitiveSet::*)()) &Select3D_SensitiveSet::MarkDirty, "Marks BVH tree of the set as outdated. It will be rebuild at the next call of BVH()");
	cls_Select3D_SensitiveSet.def("BoundingBox", (Select3D_BndBox3d (Select3D_SensitiveSet::*)()) &Select3D_SensitiveSet::BoundingBox, "Returns bounding box of the whole set. This method should be redefined in Select3D_SensitiveSet descendants");
	cls_Select3D_SensitiveSet.def("CenterOfGeometry", (gp_Pnt (Select3D_SensitiveSet::*)() const ) &Select3D_SensitiveSet::CenterOfGeometry, "Returns center of the whole set. This method should be redefined in Select3D_SensitiveSet descendants");
	cls_Select3D_SensitiveSet.def("Clear", (void (Select3D_SensitiveSet::*)()) &Select3D_SensitiveSet::Clear, "Destroys cross-reference to avoid memory leak");
	cls_Select3D_SensitiveSet.def("GetLeafNodeSize", (Standard_Integer (Select3D_SensitiveSet::*)() const ) &Select3D_SensitiveSet::GetLeafNodeSize, "Returns a number of nodes in 1 BVH leaf");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Select3D_SensitiveFace.hxx
	py::class_<Select3D_SensitiveFace, opencascade::handle<Select3D_SensitiveFace>, Select3D_SensitiveEntity> cls_Select3D_SensitiveFace(mod, "Select3D_SensitiveFace", "Sensitive Entity to make a face selectable. In some cases this class can raise Standard_ConstructionError and Standard_OutOfRange exceptions. For more details see Select3D_SensitivePoly.");
	cls_Select3D_SensitiveFace.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const TColgp_Array1OfPnt &, const Select3D_TypeOfSensitivity>(), py::arg("theOwnerId"), py::arg("thePoints"), py::arg("theType"));
	cls_Select3D_SensitiveFace.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<TColgp_HArray1OfPnt> &, const Select3D_TypeOfSensitivity>(), py::arg("theOwnerId"), py::arg("thePoints"), py::arg("theType"));
	cls_Select3D_SensitiveFace.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitiveFace::get_type_name, "None");
	cls_Select3D_SensitiveFace.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitiveFace::get_type_descriptor, "None");
	cls_Select3D_SensitiveFace.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitiveFace::*)() const ) &Select3D_SensitiveFace::DynamicType, "None");
	cls_Select3D_SensitiveFace.def("GetPoints", (void (Select3D_SensitiveFace::*)(opencascade::handle<TColgp_HArray1OfPnt> &)) &Select3D_SensitiveFace::GetPoints, "Initializes the given array theHArrayOfPnt by 3d coordinates of vertices of the face", py::arg("theHArrayOfPnt"));
	cls_Select3D_SensitiveFace.def("Matches", (Standard_Boolean (Select3D_SensitiveFace::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &Select3D_SensitiveFace::Matches, "Checks whether the face overlaps current selecting volume", py::arg("theMgr"), py::arg("thePickResult"));
	cls_Select3D_SensitiveFace.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitiveFace::*)()) &Select3D_SensitiveFace::GetConnected, "None");
	cls_Select3D_SensitiveFace.def("BoundingBox", (Select3D_BndBox3d (Select3D_SensitiveFace::*)()) &Select3D_SensitiveFace::BoundingBox, "Returns bounding box of the face. If location transformation is set, it will be applied");
	cls_Select3D_SensitiveFace.def("CenterOfGeometry", (gp_Pnt (Select3D_SensitiveFace::*)() const ) &Select3D_SensitiveFace::CenterOfGeometry, "Returns center of the face. If location transformation is set, it will be applied");
	cls_Select3D_SensitiveFace.def("BVH", (void (Select3D_SensitiveFace::*)()) &Select3D_SensitiveFace::BVH, "Builds BVH tree for the face");
	cls_Select3D_SensitiveFace.def("NbSubElements", (Standard_Integer (Select3D_SensitiveFace::*)()) &Select3D_SensitiveFace::NbSubElements, "Returns the amount of sub-entities (points or planar convex polygons)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Select3D_SensitiveSegment.hxx
	py::class_<Select3D_SensitiveSegment, opencascade::handle<Select3D_SensitiveSegment>, Select3D_SensitiveEntity> cls_Select3D_SensitiveSegment(mod, "Select3D_SensitiveSegment", "A framework to define sensitive zones along a segment One gives the 3D start and end point");
	cls_Select3D_SensitiveSegment.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const gp_Pnt &, const gp_Pnt &>(), py::arg("theOwnerId"), py::arg("theFirstPnt"), py::arg("theLastPnt"));
	cls_Select3D_SensitiveSegment.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitiveSegment::get_type_name, "None");
	cls_Select3D_SensitiveSegment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitiveSegment::get_type_descriptor, "None");
	cls_Select3D_SensitiveSegment.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitiveSegment::*)() const ) &Select3D_SensitiveSegment::DynamicType, "None");
	cls_Select3D_SensitiveSegment.def("SetStartPoint", (void (Select3D_SensitiveSegment::*)(const gp_Pnt &)) &Select3D_SensitiveSegment::SetStartPoint, "changes the start Point of the Segment;", py::arg("thePnt"));
	cls_Select3D_SensitiveSegment.def("SetEndPoint", (void (Select3D_SensitiveSegment::*)(const gp_Pnt &)) &Select3D_SensitiveSegment::SetEndPoint, "changes the end point of the segment", py::arg("thePnt"));
	cls_Select3D_SensitiveSegment.def("StartPoint", (const gp_Pnt & (Select3D_SensitiveSegment::*)() const ) &Select3D_SensitiveSegment::StartPoint, "gives the 3D start Point of the Segment");
	cls_Select3D_SensitiveSegment.def("EndPoint", (const gp_Pnt & (Select3D_SensitiveSegment::*)() const ) &Select3D_SensitiveSegment::EndPoint, "gives the 3D End Point of the Segment");
	cls_Select3D_SensitiveSegment.def("NbSubElements", (Standard_Integer (Select3D_SensitiveSegment::*)()) &Select3D_SensitiveSegment::NbSubElements, "Returns the amount of points");
	cls_Select3D_SensitiveSegment.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitiveSegment::*)()) &Select3D_SensitiveSegment::GetConnected, "None");
	cls_Select3D_SensitiveSegment.def("Matches", (Standard_Boolean (Select3D_SensitiveSegment::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &Select3D_SensitiveSegment::Matches, "Checks whether the segment overlaps current selecting volume", py::arg("theMgr"), py::arg("thePickResult"));
	cls_Select3D_SensitiveSegment.def("CenterOfGeometry", (gp_Pnt (Select3D_SensitiveSegment::*)() const ) &Select3D_SensitiveSegment::CenterOfGeometry, "Returns center of the segment. If location transformation is set, it will be applied");
	cls_Select3D_SensitiveSegment.def("BoundingBox", (Select3D_BndBox3d (Select3D_SensitiveSegment::*)()) &Select3D_SensitiveSegment::BoundingBox, "Returns bounding box of the segment. If location transformation is set, it will be applied");
	cls_Select3D_SensitiveSegment.def("StartPoint", (void (Select3D_SensitiveSegment::*)(const gp_Pnt &)) &Select3D_SensitiveSegment::StartPoint, "changes the start Point of the Segment;", py::arg("thePnt"));
	cls_Select3D_SensitiveSegment.def("EndPoint", (void (Select3D_SensitiveSegment::*)(const gp_Pnt &)) &Select3D_SensitiveSegment::EndPoint, "changes the end point of the segment", py::arg("thePnt"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Select3D_BVHIndexBuffer.hxx
	py::class_<Select3D_BVHIndexBuffer, opencascade::handle<Select3D_BVHIndexBuffer>, Graphic3d_Buffer> cls_Select3D_BVHIndexBuffer(mod, "Select3D_BVHIndexBuffer", "Index buffer for BVH tree.");
	cls_Select3D_BVHIndexBuffer.def(py::init<const opencascade::handle<NCollection_BaseAllocator> &>(), py::arg("theAlloc"));
	cls_Select3D_BVHIndexBuffer.def("HasPatches", (bool (Select3D_BVHIndexBuffer::*)() const ) &Select3D_BVHIndexBuffer::HasPatches, "None");
	cls_Select3D_BVHIndexBuffer.def("Init", (bool (Select3D_BVHIndexBuffer::*)(const Standard_Integer, const bool)) &Select3D_BVHIndexBuffer::Init, "Allocates new empty index array", py::arg("theNbElems"), py::arg("theHasPatches"));
	cls_Select3D_BVHIndexBuffer.def("Index", (Standard_Integer (Select3D_BVHIndexBuffer::*)(const Standard_Integer) const ) &Select3D_BVHIndexBuffer::Index, "Access index at specified position", py::arg("theIndex"));
	cls_Select3D_BVHIndexBuffer.def("PatchSize", (Standard_Integer (Select3D_BVHIndexBuffer::*)(const Standard_Integer) const ) &Select3D_BVHIndexBuffer::PatchSize, "Access index at specified position", py::arg("theIndex"));
	cls_Select3D_BVHIndexBuffer.def("SetIndex", (void (Select3D_BVHIndexBuffer::*)(const Standard_Integer, const Standard_Integer)) &Select3D_BVHIndexBuffer::SetIndex, "Change index at specified position", py::arg("theIndex"), py::arg("theValue"));
	cls_Select3D_BVHIndexBuffer.def("SetIndex", (void (Select3D_BVHIndexBuffer::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer)) &Select3D_BVHIndexBuffer::SetIndex, "Change index at specified position", py::arg("theIndex"), py::arg("theValue"), py::arg("thePatchSize"));
	cls_Select3D_BVHIndexBuffer.def_static("get_type_name_", (const char * (*)()) &Select3D_BVHIndexBuffer::get_type_name, "None");
	cls_Select3D_BVHIndexBuffer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_BVHIndexBuffer::get_type_descriptor, "None");
	cls_Select3D_BVHIndexBuffer.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_BVHIndexBuffer::*)() const ) &Select3D_BVHIndexBuffer::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Select3D_Pnt.hxx
	py::class_<Select3D_Pnt, std::unique_ptr<Select3D_Pnt, Deleter<Select3D_Pnt>>> cls_Select3D_Pnt(mod, "Select3D_Pnt", "None");
	cls_Select3D_Pnt.def(py::init<>());
	cls_Select3D_Pnt.def("assign", (gp_Pnt (Select3D_Pnt::*)(const gp_Pnt &)) &Select3D_Pnt::operator=, py::is_operator(), "None", py::arg("thePnt"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Select3D_PointData.hxx
	py::class_<Select3D_PointData, std::unique_ptr<Select3D_PointData, Deleter<Select3D_PointData>>> cls_Select3D_PointData(mod, "Select3D_PointData", "None");
	cls_Select3D_PointData.def(py::init<const Standard_Integer>(), py::arg("theNbPoints"));
	cls_Select3D_PointData.def("SetPnt", (void (Select3D_PointData::*)(const Standard_Integer, const Select3D_Pnt &)) &Select3D_PointData::SetPnt, "None", py::arg("theIndex"), py::arg("theValue"));
	cls_Select3D_PointData.def("SetPnt", (void (Select3D_PointData::*)(const Standard_Integer, const gp_Pnt &)) &Select3D_PointData::SetPnt, "None", py::arg("theIndex"), py::arg("theValue"));
	cls_Select3D_PointData.def("Pnt", (const Select3D_Pnt & (Select3D_PointData::*)(const Standard_Integer) const ) &Select3D_PointData::Pnt, "None", py::arg("theIndex"));
	cls_Select3D_PointData.def("Pnt3d", (gp_Pnt (Select3D_PointData::*)(const Standard_Integer) const ) &Select3D_PointData::Pnt3d, "None", py::arg("theIndex"));
	cls_Select3D_PointData.def("Size", (Standard_Integer (Select3D_PointData::*)() const ) &Select3D_PointData::Size, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Select3D_SensitivePoly.hxx
	py::class_<Select3D_SensitivePoly, opencascade::handle<Select3D_SensitivePoly>, Select3D_SensitiveSet> cls_Select3D_SensitivePoly(mod, "Select3D_SensitivePoly", "Sensitive Entity to make a face selectable. In some cases this class can raise Standard_ConstructionError and Standard_OutOfRange exceptions from its member Select3D_PointData myPolyg.");
	cls_Select3D_SensitivePoly.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const TColgp_Array1OfPnt &, const Standard_Boolean>(), py::arg("theOwnerId"), py::arg("thePoints"), py::arg("theIsBVHEnabled"));
	cls_Select3D_SensitivePoly.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<TColgp_HArray1OfPnt> &, const Standard_Boolean>(), py::arg("theOwnerId"), py::arg("thePoints"), py::arg("theIsBVHEnabled"));
	cls_Select3D_SensitivePoly.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const Standard_Boolean>(), py::arg("theOwnerId"), py::arg("theIsBVHEnabled"));
	cls_Select3D_SensitivePoly.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const Standard_Boolean, const Standard_Integer>(), py::arg("theOwnerId"), py::arg("theIsBVHEnabled"), py::arg("theNbPnts"));
	cls_Select3D_SensitivePoly.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitivePoly::get_type_name, "None");
	cls_Select3D_SensitivePoly.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitivePoly::get_type_descriptor, "None");
	cls_Select3D_SensitivePoly.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitivePoly::*)() const ) &Select3D_SensitivePoly::DynamicType, "None");
	cls_Select3D_SensitivePoly.def("NbSubElements", (Standard_Integer (Select3D_SensitivePoly::*)()) &Select3D_SensitivePoly::NbSubElements, "Returns the amount of segments in poly");
	cls_Select3D_SensitivePoly.def("Points3D", (void (Select3D_SensitivePoly::*)(opencascade::handle<TColgp_HArray1OfPnt> &)) &Select3D_SensitivePoly::Points3D, "Returns the 3D points of the array used at construction time.", py::arg("theHArrayOfPnt"));
	cls_Select3D_SensitivePoly.def("BoundingBox", (Select3D_BndBox3d (Select3D_SensitivePoly::*)()) &Select3D_SensitivePoly::BoundingBox, "Returns bounding box of a polygon. If location transformation is set, it will be applied");
	cls_Select3D_SensitivePoly.def("CenterOfGeometry", (gp_Pnt (Select3D_SensitivePoly::*)() const ) &Select3D_SensitivePoly::CenterOfGeometry, "Returns center of the point set. If location transformation is set, it will be applied");
	cls_Select3D_SensitivePoly.def("Size", (Standard_Integer (Select3D_SensitivePoly::*)() const ) &Select3D_SensitivePoly::Size, "Returns the amount of segments of the poly");
	cls_Select3D_SensitivePoly.def("Box", (Select3D_BndBox3d (Select3D_SensitivePoly::*)(const Standard_Integer) const ) &Select3D_SensitivePoly::Box, "Returns bounding box of segment with index theIdx", py::arg("theIdx"));
	cls_Select3D_SensitivePoly.def("Center", (Standard_Real (Select3D_SensitivePoly::*)(const Standard_Integer, const Standard_Integer) const ) &Select3D_SensitivePoly::Center, "Returns geometry center of sensitive entity index theIdx in the vector along the given axis theAxis", py::arg("theIdx"), py::arg("theAxis"));
	cls_Select3D_SensitivePoly.def("Swap", (void (Select3D_SensitivePoly::*)(const Standard_Integer, const Standard_Integer)) &Select3D_SensitivePoly::Swap, "Swaps items with indexes theIdx1 and theIdx2 in the vector", py::arg("theIdx1"), py::arg("theIdx2"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Select3D_InteriorSensitivePointSet.hxx
	py::class_<Select3D_InteriorSensitivePointSet, opencascade::handle<Select3D_InteriorSensitivePointSet>, Select3D_SensitiveSet> cls_Select3D_InteriorSensitivePointSet(mod, "Select3D_InteriorSensitivePointSet", "This class handles the selection of arbitrary point set with internal type of sensitivity. The main principle is to split the point set given onto planar convex polygons and search for the overlap with one or more of them through traverse of BVH tree.");
	cls_Select3D_InteriorSensitivePointSet.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const TColgp_Array1OfPnt &>(), py::arg("theOwnerId"), py::arg("thePoints"));
	cls_Select3D_InteriorSensitivePointSet.def("GetPoints", (void (Select3D_InteriorSensitivePointSet::*)(opencascade::handle<TColgp_HArray1OfPnt> &)) &Select3D_InteriorSensitivePointSet::GetPoints, "Initializes the given array theHArrayOfPnt by 3d coordinates of vertices of the whole point set", py::arg("theHArrayOfPnt"));
	cls_Select3D_InteriorSensitivePointSet.def("Size", (Standard_Integer (Select3D_InteriorSensitivePointSet::*)() const ) &Select3D_InteriorSensitivePointSet::Size, "Returns the length of vector of planar convex polygons");
	cls_Select3D_InteriorSensitivePointSet.def("Box", (Select3D_BndBox3d (Select3D_InteriorSensitivePointSet::*)(const Standard_Integer) const ) &Select3D_InteriorSensitivePointSet::Box, "Returns bounding box of planar convex polygon with index theIdx", py::arg("theIdx"));
	cls_Select3D_InteriorSensitivePointSet.def("Center", (Standard_Real (Select3D_InteriorSensitivePointSet::*)(const Standard_Integer, const Standard_Integer) const ) &Select3D_InteriorSensitivePointSet::Center, "Returns geometry center of planar convex polygon with index theIdx in the vector along the given axis theAxis", py::arg("theIdx"), py::arg("theAxis"));
	cls_Select3D_InteriorSensitivePointSet.def("Swap", (void (Select3D_InteriorSensitivePointSet::*)(const Standard_Integer, const Standard_Integer)) &Select3D_InteriorSensitivePointSet::Swap, "Swaps items with indexes theIdx1 and theIdx2 in the vector", py::arg("theIdx1"), py::arg("theIdx2"));
	cls_Select3D_InteriorSensitivePointSet.def("BoundingBox", (Select3D_BndBox3d (Select3D_InteriorSensitivePointSet::*)()) &Select3D_InteriorSensitivePointSet::BoundingBox, "Returns bounding box of the point set. If location transformation is set, it will be applied");
	cls_Select3D_InteriorSensitivePointSet.def("CenterOfGeometry", (gp_Pnt (Select3D_InteriorSensitivePointSet::*)() const ) &Select3D_InteriorSensitivePointSet::CenterOfGeometry, "Returns center of the point set. If location transformation is set, it will be applied");
	cls_Select3D_InteriorSensitivePointSet.def("NbSubElements", (Standard_Integer (Select3D_InteriorSensitivePointSet::*)()) &Select3D_InteriorSensitivePointSet::NbSubElements, "Returns the amount of points in set");
	cls_Select3D_InteriorSensitivePointSet.def_static("get_type_name_", (const char * (*)()) &Select3D_InteriorSensitivePointSet::get_type_name, "None");
	cls_Select3D_InteriorSensitivePointSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_InteriorSensitivePointSet::get_type_descriptor, "None");
	cls_Select3D_InteriorSensitivePointSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_InteriorSensitivePointSet::*)() const ) &Select3D_InteriorSensitivePointSet::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Select3D_SensitiveBox.hxx
	py::class_<Select3D_SensitiveBox, opencascade::handle<Select3D_SensitiveBox>, Select3D_SensitiveEntity> cls_Select3D_SensitiveBox(mod, "Select3D_SensitiveBox", "A framework to define selection by a sensitive box.");
	cls_Select3D_SensitiveBox.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const Bnd_Box &>(), py::arg("theOwnerId"), py::arg("theBox"));
	cls_Select3D_SensitiveBox.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theOwnerId"), py::arg("theXMin"), py::arg("theYMin"), py::arg("theZMin"), py::arg("theXMax"), py::arg("theYMax"), py::arg("theZMax"));
	cls_Select3D_SensitiveBox.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitiveBox::get_type_name, "None");
	cls_Select3D_SensitiveBox.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitiveBox::get_type_descriptor, "None");
	cls_Select3D_SensitiveBox.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitiveBox::*)() const ) &Select3D_SensitiveBox::DynamicType, "None");
	cls_Select3D_SensitiveBox.def("NbSubElements", (Standard_Integer (Select3D_SensitiveBox::*)()) &Select3D_SensitiveBox::NbSubElements, "Returns the amount of sub-entities in sensitive");
	cls_Select3D_SensitiveBox.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitiveBox::*)()) &Select3D_SensitiveBox::GetConnected, "None");
	cls_Select3D_SensitiveBox.def("Matches", (Standard_Boolean (Select3D_SensitiveBox::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &Select3D_SensitiveBox::Matches, "Checks whether the box overlaps current selecting volume", py::arg("theMgr"), py::arg("thePickResult"));
	cls_Select3D_SensitiveBox.def("Box", (Bnd_Box (Select3D_SensitiveBox::*)() const ) &Select3D_SensitiveBox::Box, "None");
	cls_Select3D_SensitiveBox.def("CenterOfGeometry", (gp_Pnt (Select3D_SensitiveBox::*)() const ) &Select3D_SensitiveBox::CenterOfGeometry, "Returns center of the box. If location transformation is set, it will be applied");
	cls_Select3D_SensitiveBox.def("BoundingBox", (Select3D_BndBox3d (Select3D_SensitiveBox::*)()) &Select3D_SensitiveBox::BoundingBox, "Returns coordinates of the box. If location transformation is set, it will be applied");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Select3D_SensitiveCircle.hxx
	py::class_<Select3D_SensitiveCircle, opencascade::handle<Select3D_SensitiveCircle>, Select3D_SensitivePoly> cls_Select3D_SensitiveCircle(mod, "Select3D_SensitiveCircle", "A framework to define sensitive 3D arcs and circles. In some cases this class can raise Standard_ConstructionError and Standard_OutOfRange exceptions. For more details see Select3D_SensitivePoly.");
	cls_Select3D_SensitiveCircle.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<Geom_Circle> &>(), py::arg("theOwnerId"), py::arg("theCircle"));
	cls_Select3D_SensitiveCircle.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<Geom_Circle> &, const Standard_Boolean>(), py::arg("theOwnerId"), py::arg("theCircle"), py::arg("theIsFilled"));
	cls_Select3D_SensitiveCircle.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<Geom_Circle> &, const Standard_Boolean, const Standard_Integer>(), py::arg("theOwnerId"), py::arg("theCircle"), py::arg("theIsFilled"), py::arg("theNbPnts"));
	cls_Select3D_SensitiveCircle.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<Geom_Circle> &, const Standard_Real, const Standard_Real>(), py::arg("theOwnerId"), py::arg("theCircle"), py::arg("theU1"), py::arg("theU2"));
	cls_Select3D_SensitiveCircle.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<Geom_Circle> &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("theOwnerId"), py::arg("theCircle"), py::arg("theU1"), py::arg("theU2"), py::arg("theIsFilled"));
	cls_Select3D_SensitiveCircle.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<Geom_Circle> &, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Integer>(), py::arg("theOwnerId"), py::arg("theCircle"), py::arg("theU1"), py::arg("theU2"), py::arg("theIsFilled"), py::arg("theNbPnts"));
	cls_Select3D_SensitiveCircle.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<TColgp_HArray1OfPnt> &>(), py::arg("theOwnerId"), py::arg("thePnts3d"));
	cls_Select3D_SensitiveCircle.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<TColgp_HArray1OfPnt> &, const Standard_Boolean>(), py::arg("theOwnerId"), py::arg("thePnts3d"), py::arg("theIsFilled"));
	cls_Select3D_SensitiveCircle.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const TColgp_Array1OfPnt &>(), py::arg("theOwnerId"), py::arg("thePnts3d"));
	cls_Select3D_SensitiveCircle.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const TColgp_Array1OfPnt &, const Standard_Boolean>(), py::arg("theOwnerId"), py::arg("thePnts3d"), py::arg("theIsFilled"));
	cls_Select3D_SensitiveCircle.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitiveCircle::get_type_name, "None");
	cls_Select3D_SensitiveCircle.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitiveCircle::get_type_descriptor, "None");
	cls_Select3D_SensitiveCircle.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitiveCircle::*)() const ) &Select3D_SensitiveCircle::DynamicType, "None");
	cls_Select3D_SensitiveCircle.def("Matches", (Standard_Boolean (Select3D_SensitiveCircle::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &Select3D_SensitiveCircle::Matches, "Checks whether the circle overlaps current selecting volume", py::arg("theMgr"), py::arg("thePickResult"));
	cls_Select3D_SensitiveCircle.def("ArrayBounds", [](Select3D_SensitiveCircle &self, Standard_Integer & theLow, Standard_Integer & theUp){ self.ArrayBounds(theLow, theUp); return std::tuple<Standard_Integer &, Standard_Integer &>(theLow, theUp); }, "None", py::arg("theLow"), py::arg("theUp"));
	cls_Select3D_SensitiveCircle.def("GetPoint3d", (gp_Pnt (Select3D_SensitiveCircle::*)(const Standard_Integer) const ) &Select3D_SensitiveCircle::GetPoint3d, "None", py::arg("thePntIdx"));
	cls_Select3D_SensitiveCircle.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitiveCircle::*)()) &Select3D_SensitiveCircle::GetConnected, "None");
	cls_Select3D_SensitiveCircle.def("CenterOfGeometry", (gp_Pnt (Select3D_SensitiveCircle::*)() const ) &Select3D_SensitiveCircle::CenterOfGeometry, "Returns center of the circle. If location transformation is set, it will be applied");
	cls_Select3D_SensitiveCircle.def("BVH", (void (Select3D_SensitiveCircle::*)()) &Select3D_SensitiveCircle::BVH, "Builds BVH tree for a circle's edge segments if needed");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Select3D_SensitiveCurve.hxx
	py::class_<Select3D_SensitiveCurve, opencascade::handle<Select3D_SensitiveCurve>, Select3D_SensitivePoly> cls_Select3D_SensitiveCurve(mod, "Select3D_SensitiveCurve", "A framework to define a sensitive 3D curve. In some cases this class can raise Standard_ConstructionError and Standard_OutOfRange exceptions. For more details see Select3D_SensitivePoly.");
	cls_Select3D_SensitiveCurve.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<Geom_Curve> &>(), py::arg("theOwnerId"), py::arg("theCurve"));
	cls_Select3D_SensitiveCurve.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<Geom_Curve> &, const Standard_Integer>(), py::arg("theOwnerId"), py::arg("theCurve"), py::arg("theNbPnts"));
	cls_Select3D_SensitiveCurve.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<TColgp_HArray1OfPnt> &>(), py::arg("theOwnerId"), py::arg("thePoints"));
	cls_Select3D_SensitiveCurve.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const TColgp_Array1OfPnt &>(), py::arg("theOwnerId"), py::arg("thePoints"));
	cls_Select3D_SensitiveCurve.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitiveCurve::get_type_name, "None");
	cls_Select3D_SensitiveCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitiveCurve::get_type_descriptor, "None");
	cls_Select3D_SensitiveCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitiveCurve::*)() const ) &Select3D_SensitiveCurve::DynamicType, "None");
	cls_Select3D_SensitiveCurve.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitiveCurve::*)()) &Select3D_SensitiveCurve::GetConnected, "Returns the copy of this");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Select3D_SensitiveGroup.hxx
	py::class_<Select3D_SensitiveGroup, opencascade::handle<Select3D_SensitiveGroup>, Select3D_SensitiveSet> cls_Select3D_SensitiveGroup(mod, "Select3D_SensitiveGroup", "A framework to define selection of a sensitive group by a sensitive entity which is a set of 3D sensitive entities. Remark: 2 modes are possible for rectangle selection the group is considered selected 1) when all the entities inside are selected in the rectangle 2) only one entity inside is selected by the rectangle By default the 'Match All entities' mode is set.");
	cls_Select3D_SensitiveGroup.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &>(), py::arg("theOwnerId"));
	cls_Select3D_SensitiveGroup.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const Standard_Boolean>(), py::arg("theOwnerId"), py::arg("theIsMustMatchAll"));
	cls_Select3D_SensitiveGroup.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, Select3D_EntitySequence &>(), py::arg("theOwnerId"), py::arg("theEntities"));
	cls_Select3D_SensitiveGroup.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, Select3D_EntitySequence &, const Standard_Boolean>(), py::arg("theOwnerId"), py::arg("theEntities"), py::arg("theIsMustMatchAll"));
	cls_Select3D_SensitiveGroup.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitiveGroup::get_type_name, "None");
	cls_Select3D_SensitiveGroup.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitiveGroup::get_type_descriptor, "None");
	cls_Select3D_SensitiveGroup.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitiveGroup::*)() const ) &Select3D_SensitiveGroup::DynamicType, "None");
	cls_Select3D_SensitiveGroup.def("Entities", (const Select3D_IndexedMapOfEntity & (Select3D_SensitiveGroup::*)() const ) &Select3D_SensitiveGroup::Entities, "Gets group content");
	cls_Select3D_SensitiveGroup.def("SubEntity", (const opencascade::handle<Select3D_SensitiveEntity> & (Select3D_SensitiveGroup::*)(const Standard_Integer) const ) &Select3D_SensitiveGroup::SubEntity, "Access entity by index [1, NbSubElements()].", py::arg("theIndex"));
	cls_Select3D_SensitiveGroup.def("LastDetectedEntity", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitiveGroup::*)() const ) &Select3D_SensitiveGroup::LastDetectedEntity, "Return last detected entity.");
	cls_Select3D_SensitiveGroup.def("LastDetectedEntityIndex", (Standard_Integer (Select3D_SensitiveGroup::*)() const ) &Select3D_SensitiveGroup::LastDetectedEntityIndex, "Return index of last detected entity.");
	cls_Select3D_SensitiveGroup.def("Add", (void (Select3D_SensitiveGroup::*)(Select3D_EntitySequence &)) &Select3D_SensitiveGroup::Add, "Adds the list of sensitive entities LL to the empty sensitive group object created at construction time.", py::arg("theEntities"));
	cls_Select3D_SensitiveGroup.def("Add", (void (Select3D_SensitiveGroup::*)(const opencascade::handle<Select3D_SensitiveEntity> &)) &Select3D_SensitiveGroup::Add, "Adds the sensitive entity aSensitive to the non-empty sensitive group object created at construction time.", py::arg("theSensitive"));
	cls_Select3D_SensitiveGroup.def("Remove", (void (Select3D_SensitiveGroup::*)(const opencascade::handle<Select3D_SensitiveEntity> &)) &Select3D_SensitiveGroup::Remove, "None", py::arg("theSensitive"));
	cls_Select3D_SensitiveGroup.def("Clear", (void (Select3D_SensitiveGroup::*)()) &Select3D_SensitiveGroup::Clear, "Removes all sensitive entities from the list used at the time of construction, or added using the function Add.");
	cls_Select3D_SensitiveGroup.def("IsIn", (Standard_Boolean (Select3D_SensitiveGroup::*)(const opencascade::handle<Select3D_SensitiveEntity> &) const ) &Select3D_SensitiveGroup::IsIn, "Returns true if the sensitive entity aSensitive is in the list used at the time of construction, or added using the function Add.", py::arg("theSensitive"));
	cls_Select3D_SensitiveGroup.def("SetMatchType", (void (Select3D_SensitiveGroup::*)(const Standard_Boolean)) &Select3D_SensitiveGroup::SetMatchType, "Sets the requirement that all sensitive entities in the list used at the time of construction, or added using the function Add must be matched.", py::arg("theIsMustMatchAll"));
	cls_Select3D_SensitiveGroup.def("MustMatchAll", (Standard_Boolean (Select3D_SensitiveGroup::*)() const ) &Select3D_SensitiveGroup::MustMatchAll, "Returns true if all sensitive entities in the list used at the time of construction, or added using the function Add must be matched.");
	cls_Select3D_SensitiveGroup.def("ToCheckOverlapAll", (Standard_Boolean (Select3D_SensitiveGroup::*)() const ) &Select3D_SensitiveGroup::ToCheckOverlapAll, "Returns TRUE if all sensitive entities should be checked within rectangular/polygonal selection, FALSE by default. Can be useful for sensitive entities holding detection results as class property.");
	cls_Select3D_SensitiveGroup.def("SetCheckOverlapAll", (void (Select3D_SensitiveGroup::*)(Standard_Boolean)) &Select3D_SensitiveGroup::SetCheckOverlapAll, "Returns TRUE if all sensitive entities should be checked within rectangular/polygonal selection, FALSE by default. Can be useful for sensitive entities holding detection results as class property.", py::arg("theToCheckAll"));
	cls_Select3D_SensitiveGroup.def("Matches", (Standard_Boolean (Select3D_SensitiveGroup::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &Select3D_SensitiveGroup::Matches, "Checks whether the group overlaps current selecting volume", py::arg("theMgr"), py::arg("thePickResult"));
	cls_Select3D_SensitiveGroup.def("NbSubElements", (Standard_Integer (Select3D_SensitiveGroup::*)()) &Select3D_SensitiveGroup::NbSubElements, "Returns the amount of sub-entities");
	cls_Select3D_SensitiveGroup.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitiveGroup::*)()) &Select3D_SensitiveGroup::GetConnected, "None");
	cls_Select3D_SensitiveGroup.def("Set", (void (Select3D_SensitiveGroup::*)(const opencascade::handle<SelectBasics_EntityOwner> &)) &Select3D_SensitiveGroup::Set, "Sets the owner for all entities in group", py::arg("theOwnerId"));
	cls_Select3D_SensitiveGroup.def("BoundingBox", (Select3D_BndBox3d (Select3D_SensitiveGroup::*)()) &Select3D_SensitiveGroup::BoundingBox, "Returns bounding box of the group. If location transformation is set, it will be applied");
	cls_Select3D_SensitiveGroup.def("CenterOfGeometry", (gp_Pnt (Select3D_SensitiveGroup::*)() const ) &Select3D_SensitiveGroup::CenterOfGeometry, "Returns center of entity set. If location transformation is set, it will be applied");
	cls_Select3D_SensitiveGroup.def("Box", (Select3D_BndBox3d (Select3D_SensitiveGroup::*)(const Standard_Integer) const ) &Select3D_SensitiveGroup::Box, "Returns bounding box of sensitive entity with index theIdx", py::arg("theIdx"));
	cls_Select3D_SensitiveGroup.def("Center", (Standard_Real (Select3D_SensitiveGroup::*)(const Standard_Integer, const Standard_Integer) const ) &Select3D_SensitiveGroup::Center, "Returns geometry center of sensitive entity index theIdx in the vector along the given axis theAxis", py::arg("theIdx"), py::arg("theAxis"));
	cls_Select3D_SensitiveGroup.def("Swap", (void (Select3D_SensitiveGroup::*)(const Standard_Integer, const Standard_Integer)) &Select3D_SensitiveGroup::Swap, "Swaps items with indexes theIdx1 and theIdx2 in the vector", py::arg("theIdx1"), py::arg("theIdx2"));
	cls_Select3D_SensitiveGroup.def("Size", (Standard_Integer (Select3D_SensitiveGroup::*)() const ) &Select3D_SensitiveGroup::Size, "Returns the length of vector of sensitive entities");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Select3D_SensitivePoint.hxx
	py::class_<Select3D_SensitivePoint, opencascade::handle<Select3D_SensitivePoint>, Select3D_SensitiveEntity> cls_Select3D_SensitivePoint(mod, "Select3D_SensitivePoint", "A framework to define sensitive 3D points.");
	cls_Select3D_SensitivePoint.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const gp_Pnt &>(), py::arg("theOwnerId"), py::arg("thePoint"));
	cls_Select3D_SensitivePoint.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitivePoint::get_type_name, "None");
	cls_Select3D_SensitivePoint.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitivePoint::get_type_descriptor, "None");
	cls_Select3D_SensitivePoint.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitivePoint::*)() const ) &Select3D_SensitivePoint::DynamicType, "None");
	cls_Select3D_SensitivePoint.def("NbSubElements", (Standard_Integer (Select3D_SensitivePoint::*)()) &Select3D_SensitivePoint::NbSubElements, "Returns the amount of sub-entities in sensitive");
	cls_Select3D_SensitivePoint.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitivePoint::*)()) &Select3D_SensitivePoint::GetConnected, "None");
	cls_Select3D_SensitivePoint.def("Matches", (Standard_Boolean (Select3D_SensitivePoint::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &Select3D_SensitivePoint::Matches, "Checks whether the point overlaps current selecting volume", py::arg("theMgr"), py::arg("thePickResult"));
	cls_Select3D_SensitivePoint.def("Point", (const gp_Pnt & (Select3D_SensitivePoint::*)() const ) &Select3D_SensitivePoint::Point, "Returns the point used at the time of construction.");
	cls_Select3D_SensitivePoint.def("CenterOfGeometry", (gp_Pnt (Select3D_SensitivePoint::*)() const ) &Select3D_SensitivePoint::CenterOfGeometry, "Returns center of point. If location transformation is set, it will be applied");
	cls_Select3D_SensitivePoint.def("BoundingBox", (Select3D_BndBox3d (Select3D_SensitivePoint::*)()) &Select3D_SensitivePoint::BoundingBox, "Returns bounding box of the point. If location transformation is set, it will be applied");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Select3D_SensitivePrimitiveArray.hxx
	py::class_<Select3D_SensitivePrimitiveArray, opencascade::handle<Select3D_SensitivePrimitiveArray>, Select3D_SensitiveSet> cls_Select3D_SensitivePrimitiveArray(mod, "Select3D_SensitivePrimitiveArray", "Sensitive for triangulation or point set defined by Primitive Array. The primitives can be optionally combined into patches within BVH tree to reduce its building time in expense of extra traverse time.");
	cls_Select3D_SensitivePrimitiveArray.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &>(), py::arg("theOwnerId"));
	cls_Select3D_SensitivePrimitiveArray.def("PatchSizeMax", (Standard_Integer (Select3D_SensitivePrimitiveArray::*)() const ) &Select3D_SensitivePrimitiveArray::PatchSizeMax, "Return patch size limit (1 by default).");
	cls_Select3D_SensitivePrimitiveArray.def("SetPatchSizeMax", (void (Select3D_SensitivePrimitiveArray::*)(const Standard_Integer)) &Select3D_SensitivePrimitiveArray::SetPatchSizeMax, "Assign patch size limit. Should be set before initialization.", py::arg("thePatchSizeMax"));
	cls_Select3D_SensitivePrimitiveArray.def("PatchDistance", (float (Select3D_SensitivePrimitiveArray::*)() const ) &Select3D_SensitivePrimitiveArray::PatchDistance, "Maximum allowed distance between consequential elements in patch (ShortRealLast() by default). Has no effect on indexed triangulation.");
	cls_Select3D_SensitivePrimitiveArray.def("SetPatchDistance", (void (Select3D_SensitivePrimitiveArray::*)(const float)) &Select3D_SensitivePrimitiveArray::SetPatchDistance, "Assign patch distance limit. Should be set before initialization.", py::arg("thePatchDistMax"));
	cls_Select3D_SensitivePrimitiveArray.def("InitTriangulation", [](Select3D_SensitivePrimitiveArray &self, const opencascade::handle<Graphic3d_Buffer> & a0, const opencascade::handle<Graphic3d_IndexBuffer> & a1, const TopLoc_Location & a2, const Standard_Integer a3, const Standard_Integer a4) -> bool { return self.InitTriangulation(a0, a1, a2, a3, a4); }, py::arg("theVerts"), py::arg("theIndices"), py::arg("theInitLoc"), py::arg("theIndexLower"), py::arg("theIndexUpper"));
	cls_Select3D_SensitivePrimitiveArray.def("InitTriangulation", [](Select3D_SensitivePrimitiveArray &self, const opencascade::handle<Graphic3d_Buffer> & a0, const opencascade::handle<Graphic3d_IndexBuffer> & a1, const TopLoc_Location & a2, const Standard_Integer a3, const Standard_Integer a4, const bool a5) -> bool { return self.InitTriangulation(a0, a1, a2, a3, a4, a5); }, py::arg("theVerts"), py::arg("theIndices"), py::arg("theInitLoc"), py::arg("theIndexLower"), py::arg("theIndexUpper"), py::arg("theToEvalMinMax"));
	cls_Select3D_SensitivePrimitiveArray.def("InitTriangulation", (bool (Select3D_SensitivePrimitiveArray::*)(const opencascade::handle<Graphic3d_Buffer> &, const opencascade::handle<Graphic3d_IndexBuffer> &, const TopLoc_Location &, const Standard_Integer, const Standard_Integer, const bool, const Standard_Integer)) &Select3D_SensitivePrimitiveArray::InitTriangulation, "Initialize the sensitive object from triangualtion. The sub-triangulation can be specified by arguments theIndexLower and theIndexUpper (these are for iterating theIndices, not to restrict the actual index values!).", py::arg("theVerts"), py::arg("theIndices"), py::arg("theInitLoc"), py::arg("theIndexLower"), py::arg("theIndexUpper"), py::arg("theToEvalMinMax"), py::arg("theNbGroups"));
	cls_Select3D_SensitivePrimitiveArray.def("InitTriangulation", [](Select3D_SensitivePrimitiveArray &self, const opencascade::handle<Graphic3d_Buffer> & a0, const opencascade::handle<Graphic3d_IndexBuffer> & a1, const TopLoc_Location & a2) -> bool { return self.InitTriangulation(a0, a1, a2); }, py::arg("theVerts"), py::arg("theIndices"), py::arg("theInitLoc"));
	cls_Select3D_SensitivePrimitiveArray.def("InitTriangulation", [](Select3D_SensitivePrimitiveArray &self, const opencascade::handle<Graphic3d_Buffer> & a0, const opencascade::handle<Graphic3d_IndexBuffer> & a1, const TopLoc_Location & a2, const bool a3) -> bool { return self.InitTriangulation(a0, a1, a2, a3); }, py::arg("theVerts"), py::arg("theIndices"), py::arg("theInitLoc"), py::arg("theToEvalMinMax"));
	cls_Select3D_SensitivePrimitiveArray.def("InitTriangulation", (bool (Select3D_SensitivePrimitiveArray::*)(const opencascade::handle<Graphic3d_Buffer> &, const opencascade::handle<Graphic3d_IndexBuffer> &, const TopLoc_Location &, const bool, const Standard_Integer)) &Select3D_SensitivePrimitiveArray::InitTriangulation, "Initialize the sensitive object from triangualtion.", py::arg("theVerts"), py::arg("theIndices"), py::arg("theInitLoc"), py::arg("theToEvalMinMax"), py::arg("theNbGroups"));
	cls_Select3D_SensitivePrimitiveArray.def("InitPoints", [](Select3D_SensitivePrimitiveArray &self, const opencascade::handle<Graphic3d_Buffer> & a0, const opencascade::handle<Graphic3d_IndexBuffer> & a1, const TopLoc_Location & a2, const Standard_Integer a3, const Standard_Integer a4) -> bool { return self.InitPoints(a0, a1, a2, a3, a4); }, py::arg("theVerts"), py::arg("theIndices"), py::arg("theInitLoc"), py::arg("theIndexLower"), py::arg("theIndexUpper"));
	cls_Select3D_SensitivePrimitiveArray.def("InitPoints", [](Select3D_SensitivePrimitiveArray &self, const opencascade::handle<Graphic3d_Buffer> & a0, const opencascade::handle<Graphic3d_IndexBuffer> & a1, const TopLoc_Location & a2, const Standard_Integer a3, const Standard_Integer a4, const bool a5) -> bool { return self.InitPoints(a0, a1, a2, a3, a4, a5); }, py::arg("theVerts"), py::arg("theIndices"), py::arg("theInitLoc"), py::arg("theIndexLower"), py::arg("theIndexUpper"), py::arg("theToEvalMinMax"));
	cls_Select3D_SensitivePrimitiveArray.def("InitPoints", (bool (Select3D_SensitivePrimitiveArray::*)(const opencascade::handle<Graphic3d_Buffer> &, const opencascade::handle<Graphic3d_IndexBuffer> &, const TopLoc_Location &, const Standard_Integer, const Standard_Integer, const bool, const Standard_Integer)) &Select3D_SensitivePrimitiveArray::InitPoints, "Initialize the sensitive object from point set. The sub-set of points can be specified by arguments theIndexLower and theIndexUpper (these are for iterating theIndices, not to restrict the actual index values!).", py::arg("theVerts"), py::arg("theIndices"), py::arg("theInitLoc"), py::arg("theIndexLower"), py::arg("theIndexUpper"), py::arg("theToEvalMinMax"), py::arg("theNbGroups"));
	cls_Select3D_SensitivePrimitiveArray.def("InitPoints", [](Select3D_SensitivePrimitiveArray &self, const opencascade::handle<Graphic3d_Buffer> & a0, const opencascade::handle<Graphic3d_IndexBuffer> & a1, const TopLoc_Location & a2) -> bool { return self.InitPoints(a0, a1, a2); }, py::arg("theVerts"), py::arg("theIndices"), py::arg("theInitLoc"));
	cls_Select3D_SensitivePrimitiveArray.def("InitPoints", [](Select3D_SensitivePrimitiveArray &self, const opencascade::handle<Graphic3d_Buffer> & a0, const opencascade::handle<Graphic3d_IndexBuffer> & a1, const TopLoc_Location & a2, const bool a3) -> bool { return self.InitPoints(a0, a1, a2, a3); }, py::arg("theVerts"), py::arg("theIndices"), py::arg("theInitLoc"), py::arg("theToEvalMinMax"));
	cls_Select3D_SensitivePrimitiveArray.def("InitPoints", (bool (Select3D_SensitivePrimitiveArray::*)(const opencascade::handle<Graphic3d_Buffer> &, const opencascade::handle<Graphic3d_IndexBuffer> &, const TopLoc_Location &, const bool, const Standard_Integer)) &Select3D_SensitivePrimitiveArray::InitPoints, "Initialize the sensitive object from point set.", py::arg("theVerts"), py::arg("theIndices"), py::arg("theInitLoc"), py::arg("theToEvalMinMax"), py::arg("theNbGroups"));
	cls_Select3D_SensitivePrimitiveArray.def("InitPoints", [](Select3D_SensitivePrimitiveArray &self, const opencascade::handle<Graphic3d_Buffer> & a0, const TopLoc_Location & a1) -> bool { return self.InitPoints(a0, a1); }, py::arg("theVerts"), py::arg("theInitLoc"));
	cls_Select3D_SensitivePrimitiveArray.def("InitPoints", [](Select3D_SensitivePrimitiveArray &self, const opencascade::handle<Graphic3d_Buffer> & a0, const TopLoc_Location & a1, const bool a2) -> bool { return self.InitPoints(a0, a1, a2); }, py::arg("theVerts"), py::arg("theInitLoc"), py::arg("theToEvalMinMax"));
	cls_Select3D_SensitivePrimitiveArray.def("InitPoints", (bool (Select3D_SensitivePrimitiveArray::*)(const opencascade::handle<Graphic3d_Buffer> &, const TopLoc_Location &, const bool, const Standard_Integer)) &Select3D_SensitivePrimitiveArray::InitPoints, "Initialize the sensitive object from point set.", py::arg("theVerts"), py::arg("theInitLoc"), py::arg("theToEvalMinMax"), py::arg("theNbGroups"));
	cls_Select3D_SensitivePrimitiveArray.def("SetMinMax", (void (Select3D_SensitivePrimitiveArray::*)(double, double, double, double, double, double)) &Select3D_SensitivePrimitiveArray::SetMinMax, "Assign new not transformed bounding box.", py::arg("theMinX"), py::arg("theMinY"), py::arg("theMinZ"), py::arg("theMaxX"), py::arg("theMaxY"), py::arg("theMaxZ"));
	cls_Select3D_SensitivePrimitiveArray.def("ToDetectElements", (bool (Select3D_SensitivePrimitiveArray::*)() const ) &Select3D_SensitivePrimitiveArray::ToDetectElements, "Return flag to keep index of last topmost detected element, TRUE by default.");
	cls_Select3D_SensitivePrimitiveArray.def("SetDetectElements", (void (Select3D_SensitivePrimitiveArray::*)(bool)) &Select3D_SensitivePrimitiveArray::SetDetectElements, "Setup keeping of the index of last topmost detected element (axis picking).", py::arg("theToDetect"));
	cls_Select3D_SensitivePrimitiveArray.def("ToDetectElementMap", (bool (Select3D_SensitivePrimitiveArray::*)() const ) &Select3D_SensitivePrimitiveArray::ToDetectElementMap, "Return flag to keep index map of last detected elements, FALSE by default (rectangle selection).");
	cls_Select3D_SensitivePrimitiveArray.def("SetDetectElementMap", (void (Select3D_SensitivePrimitiveArray::*)(bool)) &Select3D_SensitivePrimitiveArray::SetDetectElementMap, "Setup keeping of the index map of last detected elements (rectangle selection).", py::arg("theToDetect"));
	cls_Select3D_SensitivePrimitiveArray.def("ToDetectNodes", (bool (Select3D_SensitivePrimitiveArray::*)() const ) &Select3D_SensitivePrimitiveArray::ToDetectNodes, "Return flag to keep index of last topmost detected node, FALSE by default.");
	cls_Select3D_SensitivePrimitiveArray.def("SetDetectNodes", (void (Select3D_SensitivePrimitiveArray::*)(bool)) &Select3D_SensitivePrimitiveArray::SetDetectNodes, "Setup keeping of the index of last topmost detected node (for axis picking).", py::arg("theToDetect"));
	cls_Select3D_SensitivePrimitiveArray.def("ToDetectNodeMap", (bool (Select3D_SensitivePrimitiveArray::*)() const ) &Select3D_SensitivePrimitiveArray::ToDetectNodeMap, "Return flag to keep index map of last detected nodes, FALSE by default (rectangle selection).");
	cls_Select3D_SensitivePrimitiveArray.def("SetDetectNodeMap", (void (Select3D_SensitivePrimitiveArray::*)(bool)) &Select3D_SensitivePrimitiveArray::SetDetectNodeMap, "Setup keeping of the index map of last detected nodes (rectangle selection).", py::arg("theToDetect"));
	cls_Select3D_SensitivePrimitiveArray.def("ToDetectEdges", (bool (Select3D_SensitivePrimitiveArray::*)() const ) &Select3D_SensitivePrimitiveArray::ToDetectEdges, "Return flag to keep index of last topmost detected edge, FALSE by default.");
	cls_Select3D_SensitivePrimitiveArray.def("SetDetectEdges", (void (Select3D_SensitivePrimitiveArray::*)(bool)) &Select3D_SensitivePrimitiveArray::SetDetectEdges, "Setup keeping of the index of last topmost detected edge (axis picking).", py::arg("theToDetect"));
	cls_Select3D_SensitivePrimitiveArray.def("LastDetectedElement", (Standard_Integer (Select3D_SensitivePrimitiveArray::*)() const ) &Select3D_SensitivePrimitiveArray::LastDetectedElement, "Return last topmost detected element or -1 if undefined (axis picking).");
	cls_Select3D_SensitivePrimitiveArray.def("LastDetectedElementMap", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (Select3D_SensitivePrimitiveArray::*)() const ) &Select3D_SensitivePrimitiveArray::LastDetectedElementMap, "Return the index map of last detected elements (rectangle selection).");
	cls_Select3D_SensitivePrimitiveArray.def("LastDetectedNode", (Standard_Integer (Select3D_SensitivePrimitiveArray::*)() const ) &Select3D_SensitivePrimitiveArray::LastDetectedNode, "Return last topmost detected node or -1 if undefined (axis picking).");
	cls_Select3D_SensitivePrimitiveArray.def("LastDetectedNodeMap", (const opencascade::handle<TColStd_HPackedMapOfInteger> & (Select3D_SensitivePrimitiveArray::*)() const ) &Select3D_SensitivePrimitiveArray::LastDetectedNodeMap, "Return the index map of last detected nodes (rectangle selection).");
	cls_Select3D_SensitivePrimitiveArray.def("LastDetectedEdgeNode1", (Standard_Integer (Select3D_SensitivePrimitiveArray::*)() const ) &Select3D_SensitivePrimitiveArray::LastDetectedEdgeNode1, "Return the first node of last topmost detected edge or -1 if undefined (axis picking).");
	cls_Select3D_SensitivePrimitiveArray.def("LastDetectedEdgeNode2", (Standard_Integer (Select3D_SensitivePrimitiveArray::*)() const ) &Select3D_SensitivePrimitiveArray::LastDetectedEdgeNode2, "Return the second node of last topmost detected edge or -1 if undefined (axis picking).");
	cls_Select3D_SensitivePrimitiveArray.def("Matches", (Standard_Boolean (Select3D_SensitivePrimitiveArray::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &Select3D_SensitivePrimitiveArray::Matches, "Checks whether the sensitive entity is overlapped by current selecting volume.", py::arg("theMgr"), py::arg("thePickResult"));
	cls_Select3D_SensitivePrimitiveArray.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitivePrimitiveArray::*)()) &Select3D_SensitivePrimitiveArray::GetConnected, "None");
	cls_Select3D_SensitivePrimitiveArray.def("Size", (Standard_Integer (Select3D_SensitivePrimitiveArray::*)() const ) &Select3D_SensitivePrimitiveArray::Size, "Returns the length of array of triangles or edges");
	cls_Select3D_SensitivePrimitiveArray.def("NbSubElements", (Standard_Integer (Select3D_SensitivePrimitiveArray::*)()) &Select3D_SensitivePrimitiveArray::NbSubElements, "Returns the amount of nodes in triangulation");
	cls_Select3D_SensitivePrimitiveArray.def("Box", (Select3D_BndBox3d (Select3D_SensitivePrimitiveArray::*)(const Standard_Integer) const ) &Select3D_SensitivePrimitiveArray::Box, "Returns bounding box of triangle/edge with index theIdx", py::arg("theIdx"));
	cls_Select3D_SensitivePrimitiveArray.def("Center", (Standard_Real (Select3D_SensitivePrimitiveArray::*)(const Standard_Integer, const Standard_Integer) const ) &Select3D_SensitivePrimitiveArray::Center, "Returns geometry center of triangle/edge with index theIdx in array along the given axis theAxis", py::arg("theIdx"), py::arg("theAxis"));
	cls_Select3D_SensitivePrimitiveArray.def("Swap", (void (Select3D_SensitivePrimitiveArray::*)(const Standard_Integer, const Standard_Integer)) &Select3D_SensitivePrimitiveArray::Swap, "Swaps items with indexes theIdx1 and theIdx2 in array", py::arg("theIdx1"), py::arg("theIdx2"));
	cls_Select3D_SensitivePrimitiveArray.def("BoundingBox", (Select3D_BndBox3d (Select3D_SensitivePrimitiveArray::*)()) &Select3D_SensitivePrimitiveArray::BoundingBox, "Returns bounding box of the triangulation. If location transformation is set, it will be applied");
	cls_Select3D_SensitivePrimitiveArray.def("CenterOfGeometry", (gp_Pnt (Select3D_SensitivePrimitiveArray::*)() const ) &Select3D_SensitivePrimitiveArray::CenterOfGeometry, "Returns center of triangulation. If location transformation is set, it will be applied");
	cls_Select3D_SensitivePrimitiveArray.def("HasInitLocation", (Standard_Boolean (Select3D_SensitivePrimitiveArray::*)() const ) &Select3D_SensitivePrimitiveArray::HasInitLocation, "Returns true if the shape corresponding to the entity has init location");
	cls_Select3D_SensitivePrimitiveArray.def("InvInitLocation", (gp_GTrsf (Select3D_SensitivePrimitiveArray::*)() const ) &Select3D_SensitivePrimitiveArray::InvInitLocation, "Returns inversed location transformation matrix if the shape corresponding to this entity has init location set. Otherwise, returns identity matrix.");
	cls_Select3D_SensitivePrimitiveArray.def("Set", (void (Select3D_SensitivePrimitiveArray::*)(const opencascade::handle<SelectBasics_EntityOwner> &)) &Select3D_SensitivePrimitiveArray::Set, "Sets the owner for all entities in group", py::arg("theOwnerId"));
	cls_Select3D_SensitivePrimitiveArray.def("BVH", (void (Select3D_SensitivePrimitiveArray::*)()) &Select3D_SensitivePrimitiveArray::BVH, "Builds BVH tree for sensitive set.");
	cls_Select3D_SensitivePrimitiveArray.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitivePrimitiveArray::get_type_name, "None");
	cls_Select3D_SensitivePrimitiveArray.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitivePrimitiveArray::get_type_descriptor, "None");
	cls_Select3D_SensitivePrimitiveArray.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitivePrimitiveArray::*)() const ) &Select3D_SensitivePrimitiveArray::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Select3D_SensitiveTriangle.hxx
	py::class_<Select3D_SensitiveTriangle, opencascade::handle<Select3D_SensitiveTriangle>, Select3D_SensitiveEntity> cls_Select3D_SensitiveTriangle(mod, "Select3D_SensitiveTriangle", "A framework to define selection of triangles in a view. This comes into play in the detection of meshing and triangulation in surfaces. In some cases this class can raise Standard_ConstructionError and Standard_OutOfRange exceptions. For more details see Select3D_SensitivePoly.");
	cls_Select3D_SensitiveTriangle.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("theOwnerId"), py::arg("thePnt0"), py::arg("thePnt1"), py::arg("thePnt2"));
	cls_Select3D_SensitiveTriangle.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const gp_Pnt &, const gp_Pnt &, const gp_Pnt &, const Select3D_TypeOfSensitivity>(), py::arg("theOwnerId"), py::arg("thePnt0"), py::arg("thePnt1"), py::arg("thePnt2"), py::arg("theType"));
	cls_Select3D_SensitiveTriangle.def("Matches", (Standard_Boolean (Select3D_SensitiveTriangle::*)(SelectBasics_SelectingVolumeManager &, SelectBasics_PickResult &)) &Select3D_SensitiveTriangle::Matches, "Checks whether the triangle overlaps current selecting volume", py::arg("theMgr"), py::arg("thePickResult"));
	cls_Select3D_SensitiveTriangle.def("Points3D", (void (Select3D_SensitiveTriangle::*)(gp_Pnt &, gp_Pnt &, gp_Pnt &) const ) &Select3D_SensitiveTriangle::Points3D, "Returns the 3D points P1, P2, P3 used at the time of construction.", py::arg("thePnt0"), py::arg("thePnt1"), py::arg("thePnt2"));
	cls_Select3D_SensitiveTriangle.def("Center3D", (gp_Pnt (Select3D_SensitiveTriangle::*)() const ) &Select3D_SensitiveTriangle::Center3D, "Returns the center point of the sensitive triangle created at construction time.");
	cls_Select3D_SensitiveTriangle.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitiveTriangle::*)()) &Select3D_SensitiveTriangle::GetConnected, "Returns the copy of this");
	cls_Select3D_SensitiveTriangle.def("BoundingBox", (Select3D_BndBox3d (Select3D_SensitiveTriangle::*)()) &Select3D_SensitiveTriangle::BoundingBox, "Returns bounding box of the triangle. If location transformation is set, it will be applied");
	cls_Select3D_SensitiveTriangle.def("NbSubElements", (Standard_Integer (Select3D_SensitiveTriangle::*)()) &Select3D_SensitiveTriangle::NbSubElements, "Returns the amount of points");
	cls_Select3D_SensitiveTriangle.def("CenterOfGeometry", (gp_Pnt (Select3D_SensitiveTriangle::*)() const ) &Select3D_SensitiveTriangle::CenterOfGeometry, "None");
	cls_Select3D_SensitiveTriangle.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitiveTriangle::get_type_name, "None");
	cls_Select3D_SensitiveTriangle.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitiveTriangle::get_type_descriptor, "None");
	cls_Select3D_SensitiveTriangle.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitiveTriangle::*)() const ) &Select3D_SensitiveTriangle::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Select3D_SensitiveTriangulation.hxx
	py::class_<Select3D_SensitiveTriangulation, opencascade::handle<Select3D_SensitiveTriangulation>, Select3D_SensitiveSet> cls_Select3D_SensitiveTriangulation(mod, "Select3D_SensitiveTriangulation", "A framework to define selection of a sensitive entity made of a set of triangles.");
	cls_Select3D_SensitiveTriangulation.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &>(), py::arg("theOwnerId"), py::arg("theTrg"), py::arg("theInitLoc"));
	cls_Select3D_SensitiveTriangulation.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &, const Standard_Boolean>(), py::arg("theOwnerId"), py::arg("theTrg"), py::arg("theInitLoc"), py::arg("theIsInterior"));
	cls_Select3D_SensitiveTriangulation.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &, const opencascade::handle<Poly_Triangulation> &, const TopLoc_Location &, const opencascade::handle<TColStd_HArray1OfInteger> &, const gp_Pnt &, const Standard_Boolean>(), py::arg("theOwnerId"), py::arg("theTrg"), py::arg("theInitLoc"), py::arg("theFreeEdges"), py::arg("theCOG"), py::arg("theIsInterior"));
	cls_Select3D_SensitiveTriangulation.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitiveTriangulation::get_type_name, "None");
	cls_Select3D_SensitiveTriangulation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitiveTriangulation::get_type_descriptor, "None");
	cls_Select3D_SensitiveTriangulation.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitiveTriangulation::*)() const ) &Select3D_SensitiveTriangulation::DynamicType, "None");
	cls_Select3D_SensitiveTriangulation.def("NbSubElements", (Standard_Integer (Select3D_SensitiveTriangulation::*)()) &Select3D_SensitiveTriangulation::NbSubElements, "Returns the amount of nodes in triangulation");
	cls_Select3D_SensitiveTriangulation.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitiveTriangulation::*)()) &Select3D_SensitiveTriangulation::GetConnected, "None");
	cls_Select3D_SensitiveTriangulation.def("Triangulation", (const opencascade::handle<Poly_Triangulation> & (Select3D_SensitiveTriangulation::*)() const ) &Select3D_SensitiveTriangulation::Triangulation, "None");
	cls_Select3D_SensitiveTriangulation.def("Size", (Standard_Integer (Select3D_SensitiveTriangulation::*)() const ) &Select3D_SensitiveTriangulation::Size, "Returns the length of array of triangles or edges");
	cls_Select3D_SensitiveTriangulation.def("Box", (Select3D_BndBox3d (Select3D_SensitiveTriangulation::*)(const Standard_Integer) const ) &Select3D_SensitiveTriangulation::Box, "Returns bounding box of triangle/edge with index theIdx", py::arg("theIdx"));
	cls_Select3D_SensitiveTriangulation.def("Center", (Standard_Real (Select3D_SensitiveTriangulation::*)(const Standard_Integer, const Standard_Integer) const ) &Select3D_SensitiveTriangulation::Center, "Returns geometry center of triangle/edge with index theIdx in array along the given axis theAxis", py::arg("theIdx"), py::arg("theAxis"));
	cls_Select3D_SensitiveTriangulation.def("Swap", (void (Select3D_SensitiveTriangulation::*)(const Standard_Integer, const Standard_Integer)) &Select3D_SensitiveTriangulation::Swap, "Swaps items with indexes theIdx1 and theIdx2 in array", py::arg("theIdx1"), py::arg("theIdx2"));
	cls_Select3D_SensitiveTriangulation.def("BoundingBox", (Select3D_BndBox3d (Select3D_SensitiveTriangulation::*)()) &Select3D_SensitiveTriangulation::BoundingBox, "Returns bounding box of the triangulation. If location transformation is set, it will be applied");
	cls_Select3D_SensitiveTriangulation.def("CenterOfGeometry", (gp_Pnt (Select3D_SensitiveTriangulation::*)() const ) &Select3D_SensitiveTriangulation::CenterOfGeometry, "Returns center of triangulation. If location transformation is set, it will be applied");
	cls_Select3D_SensitiveTriangulation.def("HasInitLocation", (Standard_Boolean (Select3D_SensitiveTriangulation::*)() const ) &Select3D_SensitiveTriangulation::HasInitLocation, "Returns true if the shape corresponding to the entity has init location");
	cls_Select3D_SensitiveTriangulation.def("InvInitLocation", (gp_GTrsf (Select3D_SensitiveTriangulation::*)() const ) &Select3D_SensitiveTriangulation::InvInitLocation, "Returns inversed location transformation matrix if the shape corresponding to this entity has init location set. Otherwise, returns identity matrix.");
	cls_Select3D_SensitiveTriangulation.def("GetInitLocation", (const TopLoc_Location & (Select3D_SensitiveTriangulation::*)() const ) &Select3D_SensitiveTriangulation::GetInitLocation, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Select3D_SensitiveWire.hxx
	py::class_<Select3D_SensitiveWire, opencascade::handle<Select3D_SensitiveWire>, Select3D_SensitiveSet> cls_Select3D_SensitiveWire(mod, "Select3D_SensitiveWire", "A framework to define selection of a wire owner by an elastic wire band.");
	cls_Select3D_SensitiveWire.def(py::init<const opencascade::handle<SelectBasics_EntityOwner> &>(), py::arg("theOwnerId"));
	cls_Select3D_SensitiveWire.def("Add", (void (Select3D_SensitiveWire::*)(const opencascade::handle<Select3D_SensitiveEntity> &)) &Select3D_SensitiveWire::Add, "Adds the sensitive entity theSensitive to this framework.", py::arg("theSensitive"));
	cls_Select3D_SensitiveWire.def("NbSubElements", (Standard_Integer (Select3D_SensitiveWire::*)()) &Select3D_SensitiveWire::NbSubElements, "Returns the amount of sub-entities");
	cls_Select3D_SensitiveWire.def("GetConnected", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitiveWire::*)()) &Select3D_SensitiveWire::GetConnected, "None");
	cls_Select3D_SensitiveWire.def("GetEdges", (const NCollection_Vector<opencascade::handle<Select3D_SensitiveEntity> > & (Select3D_SensitiveWire::*)()) &Select3D_SensitiveWire::GetEdges, "returns the sensitive edges stored in this wire");
	cls_Select3D_SensitiveWire.def("Set", (void (Select3D_SensitiveWire::*)(const opencascade::handle<SelectBasics_EntityOwner> &)) &Select3D_SensitiveWire::Set, "Sets the owner for all entities in wire", py::arg("theOwnerId"));
	cls_Select3D_SensitiveWire.def("GetLastDetected", (opencascade::handle<Select3D_SensitiveEntity> (Select3D_SensitiveWire::*)() const ) &Select3D_SensitiveWire::GetLastDetected, "None");
	cls_Select3D_SensitiveWire.def("BoundingBox", (Select3D_BndBox3d (Select3D_SensitiveWire::*)()) &Select3D_SensitiveWire::BoundingBox, "Returns bounding box of the wire. If location transformation is set, it will be applied");
	cls_Select3D_SensitiveWire.def("CenterOfGeometry", (gp_Pnt (Select3D_SensitiveWire::*)() const ) &Select3D_SensitiveWire::CenterOfGeometry, "Returns center of the wire. If location transformation is set, it will be applied");
	cls_Select3D_SensitiveWire.def("Size", (Standard_Integer (Select3D_SensitiveWire::*)() const ) &Select3D_SensitiveWire::Size, "Returns the length of vector of sensitive entities");
	cls_Select3D_SensitiveWire.def("Box", (Select3D_BndBox3d (Select3D_SensitiveWire::*)(const Standard_Integer) const ) &Select3D_SensitiveWire::Box, "Returns bounding box of sensitive entity with index theIdx", py::arg("theIdx"));
	cls_Select3D_SensitiveWire.def("Center", (Standard_Real (Select3D_SensitiveWire::*)(const Standard_Integer, const Standard_Integer) const ) &Select3D_SensitiveWire::Center, "Returns geometry center of sensitive entity index theIdx in the vector along the given axis theAxis", py::arg("theIdx"), py::arg("theAxis"));
	cls_Select3D_SensitiveWire.def("Swap", (void (Select3D_SensitiveWire::*)(const Standard_Integer, const Standard_Integer)) &Select3D_SensitiveWire::Swap, "Swaps items with indexes theIdx1 and theIdx2 in the vector", py::arg("theIdx1"), py::arg("theIdx2"));
	cls_Select3D_SensitiveWire.def_static("get_type_name_", (const char * (*)()) &Select3D_SensitiveWire::get_type_name, "None");
	cls_Select3D_SensitiveWire.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Select3D_SensitiveWire::get_type_descriptor, "None");
	cls_Select3D_SensitiveWire.def("DynamicType", (const opencascade::handle<Standard_Type> & (Select3D_SensitiveWire::*)() const ) &Select3D_SensitiveWire::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Select3D_BndBox3d.hxx
	other_mod = py::module::import("OCCT.Graphic3d");
	if (py::hasattr(other_mod, "Graphic3d_BndBox3d")) {
		mod.attr("Select3D_BndBox3d") = other_mod.attr("Graphic3d_BndBox3d");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\Select3D_BndBox3d.hxx
	other_mod = py::module::import("OCCT.BVH");
	if (py::hasattr(other_mod, "BVH_Vec3d")) {
		mod.attr("Select3D_Vec3") = other_mod.attr("BVH_Vec3d");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\Select3D_BVHBuilder3d.hxx
	bind_BVH_Builder<double, 3>(mod, "Select3D_BVHBuilder3d");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Select3D_EntitySequence.hxx
	bind_NCollection_Sequence<opencascade::handle<Select3D_SensitiveEntity> >(mod, "Select3D_EntitySequence");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\Select3D_IndexedMapOfEntity.hxx
	bind_NCollection_IndexedMap<opencascade::handle<Select3D_SensitiveEntity>, NCollection_DefaultHasher<opencascade::handle<Select3D_SensitiveEntity> > >(mod, "Select3D_IndexedMapOfEntity");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Select3D_InteriorSensitivePointSet.hxx
	bind_NCollection_Vector<opencascade::handle<Select3D_SensitivePoly> >(mod, "Select3D_VectorOfHPoly");


}
