#include <pyOCCT_Common.hpp>

#include <SelectMgr_TypeOfUpdate.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <SelectBasics_SensitiveEntity.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Type.hxx>
#include <SelectMgr_SensitiveEntity.hxx>
#include <SelectMgr_StateOfSelection.hxx>
#include <SelectMgr_TypeOfBVHUpdate.hxx>
#include <SelectMgr_Selection.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Sequence.hxx>
#include <SelectMgr_SequenceOfSelection.hxx>
#include <SelectBasics_EntityOwner.hxx>
#include <SelectMgr_SelectableObject.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <PrsMgr_PresentationManager.hxx>
#include <PrsMgr_PresentationManager3d.hxx>
#include <Prs3d_Drawer.hxx>
#include <TopLoc_Location.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <V3d_Viewer.hxx>
#include <SelectMgr_SequenceOfOwner.hxx>
#include <SelectMgr_IndexedMapOfOwner.hxx>
#include <SelectMgr_ViewerSelector.hxx>
#include <SelectMgr_SelectionManager.hxx>
#include <PrsMgr_PresentableObject.hxx>
#include <Prs3d_Presentation.hxx>
#include <Bnd_Box.hxx>
#include <SelectMgr_SortCriterion.hxx>
#include <NCollection_BaseMap.hxx>
#include <NCollection_IndexedDataMap.hxx>
#include <SelectMgr_IndexedDataMapOfOwnerCriterion.hxx>
#include <NCollection_Vec2.hxx>
#include <NCollection_Vec3.hxx>
#include <SelectMgr_VectorTypes.hxx>
#include <NCollection_Vec4.hxx>
#include <NCollection_Mat4.hxx>
#include <Graphic3d_Mat4d.hxx>
#include <Graphic3d_WorldViewProjState.hxx>
#include <gp_Pnt.hxx>
#include <SelectMgr_FrustumBuilder.hxx>
#include <Graphic3d_Camera.hxx>
#include <gp_Pnt2d.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <SelectMgr_BaseFrustum.hxx>
#include <gp_GTrsf.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <Select3D_TypeOfSensitivity.hxx>
#include <Graphic3d_SequenceOfHClipPlane.hxx>
#include <NCollection_Vector.hxx>
#include <SelectMgr_ViewClipRange.hxx>
#include <SelectMgr_Frustum.hxx>
#include <SelectMgr_RectangularFrustum.hxx>
#include <SelectMgr_TriangularFrustum.hxx>
#include <NCollection_BaseList.hxx>
#include <NCollection_List.hxx>
#include <SelectMgr_TriangularFrustumSet.hxx>
#include <SelectBasics_SelectingVolumeManager.hxx>
#include <SelectMgr_SelectingVolumeManager.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <SelectMgr_SelectableObjectSet.hxx>
#include <BVH_Tree.hxx>
#include <SelectMgr_ToleranceMap.hxx>
#include <BVH_PrimitiveSet3d.hxx>
#include <Select3D_BVHBuilder3d.hxx>
#include <Select3D_BndBox3d.hxx>
#include <SelectMgr_SensitiveEntitySet.hxx>
#include <NCollection_DataMap.hxx>
#include <TColStd_ListOfInteger.hxx>
#include <TCollection_AsciiString.hxx>
#include <TopAbs_ShapeEnum.hxx>
#include <SelectMgr_Filter.hxx>
#include <SelectMgr_ListOfFilter.hxx>
#include <SelectMgr_CompositionFilter.hxx>
#include <Graphic3d_NMapOfTransient.hxx>
#include <SelectMgr_OrFilter.hxx>
#include <SelectMgr_AndFilter.hxx>
#include <SelectMgr_PickingStrategy.hxx>
#include <SelectMgr_SOPtr.hxx>
#include <SelectMgr_SequenceOfSelector.hxx>
#include <SelectMgr_DataMapOfObjectSelectors.hxx>
#include <NCollection_IndexedMap.hxx>
#include <SelectMgr_SequenceOfFilter.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(SelectMgr, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.SelectBasics");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.PrsMgr");
	py::module::import("OCCT.Prs3d");
	py::module::import("OCCT.TopLoc");
	py::module::import("OCCT.Graphic3d");
	py::module::import("OCCT.V3d");
	py::module::import("OCCT.Bnd");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.TColgp");
	py::module::import("OCCT.Select3D");
	py::module::import("OCCT.BVH");
	py::module::import("OCCT.TColStd");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.TopAbs");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_TypeOfUpdate.hxx
	py::enum_<SelectMgr_TypeOfUpdate>(mod, "SelectMgr_TypeOfUpdate", "Provides values for types of update, including - full - partial - none.")
		.value("SelectMgr_TOU_Full", SelectMgr_TypeOfUpdate::SelectMgr_TOU_Full)
		.value("SelectMgr_TOU_Partial", SelectMgr_TypeOfUpdate::SelectMgr_TOU_Partial)
		.value("SelectMgr_TOU_None", SelectMgr_TypeOfUpdate::SelectMgr_TOU_None)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_StateOfSelection.hxx
	py::enum_<SelectMgr_StateOfSelection>(mod, "SelectMgr_StateOfSelection", "different state of a Selection in a ViewerSelector...")
		.value("SelectMgr_SOS_Activated", SelectMgr_StateOfSelection::SelectMgr_SOS_Activated)
		.value("SelectMgr_SOS_Deactivated", SelectMgr_StateOfSelection::SelectMgr_SOS_Deactivated)
		.value("SelectMgr_SOS_Sleeping", SelectMgr_StateOfSelection::SelectMgr_SOS_Sleeping)
		.value("SelectMgr_SOS_Any", SelectMgr_StateOfSelection::SelectMgr_SOS_Any)
		.value("SelectMgr_SOS_Unknown", SelectMgr_StateOfSelection::SelectMgr_SOS_Unknown)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_TypeOfBVHUpdate.hxx
	py::enum_<SelectMgr_TypeOfBVHUpdate>(mod, "SelectMgr_TypeOfBVHUpdate", "Keeps track for BVH update state for each SelectMgr_Selection entity in a following way: - Add : 2nd level BVH does not contain any of the selection's sensitive entities and they must be added; - Remove : all sensitive entities of the selection must be removed from 2nd level BVH; - Renew : 2nd level BVH already contains sensitives of the selection, but the its complete update and removal is required. Therefore, sensitives of the selection with this type of update must be removed from 2nd level BVH and added after recomputation. - Invalidate : the 2nd level BVH needs to be rebuilt; - None : entities of the selection are up to date.")
		.value("SelectMgr_TBU_Add", SelectMgr_TypeOfBVHUpdate::SelectMgr_TBU_Add)
		.value("SelectMgr_TBU_Remove", SelectMgr_TypeOfBVHUpdate::SelectMgr_TBU_Remove)
		.value("SelectMgr_TBU_Renew", SelectMgr_TypeOfBVHUpdate::SelectMgr_TBU_Renew)
		.value("SelectMgr_TBU_Invalidate", SelectMgr_TypeOfBVHUpdate::SelectMgr_TBU_Invalidate)
		.value("SelectMgr_TBU_None", SelectMgr_TypeOfBVHUpdate::SelectMgr_TBU_None)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_PickingStrategy.hxx
	py::enum_<SelectMgr_PickingStrategy>(mod, "SelectMgr_PickingStrategy", "Enumeration defines picking strategy - which entities detected by picking line will be accepted, considering selection filters.")
		.value("SelectMgr_PickingStrategy_FirstAcceptable", SelectMgr_PickingStrategy::SelectMgr_PickingStrategy_FirstAcceptable)
		.value("SelectMgr_PickingStrategy_OnlyTopmost", SelectMgr_PickingStrategy::SelectMgr_PickingStrategy_OnlyTopmost)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_SensitiveEntity.hxx
	py::class_<SelectMgr_SensitiveEntity, opencascade::handle<SelectMgr_SensitiveEntity>, Standard_Transient> cls_SelectMgr_SensitiveEntity(mod, "SelectMgr_SensitiveEntity", "The purpose of this class is to mark sensitive entities selectable or not depending on current active selection of parent object for proper BVH traverse");
	cls_SelectMgr_SensitiveEntity.def(py::init<const opencascade::handle<SelectBasics_SensitiveEntity> &>(), py::arg("theEntity"));
	cls_SelectMgr_SensitiveEntity.def("Clear", (void (SelectMgr_SensitiveEntity::*)()) &SelectMgr_SensitiveEntity::Clear, "Clears up all resources and memory");
	cls_SelectMgr_SensitiveEntity.def("BaseSensitive", (const opencascade::handle<SelectBasics_SensitiveEntity> & (SelectMgr_SensitiveEntity::*)() const ) &SelectMgr_SensitiveEntity::BaseSensitive, "Returns related instance of SelectBasics class");
	cls_SelectMgr_SensitiveEntity.def("IsActiveForSelection", (Standard_Boolean (SelectMgr_SensitiveEntity::*)() const ) &SelectMgr_SensitiveEntity::IsActiveForSelection, "Returns true if this entity belongs to the active selection mode of parent object");
	cls_SelectMgr_SensitiveEntity.def("ResetSelectionActiveStatus", (void (SelectMgr_SensitiveEntity::*)() const ) &SelectMgr_SensitiveEntity::ResetSelectionActiveStatus, "Marks entity as inactive for selection");
	cls_SelectMgr_SensitiveEntity.def("SetActiveForSelection", (void (SelectMgr_SensitiveEntity::*)() const ) &SelectMgr_SensitiveEntity::SetActiveForSelection, "Marks entity as active for selection");
	cls_SelectMgr_SensitiveEntity.def_static("get_type_name_", (const char * (*)()) &SelectMgr_SensitiveEntity::get_type_name, "None");
	cls_SelectMgr_SensitiveEntity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_SensitiveEntity::get_type_descriptor, "None");
	cls_SelectMgr_SensitiveEntity.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_SensitiveEntity::*)() const ) &SelectMgr_SensitiveEntity::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_Selection.hxx
	py::class_<SelectMgr_Selection, opencascade::handle<SelectMgr_Selection>, Standard_Transient> cls_SelectMgr_Selection(mod, "SelectMgr_Selection", "Represents the state of a given selection mode for a Selectable Object. Contains all the sensitive entities available for this mode. An interactive object can have an indefinite number of modes of selection, each representing a 'decomposition' into sensitive primitives; each primitive has an Owner (SelectMgr_EntityOwner) which allows us to identify the exact entity which has been detected. Each Selection mode is identified by an index. The set of sensitive primitives which correspond to a given mode is stocked in a SelectMgr_Selection object. By Convention, the default selection mode which allows us to grasp the Interactive object in its entirety will be mode 0. AIS_Trihedron : 4 selection modes - mode 0 : selection of a trihedron - mode 1 : selection of the origin of the trihedron - mode 2 : selection of the axes - mode 3 : selection of the planes XOY, YOZ, XOZ when you activate one of modes 1 2 3 4 , you pick AIS objects of type: - AIS_Point - AIS_Axis (and information on the type of axis) - AIS_Plane (and information on the type of plane). AIS_PlaneTrihedron offers 3 selection modes: - mode 0 : selection of the whole trihedron - mode 1 : selection of the origin of the trihedron - mode 2 : selection of the axes - same remarks as for the Trihedron. AIS_Shape : 7 maximum selection modes, depending on the complexity of the shape : - mode 0 : selection of the AIS_Shape - mode 1 : selection of the vertices - mode 2 : selection of the edges - mode 3 : selection of the wires - mode 4 : selection of the faces - mode 5 : selection of the shells - mode 6 : selection of the constituent solids.");
	cls_SelectMgr_Selection.def(py::init<>());
	cls_SelectMgr_Selection.def(py::init<const Standard_Integer>(), py::arg("theModeIdx"));
	cls_SelectMgr_Selection.def("Destroy", (void (SelectMgr_Selection::*)()) &SelectMgr_Selection::Destroy, "None");
	cls_SelectMgr_Selection.def("Add", (void (SelectMgr_Selection::*)(const opencascade::handle<SelectBasics_SensitiveEntity> &)) &SelectMgr_Selection::Add, "Adds the sensitive primitive aprimitive to the list of stored entities in this object. Raises NullObject if the primitive is a null handle.", py::arg("theSensitive"));
	cls_SelectMgr_Selection.def("Clear", (void (SelectMgr_Selection::*)()) &SelectMgr_Selection::Clear, "empties the selection from all the stored entities");
	cls_SelectMgr_Selection.def("IsEmpty", (Standard_Boolean (SelectMgr_Selection::*)() const ) &SelectMgr_Selection::IsEmpty, "returns true if no sensitive entity is stored.");
	cls_SelectMgr_Selection.def("Mode", (Standard_Integer (SelectMgr_Selection::*)() const ) &SelectMgr_Selection::Mode, "returns the selection mode represented by this selection");
	cls_SelectMgr_Selection.def("Init", (void (SelectMgr_Selection::*)()) &SelectMgr_Selection::Init, "Begins an iteration scanning for sensitive primitives.");
	cls_SelectMgr_Selection.def("More", (Standard_Boolean (SelectMgr_Selection::*)() const ) &SelectMgr_Selection::More, "Continues the iteration scanning for sensitive primitives with the mode defined in this framework.");
	cls_SelectMgr_Selection.def("Next", (void (SelectMgr_Selection::*)()) &SelectMgr_Selection::Next, "Returns the next sensitive primitive found in the iteration. This is a scan for entities with the mode defined in this framework.");
	cls_SelectMgr_Selection.def("Sensitive", (const opencascade::handle<SelectMgr_SensitiveEntity> & (SelectMgr_Selection::*)() const ) &SelectMgr_Selection::Sensitive, "Returns any sensitive primitive in this framework.");
	cls_SelectMgr_Selection.def("UpdateStatus", (SelectMgr_TypeOfUpdate (SelectMgr_Selection::*)() const ) &SelectMgr_Selection::UpdateStatus, "Returns the flag UpdateFlag. This flage gives the update status of this framework in a ViewerSelector object: - full - partial, or - none.");
	cls_SelectMgr_Selection.def("UpdateStatus", (void (SelectMgr_Selection::*)(const SelectMgr_TypeOfUpdate)) &SelectMgr_Selection::UpdateStatus, "None", py::arg("theStatus"));
	cls_SelectMgr_Selection.def("UpdateBVHStatus", (void (SelectMgr_Selection::*)(const SelectMgr_TypeOfBVHUpdate)) &SelectMgr_Selection::UpdateBVHStatus, "None", py::arg("theStatus"));
	cls_SelectMgr_Selection.def("BVHUpdateStatus", (SelectMgr_TypeOfBVHUpdate (SelectMgr_Selection::*)() const ) &SelectMgr_Selection::BVHUpdateStatus, "None");
	cls_SelectMgr_Selection.def("GetSelectionState", (SelectMgr_StateOfSelection (SelectMgr_Selection::*)() const ) &SelectMgr_Selection::GetSelectionState, "Returns status of selection");
	cls_SelectMgr_Selection.def("SetSelectionState", (void (SelectMgr_Selection::*)(const SelectMgr_StateOfSelection) const ) &SelectMgr_Selection::SetSelectionState, "Sets status of selection", py::arg("theState"));
	cls_SelectMgr_Selection.def("Sensitivity", (Standard_Integer (SelectMgr_Selection::*)() const ) &SelectMgr_Selection::Sensitivity, "Returns sensitivity of the selection");
	cls_SelectMgr_Selection.def("SetSensitivity", (void (SelectMgr_Selection::*)(const Standard_Integer)) &SelectMgr_Selection::SetSensitivity, "Changes sensitivity of the selection and all its entities to the given value. IMPORTANT: This method does not update any outer selection structures, so for proper updates use SelectMgr_SelectionManager::SetSelectionSensitivity method.", py::arg("theNewSens"));
	cls_SelectMgr_Selection.def_static("get_type_name_", (const char * (*)()) &SelectMgr_Selection::get_type_name, "None");
	cls_SelectMgr_Selection.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_Selection::get_type_descriptor, "None");
	cls_SelectMgr_Selection.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_Selection::*)() const ) &SelectMgr_Selection::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_EntityOwner.hxx
	py::class_<SelectMgr_EntityOwner, opencascade::handle<SelectMgr_EntityOwner>, SelectBasics_EntityOwner> cls_SelectMgr_EntityOwner(mod, "SelectMgr_EntityOwner", "A framework to define classes of owners of sensitive primitives. The owner is the link between application and selection data structures. For the application to make its own objects selectable, it must define owner classes inheriting this framework.");
	cls_SelectMgr_EntityOwner.def(py::init<>());
	cls_SelectMgr_EntityOwner.def(py::init<const Standard_Integer>(), py::arg("aPriority"));
	cls_SelectMgr_EntityOwner.def(py::init<const opencascade::handle<SelectMgr_SelectableObject> &>(), py::arg("aSO"));
	cls_SelectMgr_EntityOwner.def(py::init<const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer>(), py::arg("aSO"), py::arg("aPriority"));
	cls_SelectMgr_EntityOwner.def(py::init<const opencascade::handle<SelectMgr_EntityOwner> &>(), py::arg("theOwner"));
	cls_SelectMgr_EntityOwner.def(py::init<const opencascade::handle<SelectMgr_EntityOwner> &, const Standard_Integer>(), py::arg("theOwner"), py::arg("aPriority"));
	cls_SelectMgr_EntityOwner.def_static("get_type_name_", (const char * (*)()) &SelectMgr_EntityOwner::get_type_name, "None");
	cls_SelectMgr_EntityOwner.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_EntityOwner::get_type_descriptor, "None");
	cls_SelectMgr_EntityOwner.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_EntityOwner::*)() const ) &SelectMgr_EntityOwner::DynamicType, "None");
	cls_SelectMgr_EntityOwner.def("HasSelectable", (Standard_Boolean (SelectMgr_EntityOwner::*)() const ) &SelectMgr_EntityOwner::HasSelectable, "Returns true if there is a selectable object to serve as an owner.");
	cls_SelectMgr_EntityOwner.def("Selectable", (opencascade::handle<SelectMgr_SelectableObject> (SelectMgr_EntityOwner::*)() const ) &SelectMgr_EntityOwner::Selectable, "Returns a selectable object detected in the working context.");
	cls_SelectMgr_EntityOwner.def("SetSelectable", (void (SelectMgr_EntityOwner::*)(const opencascade::handle<SelectMgr_SelectableObject> &)) &SelectMgr_EntityOwner::SetSelectable, "Sets the selectable object.", py::arg("theSelObj"));
	cls_SelectMgr_EntityOwner.def("IsHilighted", [](SelectMgr_EntityOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> Standard_Boolean { return self.IsHilighted(a0); }, py::arg("aPM"));
	cls_SelectMgr_EntityOwner.def("IsHilighted", (Standard_Boolean (SelectMgr_EntityOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer) const ) &SelectMgr_EntityOwner::IsHilighted, "Returns true if the presentation manager aPM highlights selections corresponding to the selection mode aMode.", py::arg("aPM"), py::arg("aMode"));
	cls_SelectMgr_EntityOwner.def("HilightWithColor", [](SelectMgr_EntityOwner &self, const opencascade::handle<PrsMgr_PresentationManager3d> & a0, const opencascade::handle<Prs3d_Drawer> & a1) -> void { return self.HilightWithColor(a0, a1); }, py::arg("thePM"), py::arg("theStyle"));
	cls_SelectMgr_EntityOwner.def("HilightWithColor", (void (SelectMgr_EntityOwner::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Drawer> &, const Standard_Integer)) &SelectMgr_EntityOwner::HilightWithColor, "Highlights selectable object's presentation with mode theMode in presentation manager with given highlight style. Also a check for auto-highlight is performed - if selectable object manages highlighting on its own, execution will be passed to SelectMgr_SelectableObject::HilightOwnerWithColor method", py::arg("thePM"), py::arg("theStyle"), py::arg("theMode"));
	cls_SelectMgr_EntityOwner.def("Unhilight", [](SelectMgr_EntityOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> void { return self.Unhilight(a0); }, py::arg("thePrsMgr"));
	cls_SelectMgr_EntityOwner.def("Unhilight", (void (SelectMgr_EntityOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer)) &SelectMgr_EntityOwner::Unhilight, "Removes highlighting from the owner of a detected selectable object in the presentation manager. This object could be the owner of a sensitive primitive.", py::arg("thePrsMgr"), py::arg("theMode"));
	cls_SelectMgr_EntityOwner.def("Clear", [](SelectMgr_EntityOwner &self, const opencascade::handle<PrsMgr_PresentationManager> & a0) -> void { return self.Clear(a0); }, py::arg("aPM"));
	cls_SelectMgr_EntityOwner.def("Clear", (void (SelectMgr_EntityOwner::*)(const opencascade::handle<PrsMgr_PresentationManager> &, const Standard_Integer)) &SelectMgr_EntityOwner::Clear, "Clears the owners matching the value of the selection mode aMode from the presentation manager object aPM.", py::arg("aPM"), py::arg("aMode"));
	cls_SelectMgr_EntityOwner.def("HasLocation", (Standard_Boolean (SelectMgr_EntityOwner::*)() const ) &SelectMgr_EntityOwner::HasLocation, "None");
	cls_SelectMgr_EntityOwner.def("SetLocation", (void (SelectMgr_EntityOwner::*)(const TopLoc_Location &)) &SelectMgr_EntityOwner::SetLocation, "None", py::arg("aLoc"));
	cls_SelectMgr_EntityOwner.def("ResetLocation", (void (SelectMgr_EntityOwner::*)()) &SelectMgr_EntityOwner::ResetLocation, "None");
	cls_SelectMgr_EntityOwner.def("Location", (TopLoc_Location (SelectMgr_EntityOwner::*)() const ) &SelectMgr_EntityOwner::Location, "None");
	cls_SelectMgr_EntityOwner.def("SetSelected", (void (SelectMgr_EntityOwner::*)(const Standard_Boolean)) &SelectMgr_EntityOwner::SetSelected, "Set the state of the owner.", py::arg("theIsSelected"));
	cls_SelectMgr_EntityOwner.def("IsSelected", (Standard_Boolean (SelectMgr_EntityOwner::*)() const ) &SelectMgr_EntityOwner::IsSelected, "Returns Standard_True if the owner is selected.");
	cls_SelectMgr_EntityOwner.def("State", (void (SelectMgr_EntityOwner::*)(const Standard_Integer)) &SelectMgr_EntityOwner::State, "Set the state of the owner. The method is deprecated. Use SetSelected() instead.", py::arg("theStatus"));
	cls_SelectMgr_EntityOwner.def("State", (Standard_Integer (SelectMgr_EntityOwner::*)() const ) &SelectMgr_EntityOwner::State, "None");
	cls_SelectMgr_EntityOwner.def("IsAutoHilight", (Standard_Boolean (SelectMgr_EntityOwner::*)() const ) &SelectMgr_EntityOwner::IsAutoHilight, "if owner is not auto hilighted, for group contains many such owners will be called one method HilightSelected of SelectableObject");
	cls_SelectMgr_EntityOwner.def("IsForcedHilight", (Standard_Boolean (SelectMgr_EntityOwner::*)() const ) &SelectMgr_EntityOwner::IsForcedHilight, "if this method returns TRUE the owner will allways call method Hilight for SelectableObject when the owner is detected. By default it always return FALSE.");
	cls_SelectMgr_EntityOwner.def("SetZLayer", (void (SelectMgr_EntityOwner::*)(const Graphic3d_ZLayerId)) &SelectMgr_EntityOwner::SetZLayer, "Set Z layer ID and update all presentations.", py::arg("theLayerId"));
	cls_SelectMgr_EntityOwner.def("UpdateHighlightTrsf", (void (SelectMgr_EntityOwner::*)(const opencascade::handle<V3d_Viewer> &, const opencascade::handle<PrsMgr_PresentationManager3d> &, const Standard_Integer)) &SelectMgr_EntityOwner::UpdateHighlightTrsf, "Implements immediate application of location transformation of parent object to dynamic highlight structure", py::arg("theViewer"), py::arg("theManager"), py::arg("theDispMode"));
	cls_SelectMgr_EntityOwner.def("IsSameSelectable", (Standard_Boolean (SelectMgr_EntityOwner::*)(const opencascade::handle<SelectMgr_SelectableObject> &) const ) &SelectMgr_EntityOwner::IsSameSelectable, "Returns true if pointer to selectable object of this owner is equal to the given one", py::arg("theOther"));
	cls_SelectMgr_EntityOwner.def("ComesFromDecomposition", (Standard_Boolean (SelectMgr_EntityOwner::*)() const ) &SelectMgr_EntityOwner::ComesFromDecomposition, "Returns TRUE if this owner points to a part of object and FALSE for entire object.");
	cls_SelectMgr_EntityOwner.def("SetComesFromDecomposition", (void (SelectMgr_EntityOwner::*)(const Standard_Boolean)) &SelectMgr_EntityOwner::SetComesFromDecomposition, "Sets flag indicating this owner points to a part of object (TRUE) or to entire object (FALSE).", py::arg("theIsFromDecomposition"));
	cls_SelectMgr_EntityOwner.def("Set", (void (SelectMgr_EntityOwner::*)(const opencascade::handle<SelectMgr_SelectableObject> &)) &SelectMgr_EntityOwner::Set, "Sets the selectable object.", py::arg("theSelObj"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_SelectionManager.hxx
	py::class_<SelectMgr_SelectionManager, opencascade::handle<SelectMgr_SelectionManager>, Standard_Transient> cls_SelectMgr_SelectionManager(mod, "SelectMgr_SelectionManager", "A framework to manage selection from the point of view of viewer selectors. These can be added and removed, and selection modes can be activated and deactivated. In addition, objects may be known to all selectors or only to some.");
	cls_SelectMgr_SelectionManager.def(py::init<>());
	cls_SelectMgr_SelectionManager.def("Add", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_ViewerSelector> &)) &SelectMgr_SelectionManager::Add, "Adds the viewer selector theSelector to the list of known items.", py::arg("theSelector"));
	cls_SelectMgr_SelectionManager.def("Remove", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_ViewerSelector> &)) &SelectMgr_SelectionManager::Remove, "Removes viewer selector theSelector from the list of known items.", py::arg("theSelector"));
	cls_SelectMgr_SelectionManager.def("Contains", (Standard_Boolean (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_ViewerSelector> &) const ) &SelectMgr_SelectionManager::Contains, "Returns true if the manager contains the viewer selector theSelector in a list of known items.", py::arg("theSelector"));
	cls_SelectMgr_SelectionManager.def("Contains", (Standard_Boolean (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &) const ) &SelectMgr_SelectionManager::Contains, "Returns true if the manager contains the selectable object theObject.", py::arg("theObject"));
	cls_SelectMgr_SelectionManager.def("Load", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0) -> void { return self.Load(a0); }, py::arg("theObject"));
	cls_SelectMgr_SelectionManager.def("Load", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer)) &SelectMgr_SelectionManager::Load, "Loads and computes selection mode theMode (if it is not equal to -1) in global context and adds selectable object to BVH tree. If the object theObject has an already calculated selection with mode theMode and it was removed, the selection will be recalculated.", py::arg("theObject"), py::arg("theMode"));
	cls_SelectMgr_SelectionManager.def("Load", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0, const opencascade::handle<SelectMgr_ViewerSelector> & a1) -> void { return self.Load(a0, a1); }, py::arg("theObject"), py::arg("theSelector"));
	cls_SelectMgr_SelectionManager.def("Load", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const opencascade::handle<SelectMgr_ViewerSelector> &, const Standard_Integer)) &SelectMgr_SelectionManager::Load, "Loads and computes selection mode theMode (if it is not equal to -1) and adds selectable object to BVH tree. Does not perform check of existance of theObject in global context before addition, but adds theSelector to local context.", py::arg("theObject"), py::arg("theSelector"), py::arg("theMode"));
	cls_SelectMgr_SelectionManager.def("Remove", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &)) &SelectMgr_SelectionManager::Remove, "Removes selectable object theObject from all viewer selectors it was added to previously, removes it from all contexts and clears all computed selections of theObject.", py::arg("theObject"));
	cls_SelectMgr_SelectionManager.def("Remove", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const opencascade::handle<SelectMgr_ViewerSelector> &)) &SelectMgr_SelectionManager::Remove, "Removes theObject from theSelector, does not clear selections and unbind theObject from context maps.", py::arg("theObject"), py::arg("theSelector"));
	cls_SelectMgr_SelectionManager.def("Activate", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0) -> void { return self.Activate(a0); }, py::arg("theObject"));
	cls_SelectMgr_SelectionManager.def("Activate", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0, const Standard_Integer a1) -> void { return self.Activate(a0, a1); }, py::arg("theObject"), py::arg("theMode"));
	cls_SelectMgr_SelectionManager.def("Activate", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer, const opencascade::handle<SelectMgr_ViewerSelector> &)) &SelectMgr_SelectionManager::Activate, "Activates the selection mode theMode in the selector theSelector for the selectable object anObject. By default, theMode is equal to 0. If theSelector is set to default (NULL), the selection with the mode theMode will be activated in all the viewers available.", py::arg("theObject"), py::arg("theMode"), py::arg("theSelector"));
	cls_SelectMgr_SelectionManager.def("Deactivate", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0) -> void { return self.Deactivate(a0); }, py::arg("theObject"));
	cls_SelectMgr_SelectionManager.def("Deactivate", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0, const Standard_Integer a1) -> void { return self.Deactivate(a0, a1); }, py::arg("theObject"), py::arg("theMode"));
	cls_SelectMgr_SelectionManager.def("Deactivate", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer, const opencascade::handle<SelectMgr_ViewerSelector> &)) &SelectMgr_SelectionManager::Deactivate, "Deactivates mode theMode of theObject in theSelector. If theMode value is set to default (-1), all avtive selection modes will be deactivated. Likewise, if theSelector value is set to default (NULL), theMode will be deactivated in all viewer selectors.", py::arg("theObject"), py::arg("theMode"), py::arg("theSelector"));
	cls_SelectMgr_SelectionManager.def("IsActivated", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0) -> Standard_Boolean { return self.IsActivated(a0); }, py::arg("theObject"));
	cls_SelectMgr_SelectionManager.def("IsActivated", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0, const Standard_Integer a1) -> Standard_Boolean { return self.IsActivated(a0, a1); }, py::arg("theObject"), py::arg("theMode"));
	cls_SelectMgr_SelectionManager.def("IsActivated", (Standard_Boolean (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer, const opencascade::handle<SelectMgr_ViewerSelector> &) const ) &SelectMgr_SelectionManager::IsActivated, "Returns true if the selection with theMode is active for the selectable object theObject and selector theSelector. If all parameters are set to default values, it returns it there is any active selection in any known viewer selector for object theObject.", py::arg("theObject"), py::arg("theMode"), py::arg("theSelector"));
	cls_SelectMgr_SelectionManager.def("ClearSelectionStructures", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0) -> void { return self.ClearSelectionStructures(a0); }, py::arg("theObj"));
	cls_SelectMgr_SelectionManager.def("ClearSelectionStructures", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0, const Standard_Integer a1) -> void { return self.ClearSelectionStructures(a0, a1); }, py::arg("theObj"), py::arg("theMode"));
	cls_SelectMgr_SelectionManager.def("ClearSelectionStructures", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer, const opencascade::handle<SelectMgr_ViewerSelector> &)) &SelectMgr_SelectionManager::ClearSelectionStructures, "Removes sensitive entities from all viewer selectors after method Clear() was called to the selection they belonged to or it was recomputed somehow.", py::arg("theObj"), py::arg("theMode"), py::arg("theSelector"));
	cls_SelectMgr_SelectionManager.def("RestoreSelectionStructures", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0) -> void { return self.RestoreSelectionStructures(a0); }, py::arg("theObj"));
	cls_SelectMgr_SelectionManager.def("RestoreSelectionStructures", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0, const Standard_Integer a1) -> void { return self.RestoreSelectionStructures(a0, a1); }, py::arg("theObj"), py::arg("theMode"));
	cls_SelectMgr_SelectionManager.def("RestoreSelectionStructures", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer, const opencascade::handle<SelectMgr_ViewerSelector> &)) &SelectMgr_SelectionManager::RestoreSelectionStructures, "Re-adds newely calculated sensitive entities of recomputed selection defined by mode theMode to all viewer selectors contained that selection.", py::arg("theObj"), py::arg("theMode"), py::arg("theSelector"));
	cls_SelectMgr_SelectionManager.def("RecomputeSelection", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0) -> void { return self.RecomputeSelection(a0); }, py::arg("theObject"));
	cls_SelectMgr_SelectionManager.def("RecomputeSelection", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0, const Standard_Boolean a1) -> void { return self.RecomputeSelection(a0, a1); }, py::arg("theObject"), py::arg("theIsForce"));
	cls_SelectMgr_SelectionManager.def("RecomputeSelection", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Boolean, const Standard_Integer)) &SelectMgr_SelectionManager::RecomputeSelection, "Recomputes activated selections of theObject for all known viewer selectors according to theMode specified. If theMode is set to default (-1), then all activated selections will be recomputed. If theIsForce is set to true, then selection mode theMode for object theObject will be recomputed regardless of its activation status.", py::arg("theObject"), py::arg("theIsForce"), py::arg("theMode"));
	cls_SelectMgr_SelectionManager.def("Update", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0) -> void { return self.Update(a0); }, py::arg("theObject"));
	cls_SelectMgr_SelectionManager.def("Update", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Boolean)) &SelectMgr_SelectionManager::Update, "Updates all selections of theObject in all viewer selectors according to its current update status. If theIsForce is set to true, the call is equal to recomputation.", py::arg("theObject"), py::arg("theIsForce"));
	cls_SelectMgr_SelectionManager.def("Update", [](SelectMgr_SelectionManager &self, const opencascade::handle<SelectMgr_SelectableObject> & a0, const opencascade::handle<SelectMgr_ViewerSelector> & a1) -> void { return self.Update(a0, a1); }, py::arg("theObject"), py::arg("theSelector"));
	cls_SelectMgr_SelectionManager.def("Update", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const opencascade::handle<SelectMgr_ViewerSelector> &, const Standard_Boolean)) &SelectMgr_SelectionManager::Update, "Updates all selections of theObject in specified viewer selector according to its current update status. If theIsForce is set to true, the call is equal to recomputation.", py::arg("theObject"), py::arg("theSelector"), py::arg("theIsForce"));
	cls_SelectMgr_SelectionManager.def("SetUpdateMode", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const SelectMgr_TypeOfUpdate)) &SelectMgr_SelectionManager::SetUpdateMode, "Sets type of update of all selections of theObject to the given theType.", py::arg("theObject"), py::arg("theType"));
	cls_SelectMgr_SelectionManager.def("SetUpdateMode", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer, const SelectMgr_TypeOfUpdate)) &SelectMgr_SelectionManager::SetUpdateMode, "Sets type of update of selection with theMode of theObject to the given theType.", py::arg("theObject"), py::arg("theMode"), py::arg("theType"));
	cls_SelectMgr_SelectionManager.def("SetSelectionSensitivity", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer, const Standard_Integer)) &SelectMgr_SelectionManager::SetSelectionSensitivity, "Allows to manage sensitivity of a particular selection of interactive object theObject and changes previous sensitivity value of all sensitive entities in selection with theMode to the given theNewSensitivity.", py::arg("theObject"), py::arg("theMode"), py::arg("theNewSens"));
	cls_SelectMgr_SelectionManager.def("UpdateSelection", (void (SelectMgr_SelectionManager::*)(const opencascade::handle<SelectMgr_SelectableObject> &)) &SelectMgr_SelectionManager::UpdateSelection, "Re-adds selectable object in BVHs in all viewer selectors.", py::arg("theObj"));
	cls_SelectMgr_SelectionManager.def_static("get_type_name_", (const char * (*)()) &SelectMgr_SelectionManager::get_type_name, "None");
	cls_SelectMgr_SelectionManager.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_SelectionManager::get_type_descriptor, "None");
	cls_SelectMgr_SelectionManager.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_SelectionManager::*)() const ) &SelectMgr_SelectionManager::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_SelectableObject.hxx
	py::class_<SelectMgr_SelectableObject, opencascade::handle<SelectMgr_SelectableObject>, PrsMgr_PresentableObject> cls_SelectMgr_SelectableObject(mod, "SelectMgr_SelectableObject", "A framework to supply the structure of the object to be selected. At the first pick, this structure is created by calling the appropriate algorithm and retaining this framework for further picking. This abstract framework is inherited in Application Interactive Services (AIS), notably in AIS_InteractiveObject. Consequently, 3D selection should be handled by the relevant daughter classes and their member functions in AIS. This is particularly true in the creation of new interactive objects.");
	cls_SelectMgr_SelectableObject.def_static("get_type_name_", (const char * (*)()) &SelectMgr_SelectableObject::get_type_name, "None");
	cls_SelectMgr_SelectableObject.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_SelectableObject::get_type_descriptor, "None");
	cls_SelectMgr_SelectableObject.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_SelectableObject::*)() const ) &SelectMgr_SelectableObject::DynamicType, "None");
	cls_SelectMgr_SelectableObject.def("ComputeSelection", (void (SelectMgr_SelectableObject::*)(const opencascade::handle<SelectMgr_Selection> &, const Standard_Integer)) &SelectMgr_SelectableObject::ComputeSelection, "Recovers and calculates any sensitive primitive, aSelection, available in Shape mode, specified by aMode. As a rule, these are sensitive faces. This method is defined as virtual. This enables you to implement it in the creation of a new class of AIS Interactive Object. You need to do this and in so doing, redefine this method, if you create a class which enriches the list of signatures and types.", py::arg("aSelection"), py::arg("aMode"));
	cls_SelectMgr_SelectableObject.def("RecomputePrimitives", (void (SelectMgr_SelectableObject::*)()) &SelectMgr_SelectableObject::RecomputePrimitives, "Re-computes the sensitive primitives for all modes. IMPORTANT: Do not use this method to update selection primitives except implementing custom selection manager! This method does not take into account necessary BVH updates, but may invalidate the pointers it refers to. TO UPDATE SELECTION properly from outside classes, use method UpdateSelection.");
	cls_SelectMgr_SelectableObject.def("RecomputePrimitives", (void (SelectMgr_SelectableObject::*)(const Standard_Integer)) &SelectMgr_SelectableObject::RecomputePrimitives, "Re-computes the sensitive primitives which correspond to the <theMode>th selection mode. IMPORTANT: Do not use this method to update selection primitives except implementing custom selection manager! selection manager! This method does not take into account necessary BVH updates, but may invalidate the pointers it refers to. TO UPDATE SELECTION properly from outside classes, use method UpdateSelection.", py::arg("theMode"));
	cls_SelectMgr_SelectableObject.def("AddSelection", (void (SelectMgr_SelectableObject::*)(const opencascade::handle<SelectMgr_Selection> &, const Standard_Integer)) &SelectMgr_SelectableObject::AddSelection, "Adds the selection aSelection with the selection mode index aMode to this framework.", py::arg("aSelection"), py::arg("aMode"));
	cls_SelectMgr_SelectableObject.def("ClearSelections", [](SelectMgr_SelectableObject &self) -> void { return self.ClearSelections(); });
	cls_SelectMgr_SelectableObject.def("ClearSelections", (void (SelectMgr_SelectableObject::*)(const Standard_Boolean)) &SelectMgr_SelectableObject::ClearSelections, "Empties all the selections in the SelectableObject <update> parameter defines whether all object's selections should be flagged for further update or not. This improved method can be used to recompute an object's selection (without redisplaying the object completely) when some selection mode is activated not for the first time.", py::arg("update"));
	cls_SelectMgr_SelectableObject.def("Selection", (const opencascade::handle<SelectMgr_Selection> & (SelectMgr_SelectableObject::*)(const Standard_Integer) const ) &SelectMgr_SelectableObject::Selection, "Returns the selection Selection having the selection mode aMode.", py::arg("aMode"));
	cls_SelectMgr_SelectableObject.def("HasSelection", (Standard_Boolean (SelectMgr_SelectableObject::*)(const Standard_Integer) const ) &SelectMgr_SelectableObject::HasSelection, "Returns true if a selection corresponding to the selection mode theMode was computed for this object.", py::arg("theMode"));
	cls_SelectMgr_SelectableObject.def("Init", (void (SelectMgr_SelectableObject::*)()) &SelectMgr_SelectableObject::Init, "Begins the iteration scanning for sensitive primitives.");
	cls_SelectMgr_SelectableObject.def("More", (Standard_Boolean (SelectMgr_SelectableObject::*)() const ) &SelectMgr_SelectableObject::More, "Continues the iteration scanning for sensitive primitives.");
	cls_SelectMgr_SelectableObject.def("Next", (void (SelectMgr_SelectableObject::*)()) &SelectMgr_SelectableObject::Next, "Continues the iteration scanning for sensitive primitives.");
	cls_SelectMgr_SelectableObject.def("CurrentSelection", (const opencascade::handle<SelectMgr_Selection> & (SelectMgr_SelectableObject::*)() const ) &SelectMgr_SelectableObject::CurrentSelection, "Returns the current selection in this framework.");
	cls_SelectMgr_SelectableObject.def("ResetTransformation", (void (SelectMgr_SelectableObject::*)()) &SelectMgr_SelectableObject::ResetTransformation, "None");
	cls_SelectMgr_SelectableObject.def("UpdateTransformation", (void (SelectMgr_SelectableObject::*)()) &SelectMgr_SelectableObject::UpdateTransformation, "Recomputes the location of the selection aSelection.");
	cls_SelectMgr_SelectableObject.def("UpdateTransformations", (void (SelectMgr_SelectableObject::*)(const opencascade::handle<SelectMgr_Selection> &)) &SelectMgr_SelectableObject::UpdateTransformations, "Updates locations in all sensitive entities from <aSelection> and in corresponding entity owners.", py::arg("aSelection"));
	cls_SelectMgr_SelectableObject.def("HilightSelected", (void (SelectMgr_SelectableObject::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const SelectMgr_SequenceOfOwner &)) &SelectMgr_SelectableObject::HilightSelected, "Method which draws selected owners ( for fast presentation draw )", py::arg("PM"), py::arg("Seq"));
	cls_SelectMgr_SelectableObject.def("ClearSelected", (void (SelectMgr_SelectableObject::*)()) &SelectMgr_SelectableObject::ClearSelected, "Method which clear all selected owners belonging to this selectable object ( for fast presentation draw )");
	cls_SelectMgr_SelectableObject.def("ClearDynamicHighlight", (void (SelectMgr_SelectableObject::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &)) &SelectMgr_SelectableObject::ClearDynamicHighlight, "Method that needs to be implemented when the object manages selection and dynamic highlighting on its own. Clears or invalidates dynamic highlight presentation. By default it clears immediate draw of given presentation manager.", py::arg("theMgr"));
	cls_SelectMgr_SelectableObject.def("HilightOwnerWithColor", (void (SelectMgr_SelectableObject::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &, const opencascade::handle<Prs3d_Drawer> &, const opencascade::handle<SelectMgr_EntityOwner> &)) &SelectMgr_SelectableObject::HilightOwnerWithColor, "Method which hilight an owner belonging to this selectable object ( for fast presentation draw )", py::arg("thePM"), py::arg("theStyle"), py::arg("theOwner"));
	cls_SelectMgr_SelectableObject.def("IsAutoHilight", (Standard_Boolean (SelectMgr_SelectableObject::*)() const ) &SelectMgr_SelectableObject::IsAutoHilight, "If returns True, the old mechanism for highlighting selected objects is used (HilightSelected Method may be empty). If returns False, the HilightSelected method will be fully responsible for highlighting selected entity owners belonging to this selectable object.");
	cls_SelectMgr_SelectableObject.def("SetAutoHilight", (void (SelectMgr_SelectableObject::*)(const Standard_Boolean)) &SelectMgr_SelectableObject::SetAutoHilight, "Set AutoHilight property to true or false Sets up Transform Persistence Mode for this object", py::arg("newAutoHilight"));
	cls_SelectMgr_SelectableObject.def("GetHilightPresentation", (opencascade::handle<Prs3d_Presentation> (SelectMgr_SelectableObject::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &)) &SelectMgr_SelectableObject::GetHilightPresentation, "None", py::arg("TheMgr"));
	cls_SelectMgr_SelectableObject.def("GetSelectPresentation", (opencascade::handle<Prs3d_Presentation> (SelectMgr_SelectableObject::*)(const opencascade::handle<PrsMgr_PresentationManager3d> &)) &SelectMgr_SelectableObject::GetSelectPresentation, "None", py::arg("TheMgr"));
	cls_SelectMgr_SelectableObject.def("ErasePresentations", (void (SelectMgr_SelectableObject::*)(Standard_Boolean)) &SelectMgr_SelectableObject::ErasePresentations, "Removes presentations returned by GetHilightPresentation() and GetSelectPresentation().", py::arg("theToRemove"));
	cls_SelectMgr_SelectableObject.def("SetZLayer", (void (SelectMgr_SelectableObject::*)(const Graphic3d_ZLayerId)) &SelectMgr_SelectableObject::SetZLayer, "Set Z layer ID and update all presentations of the selectable object. The layers mechanism allows drawing objects in higher layers in overlay of objects in lower layers.", py::arg("theLayerId"));
	cls_SelectMgr_SelectableObject.def("UpdateSelection", [](SelectMgr_SelectableObject &self) -> void { return self.UpdateSelection(); });
	cls_SelectMgr_SelectableObject.def("UpdateSelection", (void (SelectMgr_SelectableObject::*)(const Standard_Integer)) &SelectMgr_SelectableObject::UpdateSelection, "Sets update status FULL to selections of the object. Must be used as the only method of UpdateSelection from outer classes to prevent BVH structures from being outdated.", py::arg("theMode"));
	cls_SelectMgr_SelectableObject.def("BoundingBox", (void (SelectMgr_SelectableObject::*)(Bnd_Box &)) &SelectMgr_SelectableObject::BoundingBox, "Returns bounding box of selectable object by storing its minimum and maximum 3d coordinates to output parameters", py::arg("theBndBox"));
	cls_SelectMgr_SelectableObject.def("SetAssemblyOwner", [](SelectMgr_SelectableObject &self, const opencascade::handle<SelectMgr_EntityOwner> & a0) -> void { return self.SetAssemblyOwner(a0); }, py::arg("theOwner"));
	cls_SelectMgr_SelectableObject.def("SetAssemblyOwner", (void (SelectMgr_SelectableObject::*)(const opencascade::handle<SelectMgr_EntityOwner> &, const Standard_Integer)) &SelectMgr_SelectableObject::SetAssemblyOwner, "Sets common entity owner for assembly sensitive object entities", py::arg("theOwner"), py::arg("theMode"));
	cls_SelectMgr_SelectableObject.def("GetAssemblyOwner", (const opencascade::handle<SelectMgr_EntityOwner> & (SelectMgr_SelectableObject::*)() const ) &SelectMgr_SelectableObject::GetAssemblyOwner, "Returns common entity owner if the object is an assembly");
	cls_SelectMgr_SelectableObject.def("BndBoxOfSelected", (Bnd_Box (SelectMgr_SelectableObject::*)(const opencascade::handle<SelectMgr_IndexedMapOfOwner> &)) &SelectMgr_SelectableObject::BndBoxOfSelected, "Returns a bounding box of sensitive entities with the owners given if they are a part of activated selection", py::arg("theOwners"));
	cls_SelectMgr_SelectableObject.def("GlobalSelectionMode", (Standard_Integer (SelectMgr_SelectableObject::*)() const ) &SelectMgr_SelectableObject::GlobalSelectionMode, "Returns the mode for selection of object as a whole");
	cls_SelectMgr_SelectableObject.def("GlobalSelOwner", (opencascade::handle<SelectMgr_EntityOwner> (SelectMgr_SelectableObject::*)() const ) &SelectMgr_SelectableObject::GlobalSelOwner, "Returns the owner of mode for selection of object as a whole");

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_SortCriterion.hxx
	py::class_<SelectMgr_SortCriterion, std::unique_ptr<SelectMgr_SortCriterion, Deleter<SelectMgr_SortCriterion>>> cls_SelectMgr_SortCriterion(mod, "SelectMgr_SortCriterion", "This class provides data and criterion for sorting candidate entities in the process of interactive selection by mouse click");
	cls_SelectMgr_SortCriterion.def(py::init<>());
	cls_SelectMgr_SortCriterion.def("__gt__", (bool (SelectMgr_SortCriterion::*)(const SelectMgr_SortCriterion &) const ) &SelectMgr_SortCriterion::operator>, py::is_operator(), "Comparison operator.", py::arg("theOther"));
	cls_SelectMgr_SortCriterion.def("__lt__", (bool (SelectMgr_SortCriterion::*)(const SelectMgr_SortCriterion &) const ) &SelectMgr_SortCriterion::operator<, py::is_operator(), "Comparison operator.", py::arg("theOther"));
	cls_SelectMgr_SortCriterion.def("IsGreater", (bool (SelectMgr_SortCriterion::*)(const SelectMgr_SortCriterion &) const ) &SelectMgr_SortCriterion::IsGreater, "Compare with another item.", py::arg("theOther"));
	cls_SelectMgr_SortCriterion.def("IsLower", (bool (SelectMgr_SortCriterion::*)(const SelectMgr_SortCriterion &) const ) &SelectMgr_SortCriterion::IsLower, "Compare with another item.", py::arg("theOther"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_FrustumBuilder.hxx
	py::class_<SelectMgr_FrustumBuilder, opencascade::handle<SelectMgr_FrustumBuilder>, Standard_Transient> cls_SelectMgr_FrustumBuilder(mod, "SelectMgr_FrustumBuilder", "The purpose of this class is to provide unified interface for building selecting frustum depending on current camera projection and orientation matrices, window size and viewport parameters.");
	cls_SelectMgr_FrustumBuilder.def(py::init<>());
	cls_SelectMgr_FrustumBuilder.def("SetWorldViewMatrix", (void (SelectMgr_FrustumBuilder::*)(const Graphic3d_Mat4d &)) &SelectMgr_FrustumBuilder::SetWorldViewMatrix, "Stores current world view transformation matrix", py::arg("theWorldViewMatrix"));
	cls_SelectMgr_FrustumBuilder.def("WorldViewMatrix", (const Graphic3d_Mat4d & (SelectMgr_FrustumBuilder::*)() const ) &SelectMgr_FrustumBuilder::WorldViewMatrix, "Returns current world view transformation matrix");
	cls_SelectMgr_FrustumBuilder.def("SetProjectionMatrix", (void (SelectMgr_FrustumBuilder::*)(const Graphic3d_Mat4d &)) &SelectMgr_FrustumBuilder::SetProjectionMatrix, "Stores current projection matrix", py::arg("theProjection"));
	cls_SelectMgr_FrustumBuilder.def("ProjectionMatrix", (const Graphic3d_Mat4d & (SelectMgr_FrustumBuilder::*)() const ) &SelectMgr_FrustumBuilder::ProjectionMatrix, "Returns current projection matrix");
	cls_SelectMgr_FrustumBuilder.def("SetWorldViewProjState", (void (SelectMgr_FrustumBuilder::*)(const Graphic3d_WorldViewProjState &)) &SelectMgr_FrustumBuilder::SetWorldViewProjState, "Stores current world view projection matrix state for the orientation and projection matrices", py::arg("theState"));
	cls_SelectMgr_FrustumBuilder.def("WorldViewProjState", (const Graphic3d_WorldViewProjState & (SelectMgr_FrustumBuilder::*)() const ) &SelectMgr_FrustumBuilder::WorldViewProjState, "Returns current world view projection state");
	cls_SelectMgr_FrustumBuilder.def("SetWindowSize", (void (SelectMgr_FrustumBuilder::*)(const Standard_Integer, const Standard_Integer)) &SelectMgr_FrustumBuilder::SetWindowSize, "Stores current window width and height", py::arg("theWidth"), py::arg("theHeight"));
	cls_SelectMgr_FrustumBuilder.def("SetViewport", (void (SelectMgr_FrustumBuilder::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &SelectMgr_FrustumBuilder::SetViewport, "Stores current viewport coordinates", py::arg("theX"), py::arg("theY"), py::arg("theWidth"), py::arg("theHeight"));
	cls_SelectMgr_FrustumBuilder.def("InvalidateViewport", (void (SelectMgr_FrustumBuilder::*)()) &SelectMgr_FrustumBuilder::InvalidateViewport, "None");
	cls_SelectMgr_FrustumBuilder.def("WindowSize", [](SelectMgr_FrustumBuilder &self, Standard_Integer & theWidth, Standard_Integer & theHeight){ self.WindowSize(theWidth, theHeight); return std::tuple<Standard_Integer &, Standard_Integer &>(theWidth, theHeight); }, "None", py::arg("theWidth"), py::arg("theHeight"));
	cls_SelectMgr_FrustumBuilder.def("SignedPlanePntDist", (Standard_Real (SelectMgr_FrustumBuilder::*)(const SelectMgr_Vec3 &, const SelectMgr_Vec3 &) const ) &SelectMgr_FrustumBuilder::SignedPlanePntDist, "Calculates signed distance between plane with equation theEq and point thePnt", py::arg("theEq"), py::arg("thePnt"));
	cls_SelectMgr_FrustumBuilder.def("ProjectPntOnViewPlane", (gp_Pnt (SelectMgr_FrustumBuilder::*)(const Standard_Real &, const Standard_Real &, const Standard_Real &) const ) &SelectMgr_FrustumBuilder::ProjectPntOnViewPlane, "Projects 2d screen point onto view frustum plane: theZ = 0 - near plane, theZ = 1 - far plane", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
	cls_SelectMgr_FrustumBuilder.def_static("get_type_name_", (const char * (*)()) &SelectMgr_FrustumBuilder::get_type_name, "None");
	cls_SelectMgr_FrustumBuilder.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_FrustumBuilder::get_type_descriptor, "None");
	cls_SelectMgr_FrustumBuilder.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_FrustumBuilder::*)() const ) &SelectMgr_FrustumBuilder::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_BaseFrustum.hxx
	py::class_<SelectMgr_BaseFrustum, opencascade::handle<SelectMgr_BaseFrustum>, Standard_Transient> cls_SelectMgr_BaseFrustum(mod, "SelectMgr_BaseFrustum", "This class is an interface for different types of selecting frustums, defining different selection types, like point, box or polyline selection. It contains signatures of functions for detection of overlap by sensitive entity and initializes some data for building the selecting frustum");
	cls_SelectMgr_BaseFrustum.def(py::init<>());
	cls_SelectMgr_BaseFrustum.def("Camera", (const opencascade::handle<Graphic3d_Camera> & (SelectMgr_BaseFrustum::*)() const ) &SelectMgr_BaseFrustum::Camera, "Return camera definition.");
	cls_SelectMgr_BaseFrustum.def("SetCamera", (void (SelectMgr_BaseFrustum::*)(const opencascade::handle<Graphic3d_Camera> &)) &SelectMgr_BaseFrustum::SetCamera, "Passes camera projection and orientation matrices to builder", py::arg("theCamera"));
	cls_SelectMgr_BaseFrustum.def("SetCamera", [](SelectMgr_BaseFrustum &self, const Graphic3d_Mat4d & a0, const Graphic3d_Mat4d & a1, const Standard_Boolean a2) -> void { return self.SetCamera(a0, a1, a2); }, py::arg("theProjection"), py::arg("theWorldView"), py::arg("theIsOrthographic"));
	cls_SelectMgr_BaseFrustum.def("SetCamera", (void (SelectMgr_BaseFrustum::*)(const Graphic3d_Mat4d &, const Graphic3d_Mat4d &, const Standard_Boolean, const Graphic3d_WorldViewProjState &)) &SelectMgr_BaseFrustum::SetCamera, "Passes camera projection and orientation matrices to builder", py::arg("theProjection"), py::arg("theWorldView"), py::arg("theIsOrthographic"), py::arg("theWVPState"));
	cls_SelectMgr_BaseFrustum.def("ProjectionMatrix", (const Graphic3d_Mat4d & (SelectMgr_BaseFrustum::*)() const ) &SelectMgr_BaseFrustum::ProjectionMatrix, "Returns current camera projection transformation common for all selecting volumes");
	cls_SelectMgr_BaseFrustum.def("WorldViewMatrix", (const Graphic3d_Mat4d & (SelectMgr_BaseFrustum::*)() const ) &SelectMgr_BaseFrustum::WorldViewMatrix, "Returns current camera world view transformation common for all selecting volumes");
	cls_SelectMgr_BaseFrustum.def("WorldViewProjState", (const Graphic3d_WorldViewProjState & (SelectMgr_BaseFrustum::*)() const ) &SelectMgr_BaseFrustum::WorldViewProjState, "Returns current camera world view projection transformation state");
	cls_SelectMgr_BaseFrustum.def("SetPixelTolerance", (void (SelectMgr_BaseFrustum::*)(const Standard_Integer)) &SelectMgr_BaseFrustum::SetPixelTolerance, "None", py::arg("theTol"));
	cls_SelectMgr_BaseFrustum.def("SetWindowSize", (void (SelectMgr_BaseFrustum::*)(const Standard_Integer, const Standard_Integer)) &SelectMgr_BaseFrustum::SetWindowSize, "None", py::arg("theWidth"), py::arg("theHeight"));
	cls_SelectMgr_BaseFrustum.def("WindowSize", [](SelectMgr_BaseFrustum &self, Standard_Integer & theWidth, Standard_Integer & theHeight){ self.WindowSize(theWidth, theHeight); return std::tuple<Standard_Integer &, Standard_Integer &>(theWidth, theHeight); }, "None", py::arg("theWidth"), py::arg("theHeight"));
	cls_SelectMgr_BaseFrustum.def("SetViewport", (void (SelectMgr_BaseFrustum::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &SelectMgr_BaseFrustum::SetViewport, "Passes viewport parameters to builder", py::arg("theX"), py::arg("theY"), py::arg("theWidth"), py::arg("theHeight"));
	cls_SelectMgr_BaseFrustum.def("SetBuilder", (void (SelectMgr_BaseFrustum::*)(const opencascade::handle<SelectMgr_FrustumBuilder> &)) &SelectMgr_BaseFrustum::SetBuilder, "Nullifies the builder created in the constructor and copies the pointer given", py::arg("theBuilder"));
	cls_SelectMgr_BaseFrustum.def("Build", (void (SelectMgr_BaseFrustum::*)(const gp_Pnt2d &)) &SelectMgr_BaseFrustum::Build, "Builds volume according to the point and given pixel tolerance", py::arg(""));
	cls_SelectMgr_BaseFrustum.def("Build", (void (SelectMgr_BaseFrustum::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &SelectMgr_BaseFrustum::Build, "Builds volume according to the selected rectangle", py::arg(""), py::arg(""));
	cls_SelectMgr_BaseFrustum.def("Build", (void (SelectMgr_BaseFrustum::*)(const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &)) &SelectMgr_BaseFrustum::Build, "Builds volume according to the triangle given", py::arg(""), py::arg(""), py::arg(""));
	cls_SelectMgr_BaseFrustum.def("Build", (void (SelectMgr_BaseFrustum::*)(const TColgp_Array1OfPnt2d &)) &SelectMgr_BaseFrustum::Build, "Builds selecting volumes set according to polyline points", py::arg(""));
	cls_SelectMgr_BaseFrustum.def("ScaleAndTransform", (opencascade::handle<SelectMgr_BaseFrustum> (SelectMgr_BaseFrustum::*)(const Standard_Integer, const gp_GTrsf &) const ) &SelectMgr_BaseFrustum::ScaleAndTransform, "IMPORTANT: Scaling makes sense only for frustum built on a single point! Note that this method does not perform any checks on type of the frustum. Returns a copy of the frustum resized according to the scale factor given and transforms it using the matrix given. There are no default parameters, but in case if: - transformation only is needed: must be initialized as any negative value; - scale only is needed: must be set to gp_Identity.", py::arg(""), py::arg(""));
	cls_SelectMgr_BaseFrustum.def("Overlaps", [](SelectMgr_BaseFrustum &self, const SelectMgr_Vec3 & theBoxMin, const SelectMgr_Vec3 & theBoxMax, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(theBoxMin, theBoxMax, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "SAT intersection test between defined volume and given axis-aligned box", py::arg("theBoxMin"), py::arg("theBoxMax"), py::arg("theDepth"));
	cls_SelectMgr_BaseFrustum.def("Overlaps", [](SelectMgr_BaseFrustum &self, const SelectMgr_Vec3 & theBoxMin, const SelectMgr_Vec3 & theBoxMax, Standard_Boolean * theInside){ Standard_Boolean rv = self.Overlaps(theBoxMin, theBoxMax, theInside); return std::tuple<Standard_Boolean, Standard_Boolean *>(rv, theInside); }, "Returns true if selecting volume is overlapped by axis-aligned bounding box with minimum corner at point theMinPt and maximum at point theMaxPt", py::arg("theBoxMin"), py::arg("theBoxMax"), py::arg("theInside"));
	cls_SelectMgr_BaseFrustum.def("Overlaps", [](SelectMgr_BaseFrustum &self, const gp_Pnt & thePnt, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "Intersection test between defined volume and given point", py::arg("thePnt"), py::arg("theDepth"));
	cls_SelectMgr_BaseFrustum.def("Overlaps", (Standard_Boolean (SelectMgr_BaseFrustum::*)(const gp_Pnt &)) &SelectMgr_BaseFrustum::Overlaps, "Intersection test between defined volume and given point Does not perform depth calculation, so this method is defined as helper function for inclusion test. Therefore, its implementation makes sense only for rectangular frustum with box selection mode activated.", py::arg("thePnt"));
	cls_SelectMgr_BaseFrustum.def("Overlaps", [](SelectMgr_BaseFrustum &self, const TColgp_Array1OfPnt & theArrayOfPnts, Select3D_TypeOfSensitivity theSensType, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(theArrayOfPnts, theSensType, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "SAT intersection test between defined volume and given ordered set of points, representing line segments. The test may be considered of interior part or boundary line defined by segments depending on given sensitivity type", py::arg("theArrayOfPnts"), py::arg("theSensType"), py::arg("theDepth"));
	cls_SelectMgr_BaseFrustum.def("Overlaps", [](SelectMgr_BaseFrustum &self, const gp_Pnt & thePnt1, const gp_Pnt & thePnt2, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt1, thePnt2, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "Checks if line segment overlaps selecting frustum", py::arg("thePnt1"), py::arg("thePnt2"), py::arg("theDepth"));
	cls_SelectMgr_BaseFrustum.def("Overlaps", [](SelectMgr_BaseFrustum &self, const gp_Pnt & thePt1, const gp_Pnt & thePt2, const gp_Pnt & thePt3, Select3D_TypeOfSensitivity theSensType, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePt1, thePt2, thePt3, theSensType, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "SAT intersection test between defined volume and given triangle. The test may be considered of interior part or boundary line defined by triangle vertices depending on given sensitivity type", py::arg("thePt1"), py::arg("thePt2"), py::arg("thePt3"), py::arg("theSensType"), py::arg("theDepth"));
	cls_SelectMgr_BaseFrustum.def("DistToGeometryCenter", (Standard_Real (SelectMgr_BaseFrustum::*)(const gp_Pnt &)) &SelectMgr_BaseFrustum::DistToGeometryCenter, "Measures distance between 3d projection of user-picked screen point and given point theCOG", py::arg("theCOG"));
	cls_SelectMgr_BaseFrustum.def("DetectedPoint", (gp_Pnt (SelectMgr_BaseFrustum::*)(const Standard_Real) const ) &SelectMgr_BaseFrustum::DetectedPoint, "None", py::arg("theDepth"));
	cls_SelectMgr_BaseFrustum.def("IsClipped", (Standard_Boolean (SelectMgr_BaseFrustum::*)(const Graphic3d_SequenceOfHClipPlane &, const Standard_Real)) &SelectMgr_BaseFrustum::IsClipped, "Checks if the point of sensitive in which selection was detected belongs to the region defined by clipping planes", py::arg("thePlanes"), py::arg("theDepth"));
	cls_SelectMgr_BaseFrustum.def("SetViewClipping", (void (SelectMgr_BaseFrustum::*)(const opencascade::handle<Graphic3d_SequenceOfHClipPlane> &)) &SelectMgr_BaseFrustum::SetViewClipping, "Valid for point selection only! Computes depth range for global (defined for the whole view) clipping planes.", py::arg(""));
	cls_SelectMgr_BaseFrustum.def("SetViewClippingEnabled", (Standard_Boolean (SelectMgr_BaseFrustum::*)(const Standard_Boolean)) &SelectMgr_BaseFrustum::SetViewClippingEnabled, "Set if view clipping plane is enabled or not.", py::arg(""));
	cls_SelectMgr_BaseFrustum.def("GetPlanes", (void (SelectMgr_BaseFrustum::*)(NCollection_Vector<SelectMgr_Vec4> &) const ) &SelectMgr_BaseFrustum::GetPlanes, "Stores plane equation coefficients (in the following form: Ax + By + Cz + D = 0) to the given vector", py::arg("thePlaneEquations"));
	cls_SelectMgr_BaseFrustum.def_static("get_type_name_", (const char * (*)()) &SelectMgr_BaseFrustum::get_type_name, "None");
	cls_SelectMgr_BaseFrustum.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_BaseFrustum::get_type_descriptor, "None");
	cls_SelectMgr_BaseFrustum.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_BaseFrustum::*)() const ) &SelectMgr_BaseFrustum::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_ViewClipRange.hxx
	py::class_<SelectMgr_ViewClipRange, std::unique_ptr<SelectMgr_ViewClipRange, Deleter<SelectMgr_ViewClipRange>>> cls_SelectMgr_ViewClipRange(mod, "SelectMgr_ViewClipRange", "Class for handling depth clipping range. It is used to perform checks in case if global (for the whole view) clipping planes are defined inside of SelectMgr_RectangularFrustum class methods.");
	cls_SelectMgr_ViewClipRange.def(py::init<>());
	cls_SelectMgr_ViewClipRange.def("Set", (void (SelectMgr_ViewClipRange::*)(const Standard_Real, const Standard_Real)) &SelectMgr_ViewClipRange::Set, "Sets boundaries and validates view clipping range", py::arg("theDepthMin"), py::arg("theDepthMax"));
	cls_SelectMgr_ViewClipRange.def("IsValid", (Standard_Boolean (SelectMgr_ViewClipRange::*)() const ) &SelectMgr_ViewClipRange::IsValid, "Returns true if clip range is set and depth of each matched primitive must be tested for satisfying the defined interval");
	cls_SelectMgr_ViewClipRange.def("MaxDepth", (Standard_Real (SelectMgr_ViewClipRange::*)() const ) &SelectMgr_ViewClipRange::MaxDepth, "Returns the upper bound of valid depth range");
	cls_SelectMgr_ViewClipRange.def("MinDepth", (Standard_Real (SelectMgr_ViewClipRange::*)() const ) &SelectMgr_ViewClipRange::MinDepth, "Returns the lower bound of valid depth range");
	cls_SelectMgr_ViewClipRange.def("Clear", (void (SelectMgr_ViewClipRange::*)()) &SelectMgr_ViewClipRange::Clear, "Invalidates view clipping range");

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_RectangularFrustum.hxx
	py::class_<SelectMgr_RectangularFrustum, std::unique_ptr<SelectMgr_RectangularFrustum, Deleter<SelectMgr_RectangularFrustum>>, SelectMgr_Frustum<4>> cls_SelectMgr_RectangularFrustum(mod, "SelectMgr_RectangularFrustum", "This class contains representation of rectangular selecting frustum, created in case of point and box selection, and algorithms for overlap detection between selecting frustum and sensitive entities. The principle of frustum calculation: - for point selection: on a near view frustum plane rectangular neighborhood of user-picked point is created according to the pixel tolerance given and then this rectangle is projected onto far view frustum plane. This rectangles define the parallel bases of selecting frustum; - for box selection: box points are projected onto near and far view frustum planes. These 2 projected rectangles define parallel bases of selecting frustum. Overlap detection tests are implemented according to the terms of separating axis theorem (SAT).");
	cls_SelectMgr_RectangularFrustum.def(py::init<>());
	cls_SelectMgr_RectangularFrustum.def("Build", (void (SelectMgr_RectangularFrustum::*)(const gp_Pnt2d &)) &SelectMgr_RectangularFrustum::Build, "Builds volume according to the point and given pixel tolerance", py::arg("thePoint"));
	cls_SelectMgr_RectangularFrustum.def("Build", (void (SelectMgr_RectangularFrustum::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &SelectMgr_RectangularFrustum::Build, "Builds volume according to the selected rectangle", py::arg("theMinPnt"), py::arg("theMaxPnt"));
	cls_SelectMgr_RectangularFrustum.def("ScaleAndTransform", (opencascade::handle<SelectMgr_BaseFrustum> (SelectMgr_RectangularFrustum::*)(const Standard_Integer, const gp_GTrsf &) const ) &SelectMgr_RectangularFrustum::ScaleAndTransform, "IMPORTANT: Scaling makes sense only for frustum built on a single point! Note that this method does not perform any checks on type of the frustum. Returns a copy of the frustum resized according to the scale factor given and transforms it using the matrix given. There are no default parameters, but in case if: - transformation only is needed: must be initialized as any negative value; - scale only is needed: must be set to gp_Identity.", py::arg("theScaleFactor"), py::arg("theTrsf"));
	cls_SelectMgr_RectangularFrustum.def("Overlaps", [](SelectMgr_RectangularFrustum &self, const SelectMgr_Vec3 & theBoxMin, const SelectMgr_Vec3 & theBoxMax, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(theBoxMin, theBoxMax, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "SAT intersection test between defined volume and given axis-aligned box", py::arg("theBoxMin"), py::arg("theBoxMax"), py::arg("theDepth"));
	cls_SelectMgr_RectangularFrustum.def("Overlaps", [](SelectMgr_RectangularFrustum &self, const SelectMgr_Vec3 & theBoxMin, const SelectMgr_Vec3 & theBoxMax, Standard_Boolean * theInside){ Standard_Boolean rv = self.Overlaps(theBoxMin, theBoxMax, theInside); return std::tuple<Standard_Boolean, Standard_Boolean *>(rv, theInside); }, "Returns true if selecting volume is overlapped by axis-aligned bounding box with minimum corner at point theMinPt and maximum at point theMaxPt", py::arg("theBoxMin"), py::arg("theBoxMax"), py::arg("theInside"));
	cls_SelectMgr_RectangularFrustum.def("Overlaps", [](SelectMgr_RectangularFrustum &self, const gp_Pnt & thePnt, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "Intersection test between defined volume and given point", py::arg("thePnt"), py::arg("theDepth"));
	cls_SelectMgr_RectangularFrustum.def("Overlaps", (Standard_Boolean (SelectMgr_RectangularFrustum::*)(const gp_Pnt &)) &SelectMgr_RectangularFrustum::Overlaps, "Intersection test between defined volume and given point", py::arg("thePnt"));
	cls_SelectMgr_RectangularFrustum.def("Overlaps", [](SelectMgr_RectangularFrustum &self, const TColgp_Array1OfPnt & theArrayOfPnts, Select3D_TypeOfSensitivity theSensType, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(theArrayOfPnts, theSensType, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "SAT intersection test between defined volume and given ordered set of points, representing line segments. The test may be considered of interior part or boundary line defined by segments depending on given sensitivity type", py::arg("theArrayOfPnts"), py::arg("theSensType"), py::arg("theDepth"));
	cls_SelectMgr_RectangularFrustum.def("Overlaps", [](SelectMgr_RectangularFrustum &self, const gp_Pnt & thePnt1, const gp_Pnt & thePnt2, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt1, thePnt2, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "Checks if line segment overlaps selecting frustum", py::arg("thePnt1"), py::arg("thePnt2"), py::arg("theDepth"));
	cls_SelectMgr_RectangularFrustum.def("Overlaps", [](SelectMgr_RectangularFrustum &self, const gp_Pnt & thePnt1, const gp_Pnt & thePnt2, const gp_Pnt & thePnt3, Select3D_TypeOfSensitivity theSensType, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt1, thePnt2, thePnt3, theSensType, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "SAT intersection test between defined volume and given triangle. The test may be considered of interior part or boundary line defined by triangle vertices depending on given sensitivity type", py::arg("thePnt1"), py::arg("thePnt2"), py::arg("thePnt3"), py::arg("theSensType"), py::arg("theDepth"));
	cls_SelectMgr_RectangularFrustum.def("DistToGeometryCenter", (Standard_Real (SelectMgr_RectangularFrustum::*)(const gp_Pnt &)) &SelectMgr_RectangularFrustum::DistToGeometryCenter, "Measures distance between 3d projection of user-picked screen point and given point theCOG", py::arg("theCOG"));
	cls_SelectMgr_RectangularFrustum.def("DetectedPoint", (gp_Pnt (SelectMgr_RectangularFrustum::*)(const Standard_Real) const ) &SelectMgr_RectangularFrustum::DetectedPoint, "Calculates the point on a view ray that was detected during the run of selection algo by given depth", py::arg("theDepth"));
	cls_SelectMgr_RectangularFrustum.def("IsClipped", (Standard_Boolean (SelectMgr_RectangularFrustum::*)(const Graphic3d_SequenceOfHClipPlane &, const Standard_Real)) &SelectMgr_RectangularFrustum::IsClipped, "Checks if the point of sensitive in which selection was detected belongs to the region defined by clipping planes", py::arg("thePlanes"), py::arg("theDepth"));
	cls_SelectMgr_RectangularFrustum.def("SetViewClipping", (void (SelectMgr_RectangularFrustum::*)(const opencascade::handle<Graphic3d_SequenceOfHClipPlane> &)) &SelectMgr_RectangularFrustum::SetViewClipping, "Valid for point selection only! Computes depth range for global (defined for the whole view) clipping planes.", py::arg("thePlanes"));
	cls_SelectMgr_RectangularFrustum.def("SetViewClippingEnabled", (Standard_Boolean (SelectMgr_RectangularFrustum::*)(const Standard_Boolean)) &SelectMgr_RectangularFrustum::SetViewClippingEnabled, "Set if view clipping plane is enabled or not.", py::arg("theToEnable"));
	cls_SelectMgr_RectangularFrustum.def("GetVertices", (const gp_Pnt * (SelectMgr_RectangularFrustum::*)() const ) &SelectMgr_RectangularFrustum::GetVertices, "A set of helper functions that return rectangular selecting frustum data");
	cls_SelectMgr_RectangularFrustum.def("GetNearPnt", (const gp_Pnt & (SelectMgr_RectangularFrustum::*)() const ) &SelectMgr_RectangularFrustum::GetNearPnt, "Returns projection of 2d mouse picked point or projection of center of 2d rectangle (for point and rectangular selection correspondingly) onto near view frustum plane");
	cls_SelectMgr_RectangularFrustum.def("GetFarPnt", (const gp_Pnt & (SelectMgr_RectangularFrustum::*)() const ) &SelectMgr_RectangularFrustum::GetFarPnt, "Returns projection of 2d mouse picked point or projection of center of 2d rectangle (for point and rectangular selection correspondingly) onto far view frustum plane");
	cls_SelectMgr_RectangularFrustum.def("GetPlanes", (void (SelectMgr_RectangularFrustum::*)(NCollection_Vector<SelectMgr_Vec4> &) const ) &SelectMgr_RectangularFrustum::GetPlanes, "Stores plane equation coefficients (in the following form: Ax + By + Cz + D = 0) to the given vector", py::arg("thePlaneEquations"));
	*/

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_TriangularFrustum.hxx
	py::class_<SelectMgr_TriangularFrustum, std::unique_ptr<SelectMgr_TriangularFrustum, Deleter<SelectMgr_TriangularFrustum>>, SelectMgr_Frustum<3>> cls_SelectMgr_TriangularFrustum(mod, "SelectMgr_TriangularFrustum", "This class contains representation of triangular selecting frustum, created in case of polyline selection, and algorithms for overlap detection between selecting frustum and sensitive entities. Overlap detection tests are implemented according to the terms of separating axis theorem (SAT).");
	cls_SelectMgr_TriangularFrustum.def(py::init<>());
	cls_SelectMgr_TriangularFrustum.def("Build", (void (SelectMgr_TriangularFrustum::*)(const gp_Pnt2d &, const gp_Pnt2d &, const gp_Pnt2d &)) &SelectMgr_TriangularFrustum::Build, "Creates new triangular frustum with bases of triangles with vertices theP1, theP2 and theP3 projections onto near and far view frustum planes (only for triangular frustums)", py::arg("theP1"), py::arg("theP2"), py::arg("theP3"));
	cls_SelectMgr_TriangularFrustum.def("ScaleAndTransform", (opencascade::handle<SelectMgr_BaseFrustum> (SelectMgr_TriangularFrustum::*)(const Standard_Integer, const gp_GTrsf &) const ) &SelectMgr_TriangularFrustum::ScaleAndTransform, "Returns a copy of the frustum transformed according to the matrix given", py::arg("theScale"), py::arg("theTrsf"));
	cls_SelectMgr_TriangularFrustum.def("Overlaps", [](SelectMgr_TriangularFrustum &self, const SelectMgr_Vec3 & theMinPnt, const SelectMgr_Vec3 & theMaxPnt, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(theMinPnt, theMaxPnt, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "SAT intersection test between defined volume and given axis-aligned box", py::arg("theMinPnt"), py::arg("theMaxPnt"), py::arg("theDepth"));
	cls_SelectMgr_TriangularFrustum.def("Overlaps", [](SelectMgr_TriangularFrustum &self, const SelectMgr_Vec3 & theMinPt, const SelectMgr_Vec3 & theMaxPt, Standard_Boolean * theInside){ Standard_Boolean rv = self.Overlaps(theMinPt, theMaxPt, theInside); return std::tuple<Standard_Boolean, Standard_Boolean *>(rv, theInside); }, "Returns true if selecting volume is overlapped by axis-aligned bounding box with minimum corner at point theMinPt and maximum at point theMaxPt", py::arg("theMinPt"), py::arg("theMaxPt"), py::arg("theInside"));
	cls_SelectMgr_TriangularFrustum.def("Overlaps", [](SelectMgr_TriangularFrustum &self, const gp_Pnt & thePnt, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "Intersection test between defined volume and given point", py::arg("thePnt"), py::arg("theDepth"));
	cls_SelectMgr_TriangularFrustum.def("Overlaps", [](SelectMgr_TriangularFrustum &self, const TColgp_Array1OfPnt & theArrayOfPnts, Select3D_TypeOfSensitivity theSensType, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(theArrayOfPnts, theSensType, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "SAT intersection test between defined volume and given ordered set of points, representing line segments. The test may be considered of interior part or boundary line defined by segments depending on given sensitivity type", py::arg("theArrayOfPnts"), py::arg("theSensType"), py::arg("theDepth"));
	cls_SelectMgr_TriangularFrustum.def("Overlaps", [](SelectMgr_TriangularFrustum &self, const gp_Pnt & thePnt1, const gp_Pnt & thePnt2, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt1, thePnt2, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "Checks if line segment overlaps selecting frustum", py::arg("thePnt1"), py::arg("thePnt2"), py::arg("theDepth"));
	cls_SelectMgr_TriangularFrustum.def("Overlaps", [](SelectMgr_TriangularFrustum &self, const gp_Pnt & thePnt1, const gp_Pnt & thePnt2, const gp_Pnt & thePnt3, Select3D_TypeOfSensitivity theSensType, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt1, thePnt2, thePnt3, theSensType, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "SAT intersection test between defined volume and given triangle. The test may be considered of interior part or boundary line defined by triangle vertices depending on given sensitivity type", py::arg("thePnt1"), py::arg("thePnt2"), py::arg("thePnt3"), py::arg("theSensType"), py::arg("theDepth"));
	cls_SelectMgr_TriangularFrustum.def("Clear", (void (SelectMgr_TriangularFrustum::*)()) &SelectMgr_TriangularFrustum::Clear, "Nullifies the handle to corresponding builder instance to prevent memory leaks");
	cls_SelectMgr_TriangularFrustum.def("GetPlanes", (void (SelectMgr_TriangularFrustum::*)(NCollection_Vector<SelectMgr_Vec4> &) const ) &SelectMgr_TriangularFrustum::GetPlanes, "Stores plane equation coefficients (in the following form: Ax + By + Cz + D = 0) to the given vector", py::arg("thePlaneEquations"));
	cls_SelectMgr_TriangularFrustum.def_static("get_type_name_", (const char * (*)()) &SelectMgr_TriangularFrustum::get_type_name, "None");
	cls_SelectMgr_TriangularFrustum.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_TriangularFrustum::get_type_descriptor, "None");
	cls_SelectMgr_TriangularFrustum.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_TriangularFrustum::*)() const ) &SelectMgr_TriangularFrustum::DynamicType, "None");
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_TriangularFrustumSet.hxx
	py::class_<SelectMgr_TriangularFrustumSet, opencascade::handle<SelectMgr_TriangularFrustumSet>, SelectMgr_BaseFrustum> cls_SelectMgr_TriangularFrustumSet(mod, "SelectMgr_TriangularFrustumSet", "This class is used to handle polyline selection. The main principle of polyline selection algorithm is to split the polygon defined by polyline onto triangles. Than each of them is considered as a base for triangular frustum building. In other words, each triangle vertiex will be projected from 2d screen space to 3d world space onto near and far view frustum planes. Thus, the projected triangles make up the bases of selecting frustum. When the set of such frustums is created, the function determining selection iterates through triangular frustum set and searches for overlap with any frustum.");
	cls_SelectMgr_TriangularFrustumSet.def(py::init<>());
	cls_SelectMgr_TriangularFrustumSet.def("Build", (void (SelectMgr_TriangularFrustumSet::*)(const TColgp_Array1OfPnt2d &)) &SelectMgr_TriangularFrustumSet::Build, "Meshes polygon bounded by polyline. Than organizes a set of triangular frustums, where each triangle's projection onto near and far view frustum planes is considered as a frustum base", py::arg("thePoints"));
	cls_SelectMgr_TriangularFrustumSet.def("ScaleAndTransform", (opencascade::handle<SelectMgr_BaseFrustum> (SelectMgr_TriangularFrustumSet::*)(const Standard_Integer, const gp_GTrsf &) const ) &SelectMgr_TriangularFrustumSet::ScaleAndTransform, "Returns a copy of the frustum with all sub-volumes transformed according to the matrix given", py::arg("theScale"), py::arg("theTrsf"));
	cls_SelectMgr_TriangularFrustumSet.def("Overlaps", [](SelectMgr_TriangularFrustumSet &self, const SelectMgr_Vec3 & theMinPnt, const SelectMgr_Vec3 & theMaxPnt, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(theMinPnt, theMaxPnt, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "None", py::arg("theMinPnt"), py::arg("theMaxPnt"), py::arg("theDepth"));
	cls_SelectMgr_TriangularFrustumSet.def("Overlaps", [](SelectMgr_TriangularFrustumSet &self, const SelectMgr_Vec3 & theMinPnt, const SelectMgr_Vec3 & theMaxPnt, Standard_Boolean * theInside){ Standard_Boolean rv = self.Overlaps(theMinPnt, theMaxPnt, theInside); return std::tuple<Standard_Boolean, Standard_Boolean *>(rv, theInside); }, "None", py::arg("theMinPnt"), py::arg("theMaxPnt"), py::arg("theInside"));
	cls_SelectMgr_TriangularFrustumSet.def("Overlaps", [](SelectMgr_TriangularFrustumSet &self, const gp_Pnt & thePnt, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "None", py::arg("thePnt"), py::arg("theDepth"));
	cls_SelectMgr_TriangularFrustumSet.def("Overlaps", [](SelectMgr_TriangularFrustumSet &self, const TColgp_Array1OfPnt & theArrayOfPnts, Select3D_TypeOfSensitivity theSensType, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(theArrayOfPnts, theSensType, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "None", py::arg("theArrayOfPnts"), py::arg("theSensType"), py::arg("theDepth"));
	cls_SelectMgr_TriangularFrustumSet.def("Overlaps", [](SelectMgr_TriangularFrustumSet &self, const gp_Pnt & thePnt1, const gp_Pnt & thePnt2, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt1, thePnt2, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "None", py::arg("thePnt1"), py::arg("thePnt2"), py::arg("theDepth"));
	cls_SelectMgr_TriangularFrustumSet.def("Overlaps", [](SelectMgr_TriangularFrustumSet &self, const gp_Pnt & thePnt1, const gp_Pnt & thePnt2, const gp_Pnt & thePnt3, Select3D_TypeOfSensitivity theSensType, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt1, thePnt2, thePnt3, theSensType, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "None", py::arg("thePnt1"), py::arg("thePnt2"), py::arg("thePnt3"), py::arg("theSensType"), py::arg("theDepth"));
	cls_SelectMgr_TriangularFrustumSet.def("GetPlanes", (void (SelectMgr_TriangularFrustumSet::*)(NCollection_Vector<SelectMgr_Vec4> &) const ) &SelectMgr_TriangularFrustumSet::GetPlanes, "Stores plane equation coefficients (in the following form: Ax + By + Cz + D = 0) to the given vector", py::arg("thePlaneEquations"));

	// Callback for SelectMgr_SelectingVolumeManager.
	class PyCallback_SelectMgr_SelectingVolumeManager : public SelectMgr_SelectingVolumeManager {
	public:
		using SelectMgr_SelectingVolumeManager::SelectMgr_SelectingVolumeManager;

		Standard_Boolean Overlaps(const NCollection_Vec3<Standard_Real> & theBoxMin, const NCollection_Vec3<Standard_Real> & theBoxMax, Standard_Real & theDepth) override { PYBIND11_OVERLOAD_PURE(Standard_Boolean, SelectMgr_SelectingVolumeManager, Overlaps, theBoxMin, theBoxMax, theDepth); }
		Standard_Boolean Overlaps(const NCollection_Vec3<Standard_Real> & theBoxMin, const NCollection_Vec3<Standard_Real> & theBoxMax, Standard_Boolean * theInside) override { PYBIND11_OVERLOAD_PURE(Standard_Boolean, SelectMgr_SelectingVolumeManager, Overlaps, theBoxMin, theBoxMax, theInside); }
		void GetPlanes(NCollection_Vector<NCollection_Vec4<Standard_Real> > & thePlaneEquations) const  override { PYBIND11_OVERLOAD_PURE(void, SelectMgr_SelectingVolumeManager, GetPlanes, thePlaneEquations); }
	};

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_SelectingVolumeManager.hxx
	py::class_<SelectMgr_SelectingVolumeManager, std::unique_ptr<SelectMgr_SelectingVolumeManager, Deleter<SelectMgr_SelectingVolumeManager>>, PyCallback_SelectMgr_SelectingVolumeManager, SelectBasics_SelectingVolumeManager> cls_SelectMgr_SelectingVolumeManager(mod, "SelectMgr_SelectingVolumeManager", "This class is used to switch between active selecting volumes depending on selection type chosen by the user");
	cls_SelectMgr_SelectingVolumeManager.def(py::init<>());
	cls_SelectMgr_SelectingVolumeManager.def(py::init<Standard_Boolean>(), py::arg("theToAllocateFrustums"));
	cls_SelectMgr_SelectingVolumeManager.def("ScaleAndTransform", [](SelectMgr_SelectingVolumeManager &self, const Standard_Integer a0, const gp_GTrsf & a1) -> SelectMgr_SelectingVolumeManager { return self.ScaleAndTransform(a0, a1); }, py::arg("theScaleFactor"), py::arg("theTrsf"));
	cls_SelectMgr_SelectingVolumeManager.def("ScaleAndTransform", (SelectMgr_SelectingVolumeManager (SelectMgr_SelectingVolumeManager::*)(const Standard_Integer, const gp_GTrsf &, const opencascade::handle<SelectMgr_FrustumBuilder> &) const ) &SelectMgr_SelectingVolumeManager::ScaleAndTransform, "IMPORTANT: Scaling makes sense only for frustum built on a single point! Note that this method does not perform any checks on type of the frustum.", py::arg("theScaleFactor"), py::arg("theTrsf"), py::arg("theBuilder"));
	cls_SelectMgr_SelectingVolumeManager.def("GetActiveSelectionType", (Standard_Integer (SelectMgr_SelectingVolumeManager::*)() const ) &SelectMgr_SelectingVolumeManager::GetActiveSelectionType, "None");
	cls_SelectMgr_SelectingVolumeManager.def("SetActiveSelectionType", (void (SelectMgr_SelectingVolumeManager::*)(const SelectBasics_SelectingVolumeManager::SelectionType &)) &SelectMgr_SelectingVolumeManager::SetActiveSelectionType, "None", py::arg("theType"));
	cls_SelectMgr_SelectingVolumeManager.def("Camera", (const opencascade::handle<Graphic3d_Camera> & (SelectMgr_SelectingVolumeManager::*)() const ) &SelectMgr_SelectingVolumeManager::Camera, "Returns current camera definition.");
	cls_SelectMgr_SelectingVolumeManager.def("SetCamera", (void (SelectMgr_SelectingVolumeManager::*)(const opencascade::handle<Graphic3d_Camera>)) &SelectMgr_SelectingVolumeManager::SetCamera, "Updates camera projection and orientation matrices in all selecting volumes", py::arg("theCamera"));
	cls_SelectMgr_SelectingVolumeManager.def("SetCamera", [](SelectMgr_SelectingVolumeManager &self, const Graphic3d_Mat4d & a0, const Graphic3d_Mat4d & a1, const Standard_Boolean a2) -> void { return self.SetCamera(a0, a1, a2); }, py::arg("theProjection"), py::arg("theWorldView"), py::arg("theIsOrthographic"));
	cls_SelectMgr_SelectingVolumeManager.def("SetCamera", (void (SelectMgr_SelectingVolumeManager::*)(const Graphic3d_Mat4d &, const Graphic3d_Mat4d &, const Standard_Boolean, const Graphic3d_WorldViewProjState &)) &SelectMgr_SelectingVolumeManager::SetCamera, "Updates camera projection and orientation matrices in all selecting volumes", py::arg("theProjection"), py::arg("theWorldView"), py::arg("theIsOrthographic"), py::arg("theWVPState"));
	cls_SelectMgr_SelectingVolumeManager.def("ProjectionMatrix", (const Graphic3d_Mat4d & (SelectMgr_SelectingVolumeManager::*)() const ) &SelectMgr_SelectingVolumeManager::ProjectionMatrix, "Returns current projection transformation common for all selecting volumes");
	cls_SelectMgr_SelectingVolumeManager.def("WorldViewMatrix", (const Graphic3d_Mat4d & (SelectMgr_SelectingVolumeManager::*)() const ) &SelectMgr_SelectingVolumeManager::WorldViewMatrix, "Returns current world view transformation common for all selecting volumes");
	cls_SelectMgr_SelectingVolumeManager.def("WindowSize", [](SelectMgr_SelectingVolumeManager &self, Standard_Integer & theWidth, Standard_Integer & theHeight){ self.WindowSize(theWidth, theHeight); return std::tuple<Standard_Integer &, Standard_Integer &>(theWidth, theHeight); }, "None", py::arg("theWidth"), py::arg("theHeight"));
	cls_SelectMgr_SelectingVolumeManager.def("WorldViewProjState", (const Graphic3d_WorldViewProjState & (SelectMgr_SelectingVolumeManager::*)() const ) &SelectMgr_SelectingVolumeManager::WorldViewProjState, "Returns current camera world view projection transformation state common for all selecting volumes");
	cls_SelectMgr_SelectingVolumeManager.def("SetViewport", (void (SelectMgr_SelectingVolumeManager::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &SelectMgr_SelectingVolumeManager::SetViewport, "Updates viewport in all selecting volumes", py::arg("theX"), py::arg("theY"), py::arg("theWidth"), py::arg("theHeight"));
	cls_SelectMgr_SelectingVolumeManager.def("SetPixelTolerance", (void (SelectMgr_SelectingVolumeManager::*)(const Standard_Integer)) &SelectMgr_SelectingVolumeManager::SetPixelTolerance, "Updates pixel tolerance in all selecting volumes", py::arg("theTolerance"));
	cls_SelectMgr_SelectingVolumeManager.def("SetWindowSize", (void (SelectMgr_SelectingVolumeManager::*)(const Standard_Integer, const Standard_Integer)) &SelectMgr_SelectingVolumeManager::SetWindowSize, "Updates window size in all selecting volumes", py::arg("theWidth"), py::arg("theHeight"));
	cls_SelectMgr_SelectingVolumeManager.def("BuildSelectingVolume", (void (SelectMgr_SelectingVolumeManager::*)(const gp_Pnt2d &)) &SelectMgr_SelectingVolumeManager::BuildSelectingVolume, "Builds rectangular selecting frustum for point selection", py::arg("thePoint"));
	cls_SelectMgr_SelectingVolumeManager.def("BuildSelectingVolume", (void (SelectMgr_SelectingVolumeManager::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &SelectMgr_SelectingVolumeManager::BuildSelectingVolume, "Builds rectangular selecting frustum for box selection", py::arg("theMinPt"), py::arg("theMaxPt"));
	cls_SelectMgr_SelectingVolumeManager.def("BuildSelectingVolume", (void (SelectMgr_SelectingVolumeManager::*)(const TColgp_Array1OfPnt2d &)) &SelectMgr_SelectingVolumeManager::BuildSelectingVolume, "Builds set of triangular selecting frustums for polyline selection", py::arg("thePoints"));
	cls_SelectMgr_SelectingVolumeManager.def("Overlaps", [](SelectMgr_SelectingVolumeManager &self, const SelectMgr_Vec3 & theBoxMin, const SelectMgr_Vec3 & theBoxMax, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(theBoxMin, theBoxMax, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "SAT intersection test between defined volume and given axis-aligned box", py::arg("theBoxMin"), py::arg("theBoxMax"), py::arg("theDepth"));
	cls_SelectMgr_SelectingVolumeManager.def("Overlaps", [](SelectMgr_SelectingVolumeManager &self, const SelectMgr_Vec3 & theBoxMin, const SelectMgr_Vec3 & theBoxMax, Standard_Boolean * theInside){ Standard_Boolean rv = self.Overlaps(theBoxMin, theBoxMax, theInside); return std::tuple<Standard_Boolean, Standard_Boolean *>(rv, theInside); }, "Returns true if selecting volume is overlapped by axis-aligned bounding box with minimum corner at point theMinPt and maximum at point theMaxPt", py::arg("theBoxMin"), py::arg("theBoxMax"), py::arg("theInside"));
	cls_SelectMgr_SelectingVolumeManager.def("Overlaps", [](SelectMgr_SelectingVolumeManager &self, const gp_Pnt & thePnt, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "Intersection test between defined volume and given point", py::arg("thePnt"), py::arg("theDepth"));
	cls_SelectMgr_SelectingVolumeManager.def("Overlaps", (Standard_Boolean (SelectMgr_SelectingVolumeManager::*)(const gp_Pnt &)) &SelectMgr_SelectingVolumeManager::Overlaps, "Intersection test between defined volume and given point", py::arg("thePnt"));
	cls_SelectMgr_SelectingVolumeManager.def("Overlaps", [](SelectMgr_SelectingVolumeManager &self, const opencascade::handle<TColgp_HArray1OfPnt> & theArrayOfPts, Standard_Integer theSensType, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(theArrayOfPts, theSensType, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "SAT intersection test between defined volume and given ordered set of points, representing line segments. The test may be considered of interior part or boundary line defined by segments depending on given sensitivity type", py::arg("theArrayOfPts"), py::arg("theSensType"), py::arg("theDepth"));
	cls_SelectMgr_SelectingVolumeManager.def("Overlaps", [](SelectMgr_SelectingVolumeManager &self, const TColgp_Array1OfPnt & theArrayOfPts, Standard_Integer theSensType, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(theArrayOfPts, theSensType, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "SAT intersection test between defined volume and given ordered set of points, representing line segments. The test may be considered of interior part or boundary line defined by segments depending on given sensitivity type", py::arg("theArrayOfPts"), py::arg("theSensType"), py::arg("theDepth"));
	cls_SelectMgr_SelectingVolumeManager.def("Overlaps", [](SelectMgr_SelectingVolumeManager &self, const gp_Pnt & thePnt1, const gp_Pnt & thePnt2, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt1, thePnt2, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "Checks if line segment overlaps selecting frustum", py::arg("thePnt1"), py::arg("thePnt2"), py::arg("theDepth"));
	cls_SelectMgr_SelectingVolumeManager.def("Overlaps", [](SelectMgr_SelectingVolumeManager &self, const gp_Pnt & thePnt1, const gp_Pnt & thePnt2, const gp_Pnt & thePnt3, Standard_Integer theSensType, Standard_Real & theDepth){ Standard_Boolean rv = self.Overlaps(thePnt1, thePnt2, thePnt3, theSensType, theDepth); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theDepth); }, "SAT intersection test between defined volume and given triangle. The test may be considered of interior part or boundary line defined by triangle vertices depending on given sensitivity type", py::arg("thePnt1"), py::arg("thePnt2"), py::arg("thePnt3"), py::arg("theSensType"), py::arg("theDepth"));
	cls_SelectMgr_SelectingVolumeManager.def("DistToGeometryCenter", (Standard_Real (SelectMgr_SelectingVolumeManager::*)(const gp_Pnt &)) &SelectMgr_SelectingVolumeManager::DistToGeometryCenter, "Measures distance between 3d projection of user-picked screen point and given point theCOG", py::arg("theCOG"));
	cls_SelectMgr_SelectingVolumeManager.def("DetectedPoint", (gp_Pnt (SelectMgr_SelectingVolumeManager::*)(const Standard_Real) const ) &SelectMgr_SelectingVolumeManager::DetectedPoint, "Calculates the point on a view ray that was detected during the run of selection algo by given depth. Throws exception if active selection type is not Point.", py::arg("theDepth"));
	cls_SelectMgr_SelectingVolumeManager.def("IsClipped", (Standard_Boolean (SelectMgr_SelectingVolumeManager::*)(const Graphic3d_SequenceOfHClipPlane &, const Standard_Real &)) &SelectMgr_SelectingVolumeManager::IsClipped, "Checks if the point of sensitive in which selection was detected belongs to the region defined by clipping planes", py::arg("thePlanes"), py::arg("theDepth"));
	cls_SelectMgr_SelectingVolumeManager.def("AllowOverlapDetection", (void (SelectMgr_SelectingVolumeManager::*)(const Standard_Boolean)) &SelectMgr_SelectingVolumeManager::AllowOverlapDetection, "Is used for rectangular selection only If theIsToAllow is false, only fully included sensitives will be detected, otherwise the algorithm will mark both included and overlapped entities as matched", py::arg("theIsToAllow"));
	cls_SelectMgr_SelectingVolumeManager.def("IsOverlapAllowed", (Standard_Boolean (SelectMgr_SelectingVolumeManager::*)() const ) &SelectMgr_SelectingVolumeManager::IsOverlapAllowed, "None");
	cls_SelectMgr_SelectingVolumeManager.def("ViewClipping", (const opencascade::handle<Graphic3d_SequenceOfHClipPlane> & (SelectMgr_SelectingVolumeManager::*)() const ) &SelectMgr_SelectingVolumeManager::ViewClipping, "Return view clipping planes.");
	cls_SelectMgr_SelectingVolumeManager.def("SetViewClipping", (void (SelectMgr_SelectingVolumeManager::*)(const opencascade::handle<Graphic3d_SequenceOfHClipPlane> &)) &SelectMgr_SelectingVolumeManager::SetViewClipping, "Valid for point selection only! Computes depth range for global (defined for the whole view) clipping planes.", py::arg("thePlanes"));
	cls_SelectMgr_SelectingVolumeManager.def("SetViewClippingEnabled", (Standard_Boolean (SelectMgr_SelectingVolumeManager::*)(const Standard_Boolean)) &SelectMgr_SelectingVolumeManager::SetViewClippingEnabled, "Set if view clipping plane is enabled or not.", py::arg("theToEnable"));
	cls_SelectMgr_SelectingVolumeManager.def("GetVertices", (const gp_Pnt * (SelectMgr_SelectingVolumeManager::*)() const ) &SelectMgr_SelectingVolumeManager::GetVertices, "A set of helper functions that return rectangular selecting frustum data");
	cls_SelectMgr_SelectingVolumeManager.def("GetNearPickedPnt", (gp_Pnt (SelectMgr_SelectingVolumeManager::*)() const ) &SelectMgr_SelectingVolumeManager::GetNearPickedPnt, "Valid only for point and rectangular selection. Returns projection of 2d mouse picked point or projection of center of 2d rectangle (for point and rectangular selection correspondingly) onto near view frustum plane");
	cls_SelectMgr_SelectingVolumeManager.def("GetFarPickedPnt", (gp_Pnt (SelectMgr_SelectingVolumeManager::*)() const ) &SelectMgr_SelectingVolumeManager::GetFarPickedPnt, "Valid only for point and rectangular selection. Returns projection of 2d mouse picked point or projection of center of 2d rectangle (for point and rectangular selection correspondingly) onto far view frustum plane");
	cls_SelectMgr_SelectingVolumeManager.def("ActiveVolume", (opencascade::handle<SelectMgr_BaseFrustum> (SelectMgr_SelectingVolumeManager::*)() const ) &SelectMgr_SelectingVolumeManager::ActiveVolume, "Returns active selecting volume that was built during last run of OCCT selection mechanism");
	cls_SelectMgr_SelectingVolumeManager.def("GetPlanes", (void (SelectMgr_SelectingVolumeManager::*)(NCollection_Vector<SelectMgr_Vec4> &) const ) &SelectMgr_SelectingVolumeManager::GetPlanes, "Stores plane equation coefficients (in the following form: Ax + By + Cz + D = 0) to the given vector", py::arg("thePlaneEquations"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_SelectableObjectSet.hxx
	py::class_<SelectMgr_SelectableObjectSet, std::unique_ptr<SelectMgr_SelectableObjectSet, Deleter<SelectMgr_SelectableObjectSet>>> cls_SelectMgr_SelectableObjectSet(mod, "SelectMgr_SelectableObjectSet", "The purpose of this class is to organize all selectable objects into data structure, allowing to build set of BVH trees for each transformation persistence subclass of selectable objects. This allow to minify number of updates for BVH trees - for example 2D persistent object subclass depends only on camera's projection and the corresponding BVH tree needs to be updated when camera's projection parameters change, while another tree for non-persistent objects can be left unchanged in this case.");
	cls_SelectMgr_SelectableObjectSet.def(py::init<>());
	cls_SelectMgr_SelectableObjectSet.def("Append", (Standard_Boolean (SelectMgr_SelectableObjectSet::*)(const opencascade::handle<SelectMgr_SelectableObject> &)) &SelectMgr_SelectableObjectSet::Append, "Adds the new selectable object to the set. The selectable object is placed into one of the predefined subsets depending on its persistence type. After adding an object, this method marks the corresponding BVH tree for rebuild.", py::arg("theObject"));
	cls_SelectMgr_SelectableObjectSet.def("Remove", (Standard_Boolean (SelectMgr_SelectableObjectSet::*)(const opencascade::handle<SelectMgr_SelectableObject> &)) &SelectMgr_SelectableObjectSet::Remove, "Removes the selectable object from the set. The selectable object is removed from the subset it has been placed into. After removing an object, this method marks the corresponding BVH tree for rebuild.", py::arg("theObject"));
	cls_SelectMgr_SelectableObjectSet.def("ChangeSubset", (void (SelectMgr_SelectableObjectSet::*)(const opencascade::handle<SelectMgr_SelectableObject> &)) &SelectMgr_SelectableObjectSet::ChangeSubset, "Performs necessary updates when object's persistence types changes. This method should be called right after changing transformation persistence flags of the objects and before updating BVH tree - to provide up-to-date state of the object set.", py::arg("theObject"));
	cls_SelectMgr_SelectableObjectSet.def("UpdateBVH", (void (SelectMgr_SelectableObjectSet::*)(const opencascade::handle<Graphic3d_Camera> &, const Graphic3d_Mat4d &, const Graphic3d_Mat4d &, const Graphic3d_WorldViewProjState &, const Standard_Integer, const Standard_Integer)) &SelectMgr_SelectableObjectSet::UpdateBVH, "Updates outdated BVH trees and remembers the last state of the camera view-projection matrices and viewport (window) dimensions.", py::arg("theCamera"), py::arg("theProjectionMat"), py::arg("theWorldViewMat"), py::arg("theViewState"), py::arg("theViewportWidth"), py::arg("theViewportHeight"));
	cls_SelectMgr_SelectableObjectSet.def("MarkDirty", (void (SelectMgr_SelectableObjectSet::*)()) &SelectMgr_SelectableObjectSet::MarkDirty, "Marks every BVH subset for update.");
	cls_SelectMgr_SelectableObjectSet.def("Contains", (Standard_Boolean (SelectMgr_SelectableObjectSet::*)(const opencascade::handle<SelectMgr_SelectableObject> &) const ) &SelectMgr_SelectableObjectSet::Contains, "Returns true if this objects set contains theObject given.", py::arg("theObject"));
	cls_SelectMgr_SelectableObjectSet.def("IsEmpty", (Standard_Boolean (SelectMgr_SelectableObjectSet::*)() const ) &SelectMgr_SelectableObjectSet::IsEmpty, "Returns true if the object set does not contain any selectable objects.");
	cls_SelectMgr_SelectableObjectSet.def("IsEmpty", (Standard_Boolean (SelectMgr_SelectableObjectSet::*)(const SelectMgr_SelectableObjectSet::BVHSubset) const ) &SelectMgr_SelectableObjectSet::IsEmpty, "Returns true if the specified object subset is empty.", py::arg("theSubset"));
	cls_SelectMgr_SelectableObjectSet.def("GetObjectById", (const opencascade::handle<SelectMgr_SelectableObject> & (SelectMgr_SelectableObjectSet::*)(const SelectMgr_SelectableObjectSet::BVHSubset, const Standard_Integer) const ) &SelectMgr_SelectableObjectSet::GetObjectById, "Returns object from subset theSubset by theIndex given. The method allows to get selectable object referred by the index of an element of the subset's BVH tree.", py::arg("theSubset"), py::arg("theIndex"));
	cls_SelectMgr_SelectableObjectSet.def("BVH", (const opencascade::handle<BVH_Tree<Standard_Real, 3> > & (SelectMgr_SelectableObjectSet::*)(const SelectMgr_SelectableObjectSet::BVHSubset) const ) &SelectMgr_SelectableObjectSet::BVH, "Returns computed BVH for the theSubset given.", py::arg("theSubset"));
	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_SelectableObjectSet.hxx
	py::enum_<SelectMgr_SelectableObjectSet::BVHSubset>(cls_SelectMgr_SelectableObjectSet, "BVHSubset", "This enumeration declares names for subsets of selectable objects. Each subset has independent BVH tree. The class maintains subsets of selectable objects by their persistence flag. This allows to restric rebuilding of the trees for particular subset when the camera change does not implicitly require it: - BVHSubset_3d refers to the subset of normal world-space 3D objects. Associated BVH tree does not depend on the camera's state at all. This subset uses binned BVH builder with 32 bins and 1 element per leaf. - BVHSubset_3dPersistent refers to the subset of 3D persistent selectable objects (rotate, pan, zoom persistence). Associated BVH tree needs to be updated when either the camera's projection and position change. This subset uses linear BVH builder with 32 levels of depth and 1 element per leaf. - BVHSubset_2dPersistent refers to the subset of 2D persistent selectable objects. Associated BVH tree needs to be updated only when camera's projection changes. Bounding volumes for this object subclass is represented directly in eye space coordinates. This subset uses linear BVH builder with 32 levels of depth and 1 element per leaf.")
		.value("BVHSubset_3d", SelectMgr_SelectableObjectSet::BVHSubset::BVHSubset_3d)
		.value("BVHSubset_3dPersistent", SelectMgr_SelectableObjectSet::BVHSubset::BVHSubset_3dPersistent)
		.value("BVHSubset_2dPersistent", SelectMgr_SelectableObjectSet::BVHSubset::BVHSubset_2dPersistent)
		.value("BVHSubsetNb", SelectMgr_SelectableObjectSet::BVHSubset::BVHSubsetNb)
		.export_values();

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_ToleranceMap.hxx
	py::class_<SelectMgr_ToleranceMap, std::unique_ptr<SelectMgr_ToleranceMap, Deleter<SelectMgr_ToleranceMap>>> cls_SelectMgr_ToleranceMap(mod, "SelectMgr_ToleranceMap", "An internal class for calculation of current largest tolerance value which will be applied for creation of selecting frustum by default. Each time the selection set is deactivated, maximum tolerance value will be recalculated. If a user enables custom precision using StdSelect_ViewerSelector3d::SetPixelTolerance, it will be applied to all sensitive entities without any checks.");
	cls_SelectMgr_ToleranceMap.def(py::init<>());
	cls_SelectMgr_ToleranceMap.def("Add", (void (SelectMgr_ToleranceMap::*)(const Standard_Integer &)) &SelectMgr_ToleranceMap::Add, "Adds the value given to map, checks if the current tolerance value should be replaced by theTolerance", py::arg("theTolerance"));
	cls_SelectMgr_ToleranceMap.def("Decrement", (void (SelectMgr_ToleranceMap::*)(const Standard_Integer &)) &SelectMgr_ToleranceMap::Decrement, "Decrements a counter of the tolerance given, checks if the current tolerance value should be recalculated", py::arg("theTolerance"));
	cls_SelectMgr_ToleranceMap.def("Tolerance", (Standard_Integer (SelectMgr_ToleranceMap::*)() const ) &SelectMgr_ToleranceMap::Tolerance, "Returns a current tolerance that must be applied");
	cls_SelectMgr_ToleranceMap.def("SetCustomTolerance", (void (SelectMgr_ToleranceMap::*)(const Standard_Integer)) &SelectMgr_ToleranceMap::SetCustomTolerance, "Sets tolerance to the given one and disables adaptive checks", py::arg("theTolerance"));
	cls_SelectMgr_ToleranceMap.def("ResetDefaults", (void (SelectMgr_ToleranceMap::*)()) &SelectMgr_ToleranceMap::ResetDefaults, "Unsets a custom tolerance and enables adaptive checks");
	cls_SelectMgr_ToleranceMap.def("CustomTolerance", (Standard_Integer (SelectMgr_ToleranceMap::*)() const ) &SelectMgr_ToleranceMap::CustomTolerance, "Returns the value of custom tolerance regardless of it validity");
	cls_SelectMgr_ToleranceMap.def("IsCustomTolSet", (Standard_Boolean (SelectMgr_ToleranceMap::*)() const ) &SelectMgr_ToleranceMap::IsCustomTolSet, "Returns true if custom tolerance value is greater than zero");

	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_SensitiveEntitySet.hxx
	py::class_<SelectMgr_SensitiveEntitySet, std::unique_ptr<SelectMgr_SensitiveEntitySet, Deleter<SelectMgr_SensitiveEntitySet>>, BVH_PrimitiveSet3d> cls_SelectMgr_SensitiveEntitySet(mod, "SelectMgr_SensitiveEntitySet", "This class is used to store all calculated sensitive entites of one selectable object. It provides an interface for building BVH tree which is used to speed-up the performance of searching for overlap among sensitives of one selectable object");
	cls_SelectMgr_SensitiveEntitySet.def(py::init<const opencascade::handle<Select3D_BVHBuilder3d> &>(), py::arg("theBuilder"));
	cls_SelectMgr_SensitiveEntitySet.def_static("get_type_name_", (const char * (*)()) &SelectMgr_SensitiveEntitySet::get_type_name, "None");
	cls_SelectMgr_SensitiveEntitySet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_SensitiveEntitySet::get_type_descriptor, "None");
	cls_SelectMgr_SensitiveEntitySet.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_SensitiveEntitySet::*)() const ) &SelectMgr_SensitiveEntitySet::DynamicType, "None");
	cls_SelectMgr_SensitiveEntitySet.def("Append", (void (SelectMgr_SensitiveEntitySet::*)(const opencascade::handle<SelectMgr_SensitiveEntity> &)) &SelectMgr_SensitiveEntitySet::Append, "Adds new entity to the set and marks BVH tree for rebuild", py::arg("theEntity"));
	cls_SelectMgr_SensitiveEntitySet.def("Append", (void (SelectMgr_SensitiveEntitySet::*)(const opencascade::handle<SelectMgr_Selection> &)) &SelectMgr_SensitiveEntitySet::Append, "Adds every entity of selection theSelection to the set and marks BVH tree for rebuild", py::arg("theSelection"));
	cls_SelectMgr_SensitiveEntitySet.def("Remove", (void (SelectMgr_SensitiveEntitySet::*)(const opencascade::handle<SelectMgr_Selection> &)) &SelectMgr_SensitiveEntitySet::Remove, "Removes every entity of selection theSelection from the set and marks BVH tree for rebuild", py::arg("theSelection"));
	cls_SelectMgr_SensitiveEntitySet.def("Box", (Select3D_BndBox3d (SelectMgr_SensitiveEntitySet::*)(const Standard_Integer) const ) &SelectMgr_SensitiveEntitySet::Box, "Returns bounding box of entity with index theIdx", py::arg("theIndex"));
	cls_SelectMgr_SensitiveEntitySet.def("Center", (Standard_Real (SelectMgr_SensitiveEntitySet::*)(const Standard_Integer, const Standard_Integer) const ) &SelectMgr_SensitiveEntitySet::Center, "Returns geometry center of sensitive entity index theIdx along the given axis theAxis", py::arg("theIndex"), py::arg("theAxis"));
	cls_SelectMgr_SensitiveEntitySet.def("Swap", (void (SelectMgr_SensitiveEntitySet::*)(const Standard_Integer, const Standard_Integer)) &SelectMgr_SensitiveEntitySet::Swap, "Swaps items with indexes theIdx1 and theIdx2", py::arg("theIndex1"), py::arg("theIndex2"));
	cls_SelectMgr_SensitiveEntitySet.def("Size", (Standard_Integer (SelectMgr_SensitiveEntitySet::*)() const ) &SelectMgr_SensitiveEntitySet::Size, "Returns the amount of entities");
	cls_SelectMgr_SensitiveEntitySet.def("GetSensitiveById", (const opencascade::handle<SelectMgr_SensitiveEntity> & (SelectMgr_SensitiveEntitySet::*)(const Standard_Integer) const ) &SelectMgr_SensitiveEntitySet::GetSensitiveById, "Returns the entity with index theIndex in the set", py::arg("theIndex"));
	cls_SelectMgr_SensitiveEntitySet.def("Box", (BVH_Box<double, 3> (SelectMgr_SensitiveEntitySet::*)() const ) &SelectMgr_SensitiveEntitySet::Box, "Returns AABB of primitive set.");
	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_ViewerSelector.hxx
	py::class_<SelectMgr_ViewerSelector, opencascade::handle<SelectMgr_ViewerSelector>, Standard_Transient> cls_SelectMgr_ViewerSelector(mod, "SelectMgr_ViewerSelector", "A framework to define finding, sorting the sensitive primitives in a view. Services are also provided to define the return of the owners of those primitives selected. The primitives are sorted by criteria such as priority of the primitive or its depth in the view relative to that of other primitives. Note that in 3D, the inheriting framework StdSelect_ViewerSelector3d is only to be used if you do not want to use the services provided by AIS. Two tools are available to find and select objects found at a given position in the view. If you want to select the owners of all the objects detected at point x,y,z you use the Init - More - Next - Picked loop. If, on the other hand, you want to select only one object detected at that point, you use the Init - More - OnePicked loop. In this iteration, More is used to see if an object was picked and OnePicked, to get the object closest to the pick position. Viewer selectors are driven by SelectMgr_SelectionManager, and manipulate the SelectMgr_Selection objects given to them by the selection manager.");
	cls_SelectMgr_ViewerSelector.def_static("get_type_name_", (const char * (*)()) &SelectMgr_ViewerSelector::get_type_name, "None");
	cls_SelectMgr_ViewerSelector.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_ViewerSelector::get_type_descriptor, "None");
	cls_SelectMgr_ViewerSelector.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_ViewerSelector::*)() const ) &SelectMgr_ViewerSelector::DynamicType, "None");
	cls_SelectMgr_ViewerSelector.def("Clear", (void (SelectMgr_ViewerSelector::*)()) &SelectMgr_ViewerSelector::Clear, "Empties all the tables, removes all selections...");
	cls_SelectMgr_ViewerSelector.def("Sensitivity", (Standard_Real (SelectMgr_ViewerSelector::*)() const ) &SelectMgr_ViewerSelector::Sensitivity, "returns the Sensitivity of picking");
	cls_SelectMgr_ViewerSelector.def("SortResult", (void (SelectMgr_ViewerSelector::*)()) &SelectMgr_ViewerSelector::SortResult, "Sorts the detected entites by priority and distance. to be redefined if other criterion are used...");
	cls_SelectMgr_ViewerSelector.def("OnePicked", (opencascade::handle<SelectMgr_EntityOwner> (SelectMgr_ViewerSelector::*)() const ) &SelectMgr_ViewerSelector::OnePicked, "Returns the picked element with the highest priority, and which is the closest to the last successful mouse position.");
	cls_SelectMgr_ViewerSelector.def("SetPickClosest", (void (SelectMgr_ViewerSelector::*)(const Standard_Boolean)) &SelectMgr_ViewerSelector::SetPickClosest, "Set preference of selecting one object for OnePicked() method: - If True, objects with less depth (distance fron the view plane) are preferred regardless of priority (priority is used then to choose among objects with similar depth), - If False, objects with higher priority are preferred regardless of the depth which is used to choose among objects of the same priority.", py::arg("theToPreferClosest"));
	cls_SelectMgr_ViewerSelector.def("NbPicked", (Standard_Integer (SelectMgr_ViewerSelector::*)() const ) &SelectMgr_ViewerSelector::NbPicked, "Returns the number of detected owners.");
	cls_SelectMgr_ViewerSelector.def("Picked", (opencascade::handle<SelectMgr_EntityOwner> (SelectMgr_ViewerSelector::*)(const Standard_Integer) const ) &SelectMgr_ViewerSelector::Picked, "Returns the entity Owner for the object picked at specified position.", py::arg("theRank"));
	cls_SelectMgr_ViewerSelector.def("PickedData", (const SelectMgr_SortCriterion & (SelectMgr_ViewerSelector::*)(const Standard_Integer) const ) &SelectMgr_ViewerSelector::PickedData, "Returns the Entity for the object picked at specified position.", py::arg("theRank"));
	cls_SelectMgr_ViewerSelector.def("PickedEntity", (const opencascade::handle<SelectBasics_SensitiveEntity> & (SelectMgr_ViewerSelector::*)(const Standard_Integer) const ) &SelectMgr_ViewerSelector::PickedEntity, "Returns the Entity for the object picked at specified position.", py::arg("theRank"));
	cls_SelectMgr_ViewerSelector.def("PickedPoint", (gp_Pnt (SelectMgr_ViewerSelector::*)(const Standard_Integer) const ) &SelectMgr_ViewerSelector::PickedPoint, "Returns the 3D point (intersection of picking axis with the object nearest to eye) for the object picked at specified position.", py::arg("theRank"));
	cls_SelectMgr_ViewerSelector.def("Contains", (Standard_Boolean (SelectMgr_ViewerSelector::*)(const opencascade::handle<SelectMgr_SelectableObject> &) const ) &SelectMgr_ViewerSelector::Contains, "None", py::arg("theObject"));
	cls_SelectMgr_ViewerSelector.def("EntitySetBuilder", (const opencascade::handle<Select3D_BVHBuilder3d> (SelectMgr_ViewerSelector::*)()) &SelectMgr_ViewerSelector::EntitySetBuilder, "Returns the default builder used to construct BVH of entity set.");
	cls_SelectMgr_ViewerSelector.def("SetEntitySetBuilder", (void (SelectMgr_ViewerSelector::*)(const opencascade::handle<Select3D_BVHBuilder3d> &)) &SelectMgr_ViewerSelector::SetEntitySetBuilder, "Sets the default builder used to construct BVH of entity set. The new builder will be also assigned for already defined objects, but computed BVH trees will not be invalidated.", py::arg("theBuilder"));
	cls_SelectMgr_ViewerSelector.def("Modes", [](SelectMgr_ViewerSelector &self, const opencascade::handle<SelectMgr_SelectableObject> & a0, TColStd_ListOfInteger & a1) -> Standard_Boolean { return self.Modes(a0, a1); }, py::arg("theSelectableObject"), py::arg("theModeList"));
	cls_SelectMgr_ViewerSelector.def("Modes", (Standard_Boolean (SelectMgr_ViewerSelector::*)(const opencascade::handle<SelectMgr_SelectableObject> &, TColStd_ListOfInteger &, const SelectMgr_StateOfSelection) const ) &SelectMgr_ViewerSelector::Modes, "Returns the list of selection modes ModeList found in this selector for the selectable object aSelectableObject. Returns true if aSelectableObject is referenced inside this selector; returns false if the object is not present in this selector.", py::arg("theSelectableObject"), py::arg("theModeList"), py::arg("theWantedState"));
	cls_SelectMgr_ViewerSelector.def("IsActive", (Standard_Boolean (SelectMgr_ViewerSelector::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer) const ) &SelectMgr_ViewerSelector::IsActive, "Returns true if the selectable object aSelectableObject having the selection mode aMode is active in this selector.", py::arg("theSelectableObject"), py::arg("theMode"));
	cls_SelectMgr_ViewerSelector.def("IsInside", (Standard_Boolean (SelectMgr_ViewerSelector::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Integer) const ) &SelectMgr_ViewerSelector::IsInside, "Returns true if the selectable object aSelectableObject having the selection mode aMode is in this selector.", py::arg("theSelectableObject"), py::arg("theMode"));
	cls_SelectMgr_ViewerSelector.def("Status", (SelectMgr_StateOfSelection (SelectMgr_ViewerSelector::*)(const opencascade::handle<SelectMgr_Selection> &) const ) &SelectMgr_ViewerSelector::Status, "Returns the selection status Status of the selection aSelection.", py::arg("theSelection"));
	cls_SelectMgr_ViewerSelector.def("Status", (TCollection_AsciiString (SelectMgr_ViewerSelector::*)(const opencascade::handle<SelectMgr_SelectableObject> &) const ) &SelectMgr_ViewerSelector::Status, "None", py::arg("theSelectableObject"));
	cls_SelectMgr_ViewerSelector.def("ActiveOwners", (void (SelectMgr_ViewerSelector::*)(NCollection_List<opencascade::handle<SelectBasics_EntityOwner> > &) const ) &SelectMgr_ViewerSelector::ActiveOwners, "Returns the list of active entity owners", py::arg("theOwners"));
	cls_SelectMgr_ViewerSelector.def("AddSelectableObject", (void (SelectMgr_ViewerSelector::*)(const opencascade::handle<SelectMgr_SelectableObject> &)) &SelectMgr_ViewerSelector::AddSelectableObject, "Adds new object to the map of selectable objects", py::arg("theObject"));
	cls_SelectMgr_ViewerSelector.def("AddSelectionToObject", (void (SelectMgr_ViewerSelector::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const opencascade::handle<SelectMgr_Selection> &)) &SelectMgr_ViewerSelector::AddSelectionToObject, "Adds new selection to the object and builds its BVH tree", py::arg("theObject"), py::arg("theSelection"));
	cls_SelectMgr_ViewerSelector.def("MoveSelectableObject", (void (SelectMgr_ViewerSelector::*)(const opencascade::handle<SelectMgr_SelectableObject> &)) &SelectMgr_ViewerSelector::MoveSelectableObject, "Moves existing object from set of not transform persistence objects to set of transform persistence objects (or vice versa).", py::arg("theObject"));
	cls_SelectMgr_ViewerSelector.def("RemoveSelectableObject", (void (SelectMgr_ViewerSelector::*)(const opencascade::handle<SelectMgr_SelectableObject> &)) &SelectMgr_ViewerSelector::RemoveSelectableObject, "Removes selectable object from map of selectable ones", py::arg("theObject"));
	cls_SelectMgr_ViewerSelector.def("RemoveSelectionOfObject", (void (SelectMgr_ViewerSelector::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const opencascade::handle<SelectMgr_Selection> &)) &SelectMgr_ViewerSelector::RemoveSelectionOfObject, "Removes selection of the object and marks its BVH tree for rebuild", py::arg("theObject"), py::arg("theSelection"));
	cls_SelectMgr_ViewerSelector.def("RebuildObjectsTree", [](SelectMgr_ViewerSelector &self) -> void { return self.RebuildObjectsTree(); });
	cls_SelectMgr_ViewerSelector.def("RebuildObjectsTree", (void (SelectMgr_ViewerSelector::*)(const Standard_Boolean)) &SelectMgr_ViewerSelector::RebuildObjectsTree, "Marks BVH of selectable objects for rebuild. Parameter theIsForce set as true guarantees that 1st level BVH for the viewer selector will be rebuilt during this call", py::arg("theIsForce"));
	cls_SelectMgr_ViewerSelector.def("RebuildSensitivesTree", [](SelectMgr_ViewerSelector &self, const opencascade::handle<SelectMgr_SelectableObject> & a0) -> void { return self.RebuildSensitivesTree(a0); }, py::arg("theObject"));
	cls_SelectMgr_ViewerSelector.def("RebuildSensitivesTree", (void (SelectMgr_ViewerSelector::*)(const opencascade::handle<SelectMgr_SelectableObject> &, const Standard_Boolean)) &SelectMgr_ViewerSelector::RebuildSensitivesTree, "Marks BVH of sensitive entities of particular selectable object for rebuild. Parameter theIsForce set as true guarantees that 2nd level BVH for the object given will be rebuilt during this call", py::arg("theObject"), py::arg("theIsForce"));
	cls_SelectMgr_ViewerSelector.def("GetManager", (SelectMgr_SelectingVolumeManager & (SelectMgr_ViewerSelector::*)()) &SelectMgr_ViewerSelector::GetManager, "Returns instance of selecting volume manager of the viewer selector");
	cls_SelectMgr_ViewerSelector.def("ResetSelectionActivationStatus", (void (SelectMgr_ViewerSelector::*)()) &SelectMgr_ViewerSelector::ResetSelectionActivationStatus, "Marks all added sensitive entities of all objects as non-selectable");
	cls_SelectMgr_ViewerSelector.def("AllowOverlapDetection", (void (SelectMgr_ViewerSelector::*)(const Standard_Boolean)) &SelectMgr_ViewerSelector::AllowOverlapDetection, "Is used for rectangular selection only If theIsToAllow is false, only fully included sensitives will be detected, otherwise the algorithm will mark both included and overlapped entities as matched", py::arg("theIsToAllow"));
	cls_SelectMgr_ViewerSelector.def("Init", (void (SelectMgr_ViewerSelector::*)()) &SelectMgr_ViewerSelector::Init, "Begins an iteration scanning for the owners detected at a position in the view.");
	cls_SelectMgr_ViewerSelector.def("More", (Standard_Boolean (SelectMgr_ViewerSelector::*)()) &SelectMgr_ViewerSelector::More, "Continues the interation scanning for the owners detected at a position in the view, or continues the iteration scanning for the owner closest to the position in the view.");
	cls_SelectMgr_ViewerSelector.def("Next", (void (SelectMgr_ViewerSelector::*)()) &SelectMgr_ViewerSelector::Next, "Returns the next owner found in the iteration. This is a scan for the owners detected at a position in the view.");
	cls_SelectMgr_ViewerSelector.def("Picked", (opencascade::handle<SelectMgr_EntityOwner> (SelectMgr_ViewerSelector::*)() const ) &SelectMgr_ViewerSelector::Picked, "Returns the current selected entity detected by the selector;");
	cls_SelectMgr_ViewerSelector.def("InitDetected", (void (SelectMgr_ViewerSelector::*)()) &SelectMgr_ViewerSelector::InitDetected, "Initializes internal iterator for stored detected sensitive entities");
	cls_SelectMgr_ViewerSelector.def("NextDetected", (void (SelectMgr_ViewerSelector::*)()) &SelectMgr_ViewerSelector::NextDetected, "Makes a step along the map of detected sensitive entities and their owners");
	cls_SelectMgr_ViewerSelector.def("MoreDetected", (Standard_Boolean (SelectMgr_ViewerSelector::*)()) &SelectMgr_ViewerSelector::MoreDetected, "Returns true if iterator of map of detected sensitive entities has reached its end");
	cls_SelectMgr_ViewerSelector.def("DetectedEntity", (const opencascade::handle<SelectBasics_SensitiveEntity> & (SelectMgr_ViewerSelector::*)() const ) &SelectMgr_ViewerSelector::DetectedEntity, "Returns sensitive entity that was detected during the previous run of selection algorithm");

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_Filter.hxx
	py::class_<SelectMgr_Filter, opencascade::handle<SelectMgr_Filter>, Standard_Transient> cls_SelectMgr_Filter(mod, "SelectMgr_Filter", "The root class to define filter objects for selection. Advance handling of objects requires the services of filters. These only allow dynamic detection and selection of objects which correspond to the criteria defined in each. Eight standard filters inheriting SelectMgr_Filter are defined in Open CASCADE. You can create your own filters by defining new filter classes inheriting this framework. You use these filters by loading them into an AIS interactive context.");
	cls_SelectMgr_Filter.def("IsOk", (Standard_Boolean (SelectMgr_Filter::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const ) &SelectMgr_Filter::IsOk, "Indicates that the selected Interactive Object passes the filter. The owner, anObj, can be either direct or user. A direct owner is the corresponding construction element, whereas a user is the compound shape of which the entity forms a part. When an object is detected by the mouse - in AIS, this is done through a context selector - its owner is passed to the filter as an argument. If the object returns Standard_True, it is kept; if not, it is rejected. If you are creating a filter class inheriting this framework, and the daughter class is to be used in an AIS local context, you will need to implement the virtual function ActsOn.", py::arg("anObj"));
	cls_SelectMgr_Filter.def("ActsOn", (Standard_Boolean (SelectMgr_Filter::*)(const TopAbs_ShapeEnum) const ) &SelectMgr_Filter::ActsOn, "Returns true in an AIS local context, if this filter operates on a type of subshape defined in a filter class inheriting this framework. This function completes IsOk in an AIS local context.", py::arg("aStandardMode"));
	cls_SelectMgr_Filter.def_static("get_type_name_", (const char * (*)()) &SelectMgr_Filter::get_type_name, "None");
	cls_SelectMgr_Filter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_Filter::get_type_descriptor, "None");
	cls_SelectMgr_Filter.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_Filter::*)() const ) &SelectMgr_Filter::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_CompositionFilter.hxx
	py::class_<SelectMgr_CompositionFilter, opencascade::handle<SelectMgr_CompositionFilter>, SelectMgr_Filter> cls_SelectMgr_CompositionFilter(mod, "SelectMgr_CompositionFilter", "A framework to define a compound filter composed of two or more simple filters.");
	cls_SelectMgr_CompositionFilter.def("Add", (void (SelectMgr_CompositionFilter::*)(const opencascade::handle<SelectMgr_Filter> &)) &SelectMgr_CompositionFilter::Add, "Adds the filter afilter to a filter object created by a filter class inheriting this framework.", py::arg("afilter"));
	cls_SelectMgr_CompositionFilter.def("Remove", (void (SelectMgr_CompositionFilter::*)(const opencascade::handle<SelectMgr_Filter> &)) &SelectMgr_CompositionFilter::Remove, "Removes the filter aFilter from this framework.", py::arg("aFilter"));
	cls_SelectMgr_CompositionFilter.def("IsEmpty", (Standard_Boolean (SelectMgr_CompositionFilter::*)() const ) &SelectMgr_CompositionFilter::IsEmpty, "Returns true if this framework is empty.");
	cls_SelectMgr_CompositionFilter.def("IsIn", (Standard_Boolean (SelectMgr_CompositionFilter::*)(const opencascade::handle<SelectMgr_Filter> &) const ) &SelectMgr_CompositionFilter::IsIn, "Returns true if the filter aFilter is in this framework.", py::arg("aFilter"));
	cls_SelectMgr_CompositionFilter.def("StoredFilters", (const SelectMgr_ListOfFilter & (SelectMgr_CompositionFilter::*)() const ) &SelectMgr_CompositionFilter::StoredFilters, "Returns the list of stored filters from this framework.");
	cls_SelectMgr_CompositionFilter.def("Clear", (void (SelectMgr_CompositionFilter::*)()) &SelectMgr_CompositionFilter::Clear, "Clears the filters used in this framework.");
	cls_SelectMgr_CompositionFilter.def("ActsOn", (Standard_Boolean (SelectMgr_CompositionFilter::*)(const TopAbs_ShapeEnum) const ) &SelectMgr_CompositionFilter::ActsOn, "None", py::arg("aStandardMode"));
	cls_SelectMgr_CompositionFilter.def_static("get_type_name_", (const char * (*)()) &SelectMgr_CompositionFilter::get_type_name, "None");
	cls_SelectMgr_CompositionFilter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_CompositionFilter::get_type_descriptor, "None");
	cls_SelectMgr_CompositionFilter.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_CompositionFilter::*)() const ) &SelectMgr_CompositionFilter::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_OrFilter.hxx
	py::class_<SelectMgr_OrFilter, opencascade::handle<SelectMgr_OrFilter>, SelectMgr_CompositionFilter> cls_SelectMgr_OrFilter(mod, "SelectMgr_OrFilter", "A framework to define an or selection filter. This selects one or another type of sensitive entity.");
	cls_SelectMgr_OrFilter.def(py::init<>());
	cls_SelectMgr_OrFilter.def("IsOk", (Standard_Boolean (SelectMgr_OrFilter::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const ) &SelectMgr_OrFilter::IsOk, "None", py::arg("anobj"));
	cls_SelectMgr_OrFilter.def("SetDisabledObjects", (void (SelectMgr_OrFilter::*)(const opencascade::handle<Graphic3d_NMapOfTransient> &)) &SelectMgr_OrFilter::SetDisabledObjects, "Disable selection of specified objects.", py::arg("theObjects"));
	cls_SelectMgr_OrFilter.def_static("get_type_name_", (const char * (*)()) &SelectMgr_OrFilter::get_type_name, "None");
	cls_SelectMgr_OrFilter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_OrFilter::get_type_descriptor, "None");
	cls_SelectMgr_OrFilter.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_OrFilter::*)() const ) &SelectMgr_OrFilter::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_AndFilter.hxx
	py::class_<SelectMgr_AndFilter, opencascade::handle<SelectMgr_AndFilter>, SelectMgr_CompositionFilter> cls_SelectMgr_AndFilter(mod, "SelectMgr_AndFilter", "A framework to define a selection filter for two or more types of entity.");
	cls_SelectMgr_AndFilter.def(py::init<>());
	cls_SelectMgr_AndFilter.def("IsOk", (Standard_Boolean (SelectMgr_AndFilter::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const ) &SelectMgr_AndFilter::IsOk, "None", py::arg("anobj"));
	cls_SelectMgr_AndFilter.def_static("get_type_name_", (const char * (*)()) &SelectMgr_AndFilter::get_type_name, "None");
	cls_SelectMgr_AndFilter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &SelectMgr_AndFilter::get_type_descriptor, "None");
	cls_SelectMgr_AndFilter.def("DynamicType", (const opencascade::handle<Standard_Type> & (SelectMgr_AndFilter::*)() const ) &SelectMgr_AndFilter::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_SequenceOfSelection.hxx
	bind_NCollection_Sequence<opencascade::handle<SelectMgr_Selection> >(mod, "SelectMgr_SequenceOfSelection");

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_SequenceOfOwner.hxx
	bind_NCollection_Sequence<opencascade::handle<SelectMgr_EntityOwner> >(mod, "SelectMgr_SequenceOfOwner");

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_IndexedMapOfOwner.hxx
	bind_NCollection_Shared<NCollection_IndexedMap<opencascade::handle<SelectMgr_EntityOwner>, NCollection_DefaultHasher<opencascade::handle<SelectMgr_EntityOwner> > >, void>(mod, "SelectMgr_IndexedMapOfOwner");

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_IndexedDataMapOfOwnerCriterion.hxx
	bind_NCollection_IndexedDataMap<opencascade::handle<SelectBasics_EntityOwner>, SelectMgr_SortCriterion, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "SelectMgr_IndexedDataMapOfOwnerCriterion");

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_VectorTypes.hxx
	other_mod = py::module::import("OCCT.BVH");
	if (py::hasattr(other_mod, "BVH_Vec3d")) {
		mod.attr("SelectMgr_Vec3") = other_mod.attr("BVH_Vec3d");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_VectorTypes.hxx
	other_mod = py::module::import("OCCT.BVH");
	if (py::hasattr(other_mod, "BVH_Vec4d")) {
		mod.attr("SelectMgr_Vec4") = other_mod.attr("BVH_Vec4d");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_VectorTypes.hxx
	other_mod = py::module::import("OCCT.BVH");
	if (py::hasattr(other_mod, "BVH_Mat4d")) {
		mod.attr("SelectMgr_Mat4") = other_mod.attr("BVH_Mat4d");
	}

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_TriangularFrustumSet.hxx
	bind_NCollection_List<opencascade::handle<SelectMgr_TriangularFrustum> >(mod, "SelectMgr_TriangFrustums");

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_TriangularFrustumSet.hxx
	bind_NCollection_TListIterator<opencascade::handle<SelectMgr_TriangularFrustum> >(mod, "SelectMgr_TriangFrustumsIter");

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_ViewerSelector.hxx
	bind_NCollection_DataMap<opencascade::handle<SelectMgr_SelectableObject>, opencascade::handle<SelectMgr_SensitiveEntitySet>, NCollection_DefaultHasher<opencascade::handle<SelectMgr_SelectableObject> > >(mod, "SelectMgr_MapOfObjectSensitives");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_ViewerSelector.hxx
	bind_NCollection_DataMap<int, SelectMgr_SelectingVolumeManager, NCollection_DefaultHasher<int> >(mod, "SelectMgr_FrustumCache");

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_ListOfFilter.hxx
	bind_NCollection_List<opencascade::handle<SelectMgr_Filter> >(mod, "SelectMgr_ListOfFilter");

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_ListOfFilter.hxx
	bind_NCollection_TListIterator<opencascade::handle<SelectMgr_Filter> >(mod, "SelectMgr_ListIteratorOfListOfFilter");

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_SOPtr.hxx
	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_SequenceOfSelector.hxx
	bind_NCollection_Sequence<opencascade::handle<SelectMgr_ViewerSelector> >(mod, "SelectMgr_SequenceOfSelector");

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_DataMapOfObjectSelectors.hxx
	bind_NCollection_DataMap<opencascade::handle<SelectMgr_SelectableObject>, NCollection_Sequence<opencascade::handle<SelectMgr_ViewerSelector> >, NCollection_DefaultHasher<opencascade::handle<Standard_Transient> > >(mod, "SelectMgr_DataMapOfObjectSelectors");

	/* FIXME

	*/

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_SensitiveEntitySet.hxx
	bind_NCollection_IndexedMap<opencascade::handle<SelectMgr_SensitiveEntity>, NCollection_DefaultHasher<opencascade::handle<SelectMgr_SensitiveEntity> > >(mod, "SelectMgr_IndexedMapOfHSensitive");

	// C:\Miniconda\envs\occt\Library\include\opencascade\SelectMgr_SequenceOfFilter.hxx
	bind_NCollection_Sequence<opencascade::handle<SelectMgr_Filter> >(mod, "SelectMgr_SequenceOfFilter");


}
