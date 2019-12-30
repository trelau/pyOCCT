/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <TCollection_HAsciiString.hxx>
#include <Standard_Std.hxx>
#include <StepRepr_RepresentationItem.hxx>
#include <Standard_Type.hxx>
#include <StepData_SelectType.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <StepBasic_GeneralProperty.hxx>
#include <StepRepr_PropertyDefinition.hxx>
#include <StepRepr_PropertyDefinitionRelationship.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <StepRepr_ShapeAspectRelationship.hxx>
#include <StepRepr_RepresentedDefinition.hxx>
#include <StepRepr_Representation.hxx>
#include <StepRepr_PropertyDefinitionRepresentation.hxx>
#include <StepRepr_DataEnvironment.hxx>
#include <StepRepr_MaterialPropertyRepresentation.hxx>
#include <NCollection_Array1.hxx>
#include <StepRepr_Array1OfMaterialPropertyRepresentation.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <StepRepr_HArray1OfMaterialPropertyRepresentation.hxx>
#include <StepRepr_Array1OfRepresentationItem.hxx>
#include <StepRepr_HArray1OfRepresentationItem.hxx>
#include <StepRepr_RepresentationContext.hxx>
#include <StepRepr_CompoundRepresentationItem.hxx>
#include <StepRepr_ProductDefinitionShape.hxx>
#include <StepData_Logical.hxx>
#include <StepBasic_CharacterizedObject.hxx>
#include <StepBasic_ProductDefinition.hxx>
#include <StepBasic_ProductDefinitionRelationship.hxx>
#include <StepBasic_DocumentFile.hxx>
#include <StepRepr_CharacterizedDefinition.hxx>
#include <StepRepr_CompositeShapeAspect.hxx>
#include <StepRepr_Array1OfShapeAspect.hxx>
#include <StepRepr_HArray1OfShapeAspect.hxx>
#include <StepRepr_ContinuosShapeAspect.hxx>
#include <StepRepr_AllAroundShapeAspect.hxx>
#include <StepRepr_DerivedShapeAspect.hxx>
#include <StepRepr_Apex.hxx>
#include <StepRepr_Array1OfPropertyDefinitionRepresentation.hxx>
#include <StepRepr_ProductDefinitionUsage.hxx>
#include <StepBasic_ProductDefinitionOrReference.hxx>
#include <StepRepr_AssemblyComponentUsage.hxx>
#include <StepRepr_AssemblyComponentUsageSubstitute.hxx>
#include <StepRepr_BetweenShapeAspect.hxx>
#include <StepRepr_CentreOfSymmetry.hxx>
#include <StepRepr_CharacterizedRepresentation.hxx>
#include <StepRepr_CompShAspAndDatumFeatAndShAsp.hxx>
#include <StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp.hxx>
#include <StepRepr_CompositeGroupShapeAspect.hxx>
#include <StepBasic_ProductDefinitionFormation.hxx>
#include <StepRepr_ConfigurationDesignItem.hxx>
#include <StepRepr_ConfigurationItem.hxx>
#include <StepRepr_ConfigurationDesign.hxx>
#include <StepBasic_ProductDefinitionEffectivity.hxx>
#include <StepRepr_ConfigurationEffectivity.hxx>
#include <StepRepr_ProductConcept.hxx>
#include <StepRepr_ConstructiveGeometryRepresentation.hxx>
#include <StepRepr_RepresentationRelationship.hxx>
#include <StepRepr_ConstructiveGeometryRepresentationRelationship.hxx>
#include <StepRepr_HArray1OfPropertyDefinitionRepresentation.hxx>
#include <StepRepr_DefinitionalRepresentation.hxx>
#include <StepRepr_DescriptiveRepresentationItem.hxx>
#include <StepRepr_Extension.hxx>
#include <StepRepr_ExternallyDefinedRepresentation.hxx>
#include <StepRepr_FeatureForDatumTargetRelationship.hxx>
#include <StepRepr_FunctionallyDefinedTransformation.hxx>
#include <StepRepr_GeometricAlignment.hxx>
#include <StepBasic_HArray1OfUncertaintyMeasureWithUnit.hxx>
#include <StepBasic_UncertaintyMeasureWithUnit.hxx>
#include <StepRepr_GlobalUncertaintyAssignedContext.hxx>
#include <StepBasic_HArray1OfNamedUnit.hxx>
#include <StepBasic_NamedUnit.hxx>
#include <StepRepr_GlobalUnitAssignedContext.hxx>
#include <NCollection_Sequence.hxx>
#include <StepRepr_SequenceOfMaterialPropertyRepresentation.hxx>
#include <StepRepr_HSequenceOfMaterialPropertyRepresentation.hxx>
#include <StepRepr_SequenceOfRepresentationItem.hxx>
#include <StepRepr_HSequenceOfRepresentationItem.hxx>
#include <StepRepr_IntegerRepresentationItem.hxx>
#include <StepRepr_ItemDefinedTransformation.hxx>
#include <StepBasic_MeasureWithUnit.hxx>
#include <StepRepr_MakeFromUsageOption.hxx>
#include <StepRepr_RepresentationMap.hxx>
#include <StepRepr_MappedItem.hxx>
#include <StepRepr_MaterialDesignation.hxx>
#include <StepRepr_MaterialProperty.hxx>
#include <StepBasic_MeasureValueMember.hxx>
#include <StepBasic_Unit.hxx>
#include <StepRepr_MeasureRepresentationItem.hxx>
#include <StepRepr_NextAssemblyUsageOccurrence.hxx>
#include <StepRepr_ParallelOffset.hxx>
#include <StepRepr_ParametricRepresentationContext.hxx>
#include <StepRepr_PerpendicularTo.hxx>
#include <StepBasic_ProductConceptContext.hxx>
#include <StepRepr_PromissoryUsageOccurrence.hxx>
#include <StepRepr_QuantifiedAssemblyComponentUsage.hxx>
#include <StepRepr_Transformation.hxx>
#include <StepRepr_ShapeRepresentationRelationship.hxx>
#include <StepRepr_RepresentationRelationshipWithTransformation.hxx>
#include <StepRepr_ReprItemAndMeasureWithUnit.hxx>
#include <StepBasic_LengthMeasureWithUnit.hxx>
#include <StepRepr_ReprItemAndLengthMeasureWithUnit.hxx>
#include <StepShape_QualifiedRepresentationItem.hxx>
#include <StepRepr_ReprItemAndMeasureWithUnitAndQRI.hxx>
#include <StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI.hxx>
#include <StepBasic_PlaneAngleMeasureWithUnit.hxx>
#include <StepRepr_ReprItemAndPlaneAngleMeasureWithUnit.hxx>
#include <StepRepr_ReprItemAndPlaneAngleMeasureWithUnitAndQRI.hxx>
#include <StepRepr_ShapeAspectDerivingRelationship.hxx>
#include <StepRepr_ShapeAspectTransition.hxx>
#include <StepRepr_ShapeDefinition.hxx>
#include <StepRepr_ShapeRepresentationRelationshipWithTransformation.hxx>
#include <StepRepr_SpecifiedHigherUsageOccurrence.hxx>
#include <StepRepr_StructuralResponseProperty.hxx>
#include <StepRepr_StructuralResponsePropertyDefinitionRepresentation.hxx>
#include <StepRepr_SuppliedPartRelationship.hxx>
#include <StepRepr_Tangent.hxx>
#include <StepRepr_ValueRange.hxx>
#include <StepRepr_ValueRepresentationItem.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_Define_HArray1.hxx>
#include <bind_NCollection_Sequence.hxx>
#include <bind_Define_HSequence.hxx>

PYBIND11_MODULE(StepRepr, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.StepData");
py::module::import("OCCT.StepBasic");
py::module::import("OCCT.NCollection");

struct ImportStepShape{
	ImportStepShape() { py::module::import("OCCT.StepShape"); }
};

// CLASS: STEPREPR_REPRESENTATIONITEM
py::class_<StepRepr_RepresentationItem, opencascade::handle<StepRepr_RepresentationItem>, Standard_Transient> cls_StepRepr_RepresentationItem(mod, "StepRepr_RepresentationItem", "None");

// Constructors
cls_StepRepr_RepresentationItem.def(py::init<>());

// Methods
cls_StepRepr_RepresentationItem.def("Init", (void (StepRepr_RepresentationItem::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_RepresentationItem::Init, "None", py::arg("aName"));
cls_StepRepr_RepresentationItem.def("SetName", (void (StepRepr_RepresentationItem::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_RepresentationItem::SetName, "None", py::arg("aName"));
cls_StepRepr_RepresentationItem.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepRepr_RepresentationItem::*)() const) &StepRepr_RepresentationItem::Name, "None");
cls_StepRepr_RepresentationItem.def_static("get_type_name_", (const char * (*)()) &StepRepr_RepresentationItem::get_type_name, "None");
cls_StepRepr_RepresentationItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_RepresentationItem::get_type_descriptor, "None");
cls_StepRepr_RepresentationItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_RepresentationItem::*)() const) &StepRepr_RepresentationItem::DynamicType, "None");

// CLASS: STEPREPR_REPRESENTEDDEFINITION
py::class_<StepRepr_RepresentedDefinition, StepData_SelectType> cls_StepRepr_RepresentedDefinition(mod, "StepRepr_RepresentedDefinition", "Representation of STEP SELECT type RepresentedDefinition");

// Constructors
cls_StepRepr_RepresentedDefinition.def(py::init<>());

// Methods
// cls_StepRepr_RepresentedDefinition.def_static("operator new_", (void * (*)(size_t)) &StepRepr_RepresentedDefinition::operator new, "None", py::arg("theSize"));
// cls_StepRepr_RepresentedDefinition.def_static("operator delete_", (void (*)(void *)) &StepRepr_RepresentedDefinition::operator delete, "None", py::arg("theAddress"));
// cls_StepRepr_RepresentedDefinition.def_static("operator new[]_", (void * (*)(size_t)) &StepRepr_RepresentedDefinition::operator new[], "None", py::arg("theSize"));
// cls_StepRepr_RepresentedDefinition.def_static("operator delete[]_", (void (*)(void *)) &StepRepr_RepresentedDefinition::operator delete[], "None", py::arg("theAddress"));
// cls_StepRepr_RepresentedDefinition.def_static("operator new_", (void * (*)(size_t, void *)) &StepRepr_RepresentedDefinition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepRepr_RepresentedDefinition.def_static("operator delete_", (void (*)(void *, void *)) &StepRepr_RepresentedDefinition::operator delete, "None", py::arg(""), py::arg(""));
cls_StepRepr_RepresentedDefinition.def("CaseNum", (Standard_Integer (StepRepr_RepresentedDefinition::*)(const opencascade::handle<Standard_Transient> &) const) &StepRepr_RepresentedDefinition::CaseNum, "Recognizes a kind of RepresentedDefinition select type 1 -> GeneralProperty from StepBasic 2 -> PropertyDefinition from StepRepr 3 -> PropertyDefinitionRelationship from StepRepr 4 -> ShapeAspect from StepRepr 5 -> ShapeAspectRelationship from StepRepr 0 else", py::arg("ent"));
cls_StepRepr_RepresentedDefinition.def("GeneralProperty", (opencascade::handle<StepBasic_GeneralProperty> (StepRepr_RepresentedDefinition::*)() const) &StepRepr_RepresentedDefinition::GeneralProperty, "Returns Value as GeneralProperty (or Null if another type)");
cls_StepRepr_RepresentedDefinition.def("PropertyDefinition", (opencascade::handle<StepRepr_PropertyDefinition> (StepRepr_RepresentedDefinition::*)() const) &StepRepr_RepresentedDefinition::PropertyDefinition, "Returns Value as PropertyDefinition (or Null if another type)");
cls_StepRepr_RepresentedDefinition.def("PropertyDefinitionRelationship", (opencascade::handle<StepRepr_PropertyDefinitionRelationship> (StepRepr_RepresentedDefinition::*)() const) &StepRepr_RepresentedDefinition::PropertyDefinitionRelationship, "Returns Value as PropertyDefinitionRelationship (or Null if another type)");
cls_StepRepr_RepresentedDefinition.def("ShapeAspect", (opencascade::handle<StepRepr_ShapeAspect> (StepRepr_RepresentedDefinition::*)() const) &StepRepr_RepresentedDefinition::ShapeAspect, "Returns Value as ShapeAspect (or Null if another type)");
cls_StepRepr_RepresentedDefinition.def("ShapeAspectRelationship", (opencascade::handle<StepRepr_ShapeAspectRelationship> (StepRepr_RepresentedDefinition::*)() const) &StepRepr_RepresentedDefinition::ShapeAspectRelationship, "Returns Value as ShapeAspectRelationship (or Null if another type)");

// CLASS: STEPREPR_PROPERTYDEFINITIONREPRESENTATION
py::class_<StepRepr_PropertyDefinitionRepresentation, opencascade::handle<StepRepr_PropertyDefinitionRepresentation>, Standard_Transient> cls_StepRepr_PropertyDefinitionRepresentation(mod, "StepRepr_PropertyDefinitionRepresentation", "Representation of STEP entity PropertyDefinitionRepresentation");

// Constructors
cls_StepRepr_PropertyDefinitionRepresentation.def(py::init<>());

// Methods
cls_StepRepr_PropertyDefinitionRepresentation.def("Init", (void (StepRepr_PropertyDefinitionRepresentation::*)(const StepRepr_RepresentedDefinition &, const opencascade::handle<StepRepr_Representation> &)) &StepRepr_PropertyDefinitionRepresentation::Init, "Initialize all fields (own and inherited)", py::arg("aDefinition"), py::arg("aUsedRepresentation"));
cls_StepRepr_PropertyDefinitionRepresentation.def("Definition", (StepRepr_RepresentedDefinition (StepRepr_PropertyDefinitionRepresentation::*)() const) &StepRepr_PropertyDefinitionRepresentation::Definition, "Returns field Definition");
cls_StepRepr_PropertyDefinitionRepresentation.def("SetDefinition", (void (StepRepr_PropertyDefinitionRepresentation::*)(const StepRepr_RepresentedDefinition &)) &StepRepr_PropertyDefinitionRepresentation::SetDefinition, "Set field Definition", py::arg("Definition"));
cls_StepRepr_PropertyDefinitionRepresentation.def("UsedRepresentation", (opencascade::handle<StepRepr_Representation> (StepRepr_PropertyDefinitionRepresentation::*)() const) &StepRepr_PropertyDefinitionRepresentation::UsedRepresentation, "Returns field UsedRepresentation");
cls_StepRepr_PropertyDefinitionRepresentation.def("SetUsedRepresentation", (void (StepRepr_PropertyDefinitionRepresentation::*)(const opencascade::handle<StepRepr_Representation> &)) &StepRepr_PropertyDefinitionRepresentation::SetUsedRepresentation, "Set field UsedRepresentation", py::arg("UsedRepresentation"));
cls_StepRepr_PropertyDefinitionRepresentation.def_static("get_type_name_", (const char * (*)()) &StepRepr_PropertyDefinitionRepresentation::get_type_name, "None");
cls_StepRepr_PropertyDefinitionRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_PropertyDefinitionRepresentation::get_type_descriptor, "None");
cls_StepRepr_PropertyDefinitionRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_PropertyDefinitionRepresentation::*)() const) &StepRepr_PropertyDefinitionRepresentation::DynamicType, "None");

// CLASS: STEPREPR_MATERIALPROPERTYREPRESENTATION
py::class_<StepRepr_MaterialPropertyRepresentation, opencascade::handle<StepRepr_MaterialPropertyRepresentation>, StepRepr_PropertyDefinitionRepresentation> cls_StepRepr_MaterialPropertyRepresentation(mod, "StepRepr_MaterialPropertyRepresentation", "Representation of STEP entity MaterialPropertyRepresentation");

// Constructors
cls_StepRepr_MaterialPropertyRepresentation.def(py::init<>());

// Methods
cls_StepRepr_MaterialPropertyRepresentation.def("Init", (void (StepRepr_MaterialPropertyRepresentation::*)(const StepRepr_RepresentedDefinition &, const opencascade::handle<StepRepr_Representation> &, const opencascade::handle<StepRepr_DataEnvironment> &)) &StepRepr_MaterialPropertyRepresentation::Init, "Initialize all fields (own and inherited)", py::arg("aPropertyDefinitionRepresentation_Definition"), py::arg("aPropertyDefinitionRepresentation_UsedRepresentation"), py::arg("aDependentEnvironment"));
cls_StepRepr_MaterialPropertyRepresentation.def("DependentEnvironment", (opencascade::handle<StepRepr_DataEnvironment> (StepRepr_MaterialPropertyRepresentation::*)() const) &StepRepr_MaterialPropertyRepresentation::DependentEnvironment, "Returns field DependentEnvironment");
cls_StepRepr_MaterialPropertyRepresentation.def("SetDependentEnvironment", (void (StepRepr_MaterialPropertyRepresentation::*)(const opencascade::handle<StepRepr_DataEnvironment> &)) &StepRepr_MaterialPropertyRepresentation::SetDependentEnvironment, "Set field DependentEnvironment", py::arg("DependentEnvironment"));
cls_StepRepr_MaterialPropertyRepresentation.def_static("get_type_name_", (const char * (*)()) &StepRepr_MaterialPropertyRepresentation::get_type_name, "None");
cls_StepRepr_MaterialPropertyRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_MaterialPropertyRepresentation::get_type_descriptor, "None");
cls_StepRepr_MaterialPropertyRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_MaterialPropertyRepresentation::*)() const) &StepRepr_MaterialPropertyRepresentation::DynamicType, "None");

// TYPEDEF: STEPREPR_ARRAY1OFMATERIALPROPERTYREPRESENTATION
bind_NCollection_Array1<opencascade::handle<StepRepr_MaterialPropertyRepresentation> >(mod, "StepRepr_Array1OfMaterialPropertyRepresentation", py::module_local(false));

// CLASS: STEPREPR_HARRAY1OFMATERIALPROPERTYREPRESENTATION
bind_Define_HArray1<StepRepr_HArray1OfMaterialPropertyRepresentation, StepRepr_Array1OfMaterialPropertyRepresentation>(mod, "StepRepr_HArray1OfMaterialPropertyRepresentation");

// TYPEDEF: STEPREPR_ARRAY1OFREPRESENTATIONITEM
bind_NCollection_Array1<opencascade::handle<StepRepr_RepresentationItem> >(mod, "StepRepr_Array1OfRepresentationItem", py::module_local(false));

// CLASS: STEPREPR_HARRAY1OFREPRESENTATIONITEM
bind_Define_HArray1<StepRepr_HArray1OfRepresentationItem, StepRepr_Array1OfRepresentationItem>(mod, "StepRepr_HArray1OfRepresentationItem");

// CLASS: STEPREPR_REPRESENTATION
py::class_<StepRepr_Representation, opencascade::handle<StepRepr_Representation>, Standard_Transient> cls_StepRepr_Representation(mod, "StepRepr_Representation", "None");

// Constructors
cls_StepRepr_Representation.def(py::init<>());

// Methods
cls_StepRepr_Representation.def("Init", (void (StepRepr_Representation::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_HArray1OfRepresentationItem> &, const opencascade::handle<StepRepr_RepresentationContext> &)) &StepRepr_Representation::Init, "None", py::arg("aName"), py::arg("aItems"), py::arg("aContextOfItems"));
cls_StepRepr_Representation.def("SetName", (void (StepRepr_Representation::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_Representation::SetName, "None", py::arg("aName"));
cls_StepRepr_Representation.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepRepr_Representation::*)() const) &StepRepr_Representation::Name, "None");
cls_StepRepr_Representation.def("SetItems", (void (StepRepr_Representation::*)(const opencascade::handle<StepRepr_HArray1OfRepresentationItem> &)) &StepRepr_Representation::SetItems, "None", py::arg("aItems"));
cls_StepRepr_Representation.def("Items", (opencascade::handle<StepRepr_HArray1OfRepresentationItem> (StepRepr_Representation::*)() const) &StepRepr_Representation::Items, "None");
cls_StepRepr_Representation.def("ItemsValue", (opencascade::handle<StepRepr_RepresentationItem> (StepRepr_Representation::*)(const Standard_Integer) const) &StepRepr_Representation::ItemsValue, "None", py::arg("num"));
cls_StepRepr_Representation.def("NbItems", (Standard_Integer (StepRepr_Representation::*)() const) &StepRepr_Representation::NbItems, "None");
cls_StepRepr_Representation.def("SetContextOfItems", (void (StepRepr_Representation::*)(const opencascade::handle<StepRepr_RepresentationContext> &)) &StepRepr_Representation::SetContextOfItems, "None", py::arg("aContextOfItems"));
cls_StepRepr_Representation.def("ContextOfItems", (opencascade::handle<StepRepr_RepresentationContext> (StepRepr_Representation::*)() const) &StepRepr_Representation::ContextOfItems, "None");
cls_StepRepr_Representation.def_static("get_type_name_", (const char * (*)()) &StepRepr_Representation::get_type_name, "None");
cls_StepRepr_Representation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_Representation::get_type_descriptor, "None");
cls_StepRepr_Representation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_Representation::*)() const) &StepRepr_Representation::DynamicType, "None");

// CLASS: STEPREPR_COMPOUNDREPRESENTATIONITEM
py::class_<StepRepr_CompoundRepresentationItem, opencascade::handle<StepRepr_CompoundRepresentationItem>, StepRepr_RepresentationItem> cls_StepRepr_CompoundRepresentationItem(mod, "StepRepr_CompoundRepresentationItem", "Added for Dimensional Tolerances");

// Constructors
cls_StepRepr_CompoundRepresentationItem.def(py::init<>());

// Methods
cls_StepRepr_CompoundRepresentationItem.def("Init", (void (StepRepr_CompoundRepresentationItem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_HArray1OfRepresentationItem> &)) &StepRepr_CompoundRepresentationItem::Init, "None", py::arg("aName"), py::arg("item_element"));
cls_StepRepr_CompoundRepresentationItem.def("ItemElement", (opencascade::handle<StepRepr_HArray1OfRepresentationItem> (StepRepr_CompoundRepresentationItem::*)() const) &StepRepr_CompoundRepresentationItem::ItemElement, "None");
cls_StepRepr_CompoundRepresentationItem.def("NbItemElement", (Standard_Integer (StepRepr_CompoundRepresentationItem::*)() const) &StepRepr_CompoundRepresentationItem::NbItemElement, "None");
cls_StepRepr_CompoundRepresentationItem.def("SetItemElement", (void (StepRepr_CompoundRepresentationItem::*)(const opencascade::handle<StepRepr_HArray1OfRepresentationItem> &)) &StepRepr_CompoundRepresentationItem::SetItemElement, "None", py::arg("item_element"));
cls_StepRepr_CompoundRepresentationItem.def("ItemElementValue", (opencascade::handle<StepRepr_RepresentationItem> (StepRepr_CompoundRepresentationItem::*)(const Standard_Integer) const) &StepRepr_CompoundRepresentationItem::ItemElementValue, "None", py::arg("num"));
cls_StepRepr_CompoundRepresentationItem.def("SetItemElementValue", (void (StepRepr_CompoundRepresentationItem::*)(const Standard_Integer, const opencascade::handle<StepRepr_RepresentationItem> &)) &StepRepr_CompoundRepresentationItem::SetItemElementValue, "None", py::arg("num"), py::arg("anelement"));
cls_StepRepr_CompoundRepresentationItem.def_static("get_type_name_", (const char * (*)()) &StepRepr_CompoundRepresentationItem::get_type_name, "None");
cls_StepRepr_CompoundRepresentationItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_CompoundRepresentationItem::get_type_descriptor, "None");
cls_StepRepr_CompoundRepresentationItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_CompoundRepresentationItem::*)() const) &StepRepr_CompoundRepresentationItem::DynamicType, "None");

// CLASS: STEPREPR_SHAPEASPECT
py::class_<StepRepr_ShapeAspect, opencascade::handle<StepRepr_ShapeAspect>, Standard_Transient> cls_StepRepr_ShapeAspect(mod, "StepRepr_ShapeAspect", "None");

// Constructors
cls_StepRepr_ShapeAspect.def(py::init<>());

// Methods
cls_StepRepr_ShapeAspect.def("Init", (void (StepRepr_ShapeAspect::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &, const StepData_Logical)) &StepRepr_ShapeAspect::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aOfShape"), py::arg("aProductDefinitional"));
cls_StepRepr_ShapeAspect.def("SetName", (void (StepRepr_ShapeAspect::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ShapeAspect::SetName, "None", py::arg("aName"));
cls_StepRepr_ShapeAspect.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepRepr_ShapeAspect::*)() const) &StepRepr_ShapeAspect::Name, "None");
cls_StepRepr_ShapeAspect.def("SetDescription", (void (StepRepr_ShapeAspect::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ShapeAspect::SetDescription, "None", py::arg("aDescription"));
cls_StepRepr_ShapeAspect.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepRepr_ShapeAspect::*)() const) &StepRepr_ShapeAspect::Description, "None");
cls_StepRepr_ShapeAspect.def("SetOfShape", (void (StepRepr_ShapeAspect::*)(const opencascade::handle<StepRepr_ProductDefinitionShape> &)) &StepRepr_ShapeAspect::SetOfShape, "None", py::arg("aOfShape"));
cls_StepRepr_ShapeAspect.def("OfShape", (opencascade::handle<StepRepr_ProductDefinitionShape> (StepRepr_ShapeAspect::*)() const) &StepRepr_ShapeAspect::OfShape, "None");
cls_StepRepr_ShapeAspect.def("SetProductDefinitional", (void (StepRepr_ShapeAspect::*)(const StepData_Logical)) &StepRepr_ShapeAspect::SetProductDefinitional, "None", py::arg("aProductDefinitional"));
cls_StepRepr_ShapeAspect.def("ProductDefinitional", (StepData_Logical (StepRepr_ShapeAspect::*)() const) &StepRepr_ShapeAspect::ProductDefinitional, "None");
cls_StepRepr_ShapeAspect.def_static("get_type_name_", (const char * (*)()) &StepRepr_ShapeAspect::get_type_name, "None");
cls_StepRepr_ShapeAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ShapeAspect::get_type_descriptor, "None");
cls_StepRepr_ShapeAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ShapeAspect::*)() const) &StepRepr_ShapeAspect::DynamicType, "None");

// CLASS: STEPREPR_CHARACTERIZEDDEFINITION
py::class_<StepRepr_CharacterizedDefinition, StepData_SelectType> cls_StepRepr_CharacterizedDefinition(mod, "StepRepr_CharacterizedDefinition", "Representation of STEP SELECT type CharacterizedDefinition");

// Constructors
cls_StepRepr_CharacterizedDefinition.def(py::init<>());

// Methods
// cls_StepRepr_CharacterizedDefinition.def_static("operator new_", (void * (*)(size_t)) &StepRepr_CharacterizedDefinition::operator new, "None", py::arg("theSize"));
// cls_StepRepr_CharacterizedDefinition.def_static("operator delete_", (void (*)(void *)) &StepRepr_CharacterizedDefinition::operator delete, "None", py::arg("theAddress"));
// cls_StepRepr_CharacterizedDefinition.def_static("operator new[]_", (void * (*)(size_t)) &StepRepr_CharacterizedDefinition::operator new[], "None", py::arg("theSize"));
// cls_StepRepr_CharacterizedDefinition.def_static("operator delete[]_", (void (*)(void *)) &StepRepr_CharacterizedDefinition::operator delete[], "None", py::arg("theAddress"));
// cls_StepRepr_CharacterizedDefinition.def_static("operator new_", (void * (*)(size_t, void *)) &StepRepr_CharacterizedDefinition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepRepr_CharacterizedDefinition.def_static("operator delete_", (void (*)(void *, void *)) &StepRepr_CharacterizedDefinition::operator delete, "None", py::arg(""), py::arg(""));
cls_StepRepr_CharacterizedDefinition.def("CaseNum", (Standard_Integer (StepRepr_CharacterizedDefinition::*)(const opencascade::handle<Standard_Transient> &) const) &StepRepr_CharacterizedDefinition::CaseNum, "Recognizes a kind of CharacterizedDefinition select type 1 -> CharacterizedObject from StepBasic 2 -> ProductDefinition from StepBasic 3 -> ProductDefinitionRelationship from StepBasic 4 -> ProductDefinitionShape from StepRepr 5 -> ShapeAspect from StepRepr 6 -> ShapeAspectRelationship from StepRepr 7 -> DocumentFile from StepBasic 0 else", py::arg("ent"));
cls_StepRepr_CharacterizedDefinition.def("CharacterizedObject", (opencascade::handle<StepBasic_CharacterizedObject> (StepRepr_CharacterizedDefinition::*)() const) &StepRepr_CharacterizedDefinition::CharacterizedObject, "Returns Value as CharacterizedObject (or Null if another type)");
cls_StepRepr_CharacterizedDefinition.def("ProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepRepr_CharacterizedDefinition::*)() const) &StepRepr_CharacterizedDefinition::ProductDefinition, "Returns Value as ProductDefinition (or Null if another type)");
cls_StepRepr_CharacterizedDefinition.def("ProductDefinitionRelationship", (opencascade::handle<StepBasic_ProductDefinitionRelationship> (StepRepr_CharacterizedDefinition::*)() const) &StepRepr_CharacterizedDefinition::ProductDefinitionRelationship, "Returns Value as ProductDefinitionRelationship (or Null if another type)");
cls_StepRepr_CharacterizedDefinition.def("ProductDefinitionShape", (opencascade::handle<StepRepr_ProductDefinitionShape> (StepRepr_CharacterizedDefinition::*)() const) &StepRepr_CharacterizedDefinition::ProductDefinitionShape, "Returns Value as ProductDefinitionShape (or Null if another type)");
cls_StepRepr_CharacterizedDefinition.def("ShapeAspect", (opencascade::handle<StepRepr_ShapeAspect> (StepRepr_CharacterizedDefinition::*)() const) &StepRepr_CharacterizedDefinition::ShapeAspect, "Returns Value as ShapeAspect (or Null if another type)");
cls_StepRepr_CharacterizedDefinition.def("ShapeAspectRelationship", (opencascade::handle<StepRepr_ShapeAspectRelationship> (StepRepr_CharacterizedDefinition::*)() const) &StepRepr_CharacterizedDefinition::ShapeAspectRelationship, "Returns Value as ShapeAspectRelationship (or Null if another type)");
cls_StepRepr_CharacterizedDefinition.def("DocumentFile", (opencascade::handle<StepBasic_DocumentFile> (StepRepr_CharacterizedDefinition::*)() const) &StepRepr_CharacterizedDefinition::DocumentFile, "Returns Value as DocumentFile (or Null if another type)");

// CLASS: STEPREPR_PROPERTYDEFINITION
py::class_<StepRepr_PropertyDefinition, opencascade::handle<StepRepr_PropertyDefinition>, Standard_Transient> cls_StepRepr_PropertyDefinition(mod, "StepRepr_PropertyDefinition", "Representation of STEP entity PropertyDefinition");

// Constructors
cls_StepRepr_PropertyDefinition.def(py::init<>());

// Methods
cls_StepRepr_PropertyDefinition.def("Init", (void (StepRepr_PropertyDefinition::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const StepRepr_CharacterizedDefinition &)) &StepRepr_PropertyDefinition::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"), py::arg("aDefinition"));
cls_StepRepr_PropertyDefinition.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepRepr_PropertyDefinition::*)() const) &StepRepr_PropertyDefinition::Name, "Returns field Name");
cls_StepRepr_PropertyDefinition.def("SetName", (void (StepRepr_PropertyDefinition::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_PropertyDefinition::SetName, "Set field Name", py::arg("Name"));
cls_StepRepr_PropertyDefinition.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepRepr_PropertyDefinition::*)() const) &StepRepr_PropertyDefinition::Description, "Returns field Description");
cls_StepRepr_PropertyDefinition.def("SetDescription", (void (StepRepr_PropertyDefinition::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_PropertyDefinition::SetDescription, "Set field Description", py::arg("Description"));
cls_StepRepr_PropertyDefinition.def("HasDescription", (Standard_Boolean (StepRepr_PropertyDefinition::*)() const) &StepRepr_PropertyDefinition::HasDescription, "Returns True if optional field Description is defined");
cls_StepRepr_PropertyDefinition.def("Definition", (StepRepr_CharacterizedDefinition (StepRepr_PropertyDefinition::*)() const) &StepRepr_PropertyDefinition::Definition, "Returns field Definition");
cls_StepRepr_PropertyDefinition.def("SetDefinition", (void (StepRepr_PropertyDefinition::*)(const StepRepr_CharacterizedDefinition &)) &StepRepr_PropertyDefinition::SetDefinition, "Set field Definition", py::arg("Definition"));
cls_StepRepr_PropertyDefinition.def_static("get_type_name_", (const char * (*)()) &StepRepr_PropertyDefinition::get_type_name, "None");
cls_StepRepr_PropertyDefinition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_PropertyDefinition::get_type_descriptor, "None");
cls_StepRepr_PropertyDefinition.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_PropertyDefinition::*)() const) &StepRepr_PropertyDefinition::DynamicType, "None");

// CLASS: STEPREPR_PRODUCTDEFINITIONSHAPE
py::class_<StepRepr_ProductDefinitionShape, opencascade::handle<StepRepr_ProductDefinitionShape>, StepRepr_PropertyDefinition> cls_StepRepr_ProductDefinitionShape(mod, "StepRepr_ProductDefinitionShape", "Representation of STEP entity ProductDefinitionShape");

// Constructors
cls_StepRepr_ProductDefinitionShape.def(py::init<>());

// Methods
cls_StepRepr_ProductDefinitionShape.def_static("get_type_name_", (const char * (*)()) &StepRepr_ProductDefinitionShape::get_type_name, "None");
cls_StepRepr_ProductDefinitionShape.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ProductDefinitionShape::get_type_descriptor, "None");
cls_StepRepr_ProductDefinitionShape.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ProductDefinitionShape::*)() const) &StepRepr_ProductDefinitionShape::DynamicType, "None");

// CLASS: STEPREPR_COMPOSITESHAPEASPECT
py::class_<StepRepr_CompositeShapeAspect, opencascade::handle<StepRepr_CompositeShapeAspect>, StepRepr_ShapeAspect> cls_StepRepr_CompositeShapeAspect(mod, "StepRepr_CompositeShapeAspect", "Added for Dimensional Tolerances");

// Constructors
cls_StepRepr_CompositeShapeAspect.def(py::init<>());

// Methods
cls_StepRepr_CompositeShapeAspect.def_static("get_type_name_", (const char * (*)()) &StepRepr_CompositeShapeAspect::get_type_name, "None");
cls_StepRepr_CompositeShapeAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_CompositeShapeAspect::get_type_descriptor, "None");
cls_StepRepr_CompositeShapeAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_CompositeShapeAspect::*)() const) &StepRepr_CompositeShapeAspect::DynamicType, "None");

// TYPEDEF: STEPREPR_ARRAY1OFSHAPEASPECT
bind_NCollection_Array1<opencascade::handle<StepRepr_ShapeAspect> >(mod, "StepRepr_Array1OfShapeAspect", py::module_local(false));

// CLASS: STEPREPR_HARRAY1OFSHAPEASPECT
bind_Define_HArray1<StepRepr_HArray1OfShapeAspect, StepRepr_Array1OfShapeAspect>(mod, "StepRepr_HArray1OfShapeAspect");

// CLASS: STEPREPR_REPRESENTATIONCONTEXT
py::class_<StepRepr_RepresentationContext, opencascade::handle<StepRepr_RepresentationContext>, Standard_Transient> cls_StepRepr_RepresentationContext(mod, "StepRepr_RepresentationContext", "None");

// Constructors
cls_StepRepr_RepresentationContext.def(py::init<>());

// Methods
cls_StepRepr_RepresentationContext.def("Init", (void (StepRepr_RepresentationContext::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_RepresentationContext::Init, "None", py::arg("aContextIdentifier"), py::arg("aContextType"));
cls_StepRepr_RepresentationContext.def("SetContextIdentifier", (void (StepRepr_RepresentationContext::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_RepresentationContext::SetContextIdentifier, "None", py::arg("aContextIdentifier"));
cls_StepRepr_RepresentationContext.def("ContextIdentifier", (opencascade::handle<TCollection_HAsciiString> (StepRepr_RepresentationContext::*)() const) &StepRepr_RepresentationContext::ContextIdentifier, "None");
cls_StepRepr_RepresentationContext.def("SetContextType", (void (StepRepr_RepresentationContext::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_RepresentationContext::SetContextType, "None", py::arg("aContextType"));
cls_StepRepr_RepresentationContext.def("ContextType", (opencascade::handle<TCollection_HAsciiString> (StepRepr_RepresentationContext::*)() const) &StepRepr_RepresentationContext::ContextType, "None");
cls_StepRepr_RepresentationContext.def_static("get_type_name_", (const char * (*)()) &StepRepr_RepresentationContext::get_type_name, "None");
cls_StepRepr_RepresentationContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_RepresentationContext::get_type_descriptor, "None");
cls_StepRepr_RepresentationContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_RepresentationContext::*)() const) &StepRepr_RepresentationContext::DynamicType, "None");

// CLASS: STEPREPR_CONTINUOSSHAPEASPECT
py::class_<StepRepr_ContinuosShapeAspect, opencascade::handle<StepRepr_ContinuosShapeAspect>, StepRepr_CompositeShapeAspect> cls_StepRepr_ContinuosShapeAspect(mod, "StepRepr_ContinuosShapeAspect", "Added for Dimensional Tolerances");

// Constructors
cls_StepRepr_ContinuosShapeAspect.def(py::init<>());

// Methods
cls_StepRepr_ContinuosShapeAspect.def_static("get_type_name_", (const char * (*)()) &StepRepr_ContinuosShapeAspect::get_type_name, "None");
cls_StepRepr_ContinuosShapeAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ContinuosShapeAspect::get_type_descriptor, "None");
cls_StepRepr_ContinuosShapeAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ContinuosShapeAspect::*)() const) &StepRepr_ContinuosShapeAspect::DynamicType, "None");

// CLASS: STEPREPR_ALLAROUNDSHAPEASPECT
py::class_<StepRepr_AllAroundShapeAspect, opencascade::handle<StepRepr_AllAroundShapeAspect>, StepRepr_ContinuosShapeAspect> cls_StepRepr_AllAroundShapeAspect(mod, "StepRepr_AllAroundShapeAspect", "Added for Dimensional Tolerances");

// Constructors
cls_StepRepr_AllAroundShapeAspect.def(py::init<>());

// Methods
cls_StepRepr_AllAroundShapeAspect.def_static("get_type_name_", (const char * (*)()) &StepRepr_AllAroundShapeAspect::get_type_name, "None");
cls_StepRepr_AllAroundShapeAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_AllAroundShapeAspect::get_type_descriptor, "None");
cls_StepRepr_AllAroundShapeAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_AllAroundShapeAspect::*)() const) &StepRepr_AllAroundShapeAspect::DynamicType, "None");

// CLASS: STEPREPR_DERIVEDSHAPEASPECT
py::class_<StepRepr_DerivedShapeAspect, opencascade::handle<StepRepr_DerivedShapeAspect>, StepRepr_ShapeAspect> cls_StepRepr_DerivedShapeAspect(mod, "StepRepr_DerivedShapeAspect", "Added for Dimensional Tolerances");

// Constructors
cls_StepRepr_DerivedShapeAspect.def(py::init<>());

// Methods
cls_StepRepr_DerivedShapeAspect.def_static("get_type_name_", (const char * (*)()) &StepRepr_DerivedShapeAspect::get_type_name, "None");
cls_StepRepr_DerivedShapeAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_DerivedShapeAspect::get_type_descriptor, "None");
cls_StepRepr_DerivedShapeAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_DerivedShapeAspect::*)() const) &StepRepr_DerivedShapeAspect::DynamicType, "None");

// CLASS: STEPREPR_APEX
py::class_<StepRepr_Apex, opencascade::handle<StepRepr_Apex>, StepRepr_DerivedShapeAspect> cls_StepRepr_Apex(mod, "StepRepr_Apex", "Added for Dimensional Tolerances");

// Constructors
cls_StepRepr_Apex.def(py::init<>());

// Methods
cls_StepRepr_Apex.def_static("get_type_name_", (const char * (*)()) &StepRepr_Apex::get_type_name, "None");
cls_StepRepr_Apex.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_Apex::get_type_descriptor, "None");
cls_StepRepr_Apex.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_Apex::*)() const) &StepRepr_Apex::DynamicType, "None");

// TYPEDEF: STEPREPR_ARRAY1OFPROPERTYDEFINITIONREPRESENTATION
bind_NCollection_Array1<opencascade::handle<StepRepr_PropertyDefinitionRepresentation> >(mod, "StepRepr_Array1OfPropertyDefinitionRepresentation", py::module_local(false));

// CLASS: STEPREPR_PRODUCTDEFINITIONUSAGE
py::class_<StepRepr_ProductDefinitionUsage, opencascade::handle<StepRepr_ProductDefinitionUsage>, StepBasic_ProductDefinitionRelationship> cls_StepRepr_ProductDefinitionUsage(mod, "StepRepr_ProductDefinitionUsage", "Representation of STEP entity ProductDefinitionUsage");

// Constructors
cls_StepRepr_ProductDefinitionUsage.def(py::init<>());

// Methods
cls_StepRepr_ProductDefinitionUsage.def_static("get_type_name_", (const char * (*)()) &StepRepr_ProductDefinitionUsage::get_type_name, "None");
cls_StepRepr_ProductDefinitionUsage.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ProductDefinitionUsage::get_type_descriptor, "None");
cls_StepRepr_ProductDefinitionUsage.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ProductDefinitionUsage::*)() const) &StepRepr_ProductDefinitionUsage::DynamicType, "None");

// CLASS: STEPREPR_ASSEMBLYCOMPONENTUSAGE
py::class_<StepRepr_AssemblyComponentUsage, opencascade::handle<StepRepr_AssemblyComponentUsage>, StepRepr_ProductDefinitionUsage> cls_StepRepr_AssemblyComponentUsage(mod, "StepRepr_AssemblyComponentUsage", "Representation of STEP entity AssemblyComponentUsage");

// Constructors
cls_StepRepr_AssemblyComponentUsage.def(py::init<>());

// Methods
cls_StepRepr_AssemblyComponentUsage.def("Init", (void (StepRepr_AssemblyComponentUsage::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ProductDefinition> &, const opencascade::handle<StepBasic_ProductDefinition> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_AssemblyComponentUsage::Init, "Initialize all fields (own and inherited)", py::arg("aProductDefinitionRelationship_Id"), py::arg("aProductDefinitionRelationship_Name"), py::arg("hasProductDefinitionRelationship_Description"), py::arg("aProductDefinitionRelationship_Description"), py::arg("aProductDefinitionRelationship_RelatingProductDefinition"), py::arg("aProductDefinitionRelationship_RelatedProductDefinition"), py::arg("hasReferenceDesignator"), py::arg("aReferenceDesignator"));
cls_StepRepr_AssemblyComponentUsage.def("Init", (void (StepRepr_AssemblyComponentUsage::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const StepBasic_ProductDefinitionOrReference &, const StepBasic_ProductDefinitionOrReference &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_AssemblyComponentUsage::Init, "Initialize all fields (own and inherited)", py::arg("aProductDefinitionRelationship_Id"), py::arg("aProductDefinitionRelationship_Name"), py::arg("hasProductDefinitionRelationship_Description"), py::arg("aProductDefinitionRelationship_Description"), py::arg("aProductDefinitionRelationship_RelatingProductDefinition"), py::arg("aProductDefinitionRelationship_RelatedProductDefinition"), py::arg("hasReferenceDesignator"), py::arg("aReferenceDesignator"));
cls_StepRepr_AssemblyComponentUsage.def("ReferenceDesignator", (opencascade::handle<TCollection_HAsciiString> (StepRepr_AssemblyComponentUsage::*)() const) &StepRepr_AssemblyComponentUsage::ReferenceDesignator, "Returns field ReferenceDesignator");
cls_StepRepr_AssemblyComponentUsage.def("SetReferenceDesignator", (void (StepRepr_AssemblyComponentUsage::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_AssemblyComponentUsage::SetReferenceDesignator, "Set field ReferenceDesignator", py::arg("ReferenceDesignator"));
cls_StepRepr_AssemblyComponentUsage.def("HasReferenceDesignator", (Standard_Boolean (StepRepr_AssemblyComponentUsage::*)() const) &StepRepr_AssemblyComponentUsage::HasReferenceDesignator, "Returns True if optional field ReferenceDesignator is defined");
cls_StepRepr_AssemblyComponentUsage.def_static("get_type_name_", (const char * (*)()) &StepRepr_AssemblyComponentUsage::get_type_name, "None");
cls_StepRepr_AssemblyComponentUsage.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_AssemblyComponentUsage::get_type_descriptor, "None");
cls_StepRepr_AssemblyComponentUsage.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_AssemblyComponentUsage::*)() const) &StepRepr_AssemblyComponentUsage::DynamicType, "None");

// CLASS: STEPREPR_ASSEMBLYCOMPONENTUSAGESUBSTITUTE
py::class_<StepRepr_AssemblyComponentUsageSubstitute, opencascade::handle<StepRepr_AssemblyComponentUsageSubstitute>, Standard_Transient> cls_StepRepr_AssemblyComponentUsageSubstitute(mod, "StepRepr_AssemblyComponentUsageSubstitute", "None");

// Constructors
cls_StepRepr_AssemblyComponentUsageSubstitute.def(py::init<>());

// Methods
cls_StepRepr_AssemblyComponentUsageSubstitute.def("Init", (void (StepRepr_AssemblyComponentUsageSubstitute::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_AssemblyComponentUsage> &, const opencascade::handle<StepRepr_AssemblyComponentUsage> &)) &StepRepr_AssemblyComponentUsageSubstitute::Init, "None", py::arg("aName"), py::arg("aDef"), py::arg("aBase"), py::arg("aSubs"));
cls_StepRepr_AssemblyComponentUsageSubstitute.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepRepr_AssemblyComponentUsageSubstitute::*)() const) &StepRepr_AssemblyComponentUsageSubstitute::Name, "None");
cls_StepRepr_AssemblyComponentUsageSubstitute.def("SetName", (void (StepRepr_AssemblyComponentUsageSubstitute::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_AssemblyComponentUsageSubstitute::SetName, "None", py::arg("aName"));
cls_StepRepr_AssemblyComponentUsageSubstitute.def("Definition", (opencascade::handle<TCollection_HAsciiString> (StepRepr_AssemblyComponentUsageSubstitute::*)() const) &StepRepr_AssemblyComponentUsageSubstitute::Definition, "None");
cls_StepRepr_AssemblyComponentUsageSubstitute.def("SetDefinition", (void (StepRepr_AssemblyComponentUsageSubstitute::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_AssemblyComponentUsageSubstitute::SetDefinition, "None", py::arg("aDef"));
cls_StepRepr_AssemblyComponentUsageSubstitute.def("Base", (opencascade::handle<StepRepr_AssemblyComponentUsage> (StepRepr_AssemblyComponentUsageSubstitute::*)() const) &StepRepr_AssemblyComponentUsageSubstitute::Base, "None");
cls_StepRepr_AssemblyComponentUsageSubstitute.def("SetBase", (void (StepRepr_AssemblyComponentUsageSubstitute::*)(const opencascade::handle<StepRepr_AssemblyComponentUsage> &)) &StepRepr_AssemblyComponentUsageSubstitute::SetBase, "None", py::arg("aBase"));
cls_StepRepr_AssemblyComponentUsageSubstitute.def("Substitute", (opencascade::handle<StepRepr_AssemblyComponentUsage> (StepRepr_AssemblyComponentUsageSubstitute::*)() const) &StepRepr_AssemblyComponentUsageSubstitute::Substitute, "None");
cls_StepRepr_AssemblyComponentUsageSubstitute.def("SetSubstitute", (void (StepRepr_AssemblyComponentUsageSubstitute::*)(const opencascade::handle<StepRepr_AssemblyComponentUsage> &)) &StepRepr_AssemblyComponentUsageSubstitute::SetSubstitute, "None", py::arg("aSubstitute"));
cls_StepRepr_AssemblyComponentUsageSubstitute.def_static("get_type_name_", (const char * (*)()) &StepRepr_AssemblyComponentUsageSubstitute::get_type_name, "None");
cls_StepRepr_AssemblyComponentUsageSubstitute.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_AssemblyComponentUsageSubstitute::get_type_descriptor, "None");
cls_StepRepr_AssemblyComponentUsageSubstitute.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_AssemblyComponentUsageSubstitute::*)() const) &StepRepr_AssemblyComponentUsageSubstitute::DynamicType, "None");

// CLASS: STEPREPR_BETWEENSHAPEASPECT
py::class_<StepRepr_BetweenShapeAspect, opencascade::handle<StepRepr_BetweenShapeAspect>, StepRepr_ContinuosShapeAspect> cls_StepRepr_BetweenShapeAspect(mod, "StepRepr_BetweenShapeAspect", "Added for Dimensional Tolerances");

// Constructors
cls_StepRepr_BetweenShapeAspect.def(py::init<>());

// Methods
cls_StepRepr_BetweenShapeAspect.def_static("get_type_name_", (const char * (*)()) &StepRepr_BetweenShapeAspect::get_type_name, "None");
cls_StepRepr_BetweenShapeAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_BetweenShapeAspect::get_type_descriptor, "None");
cls_StepRepr_BetweenShapeAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_BetweenShapeAspect::*)() const) &StepRepr_BetweenShapeAspect::DynamicType, "None");

// CLASS: STEPREPR_CENTREOFSYMMETRY
py::class_<StepRepr_CentreOfSymmetry, opencascade::handle<StepRepr_CentreOfSymmetry>, StepRepr_DerivedShapeAspect> cls_StepRepr_CentreOfSymmetry(mod, "StepRepr_CentreOfSymmetry", "Added for Dimensional Tolerances");

// Constructors
cls_StepRepr_CentreOfSymmetry.def(py::init<>());

// Methods
cls_StepRepr_CentreOfSymmetry.def_static("get_type_name_", (const char * (*)()) &StepRepr_CentreOfSymmetry::get_type_name, "None");
cls_StepRepr_CentreOfSymmetry.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_CentreOfSymmetry::get_type_descriptor, "None");
cls_StepRepr_CentreOfSymmetry.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_CentreOfSymmetry::*)() const) &StepRepr_CentreOfSymmetry::DynamicType, "None");

// CLASS: STEPREPR_CHARACTERIZEDREPRESENTATION
py::class_<StepRepr_CharacterizedRepresentation, opencascade::handle<StepRepr_CharacterizedRepresentation>, StepRepr_Representation> cls_StepRepr_CharacterizedRepresentation(mod, "StepRepr_CharacterizedRepresentation", "None");

// Constructors
cls_StepRepr_CharacterizedRepresentation.def(py::init<>());

// Methods
cls_StepRepr_CharacterizedRepresentation.def("Init", (void (StepRepr_CharacterizedRepresentation::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_HArray1OfRepresentationItem> &, const opencascade::handle<StepRepr_RepresentationContext> &)) &StepRepr_CharacterizedRepresentation::Init, "Returns a CharacterizedRepresentation", py::arg("theName"), py::arg("theDescription"), py::arg("theItems"), py::arg("theContextOfItems"));
cls_StepRepr_CharacterizedRepresentation.def("SetDescription", (void (StepRepr_CharacterizedRepresentation::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_CharacterizedRepresentation::SetDescription, "None", py::arg("theDescription"));
cls_StepRepr_CharacterizedRepresentation.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepRepr_CharacterizedRepresentation::*)() const) &StepRepr_CharacterizedRepresentation::Description, "None");
cls_StepRepr_CharacterizedRepresentation.def_static("get_type_name_", (const char * (*)()) &StepRepr_CharacterizedRepresentation::get_type_name, "None");
cls_StepRepr_CharacterizedRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_CharacterizedRepresentation::get_type_descriptor, "None");
cls_StepRepr_CharacterizedRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_CharacterizedRepresentation::*)() const) &StepRepr_CharacterizedRepresentation::DynamicType, "None");

// CLASS: STEPREPR_COMPSHASPANDDATUMFEATANDSHASP
py::class_<StepRepr_CompShAspAndDatumFeatAndShAsp, opencascade::handle<StepRepr_CompShAspAndDatumFeatAndShAsp>, StepRepr_ShapeAspect> cls_StepRepr_CompShAspAndDatumFeatAndShAsp(mod, "StepRepr_CompShAspAndDatumFeatAndShAsp", "Added for Dimensional Tolerances");

// Constructors
cls_StepRepr_CompShAspAndDatumFeatAndShAsp.def(py::init<>());

// Methods
cls_StepRepr_CompShAspAndDatumFeatAndShAsp.def_static("get_type_name_", (const char * (*)()) &StepRepr_CompShAspAndDatumFeatAndShAsp::get_type_name, "None");
cls_StepRepr_CompShAspAndDatumFeatAndShAsp.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_CompShAspAndDatumFeatAndShAsp::get_type_descriptor, "None");
cls_StepRepr_CompShAspAndDatumFeatAndShAsp.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_CompShAspAndDatumFeatAndShAsp::*)() const) &StepRepr_CompShAspAndDatumFeatAndShAsp::DynamicType, "None");

// CLASS: STEPREPR_COMPGROUPSHASPANDCOMPSHASPANDDATUMFEATANDSHASP
py::class_<StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp, opencascade::handle<StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp>, StepRepr_CompShAspAndDatumFeatAndShAsp> cls_StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp(mod, "StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp", "Added for Dimensional Tolerances");

// Constructors
cls_StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp.def(py::init<>());

// Methods
cls_StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp.def_static("get_type_name_", (const char * (*)()) &StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp::get_type_name, "None");
cls_StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp::get_type_descriptor, "None");
cls_StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp::*)() const) &StepRepr_CompGroupShAspAndCompShAspAndDatumFeatAndShAsp::DynamicType, "None");

// CLASS: STEPREPR_COMPOSITEGROUPSHAPEASPECT
py::class_<StepRepr_CompositeGroupShapeAspect, opencascade::handle<StepRepr_CompositeGroupShapeAspect>, StepRepr_CompositeShapeAspect> cls_StepRepr_CompositeGroupShapeAspect(mod, "StepRepr_CompositeGroupShapeAspect", "Added for Dimensional Tolerances");

// Constructors
cls_StepRepr_CompositeGroupShapeAspect.def(py::init<>());

// Methods
cls_StepRepr_CompositeGroupShapeAspect.def_static("get_type_name_", (const char * (*)()) &StepRepr_CompositeGroupShapeAspect::get_type_name, "None");
cls_StepRepr_CompositeGroupShapeAspect.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_CompositeGroupShapeAspect::get_type_descriptor, "None");
cls_StepRepr_CompositeGroupShapeAspect.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_CompositeGroupShapeAspect::*)() const) &StepRepr_CompositeGroupShapeAspect::DynamicType, "None");

// CLASS: STEPREPR_CONFIGURATIONDESIGNITEM
py::class_<StepRepr_ConfigurationDesignItem, StepData_SelectType> cls_StepRepr_ConfigurationDesignItem(mod, "StepRepr_ConfigurationDesignItem", "Representation of STEP SELECT type ConfigurationDesignItem");

// Constructors
cls_StepRepr_ConfigurationDesignItem.def(py::init<>());

// Methods
// cls_StepRepr_ConfigurationDesignItem.def_static("operator new_", (void * (*)(size_t)) &StepRepr_ConfigurationDesignItem::operator new, "None", py::arg("theSize"));
// cls_StepRepr_ConfigurationDesignItem.def_static("operator delete_", (void (*)(void *)) &StepRepr_ConfigurationDesignItem::operator delete, "None", py::arg("theAddress"));
// cls_StepRepr_ConfigurationDesignItem.def_static("operator new[]_", (void * (*)(size_t)) &StepRepr_ConfigurationDesignItem::operator new[], "None", py::arg("theSize"));
// cls_StepRepr_ConfigurationDesignItem.def_static("operator delete[]_", (void (*)(void *)) &StepRepr_ConfigurationDesignItem::operator delete[], "None", py::arg("theAddress"));
// cls_StepRepr_ConfigurationDesignItem.def_static("operator new_", (void * (*)(size_t, void *)) &StepRepr_ConfigurationDesignItem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepRepr_ConfigurationDesignItem.def_static("operator delete_", (void (*)(void *, void *)) &StepRepr_ConfigurationDesignItem::operator delete, "None", py::arg(""), py::arg(""));
cls_StepRepr_ConfigurationDesignItem.def("CaseNum", (Standard_Integer (StepRepr_ConfigurationDesignItem::*)(const opencascade::handle<Standard_Transient> &) const) &StepRepr_ConfigurationDesignItem::CaseNum, "Recognizes a kind of ConfigurationDesignItem select type 1 -> ProductDefinition from StepBasic 2 -> ProductDefinitionFormation from StepBasic 0 else", py::arg("ent"));
cls_StepRepr_ConfigurationDesignItem.def("ProductDefinition", (opencascade::handle<StepBasic_ProductDefinition> (StepRepr_ConfigurationDesignItem::*)() const) &StepRepr_ConfigurationDesignItem::ProductDefinition, "Returns Value as ProductDefinition (or Null if another type)");
cls_StepRepr_ConfigurationDesignItem.def("ProductDefinitionFormation", (opencascade::handle<StepBasic_ProductDefinitionFormation> (StepRepr_ConfigurationDesignItem::*)() const) &StepRepr_ConfigurationDesignItem::ProductDefinitionFormation, "Returns Value as ProductDefinitionFormation (or Null if another type)");

// CLASS: STEPREPR_CONFIGURATIONDESIGN
py::class_<StepRepr_ConfigurationDesign, opencascade::handle<StepRepr_ConfigurationDesign>, Standard_Transient> cls_StepRepr_ConfigurationDesign(mod, "StepRepr_ConfigurationDesign", "Representation of STEP entity ConfigurationDesign");

// Constructors
cls_StepRepr_ConfigurationDesign.def(py::init<>());

// Methods
cls_StepRepr_ConfigurationDesign.def("Init", (void (StepRepr_ConfigurationDesign::*)(const opencascade::handle<StepRepr_ConfigurationItem> &, const StepRepr_ConfigurationDesignItem &)) &StepRepr_ConfigurationDesign::Init, "Initialize all fields (own and inherited)", py::arg("aConfiguration"), py::arg("aDesign"));
cls_StepRepr_ConfigurationDesign.def("Configuration", (opencascade::handle<StepRepr_ConfigurationItem> (StepRepr_ConfigurationDesign::*)() const) &StepRepr_ConfigurationDesign::Configuration, "Returns field Configuration");
cls_StepRepr_ConfigurationDesign.def("SetConfiguration", (void (StepRepr_ConfigurationDesign::*)(const opencascade::handle<StepRepr_ConfigurationItem> &)) &StepRepr_ConfigurationDesign::SetConfiguration, "Set field Configuration", py::arg("Configuration"));
cls_StepRepr_ConfigurationDesign.def("Design", (StepRepr_ConfigurationDesignItem (StepRepr_ConfigurationDesign::*)() const) &StepRepr_ConfigurationDesign::Design, "Returns field Design");
cls_StepRepr_ConfigurationDesign.def("SetDesign", (void (StepRepr_ConfigurationDesign::*)(const StepRepr_ConfigurationDesignItem &)) &StepRepr_ConfigurationDesign::SetDesign, "Set field Design", py::arg("Design"));
cls_StepRepr_ConfigurationDesign.def_static("get_type_name_", (const char * (*)()) &StepRepr_ConfigurationDesign::get_type_name, "None");
cls_StepRepr_ConfigurationDesign.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ConfigurationDesign::get_type_descriptor, "None");
cls_StepRepr_ConfigurationDesign.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ConfigurationDesign::*)() const) &StepRepr_ConfigurationDesign::DynamicType, "None");

// CLASS: STEPREPR_CONFIGURATIONEFFECTIVITY
py::class_<StepRepr_ConfigurationEffectivity, opencascade::handle<StepRepr_ConfigurationEffectivity>, StepBasic_ProductDefinitionEffectivity> cls_StepRepr_ConfigurationEffectivity(mod, "StepRepr_ConfigurationEffectivity", "Representation of STEP entity ConfigurationEffectivity");

// Constructors
cls_StepRepr_ConfigurationEffectivity.def(py::init<>());

// Methods
cls_StepRepr_ConfigurationEffectivity.def("Init", (void (StepRepr_ConfigurationEffectivity::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ProductDefinitionRelationship> &, const opencascade::handle<StepRepr_ConfigurationDesign> &)) &StepRepr_ConfigurationEffectivity::Init, "Initialize all fields (own and inherited)", py::arg("aEffectivity_Id"), py::arg("aProductDefinitionEffectivity_Usage"), py::arg("aConfiguration"));
cls_StepRepr_ConfigurationEffectivity.def("Configuration", (opencascade::handle<StepRepr_ConfigurationDesign> (StepRepr_ConfigurationEffectivity::*)() const) &StepRepr_ConfigurationEffectivity::Configuration, "Returns field Configuration");
cls_StepRepr_ConfigurationEffectivity.def("SetConfiguration", (void (StepRepr_ConfigurationEffectivity::*)(const opencascade::handle<StepRepr_ConfigurationDesign> &)) &StepRepr_ConfigurationEffectivity::SetConfiguration, "Set field Configuration", py::arg("Configuration"));
cls_StepRepr_ConfigurationEffectivity.def_static("get_type_name_", (const char * (*)()) &StepRepr_ConfigurationEffectivity::get_type_name, "None");
cls_StepRepr_ConfigurationEffectivity.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ConfigurationEffectivity::get_type_descriptor, "None");
cls_StepRepr_ConfigurationEffectivity.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ConfigurationEffectivity::*)() const) &StepRepr_ConfigurationEffectivity::DynamicType, "None");

// CLASS: STEPREPR_CONFIGURATIONITEM
py::class_<StepRepr_ConfigurationItem, opencascade::handle<StepRepr_ConfigurationItem>, Standard_Transient> cls_StepRepr_ConfigurationItem(mod, "StepRepr_ConfigurationItem", "Representation of STEP entity ConfigurationItem");

// Constructors
cls_StepRepr_ConfigurationItem.def(py::init<>());

// Methods
cls_StepRepr_ConfigurationItem.def("Init", (void (StepRepr_ConfigurationItem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ProductConcept> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ConfigurationItem::Init, "Initialize all fields (own and inherited)", py::arg("aId"), py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"), py::arg("aItemConcept"), py::arg("hasPurpose"), py::arg("aPurpose"));
cls_StepRepr_ConfigurationItem.def("Id", (opencascade::handle<TCollection_HAsciiString> (StepRepr_ConfigurationItem::*)() const) &StepRepr_ConfigurationItem::Id, "Returns field Id");
cls_StepRepr_ConfigurationItem.def("SetId", (void (StepRepr_ConfigurationItem::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ConfigurationItem::SetId, "Set field Id", py::arg("Id"));
cls_StepRepr_ConfigurationItem.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepRepr_ConfigurationItem::*)() const) &StepRepr_ConfigurationItem::Name, "Returns field Name");
cls_StepRepr_ConfigurationItem.def("SetName", (void (StepRepr_ConfigurationItem::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ConfigurationItem::SetName, "Set field Name", py::arg("Name"));
cls_StepRepr_ConfigurationItem.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepRepr_ConfigurationItem::*)() const) &StepRepr_ConfigurationItem::Description, "Returns field Description");
cls_StepRepr_ConfigurationItem.def("SetDescription", (void (StepRepr_ConfigurationItem::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ConfigurationItem::SetDescription, "Set field Description", py::arg("Description"));
cls_StepRepr_ConfigurationItem.def("HasDescription", (Standard_Boolean (StepRepr_ConfigurationItem::*)() const) &StepRepr_ConfigurationItem::HasDescription, "Returns True if optional field Description is defined");
cls_StepRepr_ConfigurationItem.def("ItemConcept", (opencascade::handle<StepRepr_ProductConcept> (StepRepr_ConfigurationItem::*)() const) &StepRepr_ConfigurationItem::ItemConcept, "Returns field ItemConcept");
cls_StepRepr_ConfigurationItem.def("SetItemConcept", (void (StepRepr_ConfigurationItem::*)(const opencascade::handle<StepRepr_ProductConcept> &)) &StepRepr_ConfigurationItem::SetItemConcept, "Set field ItemConcept", py::arg("ItemConcept"));
cls_StepRepr_ConfigurationItem.def("Purpose", (opencascade::handle<TCollection_HAsciiString> (StepRepr_ConfigurationItem::*)() const) &StepRepr_ConfigurationItem::Purpose, "Returns field Purpose");
cls_StepRepr_ConfigurationItem.def("SetPurpose", (void (StepRepr_ConfigurationItem::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ConfigurationItem::SetPurpose, "Set field Purpose", py::arg("Purpose"));
cls_StepRepr_ConfigurationItem.def("HasPurpose", (Standard_Boolean (StepRepr_ConfigurationItem::*)() const) &StepRepr_ConfigurationItem::HasPurpose, "Returns True if optional field Purpose is defined");
cls_StepRepr_ConfigurationItem.def_static("get_type_name_", (const char * (*)()) &StepRepr_ConfigurationItem::get_type_name, "None");
cls_StepRepr_ConfigurationItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ConfigurationItem::get_type_descriptor, "None");
cls_StepRepr_ConfigurationItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ConfigurationItem::*)() const) &StepRepr_ConfigurationItem::DynamicType, "None");

// CLASS: STEPREPR_CONSTRUCTIVEGEOMETRYREPRESENTATION
py::class_<StepRepr_ConstructiveGeometryRepresentation, opencascade::handle<StepRepr_ConstructiveGeometryRepresentation>, StepRepr_Representation> cls_StepRepr_ConstructiveGeometryRepresentation(mod, "StepRepr_ConstructiveGeometryRepresentation", "None");

// Constructors
cls_StepRepr_ConstructiveGeometryRepresentation.def(py::init<>());

// Methods
cls_StepRepr_ConstructiveGeometryRepresentation.def_static("get_type_name_", (const char * (*)()) &StepRepr_ConstructiveGeometryRepresentation::get_type_name, "None");
cls_StepRepr_ConstructiveGeometryRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ConstructiveGeometryRepresentation::get_type_descriptor, "None");
cls_StepRepr_ConstructiveGeometryRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ConstructiveGeometryRepresentation::*)() const) &StepRepr_ConstructiveGeometryRepresentation::DynamicType, "None");

// CLASS: STEPREPR_REPRESENTATIONRELATIONSHIP
py::class_<StepRepr_RepresentationRelationship, opencascade::handle<StepRepr_RepresentationRelationship>, Standard_Transient> cls_StepRepr_RepresentationRelationship(mod, "StepRepr_RepresentationRelationship", "None");

// Constructors
cls_StepRepr_RepresentationRelationship.def(py::init<>());

// Methods
cls_StepRepr_RepresentationRelationship.def("Init", (void (StepRepr_RepresentationRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_Representation> &, const opencascade::handle<StepRepr_Representation> &)) &StepRepr_RepresentationRelationship::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aRep1"), py::arg("aRep2"));
cls_StepRepr_RepresentationRelationship.def("SetName", (void (StepRepr_RepresentationRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_RepresentationRelationship::SetName, "None", py::arg("aName"));
cls_StepRepr_RepresentationRelationship.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepRepr_RepresentationRelationship::*)() const) &StepRepr_RepresentationRelationship::Name, "None");
cls_StepRepr_RepresentationRelationship.def("SetDescription", (void (StepRepr_RepresentationRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_RepresentationRelationship::SetDescription, "None", py::arg("aDescription"));
cls_StepRepr_RepresentationRelationship.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepRepr_RepresentationRelationship::*)() const) &StepRepr_RepresentationRelationship::Description, "None");
cls_StepRepr_RepresentationRelationship.def("SetRep1", (void (StepRepr_RepresentationRelationship::*)(const opencascade::handle<StepRepr_Representation> &)) &StepRepr_RepresentationRelationship::SetRep1, "None", py::arg("aRep1"));
cls_StepRepr_RepresentationRelationship.def("Rep1", (opencascade::handle<StepRepr_Representation> (StepRepr_RepresentationRelationship::*)() const) &StepRepr_RepresentationRelationship::Rep1, "None");
cls_StepRepr_RepresentationRelationship.def("SetRep2", (void (StepRepr_RepresentationRelationship::*)(const opencascade::handle<StepRepr_Representation> &)) &StepRepr_RepresentationRelationship::SetRep2, "None", py::arg("aRep2"));
cls_StepRepr_RepresentationRelationship.def("Rep2", (opencascade::handle<StepRepr_Representation> (StepRepr_RepresentationRelationship::*)() const) &StepRepr_RepresentationRelationship::Rep2, "None");
cls_StepRepr_RepresentationRelationship.def_static("get_type_name_", (const char * (*)()) &StepRepr_RepresentationRelationship::get_type_name, "None");
cls_StepRepr_RepresentationRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_RepresentationRelationship::get_type_descriptor, "None");
cls_StepRepr_RepresentationRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_RepresentationRelationship::*)() const) &StepRepr_RepresentationRelationship::DynamicType, "None");

// CLASS: STEPREPR_CONSTRUCTIVEGEOMETRYREPRESENTATIONRELATIONSHIP
py::class_<StepRepr_ConstructiveGeometryRepresentationRelationship, opencascade::handle<StepRepr_ConstructiveGeometryRepresentationRelationship>, StepRepr_RepresentationRelationship> cls_StepRepr_ConstructiveGeometryRepresentationRelationship(mod, "StepRepr_ConstructiveGeometryRepresentationRelationship", "None");

// Constructors
cls_StepRepr_ConstructiveGeometryRepresentationRelationship.def(py::init<>());

// Methods
cls_StepRepr_ConstructiveGeometryRepresentationRelationship.def_static("get_type_name_", (const char * (*)()) &StepRepr_ConstructiveGeometryRepresentationRelationship::get_type_name, "None");
cls_StepRepr_ConstructiveGeometryRepresentationRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ConstructiveGeometryRepresentationRelationship::get_type_descriptor, "None");
cls_StepRepr_ConstructiveGeometryRepresentationRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ConstructiveGeometryRepresentationRelationship::*)() const) &StepRepr_ConstructiveGeometryRepresentationRelationship::DynamicType, "None");

// CLASS: STEPREPR_HARRAY1OFPROPERTYDEFINITIONREPRESENTATION
bind_Define_HArray1<StepRepr_HArray1OfPropertyDefinitionRepresentation, StepRepr_Array1OfPropertyDefinitionRepresentation>(mod, "StepRepr_HArray1OfPropertyDefinitionRepresentation");

// CLASS: STEPREPR_DATAENVIRONMENT
py::class_<StepRepr_DataEnvironment, opencascade::handle<StepRepr_DataEnvironment>, Standard_Transient> cls_StepRepr_DataEnvironment(mod, "StepRepr_DataEnvironment", "Representation of STEP entity DataEnvironment");

// Constructors
cls_StepRepr_DataEnvironment.def(py::init<>());

// Methods
cls_StepRepr_DataEnvironment.def("Init", (void (StepRepr_DataEnvironment::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_HArray1OfPropertyDefinitionRepresentation> &)) &StepRepr_DataEnvironment::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("aDescription"), py::arg("aElements"));
cls_StepRepr_DataEnvironment.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepRepr_DataEnvironment::*)() const) &StepRepr_DataEnvironment::Name, "Returns field Name");
cls_StepRepr_DataEnvironment.def("SetName", (void (StepRepr_DataEnvironment::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_DataEnvironment::SetName, "Set field Name", py::arg("Name"));
cls_StepRepr_DataEnvironment.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepRepr_DataEnvironment::*)() const) &StepRepr_DataEnvironment::Description, "Returns field Description");
cls_StepRepr_DataEnvironment.def("SetDescription", (void (StepRepr_DataEnvironment::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_DataEnvironment::SetDescription, "Set field Description", py::arg("Description"));
cls_StepRepr_DataEnvironment.def("Elements", (opencascade::handle<StepRepr_HArray1OfPropertyDefinitionRepresentation> (StepRepr_DataEnvironment::*)() const) &StepRepr_DataEnvironment::Elements, "Returns field Elements");
cls_StepRepr_DataEnvironment.def("SetElements", (void (StepRepr_DataEnvironment::*)(const opencascade::handle<StepRepr_HArray1OfPropertyDefinitionRepresentation> &)) &StepRepr_DataEnvironment::SetElements, "Set field Elements", py::arg("Elements"));
cls_StepRepr_DataEnvironment.def_static("get_type_name_", (const char * (*)()) &StepRepr_DataEnvironment::get_type_name, "None");
cls_StepRepr_DataEnvironment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_DataEnvironment::get_type_descriptor, "None");
cls_StepRepr_DataEnvironment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_DataEnvironment::*)() const) &StepRepr_DataEnvironment::DynamicType, "None");

// CLASS: STEPREPR_DEFINITIONALREPRESENTATION
py::class_<StepRepr_DefinitionalRepresentation, opencascade::handle<StepRepr_DefinitionalRepresentation>, StepRepr_Representation> cls_StepRepr_DefinitionalRepresentation(mod, "StepRepr_DefinitionalRepresentation", "None");

// Constructors
cls_StepRepr_DefinitionalRepresentation.def(py::init<>());

// Methods
cls_StepRepr_DefinitionalRepresentation.def_static("get_type_name_", (const char * (*)()) &StepRepr_DefinitionalRepresentation::get_type_name, "None");
cls_StepRepr_DefinitionalRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_DefinitionalRepresentation::get_type_descriptor, "None");
cls_StepRepr_DefinitionalRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_DefinitionalRepresentation::*)() const) &StepRepr_DefinitionalRepresentation::DynamicType, "None");

// CLASS: STEPREPR_DESCRIPTIVEREPRESENTATIONITEM
py::class_<StepRepr_DescriptiveRepresentationItem, opencascade::handle<StepRepr_DescriptiveRepresentationItem>, StepRepr_RepresentationItem> cls_StepRepr_DescriptiveRepresentationItem(mod, "StepRepr_DescriptiveRepresentationItem", "None");

// Constructors
cls_StepRepr_DescriptiveRepresentationItem.def(py::init<>());

// Methods
cls_StepRepr_DescriptiveRepresentationItem.def("Init", (void (StepRepr_DescriptiveRepresentationItem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_DescriptiveRepresentationItem::Init, "None", py::arg("aName"), py::arg("aDescription"));
cls_StepRepr_DescriptiveRepresentationItem.def("SetDescription", (void (StepRepr_DescriptiveRepresentationItem::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_DescriptiveRepresentationItem::SetDescription, "None", py::arg("aDescription"));
cls_StepRepr_DescriptiveRepresentationItem.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepRepr_DescriptiveRepresentationItem::*)() const) &StepRepr_DescriptiveRepresentationItem::Description, "None");
cls_StepRepr_DescriptiveRepresentationItem.def_static("get_type_name_", (const char * (*)()) &StepRepr_DescriptiveRepresentationItem::get_type_name, "None");
cls_StepRepr_DescriptiveRepresentationItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_DescriptiveRepresentationItem::get_type_descriptor, "None");
cls_StepRepr_DescriptiveRepresentationItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_DescriptiveRepresentationItem::*)() const) &StepRepr_DescriptiveRepresentationItem::DynamicType, "None");

// CLASS: STEPREPR_EXTENSION
py::class_<StepRepr_Extension, opencascade::handle<StepRepr_Extension>, StepRepr_DerivedShapeAspect> cls_StepRepr_Extension(mod, "StepRepr_Extension", "Added for Dimensional Tolerances");

// Constructors
cls_StepRepr_Extension.def(py::init<>());

// Methods
cls_StepRepr_Extension.def_static("get_type_name_", (const char * (*)()) &StepRepr_Extension::get_type_name, "None");
cls_StepRepr_Extension.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_Extension::get_type_descriptor, "None");
cls_StepRepr_Extension.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_Extension::*)() const) &StepRepr_Extension::DynamicType, "None");

// CLASS: STEPREPR_EXTERNALLYDEFINEDREPRESENTATION
py::class_<StepRepr_ExternallyDefinedRepresentation, opencascade::handle<StepRepr_ExternallyDefinedRepresentation>, StepRepr_Representation> cls_StepRepr_ExternallyDefinedRepresentation(mod, "StepRepr_ExternallyDefinedRepresentation", "None");

// Constructors
cls_StepRepr_ExternallyDefinedRepresentation.def(py::init<>());

// Methods
cls_StepRepr_ExternallyDefinedRepresentation.def_static("get_type_name_", (const char * (*)()) &StepRepr_ExternallyDefinedRepresentation::get_type_name, "None");
cls_StepRepr_ExternallyDefinedRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ExternallyDefinedRepresentation::get_type_descriptor, "None");
cls_StepRepr_ExternallyDefinedRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ExternallyDefinedRepresentation::*)() const) &StepRepr_ExternallyDefinedRepresentation::DynamicType, "None");

// CLASS: STEPREPR_SHAPEASPECTRELATIONSHIP
py::class_<StepRepr_ShapeAspectRelationship, opencascade::handle<StepRepr_ShapeAspectRelationship>, Standard_Transient> cls_StepRepr_ShapeAspectRelationship(mod, "StepRepr_ShapeAspectRelationship", "Representation of STEP entity ShapeAspectRelationship");

// Constructors
cls_StepRepr_ShapeAspectRelationship.def(py::init<>());

// Methods
cls_StepRepr_ShapeAspectRelationship.def("Init", (void (StepRepr_ShapeAspectRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ShapeAspect> &, const opencascade::handle<StepRepr_ShapeAspect> &)) &StepRepr_ShapeAspectRelationship::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"), py::arg("aRelatingShapeAspect"), py::arg("aRelatedShapeAspect"));
cls_StepRepr_ShapeAspectRelationship.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepRepr_ShapeAspectRelationship::*)() const) &StepRepr_ShapeAspectRelationship::Name, "Returns field Name");
cls_StepRepr_ShapeAspectRelationship.def("SetName", (void (StepRepr_ShapeAspectRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ShapeAspectRelationship::SetName, "Set field Name", py::arg("Name"));
cls_StepRepr_ShapeAspectRelationship.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepRepr_ShapeAspectRelationship::*)() const) &StepRepr_ShapeAspectRelationship::Description, "Returns field Description");
cls_StepRepr_ShapeAspectRelationship.def("SetDescription", (void (StepRepr_ShapeAspectRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ShapeAspectRelationship::SetDescription, "Set field Description", py::arg("Description"));
cls_StepRepr_ShapeAspectRelationship.def("HasDescription", (Standard_Boolean (StepRepr_ShapeAspectRelationship::*)() const) &StepRepr_ShapeAspectRelationship::HasDescription, "Returns True if optional field Description is defined");
cls_StepRepr_ShapeAspectRelationship.def("RelatingShapeAspect", (opencascade::handle<StepRepr_ShapeAspect> (StepRepr_ShapeAspectRelationship::*)() const) &StepRepr_ShapeAspectRelationship::RelatingShapeAspect, "Returns field RelatingShapeAspect");
cls_StepRepr_ShapeAspectRelationship.def("SetRelatingShapeAspect", (void (StepRepr_ShapeAspectRelationship::*)(const opencascade::handle<StepRepr_ShapeAspect> &)) &StepRepr_ShapeAspectRelationship::SetRelatingShapeAspect, "Set field RelatingShapeAspect", py::arg("RelatingShapeAspect"));
cls_StepRepr_ShapeAspectRelationship.def("RelatedShapeAspect", (opencascade::handle<StepRepr_ShapeAspect> (StepRepr_ShapeAspectRelationship::*)() const) &StepRepr_ShapeAspectRelationship::RelatedShapeAspect, "Returns field RelatedShapeAspect");
cls_StepRepr_ShapeAspectRelationship.def("SetRelatedShapeAspect", (void (StepRepr_ShapeAspectRelationship::*)(const opencascade::handle<StepRepr_ShapeAspect> &)) &StepRepr_ShapeAspectRelationship::SetRelatedShapeAspect, "Set field RelatedShapeAspect", py::arg("RelatedShapeAspect"));
cls_StepRepr_ShapeAspectRelationship.def_static("get_type_name_", (const char * (*)()) &StepRepr_ShapeAspectRelationship::get_type_name, "None");
cls_StepRepr_ShapeAspectRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ShapeAspectRelationship::get_type_descriptor, "None");
cls_StepRepr_ShapeAspectRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ShapeAspectRelationship::*)() const) &StepRepr_ShapeAspectRelationship::DynamicType, "None");

// CLASS: STEPREPR_FEATUREFORDATUMTARGETRELATIONSHIP
py::class_<StepRepr_FeatureForDatumTargetRelationship, opencascade::handle<StepRepr_FeatureForDatumTargetRelationship>, StepRepr_ShapeAspectRelationship> cls_StepRepr_FeatureForDatumTargetRelationship(mod, "StepRepr_FeatureForDatumTargetRelationship", "Representation of STEP entity DimensionalLocation");

// Constructors
cls_StepRepr_FeatureForDatumTargetRelationship.def(py::init<>());

// Methods
cls_StepRepr_FeatureForDatumTargetRelationship.def_static("get_type_name_", (const char * (*)()) &StepRepr_FeatureForDatumTargetRelationship::get_type_name, "None");
cls_StepRepr_FeatureForDatumTargetRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_FeatureForDatumTargetRelationship::get_type_descriptor, "None");
cls_StepRepr_FeatureForDatumTargetRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_FeatureForDatumTargetRelationship::*)() const) &StepRepr_FeatureForDatumTargetRelationship::DynamicType, "None");

// CLASS: STEPREPR_FUNCTIONALLYDEFINEDTRANSFORMATION
py::class_<StepRepr_FunctionallyDefinedTransformation, opencascade::handle<StepRepr_FunctionallyDefinedTransformation>, Standard_Transient> cls_StepRepr_FunctionallyDefinedTransformation(mod, "StepRepr_FunctionallyDefinedTransformation", "None");

// Constructors
cls_StepRepr_FunctionallyDefinedTransformation.def(py::init<>());

// Methods
cls_StepRepr_FunctionallyDefinedTransformation.def("Init", (void (StepRepr_FunctionallyDefinedTransformation::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_FunctionallyDefinedTransformation::Init, "None", py::arg("aName"), py::arg("aDescription"));
cls_StepRepr_FunctionallyDefinedTransformation.def("SetName", (void (StepRepr_FunctionallyDefinedTransformation::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_FunctionallyDefinedTransformation::SetName, "None", py::arg("aName"));
cls_StepRepr_FunctionallyDefinedTransformation.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepRepr_FunctionallyDefinedTransformation::*)() const) &StepRepr_FunctionallyDefinedTransformation::Name, "None");
cls_StepRepr_FunctionallyDefinedTransformation.def("SetDescription", (void (StepRepr_FunctionallyDefinedTransformation::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_FunctionallyDefinedTransformation::SetDescription, "None", py::arg("aDescription"));
cls_StepRepr_FunctionallyDefinedTransformation.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepRepr_FunctionallyDefinedTransformation::*)() const) &StepRepr_FunctionallyDefinedTransformation::Description, "None");
cls_StepRepr_FunctionallyDefinedTransformation.def_static("get_type_name_", (const char * (*)()) &StepRepr_FunctionallyDefinedTransformation::get_type_name, "None");
cls_StepRepr_FunctionallyDefinedTransformation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_FunctionallyDefinedTransformation::get_type_descriptor, "None");
cls_StepRepr_FunctionallyDefinedTransformation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_FunctionallyDefinedTransformation::*)() const) &StepRepr_FunctionallyDefinedTransformation::DynamicType, "None");

// CLASS: STEPREPR_GEOMETRICALIGNMENT
py::class_<StepRepr_GeometricAlignment, opencascade::handle<StepRepr_GeometricAlignment>, StepRepr_DerivedShapeAspect> cls_StepRepr_GeometricAlignment(mod, "StepRepr_GeometricAlignment", "Added for Dimensional Tolerances");

// Constructors
cls_StepRepr_GeometricAlignment.def(py::init<>());

// Methods
cls_StepRepr_GeometricAlignment.def_static("get_type_name_", (const char * (*)()) &StepRepr_GeometricAlignment::get_type_name, "None");
cls_StepRepr_GeometricAlignment.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_GeometricAlignment::get_type_descriptor, "None");
cls_StepRepr_GeometricAlignment.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_GeometricAlignment::*)() const) &StepRepr_GeometricAlignment::DynamicType, "None");

// CLASS: STEPREPR_GLOBALUNCERTAINTYASSIGNEDCONTEXT
py::class_<StepRepr_GlobalUncertaintyAssignedContext, opencascade::handle<StepRepr_GlobalUncertaintyAssignedContext>, StepRepr_RepresentationContext> cls_StepRepr_GlobalUncertaintyAssignedContext(mod, "StepRepr_GlobalUncertaintyAssignedContext", "None");

// Constructors
cls_StepRepr_GlobalUncertaintyAssignedContext.def(py::init<>());

// Methods
cls_StepRepr_GlobalUncertaintyAssignedContext.def("Init", (void (StepRepr_GlobalUncertaintyAssignedContext::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_HArray1OfUncertaintyMeasureWithUnit> &)) &StepRepr_GlobalUncertaintyAssignedContext::Init, "None", py::arg("aContextIdentifier"), py::arg("aContextType"), py::arg("aUncertainty"));
cls_StepRepr_GlobalUncertaintyAssignedContext.def("SetUncertainty", (void (StepRepr_GlobalUncertaintyAssignedContext::*)(const opencascade::handle<StepBasic_HArray1OfUncertaintyMeasureWithUnit> &)) &StepRepr_GlobalUncertaintyAssignedContext::SetUncertainty, "None", py::arg("aUncertainty"));
cls_StepRepr_GlobalUncertaintyAssignedContext.def("Uncertainty", (opencascade::handle<StepBasic_HArray1OfUncertaintyMeasureWithUnit> (StepRepr_GlobalUncertaintyAssignedContext::*)() const) &StepRepr_GlobalUncertaintyAssignedContext::Uncertainty, "None");
cls_StepRepr_GlobalUncertaintyAssignedContext.def("UncertaintyValue", (opencascade::handle<StepBasic_UncertaintyMeasureWithUnit> (StepRepr_GlobalUncertaintyAssignedContext::*)(const Standard_Integer) const) &StepRepr_GlobalUncertaintyAssignedContext::UncertaintyValue, "None", py::arg("num"));
cls_StepRepr_GlobalUncertaintyAssignedContext.def("NbUncertainty", (Standard_Integer (StepRepr_GlobalUncertaintyAssignedContext::*)() const) &StepRepr_GlobalUncertaintyAssignedContext::NbUncertainty, "None");
cls_StepRepr_GlobalUncertaintyAssignedContext.def_static("get_type_name_", (const char * (*)()) &StepRepr_GlobalUncertaintyAssignedContext::get_type_name, "None");
cls_StepRepr_GlobalUncertaintyAssignedContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_GlobalUncertaintyAssignedContext::get_type_descriptor, "None");
cls_StepRepr_GlobalUncertaintyAssignedContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_GlobalUncertaintyAssignedContext::*)() const) &StepRepr_GlobalUncertaintyAssignedContext::DynamicType, "None");

// CLASS: STEPREPR_GLOBALUNITASSIGNEDCONTEXT
py::class_<StepRepr_GlobalUnitAssignedContext, opencascade::handle<StepRepr_GlobalUnitAssignedContext>, StepRepr_RepresentationContext> cls_StepRepr_GlobalUnitAssignedContext(mod, "StepRepr_GlobalUnitAssignedContext", "None");

// Constructors
cls_StepRepr_GlobalUnitAssignedContext.def(py::init<>());

// Methods
cls_StepRepr_GlobalUnitAssignedContext.def("Init", (void (StepRepr_GlobalUnitAssignedContext::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_HArray1OfNamedUnit> &)) &StepRepr_GlobalUnitAssignedContext::Init, "None", py::arg("aContextIdentifier"), py::arg("aContextType"), py::arg("aUnits"));
cls_StepRepr_GlobalUnitAssignedContext.def("SetUnits", (void (StepRepr_GlobalUnitAssignedContext::*)(const opencascade::handle<StepBasic_HArray1OfNamedUnit> &)) &StepRepr_GlobalUnitAssignedContext::SetUnits, "None", py::arg("aUnits"));
cls_StepRepr_GlobalUnitAssignedContext.def("Units", (opencascade::handle<StepBasic_HArray1OfNamedUnit> (StepRepr_GlobalUnitAssignedContext::*)() const) &StepRepr_GlobalUnitAssignedContext::Units, "None");
cls_StepRepr_GlobalUnitAssignedContext.def("UnitsValue", (opencascade::handle<StepBasic_NamedUnit> (StepRepr_GlobalUnitAssignedContext::*)(const Standard_Integer) const) &StepRepr_GlobalUnitAssignedContext::UnitsValue, "None", py::arg("num"));
cls_StepRepr_GlobalUnitAssignedContext.def("NbUnits", (Standard_Integer (StepRepr_GlobalUnitAssignedContext::*)() const) &StepRepr_GlobalUnitAssignedContext::NbUnits, "None");
cls_StepRepr_GlobalUnitAssignedContext.def_static("get_type_name_", (const char * (*)()) &StepRepr_GlobalUnitAssignedContext::get_type_name, "None");
cls_StepRepr_GlobalUnitAssignedContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_GlobalUnitAssignedContext::get_type_descriptor, "None");
cls_StepRepr_GlobalUnitAssignedContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_GlobalUnitAssignedContext::*)() const) &StepRepr_GlobalUnitAssignedContext::DynamicType, "None");

// TYPEDEF: STEPREPR_SEQUENCEOFMATERIALPROPERTYREPRESENTATION
bind_NCollection_Sequence<opencascade::handle<StepRepr_MaterialPropertyRepresentation> >(mod, "StepRepr_SequenceOfMaterialPropertyRepresentation", py::module_local(false));

// CLASS: STEPREPR_HSEQUENCEOFMATERIALPROPERTYREPRESENTATION
bind_Define_HSequence<StepRepr_HSequenceOfMaterialPropertyRepresentation, StepRepr_SequenceOfMaterialPropertyRepresentation>(mod, "StepRepr_HSequenceOfMaterialPropertyRepresentation");

// TYPEDEF: STEPREPR_SEQUENCEOFREPRESENTATIONITEM
bind_NCollection_Sequence<opencascade::handle<StepRepr_RepresentationItem> >(mod, "StepRepr_SequenceOfRepresentationItem", py::module_local(false));

// CLASS: STEPREPR_HSEQUENCEOFREPRESENTATIONITEM
bind_Define_HSequence<StepRepr_HSequenceOfRepresentationItem, StepRepr_SequenceOfRepresentationItem>(mod, "StepRepr_HSequenceOfRepresentationItem");

// CLASS: STEPREPR_INTEGERREPRESENTATIONITEM
py::class_<StepRepr_IntegerRepresentationItem, opencascade::handle<StepRepr_IntegerRepresentationItem>, StepRepr_RepresentationItem> cls_StepRepr_IntegerRepresentationItem(mod, "StepRepr_IntegerRepresentationItem", "None");

// Constructors
cls_StepRepr_IntegerRepresentationItem.def(py::init<>());

// Methods
cls_StepRepr_IntegerRepresentationItem.def("Init", (void (StepRepr_IntegerRepresentationItem::*)(const opencascade::handle<TCollection_HAsciiString> &, const Standard_Integer)) &StepRepr_IntegerRepresentationItem::Init, "None", py::arg("theName"), py::arg("theValue"));
cls_StepRepr_IntegerRepresentationItem.def("SetValue", (void (StepRepr_IntegerRepresentationItem::*)(const Standard_Integer)) &StepRepr_IntegerRepresentationItem::SetValue, "None", py::arg("theValue"));
cls_StepRepr_IntegerRepresentationItem.def("Value", (Standard_Integer (StepRepr_IntegerRepresentationItem::*)() const) &StepRepr_IntegerRepresentationItem::Value, "None");
cls_StepRepr_IntegerRepresentationItem.def_static("get_type_name_", (const char * (*)()) &StepRepr_IntegerRepresentationItem::get_type_name, "None");
cls_StepRepr_IntegerRepresentationItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_IntegerRepresentationItem::get_type_descriptor, "None");
cls_StepRepr_IntegerRepresentationItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_IntegerRepresentationItem::*)() const) &StepRepr_IntegerRepresentationItem::DynamicType, "None");

// CLASS: STEPREPR_ITEMDEFINEDTRANSFORMATION
py::class_<StepRepr_ItemDefinedTransformation, opencascade::handle<StepRepr_ItemDefinedTransformation>, Standard_Transient> cls_StepRepr_ItemDefinedTransformation(mod, "StepRepr_ItemDefinedTransformation", "Added from StepRepr Rev2 to Rev4");

// Constructors
cls_StepRepr_ItemDefinedTransformation.def(py::init<>());

// Methods
cls_StepRepr_ItemDefinedTransformation.def("Init", (void (StepRepr_ItemDefinedTransformation::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_RepresentationItem> &, const opencascade::handle<StepRepr_RepresentationItem> &)) &StepRepr_ItemDefinedTransformation::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aTransformItem1"), py::arg("aTransformItem2"));
cls_StepRepr_ItemDefinedTransformation.def("SetName", (void (StepRepr_ItemDefinedTransformation::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ItemDefinedTransformation::SetName, "None", py::arg("aName"));
cls_StepRepr_ItemDefinedTransformation.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepRepr_ItemDefinedTransformation::*)() const) &StepRepr_ItemDefinedTransformation::Name, "None");
cls_StepRepr_ItemDefinedTransformation.def("SetDescription", (void (StepRepr_ItemDefinedTransformation::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ItemDefinedTransformation::SetDescription, "None", py::arg("aDescription"));
cls_StepRepr_ItemDefinedTransformation.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepRepr_ItemDefinedTransformation::*)() const) &StepRepr_ItemDefinedTransformation::Description, "None");
cls_StepRepr_ItemDefinedTransformation.def("SetTransformItem1", (void (StepRepr_ItemDefinedTransformation::*)(const opencascade::handle<StepRepr_RepresentationItem> &)) &StepRepr_ItemDefinedTransformation::SetTransformItem1, "None", py::arg("aItem"));
cls_StepRepr_ItemDefinedTransformation.def("TransformItem1", (opencascade::handle<StepRepr_RepresentationItem> (StepRepr_ItemDefinedTransformation::*)() const) &StepRepr_ItemDefinedTransformation::TransformItem1, "None");
cls_StepRepr_ItemDefinedTransformation.def("SetTransformItem2", (void (StepRepr_ItemDefinedTransformation::*)(const opencascade::handle<StepRepr_RepresentationItem> &)) &StepRepr_ItemDefinedTransformation::SetTransformItem2, "None", py::arg("aItem"));
cls_StepRepr_ItemDefinedTransformation.def("TransformItem2", (opencascade::handle<StepRepr_RepresentationItem> (StepRepr_ItemDefinedTransformation::*)() const) &StepRepr_ItemDefinedTransformation::TransformItem2, "None");
cls_StepRepr_ItemDefinedTransformation.def_static("get_type_name_", (const char * (*)()) &StepRepr_ItemDefinedTransformation::get_type_name, "None");
cls_StepRepr_ItemDefinedTransformation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ItemDefinedTransformation::get_type_descriptor, "None");
cls_StepRepr_ItemDefinedTransformation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ItemDefinedTransformation::*)() const) &StepRepr_ItemDefinedTransformation::DynamicType, "None");

// CLASS: STEPREPR_MAKEFROMUSAGEOPTION
py::class_<StepRepr_MakeFromUsageOption, opencascade::handle<StepRepr_MakeFromUsageOption>, StepRepr_ProductDefinitionUsage> cls_StepRepr_MakeFromUsageOption(mod, "StepRepr_MakeFromUsageOption", "Representation of STEP entity MakeFromUsageOption");

// Constructors
cls_StepRepr_MakeFromUsageOption.def(py::init<>());

// Methods
cls_StepRepr_MakeFromUsageOption.def("Init", (void (StepRepr_MakeFromUsageOption::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ProductDefinition> &, const opencascade::handle<StepBasic_ProductDefinition> &, const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepRepr_MakeFromUsageOption::Init, "Initialize all fields (own and inherited)", py::arg("aProductDefinitionRelationship_Id"), py::arg("aProductDefinitionRelationship_Name"), py::arg("hasProductDefinitionRelationship_Description"), py::arg("aProductDefinitionRelationship_Description"), py::arg("aProductDefinitionRelationship_RelatingProductDefinition"), py::arg("aProductDefinitionRelationship_RelatedProductDefinition"), py::arg("aRanking"), py::arg("aRankingRationale"), py::arg("aQuantity"));
cls_StepRepr_MakeFromUsageOption.def("Init", (void (StepRepr_MakeFromUsageOption::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const StepBasic_ProductDefinitionOrReference &, const StepBasic_ProductDefinitionOrReference &, const Standard_Integer, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepRepr_MakeFromUsageOption::Init, "Initialize all fields (own and inherited)", py::arg("aProductDefinitionRelationship_Id"), py::arg("aProductDefinitionRelationship_Name"), py::arg("hasProductDefinitionRelationship_Description"), py::arg("aProductDefinitionRelationship_Description"), py::arg("aProductDefinitionRelationship_RelatingProductDefinition"), py::arg("aProductDefinitionRelationship_RelatedProductDefinition"), py::arg("aRanking"), py::arg("aRankingRationale"), py::arg("aQuantity"));
cls_StepRepr_MakeFromUsageOption.def("Ranking", (Standard_Integer (StepRepr_MakeFromUsageOption::*)() const) &StepRepr_MakeFromUsageOption::Ranking, "Returns field Ranking");
cls_StepRepr_MakeFromUsageOption.def("SetRanking", (void (StepRepr_MakeFromUsageOption::*)(const Standard_Integer)) &StepRepr_MakeFromUsageOption::SetRanking, "Set field Ranking", py::arg("Ranking"));
cls_StepRepr_MakeFromUsageOption.def("RankingRationale", (opencascade::handle<TCollection_HAsciiString> (StepRepr_MakeFromUsageOption::*)() const) &StepRepr_MakeFromUsageOption::RankingRationale, "Returns field RankingRationale");
cls_StepRepr_MakeFromUsageOption.def("SetRankingRationale", (void (StepRepr_MakeFromUsageOption::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_MakeFromUsageOption::SetRankingRationale, "Set field RankingRationale", py::arg("RankingRationale"));
cls_StepRepr_MakeFromUsageOption.def("Quantity", (opencascade::handle<StepBasic_MeasureWithUnit> (StepRepr_MakeFromUsageOption::*)() const) &StepRepr_MakeFromUsageOption::Quantity, "Returns field Quantity");
cls_StepRepr_MakeFromUsageOption.def("SetQuantity", (void (StepRepr_MakeFromUsageOption::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepRepr_MakeFromUsageOption::SetQuantity, "Set field Quantity", py::arg("Quantity"));
cls_StepRepr_MakeFromUsageOption.def_static("get_type_name_", (const char * (*)()) &StepRepr_MakeFromUsageOption::get_type_name, "None");
cls_StepRepr_MakeFromUsageOption.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_MakeFromUsageOption::get_type_descriptor, "None");
cls_StepRepr_MakeFromUsageOption.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_MakeFromUsageOption::*)() const) &StepRepr_MakeFromUsageOption::DynamicType, "None");

// CLASS: STEPREPR_MAPPEDITEM
py::class_<StepRepr_MappedItem, opencascade::handle<StepRepr_MappedItem>, StepRepr_RepresentationItem> cls_StepRepr_MappedItem(mod, "StepRepr_MappedItem", "None");

// Constructors
cls_StepRepr_MappedItem.def(py::init<>());

// Methods
cls_StepRepr_MappedItem.def("Init", (void (StepRepr_MappedItem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_RepresentationMap> &, const opencascade::handle<StepRepr_RepresentationItem> &)) &StepRepr_MappedItem::Init, "None", py::arg("aName"), py::arg("aMappingSource"), py::arg("aMappingTarget"));
cls_StepRepr_MappedItem.def("SetMappingSource", (void (StepRepr_MappedItem::*)(const opencascade::handle<StepRepr_RepresentationMap> &)) &StepRepr_MappedItem::SetMappingSource, "None", py::arg("aMappingSource"));
cls_StepRepr_MappedItem.def("MappingSource", (opencascade::handle<StepRepr_RepresentationMap> (StepRepr_MappedItem::*)() const) &StepRepr_MappedItem::MappingSource, "None");
cls_StepRepr_MappedItem.def("SetMappingTarget", (void (StepRepr_MappedItem::*)(const opencascade::handle<StepRepr_RepresentationItem> &)) &StepRepr_MappedItem::SetMappingTarget, "None", py::arg("aMappingTarget"));
cls_StepRepr_MappedItem.def("MappingTarget", (opencascade::handle<StepRepr_RepresentationItem> (StepRepr_MappedItem::*)() const) &StepRepr_MappedItem::MappingTarget, "None");
cls_StepRepr_MappedItem.def_static("get_type_name_", (const char * (*)()) &StepRepr_MappedItem::get_type_name, "None");
cls_StepRepr_MappedItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_MappedItem::get_type_descriptor, "None");
cls_StepRepr_MappedItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_MappedItem::*)() const) &StepRepr_MappedItem::DynamicType, "None");

// CLASS: STEPREPR_MATERIALDESIGNATION
py::class_<StepRepr_MaterialDesignation, opencascade::handle<StepRepr_MaterialDesignation>, Standard_Transient> cls_StepRepr_MaterialDesignation(mod, "StepRepr_MaterialDesignation", "None");

// Constructors
cls_StepRepr_MaterialDesignation.def(py::init<>());

// Methods
cls_StepRepr_MaterialDesignation.def("Init", (void (StepRepr_MaterialDesignation::*)(const opencascade::handle<TCollection_HAsciiString> &, const StepRepr_CharacterizedDefinition &)) &StepRepr_MaterialDesignation::Init, "None", py::arg("aName"), py::arg("aOfDefinition"));
cls_StepRepr_MaterialDesignation.def("SetName", (void (StepRepr_MaterialDesignation::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_MaterialDesignation::SetName, "None", py::arg("aName"));
cls_StepRepr_MaterialDesignation.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepRepr_MaterialDesignation::*)() const) &StepRepr_MaterialDesignation::Name, "None");
cls_StepRepr_MaterialDesignation.def("SetOfDefinition", (void (StepRepr_MaterialDesignation::*)(const StepRepr_CharacterizedDefinition &)) &StepRepr_MaterialDesignation::SetOfDefinition, "None", py::arg("aOfDefinition"));
cls_StepRepr_MaterialDesignation.def("OfDefinition", (StepRepr_CharacterizedDefinition (StepRepr_MaterialDesignation::*)() const) &StepRepr_MaterialDesignation::OfDefinition, "None");
cls_StepRepr_MaterialDesignation.def_static("get_type_name_", (const char * (*)()) &StepRepr_MaterialDesignation::get_type_name, "None");
cls_StepRepr_MaterialDesignation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_MaterialDesignation::get_type_descriptor, "None");
cls_StepRepr_MaterialDesignation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_MaterialDesignation::*)() const) &StepRepr_MaterialDesignation::DynamicType, "None");

// CLASS: STEPREPR_MATERIALPROPERTY
py::class_<StepRepr_MaterialProperty, opencascade::handle<StepRepr_MaterialProperty>, StepRepr_PropertyDefinition> cls_StepRepr_MaterialProperty(mod, "StepRepr_MaterialProperty", "Representation of STEP entity MaterialProperty");

// Constructors
cls_StepRepr_MaterialProperty.def(py::init<>());

// Methods
cls_StepRepr_MaterialProperty.def_static("get_type_name_", (const char * (*)()) &StepRepr_MaterialProperty::get_type_name, "None");
cls_StepRepr_MaterialProperty.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_MaterialProperty::get_type_descriptor, "None");
cls_StepRepr_MaterialProperty.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_MaterialProperty::*)() const) &StepRepr_MaterialProperty::DynamicType, "None");

// CLASS: STEPREPR_MEASUREREPRESENTATIONITEM
py::class_<StepRepr_MeasureRepresentationItem, opencascade::handle<StepRepr_MeasureRepresentationItem>, StepRepr_RepresentationItem> cls_StepRepr_MeasureRepresentationItem(mod, "StepRepr_MeasureRepresentationItem", "Implements a measure_representation_item entity which is used for storing validation properties (e.g. area) for shapes");

// Constructors
cls_StepRepr_MeasureRepresentationItem.def(py::init<>());

// Methods
cls_StepRepr_MeasureRepresentationItem.def("Init", (void (StepRepr_MeasureRepresentationItem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureValueMember> &, const StepBasic_Unit &)) &StepRepr_MeasureRepresentationItem::Init, "Init all fields", py::arg("aName"), py::arg("aValueComponent"), py::arg("aUnitComponent"));
cls_StepRepr_MeasureRepresentationItem.def("SetMeasure", (void (StepRepr_MeasureRepresentationItem::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepRepr_MeasureRepresentationItem::SetMeasure, "None", py::arg("Measure"));
cls_StepRepr_MeasureRepresentationItem.def("Measure", (opencascade::handle<StepBasic_MeasureWithUnit> (StepRepr_MeasureRepresentationItem::*)() const) &StepRepr_MeasureRepresentationItem::Measure, "None");
cls_StepRepr_MeasureRepresentationItem.def_static("get_type_name_", (const char * (*)()) &StepRepr_MeasureRepresentationItem::get_type_name, "None");
cls_StepRepr_MeasureRepresentationItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_MeasureRepresentationItem::get_type_descriptor, "None");
cls_StepRepr_MeasureRepresentationItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_MeasureRepresentationItem::*)() const) &StepRepr_MeasureRepresentationItem::DynamicType, "None");

// CLASS: STEPREPR_NEXTASSEMBLYUSAGEOCCURRENCE
py::class_<StepRepr_NextAssemblyUsageOccurrence, opencascade::handle<StepRepr_NextAssemblyUsageOccurrence>, StepRepr_AssemblyComponentUsage> cls_StepRepr_NextAssemblyUsageOccurrence(mod, "StepRepr_NextAssemblyUsageOccurrence", "Representation of STEP entity NextAssemblyUsageOccurrence");

// Constructors
cls_StepRepr_NextAssemblyUsageOccurrence.def(py::init<>());

// Methods
cls_StepRepr_NextAssemblyUsageOccurrence.def_static("get_type_name_", (const char * (*)()) &StepRepr_NextAssemblyUsageOccurrence::get_type_name, "None");
cls_StepRepr_NextAssemblyUsageOccurrence.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_NextAssemblyUsageOccurrence::get_type_descriptor, "None");
cls_StepRepr_NextAssemblyUsageOccurrence.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_NextAssemblyUsageOccurrence::*)() const) &StepRepr_NextAssemblyUsageOccurrence::DynamicType, "None");

// CLASS: STEPREPR_PARALLELOFFSET
py::class_<StepRepr_ParallelOffset, opencascade::handle<StepRepr_ParallelOffset>, StepRepr_DerivedShapeAspect> cls_StepRepr_ParallelOffset(mod, "StepRepr_ParallelOffset", "Added for Dimensional Tolerances");

// Constructors
cls_StepRepr_ParallelOffset.def(py::init<>());

// Methods
cls_StepRepr_ParallelOffset.def("Init", (void (StepRepr_ParallelOffset::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_ProductDefinitionShape> &, const StepData_Logical, const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepRepr_ParallelOffset::Init, "Initialize all fields (own and inherited)", py::arg("theName"), py::arg("theDescription"), py::arg("theOfShape"), py::arg("theProductDefinitional"), py::arg("theOffset"));
cls_StepRepr_ParallelOffset.def("Offset", (opencascade::handle<StepBasic_MeasureWithUnit> (StepRepr_ParallelOffset::*)() const) &StepRepr_ParallelOffset::Offset, "Returns field Offset");
cls_StepRepr_ParallelOffset.def("SetOffset", (void (StepRepr_ParallelOffset::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepRepr_ParallelOffset::SetOffset, "Set field Offset", py::arg("theOffset"));
cls_StepRepr_ParallelOffset.def_static("get_type_name_", (const char * (*)()) &StepRepr_ParallelOffset::get_type_name, "None");
cls_StepRepr_ParallelOffset.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ParallelOffset::get_type_descriptor, "None");
cls_StepRepr_ParallelOffset.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ParallelOffset::*)() const) &StepRepr_ParallelOffset::DynamicType, "None");

// CLASS: STEPREPR_PARAMETRICREPRESENTATIONCONTEXT
py::class_<StepRepr_ParametricRepresentationContext, opencascade::handle<StepRepr_ParametricRepresentationContext>, StepRepr_RepresentationContext> cls_StepRepr_ParametricRepresentationContext(mod, "StepRepr_ParametricRepresentationContext", "None");

// Constructors
cls_StepRepr_ParametricRepresentationContext.def(py::init<>());

// Methods
cls_StepRepr_ParametricRepresentationContext.def_static("get_type_name_", (const char * (*)()) &StepRepr_ParametricRepresentationContext::get_type_name, "None");
cls_StepRepr_ParametricRepresentationContext.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ParametricRepresentationContext::get_type_descriptor, "None");
cls_StepRepr_ParametricRepresentationContext.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ParametricRepresentationContext::*)() const) &StepRepr_ParametricRepresentationContext::DynamicType, "None");

// CLASS: STEPREPR_PERPENDICULARTO
py::class_<StepRepr_PerpendicularTo, opencascade::handle<StepRepr_PerpendicularTo>, StepRepr_DerivedShapeAspect> cls_StepRepr_PerpendicularTo(mod, "StepRepr_PerpendicularTo", "Added for Dimensional Tolerances");

// Constructors
cls_StepRepr_PerpendicularTo.def(py::init<>());

// Methods
cls_StepRepr_PerpendicularTo.def_static("get_type_name_", (const char * (*)()) &StepRepr_PerpendicularTo::get_type_name, "None");
cls_StepRepr_PerpendicularTo.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_PerpendicularTo::get_type_descriptor, "None");
cls_StepRepr_PerpendicularTo.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_PerpendicularTo::*)() const) &StepRepr_PerpendicularTo::DynamicType, "None");

// CLASS: STEPREPR_PRODUCTCONCEPT
py::class_<StepRepr_ProductConcept, opencascade::handle<StepRepr_ProductConcept>, Standard_Transient> cls_StepRepr_ProductConcept(mod, "StepRepr_ProductConcept", "Representation of STEP entity ProductConcept");

// Constructors
cls_StepRepr_ProductConcept.def(py::init<>());

// Methods
cls_StepRepr_ProductConcept.def("Init", (void (StepRepr_ProductConcept::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ProductConceptContext> &)) &StepRepr_ProductConcept::Init, "Initialize all fields (own and inherited)", py::arg("aId"), py::arg("aName"), py::arg("hasDescription"), py::arg("aDescription"), py::arg("aMarketContext"));
cls_StepRepr_ProductConcept.def("Id", (opencascade::handle<TCollection_HAsciiString> (StepRepr_ProductConcept::*)() const) &StepRepr_ProductConcept::Id, "Returns field Id");
cls_StepRepr_ProductConcept.def("SetId", (void (StepRepr_ProductConcept::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ProductConcept::SetId, "Set field Id", py::arg("Id"));
cls_StepRepr_ProductConcept.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepRepr_ProductConcept::*)() const) &StepRepr_ProductConcept::Name, "Returns field Name");
cls_StepRepr_ProductConcept.def("SetName", (void (StepRepr_ProductConcept::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ProductConcept::SetName, "Set field Name", py::arg("Name"));
cls_StepRepr_ProductConcept.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepRepr_ProductConcept::*)() const) &StepRepr_ProductConcept::Description, "Returns field Description");
cls_StepRepr_ProductConcept.def("SetDescription", (void (StepRepr_ProductConcept::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_ProductConcept::SetDescription, "Set field Description", py::arg("Description"));
cls_StepRepr_ProductConcept.def("HasDescription", (Standard_Boolean (StepRepr_ProductConcept::*)() const) &StepRepr_ProductConcept::HasDescription, "Returns True if optional field Description is defined");
cls_StepRepr_ProductConcept.def("MarketContext", (opencascade::handle<StepBasic_ProductConceptContext> (StepRepr_ProductConcept::*)() const) &StepRepr_ProductConcept::MarketContext, "Returns field MarketContext");
cls_StepRepr_ProductConcept.def("SetMarketContext", (void (StepRepr_ProductConcept::*)(const opencascade::handle<StepBasic_ProductConceptContext> &)) &StepRepr_ProductConcept::SetMarketContext, "Set field MarketContext", py::arg("MarketContext"));
cls_StepRepr_ProductConcept.def_static("get_type_name_", (const char * (*)()) &StepRepr_ProductConcept::get_type_name, "None");
cls_StepRepr_ProductConcept.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ProductConcept::get_type_descriptor, "None");
cls_StepRepr_ProductConcept.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ProductConcept::*)() const) &StepRepr_ProductConcept::DynamicType, "None");

// CLASS: STEPREPR_PROMISSORYUSAGEOCCURRENCE
py::class_<StepRepr_PromissoryUsageOccurrence, opencascade::handle<StepRepr_PromissoryUsageOccurrence>, StepRepr_AssemblyComponentUsage> cls_StepRepr_PromissoryUsageOccurrence(mod, "StepRepr_PromissoryUsageOccurrence", "None");

// Constructors
cls_StepRepr_PromissoryUsageOccurrence.def(py::init<>());

// Methods
cls_StepRepr_PromissoryUsageOccurrence.def_static("get_type_name_", (const char * (*)()) &StepRepr_PromissoryUsageOccurrence::get_type_name, "None");
cls_StepRepr_PromissoryUsageOccurrence.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_PromissoryUsageOccurrence::get_type_descriptor, "None");
cls_StepRepr_PromissoryUsageOccurrence.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_PromissoryUsageOccurrence::*)() const) &StepRepr_PromissoryUsageOccurrence::DynamicType, "None");

// CLASS: STEPREPR_PROPERTYDEFINITIONRELATIONSHIP
py::class_<StepRepr_PropertyDefinitionRelationship, opencascade::handle<StepRepr_PropertyDefinitionRelationship>, Standard_Transient> cls_StepRepr_PropertyDefinitionRelationship(mod, "StepRepr_PropertyDefinitionRelationship", "Representation of STEP entity PropertyDefinitionRelationship");

// Constructors
cls_StepRepr_PropertyDefinitionRelationship.def(py::init<>());

// Methods
cls_StepRepr_PropertyDefinitionRelationship.def("Init", (void (StepRepr_PropertyDefinitionRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_PropertyDefinition> &, const opencascade::handle<StepRepr_PropertyDefinition> &)) &StepRepr_PropertyDefinitionRelationship::Init, "Initialize all fields (own and inherited)", py::arg("aName"), py::arg("aDescription"), py::arg("aRelatingPropertyDefinition"), py::arg("aRelatedPropertyDefinition"));
cls_StepRepr_PropertyDefinitionRelationship.def("Name", (opencascade::handle<TCollection_HAsciiString> (StepRepr_PropertyDefinitionRelationship::*)() const) &StepRepr_PropertyDefinitionRelationship::Name, "Returns field Name");
cls_StepRepr_PropertyDefinitionRelationship.def("SetName", (void (StepRepr_PropertyDefinitionRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_PropertyDefinitionRelationship::SetName, "Set field Name", py::arg("Name"));
cls_StepRepr_PropertyDefinitionRelationship.def("Description", (opencascade::handle<TCollection_HAsciiString> (StepRepr_PropertyDefinitionRelationship::*)() const) &StepRepr_PropertyDefinitionRelationship::Description, "Returns field Description");
cls_StepRepr_PropertyDefinitionRelationship.def("SetDescription", (void (StepRepr_PropertyDefinitionRelationship::*)(const opencascade::handle<TCollection_HAsciiString> &)) &StepRepr_PropertyDefinitionRelationship::SetDescription, "Set field Description", py::arg("Description"));
cls_StepRepr_PropertyDefinitionRelationship.def("RelatingPropertyDefinition", (opencascade::handle<StepRepr_PropertyDefinition> (StepRepr_PropertyDefinitionRelationship::*)() const) &StepRepr_PropertyDefinitionRelationship::RelatingPropertyDefinition, "Returns field RelatingPropertyDefinition");
cls_StepRepr_PropertyDefinitionRelationship.def("SetRelatingPropertyDefinition", (void (StepRepr_PropertyDefinitionRelationship::*)(const opencascade::handle<StepRepr_PropertyDefinition> &)) &StepRepr_PropertyDefinitionRelationship::SetRelatingPropertyDefinition, "Set field RelatingPropertyDefinition", py::arg("RelatingPropertyDefinition"));
cls_StepRepr_PropertyDefinitionRelationship.def("RelatedPropertyDefinition", (opencascade::handle<StepRepr_PropertyDefinition> (StepRepr_PropertyDefinitionRelationship::*)() const) &StepRepr_PropertyDefinitionRelationship::RelatedPropertyDefinition, "Returns field RelatedPropertyDefinition");
cls_StepRepr_PropertyDefinitionRelationship.def("SetRelatedPropertyDefinition", (void (StepRepr_PropertyDefinitionRelationship::*)(const opencascade::handle<StepRepr_PropertyDefinition> &)) &StepRepr_PropertyDefinitionRelationship::SetRelatedPropertyDefinition, "Set field RelatedPropertyDefinition", py::arg("RelatedPropertyDefinition"));
cls_StepRepr_PropertyDefinitionRelationship.def_static("get_type_name_", (const char * (*)()) &StepRepr_PropertyDefinitionRelationship::get_type_name, "None");
cls_StepRepr_PropertyDefinitionRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_PropertyDefinitionRelationship::get_type_descriptor, "None");
cls_StepRepr_PropertyDefinitionRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_PropertyDefinitionRelationship::*)() const) &StepRepr_PropertyDefinitionRelationship::DynamicType, "None");

// CLASS: STEPREPR_QUANTIFIEDASSEMBLYCOMPONENTUSAGE
py::class_<StepRepr_QuantifiedAssemblyComponentUsage, opencascade::handle<StepRepr_QuantifiedAssemblyComponentUsage>, StepRepr_AssemblyComponentUsage> cls_StepRepr_QuantifiedAssemblyComponentUsage(mod, "StepRepr_QuantifiedAssemblyComponentUsage", "Representation of STEP entity QuantifiedAssemblyComponentUsage");

// Constructors
cls_StepRepr_QuantifiedAssemblyComponentUsage.def(py::init<>());

// Methods
cls_StepRepr_QuantifiedAssemblyComponentUsage.def("Init", (void (StepRepr_QuantifiedAssemblyComponentUsage::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ProductDefinition> &, const opencascade::handle<StepBasic_ProductDefinition> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepRepr_QuantifiedAssemblyComponentUsage::Init, "Initialize all fields (own and inherited)", py::arg("aProductDefinitionRelationship_Id"), py::arg("aProductDefinitionRelationship_Name"), py::arg("hasProductDefinitionRelationship_Description"), py::arg("aProductDefinitionRelationship_Description"), py::arg("aProductDefinitionRelationship_RelatingProductDefinition"), py::arg("aProductDefinitionRelationship_RelatedProductDefinition"), py::arg("hasAssemblyComponentUsage_ReferenceDesignator"), py::arg("aAssemblyComponentUsage_ReferenceDesignator"), py::arg("aQuantity"));
cls_StepRepr_QuantifiedAssemblyComponentUsage.def("Init", (void (StepRepr_QuantifiedAssemblyComponentUsage::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const StepBasic_ProductDefinitionOrReference &, const StepBasic_ProductDefinitionOrReference &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepRepr_QuantifiedAssemblyComponentUsage::Init, "Initialize all fields (own and inherited)", py::arg("aProductDefinitionRelationship_Id"), py::arg("aProductDefinitionRelationship_Name"), py::arg("hasProductDefinitionRelationship_Description"), py::arg("aProductDefinitionRelationship_Description"), py::arg("aProductDefinitionRelationship_RelatingProductDefinition"), py::arg("aProductDefinitionRelationship_RelatedProductDefinition"), py::arg("hasAssemblyComponentUsage_ReferenceDesignator"), py::arg("aAssemblyComponentUsage_ReferenceDesignator"), py::arg("aQuantity"));
cls_StepRepr_QuantifiedAssemblyComponentUsage.def("Quantity", (opencascade::handle<StepBasic_MeasureWithUnit> (StepRepr_QuantifiedAssemblyComponentUsage::*)() const) &StepRepr_QuantifiedAssemblyComponentUsage::Quantity, "Returns field Quantity");
cls_StepRepr_QuantifiedAssemblyComponentUsage.def("SetQuantity", (void (StepRepr_QuantifiedAssemblyComponentUsage::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepRepr_QuantifiedAssemblyComponentUsage::SetQuantity, "Set field Quantity", py::arg("Quantity"));
cls_StepRepr_QuantifiedAssemblyComponentUsage.def_static("get_type_name_", (const char * (*)()) &StepRepr_QuantifiedAssemblyComponentUsage::get_type_name, "None");
cls_StepRepr_QuantifiedAssemblyComponentUsage.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_QuantifiedAssemblyComponentUsage::get_type_descriptor, "None");
cls_StepRepr_QuantifiedAssemblyComponentUsage.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_QuantifiedAssemblyComponentUsage::*)() const) &StepRepr_QuantifiedAssemblyComponentUsage::DynamicType, "None");

// CLASS: STEPREPR_REPRESENTATIONMAP
py::class_<StepRepr_RepresentationMap, opencascade::handle<StepRepr_RepresentationMap>, Standard_Transient> cls_StepRepr_RepresentationMap(mod, "StepRepr_RepresentationMap", "None");

// Constructors
cls_StepRepr_RepresentationMap.def(py::init<>());

// Methods
cls_StepRepr_RepresentationMap.def("Init", (void (StepRepr_RepresentationMap::*)(const opencascade::handle<StepRepr_RepresentationItem> &, const opencascade::handle<StepRepr_Representation> &)) &StepRepr_RepresentationMap::Init, "None", py::arg("aMappingOrigin"), py::arg("aMappedRepresentation"));
cls_StepRepr_RepresentationMap.def("SetMappingOrigin", (void (StepRepr_RepresentationMap::*)(const opencascade::handle<StepRepr_RepresentationItem> &)) &StepRepr_RepresentationMap::SetMappingOrigin, "None", py::arg("aMappingOrigin"));
cls_StepRepr_RepresentationMap.def("MappingOrigin", (opencascade::handle<StepRepr_RepresentationItem> (StepRepr_RepresentationMap::*)() const) &StepRepr_RepresentationMap::MappingOrigin, "None");
cls_StepRepr_RepresentationMap.def("SetMappedRepresentation", (void (StepRepr_RepresentationMap::*)(const opencascade::handle<StepRepr_Representation> &)) &StepRepr_RepresentationMap::SetMappedRepresentation, "None", py::arg("aMappedRepresentation"));
cls_StepRepr_RepresentationMap.def("MappedRepresentation", (opencascade::handle<StepRepr_Representation> (StepRepr_RepresentationMap::*)() const) &StepRepr_RepresentationMap::MappedRepresentation, "None");
cls_StepRepr_RepresentationMap.def_static("get_type_name_", (const char * (*)()) &StepRepr_RepresentationMap::get_type_name, "None");
cls_StepRepr_RepresentationMap.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_RepresentationMap::get_type_descriptor, "None");
cls_StepRepr_RepresentationMap.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_RepresentationMap::*)() const) &StepRepr_RepresentationMap::DynamicType, "None");

// CLASS: STEPREPR_TRANSFORMATION
py::class_<StepRepr_Transformation, StepData_SelectType> cls_StepRepr_Transformation(mod, "StepRepr_Transformation", "None");

// Constructors
cls_StepRepr_Transformation.def(py::init<>());

// Methods
// cls_StepRepr_Transformation.def_static("operator new_", (void * (*)(size_t)) &StepRepr_Transformation::operator new, "None", py::arg("theSize"));
// cls_StepRepr_Transformation.def_static("operator delete_", (void (*)(void *)) &StepRepr_Transformation::operator delete, "None", py::arg("theAddress"));
// cls_StepRepr_Transformation.def_static("operator new[]_", (void * (*)(size_t)) &StepRepr_Transformation::operator new[], "None", py::arg("theSize"));
// cls_StepRepr_Transformation.def_static("operator delete[]_", (void (*)(void *)) &StepRepr_Transformation::operator delete[], "None", py::arg("theAddress"));
// cls_StepRepr_Transformation.def_static("operator new_", (void * (*)(size_t, void *)) &StepRepr_Transformation::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepRepr_Transformation.def_static("operator delete_", (void (*)(void *, void *)) &StepRepr_Transformation::operator delete, "None", py::arg(""), py::arg(""));
cls_StepRepr_Transformation.def("CaseNum", (Standard_Integer (StepRepr_Transformation::*)(const opencascade::handle<Standard_Transient> &) const) &StepRepr_Transformation::CaseNum, "Recognizes a Transformation Kind Entity that is : 1 -> ItemDefinedTransformation 2 -> FunctionallyDefinedTransformation 0 else", py::arg("ent"));
cls_StepRepr_Transformation.def("ItemDefinedTransformation", (opencascade::handle<StepRepr_ItemDefinedTransformation> (StepRepr_Transformation::*)() const) &StepRepr_Transformation::ItemDefinedTransformation, "returns Value as a ItemDefinedTransformation (Null if another type)");
cls_StepRepr_Transformation.def("FunctionallyDefinedTransformation", (opencascade::handle<StepRepr_FunctionallyDefinedTransformation> (StepRepr_Transformation::*)() const) &StepRepr_Transformation::FunctionallyDefinedTransformation, "returns Value as a FunctionallyDefinedTransformation (Null if another type)");

// CLASS: STEPREPR_SHAPEREPRESENTATIONRELATIONSHIP
py::class_<StepRepr_ShapeRepresentationRelationship, opencascade::handle<StepRepr_ShapeRepresentationRelationship>, StepRepr_RepresentationRelationship> cls_StepRepr_ShapeRepresentationRelationship(mod, "StepRepr_ShapeRepresentationRelationship", "None");

// Constructors
cls_StepRepr_ShapeRepresentationRelationship.def(py::init<>());

// Methods
cls_StepRepr_ShapeRepresentationRelationship.def_static("get_type_name_", (const char * (*)()) &StepRepr_ShapeRepresentationRelationship::get_type_name, "None");
cls_StepRepr_ShapeRepresentationRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ShapeRepresentationRelationship::get_type_descriptor, "None");
cls_StepRepr_ShapeRepresentationRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ShapeRepresentationRelationship::*)() const) &StepRepr_ShapeRepresentationRelationship::DynamicType, "None");

// CLASS: STEPREPR_REPRESENTATIONRELATIONSHIPWITHTRANSFORMATION
py::class_<StepRepr_RepresentationRelationshipWithTransformation, opencascade::handle<StepRepr_RepresentationRelationshipWithTransformation>, StepRepr_ShapeRepresentationRelationship> cls_StepRepr_RepresentationRelationshipWithTransformation(mod, "StepRepr_RepresentationRelationshipWithTransformation", "None");

// Constructors
cls_StepRepr_RepresentationRelationshipWithTransformation.def(py::init<>());

// Methods
cls_StepRepr_RepresentationRelationshipWithTransformation.def("Init", (void (StepRepr_RepresentationRelationshipWithTransformation::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_Representation> &, const opencascade::handle<StepRepr_Representation> &, const StepRepr_Transformation &)) &StepRepr_RepresentationRelationshipWithTransformation::Init, "None", py::arg("aName"), py::arg("aDescription"), py::arg("aRep1"), py::arg("aRep2"), py::arg("aTransf"));
cls_StepRepr_RepresentationRelationshipWithTransformation.def("TransformationOperator", (StepRepr_Transformation (StepRepr_RepresentationRelationshipWithTransformation::*)() const) &StepRepr_RepresentationRelationshipWithTransformation::TransformationOperator, "None");
cls_StepRepr_RepresentationRelationshipWithTransformation.def("SetTransformationOperator", (void (StepRepr_RepresentationRelationshipWithTransformation::*)(const StepRepr_Transformation &)) &StepRepr_RepresentationRelationshipWithTransformation::SetTransformationOperator, "None", py::arg("aTrans"));
cls_StepRepr_RepresentationRelationshipWithTransformation.def_static("get_type_name_", (const char * (*)()) &StepRepr_RepresentationRelationshipWithTransformation::get_type_name, "None");
cls_StepRepr_RepresentationRelationshipWithTransformation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_RepresentationRelationshipWithTransformation::get_type_descriptor, "None");
cls_StepRepr_RepresentationRelationshipWithTransformation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_RepresentationRelationshipWithTransformation::*)() const) &StepRepr_RepresentationRelationshipWithTransformation::DynamicType, "None");

// CLASS: STEPREPR_REPRITEMANDMEASUREWITHUNIT
py::class_<StepRepr_ReprItemAndMeasureWithUnit, opencascade::handle<StepRepr_ReprItemAndMeasureWithUnit>, StepRepr_RepresentationItem> cls_StepRepr_ReprItemAndMeasureWithUnit(mod, "StepRepr_ReprItemAndMeasureWithUnit", "Base class for complex types (MEASURE_REPRESENTATION_ITEM, MEASURE_WITH_UNIT, REPRESENTATION_ITEM, LENGTH_MEASURE_WITH_UNIT/PLANE_ANGLE_MEASURE_WITH_UNIT).");

// Constructors
cls_StepRepr_ReprItemAndMeasureWithUnit.def(py::init<>());

// Methods
cls_StepRepr_ReprItemAndMeasureWithUnit.def("Init", (void (StepRepr_ReprItemAndMeasureWithUnit::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_RepresentationItem> &)) &StepRepr_ReprItemAndMeasureWithUnit::Init, "None", py::arg("aMWU"), py::arg("aRI"));
cls_StepRepr_ReprItemAndMeasureWithUnit.def("GetMeasureRepresentationItem", (opencascade::handle<StepRepr_MeasureRepresentationItem> (StepRepr_ReprItemAndMeasureWithUnit::*)() const) &StepRepr_ReprItemAndMeasureWithUnit::GetMeasureRepresentationItem, "None");
cls_StepRepr_ReprItemAndMeasureWithUnit.def("SetMeasureWithUnit", (void (StepRepr_ReprItemAndMeasureWithUnit::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &)) &StepRepr_ReprItemAndMeasureWithUnit::SetMeasureWithUnit, "None", py::arg("aMWU"));
cls_StepRepr_ReprItemAndMeasureWithUnit.def("GetMeasureWithUnit", (opencascade::handle<StepBasic_MeasureWithUnit> (StepRepr_ReprItemAndMeasureWithUnit::*)() const) &StepRepr_ReprItemAndMeasureWithUnit::GetMeasureWithUnit, "None");
cls_StepRepr_ReprItemAndMeasureWithUnit.def("GetRepresentationItem", (opencascade::handle<StepRepr_RepresentationItem> (StepRepr_ReprItemAndMeasureWithUnit::*)() const) &StepRepr_ReprItemAndMeasureWithUnit::GetRepresentationItem, "None");
cls_StepRepr_ReprItemAndMeasureWithUnit.def_static("get_type_name_", (const char * (*)()) &StepRepr_ReprItemAndMeasureWithUnit::get_type_name, "None");
cls_StepRepr_ReprItemAndMeasureWithUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ReprItemAndMeasureWithUnit::get_type_descriptor, "None");
cls_StepRepr_ReprItemAndMeasureWithUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ReprItemAndMeasureWithUnit::*)() const) &StepRepr_ReprItemAndMeasureWithUnit::DynamicType, "None");

// CLASS: STEPREPR_REPRITEMANDLENGTHMEASUREWITHUNIT
py::class_<StepRepr_ReprItemAndLengthMeasureWithUnit, opencascade::handle<StepRepr_ReprItemAndLengthMeasureWithUnit>, StepRepr_ReprItemAndMeasureWithUnit> cls_StepRepr_ReprItemAndLengthMeasureWithUnit(mod, "StepRepr_ReprItemAndLengthMeasureWithUnit", "None");

// Constructors
cls_StepRepr_ReprItemAndLengthMeasureWithUnit.def(py::init<>());

// Methods
cls_StepRepr_ReprItemAndLengthMeasureWithUnit.def("SetLengthMeasureWithUnit", (void (StepRepr_ReprItemAndLengthMeasureWithUnit::*)(const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepRepr_ReprItemAndLengthMeasureWithUnit::SetLengthMeasureWithUnit, "None", py::arg("aLMWU"));
cls_StepRepr_ReprItemAndLengthMeasureWithUnit.def("GetLengthMeasureWithUnit", (opencascade::handle<StepBasic_LengthMeasureWithUnit> (StepRepr_ReprItemAndLengthMeasureWithUnit::*)() const) &StepRepr_ReprItemAndLengthMeasureWithUnit::GetLengthMeasureWithUnit, "None");
cls_StepRepr_ReprItemAndLengthMeasureWithUnit.def_static("get_type_name_", (const char * (*)()) &StepRepr_ReprItemAndLengthMeasureWithUnit::get_type_name, "None");
cls_StepRepr_ReprItemAndLengthMeasureWithUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ReprItemAndLengthMeasureWithUnit::get_type_descriptor, "None");
cls_StepRepr_ReprItemAndLengthMeasureWithUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ReprItemAndLengthMeasureWithUnit::*)() const) &StepRepr_ReprItemAndLengthMeasureWithUnit::DynamicType, "None");

// CLASS: STEPREPR_REPRITEMANDMEASUREWITHUNITANDQRI
py::class_<StepRepr_ReprItemAndMeasureWithUnitAndQRI, opencascade::handle<StepRepr_ReprItemAndMeasureWithUnitAndQRI>, StepRepr_ReprItemAndMeasureWithUnit> cls_StepRepr_ReprItemAndMeasureWithUnitAndQRI(mod, "StepRepr_ReprItemAndMeasureWithUnitAndQRI", "Base class for complex types (MEASURE_REPRESENTATION_ITEM, MEASURE_WITH_UNIT, QUALIFIED_REPRESENTATION_ITEM REPRESENTATION_ITEM, LENGTH_MEASURE_WITH_UNIT/PLANE_ANGLE_MEASURE_WITH_UNIT).");

// Constructors
cls_StepRepr_ReprItemAndMeasureWithUnitAndQRI.def(py::init<>());

// Methods
cls_StepRepr_ReprItemAndMeasureWithUnitAndQRI.def("Init", (void (StepRepr_ReprItemAndMeasureWithUnitAndQRI::*)(const opencascade::handle<StepBasic_MeasureWithUnit> &, const opencascade::handle<StepRepr_RepresentationItem> &, const opencascade::handle<StepShape_QualifiedRepresentationItem>)) &StepRepr_ReprItemAndMeasureWithUnitAndQRI::Init, "None", py::arg("aMWU"), py::arg("aRI"), py::arg("aQRI"));
cls_StepRepr_ReprItemAndMeasureWithUnitAndQRI.def("SetQualifiedRepresentationItem", (void (StepRepr_ReprItemAndMeasureWithUnitAndQRI::*)(const opencascade::handle<StepShape_QualifiedRepresentationItem> &)) &StepRepr_ReprItemAndMeasureWithUnitAndQRI::SetQualifiedRepresentationItem, "None", py::arg("aQRI"), py::call_guard<ImportStepShape>());
cls_StepRepr_ReprItemAndMeasureWithUnitAndQRI.def("GetQualifiedRepresentationItem", (opencascade::handle<StepShape_QualifiedRepresentationItem> (StepRepr_ReprItemAndMeasureWithUnitAndQRI::*)() const) &StepRepr_ReprItemAndMeasureWithUnitAndQRI::GetQualifiedRepresentationItem, "None", py::call_guard<ImportStepShape>());
cls_StepRepr_ReprItemAndMeasureWithUnitAndQRI.def_static("get_type_name_", (const char * (*)()) &StepRepr_ReprItemAndMeasureWithUnitAndQRI::get_type_name, "None");
cls_StepRepr_ReprItemAndMeasureWithUnitAndQRI.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ReprItemAndMeasureWithUnitAndQRI::get_type_descriptor, "None");
cls_StepRepr_ReprItemAndMeasureWithUnitAndQRI.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ReprItemAndMeasureWithUnitAndQRI::*)() const) &StepRepr_ReprItemAndMeasureWithUnitAndQRI::DynamicType, "None");

// CLASS: STEPREPR_REPRITEMANDLENGTHMEASUREWITHUNITANDQRI
py::class_<StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI, opencascade::handle<StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI>, StepRepr_ReprItemAndMeasureWithUnitAndQRI> cls_StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI(mod, "StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI", "None");

// Constructors
cls_StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI.def(py::init<>());

// Methods
cls_StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI.def("SetLengthMeasureWithUnit", (void (StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI::*)(const opencascade::handle<StepBasic_LengthMeasureWithUnit> &)) &StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI::SetLengthMeasureWithUnit, "None", py::arg("aLMWU"));
cls_StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI.def("GetLengthMeasureWithUnit", (opencascade::handle<StepBasic_LengthMeasureWithUnit> (StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI::*)() const) &StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI::GetLengthMeasureWithUnit, "None");
cls_StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI.def_static("get_type_name_", (const char * (*)()) &StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI::get_type_name, "None");
cls_StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI::get_type_descriptor, "None");
cls_StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI::*)() const) &StepRepr_ReprItemAndLengthMeasureWithUnitAndQRI::DynamicType, "None");

// CLASS: STEPREPR_REPRITEMANDPLANEANGLEMEASUREWITHUNIT
py::class_<StepRepr_ReprItemAndPlaneAngleMeasureWithUnit, opencascade::handle<StepRepr_ReprItemAndPlaneAngleMeasureWithUnit>, StepRepr_ReprItemAndMeasureWithUnit> cls_StepRepr_ReprItemAndPlaneAngleMeasureWithUnit(mod, "StepRepr_ReprItemAndPlaneAngleMeasureWithUnit", "None");

// Constructors
cls_StepRepr_ReprItemAndPlaneAngleMeasureWithUnit.def(py::init<>());

// Methods
cls_StepRepr_ReprItemAndPlaneAngleMeasureWithUnit.def("SetPlaneAngleMeasureWithUnit", (void (StepRepr_ReprItemAndPlaneAngleMeasureWithUnit::*)(const opencascade::handle<StepBasic_PlaneAngleMeasureWithUnit> &)) &StepRepr_ReprItemAndPlaneAngleMeasureWithUnit::SetPlaneAngleMeasureWithUnit, "None", py::arg("aLMWU"));
cls_StepRepr_ReprItemAndPlaneAngleMeasureWithUnit.def("GetPlaneAngleMeasureWithUnit", (opencascade::handle<StepBasic_PlaneAngleMeasureWithUnit> (StepRepr_ReprItemAndPlaneAngleMeasureWithUnit::*)() const) &StepRepr_ReprItemAndPlaneAngleMeasureWithUnit::GetPlaneAngleMeasureWithUnit, "None");
cls_StepRepr_ReprItemAndPlaneAngleMeasureWithUnit.def_static("get_type_name_", (const char * (*)()) &StepRepr_ReprItemAndPlaneAngleMeasureWithUnit::get_type_name, "None");
cls_StepRepr_ReprItemAndPlaneAngleMeasureWithUnit.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ReprItemAndPlaneAngleMeasureWithUnit::get_type_descriptor, "None");
cls_StepRepr_ReprItemAndPlaneAngleMeasureWithUnit.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ReprItemAndPlaneAngleMeasureWithUnit::*)() const) &StepRepr_ReprItemAndPlaneAngleMeasureWithUnit::DynamicType, "None");

// CLASS: STEPREPR_REPRITEMANDPLANEANGLEMEASUREWITHUNITANDQRI
py::class_<StepRepr_ReprItemAndPlaneAngleMeasureWithUnitAndQRI, opencascade::handle<StepRepr_ReprItemAndPlaneAngleMeasureWithUnitAndQRI>, StepRepr_ReprItemAndMeasureWithUnitAndQRI> cls_StepRepr_ReprItemAndPlaneAngleMeasureWithUnitAndQRI(mod, "StepRepr_ReprItemAndPlaneAngleMeasureWithUnitAndQRI", "None");

// Constructors
cls_StepRepr_ReprItemAndPlaneAngleMeasureWithUnitAndQRI.def(py::init<>());

// Methods
cls_StepRepr_ReprItemAndPlaneAngleMeasureWithUnitAndQRI.def("SetPlaneAngleMeasureWithUnit", (void (StepRepr_ReprItemAndPlaneAngleMeasureWithUnitAndQRI::*)(const opencascade::handle<StepBasic_PlaneAngleMeasureWithUnit> &)) &StepRepr_ReprItemAndPlaneAngleMeasureWithUnitAndQRI::SetPlaneAngleMeasureWithUnit, "None", py::arg("aLMWU"));
cls_StepRepr_ReprItemAndPlaneAngleMeasureWithUnitAndQRI.def("GetPlaneAngleMeasureWithUnit", (opencascade::handle<StepBasic_PlaneAngleMeasureWithUnit> (StepRepr_ReprItemAndPlaneAngleMeasureWithUnitAndQRI::*)() const) &StepRepr_ReprItemAndPlaneAngleMeasureWithUnitAndQRI::GetPlaneAngleMeasureWithUnit, "None");
cls_StepRepr_ReprItemAndPlaneAngleMeasureWithUnitAndQRI.def_static("get_type_name_", (const char * (*)()) &StepRepr_ReprItemAndPlaneAngleMeasureWithUnitAndQRI::get_type_name, "None");
cls_StepRepr_ReprItemAndPlaneAngleMeasureWithUnitAndQRI.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ReprItemAndPlaneAngleMeasureWithUnitAndQRI::get_type_descriptor, "None");
cls_StepRepr_ReprItemAndPlaneAngleMeasureWithUnitAndQRI.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ReprItemAndPlaneAngleMeasureWithUnitAndQRI::*)() const) &StepRepr_ReprItemAndPlaneAngleMeasureWithUnitAndQRI::DynamicType, "None");

// CLASS: STEPREPR_SHAPEASPECTDERIVINGRELATIONSHIP
py::class_<StepRepr_ShapeAspectDerivingRelationship, opencascade::handle<StepRepr_ShapeAspectDerivingRelationship>, StepRepr_ShapeAspectRelationship> cls_StepRepr_ShapeAspectDerivingRelationship(mod, "StepRepr_ShapeAspectDerivingRelationship", "Added for Dimensional Tolerances");

// Constructors
cls_StepRepr_ShapeAspectDerivingRelationship.def(py::init<>());

// Methods
cls_StepRepr_ShapeAspectDerivingRelationship.def_static("get_type_name_", (const char * (*)()) &StepRepr_ShapeAspectDerivingRelationship::get_type_name, "None");
cls_StepRepr_ShapeAspectDerivingRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ShapeAspectDerivingRelationship::get_type_descriptor, "None");
cls_StepRepr_ShapeAspectDerivingRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ShapeAspectDerivingRelationship::*)() const) &StepRepr_ShapeAspectDerivingRelationship::DynamicType, "None");

// CLASS: STEPREPR_SHAPEASPECTTRANSITION
py::class_<StepRepr_ShapeAspectTransition, opencascade::handle<StepRepr_ShapeAspectTransition>, StepRepr_ShapeAspectRelationship> cls_StepRepr_ShapeAspectTransition(mod, "StepRepr_ShapeAspectTransition", "Representation of STEP entity ShapeAspectTransition");

// Constructors
cls_StepRepr_ShapeAspectTransition.def(py::init<>());

// Methods
cls_StepRepr_ShapeAspectTransition.def_static("get_type_name_", (const char * (*)()) &StepRepr_ShapeAspectTransition::get_type_name, "None");
cls_StepRepr_ShapeAspectTransition.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ShapeAspectTransition::get_type_descriptor, "None");
cls_StepRepr_ShapeAspectTransition.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ShapeAspectTransition::*)() const) &StepRepr_ShapeAspectTransition::DynamicType, "None");

// CLASS: STEPREPR_SHAPEDEFINITION
py::class_<StepRepr_ShapeDefinition, StepData_SelectType> cls_StepRepr_ShapeDefinition(mod, "StepRepr_ShapeDefinition", "None");

// Constructors
cls_StepRepr_ShapeDefinition.def(py::init<>());

// Methods
// cls_StepRepr_ShapeDefinition.def_static("operator new_", (void * (*)(size_t)) &StepRepr_ShapeDefinition::operator new, "None", py::arg("theSize"));
// cls_StepRepr_ShapeDefinition.def_static("operator delete_", (void (*)(void *)) &StepRepr_ShapeDefinition::operator delete, "None", py::arg("theAddress"));
// cls_StepRepr_ShapeDefinition.def_static("operator new[]_", (void * (*)(size_t)) &StepRepr_ShapeDefinition::operator new[], "None", py::arg("theSize"));
// cls_StepRepr_ShapeDefinition.def_static("operator delete[]_", (void (*)(void *)) &StepRepr_ShapeDefinition::operator delete[], "None", py::arg("theAddress"));
// cls_StepRepr_ShapeDefinition.def_static("operator new_", (void * (*)(size_t, void *)) &StepRepr_ShapeDefinition::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_StepRepr_ShapeDefinition.def_static("operator delete_", (void (*)(void *, void *)) &StepRepr_ShapeDefinition::operator delete, "None", py::arg(""), py::arg(""));
cls_StepRepr_ShapeDefinition.def("CaseNum", (Standard_Integer (StepRepr_ShapeDefinition::*)(const opencascade::handle<Standard_Transient> &) const) &StepRepr_ShapeDefinition::CaseNum, "Recognizes a ShapeDefinition Kind Entity that is : 1 -> ProductDefinitionShape 2 -> ShapeAspect 3 -> ShapeAspectRelationship 0 else", py::arg("ent"));
cls_StepRepr_ShapeDefinition.def("ProductDefinitionShape", (opencascade::handle<StepRepr_ProductDefinitionShape> (StepRepr_ShapeDefinition::*)() const) &StepRepr_ShapeDefinition::ProductDefinitionShape, "returns Value as a ProductDefinitionShape (Null if another type)");
cls_StepRepr_ShapeDefinition.def("ShapeAspect", (opencascade::handle<StepRepr_ShapeAspect> (StepRepr_ShapeDefinition::*)() const) &StepRepr_ShapeDefinition::ShapeAspect, "returns Value as a ShapeAspect (Null if another type)");
cls_StepRepr_ShapeDefinition.def("ShapeAspectRelationship", (opencascade::handle<StepRepr_ShapeAspectRelationship> (StepRepr_ShapeDefinition::*)() const) &StepRepr_ShapeDefinition::ShapeAspectRelationship, "returns Value as a ShapeAspectRelationship (Null if another type)");

// CLASS: STEPREPR_SHAPEREPRESENTATIONRELATIONSHIPWITHTRANSFORMATION
py::class_<StepRepr_ShapeRepresentationRelationshipWithTransformation, opencascade::handle<StepRepr_ShapeRepresentationRelationshipWithTransformation>, StepRepr_RepresentationRelationshipWithTransformation> cls_StepRepr_ShapeRepresentationRelationshipWithTransformation(mod, "StepRepr_ShapeRepresentationRelationshipWithTransformation", "None");

// Constructors
cls_StepRepr_ShapeRepresentationRelationshipWithTransformation.def(py::init<>());

// Methods
cls_StepRepr_ShapeRepresentationRelationshipWithTransformation.def_static("get_type_name_", (const char * (*)()) &StepRepr_ShapeRepresentationRelationshipWithTransformation::get_type_name, "None");
cls_StepRepr_ShapeRepresentationRelationshipWithTransformation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ShapeRepresentationRelationshipWithTransformation::get_type_descriptor, "None");
cls_StepRepr_ShapeRepresentationRelationshipWithTransformation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ShapeRepresentationRelationshipWithTransformation::*)() const) &StepRepr_ShapeRepresentationRelationshipWithTransformation::DynamicType, "None");

// CLASS: STEPREPR_SPECIFIEDHIGHERUSAGEOCCURRENCE
py::class_<StepRepr_SpecifiedHigherUsageOccurrence, opencascade::handle<StepRepr_SpecifiedHigherUsageOccurrence>, StepRepr_AssemblyComponentUsage> cls_StepRepr_SpecifiedHigherUsageOccurrence(mod, "StepRepr_SpecifiedHigherUsageOccurrence", "Representation of STEP entity SpecifiedHigherUsageOccurrence");

// Constructors
cls_StepRepr_SpecifiedHigherUsageOccurrence.def(py::init<>());

// Methods
cls_StepRepr_SpecifiedHigherUsageOccurrence.def("Init", (void (StepRepr_SpecifiedHigherUsageOccurrence::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_ProductDefinition> &, const opencascade::handle<StepBasic_ProductDefinition> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_AssemblyComponentUsage> &, const opencascade::handle<StepRepr_NextAssemblyUsageOccurrence> &)) &StepRepr_SpecifiedHigherUsageOccurrence::Init, "Initialize all fields (own and inherited)", py::arg("aProductDefinitionRelationship_Id"), py::arg("aProductDefinitionRelationship_Name"), py::arg("hasProductDefinitionRelationship_Description"), py::arg("aProductDefinitionRelationship_Description"), py::arg("aProductDefinitionRelationship_RelatingProductDefinition"), py::arg("aProductDefinitionRelationship_RelatedProductDefinition"), py::arg("hasAssemblyComponentUsage_ReferenceDesignator"), py::arg("aAssemblyComponentUsage_ReferenceDesignator"), py::arg("aUpperUsage"), py::arg("aNextUsage"));
cls_StepRepr_SpecifiedHigherUsageOccurrence.def("Init", (void (StepRepr_SpecifiedHigherUsageOccurrence::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<TCollection_HAsciiString> &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const StepBasic_ProductDefinitionOrReference &, const StepBasic_ProductDefinitionOrReference &, const Standard_Boolean, const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepRepr_AssemblyComponentUsage> &, const opencascade::handle<StepRepr_NextAssemblyUsageOccurrence> &)) &StepRepr_SpecifiedHigherUsageOccurrence::Init, "Initialize all fields (own and inherited)", py::arg("aProductDefinitionRelationship_Id"), py::arg("aProductDefinitionRelationship_Name"), py::arg("hasProductDefinitionRelationship_Description"), py::arg("aProductDefinitionRelationship_Description"), py::arg("aProductDefinitionRelationship_RelatingProductDefinition"), py::arg("aProductDefinitionRelationship_RelatedProductDefinition"), py::arg("hasAssemblyComponentUsage_ReferenceDesignator"), py::arg("aAssemblyComponentUsage_ReferenceDesignator"), py::arg("aUpperUsage"), py::arg("aNextUsage"));
cls_StepRepr_SpecifiedHigherUsageOccurrence.def("UpperUsage", (opencascade::handle<StepRepr_AssemblyComponentUsage> (StepRepr_SpecifiedHigherUsageOccurrence::*)() const) &StepRepr_SpecifiedHigherUsageOccurrence::UpperUsage, "Returns field UpperUsage");
cls_StepRepr_SpecifiedHigherUsageOccurrence.def("SetUpperUsage", (void (StepRepr_SpecifiedHigherUsageOccurrence::*)(const opencascade::handle<StepRepr_AssemblyComponentUsage> &)) &StepRepr_SpecifiedHigherUsageOccurrence::SetUpperUsage, "Set field UpperUsage", py::arg("UpperUsage"));
cls_StepRepr_SpecifiedHigherUsageOccurrence.def("NextUsage", (opencascade::handle<StepRepr_NextAssemblyUsageOccurrence> (StepRepr_SpecifiedHigherUsageOccurrence::*)() const) &StepRepr_SpecifiedHigherUsageOccurrence::NextUsage, "Returns field NextUsage");
cls_StepRepr_SpecifiedHigherUsageOccurrence.def("SetNextUsage", (void (StepRepr_SpecifiedHigherUsageOccurrence::*)(const opencascade::handle<StepRepr_NextAssemblyUsageOccurrence> &)) &StepRepr_SpecifiedHigherUsageOccurrence::SetNextUsage, "Set field NextUsage", py::arg("NextUsage"));
cls_StepRepr_SpecifiedHigherUsageOccurrence.def_static("get_type_name_", (const char * (*)()) &StepRepr_SpecifiedHigherUsageOccurrence::get_type_name, "None");
cls_StepRepr_SpecifiedHigherUsageOccurrence.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_SpecifiedHigherUsageOccurrence::get_type_descriptor, "None");
cls_StepRepr_SpecifiedHigherUsageOccurrence.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_SpecifiedHigherUsageOccurrence::*)() const) &StepRepr_SpecifiedHigherUsageOccurrence::DynamicType, "None");

// CLASS: STEPREPR_STRUCTURALRESPONSEPROPERTY
py::class_<StepRepr_StructuralResponseProperty, opencascade::handle<StepRepr_StructuralResponseProperty>, StepRepr_PropertyDefinition> cls_StepRepr_StructuralResponseProperty(mod, "StepRepr_StructuralResponseProperty", "Representation of STEP entity StructuralResponseProperty");

// Constructors
cls_StepRepr_StructuralResponseProperty.def(py::init<>());

// Methods
cls_StepRepr_StructuralResponseProperty.def_static("get_type_name_", (const char * (*)()) &StepRepr_StructuralResponseProperty::get_type_name, "None");
cls_StepRepr_StructuralResponseProperty.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_StructuralResponseProperty::get_type_descriptor, "None");
cls_StepRepr_StructuralResponseProperty.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_StructuralResponseProperty::*)() const) &StepRepr_StructuralResponseProperty::DynamicType, "None");

// CLASS: STEPREPR_STRUCTURALRESPONSEPROPERTYDEFINITIONREPRESENTATION
py::class_<StepRepr_StructuralResponsePropertyDefinitionRepresentation, opencascade::handle<StepRepr_StructuralResponsePropertyDefinitionRepresentation>, StepRepr_PropertyDefinitionRepresentation> cls_StepRepr_StructuralResponsePropertyDefinitionRepresentation(mod, "StepRepr_StructuralResponsePropertyDefinitionRepresentation", "Representation of STEP entity StructuralResponsePropertyDefinitionRepresentation");

// Constructors
cls_StepRepr_StructuralResponsePropertyDefinitionRepresentation.def(py::init<>());

// Methods
cls_StepRepr_StructuralResponsePropertyDefinitionRepresentation.def_static("get_type_name_", (const char * (*)()) &StepRepr_StructuralResponsePropertyDefinitionRepresentation::get_type_name, "None");
cls_StepRepr_StructuralResponsePropertyDefinitionRepresentation.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_StructuralResponsePropertyDefinitionRepresentation::get_type_descriptor, "None");
cls_StepRepr_StructuralResponsePropertyDefinitionRepresentation.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_StructuralResponsePropertyDefinitionRepresentation::*)() const) &StepRepr_StructuralResponsePropertyDefinitionRepresentation::DynamicType, "None");

// CLASS: STEPREPR_SUPPLIEDPARTRELATIONSHIP
py::class_<StepRepr_SuppliedPartRelationship, opencascade::handle<StepRepr_SuppliedPartRelationship>, StepBasic_ProductDefinitionRelationship> cls_StepRepr_SuppliedPartRelationship(mod, "StepRepr_SuppliedPartRelationship", "None");

// Constructors
cls_StepRepr_SuppliedPartRelationship.def(py::init<>());

// Methods
cls_StepRepr_SuppliedPartRelationship.def_static("get_type_name_", (const char * (*)()) &StepRepr_SuppliedPartRelationship::get_type_name, "None");
cls_StepRepr_SuppliedPartRelationship.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_SuppliedPartRelationship::get_type_descriptor, "None");
cls_StepRepr_SuppliedPartRelationship.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_SuppliedPartRelationship::*)() const) &StepRepr_SuppliedPartRelationship::DynamicType, "None");

// CLASS: STEPREPR_TANGENT
py::class_<StepRepr_Tangent, opencascade::handle<StepRepr_Tangent>, StepRepr_DerivedShapeAspect> cls_StepRepr_Tangent(mod, "StepRepr_Tangent", "Added for Dimensional Tolerances");

// Constructors
cls_StepRepr_Tangent.def(py::init<>());

// Methods
cls_StepRepr_Tangent.def_static("get_type_name_", (const char * (*)()) &StepRepr_Tangent::get_type_name, "None");
cls_StepRepr_Tangent.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_Tangent::get_type_descriptor, "None");
cls_StepRepr_Tangent.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_Tangent::*)() const) &StepRepr_Tangent::DynamicType, "None");

// CLASS: STEPREPR_VALUERANGE
py::class_<StepRepr_ValueRange, opencascade::handle<StepRepr_ValueRange>, StepRepr_CompoundRepresentationItem> cls_StepRepr_ValueRange(mod, "StepRepr_ValueRange", "Added for Dimensional Tolerances");

// Constructors
cls_StepRepr_ValueRange.def(py::init<>());

// Methods
cls_StepRepr_ValueRange.def_static("get_type_name_", (const char * (*)()) &StepRepr_ValueRange::get_type_name, "None");
cls_StepRepr_ValueRange.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ValueRange::get_type_descriptor, "None");
cls_StepRepr_ValueRange.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ValueRange::*)() const) &StepRepr_ValueRange::DynamicType, "None");

// CLASS: STEPREPR_VALUEREPRESENTATIONITEM
py::class_<StepRepr_ValueRepresentationItem, opencascade::handle<StepRepr_ValueRepresentationItem>, StepRepr_RepresentationItem> cls_StepRepr_ValueRepresentationItem(mod, "StepRepr_ValueRepresentationItem", "None");

// Constructors
cls_StepRepr_ValueRepresentationItem.def(py::init<>());

// Methods
cls_StepRepr_ValueRepresentationItem.def("Init", (void (StepRepr_ValueRepresentationItem::*)(const opencascade::handle<TCollection_HAsciiString> &, const opencascade::handle<StepBasic_MeasureValueMember> &)) &StepRepr_ValueRepresentationItem::Init, "None", py::arg("theName"), py::arg("theValueComponentMember"));
cls_StepRepr_ValueRepresentationItem.def("SetValueComponentMember", (void (StepRepr_ValueRepresentationItem::*)(const opencascade::handle<StepBasic_MeasureValueMember> &)) &StepRepr_ValueRepresentationItem::SetValueComponentMember, "None", py::arg("theValueComponentMember"));
cls_StepRepr_ValueRepresentationItem.def("ValueComponentMember", (opencascade::handle<StepBasic_MeasureValueMember> (StepRepr_ValueRepresentationItem::*)() const) &StepRepr_ValueRepresentationItem::ValueComponentMember, "None");
cls_StepRepr_ValueRepresentationItem.def_static("get_type_name_", (const char * (*)()) &StepRepr_ValueRepresentationItem::get_type_name, "None");
cls_StepRepr_ValueRepresentationItem.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &StepRepr_ValueRepresentationItem::get_type_descriptor, "None");
cls_StepRepr_ValueRepresentationItem.def("DynamicType", (const opencascade::handle<Standard_Type> & (StepRepr_ValueRepresentationItem::*)() const) &StepRepr_ValueRepresentationItem::DynamicType, "None");


}
