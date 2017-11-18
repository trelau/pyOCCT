#include <pyOCCT_Common.hpp>

#include <StepVisual_AnnotationOccurrence.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <StepVisual_AnnotationCurveOccurrence.hxx>
#include <StepVisual_AnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem.hxx>
#include <StepShape_GeometricCurveSet.hxx>
#include <StepVisual_AnnotationFillArea.hxx>
#include <TCollection_HAsciiString.hxx>
#include <StepVisual_HArray1OfPresentationStyleAssignment.hxx>
#include <Standard_Transient.hxx>
#include <StepGeom_GeometricRepresentationItem.hxx>
#include <StepVisual_AnnotationFillAreaOccurrence.hxx>
#include <StepVisual_StyledItem.hxx>
#include <StepVisual_HArray1OfAnnotationPlaneElement.hxx>
#include <Standard_TypeDef.hxx>
#include <StepVisual_AnnotationPlaneElement.hxx>
#include <StepVisual_AnnotationPlane.hxx>
#include <StepVisual_PresentationArea.hxx>
#include <StepVisual_PresentationSet.hxx>
#include <StepVisual_AreaInSet.hxx>
#include <StepVisual_Colour.hxx>
#include <StepVisual_AreaOrView.hxx>
#include <StepVisual_BackgroundColour.hxx>
#include <StepRepr_MappedItem.hxx>
#include <StepVisual_CameraImage.hxx>
#include <StepVisual_CameraModel.hxx>
#include <StepVisual_PlanarBox.hxx>
#include <StepVisual_CameraModelD2.hxx>
#include <StepGeom_Axis2Placement3d.hxx>
#include <StepVisual_ViewVolume.hxx>
#include <StepVisual_CameraModelD3.hxx>
#include <StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect.hxx>
#include <StepVisual_CameraModelD3MultiClipping.hxx>
#include <StepVisual_CameraModelD3MultiClippingIntersection.hxx>
#include <StepVisual_HArray1OfCameraModelD3MultiClippingUnionSelect.hxx>
#include <StepVisual_CameraModelD3MultiClippingUnion.hxx>
#include <StepRepr_RepresentationMap.hxx>
#include <StepVisual_CameraUsage.hxx>
#include <StepVisual_DraughtingModel.hxx>
#include <StepVisual_CharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation.hxx>
#include <StepVisual_ColourSpecification.hxx>
#include <StepVisual_ColourRgb.hxx>
#include <StepVisual_HArray1OfTextOrCharacter.hxx>
#include <StepVisual_TextOrCharacter.hxx>
#include <StepVisual_CompositeText.hxx>
#include <StepVisual_PlanarExtent.hxx>
#include <StepVisual_CompositeTextWithExtent.hxx>
#include <StepVisual_Invisibility.hxx>
#include <StepVisual_HArray1OfInvisibleItem.hxx>
#include <StepVisual_InvisibilityContext.hxx>
#include <StepVisual_ContextDependentInvisibility.hxx>
#include <StepVisual_OverRidingStyledItem.hxx>
#include <StepVisual_HArray1OfStyleContextSelect.hxx>
#include <StepVisual_StyleContextSelect.hxx>
#include <StepVisual_ContextDependentOverRidingStyledItem.hxx>
#include <StepVisual_TessellatedItem.hxx>
#include <TColgp_HArray1OfXYZ.hxx>
#include <StepVisual_CoordinatesList.hxx>
#include <StepVisual_CurveStyleFontSelect.hxx>
#include <StepBasic_SizeSelect.hxx>
#include <StepVisual_CurveStyle.hxx>
#include <StepVisual_HArray1OfCurveStyleFontPattern.hxx>
#include <StepVisual_CurveStyleFontPattern.hxx>
#include <StepVisual_CurveStyleFont.hxx>
#include <StepVisual_HArray1OfDraughtingCalloutElement.hxx>
#include <StepVisual_DraughtingCalloutElement.hxx>
#include <StepVisual_DraughtingCallout.hxx>
#include <StepRepr_Representation.hxx>
#include <StepVisual_PreDefinedColour.hxx>
#include <StepVisual_DraughtingPreDefinedColour.hxx>
#include <StepVisual_PreDefinedCurveFont.hxx>
#include <StepVisual_DraughtingPreDefinedCurveFont.hxx>
#include <StepBasic_ExternallyDefinedItem.hxx>
#include <StepVisual_ExternallyDefinedCurveFont.hxx>
#include <StepVisual_HArray1OfFillStyleSelect.hxx>
#include <StepVisual_FillStyleSelect.hxx>
#include <StepVisual_FillAreaStyle.hxx>
#include <StepVisual_FillAreaStyleColour.hxx>
#include <StepVisual_InvisibleItem.hxx>
#include <StepVisual_MechanicalDesignGeometricPresentationArea.hxx>
#include <StepVisual_PresentationRepresentation.hxx>
#include <StepVisual_MechanicalDesignGeometricPresentationRepresentation.hxx>
#include <StepGeom_Axis2Placement.hxx>
#include <StepVisual_MarkerSelect.hxx>
#include <StepVisual_PointStyle.hxx>
#include <StepVisual_PreDefinedItem.hxx>
#include <StepVisual_HArray1OfLayeredItem.hxx>
#include <StepVisual_LayeredItem.hxx>
#include <StepVisual_PresentationLayerAssignment.hxx>
#include <StepVisual_PresentationLayerUsage.hxx>
#include <StepVisual_PresentationSizeAssignmentSelect.hxx>
#include <StepVisual_PresentationSize.hxx>
#include <StepVisual_HArray1OfPresentationStyleSelect.hxx>
#include <StepVisual_PresentationStyleSelect.hxx>
#include <StepVisual_PresentationStyleAssignment.hxx>
#include <StepVisual_PresentationStyleByContext.hxx>
#include <StepVisual_PresentationView.hxx>
#include <StepVisual_PresentationRepresentationSelect.hxx>
#include <StepVisual_PresentedItem.hxx>
#include <StepVisual_PresentedItemRepresentation.hxx>
#include <StepRepr_RepresentationItem.hxx>
#include <StepVisual_StyledItemTarget.hxx>
#include <StepVisual_HArray1OfSurfaceStyleElementSelect.hxx>
#include <StepVisual_SurfaceStyleElementSelect.hxx>
#include <StepVisual_SurfaceSideStyle.hxx>
#include <StepVisual_SurfaceStyleBoundary.hxx>
#include <StepVisual_SurfaceStyleControlGrid.hxx>
#include <StepVisual_SurfaceStyleFillArea.hxx>
#include <StepVisual_HArray1OfDirectionCountSelect.hxx>
#include <StepVisual_DirectionCountSelect.hxx>
#include <StepVisual_SurfaceStyleParameterLine.hxx>
#include <StepVisual_SurfaceStyleSegmentationCurve.hxx>
#include <StepVisual_SurfaceStyleSilhouette.hxx>
#include <StepVisual_SurfaceSide.hxx>
#include <StepVisual_SurfaceStyleUsage.hxx>
#include <StepVisual_Template.hxx>
#include <StepVisual_TemplateInstance.hxx>
#include <StepVisual_TessellatedAnnotationOccurrence.hxx>
#include <NCollection_BaseVector.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_Vector.hxx>
#include <StepVisual_TessellatedCurveSet.hxx>
#include <NCollection_Handle.hxx>
#include <StepVisual_TessellatedGeometricSet.hxx>
#include <StepVisual_TextPath.hxx>
#include <StepVisual_FontSelect.hxx>
#include <StepVisual_TextLiteral.hxx>
#include <StepVisual_TextStyleForDefinedFont.hxx>
#include <StepVisual_TextStyle.hxx>
#include <StepVisual_HArray1OfBoxCharacteristicSelect.hxx>
#include <StepVisual_BoxCharacteristicSelect.hxx>
#include <StepVisual_TextStyleWithBoxCharacteristics.hxx>
#include <StepVisual_CentralOrParallel.hxx>
#include <StepGeom_CartesianPoint.hxx>
#include <NCollection_Array1.hxx>
#include <StepData_SelectInt.hxx>
#include <StepVisual_NullStyle.hxx>
#include <StepVisual_NullStyleMember.hxx>
#include <StepData_SelectType.hxx>
#include <StepVisual_Array1OfPresentationStyleSelect.hxx>
#include <StepVisual_Array1OfPresentationStyleAssignment.hxx>
#include <StepShape_TopologicalRepresentationItem.hxx>
#include <StepVisual_Array1OfAnnotationPlaneElement.hxx>
#include <StepVisual_AnnotationText.hxx>
#include <StepVisual_AnnotationTextOccurrence.hxx>
#include <StepVisual_Array1OfBoxCharacteristicSelect.hxx>
#include <StepGeom_Plane.hxx>
#include <StepVisual_CameraModelD3MultiClippingInterectionSelect.hxx>
#include <StepVisual_Array1OfCameraModelD3MultiClippingInterectionSelect.hxx>
#include <StepVisual_CameraModelD3MultiClippingUnionSelect.hxx>
#include <StepVisual_Array1OfCameraModelD3MultiClippingUnionSelect.hxx>
#include <StepVisual_Array1OfCurveStyleFontPattern.hxx>
#include <StepVisual_Array1OfDirectionCountSelect.hxx>
#include <StepVisual_Array1OfDraughtingCalloutElement.hxx>
#include <StepVisual_Array1OfFillStyleSelect.hxx>
#include <StepVisual_Array1OfInvisibleItem.hxx>
#include <StepVisual_Array1OfLayeredItem.hxx>
#include <StepVisual_Array1OfStyleContextSelect.hxx>
#include <StepVisual_Array1OfSurfaceStyleElementSelect.hxx>
#include <StepVisual_Array1OfTextOrCharacter.hxx>
#include <StepVisual_CameraImage2dWithScale.hxx>
#include <StepVisual_CameraImage3dWithScale.hxx>
#include <StepVisual_DraughtingAnnotationOccurrence.hxx>
#include <StepVisual_ExternallyDefinedTextFont.hxx>
#include <StepVisual_PreDefinedTextFont.hxx>
#include <StepVisual_MarkerType.hxx>
#include <StepVisual_MarkerMember.hxx>
#include <StepData_SelectMember.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(StepVisual, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.StepShape");
	py::module::import("OCCT.TCollection");
	py::module::import("OCCT.StepGeom");
	py::module::import("OCCT.StepRepr");
	py::module::import("OCCT.TColgp");
	py::module::import("OCCT.StepBasic");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.StepData");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_CentralOrParallel.hxx
	py::enum_<StepVisual_CentralOrParallel>(mod, "StepVisual_CentralOrParallel", "None")
		.value("StepVisual_copCentral", StepVisual_CentralOrParallel::StepVisual_copCentral)
		.value("StepVisual_copParallel", StepVisual_CentralOrParallel::StepVisual_copParallel)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_MarkerType.hxx
	py::enum_<StepVisual_MarkerType>(mod, "StepVisual_MarkerType", "None")
		.value("StepVisual_mtDot", StepVisual_MarkerType::StepVisual_mtDot)
		.value("StepVisual_mtX", StepVisual_MarkerType::StepVisual_mtX)
		.value("StepVisual_mtPlus", StepVisual_MarkerType::StepVisual_mtPlus)
		.value("StepVisual_mtAsterisk", StepVisual_MarkerType::StepVisual_mtAsterisk)
		.value("StepVisual_mtRing", StepVisual_MarkerType::StepVisual_mtRing)
		.value("StepVisual_mtSquare", StepVisual_MarkerType::StepVisual_mtSquare)
		.value("StepVisual_mtTriangle", StepVisual_MarkerType::StepVisual_mtTriangle)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_NullStyle.hxx
	py::enum_<StepVisual_NullStyle>(mod, "StepVisual_NullStyle", "None")
		.value("StepVisual_Null", StepVisual_NullStyle::StepVisual_Null)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_SurfaceSide.hxx
	py::enum_<StepVisual_SurfaceSide>(mod, "StepVisual_SurfaceSide", "None")
		.value("StepVisual_ssNegative", StepVisual_SurfaceSide::StepVisual_ssNegative)
		.value("StepVisual_ssPositive", StepVisual_SurfaceSide::StepVisual_ssPositive)
		.value("StepVisual_ssBoth", StepVisual_SurfaceSide::StepVisual_ssBoth)
		.export_values();
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_TextPath.hxx
	py::enum_<StepVisual_TextPath>(mod, "StepVisual_TextPath", "None")
		.value("StepVisual_tpUp", StepVisual_TextPath::StepVisual_tpUp)
		.value("StepVisual_tpRight", StepVisual_TextPath::StepVisual_tpRight)
		.value("StepVisual_tpDown", StepVisual_TextPath::StepVisual_tpDown)
		.value("StepVisual_tpLeft", StepVisual_TextPath::StepVisual_tpLeft)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_StyledItem.hxx
	py::class_<StepVisual_StyledItem, opencascade::handle<StepVisual_StyledItem>, StepRepr_RepresentationItem> cls_StepVisual_StyledItem(mod, "StepVisual_StyledItem", "None");
	cls_StepVisual_StyledItem.def(py::init<>());
	cls_StepVisual_StyledItem.def("Init", (void (StepVisual_StyledItem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_HArray1OfPresentationStyleAssignment> &, const opencascade::handle<Standard_Transient> &)) &StepVisual_StyledItem::Init, "None", py::arg("aName"), py::arg("aStyles"), py::arg("aItem"));
	cls_StepVisual_StyledItem.def("SetStyles", (void (StepVisual_StyledItem::*)(const opencascade::handle<StepVisual_HArray1OfPresentationStyleAssignment> &)) &StepVisual_StyledItem::SetStyles, "None", py::arg("aStyles"));
	cls_StepVisual_StyledItem.def("Styles", (opencascade::handle<StepVisual_HArray1OfPresentationStyleAssignment> (StepVisual_StyledItem::*)() const ) &StepVisual_StyledItem::Styles, "None");
	cls_StepVisual_StyledItem.def("StylesValue", (opencascade::handle<StepVisual_PresentationStyleAssignment> (StepVisual_StyledItem::*)(const Standard_Integer) const ) &StepVisual_StyledItem::StylesValue, "None", py::arg("num"));
	cls_StepVisual_StyledItem.def("NbStyles", (Standard_Integer (StepVisual_StyledItem::*)() const ) &StepVisual_StyledItem::NbStyles, "None");
	cls_StepVisual_StyledItem.def("SetItem", (void (StepVisual_StyledItem::*)(const opencascade::handle<StepRepr_RepresentationItem> &)) &StepVisual_StyledItem::SetItem, "None", py::arg("aItem"));
	cls_StepVisual_StyledItem.def("Item", (opencascade::handle<StepRepr_RepresentationItem> (StepVisual_StyledItem::*)() const ) &StepVisual_StyledItem::Item, "None");
	cls_StepVisual_StyledItem.def("SetItem", (void (StepVisual_StyledItem::*)(const StepVisual_StyledItemTarget &)) &StepVisual_StyledItem::SetItem, "None", py::arg("aItem"));
	cls_StepVisual_StyledItem.def("ItemAP242", (StepVisual_StyledItemTarget (StepVisual_StyledItem::*)() const ) &StepVisual_StyledItem::ItemAP242, "None");
	cls_StepVisual_StyledItem.def_static("get_type_name_", (const char * (*)()) &StepVisual_StyledItem::get_type_name, "None");
	cls_StepVisual_StyledItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_StyledItem::get_type_descriptor, "None");
	cls_StepVisual_StyledItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_StyledItem::*)() const ) &StepVisual_StyledItem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_AnnotationOccurrence.hxx
	py::class_<StepVisual_AnnotationOccurrence, opencascade::handle<StepVisual_AnnotationOccurrence>, StepVisual_StyledItem> cls_StepVisual_AnnotationOccurrence(mod, "StepVisual_AnnotationOccurrence", "None");
	cls_StepVisual_AnnotationOccurrence.def(py::init<>());
	cls_StepVisual_AnnotationOccurrence.def_static("get_type_name_", (const char * (*)()) &StepVisual_AnnotationOccurrence::get_type_name, "None");
	cls_StepVisual_AnnotationOccurrence.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_AnnotationOccurrence::get_type_descriptor, "None");
	cls_StepVisual_AnnotationOccurrence.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_AnnotationOccurrence::*)() const ) &StepVisual_AnnotationOccurrence::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_AnnotationFillArea.hxx
	py::class_<StepVisual_AnnotationFillArea, opencascade::handle<StepVisual_AnnotationFillArea>, StepShape_GeometricCurveSet> cls_StepVisual_AnnotationFillArea(mod, "StepVisual_AnnotationFillArea", "None");
	cls_StepVisual_AnnotationFillArea.def(py::init<>());
	cls_StepVisual_AnnotationFillArea.def_static("get_type_name_", (const char * (*)()) &StepVisual_AnnotationFillArea::get_type_name, "None");
	cls_StepVisual_AnnotationFillArea.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_AnnotationFillArea::get_type_descriptor, "None");
	cls_StepVisual_AnnotationFillArea.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_AnnotationFillArea::*)() const ) &StepVisual_AnnotationFillArea::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_AnnotationFillAreaOccurrence.hxx
	py::class_<StepVisual_AnnotationFillAreaOccurrence, opencascade::handle<StepVisual_AnnotationFillAreaOccurrence>, StepVisual_AnnotationOccurrence> cls_StepVisual_AnnotationFillAreaOccurrence(mod, "StepVisual_AnnotationFillAreaOccurrence", "None");
	cls_StepVisual_AnnotationFillAreaOccurrence.def(py::init<>());
	cls_StepVisual_AnnotationFillAreaOccurrence.def("Init", (void (StepVisual_AnnotationFillAreaOccurrence::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_HArray1OfPresentationStyleAssignment> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<StepGeom_GeometricRepresentationItem> &)) &StepVisual_AnnotationFillAreaOccurrence::Init, "Initialize all fields (own and inherited)", py::arg("theName"), py::arg("theStyles"), py::arg("theItem"), py::arg("theFillStyleTarget"));
	cls_StepVisual_AnnotationFillAreaOccurrence.def("FillStyleTarget", (opencascade::handle<StepGeom_GeometricRepresentationItem> (StepVisual_AnnotationFillAreaOccurrence::*)() const ) &StepVisual_AnnotationFillAreaOccurrence::FillStyleTarget, "Returns field fill_style_target");
	cls_StepVisual_AnnotationFillAreaOccurrence.def("SetFillStyleTarget", (void (StepVisual_AnnotationFillAreaOccurrence::*)(const opencascade::handle<StepGeom_GeometricRepresentationItem> &)) &StepVisual_AnnotationFillAreaOccurrence::SetFillStyleTarget, "Set field fill_style_target", py::arg("theTarget"));
	cls_StepVisual_AnnotationFillAreaOccurrence.def_static("get_type_name_", (const char * (*)()) &StepVisual_AnnotationFillAreaOccurrence::get_type_name, "None");
	cls_StepVisual_AnnotationFillAreaOccurrence.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_AnnotationFillAreaOccurrence::get_type_descriptor, "None");
	cls_StepVisual_AnnotationFillAreaOccurrence.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_AnnotationFillAreaOccurrence::*)() const ) &StepVisual_AnnotationFillAreaOccurrence::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_AnnotationCurveOccurrence.hxx
	py::class_<StepVisual_AnnotationCurveOccurrence, opencascade::handle<StepVisual_AnnotationCurveOccurrence>, StepVisual_AnnotationOccurrence> cls_StepVisual_AnnotationCurveOccurrence(mod, "StepVisual_AnnotationCurveOccurrence", "None");
	cls_StepVisual_AnnotationCurveOccurrence.def(py::init<>());
	cls_StepVisual_AnnotationCurveOccurrence.def_static("get_type_name_", (const char * (*)()) &StepVisual_AnnotationCurveOccurrence::get_type_name, "None");
	cls_StepVisual_AnnotationCurveOccurrence.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_AnnotationCurveOccurrence::get_type_descriptor, "None");
	cls_StepVisual_AnnotationCurveOccurrence.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_AnnotationCurveOccurrence::*)() const ) &StepVisual_AnnotationCurveOccurrence::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_AnnotationPlane.hxx
	py::class_<StepVisual_AnnotationPlane, opencascade::handle<StepVisual_AnnotationPlane>, StepVisual_AnnotationOccurrence> cls_StepVisual_AnnotationPlane(mod, "StepVisual_AnnotationPlane", "None");
	cls_StepVisual_AnnotationPlane.def(py::init<>());
	cls_StepVisual_AnnotationPlane.def("Init", (void (StepVisual_AnnotationPlane::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_HArray1OfPresentationStyleAssignment> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<StepVisual_HArray1OfAnnotationPlaneElement> &)) &StepVisual_AnnotationPlane::Init, "None", py::arg("theName"), py::arg("theStyles"), py::arg("theItem"), py::arg("theElements"));
	cls_StepVisual_AnnotationPlane.def("Elements", (opencascade::handle<StepVisual_HArray1OfAnnotationPlaneElement> (StepVisual_AnnotationPlane::*)() const ) &StepVisual_AnnotationPlane::Elements, "Returns field Elements");
	cls_StepVisual_AnnotationPlane.def("SetElements", (void (StepVisual_AnnotationPlane::*)(const opencascade::handle<StepVisual_HArray1OfAnnotationPlaneElement> &)) &StepVisual_AnnotationPlane::SetElements, "Set field Elements", py::arg("theElements"));
	cls_StepVisual_AnnotationPlane.def("NbElements", (Standard_Integer (StepVisual_AnnotationPlane::*)() const ) &StepVisual_AnnotationPlane::NbElements, "Returns number of Elements");
	cls_StepVisual_AnnotationPlane.def("ElementsValue", (StepVisual_AnnotationPlaneElement (StepVisual_AnnotationPlane::*)(const Standard_Integer) const ) &StepVisual_AnnotationPlane::ElementsValue, "Returns Elements with the given number", py::arg("theNum"));
	cls_StepVisual_AnnotationPlane.def("SetElementsValue", (void (StepVisual_AnnotationPlane::*)(const Standard_Integer, const StepVisual_AnnotationPlaneElement &)) &StepVisual_AnnotationPlane::SetElementsValue, "Sets Elements with given number", py::arg("theNum"), py::arg("theItem"));
	cls_StepVisual_AnnotationPlane.def_static("get_type_name_", (const char * (*)()) &StepVisual_AnnotationPlane::get_type_name, "None");
	cls_StepVisual_AnnotationPlane.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_AnnotationPlane::get_type_descriptor, "None");
	cls_StepVisual_AnnotationPlane.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_AnnotationPlane::*)() const ) &StepVisual_AnnotationPlane::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_AreaInSet.hxx
	py::class_<StepVisual_AreaInSet, opencascade::handle<StepVisual_AreaInSet>, Standard_Transient> cls_StepVisual_AreaInSet(mod, "StepVisual_AreaInSet", "None");
	cls_StepVisual_AreaInSet.def(py::init<>());
	cls_StepVisual_AreaInSet.def("Init", (void (StepVisual_AreaInSet::*)(const opencascade::handle<StepVisual_PresentationArea> &, const opencascade::handle<StepVisual_PresentationSet> &)) &StepVisual_AreaInSet::Init, "None", py::arg("aArea"), py::arg("aInSet"));
	cls_StepVisual_AreaInSet.def("SetArea", (void (StepVisual_AreaInSet::*)(const opencascade::handle<StepVisual_PresentationArea> &)) &StepVisual_AreaInSet::SetArea, "None", py::arg("aArea"));
	cls_StepVisual_AreaInSet.def("Area", (opencascade::handle<StepVisual_PresentationArea> (StepVisual_AreaInSet::*)() const ) &StepVisual_AreaInSet::Area, "None");
	cls_StepVisual_AreaInSet.def("SetInSet", (void (StepVisual_AreaInSet::*)(const opencascade::handle<StepVisual_PresentationSet> &)) &StepVisual_AreaInSet::SetInSet, "None", py::arg("aInSet"));
	cls_StepVisual_AreaInSet.def("InSet", (opencascade::handle<StepVisual_PresentationSet> (StepVisual_AreaInSet::*)() const ) &StepVisual_AreaInSet::InSet, "None");
	cls_StepVisual_AreaInSet.def_static("get_type_name_", (const char * (*)()) &StepVisual_AreaInSet::get_type_name, "None");
	cls_StepVisual_AreaInSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_AreaInSet::get_type_descriptor, "None");
	cls_StepVisual_AreaInSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_AreaInSet::*)() const ) &StepVisual_AreaInSet::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_Colour.hxx
	py::class_<StepVisual_Colour, opencascade::handle<StepVisual_Colour>, Standard_Transient> cls_StepVisual_Colour(mod, "StepVisual_Colour", "None");
	cls_StepVisual_Colour.def(py::init<>());
	cls_StepVisual_Colour.def_static("get_type_name_", (const char * (*)()) &StepVisual_Colour::get_type_name, "None");
	cls_StepVisual_Colour.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_Colour::get_type_descriptor, "None");
	cls_StepVisual_Colour.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_Colour::*)() const ) &StepVisual_Colour::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_CameraImage.hxx
	py::class_<StepVisual_CameraImage, opencascade::handle<StepVisual_CameraImage>, StepRepr_MappedItem> cls_StepVisual_CameraImage(mod, "StepVisual_CameraImage", "None");
	cls_StepVisual_CameraImage.def(py::init<>());
	cls_StepVisual_CameraImage.def_static("get_type_name_", (const char * (*)()) &StepVisual_CameraImage::get_type_name, "None");
	cls_StepVisual_CameraImage.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_CameraImage::get_type_descriptor, "None");
	cls_StepVisual_CameraImage.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_CameraImage::*)() const ) &StepVisual_CameraImage::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_CameraModel.hxx
	py::class_<StepVisual_CameraModel, opencascade::handle<StepVisual_CameraModel>, StepGeom_GeometricRepresentationItem> cls_StepVisual_CameraModel(mod, "StepVisual_CameraModel", "None");
	cls_StepVisual_CameraModel.def(py::init<>());
	cls_StepVisual_CameraModel.def_static("get_type_name_", (const char * (*)()) &StepVisual_CameraModel::get_type_name, "None");
	cls_StepVisual_CameraModel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_CameraModel::get_type_descriptor, "None");
	cls_StepVisual_CameraModel.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_CameraModel::*)() const ) &StepVisual_CameraModel::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_CameraModelD2.hxx
	py::class_<StepVisual_CameraModelD2, opencascade::handle<StepVisual_CameraModelD2>, StepVisual_CameraModel> cls_StepVisual_CameraModelD2(mod, "StepVisual_CameraModelD2", "None");
	cls_StepVisual_CameraModelD2.def(py::init<>());
	cls_StepVisual_CameraModelD2.def("Init", (void (StepVisual_CameraModelD2::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_PlanarBox> &, const Standard_Boolean)) &StepVisual_CameraModelD2::Init, "None", py::arg("aName"), py::arg("aViewWindow"), py::arg("aViewWindowClipping"));
	cls_StepVisual_CameraModelD2.def("SetViewWindow", (void (StepVisual_CameraModelD2::*)(const opencascade::handle<StepVisual_PlanarBox> &)) &StepVisual_CameraModelD2::SetViewWindow, "None", py::arg("aViewWindow"));
	cls_StepVisual_CameraModelD2.def("ViewWindow", (opencascade::handle<StepVisual_PlanarBox> (StepVisual_CameraModelD2::*)() const ) &StepVisual_CameraModelD2::ViewWindow, "None");
	cls_StepVisual_CameraModelD2.def("SetViewWindowClipping", (void (StepVisual_CameraModelD2::*)(const Standard_Boolean)) &StepVisual_CameraModelD2::SetViewWindowClipping, "None", py::arg("aViewWindowClipping"));
	cls_StepVisual_CameraModelD2.def("ViewWindowClipping", (Standard_Boolean (StepVisual_CameraModelD2::*)() const ) &StepVisual_CameraModelD2::ViewWindowClipping, "None");
	cls_StepVisual_CameraModelD2.def_static("get_type_name_", (const char * (*)()) &StepVisual_CameraModelD2::get_type_name, "None");
	cls_StepVisual_CameraModelD2.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_CameraModelD2::get_type_descriptor, "None");
	cls_StepVisual_CameraModelD2.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_CameraModelD2::*)() const ) &StepVisual_CameraModelD2::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_CameraModelD3.hxx
	py::class_<StepVisual_CameraModelD3, opencascade::handle<StepVisual_CameraModelD3>, StepVisual_CameraModel> cls_StepVisual_CameraModelD3(mod, "StepVisual_CameraModelD3", "None");
	cls_StepVisual_CameraModelD3.def(py::init<>());
	cls_StepVisual_CameraModelD3.def("Init", (void (StepVisual_CameraModelD3::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Axis2Placement3d> &, const opencascade::handle<StepVisual_ViewVolume> &)) &StepVisual_CameraModelD3::Init, "None", py::arg("aName"), py::arg("aViewReferenceSystem"), py::arg("aPerspectiveOfVolume"));
	cls_StepVisual_CameraModelD3.def("SetViewReferenceSystem", (void (StepVisual_CameraModelD3::*)(const opencascade::handle<StepGeom_Axis2Placement3d> &)) &StepVisual_CameraModelD3::SetViewReferenceSystem, "None", py::arg("aViewReferenceSystem"));
	cls_StepVisual_CameraModelD3.def("ViewReferenceSystem", (opencascade::handle<StepGeom_Axis2Placement3d> (StepVisual_CameraModelD3::*)() const ) &StepVisual_CameraModelD3::ViewReferenceSystem, "None");
	cls_StepVisual_CameraModelD3.def("SetPerspectiveOfVolume", (void (StepVisual_CameraModelD3::*)(const opencascade::handle<StepVisual_ViewVolume> &)) &StepVisual_CameraModelD3::SetPerspectiveOfVolume, "None", py::arg("aPerspectiveOfVolume"));
	cls_StepVisual_CameraModelD3.def("PerspectiveOfVolume", (opencascade::handle<StepVisual_ViewVolume> (StepVisual_CameraModelD3::*)() const ) &StepVisual_CameraModelD3::PerspectiveOfVolume, "None");
	cls_StepVisual_CameraModelD3.def_static("get_type_name_", (const char * (*)()) &StepVisual_CameraModelD3::get_type_name, "None");
	cls_StepVisual_CameraModelD3.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_CameraModelD3::get_type_descriptor, "None");
	cls_StepVisual_CameraModelD3.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_CameraModelD3::*)() const ) &StepVisual_CameraModelD3::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_CameraModelD3MultiClipping.hxx
	py::class_<StepVisual_CameraModelD3MultiClipping, opencascade::handle<StepVisual_CameraModelD3MultiClipping>, StepVisual_CameraModelD3> cls_StepVisual_CameraModelD3MultiClipping(mod, "StepVisual_CameraModelD3MultiClipping", "None");
	cls_StepVisual_CameraModelD3MultiClipping.def(py::init<>());
	cls_StepVisual_CameraModelD3MultiClipping.def("Init", (void (StepVisual_CameraModelD3MultiClipping::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepGeom_Axis2Placement3d> &, const opencascade::handle<StepVisual_ViewVolume> &, const opencascade::handle<StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect> &)) &StepVisual_CameraModelD3MultiClipping::Init, "None", py::arg("theName"), py::arg("theViewReferenceSystem"), py::arg("thePerspectiveOfVolume"), py::arg("theShapeClipping"));
	cls_StepVisual_CameraModelD3MultiClipping.def("SetShapeClipping", (void (StepVisual_CameraModelD3MultiClipping::*)(const opencascade::handle<StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect> &)) &StepVisual_CameraModelD3MultiClipping::SetShapeClipping, "None", py::arg("theShapeClipping"));
	cls_StepVisual_CameraModelD3MultiClipping.def("ShapeClipping", (const opencascade::handle<StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect> (StepVisual_CameraModelD3MultiClipping::*)()) &StepVisual_CameraModelD3MultiClipping::ShapeClipping, "None");
	cls_StepVisual_CameraModelD3MultiClipping.def_static("get_type_name_", (const char * (*)()) &StepVisual_CameraModelD3MultiClipping::get_type_name, "None");
	cls_StepVisual_CameraModelD3MultiClipping.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_CameraModelD3MultiClipping::get_type_descriptor, "None");
	cls_StepVisual_CameraModelD3MultiClipping.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_CameraModelD3MultiClipping::*)() const ) &StepVisual_CameraModelD3MultiClipping::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_CameraModelD3MultiClippingIntersection.hxx
	py::class_<StepVisual_CameraModelD3MultiClippingIntersection, opencascade::handle<StepVisual_CameraModelD3MultiClippingIntersection>, StepGeom_GeometricRepresentationItem> cls_StepVisual_CameraModelD3MultiClippingIntersection(mod, "StepVisual_CameraModelD3MultiClippingIntersection", "None");
	cls_StepVisual_CameraModelD3MultiClippingIntersection.def(py::init<>());
	cls_StepVisual_CameraModelD3MultiClippingIntersection.def("Init", (void (StepVisual_CameraModelD3MultiClippingIntersection::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect> &)) &StepVisual_CameraModelD3MultiClippingIntersection::Init, "None", py::arg("theName"), py::arg("theShapeClipping"));
	cls_StepVisual_CameraModelD3MultiClippingIntersection.def("SetShapeClipping", (void (StepVisual_CameraModelD3MultiClippingIntersection::*)(const opencascade::handle<StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect> &)) &StepVisual_CameraModelD3MultiClippingIntersection::SetShapeClipping, "None", py::arg("theShapeClipping"));
	cls_StepVisual_CameraModelD3MultiClippingIntersection.def("ShapeClipping", (const opencascade::handle<StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect> (StepVisual_CameraModelD3MultiClippingIntersection::*)()) &StepVisual_CameraModelD3MultiClippingIntersection::ShapeClipping, "None");
	cls_StepVisual_CameraModelD3MultiClippingIntersection.def_static("get_type_name_", (const char * (*)()) &StepVisual_CameraModelD3MultiClippingIntersection::get_type_name, "None");
	cls_StepVisual_CameraModelD3MultiClippingIntersection.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_CameraModelD3MultiClippingIntersection::get_type_descriptor, "None");
	cls_StepVisual_CameraModelD3MultiClippingIntersection.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_CameraModelD3MultiClippingIntersection::*)() const ) &StepVisual_CameraModelD3MultiClippingIntersection::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_CameraModelD3MultiClippingUnion.hxx
	py::class_<StepVisual_CameraModelD3MultiClippingUnion, opencascade::handle<StepVisual_CameraModelD3MultiClippingUnion>, StepGeom_GeometricRepresentationItem> cls_StepVisual_CameraModelD3MultiClippingUnion(mod, "StepVisual_CameraModelD3MultiClippingUnion", "None");
	cls_StepVisual_CameraModelD3MultiClippingUnion.def(py::init<>());
	cls_StepVisual_CameraModelD3MultiClippingUnion.def("Init", (void (StepVisual_CameraModelD3MultiClippingUnion::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_HArray1OfCameraModelD3MultiClippingUnionSelect> &)) &StepVisual_CameraModelD3MultiClippingUnion::Init, "None", py::arg("theName"), py::arg("theShapeClipping"));
	cls_StepVisual_CameraModelD3MultiClippingUnion.def("SetShapeClipping", (void (StepVisual_CameraModelD3MultiClippingUnion::*)(const opencascade::handle<StepVisual_HArray1OfCameraModelD3MultiClippingUnionSelect> &)) &StepVisual_CameraModelD3MultiClippingUnion::SetShapeClipping, "None", py::arg("theShapeClipping"));
	cls_StepVisual_CameraModelD3MultiClippingUnion.def("ShapeClipping", (const opencascade::handle<StepVisual_HArray1OfCameraModelD3MultiClippingUnionSelect> (StepVisual_CameraModelD3MultiClippingUnion::*)()) &StepVisual_CameraModelD3MultiClippingUnion::ShapeClipping, "None");
	cls_StepVisual_CameraModelD3MultiClippingUnion.def_static("get_type_name_", (const char * (*)()) &StepVisual_CameraModelD3MultiClippingUnion::get_type_name, "None");
	cls_StepVisual_CameraModelD3MultiClippingUnion.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_CameraModelD3MultiClippingUnion::get_type_descriptor, "None");
	cls_StepVisual_CameraModelD3MultiClippingUnion.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_CameraModelD3MultiClippingUnion::*)() const ) &StepVisual_CameraModelD3MultiClippingUnion::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_CameraUsage.hxx
	py::class_<StepVisual_CameraUsage, opencascade::handle<StepVisual_CameraUsage>, StepRepr_RepresentationMap> cls_StepVisual_CameraUsage(mod, "StepVisual_CameraUsage", "None");
	cls_StepVisual_CameraUsage.def(py::init<>());
	cls_StepVisual_CameraUsage.def_static("get_type_name_", (const char * (*)()) &StepVisual_CameraUsage::get_type_name, "None");
	cls_StepVisual_CameraUsage.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_CameraUsage::get_type_descriptor, "None");
	cls_StepVisual_CameraUsage.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_CameraUsage::*)() const ) &StepVisual_CameraUsage::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_DraughtingModel.hxx
	py::class_<StepVisual_DraughtingModel, opencascade::handle<StepVisual_DraughtingModel>, StepRepr_Representation> cls_StepVisual_DraughtingModel(mod, "StepVisual_DraughtingModel", "Representation of STEP entity DraughtingModel");
	cls_StepVisual_DraughtingModel.def(py::init<>());
	cls_StepVisual_DraughtingModel.def_static("get_type_name_", (const char * (*)()) &StepVisual_DraughtingModel::get_type_name, "None");
	cls_StepVisual_DraughtingModel.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_DraughtingModel::get_type_descriptor, "None");
	cls_StepVisual_DraughtingModel.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_DraughtingModel::*)() const ) &StepVisual_DraughtingModel::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_BackgroundColour.hxx
	py::class_<StepVisual_BackgroundColour, opencascade::handle<StepVisual_BackgroundColour>, StepVisual_Colour> cls_StepVisual_BackgroundColour(mod, "StepVisual_BackgroundColour", "None");
	cls_StepVisual_BackgroundColour.def(py::init<>());
	cls_StepVisual_BackgroundColour.def("Init", (void (StepVisual_BackgroundColour::*)(const StepVisual_AreaOrView &)) &StepVisual_BackgroundColour::Init, "None", py::arg("aPresentation"));
	cls_StepVisual_BackgroundColour.def("SetPresentation", (void (StepVisual_BackgroundColour::*)(const StepVisual_AreaOrView &)) &StepVisual_BackgroundColour::SetPresentation, "None", py::arg("aPresentation"));
	cls_StepVisual_BackgroundColour.def("Presentation", (StepVisual_AreaOrView (StepVisual_BackgroundColour::*)() const ) &StepVisual_BackgroundColour::Presentation, "None");
	cls_StepVisual_BackgroundColour.def_static("get_type_name_", (const char * (*)()) &StepVisual_BackgroundColour::get_type_name, "None");
	cls_StepVisual_BackgroundColour.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_BackgroundColour::get_type_descriptor, "None");
	cls_StepVisual_BackgroundColour.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_BackgroundColour::*)() const ) &StepVisual_BackgroundColour::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_ColourSpecification.hxx
	py::class_<StepVisual_ColourSpecification, opencascade::handle<StepVisual_ColourSpecification>, StepVisual_Colour> cls_StepVisual_ColourSpecification(mod, "StepVisual_ColourSpecification", "None");
	cls_StepVisual_ColourSpecification.def(py::init<>());
	cls_StepVisual_ColourSpecification.def("Init", (void (StepVisual_ColourSpecification::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepVisual_ColourSpecification::Init, "None", py::arg("aName"));
	cls_StepVisual_ColourSpecification.def("SetName", (void (StepVisual_ColourSpecification::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepVisual_ColourSpecification::SetName, "None", py::arg("aName"));
	cls_StepVisual_ColourSpecification.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepVisual_ColourSpecification::*)() const ) &StepVisual_ColourSpecification::Name, "None");
	cls_StepVisual_ColourSpecification.def_static("get_type_name_", (const char * (*)()) &StepVisual_ColourSpecification::get_type_name, "None");
	cls_StepVisual_ColourSpecification.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_ColourSpecification::get_type_descriptor, "None");
	cls_StepVisual_ColourSpecification.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_ColourSpecification::*)() const ) &StepVisual_ColourSpecification::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_ColourRgb.hxx
	py::class_<StepVisual_ColourRgb, opencascade::handle<StepVisual_ColourRgb>, StepVisual_ColourSpecification> cls_StepVisual_ColourRgb(mod, "StepVisual_ColourRgb", "None");
	cls_StepVisual_ColourRgb.def(py::init<>());
	cls_StepVisual_ColourRgb.def("Init", (void (StepVisual_ColourRgb::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const Standard_Real, const Standard_Real)) &StepVisual_ColourRgb::Init, "None", py::arg("aName"), py::arg("aRed"), py::arg("aGreen"), py::arg("aBlue"));
	cls_StepVisual_ColourRgb.def("SetRed", (void (StepVisual_ColourRgb::*)(const Standard_Real)) &StepVisual_ColourRgb::SetRed, "None", py::arg("aRed"));
	cls_StepVisual_ColourRgb.def("Red", (Standard_Real (StepVisual_ColourRgb::*)() const ) &StepVisual_ColourRgb::Red, "None");
	cls_StepVisual_ColourRgb.def("SetGreen", (void (StepVisual_ColourRgb::*)(const Standard_Real)) &StepVisual_ColourRgb::SetGreen, "None", py::arg("aGreen"));
	cls_StepVisual_ColourRgb.def("Green", (Standard_Real (StepVisual_ColourRgb::*)() const ) &StepVisual_ColourRgb::Green, "None");
	cls_StepVisual_ColourRgb.def("SetBlue", (void (StepVisual_ColourRgb::*)(const Standard_Real)) &StepVisual_ColourRgb::SetBlue, "None", py::arg("aBlue"));
	cls_StepVisual_ColourRgb.def("Blue", (Standard_Real (StepVisual_ColourRgb::*)() const ) &StepVisual_ColourRgb::Blue, "None");
	cls_StepVisual_ColourRgb.def_static("get_type_name_", (const char * (*)()) &StepVisual_ColourRgb::get_type_name, "None");
	cls_StepVisual_ColourRgb.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_ColourRgb::get_type_descriptor, "None");
	cls_StepVisual_ColourRgb.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_ColourRgb::*)() const ) &StepVisual_ColourRgb::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_CompositeText.hxx
	py::class_<StepVisual_CompositeText, opencascade::handle<StepVisual_CompositeText>, StepGeom_GeometricRepresentationItem> cls_StepVisual_CompositeText(mod, "StepVisual_CompositeText", "None");
	cls_StepVisual_CompositeText.def(py::init<>());
	cls_StepVisual_CompositeText.def("Init", (void (StepVisual_CompositeText::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_HArray1OfTextOrCharacter> &)) &StepVisual_CompositeText::Init, "None", py::arg("aName"), py::arg("aCollectedText"));
	cls_StepVisual_CompositeText.def("SetCollectedText", (void (StepVisual_CompositeText::*)(const opencascade::handle<StepVisual_HArray1OfTextOrCharacter> &)) &StepVisual_CompositeText::SetCollectedText, "None", py::arg("aCollectedText"));
	cls_StepVisual_CompositeText.def("CollectedText", (opencascade::handle<StepVisual_HArray1OfTextOrCharacter> (StepVisual_CompositeText::*)() const ) &StepVisual_CompositeText::CollectedText, "None");
	cls_StepVisual_CompositeText.def("CollectedTextValue", (StepVisual_TextOrCharacter (StepVisual_CompositeText::*)(const Standard_Integer) const ) &StepVisual_CompositeText::CollectedTextValue, "None", py::arg("num"));
	cls_StepVisual_CompositeText.def("NbCollectedText", (Standard_Integer (StepVisual_CompositeText::*)() const ) &StepVisual_CompositeText::NbCollectedText, "None");
	cls_StepVisual_CompositeText.def_static("get_type_name_", (const char * (*)()) &StepVisual_CompositeText::get_type_name, "None");
	cls_StepVisual_CompositeText.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_CompositeText::get_type_descriptor, "None");
	cls_StepVisual_CompositeText.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_CompositeText::*)() const ) &StepVisual_CompositeText::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_CompositeTextWithExtent.hxx
	py::class_<StepVisual_CompositeTextWithExtent, opencascade::handle<StepVisual_CompositeTextWithExtent>, StepVisual_CompositeText> cls_StepVisual_CompositeTextWithExtent(mod, "StepVisual_CompositeTextWithExtent", "None");
	cls_StepVisual_CompositeTextWithExtent.def(py::init<>());
	cls_StepVisual_CompositeTextWithExtent.def("Init", (void (StepVisual_CompositeTextWithExtent::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_HArray1OfTextOrCharacter> &, const opencascade::handle<StepVisual_PlanarExtent> &)) &StepVisual_CompositeTextWithExtent::Init, "None", py::arg("aName"), py::arg("aCollectedText"), py::arg("aExtent"));
	cls_StepVisual_CompositeTextWithExtent.def("SetExtent", (void (StepVisual_CompositeTextWithExtent::*)(const opencascade::handle<StepVisual_PlanarExtent> &)) &StepVisual_CompositeTextWithExtent::SetExtent, "None", py::arg("aExtent"));
	cls_StepVisual_CompositeTextWithExtent.def("Extent", (opencascade::handle<StepVisual_PlanarExtent> (StepVisual_CompositeTextWithExtent::*)() const ) &StepVisual_CompositeTextWithExtent::Extent, "None");
	cls_StepVisual_CompositeTextWithExtent.def_static("get_type_name_", (const char * (*)()) &StepVisual_CompositeTextWithExtent::get_type_name, "None");
	cls_StepVisual_CompositeTextWithExtent.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_CompositeTextWithExtent::get_type_descriptor, "None");
	cls_StepVisual_CompositeTextWithExtent.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_CompositeTextWithExtent::*)() const ) &StepVisual_CompositeTextWithExtent::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_Invisibility.hxx
	py::class_<StepVisual_Invisibility, opencascade::handle<StepVisual_Invisibility>, Standard_Transient> cls_StepVisual_Invisibility(mod, "StepVisual_Invisibility", "None");
	cls_StepVisual_Invisibility.def(py::init<>());
	cls_StepVisual_Invisibility.def("Init", (void (StepVisual_Invisibility::*)(const opencascade::handle<StepVisual_HArray1OfInvisibleItem> &)) &StepVisual_Invisibility::Init, "None", py::arg("aInvisibleItems"));
	cls_StepVisual_Invisibility.def("SetInvisibleItems", (void (StepVisual_Invisibility::*)(const opencascade::handle<StepVisual_HArray1OfInvisibleItem> &)) &StepVisual_Invisibility::SetInvisibleItems, "None", py::arg("aInvisibleItems"));
	cls_StepVisual_Invisibility.def("InvisibleItems", (opencascade::handle<StepVisual_HArray1OfInvisibleItem> (StepVisual_Invisibility::*)() const ) &StepVisual_Invisibility::InvisibleItems, "None");
	cls_StepVisual_Invisibility.def("InvisibleItemsValue", (StepVisual_InvisibleItem (StepVisual_Invisibility::*)(const Standard_Integer) const ) &StepVisual_Invisibility::InvisibleItemsValue, "None", py::arg("num"));
	cls_StepVisual_Invisibility.def("NbInvisibleItems", (Standard_Integer (StepVisual_Invisibility::*)() const ) &StepVisual_Invisibility::NbInvisibleItems, "None");
	cls_StepVisual_Invisibility.def_static("get_type_name_", (const char * (*)()) &StepVisual_Invisibility::get_type_name, "None");
	cls_StepVisual_Invisibility.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_Invisibility::get_type_descriptor, "None");
	cls_StepVisual_Invisibility.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_Invisibility::*)() const ) &StepVisual_Invisibility::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_OverRidingStyledItem.hxx
	py::class_<StepVisual_OverRidingStyledItem, opencascade::handle<StepVisual_OverRidingStyledItem>, StepVisual_StyledItem> cls_StepVisual_OverRidingStyledItem(mod, "StepVisual_OverRidingStyledItem", "None");
	cls_StepVisual_OverRidingStyledItem.def(py::init<>());
	cls_StepVisual_OverRidingStyledItem.def("Init", (void (StepVisual_OverRidingStyledItem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_HArray1OfPresentationStyleAssignment> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<StepVisual_StyledItem> &)) &StepVisual_OverRidingStyledItem::Init, "None", py::arg("aName"), py::arg("aStyles"), py::arg("aItem"), py::arg("aOverRiddenStyle"));
	cls_StepVisual_OverRidingStyledItem.def("SetOverRiddenStyle", (void (StepVisual_OverRidingStyledItem::*)(const opencascade::handle<StepVisual_StyledItem> &)) &StepVisual_OverRidingStyledItem::SetOverRiddenStyle, "None", py::arg("aOverRiddenStyle"));
	cls_StepVisual_OverRidingStyledItem.def("OverRiddenStyle", (opencascade::handle<StepVisual_StyledItem> (StepVisual_OverRidingStyledItem::*)() const ) &StepVisual_OverRidingStyledItem::OverRiddenStyle, "None");
	cls_StepVisual_OverRidingStyledItem.def_static("get_type_name_", (const char * (*)()) &StepVisual_OverRidingStyledItem::get_type_name, "None");
	cls_StepVisual_OverRidingStyledItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_OverRidingStyledItem::get_type_descriptor, "None");
	cls_StepVisual_OverRidingStyledItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_OverRidingStyledItem::*)() const ) &StepVisual_OverRidingStyledItem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_TessellatedItem.hxx
	py::class_<StepVisual_TessellatedItem, opencascade::handle<StepVisual_TessellatedItem>, StepGeom_GeometricRepresentationItem> cls_StepVisual_TessellatedItem(mod, "StepVisual_TessellatedItem", "None");
	cls_StepVisual_TessellatedItem.def(py::init<>());
	cls_StepVisual_TessellatedItem.def_static("get_type_name_", (const char * (*)()) &StepVisual_TessellatedItem::get_type_name, "None");
	cls_StepVisual_TessellatedItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_TessellatedItem::get_type_descriptor, "None");
	cls_StepVisual_TessellatedItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_TessellatedItem::*)() const ) &StepVisual_TessellatedItem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_CurveStyle.hxx
	py::class_<StepVisual_CurveStyle, opencascade::handle<StepVisual_CurveStyle>, Standard_Transient> cls_StepVisual_CurveStyle(mod, "StepVisual_CurveStyle", "None");
	cls_StepVisual_CurveStyle.def(py::init<>());
	cls_StepVisual_CurveStyle.def("Init", (void (StepVisual_CurveStyle::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepVisual_CurveStyleFontSelect &, const StepBasic_SizeSelect &, const opencascade::handle<StepVisual_Colour> &)) &StepVisual_CurveStyle::Init, "None", py::arg("aName"), py::arg("aCurveFont"), py::arg("aCurveWidth"), py::arg("aCurveColour"));
	cls_StepVisual_CurveStyle.def("SetName", (void (StepVisual_CurveStyle::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepVisual_CurveStyle::SetName, "None", py::arg("aName"));
	cls_StepVisual_CurveStyle.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepVisual_CurveStyle::*)() const ) &StepVisual_CurveStyle::Name, "None");
	cls_StepVisual_CurveStyle.def("SetCurveFont", (void (StepVisual_CurveStyle::*)(const StepVisual_CurveStyleFontSelect &)) &StepVisual_CurveStyle::SetCurveFont, "None", py::arg("aCurveFont"));
	cls_StepVisual_CurveStyle.def("CurveFont", (StepVisual_CurveStyleFontSelect (StepVisual_CurveStyle::*)() const ) &StepVisual_CurveStyle::CurveFont, "None");
	cls_StepVisual_CurveStyle.def("SetCurveWidth", (void (StepVisual_CurveStyle::*)(const StepBasic_SizeSelect &)) &StepVisual_CurveStyle::SetCurveWidth, "None", py::arg("aCurveWidth"));
	cls_StepVisual_CurveStyle.def("CurveWidth", (StepBasic_SizeSelect (StepVisual_CurveStyle::*)() const ) &StepVisual_CurveStyle::CurveWidth, "None");
	cls_StepVisual_CurveStyle.def("SetCurveColour", (void (StepVisual_CurveStyle::*)(const opencascade::handle<StepVisual_Colour> &)) &StepVisual_CurveStyle::SetCurveColour, "None", py::arg("aCurveColour"));
	cls_StepVisual_CurveStyle.def("CurveColour", (opencascade::handle<StepVisual_Colour> (StepVisual_CurveStyle::*)() const ) &StepVisual_CurveStyle::CurveColour, "None");
	cls_StepVisual_CurveStyle.def_static("get_type_name_", (const char * (*)()) &StepVisual_CurveStyle::get_type_name, "None");
	cls_StepVisual_CurveStyle.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_CurveStyle::get_type_descriptor, "None");
	cls_StepVisual_CurveStyle.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_CurveStyle::*)() const ) &StepVisual_CurveStyle::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_CurveStyleFont.hxx
	py::class_<StepVisual_CurveStyleFont, opencascade::handle<StepVisual_CurveStyleFont>, Standard_Transient> cls_StepVisual_CurveStyleFont(mod, "StepVisual_CurveStyleFont", "None");
	cls_StepVisual_CurveStyleFont.def(py::init<>());
	cls_StepVisual_CurveStyleFont.def("Init", (void (StepVisual_CurveStyleFont::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_HArray1OfCurveStyleFontPattern> &)) &StepVisual_CurveStyleFont::Init, "None", py::arg("aName"), py::arg("aPatternList"));
	cls_StepVisual_CurveStyleFont.def("SetName", (void (StepVisual_CurveStyleFont::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepVisual_CurveStyleFont::SetName, "None", py::arg("aName"));
	cls_StepVisual_CurveStyleFont.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepVisual_CurveStyleFont::*)() const ) &StepVisual_CurveStyleFont::Name, "None");
	cls_StepVisual_CurveStyleFont.def("SetPatternList", (void (StepVisual_CurveStyleFont::*)(const opencascade::handle<StepVisual_HArray1OfCurveStyleFontPattern> &)) &StepVisual_CurveStyleFont::SetPatternList, "None", py::arg("aPatternList"));
	cls_StepVisual_CurveStyleFont.def("PatternList", (opencascade::handle<StepVisual_HArray1OfCurveStyleFontPattern> (StepVisual_CurveStyleFont::*)() const ) &StepVisual_CurveStyleFont::PatternList, "None");
	cls_StepVisual_CurveStyleFont.def("PatternListValue", (opencascade::handle<StepVisual_CurveStyleFontPattern> (StepVisual_CurveStyleFont::*)(const Standard_Integer) const ) &StepVisual_CurveStyleFont::PatternListValue, "None", py::arg("num"));
	cls_StepVisual_CurveStyleFont.def("NbPatternList", (Standard_Integer (StepVisual_CurveStyleFont::*)() const ) &StepVisual_CurveStyleFont::NbPatternList, "None");
	cls_StepVisual_CurveStyleFont.def_static("get_type_name_", (const char * (*)()) &StepVisual_CurveStyleFont::get_type_name, "None");
	cls_StepVisual_CurveStyleFont.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_CurveStyleFont::get_type_descriptor, "None");
	cls_StepVisual_CurveStyleFont.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_CurveStyleFont::*)() const ) &StepVisual_CurveStyleFont::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_CurveStyleFontPattern.hxx
	py::class_<StepVisual_CurveStyleFontPattern, opencascade::handle<StepVisual_CurveStyleFontPattern>, Standard_Transient> cls_StepVisual_CurveStyleFontPattern(mod, "StepVisual_CurveStyleFontPattern", "None");
	cls_StepVisual_CurveStyleFontPattern.def(py::init<>());
	cls_StepVisual_CurveStyleFontPattern.def("Init", (void (StepVisual_CurveStyleFontPattern::*)(const Standard_Real, const Standard_Real)) &StepVisual_CurveStyleFontPattern::Init, "None", py::arg("aVisibleSegmentLength"), py::arg("aInvisibleSegmentLength"));
	cls_StepVisual_CurveStyleFontPattern.def("SetVisibleSegmentLength", (void (StepVisual_CurveStyleFontPattern::*)(const Standard_Real)) &StepVisual_CurveStyleFontPattern::SetVisibleSegmentLength, "None", py::arg("aVisibleSegmentLength"));
	cls_StepVisual_CurveStyleFontPattern.def("VisibleSegmentLength", (Standard_Real (StepVisual_CurveStyleFontPattern::*)() const ) &StepVisual_CurveStyleFontPattern::VisibleSegmentLength, "None");
	cls_StepVisual_CurveStyleFontPattern.def("SetInvisibleSegmentLength", (void (StepVisual_CurveStyleFontPattern::*)(const Standard_Real)) &StepVisual_CurveStyleFontPattern::SetInvisibleSegmentLength, "None", py::arg("aInvisibleSegmentLength"));
	cls_StepVisual_CurveStyleFontPattern.def("InvisibleSegmentLength", (Standard_Real (StepVisual_CurveStyleFontPattern::*)() const ) &StepVisual_CurveStyleFontPattern::InvisibleSegmentLength, "None");
	cls_StepVisual_CurveStyleFontPattern.def_static("get_type_name_", (const char * (*)()) &StepVisual_CurveStyleFontPattern::get_type_name, "None");
	cls_StepVisual_CurveStyleFontPattern.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_CurveStyleFontPattern::get_type_descriptor, "None");
	cls_StepVisual_CurveStyleFontPattern.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_CurveStyleFontPattern::*)() const ) &StepVisual_CurveStyleFontPattern::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_DraughtingCallout.hxx
	py::class_<StepVisual_DraughtingCallout, opencascade::handle<StepVisual_DraughtingCallout>, StepGeom_GeometricRepresentationItem> cls_StepVisual_DraughtingCallout(mod, "StepVisual_DraughtingCallout", "None");
	cls_StepVisual_DraughtingCallout.def(py::init<>());
	cls_StepVisual_DraughtingCallout.def("Init", (void (StepVisual_DraughtingCallout::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_HArray1OfDraughtingCalloutElement> &)) &StepVisual_DraughtingCallout::Init, "Init", py::arg("theName"), py::arg("theContents"));
	cls_StepVisual_DraughtingCallout.def("Contents", (opencascade::handle<StepVisual_HArray1OfDraughtingCalloutElement> (StepVisual_DraughtingCallout::*)() const ) &StepVisual_DraughtingCallout::Contents, "Returns field Contents");
	cls_StepVisual_DraughtingCallout.def("SetContents", (void (StepVisual_DraughtingCallout::*)(const opencascade::handle<StepVisual_HArray1OfDraughtingCalloutElement> &)) &StepVisual_DraughtingCallout::SetContents, "Set field Contents", py::arg("theContents"));
	cls_StepVisual_DraughtingCallout.def("NbContents", (Standard_Integer (StepVisual_DraughtingCallout::*)() const ) &StepVisual_DraughtingCallout::NbContents, "Returns number of Contents");
	cls_StepVisual_DraughtingCallout.def("ContentsValue", (StepVisual_DraughtingCalloutElement (StepVisual_DraughtingCallout::*)(const Standard_Integer) const ) &StepVisual_DraughtingCallout::ContentsValue, "Returns Contents with the given number", py::arg("theNum"));
	cls_StepVisual_DraughtingCallout.def("SetContentsValue", (void (StepVisual_DraughtingCallout::*)(const Standard_Integer, const StepVisual_DraughtingCalloutElement &)) &StepVisual_DraughtingCallout::SetContentsValue, "Sets Contents with given number", py::arg("theNum"), py::arg("theItem"));
	cls_StepVisual_DraughtingCallout.def_static("get_type_name_", (const char * (*)()) &StepVisual_DraughtingCallout::get_type_name, "None");
	cls_StepVisual_DraughtingCallout.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_DraughtingCallout::get_type_descriptor, "None");
	cls_StepVisual_DraughtingCallout.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_DraughtingCallout::*)() const ) &StepVisual_DraughtingCallout::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_CharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation.hxx
	py::class_<StepVisual_CharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation, opencascade::handle<StepVisual_CharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation>, StepVisual_DraughtingModel> cls_StepVisual_CharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation(mod, "StepVisual_CharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation", "Added for Dimensional Tolerances Complex STEP entity Characterized_Object & Characterized_Representation & Draughting_Model & Representation");
	cls_StepVisual_CharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation.def(py::init<>());
	cls_StepVisual_CharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation.def_static("get_type_name_", (const char * (*)()) &StepVisual_CharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation::get_type_name, "None");
	cls_StepVisual_CharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_CharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation::get_type_descriptor, "None");
	cls_StepVisual_CharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_CharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation::*)() const ) &StepVisual_CharacterizedObjectAndCharacterizedRepresentationAndDraughtingModelAndRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_PreDefinedColour.hxx
	py::class_<StepVisual_PreDefinedColour, opencascade::handle<StepVisual_PreDefinedColour>, StepVisual_Colour> cls_StepVisual_PreDefinedColour(mod, "StepVisual_PreDefinedColour", "None");
	cls_StepVisual_PreDefinedColour.def(py::init<>());
	cls_StepVisual_PreDefinedColour.def("SetPreDefinedItem", (void (StepVisual_PreDefinedColour::*)(const opencascade::handle<StepVisual_PreDefinedItem> &)) &StepVisual_PreDefinedColour::SetPreDefinedItem, "set a pre_defined_item part", py::arg("item"));
	cls_StepVisual_PreDefinedColour.def("GetPreDefinedItem", (const opencascade::handle<StepVisual_PreDefinedItem> & (StepVisual_PreDefinedColour::*)() const ) &StepVisual_PreDefinedColour::GetPreDefinedItem, "return a pre_defined_item part");
	cls_StepVisual_PreDefinedColour.def_static("get_type_name_", (const char * (*)()) &StepVisual_PreDefinedColour::get_type_name, "None");
	cls_StepVisual_PreDefinedColour.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_PreDefinedColour::get_type_descriptor, "None");
	cls_StepVisual_PreDefinedColour.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_PreDefinedColour::*)() const ) &StepVisual_PreDefinedColour::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_PreDefinedItem.hxx
	py::class_<StepVisual_PreDefinedItem, opencascade::handle<StepVisual_PreDefinedItem>, Standard_Transient> cls_StepVisual_PreDefinedItem(mod, "StepVisual_PreDefinedItem", "None");
	cls_StepVisual_PreDefinedItem.def(py::init<>());
	cls_StepVisual_PreDefinedItem.def("Init", (void (StepVisual_PreDefinedItem::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepVisual_PreDefinedItem::Init, "None", py::arg("aName"));
	cls_StepVisual_PreDefinedItem.def("SetName", (void (StepVisual_PreDefinedItem::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepVisual_PreDefinedItem::SetName, "None", py::arg("aName"));
	cls_StepVisual_PreDefinedItem.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepVisual_PreDefinedItem::*)() const ) &StepVisual_PreDefinedItem::Name, "None");
	cls_StepVisual_PreDefinedItem.def_static("get_type_name_", (const char * (*)()) &StepVisual_PreDefinedItem::get_type_name, "None");
	cls_StepVisual_PreDefinedItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_PreDefinedItem::get_type_descriptor, "None");
	cls_StepVisual_PreDefinedItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_PreDefinedItem::*)() const ) &StepVisual_PreDefinedItem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_ExternallyDefinedCurveFont.hxx
	py::class_<StepVisual_ExternallyDefinedCurveFont, opencascade::handle<StepVisual_ExternallyDefinedCurveFont>, StepBasic_ExternallyDefinedItem> cls_StepVisual_ExternallyDefinedCurveFont(mod, "StepVisual_ExternallyDefinedCurveFont", "Representation of STEP entity ExternallyDefinedCurveFont");
	cls_StepVisual_ExternallyDefinedCurveFont.def(py::init<>());
	cls_StepVisual_ExternallyDefinedCurveFont.def_static("get_type_name_", (const char * (*)()) &StepVisual_ExternallyDefinedCurveFont::get_type_name, "None");
	cls_StepVisual_ExternallyDefinedCurveFont.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_ExternallyDefinedCurveFont::get_type_descriptor, "None");
	cls_StepVisual_ExternallyDefinedCurveFont.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_ExternallyDefinedCurveFont::*)() const ) &StepVisual_ExternallyDefinedCurveFont::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_FillAreaStyle.hxx
	py::class_<StepVisual_FillAreaStyle, opencascade::handle<StepVisual_FillAreaStyle>, Standard_Transient> cls_StepVisual_FillAreaStyle(mod, "StepVisual_FillAreaStyle", "None");
	cls_StepVisual_FillAreaStyle.def(py::init<>());
	cls_StepVisual_FillAreaStyle.def("Init", (void (StepVisual_FillAreaStyle::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_HArray1OfFillStyleSelect> &)) &StepVisual_FillAreaStyle::Init, "None", py::arg("aName"), py::arg("aFillStyles"));
	cls_StepVisual_FillAreaStyle.def("SetName", (void (StepVisual_FillAreaStyle::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepVisual_FillAreaStyle::SetName, "None", py::arg("aName"));
	cls_StepVisual_FillAreaStyle.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepVisual_FillAreaStyle::*)() const ) &StepVisual_FillAreaStyle::Name, "None");
	cls_StepVisual_FillAreaStyle.def("SetFillStyles", (void (StepVisual_FillAreaStyle::*)(const opencascade::handle<StepVisual_HArray1OfFillStyleSelect> &)) &StepVisual_FillAreaStyle::SetFillStyles, "None", py::arg("aFillStyles"));
	cls_StepVisual_FillAreaStyle.def("FillStyles", (opencascade::handle<StepVisual_HArray1OfFillStyleSelect> (StepVisual_FillAreaStyle::*)() const ) &StepVisual_FillAreaStyle::FillStyles, "None");
	cls_StepVisual_FillAreaStyle.def("FillStylesValue", (StepVisual_FillStyleSelect (StepVisual_FillAreaStyle::*)(const Standard_Integer) const ) &StepVisual_FillAreaStyle::FillStylesValue, "None", py::arg("num"));
	cls_StepVisual_FillAreaStyle.def("NbFillStyles", (Standard_Integer (StepVisual_FillAreaStyle::*)() const ) &StepVisual_FillAreaStyle::NbFillStyles, "None");
	cls_StepVisual_FillAreaStyle.def_static("get_type_name_", (const char * (*)()) &StepVisual_FillAreaStyle::get_type_name, "None");
	cls_StepVisual_FillAreaStyle.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_FillAreaStyle::get_type_descriptor, "None");
	cls_StepVisual_FillAreaStyle.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_FillAreaStyle::*)() const ) &StepVisual_FillAreaStyle::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_FillAreaStyleColour.hxx
	py::class_<StepVisual_FillAreaStyleColour, opencascade::handle<StepVisual_FillAreaStyleColour>, Standard_Transient> cls_StepVisual_FillAreaStyleColour(mod, "StepVisual_FillAreaStyleColour", "None");
	cls_StepVisual_FillAreaStyleColour.def(py::init<>());
	cls_StepVisual_FillAreaStyleColour.def("Init", (void (StepVisual_FillAreaStyleColour::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_Colour> &)) &StepVisual_FillAreaStyleColour::Init, "None", py::arg("aName"), py::arg("aFillColour"));
	cls_StepVisual_FillAreaStyleColour.def("SetName", (void (StepVisual_FillAreaStyleColour::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepVisual_FillAreaStyleColour::SetName, "None", py::arg("aName"));
	cls_StepVisual_FillAreaStyleColour.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepVisual_FillAreaStyleColour::*)() const ) &StepVisual_FillAreaStyleColour::Name, "None");
	cls_StepVisual_FillAreaStyleColour.def("SetFillColour", (void (StepVisual_FillAreaStyleColour::*)(const opencascade::handle<StepVisual_Colour> &)) &StepVisual_FillAreaStyleColour::SetFillColour, "None", py::arg("aFillColour"));
	cls_StepVisual_FillAreaStyleColour.def("FillColour", (opencascade::handle<StepVisual_Colour> (StepVisual_FillAreaStyleColour::*)() const ) &StepVisual_FillAreaStyleColour::FillColour, "None");
	cls_StepVisual_FillAreaStyleColour.def_static("get_type_name_", (const char * (*)()) &StepVisual_FillAreaStyleColour::get_type_name, "None");
	cls_StepVisual_FillAreaStyleColour.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_FillAreaStyleColour::get_type_descriptor, "None");
	cls_StepVisual_FillAreaStyleColour.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_FillAreaStyleColour::*)() const ) &StepVisual_FillAreaStyleColour::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_ContextDependentInvisibility.hxx
	py::class_<StepVisual_ContextDependentInvisibility, opencascade::handle<StepVisual_ContextDependentInvisibility>, StepVisual_Invisibility> cls_StepVisual_ContextDependentInvisibility(mod, "StepVisual_ContextDependentInvisibility", "None");
	cls_StepVisual_ContextDependentInvisibility.def(py::init<>());
	cls_StepVisual_ContextDependentInvisibility.def("Init", (void (StepVisual_ContextDependentInvisibility::*)(const opencascade::handle<StepVisual_HArray1OfInvisibleItem> &, const StepVisual_InvisibilityContext &)) &StepVisual_ContextDependentInvisibility::Init, "None", py::arg("aInvisibleItems"), py::arg("aPresentationContext"));
	cls_StepVisual_ContextDependentInvisibility.def("SetPresentationContext", (void (StepVisual_ContextDependentInvisibility::*)(const StepVisual_InvisibilityContext &)) &StepVisual_ContextDependentInvisibility::SetPresentationContext, "None", py::arg("aPresentationContext"));
	cls_StepVisual_ContextDependentInvisibility.def("PresentationContext", (StepVisual_InvisibilityContext (StepVisual_ContextDependentInvisibility::*)() const ) &StepVisual_ContextDependentInvisibility::PresentationContext, "None");
	cls_StepVisual_ContextDependentInvisibility.def_static("get_type_name_", (const char * (*)()) &StepVisual_ContextDependentInvisibility::get_type_name, "None");
	cls_StepVisual_ContextDependentInvisibility.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_ContextDependentInvisibility::get_type_descriptor, "None");
	cls_StepVisual_ContextDependentInvisibility.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_ContextDependentInvisibility::*)() const ) &StepVisual_ContextDependentInvisibility::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_PresentationRepresentation.hxx
	py::class_<StepVisual_PresentationRepresentation, opencascade::handle<StepVisual_PresentationRepresentation>, StepRepr_Representation> cls_StepVisual_PresentationRepresentation(mod, "StepVisual_PresentationRepresentation", "None");
	cls_StepVisual_PresentationRepresentation.def(py::init<>());
	cls_StepVisual_PresentationRepresentation.def_static("get_type_name_", (const char * (*)()) &StepVisual_PresentationRepresentation::get_type_name, "None");
	cls_StepVisual_PresentationRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_PresentationRepresentation::get_type_descriptor, "None");
	cls_StepVisual_PresentationRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_PresentationRepresentation::*)() const ) &StepVisual_PresentationRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_MechanicalDesignGeometricPresentationRepresentation.hxx
	py::class_<StepVisual_MechanicalDesignGeometricPresentationRepresentation, opencascade::handle<StepVisual_MechanicalDesignGeometricPresentationRepresentation>, StepVisual_PresentationRepresentation> cls_StepVisual_MechanicalDesignGeometricPresentationRepresentation(mod, "StepVisual_MechanicalDesignGeometricPresentationRepresentation", "None");
	cls_StepVisual_MechanicalDesignGeometricPresentationRepresentation.def(py::init<>());
	cls_StepVisual_MechanicalDesignGeometricPresentationRepresentation.def_static("get_type_name_", (const char * (*)()) &StepVisual_MechanicalDesignGeometricPresentationRepresentation::get_type_name, "None");
	cls_StepVisual_MechanicalDesignGeometricPresentationRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_MechanicalDesignGeometricPresentationRepresentation::get_type_descriptor, "None");
	cls_StepVisual_MechanicalDesignGeometricPresentationRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_MechanicalDesignGeometricPresentationRepresentation::*)() const ) &StepVisual_MechanicalDesignGeometricPresentationRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_ContextDependentOverRidingStyledItem.hxx
	py::class_<StepVisual_ContextDependentOverRidingStyledItem, opencascade::handle<StepVisual_ContextDependentOverRidingStyledItem>, StepVisual_OverRidingStyledItem> cls_StepVisual_ContextDependentOverRidingStyledItem(mod, "StepVisual_ContextDependentOverRidingStyledItem", "None");
	cls_StepVisual_ContextDependentOverRidingStyledItem.def(py::init<>());
	cls_StepVisual_ContextDependentOverRidingStyledItem.def("Init", (void (StepVisual_ContextDependentOverRidingStyledItem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_HArray1OfPresentationStyleAssignment> &, const opencascade::handle<Standard_Transient> &, const opencascade::handle<StepVisual_StyledItem> &, const opencascade::handle<StepVisual_HArray1OfStyleContextSelect> &)) &StepVisual_ContextDependentOverRidingStyledItem::Init, "None", py::arg("aName"), py::arg("aStyles"), py::arg("aItem"), py::arg("aOverRiddenStyle"), py::arg("aStyleContext"));
	cls_StepVisual_ContextDependentOverRidingStyledItem.def("SetStyleContext", (void (StepVisual_ContextDependentOverRidingStyledItem::*)(const opencascade::handle<StepVisual_HArray1OfStyleContextSelect> &)) &StepVisual_ContextDependentOverRidingStyledItem::SetStyleContext, "None", py::arg("aStyleContext"));
	cls_StepVisual_ContextDependentOverRidingStyledItem.def("StyleContext", (opencascade::handle<StepVisual_HArray1OfStyleContextSelect> (StepVisual_ContextDependentOverRidingStyledItem::*)() const ) &StepVisual_ContextDependentOverRidingStyledItem::StyleContext, "None");
	cls_StepVisual_ContextDependentOverRidingStyledItem.def("StyleContextValue", (StepVisual_StyleContextSelect (StepVisual_ContextDependentOverRidingStyledItem::*)(const Standard_Integer) const ) &StepVisual_ContextDependentOverRidingStyledItem::StyleContextValue, "None", py::arg("num"));
	cls_StepVisual_ContextDependentOverRidingStyledItem.def("NbStyleContext", (Standard_Integer (StepVisual_ContextDependentOverRidingStyledItem::*)() const ) &StepVisual_ContextDependentOverRidingStyledItem::NbStyleContext, "None");
	cls_StepVisual_ContextDependentOverRidingStyledItem.def_static("get_type_name_", (const char * (*)()) &StepVisual_ContextDependentOverRidingStyledItem::get_type_name, "None");
	cls_StepVisual_ContextDependentOverRidingStyledItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_ContextDependentOverRidingStyledItem::get_type_descriptor, "None");
	cls_StepVisual_ContextDependentOverRidingStyledItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_ContextDependentOverRidingStyledItem::*)() const ) &StepVisual_ContextDependentOverRidingStyledItem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_PlanarExtent.hxx
	py::class_<StepVisual_PlanarExtent, opencascade::handle<StepVisual_PlanarExtent>, StepGeom_GeometricRepresentationItem> cls_StepVisual_PlanarExtent(mod, "StepVisual_PlanarExtent", "None");
	cls_StepVisual_PlanarExtent.def(py::init<>());
	cls_StepVisual_PlanarExtent.def("Init", (void (StepVisual_PlanarExtent::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const Standard_Real)) &StepVisual_PlanarExtent::Init, "None", py::arg("aName"), py::arg("aSizeInX"), py::arg("aSizeInY"));
	cls_StepVisual_PlanarExtent.def("SetSizeInX", (void (StepVisual_PlanarExtent::*)(const Standard_Real)) &StepVisual_PlanarExtent::SetSizeInX, "None", py::arg("aSizeInX"));
	cls_StepVisual_PlanarExtent.def("SizeInX", (Standard_Real (StepVisual_PlanarExtent::*)() const ) &StepVisual_PlanarExtent::SizeInX, "None");
	cls_StepVisual_PlanarExtent.def("SetSizeInY", (void (StepVisual_PlanarExtent::*)(const Standard_Real)) &StepVisual_PlanarExtent::SetSizeInY, "None", py::arg("aSizeInY"));
	cls_StepVisual_PlanarExtent.def("SizeInY", (Standard_Real (StepVisual_PlanarExtent::*)() const ) &StepVisual_PlanarExtent::SizeInY, "None");
	cls_StepVisual_PlanarExtent.def_static("get_type_name_", (const char * (*)()) &StepVisual_PlanarExtent::get_type_name, "None");
	cls_StepVisual_PlanarExtent.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_PlanarExtent::get_type_descriptor, "None");
	cls_StepVisual_PlanarExtent.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_PlanarExtent::*)() const ) &StepVisual_PlanarExtent::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_PlanarBox.hxx
	py::class_<StepVisual_PlanarBox, opencascade::handle<StepVisual_PlanarBox>, StepVisual_PlanarExtent> cls_StepVisual_PlanarBox(mod, "StepVisual_PlanarBox", "None");
	cls_StepVisual_PlanarBox.def(py::init<>());
	cls_StepVisual_PlanarBox.def("Init", (void (StepVisual_PlanarBox::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Real, const Standard_Real, const StepGeom_Axis2Placement &)) &StepVisual_PlanarBox::Init, "None", py::arg("aName"), py::arg("aSizeInX"), py::arg("aSizeInY"), py::arg("aPlacement"));
	cls_StepVisual_PlanarBox.def("SetPlacement", (void (StepVisual_PlanarBox::*)(const StepGeom_Axis2Placement &)) &StepVisual_PlanarBox::SetPlacement, "None", py::arg("aPlacement"));
	cls_StepVisual_PlanarBox.def("Placement", (StepGeom_Axis2Placement (StepVisual_PlanarBox::*)() const ) &StepVisual_PlanarBox::Placement, "None");
	cls_StepVisual_PlanarBox.def_static("get_type_name_", (const char * (*)()) &StepVisual_PlanarBox::get_type_name, "None");
	cls_StepVisual_PlanarBox.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_PlanarBox::get_type_descriptor, "None");
	cls_StepVisual_PlanarBox.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_PlanarBox::*)() const ) &StepVisual_PlanarBox::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_PointStyle.hxx
	py::class_<StepVisual_PointStyle, opencascade::handle<StepVisual_PointStyle>, Standard_Transient> cls_StepVisual_PointStyle(mod, "StepVisual_PointStyle", "None");
	cls_StepVisual_PointStyle.def(py::init<>());
	cls_StepVisual_PointStyle.def("Init", (void (StepVisual_PointStyle::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepVisual_MarkerSelect &, const StepBasic_SizeSelect &, const opencascade::handle<StepVisual_Colour> &)) &StepVisual_PointStyle::Init, "None", py::arg("aName"), py::arg("aMarker"), py::arg("aMarkerSize"), py::arg("aMarkerColour"));
	cls_StepVisual_PointStyle.def("SetName", (void (StepVisual_PointStyle::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepVisual_PointStyle::SetName, "None", py::arg("aName"));
	cls_StepVisual_PointStyle.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepVisual_PointStyle::*)() const ) &StepVisual_PointStyle::Name, "None");
	cls_StepVisual_PointStyle.def("SetMarker", (void (StepVisual_PointStyle::*)(const StepVisual_MarkerSelect &)) &StepVisual_PointStyle::SetMarker, "None", py::arg("aMarker"));
	cls_StepVisual_PointStyle.def("Marker", (StepVisual_MarkerSelect (StepVisual_PointStyle::*)() const ) &StepVisual_PointStyle::Marker, "None");
	cls_StepVisual_PointStyle.def("SetMarkerSize", (void (StepVisual_PointStyle::*)(const StepBasic_SizeSelect &)) &StepVisual_PointStyle::SetMarkerSize, "None", py::arg("aMarkerSize"));
	cls_StepVisual_PointStyle.def("MarkerSize", (StepBasic_SizeSelect (StepVisual_PointStyle::*)() const ) &StepVisual_PointStyle::MarkerSize, "None");
	cls_StepVisual_PointStyle.def("SetMarkerColour", (void (StepVisual_PointStyle::*)(const opencascade::handle<StepVisual_Colour> &)) &StepVisual_PointStyle::SetMarkerColour, "None", py::arg("aMarkerColour"));
	cls_StepVisual_PointStyle.def("MarkerColour", (opencascade::handle<StepVisual_Colour> (StepVisual_PointStyle::*)() const ) &StepVisual_PointStyle::MarkerColour, "None");
	cls_StepVisual_PointStyle.def_static("get_type_name_", (const char * (*)()) &StepVisual_PointStyle::get_type_name, "None");
	cls_StepVisual_PointStyle.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_PointStyle::get_type_descriptor, "None");
	cls_StepVisual_PointStyle.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_PointStyle::*)() const ) &StepVisual_PointStyle::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_DraughtingPreDefinedColour.hxx
	py::class_<StepVisual_DraughtingPreDefinedColour, opencascade::handle<StepVisual_DraughtingPreDefinedColour>, StepVisual_PreDefinedColour> cls_StepVisual_DraughtingPreDefinedColour(mod, "StepVisual_DraughtingPreDefinedColour", "None");
	cls_StepVisual_DraughtingPreDefinedColour.def(py::init<>());
	cls_StepVisual_DraughtingPreDefinedColour.def_static("get_type_name_", (const char * (*)()) &StepVisual_DraughtingPreDefinedColour::get_type_name, "None");
	cls_StepVisual_DraughtingPreDefinedColour.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_DraughtingPreDefinedColour::get_type_descriptor, "None");
	cls_StepVisual_DraughtingPreDefinedColour.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_DraughtingPreDefinedColour::*)() const ) &StepVisual_DraughtingPreDefinedColour::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_PreDefinedCurveFont.hxx
	py::class_<StepVisual_PreDefinedCurveFont, opencascade::handle<StepVisual_PreDefinedCurveFont>, StepVisual_PreDefinedItem> cls_StepVisual_PreDefinedCurveFont(mod, "StepVisual_PreDefinedCurveFont", "None");
	cls_StepVisual_PreDefinedCurveFont.def(py::init<>());
	cls_StepVisual_PreDefinedCurveFont.def_static("get_type_name_", (const char * (*)()) &StepVisual_PreDefinedCurveFont::get_type_name, "None");
	cls_StepVisual_PreDefinedCurveFont.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_PreDefinedCurveFont::get_type_descriptor, "None");
	cls_StepVisual_PreDefinedCurveFont.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_PreDefinedCurveFont::*)() const ) &StepVisual_PreDefinedCurveFont::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_DraughtingPreDefinedCurveFont.hxx
	py::class_<StepVisual_DraughtingPreDefinedCurveFont, opencascade::handle<StepVisual_DraughtingPreDefinedCurveFont>, StepVisual_PreDefinedCurveFont> cls_StepVisual_DraughtingPreDefinedCurveFont(mod, "StepVisual_DraughtingPreDefinedCurveFont", "None");
	cls_StepVisual_DraughtingPreDefinedCurveFont.def(py::init<>());
	cls_StepVisual_DraughtingPreDefinedCurveFont.def_static("get_type_name_", (const char * (*)()) &StepVisual_DraughtingPreDefinedCurveFont::get_type_name, "None");
	cls_StepVisual_DraughtingPreDefinedCurveFont.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_DraughtingPreDefinedCurveFont::get_type_descriptor, "None");
	cls_StepVisual_DraughtingPreDefinedCurveFont.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_DraughtingPreDefinedCurveFont::*)() const ) &StepVisual_DraughtingPreDefinedCurveFont::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_PresentationArea.hxx
	py::class_<StepVisual_PresentationArea, opencascade::handle<StepVisual_PresentationArea>, StepVisual_PresentationRepresentation> cls_StepVisual_PresentationArea(mod, "StepVisual_PresentationArea", "None");
	cls_StepVisual_PresentationArea.def(py::init<>());
	cls_StepVisual_PresentationArea.def_static("get_type_name_", (const char * (*)()) &StepVisual_PresentationArea::get_type_name, "None");
	cls_StepVisual_PresentationArea.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_PresentationArea::get_type_descriptor, "None");
	cls_StepVisual_PresentationArea.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_PresentationArea::*)() const ) &StepVisual_PresentationArea::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_PresentationLayerAssignment.hxx
	py::class_<StepVisual_PresentationLayerAssignment, opencascade::handle<StepVisual_PresentationLayerAssignment>, Standard_Transient> cls_StepVisual_PresentationLayerAssignment(mod, "StepVisual_PresentationLayerAssignment", "None");
	cls_StepVisual_PresentationLayerAssignment.def(py::init<>());
	cls_StepVisual_PresentationLayerAssignment.def("Init", (void (StepVisual_PresentationLayerAssignment::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_HArray1OfLayeredItem> &)) &StepVisual_PresentationLayerAssignment::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aAssignedItems"));
	cls_StepVisual_PresentationLayerAssignment.def("SetName", (void (StepVisual_PresentationLayerAssignment::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepVisual_PresentationLayerAssignment::SetName, "None", py::arg("aName"));
	cls_StepVisual_PresentationLayerAssignment.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepVisual_PresentationLayerAssignment::*)() const ) &StepVisual_PresentationLayerAssignment::Name, "None");
	cls_StepVisual_PresentationLayerAssignment.def("SetDescription", (void (StepVisual_PresentationLayerAssignment::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepVisual_PresentationLayerAssignment::SetDescription, "None", py::arg("aDescription"));
	cls_StepVisual_PresentationLayerAssignment.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepVisual_PresentationLayerAssignment::*)() const ) &StepVisual_PresentationLayerAssignment::Description, "None");
	cls_StepVisual_PresentationLayerAssignment.def("SetAssignedItems", (void (StepVisual_PresentationLayerAssignment::*)(const opencascade::handle<StepVisual_HArray1OfLayeredItem> &)) &StepVisual_PresentationLayerAssignment::SetAssignedItems, "None", py::arg("aAssignedItems"));
	cls_StepVisual_PresentationLayerAssignment.def("AssignedItems", (opencascade::handle<StepVisual_HArray1OfLayeredItem> (StepVisual_PresentationLayerAssignment::*)() const ) &StepVisual_PresentationLayerAssignment::AssignedItems, "None");
	cls_StepVisual_PresentationLayerAssignment.def("AssignedItemsValue", (StepVisual_LayeredItem (StepVisual_PresentationLayerAssignment::*)(const Standard_Integer) const ) &StepVisual_PresentationLayerAssignment::AssignedItemsValue, "None", py::arg("num"));
	cls_StepVisual_PresentationLayerAssignment.def("NbAssignedItems", (Standard_Integer (StepVisual_PresentationLayerAssignment::*)() const ) &StepVisual_PresentationLayerAssignment::NbAssignedItems, "None");
	cls_StepVisual_PresentationLayerAssignment.def_static("get_type_name_", (const char * (*)()) &StepVisual_PresentationLayerAssignment::get_type_name, "None");
	cls_StepVisual_PresentationLayerAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_PresentationLayerAssignment::get_type_descriptor, "None");
	cls_StepVisual_PresentationLayerAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_PresentationLayerAssignment::*)() const ) &StepVisual_PresentationLayerAssignment::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_PresentationLayerUsage.hxx
	py::class_<StepVisual_PresentationLayerUsage, opencascade::handle<StepVisual_PresentationLayerUsage>, Standard_Transient> cls_StepVisual_PresentationLayerUsage(mod, "StepVisual_PresentationLayerUsage", "Added from StepVisual Rev2 to Rev4");
	cls_StepVisual_PresentationLayerUsage.def(py::init<>());
	cls_StepVisual_PresentationLayerUsage.def("Init", (void (StepVisual_PresentationLayerUsage::*)(const opencascade::handle<StepVisual_PresentationLayerAssignment> &, const opencascade::handle<StepVisual_PresentationRepresentation> &)) &StepVisual_PresentationLayerUsage::Init, "None", py::arg("aAssignment"), py::arg("aPresentation"));
	cls_StepVisual_PresentationLayerUsage.def("SetAssignment", (void (StepVisual_PresentationLayerUsage::*)(const opencascade::handle<StepVisual_PresentationLayerAssignment> &)) &StepVisual_PresentationLayerUsage::SetAssignment, "None", py::arg("aAssignment"));
	cls_StepVisual_PresentationLayerUsage.def("Assignment", (opencascade::handle<StepVisual_PresentationLayerAssignment> (StepVisual_PresentationLayerUsage::*)() const ) &StepVisual_PresentationLayerUsage::Assignment, "None");
	cls_StepVisual_PresentationLayerUsage.def("SetPresentation", (void (StepVisual_PresentationLayerUsage::*)(const opencascade::handle<StepVisual_PresentationRepresentation> &)) &StepVisual_PresentationLayerUsage::SetPresentation, "None", py::arg("aPresentation"));
	cls_StepVisual_PresentationLayerUsage.def("Presentation", (opencascade::handle<StepVisual_PresentationRepresentation> (StepVisual_PresentationLayerUsage::*)() const ) &StepVisual_PresentationLayerUsage::Presentation, "None");
	cls_StepVisual_PresentationLayerUsage.def_static("get_type_name_", (const char * (*)()) &StepVisual_PresentationLayerUsage::get_type_name, "None");
	cls_StepVisual_PresentationLayerUsage.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_PresentationLayerUsage::get_type_descriptor, "None");
	cls_StepVisual_PresentationLayerUsage.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_PresentationLayerUsage::*)() const ) &StepVisual_PresentationLayerUsage::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_MechanicalDesignGeometricPresentationArea.hxx
	py::class_<StepVisual_MechanicalDesignGeometricPresentationArea, opencascade::handle<StepVisual_MechanicalDesignGeometricPresentationArea>, StepVisual_PresentationArea> cls_StepVisual_MechanicalDesignGeometricPresentationArea(mod, "StepVisual_MechanicalDesignGeometricPresentationArea", "None");
	cls_StepVisual_MechanicalDesignGeometricPresentationArea.def(py::init<>());
	cls_StepVisual_MechanicalDesignGeometricPresentationArea.def_static("get_type_name_", (const char * (*)()) &StepVisual_MechanicalDesignGeometricPresentationArea::get_type_name, "None");
	cls_StepVisual_MechanicalDesignGeometricPresentationArea.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_MechanicalDesignGeometricPresentationArea::get_type_descriptor, "None");
	cls_StepVisual_MechanicalDesignGeometricPresentationArea.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_MechanicalDesignGeometricPresentationArea::*)() const ) &StepVisual_MechanicalDesignGeometricPresentationArea::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_PresentationSet.hxx
	py::class_<StepVisual_PresentationSet, opencascade::handle<StepVisual_PresentationSet>, Standard_Transient> cls_StepVisual_PresentationSet(mod, "StepVisual_PresentationSet", "None");
	cls_StepVisual_PresentationSet.def(py::init<>());
	cls_StepVisual_PresentationSet.def_static("get_type_name_", (const char * (*)()) &StepVisual_PresentationSet::get_type_name, "None");
	cls_StepVisual_PresentationSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_PresentationSet::get_type_descriptor, "None");
	cls_StepVisual_PresentationSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_PresentationSet::*)() const ) &StepVisual_PresentationSet::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_PresentationSize.hxx
	py::class_<StepVisual_PresentationSize, opencascade::handle<StepVisual_PresentationSize>, Standard_Transient> cls_StepVisual_PresentationSize(mod, "StepVisual_PresentationSize", "None");
	cls_StepVisual_PresentationSize.def(py::init<>());
	cls_StepVisual_PresentationSize.def("Init", (void (StepVisual_PresentationSize::*)(const StepVisual_PresentationSizeAssignmentSelect &, const opencascade::handle<StepVisual_PlanarBox> &)) &StepVisual_PresentationSize::Init, "None", py::arg("aUnit"), py::arg("aSize"));
	cls_StepVisual_PresentationSize.def("SetUnit", (void (StepVisual_PresentationSize::*)(const StepVisual_PresentationSizeAssignmentSelect &)) &StepVisual_PresentationSize::SetUnit, "None", py::arg("aUnit"));
	cls_StepVisual_PresentationSize.def("Unit", (StepVisual_PresentationSizeAssignmentSelect (StepVisual_PresentationSize::*)() const ) &StepVisual_PresentationSize::Unit, "None");
	cls_StepVisual_PresentationSize.def("SetSize", (void (StepVisual_PresentationSize::*)(const opencascade::handle<StepVisual_PlanarBox> &)) &StepVisual_PresentationSize::SetSize, "None", py::arg("aSize"));
	cls_StepVisual_PresentationSize.def("Size", (opencascade::handle<StepVisual_PlanarBox> (StepVisual_PresentationSize::*)() const ) &StepVisual_PresentationSize::Size, "None");
	cls_StepVisual_PresentationSize.def_static("get_type_name_", (const char * (*)()) &StepVisual_PresentationSize::get_type_name, "None");
	cls_StepVisual_PresentationSize.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_PresentationSize::get_type_descriptor, "None");
	cls_StepVisual_PresentationSize.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_PresentationSize::*)() const ) &StepVisual_PresentationSize::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_PresentationStyleAssignment.hxx
	py::class_<StepVisual_PresentationStyleAssignment, opencascade::handle<StepVisual_PresentationStyleAssignment>, Standard_Transient> cls_StepVisual_PresentationStyleAssignment(mod, "StepVisual_PresentationStyleAssignment", "None");
	cls_StepVisual_PresentationStyleAssignment.def(py::init<>());
	cls_StepVisual_PresentationStyleAssignment.def("Init", (void (StepVisual_PresentationStyleAssignment::*)(const opencascade::handle<StepVisual_HArray1OfPresentationStyleSelect> &)) &StepVisual_PresentationStyleAssignment::Init, "None", py::arg("aStyles"));
	cls_StepVisual_PresentationStyleAssignment.def("SetStyles", (void (StepVisual_PresentationStyleAssignment::*)(const opencascade::handle<StepVisual_HArray1OfPresentationStyleSelect> &)) &StepVisual_PresentationStyleAssignment::SetStyles, "None", py::arg("aStyles"));
	cls_StepVisual_PresentationStyleAssignment.def("Styles", (opencascade::handle<StepVisual_HArray1OfPresentationStyleSelect> (StepVisual_PresentationStyleAssignment::*)() const ) &StepVisual_PresentationStyleAssignment::Styles, "None");
	cls_StepVisual_PresentationStyleAssignment.def("StylesValue", (StepVisual_PresentationStyleSelect (StepVisual_PresentationStyleAssignment::*)(const Standard_Integer) const ) &StepVisual_PresentationStyleAssignment::StylesValue, "None", py::arg("num"));
	cls_StepVisual_PresentationStyleAssignment.def("NbStyles", (Standard_Integer (StepVisual_PresentationStyleAssignment::*)() const ) &StepVisual_PresentationStyleAssignment::NbStyles, "None");
	cls_StepVisual_PresentationStyleAssignment.def_static("get_type_name_", (const char * (*)()) &StepVisual_PresentationStyleAssignment::get_type_name, "None");
	cls_StepVisual_PresentationStyleAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_PresentationStyleAssignment::get_type_descriptor, "None");
	cls_StepVisual_PresentationStyleAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_PresentationStyleAssignment::*)() const ) &StepVisual_PresentationStyleAssignment::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_PresentationStyleByContext.hxx
	py::class_<StepVisual_PresentationStyleByContext, opencascade::handle<StepVisual_PresentationStyleByContext>, StepVisual_PresentationStyleAssignment> cls_StepVisual_PresentationStyleByContext(mod, "StepVisual_PresentationStyleByContext", "None");
	cls_StepVisual_PresentationStyleByContext.def(py::init<>());
	cls_StepVisual_PresentationStyleByContext.def("Init", (void (StepVisual_PresentationStyleByContext::*)(const opencascade::handle<StepVisual_HArray1OfPresentationStyleSelect> &, const StepVisual_StyleContextSelect &)) &StepVisual_PresentationStyleByContext::Init, "None", py::arg("aStyles"), py::arg("aStyleContext"));
	cls_StepVisual_PresentationStyleByContext.def("SetStyleContext", (void (StepVisual_PresentationStyleByContext::*)(const StepVisual_StyleContextSelect &)) &StepVisual_PresentationStyleByContext::SetStyleContext, "None", py::arg("aStyleContext"));
	cls_StepVisual_PresentationStyleByContext.def("StyleContext", (StepVisual_StyleContextSelect (StepVisual_PresentationStyleByContext::*)() const ) &StepVisual_PresentationStyleByContext::StyleContext, "None");
	cls_StepVisual_PresentationStyleByContext.def_static("get_type_name_", (const char * (*)()) &StepVisual_PresentationStyleByContext::get_type_name, "None");
	cls_StepVisual_PresentationStyleByContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_PresentationStyleByContext::get_type_descriptor, "None");
	cls_StepVisual_PresentationStyleByContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_PresentationStyleByContext::*)() const ) &StepVisual_PresentationStyleByContext::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_PresentationView.hxx
	py::class_<StepVisual_PresentationView, opencascade::handle<StepVisual_PresentationView>, StepVisual_PresentationRepresentation> cls_StepVisual_PresentationView(mod, "StepVisual_PresentationView", "None");
	cls_StepVisual_PresentationView.def(py::init<>());
	cls_StepVisual_PresentationView.def_static("get_type_name_", (const char * (*)()) &StepVisual_PresentationView::get_type_name, "None");
	cls_StepVisual_PresentationView.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_PresentationView::get_type_descriptor, "None");
	cls_StepVisual_PresentationView.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_PresentationView::*)() const ) &StepVisual_PresentationView::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_PresentedItemRepresentation.hxx
	py::class_<StepVisual_PresentedItemRepresentation, opencascade::handle<StepVisual_PresentedItemRepresentation>, Standard_Transient> cls_StepVisual_PresentedItemRepresentation(mod, "StepVisual_PresentedItemRepresentation", "Added from StepVisual Rev2 to Rev4");
	cls_StepVisual_PresentedItemRepresentation.def(py::init<>());
	cls_StepVisual_PresentedItemRepresentation.def("Init", (void (StepVisual_PresentedItemRepresentation::*)(const StepVisual_PresentationRepresentationSelect &, const opencascade::handle<StepVisual_PresentedItem> &)) &StepVisual_PresentedItemRepresentation::Init, "None", py::arg("aPresentation"), py::arg("aItem"));
	cls_StepVisual_PresentedItemRepresentation.def("SetPresentation", (void (StepVisual_PresentedItemRepresentation::*)(const StepVisual_PresentationRepresentationSelect &)) &StepVisual_PresentedItemRepresentation::SetPresentation, "None", py::arg("aPresentation"));
	cls_StepVisual_PresentedItemRepresentation.def("Presentation", (StepVisual_PresentationRepresentationSelect (StepVisual_PresentedItemRepresentation::*)() const ) &StepVisual_PresentedItemRepresentation::Presentation, "None");
	cls_StepVisual_PresentedItemRepresentation.def("SetItem", (void (StepVisual_PresentedItemRepresentation::*)(const opencascade::handle<StepVisual_PresentedItem> &)) &StepVisual_PresentedItemRepresentation::SetItem, "None", py::arg("aItem"));
	cls_StepVisual_PresentedItemRepresentation.def("Item", (opencascade::handle<StepVisual_PresentedItem> (StepVisual_PresentedItemRepresentation::*)() const ) &StepVisual_PresentedItemRepresentation::Item, "None");
	cls_StepVisual_PresentedItemRepresentation.def_static("get_type_name_", (const char * (*)()) &StepVisual_PresentedItemRepresentation::get_type_name, "None");
	cls_StepVisual_PresentedItemRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_PresentedItemRepresentation::get_type_descriptor, "None");
	cls_StepVisual_PresentedItemRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_PresentedItemRepresentation::*)() const ) &StepVisual_PresentedItemRepresentation::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_AnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem.hxx
	py::class_<StepVisual_AnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem, opencascade::handle<StepVisual_AnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem>, StepVisual_AnnotationCurveOccurrence> cls_StepVisual_AnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem(mod, "StepVisual_AnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem", "Added for Dimensional Tolerances Complex STEP entity AnnotationCurveOccurrence & AnnotationOccurrence & GeometricRepresentationItem & RepresentationItem & StyledItem");
	cls_StepVisual_AnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem.def(py::init<>());
	cls_StepVisual_AnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem.def_static("get_type_name_", (const char * (*)()) &StepVisual_AnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem::get_type_name, "None");
	cls_StepVisual_AnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_AnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem::get_type_descriptor, "None");
	cls_StepVisual_AnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_AnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem::*)() const ) &StepVisual_AnnotationCurveOccurrenceAndAnnotationOccurrenceAndGeomReprItemAndReprItemAndStyledItem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_SurfaceSideStyle.hxx
	py::class_<StepVisual_SurfaceSideStyle, opencascade::handle<StepVisual_SurfaceSideStyle>, Standard_Transient> cls_StepVisual_SurfaceSideStyle(mod, "StepVisual_SurfaceSideStyle", "None");
	cls_StepVisual_SurfaceSideStyle.def(py::init<>());
	cls_StepVisual_SurfaceSideStyle.def("Init", (void (StepVisual_SurfaceSideStyle::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_HArray1OfSurfaceStyleElementSelect> &)) &StepVisual_SurfaceSideStyle::Init, "None", py::arg("aName"), py::arg("aStyles"));
	cls_StepVisual_SurfaceSideStyle.def("SetName", (void (StepVisual_SurfaceSideStyle::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepVisual_SurfaceSideStyle::SetName, "None", py::arg("aName"));
	cls_StepVisual_SurfaceSideStyle.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepVisual_SurfaceSideStyle::*)() const ) &StepVisual_SurfaceSideStyle::Name, "None");
	cls_StepVisual_SurfaceSideStyle.def("SetStyles", (void (StepVisual_SurfaceSideStyle::*)(const opencascade::handle<StepVisual_HArray1OfSurfaceStyleElementSelect> &)) &StepVisual_SurfaceSideStyle::SetStyles, "None", py::arg("aStyles"));
	cls_StepVisual_SurfaceSideStyle.def("Styles", (opencascade::handle<StepVisual_HArray1OfSurfaceStyleElementSelect> (StepVisual_SurfaceSideStyle::*)() const ) &StepVisual_SurfaceSideStyle::Styles, "None");
	cls_StepVisual_SurfaceSideStyle.def("StylesValue", (StepVisual_SurfaceStyleElementSelect (StepVisual_SurfaceSideStyle::*)(const Standard_Integer) const ) &StepVisual_SurfaceSideStyle::StylesValue, "None", py::arg("num"));
	cls_StepVisual_SurfaceSideStyle.def("NbStyles", (Standard_Integer (StepVisual_SurfaceSideStyle::*)() const ) &StepVisual_SurfaceSideStyle::NbStyles, "None");
	cls_StepVisual_SurfaceSideStyle.def_static("get_type_name_", (const char * (*)()) &StepVisual_SurfaceSideStyle::get_type_name, "None");
	cls_StepVisual_SurfaceSideStyle.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_SurfaceSideStyle::get_type_descriptor, "None");
	cls_StepVisual_SurfaceSideStyle.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_SurfaceSideStyle::*)() const ) &StepVisual_SurfaceSideStyle::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_SurfaceStyleBoundary.hxx
	py::class_<StepVisual_SurfaceStyleBoundary, opencascade::handle<StepVisual_SurfaceStyleBoundary>, Standard_Transient> cls_StepVisual_SurfaceStyleBoundary(mod, "StepVisual_SurfaceStyleBoundary", "None");
	cls_StepVisual_SurfaceStyleBoundary.def(py::init<>());
	cls_StepVisual_SurfaceStyleBoundary.def("Init", (void (StepVisual_SurfaceStyleBoundary::*)(const opencascade::handle<StepVisual_CurveStyle> &)) &StepVisual_SurfaceStyleBoundary::Init, "None", py::arg("aStyleOfBoundary"));
	cls_StepVisual_SurfaceStyleBoundary.def("SetStyleOfBoundary", (void (StepVisual_SurfaceStyleBoundary::*)(const opencascade::handle<StepVisual_CurveStyle> &)) &StepVisual_SurfaceStyleBoundary::SetStyleOfBoundary, "None", py::arg("aStyleOfBoundary"));
	cls_StepVisual_SurfaceStyleBoundary.def("StyleOfBoundary", (opencascade::handle<StepVisual_CurveStyle> (StepVisual_SurfaceStyleBoundary::*)() const ) &StepVisual_SurfaceStyleBoundary::StyleOfBoundary, "None");
	cls_StepVisual_SurfaceStyleBoundary.def_static("get_type_name_", (const char * (*)()) &StepVisual_SurfaceStyleBoundary::get_type_name, "None");
	cls_StepVisual_SurfaceStyleBoundary.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_SurfaceStyleBoundary::get_type_descriptor, "None");
	cls_StepVisual_SurfaceStyleBoundary.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_SurfaceStyleBoundary::*)() const ) &StepVisual_SurfaceStyleBoundary::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_SurfaceStyleControlGrid.hxx
	py::class_<StepVisual_SurfaceStyleControlGrid, opencascade::handle<StepVisual_SurfaceStyleControlGrid>, Standard_Transient> cls_StepVisual_SurfaceStyleControlGrid(mod, "StepVisual_SurfaceStyleControlGrid", "None");
	cls_StepVisual_SurfaceStyleControlGrid.def(py::init<>());
	cls_StepVisual_SurfaceStyleControlGrid.def("Init", (void (StepVisual_SurfaceStyleControlGrid::*)(const opencascade::handle<StepVisual_CurveStyle> &)) &StepVisual_SurfaceStyleControlGrid::Init, "None", py::arg("aStyleOfControlGrid"));
	cls_StepVisual_SurfaceStyleControlGrid.def("SetStyleOfControlGrid", (void (StepVisual_SurfaceStyleControlGrid::*)(const opencascade::handle<StepVisual_CurveStyle> &)) &StepVisual_SurfaceStyleControlGrid::SetStyleOfControlGrid, "None", py::arg("aStyleOfControlGrid"));
	cls_StepVisual_SurfaceStyleControlGrid.def("StyleOfControlGrid", (opencascade::handle<StepVisual_CurveStyle> (StepVisual_SurfaceStyleControlGrid::*)() const ) &StepVisual_SurfaceStyleControlGrid::StyleOfControlGrid, "None");
	cls_StepVisual_SurfaceStyleControlGrid.def_static("get_type_name_", (const char * (*)()) &StepVisual_SurfaceStyleControlGrid::get_type_name, "None");
	cls_StepVisual_SurfaceStyleControlGrid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_SurfaceStyleControlGrid::get_type_descriptor, "None");
	cls_StepVisual_SurfaceStyleControlGrid.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_SurfaceStyleControlGrid::*)() const ) &StepVisual_SurfaceStyleControlGrid::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_SurfaceStyleFillArea.hxx
	py::class_<StepVisual_SurfaceStyleFillArea, opencascade::handle<StepVisual_SurfaceStyleFillArea>, Standard_Transient> cls_StepVisual_SurfaceStyleFillArea(mod, "StepVisual_SurfaceStyleFillArea", "None");
	cls_StepVisual_SurfaceStyleFillArea.def(py::init<>());
	cls_StepVisual_SurfaceStyleFillArea.def("Init", (void (StepVisual_SurfaceStyleFillArea::*)(const opencascade::handle<StepVisual_FillAreaStyle> &)) &StepVisual_SurfaceStyleFillArea::Init, "None", py::arg("aFillArea"));
	cls_StepVisual_SurfaceStyleFillArea.def("SetFillArea", (void (StepVisual_SurfaceStyleFillArea::*)(const opencascade::handle<StepVisual_FillAreaStyle> &)) &StepVisual_SurfaceStyleFillArea::SetFillArea, "None", py::arg("aFillArea"));
	cls_StepVisual_SurfaceStyleFillArea.def("FillArea", (opencascade::handle<StepVisual_FillAreaStyle> (StepVisual_SurfaceStyleFillArea::*)() const ) &StepVisual_SurfaceStyleFillArea::FillArea, "None");
	cls_StepVisual_SurfaceStyleFillArea.def_static("get_type_name_", (const char * (*)()) &StepVisual_SurfaceStyleFillArea::get_type_name, "None");
	cls_StepVisual_SurfaceStyleFillArea.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_SurfaceStyleFillArea::get_type_descriptor, "None");
	cls_StepVisual_SurfaceStyleFillArea.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_SurfaceStyleFillArea::*)() const ) &StepVisual_SurfaceStyleFillArea::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_SurfaceStyleParameterLine.hxx
	py::class_<StepVisual_SurfaceStyleParameterLine, opencascade::handle<StepVisual_SurfaceStyleParameterLine>, Standard_Transient> cls_StepVisual_SurfaceStyleParameterLine(mod, "StepVisual_SurfaceStyleParameterLine", "None");
	cls_StepVisual_SurfaceStyleParameterLine.def(py::init<>());
	cls_StepVisual_SurfaceStyleParameterLine.def("Init", (void (StepVisual_SurfaceStyleParameterLine::*)(const opencascade::handle<StepVisual_CurveStyle> &, const opencascade::handle<StepVisual_HArray1OfDirectionCountSelect> &)) &StepVisual_SurfaceStyleParameterLine::Init, "None", py::arg("aStyleOfParameterLines"), py::arg("aDirectionCounts"));
	cls_StepVisual_SurfaceStyleParameterLine.def("SetStyleOfParameterLines", (void (StepVisual_SurfaceStyleParameterLine::*)(const opencascade::handle<StepVisual_CurveStyle> &)) &StepVisual_SurfaceStyleParameterLine::SetStyleOfParameterLines, "None", py::arg("aStyleOfParameterLines"));
	cls_StepVisual_SurfaceStyleParameterLine.def("StyleOfParameterLines", (opencascade::handle<StepVisual_CurveStyle> (StepVisual_SurfaceStyleParameterLine::*)() const ) &StepVisual_SurfaceStyleParameterLine::StyleOfParameterLines, "None");
	cls_StepVisual_SurfaceStyleParameterLine.def("SetDirectionCounts", (void (StepVisual_SurfaceStyleParameterLine::*)(const opencascade::handle<StepVisual_HArray1OfDirectionCountSelect> &)) &StepVisual_SurfaceStyleParameterLine::SetDirectionCounts, "None", py::arg("aDirectionCounts"));
	cls_StepVisual_SurfaceStyleParameterLine.def("DirectionCounts", (opencascade::handle<StepVisual_HArray1OfDirectionCountSelect> (StepVisual_SurfaceStyleParameterLine::*)() const ) &StepVisual_SurfaceStyleParameterLine::DirectionCounts, "None");
	cls_StepVisual_SurfaceStyleParameterLine.def("DirectionCountsValue", (StepVisual_DirectionCountSelect (StepVisual_SurfaceStyleParameterLine::*)(const Standard_Integer) const ) &StepVisual_SurfaceStyleParameterLine::DirectionCountsValue, "None", py::arg("num"));
	cls_StepVisual_SurfaceStyleParameterLine.def("NbDirectionCounts", (Standard_Integer (StepVisual_SurfaceStyleParameterLine::*)() const ) &StepVisual_SurfaceStyleParameterLine::NbDirectionCounts, "None");
	cls_StepVisual_SurfaceStyleParameterLine.def_static("get_type_name_", (const char * (*)()) &StepVisual_SurfaceStyleParameterLine::get_type_name, "None");
	cls_StepVisual_SurfaceStyleParameterLine.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_SurfaceStyleParameterLine::get_type_descriptor, "None");
	cls_StepVisual_SurfaceStyleParameterLine.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_SurfaceStyleParameterLine::*)() const ) &StepVisual_SurfaceStyleParameterLine::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_SurfaceStyleSegmentationCurve.hxx
	py::class_<StepVisual_SurfaceStyleSegmentationCurve, opencascade::handle<StepVisual_SurfaceStyleSegmentationCurve>, Standard_Transient> cls_StepVisual_SurfaceStyleSegmentationCurve(mod, "StepVisual_SurfaceStyleSegmentationCurve", "None");
	cls_StepVisual_SurfaceStyleSegmentationCurve.def(py::init<>());
	cls_StepVisual_SurfaceStyleSegmentationCurve.def("Init", (void (StepVisual_SurfaceStyleSegmentationCurve::*)(const opencascade::handle<StepVisual_CurveStyle> &)) &StepVisual_SurfaceStyleSegmentationCurve::Init, "None", py::arg("aStyleOfSegmentationCurve"));
	cls_StepVisual_SurfaceStyleSegmentationCurve.def("SetStyleOfSegmentationCurve", (void (StepVisual_SurfaceStyleSegmentationCurve::*)(const opencascade::handle<StepVisual_CurveStyle> &)) &StepVisual_SurfaceStyleSegmentationCurve::SetStyleOfSegmentationCurve, "None", py::arg("aStyleOfSegmentationCurve"));
	cls_StepVisual_SurfaceStyleSegmentationCurve.def("StyleOfSegmentationCurve", (opencascade::handle<StepVisual_CurveStyle> (StepVisual_SurfaceStyleSegmentationCurve::*)() const ) &StepVisual_SurfaceStyleSegmentationCurve::StyleOfSegmentationCurve, "None");
	cls_StepVisual_SurfaceStyleSegmentationCurve.def_static("get_type_name_", (const char * (*)()) &StepVisual_SurfaceStyleSegmentationCurve::get_type_name, "None");
	cls_StepVisual_SurfaceStyleSegmentationCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_SurfaceStyleSegmentationCurve::get_type_descriptor, "None");
	cls_StepVisual_SurfaceStyleSegmentationCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_SurfaceStyleSegmentationCurve::*)() const ) &StepVisual_SurfaceStyleSegmentationCurve::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_SurfaceStyleSilhouette.hxx
	py::class_<StepVisual_SurfaceStyleSilhouette, opencascade::handle<StepVisual_SurfaceStyleSilhouette>, Standard_Transient> cls_StepVisual_SurfaceStyleSilhouette(mod, "StepVisual_SurfaceStyleSilhouette", "None");
	cls_StepVisual_SurfaceStyleSilhouette.def(py::init<>());
	cls_StepVisual_SurfaceStyleSilhouette.def("Init", (void (StepVisual_SurfaceStyleSilhouette::*)(const opencascade::handle<StepVisual_CurveStyle> &)) &StepVisual_SurfaceStyleSilhouette::Init, "None", py::arg("aStyleOfSilhouette"));
	cls_StepVisual_SurfaceStyleSilhouette.def("SetStyleOfSilhouette", (void (StepVisual_SurfaceStyleSilhouette::*)(const opencascade::handle<StepVisual_CurveStyle> &)) &StepVisual_SurfaceStyleSilhouette::SetStyleOfSilhouette, "None", py::arg("aStyleOfSilhouette"));
	cls_StepVisual_SurfaceStyleSilhouette.def("StyleOfSilhouette", (opencascade::handle<StepVisual_CurveStyle> (StepVisual_SurfaceStyleSilhouette::*)() const ) &StepVisual_SurfaceStyleSilhouette::StyleOfSilhouette, "None");
	cls_StepVisual_SurfaceStyleSilhouette.def_static("get_type_name_", (const char * (*)()) &StepVisual_SurfaceStyleSilhouette::get_type_name, "None");
	cls_StepVisual_SurfaceStyleSilhouette.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_SurfaceStyleSilhouette::get_type_descriptor, "None");
	cls_StepVisual_SurfaceStyleSilhouette.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_SurfaceStyleSilhouette::*)() const ) &StepVisual_SurfaceStyleSilhouette::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_SurfaceStyleUsage.hxx
	py::class_<StepVisual_SurfaceStyleUsage, opencascade::handle<StepVisual_SurfaceStyleUsage>, Standard_Transient> cls_StepVisual_SurfaceStyleUsage(mod, "StepVisual_SurfaceStyleUsage", "None");
	cls_StepVisual_SurfaceStyleUsage.def(py::init<>());
	cls_StepVisual_SurfaceStyleUsage.def("Init", (void (StepVisual_SurfaceStyleUsage::*)(const StepVisual_SurfaceSide, const opencascade::handle<StepVisual_SurfaceSideStyle> &)) &StepVisual_SurfaceStyleUsage::Init, "None", py::arg("aSide"), py::arg("aStyle"));
	cls_StepVisual_SurfaceStyleUsage.def("SetSide", (void (StepVisual_SurfaceStyleUsage::*)(const StepVisual_SurfaceSide)) &StepVisual_SurfaceStyleUsage::SetSide, "None", py::arg("aSide"));
	cls_StepVisual_SurfaceStyleUsage.def("Side", (StepVisual_SurfaceSide (StepVisual_SurfaceStyleUsage::*)() const ) &StepVisual_SurfaceStyleUsage::Side, "None");
	cls_StepVisual_SurfaceStyleUsage.def("SetStyle", (void (StepVisual_SurfaceStyleUsage::*)(const opencascade::handle<StepVisual_SurfaceSideStyle> &)) &StepVisual_SurfaceStyleUsage::SetStyle, "None", py::arg("aStyle"));
	cls_StepVisual_SurfaceStyleUsage.def("Style", (opencascade::handle<StepVisual_SurfaceSideStyle> (StepVisual_SurfaceStyleUsage::*)() const ) &StepVisual_SurfaceStyleUsage::Style, "None");
	cls_StepVisual_SurfaceStyleUsage.def_static("get_type_name_", (const char * (*)()) &StepVisual_SurfaceStyleUsage::get_type_name, "None");
	cls_StepVisual_SurfaceStyleUsage.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_SurfaceStyleUsage::get_type_descriptor, "None");
	cls_StepVisual_SurfaceStyleUsage.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_SurfaceStyleUsage::*)() const ) &StepVisual_SurfaceStyleUsage::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_Template.hxx
	py::class_<StepVisual_Template, opencascade::handle<StepVisual_Template>, StepRepr_Representation> cls_StepVisual_Template(mod, "StepVisual_Template", "None");
	cls_StepVisual_Template.def(py::init<>());
	cls_StepVisual_Template.def_static("get_type_name_", (const char * (*)()) &StepVisual_Template::get_type_name, "None");
	cls_StepVisual_Template.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_Template::get_type_descriptor, "None");
	cls_StepVisual_Template.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_Template::*)() const ) &StepVisual_Template::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_TemplateInstance.hxx
	py::class_<StepVisual_TemplateInstance, opencascade::handle<StepVisual_TemplateInstance>, StepRepr_MappedItem> cls_StepVisual_TemplateInstance(mod, "StepVisual_TemplateInstance", "None");
	cls_StepVisual_TemplateInstance.def(py::init<>());
	cls_StepVisual_TemplateInstance.def_static("get_type_name_", (const char * (*)()) &StepVisual_TemplateInstance::get_type_name, "None");
	cls_StepVisual_TemplateInstance.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_TemplateInstance::get_type_descriptor, "None");
	cls_StepVisual_TemplateInstance.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_TemplateInstance::*)() const ) &StepVisual_TemplateInstance::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_TessellatedAnnotationOccurrence.hxx
	py::class_<StepVisual_TessellatedAnnotationOccurrence, opencascade::handle<StepVisual_TessellatedAnnotationOccurrence>, StepVisual_StyledItem> cls_StepVisual_TessellatedAnnotationOccurrence(mod, "StepVisual_TessellatedAnnotationOccurrence", "None");
	cls_StepVisual_TessellatedAnnotationOccurrence.def(py::init<>());
	cls_StepVisual_TessellatedAnnotationOccurrence.def_static("get_type_name_", (const char * (*)()) &StepVisual_TessellatedAnnotationOccurrence::get_type_name, "None");
	cls_StepVisual_TessellatedAnnotationOccurrence.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_TessellatedAnnotationOccurrence::get_type_descriptor, "None");
	cls_StepVisual_TessellatedAnnotationOccurrence.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_TessellatedAnnotationOccurrence::*)() const ) &StepVisual_TessellatedAnnotationOccurrence::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_CoordinatesList.hxx
	py::class_<StepVisual_CoordinatesList, opencascade::handle<StepVisual_CoordinatesList>, StepVisual_TessellatedItem> cls_StepVisual_CoordinatesList(mod, "StepVisual_CoordinatesList", "None");
	cls_StepVisual_CoordinatesList.def(py::init<>());
	cls_StepVisual_CoordinatesList.def("Init", (void (StepVisual_CoordinatesList::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TColgp_HArray1OfXYZ> &)) &StepVisual_CoordinatesList::Init, "None", py::arg("theName"), py::arg("thePoints"));
	cls_StepVisual_CoordinatesList.def("Points", (opencascade::handle<TColgp_HArray1OfXYZ> (StepVisual_CoordinatesList::*)() const ) &StepVisual_CoordinatesList::Points, "None");
	cls_StepVisual_CoordinatesList.def_static("get_type_name_", (const char * (*)()) &StepVisual_CoordinatesList::get_type_name, "None");
	cls_StepVisual_CoordinatesList.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_CoordinatesList::get_type_descriptor, "None");
	cls_StepVisual_CoordinatesList.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_CoordinatesList::*)() const ) &StepVisual_CoordinatesList::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_TessellatedCurveSet.hxx
	py::class_<StepVisual_TessellatedCurveSet, opencascade::handle<StepVisual_TessellatedCurveSet>, StepVisual_TessellatedItem> cls_StepVisual_TessellatedCurveSet(mod, "StepVisual_TessellatedCurveSet", "None");
	cls_StepVisual_TessellatedCurveSet.def(py::init<>());
	cls_StepVisual_TessellatedCurveSet.def("Init", (void (StepVisual_TessellatedCurveSet::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_CoordinatesList> &, const NCollection_Handle<StepVisual_VectorOfHSequenceOfInteger> &)) &StepVisual_TessellatedCurveSet::Init, "None", py::arg("theName"), py::arg("theCoordList"), py::arg("theCurves"));
	cls_StepVisual_TessellatedCurveSet.def("CoordList", (opencascade::handle<StepVisual_CoordinatesList> (StepVisual_TessellatedCurveSet::*)() const ) &StepVisual_TessellatedCurveSet::CoordList, "None");
	cls_StepVisual_TessellatedCurveSet.def("Curves", (NCollection_Handle<StepVisual_VectorOfHSequenceOfInteger> (StepVisual_TessellatedCurveSet::*)() const ) &StepVisual_TessellatedCurveSet::Curves, "None");
	cls_StepVisual_TessellatedCurveSet.def_static("get_type_name_", (const char * (*)()) &StepVisual_TessellatedCurveSet::get_type_name, "None");
	cls_StepVisual_TessellatedCurveSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_TessellatedCurveSet::get_type_descriptor, "None");
	cls_StepVisual_TessellatedCurveSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_TessellatedCurveSet::*)() const ) &StepVisual_TessellatedCurveSet::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_TessellatedGeometricSet.hxx
	py::class_<StepVisual_TessellatedGeometricSet, opencascade::handle<StepVisual_TessellatedGeometricSet>, StepVisual_TessellatedItem> cls_StepVisual_TessellatedGeometricSet(mod, "StepVisual_TessellatedGeometricSet", "None");
	cls_StepVisual_TessellatedGeometricSet.def(py::init<>());
	cls_StepVisual_TessellatedGeometricSet.def("Init", (void (StepVisual_TessellatedGeometricSet::*)(const opencascade::handle<TCollection_HAsciiString> &, const NCollection_Handle<StepVisual_Array1OfTessellatedItem> &)) &StepVisual_TessellatedGeometricSet::Init, "None", py::arg("theName"), py::arg("theItems"));
	cls_StepVisual_TessellatedGeometricSet.def("Items", (NCollection_Handle<StepVisual_Array1OfTessellatedItem> (StepVisual_TessellatedGeometricSet::*)() const ) &StepVisual_TessellatedGeometricSet::Items, "None");
	cls_StepVisual_TessellatedGeometricSet.def_static("get_type_name_", (const char * (*)()) &StepVisual_TessellatedGeometricSet::get_type_name, "None");
	cls_StepVisual_TessellatedGeometricSet.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_TessellatedGeometricSet::get_type_descriptor, "None");
	cls_StepVisual_TessellatedGeometricSet.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_TessellatedGeometricSet::*)() const ) &StepVisual_TessellatedGeometricSet::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_TextLiteral.hxx
	py::class_<StepVisual_TextLiteral, opencascade::handle<StepVisual_TextLiteral>, StepGeom_GeometricRepresentationItem> cls_StepVisual_TextLiteral(mod, "StepVisual_TextLiteral", "None");
	cls_StepVisual_TextLiteral.def(py::init<>());
	cls_StepVisual_TextLiteral.def("Init", (void (StepVisual_TextLiteral::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const StepGeom_Axis2Placement &, const opencascade::handle<TCollection_HAsciiString> &, const StepVisual_TextPath, const StepVisual_FontSelect &)) &StepVisual_TextLiteral::Init, "None", py::arg("aName"), py::arg("aLiteral"), py::arg("aPlacement"), py::arg("aAlignment"), py::arg("aPath"), py::arg("aFont"));
	cls_StepVisual_TextLiteral.def("SetLiteral", (void (StepVisual_TextLiteral::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepVisual_TextLiteral::SetLiteral, "None", py::arg("aLiteral"));
	cls_StepVisual_TextLiteral.def("Literal", (opencascade::handle<TCollection_HAsciiString> (StepVisual_TextLiteral::*)() const ) &StepVisual_TextLiteral::Literal, "None");
	cls_StepVisual_TextLiteral.def("SetPlacement", (void (StepVisual_TextLiteral::*)(const StepGeom_Axis2Placement &)) &StepVisual_TextLiteral::SetPlacement, "None", py::arg("aPlacement"));
	cls_StepVisual_TextLiteral.def("Placement", (StepGeom_Axis2Placement (StepVisual_TextLiteral::*)() const ) &StepVisual_TextLiteral::Placement, "None");
	cls_StepVisual_TextLiteral.def("SetAlignment", (void (StepVisual_TextLiteral::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepVisual_TextLiteral::SetAlignment, "None", py::arg("aAlignment"));
	cls_StepVisual_TextLiteral.def("Alignment", (opencascade::handle<TCollection_HAsciiString> (StepVisual_TextLiteral::*)() const ) &StepVisual_TextLiteral::Alignment, "None");
	cls_StepVisual_TextLiteral.def("SetPath", (void (StepVisual_TextLiteral::*)(const StepVisual_TextPath)) &StepVisual_TextLiteral::SetPath, "None", py::arg("aPath"));
	cls_StepVisual_TextLiteral.def("Path", (StepVisual_TextPath (StepVisual_TextLiteral::*)() const ) &StepVisual_TextLiteral::Path, "None");
	cls_StepVisual_TextLiteral.def("SetFont", (void (StepVisual_TextLiteral::*)(const StepVisual_FontSelect &)) &StepVisual_TextLiteral::SetFont, "None", py::arg("aFont"));
	cls_StepVisual_TextLiteral.def("Font", (StepVisual_FontSelect (StepVisual_TextLiteral::*)() const ) &StepVisual_TextLiteral::Font, "None");
	cls_StepVisual_TextLiteral.def_static("get_type_name_", (const char * (*)()) &StepVisual_TextLiteral::get_type_name, "None");
	cls_StepVisual_TextLiteral.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_TextLiteral::get_type_descriptor, "None");
	cls_StepVisual_TextLiteral.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_TextLiteral::*)() const ) &StepVisual_TextLiteral::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_TextStyle.hxx
	py::class_<StepVisual_TextStyle, opencascade::handle<StepVisual_TextStyle>, Standard_Transient> cls_StepVisual_TextStyle(mod, "StepVisual_TextStyle", "None");
	cls_StepVisual_TextStyle.def(py::init<>());
	cls_StepVisual_TextStyle.def("Init", (void (StepVisual_TextStyle::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_TextStyleForDefinedFont> &)) &StepVisual_TextStyle::Init, "None", py::arg("aName"), py::arg("aCharacterAppearance"));
	cls_StepVisual_TextStyle.def("SetName", (void (StepVisual_TextStyle::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepVisual_TextStyle::SetName, "None", py::arg("aName"));
	cls_StepVisual_TextStyle.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepVisual_TextStyle::*)() const ) &StepVisual_TextStyle::Name, "None");
	cls_StepVisual_TextStyle.def("SetCharacterAppearance", (void (StepVisual_TextStyle::*)(const opencascade::handle<StepVisual_TextStyleForDefinedFont> &)) &StepVisual_TextStyle::SetCharacterAppearance, "None", py::arg("aCharacterAppearance"));
	cls_StepVisual_TextStyle.def("CharacterAppearance", (opencascade::handle<StepVisual_TextStyleForDefinedFont> (StepVisual_TextStyle::*)() const ) &StepVisual_TextStyle::CharacterAppearance, "None");
	cls_StepVisual_TextStyle.def_static("get_type_name_", (const char * (*)()) &StepVisual_TextStyle::get_type_name, "None");
	cls_StepVisual_TextStyle.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_TextStyle::get_type_descriptor, "None");
	cls_StepVisual_TextStyle.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_TextStyle::*)() const ) &StepVisual_TextStyle::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_TextStyleForDefinedFont.hxx
	py::class_<StepVisual_TextStyleForDefinedFont, opencascade::handle<StepVisual_TextStyleForDefinedFont>, Standard_Transient> cls_StepVisual_TextStyleForDefinedFont(mod, "StepVisual_TextStyleForDefinedFont", "None");
	cls_StepVisual_TextStyleForDefinedFont.def(py::init<>());
	cls_StepVisual_TextStyleForDefinedFont.def("Init", (void (StepVisual_TextStyleForDefinedFont::*)(const opencascade::handle<StepVisual_Colour> &)) &StepVisual_TextStyleForDefinedFont::Init, "None", py::arg("aTextColour"));
	cls_StepVisual_TextStyleForDefinedFont.def("SetTextColour", (void (StepVisual_TextStyleForDefinedFont::*)(const opencascade::handle<StepVisual_Colour> &)) &StepVisual_TextStyleForDefinedFont::SetTextColour, "None", py::arg("aTextColour"));
	cls_StepVisual_TextStyleForDefinedFont.def("TextColour", (opencascade::handle<StepVisual_Colour> (StepVisual_TextStyleForDefinedFont::*)() const ) &StepVisual_TextStyleForDefinedFont::TextColour, "None");
	cls_StepVisual_TextStyleForDefinedFont.def_static("get_type_name_", (const char * (*)()) &StepVisual_TextStyleForDefinedFont::get_type_name, "None");
	cls_StepVisual_TextStyleForDefinedFont.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_TextStyleForDefinedFont::get_type_descriptor, "None");
	cls_StepVisual_TextStyleForDefinedFont.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_TextStyleForDefinedFont::*)() const ) &StepVisual_TextStyleForDefinedFont::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_TextStyleWithBoxCharacteristics.hxx
	py::class_<StepVisual_TextStyleWithBoxCharacteristics, opencascade::handle<StepVisual_TextStyleWithBoxCharacteristics>, StepVisual_TextStyle> cls_StepVisual_TextStyleWithBoxCharacteristics(mod, "StepVisual_TextStyleWithBoxCharacteristics", "None");
	cls_StepVisual_TextStyleWithBoxCharacteristics.def(py::init<>());
	cls_StepVisual_TextStyleWithBoxCharacteristics.def("Init", (void (StepVisual_TextStyleWithBoxCharacteristics::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepVisual_TextStyleForDefinedFont> &, const opencascade::handle<StepVisual_HArray1OfBoxCharacteristicSelect> &)) &StepVisual_TextStyleWithBoxCharacteristics::Init, "None", py::arg("aName"), py::arg("aCharacterAppearance"), py::arg("aCharacteristics"));
	cls_StepVisual_TextStyleWithBoxCharacteristics.def("SetCharacteristics", (void (StepVisual_TextStyleWithBoxCharacteristics::*)(const opencascade::handle<StepVisual_HArray1OfBoxCharacteristicSelect> &)) &StepVisual_TextStyleWithBoxCharacteristics::SetCharacteristics, "None", py::arg("aCharacteristics"));
	cls_StepVisual_TextStyleWithBoxCharacteristics.def("Characteristics", (opencascade::handle<StepVisual_HArray1OfBoxCharacteristicSelect> (StepVisual_TextStyleWithBoxCharacteristics::*)() const ) &StepVisual_TextStyleWithBoxCharacteristics::Characteristics, "None");
	cls_StepVisual_TextStyleWithBoxCharacteristics.def("CharacteristicsValue", (StepVisual_BoxCharacteristicSelect (StepVisual_TextStyleWithBoxCharacteristics::*)(const Standard_Integer) const ) &StepVisual_TextStyleWithBoxCharacteristics::CharacteristicsValue, "None", py::arg("num"));
	cls_StepVisual_TextStyleWithBoxCharacteristics.def("NbCharacteristics", (Standard_Integer (StepVisual_TextStyleWithBoxCharacteristics::*)() const ) &StepVisual_TextStyleWithBoxCharacteristics::NbCharacteristics, "None");
	cls_StepVisual_TextStyleWithBoxCharacteristics.def_static("get_type_name_", (const char * (*)()) &StepVisual_TextStyleWithBoxCharacteristics::get_type_name, "None");
	cls_StepVisual_TextStyleWithBoxCharacteristics.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_TextStyleWithBoxCharacteristics::get_type_descriptor, "None");
	cls_StepVisual_TextStyleWithBoxCharacteristics.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_TextStyleWithBoxCharacteristics::*)() const ) &StepVisual_TextStyleWithBoxCharacteristics::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_ViewVolume.hxx
	py::class_<StepVisual_ViewVolume, opencascade::handle<StepVisual_ViewVolume>, Standard_Transient> cls_StepVisual_ViewVolume(mod, "StepVisual_ViewVolume", "None");
	cls_StepVisual_ViewVolume.def(py::init<>());
	cls_StepVisual_ViewVolume.def("Init", (void (StepVisual_ViewVolume::*)(const StepVisual_CentralOrParallel, const opencascade::handle<StepGeom_CartesianPoint> &, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const opencascade::handle<StepVisual_PlanarBox> &)) &StepVisual_ViewVolume::Init, "None", py::arg("aProjectionType"), py::arg("aProjectionPoint"), py::arg("aViewPlaneDistance"), py::arg("aFrontPlaneDistance"), py::arg("aFrontPlaneClipping"), py::arg("aBackPlaneDistance"), py::arg("aBackPlaneClipping"), py::arg("aViewVolumeSidesClipping"), py::arg("aViewWindow"));
	cls_StepVisual_ViewVolume.def("SetProjectionType", (void (StepVisual_ViewVolume::*)(const StepVisual_CentralOrParallel)) &StepVisual_ViewVolume::SetProjectionType, "None", py::arg("aProjectionType"));
	cls_StepVisual_ViewVolume.def("ProjectionType", (StepVisual_CentralOrParallel (StepVisual_ViewVolume::*)() const ) &StepVisual_ViewVolume::ProjectionType, "None");
	cls_StepVisual_ViewVolume.def("SetProjectionPoint", (void (StepVisual_ViewVolume::*)(const opencascade::handle<StepGeom_CartesianPoint> &)) &StepVisual_ViewVolume::SetProjectionPoint, "None", py::arg("aProjectionPoint"));
	cls_StepVisual_ViewVolume.def("ProjectionPoint", (opencascade::handle<StepGeom_CartesianPoint> (StepVisual_ViewVolume::*)() const ) &StepVisual_ViewVolume::ProjectionPoint, "None");
	cls_StepVisual_ViewVolume.def("SetViewPlaneDistance", (void (StepVisual_ViewVolume::*)(const Standard_Real)) &StepVisual_ViewVolume::SetViewPlaneDistance, "None", py::arg("aViewPlaneDistance"));
	cls_StepVisual_ViewVolume.def("ViewPlaneDistance", (Standard_Real (StepVisual_ViewVolume::*)() const ) &StepVisual_ViewVolume::ViewPlaneDistance, "None");
	cls_StepVisual_ViewVolume.def("SetFrontPlaneDistance", (void (StepVisual_ViewVolume::*)(const Standard_Real)) &StepVisual_ViewVolume::SetFrontPlaneDistance, "None", py::arg("aFrontPlaneDistance"));
	cls_StepVisual_ViewVolume.def("FrontPlaneDistance", (Standard_Real (StepVisual_ViewVolume::*)() const ) &StepVisual_ViewVolume::FrontPlaneDistance, "None");
	cls_StepVisual_ViewVolume.def("SetFrontPlaneClipping", (void (StepVisual_ViewVolume::*)(const Standard_Boolean)) &StepVisual_ViewVolume::SetFrontPlaneClipping, "None", py::arg("aFrontPlaneClipping"));
	cls_StepVisual_ViewVolume.def("FrontPlaneClipping", (Standard_Boolean (StepVisual_ViewVolume::*)() const ) &StepVisual_ViewVolume::FrontPlaneClipping, "None");
	cls_StepVisual_ViewVolume.def("SetBackPlaneDistance", (void (StepVisual_ViewVolume::*)(const Standard_Real)) &StepVisual_ViewVolume::SetBackPlaneDistance, "None", py::arg("aBackPlaneDistance"));
	cls_StepVisual_ViewVolume.def("BackPlaneDistance", (Standard_Real (StepVisual_ViewVolume::*)() const ) &StepVisual_ViewVolume::BackPlaneDistance, "None");
	cls_StepVisual_ViewVolume.def("SetBackPlaneClipping", (void (StepVisual_ViewVolume::*)(const Standard_Boolean)) &StepVisual_ViewVolume::SetBackPlaneClipping, "None", py::arg("aBackPlaneClipping"));
	cls_StepVisual_ViewVolume.def("BackPlaneClipping", (Standard_Boolean (StepVisual_ViewVolume::*)() const ) &StepVisual_ViewVolume::BackPlaneClipping, "None");
	cls_StepVisual_ViewVolume.def("SetViewVolumeSidesClipping", (void (StepVisual_ViewVolume::*)(const Standard_Boolean)) &StepVisual_ViewVolume::SetViewVolumeSidesClipping, "None", py::arg("aViewVolumeSidesClipping"));
	cls_StepVisual_ViewVolume.def("ViewVolumeSidesClipping", (Standard_Boolean (StepVisual_ViewVolume::*)() const ) &StepVisual_ViewVolume::ViewVolumeSidesClipping, "None");
	cls_StepVisual_ViewVolume.def("SetViewWindow", (void (StepVisual_ViewVolume::*)(const opencascade::handle<StepVisual_PlanarBox> &)) &StepVisual_ViewVolume::SetViewWindow, "None", py::arg("aViewWindow"));
	cls_StepVisual_ViewVolume.def("ViewWindow", (opencascade::handle<StepVisual_PlanarBox> (StepVisual_ViewVolume::*)() const ) &StepVisual_ViewVolume::ViewWindow, "None");
	cls_StepVisual_ViewVolume.def_static("get_type_name_", (const char * (*)()) &StepVisual_ViewVolume::get_type_name, "None");
	cls_StepVisual_ViewVolume.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_ViewVolume::get_type_descriptor, "None");
	cls_StepVisual_ViewVolume.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_ViewVolume::*)() const ) &StepVisual_ViewVolume::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_PresentedItem.hxx
	py::class_<StepVisual_PresentedItem, opencascade::handle<StepVisual_PresentedItem>, Standard_Transient> cls_StepVisual_PresentedItem(mod, "StepVisual_PresentedItem", "None");
	cls_StepVisual_PresentedItem.def_static("get_type_name_", (const char * (*)()) &StepVisual_PresentedItem::get_type_name, "None");
	cls_StepVisual_PresentedItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_PresentedItem::get_type_descriptor, "None");
	cls_StepVisual_PresentedItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_PresentedItem::*)() const ) &StepVisual_PresentedItem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_NullStyleMember.hxx
	py::class_<StepVisual_NullStyleMember, opencascade::handle<StepVisual_NullStyleMember>, StepData_SelectInt> cls_StepVisual_NullStyleMember(mod, "StepVisual_NullStyleMember", "Defines NullStyle as unique member of PresentationStyleSelect Works with an EnumTool");
	cls_StepVisual_NullStyleMember.def(py::init<>());
	cls_StepVisual_NullStyleMember.def("HasName", (Standard_Boolean (StepVisual_NullStyleMember::*)() const ) &StepVisual_NullStyleMember::HasName, "None");
	cls_StepVisual_NullStyleMember.def("Name", (Standard_CString (StepVisual_NullStyleMember::*)() const ) &StepVisual_NullStyleMember::Name, "None");
	cls_StepVisual_NullStyleMember.def("SetName", (Standard_Boolean (StepVisual_NullStyleMember::*)(const Standard_CString)) &StepVisual_NullStyleMember::SetName, "None", py::arg(""));
	cls_StepVisual_NullStyleMember.def("Kind", (Standard_Integer (StepVisual_NullStyleMember::*)() const ) &StepVisual_NullStyleMember::Kind, "None");
	cls_StepVisual_NullStyleMember.def("EnumText", (Standard_CString (StepVisual_NullStyleMember::*)() const ) &StepVisual_NullStyleMember::EnumText, "None");
	cls_StepVisual_NullStyleMember.def("SetEnumText", (void (StepVisual_NullStyleMember::*)(const Standard_Integer, const Standard_CString)) &StepVisual_NullStyleMember::SetEnumText, "None", py::arg("theValue"), py::arg("theText"));
	cls_StepVisual_NullStyleMember.def("SetValue", (void (StepVisual_NullStyleMember::*)(const StepVisual_NullStyle)) &StepVisual_NullStyleMember::SetValue, "None", py::arg("theValue"));
	cls_StepVisual_NullStyleMember.def("Value", (StepVisual_NullStyle (StepVisual_NullStyleMember::*)() const ) &StepVisual_NullStyleMember::Value, "None");
	cls_StepVisual_NullStyleMember.def_static("get_type_name_", (const char * (*)()) &StepVisual_NullStyleMember::get_type_name, "None");
	cls_StepVisual_NullStyleMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_NullStyleMember::get_type_descriptor, "None");
	cls_StepVisual_NullStyleMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_NullStyleMember::*)() const ) &StepVisual_NullStyleMember::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_PresentationStyleSelect.hxx
	py::class_<StepVisual_PresentationStyleSelect, std::unique_ptr<StepVisual_PresentationStyleSelect, Deleter<StepVisual_PresentationStyleSelect>>, StepData_SelectType> cls_StepVisual_PresentationStyleSelect(mod, "StepVisual_PresentationStyleSelect", "None");
	cls_StepVisual_PresentationStyleSelect.def(py::init<>());
	cls_StepVisual_PresentationStyleSelect.def("CaseNum", (Standard_Integer (StepVisual_PresentationStyleSelect::*)(const opencascade::handle<Standard_Transient> &) const ) &StepVisual_PresentationStyleSelect::CaseNum, "Recognizes a PresentationStyleSelect Kind Entity that is : 1 -> PointStyle 2 -> CurveStyle 3 -> SurfaceStyleUsage 4 -> SymbolStyle 5 -> FillAreaStyle 6 -> TextStyle 7 -> NullStyle 0 else", py::arg("ent"));
	cls_StepVisual_PresentationStyleSelect.def("PointStyle", (opencascade::handle<StepVisual_PointStyle> (StepVisual_PresentationStyleSelect::*)() const ) &StepVisual_PresentationStyleSelect::PointStyle, "returns Value as a PointStyle (Null if another type)");
	cls_StepVisual_PresentationStyleSelect.def("CurveStyle", (opencascade::handle<StepVisual_CurveStyle> (StepVisual_PresentationStyleSelect::*)() const ) &StepVisual_PresentationStyleSelect::CurveStyle, "returns Value as a CurveStyle (Null if another type)");
	cls_StepVisual_PresentationStyleSelect.def("NullStyle", (opencascade::handle<StepVisual_NullStyleMember> (StepVisual_PresentationStyleSelect::*)() const ) &StepVisual_PresentationStyleSelect::NullStyle, "returns Value as a NullStyleMember (Null if another type)");
	cls_StepVisual_PresentationStyleSelect.def("SurfaceStyleUsage", (opencascade::handle<StepVisual_SurfaceStyleUsage> (StepVisual_PresentationStyleSelect::*)() const ) &StepVisual_PresentationStyleSelect::SurfaceStyleUsage, "returns Value as a SurfaceStyleUsage (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_Array1OfPresentationStyleSelect.hxx
	bind_NCollection_Array1<StepVisual_PresentationStyleSelect>(mod, "StepVisual_Array1OfPresentationStyleSelect");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_Array1OfPresentationStyleAssignment.hxx
	bind_NCollection_Array1<opencascade::handle<StepVisual_PresentationStyleAssignment> >(mod, "StepVisual_Array1OfPresentationStyleAssignment");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_StyledItemTarget.hxx
	py::class_<StepVisual_StyledItemTarget, std::unique_ptr<StepVisual_StyledItemTarget, Deleter<StepVisual_StyledItemTarget>>, StepData_SelectType> cls_StepVisual_StyledItemTarget(mod, "StepVisual_StyledItemTarget", "None");
	cls_StepVisual_StyledItemTarget.def(py::init<>());
	cls_StepVisual_StyledItemTarget.def("CaseNum", (Standard_Integer (StepVisual_StyledItemTarget::*)(const opencascade::handle<Standard_Transient> &) const ) &StepVisual_StyledItemTarget::CaseNum, "Recognizes a StyledItemTarget Kind Entity that is : 1 -> GeometricRepresentationItem 2 -> MappedItem 3 -> Representation 4 -> TopologicalRepresentationItem 0 else", py::arg("ent"));
	cls_StepVisual_StyledItemTarget.def("GeometricRepresentationItem", (opencascade::handle<StepGeom_GeometricRepresentationItem> (StepVisual_StyledItemTarget::*)() const ) &StepVisual_StyledItemTarget::GeometricRepresentationItem, "returns Value as a GeometricRepresentationItem (Null if another type)");
	cls_StepVisual_StyledItemTarget.def("MappedItem", (opencascade::handle<StepRepr_MappedItem> (StepVisual_StyledItemTarget::*)() const ) &StepVisual_StyledItemTarget::MappedItem, "returns Value as a MappedItem (Null if another type)");
	cls_StepVisual_StyledItemTarget.def("Representation", (opencascade::handle<StepRepr_Representation> (StepVisual_StyledItemTarget::*)() const ) &StepVisual_StyledItemTarget::Representation, "returns Value as a Representation (Null if another type)");
	cls_StepVisual_StyledItemTarget.def("TopologicalRepresentationItem", (opencascade::handle<StepShape_TopologicalRepresentationItem> (StepVisual_StyledItemTarget::*)() const ) &StepVisual_StyledItemTarget::TopologicalRepresentationItem, "returns Value as a TopologicalRepresentationItem (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_AnnotationPlaneElement.hxx
	py::class_<StepVisual_AnnotationPlaneElement, std::unique_ptr<StepVisual_AnnotationPlaneElement, Deleter<StepVisual_AnnotationPlaneElement>>, StepData_SelectType> cls_StepVisual_AnnotationPlaneElement(mod, "StepVisual_AnnotationPlaneElement", "None");
	cls_StepVisual_AnnotationPlaneElement.def(py::init<>());
	cls_StepVisual_AnnotationPlaneElement.def("CaseNum", (Standard_Integer (StepVisual_AnnotationPlaneElement::*)(const opencascade::handle<Standard_Transient> &) const ) &StepVisual_AnnotationPlaneElement::CaseNum, "Recognizes a IdAttributeSelect Kind Entity that is : 1 -> DraughtingCallout 2 -> StyledItem 0 else", py::arg("ent"));
	cls_StepVisual_AnnotationPlaneElement.def("DraughtingCallout", (opencascade::handle<StepVisual_DraughtingCallout> (StepVisual_AnnotationPlaneElement::*)() const ) &StepVisual_AnnotationPlaneElement::DraughtingCallout, "returns Value as a DraughtingCallout (Null if another type)");
	cls_StepVisual_AnnotationPlaneElement.def("StyledItem", (opencascade::handle<StepVisual_StyledItem> (StepVisual_AnnotationPlaneElement::*)() const ) &StepVisual_AnnotationPlaneElement::StyledItem, "returns Value as a StyledItem (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_Array1OfAnnotationPlaneElement.hxx
	bind_NCollection_Array1<StepVisual_AnnotationPlaneElement>(mod, "StepVisual_Array1OfAnnotationPlaneElement");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_AnnotationText.hxx
	py::class_<StepVisual_AnnotationText, opencascade::handle<StepVisual_AnnotationText>, StepRepr_MappedItem> cls_StepVisual_AnnotationText(mod, "StepVisual_AnnotationText", "None");
	cls_StepVisual_AnnotationText.def(py::init<>());
	cls_StepVisual_AnnotationText.def_static("get_type_name_", (const char * (*)()) &StepVisual_AnnotationText::get_type_name, "None");
	cls_StepVisual_AnnotationText.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_AnnotationText::get_type_descriptor, "None");
	cls_StepVisual_AnnotationText.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_AnnotationText::*)() const ) &StepVisual_AnnotationText::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_AnnotationTextOccurrence.hxx
	py::class_<StepVisual_AnnotationTextOccurrence, opencascade::handle<StepVisual_AnnotationTextOccurrence>, StepVisual_AnnotationOccurrence> cls_StepVisual_AnnotationTextOccurrence(mod, "StepVisual_AnnotationTextOccurrence", "None");
	cls_StepVisual_AnnotationTextOccurrence.def(py::init<>());
	cls_StepVisual_AnnotationTextOccurrence.def_static("get_type_name_", (const char * (*)()) &StepVisual_AnnotationTextOccurrence::get_type_name, "None");
	cls_StepVisual_AnnotationTextOccurrence.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_AnnotationTextOccurrence::get_type_descriptor, "None");
	cls_StepVisual_AnnotationTextOccurrence.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_AnnotationTextOccurrence::*)() const ) &StepVisual_AnnotationTextOccurrence::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_AreaOrView.hxx
	py::class_<StepVisual_AreaOrView, std::unique_ptr<StepVisual_AreaOrView, Deleter<StepVisual_AreaOrView>>, StepData_SelectType> cls_StepVisual_AreaOrView(mod, "StepVisual_AreaOrView", "None");
	cls_StepVisual_AreaOrView.def(py::init<>());
	cls_StepVisual_AreaOrView.def("CaseNum", (Standard_Integer (StepVisual_AreaOrView::*)(const opencascade::handle<Standard_Transient> &) const ) &StepVisual_AreaOrView::CaseNum, "Recognizes a AreaOrView Kind Entity that is : 1 -> PresentationArea 2 -> PresentationView 0 else", py::arg("ent"));
	cls_StepVisual_AreaOrView.def("PresentationArea", (opencascade::handle<StepVisual_PresentationArea> (StepVisual_AreaOrView::*)() const ) &StepVisual_AreaOrView::PresentationArea, "returns Value as a PresentationArea (Null if another type)");
	cls_StepVisual_AreaOrView.def("PresentationView", (opencascade::handle<StepVisual_PresentationView> (StepVisual_AreaOrView::*)() const ) &StepVisual_AreaOrView::PresentationView, "returns Value as a PresentationView (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_BoxCharacteristicSelect.hxx
	py::class_<StepVisual_BoxCharacteristicSelect, std::unique_ptr<StepVisual_BoxCharacteristicSelect, Deleter<StepVisual_BoxCharacteristicSelect>>> cls_StepVisual_BoxCharacteristicSelect(mod, "StepVisual_BoxCharacteristicSelect", "None");
	cls_StepVisual_BoxCharacteristicSelect.def(py::init<>());
	cls_StepVisual_BoxCharacteristicSelect.def("TypeOfContent", (Standard_Integer (StepVisual_BoxCharacteristicSelect::*)() const ) &StepVisual_BoxCharacteristicSelect::TypeOfContent, "None");
	cls_StepVisual_BoxCharacteristicSelect.def("SetTypeOfContent", (void (StepVisual_BoxCharacteristicSelect::*)(const Standard_Integer)) &StepVisual_BoxCharacteristicSelect::SetTypeOfContent, "None", py::arg("aType"));
	cls_StepVisual_BoxCharacteristicSelect.def("RealValue", (Standard_Real (StepVisual_BoxCharacteristicSelect::*)() const ) &StepVisual_BoxCharacteristicSelect::RealValue, "None");
	cls_StepVisual_BoxCharacteristicSelect.def("SetRealValue", (void (StepVisual_BoxCharacteristicSelect::*)(const Standard_Real)) &StepVisual_BoxCharacteristicSelect::SetRealValue, "None", py::arg("aValue"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_CameraModelD3MultiClippingInterectionSelect.hxx
	py::class_<StepVisual_CameraModelD3MultiClippingInterectionSelect, std::unique_ptr<StepVisual_CameraModelD3MultiClippingInterectionSelect, Deleter<StepVisual_CameraModelD3MultiClippingInterectionSelect>>, StepData_SelectType> cls_StepVisual_CameraModelD3MultiClippingInterectionSelect(mod, "StepVisual_CameraModelD3MultiClippingInterectionSelect", "None");
	cls_StepVisual_CameraModelD3MultiClippingInterectionSelect.def(py::init<>());
	cls_StepVisual_CameraModelD3MultiClippingInterectionSelect.def("CaseNum", (Standard_Integer (StepVisual_CameraModelD3MultiClippingInterectionSelect::*)(const opencascade::handle<Standard_Transient> &) const ) &StepVisual_CameraModelD3MultiClippingInterectionSelect::CaseNum, "Recognizes a IdAttributeSelect Kind Entity that is : 1 -> Plane 2 -> CameraModelD3MultiClippingUnion 0 else", py::arg("ent"));
	cls_StepVisual_CameraModelD3MultiClippingInterectionSelect.def("Plane", (opencascade::handle<StepGeom_Plane> (StepVisual_CameraModelD3MultiClippingInterectionSelect::*)() const ) &StepVisual_CameraModelD3MultiClippingInterectionSelect::Plane, "returns Value as a Plane (Null if another type)");
	cls_StepVisual_CameraModelD3MultiClippingInterectionSelect.def("CameraModelD3MultiClippingUnion", (opencascade::handle<StepVisual_CameraModelD3MultiClippingUnion> (StepVisual_CameraModelD3MultiClippingInterectionSelect::*)() const ) &StepVisual_CameraModelD3MultiClippingInterectionSelect::CameraModelD3MultiClippingUnion, "returns Value as a CameraModelD3MultiClippingUnion (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_CameraModelD3MultiClippingUnionSelect.hxx
	py::class_<StepVisual_CameraModelD3MultiClippingUnionSelect, std::unique_ptr<StepVisual_CameraModelD3MultiClippingUnionSelect, Deleter<StepVisual_CameraModelD3MultiClippingUnionSelect>>, StepData_SelectType> cls_StepVisual_CameraModelD3MultiClippingUnionSelect(mod, "StepVisual_CameraModelD3MultiClippingUnionSelect", "None");
	cls_StepVisual_CameraModelD3MultiClippingUnionSelect.def(py::init<>());
	cls_StepVisual_CameraModelD3MultiClippingUnionSelect.def("CaseNum", (Standard_Integer (StepVisual_CameraModelD3MultiClippingUnionSelect::*)(const opencascade::handle<Standard_Transient> &) const ) &StepVisual_CameraModelD3MultiClippingUnionSelect::CaseNum, "Recognizes a IdAttributeSelect Kind Entity that is : 1 -> Plane 2 -> CameraModelD3MultiClippingIntersection 0 else", py::arg("ent"));
	cls_StepVisual_CameraModelD3MultiClippingUnionSelect.def("Plane", (opencascade::handle<StepGeom_Plane> (StepVisual_CameraModelD3MultiClippingUnionSelect::*)() const ) &StepVisual_CameraModelD3MultiClippingUnionSelect::Plane, "returns Value as a Plane (Null if another type)");
	cls_StepVisual_CameraModelD3MultiClippingUnionSelect.def("CameraModelD3MultiClippingIntersection", (opencascade::handle<StepVisual_CameraModelD3MultiClippingIntersection> (StepVisual_CameraModelD3MultiClippingUnionSelect::*)() const ) &StepVisual_CameraModelD3MultiClippingUnionSelect::CameraModelD3MultiClippingIntersection, "returns Value as a CameraModelD3MultiClippingIntersection (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_DirectionCountSelect.hxx
	py::class_<StepVisual_DirectionCountSelect, std::unique_ptr<StepVisual_DirectionCountSelect, Deleter<StepVisual_DirectionCountSelect>>> cls_StepVisual_DirectionCountSelect(mod, "StepVisual_DirectionCountSelect", "None");
	cls_StepVisual_DirectionCountSelect.def(py::init<>());
	cls_StepVisual_DirectionCountSelect.def("SetTypeOfContent", (void (StepVisual_DirectionCountSelect::*)(const Standard_Integer)) &StepVisual_DirectionCountSelect::SetTypeOfContent, "None", py::arg("aTypeOfContent"));
	cls_StepVisual_DirectionCountSelect.def("TypeOfContent", (Standard_Integer (StepVisual_DirectionCountSelect::*)() const ) &StepVisual_DirectionCountSelect::TypeOfContent, "None");
	cls_StepVisual_DirectionCountSelect.def("UDirectionCount", (Standard_Integer (StepVisual_DirectionCountSelect::*)() const ) &StepVisual_DirectionCountSelect::UDirectionCount, "None");
	cls_StepVisual_DirectionCountSelect.def("SetUDirectionCount", (void (StepVisual_DirectionCountSelect::*)(const Standard_Integer)) &StepVisual_DirectionCountSelect::SetUDirectionCount, "None", py::arg("aUDirectionCount"));
	cls_StepVisual_DirectionCountSelect.def("VDirectionCount", (Standard_Integer (StepVisual_DirectionCountSelect::*)() const ) &StepVisual_DirectionCountSelect::VDirectionCount, "None");
	cls_StepVisual_DirectionCountSelect.def("SetVDirectionCount", (void (StepVisual_DirectionCountSelect::*)(const Standard_Integer)) &StepVisual_DirectionCountSelect::SetVDirectionCount, "None", py::arg("aUDirectionCount"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_DraughtingCalloutElement.hxx
	py::class_<StepVisual_DraughtingCalloutElement, std::unique_ptr<StepVisual_DraughtingCalloutElement, Deleter<StepVisual_DraughtingCalloutElement>>, StepData_SelectType> cls_StepVisual_DraughtingCalloutElement(mod, "StepVisual_DraughtingCalloutElement", "None");
	cls_StepVisual_DraughtingCalloutElement.def(py::init<>());
	cls_StepVisual_DraughtingCalloutElement.def("CaseNum", (Standard_Integer (StepVisual_DraughtingCalloutElement::*)(const opencascade::handle<Standard_Transient> &) const ) &StepVisual_DraughtingCalloutElement::CaseNum, "Recognizes a IdAttributeSelect Kind Entity that is : 1 -> AnnotationCurveOccurrence 2 -> AnnotationTextOccurrence 3 -> TessellatedAnnotationOccurrence 4 -> AnnotationFillAreaOccurrence 0 else", py::arg("ent"));
	cls_StepVisual_DraughtingCalloutElement.def("AnnotationCurveOccurrence", (opencascade::handle<StepVisual_AnnotationCurveOccurrence> (StepVisual_DraughtingCalloutElement::*)() const ) &StepVisual_DraughtingCalloutElement::AnnotationCurveOccurrence, "returns Value as a AnnotationCurveOccurrence (Null if another type)");
	cls_StepVisual_DraughtingCalloutElement.def("AnnotationTextOccurrence", (opencascade::handle<StepVisual_AnnotationTextOccurrence> (StepVisual_DraughtingCalloutElement::*)() const ) &StepVisual_DraughtingCalloutElement::AnnotationTextOccurrence, "returns Value as a AnnotationTextOccurrence");
	cls_StepVisual_DraughtingCalloutElement.def("TessellatedAnnotationOccurrence", (opencascade::handle<StepVisual_TessellatedAnnotationOccurrence> (StepVisual_DraughtingCalloutElement::*)() const ) &StepVisual_DraughtingCalloutElement::TessellatedAnnotationOccurrence, "returns Value as a TessellatedAnnotationOccurrence");
	cls_StepVisual_DraughtingCalloutElement.def("AnnotationFillAreaOccurrence", (opencascade::handle<StepVisual_AnnotationFillAreaOccurrence> (StepVisual_DraughtingCalloutElement::*)() const ) &StepVisual_DraughtingCalloutElement::AnnotationFillAreaOccurrence, "returns Value as a AnnotationFillAreaOccurrence");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_FillStyleSelect.hxx
	py::class_<StepVisual_FillStyleSelect, std::unique_ptr<StepVisual_FillStyleSelect, Deleter<StepVisual_FillStyleSelect>>, StepData_SelectType> cls_StepVisual_FillStyleSelect(mod, "StepVisual_FillStyleSelect", "None");
	cls_StepVisual_FillStyleSelect.def(py::init<>());
	cls_StepVisual_FillStyleSelect.def("CaseNum", (Standard_Integer (StepVisual_FillStyleSelect::*)(const opencascade::handle<Standard_Transient> &) const ) &StepVisual_FillStyleSelect::CaseNum, "Recognizes a FillStyleSelect Kind Entity that is : 1 -> FillAreaStyleColour 2 -> ExternallyDefinedTileStyle 3 -> FillAreaStyleTiles 4 -> ExternallyDefinedHatchStyle 5 -> FillAreaStyleHatching 0 else", py::arg("ent"));
	cls_StepVisual_FillStyleSelect.def("FillAreaStyleColour", (opencascade::handle<StepVisual_FillAreaStyleColour> (StepVisual_FillStyleSelect::*)() const ) &StepVisual_FillStyleSelect::FillAreaStyleColour, "returns Value as a FillAreaStyleColour (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_InvisibleItem.hxx
	py::class_<StepVisual_InvisibleItem, std::unique_ptr<StepVisual_InvisibleItem, Deleter<StepVisual_InvisibleItem>>, StepData_SelectType> cls_StepVisual_InvisibleItem(mod, "StepVisual_InvisibleItem", "None");
	cls_StepVisual_InvisibleItem.def(py::init<>());
	cls_StepVisual_InvisibleItem.def("CaseNum", (Standard_Integer (StepVisual_InvisibleItem::*)(const opencascade::handle<Standard_Transient> &) const ) &StepVisual_InvisibleItem::CaseNum, "Recognizes a InvisibleItem Kind Entity that is : 1 -> StyledItem 2 -> PresentationLayerAssignment 3 -> PresentationRepresentation 0 else", py::arg("ent"));
	cls_StepVisual_InvisibleItem.def("StyledItem", (opencascade::handle<StepVisual_StyledItem> (StepVisual_InvisibleItem::*)() const ) &StepVisual_InvisibleItem::StyledItem, "returns Value as a StyledItem (Null if another type)");
	cls_StepVisual_InvisibleItem.def("PresentationLayerAssignment", (opencascade::handle<StepVisual_PresentationLayerAssignment> (StepVisual_InvisibleItem::*)() const ) &StepVisual_InvisibleItem::PresentationLayerAssignment, "returns Value as a PresentationLayerAssignment (Null if another type)");
	cls_StepVisual_InvisibleItem.def("PresentationRepresentation", (opencascade::handle<StepVisual_PresentationRepresentation> (StepVisual_InvisibleItem::*)() const ) &StepVisual_InvisibleItem::PresentationRepresentation, "returns Value as a PresentationRepresentation (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_LayeredItem.hxx
	py::class_<StepVisual_LayeredItem, std::unique_ptr<StepVisual_LayeredItem, Deleter<StepVisual_LayeredItem>>, StepData_SelectType> cls_StepVisual_LayeredItem(mod, "StepVisual_LayeredItem", "None");
	cls_StepVisual_LayeredItem.def(py::init<>());
	cls_StepVisual_LayeredItem.def("CaseNum", (Standard_Integer (StepVisual_LayeredItem::*)(const opencascade::handle<Standard_Transient> &) const ) &StepVisual_LayeredItem::CaseNum, "Recognizes a LayeredItem Kind Entity that is : 1 -> PresentationRepresentation 2 -> RepresentationItem 0 else", py::arg("ent"));
	cls_StepVisual_LayeredItem.def("PresentationRepresentation", (opencascade::handle<StepVisual_PresentationRepresentation> (StepVisual_LayeredItem::*)() const ) &StepVisual_LayeredItem::PresentationRepresentation, "returns Value as a PresentationRepresentation (Null if another type)");
	cls_StepVisual_LayeredItem.def("RepresentationItem", (opencascade::handle<StepRepr_RepresentationItem> (StepVisual_LayeredItem::*)() const ) &StepVisual_LayeredItem::RepresentationItem, "returns Value as a RepresentationItem (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_StyleContextSelect.hxx
	py::class_<StepVisual_StyleContextSelect, std::unique_ptr<StepVisual_StyleContextSelect, Deleter<StepVisual_StyleContextSelect>>, StepData_SelectType> cls_StepVisual_StyleContextSelect(mod, "StepVisual_StyleContextSelect", "None");
	cls_StepVisual_StyleContextSelect.def(py::init<>());
	cls_StepVisual_StyleContextSelect.def("CaseNum", (Standard_Integer (StepVisual_StyleContextSelect::*)(const opencascade::handle<Standard_Transient> &) const ) &StepVisual_StyleContextSelect::CaseNum, "Recognizes a StyleContextSelect Kind Entity that is : 1 -> Representation 2 -> RepresentationItem 3 -> PresentationSet 0 else", py::arg("ent"));
	cls_StepVisual_StyleContextSelect.def("Representation", (opencascade::handle<StepRepr_Representation> (StepVisual_StyleContextSelect::*)() const ) &StepVisual_StyleContextSelect::Representation, "returns Value as a Representation (Null if another type)");
	cls_StepVisual_StyleContextSelect.def("RepresentationItem", (opencascade::handle<StepRepr_RepresentationItem> (StepVisual_StyleContextSelect::*)() const ) &StepVisual_StyleContextSelect::RepresentationItem, "returns Value as a RepresentationItem (Null if another type)");
	cls_StepVisual_StyleContextSelect.def("PresentationSet", (opencascade::handle<StepVisual_PresentationSet> (StepVisual_StyleContextSelect::*)() const ) &StepVisual_StyleContextSelect::PresentationSet, "returns Value as a PresentationSet (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_SurfaceStyleElementSelect.hxx
	py::class_<StepVisual_SurfaceStyleElementSelect, std::unique_ptr<StepVisual_SurfaceStyleElementSelect, Deleter<StepVisual_SurfaceStyleElementSelect>>, StepData_SelectType> cls_StepVisual_SurfaceStyleElementSelect(mod, "StepVisual_SurfaceStyleElementSelect", "None");
	cls_StepVisual_SurfaceStyleElementSelect.def(py::init<>());
	cls_StepVisual_SurfaceStyleElementSelect.def("CaseNum", (Standard_Integer (StepVisual_SurfaceStyleElementSelect::*)(const opencascade::handle<Standard_Transient> &) const ) &StepVisual_SurfaceStyleElementSelect::CaseNum, "Recognizes a SurfaceStyleElementSelect Kind Entity that is : 1 -> SurfaceStyleFillArea 2 -> SurfaceStyleBoundary 3 -> SurfaceStyleParameterLine 4 -> SurfaceStyleSilhouette 5 -> SurfaceStyleSegmentationCurve 6 -> SurfaceStyleControlGrid 0 else", py::arg("ent"));
	cls_StepVisual_SurfaceStyleElementSelect.def("SurfaceStyleFillArea", (opencascade::handle<StepVisual_SurfaceStyleFillArea> (StepVisual_SurfaceStyleElementSelect::*)() const ) &StepVisual_SurfaceStyleElementSelect::SurfaceStyleFillArea, "returns Value as a SurfaceStyleFillArea (Null if another type)");
	cls_StepVisual_SurfaceStyleElementSelect.def("SurfaceStyleBoundary", (opencascade::handle<StepVisual_SurfaceStyleBoundary> (StepVisual_SurfaceStyleElementSelect::*)() const ) &StepVisual_SurfaceStyleElementSelect::SurfaceStyleBoundary, "returns Value as a SurfaceStyleBoundary (Null if another type)");
	cls_StepVisual_SurfaceStyleElementSelect.def("SurfaceStyleParameterLine", (opencascade::handle<StepVisual_SurfaceStyleParameterLine> (StepVisual_SurfaceStyleElementSelect::*)() const ) &StepVisual_SurfaceStyleElementSelect::SurfaceStyleParameterLine, "returns Value as a SurfaceStyleParameterLine (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_TextOrCharacter.hxx
	py::class_<StepVisual_TextOrCharacter, std::unique_ptr<StepVisual_TextOrCharacter, Deleter<StepVisual_TextOrCharacter>>, StepData_SelectType> cls_StepVisual_TextOrCharacter(mod, "StepVisual_TextOrCharacter", "None");
	cls_StepVisual_TextOrCharacter.def(py::init<>());
	cls_StepVisual_TextOrCharacter.def("CaseNum", (Standard_Integer (StepVisual_TextOrCharacter::*)(const opencascade::handle<Standard_Transient> &) const ) &StepVisual_TextOrCharacter::CaseNum, "Recognizes a TextOrCharacter Kind Entity that is : 1 -> AnnotationText 2 -> CompositeText 3 -> TextLiteral 0 else", py::arg("ent"));
	cls_StepVisual_TextOrCharacter.def("AnnotationText", (opencascade::handle<StepVisual_AnnotationText> (StepVisual_TextOrCharacter::*)() const ) &StepVisual_TextOrCharacter::AnnotationText, "returns Value as a AnnotationText (Null if another type)");
	cls_StepVisual_TextOrCharacter.def("CompositeText", (opencascade::handle<StepVisual_CompositeText> (StepVisual_TextOrCharacter::*)() const ) &StepVisual_TextOrCharacter::CompositeText, "returns Value as a CompositeText (Null if another type)");
	cls_StepVisual_TextOrCharacter.def("TextLiteral", (opencascade::handle<StepVisual_TextLiteral> (StepVisual_TextOrCharacter::*)() const ) &StepVisual_TextOrCharacter::TextLiteral, "returns Value as a TextLiteral (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_CameraImage2dWithScale.hxx
	py::class_<StepVisual_CameraImage2dWithScale, opencascade::handle<StepVisual_CameraImage2dWithScale>, StepVisual_CameraImage> cls_StepVisual_CameraImage2dWithScale(mod, "StepVisual_CameraImage2dWithScale", "None");
	cls_StepVisual_CameraImage2dWithScale.def(py::init<>());
	cls_StepVisual_CameraImage2dWithScale.def_static("get_type_name_", (const char * (*)()) &StepVisual_CameraImage2dWithScale::get_type_name, "None");
	cls_StepVisual_CameraImage2dWithScale.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_CameraImage2dWithScale::get_type_descriptor, "None");
	cls_StepVisual_CameraImage2dWithScale.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_CameraImage2dWithScale::*)() const ) &StepVisual_CameraImage2dWithScale::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_CameraImage3dWithScale.hxx
	py::class_<StepVisual_CameraImage3dWithScale, opencascade::handle<StepVisual_CameraImage3dWithScale>, StepVisual_CameraImage> cls_StepVisual_CameraImage3dWithScale(mod, "StepVisual_CameraImage3dWithScale", "None");
	cls_StepVisual_CameraImage3dWithScale.def(py::init<>());
	cls_StepVisual_CameraImage3dWithScale.def_static("get_type_name_", (const char * (*)()) &StepVisual_CameraImage3dWithScale::get_type_name, "None");
	cls_StepVisual_CameraImage3dWithScale.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_CameraImage3dWithScale::get_type_descriptor, "None");
	cls_StepVisual_CameraImage3dWithScale.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_CameraImage3dWithScale::*)() const ) &StepVisual_CameraImage3dWithScale::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_Array1OfCameraModelD3MultiClippingInterectionSelect.hxx
	bind_NCollection_Array1<StepVisual_CameraModelD3MultiClippingInterectionSelect>(mod, "StepVisual_Array1OfCameraModelD3MultiClippingInterectionSelect");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_Array1OfCameraModelD3MultiClippingUnionSelect.hxx
	bind_NCollection_Array1<StepVisual_CameraModelD3MultiClippingUnionSelect>(mod, "StepVisual_Array1OfCameraModelD3MultiClippingUnionSelect");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_Array1OfTextOrCharacter.hxx
	bind_NCollection_Array1<StepVisual_TextOrCharacter>(mod, "StepVisual_Array1OfTextOrCharacter");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_InvisibilityContext.hxx
	py::class_<StepVisual_InvisibilityContext, std::unique_ptr<StepVisual_InvisibilityContext, Deleter<StepVisual_InvisibilityContext>>, StepData_SelectType> cls_StepVisual_InvisibilityContext(mod, "StepVisual_InvisibilityContext", "None");
	cls_StepVisual_InvisibilityContext.def(py::init<>());
	cls_StepVisual_InvisibilityContext.def("CaseNum", (Standard_Integer (StepVisual_InvisibilityContext::*)(const opencascade::handle<Standard_Transient> &) const ) &StepVisual_InvisibilityContext::CaseNum, "Recognizes a InvisibilityContext Kind Entity that is : 1 -> PresentationRepresentation 2 -> PresentationSet 2 -> DraughtingModel 0 else", py::arg("ent"));
	cls_StepVisual_InvisibilityContext.def("PresentationRepresentation", (opencascade::handle<StepVisual_PresentationRepresentation> (StepVisual_InvisibilityContext::*)() const ) &StepVisual_InvisibilityContext::PresentationRepresentation, "returns Value as a PresentationRepresentation (Null if another type)");
	cls_StepVisual_InvisibilityContext.def("PresentationSet", (opencascade::handle<StepVisual_PresentationSet> (StepVisual_InvisibilityContext::*)() const ) &StepVisual_InvisibilityContext::PresentationSet, "returns Value as a PresentationSet (Null if another type)");
	cls_StepVisual_InvisibilityContext.def("DraughtingModel", (opencascade::handle<StepVisual_DraughtingModel> (StepVisual_InvisibilityContext::*)() const ) &StepVisual_InvisibilityContext::DraughtingModel, "returns Value as a PresentationSet (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_Array1OfInvisibleItem.hxx
	bind_NCollection_Array1<StepVisual_InvisibleItem>(mod, "StepVisual_Array1OfInvisibleItem");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_Array1OfStyleContextSelect.hxx
	bind_NCollection_Array1<StepVisual_StyleContextSelect>(mod, "StepVisual_Array1OfStyleContextSelect");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_CurveStyleFontSelect.hxx
	py::class_<StepVisual_CurveStyleFontSelect, std::unique_ptr<StepVisual_CurveStyleFontSelect, Deleter<StepVisual_CurveStyleFontSelect>>, StepData_SelectType> cls_StepVisual_CurveStyleFontSelect(mod, "StepVisual_CurveStyleFontSelect", "None");
	cls_StepVisual_CurveStyleFontSelect.def(py::init<>());
	cls_StepVisual_CurveStyleFontSelect.def("CaseNum", (Standard_Integer (StepVisual_CurveStyleFontSelect::*)(const opencascade::handle<Standard_Transient> &) const ) &StepVisual_CurveStyleFontSelect::CaseNum, "Recognizes a CurveStyleFontSelect Kind Entity that is : 1 -> CurveStyleFont 2 -> PreDefinedCurveFont 3 -> ExternallyDefinedCurveFont 0 else", py::arg("ent"));
	cls_StepVisual_CurveStyleFontSelect.def("CurveStyleFont", (opencascade::handle<StepVisual_CurveStyleFont> (StepVisual_CurveStyleFontSelect::*)() const ) &StepVisual_CurveStyleFontSelect::CurveStyleFont, "returns Value as a CurveStyleFont (Null if another type)");
	cls_StepVisual_CurveStyleFontSelect.def("PreDefinedCurveFont", (opencascade::handle<StepVisual_PreDefinedCurveFont> (StepVisual_CurveStyleFontSelect::*)() const ) &StepVisual_CurveStyleFontSelect::PreDefinedCurveFont, "returns Value as a PreDefinedCurveFont (Null if another type)");
	cls_StepVisual_CurveStyleFontSelect.def("ExternallyDefinedCurveFont", (opencascade::handle<StepVisual_ExternallyDefinedCurveFont> (StepVisual_CurveStyleFontSelect::*)() const ) &StepVisual_CurveStyleFontSelect::ExternallyDefinedCurveFont, "returns Value as a ExternallyDefinedCurveFont (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_Array1OfCurveStyleFontPattern.hxx
	bind_NCollection_Array1<opencascade::handle<StepVisual_CurveStyleFontPattern> >(mod, "StepVisual_Array1OfCurveStyleFontPattern");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_DraughtingAnnotationOccurrence.hxx
	py::class_<StepVisual_DraughtingAnnotationOccurrence, opencascade::handle<StepVisual_DraughtingAnnotationOccurrence>, StepVisual_AnnotationOccurrence> cls_StepVisual_DraughtingAnnotationOccurrence(mod, "StepVisual_DraughtingAnnotationOccurrence", "None");
	cls_StepVisual_DraughtingAnnotationOccurrence.def(py::init<>());
	cls_StepVisual_DraughtingAnnotationOccurrence.def_static("get_type_name_", (const char * (*)()) &StepVisual_DraughtingAnnotationOccurrence::get_type_name, "None");
	cls_StepVisual_DraughtingAnnotationOccurrence.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_DraughtingAnnotationOccurrence::get_type_descriptor, "None");
	cls_StepVisual_DraughtingAnnotationOccurrence.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_DraughtingAnnotationOccurrence::*)() const ) &StepVisual_DraughtingAnnotationOccurrence::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_Array1OfDraughtingCalloutElement.hxx
	bind_NCollection_Array1<StepVisual_DraughtingCalloutElement>(mod, "StepVisual_Array1OfDraughtingCalloutElement");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_ExternallyDefinedTextFont.hxx
	py::class_<StepVisual_ExternallyDefinedTextFont, opencascade::handle<StepVisual_ExternallyDefinedTextFont>, StepBasic_ExternallyDefinedItem> cls_StepVisual_ExternallyDefinedTextFont(mod, "StepVisual_ExternallyDefinedTextFont", "Representation of STEP entity ExternallyDefinedTextFont");
	cls_StepVisual_ExternallyDefinedTextFont.def(py::init<>());
	cls_StepVisual_ExternallyDefinedTextFont.def_static("get_type_name_", (const char * (*)()) &StepVisual_ExternallyDefinedTextFont::get_type_name, "None");
	cls_StepVisual_ExternallyDefinedTextFont.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_ExternallyDefinedTextFont::get_type_descriptor, "None");
	cls_StepVisual_ExternallyDefinedTextFont.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_ExternallyDefinedTextFont::*)() const ) &StepVisual_ExternallyDefinedTextFont::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_Array1OfFillStyleSelect.hxx
	bind_NCollection_Array1<StepVisual_FillStyleSelect>(mod, "StepVisual_Array1OfFillStyleSelect");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_PreDefinedTextFont.hxx
	py::class_<StepVisual_PreDefinedTextFont, opencascade::handle<StepVisual_PreDefinedTextFont>, StepVisual_PreDefinedItem> cls_StepVisual_PreDefinedTextFont(mod, "StepVisual_PreDefinedTextFont", "None");
	cls_StepVisual_PreDefinedTextFont.def(py::init<>());
	cls_StepVisual_PreDefinedTextFont.def_static("get_type_name_", (const char * (*)()) &StepVisual_PreDefinedTextFont::get_type_name, "None");
	cls_StepVisual_PreDefinedTextFont.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_PreDefinedTextFont::get_type_descriptor, "None");
	cls_StepVisual_PreDefinedTextFont.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_PreDefinedTextFont::*)() const ) &StepVisual_PreDefinedTextFont::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_FontSelect.hxx
	py::class_<StepVisual_FontSelect, std::unique_ptr<StepVisual_FontSelect, Deleter<StepVisual_FontSelect>>, StepData_SelectType> cls_StepVisual_FontSelect(mod, "StepVisual_FontSelect", "None");
	cls_StepVisual_FontSelect.def(py::init<>());
	cls_StepVisual_FontSelect.def("CaseNum", (Standard_Integer (StepVisual_FontSelect::*)(const opencascade::handle<Standard_Transient> &) const ) &StepVisual_FontSelect::CaseNum, "Recognizes a FontSelect Kind Entity that is : 1 -> PreDefinedTextFont 2 -> ExternallyDefinedTextFont 0 else", py::arg("ent"));
	cls_StepVisual_FontSelect.def("PreDefinedTextFont", (opencascade::handle<StepVisual_PreDefinedTextFont> (StepVisual_FontSelect::*)() const ) &StepVisual_FontSelect::PreDefinedTextFont, "returns Value as a PreDefinedTextFont (Null if another type)");
	cls_StepVisual_FontSelect.def("ExternallyDefinedTextFont", (opencascade::handle<StepVisual_ExternallyDefinedTextFont> (StepVisual_FontSelect::*)() const ) &StepVisual_FontSelect::ExternallyDefinedTextFont, "returns Value as a ExternallyDefinedTextFont (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_Array1OfBoxCharacteristicSelect.hxx
	bind_NCollection_Array1<StepVisual_BoxCharacteristicSelect>(mod, "StepVisual_Array1OfBoxCharacteristicSelect");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_Array1OfDirectionCountSelect.hxx
	bind_NCollection_Array1<StepVisual_DirectionCountSelect>(mod, "StepVisual_Array1OfDirectionCountSelect");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_Array1OfLayeredItem.hxx
	bind_NCollection_Array1<StepVisual_LayeredItem>(mod, "StepVisual_Array1OfLayeredItem");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_Array1OfSurfaceStyleElementSelect.hxx
	bind_NCollection_Array1<StepVisual_SurfaceStyleElementSelect>(mod, "StepVisual_Array1OfSurfaceStyleElementSelect");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_MarkerMember.hxx
	py::class_<StepVisual_MarkerMember, opencascade::handle<StepVisual_MarkerMember>, StepData_SelectInt> cls_StepVisual_MarkerMember(mod, "StepVisual_MarkerMember", "Defines MarkerType as unique member of MarkerSelect Works with an EnumTool");
	cls_StepVisual_MarkerMember.def(py::init<>());
	cls_StepVisual_MarkerMember.def("HasName", (Standard_Boolean (StepVisual_MarkerMember::*)() const ) &StepVisual_MarkerMember::HasName, "None");
	cls_StepVisual_MarkerMember.def("Name", (Standard_CString (StepVisual_MarkerMember::*)() const ) &StepVisual_MarkerMember::Name, "None");
	cls_StepVisual_MarkerMember.def("SetName", (Standard_Boolean (StepVisual_MarkerMember::*)(const Standard_CString)) &StepVisual_MarkerMember::SetName, "None", py::arg("name"));
	cls_StepVisual_MarkerMember.def("EnumText", (Standard_CString (StepVisual_MarkerMember::*)() const ) &StepVisual_MarkerMember::EnumText, "None");
	cls_StepVisual_MarkerMember.def("SetEnumText", (void (StepVisual_MarkerMember::*)(const Standard_Integer, const Standard_CString)) &StepVisual_MarkerMember::SetEnumText, "None", py::arg("val"), py::arg("text"));
	cls_StepVisual_MarkerMember.def("SetValue", (void (StepVisual_MarkerMember::*)(const StepVisual_MarkerType)) &StepVisual_MarkerMember::SetValue, "None", py::arg("val"));
	cls_StepVisual_MarkerMember.def("Value", (StepVisual_MarkerType (StepVisual_MarkerMember::*)() const ) &StepVisual_MarkerMember::Value, "None");
	cls_StepVisual_MarkerMember.def_static("get_type_name_", (const char * (*)()) &StepVisual_MarkerMember::get_type_name, "None");
	cls_StepVisual_MarkerMember.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_MarkerMember::get_type_descriptor, "None");
	cls_StepVisual_MarkerMember.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_MarkerMember::*)() const ) &StepVisual_MarkerMember::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_MarkerSelect.hxx
	py::class_<StepVisual_MarkerSelect, std::unique_ptr<StepVisual_MarkerSelect, Deleter<StepVisual_MarkerSelect>>, StepData_SelectType> cls_StepVisual_MarkerSelect(mod, "StepVisual_MarkerSelect", "None");
	cls_StepVisual_MarkerSelect.def(py::init<>());
	cls_StepVisual_MarkerSelect.def("CaseNum", (Standard_Integer (StepVisual_MarkerSelect::*)(const opencascade::handle<Standard_Transient> &) const ) &StepVisual_MarkerSelect::CaseNum, "Recognizes a MarkerSelect Kind Entity that is : 0 else", py::arg("ent"));
	cls_StepVisual_MarkerSelect.def("NewMember", (opencascade::handle<StepData_SelectMember> (StepVisual_MarkerSelect::*)() const ) &StepVisual_MarkerSelect::NewMember, "Returns a new MarkerMember");
	cls_StepVisual_MarkerSelect.def("CaseMem", (Standard_Integer (StepVisual_MarkerSelect::*)(const opencascade::handle<StepData_SelectMember> &) const ) &StepVisual_MarkerSelect::CaseMem, "Returns 1 for a SelectMember enum, named MARKER_TYPE", py::arg("sm"));
	cls_StepVisual_MarkerSelect.def("MarkerMember", (opencascade::handle<StepVisual_MarkerMember> (StepVisual_MarkerSelect::*)() const ) &StepVisual_MarkerSelect::MarkerMember, "Gives access to the MarkerMember in order to get/set its value");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_PresentationRepresentationSelect.hxx
	py::class_<StepVisual_PresentationRepresentationSelect, std::unique_ptr<StepVisual_PresentationRepresentationSelect, Deleter<StepVisual_PresentationRepresentationSelect>>, StepData_SelectType> cls_StepVisual_PresentationRepresentationSelect(mod, "StepVisual_PresentationRepresentationSelect", "None");
	cls_StepVisual_PresentationRepresentationSelect.def(py::init<>());
	cls_StepVisual_PresentationRepresentationSelect.def("CaseNum", (Standard_Integer (StepVisual_PresentationRepresentationSelect::*)(const opencascade::handle<Standard_Transient> &) const ) &StepVisual_PresentationRepresentationSelect::CaseNum, "Recognizes a PresentationRepresentationSelect Kind Entity that is : 1 -> PresentationRepresentation 2 -> PresentationSet 0 else", py::arg("ent"));
	cls_StepVisual_PresentationRepresentationSelect.def("PresentationRepresentation", (opencascade::handle<StepVisual_PresentationRepresentation> (StepVisual_PresentationRepresentationSelect::*)() const ) &StepVisual_PresentationRepresentationSelect::PresentationRepresentation, "returns Value as a PresentationRepresentation (Null if another type)");
	cls_StepVisual_PresentationRepresentationSelect.def("PresentationSet", (opencascade::handle<StepVisual_PresentationSet> (StepVisual_PresentationRepresentationSelect::*)() const ) &StepVisual_PresentationRepresentationSelect::PresentationSet, "returns Value as a PresentationSet (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_PresentationSizeAssignmentSelect.hxx
	py::class_<StepVisual_PresentationSizeAssignmentSelect, std::unique_ptr<StepVisual_PresentationSizeAssignmentSelect, Deleter<StepVisual_PresentationSizeAssignmentSelect>>, StepData_SelectType> cls_StepVisual_PresentationSizeAssignmentSelect(mod, "StepVisual_PresentationSizeAssignmentSelect", "None");
	cls_StepVisual_PresentationSizeAssignmentSelect.def(py::init<>());
	cls_StepVisual_PresentationSizeAssignmentSelect.def("CaseNum", (Standard_Integer (StepVisual_PresentationSizeAssignmentSelect::*)(const opencascade::handle<Standard_Transient> &) const ) &StepVisual_PresentationSizeAssignmentSelect::CaseNum, "Recognizes a PresentationSizeAssignmentSelect Kind Entity that is : 1 -> PresentationView 2 -> PresentationArea 3 -> AreaInSet 0 else", py::arg("ent"));
	cls_StepVisual_PresentationSizeAssignmentSelect.def("PresentationView", (opencascade::handle<StepVisual_PresentationView> (StepVisual_PresentationSizeAssignmentSelect::*)() const ) &StepVisual_PresentationSizeAssignmentSelect::PresentationView, "returns Value as a PresentationView (Null if another type)");
	cls_StepVisual_PresentationSizeAssignmentSelect.def("PresentationArea", (opencascade::handle<StepVisual_PresentationArea> (StepVisual_PresentationSizeAssignmentSelect::*)() const ) &StepVisual_PresentationSizeAssignmentSelect::PresentationArea, "returns Value as a PresentationArea (Null if another type)");
	cls_StepVisual_PresentationSizeAssignmentSelect.def("AreaInSet", (opencascade::handle<StepVisual_AreaInSet> (StepVisual_PresentationSizeAssignmentSelect::*)() const ) &StepVisual_PresentationSizeAssignmentSelect::AreaInSet, "returns Value as a AreaInSet (Null if another type)");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_TessellatedCurveSet.hxx
	bind_NCollection_Vector<opencascade::handle<TColStd_HSequenceOfInteger> >(mod, "StepVisual_VectorOfHSequenceOfInteger");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_TessellatedGeometricSet.hxx
	bind_NCollection_Array1<opencascade::handle<StepVisual_TessellatedItem> >(mod, "StepVisual_Array1OfTessellatedItem");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_HArray1OfPresentationStyleSelect.hxx
	py::class_<StepVisual_HArray1OfPresentationStyleSelect, opencascade::handle<StepVisual_HArray1OfPresentationStyleSelect>, StepVisual_Array1OfPresentationStyleSelect, Standard_Transient> cls_StepVisual_HArray1OfPresentationStyleSelect(mod, "StepVisual_HArray1OfPresentationStyleSelect", "None");
	cls_StepVisual_HArray1OfPresentationStyleSelect.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepVisual_HArray1OfPresentationStyleSelect.def(py::init<const Standard_Integer, const Standard_Integer, const StepVisual_Array1OfPresentationStyleSelect::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepVisual_HArray1OfPresentationStyleSelect.def(py::init<const StepVisual_Array1OfPresentationStyleSelect &>(), py::arg("theOther"));
	cls_StepVisual_HArray1OfPresentationStyleSelect.def("Array1", (const StepVisual_Array1OfPresentationStyleSelect & (StepVisual_HArray1OfPresentationStyleSelect::*)() const ) &StepVisual_HArray1OfPresentationStyleSelect::Array1, "None");
	cls_StepVisual_HArray1OfPresentationStyleSelect.def("ChangeArray1", (StepVisual_Array1OfPresentationStyleSelect & (StepVisual_HArray1OfPresentationStyleSelect::*)()) &StepVisual_HArray1OfPresentationStyleSelect::ChangeArray1, "None");
	cls_StepVisual_HArray1OfPresentationStyleSelect.def_static("get_type_name_", (const char * (*)()) &StepVisual_HArray1OfPresentationStyleSelect::get_type_name, "None");
	cls_StepVisual_HArray1OfPresentationStyleSelect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_HArray1OfPresentationStyleSelect::get_type_descriptor, "None");
	cls_StepVisual_HArray1OfPresentationStyleSelect.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_HArray1OfPresentationStyleSelect::*)() const ) &StepVisual_HArray1OfPresentationStyleSelect::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_HArray1OfPresentationStyleAssignment.hxx
	py::class_<StepVisual_HArray1OfPresentationStyleAssignment, opencascade::handle<StepVisual_HArray1OfPresentationStyleAssignment>, StepVisual_Array1OfPresentationStyleAssignment, Standard_Transient> cls_StepVisual_HArray1OfPresentationStyleAssignment(mod, "StepVisual_HArray1OfPresentationStyleAssignment", "None");
	cls_StepVisual_HArray1OfPresentationStyleAssignment.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepVisual_HArray1OfPresentationStyleAssignment.def(py::init<const Standard_Integer, const Standard_Integer, const StepVisual_Array1OfPresentationStyleAssignment::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepVisual_HArray1OfPresentationStyleAssignment.def(py::init<const StepVisual_Array1OfPresentationStyleAssignment &>(), py::arg("theOther"));
	cls_StepVisual_HArray1OfPresentationStyleAssignment.def("Array1", (const StepVisual_Array1OfPresentationStyleAssignment & (StepVisual_HArray1OfPresentationStyleAssignment::*)() const ) &StepVisual_HArray1OfPresentationStyleAssignment::Array1, "None");
	cls_StepVisual_HArray1OfPresentationStyleAssignment.def("ChangeArray1", (StepVisual_Array1OfPresentationStyleAssignment & (StepVisual_HArray1OfPresentationStyleAssignment::*)()) &StepVisual_HArray1OfPresentationStyleAssignment::ChangeArray1, "None");
	cls_StepVisual_HArray1OfPresentationStyleAssignment.def_static("get_type_name_", (const char * (*)()) &StepVisual_HArray1OfPresentationStyleAssignment::get_type_name, "None");
	cls_StepVisual_HArray1OfPresentationStyleAssignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_HArray1OfPresentationStyleAssignment::get_type_descriptor, "None");
	cls_StepVisual_HArray1OfPresentationStyleAssignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_HArray1OfPresentationStyleAssignment::*)() const ) &StepVisual_HArray1OfPresentationStyleAssignment::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_HArray1OfAnnotationPlaneElement.hxx
	py::class_<StepVisual_HArray1OfAnnotationPlaneElement, opencascade::handle<StepVisual_HArray1OfAnnotationPlaneElement>, StepVisual_Array1OfAnnotationPlaneElement, Standard_Transient> cls_StepVisual_HArray1OfAnnotationPlaneElement(mod, "StepVisual_HArray1OfAnnotationPlaneElement", "None");
	cls_StepVisual_HArray1OfAnnotationPlaneElement.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepVisual_HArray1OfAnnotationPlaneElement.def(py::init<const Standard_Integer, const Standard_Integer, const StepVisual_Array1OfAnnotationPlaneElement::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepVisual_HArray1OfAnnotationPlaneElement.def(py::init<const StepVisual_Array1OfAnnotationPlaneElement &>(), py::arg("theOther"));
	cls_StepVisual_HArray1OfAnnotationPlaneElement.def("Array1", (const StepVisual_Array1OfAnnotationPlaneElement & (StepVisual_HArray1OfAnnotationPlaneElement::*)() const ) &StepVisual_HArray1OfAnnotationPlaneElement::Array1, "None");
	cls_StepVisual_HArray1OfAnnotationPlaneElement.def("ChangeArray1", (StepVisual_Array1OfAnnotationPlaneElement & (StepVisual_HArray1OfAnnotationPlaneElement::*)()) &StepVisual_HArray1OfAnnotationPlaneElement::ChangeArray1, "None");
	cls_StepVisual_HArray1OfAnnotationPlaneElement.def_static("get_type_name_", (const char * (*)()) &StepVisual_HArray1OfAnnotationPlaneElement::get_type_name, "None");
	cls_StepVisual_HArray1OfAnnotationPlaneElement.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_HArray1OfAnnotationPlaneElement::get_type_descriptor, "None");
	cls_StepVisual_HArray1OfAnnotationPlaneElement.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_HArray1OfAnnotationPlaneElement::*)() const ) &StepVisual_HArray1OfAnnotationPlaneElement::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_HArray1OfBoxCharacteristicSelect.hxx
	py::class_<StepVisual_HArray1OfBoxCharacteristicSelect, opencascade::handle<StepVisual_HArray1OfBoxCharacteristicSelect>, StepVisual_Array1OfBoxCharacteristicSelect, Standard_Transient> cls_StepVisual_HArray1OfBoxCharacteristicSelect(mod, "StepVisual_HArray1OfBoxCharacteristicSelect", "None");
	cls_StepVisual_HArray1OfBoxCharacteristicSelect.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepVisual_HArray1OfBoxCharacteristicSelect.def(py::init<const Standard_Integer, const Standard_Integer, const StepVisual_Array1OfBoxCharacteristicSelect::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepVisual_HArray1OfBoxCharacteristicSelect.def(py::init<const StepVisual_Array1OfBoxCharacteristicSelect &>(), py::arg("theOther"));
	cls_StepVisual_HArray1OfBoxCharacteristicSelect.def("Array1", (const StepVisual_Array1OfBoxCharacteristicSelect & (StepVisual_HArray1OfBoxCharacteristicSelect::*)() const ) &StepVisual_HArray1OfBoxCharacteristicSelect::Array1, "None");
	cls_StepVisual_HArray1OfBoxCharacteristicSelect.def("ChangeArray1", (StepVisual_Array1OfBoxCharacteristicSelect & (StepVisual_HArray1OfBoxCharacteristicSelect::*)()) &StepVisual_HArray1OfBoxCharacteristicSelect::ChangeArray1, "None");
	cls_StepVisual_HArray1OfBoxCharacteristicSelect.def_static("get_type_name_", (const char * (*)()) &StepVisual_HArray1OfBoxCharacteristicSelect::get_type_name, "None");
	cls_StepVisual_HArray1OfBoxCharacteristicSelect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_HArray1OfBoxCharacteristicSelect::get_type_descriptor, "None");
	cls_StepVisual_HArray1OfBoxCharacteristicSelect.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_HArray1OfBoxCharacteristicSelect::*)() const ) &StepVisual_HArray1OfBoxCharacteristicSelect::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect.hxx
	py::class_<StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect, opencascade::handle<StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect>, StepVisual_Array1OfCameraModelD3MultiClippingInterectionSelect, Standard_Transient> cls_StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect(mod, "StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect", "None");
	cls_StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect.def(py::init<const Standard_Integer, const Standard_Integer, const StepVisual_Array1OfCameraModelD3MultiClippingInterectionSelect::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect.def(py::init<const StepVisual_Array1OfCameraModelD3MultiClippingInterectionSelect &>(), py::arg("theOther"));
	cls_StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect.def("Array1", (const StepVisual_Array1OfCameraModelD3MultiClippingInterectionSelect & (StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect::*)() const ) &StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect::Array1, "None");
	cls_StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect.def("ChangeArray1", (StepVisual_Array1OfCameraModelD3MultiClippingInterectionSelect & (StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect::*)()) &StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect::ChangeArray1, "None");
	cls_StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect.def_static("get_type_name_", (const char * (*)()) &StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect::get_type_name, "None");
	cls_StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect::get_type_descriptor, "None");
	cls_StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect::*)() const ) &StepVisual_HArray1OfCameraModelD3MultiClippingInterectionSelect::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_HArray1OfCameraModelD3MultiClippingUnionSelect.hxx
	py::class_<StepVisual_HArray1OfCameraModelD3MultiClippingUnionSelect, opencascade::handle<StepVisual_HArray1OfCameraModelD3MultiClippingUnionSelect>, StepVisual_Array1OfCameraModelD3MultiClippingUnionSelect, Standard_Transient> cls_StepVisual_HArray1OfCameraModelD3MultiClippingUnionSelect(mod, "StepVisual_HArray1OfCameraModelD3MultiClippingUnionSelect", "None");
	cls_StepVisual_HArray1OfCameraModelD3MultiClippingUnionSelect.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepVisual_HArray1OfCameraModelD3MultiClippingUnionSelect.def(py::init<const Standard_Integer, const Standard_Integer, const StepVisual_Array1OfCameraModelD3MultiClippingUnionSelect::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepVisual_HArray1OfCameraModelD3MultiClippingUnionSelect.def(py::init<const StepVisual_Array1OfCameraModelD3MultiClippingUnionSelect &>(), py::arg("theOther"));
	cls_StepVisual_HArray1OfCameraModelD3MultiClippingUnionSelect.def("Array1", (const StepVisual_Array1OfCameraModelD3MultiClippingUnionSelect & (StepVisual_HArray1OfCameraModelD3MultiClippingUnionSelect::*)() const ) &StepVisual_HArray1OfCameraModelD3MultiClippingUnionSelect::Array1, "None");
	cls_StepVisual_HArray1OfCameraModelD3MultiClippingUnionSelect.def("ChangeArray1", (StepVisual_Array1OfCameraModelD3MultiClippingUnionSelect & (StepVisual_HArray1OfCameraModelD3MultiClippingUnionSelect::*)()) &StepVisual_HArray1OfCameraModelD3MultiClippingUnionSelect::ChangeArray1, "None");
	cls_StepVisual_HArray1OfCameraModelD3MultiClippingUnionSelect.def_static("get_type_name_", (const char * (*)()) &StepVisual_HArray1OfCameraModelD3MultiClippingUnionSelect::get_type_name, "None");
	cls_StepVisual_HArray1OfCameraModelD3MultiClippingUnionSelect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_HArray1OfCameraModelD3MultiClippingUnionSelect::get_type_descriptor, "None");
	cls_StepVisual_HArray1OfCameraModelD3MultiClippingUnionSelect.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_HArray1OfCameraModelD3MultiClippingUnionSelect::*)() const ) &StepVisual_HArray1OfCameraModelD3MultiClippingUnionSelect::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_HArray1OfCurveStyleFontPattern.hxx
	py::class_<StepVisual_HArray1OfCurveStyleFontPattern, opencascade::handle<StepVisual_HArray1OfCurveStyleFontPattern>, StepVisual_Array1OfCurveStyleFontPattern, Standard_Transient> cls_StepVisual_HArray1OfCurveStyleFontPattern(mod, "StepVisual_HArray1OfCurveStyleFontPattern", "None");
	cls_StepVisual_HArray1OfCurveStyleFontPattern.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepVisual_HArray1OfCurveStyleFontPattern.def(py::init<const Standard_Integer, const Standard_Integer, const StepVisual_Array1OfCurveStyleFontPattern::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepVisual_HArray1OfCurveStyleFontPattern.def(py::init<const StepVisual_Array1OfCurveStyleFontPattern &>(), py::arg("theOther"));
	cls_StepVisual_HArray1OfCurveStyleFontPattern.def("Array1", (const StepVisual_Array1OfCurveStyleFontPattern & (StepVisual_HArray1OfCurveStyleFontPattern::*)() const ) &StepVisual_HArray1OfCurveStyleFontPattern::Array1, "None");
	cls_StepVisual_HArray1OfCurveStyleFontPattern.def("ChangeArray1", (StepVisual_Array1OfCurveStyleFontPattern & (StepVisual_HArray1OfCurveStyleFontPattern::*)()) &StepVisual_HArray1OfCurveStyleFontPattern::ChangeArray1, "None");
	cls_StepVisual_HArray1OfCurveStyleFontPattern.def_static("get_type_name_", (const char * (*)()) &StepVisual_HArray1OfCurveStyleFontPattern::get_type_name, "None");
	cls_StepVisual_HArray1OfCurveStyleFontPattern.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_HArray1OfCurveStyleFontPattern::get_type_descriptor, "None");
	cls_StepVisual_HArray1OfCurveStyleFontPattern.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_HArray1OfCurveStyleFontPattern::*)() const ) &StepVisual_HArray1OfCurveStyleFontPattern::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_HArray1OfDirectionCountSelect.hxx
	py::class_<StepVisual_HArray1OfDirectionCountSelect, opencascade::handle<StepVisual_HArray1OfDirectionCountSelect>, StepVisual_Array1OfDirectionCountSelect, Standard_Transient> cls_StepVisual_HArray1OfDirectionCountSelect(mod, "StepVisual_HArray1OfDirectionCountSelect", "None");
	cls_StepVisual_HArray1OfDirectionCountSelect.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepVisual_HArray1OfDirectionCountSelect.def(py::init<const Standard_Integer, const Standard_Integer, const StepVisual_Array1OfDirectionCountSelect::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepVisual_HArray1OfDirectionCountSelect.def(py::init<const StepVisual_Array1OfDirectionCountSelect &>(), py::arg("theOther"));
	cls_StepVisual_HArray1OfDirectionCountSelect.def("Array1", (const StepVisual_Array1OfDirectionCountSelect & (StepVisual_HArray1OfDirectionCountSelect::*)() const ) &StepVisual_HArray1OfDirectionCountSelect::Array1, "None");
	cls_StepVisual_HArray1OfDirectionCountSelect.def("ChangeArray1", (StepVisual_Array1OfDirectionCountSelect & (StepVisual_HArray1OfDirectionCountSelect::*)()) &StepVisual_HArray1OfDirectionCountSelect::ChangeArray1, "None");
	cls_StepVisual_HArray1OfDirectionCountSelect.def_static("get_type_name_", (const char * (*)()) &StepVisual_HArray1OfDirectionCountSelect::get_type_name, "None");
	cls_StepVisual_HArray1OfDirectionCountSelect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_HArray1OfDirectionCountSelect::get_type_descriptor, "None");
	cls_StepVisual_HArray1OfDirectionCountSelect.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_HArray1OfDirectionCountSelect::*)() const ) &StepVisual_HArray1OfDirectionCountSelect::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_HArray1OfDraughtingCalloutElement.hxx
	py::class_<StepVisual_HArray1OfDraughtingCalloutElement, opencascade::handle<StepVisual_HArray1OfDraughtingCalloutElement>, StepVisual_Array1OfDraughtingCalloutElement, Standard_Transient> cls_StepVisual_HArray1OfDraughtingCalloutElement(mod, "StepVisual_HArray1OfDraughtingCalloutElement", "None");
	cls_StepVisual_HArray1OfDraughtingCalloutElement.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepVisual_HArray1OfDraughtingCalloutElement.def(py::init<const Standard_Integer, const Standard_Integer, const StepVisual_Array1OfDraughtingCalloutElement::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepVisual_HArray1OfDraughtingCalloutElement.def(py::init<const StepVisual_Array1OfDraughtingCalloutElement &>(), py::arg("theOther"));
	cls_StepVisual_HArray1OfDraughtingCalloutElement.def("Array1", (const StepVisual_Array1OfDraughtingCalloutElement & (StepVisual_HArray1OfDraughtingCalloutElement::*)() const ) &StepVisual_HArray1OfDraughtingCalloutElement::Array1, "None");
	cls_StepVisual_HArray1OfDraughtingCalloutElement.def("ChangeArray1", (StepVisual_Array1OfDraughtingCalloutElement & (StepVisual_HArray1OfDraughtingCalloutElement::*)()) &StepVisual_HArray1OfDraughtingCalloutElement::ChangeArray1, "None");
	cls_StepVisual_HArray1OfDraughtingCalloutElement.def_static("get_type_name_", (const char * (*)()) &StepVisual_HArray1OfDraughtingCalloutElement::get_type_name, "None");
	cls_StepVisual_HArray1OfDraughtingCalloutElement.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_HArray1OfDraughtingCalloutElement::get_type_descriptor, "None");
	cls_StepVisual_HArray1OfDraughtingCalloutElement.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_HArray1OfDraughtingCalloutElement::*)() const ) &StepVisual_HArray1OfDraughtingCalloutElement::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_HArray1OfFillStyleSelect.hxx
	py::class_<StepVisual_HArray1OfFillStyleSelect, opencascade::handle<StepVisual_HArray1OfFillStyleSelect>, StepVisual_Array1OfFillStyleSelect, Standard_Transient> cls_StepVisual_HArray1OfFillStyleSelect(mod, "StepVisual_HArray1OfFillStyleSelect", "None");
	cls_StepVisual_HArray1OfFillStyleSelect.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepVisual_HArray1OfFillStyleSelect.def(py::init<const Standard_Integer, const Standard_Integer, const StepVisual_Array1OfFillStyleSelect::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepVisual_HArray1OfFillStyleSelect.def(py::init<const StepVisual_Array1OfFillStyleSelect &>(), py::arg("theOther"));
	cls_StepVisual_HArray1OfFillStyleSelect.def("Array1", (const StepVisual_Array1OfFillStyleSelect & (StepVisual_HArray1OfFillStyleSelect::*)() const ) &StepVisual_HArray1OfFillStyleSelect::Array1, "None");
	cls_StepVisual_HArray1OfFillStyleSelect.def("ChangeArray1", (StepVisual_Array1OfFillStyleSelect & (StepVisual_HArray1OfFillStyleSelect::*)()) &StepVisual_HArray1OfFillStyleSelect::ChangeArray1, "None");
	cls_StepVisual_HArray1OfFillStyleSelect.def_static("get_type_name_", (const char * (*)()) &StepVisual_HArray1OfFillStyleSelect::get_type_name, "None");
	cls_StepVisual_HArray1OfFillStyleSelect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_HArray1OfFillStyleSelect::get_type_descriptor, "None");
	cls_StepVisual_HArray1OfFillStyleSelect.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_HArray1OfFillStyleSelect::*)() const ) &StepVisual_HArray1OfFillStyleSelect::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_HArray1OfInvisibleItem.hxx
	py::class_<StepVisual_HArray1OfInvisibleItem, opencascade::handle<StepVisual_HArray1OfInvisibleItem>, StepVisual_Array1OfInvisibleItem, Standard_Transient> cls_StepVisual_HArray1OfInvisibleItem(mod, "StepVisual_HArray1OfInvisibleItem", "None");
	cls_StepVisual_HArray1OfInvisibleItem.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepVisual_HArray1OfInvisibleItem.def(py::init<const Standard_Integer, const Standard_Integer, const StepVisual_Array1OfInvisibleItem::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepVisual_HArray1OfInvisibleItem.def(py::init<const StepVisual_Array1OfInvisibleItem &>(), py::arg("theOther"));
	cls_StepVisual_HArray1OfInvisibleItem.def("Array1", (const StepVisual_Array1OfInvisibleItem & (StepVisual_HArray1OfInvisibleItem::*)() const ) &StepVisual_HArray1OfInvisibleItem::Array1, "None");
	cls_StepVisual_HArray1OfInvisibleItem.def("ChangeArray1", (StepVisual_Array1OfInvisibleItem & (StepVisual_HArray1OfInvisibleItem::*)()) &StepVisual_HArray1OfInvisibleItem::ChangeArray1, "None");
	cls_StepVisual_HArray1OfInvisibleItem.def_static("get_type_name_", (const char * (*)()) &StepVisual_HArray1OfInvisibleItem::get_type_name, "None");
	cls_StepVisual_HArray1OfInvisibleItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_HArray1OfInvisibleItem::get_type_descriptor, "None");
	cls_StepVisual_HArray1OfInvisibleItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_HArray1OfInvisibleItem::*)() const ) &StepVisual_HArray1OfInvisibleItem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_HArray1OfLayeredItem.hxx
	py::class_<StepVisual_HArray1OfLayeredItem, opencascade::handle<StepVisual_HArray1OfLayeredItem>, StepVisual_Array1OfLayeredItem, Standard_Transient> cls_StepVisual_HArray1OfLayeredItem(mod, "StepVisual_HArray1OfLayeredItem", "None");
	cls_StepVisual_HArray1OfLayeredItem.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepVisual_HArray1OfLayeredItem.def(py::init<const Standard_Integer, const Standard_Integer, const StepVisual_Array1OfLayeredItem::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepVisual_HArray1OfLayeredItem.def(py::init<const StepVisual_Array1OfLayeredItem &>(), py::arg("theOther"));
	cls_StepVisual_HArray1OfLayeredItem.def("Array1", (const StepVisual_Array1OfLayeredItem & (StepVisual_HArray1OfLayeredItem::*)() const ) &StepVisual_HArray1OfLayeredItem::Array1, "None");
	cls_StepVisual_HArray1OfLayeredItem.def("ChangeArray1", (StepVisual_Array1OfLayeredItem & (StepVisual_HArray1OfLayeredItem::*)()) &StepVisual_HArray1OfLayeredItem::ChangeArray1, "None");
	cls_StepVisual_HArray1OfLayeredItem.def_static("get_type_name_", (const char * (*)()) &StepVisual_HArray1OfLayeredItem::get_type_name, "None");
	cls_StepVisual_HArray1OfLayeredItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_HArray1OfLayeredItem::get_type_descriptor, "None");
	cls_StepVisual_HArray1OfLayeredItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_HArray1OfLayeredItem::*)() const ) &StepVisual_HArray1OfLayeredItem::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_HArray1OfStyleContextSelect.hxx
	py::class_<StepVisual_HArray1OfStyleContextSelect, opencascade::handle<StepVisual_HArray1OfStyleContextSelect>, StepVisual_Array1OfStyleContextSelect, Standard_Transient> cls_StepVisual_HArray1OfStyleContextSelect(mod, "StepVisual_HArray1OfStyleContextSelect", "None");
	cls_StepVisual_HArray1OfStyleContextSelect.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepVisual_HArray1OfStyleContextSelect.def(py::init<const Standard_Integer, const Standard_Integer, const StepVisual_Array1OfStyleContextSelect::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepVisual_HArray1OfStyleContextSelect.def(py::init<const StepVisual_Array1OfStyleContextSelect &>(), py::arg("theOther"));
	cls_StepVisual_HArray1OfStyleContextSelect.def("Array1", (const StepVisual_Array1OfStyleContextSelect & (StepVisual_HArray1OfStyleContextSelect::*)() const ) &StepVisual_HArray1OfStyleContextSelect::Array1, "None");
	cls_StepVisual_HArray1OfStyleContextSelect.def("ChangeArray1", (StepVisual_Array1OfStyleContextSelect & (StepVisual_HArray1OfStyleContextSelect::*)()) &StepVisual_HArray1OfStyleContextSelect::ChangeArray1, "None");
	cls_StepVisual_HArray1OfStyleContextSelect.def_static("get_type_name_", (const char * (*)()) &StepVisual_HArray1OfStyleContextSelect::get_type_name, "None");
	cls_StepVisual_HArray1OfStyleContextSelect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_HArray1OfStyleContextSelect::get_type_descriptor, "None");
	cls_StepVisual_HArray1OfStyleContextSelect.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_HArray1OfStyleContextSelect::*)() const ) &StepVisual_HArray1OfStyleContextSelect::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_HArray1OfSurfaceStyleElementSelect.hxx
	py::class_<StepVisual_HArray1OfSurfaceStyleElementSelect, opencascade::handle<StepVisual_HArray1OfSurfaceStyleElementSelect>, StepVisual_Array1OfSurfaceStyleElementSelect, Standard_Transient> cls_StepVisual_HArray1OfSurfaceStyleElementSelect(mod, "StepVisual_HArray1OfSurfaceStyleElementSelect", "None");
	cls_StepVisual_HArray1OfSurfaceStyleElementSelect.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepVisual_HArray1OfSurfaceStyleElementSelect.def(py::init<const Standard_Integer, const Standard_Integer, const StepVisual_Array1OfSurfaceStyleElementSelect::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepVisual_HArray1OfSurfaceStyleElementSelect.def(py::init<const StepVisual_Array1OfSurfaceStyleElementSelect &>(), py::arg("theOther"));
	cls_StepVisual_HArray1OfSurfaceStyleElementSelect.def("Array1", (const StepVisual_Array1OfSurfaceStyleElementSelect & (StepVisual_HArray1OfSurfaceStyleElementSelect::*)() const ) &StepVisual_HArray1OfSurfaceStyleElementSelect::Array1, "None");
	cls_StepVisual_HArray1OfSurfaceStyleElementSelect.def("ChangeArray1", (StepVisual_Array1OfSurfaceStyleElementSelect & (StepVisual_HArray1OfSurfaceStyleElementSelect::*)()) &StepVisual_HArray1OfSurfaceStyleElementSelect::ChangeArray1, "None");
	cls_StepVisual_HArray1OfSurfaceStyleElementSelect.def_static("get_type_name_", (const char * (*)()) &StepVisual_HArray1OfSurfaceStyleElementSelect::get_type_name, "None");
	cls_StepVisual_HArray1OfSurfaceStyleElementSelect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_HArray1OfSurfaceStyleElementSelect::get_type_descriptor, "None");
	cls_StepVisual_HArray1OfSurfaceStyleElementSelect.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_HArray1OfSurfaceStyleElementSelect::*)() const ) &StepVisual_HArray1OfSurfaceStyleElementSelect::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\StepVisual_HArray1OfTextOrCharacter.hxx
	py::class_<StepVisual_HArray1OfTextOrCharacter, opencascade::handle<StepVisual_HArray1OfTextOrCharacter>, StepVisual_Array1OfTextOrCharacter, Standard_Transient> cls_StepVisual_HArray1OfTextOrCharacter(mod, "StepVisual_HArray1OfTextOrCharacter", "None");
	cls_StepVisual_HArray1OfTextOrCharacter.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_StepVisual_HArray1OfTextOrCharacter.def(py::init<const Standard_Integer, const Standard_Integer, const StepVisual_Array1OfTextOrCharacter::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_StepVisual_HArray1OfTextOrCharacter.def(py::init<const StepVisual_Array1OfTextOrCharacter &>(), py::arg("theOther"));
	cls_StepVisual_HArray1OfTextOrCharacter.def("Array1", (const StepVisual_Array1OfTextOrCharacter & (StepVisual_HArray1OfTextOrCharacter::*)() const ) &StepVisual_HArray1OfTextOrCharacter::Array1, "None");
	cls_StepVisual_HArray1OfTextOrCharacter.def("ChangeArray1", (StepVisual_Array1OfTextOrCharacter & (StepVisual_HArray1OfTextOrCharacter::*)()) &StepVisual_HArray1OfTextOrCharacter::ChangeArray1, "None");
	cls_StepVisual_HArray1OfTextOrCharacter.def_static("get_type_name_", (const char * (*)()) &StepVisual_HArray1OfTextOrCharacter::get_type_name, "None");
	cls_StepVisual_HArray1OfTextOrCharacter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepVisual_HArray1OfTextOrCharacter::get_type_descriptor, "None");
	cls_StepVisual_HArray1OfTextOrCharacter.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepVisual_HArray1OfTextOrCharacter::*)() const ) &StepVisual_HArray1OfTextOrCharacter::DynamicType, "None");


}
